#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8005DB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005DB78: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005DB7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005DB80: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005DB84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005DB88: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8005DB8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005DB90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005DB94: addiu       $s2, $zero, 0x12C
    ctx->r18 = ADD32(0, 0X12C);
    // 0x8005DB98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8005DB9C:
    // 0x8005DB9C: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    // 0x8005DBA0: jal         0x80077E88
    // 0x8005DBA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80077E88(rdram, ctx);
        goto after_0;
    // 0x8005DBA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8005DBA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005DBAC: bnel        $s0, $s2, L_8005DB9C
    if (ctx->r16 != ctx->r18) {
        // 0x8005DBB0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8005DB9C;
    }
    goto skip_0;
    // 0x8005DBB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8005DBB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005DBB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005DBBC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005DBC0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005DBC4: jr          $ra
    // 0x8005DBC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005DBC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80019128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001912C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019130: jal         0x80019AC4
    // 0x80019134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019134: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019138: beq         $v0, $zero, L_8001914C
    if (ctx->r2 == 0) {
        // 0x8001913C: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8001914C;
    }
    // 0x8001913C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80019140: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80019144: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80019148: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
L_8001914C:
    // 0x8001914C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019154: jr          $ra
    // 0x80019158: nop

    return;
    // 0x80019158: nop

    // 0x8001915C: nop

;}
RECOMP_FUNC void func_804726F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804726F4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804726F8: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x804726FC: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80472700: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80472704: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80472708: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8047270C: mul.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80472710: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80472714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80472718: mul.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8047271C: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80472720: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80472724: swc1        $f12, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f12.u32l;
    // 0x80472728: swc1        $f2, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f2.u32l;
    // 0x8047272C: swc1        $f14, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f14.u32l;
    // 0x80472730: jr          $ra
    // 0x80472734: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    return;
    // 0x80472734: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
;}
RECOMP_FUNC void func_8045D680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045D680: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8045D684: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8045D688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8045D68C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8045D690: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8045D694: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8045D698: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8045D69C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8045D6A0: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(107, 0X2280) << 16);
    // 0x8045D6A4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8045D6A8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045D6AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8045D6B0: lw          $t1, -0x24F0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(107, 0X2280));
    // 0x8045D6B4: jr          $ra
    // 0x8045D6B8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8045D6B8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8045D6BC: nop

;}
RECOMP_FUNC void func_8002C064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C064: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C070: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002C074: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8002C078: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8002C07C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C080: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C084: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C088: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002C08C: lbu         $t6, 0x76($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X76);
    // 0x8002C090: beql        $t6, $zero, L_8002C0B8
    if (ctx->r14 == 0) {
        // 0x8002C094: lbu         $t7, 0x77($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X77);
            goto L_8002C0B8;
    }
    goto skip_0;
    // 0x8002C094: lbu         $t7, 0x77($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X77);
    skip_0:
    // 0x8002C098: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8002C09C: jal         0x8005FA94
    // 0x8002C0A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005FA94(rdram, ctx);
        goto after_0;
    // 0x8002C0A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C0A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C0A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C0AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8002C0B4: lbu         $t7, 0x77($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X77);
L_8002C0B8:
    // 0x8002C0B8: beql        $t7, $zero, L_8002C0D4
    if (ctx->r15 == 0) {
        // 0x8002C0BC: swc1        $f0, 0x50($a0)
        MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
            goto L_8002C0D4;
    }
    goto skip_1;
    // 0x8002C0BC: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    skip_1:
    // 0x8002C0C0: jal         0x8005FB2C
    // 0x8002C0C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005FB2C(rdram, ctx);
        goto after_1;
    // 0x8002C0C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8002C0C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C0CC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002C0D0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
L_8002C0D4:
    // 0x8002C0D4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002C0D8: swc1        $f0, 0x54($t8)
    MEM_W(0X54, ctx->r24) = ctx->f0.u32l;
    // 0x8002C0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C0E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C0E4: jr          $ra
    // 0x8002C0E8: nop

    return;
    // 0x8002C0E8: nop

;}
RECOMP_FUNC void func_8044185C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044185C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80441860: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80441864: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80441868: jal         0x8004700C
    // 0x8044186C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8044186C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80441870: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80441874: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80441878: beq         $v0, $zero, L_80441938
    if (ctx->r2 == 0) {
        // 0x8044187C: sw          $t6, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r14;
            goto L_80441938;
    }
    // 0x8044187C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80441880: jal         0x8043F33C
    // 0x80441884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F33C(rdram, ctx);
        goto after_1;
    // 0x80441884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80441888: jal         0x8043FDF0
    // 0x8044188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_2;
    // 0x8044188C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80441890: jal         0x8043F150
    // 0x80441894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_3;
    // 0x80441894: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80441898: jal         0x8044045C
    // 0x8044189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_4;
    // 0x8044189C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804418A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804418A4: jal         0x8043EF80
    // 0x804418A8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_8043EF80(rdram, ctx);
        goto after_5;
    // 0x804418A8: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_5:
    // 0x804418AC: jal         0x8043F360
    // 0x804418B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F360(rdram, ctx);
        goto after_6;
    // 0x804418B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804418B4: beq         $v0, $zero, L_80441930
    if (ctx->r2 == 0) {
        // 0x804418B8: nop
    
            goto L_80441930;
    }
    // 0x804418B8: nop

    // 0x804418BC: jal         0x80440950
    // 0x804418C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_7;
    // 0x804418C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804418C4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804418C8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x804418CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804418D0: lwc1        $f4, 0x1C84($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C84);
    // 0x804418D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804418D8: nop

    // 0x804418DC: bc1f        L_804418F4
    if (!c1cs) {
        // 0x804418E0: nop
    
            goto L_804418F4;
    }
    // 0x804418E0: nop

    // 0x804418E4: jal         0x8043F814
    // 0x804418E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F814(rdram, ctx);
        goto after_8;
    // 0x804418E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x804418EC: b           L_8044193C
    // 0x804418F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8044193C;
    // 0x804418F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804418F4:
    // 0x804418F4: jal         0x8043FB94
    // 0x804418F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FB94(rdram, ctx);
        goto after_9;
    // 0x804418F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x804418FC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80441900: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80441904: lwc1        $f8, 0x1C84($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C84);
    // 0x80441908: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8044190C: swc1        $f16, 0x1C84($v0)
    MEM_W(0X1C84, ctx->r2) = ctx->f16.u32l;
    // 0x80441910: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80441914: lwc1        $f18, 0x1C84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C84);
    // 0x80441918: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8044191C: lwc1        $f4, 0x40($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X40);
    // 0x80441920: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80441924: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80441928: b           L_80441938
    // 0x8044192C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_80441938;
    // 0x8044192C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_80441930:
    // 0x80441930: jal         0x8043F93C
    // 0x80441934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_10;
    // 0x80441934: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_80441938:
    // 0x80441938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8044193C:
    // 0x8044193C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80441940: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80441944: jr          $ra
    // 0x80441948: nop

    return;
    // 0x80441948: nop

;}
RECOMP_FUNC void func_804C0A60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C0A60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C0A64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C0A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C0A6C: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(200, 0X580) << 16);
    // 0x804C0A70: lui         $a1, 0x804C
    ctx->r5 = S32(RELOC_HI16(200, 0X590) << 16);
    // 0x804C0A74: addiu       $a1, $a1, 0xFF0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(200, 0X590));
    // 0x804C0A78: addiu       $a0, $a0, 0xFE0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(200, 0X580));
    // 0x804C0A7C: jal         0x8004667C
    // 0x804C0A80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804C0A80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x804C0A84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804C0A88: lui         $a2, 0x804C
    ctx->r6 = S32(RELOC_HI16(200, 0X374) << 16);
    // 0x804C0A8C: addiu       $a2, $a2, 0xDD4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(200, 0X374));
    // 0x804C0A90: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804C0A94: jal         0x80057B28
    // 0x804C0A98: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804C0A98: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
    // 0x804C0A9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C0AA0: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(200, 0X50) << 16);
    // 0x804C0AA4: addiu       $v0, $v0, 0xAB0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(200, 0X50));
    // 0x804C0AA8: jr          $ra
    // 0x804C0AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804C0AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8066A670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066A670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066A674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066A678: jal         0x80669E38
    // 0x8066A67C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80669E38(rdram, ctx);
        goto after_0;
    // 0x8066A67C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066A680: jal         0x80045BD8
    // 0x8066A684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8066A684: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8066A688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066A68C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066A690: jr          $ra
    // 0x8066A694: nop

    return;
    // 0x8066A694: nop

;}
RECOMP_FUNC void func_804BA360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA360: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804BA364: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x804BA368: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x804BA36C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804BA370: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x804BA374: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x804BA378: jr          $ra
    // 0x804BA37C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x804BA37C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_805199F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805199F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805199F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805199F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805199FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80519A00: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x80519A04: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x80519A08: jal         0x80065ABC
    // 0x80519A0C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x80519A0C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x80519A10: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80519A14: jal         0x80519124
    // 0x80519A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519124(rdram, ctx);
        goto after_1;
    // 0x80519A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80519A1C: jal         0x80519594
    // 0x80519A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519594(rdram, ctx);
        goto after_2;
    // 0x80519A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80519A24: jal         0x805198F8
    // 0x80519A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805198F8(rdram, ctx);
        goto after_3;
    // 0x80519A28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80519A2C: jal         0x80519358
    // 0x80519A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519358(rdram, ctx);
        goto after_4;
    // 0x80519A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80519A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80519A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80519A3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80519A40: jr          $ra
    // 0x80519A44: nop

    return;
    // 0x80519A44: nop

;}
RECOMP_FUNC void func_80429EB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429EB4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80429EB8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80429EBC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80429EC0: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
    // 0x80429EC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80429EC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80429ECC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80429ED0: lui         $v1, 0x8043
    ctx->r3 = S32(RELOC_HI16(47, 0X840) << 16);
    // 0x80429ED4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80429ED8: addiu       $v1, $v1, -0x59F0
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(47, 0X840));
    // 0x80429EDC: sw          $s2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r18;
    // 0x80429EE0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80429EE4: jal         0x80064D1C
    // 0x80429EE8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80429EE8: addiu       $a0, $zero, 0x54
    ctx->r4 = ADD32(0, 0X54);
    after_0:
    // 0x80429EEC: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x80429EF0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80429EF4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x80429EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80429EFC: beq         $t6, $zero, L_80429F3C
    if (ctx->r14 == 0) {
        // 0x80429F00: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80429F3C;
    }
    // 0x80429F00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80429F04: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
L_80429F08:
    // 0x80429F08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80429F0C: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80429F10: sh          $t7, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r15;
    // 0x80429F14: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x80429F18: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x80429F1C: sh          $t8, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r24;
    // 0x80429F20: lh          $t9, -0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, -0X2);
    // 0x80429F24: sh          $t9, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r25;
    // 0x80429F28: lw          $t0, 0x4($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4);
    // 0x80429F2C: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80429F30: bnel        $at, $zero, L_80429F08
    if (ctx->r1 != 0) {
        // 0x80429F34: lh          $t7, 0x0($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X0);
            goto L_80429F08;
    }
    goto skip_0;
    // 0x80429F34: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    skip_0:
    // 0x80429F38: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80429F3C:
    // 0x80429F3C: lui         $t1, 0x8043
    ctx->r9 = S32(RELOC_HI16(47, 0X894) << 16);
    // 0x80429F40: addiu       $t1, $t1, -0x599C
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(47, 0X894));
    // 0x80429F44: sw          $s2, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r18;
    // 0x80429F48: sw          $t1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r9;
    // 0x80429F4C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80429F50: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
L_80429F54:
    // 0x80429F54: jal         0x80064D1C
    // 0x80429F58: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x80429F58: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    after_1:
    // 0x80429F5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80429F60: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80429F64: bne         $s0, $s2, L_80429F54
    if (ctx->r16 != ctx->r18) {
        // 0x80429F68: sw          $v0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r2;
            goto L_80429F54;
    }
    // 0x80429F68: sw          $v0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r2;
    // 0x80429F6C: sh          $zero, 0x1C($s3)
    MEM_H(0X1C, ctx->r19) = 0;
    // 0x80429F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80429F74: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80429F78: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80429F7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80429F80: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80429F84: jr          $ra
    // 0x80429F88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80429F88: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8078D110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D110: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8078D114: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(802, 0XC90) << 16);
    // 0x8078D118: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8078D11C: addiu       $t6, $t6, -0x2260
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(802, 0XC90));
    // 0x8078D120: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8078D124: sw          $t6, 0xEB0($v1)
    MEM_W(0XEB0, ctx->r3) = ctx->r14;
    // 0x8078D128: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(802, 0X710) << 16);
    // 0x8078D12C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8078D130: jr          $ra
    // 0x8078D134: addiu       $v0, $v0, -0x27E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(802, 0X710));
    return;
    // 0x8078D134: addiu       $v0, $v0, -0x27E0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(802, 0X710));
;}
RECOMP_FUNC void func_8059FF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FF74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8059FF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8059FF7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8059FF80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8059FF84: jal         0x80047090
    // 0x8059FF88: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8059FF88: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    after_0:
    // 0x8059FF8C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8059FF90: lhu         $a0, 0x26($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X26);
    // 0x8059FF94: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x8059FF98: lw          $a3, 0x8C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X8C);
    // 0x8059FF9C: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x8059FFA0: lw          $a1, 0x84($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X84);
    // 0x8059FFA4: jal         0x8004613C
    // 0x8059FFA8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8059FFA8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    after_1:
    // 0x8059FFAC: beq         $v0, $zero, L_8059FFCC
    if (ctx->r2 == 0) {
        // 0x8059FFB0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8059FFCC;
    }
    // 0x8059FFB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8059FFB4: lhu         $t7, 0x1E($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1E);
    // 0x8059FFB8: lhu         $t9, 0xE($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XE);
    // 0x8059FFBC: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8059FFC0: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x8059FFC4: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x8059FFC8: sh          $t1, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r9;
L_8059FFCC:
    // 0x8059FFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8059FFD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8059FFD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8059FFD8: jr          $ra
    // 0x8059FFDC: nop

    return;
    // 0x8059FFDC: nop

;}
RECOMP_FUNC void func_8002FABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FAC4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002FAC8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FACC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FAD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002FAD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002FAD8: jal         0x8002F678
    // 0x8002FADC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FADC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FAE0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FAE4: beq         $v0, $zero, L_8002FB00
    if (ctx->r2 == 0) {
        // 0x8002FAE8: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8002FB00;
    }
    // 0x8002FAE8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8002FAEC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002FAF0: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FAF4: addiu       $t6, $t6, -0x2488
    ctx->r14 = ADD32(ctx->r14, -0X2488);
    // 0x8002FAF8: swc1        $f4, 0xC8($a2)
    MEM_W(0XC8, ctx->r6) = ctx->f4.u32l;
    // 0x8002FAFC: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FB00:
    // 0x8002FB00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FB04: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FB08: jr          $ra
    // 0x8002FB0C: nop

    return;
    // 0x8002FB0C: nop

;}
RECOMP_FUNC void func_804622C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804622C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804622C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804622CC: jal         0x80064D1C
    // 0x804622D0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x804622D0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x804622D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804622D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804622DC: jr          $ra
    // 0x804622E0: nop

    return;
    // 0x804622E0: nop

;}
RECOMP_FUNC void func_804A1A1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A1A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A1A24: jal         0x804A1820
    // 0x804A1A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A1A28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A1A2C: bnel        $v0, $zero, L_804A1A94
    if (ctx->r2 != 0) {
        // 0x804A1A30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A1A94;
    }
    goto skip_0;
    // 0x804A1A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804A1A34: jal         0x804A2910
    // 0x804A1A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A1A38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804A1A3C: beql        $v0, $zero, L_804A1A94
    if (ctx->r2 == 0) {
        // 0x804A1A40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804A1A94;
    }
    goto skip_1;
    // 0x804A1A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804A1A44: jal         0x800653D8
    // 0x804A1A48: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x804A1A48: nop

    after_2:
    // 0x804A1A4C: andi        $t6, $v0, 0x7
    ctx->r14 = ctx->r2 & 0X7;
    // 0x804A1A50: beq         $t6, $zero, L_804A1A6C
    if (ctx->r14 == 0) {
        // 0x804A1A54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A1A6C;
    }
    // 0x804A1A54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1A58: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A1A5C: jal         0x804A27A0
    // 0x804A1A60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_3;
    // 0x804A1A60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x804A1A64: b           L_804A1A94
    // 0x804A1A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804A1A94;
    // 0x804A1A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A1A6C:
    // 0x804A1A6C: jal         0x800653D8
    // 0x804A1A70: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x804A1A70: nop

    after_4:
    // 0x804A1A74: andi        $a2, $v0, 0x4
    ctx->r6 = ctx->r2 & 0X4;
    // 0x804A1A78: sra         $a2, $a2, 2
    ctx->r6 = S32(SIGNED(ctx->r6) >> 2);
    // 0x804A1A7C: addiu       $a2, $a2, 0x9
    ctx->r6 = ADD32(ctx->r6, 0X9);
    // 0x804A1A80: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804A1A84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A1A88: jal         0x804A27A0
    // 0x804A1A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804A27A0(rdram, ctx);
        goto after_5;
    // 0x804A1A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804A1A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804A1A94:
    // 0x804A1A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A1A98: jr          $ra
    // 0x804A1A9C: nop

    return;
    // 0x804A1A9C: nop

;}
RECOMP_FUNC void func_80434490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434490: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80434494: lui         $t2, 0xF700
    ctx->r10 = S32(0XF700 << 16);
    // 0x80434498: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8043449C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x804344A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804344A4: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x804344A8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x804344AC: lw          $a3, 0x0($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X0);
    // 0x804344B0: lui         $t4, 0xB800
    ctx->r12 = S32(0XB800 << 16);
    // 0x804344B4: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x804344B8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x804344BC: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x804344C0: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x804344C4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x804344C8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x804344CC: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x804344D0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x804344D4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x804344D8: jr          $ra
    // 0x804344DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    return;
    // 0x804344DC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
;}
RECOMP_FUNC void func_804731A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804731A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804731A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804731A8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x804731AC: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(161, 0XCE0) << 16);
    // 0x804731B0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804731B4: addiu       $t6, $t6, 0x3E70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(161, 0XCE0));
    // 0x804731B8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x804731BC: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804731C0: lui         $t1, 0x8047
    ctx->r9 = S32(RELOC_HI16(161, 0X1C0) << 16);
    // 0x804731C4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x804731C8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x804731CC: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x804731D0: addiu       $t1, $t1, 0x3350
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(161, 0X1C0));
    // 0x804731D4: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x804731D8: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x804731DC: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x804731E0: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    // 0x804731E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804731E8: jal         0x80045A34
    // 0x804731EC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804731EC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x804731F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804731F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804731F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804731FC: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80473200: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80473204: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x80473208: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8047320C: sh          $zero, 0x2($t2)
    MEM_H(0X2, ctx->r10) = 0;
    // 0x80473210: lw          $t3, 0x1F4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1F4);
    // 0x80473214: jal         0x80473DF8
    // 0x80473218: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    func_80473DF8(rdram, ctx);
        goto after_1;
    // 0x80473218: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    after_1:
    // 0x8047321C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80473220: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80473224: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80473228: sb          $t4, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r12;
    // 0x8047322C: jr          $ra
    // 0x80473230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80473230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805221C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221C0: jr          $ra
    // 0x805221C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805221C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804CAB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CAB80: jr          $ra
    // 0x804CAB84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804CAB84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806D08A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D08A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D08AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D08B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D08B4: jal         0x806D086C
    // 0x806D08B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806D086C(rdram, ctx);
        goto after_0;
    // 0x806D08B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806D08BC: bne         $v0, $zero, L_806D08D4
    if (ctx->r2 != 0) {
        // 0x806D08C0: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_806D08D4;
    }
    // 0x806D08C0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806D08C4: jal         0x800445A4
    // 0x806D08C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D08C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D08CC: b           L_806D092C
    // 0x806D08D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D092C;
    // 0x806D08D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D08D4:
    // 0x806D08D4: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806D08D8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806D08DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806D08E0: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X19B4) << 16);
    // 0x806D08E4: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806D08E8: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x806D08EC: addiu       $t8, $t8, 0x1154
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(607, 0X19B4));
    // 0x806D08F0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806D08F4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806D08F8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806D08FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D0900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D0904: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806D0908: jal         0x806D093C
    // 0x806D090C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806D093C(rdram, ctx);
        goto after_2;
    // 0x806D090C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806D0910: jal         0x806D070C
    // 0x806D0914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D070C(rdram, ctx);
        goto after_3;
    // 0x806D0914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806D0918: bnel        $v0, $zero, L_806D092C
    if (ctx->r2 != 0) {
        // 0x806D091C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D092C;
    }
    goto skip_0;
    // 0x806D091C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806D0920: jal         0x800445A4
    // 0x806D0924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x806D0924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806D0928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D092C:
    // 0x806D092C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D0930: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D0934: jr          $ra
    // 0x806D0938: nop

    return;
    // 0x806D0938: nop

;}
RECOMP_FUNC void func_80742D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742D64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742D68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742D70: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742D74: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742D78: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742D7C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742D80: lw          $v1, 0x6E58($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E58);
    // 0x80742D84: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742D88: beql        $v1, $zero, L_80742DA4
    if (ctx->r3 == 0) {
        // 0x80742D8C: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742DA4;
    }
    goto skip_0;
    // 0x80742D8C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742D90: jal         0x80742974
    // 0x80742D94: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    func_80742974(rdram, ctx);
        goto after_0;
    // 0x80742D94: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    after_0:
    // 0x80742D98: b           L_80742DC8
    // 0x80742D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742DC8;
    // 0x80742D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742DA0: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742DA4:
    // 0x80742DA4: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742DA8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742DAC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742DB0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742DB4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742DB8: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742DBC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742DC0: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742DC8:
    // 0x80742DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742DCC: jr          $ra
    // 0x80742DD0: nop

    return;
    // 0x80742DD0: nop

;}
RECOMP_FUNC void func_8005F7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F7D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005F7DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005F7E0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8005F7E4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8005F7E8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005F7EC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005F7F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F7F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F7F8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8005F7FC: lui         $s0, 0x8010
    ctx->r16 = S32(0X8010 << 16);
    // 0x8005F800: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8005F804: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8005F808: addiu       $s0, $s0, -0x54D8
    ctx->r16 = ADD32(ctx->r16, -0X54D8);
    // 0x8005F80C: lw          $s1, 0x10($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X10);
    // 0x8005F810: blez        $t6, L_8005F868
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8005F814: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8005F868;
    }
    // 0x8005F814: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005F818: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8005F81C: addiu       $s4, $s4, 0x64C0
    ctx->r20 = ADD32(ctx->r20, 0X64C0);
L_8005F820:
    // 0x8005F820: jal         0x8005F700
    // 0x8005F824: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_8005F700(rdram, ctx);
        goto after_0;
    // 0x8005F824: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x8005F828: beq         $v0, $zero, L_8005F848
    if (ctx->r2 == 0) {
        // 0x8005F82C: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8005F848;
    }
    // 0x8005F82C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8005F830: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8005F834: lbu         $t8, 0x164($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X164);
    // 0x8005F838: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x8005F83C: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x8005F840: b           L_8005F84C
    // 0x8005F844: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
        goto L_8005F84C;
    // 0x8005F844: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
L_8005F848:
    // 0x8005F848: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8005F84C:
    // 0x8005F84C: lh          $t1, 0x6($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X6);
    // 0x8005F850: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8005F854: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005F858: slt         $at, $s2, $t1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005F85C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8005F860: bne         $at, $zero, L_8005F820
    if (ctx->r1 != 0) {
        // 0x8005F864: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8005F820;
    }
    // 0x8005F864: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8005F868:
    // 0x8005F868: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8005F86C: addiu       $t2, $t2, -0x54D8
    ctx->r10 = ADD32(ctx->r10, -0X54D8);
    // 0x8005F870: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005F874: sw          $t2, -0x7AEC($at)
    MEM_W(-0X7AEC, ctx->r1) = ctx->r10;
    // 0x8005F878: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005F87C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8005F880: sw          $s3, -0x7AE8($at)
    MEM_W(-0X7AE8, ctx->r1) = ctx->r19;
    // 0x8005F884: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005F888: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005F88C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005F890: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005F894: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8005F898: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8005F89C: jr          $ra
    // 0x8005F8A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005F8A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804C2E14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C2E14: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x804C2E18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C2E1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C2E20: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x804C2E24: jal         0x8004921C
    // 0x804C2E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804C2E28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804C2E2C: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x804C2E30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C2E34: jal         0x8004921C
    // 0x804C2E38: sh          $v0, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r2;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804C2E38: sh          $v0, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r2;
    after_1:
    // 0x804C2E3C: lh          $t4, 0x8E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X8E);
    // 0x804C2E40: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x804C2E44: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x804C2E48: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x804C2E4C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C2E50: lbu         $t9, 0x145($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X145);
    // 0x804C2E54: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x804C2E58: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C2E5C: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
    // 0x804C2E60: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804C2E64: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x804C2E68: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x804C2E6C: mflo        $t8
    ctx->r24 = lo;
    // 0x804C2E70: nop

    // 0x804C2E74: nop

    // 0x804C2E78: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C2E7C: lw          $t8, 0x80($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X80);
    // 0x804C2E80: lw          $t9, 0x280($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X280);
    // 0x804C2E84: xori        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 ^ 0X1;
    // 0x804C2E88: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804C2E8C: mflo        $t6
    ctx->r14 = lo;
    // 0x804C2E90: addu        $a1, $t8, $t6
    ctx->r5 = ADD32(ctx->r24, ctx->r14);
    // 0x804C2E94: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x804C2E98: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804C2E9C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x804C2EA0: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x804C2EA4: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x804C2EA8: addu        $v1, $s0, $t6
    ctx->r3 = ADD32(ctx->r16, ctx->r14);
    // 0x804C2EAC: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x804C2EB0: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804C2EB4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x804C2EB8: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x804C2EBC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x804C2EC0: mflo        $a2
    ctx->r6 = lo;
    // 0x804C2EC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x804C2EC8: sra         $a2, $a2, 1
    ctx->r6 = S32(SIGNED(ctx->r6) >> 1);
    // 0x804C2ECC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x804C2ED0: slti        $at, $a2, 0x7FF
    ctx->r1 = SIGNED(ctx->r6) < 0X7FF ? 1 : 0;
    // 0x804C2ED4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x804C2ED8: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x804C2EDC: addiu       $t5, $v1, 0x28
    ctx->r13 = ADD32(ctx->r3, 0X28);
    // 0x804C2EE0: lui         $t6, 0x700
    ctx->r14 = S32(0X700 << 16);
    // 0x804C2EE4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x804C2EE8: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x804C2EEC: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x804C2EF0: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x804C2EF4: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x804C2EF8: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x804C2EFC: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x804C2F00: beq         $at, $zero, L_804C2F10
    if (ctx->r1 == 0) {
        // 0x804C2F04: sw          $a1, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r5;
            goto L_804C2F10;
    }
    // 0x804C2F04: sw          $a1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r5;
    // 0x804C2F08: b           L_804C2F10
    // 0x804C2F0C: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
        goto L_804C2F10;
    // 0x804C2F0C: or          $ra, $a2, $zero
    ctx->r31 = ctx->r6 | 0;
L_804C2F10:
    // 0x804C2F10: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x804C2F14: bgez        $a0, L_804C2F20
    if (SIGNED(ctx->r4) >= 0) {
        // 0x804C2F18: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_804C2F20;
    }
    // 0x804C2F18: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x804C2F1C: addiu       $at, $a0, 0x7
    ctx->r1 = ADD32(ctx->r4, 0X7);
L_804C2F20:
    // 0x804C2F20: sra         $a0, $at, 3
    ctx->r4 = S32(SIGNED(ctx->r1) >> 3);
    // 0x804C2F24: bgtz        $a0, L_804C2F38
    if (SIGNED(ctx->r4) > 0) {
        // 0x804C2F28: addiu       $a3, $t5, 0x8
        ctx->r7 = ADD32(ctx->r13, 0X8);
            goto L_804C2F38;
    }
    // 0x804C2F28: addiu       $a3, $t5, 0x8
    ctx->r7 = ADD32(ctx->r13, 0X8);
    // 0x804C2F2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804C2F30: b           L_804C2F3C
    // 0x804C2F34: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_804C2F3C;
    // 0x804C2F34: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_804C2F38:
    // 0x804C2F38: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
L_804C2F3C:
    // 0x804C2F3C: bgtz        $a0, L_804C2F4C
    if (SIGNED(ctx->r4) > 0) {
        // 0x804C2F40: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_804C2F4C;
    }
    // 0x804C2F40: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x804C2F44: b           L_804C2F50
    // 0x804C2F48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_804C2F50;
    // 0x804C2F48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_804C2F4C:
    // 0x804C2F4C: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
L_804C2F50:
    // 0x804C2F50: addiu       $t9, $t6, 0x7FF
    ctx->r25 = ADD32(ctx->r14, 0X7FF);
    // 0x804C2F54: div         $zero, $t9, $t3
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r11)));
    // 0x804C2F58: bne         $t3, $zero, L_804C2F64
    if (ctx->r11 != 0) {
        // 0x804C2F5C: nop
    
            goto L_804C2F64;
    }
    // 0x804C2F5C: nop

    // 0x804C2F60: break       7
    do_break(2152476512);
L_804C2F64:
    // 0x804C2F64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x804C2F68: bne         $t3, $at, L_804C2F7C
    if (ctx->r11 != ctx->r1) {
        // 0x804C2F6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_804C2F7C;
    }
    // 0x804C2F6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x804C2F70: bne         $t9, $at, L_804C2F7C
    if (ctx->r25 != ctx->r1) {
        // 0x804C2F74: nop
    
            goto L_804C2F7C;
    }
    // 0x804C2F74: nop

    // 0x804C2F78: break       6
    do_break(2152476536);
L_804C2F7C:
    // 0x804C2F7C: mflo        $t7
    ctx->r15 = lo;
    // 0x804C2F80: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x804C2F84: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x804C2F88: andi        $t9, $ra, 0xFFF
    ctx->r25 = ctx->r31 & 0XFFF;
    // 0x804C2F8C: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x804C2F90: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x804C2F94: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x804C2F98: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x804C2F9C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804C2FA0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x804C2FA4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x804C2FA8: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x804C2FAC: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x804C2FB0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C2FB4: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x804C2FB8: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x804C2FBC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x804C2FC0: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x804C2FC4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x804C2FC8: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x804C2FCC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x804C2FD0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x804C2FD4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x804C2FD8: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x804C2FDC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x804C2FE0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804C2FE4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x804C2FE8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x804C2FEC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x804C2FF0: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x804C2FF4: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x804C2FF8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x804C2FFC: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x804C3000: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x804C3004: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x804C3008: lui         $ra, 0x400
    ctx->r31 = S32(0X400 << 16);
    // 0x804C300C: lui         $t3, 0x400
    ctx->r11 = S32(0X400 << 16);
    // 0x804C3010: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x804C3014: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x804C3018: ori         $t3, $t3, 0x71BF
    ctx->r11 = ctx->r11 | 0X71BF;
    // 0x804C301C: ori         $ra, $ra, 0x81FF
    ctx->r31 = ctx->r31 | 0X81FF;
    // 0x804C3020: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x804C3024: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804C3028: lui         $t4, 0xB100
    ctx->r12 = S32(0XB100 << 16);
L_804C302C:
    // 0x804C302C: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x804C3030: bne         $at, $zero, L_804C3074
    if (ctx->r1 != 0) {
        // 0x804C3034: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_804C3074;
    }
    // 0x804C3034: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x804C3038: sll         $t6, $t0, 9
    ctx->r14 = S32(ctx->r8 << 9);
    // 0x804C303C: addu        $v1, $t6, $s0
    ctx->r3 = ADD32(ctx->r14, ctx->r16);
    // 0x804C3040: bne         $t0, $t2, L_804C305C
    if (ctx->r8 != ctx->r10) {
        // 0x804C3044: addiu       $v1, $v1, 0x288
        ctx->r3 = ADD32(ctx->r3, 0X288);
            goto L_804C305C;
    }
    // 0x804C3044: addiu       $v1, $v1, 0x288
    ctx->r3 = ADD32(ctx->r3, 0X288);
    // 0x804C3048: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x804C304C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x804C3050: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804C3054: b           L_804C306C
    // 0x804C3058: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
        goto L_804C306C;
    // 0x804C3058: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_804C305C:
    // 0x804C305C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x804C3060: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x804C3064: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804C3068: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_804C306C:
    // 0x804C306C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C3070: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_804C3074:
    // 0x804C3074: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x804C3078: addiu       $a0, $v0, 0x2
    ctx->r4 = ADD32(ctx->r2, 0X2);
    // 0x804C307C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x804C3080: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x804C3084: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x804C3088: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x804C308C: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x804C3090: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x804C3094: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x804C3098: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x804C309C: or          $t7, $t8, $t4
    ctx->r15 = ctx->r24 | ctx->r12;
    // 0x804C30A0: addiu       $t6, $v0, 0x6
    ctx->r14 = ADD32(ctx->r2, 0X6);
    // 0x804C30A4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x804C30A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804C30AC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x804C30B0: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x804C30B4: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x804C30B8: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x804C30BC: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x804C30C0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x804C30C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x804C30C8: bne         $t1, $t5, L_804C302C
    if (ctx->r9 != ctx->r13) {
        // 0x804C30CC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_804C302C;
    }
    // 0x804C30CC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x804C30D0: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804C30D4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x804C30D8: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x804C30DC: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x804C30E0: sw          $t7, 0x280($s0)
    MEM_W(0X280, ctx->r16) = ctx->r15;
    // 0x804C30E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C30E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C30EC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x804C30F0: jr          $ra
    // 0x804C30F4: nop

    return;
    // 0x804C30F4: nop

;}
RECOMP_FUNC void func_80682EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682EF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682EF8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682EFC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682F00: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682F04: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682F08: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682F0C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682F10: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682F14: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682F18: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682F1C: jr          $ra
    // 0x80682F20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682F20: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80423A6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80423A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80423A74: jal         0x80423A0C
    // 0x80423A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80423A0C(rdram, ctx);
        goto after_0;
    // 0x80423A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80423A7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80423A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423A84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80423A88: jal         0x80423DB8
    // 0x80423A8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80423DB8(rdram, ctx);
        goto after_1;
    // 0x80423A8C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80423A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80423A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80423A98: jr          $ra
    // 0x80423A9C: nop

    return;
    // 0x80423A9C: nop

;}
RECOMP_FUNC void func_8067E728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E728: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8067E72C: jr          $ra
    // 0x8067E730: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    return;
    // 0x8067E730: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_8064A60C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A60C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A610: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A614: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064A618: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064A61C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8064A620: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064A624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064A628: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8064A62C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064A630: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A634: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8064A638: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064A63C: nop

    // 0x8064A640: bc1fl       L_8064A658
    if (!c1cs) {
        // 0x8064A644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A658;
    }
    goto skip_0;
    // 0x8064A644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064A648: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064A64C: jal         0x8064A97C
    // 0x8064A650: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064A97C(rdram, ctx);
        goto after_0;
    // 0x8064A650: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064A654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A658:
    // 0x8064A658: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A65C: jr          $ra
    // 0x8064A660: nop

    return;
    // 0x8064A660: nop

;}
RECOMP_FUNC void func_807BB4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB4A8: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x807BB4AC: lui         $t6, 0x807C
    ctx->r14 = S32(RELOC_HI16(895, 0XBD8) << 16);
    // 0x807BB4B0: addiu       $t6, $t6, -0x4C18
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(895, 0XBD8));
    // 0x807BB4B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807BB4B8: jr          $ra
    // 0x807BB4BC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x807BB4BC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80444504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444504: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80444508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044450C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80444510: sb          $zero, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = 0;
    // 0x80444514: jal         0x8006D774
    // 0x80444518: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006D774(rdram, ctx);
        goto after_0;
    // 0x80444518: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8044451C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444520: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80444524: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80444528: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8044452C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80444530: sb          $t6, -0x7AE0($at)
    MEM_B(-0X7AE0, ctx->r1) = ctx->r14;
    // 0x80444534: jr          $ra
    // 0x80444538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80444538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void DmaMgr_SendRequest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DE3C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007DE40: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007DE44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007DE48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007DE4C: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x8007DE50: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x8007DE54: sw          $a3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r7;
    // 0x8007DE58: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8007DE5C: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x8007DE60: sltiu       $at, $a3, 0x10
    ctx->r1 = ctx->r7 < 0X10 ? 1 : 0;
    // 0x8007DE64: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
    // 0x8007DE68: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8007DE6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007DE70: addiu       $a0, $a0, -0x12B0
    ctx->r4 = ADD32(ctx->r4, -0X12B0);
    // 0x8007DE74: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x8007DE78: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x8007DE7C: sb          $zero, 0x11($s0)
    MEM_B(0X11, ctx->r16) = 0;
    // 0x8007DE80: sw          $a2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r6;
    // 0x8007DE84: sw          $a1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r5;
    // 0x8007DE88: beq         $at, $zero, L_8007DE9C
    if (ctx->r1 == 0) {
        // 0x8007DE8C: sw          $t8, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r24;
            goto L_8007DE9C;
    }
    // 0x8007DE8C: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x8007DE90: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x8007DE94: b           L_8007DEAC
    // 0x8007DE98: sw          $a3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r7;
        goto L_8007DEAC;
    // 0x8007DE98: sw          $a3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r7;
L_8007DE9C:
    // 0x8007DE9C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007DEA0: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8007DEA4: sb          $t9, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r25;
    // 0x8007DEA8: sw          $t0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r8;
L_8007DEAC:
    // 0x8007DEAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007DEB0: jal         0x80082210
    // 0x8007DEB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007DEB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007DEB8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8007DEBC: jal         0x8008AED0
    // 0x8007DEC0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8007DEC0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    after_1:
    // 0x8007DEC4: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x8007DEC8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8007DECC: lui         $t2, 0x8011
    ctx->r10 = S32(0X8011 << 16);
    // 0x8007DED0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8007DED4: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8007DED8: addiu       $t2, $t2, -0x12F0
    ctx->r10 = ADD32(ctx->r10, -0X12F0);
    // 0x8007DEDC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8007DEE0: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8007DEE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8007DEE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007DEEC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007DEF0: jal         0x8007DB60
    // 0x8007DEF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    DmaMgr_Read(rdram, ctx);
        goto after_2;
    // 0x8007DEF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8007DEF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DEFC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007DF00: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007DF04: jr          $ra
    // 0x8007DF08: nop

    return;
    // 0x8007DF08: nop

;}
RECOMP_FUNC void func_806DB7E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB7E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DB7E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB7EC: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x806DB7F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806DB7F4: jal         0x80049D74
    // 0x806DB7F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x806DB7F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806DB7FC: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x806DB800: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x806DB804: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806DB808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806DB80C: jal         0x8004D150
    // 0x806DB810: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D150(rdram, ctx);
        goto after_1;
    // 0x806DB810: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x806DB814: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x806DB818: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(634, 0X684) << 16);
    // 0x806DB81C: lwc1        $f4, -0x44BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(634, 0X684));
    // 0x806DB820: lwc1        $f6, 0xC8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC8);
    // 0x806DB824: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x806DB828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB82C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806DB830: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806DB834: bc1f        L_806DB858
    if (!c1cs) {
        // 0x806DB838: nop
    
            goto L_806DB858;
    }
    // 0x806DB838: nop

    // 0x806DB83C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806DB840: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x806DB844: lbu         $t0, 0x14($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X14);
    // 0x806DB848: beq         $t0, $zero, L_806DB858
    if (ctx->r8 == 0) {
        // 0x806DB84C: nop
    
            goto L_806DB858;
    }
    // 0x806DB84C: nop

    // 0x806DB850: b           L_806DB858
    // 0x806DB854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806DB858;
    // 0x806DB854: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806DB858:
    // 0x806DB858: jr          $ra
    // 0x806DB85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806DB85C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003E1C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E1C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E1C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E1C8: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x8003E1CC: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x8003E1D0: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003E1D4: jal         0x80065ABC
    // 0x8003E1D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x8003E1D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003E1DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003E1E0: jal         0x8003E070
    // 0x8003E1E4: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    func_8003E070(rdram, ctx);
        goto after_1;
    // 0x8003E1E4: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    after_1:
    // 0x8003E1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E1F0: jr          $ra
    // 0x8003E1F4: nop

    return;
    // 0x8003E1F4: nop

;}
RECOMP_FUNC void func_8064F444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F444: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F448: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F44C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F450: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F454: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F458: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F45C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F460: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F464: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F468: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F46C: jr          $ra
    // 0x8064F470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F470: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x8064F474: nop

    // 0x8064F478: nop

    // 0x8064F47C: nop

;}
RECOMP_FUNC void func_80434CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434CBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434CC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80434CC4: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x80434CC8: addiu       $v1, $v0, 0x5D0
    ctx->r3 = ADD32(ctx->r2, 0X5D0);
L_80434CCC:
    // 0x80434CCC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434CD0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434CD4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80434CD8: nop

    // 0x80434CDC: bc1f        L_80434CEC
    if (!c1cs) {
        // 0x80434CE0: nop
    
            goto L_80434CEC;
    }
    // 0x80434CE0: nop

    // 0x80434CE4: jr          $ra
    // 0x80434CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80434CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80434CEC:
    // 0x80434CEC: bgez        $a1, L_80434CCC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434CF0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80434CCC;
    }
    // 0x80434CF0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80434CF8: jr          $ra
    // 0x80434CFC: nop

    return;
    // 0x80434CFC: nop

;}
RECOMP_FUNC void func_80525C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80525C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80525C9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80525CA0: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(324, 0X63C) << 16);
    // 0x80525CA4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80525CA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80525CAC: addiu       $t8, $t8, 0x5B4C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(324, 0X63C));
    // 0x80525CB0: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80525CB4: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x80525CB8: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80525CBC: jal         0x8005FDC4
    // 0x80525CC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x80525CC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80525CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80525CC8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x80525CCC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80525CD0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80525CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80525CD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80525CDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80525CE0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x80525CE4: jr          $ra
    // 0x80525CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80525CE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806728F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806728F4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x806728F8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x806728FC: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(526, 0X21F4) << 16);
    // 0x80672900: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80672904: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80672908: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8067290C: lbu         $t7, 0x2D24($t7)
    ctx->r15 = MEM_BU(ctx->r15, (int16_t)RELOC_LO16(526, 0X21F4));
    // 0x80672910: lw          $v1, 0x16C($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X16C);
    // 0x80672914: jr          $ra
    // 0x80672918: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
    return;
    // 0x80672918: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void func_80433918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433918: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043391C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433920: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80433924: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80433928: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8043392C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(68, 0X1F4) << 16);
    // 0x80433930: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80433934: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80433938: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8043393C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80433940: lw          $t8, 0x3A24($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(68, 0X1F4));
    // 0x80433944: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80433948: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8043394C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80433950: jal         0x80048490
    // 0x80433954: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80433954: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80433958: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043395C: jal         0x80048378
    // 0x80433960: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80433960: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80433964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043396C: jr          $ra
    // 0x80433970: nop

    return;
    // 0x80433970: nop

;}
RECOMP_FUNC void func_8042DD58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DD58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DD5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DD60: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042DD64: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042DD68: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042DD6C: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(53, 0X3AC) << 16);
    // 0x8042DD70: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042DD74: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042DD78: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042DD7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042DD80: lw          $t8, -0x2034($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(53, 0X3AC));
    // 0x8042DD84: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8042DD88: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042DD8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042DD90: jal         0x80048490
    // 0x8042DD94: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8042DD94: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8042DD98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8042DD9C: jal         0x80048378
    // 0x8042DDA0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042DDA0: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8042DDA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042DDA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DDAC: jr          $ra
    // 0x8042DDB0: nop

    return;
    // 0x8042DDB0: nop

;}
RECOMP_FUNC void func_807935E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807935E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807935E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807935E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807935EC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x807935F0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807935F4: addiu       $at, $zero, 0x41A7
    ctx->r1 = ADD32(0, 0X41A7);
    // 0x807935F8: bnel        $v0, $at, L_8079360C
    if (ctx->r2 != ctx->r1) {
        // 0x807935FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079360C;
    }
    goto skip_0;
    // 0x807935FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80793600: jal         0x80793284
    // 0x80793604: nop

    func_80793284(rdram, ctx);
        goto after_0;
    // 0x80793604: nop

    after_0:
    // 0x80793608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079360C:
    // 0x8079360C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80793610: jr          $ra
    // 0x80793614: nop

    return;
    // 0x80793614: nop

;}
RECOMP_FUNC void func_80736E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736E64: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80736E68: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80736E6C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80736E70: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80736E74: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80736E78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80736E7C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80736E80: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80736E84: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(736, 0X39C4) << 16);
    // 0x80736E88: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80736E8C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80736E90: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80736E94: lw          $t1, -0x6BDC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(736, 0X39C4));
    // 0x80736E98: jr          $ra
    // 0x80736E9C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80736E9C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80703470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703470: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(709, 0X22F4) << 16);
    // 0x80703474: addiu       $v0, $v0, 0x5764
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(709, 0X22F4));
    // 0x80703478: jr          $ra
    // 0x8070347C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8070347C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void fatan2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081E8C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80081E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081E94: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80081E98: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80081E9C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80081EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081EA4: bc1fl       L_80081EC8
    if (!c1cs) {
        // 0x80081EA8: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80081EC8;
    }
    goto skip_0;
    // 0x80081EA8: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_0:
    // 0x80081EAC: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    // 0x80081EB0: nop

    // 0x80081EB4: bc1fl       L_80081EC8
    if (!c1cs) {
        // 0x80081EB8: c.eq.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
            goto L_80081EC8;
    }
    goto skip_1;
    // 0x80081EB8: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
    skip_1:
    // 0x80081EBC: b           L_80081F6C
    // 0x80081EC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80081F6C;
    // 0x80081EC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80081EC4: c.eq.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl == ctx->f2.fl;
L_80081EC8:
    // 0x80081EC8: nop

    // 0x80081ECC: bc1fl       L_80081EFC
    if (!c1cs) {
        // 0x80081ED0: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_80081EFC;
    }
    goto skip_2;
    // 0x80081ED0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_2:
    // 0x80081ED4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80081ED8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081EDC: bc1f        L_80081EF0
    if (!c1cs) {
        // 0x80081EE0: nop
    
            goto L_80081EF0;
    }
    // 0x80081EE0: nop

    // 0x80081EE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081EE8: b           L_80081F6C
    // 0x80081EEC: lwc1        $f0, 0x3188($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3188);
        goto L_80081F6C;
    // 0x80081EEC: lwc1        $f0, 0x3188($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X3188);
L_80081EF0:
    // 0x80081EF0: b           L_80081F6C
    // 0x80081EF4: lwc1        $f0, 0x318C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X318C);
        goto L_80081F6C;
    // 0x80081EF4: lwc1        $f0, 0x318C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X318C);
    // 0x80081EF8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_80081EFC:
    // 0x80081EFC: nop

    // 0x80081F00: bc1f        L_80081F64
    if (!c1cs) {
        // 0x80081F04: nop
    
            goto L_80081F64;
    }
    // 0x80081F04: nop

    // 0x80081F08: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80081F0C: nop

    // 0x80081F10: bc1fl       L_80081F44
    if (!c1cs) {
        // 0x80081F14: div.s       $f8, $f20, $f14
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
            goto L_80081F44;
    }
    goto skip_3;
    // 0x80081F14: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    skip_3:
    // 0x80081F18: div.s       $f4, $f20, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x80081F1C: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80081F20: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x80081F24: jal         0x80081D68
    // 0x80081F28: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanContFracF(rdram, ctx);
        goto after_0;
    // 0x80081F28: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_0:
    // 0x80081F2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081F30: lwc1        $f6, 0x3190($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3190);
    // 0x80081F34: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80081F38: b           L_80081F6C
    // 0x80081F3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_80081F6C;
    // 0x80081F3C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80081F40: div.s       $f8, $f20, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
L_80081F44:
    // 0x80081F44: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x80081F48: abs.d       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.d = fabs(ctx->f0.d);
    // 0x80081F4C: jal         0x80081D68
    // 0x80081F50: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    Math_FAtanContFracF(rdram, ctx);
        goto after_1;
    // 0x80081F50: cvt.s.d     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f12.fl = CVT_S_D(ctx->f0.d);
    after_1:
    // 0x80081F54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081F58: lwc1        $f10, 0x3194($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3194);
    // 0x80081F5C: b           L_80081F6C
    // 0x80081F60: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
        goto L_80081F6C;
    // 0x80081F60: sub.s       $f0, $f10, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f0.fl;
L_80081F64:
    // 0x80081F64: jal         0x80081D68
    // 0x80081F68: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    Math_FAtanContFracF(rdram, ctx);
        goto after_2;
    // 0x80081F68: div.s       $f12, $f20, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    after_2:
L_80081F6C:
    // 0x80081F6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081F70: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80081F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081F78: jr          $ra
    // 0x80081F7C: nop

    return;
    // 0x80081F7C: nop

;}
RECOMP_FUNC void func_806A9A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A9A34: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x806A9A38: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x806A9A3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806A9A40: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806A9A44: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806A9A48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806A9A4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806A9A50: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806A9A54: lb          $a0, 0x2($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X2);
    // 0x806A9A58: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806A9A5C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x806A9A60: jal         0x806A9908
    // 0x806A9A64: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    func_806A9908(rdram, ctx);
        goto after_0;
    // 0x806A9A64: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    after_0:
    // 0x806A9A68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A9A6C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x806A9A70: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x806A9A74: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x806A9A78: addiu       $s1, $s1, 0xC4
    ctx->r17 = ADD32(ctx->r17, 0XC4);
    // 0x806A9A7C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x806A9A80: bc1t        L_806A9A8C
    if (c1cs) {
        // 0x806A9A84: nop
    
            goto L_806A9A8C;
    }
    // 0x806A9A84: nop

    // 0x806A9A88: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_806A9A8C:
    // 0x806A9A8C: lw          $t8, 0x7EA8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7EA8);
    // 0x806A9A90: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x806A9A94: jal         0x806A9908
    // 0x806A9A98: lb          $a0, 0x3($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X3);
    func_806A9908(rdram, ctx);
        goto after_1;
    // 0x806A9A98: lb          $a0, 0x3($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X3);
    after_1:
    // 0x806A9A9C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A9AA0: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x806A9AA4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x806A9AA8: nop

    // 0x806A9AAC: bc1tl       L_806A9ABC
    if (c1cs) {
        // 0x806A9AB0: lwc1        $f4, 0x4($s1)
        ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
            goto L_806A9ABC;
    }
    goto skip_0;
    // 0x806A9AB0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x806A9AB4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x806A9AB8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
L_806A9ABC:
    // 0x806A9ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806A9AC0: beq         $s2, $at, L_806A9B10
    if (ctx->r18 == ctx->r1) {
        // 0x806A9AC4: swc1        $f4, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
            goto L_806A9B10;
    }
    // 0x806A9AC4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x806A9AC8: jal         0x80065954
    // 0x806A9ACC: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x806A9ACC: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x806A9AD0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11E4) << 16);
    // 0x806A9AD4: lwc1        $f6, -0x565C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11E4));
    // 0x806A9AD8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x806A9ADC: nop

    // 0x806A9AE0: bc1tl       L_806A9B14
    if (c1cs) {
        // 0x806A9AE4: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_806A9B14;
    }
    goto skip_1;
    // 0x806A9AE4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x806A9AE8: jal         0x80065954
    // 0x806A9AEC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x806A9AEC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    after_3:
    // 0x806A9AF0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11E8) << 16);
    // 0x806A9AF4: lwc1        $f8, -0x5658($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11E8));
    // 0x806A9AF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806A9AFC: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x806A9B00: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806A9B04: nop

    // 0x806A9B08: bc1fl       L_806A9B9C
    if (!c1cs) {
        // 0x806A9B0C: swc1        $f2, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
            goto L_806A9B9C;
    }
    goto skip_2;
    // 0x806A9B0C: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    skip_2:
L_806A9B10:
    // 0x806A9B10: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_806A9B14:
    // 0x806A9B14: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x806A9B18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806A9B1C: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x806A9B20: lh          $t1, 0x1BC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1BC);
    // 0x806A9B24: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806A9B28: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x806A9B2C: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x806A9B30: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x806A9B34: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x806A9B38: nop

    // 0x806A9B3C: sh          $t0, 0xC($t3)
    MEM_H(0XC, ctx->r11) = ctx->r8;
    // 0x806A9B40: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806A9B44: lwc1        $f4, 0x88($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X88);
    // 0x806A9B48: lh          $t6, 0x1BC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1BC);
    // 0x806A9B4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806A9B50: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x806A9B54: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x806A9B58: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806A9B5C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806A9B60: mfc1        $t5, $f16
    ctx->r13 = (int32_t)ctx->f16.u32l;
    // 0x806A9B64: nop

    // 0x806A9B68: sh          $t5, 0x9C($t8)
    MEM_H(0X9C, ctx->r24) = ctx->r13;
    // 0x806A9B6C: lh          $v0, 0x1BC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1BC);
    // 0x806A9B70: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x806A9B74: sh          $t9, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = ctx->r25;
    // 0x806A9B78: lh          $t1, 0x1BC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1BC);
    // 0x806A9B7C: sh          $v0, 0x1BE($s0)
    MEM_H(0X1BE, ctx->r16) = ctx->r2;
    // 0x806A9B80: slti        $at, $t1, 0x48
    ctx->r1 = SIGNED(ctx->r9) < 0X48 ? 1 : 0;
    // 0x806A9B84: bne         $at, $zero, L_806A9B90
    if (ctx->r1 != 0) {
        // 0x806A9B88: nop
    
            goto L_806A9B90;
    }
    // 0x806A9B88: nop

    // 0x806A9B8C: sh          $zero, 0x1BC($s0)
    MEM_H(0X1BC, ctx->r16) = 0;
L_806A9B90:
    // 0x806A9B90: b           L_806A9BA4
    // 0x806A9B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806A9BA4;
    // 0x806A9B94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806A9B98: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
L_806A9B9C:
    // 0x806A9B9C: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    // 0x806A9BA0: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
L_806A9BA4:
    // 0x806A9BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806A9BA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806A9BAC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806A9BB0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806A9BB4: jr          $ra
    // 0x806A9BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806A9BB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804C1F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1F30: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C1F34: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804C1F38: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804C1F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1F40: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804C1F44: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804C1F48: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804C1F4C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C1F50: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804C1F54: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804C1F58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804C1F5C: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(203, 0X1010) << 16);
    // 0x804C1F60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C1F64: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804C1F68: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804C1F6C: lw          $t2, 0x2780($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(203, 0X1010));
    // 0x804C1F70: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804C1F74: jal         0x804C1CB0
    // 0x804C1F78: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804C1CB0(rdram, ctx);
        goto after_0;
    // 0x804C1F78: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804C1F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C1F80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1F84: jr          $ra
    // 0x804C1F88: nop

    return;
    // 0x804C1F88: nop

;}
RECOMP_FUNC void func_8003943C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003943C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80039440: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80039444: lh          $t7, 0x4A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X4A);
    // 0x80039448: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8003944C: lh          $t6, -0x7680($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7680);
    // 0x80039450: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80039454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80039458: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003945C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80039460: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80039464: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80039468: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003946C: jal         0x80081E8C
    // 0x80039470: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x80039470: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_0:
    // 0x80039474: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80039478: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003947C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80039480: lwc1        $f10, 0x15C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X15C);
    // 0x80039484: mul.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80039488: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8003948C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80039490: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80039494: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80039498: lh          $t9, 0x4A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4A);
    // 0x8003949C: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800394A0: swc1        $f12, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f12.u32l;
    // 0x800394A4: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800394A8: sub.s       $f14, $f12, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x800394AC: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800394B0: nop

    // 0x800394B4: bc1fl       L_800394D0
    if (!c1cs) {
        // 0x800394B8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800394D0;
    }
    goto skip_0;
    // 0x800394B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x800394BC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800394C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800394C4: b           L_800394F0
    // 0x800394C8: sub.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f4.fl;
        goto L_800394F0;
    // 0x800394C8: sub.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800394CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800394D0:
    // 0x800394D0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800394D4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x800394D8: nop

    // 0x800394DC: bc1f        L_800394F0
    if (!c1cs) {
        // 0x800394E0: nop
    
            goto L_800394F0;
    }
    // 0x800394E0: nop

    // 0x800394E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800394E8: nop

    // 0x800394EC: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
L_800394F0:
    // 0x800394F0: bne         $t9, $zero, L_80039504
    if (ctx->r25 != 0) {
        // 0x800394F4: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80039504;
    }
    // 0x800394F4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800394F8: lh          $t0, 0xB00($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XB00);
    // 0x800394FC: beql        $t0, $zero, L_8003980C
    if (ctx->r8 == 0) {
        // 0x80039500: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8003980C;
    }
    goto skip_1;
    // 0x80039500: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
L_80039504:
    // 0x80039504: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039508: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8003950C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039510: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80039514: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80039518: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8003951C: nop

    // 0x80039520: bc1fl       L_80039538
    if (!c1cs) {
        // 0x80039524: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80039538;
    }
    goto skip_2;
    // 0x80039524: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_2:
    // 0x80039528: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003952C: nop

    // 0x80039530: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80039534: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80039538:
    // 0x80039538: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003953C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80039540: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039544: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80039548: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003954C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80039550: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x80039554: bc1f        L_80039568
    if (!c1cs) {
        // 0x80039558: nop
    
            goto L_80039568;
    }
    // 0x80039558: nop

    // 0x8003955C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039560: nop

    // 0x80039564: add.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f4.fl;
L_80039568:
    // 0x80039568: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003956C: lwc1        $f8, 0x160($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X160);
    // 0x80039570: lwc1        $f6, 0xB08($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB08);
    // 0x80039574: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x80039578: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8003957C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80039580: jal         0x80066DE4
    // 0x80039584: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80039584: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80039588: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003958C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80039590: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80039594: lwc1        $f4, 0x164($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X164);
    // 0x80039598: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8003959C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800395A0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800395A4: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800395A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800395AC: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800395B0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800395B4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800395B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800395BC: bc1fl       L_800395CC
    if (!c1cs) {
        // 0x800395C0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_800395CC;
    }
    goto skip_3;
    // 0x800395C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x800395C4: lwc1        $f12, 0x168($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X168);
    // 0x800395C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_800395CC:
    // 0x800395CC: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x800395D0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800395D4: nop

    // 0x800395D8: bc1fl       L_80039774
    if (!c1cs) {
        // 0x800395DC: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80039774;
    }
    goto skip_4;
    // 0x800395DC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_4:
    // 0x800395E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800395E4: lwc1        $f2, 0x0($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800395E8: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x800395EC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800395F0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800395F4: nop

    // 0x800395F8: bc1fl       L_8003961C
    if (!c1cs) {
        // 0x800395FC: c.lt.s      $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
            goto L_8003961C;
    }
    goto skip_5;
    // 0x800395FC: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    skip_5:
    // 0x80039600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80039604: nop

    // 0x80039608: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8003960C: nop

    // 0x80039610: bc1tl       L_80039648
    if (c1cs) {
        // 0x80039614: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80039648;
    }
    goto skip_6;
    // 0x80039614: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_6:
    // 0x80039618: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
L_8003961C:
    // 0x8003961C: lui         $at, 0xC307
    ctx->r1 = S32(0XC307 << 16);
    // 0x80039620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039624: bc1fl       L_800396E0
    if (!c1cs) {
        // 0x80039628: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_800396E0;
    }
    goto skip_7;
    // 0x80039628: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_7:
    // 0x8003962C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039630: nop

    // 0x80039634: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80039638: nop

    // 0x8003963C: bc1fl       L_800396E0
    if (!c1cs) {
        // 0x80039640: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_800396E0;
    }
    goto skip_8;
    // 0x80039640: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_8:
    // 0x80039644: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80039648:
    // 0x80039648: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003964C: bc1fl       L_8003965C
    if (!c1cs) {
        // 0x80039650: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_8003965C;
    }
    goto skip_9;
    // 0x80039650: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_9:
    // 0x80039654: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80039658: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_8003965C:
    // 0x8003965C: jal         0x80039368
    // 0x80039660: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_80039368(rdram, ctx);
        goto after_2;
    // 0x80039660: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x80039664: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80039668: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003966C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039670: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80039674: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x80039678: nop

    // 0x8003967C: bc1fl       L_800396C8
    if (!c1cs) {
        // 0x80039680: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_800396C8;
    }
    goto skip_10;
    // 0x80039680: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_10:
    // 0x80039684: jal         0x80065954
    // 0x80039688: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80039688: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_3:
    // 0x8003968C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80039690: jal         0x80065954
    // 0x80039694: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80065954(rdram, ctx);
        goto after_4;
    // 0x80039694: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80039698: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003969C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800396A0: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800396A4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800396A8: nop

    // 0x800396AC: bc1fl       L_800396C8
    if (!c1cs) {
        // 0x800396B0: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_800396C8;
    }
    goto skip_11;
    // 0x800396B0: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_11:
    // 0x800396B4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800396B8: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x800396BC: b           L_80039814
    // 0x800396C0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_80039814;
    // 0x800396C0: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800396C4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_800396C8:
    // 0x800396C8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800396CC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800396D0: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800396D4: b           L_80039814
    // 0x800396D8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80039814;
    // 0x800396D8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800396DC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_800396E0:
    // 0x800396E0: nop

    // 0x800396E4: bc1fl       L_800396F4
    if (!c1cs) {
        // 0x800396E8: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_800396F4;
    }
    goto skip_12;
    // 0x800396E8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_12:
    // 0x800396EC: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800396F0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_800396F4:
    // 0x800396F4: jal         0x80039368
    // 0x800396F8: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_80039368(rdram, ctx);
        goto after_5;
    // 0x800396F8: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x800396FC: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80039700: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80039704: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039708: mul.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8003970C: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x80039710: nop

    // 0x80039714: bc1fl       L_8003975C
    if (!c1cs) {
        // 0x80039718: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_8003975C;
    }
    goto skip_13;
    // 0x80039718: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_13:
    // 0x8003971C: jal         0x80065954
    // 0x80039720: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80065954(rdram, ctx);
        goto after_6;
    // 0x80039720: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_6:
    // 0x80039724: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80039728: jal         0x80065954
    // 0x8003972C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80065954(rdram, ctx);
        goto after_7;
    // 0x8003972C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80039730: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80039734: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80039738: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003973C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80039740: nop

    // 0x80039744: bc1fl       L_8003975C
    if (!c1cs) {
        // 0x80039748: lw          $v0, 0x40($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X40);
            goto L_8003975C;
    }
    goto skip_14;
    // 0x80039748: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    skip_14:
    // 0x8003974C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039750: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80039754: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80039758: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
L_8003975C:
    // 0x8003975C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80039760: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80039764: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80039768: b           L_80039814
    // 0x8003976C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
        goto L_80039814;
    // 0x8003976C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80039770: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80039774:
    // 0x80039774: nop

    // 0x80039778: bc1fl       L_80039788
    if (!c1cs) {
        // 0x8003977C: mfc1        $a1, $f12
        ctx->r5 = (int32_t)ctx->f12.u32l;
            goto L_80039788;
    }
    goto skip_15;
    // 0x8003977C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    skip_15:
    // 0x80039780: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80039784: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
L_80039788:
    // 0x80039788: jal         0x80039368
    // 0x8003978C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    func_80039368(rdram, ctx);
        goto after_8;
    // 0x8003978C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_8:
    // 0x80039790: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80039794: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80039798: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003979C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800397A0: c.le.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl <= ctx->f10.fl;
    // 0x800397A4: nop

    // 0x800397A8: bc1fl       L_800397F4
    if (!c1cs) {
        // 0x800397AC: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_800397F4;
    }
    goto skip_16;
    // 0x800397AC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    skip_16:
    // 0x800397B0: jal         0x80065954
    // 0x800397B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    func_80065954(rdram, ctx);
        goto after_9;
    // 0x800397B4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    after_9:
    // 0x800397B8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800397BC: jal         0x80065954
    // 0x800397C0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80065954(rdram, ctx);
        goto after_10;
    // 0x800397C0: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_10:
    // 0x800397C4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800397C8: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800397CC: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800397D0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800397D4: nop

    // 0x800397D8: bc1fl       L_800397F4
    if (!c1cs) {
        // 0x800397DC: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_800397F4;
    }
    goto skip_17;
    // 0x800397DC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    skip_17:
    // 0x800397E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800397E4: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x800397E8: b           L_80039814
    // 0x800397EC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_80039814;
    // 0x800397EC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800397F0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_800397F4:
    // 0x800397F4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800397F8: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800397FC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80039800: b           L_80039814
    // 0x80039804: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_80039814;
    // 0x80039804: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
    // 0x80039808: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8003980C:
    // 0x8003980C: nop

    // 0x80039810: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_80039814:
    // 0x80039814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80039818: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003981C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80039820: jr          $ra
    // 0x80039824: nop

    return;
    // 0x80039824: nop

;}
RECOMP_FUNC void func_80068320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068328: jal         0x8006823C
    // 0x8006832C: nop

    func_8006823C(rdram, ctx);
        goto after_0;
    // 0x8006832C: nop

    after_0:
    // 0x80068330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068338: jr          $ra
    // 0x8006833C: nop

    return;
    // 0x8006833C: nop

;}
RECOMP_FUNC void func_805172C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805172C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805172C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805172C8: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x805172CC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805172D0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805172D4: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(285, 0X384) << 16);
    // 0x805172D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805172DC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805172E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805172E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805172E8: lw          $t8, 0x7494($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(285, 0X384));
    // 0x805172EC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805172F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805172F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805172F8: jal         0x80048490
    // 0x805172FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805172FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80517300: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80517304: jal         0x80048378
    // 0x80517308: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80517308: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8051730C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517314: jr          $ra
    // 0x80517318: nop

    return;
    // 0x80517318: nop

;}
RECOMP_FUNC void func_800109DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800109DC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800109E0: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x800109E4: bnel        $v0, $zero, L_800109F8
    if (ctx->r2 != 0) {
        // 0x800109E8: lh          $t6, 0x2($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X2);
            goto L_800109F8;
    }
    goto skip_0;
    // 0x800109E8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    skip_0:
    // 0x800109EC: jr          $ra
    // 0x800109F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800109F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800109F4: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
L_800109F8:
    // 0x800109F8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800109FC: sltiu       $at, $t7, 0x35
    ctx->r1 = ctx->r15 < 0X35 ? 1 : 0;
    // 0x80010A00: beq         $at, $zero, L_80010A24
    if (ctx->r1 == 0) {
        // 0x80010A04: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80010A24;
    }
    // 0x80010A04: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80010A08: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80010A0C: addu        $at, $at, $t7
    gpr jr_addend_80010A14 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80010A10: lw          $t7, -0x3ADC($at)
    ctx->r15 = ADD32(ctx->r1, -0X3ADC);
    // 0x80010A14: jr          $t7
    // 0x80010A18: nop

    switch (jr_addend_80010A14 >> 2) {
        case 0: goto L_80010A1C; break;
        case 1: goto L_80010A1C; break;
        case 2: goto L_80010A1C; break;
        case 3: goto L_80010A1C; break;
        case 4: goto L_80010A1C; break;
        case 5: goto L_80010A1C; break;
        case 6: goto L_80010A1C; break;
        case 7: goto L_80010A1C; break;
        case 8: goto L_80010A1C; break;
        case 9: goto L_80010A1C; break;
        case 10: goto L_80010A24; break;
        case 11: goto L_80010A24; break;
        case 12: goto L_80010A24; break;
        case 13: goto L_80010A1C; break;
        case 14: goto L_80010A24; break;
        case 15: goto L_80010A24; break;
        case 16: goto L_80010A1C; break;
        case 17: goto L_80010A24; break;
        case 18: goto L_80010A24; break;
        case 19: goto L_80010A1C; break;
        case 20: goto L_80010A24; break;
        case 21: goto L_80010A24; break;
        case 22: goto L_80010A24; break;
        case 23: goto L_80010A24; break;
        case 24: goto L_80010A24; break;
        case 25: goto L_80010A24; break;
        case 26: goto L_80010A24; break;
        case 27: goto L_80010A24; break;
        case 28: goto L_80010A24; break;
        case 29: goto L_80010A24; break;
        case 30: goto L_80010A24; break;
        case 31: goto L_80010A24; break;
        case 32: goto L_80010A24; break;
        case 33: goto L_80010A24; break;
        case 34: goto L_80010A1C; break;
        case 35: goto L_80010A1C; break;
        case 36: goto L_80010A1C; break;
        case 37: goto L_80010A24; break;
        case 38: goto L_80010A24; break;
        case 39: goto L_80010A24; break;
        case 40: goto L_80010A24; break;
        case 41: goto L_80010A24; break;
        case 42: goto L_80010A24; break;
        case 43: goto L_80010A24; break;
        case 44: goto L_80010A1C; break;
        case 45: goto L_80010A24; break;
        case 46: goto L_80010A24; break;
        case 47: goto L_80010A24; break;
        case 48: goto L_80010A24; break;
        case 49: goto L_80010A1C; break;
        case 50: goto L_80010A24; break;
        case 51: goto L_80010A24; break;
        case 52: goto L_80010A1C; break;
        default: switch_error(__func__, 0x80010A14, 0x800AC524);
    }
    // 0x80010A18: nop

L_80010A1C:
    // 0x80010A1C: jr          $ra
    // 0x80010A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80010A20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80010A24:
    // 0x80010A24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80010A28: jr          $ra
    // 0x80010A2C: nop

    return;
    // 0x80010A2C: nop

;}
RECOMP_FUNC void func_80474FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474FA0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474FA4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474FA8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474FAC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474FB0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474FB4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474FB8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474FBC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474FC0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474FC4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474FC8: jr          $ra
    // 0x80474FCC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474FCC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8002F4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F4B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002F4BC: jal         0x8002B00C
    // 0x8002F4C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8002B00C(rdram, ctx);
        goto after_0;
    // 0x8002F4C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002F4C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002F4C8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F4CC: swc1        $f0, 0x54($t6)
    MEM_W(0X54, ctx->r14) = ctx->f0.u32l;
    // 0x8002F4D0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8002F4D4: swc1        $f0, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->f0.u32l;
    // 0x8002F4D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F4DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F4E0: jr          $ra
    // 0x8002F4E4: nop

    return;
    // 0x8002F4E4: nop

;}
RECOMP_FUNC void func_8040C4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C4B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8040C4B8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8040C4BC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8040C4C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C4C4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8040C4C8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8040C4CC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8040C4D0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8040C4D4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8040C4D8: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(17, 0X4E8) << 16);
    // 0x8040C4DC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8040C4E0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8040C4E4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8040C4E8: lw          $t2, -0x3A88($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(17, 0X4E8));
    // 0x8040C4EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8040C4F0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8040C4F4: jal         0x8040C124
    // 0x8040C4F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040C124(rdram, ctx);
        goto after_0;
    // 0x8040C4F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040C4FC: jal         0x8040C180
    // 0x8040C500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040C180(rdram, ctx);
        goto after_1;
    // 0x8040C500: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8040C504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C508: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C50C: jr          $ra
    // 0x8040C510: nop

    return;
    // 0x8040C510: nop

    // 0x8040C514: nop

    // 0x8040C518: nop

    // 0x8040C51C: nop

;}
RECOMP_FUNC void func_8040AD68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AD68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040AD6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040AD70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040AD74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8040AD78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040AD7C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8040AD80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040AD84: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040AD88: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8040AD8C: nop

    // 0x8040AD90: bc1fl       L_8040ADD0
    if (!c1cs) {
        // 0x8040AD94: lbu         $t8, 0x30($s0)
        ctx->r24 = MEM_BU(ctx->r16, 0X30);
            goto L_8040ADD0;
    }
    goto skip_0;
    // 0x8040AD94: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    skip_0:
    // 0x8040AD98: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040AD9C: jal         0x8004D1F0
    // 0x8040ADA0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8040ADA0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    after_0:
    // 0x8040ADA4: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8040ADA8: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8040ADAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040ADB0: jal         0x8004D698
    // 0x8040ADB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8040ADB4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8040ADB8: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040ADBC: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x8040ADC0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x8040ADC4: b           L_8040AE14
    // 0x8040ADC8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
        goto L_8040AE14;
    // 0x8040ADC8: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8040ADCC: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
L_8040ADD0:
    // 0x8040ADD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8040ADD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040ADD8: bne         $t8, $at, L_8040AE14
    if (ctx->r24 != ctx->r1) {
        // 0x8040ADDC: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_8040AE14;
    }
    // 0x8040ADDC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8040ADE0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8040ADE4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8040ADE8: jal         0x8004D1F0
    // 0x8040ADEC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x8040ADEC: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    after_2:
    // 0x8040ADF0: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8040ADF4: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8040ADF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040ADFC: jal         0x8004D698
    // 0x8040AE00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x8040AE00: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8040AE04: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040AE08: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x8040AE0C: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x8040AE10: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8040AE14:
    // 0x8040AE14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040AE18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040AE1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040AE20: jr          $ra
    // 0x8040AE24: nop

    return;
    // 0x8040AE24: nop

;}
RECOMP_FUNC void func_8057F588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F588: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057F58C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057F590: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057F594: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F598: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057F59C: lw          $t6, 0x60($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X60);
    // 0x8057F5A0: beq         $t6, $zero, L_8057F5C8
    if (ctx->r14 == 0) {
        // 0x8057F5A4: nop
    
            goto L_8057F5C8;
    }
    // 0x8057F5A4: nop

    // 0x8057F5A8: jal         0x8057F520
    // 0x8057F5AC: nop

    func_8057F520(rdram, ctx);
        goto after_0;
    // 0x8057F5AC: nop

    after_0:
    // 0x8057F5B0: jal         0x8057F218
    // 0x8057F5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F218(rdram, ctx);
        goto after_1;
    // 0x8057F5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057F5B8: jal         0x8057F484
    // 0x8057F5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F484(rdram, ctx);
        goto after_2;
    // 0x8057F5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8057F5C0: b           L_8057F5EC
    // 0x8057F5C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8057F5EC;
    // 0x8057F5C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057F5C8:
    // 0x8057F5C8: jal         0x8057F18C
    // 0x8057F5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F18C(rdram, ctx);
        goto after_3;
    // 0x8057F5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8057F5D0: jal         0x8057F1E8
    // 0x8057F5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057F1E8(rdram, ctx);
        goto after_4;
    // 0x8057F5D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8057F5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057F5DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057F5E0: jal         0x8057F680
    // 0x8057F5E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8057F680(rdram, ctx);
        goto after_5;
    // 0x8057F5E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8057F5E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057F5EC:
    // 0x8057F5EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057F5F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057F5F4: jr          $ra
    // 0x8057F5F8: nop

    return;
    // 0x8057F5F8: nop

;}
RECOMP_FUNC void func_8006AFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AFA0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8006AFA4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006AFA8: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006AFAC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006AFB0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006AFB4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8006AFB8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006AFBC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006AFC0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006AFC4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006AFC8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006AFCC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006AFD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006AFD4: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8006AFD8: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8006AFDC: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x8006AFE0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006AFE4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8006AFE8: sll         $s7, $a2, 16
    ctx->r23 = S32(ctx->r6 << 16);
    // 0x8006AFEC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006AFF0: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8006AFF4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006AFF8: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006AFFC: addiu       $a1, $zero, 0x42A
    ctx->r5 = ADD32(0, 0X42A);
    // 0x8006B000: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006B004: lw          $s3, 0x20($t0)
    ctx->r19 = MEM_W(ctx->r8, 0X20);
    // 0x8006B008: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x8006B00C: bne         $a0, $zero, L_8006B028
    if (ctx->r4 != 0) {
        // 0x8006B010: lh          $fp, 0x16($s3)
        ctx->r30 = MEM_H(ctx->r19, 0X16);
            goto L_8006B028;
    }
    // 0x8006B010: lh          $fp, 0x16($s3)
    ctx->r30 = MEM_H(ctx->r19, 0X16);
    // 0x8006B014: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006B018: jal         0x80071380
    // 0x8006B01C: addiu       $a0, $a0, 0x1040
    ctx->r4 = ADD32(ctx->r4, 0X1040);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006B01C: addiu       $a0, $a0, 0x1040
    ctx->r4 = ADD32(ctx->r4, 0X1040);
    after_0:
    // 0x8006B020: b           L_8006B198
    // 0x8006B024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006B198;
    // 0x8006B024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B028:
    // 0x8006B028: lw          $t2, 0x80($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X80);
    // 0x8006B02C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8006B030: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8006B034: blez        $t2, L_8006B194
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8006B038: addiu       $s5, $sp, 0x66
        ctx->r21 = ADD32(ctx->r29, 0X66);
            goto L_8006B194;
    }
    // 0x8006B038: addiu       $s5, $sp, 0x66
    ctx->r21 = ADD32(ctx->r29, 0X66);
    // 0x8006B03C: addiu       $s4, $sp, 0x68
    ctx->r20 = ADD32(ctx->r29, 0X68);
    // 0x8006B040: lh          $v1, 0x5E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5E);
L_8006B044:
    // 0x8006B044: lh          $t3, 0x66($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X66);
    // 0x8006B048: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006B04C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8006B050: slti        $at, $t3, 0x10
    ctx->r1 = SIGNED(ctx->r11) < 0X10 ? 1 : 0;
    // 0x8006B054: bne         $at, $zero, L_8006B0AC
    if (ctx->r1 != 0) {
        // 0x8006B058: or          $a2, $s5, $zero
        ctx->r6 = ctx->r21 | 0;
            goto L_8006B0AC;
    }
    // 0x8006B058: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8006B05C: lh          $a3, 0x76($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X76);
    // 0x8006B060: jal         0x8006AB7C
    // 0x8006B064: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_8006AB7C(rdram, ctx);
        goto after_1;
    // 0x8006B064: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_1:
    // 0x8006B068: bne         $s6, $v0, L_8006B078
    if (ctx->r22 != ctx->r2) {
        // 0x8006B06C: lh          $t5, 0x66($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X66);
            goto L_8006B078;
    }
    // 0x8006B06C: lh          $t5, 0x66($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X66);
    // 0x8006B070: b           L_8006B198
    // 0x8006B074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006B198;
    // 0x8006B074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B078:
    // 0x8006B078: multu       $fp, $t5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B07C: lw          $t4, 0x24($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X24);
    // 0x8006B080: lh          $t9, 0x68($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X68);
    // 0x8006B084: lh          $v1, 0x76($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X76);
    // 0x8006B088: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8006B08C: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8006B090: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006B094: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006B098: mflo        $t6
    ctx->r14 = lo;
    // 0x8006B09C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006B0A0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x8006B0A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006B0A8: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
L_8006B0AC:
    // 0x8006B0AC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8006B0B0: lh          $s0, 0x76($sp)
    ctx->r16 = MEM_H(ctx->r29, 0X76);
    // 0x8006B0B4: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8006B0B8: blez        $t2, L_8006B154
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8006B0BC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006B154;
    }
    // 0x8006B0BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006B0C0:
    // 0x8006B0C0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8006B0C4: bne         $at, $zero, L_8006B120
    if (ctx->r1 != 0) {
        // 0x8006B0C8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8006B120;
    }
    // 0x8006B0C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006B0CC: sll         $a3, $s0, 16
    ctx->r7 = S32(ctx->r16 << 16);
    // 0x8006B0D0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006B0D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8006B0D8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8006B0DC: jal         0x8006AB7C
    // 0x8006B0E0: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    func_8006AB7C(rdram, ctx);
        goto after_2;
    // 0x8006B0E0: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_2:
    // 0x8006B0E4: bne         $s6, $v0, L_8006B0F4
    if (ctx->r22 != ctx->r2) {
        // 0x8006B0E8: lh          $t5, 0x66($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X66);
            goto L_8006B0F4;
    }
    // 0x8006B0E8: lh          $t5, 0x66($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X66);
    // 0x8006B0EC: b           L_8006B198
    // 0x8006B0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006B198;
    // 0x8006B0F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006B0F4:
    // 0x8006B0F4: multu       $fp, $t5
    result = U64(U32(ctx->r30)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006B0F8: lw          $t3, 0x24($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X24);
    // 0x8006B0FC: lh          $t9, 0x68($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X68);
    // 0x8006B100: andi        $v1, $s0, 0xF
    ctx->r3 = ctx->r16 & 0XF;
    // 0x8006B104: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006B108: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8006B10C: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8006B110: mflo        $t6
    ctx->r14 = lo;
    // 0x8006B114: sll         $t4, $t6, 1
    ctx->r12 = S32(ctx->r14 << 1);
    // 0x8006B118: addu        $t7, $t3, $t4
    ctx->r15 = ADD32(ctx->r11, ctx->r12);
    // 0x8006B11C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_8006B120:
    // 0x8006B120: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8006B124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006B128: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B12C: sh          $t0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r8;
    // 0x8006B130: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8006B134: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006B138: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8006B13C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8006B140: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8006B144: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006B148: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8006B14C: bne         $s1, $t1, L_8006B0C0
    if (ctx->r17 != ctx->r9) {
        // 0x8006B150: sra         $v1, $v1, 16
        ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
            goto L_8006B0C0;
    }
    // 0x8006B150: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8006B154:
    // 0x8006B154: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8006B158: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8006B15C: lh          $t3, 0x66($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X66);
    // 0x8006B160: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8006B164: sll         $t5, $fp, 1
    ctx->r13 = S32(ctx->r30 << 1);
    // 0x8006B168: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8006B16C: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x8006B170: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x8006B174: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x8006B178: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8006B17C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x8006B180: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8006B184: sh          $t4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r12;
    // 0x8006B188: bne         $t7, $t8, L_8006B044
    if (ctx->r15 != ctx->r24) {
        // 0x8006B18C: sra         $s7, $s7, 16
        ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
            goto L_8006B044;
    }
    // 0x8006B18C: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x8006B190: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
L_8006B194:
    // 0x8006B194: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006B198:
    // 0x8006B198: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8006B19C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006B1A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006B1A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006B1A8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006B1AC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006B1B0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006B1B4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006B1B8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B1BC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8006B1C0: jr          $ra
    // 0x8006B1C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8006B1C4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_804EFA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFA60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EFA64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EFA68: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804EFA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804EFA70: beq         $t6, $zero, L_804EFAAC
    if (ctx->r14 == 0) {
        // 0x804EFA74: nop
    
            goto L_804EFAAC;
    }
    // 0x804EFA74: nop

    // 0x804EFA78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EFA7C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804EFA80: jalr        $t9
    // 0x804EFA84: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804EFA84: nop

    after_0:
    // 0x804EFA88: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EFA8C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804EFA90: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804EFA94: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804EFA98: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804EFA9C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804EFAA0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804EFAA4: b           L_804EFAAC
    // 0x804EFAA8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804EFAAC;
    // 0x804EFAA8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804EFAAC:
    // 0x804EFAAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EFAB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EFAB4: jr          $ra
    // 0x804EFAB8: nop

    return;
    // 0x804EFAB8: nop

;}
RECOMP_FUNC void func_8041F6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F6BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8041F6C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041F6C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041F6C8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F6CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041F6D0: jal         0x8041E9A8
    // 0x8041F6D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8041E9A8(rdram, ctx);
        goto after_0;
    // 0x8041F6D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8041F6D8: beql        $v0, $zero, L_8041F760
    if (ctx->r2 == 0) {
        // 0x8041F6DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F760;
    }
    goto skip_0;
    // 0x8041F6DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8041F6E0: jal         0x8041E5E8
    // 0x8041F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_1;
    // 0x8041F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8041F6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041F6EC: jal         0x8041E430
    // 0x8041F6F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8041E430(rdram, ctx);
        goto after_2;
    // 0x8041F6F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8041F6F4: jal         0x8041F594
    // 0x8041F6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_3;
    // 0x8041F6F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041F6FC: jal         0x8041F634
    // 0x8041F700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F634(rdram, ctx);
        goto after_4;
    // 0x8041F700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041F704: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8041F708: addiu       $at, $zero, 0x45F0
    ctx->r1 = ADD32(0, 0X45F0);
    // 0x8041F70C: beq         $v0, $at, L_8041F724
    if (ctx->r2 == ctx->r1) {
        // 0x8041F710: addiu       $at, $zero, 0x4638
        ctx->r1 = ADD32(0, 0X4638);
            goto L_8041F724;
    }
    // 0x8041F710: addiu       $at, $zero, 0x4638
    ctx->r1 = ADD32(0, 0X4638);
    // 0x8041F714: beql        $v0, $at, L_8041F748
    if (ctx->r2 == ctx->r1) {
        // 0x8041F718: lw          $t7, 0x34($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X34);
            goto L_8041F748;
    }
    goto skip_1;
    // 0x8041F718: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8041F71C: b           L_8041F760
    // 0x8041F720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041F760;
    // 0x8041F720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F724:
    // 0x8041F724: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x8041F728: slti        $at, $t6, 0x191
    ctx->r1 = SIGNED(ctx->r14) < 0X191 ? 1 : 0;
    // 0x8041F72C: bnel        $at, $zero, L_8041F760
    if (ctx->r1 != 0) {
        // 0x8041F730: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F760;
    }
    goto skip_2;
    // 0x8041F730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8041F734: jal         0x8041DFA0
    // 0x8041F738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DFA0(rdram, ctx);
        goto after_5;
    // 0x8041F738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8041F73C: b           L_8041F760
    // 0x8041F740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041F760;
    // 0x8041F740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041F744: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
L_8041F748:
    // 0x8041F748: slti        $at, $t7, -0x50
    ctx->r1 = SIGNED(ctx->r15) < -0X50 ? 1 : 0;
    // 0x8041F74C: beql        $at, $zero, L_8041F760
    if (ctx->r1 == 0) {
        // 0x8041F750: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8041F760;
    }
    goto skip_3;
    // 0x8041F750: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8041F754: jal         0x8041DFA0
    // 0x8041F758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041DFA0(rdram, ctx);
        goto after_6;
    // 0x8041F758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8041F75C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041F760:
    // 0x8041F760: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041F764: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8041F768: jr          $ra
    // 0x8041F76C: nop

    return;
    // 0x8041F76C: nop

;}
RECOMP_FUNC void func_805CC260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC260: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(456, 0X3E0) << 16);
    // 0x805CC264: lw          $t6, -0x39C0($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(456, 0X3E0));
    // 0x805CC268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CC26C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CC270: bne         $t6, $zero, L_805CC29C
    if (ctx->r14 != 0) {
        // 0x805CC274: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_805CC29C;
    }
    // 0x805CC274: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CC278: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(456, 0X4A0) << 16);
    // 0x805CC27C: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(456, 0X4B0) << 16);
    // 0x805CC280: addiu       $a1, $a1, -0x38F0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(456, 0X4B0));
    // 0x805CC284: addiu       $a0, $a0, -0x3900
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(456, 0X4A0));
    // 0x805CC288: jal         0x8004667C
    // 0x805CC28C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805CC28C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x805CC290: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x805CC294: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(456, 0X3E0) << 16);
    // 0x805CC298: sw          $t7, -0x39C0($at)
    MEM_W((int16_t)RELOC_LO16(456, 0X3E0), ctx->r1) = ctx->r15;
L_805CC29C:
    // 0x805CC29C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805CC2A0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805CC2A4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x805CC2A8: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(456, 0X338) << 16);
    // 0x805CC2AC: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x805CC2B0: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x805CC2B4: bnel        $t9, $zero, L_805CC2C8
    if (ctx->r25 != 0) {
        // 0x805CC2B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805CC2C8;
    }
    goto skip_0;
    // 0x805CC2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805CC2BC: jal         0x80057B28
    // 0x805CC2C0: addiu       $a2, $a2, -0x3A68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(456, 0X338));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805CC2C0: addiu       $a2, $a2, -0x3A68
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(456, 0X338));
    after_1:
    // 0x805CC2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CC2C8:
    // 0x805CC2C8: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(456, 0X78) << 16);
    // 0x805CC2CC: addiu       $v0, $v0, -0x3D28
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(456, 0X78));
    // 0x805CC2D0: jr          $ra
    // 0x805CC2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CC2D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80048D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048D74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80048D78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80048D7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80048D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80048D84: jal         0x8005F960
    // 0x80048D88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8005F960(rdram, ctx);
        goto after_0;
    // 0x80048D88: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80048D8C: bnel        $v0, $zero, L_80048DD8
    if (ctx->r2 != 0) {
        // 0x80048D90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80048DD8;
    }
    goto skip_0;
    // 0x80048D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80048D94: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80048D98: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80048D9C: lh          $a2, 0xC0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XC0);
    // 0x80048DA0: jal         0x800591EC
    // 0x80048DA4: lh          $a3, 0xC2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XC2);
    func_800591EC(rdram, ctx);
        goto after_1;
    // 0x80048DA4: lh          $a3, 0xC2($s0)
    ctx->r7 = MEM_H(ctx->r16, 0XC2);
    after_1:
    // 0x80048DA8: bne         $v0, $zero, L_80048DD0
    if (ctx->r2 != 0) {
        // 0x80048DAC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80048DD0;
    }
    // 0x80048DAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80048DB0: lbu         $t6, 0x1E8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1E8);
    // 0x80048DB4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80048DB8: beql        $t6, $zero, L_80048DD8
    if (ctx->r14 == 0) {
        // 0x80048DBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80048DD8;
    }
    goto skip_1;
    // 0x80048DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80048DC0: jalr        $t9
    // 0x80048DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80048DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80048DC8: b           L_80048DD8
    // 0x80048DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80048DD8;
    // 0x80048DCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80048DD0:
    // 0x80048DD0: sb          $t7, 0x1E8($s0)
    MEM_B(0X1E8, ctx->r16) = ctx->r15;
    // 0x80048DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80048DD8:
    // 0x80048DD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80048DDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80048DE0: jr          $ra
    // 0x80048DE4: nop

    return;
    // 0x80048DE4: nop

;}
RECOMP_FUNC void func_8040C090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C090: lui         $v0, 0x8041
    ctx->r2 = S32(RELOC_HI16(17, 0X10) << 16);
    // 0x8040C094: addiu       $v0, $v0, -0x3F60
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(17, 0X10));
    // 0x8040C098: jr          $ra
    // 0x8040C09C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8040C09C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8044BA84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BA84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044BA88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044BA8C: jal         0x8044B740
    // 0x8044BA90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8044B740(rdram, ctx);
        goto after_0;
    // 0x8044BA90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8044BA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044BA98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044BA9C: jr          $ra
    // 0x8044BAA0: nop

    return;
    // 0x8044BAA0: nop

;}
RECOMP_FUNC void func_80435C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80435C88: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80435C8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80435C90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80435C94: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80435C98: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80435C9C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80435CA0: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x80435CA4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x80435CA8: lw          $t8, 0xE80($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE80);
    // 0x80435CAC: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80435CB0: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80435CB4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80435CB8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80435CBC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80435CC0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80435CC4: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80435CC8: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x80435CCC: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80435CD0: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80435CD4: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x80435CD8: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80435CDC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X2838) << 16);
    // 0x80435CE0: addiu       $t8, $t8, 0x62E8
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(71, 0X2838));
    // 0x80435CE4: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80435CE8: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80435CEC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80435CF0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80435CF4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80435CF8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80435CFC: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x80435D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80435D04: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80435D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80435D0C: jal         0x8007711C
    // 0x80435D10: lw          $a3, 0x88($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X88);
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x80435D10: lw          $a3, 0x88($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X88);
    after_0:
    // 0x80435D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435D18: jal         0x8004921C
    // 0x80435D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80435D1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80435D20: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80435D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435D28: jal         0x8004921C
    // 0x80435D2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x80435D2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80435D30: lbu         $t7, 0x37($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X37);
    // 0x80435D34: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x80435D38: lbu         $t3, 0x145($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X145);
    // 0x80435D3C: multu       $t1, $t7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80435D40: lw          $t5, 0x168($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X168);
    // 0x80435D44: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80435D48: lui         $t1, 0xFD50
    ctx->r9 = S32(0XFD50 << 16);
    // 0x80435D4C: lw          $t6, 0x80($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X80);
    // 0x80435D50: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80435D54: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80435D58: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80435D5C: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x80435D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435D64: mflo        $t2
    ctx->r10 = lo;
    // 0x80435D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80435D6C: nop

    // 0x80435D70: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80435D74: lui         $t3, 0xF550
    ctx->r11 = S32(0XF550 << 16);
    // 0x80435D78: mflo        $t4
    ctx->r12 = lo;
    // 0x80435D7C: addu        $a2, $t4, $t6
    ctx->r6 = ADD32(ctx->r12, ctx->r14);
    // 0x80435D80: sw          $a2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r6;
    // 0x80435D84: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80435D88: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80435D8C: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80435D90: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80435D94: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x80435D98: sw          $t3, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r11;
    // 0x80435D9C: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80435DA0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80435DA4: addiu       $t6, $t4, 0x8
    ctx->r14 = ADD32(ctx->r12, 0X8);
    // 0x80435DA8: sw          $t6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r14;
    // 0x80435DAC: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80435DB0: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80435DB4: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80435DB8: addiu       $t1, $t9, 0x8
    ctx->r9 = ADD32(ctx->r25, 0X8);
    // 0x80435DBC: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x80435DC0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x80435DC4: jal         0x8004921C
    // 0x80435DC8: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x80435DC8: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    after_3:
    // 0x80435DCC: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80435DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435DD4: jal         0x8004921C
    // 0x80435DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x80435DD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80435DDC: lh          $t2, 0x36($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X36);
    // 0x80435DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435DE4: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80435DE8: mflo        $t3
    ctx->r11 = lo;
    // 0x80435DEC: addiu       $t5, $t3, 0x1
    ctx->r13 = ADD32(ctx->r11, 0X1);
    // 0x80435DF0: sra         $t4, $t5, 1
    ctx->r12 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80435DF4: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x80435DF8: slti        $at, $t6, 0x7FF
    ctx->r1 = SIGNED(ctx->r14) < 0X7FF ? 1 : 0;
    // 0x80435DFC: beq         $at, $zero, L_80435E3C
    if (ctx->r1 == 0) {
        // 0x80435E00: addiu       $t3, $zero, 0x7FF
        ctx->r11 = ADD32(0, 0X7FF);
            goto L_80435E3C;
    }
    // 0x80435E00: addiu       $t3, $zero, 0x7FF
    ctx->r11 = ADD32(0, 0X7FF);
    // 0x80435E04: jal         0x8004921C
    // 0x80435E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x80435E08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80435E0C: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x80435E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435E14: jal         0x8004921C
    // 0x80435E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_6;
    // 0x80435E18: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80435E1C: lh          $t8, 0x26($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X26);
    // 0x80435E20: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80435E24: mflo        $t9
    ctx->r25 = lo;
    // 0x80435E28: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80435E2C: sra         $t7, $t1, 1
    ctx->r15 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80435E30: addiu       $t2, $t7, -0x1
    ctx->r10 = ADD32(ctx->r15, -0X1);
    // 0x80435E34: b           L_80435E40
    // 0x80435E38: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
        goto L_80435E40;
    // 0x80435E38: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
L_80435E3C:
    // 0x80435E3C: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
L_80435E40:
    // 0x80435E40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435E44: jal         0x8004921C
    // 0x80435E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_7;
    // 0x80435E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80435E4C: bgez        $v0, L_80435E5C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80435E50: sra         $t5, $v0, 3
        ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80435E5C;
    }
    // 0x80435E50: sra         $t5, $v0, 3
    ctx->r13 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80435E54: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80435E58: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80435E5C:
    // 0x80435E5C: bgtz        $t5, L_80435E6C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80435E60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80435E6C;
    }
    // 0x80435E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435E64: b           L_80435E84
    // 0x80435E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80435E84;
    // 0x80435E68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80435E6C:
    // 0x80435E6C: jal         0x8004921C
    // 0x80435E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_8;
    // 0x80435E70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80435E74: bgez        $v0, L_80435E84
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80435E78: sra         $a3, $v0, 3
        ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80435E84;
    }
    // 0x80435E78: sra         $a3, $v0, 3
    ctx->r7 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80435E7C: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80435E80: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_80435E84:
    // 0x80435E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435E88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80435E8C: jal         0x8004921C
    // 0x80435E90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_9;
    // 0x80435E90: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_9:
    // 0x80435E94: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80435E98: bgez        $v0, L_80435EA8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80435E9C: sra         $t4, $v0, 3
        ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80435EA8;
    }
    // 0x80435E9C: sra         $t4, $v0, 3
    ctx->r12 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80435EA0: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80435EA4: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_80435EA8:
    // 0x80435EA8: bgtzl       $t4, L_80435EBC
    if (SIGNED(ctx->r12) > 0) {
        // 0x80435EAC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80435EBC;
    }
    goto skip_0;
    // 0x80435EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80435EB0: b           L_80435EDC
    // 0x80435EB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80435EDC;
    // 0x80435EB4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80435EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80435EBC:
    // 0x80435EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80435EC0: jal         0x8004921C
    // 0x80435EC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004921C(rdram, ctx);
        goto after_10;
    // 0x80435EC4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_10:
    // 0x80435EC8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80435ECC: bgez        $v0, L_80435EDC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80435ED0: sra         $v1, $v0, 3
        ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
            goto L_80435EDC;
    }
    // 0x80435ED0: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x80435ED4: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
    // 0x80435ED8: sra         $v1, $at, 3
    ctx->r3 = S32(SIGNED(ctx->r1) >> 3);
L_80435EDC:
    // 0x80435EDC: addiu       $t6, $a3, 0x7FF
    ctx->r14 = ADD32(ctx->r7, 0X7FF);
    // 0x80435EE0: div         $zero, $t6, $v1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r3)));
    // 0x80435EE4: bne         $v1, $zero, L_80435EF0
    if (ctx->r3 != 0) {
        // 0x80435EE8: nop
    
            goto L_80435EF0;
    }
    // 0x80435EE8: nop

    // 0x80435EEC: break       7
    do_break(2151898860);
L_80435EF0:
    // 0x80435EF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80435EF4: bne         $v1, $at, L_80435F08
    if (ctx->r3 != ctx->r1) {
        // 0x80435EF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80435F08;
    }
    // 0x80435EF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80435EFC: bne         $t6, $at, L_80435F08
    if (ctx->r14 != ctx->r1) {
        // 0x80435F00: nop
    
            goto L_80435F08;
    }
    // 0x80435F00: nop

    // 0x80435F04: break       6
    do_break(2151898884);
L_80435F08:
    // 0x80435F08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80435F0C: mflo        $t8
    ctx->r24 = lo;
    // 0x80435F10: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80435F14: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80435F18: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80435F1C: andi        $t2, $t7, 0xFFF
    ctx->r10 = ctx->r15 & 0XFFF;
    // 0x80435F20: sll         $t3, $t2, 12
    ctx->r11 = S32(ctx->r10 << 12);
    // 0x80435F24: or          $t1, $t9, $at
    ctx->r9 = ctx->r25 | ctx->r1;
    // 0x80435F28: or          $t5, $t1, $t3
    ctx->r13 = ctx->r9 | ctx->r11;
    // 0x80435F2C: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x80435F30: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x80435F34: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80435F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435F3C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x80435F40: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80435F44: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x80435F48: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80435F4C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x80435F50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80435F54: addiu       $t2, $t7, 0x8
    ctx->r10 = ADD32(ctx->r15, 0X8);
    // 0x80435F58: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    // 0x80435F5C: jal         0x8004921C
    // 0x80435F60: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_11;
    // 0x80435F60: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    after_11:
    // 0x80435F64: addiu       $t1, $v0, 0x7
    ctx->r9 = ADD32(ctx->r2, 0X7);
    // 0x80435F68: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80435F6C: sra         $t3, $t1, 3
    ctx->r11 = S32(SIGNED(ctx->r9) >> 3);
    // 0x80435F70: andi        $t5, $t3, 0x1FF
    ctx->r13 = ctx->r11 & 0X1FF;
    // 0x80435F74: sll         $t4, $t5, 9
    ctx->r12 = S32(ctx->r13 << 9);
    // 0x80435F78: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80435F7C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x80435F80: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80435F84: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80435F88: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80435F8C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80435F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435F94: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80435F98: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80435F9C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80435FA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80435FA4: jal         0x8004921C
    // 0x80435FA8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    func_8004921C(rdram, ctx);
        goto after_12;
    // 0x80435FA8: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_12:
    // 0x80435FAC: sh          $v0, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r2;
    // 0x80435FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80435FB4: jal         0x8004921C
    // 0x80435FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_13;
    // 0x80435FB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80435FBC: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80435FC0: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80435FC4: sll         $t1, $t2, 2
    ctx->r9 = S32(ctx->r10 << 2);
    // 0x80435FC8: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x80435FCC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80435FD0: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80435FD4: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x80435FD8: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80435FDC: andi        $t3, $t1, 0xFFF
    ctx->r11 = ctx->r9 & 0XFFF;
    // 0x80435FE0: or          $t7, $t3, $t9
    ctx->r15 = ctx->r11 | ctx->r25;
    // 0x80435FE4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80435FE8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80435FEC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80435FF0: addiu       $t5, $t1, 0x8
    ctx->r13 = ADD32(ctx->r9, 0X8);
    // 0x80435FF4: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
    // 0x80435FF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80435FFC: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80436000: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80436004: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80436008: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8043600C: sw          $t8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r24;
    // 0x80436010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80436014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80436018: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8043601C: jr          $ra
    // 0x80436020: nop

    return;
    // 0x80436020: nop

;}
RECOMP_FUNC void func_8002F108(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F10C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F110: sw          $zero, 0x11C($a0)
    MEM_W(0X11C, ctx->r4) = 0;
    // 0x8002F114: sw          $zero, 0x120($a0)
    MEM_W(0X120, ctx->r4) = 0;
    // 0x8002F118: lbu         $t6, 0x13($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X13);
    // 0x8002F11C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x8002F120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002F124: bnel        $t6, $zero, L_8002F140
    if (ctx->r14 != 0) {
        // 0x8002F128: sw          $zero, 0x130($a0)
        MEM_W(0X130, ctx->r4) = 0;
            goto L_8002F140;
    }
    goto skip_0;
    // 0x8002F128: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    skip_0:
    // 0x8002F12C: jal         0x80036900
    // 0x8002F130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80036900(rdram, ctx);
        goto after_0;
    // 0x8002F130: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002F134: b           L_8002F140
    // 0x8002F138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_8002F140;
    // 0x8002F138: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002F13C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
L_8002F140:
    // 0x8002F140: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x8002F144: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8002F148: sw          $zero, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = 0;
    // 0x8002F14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F154: jr          $ra
    // 0x8002F158: nop

    return;
    // 0x8002F158: nop

;}
RECOMP_FUNC void func_804B6E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6E70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6E74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6E78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804B6E7C: jal         0x804B6CE4
    // 0x804B6E80: addiu       $a1, $zero, 0x45AA
    ctx->r5 = ADD32(0, 0X45AA);
    func_804B6CE4(rdram, ctx);
        goto after_0;
    // 0x804B6E80: addiu       $a1, $zero, 0x45AA
    ctx->r5 = ADD32(0, 0X45AA);
    after_0:
    // 0x804B6E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6E88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6E8C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6E90: jal         0x804B6FF0
    // 0x804B6E94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6E94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6EA0: jr          $ra
    // 0x804B6EA4: nop

    return;
    // 0x804B6EA4: nop

;}
RECOMP_FUNC void func_8057DB50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DB50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057DB54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057DB58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057DB5C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x8057DB60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8057DB64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057DB68: bnel        $t6, $at, L_8057DB94
    if (ctx->r14 != ctx->r1) {
        // 0x8057DB6C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8057DB94;
    }
    goto skip_0;
    // 0x8057DB6C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8057DB70: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8057DB74: jal         0x80067BBC
    // 0x8057DB78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8057DB78: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8057DB7C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8057DB80: jal         0x80067F78
    // 0x8057DB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8057DB84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8057DB88: b           L_8057DBAC
    // 0x8057DB8C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8057DBAC;
    // 0x8057DB8C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8057DB90: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8057DB94:
    // 0x8057DB94: jal         0x80067BBC
    // 0x8057DB98: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8057DB98: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x8057DB9C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8057DBA0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8057DBA4: jal         0x800678F0
    // 0x8057DBA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x8057DBA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_8057DBAC:
    // 0x8057DBAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8057DBB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057DBB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057DBB8: jr          $ra
    // 0x8057DBBC: nop

    return;
    // 0x8057DBBC: nop

;}
RECOMP_FUNC void func_80741A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80741A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741A64: jal         0x80740EE0
    // 0x80741A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80740EE0(rdram, ctx);
        goto after_0;
    // 0x80741A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80741A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80741A70: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80741A74: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80741A78: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x80741A7C: bnel        $at, $zero, L_80741A90
    if (ctx->r1 != 0) {
        // 0x80741A80: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_80741A90;
    }
    goto skip_0;
    // 0x80741A80: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_0:
    // 0x80741A84: b           L_80741A90
    // 0x80741A88: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
        goto L_80741A90;
    // 0x80741A88: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x80741A8C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_80741A90:
    // 0x80741A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80741A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80741A98: jr          $ra
    // 0x80741A9C: nop

    return;
    // 0x80741A9C: nop

;}
RECOMP_FUNC void func_805198F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805198F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805198FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80519900: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519904: jal         0x80519124
    // 0x80519908: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80519124(rdram, ctx);
        goto after_0;
    // 0x80519908: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8051990C: jal         0x80519340
    // 0x80519910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519340(rdram, ctx);
        goto after_1;
    // 0x80519910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80519914: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x80519918: slti        $at, $t6, 0x5A
    ctx->r1 = SIGNED(ctx->r14) < 0X5A ? 1 : 0;
    // 0x8051991C: beql        $at, $zero, L_805199E0
    if (ctx->r1 == 0) {
        // 0x80519920: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805199E0;
    }
    goto skip_0;
    // 0x80519920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80519924: jal         0x80517CA8
    // 0x80519928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80517CA8(rdram, ctx);
        goto after_2;
    // 0x80519928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8051992C: jal         0x80518CC8
    // 0x80519930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80518CC8(rdram, ctx);
        goto after_3;
    // 0x80519930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80519934: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    // 0x80519938: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x8051993C: beql        $at, $zero, L_805199E0
    if (ctx->r1 == 0) {
        // 0x80519940: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805199E0;
    }
    goto skip_1;
    // 0x80519940: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80519944: lbu         $t8, 0x18($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18);
    // 0x80519948: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8051994C: lw          $a2, 0x174($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X174);
    // 0x80519950: bne         $t8, $at, L_805199D4
    if (ctx->r24 != ctx->r1) {
        // 0x80519954: nop
    
            goto L_805199D4;
    }
    // 0x80519954: nop

    // 0x80519958: lbu         $t0, 0x30($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X30);
    // 0x8051995C: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x80519960: bne         $t0, $zero, L_805199DC
    if (ctx->r8 != 0) {
        // 0x80519964: lw          $a0, 0x1F4($t9)
        ctx->r4 = MEM_W(ctx->r25, 0X1F4);
            goto L_805199DC;
    }
    // 0x80519964: lw          $a0, 0x1F4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X1F4);
    // 0x80519968: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8051996C: lhu         $t1, 0x12BE($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X12BE);
    // 0x80519970: lhu         $v0, 0x208($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X208);
    // 0x80519974: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x80519978: bgezl       $v0, L_80519988
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8051997C: andi        $a1, $v0, 0xFFFF
        ctx->r5 = ctx->r2 & 0XFFFF;
            goto L_80519988;
    }
    goto skip_2;
    // 0x8051997C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    skip_2:
    // 0x80519980: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80519984: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
L_80519988:
    // 0x80519988: jal         0x80040940
    // 0x8051998C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80040940(rdram, ctx);
        goto after_4;
    // 0x8051998C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x80519990: jal         0x8004816C
    // 0x80519994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004816C(rdram, ctx);
        goto after_5;
    // 0x80519994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80519998: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8051999C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805199A0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805199A4: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x805199A8: lh          $t3, 0xC($t2)
    ctx->r11 = MEM_H(ctx->r10, 0XC);
    // 0x805199AC: sh          $t3, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r11;
    // 0x805199B0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805199B4: lw          $t4, 0x20($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X20);
    // 0x805199B8: lh          $t5, 0xE($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XE);
    // 0x805199BC: jal         0x8005FDC4
    // 0x805199C0: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    func_8005FDC4(rdram, ctx);
        goto after_6;
    // 0x805199C0: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    after_6:
    // 0x805199C4: jal         0x805196C8
    // 0x805199C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805196C8(rdram, ctx);
        goto after_7;
    // 0x805199C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x805199CC: b           L_805199E0
    // 0x805199D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805199E0;
    // 0x805199D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805199D4:
    // 0x805199D4: jal         0x805196C8
    // 0x805199D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805196C8(rdram, ctx);
        goto after_8;
    // 0x805199D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
L_805199DC:
    // 0x805199DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805199E0:
    // 0x805199E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805199E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805199E8: jr          $ra
    // 0x805199EC: nop

    return;
    // 0x805199EC: nop

;}
RECOMP_FUNC void func_80462F34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462F34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80462F38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462F3C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80462F40: jal         0x80047090
    // 0x80462F44: addiu       $a0, $zero, 0x4502
    ctx->r4 = ADD32(0, 0X4502);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80462F44: addiu       $a0, $zero, 0x4502
    ctx->r4 = ADD32(0, 0X4502);
    after_0:
    // 0x80462F48: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80462F4C: bne         $v0, $at, L_80462F5C
    if (ctx->r2 != ctx->r1) {
        // 0x80462F50: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80462F5C;
    }
    // 0x80462F50: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80462F54: b           L_80462FD4
    // 0x80462F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462FD4;
    // 0x80462F58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80462F5C:
    // 0x80462F5C: lui         $at, 0x4502
    ctx->r1 = S32(0X4502 << 16);
    // 0x80462F60: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80462F64: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80462F68: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80462F6C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80462F70: lui         $a2, 0xC270
    ctx->r6 = S32(0XC270 << 16);
    // 0x80462F74: jal         0x8004613C
    // 0x80462F78: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80462F78: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x80462F7C: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x80462F80: bne         $v0, $zero, L_80462F90
    if (ctx->r2 != 0) {
        // 0x80462F84: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80462F90;
    }
    // 0x80462F84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80462F88: b           L_80462FD4
    // 0x80462F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462FD4;
    // 0x80462F8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80462F90:
    // 0x80462F90: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x80462F94: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80462F98: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80462F9C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80462FA0: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x80462FA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80462FA8: jal         0x80047F9C
    // 0x80462FAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80462FAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80462FB0: jal         0x80463A7C
    // 0x80462FB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80463A7C(rdram, ctx);
        goto after_3;
    // 0x80462FB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80462FB8: bne         $v0, $zero, L_80462FC8
    if (ctx->r2 != 0) {
        // 0x80462FBC: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80462FC8;
    }
    // 0x80462FBC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80462FC0: b           L_80462FD4
    // 0x80462FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80462FD4;
    // 0x80462FC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80462FC8:
    // 0x80462FC8: jal         0x8005FDC4
    // 0x80462FCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x80462FCC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80462FD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80462FD4:
    // 0x80462FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462FD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80462FDC: jr          $ra
    // 0x80462FE0: nop

    return;
    // 0x80462FE0: nop

;}
RECOMP_FUNC void func_80716930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80716930: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80716934: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716938: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8071693C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80716940: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80716944: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80716948: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8071694C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80716950: addiu       $t6, $zero, 0x960
    ctx->r14 = ADD32(0, 0X960);
    // 0x80716954: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80716958: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x8071695C: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80716960: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80716964: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716968: jal         0x8071637C
    // 0x8071696C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x8071696C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80716970: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80716974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716978: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8071697C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80716980: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x80716984: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80716988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8071698C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80716990: jr          $ra
    // 0x80716994: nop

    return;
    // 0x80716994: nop

;}
RECOMP_FUNC void func_806E834C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E834C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E8350: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806E8354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E8358: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806E835C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806E8360: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x806E8364: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x806E8368: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x806E836C: lui         $a1, 0x44E1
    ctx->r5 = S32(0X44E1 << 16);
    // 0x806E8370: lui         $a0, 0x806F
    ctx->r4 = S32(RELOC_HI16(667, 0X1890) << 16);
    // 0x806E8374: addiu       $a0, $a0, -0x64C0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(667, 0X1890));
    // 0x806E8378: ori         $a1, $a1, 0x2000
    ctx->r5 = ctx->r5 | 0X2000;
    // 0x806E837C: jal         0x80046804
    // 0x806E8380: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x806E8380: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806E8384: bne         $v0, $zero, L_806E8394
    if (ctx->r2 != 0) {
        // 0x806E8388: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806E8394;
    }
    // 0x806E8388: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806E838C: b           L_806E83CC
    // 0x806E8390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806E83CC;
    // 0x806E8390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E8394:
    // 0x806E8394: jal         0x80047090
    // 0x806E8398: addiu       $a0, $zero, 0x44E1
    ctx->r4 = ADD32(0, 0X44E1);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806E8398: addiu       $a0, $zero, 0x44E1
    ctx->r4 = ADD32(0, 0X44E1);
    after_1:
    // 0x806E839C: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x806E83A0: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x806E83A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E83A8: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806E83AC: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806E83B0: jal         0x80044194
    // 0x806E83B4: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x806E83B4: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    after_2:
    // 0x806E83B8: jal         0x806E9800
    // 0x806E83BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806E9800(rdram, ctx);
        goto after_3;
    // 0x806E83BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806E83C0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x806E83C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x806E83C8: sw          $t1, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r9;
L_806E83CC:
    // 0x806E83CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806E83D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806E83D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806E83D8: jr          $ra
    // 0x806E83DC: nop

    return;
    // 0x806E83DC: nop

;}
RECOMP_FUNC void func_8042A224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042A224: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8042A228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042A22C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042A230: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042A234: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8042A238: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8042A23C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8042A240: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8042A244: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8042A248: lw          $t8, 0x1F4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1F4);
    // 0x8042A24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042A250: jal         0x8004921C
    // 0x8042A254: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8042A254: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    after_0:
    // 0x8042A258: sh          $v0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r2;
    // 0x8042A25C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8042A260: jal         0x8004921C
    // 0x8042A264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8042A264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8042A268: lbu         $t0, 0x25($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X25);
    // 0x8042A26C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8042A270: lbu         $t2, 0x145($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X145);
    // 0x8042A274: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042A278: lw          $v1, 0x168($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X168);
    // 0x8042A27C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8042A280: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8042A284: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x8042A288: lw          $a3, 0x88($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X88);
    // 0x8042A28C: mflo        $t1
    ctx->r9 = lo;
    // 0x8042A290: nop

    // 0x8042A294: nop

    // 0x8042A298: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8042A29C: mflo        $t3
    ctx->r11 = lo;
    // 0x8042A2A0: addu        $a2, $t3, $t4
    ctx->r6 = ADD32(ctx->r11, ctx->r12);
    // 0x8042A2A4: jal         0x8042A090
    // 0x8042A2A8: nop

    func_8042A090(rdram, ctx);
        goto after_2;
    // 0x8042A2A8: nop

    after_2:
    // 0x8042A2AC: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x8042A2B0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8042A2B4: sh          $t6, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r14;
    // 0x8042A2B8: lh          $t7, 0x1C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1C);
    // 0x8042A2BC: slti        $at, $t7, 0x3
    ctx->r1 = SIGNED(ctx->r15) < 0X3 ? 1 : 0;
    // 0x8042A2C0: bnel        $at, $zero, L_8042A2D0
    if (ctx->r1 != 0) {
        // 0x8042A2C4: lw          $t8, 0x2C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X2C);
            goto L_8042A2D0;
    }
    goto skip_0;
    // 0x8042A2C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8042A2C8: sh          $zero, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = 0;
    // 0x8042A2CC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
L_8042A2D0:
    // 0x8042A2D0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8042A2D4: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x8042A2D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042A2DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042A2E0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042A2E4: jr          $ra
    // 0x8042A2E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8042A2E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8073FB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FB70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073FB74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073FB78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073FB7C: jal         0x8073F438
    // 0x8073FB80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8073F438(rdram, ctx);
        goto after_0;
    // 0x8073FB80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8073FB84: jal         0x8073F688
    // 0x8073FB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F688(rdram, ctx);
        goto after_1;
    // 0x8073FB88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073FB8C: jal         0x8073F98C
    // 0x8073FB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F98C(rdram, ctx);
        goto after_2;
    // 0x8073FB90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8073FB94: jal         0x8073F760
    // 0x8073FB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F760(rdram, ctx);
        goto after_3;
    // 0x8073FB98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073FB9C: jal         0x8073F2FC
    // 0x8073FBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F2FC(rdram, ctx);
        goto after_4;
    // 0x8073FBA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073FBA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073FBA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073FBAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073FBB0: jr          $ra
    // 0x8073FBB4: nop

    return;
    // 0x8073FBB4: nop

;}
RECOMP_FUNC void func_80079134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079134: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80079138: jr          $ra
    // 0x8007913C: nop

    return;
    // 0x8007913C: nop

;}
RECOMP_FUNC void func_80705270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80705270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80705274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80705278: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8070527C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80705280: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80705284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80705288: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8070528C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80705290: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80705294: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80705298: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8070529C: bc1fl       L_807052C4
    if (!c1cs) {
        // 0x807052A0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_807052C4;
    }
    goto skip_0;
    // 0x807052A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x807052A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807052A8: nop

    // 0x807052AC: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x807052B0: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x807052B4: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x807052B8: b           L_807052CC
    // 0x807052BC: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
        goto L_807052CC;
    // 0x807052BC: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x807052C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_807052C4:
    // 0x807052C4: nop

    // 0x807052C8: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
L_807052CC:
    // 0x807052CC: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x807052D0: beq         $v0, $zero, L_807052DC
    if (ctx->r2 == 0) {
        // 0x807052D4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807052DC;
    }
    // 0x807052D4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807052D8: sw          $t6, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r14;
L_807052DC:
    // 0x807052DC: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x807052E0: beq         $v0, $zero, L_807052EC
    if (ctx->r2 == 0) {
        // 0x807052E4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_807052EC;
    }
    // 0x807052E4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x807052E8: sw          $t7, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r15;
L_807052EC:
    // 0x807052EC: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x807052F0: bnel        $t8, $zero, L_80705418
    if (ctx->r24 != 0) {
        // 0x807052F4: addiu       $a3, $s0, 0xC4
        ctx->r7 = ADD32(ctx->r16, 0XC4);
            goto L_80705418;
    }
    goto skip_1;
    // 0x807052F4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    skip_1:
    // 0x807052F8: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x807052FC: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(709, 0X3680) << 16);
    // 0x80705300: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80705304: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80705308: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8070530C: lw          $t0, 0x6AF0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(709, 0X3680));
    // 0x80705310: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80705314: sw          $a2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r6;
    // 0x80705318: beq         $at, $zero, L_80705330
    if (ctx->r1 == 0) {
        // 0x8070531C: sw          $t0, 0x28($v1)
        MEM_W(0X28, ctx->r3) = ctx->r8;
            goto L_80705330;
    }
    // 0x8070531C: sw          $t0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r8;
    // 0x80705320: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80705324: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
    // 0x80705328: b           L_80705354
    // 0x8070532C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_80705354;
    // 0x8070532C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_80705330:
    // 0x80705330: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x80705334: beql        $t2, $zero, L_80705358
    if (ctx->r10 == 0) {
        // 0x80705338: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80705358;
    }
    goto skip_2;
    // 0x80705338: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_2:
    // 0x8070533C: lw          $t3, 0x40($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X40);
    // 0x80705340: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80705344: bnel        $t3, $zero, L_80705358
    if (ctx->r11 != 0) {
        // 0x80705348: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80705358;
    }
    goto skip_3;
    // 0x80705348: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_3:
    // 0x8070534C: sw          $t4, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r12;
    // 0x80705350: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_80705354:
    // 0x80705354: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_80705358:
    // 0x80705358: bnel        $v0, $at, L_807053E0
    if (ctx->r2 != ctx->r1) {
        // 0x8070535C: slti        $at, $v0, 0x16
        ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
            goto L_807053E0;
    }
    goto skip_4;
    // 0x8070535C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    skip_4:
    // 0x80705360: lw          $t5, 0x44($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X44);
    // 0x80705364: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x80705368: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3730) << 16);
    // 0x8070536C: bnel        $t5, $zero, L_807053E0
    if (ctx->r13 != 0) {
        // 0x80705370: slti        $at, $v0, 0x16
        ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
            goto L_807053E0;
    }
    goto skip_5;
    // 0x80705370: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    skip_5:
    // 0x80705374: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x80705378: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8070537C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80705380: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80705384: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80705388: lwc1        $f16, 0x6BA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3730));
    // 0x8070538C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80705390: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80705394: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80705398: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8070539C: swc1        $f18, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f18.u32l;
    // 0x807053A0: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x807053A4: swc1        $f4, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f4.u32l;
    // 0x807053A8: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x807053AC: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x807053B0: sw          $a2, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r6;
    // 0x807053B4: sw          $t8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r24;
    // 0x807053B8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x807053BC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x807053C0: jal         0x80067BBC
    // 0x807053C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x807053C4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x807053C8: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x807053CC: jal         0x80067818
    // 0x807053D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x807053D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807053D4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x807053D8: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x807053DC: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
L_807053E0:
    // 0x807053E0: bne         $at, $zero, L_80705414
    if (ctx->r1 != 0) {
        // 0x807053E4: addiu       $a3, $s0, 0xC4
        ctx->r7 = ADD32(ctx->r16, 0XC4);
            goto L_80705414;
    }
    // 0x807053E4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x807053E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807053EC: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x807053F0: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x807053F4: sw          $zero, 0x40($v1)
    MEM_W(0X40, ctx->r3) = 0;
    // 0x807053F8: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x807053FC: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    // 0x80705400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80705404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80705408: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8070540C: jal         0x80705A5C
    // 0x80705410: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_80705A5C(rdram, ctx);
        goto after_2;
    // 0x80705410: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_2:
L_80705414:
    // 0x80705414: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
L_80705418:
    // 0x80705418: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8070541C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80705420: jal         0x80048F84
    // 0x80705424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x80705424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80705428: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8070542C: jal         0x80048F84
    // 0x80705430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x80705430: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80705434: jal         0x8070384C
    // 0x80705438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8070384C(rdram, ctx);
        goto after_5;
    // 0x80705438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8070543C: jal         0x80703F10
    // 0x80705440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80703F10(rdram, ctx);
        goto after_6;
    // 0x80705440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80705444: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80705448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8070544C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80705450: jr          $ra
    // 0x80705454: nop

    return;
    // 0x80705454: nop

;}
RECOMP_FUNC void func_80465D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465D08: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465D0C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80465D10: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x80465D14: addiu       $a1, $v0, 0x2018
    ctx->r5 = ADD32(ctx->r2, 0X2018);
    // 0x80465D18: addiu       $a2, $v0, 0x2818
    ctx->r6 = ADD32(ctx->r2, 0X2818);
    // 0x80465D1C: addiu       $v0, $zero, 0x3C0
    ctx->r2 = ADD32(0, 0X3C0);
    // 0x80465D20: addiu       $t4, $zero, 0x1C0
    ctx->r12 = ADD32(0, 0X1C0);
    // 0x80465D24: addiu       $t3, $zero, 0x9B
    ctx->r11 = ADD32(0, 0X9B);
    // 0x80465D28: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80465D2C: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80465D30: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x80465D34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80465D38:
    // 0x80465D38: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80465D3C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80465D40: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80465D44: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x80465D48: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x80465D4C: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x80465D50: sb          $a0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r4;
    // 0x80465D54: sb          $a0, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r4;
    // 0x80465D58: sb          $a3, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r7;
    // 0x80465D5C: sb          $t0, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r8;
    // 0x80465D60: sb          $t0, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r8;
    // 0x80465D64: sb          $a3, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r7;
    // 0x80465D68: sb          $a0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r4;
    // 0x80465D6C: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
    // 0x80465D70: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // 0x80465D74: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80465D78: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80465D7C: sh          $zero, 0x4($a2)
    MEM_H(0X4, ctx->r6) = 0;
    // 0x80465D80: sh          $zero, 0x2($a2)
    MEM_H(0X2, ctx->r6) = 0;
    // 0x80465D84: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80465D88: sb          $t3, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r11;
    // 0x80465D8C: sb          $a3, 0x1E($a1)
    MEM_B(0X1E, ctx->r5) = ctx->r7;
    // 0x80465D90: sb          $t2, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r10;
    // 0x80465D94: sb          $t2, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r10;
    // 0x80465D98: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x80465D9C: sh          $zero, 0x18($a1)
    MEM_H(0X18, ctx->r5) = 0;
    // 0x80465DA0: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
    // 0x80465DA4: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x80465DA8: sh          $t1, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r9;
    // 0x80465DAC: sh          $zero, 0x10($a1)
    MEM_H(0X10, ctx->r5) = 0;
    // 0x80465DB0: sb          $t3, 0x1F($a2)
    MEM_B(0X1F, ctx->r6) = ctx->r11;
    // 0x80465DB4: sb          $a3, 0x1E($a2)
    MEM_B(0X1E, ctx->r6) = ctx->r7;
    // 0x80465DB8: sb          $t2, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r10;
    // 0x80465DBC: sb          $t2, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r10;
    // 0x80465DC0: sh          $zero, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = 0;
    // 0x80465DC4: sh          $zero, 0x18($a2)
    MEM_H(0X18, ctx->r6) = 0;
    // 0x80465DC8: sh          $zero, 0x16($a2)
    MEM_H(0X16, ctx->r6) = 0;
    // 0x80465DCC: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x80465DD0: sh          $t1, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r9;
    // 0x80465DD4: sh          $zero, 0x10($a2)
    MEM_H(0X10, ctx->r6) = 0;
    // 0x80465DD8: sb          $t3, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r11;
    // 0x80465DDC: sb          $a3, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = ctx->r7;
    // 0x80465DE0: sb          $t2, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r10;
    // 0x80465DE4: sb          $t2, 0x2C($a1)
    MEM_B(0X2C, ctx->r5) = ctx->r10;
    // 0x80465DE8: sh          $zero, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = 0;
    // 0x80465DEC: sh          $t4, 0x28($a1)
    MEM_H(0X28, ctx->r5) = ctx->r12;
    // 0x80465DF0: sh          $zero, 0x26($a1)
    MEM_H(0X26, ctx->r5) = 0;
    // 0x80465DF4: sh          $zero, 0x24($a1)
    MEM_H(0X24, ctx->r5) = 0;
    // 0x80465DF8: sh          $t1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r9;
    // 0x80465DFC: sh          $t1, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r9;
    // 0x80465E00: sb          $t3, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r11;
    // 0x80465E04: sb          $a3, 0x2E($a2)
    MEM_B(0X2E, ctx->r6) = ctx->r7;
    // 0x80465E08: sb          $t2, 0x2D($a2)
    MEM_B(0X2D, ctx->r6) = ctx->r10;
    // 0x80465E0C: sb          $t2, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r10;
    // 0x80465E10: sh          $zero, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = 0;
    // 0x80465E14: sh          $t4, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r12;
    // 0x80465E18: sh          $zero, 0x26($a2)
    MEM_H(0X26, ctx->r6) = 0;
    // 0x80465E1C: sh          $zero, 0x24($a2)
    MEM_H(0X24, ctx->r6) = 0;
    // 0x80465E20: sh          $t1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r9;
    // 0x80465E24: sh          $t1, 0x20($a2)
    MEM_H(0X20, ctx->r6) = ctx->r9;
    // 0x80465E28: sb          $t0, 0x3F($a1)
    MEM_B(0X3F, ctx->r5) = ctx->r8;
    // 0x80465E2C: sb          $a3, 0x3E($a1)
    MEM_B(0X3E, ctx->r5) = ctx->r7;
    // 0x80465E30: sb          $a0, 0x3D($a1)
    MEM_B(0X3D, ctx->r5) = ctx->r4;
    // 0x80465E34: sb          $a0, 0x3C($a1)
    MEM_B(0X3C, ctx->r5) = ctx->r4;
    // 0x80465E38: sh          $v0, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r2;
    // 0x80465E3C: sh          $t4, 0x38($a1)
    MEM_H(0X38, ctx->r5) = ctx->r12;
    // 0x80465E40: sh          $zero, 0x36($a1)
    MEM_H(0X36, ctx->r5) = 0;
    // 0x80465E44: sh          $zero, 0x34($a1)
    MEM_H(0X34, ctx->r5) = 0;
    // 0x80465E48: sh          $zero, 0x32($a1)
    MEM_H(0X32, ctx->r5) = 0;
    // 0x80465E4C: sh          $t1, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r9;
    // 0x80465E50: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80465E54: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
    // 0x80465E58: addiu       $a2, $a2, -0x40
    ctx->r6 = ADD32(ctx->r6, -0X40);
    // 0x80465E5C: sb          $t0, 0x7F($a2)
    MEM_B(0X7F, ctx->r6) = ctx->r8;
    // 0x80465E60: sb          $a3, 0x7E($a2)
    MEM_B(0X7E, ctx->r6) = ctx->r7;
    // 0x80465E64: sb          $a0, 0x7D($a2)
    MEM_B(0X7D, ctx->r6) = ctx->r4;
    // 0x80465E68: sb          $a0, 0x7C($a2)
    MEM_B(0X7C, ctx->r6) = ctx->r4;
    // 0x80465E6C: sh          $v0, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r2;
    // 0x80465E70: sh          $t4, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r12;
    // 0x80465E74: sh          $zero, 0x76($a2)
    MEM_H(0X76, ctx->r6) = 0;
    // 0x80465E78: sh          $zero, 0x74($a2)
    MEM_H(0X74, ctx->r6) = 0;
    // 0x80465E7C: sh          $zero, 0x72($a2)
    MEM_H(0X72, ctx->r6) = 0;
    // 0x80465E80: bgez        $v1, L_80465D38
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80465E84: sh          $t1, 0x70($a2)
        MEM_H(0X70, ctx->r6) = ctx->r9;
            goto L_80465D38;
    }
    // 0x80465E84: sh          $t1, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r9;
    // 0x80465E88: jr          $ra
    // 0x80465E8C: nop

    return;
    // 0x80465E8C: nop

;}
RECOMP_FUNC void func_800727EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800727F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800727F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800727F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800727FC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80072800: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80072804: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80072808: addiu       $a0, $a0, -0x59E0
    ctx->r4 = ADD32(ctx->r4, -0X59E0);
    // 0x8007280C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80072810: jal         0x80082210
    // 0x80072814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072814: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80072818: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8007281C: addiu       $s0, $s0, -0x5948
    ctx->r16 = ADD32(ctx->r16, -0X5948);
    // 0x80072820: addiu       $s1, $sp, 0x24
    ctx->r17 = ADD32(ctx->r29, 0X24);
    // 0x80072824: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80072828:
    // 0x80072828: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8007282C: jal         0x800824B0
    // 0x80072830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80072830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80072834: jal         0x800726C0
    // 0x80072838: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_800726C0(rdram, ctx);
        goto after_2;
    // 0x80072838: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8007283C: b           L_80072828
    // 0x80072840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80072828;
    // 0x80072840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80072844: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80072848: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007284C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80072850: jr          $ra
    // 0x80072854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80072854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8003C3C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C3C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003C3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C3C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8003C3CC: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8003C3D0: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8003C3D4: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8003C3D8: lwc1        $f8, 0x88($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8003C3DC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003C3E0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003C3E4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003C3E8: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8003C3EC: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x8003C3F0: jal         0x80081E8C
    // 0x8003C3F4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    fatan2(rdram, ctx);
        goto after_0;
    // 0x8003C3F4: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8003C3F8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003C3FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003C400: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003C404: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8003C408: mul.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8003C40C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8003C410: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003C414: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C418: lwc1        $f6, 0x1E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1E8);
    // 0x8003C41C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8003C420: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003C424: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x8003C428: div.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003C42C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003C430: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8003C434: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8003C438: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    // 0x8003C43C: beql        $t6, $zero, L_8003C450
    if (ctx->r14 == 0) {
        // 0x8003C440: lwc1        $f4, 0x98($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X98);
            goto L_8003C450;
    }
    goto skip_0;
    // 0x8003C440: lwc1        $f4, 0x98($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X98);
    skip_0:
    // 0x8003C444: b           L_8003C454
    // 0x8003C448: lwc1        $f16, 0x98($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X98);
        goto L_8003C454;
    // 0x8003C448: lwc1        $f16, 0x98($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X98);
    // 0x8003C44C: lwc1        $f4, 0x98($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X98);
L_8003C450:
    // 0x8003C450: add.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f14.fl;
L_8003C454:
    // 0x8003C454: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8003C458: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C45C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003C460: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8003C464: nop

    // 0x8003C468: bc1fl       L_8003C490
    if (!c1cs) {
        // 0x8003C46C: c.lt.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
            goto L_8003C490;
    }
    goto skip_1;
    // 0x8003C46C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    skip_1:
    // 0x8003C470: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003C474: nop

    // 0x8003C478: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
L_8003C47C:
    // 0x8003C47C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8003C480: nop

    // 0x8003C484: bc1tl       L_8003C47C
    if (c1cs) {
        // 0x8003C488: add.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
            goto L_8003C47C;
    }
    goto skip_2;
    // 0x8003C488: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    skip_2:
    // 0x8003C48C: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
L_8003C490:
    // 0x8003C490: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003C494: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003C498: bc1f        L_8003C4B4
    if (!c1cs) {
        // 0x8003C49C: nop
    
            goto L_8003C4B4;
    }
    // 0x8003C49C: nop

    // 0x8003C4A0: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_8003C4A4:
    // 0x8003C4A4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8003C4A8: nop

    // 0x8003C4AC: bc1tl       L_8003C4A4
    if (c1cs) {
        // 0x8003C4B0: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8003C4A4;
    }
    goto skip_3;
    // 0x8003C4B0: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    skip_3:
L_8003C4B4:
    // 0x8003C4B4: jal         0x80065954
    // 0x8003C4B8: nop

    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8003C4B8: nop

    after_1:
    // 0x8003C4BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8003C4C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C4C4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8003C4C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003C4CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8003C4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C4D4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8003C4D8: bc1f        L_8003C4E4
    if (!c1cs) {
        // 0x8003C4DC: nop
    
            goto L_8003C4E4;
    }
    // 0x8003C4DC: nop

    // 0x8003C4E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003C4E4:
    // 0x8003C4E4: bne         $v0, $zero, L_8003C508
    if (ctx->r2 != 0) {
        // 0x8003C4E8: nop
    
            goto L_8003C508;
    }
    // 0x8003C4E8: nop

    // 0x8003C4EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003C4F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003C4F4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8003C4F8: nop

    // 0x8003C4FC: bc1f        L_8003C508
    if (!c1cs) {
        // 0x8003C500: nop
    
            goto L_8003C508;
    }
    // 0x8003C500: nop

    // 0x8003C504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003C508:
    // 0x8003C508: jr          $ra
    // 0x8003C50C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8003C50C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8067BF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BF0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067BF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067BF14: jal         0x80679E10
    // 0x8067BF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80679E10(rdram, ctx);
        goto after_0;
    // 0x8067BF18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067BF1C: jal         0x80045BD8
    // 0x8067BF20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8067BF20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8067BF24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067BF28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067BF2C: jr          $ra
    // 0x8067BF30: nop

    return;
    // 0x8067BF30: nop

;}
RECOMP_FUNC void func_80451F38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451F38: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80451F3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80451F40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80451F44: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80451F48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80451F4C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451F50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80451F54: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80451F58: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80451F5C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x80451F60: lui         $at, 0x4425
    ctx->r1 = S32(0X4425 << 16);
    // 0x80451F64: bc1fl       L_80451FC0
    if (!c1cs) {
        // 0x80451F68: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80451FC0;
    }
    goto skip_0;
    // 0x80451F68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_0:
    // 0x80451F6C: jal         0x80450760
    // 0x80451F70: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80450760(rdram, ctx);
        goto after_0;
    // 0x80451F70: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80451F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451F78: jal         0x80450B18
    // 0x80451F7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80451F7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80451F80: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80451F84: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451F8C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80451F90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80451F94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80451F98: lwc1        $f6, 0x6F10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x80451F9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80451FA0: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80451FA4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80451FA8: swc1        $f10, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f10.u32l;
    // 0x80451FAC: jal         0x8044E9C0
    // 0x80451FB0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_2;
    // 0x80451FB0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_2:
    // 0x80451FB4: b           L_80452144
    // 0x80451FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80452144;
    // 0x80451FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80451FBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80451FC0:
    // 0x80451FC0: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80451FC4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80451FC8: nop

    // 0x80451FCC: bc1fl       L_80452040
    if (!c1cs) {
        // 0x80451FD0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80452040;
    }
    goto skip_1;
    // 0x80451FD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80451FD4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451FD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80451FDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80451FE0: beq         $t6, $at, L_80452004
    if (ctx->r14 == ctx->r1) {
        // 0x80451FE4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80452004;
    }
    // 0x80451FE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451FE8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80451FEC: jal         0x80450B18
    // 0x80451FF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451FF0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x80451FF4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80451FF8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80451FFC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80452000: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80452004:
    // 0x80452004: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452008: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8045200C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80452014: lwc1        $f18, 0x6F10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x80452018: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045201C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80452020: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80452024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452028: swc1        $f6, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f6.u32l;
    // 0x8045202C: jal         0x8044E9C0
    // 0x80452030: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_4;
    // 0x80452030: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_4:
    // 0x80452034: b           L_80452144
    // 0x80452038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80452144;
    // 0x80452038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045203C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80452040:
    // 0x80452040: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80452044: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80452048: nop

    // 0x8045204C: bc1fl       L_804520C0
    if (!c1cs) {
        // 0x80452050: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_804520C0;
    }
    goto skip_2;
    // 0x80452050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_2:
    // 0x80452054: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80452058: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8045205C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452060: beq         $t8, $at, L_80452084
    if (ctx->r24 == ctx->r1) {
        // 0x80452064: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80452084;
    }
    // 0x80452064: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80452068: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8045206C: jal         0x80450B18
    // 0x80452070: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80452070: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_5:
    // 0x80452074: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80452078: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8045207C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80452080: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80452084:
    // 0x80452084: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452088: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x8045208C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452090: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80452094: lwc1        $f10, 0x6F10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6F10);
    // 0x80452098: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045209C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x804520A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804520A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804520A8: swc1        $f18, 0x6F10($at)
    MEM_W(0X6F10, ctx->r1) = ctx->f18.u32l;
    // 0x804520AC: jal         0x8044E9C0
    // 0x804520B0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    func_8044E9C0(rdram, ctx);
        goto after_6;
    // 0x804520B0: lw          $a1, 0x6F10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X6F10);
    after_6:
    // 0x804520B4: b           L_80452144
    // 0x804520B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80452144;
    // 0x804520B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804520BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_804520C0:
    // 0x804520C0: nop

    // 0x804520C4: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x804520C8: nop

    // 0x804520CC: bc1fl       L_80452104
    if (!c1cs) {
        // 0x804520D0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80452104;
    }
    goto skip_3;
    // 0x804520D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_3:
    // 0x804520D4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x804520D8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804520DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804520E0: beq         $t0, $at, L_80452140
    if (ctx->r8 == ctx->r1) {
        // 0x804520E4: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_80452140;
    }
    // 0x804520E4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804520E8: jal         0x80450B18
    // 0x804520EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x804520EC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_7:
    // 0x804520F0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x804520F4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x804520F8: b           L_80452140
    // 0x804520FC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
        goto L_80452140;
    // 0x804520FC: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80452100: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80452104:
    // 0x80452104: nop

    // 0x80452108: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8045210C: nop

    // 0x80452110: bc1fl       L_80452144
    if (!c1cs) {
        // 0x80452114: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80452144;
    }
    goto skip_4;
    // 0x80452114: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80452118: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8045211C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80452120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80452124: beq         $t2, $at, L_80452140
    if (ctx->r10 == ctx->r1) {
        // 0x80452128: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80452140;
    }
    // 0x80452128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045212C: jal         0x80450B18
    // 0x80452130: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_8;
    // 0x80452130: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_8:
    // 0x80452134: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80452138: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8045213C: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_80452140:
    // 0x80452140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80452144:
    // 0x80452144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80452148: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8045214C: jr          $ra
    // 0x80452150: nop

    return;
    // 0x80452150: nop

;}
RECOMP_FUNC void func_806F1DC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1DC4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F1DC8: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0X674) << 16);
    // 0x806F1DCC: addiu       $t6, $t6, 0x1BF4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0X674));
    // 0x806F1DD0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F1DD4: jr          $ra
    // 0x806F1DD8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806F1DD8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_805A5440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A5444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5448: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x805A544C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805A5450: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805A5454: beq         $a1, $at, L_805A5470
    if (ctx->r5 == ctx->r1) {
        // 0x805A5458: addiu       $a0, $zero, 0x38
        ctx->r4 = ADD32(0, 0X38);
            goto L_805A5470;
    }
    // 0x805A5458: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x805A545C: jal         0x80067878
    // 0x805A5460: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x805A5460: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x805A5464: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805A5468: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805A546C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_805A5470:
    // 0x805A5470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A5474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A5478: jr          $ra
    // 0x805A547C: nop

    return;
    // 0x805A547C: nop

;}
RECOMP_FUNC void func_8004CEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004CEF8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004CEFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004CF00: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004CF04: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004CF08: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004CF0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004CF10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004CF14: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004CF18: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004CF1C: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004CF20: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8004CF24: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8004CF28: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x8004CF2C: jal         0x8004B3F8
    // 0x8004CF30: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004B3F8(rdram, ctx);
        goto after_0;
    // 0x8004CF30: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8004CF34: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004CF38: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004CF3C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8004CF40: swc1        $f8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f8.u32l;
    // 0x8004CF44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004CF48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004CF4C: jr          $ra
    // 0x8004CF50: nop

    return;
    // 0x8004CF50: nop

;}
RECOMP_FUNC void func_8073A1D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073A1D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073A1D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073A1D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8073A1DC: jal         0x80064E84
    // 0x8073A1E0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8073A1E0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8073A1E4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8073A1E8: jal         0x80064E84
    // 0x8073A1EC: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8073A1EC: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x8073A1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073A1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073A1F8: jr          $ra
    // 0x8073A1FC: nop

    return;
    // 0x8073A1FC: nop

;}
RECOMP_FUNC void func_8067E720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E720: jr          $ra
    // 0x8067E724: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8067E724: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8045BE24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BE24: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045BE28: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x8045BE2C: srl         $a3, $a1, 1
    ctx->r7 = S32(U32(ctx->r5) >> 1);
    // 0x8045BE30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045BE34: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8045BE38: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8045BE3C: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8045BE40: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x8045BE44: beq         $a3, $zero, L_8045BE84
    if (ctx->r7 == 0) {
        // 0x8045BE48: sw          $a1, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r5;
            goto L_8045BE84;
    }
    // 0x8045BE48: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x8045BE4C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045BE50: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045BE54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BE58: nop

L_8045BE5C:
    // 0x8045BE5C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8045BE60: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8045BE64: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8045BE68: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x8045BE6C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8045BE70: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8045BE74: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8045BE78: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8045BE7C: bne         $at, $zero, L_8045BE5C
    if (ctx->r1 != 0) {
        // 0x8045BE80: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8045BE5C;
    }
    // 0x8045BE80: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8045BE84:
    // 0x8045BE84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BE88: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22A8) << 16);
    // 0x8045BE8C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8045BE90: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x8045BE94: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8045BE98: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8045BE9C: lwc1        $f4, -0x24C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22A8));
    // 0x8045BEA0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22AC) << 16);
    // 0x8045BEA4: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x8045BEA8: lwc1        $f6, -0x24C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22AC));
    // 0x8045BEAC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8045BEB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8045BEB4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22B0) << 16);
    // 0x8045BEB8: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8045BEBC: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x8045BEC0: lwc1        $f10, -0x24C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22B0));
    // 0x8045BEC4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8045BEC8: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x8045BECC: jr          $ra
    // 0x8045BED0: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8045BED0: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_804386DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804386DC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804386E0: lui         $t6, 0x8044
    ctx->r14 = S32(RELOC_HI16(77, 0X1DF0) << 16);
    // 0x804386E4: addiu       $t6, $t6, -0x7970
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(77, 0X1DF0));
    // 0x804386E8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804386EC: jr          $ra
    // 0x804386F0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804386F0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806E3D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E3D64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806E3D68: nop

    // 0x806E3D6C: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x806E3D70: jr          $ra
    // 0x806E3D74: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x806E3D74: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_80025334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025334: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80025338: addiu       $t6, $t6, 0x50FC
    ctx->r14 = ADD32(ctx->r14, 0X50FC);
    // 0x8002533C: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80025340: jr          $ra
    // 0x80025344: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x80025344: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_800244DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800244DC: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x800244E0: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800244E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800244E8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800244EC: addiu       $t7, $t7, -0x6220
    ctx->r15 = ADD32(ctx->r15, -0X6220);
    // 0x800244F0: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800244F4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800244F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800244FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80024500: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80024504: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80024508: sll         $t9, $a3, 7
    ctx->r25 = S32(ctx->r7 << 7);
    // 0x8002450C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80024510: addu        $a1, $t9, $a1
    ctx->r5 = ADD32(ctx->r25, ctx->r5);
    // 0x80024514: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80024518: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8002451C: jal         0x800655F4
    // 0x80024520: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_800655F4(rdram, ctx);
        goto after_0;
    // 0x80024520: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80024524: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80024528: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x8002452C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80024530: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x80024534: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80024538: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8002453C: sw          $t1, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r9;
    // 0x80024540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80024544: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024548: jr          $ra
    // 0x8002454C: nop

    return;
    // 0x8002454C: nop

;}
RECOMP_FUNC void func_8043280C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043280C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80432810: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80432814: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80432818: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8043281C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80432820: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(62, 0X590) << 16);
    // 0x80432824: lwc1        $f0, 0x2D30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(62, 0X590));
    // 0x80432828: addiu       $t7, $t6, 0xD
    ctx->r15 = ADD32(ctx->r14, 0XD);
    // 0x8043282C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80432830: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80432834: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80432838: lwc1        $f16, 0xE0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x8043283C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80432840: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80432844: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80432848: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043284C: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80432850: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x80432854: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x80432858: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8043285C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80432860: nop

    // 0x80432864: bc1t        L_8043287C
    if (c1cs) {
        // 0x80432868: nop
    
            goto L_8043287C;
    }
    // 0x80432868: nop

    // 0x8043286C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80432870: lwc1        $f8, 0x28($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80432874: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80432878: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8043287C:
    // 0x8043287C: jal         0x804327B0
    // 0x80432880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804327B0(rdram, ctx);
        goto after_0;
    // 0x80432880: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80432884: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(62, 0X594) << 16);
    // 0x80432888: lwc1        $f0, 0x2D34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(62, 0X594));
    // 0x8043288C: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80432890: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80432894: lh          $v0, 0x144($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X144);
    // 0x80432898: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8043289C: addiu       $s1, $s0, 0xC4
    ctx->r17 = ADD32(ctx->r16, 0XC4);
    // 0x804328A0: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x804328A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804328A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804328AC: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x804328B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804328B4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x804328B8: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x804328BC: bne         $at, $zero, L_804328C8
    if (ctx->r1 != 0) {
        // 0x804328C0: swc1        $f6, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
            goto L_804328C8;
    }
    // 0x804328C0: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x804328C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_804328C8:
    // 0x804328C8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x804328CC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x804328D0: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x804328D4: sb          $t9, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r25;
    // 0x804328D8: lbu         $t1, 0x30($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X30);
    // 0x804328DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804328E0: bne         $t1, $at, L_804328F8
    if (ctx->r9 != ctx->r1) {
        // 0x804328E4: nop
    
            goto L_804328F8;
    }
    // 0x804328E4: nop

    // 0x804328E8: lh          $t2, 0x144($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X144);
    // 0x804328EC: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x804328F0: bnel        $t2, $at, L_8043294C
    if (ctx->r10 != ctx->r1) {
        // 0x804328F4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8043294C;
    }
    goto skip_0;
    // 0x804328F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_804328F8:
    // 0x804328F8: jal         0x80048378
    // 0x804328FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804328FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80432900: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80432904: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80432908: sb          $t3, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r11;
    // 0x8043290C: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x80432910: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80432914: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80432918: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8043291C: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    // 0x80432920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80432924: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80432928: jal         0x80432B00
    // 0x8043292C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80432B00(rdram, ctx);
        goto after_2;
    // 0x8043292C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80432930: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x80432934: jal         0x8005FB2C
    // 0x80432938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FB2C(rdram, ctx);
        goto after_3;
    // 0x80432938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8043293C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80432940: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80432944: sb          $t4, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r12;
    // 0x80432948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043294C:
    // 0x8043294C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80432950: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80432954: jr          $ra
    // 0x80432958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80432958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8001A028(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A028: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001A02C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001A030: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8001A034: addiu       $s6, $s6, 0x590
    ctx->r22 = ADD32(ctx->r22, 0X590);
    // 0x8001A038: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A03C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001A040: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001A044: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001A048: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001A04C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001A050: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001A054: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001A058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001A05C: jal         0x8001A568
    // 0x8001A060: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    func_8001A568(rdram, ctx);
        goto after_0;
    // 0x8001A060: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    after_0:
    // 0x8001A064: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x8001A068: addiu       $s2, $s2, 0x4D10
    ctx->r18 = ADD32(ctx->r18, 0X4D10);
    // 0x8001A06C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001A070: addiu       $fp, $zero, 0x7
    ctx->r30 = ADD32(0, 0X7);
    // 0x8001A074: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x8001A078: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001A07C: addiu       $s3, $zero, 0x160
    ctx->r19 = ADD32(0, 0X160);
    // 0x8001A080: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
L_8001A084:
    // 0x8001A084: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x8001A088: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001A08C: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
    // 0x8001A090: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001A094: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8001A098: jal         0x8001ABE0
    // 0x8001A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001ABE0(rdram, ctx);
        goto after_1;
    // 0x8001A09C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8001A0A0: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x8001A0A4: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x8001A0A8: beq         $at, $zero, L_8001A2EC
    if (ctx->r1 == 0) {
        // 0x8001A0AC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8001A2EC;
    }
    // 0x8001A0AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001A0B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001A0B4: addu        $at, $at, $t8
    gpr jr_addend_8001A0BC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8001A0B8: lw          $t8, -0x68C($at)
    ctx->r24 = ADD32(ctx->r1, -0X68C);
    // 0x8001A0BC: jr          $t8
    // 0x8001A0C0: nop

    switch (jr_addend_8001A0BC >> 2) {
        case 0: goto L_8001A1AC; break;
        case 1: goto L_8001A124; break;
        case 2: goto L_8001A17C; break;
        case 3: goto L_8001A0C4; break;
        case 4: goto L_8001A25C; break;
        case 5: goto L_8001A2EC; break;
        case 6: goto L_8001A2EC; break;
        case 7: goto L_8001A2EC; break;
        default: switch_error(__func__, 0x8001A0BC, 0x800AF974);
    }
    // 0x8001A0C0: nop

L_8001A0C4:
    // 0x8001A0C4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A0C8: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A0CC: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A0D0: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8001A0D4: lw          $t1, 0x2A30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2A30);
    // 0x8001A0D8: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8001A0DC: bnel        $t2, $zero, L_8001A2F0
    if (ctx->r10 != 0) {
        // 0x8001A0E0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_0;
    // 0x8001A0E0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x8001A0E4: lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8C);
    // 0x8001A0E8: beql        $v1, $zero, L_8001A108
    if (ctx->r3 == 0) {
        // 0x8001A0EC: sw          $fp, 0x84($s0)
        MEM_W(0X84, ctx->r16) = ctx->r30;
            goto L_8001A108;
    }
    goto skip_1;
    // 0x8001A0EC: sw          $fp, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r30;
    skip_1:
    // 0x8001A0F0: bne         $v1, $s5, L_8001A114
    if (ctx->r3 != ctx->r21) {
        // 0x8001A0F4: nop
    
            goto L_8001A114;
    }
    // 0x8001A0F4: nop

    // 0x8001A0F8: sw          $s7, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r23;
    // 0x8001A0FC: b           L_8001A114
    // 0x8001A100: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
        goto L_8001A114;
    // 0x8001A100: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A104: sw          $fp, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r30;
L_8001A108:
    // 0x8001A108: jal         0x80019BE0
    // 0x8001A10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019BE0(rdram, ctx);
        goto after_2;
    // 0x8001A10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001A110: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_8001A114:
    // 0x8001A114: jal         0x8001A4D4
    // 0x8001A118: nop

    func_8001A4D4(rdram, ctx);
        goto after_3;
    // 0x8001A118: nop

    after_3:
    // 0x8001A11C: b           L_8001A2F0
    // 0x8001A120: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8001A2F0;
    // 0x8001A120: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001A124:
    // 0x8001A124: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x8001A128: blez        $v0, L_8001A138
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001A12C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8001A138;
    }
    // 0x8001A12C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8001A130: b           L_8001A2EC
    // 0x8001A134: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
        goto L_8001A2EC;
    // 0x8001A134: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_8001A138:
    // 0x8001A138: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A13C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001A140: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A144: mflo        $t4
    ctx->r12 = lo;
    // 0x8001A148: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8001A14C: lw          $t6, 0x2A30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2A30);
    // 0x8001A150: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8001A154: bnel        $t7, $zero, L_8001A2F0
    if (ctx->r15 != 0) {
        // 0x8001A158: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_2;
    // 0x8001A158: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_2:
    // 0x8001A15C: sw          $t8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r24;
    // 0x8001A160: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8001A164: jal         0x80019D30
    // 0x8001A168: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    func_80019D30(rdram, ctx);
        goto after_4;
    // 0x8001A168: lh          $a2, 0x4($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4);
    after_4:
    // 0x8001A16C: jal         0x8001A3E8
    // 0x8001A170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A3E8(rdram, ctx);
        goto after_5;
    // 0x8001A170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001A174: b           L_8001A2F0
    // 0x8001A178: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8001A2F0;
    // 0x8001A178: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001A17C:
    // 0x8001A17C: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x8001A180: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001A184: multu       $t9, $s3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A188: mflo        $t0
    ctx->r8 = lo;
    // 0x8001A18C: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x8001A190: lw          $t2, 0x2A30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X2A30);
    // 0x8001A194: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8001A198: beql        $t3, $zero, L_8001A2F0
    if (ctx->r11 == 0) {
        // 0x8001A19C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_3;
    // 0x8001A19C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_3:
    // 0x8001A1A0: sw          $s0, 0x590($at)
    MEM_W(0X590, ctx->r1) = ctx->r16;
    // 0x8001A1A4: b           L_8001A2EC
    // 0x8001A1A8: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
        goto L_8001A2EC;
    // 0x8001A1A8: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
L_8001A1AC:
    // 0x8001A1AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A1B0: multu       $a0, $s3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A1B4: mflo        $t4
    ctx->r12 = lo;
    // 0x8001A1B8: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8001A1BC: lw          $t6, 0x2A30($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2A30);
    // 0x8001A1C0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8001A1C4: bnel        $t7, $zero, L_8001A218
    if (ctx->r15 != 0) {
        // 0x8001A1C8: lw          $t8, 0x88($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X88);
            goto L_8001A218;
    }
    goto skip_4;
    // 0x8001A1C8: lw          $t8, 0x88($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X88);
    skip_4:
    // 0x8001A1CC: lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8C);
    // 0x8001A1D0: beql        $v1, $zero, L_8001A1F0
    if (ctx->r3 == 0) {
        // 0x8001A1D4: sw          $fp, 0x84($s0)
        MEM_W(0X84, ctx->r16) = ctx->r30;
            goto L_8001A1F0;
    }
    goto skip_5;
    // 0x8001A1D4: sw          $fp, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r30;
    skip_5:
    // 0x8001A1D8: bne         $v1, $s5, L_8001A1FC
    if (ctx->r3 != ctx->r21) {
        // 0x8001A1DC: nop
    
            goto L_8001A1FC;
    }
    // 0x8001A1DC: nop

    // 0x8001A1E0: sw          $s7, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r23;
    // 0x8001A1E4: b           L_8001A1FC
    // 0x8001A1E8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
        goto L_8001A1FC;
    // 0x8001A1E8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8001A1EC: sw          $fp, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r30;
L_8001A1F0:
    // 0x8001A1F0: jal         0x80019BE0
    // 0x8001A1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019BE0(rdram, ctx);
        goto after_6;
    // 0x8001A1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8001A1F8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_8001A1FC:
    // 0x8001A1FC: jal         0x8001A4D4
    // 0x8001A200: nop

    func_8001A4D4(rdram, ctx);
        goto after_7;
    // 0x8001A200: nop

    after_7:
    // 0x8001A204: jal         0x8001A568
    // 0x8001A208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A568(rdram, ctx);
        goto after_8;
    // 0x8001A208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8001A20C: b           L_8001A2EC
    // 0x8001A210: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
        goto L_8001A2EC;
    // 0x8001A210: sw          $v0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r2;
    // 0x8001A214: lw          $t8, 0x88($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X88);
L_8001A218:
    // 0x8001A218: bnel        $t8, $zero, L_8001A2F0
    if (ctx->r24 != 0) {
        // 0x8001A21C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_6;
    // 0x8001A21C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_6:
    // 0x8001A220: jal         0x8001A5C4
    // 0x8001A224: nop

    func_8001A5C4(rdram, ctx);
        goto after_9;
    // 0x8001A224: nop

    after_9:
    // 0x8001A228: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001A22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001A230: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001A234: mflo        $t9
    ctx->r25 = lo;
    // 0x8001A238: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8001A23C: lw          $t1, 0x2A30($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X2A30);
    // 0x8001A240: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8001A244: beql        $t2, $zero, L_8001A2F0
    if (ctx->r10 == 0) {
        // 0x8001A248: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_7;
    // 0x8001A248: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_7:
    // 0x8001A24C: jal         0x8001A8A0
    // 0x8001A250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001A8A0(rdram, ctx);
        goto after_10;
    // 0x8001A250: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8001A254: b           L_8001A2F0
    // 0x8001A258: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
        goto L_8001A2F0;
    // 0x8001A258: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001A25C:
    // 0x8001A25C: jal         0x8001A73C
    // 0x8001A260: nop

    func_8001A73C(rdram, ctx);
        goto after_11;
    // 0x8001A260: nop

    after_11:
    // 0x8001A264: bnel        $v0, $s0, L_8001A2F0
    if (ctx->r2 != ctx->r16) {
        // 0x8001A268: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_8;
    // 0x8001A268: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_8:
    // 0x8001A26C: jal         0x8001A420
    // 0x8001A270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8001A420(rdram, ctx);
        goto after_12;
    // 0x8001A270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_12:
    // 0x8001A274: lw          $v1, 0x88($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X88);
    // 0x8001A278: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8001A27C: beq         $v1, $zero, L_8001A294
    if (ctx->r3 == 0) {
        // 0x8001A280: nop
    
            goto L_8001A294;
    }
    // 0x8001A280: nop

    // 0x8001A284: beql        $v1, $s5, L_8001A2C0
    if (ctx->r3 == ctx->r21) {
        // 0x8001A288: lh          $t3, 0x0($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X0);
            goto L_8001A2C0;
    }
    goto skip_9;
    // 0x8001A288: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    skip_9:
    // 0x8001A28C: b           L_8001A2CC
    // 0x8001A290: nop

        goto L_8001A2CC;
    // 0x8001A290: nop

L_8001A294:
    // 0x8001A294: jal         0x8001A5A4
    // 0x8001A298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8001A5A4(rdram, ctx);
        goto after_13;
    // 0x8001A298: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8001A29C: bne         $v0, $zero, L_8001A2B4
    if (ctx->r2 != 0) {
        // 0x8001A2A0: sll         $a0, $s5, 16
        ctx->r4 = S32(ctx->r21 << 16);
            goto L_8001A2B4;
    }
    // 0x8001A2A0: sll         $a0, $s5, 16
    ctx->r4 = S32(ctx->r21 << 16);
    // 0x8001A2A4: jal         0x8001A5A4
    // 0x8001A2A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8001A5A4(rdram, ctx);
        goto after_14;
    // 0x8001A2A8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_14:
    // 0x8001A2AC: beq         $v0, $zero, L_8001A2CC
    if (ctx->r2 == 0) {
        // 0x8001A2B0: nop
    
            goto L_8001A2CC;
    }
    // 0x8001A2B0: nop

L_8001A2B4:
    // 0x8001A2B4: b           L_8001A2CC
    // 0x8001A2B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_8001A2CC;
    // 0x8001A2B8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001A2BC: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
L_8001A2C0:
    // 0x8001A2C0: bgez        $t3, L_8001A2CC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8001A2C4: nop
    
            goto L_8001A2CC;
    }
    // 0x8001A2C4: nop

    // 0x8001A2C8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8001A2CC:
    // 0x8001A2CC: bnel        $s1, $zero, L_8001A2F0
    if (ctx->r17 != 0) {
        // 0x8001A2D0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8001A2F0;
    }
    goto skip_10;
    // 0x8001A2D0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_10:
    // 0x8001A2D4: jal         0x8001A46C
    // 0x8001A2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A46C(rdram, ctx);
        goto after_15;
    // 0x8001A2D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8001A2DC: jal         0x8001A6EC
    // 0x8001A2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001A6EC(rdram, ctx);
        goto after_16;
    // 0x8001A2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8001A2E4: sw          $s5, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r21;
    // 0x8001A2E8: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
L_8001A2EC:
    // 0x8001A2EC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_8001A2F0:
    // 0x8001A2F0: andi        $s4, $s4, 0xFFFF
    ctx->r20 = ctx->r20 & 0XFFFF;
    // 0x8001A2F4: slti        $at, $s4, 0xA
    ctx->r1 = SIGNED(ctx->r20) < 0XA ? 1 : 0;
    // 0x8001A2F8: bnel        $at, $zero, L_8001A084
    if (ctx->r1 != 0) {
        // 0x8001A2FC: sll         $t6, $s4, 3
        ctx->r14 = S32(ctx->r20 << 3);
            goto L_8001A084;
    }
    goto skip_11;
    // 0x8001A2FC: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    skip_11:
    // 0x8001A300: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A304: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001A308: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A30C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001A310: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A314: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A318: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A31C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A320: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A324: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A328: jr          $ra
    // 0x8001A32C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8001A32C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8043AC3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AC3C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043AC40: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8043AC44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8043AC48: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8043AC4C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8043AC50: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8043AC54: nop

    // 0x8043AC58: bc1fl       L_8043AC6C
    if (!c1cs) {
        // 0x8043AC5C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8043AC6C;
    }
    goto skip_0;
    // 0x8043AC5C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8043AC60: jr          $ra
    // 0x8043AC64: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    return;
    // 0x8043AC64: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8043AC68: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8043AC6C:
    // 0x8043AC6C: nop

    // 0x8043AC70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8043AC74: nop

    // 0x8043AC78: bc1f        L_8043AC84
    if (!c1cs) {
        // 0x8043AC7C: nop
    
            goto L_8043AC84;
    }
    // 0x8043AC7C: nop

    // 0x8043AC80: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_8043AC84:
    // 0x8043AC84: jr          $ra
    // 0x8043AC88: nop

    return;
    // 0x8043AC88: nop

;}
RECOMP_FUNC void func_807BAA20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BAA20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BAA24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BAA28: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x807BAA2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807BAA30: beq         $t6, $zero, L_807BAA6C
    if (ctx->r14 == 0) {
        // 0x807BAA34: nop
    
            goto L_807BAA6C;
    }
    // 0x807BAA34: nop

    // 0x807BAA38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807BAA3C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x807BAA40: jalr        $t9
    // 0x807BAA44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807BAA44: nop

    after_0:
    // 0x807BAA48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BAA4C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x807BAA50: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x807BAA54: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x807BAA58: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x807BAA5C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x807BAA60: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x807BAA64: b           L_807BAA6C
    // 0x807BAA68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_807BAA6C;
    // 0x807BAA68: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_807BAA6C:
    // 0x807BAA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BAA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BAA74: jr          $ra
    // 0x807BAA78: nop

    return;
    // 0x807BAA78: nop

;}
RECOMP_FUNC void func_80574B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574B44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80574B48: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80574B4C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80574B50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80574B54: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80574B58: lhu         $a1, 0x4($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X4);
    // 0x80574B5C: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80574B60: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x80574B64: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x80574B68: lui         $a0, 0x8057
    ctx->r4 = S32(RELOC_HI16(381, 0X10A0) << 16);
    // 0x80574B6C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80574B70: ori         $a1, $a1, 0x1800
    ctx->r5 = ctx->r5 | 0X1800;
    // 0x80574B74: addiu       $a0, $a0, 0x4F30
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(381, 0X10A0));
    // 0x80574B78: jal         0x80046804
    // 0x80574B7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x80574B7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80574B80: bne         $v0, $zero, L_80574B90
    if (ctx->r2 != 0) {
        // 0x80574B84: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80574B90;
    }
    // 0x80574B84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80574B88: b           L_80574CC0
    // 0x80574B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80574CC0;
    // 0x80574B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80574B90:
    // 0x80574B90: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x80574B94: jal         0x80574A88
    // 0x80574B98: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    func_80574A88(rdram, ctx);
        goto after_1;
    // 0x80574B98: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    after_1:
    // 0x80574B9C: lw          $a1, 0x174($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X174);
    // 0x80574BA0: lui         $t7, 0x8057
    ctx->r15 = S32(RELOC_HI16(381, 0XE7C) << 16);
    // 0x80574BA4: addiu       $t7, $t7, 0x4D0C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(381, 0XE7C));
    // 0x80574BA8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80574BAC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80574BB0: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x80574BB4: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80574BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574BBC: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x80574BC0: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x80574BC4: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80574BC8: sh          $t0, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = ctx->r8;
    // 0x80574BCC: jal         0x80052BA4
    // 0x80574BD0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80052BA4(rdram, ctx);
        goto after_2;
    // 0x80574BD0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x80574BD4: jal         0x8005FDC4
    // 0x80574BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x80574BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80574BDC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80574BE0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80574BE4: jal         0x8004A73C
    // 0x80574BE8: sh          $zero, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = 0;
    func_8004A73C(rdram, ctx);
        goto after_4;
    // 0x80574BE8: sh          $zero, 0x4C($t2)
    MEM_H(0X4C, ctx->r10) = 0;
    after_4:
    // 0x80574BEC: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80574BF0: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x80574BF4: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80574BF8: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    // 0x80574BFC: jal         0x80047090
    // 0x80574C00: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x80574C00: lhu         $a0, 0x4($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X4);
    after_5:
    // 0x80574C04: lhu         $t5, 0xE($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XE);
    // 0x80574C08: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x80574C0C: addiu       $a2, $v0, 0x32
    ctx->r6 = ADD32(ctx->r2, 0X32);
    // 0x80574C10: andi        $t6, $t5, 0xFC00
    ctx->r14 = ctx->r13 & 0XFC00;
    // 0x80574C14: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80574C18: sh          $t7, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r15;
    // 0x80574C1C: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x80574C20: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80574C24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80574C28: beql        $v1, $zero, L_80574C54
    if (ctx->r3 == 0) {
        // 0x80574C2C: lhu         $t0, 0xE($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0XE);
            goto L_80574C54;
    }
    goto skip_0;
    // 0x80574C2C: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    skip_0:
    // 0x80574C30: beq         $v1, $at, L_80574C74
    if (ctx->r3 == ctx->r1) {
        // 0x80574C34: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80574C74;
    }
    // 0x80574C34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80574C38: beq         $v1, $at, L_80574C84
    if (ctx->r3 == ctx->r1) {
        // 0x80574C3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80574C84;
    }
    // 0x80574C3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80574C40: beq         $v1, $at, L_80574CB4
    if (ctx->r3 == ctx->r1) {
        // 0x80574C44: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80574CB4;
    }
    // 0x80574C44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80574C48: b           L_80574CC0
    // 0x80574C4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80574CC0;
    // 0x80574C4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80574C50: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
L_80574C54:
    // 0x80574C54: andi        $t9, $a2, 0x3FF
    ctx->r25 = ctx->r6 & 0X3FF;
    // 0x80574C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574C5C: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x80574C60: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x80574C64: jal         0x80044194
    // 0x80574C68: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    func_80044194(rdram, ctx);
        goto after_6;
    // 0x80574C68: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    after_6:
    // 0x80574C6C: b           L_80574CC0
    // 0x80574C70: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80574CC0;
    // 0x80574C70: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80574C74:
    // 0x80574C74: jal         0x80044194
    // 0x80574C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_7;
    // 0x80574C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80574C7C: b           L_80574CC0
    // 0x80574C80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80574CC0;
    // 0x80574C80: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80574C84:
    // 0x80574C84: lhu         $t4, 0xE($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XE);
    // 0x80574C88: andi        $t5, $a2, 0x3FF
    ctx->r13 = ctx->r6 & 0X3FF;
    // 0x80574C8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80574C90: andi        $t6, $t4, 0xFC00
    ctx->r14 = ctx->r12 & 0XFC00;
    // 0x80574C94: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80574C98: sh          $t7, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r15;
    // 0x80574C9C: jal         0x80047F9C
    // 0x80574CA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80574CA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_8:
    // 0x80574CA4: jal         0x8005FDC4
    // 0x80574CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_9;
    // 0x80574CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80574CAC: b           L_80574CC0
    // 0x80574CB0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80574CC0;
    // 0x80574CB0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80574CB4:
    // 0x80574CB4: jal         0x80047F9C
    // 0x80574CB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x80574CB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x80574CBC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80574CC0:
    // 0x80574CC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80574CC4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80574CC8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80574CCC: jr          $ra
    // 0x80574CD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80574CD0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80574CD4: nop

    // 0x80574CD8: nop

    // 0x80574CDC: nop

;}
RECOMP_FUNC void func_805221C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221C8: jr          $ra
    // 0x805221CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805221CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80049318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049318: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8004931C: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80049320: lw          $t6, 0xCE8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XCE8);
    // 0x80049324: bnel        $t6, $zero, L_80049374
    if (ctx->r14 != 0) {
        // 0x80049328: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049374;
    }
    goto skip_0;
    // 0x80049328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8004932C: lbu         $t7, 0x2($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2);
    // 0x80049330: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80049334: beql        $t7, $at, L_80049374
    if (ctx->r15 == ctx->r1) {
        // 0x80049338: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049374;
    }
    goto skip_1;
    // 0x80049338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8004933C: lbu         $v0, 0xF5C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XF5C);
    // 0x80049340: bne         $v0, $zero, L_80049370
    if (ctx->r2 != 0) {
        // 0x80049344: sll         $t8, $v0, 2
        ctx->r24 = S32(ctx->r2 << 2);
            goto L_80049370;
    }
    // 0x80049344: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80049348: lbu         $t9, 0xF5D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XF5D);
    // 0x8004934C: lw          $t2, 0xFBC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XFBC);
    // 0x80049350: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80049354: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80049358: sllv        $t1, $t0, $v1
    ctx->r9 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8004935C: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80049360: bnel        $t3, $zero, L_80049374
    if (ctx->r11 != 0) {
        // 0x80049364: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80049374;
    }
    goto skip_2;
    // 0x80049364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80049368: jr          $ra
    // 0x8004936C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8004936C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80049370:
    // 0x80049370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80049374:
    // 0x80049374: jr          $ra
    // 0x80049378: nop

    return;
    // 0x80049378: nop

;}
RECOMP_FUNC void func_804C1D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1D0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C1D10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1D14: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x804C1D18: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(203, 0XFFC) << 16);
    // 0x804C1D1C: addiu       $t8, $t8, 0x276C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(203, 0XFFC));
    // 0x804C1D20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C1D24: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804C1D28: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C1D2C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x804C1D30: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804C1D34: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804C1D38: beql        $v1, $zero, L_804C1D70
    if (ctx->r3 == 0) {
        // 0x804C1D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C1D70;
    }
    goto skip_0;
    // 0x804C1D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C1D40: jalr        $v1
    // 0x804C1D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804C1D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C1D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C1D4C: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x804C1D50: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x804C1D54: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x804C1D58: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x804C1D5C: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x804C1D60: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x804C1D64: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x804C1D68: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x804C1D6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1D70:
    // 0x804C1D70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C1D74: jr          $ra
    // 0x804C1D78: nop

    return;
    // 0x804C1D78: nop

;}
RECOMP_FUNC void func_8064F0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F0A8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F0AC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F0B0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F0B4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F0B8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F0BC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F0C0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F0C4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F0C8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F0CC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F0D0: jr          $ra
    // 0x8064F0D4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F0D4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8044981C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044981C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449820: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449824: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80449828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044982C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449830: bne         $a2, $zero, L_80449870
    if (ctx->r6 != 0) {
        // 0x80449834: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80449870;
    }
    // 0x80449834: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80449838: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x8044983C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80449840: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80449844: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80449848: bne         $at, $zero, L_804498B0
    if (ctx->r1 != 0) {
        // 0x8044984C: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_804498B0;
    }
    // 0x8044984C: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    // 0x80449850: jal         0x804469FC
    // 0x80449854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_0;
    // 0x80449854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80449858: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044985C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449860: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80449864: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449868: b           L_804498B0
    // 0x8044986C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804498B0;
    // 0x8044986C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_80449870:
    // 0x80449870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80449874: bnel        $a2, $at, L_804498A0
    if (ctx->r6 != ctx->r1) {
        // 0x80449878: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804498A0;
    }
    goto skip_0;
    // 0x80449878: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8044987C: jal         0x804469FC
    // 0x80449880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804469FC(rdram, ctx);
        goto after_1;
    // 0x80449880: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80449884: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80449888: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044988C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80449890: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80449894: b           L_804498B0
    // 0x80449898: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_804498B0;
    // 0x80449898: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x8044989C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804498A0:
    // 0x804498A0: bnel        $a2, $at, L_804498B4
    if (ctx->r6 != ctx->r1) {
        // 0x804498A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804498B4;
    }
    goto skip_1;
    // 0x804498A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804498A8: jal         0x80446A5C
    // 0x804498AC: nop

    func_80446A5C(rdram, ctx);
        goto after_2;
    // 0x804498AC: nop

    after_2:
L_804498B0:
    // 0x804498B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804498B4:
    // 0x804498B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804498B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804498BC: jr          $ra
    // 0x804498C0: nop

    return;
    // 0x804498C0: nop

;}
RECOMP_FUNC void func_804548E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804548E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804548E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804548EC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804548F0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804548F4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x804548F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804548FC: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80454900: lw          $v0, 0xA5C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XA5C);
    // 0x80454904: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80454908: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8045490C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80454910: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80454914: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80454918: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8045491C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454920: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454924: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80454928: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045492C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80454930: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80454934: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80454938: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x8045493C: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80454940: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80454944: jal         0x8044EEF8
    // 0x80454948: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8044EEF8(rdram, ctx);
        goto after_0;
    // 0x80454948: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x8045494C: jal         0x80446D70
    // 0x80454950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80446D70(rdram, ctx);
        goto after_1;
    // 0x80454950: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80454954: jal         0x8044E87C
    // 0x80454958: nop

    func_8044E87C(rdram, ctx);
        goto after_2;
    // 0x80454958: nop

    after_2:
    // 0x8045495C: jal         0x8044FD5C
    // 0x80454960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_3;
    // 0x80454960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80454964: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80454968: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8045496C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80454970: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80454974: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80454978: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045497C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454980: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80454984: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80454988: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x8045498C: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x80454990: jal         0x8044ED68
    // 0x80454994: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_4;
    // 0x80454994: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_4:
    // 0x80454998: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8045499C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804549A0: jal         0x8044F178
    // 0x804549A4: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    func_8044F178(rdram, ctx);
        goto after_5;
    // 0x804549A4: sw          $t1, 0xA5C($s1)
    MEM_W(0XA5C, ctx->r17) = ctx->r9;
    after_5:
    // 0x804549A8: jal         0x8044F384
    // 0x804549AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F384(rdram, ctx);
        goto after_6;
    // 0x804549AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804549B0: jal         0x80450220
    // 0x804549B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80450220(rdram, ctx);
        goto after_7;
    // 0x804549B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804549B8: jal         0x8045043C
    // 0x804549BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045043C(rdram, ctx);
        goto after_8;
    // 0x804549BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x804549C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804549C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804549C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804549CC: jr          $ra
    // 0x804549D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804549D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
