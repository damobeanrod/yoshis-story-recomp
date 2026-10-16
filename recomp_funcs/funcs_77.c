#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80522ED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522ED4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80522ED8: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x80522EDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522EE4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80522EE8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80522EEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522EF0: bne         $v1, $t7, L_80522F10
    if (ctx->r3 != ctx->r15) {
        // 0x80522EF4: addiu       $t8, $zero, 0x13
        ctx->r24 = ADD32(0, 0X13);
            goto L_80522F10;
    }
    // 0x80522EF4: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x80522EF8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80522EFC: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x80522F00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80522F04: jal         0x80523830
    // 0x80522F08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80523830(rdram, ctx);
        goto after_0;
    // 0x80522F08: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80522F0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80522F10:
    // 0x80522F10: jal         0x80522AD4
    // 0x80522F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_1;
    // 0x80522F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80522F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80522F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522F20: jr          $ra
    // 0x80522F24: nop

    return;
    // 0x80522F24: nop

;}
RECOMP_FUNC void func_80711038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80711038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8071103C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80711040: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80711044: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80711048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8071104C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80711050: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(727, 0X195C) << 16);
    // 0x80711054: lwc1        $f4, 0x28CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(727, 0X195C));
    // 0x80711058: lui         $a1, 0x4620
    ctx->r5 = S32(0X4620 << 16);
    // 0x8071105C: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(727, 0X1A90) << 16);
    // 0x80711060: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x80711064: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x80711068: addiu       $a0, $a0, 0x2A00
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(727, 0X1A90));
    // 0x8071106C: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x80711070: jal         0x80046804
    // 0x80711074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x80711074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80711078: bne         $v0, $zero, L_80711088
    if (ctx->r2 != 0) {
        // 0x8071107C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80711088;
    }
    // 0x8071107C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80711080: b           L_807110DC
    // 0x80711084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807110DC;
    // 0x80711084: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80711088:
    // 0x80711088: addiu       $a0, $zero, 0x4620
    ctx->r4 = ADD32(0, 0X4620);
    // 0x8071108C: jal         0x80047090
    // 0x80711090: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x80711090: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80711094: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80711098: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x8071109C: lhu         $t9, 0xE($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0XE);
    // 0x807110A0: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x807110A4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x807110A8: jal         0x80044194
    // 0x807110AC: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807110AC: sh          $t1, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r9;
    after_2:
    // 0x807110B0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x807110B4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x807110B8: beql        $v1, $zero, L_807110D4
    if (ctx->r3 == 0) {
        // 0x807110BC: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_807110D4;
    }
    goto skip_0;
    // 0x807110BC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x807110C0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807110C4: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x807110C8: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807110CC: swc1        $f8, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f8.u32l;
    // 0x807110D0: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_807110D4:
    // 0x807110D4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x807110D8: sw          $t2, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r10;
L_807110DC:
    // 0x807110DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807110E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807110E4: jr          $ra
    // 0x807110E8: nop

    return;
    // 0x807110E8: nop

;}
RECOMP_FUNC void func_8045AB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AB2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045AB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045AB34: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8045AB38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045AB3C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045AB40: jal         0x80066DE4
    // 0x8045AB44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8045AB44: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x8045AB48: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8045AB4C: jal         0x80066E88
    // 0x8045AB50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8045AB50: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8045AB54: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8045AB58: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8045AB5C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8045AB60: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045AB64: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045AB68: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x8045AB6C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8045AB70: nop

    // 0x8045AB74: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8045AB78: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8045AB7C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8045AB80: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045AB84: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045AB88: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8045AB8C: nop

    // 0x8045AB90: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8045AB94: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8045AB98: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8045AB9C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8045ABA0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8045ABA4: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8045ABA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045ABAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045ABB0: jr          $ra
    // 0x8045ABB4: nop

    return;
    // 0x8045ABB4: nop

;}
RECOMP_FUNC void func_804C9450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C9454: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C9458: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804C945C: lh          $t6, 0x144($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X144);
    // 0x804C9460: lw          $t0, 0x174($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X174);
    // 0x804C9464: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C9468: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x804C946C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x804C9470: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804C9474: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x804C9478: jal         0x80065528
    // 0x804C947C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x804C947C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_0:
    // 0x804C9480: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x804C9484: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804C9488: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(228, 0X798) << 16);
    // 0x804C948C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x804C9490: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x804C9494: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x804C9498: lh          $a0, -0x6528($a0)
    ctx->r4 = MEM_H(ctx->r4, (int16_t)RELOC_LO16(228, 0X798));
    // 0x804C949C: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x804C94A0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x804C94A4: beql        $at, $zero, L_804C94C0
    if (ctx->r1 == 0) {
        // 0x804C94A8: slt         $at, $a0, $v0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_804C94C0;
    }
    goto skip_0;
    // 0x804C94A8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x804C94AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x804C94B0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x804C94B4: b           L_804C94D4
    // 0x804C94B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
        goto L_804C94D4;
    // 0x804C94B8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x804C94BC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
L_804C94C0:
    // 0x804C94C0: beql        $at, $zero, L_804C94D8
    if (ctx->r1 == 0) {
        // 0x804C94C4: sh          $v0, 0x6($v1)
        MEM_H(0X6, ctx->r3) = ctx->r2;
            goto L_804C94D8;
    }
    goto skip_1;
    // 0x804C94C4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    skip_1:
    // 0x804C94C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x804C94CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x804C94D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
L_804C94D4:
    // 0x804C94D4: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_804C94D8:
    // 0x804C94D8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x804C94DC: sh          $v0, 0x52($t9)
    MEM_H(0X52, ctx->r25) = ctx->r2;
    // 0x804C94E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C94E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C94E8: jr          $ra
    // 0x804C94EC: nop

    return;
    // 0x804C94EC: nop

;}
RECOMP_FUNC void func_804C9898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9898: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C989C: lui         $t6, 0x8006
    ctx->r14 = S32(0X8006 << 16);
    // 0x804C98A0: addiu       $t6, $t6, 0x5284
    ctx->r14 = ADD32(ctx->r14, 0X5284);
    // 0x804C98A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C98A8: jr          $ra
    // 0x804C98AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804C98AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8044755C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044755C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80447564: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80447568: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8044756C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80447570: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80447574: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X13308) << 16);
    // 0x80447578: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8044757C: lw          $v1, 0x6CA0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CA0);
    // 0x80447580: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x80447584: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80447588: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8044758C: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80447590: lw          $t0, 0x76E8($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X13308));
    // 0x80447594: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80447598: beql        $t0, $zero, L_804475AC
    if (ctx->r8 == 0) {
        // 0x8044759C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804475AC;
    }
    goto skip_0;
    // 0x8044759C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804475A0: jalr        $t0
    // 0x804475A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x804475A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x804475A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804475AC:
    // 0x804475AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804475B0: jr          $ra
    // 0x804475B4: nop

    return;
    // 0x804475B4: nop

;}
RECOMP_FUNC void func_80671AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671AB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80671ABC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80671AC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80671AC4: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x80671AC8: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80671ACC: lw          $t7, -0x7478($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7478);
    // 0x80671AD0: lw          $t6, 0x3C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3C);
    // 0x80671AD4: lw          $a3, 0x38($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X38);
    // 0x80671AD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80671ADC: beq         $t7, $zero, L_80671B04
    if (ctx->r15 == 0) {
        // 0x80671AE0: sw          $t6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r14;
            goto L_80671B04;
    }
    // 0x80671AE0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80671AE4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80671AE8: lw          $t8, -0x7494($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7494);
    // 0x80671AEC: beql        $t8, $zero, L_80671B30
    if (ctx->r24 == 0) {
        // 0x80671AF0: lh          $t9, 0x184($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X184);
            goto L_80671B30;
    }
    goto skip_0;
    // 0x80671AF0: lh          $t9, 0x184($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X184);
    skip_0:
    // 0x80671AF4: jal         0x80671738
    // 0x80671AF8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    func_80671738(rdram, ctx);
        goto after_0;
    // 0x80671AF8: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80671AFC: b           L_80671B30
    // 0x80671B00: lh          $t9, 0x184($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X184);
        goto L_80671B30;
    // 0x80671B00: lh          $t9, 0x184($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X184);
L_80671B04:
    // 0x80671B04: lw          $v0, 0x168($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X168);
    // 0x80671B08: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80671B0C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80671B10: lw          $a2, 0x80($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X80);
    // 0x80671B14: jal         0x8005B350
    // 0x80671B18: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8005B350(rdram, ctx);
        goto after_1;
    // 0x80671B18: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x80671B1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80671B20: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80671B24: jal         0x8005B350
    // 0x80671B28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8005B350(rdram, ctx);
        goto after_2;
    // 0x80671B28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x80671B2C: lh          $t9, 0x184($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X184);
L_80671B30:
    // 0x80671B30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80671B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80671B38: blez        $t9, L_80671B64
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80671B3C: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80671B64;
    }
    // 0x80671B3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80671B40: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80671B44: lw          $t0, 0x188($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X188);
L_80671B48:
    // 0x80671B48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80671B4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80671B50: sb          $zero, 0x165($t0)
    MEM_B(0X165, ctx->r8) = 0;
    // 0x80671B54: lh          $t1, 0x184($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X184);
    // 0x80671B58: slt         $at, $v0, $t1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80671B5C: bnel        $at, $zero, L_80671B48
    if (ctx->r1 != 0) {
        // 0x80671B60: lw          $t0, 0x188($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X188);
            goto L_80671B48;
    }
    goto skip_1;
    // 0x80671B60: lw          $t0, 0x188($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X188);
    skip_1:
L_80671B64:
    // 0x80671B64: jal         0x80672C80
    // 0x80671B68: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80671B68: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    after_3:
    // 0x80671B6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80671B70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80671B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80671B78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80671B7C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    // 0x80671B80: jr          $ra
    // 0x80671B84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80671B84: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Fault_DrawRec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F600: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x8006F604: addiu       $t1, $t1, -0x7968
    ctx->r9 = ADD32(ctx->r9, -0X7968);
    // 0x8006F608: lhu         $v1, 0x5D0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X5D0);
    // 0x8006F60C: lw          $t8, 0x5CC($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X5CC);
    // 0x8006F610: sll         $t2, $a0, 1
    ctx->r10 = S32(ctx->r4 << 1);
    // 0x8006F614: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006F618: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8006F61C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8006F620: mflo        $t6
    ctx->r14 = lo;
    // 0x8006F624: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006F628: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006F62C: blez        $a3, L_8006F694
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8006F630: addu        $v0, $t9, $t2
        ctx->r2 = ADD32(ctx->r25, ctx->r10);
            goto L_8006F694;
    }
    // 0x8006F630: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
L_8006F634:
    // 0x8006F634: blez        $a2, L_8006F680
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006F638: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8006F680;
    }
    // 0x8006F638: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006F63C: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x8006F640: beq         $a1, $zero, L_8006F65C
    if (ctx->r5 == 0) {
        // 0x8006F644: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8006F65C;
    }
    // 0x8006F644: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8006F648:
    // 0x8006F648: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006F64C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x8006F650: bne         $v1, $a0, L_8006F648
    if (ctx->r3 != ctx->r4) {
        // 0x8006F654: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_8006F648;
    }
    // 0x8006F654: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006F658: beq         $a0, $a2, L_8006F678
    if (ctx->r4 == ctx->r6) {
        // 0x8006F65C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8006F678;
    }
L_8006F65C:
    // 0x8006F65C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006F660: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x8006F664: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8006F668: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
    // 0x8006F66C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8006F670: bne         $a0, $a2, L_8006F65C
    if (ctx->r4 != ctx->r6) {
        // 0x8006F674: sh          $t1, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r9;
            goto L_8006F65C;
    }
    // 0x8006F674: sh          $t1, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r9;
L_8006F678:
    // 0x8006F678: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8006F67C: lhu         $v1, -0x7398($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X7398);
L_8006F680:
    // 0x8006F680: subu        $t3, $v1, $a2
    ctx->r11 = SUB32(ctx->r3, ctx->r6);
    // 0x8006F684: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006F688: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8006F68C: bne         $t0, $a3, L_8006F634
    if (ctx->r8 != ctx->r7) {
        // 0x8006F690: addu        $v0, $v0, $t4
        ctx->r2 = ADD32(ctx->r2, ctx->r12);
            goto L_8006F634;
    }
    // 0x8006F690: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
L_8006F694:
    // 0x8006F694: jr          $ra
    // 0x8006F698: nop

    return;
    // 0x8006F698: nop

;}
RECOMP_FUNC void func_80673728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673728: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067372C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80673734: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80673738: jal         0x8067302C
    // 0x8067373C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8067302C(rdram, ctx);
        goto after_0;
    // 0x8067373C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_0:
    // 0x80673740: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80673744: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80673748: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067374C: addiu       $v1, $v1, 0x14C
    ctx->r3 = ADD32(ctx->r3, 0X14C);
    // 0x80673750: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80673754: jal         0x8067302C
    // 0x80673758: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8067302C(rdram, ctx);
        goto after_1;
    // 0x80673758: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x8067375C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80673760: beq         $v0, $zero, L_80673774
    if (ctx->r2 == 0) {
        // 0x80673764: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80673774;
    }
    // 0x80673764: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80673768: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067376C: b           L_8067377C
    // 0x80673770: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
        goto L_8067377C;
    // 0x80673770: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
L_80673774:
    // 0x80673774: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80673778: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
L_8067377C:
    // 0x8067377C: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(529, 0X6A0) << 16);
    // 0x80673780: addiu       $t8, $t8, 0x3680
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(529, 0X6A0));
    // 0x80673784: sw          $t8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r24;
    // 0x80673788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067378C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80673794: jr          $ra
    // 0x80673798: nop

    return;
    // 0x80673798: nop

;}
RECOMP_FUNC void func_806D74F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D74F0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806D74F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D74F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D74FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D7500: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(622, 0X1A84) << 16);
    // 0x806D7504: lui         $t0, 0x806D
    ctx->r8 = S32(RELOC_HI16(622, 0XEB0) << 16);
    // 0x806D7508: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x806D750C: addiu       $t0, $t0, 0x7A60
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(622, 0XEB0));
    // 0x806D7510: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D7514: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D7518: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D751C: lw          $t8, -0x79CC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(622, 0X1A84));
    // 0x806D7520: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x806D7524: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D7528: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x806D752C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x806D7530: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x806D7534: jal         0x8004700C
    // 0x806D7538: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D7538: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x806D753C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D7540: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x806D7544: beq         $v0, $zero, L_806D7748
    if (ctx->r2 == 0) {
        // 0x806D7548: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_806D7748;
    }
    // 0x806D7548: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x806D754C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7550: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x806D7554: jal         0x806D6BC0
    // 0x806D7558: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    func_806D6BC0(rdram, ctx);
        goto after_1;
    // 0x806D7558: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_1:
    // 0x806D755C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D7560: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x806D7564: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x806D7568: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806D756C: beql        $v0, $zero, L_806D757C
    if (ctx->r2 == 0) {
        // 0x806D7570: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_806D757C;
    }
    goto skip_0;
    // 0x806D7570: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x806D7574: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x806D7578: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_806D757C:
    // 0x806D757C: beq         $v0, $zero, L_806D758C
    if (ctx->r2 == 0) {
        // 0x806D7580: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_806D758C;
    }
    // 0x806D7580: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x806D7584: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x806D7588: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_806D758C:
    // 0x806D758C: bnel        $v0, $zero, L_806D7740
    if (ctx->r2 != 0) {
        // 0x806D7590: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D7740;
    }
    goto skip_1;
    // 0x806D7590: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x806D7594: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x806D7598: bnel        $t2, $zero, L_806D75CC
    if (ctx->r10 != 0) {
        // 0x806D759C: lw          $t6, 0xC($v1)
        ctx->r14 = MEM_W(ctx->r3, 0XC);
            goto L_806D75CC;
    }
    goto skip_2;
    // 0x806D759C: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    skip_2:
    // 0x806D75A0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806D75A4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x806D75A8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D75AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D75B0: lwc1        $f6, 0x84($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X84);
    // 0x806D75B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806D75B8: nop

    // 0x806D75BC: bc1fl       L_806D75CC
    if (!c1cs) {
        // 0x806D75C0: lw          $t6, 0xC($v1)
        ctx->r14 = MEM_W(ctx->r3, 0XC);
            goto L_806D75CC;
    }
    goto skip_3;
    // 0x806D75C0: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    skip_3:
    // 0x806D75C4: sw          $t4, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r12;
    // 0x806D75C8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
L_806D75CC:
    // 0x806D75CC: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(622, 0X1AD4) << 16);
    // 0x806D75D0: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x806D75D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D75D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806D75DC: lw          $t8, -0x797C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(622, 0X1AD4));
    // 0x806D75E0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806D75E4: sh          $t8, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r24;
    // 0x806D75E8: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x806D75EC: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x806D75F0: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x806D75F4: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x806D75F8: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x806D75FC: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x806D7600: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x806D7604: bnel        $v0, $at, L_806D76E4
    if (ctx->r2 != ctx->r1) {
        // 0x806D7608: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_806D76E4;
    }
    goto skip_4;
    // 0x806D7608: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    skip_4:
    // 0x806D760C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x806D7610: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x806D7614: beq         $t9, $zero, L_806D76D8
    if (ctx->r25 == 0) {
        // 0x806D7618: nop
    
            goto L_806D76D8;
    }
    // 0x806D7618: nop

    // 0x806D761C: lw          $t1, 0x180($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X180);
    // 0x806D7620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7624: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x806D7628: bne         $s0, $t1, L_806D76D8
    if (ctx->r16 != ctx->r9) {
        // 0x806D762C: addiu       $a2, $zero, 0x140
        ctx->r6 = ADD32(0, 0X140);
            goto L_806D76D8;
    }
    // 0x806D762C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x806D7630: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x806D7634: jal         0x80047534
    // 0x806D7638: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80047534(rdram, ctx);
        goto after_2;
    // 0x806D7638: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_2:
    // 0x806D763C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D7640: bne         $v0, $zero, L_806D7660
    if (ctx->r2 != 0) {
        // 0x806D7644: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_806D7660;
    }
    // 0x806D7644: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806D7648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D764C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D7650: jal         0x800474D8
    // 0x806D7654: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_800474D8(rdram, ctx);
        goto after_3;
    // 0x806D7654: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x806D7658: beq         $v0, $zero, L_806D7670
    if (ctx->r2 == 0) {
        // 0x806D765C: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_806D7670;
    }
    // 0x806D765C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_806D7660:
    // 0x806D7660: jal         0x80044658
    // 0x806D7664: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    func_80044658(rdram, ctx);
        goto after_4;
    // 0x806D7664: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x806D7668: b           L_806D774C
    // 0x806D766C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D774C;
    // 0x806D766C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D7670:
    // 0x806D7670: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x806D7674: jal         0x8004816C
    // 0x806D7678: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    func_8004816C(rdram, ctx);
        goto after_5;
    // 0x806D7678: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_5:
    // 0x806D767C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x806D7680: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x806D7684: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806D7688: lw          $v0, 0x1F4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X1F4);
    // 0x806D768C: sw          $t3, 0x138($t2)
    MEM_W(0X138, ctx->r10) = ctx->r11;
    // 0x806D7690: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x806D7694: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x806D7698: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806D769C: jal         0x80067BBC
    // 0x806D76A0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x806D76A0: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_6:
    // 0x806D76A4: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x806D76A8: jal         0x80067818
    // 0x806D76AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x806D76AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x806D76B0: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x806D76B4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D76B8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D76BC: lwc1        $f18, 0x88($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X88);
    // 0x806D76C0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x806D76C4: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x806D76C8: nop

    // 0x806D76CC: bc1f        L_806D76D8
    if (!c1cs) {
        // 0x806D76D0: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_806D76D8;
    }
    // 0x806D76D0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806D76D4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
L_806D76D8:
    // 0x806D76D8: b           L_806D7710
    // 0x806D76DC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
        goto L_806D7710;
    // 0x806D76DC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x806D76E0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
L_806D76E4:
    // 0x806D76E4: beq         $at, $zero, L_806D7710
    if (ctx->r1 == 0) {
        // 0x806D76E8: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_806D7710;
    }
    // 0x806D76E8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x806D76EC: lui         $a1, 0x806E
    ctx->r5 = S32(RELOC_HI16(622, 0X1AAC) << 16);
    // 0x806D76F0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x806D76F4: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x806D76F8: lw          $a1, -0x79A4($a1)
    ctx->r5 = MEM_W(ctx->r5, (int16_t)RELOC_LO16(622, 0X1AAC));
    // 0x806D76FC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x806D7700: jal         0x806D6C6C
    // 0x806D7704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D6C6C(rdram, ctx);
        goto after_8;
    // 0x806D7704: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806D7708: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806D770C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_806D7710:
    // 0x806D7710: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x806D7714: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x806D7718: bne         $at, $zero, L_806D773C
    if (ctx->r1 != 0) {
        // 0x806D771C: sw          $t9, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r25;
            goto L_806D773C;
    }
    // 0x806D771C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x806D7720: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x806D7724: jal         0x806D6D60
    // 0x806D7728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D6D60(rdram, ctx);
        goto after_9;
    // 0x806D7728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x806D772C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D7734: jal         0x806D7A20
    // 0x806D7738: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806D7A20(rdram, ctx);
        goto after_10;
    // 0x806D7738: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_10:
L_806D773C:
    // 0x806D773C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D7740:
    // 0x806D7740: jal         0x80048F84
    // 0x806D7744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_11;
    // 0x806D7744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_806D7748:
    // 0x806D7748: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D774C:
    // 0x806D774C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D7750: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x806D7754: jr          $ra
    // 0x806D7758: nop

    return;
    // 0x806D7758: nop

;}
RECOMP_FUNC void func_80080914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80080914: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80080918: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8008091C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80080920: lwc1        $f4, 0x2F70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2F70);
    // 0x80080924: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80080928: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8008092C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80080930: mul.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80080934: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80080938: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8008093C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80080940: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80080944: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80080948: swc1        $f14, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f14.u32l;
    // 0x8008094C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x80080950: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    // 0x80080954: jal         0x80082730
    // 0x80080958: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    fsin(rdram, ctx);
        goto after_0;
    // 0x80080958: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8008095C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80080960: jal         0x8008D250
    // 0x80080964: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80080964: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80080968: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8008096C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80080970: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80080974: jal         0x8008C150
    // 0x80080978: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    guNormalize(rdram, ctx);
        goto after_2;
    // 0x80080978: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8008097C: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80080980: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80080984: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80080988: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8008098C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80080990: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80080994: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80080998: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8008099C: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x800809A0: sub.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800809A4: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800809A8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800809AC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800809B0: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800809B4: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    // 0x800809B8: mul.s       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800809BC: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800809C0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800809C4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800809C8: nop

    // 0x800809CC: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800809D0: nop

    // 0x800809D4: mul.s       $f16, $f8, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800809D8: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800809DC: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800809E0: add.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800809E4: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800809E8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800809EC: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800809F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800809F4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800809F8: sub.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x800809FC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x80080A00: add.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80080A04: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x80080A08: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80080A0C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80080A10: mul.s       $f0, $f8, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80080A14: nop

    // 0x80080A18: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80080A1C: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80080A20: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80080A24: sub.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80080A28: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80080A2C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80080A30: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80080A34: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80080A38: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    // 0x80080A3C: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80080A40: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x80080A44: mul.s       $f14, $f10, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80080A48: nop

    // 0x80080A4C: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80080A50: add.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80080A54: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80080A58: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80080A5C: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80080A60: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80080A64: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80080A68: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80080A6C: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80080A70: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80080A74: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80080A78: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80080A7C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080A80: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80080A84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080A88: lwc1        $f12, 0x20($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80080A8C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080A90: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080A94: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080A98: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080A9C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080AA0: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80080AA4: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80080AA8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80080AAC: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080AB0: nop

    // 0x80080AB4: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080AB8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80080ABC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080AC0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080AC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080AC8: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x80080ACC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80080AD0: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80080AD4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080AD8: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80080ADC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080AE0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80080AE4: lwc1        $f2, 0x14($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80080AE8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080AEC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080AF0: lwc1        $f12, 0x24($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80080AF4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080AF8: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x80080AFC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80080B00: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080B04: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080B08: nop

    // 0x80080B0C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080B10: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080B14: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080B18: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080B1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080B20: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x80080B24: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80080B28: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80080B2C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080B30: nop

    // 0x80080B34: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080B38: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80080B3C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080B40: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080B44: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080B48: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    // 0x80080B4C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80080B50: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80080B54: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080B58: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80080B5C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080B60: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80080B64: lwc1        $f2, 0x18($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X18);
    // 0x80080B68: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080B6C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080B70: lwc1        $f12, 0x28($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X28);
    // 0x80080B74: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080B78: swc1        $f10, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f10.u32l;
    // 0x80080B7C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80080B80: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080B84: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080B88: nop

    // 0x80080B8C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080B90: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080B94: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080B98: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080B9C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080BA0: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80080BA4: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80080BA8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80080BAC: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080BB0: nop

    // 0x80080BB4: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080BB8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80080BBC: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080BC0: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080BC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080BC8: swc1        $f10, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f10.u32l;
    // 0x80080BCC: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80080BD0: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80080BD4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080BD8: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80080BDC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080BE0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80080BE4: lwc1        $f2, 0x1C($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80080BE8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080BEC: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080BF0: lwc1        $f12, 0x2C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80080BF4: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080BF8: swc1        $f10, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f10.u32l;
    // 0x80080BFC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80080C00: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080C04: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080C08: nop

    // 0x80080C0C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080C10: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080C14: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080C18: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080C1C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080C20: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
    // 0x80080C24: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80080C28: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80080C2C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80080C30: nop

    // 0x80080C34: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80080C38: lwc1        $f8, 0x60($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80080C3C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080C40: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80080C44: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80080C48: swc1        $f10, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f10.u32l;
    // 0x80080C4C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80080C50: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80080C54: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80080C58: nop

    // 0x80080C5C: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80080C60: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80080C64: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80080C68: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80080C6C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80080C70: swc1        $f10, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f10.u32l;
    // 0x80080C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080C78: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x80080C7C: jr          $ra
    // 0x80080C80: nop

    return;
    // 0x80080C80: nop

;}
RECOMP_FUNC void func_806E07B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E07B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E07B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E07B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E07BC: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(646, 0X340) << 16);
    // 0x806E07C0: lui         $a1, 0x806E
    ctx->r5 = S32(RELOC_HI16(646, 0X350) << 16);
    // 0x806E07C4: addiu       $a1, $a1, 0xB00
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(646, 0X350));
    // 0x806E07C8: addiu       $a0, $a0, 0xAF0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(646, 0X340));
    // 0x806E07CC: jal         0x8004667C
    // 0x806E07D0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x806E07D0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    after_0:
    // 0x806E07D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E07D8: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(646, 0XA8) << 16);
    // 0x806E07DC: addiu       $t6, $t6, 0x858
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(646, 0XA8));
    // 0x806E07E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806E07E4: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(646, 0X68) << 16);
    // 0x806E07E8: sw          $t6, -0x72F4($at)
    MEM_W(-0X72F4, ctx->r1) = ctx->r14;
    // 0x806E07EC: addiu       $v0, $v0, 0x818
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(646, 0X68));
    // 0x806E07F0: jr          $ra
    // 0x806E07F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806E07F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80709B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709B48: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80709B4C: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(718, 0X13C8) << 16);
    // 0x80709B50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80709B54: beq         $v0, $zero, L_80709B6C
    if (ctx->r2 == 0) {
        // 0x80709B58: addiu       $t1, $t1, -0x5A58
        ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(718, 0X13C8));
            goto L_80709B6C;
    }
    // 0x80709B58: addiu       $t1, $t1, -0x5A58
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(718, 0X13C8));
    // 0x80709B5C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80709B60: sw          $t6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r14;
    // 0x80709B64: jr          $ra
    // 0x80709B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80709B68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80709B6C:
    // 0x80709B6C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80709B70: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x80709B74: slti        $at, $v0, 0x23
    ctx->r1 = SIGNED(ctx->r2) < 0X23 ? 1 : 0;
    // 0x80709B78: bne         $at, $zero, L_80709B8C
    if (ctx->r1 != 0) {
        // 0x80709B7C: sw          $v0, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r2;
            goto L_80709B8C;
    }
    // 0x80709B7C: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80709B80: addiu       $v0, $zero, 0x22
    ctx->r2 = ADD32(0, 0X22);
    // 0x80709B84: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80709B88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80709B8C:
    // 0x80709B8C: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x80709B90: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x80709B94: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80709B98: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x80709B9C: lw          $t3, 0x4($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X4);
    // 0x80709BA0: sw          $t3, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r11;
    // 0x80709BA4: jr          $ra
    // 0x80709BA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80709BA8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8004CEC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CEC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004CEC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004CECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CED0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004CED4: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004CED8: jal         0x8004AF8C
    // 0x8004CEDC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8004AF8C(rdram, ctx);
        goto after_0;
    // 0x8004CEDC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8004CEE0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8004CEE4: swc1        $f0, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f0.u32l;
    // 0x8004CEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CEEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004CEF0: jr          $ra
    // 0x8004CEF4: nop

    return;
    // 0x8004CEF4: nop

;}
RECOMP_FUNC void func_80050790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80050794: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80050798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005079C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800507A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800507A4: jal         0x800579E4
    // 0x800507A8: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    func_800579E4(rdram, ctx);
        goto after_0;
    // 0x800507A8: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    after_0:
    // 0x800507AC: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800507B0: bne         $v0, $at, L_800507D0
    if (ctx->r2 != ctx->r1) {
        // 0x800507B4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800507D0;
    }
    // 0x800507B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800507B8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800507BC: addiu       $a0, $a0, 0x9D0
    ctx->r4 = ADD32(ctx->r4, 0X9D0);
    // 0x800507C0: jal         0x80071380
    // 0x800507C4: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800507C4: addiu       $a1, $zero, 0xB5
    ctx->r5 = ADD32(0, 0XB5);
    after_1:
    // 0x800507C8: b           L_80050810
    // 0x800507CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80050810;
    // 0x800507CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800507D0:
    // 0x800507D0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800507D4: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x800507D8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800507DC: addiu       $t7, $t7, -0x6150
    ctx->r15 = ADD32(ctx->r15, -0X6150);
    // 0x800507E0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800507E4: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800507E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800507EC: addiu       $a0, $a0, -0x5A48
    ctx->r4 = ADD32(ctx->r4, -0X5A48);
    // 0x800507F0: jal         0x80057B28
    // 0x800507F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80057B28(rdram, ctx);
        goto after_2;
    // 0x800507F4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x800507F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800507FC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80050800: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80050804: jal         0x80050720
    // 0x80050808: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_80050720(rdram, ctx);
        goto after_3;
    // 0x80050808: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8005080C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80050810:
    // 0x80050810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050814: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80050818: jr          $ra
    // 0x8005081C: nop

    return;
    // 0x8005081C: nop

;}
RECOMP_FUNC void func_8045A490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A490: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045A494: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045A498: jal         0x8045A830
    // 0x8045A49C: nop

    func_8045A830(rdram, ctx);
        goto after_0;
    // 0x8045A49C: nop

    after_0:
    // 0x8045A4A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045A4A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045A4A8: jr          $ra
    // 0x8045A4AC: nop

    return;
    // 0x8045A4AC: nop

;}
RECOMP_FUNC void func_8002C61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C61C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C620: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C624: addiu       $a1, $a1, -0x2B04
    ctx->r5 = ADD32(ctx->r5, -0X2B04);
    // 0x8002C628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C62C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C630: jal         0x80028118
    // 0x8002C634: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C634: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C638: jal         0x8002C600
    // 0x8002C63C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C600(rdram, ctx);
        goto after_1;
    // 0x8002C63C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C644: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C648: jr          $ra
    // 0x8002C64C: nop

    return;
    // 0x8002C64C: nop

;}
RECOMP_FUNC void func_8064F078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F078: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F07C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F080: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F084: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F088: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F08C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F090: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F094: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F098: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F09C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F0A0: jr          $ra
    // 0x8064F0A4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F0A4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800272EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800272EC: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x800272F0: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800272F4: addiu       $t7, $t7, 0x48FC
    ctx->r15 = ADD32(ctx->r15, 0X48FC);
    // 0x800272F8: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x800272FC: jr          $ra
    // 0x80027300: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    return;
    // 0x80027300: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80665C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80665C80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80665C84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80665C88: jal         0x8004700C
    // 0x80665C8C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80665C8C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80665C90: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80665C94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80665C98: lw          $v1, 0x1E0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1E0);
    // 0x80665C9C: beq         $v1, $zero, L_80665CAC
    if (ctx->r3 == 0) {
        // 0x80665CA0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80665CAC;
    }
    // 0x80665CA0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80665CA4: b           L_80665D6C
    // 0x80665CA8: sw          $t6, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r14;
        goto L_80665D6C;
    // 0x80665CA8: sw          $t6, 0x1E0($a1)
    MEM_W(0X1E0, ctx->r5) = ctx->r14;
L_80665CAC:
    // 0x80665CAC: beql        $v0, $zero, L_80665D70
    if (ctx->r2 == 0) {
        // 0x80665CB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80665D70;
    }
    goto skip_0;
    // 0x80665CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80665CB4: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x80665CB8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80665CBC: beql        $t7, $at, L_80665D70
    if (ctx->r15 == ctx->r1) {
        // 0x80665CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80665D70;
    }
    goto skip_1;
    // 0x80665CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80665CC4: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x80665CC8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80665CCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80665CD0: beql        $t8, $at, L_80665D70
    if (ctx->r24 == ctx->r1) {
        // 0x80665CD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80665D70;
    }
    goto skip_2;
    // 0x80665CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80665CD8: jal         0x800447C8
    // 0x80665CDC: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x80665CDC: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_1:
    // 0x80665CE0: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80665CE4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x80665CE8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80665CEC: lwc1        $f4, 0x3C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80665CF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80665CF4: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D74) << 16);
    // 0x80665CF8: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80665CFC: lwc1        $f6, 0x40($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80665D00: lwc1        $f10, 0x7A44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D74));
    // 0x80665D04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80665D08: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80665D0C: lwc1        $f8, 0x44($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X44);
    // 0x80665D10: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80665D14: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x80665D18: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80665D1C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80665D20: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80665D24: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80665D28: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80665D2C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80665D30: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80665D34: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80665D38: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80665D3C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80665D40: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x80665D44: jalr        $t9
    // 0x80665D48: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80665D48: nop

    after_2:
    // 0x80665D4C: jal         0x800677F8
    // 0x80665D50: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x80665D50: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_3:
    // 0x80665D54: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80665D58: lw          $t9, -0x7288($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7288);
    // 0x80665D5C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80665D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80665D64: jalr        $t9
    // 0x80665D68: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80665D68: nop

    after_4:
L_80665D6C:
    // 0x80665D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80665D70:
    // 0x80665D70: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80665D74: jr          $ra
    // 0x80665D78: nop

    return;
    // 0x80665D78: nop

;}
RECOMP_FUNC void func_80018B78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018B78: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80018B7C: lh          $t6, -0x6D90($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X6D90);
    // 0x80018B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80018B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80018B88: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80018B8C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80018B90: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80018B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018B98: bne         $t6, $at, L_80018C6C
    if (ctx->r14 != ctx->r1) {
        // 0x80018B9C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80018C6C;
    }
    // 0x80018B9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018BA0: blez        $a0, L_80018BB0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80018BA4: lui         $t7, 0x800A
        ctx->r15 = S32(0X800A << 16);
            goto L_80018BB0;
    }
    // 0x80018BA4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80018BA8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80018BAC: sw          $a0, -0x6D2C($at)
    MEM_W(-0X6D2C, ctx->r1) = ctx->r4;
L_80018BB0:
    // 0x80018BB0: lw          $t7, -0x6D2C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6D2C);
    // 0x80018BB4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80018BB8: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x80018BBC: beq         $at, $zero, L_80018C04
    if (ctx->r1 == 0) {
        // 0x80018BC0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80018C04;
    }
    // 0x80018BC0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80018BC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018BC8: addu        $at, $at, $t8
    gpr jr_addend_80018BD0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80018BCC: lw          $t8, -0xBC4($at)
    ctx->r24 = ADD32(ctx->r1, -0XBC4);
    // 0x80018BD0: jr          $t8
    // 0x80018BD4: nop

    switch (jr_addend_80018BD0 >> 2) {
        case 0: goto L_80018BD8; break;
        case 1: goto L_80018BE0; break;
        case 2: goto L_80018BE8; break;
        case 3: goto L_80018BF0; break;
        case 4: goto L_80018BF8; break;
        case 5: goto L_80018C00; break;
        default: switch_error(__func__, 0x80018BD0, 0x800AF43C);
    }
    // 0x80018BD4: nop

L_80018BD8:
    // 0x80018BD8: b           L_80018C04
    // 0x80018BDC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
        goto L_80018C04;
    // 0x80018BDC: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
L_80018BE0:
    // 0x80018BE0: b           L_80018C04
    // 0x80018BE4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
        goto L_80018C04;
    // 0x80018BE4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_80018BE8:
    // 0x80018BE8: b           L_80018C04
    // 0x80018BEC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
        goto L_80018C04;
    // 0x80018BEC: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
L_80018BF0:
    // 0x80018BF0: b           L_80018C04
    // 0x80018BF4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
        goto L_80018C04;
    // 0x80018BF4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
L_80018BF8:
    // 0x80018BF8: b           L_80018C04
    // 0x80018BFC: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
        goto L_80018C04;
    // 0x80018BFC: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
L_80018C00:
    // 0x80018C00: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_80018C04:
    // 0x80018C04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80018C08: lw          $v0, -0x6D30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D30);
    // 0x80018C0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018C10: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018C14: beql        $v0, $zero, L_80018C40
    if (ctx->r2 == 0) {
        // 0x80018C18: ori         $a1, $a1, 0x7800
        ctx->r5 = ctx->r5 | 0X7800;
            goto L_80018C40;
    }
    goto skip_0;
    // 0x80018C18: ori         $a1, $a1, 0x7800
    ctx->r5 = ctx->r5 | 0X7800;
    skip_0:
    // 0x80018C1C: beq         $v0, $at, L_80018C48
    if (ctx->r2 == ctx->r1) {
        // 0x80018C20: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80018C48;
    }
    // 0x80018C20: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80018C24: beq         $v0, $at, L_80018C54
    if (ctx->r2 == ctx->r1) {
        // 0x80018C28: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80018C54;
    }
    // 0x80018C28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018C2C: beql        $v0, $at, L_80018C64
    if (ctx->r2 == ctx->r1) {
        // 0x80018C30: addiu       $a1, $zero, 0x47FF
        ctx->r5 = ADD32(0, 0X47FF);
            goto L_80018C64;
    }
    goto skip_1;
    // 0x80018C30: addiu       $a1, $zero, 0x47FF
    ctx->r5 = ADD32(0, 0X47FF);
    skip_1:
    // 0x80018C34: b           L_80018C64
    // 0x80018C38: nop

        goto L_80018C64;
    // 0x80018C38: nop

    // 0x80018C3C: ori         $a1, $a1, 0x7800
    ctx->r5 = ctx->r5 | 0X7800;
L_80018C40:
    // 0x80018C40: b           L_80018C64
    // 0x80018C44: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
        goto L_80018C64;
    // 0x80018C44: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80018C48:
    // 0x80018C48: ori         $a1, $a1, 0x7800
    ctx->r5 = ctx->r5 | 0X7800;
    // 0x80018C4C: b           L_80018C64
    // 0x80018C50: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
        goto L_80018C64;
    // 0x80018C50: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_80018C54:
    // 0x80018C54: ori         $a1, $a1, 0x7800
    ctx->r5 = ctx->r5 | 0X7800;
    // 0x80018C58: b           L_80018C64
    // 0x80018C5C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
        goto L_80018C64;
    // 0x80018C5C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80018C60: addiu       $a1, $zero, 0x47FF
    ctx->r5 = ADD32(0, 0X47FF);
L_80018C64:
    // 0x80018C64: jal         0x8001AE64
    // 0x80018C68: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    func_8001AE64(rdram, ctx);
        goto after_0;
    // 0x80018C68: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    after_0:
L_80018C6C:
    // 0x80018C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80018C70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018C74: jr          $ra
    // 0x80018C78: nop

    return;
    // 0x80018C78: nop

    // 0x80018C7C: nop

;}
RECOMP_FUNC void func_8042F3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F3F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F3FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F400: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8042F404: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8042F408: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8042F40C: jal         0x80048F84
    // 0x8042F410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8042F410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8042F414: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042F418: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8042F41C: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x8042F420: lwc1        $f0, 0x40($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X40);
    // 0x8042F424: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8042F428: lwc1        $f2, 0x14($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8042F42C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8042F430: nop

    // 0x8042F434: bc1fl       L_8042F44C
    if (!c1cs) {
        // 0x8042F438: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8042F44C;
    }
    goto skip_0;
    // 0x8042F438: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x8042F43C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042F440: b           L_8042F464
    // 0x8042F444: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
        goto L_8042F464;
    // 0x8042F444: swc1        $f4, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f4.u32l;
    // 0x8042F448: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8042F44C:
    // 0x8042F44C: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8042F450: bc1f        L_8042F464
    if (!c1cs) {
        // 0x8042F454: nop
    
            goto L_8042F464;
    }
    // 0x8042F454: nop

    // 0x8042F458: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042F45C: nop

    // 0x8042F460: swc1        $f6, 0xE0($a2)
    MEM_W(0XE0, ctx->r6) = ctx->f6.u32l;
L_8042F464:
    // 0x8042F464: jal         0x8042F190
    // 0x8042F468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8042F190(rdram, ctx);
        goto after_1;
    // 0x8042F468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8042F46C: jal         0x8042F134
    // 0x8042F470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042F134(rdram, ctx);
        goto after_2;
    // 0x8042F470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8042F474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F47C: jr          $ra
    // 0x8042F480: nop

    return;
    // 0x8042F480: nop

;}
RECOMP_FUNC void func_8003241C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003241C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80032420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032424: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80032428: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8003242C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80032430: lbu         $t7, 0x111($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X111);
    // 0x80032434: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80032438: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8003243C: beq         $t7, $zero, L_8003244C
    if (ctx->r15 == 0) {
        // 0x80032440: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_8003244C;
    }
    // 0x80032440: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80032444: b           L_80032464
    // 0x80032448: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
        goto L_80032464;
    // 0x80032448: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
L_8003244C:
    // 0x8003244C: lbu         $t9, 0xF4($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XF4);
    // 0x80032450: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80032454: beq         $t9, $zero, L_80032464
    if (ctx->r25 == 0) {
        // 0x80032458: nop
    
            goto L_80032464;
    }
    // 0x80032458: nop

    // 0x8003245C: b           L_80032464
    // 0x80032460: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
        goto L_80032464;
    // 0x80032460: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
L_80032464:
    // 0x80032464: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80032468: jal         0x8003CC14
    // 0x8003246C: lw          $a3, 0x174($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X174);
    func_8003CC14(rdram, ctx);
        goto after_0;
    // 0x8003246C: lw          $a3, 0x174($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X174);
    after_0:
    // 0x80032470: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80032474: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80032478: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8003247C: lwc1        $f6, 0x68($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X68);
    // 0x80032480: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80032484: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80032488: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003248C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80032490: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80032494: swc1        $f16, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f16.u32l;
    // 0x80032498: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8003249C: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x800324A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800324A4: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x800324A8: lwc1        $f8, 0x40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X40);
    // 0x800324AC: lwc1        $f10, 0x8C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x800324B0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800324B4: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x800324B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800324BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800324C0: jr          $ra
    // 0x800324C4: nop

    return;
    // 0x800324C4: nop

;}
RECOMP_FUNC void func_80737C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737C4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80737C50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737C54: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80737C58: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80737C5C: blez        $v0, L_80737C6C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80737C60: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80737C6C;
    }
    // 0x80737C60: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80737C64: b           L_80737C94
    // 0x80737C68: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_80737C94;
    // 0x80737C68: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_80737C6C:
    // 0x80737C6C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80737C70: jal         0x80737BEC
    // 0x80737C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80737BEC(rdram, ctx);
        goto after_0;
    // 0x80737C74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80737C78: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80737C7C: beq         $v0, $zero, L_80737C94
    if (ctx->r2 == 0) {
        // 0x80737C80: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80737C94;
    }
    // 0x80737C80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80737C84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80737C88: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80737C8C: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x80737C90: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_80737C94:
    // 0x80737C94: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80737C98: lui         $a2, 0x8074
    ctx->r6 = S32(RELOC_HI16(736, 0X3A74) << 16);
    // 0x80737C9C: addiu       $a2, $a2, -0x6B2C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(736, 0X3A74));
    // 0x80737CA0: beql        $t9, $zero, L_80737D28
    if (ctx->r25 == 0) {
        // 0x80737CA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80737D28;
    }
    goto skip_0;
    // 0x80737CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80737CA8: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x80737CAC: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80737CB0: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80737CB4: bne         $at, $zero, L_80737CC8
    if (ctx->r1 != 0) {
        // 0x80737CB8: sw          $v0, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->r2;
            goto L_80737CC8;
    }
    // 0x80737CB8: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x80737CBC: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x80737CC0: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x80737CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80737CC8:
    // 0x80737CC8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80737CCC: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x80737CD0: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80737CD4: lui         $a1, 0x8074
    ctx->r5 = S32(RELOC_HI16(736, 0X3A2C) << 16);
    // 0x80737CD8: addiu       $a1, $a1, -0x6B74
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(736, 0X3A2C));
    // 0x80737CDC: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x80737CE0: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x80737CE4: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80737CE8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80737CEC: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80737CF0: lw          $t7, 0x1C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C);
    // 0x80737CF4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80737CF8: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x80737CFC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80737D00: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80737D04: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x80737D08: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80737D0C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80737D10: lw          $t3, 0x1C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X1C);
    // 0x80737D14: bnel        $t3, $at, L_80737D28
    if (ctx->r11 != ctx->r1) {
        // 0x80737D18: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80737D28;
    }
    goto skip_1;
    // 0x80737D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80737D1C: jal         0x80737570
    // 0x80737D20: nop

    func_80737570(rdram, ctx);
        goto after_1;
    // 0x80737D20: nop

    after_1:
    // 0x80737D24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80737D28:
    // 0x80737D28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80737D2C: jr          $ra
    // 0x80737D30: nop

    return;
    // 0x80737D30: nop

;}
RECOMP_FUNC void func_8002FF88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FF88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FF8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FF90: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FF94: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FF98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002FF9C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FFA0: jal         0x8002F678
    // 0x8002FFA4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FFA4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FFA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FFAC: beq         $v0, $zero, L_8002FFCC
    if (ctx->r2 == 0) {
        // 0x8002FFB0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8002FFCC;
    }
    // 0x8002FFB0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002FFB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002FFB8: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FFBC: addiu       $t6, $t6, -0x33C4
    ctx->r14 = ADD32(ctx->r14, -0X33C4);
    // 0x8002FFC0: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
    // 0x8002FFC4: swc1        $f0, 0xC4($a2)
    MEM_W(0XC4, ctx->r6) = ctx->f0.u32l;
    // 0x8002FFC8: swc1        $f0, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f0.u32l;
L_8002FFCC:
    // 0x8002FFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FFD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FFD4: jr          $ra
    // 0x8002FFD8: nop

    return;
    // 0x8002FFD8: nop

;}
RECOMP_FUNC void func_8002C824(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C824: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C82C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002C830: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002C834: jal         0x8002C57C
    // 0x8002C838: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8002C57C(rdram, ctx);
        goto after_0;
    // 0x8002C838: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002C83C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002C840: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8002C844: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002C848: sw          $v0, -0x7640($at)
    MEM_W(-0X7640, ctx->r1) = ctx->r2;
    // 0x8002C84C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8002C850: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C854: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x8002C858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C860: jr          $ra
    // 0x8002C864: nop

    return;
    // 0x8002C864: nop

;}
RECOMP_FUNC void func_805D3794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3794: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D3798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D379C: jal         0x805D3358
    // 0x805D37A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D3358(rdram, ctx);
        goto after_0;
    // 0x805D37A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D37A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D37A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D37AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805D37B0: jal         0x805D3B18
    // 0x805D37B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D37B4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D37B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D37BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D37C0: jr          $ra
    // 0x805D37C4: nop

    return;
    // 0x805D37C4: nop

;}
RECOMP_FUNC void func_8006E524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E524: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006E528: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006E52C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006E530: jal         0x8006E248
    // 0x8006E534: addiu       $a1, $a1, -0x1BBC
    ctx->r5 = ADD32(ctx->r5, -0X1BBC);
    func_8006E248(rdram, ctx);
        goto after_0;
    // 0x8006E534: addiu       $a1, $a1, -0x1BBC
    ctx->r5 = ADD32(ctx->r5, -0X1BBC);
    after_0:
    // 0x8006E538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006E53C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006E540: jr          $ra
    // 0x8006E544: nop

    return;
    // 0x8006E544: nop

;}
RECOMP_FUNC void func_804CCB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CCB2C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804CCB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CCB34: lw          $ra, 0x1F4($a0)
    ctx->r31 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CCB38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804CCB3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804CCB40: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x804CCB44: jal         0x8004921C
    // 0x804CCB48: nop

    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804CCB48: nop

    after_0:
    // 0x804CCB4C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x804CCB50: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x804CCB54: jal         0x8004921C
    // 0x804CCB58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804CCB58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804CCB5C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x804CCB60: lh          $t4, 0x1E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X1E);
    // 0x804CCB64: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804CCB68: lw          $t6, 0xC($ra)
    ctx->r14 = MEM_W(ctx->r31, 0XC);
    // 0x804CCB6C: lw          $a3, 0x0($ra)
    ctx->r7 = MEM_W(ctx->r31, 0X0);
    // 0x804CCB70: lw          $v1, 0x4($ra)
    ctx->r3 = MEM_W(ctx->r31, 0X4);
    // 0x804CCB74: beq         $t6, $zero, L_804CCCA4
    if (ctx->r14 == 0) {
        // 0x804CCB78: sll         $t4, $t4, 6
        ctx->r12 = S32(ctx->r12 << 6);
            goto L_804CCCA4;
    }
    // 0x804CCB78: sll         $t4, $t4, 6
    ctx->r12 = S32(ctx->r12 << 6);
    // 0x804CCB7C: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x804CCB80: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x804CCB84: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x804CCB88: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x804CCB8C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
L_804CCB90:
    // 0x804CCB90: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804CCB94: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    // 0x804CCB98: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x804CCB9C: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804CCBA0: sb          $t0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r8;
    // 0x804CCBA4: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x804CCBA8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x804CCBAC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804CCBB0: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x804CCBB4: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x804CCBB8: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x804CCBBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x804CCBC0: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x804CCBC4: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x804CCBC8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x804CCBCC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x804CCBD0: add.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x804CCBD4: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    // 0x804CCBD8: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x804CCBDC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804CCBE0: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x804CCBE4: sh          $a1, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r5;
    // 0x804CCBE8: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804CCBEC: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x804CCBF0: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x804CCBF4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x804CCBF8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x804CCBFC: sll         $t3, $t3, 16
    ctx->r11 = S32(ctx->r11 << 16);
    // 0x804CCC00: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x804CCC04: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x804CCC08: sll         $t2, $t2, 16
    ctx->r10 = S32(ctx->r10 << 16);
    // 0x804CCC0C: sra         $t2, $t2, 16
    ctx->r10 = S32(SIGNED(ctx->r10) >> 16);
    // 0x804CCC10: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x804CCC14: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x804CCC18: sh          $t3, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r11;
    // 0x804CCC1C: sh          $a2, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r6;
    // 0x804CCC20: sb          $t0, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r8;
    // 0x804CCC24: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
    // 0x804CCC28: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x804CCC2C: sh          $t5, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r13;
    // 0x804CCC30: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
    // 0x804CCC34: sh          $zero, 0x16($v1)
    MEM_H(0X16, ctx->r3) = 0;
    // 0x804CCC38: sh          $zero, 0x14($v1)
    MEM_H(0X14, ctx->r3) = 0;
    // 0x804CCC3C: sh          $a2, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r6;
    // 0x804CCC40: sh          $t2, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r10;
    // 0x804CCC44: sb          $zero, 0x2F($v1)
    MEM_B(0X2F, ctx->r3) = 0;
    // 0x804CCC48: sb          $t0, 0x2E($v1)
    MEM_B(0X2E, ctx->r3) = ctx->r8;
    // 0x804CCC4C: sb          $zero, 0x2D($v1)
    MEM_B(0X2D, ctx->r3) = 0;
    // 0x804CCC50: sb          $zero, 0x2C($v1)
    MEM_B(0X2C, ctx->r3) = 0;
    // 0x804CCC54: sh          $t5, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r13;
    // 0x804CCC58: sh          $t4, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r12;
    // 0x804CCC5C: sh          $zero, 0x26($v1)
    MEM_H(0X26, ctx->r3) = 0;
    // 0x804CCC60: sh          $zero, 0x24($v1)
    MEM_H(0X24, ctx->r3) = 0;
    // 0x804CCC64: sh          $t2, 0x30($v1)
    MEM_H(0X30, ctx->r3) = ctx->r10;
    // 0x804CCC68: sh          $t3, 0x32($v1)
    MEM_H(0X32, ctx->r3) = ctx->r11;
    // 0x804CCC6C: sb          $zero, 0x3F($v1)
    MEM_B(0X3F, ctx->r3) = 0;
    // 0x804CCC70: sb          $t0, 0x3E($v1)
    MEM_B(0X3E, ctx->r3) = ctx->r8;
    // 0x804CCC74: sb          $zero, 0x3D($v1)
    MEM_B(0X3D, ctx->r3) = 0;
    // 0x804CCC78: sb          $zero, 0x3C($v1)
    MEM_B(0X3C, ctx->r3) = 0;
    // 0x804CCC7C: sh          $zero, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = 0;
    // 0x804CCC80: sh          $t4, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r12;
    // 0x804CCC84: sh          $zero, 0x36($v1)
    MEM_H(0X36, ctx->r3) = 0;
    // 0x804CCC88: sh          $zero, 0x34($v1)
    MEM_H(0X34, ctx->r3) = 0;
    // 0x804CCC8C: lw          $t8, 0xC($ra)
    ctx->r24 = MEM_W(ctx->r31, 0XC);
    // 0x804CCC90: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x804CCC94: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x804CCC98: sltu        $at, $t1, $t8
    ctx->r1 = ctx->r9 < ctx->r24 ? 1 : 0;
    // 0x804CCC9C: bne         $at, $zero, L_804CCB90
    if (ctx->r1 != 0) {
        // 0x804CCCA0: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_804CCB90;
    }
    // 0x804CCCA0: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
L_804CCCA4:
    // 0x804CCCA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CCCA8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804CCCAC: jr          $ra
    // 0x804CCCB0: nop

    return;
    // 0x804CCCB0: nop

;}
RECOMP_FUNC void func_8006E7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E7C8: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8006E7CC: addiu       $at, $zero, 0x4070
    ctx->r1 = ADD32(0, 0X4070);
    // 0x8006E7D0: lui         $t7, 0x8007
    ctx->r15 = S32(0X8007 << 16);
    // 0x8006E7D4: bne         $t6, $at, L_8006E7E8
    if (ctx->r14 != ctx->r1) {
        // 0x8006E7D8: lui         $v0, 0x8007
        ctx->r2 = S32(0X8007 << 16);
            goto L_8006E7E8;
    }
    // 0x8006E7D8: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E7DC: addiu       $t7, $t7, -0xF24
    ctx->r15 = ADD32(ctx->r15, -0XF24);
    // 0x8006E7E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8006E7E4: sw          $t7, -0x71E8($at)
    MEM_W(-0X71E8, ctx->r1) = ctx->r15;
L_8006E7E8:
    // 0x8006E7E8: jr          $ra
    // 0x8006E7EC: addiu       $v0, $v0, -0xE88
    ctx->r2 = ADD32(ctx->r2, -0XE88);
    return;
    // 0x8006E7EC: addiu       $v0, $v0, -0xE88
    ctx->r2 = ADD32(ctx->r2, -0XE88);
;}
RECOMP_FUNC void func_806CB8BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB8BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CB8C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CB8C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806CB8C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806CB8CC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806CB8D0: jal         0x80067BBC
    // 0x806CB8D4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806CB8D4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806CB8D8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806CB8DC: jal         0x80067818
    // 0x806CB8E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806CB8E0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806CB8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CB8E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CB8EC: jr          $ra
    // 0x806CB8F0: nop

    return;
    // 0x806CB8F0: nop

;}
RECOMP_FUNC void func_80555214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80555214: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80555218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8055521C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80555220: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80555224: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80555228: addiu       $a1, $zero, 0x558
    ctx->r5 = ADD32(0, 0X558);
    // 0x8055522C: addiu       $t0, $a0, 0x348
    ctx->r8 = ADD32(ctx->r4, 0X348);
    // 0x80555230: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80555234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80555238: jal         0x80065728
    // 0x8055523C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8055523C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80555240: lui         $a0, 0x8055
    ctx->r4 = S32(RELOC_HI16(357, 0X19A8) << 16);
    // 0x80555244: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80555248: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8055524C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80555250: addiu       $a0, $a0, 0x6898
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(357, 0X19A8));
    // 0x80555254: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80555258:
    // 0x80555258: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8055525C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80555260: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x80555264: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80555268: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8055526C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x80555270: sw          $t6, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r14;
    // 0x80555274: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80555278: sw          $t7, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r15;
    // 0x8055527C: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80555280: bne         $at, $zero, L_80555258
    if (ctx->r1 != 0) {
        // 0x80555284: sw          $t6, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r14;
            goto L_80555258;
    }
    // 0x80555284: sw          $t6, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r14;
    // 0x80555288: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8055528C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
L_80555290:
    // 0x80555290: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80555294: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80555298: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8055529C: swc1        $f4, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f4.u32l;
    // 0x805552A0: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805552A4: swc1        $f6, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f6.u32l;
    // 0x805552A8: lwc1        $f8, 0x3C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x805552AC: swc1        $f8, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = ctx->f8.u32l;
    // 0x805552B0: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805552B4: swc1        $f10, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f10.u32l;
    // 0x805552B8: lwc1        $f16, 0x3C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x805552BC: swc1        $f16, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f16.u32l;
    // 0x805552C0: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805552C4: swc1        $f18, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f18.u32l;
    // 0x805552C8: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x805552CC: swc1        $f4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f4.u32l;
    // 0x805552D0: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x805552D4: bne         $v1, $a0, L_80555290
    if (ctx->r3 != ctx->r4) {
        // 0x805552D8: swc1        $f6, -0x8($v0)
        MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
            goto L_80555290;
    }
    // 0x805552D8: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x805552DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805552E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805552E4: jr          $ra
    // 0x805552E8: nop

    return;
    // 0x805552E8: nop

;}
RECOMP_FUNC void func_806D8D28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8D28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D8D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D8D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D8D34: jal         0x80045A34
    // 0x806D8D38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D8D38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x806D8D3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D8D40: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(625, 0X544) << 16);
    // 0x806D8D44: bne         $v0, $zero, L_806D8D5C
    if (ctx->r2 != 0) {
        // 0x806D8D48: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806D8D5C;
    }
    // 0x806D8D48: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806D8D4C: jal         0x800445A4
    // 0x806D8D50: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D8D50: nop

    after_1:
    // 0x806D8D54: b           L_806D8DB8
    // 0x806D8D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D8DB8;
    // 0x806D8D58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D8D5C:
    // 0x806D8D5C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806D8D60: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806D8D64: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806D8D68: addiu       $t6, $t6, -0x71FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(625, 0X544));
    // 0x806D8D6C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806D8D70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D8D74: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806D8D78: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806D8D7C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806D8D80: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x806D8D84: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806D8D88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x806D8D8C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x806D8D90: jal         0x8005FD1C
    // 0x806D8D94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x806D8D94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x806D8D98: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806D8D9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D8DA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D8DA4: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x806D8DA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806D8DAC: jal         0x806D8DC4
    // 0x806D8DB0: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    func_806D8DC4(rdram, ctx);
        goto after_3;
    // 0x806D8DB0: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    after_3:
    // 0x806D8DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D8DB8:
    // 0x806D8DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D8DBC: jr          $ra
    // 0x806D8DC0: nop

    return;
    // 0x806D8DC0: nop

;}
RECOMP_FUNC void func_8073EAC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EAD0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8073EAD4: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X2318) << 16);
    // 0x8073EAD8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8073EADC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073EAE0: addiu       $t6, $t6, 0xB08
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X2318));
    // 0x8073EAE4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8073EAE8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073EAEC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073EAF0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8073EAF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073EAF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073EAFC: jal         0x8073EB14
    // 0x8073EB00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8073EB14(rdram, ctx);
        goto after_0;
    // 0x8073EB00: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8073EB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EB0C: jr          $ra
    // 0x8073EB10: nop

    return;
    // 0x8073EB10: nop

;}
RECOMP_FUNC void func_806662F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806662F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806662F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806662FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80666300: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80666304: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80666308: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8066630C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80666310: jal         0x80047090
    // 0x80666314: addiu       $a0, $zero, 0x4551
    ctx->r4 = ADD32(0, 0X4551);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80666314: addiu       $a0, $zero, 0x4551
    ctx->r4 = ADD32(0, 0X4551);
    after_0:
    // 0x80666318: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8066631C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80666320: beq         $v0, $at, L_80666400
    if (ctx->r2 == ctx->r1) {
        // 0x80666324: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80666400;
    }
    // 0x80666324: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80666328: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x8066632C: beq         $a0, $zero, L_80666354
    if (ctx->r4 == 0) {
        // 0x80666330: xor         $t0, $t6, $a0
        ctx->r8 = ctx->r14 ^ ctx->r4;
            goto L_80666354;
    }
    // 0x80666330: xor         $t0, $t6, $a0
    ctx->r8 = ctx->r14 ^ ctx->r4;
    // 0x80666334: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80666338: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8066633C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80666340: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80666344: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80666348: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8066634C: b           L_80666374
    // 0x80666350: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
        goto L_80666374;
    // 0x80666350: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_80666354:
    // 0x80666354: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80666358: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8066635C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80666360: nop

    // 0x80666364: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80666368: mul.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8066636C: nop

    // 0x80666370: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
L_80666374:
    // 0x80666374: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80666378: lui         $at, 0x4551
    ctx->r1 = S32(0X4551 << 16);
    // 0x8066637C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80666380: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x80666384: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80666388: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8066638C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80666390: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80666394: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80666398: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8066639C: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806663A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806663A4: jal         0x8004613C
    // 0x806663A8: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806663A8: nop

    after_1:
    // 0x806663AC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x806663B0: beq         $v0, $zero, L_80666400
    if (ctx->r2 == 0) {
        // 0x806663B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80666400;
    }
    // 0x806663B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806663B8: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x806663BC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x806663C0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x806663C4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x806663C8: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x806663CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806663D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806663D4: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806663D8: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x806663DC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x806663E0: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x806663E4: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x806663E8: sw          $t0, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r8;
    // 0x806663EC: swc1        $f10, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f10.u32l;
    // 0x806663F0: jal         0x8066626C
    // 0x806663F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8066626C(rdram, ctx);
        goto after_2;
    // 0x806663F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x806663F8: b           L_80666404
    // 0x806663FC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80666404;
    // 0x806663FC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80666400:
    // 0x80666400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80666404:
    // 0x80666404: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80666408: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8066640C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80666410: jr          $ra
    // 0x80666414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80666414: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8043CCA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043CCA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043CCA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043CCAC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8043CCB0: lw          $a0, 0x330($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X330);
    // 0x8043CCB4: jal         0x80064E84
    // 0x8043CCB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8043CCB8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8043CCBC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8043CCC0: lw          $a0, 0x338($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X338);
    // 0x8043CCC4: beql        $a0, $zero, L_8043CCE4
    if (ctx->r4 == 0) {
        // 0x8043CCC8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043CCE4;
    }
    goto skip_0;
    // 0x8043CCC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043CCCC: lw          $v0, 0x33C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X33C);
    // 0x8043CCD0: beql        $v0, $zero, L_8043CCE4
    if (ctx->r2 == 0) {
        // 0x8043CCD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043CCE4;
    }
    goto skip_1;
    // 0x8043CCD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043CCD8: jalr        $v0
    // 0x8043CCDC: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8043CCDC: nop

    after_1:
    // 0x8043CCE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043CCE4:
    // 0x8043CCE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043CCE8: jr          $ra
    // 0x8043CCEC: nop

    return;
    // 0x8043CCEC: nop

;}
RECOMP_FUNC void func_805300EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805300EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805300F0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805300F4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805300F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805300FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80530100: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80530104: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80530108: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8053010C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80530110: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(333, 0X2388) << 16);
    // 0x80530114: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80530118: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8053011C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80530120: lw          $t1, 0x148($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(333, 0X2388));
    // 0x80530124: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80530128: jal         0x80048378
    // 0x8053012C: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x8053012C: sw          $t1, -0xA4($a0)
    MEM_W(-0XA4, ctx->r4) = ctx->r9;
    after_0:
    // 0x80530130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530138: jr          $ra
    // 0x8053013C: nop

    return;
    // 0x8053013C: nop

;}
RECOMP_FUNC void func_806F2AF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2AF4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806F2AF8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806F2AFC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806F2B00: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806F2B04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806F2B08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806F2B0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F2B10: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806F2B14: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(679, 0X1B8C) << 16);
    // 0x806F2B18: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806F2B1C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F2B20: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806F2B24: lw          $t1, 0x310C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(679, 0X1B8C));
    // 0x806F2B28: jr          $ra
    // 0x806F2B2C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806F2B2C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800502E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800502E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800502EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800502F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800502F4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800502F8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800502FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80050300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80050304: lbu         $v0, 0x68($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X68);
    // 0x80050308: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8005030C: lw          $s2, 0x1B8($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1B8);
    // 0x80050310: bne         $v0, $zero, L_80050320
    if (ctx->r2 != 0) {
        // 0x80050314: addiu       $s0, $s4, 0x6C
        ctx->r16 = ADD32(ctx->r20, 0X6C);
            goto L_80050320;
    }
    // 0x80050314: addiu       $s0, $s4, 0x6C
    ctx->r16 = ADD32(ctx->r20, 0X6C);
    // 0x80050318: b           L_800503E4
    // 0x8005031C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800503E4;
    // 0x8005031C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050320:
    // 0x80050320: sb          $v0, 0x69($s4)
    MEM_B(0X69, ctx->r20) = ctx->r2;
    // 0x80050324: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80050328: blez        $v0, L_800503D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005032C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800503D4;
    }
    // 0x8005032C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80050330: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80050334:
    // 0x80050334: jal         0x8004F42C
    // 0x80050338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004F42C(rdram, ctx);
        goto after_0;
    // 0x80050338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8005033C: lh          $t7, 0x52($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X52);
    // 0x80050340: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80050344: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80050348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005034C: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x80050350: mfhi        $t8
    ctx->r24 = hi;
    // 0x80050354: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80050358: bne         $t7, $zero, L_80050364
    if (ctx->r15 != 0) {
        // 0x8005035C: nop
    
            goto L_80050364;
    }
    // 0x8005035C: nop

    // 0x80050360: break       7
    do_break(2147812192);
L_80050364:
    // 0x80050364: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80050368: bne         $t7, $at, L_8005037C
    if (ctx->r15 != ctx->r1) {
        // 0x8005036C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8005037C;
    }
    // 0x8005036C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80050370: bne         $t6, $at, L_8005037C
    if (ctx->r14 != ctx->r1) {
        // 0x80050374: nop
    
            goto L_8005037C;
    }
    // 0x80050374: nop

    // 0x80050378: break       6
    do_break(2147812216);
L_8005037C:
    // 0x8005037C: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x80050380: jal         0x8004F42C
    // 0x80050384: nop

    func_8004F42C(rdram, ctx);
        goto after_1;
    // 0x80050384: nop

    after_1:
    // 0x80050388: lh          $t1, 0x54($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X54);
    // 0x8005038C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80050390: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80050394: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80050398: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x8005039C: mfhi        $t2
    ctx->r10 = hi;
    // 0x800503A0: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800503A4: bne         $t1, $zero, L_800503B0
    if (ctx->r9 != 0) {
        // 0x800503A8: nop
    
            goto L_800503B0;
    }
    // 0x800503A8: nop

    // 0x800503AC: break       7
    do_break(2147812268);
L_800503B0:
    // 0x800503B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800503B4: bne         $t1, $at, L_800503C8
    if (ctx->r9 != ctx->r1) {
        // 0x800503B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800503C8;
    }
    // 0x800503B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800503BC: bne         $t0, $at, L_800503C8
    if (ctx->r8 != ctx->r1) {
        // 0x800503C0: nop
    
            goto L_800503C8;
    }
    // 0x800503C0: nop

    // 0x800503C4: break       6
    do_break(2147812292);
L_800503C8:
    // 0x800503C8: sh          $t3, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r11;
    // 0x800503CC: bnel        $s1, $s3, L_80050334
    if (ctx->r17 != ctx->r19) {
        // 0x800503D0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80050334;
    }
    goto skip_0;
    // 0x800503D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_800503D4:
    // 0x800503D4: sb          $zero, 0x68($s4)
    MEM_B(0X68, ctx->r20) = 0;
    // 0x800503D8: jal         0x8004F26C
    // 0x800503DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8004F26C(rdram, ctx);
        goto after_2;
    // 0x800503DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x800503E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800503E4:
    // 0x800503E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800503E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800503EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800503F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800503F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800503F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800503FC: jr          $ra
    // 0x80050400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80050400: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8046AC6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AC6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046AC70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046AC74: jal         0x8046A4A4
    // 0x8046AC78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8046A4A4(rdram, ctx);
        goto after_0;
    // 0x8046AC78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046AC7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8046AC80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8046AC84: jal         0x8046A424
    // 0x8046AC88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_8046A424(rdram, ctx);
        goto after_1;
    // 0x8046AC88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8046AC8C: beq         $v0, $zero, L_8046AC9C
    if (ctx->r2 == 0) {
        // 0x8046AC90: nop
    
            goto L_8046AC9C;
    }
    // 0x8046AC90: nop

    // 0x8046AC94: b           L_8046ACA4
    // 0x8046AC98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8046ACA4;
    // 0x8046AC98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8046AC9C:
    // 0x8046AC9C: jal         0x8046AB28
    // 0x8046ACA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8046AB28(rdram, ctx);
        goto after_2;
    // 0x8046ACA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
L_8046ACA4:
    // 0x8046ACA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046ACA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046ACAC: jr          $ra
    // 0x8046ACB0: nop

    return;
    // 0x8046ACB0: nop

;}
RECOMP_FUNC void func_800068F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800068F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800068FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80006900: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006908: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000690C: jal         0x800073BC
    // 0x80006910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006914: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80006918: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000691C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80006920: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80006924: beql        $t7, $zero, L_8000693C
    if (ctx->r15 == 0) {
        // 0x80006928: lw          $t8, 0x24($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X24);
            goto L_8000693C;
    }
    goto skip_0;
    // 0x80006928: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8000692C: jal         0x8000684C
    // 0x80006930: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8000684C(rdram, ctx);
        goto after_1;
    // 0x80006930: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80006934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80006938: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
L_8000693C:
    // 0x8000693C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80006940: beql        $t9, $zero, L_80006954
    if (ctx->r25 == 0) {
        // 0x80006944: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006954;
    }
    goto skip_1;
    // 0x80006944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80006948: jal         0x80006FE0
    // 0x8000694C: nop

    func_80006FE0(rdram, ctx);
        goto after_2;
    // 0x8000694C: nop

    after_2:
    // 0x80006950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006954:
    // 0x80006954: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80006958: jr          $ra
    // 0x8000695C: nop

    return;
    // 0x8000695C: nop

;}
RECOMP_FUNC void func_8001EB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EB3C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001EB40: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x8001EB44: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8001EB48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001EB4C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001EB50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001EB54: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x8001EB58: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8001EB5C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8001EB60: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x8001EB64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001EB68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001EB6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EB70: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001EB74: jal         0x800534C0
    // 0x8001EB78: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8001EB78: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8001EB7C: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001EB80: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001EB84: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EB88: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001EB8C: andi        $t0, $v0, 0x7FF
    ctx->r8 = ctx->r2 & 0X7FF;
    // 0x8001EB90: andi        $t8, $t7, 0xF8
    ctx->r24 = ctx->r15 & 0XF8;
    // 0x8001EB94: bne         $t8, $at, L_8001EBA0
    if (ctx->r24 != ctx->r1) {
        // 0x8001EB98: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001EBA0;
    }
    // 0x8001EB98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EB9C: sh          $t0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r8;
L_8001EBA0:
    // 0x8001EBA0: lhu         $t1, 0x36($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X36);
    // 0x8001EBA4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001EBA8: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001EBAC: beq         $t1, $zero, L_8001EC08
    if (ctx->r9 == 0) {
        // 0x8001EBB0: lwc1        $f14, 0x3C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8001EC08;
    }
    // 0x8001EBB0: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001EBB4: beql        $t1, $at, L_8001EC0C
    if (ctx->r9 == ctx->r1) {
        // 0x8001EBB8: addiu       $t2, $sp, 0x28
        ctx->r10 = ADD32(ctx->r29, 0X28);
            goto L_8001EC0C;
    }
    goto skip_0;
    // 0x8001EBB8: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    skip_0:
    // 0x8001EBBC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EBC0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001EBC4: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001EBC8: beq         $v0, $at, L_8001EC08
    if (ctx->r2 == ctx->r1) {
        // 0x8001EBCC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001EC08;
    }
    // 0x8001EBCC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EBD0: beq         $v0, $at, L_8001EC08
    if (ctx->r2 == ctx->r1) {
        // 0x8001EBD4: or          $a0, $t1, $zero
        ctx->r4 = ctx->r9 | 0;
            goto L_8001EC08;
    }
    // 0x8001EBD4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8001EBD8: jal         0x8004A97C
    // 0x8001EBDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_1;
    // 0x8001EBDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001EBE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001EBE4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001EBE8: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8001EBEC: nop

    // 0x8001EBF0: bc1f        L_8001EC00
    if (!c1cs) {
        // 0x8001EBF4: nop
    
            goto L_8001EC00;
    }
    // 0x8001EBF4: nop

    // 0x8001EBF8: b           L_8001ED2C
    // 0x8001EBFC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8001ED2C;
    // 0x8001EBFC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
L_8001EC00:
    // 0x8001EC00: b           L_8001ED2C
    // 0x8001EC04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001ED2C;
    // 0x8001EC04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001EC08:
    // 0x8001EC08: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
L_8001EC0C:
    // 0x8001EC0C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001EC10: jal         0x800534C0
    // 0x8001EC14: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    func_800534C0(rdram, ctx);
        goto after_2;
    // 0x8001EC14: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8001EC18: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001EC1C: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001EC20: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EC24: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001EC28: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x8001EC2C: andi        $t4, $t3, 0xF8
    ctx->r12 = ctx->r11 & 0XF8;
    // 0x8001EC30: bne         $t4, $at, L_8001EC3C
    if (ctx->r12 != ctx->r1) {
        // 0x8001EC34: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001EC3C;
    }
    // 0x8001EC34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001EC38: sh          $t6, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r14;
L_8001EC3C:
    // 0x8001EC3C: lhu         $t7, 0x36($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X36);
    // 0x8001EC40: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001EC44: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001EC48: beq         $t7, $zero, L_8001EC84
    if (ctx->r15 == 0) {
        // 0x8001EC4C: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8001EC84;
    }
    // 0x8001EC4C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001EC50: beql        $t7, $at, L_8001EC88
    if (ctx->r15 == ctx->r1) {
        // 0x8001EC54: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8001EC88;
    }
    goto skip_1;
    // 0x8001EC54: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_1:
    // 0x8001EC58: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001EC5C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001EC60: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001EC64: beq         $v0, $at, L_8001EC84
    if (ctx->r2 == ctx->r1) {
        // 0x8001EC68: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001EC84;
    }
    // 0x8001EC68: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001EC6C: beq         $v0, $at, L_8001EC84
    if (ctx->r2 == ctx->r1) {
        // 0x8001EC70: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8001EC84;
    }
    // 0x8001EC70: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001EC74: jal         0x8004A97C
    // 0x8001EC78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_3;
    // 0x8001EC78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8001EC7C: b           L_8001ED30
    // 0x8001EC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001ED30;
    // 0x8001EC80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EC84:
    // 0x8001EC84: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8001EC88:
    // 0x8001EC88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001EC8C: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x8001EC90: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8001EC94: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8001EC98: jal         0x800534C0
    // 0x8001EC9C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    func_800534C0(rdram, ctx);
        goto after_4;
    // 0x8001EC9C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_4:
    // 0x8001ECA0: addiu       $v1, $sp, 0x36
    ctx->r3 = ADD32(ctx->r29, 0X36);
    // 0x8001ECA4: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x8001ECA8: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8001ECAC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8001ECB0: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x8001ECB4: andi        $t0, $t9, 0xF8
    ctx->r8 = ctx->r25 & 0XF8;
    // 0x8001ECB8: bnel        $t0, $at, L_8001ECC8
    if (ctx->r8 != ctx->r1) {
        // 0x8001ECBC: lhu         $t3, 0x36($sp)
        ctx->r11 = MEM_HU(ctx->r29, 0X36);
            goto L_8001ECC8;
    }
    goto skip_2;
    // 0x8001ECBC: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
    skip_2:
    // 0x8001ECC0: sh          $t2, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r10;
    // 0x8001ECC4: lhu         $t3, 0x36($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X36);
L_8001ECC8:
    // 0x8001ECC8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8001ECCC: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001ECD0: beq         $t3, $zero, L_8001ED2C
    if (ctx->r11 == 0) {
        // 0x8001ECD4: nop
    
            goto L_8001ED2C;
    }
    // 0x8001ECD4: nop

    // 0x8001ECD8: beq         $t3, $at, L_8001ED2C
    if (ctx->r11 == ctx->r1) {
        // 0x8001ECDC: nop
    
            goto L_8001ED2C;
    }
    // 0x8001ECDC: nop

    // 0x8001ECE0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8001ECE4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8001ECE8: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8001ECEC: beq         $v0, $at, L_8001ED2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001ECF0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8001ED2C;
    }
    // 0x8001ECF0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001ECF4: beq         $v0, $at, L_8001ED2C
    if (ctx->r2 == ctx->r1) {
        // 0x8001ECF8: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8001ED2C;
    }
    // 0x8001ECF8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8001ECFC: jal         0x8004A97C
    // 0x8001ED00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A97C(rdram, ctx);
        goto after_5;
    // 0x8001ED00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8001ED04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001ED08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001ED0C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8001ED10: nop

    // 0x8001ED14: bc1f        L_8001ED24
    if (!c1cs) {
        // 0x8001ED18: nop
    
            goto L_8001ED24;
    }
    // 0x8001ED18: nop

    // 0x8001ED1C: b           L_8001ED2C
    // 0x8001ED20: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
        goto L_8001ED2C;
    // 0x8001ED20: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
L_8001ED24:
    // 0x8001ED24: b           L_8001ED2C
    // 0x8001ED28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001ED2C;
    // 0x8001ED28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001ED2C:
    // 0x8001ED2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001ED30:
    // 0x8001ED30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001ED34: jr          $ra
    // 0x8001ED38: nop

    return;
    // 0x8001ED38: nop

;}
RECOMP_FUNC void func_804525A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804525A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x804525AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804525B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804525B4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804525B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x804525BC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x804525C0: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804525C4: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x804525C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804525CC: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x804525D0: jal         0x804503F8
    // 0x804525D4: lw          $a1, 0x6A28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6A28);
    func_804503F8(rdram, ctx);
        goto after_0;
    // 0x804525D4: lw          $a1, 0x6A28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6A28);
    after_0:
    // 0x804525D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x804525DC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804525E0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804525E4: sw          $t6, 0x6A20($at)
    MEM_W(0X6A20, ctx->r1) = ctx->r14;
    // 0x804525E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804525EC: ori         $at, $at, 0x6A24
    ctx->r1 = ctx->r1 | 0X6A24;
    // 0x804525F0: addu        $v1, $s0, $at
    ctx->r3 = ADD32(ctx->r16, ctx->r1);
    // 0x804525F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804525F8: ori         $at, $at, 0x6A28
    ctx->r1 = ctx->r1 | 0X6A28;
    // 0x804525FC: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80452600: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80452604: addiu       $t8, $zero, -0x64
    ctx->r24 = ADD32(0, -0X64);
    // 0x80452608: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045260C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80452610: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80452614: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80452618: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8045261C: sw          $t9, 0x6A2C($at)
    MEM_W(0X6A2C, ctx->r1) = ctx->r25;
    // 0x80452620: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452624: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80452628: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8045262C: sw          $t0, 0x6A30($at)
    MEM_W(0X6A30, ctx->r1) = ctx->r8;
    // 0x80452630: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80452634: jal         0x8044EFA0
    // 0x80452638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044EFA0(rdram, ctx);
        goto after_1;
    // 0x80452638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8045263C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80452640: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80452644: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80452648: jal         0x80446CD0
    // 0x8045264C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    func_80446CD0(rdram, ctx);
        goto after_2;
    // 0x8045264C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    after_2:
    // 0x80452650: jal         0x804457C0
    // 0x80452654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804457C0(rdram, ctx);
        goto after_3;
    // 0x80452654: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80452658: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8045265C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452660: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80452664: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80452668: jal         0x80450200
    // 0x8045266C: sw          $t1, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r9;
    func_80450200(rdram, ctx);
        goto after_4;
    // 0x8045266C: sw          $t1, 0x6CE4($at)
    MEM_W(0X6CE4, ctx->r1) = ctx->r9;
    after_4:
    // 0x80452670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80452674: jal         0x8044FEC4
    // 0x80452678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8044FEC4(rdram, ctx);
        goto after_5;
    // 0x80452678: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8045267C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80452680: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80452684: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80452688: jr          $ra
    // 0x8045268C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8045268C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80028170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028174: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028178: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002817C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80028180: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80028184: sw          $t6, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r14;
    // 0x80028188: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002818C: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x80028190: jalr        $t9
    // 0x80028194: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80028194: nop

    after_0:
    // 0x80028198: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8002819C: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x800281A0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800281A4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800281A8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x800281AC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800281B0: lw          $v1, 0x168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X168);
    // 0x800281B4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800281B8: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x800281BC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800281C0: lw          $a1, 0x16C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X16C);
    // 0x800281C4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x800281C8: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x800281CC: lw          $t0, 0x4C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4C);
    // 0x800281D0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800281D4: lw          $t1, -0x7250($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7250);
    // 0x800281D8: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x800281DC: lw          $t8, 0x28($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X28);
    // 0x800281E0: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x800281E4: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x800281E8: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800281EC: lh          $a3, 0x0($t7)
    ctx->r7 = MEM_H(ctx->r15, 0X0);
    // 0x800281F0: lw          $a2, 0x54($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X54);
    // 0x800281F4: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800281F8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800281FC: jal         0x800245A0
    // 0x80028200: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_800245A0(rdram, ctx);
        goto after_1;
    // 0x80028200: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_1:
    // 0x80028204: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80028208: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8002820C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80028210: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80028214: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80028218: jr          $ra
    // 0x8002821C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002821C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_807C49D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C49D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x807C49D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C49D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807C49DC: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C49E0: lui         $t8, 0x807C
    ctx->r24 = S32(RELOC_HI16(910, 0XAF0) << 16);
    // 0x807C49E4: addiu       $t8, $t8, 0x54B0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(910, 0XAF0));
    // 0x807C49E8: lw          $t6, 0x1C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C);
    // 0x807C49EC: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x807C49F0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x807C49F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807C49F8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x807C49FC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x807C4A00: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x807C4A04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807C4A08: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x807C4A0C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x807C4A10: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x807C4A14: jal         0x8004700C
    // 0x807C4A18: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807C4A18: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    after_0:
    // 0x807C4A1C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x807C4A20: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x807C4A24: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x807C4A28: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x807C4A2C: beq         $v0, $zero, L_807C4CBC
    if (ctx->r2 == 0) {
        // 0x807C4A30: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807C4CBC;
    }
    // 0x807C4A30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807C4A34: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x807C4A38: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807C4A3C: beq         $t9, $zero, L_807C4A7C
    if (ctx->r25 == 0) {
        // 0x807C4A40: neg.s       $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
            goto L_807C4A7C;
    }
    // 0x807C4A40: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x807C4A44: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807C4A48: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x807C4A4C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x807C4A50: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x807C4A54: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807C4A58: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x807C4A5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807C4A60: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807C4A64: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807C4A68: nop

    // 0x807C4A6C: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807C4A70: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x807C4A74: b           L_807C4AAC
    // 0x807C4A78: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
        goto L_807C4AAC;
    // 0x807C4A78: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_807C4A7C:
    // 0x807C4A7C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x807C4A80: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x807C4A84: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x807C4A88: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x807C4A8C: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x807C4A90: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x807C4A94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807C4A98: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807C4A9C: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807C4AA0: nop

    // 0x807C4AA4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807C4AA8: nop

L_807C4AAC:
    // 0x807C4AAC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x807C4AB0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x807C4AB4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807C4AB8: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x807C4ABC: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x807C4AC0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x807C4AC4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x807C4AC8: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x807C4ACC: jal         0x80066DE4
    // 0x807C4AD0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x807C4AD0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x807C4AD4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x807C4AD8: jal         0x80066E88
    // 0x807C4ADC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x807C4ADC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x807C4AE0: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x807C4AE4: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x807C4AE8: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x807C4AEC: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x807C4AF0: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807C4AF4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x807C4AF8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x807C4AFC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x807C4B00: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x807C4B04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807C4B08: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x807C4B0C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807C4B10: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x807C4B14: mul.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x807C4B18: nop

    // 0x807C4B1C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x807C4B20: nop

    // 0x807C4B24: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x807C4B28: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x807C4B2C: mul.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x807C4B30: nop

    // 0x807C4B34: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x807C4B38: swc1        $f4, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f4.u32l;
    // 0x807C4B3C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807C4B40: swc1        $f6, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->f6.u32l;
    // 0x807C4B44: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x807C4B48: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x807C4B4C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x807C4B50: nop

    // 0x807C4B54: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807C4B58: mul.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x807C4B5C: nop

    // 0x807C4B60: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x807C4B64: nop

    // 0x807C4B68: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x807C4B6C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807C4B70: mul.s       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x807C4B74: nop

    // 0x807C4B78: mul.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x807C4B7C: swc1        $f4, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f4.u32l;
    // 0x807C4B80: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x807C4B84: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x807C4B88: lw          $v1, 0x138($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X138);
    // 0x807C4B8C: sw          $v1, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r3;
    // 0x807C4B90: sw          $v1, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r3;
    // 0x807C4B94: lwc1        $f4, 0x6C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x807C4B98: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807C4B9C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x807C4BA0: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x807C4BA4: lwc1        $f8, 0x70($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X70);
    // 0x807C4BA8: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807C4BAC: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x807C4BB0: swc1        $f10, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f10.u32l;
    // 0x807C4BB4: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807C4BB8: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
    // 0x807C4BBC: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x807C4BC0: bne         $t6, $zero, L_807C4BDC
    if (ctx->r14 != 0) {
        // 0x807C4BC4: nop
    
            goto L_807C4BDC;
    }
    // 0x807C4BC4: nop

    // 0x807C4BC8: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807C4BCC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807C4BD0: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x807C4BD4: b           L_807C4BEC
    // 0x807C4BD8: swc1        $f10, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f10.u32l;
        goto L_807C4BEC;
    // 0x807C4BD8: swc1        $f10, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f10.u32l;
L_807C4BDC:
    // 0x807C4BDC: lwc1        $f6, 0x50($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X50);
    // 0x807C4BE0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x807C4BE4: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807C4BE8: swc1        $f4, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f4.u32l;
L_807C4BEC:
    // 0x807C4BEC: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x807C4BF0: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(910, 0X1140) << 16);
    // 0x807C4BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C4BF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807C4BFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807C4C00: lw          $t9, 0x5B00($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(910, 0X1140));
    // 0x807C4C04: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x807C4C08: sh          $t9, 0x144($a2)
    MEM_H(0X144, ctx->r6) = ctx->r25;
    // 0x807C4C0C: lbu         $t0, 0x18($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X18);
    // 0x807C4C10: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x807C4C14: bnel        $v0, $t0, L_807C4C84
    if (ctx->r2 != ctx->r8) {
        // 0x807C4C18: lw          $t7, 0x2C($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X2C);
            goto L_807C4C84;
    }
    goto skip_0;
    // 0x807C4C18: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    skip_0:
    // 0x807C4C1C: lbu         $t1, 0x30($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X30);
    // 0x807C4C20: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x807C4C24: bnel        $t1, $at, L_807C4C84
    if (ctx->r9 != ctx->r1) {
        // 0x807C4C28: lw          $t7, 0x2C($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X2C);
            goto L_807C4C84;
    }
    goto skip_1;
    // 0x807C4C28: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    skip_1:
    // 0x807C4C2C: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x807C4C30: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x807C4C34: andi        $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 & 0XF00;
    // 0x807C4C38: beql        $t4, $zero, L_807C4C84
    if (ctx->r12 == 0) {
        // 0x807C4C3C: lw          $t7, 0x2C($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X2C);
            goto L_807C4C84;
    }
    goto skip_2;
    // 0x807C4C3C: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    skip_2:
    // 0x807C4C40: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x807C4C44: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x807C4C48: addiu       $t5, $t5, -0x7218
    ctx->r13 = ADD32(ctx->r13, -0X7218);
    // 0x807C4C4C: beql        $t5, $t6, L_807C4C84
    if (ctx->r13 == ctx->r14) {
        // 0x807C4C50: lw          $t7, 0x2C($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X2C);
            goto L_807C4C84;
    }
    goto skip_3;
    // 0x807C4C50: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    skip_3:
    // 0x807C4C54: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x807C4C58: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807C4C5C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807C4C60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807C4C64: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x807C4C68: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x807C4C6C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x807C4C70: nop

    // 0x807C4C74: bc1fl       L_807C4C84
    if (!c1cs) {
        // 0x807C4C78: lw          $t7, 0x2C($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X2C);
            goto L_807C4C84;
    }
    goto skip_4;
    // 0x807C4C78: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
    skip_4:
    // 0x807C4C7C: sw          $v0, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r2;
    // 0x807C4C80: lw          $t7, 0x2C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C);
L_807C4C84:
    // 0x807C4C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C4C88: beql        $t7, $zero, L_807C4CC0
    if (ctx->r15 == 0) {
        // 0x807C4C8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807C4CC0;
    }
    goto skip_5;
    // 0x807C4C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x807C4C90: jal         0x80047534
    // 0x807C4C94: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_80047534(rdram, ctx);
        goto after_3;
    // 0x807C4C94: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_3:
    // 0x807C4C98: bne         $v0, $zero, L_807C4CB4
    if (ctx->r2 != 0) {
        // 0x807C4C9C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_807C4CB4;
    }
    // 0x807C4C9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x807C4CA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C4CA4: jal         0x800474D8
    // 0x807C4CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800474D8(rdram, ctx);
        goto after_4;
    // 0x807C4CA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x807C4CAC: beql        $v0, $zero, L_807C4CC0
    if (ctx->r2 == 0) {
        // 0x807C4CB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807C4CC0;
    }
    goto skip_6;
    // 0x807C4CB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
L_807C4CB4:
    // 0x807C4CB4: jal         0x800447C8
    // 0x807C4CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x807C4CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_807C4CBC:
    // 0x807C4CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C4CC0:
    // 0x807C4CC0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807C4CC4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x807C4CC8: jr          $ra
    // 0x807C4CCC: nop

    return;
    // 0x807C4CCC: nop

;}
RECOMP_FUNC void func_80437048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80437048: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8043704C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80437050: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80437054: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x80437058: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8043705C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80437060: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80437064: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80437068: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8043706C: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80437070: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
    // 0x80437074: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80437078: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8043707C: swc1        $f18, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f18.u32l;
    // 0x80437080: bc1fl       L_8043709C
    if (!c1cs) {
        // 0x80437084: lwc1        $f8, 0x4($a2)
        ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
            goto L_8043709C;
    }
    goto skip_0;
    // 0x80437084: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    skip_0:
    // 0x80437088: sqrt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = sqrtf(ctx->f18.fl);
    // 0x8043708C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80437090: b           L_804370A0
    // 0x80437094: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
        goto L_804370A0;
    // 0x80437094: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80437098: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
L_8043709C:
    // 0x8043709C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
L_804370A0:
    // 0x804370A0: lw          $t6, 0x174($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X174);
    // 0x804370A4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804370A8: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x804370AC: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x804370B0: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x804370B4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x804370B8: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x804370BC: lwc1        $f0, 0x4($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X4);
    // 0x804370C0: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x804370C4: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x804370C8: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x804370CC: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x804370D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804370D4: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x804370D8: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x804370DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804370E0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x804370E4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804370E8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804370EC: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x804370F0: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804370F4: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x804370F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804370FC: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x80437100: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80437104: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80437108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043710C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80437110: jr          $ra
    // 0x80437114: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x80437114: swc1        $f8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_807106E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807106E4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x807106E8: lui         $t7, 0x8071
    ctx->r15 = S32(RELOC_HI16(724, 0X18C4) << 16);
    // 0x807106EC: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x807106F0: lbu         $t7, 0xCB4($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(724, 0X18C4));
    // 0x807106F4: lw          $v0, 0x16C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X16C);
    // 0x807106F8: jr          $ra
    // 0x807106FC: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
    return;
    // 0x807106FC: sb          $t7, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_8002DBE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DBE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DBEC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DBF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DBF4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8002DBF8: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8002DBFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DC00: jal         0x8002B9E4
    // 0x8002DC04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002DC04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002DC08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DC0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DC10: sb          $zero, 0x1AD($v0)
    MEM_B(0X1AD, ctx->r2) = 0;
    // 0x8002DC14: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x8002DC18: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002DC1C: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x8002DC20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DC24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DC28: jr          $ra
    // 0x8002DC2C: nop

    return;
    // 0x8002DC2C: nop

;}
RECOMP_FUNC void func_80682070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80682074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80682078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8068207C: jal         0x80682014
    // 0x80682080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80682014(rdram, ctx);
        goto after_0;
    // 0x80682080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80682084: bne         $v0, $zero, L_80682094
    if (ctx->r2 != 0) {
        // 0x80682088: lui         $t6, 0x8068
        ctx->r14 = S32(RELOC_HI16(550, 0X1A24) << 16);
            goto L_80682094;
    }
    // 0x80682088: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X1A24) << 16);
    // 0x8068208C: b           L_806820E8
    // 0x80682090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806820E8;
    // 0x80682090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80682094:
    // 0x80682094: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80682098: addiu       $t6, $t6, 0x1E34
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X1A24));
    // 0x8068209C: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X2224) << 16);
    // 0x806820A0: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x806820A4: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806820A8: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x806820AC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806820B0: addiu       $t8, $t8, 0x2634
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(550, 0X2224));
    // 0x806820B4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806820B8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806820BC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806820C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806820C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806820C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806820CC: jal         0x806820FC
    // 0x806820D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806820FC(rdram, ctx);
        goto after_1;
    // 0x806820D0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806820D4: jal         0x80681F68
    // 0x806820D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80681F68(rdram, ctx);
        goto after_2;
    // 0x806820D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806820DC: jal         0x80682058
    // 0x806820E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80682058(rdram, ctx);
        goto after_3;
    // 0x806820E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806820E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806820E8:
    // 0x806820E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806820EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806820F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806820F4: jr          $ra
    // 0x806820F8: nop

    return;
    // 0x806820F8: nop

;}
RECOMP_FUNC void func_80468820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80468820: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(135, 0XBD4) << 16);
    // 0x80468824: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80468828: jr          $ra
    // 0x8046882C: addiu       $v0, $v0, -0x6C0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(135, 0XBD4));
    return;
    // 0x8046882C: addiu       $v0, $v0, -0x6C0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(135, 0XBD4));
;}
RECOMP_FUNC void func_80533A80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80533A84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80533A88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80533A8C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80533A90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80533A94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80533A98: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80533A9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80533AA0: jal         0x80047090
    // 0x80533AA4: addiu       $a0, $zero, 0x4040
    ctx->r4 = ADD32(0, 0X4040);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80533AA4: addiu       $a0, $zero, 0x4040
    ctx->r4 = ADD32(0, 0X4040);
    after_0:
    // 0x80533AA8: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80533AAC: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80533AB0: bne         $a0, $v0, L_80533AC0
    if (ctx->r4 != ctx->r2) {
        // 0x80533AB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80533AC0;
    }
    // 0x80533AB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80533AB8: b           L_80533B20
    // 0x80533ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80533B20;
    // 0x80533ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80533AC0:
    // 0x80533AC0: beq         $a0, $v1, L_80533B1C
    if (ctx->r4 == ctx->r3) {
        // 0x80533AC4: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80533B1C;
    }
    // 0x80533AC4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80533AC8: ori         $at, $at, 0x2800
    ctx->r1 = ctx->r1 | 0X2800;
    // 0x80533ACC: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x80533AD0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80533AD4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80533AD8: jal         0x8004613C
    // 0x80533ADC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80533ADC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80533AE0: beq         $v0, $zero, L_80533B1C
    if (ctx->r2 == 0) {
        // 0x80533AE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80533B1C;
    }
    // 0x80533AE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80533AE8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80533AEC: jal         0x80047F9C
    // 0x80533AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80533AF0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80533AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80533AF8: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80533AFC: jal         0x80533980
    // 0x80533B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80533980(rdram, ctx);
        goto after_3;
    // 0x80533B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80533B04: bnel        $v0, $zero, L_80533B20
    if (ctx->r2 != 0) {
        // 0x80533B08: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_80533B20;
    }
    goto skip_0;
    // 0x80533B08: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    skip_0:
    // 0x80533B0C: jal         0x800445A4
    // 0x80533B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x80533B10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80533B14: b           L_80533B20
    // 0x80533B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80533B20;
    // 0x80533B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80533B1C:
    // 0x80533B1C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80533B20:
    // 0x80533B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80533B24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80533B28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80533B2C: jr          $ra
    // 0x80533B30: nop

    return;
    // 0x80533B30: nop

;}
RECOMP_FUNC void func_80581308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581308: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058130C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581310: jal         0x80580C70
    // 0x80581314: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80580C70(rdram, ctx);
        goto after_0;
    // 0x80581314: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581318: jal         0x8058121C
    // 0x8058131C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8058121C(rdram, ctx);
        goto after_1;
    // 0x8058131C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80581320: jal         0x805812C8
    // 0x80581324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805812C8(rdram, ctx);
        goto after_2;
    // 0x80581324: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80581328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8058132C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581330: jr          $ra
    // 0x80581334: nop

    return;
    // 0x80581334: nop

;}
RECOMP_FUNC void func_80551518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80551518: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8055151C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80551520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80551524: jal         0x80551620
    // 0x80551528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80551620(rdram, ctx);
        goto after_0;
    // 0x80551528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8055152C: beq         $v0, $zero, L_805515EC
    if (ctx->r2 == 0) {
        // 0x80551530: nop
    
            goto L_805515EC;
    }
    // 0x80551530: nop

    // 0x80551534: jal         0x80551658
    // 0x80551538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80551658(rdram, ctx);
        goto after_1;
    // 0x80551538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8055153C: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80551540: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80551544: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80551548: lui         $t7, 0x8055
    ctx->r15 = S32(RELOC_HI16(354, 0X4078) << 16);
    // 0x8055154C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80551550: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80551554: addiu       $t7, $t7, 0x4B98
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(354, 0X4078));
    // 0x80551558: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8055155C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80551560: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80551564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80551568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8055156C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80551570: jal         0x8055484C
    // 0x80551574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8055484C(rdram, ctx);
        goto after_2;
    // 0x80551574: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80551578: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8055157C: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(354, 0X18E8) << 16);
    // 0x80551580: addiu       $t9, $t9, 0x2408
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(354, 0X18E8));
    // 0x80551584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80551588: jal         0x80550B5C
    // 0x8055158C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80550B5C(rdram, ctx);
        goto after_3;
    // 0x8055158C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x80551590: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x80551594: lui         $a1, 0x8055
    ctx->r5 = S32(RELOC_HI16(354, 0X4080) << 16);
    // 0x80551598: addiu       $a1, $a1, 0x4BA0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(354, 0X4080));
    // 0x8055159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805515A0: jal         0x80554A94
    // 0x805515A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80554A94(rdram, ctx);
        goto after_4;
    // 0x805515A4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x805515A8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805515AC: lui         $a1, 0x8055
    ctx->r5 = S32(RELOC_HI16(354, 0X408C) << 16);
    // 0x805515B0: addiu       $a1, $a1, 0x4BAC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(354, 0X408C));
    // 0x805515B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805515B8: jal         0x80554A94
    // 0x805515BC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    func_80554A94(rdram, ctx);
        goto after_5;
    // 0x805515BC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    after_5:
    // 0x805515C0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805515C4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x805515C8: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x805515CC: beq         $t1, $zero, L_805515DC
    if (ctx->r9 == 0) {
        // 0x805515D0: nop
    
            goto L_805515DC;
    }
    // 0x805515D0: nop

    // 0x805515D4: bne         $v0, $zero, L_805515FC
    if (ctx->r2 != 0) {
        // 0x805515D8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805515FC;
    }
    // 0x805515D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_805515DC:
    // 0x805515DC: jal         0x800445A4
    // 0x805515E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x805515E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x805515E4: b           L_80551610
    // 0x805515E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80551610;
    // 0x805515E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805515EC:
    // 0x805515EC: jal         0x800445A4
    // 0x805515F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x805515F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805515F4: b           L_80551610
    // 0x805515F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80551610;
    // 0x805515F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805515FC:
    // 0x805515FC: jal         0x80553FF0
    // 0x80551600: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80553FF0(rdram, ctx);
        goto after_8;
    // 0x80551600: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_8:
    // 0x80551604: jal         0x805514AC
    // 0x80551608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805514AC(rdram, ctx);
        goto after_9;
    // 0x80551608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8055160C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80551610:
    // 0x80551610: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80551614: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80551618: jr          $ra
    // 0x8055161C: nop

    return;
    // 0x8055161C: nop

;}
RECOMP_FUNC void func_80430124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80430128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043012C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430130: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BCC) << 16);
    // 0x80430134: lwc1        $f4, 0x1CAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BCC));
    // 0x80430138: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8043013C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80430140: nop

    // 0x80430144: bc1f        L_8043015C
    if (!c1cs) {
        // 0x80430148: nop
    
            goto L_8043015C;
    }
    // 0x80430148: nop

    // 0x8043014C: jal         0x8043029C
    // 0x80430150: nop

    func_8043029C(rdram, ctx);
        goto after_0;
    // 0x80430150: nop

    after_0:
    // 0x80430154: b           L_80430168
    // 0x80430158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80430168;
    // 0x80430158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043015C:
    // 0x8043015C: jal         0x80430198
    // 0x80430160: nop

    func_80430198(rdram, ctx);
        goto after_1;
    // 0x80430160: nop

    after_1:
    // 0x80430164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80430168:
    // 0x80430168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043016C: jr          $ra
    // 0x80430170: nop

    return;
    // 0x80430170: nop

;}
RECOMP_FUNC void func_80534620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80534624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534628: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8053462C: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80534630: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80534634: beql        $a1, $at, L_8053466C
    if (ctx->r5 == ctx->r1) {
        // 0x80534638: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8053466C;
    }
    goto skip_0;
    // 0x80534638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8053463C: jal         0x80067930
    // 0x80534640: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80534640: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_0:
    // 0x80534644: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534648: bne         $v0, $at, L_8053465C
    if (ctx->r2 != ctx->r1) {
        // 0x8053464C: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_8053465C;
    }
    // 0x8053464C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80534650: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80534654: jal         0x80067878
    // 0x80534658: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80534658: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
L_8053465C:
    // 0x8053465C: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80534660: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80534664: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
    // 0x80534668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8053466C:
    // 0x8053466C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534670: jr          $ra
    // 0x80534674: nop

    return;
    // 0x80534674: nop

;}
RECOMP_FUNC void func_8064E7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E7C0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8064E7C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8064E7C8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8064E7CC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8064E7D0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8064E7D4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8064E7D8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064E7DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8064E7E0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8064E7E4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8064E7E8: lui         $t1, 0x8065
    ctx->r9 = S32(RELOC_HI16(498, 0XB8C) << 16);
    // 0x8064E7EC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8064E7F0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8064E7F4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8064E7F8: lw          $t1, -0x17A4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(498, 0XB8C));
    // 0x8064E7FC: jr          $ra
    // 0x8064E800: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8064E800: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8064E804: nop

    // 0x8064E808: nop

    // 0x8064E80C: nop

;}
RECOMP_FUNC void func_8003994C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003994C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80039950: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80039954: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80039958: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8003995C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80039960: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80039964: lw          $t8, -0x1410($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1410);
    // 0x80039968: jr          $ra
    // 0x8003996C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8003996C: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805C6500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6500: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x805C6504: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x805C6508: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x805C650C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x805C6510: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x805C6514: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x805C6518: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x805C651C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x805C6520: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x805C6524: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x805C6528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C652C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x805C6530: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805C6534: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805C6538: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805C653C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C6540: jal         0x8004921C
    // 0x805C6544: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805C6544: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    after_0:
    // 0x805C6548: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x805C654C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C6550: jal         0x8004921C
    // 0x805C6554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805C6554: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805C6558: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x805C655C: addiu       $s5, $sp, 0xAC
    ctx->r21 = ADD32(ctx->r29, 0XAC);
    // 0x805C6560: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x805C6564: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x805C6568: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805C656C: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x805C6570: sw          $t8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r24;
    // 0x805C6574: lw          $s2, 0x1F4($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X1F4);
    // 0x805C6578: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805C657C: jal         0x80077338
    // 0x805C6580: lw          $s1, 0x88($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X88);
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x805C6580: lw          $s1, 0x88($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X88);
    after_2:
    // 0x805C6584: lh          $v0, 0x168($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X168);
    // 0x805C6588: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C658C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x805C6590: beq         $v0, $at, L_805C65A8
    if (ctx->r2 == ctx->r1) {
        // 0x805C6594: addiu       $a0, $v0, -0x18
        ctx->r4 = ADD32(ctx->r2, -0X18);
            goto L_805C65A8;
    }
    // 0x805C6594: addiu       $a0, $v0, -0x18
    ctx->r4 = ADD32(ctx->r2, -0X18);
    // 0x805C6598: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x805C659C: beq         $v0, $at, L_805C65A8
    if (ctx->r2 == ctx->r1) {
        // 0x805C65A0: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_805C65A8;
    }
    // 0x805C65A0: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x805C65A4: bne         $v0, $at, L_805C65B8
    if (ctx->r2 != ctx->r1) {
        // 0x805C65A8: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_805C65B8;
    }
L_805C65A8:
    // 0x805C65A8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x805C65AC: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(447, 0X3988) << 16);
    // 0x805C65B0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x805C65B4: lwc1        $f0, -0x6188($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(447, 0X3988));
L_805C65B8:
    // 0x805C65B8: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(447, 0X3978) << 16);
    // 0x805C65BC: addiu       $v0, $v0, -0x6198
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(447, 0X3978));
    // 0x805C65C0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805C65C4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x805C65C8: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x805C65CC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x805C65D0: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x805C65D4: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x805C65D8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x805C65DC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805C65E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805C65E4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x805C65E8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x805C65EC: nop

    // 0x805C65F0: sh          $t7, 0x68($s2)
    MEM_H(0X68, ctx->r18) = ctx->r15;
    // 0x805C65F4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805C65F8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x805C65FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x805C6600: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x805C6604: nop

    // 0x805C6608: sh          $t9, 0x78($s2)
    MEM_H(0X78, ctx->r18) = ctx->r25;
    // 0x805C660C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805C6610: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x805C6614: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805C6618: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x805C661C: nop

    // 0x805C6620: sh          $t7, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r15;
    // 0x805C6624: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x805C6628: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x805C662C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x805C6630: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x805C6634: nop

    // 0x805C6638: sh          $t9, 0x98($s2)
    MEM_H(0X98, ctx->r18) = ctx->r25;
    // 0x805C663C: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6640: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x805C6644: ori         $t9, $t9, 0xACB0
    ctx->r25 = ctx->r25 | 0XACB0;
    // 0x805C6648: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x805C664C: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x805C6650: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x805C6654: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x805C6658: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x805C665C: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x805C6660: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x805C6664: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x805C6668: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x805C666C: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x805C6670: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x805C6674: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6678: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x805C667C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x805C6680: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x805C6684: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x805C6688: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x805C668C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805C6690: jal         0x8007711C
    // 0x805C6694: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x805C6694: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    after_3:
    // 0x805C6698: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x805C669C: multu       $s3, $s4
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C66A0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x805C66A4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805C66A8: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x805C66AC: ori         $t6, $t6, 0x40FF
    ctx->r14 = ctx->r14 | 0X40FF;
    // 0x805C66B0: addiu       $t7, $s2, 0x68
    ctx->r15 = ADD32(ctx->r18, 0X68);
    // 0x805C66B4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x805C66B8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x805C66BC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x805C66C0: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x805C66C4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x805C66C8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805C66CC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x805C66D0: addiu       $s0, $v1, 0x7
    ctx->r16 = ADD32(ctx->r3, 0X7);
    // 0x805C66D4: sra         $s0, $s0, 3
    ctx->r16 = S32(SIGNED(ctx->r16) >> 3);
    // 0x805C66D8: addiu       $t8, $s4, -0x1
    ctx->r24 = ADD32(ctx->r20, -0X1);
    // 0x805C66DC: mflo        $t5
    ctx->r13 = lo;
    // 0x805C66E0: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x805C66E4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805C66E8: andi        $s0, $s0, 0x1FF
    ctx->r16 = ctx->r16 & 0X1FF;
    // 0x805C66EC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x805C66F0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x805C66F4: sll         $s0, $s0, 9
    ctx->r16 = S32(ctx->r16 << 9);
    // 0x805C66F8: sra         $t5, $t5, 1
    ctx->r13 = S32(SIGNED(ctx->r13) >> 1);
    // 0x805C66FC: or          $t3, $s2, $zero
    ctx->r11 = ctx->r18 | 0;
    // 0x805C6700: lui         $t0, 0x805D
    ctx->r8 = S32(RELOC_HI16(447, 0X3A98) << 16);
    // 0x805C6704: addiu       $t0, $t0, -0x6078
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(447, 0X3A98));
    // 0x805C6708: lui         $s2, 0xFD50
    ctx->r18 = S32(0XFD50 << 16);
    // 0x805C670C: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x805C6710: or          $s1, $t7, $t6
    ctx->r17 = ctx->r15 | ctx->r14;
    // 0x805C6714: lui         $s4, 0xF550
    ctx->r20 = S32(0XF550 << 16);
    // 0x805C6718: addiu       $s3, $zero, 0x7E0
    ctx->r19 = ADD32(0, 0X7E0);
    // 0x805C671C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x805C6720: bgez        $v1, L_805C6730
    if (SIGNED(ctx->r3) >= 0) {
        // 0x805C6724: sra         $a3, $v1, 3
        ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
            goto L_805C6730;
    }
    // 0x805C6724: sra         $a3, $v1, 3
    ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
    // 0x805C6728: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x805C672C: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_805C6730:
    // 0x805C6730: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x805C6734: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x805C6738: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x805C673C: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x805C6740: lui         $s6, 0xF300
    ctx->r22 = S32(0XF300 << 16);
    // 0x805C6744: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x805C6748: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
L_805C674C:
    // 0x805C674C: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6750: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x805C6754: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x805C6758: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805C675C: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x805C6760: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x805C6764: lh          $t7, 0x168($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X168);
    // 0x805C6768: lw          $t8, 0xA0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA0);
    // 0x805C676C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x805C6770: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C6774: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805C6778: mflo        $t6
    ctx->r14 = lo;
    // 0x805C677C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x805C6780: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805C6784: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6788: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x805C678C: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x805C6790: sw          $s4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r20;
    // 0x805C6794: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x805C6798: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    // 0x805C679C: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x805C67A0: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x805C67A4: sw          $t9, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r25;
    // 0x805C67A8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x805C67AC: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
    // 0x805C67B0: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x805C67B4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x805C67B8: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x805C67BC: sw          $s6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r22;
    // 0x805C67C0: beq         $at, $zero, L_805C67D0
    if (ctx->r1 == 0) {
        // 0x805C67C4: or          $t4, $t7, $zero
        ctx->r12 = ctx->r15 | 0;
            goto L_805C67D0;
    }
    // 0x805C67C4: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x805C67C8: b           L_805C67D0
    // 0x805C67CC: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
        goto L_805C67D0;
    // 0x805C67CC: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
L_805C67D0:
    // 0x805C67D0: bgtz        $a3, L_805C67E0
    if (SIGNED(ctx->r7) > 0) {
        // 0x805C67D4: nop
    
            goto L_805C67E0;
    }
    // 0x805C67D4: nop

    // 0x805C67D8: b           L_805C67E0
    // 0x805C67DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_805C67E0;
    // 0x805C67DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_805C67E0:
    // 0x805C67E0: bgtz        $a3, L_805C67F0
    if (SIGNED(ctx->r7) > 0) {
        // 0x805C67E4: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_805C67F0;
    }
    // 0x805C67E4: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x805C67E8: b           L_805C67F0
    // 0x805C67EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_805C67F0;
    // 0x805C67EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805C67F0:
    // 0x805C67F0: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x805C67F4: mflo        $t9
    ctx->r25 = lo;
    // 0x805C67F8: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x805C67FC: bne         $a1, $zero, L_805C6808
    if (ctx->r5 != 0) {
        // 0x805C6800: nop
    
            goto L_805C6808;
    }
    // 0x805C6800: nop

    // 0x805C6804: break       7
    do_break(2153539588);
L_805C6808:
    // 0x805C6808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805C680C: bne         $a1, $at, L_805C6820
    if (ctx->r5 != ctx->r1) {
        // 0x805C6810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805C6820;
    }
    // 0x805C6810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805C6814: bne         $t8, $at, L_805C6820
    if (ctx->r24 != ctx->r1) {
        // 0x805C6818: nop
    
            goto L_805C6820;
    }
    // 0x805C6818: nop

    // 0x805C681C: break       6
    do_break(2153539612);
L_805C6820:
    // 0x805C6820: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x805C6824: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x805C6828: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x805C682C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x805C6830: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x805C6834: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6838: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x805C683C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x805C6840: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x805C6844: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805C6848: sw          $s7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r23;
    // 0x805C684C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6850: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x805C6854: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x805C6858: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x805C685C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x805C6860: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x805C6864: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6868: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x805C686C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x805C6870: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x805C6874: sw          $s1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r17;
    // 0x805C6878: sw          $fp, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r30;
    // 0x805C687C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x805C6880: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(447, 0X3AF8) << 16);
    // 0x805C6884: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x805C6888: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x805C688C: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x805C6890: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x805C6894: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x805C6898: addiu       $t6, $t6, -0x6018
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(447, 0X3AF8));
    // 0x805C689C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x805C68A0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x805C68A4: bne         $t0, $t6, L_805C674C
    if (ctx->r8 != ctx->r14) {
        // 0x805C68A8: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_805C674C;
    }
    // 0x805C68A8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x805C68AC: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x805C68B0: lw          $t7, 0xB8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB8);
    // 0x805C68B4: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x805C68B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x805C68BC: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x805C68C0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x805C68C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x805C68C8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x805C68CC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x805C68D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x805C68D4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x805C68D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x805C68DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C68E0: jr          $ra
    // 0x805C68E4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x805C68E4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8001CD9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD9C: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001CDA0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8001CDA4: bne         $t7, $zero, L_8001CE1C
    if (ctx->r15 != 0) {
        // 0x8001CDA8: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8001CE1C;
    }
    // 0x8001CDA8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8001CDAC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001CDB0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8001CDB4: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8001CDB8: lbu         $a2, 0x31($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X31);
    // 0x8001CDBC: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x8001CDC0: addiu       $a1, $v0, 0x28
    ctx->r5 = ADD32(ctx->r2, 0X28);
    // 0x8001CDC4: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x8001CDC8: lbu         $a3, -0x6954($a3)
    ctx->r7 = MEM_BU(ctx->r7, -0X6954);
    // 0x8001CDCC: xori        $t9, $a2, 0x1
    ctx->r25 = ctx->r6 ^ 0X1;
    // 0x8001CDD0: sb          $t9, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r25;
    // 0x8001CDD4: beq         $v1, $zero, L_8001CE1C
    if (ctx->r3 == 0) {
        // 0x8001CDD8: sw          $t0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r8;
            goto L_8001CE1C;
    }
    // 0x8001CDD8: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x8001CDDC: andi        $a0, $v1, 0x3
    ctx->r4 = ctx->r3 & 0X3;
    // 0x8001CDE0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8001CDE4: beq         $a0, $zero, L_8001CE00
    if (ctx->r4 == 0) {
        // 0x8001CDE8: addu        $v0, $a0, $v1
        ctx->r2 = ADD32(ctx->r4, ctx->r3);
            goto L_8001CE00;
    }
    // 0x8001CDE8: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
L_8001CDEC:
    // 0x8001CDEC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001CDF0: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
    // 0x8001CDF4: bne         $v0, $v1, L_8001CDEC
    if (ctx->r2 != ctx->r3) {
        // 0x8001CDF8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8001CDEC;
    }
    // 0x8001CDF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8001CDFC: beq         $v1, $zero, L_8001CE1C
    if (ctx->r3 == 0) {
        // 0x8001CE00: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_8001CE1C;
    }
L_8001CE00:
    // 0x8001CE00: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8001CE04: sb          $a3, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r7;
    // 0x8001CE08: sb          $a3, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r7;
    // 0x8001CE0C: sb          $a3, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r7;
    // 0x8001CE10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8001CE14: bne         $v1, $zero, L_8001CE00
    if (ctx->r3 != 0) {
        // 0x8001CE18: sb          $a3, -0x4($a1)
        MEM_B(-0X4, ctx->r5) = ctx->r7;
            goto L_8001CE00;
    }
    // 0x8001CE18: sb          $a3, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r7;
L_8001CE1C:
    // 0x8001CE1C: jr          $ra
    // 0x8001CE20: nop

    return;
    // 0x8001CE20: nop

;}
RECOMP_FUNC void func_8078E858(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078E85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E860: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078E864: jal         0x80045A34
    // 0x8078E868: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078E868: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_0:
    // 0x8078E86C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078E870: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(808, 0XA40) << 16);
    // 0x8078E874: bne         $v0, $zero, L_8078E88C
    if (ctx->r2 != 0) {
        // 0x8078E878: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8078E88C;
    }
    // 0x8078E878: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8078E87C: jal         0x800445A4
    // 0x8078E880: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8078E880: nop

    after_1:
    // 0x8078E884: b           L_8078E90C
    // 0x8078E888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078E90C;
    // 0x8078E888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E88C:
    // 0x8078E88C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8078E890: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8078E894: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8078E898: addiu       $t6, $t6, -0x16A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(808, 0XA40));
    // 0x8078E89C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8078E8A0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8078E8A4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8078E8A8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8078E8AC: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8078E8B0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8078E8B4: jal         0x8078E344
    // 0x8078E8B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8078E344(rdram, ctx);
        goto after_2;
    // 0x8078E8B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8078E8BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078E8C0: lui         $t0, 0x8079
    ctx->r8 = S32(RELOC_HI16(808, 0X14C) << 16);
    // 0x8078E8C4: addiu       $t0, $t0, -0x1F94
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(808, 0X14C));
    // 0x8078E8C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078E8CC: sw          $t0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r8;
    // 0x8078E8D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078E8D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E8D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8078E8DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8078E8E0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8078E8E4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8078E8E8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8078E8EC: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8078E8F0: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8078E8F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078E8F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078E8FC: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x8078E900: jal         0x8078E918
    // 0x8078E904: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    func_8078E918(rdram, ctx);
        goto after_3;
    // 0x8078E904: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    after_3:
    // 0x8078E908: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E90C:
    // 0x8078E90C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078E910: jr          $ra
    // 0x8078E914: nop

    return;
    // 0x8078E914: nop

;}
RECOMP_FUNC void func_80023144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80023148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002314C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80023150: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80023154: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80023158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002315C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80023160: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80023164: lw          $t8, -0x63C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X63C0);
    // 0x80023168: jal         0x8001D78C
    // 0x8002316C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_8001D78C(rdram, ctx);
        goto after_0;
    // 0x8002316C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80023170: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80023174: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80023178: jalr        $t9
    // 0x8002317C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002317C: nop

    after_1:
    // 0x80023180: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80023184: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80023188: beql        $t0, $zero, L_800231A0
    if (ctx->r8 == 0) {
        // 0x8002318C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800231A0;
    }
    goto skip_0;
    // 0x8002318C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80023190: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80023194: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80023198: swc1        $f6, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f6.u32l;
    // 0x8002319C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800231A0:
    // 0x800231A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800231A4: jr          $ra
    // 0x800231A8: nop

    return;
    // 0x800231A8: nop

;}
RECOMP_FUNC void func_8067BDC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BDC0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8067BDC4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067BDC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BDCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BDD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8067BDD4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8067BDD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067BDDC: nop

    // 0x8067BDE0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8067BDE4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8067BDE8: nop

    // 0x8067BDEC: bc1fl       L_8067BE0C
    if (!c1cs) {
        // 0x8067BDF0: swc1        $f0, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
            goto L_8067BE0C;
    }
    goto skip_0;
    // 0x8067BDF0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8067BDF4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8067BDF8:
    // 0x8067BDF8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8067BDFC: nop

    // 0x8067BE00: bc1tl       L_8067BDF8
    if (c1cs) {
        // 0x8067BE04: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8067BDF8;
    }
    goto skip_1;
    // 0x8067BE04: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8067BE08: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_8067BE0C:
    // 0x8067BE0C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8067BE10: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8067BE14: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8067BE18: jal         0x80065ABC
    // 0x8067BE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8067BE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067BE20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067BE24: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8067BE28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BE2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BE30: jr          $ra
    // 0x8067BE34: nop

    return;
    // 0x8067BE34: nop

;}
RECOMP_FUNC void func_807AF100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF100: lui         $v0, 0x807B
    ctx->r2 = S32(RELOC_HI16(865, 0XDC) << 16);
    // 0x807AF104: addiu       $v0, $v0, -0xE24
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(865, 0XDC));
    // 0x807AF108: jr          $ra
    // 0x807AF10C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807AF10C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80407A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80407A64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80407A68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80407A6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80407A70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80407A74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80407A78: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x80407A7C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x80407A80: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x80407A84: jal         0x80051194
    // 0x80407A88: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80407A88: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80407A8C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80407A90: jal         0x8040A260
    // 0x80407A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040A260(rdram, ctx);
        goto after_1;
    // 0x80407A94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80407A98: beq         $v0, $zero, L_80407B08
    if (ctx->r2 == 0) {
        // 0x80407A9C: nop
    
            goto L_80407B08;
    }
    // 0x80407A9C: nop

    // 0x80407AA0: jal         0x8040A2F4
    // 0x80407AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040A2F4(rdram, ctx);
        goto after_2;
    // 0x80407AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80407AA8: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80407AAC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80407AB0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80407AB4: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(11, 0X2C7C) << 16);
    // 0x80407AB8: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80407ABC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80407AC0: addiu       $t7, $t7, -0x59B4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(11, 0X2C7C));
    // 0x80407AC4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80407AC8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80407ACC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x80407AD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80407AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80407AD8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80407ADC: jal         0x8040A40C
    // 0x80407AE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040A40C(rdram, ctx);
        goto after_3;
    // 0x80407AE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80407AE4: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80407AE8: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(11, 0XD40) << 16);
    // 0x80407AEC: addiu       $t9, $t9, -0x78F0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(11, 0XD40));
    // 0x80407AF0: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80407AF4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
    // 0x80407AF8: jal         0x8005770C
    // 0x80407AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005770C(rdram, ctx);
        goto after_4;
    // 0x80407AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80407B00: b           L_80407B14
    // 0x80407B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80407B14;
    // 0x80407B04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80407B08:
    // 0x80407B08: jal         0x800445A4
    // 0x80407B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x80407B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80407B10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80407B14:
    // 0x80407B14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80407B18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80407B1C: jr          $ra
    // 0x80407B20: nop

    return;
    // 0x80407B20: nop

;}
RECOMP_FUNC void func_8051830C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051830C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80518310: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80518314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80518318: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8051831C: addiu       $t0, $zero, 0x100
    ctx->r8 = ADD32(0, 0X100);
    // 0x80518320: sub.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f12.fl;
L_80518324:
    // 0x80518324: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80518328: lh          $a3, 0x0($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X0);
    // 0x8051832C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518330: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x80518334: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x80518338: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8051833C: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80518340: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80518344: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80518348: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8051834C: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80518350: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80518354: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80518358: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8051835C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80518360: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518364: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x80518368: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8051836C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80518370: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518374: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518378: nop

    // 0x8051837C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80518380: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518384: nop

    // 0x80518388: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8051838C: beql        $t2, $zero, L_805183DC
    if (ctx->r10 == 0) {
        // 0x80518390: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_805183DC;
    }
    goto skip_0;
    // 0x80518390: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x80518394: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80518398: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8051839C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x805183A0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805183A4: nop

    // 0x805183A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x805183AC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805183B0: nop

    // 0x805183B4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805183B8: bne         $t2, $zero, L_805183D0
    if (ctx->r10 != 0) {
        // 0x805183BC: nop
    
            goto L_805183D0;
    }
    // 0x805183BC: nop

    // 0x805183C0: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x805183C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805183C8: b           L_805183E8
    // 0x805183CC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805183E8;
    // 0x805183CC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_805183D0:
    // 0x805183D0: b           L_805183E8
    // 0x805183D4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805183E8;
    // 0x805183D4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x805183D8: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_805183DC:
    // 0x805183DC: nop

    // 0x805183E0: bltz        $t2, L_805183D0
    if (SIGNED(ctx->r10) < 0) {
        // 0x805183E4: nop
    
            goto L_805183D0;
    }
    // 0x805183E4: nop

L_805183E8:
    // 0x805183E8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805183EC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805183F0: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x805183F4: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x805183F8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805183FC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80518400: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80518404: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518408: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x8051840C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80518410: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80518414: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x80518418: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8051841C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518420: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80518424: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80518428: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8051842C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518430: nop

    // 0x80518434: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80518438: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8051843C: nop

    // 0x80518440: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518444: beql        $t2, $zero, L_80518494
    if (ctx->r10 == 0) {
        // 0x80518448: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_80518494;
    }
    goto skip_1;
    // 0x80518448: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_1:
    // 0x8051844C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80518450: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518454: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80518458: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8051845C: nop

    // 0x80518460: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80518464: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518468: nop

    // 0x8051846C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518470: bne         $t2, $zero, L_80518488
    if (ctx->r10 != 0) {
        // 0x80518474: nop
    
            goto L_80518488;
    }
    // 0x80518474: nop

    // 0x80518478: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8051847C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518480: b           L_805184A0
    // 0x80518484: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805184A0;
    // 0x80518484: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518488:
    // 0x80518488: b           L_805184A0
    // 0x8051848C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805184A0;
    // 0x8051848C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518490: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_80518494:
    // 0x80518494: nop

    // 0x80518498: bltz        $t2, L_80518488
    if (SIGNED(ctx->r10) < 0) {
        // 0x8051849C: nop
    
            goto L_80518488;
    }
    // 0x8051849C: nop

L_805184A0:
    // 0x805184A0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805184A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x805184A8: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x805184AC: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805184B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805184B4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x805184B8: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x805184BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805184C0: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x805184C4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x805184C8: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x805184CC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x805184D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805184D4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x805184D8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805184DC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805184E0: nop

    // 0x805184E4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x805184E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805184EC: nop

    // 0x805184F0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805184F4: beql        $t2, $zero, L_80518544
    if (ctx->r10 == 0) {
        // 0x805184F8: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_80518544;
    }
    goto skip_2;
    // 0x805184F8: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_2:
    // 0x805184FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80518500: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518504: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80518508: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8051850C: nop

    // 0x80518510: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80518514: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518518: nop

    // 0x8051851C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518520: bne         $t2, $zero, L_80518538
    if (ctx->r10 != 0) {
        // 0x80518524: nop
    
            goto L_80518538;
    }
    // 0x80518524: nop

    // 0x80518528: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8051852C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518530: b           L_80518550
    // 0x80518534: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518550;
    // 0x80518534: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518538:
    // 0x80518538: b           L_80518550
    // 0x8051853C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518550;
    // 0x8051853C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518540: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_80518544:
    // 0x80518544: nop

    // 0x80518548: bltz        $t2, L_80518538
    if (SIGNED(ctx->r10) < 0) {
        // 0x8051854C: nop
    
            goto L_80518538;
    }
    // 0x8051854C: nop

L_80518550:
    // 0x80518550: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x80518554: or          $t4, $t3, $t5
    ctx->r12 = ctx->r11 | ctx->r13;
    // 0x80518558: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8051855C: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80518560: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x80518564: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518568: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x8051856C: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x80518570: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80518574: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80518578: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x8051857C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80518580: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80518584: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518588: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x8051858C: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80518590: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518594: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80518598: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8051859C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x805185A0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x805185A4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x805185A8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x805185AC: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x805185B0: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x805185B4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805185B8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805185BC: nop

    // 0x805185C0: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x805185C4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805185C8: nop

    // 0x805185CC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805185D0: beql        $t2, $zero, L_80518620
    if (ctx->r10 == 0) {
        // 0x805185D4: mfc1        $t2, $f16
        ctx->r10 = (int32_t)ctx->f16.u32l;
            goto L_80518620;
    }
    goto skip_3;
    // 0x805185D4: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x805185D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805185DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805185E0: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x805185E4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805185E8: nop

    // 0x805185EC: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x805185F0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805185F4: nop

    // 0x805185F8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805185FC: bne         $t2, $zero, L_80518614
    if (ctx->r10 != 0) {
        // 0x80518600: nop
    
            goto L_80518614;
    }
    // 0x80518600: nop

    // 0x80518604: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80518608: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8051860C: b           L_8051862C
    // 0x80518610: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_8051862C;
    // 0x80518610: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518614:
    // 0x80518614: b           L_8051862C
    // 0x80518618: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_8051862C;
    // 0x80518618: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8051861C: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
L_80518620:
    // 0x80518620: nop

    // 0x80518624: bltz        $t2, L_80518614
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518628: nop
    
            goto L_80518614;
    }
    // 0x80518628: nop

L_8051862C:
    // 0x8051862C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518630: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80518634: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x80518638: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x8051863C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518640: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80518644: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80518648: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8051864C: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x80518650: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80518654: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80518658: or          $t4, $t5, $t3
    ctx->r12 = ctx->r13 | ctx->r11;
    // 0x8051865C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80518660: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518664: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80518668: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8051866C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518670: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518674: nop

    // 0x80518678: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8051867C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518680: nop

    // 0x80518684: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518688: beql        $t2, $zero, L_805186D8
    if (ctx->r10 == 0) {
        // 0x8051868C: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_805186D8;
    }
    goto skip_4;
    // 0x8051868C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_4:
    // 0x80518690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80518694: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518698: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8051869C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805186A0: nop

    // 0x805186A4: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x805186A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805186AC: nop

    // 0x805186B0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805186B4: bne         $t2, $zero, L_805186CC
    if (ctx->r10 != 0) {
        // 0x805186B8: nop
    
            goto L_805186CC;
    }
    // 0x805186B8: nop

    // 0x805186BC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x805186C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805186C4: b           L_805186E4
    // 0x805186C8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805186E4;
    // 0x805186C8: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_805186CC:
    // 0x805186CC: b           L_805186E4
    // 0x805186D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805186E4;
    // 0x805186D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x805186D4: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_805186D8:
    // 0x805186D8: nop

    // 0x805186DC: bltz        $t2, L_805186CC
    if (SIGNED(ctx->r10) < 0) {
        // 0x805186E0: nop
    
            goto L_805186CC;
    }
    // 0x805186E0: nop

L_805186E4:
    // 0x805186E4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805186E8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x805186EC: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x805186F0: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x805186F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805186F8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x805186FC: sll         $t5, $t2, 6
    ctx->r13 = S32(ctx->r10 << 6);
    // 0x80518700: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518704: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x80518708: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8051870C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80518710: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518714: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80518718: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8051871C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518720: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518724: nop

    // 0x80518728: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8051872C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518730: nop

    // 0x80518734: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518738: beql        $t2, $zero, L_80518788
    if (ctx->r10 == 0) {
        // 0x8051873C: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_80518788;
    }
    goto skip_5;
    // 0x8051873C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x80518740: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80518744: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518748: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8051874C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518750: nop

    // 0x80518754: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80518758: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8051875C: nop

    // 0x80518760: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518764: bne         $t2, $zero, L_8051877C
    if (ctx->r10 != 0) {
        // 0x80518768: nop
    
            goto L_8051877C;
    }
    // 0x80518768: nop

    // 0x8051876C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80518770: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518774: b           L_80518794
    // 0x80518778: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518794;
    // 0x80518778: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_8051877C:
    // 0x8051877C: b           L_80518794
    // 0x80518780: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518794;
    // 0x80518780: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518784: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_80518788:
    // 0x80518788: nop

    // 0x8051878C: bltz        $t2, L_8051877C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518790: nop
    
            goto L_8051877C;
    }
    // 0x80518790: nop

L_80518794:
    // 0x80518794: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80518798: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8051879C: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x805187A0: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x805187A4: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x805187A8: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805187AC: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x805187B0: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x805187B4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x805187B8: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x805187BC: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x805187C0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805187C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x805187C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805187CC: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x805187D0: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x805187D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805187D8: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x805187DC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x805187E0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x805187E4: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x805187E8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x805187EC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x805187F0: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x805187F4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x805187F8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805187FC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518800: nop

    // 0x80518804: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80518808: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8051880C: nop

    // 0x80518810: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518814: beql        $t2, $zero, L_80518864
    if (ctx->r10 == 0) {
        // 0x80518818: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_80518864;
    }
    goto skip_6;
    // 0x80518818: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_6:
    // 0x8051881C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80518820: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518824: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80518828: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8051882C: nop

    // 0x80518830: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80518834: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518838: nop

    // 0x8051883C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518840: bne         $t2, $zero, L_80518858
    if (ctx->r10 != 0) {
        // 0x80518844: nop
    
            goto L_80518858;
    }
    // 0x80518844: nop

    // 0x80518848: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8051884C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518850: b           L_80518870
    // 0x80518854: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518870;
    // 0x80518854: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518858:
    // 0x80518858: b           L_80518870
    // 0x8051885C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518870;
    // 0x8051885C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518860: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_80518864:
    // 0x80518864: nop

    // 0x80518868: bltz        $t2, L_80518858
    if (SIGNED(ctx->r10) < 0) {
        // 0x8051886C: nop
    
            goto L_80518858;
    }
    // 0x8051886C: nop

L_80518870:
    // 0x80518870: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518874: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80518878: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x8051887C: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80518880: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80518884: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80518888: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x8051888C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518890: andi        $t4, $v1, 0x1
    ctx->r12 = ctx->r3 & 0X1;
    // 0x80518894: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80518898: mul.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8051889C: or          $t5, $t4, $t3
    ctx->r13 = ctx->r12 | ctx->r11;
    // 0x805188A0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x805188A4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x805188A8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805188AC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x805188B0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x805188B4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805188B8: nop

    // 0x805188BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x805188C0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805188C4: nop

    // 0x805188C8: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805188CC: beql        $t2, $zero, L_8051891C
    if (ctx->r10 == 0) {
        // 0x805188D0: mfc1        $t2, $f6
        ctx->r10 = (int32_t)ctx->f6.u32l;
            goto L_8051891C;
    }
    goto skip_7;
    // 0x805188D0: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    skip_7:
    // 0x805188D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805188D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805188DC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805188E0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x805188E4: nop

    // 0x805188E8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x805188EC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805188F0: nop

    // 0x805188F4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805188F8: bne         $t2, $zero, L_80518910
    if (ctx->r10 != 0) {
        // 0x805188FC: nop
    
            goto L_80518910;
    }
    // 0x805188FC: nop

    // 0x80518900: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80518904: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518908: b           L_80518928
    // 0x8051890C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518928;
    // 0x8051890C: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518910:
    // 0x80518910: b           L_80518928
    // 0x80518914: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518928;
    // 0x80518914: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518918: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
L_8051891C:
    // 0x8051891C: nop

    // 0x80518920: bltz        $t2, L_80518910
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518924: nop
    
            goto L_80518910;
    }
    // 0x80518924: nop

L_80518928:
    // 0x80518928: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8051892C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80518930: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x80518934: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80518938: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8051893C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80518940: sll         $t4, $t2, 6
    ctx->r12 = S32(ctx->r10 << 6);
    // 0x80518944: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518948: or          $t3, $t5, $t4
    ctx->r11 = ctx->r13 | ctx->r12;
    // 0x8051894C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518950: mul.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80518954: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518958: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8051895C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80518960: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518964: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518968: nop

    // 0x8051896C: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80518970: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518974: nop

    // 0x80518978: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x8051897C: beql        $t2, $zero, L_805189CC
    if (ctx->r10 == 0) {
        // 0x80518980: mfc1        $t2, $f16
        ctx->r10 = (int32_t)ctx->f16.u32l;
            goto L_805189CC;
    }
    goto skip_8;
    // 0x80518980: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    skip_8:
    // 0x80518984: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80518988: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8051898C: sub.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80518990: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518994: nop

    // 0x80518998: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8051899C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x805189A0: nop

    // 0x805189A4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x805189A8: bne         $t2, $zero, L_805189C0
    if (ctx->r10 != 0) {
        // 0x805189AC: nop
    
            goto L_805189C0;
    }
    // 0x805189AC: nop

    // 0x805189B0: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x805189B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805189B8: b           L_805189D8
    // 0x805189BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_805189D8;
    // 0x805189BC: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_805189C0:
    // 0x805189C0: b           L_805189D8
    // 0x805189C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_805189D8;
    // 0x805189C4: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x805189C8: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
L_805189CC:
    // 0x805189CC: nop

    // 0x805189D0: bltz        $t2, L_805189C0
    if (SIGNED(ctx->r10) < 0) {
        // 0x805189D4: nop
    
            goto L_805189C0;
    }
    // 0x805189D4: nop

L_805189D8:
    // 0x805189D8: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x805189DC: or          $t4, $t3, $t5
    ctx->r12 = ctx->r11 | ctx->r13;
    // 0x805189E0: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x805189E4: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x805189E8: lh          $a3, 0x2($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X2);
    // 0x805189EC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x805189F0: andi        $t6, $v1, 0xF800
    ctx->r14 = ctx->r3 & 0XF800;
    // 0x805189F4: sra         $t7, $t6, 11
    ctx->r15 = S32(SIGNED(ctx->r14) >> 11);
    // 0x805189F8: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x805189FC: andi        $t8, $a3, 0xF800
    ctx->r24 = ctx->r7 & 0XF800;
    // 0x80518A00: sra         $t9, $t8, 11
    ctx->r25 = S32(SIGNED(ctx->r24) >> 11);
    // 0x80518A04: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80518A08: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80518A0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518A10: andi        $t6, $v1, 0x7C0
    ctx->r14 = ctx->r3 & 0X7C0;
    // 0x80518A14: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80518A18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80518A1C: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80518A20: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80518A24: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80518A28: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80518A2C: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80518A30: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80518A34: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80518A38: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518A3C: andi        $t6, $v1, 0x3E
    ctx->r14 = ctx->r3 & 0X3E;
    // 0x80518A40: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80518A44: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518A48: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518A4C: nop

    // 0x80518A50: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80518A54: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518A58: nop

    // 0x80518A5C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518A60: beql        $t2, $zero, L_80518AB0
    if (ctx->r10 == 0) {
        // 0x80518A64: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_80518AB0;
    }
    goto skip_9;
    // 0x80518A64: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_9:
    // 0x80518A68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80518A6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518A70: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80518A74: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518A78: nop

    // 0x80518A7C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80518A80: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518A84: nop

    // 0x80518A88: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518A8C: bne         $t2, $zero, L_80518AA4
    if (ctx->r10 != 0) {
        // 0x80518A90: nop
    
            goto L_80518AA4;
    }
    // 0x80518A90: nop

    // 0x80518A94: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80518A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518A9C: b           L_80518ABC
    // 0x80518AA0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518ABC;
    // 0x80518AA0: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518AA4:
    // 0x80518AA4: b           L_80518ABC
    // 0x80518AA8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518ABC;
    // 0x80518AA8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518AAC: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_80518AB0:
    // 0x80518AB0: nop

    // 0x80518AB4: bltz        $t2, L_80518AA4
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518AB8: nop
    
            goto L_80518AA4;
    }
    // 0x80518AB8: nop

L_80518ABC:
    // 0x80518ABC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518AC0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80518AC4: andi        $t8, $a3, 0x7C0
    ctx->r24 = ctx->r7 & 0X7C0;
    // 0x80518AC8: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80518ACC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80518AD0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80518AD4: sll         $t3, $t2, 11
    ctx->r11 = S32(ctx->r10 << 11);
    // 0x80518AD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518ADC: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x80518AE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80518AE4: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80518AE8: or          $t4, $t5, $t3
    ctx->r12 = ctx->r13 | ctx->r11;
    // 0x80518AEC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80518AF0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518AF4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80518AF8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80518AFC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518B00: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518B04: nop

    // 0x80518B08: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80518B0C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518B10: nop

    // 0x80518B14: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518B18: beql        $t2, $zero, L_80518B68
    if (ctx->r10 == 0) {
        // 0x80518B1C: mfc1        $t2, $f8
        ctx->r10 = (int32_t)ctx->f8.u32l;
            goto L_80518B68;
    }
    goto skip_10;
    // 0x80518B1C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    skip_10:
    // 0x80518B20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80518B24: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518B28: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80518B2C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518B30: nop

    // 0x80518B34: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80518B38: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518B3C: nop

    // 0x80518B40: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518B44: bne         $t2, $zero, L_80518B5C
    if (ctx->r10 != 0) {
        // 0x80518B48: nop
    
            goto L_80518B5C;
    }
    // 0x80518B48: nop

    // 0x80518B4C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80518B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518B54: b           L_80518B74
    // 0x80518B58: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518B74;
    // 0x80518B58: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518B5C:
    // 0x80518B5C: b           L_80518B74
    // 0x80518B60: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518B74;
    // 0x80518B60: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518B64: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
L_80518B68:
    // 0x80518B68: nop

    // 0x80518B6C: bltz        $t2, L_80518B5C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518B70: nop
    
            goto L_80518B5C;
    }
    // 0x80518B70: nop

L_80518B74:
    // 0x80518B74: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518B78: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80518B7C: andi        $t8, $a3, 0x3E
    ctx->r24 = ctx->r7 & 0X3E;
    // 0x80518B80: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80518B84: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80518B88: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80518B8C: sll         $t5, $t2, 6
    ctx->r13 = S32(ctx->r10 << 6);
    // 0x80518B90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518B94: or          $t3, $t4, $t5
    ctx->r11 = ctx->r12 | ctx->r13;
    // 0x80518B98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80518B9C: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80518BA0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80518BA4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80518BA8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80518BAC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80518BB0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518BB4: nop

    // 0x80518BB8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80518BBC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518BC0: nop

    // 0x80518BC4: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518BC8: beql        $t2, $zero, L_80518C18
    if (ctx->r10 == 0) {
        // 0x80518BCC: mfc1        $t2, $f18
        ctx->r10 = (int32_t)ctx->f18.u32l;
            goto L_80518C18;
    }
    goto skip_11;
    // 0x80518BCC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    skip_11:
    // 0x80518BD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80518BD4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80518BD8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80518BDC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80518BE0: nop

    // 0x80518BE4: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80518BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80518BEC: nop

    // 0x80518BF0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x80518BF4: bne         $t2, $zero, L_80518C0C
    if (ctx->r10 != 0) {
        // 0x80518BF8: nop
    
            goto L_80518C0C;
    }
    // 0x80518BF8: nop

    // 0x80518BFC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80518C00: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80518C04: b           L_80518C24
    // 0x80518C08: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_80518C24;
    // 0x80518C08: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_80518C0C:
    // 0x80518C0C: b           L_80518C24
    // 0x80518C10: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_80518C24;
    // 0x80518C10: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80518C14: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
L_80518C18:
    // 0x80518C18: nop

    // 0x80518C1C: bltz        $t2, L_80518C0C
    if (SIGNED(ctx->r10) < 0) {
        // 0x80518C20: nop
    
            goto L_80518C0C;
    }
    // 0x80518C20: nop

L_80518C24:
    // 0x80518C24: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x80518C28: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80518C2C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80518C30: sh          $t5, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r13;
    // 0x80518C34: bne         $v0, $t0, L_80518324
    if (ctx->r2 != ctx->r8) {
        // 0x80518C38: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80518324;
    }
    // 0x80518C38: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80518C3C: jr          $ra
    // 0x80518C40: nop

    return;
    // 0x80518C40: nop

;}
RECOMP_FUNC void func_80424238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424238: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042423C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424240: jal         0x804241A4
    // 0x80424244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804241A4(rdram, ctx);
        goto after_0;
    // 0x80424244: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80424248: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042424C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80424250: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80424254: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80424258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042425C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80424260: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80424264: lwc1        $f6, 0xEC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x80424268: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8042426C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80424270: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80424274: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80424278: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042427C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80424280: nop

    // 0x80424284: bc1fl       L_80424298
    if (!c1cs) {
        // 0x80424288: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80424298;
    }
    goto skip_0;
    // 0x80424288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042428C: jal         0x80424550
    // 0x80424290: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    func_80424550(rdram, ctx);
        goto after_1;
    // 0x80424290: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    after_1:
    // 0x80424294: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80424298:
    // 0x80424298: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042429C: jr          $ra
    // 0x804242A0: nop

    return;
    // 0x804242A0: nop

;}
RECOMP_FUNC void func_8044D078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044D078: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8044D07C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8044D080: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x8044D084: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8044D088: div         $zero, $t9, $t0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r8)));
    // 0x8044D08C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044D090: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8044D094: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8044D098: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x8044D09C: lw          $a2, 0x4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X4);
    // 0x8044D0A0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8044D0A4: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044D0A8: mflo        $a3
    ctx->r7 = lo;
    // 0x8044D0AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8044D0B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8044D0B4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8044D0B8: mfhi        $v1
    ctx->r3 = hi;
    // 0x8044D0BC: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x8044D0C0: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8044D0C4: bne         $t0, $zero, L_8044D0D0
    if (ctx->r8 != 0) {
        // 0x8044D0C8: nop
    
            goto L_8044D0D0;
    }
    // 0x8044D0C8: nop

    // 0x8044D0CC: break       7
    do_break(2151993548);
L_8044D0D0:
    // 0x8044D0D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8044D0D4: bne         $t0, $at, L_8044D0E8
    if (ctx->r8 != ctx->r1) {
        // 0x8044D0D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8044D0E8;
    }
    // 0x8044D0D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8044D0DC: bne         $t9, $at, L_8044D0E8
    if (ctx->r25 != ctx->r1) {
        // 0x8044D0E0: nop
    
            goto L_8044D0E8;
    }
    // 0x8044D0E0: nop

    // 0x8044D0E4: break       6
    do_break(2151993572);
L_8044D0E8:
    // 0x8044D0E8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8044D0EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8044D0F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8044D0F4: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8044D0F8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8044D0FC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8044D100: jal         0x8044CD4C
    // 0x8044D104: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8044CD4C(rdram, ctx);
        goto after_0;
    // 0x8044D104: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8044D108: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8044D10C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8044D110: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8044D114: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8044D118: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8044D11C: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8044D120: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8044D124: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x8044D128: jal         0x8044CED4
    // 0x8044D12C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_8044CED4(rdram, ctx);
        goto after_1;
    // 0x8044D12C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_1:
    // 0x8044D130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044D134: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8044D138: jr          $ra
    // 0x8044D13C: nop

    return;
    // 0x8044D13C: nop

;}
RECOMP_FUNC void func_805684E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805684E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805684E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805684EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805684F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805684F4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805684F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805684FC: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80568500: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21BC) << 16);
    // 0x80568504: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80568508: nop

    // 0x8056850C: bc1fl       L_80568538
    if (!c1cs) {
        // 0x80568510: swc1        $f14, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
            goto L_80568538;
    }
    goto skip_0;
    // 0x80568510: swc1        $f14, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
    skip_0:
    // 0x80568514: lwc1        $f4, -0x6894($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21BC));
    // 0x80568518: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8056851C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80568520: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80568524: jal         0x80569310
    // 0x80568528: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80569310(rdram, ctx);
        goto after_0;
    // 0x80568528: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8056852C: b           L_80568564
    // 0x80568530: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80568564;
    // 0x80568530: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80568534: swc1        $f14, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f14.u32l;
L_80568538:
    // 0x80568538: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8056853C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80568540: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21C0) << 16);
    // 0x80568544: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80568548: nop

    // 0x8056854C: bc1fl       L_80568568
    if (!c1cs) {
        // 0x80568550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80568568;
    }
    goto skip_1;
    // 0x80568550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80568554: lwc1        $f8, -0x6890($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21C0));
    // 0x80568558: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8056855C: add.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80568560: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_80568564:
    // 0x80568564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80568568:
    // 0x80568568: jal         0x80567DD4
    // 0x8056856C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80567DD4(rdram, ctx);
        goto after_1;
    // 0x8056856C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x80568570: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80568574: jal         0x80048F84
    // 0x80568578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x80568578: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8056857C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80568580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80568584: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x80568588: beq         $t6, $zero, L_80568598
    if (ctx->r14 == 0) {
        // 0x8056858C: nop
    
            goto L_80568598;
    }
    // 0x8056858C: nop

    // 0x80568590: jal         0x80569310
    // 0x80568594: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80569310(rdram, ctx);
        goto after_3;
    // 0x80568594: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_3:
L_80568598:
    // 0x80568598: jal         0x80567E60
    // 0x8056859C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80567E60(rdram, ctx);
        goto after_4;
    // 0x8056859C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805685A0: jal         0x805677F4
    // 0x805685A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805677F4(rdram, ctx);
        goto after_5;
    // 0x805685A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805685A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805685AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805685B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805685B4: jr          $ra
    // 0x805685B8: nop

    return;
    // 0x805685B8: nop

;}
RECOMP_FUNC void func_80445904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044590C: jal         0x80067D28
    // 0x80445910: nop

    func_80067D28(rdram, ctx);
        goto after_0;
    // 0x80445910: nop

    after_0:
    // 0x80445914: addiu       $a0, $zero, 0x229
    ctx->r4 = ADD32(0, 0X229);
    // 0x80445918: jal         0x80067818
    // 0x8044591C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8044591C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80445920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445928: jr          $ra
    // 0x8044592C: nop

    return;
    // 0x8044592C: nop

;}
RECOMP_FUNC void func_80007798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007798: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000779C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800077A0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800077A4: jr          $ra
    // 0x800077A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    return;
    // 0x800077A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
;}
RECOMP_FUNC void func_80673FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673FD0: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80673FD4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80673FD8: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x80673FDC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80673FE0: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80673FE4: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80673FE8: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x80673FEC: bnel        $at, $zero, L_80674028
    if (ctx->r1 != 0) {
        // 0x80673FF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80674028;
    }
    goto skip_0;
    // 0x80673FF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80673FF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80673FF8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80673FFC: beq         $v0, $zero, L_8067400C
    if (ctx->r2 == 0) {
        // 0x80674000: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8067400C;
    }
    // 0x80674000: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80674004: b           L_80674024
    // 0x80674008: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_80674024;
    // 0x80674008: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8067400C:
    // 0x8067400C: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x80674010: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80674014: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80674018: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8067401C: jr          $ra
    // 0x80674020: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x80674020: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80674024:
    // 0x80674024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80674028:
    // 0x80674028: jr          $ra
    // 0x8067402C: nop

    return;
    // 0x8067402C: nop

;}
RECOMP_FUNC void func_8045B594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B594: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045B598: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8045B59C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8045B5A0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8045B5A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045B5A8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8045B5AC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8045B5B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8045B5B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8045B5B8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8045B5BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045B5C0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8045B5C4: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(104, 0XCB8) << 16);
    // 0x8045B5C8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045B5CC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8045B5D0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8045B5D4: lw          $t2, -0x4938($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(104, 0XCB8));
    // 0x8045B5D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8045B5DC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8045B5E0: jal         0x8045B600
    // 0x8045B5E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8045B600(rdram, ctx);
        goto after_0;
    // 0x8045B5E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045B5E8: jal         0x8045B64C
    // 0x8045B5EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8045B64C(rdram, ctx);
        goto after_1;
    // 0x8045B5EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8045B5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045B5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045B5F8: jr          $ra
    // 0x8045B5FC: nop

    return;
    // 0x8045B5FC: nop

;}
RECOMP_FUNC void func_800679F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800679F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800679F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800679F8: jal         0x800186E0
    // 0x800679FC: nop

    func_800186E0(rdram, ctx);
        goto after_0;
    // 0x800679FC: nop

    after_0:
    // 0x80067A00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067A04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067A08: jr          $ra
    // 0x80067A0C: nop

    return;
    // 0x80067A0C: nop

;}
RECOMP_FUNC void func_806E3A3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3A3C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806E3A40: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806E3A44: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x806E3A48: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x806E3A4C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x806E3A50: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x806E3A54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x806E3A58: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x806E3A5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806E3A60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806E3A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E3A68: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E3A6C: lw          $s2, 0x174($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X174);
    // 0x806E3A70: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    // 0x806E3A74: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x806E3A78: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x806E3A7C: beq         $v0, $zero, L_806E3A8C
    if (ctx->r2 == 0) {
        // 0x806E3A80: lw          $s0, 0x2C($t6)
        ctx->r16 = MEM_W(ctx->r14, 0X2C);
            goto L_806E3A8C;
    }
    // 0x806E3A80: lw          $s0, 0x2C($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X2C);
    // 0x806E3A84: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806E3A88: sw          $t7, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r15;
L_806E3A8C:
    // 0x806E3A8C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x806E3A90: jal         0x80049D74
    // 0x806E3A94: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x806E3A94: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E3A98: sw          $zero, 0x8($s2)
    MEM_W(0X8, ctx->r18) = 0;
    // 0x806E3A9C: beq         $s0, $zero, L_806E3B48
    if (ctx->r16 == 0) {
        // 0x806E3AA0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_806E3B48;
    }
    // 0x806E3AA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E3AA4: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x806E3AA8: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x806E3AAC: lui         $s6, 0x806E
    ctx->r22 = S32(RELOC_HI16(649, 0X2174) << 16);
    // 0x806E3AB0: addiu       $s6, $s6, 0x5974
    ctx->r22 = ADD32(ctx->r22, (int16_t)RELOC_LO16(649, 0X2174));
    // 0x806E3AB4: sll         $s1, $s1, 3
    ctx->r17 = S32(ctx->r17 << 3);
    // 0x806E3AB8: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x806E3ABC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x806E3AC0: addiu       $s5, $zero, 0x40
    ctx->r21 = ADD32(0, 0X40);
    // 0x806E3AC4: addiu       $s4, $zero, 0x38
    ctx->r20 = ADD32(0, 0X38);
    // 0x806E3AC8: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x806E3ACC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_806E3AD0:
    // 0x806E3AD0: addiu       $s1, $s1, -0x18
    ctx->r17 = ADD32(ctx->r17, -0X18);
    // 0x806E3AD4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x806E3AD8: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806E3ADC: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x806E3AE0: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x806E3AE4: beq         $v1, $zero, L_806E3B40
    if (ctx->r3 == 0) {
        // 0x806E3AE8: nop
    
            goto L_806E3B40;
    }
    // 0x806E3AE8: nop

    // 0x806E3AEC: beq         $s3, $v1, L_806E3B40
    if (ctx->r19 == ctx->r3) {
        // 0x806E3AF0: nop
    
            goto L_806E3B40;
    }
    // 0x806E3AF0: nop

    // 0x806E3AF4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x806E3AF8: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x806E3AFC: beq         $s4, $v1, L_806E3B40
    if (ctx->r20 == ctx->r3) {
        // 0x806E3B00: nop
    
            goto L_806E3B40;
    }
    // 0x806E3B00: nop

    // 0x806E3B04: beq         $s5, $v1, L_806E3B40
    if (ctx->r21 == ctx->r3) {
        // 0x806E3B08: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_806E3B40;
    }
    // 0x806E3B08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806E3B0C: beq         $s0, $at, L_806E3B40
    if (ctx->r16 == ctx->r1) {
        // 0x806E3B10: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_806E3B40;
    }
    // 0x806E3B10: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x806E3B14: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x806E3B18: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x806E3B1C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x806E3B20: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806E3B24: jalr        $t9
    // 0x806E3B28: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x806E3B28: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_1:
    // 0x806E3B2C: beq         $s0, $s7, L_806E3B3C
    if (ctx->r16 == ctx->r23) {
        // 0x806E3B30: lw          $a2, 0x40($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X40);
            goto L_806E3B3C;
    }
    // 0x806E3B30: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x806E3B34: bne         $s0, $fp, L_806E3B40
    if (ctx->r16 != ctx->r30) {
        // 0x806E3B38: nop
    
            goto L_806E3B40;
    }
    // 0x806E3B38: nop

L_806E3B3C:
    // 0x806E3B3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_806E3B40:
    // 0x806E3B40: bnel        $s0, $zero, L_806E3AD0
    if (ctx->r16 != 0) {
        // 0x806E3B44: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_806E3AD0;
    }
    goto skip_0;
    // 0x806E3B44: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_806E3B48:
    // 0x806E3B48: bne         $a2, $zero, L_806E3BA4
    if (ctx->r6 != 0) {
        // 0x806E3B4C: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_806E3BA4;
    }
    // 0x806E3B4C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x806E3B50: lw          $t2, 0x60($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X60);
    // 0x806E3B54: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x806E3B58: bnel        $t2, $zero, L_806E3BA8
    if (ctx->r10 != 0) {
        // 0x806E3B5C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_806E3BA8;
    }
    goto skip_1;
    // 0x806E3B5C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x806E3B60: beq         $s0, $at, L_806E3BA4
    if (ctx->r16 == ctx->r1) {
        // 0x806E3B64: lw          $v0, 0x50($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X50);
            goto L_806E3BA4;
    }
    // 0x806E3B64: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x806E3B68: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806E3B6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806E3B70: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x806E3B74: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x806E3B78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E3B7C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806E3B80: nop

    // 0x806E3B84: bc1fl       L_806E3BA8
    if (!c1cs) {
        // 0x806E3B88: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_806E3BA8;
    }
    goto skip_2;
    // 0x806E3B88: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
    // 0x806E3B8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806E3B90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806E3B94: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806E3B98: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x806E3B9C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x806E3BA0: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
L_806E3BA4:
    // 0x806E3BA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_806E3BA8:
    // 0x806E3BA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E3BAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806E3BB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806E3BB4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806E3BB8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806E3BBC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x806E3BC0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x806E3BC4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x806E3BC8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x806E3BCC: jr          $ra
    // 0x806E3BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x806E3BD0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80526B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526BA0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526BA4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X614C) << 16);
    // 0x80526BA8: lwc1        $f6, -0x3FB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X614C));
    // 0x80526BAC: lwc1        $f2, 0x30($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80526BB0: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80526BB4: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6150) << 16);
    // 0x80526BB8: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80526BBC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80526BC0: nop

    // 0x80526BC4: bc1tl       L_80526C2C
    if (c1cs) {
        // 0x80526BC8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80526C2C;
    }
    goto skip_0;
    // 0x80526BC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80526BCC: lwc1        $f8, -0x3FB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6150));
    // 0x80526BD0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80526BD4: nop

    // 0x80526BD8: bc1tl       L_80526C2C
    if (c1cs) {
        // 0x80526BDC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80526C2C;
    }
    goto skip_1;
    // 0x80526BDC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80526BE0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80526BE4: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80526BE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80526BEC: addiu       $v0, $t6, -0x1
    ctx->r2 = ADD32(ctx->r14, -0X1);
    // 0x80526BF0: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80526BF4: bgez        $v0, L_80526C0C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80526BF8: swc1        $f10, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
            goto L_80526C0C;
    }
    // 0x80526BF8: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
    // 0x80526BFC: jal         0x80527424
    // 0x80526C00: nop

    func_80527424(rdram, ctx);
        goto after_0;
    // 0x80526C00: nop

    after_0:
    // 0x80526C04: b           L_80526C40
    // 0x80526C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526C40;
    // 0x80526C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526C0C:
    // 0x80526C0C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80526C10: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80526C14: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80526C18: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80526C1C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80526C20: b           L_80526C3C
    // 0x80526C24: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80526C3C;
    // 0x80526C24: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80526C28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80526C2C:
    // 0x80526C2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80526C30: nop

    // 0x80526C34: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80526C38: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80526C3C:
    // 0x80526C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526C40:
    // 0x80526C40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526C44: jr          $ra
    // 0x80526C48: nop

    return;
    // 0x80526C48: nop

;}
RECOMP_FUNC void func_8069DC34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069DC34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069DC38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069DC3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8069DC40: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8069DC44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8069DC48: jal         0x80047090
    // 0x8069DC4C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8069DC4C: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8069DC50: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8069DC54: beq         $v0, $at, L_8069DC98
    if (ctx->r2 == ctx->r1) {
        // 0x8069DC58: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8069DC98;
    }
    // 0x8069DC58: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8069DC5C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8069DC60: lhu         $t6, 0x26($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X26);
    // 0x8069DC64: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8069DC68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8069DC6C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8069DC70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8069DC74: jal         0x8004613C
    // 0x8069DC78: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8069DC78: or          $a0, $t7, $v1
    ctx->r4 = ctx->r15 | ctx->r3;
    after_1:
    // 0x8069DC7C: beq         $v0, $zero, L_8069DC98
    if (ctx->r2 == 0) {
        // 0x8069DC80: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8069DC98;
    }
    // 0x8069DC80: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8069DC84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8069DC88: jal         0x80047F9C
    // 0x8069DC8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8069DC8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8069DC90: b           L_8069DC9C
    // 0x8069DC94: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8069DC9C;
    // 0x8069DC94: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8069DC98:
    // 0x8069DC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8069DC9C:
    // 0x8069DC9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069DCA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069DCA4: jr          $ra
    // 0x8069DCA8: nop

    return;
    // 0x8069DCA8: nop

    // 0x8069DCAC: nop

;}
RECOMP_FUNC void func_80673620(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673620: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x80673624: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80673628: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x8067362C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80673630: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x80673634: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80673638: sltu        $at, $t7, $t9
    ctx->r1 = ctx->r15 < ctx->r25 ? 1 : 0;
    // 0x8067363C: bnel        $at, $zero, L_80673678
    if (ctx->r1 != 0) {
        // 0x80673640: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80673678;
    }
    goto skip_0;
    // 0x80673640: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80673644: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80673648: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8067364C: beq         $v0, $zero, L_8067365C
    if (ctx->r2 == 0) {
        // 0x80673650: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_8067365C;
    }
    // 0x80673650: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80673654: b           L_80673674
    // 0x80673658: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
        goto L_80673674;
    // 0x80673658: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8067365C:
    // 0x8067365C: lw          $t1, 0x10($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X10);
    // 0x80673660: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80673664: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80673668: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x8067366C: jr          $ra
    // 0x80673670: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    return;
    // 0x80673670: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80673674:
    // 0x80673674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673678:
    // 0x80673678: jr          $ra
    // 0x8067367C: nop

    return;
    // 0x8067367C: nop

;}
RECOMP_FUNC void coss(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008D3C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008D3C8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008D3CC: addiu       $a0, $a1, 0x4000
    ctx->r4 = ADD32(ctx->r5, 0X4000);
    // 0x8008D3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D3D4: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x8008D3D8: jal         0x800828F0
    // 0x8008D3DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    sins(rdram, ctx);
        goto after_0;
    // 0x8008D3DC: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x8008D3E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D3E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008D3E8: jr          $ra
    // 0x8008D3EC: nop

    return;
    // 0x8008D3EC: nop

;}
RECOMP_FUNC void func_807415B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807415B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807415BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807415C0: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x807415C4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807415C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807415CC: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x807415D0: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x807415D4: beql        $t7, $zero, L_80741634
    if (ctx->r15 == 0) {
        // 0x807415D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80741634;
    }
    goto skip_0;
    // 0x807415D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807415DC: jal         0x80740E70
    // 0x807415E0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80740E70(rdram, ctx);
        goto after_0;
    // 0x807415E0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807415E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807415E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807415EC: jal         0x80741E44
    // 0x807415F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80741E44(rdram, ctx);
        goto after_1;
    // 0x807415F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x807415F4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807415F8: lw          $a0, 0x34($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X34);
    // 0x807415FC: jal         0x80067BBC
    // 0x80741600: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80741600: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x80741604: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x80741608: jal         0x80067818
    // 0x8074160C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8074160C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80741610: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80741614: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80741618: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x8074161C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80741620: sb          $zero, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = 0;
    // 0x80741624: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80741628: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8074162C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x80741630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80741634:
    // 0x80741634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80741638: jr          $ra
    // 0x8074163C: nop

    return;
    // 0x8074163C: nop

;}
RECOMP_FUNC void func_80441690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80441690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80441694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80441698: jal         0x8004700C
    // 0x8044169C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044169C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804416A0: beql        $v0, $zero, L_804416C0
    if (ctx->r2 == 0) {
        // 0x804416A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804416C0;
    }
    goto skip_0;
    // 0x804416A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804416A8: lw          $t6, 0x138($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X138);
    // 0x804416AC: bnel        $t6, $zero, L_804416C0
    if (ctx->r14 != 0) {
        // 0x804416B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804416C0;
    }
    goto skip_1;
    // 0x804416B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804416B4: jal         0x8043F6CC
    // 0x804416B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043F6CC(rdram, ctx);
        goto after_1;
    // 0x804416B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804416BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804416C0:
    // 0x804416C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804416C4: jr          $ra
    // 0x804416C8: nop

    return;
    // 0x804416C8: nop

;}
RECOMP_FUNC void func_8042E220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042E224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E228: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042E22C: jal         0x8005FE48
    // 0x8042E230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8042E230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042E234: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8042E238: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8042E23C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042E240: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042E244: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042E248: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8042E24C: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8042E250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042E254: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8042E258: div.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8042E25C: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8042E260: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8042E264: mul.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8042E268: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x8042E26C: nop

    // 0x8042E270: bc1fl       L_8042E284
    if (!c1cs) {
        // 0x8042E274: div.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
            goto L_8042E284;
    }
    goto skip_0;
    // 0x8042E274: div.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    skip_0:
    // 0x8042E278: b           L_8042E288
    // 0x8042E27C: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
        goto L_8042E288;
    // 0x8042E27C: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    // 0x8042E280: div.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
L_8042E284:
    // 0x8042E284: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
L_8042E288:
    // 0x8042E288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E28C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042E290: jr          $ra
    // 0x8042E294: nop

    return;
    // 0x8042E294: nop

;}
RECOMP_FUNC void func_804BD11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD11C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD124: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BD128: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804BD12C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BD130: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X4090) << 16);
    // 0x804BD134: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BD138: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804BD13C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BD140: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BD144: lw          $t8, -0x640($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(191, 0X4090));
    // 0x804BD148: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BD14C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BD150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BD154: jal         0x80048490
    // 0x804BD158: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804BD158: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804BD15C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804BD160: jal         0x80048378
    // 0x804BD164: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804BD164: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804BD168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD16C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD170: jr          $ra
    // 0x804BD174: nop

    return;
    // 0x804BD174: nop

;}
RECOMP_FUNC void func_8000AC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AC64: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8000AC68: jr          $ra
    // 0x8000AC6C: sw          $zero, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = 0;
    return;
    // 0x8000AC6C: sw          $zero, -0x5AF8($at)
    MEM_W(-0X5AF8, ctx->r1) = 0;
;}
RECOMP_FUNC void func_806F8DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8DF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F8DF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F8DF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F8DFC: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x806F8E00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F8E04: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x806F8E08: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x806F8E0C: jal         0x80045A34
    // 0x806F8E10: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F8E10: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x806F8E14: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806F8E18: bne         $v0, $zero, L_806F8E30
    if (ctx->r2 != 0) {
        // 0x806F8E1C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_806F8E30;
    }
    // 0x806F8E1C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x806F8E20: jal         0x800445A4
    // 0x806F8E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F8E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F8E28: b           L_806F8E6C
    // 0x806F8E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F8E6C;
    // 0x806F8E2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F8E30:
    // 0x806F8E30: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806F8E34: addiu       $a1, $zero, 0x26C
    ctx->r5 = ADD32(0, 0X26C);
    // 0x806F8E38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F8E3C: jal         0x80065728
    // 0x806F8E40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x806F8E40: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x806F8E44: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x806F8E48: jal         0x8005D730
    // 0x806F8E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x806F8E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F8E50: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x806F8E54: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x806F8E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F8E5C: sw          $t8, 0x260($a3)
    MEM_W(0X260, ctx->r7) = ctx->r24;
    // 0x806F8E60: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x806F8E64: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x806F8E68: sh          $t0, 0x25C($a3)
    MEM_H(0X25C, ctx->r7) = ctx->r8;
L_806F8E6C:
    // 0x806F8E6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8E70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F8E74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F8E78: jr          $ra
    // 0x806F8E7C: nop

    return;
    // 0x806F8E7C: nop

;}
RECOMP_FUNC void func_806DB928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB928: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB92C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806DB930: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806DB934: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806DB938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB93C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806DB940: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806DB944: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806DB948: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806DB94C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x806DB950: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806DB954: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806DB958: lui         $t2, 0x806E
    ctx->r10 = S32(RELOC_HI16(634, 0X664) << 16);
    // 0x806DB95C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806DB960: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806DB964: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806DB968: lw          $t2, -0x44DC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(634, 0X664));
    // 0x806DB96C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806DB970: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806DB974: jal         0x806DB5EC
    // 0x806DB978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806DB5EC(rdram, ctx);
        goto after_0;
    // 0x806DB978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DB97C: jal         0x806DB648
    // 0x806DB980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806DB648(rdram, ctx);
        goto after_1;
    // 0x806DB980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806DB984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB988: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB98C: jr          $ra
    // 0x806DB990: nop

    return;
    // 0x806DB990: nop

;}
RECOMP_FUNC void func_80446B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446B8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446B90: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80446B94: jr          $ra
    // 0x80446B98: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    return;
    // 0x80446B98: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80031F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80031F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031F08: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x80031F0C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80031F10: bne         $v0, $zero, L_80031F28
    if (ctx->r2 != 0) {
        // 0x80031F14: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80031F28;
    }
    // 0x80031F14: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80031F18: jal         0x80030B7C
    // 0x80031F1C: addiu       $a1, $a1, -0x1710
    ctx->r5 = ADD32(ctx->r5, -0X1710);
    func_80030B7C(rdram, ctx);
        goto after_0;
    // 0x80031F1C: addiu       $a1, $a1, -0x1710
    ctx->r5 = ADD32(ctx->r5, -0X1710);
    after_0:
    // 0x80031F20: b           L_80031F30
    // 0x80031F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80031F30;
    // 0x80031F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031F28:
    // 0x80031F28: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x80031F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80031F30:
    // 0x80031F30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80031F34: jr          $ra
    // 0x80031F38: nop

    return;
    // 0x80031F38: nop

;}
RECOMP_FUNC void func_80715258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80715258: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8071525C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80715260: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80715264: jal         0x80714DD4
    // 0x80715268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80714DD4(rdram, ctx);
        goto after_0;
    // 0x80715268: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8071526C: jal         0x80714E64
    // 0x80715270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714E64(rdram, ctx);
        goto after_1;
    // 0x80715270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80715274: jal         0x80714D40
    // 0x80715278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714D40(rdram, ctx);
        goto after_2;
    // 0x80715278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8071527C: jal         0x80714B20
    // 0x80715280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80714B20(rdram, ctx);
        goto after_3;
    // 0x80715280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80715284: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80715288: bne         $v0, $at, L_807152A0
    if (ctx->r2 != ctx->r1) {
        // 0x8071528C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_807152A0;
    }
    // 0x8071528C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80715290: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80715294: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80715298: jal         0x80715C24
    // 0x8071529C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80715C24(rdram, ctx);
        goto after_4;
    // 0x8071529C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_807152A0:
    // 0x807152A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807152A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807152A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807152AC: jr          $ra
    // 0x807152B0: nop

    return;
    // 0x807152B0: nop

;}
RECOMP_FUNC void func_805A6BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A6BB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A6BBC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A6BC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A6BC4: jal         0x80062684
    // 0x805A6BC8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x805A6BC8: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x805A6BCC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805A6BD0: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x805A6BD4: bnel        $t6, $zero, L_805A6C30
    if (ctx->r14 != 0) {
        // 0x805A6BD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A6C30;
    }
    goto skip_0;
    // 0x805A6BD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A6BDC: jal         0x8004700C
    // 0x805A6BE0: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x805A6BE0: nop

    after_1:
    // 0x805A6BE4: beq         $v0, $zero, L_805A6C00
    if (ctx->r2 == 0) {
        // 0x805A6BE8: nop
    
            goto L_805A6C00;
    }
    // 0x805A6BE8: nop

    // 0x805A6BEC: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x805A6BF0: bne         $s0, $t7, L_805A6C00
    if (ctx->r16 != ctx->r15) {
        // 0x805A6BF4: nop
    
            goto L_805A6C00;
    }
    // 0x805A6BF4: nop

    // 0x805A6BF8: jal         0x80060FE0
    // 0x805A6BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_2;
    // 0x805A6BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_805A6C00:
    // 0x805A6C00: lui         $t0, 0x805A
    ctx->r8 = S32(RELOC_HI16(420, 0X260) << 16);
    // 0x805A6C04: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A6C08: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x805A6C0C: addiu       $t0, $t0, 0x6C40
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(420, 0X260));
    // 0x805A6C10: sb          $t8, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r24;
    // 0x805A6C14: sb          $t9, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r25;
    // 0x805A6C18: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x805A6C1C: jal         0x8005FE48
    // 0x805A6C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x805A6C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A6C24: jal         0x805A6A30
    // 0x805A6C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A6A30(rdram, ctx);
        goto after_4;
    // 0x805A6C28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A6C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A6C30:
    // 0x805A6C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A6C34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A6C38: jr          $ra
    // 0x805A6C3C: nop

    return;
    // 0x805A6C3C: nop

;}
RECOMP_FUNC void func_80736C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736C4C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80736C50: lui         $t6, 0x8073
    ctx->r14 = S32(RELOC_HI16(736, 0X1090) << 16);
    // 0x80736C54: addiu       $t6, $t6, 0x6AF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(736, 0X1090));
    // 0x80736C58: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80736C5C: lui         $t9, 0x8073
    ctx->r25 = S32(RELOC_HI16(736, 0X10C8) << 16);
    // 0x80736C60: addiu       $t9, $t9, 0x6B28
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(736, 0X10C8));
    // 0x80736C64: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x80736C68: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x80736C6C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80736C70: jr          $ra
    // 0x80736C74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x80736C74: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_806E5C38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E5C38: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E5C3C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E5C40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E5C44: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E5C48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E5C4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E5C50: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E5C54: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(652, 0X98) << 16);
    // 0x806E5C58: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E5C5C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E5C60: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E5C64: lw          $t1, 0x5C78($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(652, 0X98));
    // 0x806E5C68: jr          $ra
    // 0x806E5C6C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E5C6C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_800011CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011CC: jr          $ra
    // 0x800011D0: nop

    return;
    // 0x800011D0: nop

    // 0x800011D4: jr          $ra
    // 0x800011D8: nop

    return;
    // 0x800011D8: nop

    // 0x800011DC: jr          $ra
    // 0x800011E0: nop

    return;
    // 0x800011E0: nop

    // 0x800011E4: jr          $ra
    // 0x800011E8: nop

    return;
    // 0x800011E8: nop

;}
RECOMP_FUNC void func_806F1A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1A2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F1A30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1A34: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F1A38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F1A3C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x806F1A40: jal         0x80062684
    // 0x806F1A44: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x806F1A44: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806F1A48: jal         0x806F16CC
    // 0x806F1A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_806F16CC(rdram, ctx);
        goto after_1;
    // 0x806F1A4C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806F1A50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F1A54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F1A58: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1970) << 16);
    // 0x806F1A5C: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F1A60: addiu       $t8, $t8, 0x2EF0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(679, 0X1970));
    // 0x806F1A64: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x806F1A68: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x806F1A6C: beq         $at, $zero, L_806F1AA0
    if (ctx->r1 == 0) {
        // 0x806F1A70: sll         $t7, $v1, 3
        ctx->r15 = S32(ctx->r3 << 3);
            goto L_806F1AA0;
    }
    // 0x806F1A70: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x806F1A74: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x806F1A78: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x806F1A7C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806F1A80: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x806F1A84: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x806F1A88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806F1A8C: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
    // 0x806F1A90: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806F1A94: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    // 0x806F1A98: b           L_806F1AB8
    // 0x806F1A9C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
        goto L_806F1AB8;
    // 0x806F1A9C: swc1        $f16, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f16.u32l;
L_806F1AA0:
    // 0x806F1AA0: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x806F1AA4: sw          $t1, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r9;
    // 0x806F1AA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1AAC: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806F1AB0: jal         0x806F1F14
    // 0x806F1AB4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_2;
    // 0x806F1AB4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_2:
L_806F1AB8:
    // 0x806F1AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1ABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1AC0: jr          $ra
    // 0x806F1AC4: nop

    return;
    // 0x806F1AC4: nop

;}
RECOMP_FUNC void func_800735EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800735EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800735F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800735F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800735F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800735FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80073600: jal         0x80081FE0
    // 0x80073604: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    floorf_recomp(rdram, ctx);
        goto after_0;
    // 0x80073604: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_0:
    // 0x80073608: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8007360C: jal         0x80081FE0
    // 0x80073610: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    floorf_recomp(rdram, ctx);
        goto after_1;
    // 0x80073610: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x80073614: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80073618: jal         0x80081FE0
    // 0x8007361C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    floorf_recomp(rdram, ctx);
        goto after_2;
    // 0x8007361C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x80073620: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80073624: jal         0x80081FE0
    // 0x80073628: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    floorf_recomp(rdram, ctx);
        goto after_3;
    // 0x80073628: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x8007362C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80073630: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80073634: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80073638: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8007363C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80073640: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80073644: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80073648: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8007364C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80073650: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80073654: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80073658: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8007365C: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80073660: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80073664: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80073668: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8007366C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80073670: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80073674: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80073678: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8007367C: jal         0x80073694
    // 0x80073680: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    func_80073694(rdram, ctx);
        goto after_4;
    // 0x80073680: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_4:
    // 0x80073684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80073688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007368C: jr          $ra
    // 0x80073690: nop

    return;
    // 0x80073690: nop

;}
RECOMP_FUNC void func_80455CC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455CC0: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80455CC4: lbu         $v0, -0x7204($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7204);
    // 0x80455CC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80455CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455CD0: bne         $v0, $zero, L_80455CE8
    if (ctx->r2 != 0) {
        // 0x80455CD4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80455CE8;
    }
    // 0x80455CD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80455CD8: jal         0x804559F0
    // 0x80455CDC: nop

    func_804559F0(rdram, ctx);
        goto after_0;
    // 0x80455CDC: nop

    after_0:
    // 0x80455CE0: b           L_80455D7C
    // 0x80455CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455CE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80455CE8:
    // 0x80455CE8: bnel        $v0, $at, L_80455D04
    if (ctx->r2 != ctx->r1) {
        // 0x80455CEC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80455D04;
    }
    goto skip_0;
    // 0x80455CEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80455CF0: jal         0x80455A68
    // 0x80455CF4: nop

    func_80455A68(rdram, ctx);
        goto after_1;
    // 0x80455CF4: nop

    after_1:
    // 0x80455CF8: b           L_80455D7C
    // 0x80455CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455D00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80455D04:
    // 0x80455D04: bnel        $v0, $at, L_80455D20
    if (ctx->r2 != ctx->r1) {
        // 0x80455D08: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80455D20;
    }
    goto skip_1;
    // 0x80455D08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x80455D0C: jal         0x80455AE0
    // 0x80455D10: nop

    func_80455AE0(rdram, ctx);
        goto after_2;
    // 0x80455D10: nop

    after_2:
    // 0x80455D14: b           L_80455D7C
    // 0x80455D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455D1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80455D20:
    // 0x80455D20: bnel        $v0, $at, L_80455D3C
    if (ctx->r2 != ctx->r1) {
        // 0x80455D24: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80455D3C;
    }
    goto skip_2;
    // 0x80455D24: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_2:
    // 0x80455D28: jal         0x80455B58
    // 0x80455D2C: nop

    func_80455B58(rdram, ctx);
        goto after_3;
    // 0x80455D2C: nop

    after_3:
    // 0x80455D30: b           L_80455D7C
    // 0x80455D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455D34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455D38: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80455D3C:
    // 0x80455D3C: bnel        $v0, $at, L_80455D58
    if (ctx->r2 != ctx->r1) {
        // 0x80455D40: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80455D58;
    }
    goto skip_3;
    // 0x80455D40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_3:
    // 0x80455D44: jal         0x80455BD0
    // 0x80455D48: nop

    func_80455BD0(rdram, ctx);
        goto after_4;
    // 0x80455D48: nop

    after_4:
    // 0x80455D4C: b           L_80455D7C
    // 0x80455D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455D54: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_80455D58:
    // 0x80455D58: bne         $v0, $at, L_80455D70
    if (ctx->r2 != ctx->r1) {
        // 0x80455D5C: nop
    
            goto L_80455D70;
    }
    // 0x80455D5C: nop

    // 0x80455D60: jal         0x80455C48
    // 0x80455D64: nop

    func_80455C48(rdram, ctx);
        goto after_5;
    // 0x80455D64: nop

    after_5:
    // 0x80455D68: b           L_80455D7C
    // 0x80455D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80455D7C;
    // 0x80455D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80455D70:
    // 0x80455D70: jal         0x804559F0
    // 0x80455D74: nop

    func_804559F0(rdram, ctx);
        goto after_6;
    // 0x80455D74: nop

    after_6:
    // 0x80455D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80455D7C:
    // 0x80455D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80455D80: jr          $ra
    // 0x80455D84: nop

    return;
    // 0x80455D84: nop

;}
RECOMP_FUNC void func_805349A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805349A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805349A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805349AC: lwc1        $f6, 0xDC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x805349B0: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x805349B4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805349B8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805349BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805349C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805349C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x805349C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805349CC: bc1fl       L_805349E8
    if (!c1cs) {
        // 0x805349D0: lhu         $t6, 0xE($v1)
        ctx->r14 = MEM_HU(ctx->r3, 0XE);
            goto L_805349E8;
    }
    goto skip_0;
    // 0x805349D0: lhu         $t6, 0xE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XE);
    skip_0:
    // 0x805349D4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805349D8: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x805349DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805349E0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x805349E4: lhu         $t6, 0xE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XE);
L_805349E8:
    // 0x805349E8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805349EC: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x805349F0: beq         $t7, $zero, L_80534A04
    if (ctx->r15 == 0) {
        // 0x805349F4: nop
    
            goto L_80534A04;
    }
    // 0x805349F4: nop

    // 0x805349F8: jal         0x805350A0
    // 0x805349FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x805349FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80534A00: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80534A04:
    // 0x80534A04: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X108C) << 16);
    // 0x80534A08: lwc1        $f4, 0x569C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X108C));
    // 0x80534A0C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80534A10: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80534A14: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80534A18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534A1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80534A20: jr          $ra
    // 0x80534A24: nop

    return;
    // 0x80534A24: nop

;}
RECOMP_FUNC void func_80044C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044C60: jal         0x8004700C
    // 0x80044C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80044C64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80044C68: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80044C6C: lw          $t6, -0x77D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77D8);
    // 0x80044C70: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80044C74: bne         $t6, $zero, L_80044C88
    if (ctx->r14 != 0) {
        // 0x80044C78: nop
    
            goto L_80044C88;
    }
    // 0x80044C78: nop

    // 0x80044C7C: beq         $v0, $zero, L_80044C88
    if (ctx->r2 == 0) {
        // 0x80044C80: nop
    
            goto L_80044C88;
    }
    // 0x80044C80: nop

    // 0x80044C84: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
L_80044C88:
    // 0x80044C88: jal         0x8004393C
    // 0x80044C8C: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    func_8004393C(rdram, ctx);
        goto after_1;
    // 0x80044C8C: addiu       $a0, $v1, 0x4
    ctx->r4 = ADD32(ctx->r3, 0X4);
    after_1:
    // 0x80044C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044C98: jr          $ra
    // 0x80044C9C: nop

    return;
    // 0x80044C9C: nop

;}
RECOMP_FUNC void func_804607B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804607B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804607BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804607C0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804607C4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804607C8: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3684) << 16);
    // 0x804607CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804607D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804607D4: lw          $t8, 0x3C14($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3684));
    // 0x804607D8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804607DC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804607E0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804607E4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804607E8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804607EC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804607F0: beql        $v1, $zero, L_80460824
    if (ctx->r3 == 0) {
        // 0x804607F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80460824;
    }
    goto skip_0;
    // 0x804607F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804607F8: jalr        $v1
    // 0x804607FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804607FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80460800: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80460804: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80460808: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8046080C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80460810: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80460814: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80460818: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8046081C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80460820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80460824:
    // 0x80460824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460828: jr          $ra
    // 0x8046082C: nop

    return;
    // 0x8046082C: nop

;}
RECOMP_FUNC void func_80461EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461EF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80461EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461EF8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80461EFC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80461F00: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x80461F04: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80461F08: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x80461F0C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80461F10: nop

    // 0x80461F14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80461F18: jal         0x80461D10
    // 0x80461F1C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_80461D10(rdram, ctx);
        goto after_0;
    // 0x80461F1C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80461F20: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80461F24: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80461F28: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x80461F2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461F30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80461F34: jr          $ra
    // 0x80461F38: nop

    return;
    // 0x80461F38: nop

;}
RECOMP_FUNC void func_80793490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80793494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80793498: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079349C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807934A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807934A4: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x807934A8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807934AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x807934B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x807934B4: jal         0x80062AEC
    // 0x807934B8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x807934B8: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    after_0:
    // 0x807934BC: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x807934C0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x807934C4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807934C8: bne         $v1, $at, L_80793544
    if (ctx->r3 != ctx->r1) {
        // 0x807934CC: lw          $a0, 0x1F4($t7)
        ctx->r4 = MEM_W(ctx->r15, 0X1F4);
            goto L_80793544;
    }
    // 0x807934CC: lw          $a0, 0x1F4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X1F4);
    // 0x807934D0: lbu         $v1, 0x30($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X30);
    // 0x807934D4: slti        $at, $v1, 0x12
    ctx->r1 = SIGNED(ctx->r3) < 0X12 ? 1 : 0;
    // 0x807934D8: bne         $at, $zero, L_807934E8
    if (ctx->r1 != 0) {
        // 0x807934DC: slti        $at, $v1, 0x19
        ctx->r1 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
            goto L_807934E8;
    }
    // 0x807934DC: slti        $at, $v1, 0x19
    ctx->r1 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // 0x807934E0: bnel        $at, $zero, L_807935D0
    if (ctx->r1 != 0) {
        // 0x807934E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807935D0;
    }
    goto skip_0;
    // 0x807934E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_807934E8:
    // 0x807934E8: lw          $t8, 0x3C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X3C);
    // 0x807934EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807934F0: bgtzl       $t8, L_807935D0
    if (SIGNED(ctx->r24) > 0) {
        // 0x807934F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807935D0;
    }
    goto skip_1;
    // 0x807934F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807934F8: bne         $v0, $at, L_8079352C
    if (ctx->r2 != ctx->r1) {
        // 0x807934FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8079352C;
    }
    // 0x807934FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80793500: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80793504: lw          $a0, 0x34($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X34);
    // 0x80793508: jal         0x80067BBC
    // 0x8079350C: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8079350C: lw          $a1, 0x38($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X38);
    after_1:
    // 0x80793510: addiu       $a0, $zero, 0x22F
    ctx->r4 = ADD32(0, 0X22F);
    // 0x80793514: jal         0x80067818
    // 0x80793518: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80793518: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8079351C: jal         0x8002F92C
    // 0x80793520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002F92C(rdram, ctx);
        goto after_3;
    // 0x80793520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80793524: b           L_807935D0
    // 0x80793528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807935D0;
    // 0x80793528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079352C:
    // 0x8079352C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80793530: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80793534: jal         0x8002F6E4
    // 0x80793538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x80793538: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8079353C: b           L_807935D0
    // 0x80793540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807935D0;
    // 0x80793540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80793544:
    // 0x80793544: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x80793548: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8079354C: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x80793550: bnel        $a0, $v0, L_807935D0
    if (ctx->r4 != ctx->r2) {
        // 0x80793554: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807935D0;
    }
    goto skip_2;
    // 0x80793554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80793558: beq         $v1, $at, L_80793574
    if (ctx->r3 == ctx->r1) {
        // 0x8079355C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80793574;
    }
    // 0x8079355C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80793560: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80793564: beq         $v1, $at, L_80793584
    if (ctx->r3 == ctx->r1) {
        // 0x80793568: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80793584;
    }
    // 0x80793568: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8079356C: b           L_807935C4
    // 0x80793570: nop

        goto L_807935C4;
    // 0x80793570: nop

L_80793574:
    // 0x80793574: jal         0x807933FC
    // 0x80793578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_807933FC(rdram, ctx);
        goto after_5;
    // 0x80793578: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8079357C: b           L_807935D0
    // 0x80793580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807935D0;
    // 0x80793580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80793584:
    // 0x80793584: bnel        $a0, $v0, L_807935D0
    if (ctx->r4 != ctx->r2) {
        // 0x80793588: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807935D0;
    }
    goto skip_3;
    // 0x80793588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8079358C: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x80793590: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80793594: bnel        $t0, $zero, L_807935B4
    if (ctx->r8 != 0) {
        // 0x80793598: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_807935B4;
    }
    goto skip_4;
    // 0x80793598: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    skip_4:
    // 0x8079359C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x807935A0: sb          $t1, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r9;
    // 0x807935A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807935A8: jalr        $t9
    // 0x807935AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x807935AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x807935B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_807935B4:
    // 0x807935B4: jal         0x80793284
    // 0x807935B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80793284(rdram, ctx);
        goto after_7;
    // 0x807935B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x807935BC: b           L_807935D0
    // 0x807935C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807935D0;
    // 0x807935C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807935C4:
    // 0x807935C4: jal         0x80793284
    // 0x807935C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80793284(rdram, ctx);
        goto after_8;
    // 0x807935C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x807935CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807935D0:
    // 0x807935D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807935D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807935D8: jr          $ra
    // 0x807935DC: nop

    return;
    // 0x807935DC: nop

;}
