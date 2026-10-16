#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800442E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800442E0: sh          $zero, 0x38($a0)
    MEM_H(0X38, ctx->r4) = 0;
    // 0x800442E4: lh          $t6, 0x38($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X38);
    // 0x800442E8: jr          $ra
    // 0x800442EC: sh          $t6, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r14;
    return;
    // 0x800442EC: sh          $t6, 0x36($a0)
    MEM_H(0X36, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_804A0278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0278: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A027C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A0280: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804A0284: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804A0288: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804A028C: lui         $t8, 0x804A
    ctx->r24 = S32(RELOC_HI16(170, 0X348) << 16);
    // 0x804A0290: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A0294: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804A0298: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804A029C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804A02A0: lw          $t8, 0x3A8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(170, 0X348));
    // 0x804A02A4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804A02A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804A02AC: jal         0x80048490
    // 0x804A02B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804A02B0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804A02B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A02B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A02BC: jr          $ra
    // 0x804A02C0: nop

    return;
    // 0x804A02C0: nop

;}
RECOMP_FUNC void func_80024748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002474C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80024750: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80024754: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80024758: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8002475C: addiu       $a0, $a0, 0x14C
    ctx->r4 = ADD32(ctx->r4, 0X14C);
    // 0x80024760: jal         0x80024680
    // 0x80024764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80024680(rdram, ctx);
        goto after_0;
    // 0x80024764: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80024768: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002476C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80024770: jr          $ra
    // 0x80024774: nop

    return;
    // 0x80024774: nop

;}
RECOMP_FUNC void func_805C6A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6A70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805C6A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C6A78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C6A7C: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x805C6A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C6A84: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x805C6A88: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805C6A8C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x805C6A90: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x805C6A94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805C6A98: lwc1        $f12, 0x84($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805C6A9C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805C6AA0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805C6AA4: jal         0x80053924
    // 0x805C6AA8: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    func_80053924(rdram, ctx);
        goto after_0;
    // 0x805C6AA8: add.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f4.fl;
    after_0:
    // 0x805C6AAC: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x805C6AB0: bne         $v0, $at, L_805C6AC0
    if (ctx->r2 != ctx->r1) {
        // 0x805C6AB4: sh          $v0, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r2;
            goto L_805C6AC0;
    }
    // 0x805C6AB4: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x805C6AB8: b           L_805C6AE0
    // 0x805C6ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805C6AE0;
    // 0x805C6ABC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805C6AC0:
    // 0x805C6AC0: lbu         $t7, 0x1A($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1A);
    // 0x805C6AC4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x805C6AC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805C6ACC: andi        $t8, $t7, 0xF8
    ctx->r24 = ctx->r15 & 0XF8;
    // 0x805C6AD0: bne         $t8, $at, L_805C6AE0
    if (ctx->r24 != ctx->r1) {
        // 0x805C6AD4: nop
    
            goto L_805C6AE0;
    }
    // 0x805C6AD4: nop

    // 0x805C6AD8: b           L_805C6AE0
    // 0x805C6ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805C6AE0;
    // 0x805C6ADC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805C6AE0:
    // 0x805C6AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C6AE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805C6AE8: jr          $ra
    // 0x805C6AEC: nop

    return;
    // 0x805C6AEC: nop

;}
RECOMP_FUNC void func_807AB428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AB428: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807AB42C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AB430: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807AB434: jal         0x80047090
    // 0x807AB438: addiu       $a0, $zero, 0x46E4
    ctx->r4 = ADD32(0, 0X46E4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807AB438: addiu       $a0, $zero, 0x46E4
    ctx->r4 = ADD32(0, 0X46E4);
    after_0:
    // 0x807AB43C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807AB440: beq         $v0, $at, L_807AB490
    if (ctx->r2 == ctx->r1) {
        // 0x807AB444: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807AB490;
    }
    // 0x807AB444: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807AB448: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AB44C: lui         $at, 0x46E4
    ctx->r1 = S32(0X46E4 << 16);
    // 0x807AB450: ori         $at, $at, 0x2400
    ctx->r1 = ctx->r1 | 0X2400;
    // 0x807AB454: lui         $a3, 0xBA83
    ctx->r7 = S32(0XBA83 << 16);
    // 0x807AB458: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807AB45C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807AB460: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807AB464: jal         0x8004613C
    // 0x807AB468: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807AB468: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807AB46C: beq         $v0, $zero, L_807AB490
    if (ctx->r2 == 0) {
        // 0x807AB470: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_807AB490;
    }
    // 0x807AB470: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807AB474: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807AB478: jal         0x80047F9C
    // 0x807AB47C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807AB47C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x807AB480: jal         0x807AB2EC
    // 0x807AB484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807AB2EC(rdram, ctx);
        goto after_3;
    // 0x807AB484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x807AB488: b           L_807AB494
    // 0x807AB48C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
        goto L_807AB494;
    // 0x807AB48C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_807AB490:
    // 0x807AB490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AB494:
    // 0x807AB494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AB498: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807AB49C: jr          $ra
    // 0x807AB4A0: nop

    return;
    // 0x807AB4A0: nop

    // 0x807AB4A4: nop

    // 0x807AB4A8: nop

    // 0x807AB4AC: nop

;}
RECOMP_FUNC void func_80078760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078760: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80078764: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80078768: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007876C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80078770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078774: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80078778: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x8007877C: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x80078780: lw          $s1, 0x8($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X8);
    // 0x80078784: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80078788: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007878C: addu        $t2, $a0, $s0
    ctx->r10 = ADD32(ctx->r4, ctx->r16);
    // 0x80078790: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80078794: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x80078798: subu        $s2, $t2, $a1
    ctx->r18 = SUB32(ctx->r10, ctx->r5);
    // 0x8007879C: srl         $s1, $s1, 24
    ctx->r17 = S32(U32(ctx->r17) >> 24);
    // 0x800787A0: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800787A4: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    // 0x800787A8: blez        $s1, L_800787CC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800787AC: sw          $s2, 0x14($a0)
        MEM_W(0X14, ctx->r4) = ctx->r18;
            goto L_800787CC;
    }
    // 0x800787AC: sw          $s2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r18;
L_800787B0:
    // 0x800787B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800787B4: jal         0x80078444
    // 0x800787B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80078444(rdram, ctx);
        goto after_0;
    // 0x800787B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x800787BC: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800787C0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800787C4: bgtz        $s1, L_800787B0
    if (SIGNED(ctx->r17) > 0) {
        // 0x800787C8: addiu       $s2, $s2, 0x8
        ctx->r18 = ADD32(ctx->r18, 0X8);
            goto L_800787B0;
    }
    // 0x800787C8: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
L_800787CC:
    // 0x800787CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800787D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800787D4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800787D8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800787DC: jr          $ra
    // 0x800787E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800787E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800787E4: nop

    // 0x800787E8: nop

    // 0x800787EC: nop

;}
RECOMP_FUNC void func_8005D320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D320: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D324: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005D328: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D32C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8005D330: addiu       $a0, $a0, -0x7F70
    ctx->r4 = ADD32(ctx->r4, -0X7F70);
    // 0x8005D334: jal         0x80065528
    // 0x8005D338: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x8005D338: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    after_0:
    // 0x8005D33C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005D340: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005D344: lw          $t7, 0x8D0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8D0);
    // 0x8005D348: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x8005D34C: addiu       $t6, $t6, -0x7F70
    ctx->r14 = ADD32(ctx->r14, -0X7F70);
    // 0x8005D350: sw          $t6, 0x80($t7)
    MEM_W(0X80, ctx->r15) = ctx->r14;
    // 0x8005D354: lw          $t9, 0x8D0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8D0);
    // 0x8005D358: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D35C: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8005D360: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8005D364: sh          $t8, 0x7C($t9)
    MEM_H(0X7C, ctx->r25) = ctx->r24;
    // 0x8005D368: lbu         $a2, -0x7F6C($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7F6C);
    // 0x8005D36C: lbu         $a1, -0x7F5C($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7F5C);
    // 0x8005D370: jal         0x8006E0FC
    // 0x8005D374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x8005D374: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8005D378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005D37C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D380: jr          $ra
    // 0x8005D384: nop

    return;
    // 0x8005D384: nop

;}
RECOMP_FUNC void func_804755D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804755D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804755D4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804755D8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804755DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804755E0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804755E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804755E8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804755EC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804755F0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804755F4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804755F8: jr          $ra
    // 0x804755FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804755FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804714C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804714C0: lui         $v0, 0x8047
    ctx->r2 = S32(RELOC_HI16(158, 0X10) << 16);
    // 0x804714C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804714C8: jr          $ra
    // 0x804714CC: addiu       $v0, $v0, 0x14D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(158, 0X10));
    return;
    // 0x804714CC: addiu       $v0, $v0, 0x14D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(158, 0X10));
;}
RECOMP_FUNC void func_800582D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800582D8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800582DC: jr          $ra
    // 0x800582E0: addiu       $v0, $v0, -0x4BC8
    ctx->r2 = ADD32(ctx->r2, -0X4BC8);
    return;
    // 0x800582E0: addiu       $v0, $v0, -0x4BC8
    ctx->r2 = ADD32(ctx->r2, -0X4BC8);
;}
RECOMP_FUNC void func_805AA350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AA350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AA354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AA358: jal         0x805AA510
    // 0x805AA35C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AA510(rdram, ctx);
        goto after_0;
    // 0x805AA35C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AA360: beq         $v0, $zero, L_805AA3CC
    if (ctx->r2 == 0) {
        // 0x805AA364: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_805AA3CC;
    }
    // 0x805AA364: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AA368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805AA36C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA370: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x805AA374: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x805AA378: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x805AA37C: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA380: lui         $t0, 0x805B
    ctx->r8 = S32(RELOC_HI16(432, 0XAA0) << 16);
    // 0x805AA384: addiu       $t0, $t0, -0x5270
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(432, 0XAA0));
    // 0x805AA388: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x805AA38C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AA390: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805AA394: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805AA398: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x805AA39C: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x805AA3A0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x805AA3A4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805AA3A8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x805AA3AC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805AA3B0: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x805AA3B4: jal         0x805AABAC
    // 0x805AA3B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AABAC(rdram, ctx);
        goto after_1;
    // 0x805AA3B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x805AA3BC: jal         0x805AA338
    // 0x805AA3C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AA338(rdram, ctx);
        goto after_2;
    // 0x805AA3C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805AA3C4: b           L_805AA3D8
    // 0x805AA3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805AA3D8;
    // 0x805AA3C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA3CC:
    // 0x805AA3CC: jal         0x800445A4
    // 0x805AA3D0: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x805AA3D0: nop

    after_3:
    // 0x805AA3D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AA3D8:
    // 0x805AA3D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AA3DC: jr          $ra
    // 0x805AA3E0: nop

    return;
    // 0x805AA3E0: nop

;}
RECOMP_FUNC void func_800037CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800037CC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800037D0: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x800037D4: lw          $t6, 0x1EA8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1EA8);
    // 0x800037D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800037DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800037E0: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800037E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800037E8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800037EC: sw          $t6, 0x1EAC($v0)
    MEM_W(0X1EAC, ctx->r2) = ctx->r14;
    // 0x800037F0: addiu       $a0, $a0, 0x6BB8
    ctx->r4 = ADD32(ctx->r4, 0X6BB8);
    // 0x800037F4: jal         0x80003698
    // 0x800037F8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x800037F8: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x800037FC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80003800: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003804: addiu       $a0, $a0, 0x6BE8
    ctx->r4 = ADD32(ctx->r4, 0X6BE8);
    // 0x80003808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000380C: jal         0x800036F0
    // 0x80003810: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    func_800036F0(rdram, ctx);
        goto after_1;
    // 0x80003810: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x80003814: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80003818: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8000381C: addiu       $a0, $a0, 0x6BB8
    ctx->r4 = ADD32(ctx->r4, 0X6BB8);
    // 0x80003820: jal         0x80003698
    // 0x80003824: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    func_80003698(rdram, ctx);
        goto after_2;
    // 0x80003824: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    after_2:
    // 0x80003828: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000382C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003830: addiu       $a0, $a0, 0x6C18
    ctx->r4 = ADD32(ctx->r4, 0X6C18);
    // 0x80003834: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80003838: jal         0x800036F0
    // 0x8000383C: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    func_800036F0(rdram, ctx);
        goto after_3;
    // 0x8000383C: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    after_3:
    // 0x80003840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003848: jr          $ra
    // 0x8000384C: nop

    return;
    // 0x8000384C: nop

;}
RECOMP_FUNC void func_805AD218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AD21C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AD220: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805AD224: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x805AD228: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805AD22C: lui         $t8, 0x805B
    ctx->r24 = S32(RELOC_HI16(441, 0X11B4) << 16);
    // 0x805AD230: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805AD234: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x805AD238: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805AD23C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805AD240: lw          $t8, -0x2C5C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(441, 0X11B4));
    // 0x805AD244: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x805AD248: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x805AD24C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AD250: jal         0x80048490
    // 0x805AD254: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x805AD254: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x805AD258: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805AD25C: jal         0x80048378
    // 0x805AD260: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x805AD260: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x805AD264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AD268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AD26C: jr          $ra
    // 0x805AD270: nop

    return;
    // 0x805AD270: nop

;}
RECOMP_FUNC void func_8045BA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BA68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045BA6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BA70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8045BA74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045BA78: jal         0x80051194
    // 0x8045BA7C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x8045BA7C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8045BA80: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x8045BA84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BA88: jal         0x8045BBF4
    // 0x8045BA8C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8045BBF4(rdram, ctx);
        goto after_1;
    // 0x8045BA8C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_1:
    // 0x8045BA90: beq         $v0, $zero, L_8045BABC
    if (ctx->r2 == 0) {
        // 0x8045BA94: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8045BABC;
    }
    // 0x8045BA94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BA98: jal         0x8045BD74
    // 0x8045BA9C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    func_8045BD74(rdram, ctx);
        goto after_2;
    // 0x8045BA9C: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_2:
    // 0x8045BAA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BAA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045BAA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045BAAC: jal         0x8045D680
    // 0x8045BAB0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8045D680(rdram, ctx);
        goto after_3;
    // 0x8045BAB0: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
    // 0x8045BAB4: b           L_8045BAC8
    // 0x8045BAB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8045BAC8;
    // 0x8045BAB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BABC:
    // 0x8045BABC: jal         0x800445A4
    // 0x8045BAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8045BAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8045BAC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8045BAC8:
    // 0x8045BAC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045BACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045BAD0: jr          $ra
    // 0x8045BAD4: nop

    return;
    // 0x8045BAD4: nop

;}
RECOMP_FUNC void func_806EBFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EBFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EBFBC: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x806EBFC0: beq         $at, $zero, L_806EBFD0
    if (ctx->r1 == 0) {
        // 0x806EBFC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_806EBFD0;
    }
    // 0x806EBFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EBFC8: b           L_806EC02C
    // 0x806EBFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EC02C;
    // 0x806EBFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EBFD0:
    // 0x806EBFD0: bnel        $a0, $a1, L_806EBFE4
    if (ctx->r4 != ctx->r5) {
        // 0x806EBFD4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_806EBFE4;
    }
    goto skip_0;
    // 0x806EBFD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x806EBFD8: b           L_806EC02C
    // 0x806EBFDC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_806EC02C;
    // 0x806EBFDC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x806EBFE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_806EBFE4:
    // 0x806EBFE4: jal         0x800653D8
    // 0x806EBFE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x806EBFE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806EBFEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EBFF0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806EBFF4: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x806EBFF8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x806EBFFC: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x806EC000: mfhi        $t8
    ctx->r24 = hi;
    // 0x806EC004: bne         $t7, $zero, L_806EC010
    if (ctx->r15 != 0) {
        // 0x806EC008: nop
    
            goto L_806EC010;
    }
    // 0x806EC008: nop

    // 0x806EC00C: break       7
    do_break(2154741772);
L_806EC010:
    // 0x806EC010: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806EC014: bne         $t7, $at, L_806EC028
    if (ctx->r15 != ctx->r1) {
        // 0x806EC018: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806EC028;
    }
    // 0x806EC018: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806EC01C: bne         $v0, $at, L_806EC028
    if (ctx->r2 != ctx->r1) {
        // 0x806EC020: nop
    
            goto L_806EC028;
    }
    // 0x806EC020: nop

    // 0x806EC024: break       6
    do_break(2154741796);
L_806EC028:
    // 0x806EC028: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_806EC02C:
    // 0x806EC02C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EC030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC034: jr          $ra
    // 0x806EC038: nop

    return;
    // 0x806EC038: nop

;}
RECOMP_FUNC void func_80455544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455544: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80455548: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045554C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80455550: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455554: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x80455558: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045555C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80455560: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80455564: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80455568: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8045556C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80455570: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80455574: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80455578: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045557C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80455580: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80455584: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80455588: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x8045558C: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80455590: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x80455594: jal         0x80446D70
    // 0x80455598: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80455598: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x8045559C: jal         0x80450568
    // 0x804555A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80450568(rdram, ctx);
        goto after_1;
    // 0x804555A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x804555A4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x804555A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x804555AC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x804555B0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804555B4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804555B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804555BC: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804555C0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804555C4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804555C8: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x804555CC: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x804555D0: jal         0x8044ED68
    // 0x804555D4: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_2;
    // 0x804555D4: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_2:
    // 0x804555D8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x804555DC: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x804555E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804555E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804555E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804555EC: jr          $ra
    // 0x804555F0: nop

    return;
    // 0x804555F0: nop

;}
RECOMP_FUNC void func_8040B590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B598: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8040B59C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8040B5A0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040B5A4: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(14, 0X1328) << 16);
    // 0x8040B5A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040B5AC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8040B5B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040B5B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040B5B8: lw          $t8, -0x4178($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(14, 0X1328));
    // 0x8040B5BC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040B5C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040B5C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040B5C8: jal         0x80048490
    // 0x8040B5CC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8040B5CC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8040B5D0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8040B5D4: jal         0x80048378
    // 0x8040B5D8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8040B5D8: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8040B5DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B5E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B5E4: jr          $ra
    // 0x8040B5E8: nop

    return;
    // 0x8040B5E8: nop

;}
RECOMP_FUNC void Fault_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070FB0: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x80070FB4: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x80070FB8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80070FBC: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_80070FC0:
    // 0x80070FC0: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x80070FC4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070FC8: bne         $t9, $sp, L_80070FC0
    if (ctx->r25 != ctx->r29) {
        // 0x80070FCC: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_80070FC0;
    }
    // 0x80070FCC: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80070FD0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80070FD4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80070FD8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80070FDC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80070FE0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80070FE4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80070FE8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80070FEC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80070FF0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80070FF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80070FF8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80070FFC: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x80071000: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x80071004: lui         $s4, 0x800B
    ctx->r20 = S32(0X800B << 16);
    // 0x80071008: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x8007100C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80071010: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80071014: addiu       $s1, $s1, -0x7970
    ctx->r17 = ADD32(ctx->r17, -0X7970);
    // 0x80071018: addiu       $s2, $s2, -0x57C4
    ctx->r18 = ADD32(ctx->r18, -0X57C4);
    // 0x8007101C: addiu       $s3, $s3, -0x7FFC
    ctx->r19 = ADD32(ctx->r19, -0X7FFC);
    // 0x80071020: addiu       $s4, $s4, -0x8000
    ctx->r20 = ADD32(ctx->r20, -0X8000);
    // 0x80071024: addiu       $s5, $s5, -0x73B8
    ctx->r21 = ADD32(ctx->r21, -0X73B8);
    // 0x80071028: addiu       $s6, $s6, -0x7FF8
    ctx->r22 = ADD32(ctx->r22, -0X7FF8);
    // 0x8007102C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80071030: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x80071034: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80071038:
    // 0x80071038: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8007103C: jal         0x80089D70
    // 0x80071040: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071040: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x80071044: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80071048: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8007104C: jal         0x80089D70
    // 0x80071050: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80071050: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80071054: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80071058:
    // 0x80071058: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8007105C: jal         0x800824B0
    // 0x80071060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80071060: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80071064: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x80071068: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007106C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80071070: bne         $v1, $fp, L_8007108C
    if (ctx->r3 != ctx->r30) {
        // 0x80071074: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007108C;
    }
    // 0x80071074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80071078: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8007107C: jal         0x8008AD5C
    // 0x80071080: addiu       $a0, $a0, 0x1924
    ctx->r4 = ADD32(ctx->r4, 0X1924);
    osSyncPrintf(rdram, ctx);
        goto after_3;
    // 0x80071080: addiu       $a0, $a0, 0x1924
    ctx->r4 = ADD32(ctx->r4, 0X1924);
    after_3:
    // 0x80071084: b           L_800710C0
    // 0x80071088: nop

        goto L_800710C0;
    // 0x80071088: nop

L_8007108C:
    // 0x8007108C: bne         $v1, $at, L_800710B0
    if (ctx->r3 != ctx->r1) {
        // 0x80071090: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800710B0;
    }
    // 0x80071090: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80071094: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80071098: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8007109C: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800710A0: jal         0x8008AD5C
    // 0x800710A4: addiu       $a0, $a0, 0x195C
    ctx->r4 = ADD32(ctx->r4, 0X195C);
    osSyncPrintf(rdram, ctx);
        goto after_4;
    // 0x800710A4: addiu       $a0, $a0, 0x195C
    ctx->r4 = ADD32(ctx->r4, 0X195C);
    after_4:
    // 0x800710A8: b           L_800710C0
    // 0x800710AC: nop

        goto L_800710C0;
    // 0x800710AC: nop

L_800710B0:
    // 0x800710B0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800710B4: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800710B8: jal         0x8008AD5C
    // 0x800710BC: addiu       $a0, $a0, 0x1990
    ctx->r4 = ADD32(ctx->r4, 0X1990);
    osSyncPrintf(rdram, ctx);
        goto after_5;
    // 0x800710BC: addiu       $a0, $a0, 0x1990
    ctx->r4 = ADD32(ctx->r4, 0X1990);
    after_5:
L_800710C0:
    // 0x800710C0: jal         0x80090740
    // 0x800710C4: nop

    __osGetCurrFaultedThread(rdram, ctx);
        goto after_6;
    // 0x800710C4: nop

    after_6:
    // 0x800710C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800710CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800710D0: addiu       $a0, $a0, 0x19C4
    ctx->r4 = ADD32(ctx->r4, 0X19C4);
    // 0x800710D4: jal         0x8008AD5C
    // 0x800710D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    osSyncPrintf(rdram, ctx);
        goto after_7;
    // 0x800710D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x800710DC: bne         $s0, $zero, L_80071100
    if (ctx->r16 != 0) {
        // 0x800710E0: nop
    
            goto L_80071100;
    }
    // 0x800710E0: nop

    // 0x800710E4: jal         0x8007033C
    // 0x800710E8: nop

    FindFaultedThread(rdram, ctx);
        goto after_8;
    // 0x800710E8: nop

    after_8:
    // 0x800710EC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800710F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800710F4: addiu       $a0, $a0, 0x19E8
    ctx->r4 = ADD32(ctx->r4, 0X19E8);
    // 0x800710F8: jal         0x8008AD5C
    // 0x800710FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    osSyncPrintf(rdram, ctx);
        goto after_9;
    // 0x800710FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
L_80071100:
    // 0x80071100: beql        $s0, $zero, L_80071058
    if (ctx->r16 == 0) {
        // 0x80071104: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80071058;
    }
    goto skip_0;
    // 0x80071104: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_0:
    // 0x80071108: jal         0x80070038
    // 0x8007110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Fault_LogThreadContext(rdram, ctx);
        goto after_10;
    // 0x8007110C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80071110: jal         0x80086880
    // 0x80071114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_11;
    // 0x80071114: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80071118: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x8007111C: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80071120: addiu       $t9, $t9, 0x1A20
    ctx->r25 = ADD32(ctx->r25, 0X1A20);
    // 0x80071124: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80071128: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8007112C: addiu       $a2, $a2, 0x1A18
    ctx->r6 = ADD32(ctx->r6, 0X1A18);
    // 0x80071130: addiu       $a0, $a0, 0x1A04
    ctx->r4 = ADD32(ctx->r4, 0X1A04);
    // 0x80071134: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80071138: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8007113C: addiu       $a3, $zero, 0x47E
    ctx->r7 = ADD32(0, 0X47E);
    // 0x80071140: jal         0x8008AD5C
    // 0x80071144: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osSyncPrintf(rdram, ctx);
        goto after_12;
    // 0x80071144: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_12:
    // 0x80071148: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x8007114C: bne         $t1, $zero, L_80071168
    if (ctx->r9 != 0) {
        // 0x80071150: nop
    
            goto L_80071168;
    }
    // 0x80071150: nop

L_80071154:
    // 0x80071154: jal         0x8006F8F0
    // 0x80071158: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    Fault_Sleep(rdram, ctx);
        goto after_13;
    // 0x80071158: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_13:
    // 0x8007115C: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80071160: beq         $t2, $zero, L_80071154
    if (ctx->r10 == 0) {
        // 0x80071164: nop
    
            goto L_80071154;
    }
    // 0x80071164: nop

L_80071168:
    // 0x80071168: jal         0x8006F8F0
    // 0x8007116C: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    Fault_Sleep(rdram, ctx);
        goto after_14;
    // 0x8007116C: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_14:
    // 0x80071170: jal         0x800703C4
    // 0x80071174: nop

    Fault_WaitButtonCombo(rdram, ctx);
        goto after_15;
    // 0x80071174: nop

    after_15:
L_80071178:
    // 0x80071178: jal         0x80070F1C
    // 0x8007117C: nop

    Fault_DisplayFramebuffer(rdram, ctx);
        goto after_16;
    // 0x8007117C: nop

    after_16:
    // 0x80071180: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80071184:
    // 0x80071184: jal         0x80070988
    // 0x80071188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80070988(rdram, ctx);
        goto after_17;
    // 0x80071188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8007118C: jal         0x8007080C
    // 0x80071190: nop

    Fault_WaitInput(rdram, ctx);
        goto after_18;
    // 0x80071190: nop

    after_18:
    // 0x80071194: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80071198: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8007119C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800711A0: bne         $at, $zero, L_80071184
    if (ctx->r1 != 0) {
        // 0x800711A4: nop
    
            goto L_80071184;
    }
    // 0x800711A4: nop

    // 0x800711A8: jal         0x80070B60
    // 0x800711AC: nop

    Fault_PrintDebuggerInfo(rdram, ctx);
        goto after_19;
    // 0x800711AC: nop

    after_19:
    // 0x800711B0: jal         0x8007080C
    // 0x800711B4: nop

    Fault_WaitInput(rdram, ctx);
        goto after_20;
    // 0x800711B4: nop

    after_20:
    // 0x800711B8: jal         0x8006FC04
    // 0x800711BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Fault_PrintThreadContext(rdram, ctx);
        goto after_21;
    // 0x800711BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x800711C0: jal         0x8007080C
    // 0x800711C4: nop

    Fault_WaitInput(rdram, ctx);
        goto after_22;
    // 0x800711C4: nop

    after_22:
    // 0x800711C8: jal         0x80070DA0
    // 0x800711CC: nop

    func_80070DA0(rdram, ctx);
        goto after_23;
    // 0x800711CC: nop

    after_23:
    // 0x800711D0: jal         0x8007080C
    // 0x800711D4: nop

    Fault_WaitInput(rdram, ctx);
        goto after_24;
    // 0x800711D4: nop

    after_24:
    // 0x800711D8: jal         0x80070CA0
    // 0x800711DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Fault_PrintStackTrace(rdram, ctx);
        goto after_25;
    // 0x800711DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800711E0: jal         0x8007080C
    // 0x800711E4: nop

    Fault_WaitInput(rdram, ctx);
        goto after_26;
    // 0x800711E4: nop

    after_26:
    // 0x800711E8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800711EC: beq         $t5, $zero, L_80071178
    if (ctx->r13 == 0) {
        // 0x800711F0: nop
    
            goto L_80071178;
    }
    // 0x800711F0: nop

    // 0x800711F4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800711F8: bne         $t6, $zero, L_8007120C
    if (ctx->r14 != 0) {
        // 0x800711FC: nop
    
            goto L_8007120C;
    }
    // 0x800711FC: nop

    // 0x80071200: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
L_80071204:
    // 0x80071204: beql        $t7, $zero, L_80071204
    if (ctx->r15 == 0) {
        // 0x80071208: lw          $t7, 0x0($s4)
        ctx->r15 = MEM_W(ctx->r20, 0X0);
            goto L_80071204;
    }
    goto skip_1;
    // 0x80071208: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    skip_1:
L_8007120C:
    // 0x8007120C: jal         0x80070EA0
    // 0x80071210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Fault_ResumeThread(rdram, ctx);
        goto after_27;
    // 0x80071210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x80071214: b           L_80071038
    // 0x80071218: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_80071038;
    // 0x80071218: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8007121C: nop

    // 0x80071220: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80071224: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80071228: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8007122C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80071230: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80071234: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80071238: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8007123C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80071240: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80071244: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80071248: jr          $ra
    // 0x8007124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007124C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80705764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80705764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80705768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8070576C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80705770: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80705774: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80705778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070577C: bne         $v1, $zero, L_80705794
    if (ctx->r3 != 0) {
        // 0x80705780: nop
    
            goto L_80705794;
    }
    // 0x80705780: nop

    // 0x80705784: jal         0x80045A34
    // 0x80705788: addiu       $a1, $zero, 0x1D8
    ctx->r5 = ADD32(0, 0X1D8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80705788: addiu       $a1, $zero, 0x1D8
    ctx->r5 = ADD32(0, 0X1D8);
    after_0:
    // 0x8070578C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80705790: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80705794:
    // 0x80705794: bne         $v1, $zero, L_807057AC
    if (ctx->r3 != 0) {
        // 0x80705798: lui         $t6, 0x8070
        ctx->r14 = S32(RELOC_HI16(709, 0X3768) << 16);
            goto L_807057AC;
    }
    // 0x80705798: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0X3768) << 16);
    // 0x8070579C: jal         0x800445A4
    // 0x807057A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x807057A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807057A4: b           L_80705A4C
    // 0x807057A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80705A4C;
    // 0x807057A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807057AC:
    // 0x807057AC: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x807057B0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807057B4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x807057B8: addiu       $t6, $t6, 0x6BD8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0X3768));
    // 0x807057BC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807057C0: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x807057C4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x807057C8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x807057CC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x807057D0: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x807057D4: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x807057D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807057DC: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x807057E0: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x807057E4: sw          $zero, 0x18($s1)
    MEM_W(0X18, ctx->r17) = 0;
    // 0x807057E8: sw          $zero, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = 0;
    // 0x807057EC: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x807057F0: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x807057F4: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x807057F8: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x807057FC: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x80705800: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x80705804: sw          $zero, 0x38($s1)
    MEM_W(0X38, ctx->r17) = 0;
    // 0x80705808: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x8070580C: sw          $zero, 0x40($s1)
    MEM_W(0X40, ctx->r17) = 0;
    // 0x80705810: sw          $zero, 0x44($s1)
    MEM_W(0X44, ctx->r17) = 0;
    // 0x80705814: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80705818: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8070581C: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80705820: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80705824: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80705828: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_8070582C:
    // 0x8070582C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80705830: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80705834: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80705838: bne         $at, $zero, L_8070582C
    if (ctx->r1 != 0) {
        // 0x8070583C: sh          $zero, 0x46($v0)
        MEM_H(0X46, ctx->r2) = 0;
            goto L_8070582C;
    }
    // 0x8070583C: sh          $zero, 0x46($v0)
    MEM_H(0X46, ctx->r2) = 0;
    // 0x80705840: lui         $a1, 0x8070
    ctx->r5 = S32(RELOC_HI16(709, 0X2668) << 16);
    // 0x80705844: lui         $a3, 0x8070
    ctx->r7 = S32(RELOC_HI16(709, 0X2678) << 16);
    // 0x80705848: lui         $t1, 0x8070
    ctx->r9 = S32(RELOC_HI16(709, 0X2688) << 16);
    // 0x8070584C: lui         $v0, 0x8070
    ctx->r2 = S32(RELOC_HI16(709, 0X2698) << 16);
    // 0x80705850: lui         $v1, 0x8070
    ctx->r3 = S32(RELOC_HI16(709, 0X2818) << 16);
    // 0x80705854: addiu       $v1, $v1, 0x5C88
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(709, 0X2818));
    // 0x80705858: addiu       $v0, $v0, 0x5B08
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(709, 0X2698));
    // 0x8070585C: addiu       $t1, $t1, 0x5AF8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(709, 0X2688));
    // 0x80705860: addiu       $a3, $a3, 0x5AE8
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(709, 0X2678));
    // 0x80705864: addiu       $a1, $a1, 0x5AD8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(709, 0X2668));
    // 0x80705868: addiu       $a0, $s1, 0x58
    ctx->r4 = ADD32(ctx->r17, 0X58);
    // 0x8070586C: addiu       $a2, $s1, 0x68
    ctx->r6 = ADD32(ctx->r17, 0X68);
    // 0x80705870: addiu       $t0, $s1, 0x78
    ctx->r8 = ADD32(ctx->r17, 0X78);
    // 0x80705874: addiu       $t2, $s1, 0x88
    ctx->r10 = ADD32(ctx->r17, 0X88);
L_80705878:
    // 0x80705878: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8070587C: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x80705880: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80705884: sw          $t5, -0x40($a0)
    MEM_W(-0X40, ctx->r4) = ctx->r13;
    // 0x80705888: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x8070588C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80705890: addiu       $a2, $a2, 0x40
    ctx->r6 = ADD32(ctx->r6, 0X40);
    // 0x80705894: sw          $t4, -0x3C($a0)
    MEM_W(-0X3C, ctx->r4) = ctx->r12;
    // 0x80705898: lw          $t5, -0x38($a1)
    ctx->r13 = MEM_W(ctx->r5, -0X38);
    // 0x8070589C: addiu       $a3, $a3, 0x40
    ctx->r7 = ADD32(ctx->r7, 0X40);
    // 0x807058A0: addiu       $t0, $t0, 0x40
    ctx->r8 = ADD32(ctx->r8, 0X40);
    // 0x807058A4: sw          $t5, -0x38($a0)
    MEM_W(-0X38, ctx->r4) = ctx->r13;
    // 0x807058A8: lw          $t4, -0x34($a1)
    ctx->r12 = MEM_W(ctx->r5, -0X34);
    // 0x807058AC: addiu       $t1, $t1, 0x40
    ctx->r9 = ADD32(ctx->r9, 0X40);
    // 0x807058B0: addiu       $t2, $t2, 0x40
    ctx->r10 = ADD32(ctx->r10, 0X40);
    // 0x807058B4: sw          $t4, -0x34($a0)
    MEM_W(-0X34, ctx->r4) = ctx->r12;
    // 0x807058B8: lw          $t7, -0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, -0X40);
    // 0x807058BC: sw          $t7, -0x40($a2)
    MEM_W(-0X40, ctx->r6) = ctx->r15;
    // 0x807058C0: lw          $t6, -0x3C($a3)
    ctx->r14 = MEM_W(ctx->r7, -0X3C);
    // 0x807058C4: sw          $t6, -0x3C($a2)
    MEM_W(-0X3C, ctx->r6) = ctx->r14;
    // 0x807058C8: lw          $t7, -0x38($a3)
    ctx->r15 = MEM_W(ctx->r7, -0X38);
    // 0x807058CC: sw          $t7, -0x38($a2)
    MEM_W(-0X38, ctx->r6) = ctx->r15;
    // 0x807058D0: lw          $t6, -0x34($a3)
    ctx->r14 = MEM_W(ctx->r7, -0X34);
    // 0x807058D4: sw          $t6, -0x34($a2)
    MEM_W(-0X34, ctx->r6) = ctx->r14;
    // 0x807058D8: lw          $t9, -0x40($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X40);
    // 0x807058DC: sw          $t9, -0x40($t0)
    MEM_W(-0X40, ctx->r8) = ctx->r25;
    // 0x807058E0: lw          $t8, -0x3C($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X3C);
    // 0x807058E4: sw          $t8, -0x3C($t0)
    MEM_W(-0X3C, ctx->r8) = ctx->r24;
    // 0x807058E8: lw          $t9, -0x38($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X38);
    // 0x807058EC: sw          $t9, -0x38($t0)
    MEM_W(-0X38, ctx->r8) = ctx->r25;
    // 0x807058F0: lw          $t8, -0x34($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X34);
    // 0x807058F4: sw          $t8, -0x34($t0)
    MEM_W(-0X34, ctx->r8) = ctx->r24;
    // 0x807058F8: lw          $t5, -0x40($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X40);
    // 0x807058FC: sw          $t5, -0x40($t2)
    MEM_W(-0X40, ctx->r10) = ctx->r13;
    // 0x80705900: lw          $t4, -0x3C($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X3C);
    // 0x80705904: sw          $t4, -0x3C($t2)
    MEM_W(-0X3C, ctx->r10) = ctx->r12;
    // 0x80705908: lw          $t5, -0x38($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X38);
    // 0x8070590C: sw          $t5, -0x38($t2)
    MEM_W(-0X38, ctx->r10) = ctx->r13;
    // 0x80705910: lw          $t4, -0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, -0X34);
    // 0x80705914: bne         $v0, $v1, L_80705878
    if (ctx->r2 != ctx->r3) {
        // 0x80705918: sw          $t4, -0x34($t2)
        MEM_W(-0X34, ctx->r10) = ctx->r12;
            goto L_80705878;
    }
    // 0x80705918: sw          $t4, -0x34($t2)
    MEM_W(-0X34, ctx->r10) = ctx->r12;
    // 0x8070591C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80705920: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0X4F8) << 16);
    // 0x80705924: addiu       $t6, $t6, 0x3968
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0X4F8));
    // 0x80705928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070592C: jal         0x807041E0
    // 0x80705930: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    func_807041E0(rdram, ctx);
        goto after_2;
    // 0x80705930: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    after_2:
    // 0x80705934: lhu         $t8, 0xC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XC);
    // 0x80705938: addiu       $t9, $t8, -0x4605
    ctx->r25 = ADD32(ctx->r24, -0X4605);
    // 0x8070593C: sltiu       $at, $t9, 0x1B
    ctx->r1 = ctx->r25 < 0X1B ? 1 : 0;
    // 0x80705940: beq         $at, $zero, L_80705A08
    if (ctx->r1 == 0) {
        // 0x80705944: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80705A08;
    }
    // 0x80705944: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80705948: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X38C8) << 16);
    // 0x8070594C: addu        $at, $at, $t9
    gpr jr_addend_80705954 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80705950: lw          $t9, 0x6D38($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(709, 0X38C8));
    // 0x80705954: jr          $t9
    // 0x80705958: nop

    switch (jr_addend_80705954 >> 2) {
        case 0: goto L_807059F0; break;
        case 1: goto L_807059F0; break;
        case 2: goto L_8070595C; break;
        case 3: goto L_80705A08; break;
        case 4: goto L_80705A08; break;
        case 5: goto L_80705A08; break;
        case 6: goto L_80705A08; break;
        case 7: goto L_80705A08; break;
        case 8: goto L_80705A08; break;
        case 9: goto L_80705A08; break;
        case 10: goto L_80705A08; break;
        case 11: goto L_80705A08; break;
        case 12: goto L_80705A08; break;
        case 13: goto L_80705A08; break;
        case 14: goto L_80705A08; break;
        case 15: goto L_80705A08; break;
        case 16: goto L_80705A08; break;
        case 17: goto L_80705A08; break;
        case 18: goto L_80705A08; break;
        case 19: goto L_80705A08; break;
        case 20: goto L_80705A08; break;
        case 21: goto L_80705A08; break;
        case 22: goto L_80705A08; break;
        case 23: goto L_80705A08; break;
        case 24: goto L_80705A08; break;
        case 25: goto L_80705988; break;
        case 26: goto L_807059BC; break;
        default: switch_error(__func__, 0x80705954, 0x80706D38);
    }
    // 0x80705958: nop

L_8070595C:
    // 0x8070595C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3934) << 16);
    // 0x80705960: lwc1        $f0, 0x6DA4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3934));
    // 0x80705964: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80705968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070596C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80705970: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80705974: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x80705978: jal         0x80705A5C
    // 0x8070597C: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    func_80705A5C(rdram, ctx);
        goto after_3;
    // 0x8070597C: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80705980: b           L_80705A0C
    // 0x80705984: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
        goto L_80705A0C;
    // 0x80705984: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
L_80705988:
    // 0x80705988: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8070598C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80705990: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80705994: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80705998: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8070599C: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x807059A0: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x807059A4: sw          $t4, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r12;
    // 0x807059A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807059AC: jal         0x80705A5C
    // 0x807059B0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80705A5C(rdram, ctx);
        goto after_4;
    // 0x807059B0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_4:
    // 0x807059B4: b           L_80705A0C
    // 0x807059B8: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
        goto L_80705A0C;
    // 0x807059B8: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
L_807059BC:
    // 0x807059BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807059C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807059C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x807059C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807059CC: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x807059D0: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x807059D4: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x807059D8: sw          $t5, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r13;
    // 0x807059DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807059E0: jal         0x80705A5C
    // 0x807059E4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80705A5C(rdram, ctx);
        goto after_5;
    // 0x807059E4: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_5:
    // 0x807059E8: b           L_80705A0C
    // 0x807059EC: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
        goto L_80705A0C;
    // 0x807059EC: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
L_807059F0:
    // 0x807059F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807059F4: sw          $t6, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r14;
    // 0x807059F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807059FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80705A00: jal         0x80705A5C
    // 0x80705A04: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80705A5C(rdram, ctx);
        goto after_6;
    // 0x80705A04: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_6:
L_80705A08:
    // 0x80705A08: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
L_80705A0C:
    // 0x80705A0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80705A10: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80705A14: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    // 0x80705A18: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X3938) << 16);
    // 0x80705A1C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80705A20: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80705A24: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80705A28: lwc1        $f8, 0x6DA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X3938));
    // 0x80705A2C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(709, 0X393C) << 16);
    // 0x80705A30: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x80705A34: lwc1        $f10, 0x6DAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(709, 0X393C));
    // 0x80705A38: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80705A3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80705A40: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x80705A44: swc1        $f16, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f16.u32l;
    // 0x80705A48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80705A4C:
    // 0x80705A4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80705A50: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80705A54: jr          $ra
    // 0x80705A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80705A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8043FDF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FDF0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043FDF4: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043FDF8: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043FDFC: lw          $a2, 0x1C90($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C90);
    // 0x8043FE00: lwc1        $f12, 0x1C74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X1C74);
    // 0x8043FE04: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8043FE08: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x8043FE0C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8043FE10: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x8043FE14: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x8043FE18: beq         $at, $zero, L_8043FE58
    if (ctx->r1 == 0) {
        // 0x8043FE1C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8043FE58;
    }
    // 0x8043FE1C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8043FE20:
    // 0x8043FE20: lwc1        $f4, 0x28($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8043FE24: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8043FE28: lwc1        $f8, 0x2C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8043FE2C: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8043FE30: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043FE34: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
    // 0x8043FE38: slti        $at, $a2, 0x96
    ctx->r1 = SIGNED(ctx->r6) < 0X96 ? 1 : 0;
    // 0x8043FE3C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8043FE40: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8043FE44: addiu       $a1, $a1, 0x150
    ctx->r5 = ADD32(ctx->r5, 0X150);
    // 0x8043FE48: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8043FE4C: swc1        $f18, -0x148($a1)
    MEM_W(-0X148, ctx->r5) = ctx->f18.u32l;
    // 0x8043FE50: bne         $at, $zero, L_8043FE20
    if (ctx->r1 != 0) {
        // 0x8043FE54: swc1        $f4, -0x144($a1)
        MEM_W(-0X144, ctx->r5) = ctx->f4.u32l;
            goto L_8043FE20;
    }
    // 0x8043FE54: swc1        $f4, -0x144($a1)
    MEM_W(-0X144, ctx->r5) = ctx->f4.u32l;
L_8043FE58:
    // 0x8043FE58: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    // 0x8043FE5C: addiu       $a2, $zero, 0x95
    ctx->r6 = ADD32(0, 0X95);
L_8043FE60:
    // 0x8043FE60: lwc1        $f6, 0x20($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8043FE64: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8043FE68: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8043FE6C: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8043FE70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8043FE74: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8043FE78: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    // 0x8043FE7C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8043FE80: swc1        $f10, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->f10.u32l;
    // 0x8043FE84: lwc1        $f8, -0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, -0X10);
    // 0x8043FE88: swc1        $f6, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f6.u32l;
    // 0x8043FE8C: lwc1        $f18, -0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, -0XC);
    // 0x8043FE90: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8043FE94: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8043FE98: swc1        $f10, -0x30($a1)
    MEM_W(-0X30, ctx->r5) = ctx->f10.u32l;
    // 0x8043FE9C: bgez        $a2, L_8043FE60
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8043FEA0: swc1        $f4, -0x2C($a1)
        MEM_W(-0X2C, ctx->r5) = ctx->f4.u32l;
            goto L_8043FE60;
    }
    // 0x8043FEA0: swc1        $f4, -0x2C($a1)
    MEM_W(-0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x8043FEA4: jr          $ra
    // 0x8043FEA8: nop

    return;
    // 0x8043FEA8: nop

;}
RECOMP_FUNC void func_80071D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071D78: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x80071D7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071D80: jal         0x800824B0
    // 0x80071D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071D84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80071D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071D90: jr          $ra
    // 0x80071D94: nop

    return;
    // 0x80071D94: nop

;}
RECOMP_FUNC void func_804B6AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6AC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804B6AC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6AC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B6ACC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804B6AD0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x804B6AD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B6AD8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804B6ADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804B6AE0: lw          $v1, 0x88($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X88);
    // 0x804B6AE4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x804B6AE8: nop

    // 0x804B6AEC: sra         $v0, $v0, 4
    ctx->r2 = S32(SIGNED(ctx->r2) >> 4);
    // 0x804B6AF0: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x804B6AF4: beql        $v0, $zero, L_804B6BC0
    if (ctx->r2 == 0) {
        // 0x804B6AF8: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_804B6BC0;
    }
    goto skip_0;
    // 0x804B6AF8: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_0:
    // 0x804B6AFC: beq         $v0, $at, L_804B6B24
    if (ctx->r2 == ctx->r1) {
        // 0x804B6B00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804B6B24;
    }
    // 0x804B6B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6B04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804B6B08: beq         $v0, $at, L_804B6B58
    if (ctx->r2 == ctx->r1) {
        // 0x804B6B0C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804B6B58;
    }
    // 0x804B6B0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6B10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x804B6B14: beq         $v0, $at, L_804B6B88
    if (ctx->r2 == ctx->r1) {
        // 0x804B6B18: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804B6B88;
    }
    // 0x804B6B18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6B1C: b           L_804B6BE8
    // 0x804B6B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804B6BE8;
    // 0x804B6B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B6B24:
    // 0x804B6B24: jal         0x8004590C
    // 0x804B6B28: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x804B6B28: addiu       $a1, $v1, 0x200
    ctx->r5 = ADD32(ctx->r3, 0X200);
    after_0:
    // 0x804B6B2C: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    // 0x804B6B30: addiu       $t8, $zero, 0x2242
    ctx->r24 = ADD32(0, 0X2242);
    // 0x804B6B34: addiu       $t1, $zero, 0x2244
    ctx->r9 = ADD32(0, 0X2244);
    // 0x804B6B38: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804B6B3C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x804B6B40: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x804B6B44: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x804B6B48: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804B6B4C: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x804B6B50: b           L_804B6BE4
    // 0x804B6B54: sw          $t4, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r12;
        goto L_804B6BE4;
    // 0x804B6B54: sw          $t4, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r12;
L_804B6B58:
    // 0x804B6B58: jal         0x8004590C
    // 0x804B6B5C: addiu       $a1, $v1, 0x400
    ctx->r5 = ADD32(ctx->r3, 0X400);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x804B6B5C: addiu       $a1, $v1, 0x400
    ctx->r5 = ADD32(ctx->r3, 0X400);
    after_1:
    // 0x804B6B60: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x804B6B64: addiu       $t5, $zero, 0x4222
    ctx->r13 = ADD32(0, 0X4222);
    // 0x804B6B68: addiu       $t9, $zero, 0x2244
    ctx->r25 = ADD32(0, 0X2244);
    // 0x804B6B6C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x804B6B70: sh          $t5, 0x18($t7)
    MEM_H(0X18, ctx->r15) = ctx->r13;
    // 0x804B6B74: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x804B6B78: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x804B6B7C: sh          $t9, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r25;
    // 0x804B6B80: b           L_804B6BE4
    // 0x804B6B84: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
        goto L_804B6BE4;
    // 0x804B6B84: sw          $zero, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = 0;
L_804B6B88:
    // 0x804B6B88: jal         0x8004590C
    // 0x804B6B8C: addiu       $a1, $v1, 0x600
    ctx->r5 = ADD32(ctx->r3, 0X600);
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x804B6B8C: addiu       $a1, $v1, 0x600
    ctx->r5 = ADD32(ctx->r3, 0X600);
    after_2:
    // 0x804B6B90: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x804B6B94: addiu       $t2, $zero, 0x2224
    ctx->r10 = ADD32(0, 0X2224);
    // 0x804B6B98: addiu       $t4, $zero, 0x4244
    ctx->r12 = ADD32(0, 0X4244);
    // 0x804B6B9C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x804B6BA0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x804B6BA4: sh          $t2, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r10;
    // 0x804B6BA8: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x804B6BAC: lw          $t5, 0x0($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X0);
    // 0x804B6BB0: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x804B6BB4: b           L_804B6BE4
    // 0x804B6BB8: sw          $t7, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r15;
        goto L_804B6BE4;
    // 0x804B6BB8: sw          $t7, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r15;
    // 0x804B6BBC: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
L_804B6BC0:
    // 0x804B6BC0: addiu       $t8, $zero, 0x2422
    ctx->r24 = ADD32(0, 0X2422);
    // 0x804B6BC4: addiu       $t1, $zero, 0x2444
    ctx->r9 = ADD32(0, 0X2444);
    // 0x804B6BC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804B6BCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804B6BD0: sh          $t8, 0x18($t0)
    MEM_H(0X18, ctx->r8) = ctx->r24;
    // 0x804B6BD4: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x804B6BD8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x804B6BDC: sh          $t1, 0x1A($t3)
    MEM_H(0X1A, ctx->r11) = ctx->r9;
    // 0x804B6BE0: sw          $t6, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r14;
L_804B6BE4:
    // 0x804B6BE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B6BE8:
    // 0x804B6BE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B6BEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804B6BF0: jr          $ra
    // 0x804B6BF4: nop

    return;
    // 0x804B6BF4: nop

;}
RECOMP_FUNC void func_8066D704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066D704: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066D708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066D70C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066D710: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8066D714: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066D718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066D71C: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8066D720: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8066D724: bnel        $t6, $zero, L_8066D7BC
    if (ctx->r14 != 0) {
        // 0x8066D728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8066D7BC;
    }
    goto skip_0;
    // 0x8066D728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8066D72C: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8066D730: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D734: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x8066D738: beq         $t7, $zero, L_8066D77C
    if (ctx->r15 == 0) {
        // 0x8066D73C: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_8066D77C;
    }
    // 0x8066D73C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8066D740: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D744: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x8066D748: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8066D74C: jal         0x8004D1F0
    // 0x8066D750: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x8066D750: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8066D754: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D758: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x8066D75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D760: jal         0x8004D698
    // 0x8066D764: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x8066D764: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8066D768: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8066D76C: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x8066D770: ori         $t9, $t8, 0xF
    ctx->r25 = ctx->r24 | 0XF;
    // 0x8066D774: b           L_8066D7B0
    // 0x8066D778: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
        goto L_8066D7B0;
    // 0x8066D778: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_8066D77C:
    // 0x8066D77C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D780: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8066D784: jal         0x8004D1F0
    // 0x8066D788: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x8066D788: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x8066D78C: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8066D790: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x8066D794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066D798: jal         0x8004D698
    // 0x8066D79C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x8066D79C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8066D7A0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8066D7A4: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8066D7A8: ori         $t1, $t0, 0xF0
    ctx->r9 = ctx->r8 | 0XF0;
    // 0x8066D7AC: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
L_8066D7B0:
    // 0x8066D7B0: jal         0x8066D5D0
    // 0x8066D7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066D5D0(rdram, ctx);
        goto after_4;
    // 0x8066D7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8066D7B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066D7BC:
    // 0x8066D7BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066D7C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066D7C4: jr          $ra
    // 0x8066D7C8: nop

    return;
    // 0x8066D7C8: nop

;}
RECOMP_FUNC void func_806D6F58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6F58: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806D6F5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D6F60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D6F64: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D6F68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D6F6C: jal         0x8004700C
    // 0x806D6F70: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D6F70: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x806D6F74: beq         $v0, $zero, L_806D7214
    if (ctx->r2 == 0) {
        // 0x806D6F78: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_806D7214;
    }
    // 0x806D6F78: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806D6F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D6F80: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x806D6F84: jal         0x806D6BC0
    // 0x806D6F88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_806D6BC0(rdram, ctx);
        goto after_1;
    // 0x806D6F88: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x806D6F8C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806D6F90: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806D6F94: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x806D6F98: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x806D6F9C: beq         $v0, $zero, L_806D6FAC
    if (ctx->r2 == 0) {
        // 0x806D6FA0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806D6FAC;
    }
    // 0x806D6FA0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806D6FA4: sw          $t6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r14;
    // 0x806D6FA8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_806D6FAC:
    // 0x806D6FAC: bnel        $v0, $zero, L_806D6FEC
    if (ctx->r2 != 0) {
        // 0x806D6FB0: lwc1        $f14, 0x3C($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_806D6FEC;
    }
    goto skip_0;
    // 0x806D6FB0: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    skip_0:
    // 0x806D6FB4: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x806D6FB8: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(622, 0X18E4) << 16);
    // 0x806D6FBC: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x806D6FC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D6FC4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x806D6FC8: lw          $t1, -0x7B6C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(622, 0X18E4));
    // 0x806D6FCC: sh          $t1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r9;
    // 0x806D6FD0: lw          $t2, 0xC($a3)
    ctx->r10 = MEM_W(ctx->r7, 0XC);
    // 0x806D6FD4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x806D6FD8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x806D6FDC: bne         $at, $zero, L_806D6FE8
    if (ctx->r1 != 0) {
        // 0x806D6FE0: sw          $t3, 0xC($a3)
        MEM_W(0XC, ctx->r7) = ctx->r11;
            goto L_806D6FE8;
    }
    // 0x806D6FE0: sw          $t3, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r11;
    // 0x806D6FE4: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
L_806D6FE8:
    // 0x806D6FE8: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
L_806D6FEC:
    // 0x806D6FEC: lwc1        $f4, 0x84($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806D6FF0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x806D6FF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D6FF8: sub.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x806D6FFC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x806D7000: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x806D7004: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x806D7008: nop

    // 0x806D700C: bc1fl       L_806D7030
    if (!c1cs) {
        // 0x806D7010: lwc1        $f10, 0x1C($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X1C);
            goto L_806D7030;
    }
    goto skip_1;
    // 0x806D7010: lwc1        $f10, 0x1C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X1C);
    skip_1:
    // 0x806D7014: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806D7018: nop

    // 0x806D701C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x806D7020: nop

    // 0x806D7024: bc1tl       L_806D7054
    if (c1cs) {
        // 0x806D7028: sw          $zero, 0xC($a3)
        MEM_W(0XC, ctx->r7) = 0;
            goto L_806D7054;
    }
    goto skip_2;
    // 0x806D7028: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    skip_2:
    // 0x806D702C: lwc1        $f10, 0x1C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X1C);
L_806D7030:
    // 0x806D7030: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x806D7034: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D7038: sub.s       $f2, $f10, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x806D703C: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x806D7040: c.le.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl <= ctx->f2.fl;
    // 0x806D7044: nop

    // 0x806D7048: bc1fl       L_806D709C
    if (!c1cs) {
        // 0x806D704C: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_806D709C;
    }
    goto skip_3;
    // 0x806D704C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_3:
    // 0x806D7050: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
L_806D7054:
    // 0x806D7054: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x806D7058: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x806D705C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x806D7060: jal         0x806D6D60
    // 0x806D7064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806D6D60(rdram, ctx);
        goto after_2;
    // 0x806D7064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806D7068: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x806D706C: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
    // 0x806D7070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7074: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D7078: jal         0x806D7A20
    // 0x806D707C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_806D7A20(rdram, ctx);
        goto after_3;
    // 0x806D707C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x806D7080: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806D7084: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D7088: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806D708C: lwc1        $f18, 0x1C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x806D7090: sub.s       $f2, $f18, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x806D7094: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x806D7098: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_806D709C:
    // 0x806D709C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D70A0: nop

    // 0x806D70A4: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x806D70A8: nop

    // 0x806D70AC: bc1fl       L_806D720C
    if (!c1cs) {
        // 0x806D70B0: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D720C;
    }
    goto skip_4;
    // 0x806D70B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_4:
    // 0x806D70B4: lwc1        $f12, 0x84($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806D70B8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x806D70BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D70C0: sub.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x806D70C4: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
    // 0x806D70C8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x806D70CC: nop

    // 0x806D70D0: bc1fl       L_806D717C
    if (!c1cs) {
        // 0x806D70D4: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_806D717C;
    }
    goto skip_5;
    // 0x806D70D4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    skip_5:
    // 0x806D70D8: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x806D70DC: nop

    // 0x806D70E0: bc1fl       L_806D70F8
    if (!c1cs) {
        // 0x806D70E4: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_806D70F8;
    }
    goto skip_6;
    // 0x806D70E4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_6:
    // 0x806D70E8: lw          $t6, 0x138($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X138);
    // 0x806D70EC: beql        $t6, $zero, L_806D7114
    if (ctx->r14 == 0) {
        // 0x806D70F0: sw          $zero, 0xC($a3)
        MEM_W(0XC, ctx->r7) = 0;
            goto L_806D7114;
    }
    goto skip_7;
    // 0x806D70F0: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    skip_7:
    // 0x806D70F4: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_806D70F8:
    // 0x806D70F8: lw          $v1, 0x138($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X138);
    // 0x806D70FC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1AFC) << 16);
    // 0x806D7100: bc1f        L_806D714C
    if (!c1cs) {
        // 0x806D7104: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_806D714C;
    }
    // 0x806D7104: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x806D7108: beql        $v1, $zero, L_806D7150
    if (ctx->r3 == 0) {
        // 0x806D710C: addu        $at, $at, $t7
        ctx->r1 = ADD32(ctx->r1, ctx->r15);
            goto L_806D7150;
    }
    goto skip_8;
    // 0x806D710C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    skip_8:
    // 0x806D7110: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
L_806D7114:
    // 0x806D7114: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x806D7118: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x806D711C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x806D7120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D7124: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D7128: jal         0x806D7A20
    // 0x806D712C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806D7A20(rdram, ctx);
        goto after_4;
    // 0x806D712C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x806D7130: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x806D7134: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D7138: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806D713C: lwc1        $f12, 0x84($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806D7140: sub.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x806D7144: b           L_806D7178
    // 0x806D7148: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
        goto L_806D7178;
    // 0x806D7148: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
L_806D714C:
    // 0x806D714C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
L_806D7150:
    // 0x806D7150: lwc1        $f8, -0x7954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1AFC));
    // 0x806D7154: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806D7158: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B64) << 16);
    // 0x806D715C: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x806D7160: lwc1        $f10, -0x78EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B64));
    // 0x806D7164: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x806D7168: lwc1        $f12, 0x84($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X84);
    // 0x806D716C: lwc1        $f14, 0x3C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x806D7170: sub.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x806D7174: abs.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = fabsf(ctx->f2.fl);
L_806D7178:
    // 0x806D7178: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
L_806D717C:
    // 0x806D717C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806D7180: nop

    // 0x806D7184: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x806D7188: nop

    // 0x806D718C: bc1fl       L_806D720C
    if (!c1cs) {
        // 0x806D7190: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_806D720C;
    }
    goto skip_9;
    // 0x806D7190: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_9:
    // 0x806D7194: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x806D7198: nop

    // 0x806D719C: bc1fl       L_806D71B4
    if (!c1cs) {
        // 0x806D71A0: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_806D71B4;
    }
    goto skip_10;
    // 0x806D71A0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_10:
    // 0x806D71A4: lw          $t8, 0x138($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X138);
    // 0x806D71A8: bnel        $t8, $zero, L_806D71D0
    if (ctx->r24 != 0) {
        // 0x806D71AC: sw          $zero, 0xC($a3)
        MEM_W(0XC, ctx->r7) = 0;
            goto L_806D71D0;
    }
    goto skip_11;
    // 0x806D71AC: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    skip_11:
    // 0x806D71B0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_806D71B4:
    // 0x806D71B4: lw          $v1, 0x138($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X138);
    // 0x806D71B8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B04) << 16);
    // 0x806D71BC: bc1f        L_806D71EC
    if (!c1cs) {
        // 0x806D71C0: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_806D71EC;
    }
    // 0x806D71C0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x806D71C4: bnel        $v1, $zero, L_806D71F0
    if (ctx->r3 != 0) {
        // 0x806D71C8: addu        $at, $at, $t9
        ctx->r1 = ADD32(ctx->r1, ctx->r25);
            goto L_806D71F0;
    }
    goto skip_12;
    // 0x806D71C8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    skip_12:
    // 0x806D71CC: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
L_806D71D0:
    // 0x806D71D0: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x806D71D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D71D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D71DC: jal         0x806D7A20
    // 0x806D71E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806D7A20(rdram, ctx);
        goto after_5;
    // 0x806D71E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x806D71E4: b           L_806D720C
    // 0x806D71E8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
        goto L_806D720C;
    // 0x806D71E8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D71EC:
    // 0x806D71EC: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
L_806D71F0:
    // 0x806D71F0: lwc1        $f18, -0x794C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B04));
    // 0x806D71F4: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x806D71F8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(622, 0X1B68) << 16);
    // 0x806D71FC: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x806D7200: lwc1        $f4, -0x78E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(622, 0X1B68));
    // 0x806D7204: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x806D7208: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_806D720C:
    // 0x806D720C: jal         0x80048F84
    // 0x806D7210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x806D7210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_806D7214:
    // 0x806D7214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D7218: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D721C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806D7220: jr          $ra
    // 0x806D7224: nop

    return;
    // 0x806D7224: nop

;}
RECOMP_FUNC void func_80760438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80760438: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8076043C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC33C) << 16);
    // 0x80760440: lwc1        $f4, -0x3C34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC33C));
    // 0x80760444: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC340) << 16);
    // 0x80760448: lwc1        $f6, -0x3C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC340));
    // 0x8076044C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80760450: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80760454: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80760458: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8076045C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80760460: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80760464: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80760468: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8076046C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80760470: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80760474: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80760478: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8076047C: jal         0x8076009C
    // 0x80760480: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_8076009C(rdram, ctx);
        goto after_0;
    // 0x80760480: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80760484: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80760488: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(763, 0XC344) << 16);
    // 0x8076048C: lwc1        $f2, -0x3C2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(763, 0XC344));
    // 0x80760490: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x80760494: addiu       $t8, $zero, 0xAC8
    ctx->r24 = ADD32(0, 0XAC8);
    // 0x80760498: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8076049C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807604A0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x807604A4: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x807604A8: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x807604AC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x807604B0: jal         0x8076009C
    // 0x807604B4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_8076009C(rdram, ctx);
        goto after_1;
    // 0x807604B4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x807604B8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x807604BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807604C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x807604C4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x807604C8: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x807604CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807604D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807604D4: jr          $ra
    // 0x807604D8: nop

    return;
    // 0x807604D8: nop

;}
RECOMP_FUNC void func_8001A850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A850: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A858: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001A85C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001A860: jal         0x8001A374
    // 0x8001A864: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8001A374(rdram, ctx);
        goto after_0;
    // 0x8001A864: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8001A868: beq         $v0, $zero, L_8001A88C
    if (ctx->r2 == 0) {
        // 0x8001A86C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001A88C;
    }
    // 0x8001A86C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001A870: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x8001A874: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x8001A878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001A87C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001A880: jal         0x8001AA4C
    // 0x8001A884: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    func_8001AA4C(rdram, ctx);
        goto after_1;
    // 0x8001A884: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    after_1:
    // 0x8001A888: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8001A88C:
    // 0x8001A88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A890: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001A894: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001A898: jr          $ra
    // 0x8001A89C: nop

    return;
    // 0x8001A89C: nop

;}
RECOMP_FUNC void func_8043295C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043295C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80432960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80432964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80432968: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8043296C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80432970: beql        $v0, $zero, L_804329FC
    if (ctx->r2 == 0) {
        // 0x80432974: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804329FC;
    }
    goto skip_0;
    // 0x80432974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80432978: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8043297C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80432980: beql        $t6, $zero, L_804329FC
    if (ctx->r14 == 0) {
        // 0x80432984: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804329FC;
    }
    goto skip_1;
    // 0x80432984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80432988: jal         0x80047AB8
    // 0x8043298C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x8043298C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80432990: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(62, 0X598) << 16);
    // 0x80432994: lwc1        $f0, 0x2D38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(62, 0X598));
    // 0x80432998: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8043299C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804329A0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804329A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804329A8: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x804329AC: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x804329B0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804329B4: addiu       $t8, $t8, -0x7C48
    ctx->r24 = ADD32(ctx->r24, -0X7C48);
    // 0x804329B8: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x804329BC: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x804329C0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804329C4: sb          $t7, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r15;
    // 0x804329C8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x804329CC: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x804329D0: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x804329D4: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x804329D8: sw          $t8, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r24;
    // 0x804329DC: lbu         $a2, 0x30($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X30);
    // 0x804329E0: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x804329E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804329E8: jal         0x80432B00
    // 0x804329EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80432B00(rdram, ctx);
        goto after_1;
    // 0x804329EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804329F0: jal         0x8005FAE0
    // 0x804329F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FAE0(rdram, ctx);
        goto after_2;
    // 0x804329F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804329F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804329FC:
    // 0x804329FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80432A00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80432A04: jr          $ra
    // 0x80432A08: nop

    return;
    // 0x80432A08: nop

;}
RECOMP_FUNC void func_804C6DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C6DFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C6E00: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C6E04: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C6E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C6E0C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C6E10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804C6E14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804C6E18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C6E1C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x804C6E20: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C6E24: lui         $t1, 0x804C
    ctx->r9 = S32(RELOC_HI16(221, 0X320) << 16);
    // 0x804C6E28: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C6E2C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C6E30: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C6E34: lw          $t1, 0x6F80($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(221, 0X320));
    // 0x804C6E38: jal         0x804C6D08
    // 0x804C6E3C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_804C6D08(rdram, ctx);
        goto after_0;
    // 0x804C6E3C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x804C6E40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C6E44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6E48: jr          $ra
    // 0x804C6E4C: nop

    return;
    // 0x804C6E4C: nop

;}
RECOMP_FUNC void func_80067D48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D48: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067D4C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067D50: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x80067D54: jr          $ra
    // 0x80067D58: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
    return;
    // 0x80067D58: sw          $a1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_80531880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80531880: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80531884: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80531888: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8053188C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80531890: lwc1        $f0, 0x274($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X274);
    // 0x80531894: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80531898: jal         0x8004700C
    // 0x8053189C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8053189C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805318A0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805318A4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805318A8: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(342, 0X1A00) << 16);
    // 0x805318AC: lwc1        $f2, 0x27F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(342, 0X1A00));
    // 0x805318B0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805318B4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805318B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805318BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805318C0: nop

    // 0x805318C4: bc1fl       L_805318D8
    if (!c1cs) {
        // 0x805318C8: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_805318D8;
    }
    goto skip_0;
    // 0x805318C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x805318CC: b           L_805318F0
    // 0x805318D0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_805318F0;
    // 0x805318D0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x805318D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_805318D8:
    // 0x805318D8: nop

    // 0x805318DC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805318E0: nop

    // 0x805318E4: bc1f        L_805318F0
    if (!c1cs) {
        // 0x805318E8: nop
    
            goto L_805318F0;
    }
    // 0x805318E8: nop

    // 0x805318EC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_805318F0:
    // 0x805318F0: beq         $v0, $zero, L_80531914
    if (ctx->r2 == 0) {
        // 0x805318F4: swc1        $f0, 0x274($v1)
        MEM_W(0X274, ctx->r3) = ctx->f0.u32l;
            goto L_80531914;
    }
    // 0x805318F4: swc1        $f0, 0x274($v1)
    MEM_W(0X274, ctx->r3) = ctx->f0.u32l;
    // 0x805318F8: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x805318FC: lwc1        $f10, 0x7C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80531900: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80531904: nop

    // 0x80531908: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8053190C: swc1        $f8, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f8.u32l;
    // 0x80531910: swc1        $f16, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f16.u32l;
L_80531914:
    // 0x80531914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80531918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8053191C: jr          $ra
    // 0x80531920: nop

    return;
    // 0x80531920: nop

;}
RECOMP_FUNC void func_8040D728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D728: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040D72C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8040D730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8040D734: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D738: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D73C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040D740: jal         0x8040CBE8
    // 0x8040D744: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8040CBE8(rdram, ctx);
        goto after_0;
    // 0x8040D744: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8040D748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D74C: jal         0x8040CBE8
    // 0x8040D750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8040CBE8(rdram, ctx);
        goto after_1;
    // 0x8040D750: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8040D754: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8040D758: bne         $v0, $at, L_8040D7AC
    if (ctx->r2 != ctx->r1) {
        // 0x8040D75C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8040D7AC;
    }
    // 0x8040D75C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8040D760: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8040D764: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8040D768: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8040D76C: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040D770: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8040D774: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8040D778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D77C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8040D780: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8040D784: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x8040D788: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x8040D78C: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x8040D790: jal         0x8005FDC4
    // 0x8040D794: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x8040D794: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x8040D798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D79C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D7A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040D7A4: jal         0x8040E254
    // 0x8040D7A8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_3;
    // 0x8040D7A8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_3:
L_8040D7AC:
    // 0x8040D7AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8040D7B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8040D7B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8040D7B8: jr          $ra
    // 0x8040D7BC: nop

    return;
    // 0x8040D7BC: nop

;}
RECOMP_FUNC void func_805A2A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A2A5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A2A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A2A64: jal         0x805A27E8
    // 0x805A2A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A27E8(rdram, ctx);
        goto after_0;
    // 0x805A2A68: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A2A6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A2A70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805A2A74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A2A78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805A2A7C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x805A2A80: jal         0x805A2B28
    // 0x805A2A84: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_805A2B28(rdram, ctx);
        goto after_1;
    // 0x805A2A84: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x805A2A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A2A8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A2A90: jr          $ra
    // 0x805A2A94: nop

    return;
    // 0x805A2A94: nop

;}
RECOMP_FUNC void func_80027CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027CDC: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x80027CE0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80027CE4: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x80027CE8: xori        $v0, $v0, 0x19
    ctx->r2 = ctx->r2 ^ 0X19;
    // 0x80027CEC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80027CF0: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80027CF4: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80027CF8: lw          $t6, -0x3A20($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3A20);
    // 0x80027CFC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80027D00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80027D04: bne         $v1, $t6, L_80027D20
    if (ctx->r3 != ctx->r14) {
        // 0x80027D08: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80027D20;
    }
    // 0x80027D08: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80027D0C: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x80027D10: lw          $t7, -0x3A18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3A18);
    // 0x80027D14: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80027D18: jr          $ra
    // 0x80027D1C: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
    return;
    // 0x80027D1C: sw          $t7, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r15;
L_80027D20:
    // 0x80027D20: sw          $t8, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r24;
    // 0x80027D24: jr          $ra
    // 0x80027D28: nop

    return;
    // 0x80027D28: nop

;}
RECOMP_FUNC void func_8051AD50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051AD50: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8051AD54: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(294, 0XC78) << 16);
    // 0x8051AD58: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(294, 0XC88) << 16);
    // 0x8051AD5C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8051AD60: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8051AD64: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8051AD68: lw          $t6, -0x4E68($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(294, 0XC78));
    // 0x8051AD6C: lw          $t8, -0x4E58($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(294, 0XC88));
    // 0x8051AD70: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8051AD74: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8051AD78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8051AD7C: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x8051AD80: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8051AD84: sw          $t8, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r24;
    // 0x8051AD88: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8051AD8C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8051AD90: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x8051AD94: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    // 0x8051AD98: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8051AD9C: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
    // 0x8051ADA0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8051ADA4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8051ADA8: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x8051ADAC: swc1        $f0, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f0.u32l;
    // 0x8051ADB0: swc1        $f0, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f0.u32l;
    // 0x8051ADB4: swc1        $f0, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f0.u32l;
    // 0x8051ADB8: jr          $ra
    // 0x8051ADBC: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8051ADBC: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_805A1380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A1380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A1384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A1388: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x805A138C: addiu       $at, $zero, 0x417E
    ctx->r1 = ADD32(0, 0X417E);
    // 0x805A1390: beq         $v0, $at, L_805A13B8
    if (ctx->r2 == ctx->r1) {
        // 0x805A1394: addiu       $at, $zero, 0x417F
        ctx->r1 = ADD32(0, 0X417F);
            goto L_805A13B8;
    }
    // 0x805A1394: addiu       $at, $zero, 0x417F
    ctx->r1 = ADD32(0, 0X417F);
    // 0x805A1398: beq         $v0, $at, L_805A13C8
    if (ctx->r2 == ctx->r1) {
        // 0x805A139C: addiu       $at, $zero, 0x4180
        ctx->r1 = ADD32(0, 0X4180);
            goto L_805A13C8;
    }
    // 0x805A139C: addiu       $at, $zero, 0x4180
    ctx->r1 = ADD32(0, 0X4180);
    // 0x805A13A0: beq         $v0, $at, L_805A13D8
    if (ctx->r2 == ctx->r1) {
        // 0x805A13A4: addiu       $at, $zero, 0x4181
        ctx->r1 = ADD32(0, 0X4181);
            goto L_805A13D8;
    }
    // 0x805A13A4: addiu       $at, $zero, 0x4181
    ctx->r1 = ADD32(0, 0X4181);
    // 0x805A13A8: beq         $v0, $at, L_805A13E8
    if (ctx->r2 == ctx->r1) {
        // 0x805A13AC: nop
    
            goto L_805A13E8;
    }
    // 0x805A13AC: nop

    // 0x805A13B0: b           L_805A13F4
    // 0x805A13B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A13F4;
    // 0x805A13B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A13B8:
    // 0x805A13B8: jal         0x805A29EC
    // 0x805A13BC: nop

    func_805A29EC(rdram, ctx);
        goto after_0;
    // 0x805A13BC: nop

    after_0:
    // 0x805A13C0: b           L_805A13F4
    // 0x805A13C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A13F4;
    // 0x805A13C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A13C8:
    // 0x805A13C8: jal         0x805A2A28
    // 0x805A13CC: nop

    func_805A2A28(rdram, ctx);
        goto after_1;
    // 0x805A13CC: nop

    after_1:
    // 0x805A13D0: b           L_805A13F4
    // 0x805A13D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A13F4;
    // 0x805A13D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A13D8:
    // 0x805A13D8: jal         0x805A2A5C
    // 0x805A13DC: nop

    func_805A2A5C(rdram, ctx);
        goto after_2;
    // 0x805A13DC: nop

    after_2:
    // 0x805A13E0: b           L_805A13F4
    // 0x805A13E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A13F4;
    // 0x805A13E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A13E8:
    // 0x805A13E8: jal         0x805A2A98
    // 0x805A13EC: nop

    func_805A2A98(rdram, ctx);
        goto after_3;
    // 0x805A13EC: nop

    after_3:
    // 0x805A13F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A13F4:
    // 0x805A13F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A13F8: jr          $ra
    // 0x805A13FC: nop

    return;
    // 0x805A13FC: nop

;}
RECOMP_FUNC void func_8002F318(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F318: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F31C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F320: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002F324: lbu         $t7, 0x111($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X111);
    // 0x8002F328: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x8002F32C: beq         $t7, $zero, L_8002F344
    if (ctx->r15 == 0) {
        // 0x8002F330: nop
    
            goto L_8002F344;
    }
    // 0x8002F330: nop

    // 0x8002F334: jal         0x8002F15C
    // 0x8002F338: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    func_8002F15C(rdram, ctx);
        goto after_0;
    // 0x8002F338: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x8002F33C: b           L_8002F350
    // 0x8002F340: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F350;
    // 0x8002F340: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F344:
    // 0x8002F344: jal         0x8002DBE4
    // 0x8002F348: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8002F348: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002F34C: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
L_8002F350:
    // 0x8002F350: sw          $zero, 0x1400($t8)
    MEM_W(0X1400, ctx->r24) = 0;
    // 0x8002F354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F358: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F35C: jr          $ra
    // 0x8002F360: nop

    return;
    // 0x8002F360: nop

;}
RECOMP_FUNC void func_8000EC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000EC4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000EC50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000EC54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000EC58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000EC5C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000EC60: lbu         $a0, 0x7($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7);
    // 0x8000EC64: jal         0x8000B808
    // 0x8000EC68: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    func_8000B808(rdram, ctx);
        goto after_0;
    // 0x8000EC68: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    after_0:
    // 0x8000EC6C: lbu         $a0, 0x1F($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X1F);
    // 0x8000EC70: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8000EC74: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000EC78: bne         $v0, $zero, L_8000EC8C
    if (ctx->r2 != 0) {
        // 0x8000EC7C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8000EC8C;
    }
    // 0x8000EC7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000EC80: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8000EC84: b           L_8000ECA8
    // 0x8000EC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000ECA8;
    // 0x8000EC88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EC8C:
    // 0x8000EC8C: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8000EC90: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000EC94: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8000EC98: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8000EC9C: lbu         $t8, 0x3($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X3);
    // 0x8000ECA0: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x8000ECA4: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_8000ECA8:
    // 0x8000ECA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ECAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000ECB0: jr          $ra
    // 0x8000ECB4: nop

    return;
    // 0x8000ECB4: nop

;}
RECOMP_FUNC void func_80527424(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527424: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X617C) << 16);
    // 0x80527428: lwc1        $f4, -0x3F84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X617C));
    // 0x8052742C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80527430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527434: lui         $v1, 0x8053
    ctx->r3 = S32(RELOC_HI16(327, 0X5154) << 16);
    // 0x80527438: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(327, 0X15D8) << 16);
    // 0x8052743C: addiu       $v1, $v1, -0x4FAC
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(327, 0X5154));
    // 0x80527440: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80527444: addiu       $t6, $t6, 0x74D8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(327, 0X15D8));
    // 0x80527448: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x8052744C: sw          $v0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r2;
    // 0x80527450: sw          $v1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r3;
    // 0x80527454: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80527458: sw          $v0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r2;
    // 0x8052745C: sw          $t6, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r14;
    // 0x80527460: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80527464: jr          $ra
    // 0x80527468: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x80527468: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80445730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445730: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445734: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445738: jal         0x80046E88
    // 0x8044573C: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x8044573C: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x80445740: beq         $v0, $zero, L_80445750
    if (ctx->r2 == 0) {
        // 0x80445744: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80445750;
    }
    // 0x80445744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80445748: jal         0x800447C8
    // 0x8044574C: nop

    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8044574C: nop

    after_1:
L_80445750:
    // 0x80445750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445758: jr          $ra
    // 0x8044575C: nop

    return;
    // 0x8044575C: nop

;}
RECOMP_FUNC void func_804279C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804279C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804279CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804279D0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804279D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804279D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804279DC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1D08) << 16);
    // 0x804279E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804279E4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804279E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804279EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804279F0: lw          $t8, -0x69B8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1D08));
    // 0x804279F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804279F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804279FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80427A00: jal         0x80048490
    // 0x80427A04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80427A04: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80427A08: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80427A0C: jal         0x80048378
    // 0x80427A10: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80427A10: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80427A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427A18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427A1C: jr          $ra
    // 0x80427A20: nop

    return;
    // 0x80427A20: nop

;}
RECOMP_FUNC void func_8064F1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064F1C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064F1CC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064F1D0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064F1D4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064F1D8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064F1DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064F1E0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064F1E4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064F1E8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064F1EC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064F1F0: jr          $ra
    // 0x8064F1F4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064F1F4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80714B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80714B7C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80714B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80714B84: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80714B88: addiu       $t6, $sp, 0x44
    ctx->r14 = ADD32(ctx->r29, 0X44);
    // 0x80714B8C: lw          $t7, 0x5EC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X5EC);
    // 0x80714B90: lw          $v1, 0x5F8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X5F8);
    // 0x80714B94: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80714B98: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80714B9C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80714BA0: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80714BA4: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80714BA8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80714BAC: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80714BB0: sw          $t1, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r9;
    // 0x80714BB4: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x80714BB8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x80714BBC: lw          $v0, 0x5EC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5EC);
    // 0x80714BC0: lh          $t2, 0x5FC($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X5FC);
    // 0x80714BC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80714BC8: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80714BCC: bnel        $at, $zero, L_80714BDC
    if (ctx->r1 != 0) {
        // 0x80714BD0: sll         $t4, $v0, 4
        ctx->r12 = S32(ctx->r2 << 4);
            goto L_80714BDC;
    }
    goto skip_0;
    // 0x80714BD0: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    skip_0:
    // 0x80714BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80714BD8: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
L_80714BDC:
    // 0x80714BDC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80714BE0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80714BE4: addiu       $t3, $sp, 0x34
    ctx->r11 = ADD32(ctx->r29, 0X34);
    // 0x80714BE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80714BEC: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80714BF0: lw          $t7, 0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X4);
    // 0x80714BF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80714BF8: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80714BFC: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x80714C00: sw          $t8, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r24;
    // 0x80714C04: lw          $t7, 0xC($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XC);
    // 0x80714C08: sw          $t7, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r15;
    // 0x80714C0C: lh          $t6, 0x4C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4C);
    // 0x80714C10: lwc1        $f4, 0x5F0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X5F0);
    // 0x80714C14: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80714C18: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80714C1C: lwc1        $f16, 0x5E4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5E4);
    // 0x80714C20: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80714C24: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80714C28: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80714C2C: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80714C30: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80714C34: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80714C38: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80714C3C: add.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80714C40: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x80714C44: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80714C48: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80714C4C: lwc1        $f16, 0x5E8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5E8);
    // 0x80714C50: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80714C54: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80714C58: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80714C5C: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80714C60: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80714C64: lwc1        $f16, 0x5F0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X5F0);
    // 0x80714C68: lwc1        $f8, 0x5F4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X5F4);
    // 0x80714C6C: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80714C70: swc1        $f10, 0x5F0($a1)
    MEM_W(0X5F0, ctx->r5) = ctx->f10.u32l;
    // 0x80714C74: lwc1        $f12, 0x5F0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X5F0);
    // 0x80714C78: lh          $t1, 0x4C($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X4C);
    // 0x80714C7C: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80714C80: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80714C84: nop

    // 0x80714C88: slt         $at, $t0, $t1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80714C8C: bnel        $at, $zero, L_80714CAC
    if (ctx->r1 != 0) {
        // 0x80714C90: lhu         $t2, 0x3E($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X3E);
            goto L_80714CAC;
    }
    goto skip_1;
    // 0x80714C90: lhu         $t2, 0x3E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3E);
    skip_1:
    // 0x80714C94: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80714C98: sw          $v0, 0x5EC($a1)
    MEM_W(0X5EC, ctx->r5) = ctx->r2;
    // 0x80714C9C: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80714CA0: sub.s       $f16, $f12, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80714CA4: swc1        $f16, 0x5F0($a1)
    MEM_W(0X5F0, ctx->r5) = ctx->f16.u32l;
    // 0x80714CA8: lhu         $t2, 0x3E($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X3E);
L_80714CAC:
    // 0x80714CAC: lhu         $t4, 0x144($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X144);
    // 0x80714CB0: beql        $t2, $t4, L_80714CF4
    if (ctx->r10 == ctx->r12) {
        // 0x80714CB4: lbu         $t5, 0x50($sp)
        ctx->r13 = MEM_BU(ctx->r29, 0X50);
            goto L_80714CF4;
    }
    goto skip_2;
    // 0x80714CB4: lbu         $t5, 0x50($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X50);
    skip_2:
    // 0x80714CB8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80714CBC: jal         0x80714B20
    // 0x80714CC0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    func_80714B20(rdram, ctx);
        goto after_0;
    // 0x80714CC0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x80714CC4: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80714CC8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80714CCC: lh          $v0, 0x144($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X144);
    // 0x80714CD0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80714CD4: bne         $at, $zero, L_80714CEC
    if (ctx->r1 != 0) {
        // 0x80714CD8: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80714CEC;
    }
    // 0x80714CD8: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x80714CDC: beq         $at, $zero, L_80714CEC
    if (ctx->r1 == 0) {
        // 0x80714CE0: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80714CEC;
    }
    // 0x80714CE0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80714CE4: b           L_80714CF0
    // 0x80714CE8: sw          $t3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r11;
        goto L_80714CF0;
    // 0x80714CE8: sw          $t3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r11;
L_80714CEC:
    // 0x80714CEC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_80714CF0:
    // 0x80714CF0: lbu         $t5, 0x50($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X50);
L_80714CF4:
    // 0x80714CF4: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X187C) << 16);
    // 0x80714CF8: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80714CFC: beq         $t5, $zero, L_80714D10
    if (ctx->r13 == 0) {
        // 0x80714D00: addiu       $v1, $a1, 0x38
        ctx->r3 = ADD32(ctx->r5, 0X38);
            goto L_80714D10;
    }
    // 0x80714D00: addiu       $v1, $a1, 0x38
    ctx->r3 = ADD32(ctx->r5, 0X38);
    // 0x80714D04: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(730, 0X1878) << 16);
    // 0x80714D08: b           L_80714D14
    // 0x80714D0C: lwc1        $f2, 0x6098($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1878));
        goto L_80714D14;
    // 0x80714D0C: lwc1        $f2, 0x6098($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X1878));
L_80714D10:
    // 0x80714D10: lwc1        $f2, 0x609C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(730, 0X187C));
L_80714D14:
    // 0x80714D14: lwc1        $f0, 0x44($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X44);
L_80714D18:
    // 0x80714D18: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80714D1C: lw          $t7, 0x5A4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X5A4);
    // 0x80714D20: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80714D24: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x80714D28: bgez        $v0, L_80714D18
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80714D2C: swc1        $f0, 0x44($t7)
        MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
            goto L_80714D18;
    }
    // 0x80714D2C: swc1        $f0, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f0.u32l;
    // 0x80714D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80714D34: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80714D38: jr          $ra
    // 0x80714D3C: nop

    return;
    // 0x80714D3C: nop

;}
RECOMP_FUNC void func_805CA8A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA8A0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805CA8A4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805CA8A8: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x805CA8AC: lui         $t7, 0x805D
    ctx->r15 = S32(RELOC_HI16(453, 0X6F8) << 16);
    // 0x805CA8B0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805CA8B4: lh          $t7, -0x50B8($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(453, 0X6F8));
    // 0x805CA8B8: jr          $ra
    // 0x805CA8BC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
    return;
    // 0x805CA8BC: sh          $t7, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_800689E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800689E8: jr          $ra
    // 0x800689EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800689EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80445C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445C24: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80445C28: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C2C: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x80445C30: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C34: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80445C38: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x80445C3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80445C40: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80445C44: jr          $ra
    // 0x80445C48: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    return;
    // 0x80445C48: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void func_807BBF84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BBF84: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x807BBF88: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6EA8) << 16);
    // 0x807BBF8C: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(898, 0X5E10) << 16);
    // 0x807BBF90: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x807BBF94: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(898, 0XB90) << 16);
    // 0x807BBF98: lwc1        $f0, 0x2B68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6EA8));
    // 0x807BBF9C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x807BBFA0: addiu       $t7, $t7, 0x1AD0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(898, 0X5E10));
    // 0x807BBFA4: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x807BBFA8: addiu       $t9, $t9, -0x37B0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(898, 0XB90));
    // 0x807BBFAC: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(898, 0X6EAC) << 16);
    // 0x807BBFB0: lui         $t3, 0x807C
    ctx->r11 = S32(RELOC_HI16(898, 0X6BD0) << 16);
    // 0x807BBFB4: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x807BBFB8: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x807BBFBC: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x807BBFC0: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x807BBFC4: lwc1        $f12, 0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X4);
    // 0x807BBFC8: addiu       $t3, $t3, 0x2890
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(898, 0X6BD0));
    // 0x807BBFCC: lwc1        $f14, 0x2B6C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(898, 0X6EAC));
    // 0x807BBFD0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x807BBFD4: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x807BBFD8: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
L_807BBFDC:
    // 0x807BBFDC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807BBFE0: lbu         $t1, 0x58($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X58);
    // 0x807BBFE4: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x807BBFE8: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x807BBFEC: bne         $t1, $zero, L_807BC010
    if (ctx->r9 != 0) {
        // 0x807BBFF0: lw          $a1, 0x0($t6)
        ctx->r5 = MEM_W(ctx->r14, 0X0);
            goto L_807BC010;
    }
    // 0x807BBFF0: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x807BBFF4: bne         $t2, $t0, L_807BC008
    if (ctx->r10 != ctx->r8) {
        // 0x807BBFF8: addu        $t7, $t3, $v0
        ctx->r15 = ADD32(ctx->r11, ctx->r2);
            goto L_807BC008;
    }
    // 0x807BBFF8: addu        $t7, $t3, $v0
    ctx->r15 = ADD32(ctx->r11, ctx->r2);
    // 0x807BBFFC: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x807BC000: b           L_807BC014
    // 0x807BC004: sb          $t8, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r24;
        goto L_807BC014;
    // 0x807BC004: sb          $t8, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r24;
L_807BC008:
    // 0x807BC008: b           L_807BC014
    // 0x807BC00C: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
        goto L_807BC014;
    // 0x807BC00C: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
L_807BC010:
    // 0x807BC010: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
L_807BC014:
    // 0x807BC014: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x807BC018: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807BC01C: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x807BC020: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x807BC024: nop

    // 0x807BC028: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807BC02C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807BC030: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x807BC034: lw          $t5, -0x14($a2)
    ctx->r13 = MEM_W(ctx->r6, -0X14);
    // 0x807BC038: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x807BC03C: nop

    // 0x807BC040: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807BC044: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x807BC048: swc1        $f18, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f18.u32l;
    // 0x807BC04C: lwc1        $f4, -0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, -0X10);
    // 0x807BC050: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807BC054: swc1        $f6, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f6.u32l;
    // 0x807BC058: lwc1        $f8, -0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, -0XC);
    // 0x807BC05C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x807BC060: swc1        $f10, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f10.u32l;
    // 0x807BC064: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x807BC068: swc1        $f16, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f16.u32l;
    // 0x807BC06C: lw          $t6, -0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X4);
    // 0x807BC070: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x807BC074: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807BC078: sw          $t6, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r14;
    // 0x807BC07C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807BC080: lbu         $t1, 0x58($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X58);
    // 0x807BC084: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x807BC088: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x807BC08C: bne         $t1, $zero, L_807BC0B0
    if (ctx->r9 != 0) {
        // 0x807BC090: lw          $a1, 0x0($t8)
        ctx->r5 = MEM_W(ctx->r24, 0X0);
            goto L_807BC0B0;
    }
    // 0x807BC090: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x807BC094: bne         $t2, $t0, L_807BC0A8
    if (ctx->r10 != ctx->r8) {
        // 0x807BC098: addu        $t9, $t3, $v0
        ctx->r25 = ADD32(ctx->r11, ctx->r2);
            goto L_807BC0A8;
    }
    // 0x807BC098: addu        $t9, $t3, $v0
    ctx->r25 = ADD32(ctx->r11, ctx->r2);
    // 0x807BC09C: lbu         $t5, 0x0($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X0);
    // 0x807BC0A0: b           L_807BC0B4
    // 0x807BC0A4: sb          $t5, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r13;
        goto L_807BC0B4;
    // 0x807BC0A4: sb          $t5, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r13;
L_807BC0A8:
    // 0x807BC0A8: b           L_807BC0B4
    // 0x807BC0AC: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
        goto L_807BC0B4;
    // 0x807BC0AC: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
L_807BC0B0:
    // 0x807BC0B0: sb          $t1, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r9;
L_807BC0B4:
    // 0x807BC0B4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x807BC0B8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x807BC0BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807BC0C0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x807BC0C4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x807BC0C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x807BC0CC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x807BC0D0: swc1        $f6, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f6.u32l;
    // 0x807BC0D4: lw          $t7, -0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X14);
    // 0x807BC0D8: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x807BC0DC: nop

    // 0x807BC0E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807BC0E4: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x807BC0E8: swc1        $f16, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f16.u32l;
    // 0x807BC0EC: lwc1        $f18, -0x10($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, -0X10);
    // 0x807BC0F0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807BC0F4: swc1        $f4, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f4.u32l;
    // 0x807BC0F8: lwc1        $f6, -0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0XC);
    // 0x807BC0FC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x807BC100: swc1        $f8, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f8.u32l;
    // 0x807BC104: lwc1        $f10, -0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X8);
    // 0x807BC108: swc1        $f10, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f10.u32l;
    // 0x807BC10C: lw          $t8, -0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, -0X4);
    // 0x807BC110: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x807BC114: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x807BC118: bne         $a3, $t4, L_807BBFDC
    if (ctx->r7 != ctx->r12) {
        // 0x807BC11C: sw          $t8, 0x138($a1)
        MEM_W(0X138, ctx->r5) = ctx->r24;
            goto L_807BBFDC;
    }
    // 0x807BC11C: sw          $t8, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r24;
    // 0x807BC120: jr          $ra
    // 0x807BC124: nop

    return;
    // 0x807BC124: nop

;}
RECOMP_FUNC void func_80028BFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028BFC: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80028C00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028C04: lwc1        $f12, -0x228($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X228);
    // 0x80028C08: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x80028C0C: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80028C10: lwc1        $f6, 0xA8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XA8);
    // 0x80028C14: lwc1        $f8, 0x84($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80028C18: lwc1        $f10, 0xA8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x80028C1C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80028C20: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80028C24: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80028C28: nop

    // 0x80028C2C: bc1t        L_80028C48
    if (c1cs) {
        // 0x80028C30: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80028C48;
    }
    // 0x80028C30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028C34: lwc1        $f16, -0x224($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X224);
    // 0x80028C38: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80028C3C: nop

    // 0x80028C40: bc1f        L_80028C8C
    if (!c1cs) {
        // 0x80028C44: nop
    
            goto L_80028C8C;
    }
    // 0x80028C44: nop

L_80028C48:
    // 0x80028C48: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80028C4C: nop

    // 0x80028C50: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80028C54: nop

    // 0x80028C58: bc1fl       L_80028C7C
    if (!c1cs) {
        // 0x80028C5C: lw          $t7, 0x34($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X34);
            goto L_80028C7C;
    }
    goto skip_0;
    // 0x80028C5C: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
    skip_0:
    // 0x80028C60: lw          $t6, 0x34($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X34);
    // 0x80028C64: slti        $at, $t6, 0x11A
    ctx->r1 = SIGNED(ctx->r14) < 0X11A ? 1 : 0;
    // 0x80028C68: beq         $at, $zero, L_80028C8C
    if (ctx->r1 == 0) {
        // 0x80028C6C: nop
    
            goto L_80028C8C;
    }
    // 0x80028C6C: nop

    // 0x80028C70: b           L_80028C8C
    // 0x80028C74: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_80028C8C;
    // 0x80028C74: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80028C78: lw          $t7, 0x34($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X34);
L_80028C7C:
    // 0x80028C7C: slti        $at, $t7, 0x27
    ctx->r1 = SIGNED(ctx->r15) < 0X27 ? 1 : 0;
    // 0x80028C80: bne         $at, $zero, L_80028C8C
    if (ctx->r1 != 0) {
        // 0x80028C84: nop
    
            goto L_80028C8C;
    }
    // 0x80028C84: nop

    // 0x80028C88: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80028C8C:
    // 0x80028C8C: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80028C90: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80028C94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80028C98: c.lt.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl < ctx->f14.fl;
    // 0x80028C9C: nop

    // 0x80028CA0: bc1fl       L_80028CB4
    if (!c1cs) {
        // 0x80028CA4: add.s       $f4, $f0, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
            goto L_80028CB4;
    }
    goto skip_1;
    // 0x80028CA4: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    skip_1:
    // 0x80028CA8: b           L_80028CB8
    // 0x80028CAC: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
        goto L_80028CB8;
    // 0x80028CAC: swc1        $f0, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f0.u32l;
    // 0x80028CB0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
L_80028CB4:
    // 0x80028CB4: swc1        $f4, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f4.u32l;
L_80028CB8:
    // 0x80028CB8: lwc1        $f0, 0xAC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XAC);
    // 0x80028CBC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80028CC0: nop

    // 0x80028CC4: bc1tl       L_80028CE4
    if (c1cs) {
        // 0x80028CC8: c.lt.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
            goto L_80028CE4;
    }
    goto skip_2;
    // 0x80028CC8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    skip_2:
    // 0x80028CCC: lwc1        $f6, -0x220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X220);
    // 0x80028CD0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80028CD4: nop

    // 0x80028CD8: bc1fl       L_80028D34
    if (!c1cs) {
        // 0x80028CDC: swc1        $f14, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f14.u32l;
            goto L_80028D34;
    }
    goto skip_3;
    // 0x80028CDC: swc1        $f14, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f14.u32l;
    skip_3:
    // 0x80028CE0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
L_80028CE4:
    // 0x80028CE4: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80028CE8: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80028CEC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80028CF0: bc1f        L_80028D1C
    if (!c1cs) {
        // 0x80028CF4: addu        $t3, $t3, $t2
        ctx->r11 = ADD32(ctx->r11, ctx->r10);
            goto L_80028D1C;
    }
    // 0x80028CF4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80028CF8: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80028CFC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80028D00: lw          $t9, -0x2234($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2234);
    // 0x80028D04: lw          $t0, 0x34($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X34);
    // 0x80028D08: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80028D0C: beql        $at, $zero, L_80028D34
    if (ctx->r1 == 0) {
        // 0x80028D10: swc1        $f14, 0xAC($a0)
        MEM_W(0XAC, ctx->r4) = ctx->f14.u32l;
            goto L_80028D34;
    }
    goto skip_4;
    // 0x80028D10: swc1        $f14, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f14.u32l;
    skip_4:
    // 0x80028D14: jr          $ra
    // 0x80028D18: nop

    return;
    // 0x80028D18: nop

L_80028D1C:
    // 0x80028D1C: lw          $t1, 0x34($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X34);
    // 0x80028D20: lw          $t3, -0x227C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X227C);
    // 0x80028D24: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80028D28: bne         $at, $zero, L_80028D34
    if (ctx->r1 != 0) {
        // 0x80028D2C: nop
    
            goto L_80028D34;
    }
    // 0x80028D2C: nop

    // 0x80028D30: swc1        $f14, 0xAC($a0)
    MEM_W(0XAC, ctx->r4) = ctx->f14.u32l;
L_80028D34:
    // 0x80028D34: jr          $ra
    // 0x80028D38: nop

    return;
    // 0x80028D38: nop

;}
RECOMP_FUNC void func_807167F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807167F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807167FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716800: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80716804: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80716808: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8071680C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80716810: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80716814: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80716818: addiu       $t6, $zero, 0x99C
    ctx->r14 = ADD32(0, 0X99C);
    // 0x8071681C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80716820: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80716824: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x80716828: addiu       $a1, $zero, 0x1A4
    ctx->r5 = ADD32(0, 0X1A4);
    // 0x8071682C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716830: jal         0x8071637C
    // 0x80716834: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x80716834: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80716838: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8071683C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716840: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80716844: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80716848: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x8071684C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x80716850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80716854: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80716858: jr          $ra
    // 0x8071685C: nop

    return;
    // 0x8071685C: nop

;}
RECOMP_FUNC void func_80461914(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80461918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046191C: jal         0x80064D1C
    // 0x80461920: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80461920: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80461924: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461928: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046192C: jr          $ra
    // 0x80461930: nop

    return;
    // 0x80461930: nop

;}
RECOMP_FUNC void func_80561450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80561450: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(366, 0X10) << 16);
    // 0x80561454: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80561458: jr          $ra
    // 0x8056145C: addiu       $v0, $v0, 0x1460
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(366, 0X10));
    return;
    // 0x8056145C: addiu       $v0, $v0, 0x1460
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(366, 0X10));
;}
RECOMP_FUNC void func_805532D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805532D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805532D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805532D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805532DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805532E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805532E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805532E8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805532EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805532F0: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x805532F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805532F8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x805532FC: jal         0x8004D150
    // 0x80553300: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x80553300: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x80553304: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80553308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8055330C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80553310: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x80553314: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80553318: lbu         $t9, 0x2C($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2C);
    // 0x8055331C: beq         $t9, $zero, L_80553360
    if (ctx->r25 == 0) {
        // 0x80553320: nop
    
            goto L_80553360;
    }
    // 0x80553320: nop

    // 0x80553324: jal         0x8004D618
    // 0x80553328: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x80553328: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_1:
    // 0x8055332C: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x80553330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80553334: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x80553338: jal         0x8004A97C
    // 0x8055333C: lhu         $a0, 0x18($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X18);
    func_8004A97C(rdram, ctx);
        goto after_2;
    // 0x8055333C: lhu         $a0, 0x18($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X18);
    after_2:
    // 0x80553340: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80553344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80553348: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8055334C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80553350: swc1        $f6, 0xD60($t2)
    MEM_W(0XD60, ctx->r10) = ctx->f6.u32l;
    // 0x80553354: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x80553358: ori         $t4, $t3, 0xF00
    ctx->r12 = ctx->r11 | 0XF00;
    // 0x8055335C: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
L_80553360:
    // 0x80553360: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80553364: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80553368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8055336C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80553370: jal         0x8004D150
    // 0x80553374: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_3;
    // 0x80553374: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_3:
    // 0x80553378: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8055337C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80553380: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80553384: lw          $t6, 0x40($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X40);
    // 0x80553388: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8055338C: lbu         $t7, 0x44($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X44);
    // 0x80553390: beql        $t7, $zero, L_805533C8
    if (ctx->r15 == 0) {
        // 0x80553394: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805533C8;
    }
    goto skip_0;
    // 0x80553394: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80553398: jal         0x8004D618
    // 0x8055339C: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x8055339C: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    after_4:
    // 0x805533A0: jal         0x8055386C
    // 0x805533A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8055386C(rdram, ctx);
        goto after_5;
    // 0x805533A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805533A8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805533AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805533B0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x805533B4: swc1        $f8, 0xD60($t8)
    MEM_W(0XD60, ctx->r24) = ctx->f8.u32l;
    // 0x805533B8: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x805533BC: ori         $t0, $t9, 0xF0
    ctx->r8 = ctx->r25 | 0XF0;
    // 0x805533C0: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
    // 0x805533C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805533C8:
    // 0x805533C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805533CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805533D0: jr          $ra
    // 0x805533D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805533D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8041D864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041D868: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041D86C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8041D870: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(29, 0X2FE8) << 16);
    // 0x8041D874: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8041D878: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8041D87C: addiu       $t6, $t6, 0x648
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(29, 0X2FE8));
    // 0x8041D880: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8041D884: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8041D888: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8041D88C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8041D890: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041D894: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8041D898: jal         0x8041DAD8
    // 0x8041D89C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8041DAD8(rdram, ctx);
        goto after_0;
    // 0x8041D89C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8041D8A0: jal         0x8041D7EC
    // 0x8041D8A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8041D7EC(rdram, ctx);
        goto after_1;
    // 0x8041D8A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8041D8A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8041D8AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041D8B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041D8B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8041D8B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041D8BC: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x8041D8C0: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x8041D8C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041D8C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041D8CC: jr          $ra
    // 0x8041D8D0: nop

    return;
    // 0x8041D8D0: nop

;}
RECOMP_FUNC void func_80409110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80409110: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80409114: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80409118: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8040911C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80409120: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80409124: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80409128: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8040912C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80409130: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80409134: addiu       $s0, $a0, 0xB50
    ctx->r16 = ADD32(ctx->r4, 0XB50);
    // 0x80409138: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8040913C: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
L_80409140:
    // 0x80409140: lw          $v0, 0x2C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C);
    // 0x80409144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80409148: beql        $v0, $zero, L_80409160
    if (ctx->r2 == 0) {
        // 0x8040914C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80409160;
    }
    goto skip_0;
    // 0x8040914C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80409150: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80409154: jalr        $v0
    // 0x80409158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80409158: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8040915C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80409160:
    // 0x80409160: bne         $s1, $s3, L_80409140
    if (ctx->r17 != ctx->r19) {
        // 0x80409164: addiu       $s0, $s0, 0x30
        ctx->r16 = ADD32(ctx->r16, 0X30);
            goto L_80409140;
    }
    // 0x80409164: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x80409168: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8040916C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80409170: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80409174: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80409178: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8040917C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80409180: jr          $ra
    // 0x80409184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80409184: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805264B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805264B4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805264B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805264BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805264C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805264C4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x805264C8: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805264CC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x805264D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805264D4: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x805264D8: lw          $s0, 0x1F4($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X1F4);
    // 0x805264DC: jal         0x8004921C
    // 0x805264E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x805264E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x805264E4: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x805264E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805264EC: jal         0x8004921C
    // 0x805264F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x805264F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x805264F4: lbu         $t9, 0x27($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X27);
    // 0x805264F8: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x805264FC: lbu         $t2, 0x145($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X145);
    // 0x80526500: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80526504: lw          $v1, 0x168($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X168);
    // 0x80526508: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8052650C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80526510: lw          $t4, 0x80($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X80);
    // 0x80526514: lw          $a2, 0x88($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X88);
    // 0x80526518: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8052651C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80526520: mflo        $t1
    ctx->r9 = lo;
    // 0x80526524: nop

    // 0x80526528: nop

    // 0x8052652C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80526530: mflo        $t3
    ctx->r11 = lo;
    // 0x80526534: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80526538: jal         0x80063F08
    // 0x8052653C: nop

    func_80063F08(rdram, ctx);
        goto after_2;
    // 0x8052653C: nop

    after_2:
    // 0x80526540: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80526544: lh          $t5, 0x50($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X50);
    // 0x80526548: sh          $t5, 0x80($s0)
    MEM_H(0X80, ctx->r16) = ctx->r13;
    // 0x8052654C: lh          $t6, 0x52($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X52);
    // 0x80526550: sh          $t6, 0x82($s0)
    MEM_H(0X82, ctx->r16) = ctx->r14;
    // 0x80526554: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80526558: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8052655C: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80526560: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80526564: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80526568: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8052656C: jr          $ra
    // 0x80526570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80526570: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805225E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805225E4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805225E8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x805225EC: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x805225F0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x805225F4: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x805225F8: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x805225FC: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80522600: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80522604: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80522608: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8052260C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x80522610: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80522614: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80522618: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8052261C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80522620: jal         0x8004700C
    // 0x80522624: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80522624: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80522628: beql        $v0, $zero, L_805227AC
    if (ctx->r2 == 0) {
        // 0x8052262C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_805227AC;
    }
    goto skip_0;
    // 0x8052262C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80522630: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x80522634: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80522638: bnel        $t7, $at, L_805227AC
    if (ctx->r15 != ctx->r1) {
        // 0x8052263C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_805227AC;
    }
    goto skip_1;
    // 0x8052263C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_1:
    // 0x80522640: lbu         $t8, 0x165($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X165);
    // 0x80522644: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x80522648: bnel        $t8, $zero, L_805227AC
    if (ctx->r24 != 0) {
        // 0x8052264C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_805227AC;
    }
    goto skip_2;
    // 0x8052264C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x80522650: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80522654: lui         $s5, 0x800F
    ctx->r21 = S32(0X800F << 16);
    // 0x80522658: addiu       $s5, $s5, 0x7EA0
    ctx->r21 = ADD32(ctx->r21, 0X7EA0);
    // 0x8052265C: bne         $t9, $zero, L_805227A8
    if (ctx->r25 != 0) {
        // 0x80522660: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805227A8;
    }
    // 0x80522660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80522664: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x80522668: lw          $t1, 0xE88($s5)
    ctx->r9 = MEM_W(ctx->r21, 0XE88);
    // 0x8052266C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80522670: jal         0x800677F8
    // 0x80522674: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    func_800677F8(rdram, ctx);
        goto after_1;
    // 0x80522674: sw          $v0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r2;
    after_1:
    // 0x80522678: lw          $a0, 0x34($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X34);
    // 0x8052267C: jal         0x80067BBC
    // 0x80522680: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80522680: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    after_2:
    // 0x80522684: addiu       $a0, $zero, 0xC2
    ctx->r4 = ADD32(0, 0XC2);
    // 0x80522688: jal         0x80067818
    // 0x8052268C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8052268C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80522690: jal         0x80047090
    // 0x80522694: addiu       $a0, $zero, 0x4733
    ctx->r4 = ADD32(0, 0X4733);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80522694: addiu       $a0, $zero, 0x4733
    ctx->r4 = ADD32(0, 0X4733);
    after_4:
    // 0x80522698: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052269C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x805226A0: lui         $at, 0x4733
    ctx->r1 = S32(0X4733 << 16);
    // 0x805226A4: lw          $v1, 0x478($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X478);
    // 0x805226A8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x805226AC: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x805226B0: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x805226B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805226B8: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x805226BC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x805226C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805226C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805226C8: lwc1        $f4, 0x44($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X44);
    // 0x805226CC: lwc1        $f10, 0x34($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X34);
    // 0x805226D0: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x805226D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x805226D8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805226DC: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x805226E0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x805226E4: jal         0x8004613C
    // 0x805226E8: nop

    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x805226E8: nop

    after_5:
    // 0x805226EC: beq         $v0, $zero, L_805226FC
    if (ctx->r2 == 0) {
        // 0x805226F0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805226FC;
    }
    // 0x805226F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805226F4: jal         0x80044194
    // 0x805226F8: nop

    func_80044194(rdram, ctx);
        goto after_6;
    // 0x805226F8: nop

    after_6:
L_805226FC:
    // 0x805226FC: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80522700: lui         $s0, 0x8052
    ctx->r16 = S32(RELOC_HI16(321, 0X15B4) << 16);
    // 0x80522704: lui         $s3, 0x8052
    ctx->r19 = S32(RELOC_HI16(321, 0X15C2) << 16);
    // 0x80522708: lui         $s2, 0x8052
    ctx->r18 = S32(RELOC_HI16(321, 0X20D0) << 16);
    // 0x8052270C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80522710: addiu       $s2, $s2, 0x4380
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(321, 0X20D0));
    // 0x80522714: addiu       $s3, $s3, 0x3872
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(321, 0X15C2));
    // 0x80522718: addiu       $s0, $s0, 0x3864
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(321, 0X15B4));
    // 0x8052271C: addiu       $s1, $zero, 0x3FF
    ctx->r17 = ADD32(0, 0X3FF);
L_80522720:
    // 0x80522720: jal         0x80047090
    // 0x80522724: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    func_80047090(rdram, ctx);
        goto after_7;
    // 0x80522724: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_7:
    // 0x80522728: beq         $s1, $v0, L_80522778
    if (ctx->r17 == ctx->r2) {
        // 0x8052272C: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_80522778;
    }
    // 0x8052272C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80522730: lw          $v1, 0x478($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X478);
    // 0x80522734: lwc1        $f16, 0x44($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X44);
    // 0x80522738: lhu         $t2, 0x0($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X0);
    // 0x8052273C: lwc1        $f8, 0x34($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80522740: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80522744: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80522748: ori         $t4, $t3, 0x2000
    ctx->r12 = ctx->r11 | 0X2000;
    // 0x8052274C: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80522750: lw          $a2, 0x30($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X30);
    // 0x80522754: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80522758: or          $a1, $t4, $t0
    ctx->r5 = ctx->r12 | ctx->r8;
    // 0x8052275C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80522760: jal         0x80046804
    // 0x80522764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80046804(rdram, ctx);
        goto after_8;
    // 0x80522764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x80522768: beq         $v0, $zero, L_80522778
    if (ctx->r2 == 0) {
        // 0x8052276C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80522778;
    }
    // 0x8052276C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80522770: jal         0x80044194
    // 0x80522774: nop

    func_80044194(rdram, ctx);
        goto after_9;
    // 0x80522774: nop

    after_9:
L_80522778:
    // 0x80522778: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8052277C: bne         $s0, $s3, L_80522720
    if (ctx->r16 != ctx->r19) {
        // 0x80522780: nop
    
            goto L_80522720;
    }
    // 0x80522780: nop

    // 0x80522784: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80522788: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8052278C: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80522790: sw          $t5, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r13;
    // 0x80522794: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80522798: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8052279C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x805227A0: jal         0x80523830
    // 0x805227A4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    func_80523830(rdram, ctx);
        goto after_10;
    // 0x805227A4: sw          $t7, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r15;
    after_10:
L_805227A8:
    // 0x805227A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_805227AC:
    // 0x805227AC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805227B0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805227B4: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x805227B8: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x805227BC: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x805227C0: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x805227C4: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x805227C8: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x805227CC: jr          $ra
    // 0x805227D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x805227D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80532C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532C2C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80532C30: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80532C34: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80532C38: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(345, 0X1834) << 16);
    // 0x80532C3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80532C40: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80532C44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80532C48: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80532C4C: lw          $t8, 0x4304($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(345, 0X1834));
    // 0x80532C50: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80532C54: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80532C58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80532C5C: jal         0x80048490
    // 0x80532C60: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80532C60: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80532C64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80532C68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80532C6C: nop

    // 0x80532C70: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x80532C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532C7C: jr          $ra
    // 0x80532C80: nop

    return;
    // 0x80532C80: nop

;}
RECOMP_FUNC void func_8007E200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E200: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8007E204: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8007E208: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8007E20C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8007E210: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8007E214: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8007E218: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8007E21C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007E220: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8007E224: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8007E228: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007E22C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007E230: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x8007E234: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8007E238: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E23C: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8007E240: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007E244: lw          $s5, 0xA4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XA4);
    // 0x8007E248: bne         $a2, $at, L_8007E258
    if (ctx->r6 != ctx->r1) {
        // 0x8007E24C: sw          $t7, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r15;
            goto L_8007E258;
    }
    // 0x8007E24C: sw          $t7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r15;
    // 0x8007E250: b           L_8007E25C
    // 0x8007E254: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
        goto L_8007E25C;
    // 0x8007E254: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
L_8007E258:
    // 0x8007E258: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
L_8007E25C:
    // 0x8007E25C: sllv        $v1, $v0, $a3
    ctx->r3 = S32(ctx->r2 << (ctx->r7 & 31));
    // 0x8007E260: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007E264: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x8007E268: multu       $v1, $s5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E26C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007E270: mflo        $t8
    ctx->r24 = lo;
    // 0x8007E274: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8007E278: bne         $at, $zero, L_8007E2BC
    if (ctx->r1 != 0) {
        // 0x8007E27C: nop
    
            goto L_8007E2BC;
    }
    // 0x8007E27C: nop

    // 0x8007E280: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x8007E284: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8007E288: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8007E28C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007E290: sw          $s5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r21;
    // 0x8007E294: jal         0x80077084
    // 0x8007E298: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    func_80077084(rdram, ctx);
        goto after_0;
    // 0x8007E298: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8007E29C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8007E2A0: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8007E2A4: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8007E2A8: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x8007E2AC: jal         0x8007E134
    // 0x8007E2B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    func_8007E134(rdram, ctx);
        goto after_1;
    // 0x8007E2B0: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_1:
    // 0x8007E2B4: b           L_8007E390
    // 0x8007E2B8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
        goto L_8007E390;
    // 0x8007E2B8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
L_8007E2BC:
    // 0x8007E2BC: div         $zero, $a0, $v1
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r3)));
    // 0x8007E2C0: mflo        $a1
    ctx->r5 = lo;
    // 0x8007E2C4: addiu       $s7, $s5, -0x1
    ctx->r23 = ADD32(ctx->r21, -0X1);
    // 0x8007E2C8: bne         $v1, $zero, L_8007E2D4
    if (ctx->r3 != 0) {
        // 0x8007E2CC: nop
    
            goto L_8007E2D4;
    }
    // 0x8007E2CC: nop

    // 0x8007E2D0: break       7
    do_break(2148000464);
L_8007E2D4:
    // 0x8007E2D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E2D8: bne         $v1, $at, L_8007E2EC
    if (ctx->r3 != ctx->r1) {
        // 0x8007E2DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E2EC;
    }
    // 0x8007E2DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E2E0: bne         $a0, $at, L_8007E2EC
    if (ctx->r4 != ctx->r1) {
        // 0x8007E2E4: nop
    
            goto L_8007E2EC;
    }
    // 0x8007E2E4: nop

    // 0x8007E2E8: break       6
    do_break(2148000488);
L_8007E2EC:
    // 0x8007E2EC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007E2F0: blez        $s7, L_8007E38C
    if (SIGNED(ctx->r23) <= 0) {
        // 0x8007E2F4: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_8007E38C;
    }
    // 0x8007E2F4: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x8007E2F8: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E2FC: addiu       $fp, $v0, -0x1
    ctx->r30 = ADD32(ctx->r2, -0X1);
    // 0x8007E300: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8007E304: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    // 0x8007E308: addiu       $s6, $sp, 0x8C
    ctx->r22 = ADD32(ctx->r29, 0X8C);
    // 0x8007E30C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E310: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x8007E314: nop

L_8007E318:
    // 0x8007E318: addu        $s2, $s0, $s1
    ctx->r18 = ADD32(ctx->r16, ctx->r17);
    // 0x8007E31C: slt         $at, $s5, $s2
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8007E320: lw          $v0, 0xA0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA0);
    // 0x8007E324: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x8007E328: beq         $at, $zero, L_8007E338
    if (ctx->r1 == 0) {
        // 0x8007E32C: lw          $a3, 0x9C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X9C);
            goto L_8007E338;
    }
    // 0x8007E32C: lw          $a3, 0x9C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X9C);
    // 0x8007E330: subu        $s1, $s5, $s0
    ctx->r17 = SUB32(ctx->r21, ctx->r16);
    // 0x8007E334: addu        $s2, $s0, $s1
    ctx->r18 = ADD32(ctx->r16, ctx->r17);
L_8007E338:
    // 0x8007E338: addiu       $s3, $s1, -0x1
    ctx->r19 = ADD32(ctx->r17, -0X1);
    // 0x8007E33C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8007E340: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8007E344: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007E348: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007E34C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007E350: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x8007E354: jal         0x80077084
    // 0x8007E358: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    func_80077084(rdram, ctx);
        goto after_2;
    // 0x8007E358: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    after_2:
    // 0x8007E35C: lw          $t1, 0xAC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XAC);
    // 0x8007E360: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8007E364: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8007E368: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8007E36C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8007E370: jal         0x8007E134
    // 0x8007E374: addu        $a2, $t1, $s0
    ctx->r6 = ADD32(ctx->r9, ctx->r16);
    func_8007E134(rdram, ctx);
        goto after_3;
    // 0x8007E374: addu        $a2, $t1, $s0
    ctx->r6 = ADD32(ctx->r9, ctx->r16);
    after_3:
    // 0x8007E378: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8007E37C: addiu       $s0, $s2, -0x1
    ctx->r16 = ADD32(ctx->r18, -0X1);
    // 0x8007E380: slt         $at, $s0, $s7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8007E384: bne         $at, $zero, L_8007E318
    if (ctx->r1 != 0) {
        // 0x8007E388: addu        $s4, $s4, $t2
        ctx->r20 = ADD32(ctx->r20, ctx->r10);
            goto L_8007E318;
    }
    // 0x8007E388: addu        $s4, $s4, $t2
    ctx->r20 = ADD32(ctx->r20, ctx->r10);
L_8007E38C:
    // 0x8007E38C: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
L_8007E390:
    // 0x8007E390: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x8007E394: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007E398: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8007E39C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007E3A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E3A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007E3A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8007E3AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8007E3B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E3B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8007E3B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8007E3BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8007E3C0: jr          $ra
    // 0x8007E3C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8007E3C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x8007E3C8: nop

    // 0x8007E3CC: nop

;}
RECOMP_FUNC void func_805304DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805304DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805304E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805304E4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x805304E8: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805304EC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805304F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805304F4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x805304F8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x805304FC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(336, 0X400) << 16);
    // 0x80530500: lwc1        $f10, 0x890($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(336, 0X400));
    // 0x80530504: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80530508: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8053050C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80530510: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80530514: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80530518: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8053051C: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80530520: lwc1        $f18, 0x6C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80530524: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80530528: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8053052C: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80530530: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80530534: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80530538: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8053053C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80530540: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80530544: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80530548: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8053054C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80530550: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80530554: jalr        $t9
    // 0x80530558: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80530558: nop

    after_0:
    // 0x8053055C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530560: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80530564: jr          $ra
    // 0x80530568: nop

    return;
    // 0x80530568: nop

;}
RECOMP_FUNC void func_8003A5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003A5EC: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8003A5F0: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8003A5F4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8003A5F8: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8003A5FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A600: lwc1        $f6, 0xCC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XCC);
    // 0x8003A604: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8003A608: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003A60C: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x8003A610: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003A614: swc1        $f18, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f18.u32l;
    // 0x8003A618: jr          $ra
    // 0x8003A61C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8003A61C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_805D2744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D274C: jal         0x805D1DF8
    // 0x805D2750: nop

    func_805D1DF8(rdram, ctx);
        goto after_0;
    // 0x805D2750: nop

    after_0:
    // 0x805D2754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2758: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D275C: jr          $ra
    // 0x805D2760: nop

    return;
    // 0x805D2760: nop

;}
RECOMP_FUNC void func_80534AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534AB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80534ABC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534AC0: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80534AC4: lwc1        $f4, 0xDC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80534AC8: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    // 0x80534ACC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80534AD0: nop

    // 0x80534AD4: bc1fl       L_80534AF0
    if (!c1cs) {
        // 0x80534AD8: addiu       $v1, $a0, 0xC4
        ctx->r3 = ADD32(ctx->r4, 0XC4);
            goto L_80534AF0;
    }
    goto skip_0;
    // 0x80534AD8: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
    skip_0:
    // 0x80534ADC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80534AE0: lwc1        $f10, 0x24($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80534AE4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80534AE8: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x80534AEC: addiu       $v1, $a0, 0xC4
    ctx->r3 = ADD32(ctx->r4, 0XC4);
L_80534AF0:
    // 0x80534AF0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80534AF4: jal         0x805347F0
    // 0x80534AF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805347F0(rdram, ctx);
        goto after_0;
    // 0x80534AF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80534AFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534B00: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80534B04: bne         $v0, $at, L_80534B24
    if (ctx->r2 != ctx->r1) {
        // 0x80534B08: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80534B24;
    }
    // 0x80534B08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80534B0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534B10: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80534B14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80534B18: jal         0x805350A0
    // 0x80534B1C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_805350A0(rdram, ctx);
        goto after_1;
    // 0x80534B1C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80534B20: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80534B24:
    // 0x80534B24: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(348, 0X1094) << 16);
    // 0x80534B28: lwc1        $f4, 0x56A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(348, 0X1094));
    // 0x80534B2C: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80534B30: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80534B34: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80534B38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80534B3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80534B40: jr          $ra
    // 0x80534B44: nop

    return;
    // 0x80534B44: nop

;}
RECOMP_FUNC void func_804462F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804462F0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804462F4: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x804462F8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804462FC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446300: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80446304: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446308: jr          $ra
    // 0x8044630C: sw          $t7, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->r15;
    return;
    // 0x8044630C: sw          $t7, 0x6CA8($at)
    MEM_W(0X6CA8, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80035FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035FEC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80035FF0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x80035FF4: lw          $t6, 0xF10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XF10);
    // 0x80035FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035FFC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80036000: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80036004: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80036008: lw          $v1, 0xF14($t8)
    ctx->r3 = MEM_W(ctx->r24, 0XF14);
    // 0x8003600C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036010: lw          $v0, 0x144($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X144);
    // 0x80036014: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80036018: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8003601C: lw          $t9, 0xC0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XC0);
    // 0x80036020: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80036024: bnel        $at, $zero, L_80036044
    if (ctx->r1 != 0) {
        // 0x80036028: lbu         $t1, 0x30($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X30);
            goto L_80036044;
    }
    goto skip_0;
    // 0x80036028: lbu         $t1, 0x30($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X30);
    skip_0:
    // 0x8003602C: lbu         $t0, 0x155($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X155);
    // 0x80036030: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80036034: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80036038: beq         $t0, $zero, L_80036060
    if (ctx->r8 == 0) {
        // 0x8003603C: nop
    
            goto L_80036060;
    }
    // 0x8003603C: nop

    // 0x80036040: lbu         $t1, 0x30($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X30);
L_80036044:
    // 0x80036044: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80036048: bne         $t1, $at, L_80036058
    if (ctx->r9 != ctx->r1) {
        // 0x8003604C: nop
    
            goto L_80036058;
    }
    // 0x8003604C: nop

    // 0x80036050: b           L_80036088
    // 0x80036054: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
        goto L_80036088;
    // 0x80036054: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
L_80036058:
    // 0x80036058: b           L_80036088
    // 0x8003605C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
        goto L_80036088;
    // 0x8003605C: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_80036060:
    // 0x80036060: lw          $t2, 0x110($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X110);
    // 0x80036064: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80036068: beql        $at, $zero, L_80036088
    if (ctx->r1 == 0) {
        // 0x8003606C: addiu       $a1, $zero, 0x35
        ctx->r5 = ADD32(0, 0X35);
            goto L_80036088;
    }
    goto skip_1;
    // 0x8003606C: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    skip_1:
    // 0x80036070: jal         0x80035ED8
    // 0x80036074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80035ED8(rdram, ctx);
        goto after_0;
    // 0x80036074: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036078: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003607C: b           L_80036088
    // 0x80036080: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
        goto L_80036088;
    // 0x80036080: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80036084: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
L_80036088:
    // 0x80036088: jal         0x8002DBE4
    // 0x8003608C: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_1;
    // 0x8003608C: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80036090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036098: jr          $ra
    // 0x8003609C: nop

    return;
    // 0x8003609C: nop

;}
RECOMP_FUNC void func_80584C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584C3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584C40: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584C44: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584C48: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584C4C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584C50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584C54: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584C58: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584C5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584C60: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584C64: jr          $ra
    // 0x80584C68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584C68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F8ABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F8ABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F8AC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8AC4: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x806F8AC8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F8ACC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806F8AD0: beq         $v0, $zero, L_806F8AF8
    if (ctx->r2 == 0) {
        // 0x806F8AD4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_806F8AF8;
    }
    // 0x806F8AD4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806F8AD8: bne         $t6, $zero, L_806F8B50
    if (ctx->r14 != 0) {
        // 0x806F8ADC: sw          $t6, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r14;
            goto L_806F8B50;
    }
    // 0x806F8ADC: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x806F8AE0: addiu       $a0, $zero, 0x218
    ctx->r4 = ADD32(0, 0X218);
    // 0x806F8AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806F8AE8: jal         0x80067818
    // 0x806F8AEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80067818(rdram, ctx);
        goto after_0;
    // 0x806F8AEC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x806F8AF0: b           L_806F8B50
    // 0x806F8AF4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_806F8B50;
    // 0x806F8AF4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_806F8AF8:
    // 0x806F8AF8: lwc1        $f0, 0x5F0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5F0);
    // 0x806F8AFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F8B00: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806F8B04: lui         $t8, 0x8070
    ctx->r24 = S32(RELOC_HI16(694, 0XEE4) << 16);
    // 0x806F8B08: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x806F8B0C: addiu       $t8, $t8, -0x790C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(694, 0XEE4));
    // 0x806F8B10: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806F8B14: nop

    // 0x806F8B18: bc1fl       L_806F8B50
    if (!c1cs) {
        // 0x806F8B1C: swc1        $f0, 0x5F0($v1)
        MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
            goto L_806F8B50;
    }
    goto skip_0;
    // 0x806F8B1C: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
    skip_0:
    // 0x806F8B20: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x806F8B24: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F8B28: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x806F8B2C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806F8B30: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F8B34: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    // 0x806F8B38: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x806F8B3C: jal         0x8005FDC4
    // 0x806F8B40: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x806F8B40: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x806F8B44: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8B48: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806F8B4C: swc1        $f0, 0x5F0($v1)
    MEM_W(0X5F0, ctx->r3) = ctx->f0.u32l;
L_806F8B50:
    // 0x806F8B50: jal         0x806F85F8
    // 0x806F8B54: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    func_806F85F8(rdram, ctx);
        goto after_2;
    // 0x806F8B54: addiu       $a0, $v1, 0x268
    ctx->r4 = ADD32(ctx->r3, 0X268);
    after_2:
    // 0x806F8B58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F8B5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F8B60: jr          $ra
    // 0x806F8B64: nop

    return;
    // 0x806F8B64: nop

;}
RECOMP_FUNC void func_8070CF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070CF08: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8070CF0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8070CF10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8070CF14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070CF18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8070CF1C: jal         0x8070CCD4
    // 0x8070CF20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    func_8070CCD4(rdram, ctx);
        goto after_0;
    // 0x8070CF20: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8070CF24: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8070CF28: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD70) << 16);
    // 0x8070CF2C: lwc1        $f2, -0x2C00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD70));
    // 0x8070CF30: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CF34: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD78) << 16);
    // 0x8070CF38: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8070CF3C: nop

    // 0x8070CF40: bc1f        L_8070CF60
    if (!c1cs) {
        // 0x8070CF44: nop
    
            goto L_8070CF60;
    }
    // 0x8070CF44: nop

    // 0x8070CF48: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD74) << 16);
    // 0x8070CF4C: lwc1        $f4, -0x2BFC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD74));
    // 0x8070CF50: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8070CF54: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8070CF58: b           L_8070CF88
    // 0x8070CF5C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
        goto L_8070CF88;
    // 0x8070CF5C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
L_8070CF60:
    // 0x8070CF60: lwc1        $f8, -0x2BF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD78));
    // 0x8070CF64: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8070CF68: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8070CF6C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8070CF70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8070CF74: nop

    // 0x8070CF78: bc1fl       L_8070CF8C
    if (!c1cs) {
        // 0x8070CF7C: lwc1        $f16, 0x50($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
            goto L_8070CF8C;
    }
    goto skip_0;
    // 0x8070CF7C: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    skip_0:
    // 0x8070CF80: swc1        $f2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f2.u32l;
    // 0x8070CF84: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
L_8070CF88:
    // 0x8070CF88: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
L_8070CF8C:
    // 0x8070CF8C: jal         0x800659EC
    // 0x8070CF90: add.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f0.fl;
    func_800659EC(rdram, ctx);
        goto after_1;
    // 0x8070CF90: add.s       $f12, $f16, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f0.fl;
    after_1:
    // 0x8070CF94: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8070CF98: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8070CF9C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8070CFA0: lw          $t6, 0xA68($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XA68);
    // 0x8070CFA4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8070CFA8: lw          $t8, 0x70($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X70);
    // 0x8070CFAC: beql        $t8, $zero, L_8070D080
    if (ctx->r24 == 0) {
        // 0x8070CFB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8070D080;
    }
    goto skip_1;
    // 0x8070CFB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8070CFB4: lw          $t9, 0xD8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD8);
    // 0x8070CFB8: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8070CFBC: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x8070CFC0: mfhi        $t0
    ctx->r8 = hi;
    // 0x8070CFC4: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8070CFC8: bnel        $t0, $zero, L_8070D080
    if (ctx->r8 != 0) {
        // 0x8070CFCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8070D080;
    }
    goto skip_2;
    // 0x8070CFCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8070CFD0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8070CFD4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8070CFD8: jal         0x8070C798
    // 0x8070CFDC: nop

    func_8070C798(rdram, ctx);
        goto after_2;
    // 0x8070CFDC: nop

    after_2:
    // 0x8070CFE0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8070CFE4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8070CFE8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8070CFEC: jal         0x8070C798
    // 0x8070CFF0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    func_8070C798(rdram, ctx);
        goto after_3;
    // 0x8070CFF0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8070CFF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8070CFF8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8070CFFC: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD7C) << 16);
    // 0x8070D000: lwc1        $f14, -0x2BF4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD7C));
    // 0x8070D004: jal         0x8070C798
    // 0x8070D008: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_8070C798(rdram, ctx);
        goto after_4;
    // 0x8070D008: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8070D00C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8070D010: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8070D014: jal         0x8070C714
    // 0x8070D018: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8070C714(rdram, ctx);
        goto after_5;
    // 0x8070D018: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_5:
    // 0x8070D01C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8070D020: lui         $t2, 0x8071
    ctx->r10 = S32(RELOC_HI16(721, 0XCE4) << 16);
    // 0x8070D024: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8070D028: lw          $t2, -0x2C8C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(721, 0XCE4));
    // 0x8070D02C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8070D030: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8070D034: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8070D038: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x8070D03C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8070D040: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8070D044: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(721, 0XD80) << 16);
    // 0x8070D048: lwc1        $f16, -0x2BF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(721, 0XD80));
    // 0x8070D04C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8070D050: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8070D054: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8070D058: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8070D05C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8070D060: lw          $t9, 0x70($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X70);
    // 0x8070D064: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8070D068: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8070D06C: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8070D070: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8070D074: jalr        $t9
    // 0x8070D078: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8070D078: nop

    after_6:
    // 0x8070D07C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8070D080:
    // 0x8070D080: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8070D084: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8070D088: jr          $ra
    // 0x8070D08C: nop

    return;
    // 0x8070D08C: nop

;}
RECOMP_FUNC void func_8075ED60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075ED60: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8075ED64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075ED68: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8075ED6C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x8075ED70: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8075ED74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8075ED78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8075ED7C: jal         0x8004921C
    // 0x8075ED80: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x8075ED80: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    after_0:
    // 0x8075ED84: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x8075ED88: lw          $a0, 0x7C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X7C);
    // 0x8075ED8C: jal         0x8004921C
    // 0x8075ED90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x8075ED90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8075ED94: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8075ED98: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8075ED9C: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8075EDA0: lw          $v1, 0x168($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X168);
    // 0x8075EDA4: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x8075EDA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8075EDAC: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x8075EDB0: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8075EDB4: lw          $t9, 0x88($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X88);
    // 0x8075EDB8: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x8075EDBC: lw          $t0, 0x1F4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1F4);
    // 0x8075EDC0: jal         0x80077338
    // 0x8075EDC4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x8075EDC4: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8075EDC8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075EDCC: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8075EDD0: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8075EDD4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8075EDD8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8075EDDC: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x8075EDE0: ori         $t9, $t9, 0xACB0
    ctx->r25 = ctx->r25 | 0XACB0;
    // 0x8075EDE4: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x8075EDE8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8075EDEC: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8075EDF0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075EDF4: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x8075EDF8: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x8075EDFC: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8075EE00: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8075EE04: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x8075EE08: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x8075EE0C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8075EE10: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x8075EE14: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8075EE18: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8075EE1C: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8075EE20: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x8075EE24: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x8075EE28: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x8075EE2C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8075EE30: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x8075EE34: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8075EE38: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x8075EE3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8075EE40: jal         0x8007711C
    // 0x8075EE44: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8075EE44: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8075EE48: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8075EE4C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8075EE50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8075EE54: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8075EE58: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8075EE5C:
    // 0x8075EE5C: lh          $t8, 0x10A($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10A);
    // 0x8075EE60: lwc1        $f8, 0x210($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X210);
    // 0x8075EE64: lh          $t7, 0x11A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X11A);
    // 0x8075EE68: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8075EE6C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8075EE70: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8075EE74: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8075EE78: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8075EE7C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8075EE80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8075EE84: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8075EE88: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x8075EE8C: nop

    // 0x8075EE90: sh          $t6, -0x36($v0)
    MEM_H(-0X36, ctx->r2) = ctx->r14;
    // 0x8075EE94: lwc1        $f6, 0x210($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X210);
    // 0x8075EE98: lh          $t6, 0xEA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XEA);
    // 0x8075EE9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8075EEA0: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8075EEA4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8075EEA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8075EEAC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8075EEB0: nop

    // 0x8075EEB4: sh          $t9, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r25;
    // 0x8075EEB8: lwc1        $f4, 0x210($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X210);
    // 0x8075EEBC: lh          $t9, 0xFA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XFA);
    // 0x8075EEC0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8075EEC4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8075EEC8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8075EECC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8075EED0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8075EED4: nop

    // 0x8075EED8: sh          $t8, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = ctx->r24;
    // 0x8075EEDC: lwc1        $f18, 0x210($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X210);
    // 0x8075EEE0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8075EEE4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8075EEE8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8075EEEC: bne         $v1, $a0, L_8075EE5C
    if (ctx->r3 != ctx->r4) {
        // 0x8075EEF0: sh          $t7, -0x6($v0)
        MEM_H(-0X6, ctx->r2) = ctx->r15;
            goto L_8075EE5C;
    }
    // 0x8075EEF0: sh          $t7, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r15;
    // 0x8075EEF4: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8075EEF8: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x8075EEFC: ori         $t6, $t6, 0x40FF
    ctx->r14 = ctx->r14 | 0X40FF;
    // 0x8075EF00: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8075EF04: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8075EF08: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x8075EF0C: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8075EF10: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8075EF14: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8075EF18: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8075EF1C: lui         $t4, 0x700
    ctx->r12 = S32(0X700 << 16);
    // 0x8075EF20: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8075EF24: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8075EF28: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8075EF2C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8075EF30: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x8075EF34: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x8075EF38: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8075EF3C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8075EF40: or          $t0, $t3, $zero
    ctx->r8 = ctx->r11 | 0;
    // 0x8075EF44: addiu       $a3, $zero, 0x7FF
    ctx->r7 = ADD32(0, 0X7FF);
    // 0x8075EF48: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8075EF4C: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8075EF50: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x8075EF54: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8075EF58: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8075EF5C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8075EF60: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8075EF64: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8075EF68: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8075EF6C: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8075EF70: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8075EF74: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8075EF78: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075EF7C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8075EF80: multu       $t3, $t5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8075EF84: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8075EF88: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8075EF8C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8075EF90: or          $t2, $t6, $zero
    ctx->r10 = ctx->r14 | 0;
    // 0x8075EF94: mflo        $v0
    ctx->r2 = lo;
    // 0x8075EF98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8075EF9C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8075EFA0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8075EFA4: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8075EFA8: beq         $at, $zero, L_8075EFB8
    if (ctx->r1 == 0) {
        // 0x8075EFAC: nop
    
            goto L_8075EFB8;
    }
    // 0x8075EFAC: nop

    // 0x8075EFB0: b           L_8075EFB8
    // 0x8075EFB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8075EFB8;
    // 0x8075EFB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8075EFB8:
    // 0x8075EFB8: bgez        $t0, L_8075EFC8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8075EFBC: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8075EFC8;
    }
    // 0x8075EFBC: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8075EFC0: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8075EFC4: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_8075EFC8:
    // 0x8075EFC8: bgtz        $v0, L_8075EFD8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8075EFCC: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8075EFD8;
    }
    // 0x8075EFCC: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8075EFD0: b           L_8075EFD8
    // 0x8075EFD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8075EFD8;
    // 0x8075EFD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8075EFD8:
    // 0x8075EFD8: bgtz        $v0, L_8075EFE8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8075EFDC: addiu       $t9, $t1, 0x7FF
        ctx->r25 = ADD32(ctx->r9, 0X7FF);
            goto L_8075EFE8;
    }
    // 0x8075EFDC: addiu       $t9, $t1, 0x7FF
    ctx->r25 = ADD32(ctx->r9, 0X7FF);
    // 0x8075EFE0: b           L_8075EFEC
    // 0x8075EFE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8075EFEC;
    // 0x8075EFE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8075EFE8:
    // 0x8075EFE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8075EFEC:
    // 0x8075EFEC: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8075EFF0: mflo        $t6
    ctx->r14 = lo;
    // 0x8075EFF4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8075EFF8: bne         $a1, $zero, L_8075F004
    if (ctx->r5 != 0) {
        // 0x8075EFFC: nop
    
            goto L_8075F004;
    }
    // 0x8075EFFC: nop

    // 0x8075F000: break       7
    do_break(2155212800);
L_8075F004:
    // 0x8075F004: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8075F008: bne         $a1, $at, L_8075F01C
    if (ctx->r5 != ctx->r1) {
        // 0x8075F00C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8075F01C;
    }
    // 0x8075F00C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8075F010: bne         $t9, $at, L_8075F01C
    if (ctx->r25 != ctx->r1) {
        // 0x8075F014: nop
    
            goto L_8075F01C;
    }
    // 0x8075F014: nop

    // 0x8075F018: break       6
    do_break(2155212824);
L_8075F01C:
    // 0x8075F01C: andi        $t9, $a3, 0xFFF
    ctx->r25 = ctx->r7 & 0XFFF;
    // 0x8075F020: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8075F024: or          $t8, $t7, $t4
    ctx->r24 = ctx->r15 | ctx->r12;
    // 0x8075F028: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8075F02C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x8075F030: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8075F034: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8075F038: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x8075F03C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x8075F040: sw          $t8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r24;
    // 0x8075F044: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8075F048: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8075F04C: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x8075F050: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8075F054: addiu       $t8, $t0, 0x7
    ctx->r24 = ADD32(ctx->r8, 0X7);
    // 0x8075F058: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8075F05C: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8075F060: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8075F064: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8075F068: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8075F06C: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x8075F070: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8075F074: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8075F078: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8075F07C: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075F080: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8075F084: addiu       $t8, $t3, -0x1
    ctx->r24 = ADD32(ctx->r11, -0X1);
    // 0x8075F088: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8075F08C: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8075F090: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8075F094: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8075F098: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8075F09C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8075F0A0: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8075F0A4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8075F0A8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8075F0AC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8075F0B0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8075F0B4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8075F0B8: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075F0BC: lui         $t8, 0x8076
    ctx->r24 = S32(RELOC_HI16(757, 0XAE0) << 16);
    // 0x8075F0C0: addiu       $t8, $t8, -0x7D0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(757, 0XAE0));
    // 0x8075F0C4: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x8075F0C8: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8075F0CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8075F0D0: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8075F0D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8075F0D8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8075F0DC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8075F0E0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8075F0E4: sw          $t6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r14;
    // 0x8075F0E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8075F0EC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8075F0F0: jr          $ra
    // 0x8075F0F4: nop

    return;
    // 0x8075F0F4: nop

;}
RECOMP_FUNC void func_80461614(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461614: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80461618: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8046161C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80461620: jal         0x8004700C
    // 0x80461624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80461624: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80461628: beq         $v0, $zero, L_804616B8
    if (ctx->r2 == 0) {
        // 0x8046162C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_804616B8;
    }
    // 0x8046162C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80461630: jal         0x804610B4
    // 0x80461634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804610B4(rdram, ctx);
        goto after_1;
    // 0x80461634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80461638: jal         0x8046136C
    // 0x8046163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8046136C(rdram, ctx);
        goto after_2;
    // 0x8046163C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80461640: jal         0x80461490
    // 0x80461644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80461490(rdram, ctx);
        goto after_3;
    // 0x80461644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80461648: jal         0x804615A8
    // 0x8046164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804615A8(rdram, ctx);
        goto after_4;
    // 0x8046164C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80461650: jal         0x80460EF0
    // 0x80461654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460EF0(rdram, ctx);
        goto after_5;
    // 0x80461654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80461658: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8046165C: lw          $t7, 0x180($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X180);
    // 0x80461660: bne         $s0, $t7, L_804616B0
    if (ctx->r16 != ctx->r15) {
        // 0x80461664: nop
    
            goto L_804616B0;
    }
    // 0x80461664: nop

    // 0x80461668: jal         0x8001D770
    // 0x8046166C: nop

    func_8001D770(rdram, ctx);
        goto after_6;
    // 0x8046166C: nop

    after_6:
    // 0x80461670: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80461674: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80461678: jal         0x80067BF8
    // 0x8046167C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_7;
    // 0x8046167C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x80461680: addiu       $a0, $zero, 0x7E
    ctx->r4 = ADD32(0, 0X7E);
    // 0x80461684: jal         0x80067818
    // 0x80461688: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x80461688: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8046168C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80461690: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80461694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80461698: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x8046169C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804616A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804616A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804616A8: jal         0x80461ACC
    // 0x804616AC: sb          $t8, 0xDC($t0)
    MEM_B(0XDC, ctx->r8) = ctx->r24;
    func_80461ACC(rdram, ctx);
        goto after_9;
    // 0x804616AC: sb          $t8, 0xDC($t0)
    MEM_B(0XDC, ctx->r8) = ctx->r24;
    after_9:
L_804616B0:
    // 0x804616B0: jal         0x80460F94
    // 0x804616B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80460F94(rdram, ctx);
        goto after_10;
    // 0x804616B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
L_804616B8:
    // 0x804616B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804616BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804616C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804616C4: jr          $ra
    // 0x804616C8: nop

    return;
    // 0x804616C8: nop

;}
RECOMP_FUNC void func_80568D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568D74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568D78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568D7C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80568D80: addiu       $at, $zero, 0x4156
    ctx->r1 = ADD32(0, 0X4156);
    // 0x80568D84: beq         $v0, $at, L_80568DA4
    if (ctx->r2 == ctx->r1) {
        // 0x80568D88: addiu       $at, $zero, 0x4162
        ctx->r1 = ADD32(0, 0X4162);
            goto L_80568DA4;
    }
    // 0x80568D88: addiu       $at, $zero, 0x4162
    ctx->r1 = ADD32(0, 0X4162);
    // 0x80568D8C: beq         $v0, $at, L_80568DB4
    if (ctx->r2 == ctx->r1) {
        // 0x80568D90: addiu       $at, $zero, 0x416E
        ctx->r1 = ADD32(0, 0X416E);
            goto L_80568DB4;
    }
    // 0x80568D90: addiu       $at, $zero, 0x416E
    ctx->r1 = ADD32(0, 0X416E);
    // 0x80568D94: beql        $v0, $at, L_80568DC8
    if (ctx->r2 == ctx->r1) {
        // 0x80568D98: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80568DC8;
    }
    goto skip_0;
    // 0x80568D98: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x80568D9C: b           L_80568DD4
    // 0x80568DA0: nop

        goto L_80568DD4;
    // 0x80568DA0: nop

L_80568DA4:
    // 0x80568DA4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568DA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568DAC: b           L_80568DD4
    // 0x80568DB0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
        goto L_80568DD4;
    // 0x80568DB0: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
L_80568DB4:
    // 0x80568DB4: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X21F4) << 16);
    // 0x80568DB8: lwc1        $f6, -0x685C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(378, 0X21F4));
    // 0x80568DBC: b           L_80568DD4
    // 0x80568DC0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
        goto L_80568DD4;
    // 0x80568DC0: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x80568DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80568DC8:
    // 0x80568DC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80568DCC: nop

    // 0x80568DD0: swc1        $f8, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f8.u32l;
L_80568DD4:
    // 0x80568DD4: jal         0x80568710
    // 0x80568DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568DDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568DE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80568DE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80568DE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568DEC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80568DF0: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x80568DF4: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568DF8: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568DFC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568E00: jal         0x80569310
    // 0x80568E04: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    func_80569310(rdram, ctx);
        goto after_1;
    // 0x80568E04: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    after_1:
    // 0x80568E08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568E0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568E10: jr          $ra
    // 0x80568E14: nop

    return;
    // 0x80568E14: nop

;}
RECOMP_FUNC void func_8041E9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E9F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8041E9F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041E9FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041EA00: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041EA04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041EA08: jal         0x8041DB1C
    // 0x8041EA0C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041EA0C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8041EA10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EA14: jal         0x8041E9A8
    // 0x8041EA18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041EA18: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041EA1C: beq         $v0, $zero, L_8041EB8C
    if (ctx->r2 == 0) {
        // 0x8041EA20: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_8041EB8C;
    }
    // 0x8041EA20: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8041EA24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8041EA28: jal         0x80048F84
    // 0x8041EA2C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8041EA2C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8041EA30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8041EA34: jal         0x80048F84
    // 0x8041EA38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8041EA38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8041EA3C: jal         0x8041E62C
    // 0x8041EA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E62C(rdram, ctx);
        goto after_4;
    // 0x8041EA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041EA44: jal         0x8041E5E8
    // 0x8041EA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_5;
    // 0x8041EA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8041EA4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EA50: jal         0x8041E430
    // 0x8041EA54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_6;
    // 0x8041EA54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8041EA58: jal         0x8041E694
    // 0x8041EA5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8041E694(rdram, ctx);
        goto after_7;
    // 0x8041EA5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8041EA60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EA64: jal         0x8041E734
    // 0x8041EA68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E734(rdram, ctx);
        goto after_8;
    // 0x8041EA68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x8041EA6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EA70: jal         0x8041E7D4
    // 0x8041EA74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E7D4(rdram, ctx);
        goto after_9;
    // 0x8041EA74: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x8041EA78: lh          $v0, 0x2C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2C);
    // 0x8041EA7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8041EA80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EA84: bne         $v0, $at, L_8041EAB0
    if (ctx->r2 != ctx->r1) {
        // 0x8041EA88: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8041EAB0;
    }
    // 0x8041EA88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EA8C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8041EA90: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8041EA94: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8041EA98: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EA9C: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x8041EAA0: jal         0x8041FE10
    // 0x8041EAA4: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    func_8041FE10(rdram, ctx);
        goto after_10;
    // 0x8041EAA4: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    after_10:
    // 0x8041EAA8: b           L_8041EB90
    // 0x8041EAAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041EB90;
    // 0x8041EAAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EAB0:
    // 0x8041EAB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8041EAB4: bne         $v0, $at, L_8041EAEC
    if (ctx->r2 != ctx->r1) {
        // 0x8041EAB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041EAEC;
    }
    // 0x8041EAB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EABC: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8041EAC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8041EAC4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041EAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041EACC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EAD0: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8041EAD4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EAD8: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x8041EADC: jal         0x8041FE10
    // 0x8041EAE0: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    func_8041FE10(rdram, ctx);
        goto after_11;
    // 0x8041EAE0: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    after_11:
    // 0x8041EAE4: b           L_8041EB90
    // 0x8041EAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041EB90;
    // 0x8041EAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EAEC:
    // 0x8041EAEC: lh          $v0, 0x2E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X2E);
    // 0x8041EAF0: beq         $v0, $zero, L_8041EB00
    if (ctx->r2 == 0) {
        // 0x8041EAF4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8041EB00;
    }
    // 0x8041EAF4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8041EAF8: b           L_8041EB8C
    // 0x8041EAFC: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
        goto L_8041EB8C;
    // 0x8041EAFC: sh          $t6, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r14;
L_8041EB00:
    // 0x8041EB00: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8041EB04: addiu       $at, $zero, 0x40AF
    ctx->r1 = ADD32(0, 0X40AF);
    // 0x8041EB08: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8041EB0C: beq         $v0, $at, L_8041EB50
    if (ctx->r2 == ctx->r1) {
        // 0x8041EB10: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_8041EB50;
    }
    // 0x8041EB10: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8041EB14: addiu       $at, $zero, 0x40B0
    ctx->r1 = ADD32(0, 0X40B0);
    // 0x8041EB18: beq         $v0, $at, L_8041EB78
    if (ctx->r2 == ctx->r1) {
        // 0x8041EB1C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8041EB78;
    }
    // 0x8041EB1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EB20: addiu       $at, $zero, 0x45A0
    ctx->r1 = ADD32(0, 0X45A0);
    // 0x8041EB24: bne         $v0, $at, L_8041EB8C
    if (ctx->r2 != ctx->r1) {
        // 0x8041EB28: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_8041EB8C;
    }
    // 0x8041EB28: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8041EB2C: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
    // 0x8041EB30: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8041EB34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EB38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EB3C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8041EB40: jal         0x8041FE10
    // 0x8041EB44: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_12;
    // 0x8041EB44: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_12:
    // 0x8041EB48: b           L_8041EB90
    // 0x8041EB4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041EB90;
    // 0x8041EB4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EB50:
    // 0x8041EB50: sh          $t8, 0x2E($s1)
    MEM_H(0X2E, ctx->r17) = ctx->r24;
    // 0x8041EB54: sh          $t9, 0x30($s1)
    MEM_H(0X30, ctx->r17) = ctx->r25;
    // 0x8041EB58: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8041EB5C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8041EB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041EB64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EB68: jal         0x8041FE10
    // 0x8041EB6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8041FE10(rdram, ctx);
        goto after_13;
    // 0x8041EB6C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_13:
    // 0x8041EB70: b           L_8041EB90
    // 0x8041EB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8041EB90;
    // 0x8041EB74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EB78:
    // 0x8041EB78: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8041EB7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041EB80: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8041EB84: jal         0x8041FE10
    // 0x8041EB88: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_14;
    // 0x8041EB88: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_14:
L_8041EB8C:
    // 0x8041EB8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8041EB90:
    // 0x8041EB90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041EB94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041EB98: jr          $ra
    // 0x8041EB9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8041EB9C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80051C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80051C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051C2C: addiu       $a1, $zero, 0x29C
    ctx->r5 = ADD32(0, 0X29C);
    // 0x80051C30: jal         0x80065728
    // 0x80051C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80051C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80051C38: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80051C3C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80051C40: lw          $t6, 0x3EC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3EC);
    // 0x80051C44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051C48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80051C4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80051C50: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80051C54: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80051C58: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80051C5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80051C60: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80051C64: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80051C68: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80051C6C: addiu       $t9, $t8, 0x638
    ctx->r25 = ADD32(ctx->r24, 0X638);
    // 0x80051C70: jr          $ra
    // 0x80051C74: sw          $t9, 0x634($v0)
    MEM_W(0X634, ctx->r2) = ctx->r25;
    return;
    // 0x80051C74: sw          $t9, 0x634($v0)
    MEM_W(0X634, ctx->r2) = ctx->r25;
    // 0x80051C78: nop

    // 0x80051C7C: nop

;}
RECOMP_FUNC void ViMode_Save(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007EA24: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007EA28: jr          $ra
    // 0x8007EA2C: nop

    return;
    // 0x8007EA2C: nop

;}
RECOMP_FUNC void func_80465058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80465058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8046505C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80465060: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80465064: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80465068: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8046506C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80465070: addiu       $t7, $v0, 0x928
    ctx->r15 = ADD32(ctx->r2, 0X928);
    // 0x80465074: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80465078: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8046507C: jal         0x80465038
    // 0x80465080: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80465038(rdram, ctx);
        goto after_0;
    // 0x80465080: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80465084: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80465088: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8046508C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(125, 0XA10) << 16);
    // 0x80465090: sw          $t8, 0x1250($v0)
    MEM_W(0X1250, ctx->r2) = ctx->r24;
    // 0x80465094: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80465098: addiu       $t9, $t9, 0x4FE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(125, 0XA10));
    // 0x8046509C: lw          $t1, 0x16C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X16C);
    // 0x804650A0: sw          $t9, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r25;
    // 0x804650A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804650A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804650AC: jr          $ra
    // 0x804650B0: nop

    return;
    // 0x804650B0: nop

;}
RECOMP_FUNC void func_8006EF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EF38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EF3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006EF40: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8006EF44: jal         0x80048F84
    // 0x8006EF48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8006EF48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8006EF4C: jal         0x8006E7F0
    // 0x8006EF50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006E7F0(rdram, ctx);
        goto after_1;
    // 0x8006EF50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006EF54: jal         0x8006E84C
    // 0x8006EF58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006E84C(rdram, ctx);
        goto after_2;
    // 0x8006EF58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8006EF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EF64: jr          $ra
    // 0x8006EF68: nop

    return;
    // 0x8006EF68: nop

;}
RECOMP_FUNC void func_80433410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433410: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433414: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433418: jal         0x80432E28
    // 0x8043341C: nop

    func_80432E28(rdram, ctx);
        goto after_0;
    // 0x8043341C: nop

    after_0:
    // 0x80433420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80433424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80433428: jr          $ra
    // 0x8043342C: nop

    return;
    // 0x8043342C: nop

;}
RECOMP_FUNC void func_80471E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471E20: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80471E24: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80471E28: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80471E2C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80471E30: addiu       $t5, $zero, 0x1000
    ctx->r13 = ADD32(0, 0X1000);
    // 0x80471E34: addiu       $t8, $zero, -0x40
    ctx->r24 = ADD32(0, -0X40);
    // 0x80471E38: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80471E3C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80471E40: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80471E44: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x80471E48: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80471E4C: addiu       $v1, $v0, -0x40
    ctx->r3 = ADD32(ctx->r2, -0X40);
    // 0x80471E50: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    // 0x80471E54: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80471E58: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80471E5C: addiu       $a2, $v0, -0x40
    ctx->r6 = ADD32(ctx->r2, -0X40);
    // 0x80471E60: addiu       $t0, $v0, 0x40
    ctx->r8 = ADD32(ctx->r2, 0X40);
    // 0x80471E64: addiu       $t6, $zero, 0x800
    ctx->r14 = ADD32(0, 0X800);
    // 0x80471E68: addiu       $t7, $zero, 0x800
    ctx->r15 = ADD32(0, 0X800);
    // 0x80471E6C: sb          $t4, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r12;
    // 0x80471E70: sb          $t4, 0xD($a1)
    MEM_B(0XD, ctx->r5) = ctx->r12;
    // 0x80471E74: sb          $t4, 0xE($a1)
    MEM_B(0XE, ctx->r5) = ctx->r12;
    // 0x80471E78: sb          $t4, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r12;
    // 0x80471E7C: sh          $zero, 0xA($a1)
    MEM_H(0XA, ctx->r5) = 0;
    // 0x80471E80: sh          $zero, 0x8($a1)
    MEM_H(0X8, ctx->r5) = 0;
    // 0x80471E84: sh          $zero, 0x6($a1)
    MEM_H(0X6, ctx->r5) = 0;
    // 0x80471E88: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x80471E8C: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80471E90: sh          $t9, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r25;
    // 0x80471E94: sh          $t5, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r13;
    // 0x80471E98: sb          $t4, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r12;
    // 0x80471E9C: sb          $t4, 0x1D($a1)
    MEM_B(0X1D, ctx->r5) = ctx->r12;
    // 0x80471EA0: sb          $t4, 0x1E($a1)
    MEM_B(0X1E, ctx->r5) = ctx->r12;
    // 0x80471EA4: sb          $t4, 0x1F($a1)
    MEM_B(0X1F, ctx->r5) = ctx->r12;
    // 0x80471EA8: sh          $zero, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = 0;
    // 0x80471EAC: sh          $zero, 0x16($a1)
    MEM_H(0X16, ctx->r5) = 0;
    // 0x80471EB0: sh          $zero, 0x14($a1)
    MEM_H(0X14, ctx->r5) = 0;
    // 0x80471EB4: sh          $zero, 0x12($a1)
    MEM_H(0X12, ctx->r5) = 0;
    // 0x80471EB8: sh          $t6, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = ctx->r14;
    // 0x80471EBC: sh          $a2, 0x20($a1)
    MEM_H(0X20, ctx->r5) = ctx->r6;
    // 0x80471EC0: sh          $t3, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r11;
    // 0x80471EC4: sb          $t4, 0x2C($a1)
    MEM_B(0X2C, ctx->r5) = ctx->r12;
    // 0x80471EC8: sb          $t4, 0x2D($a1)
    MEM_B(0X2D, ctx->r5) = ctx->r12;
    // 0x80471ECC: sb          $t4, 0x2E($a1)
    MEM_B(0X2E, ctx->r5) = ctx->r12;
    // 0x80471ED0: sb          $t4, 0x2F($a1)
    MEM_B(0X2F, ctx->r5) = ctx->r12;
    // 0x80471ED4: sh          $zero, 0x28($a1)
    MEM_H(0X28, ctx->r5) = 0;
    // 0x80471ED8: sh          $zero, 0x26($a1)
    MEM_H(0X26, ctx->r5) = 0;
    // 0x80471EDC: sh          $zero, 0x24($a1)
    MEM_H(0X24, ctx->r5) = 0;
    // 0x80471EE0: sh          $t7, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = ctx->r15;
    // 0x80471EE4: sh          $t0, 0x30($a1)
    MEM_H(0X30, ctx->r5) = ctx->r8;
    // 0x80471EE8: sh          $t3, 0x32($a1)
    MEM_H(0X32, ctx->r5) = ctx->r11;
    // 0x80471EEC: sh          $t5, 0x38($a1)
    MEM_H(0X38, ctx->r5) = ctx->r13;
    // 0x80471EF0: sb          $t4, 0x3C($a1)
    MEM_B(0X3C, ctx->r5) = ctx->r12;
    // 0x80471EF4: sb          $t4, 0x3D($a1)
    MEM_B(0X3D, ctx->r5) = ctx->r12;
    // 0x80471EF8: sb          $t4, 0x3E($a1)
    MEM_B(0X3E, ctx->r5) = ctx->r12;
    // 0x80471EFC: sb          $t4, 0x3F($a1)
    MEM_B(0X3F, ctx->r5) = ctx->r12;
    // 0x80471F00: sh          $zero, 0x36($a1)
    MEM_H(0X36, ctx->r5) = 0;
    // 0x80471F04: sh          $zero, 0x34($a1)
    MEM_H(0X34, ctx->r5) = 0;
    // 0x80471F08: sh          $a2, 0x40($a1)
    MEM_H(0X40, ctx->r5) = ctx->r6;
    // 0x80471F0C: sh          $t3, 0x42($a1)
    MEM_H(0X42, ctx->r5) = ctx->r11;
    // 0x80471F10: sb          $t4, 0x4C($a1)
    MEM_B(0X4C, ctx->r5) = ctx->r12;
    // 0x80471F14: sb          $t4, 0x4D($a1)
    MEM_B(0X4D, ctx->r5) = ctx->r12;
    // 0x80471F18: sb          $t4, 0x4E($a1)
    MEM_B(0X4E, ctx->r5) = ctx->r12;
    // 0x80471F1C: sb          $t4, 0x4F($a1)
    MEM_B(0X4F, ctx->r5) = ctx->r12;
    // 0x80471F20: sh          $zero, 0x4A($a1)
    MEM_H(0X4A, ctx->r5) = 0;
    // 0x80471F24: sh          $zero, 0x48($a1)
    MEM_H(0X48, ctx->r5) = 0;
    // 0x80471F28: sh          $zero, 0x46($a1)
    MEM_H(0X46, ctx->r5) = 0;
    // 0x80471F2C: sh          $zero, 0x44($a1)
    MEM_H(0X44, ctx->r5) = 0;
    // 0x80471F30: sh          $t0, 0x50($a1)
    MEM_H(0X50, ctx->r5) = ctx->r8;
    // 0x80471F34: sh          $t3, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r11;
    // 0x80471F38: sh          $t5, 0x58($a1)
    MEM_H(0X58, ctx->r5) = ctx->r13;
    // 0x80471F3C: sb          $t4, 0x5C($a1)
    MEM_B(0X5C, ctx->r5) = ctx->r12;
    // 0x80471F40: sb          $t4, 0x5D($a1)
    MEM_B(0X5D, ctx->r5) = ctx->r12;
    // 0x80471F44: sb          $t4, 0x5E($a1)
    MEM_B(0X5E, ctx->r5) = ctx->r12;
    // 0x80471F48: sb          $t4, 0x5F($a1)
    MEM_B(0X5F, ctx->r5) = ctx->r12;
    // 0x80471F4C: sh          $zero, 0x5A($a1)
    MEM_H(0X5A, ctx->r5) = 0;
    // 0x80471F50: sh          $zero, 0x56($a1)
    MEM_H(0X56, ctx->r5) = 0;
    // 0x80471F54: sh          $zero, 0x54($a1)
    MEM_H(0X54, ctx->r5) = 0;
    // 0x80471F58: addiu       $v0, $a1, 0x60
    ctx->r2 = ADD32(ctx->r5, 0X60);
    // 0x80471F5C: sh          $v1, 0x60($a1)
    MEM_H(0X60, ctx->r5) = ctx->r3;
    // 0x80471F60: addiu       $t8, $zero, 0x800
    ctx->r24 = ADD32(0, 0X800);
    // 0x80471F64: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x80471F68: sb          $t4, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r12;
    // 0x80471F6C: sb          $t4, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r12;
    // 0x80471F70: sb          $t4, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r12;
    // 0x80471F74: sb          $t4, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r12;
    // 0x80471F78: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80471F7C: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80471F80: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80471F84: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80471F88: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80471F8C: sh          $t9, 0x7A($a1)
    MEM_H(0X7A, ctx->r5) = ctx->r25;
    // 0x80471F90: sb          $t4, 0x7F($a1)
    MEM_B(0X7F, ctx->r5) = ctx->r12;
    // 0x80471F94: sb          $t4, 0x7E($a1)
    MEM_B(0X7E, ctx->r5) = ctx->r12;
    // 0x80471F98: sb          $t4, 0x7D($a1)
    MEM_B(0X7D, ctx->r5) = ctx->r12;
    // 0x80471F9C: sb          $t4, 0x7C($a1)
    MEM_B(0X7C, ctx->r5) = ctx->r12;
    // 0x80471FA0: sh          $t5, 0x78($a1)
    MEM_H(0X78, ctx->r5) = ctx->r13;
    // 0x80471FA4: sh          $zero, 0x76($a1)
    MEM_H(0X76, ctx->r5) = 0;
    // 0x80471FA8: sh          $zero, 0x74($a1)
    MEM_H(0X74, ctx->r5) = 0;
    // 0x80471FAC: sh          $a3, 0x70($a1)
    MEM_H(0X70, ctx->r5) = ctx->r7;
    // 0x80471FB0: jr          $ra
    // 0x80471FB4: sh          $t2, 0x72($a1)
    MEM_H(0X72, ctx->r5) = ctx->r10;
    return;
    // 0x80471FB4: sh          $t2, 0x72($a1)
    MEM_H(0X72, ctx->r5) = ctx->r10;
;}
RECOMP_FUNC void func_80051CB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051CB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80051CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051CC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80051CC4: jal         0x80050C8C
    // 0x80051CC8: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    func_80050C8C(rdram, ctx);
        goto after_0;
    // 0x80051CC8: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    after_0:
    // 0x80051CCC: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80051CD0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x80051CD4: jal         0x80064DD0
    // 0x80051CD8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80064DD0(rdram, ctx);
        goto after_1;
    // 0x80051CD8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_1:
    // 0x80051CDC: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x80051CE0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80051CE4: addiu       $a3, $a3, 0x758C
    ctx->r7 = ADD32(ctx->r7, 0X758C);
    // 0x80051CE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80051CEC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80051CF0: jal         0x800675D0
    // 0x80051CF4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    func_800675D0(rdram, ctx);
        goto after_2;
    // 0x80051CF4: addiu       $a2, $zero, 0x44
    ctx->r6 = ADD32(0, 0X44);
    after_2:
    // 0x80051CF8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80051CFC: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x80051D00: addiu       $a1, $v0, 0x2C
    ctx->r5 = ADD32(ctx->r2, 0X2C);
    // 0x80051D04: jal         0x80050B38
    // 0x80051D08: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
    func_80050B38(rdram, ctx);
        goto after_3;
    // 0x80051D08: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
    after_3:
    // 0x80051D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051D10: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80051D14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80051D18: jr          $ra
    // 0x80051D1C: nop

    return;
    // 0x80051D1C: nop

;}
RECOMP_FUNC void func_806E72B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E72B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806E72BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806E72C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E72C4: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x806E72C8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806E72CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806E72D0: bnel        $t6, $at, L_806E72FC
    if (ctx->r14 != ctx->r1) {
        // 0x806E72D4: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_806E72FC;
    }
    goto skip_0;
    // 0x806E72D4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x806E72D8: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x806E72DC: jal         0x80067BBC
    // 0x806E72E0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806E72E0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x806E72E4: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E72E8: jal         0x80067F78
    // 0x806E72EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806E72EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806E72F0: b           L_806E7314
    // 0x806E72F4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_806E7314;
    // 0x806E72F4: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x806E72F8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_806E72FC:
    // 0x806E72FC: jal         0x80067BBC
    // 0x806E7300: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806E7300: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x806E7304: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x806E7308: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x806E730C: jal         0x800678F0
    // 0x806E7310: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x806E7310: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_806E7314:
    // 0x806E7314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806E7318: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E731C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806E7320: jr          $ra
    // 0x806E7324: nop

    return;
    // 0x806E7324: nop

;}
RECOMP_FUNC void func_806DF680(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF680: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806DF684: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806DF688: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF68C: lwc1        $f10, 0xC8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806DF690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806DF694: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806DF698: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806DF69C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DF6A0: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    // 0x806DF6A4: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x806DF6A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806DF6AC: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x806DF6B0: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x806DF6B4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806DF6B8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806DF6BC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806DF6C0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x806DF6C4: nop

    // 0x806DF6C8: bc1f        L_806DF6D8
    if (!c1cs) {
        // 0x806DF6CC: nop
    
            goto L_806DF6D8;
    }
    // 0x806DF6CC: nop

    // 0x806DF6D0: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806DF6D4: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
L_806DF6D8:
    // 0x806DF6D8: jr          $ra
    // 0x806DF6DC: nop

    return;
    // 0x806DF6DC: nop

;}
RECOMP_FUNC void func_80526880(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526880: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80526884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80526888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8052688C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526890: jal         0x8052675C
    // 0x80526894: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    func_8052675C(rdram, ctx);
        goto after_0;
    // 0x80526894: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_0:
    // 0x80526898: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x8052689C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x805268A0: jalr        $t9
    // 0x805268A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x805268A4: nop

    after_1:
    // 0x805268A8: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x805268AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805268B0: lw          $t9, 0x1C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1C);
    // 0x805268B4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805268B8: jalr        $t9
    // 0x805268BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805268BC: nop

    after_2:
    // 0x805268C0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x805268C4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x805268C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805268CC: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x805268D0: jalr        $t9
    // 0x805268D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x805268D4: nop

    after_3:
    // 0x805268D8: lw          $t6, 0x88($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X88);
    // 0x805268DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805268E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805268E4: beql        $t6, $zero, L_8052695C
    if (ctx->r14 == 0) {
        // 0x805268E8: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8052695C;
    }
    goto skip_0;
    // 0x805268E8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x805268EC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x805268F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805268F4: beql        $t7, $zero, L_8052690C
    if (ctx->r15 == 0) {
        // 0x805268F8: sw          $v1, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r3;
            goto L_8052690C;
    }
    goto skip_1;
    // 0x805268F8: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    skip_1:
    // 0x805268FC: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x80526900: b           L_8052690C
    // 0x80526904: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8052690C;
    // 0x80526904: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80526908: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
L_8052690C:
    // 0x8052690C: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    // 0x80526910: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(327, 0X6104) << 16);
    // 0x80526914: addiu       $a2, $a2, -0x3FFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(327, 0X6104));
    // 0x80526918: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x8052691C: addu        $t1, $a2, $t0
    ctx->r9 = ADD32(ctx->r6, ctx->r8);
    // 0x80526920: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80526924: sw          $t2, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r10;
    // 0x80526928: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x8052692C: beql        $t3, $zero, L_80526940
    if (ctx->r11 == 0) {
        // 0x80526930: sw          $v1, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r3;
            goto L_80526940;
    }
    goto skip_2;
    // 0x80526930: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    skip_2:
    // 0x80526934: b           L_80526940
    // 0x80526938: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
        goto L_80526940;
    // 0x80526938: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8052693C: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
L_80526940:
    // 0x80526940: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x80526944: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80526948: addu        $t9, $a2, $t5
    ctx->r25 = ADD32(ctx->r6, ctx->r13);
    // 0x8052694C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80526950: b           L_805269E4
    // 0x80526954: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
        goto L_805269E4;
    // 0x80526954: sw          $t6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r14;
    // 0x80526958: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8052695C:
    // 0x8052695C: beql        $t7, $zero, L_805269E8
    if (ctx->r15 == 0) {
        // 0x80526960: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805269E8;
    }
    goto skip_3;
    // 0x80526960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80526964: beql        $v0, $zero, L_805269E8
    if (ctx->r2 == 0) {
        // 0x80526968: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805269E8;
    }
    goto skip_4;
    // 0x80526968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8052696C: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    // 0x80526970: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80526974: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(327, 0X6104) << 16);
    // 0x80526978: bne         $v1, $t8, L_805269C4
    if (ctx->r3 != ctx->r24) {
        // 0x8052697C: addiu       $a2, $a2, -0x3FFC
        ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(327, 0X6104));
            goto L_805269C4;
    }
    // 0x8052697C: addiu       $a2, $a2, -0x3FFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(327, 0X6104));
    // 0x80526980: lw          $t0, 0x18($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X18);
    // 0x80526984: bnel        $v1, $t0, L_805269C8
    if (ctx->r3 != ctx->r8) {
        // 0x80526988: sw          $v1, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r3;
            goto L_805269C8;
    }
    goto skip_5;
    // 0x80526988: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
    skip_5:
    // 0x8052698C: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x80526990: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(327, 0X6104) << 16);
    // 0x80526994: addiu       $a2, $a2, -0x3FFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(327, 0X6104));
    // 0x80526998: bnel        $v0, $zero, L_805269BC
    if (ctx->r2 != 0) {
        // 0x8052699C: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_805269BC;
    }
    goto skip_6;
    // 0x8052699C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    skip_6:
    // 0x805269A0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x805269A4: sw          $zero, 0x18($a1)
    MEM_W(0X18, ctx->r5) = 0;
    // 0x805269A8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805269AC: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x805269B0: b           L_805269E4
    // 0x805269B4: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
        goto L_805269E4;
    // 0x805269B4: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x805269B8: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_805269BC:
    // 0x805269BC: b           L_805269E4
    // 0x805269C0: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
        goto L_805269E4;
    // 0x805269C0: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
L_805269C4:
    // 0x805269C4: sw          $v1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r3;
L_805269C8:
    // 0x805269C8: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x805269CC: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x805269D0: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x805269D4: jal         0x800653D8
    // 0x805269D8: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x805269D8: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    after_4:
    // 0x805269DC: andi        $t2, $v0, 0x7F
    ctx->r10 = ctx->r2 & 0X7F;
    // 0x805269E0: sw          $t2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r10;
L_805269E4:
    // 0x805269E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805269E8:
    // 0x805269E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805269EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805269F0: jr          $ra
    // 0x805269F4: nop

    return;
    // 0x805269F4: nop

;}
RECOMP_FUNC void func_8042FC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FC38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042FC3C: lui         $t6, 0x8043
    ctx->r14 = S32(RELOC_HI16(56, 0X3810) << 16);
    // 0x8042FC40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FC44: addiu       $t6, $t6, 0x18F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(56, 0X3810));
    // 0x8042FC48: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8042FC4C: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x8042FC50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8042FC54: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8042FC58: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8042FC5C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042FC60: lw          $t9, 0x138($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X138);
    // 0x8042FC64: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042FC68: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x8042FC6C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8042FC70: jalr        $t9
    // 0x8042FC74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042FC74: nop

    after_0:
    // 0x8042FC78: jal         0x8042FA9C
    // 0x8042FC7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8042FA9C(rdram, ctx);
        goto after_1;
    // 0x8042FC7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8042FC80: jal         0x8042F6B4
    // 0x8042FC84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8042F6B4(rdram, ctx);
        goto after_2;
    // 0x8042FC84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8042FC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FC8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042FC90: jr          $ra
    // 0x8042FC94: nop

    return;
    // 0x8042FC94: nop

;}
RECOMP_FUNC void func_8044C7FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C7FC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8044C800: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8044C804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044C808: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8044C80C: addiu       $s0, $a1, 0x4
    ctx->r16 = ADD32(ctx->r5, 0X4);
    // 0x8044C810: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8044C814: jal         0x80066E88
    // 0x8044C818: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C818: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8044C81C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8044C820: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C824: jal         0x80066DE4
    // 0x8044C828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    after_1:
    // 0x8044C82C: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C830: jal         0x80066E88
    // 0x8044C834: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x8044C834: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8044C838: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8044C83C: jal         0x80066DE4
    // 0x8044C840: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8044C840: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8044C844: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8044C848: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8044C84C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044C850: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C854: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8044C858: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8044C85C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C860: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8044C864: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C868: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8044C86C: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8044C870: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8044C874: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8044C878: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8044C87C: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8044C880: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x8044C884: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8044C888: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8044C88C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8044C890: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8044C894: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8044C898: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8044C89C: swc1        $f12, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f12.u32l;
    // 0x8044C8A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8044C8A4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8044C8A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8044C8AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8044C8B0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C8B4: jr          $ra
    // 0x8044C8B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8044C8B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800199B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800199B0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800199B4: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800199B8: sw          $zero, -0x20($at)
    MEM_W(-0X20, ctx->r1) = 0;
    // 0x800199BC: addiu       $v1, $v1, -0x4820
    ctx->r3 = ADD32(ctx->r3, -0X4820);
    // 0x800199C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800199C4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
L_800199C8:
    // 0x800199C8: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800199CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800199D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800199D4: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x800199D8: mflo        $t6
    ctx->r14 = lo;
    // 0x800199DC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800199E0: bne         $at, $zero, L_800199C8
    if (ctx->r1 != 0) {
        // 0x800199E4: sw          $zero, 0x3C($t7)
        MEM_W(0X3C, ctx->r15) = 0;
            goto L_800199C8;
    }
    // 0x800199E4: sw          $zero, 0x3C($t7)
    MEM_W(0X3C, ctx->r15) = 0;
    // 0x800199E8: jr          $ra
    // 0x800199EC: nop

    return;
    // 0x800199EC: nop

;}
RECOMP_FUNC void func_806FCF44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FCF44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FCF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FCF4C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FCF50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806FCF54: jal         0x806FCFE0
    // 0x806FCF58: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_806FCFE0(rdram, ctx);
        goto after_0;
    // 0x806FCF58: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_0:
    // 0x806FCF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FCF60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FCF64: jr          $ra
    // 0x806FCF68: nop

    return;
    // 0x806FCF68: nop

;}
RECOMP_FUNC void gfxprint_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F920: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F924: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007F928: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007F92C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007F930: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007F934: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007F938: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007F93C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007F940: mflo        $s1
    ctx->r17 = lo;
    // 0x8007F944: beq         $s1, $zero, L_8007F964
    if (ctx->r17 == 0) {
        // 0x8007F948: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007F964;
    }
    // 0x8007F948: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8007F94C:
    // 0x8007F94C: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007F950: jal         0x8007F79C
    // 0x8007F954: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    gfxprint_putc(rdram, ctx);
        goto after_0;
    // 0x8007F954: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_0:
    // 0x8007F958: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8007F95C: bnel        $s1, $zero, L_8007F94C
    if (ctx->r17 != 0) {
        // 0x8007F960: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8007F94C;
    }
    goto skip_0;
    // 0x8007F960: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_8007F964:
    // 0x8007F964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007F968: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007F96C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F970: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007F974: jr          $ra
    // 0x8007F978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007F978: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8042E8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E8D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042E8DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042E8E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042E8E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8042E8E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8042E8EC: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8042E8F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8042E8F4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8042E8F8: beq         $v0, $at, L_8042E914
    if (ctx->r2 == ctx->r1) {
        // 0x8042E8FC: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8042E914;
    }
    // 0x8042E8FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042E900: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8042E904: beq         $v0, $at, L_8042E970
    if (ctx->r2 == ctx->r1) {
        // 0x8042E908: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_8042E970;
    }
    // 0x8042E908: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8042E90C: b           L_8042E9A0
    // 0x8042E910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042E9A0;
    // 0x8042E910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042E914:
    // 0x8042E914: jal         0x80062AEC
    // 0x8042E918: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80062AEC(rdram, ctx);
        goto after_0;
    // 0x8042E918: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x8042E91C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8042E920: beq         $v0, $at, L_8042E940
    if (ctx->r2 == ctx->r1) {
        // 0x8042E924: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8042E940;
    }
    // 0x8042E924: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8042E928: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8042E92C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8042E930: jal         0x8002F6E4
    // 0x8042E934: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_1;
    // 0x8042E934: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8042E938: b           L_8042E9A0
    // 0x8042E93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042E9A0;
    // 0x8042E93C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042E940:
    // 0x8042E940: jal         0x8002FABC
    // 0x8042E944: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    func_8002FABC(rdram, ctx);
        goto after_2;
    // 0x8042E944: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    after_2:
    // 0x8042E948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042E94C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042E950: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042E954: jal         0x8042EB3C
    // 0x8042E958: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042EB3C(rdram, ctx);
        goto after_3;
    // 0x8042E958: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_3:
    // 0x8042E95C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042E960: jal         0x8042E220
    // 0x8042E964: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_4;
    // 0x8042E964: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8042E968: b           L_8042E9A0
    // 0x8042E96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8042E9A0;
    // 0x8042E96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042E970:
    // 0x8042E970: lbu         $t8, 0x18($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X18);
    // 0x8042E974: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8042E978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042E97C: bne         $t8, $at, L_8042E99C
    if (ctx->r24 != ctx->r1) {
        // 0x8042E980: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8042E99C;
    }
    // 0x8042E980: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042E984: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042E988: jal         0x8042EB3C
    // 0x8042E98C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8042EB3C(rdram, ctx);
        goto after_5;
    // 0x8042E98C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x8042E990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042E994: jal         0x8042E220
    // 0x8042E998: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    func_8042E220(rdram, ctx);
        goto after_6;
    // 0x8042E998: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_6:
L_8042E99C:
    // 0x8042E99C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042E9A0:
    // 0x8042E9A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042E9A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042E9A8: jr          $ra
    // 0x8042E9AC: nop

    return;
    // 0x8042E9AC: nop

;}
RECOMP_FUNC void func_807BA2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA2F0: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(889, 0X18) << 16);
    // 0x807BA2F4: addiu       $v0, $v0, -0x5CF8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(889, 0X18));
    // 0x807BA2F8: jr          $ra
    // 0x807BA2FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807BA2FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8078F190(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078F190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078F194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078F198: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078F19C: lui         $a0, 0x8079
    ctx->r4 = S32(RELOC_HI16(814, 0XF30) << 16);
    // 0x8078F1A0: lui         $a1, 0x8079
    ctx->r5 = S32(RELOC_HI16(814, 0XF40) << 16);
    // 0x8078F1A4: addiu       $a1, $a1, 0xD0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(814, 0XF40));
    // 0x8078F1A8: addiu       $a0, $a0, 0xC0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(814, 0XF30));
    // 0x8078F1AC: jal         0x8004667C
    // 0x8078F1B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8078F1B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8078F1B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078F1B8: lui         $t6, 0x8079
    ctx->r14 = S32(RELOC_HI16(814, 0XCBC) << 16);
    // 0x8078F1BC: addiu       $t6, $t6, -0x1B4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(814, 0XCBC));
    // 0x8078F1C0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8078F1C4: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(814, 0XA9C) << 16);
    // 0x8078F1C8: sw          $t6, -0x72BC($at)
    MEM_W(-0X72BC, ctx->r1) = ctx->r14;
    // 0x8078F1CC: addiu       $v0, $v0, -0x3D4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(814, 0XA9C));
    // 0x8078F1D0: jr          $ra
    // 0x8078F1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8078F1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80741D0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80741D0C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80741D10: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80741D14: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80741D18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80741D1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80741D20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80741D24: lhu         $v1, 0xC($t8)
    ctx->r3 = MEM_HU(ctx->r24, 0XC);
    // 0x80741D28: lw          $t7, 0x180($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X180);
    // 0x80741D2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80741D30: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x80741D34: beq         $t9, $at, L_80741D58
    if (ctx->r25 == ctx->r1) {
        // 0x80741D38: lw          $a1, 0x1F4($t7)
        ctx->r5 = MEM_W(ctx->r15, 0X1F4);
            goto L_80741D58;
    }
    // 0x80741D38: lw          $a1, 0x1F4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X1F4);
    // 0x80741D3C: andi        $t0, $v1, 0x4000
    ctx->r8 = ctx->r3 & 0X4000;
    // 0x80741D40: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x80741D44: beq         $t0, $at, L_80741D58
    if (ctx->r8 == ctx->r1) {
        // 0x80741D48: andi        $t1, $v1, 0x1000
        ctx->r9 = ctx->r3 & 0X1000;
            goto L_80741D58;
    }
    // 0x80741D48: andi        $t1, $v1, 0x1000
    ctx->r9 = ctx->r3 & 0X1000;
    // 0x80741D4C: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x80741D50: bnel        $t1, $at, L_80741E30
    if (ctx->r9 != ctx->r1) {
        // 0x80741D54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80741E30;
    }
    goto skip_0;
    // 0x80741D54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80741D58:
    // 0x80741D58: sw          $zero, 0x48($a1)
    MEM_W(0X48, ctx->r5) = 0;
    // 0x80741D5C: lw          $t2, 0xCE8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XCE8);
    // 0x80741D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741D64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80741D68: beq         $t2, $zero, L_80741DB4
    if (ctx->r10 == 0) {
        // 0x80741D6C: nop
    
            goto L_80741DB4;
    }
    // 0x80741D6C: nop

    // 0x80741D70: lw          $t3, 0xFB8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XFB8);
    // 0x80741D74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80741D78: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80741D7C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80741D80: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x80741D84: bne         $t5, $at, L_80741DA4
    if (ctx->r13 != ctx->r1) {
        // 0x80741D88: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80741DA4;
    }
    // 0x80741D88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741D8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80741D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80741D94: jal         0x8006E0FC
    // 0x80741D98: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_8006E0FC(rdram, ctx);
        goto after_0;
    // 0x80741D98: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_0:
    // 0x80741D9C: b           L_80741E20
    // 0x80741DA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80741E20;
    // 0x80741DA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80741DA4:
    // 0x80741DA4: jal         0x8006E0FC
    // 0x80741DA8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    func_8006E0FC(rdram, ctx);
        goto after_1;
    // 0x80741DA8: addiu       $a2, $zero, 0x29
    ctx->r6 = ADD32(0, 0X29);
    after_1:
    // 0x80741DAC: b           L_80741E20
    // 0x80741DB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_80741E20;
    // 0x80741DB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80741DB4:
    // 0x80741DB4: jal         0x8006E0FC
    // 0x80741DB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x80741DB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80741DBC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80741DC0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80741DC4: lw          $t7, 0xF54($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF54);
    // 0x80741DC8: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80741DCC: lbu         $t3, 0xFB8($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0XFB8);
    // 0x80741DD0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80741DD4: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80741DD8: and         $t0, $t8, $at
    ctx->r8 = ctx->r24 & ctx->r1;
    // 0x80741DDC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80741DE0: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80741DE4: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80741DE8: sw          $t6, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r14;
    // 0x80741DEC: sw          $t8, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r24;
    // 0x80741DF0: ori         $at, $at, 0x3FFF
    ctx->r1 = ctx->r1 | 0X3FFF;
    // 0x80741DF4: sw          $t0, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r8;
    // 0x80741DF8: and         $t2, $t0, $at
    ctx->r10 = ctx->r8 & ctx->r1;
    // 0x80741DFC: sb          $t5, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r13;
    // 0x80741E00: andi        $t6, $t5, 0xEF
    ctx->r14 = ctx->r13 & 0XEF;
    // 0x80741E04: sw          $t2, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r10;
    // 0x80741E08: jal         0x80741C34
    // 0x80741E0C: sb          $t6, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r14;
    func_80741C34(rdram, ctx);
        goto after_3;
    // 0x80741E0C: sb          $t6, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r14;
    after_3:
    // 0x80741E10: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80741E14: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80741E18: sw          $zero, 0xFB4($v0)
    MEM_W(0XFB4, ctx->r2) = 0;
    // 0x80741E1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80741E20:
    // 0x80741E20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80741E24: jal         0x80741E44
    // 0x80741E28: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_80741E44(rdram, ctx);
        goto after_4;
    // 0x80741E28: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x80741E2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80741E30:
    // 0x80741E30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80741E34: jr          $ra
    // 0x80741E38: nop

    return;
    // 0x80741E38: nop

;}
RECOMP_FUNC void func_8064E07C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E07C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x8064E080: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8064E084: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064E088: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E08C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8064E090: sw          $t7, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r15;
    // 0x8064E094: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8064E098: jr          $ra
    // 0x8064E09C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x8064E09C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_807074AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807074AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807074B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807074B4: jal         0x8004700C
    // 0x807074B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807074B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807074BC: beq         $v0, $zero, L_80707614
    if (ctx->r2 == 0) {
        // 0x807074C0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80707614;
    }
    // 0x807074C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807074C4: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x807074C8: addiu       $at, $zero, 0x4608
    ctx->r1 = ADD32(0, 0X4608);
    // 0x807074CC: beq         $v1, $at, L_807074F4
    if (ctx->r3 == ctx->r1) {
        // 0x807074D0: addiu       $at, $zero, 0x4609
        ctx->r1 = ADD32(0, 0X4609);
            goto L_807074F4;
    }
    // 0x807074D0: addiu       $at, $zero, 0x4609
    ctx->r1 = ADD32(0, 0X4609);
    // 0x807074D4: beq         $v1, $at, L_8070753C
    if (ctx->r3 == ctx->r1) {
        // 0x807074D8: addiu       $at, $zero, 0x460A
        ctx->r1 = ADD32(0, 0X460A);
            goto L_8070753C;
    }
    // 0x807074D8: addiu       $at, $zero, 0x460A
    ctx->r1 = ADD32(0, 0X460A);
    // 0x807074DC: beq         $v1, $at, L_80707584
    if (ctx->r3 == ctx->r1) {
        // 0x807074E0: addiu       $at, $zero, 0x460B
        ctx->r1 = ADD32(0, 0X460B);
            goto L_80707584;
    }
    // 0x807074E0: addiu       $at, $zero, 0x460B
    ctx->r1 = ADD32(0, 0X460B);
    // 0x807074E4: beql        $v1, $at, L_807075D4
    if (ctx->r3 == ctx->r1) {
        // 0x807074E8: lwc1        $f4, 0x84($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
            goto L_807075D4;
    }
    goto skip_0;
    // 0x807074E8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    skip_0:
    // 0x807074EC: b           L_80707618
    // 0x807074F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80707618;
    // 0x807074F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807074F4:
    // 0x807074F4: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x807074F8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807074FC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80707500: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x80707504: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80707508: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8070750C: addiu       $t6, $t6, 0x78F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(712, 0X750));
    // 0x80707510: bc1fl       L_80707618
    if (!c1cs) {
        // 0x80707514: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_1;
    // 0x80707514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80707518: sw          $t6, 0xE90($v1)
    MEM_W(0XE90, ctx->r3) = ctx->r14;
    // 0x8070751C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80707520: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80707524: bnel        $t8, $zero, L_80707618
    if (ctx->r24 != 0) {
        // 0x80707528: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_2;
    // 0x80707528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8070752C: jal         0x80707788
    // 0x80707530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80707788(rdram, ctx);
        goto after_1;
    // 0x80707530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80707534: b           L_80707618
    // 0x80707538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80707618;
    // 0x80707538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8070753C:
    // 0x8070753C: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80707540: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80707544: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80707548: lui         $t9, 0x8070
    ctx->r25 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x8070754C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80707550: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80707554: addiu       $t9, $t9, 0x78F0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(712, 0X750));
    // 0x80707558: bc1fl       L_80707618
    if (!c1cs) {
        // 0x8070755C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_3;
    // 0x8070755C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80707560: sw          $t9, 0xE90($v1)
    MEM_W(0XE90, ctx->r3) = ctx->r25;
    // 0x80707564: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x80707568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8070756C: bnel        $t1, $zero, L_80707618
    if (ctx->r9 != 0) {
        // 0x80707570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_4;
    // 0x80707570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80707574: jal         0x80707788
    // 0x80707578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80707788(rdram, ctx);
        goto after_2;
    // 0x80707578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8070757C: b           L_80707618
    // 0x80707580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80707618;
    // 0x80707580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80707584:
    // 0x80707584: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80707588: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8070758C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80707590: lui         $t2, 0x8070
    ctx->r10 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x80707594: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80707598: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8070759C: addiu       $t2, $t2, 0x78F0
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(712, 0X750));
    // 0x807075A0: bc1fl       L_80707618
    if (!c1cs) {
        // 0x807075A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_5;
    // 0x807075A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x807075A8: sw          $t2, 0xE90($v1)
    MEM_W(0XE90, ctx->r3) = ctx->r10;
    // 0x807075AC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x807075B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x807075B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807075B8: bne         $t3, $zero, L_80707614
    if (ctx->r11 != 0) {
        // 0x807075BC: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80707614;
    }
    // 0x807075BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807075C0: jal         0x80707788
    // 0x807075C4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    func_80707788(rdram, ctx);
        goto after_3;
    // 0x807075C4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    after_3:
    // 0x807075C8: b           L_80707618
    // 0x807075CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80707618;
    // 0x807075CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807075D0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
L_807075D4:
    // 0x807075D4: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x807075D8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807075DC: lui         $t5, 0x8070
    ctx->r13 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x807075E0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x807075E4: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807075E8: addiu       $t5, $t5, 0x78F0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(712, 0X750));
    // 0x807075EC: bc1fl       L_80707618
    if (!c1cs) {
        // 0x807075F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80707618;
    }
    goto skip_6;
    // 0x807075F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x807075F4: sw          $t5, 0xE90($v1)
    MEM_W(0XE90, ctx->r3) = ctx->r13;
    // 0x807075F8: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x807075FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80707600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80707604: bne         $t6, $zero, L_80707614
    if (ctx->r14 != 0) {
        // 0x80707608: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80707614;
    }
    // 0x80707608: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8070760C: jal         0x80707788
    // 0x80707610: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    func_80707788(rdram, ctx);
        goto after_4;
    // 0x80707610: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    after_4:
L_80707614:
    // 0x80707614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80707618:
    // 0x80707618: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070761C: jr          $ra
    // 0x80707620: nop

    return;
    // 0x80707620: nop

;}
RECOMP_FUNC void func_80581F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581F9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581FA0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80581FA4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80581FA8: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(399, 0X46DC) << 16);
    // 0x80581FAC: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x80581FB0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80581FB4: addiu       $t7, $t7, 0x34EC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(399, 0X46DC));
    // 0x80581FB8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80581FBC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80581FC0: jal         0x80581EFC
    // 0x80581FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80581EFC(rdram, ctx);
        goto after_0;
    // 0x80581FC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581FC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581FCC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581FD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80581FD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80581FD8: jal         0x80581F38
    // 0x80581FDC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    func_80581F38(rdram, ctx);
        goto after_1;
    // 0x80581FDC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    after_1:
    // 0x80581FE0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4808) << 16);
    // 0x80581FE4: lwc1        $f0, 0x3618($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X4808));
    // 0x80581FE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80581FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80581FF4: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x80581FF8: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80581FFC: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80582000: lui         $at, 0xC31F
    ctx->r1 = S32(0XC31F << 16);
    // 0x80582004: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80582008: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8058200C: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x80582010: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80582014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80582018: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x8058201C: sb          $v0, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r2;
    // 0x80582020: swc1        $f10, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f10.u32l;
    // 0x80582024: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80582028: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x8058202C: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x80582030: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80582034: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80582038: jr          $ra
    // 0x8058203C: nop

    return;
    // 0x8058203C: nop

;}
RECOMP_FUNC void func_8003C0DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C0DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C0E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C0E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003C0E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003C0EC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003C0F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C0F4: jal         0x80042148
    // 0x8003C0F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042148(rdram, ctx);
        goto after_0;
    // 0x8003C0F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8003C0FC: beq         $v0, $zero, L_8003C17C
    if (ctx->r2 == 0) {
        // 0x8003C100: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003C17C;
    }
    // 0x8003C100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C104: jal         0x80042880
    // 0x8003C108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042880(rdram, ctx);
        goto after_1;
    // 0x8003C108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8003C10C: jal         0x80032D78
    // 0x8003C110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80032D78(rdram, ctx);
        goto after_2;
    // 0x8003C110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003C114: jal         0x8003C094
    // 0x8003C118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003C094(rdram, ctx);
        goto after_3;
    // 0x8003C118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003C11C: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    // 0x8003C120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C124: jalr        $t9
    // 0x8003C128: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8003C128: nop

    after_4:
    // 0x8003C12C: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
    // 0x8003C130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C134: jalr        $t9
    // 0x8003C138: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8003C138: nop

    after_5:
    // 0x8003C13C: beq         $v0, $zero, L_8003C174
    if (ctx->r2 == 0) {
        // 0x8003C140: nop
    
            goto L_8003C174;
    }
    // 0x8003C140: nop

    // 0x8003C144: lw          $t9, 0xB4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB4);
    // 0x8003C148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C14C: jalr        $t9
    // 0x8003C150: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8003C150: nop

    after_6:
    // 0x8003C154: lw          $t9, 0xB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB8);
    // 0x8003C158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C15C: jalr        $t9
    // 0x8003C160: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8003C160: nop

    after_7:
    // 0x8003C164: lw          $t9, 0xBC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XBC);
    // 0x8003C168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C16C: jalr        $t9
    // 0x8003C170: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8003C170: nop

    after_8:
L_8003C174:
    // 0x8003C174: jal         0x8003C064
    // 0x8003C178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003C064(rdram, ctx);
        goto after_9;
    // 0x8003C178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_8003C17C:
    // 0x8003C17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C180: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003C184: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003C188: jr          $ra
    // 0x8003C18C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003C18C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80666E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80666E34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80666E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80666E3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80666E40: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80666E44: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80666E48: lwc1        $f2, 0x4C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x80666E4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80666E50: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80666E54: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D8C) << 16);
    // 0x80666E58: swc1        $f6, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f6.u32l;
    // 0x80666E5C: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80666E60: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80666E64: nop

    // 0x80666E68: bc1f        L_80666E7C
    if (!c1cs) {
        // 0x80666E6C: nop
    
            goto L_80666E7C;
    }
    // 0x80666E6C: nop

    // 0x80666E70: swc1        $f2, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f2.u32l;
    // 0x80666E74: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80666E78: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
L_80666E7C:
    // 0x80666E7C: lwc1        $f16, 0x7A5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D8C));
    // 0x80666E80: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80666E84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80666E88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80666E8C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80666E90: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D90) << 16);
    // 0x80666E94: mul.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80666E98: sub.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80666E9C: bc1f        L_80666EC8
    if (!c1cs) {
        // 0x80666EA0: swc1        $f18, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
            goto L_80666EC8;
    }
    // 0x80666EA0: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x80666EA4: lwc1        $f4, 0x7A60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D90));
    // 0x80666EA8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80666EAC: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x80666EB0: lwc1        $f8, 0x50($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80666EB4: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80666EB8: nop

    // 0x80666EBC: bc1fl       L_80666ECC
    if (!c1cs) {
        // 0x80666EC0: lui         $at, 0x4280
        ctx->r1 = S32(0X4280 << 16);
            goto L_80666ECC;
    }
    goto skip_0;
    // 0x80666EC0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    skip_0:
    // 0x80666EC4: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
L_80666EC8:
    // 0x80666EC8: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
L_80666ECC:
    // 0x80666ECC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80666ED0: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80666ED4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80666ED8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80666EDC: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80666EE0: sub.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80666EE4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80666EE8: nop

    // 0x80666EEC: bc1fl       L_80666EFC
    if (!c1cs) {
        // 0x80666EF0: lw          $t6, 0x138($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X138);
            goto L_80666EFC;
    }
    goto skip_1;
    // 0x80666EF0: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
    skip_1:
    // 0x80666EF4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80666EF8: lw          $t6, 0x138($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X138);
L_80666EFC:
    // 0x80666EFC: beql        $t6, $zero, L_80666F40
    if (ctx->r14 == 0) {
        // 0x80666F00: lwc1        $f12, 0x40($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
            goto L_80666F40;
    }
    goto skip_2;
    // 0x80666F00: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    skip_2:
    // 0x80666F04: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80666F08: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80666F0C: jal         0x80066E88
    // 0x80666F10: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80666F10: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80666F14: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80666F18: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80666F1C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80666F20: jal         0x80066DE4
    // 0x80666F24: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80666F24: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    after_1:
    // 0x80666F28: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80666F2C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80666F30: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80666F34: b           L_80666F7C
    // 0x80666F38: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
        goto L_80666F7C;
    // 0x80666F38: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80666F3C: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
L_80666F40:
    // 0x80666F40: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80666F44: jal         0x80066E88
    // 0x80666F48: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80666F48: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_2:
    // 0x80666F4C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80666F50: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x80666F54: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80666F58: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80666F5C: lwc1        $f12, 0x40($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80666F60: jal         0x80066DE4
    // 0x80666F64: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x80666F64: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80666F68: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80666F6C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80666F70: mul.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80666F74: nop

    // 0x80666F78: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
L_80666F7C:
    // 0x80666F7C: swc1        $f12, 0x58($a1)
    MEM_W(0X58, ctx->r5) = ctx->f12.u32l;
    // 0x80666F80: lwc1        $f0, 0x6C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80666F84: swc1        $f8, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f8.u32l;
    // 0x80666F88: lwc1        $f2, 0x90($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80666F8C: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D94) << 16);
    // 0x80666F90: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80666F94: nop

    // 0x80666F98: bc1fl       L_80666FC4
    if (!c1cs) {
        // 0x80666F9C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80666FC4;
    }
    goto skip_3;
    // 0x80666F9C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x80666FA0: lwc1        $f10, 0x7A64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D94));
    // 0x80666FA4: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80666FA8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80666FAC: nop

    // 0x80666FB0: bc1fl       L_80666FF0
    if (!c1cs) {
        // 0x80666FB4: lw          $t7, 0x84($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X84);
            goto L_80666FF0;
    }
    goto skip_4;
    // 0x80666FB4: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    skip_4:
    // 0x80666FB8: b           L_80666FEC
    // 0x80666FBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80666FEC;
    // 0x80666FBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80666FC0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80666FC4:
    // 0x80666FC4: lui         $at, 0x8066
    ctx->r1 = S32(RELOC_HI16(504, 0X2D98) << 16);
    // 0x80666FC8: bc1fl       L_80666FF0
    if (!c1cs) {
        // 0x80666FCC: lw          $t7, 0x84($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X84);
            goto L_80666FF0;
    }
    goto skip_5;
    // 0x80666FCC: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    skip_5:
    // 0x80666FD0: lwc1        $f18, 0x7A68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(504, 0X2D98));
    // 0x80666FD4: sub.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80666FD8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80666FDC: nop

    // 0x80666FE0: bc1fl       L_80666FF0
    if (!c1cs) {
        // 0x80666FE4: lw          $t7, 0x84($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X84);
            goto L_80666FF0;
    }
    goto skip_6;
    // 0x80666FE4: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
    skip_6:
    // 0x80666FE8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80666FEC:
    // 0x80666FEC: lw          $t7, 0x84($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X84);
L_80666FF0:
    // 0x80666FF0: beql        $t7, $zero, L_80667014
    if (ctx->r15 == 0) {
        // 0x80666FF4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80667014;
    }
    goto skip_7;
    // 0x80666FF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80666FF8: lw          $t8, 0x180($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X180);
    // 0x80666FFC: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
    // 0x80667000: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x80667004: swc1        $f0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f0.u32l;
    // 0x80667008: lw          $t9, 0x180($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X180);
    // 0x8066700C: swc1        $f0, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f0.u32l;
    // 0x80667010: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80667014:
    // 0x80667014: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80667018: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8066701C: jr          $ra
    // 0x80667020: nop

    return;
    // 0x80667020: nop

;}
RECOMP_FUNC void func_8005B22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B22C: addu        $t6, $a0, $a1
    ctx->r14 = ADD32(ctx->r4, ctx->r5);
    // 0x8005B230: jr          $ra
    // 0x8005B234: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
    return;
    // 0x8005B234: lbu         $v0, 0x10($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X10);
;}
RECOMP_FUNC void func_8073E344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073E344: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8073E348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8073E34C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8073E350: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8073E354: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8073E358: jal         0x8004700C
    // 0x8073E35C: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8073E35C: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    after_0:
    // 0x8073E360: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8073E364: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8073E368: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8073E36C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073E370: jal         0x80048F84
    // 0x8073E374: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8073E374: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x8073E378: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8073E37C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8073E380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8073E384: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8073E388: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8073E38C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8073E390: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8073E394: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8073E398: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8073E39C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8073E3A0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8073E3A4: nop

    // 0x8073E3A8: bc1f        L_8073E3C0
    if (!c1cs) {
        // 0x8073E3AC: nop
    
            goto L_8073E3C0;
    }
    // 0x8073E3AC: nop

    // 0x8073E3B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8073E3B4: nop

    // 0x8073E3B8: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8073E3BC: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_8073E3C0:
    // 0x8073E3C0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X149C) << 16);
    // 0x8073E3C4: lwc1        $f0, -0x1994($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X149C));
    // 0x8073E3C8: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X14A0) << 16);
    // 0x8073E3CC: lwc1        $f4, -0x1990($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X14A0));
    // 0x8073E3D0: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X14A4) << 16);
    // 0x8073E3D4: sub.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f4.fl;
    // 0x8073E3D8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8073E3DC: nop

    // 0x8073E3E0: bc1fl       L_8073E480
    if (!c1cs) {
        // 0x8073E3E4: swc1        $f20, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
            goto L_8073E480;
    }
    goto skip_0;
    // 0x8073E3E4: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8073E3E8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8073E3EC: lwc1        $f10, -0x198C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X14A4));
    // 0x8073E3F0: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8073E3F4: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x8073E3F8: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8073E3FC: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x8073E400: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8073E404: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x8073E408: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8073E40C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8073E410: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8073E414: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8073E418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073E41C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x8073E420: jalr        $t9
    // 0x8073E424: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8073E424: nop

    after_2:
    // 0x8073E428: jal         0x800447C8
    // 0x8073E42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x8073E42C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073E430: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8073E434: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8073E438: lw          $t8, 0x3C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X3C);
    // 0x8073E43C: beql        $t8, $zero, L_8073E468
    if (ctx->r24 == 0) {
        // 0x8073E440: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8073E468;
    }
    goto skip_1;
    // 0x8073E440: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8073E444: beql        $a0, $zero, L_8073E468
    if (ctx->r4 == 0) {
        // 0x8073E448: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_8073E468;
    }
    goto skip_2;
    // 0x8073E448: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_2:
    // 0x8073E44C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073E450: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8073E454: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073E458: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073E45C: jal         0x8002FCFC
    // 0x8073E460: nop

    func_8002FCFC(rdram, ctx);
        goto after_4;
    // 0x8073E460: nop

    after_4:
    // 0x8073E464: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8073E468:
    // 0x8073E468: jal         0x80067BBC
    // 0x8073E46C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8073E46C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8073E470: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    // 0x8073E474: jal         0x80067818
    // 0x8073E478: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8073E478: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8073E47C: swc1        $f20, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f20.u32l;
L_8073E480:
    // 0x8073E480: swc1        $f20, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f20.u32l;
    // 0x8073E484: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8073E488: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8073E48C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8073E490: jr          $ra
    // 0x8073E494: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8073E494: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8005A0B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A0B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A0B8: jal         0x80047058
    // 0x8005A0BC: nop

    func_80047058(rdram, ctx);
        goto after_0;
    // 0x8005A0BC: nop

    after_0:
    // 0x8005A0C0: bne         $v0, $zero, L_8005A0D0
    if (ctx->r2 != 0) {
        // 0x8005A0C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005A0D0;
    }
    // 0x8005A0C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005A0C8: b           L_8005A140
    // 0x8005A0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A140;
    // 0x8005A0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005A0D0:
    // 0x8005A0D0: lwc1        $f4, 0xA8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x8005A0D4: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8005A0D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A0DC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8005A0E0: nop

    // 0x8005A0E4: bc1t        L_8005A0F0
    if (c1cs) {
        // 0x8005A0E8: nop
    
            goto L_8005A0F0;
    }
    // 0x8005A0E8: nop

    // 0x8005A0EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A0F0:
    // 0x8005A0F0: bnel        $v0, $zero, L_8005A144
    if (ctx->r2 != 0) {
        // 0x8005A0F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A144;
    }
    goto skip_0;
    // 0x8005A0F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005A0F8: lwc1        $f8, 0xAC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XAC);
    // 0x8005A0FC: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8005A100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A104: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8005A108: nop

    // 0x8005A10C: bc1t        L_8005A118
    if (c1cs) {
        // 0x8005A110: nop
    
            goto L_8005A118;
    }
    // 0x8005A110: nop

    // 0x8005A114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A118:
    // 0x8005A118: bnel        $v0, $zero, L_8005A144
    if (ctx->r2 != 0) {
        // 0x8005A11C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A144;
    }
    goto skip_1;
    // 0x8005A11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005A120: lwc1        $f16, 0xB0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x8005A124: lwc1        $f18, 0x8C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8005A128: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A12C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8005A130: nop

    // 0x8005A134: bc1tl       L_8005A144
    if (c1cs) {
        // 0x8005A138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A144;
    }
    goto skip_2;
    // 0x8005A138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8005A13C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A140:
    // 0x8005A140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A144:
    // 0x8005A144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A148: jr          $ra
    // 0x8005A14C: nop

    return;
    // 0x8005A14C: nop

;}
RECOMP_FUNC void func_804CECB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CECB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CECBC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CECC0: jr          $ra
    // 0x804CECC4: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x804CECC4: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_806EAE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EAE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EAE08: jal         0x806EA92C
    // 0x806EAE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806EA92C(rdram, ctx);
        goto after_0;
    // 0x806EAE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EAE10: beq         $v0, $zero, L_806EAE3C
    if (ctx->r2 == 0) {
        // 0x806EAE14: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806EAE3C;
    }
    // 0x806EAE14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EAE18: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    // 0x806EAE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EAE20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EAE24: jal         0x806EB43C
    // 0x806EAE28: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_806EB43C(rdram, ctx);
        goto after_1;
    // 0x806EAE28: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x806EAE2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806EAE30: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x806EAE34: jal         0x806EA988
    // 0x806EAE38: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_806EA988(rdram, ctx);
        goto after_2;
    // 0x806EAE38: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
L_806EAE3C:
    // 0x806EAE3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EAE40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EAE44: jr          $ra
    // 0x806EAE48: nop

    return;
    // 0x806EAE48: nop

;}
RECOMP_FUNC void func_80474878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474878: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8047487C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80474880: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80474884: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80474888: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8047488C: jal         0x80066DE4
    // 0x80474890: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80474890: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80474894: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80474898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8047489C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804748A0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x804748A4: jal         0x80066E88
    // 0x804748A8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x804748A8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x804748AC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804748B0: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804748B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804748B8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804748BC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804748C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804748C4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x804748C8: jr          $ra
    // 0x804748CC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    return;
    // 0x804748CC: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
;}
