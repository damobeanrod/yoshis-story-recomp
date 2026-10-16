#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804311BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804311BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804311C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804311C4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804311C8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804311CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804311D0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804311D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804311D8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804311DC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804311E0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x804311E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804311E8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804311EC: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X3B2C) << 16);
    // 0x804311F0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804311F4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804311F8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804311FC: lw          $t2, 0x1C0C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X3B2C));
    // 0x80431200: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80431204: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80431208: jal         0x80430B14
    // 0x8043120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80430B14(rdram, ctx);
        goto after_0;
    // 0x8043120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80431210: jal         0x80430B70
    // 0x80431214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80430B70(rdram, ctx);
        goto after_1;
    // 0x80431214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80431218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043121C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80431220: jr          $ra
    // 0x80431224: nop

    return;
    // 0x80431224: nop

;}
RECOMP_FUNC void func_805346E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805346E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805346E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805346EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805346F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805346F4: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805346F8: jal         0x80067BBC
    // 0x805346FC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805346FC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x80534700: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80534704: jal         0x80067818
    // 0x80534708: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80534708: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8053470C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534710: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80534714: jr          $ra
    // 0x80534718: nop

    return;
    // 0x80534718: nop

;}
RECOMP_FUNC void func_8005AB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005AB3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005AB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005AB44: jal         0x80064DD0
    // 0x8005AB48: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80064DD0(rdram, ctx);
        goto after_0;
    // 0x8005AB48: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_0:
    // 0x8005AB4C: bne         $v0, $zero, L_8005AB6C
    if (ctx->r2 != 0) {
        // 0x8005AB50: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8005AB6C;
    }
    // 0x8005AB50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8005AB54: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005AB58: addiu       $a0, $a0, 0xC00
    ctx->r4 = ADD32(ctx->r4, 0XC00);
    // 0x8005AB5C: jal         0x80071380
    // 0x8005AB60: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x8005AB60: addiu       $a1, $zero, 0x34
    ctx->r5 = ADD32(0, 0X34);
    after_1:
    // 0x8005AB64: b           L_8005AB80
    // 0x8005AB68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005AB80;
    // 0x8005AB68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005AB6C:
    // 0x8005AB6C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8005AB70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005AB74: jal         0x80065728
    // 0x8005AB78: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8005AB78: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8005AB7C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8005AB80:
    // 0x8005AB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005AB84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005AB88: jr          $ra
    // 0x8005AB8C: nop

    return;
    // 0x8005AB8C: nop

;}
RECOMP_FUNC void func_804C2348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2348: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C234C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804C2350: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(203, 0X1150) << 16);
    // 0x804C2354: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x804C2358: lwc1        $f6, 0x28C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(203, 0X1150));
    // 0x804C235C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804C2360: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804C2364: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x804C2368: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C236C: sh          $zero, 0x10($v0)
    MEM_H(0X10, ctx->r2) = 0;
    // 0x804C2370: jr          $ra
    // 0x804C2374: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x804C2374: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_807B4850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4850: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807B4854: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B4858: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x807B485C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807B4860: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x807B4864: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x807B4868: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B486C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B4870: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B4874: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B4878: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B487C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x807B4880: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x807B4884: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B4888: beq         $s3, $zero, L_807B48D8
    if (ctx->r19 == 0) {
        // 0x807B488C: lw          $s4, 0x18($t6)
        ctx->r20 = MEM_W(ctx->r14, 0X18);
            goto L_807B48D8;
    }
    // 0x807B488C: lw          $s4, 0x18($t6)
    ctx->r20 = MEM_W(ctx->r14, 0X18);
    // 0x807B4890: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
L_807B4894:
    // 0x807B4894: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807B4898: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807B489C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x807B48A0: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x807B48A4: beq         $at, $zero, L_807B48D8
    if (ctx->r1 == 0) {
        // 0x807B48A8: addu        $t7, $a1, $s4
        ctx->r15 = ADD32(ctx->r5, ctx->r20);
            goto L_807B48D8;
    }
    // 0x807B48A8: addu        $t7, $a1, $s4
    ctx->r15 = ADD32(ctx->r5, ctx->r20);
    // 0x807B48AC: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x807B48B0: addu        $s0, $v0, $s1
    ctx->r16 = ADD32(ctx->r2, ctx->r17);
    // 0x807B48B4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x807B48B8: beql        $at, $zero, L_807B48DC
    if (ctx->r1 == 0) {
        // 0x807B48BC: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_807B48DC;
    }
    goto skip_0;
    // 0x807B48BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x807B48C0: jal         0x8005C27C
    // 0x807B48C4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B48C4: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_0:
    // 0x807B48C8: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x807B48CC: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807B48D0: bne         $at, $zero, L_807B4894
    if (ctx->r1 != 0) {
        // 0x807B48D4: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_807B4894;
    }
    // 0x807B48D4: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_807B48D8:
    // 0x807B48D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_807B48DC:
    // 0x807B48DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B48E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B48E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B48E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B48EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B48F0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x807B48F4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x807B48F8: jr          $ra
    // 0x807B48FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807B48FC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8078F304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F304: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8078F308: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8078F30C: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x8078F310: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8078F314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F318: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8078F31C: bne         $t6, $zero, L_8078F3E4
    if (ctx->r14 != 0) {
        // 0x8078F320: lw          $v0, 0xD8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XD8);
            goto L_8078F3E4;
    }
    // 0x8078F320: lw          $v0, 0xD8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XD8);
    // 0x8078F324: andi        $t7, $v0, 0x7
    ctx->r15 = ctx->r2 & 0X7;
    // 0x8078F328: bnel        $t7, $zero, L_8078F3E8
    if (ctx->r15 != 0) {
        // 0x8078F32C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F3E8;
    }
    goto skip_0;
    // 0x8078F32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8078F330: lw          $t8, 0xEA8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XEA8);
    // 0x8078F334: beql        $t8, $zero, L_8078F3E8
    if (ctx->r24 == 0) {
        // 0x8078F338: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078F3E8;
    }
    goto skip_1;
    // 0x8078F338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8078F33C: jal         0x800653D8
    // 0x8078F340: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8078F340: nop

    after_0:
    // 0x8078F344: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8078F348: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8078F34C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8078F350: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XD60) << 16);
    // 0x8078F354: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8078F358: lwc1        $f4, -0x110($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XD60));
    // 0x8078F35C: lwc1        $f6, 0x50($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X50);
    // 0x8078F360: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8078F364: jal         0x80066DE4
    // 0x8078F368: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8078F368: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8078F36C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8078F370: jal         0x80066E88
    // 0x8078F374: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8078F374: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8078F378: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8078F37C: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x8078F380: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8078F384: lw          $t2, 0x138($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X138);
    // 0x8078F388: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XD38) << 16);
    // 0x8078F38C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8078F390: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8078F394: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8078F398: lwc1        $f10, -0x138($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XD38));
    // 0x8078F39C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8078F3A0: mul.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8078F3A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078F3A8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8078F3AC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8078F3B0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8078F3B4: lw          $t9, -0x72B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72B8);
    // 0x8078F3B8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(814, 0XDBC) << 16);
    // 0x8078F3BC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8078F3C0: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8078F3C4: lwc1        $f4, -0xB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(814, 0XDBC));
    // 0x8078F3C8: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8078F3CC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8078F3D0: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8078F3D4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8078F3D8: add.s       $f18, $f2, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8078F3DC: jalr        $t9
    // 0x8078F3E0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8078F3E0: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
L_8078F3E4:
    // 0x8078F3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078F3E8:
    // 0x8078F3E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8078F3EC: jr          $ra
    // 0x8078F3F0: nop

    return;
    // 0x8078F3F0: nop

;}
RECOMP_FUNC void func_8046D3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D3E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D3EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8046D3F0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8046D3F4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8046D3F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D3FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8046D400: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046D404: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8046D408: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8046D40C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8046D410: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8046D414: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8046D418: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(143, 0X14B8) << 16);
    // 0x8046D41C: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x8046D420: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8046D424: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8046D428: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8046D42C: lw          $t1, -0x26F8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(143, 0X14B8));
    // 0x8046D430: lw          $a1, 0x138($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X138);
    // 0x8046D434: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8046D438: jal         0x8046D35C
    // 0x8046D43C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046D35C(rdram, ctx);
        goto after_0;
    // 0x8046D43C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046D440: jal         0x8046C7C4
    // 0x8046D444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8046C7C4(rdram, ctx);
        goto after_1;
    // 0x8046D444: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8046D448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D44C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D450: jr          $ra
    // 0x8046D454: nop

    return;
    // 0x8046D454: nop

    // 0x8046D458: nop

    // 0x8046D45C: nop

;}
RECOMP_FUNC void func_80792F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792F38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80792F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80792F40: jal         0x80790714
    // 0x80792F44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80792F44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80792F48: beq         $v0, $zero, L_80792F70
    if (ctx->r2 == 0) {
        // 0x80792F4C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80792F70;
    }
    // 0x80792F4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792F50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792F54: addiu       $a2, $zero, 0x1F
    ctx->r6 = ADD32(0, 0X1F);
    // 0x80792F58: jal         0x8079393C
    // 0x80792F5C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80792F5C: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x80792F60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80792F64: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80792F68: jal         0x8079145C
    // 0x80792F6C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    func_8079145C(rdram, ctx);
        goto after_2;
    // 0x80792F6C: lui         $a2, 0x4040
    ctx->r6 = S32(0X4040 << 16);
    after_2:
L_80792F70:
    // 0x80792F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80792F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80792F78: jr          $ra
    // 0x80792F7C: nop

    return;
    // 0x80792F7C: nop

;}
RECOMP_FUNC void func_8001BE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BE30: lui         $v0, 0x8002
    ctx->r2 = S32(0X8002 << 16);
    // 0x8001BE34: addiu       $v0, $v0, -0x3F4C
    ctx->r2 = ADD32(ctx->r2, -0X3F4C);
    // 0x8001BE38: jr          $ra
    // 0x8001BE3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8001BE3C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8044BB48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB48: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB4C: jr          $ra
    // 0x8044BB50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB50: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_805D83E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D83E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D83EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D83F0: jal         0x8004700C
    // 0x805D83F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D83F4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D83F8: beq         $v0, $zero, L_805D8490
    if (ctx->r2 == 0) {
        // 0x805D83FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805D8490;
    }
    // 0x805D83FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805D8400: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805D8404: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x805D8408: lh          $t7, 0x22($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X22);
    // 0x805D840C: beql        $t7, $zero, L_805D8494
    if (ctx->r15 == 0) {
        // 0x805D8410: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805D8494;
    }
    goto skip_0;
    // 0x805D8410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x805D8414: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805D8418: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x805D841C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x805D8420: jal         0x80065954
    // 0x805D8424: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x805D8424: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x805D8428: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805D842C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x805D8430: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x805D8434: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x805D8438: lwc1        $f8, 0x88($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X88);
    // 0x805D843C: jal         0x80065954
    // 0x805D8440: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x805D8440: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x805D8444: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x805D8448: lw          $t9, -0x7CE8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CE8);
    // 0x805D844C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x805D8450: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805D8454: lbu         $t0, 0xF0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XF0);
    // 0x805D8458: beql        $t0, $zero, L_805D8494
    if (ctx->r8 == 0) {
        // 0x805D845C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805D8494;
    }
    goto skip_1;
    // 0x805D845C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x805D8460: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D8464: nop

    // 0x805D8468: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x805D846C: nop

    // 0x805D8470: bc1fl       L_805D8494
    if (!c1cs) {
        // 0x805D8474: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805D8494;
    }
    goto skip_2;
    // 0x805D8474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x805D8478: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805D847C: nop

    // 0x805D8480: bc1fl       L_805D8494
    if (!c1cs) {
        // 0x805D8484: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805D8494;
    }
    goto skip_3;
    // 0x805D8484: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x805D8488: b           L_805D8494
    // 0x805D848C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805D8494;
    // 0x805D848C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805D8490:
    // 0x805D8490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D8494:
    // 0x805D8494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D8498: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D849C: jr          $ra
    // 0x805D84A0: nop

    return;
    // 0x805D84A0: nop

;}
RECOMP_FUNC void func_8073E7F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E7F0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8073E7F4: slti        $at, $v0, 0x4707
    ctx->r1 = SIGNED(ctx->r2) < 0X4707 ? 1 : 0;
    // 0x8073E7F8: bne         $at, $zero, L_8073E810
    if (ctx->r1 != 0) {
        // 0x8073E7FC: addiu       $at, $zero, 0x4707
        ctx->r1 = ADD32(0, 0X4707);
            goto L_8073E810;
    }
    // 0x8073E7FC: addiu       $at, $zero, 0x4707
    ctx->r1 = ADD32(0, 0X4707);
    // 0x8073E800: beq         $v0, $at, L_8073E850
    if (ctx->r2 == ctx->r1) {
        // 0x8073E804: nop
    
            goto L_8073E850;
    }
    // 0x8073E804: nop

    // 0x8073E808: b           L_8073E8A8
    // 0x8073E80C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073E8A8;
    // 0x8073E80C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073E810:
    // 0x8073E810: slti        $at, $v0, 0x4649
    ctx->r1 = SIGNED(ctx->r2) < 0X4649 ? 1 : 0;
    // 0x8073E814: bne         $at, $zero, L_8073E830
    if (ctx->r1 != 0) {
        // 0x8073E818: addiu       $t6, $v0, -0x4640
        ctx->r14 = ADD32(ctx->r2, -0X4640);
            goto L_8073E830;
    }
    // 0x8073E818: addiu       $t6, $v0, -0x4640
    ctx->r14 = ADD32(ctx->r2, -0X4640);
    // 0x8073E81C: addiu       $at, $zero, 0x4706
    ctx->r1 = ADD32(0, 0X4706);
    // 0x8073E820: beq         $v0, $at, L_8073E898
    if (ctx->r2 == ctx->r1) {
        // 0x8073E824: nop
    
            goto L_8073E898;
    }
    // 0x8073E824: nop

    // 0x8073E828: b           L_8073E8A8
    // 0x8073E82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8073E8A8;
    // 0x8073E82C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073E830:
    // 0x8073E830: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x8073E834: beq         $at, $zero, L_8073E8A4
    if (ctx->r1 == 0) {
        // 0x8073E838: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8073E8A4;
    }
    // 0x8073E838: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8073E83C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(748, 0X2420) << 16);
    // 0x8073E840: addu        $at, $at, $t6
    gpr jr_addend_8073E848 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8073E844: lw          $t6, 0xC10($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(748, 0X2420));
    // 0x8073E848: jr          $t6
    // 0x8073E84C: nop

    switch (jr_addend_8073E848 >> 2) {
        case 0: goto L_8073E850; break;
        case 1: goto L_8073E85C; break;
        case 2: goto L_8073E880; break;
        case 3: goto L_8073E874; break;
        case 4: goto L_8073E88C; break;
        case 5: goto L_8073E8A4; break;
        case 6: goto L_8073E8A4; break;
        case 7: goto L_8073E8A4; break;
        case 8: goto L_8073E868; break;
        default: switch_error(__func__, 0x8073E848, 0x80740C10);
    }
    // 0x8073E84C: nop

L_8073E850:
    // 0x8073E850: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X14AC) << 16);
    // 0x8073E854: jr          $ra
    // 0x8073E858: addiu       $v0, $v0, -0x364
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X14AC));
    return;
    // 0x8073E858: addiu       $v0, $v0, -0x364
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X14AC));
L_8073E85C:
    // 0x8073E85C: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X278) << 16);
    // 0x8073E860: jr          $ra
    // 0x8073E864: addiu       $v0, $v0, -0x1598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X278));
    return;
    // 0x8073E864: addiu       $v0, $v0, -0x1598
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X278));
L_8073E868:
    // 0x8073E868: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X2D8) << 16);
    // 0x8073E86C: jr          $ra
    // 0x8073E870: addiu       $v0, $v0, -0x1538
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X2D8));
    return;
    // 0x8073E870: addiu       $v0, $v0, -0x1538
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X2D8));
L_8073E874:
    // 0x8073E874: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X384) << 16);
    // 0x8073E878: jr          $ra
    // 0x8073E87C: addiu       $v0, $v0, -0x148C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X384));
    return;
    // 0x8073E87C: addiu       $v0, $v0, -0x148C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X384));
L_8073E880:
    // 0x8073E880: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X414) << 16);
    // 0x8073E884: jr          $ra
    // 0x8073E888: addiu       $v0, $v0, -0x13FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X414));
    return;
    // 0x8073E888: addiu       $v0, $v0, -0x13FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X414));
L_8073E88C:
    // 0x8073E88C: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X4A4) << 16);
    // 0x8073E890: jr          $ra
    // 0x8073E894: addiu       $v0, $v0, -0x136C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X4A4));
    return;
    // 0x8073E894: addiu       $v0, $v0, -0x136C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X4A4));
L_8073E898:
    // 0x8073E898: lui         $v0, 0x8074
    ctx->r2 = S32(RELOC_HI16(748, 0X5DC) << 16);
    // 0x8073E89C: jr          $ra
    // 0x8073E8A0: addiu       $v0, $v0, -0x1234
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X5DC));
    return;
    // 0x8073E8A0: addiu       $v0, $v0, -0x1234
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(748, 0X5DC));
L_8073E8A4:
    // 0x8073E8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8073E8A8:
    // 0x8073E8A8: jr          $ra
    // 0x8073E8AC: nop

    return;
    // 0x8073E8AC: nop

;}
RECOMP_FUNC void func_80673680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80673684: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673688: lbu         $t7, 0x158($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X158);
    // 0x8067368C: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80673690: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80673694: bne         $t7, $at, L_806736D0
    if (ctx->r15 != ctx->r1) {
        // 0x80673698: sw          $t6, 0x150($a0)
        MEM_W(0X150, ctx->r4) = ctx->r14;
            goto L_806736D0;
    }
    // 0x80673698: sw          $t6, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r14;
    // 0x8067369C: jal         0x806735BC
    // 0x806736A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_806735BC(rdram, ctx);
        goto after_0;
    // 0x806736A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806736A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806736A8: bne         $v0, $at, L_80673714
    if (ctx->r2 != ctx->r1) {
        // 0x806736AC: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80673714;
    }
    // 0x806736AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806736B0: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x806736B4: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x806736B8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x806736BC: sb          $t8, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r24;
    // 0x806736C0: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x806736C4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x806736C8: b           L_80673718
    // 0x806736CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80673718;
    // 0x806736CC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_806736D0:
    // 0x806736D0: addiu       $v1, $a0, 0x14C
    ctx->r3 = ADD32(ctx->r4, 0X14C);
    // 0x806736D4: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x806736D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806736DC: bnel        $t1, $at, L_80673718
    if (ctx->r9 != ctx->r1) {
        // 0x806736E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80673718;
    }
    goto skip_0;
    // 0x806736E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806736E4: jal         0x80673620
    // 0x806736E8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80673620(rdram, ctx);
        goto after_1;
    // 0x806736E8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x806736EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x806736F0: bne         $v0, $at, L_80673714
    if (ctx->r2 != ctx->r1) {
        // 0x806736F4: lw          $v1, 0x18($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X18);
            goto L_80673714;
    }
    // 0x806736F4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x806736F8: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x806736FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80673700: sb          $t2, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r10;
    // 0x80673704: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80673708: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8067370C: b           L_80673718
    // 0x80673710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80673718;
    // 0x80673710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80673714:
    // 0x80673714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673718:
    // 0x80673718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067371C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673720: jr          $ra
    // 0x80673724: nop

    return;
    // 0x80673724: nop

;}
RECOMP_FUNC void func_804C197C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C197C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1984: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C1988: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C198C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804C1990: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804C1994: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804C1998: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804C199C: bne         $v0, $at, L_804C19AC
    if (ctx->r2 != ctx->r1) {
        // 0x804C19A0: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_804C19AC;
    }
    // 0x804C19A0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C19A4: jal         0x8002F6E4
    // 0x804C19A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x804C19A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_804C19AC:
    // 0x804C19AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C19B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C19B4: jr          $ra
    // 0x804C19B8: nop

    return;
    // 0x804C19B8: nop

;}
RECOMP_FUNC void func_8003A854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A854: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003A858: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003A85C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003A860: jal         0x8003A620
    // 0x8003A864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8003A620(rdram, ctx);
        goto after_0;
    // 0x8003A864: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8003A868: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8003A86C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8003A870: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x8003A874: beql        $t7, $zero, L_8003A88C
    if (ctx->r15 == 0) {
        // 0x8003A878: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_8003A88C;
    }
    goto skip_0;
    // 0x8003A878: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8003A87C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A880: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8003A884: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x8003A888: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_8003A88C:
    // 0x8003A88C: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x8003A890: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8003A894: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8003A898: andi        $t1, $t0, 0xF8
    ctx->r9 = ctx->r8 & 0XF8;
    // 0x8003A89C: bne         $t1, $at, L_8003A8BC
    if (ctx->r9 != ctx->r1) {
        // 0x8003A8A0: nop
    
            goto L_8003A8BC;
    }
    // 0x8003A8A0: nop

    // 0x8003A8A4: jal         0x800447C8
    // 0x8003A8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003A8A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003A8AC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003A8B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A8B4: b           L_8003A8E0
    // 0x8003A8B8: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
        goto L_8003A8E0;
    // 0x8003A8B8: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
L_8003A8BC:
    // 0x8003A8BC: jal         0x8003A4EC
    // 0x8003A8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003A4EC(rdram, ctx);
        goto after_2;
    // 0x8003A8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003A8C4: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8003A8C8: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8003A8CC: jal         0x80065ABC
    // 0x8003A8D0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8003A8D0: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8003A8D4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8003A8D8: jal         0x80039DF0
    // 0x8003A8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80039DF0(rdram, ctx);
        goto after_4;
    // 0x8003A8DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8003A8E0:
    // 0x8003A8E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003A8E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003A8E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003A8EC: jr          $ra
    // 0x8003A8F0: nop

    return;
    // 0x8003A8F0: nop

;}
RECOMP_FUNC void func_804467B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804467B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804467B4: jr          $ra
    // 0x804467B8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    return;
    // 0x804467B8: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
;}
RECOMP_FUNC void func_8042FFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FFC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FFC8: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8042FFCC: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042FFD0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8042FFD4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8042FFD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042FFDC: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8042FFE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8042FFE4: bc1tl       L_80430018
    if (c1cs) {
        // 0x8042FFE8: lw          $a3, 0x138($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X138);
            goto L_80430018;
    }
    goto skip_0;
    // 0x8042FFE8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x8042FFEC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8042FFF0: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8042FFF4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042FFF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042FFFC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80430000: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80430004: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80430008: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8043000C: b           L_80430040
    // 0x80430010: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
        goto L_80430040;
    // 0x80430010: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x80430014: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
L_80430018:
    // 0x80430018: jal         0x804303F0
    // 0x8043001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804303F0(rdram, ctx);
        goto after_0;
    // 0x8043001C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430020: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80430024: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X18C8) << 16);
    // 0x80430028: addiu       $t6, $t6, -0x658
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X18C8));
    // 0x8043002C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3BC4) << 16);
    // 0x80430030: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80430034: lwc1        $f10, 0x1CA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3BC4));
    // 0x80430038: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043003C: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
L_80430040:
    // 0x80430040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430048: jr          $ra
    // 0x8043004C: nop

    return;
    // 0x8043004C: nop

;}
RECOMP_FUNC void func_80041760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041760: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80041764: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80041768: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8004176C: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041770: mflo        $t8
    ctx->r24 = lo;
    // 0x80041774: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
    // 0x80041778: lh          $a1, 0x1210($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X1210);
    // 0x8004177C: lw          $v0, 0x11FC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X11FC);
    // 0x80041780: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80041784: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80041788: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004178C: bne         $a1, $zero, L_80041830
    if (ctx->r5 != 0) {
        // 0x80041790: nop
    
            goto L_80041830;
    }
    // 0x80041790: nop

    // 0x80041794: sw          $zero, 0x130($v0)
    MEM_W(0X130, ctx->r2) = 0;
    // 0x80041798: lhu         $t0, 0x8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X8);
    // 0x8004179C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800417A0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x800417A4: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800417A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800417AC: mflo        $t1
    ctx->r9 = lo;
    // 0x800417B0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800417B4: swc1        $f4, 0x1204($t2)
    MEM_W(0X1204, ctx->r10) = ctx->f4.u32l;
    // 0x800417B8: lhu         $t4, 0x8($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X8);
    // 0x800417BC: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x800417C0: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x800417C4: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800417C8: mflo        $t5
    ctx->r13 = lo;
    // 0x800417CC: addu        $t7, $t3, $t5
    ctx->r15 = ADD32(ctx->r11, ctx->r13);
    // 0x800417D0: swc1        $f6, 0x1208($t7)
    MEM_W(0X1208, ctx->r15) = ctx->f6.u32l;
    // 0x800417D4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800417D8: lwc1        $f8, 0x8C($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x800417DC: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x800417E0: lhu         $t0, 0x8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X8);
    // 0x800417E4: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x800417E8: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800417EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800417F0: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x800417F4: swc1        $f10, 0x120C($t1)
    MEM_W(0X120C, ctx->r9) = ctx->f10.u32l;
    // 0x800417F8: lhu         $t4, 0x8($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X8);
    // 0x800417FC: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x80041800: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041804: mflo        $t3
    ctx->r11 = lo;
    // 0x80041808: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8004180C: lbu         $t5, 0x1202($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1202);
    // 0x80041810: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x80041814: sb          $t7, 0x1202($v1)
    MEM_B(0X1202, ctx->r3) = ctx->r15;
    // 0x80041818: lhu         $t0, 0x8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X8);
    // 0x8004181C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80041820: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80041824: subu        $t8, $t8, $t0
    ctx->r24 = SUB32(ctx->r24, ctx->r8);
    // 0x80041828: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004182C: addu        $v1, $t6, $t8
    ctx->r3 = ADD32(ctx->r14, ctx->r24);
L_80041830:
    // 0x80041830: jr          $ra
    // 0x80041834: sh          $a1, 0x1210($v1)
    MEM_H(0X1210, ctx->r3) = ctx->r5;
    return;
    // 0x80041834: sh          $a1, 0x1210($v1)
    MEM_H(0X1210, ctx->r3) = ctx->r5;
;}
RECOMP_FUNC void func_805640E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805640E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805640E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805640E8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805640EC: lw          $t6, 0x510($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X510);
    // 0x805640F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805640F4: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805640F8: mflo        $t8
    ctx->r24 = lo;
    // 0x805640FC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80564100: jal         0x80066DE4
    // 0x80564104: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80564104: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80564108: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x8056410C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80564110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80564114: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80564118: lwc1        $f6, 0x518($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X518);
    // 0x8056411C: lwc1        $f18, 0x50C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X50C);
    // 0x80564120: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80564124: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80564128: lwc1        $f6, 0x514($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X514);
    // 0x8056412C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80564130: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80564134: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80564138: jr          $ra
    // 0x8056413C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    return;
    // 0x8056413C: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
;}
RECOMP_FUNC void func_80040964(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040964: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x80040968: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004096C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80040970: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80040974: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80040978: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004097C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040980: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80040984: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80040988: lw          $s0, 0x11FC($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X11FC);
    // 0x8004098C: jal         0x80040940
    // 0x80040990: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    func_80040940(rdram, ctx);
        goto after_0;
    // 0x80040990: andi        $a1, $a2, 0xFFFF
    ctx->r5 = ctx->r6 & 0XFFFF;
    after_0:
    // 0x80040994: jal         0x80067E78
    // 0x80040998: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067E78(rdram, ctx);
        goto after_1;
    // 0x80040998: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x8004099C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x800409A0: jal         0x80067818
    // 0x800409A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x800409A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x800409A8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800409AC: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x800409B0: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    // 0x800409B4: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x800409B8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x800409BC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x800409C0: lw          $t9, 0x18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X18);
    // 0x800409C4: jalr        $t9
    // 0x800409C8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800409C8: nop

    after_3:
    // 0x800409CC: jal         0x800447C8
    // 0x800409D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x800409D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800409D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800409D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800409DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800409E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800409E4: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x800409E8: jr          $ra
    // 0x800409EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800409EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806B1A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1A18: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x806B1A1C: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x806B1A20: addu        $t7, $a2, $v0
    ctx->r15 = ADD32(ctx->r6, ctx->r2);
    // 0x806B1A24: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806B1A28: bnel        $at, $zero, L_806B1A3C
    if (ctx->r1 != 0) {
        // 0x806B1A2C: lw          $t8, -0x4($t7)
        ctx->r24 = MEM_W(ctx->r15, -0X4);
            goto L_806B1A3C;
    }
    goto skip_0;
    // 0x806B1A2C: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    skip_0:
    // 0x806B1A30: jr          $ra
    // 0x806B1A34: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    return;
    // 0x806B1A34: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x806B1A38: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
L_806B1A3C:
    // 0x806B1A3C: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x806B1A40: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x806B1A44: bnel        $at, $zero, L_806B1A58
    if (ctx->r1 != 0) {
        // 0x806B1A48: slti        $at, $a3, 0x2
        ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
            goto L_806B1A58;
    }
    goto skip_1;
    // 0x806B1A48: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    skip_1:
    // 0x806B1A4C: jr          $ra
    // 0x806B1A50: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    return;
    // 0x806B1A50: lwc1        $f0, -0x4($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, -0X4);
    // 0x806B1A54: slti        $at, $a3, 0x2
    ctx->r1 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
L_806B1A58:
    // 0x806B1A58: bne         $at, $zero, L_806B1BB4
    if (ctx->r1 != 0) {
        // 0x806B1A5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806B1BB4;
    }
    // 0x806B1A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806B1A60: addiu       $v1, $a3, -0x1
    ctx->r3 = ADD32(ctx->r7, -0X1);
    // 0x806B1A64: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x806B1A68: beql        $v1, $zero, L_806B1AE0
    if (ctx->r3 == 0) {
        // 0x806B1A6C: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_806B1AE0;
    }
    goto skip_2;
    // 0x806B1A6C: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    skip_2:
    // 0x806B1A70: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x806B1A74: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x806B1A78: bnel        $a0, $t0, L_806B1A8C
    if (ctx->r4 != ctx->r8) {
        // 0x806B1A7C: lw          $v1, -0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, -0X4);
            goto L_806B1A8C;
    }
    goto skip_3;
    // 0x806B1A7C: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
    skip_3:
    // 0x806B1A80: jr          $ra
    // 0x806B1A84: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    return;
    // 0x806B1A84: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x806B1A88: lw          $v1, -0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X4);
L_806B1A8C:
    // 0x806B1A8C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x806B1A90: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806B1A94: beq         $at, $zero, L_806B1AD8
    if (ctx->r1 == 0) {
        // 0x806B1A98: slt         $at, $a0, $t0
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_806B1AD8;
    }
    // 0x806B1A98: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x806B1A9C: beq         $at, $zero, L_806B1AD8
    if (ctx->r1 == 0) {
        // 0x806B1AA0: subu        $t3, $a0, $v1
        ctx->r11 = SUB32(ctx->r4, ctx->r3);
            goto L_806B1AD8;
    }
    // 0x806B1AA0: subu        $t3, $a0, $v1
    ctx->r11 = SUB32(ctx->r4, ctx->r3);
    // 0x806B1AA4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x806B1AA8: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x806B1AAC: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x806B1AB0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B1AB4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806B1AB8: subu        $t4, $t0, $v1
    ctx->r12 = SUB32(ctx->r8, ctx->r3);
    // 0x806B1ABC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x806B1AC0: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x806B1AC4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806B1AC8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806B1ACC: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x806B1AD0: jr          $ra
    // 0x806B1AD4: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x806B1AD4: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_806B1AD8:
    // 0x806B1AD8: beq         $v0, $a3, L_806B1BB4
    if (ctx->r2 == ctx->r7) {
        // 0x806B1ADC: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_806B1BB4;
    }
    // 0x806B1ADC: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
L_806B1AE0:
    // 0x806B1AE0: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
L_806B1AE4:
    // 0x806B1AE4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x806B1AE8: bne         $a0, $a2, L_806B1AF8
    if (ctx->r4 != ctx->r6) {
        // 0x806B1AEC: addu        $t5, $a1, $t0
        ctx->r13 = ADD32(ctx->r5, ctx->r8);
            goto L_806B1AF8;
    }
    // 0x806B1AEC: addu        $t5, $a1, $t0
    ctx->r13 = ADD32(ctx->r5, ctx->r8);
    // 0x806B1AF0: jr          $ra
    // 0x806B1AF4: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    return;
    // 0x806B1AF4: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
L_806B1AF8:
    // 0x806B1AF8: lw          $v1, -0x4($t1)
    ctx->r3 = MEM_W(ctx->r9, -0X4);
    // 0x806B1AFC: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806B1B00: beq         $at, $zero, L_806B1B44
    if (ctx->r1 == 0) {
        // 0x806B1B04: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_806B1B44;
    }
    // 0x806B1B04: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x806B1B08: beq         $at, $zero, L_806B1B44
    if (ctx->r1 == 0) {
        // 0x806B1B0C: subu        $t6, $a0, $v1
        ctx->r14 = SUB32(ctx->r4, ctx->r3);
            goto L_806B1B44;
    }
    // 0x806B1B0C: subu        $t6, $a0, $v1
    ctx->r14 = SUB32(ctx->r4, ctx->r3);
    // 0x806B1B10: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x806B1B14: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x806B1B18: lwc1        $f2, -0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X4);
    // 0x806B1B1C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B1B20: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806B1B24: subu        $t7, $a2, $v1
    ctx->r15 = SUB32(ctx->r6, ctx->r3);
    // 0x806B1B28: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x806B1B2C: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x806B1B30: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806B1B34: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806B1B38: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806B1B3C: jr          $ra
    // 0x806B1B40: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
    return;
    // 0x806B1B40: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
L_806B1B44:
    // 0x806B1B44: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x806B1B48: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x806B1B4C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806B1B50: bne         $a0, $t2, L_806B1B64
    if (ctx->r4 != ctx->r10) {
        // 0x806B1B54: addiu       $v0, $v0, 0x2
        ctx->r2 = ADD32(ctx->r2, 0X2);
            goto L_806B1B64;
    }
    // 0x806B1B54: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x806B1B58: addu        $t8, $a1, $t0
    ctx->r24 = ADD32(ctx->r5, ctx->r8);
    // 0x806B1B5C: jr          $ra
    // 0x806B1B60: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    return;
    // 0x806B1B60: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
L_806B1B64:
    // 0x806B1B64: beq         $at, $zero, L_806B1BAC
    if (ctx->r1 == 0) {
        // 0x806B1B68: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_806B1BAC;
    }
    // 0x806B1B68: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x806B1B6C: slt         $at, $a0, $t2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x806B1B70: beq         $at, $zero, L_806B1BAC
    if (ctx->r1 == 0) {
        // 0x806B1B74: subu        $t9, $a0, $v1
        ctx->r25 = SUB32(ctx->r4, ctx->r3);
            goto L_806B1BAC;
    }
    // 0x806B1B74: subu        $t9, $a0, $v1
    ctx->r25 = SUB32(ctx->r4, ctx->r3);
    // 0x806B1B78: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x806B1B7C: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x806B1B80: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B1B84: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806B1B88: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x806B1B8C: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x806B1B90: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x806B1B94: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x806B1B98: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x806B1B9C: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x806B1BA0: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x806B1BA4: jr          $ra
    // 0x806B1BA8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
    return;
    // 0x806B1BA8: add.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f2.fl;
L_806B1BAC:
    // 0x806B1BAC: bne         $v0, $a3, L_806B1AE4
    if (ctx->r2 != ctx->r7) {
        // 0x806B1BB0: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_806B1AE4;
    }
    // 0x806B1BB0: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_806B1BB4:
    // 0x806B1BB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806B1BB8: nop

    // 0x806B1BBC: jr          $ra
    // 0x806B1BC0: nop

    return;
    // 0x806B1BC0: nop

;}
RECOMP_FUNC void func_8043B144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043B144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043B148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043B14C: jal         0x8043AC18
    // 0x8043B150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043AC18(rdram, ctx);
        goto after_0;
    // 0x8043B150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043B154: jal         0x8043B000
    // 0x8043B158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043B000(rdram, ctx);
        goto after_1;
    // 0x8043B158: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043B15C: jal         0x8043AF28
    // 0x8043B160: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043AF28(rdram, ctx);
        goto after_2;
    // 0x8043B160: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8043B164: jal         0x8043B064
    // 0x8043B168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8043B064(rdram, ctx);
        goto after_3;
    // 0x8043B168: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8043B16C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043B170: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043B174: jr          $ra
    // 0x8043B178: nop

    return;
    // 0x8043B178: nop

;}
RECOMP_FUNC void func_80024E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024E04: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80024E08: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x80024E0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80024E10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80024E14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80024E18: beq         $t6, $zero, L_80024EEC
    if (ctx->r14 == 0) {
        // 0x80024E1C: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_80024EEC;
    }
    // 0x80024E1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80024E20: jal         0x80066E88
    // 0x80024E24: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80024E24: lwc1        $f12, 0x120($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X120);
    after_0:
    // 0x80024E28: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80024E2C: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80024E30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024E34: nop

    // 0x80024E38: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80024E3C: jal         0x80065954
    // 0x80024E40: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80024E40: nop

    after_1:
    // 0x80024E44: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024E48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80024E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024E50: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80024E54: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80024E58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80024E5C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024E60: nop

    // 0x80024E64: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80024E68: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024E6C: nop

    // 0x80024E70: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024E74: beql        $v0, $zero, L_80024ED4
    if (ctx->r2 == 0) {
        // 0x80024E78: mfc1        $v0, $f18
        ctx->r2 = (int32_t)ctx->f18.u32l;
            goto L_80024ED4;
    }
    goto skip_0;
    // 0x80024E78: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80024E7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024E84: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80024E88: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024E8C: nop

    // 0x80024E90: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80024E94: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024E98: nop

    // 0x80024E9C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024EA0: bnel        $v0, $zero, L_80024EC4
    if (ctx->r2 != 0) {
        // 0x80024EA4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80024EC4;
    }
    goto skip_1;
    // 0x80024EA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_1:
    // 0x80024EA8: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80024EAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024EB0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80024EB4: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x80024EB8: b           L_80024FAC
    // 0x80024EBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80024FAC;
    // 0x80024EBC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80024EC0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80024EC4:
    // 0x80024EC4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80024EC8: b           L_80024FAC
    // 0x80024ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80024FAC;
    // 0x80024ECC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80024ED0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
L_80024ED4:
    // 0x80024ED4: nop

    // 0x80024ED8: bltzl       $v0, L_80024EC4
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024EDC: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80024EC4;
    }
    goto skip_2;
    // 0x80024EDC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    skip_2:
    // 0x80024EE0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80024EE4: b           L_80024FAC
    // 0x80024EE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80024FAC;
    // 0x80024EE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80024EEC:
    // 0x80024EEC: jal         0x80066E88
    // 0x80024EF0: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80024EF0: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_2:
    // 0x80024EF4: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80024EF8: lwc1        $f6, 0x100($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X100);
    // 0x80024EFC: lwc1        $f16, 0x10C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80024F00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024F04: nop

    // 0x80024F08: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80024F0C: jal         0x80065954
    // 0x80024F10: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80024F10: add.s       $f12, $f16, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f10.fl;
    after_3:
    // 0x80024F14: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80024F18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80024F1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024F20: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80024F24: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80024F28: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80024F2C: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024F30: nop

    // 0x80024F34: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80024F38: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024F3C: nop

    // 0x80024F40: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024F44: beql        $v0, $zero, L_80024F94
    if (ctx->r2 == 0) {
        // 0x80024F48: mfc1        $v0, $f6
        ctx->r2 = (int32_t)ctx->f6.u32l;
            goto L_80024F94;
    }
    goto skip_3;
    // 0x80024F48: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x80024F4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80024F50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80024F54: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80024F58: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024F5C: nop

    // 0x80024F60: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80024F64: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024F68: nop

    // 0x80024F6C: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80024F70: bne         $v0, $zero, L_80024F88
    if (ctx->r2 != 0) {
        // 0x80024F74: nop
    
            goto L_80024F88;
    }
    // 0x80024F74: nop

    // 0x80024F78: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80024F7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024F80: b           L_80024FA0
    // 0x80024F84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80024FA0;
    // 0x80024F84: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80024F88:
    // 0x80024F88: b           L_80024FA0
    // 0x80024F8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80024FA0;
    // 0x80024F8C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80024F90: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
L_80024F94:
    // 0x80024F94: nop

    // 0x80024F98: bltz        $v0, L_80024F88
    if (SIGNED(ctx->r2) < 0) {
        // 0x80024F9C: nop
    
            goto L_80024F88;
    }
    // 0x80024F9C: nop

L_80024FA0:
    // 0x80024FA0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80024FA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80024FA8: nop

L_80024FAC:
    // 0x80024FAC: sltiu       $at, $v0, 0x14
    ctx->r1 = ctx->r2 < 0X14 ? 1 : 0;
    // 0x80024FB0: beq         $at, $zero, L_80024FBC
    if (ctx->r1 == 0) {
        // 0x80024FB4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80024FBC;
    }
    // 0x80024FB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80024FB8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
L_80024FBC:
    // 0x80024FBC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80024FC0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80024FC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80024FC8: jal         0x80024D30
    // 0x80024FCC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    func_80024D30(rdram, ctx);
        goto after_4;
    // 0x80024FCC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_4:
    // 0x80024FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80024FD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80024FD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80024FDC: jr          $ra
    // 0x80024FE0: nop

    return;
    // 0x80024FE0: nop

;}
RECOMP_FUNC void func_80005F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005F80: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80005F84: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x80005F88: lw          $v1, 0x1B58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1B58);
    // 0x80005F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80005F90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80005F94: beql        $v1, $zero, L_80005FF8
    if (ctx->r3 == 0) {
        // 0x80005F98: lw          $t4, 0x1B54($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X1B54);
            goto L_80005FF8;
    }
    goto skip_0;
    // 0x80005F98: lw          $t4, 0x1B54($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X1B54);
    skip_0:
    // 0x80005F9C: lw          $t6, 0x1B50($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1B50);
L_80005FA0:
    // 0x80005FA0: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80005FA4: lbu         $a1, 0xE($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XE);
    // 0x80005FA8: beq         $a1, $zero, L_80005FDC
    if (ctx->r5 == 0) {
        // 0x80005FAC: addiu       $t7, $a1, -0x1
        ctx->r15 = ADD32(ctx->r5, -0X1);
            goto L_80005FDC;
    }
    // 0x80005FAC: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x80005FB0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80005FB4: bne         $t8, $zero, L_80005FDC
    if (ctx->r24 != 0) {
        // 0x80005FB8: sb          $t7, 0xE($v1)
        MEM_B(0XE, ctx->r3) = ctx->r15;
            goto L_80005FDC;
    }
    // 0x80005FB8: sb          $t7, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r15;
    // 0x80005FBC: lbu         $t9, 0x1D62($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1D62);
    // 0x80005FC0: sb          $t9, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r25;
    // 0x80005FC4: lbu         $t0, 0x1D62($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X1D62);
    // 0x80005FC8: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x80005FCC: sb          $v0, 0x1B60($t1)
    MEM_B(0X1B60, ctx->r9) = ctx->r2;
    // 0x80005FD0: lbu         $t2, 0x1D62($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1D62);
    // 0x80005FD4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80005FD8: sb          $t3, 0x1D62($a2)
    MEM_B(0X1D62, ctx->r6) = ctx->r11;
L_80005FDC:
    // 0x80005FDC: lw          $v1, 0x1B58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1B58);
    // 0x80005FE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80005FE4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80005FE8: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80005FEC: bnel        $at, $zero, L_80005FA0
    if (ctx->r1 != 0) {
        // 0x80005FF0: lw          $t6, 0x1B50($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X1B50);
            goto L_80005FA0;
    }
    goto skip_1;
    // 0x80005FF0: lw          $t6, 0x1B50($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1B50);
    skip_1:
    // 0x80005FF4: lw          $t4, 0x1B54($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X1B54);
L_80005FF8:
    // 0x80005FF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80005FFC: sll         $a0, $v1, 4
    ctx->r4 = S32(ctx->r3 << 4);
    // 0x80006000: sltu        $at, $v1, $t4
    ctx->r1 = ctx->r3 < ctx->r12 ? 1 : 0;
    // 0x80006004: beq         $at, $zero, L_80006064
    if (ctx->r1 == 0) {
        // 0x80006008: nop
    
            goto L_80006064;
    }
    // 0x80006008: nop

    // 0x8000600C: lw          $t5, 0x1B50($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1B50);
L_80006010:
    // 0x80006010: addu        $v1, $a0, $t5
    ctx->r3 = ADD32(ctx->r4, ctx->r13);
    // 0x80006014: lbu         $a1, 0xE($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0XE);
    // 0x80006018: beq         $a1, $zero, L_8000604C
    if (ctx->r5 == 0) {
        // 0x8000601C: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8000604C;
    }
    // 0x8000601C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80006020: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80006024: bne         $t7, $zero, L_8000604C
    if (ctx->r15 != 0) {
        // 0x80006028: sb          $t6, 0xE($v1)
        MEM_B(0XE, ctx->r3) = ctx->r14;
            goto L_8000604C;
    }
    // 0x80006028: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x8000602C: lbu         $t8, 0x1D63($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1D63);
    // 0x80006030: sb          $t8, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r24;
    // 0x80006034: lbu         $t9, 0x1D63($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1D63);
    // 0x80006038: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x8000603C: sb          $v0, 0x1C60($t0)
    MEM_B(0X1C60, ctx->r8) = ctx->r2;
    // 0x80006040: lbu         $t1, 0x1D63($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X1D63);
    // 0x80006044: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80006048: sb          $t2, 0x1D63($a2)
    MEM_B(0X1D63, ctx->r6) = ctx->r10;
L_8000604C:
    // 0x8000604C: lw          $t3, 0x1B54($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X1B54);
    // 0x80006050: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006054: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80006058: sltu        $at, $v0, $t3
    ctx->r1 = ctx->r2 < ctx->r11 ? 1 : 0;
    // 0x8000605C: bnel        $at, $zero, L_80006010
    if (ctx->r1 != 0) {
        // 0x80006060: lw          $t5, 0x1B50($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X1B50);
            goto L_80006010;
    }
    goto skip_2;
    // 0x80006060: lw          $t5, 0x1B50($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X1B50);
    skip_2:
L_80006064:
    // 0x80006064: jr          $ra
    // 0x80006068: sw          $zero, 0x1B5C($a2)
    MEM_W(0X1B5C, ctx->r6) = 0;
    return;
    // 0x80006068: sw          $zero, 0x1B5C($a2)
    MEM_W(0X1B5C, ctx->r6) = 0;
;}
RECOMP_FUNC void func_8064E11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E11C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064E120: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8064E124: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8064E128: nop

    // 0x8064E12C: bc1f        L_8064E164
    if (!c1cs) {
        // 0x8064E130: nop
    
            goto L_8064E164;
    }
    // 0x8064E130: nop

    // 0x8064E134: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8064E138: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8064E13C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8064E140: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8064E144: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8064E148: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8064E14C: nop

    // 0x8064E150: bc1f        L_8064E164
    if (!c1cs) {
        // 0x8064E154: nop
    
            goto L_8064E164;
    }
    // 0x8064E154: nop

    // 0x8064E158: swc1        $f2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f2.u32l;
    // 0x8064E15C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x8064E160: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
L_8064E164:
    // 0x8064E164: jr          $ra
    // 0x8064E168: nop

    return;
    // 0x8064E168: nop

;}
RECOMP_FUNC void func_80714A38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714A38: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80714A3C: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x80714A40: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80714A44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80714A48: nop

    // 0x80714A4C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80714A50: nop

    // 0x80714A54: bc1fl       L_80714A84
    if (!c1cs) {
        // 0x80714A58: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_80714A84;
    }
    goto skip_0;
    // 0x80714A58: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80714A5C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80714A60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80714A64: nop

    // 0x80714A68: bc1f        L_80714AA0
    if (!c1cs) {
        // 0x80714A6C: nop
    
            goto L_80714AA0;
    }
    // 0x80714A6C: nop

    // 0x80714A70: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80714A74: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80714A78: jr          $ra
    // 0x80714A7C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80714A7C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80714A80: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_80714A84:
    // 0x80714A84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80714A88: nop

    // 0x80714A8C: bc1f        L_80714AA0
    if (!c1cs) {
        // 0x80714A90: nop
    
            goto L_80714AA0;
    }
    // 0x80714A90: nop

    // 0x80714A94: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80714A98: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80714A9C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_80714AA0:
    // 0x80714AA0: jr          $ra
    // 0x80714AA4: nop

    return;
    // 0x80714AA4: nop

;}
RECOMP_FUNC void func_80435748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435748: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8043574C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80435750: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80435754: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80435758: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8043575C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80435760: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
    // 0x80435764: addiu       $v1, $v0, 0xE8C
    ctx->r3 = ADD32(ctx->r2, 0XE8C);
L_80435768:
    // 0x80435768: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8043576C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80435770: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80435774: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80435778: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x8043577C: bc1fl       L_80435790
    if (!c1cs) {
        // 0x80435780: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80435790;
    }
    goto skip_0;
    // 0x80435780: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x80435784: b           L_804357A0
    // 0x80435788: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_804357A0;
    // 0x80435788: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8043578C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80435790:
    // 0x80435790: nop

    // 0x80435794: bc1fl       L_804357A4
    if (!c1cs) {
        // 0x80435798: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_804357A4;
    }
    goto skip_1;
    // 0x80435798: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x8043579C: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_804357A0:
    // 0x804357A0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_804357A4:
    // 0x804357A4: nop

    // 0x804357A8: bc1fl       L_804357BC
    if (!c1cs) {
        // 0x804357AC: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_804357BC;
    }
    goto skip_2;
    // 0x804357AC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x804357B0: b           L_804357CC
    // 0x804357B4: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
        goto L_804357CC;
    // 0x804357B4: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x804357B8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_804357BC:
    // 0x804357BC: nop

    // 0x804357C0: bc1fl       L_804357D0
    if (!c1cs) {
        // 0x804357C4: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_804357D0;
    }
    goto skip_3;
    // 0x804357C4: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_3:
    // 0x804357C8: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_804357CC:
    // 0x804357CC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_804357D0:
    // 0x804357D0: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x804357D4: bgez        $a1, L_80435768
    if (SIGNED(ctx->r5) >= 0) {
        // 0x804357D8: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80435768;
    }
    // 0x804357D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x804357DC: jr          $ra
    // 0x804357E0: nop

    return;
    // 0x804357E0: nop

;}
RECOMP_FUNC void func_806CFB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CFB2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CFB30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CFB34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CFB38: jal         0x8004700C
    // 0x806CFB3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806CFB3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CFB40: beql        $v0, $zero, L_806CFBE4
    if (ctx->r2 == 0) {
        // 0x806CFB44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CFBE4;
    }
    goto skip_0;
    // 0x806CFB44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806CFB48: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806CFB4C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806CFB50: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x806CFB54: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806CFB58: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806CFB5C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806CFB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CFB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CFB68: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806CFB6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806CFB70: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806CFB74: nop

    // 0x806CFB78: bc1fl       L_806CFBE4
    if (!c1cs) {
        // 0x806CFB7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806CFBE4;
    }
    goto skip_1;
    // 0x806CFB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806CFB80: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x806CFB84: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806CFB88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806CFB8C: lwc1        $f10, 0x4($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X4);
    // 0x806CFB90: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806CFB94: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806CFB98: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806CFB9C: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x806CFBA0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x806CFBA4: beq         $v0, $zero, L_806CFBB0
    if (ctx->r2 == 0) {
        // 0x806CFBA8: nop
    
            goto L_806CFBB0;
    }
    // 0x806CFBA8: nop

    // 0x806CFBAC: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_806CFBB0:
    // 0x806CFBB0: jal         0x806D093C
    // 0x806CFBB4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806D093C(rdram, ctx);
        goto after_1;
    // 0x806CFBB4: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806CFBB8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AD4) << 16);
    // 0x806CFBBC: lwc1        $f12, 0x1274($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AD4));
    // 0x806CFBC0: jal         0x806CF864
    // 0x806CFBC4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_806CF864(rdram, ctx);
        goto after_2;
    // 0x806CFBC4: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x806CFBC8: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x806CFBCC: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(607, 0X1AD8) << 16);
    // 0x806CFBD0: lwc1        $f14, 0x1278($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(607, 0X1AD8));
    // 0x806CFBD4: jal         0x806CF864
    // 0x806CFBD8: lwc1        $f12, 0xE8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XE8);
    func_806CF864(rdram, ctx);
        goto after_3;
    // 0x806CFBD8: lwc1        $f12, 0xE8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XE8);
    after_3:
    // 0x806CFBDC: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x806CFBE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806CFBE4:
    // 0x806CFBE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CFBE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CFBEC: jr          $ra
    // 0x806CFBF0: nop

    return;
    // 0x806CFBF0: nop

;}
RECOMP_FUNC void func_8005F700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005F704: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005F708: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005F70C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005F710: lui         $at, 0x1997
    ctx->r1 = S32(0X1997 << 16);
    // 0x8005F714: ori         $at, $at, 0x1110
    ctx->r1 = ctx->r1 | 0X1110;
    // 0x8005F718: beq         $t6, $at, L_8005F738
    if (ctx->r14 == ctx->r1) {
        // 0x8005F71C: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8005F738;
    }
    // 0x8005F71C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005F720: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005F724: addiu       $a0, $a0, 0xD40
    ctx->r4 = ADD32(ctx->r4, 0XD40);
    // 0x8005F728: jal         0x80071380
    // 0x8005F72C: addiu       $a1, $zero, 0x629
    ctx->r5 = ADD32(0, 0X629);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005F72C: addiu       $a1, $zero, 0x629
    ctx->r5 = ADD32(0, 0X629);
    after_0:
    // 0x8005F730: b           L_8005F7C4
    // 0x8005F734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005F7C4;
    // 0x8005F734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005F738:
    // 0x8005F738: lbu         $v0, 0x164($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X164);
    // 0x8005F73C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005F740: beql        $v0, $at, L_8005F7AC
    if (ctx->r2 == ctx->r1) {
        // 0x8005F744: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_8005F7AC;
    }
    goto skip_0;
    // 0x8005F744: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    skip_0:
    // 0x8005F748: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x8005F74C: bnel        $v0, $zero, L_8005F760
    if (ctx->r2 != 0) {
        // 0x8005F750: lw          $t7, 0xC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XC);
            goto L_8005F760;
    }
    goto skip_1;
    // 0x8005F750: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8005F754: b           L_8005F7C4
    // 0x8005F758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005F7C4;
    // 0x8005F758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F75C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
L_8005F760:
    // 0x8005F760: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F764: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8005F768: bnel        $t8, $at, L_8005F7A0
    if (ctx->r24 != ctx->r1) {
        // 0x8005F76C: lw          $t1, 0x16C($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X16C);
            goto L_8005F7A0;
    }
    goto skip_2;
    // 0x8005F76C: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    skip_2:
    // 0x8005F770: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8005F774: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8005F778: lh          $a2, 0x26($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X26);
    // 0x8005F77C: jal         0x800591EC
    // 0x8005F780: lh          $a3, 0x28($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X28);
    func_800591EC(rdram, ctx);
        goto after_1;
    // 0x8005F780: lh          $a3, 0x28($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X28);
    after_1:
    // 0x8005F784: bne         $v0, $zero, L_8005F79C
    if (ctx->r2 != 0) {
        // 0x8005F788: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8005F79C;
    }
    // 0x8005F788: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005F78C: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8005F790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005F794: b           L_8005F7C4
    // 0x8005F798: sb          $t9, 0x25($t0)
    MEM_B(0X25, ctx->r8) = ctx->r25;
        goto L_8005F7C4;
    // 0x8005F798: sb          $t9, 0x25($t0)
    MEM_B(0X25, ctx->r8) = ctx->r25;
L_8005F79C:
    // 0x8005F79C: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
L_8005F7A0:
    // 0x8005F7A0: sb          $zero, 0x25($t1)
    MEM_B(0X25, ctx->r9) = 0;
    // 0x8005F7A4: lbu         $v0, 0x164($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X164);
    // 0x8005F7A8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
L_8005F7AC:
    // 0x8005F7AC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8005F7B0: addu        $t9, $t9, $t2
    ctx->r25 = ADD32(ctx->r25, ctx->r10);
    // 0x8005F7B4: lw          $t9, 0x64A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X64A0);
    // 0x8005F7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005F7BC: jalr        $t9
    // 0x8005F7C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8005F7C0: nop

    after_2:
L_8005F7C4:
    // 0x8005F7C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005F7CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005F7D0: jr          $ra
    // 0x8005F7D4: nop

    return;
    // 0x8005F7D4: nop

;}
RECOMP_FUNC void func_80716C58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716C58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80716C5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80716C60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80716C64: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80716C68: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80716C6C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80716C70: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80716C74: lw          $v1, 0x6E40($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E40);
    // 0x80716C78: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80716C7C: beql        $v1, $zero, L_80716C98
    if (ctx->r3 == 0) {
        // 0x80716C80: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80716C98;
    }
    goto skip_0;
    // 0x80716C80: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80716C84: jal         0x807169C8
    // 0x80716C88: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    func_807169C8(rdram, ctx);
        goto after_0;
    // 0x80716C88: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_0:
    // 0x80716C8C: b           L_80716CBC
    // 0x80716C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80716CBC;
    // 0x80716C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80716C94: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80716C98:
    // 0x80716C98: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80716C9C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80716CA0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80716CA4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80716CA8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80716CAC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80716CB0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80716CB4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80716CB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80716CBC:
    // 0x80716CBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80716CC0: jr          $ra
    // 0x80716CC4: nop

    return;
    // 0x80716CC4: nop

;}
RECOMP_FUNC void func_804211D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804211D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804211DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804211E0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804211E4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804211E8: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(32, 0X170C) << 16);
    // 0x804211EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804211F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804211F4: lw          $t8, 0x27CC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(32, 0X170C));
    // 0x804211F8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804211FC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80421200: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80421204: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80421208: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042120C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80421210: beql        $v1, $zero, L_80421244
    if (ctx->r3 == 0) {
        // 0x80421214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80421244;
    }
    goto skip_0;
    // 0x80421214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80421218: jalr        $v1
    // 0x8042121C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042121C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80421220: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80421224: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80421228: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042122C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80421230: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80421234: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80421238: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042123C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80421240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80421244:
    // 0x80421244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80421248: jr          $ra
    // 0x8042124C: nop

    return;
    // 0x8042124C: nop

;}
RECOMP_FUNC void func_806AB100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AB100: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806AB104: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AB108: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AB10C: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x806AB110: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AB114: jal         0x8004700C
    // 0x806AB118: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806AB118: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_0:
    // 0x806AB11C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x806AB120: beq         $a1, $zero, L_806AB1CC
    if (ctx->r5 == 0) {
        // 0x806AB124: nop
    
            goto L_806AB1CC;
    }
    // 0x806AB124: nop

    // 0x806AB128: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x806AB12C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806AB130: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806AB134: lh          $t7, 0x2($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X2);
    // 0x806AB138: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806AB13C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806AB140: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x806AB144: nop

    // 0x806AB148: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806AB14C: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806AB150: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806AB154: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806AB158: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806AB15C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806AB160: nop

    // 0x806AB164: bc1f        L_806AB188
    if (!c1cs) {
        // 0x806AB168: nop
    
            goto L_806AB188;
    }
    // 0x806AB168: nop

    // 0x806AB16C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x806AB170: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB174: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x806AB178: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x806AB17C: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB180: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x806AB184: sh          $t9, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r25;
L_806AB188:
    // 0x806AB188: beq         $v0, $zero, L_806AB1CC
    if (ctx->r2 == 0) {
        // 0x806AB18C: nop
    
            goto L_806AB1CC;
    }
    // 0x806AB18C: nop

    // 0x806AB190: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x806AB194: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x806AB198: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x806AB19C: beq         $t2, $zero, L_806AB1CC
    if (ctx->r10 == 0) {
        // 0x806AB1A0: nop
    
            goto L_806AB1CC;
    }
    // 0x806AB1A0: nop

    // 0x806AB1A4: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806AB1A8: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x806AB1AC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806AB1B0: nop

    // 0x806AB1B4: bc1f        L_806AB1CC
    if (!c1cs) {
        // 0x806AB1B8: nop
    
            goto L_806AB1CC;
    }
    // 0x806AB1B8: nop

    // 0x806AB1BC: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB1C0: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB1C4: ori         $t4, $t3, 0x2
    ctx->r12 = ctx->r11 | 0X2;
    // 0x806AB1C8: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_806AB1CC:
    // 0x806AB1CC: jal         0x806AB0A0
    // 0x806AB1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AB0A0(rdram, ctx);
        goto after_1;
    // 0x806AB1D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806AB1D4: beql        $v0, $zero, L_806AB234
    if (ctx->r2 == 0) {
        // 0x806AB1D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AB234;
    }
    goto skip_0;
    // 0x806AB1D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806AB1DC: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB1E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB1E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AB1E8: lhu         $t7, 0x0($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X0);
    // 0x806AB1EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806AB1F0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806AB1F4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x806AB1F8: beq         $t8, $zero, L_806AB230
    if (ctx->r24 == 0) {
        // 0x806AB1FC: addiu       $t9, $s0, 0xC4
        ctx->r25 = ADD32(ctx->r16, 0XC4);
            goto L_806AB230;
    }
    // 0x806AB1FC: addiu       $t9, $s0, 0xC4
    ctx->r25 = ADD32(ctx->r16, 0XC4);
    // 0x806AB200: jal         0x806AB72C
    // 0x806AB204: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    func_806AB72C(rdram, ctx);
        goto after_2;
    // 0x806AB204: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_2:
    // 0x806AB208: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806AB20C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x806AB210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AB214: addiu       $a1, $zero, 0x270
    ctx->r5 = ADD32(0, 0X270);
    // 0x806AB218: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x806AB21C: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806AB220: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x806AB224: andi        $t2, $t1, 0xFFFD
    ctx->r10 = ctx->r9 & 0XFFFD;
    // 0x806AB228: jal         0x806AAC54
    // 0x806AB22C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    func_806AAC54(rdram, ctx);
        goto after_3;
    // 0x806AB22C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    after_3:
L_806AB230:
    // 0x806AB230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AB234:
    // 0x806AB234: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AB238: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806AB23C: jr          $ra
    // 0x806AB240: nop

    return;
    // 0x806AB240: nop

;}
RECOMP_FUNC void func_80050404(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050404: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050408: addiu       $t7, $a1, -0x1
    ctx->r15 = ADD32(ctx->r5, -0X1);
    // 0x8005040C: slti        $at, $t7, 0x15
    ctx->r1 = SIGNED(ctx->r15) < 0X15 ? 1 : 0;
    // 0x80050410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050414: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050418: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005041C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80050420: bne         $at, $zero, L_80050438
    if (ctx->r1 != 0) {
        // 0x80050424: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_80050438;
    }
    // 0x80050424: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80050428: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005042C: addiu       $a0, $a0, 0x960
    ctx->r4 = ADD32(ctx->r4, 0X960);
    // 0x80050430: jal         0x80071380
    // 0x80050434: addiu       $a1, $zero, 0x504
    ctx->r5 = ADD32(0, 0X504);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80050434: addiu       $a1, $zero, 0x504
    ctx->r5 = ADD32(0, 0X504);
    after_0:
L_80050438:
    // 0x80050438: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8005043C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050440: addiu       $a0, $a0, 0x96C
    ctx->r4 = ADD32(ctx->r4, 0X96C);
    // 0x80050444: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80050448: slti        $at, $t9, 0x10
    ctx->r1 = SIGNED(ctx->r25) < 0X10 ? 1 : 0;
    // 0x8005044C: bnel        $at, $zero, L_80050460
    if (ctx->r1 != 0) {
        // 0x80050450: lw          $v0, 0x18($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X18);
            goto L_80050460;
    }
    goto skip_0;
    // 0x80050450: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80050454: jal         0x80071380
    // 0x80050458: addiu       $a1, $zero, 0x50B
    ctx->r5 = ADD32(0, 0X50B);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80050458: addiu       $a1, $zero, 0x50B
    ctx->r5 = ADD32(0, 0X50B);
    after_1:
    // 0x8005045C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80050460:
    // 0x80050460: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80050464: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x80050468: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8005046C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80050470: addiu       $v0, $v0, 0x38
    ctx->r2 = ADD32(ctx->r2, 0X38);
    // 0x80050474: bne         $v1, $zero, L_80050494
    if (ctx->r3 != 0) {
        // 0x80050478: sll         $t2, $t1, 1
        ctx->r10 = S32(ctx->r9 << 1);
            goto L_80050494;
    }
    // 0x80050478: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8005047C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050480: addiu       $a0, $a0, 0x978
    ctx->r4 = ADD32(ctx->r4, 0X978);
    // 0x80050484: jal         0x80071380
    // 0x80050488: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80050488: addiu       $a1, $zero, 0x511
    ctx->r5 = ADD32(0, 0X511);
    after_2:
    // 0x8005048C: b           L_800504C4
    // 0x80050490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800504C4;
    // 0x80050490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80050494:
    // 0x80050494: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80050498: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005049C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800504A0: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800504A4: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800504A8: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800504AC: sh          $t0, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r8;
    // 0x800504B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800504B4: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800504B8: jal         0x8004F26C
    // 0x800504BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004F26C(rdram, ctx);
        goto after_3;
    // 0x800504BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800504C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800504C4:
    // 0x800504C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800504C8: jr          $ra
    // 0x800504CC: nop

    return;
    // 0x800504CC: nop

;}
RECOMP_FUNC void func_80034F80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034F84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034F88: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034F8C: lw          $t7, 0x24($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X24);
    // 0x80034F90: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x80034F94: beql        $t8, $zero, L_80034FE8
    if (ctx->r24 == 0) {
        // 0x80034F98: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80034FE8;
    }
    goto skip_0;
    // 0x80034F98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80034F9C: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80034FA0: jal         0x80065954
    // 0x80034FA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80034FA4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80034FA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034FAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034FB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80034FB4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034FB8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80034FBC: nop

    // 0x80034FC0: bc1f        L_80034FD8
    if (!c1cs) {
        // 0x80034FC4: nop
    
            goto L_80034FD8;
    }
    // 0x80034FC4: nop

    // 0x80034FC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034FCC: lwc1        $f6, 0xD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD0);
    // 0x80034FD0: b           L_80034FF0
    // 0x80034FD4: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
        goto L_80034FF0;
    // 0x80034FD4: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
L_80034FD8:
    // 0x80034FD8: lwc1        $f8, 0xD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XD4);
    // 0x80034FDC: b           L_80034FF0
    // 0x80034FE0: swc1        $f8, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f8.u32l;
        goto L_80034FF0;
    // 0x80034FE0: swc1        $f8, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f8.u32l;
    // 0x80034FE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80034FE8:
    // 0x80034FE8: nop

    // 0x80034FEC: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
L_80034FF0:
    // 0x80034FF0: jal         0x80023EA0
    // 0x80034FF4: nop

    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x80034FF4: nop

    after_1:
    // 0x80034FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035000: jr          $ra
    // 0x80035004: nop

    return;
    // 0x80035004: nop

;}
RECOMP_FUNC void func_80011600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011604: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011608: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x8001160C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80011610: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80011614: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80011618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001161C: bltz        $a3, L_8001167C
    if (SIGNED(ctx->r7) < 0) {
        // 0x80011620: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8001167C;
    }
    // 0x80011620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80011624: sll         $a0, $a1, 16
    ctx->r4 = S32(ctx->r5 << 16);
    // 0x80011628: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8001162C: jal         0x8001137C
    // 0x80011630: sh          $a3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r7;
    func_8001137C(rdram, ctx);
        goto after_0;
    // 0x80011630: sh          $a3, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r7;
    after_0:
    // 0x80011634: lh          $a3, 0x1A($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1A);
    // 0x80011638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001163C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80011640: sll         $a0, $a3, 16
    ctx->r4 = S32(ctx->r7 << 16);
    // 0x80011644: jal         0x8001A850
    // 0x80011648: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8001A850(rdram, ctx);
        goto after_1;
    // 0x80011648: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8001164C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80011650: jal         0x80011540
    // 0x80011654: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
    func_80011540(rdram, ctx);
        goto after_2;
    // 0x80011654: sw          $v0, -0x6D70($at)
    MEM_W(-0X6D70, ctx->r1) = ctx->r2;
    after_2:
    // 0x80011658: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001165C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80011660: jal         0x8001AE64
    // 0x80011664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001AE64(rdram, ctx);
        goto after_3;
    // 0x80011664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80011668: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001166C: jal         0x800186E0
    // 0x80011670: lw          $a0, -0x6D30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D30);
    func_800186E0(rdram, ctx);
        goto after_4;
    // 0x80011670: lw          $a0, -0x6D30($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D30);
    after_4:
    // 0x80011674: jal         0x80018B78
    // 0x80011678: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80018B78(rdram, ctx);
        goto after_5;
    // 0x80011678: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_5:
L_8001167C:
    // 0x8001167C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80011684: jr          $ra
    // 0x80011688: nop

    return;
    // 0x80011688: nop

;}
RECOMP_FUNC void func_806F8058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F805C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806F8064: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806F8068: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806F806C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x806F8070: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F8074: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x806F8078: lw          $t9, 0x168($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X168);
    // 0x806F807C: addiu       $t1, $t7, 0x8
    ctx->r9 = ADD32(ctx->r15, 0X8);
    // 0x806F8080: lw          $t0, 0x88($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X88);
    // 0x806F8084: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x806F8088: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x806F808C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x806F8090: jal         0x806F7B28
    // 0x806F8094: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    func_806F7B28(rdram, ctx);
        goto after_0;
    // 0x806F8094: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    after_0:
    // 0x806F8098: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F809C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F80A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F80A4: jal         0x8007711C
    // 0x806F80A8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    func_8007711C(rdram, ctx);
        goto after_1;
    // 0x806F80A8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x806F80AC: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x806F80B0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x806F80B4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x806F80B8: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x806F80BC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x806F80C0: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x806F80C4: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x806F80C8: jal         0x806F7DD8
    // 0x806F80CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_806F7DD8(rdram, ctx);
        goto after_2;
    // 0x806F80CC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x806F80D0: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(694, 0X1AC8) << 16);
    // 0x806F80D4: addiu       $a1, $a1, -0x6D28
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(694, 0X1AC8));
    // 0x806F80D8: jal         0x806F7AE4
    // 0x806F80DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_806F7AE4(rdram, ctx);
        goto after_3;
    // 0x806F80DC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x806F80E0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x806F80E4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x806F80E8: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x806F80EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F80F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F80F4: jr          $ra
    // 0x806F80F8: nop

    return;
    // 0x806F80F8: nop

;}
RECOMP_FUNC void func_80065408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065408: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8006540C: jr          $ra
    // 0x80065410: sw          $a0, 0x65CC($at)
    MEM_W(0X65CC, ctx->r1) = ctx->r4;
    return;
    // 0x80065410: sw          $a0, 0x65CC($at)
    MEM_W(0X65CC, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_804B8C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B8C04: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804B8C08: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804B8C0C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804B8C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B8C14: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804B8C18: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804B8C1C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804B8C20: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804B8C24: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804B8C28: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(185, 0X29D4) << 16);
    // 0x804B8C2C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804B8C30: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804B8C34: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804B8C38: lw          $t2, -0x580C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(185, 0X29D4));
    // 0x804B8C3C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804B8C40: jal         0x804B8770
    // 0x804B8C44: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804B8770(rdram, ctx);
        goto after_0;
    // 0x804B8C44: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804B8C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B8C4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B8C50: jr          $ra
    // 0x804B8C54: nop

    return;
    // 0x804B8C54: nop

;}
RECOMP_FUNC void func_804506D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804506D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804506D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804506D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804506DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804506E0: jal         0x8006E0FC
    // 0x804506E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x804506E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x804506E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804506EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804506F0: sw          $zero, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = 0;
    // 0x804506F4: jr          $ra
    // 0x804506F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804506F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806F3884(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F3884: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F3888: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F388C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F3890: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x806F3894: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F3898: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F389C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F38A0: jal         0x80065ABC
    // 0x806F38A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F38A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F38A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F38AC: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x806F38B0: jal         0x806F34EC
    // 0x806F38B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_806F34EC(rdram, ctx);
        goto after_1;
    // 0x806F38B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x806F38B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F38BC: jal         0x806F35BC
    // 0x806F38C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_806F35BC(rdram, ctx);
        goto after_2;
    // 0x806F38C0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x806F38C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F38C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F38CC: jr          $ra
    // 0x806F38D0: nop

    return;
    // 0x806F38D0: nop

;}
RECOMP_FUNC void func_806EE258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE258: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EE25C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EE260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EE264: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EE268: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806EE26C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x806EE270: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x806EE274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806EE278: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EE27C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806EE280: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806EE284: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EE288: nop

    // 0x806EE28C: bc1fl       L_806EE2A0
    if (!c1cs) {
        // 0x806EE290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806EE2A0;
    }
    goto skip_0;
    // 0x806EE290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806EE294: jal         0x8002F6E4
    // 0x806EE298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x806EE298: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806EE29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EE2A0:
    // 0x806EE2A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EE2A4: jr          $ra
    // 0x806EE2A8: nop

    return;
    // 0x806EE2A8: nop

;}
RECOMP_FUNC void func_805ADE74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADE74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADE78: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADE7C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADE80: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADE84: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADE88: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADE8C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADE90: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADE94: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADE98: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADE9C: jr          $ra
    // 0x805ADEA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADEA0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804BE304(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE304: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804BE308: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BE30C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x804BE310: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804BE314: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BE318: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x804BE31C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804BE320: lw          $v0, 0x370($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X370);
    // 0x804BE324: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X2A28) << 16);
    // 0x804BE328: addiu       $t8, $t8, -0x1CA8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X2A28));
    // 0x804BE32C: lwc1        $f4, 0x50($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804BE330: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804BE334: swc1        $f8, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f8.u32l;
    // 0x804BE338: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x804BE33C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x804BE340: nop

    // 0x804BE344: bc1f        L_804BE350
    if (!c1cs) {
        // 0x804BE348: nop
    
            goto L_804BE350;
    }
    // 0x804BE348: nop

    // 0x804BE34C: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
L_804BE350:
    // 0x804BE350: jr          $ra
    // 0x804BE354: nop

    return;
    // 0x804BE354: nop

;}
RECOMP_FUNC void func_80000E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000E24: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80000E28: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000E2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000E30: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000E34: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80000E38: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80000E3C: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80000E40: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x80000E44: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80000E48: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80000E4C: lw          $t8, 0x118($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X118);
    // 0x80000E50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000E54: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80000E58: beq         $t8, $zero, L_80000E9C
    if (ctx->r24 == 0) {
        // 0x80000E5C: lui         $at, 0x702
        ctx->r1 = S32(0X702 << 16);
            goto L_80000E9C;
    }
    // 0x80000E5C: lui         $at, 0x702
    ctx->r1 = S32(0X702 << 16);
    // 0x80000E60: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80000E64: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80000E68: lw          $t1, 0x118($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X118);
    // 0x80000E6C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80000E70: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80000E74: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80000E78: lbu         $t3, 0x18($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X18);
    // 0x80000E7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80000E80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80000E84: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80000E88: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80000E8C: ori         $t6, $t5, 0xC80
    ctx->r14 = ctx->r13 | 0XC80;
    // 0x80000E90: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80000E94: lw          $t7, 0x120($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X120);
    // 0x80000E98: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80000E9C:
    // 0x80000E9C: lw          $t8, 0x11C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X11C);
    // 0x80000EA0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80000EA4: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x80000EA8: beq         $t8, $zero, L_80000EEC
    if (ctx->r24 == 0) {
        // 0x80000EAC: lui         $at, 0x702
        ctx->r1 = S32(0X702 << 16);
            goto L_80000EEC;
    }
    // 0x80000EAC: lui         $at, 0x702
    ctx->r1 = S32(0X702 << 16);
    // 0x80000EB0: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80000EB4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80000EB8: lw          $t1, 0x11C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X11C);
    // 0x80000EBC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80000EC0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80000EC4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80000EC8: lbu         $t3, 0x18($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X18);
    // 0x80000ECC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80000ED0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80000ED4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80000ED8: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80000EDC: ori         $t6, $t5, 0xE20
    ctx->r14 = ctx->r13 | 0XE20;
    // 0x80000EE0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80000EE4: lw          $t7, 0x124($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X124);
    // 0x80000EE8: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_80000EEC:
    // 0x80000EEC: jr          $ra
    // 0x80000EF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80000EF0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void DoRelocation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081430: addiu       $sp, $sp, -0x178
    ctx->r29 = ADD32(ctx->r29, -0X178);
    // 0x80081434: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081438: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8008143C: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x80081440: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x80081444: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80081448: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8008144C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x80081450: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80081454: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x80081458: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8008145C: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
    // 0x80081460: sw          $a0, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r4;
    // 0x80081464: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80081468: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x8008146C: addiu       $s5, $s5, -0x5C70
    ctx->r21 = ADD32(ctx->r21, -0X5C70);
    // 0x80081470: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80081474: sw          $t7, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r15;
    // 0x80081478: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x8008147C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80081480: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80081484: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80081488: sw          $t6, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r14;
    // 0x8008148C: lw          $t1, 0x10($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X10);
    // 0x80081490: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80081494: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80081498: beq         $t1, $zero, L_8008166C
    if (ctx->r9 == 0) {
        // 0x8008149C: or          $t3, $a1, $zero
        ctx->r11 = ctx->r5 | 0;
            goto L_8008166C;
    }
    // 0x8008149C: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x800814A0: lui         $s7, 0xFF
    ctx->r23 = S32(0XFF << 16);
    // 0x800814A4: ori         $s7, $s7, 0xFFFF
    ctx->r23 = ctx->r23 | 0XFFFF;
    // 0x800814A8: lui         $ra, 0x3F00
    ctx->r31 = S32(0X3F00 << 16);
    // 0x800814AC: lui         $fp, 0x200
    ctx->r30 = S32(0X200 << 16);
    // 0x800814B0: addiu       $s6, $sp, 0x168
    ctx->r22 = ADD32(ctx->r29, 0X168);
    // 0x800814B4: lui         $s4, 0xFFFF
    ctx->r20 = S32(0XFFFF << 16);
    // 0x800814B8: lui         $s3, 0xF00
    ctx->r19 = S32(0XF00 << 16);
    // 0x800814BC: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x800814C0: addiu       $t4, $sp, 0xCC
    ctx->r12 = ADD32(ctx->r29, 0XCC);
L_800814C4:
    // 0x800814C4: lw          $v0, 0x14($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X14);
    // 0x800814C8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800814CC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800814D0: srl         $t7, $v0, 30
    ctx->r15 = S32(U32(ctx->r2) >> 30);
    // 0x800814D4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800814D8: addu        $t9, $s6, $t8
    ctx->r25 = ADD32(ctx->r22, ctx->r24);
    // 0x800814DC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800814E0: and         $t7, $v0, $s7
    ctx->r15 = ctx->r2 & ctx->r23;
    // 0x800814E4: and         $v1, $v0, $ra
    ctx->r3 = ctx->r2 & ctx->r31;
    // 0x800814E8: beq         $fp, $v1, L_80081510
    if (ctx->r30 == ctx->r3) {
        // 0x800814EC: addu        $a0, $t6, $t7
        ctx->r4 = ADD32(ctx->r14, ctx->r15);
            goto L_80081510;
    }
    // 0x800814EC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800814F0: beq         $v1, $at, L_80081548
    if (ctx->r3 == ctx->r1) {
        // 0x800814F4: lui         $at, 0x500
        ctx->r1 = S32(0X500 << 16);
            goto L_80081548;
    }
    // 0x800814F4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800814F8: beq         $v1, $at, L_80081594
    if (ctx->r3 == ctx->r1) {
        // 0x800814FC: lui         $at, 0x600
        ctx->r1 = S32(0X600 << 16);
            goto L_80081594;
    }
    // 0x800814FC: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x80081500: beql        $v1, $at, L_800815D0
    if (ctx->r3 == ctx->r1) {
        // 0x80081504: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_800815D0;
    }
    goto skip_0;
    // 0x80081504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80081508: b           L_80081664
    // 0x8008150C: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
        goto L_80081664;
    // 0x8008150C: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
L_80081510:
    // 0x80081510: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80081514: and         $t8, $v0, $s3
    ctx->r24 = ctx->r2 & ctx->r19;
    // 0x80081518: bne         $t8, $zero, L_80081530
    if (ctx->r24 != 0) {
        // 0x8008151C: subu        $t9, $v0, $s2
        ctx->r25 = SUB32(ctx->r2, ctx->r18);
            goto L_80081530;
    }
    // 0x8008151C: subu        $t9, $v0, $s2
    ctx->r25 = SUB32(ctx->r2, ctx->r18);
    // 0x80081520: addu        $t6, $t9, $s1
    ctx->r14 = ADD32(ctx->r25, ctx->r17);
    // 0x80081524: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80081528: b           L_80081660
    // 0x8008152C: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
        goto L_80081660;
    // 0x8008152C: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
L_80081530:
    // 0x80081530: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80081534: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x80081538: bnel        $at, $zero, L_80081664
    if (ctx->r1 != 0) {
        // 0x8008153C: sltu        $at, $t2, $t1
        ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
            goto L_80081664;
    }
    goto skip_1;
    // 0x8008153C: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    skip_1:
    // 0x80081540: b           L_80081664
    // 0x80081544: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
        goto L_80081664;
    // 0x80081544: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
L_80081548:
    // 0x80081548: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8008154C: lui         $at, 0x3FF
    ctx->r1 = S32(0X3FF << 16);
    // 0x80081550: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80081554: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80081558: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008155C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081560: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80081564: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x80081568: lui         $at, 0xFFF
    ctx->r1 = S32(0XFFF << 16);
    // 0x8008156C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80081570: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80081574: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80081578: lui         $at, 0xFC00
    ctx->r1 = S32(0XFC00 << 16);
    // 0x8008157C: srl         $t6, $t9, 2
    ctx->r14 = S32(U32(ctx->r25) >> 2);
    // 0x80081580: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80081584: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80081588: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008158C: b           L_80081660
    // 0x80081590: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
        goto L_80081660;
    // 0x80081590: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
L_80081594:
    // 0x80081594: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80081598: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8008159C: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x800815A0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800815A4: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800815A8: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x800815AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800815B0: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x800815B4: andi        $t7, $t6, 0x1F
    ctx->r15 = ctx->r14 & 0X1F;
    // 0x800815B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800815BC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800815C0: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x800815C4: b           L_80081660
    // 0x800815C8: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
        goto L_80081660;
    // 0x800815C8: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x800815CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_800815D0:
    // 0x800815D0: srl         $v1, $v0, 21
    ctx->r3 = S32(U32(ctx->r2) >> 21);
    // 0x800815D4: andi        $v1, $v1, 0x1F
    ctx->r3 = ctx->r3 & 0X1F;
    // 0x800815D8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800815DC: addu        $t6, $t4, $v1
    ctx->r14 = ADD32(ctx->r12, ctx->r3);
    // 0x800815E0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800815E4: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x800815E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800815EC: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x800815F0: addu        $t0, $t5, $v1
    ctx->r8 = ADD32(ctx->r13, ctx->r3);
    // 0x800815F4: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800815F8: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800815FC: and         $t9, $t8, $s3
    ctx->r25 = ctx->r24 & ctx->r19;
    // 0x80081600: bnel        $t9, $zero, L_80081664
    if (ctx->r25 != 0) {
        // 0x80081604: sltu        $at, $t2, $t1
        ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
            goto L_80081664;
    }
    goto skip_2;
    // 0x80081604: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
    skip_2:
    // 0x80081608: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8008160C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80081610: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80081614: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80081618: subu        $t9, $t8, $s2
    ctx->r25 = SUB32(ctx->r24, ctx->r18);
    // 0x8008161C: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80081620: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x80081624: beq         $t6, $zero, L_80081634
    if (ctx->r14 == 0) {
        // 0x80081628: and         $t7, $a3, $s4
        ctx->r15 = ctx->r7 & ctx->r20;
            goto L_80081634;
    }
    // 0x80081628: and         $t7, $a3, $s4
    ctx->r15 = ctx->r7 & ctx->r20;
    // 0x8008162C: b           L_80081634
    // 0x80081630: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80081634;
    // 0x80081630: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80081634:
    // 0x80081634: srl         $t8, $v0, 16
    ctx->r24 = S32(U32(ctx->r2) >> 16);
    // 0x80081638: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8008163C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x80081640: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80081644: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80081648: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8008164C: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80081650: and         $t7, $t9, $s4
    ctx->r15 = ctx->r25 & ctx->r20;
    // 0x80081654: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80081658: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8008165C: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
L_80081660:
    // 0x80081660: sltu        $at, $t2, $t1
    ctx->r1 = ctx->r10 < ctx->r9 ? 1 : 0;
L_80081664:
    // 0x80081664: bne         $at, $zero, L_800814C4
    if (ctx->r1 != 0) {
        // 0x80081668: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_800814C4;
    }
    // 0x80081668: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_8008166C:
    // 0x8008166C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80081670: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80081674: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x80081678: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8008167C: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x80081680: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x80081684: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x80081688: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8008168C: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x80081690: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x80081694: jr          $ra
    // 0x80081698: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
    return;
    // 0x80081698: addiu       $sp, $sp, 0x178
    ctx->r29 = ADD32(ctx->r29, 0X178);
;}
RECOMP_FUNC void func_8007C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C188: jal         0x8007C174
    // 0x8007C18C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_8007C174(rdram, ctx);
        goto after_0;
    // 0x8007C18C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8007C190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C194: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007C198: jr          $ra
    // 0x8007C19C: nop

    return;
    // 0x8007C19C: nop

;}
RECOMP_FUNC void func_8000D7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D7E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000D7E4: beq         $a0, $zero, L_8000D80C
    if (ctx->r4 == 0) {
        // 0x8000D7E8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000D80C;
    }
    // 0x8000D7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D7EC: jal         0x8000BBF4
    // 0x8000D7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8000BBF4(rdram, ctx);
        goto after_0;
    // 0x8000D7F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8000D7F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000D7F8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D7FC: andi        $t9, $t6, 0xFF7F
    ctx->r25 = ctx->r14 & 0XFF7F;
    // 0x8000D800: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x8000D804: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8000D808: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_8000D80C:
    // 0x8000D80C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000D814: jr          $ra
    // 0x8000D818: nop

    return;
    // 0x8000D818: nop

;}
RECOMP_FUNC void func_80026F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026F84: jal         0x80024668
    // 0x80026F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80024668(rdram, ctx);
        goto after_0;
    // 0x80026F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80026F8C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80026F90: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80026F94: addiu       $t6, $t6, 0x6F0C
    ctx->r14 = ADD32(ctx->r14, 0X6F0C);
    // 0x80026F98: jal         0x8001D770
    // 0x80026F9C: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x80026F9C: sw          $t6, 0x160($t7)
    MEM_W(0X160, ctx->r15) = ctx->r14;
    after_1:
    // 0x80026FA0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80026FA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80026FAC: lw          $a2, 0x34($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X34);
    // 0x80026FB0: jal         0x80067CE4
    // 0x80026FB4: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    func_80067CE4(rdram, ctx);
        goto after_2;
    // 0x80026FB4: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    after_2:
    // 0x80026FB8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80026FBC: jal         0x80067818
    // 0x80026FC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80026FC0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80026FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026FCC: jr          $ra
    // 0x80026FD0: nop

    return;
    // 0x80026FD0: nop

;}
RECOMP_FUNC void func_8003BC64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BC64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003BC68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BC6C: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8003BC70: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8003BC74: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003BC78: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003BC7C: jal         0x80047090
    // 0x8003BC80: addiu       $a0, $zero, 0x401E
    ctx->r4 = ADD32(0, 0X401E);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8003BC80: addiu       $a0, $zero, 0x401E
    ctx->r4 = ADD32(0, 0X401E);
    after_0:
    // 0x8003BC84: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003BC88: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8003BC8C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8003BC90: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8003BC94: lw          $a0, 0x427C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X427C);
    // 0x8003BC98: or          $a1, $v0, $at
    ctx->r5 = ctx->r2 | ctx->r1;
    // 0x8003BC9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8003BCA0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8003BCA4: jal         0x80046804
    // 0x8003BCA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x8003BCA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8003BCAC: bne         $v0, $zero, L_8003BCBC
    if (ctx->r2 != 0) {
        // 0x8003BCB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003BCBC;
    }
    // 0x8003BCB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003BCB4: b           L_8003BCCC
    // 0x8003BCB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003BCCC;
    // 0x8003BCB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BCBC:
    // 0x8003BCBC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003BCC0: jal         0x8003B8B0
    // 0x8003BCC4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_8003B8B0(rdram, ctx);
        goto after_2;
    // 0x8003BCC4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003BCC8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8003BCCC:
    // 0x8003BCCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BCD0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003BCD4: jr          $ra
    // 0x8003BCD8: nop

    return;
    // 0x8003BCD8: nop

;}
RECOMP_FUNC void func_8006CB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB2C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006CB30: lw          $t6, -0x7D6C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D6C);
    // 0x8006CB34: jr          $ra
    // 0x8006CB38: swc1        $f12, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f12.u32l;
    return;
    // 0x8006CB38: swc1        $f12, 0x70($t6)
    MEM_W(0X70, ctx->r14) = ctx->f12.u32l;
;}
RECOMP_FUNC void func_804BBCCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBCCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BBCD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BBCD4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BBCD8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804BBCDC: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X3F4C) << 16);
    // 0x804BBCE0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BBCE4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BBCE8: lw          $t8, -0x784($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(191, 0X3F4C));
    // 0x804BBCEC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BBCF0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BBCF4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804BBCF8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804BBCFC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804BBD00: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804BBD04: beql        $v1, $zero, L_804BBD38
    if (ctx->r3 == 0) {
        // 0x804BBD08: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BBD38;
    }
    goto skip_0;
    // 0x804BBD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BBD0C: jalr        $v1
    // 0x804BBD10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804BBD10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BBD14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BBD18: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804BBD1C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804BBD20: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804BBD24: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804BBD28: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804BBD2C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804BBD30: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804BBD34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BBD38:
    // 0x804BBD38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BBD3C: jr          $ra
    // 0x804BBD40: nop

    return;
    // 0x804BBD40: nop

;}
RECOMP_FUNC void func_806F80FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F80FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F8100: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x806F8104: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x806F8108: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x806F810C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806F8110: lui         $s2, 0x8070
    ctx->r18 = S32(RELOC_HI16(694, 0X1A88) << 16);
    // 0x806F8114: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806F8118: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F811C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F8120: addiu       $s2, $s2, -0x6D68
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(694, 0X1A88));
    // 0x806F8124: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x806F8128: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806F812C: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
L_806F8130:
    // 0x806F8130: lui         $s0, 0x8070
    ctx->r16 = S32(RELOC_HI16(694, 0X1908) << 16);
    // 0x806F8134: addiu       $s0, $s0, -0x6EE8
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(694, 0X1908));
    // 0x806F8138: addiu       $s1, $s4, 0x2F0
    ctx->r17 = ADD32(ctx->r20, 0X2F0);
L_806F813C:
    // 0x806F813C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F8140: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x806F8144: jal         0x80065528
    // 0x806F8148: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x806F8148: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_0:
    // 0x806F814C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x806F8150: bne         $s0, $s2, L_806F813C
    if (ctx->r16 != ctx->r18) {
        // 0x806F8154: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_806F813C;
    }
    // 0x806F8154: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x806F8158: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x806F815C: bne         $s3, $s5, L_806F8130
    if (ctx->r19 != ctx->r21) {
        // 0x806F8160: addiu       $s4, $s4, 0x180
        ctx->r20 = ADD32(ctx->r20, 0X180);
            goto L_806F8130;
    }
    // 0x806F8160: addiu       $s4, $s4, 0x180
    ctx->r20 = ADD32(ctx->r20, 0X180);
    // 0x806F8164: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806F8168: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F816C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F8170: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8174: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806F8178: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806F817C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806F8180: jr          $ra
    // 0x806F8184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806F8184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8044A8D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A8D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044A8D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044A8DC: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044A8E0: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044A8E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044A8E8: jal         0x8044A558
    // 0x8044A8EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044A8EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8044A8F0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044A8F4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044A8F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044A8FC: bne         $v0, $zero, L_8044A914
    if (ctx->r2 != 0) {
        // 0x8044A900: nop
    
            goto L_8044A914;
    }
    // 0x8044A900: nop

    // 0x8044A904: jal         0x80446088
    // 0x8044A908: nop

    func_80446088(rdram, ctx);
        goto after_1;
    // 0x8044A908: nop

    after_1:
    // 0x8044A90C: b           L_8044A938
    // 0x8044A910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A938;
    // 0x8044A910: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A914:
    // 0x8044A914: bne         $v0, $at, L_8044A92C
    if (ctx->r2 != ctx->r1) {
        // 0x8044A918: nop
    
            goto L_8044A92C;
    }
    // 0x8044A918: nop

    // 0x8044A91C: jal         0x804460C8
    // 0x8044A920: nop

    func_804460C8(rdram, ctx);
        goto after_2;
    // 0x8044A920: nop

    after_2:
    // 0x8044A924: b           L_8044A938
    // 0x8044A928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044A938;
    // 0x8044A928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A92C:
    // 0x8044A92C: jal         0x8044610C
    // 0x8044A930: nop

    func_8044610C(rdram, ctx);
        goto after_3;
    // 0x8044A930: nop

    after_3:
    // 0x8044A934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044A938:
    // 0x8044A938: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044A93C: jr          $ra
    // 0x8044A940: nop

    return;
    // 0x8044A940: nop

;}
RECOMP_FUNC void func_806FD688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD68C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD690: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806FD694: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x806FD698: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(706, 0X1250) << 16);
    // 0x806FD69C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FD6A0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806FD6A4: lw          $t8, -0x1950($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(706, 0X1250));
    // 0x806FD6A8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806FD6AC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x806FD6B0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x806FD6B4: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x806FD6B8: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x806FD6BC: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x806FD6C0: beql        $v1, $zero, L_806FD6F4
    if (ctx->r3 == 0) {
        // 0x806FD6C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FD6F4;
    }
    goto skip_0;
    // 0x806FD6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806FD6C8: jalr        $v1
    // 0x806FD6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x806FD6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FD6D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FD6D4: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x806FD6D8: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x806FD6DC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x806FD6E0: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x806FD6E4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x806FD6E8: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x806FD6EC: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x806FD6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FD6F4:
    // 0x806FD6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD6F8: jr          $ra
    // 0x806FD6FC: nop

    return;
    // 0x806FD6FC: nop

;}
RECOMP_FUNC void func_80526F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526F30: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80526F34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80526F38: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80526F3C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80526F40: jal         0x80067BBC
    // 0x80526F44: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80526F44: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80526F48: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    // 0x80526F4C: jal         0x80067818
    // 0x80526F50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80526F50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80526F54: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80526F58: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6164) << 16);
    // 0x80526F5C: lwc1        $f4, -0x3F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6164));
    // 0x80526F60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526F64: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X3B70) << 16);
    // 0x80526F68: addiu       $v0, $v0, -0x6590
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X3B70));
    // 0x80526F6C: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X10A4) << 16);
    // 0x80526F70: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x80526F74: addiu       $t7, $t7, 0x6FA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X10A4));
    // 0x80526F78: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80526F7C: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80526F80: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80526F84: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80526F88: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80526F8C: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80526F90: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80526F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526F98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526F9C: jr          $ra
    // 0x80526FA0: nop

    return;
    // 0x80526FA0: nop

;}
RECOMP_FUNC void func_8003D254(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D25C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003D260: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x8003D264: lw          $v0, 0x160($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X160);
    // 0x8003D268: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003D26C: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8003D270: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003D274: lwc1        $f10, 0x70($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8003D278: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003D27C: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8003D280: lwc1        $f12, 0xC4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8003D284: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003D288: jal         0x80065954
    // 0x8003D28C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8003D28C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003D290: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D294: lwc1        $f12, 0x200($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X200);
    // 0x8003D298: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003D29C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003D2A0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003D2A4: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8003D2A8: bc1fl       L_8003D2BC
    if (!c1cs) {
        // 0x8003D2AC: lwc1        $f4, 0x6C($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
            goto L_8003D2BC;
    }
    goto skip_0;
    // 0x8003D2AC: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    skip_0:
    // 0x8003D2B0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003D2B4: nop

    // 0x8003D2B8: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
L_8003D2BC:
    // 0x8003D2BC: lwc1        $f6, 0x204($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X204);
    // 0x8003D2C0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003D2C4: jal         0x80065954
    // 0x8003D2C8: div.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8003D2C8: div.s       $f12, $f2, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
    after_1:
    // 0x8003D2CC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003D2D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D2D4: nop

    // 0x8003D2D8: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8003D2DC: jal         0x80066DE4
    // 0x8003D2E0: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8003D2E0: nop

    after_2:
    // 0x8003D2E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003D2E8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003D2EC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003D2F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003D2F4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003D2F8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8003D2FC: add.s       $f12, $f18, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8003D300: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8003D304: nop

    // 0x8003D308: bc1f        L_8003D314
    if (!c1cs) {
        // 0x8003D30C: nop
    
            goto L_8003D314;
    }
    // 0x8003D30C: nop

    // 0x8003D310: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8003D314:
    // 0x8003D314: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8003D318: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003D31C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x8003D320: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8003D324: div.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8003D328: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
    // 0x8003D32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003D334: jr          $ra
    // 0x8003D338: nop

    return;
    // 0x8003D338: nop

;}
RECOMP_FUNC void func_8043D1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D1FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8043D200: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8043D204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D208: addu        $v1, $a2, $v0
    ctx->r3 = ADD32(ctx->r6, ctx->r2);
    // 0x8043D20C: addu        $t0, $a1, $v0
    ctx->r8 = ADD32(ctx->r5, ctx->r2);
    // 0x8043D210: lwc1        $f6, 0x84($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X84);
    // 0x8043D214: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8043D218: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8043D21C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8043D220: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8043D224: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8043D228: jal         0x80065954
    // 0x8043D22C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043D22C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8043D230: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8043D234: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043D238: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8043D23C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8043D240: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8043D244: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8043D248: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8043D24C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8043D250: bc1fl       L_8043D26C
    if (!c1cs) {
        // 0x8043D254: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8043D26C;
    }
    goto skip_0;
    // 0x8043D254: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x8043D258: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8043D25C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043D260: b           L_8043D274
    // 0x8043D264: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
        goto L_8043D274;
    // 0x8043D264: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8043D268: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8043D26C:
    // 0x8043D26C: nop

    // 0x8043D270: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
L_8043D274:
    // 0x8043D274: lwc1        $f16, 0x84($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X84);
    // 0x8043D278: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A18) << 16);
    // 0x8043D27C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D280: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x8043D284: nop

    // 0x8043D288: bc1f        L_8043D2D8
    if (!c1cs) {
        // 0x8043D28C: nop
    
            goto L_8043D2D8;
    }
    // 0x8043D28C: nop

    // 0x8043D290: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A18) << 16);
    // 0x8043D294: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D298: lwc1        $f4, -0x15A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A18));
    // 0x8043D29C: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D2A0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A20) << 16);
    // 0x8043D2A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8043D2A8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D2AC: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8043D2B0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8043D2B4: lwc1        $f2, -0x15A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A20));
    // 0x8043D2B8: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D2BC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8043D2C0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8043D2C4: nop

    // 0x8043D2C8: bc1fl       L_8043D314
    if (!c1cs) {
        // 0x8043D2CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043D314;
    }
    goto skip_1;
    // 0x8043D2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043D2D0: b           L_8043D310
    // 0x8043D2D4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
        goto L_8043D310;
    // 0x8043D2D4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8043D2D8:
    // 0x8043D2D8: lwc1        $f4, -0x15A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A18));
    // 0x8043D2DC: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D2E0: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1A20) << 16);
    // 0x8043D2E4: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8043D2E8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8043D2EC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8043D2F0: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8043D2F4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8043D2F8: lwc1        $f2, -0x15A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1A20));
    // 0x8043D2FC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8043D300: nop

    // 0x8043D304: bc1fl       L_8043D314
    if (!c1cs) {
        // 0x8043D308: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043D314;
    }
    goto skip_2;
    // 0x8043D308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8043D30C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8043D310:
    // 0x8043D310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043D314:
    // 0x8043D314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8043D318: jr          $ra
    // 0x8043D31C: nop

    return;
    // 0x8043D31C: nop

;}
RECOMP_FUNC void func_805230F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805230F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805230F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805230F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805230FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80523100: jal         0x8004700C
    // 0x80523104: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80523104: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80523108: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8052310C: beq         $v0, $zero, L_805231B4
    if (ctx->r2 == 0) {
        // 0x80523110: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805231B4;
    }
    // 0x80523110: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80523114: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80523118: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8052311C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80523120: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80523124: nop

    // 0x80523128: bc1tl       L_80523148
    if (c1cs) {
        // 0x8052312C: lw          $t9, 0x10($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X10);
            goto L_80523148;
    }
    goto skip_0;
    // 0x8052312C: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    skip_0:
    // 0x80523130: lw          $t7, -0x72D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X72D8);
    // 0x80523134: addiu       $a2, $zero, 0x309
    ctx->r6 = ADD32(0, 0X309);
    // 0x80523138: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8052313C: bnel        $a2, $t8, L_805231AC
    if (ctx->r6 != ctx->r24) {
        // 0x80523140: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_805231AC;
    }
    goto skip_1;
    // 0x80523140: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_1:
    // 0x80523144: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
L_80523148:
    // 0x80523148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8052314C: addiu       $a2, $zero, 0x309
    ctx->r6 = ADD32(0, 0X309);
    // 0x80523150: beq         $t9, $at, L_805231A8
    if (ctx->r25 == ctx->r1) {
        // 0x80523154: lui         $v0, 0x8010
        ctx->r2 = S32(0X8010 << 16);
            goto L_805231A8;
    }
    // 0x80523154: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80523158: lw          $v0, -0x72D8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72D8);
    // 0x8052315C: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80523160: beql        $a2, $t0, L_8052319C
    if (ctx->r6 == ctx->r8) {
        // 0x80523164: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_8052319C;
    }
    goto skip_2;
    // 0x80523164: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    skip_2:
    // 0x80523168: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8052316C: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80523170: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80523174: beql        $at, $zero, L_8052319C
    if (ctx->r1 == 0) {
        // 0x80523178: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_8052319C;
    }
    goto skip_3;
    // 0x80523178: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    skip_3:
    // 0x8052317C: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80523180: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80523184: jal         0x800677F8
    // 0x80523188: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x80523188: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8052318C: jal         0x8002FF38
    // 0x80523190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002FF38(rdram, ctx);
        goto after_2;
    // 0x80523190: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80523194: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80523198: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
L_8052319C:
    // 0x8052319C: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x805231A0: sw          $t2, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r10;
    // 0x805231A4: sw          $t3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r11;
L_805231A8:
    // 0x805231A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_805231AC:
    // 0x805231AC: jal         0x80522AD4
    // 0x805231B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80522AD4(rdram, ctx);
        goto after_3;
    // 0x805231B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_805231B4:
    // 0x805231B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805231B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805231BC: jr          $ra
    // 0x805231C0: nop

    return;
    // 0x805231C0: nop

;}
RECOMP_FUNC void func_8043E8C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E8C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E8C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E8CC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043E8D0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8043E8D4: lui         $t7, 0x8044
    ctx->r15 = S32(RELOC_HI16(92, 0X1A38) << 16);
    // 0x8043E8D8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x8043E8DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8043E8E0: addiu       $t7, $t7, -0x1588
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(92, 0X1A38));
    // 0x8043E8E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8043E8E8: lui         $t9, 0x8044
    ctx->r25 = S32(RELOC_HI16(92, 0X1830) << 16);
    // 0x8043E8EC: addiu       $t9, $t9, -0x1790
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(92, 0X1830));
    // 0x8043E8F0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8043E8F4: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x8043E8F8: sh          $t0, 0x1F0($a0)
    MEM_H(0X1F0, ctx->r4) = ctx->r8;
    // 0x8043E8FC: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    // 0x8043E900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8043E904: jal         0x8043E490
    // 0x8043E908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043E490(rdram, ctx);
        goto after_0;
    // 0x8043E908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8043E90C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E910: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8043E914: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x8043E918: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(92, 0X1B90) << 16);
    // 0x8043E91C: sw          $t1, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r9;
    // 0x8043E920: lwc1        $f4, -0x1430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(92, 0X1B90));
    // 0x8043E924: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8043E928: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8043E92C: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x8043E930: jal         0x8043E898
    // 0x8043E934: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    func_8043E898(rdram, ctx);
        goto after_1;
    // 0x8043E934: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    after_1:
    // 0x8043E938: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8043E93C: lui         $t2, 0x8044
    ctx->r10 = S32(RELOC_HI16(92, 0X1698) << 16);
    // 0x8043E940: addiu       $t2, $t2, -0x1928
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(92, 0X1698));
    // 0x8043E944: sw          $t2, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r10;
    // 0x8043E948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043E94C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8043E950: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8043E954: sb          $t3, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r11;
    // 0x8043E958: jr          $ra
    // 0x8043E95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8043E95C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805677F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805677F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805677F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805677FC: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x80567800: beql        $v0, $zero, L_80567838
    if (ctx->r2 == 0) {
        // 0x80567804: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80567838;
    }
    goto skip_0;
    // 0x80567804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80567808: jalr        $v0
    // 0x8056780C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8056780C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80567810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80567814: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80567818: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8056781C: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80567820: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80567824: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80567828: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x8056782C: b           L_80567838
    // 0x80567830: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_80567838;
    // 0x80567830: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80567834: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80567838:
    // 0x80567838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8056783C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80567840: jr          $ra
    // 0x80567844: nop

    return;
    // 0x80567844: nop

;}
RECOMP_FUNC void func_8007812C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007812C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078130: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078134: jal         0x800786D4
    // 0x80078138: nop

    func_800786D4(rdram, ctx);
        goto after_0;
    // 0x80078138: nop

    after_0:
    // 0x8007813C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078144: jr          $ra
    // 0x80078148: nop

    return;
    // 0x80078148: nop

;}
RECOMP_FUNC void func_807BAF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAF34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807BAF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAF3C: jal         0x8004700C
    // 0x807BAF40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807BAF40: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x807BAF44: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807BAF48: beq         $v0, $zero, L_807BB098
    if (ctx->r2 == 0) {
        // 0x807BAF4C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_807BB098;
    }
    // 0x807BAF4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x807BAF50: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x807BAF54: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x807BAF58: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807BAF5C: slti        $at, $t7, 0x78
    ctx->r1 = SIGNED(ctx->r15) < 0X78 ? 1 : 0;
    // 0x807BAF60: bne         $at, $zero, L_807BB01C
    if (ctx->r1 != 0) {
        // 0x807BAF64: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_807BB01C;
    }
    // 0x807BAF64: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x807BAF68: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807BAF6C: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x807BAF70: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x807BAF74: nop

    // 0x807BAF78: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807BAF7C: nop

    // 0x807BAF80: bc1fl       L_807BAFD8
    if (!c1cs) {
        // 0x807BAF84: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_807BAFD8;
    }
    goto skip_0;
    // 0x807BAF84: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x807BAF88: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x807BAF8C: jal         0x800653D8
    // 0x807BAF90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x807BAF90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x807BAF94: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x807BAF98: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x807BAF9C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1230) << 16);
    // 0x807BAFA0: lwc1        $f2, -0x45C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1230));
    // 0x807BAFA4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807BAFA8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1234) << 16);
    // 0x807BAFAC: lwc1        $f18, -0x45BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1234));
    // 0x807BAFB0: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1238) << 16);
    // 0x807BAFB4: lwc1        $f6, -0x45B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1238));
    // 0x807BAFB8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807BAFBC: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x807BAFC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807BAFC4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x807BAFC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807BAFCC: b           L_807BB01C
    // 0x807BAFD0: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
        goto L_807BB01C;
    // 0x807BAFD0: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x807BAFD4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_807BAFD8:
    // 0x807BAFD8: jal         0x800653D8
    // 0x807BAFDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x807BAFDC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x807BAFE0: andi        $t0, $v0, 0x3F
    ctx->r8 = ctx->r2 & 0X3F;
    // 0x807BAFE4: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x807BAFE8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X123C) << 16);
    // 0x807BAFEC: lwc1        $f2, -0x45B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X123C));
    // 0x807BAFF0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807BAFF4: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1240) << 16);
    // 0x807BAFF8: lwc1        $f4, -0x45B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1240));
    // 0x807BAFFC: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1244) << 16);
    // 0x807BB000: lwc1        $f8, -0x45AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1244));
    // 0x807BB004: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB008: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x807BB00C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807BB010: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x807BB014: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x807BB018: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
L_807BB01C:
    // 0x807BB01C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x807BB020: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(895, 0X1248) << 16);
    // 0x807BB024: lwc1        $f2, -0x45A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(895, 0X1248));
    // 0x807BB028: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807BB02C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807BB030: lwc1        $f16, 0x88($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X88);
    // 0x807BB034: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807BB038: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x807BB03C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x807BB040: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807BB044: nop

    // 0x807BB048: bc1fl       L_807BB07C
    if (!c1cs) {
        // 0x807BB04C: lwc1        $f0, 0x4($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
            goto L_807BB07C;
    }
    goto skip_1;
    // 0x807BB04C: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x807BB050: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x807BB054: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x807BB058: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x807BB05C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x807BB060: nop

    // 0x807BB064: bc1fl       L_807BB09C
    if (!c1cs) {
        // 0x807BB068: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807BB09C;
    }
    goto skip_2;
    // 0x807BB068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x807BB06C: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x807BB070: b           L_807BB098
    // 0x807BB074: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
        goto L_807BB098;
    // 0x807BB074: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
    // 0x807BB078: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
L_807BB07C:
    // 0x807BB07C: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x807BB080: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x807BB084: nop

    // 0x807BB088: bc1fl       L_807BB09C
    if (!c1cs) {
        // 0x807BB08C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807BB09C;
    }
    goto skip_3;
    // 0x807BB08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x807BB090: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x807BB094: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
L_807BB098:
    // 0x807BB098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807BB09C:
    // 0x807BB09C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807BB0A0: jr          $ra
    // 0x807BB0A4: nop

    return;
    // 0x807BB0A4: nop

;}
RECOMP_FUNC void func_804CC548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC548: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x804CC54C: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(237, 0X1218) << 16);
    // 0x804CC550: addiu       $t6, $t6, -0x2978
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(237, 0X1218));
    // 0x804CC554: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x804CC558: jr          $ra
    // 0x804CC55C: sw          $t6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r14;
    return;
    // 0x804CC55C: sw          $t6, 0x64($t7)
    MEM_W(0X64, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_804A1820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A1824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1828: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804A182C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804A1830: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804A1834: beq         $t7, $zero, L_804A1888
    if (ctx->r15 == 0) {
        // 0x804A1838: nop
    
            goto L_804A1888;
    }
    // 0x804A1838: nop

    // 0x804A183C: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x804A1840: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x804A1844: sltiu       $at, $v0, 0x2
    ctx->r1 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x804A1848: bne         $at, $zero, L_804A1878
    if (ctx->r1 != 0) {
        // 0x804A184C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_804A1878;
    }
    // 0x804A184C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x804A1850: bne         $v0, $at, L_804A1860
    if (ctx->r2 != ctx->r1) {
        // 0x804A1854: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_804A1860;
    }
    // 0x804A1854: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x804A1858: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x804A185C: sw          $v0, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r2;
L_804A1860:
    // 0x804A1860: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x804A1864: bne         $v0, $at, L_804A1870
    if (ctx->r2 != ctx->r1) {
        // 0x804A1868: nop
    
            goto L_804A1870;
    }
    // 0x804A1868: nop

    // 0x804A186C: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
L_804A1870:
    // 0x804A1870: b           L_804A1878
    // 0x804A1874: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
        goto L_804A1878;
    // 0x804A1874: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
L_804A1878:
    // 0x804A1878: jal         0x804A27A0
    // 0x804A187C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_0;
    // 0x804A187C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x804A1880: b           L_804A1888
    // 0x804A1884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804A1888;
    // 0x804A1884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804A1888:
    // 0x804A1888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A188C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A1890: jr          $ra
    // 0x804A1894: nop

    return;
    // 0x804A1894: nop

;}
RECOMP_FUNC void sins(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800828F0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800828F4: srl         $t7, $t6, 4
    ctx->r15 = S32(U32(ctx->r14) >> 4);
    // 0x800828F8: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800828FC: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80082900: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80082904: beq         $t9, $zero, L_80082928
    if (ctx->r25 == 0) {
        // 0x80082908: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80082928;
    }
    // 0x80082908: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008290C: andi        $t0, $t8, 0x3FF
    ctx->r8 = ctx->r24 & 0X3FF;
    // 0x80082910: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80082914: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x80082918: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8008291C: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x80082920: b           L_8008293C
    // 0x80082924: lh          $v1, -0x5452($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5452);
        goto L_8008293C;
    // 0x80082924: lh          $v1, -0x5452($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5452);
L_80082928:
    // 0x80082928: andi        $t3, $v0, 0x3FF
    ctx->r11 = ctx->r2 & 0X3FF;
    // 0x8008292C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80082930: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80082934: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x80082938: lh          $v1, -0x5C50($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X5C50);
L_8008293C:
    // 0x8008293C: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x80082940: beq         $t5, $zero, L_80082958
    if (ctx->r13 == 0) {
        // 0x80082944: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80082958;
    }
    // 0x80082944: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80082948: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8008294C: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80082950: jr          $ra
    // 0x80082954: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
    return;
    // 0x80082954: sra         $v0, $t6, 16
    ctx->r2 = S32(SIGNED(ctx->r14) >> 16);
L_80082958:
    // 0x80082958: jr          $ra
    // 0x8008295C: nop

    return;
    // 0x8008295C: nop

;}
RECOMP_FUNC void func_80057E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057E04: beq         $a1, $zero, L_80057E9C
    if (ctx->r5 == 0) {
        // 0x80057E08: lui         $t6, 0x800A
        ctx->r14 = S32(0X800A << 16);
            goto L_80057E9C;
    }
    // 0x80057E08: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80057E0C: lw          $t6, 0x6130($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6130);
    // 0x80057E10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80057E14: beql        $t6, $a1, L_80057E2C
    if (ctx->r14 == ctx->r5) {
        // 0x80057E18: lh          $t7, 0x6($a1)
        ctx->r15 = MEM_H(ctx->r5, 0X6);
            goto L_80057E2C;
    }
    goto skip_0;
    // 0x80057E18: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    skip_0:
    // 0x80057E1C: sw          $a1, 0x6130($at)
    MEM_W(0X6130, ctx->r1) = ctx->r5;
    // 0x80057E20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057E24: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x80057E28: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
L_80057E2C:
    // 0x80057E2C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80057E30: lw          $v1, -0x4CE0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4CE0);
    // 0x80057E34: bnel        $t7, $zero, L_80057E48
    if (ctx->r15 != 0) {
        // 0x80057E38: lh          $t8, 0x8($a1)
        ctx->r24 = MEM_H(ctx->r5, 0X8);
            goto L_80057E48;
    }
    goto skip_1;
    // 0x80057E38: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    skip_1:
    // 0x80057E3C: jr          $ra
    // 0x80057E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80057E40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057E44: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
L_80057E48:
    // 0x80057E48: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057E4C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80057E50: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80057E54: beq         $at, $zero, L_80057E9C
    if (ctx->r1 == 0) {
        // 0x80057E58: nop
    
            goto L_80057E9C;
    }
    // 0x80057E58: nop

    // 0x80057E5C: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
L_80057E60:
    // 0x80057E60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80057E64: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80057E68: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80057E6C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80057E70: beq         $t1, $zero, L_80057E8C
    if (ctx->r9 == 0) {
        // 0x80057E74: sw          $t1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r9;
            goto L_80057E8C;
    }
    // 0x80057E74: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80057E78: beq         $a3, $t1, L_80057E8C
    if (ctx->r7 == ctx->r9) {
        // 0x80057E7C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80057E8C;
    }
    // 0x80057E7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057E80: sw          $v1, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = ctx->r3;
    // 0x80057E84: jr          $ra
    // 0x80057E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057E88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057E8C:
    // 0x80057E8C: lh          $t2, 0x8($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X8);
    // 0x80057E90: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80057E94: bnel        $at, $zero, L_80057E60
    if (ctx->r1 != 0) {
        // 0x80057E98: lw          $t9, 0x10($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X10);
            goto L_80057E60;
    }
    goto skip_2;
    // 0x80057E98: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    skip_2:
L_80057E9C:
    // 0x80057E9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80057EA0: sw          $zero, -0x4CE0($at)
    MEM_W(-0X4CE0, ctx->r1) = 0;
    // 0x80057EA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057EA8: jr          $ra
    // 0x80057EAC: nop

    return;
    // 0x80057EAC: nop

;}
RECOMP_FUNC void func_806CCF00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CCF00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CCF04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CCF08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CCF0C: jal         0x806CCD24
    // 0x806CCF10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CCD24(rdram, ctx);
        goto after_0;
    // 0x806CCF10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CCF14: jal         0x806CCD4C
    // 0x806CCF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCD4C(rdram, ctx);
        goto after_1;
    // 0x806CCF18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806CCF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CCF20: jal         0x806CBA6C
    // 0x806CCF24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    func_806CBA6C(rdram, ctx);
        goto after_2;
    // 0x806CCF24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x806CCF28: jal         0x806CCE78
    // 0x806CCF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CCE78(rdram, ctx);
        goto after_3;
    // 0x806CCF2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CCF30: jal         0x806CC008
    // 0x806CCF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CC008(rdram, ctx);
        goto after_4;
    // 0x806CCF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806CCF38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CCF3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CCF40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CCF44: jr          $ra
    // 0x806CCF48: nop

    return;
    // 0x806CCF48: nop

;}
RECOMP_FUNC void func_8002B428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B428: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8002B42C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8002B430: lw          $t6, 0xF10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XF10);
    // 0x8002B434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002B438: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002B43C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B440: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x8002B444: lw          $t8, 0xF14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XF14);
    // 0x8002B448: sltu        $at, $t8, $a0
    ctx->r1 = ctx->r24 < ctx->r4 ? 1 : 0;
    // 0x8002B44C: beq         $at, $zero, L_8002B458
    if (ctx->r1 == 0) {
        // 0x8002B450: nop
    
            goto L_8002B458;
    }
    // 0x8002B450: nop

    // 0x8002B454: sw          $a0, 0xF14($v0)
    MEM_W(0XF14, ctx->r2) = ctx->r4;
L_8002B458:
    // 0x8002B458: jal         0x8002B3A0
    // 0x8002B45C: nop

    func_8002B3A0(rdram, ctx);
        goto after_0;
    // 0x8002B45C: nop

    after_0:
    // 0x8002B460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002B468: jr          $ra
    // 0x8002B46C: nop

    return;
    // 0x8002B46C: nop

;}
RECOMP_FUNC void func_80681844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681844: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80681848: lui         $at, 0xC228
    ctx->r1 = S32(0XC228 << 16);
    // 0x8068184C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80681850: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80681854: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80681858: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x8068185C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80681860: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x80681864: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80681868: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8068186C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80681870: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80681874: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80681878: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8068187C: nop

    // 0x80681880: bc1f        L_8068188C
    if (!c1cs) {
        // 0x80681884: nop
    
            goto L_8068188C;
    }
    // 0x80681884: nop

    // 0x80681888: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8068188C:
    // 0x8068188C: jr          $ra
    // 0x80681890: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80681890: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_806F2788(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2788: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F278C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2790: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F2794: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F2798: jal         0x806F2680
    // 0x806F279C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_806F2680(rdram, ctx);
        goto after_0;
    // 0x806F279C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806F27A0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F27A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806F27A8: jal         0x806F2700
    // 0x806F27AC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    func_806F2700(rdram, ctx);
        goto after_1;
    // 0x806F27AC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    after_1:
    // 0x806F27B0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F27B4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x806F27B8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x806F27BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F27C0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806F27C4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806F27C8: beq         $v0, $zero, L_806F27DC
    if (ctx->r2 == 0) {
        // 0x806F27CC: nop
    
            goto L_806F27DC;
    }
    // 0x806F27CC: nop

    // 0x806F27D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x806F27D4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x806F27D8: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
L_806F27DC:
    // 0x806F27DC: jr          $ra
    // 0x806F27E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F27E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_804352CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804352CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804352D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804352D4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804352D8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804352DC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804352E0: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X2A70) << 16);
    // 0x804352E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804352E8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804352EC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804352F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804352F4: lw          $t8, 0x6520($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X2A70));
    // 0x804352F8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804352FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80435300: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80435304: jal         0x80048490
    // 0x80435308: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80435308: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8043530C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80435310: jal         0x80048378
    // 0x80435314: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80435314: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80435318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043531C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80435320: jr          $ra
    // 0x80435324: nop

    return;
    // 0x80435324: nop

;}
RECOMP_FUNC void func_80521818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521818: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8052181C: addiu       $at, $zero, 0x41DA
    ctx->r1 = ADD32(0, 0X41DA);
    // 0x80521820: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x80521824: bne         $t6, $at, L_8052184C
    if (ctx->r14 != ctx->r1) {
        // 0x80521828: lui         $t9, 0x8052
        ctx->r25 = S32(RELOC_HI16(309, 0X338) << 16);
            goto L_8052184C;
    }
    // 0x80521828: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(309, 0X338) << 16);
    // 0x8052182C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80521830: addiu       $t9, $t9, 0x19F8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(309, 0X338));
    // 0x80521834: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80521838: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8052183C: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x80521840: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80521844: b           L_80521870
    // 0x80521848: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
        goto L_80521870;
    // 0x80521848: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
L_8052184C:
    // 0x8052184C: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x80521850: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80521854: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(309, 0X3A8) << 16);
    // 0x80521858: addiu       $t2, $t2, 0x1A68
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(309, 0X3A8));
    // 0x8052185C: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80521860: addu        $a3, $t1, $t2
    ctx->r7 = ADD32(ctx->r9, ctx->r10);
    // 0x80521864: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80521868: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x8052186C: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_80521870:
    // 0x80521870: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80521874: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80521878: lui         $t4, 0x8052
    ctx->r12 = S32(RELOC_HI16(309, 0X248) << 16);
    // 0x8052187C: addiu       $t4, $t4, 0x1908
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(309, 0X248));
    // 0x80521880: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80521884: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x80521888: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8052188C: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80521890: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80521894: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80521898: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8052189C: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x805218A0: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x805218A4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x805218A8: sltu        $at, $t6, $a1
    ctx->r1 = ctx->r14 < ctx->r5 ? 1 : 0;
    // 0x805218AC: bne         $at, $zero, L_805218D0
    if (ctx->r1 != 0) {
        // 0x805218B0: sw          $t6, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r14;
            goto L_805218D0;
    }
    // 0x805218B0: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x805218B4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x805218B8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x805218BC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x805218C0: sltu        $at, $t9, $a2
    ctx->r1 = ctx->r25 < ctx->r6 ? 1 : 0;
    // 0x805218C4: bne         $at, $zero, L_805218D0
    if (ctx->r1 != 0) {
        // 0x805218C8: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_805218D0;
    }
    // 0x805218C8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805218CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_805218D0:
    // 0x805218D0: jr          $ra
    // 0x805218D4: nop

    return;
    // 0x805218D4: nop

;}
RECOMP_FUNC void func_8005B508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B508: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005B50C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005B510: lw          $a1, 0x1C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1C);
    // 0x8005B514: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005B518: beq         $a1, $zero, L_8005B52C
    if (ctx->r5 == 0) {
        // 0x8005B51C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8005B52C;
    }
    // 0x8005B51C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8005B520: jal         0x80064E84
    // 0x8005B524: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8005B524: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005B528: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_8005B52C:
    // 0x8005B52C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005B530: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005B534: jal         0x80073390
    // 0x8005B538: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80073390(rdram, ctx);
        goto after_1;
    // 0x8005B538: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005B53C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005B540: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005B544: jr          $ra
    // 0x8005B548: nop

    return;
    // 0x8005B548: nop

;}
RECOMP_FUNC void func_807B0E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0E30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B0E34: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(871, 0X3680) << 16);
    // 0x807B0E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B0E3C: addiu       $t6, $t6, 0x31D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(871, 0X3680));
    // 0x807B0E40: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x807B0E44: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B0E48: addiu       $v0, $sp, 0x1C
    ctx->r2 = ADD32(ctx->r29, 0X1C);
    // 0x807B0E4C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x807B0E50: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x807B0E54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x807B0E58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x807B0E5C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x807B0E60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807B0E64: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x807B0E68: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x807B0E6C: jalr        $t9
    // 0x807B0E70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807B0E70: nop

    after_0:
    // 0x807B0E74: jal         0x807AFEEC
    // 0x807B0E78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_807AFEEC(rdram, ctx);
        goto after_1;
    // 0x807B0E78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x807B0E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B0E80: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B0E84: jr          $ra
    // 0x807B0E88: nop

    return;
    // 0x807B0E88: nop

;}
RECOMP_FUNC void func_80517120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517128: lw          $v0, 0x160($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X160);
    // 0x8051712C: beql        $v0, $zero, L_80517164
    if (ctx->r2 == 0) {
        // 0x80517130: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80517164;
    }
    goto skip_0;
    // 0x80517130: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80517134: jalr        $v0
    // 0x80517138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80517138: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051713C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80517140: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80517144: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80517148: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8051714C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80517150: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80517154: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80517158: b           L_80517164
    // 0x8051715C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
        goto L_80517164;
    // 0x8051715C: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
    // 0x80517160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80517164:
    // 0x80517164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051716C: jr          $ra
    // 0x80517170: nop

    return;
    // 0x80517170: nop

;}
RECOMP_FUNC void func_80044014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004401C: jal         0x80043F00
    // 0x80044020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80043F00(rdram, ctx);
        goto after_0;
    // 0x80044020: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80044024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80044028: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8004402C: bnel        $t6, $zero, L_80044040
    if (ctx->r14 != 0) {
        // 0x80044030: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80044040;
    }
    goto skip_0;
    // 0x80044030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80044034: jal         0x80057B14
    // 0x80044038: nop

    func_80057B14(rdram, ctx);
        goto after_1;
    // 0x80044038: nop

    after_1:
    // 0x8004403C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044040:
    // 0x80044040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044044: jr          $ra
    // 0x80044048: nop

    return;
    // 0x80044048: nop

;}
RECOMP_FUNC void func_8066ACCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066ACCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066ACD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066ACD4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8066ACD8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8066ACDC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066ACE0: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(514, 0XFF8) << 16);
    // 0x8066ACE4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8066ACE8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8066ACEC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8066ACF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066ACF4: lw          $t8, -0x43A8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(514, 0XFF8));
    // 0x8066ACF8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8066ACFC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8066AD00: jal         0x80048490
    // 0x8066AD04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8066AD04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8066AD08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066AD0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066AD10: jr          $ra
    // 0x8066AD14: nop

    return;
    // 0x8066AD14: nop

;}
RECOMP_FUNC void func_80675DD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675DD8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80675DDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80675DE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80675DE4: jal         0x8004700C
    // 0x80675DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80675DE8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80675DEC: lw          $v1, 0x180($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X180);
    // 0x80675DF0: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80675DF4: beq         $v1, $zero, L_80675ED8
    if (ctx->r3 == 0) {
        // 0x80675DF8: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80675ED8;
    }
    // 0x80675DF8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80675DFC: beql        $v0, $zero, L_80675EDC
    if (ctx->r2 == 0) {
        // 0x80675E00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80675EDC;
    }
    goto skip_0;
    // 0x80675E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80675E04: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80675E08: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80675E0C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80675E10: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80675E14: jal         0x80065954
    // 0x80675E18: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80675E18: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80675E1C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80675E20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80675E24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80675E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80675E2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80675E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80675E34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80675E38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80675E3C: bc1fl       L_80675EDC
    if (!c1cs) {
        // 0x80675E40: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80675EDC;
    }
    goto skip_1;
    // 0x80675E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80675E44: lw          $t0, 0x1F4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1F4);
    // 0x80675E48: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80675E4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80675E50: lwc1        $f10, 0x3EC($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X3EC);
    // 0x80675E54: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80675E58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80675E5C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80675E60: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80675E64: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80675E68: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80675E6C: nop

    // 0x80675E70: bgezl       $v0, L_80675E80
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80675E74: swc1        $f0, 0x3F8($t0)
        MEM_W(0X3F8, ctx->r8) = ctx->f0.u32l;
            goto L_80675E80;
    }
    goto skip_2;
    // 0x80675E74: swc1        $f0, 0x3F8($t0)
    MEM_W(0X3F8, ctx->r8) = ctx->f0.u32l;
    skip_2:
    // 0x80675E78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80675E7C: swc1        $f0, 0x3F8($t0)
    MEM_W(0X3F8, ctx->r8) = ctx->f0.u32l;
L_80675E80:
    // 0x80675E80: jal         0x80677A88
    // 0x80675E84: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80677A88(rdram, ctx);
        goto after_2;
    // 0x80675E84: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x80675E88: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80675E8C: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80675E90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80675E94: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80675E98: sh          $v0, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r2;
    // 0x80675E9C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80675EA0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80675EA4: nop

    // 0x80675EA8: bc1fl       L_80675EC8
    if (!c1cs) {
        // 0x80675EAC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80675EC8;
    }
    goto skip_3;
    // 0x80675EAC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_3:
    // 0x80675EB0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80675EB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80675EB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80675EBC: b           L_80675EDC
    // 0x80675EC0: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
        goto L_80675EDC;
    // 0x80675EC0: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x80675EC4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80675EC8:
    // 0x80675EC8: nop

    // 0x80675ECC: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x80675ED0: b           L_80675EDC
    // 0x80675ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80675EDC;
    // 0x80675ED4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80675ED8:
    // 0x80675ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80675EDC:
    // 0x80675EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80675EE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80675EE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80675EE8: jr          $ra
    // 0x80675EEC: nop

    return;
    // 0x80675EEC: nop

;}
RECOMP_FUNC void gfxprint_putc1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F4A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8007F4A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F4A8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007F4AC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8007F4B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F4B4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F4B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F4BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F4C0: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x8007F4C4: beql        $t8, $zero, L_8007F5E4
    if (ctx->r24 == 0) {
        // 0x8007F4C8: lw          $t9, 0x20($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X20);
            goto L_8007F5E4;
    }
    goto skip_0;
    // 0x8007F4C8: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    skip_0:
    // 0x8007F4CC: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8007F4D0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x8007F4D4: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8007F4D8: beq         $t9, $zero, L_8007F568
    if (ctx->r25 == 0) {
        // 0x8007F4DC: ori         $t7, $t7, 0xE02
        ctx->r15 = ctx->r15 | 0XE02;
            goto L_8007F568;
    }
    // 0x8007F4DC: ori         $t7, $t7, 0xE02
    ctx->r15 = ctx->r15 | 0XE02;
    // 0x8007F4E0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F4E4: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x8007F4E8: ori         $t3, $t3, 0xE02
    ctx->r11 = ctx->r11 | 0XE02;
    // 0x8007F4EC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007F4F0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8007F4F4: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x8007F4F8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007F4FC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007F500: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F504: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x8007F508: ori         $t6, $t6, 0x1402
    ctx->r14 = ctx->r14 | 0X1402;
    // 0x8007F50C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007F510: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8007F514: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x8007F518: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F51C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007F520: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F524: lui         $t2, 0xC18
    ctx->r10 = S32(0XC18 << 16);
    // 0x8007F528: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x8007F52C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F530: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007F534: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x8007F538: ori         $t2, $t2, 0x4240
    ctx->r10 = ctx->r10 | 0X4240;
    // 0x8007F53C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007F540: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F544: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F548: lui         $t4, 0xFC11
    ctx->r12 = S32(0XFC11 << 16);
    // 0x8007F54C: ori         $t4, $t4, 0x15FF
    ctx->r12 = ctx->r12 | 0X15FF;
    // 0x8007F550: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007F554: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8007F558: addiu       $t5, $zero, -0x1C8
    ctx->r13 = ADD32(0, -0X1C8);
    // 0x8007F55C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007F560: b           L_8007F5E0
    // 0x8007F564: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007F5E0;
    // 0x8007F564: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007F568:
    // 0x8007F568: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F56C: ori         $t8, $zero, 0xC000
    ctx->r24 = 0 | 0XC000;
    // 0x8007F570: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8007F574: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F578: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F57C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F580: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F584: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F588: ori         $t2, $t2, 0x1402
    ctx->r10 = ctx->r10 | 0X1402;
    // 0x8007F58C: lui         $t4, 0xB900
    ctx->r12 = S32(0XB900 << 16);
    // 0x8007F590: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F594: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F598: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F59C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007F5A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F5A4: lui         $t5, 0x50
    ctx->r13 = S32(0X50 << 16);
    // 0x8007F5A8: ori         $t5, $t5, 0x4240
    ctx->r13 = ctx->r13 | 0X4240;
    // 0x8007F5AC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007F5B0: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8007F5B4: ori         $t4, $t4, 0x31D
    ctx->r12 = ctx->r12 | 0X31D;
    // 0x8007F5B8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007F5BC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007F5C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F5C4: lui         $t7, 0xFC11
    ctx->r15 = S32(0XFC11 << 16);
    // 0x8007F5C8: ori         $t7, $t7, 0xFE23
    ctx->r15 = ctx->r15 | 0XFE23;
    // 0x8007F5CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F5D0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F5D4: addiu       $t8, $zero, -0xC07
    ctx->r24 = ADD32(0, -0XC07);
    // 0x8007F5D8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F5DC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8007F5E0:
    // 0x8007F5E0: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
L_8007F5E4:
    // 0x8007F5E4: beql        $t9, $zero, L_8007F6DC
    if (ctx->r25 == 0) {
        // 0x8007F5E8: lw          $t4, 0xC($a0)
        ctx->r12 = MEM_W(ctx->r4, 0XC);
            goto L_8007F6DC;
    }
    goto skip_1;
    // 0x8007F5E8: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x8007F5EC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F5F0: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8007F5F4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007F5F8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007F5FC: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8007F600: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F604: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8007F608: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
    // 0x8007F60C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F610: lw          $t9, 0x10($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X10);
    // 0x8007F614: addiu       $t5, $t4, 0x24
    ctx->r13 = ADD32(ctx->r12, 0X24);
    // 0x8007F618: andi        $t6, $t5, 0xFFF
    ctx->r14 = ctx->r13 & 0XFFF;
    // 0x8007F61C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007F620: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8007F624: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007F628: addiu       $t2, $t9, 0x24
    ctx->r10 = ADD32(ctx->r25, 0X24);
    // 0x8007F62C: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x8007F630: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007F634: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x8007F638: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007F63C: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x8007F640: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x8007F644: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007F648: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8007F64C: addiu       $t8, $t2, 0x4
    ctx->r24 = ADD32(ctx->r10, 0X4);
    // 0x8007F650: andi        $t3, $t8, 0xFFF
    ctx->r11 = ctx->r24 & 0XFFF;
    // 0x8007F654: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x8007F658: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x8007F65C: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x8007F660: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x8007F664: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8007F668: or          $t8, $t5, $t2
    ctx->r24 = ctx->r13 | ctx->r10;
    // 0x8007F66C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F670: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F674: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8007F678: andi        $t5, $a1, 0x4
    ctx->r13 = ctx->r5 & 0X4;
    // 0x8007F67C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007F680: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8007F684: sra         $t3, $a1, 3
    ctx->r11 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8007F688: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F68C: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x8007F690: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x8007F694: sll         $t2, $t5, 22
    ctx->r10 = S32(ctx->r13 << 22);
    // 0x8007F698: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8007F69C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007F6A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F6A4: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x8007F6A8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8007F6AC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F6B0: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F6B4: lui         $t5, 0xB300
    ctx->r13 = S32(0XB300 << 16);
    // 0x8007F6B8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007F6BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F6C0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F6C4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007F6C8: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x8007F6CC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8007F6D0: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8007F6D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007F6D8: lw          $t4, 0xC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0XC);
L_8007F6DC:
    // 0x8007F6DC: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F6E0: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8007F6E4: addiu       $t6, $t4, 0x20
    ctx->r14 = ADD32(ctx->r12, 0X20);
    // 0x8007F6E8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007F6EC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007F6F0: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x8007F6F4: sll         $t5, $t7, 12
    ctx->r13 = S32(ctx->r15 << 12);
    // 0x8007F6F8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8007F6FC: addiu       $t9, $t3, 0x20
    ctx->r25 = ADD32(ctx->r11, 0X20);
    // 0x8007F700: andi        $t2, $t9, 0xFFF
    ctx->r10 = ctx->r25 & 0XFFF;
    // 0x8007F704: or          $t8, $t5, $at
    ctx->r24 = ctx->r13 | ctx->r1;
    // 0x8007F708: or          $t4, $t8, $t2
    ctx->r12 = ctx->r24 | ctx->r10;
    // 0x8007F70C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007F710: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8007F714: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x8007F718: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x8007F71C: andi        $t5, $t7, 0x7
    ctx->r13 = ctx->r15 & 0X7;
    // 0x8007F720: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007F724: sll         $t2, $t8, 12
    ctx->r10 = S32(ctx->r24 << 12);
    // 0x8007F728: sll         $t3, $t5, 24
    ctx->r11 = S32(ctx->r13 << 24);
    // 0x8007F72C: or          $t4, $t3, $t2
    ctx->r12 = ctx->r11 | ctx->r10;
    // 0x8007F730: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007F734: or          $t5, $t4, $t7
    ctx->r13 = ctx->r12 | ctx->r15;
    // 0x8007F738: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007F73C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F740: lui         $t8, 0xB400
    ctx->r24 = S32(0XB400 << 16);
    // 0x8007F744: andi        $t4, $a1, 0x4
    ctx->r12 = ctx->r5 & 0X4;
    // 0x8007F748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F74C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F750: sra         $t9, $a1, 3
    ctx->r25 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8007F754: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007F758: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x8007F75C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x8007F760: sll         $t7, $t4, 22
    ctx->r15 = S32(ctx->r12 << 22);
    // 0x8007F764: or          $t2, $t7, $t3
    ctx->r10 = ctx->r15 | ctx->r11;
    // 0x8007F768: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007F76C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8007F770: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x8007F774: ori         $t5, $t5, 0x400
    ctx->r13 = ctx->r13 | 0X400;
    // 0x8007F778: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F77C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8007F780: lui         $t4, 0xB300
    ctx->r12 = S32(0XB300 << 16);
    // 0x8007F784: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007F788: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007F78C: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8007F790: addiu       $t8, $t9, 0x20
    ctx->r24 = ADD32(ctx->r25, 0X20);
    // 0x8007F794: jr          $ra
    // 0x8007F798: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    return;
    // 0x8007F798: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80456E84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456E84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456E88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80456E8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80456E90: jal         0x80456D98
    // 0x80456E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80456D98(rdram, ctx);
        goto after_0;
    // 0x80456E94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80456E98: jal         0x80455948
    // 0x80456E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455948(rdram, ctx);
        goto after_1;
    // 0x80456E9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80456EA0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80456EA4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80456EA8: beq         $v0, $zero, L_80456EC0
    if (ctx->r2 == 0) {
        // 0x80456EAC: nop
    
            goto L_80456EC0;
    }
    // 0x80456EAC: nop

    // 0x80456EB0: lbu         $t6, -0x71F5($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X71F5);
    // 0x80456EB4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456EB8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80456EBC: sw          $t6, 0x6D10($at)
    MEM_W(0X6D10, ctx->r1) = ctx->r14;
L_80456EC0:
    // 0x80456EC0: jal         0x80455770
    // 0x80456EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455770(rdram, ctx);
        goto after_2;
    // 0x80456EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80456EC8: jal         0x804558BC
    // 0x80456ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804558BC(rdram, ctx);
        goto after_3;
    // 0x80456ECC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80456ED0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80456ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456ED8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80456EDC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80456EE0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80456EE4: jal         0x80444A40
    // 0x80456EE8: nop

    func_80444A40(rdram, ctx);
        goto after_4;
    // 0x80456EE8: nop

    after_4:
    // 0x80456EEC: jal         0x80450A74
    // 0x80456EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80450A74(rdram, ctx);
        goto after_5;
    // 0x80456EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80456EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456EF8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80456EFC: jal         0x80457164
    // 0x80456F00: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_80457164(rdram, ctx);
        goto after_6;
    // 0x80456F00: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_6:
    // 0x80456F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80456F08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80456F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80456F10: jr          $ra
    // 0x80456F14: nop

    return;
    // 0x80456F14: nop

;}
RECOMP_FUNC void func_8001A73C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A73C: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A740: lw          $v1, 0x650($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X650);
    // 0x8001A744: bnel        $v1, $zero, L_8001A758
    if (ctx->r3 != 0) {
        // 0x8001A748: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_8001A758;
    }
    goto skip_0;
    // 0x8001A748: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8001A74C: jr          $ra
    // 0x8001A750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8001A750: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001A754: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_8001A758:
    // 0x8001A758: jr          $ra
    // 0x8001A75C: nop

    return;
    // 0x8001A75C: nop

;}
RECOMP_FUNC void func_805A15C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A15C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A15C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A15C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A15CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805A15D0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A15D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A15D8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805A15DC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x805A15E0: bnel        $t6, $zero, L_805A1704
    if (ctx->r14 != 0) {
        // 0x805A15E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A1704;
    }
    goto skip_0;
    // 0x805A15E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A15E8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x805A15EC: beql        $t7, $zero, L_805A1704
    if (ctx->r15 == 0) {
        // 0x805A15F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A1704;
    }
    goto skip_1;
    // 0x805A15F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A15F4: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x805A15F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805A15FC: bnel        $t8, $at, L_805A1704
    if (ctx->r24 != ctx->r1) {
        // 0x805A1600: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A1704;
    }
    goto skip_2;
    // 0x805A1600: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x805A1604: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x805A1608: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A160C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x805A1610: beq         $t9, $zero, L_805A1658
    if (ctx->r25 == 0) {
        // 0x805A1614: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_805A1658;
    }
    // 0x805A1614: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805A1618: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A161C: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x805A1620: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x805A1624: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805A1628: jal         0x8004D1F0
    // 0x805A162C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805A162C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805A1630: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A1634: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x805A1638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A163C: jal         0x8004D698
    // 0x805A1640: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805A1640: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x805A1644: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805A1648: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x805A164C: ori         $t1, $t0, 0xF
    ctx->r9 = ctx->r8 | 0XF;
    // 0x805A1650: b           L_805A1690
    // 0x805A1654: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
        goto L_805A1690;
    // 0x805A1654: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
L_805A1658:
    // 0x805A1658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A165C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x805A1660: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x805A1664: jal         0x8004D1F0
    // 0x805A1668: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x805A1668: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x805A166C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A1670: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x805A1674: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A1678: jal         0x8004D698
    // 0x805A167C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x805A167C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x805A1680: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x805A1684: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x805A1688: ori         $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 | 0XF0;
    // 0x805A168C: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
L_805A1690:
    // 0x805A1690: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805A1694: lwc1        $f4, 0xA8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA8);
    // 0x805A1698: lwc1        $f6, 0xAC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x805A169C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805A16A0: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805A16A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805A16A8: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x805A16AC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805A16B0: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x805A16B4: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805A16B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805A16BC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805A16C0: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805A16C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805A16C8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x805A16CC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x805A16D0: swc1        $f2, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f2.u32l;
    // 0x805A16D4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x805A16D8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    // 0x805A16DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A16E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A16E4: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x805A16E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A16EC: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x805A16F0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805A16F4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805A16F8: jal         0x805A2B28
    // 0x805A16FC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A2B28(rdram, ctx);
        goto after_4;
    // 0x805A16FC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x805A1700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A1704:
    // 0x805A1704: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A1708: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A170C: jr          $ra
    // 0x805A1710: nop

    return;
    // 0x805A1710: nop

;}
RECOMP_FUNC void func_800728EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800728EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800728F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800728F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800728F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800728FC: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x80072900: sw          $a1, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->r5;
    // 0x80072904: jal         0x80072858
    // 0x80072908: sw          $a2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r6;
    func_80072858(rdram, ctx);
        goto after_0;
    // 0x80072908: sw          $a2, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r6;
    after_0:
    // 0x8007290C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80072914: jr          $ra
    // 0x80072918: nop

    return;
    // 0x80072918: nop

;}
RECOMP_FUNC void func_8046AFC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046AFC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046AFCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046AFD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046AFD4: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x8046AFD8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8046AFDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8046AFE0: bne         $a2, $at, L_8046B00C
    if (ctx->r6 != ctx->r1) {
        // 0x8046AFE4: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8046B00C;
    }
    // 0x8046AFE4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8046AFE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8046AFEC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8046AFF0: jal         0x80067D5C
    // 0x8046AFF4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8046AFF4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8046AFF8: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046AFFC: jal         0x80067F78
    // 0x8046B000: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8046B000: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8046B004: b           L_8046B078
    // 0x8046B008: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8046B078;
    // 0x8046B008: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_8046B00C:
    // 0x8046B00C: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x8046B010: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8046B014: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046B018: jal         0x80067930
    // 0x8046B01C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x8046B01C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x8046B020: beq         $v0, $zero, L_8046B058
    if (ctx->r2 == 0) {
        // 0x8046B024: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_8046B058;
    }
    // 0x8046B024: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8046B028: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8046B02C: bne         $v0, $at, L_8046B078
    if (ctx->r2 != ctx->r1) {
        // 0x8046B030: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8046B078;
    }
    // 0x8046B030: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046B034: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8046B038: jal         0x80067D5C
    // 0x8046B03C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8046B03C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8046B040: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046B044: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8046B048: jal         0x800678F0
    // 0x8046B04C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8046B04C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8046B050: b           L_8046B07C
    // 0x8046B054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8046B07C;
    // 0x8046B054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046B058:
    // 0x8046B058: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046B05C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8046B060: jal         0x80067D5C
    // 0x8046B064: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x8046B064: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8046B068: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x8046B06C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8046B070: jal         0x80067838
    // 0x8046B074: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x8046B074: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_8046B078:
    // 0x8046B078: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8046B07C:
    // 0x8046B07C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046B080: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046B084: jr          $ra
    // 0x8046B088: nop

    return;
    // 0x8046B088: nop

;}
RECOMP_FUNC void func_804465DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804465DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804465E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804465E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804465E8: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x804465EC: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x804465F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804465F4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x804465F8: sw          $a1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r5;
    // 0x804465FC: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    // 0x80446600: sw          $t6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r14;
    // 0x80446604: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446608: sw          $t7, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = ctx->r15;
    // 0x8044660C: lui         $v1, 0x8045
    ctx->r3 = S32(RELOC_HI16(98, 0X131EC) << 16);
    // 0x80446610: lw          $v1, 0x75CC($v1)
    ctx->r3 = MEM_W(ctx->r3, (int16_t)RELOC_LO16(98, 0X131EC));
    // 0x80446614: beql        $v1, $zero, L_80446628
    if (ctx->r3 == 0) {
        // 0x80446618: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80446628;
    }
    goto skip_0;
    // 0x80446618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044661C: jalr        $v1
    // 0x80446620: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80446620: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x80446624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80446628:
    // 0x80446628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044662C: jr          $ra
    // 0x80446630: nop

    return;
    // 0x80446630: nop

;}
RECOMP_FUNC void func_806E9760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E9764: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E9768: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E976C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806E9770: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(667, 0X1698) << 16);
    // 0x806E9774: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E9778: addiu       $t6, $t6, -0x66B8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(667, 0X1698));
    // 0x806E977C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E9780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E9784: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E9788: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E978C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806E9790: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806E9794: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
    // 0x806E9798: jal         0x80048378
    // 0x806E979C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x806E979C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x806E97A0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806E97A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E97A8: bne         $v1, $zero, L_806E97C0
    if (ctx->r3 != 0) {
        // 0x806E97AC: nop
    
            goto L_806E97C0;
    }
    // 0x806E97AC: nop

    // 0x806E97B0: jal         0x80045A34
    // 0x806E97B4: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806E97B4: addiu       $a1, $zero, 0x5DC
    ctx->r5 = ADD32(0, 0X5DC);
    after_1:
    // 0x806E97B8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806E97BC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_806E97C0:
    // 0x806E97C0: bnel        $v1, $zero, L_806E97D8
    if (ctx->r3 != 0) {
        // 0x806E97C4: sh          $zero, 0x5D8($v1)
        MEM_H(0X5D8, ctx->r3) = 0;
            goto L_806E97D8;
    }
    goto skip_0;
    // 0x806E97C4: sh          $zero, 0x5D8($v1)
    MEM_H(0X5D8, ctx->r3) = 0;
    skip_0:
    // 0x806E97C8: jal         0x800447C8
    // 0x806E97CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x806E97CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806E97D0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806E97D4: sh          $zero, 0x5D8($v1)
    MEM_H(0X5D8, ctx->r3) = 0;
L_806E97D8:
    // 0x806E97D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806E97DC: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x806E97E0: sw          $t9, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r25;
    // 0x806E97E4: jal         0x806E9144
    // 0x806E97E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E9144(rdram, ctx);
        goto after_3;
    // 0x806E97E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E97EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E97F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E97F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E97F8: jr          $ra
    // 0x806E97FC: nop

    return;
    // 0x806E97FC: nop

;}
RECOMP_FUNC void func_806CECB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CECB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806CECBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806CECC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806CECC4: jal         0x806CEC44
    // 0x806CECC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806CEC44(rdram, ctx);
        goto after_0;
    // 0x806CECC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806CECCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806CECD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806CECD4: jal         0x806CED40
    // 0x806CECD8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_806CED40(rdram, ctx);
        goto after_1;
    // 0x806CECD8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x806CECDC: jal         0x806CEB14
    // 0x806CECE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806CEB14(rdram, ctx);
        goto after_2;
    // 0x806CECE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806CECE4: jal         0x8005FDC4
    // 0x806CECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x806CECE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806CECEC: sw          $zero, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = 0;
    // 0x806CECF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806CECF4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806CECF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806CECFC: jr          $ra
    // 0x806CED00: nop

    return;
    // 0x806CED00: nop

;}
RECOMP_FUNC void func_807C3568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3568: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x807C356C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x807C3570: lw          $v1, 0xF54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XF54);
    // 0x807C3574: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x807C3578: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x807C357C: and         $v0, $v1, $at
    ctx->r2 = ctx->r3 & ctx->r1;
    // 0x807C3580: srl         $v0, $v0, 14
    ctx->r2 = S32(U32(ctx->r2) >> 14);
    // 0x807C3584: beq         $v0, $zero, L_807C3590
    if (ctx->r2 == 0) {
        // 0x807C3588: lui         $at, 0xFFFE
        ctx->r1 = S32(0XFFFE << 16);
            goto L_807C3590;
    }
    // 0x807C3588: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x807C358C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_807C3590:
    // 0x807C3590: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x807C3594: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x807C3598: sll         $t7, $v0, 14
    ctx->r15 = S32(ctx->r2 << 14);
    // 0x807C359C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x807C35A0: jr          $ra
    // 0x807C35A4: sw          $t8, 0xF54($a0)
    MEM_W(0XF54, ctx->r4) = ctx->r24;
    return;
    // 0x807C35A4: sw          $t8, 0xF54($a0)
    MEM_W(0XF54, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8045B078(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045B078: jr          $ra
    // 0x8045B07C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    return;
    // 0x8045B07C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
;}
RECOMP_FUNC void func_807B4FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4FD0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x807B4FD4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B4FD8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807B4FDC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B4FE0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B4FE4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B4FE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B4FEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B4FF0: lw          $s2, 0x14($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X14);
    // 0x807B4FF4: lbu         $t6, 0xF5C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF5C);
    // 0x807B4FF8: lbu         $t7, 0xF5D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF5D);
    // 0x807B4FFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B5004: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x807B5008: jal         0x807B4A10
    // 0x807B500C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B500C: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
    after_0:
    // 0x807B5010: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2D94) << 16);
    // 0x807B5014: addiu       $a1, $a1, 0x7594
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2D94));
    // 0x807B5018: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B501C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B5020: jal         0x807B4900
    // 0x807B5024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B5024: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B5028: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B502C: jal         0x807B4A10
    // 0x807B5030: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_2;
    // 0x807B5030: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x807B5034: jal         0x807B4A74
    // 0x807B5038: nop

    func_807B4A74(rdram, ctx);
        goto after_3;
    // 0x807B5038: nop

    after_3:
    // 0x807B503C: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x807B5040: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B5044: jal         0x807B4B3C
    // 0x807B5048: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_4;
    // 0x807B5048: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x807B504C: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x807B5050: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
L_807B5054:
    // 0x807B5054: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B5058: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x807B505C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5060: jal         0x8005C27C
    // 0x807B5064: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B5064: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x807B5068: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B506C: slti        $at, $s0, 0x78
    ctx->r1 = SIGNED(ctx->r16) < 0X78 ? 1 : 0;
    // 0x807B5070: bne         $at, $zero, L_807B5054
    if (ctx->r1 != 0) {
        // 0x807B5074: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B5054;
    }
    // 0x807B5074: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B5078: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B507C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5080: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5084: jal         0x8005C27C
    // 0x807B5088: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B5088: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x807B508C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B5090: jal         0x807B4A10
    // 0x807B5094: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_807B4A10(rdram, ctx);
        goto after_7;
    // 0x807B5094: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_7:
    // 0x807B5098: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2DB4) << 16);
    // 0x807B509C: addiu       $a1, $a1, 0x75B4
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2DB4));
    // 0x807B50A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B50A4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x807B50A8: jal         0x807B4900
    // 0x807B50AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_8;
    // 0x807B50AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x807B50B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B50B4: jal         0x807B4A10
    // 0x807B50B8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_807B4A10(rdram, ctx);
        goto after_9;
    // 0x807B50B8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_9:
    // 0x807B50BC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x807B50C0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x807B50C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B50C8: sll         $s3, $s3, 2
    ctx->r19 = S32(ctx->r19 << 2);
    // 0x807B50CC: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x807B50D0: jal         0x800696D4
    // 0x807B50D4: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    func_800696D4(rdram, ctx);
        goto after_10;
    // 0x807B50D4: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    after_10:
    // 0x807B50D8: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x807B50DC: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
L_807B50E0:
    // 0x807B50E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B50E4: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x807B50E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B50EC: jal         0x8005C27C
    // 0x807B50F0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x807B50F0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_11:
    // 0x807B50F4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B50F8: slti        $at, $s0, 0x48
    ctx->r1 = SIGNED(ctx->r16) < 0X48 ? 1 : 0;
    // 0x807B50FC: bne         $at, $zero, L_807B50E0
    if (ctx->r1 != 0) {
        // 0x807B5100: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_807B50E0;
    }
    // 0x807B5100: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x807B5104: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x807B5108: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x807B510C: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x807B5110: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x807B5114: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x807B5118: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x807B511C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x807B5120: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x807B5124: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807B5128: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x807B512C: lhu         $a1, -0x7178($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7178);
    // 0x807B5130: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x807B5134: jal         0x807B4B3C
    // 0x807B5138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_12;
    // 0x807B5138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x807B513C: addiu       $s1, $sp, 0x44
    ctx->r17 = ADD32(ctx->r29, 0X44);
    // 0x807B5140: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
    // 0x807B5144: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
L_807B5148:
    // 0x807B5148: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B514C: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x807B5150: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5154: jal         0x8005C27C
    // 0x807B5158: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_13;
    // 0x807B5158: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_13:
    // 0x807B515C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5160: bne         $s0, $s3, L_807B5148
    if (ctx->r16 != ctx->r19) {
        // 0x807B5164: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B5148;
    }
    // 0x807B5164: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B5168: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B516C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5170: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5174: jal         0x8005C27C
    // 0x807B5178: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_14;
    // 0x807B5178: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_14:
    // 0x807B517C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B5180: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B5184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B5188: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B518C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B5190: jr          $ra
    // 0x807B5194: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x807B5194: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_80515A98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515A98: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE5C) << 16);
    // 0x80515A9C: lwc1        $f2, 0x62FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE5C));
    // 0x80515AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515AA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515AA8: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE60) << 16);
    // 0x80515AAC: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80515AB0: lwc1        $f4, 0x6300($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE60));
    // 0x80515AB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80515AB8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80515ABC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80515AC0: nop

    // 0x80515AC4: bc1fl       L_80515AE4
    if (!c1cs) {
        // 0x80515AC8: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80515AE4;
    }
    goto skip_0;
    // 0x80515AC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80515ACC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80515AD0: jal         0x80515DD4
    // 0x80515AD4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80515DD4(rdram, ctx);
        goto after_0;
    // 0x80515AD4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80515AD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80515ADC: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80515AE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80515AE4:
    // 0x80515AE4: jal         0x805158B4
    // 0x80515AE8: nop

    func_805158B4(rdram, ctx);
        goto after_1;
    // 0x80515AE8: nop

    after_1:
    // 0x80515AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515AF4: jr          $ra
    // 0x80515AF8: nop

    return;
    // 0x80515AF8: nop

;}
RECOMP_FUNC void func_804758A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804758A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804758A4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804758A8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804758AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804758B0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804758B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804758B8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804758BC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804758C0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804758C4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804758C8: jr          $ra
    // 0x804758CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804758CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8058472C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058472C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584730: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584734: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584738: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058473C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584740: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584744: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584748: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058474C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584750: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584754: jr          $ra
    // 0x80584758: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584758: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80050C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050C90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80050C94: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x80050C98: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80050C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050CA0: addiu       $v1, $v1, 0x1090
    ctx->r3 = ADD32(ctx->r3, 0X1090);
    // 0x80050CA4: addiu       $a0, $zero, 0x62E
    ctx->r4 = ADD32(0, 0X62E);
    // 0x80050CA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050CAC:
    // 0x80050CAC: lhu         $t6, 0x0($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X0);
    // 0x80050CB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80050CB4: bne         $a1, $t6, L_80050CC4
    if (ctx->r5 != ctx->r14) {
        // 0x80050CB8: nop
    
            goto L_80050CC4;
    }
    // 0x80050CB8: nop

    // 0x80050CBC: b           L_80050CE0
    // 0x80050CC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80050CE0;
    // 0x80050CC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80050CC4:
    // 0x80050CC4: bne         $v0, $a0, L_80050CAC
    if (ctx->r2 != ctx->r4) {
        // 0x80050CC8: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80050CAC;
    }
    // 0x80050CC8: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80050CCC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80050CD0: addiu       $a0, $a0, 0xA00
    ctx->r4 = ADD32(ctx->r4, 0XA00);
    // 0x80050CD4: jal         0x80071380
    // 0x80050CD8: addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80050CD8: addiu       $a1, $zero, 0x24E
    ctx->r5 = ADD32(0, 0X24E);
    after_0:
    // 0x80050CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80050CE0:
    // 0x80050CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80050CE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050CE8: jr          $ra
    // 0x80050CEC: nop

    return;
    // 0x80050CEC: nop

;}
RECOMP_FUNC void func_805C8D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8D30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805C8D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8D38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8D3C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C8D40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8D44: lw          $v0, 0x1C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1C);
    // 0x805C8D48: beq         $v0, $zero, L_805C8D54
    if (ctx->r2 == 0) {
        // 0x805C8D4C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805C8D54;
    }
    // 0x805C8D4C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805C8D50: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
L_805C8D54:
    // 0x805C8D54: lw          $a0, 0x18($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X18);
    // 0x805C8D58: lui         $t8, 0x805D
    ctx->r24 = S32(RELOC_HI16(447, 0X3870) << 16);
    // 0x805C8D5C: addiu       $t8, $t8, -0x62A0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(447, 0X3870));
    // 0x805C8D60: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x805C8D64: sll         $t7, $a0, 1
    ctx->r15 = S32(ctx->r4 << 1);
    // 0x805C8D68: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x805C8D6C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x805C8D70: lw          $t3, 0x1C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X1C);
    // 0x805C8D74: sh          $t9, 0x168($a3)
    MEM_H(0X168, ctx->r7) = ctx->r25;
    // 0x805C8D78: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x805C8D7C: sh          $t0, 0x16A($a3)
    MEM_H(0X16A, ctx->r7) = ctx->r8;
    // 0x805C8D80: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x805C8D84: sh          $t1, 0x16C($a3)
    MEM_H(0X16C, ctx->r7) = ctx->r9;
    // 0x805C8D88: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x805C8D8C: bne         $t3, $zero, L_805C8E04
    if (ctx->r11 != 0) {
        // 0x805C8D90: sh          $t2, 0x16E($a3)
        MEM_H(0X16E, ctx->r7) = ctx->r10;
            goto L_805C8E04;
    }
    // 0x805C8D90: sh          $t2, 0x16E($a3)
    MEM_H(0X16E, ctx->r7) = ctx->r10;
    // 0x805C8D94: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x805C8D98: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C8D9C: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x805C8DA0: bne         $v0, $at, L_805C8DBC
    if (ctx->r2 != ctx->r1) {
        // 0x805C8DA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805C8DBC;
    }
    // 0x805C8DA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8DA8: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x805C8DAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x805C8DB0: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x805C8DB4: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x805C8DB8: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
L_805C8DBC:
    // 0x805C8DBC: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x805C8DC0: slti        $at, $t7, 0x6
    ctx->r1 = SIGNED(ctx->r15) < 0X6 ? 1 : 0;
    // 0x805C8DC4: bne         $at, $zero, L_805C8DFC
    if (ctx->r1 != 0) {
        // 0x805C8DC8: sw          $t7, 0x18($a3)
        MEM_W(0X18, ctx->r7) = ctx->r15;
            goto L_805C8DFC;
    }
    // 0x805C8DC8: sw          $t7, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r15;
    // 0x805C8DCC: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    // 0x805C8DD0: sw          $t9, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r25;
    // 0x805C8DD4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8DD8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C8DDC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x805C8DE0: jal         0x805C74C8
    // 0x805C8DE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_0;
    // 0x805C8DE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x805C8DE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8DF0: jal         0x805C9D10
    // 0x805C8DF4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_805C9D10(rdram, ctx);
        goto after_1;
    // 0x805C8DF4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x805C8DF8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_805C8DFC:
    // 0x805C8DFC: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x805C8E00: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_805C8E04:
    // 0x805C8E04: jal         0x805C6CA4
    // 0x805C8E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_2;
    // 0x805C8E08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805C8E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C8E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805C8E18: jr          $ra
    // 0x805C8E1C: nop

    return;
    // 0x805C8E1C: nop

;}
RECOMP_FUNC void func_800010C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800010C4: sra         $t6, $a2, 4
    ctx->r14 = S32(SIGNED(ctx->r6) >> 4);
    // 0x800010C8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800010CC: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800010D0: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x800010D4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800010D8: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x800010DC: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800010E0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800010E4: jr          $ra
    // 0x800010E8: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    return;
    // 0x800010E8: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void func_80069E18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069E18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069E20: lw          $a1, 0x20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X20);
    // 0x80069E24: beql        $a1, $zero, L_80069E40
    if (ctx->r5 == 0) {
        // 0x80069E28: lw          $a1, 0x28($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X28);
            goto L_80069E40;
    }
    goto skip_0;
    // 0x80069E28: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    skip_0:
    // 0x80069E2C: jal         0x80064E84
    // 0x80069E30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x80069E30: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80069E34: b           L_80069E8C
    // 0x80069E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E8C;
    // 0x80069E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069E3C: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
L_80069E40:
    // 0x80069E40: beql        $a1, $zero, L_80069E5C
    if (ctx->r5 == 0) {
        // 0x80069E44: lw          $a1, 0x38($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X38);
            goto L_80069E5C;
    }
    goto skip_1;
    // 0x80069E44: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
    skip_1:
    // 0x80069E48: jal         0x80064E84
    // 0x80069E4C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x80069E4C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80069E50: b           L_80069E8C
    // 0x80069E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E8C;
    // 0x80069E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069E58: lw          $a1, 0x38($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X38);
L_80069E5C:
    // 0x80069E5C: beql        $a1, $zero, L_80069E78
    if (ctx->r5 == 0) {
        // 0x80069E60: lw          $a1, 0x30($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X30);
            goto L_80069E78;
    }
    goto skip_2;
    // 0x80069E60: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
    skip_2:
    // 0x80069E64: jal         0x80064E84
    // 0x80069E68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x80069E68: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80069E6C: b           L_80069E8C
    // 0x80069E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069E8C;
    // 0x80069E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80069E74: lw          $a1, 0x30($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X30);
L_80069E78:
    // 0x80069E78: beql        $a1, $zero, L_80069E8C
    if (ctx->r5 == 0) {
        // 0x80069E7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069E8C;
    }
    goto skip_3;
    // 0x80069E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80069E80: jal         0x80064E84
    // 0x80069E84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x80069E84: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_3:
    // 0x80069E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069E8C:
    // 0x80069E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069E90: jr          $ra
    // 0x80069E94: nop

    return;
    // 0x80069E94: nop

;}
RECOMP_FUNC void func_805849FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805849FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584A00: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584A04: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584A08: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584A0C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584A10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584A14: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584A18: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584A1C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584A20: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584A24: jr          $ra
    // 0x80584A28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584A28: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8000A82C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A82C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A834: jal         0x80006C40
    // 0x8000A838: nop

    func_80006C40(rdram, ctx);
        goto after_0;
    // 0x8000A838: nop

    after_0:
    // 0x8000A83C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A844: jr          $ra
    // 0x8000A848: nop

    return;
    // 0x8000A848: nop

;}
RECOMP_FUNC void func_80423E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423E24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423E28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423E2C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80423E30: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80423E34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80423E38: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X324C) << 16);
    // 0x80423E3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80423E40: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80423E44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80423E48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80423E4C: lw          $t8, 0x5C4C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X324C));
    // 0x80423E50: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80423E54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80423E58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80423E5C: jal         0x80048490
    // 0x80423E60: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80423E60: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80423E64: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80423E68: jal         0x80048378
    // 0x80423E6C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80423E6C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80423E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423E78: jr          $ra
    // 0x80423E7C: nop

    return;
    // 0x80423E7C: nop

;}
