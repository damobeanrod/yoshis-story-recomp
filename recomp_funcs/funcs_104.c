#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80041EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041EC0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80041EC4: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80041EC8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80041ECC: slti        $at, $a2, 0x34E
    ctx->r1 = SIGNED(ctx->r6) < 0X34E ? 1 : 0;
    // 0x80041ED0: bne         $at, $zero, L_80041F50
    if (ctx->r1 != 0) {
        // 0x80041ED4: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_80041F50;
    }
    // 0x80041ED4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80041ED8: lw          $v0, 0x1F0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F0);
    // 0x80041EDC: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80041EE0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80041EE4: lh          $t6, 0x13E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X13E);
    // 0x80041EE8: addiu       $t8, $t8, -0xA14
    ctx->r24 = ADD32(ctx->r24, -0XA14);
    // 0x80041EEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80041EF0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80041EF4: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80041EF8: lwc1        $f8, -0x27A8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X27A8);
    // 0x80041EFC: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80041F00: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041F04: lwc1        $f16, -0x27A4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X27A4);
    // 0x80041F08: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80041F0C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80041F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041F14: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80041F18: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80041F1C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80041F20: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80041F24: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80041F28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80041F2C: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x80041F30: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80041F34: beq         $t9, $zero, L_80041F40
    if (ctx->r25 == 0) {
        // 0x80041F38: add.s       $f12, $f4, $f10
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
            goto L_80041F40;
    }
    // 0x80041F38: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80041F3C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80041F40:
    // 0x80041F40: swc1        $f2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f2.u32l;
    // 0x80041F44: swc1        $f12, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f12.u32l;
    // 0x80041F48: lwc1        $f18, -0x27A0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X27A0);
    // 0x80041F4C: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
L_80041F50:
    // 0x80041F50: jr          $ra
    // 0x80041F54: nop

    return;
    // 0x80041F54: nop

;}
RECOMP_FUNC void func_8045290C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045290C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452914: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452918: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045291C: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80452920: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80452924: sw          $t6, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r14;
    // 0x80452928: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8045292C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452930: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80452934: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80452938: jal         0x80445858
    // 0x8045293C: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80445858(rdram, ctx);
        goto after_0;
    // 0x8045293C: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80452940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80452944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452948: jr          $ra
    // 0x8045294C: nop

    return;
    // 0x8045294C: nop

;}
RECOMP_FUNC void func_8040E120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040E124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040E128: jal         0x8040DCF0
    // 0x8040E12C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040E12C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040E130: bne         $v0, $zero, L_8040E148
    if (ctx->r2 != 0) {
        // 0x8040E134: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040E148;
    }
    // 0x8040E134: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040E138: jal         0x800445A4
    // 0x8040E13C: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040E13C: nop

    after_1:
    // 0x8040E140: b           L_8040E174
    // 0x8040E144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040E174;
    // 0x8040E144: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E148:
    // 0x8040E148: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040E14C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8040E150: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8040E154: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x8040E158: sw          $t7, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r15;
    // 0x8040E15C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8040E160: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8040E164: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E168: jal         0x8040E254
    // 0x8040E16C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040E16C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040E170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040E174:
    // 0x8040E174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040E178: jr          $ra
    // 0x8040E17C: nop

    return;
    // 0x8040E17C: nop

;}
RECOMP_FUNC void func_807BC78C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC78C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807BC790: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807BC794: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807BC798: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807BC79C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807BC7A0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807BC7A4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807BC7A8: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(898, 0X6E78) << 16);
    // 0x807BC7AC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807BC7B0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807BC7B4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807BC7B8: lw          $t1, 0x2B38($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(898, 0X6E78));
    // 0x807BC7BC: jr          $ra
    // 0x807BC7C0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807BC7C0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804716A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804716A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804716A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804716AC: jal         0x804715A4
    // 0x804716B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804715A4(rdram, ctx);
        goto after_0;
    // 0x804716B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804716B4: jal         0x80471660
    // 0x804716B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80471660(rdram, ctx);
        goto after_1;
    // 0x804716B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804716BC: jal         0x80045BD8
    // 0x804716C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_2;
    // 0x804716C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804716C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804716C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804716CC: jr          $ra
    // 0x804716D0: nop

    return;
    // 0x804716D0: nop

;}
RECOMP_FUNC void func_80468100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468100: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80468104: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80468108: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046810C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80468110: jal         0x80467610
    // 0x80468114: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80467610(rdram, ctx);
        goto after_0;
    // 0x80468114: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80468118: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8046811C: lh          $t6, 0x1A($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1A);
    // 0x80468120: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x80468124: lw          $t9, 0x1FA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1FA0);
    // 0x80468128: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x8046812C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80468130: addiu       $t1, $v0, 0x2C70
    ctx->r9 = ADD32(ctx->r2, 0X2C70);
    // 0x80468134: addiu       $t2, $v0, 0x2CF0
    ctx->r10 = ADD32(ctx->r2, 0X2CF0);
    // 0x80468138: addiu       $t3, $v0, 0x18
    ctx->r11 = ADD32(ctx->r2, 0X18);
    // 0x8046813C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80468140: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80468144: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80468148: lh          $t4, 0x16($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X16);
    // 0x8046814C: addiu       $a2, $v0, 0x27FE
    ctx->r6 = ADD32(ctx->r2, 0X27FE);
    // 0x80468150: addiu       $a3, $v0, 0x27FC
    ctx->r7 = ADD32(ctx->r2, 0X27FC);
    // 0x80468154: mflo        $t8
    ctx->r24 = lo;
    // 0x80468158: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x8046815C: nop

    // 0x80468160: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80468164: mflo        $t0
    ctx->r8 = lo;
    // 0x80468168: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    // 0x8046816C: jal         0x80055E10
    // 0x80468170: addiu       $a1, $a1, 0xFDC
    ctx->r5 = ADD32(ctx->r5, 0XFDC);
    func_80055E10(rdram, ctx);
        goto after_1;
    // 0x80468170: addiu       $a1, $a1, 0xFDC
    ctx->r5 = ADD32(ctx->r5, 0XFDC);
    after_1:
    // 0x80468174: jal         0x80468020
    // 0x80468178: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80468020(rdram, ctx);
        goto after_2;
    // 0x80468178: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8046817C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80468180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80468184: jr          $ra
    // 0x80468188: nop

    return;
    // 0x80468188: nop

;}
RECOMP_FUNC void func_80046E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046E8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046E94: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80046E98: addiu       $a0, $a0, 0x6E64
    ctx->r4 = ADD32(ctx->r4, 0X6E64);
    // 0x80046E9C: jal         0x80046D2C
    // 0x80046EA0: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    func_80046D2C(rdram, ctx);
        goto after_0;
    // 0x80046EA0: addiu       $a1, $sp, 0x1A
    ctx->r5 = ADD32(ctx->r29, 0X1A);
    after_0:
    // 0x80046EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046EAC: jr          $ra
    // 0x80046EB0: nop

    return;
    // 0x80046EB0: nop

;}
RECOMP_FUNC void func_807812F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807812F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807812F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807812FC: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6674) << 16);
    // 0x80781300: lwc1        $f4, 0x6864($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6674));
    // 0x80781304: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80781308: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8078130C: nop

    // 0x80781310: bc1f        L_80781328
    if (!c1cs) {
        // 0x80781314: nop
    
            goto L_80781328;
    }
    // 0x80781314: nop

    // 0x80781318: jal         0x807807F0
    // 0x8078131C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807807F0(rdram, ctx);
        goto after_0;
    // 0x8078131C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80781320: b           L_80781334
    // 0x80781324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80781334;
    // 0x80781324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80781328:
    // 0x80781328: jal         0x807808AC
    // 0x8078132C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807808AC(rdram, ctx);
        goto after_1;
    // 0x8078132C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80781330: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80781334:
    // 0x80781334: lh          $t6, 0x144($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X144);
    // 0x80781338: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8078133C: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    // 0x80781340: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x80781344: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80781348: bnel        $at, $zero, L_80781358
    if (ctx->r1 != 0) {
        // 0x8078134C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80781358;
    }
    goto skip_0;
    // 0x8078134C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80781350: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80781354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80781358:
    // 0x80781358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078135C: jr          $ra
    // 0x80781360: nop

    return;
    // 0x80781360: nop

;}
RECOMP_FUNC void func_805ABE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABE74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805ABE78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805ABE7C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805ABE80: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805ABE84: lw          $a2, 0x264($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X264);
    // 0x805ABE88: beql        $a2, $zero, L_805ABEB8
    if (ctx->r6 == 0) {
        // 0x805ABE8C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_805ABEB8;
    }
    goto skip_0;
    // 0x805ABE8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x805ABE90: lw          $v0, 0x268($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X268);
    // 0x805ABE94: bne         $v0, $zero, L_805ABEAC
    if (ctx->r2 != 0) {
        // 0x805ABE98: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805ABEAC;
    }
    // 0x805ABE98: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805ABE9C: jal         0x805ABBE8
    // 0x805ABEA0: nop

    func_805ABBE8(rdram, ctx);
        goto after_0;
    // 0x805ABEA0: nop

    after_0:
    // 0x805ABEA4: b           L_805ABF08
    // 0x805ABEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805ABF08;
    // 0x805ABEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805ABEAC:
    // 0x805ABEAC: b           L_805ABF04
    // 0x805ABEB0: sw          $t6, 0x268($a1)
    MEM_W(0X268, ctx->r5) = ctx->r14;
        goto L_805ABF04;
    // 0x805ABEB0: sw          $t6, 0x268($a1)
    MEM_W(0X268, ctx->r5) = ctx->r14;
    // 0x805ABEB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_805ABEB8:
    // 0x805ABEB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805ABEBC: jal         0x805ABBA0
    // 0x805ABEC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_805ABBA0(rdram, ctx);
        goto after_1;
    // 0x805ABEC0: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x805ABEC4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805ABEC8: beq         $v0, $zero, L_805ABEDC
    if (ctx->r2 == 0) {
        // 0x805ABECC: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805ABEDC;
    }
    // 0x805ABECC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805ABED0: sw          $v0, 0x264($a1)
    MEM_W(0X264, ctx->r5) = ctx->r2;
    // 0x805ABED4: b           L_805ABF04
    // 0x805ABED8: sw          $zero, 0x268($a1)
    MEM_W(0X268, ctx->r5) = 0;
        goto L_805ABF04;
    // 0x805ABED8: sw          $zero, 0x268($a1)
    MEM_W(0X268, ctx->r5) = 0;
L_805ABEDC:
    // 0x805ABEDC: lw          $v0, 0x268($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X268);
    // 0x805ABEE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805ABEE4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805ABEE8: bne         $v0, $zero, L_805ABF00
    if (ctx->r2 != 0) {
        // 0x805ABEEC: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_805ABF00;
    }
    // 0x805ABEEC: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x805ABEF0: jal         0x805AC088
    // 0x805ABEF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805AC088(rdram, ctx);
        goto after_2;
    // 0x805ABEF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x805ABEF8: b           L_805ABF08
    // 0x805ABEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805ABF08;
    // 0x805ABEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805ABF00:
    // 0x805ABF00: sw          $t7, 0x268($a1)
    MEM_W(0X268, ctx->r5) = ctx->r15;
L_805ABF04:
    // 0x805ABF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805ABF08:
    // 0x805ABF08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805ABF0C: jr          $ra
    // 0x805ABF10: nop

    return;
    // 0x805ABF10: nop

;}
RECOMP_FUNC void func_807C33B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C33B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C33B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C33BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807C33C0: jal         0x80047090
    // 0x807C33C4: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807C33C4: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x807C33C8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807C33CC: beq         $v0, $at, L_807C3434
    if (ctx->r2 == ctx->r1) {
        // 0x807C33D0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807C3434;
    }
    // 0x807C33D0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807C33D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C33D8: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x807C33DC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807C33E0: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x807C33E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C33E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C33EC: ori         $a3, $a3, 0x7AE
    ctx->r7 = ctx->r7 | 0X7AE;
    // 0x807C33F0: jal         0x8004613C
    // 0x807C33F4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807C33F4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807C33F8: beq         $v0, $zero, L_807C3434
    if (ctx->r2 == 0) {
        // 0x807C33FC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807C3434;
    }
    // 0x807C33FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807C3400: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807C3404: jal         0x80047F9C
    // 0x807C3408: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807C3408: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x807C340C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807C3410: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x807C3414: jalr        $t9
    // 0x807C3418: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x807C3418: nop

    after_3:
    // 0x807C341C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x807C3420: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807C3424: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x807C3428: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x807C342C: b           L_807C3438
    // 0x807C3430: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
        goto L_807C3438;
    // 0x807C3430: sb          $t6, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r14;
L_807C3434:
    // 0x807C3434: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C3438:
    // 0x807C3438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C343C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C3440: jr          $ra
    // 0x807C3444: nop

    return;
    // 0x807C3444: nop

;}
RECOMP_FUNC void func_8000ABEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ABEC: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8000ABF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000ABF4: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000ABF8: lui         $at, 0xFA00
    ctx->r1 = S32(0XFA00 << 16);
    // 0x8000ABFC: andi        $t0, $a1, 0xFF
    ctx->r8 = ctx->r5 & 0XFF;
    // 0x8000AC00: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x8000AC04: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8000AC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AC0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000AC10: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8000AC14: andi        $t3, $a2, 0xFF
    ctx->r11 = ctx->r6 & 0XFF;
    // 0x8000AC18: or          $a0, $t2, $t3
    ctx->r4 = ctx->r10 | ctx->r11;
    // 0x8000AC1C: jal         0x8000A364
    // 0x8000AC20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8000A364(rdram, ctx);
        goto after_0;
    // 0x8000AC20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8000AC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AC2C: jr          $ra
    // 0x8000AC30: nop

    return;
    // 0x8000AC30: nop

;}
RECOMP_FUNC void func_8043FA00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FA00: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8043FA04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043FA08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043FA0C: jal         0x8004700C
    // 0x8043FA10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043FA10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043FA14: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8043FA18: bne         $v0, $zero, L_8043FA28
    if (ctx->r2 != 0) {
        // 0x8043FA1C: lw          $t0, 0x174($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X174);
            goto L_8043FA28;
    }
    // 0x8043FA1C: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x8043FA20: b           L_8043FB80
    // 0x8043FA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8043FB80;
    // 0x8043FA24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043FA28:
    // 0x8043FA28: lw          $a3, 0x174($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X174);
    // 0x8043FA2C: lwc1        $f0, 0x3C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8043FA30: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8043FA34: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8043FA38: lwc1        $f12, 0x3C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043FA3C: lwc1        $f14, 0x40($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043FA40: lh          $t6, 0xA($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA);
    // 0x8043FA44: lw          $a1, 0x70($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X70);
    // 0x8043FA48: lh          $t7, 0xC($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XC);
    // 0x8043FA4C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8043FA50: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8043FA54: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8043FA58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043FA5C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8043FA60: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8043FA64: mul.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8043FA68: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8043FA6C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8043FA70: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8043FA74: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8043FA78: lh          $t8, 0xA($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XA);
    // 0x8043FA7C: lw          $a2, 0x70($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X70);
    // 0x8043FA80: lh          $t9, 0xC($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XC);
    // 0x8043FA84: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8043FA88: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8043FA8C: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8043FA90: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8043FA94: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8043FA98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043FA9C: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8043FAA0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8043FAA4: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8043FAA8: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8043FAAC: sub.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8043FAB0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8043FAB4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8043FAB8: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8043FABC: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x8043FAC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8043FAC4: nop

    // 0x8043FAC8: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x8043FACC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8043FAD0: bc1fl       L_8043FAE4
    if (!c1cs) {
        // 0x8043FAD4: lwc1        $f8, 0x2C($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8043FAE4;
    }
    goto skip_0;
    // 0x8043FAD4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8043FAD8: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8043FADC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8043FAE0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
L_8043FAE4:
    // 0x8043FAE4: c.lt.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl < ctx->f6.fl;
    // 0x8043FAE8: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8043FAEC: bc1fl       L_8043FB00
    if (!c1cs) {
        // 0x8043FAF0: lwc1        $f10, 0x28($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8043FB00;
    }
    goto skip_1;
    // 0x8043FAF0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x8043FAF4: sub.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8043FAF8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8043FAFC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
L_8043FB00:
    // 0x8043FB00: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8043FB04: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8043FB08: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8043FB0C: bc1f        L_8043FB5C
    if (!c1cs) {
        // 0x8043FB10: nop
    
            goto L_8043FB5C;
    }
    // 0x8043FB10: nop

    // 0x8043FB14: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8043FB18: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8043FB1C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8043FB20: nop

    // 0x8043FB24: bc1f        L_8043FB5C
    if (!c1cs) {
        // 0x8043FB28: nop
    
            goto L_8043FB5C;
    }
    // 0x8043FB28: nop

    // 0x8043FB2C: lbu         $t1, 0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X18);
    // 0x8043FB30: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8043FB34: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8043FB38: beq         $t1, $at, L_8043FB4C
    if (ctx->r9 == ctx->r1) {
        // 0x8043FB3C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8043FB4C;
    }
    // 0x8043FB3C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8043FB40: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8043FB44: jal         0x8002F6E4
    // 0x8043FB48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8043FB48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8043FB4C:
    // 0x8043FB4C: jal         0x8043F86C
    // 0x8043FB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F86C(rdram, ctx);
        goto after_2;
    // 0x8043FB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043FB54: b           L_8043FB80
    // 0x8043FB58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8043FB80;
    // 0x8043FB58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8043FB5C:
    // 0x8043FB5C: jal         0x80047534
    // 0x8043FB60: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    func_80047534(rdram, ctx);
        goto after_3;
    // 0x8043FB60: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    after_3:
    // 0x8043FB64: beql        $v0, $zero, L_8043FB80
    if (ctx->r2 == 0) {
        // 0x8043FB68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8043FB80;
    }
    goto skip_2;
    // 0x8043FB68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8043FB6C: jal         0x8043F93C
    // 0x8043FB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_4;
    // 0x8043FB70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8043FB74: b           L_8043FB80
    // 0x8043FB78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8043FB80;
    // 0x8043FB78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8043FB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8043FB80:
    // 0x8043FB80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043FB84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043FB88: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8043FB8C: jr          $ra
    // 0x8043FB90: nop

    return;
    // 0x8043FB90: nop

;}
RECOMP_FUNC void func_8007DB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DB34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007DB38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007DB3C: jal         0x8007D5E0
    // 0x8007DB40: nop

    func_8007D5E0(rdram, ctx);
        goto after_0;
    // 0x8007DB40: nop

    after_0:
    // 0x8007DB44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007DB48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007DB4C: jr          $ra
    // 0x8007DB50: nop

    return;
    // 0x8007DB50: nop

    // 0x8007DB54: nop

    // 0x8007DB58: nop

    // 0x8007DB5C: nop

;}
RECOMP_FUNC void func_804472A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804472A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804472AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804472B0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804472B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804472B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804472BC: bne         $a2, $zero, L_804472FC
    if (ctx->r6 != 0) {
        // 0x804472C0: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804472FC;
    }
    // 0x804472C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804472C4: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x804472C8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x804472CC: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804472D0: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804472D4: bne         $at, $zero, L_8044733C
    if (ctx->r1 != 0) {
        // 0x804472D8: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_8044733C;
    }
    // 0x804472D8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x804472DC: jal         0x80445FD4
    // 0x804472E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_0;
    // 0x804472E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804472E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804472E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804472EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804472F0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804472F4: b           L_8044733C
    // 0x804472F8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_8044733C;
    // 0x804472F8: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_804472FC:
    // 0x804472FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447300: bnel        $a2, $at, L_8044732C
    if (ctx->r6 != ctx->r1) {
        // 0x80447304: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044732C;
    }
    goto skip_0;
    // 0x80447304: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80447308: jal         0x80445FD4
    // 0x8044730C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_1;
    // 0x8044730C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447310: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447314: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447318: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8044731C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447320: b           L_8044733C
    // 0x80447324: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_8044733C;
    // 0x80447324: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80447328: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044732C:
    // 0x8044732C: bnel        $a2, $at, L_80447340
    if (ctx->r6 != ctx->r1) {
        // 0x80447330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80447340;
    }
    goto skip_1;
    // 0x80447330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80447334: jal         0x80446038
    // 0x80447338: nop

    func_80446038(rdram, ctx);
        goto after_2;
    // 0x80447338: nop

    after_2:
L_8044733C:
    // 0x8044733C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447340:
    // 0x80447340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80447348: jr          $ra
    // 0x8044734C: nop

    return;
    // 0x8044734C: nop

;}
RECOMP_FUNC void func_80408030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408030: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80408034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80408038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040803C: jal         0x8004700C
    // 0x80408040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80408040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80408044: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80408048: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8040804C: beq         $v0, $zero, L_8040809C
    if (ctx->r2 == 0) {
        // 0x80408050: lw          $v1, 0x4($t0)
        ctx->r3 = MEM_W(ctx->r8, 0X4);
            goto L_8040809C;
    }
    // 0x80408050: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x80408054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80408058: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8040805C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80408060: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80408064: jal         0x80407D10
    // 0x80408068: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_80407D10(rdram, ctx);
        goto after_1;
    // 0x80408068: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_1:
    // 0x8040806C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80408070: beq         $v0, $zero, L_8040809C
    if (ctx->r2 == 0) {
        // 0x80408074: lw          $t0, 0x28($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X28);
            goto L_8040809C;
    }
    // 0x80408074: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80408078: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8040807C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80408080: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80408084: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80408088: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8040808C: jal         0x8002F6E4
    // 0x80408090: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x80408090: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_2:
    // 0x80408094: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80408098: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
L_8040809C:
    // 0x8040809C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804080A0: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x804080A4: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(11, 0X2E04) << 16);
    // 0x804080A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x804080AC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804080B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804080B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804080B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804080BC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x804080C0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x804080C4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804080C8: lwc1        $f10, -0x582C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(11, 0X2E04));
    // 0x804080CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804080D0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804080D4: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x804080D8: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804080DC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x804080E0: nop

    // 0x804080E4: bc1f        L_804080FC
    if (!c1cs) {
        // 0x804080E8: nop
    
            goto L_804080FC;
    }
    // 0x804080E8: nop

    // 0x804080EC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x804080F0: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x804080F4: jal         0x8040818C
    // 0x804080F8: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    func_8040818C(rdram, ctx);
        goto after_3;
    // 0x804080F8: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
    after_3:
L_804080FC:
    // 0x804080FC: jal         0x8040A470
    // 0x80408100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040A470(rdram, ctx);
        goto after_4;
    // 0x80408100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80408104: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80408108: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040810C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80408110: jr          $ra
    // 0x80408114: nop

    return;
    // 0x80408114: nop

;}
RECOMP_FUNC void func_8046FC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046FC10: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(149, 0XE18) << 16);
    // 0x8046FC14: addiu       $v0, $v0, 0xA28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(149, 0XE18));
    // 0x8046FC18: jr          $ra
    // 0x8046FC1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8046FC1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804A18E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A18E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A18EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A18F0: jal         0x804A1820
    // 0x804A18F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A18F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A18F8: bnel        $v0, $zero, L_804A191C
    if (ctx->r2 != 0) {
        // 0x804A18FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A191C;
    }
    goto skip_0;
    // 0x804A18FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A1900: jal         0x804A2910
    // 0x804A1904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A1904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804A1908: beql        $v0, $zero, L_804A191C
    if (ctx->r2 == 0) {
        // 0x804A190C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A191C;
    }
    goto skip_1;
    // 0x804A190C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804A1910: jal         0x804A1604
    // 0x804A1914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A1604(rdram, ctx);
        goto after_2;
    // 0x804A1914: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804A1918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A191C:
    // 0x804A191C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A1920: jr          $ra
    // 0x804A1924: nop

    return;
    // 0x804A1924: nop

;}
RECOMP_FUNC void func_80045C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045C48: bne         $a0, $zero, L_80045C68
    if (ctx->r4 != 0) {
        // 0x80045C4C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80045C68;
    }
    // 0x80045C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045C50: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045C54: addiu       $a0, $a0, 0x6D0
    ctx->r4 = ADD32(ctx->r4, 0X6D0);
    // 0x80045C58: jal         0x80071380
    // 0x80045C5C: addiu       $a1, $zero, 0x2E0
    ctx->r5 = ADD32(0, 0X2E0);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80045C5C: addiu       $a1, $zero, 0x2E0
    ctx->r5 = ADD32(0, 0X2E0);
    after_0:
    // 0x80045C60: b           L_80045CA0
    // 0x80045C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80045CA0;
    // 0x80045C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045C68:
    // 0x80045C68: addiu       $a1, $zero, 0x1FC
    ctx->r5 = ADD32(0, 0X1FC);
    // 0x80045C6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80045C70: jal         0x80065728
    // 0x80045C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80045C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80045C78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80045C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80045C80: addiu       $t6, $zero, 0x96
    ctx->r14 = ADD32(0, 0X96);
    // 0x80045C84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80045C88: sh          $t6, 0x17E($a0)
    MEM_H(0X17E, ctx->r4) = ctx->r14;
    // 0x80045C8C: sb          $v0, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = ctx->r2;
    // 0x80045C90: sb          $v0, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r2;
    // 0x80045C94: lwc1        $f4, 0x898($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X898);
    // 0x80045C98: swc1        $f4, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->f4.u32l;
    // 0x80045C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045CA0:
    // 0x80045CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045CA4: jr          $ra
    // 0x80045CA8: nop

    return;
    // 0x80045CA8: nop

;}
RECOMP_FUNC void func_8069B61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069B61C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8069B620: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069B624: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069B628: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8069B62C: jal         0x8004700C
    // 0x8069B630: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8069B630: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8069B634: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8069B638: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8069B63C: beq         $v0, $zero, L_8069B80C
    if (ctx->r2 == 0) {
        // 0x8069B640: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8069B80C;
    }
    // 0x8069B640: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8069B644: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8069B648: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(565, 0X1840) << 16);
    // 0x8069B64C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8069B650: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8069B654: lw          $t8, -0x3AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(565, 0X1840));
    // 0x8069B658: sh          $t8, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r24;
    // 0x8069B65C: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x8069B660: bne         $t9, $zero, L_8069B804
    if (ctx->r25 != 0) {
        // 0x8069B664: nop
    
            goto L_8069B804;
    }
    // 0x8069B664: nop

    // 0x8069B668: lw          $t0, 0x14($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X14);
    // 0x8069B66C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8069B670: bne         $t0, $zero, L_8069B804
    if (ctx->r8 != 0) {
        // 0x8069B674: nop
    
            goto L_8069B804;
    }
    // 0x8069B674: nop

    // 0x8069B678: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8069B67C: jal         0x80047AB8
    // 0x8069B680: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x8069B680: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_1:
    // 0x8069B684: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8069B688: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8069B68C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8069B690: lwc1        $f6, 0x84($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8069B694: lwc1        $f10, 0x88($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8069B698: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8069B69C: jal         0x80067114
    // 0x8069B6A0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x8069B6A0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x8069B6A4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8069B6A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8069B6AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8069B6B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8069B6B4: sub.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8069B6B8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8069B6BC: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8069B6C0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8069B6C4: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8069B6C8: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x8069B6CC: bc1fl       L_8069B6E4
    if (!c1cs) {
        // 0x8069B6D0: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8069B6E4;
    }
    goto skip_0;
    // 0x8069B6D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_0:
    // 0x8069B6D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8069B6D8: nop

    // 0x8069B6DC: add.s       $f14, $f2, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8069B6E0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8069B6E4:
    // 0x8069B6E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8069B6E8: nop

    // 0x8069B6EC: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x8069B6F0: nop

    // 0x8069B6F4: bc1fl       L_8069B704
    if (!c1cs) {
        // 0x8069B6F8: lwc1        $f0, 0x0($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8069B704;
    }
    goto skip_1;
    // 0x8069B6F8: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8069B6FC: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8069B700: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
L_8069B704:
    // 0x8069B704: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8069B708: nop

    // 0x8069B70C: bc1fl       L_8069B7A0
    if (!c1cs) {
        // 0x8069B710: lwc1        $f12, 0x50($a2)
        ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
            goto L_8069B7A0;
    }
    goto skip_2;
    // 0x8069B710: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
    skip_2:
    // 0x8069B714: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8069B718: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8069B71C: nop

    // 0x8069B720: bc1fl       L_8069B760
    if (!c1cs) {
        // 0x8069B724: sub.s       $f0, $f14, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
            goto L_8069B760;
    }
    goto skip_3;
    // 0x8069B724: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
    skip_3:
    // 0x8069B728: sub.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8069B72C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8069B730: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8069B734: nop

    // 0x8069B738: bc1fl       L_8069B754
    if (!c1cs) {
        // 0x8069B73C: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8069B754;
    }
    goto skip_4;
    // 0x8069B73C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_4:
    // 0x8069B740: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8069B744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069B748: b           L_8069B794
    // 0x8069B74C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_8069B794;
    // 0x8069B74C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8069B750: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8069B754:
    // 0x8069B754: b           L_8069B794
    // 0x8069B758: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
        goto L_8069B794;
    // 0x8069B758: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8069B75C: sub.s       $f0, $f14, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f12.fl;
L_8069B760:
    // 0x8069B760: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8069B764: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8069B768: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8069B76C: nop

    // 0x8069B770: bc1fl       L_8069B78C
    if (!c1cs) {
        // 0x8069B774: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_8069B78C;
    }
    goto skip_5;
    // 0x8069B774: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_5:
    // 0x8069B778: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8069B77C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8069B780: b           L_8069B794
    // 0x8069B784: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_8069B794;
    // 0x8069B784: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8069B788: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_8069B78C:
    // 0x8069B78C: nop

    // 0x8069B790: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_8069B794:
    // 0x8069B794: b           L_8069B804
    // 0x8069B798: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
        goto L_8069B804;
    // 0x8069B798: swc1        $f14, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f14.u32l;
    // 0x8069B79C: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
L_8069B7A0:
    // 0x8069B7A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8069B7A4: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8069B7A8: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8069B7AC: nop

    // 0x8069B7B0: bc1fl       L_8069B7C0
    if (!c1cs) {
        // 0x8069B7B4: c.lt.s      $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
            goto L_8069B7C0;
    }
    goto skip_6;
    // 0x8069B7B4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    skip_6:
    // 0x8069B7B8: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8069B7BC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
L_8069B7C0:
    // 0x8069B7C0: nop

    // 0x8069B7C4: bc1fl       L_8069B7D4
    if (!c1cs) {
        // 0x8069B7C8: lwc1        $f4, 0x4($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
            goto L_8069B7D4;
    }
    goto skip_7;
    // 0x8069B7C8: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    skip_7:
    // 0x8069B7CC: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8069B7D0: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
L_8069B7D4:
    // 0x8069B7D4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8069B7D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8069B7DC: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8069B7E0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8069B7E4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8069B7E8: nop

    // 0x8069B7EC: bc1fl       L_8069B804
    if (!c1cs) {
        // 0x8069B7F0: swc1        $f2, 0x50($a2)
        MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
            goto L_8069B804;
    }
    goto skip_8;
    // 0x8069B7F0: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
    skip_8:
    // 0x8069B7F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8069B7F8: b           L_8069B804
    // 0x8069B7FC: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_8069B804;
    // 0x8069B7FC: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8069B800: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
L_8069B804:
    // 0x8069B804: jal         0x8069B588
    // 0x8069B808: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8069B588(rdram, ctx);
        goto after_3;
    // 0x8069B808: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
L_8069B80C:
    // 0x8069B80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069B810: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8069B814: jr          $ra
    // 0x8069B818: nop

    return;
    // 0x8069B818: nop

;}
RECOMP_FUNC void func_804C3AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3AD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3ADC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3AE0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C3AE4: lwc1        $f4, 0x908($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X908);
    // 0x804C3AE8: jal         0x804C37CC
    // 0x804C3AEC: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    func_804C37CC(rdram, ctx);
        goto after_0;
    // 0x804C3AEC: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    after_0:
    // 0x804C3AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C3AF8: jr          $ra
    // 0x804C3AFC: nop

    return;
    // 0x804C3AFC: nop

;}
RECOMP_FUNC void func_806F2048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2048: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F204C: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x806F2050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2058: beq         $t6, $zero, L_806F2098
    if (ctx->r14 == 0) {
        // 0x806F205C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806F2098;
    }
    // 0x806F205C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2060: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806F2064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F2068: jal         0x806F2554
    // 0x806F206C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806F2554(rdram, ctx);
        goto after_0;
    // 0x806F206C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x806F2070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2074: jal         0x8005FDC4
    // 0x806F2078: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x806F2078: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    after_1:
    // 0x806F207C: jal         0x806F1FC8
    // 0x806F2080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F1FC8(rdram, ctx);
        goto after_2;
    // 0x806F2080: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F2084: jal         0x80067E68
    // 0x806F2088: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x806F2088: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x806F208C: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F2090: jal         0x80067818
    // 0x806F2094: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806F2094: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
L_806F2098:
    // 0x806F2098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F209C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F20A0: jr          $ra
    // 0x806F20A4: nop

    return;
    // 0x806F20A4: nop

;}
RECOMP_FUNC void func_80050CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050CF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80050CF4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80050CF8: or          $a0, $sp, $zero
    ctx->r4 = ctx->r29 | 0;
    // 0x80050CFC: addiu       $a0, $a0, 0x2F
    ctx->r4 = ADD32(ctx->r4, 0X2F);
    // 0x80050D00: srl         $a0, $a0, 3
    ctx->r4 = S32(U32(ctx->r4) >> 3);
    // 0x80050D04: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80050D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050D0C: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80050D10: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80050D14: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80050D18: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80050D1C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80050D20: jal         0x800675D0
    // 0x80050D24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_800675D0(rdram, ctx);
        goto after_0;
    // 0x80050D24: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80050D28: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80050D2C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80050D30: jal         0x80064DD0
    // 0x80050D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x80050D34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80050D38: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80050D3C: bne         $v0, $zero, L_80050D4C
    if (ctx->r2 != 0) {
        // 0x80050D40: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80050D4C;
    }
    // 0x80050D40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80050D44: b           L_80050D64
    // 0x80050D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050D64;
    // 0x80050D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050D4C:
    // 0x80050D4C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80050D50: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80050D54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80050D58: jal         0x800675D0
    // 0x80050D5C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x80050D5C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    after_2:
    // 0x80050D60: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80050D64:
    // 0x80050D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80050D6C: jr          $ra
    // 0x80050D70: nop

    return;
    // 0x80050D70: nop

;}
RECOMP_FUNC void func_805DCF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DCF7C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805DCF80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805DCF84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805DCF88: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805DCF8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DCF90: slti        $at, $v0, 0x407A
    ctx->r1 = SIGNED(ctx->r2) < 0X407A ? 1 : 0;
    // 0x805DCF94: bne         $at, $zero, L_805DCFE4
    if (ctx->r1 != 0) {
        // 0x805DCF98: addiu       $t6, $v0, -0x4532
        ctx->r14 = ADD32(ctx->r2, -0X4532);
            goto L_805DCFE4;
    }
    // 0x805DCF98: addiu       $t6, $v0, -0x4532
    ctx->r14 = ADD32(ctx->r2, -0X4532);
    // 0x805DCF9C: slti        $at, $v0, 0x4093
    ctx->r1 = SIGNED(ctx->r2) < 0X4093 ? 1 : 0;
    // 0x805DCFA0: bne         $at, $zero, L_805DCFC4
    if (ctx->r1 != 0) {
        // 0x805DCFA4: sltiu       $at, $t6, 0x15
        ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
            goto L_805DCFC4;
    }
    // 0x805DCFA4: sltiu       $at, $t6, 0x15
    ctx->r1 = ctx->r14 < 0X15 ? 1 : 0;
    // 0x805DCFA8: beq         $at, $zero, L_805DD1A8
    if (ctx->r1 == 0) {
        // 0x805DCFAC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805DD1A8;
    }
    // 0x805DCFAC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805DCFB0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X28D0) << 16);
    // 0x805DCFB4: addu        $at, $at, $t6
    gpr jr_addend_805DCFBC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805DCFB8: lw          $t6, -0x2A30($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(480, 0X28D0));
    // 0x805DCFBC: jr          $t6
    // 0x805DCFC0: nop

    switch (jr_addend_805DCFBC >> 2) {
        case 0: goto L_805DD0D4; break;
        case 1: goto L_805DD00C; break;
        case 2: goto L_805DD00C; break;
        case 3: goto L_805DD04C; break;
        case 4: goto L_805DD1A8; break;
        case 5: goto L_805DD1A8; break;
        case 6: goto L_805DD1A8; break;
        case 7: goto L_805DD1A8; break;
        case 8: goto L_805DD1A8; break;
        case 9: goto L_805DD1A8; break;
        case 10: goto L_805DD1A8; break;
        case 11: goto L_805DD04C; break;
        case 12: goto L_805DD1A8; break;
        case 13: goto L_805DD1A8; break;
        case 14: goto L_805DD1A8; break;
        case 15: goto L_805DD1A8; break;
        case 16: goto L_805DD1A8; break;
        case 17: goto L_805DD1A8; break;
        case 18: goto L_805DD1A8; break;
        case 19: goto L_805DD090; break;
        case 20: goto L_805DD090; break;
        default: switch_error(__func__, 0x805DCFBC, 0x805DD5D0);
    }
    // 0x805DCFC0: nop

L_805DCFC4:
    // 0x805DCFC4: addiu       $at, $zero, 0x407C
    ctx->r1 = ADD32(0, 0X407C);
    // 0x805DCFC8: beq         $v0, $at, L_805DD164
    if (ctx->r2 == ctx->r1) {
        // 0x805DCFCC: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_805DD164;
    }
    // 0x805DCFCC: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DCFD0: addiu       $at, $zero, 0x4092
    ctx->r1 = ADD32(0, 0X4092);
    // 0x805DCFD4: beql        $v0, $at, L_805DD168
    if (ctx->r2 == ctx->r1) {
        // 0x805DCFD8: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_805DD168;
    }
    goto skip_0;
    // 0x805DCFD8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    skip_0:
    // 0x805DCFDC: b           L_805DD1AC
    // 0x805DCFE0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
        goto L_805DD1AC;
    // 0x805DCFE0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_805DCFE4:
    // 0x805DCFE4: addiu       $at, $zero, 0x4047
    ctx->r1 = ADD32(0, 0X4047);
    // 0x805DCFE8: beq         $v0, $at, L_805DD0D4
    if (ctx->r2 == ctx->r1) {
        // 0x805DCFEC: addiu       $at, $zero, 0x4048
        ctx->r1 = ADD32(0, 0X4048);
            goto L_805DD0D4;
    }
    // 0x805DCFEC: addiu       $at, $zero, 0x4048
    ctx->r1 = ADD32(0, 0X4048);
    // 0x805DCFF0: beq         $v0, $at, L_805DD11C
    if (ctx->r2 == ctx->r1) {
        // 0x805DCFF4: addiu       $a0, $sp, 0x2C
        ctx->r4 = ADD32(ctx->r29, 0X2C);
            goto L_805DD11C;
    }
    // 0x805DCFF4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DCFF8: addiu       $at, $zero, 0x4079
    ctx->r1 = ADD32(0, 0X4079);
    // 0x805DCFFC: beql        $v0, $at, L_805DD120
    if (ctx->r2 == ctx->r1) {
        // 0x805DD000: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_805DD120;
    }
    goto skip_1;
    // 0x805DD000: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    skip_1:
    // 0x805DD004: b           L_805DD1AC
    // 0x805DD008: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
        goto L_805DD1AC;
    // 0x805DD008: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_805DD00C:
    // 0x805DD00C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DD010: jal         0x805DB2D8
    // 0x805DD014: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_805DB2D8(rdram, ctx);
        goto after_0;
    // 0x805DD014: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x805DD018: jal         0x805DCC30
    // 0x805DD01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_1;
    // 0x805DD01C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805DD020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805DD024: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805DD028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD02C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD030: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805DD034: addiu       $a2, $zero, 0x4194
    ctx->r6 = ADD32(0, 0X4194);
    // 0x805DD038: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x805DD03C: jal         0x805DCE84
    // 0x805DD040: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_805DCE84(rdram, ctx);
        goto after_2;
    // 0x805DD040: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x805DD044: b           L_805DD1AC
    // 0x805DD048: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
        goto L_805DD1AC;
    // 0x805DD048: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_805DD04C:
    // 0x805DD04C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DD050: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x805DD054: jal         0x805DB9FC
    // 0x805DD058: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_805DB9FC(rdram, ctx);
        goto after_3;
    // 0x805DD058: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_3:
    // 0x805DD05C: jal         0x805DCC30
    // 0x805DD060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_4;
    // 0x805DD060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805DD064: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805DD068: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805DD06C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD070: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD074: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805DD078: addiu       $a2, $zero, 0x4194
    ctx->r6 = ADD32(0, 0X4194);
    // 0x805DD07C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x805DD080: jal         0x805DCE84
    // 0x805DD084: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_805DCE84(rdram, ctx);
        goto after_5;
    // 0x805DD084: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x805DD088: b           L_805DD1A8
    // 0x805DD08C: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
        goto L_805DD1A8;
    // 0x805DD08C: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
L_805DD090:
    // 0x805DD090: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DD094: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x805DD098: jal         0x805DB9FC
    // 0x805DD09C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805DB9FC(rdram, ctx);
        goto after_6;
    // 0x805DD09C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x805DD0A0: jal         0x805DCC30
    // 0x805DD0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_7;
    // 0x805DD0A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805DD0A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805DD0AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805DD0B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD0B4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD0B8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805DD0BC: addiu       $a2, $zero, 0x4194
    ctx->r6 = ADD32(0, 0X4194);
    // 0x805DD0C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x805DD0C4: jal         0x805DCE84
    // 0x805DD0C8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_805DCE84(rdram, ctx);
        goto after_8;
    // 0x805DD0C8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x805DD0CC: b           L_805DD1A8
    // 0x805DD0D0: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
        goto L_805DD1A8;
    // 0x805DD0D0: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
L_805DD0D4:
    // 0x805DD0D4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805DD0D8: jal         0x805DB2D8
    // 0x805DD0DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_805DB2D8(rdram, ctx);
        goto after_9;
    // 0x805DD0DC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_9:
    // 0x805DD0E0: jal         0x805DCC30
    // 0x805DD0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_10;
    // 0x805DD0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805DD0E8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805DD0EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805DD0F0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2924) << 16);
    // 0x805DD0F4: lwc1        $f6, -0x29DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2924));
    // 0x805DD0F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD0FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD100: addiu       $a2, $zero, 0x4195
    ctx->r6 = ADD32(0, 0X4195);
    // 0x805DD104: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x805DD108: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805DD10C: jal         0x805DCE84
    // 0x805DD110: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_805DCE84(rdram, ctx);
        goto after_11;
    // 0x805DD110: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x805DD114: b           L_805DD1AC
    // 0x805DD118: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
        goto L_805DD1AC;
    // 0x805DD118: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_805DD11C:
    // 0x805DD11C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_805DD120:
    // 0x805DD120: jal         0x805DB9FC
    // 0x805DD124: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_805DB9FC(rdram, ctx);
        goto after_12;
    // 0x805DD124: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_12:
    // 0x805DD128: jal         0x805DCC30
    // 0x805DD12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_13;
    // 0x805DD12C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x805DD130: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805DD134: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805DD138: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X2928) << 16);
    // 0x805DD13C: lwc1        $f10, -0x29D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X2928));
    // 0x805DD140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD144: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD148: addiu       $a2, $zero, 0x4195
    ctx->r6 = ADD32(0, 0X4195);
    // 0x805DD14C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x805DD150: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x805DD154: jal         0x805DCE84
    // 0x805DD158: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    func_805DCE84(rdram, ctx);
        goto after_14;
    // 0x805DD158: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x805DD15C: b           L_805DD1A8
    // 0x805DD160: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
        goto L_805DD1A8;
    // 0x805DD160: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
L_805DD164:
    // 0x805DD164: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_805DD168:
    // 0x805DD168: jal         0x805DB9FC
    // 0x805DD16C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805DB9FC(rdram, ctx);
        goto after_15;
    // 0x805DD16C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x805DD170: jal         0x805DCC30
    // 0x805DD174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DCC30(rdram, ctx);
        goto after_16;
    // 0x805DD174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x805DD178: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805DD17C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805DD180: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(480, 0X292C) << 16);
    // 0x805DD184: lwc1        $f18, -0x29D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(480, 0X292C));
    // 0x805DD188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD18C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x805DD190: addiu       $a2, $zero, 0x4195
    ctx->r6 = ADD32(0, 0X4195);
    // 0x805DD194: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x805DD198: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x805DD19C: jal         0x805DCE84
    // 0x805DD1A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_805DCE84(rdram, ctx);
        goto after_17;
    // 0x805DD1A0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_17:
    // 0x805DD1A4: sw          $zero, 0x1D8($s0)
    MEM_W(0X1D8, ctx->r16) = 0;
L_805DD1A8:
    // 0x805DD1A8: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
L_805DD1AC:
    // 0x805DD1AC: lui         $t7, 0x805E
    ctx->r15 = S32(RELOC_HI16(480, 0X2728) << 16);
    // 0x805DD1B0: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(480, 0X2750) << 16);
    // 0x805DD1B4: addiu       $t8, $t8, -0x2BB0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(480, 0X2750));
    // 0x805DD1B8: addiu       $t7, $t7, -0x2BD8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(480, 0X2728));
    // 0x805DD1BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x805DD1C0: sw          $t7, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r15;
    // 0x805DD1C4: sw          $t8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r24;
    // 0x805DD1C8: sh          $t9, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r25;
    // 0x805DD1CC: sh          $zero, 0x74($v1)
    MEM_H(0X74, ctx->r3) = 0;
    // 0x805DD1D0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805DD1D4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x805DD1D8: sw          $t0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->r8;
    // 0x805DD1DC: swc1        $f4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f4.u32l;
    // 0x805DD1E0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x805DD1E4: addiu       $at, $zero, 0x407C
    ctx->r1 = ADD32(0, 0X407C);
    // 0x805DD1E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DD1EC: beq         $v0, $at, L_805DD20C
    if (ctx->r2 == ctx->r1) {
        // 0x805DD1F0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_805DD20C;
    }
    // 0x805DD1F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DD1F4: addiu       $at, $zero, 0x4092
    ctx->r1 = ADD32(0, 0X4092);
    // 0x805DD1F8: beq         $v0, $at, L_805DD20C
    if (ctx->r2 == ctx->r1) {
        // 0x805DD1FC: addiu       $at, $zero, 0x4545
        ctx->r1 = ADD32(0, 0X4545);
            goto L_805DD20C;
    }
    // 0x805DD1FC: addiu       $at, $zero, 0x4545
    ctx->r1 = ADD32(0, 0X4545);
    // 0x805DD200: beq         $v0, $at, L_805DD20C
    if (ctx->r2 == ctx->r1) {
        // 0x805DD204: addiu       $at, $zero, 0x4546
        ctx->r1 = ADD32(0, 0X4546);
            goto L_805DD20C;
    }
    // 0x805DD204: addiu       $at, $zero, 0x4546
    ctx->r1 = ADD32(0, 0X4546);
    // 0x805DD208: bne         $v0, $at, L_805DD214
    if (ctx->r2 != ctx->r1) {
        // 0x805DD20C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_805DD214;
    }
L_805DD20C:
    // 0x805DD20C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x805DD210: sh          $t1, 0x58($v1)
    MEM_H(0X58, ctx->r3) = ctx->r9;
L_805DD214:
    // 0x805DD214: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805DD218: jal         0x805DD234
    // 0x805DD21C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805DD234(rdram, ctx);
        goto after_18;
    // 0x805DD21C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_18:
    // 0x805DD220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805DD224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805DD228: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x805DD22C: jr          $ra
    // 0x805DD230: nop

    return;
    // 0x805DD230: nop

;}
RECOMP_FUNC void func_80059700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059700: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059708: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005970C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059710: jal         0x80081C64
    // 0x80059714: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80059714: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059718: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005971C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059720: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x80059724: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059728: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005972C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059730: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80059734: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059738: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8005973C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80059740: lh          $t8, 0x2($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X2);
    // 0x80059744: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80059748: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8005974C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80059750: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80059754: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x80059758: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x8005975C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059764: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80059768: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8005976C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80059770: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059774: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80059778: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8005977C: add.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059780: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80059784: sub.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80059788: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8005978C: nop

    // 0x80059790: bc1f        L_8005979C
    if (!c1cs) {
        // 0x80059794: nop
    
            goto L_8005979C;
    }
    // 0x80059794: nop

    // 0x80059798: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005979C:
    // 0x8005979C: jr          $ra
    // 0x800597A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800597A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004FC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004FC2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004FC30: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8004FC34: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8004FC38: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8004FC3C: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x8004FC40: lw          $t9, 0x1070($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1070);
    // 0x8004FC44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FC48: jalr        $t9
    // 0x8004FC4C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8004FC4C: nop

    after_0:
    // 0x8004FC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004FC54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004FC58: jr          $ra
    // 0x8004FC5C: nop

    return;
    // 0x8004FC5C: nop

;}
RECOMP_FUNC void func_80760578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760578: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076057C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC354) << 16);
    // 0x80760580: lwc1        $f0, -0x3C1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC354));
    // 0x80760584: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80760588: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8076058C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80760590: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80760594: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80760598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8076059C: addiu       $t6, $zero, 0x834
    ctx->r14 = ADD32(0, 0X834);
    // 0x807605A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x807605A4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807605A8: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x807605AC: addiu       $a1, $zero, 0x348
    ctx->r5 = ADD32(0, 0X348);
    // 0x807605B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x807605B4: jal         0x8076009C
    // 0x807605B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x807605B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x807605BC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807605C0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x807605C4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807605C8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x807605CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807605D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807605D4: jr          $ra
    // 0x807605D8: nop

    return;
    // 0x807605D8: nop

;}
RECOMP_FUNC void func_8042FBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FBFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FC00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FC04: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FC08: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042FC0C: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8042FC10: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8042FC14: nop

    // 0x8042FC18: bc1fl       L_8042FC2C
    if (!c1cs) {
        // 0x8042FC1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042FC2C;
    }
    goto skip_0;
    // 0x8042FC1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042FC20: jal         0x8042FB6C
    // 0x8042FC24: nop

    func_8042FB6C(rdram, ctx);
        goto after_0;
    // 0x8042FC24: nop

    after_0:
    // 0x8042FC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042FC2C:
    // 0x8042FC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FC30: jr          $ra
    // 0x8042FC34: nop

    return;
    // 0x8042FC34: nop

;}
RECOMP_FUNC void func_806E7468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7468: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E746C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E7470: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E7474: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806E7478: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806E747C: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(664, 0XEA0) << 16);
    // 0x806E7480: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806E7484: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E7488: addiu       $t7, $t7, -0x7F20
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(664, 0XEA0));
    // 0x806E748C: lui         $a1, 0x806F
    ctx->r5 = S32(RELOC_HI16(664, 0XEB0) << 16);
    // 0x806E7490: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E7494: addiu       $a1, $a1, -0x7F10
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(664, 0XEB0));
    // 0x806E7498: jal         0x806E8030
    // 0x806E749C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_806E8030(rdram, ctx);
        goto after_0;
    // 0x806E749C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_0:
    // 0x806E74A0: lhu         $v1, 0xC($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XC);
    // 0x806E74A4: addiu       $at, $zero, 0x40C5
    ctx->r1 = ADD32(0, 0X40C5);
    // 0x806E74A8: beq         $v1, $at, L_806E74CC
    if (ctx->r3 == ctx->r1) {
        // 0x806E74AC: addiu       $at, $zero, 0x466C
        ctx->r1 = ADD32(0, 0X466C);
            goto L_806E74CC;
    }
    // 0x806E74AC: addiu       $at, $zero, 0x466C
    ctx->r1 = ADD32(0, 0X466C);
    // 0x806E74B0: beq         $v1, $at, L_806E74F0
    if (ctx->r3 == ctx->r1) {
        // 0x806E74B4: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_806E74F0;
    }
    // 0x806E74B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x806E74B8: addiu       $at, $zero, 0x4689
    ctx->r1 = ADD32(0, 0X4689);
    // 0x806E74BC: beq         $v1, $at, L_806E7504
    if (ctx->r3 == ctx->r1) {
        // 0x806E74C0: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_806E7504;
    }
    // 0x806E74C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x806E74C4: b           L_806E7528
    // 0x806E74C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_806E7528;
    // 0x806E74C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_806E74CC:
    // 0x806E74CC: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x806E74D0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806E74D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806E74D8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806E74DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E74E0: jal         0x8005FCA8
    // 0x806E74E4: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x806E74E4: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    after_1:
    // 0x806E74E8: b           L_806E7538
    // 0x806E74EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_806E7538;
    // 0x806E74EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_806E74F0:
    // 0x806E74F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806E74F4: beq         $v0, $zero, L_806E7538
    if (ctx->r2 == 0) {
        // 0x806E74F8: sb          $v1, 0x165($s0)
        MEM_B(0X165, ctx->r16) = ctx->r3;
            goto L_806E7538;
    }
    // 0x806E74F8: sb          $v1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r3;
    // 0x806E74FC: b           L_806E7538
    // 0x806E7500: sb          $v1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r3;
        goto L_806E7538;
    // 0x806E7500: sb          $v1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r3;
L_806E7504:
    // 0x806E7504: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806E7508: beq         $v0, $zero, L_806E7514
    if (ctx->r2 == 0) {
        // 0x806E750C: sb          $v1, 0x165($s0)
        MEM_B(0X165, ctx->r16) = ctx->r3;
            goto L_806E7514;
    }
    // 0x806E750C: sb          $v1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r3;
    // 0x806E7510: sb          $v1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r3;
L_806E7514:
    // 0x806E7514: lbu         $t2, 0xE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XE);
    // 0x806E7518: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x806E751C: ori         $t4, $t3, 0x18
    ctx->r12 = ctx->r11 | 0X18;
    // 0x806E7520: b           L_806E7538
    // 0x806E7524: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
        goto L_806E7538;
    // 0x806E7524: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
L_806E7528:
    // 0x806E7528: sb          $v1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r3;
    // 0x806E752C: beq         $v0, $zero, L_806E7538
    if (ctx->r2 == 0) {
        // 0x806E7530: addiu       $a1, $zero, 0x4
        ctx->r5 = ADD32(0, 0X4);
            goto L_806E7538;
    }
    // 0x806E7530: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x806E7534: sb          $v1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r3;
L_806E7538:
    // 0x806E7538: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806E753C: jal         0x806E7E4C
    // 0x806E7540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E7E4C(rdram, ctx);
        goto after_2;
    // 0x806E7540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806E7544: jal         0x806E72A0
    // 0x806E7548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E72A0(rdram, ctx);
        goto after_3;
    // 0x806E7548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E754C: lui         $t5, 0x806E
    ctx->r13 = S32(RELOC_HI16(664, 0X190) << 16);
    // 0x806E7550: addiu       $t5, $t5, 0x73D0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(664, 0X190));
    // 0x806E7554: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x806E7558: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x806E755C: sh          $t6, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r14;
    // 0x806E7560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E7564: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E7568: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E756C: jr          $ra
    // 0x806E7570: nop

    return;
    // 0x806E7570: nop

;}
RECOMP_FUNC void func_806D0D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D0D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0D08: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806D0D0C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806D0D10: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806D0D14: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X1A90) << 16);
    // 0x806D0D18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D0D1C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806D0D20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D0D24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806D0D28: lw          $t8, 0x1230($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(607, 0X1A90));
    // 0x806D0D2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806D0D30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806D0D34: jal         0x80048490
    // 0x806D0D38: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806D0D38: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806D0D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D0D44: jr          $ra
    // 0x806D0D48: nop

    return;
    // 0x806D0D48: nop

;}
RECOMP_FUNC void func_8064BCE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BCE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BCE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BCEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8064BCF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8064BCF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8064BCF8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8064BCFC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8064BD00: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8064BD04: bne         $v0, $at, L_8064BD2C
    if (ctx->r2 != ctx->r1) {
        // 0x8064BD08: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8064BD2C;
    }
    // 0x8064BD08: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8064BD0C: jal         0x8064A1C8
    // 0x8064BD10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8064A1C8(rdram, ctx);
        goto after_0;
    // 0x8064BD10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8064BD14: beq         $v0, $zero, L_8064BD2C
    if (ctx->r2 == 0) {
        // 0x8064BD18: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8064BD2C;
    }
    // 0x8064BD18: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8064BD1C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8064BD20: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8064BD24: jal         0x8002F6E4
    // 0x8064BD28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8064BD28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_8064BD2C:
    // 0x8064BD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8064BD30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BD34: jr          $ra
    // 0x8064BD38: nop

    return;
    // 0x8064BD38: nop

;}
RECOMP_FUNC void func_806F8C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8C58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F8C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8C60: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F8C64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F8C68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F8C6C: lwc1        $f6, 0x268($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X268);
    // 0x806F8C70: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x806F8C74: nop

    // 0x806F8C78: bc1f        L_806F8CBC
    if (!c1cs) {
        // 0x806F8C7C: nop
    
            goto L_806F8CBC;
    }
    // 0x806F8C7C: nop

    // 0x806F8C80: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806F8C84: jal         0x8004700C
    // 0x806F8C88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F8C88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F8C8C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8C90: beq         $v0, $zero, L_806F8CBC
    if (ctx->r2 == 0) {
        // 0x806F8C94: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806F8CBC;
    }
    // 0x806F8C94: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F8C98: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(694, 0X116C) << 16);
    // 0x806F8C9C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806F8CA0: addiu       $t7, $t7, -0x7684
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(694, 0X116C));
    // 0x806F8CA4: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806F8CA8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806F8CAC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806F8CB0: sb          $t8, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r24;
    // 0x806F8CB4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x806F8CB8: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
L_806F8CBC:
    // 0x806F8CBC: jal         0x806F85A0
    // 0x806F8CC0: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    func_806F85A0(rdram, ctx);
        goto after_1;
    // 0x806F8CC0: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    after_1:
    // 0x806F8CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8CC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8CCC: jr          $ra
    // 0x806F8CD0: nop

    return;
    // 0x806F8CD0: nop

;}
RECOMP_FUNC void func_804A455C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A455C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804A4560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A4564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A4568: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A456C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804A4570: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804A4574: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x804A4578: sltiu       $at, $t8, 0xA
    ctx->r1 = ctx->r24 < 0XA ? 1 : 0;
    // 0x804A457C: beq         $at, $zero, L_804A4614
    if (ctx->r1 == 0) {
        // 0x804A4580: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_804A4614;
    }
    // 0x804A4580: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804A4584: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(176, 0X10B0) << 16);
    // 0x804A4588: addu        $at, $at, $t8
    gpr jr_addend_804A4590 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x804A458C: lw          $t8, 0x4AB0($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(176, 0X10B0));
    // 0x804A4590: jr          $t8
    // 0x804A4594: nop

    switch (jr_addend_804A4590 >> 2) {
        case 0: goto L_804A4598; break;
        case 1: goto L_804A45A8; break;
        case 2: goto L_804A4614; break;
        case 3: goto L_804A45B8; break;
        case 4: goto L_804A45C8; break;
        case 5: goto L_804A45D8; break;
        case 6: goto L_804A4614; break;
        case 7: goto L_804A45E8; break;
        case 8: goto L_804A45F8; break;
        case 9: goto L_804A4608; break;
        default: switch_error(__func__, 0x804A4590, 0x804A4AB0);
    }
    // 0x804A4594: nop

L_804A4598:
    // 0x804A4598: jal         0x804A3C2C
    // 0x804A459C: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A3C2C(rdram, ctx);
        goto after_0;
    // 0x804A459C: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_0:
    // 0x804A45A0: b           L_804A4614
    // 0x804A45A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45A8:
    // 0x804A45A8: jal         0x804A3D4C
    // 0x804A45AC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A3D4C(rdram, ctx);
        goto after_1;
    // 0x804A45AC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_1:
    // 0x804A45B0: b           L_804A4614
    // 0x804A45B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45B8:
    // 0x804A45B8: jal         0x804A3E6C
    // 0x804A45BC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A3E6C(rdram, ctx);
        goto after_2;
    // 0x804A45BC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_2:
    // 0x804A45C0: b           L_804A4614
    // 0x804A45C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45C8:
    // 0x804A45C8: jal         0x804A3F8C
    // 0x804A45CC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A3F8C(rdram, ctx);
        goto after_3;
    // 0x804A45CC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_3:
    // 0x804A45D0: b           L_804A4614
    // 0x804A45D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45D8:
    // 0x804A45D8: jal         0x804A40B8
    // 0x804A45DC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A40B8(rdram, ctx);
        goto after_4;
    // 0x804A45DC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_4:
    // 0x804A45E0: b           L_804A4614
    // 0x804A45E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45E8:
    // 0x804A45E8: jal         0x804A41E4
    // 0x804A45EC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A41E4(rdram, ctx);
        goto after_5;
    // 0x804A45EC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_5:
    // 0x804A45F0: b           L_804A4614
    // 0x804A45F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A45F4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A45F8:
    // 0x804A45F8: jal         0x804A4304
    // 0x804A45FC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A4304(rdram, ctx);
        goto after_6;
    // 0x804A45FC: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_6:
    // 0x804A4600: b           L_804A4614
    // 0x804A4604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
        goto L_804A4614;
    // 0x804A4604: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A4608:
    // 0x804A4608: jal         0x804A4430
    // 0x804A460C: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    func_804A4430(rdram, ctx);
        goto after_7;
    // 0x804A460C: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    after_7:
    // 0x804A4610: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_804A4614:
    // 0x804A4614: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804A4618: addiu       $at, $zero, 0x41F9
    ctx->r1 = ADD32(0, 0X41F9);
    // 0x804A461C: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x804A4620: lhu         $t9, 0xC($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XC);
    // 0x804A4624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804A4628: bne         $t9, $at, L_804A4668
    if (ctx->r25 != ctx->r1) {
        // 0x804A462C: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_804A4668;
    }
    // 0x804A462C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x804A4630: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A4634: lwc1        $f0, 0x3C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x804A4638: lui         $at, 0x4391
    ctx->r1 = S32(0X4391 << 16);
    // 0x804A463C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x804A4640: nop

    // 0x804A4644: bc1tl       L_804A4668
    if (c1cs) {
        // 0x804A4648: lw          $v1, 0x180($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X180);
            goto L_804A4668;
    }
    goto skip_0;
    // 0x804A4648: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x804A464C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804A4650: nop

    // 0x804A4654: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x804A4658: nop

    // 0x804A465C: bc1fl       L_804A466C
    if (!c1cs) {
        // 0x804A4660: lw          $t0, 0x180($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X180);
            goto L_804A466C;
    }
    goto skip_1;
    // 0x804A4660: lw          $t0, 0x180($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x804A4664: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
L_804A4668:
    // 0x804A4668: lw          $t0, 0x180($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X180);
L_804A466C:
    // 0x804A466C: beql        $v1, $t0, L_804A4684
    if (ctx->r3 == ctx->r8) {
        // 0x804A4670: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804A4684;
    }
    goto skip_2;
    // 0x804A4670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x804A4674: jal         0x80067818
    // 0x804A4678: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x804A4678: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_8:
    // 0x804A467C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804A4680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_804A4684:
    // 0x804A4684: jal         0x80048060
    // 0x804A4688: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80048060(rdram, ctx);
        goto after_9;
    // 0x804A4688: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_9:
    // 0x804A468C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804A4690: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A4694: addiu       $at, $zero, 0x41F9
    ctx->r1 = ADD32(0, 0X41F9);
    // 0x804A4698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A469C: sw          $v1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r3;
    // 0x804A46A0: lhu         $t2, 0xC($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XC);
    // 0x804A46A4: beq         $t2, $at, L_804A46B8
    if (ctx->r10 == ctx->r1) {
        // 0x804A46A8: nop
    
            goto L_804A46B8;
    }
    // 0x804A46A8: nop

    // 0x804A46AC: lw          $t4, 0x1F4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1F4);
    // 0x804A46B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x804A46B4: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_804A46B8:
    // 0x804A46B8: jal         0x804A3AB0
    // 0x804A46BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804A3AB0(rdram, ctx);
        goto after_10;
    // 0x804A46BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x804A46C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A46C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A46C8: jal         0x804A491C
    // 0x804A46CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A491C(rdram, ctx);
        goto after_11;
    // 0x804A46CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x804A46D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804A46D4: jal         0x804A3A9C
    // 0x804A46D8: lw          $a0, 0x16C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X16C);
    func_804A3A9C(rdram, ctx);
        goto after_12;
    // 0x804A46D8: lw          $a0, 0x16C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X16C);
    after_12:
    // 0x804A46DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A46E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A46E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804A46E8: jr          $ra
    // 0x804A46EC: nop

    return;
    // 0x804A46EC: nop

;}
RECOMP_FUNC void func_80679CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80679CB0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80679CB4: slti        $at, $v0, 0x46A0
    ctx->r1 = SIGNED(ctx->r2) < 0X46A0 ? 1 : 0;
    // 0x80679CB8: bne         $at, $zero, L_80679CD4
    if (ctx->r1 != 0) {
        // 0x80679CBC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80679CD4;
    }
    // 0x80679CBC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80679CC0: slti        $at, $v0, 0x46A4
    ctx->r1 = SIGNED(ctx->r2) < 0X46A4 ? 1 : 0;
    // 0x80679CC4: beq         $at, $zero, L_80679CD4
    if (ctx->r1 == 0) {
        // 0x80679CC8: lui         $v0, 0x8068
        ctx->r2 = S32(RELOC_HI16(541, 0X23C4) << 16);
            goto L_80679CD4;
    }
    // 0x80679CC8: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(541, 0X23C4) << 16);
    // 0x80679CCC: jr          $ra
    // 0x80679CD0: addiu       $v0, $v0, -0x3F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X23C4));
    return;
    // 0x80679CD0: addiu       $v0, $v0, -0x3F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X23C4));
L_80679CD4:
    // 0x80679CD4: slti        $at, $v1, 0x46A4
    ctx->r1 = SIGNED(ctx->r3) < 0X46A4 ? 1 : 0;
    // 0x80679CD8: bne         $at, $zero, L_80679CF0
    if (ctx->r1 != 0) {
        // 0x80679CDC: slti        $at, $v1, 0x46A8
        ctx->r1 = SIGNED(ctx->r3) < 0X46A8 ? 1 : 0;
            goto L_80679CF0;
    }
    // 0x80679CDC: slti        $at, $v1, 0x46A8
    ctx->r1 = SIGNED(ctx->r3) < 0X46A8 ? 1 : 0;
    // 0x80679CE0: beq         $at, $zero, L_80679CF0
    if (ctx->r1 == 0) {
        // 0x80679CE4: lui         $v0, 0x8068
        ctx->r2 = S32(RELOC_HI16(541, 0X2434) << 16);
            goto L_80679CF0;
    }
    // 0x80679CE4: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(541, 0X2434) << 16);
    // 0x80679CE8: jr          $ra
    // 0x80679CEC: addiu       $v0, $v0, -0x3F1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X2434));
    return;
    // 0x80679CEC: addiu       $v0, $v0, -0x3F1C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X2434));
L_80679CF0:
    // 0x80679CF0: slti        $at, $v1, 0x46D4
    ctx->r1 = SIGNED(ctx->r3) < 0X46D4 ? 1 : 0;
    // 0x80679CF4: bne         $at, $zero, L_80679D14
    if (ctx->r1 != 0) {
        // 0x80679CF8: lui         $v0, 0x8068
        ctx->r2 = S32(RELOC_HI16(541, 0X2370) << 16);
            goto L_80679D14;
    }
    // 0x80679CF8: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(541, 0X2370) << 16);
    // 0x80679CFC: slti        $at, $v1, 0x46D8
    ctx->r1 = SIGNED(ctx->r3) < 0X46D8 ? 1 : 0;
    // 0x80679D00: beq         $at, $zero, L_80679D14
    if (ctx->r1 == 0) {
        // 0x80679D04: nop
    
            goto L_80679D14;
    }
    // 0x80679D04: nop

    // 0x80679D08: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(541, 0X24C4) << 16);
    // 0x80679D0C: jr          $ra
    // 0x80679D10: addiu       $v0, $v0, -0x3E8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X24C4));
    return;
    // 0x80679D10: addiu       $v0, $v0, -0x3E8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X24C4));
L_80679D14:
    // 0x80679D14: addiu       $v0, $v0, -0x3FE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(541, 0X2370));
    // 0x80679D18: jr          $ra
    // 0x80679D1C: nop

    return;
    // 0x80679D1C: nop

;}
RECOMP_FUNC void func_8005F9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F9A8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8005F9AC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8005F9B0: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8005F9B4: lw          $a0, -0x776C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X776C);
    // 0x8005F9B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F9C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005F9C4: jal         0x800579A0
    // 0x8005F9C8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_800579A0(rdram, ctx);
        goto after_0;
    // 0x8005F9C8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005F9CC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005F9D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F9D4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005F9D8: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8005F9DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8005F9E0: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x8005F9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F9E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F9EC: jr          $ra
    // 0x8005F9F0: nop

    return;
    // 0x8005F9F0: nop

;}
RECOMP_FUNC void func_8040A40C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040A40C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040A410: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040A414: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8040A418: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8040A41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040A420: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8040A424: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8040A428: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8040A42C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8040A430: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8040A434: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(11, 0X2DF0) << 16);
    // 0x8040A438: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8040A43C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8040A440: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8040A444: lw          $t2, -0x5840($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(11, 0X2DF0));
    // 0x8040A448: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8040A44C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8040A450: jal         0x80408628
    // 0x8040A454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80408628(rdram, ctx);
        goto after_0;
    // 0x8040A454: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040A458: jal         0x80408684
    // 0x8040A45C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80408684(rdram, ctx);
        goto after_1;
    // 0x8040A45C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040A460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040A464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040A468: jr          $ra
    // 0x8040A46C: nop

    return;
    // 0x8040A46C: nop

;}
RECOMP_FUNC void func_80047C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047C38: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80047C3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80047C40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047C44: beq         $a0, $zero, L_80047E5C
    if (ctx->r4 == 0) {
        // 0x80047C48: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80047E5C;
    }
    // 0x80047C48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80047C4C: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80047C50: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80047C54: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x80047C58: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x80047C5C: swc1        $f4, 0xA8($a0)
    MEM_W(0XA8, ctx->r4) = ctx->f4.u32l;
    // 0x80047C60: swc1        $f6, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f6.u32l;
    // 0x80047C64: beq         $v1, $zero, L_80047C78
    if (ctx->r3 == 0) {
        // 0x80047C68: swc1        $f8, 0xB0($a0)
        MEM_W(0XB0, ctx->r4) = ctx->f8.u32l;
            goto L_80047C78;
    }
    // 0x80047C68: swc1        $f8, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = ctx->f8.u32l;
    // 0x80047C6C: lbu         $v0, 0x17C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X17C);
    // 0x80047C70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80047C74: bne         $v0, $at, L_80047CA4
    if (ctx->r2 != ctx->r1) {
        // 0x80047C78: addiu       $a0, $s0, 0x84
        ctx->r4 = ADD32(ctx->r16, 0X84);
            goto L_80047CA4;
    }
L_80047C78:
    // 0x80047C78: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x80047C7C: jal         0x80065490
    // 0x80047C80: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80047C80: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    after_0:
    // 0x80047C84: addiu       $a0, $s0, 0x90
    ctx->r4 = ADD32(ctx->r16, 0X90);
    // 0x80047C88: jal         0x80065490
    // 0x80047C8C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x80047C8C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_1:
    // 0x80047C90: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x80047C94: jal         0x80065490
    // 0x80047C98: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x80047C98: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_2:
    // 0x80047C9C: b           L_80047E60
    // 0x80047CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80047E60;
    // 0x80047CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047CA4:
    // 0x80047CA4: bne         $v0, $zero, L_80047CFC
    if (ctx->r2 != 0) {
        // 0x80047CA8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80047CFC;
    }
    // 0x80047CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047CAC: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80047CB0: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047CB4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047CB8: addiu       $a0, $s0, 0x90
    ctx->r4 = ADD32(ctx->r16, 0X90);
    // 0x80047CBC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80047CC0: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047CC4: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80047CC8: swc1        $f18, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f18.u32l;
    // 0x80047CCC: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80047CD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047CD4: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
    // 0x80047CD8: lwc1        $f16, 0x8C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x80047CDC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80047CE0: jal         0x80065490
    // 0x80047CE4: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x80047CE4: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80047CE8: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x80047CEC: jal         0x80065490
    // 0x80047CF0: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x80047CF0: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_4:
    // 0x80047CF4: b           L_80047E60
    // 0x80047CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80047E60;
    // 0x80047CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047CFC:
    // 0x80047CFC: beq         $v0, $at, L_80047D10
    if (ctx->r2 == ctx->r1) {
        // 0x80047D00: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80047D10;
    }
    // 0x80047D00: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80047D04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80047D08: bne         $v0, $at, L_80047E3C
    if (ctx->r2 != ctx->r1) {
        // 0x80047D0C: addiu       $a0, $s0, 0x84
        ctx->r4 = ADD32(ctx->r16, 0X84);
            goto L_80047E3C;
    }
    // 0x80047D0C: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
L_80047D10:
    // 0x80047D10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047D14: lwc1        $f4, 0x98($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X98);
    // 0x80047D18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047D1C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80047D20: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80047D24: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80047D28: jal         0x80047648
    // 0x80047D2C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    func_80047648(rdram, ctx);
        goto after_5;
    // 0x80047D2C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80047D30: lbu         $t6, 0x17C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X17C);
    // 0x80047D34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047D38: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80047D3C: bnel        $t6, $at, L_80047D64
    if (ctx->r14 != ctx->r1) {
        // 0x80047D40: lwc1        $f10, 0x40($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80047D64;
    }
    goto skip_0;
    // 0x80047D40: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80047D44: jal         0x80049018
    // 0x80047D48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80049018(rdram, ctx);
        goto after_6;
    // 0x80047D48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_6:
    // 0x80047D4C: beq         $v0, $zero, L_80047D60
    if (ctx->r2 == 0) {
        // 0x80047D50: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_80047D60;
    }
    // 0x80047D50: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047D54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80047D58: nop

    // 0x80047D5C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_80047D60:
    // 0x80047D60: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
L_80047D64:
    // 0x80047D64: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047D68: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80047D6C: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80047D70: jal         0x80066E88
    // 0x80047D74: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x80047D74: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x80047D78: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80047D7C: jal         0x80066DE4
    // 0x80047D80: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x80047D80: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80047D84: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80047D88: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80047D8C: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80047D90: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80047D94: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80047D98: addiu       $a0, $s0, 0x90
    ctx->r4 = ADD32(ctx->r16, 0X90);
    // 0x80047D9C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    // 0x80047DA0: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80047DA4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80047DA8: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80047DAC: nop

    // 0x80047DB0: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80047DB4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80047DB8: swc1        $f16, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f16.u32l;
    // 0x80047DBC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80047DC0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80047DC4: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80047DC8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80047DCC: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
    // 0x80047DD0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80047DD4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80047DD8: jal         0x80065490
    // 0x80047DDC: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    func_80065490(rdram, ctx);
        goto after_9;
    // 0x80047DDC: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    after_9:
    // 0x80047DE0: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x80047DE4: jal         0x80065490
    // 0x80047DE8: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_10;
    // 0x80047DE8: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_10:
    // 0x80047DEC: lbu         $t7, 0x17C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X17C);
    // 0x80047DF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80047DF4: bnel        $t7, $at, L_80047E24
    if (ctx->r15 != ctx->r1) {
        // 0x80047DF8: lwc1        $f16, 0x40($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80047E24;
    }
    goto skip_1;
    // 0x80047DF8: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    skip_1:
    // 0x80047DFC: jal         0x80049018
    // 0x80047E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_11;
    // 0x80047E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80047E04: beq         $v0, $zero, L_80047E20
    if (ctx->r2 == 0) {
        // 0x80047E08: lwc1        $f10, 0x34($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
            goto L_80047E20;
    }
    // 0x80047E08: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047E0C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80047E10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047E14: nop

    // 0x80047E18: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80047E1C: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_80047E20:
    // 0x80047E20: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
L_80047E24:
    // 0x80047E24: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80047E28: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80047E2C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80047E30: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80047E34: b           L_80047E5C
    // 0x80047E38: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
        goto L_80047E5C;
    // 0x80047E38: swc1        $f6, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f6.u32l;
L_80047E3C:
    // 0x80047E3C: jal         0x80065490
    // 0x80047E40: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    func_80065490(rdram, ctx);
        goto after_12;
    // 0x80047E40: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    after_12:
    // 0x80047E44: addiu       $a0, $s0, 0x90
    ctx->r4 = ADD32(ctx->r16, 0X90);
    // 0x80047E48: jal         0x80065490
    // 0x80047E4C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    func_80065490(rdram, ctx);
        goto after_13;
    // 0x80047E4C: addiu       $a1, $s0, 0x48
    ctx->r5 = ADD32(ctx->r16, 0X48);
    after_13:
    // 0x80047E50: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x80047E54: jal         0x80065490
    // 0x80047E58: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_14;
    // 0x80047E58: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_14:
L_80047E5C:
    // 0x80047E5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047E60:
    // 0x80047E60: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80047E64: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80047E68: jr          $ra
    // 0x80047E6C: nop

    return;
    // 0x80047E6C: nop

;}
RECOMP_FUNC void func_80569158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80569158: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8056915C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80569160: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80569164: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80569168: addiu       $at, $zero, 0x415B
    ctx->r1 = ADD32(0, 0X415B);
    // 0x8056916C: beq         $v0, $at, L_8056918C
    if (ctx->r2 == ctx->r1) {
        // 0x80569170: addiu       $at, $zero, 0x4167
        ctx->r1 = ADD32(0, 0X4167);
            goto L_8056918C;
    }
    // 0x80569170: addiu       $at, $zero, 0x4167
    ctx->r1 = ADD32(0, 0X4167);
    // 0x80569174: beq         $v0, $at, L_8056919C
    if (ctx->r2 == ctx->r1) {
        // 0x80569178: addiu       $at, $zero, 0x4173
        ctx->r1 = ADD32(0, 0X4173);
            goto L_8056919C;
    }
    // 0x80569178: addiu       $at, $zero, 0x4173
    ctx->r1 = ADD32(0, 0X4173);
    // 0x8056917C: beql        $v0, $at, L_805691AC
    if (ctx->r2 == ctx->r1) {
        // 0x80569180: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_805691AC;
    }
    goto skip_0;
    // 0x80569180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80569184: b           L_805691B8
    // 0x80569188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_805691B8;
    // 0x80569188: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_8056918C:
    // 0x8056918C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80569190: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80569194: b           L_805691B8
    // 0x80569198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
        goto L_805691B8;
    // 0x80569198: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_8056919C:
    // 0x8056919C: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X2218) << 16);
    // 0x805691A0: b           L_805691B4
    // 0x805691A4: lwc1        $f0, -0x6838($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2218));
        goto L_805691B4;
    // 0x805691A4: lwc1        $f0, -0x6838($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X2218));
    // 0x805691A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_805691AC:
    // 0x805691AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805691B0: nop

L_805691B4:
    // 0x805691B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_805691B8:
    // 0x805691B8: jal         0x80568710
    // 0x805691BC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x805691BC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805691C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805691C4: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805691C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805691CC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805691D0: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x805691D4: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x805691D8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x805691DC: jal         0x80569310
    // 0x805691E0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x805691E0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x805691E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805691E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805691EC: jr          $ra
    // 0x805691F0: nop

    return;
    // 0x805691F0: nop

;}
RECOMP_FUNC void func_80704B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80704B24: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80704B28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80704B2C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80704B30: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80704B34: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80704B38: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80704B3C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80704B40: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80704B44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80704B48: lw          $v1, 0xD8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XD8);
    // 0x80704B4C: beq         $v0, $zero, L_80704B58
    if (ctx->r2 == 0) {
        // 0x80704B50: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80704B58;
    }
    // 0x80704B50: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80704B54: sw          $t6, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r14;
L_80704B58:
    // 0x80704B58: lw          $t7, 0xA68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XA68);
    // 0x80704B5C: andi        $t0, $v1, 0x3
    ctx->r8 = ctx->r3 & 0X3;
    // 0x80704B60: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80704B64: lw          $t9, 0x70($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X70);
    // 0x80704B68: beql        $t9, $zero, L_80704C28
    if (ctx->r25 == 0) {
        // 0x80704B6C: lw          $t5, 0x20($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X20);
            goto L_80704C28;
    }
    goto skip_0;
    // 0x80704B6C: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
    skip_0:
    // 0x80704B70: bne         $t0, $zero, L_80704C24
    if (ctx->r8 != 0) {
        // 0x80704B74: lui         $at, 0x4140
        ctx->r1 = S32(0X4140 << 16);
            goto L_80704C24;
    }
    // 0x80704B74: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80704B78: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80704B7C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80704B80: jal         0x80703E30
    // 0x80704B84: nop

    func_80703E30(rdram, ctx);
        goto after_0;
    // 0x80704B84: nop

    after_0:
    // 0x80704B88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80704B8C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80704B90: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80704B94: jal         0x80703E30
    // 0x80704B98: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80703E30(rdram, ctx);
        goto after_1;
    // 0x80704B98: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80704B9C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80704BA0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80704BA4: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38A0) << 16);
    // 0x80704BA8: lwc1        $f14, 0x6D10($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38A0));
    // 0x80704BAC: jal         0x80703E30
    // 0x80704BB0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80703E30(rdram, ctx);
        goto after_2;
    // 0x80704BB0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80704BB4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80704BB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80704BBC: jal         0x80703E8C
    // 0x80704BC0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_80703E8C(rdram, ctx);
        goto after_3;
    // 0x80704BC0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_3:
    // 0x80704BC4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80704BC8: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(709, 0X3788) << 16);
    // 0x80704BCC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80704BD0: lw          $t2, 0x6BF8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(709, 0X3788));
    // 0x80704BD4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80704BD8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80704BDC: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x80704BE0: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x80704BE4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80704BE8: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80704BEC: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38A4) << 16);
    // 0x80704BF0: lwc1        $f18, 0x6D14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38A4));
    // 0x80704BF4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80704BF8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80704BFC: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x80704C00: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80704C04: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80704C08: lw          $t9, 0x70($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X70);
    // 0x80704C0C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80704C10: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80704C14: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80704C18: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80704C1C: jalr        $t9
    // 0x80704C20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80704C20: nop

    after_4:
L_80704C24:
    // 0x80704C24: lw          $t5, 0x20($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X20);
L_80704C28:
    // 0x80704C28: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x80704C2C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38A8) << 16);
    // 0x80704C30: bne         $t5, $zero, L_80704C70
    if (ctx->r13 != 0) {
        // 0x80704C34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80704C70;
    }
    // 0x80704C34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80704C38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80704C3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80704C40: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x80704C44: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x80704C48: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x80704C4C: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x80704C50: lwc1        $f10, 0x6D18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38A8));
    // 0x80704C54: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38AC) << 16);
    // 0x80704C58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80704C5C: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x80704C60: lwc1        $f16, 0x6D1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X38AC));
    // 0x80704C64: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80704C68: jal         0x80705A5C
    // 0x80704C6C: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    func_80705A5C(rdram, ctx);
        goto after_5;
    // 0x80704C6C: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    after_5:
L_80704C70:
    // 0x80704C70: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x80704C74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80704C78: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80704C7C: jal         0x80048F84
    // 0x80704C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x80704C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80704C84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80704C88: jal         0x80048F84
    // 0x80704C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x80704C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80704C90: jal         0x8070384C
    // 0x80704C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_8;
    // 0x80704C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80704C98: jal         0x80703F10
    // 0x80704C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_9;
    // 0x80704C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80704CA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80704CA4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80704CA8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80704CAC: jr          $ra
    // 0x80704CB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80704CB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8064C8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C8A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C8A8: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8064C8AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064C8B0: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064C8B4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8064C8B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C8BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C8C0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8064C8C4: bc1fl       L_8064C8E8
    if (!c1cs) {
        // 0x8064C8C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C8E8;
    }
    goto skip_0;
    // 0x8064C8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C8CC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064C8D0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064C8D4: jal         0x8064CD50
    // 0x8064C8D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C8D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064C8DC: jal         0x8064A40C
    // 0x8064C8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8064A40C(rdram, ctx);
        goto after_1;
    // 0x8064C8E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8064C8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C8E8:
    // 0x8064C8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C8EC: jr          $ra
    // 0x8064C8F0: nop

    return;
    // 0x8064C8F0: nop

;}
RECOMP_FUNC void func_805AA6F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA6F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA6F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA6FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AA700: lh          $a2, 0x13C($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X13C);
    // 0x805AA704: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x805AA708: lw          $a1, 0x38($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X38);
    // 0x805AA70C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805AA710: jal         0x800591EC
    // 0x805AA714: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    func_800591EC(rdram, ctx);
        goto after_0;
    // 0x805AA714: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_0:
    // 0x805AA718: bnel        $v0, $zero, L_805AA72C
    if (ctx->r2 != 0) {
        // 0x805AA71C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AA72C;
    }
    goto skip_0;
    // 0x805AA71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AA720: jal         0x800447C8
    // 0x805AA724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x805AA724: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805AA728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA72C:
    // 0x805AA72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA730: jr          $ra
    // 0x805AA734: nop

    return;
    // 0x805AA734: nop

;}
RECOMP_FUNC void func_806B2CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2CA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2CA8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2CAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2CB0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2CB4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2CB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2CBC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2CC0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2CC4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2CC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2CCC: jr          $ra
    // 0x806B2CD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2CD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x806B2CD4: nop

    // 0x806B2CD8: nop

    // 0x806B2CDC: nop

;}
RECOMP_FUNC void func_80401438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80401438: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8040143C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80401440: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80401444: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80401448: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8040144C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80401450: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80401454: jal         0x8004700C
    // 0x80401458: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80401458: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8040145C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80401460: jal         0x80400B50
    // 0x80401464: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    func_80400B50(rdram, ctx);
        goto after_1;
    // 0x80401464: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    after_1:
    // 0x80401468: jal         0x80400F7C
    // 0x8040146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80400F7C(rdram, ctx);
        goto after_2;
    // 0x8040146C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80401470: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80401474: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80401478: jal         0x80048F84
    // 0x8040147C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8040147C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80401480: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80401484: jal         0x80048F84
    // 0x80401488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80401488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8040148C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80401490: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80401494: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80401498: beql        $t7, $zero, L_804014E0
    if (ctx->r15 == 0) {
        // 0x8040149C: lw          $t1, 0x130($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X130);
            goto L_804014E0;
    }
    goto skip_0;
    // 0x8040149C: lw          $t1, 0x130($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X130);
    skip_0:
    // 0x804014A0: lw          $t8, 0xAA4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAA4);
    // 0x804014A4: beql        $t8, $zero, L_804014E0
    if (ctx->r24 == 0) {
        // 0x804014A8: lw          $t1, 0x130($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X130);
            goto L_804014E0;
    }
    goto skip_1;
    // 0x804014A8: lw          $t1, 0x130($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X130);
    skip_1:
    // 0x804014AC: lw          $t9, 0x478($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X478);
    // 0x804014B0: lbu         $t0, 0xF0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XF0);
    // 0x804014B4: beql        $t0, $zero, L_804014E0
    if (ctx->r8 == 0) {
        // 0x804014B8: lw          $t1, 0x130($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X130);
            goto L_804014E0;
    }
    goto skip_2;
    // 0x804014B8: lw          $t1, 0x130($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X130);
    skip_2:
    // 0x804014BC: jal         0x80059278
    // 0x804014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80059278(rdram, ctx);
        goto after_5;
    // 0x804014C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804014C4: beql        $v0, $zero, L_804014E0
    if (ctx->r2 == 0) {
        // 0x804014C8: lw          $t1, 0x130($s1)
        ctx->r9 = MEM_W(ctx->r17, 0X130);
            goto L_804014E0;
    }
    goto skip_3;
    // 0x804014C8: lw          $t1, 0x130($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X130);
    skip_3:
    // 0x804014CC: jal         0x804011D8
    // 0x804014D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804011D8(rdram, ctx);
        goto after_6;
    // 0x804014D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804014D4: b           L_8040164C
    // 0x804014D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8040164C;
    // 0x804014D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804014DC: lw          $t1, 0x130($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X130);
L_804014E0:
    // 0x804014E0: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X7718) << 16);
    // 0x804014E4: beql        $t1, $zero, L_80401574
    if (ctx->r9 == 0) {
        // 0x804014E8: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_80401574;
    }
    goto skip_4;
    // 0x804014E8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    skip_4:
    // 0x804014EC: lwc1        $f2, 0x7758($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X7718));
    // 0x804014F0: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x804014F4: lui         $at, 0x8040
    ctx->r1 = S32(RELOC_HI16(8, 0X771C) << 16);
    // 0x804014F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804014FC: nop

    // 0x80401500: bc1tl       L_8040164C
    if (c1cs) {
        // 0x80401504: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040164C;
    }
    goto skip_5;
    // 0x80401504: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80401508: lwc1        $f12, 0x775C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(8, 0X771C));
    // 0x8040150C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80401510: nop

    // 0x80401514: bc1tl       L_8040164C
    if (c1cs) {
        // 0x80401518: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040164C;
    }
    goto skip_6;
    // 0x80401518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8040151C: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80401520: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80401524: nop

    // 0x80401528: bc1tl       L_8040164C
    if (c1cs) {
        // 0x8040152C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040164C;
    }
    goto skip_7;
    // 0x8040152C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80401530: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80401534: nop

    // 0x80401538: bc1tl       L_8040164C
    if (c1cs) {
        // 0x8040153C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040164C;
    }
    goto skip_8;
    // 0x8040153C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80401540: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x80401544: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80401548: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x8040154C: lwc1        $f6, 0x13C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X13C);
    // 0x80401550: swc1        $f6, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f6.u32l;
    // 0x80401554: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    // 0x80401558: swc1        $f8, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f8.u32l;
    // 0x8040155C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80401560: swc1        $f10, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f10.u32l;
    // 0x80401564: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80401568: b           L_80401648
    // 0x8040156C: swc1        $f16, 0x120($s1)
    MEM_W(0X120, ctx->r17) = ctx->f16.u32l;
        goto L_80401648;
    // 0x8040156C: swc1        $f16, 0x120($s1)
    MEM_W(0X120, ctx->r17) = ctx->f16.u32l;
    // 0x80401570: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_80401574:
    // 0x80401574: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80401578: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8040157C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80401580: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80401584: nop

    // 0x80401588: bc1fl       L_804015C8
    if (!c1cs) {
        // 0x8040158C: lw          $t7, 0x0($t6)
        ctx->r15 = MEM_W(ctx->r14, 0X0);
            goto L_804015C8;
    }
    goto skip_9;
    // 0x8040158C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    skip_9:
    // 0x80401590: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80401594: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80401598: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x8040159C: lbu         $t5, 0x44($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X44);
    // 0x804015A0: beq         $t5, $zero, L_804015F0
    if (ctx->r13 == 0) {
        // 0x804015A4: nop
    
            goto L_804015F0;
    }
    // 0x804015A4: nop

    // 0x804015A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804015AC: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x804015B0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804015B4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x804015B8: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x804015BC: b           L_804015F0
    // 0x804015C0: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
        goto L_804015F0;
    // 0x804015C0: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x804015C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
L_804015C8:
    // 0x804015C8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804015CC: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x804015D0: lbu         $t9, 0x5C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X5C);
    // 0x804015D4: beq         $t9, $zero, L_804015F0
    if (ctx->r25 == 0) {
        // 0x804015D8: nop
    
            goto L_804015F0;
    }
    // 0x804015D8: nop

    // 0x804015DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804015E0: lwc1        $f16, 0x138($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X138);
    // 0x804015E4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x804015E8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
    // 0x804015EC: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
L_804015F0:
    // 0x804015F0: jal         0x80066DE4
    // 0x804015F4: lwc1        $f12, 0x128($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X128);
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x804015F4: lwc1        $f12, 0x128($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X128);
    after_7:
    // 0x804015F8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804015FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80401600: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80401604: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80401608: lwc1        $f10, 0x120($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X120);
    // 0x8040160C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80401610: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80401614: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80401618: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040161C: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x80401620: lwc1        $f18, 0x128($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X128);
    // 0x80401624: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80401628: swc1        $f6, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f6.u32l;
    // 0x8040162C: lwc1        $f2, 0x128($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X128);
    // 0x80401630: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80401634: nop

    // 0x80401638: bc1fl       L_8040164C
    if (!c1cs) {
        // 0x8040163C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8040164C;
    }
    goto skip_10;
    // 0x8040163C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80401640: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80401644: swc1        $f8, 0x128($s1)
    MEM_W(0X128, ctx->r17) = ctx->f8.u32l;
L_80401648:
    // 0x80401648: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8040164C:
    // 0x8040164C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80401650: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80401654: jr          $ra
    // 0x80401658: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80401658: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80042578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004257C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042580: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80042584: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80042588: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004258C: jal         0x80042290
    // 0x80042590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80042290(rdram, ctx);
        goto after_0;
    // 0x80042590: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80042594: jal         0x800422B4
    // 0x80042598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800422B4(rdram, ctx);
        goto after_1;
    // 0x80042598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004259C: jal         0x80042314
    // 0x800425A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80042314(rdram, ctx);
        goto after_2;
    // 0x800425A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800425A4: jal         0x8004246C
    // 0x800425A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004246C(rdram, ctx);
        goto after_3;
    // 0x800425A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800425AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800425B0: jal         0x800424A4
    // 0x800425B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800424A4(rdram, ctx);
        goto after_4;
    // 0x800425B4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800425B8: jal         0x80042558
    // 0x800425BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80042558(rdram, ctx);
        goto after_5;
    // 0x800425BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800425C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800425C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800425C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800425CC: jr          $ra
    // 0x800425D0: nop

    return;
    // 0x800425D0: nop

;}
RECOMP_FUNC void func_804490A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804490A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804490A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804490A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804490AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804490B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804490B4: bne         $a2, $zero, L_804490F4
    if (ctx->r6 != 0) {
        // 0x804490B8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804490F4;
    }
    // 0x804490B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804490BC: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x804490C0: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    // 0x804490C4: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x804490C8: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804490CC: bne         $at, $zero, L_80449134
    if (ctx->r1 != 0) {
        // 0x804490D0: sw          $t7, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->r15;
            goto L_80449134;
    }
    // 0x804490D0: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    // 0x804490D4: jal         0x804468D4
    // 0x804490D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_0;
    // 0x804490D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804490DC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804490E0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804490E4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x804490E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804490EC: b           L_80449134
    // 0x804490F0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80449134;
    // 0x804490F0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_804490F4:
    // 0x804490F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804490F8: bnel        $a2, $at, L_80449124
    if (ctx->r6 != ctx->r1) {
        // 0x804490FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80449124;
    }
    goto skip_0;
    // 0x804490FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80449100: jal         0x804468D4
    // 0x80449104: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804468D4(rdram, ctx);
        goto after_1;
    // 0x80449104: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449108: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044910C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449110: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80449114: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449118: b           L_80449134
    // 0x8044911C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80449134;
    // 0x8044911C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80449120: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80449124:
    // 0x80449124: bnel        $a2, $at, L_80449138
    if (ctx->r6 != ctx->r1) {
        // 0x80449128: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449138;
    }
    goto skip_1;
    // 0x80449128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044912C: jal         0x80446938
    // 0x80449130: nop

    func_80446938(rdram, ctx);
        goto after_2;
    // 0x80449130: nop

    after_2:
L_80449134:
    // 0x80449134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449138:
    // 0x80449138: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044913C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449140: jr          $ra
    // 0x80449144: nop

    return;
    // 0x80449144: nop

;}
RECOMP_FUNC void func_807892D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807892D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x807892D8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x807892DC: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x807892E0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x807892E4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x807892E8: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x807892EC: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x807892F0: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x807892F4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x807892F8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x807892FC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80789300: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80789304: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80789308: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8078930C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80789310: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80789314: lw          $s6, 0x1F4($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X1F4);
    // 0x80789318: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x8078931C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80789320: lwc1        $f4, 0x52C8($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X52C8);
    // 0x80789324: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80789328: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8078932C: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80789330: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80789334: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80789338: addiu       $s5, $zero, 0x16A
    ctx->r21 = ADD32(0, 0X16A);
    // 0x8078933C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80789340: or          $fp, $s6, $zero
    ctx->r30 = ctx->r22 | 0;
    // 0x80789344: mul.s       $f24, $f6, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80789348: nop

    // 0x8078934C: mul.s       $f26, $f10, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80789350: nop

L_80789354:
    // 0x80789354: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x80789358: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x8078935C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80789360: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80789364: or          $s1, $s6, $zero
    ctx->r17 = ctx->r22 | 0;
    // 0x80789368: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
L_8078936C:
    // 0x8078936C: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80789370: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x80789374: lh          $t6, 0x10($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X10);
    // 0x80789378: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8078937C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80789380: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80789384: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80789388: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8078938C: sh          $t6, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r14;
    // 0x80789390: sh          $v0, -0xE($s0)
    MEM_H(-0XE, ctx->r16) = ctx->r2;
    // 0x80789394: jal         0x8078743C
    // 0x80789398: sh          $v0, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r2;
    func_8078743C(rdram, ctx);
        goto after_0;
    // 0x80789398: sh          $v0, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r2;
    after_0:
    // 0x8078939C: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x807893A0: swc1        $f0, 0x4990($s1)
    MEM_W(0X4990, ctx->r17) = ctx->f0.u32l;
    // 0x807893A4: swc1        $f0, 0x4F38($s1)
    MEM_W(0X4F38, ctx->r17) = ctx->f0.u32l;
    // 0x807893A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x807893AC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807893B0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x807893B4: swc1        $f22, 0x43E0($s2)
    MEM_W(0X43E0, ctx->r18) = ctx->f22.u32l;
    // 0x807893B8: bne         $s4, $s5, L_8078936C
    if (ctx->r20 != ctx->r21) {
        // 0x807893BC: swc1        $f22, 0x43E4($s2)
        MEM_W(0X43E4, ctx->r18) = ctx->f22.u32l;
            goto L_8078936C;
    }
    // 0x807893BC: swc1        $f22, 0x43E4($s2)
    MEM_W(0X43E4, ctx->r18) = ctx->f22.u32l;
    // 0x807893C0: addiu       $s7, $s7, 0x16A0
    ctx->r23 = ADD32(ctx->r23, 0X16A0);
    // 0x807893C4: addiu       $at, $zero, 0x43E0
    ctx->r1 = ADD32(0, 0X43E0);
    // 0x807893C8: bne         $s7, $at, L_80789354
    if (ctx->r23 != ctx->r1) {
        // 0x807893CC: addiu       $fp, $fp, 0x16A0
        ctx->r30 = ADD32(ctx->r30, 0X16A0);
            goto L_80789354;
    }
    // 0x807893CC: addiu       $fp, $fp, 0x16A0
    ctx->r30 = ADD32(ctx->r30, 0X16A0);
    // 0x807893D0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x807893D4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x807893D8: swc1        $f6, 0x52CC($s6)
    MEM_W(0X52CC, ctx->r22) = ctx->f6.u32l;
    // 0x807893DC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x807893E0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x807893E4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x807893E8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x807893EC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x807893F0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x807893F4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x807893F8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x807893FC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80789400: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80789404: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80789408: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8078940C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80789410: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80789414: jr          $ra
    // 0x80789418: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80789418: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_806EDBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EDBBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EDBC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EDBC4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EDBC8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EDBCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EDBD0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EDBD4: jal         0x800577D8
    // 0x806EDBD8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EDBD8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EDBDC: jal         0x806ED57C
    // 0x806EDBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED57C(rdram, ctx);
        goto after_1;
    // 0x806EDBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EDBE4: jal         0x806ED5F0
    // 0x806EDBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED5F0(rdram, ctx);
        goto after_2;
    // 0x806EDBE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EDBEC: jal         0x806ED6C4
    // 0x806EDBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED6C4(rdram, ctx);
        goto after_3;
    // 0x806EDBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EDBF4: bne         $v0, $zero, L_806EDC14
    if (ctx->r2 != 0) {
        // 0x806EDBF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDC14;
    }
    // 0x806EDBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDBFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDC00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EDC04: jal         0x806EE584
    // 0x806EDC08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_4;
    // 0x806EDC08: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EDC0C: b           L_806EDC88
    // 0x806EDC10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDC88;
    // 0x806EDC10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDC14:
    // 0x806EDC14: jal         0x806ED714
    // 0x806EDC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED714(rdram, ctx);
        goto after_5;
    // 0x806EDC18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EDC1C: beq         $v0, $zero, L_806EDC3C
    if (ctx->r2 == 0) {
        // 0x806EDC20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EDC3C;
    }
    // 0x806EDC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDC24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDC28: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EDC2C: jal         0x806EE584
    // 0x806EDC30: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_6;
    // 0x806EDC30: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EDC34: b           L_806EDC88
    // 0x806EDC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDC88;
    // 0x806EDC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDC3C:
    // 0x806EDC3C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x806EDC40: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EDC44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EDC48: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x806EDC4C: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806EDC50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EDC54: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x806EDC58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EDC5C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806EDC60: nop

    // 0x806EDC64: bc1f        L_806EDC7C
    if (!c1cs) {
        // 0x806EDC68: nop
    
            goto L_806EDC7C;
    }
    // 0x806EDC68: nop

    // 0x806EDC6C: jal         0x806EE584
    // 0x806EDC70: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EE584(rdram, ctx);
        goto after_7;
    // 0x806EDC70: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EDC74: b           L_806EDC88
    // 0x806EDC78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EDC88;
    // 0x806EDC78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDC7C:
    // 0x806EDC7C: jal         0x806ED844
    // 0x806EDC80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED844(rdram, ctx);
        goto after_8;
    // 0x806EDC80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806EDC84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EDC88:
    // 0x806EDC88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EDC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EDC90: jr          $ra
    // 0x806EDC94: nop

    return;
    // 0x806EDC94: nop

;}
RECOMP_FUNC void func_804C4000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C4004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C4008: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x804C400C: addiu       $at, $zero, 0x405E
    ctx->r1 = ADD32(0, 0X405E);
    // 0x804C4010: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804C4014: beq         $v1, $at, L_804C4028
    if (ctx->r3 == ctx->r1) {
        // 0x804C4018: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804C4028;
    }
    // 0x804C4018: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C401C: addiu       $at, $zero, 0x405F
    ctx->r1 = ADD32(0, 0X405F);
    // 0x804C4020: bnel        $v1, $at, L_804C4040
    if (ctx->r3 != ctx->r1) {
        // 0x804C4024: lh          $t6, 0x1C($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X1C);
            goto L_804C4040;
    }
    goto skip_0;
    // 0x804C4024: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
    skip_0:
L_804C4028:
    // 0x804C4028: lwc1        $f4, 0x78($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X78);
    // 0x804C402C: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804C4030: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804C4034: b           L_804C40A0
    // 0x804C4038: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
        goto L_804C40A0;
    // 0x804C4038: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
    // 0x804C403C: lh          $t6, 0x1C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1C);
L_804C4040:
    // 0x804C4040: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x804C4044: sh          $t7, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r15;
    // 0x804C4048: lh          $v1, 0x1C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1C);
    // 0x804C404C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x804C4050: bnel        $at, $zero, L_804C4064
    if (ctx->r1 != 0) {
        // 0x804C4054: addiu       $a0, $v1, -0x80
        ctx->r4 = ADD32(ctx->r3, -0X80);
            goto L_804C4064;
    }
    goto skip_1;
    // 0x804C4054: addiu       $a0, $v1, -0x80
    ctx->r4 = ADD32(ctx->r3, -0X80);
    skip_1:
    // 0x804C4058: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x804C405C: lh          $v1, 0x1C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1C);
    // 0x804C4060: addiu       $a0, $v1, -0x80
    ctx->r4 = ADD32(ctx->r3, -0X80);
L_804C4064:
    // 0x804C4064: jal         0x8006593C
    // 0x804C4068: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x804C4068: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x804C406C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x804C4070: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE60) << 16);
    // 0x804C4074: lwc1        $f16, 0x4E50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE60));
    // 0x804C4078: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804C407C: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(209, 0XE64) << 16);
    // 0x804C4080: lwc1        $f4, 0x4E54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(209, 0XE64));
    // 0x804C4084: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C4088: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804C408C: lwc1        $f8, 0x78($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X78);
    // 0x804C4090: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804C4094: mul.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804C4098: nop

    // 0x804C409C: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
L_804C40A0:
    // 0x804C40A0: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x804C40A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C40A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C40AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804C40B0: jr          $ra
    // 0x804C40B4: nop

    return;
    // 0x804C40B4: nop

;}
RECOMP_FUNC void func_8057F484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F484: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8057F488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F48C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F490: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8057F494: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8057F498: lw          $t6, 0x5C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X5C);
    // 0x8057F49C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8057F4A0: jal         0x80047AB8
    // 0x8057F4A4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8057F4A4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x8057F4A8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8057F4AC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8057F4B0: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8057F4B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8057F4B8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8057F4BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8057F4C0: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x8057F4C4: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8057F4C8: addiu       $v1, $a2, 0x64
    ctx->r3 = ADD32(ctx->r6, 0X64);
    // 0x8057F4CC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8057F4D0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057F4D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8057F4D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8057F4DC: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x8057F4E0: swc1        $f8, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->f8.u32l;
    // 0x8057F4E4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8057F4E8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057F4EC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8057F4F0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8057F4F4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8057F4F8: swc1        $f6, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f6.u32l;
    // 0x8057F4FC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8057F500: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8057F504: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8057F508: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057F50C: swc1        $f16, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f16.u32l;
    // 0x8057F510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F514: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8057F518: jr          $ra
    // 0x8057F51C: nop

    return;
    // 0x8057F51C: nop

;}
RECOMP_FUNC void func_80422A10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80422A14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80422A18: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80422A1C: slti        $at, $v0, 0x4068
    ctx->r1 = SIGNED(ctx->r2) < 0X4068 ? 1 : 0;
    // 0x80422A20: bne         $at, $zero, L_80422A64
    if (ctx->r1 != 0) {
        // 0x80422A24: addiu       $t6, $v0, -0x40A9
        ctx->r14 = ADD32(ctx->r2, -0X40A9);
            goto L_80422A64;
    }
    // 0x80422A24: addiu       $t6, $v0, -0x40A9
    ctx->r14 = ADD32(ctx->r2, -0X40A9);
    // 0x80422A28: slti        $at, $v0, 0x4069
    ctx->r1 = SIGNED(ctx->r2) < 0X4069 ? 1 : 0;
    // 0x80422A2C: bne         $at, $zero, L_80422A50
    if (ctx->r1 != 0) {
        // 0x80422A30: sltiu       $at, $t6, 0x5
        ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
            goto L_80422A50;
    }
    // 0x80422A30: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80422A34: beq         $at, $zero, L_80422AF8
    if (ctx->r1 == 0) {
        // 0x80422A38: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80422AF8;
    }
    // 0x80422A38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80422A3C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36B0) << 16);
    // 0x80422A40: addu        $at, $at, $t6
    gpr jr_addend_80422A48 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80422A44: lw          $t6, 0x60B0($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(35, 0X36B0));
    // 0x80422A48: jr          $t6
    // 0x80422A4C: nop

    switch (jr_addend_80422A48 >> 2) {
        case 0: goto L_80422AB0; break;
        case 1: goto L_80422AC0; break;
        case 2: goto L_80422AD0; break;
        case 3: goto L_80422AE0; break;
        case 4: goto L_80422AF0; break;
        default: switch_error(__func__, 0x80422A48, 0x804260B0);
    }
    // 0x80422A4C: nop

L_80422A50:
    // 0x80422A50: addiu       $at, $zero, 0x4068
    ctx->r1 = ADD32(0, 0X4068);
    // 0x80422A54: beq         $v0, $at, L_80422AA0
    if (ctx->r2 == ctx->r1) {
        // 0x80422A58: nop
    
            goto L_80422AA0;
    }
    // 0x80422A58: nop

    // 0x80422A5C: b           L_80422AFC
    // 0x80422A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422A64:
    // 0x80422A64: addiu       $at, $zero, 0x4066
    ctx->r1 = ADD32(0, 0X4066);
    // 0x80422A68: beq         $v0, $at, L_80422A80
    if (ctx->r2 == ctx->r1) {
        // 0x80422A6C: addiu       $at, $zero, 0x4067
        ctx->r1 = ADD32(0, 0X4067);
            goto L_80422A80;
    }
    // 0x80422A6C: addiu       $at, $zero, 0x4067
    ctx->r1 = ADD32(0, 0X4067);
    // 0x80422A70: beq         $v0, $at, L_80422A90
    if (ctx->r2 == ctx->r1) {
        // 0x80422A74: nop
    
            goto L_80422A90;
    }
    // 0x80422A74: nop

    // 0x80422A78: b           L_80422AFC
    // 0x80422A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422A80:
    // 0x80422A80: jal         0x804255F0
    // 0x80422A84: nop

    func_804255F0(rdram, ctx);
        goto after_0;
    // 0x80422A84: nop

    after_0:
    // 0x80422A88: b           L_80422AFC
    // 0x80422A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422A90:
    // 0x80422A90: jal         0x80425638
    // 0x80422A94: nop

    func_80425638(rdram, ctx);
        goto after_1;
    // 0x80422A94: nop

    after_1:
    // 0x80422A98: b           L_80422AFC
    // 0x80422A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AA0:
    // 0x80422AA0: jal         0x80422E24
    // 0x80422AA4: nop

    func_80422E24(rdram, ctx);
        goto after_2;
    // 0x80422AA4: nop

    after_2:
    // 0x80422AA8: b           L_80422AFC
    // 0x80422AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AB0:
    // 0x80422AB0: jal         0x80423C54
    // 0x80422AB4: nop

    func_80423C54(rdram, ctx);
        goto after_3;
    // 0x80422AB4: nop

    after_3:
    // 0x80422AB8: b           L_80422AFC
    // 0x80422ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422ABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AC0:
    // 0x80422AC0: jal         0x804243EC
    // 0x80422AC4: nop

    func_804243EC(rdram, ctx);
        goto after_4;
    // 0x80422AC4: nop

    after_4:
    // 0x80422AC8: b           L_80422AFC
    // 0x80422ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422ACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AD0:
    // 0x80422AD0: jal         0x80424CA4
    // 0x80422AD4: nop

    func_80424CA4(rdram, ctx);
        goto after_5;
    // 0x80422AD4: nop

    after_5:
    // 0x80422AD8: b           L_80422AFC
    // 0x80422ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AE0:
    // 0x80422AE0: jal         0x80425240
    // 0x80422AE4: nop

    func_80425240(rdram, ctx);
        goto after_6;
    // 0x80422AE4: nop

    after_6:
    // 0x80422AE8: b           L_80422AFC
    // 0x80422AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80422AFC;
    // 0x80422AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AF0:
    // 0x80422AF0: jal         0x80425324
    // 0x80422AF4: nop

    func_80425324(rdram, ctx);
        goto after_7;
    // 0x80422AF4: nop

    after_7:
L_80422AF8:
    // 0x80422AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422AFC:
    // 0x80422AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80422B00: jr          $ra
    // 0x80422B04: nop

    return;
    // 0x80422B04: nop

;}
RECOMP_FUNC void func_804E7920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E7920: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x804E7924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E7928: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x804E792C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x804E7930: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x804E7934: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x804E7938: jal         0x8006C67C
    // 0x804E793C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    func_8006C67C(rdram, ctx);
        goto after_0;
    // 0x804E793C: addiu       $a3, $sp, 0x5C
    ctx->r7 = ADD32(ctx->r29, 0X5C);
    after_0:
    // 0x804E7940: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x804E7944: jal         0x80047AB8
    // 0x804E7948: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x804E7948: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x804E794C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x804E7950: jal         0x80058CC0
    // 0x804E7954: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80058CC0(rdram, ctx);
        goto after_2;
    // 0x804E7954: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x804E7958: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804E795C: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804E7960: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x804E7964: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x804E7968: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804E796C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804E7970: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804E7974: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x804E7978: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x804E797C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804E7980: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x804E7984: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    // 0x804E7988: jal         0x80081E8C
    // 0x804E798C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    fatan2(rdram, ctx);
        goto after_3;
    // 0x804E798C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x804E7990: lui         $at, 0x804E
    ctx->r1 = S32(RELOC_HI16(261, 0X6F0) << 16);
    // 0x804E7994: lwc1        $f6, 0x7F50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(261, 0X6F0));
    // 0x804E7998: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x804E799C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804E79A0: swc1        $f8, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f8.u32l;
    // 0x804E79A4: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x804E79A8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x804E79AC: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x804E79B0: jal         0x80081E8C
    // 0x804E79B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    fatan2(rdram, ctx);
        goto after_4;
    // 0x804E79B4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_4:
    // 0x804E79B8: lui         $at, 0x804E
    ctx->r1 = S32(RELOC_HI16(261, 0X6F4) << 16);
    // 0x804E79BC: lwc1        $f10, 0x7F54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(261, 0X6F4));
    // 0x804E79C0: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x804E79C4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804E79C8: swc1        $f16, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->f16.u32l;
    // 0x804E79CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E79D0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x804E79D4: jr          $ra
    // 0x804E79D8: nop

    return;
    // 0x804E79D8: nop

;}
RECOMP_FUNC void func_8004D1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D1F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004D1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D1F8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8004D1FC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004D200: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004D204: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8004D208: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8004D20C: jal         0x80047AB8
    // 0x8004D210: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8004D210: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8004D214: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8004D218: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004D21C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D220: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8004D224: jalr        $t9
    // 0x8004D228: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8004D228: addiu       $a3, $sp, 0x1C
    ctx->r7 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8004D22C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004D234: jr          $ra
    // 0x8004D238: nop

    return;
    // 0x8004D238: nop

;}
RECOMP_FUNC void func_805CA5D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA5D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CA5D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CA5DC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CA5E0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x805CA5E4: jal         0x80065728
    // 0x805CA5E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x805CA5E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x805CA5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CA5F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CA5F4: jr          $ra
    // 0x805CA5F8: nop

    return;
    // 0x805CA5F8: nop

;}
RECOMP_FUNC void func_80008AE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008AE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80008AEC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80008AF0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80008AF4: jr          $ra
    // 0x80008AF8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x80008AF8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_804222BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804222BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804222C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804222C4: jal         0x80422294
    // 0x804222C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80422294(rdram, ctx);
        goto after_0;
    // 0x804222C8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804222CC: jal         0x80045BD8
    // 0x804222D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x804222D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804222D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804222D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804222DC: jr          $ra
    // 0x804222E0: nop

    return;
    // 0x804222E0: nop

;}
RECOMP_FUNC void func_80000BC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000BC0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80000BC4: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80000BC8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80000BCC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80000BD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80000BD4: lui         $t6, 0xA00
    ctx->r14 = S32(0XA00 << 16);
    // 0x80000BD8: lui         $t7, 0x3E0
    ctx->r15 = S32(0X3E0 << 16);
    // 0x80000BDC: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x80000BE0: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80000BE4: ori         $t7, $t7, 0x1A0
    ctx->r15 = ctx->r15 | 0X1A0;
    // 0x80000BE8: ori         $t6, $t6, 0xC80
    ctx->r14 = ctx->r14 | 0XC80;
    // 0x80000BEC: addiu       $t9, $t9, 0x4D10
    ctx->r25 = ADD32(ctx->r25, 0X4D10);
    // 0x80000BF0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80000BF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80000BF8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80000BFC: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80000C00: lhu         $t3, 0x28($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X28);
    // 0x80000C04: lui         $t1, 0xC1A
    ctx->r9 = S32(0XC1A << 16);
    // 0x80000C08: addiu       $a2, $a0, 0x8
    ctx->r6 = ADD32(ctx->r4, 0X8);
    // 0x80000C0C: lui         $t5, 0xE20
    ctx->r13 = S32(0XE20 << 16);
    // 0x80000C10: ori         $t5, $t5, 0xC80
    ctx->r13 = ctx->r13 | 0XC80;
    // 0x80000C14: or          $t4, $t3, $t1
    ctx->r12 = ctx->r11 | ctx->r9;
    // 0x80000C18: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80000C1C: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x80000C20: lhu         $t7, 0x2A($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X2A);
    // 0x80000C24: addiu       $t0, $a2, 0x8
    ctx->r8 = ADD32(ctx->r6, 0X8);
    // 0x80000C28: lui         $t9, 0x3E0
    ctx->r25 = S32(0X3E0 << 16);
    // 0x80000C2C: ori         $t9, $t9, 0xE20
    ctx->r25 = ctx->r25 | 0XE20;
    // 0x80000C30: or          $t8, $t7, $t1
    ctx->r24 = ctx->r15 | ctx->r9;
    // 0x80000C34: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80000C38: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80000C3C: jr          $ra
    // 0x80000C40: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    return;
    // 0x80000C40: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
;}
RECOMP_FUNC void func_804BC490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BC490: lwc1        $f2, 0x360($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X360);
    // 0x804BC494: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x804BC498: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BC49C: mul.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804BC4A0: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X4164) << 16);
    // 0x804BC4A4: lwc1        $f6, -0x56C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X4164));
    // 0x804BC4A8: sub.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x804BC4AC: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x804BC4B0: nop

    // 0x804BC4B4: bc1fl       L_804BC4CC
    if (!c1cs) {
        // 0x804BC4B8: sqrt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
            goto L_804BC4CC;
    }
    goto skip_0;
    // 0x804BC4B8: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
    skip_0:
    // 0x804BC4BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804BC4C0: b           L_804BC4D8
    // 0x804BC4C4: swc1        $f18, 0x2A0($a0)
    MEM_W(0X2A0, ctx->r4) = ctx->f18.u32l;
        goto L_804BC4D8;
    // 0x804BC4C4: swc1        $f18, 0x2A0($a0)
    MEM_W(0X2A0, ctx->r4) = ctx->f18.u32l;
    // 0x804BC4C8: sqrt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = sqrtf(ctx->f12.fl);
L_804BC4CC:
    // 0x804BC4CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804BC4D0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x804BC4D4: swc1        $f8, 0x2A0($a0)
    MEM_W(0X2A0, ctx->r4) = ctx->f8.u32l;
L_804BC4D8:
    // 0x804BC4D8: lwc1        $f2, 0x360($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X360);
    // 0x804BC4DC: lwc1        $f12, 0x2A0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2A0);
    // 0x804BC4E0: swc1        $f18, 0x2AC($a0)
    MEM_W(0X2AC, ctx->r4) = ctx->f18.u32l;
    // 0x804BC4E4: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x804BC4E8: swc1        $f2, 0x2A4($a0)
    MEM_W(0X2A4, ctx->r4) = ctx->f2.u32l;
    // 0x804BC4EC: sub.s       $f14, $f18, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x804BC4F0: swc1        $f0, 0x2B0($a0)
    MEM_W(0X2B0, ctx->r4) = ctx->f0.u32l;
    // 0x804BC4F4: add.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804BC4F8: swc1        $f14, 0x2B8($a0)
    MEM_W(0X2B8, ctx->r4) = ctx->f14.u32l;
    // 0x804BC4FC: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804BC500: swc1        $f16, 0x2BC($a0)
    MEM_W(0X2BC, ctx->r4) = ctx->f16.u32l;
    // 0x804BC504: add.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x804BC508: swc1        $f10, 0x2C4($a0)
    MEM_W(0X2C4, ctx->r4) = ctx->f10.u32l;
    // 0x804BC50C: jr          $ra
    // 0x804BC510: swc1        $f4, 0x2C8($a0)
    MEM_W(0X2C8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x804BC510: swc1        $f4, 0x2C8($a0)
    MEM_W(0X2C8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80566FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566FA8: jal         0x80566E48
    // 0x80566FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80566E48(rdram, ctx);
        goto after_0;
    // 0x80566FAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80566FB0: jal         0x80566F88
    // 0x80566FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80566F88(rdram, ctx);
        goto after_1;
    // 0x80566FB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80566FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566FBC: jal         0x805670F4
    // 0x80566FC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80566FC0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80566FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80566FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566FCC: jr          $ra
    // 0x80566FD0: nop

    return;
    // 0x80566FD0: nop

;}
RECOMP_FUNC void func_805D33AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D33AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D33B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D33B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D33B8: jal         0x805D2110
    // 0x805D33BC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_805D2110(rdram, ctx);
        goto after_0;
    // 0x805D33BC: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x805D33C0: jal         0x80045BD8
    // 0x805D33C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805D33C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805D33C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D33CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D33D0: jr          $ra
    // 0x805D33D4: nop

    return;
    // 0x805D33D4: nop

;}
RECOMP_FUNC void func_805305E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805305E8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805305EC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805305F0: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(336, 0X404) << 16);
    // 0x805305F4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x805305F8: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x805305FC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80530600: lwc1        $f22, 0x894($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(336, 0X404));
    // 0x80530604: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80530608: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8053060C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80530610: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(336, 0X408) << 16);
    // 0x80530614: lui         $s0, 0x8053
    ctx->r16 = S32(RELOC_HI16(336, 0X3D0) << 16);
    // 0x80530618: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8053061C: lui         $s4, 0x8053
    ctx->r20 = S32(RELOC_HI16(336, 0X3E8) << 16);
    // 0x80530620: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80530624: addiu       $s4, $s4, 0x878
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(336, 0X3E8));
    // 0x80530628: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x8053062C: addiu       $s0, $s0, 0x860
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(336, 0X3D0));
    // 0x80530630: lwc1        $f20, 0x898($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(336, 0X408));
    // 0x80530634: addiu       $s1, $a0, 0x84
    ctx->r17 = ADD32(ctx->r4, 0X84);
    // 0x80530638: addiu       $s2, $sp, 0x4C
    ctx->r18 = ADD32(ctx->r29, 0X4C);
L_8053063C:
    // 0x8053063C: jal         0x80065414
    // 0x80530640: nop

    func_80065414(rdram, ctx);
        goto after_0;
    // 0x80530640: nop

    after_0:
    // 0x80530644: cvt.s.d     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f4.fl = CVT_S_D(ctx->f0.d);
    // 0x80530648: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8053064C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80530650: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80530654: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80530658: jal         0x80065414
    // 0x8053065C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    func_80065414(rdram, ctx);
        goto after_1;
    // 0x8053065C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80530660: cvt.s.d     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f18.fl = CVT_S_D(ctx->f0.d);
    // 0x80530664: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80530668: lw          $t9, 0xF78($s3)
    ctx->r25 = MEM_W(ctx->r19, 0XF78);
    // 0x8053066C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80530670: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80530674: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80530678: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8053067C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80530680: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80530684: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80530688: jalr        $t9
    // 0x8053068C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8053068C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80530690: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80530694: bne         $s0, $s4, L_8053063C
    if (ctx->r16 != ctx->r20) {
        // 0x80530698: nop
    
            goto L_8053063C;
    }
    // 0x80530698: nop

    // 0x8053069C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x805306A0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805306A4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805306A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x805306AC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x805306B0: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x805306B4: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x805306B8: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x805306BC: jr          $ra
    // 0x805306C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x805306C0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_806F0348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F0348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F034C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F0350: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F0354: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F0358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F035C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F0360: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F0364: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x806F0368: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F036C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F0370: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(676, 0X4C7C) << 16);
    // 0x806F0374: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F0378: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F037C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F0380: lw          $t2, 0xBCC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(676, 0X4C7C));
    // 0x806F0384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F0388: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806F038C: jal         0x806F008C
    // 0x806F0390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F008C(rdram, ctx);
        goto after_0;
    // 0x806F0390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F0394: jal         0x806F00D8
    // 0x806F0398: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F00D8(rdram, ctx);
        goto after_1;
    // 0x806F0398: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F039C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F03A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F03A4: jr          $ra
    // 0x806F03A8: nop

    return;
    // 0x806F03A8: nop

    // 0x806F03AC: nop

;}
RECOMP_FUNC void func_80584B1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584B1C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584B20: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584B24: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584B28: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584B2C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584B30: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584B34: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584B38: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584B3C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584B40: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584B44: jr          $ra
    // 0x80584B48: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584B48: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800679D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800679D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800679D8: jal         0x800106CC
    // 0x800679DC: nop

    func_800106CC(rdram, ctx);
        goto after_0;
    // 0x800679DC: nop

    after_0:
    // 0x800679E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800679E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800679E8: jr          $ra
    // 0x800679EC: nop

    return;
    // 0x800679EC: nop

;}
RECOMP_FUNC void func_807B634C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B634C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B6350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B6354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B6358: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B635C: lui         $a0, 0x402C
    ctx->r4 = S32(0X402C << 16);
    // 0x807B6360: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x807B6364: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B6368: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    // 0x807B636C: lui         $a1, 0x42D0
    ctx->r5 = S32(0X42D0 << 16);
    // 0x807B6370: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    // 0x807B6374: jal         0x8004613C
    // 0x807B6378: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x807B6378: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x807B637C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807B6380: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807B6384: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x807B6388: sb          $t7, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r15;
    // 0x807B638C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B6390: jal         0x80047F9C
    // 0x807B6394: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x807B6394: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    after_1:
    // 0x807B6398: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807B639C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EC0) << 16);
    // 0x807B63A0: lwc1        $f0, 0x76C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EC0));
    // 0x807B63A4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x807B63A8: swc1        $f0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f0.u32l;
    // 0x807B63AC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x807B63B0: swc1        $f0, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f0.u32l;
    // 0x807B63B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B63B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B63BC: jr          $ra
    // 0x807B63C0: nop

    return;
    // 0x807B63C0: nop

;}
RECOMP_FUNC void func_807989A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807989A4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807989A8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807989AC: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(823, 0X160) << 16);
    // 0x807989B0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807989B4: addiu       $t7, $t7, -0x7550
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(823, 0X160));
    // 0x807989B8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807989BC: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(823, 0X20) << 16);
    // 0x807989C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807989C4: addiu       $t9, $t9, -0x7690
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(823, 0X20));
    // 0x807989C8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x807989CC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807989D0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807989D4: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807989D8: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807989DC: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x807989E0: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x807989E4: lw          $t1, -0x7BC4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7BC4);
    // 0x807989E8: lui         $t2, 0x807A
    ctx->r10 = S32(RELOC_HI16(823, 0X168) << 16);
    // 0x807989EC: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807989F0: lw          $v1, 0x10C($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X10C);
    // 0x807989F4: lui         $t3, 0x807A
    ctx->r11 = S32(RELOC_HI16(823, 0X16C) << 16);
    // 0x807989F8: lui         $t4, 0x807A
    ctx->r12 = S32(RELOC_HI16(823, 0X170) << 16);
    // 0x807989FC: srl         $v1, $v1, 30
    ctx->r3 = S32(U32(ctx->r3) >> 30);
    // 0x80798A00: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80798A04: lbu         $t2, -0x7548($t2)
    ctx->r10 = MEM_BU(ctx->r10, (int16_t)RELOC_LO16(823, 0X168));
    // 0x80798A08: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80798A0C: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80798A10: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x80798A14: lbu         $t3, -0x7544($t3)
    ctx->r11 = MEM_BU(ctx->r11, (int16_t)RELOC_LO16(823, 0X16C));
    // 0x80798A18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80798A1C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x80798A20: sb          $t3, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r11;
    // 0x80798A24: lbu         $t4, -0x7540($t4)
    ctx->r12 = MEM_BU(ctx->r12, (int16_t)RELOC_LO16(823, 0X170));
    // 0x80798A28: sb          $t4, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r12;
    // 0x80798A2C: jr          $ra
    // 0x80798A30: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
    return;
    // 0x80798A30: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
;}
RECOMP_FUNC void func_8040ACB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040ACB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040ACB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040ACB8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040ACBC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040ACC0: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8040ACC4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040ACC8: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x8040ACCC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8040ACD0: nop

    // 0x8040ACD4: bc1fl       L_8040AD00
    if (!c1cs) {
        // 0x8040ACD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040AD00;
    }
    goto skip_0;
    // 0x8040ACD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040ACDC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040ACE0: jal         0x8004D1F0
    // 0x8040ACE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8040ACE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040ACE8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040ACEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040ACF0: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x8040ACF4: jal         0x8004D698
    // 0x8040ACF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8040ACF8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8040ACFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040AD00:
    // 0x8040AD00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040AD04: jr          $ra
    // 0x8040AD08: nop

    return;
    // 0x8040AD08: nop

;}
RECOMP_FUNC void func_806DF8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF8AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF8B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF8B4: jal         0x8004700C
    // 0x806DF8B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806DF8B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DF8BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DF8C0: beq         $v0, $zero, L_806DF9B8
    if (ctx->r2 == 0) {
        // 0x806DF8C4: lw          $v1, 0x1F4($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X1F4);
            goto L_806DF9B8;
    }
    // 0x806DF8C4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF8C8: lw          $a1, 0x1E0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1E0);
    // 0x806DF8CC: slti        $at, $a1, 0xB
    ctx->r1 = SIGNED(ctx->r5) < 0XB ? 1 : 0;
    // 0x806DF8D0: bne         $at, $zero, L_806DF8EC
    if (ctx->r1 != 0) {
        // 0x806DF8D4: lui         $at, 0x806E
        ctx->r1 = S32(RELOC_HI16(643, 0X1178) << 16);
            goto L_806DF8EC;
    }
    // 0x806DF8D4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1178) << 16);
    // 0x806DF8D8: lwc1        $f6, 0x5A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1178));
    // 0x806DF8DC: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x806DF8E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806DF8E4: b           L_806DF914
    // 0x806DF8E8: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
        goto L_806DF914;
    // 0x806DF8E8: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
L_806DF8EC:
    // 0x806DF8EC: blez        $a1, L_806DF908
    if (SIGNED(ctx->r5) <= 0) {
        // 0x806DF8F0: lui         $at, 0x806E
        ctx->r1 = S32(RELOC_HI16(643, 0X117C) << 16);
            goto L_806DF908;
    }
    // 0x806DF8F0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X117C) << 16);
    // 0x806DF8F4: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x806DF8F8: lwc1        $f16, 0x5AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X117C));
    // 0x806DF8FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806DF900: b           L_806DF914
    // 0x806DF904: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
        goto L_806DF914;
    // 0x806DF904: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
L_806DF908:
    // 0x806DF908: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806DF90C: nop

    // 0x806DF910: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
L_806DF914:
    // 0x806DF914: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x806DF918: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806DF91C: bnel        $a0, $t6, L_806DF934
    if (ctx->r4 != ctx->r14) {
        // 0x806DF920: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_806DF934;
    }
    goto skip_0;
    // 0x806DF920: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x806DF924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806DF928: b           L_806DF93C
    // 0x806DF92C: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
        goto L_806DF93C;
    // 0x806DF92C: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
    // 0x806DF930: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_806DF934:
    // 0x806DF934: nop

    // 0x806DF938: swc1        $f8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f8.u32l;
L_806DF93C:
    // 0x806DF93C: lw          $t7, 0x12C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X12C);
    // 0x806DF940: bnel        $t7, $zero, L_806DF988
    if (ctx->r15 != 0) {
        // 0x806DF944: lwc1        $f16, 0x40($a0)
        ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
            goto L_806DF988;
    }
    goto skip_1;
    // 0x806DF944: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    skip_1:
    // 0x806DF948: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806DF94C: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806DF950: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x806DF954: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1180) << 16);
    // 0x806DF958: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806DF95C: lwc1        $f8, 0x5B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1180));
    // 0x806DF960: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x806DF964: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806DF968: nop

    // 0x806DF96C: bc1fl       L_806DF9BC
    if (!c1cs) {
        // 0x806DF970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF9BC;
    }
    goto skip_2;
    // 0x806DF970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806DF974: jal         0x806DF624
    // 0x806DF978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_806DF624(rdram, ctx);
        goto after_1;
    // 0x806DF978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806DF97C: b           L_806DF9BC
    // 0x806DF980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806DF9BC;
    // 0x806DF980: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF984: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
L_806DF988:
    // 0x806DF988: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806DF98C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x806DF990: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1184) << 16);
    // 0x806DF994: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806DF998: lwc1        $f10, 0x5B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1184));
    // 0x806DF99C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806DF9A0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x806DF9A4: nop

    // 0x806DF9A8: bc1fl       L_806DF9BC
    if (!c1cs) {
        // 0x806DF9AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF9BC;
    }
    goto skip_3;
    // 0x806DF9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x806DF9B0: jal         0x806DF624
    // 0x806DF9B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_806DF624(rdram, ctx);
        goto after_2;
    // 0x806DF9B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
L_806DF9B8:
    // 0x806DF9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DF9BC:
    // 0x806DF9BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF9C0: jr          $ra
    // 0x806DF9C4: nop

    return;
    // 0x806DF9C4: nop

;}
RECOMP_FUNC void func_806A9DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A9DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A9DEC: jal         0x806A98AC
    // 0x806A9DF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806A9DF0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806A9DF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806A9DF8: bne         $v0, $at, L_806A9E10
    if (ctx->r2 != ctx->r1) {
        // 0x806A9DFC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806A9E10;
    }
    // 0x806A9DFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A9E00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9E04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806A9E08: jal         0x806AA784
    // 0x806A9E0C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806A9E0C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
L_806A9E10:
    // 0x806A9E10: jal         0x806A9CD8
    // 0x806A9E14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806A9CD8(rdram, ctx);
        goto after_2;
    // 0x806A9E14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806A9E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A9E1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A9E20: jr          $ra
    // 0x806A9E24: nop

    return;
    // 0x806A9E24: nop

;}
RECOMP_FUNC void func_804335D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804335D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804335D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804335D8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804335DC: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(65, 0X928) << 16);
    // 0x804335E0: sw          $zero, 0x124($a0)
    MEM_W(0X124, ctx->r4) = 0;
    // 0x804335E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804335E8: addiu       $t6, $t6, 0x3708
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(65, 0X928));
    // 0x804335EC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804335F0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804335F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804335F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804335FC: jal         0x80433634
    // 0x80433600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80433634(rdram, ctx);
        goto after_0;
    // 0x80433600: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80433604: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80433608: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8043360C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80433610: lui         $t9, 0x8043
    ctx->r25 = S32(RELOC_HI16(65, 0X630) << 16);
    // 0x80433614: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80433618: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x8043361C: addiu       $t9, $t9, 0x3410
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(65, 0X630));
    // 0x80433620: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80433624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043362C: jr          $ra
    // 0x80433630: nop

    return;
    // 0x80433630: nop

;}
RECOMP_FUNC void func_8052E690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E690: jr          $ra
    // 0x8052E694: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8052E694: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806F6E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6E20: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806F6E24: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x806F6E28: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806F6E2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F6E30: nop

    // 0x806F6E34: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806F6E38: nop

    // 0x806F6E3C: bc1fl       L_806F6E6C
    if (!c1cs) {
        // 0x806F6E40: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806F6E6C;
    }
    goto skip_0;
    // 0x806F6E40: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806F6E44: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806F6E48: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806F6E4C: nop

    // 0x806F6E50: bc1f        L_806F6E88
    if (!c1cs) {
        // 0x806F6E54: nop
    
            goto L_806F6E88;
    }
    // 0x806F6E54: nop

    // 0x806F6E58: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806F6E5C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806F6E60: jr          $ra
    // 0x806F6E64: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806F6E64: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x806F6E68: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_806F6E6C:
    // 0x806F6E6C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806F6E70: nop

    // 0x806F6E74: bc1f        L_806F6E88
    if (!c1cs) {
        // 0x806F6E78: nop
    
            goto L_806F6E88;
    }
    // 0x806F6E78: nop

    // 0x806F6E7C: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806F6E80: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x806F6E84: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_806F6E88:
    // 0x806F6E88: jr          $ra
    // 0x806F6E8C: nop

    return;
    // 0x806F6E8C: nop

;}
RECOMP_FUNC void func_800471A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800471A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800471A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800471A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800471AC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800471B0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800471B4: addiu       $a3, $a3, 0x7128
    ctx->r7 = ADD32(ctx->r7, 0X7128);
    // 0x800471B8: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x800471BC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800471C0: jal         0x80057F74
    // 0x800471C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x800471C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800471C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800471CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800471D0: jr          $ra
    // 0x800471D4: nop

    return;
    // 0x800471D4: nop

;}
RECOMP_FUNC void func_8044A944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A944: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044A948: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13474) << 16);
    // 0x8044A94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A950: addiu       $t6, $t6, 0x7854
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13474));
    // 0x8044A954: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044A958: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044A95C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044A960: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044A964: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044A968: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A96C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044A970: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044A974: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044A978: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044A97C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044A980: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044A984: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A988: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044A98C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044A990: jal         0x80050A50
    // 0x8044A994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044A994: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044A998: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044A99C: jalr        $v0
    // 0x8044A9A0: sw          $v0, 0x6A58($v1)
    MEM_W(0X6A58, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044A9A0: sw          $v0, 0x6A58($v1)
    MEM_W(0X6A58, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044A9A4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A9A8: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x8044A9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044A9B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044A9B4: jr          $ra
    // 0x8044A9B8: nop

    return;
    // 0x8044A9B8: nop

;}
RECOMP_FUNC void func_804BCE64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BCE64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BCE68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BCE6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BCE70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BCE74: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BCE78: jal         0x804BC948
    // 0x804BCE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BC948(rdram, ctx);
        goto after_0;
    // 0x804BCE7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x804BCE80: jal         0x804BC490
    // 0x804BCE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BC490(rdram, ctx);
        goto after_1;
    // 0x804BCE84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BCE88: jal         0x804BC514
    // 0x804BCE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BC514(rdram, ctx);
        goto after_2;
    // 0x804BCE8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804BCE90: jal         0x804BC86C
    // 0x804BCE94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BC86C(rdram, ctx);
        goto after_3;
    // 0x804BCE94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BCE98: jal         0x804BCA20
    // 0x804BCE9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804BCA20(rdram, ctx);
        goto after_4;
    // 0x804BCE9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x804BCEA0: lw          $t7, 0x358($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X358);
    // 0x804BCEA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804BCEA8: beq         $t7, $zero, L_804BCED8
    if (ctx->r15 == 0) {
        // 0x804BCEAC: nop
    
            goto L_804BCED8;
    }
    // 0x804BCEAC: nop

    // 0x804BCEB0: lwc1        $f4, 0x354($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X354);
    // 0x804BCEB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BCEB8: nop

    // 0x804BCEBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BCEC0: swc1        $f8, 0x354($s0)
    MEM_W(0X354, ctx->r16) = ctx->f8.u32l;
    // 0x804BCEC4: lwc1        $f10, 0x354($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X354);
    // 0x804BCEC8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804BCECC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x804BCED0: nop

    // 0x804BCED4: sw          $t9, 0x350($s0)
    MEM_W(0X350, ctx->r16) = ctx->r25;
L_804BCED8:
    // 0x804BCED8: jal         0x804BD064
    // 0x804BCEDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804BD064(rdram, ctx);
        goto after_5;
    // 0x804BCEDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x804BCEE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BCEE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BCEE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BCEEC: jr          $ra
    // 0x804BCEF0: nop

    return;
    // 0x804BCEF0: nop

;}
RECOMP_FUNC void func_80536564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536564: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536568: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053656C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536570: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536574: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536578: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053657C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536580: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536584: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536588: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053658C: jr          $ra
    // 0x80536590: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536590: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806B15A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B15A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806B15A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B15AC: jal         0x806B1578
    // 0x806B15B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806B1578(rdram, ctx);
        goto after_0;
    // 0x806B15B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B15B4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806B15B8: lw          $t7, 0x174($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X174);
    // 0x806B15BC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806B15C0: sw          $zero, 0x44($t8)
    MEM_W(0X44, ctx->r24) = 0;
    // 0x806B15C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806B15C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806B15CC: jr          $ra
    // 0x806B15D0: nop

    return;
    // 0x806B15D0: nop

;}
RECOMP_FUNC void func_8043B31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B31C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043B320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8043B324: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8043B328: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043B32C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043B330: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(83, 0X1160) << 16);
    // 0x8043B334: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043B338: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043B33C: addiu       $t7, $t7, -0x4840
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(83, 0X1160));
    // 0x8043B340: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043B344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043B348: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043B34C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8043B350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043B354: jal         0x8043B44C
    // 0x8043B358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8043B44C(rdram, ctx);
        goto after_0;
    // 0x8043B358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8043B35C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8043B360: jal         0x8043B17C
    // 0x8043B364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043B17C(rdram, ctx);
        goto after_1;
    // 0x8043B364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8043B368: bne         $v0, $zero, L_8043B380
    if (ctx->r2 != 0) {
        // 0x8043B36C: nop
    
            goto L_8043B380;
    }
    // 0x8043B36C: nop

    // 0x8043B370: jal         0x800445A4
    // 0x8043B374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8043B374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043B378: b           L_8043B43C
    // 0x8043B37C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8043B43C;
    // 0x8043B37C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8043B380:
    // 0x8043B380: jal         0x8043B304
    // 0x8043B384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043B304(rdram, ctx);
        goto after_3;
    // 0x8043B384: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043B388: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x8043B38C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043B390: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043B394: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043B398: lui         $at, 0xC286
    ctx->r1 = S32(0XC286 << 16);
    // 0x8043B39C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043B3A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043B3A4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8043B3A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043B3AC: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8043B3B0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043B3B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8043B3B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043B3BC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8043B3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043B3C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8043B3C8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8043B3CC: jal         0x8043B22C
    // 0x8043B3D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8043B22C(rdram, ctx);
        goto after_4;
    // 0x8043B3D0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8043B3D4: lui         $at, 0x4323
    ctx->r1 = S32(0X4323 << 16);
    // 0x8043B3D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8043B3DC: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043B3E0: lui         $at, 0xC238
    ctx->r1 = S32(0XC238 << 16);
    // 0x8043B3E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043B3E8: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8043B3EC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8043B3F0: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8043B3F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8043B3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043B3FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8043B400: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8043B404: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8043B408: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8043B40C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8043B410: jal         0x8043B22C
    // 0x8043B414: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8043B22C(rdram, ctx);
        goto after_5;
    // 0x8043B414: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8043B418: lui         $t1, 0x8044
    ctx->r9 = S32(RELOC_HI16(83, 0X79C) << 16);
    // 0x8043B41C: addiu       $t1, $t1, -0x5204
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(83, 0X79C));
    // 0x8043B420: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8043B424: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x8043B428: sh          $t2, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r10;
    // 0x8043B42C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8043B430: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043B434: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8043B438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8043B43C:
    // 0x8043B43C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8043B440: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043B444: jr          $ra
    // 0x8043B448: nop

    return;
    // 0x8043B448: nop

;}
RECOMP_FUNC void func_8003CF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF70: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003CF74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CF78: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003CF7C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003CF80: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8003CF84: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8003CF88: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8003CF8C: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8003CF90: sltu        $t7, $zero, $t6
    ctx->r15 = 0 < ctx->r14 ? 1 : 0;
    // 0x8003CF94: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003CF98: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8003CF9C: lwc1        $f4, -0x10A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X10A8);
    // 0x8003CFA0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003CFA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CFA8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003CFAC: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8003CFB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CFB4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003CFB8: mul.s       $f20, $f8, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003CFBC: jal         0x80066DE4
    // 0x8003CFC0: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8003CFC0: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8003CFC4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8003CFC8: jal         0x80066E88
    // 0x8003CFCC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8003CFCC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    after_1:
    // 0x8003CFD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CFD4: jal         0x8003CDF0
    // 0x8003CFD8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    func_8003CDF0(rdram, ctx);
        goto after_2;
    // 0x8003CFD8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8003CFDC: sb          $v0, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r2;
    // 0x8003CFE0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8003CFE4: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8003CFE8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003CFEC: jal         0x8003CC14
    // 0x8003CFF0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    func_8003CC14(rdram, ctx);
        goto after_3;
    // 0x8003CFF0: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x8003CFF4: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x8003CFF8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003CFFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003D000: beq         $t9, $zero, L_8003D018
    if (ctx->r25 == 0) {
        // 0x8003D004: lwc1        $f2, 0x38($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8003D018;
    }
    // 0x8003D004: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003D008: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003D00C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8003D010: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8003D014: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
L_8003D018:
    // 0x8003D018: mul.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8003D01C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003D020: lwc1        $f0, 0x3C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8003D024: lwc1        $f12, 0x40($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8003D028: mul.s       $f6, $f20, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8003D02C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003D030: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8003D034: swc1        $f16, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f16.u32l;
    // 0x8003D038: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003D03C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8003D040: lwc1        $f10, 0x3C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8003D044: mul.s       $f14, $f20, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x8003D048: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8003D04C: swc1        $f16, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f16.u32l;
    // 0x8003D050: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x8003D054: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003D058: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x8003D05C: swc1        $f8, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f8.u32l;
    // 0x8003D060: lwc1        $f18, 0x40($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8003D064: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003D068: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x8003D06C: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
    // 0x8003D070: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8003D074: swc1        $f14, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f14.u32l;
    // 0x8003D078: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D07C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003D080: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003D084: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003D088: jr          $ra
    // 0x8003D08C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003D08C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_805CAC04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CAC04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CAC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CAC0C: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805CAC10: lw          $v0, 0x138($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X138);
    // 0x805CAC14: sw          $v0, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r2;
    // 0x805CAC18: sw          $v0, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r2;
    // 0x805CAC1C: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
    // 0x805CAC20: jal         0x805CA904
    // 0x805CAC24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805CA904(rdram, ctx);
        goto after_0;
    // 0x805CAC24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CAC28: jal         0x805CA9FC
    // 0x805CAC2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805CA9FC(rdram, ctx);
        goto after_1;
    // 0x805CAC2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805CAC30: beq         $v0, $zero, L_805CAC44
    if (ctx->r2 == 0) {
        // 0x805CAC34: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805CAC44;
    }
    // 0x805CAC34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CAC38: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x805CAC3C: lbu         $t8, 0x165($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X165);
    // 0x805CAC40: sb          $t8, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r24;
L_805CAC44:
    // 0x805CAC44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CAC48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CAC4C: jr          $ra
    // 0x805CAC50: nop

    return;
    // 0x805CAC50: nop

;}
RECOMP_FUNC void func_80039B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039B24: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039B28: addiu       $a0, $a0, 0x4280
    ctx->r4 = ADD32(ctx->r4, 0X4280);
    // 0x80039B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039B30: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039B34: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039B38: sw          $a0, 0x4268($at)
    MEM_W(0X4268, ctx->r1) = ctx->r4;
    // 0x80039B3C: addiu       $a1, $a1, 0x4290
    ctx->r5 = ADD32(ctx->r5, 0X4290);
    // 0x80039B40: jal         0x8004667C
    // 0x80039B44: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039B44: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x80039B48: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039B4C: addiu       $a0, $a0, 0x4290
    ctx->r4 = ADD32(ctx->r4, 0X4290);
    // 0x80039B50: jal         0x80039ABC
    // 0x80039B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039B54: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x80039B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039B5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039B60: jr          $ra
    // 0x80039B64: nop

    return;
    // 0x80039B64: nop

;}
RECOMP_FUNC void func_8070D0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070D0DC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070D0E0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8070D0E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8070D0E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8070D0EC: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8070D0F0: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8070D0F4: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8070D0F8: jr          $ra
    // 0x8070D0FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8070D0FC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_8073B2D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B2D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073B2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073B2E0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073B2E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8073B2E8: lw          $v1, 0x38($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X38);
    // 0x8073B2EC: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8073B2F0: lwc1        $f0, 0x78($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X78);
    // 0x8073B2F4: addiu       $a1, $t6, 0x1
    ctx->r5 = ADD32(ctx->r14, 0X1);
    // 0x8073B2F8: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8073B2FC: lwc1        $f2, 0x7C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x8073B300: beq         $at, $zero, L_8073B328
    if (ctx->r1 == 0) {
        // 0x8073B304: sw          $a1, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r5;
            goto L_8073B328;
    }
    // 0x8073B304: sw          $a1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r5;
    // 0x8073B308: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X249C) << 16);
    // 0x8073B30C: lwc1        $f14, -0x4134($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X249C));
    // 0x8073B310: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8073B314: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x8073B318: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
    // 0x8073B31C: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x8073B320: b           L_8073B420
    // 0x8073B324: swc1        $f2, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f2.u32l;
        goto L_8073B420;
    // 0x8073B324: swc1        $f2, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f2.u32l;
L_8073B328:
    // 0x8073B328: slti        $at, $a1, 0x7
    ctx->r1 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8073B32C: beq         $at, $zero, L_8073B384
    if (ctx->r1 == 0) {
        // 0x8073B330: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_8073B384;
    }
    // 0x8073B330: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8073B334: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X24A0) << 16);
    // 0x8073B338: lwc1        $f12, -0x4130($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X24A0));
    // 0x8073B33C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X24A4) << 16);
    // 0x8073B340: lwc1        $f14, -0x412C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X24A4));
    // 0x8073B344: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8073B348: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8073B34C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8073B350: nop

    // 0x8073B354: bc1fl       L_8073B364
    if (!c1cs) {
        // 0x8073B358: c.le.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
            goto L_8073B364;
    }
    goto skip_0;
    // 0x8073B358: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    skip_0:
    // 0x8073B35C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8073B360: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
L_8073B364:
    // 0x8073B364: nop

    // 0x8073B368: bc1fl       L_8073B378
    if (!c1cs) {
        // 0x8073B36C: swc1        $f0, 0x6C($v1)
        MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
            goto L_8073B378;
    }
    goto skip_1;
    // 0x8073B36C: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
    skip_1:
    // 0x8073B370: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8073B374: swc1        $f0, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f0.u32l;
L_8073B378:
    // 0x8073B378: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x8073B37C: b           L_8073B420
    // 0x8073B380: swc1        $f2, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f2.u32l;
        goto L_8073B420;
    // 0x8073B380: swc1        $f2, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f2.u32l;
L_8073B384:
    // 0x8073B384: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8073B388: lwc1        $f4, 0x28($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8073B38C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8073B390: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8073B394: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8073B398: lui         $t0, 0x8074
    ctx->r8 = S32(RELOC_HI16(739, 0X2250) << 16);
    // 0x8073B39C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8073B3A0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8073B3A4: nop

    // 0x8073B3A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8073B3AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8073B3B0: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8073B3B4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8073B3B8: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8073B3BC: beq         $v1, $zero, L_8073B408
    if (ctx->r3 == 0) {
        // 0x8073B3C0: addu        $a0, $t1, $t4
        ctx->r4 = ADD32(ctx->r9, ctx->r12);
            goto L_8073B408;
    }
    // 0x8073B3C0: addu        $a0, $t1, $t4
    ctx->r4 = ADD32(ctx->r9, ctx->r12);
    // 0x8073B3C4: beq         $v1, $at, L_8073B3E0
    if (ctx->r3 == ctx->r1) {
        // 0x8073B3C8: sll         $t5, $a0, 1
        ctx->r13 = S32(ctx->r4 << 1);
            goto L_8073B3E0;
    }
    // 0x8073B3C8: sll         $t5, $a0, 1
    ctx->r13 = S32(ctx->r4 << 1);
    // 0x8073B3CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8073B3D0: beq         $v1, $at, L_8073B3F4
    if (ctx->r3 == ctx->r1) {
        // 0x8073B3D4: sll         $t7, $a0, 1
        ctx->r15 = S32(ctx->r4 << 1);
            goto L_8073B3F4;
    }
    // 0x8073B3D4: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x8073B3D8: b           L_8073B418
    // 0x8073B3DC: nop

        goto L_8073B418;
    // 0x8073B3DC: nop

L_8073B3E0:
    // 0x8073B3E0: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(739, 0X2148) << 16);
    // 0x8073B3E4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8073B3E8: lhu         $t6, -0x4488($t6)
    ctx->r14 = MEM_HU(ctx->r14, (int16_t)RELOC_LO16(739, 0X2148));
    // 0x8073B3EC: b           L_8073B418
    // 0x8073B3F0: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
        goto L_8073B418;
    // 0x8073B3F0: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
L_8073B3F4:
    // 0x8073B3F4: lui         $t8, 0x8074
    ctx->r24 = S32(RELOC_HI16(739, 0X21CC) << 16);
    // 0x8073B3F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8073B3FC: lhu         $t8, -0x4404($t8)
    ctx->r24 = MEM_HU(ctx->r24, (int16_t)RELOC_LO16(739, 0X21CC));
    // 0x8073B400: b           L_8073B418
    // 0x8073B404: sh          $t8, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r24;
        goto L_8073B418;
    // 0x8073B404: sh          $t8, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r24;
L_8073B408:
    // 0x8073B408: sll         $t9, $a0, 1
    ctx->r25 = S32(ctx->r4 << 1);
    // 0x8073B40C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8073B410: lhu         $t0, -0x4380($t0)
    ctx->r8 = MEM_HU(ctx->r8, (int16_t)RELOC_LO16(739, 0X2250));
    // 0x8073B414: sh          $t0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r8;
L_8073B418:
    // 0x8073B418: jal         0x8073B8CC
    // 0x8073B41C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8073B8CC(rdram, ctx);
        goto after_0;
    // 0x8073B41C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_8073B420:
    // 0x8073B420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073B424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073B428: jr          $ra
    // 0x8073B42C: nop

    return;
    // 0x8073B42C: nop

;}
RECOMP_FUNC void func_8001FB1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FB1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001FB20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FB24: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x8001FB28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FB2C: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB30: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8001FB64;
    }
    // 0x8001FB30: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8001FB34: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB38: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8001FB64;
    }
    // 0x8001FB38: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001FB3C: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB40: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8001FB64;
    }
    // 0x8001FB40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8001FB44: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FB64;
    }
    // 0x8001FB48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FB4C: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB50: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001FB64;
    }
    // 0x8001FB50: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FB54: beq         $v0, $at, L_8001FB64
    if (ctx->r2 == ctx->r1) {
        // 0x8001FB58: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001FB64;
    }
    // 0x8001FB58: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001FB5C: bnel        $v0, $at, L_8001FBD8
    if (ctx->r2 != ctx->r1) {
        // 0x8001FB60: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FBD8;
    }
    goto skip_0;
    // 0x8001FB60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
L_8001FB64:
    // 0x8001FB64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001FB68: lbu         $t6, 0xF4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF4);
    // 0x8001FB6C: beql        $t6, $zero, L_8001FBBC
    if (ctx->r14 == 0) {
        // 0x8001FB70: lbu         $t1, 0x111($v0)
        ctx->r9 = MEM_BU(ctx->r2, 0X111);
            goto L_8001FBBC;
    }
    goto skip_1;
    // 0x8001FB70: lbu         $t1, 0x111($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X111);
    skip_1:
    // 0x8001FB74: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8001FB78: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8001FB7C: beq         $v0, $zero, L_8001FB9C
    if (ctx->r2 == 0) {
        // 0x8001FB80: nop
    
            goto L_8001FB9C;
    }
    // 0x8001FB80: nop

    // 0x8001FB84: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x8001FB88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FB8C: srl         $t9, $t8, 10
    ctx->r25 = S32(U32(ctx->r24) >> 10);
    // 0x8001FB90: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x8001FB94: beq         $t0, $at, L_8001FBA8
    if (ctx->r8 == ctx->r1) {
        // 0x8001FB98: nop
    
            goto L_8001FBA8;
    }
    // 0x8001FB98: nop

L_8001FB9C:
    // 0x8001FB9C: jal         0x80022594
    // 0x8001FBA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80022594(rdram, ctx);
        goto after_0;
    // 0x8001FBA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001FBA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8001FBA8:
    // 0x8001FBA8: jal         0x8002E290
    // 0x8001FBAC: nop

    func_8002E290(rdram, ctx);
        goto after_1;
    // 0x8001FBAC: nop

    after_1:
    // 0x8001FBB0: b           L_8001FBD8
    // 0x8001FBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FBD8;
    // 0x8001FBB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FBB8: lbu         $t1, 0x111($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X111);
L_8001FBBC:
    // 0x8001FBBC: beql        $t1, $zero, L_8001FBD8
    if (ctx->r9 == 0) {
        // 0x8001FBC0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8001FBD8;
    }
    goto skip_2;
    // 0x8001FBC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x8001FBC4: jal         0x8002E290
    // 0x8001FBC8: nop

    func_8002E290(rdram, ctx);
        goto after_2;
    // 0x8001FBC8: nop

    after_2:
    // 0x8001FBCC: b           L_8001FBD8
    // 0x8001FBD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001FBD8;
    // 0x8001FBD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001FBD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001FBD8:
    // 0x8001FBD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FBDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001FBE0: jr          $ra
    // 0x8001FBE4: nop

    return;
    // 0x8001FBE4: nop

;}
RECOMP_FUNC void func_804306CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804306CC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804306D0: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X1630) << 16);
    // 0x804306D4: addiu       $t6, $t6, -0x8F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X1630));
    // 0x804306D8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804306DC: jr          $ra
    // 0x804306E0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804306E0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804CBAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CBAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CBACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CBAD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804CBAD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CBAD8: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x804CBADC: addiu       $at, $zero, 0x4115
    ctx->r1 = ADD32(0, 0X4115);
    // 0x804CBAE0: bnel        $t7, $at, L_804CBB44
    if (ctx->r15 != ctx->r1) {
        // 0x804CBAE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CBB44;
    }
    goto skip_0;
    // 0x804CBAE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804CBAE8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804CBAEC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CBAF0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804CBAF4: nop

    // 0x804CBAF8: bc1fl       L_804CBB44
    if (!c1cs) {
        // 0x804CBAFC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CBB44;
    }
    goto skip_1;
    // 0x804CBAFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804CBB00: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x804CBB04: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804CBB08: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x804CBB0C: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x804CBB10: beql        $v0, $zero, L_804CBB44
    if (ctx->r2 == 0) {
        // 0x804CBB14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CBB44;
    }
    goto skip_2;
    // 0x804CBB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x804CBB18: jalr        $v0
    // 0x804CBB1C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x804CBB1C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x804CBB20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804CBB24: lh          $t0, 0x184($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X184);
    // 0x804CBB28: beql        $t0, $zero, L_804CBB44
    if (ctx->r8 == 0) {
        // 0x804CBB2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804CBB44;
    }
    goto skip_3;
    // 0x804CBB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804CBB30: lw          $t1, 0x174($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X174);
    // 0x804CBB34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804CBB38: jal         0x8005FA94
    // 0x804CBB3C: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
    func_8005FA94(rdram, ctx);
        goto after_1;
    // 0x804CBB3C: sh          $zero, 0x10($t2)
    MEM_H(0X10, ctx->r10) = 0;
    after_1:
    // 0x804CBB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804CBB44:
    // 0x804CBB44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CBB48: jr          $ra
    // 0x804CBB4C: nop

    return;
    // 0x804CBB4C: nop

;}
RECOMP_FUNC void func_806A2C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A2C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A2C4C: jal         0x800447C8
    // 0x806A2C50: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806A2C50: nop

    after_0:
    // 0x806A2C54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A2C58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A2C5C: jr          $ra
    // 0x806A2C60: nop

    return;
    // 0x806A2C60: nop

;}
RECOMP_FUNC void func_8007FEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FEC8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FED0: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FED4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FED8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FEDC: jal         0x800818E8
    // 0x8007FEE0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FEE0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FEE4: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FEE8: jal         0x800804E0
    // 0x8007FEEC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800804E0(rdram, ctx);
        goto after_1;
    // 0x8007FEEC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x8007FEF0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FEF4: jal         0x800817A0
    // 0x8007FEF8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FEF8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FEFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FF00: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FF04: jr          $ra
    // 0x8007FF08: nop

    return;
    // 0x8007FF08: nop

;}
RECOMP_FUNC void func_806E7B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7B30: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806E7B34: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x806E7B38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7B3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7B40: beql        $t6, $zero, L_806E7B64
    if (ctx->r14 == 0) {
        // 0x806E7B44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7B64;
    }
    goto skip_0;
    // 0x806E7B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E7B48: lhu         $t7, 0xC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0XC);
    // 0x806E7B4C: addiu       $at, $zero, 0x466C
    ctx->r1 = ADD32(0, 0X466C);
    // 0x806E7B50: bnel        $t7, $at, L_806E7B64
    if (ctx->r15 != ctx->r1) {
        // 0x806E7B54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7B64;
    }
    goto skip_1;
    // 0x806E7B54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E7B58: jal         0x806E77D4
    // 0x806E7B5C: nop

    func_806E77D4(rdram, ctx);
        goto after_0;
    // 0x806E7B5C: nop

    after_0:
    // 0x806E7B60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E7B64:
    // 0x806E7B64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7B68: jr          $ra
    // 0x806E7B6C: nop

    return;
    // 0x806E7B6C: nop

;}
RECOMP_FUNC void func_804CEA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEA08: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804CEA0C: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x804CEA10: lwc1        $f2, 0x4($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804CEA14: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804CEA18: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x804CEA1C: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x804CEA20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804CEA24: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x804CEA28: lwc1        $f4, 0x4($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X4);
    // 0x804CEA2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804CEA30: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804CEA34: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x804CEA38: nop

    // 0x804CEA3C: bc1f        L_804CEA7C
    if (!c1cs) {
        // 0x804CEA40: nop
    
            goto L_804CEA7C;
    }
    // 0x804CEA40: nop

    // 0x804CEA44: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804CEA48: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CEA4C: mul.s       $f0, $f12, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x804CEA50: nop

    // 0x804CEA54: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804CEA58: nop

    // 0x804CEA5C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x804CEA60: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x804CEA64: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x804CEA68: nop

    // 0x804CEA6C: bc1f        L_804CEA7C
    if (!c1cs) {
        // 0x804CEA70: nop
    
            goto L_804CEA7C;
    }
    // 0x804CEA70: nop

    // 0x804CEA74: jr          $ra
    // 0x804CEA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x804CEA78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804CEA7C:
    // 0x804CEA7C: jr          $ra
    // 0x804CEA80: nop

    return;
    // 0x804CEA80: nop

;}
RECOMP_FUNC void func_805333CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805333CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805333D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805333D4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805333D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805333DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805333E0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805333E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x805333E8: jal         0x80533878
    // 0x805333EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80533878(rdram, ctx);
        goto after_0;
    // 0x805333EC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805333F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805333F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805333F8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x805333FC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80533400: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80533404: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(345, 0X1924) << 16);
    // 0x80533408: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8053340C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80533410: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80533414: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80533418: lwc1        $f18, 0x43F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(345, 0X1924));
    // 0x8053341C: lwc1        $f16, 0xC4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80533420: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80533424: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80533428: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8053342C: swc1        $f6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f6.u32l;
    // 0x80533430: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80533434: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533438: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8053343C: jr          $ra
    // 0x80533440: nop

    return;
    // 0x80533440: nop

;}
RECOMP_FUNC void func_805588D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805588D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805588DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805588E0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805588E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805588E8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x805588EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805588F0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805588F4: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x805588F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805588FC: jal         0x80048F84
    // 0x80558900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80558900: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80558904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80558908: jal         0x80048F84
    // 0x8055890C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8055890C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80558910: jal         0x805580E8
    // 0x80558914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_2;
    // 0x80558914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558918: jal         0x805582E0
    // 0x8055891C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x8055891C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80558920: beq         $v0, $zero, L_80558A14
    if (ctx->r2 == 0) {
        // 0x80558924: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80558A14;
    }
    // 0x80558924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558928: jal         0x80557B60
    // 0x8055892C: addiu       $a1, $zero, 0x290
    ctx->r5 = ADD32(0, 0X290);
    func_80557B60(rdram, ctx);
        goto after_4;
    // 0x8055892C: addiu       $a1, $zero, 0x290
    ctx->r5 = ADD32(0, 0X290);
    after_4:
    // 0x80558930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558934: jal         0x80557B60
    // 0x80558938: addiu       $a1, $zero, 0x285
    ctx->r5 = ADD32(0, 0X285);
    func_80557B60(rdram, ctx);
        goto after_5;
    // 0x80558938: addiu       $a1, $zero, 0x285
    ctx->r5 = ADD32(0, 0X285);
    after_5:
    // 0x8055893C: jal         0x80558830
    // 0x80558940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80558830(rdram, ctx);
        goto after_6;
    // 0x80558940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80558944: lw          $t6, 0x24($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X24);
    // 0x80558948: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8055894C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80558950: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80558954: beq         $at, $zero, L_805589BC
    if (ctx->r1 == 0) {
        // 0x80558958: addiu       $t4, $zero, 0x64
        ctx->r12 = ADD32(0, 0X64);
            goto L_805589BC;
    }
    // 0x80558958: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8055895C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80558960: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80558964: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x80558968: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8055896C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80558970: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x80558974: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80558978: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8055897C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80558980: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80558984: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x80558988: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x8055898C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558990: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558994: lbu         $t0, 0xF0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0XF0);
    // 0x80558998: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8055899C: andi        $t1, $t0, 0x7
    ctx->r9 = ctx->r8 & 0X7;
    // 0x805589A0: addiu       $t2, $t1, 0x20
    ctx->r10 = ADD32(ctx->r9, 0X20);
    // 0x805589A4: sb          $t2, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r10;
    // 0x805589A8: lw          $t3, 0x478($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X478);
    // 0x805589AC: jal         0x80559928
    // 0x805589B0: sb          $zero, 0xF2($t3)
    MEM_B(0XF2, ctx->r11) = 0;
    func_80559928(rdram, ctx);
        goto after_7;
    // 0x805589B0: sb          $zero, 0xF2($t3)
    MEM_B(0XF2, ctx->r11) = 0;
    after_7:
    // 0x805589B4: b           L_80558A0C
    // 0x805589B8: lw          $t1, 0x18($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18);
        goto L_80558A0C;
    // 0x805589B8: lw          $t1, 0x18($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18);
L_805589BC:
    // 0x805589BC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805589C0: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x805589C4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805589C8: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x805589CC: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x805589D0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805589D4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x805589D8: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x805589DC: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x805589E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805589E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805589E8: lbu         $t7, 0xF0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF0);
    // 0x805589EC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805589F0: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x805589F4: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x805589F8: sb          $t9, 0xF0($v0)
    MEM_B(0XF0, ctx->r2) = ctx->r25;
    // 0x805589FC: lw          $t0, 0x478($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X478);
    // 0x80558A00: jal         0x80559928
    // 0x80558A04: sb          $zero, 0xF2($t0)
    MEM_B(0XF2, ctx->r8) = 0;
    func_80559928(rdram, ctx);
        goto after_8;
    // 0x80558A04: sb          $zero, 0xF2($t0)
    MEM_B(0XF2, ctx->r8) = 0;
    after_8:
    // 0x80558A08: lw          $t1, 0x18($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X18);
L_80558A0C:
    // 0x80558A0C: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x80558A10: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
L_80558A14:
    // 0x80558A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558A18: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80558A1C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80558A20: jr          $ra
    // 0x80558A24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80558A24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806EC8A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC8A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EC8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC8AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EC8B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EC8B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EC8B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806EC8BC: jal         0x800577D8
    // 0x806EC8C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EC8C0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_0:
    // 0x806EC8C4: jal         0x806EC444
    // 0x806EC8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC444(rdram, ctx);
        goto after_1;
    // 0x806EC8C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EC8CC: jal         0x806EC4B0
    // 0x806EC8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC4B0(rdram, ctx);
        goto after_2;
    // 0x806EC8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EC8D4: jal         0x806EC584
    // 0x806EC8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_3;
    // 0x806EC8D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EC8DC: bne         $v0, $zero, L_806EC8FC
    if (ctx->r2 != 0) {
        // 0x806EC8E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EC8FC;
    }
    // 0x806EC8E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC8E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC8E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EC8EC: jal         0x806ED360
    // 0x806EC8F0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_4;
    // 0x806EC8F0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EC8F4: b           L_806EC9BC
    // 0x806EC8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC9BC;
    // 0x806EC8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC8FC:
    // 0x806EC8FC: jal         0x806EC5D4
    // 0x806EC900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC5D4(rdram, ctx);
        goto after_5;
    // 0x806EC900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EC904: beq         $v0, $zero, L_806EC924
    if (ctx->r2 == 0) {
        // 0x806EC908: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EC924;
    }
    // 0x806EC908: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC90C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC910: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EC914: jal         0x806ED360
    // 0x806EC918: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_6;
    // 0x806EC918: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EC91C: b           L_806EC9BC
    // 0x806EC920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC9BC;
    // 0x806EC920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC924:
    // 0x806EC924: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806EC928: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806EC92C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC930: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC934: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EC938: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EC93C: bc1fl       L_806EC9BC
    if (!c1cs) {
        // 0x806EC940: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EC9BC;
    }
    goto skip_0;
    // 0x806EC940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EC944: jal         0x806ED360
    // 0x806EC948: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_7;
    // 0x806EC948: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_7:
    // 0x806EC94C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806EC950: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC954: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x806EC958: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x806EC95C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EC960: nop

    // 0x806EC964: bc1fl       L_806EC994
    if (!c1cs) {
        // 0x806EC968: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EC994;
    }
    goto skip_1;
    // 0x806EC968: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x806EC96C: lui         $at, 0xC1B0
    ctx->r1 = S32(0XC1B0 << 16);
    // 0x806EC970: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EC974: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806EC978: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC97C: jal         0x806EC03C
    // 0x806EC980: nop

    func_806EC03C(rdram, ctx);
        goto after_8;
    // 0x806EC980: nop

    after_8:
    // 0x806EC984: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806EC988: b           L_806EC9AC
    // 0x806EC98C: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
        goto L_806EC9AC;
    // 0x806EC98C: swc1        $f0, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f0.u32l;
    // 0x806EC990: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EC994:
    // 0x806EC994: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806EC998: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC99C: jal         0x806EC03C
    // 0x806EC9A0: nop

    func_806EC03C(rdram, ctx);
        goto after_9;
    // 0x806EC9A0: nop

    after_9:
    // 0x806EC9A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806EC9A8: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
L_806EC9AC:
    // 0x806EC9AC: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC9B0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x806EC9B4: swc1        $f16, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f16.u32l;
    // 0x806EC9B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC9BC:
    // 0x806EC9BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EC9C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EC9C4: jr          $ra
    // 0x806EC9C8: nop

    return;
    // 0x806EC9C8: nop

;}
RECOMP_FUNC void func_80676D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80676D8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80676D90: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80676D94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80676D98: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80676D9C: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80676DA0: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80676DA4: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80676DA8: jr          $ra
    // 0x80676DAC: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    return;
    // 0x80676DAC: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_804EF878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EF87C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804EF880: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804EF884: jal         0x804EF6D8
    // 0x804EF888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804EF6D8(rdram, ctx);
        goto after_0;
    // 0x804EF888: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804EF88C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804EF890: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804EF894: lui         $t7, 0x804F
    ctx->r15 = S32(RELOC_HI16(267, 0X1080) << 16);
    // 0x804EF898: sw          $t6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r14;
    // 0x804EF89C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804EF8A0: addiu       $t7, $t7, -0x1F0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(267, 0X1080));
    // 0x804EF8A4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804EF8A8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804EF8AC: jal         0x804EF7AC
    // 0x804EF8B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF7AC(rdram, ctx);
        goto after_1;
    // 0x804EF8B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804EF8B4: bne         $v0, $zero, L_804EF8CC
    if (ctx->r2 != 0) {
        // 0x804EF8B8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804EF8CC;
    }
    // 0x804EF8B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804EF8BC: jal         0x800445A4
    // 0x804EF8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x804EF8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804EF8C4: b           L_804EF8F8
    // 0x804EF8C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804EF8F8;
    // 0x804EF8C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF8CC:
    // 0x804EF8CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF8D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804EF8D4: jal         0x804EF908
    // 0x804EF8D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804EF908(rdram, ctx);
        goto after_3;
    // 0x804EF8D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804EF8DC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804EF8E0: jal         0x804EF95C
    // 0x804EF8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804EF95C(rdram, ctx);
        goto after_4;
    // 0x804EF8E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804EF8E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804EF8EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804EF8F0: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804EF8F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804EF8F8:
    // 0x804EF8F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804EF8FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EF900: jr          $ra
    // 0x804EF904: nop

    return;
    // 0x804EF904: nop

;}
RECOMP_FUNC void func_805AC528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC528: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805AC52C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805AC530: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x805AC534: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x805AC538: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x805AC53C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x805AC540: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805AC544: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805AC548: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805AC54C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805AC550: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805AC554: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC558: lw          $s5, 0x174($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X174);
    // 0x805AC55C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x805AC560: lw          $v0, 0x10($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X10);
    // 0x805AC564: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x805AC568: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x805AC56C: beq         $v0, $zero, L_805AC58C
    if (ctx->r2 == 0) {
        // 0x805AC570: lw          $s0, 0x2C($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X2C);
            goto L_805AC58C;
    }
    // 0x805AC570: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x805AC574: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x805AC578: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x805AC57C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805AC580: beq         $t7, $at, L_805AC58C
    if (ctx->r15 == ctx->r1) {
        // 0x805AC584: nop
    
            goto L_805AC58C;
    }
    // 0x805AC584: nop

    // 0x805AC588: sw          $t8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r24;
L_805AC58C:
    // 0x805AC58C: jal         0x80049D74
    // 0x805AC590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x805AC590: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x805AC594: beq         $s0, $zero, L_805AC65C
    if (ctx->r16 == 0) {
        // 0x805AC598: sw          $zero, 0x8($s5)
        MEM_W(0X8, ctx->r21) = 0;
            goto L_805AC65C;
    }
    // 0x805AC598: sw          $zero, 0x8($s5)
    MEM_W(0X8, ctx->r21) = 0;
    // 0x805AC59C: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x805AC5A0: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x805AC5A4: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x805AC5A8: addiu       $fp, $zero, 0x40
    ctx->r30 = ADD32(0, 0X40);
    // 0x805AC5AC: addiu       $s7, $zero, 0x38
    ctx->r23 = ADD32(0, 0X38);
    // 0x805AC5B0: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x805AC5B4: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x805AC5B8: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
L_805AC5BC:
    // 0x805AC5BC: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x805AC5C0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x805AC5C4: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x805AC5C8: addu        $v0, $t0, $s1
    ctx->r2 = ADD32(ctx->r8, ctx->r17);
    // 0x805AC5CC: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x805AC5D0: beq         $v1, $zero, L_805AC624
    if (ctx->r3 == 0) {
        // 0x805AC5D4: nop
    
            goto L_805AC624;
    }
    // 0x805AC5D4: nop

    // 0x805AC5D8: beq         $s6, $v1, L_805AC624
    if (ctx->r22 == ctx->r3) {
        // 0x805AC5DC: nop
    
            goto L_805AC624;
    }
    // 0x805AC5DC: nop

    // 0x805AC5E0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x805AC5E4: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x805AC5E8: beq         $s7, $v1, L_805AC624
    if (ctx->r23 == ctx->r3) {
        // 0x805AC5EC: nop
    
            goto L_805AC624;
    }
    // 0x805AC5EC: nop

    // 0x805AC5F0: beq         $fp, $v1, L_805AC624
    if (ctx->r30 == ctx->r3) {
        // 0x805AC5F4: nop
    
            goto L_805AC624;
    }
    // 0x805AC5F4: nop

    // 0x805AC5F8: beq         $s0, $s4, L_805AC654
    if (ctx->r16 == ctx->r20) {
        // 0x805AC5FC: sll         $t1, $s0, 2
        ctx->r9 = S32(ctx->r16 << 2);
            goto L_805AC654;
    }
    // 0x805AC5FC: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x805AC600: lui         $t9, 0x805B
    ctx->r25 = S32(RELOC_HI16(441, 0X10F0) << 16);
    // 0x805AC604: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x805AC608: lw          $t9, -0x2D20($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(441, 0X10F0));
    // 0x805AC60C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805AC610: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x805AC614: jalr        $t9
    // 0x805AC618: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805AC618: nop

    after_1:
    // 0x805AC61C: b           L_805AC654
    // 0x805AC620: nop

        goto L_805AC654;
    // 0x805AC620: nop

L_805AC624:
    // 0x805AC624: bne         $s0, $s4, L_805AC654
    if (ctx->r16 != ctx->r20) {
        // 0x805AC628: nop
    
            goto L_805AC654;
    }
    // 0x805AC628: nop

    // 0x805AC62C: lw          $t2, 0x10($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X10);
    // 0x805AC630: bne         $t2, $zero, L_805AC654
    if (ctx->r10 != 0) {
        // 0x805AC634: nop
    
            goto L_805AC654;
    }
    // 0x805AC634: nop

    // 0x805AC638: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x805AC63C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x805AC640: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x805AC644: beq         $t3, $zero, L_805AC654
    if (ctx->r11 == 0) {
        // 0x805AC648: nop
    
            goto L_805AC654;
    }
    // 0x805AC648: nop

    // 0x805AC64C: jal         0x805AC200
    // 0x805AC650: sw          $t4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r12;
    func_805AC200(rdram, ctx);
        goto after_2;
    // 0x805AC650: sw          $t4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r12;
    after_2:
L_805AC654:
    // 0x805AC654: bnel        $s0, $zero, L_805AC5BC
    if (ctx->r16 != 0) {
        // 0x805AC658: lw          $t9, 0x0($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X0);
            goto L_805AC5BC;
    }
    goto skip_0;
    // 0x805AC658: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_805AC65C:
    // 0x805AC65C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x805AC660: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805AC664: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805AC668: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805AC66C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805AC670: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805AC674: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805AC678: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805AC67C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x805AC680: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x805AC684: jr          $ra
    // 0x805AC688: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x805AC688: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8006009C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006009C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800600A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800600A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800600A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800600AC: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x800600B0: jal         0x8005FEBC
    // 0x800600B4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_8005FEBC(rdram, ctx);
        goto after_0;
    // 0x800600B4: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x800600B8: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800600BC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x800600C0: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800600C4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800600C8: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800600CC: lh          $t8, 0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA);
    // 0x800600D0: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x800600D4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800600D8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800600DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800600E0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800600E4: jal         0x80065954
    // 0x800600E8: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x800600E8: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x800600EC: lwc1        $f18, 0x30($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800600F0: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800600F4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800600F8: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800600FC: nop

    // 0x80060100: bc1fl       L_80060260
    if (!c1cs) {
        // 0x80060104: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060260;
    }
    goto skip_0;
    // 0x80060104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80060108: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x8006010C: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x80060110: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060114: lwc1        $f6, 0x88($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X88);
    // 0x80060118: lh          $t0, 0x6($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X6);
    // 0x8006011C: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x80060120: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80060124: lwc1        $f8, 0x4($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80060128: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006012C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80060130: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80060134: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80060138: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006013C: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80060140: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80060144: lh          $t3, 0xC($v0)
    ctx->r11 = MEM_H(ctx->r2, 0XC);
    // 0x80060148: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8006014C: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80060150: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80060154: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80060158: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006015C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80060160: jal         0x80065954
    // 0x80060164: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80060164: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_2:
    // 0x80060168: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8006016C: lwc1        $f10, 0x54($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80060170: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80060174: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80060178: nop

    // 0x8006017C: bc1fl       L_80060260
    if (!c1cs) {
        // 0x80060180: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060260;
    }
    goto skip_1;
    // 0x80060180: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80060184: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x80060188: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x8006018C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060190: lwc1        $f10, 0x8C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x80060194: lh          $t5, 0x8($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8);
    // 0x80060198: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x8006019C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800601A0: lwc1        $f18, 0x8($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800601A4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800601A8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800601AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800601B0: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x800601B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800601B8: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800601BC: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800601C0: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800601C4: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x800601C8: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800601CC: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800601D0: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800601D4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800601D8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800601DC: jal         0x80065954
    // 0x800601E0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x800601E0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x800601E4: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800601E8: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800601EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800601F0: add.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800601F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800601F8: nop

    // 0x800601FC: bc1fl       L_80060260
    if (!c1cs) {
        // 0x80060200: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80060260;
    }
    goto skip_2;
    // 0x80060200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80060204: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80060208: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8006020C: lwc1        $f14, 0x28($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X28);
    // 0x80060210: lwc1        $f12, 0x48($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80060214: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80060218: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8006021C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80060220: sub.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80060224: lwc1        $f14, 0x50($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80060228: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8006022C: sub.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80060230: lwc1        $f18, 0x54($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80060234: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80060238: add.s       $f8, $f14, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8006023C: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x80060240: swc1        $f12, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f12.u32l;
    // 0x80060244: add.s       $f6, $f18, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80060248: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x8006024C: swc1        $f8, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f8.u32l;
    // 0x80060250: swc1        $f2, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f2.u32l;
    // 0x80060254: b           L_80060260
    // 0x80060258: swc1        $f6, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f6.u32l;
        goto L_80060260;
    // 0x80060258: swc1        $f6, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f6.u32l;
    // 0x8006025C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060260:
    // 0x80060260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80060268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006026C: jr          $ra
    // 0x80060270: nop

    return;
    // 0x80060270: nop

;}
RECOMP_FUNC void func_80699A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699A9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80699AA0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80699AA4: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    // 0x80699AA8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80699AAC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80699AB0: beq         $v1, $zero, L_80699AC4
    if (ctx->r3 == 0) {
        // 0x80699AB4: lw          $a2, 0x1F4($a1)
        ctx->r6 = MEM_W(ctx->r5, 0X1F4);
            goto L_80699AC4;
    }
    // 0x80699AB4: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x80699AB8: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80699ABC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x80699AC0: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_80699AC4:
    // 0x80699AC4: bne         $v1, $zero, L_80699B14
    if (ctx->r3 != 0) {
        // 0x80699AC8: nop
    
            goto L_80699B14;
    }
    // 0x80699AC8: nop

    // 0x80699ACC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80699AD0: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(562, 0X1528) << 16);
    // 0x80699AD4: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(562, 0X14D8) << 16);
    // 0x80699AD8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80699ADC: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80699AE0: lw          $t7, -0x5608($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(562, 0X1528));
    // 0x80699AE4: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80699AE8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80699AEC: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80699AF0: lw          $t8, -0x5658($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(562, 0X14D8));
    // 0x80699AF4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80699AF8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80699AFC: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80699B00: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80699B04: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x80699B08: bne         $at, $zero, L_80699B14
    if (ctx->r1 != 0) {
        // 0x80699B0C: sw          $t1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r9;
            goto L_80699B14;
    }
    // 0x80699B0C: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x80699B10: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
L_80699B14:
    // 0x80699B14: jal         0x80048F84
    // 0x80699B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80699B18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80699B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699B20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699B24: jr          $ra
    // 0x80699B28: nop

    return;
    // 0x80699B28: nop

;}
RECOMP_FUNC void func_80716E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716E70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716E74: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716E78: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716E7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716E80: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716E84: lw          $v1, 0x6E3C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E3C);
    // 0x80716E88: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716E8C: beql        $v1, $zero, L_80716EA8
    if (ctx->r3 == 0) {
        // 0x80716E90: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716EA8;
    }
    goto skip_0;
    // 0x80716E90: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716E94: jal         0x807169F8
    // 0x80716E98: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_807169F8(rdram, ctx);
        goto after_0;
    // 0x80716E98: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x80716E9C: b           L_80716ECC
    // 0x80716EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716ECC;
    // 0x80716EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716EA4: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716EA8:
    // 0x80716EA8: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716EAC: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716EB0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716EB4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716EB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716EBC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716EC0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716EC4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716ECC:
    // 0x80716ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716ED0: jr          $ra
    // 0x80716ED4: nop

    return;
    // 0x80716ED4: nop

;}
RECOMP_FUNC void func_80735D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735D54: jr          $ra
    // 0x80735D58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80735D58: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8003ACEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003ACF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003ACF4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8003ACF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003ACFC: beq         $a1, $at, L_8003AD20
    if (ctx->r5 == ctx->r1) {
        // 0x8003AD00: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8003AD20;
    }
    // 0x8003AD00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD04: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003AD08: beq         $a1, $at, L_8003AD40
    if (ctx->r5 == ctx->r1) {
        // 0x8003AD0C: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_8003AD40;
    }
    // 0x8003AD0C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8003AD10: beq         $a1, $at, L_8003AD30
    if (ctx->r5 == ctx->r1) {
        // 0x8003AD14: nop
    
            goto L_8003AD30;
    }
    // 0x8003AD14: nop

    // 0x8003AD18: b           L_8003AD4C
    // 0x8003AD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003AD4C;
    // 0x8003AD1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AD20:
    // 0x8003AD20: jal         0x8003B540
    // 0x8003AD24: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    func_8003B540(rdram, ctx);
        goto after_0;
    // 0x8003AD24: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    after_0:
    // 0x8003AD28: b           L_8003AD4C
    // 0x8003AD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003AD4C;
    // 0x8003AD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AD30:
    // 0x8003AD30: jal         0x8003B694
    // 0x8003AD34: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    func_8003B694(rdram, ctx);
        goto after_1;
    // 0x8003AD34: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    after_1:
    // 0x8003AD38: b           L_8003AD4C
    // 0x8003AD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003AD4C;
    // 0x8003AD3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AD40:
    // 0x8003AD40: jal         0x8003B6F8
    // 0x8003AD44: nop

    func_8003B6F8(rdram, ctx);
        goto after_2;
    // 0x8003AD44: nop

    after_2:
    // 0x8003AD48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003AD4C:
    // 0x8003AD4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003AD50: jr          $ra
    // 0x8003AD54: nop

    return;
    // 0x8003AD54: nop

;}
RECOMP_FUNC void func_80460CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460CA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80460CA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80460CA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80460CAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80460CB0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39D8) << 16);
    // 0x80460CB4: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80460CB8: jal         0x80082730
    // 0x80460CBC: lwc1        $f12, 0x3F68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39D8));
    fsin(rdram, ctx);
        goto after_0;
    // 0x80460CBC: lwc1        $f12, 0x3F68($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39D8));
    after_0:
    // 0x80460CC0: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80460CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80460CC8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80460CCC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39DC) << 16);
    // 0x80460CD0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80460CD4: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80460CD8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80460CDC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80460CE0: jal         0x8008D250
    // 0x80460CE4: lwc1        $f12, 0x3F6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39DC));
    fcos(rdram, ctx);
        goto after_1;
    // 0x80460CE4: lwc1        $f12, 0x3F6C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39DC));
    after_1:
    // 0x80460CE8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80460CEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80460CF0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80460CF4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39E0) << 16);
    // 0x80460CF8: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80460CFC: lwc1        $f16, 0x40($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X40);
    // 0x80460D00: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80460D04: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80460D08: jal         0x80081F80
    // 0x80460D0C: lwc1        $f12, 0x3F70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39E0));
    Math_FAsinF(rdram, ctx);
        goto after_2;
    // 0x80460D0C: lwc1        $f12, 0x3F70($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39E0));
    after_2:
    // 0x80460D10: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80460D14: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X39E4) << 16);
    // 0x80460D18: lwc1        $f8, 0x3F74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X39E4));
    // 0x80460D1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80460D20: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80460D24: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80460D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80460D2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80460D30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80460D34: jr          $ra
    // 0x80460D38: nop

    return;
    // 0x80460D38: nop

;}
