#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806EB264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EB264: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EB268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EB26C: jal         0x806EA9C0
    // 0x806EB270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806EA9C0(rdram, ctx);
        goto after_0;
    // 0x806EB270: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EB274: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EB278: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF80) << 16);
    // 0x806EB27C: lwc1        $f0, -0x48B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF80));
    // 0x806EB280: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x806EB284: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806EB288: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806EB28C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806EB290: nop

    // 0x806EB294: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806EB298: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x806EB29C: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x806EB2A0: jal         0x806EA92C
    // 0x806EB2A4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_806EA92C(rdram, ctx);
        goto after_1;
    // 0x806EB2A4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x806EB2A8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806EB2AC: beq         $v0, $zero, L_806EB2E4
    if (ctx->r2 == 0) {
        // 0x806EB2B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806EB2E4;
    }
    // 0x806EB2B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806EB2B4: lw          $t6, 0x68($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X68);
    // 0x806EB2B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x806EB2BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB2C0: bne         $t6, $zero, L_806EB2DC
    if (ctx->r14 != 0) {
        // 0x806EB2C4: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_806EB2DC;
    }
    // 0x806EB2C4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x806EB2C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EB2CC: jal         0x806EB43C
    // 0x806EB2D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_806EB43C(rdram, ctx);
        goto after_2;
    // 0x806EB2D0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_2:
    // 0x806EB2D4: b           L_806EB2E8
    // 0x806EB2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806EB2E8;
    // 0x806EB2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EB2DC:
    // 0x806EB2DC: jal         0x806EB43C
    // 0x806EB2E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EB43C(rdram, ctx);
        goto after_3;
    // 0x806EB2E0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
L_806EB2E4:
    // 0x806EB2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EB2E8:
    // 0x806EB2E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EB2EC: jr          $ra
    // 0x806EB2F0: nop

    return;
    // 0x806EB2F0: nop

;}
RECOMP_FUNC void func_806D6850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6850: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(619, 0X228) << 16);
    // 0x806D6854: addiu       $v0, $v0, 0x6A78
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(619, 0X228));
    // 0x806D6858: jr          $ra
    // 0x806D685C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D685C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806741B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806741B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806741BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806741C0: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806741C4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806741C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806741CC: beq         $t6, $zero, L_8067423C
    if (ctx->r14 == 0) {
        // 0x806741D0: nop
    
            goto L_8067423C;
    }
    // 0x806741D0: nop

    // 0x806741D4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806741D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806741DC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806741E0: jalr        $t9
    // 0x806741E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806741E4: nop

    after_0:
    // 0x806741E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806741EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806741F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806741F4: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806741F8: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806741FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80674200: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80674204: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80674208: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8067420C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80674210: bne         $v0, $at, L_80674234
    if (ctx->r2 != ctx->r1) {
        // 0x80674214: sh          $t3, 0x144($a0)
        MEM_H(0X144, ctx->r4) = ctx->r11;
            goto L_80674234;
    }
    // 0x80674214: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x80674218: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8067421C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80674220: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80674224: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x80674228: beq         $at, $zero, L_80674234
    if (ctx->r1 == 0) {
        // 0x8067422C: sw          $t5, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r13;
            goto L_80674234;
    }
    // 0x8067422C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80674230: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80674234:
    // 0x80674234: b           L_8067423C
    // 0x80674238: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8067423C;
    // 0x80674238: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8067423C:
    // 0x8067423C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80674240: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80674244: jr          $ra
    // 0x80674248: nop

    return;
    // 0x80674248: nop

;}
RECOMP_FUNC void func_800261E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800261E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800261E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800261E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800261EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800261F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x800261F4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800261F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800261FC: jal         0x80024680
    // 0x80026200: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80026200: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_0:
    // 0x80026204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80026208: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002620C: jr          $ra
    // 0x80026210: nop

    return;
    // 0x80026210: nop

;}
RECOMP_FUNC void func_804CEE0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CEE0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CEE10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CEE14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CEE18: jal         0x8004700C
    // 0x804CEE1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804CEE1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804CEE20: beq         $v0, $zero, L_804CEE64
    if (ctx->r2 == 0) {
        // 0x804CEE24: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804CEE64;
    }
    // 0x804CEE24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x804CEE28: jal         0x804CED5C
    // 0x804CEE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CED5C(rdram, ctx);
        goto after_1;
    // 0x804CEE2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CEE30: jal         0x804CECC8
    // 0x804CEE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECC8(rdram, ctx);
        goto after_2;
    // 0x804CEE34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804CEE38: jal         0x804CECB8
    // 0x804CEE3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CECB8(rdram, ctx);
        goto after_3;
    // 0x804CEE3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804CEE40: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804CEE44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CEE48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CEE4C: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x804CEE50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CEE54: bnel        $s0, $t7, L_804CEE68
    if (ctx->r16 != ctx->r15) {
        // 0x804CEE58: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CEE68;
    }
    goto skip_0;
    // 0x804CEE58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CEE5C: jal         0x804CF34C
    // 0x804CEE60: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804CF34C(rdram, ctx);
        goto after_4;
    // 0x804CEE60: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
L_804CEE64:
    // 0x804CEE64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CEE68:
    // 0x804CEE68: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CEE6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CEE70: jr          $ra
    // 0x804CEE74: nop

    return;
    // 0x804CEE74: nop

;}
RECOMP_FUNC void func_8069D090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D098: jal         0x8069CFB0
    // 0x8069D09C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069CFB0(rdram, ctx);
        goto after_0;
    // 0x8069D09C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D0A0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8069D0A4: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8069D0A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D0AC: bnel        $t6, $zero, L_8069D0DC
    if (ctx->r14 != 0) {
        // 0x8069D0B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069D0DC;
    }
    goto skip_0;
    // 0x8069D0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8069D0B4: jal         0x8069CD84
    // 0x8069D0B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8069CD84(rdram, ctx);
        goto after_1;
    // 0x8069D0B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8069D0BC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8069D0C0: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X3F8) << 16);
    // 0x8069D0C4: addiu       $t7, $t7, -0x2F18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X3F8));
    // 0x8069D0C8: sw          $t7, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r15;
    // 0x8069D0CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8069D0D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8069D0D4: sb          $t9, 0x165($t0)
    MEM_B(0X165, ctx->r8) = ctx->r25;
    // 0x8069D0D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069D0DC:
    // 0x8069D0DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D0E0: jr          $ra
    // 0x8069D0E4: nop

    return;
    // 0x8069D0E4: nop

;}
RECOMP_FUNC void func_8044B4DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B4DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044B4E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B4E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B4E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B4EC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B4F0: lw          $a1, 0x6A78($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A78);
    // 0x8044B4F4: beq         $a1, $zero, L_8044B50C
    if (ctx->r5 == 0) {
        // 0x8044B4F8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044B50C;
    }
    // 0x8044B4F8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044B4FC: jal         0x80050A2C
    // 0x8044B500: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044B500: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044B504: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B508: sw          $zero, 0x6A78($v1)
    MEM_W(0X6A78, ctx->r3) = 0;
L_8044B50C:
    // 0x8044B50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B510: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044B514: jr          $ra
    // 0x8044B518: nop

    return;
    // 0x8044B518: nop

;}
RECOMP_FUNC void func_805D84A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D84A4: lw          $t6, 0x14($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14);
    // 0x805D84A8: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x805D84AC: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x805D84B0: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805D84B4: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805D84B8: sw          $t9, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->r25;
    // 0x805D84BC: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x805D84C0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x805D84C4: lui         $t8, 0x805E
    ctx->r24 = S32(RELOC_HI16(474, 0X1280) << 16);
    // 0x805D84C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805D84CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x805D84D0: addiu       $t8, $t8, -0x7480
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(474, 0X1280));
    // 0x805D84D4: beq         $t1, $zero, L_805D8500
    if (ctx->r9 == 0) {
        // 0x805D84D8: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_805D8500;
    }
    // 0x805D84D8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x805D84DC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x805D84E0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x805D84E4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x805D84E8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805D84EC: nop

    // 0x805D84F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D84F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D84F8: b           L_805D851C
    // 0x805D84FC: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
        goto L_805D851C;
    // 0x805D84FC: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
L_805D8500:
    // 0x805D8500: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x805D8504: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x805D8508: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x805D850C: nop

    // 0x805D8510: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805D8514: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805D8518: swc1        $f4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f4.u32l;
L_805D851C:
    // 0x805D851C: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x805D8520: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x805D8524: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x805D8528: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x805D852C: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x805D8530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D8534: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805D8538: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x805D853C: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x805D8540: lwc1        $f16, -0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X10);
    // 0x805D8544: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x805D8548: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805D854C: swc1        $f18, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f18.u32l;
    // 0x805D8550: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x805D8554: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x805D8558: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x805D855C: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x805D8560: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x805D8564: lwc1        $f8, -0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X8);
    // 0x805D8568: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x805D856C: swc1        $f8, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f8.u32l;
L_805D8570:
    // 0x805D8570: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x805D8574: beql        $t1, $zero, L_805D85A4
    if (ctx->r9 == 0) {
        // 0x805D8578: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_805D85A4;
    }
    goto skip_0;
    // 0x805D8578: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x805D857C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x805D8580: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x805D8584: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x805D8588: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x805D858C: nop

    // 0x805D8590: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805D8594: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805D8598: b           L_805D85BC
    // 0x805D859C: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
        goto L_805D85BC;
    // 0x805D859C: swc1        $f4, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f4.u32l;
    // 0x805D85A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_805D85A4:
    // 0x805D85A4: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x805D85A8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x805D85AC: nop

    // 0x805D85B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805D85B4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805D85B8: swc1        $f10, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f10.u32l;
L_805D85BC:
    // 0x805D85BC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x805D85C0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x805D85C4: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x805D85C8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x805D85CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x805D85D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805D85D4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x805D85D8: swc1        $f4, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f4.u32l;
    // 0x805D85DC: lwc1        $f6, -0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, -0X10);
    // 0x805D85E0: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x805D85E4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805D85E8: swc1        $f8, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f8.u32l;
    // 0x805D85EC: lwc1        $f10, -0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0XC);
    // 0x805D85F0: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x805D85F4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x805D85F8: swc1        $f16, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f16.u32l;
    // 0x805D85FC: lw          $t0, -0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X4);
    // 0x805D8600: lwc1        $f18, -0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X8);
    // 0x805D8604: swc1        $f18, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f18.u32l;
    // 0x805D8608: lw          $t1, 0x138($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X138);
    // 0x805D860C: beql        $t1, $zero, L_805D863C
    if (ctx->r9 == 0) {
        // 0x805D8610: lw          $t4, 0x0($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X0);
            goto L_805D863C;
    }
    goto skip_1;
    // 0x805D8610: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x805D8614: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x805D8618: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x805D861C: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x805D8620: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x805D8624: nop

    // 0x805D8628: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805D862C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805D8630: b           L_805D8654
    // 0x805D8634: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
        goto L_805D8654;
    // 0x805D8634: swc1        $f10, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f10.u32l;
    // 0x805D8638: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
L_805D863C:
    // 0x805D863C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x805D8640: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x805D8644: nop

    // 0x805D8648: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805D864C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805D8650: swc1        $f4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f4.u32l;
L_805D8654:
    // 0x805D8654: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x805D8658: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x805D865C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x805D8660: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x805D8664: addiu       $v1, $v1, 0x18
    ctx->r3 = ADD32(ctx->r3, 0X18);
    // 0x805D8668: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x805D866C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805D8670: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x805D8674: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x805D8678: lwc1        $f16, -0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0X10);
    // 0x805D867C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x805D8680: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805D8684: swc1        $f18, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f18.u32l;
    // 0x805D8688: lwc1        $f4, -0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0XC);
    // 0x805D868C: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x805D8690: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x805D8694: swc1        $f6, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f6.u32l;
    // 0x805D8698: lw          $t0, -0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X4);
    // 0x805D869C: lwc1        $f8, -0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X8);
    // 0x805D86A0: bne         $a2, $a1, L_805D8570
    if (ctx->r6 != ctx->r5) {
        // 0x805D86A4: swc1        $f8, 0x50($t0)
        MEM_W(0X50, ctx->r8) = ctx->f8.u32l;
            goto L_805D8570;
    }
    // 0x805D86A4: swc1        $f8, 0x50($t0)
    MEM_W(0X50, ctx->r8) = ctx->f8.u32l;
    // 0x805D86A8: jr          $ra
    // 0x805D86AC: nop

    return;
    // 0x805D86AC: nop

;}
RECOMP_FUNC void func_8001AA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AA84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001AA88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001AA8C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8001AA90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001AA94: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001AA98: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001AA9C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001AAA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001AAA4: sw          $t6, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r14;
    // 0x8001AAA8: sw          $zero, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = 0;
    // 0x8001AAAC: sh          $a1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r5;
    // 0x8001AAB0: sw          $a2, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r6;
    // 0x8001AAB4: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001AAB8: jal         0x8001A568
    // 0x8001AABC: lw          $a0, 0x590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X590);
    func_8001A568(rdram, ctx);
        goto after_0;
    // 0x8001AABC: lw          $a0, 0x590($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X590);
    after_0:
    // 0x8001AAC0: lw          $a0, 0x88($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X88);
    // 0x8001AAC4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001AAC8: addiu       $a3, $a3, 0x590
    ctx->r7 = ADD32(ctx->r7, 0X590);
    // 0x8001AACC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8001AAD0: beq         $a0, $zero, L_8001AAE8
    if (ctx->r4 == 0) {
        // 0x8001AAD4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001AAE8;
    }
    // 0x8001AAD4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001AAD8: beq         $a0, $a2, L_8001AB30
    if (ctx->r4 == ctx->r6) {
        // 0x8001AADC: nop
    
            goto L_8001AB30;
    }
    // 0x8001AADC: nop

    // 0x8001AAE0: b           L_8001AB44
    // 0x8001AAE4: nop

        goto L_8001AB44;
    // 0x8001AAE4: nop

L_8001AAE8:
    // 0x8001AAE8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8001AAEC: beq         $v0, $zero, L_8001AB14
    if (ctx->r2 == 0) {
        // 0x8001AAF0: nop
    
            goto L_8001AB14;
    }
    // 0x8001AAF0: nop

    // 0x8001AAF4: sw          $a2, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->r6;
    // 0x8001AAF8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001AAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AB00: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x8001AB04: jal         0x80019D78
    // 0x8001AB08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80019D78(rdram, ctx);
        goto after_1;
    // 0x8001AB08: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8001AB0C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8001AB10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8001AB14:
    // 0x8001AB14: beq         $v1, $zero, L_8001AB44
    if (ctx->r3 == 0) {
        // 0x8001AB18: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001AB44;
    }
    // 0x8001AB18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AB1C: sw          $a2, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r6;
    // 0x8001AB20: jal         0x80019D78
    // 0x8001AB24: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_80019D78(rdram, ctx);
        goto after_2;
    // 0x8001AB24: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_2:
    // 0x8001AB28: b           L_8001AB44
    // 0x8001AB2C: nop

        goto L_8001AB44;
    // 0x8001AB2C: nop

L_8001AB30:
    // 0x8001AB30: beq         $v0, $zero, L_8001AB44
    if (ctx->r2 == 0) {
        // 0x8001AB34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001AB44;
    }
    // 0x8001AB34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001AB38: sw          $a2, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r6;
    // 0x8001AB3C: jal         0x80019D78
    // 0x8001AB40: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    func_80019D78(rdram, ctx);
        goto after_3;
    // 0x8001AB40: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    after_3:
L_8001AB44:
    // 0x8001AB44: jal         0x8001A46C
    // 0x8001AB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A46C(rdram, ctx);
        goto after_4;
    // 0x8001AB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8001AB4C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8001AB50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001AB54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001AB58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001AB5C: jr          $ra
    // 0x8001AB60: nop

    return;
    // 0x8001AB60: nop

    // 0x8001AB64: nop

    // 0x8001AB68: nop

    // 0x8001AB6C: nop

;}
RECOMP_FUNC void func_806E9858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E985C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E9860: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806E9864: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(667, 0X1698) << 16);
    // 0x806E9868: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E986C: addiu       $t6, $t6, -0x66B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(667, 0X1698));
    // 0x806E9870: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E9874: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806E9878: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E987C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E9880: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806E9884: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806E9888: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806E988C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x806E9890: jal         0x80048378
    // 0x806E9894: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806E9894: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806E9898: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806E989C: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(667, 0XCEC) << 16);
    // 0x806E98A0: addiu       $t9, $t9, -0x7064
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(667, 0XCEC));
    // 0x806E98A4: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    // 0x806E98A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E98AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E98B0: jr          $ra
    // 0x806E98B4: nop

    return;
    // 0x806E98B4: nop

;}
RECOMP_FUNC void func_804A28A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A28A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A28A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A28AC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804A28B0: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(173, 0X2B2C) << 16);
    // 0x804A28B4: addiu       $t8, $t8, 0x2F6C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(173, 0X2B2C));
    // 0x804A28B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A28BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804A28C0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804A28C4: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804A28C8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804A28CC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804A28D0: beql        $v1, $zero, L_804A2904
    if (ctx->r3 == 0) {
        // 0x804A28D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A2904;
    }
    goto skip_0;
    // 0x804A28D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A28D8: jalr        $v1
    // 0x804A28DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804A28DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A28E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A28E4: lw          $t9, 0x15C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X15C);
    // 0x804A28E8: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x804A28EC: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x804A28F0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x804A28F4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x804A28F8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x804A28FC: sh          $t4, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r12;
    // 0x804A2900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A2904:
    // 0x804A2904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A2908: jr          $ra
    // 0x804A290C: nop

    return;
    // 0x804A290C: nop

;}
RECOMP_FUNC void func_806CDE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDE04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806CDE08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CDE0C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806CDE10: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806CDE14: jal         0x8004700C
    // 0x806CDE18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806CDE18: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x806CDE1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x806CDE20: lw          $t6, 0x1E0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1E0);
    // 0x806CDE24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806CDE28: bnel        $t6, $at, L_806CDF24
    if (ctx->r14 != ctx->r1) {
        // 0x806CDE2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CDF24;
    }
    goto skip_0;
    // 0x806CDE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CDE30: jal         0x80067E68
    // 0x806CDE34: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x806CDE34: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_1:
    // 0x806CDE38: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x806CDE3C: jal         0x80067BBC
    // 0x806CDE40: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806CDE40: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    after_2:
    // 0x806CDE44: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806CDE48: jal         0x80067818
    // 0x806CDE4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806CDE4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806CDE50: jal         0x80047090
    // 0x806CDE54: addiu       $a0, $zero, 0x45A1
    ctx->r4 = ADD32(0, 0X45A1);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x806CDE54: addiu       $a0, $zero, 0x45A1
    ctx->r4 = ADD32(0, 0X45A1);
    after_4:
    // 0x806CDE58: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806CDE5C: beq         $v0, $at, L_806CDF20
    if (ctx->r2 == ctx->r1) {
        // 0x806CDE60: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_806CDF20;
    }
    // 0x806CDE60: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x806CDE64: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C54) << 16);
    // 0x806CDE68: lwc1        $f4, -0xC8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C54));
    // 0x806CDE6C: lwc1        $f6, 0x8C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x806CDE70: lui         $a0, 0x45A1
    ctx->r4 = S32(0X45A1 << 16);
    // 0x806CDE74: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    // 0x806CDE78: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CDE7C: sh          $v1, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r3;
    // 0x806CDE80: lui         $a1, 0xC080
    ctx->r5 = S32(0XC080 << 16);
    // 0x806CDE84: lui         $a2, 0xC140
    ctx->r6 = S32(0XC140 << 16);
    // 0x806CDE88: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x806CDE8C: jal         0x8004613C
    // 0x806CDE90: nop

    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x806CDE90: nop

    after_5:
    // 0x806CDE94: lhu         $v1, 0x2A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X2A);
    // 0x806CDE98: beq         $v0, $zero, L_806CDF1C
    if (ctx->r2 == 0) {
        // 0x806CDE9C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806CDF1C;
    }
    // 0x806CDE9C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806CDEA0: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x806CDEA4: andi        $t8, $v1, 0x3FF
    ctx->r24 = ctx->r3 & 0X3FF;
    // 0x806CDEA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806CDEAC: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806CDEB0: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806CDEB4: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
    // 0x806CDEB8: jal         0x80047F9C
    // 0x806CDEBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806CDEBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x806CDEC0: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x806CDEC4: jal         0x8005FDC4
    // 0x806CDEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_7;
    // 0x806CDEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806CDECC: lui         $t2, 0x806D
    ctx->r10 = S32(RELOC_HI16(604, 0X24E8) << 16);
    // 0x806CDED0: addiu       $t2, $t2, -0x23F8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(604, 0X24E8));
    // 0x806CDED4: sw          $t2, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r10;
    // 0x806CDED8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x806CDEDC: beql        $t3, $zero, L_806CDF24
    if (ctx->r11 == 0) {
        // 0x806CDEE0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CDF24;
    }
    goto skip_1;
    // 0x806CDEE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806CDEE4: jal         0x806CEB64
    // 0x806CDEE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CEB64(rdram, ctx);
        goto after_8;
    // 0x806CDEE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806CDEEC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x806CDEF0: lwc1        $f10, 0x84($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X84);
    // 0x806CDEF4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806CDEF8: lwc1        $f16, 0x84($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X84);
    // 0x806CDEFC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x806CDF00: nop

    // 0x806CDF04: bc1f        L_806CDF14
    if (!c1cs) {
        // 0x806CDF08: nop
    
            goto L_806CDF14;
    }
    // 0x806CDF08: nop

    // 0x806CDF0C: b           L_806CDF20
    // 0x806CDF10: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
        goto L_806CDF20;
    // 0x806CDF10: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
L_806CDF14:
    // 0x806CDF14: b           L_806CDF20
    // 0x806CDF18: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
        goto L_806CDF20;
    // 0x806CDF18: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
L_806CDF1C:
    // 0x806CDF1C: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
L_806CDF20:
    // 0x806CDF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CDF24:
    // 0x806CDF24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806CDF28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806CDF2C: jr          $ra
    // 0x806CDF30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806CDF30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80580720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80580724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580728: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8058072C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80580730: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80580734: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80580738: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8058073C: jal         0x80047090
    // 0x80580740: addiu       $a0, $zero, 0x40ED
    ctx->r4 = ADD32(0, 0X40ED);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80580740: addiu       $a0, $zero, 0x40ED
    ctx->r4 = ADD32(0, 0X40ED);
    after_0:
    // 0x80580744: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80580748: beq         $v0, $at, L_80580780
    if (ctx->r2 == ctx->r1) {
        // 0x8058074C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80580780;
    }
    // 0x8058074C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80580750: lui         $at, 0x40ED
    ctx->r1 = S32(0X40ED << 16);
    // 0x80580754: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80580758: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x8058075C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80580760: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80580764: jal         0x8004613C
    // 0x80580768: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80580768: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8058076C: beq         $v0, $zero, L_80580780
    if (ctx->r2 == 0) {
        // 0x80580770: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80580780;
    }
    // 0x80580770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80580774: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80580778: jal         0x80047F9C
    // 0x8058077C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8058077C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
L_80580780:
    // 0x80580780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580784: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80580788: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8058078C: jr          $ra
    // 0x80580790: nop

    return;
    // 0x80580790: nop

;}
RECOMP_FUNC void func_800597A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800597A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800597A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800597AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800597B0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800597B4: jal         0x80081C64
    // 0x800597B8: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x800597B8: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x800597BC: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800597C0: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800597C4: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x800597C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800597CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800597D0: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800597D4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800597D8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800597DC: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800597E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800597E4: lh          $t9, 0x2($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2);
    // 0x800597E8: lw          $t7, 0x478($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X478);
    // 0x800597EC: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800597F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800597F4: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800597F8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800597FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059804: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059808: lwc1        $f6, 0x34($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X34);
    // 0x8005980C: mul.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059810: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80059814: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059818: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005981C: lwc1        $f4, 0x4($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80059820: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80059824: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80059828: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005982C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80059830: nop

    // 0x80059834: bc1f        L_80059840
    if (!c1cs) {
        // 0x80059838: nop
    
            goto L_80059840;
    }
    // 0x80059838: nop

    // 0x8005983C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059840:
    // 0x80059840: jr          $ra
    // 0x80059844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8004E3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E3B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004E3BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E3C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E3C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004E3C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004E3CC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004E3D0: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004E3D4: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004E3D8: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004E3DC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004E3E0: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004E3E4: addu        $s0, $t8, $t0
    ctx->r16 = ADD32(ctx->r24, ctx->r8);
    // 0x8004E3E8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8004E3EC: beql        $v0, $zero, L_8004E440
    if (ctx->r2 == 0) {
        // 0x8004E3F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E440;
    }
    goto skip_0;
    // 0x8004E3F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8004E3F4: beql        $v0, $at, L_8004E440
    if (ctx->r2 == ctx->r1) {
        // 0x8004E3F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E440;
    }
    goto skip_1;
    // 0x8004E3F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004E3FC: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004E400: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004E404: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004E408: beq         $v0, $at, L_8004E43C
    if (ctx->r2 == ctx->r1) {
        // 0x8004E40C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004E43C;
    }
    // 0x8004E40C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004E410: beq         $v0, $at, L_8004E43C
    if (ctx->r2 == ctx->r1) {
        // 0x8004E414: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004E43C;
    }
    // 0x8004E414: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004E418: jal         0x8004D11C
    // 0x8004E41C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_8004D11C(rdram, ctx);
        goto after_0;
    // 0x8004E41C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x8004E420: lbu         $t1, 0x14($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X14);
    // 0x8004E424: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8004E428: beql        $t1, $zero, L_8004E440
    if (ctx->r9 == 0) {
        // 0x8004E42C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004E440;
    }
    goto skip_2;
    // 0x8004E42C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8004E430: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8004E434: ori         $t3, $t2, 0xF
    ctx->r11 = ctx->r10 | 0XF;
    // 0x8004E438: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_8004E43C:
    // 0x8004E43C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004E440:
    // 0x8004E440: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004E444: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004E448: jr          $ra
    // 0x8004E44C: nop

    return;
    // 0x8004E44C: nop

;}
RECOMP_FUNC void func_8064B530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B530: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064B534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064B538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064B53C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064B540: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064B544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B548: blez        $v0, L_8064B55C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064B54C: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064B55C;
    }
    // 0x8064B54C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064B550: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064B554: b           L_8064B588
    // 0x8064B558: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064B588;
    // 0x8064B558: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064B55C:
    // 0x8064B55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064B560: jal         0x8064B918
    // 0x8064B564: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064B918(rdram, ctx);
        goto after_0;
    // 0x8064B564: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064B568: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064B56C: jal         0x80067BBC
    // 0x8064B570: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064B570: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064B574: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064B578: jal         0x80067818
    // 0x8064B57C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064B57C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064B580: jal         0x8064A43C
    // 0x8064B584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064B584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064B588:
    // 0x8064B588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064B58C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064B590: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064B594: jr          $ra
    // 0x8064B598: nop

    return;
    // 0x8064B598: nop

;}
RECOMP_FUNC void func_806F9894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9894: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F9898: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(697, 0X3C) << 16);
    // 0x806F989C: addiu       $t6, $t6, -0x6A44
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(697, 0X3C));
    // 0x806F98A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F98A4: jr          $ra
    // 0x806F98A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806F98A8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806E7240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7240: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806E7244: addiu       $at, $zero, 0x40C5
    ctx->r1 = ADD32(0, 0X40C5);
    // 0x806E7248: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(664, 0XC30) << 16);
    // 0x806E724C: bne         $v0, $at, L_806E7260
    if (ctx->r2 != ctx->r1) {
        // 0x806E7250: addiu       $t6, $t6, 0x7E70
        ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(664, 0XC30));
            goto L_806E7260;
    }
    // 0x806E7250: addiu       $t6, $t6, 0x7E70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(664, 0XC30));
    // 0x806E7254: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806E7258: sw          $t6, -0x72C8($at)
    MEM_W(-0X72C8, ctx->r1) = ctx->r14;
    // 0x806E725C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
L_806E7260:
    // 0x806E7260: addiu       $at, $zero, 0x4027
    ctx->r1 = ADD32(0, 0X4027);
    // 0x806E7264: beq         $v0, $at, L_806E727C
    if (ctx->r2 == ctx->r1) {
        // 0x806E7268: addiu       $at, $zero, 0x473B
        ctx->r1 = ADD32(0, 0X473B);
            goto L_806E727C;
    }
    // 0x806E7268: addiu       $at, $zero, 0x473B
    ctx->r1 = ADD32(0, 0X473B);
    // 0x806E726C: beq         $v0, $at, L_806E7288
    if (ctx->r2 == ctx->r1) {
        // 0x806E7270: nop
    
            goto L_806E7288;
    }
    // 0x806E7270: nop

    // 0x806E7274: b           L_806E7294
    // 0x806E7278: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(664, 0X228) << 16);
        goto L_806E7294;
    // 0x806E7278: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(664, 0X228) << 16);
L_806E727C:
    // 0x806E727C: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(664, 0XCD8) << 16);
    // 0x806E7280: jr          $ra
    // 0x806E7284: addiu       $v0, $v0, 0x7F18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0XCD8));
    return;
    // 0x806E7284: addiu       $v0, $v0, 0x7F18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0XCD8));
L_806E7288:
    // 0x806E7288: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(664, 0X1B8) << 16);
    // 0x806E728C: jr          $ra
    // 0x806E7290: addiu       $v0, $v0, 0x73F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0X1B8));
    return;
    // 0x806E7290: addiu       $v0, $v0, 0x73F8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0X1B8));
L_806E7294:
    // 0x806E7294: addiu       $v0, $v0, 0x7468
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(664, 0X228));
    // 0x806E7298: jr          $ra
    // 0x806E729C: nop

    return;
    // 0x806E729C: nop

;}
RECOMP_FUNC void func_80411968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80411968: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8041196C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80411970: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80411974: addu        $a2, $a0, $at
    ctx->r6 = ADD32(ctx->r4, ctx->r1);
    // 0x80411978: lw          $t6, 0x39E4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X39E4);
    // 0x8041197C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80411980: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80411984: beq         $t6, $zero, L_80411A88
    if (ctx->r14 == 0) {
        // 0x80411988: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80411A88;
    }
    // 0x80411988: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8041198C: addu        $a1, $a0, $at
    ctx->r5 = ADD32(ctx->r4, ctx->r1);
    // 0x80411990: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80411994: lw          $t7, 0x39E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X39E8);
L_80411998:
    // 0x80411998: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8041199C: beql        $t7, $zero, L_80411A78
    if (ctx->r15 == 0) {
        // 0x804119A0: lw          $t7, 0x39E4($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X39E4);
            goto L_80411A78;
    }
    goto skip_0;
    // 0x804119A0: lw          $t7, 0x39E4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X39E4);
    skip_0:
    // 0x804119A4: lw          $t8, 0x39E8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X39E8);
L_804119A8:
    // 0x804119A8: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x804119AC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804119B0: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804119B4: mflo        $t2
    ctx->r10 = lo;
    // 0x804119B8: addu        $a3, $t2, $v0
    ctx->r7 = ADD32(ctx->r10, ctx->r2);
    // 0x804119BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804119C0: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804119C4: mflo        $t3
    ctx->r11 = lo;
    // 0x804119C8: addu        $t0, $a0, $t3
    ctx->r8 = ADD32(ctx->r4, ctx->r11);
    // 0x804119CC: lbu         $t4, 0x6($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X6);
    // 0x804119D0: sb          $t4, -0x34($s0)
    MEM_B(-0X34, ctx->r16) = ctx->r12;
    // 0x804119D4: lbu         $t5, 0x7($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X7);
    // 0x804119D8: sb          $t5, -0x33($s0)
    MEM_B(-0X33, ctx->r16) = ctx->r13;
    // 0x804119DC: lbu         $t6, 0x8($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X8);
    // 0x804119E0: sb          $t6, -0x32($s0)
    MEM_B(-0X32, ctx->r16) = ctx->r14;
    // 0x804119E4: lbu         $t7, 0x9($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X9);
    // 0x804119E8: sb          $t7, -0x31($s0)
    MEM_B(-0X31, ctx->r16) = ctx->r15;
    // 0x804119EC: lbu         $t8, 0x10($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X10);
    // 0x804119F0: sb          $t8, -0x14($s0)
    MEM_B(-0X14, ctx->r16) = ctx->r24;
    // 0x804119F4: lbu         $t9, 0x11($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X11);
    // 0x804119F8: sb          $t9, -0x13($s0)
    MEM_B(-0X13, ctx->r16) = ctx->r25;
    // 0x804119FC: lbu         $t2, 0x12($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X12);
    // 0x80411A00: sb          $t2, -0x12($s0)
    MEM_B(-0X12, ctx->r16) = ctx->r10;
    // 0x80411A04: lbu         $t3, 0x13($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X13);
    // 0x80411A08: sb          $t3, -0x11($s0)
    MEM_B(-0X11, ctx->r16) = ctx->r11;
    // 0x80411A0C: lw          $t4, 0x39E8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X39E8);
    // 0x80411A10: addu        $a3, $a3, $t4
    ctx->r7 = ADD32(ctx->r7, ctx->r12);
    // 0x80411A14: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80411A18: multu       $a3, $t1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80411A1C: mflo        $t5
    ctx->r13 = lo;
    // 0x80411A20: addu        $t0, $a0, $t5
    ctx->r8 = ADD32(ctx->r4, ctx->r13);
    // 0x80411A24: lbu         $t6, 0x6($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X6);
    // 0x80411A28: sb          $t6, -0x24($s0)
    MEM_B(-0X24, ctx->r16) = ctx->r14;
    // 0x80411A2C: lbu         $t7, 0x7($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X7);
    // 0x80411A30: sb          $t7, -0x23($s0)
    MEM_B(-0X23, ctx->r16) = ctx->r15;
    // 0x80411A34: lbu         $t8, 0x8($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X8);
    // 0x80411A38: sb          $t8, -0x22($s0)
    MEM_B(-0X22, ctx->r16) = ctx->r24;
    // 0x80411A3C: lbu         $t9, 0x9($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X9);
    // 0x80411A40: sb          $t9, -0x21($s0)
    MEM_B(-0X21, ctx->r16) = ctx->r25;
    // 0x80411A44: lbu         $t2, 0x10($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X10);
    // 0x80411A48: sb          $t2, -0x4($s0)
    MEM_B(-0X4, ctx->r16) = ctx->r10;
    // 0x80411A4C: lbu         $t3, 0x11($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X11);
    // 0x80411A50: sb          $t3, -0x3($s0)
    MEM_B(-0X3, ctx->r16) = ctx->r11;
    // 0x80411A54: lbu         $t4, 0x12($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X12);
    // 0x80411A58: sb          $t4, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r12;
    // 0x80411A5C: lbu         $t5, 0x13($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X13);
    // 0x80411A60: sb          $t5, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r13;
    // 0x80411A64: lw          $t6, 0x39E8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X39E8);
    // 0x80411A68: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x80411A6C: bnel        $at, $zero, L_804119A8
    if (ctx->r1 != 0) {
        // 0x80411A70: lw          $t8, 0x39E8($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X39E8);
            goto L_804119A8;
    }
    goto skip_1;
    // 0x80411A70: lw          $t8, 0x39E8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X39E8);
    skip_1:
    // 0x80411A74: lw          $t7, 0x39E4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X39E4);
L_80411A78:
    // 0x80411A78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80411A7C: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x80411A80: bnel        $at, $zero, L_80411998
    if (ctx->r1 != 0) {
        // 0x80411A84: lw          $t7, 0x39E8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X39E8);
            goto L_80411998;
    }
    goto skip_2;
    // 0x80411A84: lw          $t7, 0x39E8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X39E8);
    skip_2:
L_80411A88:
    // 0x80411A88: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80411A8C: jr          $ra
    // 0x80411A90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80411A90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80411A94: nop

    // 0x80411A98: nop

    // 0x80411A9C: nop

;}
RECOMP_FUNC void ViMode_Configure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E47C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007E480: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8007E484: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8007E488: sltiu       $t0, $a3, 0x1
    ctx->r8 = ctx->r7 < 0X1 ? 1 : 0;
    // 0x8007E48C: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x8007E490: beq         $v0, $zero, L_8007E4A4
    if (ctx->r2 == 0) {
        // 0x8007E494: sltu        $a1, $zero, $a3
        ctx->r5 = 0 < ctx->r7 ? 1 : 0;
            goto L_8007E4A4;
    }
    // 0x8007E494: sltu        $a1, $zero, $a3
    ctx->r5 = 0 < ctx->r7 ? 1 : 0;
    // 0x8007E498: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8007E49C: sltiu       $v0, $v1, 0x1
    ctx->r2 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007E4A0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8007E4A4:
    // 0x8007E4A4: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x8007E4A8: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8007E4AC: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x8007E4B0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007E4B4: beq         $v0, $zero, L_8007E4C0
    if (ctx->r2 == 0) {
        // 0x8007E4B8: sltiu       $a2, $v1, 0x1
        ctx->r6 = ctx->r3 < 0X1 ? 1 : 0;
            goto L_8007E4C0;
    }
    // 0x8007E4B8: sltiu       $a2, $v1, 0x1
    ctx->r6 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x8007E4BC: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
L_8007E4C0:
    // 0x8007E4C0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8007E4C4: beq         $a1, $zero, L_8007E4D0
    if (ctx->r5 == 0) {
        // 0x8007E4C8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007E4D0;
    }
    // 0x8007E4C8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007E4CC: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
L_8007E4D0:
    // 0x8007E4D0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8007E4D4: beq         $a1, $zero, L_8007E4E0
    if (ctx->r5 == 0) {
        // 0x8007E4D8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007E4E0;
    }
    // 0x8007E4D8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007E4DC: sltu        $v0, $zero, $a2
    ctx->r2 = 0 < ctx->r6 ? 1 : 0;
L_8007E4E0:
    // 0x8007E4E0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8007E4E4: beq         $a1, $zero, L_8007E514
    if (ctx->r5 == 0) {
        // 0x8007E4E8: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8007E514;
    }
    // 0x8007E4E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007E4EC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8007E4F0: sltiu       $a3, $t3, 0x1
    ctx->r7 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8007E4F4: sltu        $v0, $zero, $a3
    ctx->r2 = 0 < ctx->r7 ? 1 : 0;
    // 0x8007E4F8: beql        $v0, $zero, L_8007E518
    if (ctx->r2 == 0) {
        // 0x8007E4FC: lw          $t5, 0x78($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X78);
            goto L_8007E518;
    }
    goto skip_0;
    // 0x8007E4FC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x8007E500: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8007E504: beq         $v0, $zero, L_8007E514
    if (ctx->r2 == 0) {
        // 0x8007E508: sw          $v0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r2;
            goto L_8007E514;
    }
    // 0x8007E508: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007E50C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8007E510: sltu        $v0, $zero, $t5
    ctx->r2 = 0 < ctx->r13 ? 1 : 0;
L_8007E514:
    // 0x8007E514: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
L_8007E518:
    // 0x8007E518: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8007E51C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8007E520: sltu        $t6, $zero, $t5
    ctx->r14 = 0 < ctx->r13 ? 1 : 0;
    // 0x8007E524: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8007E528: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8007E52C: beq         $a1, $zero, L_8007E554
    if (ctx->r5 == 0) {
        // 0x8007E530: sltiu       $t4, $t3, 0x1
        ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
            goto L_8007E554;
    }
    // 0x8007E530: sltiu       $t4, $t3, 0x1
    ctx->r12 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8007E534: sltu        $v0, $zero, $t3
    ctx->r2 = 0 < ctx->r11 ? 1 : 0;
    // 0x8007E538: beq         $v0, $zero, L_8007E554
    if (ctx->r2 == 0) {
        // 0x8007E53C: sw          $v0, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r2;
            goto L_8007E554;
    }
    // 0x8007E53C: sw          $v0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r2;
    // 0x8007E540: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8007E544: beq         $v0, $zero, L_8007E554
    if (ctx->r2 == 0) {
        // 0x8007E548: sw          $v0, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r2;
            goto L_8007E554;
    }
    // 0x8007E548: sw          $v0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r2;
    // 0x8007E54C: sltiu       $v0, $t5, 0x1
    ctx->r2 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8007E550: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_8007E554:
    // 0x8007E554: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8007E558: sltu        $v0, $zero, $t0
    ctx->r2 = 0 < ctx->r8 ? 1 : 0;
    // 0x8007E55C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x8007E560: beq         $v0, $zero, L_8007E584
    if (ctx->r2 == 0) {
        // 0x8007E564: sltiu       $a3, $t5, 0x1
        ctx->r7 = ctx->r13 < 0X1 ? 1 : 0;
            goto L_8007E584;
    }
    // 0x8007E564: sltiu       $a3, $t5, 0x1
    ctx->r7 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x8007E568: sltu        $v0, $zero, $t3
    ctx->r2 = 0 < ctx->r11 ? 1 : 0;
    // 0x8007E56C: beq         $v0, $zero, L_8007E584
    if (ctx->r2 == 0) {
        // 0x8007E570: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_8007E584;
    }
    // 0x8007E570: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007E574: sltu        $v0, $zero, $v1
    ctx->r2 = 0 < ctx->r3 ? 1 : 0;
    // 0x8007E578: beq         $v0, $zero, L_8007E584
    if (ctx->r2 == 0) {
        // 0x8007E57C: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_8007E584;
    }
    // 0x8007E57C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007E580: sltu        $v0, $zero, $a3
    ctx->r2 = 0 < ctx->r7 ? 1 : 0;
L_8007E584:
    // 0x8007E584: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8007E588: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8007E58C: addiu       $v1, $zero, -0x2
    ctx->r3 = ADD32(0, -0X2);
    // 0x8007E590: and         $t6, $t9, $v1
    ctx->r14 = ctx->r25 & ctx->r3;
    // 0x8007E594: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x8007E598: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8007E59C: sw          $t6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r14;
    // 0x8007E5A0: beq         $t2, $zero, L_8007E5B4
    if (ctx->r10 == 0) {
        // 0x8007E5A4: sw          $t8, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r24;
            goto L_8007E5B4;
    }
    // 0x8007E5A4: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x8007E5A8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8007E5AC: b           L_8007E5BC
    // 0x8007E5B0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8007E5BC;
    // 0x8007E5B0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8007E5B4:
    // 0x8007E5B4: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8007E5B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8007E5BC:
    // 0x8007E5BC: beq         $a1, $zero, L_8007E5CC
    if (ctx->r5 == 0) {
        // 0x8007E5C0: lw          $t9, 0x90($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X90);
            goto L_8007E5CC;
    }
    // 0x8007E5C0: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8007E5C4: b           L_8007E5D0
    // 0x8007E5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007E5D0;
    // 0x8007E5C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E5CC:
    // 0x8007E5CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007E5D0:
    // 0x8007E5D0: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x8007E5D4: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8007E5D8: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8007E5DC: addiu       $t8, $t7, 0x1E0
    ctx->r24 = ADD32(ctx->r15, 0X1E0);
    // 0x8007E5E0: sll         $t6, $t9, 11
    ctx->r14 = S32(ctx->r25 << 11);
    // 0x8007E5E4: div         $zero, $t6, $t8
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r24)));
    // 0x8007E5E8: mflo        $t7
    ctx->r15 = lo;
    // 0x8007E5EC: bne         $t8, $zero, L_8007E5F8
    if (ctx->r24 != 0) {
        // 0x8007E5F0: nop
    
            goto L_8007E5F8;
    }
    // 0x8007E5F0: nop

    // 0x8007E5F4: break       7
    do_break(2148001268);
L_8007E5F8:
    // 0x8007E5F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E5FC: bne         $t8, $at, L_8007E610
    if (ctx->r24 != ctx->r1) {
        // 0x8007E600: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E610;
    }
    // 0x8007E600: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E604: bne         $t6, $at, L_8007E610
    if (ctx->r14 != ctx->r1) {
        // 0x8007E608: nop
    
            goto L_8007E610;
    }
    // 0x8007E608: nop

    // 0x8007E60C: break       6
    do_break(2148001292);
L_8007E610:
    // 0x8007E610: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x8007E614: mflo        $t9
    ctx->r25 = lo;
    // 0x8007E618: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8007E61C: bne         $v0, $zero, L_8007E628
    if (ctx->r2 != 0) {
        // 0x8007E620: nop
    
            goto L_8007E628;
    }
    // 0x8007E620: nop

    // 0x8007E624: break       7
    do_break(2148001316);
L_8007E628:
    // 0x8007E628: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E62C: bne         $v0, $at, L_8007E640
    if (ctx->r2 != ctx->r1) {
        // 0x8007E630: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E640;
    }
    // 0x8007E630: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E634: bne         $t7, $at, L_8007E640
    if (ctx->r15 != ctx->r1) {
        // 0x8007E638: nop
    
            goto L_8007E640;
    }
    // 0x8007E638: nop

    // 0x8007E63C: break       6
    do_break(2148001340);
L_8007E640:
    // 0x8007E640: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E644: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E648: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8007E64C: beql        $a2, $zero, L_8007E670
    if (ctx->r6 == 0) {
        // 0x8007E650: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8007E670;
    }
    goto skip_1;
    // 0x8007E650: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    skip_1:
    // 0x8007E654: beq         $t1, $zero, L_8007E664
    if (ctx->r9 == 0) {
        // 0x8007E658: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8007E664;
    }
    // 0x8007E658: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8007E65C: b           L_8007E670
    // 0x8007E660: lui         $t2, 0x100
    ctx->r10 = S32(0X100 << 16);
        goto L_8007E670;
    // 0x8007E660: lui         $t2, 0x100
    ctx->r10 = S32(0X100 << 16);
L_8007E664:
    // 0x8007E664: b           L_8007E670
    // 0x8007E668: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_8007E670;
    // 0x8007E668: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8007E66C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007E670:
    // 0x8007E670: beql        $a2, $zero, L_8007E694
    if (ctx->r6 == 0) {
        // 0x8007E674: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8007E694;
    }
    goto skip_2;
    // 0x8007E674: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    skip_2:
    // 0x8007E678: beq         $t1, $zero, L_8007E688
    if (ctx->r9 == 0) {
        // 0x8007E67C: lui         $v0, 0x200
        ctx->r2 = S32(0X200 << 16);
            goto L_8007E688;
    }
    // 0x8007E67C: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8007E680: b           L_8007E694
    // 0x8007E684: lui         $t1, 0x300
    ctx->r9 = S32(0X300 << 16);
        goto L_8007E694;
    // 0x8007E684: lui         $t1, 0x300
    ctx->r9 = S32(0X300 << 16);
L_8007E688:
    // 0x8007E688: b           L_8007E694
    // 0x8007E68C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
        goto L_8007E694;
    // 0x8007E68C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8007E690: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8007E694:
    // 0x8007E694: beq         $t4, $zero, L_8007E6A4
    if (ctx->r12 == 0) {
        // 0x8007E698: sb          $t8, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r24;
            goto L_8007E6A4;
    }
    // 0x8007E698: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8007E69C: b           L_8007E6A8
    // 0x8007E6A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
        goto L_8007E6A8;
    // 0x8007E6A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8007E6A4:
    // 0x8007E6A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8007E6A8:
    // 0x8007E6A8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007E6AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007E6B0: bne         $t7, $zero, L_8007E6C0
    if (ctx->r15 != 0) {
        // 0x8007E6B4: nop
    
            goto L_8007E6C0;
    }
    // 0x8007E6B4: nop

    // 0x8007E6B8: b           L_8007E6C0
    // 0x8007E6BC: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
        goto L_8007E6C0;
    // 0x8007E6BC: addiu       $v1, $zero, 0x40
    ctx->r3 = ADD32(0, 0X40);
L_8007E6C0:
    // 0x8007E6C0: beq         $a3, $zero, L_8007E6D0
    if (ctx->r7 == 0) {
        // 0x8007E6C4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007E6D0;
    }
    // 0x8007E6C4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007E6C8: b           L_8007E6D0
    // 0x8007E6CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8007E6D0;
    // 0x8007E6CC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8007E6D0:
    // 0x8007E6D0: ori         $t9, $v0, 0x300C
    ctx->r25 = ctx->r2 | 0X300C;
    // 0x8007E6D4: or          $t6, $t9, $v1
    ctx->r14 = ctx->r25 | ctx->r3;
    // 0x8007E6D8: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E6DC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E6E0: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E6E4: ori         $t6, $t8, 0x100
    ctx->r14 = ctx->r24 | 0X100;
    // 0x8007E6E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007E6EC: beql        $t7, $zero, L_8007E700
    if (ctx->r15 == 0) {
        // 0x8007E6F0: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_8007E700;
    }
    goto skip_3;
    // 0x8007E6F0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    skip_3:
    // 0x8007E6F4: b           L_8007E73C
    // 0x8007E6F8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
        goto L_8007E73C;
    // 0x8007E6F8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007E6FC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_8007E700:
    // 0x8007E700: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8007E704: beq         $t7, $zero, L_8007E71C
    if (ctx->r15 == 0) {
        // 0x8007E708: nop
    
            goto L_8007E71C;
    }
    // 0x8007E708: nop

    // 0x8007E70C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8007E710: ori         $t6, $t9, 0x300
    ctx->r14 = ctx->r25 | 0X300;
    // 0x8007E714: b           L_8007E73C
    // 0x8007E718: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
        goto L_8007E73C;
    // 0x8007E718: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_8007E71C:
    // 0x8007E71C: beql        $t3, $zero, L_8007E738
    if (ctx->r11 == 0) {
        // 0x8007E720: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_8007E738;
    }
    goto skip_4;
    // 0x8007E720: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_4:
    // 0x8007E724: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8007E728: ori         $t7, $t8, 0x200
    ctx->r15 = ctx->r24 | 0X200;
    // 0x8007E72C: b           L_8007E73C
    // 0x8007E730: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
        goto L_8007E73C;
    // 0x8007E730: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E734: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_8007E738:
    // 0x8007E738: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
L_8007E73C:
    // 0x8007E73C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8007E740: lui         $t7, 0x3E5
    ctx->r15 = S32(0X3E5 << 16);
    // 0x8007E744: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8007E748: beq         $t6, $zero, L_8007E758
    if (ctx->r14 == 0) {
        // 0x8007E74C: ori         $t7, $t7, 0x2239
        ctx->r15 = ctx->r15 | 0X2239;
            goto L_8007E758;
    }
    // 0x8007E74C: ori         $t7, $t7, 0x2239
    ctx->r15 = ctx->r15 | 0X2239;
    // 0x8007E750: b           L_8007E758
    // 0x8007E754: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8007E758;
    // 0x8007E754: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007E758:
    // 0x8007E758: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E75C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E760: addiu       $t9, $zero, 0x20C
    ctx->r25 = ADD32(0, 0X20C);
    // 0x8007E764: addiu       $t6, $zero, 0xC15
    ctx->r14 = ADD32(0, 0XC15);
    // 0x8007E768: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007E76C: mflo        $t8
    ctx->r24 = lo;
    // 0x8007E770: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8007E774: bne         $t0, $at, L_8007E7B8
    if (ctx->r8 != ctx->r1) {
        // 0x8007E778: lui         $t8, 0xC15
        ctx->r24 = S32(0XC15 << 16);
            goto L_8007E7B8;
    }
    // 0x8007E778: lui         $t8, 0xC15
    ctx->r24 = S32(0XC15 << 16);
    // 0x8007E77C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8007E780: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8007E784: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x8007E788: lui         $t7, 0x6C
    ctx->r15 = S32(0X6C << 16);
    // 0x8007E78C: lui         $t9, 0x25
    ctx->r25 = S32(0X25 << 16);
    // 0x8007E790: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x8007E794: ori         $t8, $t8, 0xC15
    ctx->r24 = ctx->r24 | 0XC15;
    // 0x8007E798: ori         $t7, $t7, 0x2EC
    ctx->r15 = ctx->r15 | 0X2EC;
    // 0x8007E79C: ori         $t9, $t9, 0x1FF
    ctx->r25 = ctx->r25 | 0X1FF;
    // 0x8007E7A0: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x8007E7A4: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x8007E7A8: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x8007E7AC: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x8007E7B0: b           L_8007E868
    // 0x8007E7B4: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
        goto L_8007E868;
    // 0x8007E7B4: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
L_8007E7B8:
    // 0x8007E7B8: bne         $t0, $zero, L_8007E818
    if (ctx->r8 != 0) {
        // 0x8007E7BC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007E818;
    }
    // 0x8007E7BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007E7C0: lui         $t8, 0x404
    ctx->r24 = S32(0X404 << 16);
    // 0x8007E7C4: lui         $t9, 0x15
    ctx->r25 = S32(0X15 << 16);
    // 0x8007E7C8: ori         $t8, $t8, 0x233A
    ctx->r24 = ctx->r24 | 0X233A;
    // 0x8007E7CC: addiu       $t7, $zero, 0x270
    ctx->r15 = ADD32(0, 0X270);
    // 0x8007E7D0: ori         $t9, $t9, 0xC69
    ctx->r25 = ctx->r25 | 0XC69;
    // 0x8007E7D4: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x8007E7D8: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x8007E7DC: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8007E7E0: lui         $t6, 0xC6F
    ctx->r14 = S32(0XC6F << 16);
    // 0x8007E7E4: lui         $t8, 0x80
    ctx->r24 = S32(0X80 << 16);
    // 0x8007E7E8: lui         $t7, 0x5F
    ctx->r15 = S32(0X5F << 16);
    // 0x8007E7EC: lui         $t9, 0x9
    ctx->r25 = S32(0X9 << 16);
    // 0x8007E7F0: ori         $t6, $t6, 0xC6E
    ctx->r14 = ctx->r14 | 0XC6E;
    // 0x8007E7F4: ori         $t8, $t8, 0x300
    ctx->r24 = ctx->r24 | 0X300;
    // 0x8007E7F8: ori         $t7, $t7, 0x239
    ctx->r15 = ctx->r15 | 0X239;
    // 0x8007E7FC: ori         $t9, $t9, 0x26B
    ctx->r25 = ctx->r25 | 0X26B;
    // 0x8007E800: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8007E804: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8007E808: sw          $t7, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r15;
    // 0x8007E80C: sw          $t9, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r25;
    // 0x8007E810: b           L_8007E868
    // 0x8007E814: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8007E868;
    // 0x8007E814: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007E818:
    // 0x8007E818: bne         $t0, $v0, L_8007E868
    if (ctx->r8 != ctx->r2) {
        // 0x8007E81C: lui         $t6, 0x465
        ctx->r14 = S32(0X465 << 16);
            goto L_8007E868;
    }
    // 0x8007E81C: lui         $t6, 0x465
    ctx->r14 = S32(0X465 << 16);
    // 0x8007E820: ori         $t6, $t6, 0x1E39
    ctx->r14 = ctx->r14 | 0X1E39;
    // 0x8007E824: addiu       $t8, $zero, 0x20C
    ctx->r24 = ADD32(0, 0X20C);
    // 0x8007E828: addiu       $t7, $zero, 0xC10
    ctx->r15 = ADD32(0, 0XC10);
    // 0x8007E82C: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x8007E830: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8007E834: sw          $t7, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r15;
    // 0x8007E838: lui         $t9, 0xC1C
    ctx->r25 = S32(0XC1C << 16);
    // 0x8007E83C: lui         $t6, 0x6C
    ctx->r14 = S32(0X6C << 16);
    // 0x8007E840: lui         $t8, 0x25
    ctx->r24 = S32(0X25 << 16);
    // 0x8007E844: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x8007E848: ori         $t9, $t9, 0xC1C
    ctx->r25 = ctx->r25 | 0XC1C;
    // 0x8007E84C: ori         $t6, $t6, 0x2EC
    ctx->r14 = ctx->r14 | 0X2EC;
    // 0x8007E850: ori         $t8, $t8, 0x1FF
    ctx->r24 = ctx->r24 | 0X1FF;
    // 0x8007E854: ori         $t7, $t7, 0x204
    ctx->r15 = ctx->r15 | 0X204;
    // 0x8007E858: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x8007E85C: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x8007E860: sw          $t8, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r24;
    // 0x8007E864: sw          $t7, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r15;
L_8007E868:
    // 0x8007E868: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8007E86C: lw          $a3, 0x84($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X84);
    // 0x8007E870: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x8007E874: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x8007E878: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8007E87C: lw          $t6, 0x1C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C);
    // 0x8007E880: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x8007E884: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8007E888: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E88C: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x8007E890: sw          $v1, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r3;
    // 0x8007E894: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x8007E898: lh          $t7, 0x92($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X92);
    // 0x8007E89C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8007E8A0: addu        $t4, $t6, $t7
    ctx->r12 = ADD32(ctx->r14, ctx->r15);
    // 0x8007E8A4: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x8007E8A8: addu        $t9, $v1, $t4
    ctx->r25 = ADD32(ctx->r3, ctx->r12);
    // 0x8007E8AC: addu        $t6, $v1, $t4
    ctx->r14 = ADD32(ctx->r3, ctx->r12);
    // 0x8007E8B0: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x8007E8B4: sw          $t6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r14;
    // 0x8007E8B8: sw          $t7, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r15;
    // 0x8007E8BC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8007E8C0: beql        $t9, $zero, L_8007E910
    if (ctx->r25 == 0) {
        // 0x8007E8C4: lw          $t7, 0x30($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X30);
            goto L_8007E910;
    }
    goto skip_5;
    // 0x8007E8C4: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
    skip_5:
    // 0x8007E8C8: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8007E8CC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x8007E8D0: bne         $t0, $v0, L_8007E8EC
    if (ctx->r8 != ctx->r2) {
        // 0x8007E8D4: sw          $t6, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r14;
            goto L_8007E8EC;
    }
    // 0x8007E8D4: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x8007E8D8: lw          $t7, 0x14($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14);
    // 0x8007E8DC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x8007E8E0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8007E8E4: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x8007E8E8: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
L_8007E8EC:
    // 0x8007E8EC: bnel        $t0, $v0, L_8007E958
    if (ctx->r8 != ctx->r2) {
        // 0x8007E8F0: subu        $t6, $t3, $a3
        ctx->r14 = SUB32(ctx->r11, ctx->r7);
            goto L_8007E958;
    }
    goto skip_6;
    // 0x8007E8F0: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
    skip_6:
    // 0x8007E8F4: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8007E8F8: lui         $at, 0xFFFC
    ctx->r1 = S32(0XFFFC << 16);
    // 0x8007E8FC: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8007E900: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x8007E904: b           L_8007E954
    // 0x8007E908: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
        goto L_8007E954;
    // 0x8007E908: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x8007E90C: lw          $t7, 0x30($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X30);
L_8007E910:
    // 0x8007E910: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x8007E914: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8007E918: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x8007E91C: bne         $t0, $v0, L_8007E938
    if (ctx->r8 != ctx->r2) {
        // 0x8007E920: sw          $t9, 0x30($a0)
        MEM_W(0X30, ctx->r4) = ctx->r25;
            goto L_8007E938;
    }
    // 0x8007E920: sw          $t9, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r25;
    // 0x8007E924: lw          $t8, 0x34($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X34);
    // 0x8007E928: lui         $at, 0xFFFC
    ctx->r1 = S32(0XFFFC << 16);
    // 0x8007E92C: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8007E930: addu        $t6, $t8, $at
    ctx->r14 = ADD32(ctx->r24, ctx->r1);
    // 0x8007E934: sw          $t6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r14;
L_8007E938:
    // 0x8007E938: bnel        $t0, $zero, L_8007E958
    if (ctx->r8 != 0) {
        // 0x8007E93C: subu        $t6, $t3, $a3
        ctx->r14 = SUB32(ctx->r11, ctx->r7);
            goto L_8007E958;
    }
    goto skip_7;
    // 0x8007E93C: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
    skip_7:
    // 0x8007E940: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x8007E944: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8007E948: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x8007E94C: addu        $t9, $t7, $at
    ctx->r25 = ADD32(ctx->r15, ctx->r1);
    // 0x8007E950: sw          $t9, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r25;
L_8007E954:
    // 0x8007E954: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
L_8007E958:
    // 0x8007E958: addiu       $t7, $t6, 0x280
    ctx->r15 = ADD32(ctx->r14, 0X280);
    // 0x8007E95C: sll         $t8, $a2, 10
    ctx->r24 = S32(ctx->r6 << 10);
    // 0x8007E960: div         $zero, $t8, $t7
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r15)));
    // 0x8007E964: lw          $v1, 0x4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4);
    // 0x8007E968: bne         $t7, $zero, L_8007E974
    if (ctx->r15 != 0) {
        // 0x8007E96C: nop
    
            goto L_8007E974;
    }
    // 0x8007E96C: nop

    // 0x8007E970: break       7
    do_break(2148002160);
L_8007E974:
    // 0x8007E974: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E978: bne         $t7, $at, L_8007E98C
    if (ctx->r15 != ctx->r1) {
        // 0x8007E97C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E98C;
    }
    // 0x8007E97C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E980: bne         $t8, $at, L_8007E98C
    if (ctx->r24 != ctx->r1) {
        // 0x8007E984: nop
    
            goto L_8007E98C;
    }
    // 0x8007E984: nop

    // 0x8007E988: break       6
    do_break(2148002184);
L_8007E98C:
    // 0x8007E98C: mflo        $t9
    ctx->r25 = lo;
    // 0x8007E990: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8007E994: beq         $v1, $zero, L_8007E9A4
    if (ctx->r3 == 0) {
        // 0x8007E998: sw          $zero, 0x24($a0)
        MEM_W(0X24, ctx->r4) = 0;
            goto L_8007E9A4;
    }
    // 0x8007E998: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8007E99C: b           L_8007E9A8
    // 0x8007E9A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007E9A8;
    // 0x8007E9A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E9A4:
    // 0x8007E9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007E9A8:
    // 0x8007E9A8: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007E9B0: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E9B4: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8007E9B8: beq         $v1, $zero, L_8007E9C8
    if (ctx->r3 == 0) {
        // 0x8007E9BC: sw          $t8, 0x28($a0)
        MEM_W(0X28, ctx->r4) = ctx->r24;
            goto L_8007E9C8;
    }
    // 0x8007E9BC: sw          $t8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r24;
    // 0x8007E9C0: b           L_8007E9CC
    // 0x8007E9C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8007E9CC;
    // 0x8007E9C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8007E9C8:
    // 0x8007E9C8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8007E9CC:
    // 0x8007E9CC: beq         $a1, $zero, L_8007E9DC
    if (ctx->r5 == 0) {
        // 0x8007E9D0: nop
    
            goto L_8007E9DC;
    }
    // 0x8007E9D0: nop

    // 0x8007E9D4: b           L_8007E9DC
    // 0x8007E9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007E9DC;
    // 0x8007E9D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007E9DC:
    // 0x8007E9DC: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007E9E4: mflo        $t7
    ctx->r15 = lo;
    // 0x8007E9E8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8007E9EC: nop

    // 0x8007E9F0: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9F4: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E9F8: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x8007E9FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA00: or          $t7, $t8, $t2
    ctx->r15 = ctx->r24 | ctx->r10;
    // 0x8007EA04: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8007EA08: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007EA0C: sw          $a1, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r5;
    // 0x8007EA10: sw          $a1, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->r5;
    // 0x8007EA14: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x8007EA18: sw          $t6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r14;
    // 0x8007EA1C: jr          $ra
    // 0x8007EA20: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8007EA20: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80002B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002B94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002B98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80002B9C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80002BA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002BA4: lbu         $t0, 0x6($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X6);
    // 0x80002BA8: sll         $t7, $t6, 11
    ctx->r15 = S32(ctx->r14 << 11);
    // 0x80002BAC: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x80002BB0: beq         $t8, $zero, L_80002C0C
    if (ctx->r24 == 0) {
        // 0x80002BB4: lw          $v1, 0x8($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X8);
            goto L_80002C0C;
    }
    // 0x80002BB4: lw          $v1, 0x8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X8);
    // 0x80002BB8: sll         $a2, $a3, 1
    ctx->r6 = S32(ctx->r7 << 1);
    // 0x80002BBC: addiu       $a2, $a2, 0xF
    ctx->r6 = ADD32(ctx->r6, 0XF);
    // 0x80002BC0: lui         $a3, 0x8009
    ctx->r7 = S32(0X8009 << 16);
    // 0x80002BC4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80002BC8: lw          $a3, 0x61D0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X61D0);
    // 0x80002BCC: and         $a2, $a2, $at
    ctx->r6 = ctx->r6 & ctx->r1;
    // 0x80002BD0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002BD8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80002BDC: addiu       $a1, $zero, 0x580
    ctx->r5 = ADD32(0, 0X580);
    // 0x80002BE0: jal         0x800010C4
    // 0x80002BE4: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    func_800010C4(rdram, ctx);
        goto after_0;
    // 0x80002BE4: addu        $a3, $a3, $at
    ctx->r7 = ADD32(ctx->r7, ctx->r1);
    after_0:
    // 0x80002BE8: lui         $v1, 0x8009
    ctx->r3 = S32(0X8009 << 16);
    // 0x80002BEC: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80002BF0: addiu       $v1, $v1, 0x61B0
    ctx->r3 = ADD32(ctx->r3, 0X61B0);
    // 0x80002BF4: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80002BF8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80002BFC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80002C00: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x80002C04: b           L_80002CF8
    // 0x80002C08: sw          $t3, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r11;
        goto L_80002CF8;
    // 0x80002C08: sw          $t3, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r11;
L_80002C0C:
    // 0x80002C0C: lui         $t4, 0x1408
    ctx->r12 = S32(0X1408 << 16);
    // 0x80002C10: ori         $t4, $t4, 0x580
    ctx->r12 = ctx->r12 | 0X580;
    // 0x80002C14: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80002C18: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80002C1C: lw          $t5, 0x10($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X10);
    // 0x80002C20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002C24: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80002C28: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80002C2C: beq         $t0, $zero, L_80002C90
    if (ctx->r8 == 0) {
        // 0x80002C30: sw          $t6, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r14;
            goto L_80002C90;
    }
    // 0x80002C30: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80002C34: lui         $v0, 0x8009
    ctx->r2 = S32(0X8009 << 16);
    // 0x80002C38: addiu       $v0, $v0, 0x7788
    ctx->r2 = ADD32(ctx->r2, 0X7788);
    // 0x80002C3C: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x80002C40: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80002C44: lbu         $t1, 0x0($t8)
    ctx->r9 = MEM_BU(ctx->r24, 0X0);
    // 0x80002C48: andi        $t2, $t0, 0x3
    ctx->r10 = ctx->r8 & 0X3;
    // 0x80002C4C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80002C50: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002C54: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80002C58: mflo        $t9
    ctx->r25 = lo;
    // 0x80002C5C: nop

    // 0x80002C60: nop

    // 0x80002C64: div         $zero, $t9, $t4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r12)));
    // 0x80002C68: mflo        $v1
    ctx->r3 = lo;
    // 0x80002C6C: bne         $t4, $zero, L_80002C78
    if (ctx->r12 != 0) {
        // 0x80002C70: nop
    
            goto L_80002C78;
    }
    // 0x80002C70: nop

    // 0x80002C74: break       7
    do_break(2147495028);
L_80002C78:
    // 0x80002C78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002C7C: bne         $t4, $at, L_80002C90
    if (ctx->r12 != ctx->r1) {
        // 0x80002C80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80002C90;
    }
    // 0x80002C80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80002C84: bne         $t9, $at, L_80002C90
    if (ctx->r25 != ctx->r1) {
        // 0x80002C88: nop
    
            goto L_80002C90;
    }
    // 0x80002C88: nop

    // 0x80002C8C: break       6
    do_break(2147495052);
L_80002C90:
    // 0x80002C90: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80002C94: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80002C98: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80002C9C: subu        $v0, $t5, $v1
    ctx->r2 = SUB32(ctx->r13, ctx->r3);
    // 0x80002CA0: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80002CA4: beq         $at, $zero, L_80002CF0
    if (ctx->r1 == 0) {
        // 0x80002CA8: subu        $a0, $t6, $v0
        ctx->r4 = SUB32(ctx->r14, ctx->r2);
            goto L_80002CF0;
    }
    // 0x80002CA8: subu        $a0, $t6, $v0
    ctx->r4 = SUB32(ctx->r14, ctx->r2);
    // 0x80002CAC: addiu       $a0, $a0, 0x3F
    ctx->r4 = ADD32(ctx->r4, 0X3F);
    // 0x80002CB0: bgez        $a0, L_80002CBC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80002CB4: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_80002CBC;
    }
    // 0x80002CB4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80002CB8: addiu       $at, $a0, 0x3F
    ctx->r1 = ADD32(ctx->r4, 0X3F);
L_80002CBC:
    // 0x80002CBC: sra         $a0, $at, 6
    ctx->r4 = S32(SIGNED(ctx->r1) >> 6);
    // 0x80002CC0: beq         $a0, $zero, L_80002CF0
    if (ctx->r4 == 0) {
        // 0x80002CC4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80002CF0;
    }
    // 0x80002CC4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80002CC8: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x80002CCC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80002CD0: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x80002CD4: or          $t1, $t8, $at
    ctx->r9 = ctx->r24 | ctx->r1;
    // 0x80002CD8: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80002CDC: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x80002CE0: ori         $t2, $t1, 0x580
    ctx->r10 = ctx->r9 | 0X580;
    // 0x80002CE4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80002CE8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80002CEC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80002CF0:
    // 0x80002CF0: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x80002CF4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80002CF8:
    // 0x80002CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002CFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80002D00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002D04: jr          $ra
    // 0x80002D08: nop

    return;
    // 0x80002D08: nop

;}
RECOMP_FUNC void func_805197A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805197A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805197A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805197AC: jal         0x80519170
    // 0x805197B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80519170(rdram, ctx);
        goto after_0;
    // 0x805197B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805197B4: jal         0x80519340
    // 0x805197B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80519340(rdram, ctx);
        goto after_1;
    // 0x805197B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805197BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805197C0: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x805197C4: bnel        $t6, $zero, L_805197E4
    if (ctx->r14 != 0) {
        // 0x805197C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805197E4;
    }
    goto skip_0;
    // 0x805197C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805197CC: jal         0x800447C8
    // 0x805197D0: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x805197D0: nop

    after_2:
    // 0x805197D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805197D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805197DC: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x805197E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805197E4:
    // 0x805197E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805197E8: jr          $ra
    // 0x805197EC: nop

    return;
    // 0x805197EC: nop

;}
RECOMP_FUNC void func_80790A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790A58: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80790A5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790A60: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80790A64: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80790A68: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80790A6C: jal         0x8004700C
    // 0x80790A70: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790A70: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80790A74: beq         $v0, $zero, L_80790A8C
    if (ctx->r2 == 0) {
        // 0x80790A78: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80790A8C;
    }
    // 0x80790A78: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80790A7C: jal         0x80047AB8
    // 0x80790A80: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x80790A80: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_1:
    // 0x80790A84: b           L_80790AA0
    // 0x80790A88: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_80790AA0;
    // 0x80790A88: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80790A8C:
    // 0x80790A8C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80790A90: nop

    // 0x80790A94: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80790A98: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80790A9C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_80790AA0:
    // 0x80790AA0: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x80790AA4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80790AA8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80790AAC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80790AB0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80790AB4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80790AB8: beq         $t6, $zero, L_80790AC4
    if (ctx->r14 == 0) {
        // 0x80790ABC: sub.s       $f14, $f8, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
            goto L_80790AC4;
    }
    // 0x80790ABC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80790AC0: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_80790AC4:
    // 0x80790AC4: jal         0x80067114
    // 0x80790AC8: nop

    func_80067114(rdram, ctx);
        goto after_2;
    // 0x80790AC8: nop

    after_2:
    // 0x80790ACC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80790AD0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80790AD4: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x80790AD8: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80790ADC: nop

    // 0x80790AE0: bc1fl       L_80790B0C
    if (!c1cs) {
        // 0x80790AE4: c.le.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
            goto L_80790B0C;
    }
    goto skip_0;
    // 0x80790AE4: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    skip_0:
    // 0x80790AE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80790AEC: nop

    // 0x80790AF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80790AF4: nop

    // 0x80790AF8: bc1fl       L_80790B0C
    if (!c1cs) {
        // 0x80790AFC: c.le.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
            goto L_80790B0C;
    }
    goto skip_1;
    // 0x80790AFC: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    skip_1:
    // 0x80790B00: b           L_80790B34
    // 0x80790B04: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
        goto L_80790B34;
    // 0x80790B04: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80790B08: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
L_80790B0C:
    // 0x80790B0C: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80790B10: bc1f        L_80790B34
    if (!c1cs) {
        // 0x80790B14: nop
    
            goto L_80790B34;
    }
    // 0x80790B14: nop

    // 0x80790B18: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80790B1C: nop

    // 0x80790B20: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80790B24: nop

    // 0x80790B28: bc1f        L_80790B34
    if (!c1cs) {
        // 0x80790B2C: nop
    
            goto L_80790B34;
    }
    // 0x80790B2C: nop

    // 0x80790B30: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80790B34:
    // 0x80790B34: jal         0x800653D8
    // 0x80790B38: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80790B38: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80790B3C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80790B40: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80790B44: mfhi        $t7
    ctx->r15 = hi;
    // 0x80790B48: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80790B4C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7A9C) << 16);
    // 0x80790B50: lwc1        $f4, 0x7DEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7A9C));
    // 0x80790B54: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80790B58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80790B5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80790B60: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80790B64: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80790B68: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80790B6C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80790B70: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80790B74: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x80790B78: jal         0x80066E88
    // 0x80790B7C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x80790B7C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80790B80: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80790B84: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80790B88: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80790B8C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80790B90: jal         0x80066DE4
    // 0x80790B94: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80790B94: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    after_5:
    // 0x80790B98: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80790B9C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80790BA0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80790BA4: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80790BA8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80790BAC: beql        $t9, $zero, L_80790BC4
    if (ctx->r25 == 0) {
        // 0x80790BB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80790BC4;
    }
    goto skip_2;
    // 0x80790BB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80790BB4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80790BB8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80790BBC: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80790BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80790BC4:
    // 0x80790BC4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80790BC8: jr          $ra
    // 0x80790BCC: nop

    return;
    // 0x80790BCC: nop

;}
RECOMP_FUNC void func_80710860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80710860: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80710864: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80710868: lw          $v0, 0xF54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XF54);
    // 0x8071086C: lw          $t6, 0xCD0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XCD0);
    // 0x80710870: lw          $t7, 0xCD4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XCD4);
    // 0x80710874: lw          $t8, 0xCD8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XCD8);
    // 0x80710878: lw          $t9, 0xCDC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XCDC);
    // 0x8071087C: lw          $t0, 0xCE0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XCE0);
    // 0x80710880: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80710884: sb          $zero, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = 0;
    // 0x80710888: sh          $t6, 0x13A8($v1)
    MEM_H(0X13A8, ctx->r3) = ctx->r14;
    // 0x8071088C: sh          $t7, 0x13AA($v1)
    MEM_H(0X13AA, ctx->r3) = ctx->r15;
    // 0x80710890: sh          $t8, 0x13AC($v1)
    MEM_H(0X13AC, ctx->r3) = ctx->r24;
    // 0x80710894: sh          $t9, 0x13AE($v1)
    MEM_H(0X13AE, ctx->r3) = ctx->r25;
    // 0x80710898: beq         $t1, $zero, L_807108A8
    if (ctx->r9 == 0) {
        // 0x8071089C: sh          $t0, 0x13B0($v1)
        MEM_H(0X13B0, ctx->r3) = ctx->r8;
            goto L_807108A8;
    }
    // 0x8071089C: sh          $t0, 0x13B0($v1)
    MEM_H(0X13B0, ctx->r3) = ctx->r8;
    // 0x807108A0: ori         $t4, $zero, 0x4
    ctx->r12 = 0 | 0X4;
    // 0x807108A4: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
L_807108A8:
    // 0x807108A8: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x807108AC: beq         $t5, $zero, L_807108C0
    if (ctx->r13 == 0) {
        // 0x807108B0: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_807108C0;
    }
    // 0x807108B0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x807108B4: lbu         $t7, 0x13B2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B2);
    // 0x807108B8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x807108BC: sb          $t8, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r24;
L_807108C0:
    // 0x807108C0: beq         $t9, $zero, L_807108D4
    if (ctx->r25 == 0) {
        // 0x807108C4: andi        $t3, $v0, 0x8
        ctx->r11 = ctx->r2 & 0X8;
            goto L_807108D4;
    }
    // 0x807108C4: andi        $t3, $v0, 0x8
    ctx->r11 = ctx->r2 & 0X8;
    // 0x807108C8: lbu         $t1, 0x13B2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13B2);
    // 0x807108CC: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x807108D0: sb          $t2, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r10;
L_807108D4:
    // 0x807108D4: beq         $t3, $zero, L_807108E8
    if (ctx->r11 == 0) {
        // 0x807108D8: andi        $t7, $v0, 0x10
        ctx->r15 = ctx->r2 & 0X10;
            goto L_807108E8;
    }
    // 0x807108D8: andi        $t7, $v0, 0x10
    ctx->r15 = ctx->r2 & 0X10;
    // 0x807108DC: lbu         $t5, 0x13B2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B2);
    // 0x807108E0: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x807108E4: sb          $t6, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r14;
L_807108E8:
    // 0x807108E8: beq         $t7, $zero, L_807108FC
    if (ctx->r15 == 0) {
        // 0x807108EC: andi        $t1, $v0, 0x20
        ctx->r9 = ctx->r2 & 0X20;
            goto L_807108FC;
    }
    // 0x807108EC: andi        $t1, $v0, 0x20
    ctx->r9 = ctx->r2 & 0X20;
    // 0x807108F0: lbu         $t9, 0x13B2($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X13B2);
    // 0x807108F4: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x807108F8: sb          $t0, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r8;
L_807108FC:
    // 0x807108FC: beq         $t1, $zero, L_80710910
    if (ctx->r9 == 0) {
        // 0x80710900: andi        $t5, $v0, 0x40
        ctx->r13 = ctx->r2 & 0X40;
            goto L_80710910;
    }
    // 0x80710900: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x80710904: lbu         $t3, 0x13B2($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X13B2);
    // 0x80710908: ori         $t4, $t3, 0x8
    ctx->r12 = ctx->r11 | 0X8;
    // 0x8071090C: sb          $t4, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r12;
L_80710910:
    // 0x80710910: beq         $t5, $zero, L_80710924
    if (ctx->r13 == 0) {
        // 0x80710914: andi        $t9, $v0, 0x80
        ctx->r25 = ctx->r2 & 0X80;
            goto L_80710924;
    }
    // 0x80710914: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x80710918: lbu         $t7, 0x13B2($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B2);
    // 0x8071091C: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x80710920: sb          $t8, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r24;
L_80710924:
    // 0x80710924: beq         $t9, $zero, L_80710938
    if (ctx->r25 == 0) {
        // 0x80710928: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80710938;
    }
    // 0x80710928: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8071092C: lbu         $t1, 0x13B2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X13B2);
    // 0x80710930: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80710934: sb          $t2, 0x13B2($v1)
    MEM_B(0X13B2, ctx->r3) = ctx->r10;
L_80710938:
    // 0x80710938: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x8071093C: lbu         $t8, 0x13B4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X13B4);
    // 0x80710940: and         $t3, $v0, $at
    ctx->r11 = ctx->r2 & ctx->r1;
    // 0x80710944: srl         $t5, $t3, 14
    ctx->r13 = S32(U32(ctx->r11) >> 14);
    // 0x80710948: lw          $t2, 0xCC0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XCC0);
    // 0x8071094C: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x80710950: lbu         $t5, 0x13B3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B3);
    // 0x80710954: andi        $t9, $t8, 0xFF1F
    ctx->r25 = ctx->r24 & 0XFF1F;
    // 0x80710958: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8071095C: lw          $t9, 0xAA0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAA0);
    // 0x80710960: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80710964: lbu         $t7, 0x13B5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80710968: andi        $t4, $t3, 0x30
    ctx->r12 = ctx->r11 & 0X30;
    // 0x8071096C: andi        $t6, $t5, 0xFFCF
    ctx->r14 = ctx->r13 & 0XFFCF;
    // 0x80710970: or          $t2, $t4, $t6
    ctx->r10 = ctx->r12 | ctx->r14;
    // 0x80710974: addiu       $t6, $a0, 0x1
    ctx->r14 = ADD32(ctx->r4, 0X1);
    // 0x80710978: sll         $t1, $t9, 6
    ctx->r9 = S32(ctx->r25 << 6);
    // 0x8071097C: sb          $t0, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r8;
    // 0x80710980: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x80710984: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x80710988: andi        $t9, $t7, 0xFFF8
    ctx->r25 = ctx->r15 & 0XFFF8;
    // 0x8071098C: sb          $t2, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r10;
    // 0x80710990: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80710994: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80710998: sltiu       $at, $a0, 0x5
    ctx->r1 = ctx->r4 < 0X5 ? 1 : 0;
    // 0x8071099C: sb          $t5, 0x13B3($v1)
    MEM_B(0X13B3, ctx->r3) = ctx->r13;
    // 0x807109A0: beq         $at, $zero, L_80710A5C
    if (ctx->r1 == 0) {
        // 0x807109A4: sb          $t0, 0x13B5($v1)
        MEM_B(0X13B5, ctx->r3) = ctx->r8;
            goto L_80710A5C;
    }
    // 0x807109A4: sb          $t0, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r8;
    // 0x807109A8: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x807109AC: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X193C) << 16);
    // 0x807109B0: addu        $at, $at, $t2
    gpr jr_addend_807109B8 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x807109B4: lw          $t2, 0xD2C($at)
    ctx->r10 = ADD32(ctx->r1, (int16_t)RELOC_LO16(724, 0X193C));
    // 0x807109B8: jr          $t2
    // 0x807109BC: nop

    switch (jr_addend_807109B8 >> 2) {
        case 0: goto L_807109C0; break;
        case 1: goto L_807109E0; break;
        case 2: goto L_80710A00; break;
        case 3: goto L_80710A20; break;
        case 4: goto L_80710A40; break;
        default: switch_error(__func__, 0x807109B8, 0x80710D2C);
    }
    // 0x807109BC: nop

L_807109C0:
    // 0x807109C0: lbu         $t3, 0xF5D($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XF5D);
    // 0x807109C4: lbu         $t6, 0x13B4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13B4);
    // 0x807109C8: sll         $t5, $t3, 3
    ctx->r13 = S32(ctx->r11 << 3);
    // 0x807109CC: andi        $t4, $t5, 0x18
    ctx->r12 = ctx->r13 & 0X18;
    // 0x807109D0: andi        $t7, $t6, 0xFFE7
    ctx->r15 = ctx->r14 & 0XFFE7;
    // 0x807109D4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x807109D8: jr          $ra
    // 0x807109DC: sb          $t8, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r24;
    return;
    // 0x807109DC: sb          $t8, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r24;
L_807109E0:
    // 0x807109E0: lbu         $t0, 0xF5D($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0XF5D);
    // 0x807109E4: lbu         $t3, 0x13B4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X13B4);
    // 0x807109E8: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x807109EC: andi        $t1, $t2, 0x6
    ctx->r9 = ctx->r10 & 0X6;
    // 0x807109F0: andi        $t5, $t3, 0xFFF9
    ctx->r13 = ctx->r11 & 0XFFF9;
    // 0x807109F4: or          $t6, $t1, $t5
    ctx->r14 = ctx->r9 | ctx->r13;
    // 0x807109F8: jr          $ra
    // 0x807109FC: sb          $t6, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r14;
    return;
    // 0x807109FC: sb          $t6, 0x13B4($v1)
    MEM_B(0X13B4, ctx->r3) = ctx->r14;
L_80710A00:
    // 0x80710A00: lbu         $t7, 0xF5D($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80710A04: lhu         $t0, 0x13B4($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X13B4);
    // 0x80710A08: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80710A0C: andi        $t9, $t8, 0x180
    ctx->r25 = ctx->r24 & 0X180;
    // 0x80710A10: andi        $t2, $t0, 0xFE7F
    ctx->r10 = ctx->r8 & 0XFE7F;
    // 0x80710A14: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80710A18: jr          $ra
    // 0x80710A1C: sh          $t3, 0x13B4($v1)
    MEM_H(0X13B4, ctx->r3) = ctx->r11;
    return;
    // 0x80710A1C: sh          $t3, 0x13B4($v1)
    MEM_H(0X13B4, ctx->r3) = ctx->r11;
L_80710A20:
    // 0x80710A20: lbu         $t5, 0xF5D($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80710A24: lbu         $t7, 0x13B5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80710A28: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x80710A2C: andi        $t4, $t6, 0x60
    ctx->r12 = ctx->r14 & 0X60;
    // 0x80710A30: andi        $t8, $t7, 0xFF9F
    ctx->r24 = ctx->r15 & 0XFF9F;
    // 0x80710A34: or          $t0, $t4, $t8
    ctx->r8 = ctx->r12 | ctx->r24;
    // 0x80710A38: jr          $ra
    // 0x80710A3C: sb          $t0, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r8;
    return;
    // 0x80710A3C: sb          $t0, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r8;
L_80710A40:
    // 0x80710A40: lbu         $t2, 0xF5D($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80710A44: lbu         $t5, 0x13B5($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X13B5);
    // 0x80710A48: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x80710A4C: andi        $t1, $t3, 0x18
    ctx->r9 = ctx->r11 & 0X18;
    // 0x80710A50: andi        $t6, $t5, 0xFFE7
    ctx->r14 = ctx->r13 & 0XFFE7;
    // 0x80710A54: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x80710A58: sb          $t7, 0x13B5($v1)
    MEM_B(0X13B5, ctx->r3) = ctx->r15;
L_80710A5C:
    // 0x80710A5C: jr          $ra
    // 0x80710A60: nop

    return;
    // 0x80710A60: nop

;}
RECOMP_FUNC void func_8044D394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D394: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044D398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D39C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8044D3A0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8044D3A4: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8044D3A8: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x8044D3AC: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044D3B0: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044D3B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044D3B8: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x8044D3BC: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    // 0x8044D3C0: beq         $t7, $zero, L_8044D400
    if (ctx->r15 == 0) {
        // 0x8044D3C4: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8044D400;
    }
    // 0x8044D3C4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8044D3C8: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8044D3CC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8044D3D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8044D3D4: sll         $t1, $t0, 6
    ctx->r9 = S32(ctx->r8 << 6);
    // 0x8044D3D8: addu        $a1, $t1, $a1
    ctx->r5 = ADD32(ctx->r9, ctx->r5);
    // 0x8044D3DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8044D3E0: jal         0x8044D1F4
    // 0x8044D3E4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    func_8044D1F4(rdram, ctx);
        goto after_0;
    // 0x8044D3E4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    after_0:
    // 0x8044D3E8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8044D3EC: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8044D3F0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8044D3F4: lh          $t5, 0x2($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2);
    // 0x8044D3F8: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x8044D3FC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8044D400:
    // 0x8044D400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D404: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8044D408: jr          $ra
    // 0x8044D40C: nop

    return;
    // 0x8044D40C: nop

;}
RECOMP_FUNC void func_80790A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80790A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80790A24: jal         0x8004700C
    // 0x80790A28: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80790A28: nop

    after_0:
    // 0x80790A2C: beq         $v0, $zero, L_80790A4C
    if (ctx->r2 == 0) {
        // 0x80790A30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80790A4C;
    }
    // 0x80790A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80790A34: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80790A38: lbu         $t6, 0x1F8($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1F8);
    // 0x80790A3C: beql        $t6, $zero, L_80790A50
    if (ctx->r14 == 0) {
        // 0x80790A40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80790A50;
    }
    goto skip_0;
    // 0x80790A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80790A44: b           L_80790A50
    // 0x80790A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80790A50;
    // 0x80790A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80790A4C:
    // 0x80790A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80790A50:
    // 0x80790A50: jr          $ra
    // 0x80790A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80790A54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805A3FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3FD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805A3FD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A3FD8: lwc1        $f6, 0xB4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XB4);
    // 0x805A3FDC: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805A3FE0: jr          $ra
    // 0x805A3FE4: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x805A3FE4: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80670A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670A40: lui         $v0, 0x8067
    ctx->r2 = S32(RELOC_HI16(523, 0X18) << 16);
    // 0x80670A44: addiu       $v0, $v0, 0xA58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(523, 0X18));
    // 0x80670A48: jr          $ra
    // 0x80670A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80670A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806F8F3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8F3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F8F40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F8F48: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x806F8F4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F8F50: jal         0x806F8EB0
    // 0x806F8F54: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_806F8EB0(rdram, ctx);
        goto after_0;
    // 0x806F8F54: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x806F8F58: bne         $v0, $zero, L_806F8F70
    if (ctx->r2 != 0) {
        // 0x806F8F5C: nop
    
            goto L_806F8F70;
    }
    // 0x806F8F5C: nop

    // 0x806F8F60: jal         0x800445A4
    // 0x806F8F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F8F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F8F68: b           L_806F9008
    // 0x806F8F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F9008;
    // 0x806F8F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F8F70:
    // 0x806F8F70: jal         0x806F8D58
    // 0x806F8F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F8D58(rdram, ctx);
        goto after_2;
    // 0x806F8F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F8F78: beq         $v0, $zero, L_806F9004
    if (ctx->r2 == 0) {
        // 0x806F8F7C: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_806F9004;
    }
    // 0x806F8F7C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x806F8F80: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806F8F84: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(694, 0X1900) << 16);
    // 0x806F8F88: sw          $t7, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r15;
    // 0x806F8F8C: addiu       $t8, $t8, -0x6EF0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(694, 0X1900));
    // 0x806F8F90: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806F8F94: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x806F8F98: lui         $t0, 0x806F
    ctx->r8 = S32(RELOC_HI16(694, 0X6A0) << 16);
    // 0x806F8F9C: addiu       $t0, $t0, 0x7EB0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(694, 0X6A0));
    // 0x806F8FA0: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    // 0x806F8FA4: lui         $t3, 0x8070
    ctx->r11 = S32(RELOC_HI16(694, 0XEE4) << 16);
    // 0x806F8FA8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x806F8FAC: addiu       $t3, $t3, -0x790C
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(694, 0XEE4));
    // 0x806F8FB0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F8FB4: sb          $t2, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r10;
    // 0x806F8FB8: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x806F8FBC: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    // 0x806F8FC0: jal         0x806F8E80
    // 0x806F8FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F8E80(rdram, ctx);
        goto after_3;
    // 0x806F8FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F8FC8: jal         0x806F8188
    // 0x806F8FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F8188(rdram, ctx);
        goto after_4;
    // 0x806F8FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F8FD0: lhu         $t5, 0x26($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X26);
    // 0x806F8FD4: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x806F8FD8: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(694, 0X1B14) << 16);
    // 0x806F8FDC: slti        $t6, $t5, 0x42EB
    ctx->r14 = SIGNED(ctx->r13) < 0X42EB ? 1 : 0;
    // 0x806F8FE0: xori        $t6, $t6, 0x1
    ctx->r14 = ctx->r14 ^ 0X1;
    // 0x806F8FE4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x806F8FE8: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x806F8FEC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x806F8FF0: lh          $t9, -0x6CDC($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(694, 0X1B14));
    // 0x806F8FF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F8FF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F8FFC: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
    // 0x806F9000: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_806F9004:
    // 0x806F9004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F9008:
    // 0x806F9008: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F900C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F9010: jr          $ra
    // 0x806F9014: nop

    return;
    // 0x806F9014: nop

;}
RECOMP_FUNC void func_8073D2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D2F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073D2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073D2F8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073D2FC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8073D300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073D304: jal         0x80065728
    // 0x8073D308: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8073D308: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073D30C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8073D310: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8073D314: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8073D318: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(745, 0X13E8) << 16);
    // 0x8073D31C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8073D320: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8073D324: lw          $t6, -0x1A48($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(745, 0X13E8));
    // 0x8073D328: sw          $t6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r14;
    // 0x8073D32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073D330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073D334: jr          $ra
    // 0x8073D338: nop

    return;
    // 0x8073D338: nop

;}
RECOMP_FUNC void func_80004698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004698: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000469C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800046A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046A4:
    // 0x800046A4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800046A8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800046AC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x800046B0: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x800046B4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800046B8: bne         $v0, $a0, L_800046A4
    if (ctx->r2 != ctx->r4) {
        // 0x800046BC: sh          $zero, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = 0;
            goto L_800046A4;
    }
    // 0x800046BC: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x800046C0: jr          $ra
    // 0x800046C4: nop

    return;
    // 0x800046C4: nop

;}
RECOMP_FUNC void func_805D871C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D871C: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x805D8720: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805D8724: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X2350) << 16);
    // 0x805D8728: bne         $v0, $zero, L_805D8758
    if (ctx->r2 != 0) {
        // 0x805D872C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_805D8758;
    }
    // 0x805D872C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x805D8730: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x805D8734: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x805D8738: addiu       $a1, $t6, 0x1
    ctx->r5 = ADD32(ctx->r14, 0X1);
    // 0x805D873C: slti        $at, $a1, 0x25
    ctx->r1 = SIGNED(ctx->r5) < 0X25 ? 1 : 0;
    // 0x805D8740: bne         $at, $zero, L_805D8760
    if (ctx->r1 != 0) {
        // 0x805D8744: sw          $a1, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r5;
            goto L_805D8760;
    }
    // 0x805D8744: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x805D8748: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x805D874C: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x805D8750: b           L_805D8760
    // 0x805D8754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D8760;
    // 0x805D8754: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D8758:
    // 0x805D8758: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x805D875C: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
L_805D8760:
    // 0x805D8760: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x805D8764: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D8768: lw          $t1, -0x63B0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X2350));
    // 0x805D876C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x805D8770: jr          $ra
    // 0x805D8774: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
    return;
    // 0x805D8774: sw          $t1, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805C6E78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6E78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x805C6E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C6E80: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C6E84: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x805C6E88: jal         0x8004700C
    // 0x805C6E8C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C6E8C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C6E90: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C6E94: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805C6E98: beq         $v0, $zero, L_805C70A0
    if (ctx->r2 == 0) {
        // 0x805C6E9C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805C70A0;
    }
    // 0x805C6E9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805C6EA0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x805C6EA4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x805C6EA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x805C6EAC: jal         0x80047AB8
    // 0x805C6EB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x805C6EB0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_1:
    // 0x805C6EB4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805C6EB8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805C6EBC: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C6EC0: sw          $zero, 0x138($a2)
    MEM_W(0X138, ctx->r6) = 0;
    // 0x805C6EC4: lwc1        $f0, 0x3C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x805C6EC8: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805C6ECC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805C6ED0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x805C6ED4: nop

    // 0x805C6ED8: bc1fl       L_805C6EEC
    if (!c1cs) {
        // 0x805C6EDC: lwc1        $f8, 0x174($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X174);
            goto L_805C6EEC;
    }
    goto skip_0;
    // 0x805C6EDC: lwc1        $f8, 0x174($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X174);
    skip_0:
    // 0x805C6EE0: sw          $t6, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r14;
    // 0x805C6EE4: lwc1        $f0, 0x3C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x805C6EE8: lwc1        $f8, 0x174($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X174);
L_805C6EEC:
    // 0x805C6EEC: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x805C6EF0: lwc1        $f4, 0x40($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X40);
    // 0x805C6EF4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x805C6EF8: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x805C6EFC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x805C6F00: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x805C6F04: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x805C6F08: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805C6F0C: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x805C6F10: jal         0x80067114
    // 0x805C6F14: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x805C6F14: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x805C6F18: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805C6F1C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C6F20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C6F24: lw          $t7, 0x138($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X138);
    // 0x805C6F28: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C6F2C: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x805C6F30: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805C6F34: beq         $t7, $zero, L_805C6F5C
    if (ctx->r15 == 0) {
        // 0x805C6F38: add.s       $f2, $f0, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
            goto L_805C6F5C;
    }
    // 0x805C6F38: add.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x805C6F3C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x805C6F40: jal         0x80067114
    // 0x805C6F44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x805C6F44: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_3:
    // 0x805C6F48: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x805C6F4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805C6F50: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x805C6F54: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x805C6F58: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_805C6F5C:
    // 0x805C6F5C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805C6F60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805C6F64: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C6F68: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x805C6F6C: nop

    // 0x805C6F70: bc1fl       L_805C6F88
    if (!c1cs) {
        // 0x805C6F74: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_805C6F88;
    }
    goto skip_1;
    // 0x805C6F74: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_1:
    // 0x805C6F78: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C6F7C: nop

    // 0x805C6F80: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805C6F84: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_805C6F88:
    // 0x805C6F88: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805C6F8C: nop

    // 0x805C6F90: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x805C6F94: nop

    // 0x805C6F98: bc1fl       L_805C6FA8
    if (!c1cs) {
        // 0x805C6F9C: lwc1        $f0, 0x8($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
            goto L_805C6FA8;
    }
    goto skip_2;
    // 0x805C6F9C: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x805C6FA0: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x805C6FA4: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
L_805C6FA8:
    // 0x805C6FA8: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x805C6FAC: nop

    // 0x805C6FB0: bc1fl       L_805C7044
    if (!c1cs) {
        // 0x805C6FB4: lwc1        $f12, 0x50($a2)
        ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
            goto L_805C7044;
    }
    goto skip_3;
    // 0x805C6FB4: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
    skip_3:
    // 0x805C6FB8: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
    // 0x805C6FBC: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x805C6FC0: nop

    // 0x805C6FC4: bc1fl       L_805C7004
    if (!c1cs) {
        // 0x805C6FC8: sub.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_805C7004;
    }
    goto skip_4;
    // 0x805C6FC8: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    skip_4:
    // 0x805C6FCC: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805C6FD0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805C6FD4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C6FD8: nop

    // 0x805C6FDC: bc1fl       L_805C6FF8
    if (!c1cs) {
        // 0x805C6FE0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805C6FF8;
    }
    goto skip_5;
    // 0x805C6FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_5:
    // 0x805C6FE4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805C6FE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C6FEC: b           L_805C7038
    // 0x805C6FF0: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
        goto L_805C7038;
    // 0x805C6FF0: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x805C6FF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805C6FF8:
    // 0x805C6FF8: b           L_805C7038
    // 0x805C6FFC: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
        goto L_805C7038;
    // 0x805C6FFC: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x805C7000: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
L_805C7004:
    // 0x805C7004: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805C7008: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C700C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805C7010: nop

    // 0x805C7014: bc1fl       L_805C7030
    if (!c1cs) {
        // 0x805C7018: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_805C7030;
    }
    goto skip_6;
    // 0x805C7018: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_6:
    // 0x805C701C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805C7020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C7024: b           L_805C7038
    // 0x805C7028: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
        goto L_805C7038;
    // 0x805C7028: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    // 0x805C702C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_805C7030:
    // 0x805C7030: nop

    // 0x805C7034: swc1        $f10, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f10.u32l;
L_805C7038:
    // 0x805C7038: b           L_805C70A0
    // 0x805C703C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
        goto L_805C70A0;
    // 0x805C703C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x805C7040: lwc1        $f12, 0x50($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X50);
L_805C7044:
    // 0x805C7044: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x805C7048: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x805C704C: nop

    // 0x805C7050: bc1fl       L_805C7060
    if (!c1cs) {
        // 0x805C7054: c.lt.s      $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
            goto L_805C7060;
    }
    goto skip_7;
    // 0x805C7054: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    skip_7:
    // 0x805C7058: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x805C705C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
L_805C7060:
    // 0x805C7060: nop

    // 0x805C7064: bc1fl       L_805C7074
    if (!c1cs) {
        // 0x805C7068: lwc1        $f4, 0x4($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
            goto L_805C7074;
    }
    goto skip_8;
    // 0x805C7068: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    skip_8:
    // 0x805C706C: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805C7070: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
L_805C7074:
    // 0x805C7074: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805C7078: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C707C: sub.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x805C7080: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C7084: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805C7088: nop

    // 0x805C708C: bc1fl       L_805C70A0
    if (!c1cs) {
        // 0x805C7090: swc1        $f2, 0x50($a2)
        MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
            goto L_805C70A0;
    }
    goto skip_9;
    // 0x805C7090: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
    skip_9:
    // 0x805C7094: b           L_805C70A0
    // 0x805C7098: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
        goto L_805C70A0;
    // 0x805C7098: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x805C709C: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
L_805C70A0:
    // 0x805C70A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C70A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x805C70A8: jr          $ra
    // 0x805C70AC: nop

    return;
    // 0x805C70AC: nop

;}
RECOMP_FUNC void func_8003B540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B540: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B544: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B548: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003B54C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003B550: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8003B554: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B558: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8003B55C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003B560: andi        $v0, $t7, 0xFF
    ctx->r2 = ctx->r15 & 0XFF;
    // 0x8003B564: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8003B568: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8003B56C: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x8003B570: lw          $t8, -0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1378);
    // 0x8003B574: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x8003B578: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8003B57C: lw          $t9, -0x1360($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1360);
    // 0x8003B580: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003B584: jalr        $t9
    // 0x8003B588: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003B588: nop

    after_0:
    // 0x8003B58C: jal         0x80039EAC
    // 0x8003B590: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80039EAC(rdram, ctx);
        goto after_1;
    // 0x8003B590: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003B594: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B598: addiu       $at, $zero, 0x401C
    ctx->r1 = ADD32(0, 0X401C);
    // 0x8003B59C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8003B5A0: beq         $v0, $at, L_8003B5B8
    if (ctx->r2 == ctx->r1) {
        // 0x8003B5A4: addiu       $at, $zero, 0x401D
        ctx->r1 = ADD32(0, 0X401D);
            goto L_8003B5B8;
    }
    // 0x8003B5A4: addiu       $at, $zero, 0x401D
    ctx->r1 = ADD32(0, 0X401D);
    // 0x8003B5A8: beql        $v0, $at, L_8003B620
    if (ctx->r2 == ctx->r1) {
        // 0x8003B5AC: lbu         $v0, 0x1F($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X1F);
            goto L_8003B620;
    }
    goto skip_0;
    // 0x8003B5AC: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    skip_0:
    // 0x8003B5B0: b           L_8003B67C
    // 0x8003B5B4: nop

        goto L_8003B67C;
    // 0x8003B5B4: nop

L_8003B5B8:
    // 0x8003B5B8: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x8003B5BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003B5C0: bnel        $v0, $at, L_8003B5E4
    if (ctx->r2 != ctx->r1) {
        // 0x8003B5C4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003B5E4;
    }
    goto skip_1;
    // 0x8003B5C4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
    // 0x8003B5C8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B5CC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B5D0: lw          $t0, 0xF54($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B5D4: ori         $t1, $t0, 0x800
    ctx->r9 = ctx->r8 | 0X800;
    // 0x8003B5D8: b           L_8003B67C
    // 0x8003B5DC: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
        goto L_8003B67C;
    // 0x8003B5DC: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
    // 0x8003B5E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8003B5E4:
    // 0x8003B5E4: bne         $v0, $at, L_8003B600
    if (ctx->r2 != ctx->r1) {
        // 0x8003B5E8: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_8003B600;
    }
    // 0x8003B5E8: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B5EC: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B5F0: lw          $t2, 0xF54($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B5F4: ori         $t3, $t2, 0x800
    ctx->r11 = ctx->r10 | 0X800;
    // 0x8003B5F8: b           L_8003B67C
    // 0x8003B5FC: sw          $t3, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r11;
        goto L_8003B67C;
    // 0x8003B5FC: sw          $t3, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r11;
L_8003B600:
    // 0x8003B600: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B604: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B608: lw          $t4, 0xF54($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B60C: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8003B610: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8003B614: b           L_8003B67C
    // 0x8003B618: sw          $t5, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r13;
        goto L_8003B67C;
    // 0x8003B618: sw          $t5, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r13;
    // 0x8003B61C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
L_8003B620:
    // 0x8003B620: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003B624: bnel        $v0, $at, L_8003B648
    if (ctx->r2 != ctx->r1) {
        // 0x8003B628: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8003B648;
    }
    goto skip_2;
    // 0x8003B628: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_2:
    // 0x8003B62C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B630: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B634: lw          $t6, 0xF54($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B638: ori         $t7, $t6, 0x400
    ctx->r15 = ctx->r14 | 0X400;
    // 0x8003B63C: b           L_8003B67C
    // 0x8003B640: sw          $t7, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r15;
        goto L_8003B67C;
    // 0x8003B640: sw          $t7, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r15;
    // 0x8003B644: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8003B648:
    // 0x8003B648: bne         $v0, $at, L_8003B664
    if (ctx->r2 != ctx->r1) {
        // 0x8003B64C: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_8003B664;
    }
    // 0x8003B64C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B650: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B654: lw          $t8, 0xF54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B658: ori         $t9, $t8, 0x400
    ctx->r25 = ctx->r24 | 0X400;
    // 0x8003B65C: b           L_8003B67C
    // 0x8003B660: sw          $t9, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r25;
        goto L_8003B67C;
    // 0x8003B660: sw          $t9, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r25;
L_8003B664:
    // 0x8003B664: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8003B668: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8003B66C: lw          $t0, 0xF54($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XF54);
    // 0x8003B670: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8003B674: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8003B678: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
L_8003B67C:
    // 0x8003B67C: jal         0x8003A060
    // 0x8003B680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003A060(rdram, ctx);
        goto after_2;
    // 0x8003B680: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8003B684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B68C: jr          $ra
    // 0x8003B690: nop

    return;
    // 0x8003B690: nop

;}
RECOMP_FUNC void func_805AC844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC844: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AC848: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC84C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AC850: jal         0x8004700C
    // 0x805AC854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805AC854: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805AC858: beq         $v0, $zero, L_805AC874
    if (ctx->r2 == 0) {
        // 0x805AC85C: lbu         $t6, 0x1F($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X1F);
            goto L_805AC874;
    }
    // 0x805AC85C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805AC860: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x805AC864: bnel        $t6, $at, L_805AC878
    if (ctx->r14 != ctx->r1) {
        // 0x805AC868: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC878;
    }
    goto skip_0;
    // 0x805AC868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AC86C: jal         0x805AC77C
    // 0x805AC870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AC77C(rdram, ctx);
        goto after_1;
    // 0x805AC870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_805AC874:
    // 0x805AC874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AC878:
    // 0x805AC878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AC87C: jr          $ra
    // 0x805AC880: nop

    return;
    // 0x805AC880: nop

;}
RECOMP_FUNC void func_804461C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804461C0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804461C4: addiu       $a1, $zero, 0x1EF0
    ctx->r5 = ADD32(0, 0X1EF0);
    // 0x804461C8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804461CC: sw          $a1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r5;
    // 0x804461D0: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x804461D4: sw          $zero, 0x6CA8($v1)
    MEM_W(0X6CA8, ctx->r3) = 0;
    // 0x804461D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804461DC: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x804461E0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x804461E4: sw          $a2, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r6;
    // 0x804461E8: sw          $a3, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r7;
    // 0x804461EC: sw          $a2, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r6;
    // 0x804461F0: sw          $a3, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->r7;
    // 0x804461F4: sw          $a1, 0xFC($v0)
    MEM_W(0XFC, ctx->r2) = ctx->r5;
    // 0x804461F8: swc1        $f0, 0x6B18($v1)
    MEM_W(0X6B18, ctx->r3) = ctx->f0.u32l;
    // 0x804461FC: swc1        $f0, 0x6B1C($v1)
    MEM_W(0X6B1C, ctx->r3) = ctx->f0.u32l;
    // 0x80446200: swc1        $f0, 0x6B20($v1)
    MEM_W(0X6B20, ctx->r3) = ctx->f0.u32l;
    // 0x80446204: jr          $ra
    // 0x80446208: swc1        $f0, 0x6B24($v1)
    MEM_W(0X6B24, ctx->r3) = ctx->f0.u32l;
    return;
    // 0x80446208: swc1        $f0, 0x6B24($v1)
    MEM_W(0X6B24, ctx->r3) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8045FD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FD6C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8045FD70: jr          $ra
    // 0x8045FD74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8045FD74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800388B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800388B4: jr          $ra
    // 0x800388B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800388B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804475C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804475C0: slti        $at, $a0, 0x30C
    ctx->r1 = SIGNED(ctx->r4) < 0X30C ? 1 : 0;
    // 0x804475C4: beq         $at, $zero, L_804475D4
    if (ctx->r1 == 0) {
        // 0x804475C8: lw          $v0, 0x1F4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X1F4);
            goto L_804475D4;
    }
    // 0x804475C8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804475CC: jr          $ra
    // 0x804475D0: sw          $zero, 0x200($v0)
    MEM_W(0X200, ctx->r2) = 0;
    return;
    // 0x804475D0: sw          $zero, 0x200($v0)
    MEM_W(0X200, ctx->r2) = 0;
L_804475D4:
    // 0x804475D4: slti        $at, $a0, 0x3C0
    ctx->r1 = SIGNED(ctx->r4) < 0X3C0 ? 1 : 0;
    // 0x804475D8: beq         $at, $zero, L_804475E8
    if (ctx->r1 == 0) {
        // 0x804475DC: addiu       $t6, $a0, -0x30C
        ctx->r14 = ADD32(ctx->r4, -0X30C);
            goto L_804475E8;
    }
    // 0x804475DC: addiu       $t6, $a0, -0x30C
    ctx->r14 = ADD32(ctx->r4, -0X30C);
    // 0x804475E0: jr          $ra
    // 0x804475E4: sw          $t6, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->r14;
    return;
    // 0x804475E4: sw          $t6, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->r14;
L_804475E8:
    // 0x804475E8: slti        $at, $a0, 0x1B6C
    ctx->r1 = SIGNED(ctx->r4) < 0X1B6C ? 1 : 0;
    // 0x804475EC: beq         $at, $zero, L_8044765C
    if (ctx->r1 == 0) {
        // 0x804475F0: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_8044765C;
    }
    // 0x804475F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804475F4: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x804475F8: lw          $v1, 0x6980($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6980);
    // 0x804475FC: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80447600: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x80447604: lh          $at, 0x8($a2)
    ctx->r1 = MEM_H(ctx->r6, 0X8);
    // 0x80447608: sll         $a3, $at, 4
    ctx->r7 = S32(ctx->r1 << 4);
    // 0x8044760C: subu        $a3, $a3, $at
    ctx->r7 = SUB32(ctx->r7, ctx->r1);
    // 0x80447610: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x80447614: sw          $a3, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->r7;
    // 0x80447618: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8044761C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80447620: lwc1        $f4, 0x6AF0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6AF0);
    // 0x80447624: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80447628: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8044762C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80447630: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447634: swc1        $f8, 0x6AF0($a0)
    MEM_W(0X6AF0, ctx->r4) = ctx->f8.u32l;
    // 0x80447638: lwc1        $f10, 0x6AF0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6AF0);
    // 0x8044763C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80447640: nop

    // 0x80447644: bc1f        L_80447678
    if (!c1cs) {
        // 0x80447648: nop
    
            goto L_80447678;
    }
    // 0x80447648: nop

    // 0x8044764C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80447650: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447654: jr          $ra
    // 0x80447658: swc1        $f18, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->f18.u32l;
    return;
    // 0x80447658: swc1        $f18, 0x6AF0($at)
    MEM_W(0X6AF0, ctx->r1) = ctx->f18.u32l;
L_8044765C:
    // 0x8044765C: slti        $at, $a0, 0x1C20
    ctx->r1 = SIGNED(ctx->r4) < 0X1C20 ? 1 : 0;
    // 0x80447660: beq         $at, $zero, L_80447674
    if (ctx->r1 == 0) {
        // 0x80447664: addiu       $t7, $zero, 0x1C20
        ctx->r15 = ADD32(0, 0X1C20);
            goto L_80447674;
    }
    // 0x80447664: addiu       $t7, $zero, 0x1C20
    ctx->r15 = ADD32(0, 0X1C20);
    // 0x80447668: subu        $t8, $t7, $a0
    ctx->r24 = SUB32(ctx->r15, ctx->r4);
    // 0x8044766C: jr          $ra
    // 0x80447670: sw          $t8, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->r24;
    return;
    // 0x80447670: sw          $t8, 0x200($v0)
    MEM_W(0X200, ctx->r2) = ctx->r24;
L_80447674:
    // 0x80447674: sw          $zero, 0x200($v0)
    MEM_W(0X200, ctx->r2) = 0;
L_80447678:
    // 0x80447678: jr          $ra
    // 0x8044767C: nop

    return;
    // 0x8044767C: nop

;}
RECOMP_FUNC void func_806CCD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCD4C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806CCD50: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x806CCD54: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x806CCD58: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x806CCD5C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x806CCD60: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x806CCD64: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x806CCD68: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x806CCD6C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x806CCD70: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCD74: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C24) << 16);
    // 0x806CCD78: lwc1        $f22, -0xCBC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C24));
    // 0x806CCD7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806CCD80: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806CCD84: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806CCD88: addiu       $s4, $zero, 0x3B
    ctx->r20 = ADD32(0, 0X3B);
    // 0x806CCD8C: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x806CCD90: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_806CCD94:
    // 0x806CCD94: lbu         $a0, 0x86C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X86C);
    // 0x806CCD98: lbu         $a1, 0x86D($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X86D);
    // 0x806CCD9C: lh          $a2, 0x86E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X86E);
    // 0x806CCDA0: jal         0x806CB8F4
    // 0x806CCDA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_806CB8F4(rdram, ctx);
        goto after_0;
    // 0x806CCDA4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_0:
    // 0x806CCDA8: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x806CCDAC: lwc1        $f6, 0x590($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X590);
    // 0x806CCDB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806CCDB4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x806CCDB8: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x806CCDBC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x806CCDC0: swc1        $f10, 0x590($s3)
    MEM_W(0X590, ctx->r19) = ctx->f10.u32l;
    // 0x806CCDC4: lh          $a2, 0x86E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X86E);
    // 0x806CCDC8: lbu         $a1, 0x86D($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X86D);
    // 0x806CCDCC: lbu         $a0, 0x86C($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X86C);
    // 0x806CCDD0: jal         0x806CB9B8
    // 0x806CCDD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_806CB9B8(rdram, ctx);
        goto after_1;
    // 0x806CCDD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x806CCDD8: lwc1        $f12, 0x67C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X67C);
    // 0x806CCDDC: lwc1        $f14, 0x680($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X680);
    // 0x806CCDE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806CCDE4: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x806CCDE8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x806CCDEC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x806CCDF0: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x806CCDF4: mul.s       $f2, $f16, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x806CCDF8: add.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x806CCDFC: mul.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x806CCE00: swc1        $f18, 0x674($s1)
    MEM_W(0X674, ctx->r17) = ctx->f18.u32l;
    // 0x806CCE04: add.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x806CCE08: bne         $s2, $s4, L_806CCD94
    if (ctx->r18 != ctx->r20) {
        // 0x806CCE0C: swc1        $f4, 0x678($s1)
        MEM_W(0X678, ctx->r17) = ctx->f4.u32l;
            goto L_806CCD94;
    }
    // 0x806CCE0C: swc1        $f4, 0x678($s1)
    MEM_W(0X678, ctx->r17) = ctx->f4.u32l;
    // 0x806CCE10: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x806CCE14: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x806CCE18: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x806CCE1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x806CCE20: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x806CCE24: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x806CCE28: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x806CCE2C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x806CCE30: jr          $ra
    // 0x806CCE34: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x806CCE34: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806CDF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CDF34: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806CDF38: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806CDF3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CDF40: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806CDF44: lwc1        $f8, 0x10C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10C);
    // 0x806CDF48: mul.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x806CDF4C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x806CDF50: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x806CDF54: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x806CDF58: jr          $ra
    // 0x806CDF5C: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
    return;
    // 0x806CDF5C: swc1        $f18, 0x10C($a0)
    MEM_W(0X10C, ctx->r4) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_80024340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80024344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024348: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002434C: lwc1        $f12, -0x7678($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80024350: jal         0x80065954
    // 0x80024354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80024354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80024358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002435C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80024360: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80024364: lbu         $t7, 0x113($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X113);
    // 0x80024368: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002436C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80024370: lwc1        $f2, -0x624C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X624C);
    // 0x80024374: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80024378: lwc1        $f4, -0x284($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X284);
    // 0x8002437C: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80024380: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80024384: nop

    // 0x80024388: bc1fl       L_8002439C
    if (!c1cs) {
        // 0x8002438C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8002439C;
    }
    goto skip_0;
    // 0x8002438C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x80024390: b           L_800243B8
    // 0x80024394: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800243B8;
    // 0x80024394: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80024398: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8002439C:
    // 0x8002439C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800243A0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800243A4: nop

    // 0x800243A8: bc1f        L_800243B8
    if (!c1cs) {
        // 0x800243AC: nop
    
            goto L_800243B8;
    }
    // 0x800243AC: nop

    // 0x800243B0: b           L_800243B8
    // 0x800243B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800243B8;
    // 0x800243B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800243B8:
    // 0x800243B8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800243BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800243C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800243C4: lwc1        $f8, -0x6264($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6264);
    // 0x800243C8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800243CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800243D0: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800243D4: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
    // 0x800243D8: lwc1        $f16, -0x6258($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6258);
    // 0x800243DC: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800243E0: jal         0x800240C0
    // 0x800243E4: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
    func_800240C0(rdram, ctx);
        goto after_1;
    // 0x800243E4: swc1        $f18, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f18.u32l;
    after_1:
    // 0x800243E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800243EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800243F0: jr          $ra
    // 0x800243F4: nop

    return;
    // 0x800243F4: nop

;}
RECOMP_FUNC void func_8064B064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064B068: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064B06C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064B070: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B074: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8064B078: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064B07C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064B080: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8064B084: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064B088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B08C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064B090: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064B094: nop

    // 0x8064B098: bc1fl       L_8064B0B0
    if (!c1cs) {
        // 0x8064B09C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064B0B0;
    }
    goto skip_0;
    // 0x8064B09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064B0A0: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064B0A4: jal         0x8064B3E0
    // 0x8064B0A8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064B3E0(rdram, ctx);
        goto after_0;
    // 0x8064B0A8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064B0AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064B0B0:
    // 0x8064B0B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064B0B4: jr          $ra
    // 0x8064B0B8: nop

    return;
    // 0x8064B0B8: nop

;}
RECOMP_FUNC void func_8073A200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A200: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8073A204: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8073A208: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x8073A20C: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x8073A210: lw          $t7, 0xA68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XA68);
    // 0x8073A214: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8073A218: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8073A21C: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8073A220: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8073A224: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8073A228: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8073A22C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8073A230: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8073A234: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8073A238: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8073A23C: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073A240: lw          $t9, 0xAC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XAC);
    // 0x8073A244: jalr        $t9
    // 0x8073A248: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8073A248: nop

    after_0:
    // 0x8073A24C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8073A250: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073A254: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2480) << 16);
    // 0x8073A258: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8073A25C: swc1        $f4, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x8073A260: lwc1        $f6, -0x4150($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2480));
    // 0x8073A264: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x8073A268: jal         0x80047F9C
    // 0x8073A26C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8073A26C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8073A270: lui         $a0, 0x46E9
    ctx->r4 = S32(0X46E9 << 16);
    // 0x8073A274: lui         $a3, 0xBCA3
    ctx->r7 = S32(0XBCA3 << 16);
    // 0x8073A278: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8073A27C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8073A280: lui         $a1, 0xC2C2
    ctx->r5 = S32(0XC2C2 << 16);
    // 0x8073A284: jal         0x8004613C
    // 0x8073A288: lui         $a2, 0xC1A8
    ctx->r6 = S32(0XC1A8 << 16);
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x8073A288: lui         $a2, 0xC1A8
    ctx->r6 = S32(0XC1A8 << 16);
    after_2:
    // 0x8073A28C: sw          $v0, 0x38($s5)
    MEM_W(0X38, ctx->r21) = ctx->r2;
    // 0x8073A290: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8073A294: jal         0x80047F9C
    // 0x8073A298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8073A298: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8073A29C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2484) << 16);
    // 0x8073A2A0: lwc1        $f0, -0x414C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2484));
    // 0x8073A2A4: lw          $t0, 0x38($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X38);
    // 0x8073A2A8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2488) << 16);
    // 0x8073A2AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8073A2B0: swc1        $f0, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f0.u32l;
    // 0x8073A2B4: lw          $t1, 0x38($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X38);
    // 0x8073A2B8: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x8073A2BC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x8073A2C0: swc1        $f0, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f0.u32l;
    // 0x8073A2C4: lw          $v0, 0x38($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X38);
    // 0x8073A2C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8073A2CC: lui         $a3, 0xC22C
    ctx->r7 = S32(0XC22C << 16);
    // 0x8073A2D0: lwc1        $f8, 0x6C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8073A2D4: swc1        $f8, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f8.u32l;
    // 0x8073A2D8: lw          $v0, 0x38($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X38);
    // 0x8073A2DC: lwc1        $f10, 0x70($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8073A2E0: swc1        $f10, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f10.u32l;
    // 0x8073A2E4: lwc1        $f16, -0x4148($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2488));
    // 0x8073A2E8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8073A2EC: jal         0x8005CEBC
    // 0x8073A2F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x8073A2F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8073A2F4: sw          $v0, 0x3C($s5)
    MEM_W(0X3C, ctx->r21) = ctx->r2;
    // 0x8073A2F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8073A2FC: jal         0x80047F9C
    // 0x8073A300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8073A300: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8073A304: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X248C) << 16);
    // 0x8073A308: lwc1        $f18, -0x4144($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X248C));
    // 0x8073A30C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8073A310: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8073A314: addiu       $a0, $zero, 0x40F1
    ctx->r4 = ADD32(0, 0X40F1);
    // 0x8073A318: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x8073A31C: lui         $a2, 0xC3C8
    ctx->r6 = S32(0XC3C8 << 16);
    // 0x8073A320: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8073A324: jal         0x8005CEBC
    // 0x8073A328: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_6;
    // 0x8073A328: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8073A32C: sw          $v0, 0x40($s5)
    MEM_W(0X40, ctx->r21) = ctx->r2;
    // 0x8073A330: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    // 0x8073A334: jal         0x80047F9C
    // 0x8073A338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8073A338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8073A33C: lw          $t4, 0x40($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X40);
    // 0x8073A340: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x8073A344: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8073A348: lw          $v0, 0x16C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X16C);
    // 0x8073A34C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073A350: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x8073A354: sb          $t5, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r13;
    // 0x8073A358: sw          $zero, 0x8($s5)
    MEM_W(0X8, ctx->r21) = 0;
    // 0x8073A35C: lw          $t6, 0xFB8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XFB8);
    // 0x8073A360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8073A364: addiu       $s2, $s2, -0x76C0
    ctx->r18 = ADD32(ctx->r18, -0X76C0);
    // 0x8073A368: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8073A36C: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8073A370: bne         $v1, $t8, L_8073A38C
    if (ctx->r3 != ctx->r24) {
        // 0x8073A374: or          $s0, $s5, $zero
        ctx->r16 = ctx->r21 | 0;
            goto L_8073A38C;
    }
    // 0x8073A374: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x8073A378: sw          $v1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r3;
    // 0x8073A37C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8073A380: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8073A384: b           L_8073A398
    // 0x8073A388: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
        goto L_8073A398;
    // 0x8073A388: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
L_8073A38C:
    // 0x8073A38C: sw          $zero, 0xC($s5)
    MEM_W(0XC, ctx->r21) = 0;
    // 0x8073A390: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8073A394: sh          $zero, 0x144($t1)
    MEM_H(0X144, ctx->r9) = 0;
L_8073A398:
    // 0x8073A398: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8073A39C: sw          $zero, 0x10($s5)
    MEM_W(0X10, ctx->r21) = 0;
    // 0x8073A3A0: swc1        $f0, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->f0.u32l;
    // 0x8073A3A4: swc1        $f0, 0x2C($s5)
    MEM_W(0X2C, ctx->r21) = ctx->f0.u32l;
    // 0x8073A3A8: swc1        $f0, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f0.u32l;
    // 0x8073A3AC: swc1        $f0, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f0.u32l;
    // 0x8073A3B0: addiu       $v1, $v1, -0x76B4
    ctx->r3 = ADD32(ctx->r3, -0X76B4);
L_8073A3B4:
    // 0x8073A3B4: lhu         $t2, 0x204($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X204);
    // 0x8073A3B8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8073A3BC: sltu        $at, $s2, $v1
    ctx->r1 = ctx->r18 < ctx->r3 ? 1 : 0;
    // 0x8073A3C0: bne         $at, $zero, L_8073A3B4
    if (ctx->r1 != 0) {
        // 0x8073A3C4: or          $v0, $v0, $t2
        ctx->r2 = ctx->r2 | ctx->r10;
            goto L_8073A3B4;
    }
    // 0x8073A3C4: or          $v0, $v0, $t2
    ctx->r2 = ctx->r2 | ctx->r10;
    // 0x8073A3C8: bne         $v0, $zero, L_8073A3F8
    if (ctx->r2 != 0) {
        // 0x8073A3CC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8073A3F8;
    }
    // 0x8073A3CC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8073A3D0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8073A3D4: sll         $t3, $v1, 1
    ctx->r11 = S32(ctx->r3 << 1);
    // 0x8073A3D8: sh          $zero, 0x1A($s5)
    MEM_H(0X1A, ctx->r21) = 0;
    // 0x8073A3DC: sh          $zero, 0x1C($s5)
    MEM_H(0X1C, ctx->r21) = 0;
    // 0x8073A3E0: addu        $s0, $s5, $t3
    ctx->r16 = ADD32(ctx->r21, ctx->r11);
    // 0x8073A3E4: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x8073A3E8: sh          $zero, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = 0;
    // 0x8073A3EC: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x8073A3F0: b           L_8073A518
    // 0x8073A3F4: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
        goto L_8073A518;
    // 0x8073A3F4: sh          $zero, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = 0;
L_8073A3F8:
    // 0x8073A3F8: lw          $t4, 0x3C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X3C);
    // 0x8073A3FC: lui         $s2, 0x8010
    ctx->r18 = S32(0X8010 << 16);
    // 0x8073A400: lui         $s6, 0x8010
    ctx->r22 = S32(0X8010 << 16);
    // 0x8073A404: addiu       $s6, $s6, -0x76B4
    ctx->r22 = ADD32(ctx->r22, -0X76B4);
    // 0x8073A408: addiu       $s2, $s2, -0x76C0
    ctx->r18 = ADD32(ctx->r18, -0X76C0);
    // 0x8073A40C: lw          $s7, 0x1F4($t4)
    ctx->r23 = MEM_W(ctx->r12, 0X1F4);
L_8073A410:
    // 0x8073A410: andi        $s3, $s4, 0xFF
    ctx->r19 = ctx->r20 & 0XFF;
    // 0x8073A414: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8073A418: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    // 0x8073A41C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073A420: jal         0x8005C27C
    // 0x8073A424: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x8073A424: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8073A428: lhu         $t5, 0x204($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X204);
    // 0x8073A42C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8073A430: sh          $t5, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r13;
    // 0x8073A434: lw          $t6, 0x18($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X18);
    // 0x8073A438: andi        $a1, $t5, 0xFFFF
    ctx->r5 = ctx->r13 & 0XFFFF;
    // 0x8073A43C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8073A440: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8073A444: subu        $s1, $s3, $t8
    ctx->r17 = SUB32(ctx->r19, ctx->r24);
    // 0x8073A448: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x8073A44C: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8073A450: andi        $t9, $s1, 0x7
    ctx->r25 = ctx->r17 & 0X7;
    // 0x8073A454: beql        $t9, $zero, L_8073A468
    if (ctx->r25 == 0) {
        // 0x8073A458: lw          $a0, 0x3C($s5)
        ctx->r4 = MEM_W(ctx->r21, 0X3C);
            goto L_8073A468;
    }
    goto skip_0;
    // 0x8073A458: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
    skip_0:
    // 0x8073A45C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8073A460: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x8073A464: lw          $a0, 0x3C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X3C);
L_8073A468:
    // 0x8073A468: jal         0x8005C27C
    // 0x8073A46C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x8073A46C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_9:
    // 0x8073A470: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8073A474: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8073A478: bne         $s2, $s6, L_8073A410
    if (ctx->r18 != ctx->r22) {
        // 0x8073A47C: addiu       $s4, $s4, 0x8
        ctx->r20 = ADD32(ctx->r20, 0X8);
            goto L_8073A410;
    }
    // 0x8073A47C: addiu       $s4, $s4, 0x8
    ctx->r20 = ADD32(ctx->r20, 0X8);
    // 0x8073A480: lw          $t0, 0xC($s5)
    ctx->r8 = MEM_W(ctx->r21, 0XC);
    // 0x8073A484: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8073A488: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073A48C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8073A490: lui         $v1, 0x8074
    ctx->r3 = S32(RELOC_HI16(739, 0X1F08) << 16);
    // 0x8073A494: addiu       $v1, $v1, -0x46C8
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(739, 0X1F08));
    // 0x8073A498: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8073A49C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8073A4A0: swc1        $f4, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f4.u32l;
    // 0x8073A4A4: swc1        $f6, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f6.u32l;
    // 0x8073A4A8: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8073A4AC: lw          $t3, 0x38($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X38);
    // 0x8073A4B0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F30) << 16);
    // 0x8073A4B4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8073A4B8: swc1        $f8, 0x3C($t3)
    MEM_W(0X3C, ctx->r11) = ctx->f8.u32l;
    // 0x8073A4BC: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x8073A4C0: lw          $t7, 0x38($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X38);
    // 0x8073A4C4: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x8073A4C8: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8073A4CC: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8073A4D0: swc1        $f10, 0x40($t7)
    MEM_W(0X40, ctx->r15) = ctx->f10.u32l;
    // 0x8073A4D4: lw          $t8, 0xC($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XC);
    // 0x8073A4D8: lw          $t0, 0x38($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X38);
    // 0x8073A4DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073A4E0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8073A4E4: lwc1        $f16, -0x46A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F30));
    // 0x8073A4E8: swc1        $f16, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f16.u32l;
    // 0x8073A4EC: lw          $v0, 0x38($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X38);
    // 0x8073A4F0: lwc1        $f18, 0x6C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8073A4F4: swc1        $f18, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f18.u32l;
    // 0x8073A4F8: jal         0x8073B8CC
    // 0x8073A4FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    func_8073B8CC(rdram, ctx);
        goto after_10;
    // 0x8073A4FC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_10:
    // 0x8073A500: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8073A504: sw          $t1, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r9;
    // 0x8073A508: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F58) << 16);
    // 0x8073A50C: lwc1        $f4, -0x4678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F58));
    // 0x8073A510: lw          $t2, 0x40($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X40);
    // 0x8073A514: swc1        $f4, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f4.u32l;
L_8073A518:
    // 0x8073A518: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8073A51C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8073A520: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8073A524: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8073A528: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8073A52C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8073A530: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8073A534: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8073A538: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8073A53C: jr          $ra
    // 0x8073A540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8073A540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_807111A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807111A4: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x807111A8: lui         $t9, 0x8071
    ctx->r25 = S32(RELOC_HI16(727, 0X18D4) << 16);
    // 0x807111AC: addiu       $t9, $t9, 0x2844
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(727, 0X18D4));
    // 0x807111B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807111B4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x807111B8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x807111BC: addu        $t4, $t8, $t9
    ctx->r12 = ADD32(ctx->r24, ctx->r25);
    // 0x807111C0: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x807111C4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807111C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807111CC: addiu       $t6, $sp, 0x3C
    ctx->r14 = ADD32(ctx->r29, 0X3C);
    // 0x807111D0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x807111D4: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x807111D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x807111DC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x807111E0: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x807111E4: lw          $t7, 0x8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X8);
    // 0x807111E8: lui         $a3, 0x8071
    ctx->r7 = S32(RELOC_HI16(727, 0XB88) << 16);
    // 0x807111EC: addiu       $a3, $a3, 0x1AF8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(727, 0XB88));
    // 0x807111F0: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x807111F4: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x807111F8: addiu       $a2, $sp, 0xC
    ctx->r6 = ADD32(ctx->r29, 0XC);
    // 0x807111FC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80711200: sw          $t5, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r13;
    // 0x80711204: lw          $t7, 0x10($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X10);
    // 0x80711208: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8071120C: sw          $t7, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r15;
    // 0x80711210: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x80711214: sw          $t5, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r13;
    // 0x80711218: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8071121C: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80711220: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x80711224: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80711228: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8071122C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80711230: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80711234: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x80711238: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8071123C: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80711240: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x80711244: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80711248: mflo        $t8
    ctx->r24 = lo;
    // 0x8071124C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80711250: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x80711254: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80711258: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x8071125C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x80711260: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80711264: lw          $t4, 0x4($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X4);
    // 0x80711268: sw          $t4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r12;
    // 0x8071126C: lw          $t5, 0x8($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X8);
    // 0x80711270: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
    // 0x80711274: lw          $t4, 0xC($t9)
    ctx->r12 = MEM_W(ctx->r25, 0XC);
    // 0x80711278: sw          $t4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r12;
    // 0x8071127C: lw          $t5, 0x10($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X10);
    // 0x80711280: beq         $v1, $zero, L_8071131C
    if (ctx->r3 == 0) {
        // 0x80711284: sw          $t5, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r13;
            goto L_8071131C;
    }
    // 0x80711284: sw          $t5, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r13;
    // 0x80711288: lh          $t7, 0xC($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC);
    // 0x8071128C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80711290: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80711294: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80711298: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8071129C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807112A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807112A4: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x807112A8: nop

    // 0x807112AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x807112B0: swc1        $f10, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f10.u32l;
    // 0x807112B4: lh          $t8, 0xE($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XE);
    // 0x807112B8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x807112BC: nop

    // 0x807112C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807112C4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807112C8: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x807112CC: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x807112D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x807112D4: swc1        $f8, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f8.u32l;
    // 0x807112D8: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807112DC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807112E0: swc1        $f16, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f16.u32l;
    // 0x807112E4: lh          $t6, 0x18($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X18);
    // 0x807112E8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807112EC: nop

    // 0x807112F0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807112F4: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x807112F8: swc1        $f6, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f6.u32l;
    // 0x807112FC: lh          $t9, 0x1C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X1C);
    // 0x80711300: sh          $t9, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r25;
    // 0x80711304: lh          $t4, 0x144($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X144);
    // 0x80711308: bne         $t1, $t4, L_80711318
    if (ctx->r9 != ctx->r12) {
        // 0x8071130C: nop
    
            goto L_80711318;
    }
    // 0x8071130C: nop

    // 0x80711310: b           L_8071131C
    // 0x80711314: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
        goto L_8071131C;
    // 0x80711314: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
L_80711318:
    // 0x80711318: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
L_8071131C:
    // 0x8071131C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80711320: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80711324: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80711328: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8071132C:
    // 0x8071132C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80711330: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80711334: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x80711338: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8071133C: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x80711340: lh          $t9, 0x0($t6)
    ctx->r25 = MEM_H(ctx->r14, 0X0);
    // 0x80711344: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80711348: mflo        $t4
    ctx->r12 = lo;
    // 0x8071134C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x80711350: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x80711354: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80711358: addu        $t5, $a3, $t7
    ctx->r13 = ADD32(ctx->r7, ctx->r15);
    // 0x8071135C: addu        $t8, $t5, $a1
    ctx->r24 = ADD32(ctx->r13, ctx->r5);
    // 0x80711360: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80711364: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80711368: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x8071136C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80711370: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80711374: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x80711378: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x8071137C: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x80711380: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x80711384: beq         $v1, $zero, L_80711414
    if (ctx->r3 == 0) {
        // 0x80711388: sw          $t9, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r25;
            goto L_80711414;
    }
    // 0x80711388: sw          $t9, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r25;
    // 0x8071138C: lh          $t4, 0xC($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XC);
    // 0x80711390: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80711394: nop

    // 0x80711398: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8071139C: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x807113A0: nop

    // 0x807113A4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807113A8: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x807113AC: lh          $t7, 0xE($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XE);
    // 0x807113B0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807113B4: nop

    // 0x807113B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807113BC: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807113C0: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x807113C4: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x807113C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x807113CC: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    // 0x807113D0: lwc1        $f18, 0x14($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807113D4: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807113D8: swc1        $f4, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f4.u32l;
    // 0x807113DC: lh          $t5, 0x18($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X18);
    // 0x807113E0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x807113E4: nop

    // 0x807113E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807113EC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x807113F0: swc1        $f10, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f10.u32l;
    // 0x807113F4: lh          $t8, 0x1C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X1C);
    // 0x807113F8: sh          $t8, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r24;
    // 0x807113FC: lh          $t6, 0x144($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X144);
    // 0x80711400: bne         $t1, $t6, L_80711410
    if (ctx->r9 != ctx->r14) {
        // 0x80711404: nop
    
            goto L_80711410;
    }
    // 0x80711404: nop

    // 0x80711408: b           L_80711414
    // 0x8071140C: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
        goto L_80711414;
    // 0x8071140C: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
L_80711410:
    // 0x80711410: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
L_80711414:
    // 0x80711414: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80711418: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8071141C: lw          $v1, 0x10($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X10);
    // 0x80711420: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x80711424: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x80711428: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8071142C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80711430: mflo        $t6
    ctx->r14 = lo;
    // 0x80711434: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x80711438: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8071143C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80711440: addu        $t9, $a3, $t4
    ctx->r25 = ADD32(ctx->r7, ctx->r12);
    // 0x80711444: addu        $t7, $t9, $a1
    ctx->r15 = ADD32(ctx->r25, ctx->r5);
    // 0x80711448: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8071144C: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x80711450: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80711454: lw          $t5, 0x18($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X18);
    // 0x80711458: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8071145C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x80711460: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80711464: lw          $t5, 0x20($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X20);
    // 0x80711468: sw          $t5, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r13;
    // 0x8071146C: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x80711470: beq         $v1, $zero, L_80711500
    if (ctx->r3 == 0) {
        // 0x80711474: sw          $t8, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r24;
            goto L_80711500;
    }
    // 0x80711474: sw          $t8, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r24;
    // 0x80711478: lh          $t6, 0xC($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XC);
    // 0x8071147C: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80711480: nop

    // 0x80711484: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80711488: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8071148C: nop

    // 0x80711490: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80711494: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80711498: lh          $t4, 0xE($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XE);
    // 0x8071149C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x807114A0: nop

    // 0x807114A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807114A8: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807114AC: swc1        $f16, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f16.u32l;
    // 0x807114B0: lwc1        $f18, 0x10($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X10);
    // 0x807114B4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807114B8: swc1        $f4, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f4.u32l;
    // 0x807114BC: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x807114C0: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807114C4: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x807114C8: lh          $t9, 0x18($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X18);
    // 0x807114CC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x807114D0: nop

    // 0x807114D4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807114D8: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807114DC: swc1        $f18, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f18.u32l;
    // 0x807114E0: lh          $t7, 0x1C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1C);
    // 0x807114E4: sh          $t7, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r15;
    // 0x807114E8: lh          $t5, 0x144($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X144);
    // 0x807114EC: bne         $t1, $t5, L_807114FC
    if (ctx->r9 != ctx->r13) {
        // 0x807114F0: nop
    
            goto L_807114FC;
    }
    // 0x807114F0: nop

    // 0x807114F4: b           L_80711500
    // 0x807114F8: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
        goto L_80711500;
    // 0x807114F8: sb          $t2, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r10;
L_807114FC:
    // 0x807114FC: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
L_80711500:
    // 0x80711500: bne         $a1, $t3, L_8071132C
    if (ctx->r5 != ctx->r11) {
        // 0x80711504: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_8071132C;
    }
    // 0x80711504: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80711508: jr          $ra
    // 0x8071150C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8071150C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8079877C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079877C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80798780: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x80798784: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80798788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079878C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80798790: lh          $a1, 0x6($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X6);
    // 0x80798794: jal         0x8079862C
    // 0x80798798: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    func_8079862C(rdram, ctx);
        goto after_0;
    // 0x80798798: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    after_0:
    // 0x8079879C: beq         $v0, $zero, L_80798854
    if (ctx->r2 == 0) {
        // 0x807987A0: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80798854;
    }
    // 0x807987A0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x807987A4: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x807987A8: addiu       $at, $zero, 0x4695
    ctx->r1 = ADD32(0, 0X4695);
    // 0x807987AC: addiu       $t6, $zero, 0x4507
    ctx->r14 = ADD32(0, 0X4507);
    // 0x807987B0: beq         $v0, $at, L_807987E0
    if (ctx->r2 == ctx->r1) {
        // 0x807987B4: addiu       $at, $zero, 0x471F
        ctx->r1 = ADD32(0, 0X471F);
            goto L_807987E0;
    }
    // 0x807987B4: addiu       $at, $zero, 0x471F
    ctx->r1 = ADD32(0, 0X471F);
    // 0x807987B8: beq         $v0, $at, L_807987E8
    if (ctx->r2 == ctx->r1) {
        // 0x807987BC: addiu       $t7, $zero, 0x4508
        ctx->r15 = ADD32(0, 0X4508);
            goto L_807987E8;
    }
    // 0x807987BC: addiu       $t7, $zero, 0x4508
    ctx->r15 = ADD32(0, 0X4508);
    // 0x807987C0: addiu       $at, $zero, 0x4720
    ctx->r1 = ADD32(0, 0X4720);
    // 0x807987C4: beq         $v0, $at, L_807987F0
    if (ctx->r2 == ctx->r1) {
        // 0x807987C8: addiu       $t8, $zero, 0x4509
        ctx->r24 = ADD32(0, 0X4509);
            goto L_807987F0;
    }
    // 0x807987C8: addiu       $t8, $zero, 0x4509
    ctx->r24 = ADD32(0, 0X4509);
    // 0x807987CC: addiu       $at, $zero, 0x4721
    ctx->r1 = ADD32(0, 0X4721);
    // 0x807987D0: beq         $v0, $at, L_807987F8
    if (ctx->r2 == ctx->r1) {
        // 0x807987D4: addiu       $t9, $zero, 0x450A
        ctx->r25 = ADD32(0, 0X450A);
            goto L_807987F8;
    }
    // 0x807987D4: addiu       $t9, $zero, 0x450A
    ctx->r25 = ADD32(0, 0X450A);
    // 0x807987D8: b           L_807987FC
    // 0x807987DC: nop

        goto L_807987FC;
    // 0x807987DC: nop

L_807987E0:
    // 0x807987E0: b           L_807987FC
    // 0x807987E4: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
        goto L_807987FC;
    // 0x807987E4: sh          $t6, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r14;
L_807987E8:
    // 0x807987E8: b           L_807987FC
    // 0x807987EC: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
        goto L_807987FC;
    // 0x807987EC: sh          $t7, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r15;
L_807987F0:
    // 0x807987F0: b           L_807987FC
    // 0x807987F4: sh          $t8, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r24;
        goto L_807987FC;
    // 0x807987F4: sh          $t8, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r24;
L_807987F8:
    // 0x807987F8: sh          $t9, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r25;
L_807987FC:
    // 0x807987FC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80798800: lw          $t9, -0x729C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X729C);
    // 0x80798804: addiu       $a0, $v1, 0x3C
    ctx->r4 = ADD32(ctx->r3, 0X3C);
    // 0x80798808: lhu         $a1, 0x1A($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1A);
    // 0x8079880C: jalr        $t9
    // 0x80798810: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80798810: nop

    after_1:
    // 0x80798814: beq         $v0, $zero, L_80798854
    if (ctx->r2 == 0) {
        // 0x80798818: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80798854;
    }
    // 0x80798818: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8079881C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80798820: lw          $a2, 0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XC);
    // 0x80798824: lw          $a1, 0x1D8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X1D8);
    // 0x80798828: jal         0x80048BE8
    // 0x8079882C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    func_80048BE8(rdram, ctx);
        goto after_2;
    // 0x8079882C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_2:
    // 0x80798830: jal         0x807986FC
    // 0x80798834: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807986FC(rdram, ctx);
        goto after_3;
    // 0x80798834: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80798838: jal         0x80067E68
    // 0x8079883C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80067E68(rdram, ctx);
        goto after_4;
    // 0x8079883C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_4:
    // 0x80798840: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80798844: jal         0x80067818
    // 0x80798848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x80798848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8079884C: jal         0x800447C8
    // 0x80798850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_800447C8(rdram, ctx);
        goto after_6;
    // 0x80798850: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_80798854:
    // 0x80798854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80798858: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079885C: jr          $ra
    // 0x80798860: nop

    return;
    // 0x80798860: nop

;}
RECOMP_FUNC void func_80065200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065200: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80065204: bne         $at, $zero, L_8006527C
    if (ctx->r1 != 0) {
        // 0x80065208: addiu       $v1, $a0, 0x2
        ctx->r3 = ADD32(ctx->r4, 0X2);
            goto L_8006527C;
    }
    // 0x80065208: addiu       $v1, $a0, 0x2
    ctx->r3 = ADD32(ctx->r4, 0X2);
    // 0x8006520C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065210: addiu       $t3, $a1, -0x1
    ctx->r11 = ADD32(ctx->r5, -0X1);
L_80065214:
    // 0x80065214: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80065218: bltz        $a3, L_80065264
    if (SIGNED(ctx->r7) < 0) {
        // 0x8006521C: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80065264;
    }
    // 0x8006521C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80065220: sll         $t6, $a3, 1
    ctx->r14 = S32(ctx->r7 << 1);
    // 0x80065224: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80065228: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8006522C: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x80065230: addu        $t1, $a0, $t9
    ctx->r9 = ADD32(ctx->r4, ctx->r25);
    // 0x80065234: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80065238: beq         $at, $zero, L_80065264
    if (ctx->r1 == 0) {
        // 0x8006523C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80065264;
    }
    // 0x8006523C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80065240: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80065244: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_80065248:
    // 0x80065248: addiu       $t1, $t1, -0x2
    ctx->r9 = ADD32(ctx->r9, -0X2);
    // 0x8006524C: bltz        $a2, L_80065264
    if (SIGNED(ctx->r6) < 0) {
        // 0x80065250: sh          $t2, 0x4($t1)
        MEM_H(0X4, ctx->r9) = ctx->r10;
            goto L_80065264;
    }
    // 0x80065250: sh          $t2, 0x4($t1)
    MEM_H(0X4, ctx->r9) = ctx->r10;
    // 0x80065254: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80065258: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8006525C: bnel        $at, $zero, L_80065248
    if (ctx->r1 != 0) {
        // 0x80065260: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_80065248;
    }
    goto skip_0;
    // 0x80065260: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    skip_0:
L_80065264:
    // 0x80065264: sll         $t4, $a2, 1
    ctx->r12 = S32(ctx->r6 << 1);
    // 0x80065268: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006526C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80065270: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80065274: bne         $a3, $t3, L_80065214
    if (ctx->r7 != ctx->r11) {
        // 0x80065278: sh          $v0, 0x2($t5)
        MEM_H(0X2, ctx->r13) = ctx->r2;
            goto L_80065214;
    }
    // 0x80065278: sh          $v0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r2;
L_8006527C:
    // 0x8006527C: jr          $ra
    // 0x80065280: nop

    return;
    // 0x80065280: nop

;}
RECOMP_FUNC void func_80030F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030F38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80030F3C: lw          $t7, 0x78($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X78);
    // 0x80030F40: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80030F44: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80030F48: beq         $t7, $zero, L_80030F94
    if (ctx->r15 == 0) {
        // 0x80030F4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030F94;
    }
    // 0x80030F4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030F50: lbu         $t0, 0x30($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X30);
    // 0x80030F54: addiu       $t9, $t9, 0x3450
    ctx->r25 = ADD32(ctx->r25, 0X3450);
    // 0x80030F58: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80030F5C: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x80030F60: bne         $t0, $at, L_80030F78
    if (ctx->r8 != ctx->r1) {
        // 0x80030F64: sw          $t9, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r25;
            goto L_80030F78;
    }
    // 0x80030F64: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80030F68: jal         0x8002DB14
    // 0x80030F6C: nop

    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x80030F6C: nop

    after_0:
    // 0x80030F70: b           L_80030F88
    // 0x80030F74: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
        goto L_80030F88;
    // 0x80030F74: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80030F78:
    // 0x80030F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030F7C: jal         0x8002DBE4
    // 0x80030F80: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x80030F80: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80030F84: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
L_80030F88:
    // 0x80030F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030F8C: b           L_80030F94
    // 0x80030F90: sw          $zero, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = 0;
        goto L_80030F94;
    // 0x80030F90: sw          $zero, 0xD8($t1)
    MEM_W(0XD8, ctx->r9) = 0;
L_80030F94:
    // 0x80030F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030F9C: jr          $ra
    // 0x80030FA0: nop

    return;
    // 0x80030FA0: nop

;}
RECOMP_FUNC void func_8079BC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BC38: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8079BC3C: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x8079BC40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8079BC44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079BC48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079BC4C: lbu         $t7, 0x41($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X41);
    // 0x8079BC50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8079BC54: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8079BC58: beq         $t7, $zero, L_8079BCAC
    if (ctx->r15 == 0) {
        // 0x8079BC5C: nop
    
            goto L_8079BCAC;
    }
    // 0x8079BC5C: nop

    // 0x8079BC60: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8079BC64: add.s       $f0, $f2, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8079BC68: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8079BC6C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8079BC70: jal         0x8005FE48
    // 0x8079BC74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8079BC74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8079BC78: jal         0x800447C8
    // 0x8079BC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8079BC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079BC80: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8079BC84: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x8079BC88: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x8079BC8C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8079BC90: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8079BC94: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8079BC98: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x8079BC9C: jalr        $t9
    // 0x8079BCA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8079BCA0: nop

    after_2:
    // 0x8079BCA4: b           L_8079BCFC
    // 0x8079BCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079BCFC;
    // 0x8079BCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079BCAC:
    // 0x8079BCAC: beql        $v0, $zero, L_8079BCFC
    if (ctx->r2 == 0) {
        // 0x8079BCB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8079BCFC;
    }
    goto skip_0;
    // 0x8079BCB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8079BCB4: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8079BCB8: lwc1        $f2, 0x40($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8079BCBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8079BCC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079BCC4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8079BCC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079BCCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8079BCD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8079BCD4: bc1f        L_8079BCF0
    if (!c1cs) {
        // 0x8079BCD8: nop
    
            goto L_8079BCF0;
    }
    // 0x8079BCD8: nop

    // 0x8079BCDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8079BCE0: nop

    // 0x8079BCE4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8079BCE8: b           L_8079BCF8
    // 0x8079BCEC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_8079BCF8;
    // 0x8079BCEC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_8079BCF0:
    // 0x8079BCF0: jal         0x8079C140
    // 0x8079BCF4: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    func_8079C140(rdram, ctx);
        goto after_3;
    // 0x8079BCF4: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    after_3:
L_8079BCF8:
    // 0x8079BCF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079BCFC:
    // 0x8079BCFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079BD00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8079BD04: jr          $ra
    // 0x8079BD08: nop

    return;
    // 0x8079BD08: nop

;}
RECOMP_FUNC void func_80001264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001264: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001268: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000126C: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80001270: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80001274: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x80001278: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000127C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80001280: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80001284: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80001288: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000128C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80001290: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80001294: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80001298: lbu         $t9, 0x1B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1B);
    // 0x8000129C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800012A0: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x800012A4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800012A8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800012AC: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800012B0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x800012B4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800012B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800012BC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800012C0: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800012C4: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x800012C8: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x800012CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800012D0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800012D4: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x800012D8: lh          $a3, 0x10($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X10);
    // 0x800012DC: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x800012E0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800012E4: addiu       $a1, $zero, 0xC80
    ctx->r5 = ADD32(0, 0XC80);
    // 0x800012E8: jal         0x80001338
    // 0x800012EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80001338(rdram, ctx);
        goto after_0;
    // 0x800012EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800012F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800012F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800012F8: lh          $t4, 0x32($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X32);
    // 0x800012FC: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x80001300: beql        $a3, $zero, L_80001328
    if (ctx->r7 == 0) {
        // 0x80001304: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80001328;
    }
    goto skip_0;
    // 0x80001304: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80001308: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x8000130C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80001310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80001314: addiu       $a1, $a1, 0xC80
    ctx->r5 = ADD32(ctx->r5, 0XC80);
    // 0x80001318: jal         0x80001338
    // 0x8000131C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80001338(rdram, ctx);
        goto after_1;
    // 0x8000131C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // 0x80001320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80001324: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80001328:
    // 0x80001328: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000132C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80001330: jr          $ra
    // 0x80001334: nop

    return;
    // 0x80001334: nop

;}
RECOMP_FUNC void func_8006C848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C848: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C84C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C850: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006C854: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8006C858: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006C85C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8006C860: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006C864: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8006C868: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8006C86C: lw          $t9, 0x78($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X78);
    // 0x8006C870: jalr        $t9
    // 0x8006C874: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8006C874: nop

    after_0:
    // 0x8006C878: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8006C87C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8006C880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006C884: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8006C888: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006C88C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006C890: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x8006C894: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x8006C898: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x8006C89C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C8A0: swc1        $f16, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f16.u32l;
    // 0x8006C8A4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006C8A8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006C8AC: c.eq.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl == ctx->f0.fl;
    // 0x8006C8B0: nop

    // 0x8006C8B4: bc1t        L_8006C8C0
    if (c1cs) {
        // 0x8006C8B8: nop
    
            goto L_8006C8C0;
    }
    // 0x8006C8B8: nop

    // 0x8006C8BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C8C0:
    // 0x8006C8C0: bnel        $v0, $zero, L_8006C900
    if (ctx->r2 != 0) {
        // 0x8006C8C4: sw          $v0, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->r2;
            goto L_8006C900;
    }
    goto skip_0;
    // 0x8006C8C4: sw          $v0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r2;
    skip_0:
    // 0x8006C8C8: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8006C8CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C8D0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006C8D4: bc1t        L_8006C8E0
    if (c1cs) {
        // 0x8006C8D8: nop
    
            goto L_8006C8E0;
    }
    // 0x8006C8D8: nop

    // 0x8006C8DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C8E0:
    // 0x8006C8E0: bnel        $v0, $zero, L_8006C900
    if (ctx->r2 != 0) {
        // 0x8006C8E4: sw          $v0, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->r2;
            goto L_8006C900;
    }
    goto skip_1;
    // 0x8006C8E4: sw          $v0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r2;
    skip_1:
    // 0x8006C8E8: c.eq.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl == ctx->f12.fl;
    // 0x8006C8EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C8F0: bc1tl       L_8006C900
    if (c1cs) {
        // 0x8006C8F4: sw          $v0, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->r2;
            goto L_8006C900;
    }
    goto skip_2;
    // 0x8006C8F4: sw          $v0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r2;
    skip_2:
    // 0x8006C8F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C8FC: sw          $v0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r2;
L_8006C900:
    // 0x8006C900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006C908: jr          $ra
    // 0x8006C90C: nop

    return;
    // 0x8006C90C: nop

;}
RECOMP_FUNC void func_80059F64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059F64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059F68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80059F6C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059F70: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059F74: lh          $v0, 0x0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X0);
    // 0x80059F78: addiu       $at, $zero, 0x7FFF
    ctx->r1 = ADD32(0, 0X7FFF);
    // 0x80059F7C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80059F80: bne         $v0, $at, L_80059F90
    if (ctx->r2 != ctx->r1) {
        // 0x80059F84: lw          $t7, 0x28($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X28);
            goto L_80059F90;
    }
    // 0x80059F84: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80059F88: b           L_80059FC4
    // 0x80059F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80059FC4;
    // 0x80059F8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059F90:
    // 0x80059F90: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80059F94: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x80059F98: lh          $a2, 0x2($t8)
    ctx->r6 = MEM_H(ctx->r24, 0X2);
    // 0x80059F9C: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80059FA0: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x80059FA4: addiu       $t1, $zero, 0x7D
    ctx->r9 = ADD32(0, 0X7D);
    // 0x80059FA8: addiu       $t2, $zero, 0xA5
    ctx->r10 = ADD32(0, 0XA5);
    // 0x80059FAC: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80059FB0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80059FB4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80059FB8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80059FBC: jal         0x80065BC8
    // 0x80059FC0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80065BC8(rdram, ctx);
        goto after_0;
    // 0x80059FC0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_0:
L_80059FC4:
    // 0x80059FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80059FC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059FCC: jr          $ra
    // 0x80059FD0: nop

    return;
    // 0x80059FD0: nop

;}
RECOMP_FUNC void func_80075120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80075124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007512C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80075130: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80075134: jal         0x800825F0
    // 0x80075138: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x80075138: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007513C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80075140: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80075144: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80075148: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8007514C: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80075150: lw          $t7, 0x248($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X248);
    // 0x80075154: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80075158: jal         0x800825F0
    // 0x8007515C: sw          $a1, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r5;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8007515C: sw          $a1, 0x248($v1)
    MEM_W(0X248, ctx->r3) = ctx->r5;
    after_1:
    // 0x80075160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075168: jr          $ra
    // 0x8007516C: nop

    return;
    // 0x8007516C: nop

;}
RECOMP_FUNC void func_80064DD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064DD0: addiu       $v0, $a0, 0x10
    ctx->r2 = ADD32(ctx->r4, 0X10);
    // 0x80064DD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80064DD8: andi        $t6, $v0, 0xF
    ctx->r14 = ctx->r2 & 0XF;
    // 0x80064DDC: beq         $t6, $zero, L_80064DF4
    if (ctx->r14 == 0) {
        // 0x80064DE0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80064DF4;
    }
    // 0x80064DE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80064DE4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80064DE8: and         $a2, $v0, $at
    ctx->r6 = ctx->r2 & ctx->r1;
    // 0x80064DEC: b           L_80064DF8
    // 0x80064DF0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
        goto L_80064DF8;
    // 0x80064DF0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_80064DF4:
    // 0x80064DF4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80064DF8:
    // 0x80064DF8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80064DFC: addiu       $a1, $v1, -0x6C08
    ctx->r5 = ADD32(ctx->r3, -0X6C08);
    // 0x80064E00: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80064E04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064E08: beq         $v0, $a1, L_80064E5C
    if (ctx->r2 == ctx->r5) {
        // 0x80064E0C: nop
    
            goto L_80064E5C;
    }
    // 0x80064E0C: nop

    // 0x80064E10: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
L_80064E14:
    // 0x80064E14: bnel        $t7, $zero, L_80064E54
    if (ctx->r15 != 0) {
        // 0x80064E18: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80064E54;
    }
    goto skip_0;
    // 0x80064E18: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80064E1C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80064E20: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80064E24: bnel        $at, $zero, L_80064E54
    if (ctx->r1 != 0) {
        // 0x80064E28: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80064E54;
    }
    goto skip_1;
    // 0x80064E28: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x80064E2C: bnel        $a0, $zero, L_80064E40
    if (ctx->r4 != 0) {
        // 0x80064E30: lw          $t8, 0xC($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XC);
            goto L_80064E40;
    }
    goto skip_2;
    // 0x80064E30: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x80064E34: b           L_80064E50
    // 0x80064E38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80064E50;
    // 0x80064E38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80064E3C: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
L_80064E40:
    // 0x80064E40: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80064E44: beql        $at, $zero, L_80064E54
    if (ctx->r1 == 0) {
        // 0x80064E48: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80064E54;
    }
    goto skip_3;
    // 0x80064E48: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_3:
    // 0x80064E4C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80064E50:
    // 0x80064E50: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80064E54:
    // 0x80064E54: bnel        $v0, $a1, L_80064E14
    if (ctx->r2 != ctx->r5) {
        // 0x80064E58: lhu         $t7, 0x2($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X2);
            goto L_80064E14;
    }
    goto skip_4;
    // 0x80064E58: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    skip_4:
L_80064E5C:
    // 0x80064E5C: beq         $a0, $zero, L_80064E74
    if (ctx->r4 == 0) {
        // 0x80064E60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80064E74;
    }
    // 0x80064E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80064E64: jal         0x80064CB8
    // 0x80064E68: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80064CB8(rdram, ctx);
        goto after_0;
    // 0x80064E68: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80064E6C: b           L_80064E78
    // 0x80064E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80064E78;
    // 0x80064E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064E74:
    // 0x80064E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064E78:
    // 0x80064E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80064E7C: jr          $ra
    // 0x80064E80: nop

    return;
    // 0x80064E80: nop

;}
RECOMP_FUNC void func_800327D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800327D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800327D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800327D8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800327DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800327E0: lbu         $t6, 0x111($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X111);
    // 0x800327E4: sb          $zero, 0x154($v0)
    MEM_B(0X154, ctx->r2) = 0;
    // 0x800327E8: beql        $t6, $zero, L_80032844
    if (ctx->r14 == 0) {
        // 0x800327EC: lw          $t7, 0x24($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X24);
            goto L_80032844;
    }
    goto skip_0;
    // 0x800327EC: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    skip_0:
    // 0x800327F0: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800327F4: lwc1        $f4, 0x44($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X44);
    // 0x800327F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800327FC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80032800: nop

    // 0x80032804: bc1t        L_80032830
    if (c1cs) {
        // 0x80032808: nop
    
            goto L_80032830;
    }
    // 0x80032808: nop

    // 0x8003280C: lwc1        $f6, 0x48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X48);
    // 0x80032810: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80032814: nop

    // 0x80032818: bc1t        L_80032830
    if (c1cs) {
        // 0x8003281C: nop
    
            goto L_80032830;
    }
    // 0x8003281C: nop

    // 0x80032820: jal         0x8002F15C
    // 0x80032824: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x80032824: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x80032828: b           L_8003286C
    // 0x8003282C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003286C;
    // 0x8003282C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032830:
    // 0x80032830: jal         0x8002F1D4
    // 0x80032834: nop

    func_8002F1D4(rdram, ctx);
        goto after_1;
    // 0x80032834: nop

    after_1:
    // 0x80032838: b           L_8003286C
    // 0x8003283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003286C;
    // 0x8003283C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032840: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
L_80032844:
    // 0x80032844: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80032848: beq         $t8, $zero, L_80032860
    if (ctx->r24 == 0) {
        // 0x8003284C: nop
    
            goto L_80032860;
    }
    // 0x8003284C: nop

    // 0x80032850: jal         0x8002E110
    // 0x80032854: nop

    func_8002E110(rdram, ctx);
        goto after_2;
    // 0x80032854: nop

    after_2:
    // 0x80032858: b           L_8003286C
    // 0x8003285C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003286C;
    // 0x8003285C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032860:
    // 0x80032860: jal         0x8002DBA8
    // 0x80032864: nop

    func_8002DBA8(rdram, ctx);
        goto after_3;
    // 0x80032864: nop

    after_3:
    // 0x80032868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003286C:
    // 0x8003286C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80032870: jr          $ra
    // 0x80032874: nop

    return;
    // 0x80032874: nop

;}
RECOMP_FUNC void func_8076D964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D964: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8076D968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8076D96C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8076D970: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8076D974: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8076D978: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8076D97C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8076D980: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8076D984: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8076D988: lui         $a1, 0x8077
    ctx->r5 = S32(RELOC_HI16(766, 0X34E8) << 16);
    // 0x8076D98C: addiu       $a1, $a1, -0x328
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(766, 0X34E8));
    // 0x8076D990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8076D994: jal         0x8076D134
    // 0x8076D998: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_8076D134(rdram, ctx);
        goto after_0;
    // 0x8076D998: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8076D99C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076D9A0: jal         0x8076CD88
    // 0x8076D9A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8076CD88(rdram, ctx);
        goto after_1;
    // 0x8076D9A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8076D9A8: lwc1        $f8, 0x38($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8076D9AC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8076D9B0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8076D9B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8076D9B8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8076D9BC: lwc1        $f18, 0x3C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8076D9C0: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8076D9C4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8076D9C8: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8076D9CC: jal         0x80067114
    // 0x8076D9D0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    func_80067114(rdram, ctx);
        goto after_2;
    // 0x8076D9D0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    after_2:
    // 0x8076D9D4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8076D9D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8076D9DC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8076D9E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8076D9E4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8076D9E8: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x8076D9EC: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8076D9F0: sub.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8076D9F4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8076D9F8: jal         0x80067170
    // 0x8076D9FC: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    func_80067170(rdram, ctx);
        goto after_3;
    // 0x8076D9FC: swc1        $f2, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f2.u32l;
    after_3:
    // 0x8076DA00: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8076DA04: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8076DA08: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8076DA0C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8076DA10: jal         0x80066E88
    // 0x8076DA14: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8076DA14: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x8076DA18: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8076DA1C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8076DA20: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8076DA24: jal         0x80066DE4
    // 0x8076DA28: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8076DA28: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x8076DA2C: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8076DA30: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8076DA34: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8076DA38: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x8076DA3C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8076DA40: bnel        $t7, $zero, L_8076DB08
    if (ctx->r15 != 0) {
        // 0x8076DA44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8076DB08;
    }
    goto skip_0;
    // 0x8076DA44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8076DA48: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x8076DA4C: lwc1        $f18, 0x24($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8076DA50: jal         0x80065954
    // 0x8076DA54: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x8076DA54: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_6:
    // 0x8076DA58: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8076DA5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076DA60: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X36C0) << 16);
    // 0x8076DA64: addiu       $v0, $v0, -0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X36C0));
    // 0x8076DA68: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8076DA6C: nop

    // 0x8076DA70: bc1fl       L_8076DAB8
    if (!c1cs) {
        // 0x8076DA74: lw          $v0, 0x40($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X40);
            goto L_8076DAB8;
    }
    goto skip_1;
    // 0x8076DA74: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    skip_1:
    // 0x8076DA78: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8076DA7C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8076DA80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8076DA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076DA88: sw          $t8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r24;
    // 0x8076DA8C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8076DA90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DA94: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8076DA98: sw          $t9, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r25;
    // 0x8076DA9C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8076DAA0: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8076DAA4: jal         0x8076DD8C
    // 0x8076DAA8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    func_8076DD8C(rdram, ctx);
        goto after_7;
    // 0x8076DAA8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    after_7:
    // 0x8076DAAC: b           L_8076DB08
    // 0x8076DAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8076DB08;
    // 0x8076DAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8076DAB4: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
L_8076DAB8:
    // 0x8076DAB8: beq         $v0, $zero, L_8076DAC8
    if (ctx->r2 == 0) {
        // 0x8076DABC: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8076DAC8;
    }
    // 0x8076DABC: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8076DAC0: b           L_8076DB04
    // 0x8076DAC4: sw          $t0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r8;
        goto L_8076DB04;
    // 0x8076DAC4: sw          $t0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r8;
L_8076DAC8:
    // 0x8076DAC8: lui         $v0, 0x8077
    ctx->r2 = S32(RELOC_HI16(766, 0X36C0) << 16);
    // 0x8076DACC: addiu       $v0, $v0, -0x150
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(766, 0X36C0));
    // 0x8076DAD0: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8076DAD4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8076DAD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8076DADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8076DAE0: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8076DAE4: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8076DAE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8076DAEC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8076DAF0: sw          $t2, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r10;
    // 0x8076DAF4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8076DAF8: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8076DAFC: jal         0x8076DD8C
    // 0x8076DB00: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    func_8076DD8C(rdram, ctx);
        goto after_8;
    // 0x8076DB00: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    after_8:
L_8076DB04:
    // 0x8076DB04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8076DB08:
    // 0x8076DB08: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8076DB0C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8076DB10: jr          $ra
    // 0x8076DB14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8076DB14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8079B8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B8B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079B8B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8079B8B8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8079B8BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8079B8C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8079B8C4: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8079B8C8: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(829, 0XC20) << 16);
    // 0x8079B8CC: lui         $a1, 0x41A7
    ctx->r5 = S32(0X41A7 << 16);
    // 0x8079B8D0: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x8079B8D4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8079B8D8: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x8079B8DC: addiu       $a0, $a0, -0x3C70
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(829, 0XC20));
    // 0x8079B8E0: jal         0x80046804
    // 0x8079B8E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8079B8E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8079B8E8: bne         $v0, $zero, L_8079B8F8
    if (ctx->r2 != 0) {
        // 0x8079B8EC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8079B8F8;
    }
    // 0x8079B8EC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8079B8F0: b           L_8079B940
    // 0x8079B8F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079B940;
    // 0x8079B8F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079B8F8:
    // 0x8079B8F8: jal         0x80047090
    // 0x8079B8FC: addiu       $a0, $zero, 0x41A7
    ctx->r4 = ADD32(0, 0X41A7);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8079B8FC: addiu       $a0, $zero, 0x41A7
    ctx->r4 = ADD32(0, 0X41A7);
    after_1:
    // 0x8079B900: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x8079B904: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x8079B908: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x8079B90C: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8079B910: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8079B914: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    // 0x8079B918: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8079B91C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8079B920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079B924: jal         0x80052BA4
    // 0x8079B928: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    func_80052BA4(rdram, ctx);
        goto after_2;
    // 0x8079B928: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_2:
    // 0x8079B92C: jal         0x8005FDC4
    // 0x8079B930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x8079B930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079B934: jal         0x8079C074
    // 0x8079B938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079C074(rdram, ctx);
        goto after_4;
    // 0x8079B938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8079B93C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8079B940:
    // 0x8079B940: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8079B944: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8079B948: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8079B94C: jr          $ra
    // 0x8079B950: nop

    return;
    // 0x8079B950: nop

;}
RECOMP_FUNC void func_8053319C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053319C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805331A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805331A4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805331A8: lui         $t6, 0x8053
    ctx->r14 = S32(RELOC_HI16(345, 0X4C0) << 16);
    // 0x805331AC: addiu       $t6, $t6, 0x2F90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(345, 0X4C0));
    // 0x805331B0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805331B4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805331B8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x805331BC: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x805331C0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x805331C4: jal         0x8005FCA8
    // 0x805331C8: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x805331C8: sh          $t9, 0x12($t1)
    MEM_H(0X12, ctx->r9) = ctx->r25;
    after_0:
    // 0x805331CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805331D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805331D4: jr          $ra
    // 0x805331D8: nop

    return;
    // 0x805331D8: nop

;}
RECOMP_FUNC void func_8042A464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A464: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042A468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042A46C: jal         0x8042A444
    // 0x8042A470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042A444(rdram, ctx);
        goto after_0;
    // 0x8042A470: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042A474: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8042A478: lw          $t6, 0x7EA8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7EA8);
    // 0x8042A47C: addiu       $at, $zero, 0x100
    ctx->r1 = ADD32(0, 0X100);
    // 0x8042A480: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042A484: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8042A488: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8042A48C: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8042A490: bne         $t7, $at, L_8042A4D4
    if (ctx->r15 != ctx->r1) {
        // 0x8042A494: andi        $t9, $v0, 0x200
        ctx->r25 = ctx->r2 & 0X200;
            goto L_8042A4D4;
    }
    // 0x8042A494: andi        $t9, $v0, 0x200
    ctx->r25 = ctx->r2 & 0X200;
    // 0x8042A498: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042A49C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042A4A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042A4A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042A4A8: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8042A4AC: add.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8042A4B0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8042A4B4: nop

    // 0x8042A4B8: bc1fl       L_8042A4C8
    if (!c1cs) {
        // 0x8042A4BC: swc1        $f0, 0x4C($a0)
        MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
            goto L_8042A4C8;
    }
    goto skip_0;
    // 0x8042A4BC: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8042A4C0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8042A4C4: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
L_8042A4C8:
    // 0x8042A4C8: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x8042A4CC: b           L_8042A520
    // 0x8042A4D0: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
        goto L_8042A520;
    // 0x8042A4D0: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_8042A4D4:
    // 0x8042A4D4: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8042A4D8: bne         $t9, $at, L_8042A520
    if (ctx->r25 != ctx->r1) {
        // 0x8042A4DC: lui         $t0, 0x800F
        ctx->r8 = S32(0X800F << 16);
            goto L_8042A520;
    }
    // 0x8042A4DC: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8042A4E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042A4E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042A4E8: lwc1        $f6, 0x4C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8042A4EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8042A4F0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042A4F4: sub.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8042A4F8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042A4FC: nop

    // 0x8042A500: bc1fl       L_8042A518
    if (!c1cs) {
        // 0x8042A504: swc1        $f0, 0x4C($a0)
        MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
            goto L_8042A518;
    }
    goto skip_1;
    // 0x8042A504: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8042A508: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042A50C: nop

    // 0x8042A510: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8042A514: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
L_8042A518:
    // 0x8042A518: lw          $t0, 0x7EA8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7EA8);
    // 0x8042A51C: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
L_8042A520:
    // 0x8042A520: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042A524: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042A528: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042A52C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042A530: addiu       $at, $zero, 0x800
    ctx->r1 = ADD32(0, 0X800);
    // 0x8042A534: andi        $t1, $v0, 0x800
    ctx->r9 = ctx->r2 & 0X800;
    // 0x8042A538: bne         $t1, $at, L_8042A564
    if (ctx->r9 != ctx->r1) {
        // 0x8042A53C: andi        $t2, $v0, 0x400
        ctx->r10 = ctx->r2 & 0X400;
            goto L_8042A564;
    }
    // 0x8042A53C: andi        $t2, $v0, 0x400
    ctx->r10 = ctx->r2 & 0X400;
    // 0x8042A540: lwc1        $f10, 0x48($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8042A544: add.s       $f0, $f10, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8042A548: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8042A54C: nop

    // 0x8042A550: bc1f        L_8042A55C
    if (!c1cs) {
        // 0x8042A554: nop
    
            goto L_8042A55C;
    }
    // 0x8042A554: nop

    // 0x8042A558: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8042A55C:
    // 0x8042A55C: b           L_8042A594
    // 0x8042A560: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
        goto L_8042A594;
    // 0x8042A560: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
L_8042A564:
    // 0x8042A564: addiu       $at, $zero, 0x400
    ctx->r1 = ADD32(0, 0X400);
    // 0x8042A568: bnel        $t2, $at, L_8042A598
    if (ctx->r10 != ctx->r1) {
        // 0x8042A56C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042A598;
    }
    goto skip_2;
    // 0x8042A56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8042A570: lwc1        $f16, 0x48($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8042A574: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8042A578: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8042A57C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8042A580: nop

    // 0x8042A584: bc1fl       L_8042A594
    if (!c1cs) {
        // 0x8042A588: swc1        $f0, 0x48($a0)
        MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
            goto L_8042A594;
    }
    goto skip_3;
    // 0x8042A588: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
    skip_3:
    // 0x8042A58C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8042A590: swc1        $f0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f0.u32l;
L_8042A594:
    // 0x8042A594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042A598:
    // 0x8042A598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042A59C: jr          $ra
    // 0x8042A5A0: nop

    return;
    // 0x8042A5A0: nop

;}
RECOMP_FUNC void func_80780A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80780A24: lw          $t6, 0x188($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X188);
    // 0x80780A28: lh          $v0, 0x184($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X184);
    // 0x80780A2C: lw          $a1, 0x16C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X16C);
    // 0x80780A30: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80780A34: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80780A38: lbu         $v1, 0xD($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XD);
    // 0x80780A3C: lbu         $a2, 0x11($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X11);
    // 0x80780A40: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80780A44: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80780A48: slti        $at, $v1, 0x9C
    ctx->r1 = SIGNED(ctx->r3) < 0X9C ? 1 : 0;
    // 0x80780A4C: beq         $at, $zero, L_80780A58
    if (ctx->r1 == 0) {
        // 0x80780A50: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80780A58;
    }
    // 0x80780A50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80780A54: addiu       $v1, $zero, 0x9B
    ctx->r3 = ADD32(0, 0X9B);
L_80780A58:
    // 0x80780A58: slti        $at, $a2, 0x64
    ctx->r1 = SIGNED(ctx->r6) < 0X64 ? 1 : 0;
    // 0x80780A5C: bne         $at, $zero, L_80780A68
    if (ctx->r1 != 0) {
        // 0x80780A60: andi        $t1, $v0, 0x3
        ctx->r9 = ctx->r2 & 0X3;
            goto L_80780A68;
    }
    // 0x80780A60: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x80780A64: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
L_80780A68:
    // 0x80780A68: blez        $v0, L_80780C10
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80780A6C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80780C10;
    }
    // 0x80780A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80780A70: beq         $t1, $zero, L_80780AD8
    if (ctx->r9 == 0) {
        // 0x80780A74: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_80780AD8;
    }
    // 0x80780A74: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80780A78: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x80780A7C: addu        $a3, $a0, $t7
    ctx->r7 = ADD32(ctx->r4, ctx->r15);
L_80780A80:
    // 0x80780A80: lw          $t8, 0x188($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X188);
    // 0x80780A84: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80780A88: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80780A8C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780A90: sb          $v1, 0xD($t9)
    MEM_B(0XD, ctx->r25) = ctx->r3;
    // 0x80780A94: lw          $t2, 0x184($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X184);
    // 0x80780A98: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780A9C: sb          $v1, 0xE($t3)
    MEM_B(0XE, ctx->r11) = ctx->r3;
    // 0x80780AA0: lw          $t4, 0x184($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X184);
    // 0x80780AA4: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780AA8: sb          $v1, 0xF($t5)
    MEM_B(0XF, ctx->r13) = ctx->r3;
    // 0x80780AAC: lw          $t6, 0x184($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X184);
    // 0x80780AB0: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780AB4: sb          $a2, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r6;
    // 0x80780AB8: lw          $t8, 0x184($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X184);
    // 0x80780ABC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780AC0: sb          $a2, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r6;
    // 0x80780AC4: lw          $t2, 0x184($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X184);
    // 0x80780AC8: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780ACC: bne         $t0, $a1, L_80780A80
    if (ctx->r8 != ctx->r5) {
        // 0x80780AD0: sb          $a2, 0x13($t3)
        MEM_B(0X13, ctx->r11) = ctx->r6;
            goto L_80780A80;
    }
    // 0x80780AD0: sb          $a2, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r6;
    // 0x80780AD4: beq         $a1, $v0, L_80780C10
    if (ctx->r5 == ctx->r2) {
        // 0x80780AD8: sll         $t4, $a1, 2
        ctx->r12 = S32(ctx->r5 << 2);
            goto L_80780C10;
    }
L_80780AD8:
    // 0x80780AD8: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80780ADC: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80780AE0: addu        $t0, $t5, $a0
    ctx->r8 = ADD32(ctx->r13, ctx->r4);
    // 0x80780AE4: addu        $a3, $a0, $t4
    ctx->r7 = ADD32(ctx->r4, ctx->r12);
L_80780AE8:
    // 0x80780AE8: lw          $t6, 0x188($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X188);
    // 0x80780AEC: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x80780AF0: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780AF4: sb          $v1, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r3;
    // 0x80780AF8: lw          $t8, 0x178($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X178);
    // 0x80780AFC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780B00: sb          $v1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r3;
    // 0x80780B04: lw          $t2, 0x178($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X178);
    // 0x80780B08: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780B0C: sb          $v1, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r3;
    // 0x80780B10: lw          $t4, 0x178($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X178);
    // 0x80780B14: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780B18: sb          $a2, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r6;
    // 0x80780B1C: lw          $t6, 0x178($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X178);
    // 0x80780B20: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780B24: sb          $a2, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r6;
    // 0x80780B28: lw          $t8, 0x178($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X178);
    // 0x80780B2C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780B30: sb          $a2, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r6;
    // 0x80780B34: lw          $t2, 0x17C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B38: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780B3C: sb          $v1, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r3;
    // 0x80780B40: lw          $t4, 0x17C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B44: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780B48: sb          $v1, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r3;
    // 0x80780B4C: lw          $t6, 0x17C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B50: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780B54: sb          $v1, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r3;
    // 0x80780B58: lw          $t8, 0x17C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B5C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780B60: sb          $a2, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r6;
    // 0x80780B64: lw          $t2, 0x17C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B68: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780B6C: sb          $a2, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r6;
    // 0x80780B70: lw          $t4, 0x17C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X17C);
    // 0x80780B74: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780B78: sb          $a2, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r6;
    // 0x80780B7C: lw          $t6, 0x180($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X180);
    // 0x80780B80: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780B84: sb          $v1, 0xD($t7)
    MEM_B(0XD, ctx->r15) = ctx->r3;
    // 0x80780B88: lw          $t8, 0x180($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X180);
    // 0x80780B8C: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780B90: sb          $v1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r3;
    // 0x80780B94: lw          $t2, 0x180($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X180);
    // 0x80780B98: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780B9C: sb          $v1, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r3;
    // 0x80780BA0: lw          $t4, 0x180($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X180);
    // 0x80780BA4: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780BA8: sb          $a2, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r6;
    // 0x80780BAC: lw          $t6, 0x180($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X180);
    // 0x80780BB0: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780BB4: sb          $a2, 0x12($t7)
    MEM_B(0X12, ctx->r15) = ctx->r6;
    // 0x80780BB8: lw          $t8, 0x180($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X180);
    // 0x80780BBC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780BC0: sb          $a2, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r6;
    // 0x80780BC4: lw          $t2, 0x184($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X184);
    // 0x80780BC8: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780BCC: sb          $v1, 0xD($t3)
    MEM_B(0XD, ctx->r11) = ctx->r3;
    // 0x80780BD0: lw          $t4, 0x184($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X184);
    // 0x80780BD4: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780BD8: sb          $v1, 0xE($t5)
    MEM_B(0XE, ctx->r13) = ctx->r3;
    // 0x80780BDC: lw          $t6, 0x184($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X184);
    // 0x80780BE0: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x80780BE4: sb          $v1, 0xF($t7)
    MEM_B(0XF, ctx->r15) = ctx->r3;
    // 0x80780BE8: lw          $t8, 0x184($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X184);
    // 0x80780BEC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x80780BF0: sb          $a2, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r6;
    // 0x80780BF4: lw          $t2, 0x184($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X184);
    // 0x80780BF8: lw          $t3, 0x16C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X16C);
    // 0x80780BFC: sb          $a2, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r6;
    // 0x80780C00: lw          $t4, 0x184($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X184);
    // 0x80780C04: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x80780C08: bne         $a3, $t0, L_80780AE8
    if (ctx->r7 != ctx->r8) {
        // 0x80780C0C: sb          $a2, 0x13($t5)
        MEM_B(0X13, ctx->r13) = ctx->r6;
            goto L_80780AE8;
    }
    // 0x80780C0C: sb          $a2, 0x13($t5)
    MEM_B(0X13, ctx->r13) = ctx->r6;
L_80780C10:
    // 0x80780C10: jr          $ra
    // 0x80780C14: nop

    return;
    // 0x80780C14: nop

;}
RECOMP_FUNC void func_8043DC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DC00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043DC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043DC08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043DC0C: jal         0x8004700C
    // 0x8043DC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043DC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8043DC14: beql        $v0, $zero, L_8043DCCC
    if (ctx->r2 == 0) {
        // 0x8043DC18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8043DCCC;
    }
    goto skip_0;
    // 0x8043DC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8043DC1C: lw          $a0, 0x1F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1F4);
    // 0x8043DC20: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x8043DC24: lhu         $a1, 0x8($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X8);
    // 0x8043DC28: lhu         $t8, 0x12BC($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X12BC);
    // 0x8043DC2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043DC30: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8043DC34: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8043DC38: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8043DC3C: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8043DC40: lhu         $t7, 0x1200($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1200);
    // 0x8043DC44: lbu         $t9, 0x1202($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1202);
    // 0x8043DC48: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x8043DC4C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8043DC50: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8043DC54: beq         $at, $zero, L_8043DC6C
    if (ctx->r1 == 0) {
        // 0x8043DC58: andi        $a3, $a3, 0xFFFF
        ctx->r7 = ctx->r7 & 0XFFFF;
            goto L_8043DC6C;
    }
    // 0x8043DC58: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x8043DC5C: jal         0x8043DA34
    // 0x8043DC60: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    func_8043DA34(rdram, ctx);
        goto after_1;
    // 0x8043DC60: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_1:
    // 0x8043DC64: b           L_8043DCCC
    // 0x8043DC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043DCCC;
    // 0x8043DC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043DC6C:
    // 0x8043DC6C: sll         $t0, $a3, 4
    ctx->r8 = S32(ctx->r7 << 4);
    // 0x8043DC70: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x8043DC74: lbu         $t2, 0x209($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X209);
    // 0x8043DC78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043DC7C: srl         $t3, $t2, 4
    ctx->r11 = S32(U32(ctx->r10) >> 4);
    // 0x8043DC80: bnel        $t3, $zero, L_8043DC9C
    if (ctx->r11 != 0) {
        // 0x8043DC84: lbu         $t4, 0x1FA($a2)
        ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
            goto L_8043DC9C;
    }
    goto skip_1;
    // 0x8043DC84: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
    skip_1:
    // 0x8043DC88: jal         0x8043DBBC
    // 0x8043DC8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8043DBBC(rdram, ctx);
        goto after_2;
    // 0x8043DC8C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x8043DC90: b           L_8043DCCC
    // 0x8043DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043DCCC;
    // 0x8043DC94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DC98: lbu         $t4, 0x1FA($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X1FA);
L_8043DC9C:
    // 0x8043DC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8043DCA0: bne         $t4, $zero, L_8043DCC0
    if (ctx->r12 != 0) {
        // 0x8043DCA4: nop
    
            goto L_8043DCC0;
    }
    // 0x8043DCA4: nop

    // 0x8043DCA8: lbu         $t5, 0x1F9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X1F9);
    // 0x8043DCAC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8043DCB0: bne         $t5, $zero, L_8043DCC0
    if (ctx->r13 != 0) {
        // 0x8043DCB4: nop
    
            goto L_8043DCC0;
    }
    // 0x8043DCB4: nop

    // 0x8043DCB8: b           L_8043DCC8
    // 0x8043DCBC: sh          $t6, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r14;
        goto L_8043DCC8;
    // 0x8043DCBC: sh          $t6, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r14;
L_8043DCC0:
    // 0x8043DCC0: jal         0x8043DA9C
    // 0x8043DCC4: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    func_8043DA9C(rdram, ctx);
        goto after_3;
    // 0x8043DCC4: andi        $a1, $a3, 0xFFFF
    ctx->r5 = ctx->r7 & 0XFFFF;
    after_3:
L_8043DCC8:
    // 0x8043DCC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043DCCC:
    // 0x8043DCCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043DCD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043DCD4: jr          $ra
    // 0x8043DCD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8043DCD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_80078980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078988: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007898C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80078990: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80078994: jal         0x80084820
    // 0x80078998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_0;
    // 0x80078998: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007899C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800789A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800789A4: jal         0x80084820
    // 0x800789A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    _blkclr(rdram, ctx);
        goto after_1;
    // 0x800789A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x800789AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800789B0: lui         $t7, 0x8008
    ctx->r15 = S32(0X8008 << 16);
    // 0x800789B4: addiu       $t7, $t7, -0x7808
    ctx->r15 = ADD32(ctx->r15, -0X7808);
    // 0x800789B8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800789BC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800789C0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800789C4: lbu         $t8, 0x8($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X8);
    // 0x800789C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800789CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800789D0: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x800789D4: sb          $t9, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r25;
    // 0x800789D8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800789DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800789E0: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800789E4: swc1        $f2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f2.u32l;
    // 0x800789E8: swc1        $f2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f2.u32l;
    // 0x800789EC: sb          $t0, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r8;
    // 0x800789F0: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800789F4: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800789F8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800789FC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078A00: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80078A04: sb          $zero, 0x24($a0)
    MEM_B(0X24, ctx->r4) = 0;
    // 0x80078A08: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x80078A0C: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x80078A10: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x80078A14: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x80078A18: sb          $v1, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = ctx->r3;
    // 0x80078A1C: sb          $v1, 0x2D($a0)
    MEM_B(0X2D, ctx->r4) = ctx->r3;
    // 0x80078A20: sb          $v1, 0x2E($a0)
    MEM_B(0X2E, ctx->r4) = ctx->r3;
    // 0x80078A24: sb          $v1, 0x2F($a0)
    MEM_B(0X2F, ctx->r4) = ctx->r3;
    // 0x80078A28: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    // 0x80078A2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078A30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078A34: jr          $ra
    // 0x80078A38: nop

    return;
    // 0x80078A38: nop

    // 0x80078A3C: nop

;}
RECOMP_FUNC void func_807B8F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8F6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B8F70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B8F74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B8F78: jal         0x800694BC
    // 0x807B8F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800694BC(rdram, ctx);
        goto after_0;
    // 0x807B8F7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x807B8F80: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x807B8F84: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x807B8F88: sw          $zero, 0x8($t7)
    MEM_W(0X8, ctx->r15) = 0;
    // 0x807B8F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B8F90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B8F94: jr          $ra
    // 0x807B8F98: nop

    return;
    // 0x807B8F98: nop

;}
RECOMP_FUNC void func_8079393C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079393C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80793940: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80793944: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80793948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079394C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80793950: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80793954: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80793958: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(817, 0X79EC) << 16);
    // 0x8079395C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80793960: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80793964: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80793968: lw          $t9, 0x7D3C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(817, 0X79EC));
    // 0x8079396C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80793970: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80793974: jal         0x80790378
    // 0x80793978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790378(rdram, ctx);
        goto after_0;
    // 0x80793978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079397C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80793980: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80793984: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80793988: beql        $v0, $at, L_807939B0
    if (ctx->r2 == ctx->r1) {
        // 0x8079398C: addiu       $t0, $v0, -0x6
        ctx->r8 = ADD32(ctx->r2, -0X6);
            goto L_807939B0;
    }
    goto skip_0;
    // 0x8079398C: addiu       $t0, $v0, -0x6
    ctx->r8 = ADD32(ctx->r2, -0X6);
    skip_0:
    // 0x80793990: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80793994: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80793998: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8079399C: jal         0x80790434
    // 0x807939A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790434(rdram, ctx);
        goto after_1;
    // 0x807939A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x807939A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807939A8: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x807939AC: addiu       $t0, $v0, -0x6
    ctx->r8 = ADD32(ctx->r2, -0X6);
L_807939B0:
    // 0x807939B0: sltiu       $at, $t0, 0x1B
    ctx->r1 = ctx->r8 < 0X1B ? 1 : 0;
    // 0x807939B4: beq         $at, $zero, L_80793A18
    if (ctx->r1 == 0) {
        // 0x807939B8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80793A18;
    }
    // 0x807939B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x807939BC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B18) << 16);
    // 0x807939C0: addu        $at, $at, $t0
    gpr jr_addend_807939C8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x807939C4: lw          $t0, 0x7E68($at)
    ctx->r8 = ADD32(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B18));
    // 0x807939C8: jr          $t0
    // 0x807939CC: nop

    switch (jr_addend_807939C8 >> 2) {
        case 0: goto L_807939F0; break;
        case 1: goto L_80793A18; break;
        case 2: goto L_80793A18; break;
        case 3: goto L_80793A00; break;
        case 4: goto L_80793A18; break;
        case 5: goto L_80793A18; break;
        case 6: goto L_80793A18; break;
        case 7: goto L_80793A18; break;
        case 8: goto L_80793A18; break;
        case 9: goto L_80793A18; break;
        case 10: goto L_80793A18; break;
        case 11: goto L_80793A18; break;
        case 12: goto L_80793A18; break;
        case 13: goto L_80793A18; break;
        case 14: goto L_80793A18; break;
        case 15: goto L_80793A18; break;
        case 16: goto L_80793A10; break;
        case 17: goto L_80793A18; break;
        case 18: goto L_80793A18; break;
        case 19: goto L_80793A18; break;
        case 20: goto L_80793A18; break;
        case 21: goto L_80793A18; break;
        case 22: goto L_807939E0; break;
        case 23: goto L_80793A18; break;
        case 24: goto L_80793A18; break;
        case 25: goto L_80793A18; break;
        case 26: goto L_807939D0; break;
        default: switch_error(__func__, 0x807939C8, 0x80797E68);
    }
    // 0x807939CC: nop

L_807939D0:
    // 0x807939D0: jal         0x807907AC
    // 0x807939D4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    func_807907AC(rdram, ctx);
        goto after_2;
    // 0x807939D4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_2:
    // 0x807939D8: b           L_80793A1C
    // 0x807939DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80793A1C;
    // 0x807939DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807939E0:
    // 0x807939E0: jal         0x807907AC
    // 0x807939E4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    func_807907AC(rdram, ctx);
        goto after_3;
    // 0x807939E4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_3:
    // 0x807939E8: b           L_80793A1C
    // 0x807939EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80793A1C;
    // 0x807939EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807939F0:
    // 0x807939F0: jal         0x807907AC
    // 0x807939F4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    func_807907AC(rdram, ctx);
        goto after_4;
    // 0x807939F4: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    after_4:
    // 0x807939F8: b           L_80793A1C
    // 0x807939FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80793A1C;
    // 0x807939FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80793A00:
    // 0x80793A00: jal         0x807907AC
    // 0x80793A04: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    func_807907AC(rdram, ctx);
        goto after_5;
    // 0x80793A04: addiu       $a1, $zero, 0xB3
    ctx->r5 = ADD32(0, 0XB3);
    after_5:
    // 0x80793A08: b           L_80793A1C
    // 0x80793A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80793A1C;
    // 0x80793A0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80793A10:
    // 0x80793A10: jal         0x807907AC
    // 0x80793A14: addiu       $a1, $zero, 0x291
    ctx->r5 = ADD32(0, 0X291);
    func_807907AC(rdram, ctx);
        goto after_6;
    // 0x80793A14: addiu       $a1, $zero, 0x291
    ctx->r5 = ADD32(0, 0X291);
    after_6:
L_80793A18:
    // 0x80793A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80793A1C:
    // 0x80793A1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80793A20: jr          $ra
    // 0x80793A24: nop

    return;
    // 0x80793A24: nop

    // 0x80793A28: nop

    // 0x80793A2C: nop

;}
RECOMP_FUNC void func_807B61D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B61D4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x807B61D8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807B61DC: lw          $t6, -0x7250($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7250);
    // 0x807B61E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B61E4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B61E8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B61EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B61F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B61F4: sltiu       $at, $t6, 0x6
    ctx->r1 = ctx->r14 < 0X6 ? 1 : 0;
    // 0x807B61F8: bne         $at, $zero, L_807B6208
    if (ctx->r1 != 0) {
        // 0x807B61FC: lw          $s3, 0x10($a0)
        ctx->r19 = MEM_W(ctx->r4, 0X10);
            goto L_807B6208;
    }
    // 0x807B61FC: lw          $s3, 0x10($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X10);
    // 0x807B6200: jal         0x807B56F0
    // 0x807B6204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_807B56F0(rdram, ctx);
        goto after_0;
    // 0x807B6204: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
L_807B6208:
    // 0x807B6208: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B620C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B6210:
    // 0x807B6210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B6214: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B6218: jal         0x8005C27C
    // 0x807B621C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B621C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_1:
    // 0x807B6220: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B6224: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x807B6228: bnel        $at, $zero, L_807B6210
    if (ctx->r1 != 0) {
        // 0x807B622C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B6210;
    }
    goto skip_0;
    // 0x807B622C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x807B6230: lui         $s1, 0x807B
    ctx->r17 = S32(RELOC_HI16(880, 0X2E88) << 16);
    // 0x807B6234: addiu       $s1, $s1, 0x7688
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(880, 0X2E88));
    // 0x807B6238: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B623C: addiu       $s2, $zero, 0x1000
    ctx->r18 = ADD32(0, 0X1000);
    // 0x807B6240: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
L_807B6244:
    // 0x807B6244: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x807B6248: lhu         $a1, 0x0($t8)
    ctx->r5 = MEM_HU(ctx->r24, 0X0);
    // 0x807B624C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B6250: sll         $a2, $s0, 3
    ctx->r6 = S32(ctx->r16 << 3);
    // 0x807B6254: bne         $s2, $a1, L_807B6264
    if (ctx->r18 != ctx->r5) {
        // 0x807B6258: nop
    
            goto L_807B6264;
    }
    // 0x807B6258: nop

    // 0x807B625C: b           L_807B626C
    // 0x807B6260: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
        goto L_807B626C;
    // 0x807B6260: addiu       $s0, $zero, 0x10
    ctx->r16 = ADD32(0, 0X10);
L_807B6264:
    // 0x807B6264: jal         0x8005C27C
    // 0x807B6268: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x807B6268: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_2:
L_807B626C:
    // 0x807B626C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B6270: slti        $at, $s0, 0x10
    ctx->r1 = SIGNED(ctx->r16) < 0X10 ? 1 : 0;
    // 0x807B6274: bnel        $at, $zero, L_807B6244
    if (ctx->r1 != 0) {
        // 0x807B6278: sll         $t7, $s0, 1
        ctx->r15 = S32(ctx->r16 << 1);
            goto L_807B6244;
    }
    goto skip_1;
    // 0x807B6278: sll         $t7, $s0, 1
    ctx->r15 = S32(ctx->r16 << 1);
    skip_1:
    // 0x807B627C: jal         0x807B4A74
    // 0x807B6280: nop

    func_807B4A74(rdram, ctx);
        goto after_3;
    // 0x807B6280: nop

    after_3:
    // 0x807B6284: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x807B6288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B628C: jal         0x807B4B3C
    // 0x807B6290: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_4;
    // 0x807B6290: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x807B6294: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x807B6298: addiu       $s1, $zero, 0x50
    ctx->r17 = ADD32(0, 0X50);
    // 0x807B629C: addiu       $s0, $zero, 0x70
    ctx->r16 = ADD32(0, 0X70);
L_807B62A0:
    // 0x807B62A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B62A4: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x807B62A8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B62AC: jal         0x8005C27C
    // 0x807B62B0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B62B0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_5:
    // 0x807B62B4: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x807B62B8: bne         $s1, $s0, L_807B62A0
    if (ctx->r17 != ctx->r16) {
        // 0x807B62BC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_807B62A0;
    }
    // 0x807B62BC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B62C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B62C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B62C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B62CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B62D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B62D4: jr          $ra
    // 0x807B62D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x807B62D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_804CC340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC340: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CC344: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x804CC348: lw          $v0, 0x7EA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7EA8);
    // 0x804CC34C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CC350: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CC354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804CC358: lhu         $t7, 0x0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X0);
    // 0x804CC35C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CC360: bnel        $t7, $zero, L_804CC3A8
    if (ctx->r15 != 0) {
        // 0x804CC364: sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
            goto L_804CC3A8;
    }
    goto skip_0;
    // 0x804CC364: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    skip_0:
    // 0x804CC368: jal         0x8006593C
    // 0x804CC36C: lb          $a0, 0x2($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X2);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x804CC36C: lb          $a0, 0x2($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X2);
    after_0:
    // 0x804CC370: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x804CC374: beq         $at, $zero, L_804CC3A4
    if (ctx->r1 == 0) {
        // 0x804CC378: lui         $t8, 0x800F
        ctx->r24 = S32(0X800F << 16);
            goto L_804CC3A4;
    }
    // 0x804CC378: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x804CC37C: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x804CC380: jal         0x8006593C
    // 0x804CC384: lb          $a0, 0x3($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X3);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x804CC384: lb          $a0, 0x3($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X3);
    after_1:
    // 0x804CC388: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x804CC38C: beql        $at, $zero, L_804CC3A8
    if (ctx->r1 == 0) {
        // 0x804CC390: sh          $zero, 0xC($s0)
        MEM_H(0XC, ctx->r16) = 0;
            goto L_804CC3A8;
    }
    goto skip_1;
    // 0x804CC390: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
    skip_1:
    // 0x804CC394: lhu         $t9, 0xC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XC);
    // 0x804CC398: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x804CC39C: b           L_804CC3BC
    // 0x804CC3A0: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
        goto L_804CC3BC;
    // 0x804CC3A0: sh          $t0, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r8;
L_804CC3A4:
    // 0x804CC3A4: sh          $zero, 0xC($s0)
    MEM_H(0XC, ctx->r16) = 0;
L_804CC3A8:
    // 0x804CC3A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804CC3AC: jal         0x804CC1B8
    // 0x804CC3B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_804CC1B8(rdram, ctx);
        goto after_2;
    // 0x804CC3B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x804CC3B4: jal         0x804CC2AC
    // 0x804CC3B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804CC2AC(rdram, ctx);
        goto after_3;
    // 0x804CC3B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_804CC3BC:
    // 0x804CC3BC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x804CC3C0: jal         0x8001BF80
    // 0x804CC3C4: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    func_8001BF80(rdram, ctx);
        goto after_4;
    // 0x804CC3C4: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    after_4:
    // 0x804CC3C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CC3CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CC3D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CC3D4: jr          $ra
    // 0x804CC3D8: nop

    return;
    // 0x804CC3D8: nop

;}
RECOMP_FUNC void func_80078E74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078E74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80078E78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80078E7C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x80078E80: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80078E84: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80078E88: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80078E8C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x80078E90: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80078E94: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80078E98: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80078E9C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x80078EA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80078EA4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80078EA8: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80078EAC: lw          $t6, -0x7AF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AF0);
    // 0x80078EB0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80078EB4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80078EB8: lw          $t3, 0x10($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X10);
    // 0x80078EBC: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80078EC0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80078EC4: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80078EC8: addiu       $t9, $t9, -0x6A00
    ctx->r25 = ADD32(ctx->r25, -0X6A00);
    // 0x80078ECC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80078ED0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80078ED4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078ED8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80078EDC: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80078EE0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80078EE4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80078EE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80078EEC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078EF0: lui         $fp, 0x4F
    ctx->r30 = S32(0X4F << 16);
    // 0x80078EF4: lui         $s6, 0x8
    ctx->r22 = S32(0X8 << 16);
    // 0x80078EF8: lui         $s5, 0xF510
    ctx->r21 = S32(0XF510 << 16);
    // 0x80078EFC: lui         $s0, 0x708
    ctx->r16 = S32(0X708 << 16);
    // 0x80078F00: ori         $s0, $s0, 0x200
    ctx->r16 = ctx->r16 | 0X200;
    // 0x80078F04: ori         $s5, $s5, 0xA000
    ctx->r21 = ctx->r21 | 0XA000;
    // 0x80078F08: ori         $s6, $s6, 0x200
    ctx->r22 = ctx->r22 | 0X200;
    // 0x80078F0C: ori         $fp, $fp, 0xC014
    ctx->r30 = ctx->r30 | 0XC014;
    // 0x80078F10: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80078F14: lui         $ra, 0xE450
    ctx->r31 = S32(0XE450 << 16);
    // 0x80078F18: lui         $s7, 0xF200
    ctx->r23 = S32(0XF200 << 16);
    // 0x80078F1C: lui         $s4, 0xE700
    ctx->r20 = S32(0XE700 << 16);
    // 0x80078F20: lui         $s3, 0x700
    ctx->r19 = S32(0X700 << 16);
    // 0x80078F24: lui         $s2, 0xF300
    ctx->r18 = S32(0XF300 << 16);
    // 0x80078F28: lui         $s1, 0xE600
    ctx->r17 = S32(0XE600 << 16);
    // 0x80078F2C: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x80078F30: lui         $t4, 0xFD10
    ctx->r12 = S32(0XFD10 << 16);
L_80078F34:
    // 0x80078F34: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80078F38: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80078F3C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078F40: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078F44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80078F48: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80078F4C: sw          $s0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r16;
    // 0x80078F50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078F54: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80078F58: sw          $s1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r17;
    // 0x80078F5C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80078F60: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078F64: addiu       $a3, $zero, 0x77F
    ctx->r7 = ADD32(0, 0X77F);
    // 0x80078F68: andi        $t8, $a3, 0xFFF
    ctx->r24 = ctx->r7 & 0XFFF;
    // 0x80078F6C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80078F70: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80078F74: or          $t6, $t9, $s3
    ctx->r14 = ctx->r25 | ctx->r19;
    // 0x80078F78: ori         $t7, $t6, 0x1A
    ctx->r15 = ctx->r14 | 0X1A;
    // 0x80078F7C: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80078F80: sw          $s2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r18;
    // 0x80078F84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078F88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80078F8C: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x80078F90: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078F94: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078F98: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80078F9C: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
    // 0x80078FA0: sw          $s6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r22;
    // 0x80078FA4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078FA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80078FAC: sw          $s7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r23;
    // 0x80078FB0: sw          $fp, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r30;
    // 0x80078FB4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078FB8: addiu       $t1, $t2, 0x6
    ctx->r9 = ADD32(ctx->r10, 0X6);
    // 0x80078FBC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80078FC0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80078FC4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80078FC8: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80078FCC: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80078FD0: or          $t6, $t9, $ra
    ctx->r14 = ctx->r25 | ctx->r31;
    // 0x80078FD4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80078FD8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80078FDC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078FE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80078FE4: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x80078FE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80078FEC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80078FF0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80078FF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80078FF8: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80078FFC: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x80079000: lui         $t6, 0xB300
    ctx->r14 = S32(0XB300 << 16);
    // 0x80079004: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80079008: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007900C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80079010: slti        $at, $t1, 0xEB
    ctx->r1 = SIGNED(ctx->r9) < 0XEB ? 1 : 0;
    // 0x80079014: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x80079018: bne         $at, $zero, L_80078F34
    if (ctx->r1 != 0) {
        // 0x8007901C: addiu       $t3, $t3, 0xF00
        ctx->r11 = ADD32(ctx->r11, 0XF00);
            goto L_80078F34;
    }
    // 0x8007901C: addiu       $t3, $t3, 0xF00
    ctx->r11 = ADD32(ctx->r11, 0XF00);
    // 0x80079020: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80079024: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x80079028: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007902C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80079030: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80079034: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x80079038: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007903C: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80079040: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80079044: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x80079048: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007904C: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80079050: jr          $ra
    // 0x80079054: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80079054: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80079058: nop

    // 0x8007905C: nop

;}
RECOMP_FUNC void func_8007C030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C030: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C034: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C038: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8007C03C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8007C040: addiu       $t6, $t6, -0x7B10
    ctx->r14 = ADD32(ctx->r14, -0X7B10);
    // 0x8007C044: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8007C048: jal         0x80090C54
    // 0x8007C04C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    __ull_to_d_recomp(rdram, ctx);
        goto after_0;
    // 0x8007C04C: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    after_0:
    // 0x8007C050: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8007C054: ldc1        $f4, 0x2A90($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, 0X2A90);
    // 0x8007C058: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007C05C: mul.d       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f0.d, ctx->f4.d);
    // 0x8007C060: jal         0x8008BF60
    // 0x8007C064: nop

    osDpGetCounters_recomp(rdram, ctx);
        goto after_1;
    // 0x8007C064: nop

    after_1:
    // 0x8007C068: jal         0x8008C1E0
    // 0x8007C06C: addiu       $a0, $zero, 0x3C0
    ctx->r4 = ADD32(0, 0X3C0);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_2;
    // 0x8007C06C: addiu       $a0, $zero, 0x3C0
    ctx->r4 = ADD32(0, 0X3C0);
    after_2:
    // 0x8007C070: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007C074: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007C078: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8007C07C: bgez        $t7, L_8007C094
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8007C080: cvt.d.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
            goto L_8007C094;
    }
    // 0x8007C080: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007C084: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8007C088: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8007C08C: nop

    // 0x8007C090: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_8007C094:
    // 0x8007C094: mul.d       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f8.d, ctx->f20.d);
    // 0x8007C098: jal         0x80090AE8
    // 0x8007C09C: nop

    __d_to_ull_recomp(rdram, ctx);
        goto after_3;
    // 0x8007C09C: nop

    after_3:
    // 0x8007C0A0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C0A4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C0A8: sw          $v0, -0x2590($at)
    MEM_W(-0X2590, ctx->r1) = ctx->r2;
    // 0x8007C0AC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8007C0B0: sw          $v1, -0x258C($at)
    MEM_W(-0X258C, ctx->r1) = ctx->r3;
    // 0x8007C0B4: bgez        $t8, L_8007C0D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007C0B8: cvt.d.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
            goto L_8007C0D0;
    }
    // 0x8007C0B8: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x8007C0BC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007C0C0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8007C0C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007C0C8: nop

    // 0x8007C0CC: add.d       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f18.d + ctx->f4.d;
L_8007C0D0:
    // 0x8007C0D0: mul.d       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f18.d, ctx->f20.d);
    // 0x8007C0D4: jal         0x80090AE8
    // 0x8007C0D8: nop

    __d_to_ull_recomp(rdram, ctx);
        goto after_4;
    // 0x8007C0D8: nop

    after_4:
    // 0x8007C0DC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007C0E0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C0E4: sw          $v0, -0x2588($at)
    MEM_W(-0X2588, ctx->r1) = ctx->r2;
    // 0x8007C0E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8007C0EC: sw          $v1, -0x2584($at)
    MEM_W(-0X2584, ctx->r1) = ctx->r3;
    // 0x8007C0F0: bgez        $t9, L_8007C10C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007C0F4: cvt.d.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
            goto L_8007C10C;
    }
    // 0x8007C0F4: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x8007C0F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007C0FC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8007C100: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8007C104: nop

    // 0x8007C108: add.d       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f10.d + ctx->f8.d;
L_8007C10C:
    // 0x8007C10C: mul.d       $f12, $f10, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f10.d, ctx->f20.d);
    // 0x8007C110: jal         0x80090AE8
    // 0x8007C114: nop

    __d_to_ull_recomp(rdram, ctx);
        goto after_5;
    // 0x8007C114: nop

    after_5:
    // 0x8007C118: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8007C11C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C120: sw          $v0, -0x2580($at)
    MEM_W(-0X2580, ctx->r1) = ctx->r2;
    // 0x8007C124: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8007C128: sw          $v1, -0x257C($at)
    MEM_W(-0X257C, ctx->r1) = ctx->r3;
    // 0x8007C12C: bgez        $t0, L_8007C148
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007C130: cvt.d.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
            goto L_8007C148;
    }
    // 0x8007C130: cvt.d.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.d = CVT_D_W(ctx->f16.u32l);
    // 0x8007C134: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007C138: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8007C13C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8007C140: nop

    // 0x8007C144: add.d       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f4.d + ctx->f18.d;
L_8007C148:
    // 0x8007C148: mul.d       $f12, $f4, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f12.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x8007C14C: jal         0x80090AE8
    // 0x8007C150: nop

    __d_to_ull_recomp(rdram, ctx);
        goto after_6;
    // 0x8007C150: nop

    after_6:
    // 0x8007C154: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8007C158: sw          $v0, -0x2578($at)
    MEM_W(-0X2578, ctx->r1) = ctx->r2;
    // 0x8007C15C: sw          $v1, -0x2574($at)
    MEM_W(-0X2574, ctx->r1) = ctx->r3;
    // 0x8007C160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007C164: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8007C168: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8007C16C: jr          $ra
    // 0x8007C170: nop

    return;
    // 0x8007C170: nop

;}
RECOMP_FUNC void func_804A1B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1B44: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x804A1B48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804A1B4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A1B50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1B54: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x804A1B58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A1B5C: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x804A1B60: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X3188) << 16);
    // 0x804A1B64: lwc1        $f10, 0x35C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X3188));
    // 0x804A1B68: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804A1B6C: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804A1B70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1B74: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804A1B78: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x804A1B7C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x804A1B80: nop

    // 0x804A1B84: bc1fl       L_804A1B98
    if (!c1cs) {
        // 0x804A1B88: lw          $a1, 0x3C($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X3C);
            goto L_804A1B98;
    }
    goto skip_0;
    // 0x804A1B88: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
    skip_0:
    // 0x804A1B8C: b           L_804A1BD8
    // 0x804A1B90: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
        goto L_804A1BD8;
    // 0x804A1B90: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x804A1B94: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
L_804A1B98:
    // 0x804A1B98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x804A1B9C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x804A1BA0: jal         0x804A1320
    // 0x804A1BA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_804A1320(rdram, ctx);
        goto after_0;
    // 0x804A1BA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1BA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x804A1BAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804A1BB0: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804A1BB4: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x804A1BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A1BBC: bc1tl       L_804A1BD8
    if (c1cs) {
        // 0x804A1BC0: swc1        $f2, 0x40($a0)
        MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
            goto L_804A1BD8;
    }
    goto skip_1;
    // 0x804A1BC0: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x804A1BC4: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x804A1BC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804A1BCC: b           L_804A1BD8
    // 0x804A1BD0: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
        goto L_804A1BD8;
    // 0x804A1BD0: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x804A1BD4: swc1        $f2, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f2.u32l;
L_804A1BD8:
    // 0x804A1BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A1BDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A1BE0: jr          $ra
    // 0x804A1BE4: nop

    return;
    // 0x804A1BE4: nop

;}
RECOMP_FUNC void func_8058413C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058413C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80584140: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80584144: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80584148: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8058414C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80584150: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80584154: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80584158: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8058415C: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80584160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80584164: addiu       $a2, $zero, 0x21C
    ctx->r6 = ADD32(0, 0X21C);
    // 0x80584168: addiu       $a3, $zero, 0x1D10
    ctx->r7 = ADD32(0, 0X1D10);
    // 0x8058416C: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80584170: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80584174: jal         0x80583CCC
    // 0x80584178: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80583CCC(rdram, ctx);
        goto after_0;
    // 0x80584178: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8058417C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80584180: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80584184: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80584188: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8058418C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80584190: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80584194: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80584198: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8058419C: jr          $ra
    // 0x805841A0: nop

    return;
    // 0x805841A0: nop

;}
RECOMP_FUNC void func_8078A018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078A018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078A01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078A020: jal         0x80789E20
    // 0x8078A024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80789E20(rdram, ctx);
        goto after_0;
    // 0x8078A024: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078A028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078A02C: beq         $v0, $zero, L_8078A054
    if (ctx->r2 == 0) {
        // 0x8078A030: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8078A054;
    }
    // 0x8078A030: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8078A034: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8078A038: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8078A03C: bnel        $t6, $zero, L_8078A060
    if (ctx->r14 != 0) {
        // 0x8078A040: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078A060;
    }
    goto skip_0;
    // 0x8078A040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078A044: jal         0x80789F04
    // 0x8078A048: nop

    func_80789F04(rdram, ctx);
        goto after_1;
    // 0x8078A048: nop

    after_1:
    // 0x8078A04C: b           L_8078A060
    // 0x8078A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078A060;
    // 0x8078A050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078A054:
    // 0x8078A054: jal         0x800447C8
    // 0x8078A058: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x8078A058: nop

    after_2:
    // 0x8078A05C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078A060:
    // 0x8078A060: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078A064: jr          $ra
    // 0x8078A068: nop

    return;
    // 0x8078A068: nop

;}
RECOMP_FUNC void func_8042703C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042703C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427044: jal         0x80426FCC
    // 0x80427048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80426FCC(rdram, ctx);
        goto after_0;
    // 0x80427048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042704C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80427050: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80427054: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80427058: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042705C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(38, 0X1220) << 16);
    // 0x80427060: lwc1        $f6, 0x7820($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(38, 0X1220));
    // 0x80427064: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80427068: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042706C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80427070: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80427074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80427078: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8042707C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80427080: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80427084: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80427088: nop

    // 0x8042708C: bc1fl       L_804270A0
    if (!c1cs) {
        // 0x80427090: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804270A0;
    }
    goto skip_0;
    // 0x80427090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80427094: jal         0x80427118
    // 0x80427098: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    func_80427118(rdram, ctx);
        goto after_1;
    // 0x80427098: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x8042709C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804270A0:
    // 0x804270A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804270A4: jr          $ra
    // 0x804270A8: nop

    return;
    // 0x804270A8: nop

;}
RECOMP_FUNC void func_8075ED50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075ED50: lui         $v0, 0x8076
    ctx->r2 = S32(RELOC_HI16(757, 0X6C4) << 16);
    // 0x8075ED54: addiu       $v0, $v0, -0xBEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(757, 0X6C4));
    // 0x8075ED58: jr          $ra
    // 0x8075ED5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8075ED5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8079140C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079140C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80791410: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80791414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80791418: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8079141C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80791420: jal         0x807903C4
    // 0x80791424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80791424: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80791428: jal         0x80790714
    // 0x8079142C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x8079142C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80791430: beq         $v0, $zero, L_8079144C
    if (ctx->r2 == 0) {
        // 0x80791434: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8079144C;
    }
    // 0x80791434: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80791438: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8079143C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80791440: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80791444: jal         0x8079393C
    // 0x80791448: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80791448: lw          $a3, 0x68($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X68);
    after_2:
L_8079144C:
    // 0x8079144C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80791450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80791454: jr          $ra
    // 0x80791458: nop

    return;
    // 0x80791458: nop

;}
RECOMP_FUNC void func_807B8680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B8680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B8684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B8688: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B868C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B8690: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B8694: jal         0x807B8298
    // 0x807B8698: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_807B8298(rdram, ctx);
        goto after_0;
    // 0x807B8698: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x807B869C: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x807B86A0: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B86A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B86A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B86AC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807B86B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807B86B4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x807B86B8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B86BC: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B86C0: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x807B86C4: lui         $a2, 0x4188
    ctx->r6 = S32(0X4188 << 16);
    // 0x807B86C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807B86CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x807B86D0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x807B86D4: ori         $a2, $a2, 0x51EB
    ctx->r6 = ctx->r6 | 0X51EB;
    // 0x807B86D8: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B86DC: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x807B86E0: jal         0x8005CEBC
    // 0x807B86E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_1;
    // 0x807B86E4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B86E8: lw          $t2, 0x3C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X3C);
    // 0x807B86EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B86F0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x807B86F4: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x807B86F8: jal         0x807B8314
    // 0x807B86FC: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_2;
    // 0x807B86FC: sw          $v0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->r2;
    after_2:
    // 0x807B8700: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x807B8704: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x807B8708: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x807B870C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x807B8710: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x807B8714: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x807B8718: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x807B871C: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x807B8720: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(886, 0X1C10) << 16);
    // 0x807B8724: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x807B8728: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B872C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x807B8730: lhu         $a0, -0x6180($a0)
    ctx->r4 = MEM_HU(ctx->r4, (int16_t)RELOC_LO16(886, 0X1C10));
    // 0x807B8734: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x807B8738: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x807B873C: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    // 0x807B8740: jal         0x8005CEBC
    // 0x807B8744: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_3;
    // 0x807B8744: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x807B8748: lw          $t1, 0x3C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X3C);
    // 0x807B874C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B8750: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x807B8754: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x807B8758: jal         0x807B8314
    // 0x807B875C: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    func_807B8314(rdram, ctx);
        goto after_4;
    // 0x807B875C: sw          $v0, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->r2;
    after_4:
    // 0x807B8760: jal         0x807B8340
    // 0x807B8764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807B8340(rdram, ctx);
        goto after_5;
    // 0x807B8764: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x807B8768: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B876C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B8770: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B8774: jr          $ra
    // 0x807B8778: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B8778: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80011400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011400: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011404: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011408: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x8001140C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80011410: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80011414: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80011418: jal         0x8001A900
    // 0x8001141C: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    func_8001A900(rdram, ctx);
        goto after_0;
    // 0x8001141C: lw          $a0, -0x6D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D6C);
    after_0:
    // 0x80011420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011424: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80011428: sw          $zero, -0x6D6C($at)
    MEM_W(-0X6D6C, ctx->r1) = 0;
    // 0x8001142C: jr          $ra
    // 0x80011430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80011430: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806EF584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EF584: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806EF588: bnel        $t6, $zero, L_806EF5B0
    if (ctx->r14 != 0) {
        // 0x806EF58C: lh          $t9, 0x144($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X144);
            goto L_806EF5B0;
    }
    goto skip_0;
    // 0x806EF58C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    skip_0:
    // 0x806EF590: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x806EF594: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4C64) << 16);
    // 0x806EF598: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806EF59C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x806EF5A0: lwc1        $f4, 0xBB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4C64));
    // 0x806EF5A4: jr          $ra
    // 0x806EF5A8: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x806EF5A8: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x806EF5AC: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
L_806EF5B0:
    // 0x806EF5B0: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4C64) << 16);
    // 0x806EF5B4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806EF5B8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x806EF5BC: lwc1        $f6, 0xBB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4C64));
    // 0x806EF5C0: swc1        $f6, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f6.u32l;
    // 0x806EF5C4: jr          $ra
    // 0x806EF5C8: nop

    return;
    // 0x806EF5C8: nop

;}
RECOMP_FUNC void func_806F7C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7C14: lh          $v1, 0x144($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X144);
    // 0x806F7C18: lw          $t3, 0x168($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X168);
    // 0x806F7C1C: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(694, 0X1B08) << 16);
    // 0x806F7C20: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x806F7C24: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x806F7C28: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x806F7C2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7C30: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F7C34: lbu         $t8, -0x6CE8($t8)
    ctx->r24 = MEM_BU(ctx->r24, (int16_t)RELOC_LO16(694, 0X1B08));
    // 0x806F7C38: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x806F7C3C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x806F7C40: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x806F7C44: sll         $t9, $t8, 11
    ctx->r25 = S32(ctx->r24 << 11);
    // 0x806F7C48: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x806F7C4C: addu        $a3, $t9, $t4
    ctx->r7 = ADD32(ctx->r25, ctx->r12);
    // 0x806F7C50: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x806F7C54: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x806F7C58: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7C5C: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x806F7C60: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x806F7C64: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x806F7C68: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x806F7C6C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x806F7C70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x806F7C74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7C78: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x806F7C7C: lui         $t7, 0x73F
    ctx->r15 = S32(0X73F << 16);
    // 0x806F7C80: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806F7C84: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7C88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806F7C8C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x806F7C90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7C94: ori         $t7, $t7, 0xF200
    ctx->r15 = ctx->r15 | 0XF200;
    // 0x806F7C98: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x806F7C9C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x806F7CA0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x806F7CA4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x806F7CA8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x806F7CAC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7CB0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x806F7CB4: lui         $t4, 0xF548
    ctx->r12 = S32(0XF548 << 16);
    // 0x806F7CB8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x806F7CBC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x806F7CC0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806F7CC4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x806F7CC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7CCC: ori         $t4, $t4, 0x800
    ctx->r12 = ctx->r12 | 0X800;
    // 0x806F7CD0: lui         $t7, 0x7
    ctx->r15 = S32(0X7 << 16);
    // 0x806F7CD4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x806F7CD8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x806F7CDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806F7CE0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x806F7CE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x806F7CE8: ori         $t7, $t7, 0xC0FC
    ctx->r15 = ctx->r15 | 0XC0FC;
    // 0x806F7CEC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x806F7CF0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x806F7CF4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x806F7CF8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x806F7CFC: jr          $ra
    // 0x806F7D00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    return;
    // 0x806F7D00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_805A8738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A8738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A873C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A8740: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805A8744: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805A8748: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A874C: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(426, 0X16C0) << 16);
    // 0x805A8750: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A8754: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805A8758: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805A875C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A8760: lw          $t8, -0x75F0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(426, 0X16C0));
    // 0x805A8764: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805A8768: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805A876C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805A8770: jal         0x80048490
    // 0x805A8774: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805A8774: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805A8778: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805A877C: jal         0x80048378
    // 0x805A8780: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805A8780: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x805A8784: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A8788: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A878C: jr          $ra
    // 0x805A8790: nop

    return;
    // 0x805A8790: nop

;}
RECOMP_FUNC void func_8002A0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A0D0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002A0D4: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8002A0D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A0DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A0E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002A0E4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8002A0E8: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8002A0EC: beql        $v0, $zero, L_8002A13C
    if (ctx->r2 == 0) {
        // 0x8002A0F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002A13C;
    }
    goto skip_0;
    // 0x8002A0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002A0F4: jal         0x80081C64
    // 0x8002A0F8: lwc1        $f12, 0x8C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8C);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8002A0F8: lwc1        $f12, 0x8C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8C);
    after_0:
    // 0x8002A0FC: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002A100: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8002A104: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8002A108: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002A10C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002A110: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002A114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002A118: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002A11C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002A120: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8002A124: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002A128: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8002A12C: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8002A130: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8002A134: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x8002A138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002A13C:
    // 0x8002A13C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A140: jr          $ra
    // 0x8002A144: nop

    return;
    // 0x8002A144: nop

;}
RECOMP_FUNC void func_8003C1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C1B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003C1B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003C1B8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8003C1BC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003C1C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8003C1C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003C1C8: jal         0x8004700C
    // 0x8003C1CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003C1CC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003C1D0: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x8003C1D4: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003C1D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003C1DC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8003C1E0: lw          $s0, 0x160($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X160);
    // 0x8003C1E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003C1E8: jal         0x80048060
    // 0x8003C1EC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80048060(rdram, ctx);
        goto after_1;
    // 0x8003C1EC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x8003C1F0: jal         0x80048060
    // 0x8003C1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x8003C1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003C1F8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8003C1FC: jal         0x80047F9C
    // 0x8003C200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8003C200: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8003C204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8003C208: jal         0x80047F9C
    // 0x8003C20C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x8003C20C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x8003C210: lwc1        $f4, 0x98($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X98);
    // 0x8003C214: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C218: swc1        $f4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f4.u32l;
    // 0x8003C21C: lwc1        $f6, 0x98($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8003C220: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8003C224: lw          $v0, 0x180($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X180);
    // 0x8003C228: beq         $v0, $zero, L_8003C270
    if (ctx->r2 == 0) {
        // 0x8003C22C: nop
    
            goto L_8003C270;
    }
    // 0x8003C22C: nop

    // 0x8003C230: lw          $v1, 0x174($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X174);
    // 0x8003C234: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    // 0x8003C238: beq         $a0, $zero, L_8003C254
    if (ctx->r4 == 0) {
        // 0x8003C23C: nop
    
            goto L_8003C254;
    }
    // 0x8003C23C: nop

    // 0x8003C240: bne         $a0, $v0, L_8003C254
    if (ctx->r4 != ctx->r2) {
        // 0x8003C244: nop
    
            goto L_8003C254;
    }
    // 0x8003C244: nop

    // 0x8003C248: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8003C24C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8003C250: sb          $zero, 0xDC($t7)
    MEM_B(0XDC, ctx->r15) = 0;
L_8003C254:
    // 0x8003C254: jal         0x80048060
    // 0x8003C258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80048060(rdram, ctx);
        goto after_5;
    // 0x8003C258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8003C25C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C260: jal         0x80047F9C
    // 0x8003C264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8003C264: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8003C268: b           L_8003C27C
    // 0x8003C26C: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
        goto L_8003C27C;
    // 0x8003C26C: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
L_8003C270:
    // 0x8003C270: jal         0x80048114
    // 0x8003C274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80048114(rdram, ctx);
        goto after_7;
    // 0x8003C274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x8003C278: lwc1        $f8, 0x84($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X84);
L_8003C27C:
    // 0x8003C27C: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8003C280: lwc1        $f18, 0x88($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X88);
    // 0x8003C284: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C288: lwc1        $f8, 0x8C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x8003C28C: swc1        $f16, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f16.u32l;
    // 0x8003C290: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8003C294: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C298: swc1        $f6, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f6.u32l;
    // 0x8003C29C: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8003C2A0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C2A4: swc1        $f16, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f16.u32l;
    // 0x8003C2A8: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C2AC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8003C2B0: lbu         $t9, 0x79($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X79);
    // 0x8003C2B4: beql        $t9, $zero, L_8003C2D0
    if (ctx->r25 == 0) {
        // 0x8003C2B8: lw          $v1, 0x3C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X3C);
            goto L_8003C2D0;
    }
    goto skip_0;
    // 0x8003C2B8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8003C2BC: jal         0x8005FBC0
    // 0x8003C2C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FBC0(rdram, ctx);
        goto after_8;
    // 0x8003C2C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8003C2C4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C2C8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8003C2CC: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
L_8003C2D0:
    // 0x8003C2D0: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x8003C2D4: lwc1        $f0, 0x84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X84);
    // 0x8003C2D8: lwc1        $f18, 0x84($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8003C2DC: lwc1        $f6, 0x88($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X88);
    // 0x8003C2E0: lwc1        $f16, 0x8C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x8003C2E4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8003C2E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003C2EC: swc1        $f4, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f4.u32l;
    // 0x8003C2F0: lwc1        $f8, 0x88($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8003C2F4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C2F8: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8003C2FC: lwc1        $f18, 0x8C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8003C300: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003C304: swc1        $f4, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f4.u32l;
    // 0x8003C308: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8003C30C: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8003C310: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8003C314: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8003C318: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x8003C31C: lwc1        $f16, 0x88($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X88);
    // 0x8003C320: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003C324: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x8003C328: lwc1        $f6, 0x8C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x8003C32C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003C330: jal         0x8002FB50
    // 0x8003C334: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    func_8002FB50(rdram, ctx);
        goto after_9;
    // 0x8003C334: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_9:
    // 0x8003C338: jal         0x8005FE48
    // 0x8003C33C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8005FE48(rdram, ctx);
        goto after_10;
    // 0x8003C33C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8003C340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003C344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003C348: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C34C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8003C350: jr          $ra
    // 0x8003C354: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003C354: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_807A6020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A6024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A6028: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807A602C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807A6030: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x807A6034: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(847, 0X14A4) << 16);
    // 0x807A6038: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x807A603C: addiu       $t7, $t7, 0x71A4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(847, 0X14A4));
    // 0x807A6040: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A6044: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807A6048: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A604C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x807A6050: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807A6054: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A6058: jal         0x807A6070
    // 0x807A605C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807A6070(rdram, ctx);
        goto after_0;
    // 0x807A605C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x807A6060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A6064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A6068: jr          $ra
    // 0x807A606C: nop

    return;
    // 0x807A606C: nop

;}
RECOMP_FUNC void func_8000675C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000675C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80006760: beq         $a0, $at, L_80006784
    if (ctx->r4 == ctx->r1) {
        // 0x80006764: lui         $t6, 0x800B
        ctx->r14 = S32(0X800B << 16);
            goto L_80006784;
    }
    // 0x80006764: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80006768: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x8000676C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80006770: lbu         $t7, 0x2996($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2996);
    // 0x80006774: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80006778: beq         $t7, $at, L_80006784
    if (ctx->r15 == ctx->r1) {
        // 0x8000677C: nop
    
            goto L_80006784;
    }
    // 0x8000677C: nop

    // 0x80006780: sb          $a1, 0x2996($v0)
    MEM_B(0X2996, ctx->r2) = ctx->r5;
L_80006784:
    // 0x80006784: jr          $ra
    // 0x80006788: nop

    return;
    // 0x80006788: nop

;}
RECOMP_FUNC void func_806CCF4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCF4C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x806CCF50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CCF54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CCF58: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x806CCF5C: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x806CCF60: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x806CCF64: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x806CCF68: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CCF6C: jal         0x8004700C
    // 0x806CCF70: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806CCF70: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    after_0:
    // 0x806CCF74: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x806CCF78: lw          $t8, 0x7F78($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7F78);
    // 0x806CCF7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806CCF80: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x806CCF84: jal         0x80049018
    // 0x806CCF88: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    func_80049018(rdram, ctx);
        goto after_1;
    // 0x806CCF88: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_1:
    // 0x806CCF8C: beq         $v0, $zero, L_806CCFFC
    if (ctx->r2 == 0) {
        // 0x806CCF90: nop
    
            goto L_806CCFFC;
    }
    // 0x806CCF90: nop

    // 0x806CCF94: jal         0x800653D8
    // 0x806CCF98: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x806CCF98: nop

    after_2:
    // 0x806CCF9C: andi        $t2, $v0, 0x7
    ctx->r10 = ctx->r2 & 0X7;
    // 0x806CCFA0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x806CCFA4: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x806CCFA8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x806CCFAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CCFB0: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C28) << 16);
    // 0x806CCFB4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x806CCFB8: lwc1        $f8, -0xCB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C28));
    // 0x806CCFBC: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x806CCFC0: lw          $t3, 0x874($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X874);
    // 0x806CCFC4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CCFC8: lui         $at, 0xC2E6
    ctx->r1 = S32(0XC2E6 << 16);
    // 0x806CCFCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CCFD0: lwc1        $f6, 0x50($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X50);
    // 0x806CCFD4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x806CCFD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806CCFDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CCFE0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806CCFE4: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806CCFE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CCFEC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CCFF0: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x806CCFF4: b           L_806CD054
    // 0x806CCFF8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_806CD054;
    // 0x806CCFF8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_806CCFFC:
    // 0x806CCFFC: jal         0x800653D8
    // 0x806CD000: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x806CD000: nop

    after_3:
    // 0x806CD004: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x806CD008: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x806CD00C: andi        $t4, $v0, 0x7
    ctx->r12 = ctx->r2 & 0X7;
    // 0x806CD010: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x806CD014: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806CD018: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x806CD01C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806CD020: lw          $t8, 0x874($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X874);
    // 0x806CD024: lui         $at, 0xC2E6
    ctx->r1 = S32(0XC2E6 << 16);
    // 0x806CD028: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CD02C: lwc1        $f6, 0x50($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X50);
    // 0x806CD030: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x806CD034: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x806CD038: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CD03C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CD040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CD044: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CD048: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CD04C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CD050: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
L_806CD054:
    // 0x806CD054: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x806CD058: andi        $t9, $t0, 0x3
    ctx->r25 = ctx->r8 & 0X3;
    // 0x806CD05C: bne         $t9, $zero, L_806CD0F0
    if (ctx->r25 != 0) {
        // 0x806CD060: nop
    
            goto L_806CD0F0;
    }
    // 0x806CD060: nop

    // 0x806CD064: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806CD068: jal         0x800653D8
    // 0x806CD06C: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x806CD06C: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x806CD070: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x806CD074: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x806CD078: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x806CD07C: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x806CD080: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x806CD084: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806CD088: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x806CD08C: lw          $t9, 0x6C($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X6C);
    // 0x806CD090: lui         $a2, 0x806D
    ctx->r6 = S32(RELOC_HI16(604, 0X3B1C) << 16);
    // 0x806CD094: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x806CD098: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x806CD09C: lw          $a2, -0xDC4($a2)
    ctx->r6 = MEM_W(ctx->r6, (int16_t)RELOC_LO16(604, 0X3B1C));
    // 0x806CD0A0: jalr        $t9
    // 0x806CD0A4: lw          $a0, 0x874($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X874);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x806CD0A4: lw          $a0, 0x874($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X874);
    after_5:
    // 0x806CD0A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806CD0AC: beq         $v0, $zero, L_806CD0F0
    if (ctx->r2 == 0) {
        // 0x806CD0B0: lwc1        $f2, 0x60($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
            goto L_806CD0F0;
    }
    // 0x806CD0B0: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x806CD0B4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x806CD0B8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x806CD0BC: lwc1        $f10, 0x8C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x806CD0C0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x806CD0C4: swc1        $f6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f6.u32l;
    // 0x806CD0C8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806CD0CC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x806CD0D0: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806CD0D4: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806CD0D8: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x806CD0DC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x806CD0E0: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x806CD0E4: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x806CD0E8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806CD0EC: swc1        $f4, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f4.u32l;
L_806CD0F0:
    // 0x806CD0F0: beql        $s0, $zero, L_806CD374
    if (ctx->r16 == 0) {
        // 0x806CD0F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CD374;
    }
    goto skip_0;
    // 0x806CD0F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CD0F8: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x806CD0FC: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x806CD100: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x806CD104: lw          $t7, 0x874($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X874);
    // 0x806CD108: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806CD10C: lwc1        $f10, 0x84($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X84);
    // 0x806CD110: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806CD114: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x806CD118: lw          $t8, 0x874($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X874);
    // 0x806CD11C: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806CD120: lwc1        $f8, 0x88($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X88);
    // 0x806CD124: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x806CD128: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x806CD12C: jal         0x80066E88
    // 0x806CD130: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x806CD130: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x806CD134: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806CD138: jal         0x80066DE4
    // 0x806CD13C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_7;
    // 0x806CD13C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_7:
    // 0x806CD140: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x806CD144: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806CD148: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x806CD14C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806CD150: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x806CD154: nop

    // 0x806CD158: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x806CD15C: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x806CD160: jal         0x80066E88
    // 0x806CD164: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    func_80066E88(rdram, ctx);
        goto after_8;
    // 0x806CD164: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x806CD168: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806CD16C: jal         0x80066DE4
    // 0x806CD170: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_9;
    // 0x806CD170: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_9:
    // 0x806CD174: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x806CD178: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x806CD17C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806CD180: mul.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x806CD184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806CD188: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806CD18C: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CD190: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x806CD194: nop

    // 0x806CD198: bc1tl       L_806CD374
    if (c1cs) {
        // 0x806CD19C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CD374;
    }
    goto skip_1;
    // 0x806CD19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806CD1A0: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x806CD1A4: lui         $at, 0x47C8
    ctx->r1 = S32(0X47C8 << 16);
    // 0x806CD1A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806CD1AC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x806CD1B0: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x806CD1B4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CD1B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806CD1BC: nop

    // 0x806CD1C0: bc1tl       L_806CD374
    if (c1cs) {
        // 0x806CD1C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CD374;
    }
    goto skip_2;
    // 0x806CD1C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806CD1C8: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x806CD1CC: jal         0x80067114
    // 0x806CD1D0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    func_80067114(rdram, ctx);
        goto after_10;
    // 0x806CD1D0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    after_10:
    // 0x806CD1D4: jal         0x80065954
    // 0x806CD1D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80065954(rdram, ctx);
        goto after_11;
    // 0x806CD1D8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x806CD1DC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806CD1E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CD1E4: nop

    // 0x806CD1E8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806CD1EC: nop

    // 0x806CD1F0: bc1tl       L_806CD374
    if (c1cs) {
        // 0x806CD1F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CD374;
    }
    goto skip_3;
    // 0x806CD1F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806CD1F8: jal         0x80065954
    // 0x806CD1FC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    func_80065954(rdram, ctx);
        goto after_12;
    // 0x806CD1FC: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    after_12:
    // 0x806CD200: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x806CD204: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CD208: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x806CD20C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806CD210: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x806CD214: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x806CD218: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x806CD21C: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806CD220: mul.s       $f18, $f4, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806CD224: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x806CD228: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x806CD22C: bc1f        L_806CD274
    if (!c1cs) {
        // 0x806CD230: nop
    
            goto L_806CD274;
    }
    // 0x806CD230: nop

    // 0x806CD234: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x806CD238: andi        $t2, $t1, 0x700
    ctx->r10 = ctx->r9 & 0X700;
    // 0x806CD23C: beq         $t2, $zero, L_806CD274
    if (ctx->r10 == 0) {
        // 0x806CD240: nop
    
            goto L_806CD274;
    }
    // 0x806CD240: nop

    // 0x806CD244: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x806CD248: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x806CD24C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806CD250: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x806CD254: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x806CD258: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x806CD25C: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x806CD260: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x806CD264: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x806CD268: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x806CD26C: b           L_806CD294
    // 0x806CD270: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
        goto L_806CD294;
    // 0x806CD270: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
L_806CD274:
    // 0x806CD274: jal         0x80065954
    // 0x806CD278: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    func_80065954(rdram, ctx);
        goto after_13;
    // 0x806CD278: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x806CD27C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x806CD280: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CD284: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806CD288: sub.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x806CD28C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806CD290: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
L_806CD294:
    // 0x806CD294: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806CD298: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806CD29C: lwc1        $f10, 0x10C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x806CD2A0: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x806CD2A4: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CD2A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806CD2AC: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x806CD2B0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x806CD2B4: swc1        $f6, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f6.u32l;
    // 0x806CD2B8: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x806CD2BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806CD2C0: nop

    // 0x806CD2C4: bc1fl       L_806CD2D8
    if (!c1cs) {
        // 0x806CD2C8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806CD2D8;
    }
    goto skip_4;
    // 0x806CD2C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_4:
    // 0x806CD2CC: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x806CD2D0: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x806CD2D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806CD2D8:
    // 0x806CD2D8: lui         $at, 0xC060
    ctx->r1 = S32(0XC060 << 16);
    // 0x806CD2DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CD2E0: nop

    // 0x806CD2E4: bc1fl       L_806CD2F4
    if (!c1cs) {
        // 0x806CD2E8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806CD2F4;
    }
    goto skip_5;
    // 0x806CD2E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_5:
    // 0x806CD2EC: swc1        $f2, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f2.u32l;
    // 0x806CD2F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806CD2F4:
    // 0x806CD2F4: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    // 0x806CD2F8: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x806CD2FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806CD300: nop

    // 0x806CD304: bc1fl       L_806CD318
    if (!c1cs) {
        // 0x806CD308: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806CD318;
    }
    goto skip_6;
    // 0x806CD308: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_6:
    // 0x806CD30C: swc1        $f2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f2.u32l;
    // 0x806CD310: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    // 0x806CD314: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806CD318:
    // 0x806CD318: nop

    // 0x806CD31C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806CD320: nop

    // 0x806CD324: bc1f        L_806CD330
    if (!c1cs) {
        // 0x806CD328: nop
    
            goto L_806CD330;
    }
    // 0x806CD328: nop

    // 0x806CD32C: swc1        $f2, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f2.u32l;
L_806CD330:
    // 0x806CD330: jal         0x80065954
    // 0x806CD334: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    func_80065954(rdram, ctx);
        goto after_14;
    // 0x806CD334: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    after_14:
    // 0x806CD338: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806CD33C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CD340: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CD344: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x806CD348: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806CD34C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x806CD350: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x806CD354: bc1fl       L_806CD374
    if (!c1cs) {
        // 0x806CD358: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CD374;
    }
    goto skip_7;
    // 0x806CD358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x806CD35C: sb          $t3, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r11;
    // 0x806CD360: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CD364: sb          $t4, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r12;
    // 0x806CD368: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806CD36C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x806CD370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CD374:
    // 0x806CD374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CD378: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x806CD37C: jr          $ra
    // 0x806CD380: nop

    return;
    // 0x806CD380: nop

;}
RECOMP_FUNC void func_8005A070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A078: jal         0x80047058
    // 0x8005A07C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80047058(rdram, ctx);
        goto after_0;
    // 0x8005A07C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005A080: bne         $v0, $zero, L_8005A098
    if (ctx->r2 != 0) {
        // 0x8005A084: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8005A098;
    }
    // 0x8005A084: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005A088: jal         0x80059FD4
    // 0x8005A08C: nop

    func_80059FD4(rdram, ctx);
        goto after_1;
    // 0x8005A08C: nop

    after_1:
    // 0x8005A090: b           L_8005A0A4
    // 0x8005A094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005A0A4;
    // 0x8005A094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A098:
    // 0x8005A098: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A09C: sw          $a0, -0x6580($at)
    MEM_W(-0X6580, ctx->r1) = ctx->r4;
    // 0x8005A0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A0A4:
    // 0x8005A0A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A0A8: jr          $ra
    // 0x8005A0AC: nop

    return;
    // 0x8005A0AC: nop

;}
RECOMP_FUNC void func_8044692C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044692C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446930: jr          $ra
    // 0x80446934: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    return;
    // 0x80446934: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8064B2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064B2FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064B300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064B304: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064B308: lh          $t6, 0xC0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XC0);
    // 0x8064B30C: lui         $at, 0xC32E
    ctx->r1 = S32(0XC32E << 16);
    // 0x8064B310: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8064B314: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8064B318: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8064B31C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8064B320: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064B324: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064B328: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8064B32C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064B330: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8064B334: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8064B338: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
    // 0x8064B33C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8064B340: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064B344: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8064B348: swc1        $f10, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f10.u32l;
    // 0x8064B34C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8064B350: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8064B354: jal         0x8064B2A0
    // 0x8064B358: sh          $t8, 0xC0($a0)
    MEM_H(0XC0, ctx->r4) = ctx->r24;
    func_8064B2A0(rdram, ctx);
        goto after_0;
    // 0x8064B358: sh          $t8, 0xC0($a0)
    MEM_H(0XC0, ctx->r4) = ctx->r24;
    after_0:
    // 0x8064B35C: bne         $v0, $zero, L_8064B374
    if (ctx->r2 != 0) {
        // 0x8064B360: lui         $t9, 0x8065
        ctx->r25 = S32(RELOC_HI16(495, 0X1148) << 16);
            goto L_8064B374;
    }
    // 0x8064B360: lui         $t9, 0x8065
    ctx->r25 = S32(RELOC_HI16(495, 0X1148) << 16);
    // 0x8064B364: jal         0x800445A4
    // 0x8064B368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8064B368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8064B36C: b           L_8064B3D0
    // 0x8064B370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8064B3D0;
    // 0x8064B370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064B374:
    // 0x8064B374: addiu       $t9, $t9, -0x4DE8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(495, 0X1148));
    // 0x8064B378: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8064B37C: jal         0x8064A468
    // 0x8064B380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A468(rdram, ctx);
        goto after_2;
    // 0x8064B380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064B384: jal         0x8064B2E4
    // 0x8064B388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064B2E4(rdram, ctx);
        goto after_3;
    // 0x8064B388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8064B38C: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8064B390: lui         $t0, 0x8065
    ctx->r8 = S32(RELOC_HI16(495, 0X2FB8) << 16);
    // 0x8064B394: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8064B398: addiu       $t0, $t0, -0x2F78
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(495, 0X2FB8));
    // 0x8064B39C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8064B3A0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8064B3A4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064B3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064B3AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064B3B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8064B3B4: jal         0x8064B3E0
    // 0x8064B3B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8064B3E0(rdram, ctx);
        goto after_4;
    // 0x8064B3B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8064B3BC: jal         0x8064A158
    // 0x8064B3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A158(rdram, ctx);
        goto after_5;
    // 0x8064B3C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8064B3C4: jal         0x8064A40C
    // 0x8064B3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A40C(rdram, ctx);
        goto after_6;
    // 0x8064B3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8064B3CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064B3D0:
    // 0x8064B3D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064B3D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064B3D8: jr          $ra
    // 0x8064B3DC: nop

    return;
    // 0x8064B3DC: nop

;}
RECOMP_FUNC void func_8007B55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B55C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8007B560: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8007B564: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8007B568: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8007B56C: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x8007B570: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8007B574: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x8007B578: jr          $ra
    // 0x8007B57C: nop

    return;
    // 0x8007B57C: nop

;}
RECOMP_FUNC void func_806EE4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE4D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EE4DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EE4E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EE4E4: jal         0x806EE3DC
    // 0x806EE4E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EE3DC(rdram, ctx);
        goto after_0;
    // 0x806EE4E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EE4EC: bne         $v0, $zero, L_806EE504
    if (ctx->r2 != 0) {
        // 0x806EE4F0: nop
    
            goto L_806EE504;
    }
    // 0x806EE4F0: nop

    // 0x806EE4F4: jal         0x800445A4
    // 0x806EE4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806EE4F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EE4FC: b           L_806EE574
    // 0x806EE500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EE574;
    // 0x806EE500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EE504:
    // 0x806EE504: jal         0x806EE4C0
    // 0x806EE508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE4C0(rdram, ctx);
        goto after_2;
    // 0x806EE508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EE50C: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x806EE510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806EE514: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806EE518: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806EE51C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806EE520: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X4890) << 16);
    // 0x806EE524: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806EE528: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806EE52C: addiu       $t7, $t7, 0x7E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(676, 0X4890));
    // 0x806EE530: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x806EE534: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806EE538: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806EE53C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806EE540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE548: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806EE54C: jal         0x806EE584
    // 0x806EE550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806EE584(rdram, ctx);
        goto after_3;
    // 0x806EE550: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806EE554: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806EE558: jal         0x806ED3C0
    // 0x806EE55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED3C0(rdram, ctx);
        goto after_4;
    // 0x806EE55C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EE560: bnel        $v0, $zero, L_806EE574
    if (ctx->r2 != 0) {
        // 0x806EE564: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EE574;
    }
    goto skip_0;
    // 0x806EE564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EE568: jal         0x800445A4
    // 0x806EE56C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806EE56C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EE570: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EE574:
    // 0x806EE574: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EE578: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EE57C: jr          $ra
    // 0x806EE580: nop

    return;
    // 0x806EE580: nop

;}
RECOMP_FUNC void func_804CAD4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAD4C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804CAD50: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(231, 0XF88) << 16);
    // 0x804CAD54: addiu       $t6, $t6, -0x4538
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(231, 0XF88));
    // 0x804CAD58: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804CAD5C: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(231, 0X1074) << 16);
    // 0x804CAD60: addiu       $t9, $t9, -0x444C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(231, 0X1074));
    // 0x804CAD64: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x804CAD68: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x804CAD6C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804CAD70: jr          $ra
    // 0x804CAD74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x804CAD74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_80058F68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058F68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80058F6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058F70: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80058F74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80058F78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80058F7C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80058F80: jal         0x80081C64
    // 0x80058F84: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x80058F84: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80058F88: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80058F8C: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80058F90: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80058F94: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058F98: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80058F9C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058FA0: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80058FA4: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058FA8: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80058FAC: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80058FB0: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80058FB4: jal         0x80058D94
    // 0x80058FB8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    func_80058D94(rdram, ctx);
        goto after_1;
    // 0x80058FB8: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80058FBC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80058FC0: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x80058FC4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058FC8: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80058FCC: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80058FD0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80058FD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80058FD8: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80058FDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80058FE0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80058FE4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80058FE8: nop

    // 0x80058FEC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80058FF0: jal         0x80058E08
    // 0x80058FF4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80058E08(rdram, ctx);
        goto after_2;
    // 0x80058FF4: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80058FF8: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80058FFC: lw          $t0, -0x7CE8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7CE8);
    // 0x80059000: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80059004: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80059008: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8005900C: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80059010: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80059014: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80059018: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8005901C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80059020: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80059024: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80059028: nop

    // 0x8005902C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80059030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059034: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80059038: jr          $ra
    // 0x8005903C: nop

    return;
    // 0x8005903C: nop

;}
RECOMP_FUNC void func_80716A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716A58: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80716A5C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80716A60: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80716A64: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80716A68: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80716A6C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80716A70: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80716A74: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80716A78: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80716A7C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80716A80: jr          $ra
    // 0x80716A84: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80716A84: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804EFCB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFCB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EFCBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804EFCC0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804EFCC4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804EFCC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EFCCC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804EFCD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804EFCD4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804EFCD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804EFCDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804EFCE0: lui         $t2, 0x804F
    ctx->r10 = S32(RELOC_HI16(267, 0X1178) << 16);
    // 0x804EFCE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804EFCE8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804EFCEC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804EFCF0: lw          $t2, -0xF8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(267, 0X1178));
    // 0x804EFCF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804EFCF8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804EFCFC: jal         0x804EF98C
    // 0x804EFD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF98C(rdram, ctx);
        goto after_0;
    // 0x804EFD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EFD04: jal         0x804EF9E8
    // 0x804EFD08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804EF9E8(rdram, ctx);
        goto after_1;
    // 0x804EFD08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804EFD0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EFD10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EFD14: jr          $ra
    // 0x804EFD18: nop

    return;
    // 0x804EFD18: nop

    // 0x804EFD1C: nop

;}
RECOMP_FUNC void func_8079ADE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079ADE4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8079ADE8: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(826, 0X1A68) << 16);
    // 0x8079ADEC: addiu       $t6, $t6, -0x5A78
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(826, 0X1A68));
    // 0x8079ADF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8079ADF4: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(826, 0X20C4) << 16);
    // 0x8079ADF8: addiu       $t9, $t9, -0x541C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(826, 0X20C4));
    // 0x8079ADFC: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x8079AE00: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8079AE04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8079AE08: jr          $ra
    // 0x8079AE0C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x8079AE0C: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_8073D1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D1E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8073D1E4: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(745, 0X854) << 16);
    // 0x8073D1E8: addiu       $t6, $t6, -0x25DC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(745, 0X854));
    // 0x8073D1EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8073D1F0: jr          $ra
    // 0x8073D1F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8073D1F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8073605C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073605C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736064: jal         0x800447C8
    // 0x80736068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80736068: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073606C: jal         0x80735F6C
    // 0x80736070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80735F6C(rdram, ctx);
        goto after_1;
    // 0x80736070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80736074: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80736078: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x8073607C: jal         0x80067BBC
    // 0x80736080: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80736080: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_2:
    // 0x80736084: addiu       $a0, $zero, 0x72
    ctx->r4 = ADD32(0, 0X72);
    // 0x80736088: jal         0x80067818
    // 0x8073608C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8073608C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80736090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736098: jr          $ra
    // 0x8073609C: nop

    return;
    // 0x8073609C: nop

;}
RECOMP_FUNC void func_8002F5B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F5B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002F5B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F5BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002F5C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002F5C4: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8002F5C8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002F5CC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8002F5D0: jal         0x8002B9E4
    // 0x8002F5D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002F5D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F5D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002F5DC: jal         0x8002F4B0
    // 0x8002F5E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002F4B0(rdram, ctx);
        goto after_1;
    // 0x8002F5E0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002F5E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F5E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002F5EC: jr          $ra
    // 0x8002F5F0: nop

    return;
    // 0x8002F5F0: nop

;}
RECOMP_FUNC void func_80046EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046EB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046EC0: bne         $a1, $at, L_80046ED0
    if (ctx->r5 != ctx->r1) {
        // 0x80046EC4: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80046ED0;
    }
    // 0x80046EC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046EC8: b           L_80046EE0
    // 0x80046ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046EE0;
    // 0x80046ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046ED0:
    // 0x80046ED0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80046ED4: addiu       $a1, $a1, 0x6E64
    ctx->r5 = ADD32(ctx->r5, 0X6E64);
    // 0x80046ED8: jal         0x80046D90
    // 0x80046EDC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80046D90(rdram, ctx);
        goto after_0;
    // 0x80046EDC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
L_80046EE0:
    // 0x80046EE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046EE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046EE8: jr          $ra
    // 0x80046EEC: nop

    return;
    // 0x80046EEC: nop

;}
RECOMP_FUNC void func_8002680C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002680C: lbu         $t6, 0x158($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X158);
    // 0x80026810: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80026814: addiu       $t7, $t7, 0x68BC
    ctx->r15 = ADD32(ctx->r15, 0X68BC);
    // 0x80026818: bne         $t6, $zero, L_80026830
    if (ctx->r14 != 0) {
        // 0x8002681C: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_80026830;
    }
    // 0x8002681C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80026820: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026824: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x80026828: jr          $ra
    // 0x8002682C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002682C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80026830:
    // 0x80026830: lh          $v0, -0x7680($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7680);
    // 0x80026834: bltz        $v0, L_80026844
    if (SIGNED(ctx->r2) < 0) {
        // 0x80026838: slti        $at, $v0, -0x9
        ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
            goto L_80026844;
    }
    // 0x80026838: slti        $at, $v0, -0x9
    ctx->r1 = SIGNED(ctx->r2) < -0X9 ? 1 : 0;
    // 0x8002683C: b           L_80026850
    // 0x80026840: addiu       $v0, $zero, -0x32
    ctx->r2 = ADD32(0, -0X32);
        goto L_80026850;
    // 0x80026840: addiu       $v0, $zero, -0x32
    ctx->r2 = ADD32(0, -0X32);
L_80026844:
    // 0x80026844: bnel        $at, $zero, L_80026854
    if (ctx->r1 != 0) {
        // 0x80026848: lw          $t8, 0x154($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X154);
            goto L_80026854;
    }
    goto skip_0;
    // 0x80026848: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    skip_0:
    // 0x8002684C: addiu       $v0, $zero, -0xA
    ctx->r2 = ADD32(0, -0XA);
L_80026850:
    // 0x80026850: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
L_80026854:
    // 0x80026854: lw          $a1, 0x15C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X15C);
    // 0x80026858: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x8002685C: sw          $t9, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r25;
    // 0x80026860: lw          $t0, 0x4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X4);
    // 0x80026864: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80026868: sltu        $at, $t0, $t9
    ctx->r1 = ctx->r8 < ctx->r25 ? 1 : 0;
    // 0x8002686C: beq         $at, $zero, L_800268B4
    if (ctx->r1 == 0) {
        // 0x80026870: nop
    
            goto L_800268B4;
    }
    // 0x80026870: nop

    // 0x80026874: lbu         $t1, 0x158($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X158);
    // 0x80026878: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8002687C: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80026880: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80026884: sb          $t2, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r10;
    // 0x80026888: sw          $t4, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r12;
    // 0x8002688C: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80026890: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x80026894: beq         $at, $zero, L_800268B4
    if (ctx->r1 == 0) {
        // 0x80026898: subu        $t5, $v1, $v0
        ctx->r13 = SUB32(ctx->r3, ctx->r2);
            goto L_800268B4;
    }
    // 0x80026898: subu        $t5, $v1, $v0
    ctx->r13 = SUB32(ctx->r3, ctx->r2);
L_8002689C:
    // 0x8002689C: sw          $t5, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r13;
    // 0x800268A0: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800268A4: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800268A8: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x800268AC: bnel        $at, $zero, L_8002689C
    if (ctx->r1 != 0) {
        // 0x800268B0: subu        $t5, $v1, $v0
        ctx->r13 = SUB32(ctx->r3, ctx->r2);
            goto L_8002689C;
    }
    goto skip_1;
    // 0x800268B0: subu        $t5, $v1, $v0
    ctx->r13 = SUB32(ctx->r3, ctx->r2);
    skip_1:
L_800268B4:
    // 0x800268B4: jr          $ra
    // 0x800268B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800268B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_807B6778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B6778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B677C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807B6780: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B6784: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B6788: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807B678C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x807B6790: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807B6794: sw          $zero, 0x1E4($a0)
    MEM_W(0X1E4, ctx->r4) = 0;
    // 0x807B6798: jal         0x80045A34
    // 0x807B679C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807B679C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_0:
    // 0x807B67A0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807B67A4: jal         0x807B64DC
    // 0x807B67A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807B64DC(rdram, ctx);
        goto after_1;
    // 0x807B67A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807B67AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B67B0: jal         0x807B73B0
    // 0x807B67B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807B73B0(rdram, ctx);
        goto after_2;
    // 0x807B67B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x807B67B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B67BC: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
    // 0x807B67C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807B67C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807B67C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B67CC: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x807B67D0: jr          $ra
    // 0x807B67D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807B67D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
