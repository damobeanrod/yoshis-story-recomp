#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806F2440(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F2448: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F244C: jal         0x806F23E4
    // 0x806F2450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806F23E4(rdram, ctx);
        goto after_0;
    // 0x806F2450: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F2454: bne         $v0, $zero, L_806F246C
    if (ctx->r2 != 0) {
        // 0x806F2458: nop
    
            goto L_806F246C;
    }
    // 0x806F2458: nop

    // 0x806F245C: jal         0x800445A4
    // 0x806F2460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F2460: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F2464: b           L_806F2544
    // 0x806F2468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F2544;
    // 0x806F2468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F246C:
    // 0x806F246C: jal         0x806F2428
    // 0x806F2470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F2428(rdram, ctx);
        goto after_2;
    // 0x806F2470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F2474: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806F2478: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806F247C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806F2480: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(679, 0X1AE4) << 16);
    // 0x806F2484: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806F2488: addiu       $t7, $t7, 0x3064
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(679, 0X1AE4));
    // 0x806F248C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F2490: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F2494: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806F2498: jal         0x806F2364
    // 0x806F249C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F2364(rdram, ctx);
        goto after_3;
    // 0x806F249C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F24A0: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x806F24A4: addiu       $at, $zero, 0x45E7
    ctx->r1 = ADD32(0, 0X45E7);
    // 0x806F24A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F24AC: beq         $v0, $at, L_806F24D4
    if (ctx->r2 == ctx->r1) {
        // 0x806F24B0: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_806F24D4;
    }
    // 0x806F24B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F24B4: addiu       $at, $zero, 0x4615
    ctx->r1 = ADD32(0, 0X4615);
    // 0x806F24B8: beq         $v0, $at, L_806F24E8
    if (ctx->r2 == ctx->r1) {
        // 0x806F24BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F24E8;
    }
    // 0x806F24BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F24C0: addiu       $at, $zero, 0x4616
    ctx->r1 = ADD32(0, 0X4616);
    // 0x806F24C4: beq         $v0, $at, L_806F2510
    if (ctx->r2 == ctx->r1) {
        // 0x806F24C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F2510;
    }
    // 0x806F24C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F24CC: b           L_806F2544
    // 0x806F24D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F2544;
    // 0x806F24D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F24D4:
    // 0x806F24D4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F24D8: jal         0x806F2554
    // 0x806F24DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F2554(rdram, ctx);
        goto after_4;
    // 0x806F24DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x806F24E0: b           L_806F2540
    // 0x806F24E4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
        goto L_806F2540;
    // 0x806F24E4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
L_806F24E8:
    // 0x806F24E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F24EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F24F0: jal         0x806F2554
    // 0x806F24F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F2554(rdram, ctx);
        goto after_5;
    // 0x806F24F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x806F24F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806F24FC: sb          $t9, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r25;
    // 0x806F2500: jal         0x8005FE48
    // 0x806F2504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_6;
    // 0x806F2504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x806F2508: b           L_806F2544
    // 0x806F250C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F2544;
    // 0x806F250C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2510:
    // 0x806F2510: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F2518: jal         0x806F2554
    // 0x806F251C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F2554(rdram, ctx);
        goto after_7;
    // 0x806F251C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x806F2520: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F2524: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x806F2528: jal         0x8005FE48
    // 0x806F252C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_8;
    // 0x806F252C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x806F2530: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x806F2534: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x806F2538: ori         $t3, $t2, 0x18
    ctx->r11 = ctx->r10 | 0X18;
    // 0x806F253C: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
L_806F2540:
    // 0x806F2540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2544:
    // 0x806F2544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F2548: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F254C: jr          $ra
    // 0x806F2550: nop

    return;
    // 0x806F2550: nop

;}
RECOMP_FUNC void func_80058110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005811C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80058120: jal         0x80058098
    // 0x80058124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80058098(rdram, ctx);
        goto after_0;
    // 0x80058124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80058128: lh          $a1, 0x22($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X22);
    // 0x8005812C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80058130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80058134: jal         0x80065728
    // 0x80058138: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x80058138: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    after_1:
    // 0x8005813C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80058140: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x80058144: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80058148: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8005814C: sw          $t7, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r15;
    // 0x80058150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058158: jr          $ra
    // 0x8005815C: nop

    return;
    // 0x8005815C: nop

;}
RECOMP_FUNC void func_80473B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80473B9C: lui         $at, 0x4224
    ctx->r1 = S32(0X4224 << 16);
    // 0x80473BA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80473BA4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80473BA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80473BAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80473BB0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80473BB4: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80473BB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80473BBC: jal         0x804736C0
    // 0x80473BC0: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    func_804736C0(rdram, ctx);
        goto after_0;
    // 0x80473BC0: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80473BC4: jal         0x80473904
    // 0x80473BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80473904(rdram, ctx);
        goto after_1;
    // 0x80473BC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80473BCC: beql        $v0, $zero, L_80473BFC
    if (ctx->r2 == 0) {
        // 0x80473BD0: lw          $t8, 0x14C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X14C);
            goto L_80473BFC;
    }
    goto skip_0;
    // 0x80473BD0: lw          $t8, 0x14C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14C);
    skip_0:
    // 0x80473BD4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80473BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473BDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80473BE0: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x80473BE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80473BE8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80473BEC: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x80473BF0: jal         0x80473DF8
    // 0x80473BF4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_2;
    // 0x80473BF4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x80473BF8: lw          $t8, 0x14C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14C);
L_80473BFC:
    // 0x80473BFC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80473C00: bnel        $t8, $at, L_80473D08
    if (ctx->r24 != ctx->r1) {
        // 0x80473C04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80473D08;
    }
    goto skip_1;
    // 0x80473C04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80473C08: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80473C0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80473C10: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80473C14: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1494) << 16);
    // 0x80473C18: lwc1        $f12, 0x4624($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1494));
    // 0x80473C1C: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80473C20: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80473C24: lwc1        $f10, 0x44($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80473C28: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(161, 0X1498) << 16);
    // 0x80473C2C: lwc1        $f16, 0x4628($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(161, 0X1498));
    // 0x80473C30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80473C34: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80473C38: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80473C3C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x80473C40: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80473C44: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80473C48: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80473C4C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80473C50: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80473C54: lw          $t9, 0x138($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X138);
    // 0x80473C58: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80473C5C: bnel        $t9, $zero, L_80473C8C
    if (ctx->r25 != 0) {
        // 0x80473C60: lwc1        $f10, 0x3C($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
            goto L_80473C8C;
    }
    goto skip_2;
    // 0x80473C60: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    skip_2:
    // 0x80473C64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80473C68: lui         $at, 0x4224
    ctx->r1 = S32(0X4224 << 16);
    // 0x80473C6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80473C70: nop

    // 0x80473C74: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80473C78: nop

    // 0x80473C7C: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80473C80: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80473C84: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80473C88: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
L_80473C8C:
    // 0x80473C8C: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80473C90: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x80473C94: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x80473C98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80473C9C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80473CA0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80473CA4: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x80473CA8: lw          $t9, 0x10($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X10);
    // 0x80473CAC: jalr        $t9
    // 0x80473CB0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80473CB0: nop

    after_3:
    // 0x80473CB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80473CBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80473CC0: jal         0x80473DF8
    // 0x80473CC4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_80473DF8(rdram, ctx);
        goto after_4;
    // 0x80473CC4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x80473CC8: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80473CCC: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80473CD0: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80473CD4: lw          $a2, 0x44($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X44);
    // 0x80473CD8: lw          $a3, 0x50($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X50);
    // 0x80473CDC: jal         0x80473B34
    // 0x80473CE0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    func_80473B34(rdram, ctx);
        goto after_5;
    // 0x80473CE0: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_5:
    // 0x80473CE4: lw          $t2, 0x138($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X138);
    // 0x80473CE8: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    // 0x80473CEC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80473CF0: jal         0x80067BBC
    // 0x80473CF4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x80473CF4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_6:
    // 0x80473CF8: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    // 0x80473CFC: jal         0x80067818
    // 0x80473D00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x80473D00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80473D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80473D08:
    // 0x80473D08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80473D0C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80473D10: jr          $ra
    // 0x80473D14: nop

    return;
    // 0x80473D14: nop

;}
RECOMP_FUNC void func_8066B390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B390: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8066B394: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066B398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8066B39C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066B3A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8066B3A4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8066B3A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B3AC: jal         0x8066AD18
    // 0x8066B3B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8066AD18(rdram, ctx);
        goto after_0;
    // 0x8066B3B0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8066B3B4: jal         0x8066B050
    // 0x8066B3B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8066B050(rdram, ctx);
        goto after_1;
    // 0x8066B3B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8066B3BC: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8066B3C0: lwc1        $f4, 0x88($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8066B3C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8066B3C8: lwc1        $f6, 0x4($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8066B3CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066B3D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8066B3D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8066B3D8: nop

    // 0x8066B3DC: bc1fl       L_8066B3F0
    if (!c1cs) {
        // 0x8066B3E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8066B3F0;
    }
    goto skip_0;
    // 0x8066B3E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8066B3E4: jal         0x8066B970
    // 0x8066B3E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8066B970(rdram, ctx);
        goto after_2;
    // 0x8066B3E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8066B3EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066B3F0:
    // 0x8066B3F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8066B3F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8066B3F8: jr          $ra
    // 0x8066B3FC: nop

    return;
    // 0x8066B3FC: nop

;}
RECOMP_FUNC void func_80446968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446968: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044696C: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80446970: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446974: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80446978: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8044697C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446980: jr          $ra
    // 0x80446984: sw          $t7, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r15;
    return;
    // 0x80446984: sw          $t7, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8002D2F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D2F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002D2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D2F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D2FC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002D300: addiu       $t7, $t7, 0x3FC
    ctx->r15 = ADD32(ctx->r15, 0X3FC);
    // 0x8002D304: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002D308: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002D30C: jal         0x80022EB4
    // 0x8002D310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80022EB4(rdram, ctx);
        goto after_0;
    // 0x8002D310: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002D314: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D318: addiu       $a1, $a1, -0x2B94
    ctx->r5 = ADD32(ctx->r5, -0X2B94);
    // 0x8002D31C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002D320: jal         0x80028118
    // 0x8002D324: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_1;
    // 0x8002D324: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_1:
    // 0x8002D328: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D32C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8002D330: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002D334: jal         0x80067878
    // 0x8002D338: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    func_80067878(rdram, ctx);
        goto after_2;
    // 0x8002D338: sw          $zero, 0x78($t8)
    MEM_W(0X78, ctx->r24) = 0;
    after_2:
    // 0x8002D33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002D344: jr          $ra
    // 0x8002D348: nop

    return;
    // 0x8002D348: nop

;}
RECOMP_FUNC void func_80055E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055E10: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80055E14: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80055E18: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80055E1C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80055E20: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80055E24: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80055E28: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80055E2C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80055E30: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80055E34: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80055E38: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80055E3C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80055E40: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80055E44: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80055E48: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80055E4C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80055E50: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80055E54: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80055E58: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80055E5C: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80055E60: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x80055E64: jal         0x8004921C
    // 0x80055E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80055E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80055E6C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80055E70: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80055E74: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80055E78: jal         0x8004921C
    // 0x80055E7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80055E7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80055E80: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055E84: lh          $t7, 0x96($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X96);
    // 0x80055E88: lw          $v1, 0x168($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X168);
    // 0x80055E8C: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80055E90: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80055E94: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x80055E98: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80055E9C: nop

    // 0x80055EA0: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x80055EA4: mflo        $t6
    ctx->r14 = lo;
    // 0x80055EA8: nop

    // 0x80055EAC: nop

    // 0x80055EB0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055EB4: mflo        $t8
    ctx->r24 = lo;
    // 0x80055EB8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80055EBC: sw          $t1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r9;
    // 0x80055EC0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x80055EC4: lbu         $t4, 0x1($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1);
    // 0x80055EC8: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x80055ECC: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x80055ED0: subu        $s2, $t4, $t5
    ctx->r18 = SUB32(ctx->r12, ctx->r13);
    // 0x80055ED4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80055ED8: subu        $s1, $t2, $t3
    ctx->r17 = SUB32(ctx->r10, ctx->r11);
    // 0x80055EDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80055EE0: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80055EE4: beq         $at, $zero, L_80055EF4
    if (ctx->r1 == 0) {
        // 0x80055EE8: lw          $s0, 0x88($v1)
        ctx->r16 = MEM_W(ctx->r3, 0X88);
            goto L_80055EF4;
    }
    // 0x80055EE8: lw          $s0, 0x88($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X88);
    // 0x80055EEC: b           L_80055EF8
    // 0x80055EF0: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
        goto L_80055EF8;
    // 0x80055EF0: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
L_80055EF4:
    // 0x80055EF4: or          $s5, $s2, $zero
    ctx->r21 = ctx->r18 | 0;
L_80055EF8:
    // 0x80055EF8: jal         0x80049018
    // 0x80055EFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x80055EFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_2:
    // 0x80055F00: beq         $v0, $zero, L_80056154
    if (ctx->r2 == 0) {
        // 0x80055F04: nop
    
            goto L_80056154;
    }
    // 0x80055F04: nop

    // 0x80055F08: blez        $s5, L_80056390
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80055F0C: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80056390;
    }
    // 0x80055F0C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80055F10: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80055F14: mtc1        $s5, $f8
    ctx->f8.u32l = ctx->r21;
    // 0x80055F18: mtc1        $s2, $f16
    ctx->f16.u32l = ctx->r18;
    // 0x80055F1C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055F20: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x80055F24: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x80055F28: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x80055F2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80055F30: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80055F34: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055F38: div.s       $f28, $f6, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80055F3C: div.s       $f30, $f18, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_80055F40:
    // 0x80055F40: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80055F44: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80055F48: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80055F4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80055F50: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80055F54: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80055F58: jal         0x8004921C
    // 0x80055F5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x80055F5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_3:
    // 0x80055F60: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80055F64: lw          $t7, 0x84($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X84);
    // 0x80055F68: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80055F6C: trunc.w.s   $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    ctx->f10.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80055F70: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80055F74: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80055F78: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80055F7C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80055F80: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80055F84: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x80055F88: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055F8C: lh          $t5, 0x0($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X0);
    // 0x80055F90: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x80055F94: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80055F98: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80055F9C: mflo        $t2
    ctx->r10 = lo;
    // 0x80055FA0: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80055FA4: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80055FA8: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055FAC: addu        $t2, $fp, $a2
    ctx->r10 = ADD32(ctx->r30, ctx->r6);
    // 0x80055FB0: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x80055FB4: lbu         $t0, 0x0($t4)
    ctx->r8 = MEM_BU(ctx->r12, 0X0);
    // 0x80055FB8: lbu         $a3, 0x0($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X0);
    // 0x80055FBC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80055FC0: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80055FC4: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80055FC8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80055FCC: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055FD0: mflo        $t9
    ctx->r25 = lo;
    // 0x80055FD4: addu        $a0, $t9, $t1
    ctx->r4 = ADD32(ctx->r25, ctx->r9);
    // 0x80055FD8: beq         $at, $zero, L_80055FE8
    if (ctx->r1 == 0) {
        // 0x80055FDC: nop
    
            goto L_80055FE8;
    }
    // 0x80055FDC: nop

    // 0x80055FE0: b           L_80055FE8
    // 0x80055FE4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_80055FE8;
    // 0x80055FE4: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80055FE8:
    // 0x80055FE8: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80055FEC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80055FF0: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80055FF4: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80055FF8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80055FFC: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x80056000: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80056004: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80056008: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8005600C: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80056010: bne         $t9, $zero, L_80056038
    if (ctx->r25 != 0) {
        // 0x80056014: div.s       $f12, $f6, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
            goto L_80056038;
    }
    // 0x80056014: div.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80056018: lbu         $t1, -0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X1);
L_8005601C:
    // 0x8005601C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80056020: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80056024: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80056028: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8005602C: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80056030: beql        $t6, $zero, L_8005601C
    if (ctx->r14 == 0) {
        // 0x80056034: lbu         $t1, -0x1($v1)
        ctx->r9 = MEM_BU(ctx->r3, -0X1);
            goto L_8005601C;
    }
    goto skip_0;
    // 0x80056034: lbu         $t1, -0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X1);
    skip_0:
L_80056038:
    // 0x80056038: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8005603C: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x80056040: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x80056044: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80056048: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8005604C: bne         $t1, $zero, L_80056074
    if (ctx->r9 != 0) {
        // 0x80056050: nop
    
            goto L_80056074;
    }
    // 0x80056050: nop

    // 0x80056054: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
L_80056058:
    // 0x80056058: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005605C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80056060: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80056064: lhu         $t6, 0x0($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0X0);
    // 0x80056068: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8005606C: beql        $t7, $zero, L_80056058
    if (ctx->r15 == 0) {
        // 0x80056070: lbu         $t2, 0x1($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X1);
            goto L_80056058;
    }
    goto skip_1;
    // 0x80056070: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    skip_1:
L_80056074:
    // 0x80056074: blezl       $a2, L_80056140
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80056078: add.s       $f26, $f26, $f28
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
            goto L_80056140;
    }
    goto skip_2;
    // 0x80056078: add.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
    skip_2:
L_8005607C:
    // 0x8005607C: trunc.w.s   $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    ctx->f10.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x80056080: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056084: trunc.w.s   $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80056088: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005608C: add.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x80056090: beql        $s2, $v0, L_800560E0
    if (ctx->r18 == ctx->r2) {
        // 0x80056094: mfc1        $v0, $f16
        ctx->r2 = (int32_t)ctx->f16.u32l;
            goto L_800560E0;
    }
    goto skip_3;
    // 0x80056094: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    skip_3:
    // 0x80056098: lbu         $t8, -0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, -0X1);
    // 0x8005609C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800560A0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800560A4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800560A8: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x800560AC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800560B0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800560B4: bne         $t3, $zero, L_800560DC
    if (ctx->r11 != 0) {
        // 0x800560B8: nop
    
            goto L_800560DC;
    }
    // 0x800560B8: nop

    // 0x800560BC: lbu         $t4, -0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, -0X1);
L_800560C0:
    // 0x800560C0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800560C4: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x800560C8: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x800560CC: lhu         $t5, 0x0($t7)
    ctx->r13 = MEM_HU(ctx->r15, 0X0);
    // 0x800560D0: andi        $t8, $t5, 0x1
    ctx->r24 = ctx->r13 & 0X1;
    // 0x800560D4: beql        $t8, $zero, L_800560C0
    if (ctx->r24 == 0) {
        // 0x800560D8: lbu         $t4, -0x1($v1)
        ctx->r12 = MEM_BU(ctx->r3, -0X1);
            goto L_800560C0;
    }
    goto skip_4;
    // 0x800560D8: lbu         $t4, -0x1($v1)
    ctx->r12 = MEM_BU(ctx->r3, -0X1);
    skip_4:
L_800560DC:
    // 0x800560DC: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
L_800560E0:
    // 0x800560E0: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800560E4: add.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x800560E8: beq         $s3, $v0, L_80056134
    if (ctx->r19 == ctx->r2) {
        // 0x800560EC: nop
    
            goto L_80056134;
    }
    // 0x800560EC: nop

    // 0x800560F0: lbu         $t1, 0x1($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X1);
    // 0x800560F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800560F8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800560FC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80056100: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80056104: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x80056108: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x8005610C: bne         $t6, $zero, L_80056134
    if (ctx->r14 != 0) {
        // 0x80056110: nop
    
            goto L_80056134;
    }
    // 0x80056110: nop

    // 0x80056114: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_80056118:
    // 0x80056118: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005611C: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x80056120: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x80056124: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80056128: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x8005612C: beql        $t1, $zero, L_80056118
    if (ctx->r9 == 0) {
        // 0x80056130: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_80056118;
    }
    goto skip_5;
    // 0x80056130: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_5:
L_80056134:
    // 0x80056134: bne         $s1, $a2, L_8005607C
    if (ctx->r17 != ctx->r6) {
        // 0x80056138: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_8005607C;
    }
    // 0x80056138: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8005613C: add.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
L_80056140:
    // 0x80056140: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80056144: bne         $s4, $s5, L_80055F40
    if (ctx->r20 != ctx->r21) {
        // 0x80056148: add.s       $f24, $f24, $f30
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f30.fl;
            goto L_80055F40;
    }
    // 0x80056148: add.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f30.fl;
    // 0x8005614C: b           L_80056394
    // 0x80056150: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
        goto L_80056394;
    // 0x80056150: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80056154:
    // 0x80056154: blez        $s5, L_80056390
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80056158: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80056390;
    }
    // 0x80056158: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8005615C: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80056160: mtc1        $s5, $f8
    ctx->f8.u32l = ctx->r21;
    // 0x80056164: mtc1        $s2, $f10
    ctx->f10.u32l = ctx->r18;
    // 0x80056168: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005616C: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x80056170: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x80056174: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x80056178: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005617C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80056180: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80056184: div.s       $f28, $f18, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80056188: div.s       $f30, $f16, $f8
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f30.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
L_8005618C:
    // 0x8005618C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80056190: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80056194: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80056198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005619C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800561A0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800561A4: jal         0x8004921C
    // 0x800561A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x800561A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_4:
    // 0x800561AC: trunc.w.s   $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    ctx->f18.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800561B0: lw          $t3, 0x84($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X84);
    // 0x800561B4: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800561B8: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800561BC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800561C0: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x800561C4: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800561C8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800561CC: addu        $t6, $a1, $t4
    ctx->r14 = ADD32(ctx->r5, ctx->r12);
    // 0x800561D0: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800561D4: lh          $t9, 0x0($s7)
    ctx->r25 = MEM_H(ctx->r23, 0X0);
    // 0x800561D8: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x800561DC: addu        $t3, $a2, $t2
    ctx->r11 = ADD32(ctx->r6, ctx->r10);
    // 0x800561E0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800561E4: mflo        $t7
    ctx->r15 = lo;
    // 0x800561E8: addu        $v1, $t7, $t5
    ctx->r3 = ADD32(ctx->r15, ctx->r13);
    // 0x800561EC: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800561F0: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800561F4: addu        $t7, $fp, $a2
    ctx->r15 = ADD32(ctx->r30, ctx->r6);
    // 0x800561F8: addu        $t8, $t5, $a1
    ctx->r24 = ADD32(ctx->r13, ctx->r5);
    // 0x800561FC: lbu         $t0, 0x0($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X0);
    // 0x80056200: lbu         $a3, 0x0($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X0);
    // 0x80056204: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80056208: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8005620C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80056210: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80056214: mflo        $t4
    ctx->r12 = lo;
    // 0x80056218: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8005621C: beq         $at, $zero, L_8005622C
    if (ctx->r1 == 0) {
        // 0x80056220: nop
    
            goto L_8005622C;
    }
    // 0x80056220: nop

    // 0x80056224: b           L_8005622C
    // 0x80056228: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_8005622C;
    // 0x80056228: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_8005622C:
    // 0x8005622C: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80056230: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80056234: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80056238: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005623C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80056240: addu        $t9, $s0, $t2
    ctx->r25 = ADD32(ctx->r16, ctx->r10);
    // 0x80056244: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x80056248: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005624C: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80056250: div.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80056254: bne         $t4, $zero, L_8005627C
    if (ctx->r12 != 0) {
        // 0x80056258: div.s       $f12, $f18, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
            goto L_8005627C;
    }
    // 0x80056258: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005625C: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
L_80056260:
    // 0x80056260: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80056264: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80056268: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x8005626C: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x80056270: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x80056274: beql        $t1, $zero, L_80056260
    if (ctx->r9 == 0) {
        // 0x80056278: lbu         $t6, 0x1($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X1);
            goto L_80056260;
    }
    goto skip_6;
    // 0x80056278: lbu         $t6, 0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1);
    skip_6:
L_8005627C:
    // 0x8005627C: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x80056280: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x80056284: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80056288: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8005628C: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80056290: bne         $t6, $zero, L_800562B8
    if (ctx->r14 != 0) {
        // 0x80056294: nop
    
            goto L_800562B8;
    }
    // 0x80056294: nop

    // 0x80056298: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_8005629C:
    // 0x8005629C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800562A0: sll         $t5, $t7, 1
    ctx->r13 = S32(ctx->r15 << 1);
    // 0x800562A4: addu        $t8, $s0, $t5
    ctx->r24 = ADD32(ctx->r16, ctx->r13);
    // 0x800562A8: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x800562AC: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x800562B0: beql        $t2, $zero, L_8005629C
    if (ctx->r10 == 0) {
        // 0x800562B4: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_8005629C;
    }
    goto skip_7;
    // 0x800562B4: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_7:
L_800562B8:
    // 0x800562B8: blezl       $a2, L_80056384
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800562BC: add.s       $f26, $f26, $f28
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
            goto L_80056384;
    }
    goto skip_8;
    // 0x800562BC: add.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
    skip_8:
L_800562C0:
    // 0x800562C0: trunc.w.s   $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    ctx->f6.u32l = TRUNC_W_S(ctx->f22.fl);
    // 0x800562C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800562C8: trunc.w.s   $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    ctx->f10.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800562CC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800562D0: add.s       $f20, $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f12.fl;
    // 0x800562D4: beql        $s2, $v0, L_80056324
    if (ctx->r18 == ctx->r2) {
        // 0x800562D8: mfc1        $v0, $f10
        ctx->r2 = (int32_t)ctx->f10.u32l;
            goto L_80056324;
    }
    goto skip_9;
    // 0x800562D8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    skip_9:
    // 0x800562DC: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x800562E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800562E4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800562E8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800562EC: addu        $t6, $s0, $t4
    ctx->r14 = ADD32(ctx->r16, ctx->r12);
    // 0x800562F0: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800562F4: andi        $t5, $t7, 0x1
    ctx->r13 = ctx->r15 & 0X1;
    // 0x800562F8: bne         $t5, $zero, L_80056320
    if (ctx->r13 != 0) {
        // 0x800562FC: nop
    
            goto L_80056320;
    }
    // 0x800562FC: nop

    // 0x80056300: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
L_80056304:
    // 0x80056304: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80056308: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8005630C: addu        $t2, $s0, $t1
    ctx->r10 = ADD32(ctx->r16, ctx->r9);
    // 0x80056310: lhu         $t9, 0x0($t2)
    ctx->r25 = MEM_HU(ctx->r10, 0X0);
    // 0x80056314: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x80056318: beql        $t3, $zero, L_80056304
    if (ctx->r11 == 0) {
        // 0x8005631C: lbu         $t8, 0x1($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X1);
            goto L_80056304;
    }
    goto skip_10;
    // 0x8005631C: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    skip_10:
L_80056320:
    // 0x80056320: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
L_80056324:
    // 0x80056324: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80056328: add.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f2.fl;
    // 0x8005632C: beq         $s3, $v0, L_80056378
    if (ctx->r19 == ctx->r2) {
        // 0x80056330: nop
    
            goto L_80056378;
    }
    // 0x80056330: nop

    // 0x80056334: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80056338: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005633C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80056340: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80056344: addu        $t5, $s0, $t7
    ctx->r13 = ADD32(ctx->r16, ctx->r15);
    // 0x80056348: lhu         $t8, 0x0($t5)
    ctx->r24 = MEM_HU(ctx->r13, 0X0);
    // 0x8005634C: andi        $t1, $t8, 0x1
    ctx->r9 = ctx->r24 & 0X1;
    // 0x80056350: bne         $t1, $zero, L_80056378
    if (ctx->r9 != 0) {
        // 0x80056354: nop
    
            goto L_80056378;
    }
    // 0x80056354: nop

    // 0x80056358: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
L_8005635C:
    // 0x8005635C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056360: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x80056364: addu        $t3, $s0, $t9
    ctx->r11 = ADD32(ctx->r16, ctx->r25);
    // 0x80056368: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x8005636C: andi        $t6, $t4, 0x1
    ctx->r14 = ctx->r12 & 0X1;
    // 0x80056370: beql        $t6, $zero, L_8005635C
    if (ctx->r14 == 0) {
        // 0x80056374: lbu         $t2, 0x1($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X1);
            goto L_8005635C;
    }
    goto skip_11;
    // 0x80056374: lbu         $t2, 0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X1);
    skip_11:
L_80056378:
    // 0x80056378: bne         $s1, $a2, L_800562C0
    if (ctx->r17 != ctx->r6) {
        // 0x8005637C: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_800562C0;
    }
    // 0x8005637C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x80056380: add.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
L_80056384:
    // 0x80056384: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80056388: bne         $s4, $s5, L_8005618C
    if (ctx->r20 != ctx->r21) {
        // 0x8005638C: add.s       $f24, $f24, $f30
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f30.fl;
            goto L_8005618C;
    }
    // 0x8005638C: add.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f30.fl;
L_80056390:
    // 0x80056390: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_80056394:
    // 0x80056394: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80056398: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8005639C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800563A0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800563A4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800563A8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x800563AC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800563B0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800563B4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800563B8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800563BC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800563C0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800563C4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800563C8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800563CC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800563D0: jr          $ra
    // 0x800563D4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800563D4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8066B568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B568: jr          $ra
    // 0x8066B56C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8066B56C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804BD3A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD3A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BD3A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD3A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BD3AC: jal         0x80062748
    // 0x804BD3B0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x804BD3B0: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    after_0:
    // 0x804BD3B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BD3B8: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x804BD3BC: beql        $v1, $zero, L_804BD3DC
    if (ctx->r3 == 0) {
        // 0x804BD3C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD3DC;
    }
    goto skip_0;
    // 0x804BD3C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD3C4: jal         0x804BD364
    // 0x804BD3C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_804BD364(rdram, ctx);
        goto after_1;
    // 0x804BD3C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x804BD3CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD3D0: lw          $t6, 0x1F4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1F4);
    // 0x804BD3D4: sw          $v0, 0x374($t6)
    MEM_W(0X374, ctx->r14) = ctx->r2;
    // 0x804BD3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD3DC:
    // 0x804BD3DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BD3E0: jr          $ra
    // 0x804BD3E4: nop

    return;
    // 0x804BD3E4: nop

;}
RECOMP_FUNC void func_80400A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400A5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80400A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80400A64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80400A68: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80400A6C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x80400A70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80400A74: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80400A78: jal         0x80065728
    // 0x80400A7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80400A7C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80400A80: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80400A84: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80400A88: sw          $t7, 0xF0($a3)
    MEM_W(0XF0, ctx->r7) = ctx->r15;
    // 0x80400A8C: addiu       $a0, $a3, 0xF4
    ctx->r4 = ADD32(ctx->r7, 0XF4);
    // 0x80400A90: jal         0x8040165C
    // 0x80400A94: addiu       $a1, $a3, 0x114
    ctx->r5 = ADD32(ctx->r7, 0X114);
    func_8040165C(rdram, ctx);
        goto after_1;
    // 0x80400A94: addiu       $a1, $a3, 0x114
    ctx->r5 = ADD32(ctx->r7, 0X114);
    after_1:
    // 0x80400A98: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80400A9C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80400AA0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80400AA4: swc1        $f4, 0x11C($a3)
    MEM_W(0X11C, ctx->r7) = ctx->f4.u32l;
    // 0x80400AA8: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80400AAC: swc1        $f6, 0x120($a3)
    MEM_W(0X120, ctx->r7) = ctx->f6.u32l;
    // 0x80400AB0: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80400AB4: swc1        $f8, 0x124($a3)
    MEM_W(0X124, ctx->r7) = ctx->f8.u32l;
    // 0x80400AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80400ABC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80400AC0: jr          $ra
    // 0x80400AC4: nop

    return;
    // 0x80400AC4: nop

;}
RECOMP_FUNC void func_80071E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071E2C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80071E30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80071E34: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80071E38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80071E3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80071E40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80071E44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071E48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071E4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071E50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80071E54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80071E58: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80071E5C: lui         $fp, 0x800B
    ctx->r30 = S32(0X800B << 16);
    // 0x80071E60: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x80071E64: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80071E68: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80071E6C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x80071E70: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80071E74: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80071E78: addiu       $s0, $s0, -0x58E8
    ctx->r16 = ADD32(ctx->r16, -0X58E8);
    // 0x80071E7C: addiu       $s2, $s2, -0x58C0
    ctx->r18 = ADD32(ctx->r18, -0X58C0);
    // 0x80071E80: addiu       $s3, $s3, -0x2730
    ctx->r19 = ADD32(ctx->r19, -0X2730);
    // 0x80071E84: addiu       $s4, $s4, -0x4D98
    ctx->r20 = ADD32(ctx->r20, -0X4D98);
    // 0x80071E88: addiu       $s7, $s7, -0x2790
    ctx->r23 = ADD32(ctx->r23, -0X2790);
    // 0x80071E8C: addiu       $fp, $fp, -0x7B20
    ctx->r30 = ADD32(ctx->r30, -0X7B20);
    // 0x80071E90: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80071E94: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80071E98: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_80071E9C:
    // 0x80071E9C: beq         $t6, $zero, L_80071EBC
    if (ctx->r14 == 0) {
        // 0x80071EA0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80071EBC;
    }
    // 0x80071EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80071EA4:
    // 0x80071EA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071EA8: jal         0x800824B0
    // 0x80071EAC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80071EAC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80071EB0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80071EB4: bnel        $t7, $zero, L_80071EA4
    if (ctx->r15 != 0) {
        // 0x80071EB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80071EA4;
    }
    goto skip_0;
    // 0x80071EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_80071EBC:
    // 0x80071EBC: sll         $a1, $s5, 16
    ctx->r5 = S32(ctx->r21 << 16);
    // 0x80071EC0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80071EC4: jal         0x800756A8
    // 0x80071EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800756A8(rdram, ctx);
        goto after_1;
    // 0x80071EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80071ECC: beq         $s1, $zero, L_80071F70
    if (ctx->r17 == 0) {
        // 0x80071ED0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80071F70;
    }
    // 0x80071ED0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80071ED4: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x80071ED8: or          $t1, $s2, $zero
    ctx->r9 = ctx->r18 | 0;
    // 0x80071EDC: addiu       $t2, $s1, 0x3C
    ctx->r10 = ADD32(ctx->r17, 0X3C);
L_80071EE0:
    // 0x80071EE0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80071EE4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80071EE8: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80071EEC: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x80071EF0: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x80071EF4: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x80071EF8: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x80071EFC: bne         $t0, $t2, L_80071EE0
    if (ctx->r8 != ctx->r10) {
        // 0x80071F00: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_80071EE0;
    }
    // 0x80071F00: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x80071F04: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80071F08: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80071F0C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80071F10: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x80071F14: sw          $t3, -0x5880($at)
    MEM_W(-0X5880, ctx->r1) = ctx->r11;
    // 0x80071F18: lw          $t4, 0x44($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X44);
    // 0x80071F1C: sw          $t4, -0x587C($at)
    MEM_W(-0X587C, ctx->r1) = ctx->r12;
    // 0x80071F20: lw          $t5, 0x48($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X48);
    // 0x80071F24: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80071F28: sw          $t5, -0x5878($at)
    MEM_W(-0X5878, ctx->r1) = ctx->r13;
    // 0x80071F2C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80071F30: beql        $v0, $zero, L_80071F50
    if (ctx->r2 == 0) {
        // 0x80071F34: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80071F50;
    }
    goto skip_1;
    // 0x80071F34: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    skip_1:
    // 0x80071F38: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x80071F3C: bnel        $s5, $t6, L_80071F50
    if (ctx->r21 != ctx->r14) {
        // 0x80071F40: addiu       $t7, $zero, 0x5
        ctx->r15 = ADD32(0, 0X5);
            goto L_80071F50;
    }
    goto skip_2;
    // 0x80071F40: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    skip_2:
    // 0x80071F44: jal         0x80086860
    // 0x80071F48: sw          $s6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r22;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_2;
    // 0x80071F48: sw          $s6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r22;
    after_2:
    // 0x80071F4C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
L_80071F50:
    // 0x80071F50: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80071F54: sw          $t7, -0x5878($at)
    MEM_W(-0X5878, ctx->r1) = ctx->r15;
    // 0x80071F58: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80071F5C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80071F60: jal         0x8008AFE0
    // 0x80071F64: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osJamMesg_recomp(rdram, ctx);
        goto after_3;
    // 0x80071F64: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x80071F68: b           L_80071F7C
    // 0x80071F6C: nop

        goto L_80071F7C;
    // 0x80071F6C: nop

L_80071F70:
    // 0x80071F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071F74: jal         0x80082210
    // 0x80071F78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x80071F78: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_4:
L_80071F7C:
    // 0x80071F7C: jal         0x80071DEC
    // 0x80071F80: nop

    func_80071DEC(rdram, ctx);
        goto after_5;
    // 0x80071F80: nop

    after_5:
    // 0x80071F84: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x80071F88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80071F8C: bne         $t2, $zero, L_80071FA4
    if (ctx->r10 != 0) {
        // 0x80071F90: nop
    
            goto L_80071FA4;
    }
    // 0x80071F90: nop

    // 0x80071F94: jal         0x80009930
    // 0x80071F98: nop

    func_80009930(rdram, ctx);
        goto after_6;
    // 0x80071F98: nop

    after_6:
    // 0x80071F9C: b           L_80071FA4
    // 0x80071FA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_80071FA4;
    // 0x80071FA0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80071FA4:
    // 0x80071FA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80071FA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071FAC: jal         0x800824B0
    // 0x80071FB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80071FB0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_7:
    // 0x80071FB4: b           L_80071E9C
    // 0x80071FB8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
        goto L_80071E9C;
    // 0x80071FB8: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80071FBC: nop

    // 0x80071FC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80071FC4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071FC8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80071FCC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071FD0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071FD4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071FD8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80071FDC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80071FE0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80071FE4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80071FE8: jr          $ra
    // 0x80071FEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80071FEC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8045C760(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045C760: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045C764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045C768: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045C76C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8045C770: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8045C774: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8045C778: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8045C77C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8045C780: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x8045C784: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8045C788: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8045C78C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8045C790: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x8045C794: lw          $t5, 0x8($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X8);
    // 0x8045C798: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x8045C79C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8045C7A0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8045C7A4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8045C7A8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8045C7AC: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8045C7B0: lwc1        $f18, 0x4($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8045C7B4: lwc1        $f16, 0x4($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8045C7B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8045C7BC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8045C7C0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8045C7C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8045C7C8: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8045C7CC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8045C7D0: nop

    // 0x8045C7D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8045C7D8: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8045C7DC: lwc1        $f8, 0x8($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8045C7E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8045C7E4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045C7E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8045C7EC: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8045C7F0: jal         0x8006593C
    // 0x8045C7F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x8045C7F4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x8045C7F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8045C7FC: jal         0x8006593C
    // 0x8045C800: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x8045C800: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8045C804: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8045C808: jal         0x8006593C
    // 0x8045C80C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8006593C(rdram, ctx);
        goto after_2;
    // 0x8045C80C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8045C810: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8045C814: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8045C818: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8045C81C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8045C820: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x8045C824: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8045C828: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8045C82C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8045C830: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8045C834: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x8045C838: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8045C83C: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8045C840: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8045C844: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8045C848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045C84C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8045C850: bnel        $at, $zero, L_8045C89C
    if (ctx->r1 != 0) {
        // 0x8045C854: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8045C89C;
    }
    goto skip_0;
    // 0x8045C854: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x8045C858: lw          $t5, 0x4($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X4);
    // 0x8045C85C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8045C860: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8045C864: bne         $at, $zero, L_8045C898
    if (ctx->r1 != 0) {
        // 0x8045C868: slt         $at, $t8, $v0
        ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8045C898;
    }
    // 0x8045C868: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8045C86C: bnel        $at, $zero, L_8045C89C
    if (ctx->r1 != 0) {
        // 0x8045C870: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8045C89C;
    }
    goto skip_1;
    // 0x8045C870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8045C874: bgez        $a2, L_8045C884
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8045C878: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8045C884;
    }
    // 0x8045C878: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8045C87C: b           L_8045C884
    // 0x8045C880: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8045C884;
    // 0x8045C880: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8045C884:
    // 0x8045C884: bgezl       $a3, L_8045C898
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8045C888: ori         $v1, $v1, 0x4
        ctx->r3 = ctx->r3 | 0X4;
            goto L_8045C898;
    }
    goto skip_2;
    // 0x8045C888: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
    skip_2:
    // 0x8045C88C: b           L_8045C898
    // 0x8045C890: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
        goto L_8045C898;
    // 0x8045C890: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x8045C894: ori         $v1, $v1, 0x4
    ctx->r3 = ctx->r3 | 0X4;
L_8045C898:
    // 0x8045C898: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8045C89C:
    // 0x8045C89C: jr          $ra
    // 0x8045C8A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8045C8A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80044D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044D34: bne         $a0, $zero, L_80044D54
    if (ctx->r4 != 0) {
        // 0x80044D38: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80044D54;
    }
    // 0x80044D38: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80044D3C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044D40: addiu       $a0, $a0, 0x5E8
    ctx->r4 = ADD32(ctx->r4, 0X5E8);
    // 0x80044D44: jal         0x80071380
    // 0x80044D48: addiu       $a1, $zero, 0x6B7
    ctx->r5 = ADD32(0, 0X6B7);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80044D48: addiu       $a1, $zero, 0x6B7
    ctx->r5 = ADD32(0, 0X6B7);
    after_0:
    // 0x80044D4C: b           L_80044DB4
    // 0x80044D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044DB4;
    // 0x80044D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044D54:
    // 0x80044D54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80044D58: bne         $a1, $at, L_80044D78
    if (ctx->r5 != ctx->r1) {
        // 0x80044D5C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80044D78;
    }
    // 0x80044D5C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80044D60: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80044D64: addiu       $a0, $a0, 0x5F8
    ctx->r4 = ADD32(ctx->r4, 0X5F8);
    // 0x80044D68: jal         0x80071380
    // 0x80044D6C: addiu       $a1, $zero, 0x6BE
    ctx->r5 = ADD32(0, 0X6BE);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80044D6C: addiu       $a1, $zero, 0x6BE
    ctx->r5 = ADD32(0, 0X6BE);
    after_1:
    // 0x80044D70: b           L_80044DB4
    // 0x80044D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80044DB4;
    // 0x80044D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044D78:
    // 0x80044D78: jal         0x8004627C
    // 0x80044D7C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004627C(rdram, ctx);
        goto after_2;
    // 0x80044D7C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x80044D80: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80044D84: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x80044D88: lh          $t6, 0x17E($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X17E);
    // 0x80044D8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80044D90: beq         $t6, $at, L_80044DA4
    if (ctx->r14 == ctx->r1) {
        // 0x80044D94: nop
    
            goto L_80044DA4;
    }
    // 0x80044D94: nop

    // 0x80044D98: jal         0x8004457C
    // 0x80044D9C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004457C(rdram, ctx);
        goto after_3;
    // 0x80044D9C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x80044DA0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
L_80044DA4:
    // 0x80044DA4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044DA8: jal         0x80057C08
    // 0x80044DAC: addiu       $a0, $a0, -0x770C
    ctx->r4 = ADD32(ctx->r4, -0X770C);
    func_80057C08(rdram, ctx);
        goto after_4;
    // 0x80044DAC: addiu       $a0, $a0, -0x770C
    ctx->r4 = ADD32(ctx->r4, -0X770C);
    after_4:
    // 0x80044DB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80044DB4:
    // 0x80044DB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044DB8: jr          $ra
    // 0x80044DBC: nop

    return;
    // 0x80044DBC: nop

;}
RECOMP_FUNC void func_80446568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446568: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044656C: addiu       $v1, $zero, 0x1EF0
    ctx->r3 = ADD32(0, 0X1EF0);
    // 0x80446570: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446574: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x80446578: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044657C: sw          $zero, 0x6CB4($at)
    MEM_W(0X6CB4, ctx->r1) = 0;
    // 0x80446580: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x80446584: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x80446588: sw          $a1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r5;
    // 0x8044658C: sw          $a2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r6;
    // 0x80446590: sw          $a1, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r5;
    // 0x80446594: sw          $a2, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r6;
    // 0x80446598: jr          $ra
    // 0x8044659C: sw          $v1, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r3;
    return;
    // 0x8044659C: sw          $v1, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void func_805175E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805175E4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x805175E8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x805175EC: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x805175F0: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x805175F4: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x805175F8: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x805175FC: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80517600: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80517604: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80517608: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8051760C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80517610: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80517614: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80517618: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8051761C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80517620: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80517624: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80517628: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x8051762C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80517630: bltz        $v0, L_8051780C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80517634: slti        $at, $v0, 0x140
        ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
            goto L_8051780C;
    }
    // 0x80517634: slti        $at, $v0, 0x140
    ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80517638: beq         $at, $zero, L_8051780C
    if (ctx->r1 == 0) {
        // 0x8051763C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8051780C;
    }
    // 0x8051763C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80517640: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80517644: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80517648: lui         $at, 0xC0B0
    ctx->r1 = S32(0XC0B0 << 16);
    // 0x8051764C: lui         $s7, 0x8051
    ctx->r23 = S32(RELOC_HI16(288, 0X4A0) << 16);
    // 0x80517650: lui         $s6, 0x800F
    ctx->r22 = S32(0X800F << 16);
    // 0x80517654: lui         $s5, 0x8051
    ctx->r21 = S32(RELOC_HI16(288, 0X488) << 16);
    // 0x80517658: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8051765C: lw          $s4, 0x1E0($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X1E0);
    // 0x80517660: addiu       $s5, $s5, 0x7A08
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(288, 0X488));
    // 0x80517664: addiu       $s6, $s6, 0x7EA0
    ctx->r22 = ADD32(ctx->r22, 0X7EA0);
    // 0x80517668: addiu       $s7, $s7, 0x7A20
    ctx->r23 = ADD32(ctx->r23, (int16_t)RELOC_LO16(288, 0X4A0));
    // 0x8051766C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
L_80517670:
    // 0x80517670: bnel        $s4, $zero, L_805177D4
    if (ctx->r20 != 0) {
        // 0x80517674: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_805177D4;
    }
    goto skip_0;
    // 0x80517674: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x80517678: lwc1        $f20, 0x98($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X98);
    // 0x8051767C: sll         $s2, $s3, 2
    ctx->r18 = S32(ctx->r19 << 2);
    // 0x80517680: jal         0x80066DE4
    // 0x80517684: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80517684: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80517688: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8051768C: jal         0x80066E88
    // 0x80517690: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80517690: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80517694: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80517698: jal         0x80049018
    // 0x8051769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_2;
    // 0x8051769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805176A0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x805176A4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x805176A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805176AC: addu        $t7, $s5, $t6
    ctx->r15 = ADD32(ctx->r21, ctx->r14);
    // 0x805176B0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x805176B4: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x805176B8: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805176BC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x805176C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805176C4: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805176C8: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805176CC: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(288, 0X640) << 16);
    // 0x805176D0: lwc1        $f6, 0x7BC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(288, 0X640));
    // 0x805176D4: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805176D8: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x805176DC: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805176E0: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x805176E4: lw          $t9, 0xA68($s6)
    ctx->r25 = MEM_W(ctx->r22, 0XA68);
    // 0x805176E8: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805176EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x805176F0: mul.s       $f6, $f2, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x805176F4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x805176F8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805176FC: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x80517700: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80517704: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80517708: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8051770C: add.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80517710: mul.s       $f6, $f2, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80517714: lw          $t9, 0x24($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X24);
    // 0x80517718: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8051771C: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x80517720: jalr        $t9
    // 0x80517724: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80517724: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x80517728: beq         $v0, $zero, L_805177D0
    if (ctx->r2 == 0) {
        // 0x8051772C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_805177D0;
    }
    // 0x8051772C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80517730: jal         0x8004700C
    // 0x80517734: nop

    func_8004700C(rdram, ctx);
        goto after_4;
    // 0x80517734: nop

    after_4:
    // 0x80517738: beq         $v0, $zero, L_8051780C
    if (ctx->r2 == 0) {
        // 0x8051773C: lui         $at, 0xC040
        ctx->r1 = S32(0XC040 << 16);
            goto L_8051780C;
    }
    // 0x8051773C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80517740: lwc1        $f12, 0x8C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x80517744: lw          $t1, 0x138($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X138);
    // 0x80517748: lwc1        $f14, 0xC4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8051774C: sub.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f24.fl;
    // 0x80517750: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80517754: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80517758: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8051775C: div.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f28.fl);
    // 0x80517760: addu        $t3, $s7, $t2
    ctx->r11 = ADD32(ctx->r23, ctx->r10);
    // 0x80517764: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x80517768: lwc1        $f2, 0x84($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8051776C: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80517770: add.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x80517774: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80517778: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8051777C: sub.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f26.fl;
    // 0x80517780: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80517784: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x80517788: mov.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.fl = ctx->f20.fl;
    // 0x8051778C: bc1fl       L_805177A0
    if (!c1cs) {
        // 0x80517790: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_805177A0;
    }
    goto skip_1;
    // 0x80517790: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x80517794: b           L_805177BC
    // 0x80517798: mov.s       $f18, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    ctx->f18.fl = ctx->f30.fl;
        goto L_805177BC;
    // 0x80517798: mov.s       $f18, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    ctx->f18.fl = ctx->f30.fl;
    // 0x8051779C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_805177A0:
    // 0x805177A0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805177A4: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x805177A8: nop

    // 0x805177AC: bc1fl       L_805177C0
    if (!c1cs) {
        // 0x805177B0: lui         $at, 0xC0C0
        ctx->r1 = S32(0XC0C0 << 16);
            goto L_805177C0;
    }
    goto skip_2;
    // 0x805177B0: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    skip_2:
    // 0x805177B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805177B8: nop

L_805177BC:
    // 0x805177BC: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
L_805177C0:
    // 0x805177C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805177C4: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
    // 0x805177C8: swc1        $f28, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = ctx->f28.u32l;
    // 0x805177CC: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
L_805177D0:
    // 0x805177D0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_805177D4:
    // 0x805177D4: bne         $s3, $fp, L_80517670
    if (ctx->r19 != ctx->r30) {
        // 0x805177D8: addiu       $s4, $s4, -0x10
        ctx->r20 = ADD32(ctx->r20, -0X10);
            goto L_80517670;
    }
    // 0x805177D8: addiu       $s4, $s4, -0x10
    ctx->r20 = ADD32(ctx->r20, -0X10);
    // 0x805177DC: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x805177E0: addiu       $at, $zero, 0x1D6
    ctx->r1 = ADD32(0, 0X1D6);
    // 0x805177E4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x805177E8: andi        $t6, $t5, 0x1FF
    ctx->r14 = ctx->r13 & 0X1FF;
    // 0x805177EC: bne         $t6, $at, L_8051780C
    if (ctx->r14 != ctx->r1) {
        // 0x805177F0: sw          $t6, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r14;
            goto L_8051780C;
    }
    // 0x805177F0: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
    // 0x805177F4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805177F8: jal         0x80067BBC
    // 0x805177FC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805177FC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80517800: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    // 0x80517804: jal         0x80067818
    // 0x80517808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80517808: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
L_8051780C:
    // 0x8051780C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80517810: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80517814: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80517818: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8051781C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80517820: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80517824: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80517828: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8051782C: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80517830: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80517834: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80517838: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8051783C: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80517840: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80517844: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80517848: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8051784C: jr          $ra
    // 0x80517850: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80517850: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_805CA850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CA854: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805CA858: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CA85C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(453, 0XB00) << 16);
    // 0x805CA860: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(453, 0XB10) << 16);
    // 0x805CA864: addiu       $a1, $a1, -0x4CA0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(453, 0XB10));
    // 0x805CA868: addiu       $a0, $a0, -0x4CB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(453, 0XB00));
    // 0x805CA86C: jal         0x8004667C
    // 0x805CA870: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805CA870: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x805CA874: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805CA878: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(453, 0X624) << 16);
    // 0x805CA87C: addiu       $a2, $a2, -0x518C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(453, 0X624));
    // 0x805CA880: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805CA884: jal         0x80057B28
    // 0x805CA888: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805CA888: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_1:
    // 0x805CA88C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CA890: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(453, 0X474) << 16);
    // 0x805CA894: addiu       $v0, $v0, -0x533C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(453, 0X474));
    // 0x805CA898: jr          $ra
    // 0x805CA89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805CA89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80556158(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80556158: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8055615C: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80556160: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x80556164: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80556168: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8055616C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80556170: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80556174: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80556178: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8055617C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80556180: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80556184: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80556188: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8055618C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80556190: jal         0x8004700C
    // 0x80556194: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80556194: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80556198: beq         $v0, $zero, L_8055636C
    if (ctx->r2 == 0) {
        // 0x8055619C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8055636C;
    }
    // 0x8055619C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x805561A0: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x805561A4: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805561A8: addiu       $s0, $s2, 0x2DC
    ctx->r16 = ADD32(ctx->r18, 0X2DC);
    // 0x805561AC: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x805561B0: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x805561B4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x805561B8: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x805561BC: lw          $a0, 0x70($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X70);
    // 0x805561C0: lh          $t8, 0x6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X6);
    // 0x805561C4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x805561C8: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x805561CC: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x805561D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805561D4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x805561D8: lh          $t0, 0xC($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XC);
    // 0x805561DC: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x805561E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x805561E4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x805561E8: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x805561EC: lwc1        $f6, 0x88($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805561F0: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x805561F4: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805561F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x805561FC: nop

    // 0x80556200: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80556204: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80556208: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8055620C: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80556210: mul.s       $f26, $f2, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80556214: add.s       $f30, $f12, $f28
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f30.fl = ctx->f12.fl + ctx->f28.fl;
L_80556218:
    // 0x80556218: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8055621C: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80556220: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x80556224: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80556228: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8055622C: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80556230: jal         0x80065954
    // 0x80556234: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80556234: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80556238: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x8055623C: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80556240: bc1fl       L_80556364
    if (!c1cs) {
        // 0x80556244: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80556364;
    }
    goto skip_0;
    // 0x80556244: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80556248: jal         0x80065954
    // 0x8055624C: add.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f26.fl + ctx->f28.fl;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8055624C: add.s       $f20, $f26, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f26.fl + ctx->f28.fl;
    after_2:
    // 0x80556250: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80556254: nop

    // 0x80556258: bc1f        L_80556360
    if (!c1cs) {
        // 0x8055625C: addiu       $t1, $zero, 0x32
        ctx->r9 = ADD32(0, 0X32);
            goto L_80556360;
    }
    // 0x8055625C: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80556260: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80556264: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x80556268: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8055626C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80556270: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80556274: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x80556278: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8055627C: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x80556280: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
    // 0x80556284: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80556288: lwc1        $f0, 0xDC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XDC);
    // 0x8055628C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80556290: nop

    // 0x80556294: bc1fl       L_805562F8
    if (!c1cs) {
        // 0x80556298: lw          $t1, 0x138($s3)
        ctx->r9 = MEM_W(ctx->r19, 0X138);
            goto L_805562F8;
    }
    goto skip_1;
    // 0x80556298: lw          $t1, 0x138($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X138);
    skip_1:
    // 0x8055629C: lw          $t4, 0x138($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X138);
    // 0x805562A0: beql        $t4, $zero, L_805562D4
    if (ctx->r12 == 0) {
        // 0x805562A4: lw          $t8, 0x174($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X174);
            goto L_805562D4;
    }
    goto skip_2;
    // 0x805562A4: lw          $t8, 0x174($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X174);
    skip_2:
    // 0x805562A8: lw          $t5, 0x174($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X174);
    // 0x805562AC: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x805562B0: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x805562B4: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x805562B8: bnel        $t6, $zero, L_8055634C
    if (ctx->r14 != 0) {
        // 0x805562BC: andi        $t8, $v0, 0xF00
        ctx->r24 = ctx->r2 & 0XF00;
            goto L_8055634C;
    }
    goto skip_3;
    // 0x805562BC: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
    skip_3:
    // 0x805562C0: lw          $t7, 0x174($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X174);
    // 0x805562C4: swc1        $f0, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f0.u32l;
    // 0x805562C8: b           L_80556348
    // 0x805562CC: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
        goto L_80556348;
    // 0x805562CC: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x805562D0: lw          $t8, 0x174($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X174);
L_805562D4:
    // 0x805562D4: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x805562D8: srl         $t9, $v0, 28
    ctx->r25 = S32(U32(ctx->r2) >> 28);
    // 0x805562DC: bnel        $t9, $zero, L_8055634C
    if (ctx->r25 != 0) {
        // 0x805562E0: andi        $t8, $v0, 0xF00
        ctx->r24 = ctx->r2 & 0XF00;
            goto L_8055634C;
    }
    goto skip_4;
    // 0x805562E0: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
    skip_4:
    // 0x805562E4: lw          $t0, 0x174($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X174);
    // 0x805562E8: swc1        $f0, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f0.u32l;
    // 0x805562EC: b           L_80556348
    // 0x805562F0: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
        goto L_80556348;
    // 0x805562F0: lw          $v0, 0x8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X8);
    // 0x805562F4: lw          $t1, 0x138($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X138);
L_805562F8:
    // 0x805562F8: beql        $t1, $zero, L_80556328
    if (ctx->r9 == 0) {
        // 0x805562FC: lw          $t5, 0x174($s3)
        ctx->r13 = MEM_W(ctx->r19, 0X174);
            goto L_80556328;
    }
    goto skip_5;
    // 0x805562FC: lw          $t5, 0x174($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X174);
    skip_5:
    // 0x80556300: lw          $t2, 0x174($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X174);
    // 0x80556304: lw          $v0, 0x8($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X8);
    // 0x80556308: srl         $t3, $v0, 28
    ctx->r11 = S32(U32(ctx->r2) >> 28);
    // 0x8055630C: bnel        $t3, $zero, L_8055634C
    if (ctx->r11 != 0) {
        // 0x80556310: andi        $t8, $v0, 0xF00
        ctx->r24 = ctx->r2 & 0XF00;
            goto L_8055634C;
    }
    goto skip_6;
    // 0x80556310: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
    skip_6:
    // 0x80556314: lw          $t4, 0x174($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X174);
    // 0x80556318: swc1        $f0, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f0.u32l;
    // 0x8055631C: b           L_80556348
    // 0x80556320: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
        goto L_80556348;
    // 0x80556320: lw          $v0, 0x8($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X8);
    // 0x80556324: lw          $t5, 0x174($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X174);
L_80556328:
    // 0x80556328: lui         $at, 0xF00
    ctx->r1 = S32(0XF00 << 16);
    // 0x8055632C: lw          $v0, 0x8($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X8);
    // 0x80556330: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80556334: bnel        $t6, $zero, L_8055634C
    if (ctx->r14 != 0) {
        // 0x80556338: andi        $t8, $v0, 0xF00
        ctx->r24 = ctx->r2 & 0XF00;
            goto L_8055634C;
    }
    goto skip_7;
    // 0x80556338: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
    skip_7:
    // 0x8055633C: lw          $t7, 0x174($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X174);
    // 0x80556340: swc1        $f0, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f0.u32l;
    // 0x80556344: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
L_80556348:
    // 0x80556348: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
L_8055634C:
    // 0x8055634C: bnel        $t8, $zero, L_80556370
    if (ctx->r24 != 0) {
        // 0x80556350: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80556370;
    }
    goto skip_8;
    // 0x80556350: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_8:
    // 0x80556354: lwc1        $f18, 0xE0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XE0);
    // 0x80556358: b           L_8055636C
    // 0x8055635C: swc1        $f18, 0x110($s3)
    MEM_W(0X110, ctx->r19) = ctx->f18.u32l;
        goto L_8055636C;
    // 0x8055635C: swc1        $f18, 0x110($s3)
    MEM_W(0X110, ctx->r19) = ctx->f18.u32l;
L_80556360:
    // 0x80556360: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80556364:
    // 0x80556364: bne         $s1, $s2, L_80556218
    if (ctx->r17 != ctx->r18) {
        // 0x80556368: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80556218;
    }
    // 0x80556368: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
L_8055636C:
    // 0x8055636C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80556370:
    // 0x80556370: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80556374: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80556378: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8055637C: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80556380: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80556384: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80556388: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8055638C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80556390: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80556394: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80556398: jr          $ra
    // 0x8055639C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8055639C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8002EE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EE54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002EE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002EE5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002EE60: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002EE64: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x8002EE68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002EE6C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002EE70: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8002EE74: jal         0x8002B9E4
    // 0x8002EE78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002EE78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002EE7C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002EE80: jal         0x8002ED94
    // 0x8002EE84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8002ED94(rdram, ctx);
        goto after_1;
    // 0x8002EE84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8002EE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EE8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002EE90: jr          $ra
    // 0x8002EE94: nop

    return;
    // 0x8002EE94: nop

;}
RECOMP_FUNC void func_804CFBB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CFBB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CFBBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CFBC0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804CFBC4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804CFBC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CFBCC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804CFBD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CFBD4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x804CFBD8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CFBDC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804CFBE0: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(240, 0X1AD8) << 16);
    // 0x804CFBE4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CFBE8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804CFBEC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804CFBF0: lw          $t2, -0x278($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(240, 0X1AD8));
    // 0x804CFBF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CFBF8: jal         0x804CF8D4
    // 0x804CFBFC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804CF8D4(rdram, ctx);
        goto after_0;
    // 0x804CFBFC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804CFC00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CFC04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CFC08: jr          $ra
    // 0x804CFC0C: nop

    return;
    // 0x804CFC0C: nop

;}
RECOMP_FUNC void func_804D2BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2BC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D2BC8: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(249, 0X4AC) << 16);
    // 0x804D2BCC: addiu       $v0, $v0, 0x2FBC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(249, 0X4AC));
    // 0x804D2BD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D2BD4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804D2BD8: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x804D2BDC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D2BE0: jalr        $t9
    // 0x804D2BE4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804D2BE4: nop

    after_0:
    // 0x804D2BE8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D2BEC: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x804D2BF0: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x804D2BF4: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x804D2BF8: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x804D2BFC: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x804D2C00: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x804D2C04: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x804D2C08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D2C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D2C10: jr          $ra
    // 0x804D2C14: nop

    return;
    // 0x804D2C14: nop

;}
RECOMP_FUNC void func_80071974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071974: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80071978: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8007197C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80071980: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80071984: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80071988: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8007198C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80071990: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80071994: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80071998: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007199C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800719A0: lui         $s7, 0x800B
    ctx->r23 = S32(0X800B << 16);
    // 0x800719A4: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x800719A8: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x800719AC: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x800719B0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800719B4: addiu       $s2, $s2, -0x5E50
    ctx->r18 = ADD32(ctx->r18, -0X5E50);
    // 0x800719B8: addiu       $s4, $s4, -0x5E08
    ctx->r20 = ADD32(ctx->r20, -0X5E08);
    // 0x800719BC: addiu       $s6, $s6, -0x7B20
    ctx->r22 = ADD32(ctx->r22, -0X7B20);
    // 0x800719C0: addiu       $s7, $s7, -0x7B78
    ctx->r23 = ADD32(ctx->r23, -0X7B78);
    // 0x800719C4: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
L_800719C8:
    // 0x800719C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800719CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800719D0: jal         0x800824B0
    // 0x800719D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800719D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800719D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800719DC: beq         $s1, $zero, L_80071AA8
    if (ctx->r17 == 0) {
        // 0x800719E0: nop
    
            goto L_80071AA8;
    }
    // 0x800719E0: nop

    // 0x800719E4: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x800719E8: bne         $t6, $zero, L_80071AA8
    if (ctx->r14 != 0) {
        // 0x800719EC: nop
    
            goto L_80071AA8;
    }
    // 0x800719EC: nop

    // 0x800719F0: sb          $zero, 0x15($s1)
    MEM_B(0X15, ctx->r17) = 0;
    // 0x800719F4: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x800719F8: beq         $t7, $zero, L_80071A10
    if (ctx->r15 == 0) {
        // 0x800719FC: nop
    
            goto L_80071A10;
    }
    // 0x800719FC: nop

    // 0x80071A00: jal         0x800867A0
    // 0x80071A04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_1;
    // 0x80071A04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80071A08: b           L_80071A18
    // 0x80071A0C: nop

        goto L_80071A18;
    // 0x80071A0C: nop

L_80071A10:
    // 0x80071A10: jal         0x800867A0
    // 0x80071A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x80071A14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_80071A18:
    // 0x80071A18: jal         0x8008B230
    // 0x80071A1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_3;
    // 0x80071A1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x80071A20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80071A24: lhu         $a1, 0xA($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XA);
    // 0x80071A28: jal         0x80071250
    // 0x80071A2C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    Fault_SetFramebuffer(rdram, ctx);
        goto after_4;
    // 0x80071A2C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_4:
    // 0x80071A30: jal         0x800914F0
    // 0x80071A34: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_5;
    // 0x80071A34: nop

    after_5:
    // 0x80071A38: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80071A3C: beq         $v0, $t8, L_80071A60
    if (ctx->r2 == ctx->r24) {
        // 0x80071A40: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80071A60;
    }
    // 0x80071A40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80071A44:
    // 0x80071A44: jal         0x800756A8
    // 0x80071A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800756A8(rdram, ctx);
        goto after_6;
    // 0x80071A48: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80071A4C: jal         0x800914F0
    // 0x80071A50: nop

    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_7;
    // 0x80071A50: nop

    after_7:
    // 0x80071A54: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80071A58: bnel        $v0, $t9, L_80071A44
    if (ctx->r2 != ctx->r25) {
        // 0x80071A5C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80071A44;
    }
    goto skip_0;
    // 0x80071A5C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_80071A60:
    // 0x80071A60: lbu         $t0, 0x15($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X15);
    // 0x80071A64: lbu         $s0, 0x14($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X14);
    // 0x80071A68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80071A6C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80071A70: slt         $at, $t2, $s0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80071A74: beq         $at, $zero, L_80071ABC
    if (ctx->r1 == 0) {
        // 0x80071A78: sb          $t1, 0x15($s1)
        MEM_B(0X15, ctx->r17) = ctx->r9;
            goto L_80071ABC;
    }
    // 0x80071A78: sb          $t1, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r9;
L_80071A7C:
    // 0x80071A7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80071A80: jal         0x800756A8
    // 0x80071A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800756A8(rdram, ctx);
        goto after_8;
    // 0x80071A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80071A88: lbu         $t3, 0x15($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X15);
    // 0x80071A8C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80071A90: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80071A94: slt         $at, $t5, $s0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80071A98: bne         $at, $zero, L_80071A7C
    if (ctx->r1 != 0) {
        // 0x80071A9C: sb          $t4, 0x15($s1)
        MEM_B(0X15, ctx->r17) = ctx->r12;
            goto L_80071A7C;
    }
    // 0x80071A9C: sb          $t4, 0x15($s1)
    MEM_B(0X15, ctx->r17) = ctx->r12;
    // 0x80071AA0: b           L_80071ABC
    // 0x80071AA4: nop

        goto L_80071ABC;
    // 0x80071AA4: nop

L_80071AA8:
    // 0x80071AA8: jal         0x800867A0
    // 0x80071AAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_9;
    // 0x80071AAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x80071AB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80071AB4: jal         0x800756A8
    // 0x80071AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800756A8(rdram, ctx);
        goto after_10;
    // 0x80071AB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
L_80071ABC:
    // 0x80071ABC: beq         $s3, $zero, L_80071ACC
    if (ctx->r19 == 0) {
        // 0x80071AC0: nop
    
            goto L_80071ACC;
    }
    // 0x80071AC0: nop

    // 0x80071AC4: jal         0x8007180C
    // 0x80071AC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8007180C(rdram, ctx);
        goto after_11;
    // 0x80071AC8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
L_80071ACC:
    // 0x80071ACC: b           L_800719C8
    // 0x80071AD0: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
        goto L_800719C8;
    // 0x80071AD0: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x80071AD4: nop

    // 0x80071AD8: nop

    // 0x80071ADC: nop

    // 0x80071AE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80071AE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80071AE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80071AEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80071AF0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80071AF4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80071AF8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80071AFC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80071B00: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80071B04: jr          $ra
    // 0x80071B08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80071B08: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A510: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8008A514: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008A518: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008A51C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008A520: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008A524: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008A528: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008A52C: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x8008A530: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x8008A534: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x8008A538: lui         $s7, 0x800B
    ctx->r23 = S32(0X800B << 16);
    // 0x8008A53C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8008A540: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8008A544: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8008A548: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008A54C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008A550: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008A554: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008A558: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8008A55C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x8008A560: addiu       $s7, $s7, -0x4630
    ctx->r23 = ADD32(ctx->r23, -0X4630);
    // 0x8008A564: addiu       $s6, $s6, 0x32F4
    ctx->r22 = ADD32(ctx->r22, 0X32F4);
    // 0x8008A568: addiu       $s5, $s5, -0x460C
    ctx->r21 = ADD32(ctx->r21, -0X460C);
    // 0x8008A56C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_8008A570:
    // 0x8008A570: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x8008A574: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x8008A578: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8008A57C: beq         $v0, $zero, L_8008A5A4
    if (ctx->r2 == 0) {
        // 0x8008A580: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8008A5A4;
    }
    // 0x8008A580: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008A584: beql        $v1, $v0, L_8008A5A8
    if (ctx->r3 == ctx->r2) {
        // 0x8008A588: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_8008A5A8;
    }
    goto skip_0;
    // 0x8008A588: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x8008A58C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_8008A590:
    // 0x8008A590: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A594: beq         $v0, $zero, L_8008A5A4
    if (ctx->r2 == 0) {
        // 0x8008A598: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8008A5A4;
    }
    // 0x8008A598: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8008A59C: bnel        $v1, $v0, L_8008A590
    if (ctx->r3 != ctx->r2) {
        // 0x8008A5A0: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_8008A590;
    }
    goto skip_1;
    // 0x8008A5A0: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_8008A5A4:
    // 0x8008A5A4: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_8008A5A8:
    // 0x8008A5A8: blez        $v0, L_8008A5E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A5AC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008A5E0;
    }
    // 0x8008A5AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A5B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8008A5B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008A5B8: jalr        $s4
    // 0x8008A5BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8008A5BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x8008A5C0: beq         $v0, $zero, L_8008A5D8
    if (ctx->r2 == 0) {
        // 0x8008A5C4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A5D8;
    }
    // 0x8008A5C4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A5C8: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A5CC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8008A5D0: b           L_8008A5E0
    // 0x8008A5D4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8008A5E0;
    // 0x8008A5D4: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8008A5D8:
    // 0x8008A5D8: b           L_8008AB28
    // 0x8008A5DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A5DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A5E0:
    // 0x8008A5E0: bne         $s0, $zero, L_8008A5F0
    if (ctx->r16 != 0) {
        // 0x8008A5E4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8008A5F0;
    }
    // 0x8008A5E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A5E8: b           L_8008AB28
    // 0x8008A5EC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A5EC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A5F0:
    // 0x8008A5F0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x8008A5F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A5F8: jal         0x8008ADD4
    // 0x8008A5FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x8008A5FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x8008A600: beq         $v0, $zero, L_8008A640
    if (ctx->r2 == 0) {
        // 0x8008A604: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8008A640;
    }
    // 0x8008A604: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8008A608:
    // 0x8008A608: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x8008A60C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8008A610: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8008A614: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8008A618: lw          $t7, 0x32FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X32FC);
    // 0x8008A61C: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8008A620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A624: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008A628: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8008A62C: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x8008A630: jal         0x8008ADD4
    // 0x8008A634: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x8008A634: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x8008A638: bne         $v0, $zero, L_8008A608
    if (ctx->r2 != 0) {
        // 0x8008A63C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8008A608;
    }
    // 0x8008A63C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8008A640:
    // 0x8008A640: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A644: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x8008A648: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8008A64C: bne         $v0, $t6, L_8008A694
    if (ctx->r2 != ctx->r14) {
        // 0x8008A650: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8008A694;
    }
    // 0x8008A650: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8008A654: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x8008A658: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A65C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x8008A660: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x8008A664: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x8008A668: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8008A66C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A670: bgez        $t8, L_8008A68C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008A674: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_8008A68C;
    }
    // 0x8008A674: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8008A678: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8008A67C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x8008A680: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x8008A684: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x8008A688: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_8008A68C:
    // 0x8008A68C: b           L_8008A6F0
    // 0x8008A690: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8008A6F0;
    // 0x8008A690: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8008A694:
    // 0x8008A694: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x8008A698: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A69C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8008A6A0: bne         $at, $zero, L_8008A6F0
    if (ctx->r1 != 0) {
        // 0x8008A6A4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8008A6F0;
    }
    // 0x8008A6A4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8008A6A8: beql        $at, $zero, L_8008A6F4
    if (ctx->r1 == 0) {
        // 0x8008A6AC: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8008A6F4;
    }
    goto skip_2;
    // 0x8008A6AC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x8008A6B0: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_8008A6B4:
    // 0x8008A6B4: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x8008A6B8: beql        $at, $zero, L_8008A6D8
    if (ctx->r1 == 0) {
        // 0x8008A6BC: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_8008A6D8;
    }
    goto skip_3;
    // 0x8008A6BC: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x8008A6C0: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A6C4: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A6C8: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x8008A6CC: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x8008A6D0: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x8008A6D4: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_8008A6D8:
    // 0x8008A6D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A6DC: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8008A6E0: bne         $at, $zero, L_8008A6F0
    if (ctx->r1 != 0) {
        // 0x8008A6E4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8008A6F0;
    }
    // 0x8008A6E4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8008A6E8: bnel        $at, $zero, L_8008A6B4
    if (ctx->r1 != 0) {
        // 0x8008A6EC: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_8008A6B4;
    }
    goto skip_4;
    // 0x8008A6EC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_8008A6F0:
    // 0x8008A6F0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_8008A6F4:
    // 0x8008A6F4: beq         $a1, $at, L_8008A708
    if (ctx->r5 == ctx->r1) {
        // 0x8008A6F8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8008A708;
    }
    // 0x8008A6F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8008A6FC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x8008A700: b           L_8008A79C
    // 0x8008A704: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8008A79C;
    // 0x8008A704: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8008A708:
    // 0x8008A708: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x8008A70C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8008A710: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A714: bne         $v0, $t7, L_8008A740
    if (ctx->r2 != ctx->r15) {
        // 0x8008A718: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_8008A740;
    }
    // 0x8008A718: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x8008A71C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8008A720: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x8008A724: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x8008A728: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8008A72C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8008A730: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A734: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x8008A738: b           L_8008A79C
    // 0x8008A73C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8008A79C;
    // 0x8008A73C: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_8008A740:
    // 0x8008A740: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x8008A744: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A748: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8008A74C: bne         $at, $zero, L_8008A79C
    if (ctx->r1 != 0) {
        // 0x8008A750: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8008A79C;
    }
    // 0x8008A750: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8008A754: beq         $at, $zero, L_8008A79C
    if (ctx->r1 == 0) {
        // 0x8008A758: nop
    
            goto L_8008A79C;
    }
    // 0x8008A758: nop

    // 0x8008A75C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_8008A760:
    // 0x8008A760: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x8008A764: beql        $at, $zero, L_8008A784
    if (ctx->r1 == 0) {
        // 0x8008A768: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_8008A784;
    }
    goto skip_5;
    // 0x8008A768: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x8008A76C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A770: mflo        $t7
    ctx->r15 = lo;
    // 0x8008A774: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8008A778: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8008A77C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x8008A780: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_8008A784:
    // 0x8008A784: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A788: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8008A78C: bne         $at, $zero, L_8008A79C
    if (ctx->r1 != 0) {
        // 0x8008A790: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8008A79C;
    }
    // 0x8008A790: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x8008A794: bnel        $at, $zero, L_8008A760
    if (ctx->r1 != 0) {
        // 0x8008A798: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_8008A760;
    }
    goto skip_6;
    // 0x8008A798: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_8008A79C:
    // 0x8008A79C: jal         0x8008ADD4
    // 0x8008A7A0: addiu       $a0, $a0, 0x32F0
    ctx->r4 = ADD32(ctx->r4, 0X32F0);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x8008A7A0: addiu       $a0, $a0, 0x32F0
    ctx->r4 = ADD32(ctx->r4, 0X32F0);
    after_3:
    // 0x8008A7A4: beq         $v0, $zero, L_8008A7BC
    if (ctx->r2 == 0) {
        // 0x8008A7A8: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_8008A7BC;
    }
    // 0x8008A7A8: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x8008A7AC: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A7B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008A7B4: b           L_8008A7C0
    // 0x8008A7B8: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_8008A7C0;
    // 0x8008A7B8: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_8008A7BC:
    // 0x8008A7BC: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_8008A7C0:
    // 0x8008A7C0: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x8008A7C4: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x8008A7C8: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8008A7CC: bne         $v0, $t7, L_8008A7EC
    if (ctx->r2 != ctx->r15) {
        // 0x8008A7D0: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_8008A7EC;
    }
    // 0x8008A7D0: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x8008A7D4: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x8008A7D8: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8008A7DC: bne         $v0, $t8, L_8008A7EC
    if (ctx->r2 != ctx->r24) {
        // 0x8008A7E0: nop
    
            goto L_8008A7EC;
    }
    // 0x8008A7E0: nop

    // 0x8008A7E4: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x8008A7E8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8008A7EC:
    // 0x8008A7EC: jal         0x80089EA0
    // 0x8008A7F0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    static_4_80089EA0(rdram, ctx);
        goto after_4;
    // 0x8008A7F0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x8008A7F4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x8008A7F8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8008A7FC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x8008A800: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A804: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8008A808: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8008A80C: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x8008A810: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A814: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8008A818: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8008A81C: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x8008A820: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x8008A824: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x8008A828: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x8008A82C: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x8008A830: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x8008A834: bne         $t8, $zero, L_8008A8A0
    if (ctx->r24 != 0) {
        // 0x8008A838: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_8008A8A0;
    }
    // 0x8008A838: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008A83C: beql        $t6, $zero, L_8008A8A4
    if (ctx->r14 == 0) {
        // 0x8008A840: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8008A8A4;
    }
    goto skip_7;
    // 0x8008A840: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x8008A844: beq         $t6, $zero, L_8008A8A0
    if (ctx->r14 == 0) {
        // 0x8008A848: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008A8A0;
    }
    // 0x8008A848: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008A84C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8008A850:
    // 0x8008A850: bne         $at, $zero, L_8008A860
    if (ctx->r1 != 0) {
        // 0x8008A854: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8008A860;
    }
    // 0x8008A854: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8008A858: b           L_8008A860
    // 0x8008A85C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8008A860;
    // 0x8008A85C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8008A860:
    // 0x8008A860: blez        $s0, L_8008A894
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008A864: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008A894;
    }
    // 0x8008A864: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A868: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8008A86C: jalr        $s4
    // 0x8008A870: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x8008A870: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8008A874: beq         $v0, $zero, L_8008A88C
    if (ctx->r2 == 0) {
        // 0x8008A878: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A88C;
    }
    // 0x8008A878: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A87C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A880: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8008A884: b           L_8008A894
    // 0x8008A888: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008A894;
    // 0x8008A888: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008A88C:
    // 0x8008A88C: b           L_8008AB28
    // 0x8008A890: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A890: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A894:
    // 0x8008A894: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8008A898: bgtzl       $s1, L_8008A850
    if (SIGNED(ctx->r17) > 0) {
        // 0x8008A89C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8008A850;
    }
    goto skip_8;
    // 0x8008A89C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_8008A8A0:
    // 0x8008A8A0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_8008A8A4:
    // 0x8008A8A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A8A8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8008A8AC: blezl       $t9, L_8008A8E4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008A8B0: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_8008A8E4;
    }
    goto skip_9;
    // 0x8008A8B0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x8008A8B4: jalr        $s4
    // 0x8008A8B8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x8008A8B8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x8008A8BC: beq         $v0, $zero, L_8008A8D8
    if (ctx->r2 == 0) {
        // 0x8008A8C0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A8D8;
    }
    // 0x8008A8C0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A8C4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A8C8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8008A8CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008A8D0: b           L_8008A8E0
    // 0x8008A8D4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008A8E0;
    // 0x8008A8D4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008A8D8:
    // 0x8008A8D8: b           L_8008AB28
    // 0x8008A8DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A8DC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A8E0:
    // 0x8008A8E0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_8008A8E4:
    // 0x8008A8E4: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008A8E8: beql        $t6, $zero, L_8008A950
    if (ctx->r14 == 0) {
        // 0x8008A8EC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_8008A950;
    }
    goto skip_10;
    // 0x8008A8EC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x8008A8F0: beq         $t6, $zero, L_8008A94C
    if (ctx->r14 == 0) {
        // 0x8008A8F4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008A94C;
    }
    // 0x8008A8F4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008A8F8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8008A8FC:
    // 0x8008A8FC: bne         $at, $zero, L_8008A90C
    if (ctx->r1 != 0) {
        // 0x8008A900: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8008A90C;
    }
    // 0x8008A900: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8008A904: b           L_8008A90C
    // 0x8008A908: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8008A90C;
    // 0x8008A908: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8008A90C:
    // 0x8008A90C: blez        $s0, L_8008A940
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008A910: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008A940;
    }
    // 0x8008A910: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A914: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8008A918: jalr        $s4
    // 0x8008A91C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x8008A91C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8008A920: beq         $v0, $zero, L_8008A938
    if (ctx->r2 == 0) {
        // 0x8008A924: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A938;
    }
    // 0x8008A924: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A928: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A92C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8008A930: b           L_8008A940
    // 0x8008A934: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008A940;
    // 0x8008A934: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008A938:
    // 0x8008A938: b           L_8008AB28
    // 0x8008A93C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A93C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A940:
    // 0x8008A940: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8008A944: bgtzl       $s1, L_8008A8FC
    if (SIGNED(ctx->r17) > 0) {
        // 0x8008A948: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8008A8FC;
    }
    goto skip_11;
    // 0x8008A948: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_8008A94C:
    // 0x8008A94C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_8008A950:
    // 0x8008A950: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A954: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8008A958: blezl       $t9, L_8008A990
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008A95C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_8008A990;
    }
    goto skip_12;
    // 0x8008A95C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x8008A960: jalr        $s4
    // 0x8008A964: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x8008A964: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x8008A968: beq         $v0, $zero, L_8008A984
    if (ctx->r2 == 0) {
        // 0x8008A96C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A984;
    }
    // 0x8008A96C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A970: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A974: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8008A978: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8008A97C: b           L_8008A98C
    // 0x8008A980: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008A98C;
    // 0x8008A980: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008A984:
    // 0x8008A984: b           L_8008AB28
    // 0x8008A988: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A988: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A98C:
    // 0x8008A98C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_8008A990:
    // 0x8008A990: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008A994: beql        $t6, $zero, L_8008A9FC
    if (ctx->r14 == 0) {
        // 0x8008A998: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_8008A9FC;
    }
    goto skip_13;
    // 0x8008A998: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x8008A99C: beq         $t6, $zero, L_8008A9F8
    if (ctx->r14 == 0) {
        // 0x8008A9A0: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008A9F8;
    }
    // 0x8008A9A0: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008A9A4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8008A9A8:
    // 0x8008A9A8: bne         $at, $zero, L_8008A9B8
    if (ctx->r1 != 0) {
        // 0x8008A9AC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8008A9B8;
    }
    // 0x8008A9AC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8008A9B0: b           L_8008A9B8
    // 0x8008A9B4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8008A9B8;
    // 0x8008A9B4: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8008A9B8:
    // 0x8008A9B8: blez        $s0, L_8008A9EC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008A9BC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008A9EC;
    }
    // 0x8008A9BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008A9C0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8008A9C4: jalr        $s4
    // 0x8008A9C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x8008A9C8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x8008A9CC: beq         $v0, $zero, L_8008A9E4
    if (ctx->r2 == 0) {
        // 0x8008A9D0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008A9E4;
    }
    // 0x8008A9D0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008A9D4: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x8008A9D8: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8008A9DC: b           L_8008A9EC
    // 0x8008A9E0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008A9EC;
    // 0x8008A9E0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008A9E4:
    // 0x8008A9E4: b           L_8008AB28
    // 0x8008A9E8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008A9E8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008A9EC:
    // 0x8008A9EC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8008A9F0: bgtzl       $s1, L_8008A9A8
    if (SIGNED(ctx->r17) > 0) {
        // 0x8008A9F4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8008A9A8;
    }
    goto skip_14;
    // 0x8008A9F4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_8008A9F8:
    // 0x8008A9F8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_8008A9FC:
    // 0x8008A9FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008AA00: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x8008AA04: blez        $t9, L_8008AA3C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8008AA08: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_8008AA3C;
    }
    // 0x8008AA08: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8008AA0C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8008AA10: jalr        $s4
    // 0x8008AA14: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x8008AA14: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x8008AA18: beq         $v0, $zero, L_8008AA34
    if (ctx->r2 == 0) {
        // 0x8008AA1C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008AA34;
    }
    // 0x8008AA1C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008AA20: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x8008AA24: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8008AA28: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8008AA2C: b           L_8008AA3C
    // 0x8008AA30: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8008AA3C;
    // 0x8008AA30: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8008AA34:
    // 0x8008AA34: b           L_8008AB28
    // 0x8008AA38: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008AA38: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008AA3C:
    // 0x8008AA3C: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x8008AA40: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8008AA44: beql        $t8, $zero, L_8008AAAC
    if (ctx->r24 == 0) {
        // 0x8008AA48: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_8008AAAC;
    }
    goto skip_15;
    // 0x8008AA48: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x8008AA4C: beq         $t8, $zero, L_8008AAA8
    if (ctx->r24 == 0) {
        // 0x8008AA50: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8008AAA8;
    }
    // 0x8008AA50: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8008AA54: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8008AA58:
    // 0x8008AA58: bne         $at, $zero, L_8008AA68
    if (ctx->r1 != 0) {
        // 0x8008AA5C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8008AA68;
    }
    // 0x8008AA5C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8008AA60: b           L_8008AA68
    // 0x8008AA64: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8008AA68;
    // 0x8008AA64: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8008AA68:
    // 0x8008AA68: blez        $s0, L_8008AA9C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008AA6C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008AA9C;
    }
    // 0x8008AA6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008AA70: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8008AA74: jalr        $s4
    // 0x8008AA78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x8008AA78: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8008AA7C: beq         $v0, $zero, L_8008AA94
    if (ctx->r2 == 0) {
        // 0x8008AA80: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008AA94;
    }
    // 0x8008AA80: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008AA84: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8008AA88: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8008AA8C: b           L_8008AA9C
    // 0x8008AA90: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8008AA9C;
    // 0x8008AA90: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_8008AA94:
    // 0x8008AA94: b           L_8008AB28
    // 0x8008AA98: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008AA98: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008AA9C:
    // 0x8008AA9C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8008AAA0: bgtzl       $s1, L_8008AA58
    if (SIGNED(ctx->r17) > 0) {
        // 0x8008AAA4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8008AA58;
    }
    goto skip_16;
    // 0x8008AAA4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_8008AAA8:
    // 0x8008AAA8: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_8008AAAC:
    // 0x8008AAAC: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8008AAB0: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x8008AAB4: beq         $t8, $zero, L_8008AB20
    if (ctx->r24 == 0) {
        // 0x8008AAB8: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_8008AB20;
    }
    // 0x8008AAB8: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8008AABC: beq         $t7, $zero, L_8008AB20
    if (ctx->r15 == 0) {
        // 0x8008AAC0: nop
    
            goto L_8008AB20;
    }
    // 0x8008AAC0: nop

    // 0x8008AAC4: beq         $t7, $zero, L_8008AB20
    if (ctx->r15 == 0) {
        // 0x8008AAC8: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_8008AB20;
    }
    // 0x8008AAC8: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8008AACC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_8008AAD0:
    // 0x8008AAD0: bne         $at, $zero, L_8008AAE0
    if (ctx->r1 != 0) {
        // 0x8008AAD4: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8008AAE0;
    }
    // 0x8008AAD4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8008AAD8: b           L_8008AAE0
    // 0x8008AADC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_8008AAE0;
    // 0x8008AADC: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_8008AAE0:
    // 0x8008AAE0: blez        $s0, L_8008AB14
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008AAE4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008AB14;
    }
    // 0x8008AAE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008AAE8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8008AAEC: jalr        $s4
    // 0x8008AAF0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x8008AAF0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x8008AAF4: beq         $v0, $zero, L_8008AB0C
    if (ctx->r2 == 0) {
        // 0x8008AAF8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8008AB0C;
    }
    // 0x8008AAF8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8008AAFC: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x8008AB00: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x8008AB04: b           L_8008AB14
    // 0x8008AB08: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8008AB14;
    // 0x8008AB08: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8008AB0C:
    // 0x8008AB0C: b           L_8008AB28
    // 0x8008AB10: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_8008AB28;
    // 0x8008AB10: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8008AB14:
    // 0x8008AB14: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x8008AB18: bgtzl       $s1, L_8008AAD0
    if (SIGNED(ctx->r17) > 0) {
        // 0x8008AB1C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_8008AAD0;
    }
    goto skip_17;
    // 0x8008AB1C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_8008AB20:
    // 0x8008AB20: b           L_8008A570
    // 0x8008AB24: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_8008A570;
    // 0x8008AB24: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_8008AB28:
    // 0x8008AB28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008AB2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AB30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AB34: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008AB38: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008AB3C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008AB40: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AB44: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008AB48: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008AB4C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008AB50: jr          $ra
    // 0x8008AB54: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8008AB54: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8064A4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064A4B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064A4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064A4B8: jal         0x8004700C
    // 0x8064A4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064A4BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064A4C0: beq         $v0, $zero, L_8064A520
    if (ctx->r2 == 0) {
        // 0x8064A4C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064A520;
    }
    // 0x8064A4C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064A4C8: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064A4CC: blez        $v1, L_8064A4DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8064A4D0: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8064A4DC;
    }
    // 0x8064A4D0: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8064A4D4: b           L_8064A520
    // 0x8064A4D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064A520;
    // 0x8064A4D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064A4DC:
    // 0x8064A4DC: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064A4E0: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064A4E4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064A4E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064A4EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064A4F0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8064A4F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064A4F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064A4FC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064A500: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064A504: nop

    // 0x8064A508: bc1fl       L_8064A524
    if (!c1cs) {
        // 0x8064A50C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064A524;
    }
    goto skip_0;
    // 0x8064A50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064A510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064A514: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8064A518: jal         0x8064A97C
    // 0x8064A51C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    func_8064A97C(rdram, ctx);
        goto after_1;
    // 0x8064A51C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064A520:
    // 0x8064A520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064A524:
    // 0x8064A524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064A528: jr          $ra
    // 0x8064A52C: nop

    return;
    // 0x8064A52C: nop

;}
RECOMP_FUNC void func_80007490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007490: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80007494: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80007498: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000749C: lw          $t7, 0x6A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A88);
    // 0x800074A0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x800074A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800074A8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800074AC: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800074B0: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800074B4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800074B8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800074BC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800074C0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800074C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800074C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800074CC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x800074D0: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800074D4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800074D8: lbu         $s5, 0x1($v0)
    ctx->r21 = MEM_BU(ctx->r2, 0X1);
    // 0x800074DC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800074E0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800074E4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800074E8: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800074EC: beql        $v1, $zero, L_80007564
    if (ctx->r3 == 0) {
        // 0x800074F0: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_80007564;
    }
    goto skip_0;
    // 0x800074F0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x800074F4: beq         $s5, $zero, L_80007560
    if (ctx->r21 == 0) {
        // 0x800074F8: addu        $t0, $v1, $a1
        ctx->r8 = ADD32(ctx->r3, ctx->r5);
            goto L_80007560;
    }
    // 0x800074F8: addu        $t0, $v1, $a1
    ctx->r8 = ADD32(ctx->r3, ctx->r5);
    // 0x800074FC: blez        $s5, L_80007560
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80007500: sw          $t0, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r8;
            goto L_80007560;
    }
    // 0x80007500: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80007504: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80007508: sll         $s6, $s5, 2
    ctx->r22 = S32(ctx->r21 << 2);
    // 0x8000750C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80007510: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_80007514:
    // 0x80007514: addu        $v0, $t1, $s3
    ctx->r2 = ADD32(ctx->r9, ctx->r19);
    // 0x80007518: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8000751C: beq         $s0, $zero, L_80007554
    if (ctx->r16 == 0) {
        // 0x80007520: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_80007554;
    }
    // 0x80007520: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x80007524: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x80007528: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x8000752C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80007530: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80007534: bne         $t2, $zero, L_80007554
    if (ctx->r10 != 0) {
        // 0x80007538: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80007554;
    }
    // 0x80007538: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000753C: jal         0x80008AFC
    // 0x80007540: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80008AFC(rdram, ctx);
        goto after_0;
    // 0x80007540: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_0:
    // 0x80007544: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x80007548: sb          $s7, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r23;
    // 0x8000754C: addu        $t3, $s0, $s2
    ctx->r11 = ADD32(ctx->r16, ctx->r18);
    // 0x80007550: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
L_80007554:
    // 0x80007554: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007558: bnel        $s3, $s6, L_80007514
    if (ctx->r19 != ctx->r22) {
        // 0x8000755C: lw          $t1, 0x0($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X0);
            goto L_80007514;
    }
    goto skip_1;
    // 0x8000755C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80007560:
    // 0x80007560: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_80007564:
    // 0x80007564: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80007568: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x8000756C: slti        $at, $t4, 0x80
    ctx->r1 = SIGNED(ctx->r12) < 0X80 ? 1 : 0;
    // 0x80007570: bne         $at, $zero, L_8000757C
    if (ctx->r1 != 0) {
        // 0x80007574: addiu       $s3, $s2, 0x4
        ctx->r19 = ADD32(ctx->r18, 0X4);
            goto L_8000757C;
    }
    // 0x80007574: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80007578: sw          $t5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r13;
L_8000757C:
    // 0x8000757C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80007580: addiu       $s6, $zero, 0x7F
    ctx->r22 = ADD32(0, 0X7F);
    // 0x80007584: blez        $t6, L_80007618
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80007588: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_80007618;
    }
    // 0x80007588: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000758C: addu        $s5, $t7, $s2
    ctx->r21 = ADD32(ctx->r15, ctx->r18);
    // 0x80007590: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80007594: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80007598:
    // 0x80007598: beq         $v0, $zero, L_8000760C
    if (ctx->r2 == 0) {
        // 0x8000759C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_8000760C;
    }
    // 0x8000759C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    // 0x800075A0: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800075A4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800075A8: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x800075AC: bnel        $t9, $zero, L_80007610
    if (ctx->r25 != 0) {
        // 0x800075B0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80007610;
    }
    goto skip_2;
    // 0x800075B0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    skip_2:
    // 0x800075B4: lbu         $t0, 0x1($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X1);
    // 0x800075B8: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800075BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800075C0: beql        $t0, $zero, L_800075D4
    if (ctx->r8 == 0) {
        // 0x800075C4: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_800075D4;
    }
    goto skip_3;
    // 0x800075C4: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    skip_3:
    // 0x800075C8: jal         0x80008AFC
    // 0x800075CC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80008AFC(rdram, ctx);
        goto after_1;
    // 0x800075CC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
    // 0x800075D0: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
L_800075D4:
    // 0x800075D4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800075D8: jal         0x80008AFC
    // 0x800075DC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80008AFC(rdram, ctx);
        goto after_2;
    // 0x800075DC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_2:
    // 0x800075E0: lbu         $t1, 0x2($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X2);
    // 0x800075E4: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x800075E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800075EC: beql        $s6, $t1, L_80007600
    if (ctx->r22 == ctx->r9) {
        // 0x800075F0: lw          $s0, 0x4($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X4);
            goto L_80007600;
    }
    goto skip_4;
    // 0x800075F0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    skip_4:
    // 0x800075F4: jal         0x80008AFC
    // 0x800075F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    func_80008AFC(rdram, ctx);
        goto after_3;
    // 0x800075F8: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_3:
    // 0x800075FC: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
L_80007600:
    // 0x80007600: sb          $s7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r23;
    // 0x80007604: addu        $t2, $s0, $s2
    ctx->r10 = ADD32(ctx->r16, ctx->r18);
    // 0x80007608: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
L_8000760C:
    // 0x8000760C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80007610:
    // 0x80007610: bnel        $s5, $s3, L_80007598
    if (ctx->r21 != ctx->r19) {
        // 0x80007614: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80007598;
    }
    goto skip_5;
    // 0x80007614: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_5:
L_80007618:
    // 0x80007618: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x8000761C: lw          $t4, 0x6A88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A88);
    // 0x80007620: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80007624: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80007628: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8000762C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80007630: sw          $t3, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r11;
    // 0x80007634: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80007638: lw          $t8, 0x6A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A88);
    // 0x8000763C: addiu       $t7, $s2, 0x4
    ctx->r15 = ADD32(ctx->r18, 0X4);
    // 0x80007640: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80007644: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x80007648: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000764C: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80007650: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80007654: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80007658: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000765C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80007660: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80007664: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80007668: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000766C: jr          $ra
    // 0x80007670: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80007670: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8053346C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053346C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80533470: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533474: jal         0x805331DC
    // 0x80533478: nop

    func_805331DC(rdram, ctx);
        goto after_0;
    // 0x80533478: nop

    after_0:
    // 0x8053347C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533480: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533484: jr          $ra
    // 0x80533488: nop

    return;
    // 0x80533488: nop

;}
RECOMP_FUNC void func_807B0264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B0268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B026C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x807B0270: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x807B0274: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807B0278: lui         $t8, 0x807B
    ctx->r24 = S32(RELOC_HI16(871, 0X3650) << 16);
    // 0x807B027C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807B0280: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x807B0284: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x807B0288: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807B028C: lw          $t8, 0x31A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(871, 0X3650));
    // 0x807B0290: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x807B0294: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807B0298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B029C: jal         0x80048490
    // 0x807B02A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x807B02A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x807B02A4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x807B02A8: jal         0x80048378
    // 0x807B02AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x807B02AC: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x807B02B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B02B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B02B8: jr          $ra
    // 0x807B02BC: nop

    return;
    // 0x807B02BC: nop

;}
RECOMP_FUNC void func_80526B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526B14: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80526B18: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80526B1C: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80526B20: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80526B24: jal         0x80067BBC
    // 0x80526B28: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80526B28: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80526B2C: addiu       $a0, $zero, 0x9C
    ctx->r4 = ADD32(0, 0X9C);
    // 0x80526B30: jal         0x80067818
    // 0x80526B34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80526B34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80526B38: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80526B3C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6148) << 16);
    // 0x80526B40: lwc1        $f4, -0x3FB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6148));
    // 0x80526B44: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80526B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80526B4C: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(327, 0X2AE4) << 16);
    // 0x80526B50: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X2B38) << 16);
    // 0x80526B54: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(327, 0XC98) << 16);
    // 0x80526B58: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80526B5C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80526B60: addiu       $t8, $t8, -0x761C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(327, 0X2AE4));
    // 0x80526B64: addiu       $t9, $t9, -0x75C8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(327, 0X2B38));
    // 0x80526B68: addiu       $t0, $t0, 0x6B98
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(327, 0XC98));
    // 0x80526B6C: sw          $t6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r14;
    // 0x80526B70: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x80526B74: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80526B78: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80526B7C: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x80526B80: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80526B84: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80526B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526B90: jr          $ra
    // 0x80526B94: nop

    return;
    // 0x80526B94: nop

;}
RECOMP_FUNC void func_80681334(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681334: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80681338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8068133C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80681340: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80681344: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80681348: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x8068134C: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x80681350: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80681354: lw          $t9, 0x168($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X168);
    // 0x80681358: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x8068135C: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x80681360: lw          $a3, 0x88($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X88);
    // 0x80681364: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x80681368: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8068136C: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x80681370: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80681374: ori         $t5, $t5, 0xAC80
    ctx->r13 = ctx->r13 | 0XAC80;
    // 0x80681378: ori         $t4, $t4, 0x18
    ctx->r12 = ctx->r12 | 0X18;
    // 0x8068137C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80681380: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x80681384: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    // 0x80681388: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8068138C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80681390: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80681394: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x80681398: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8068139C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x806813A0: ori         $a1, $a1, 0x3008
    ctx->r5 = ctx->r5 | 0X3008;
    // 0x806813A4: ori         $t9, $t9, 0x3
    ctx->r25 = ctx->r25 | 0X3;
    // 0x806813A8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806813AC: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x806813B0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x806813B4: lui         $t1, 0xB900
    ctx->r9 = S32(0XB900 << 16);
    // 0x806813B8: ori         $t1, $t1, 0x31D
    ctx->r9 = ctx->r9 | 0X31D;
    // 0x806813BC: addiu       $t0, $t7, 0x8
    ctx->r8 = ADD32(ctx->r15, 0X8);
    // 0x806813C0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x806813C4: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x806813C8: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x806813CC: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x806813D0: lui         $t4, 0xFCFF
    ctx->r12 = S32(0XFCFF << 16);
    // 0x806813D4: lui         $t5, 0xFFFC
    ctx->r13 = S32(0XFFFC << 16);
    // 0x806813D8: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x806813DC: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x806813E0: ori         $t5, $t5, 0xF279
    ctx->r13 = ctx->r13 | 0XF279;
    // 0x806813E4: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x806813E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806813EC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x806813F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806813F4: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x806813F8: jal         0x8007711C
    // 0x806813FC: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x806813FC: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
    after_0:
    // 0x80681400: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80681404: jal         0x806810CC
    // 0x80681408: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_806810CC(rdram, ctx);
        goto after_1;
    // 0x80681408: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x8068140C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80681410: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80681414: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x80681418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8068141C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80681420: jr          $ra
    // 0x80681424: nop

    return;
    // 0x80681424: nop

;}
RECOMP_FUNC void func_8046A744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A744: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046A748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046A74C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046A754: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2968) << 16);
    // 0x8046A758: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8046A75C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8046A760: nop

    // 0x8046A764: bc1f        L_8046A7A8
    if (!c1cs) {
        // 0x8046A768: nop
    
            goto L_8046A7A8;
    }
    // 0x8046A768: nop

    // 0x8046A76C: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2960) << 16);
    // 0x8046A770: lwc1        $f2, -0x3F60($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2960));
    // 0x8046A774: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2964) << 16);
    // 0x8046A778: lwc1        $f10, -0x3F5C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2964));
    // 0x8046A77C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A780: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8046A784: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x8046A788: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A78C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8046A790: nop

    // 0x8046A794: bc1fl       L_8046A7E0
    if (!c1cs) {
        // 0x8046A798: lwc1        $f8, 0x14($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8046A7E0;
    }
    goto skip_0;
    // 0x8046A798: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    skip_0:
    // 0x8046A79C: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8046A7A0: b           L_8046A7DC
    // 0x8046A7A4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
        goto L_8046A7DC;
    // 0x8046A7A4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
L_8046A7A8:
    // 0x8046A7A8: lwc1        $f2, -0x3F58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2968));
    // 0x8046A7AC: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X296C) << 16);
    // 0x8046A7B0: lwc1        $f4, -0x3F54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X296C));
    // 0x8046A7B4: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A7B8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8046A7BC: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8046A7C0: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A7C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8046A7C8: nop

    // 0x8046A7CC: bc1fl       L_8046A7E0
    if (!c1cs) {
        // 0x8046A7D0: lwc1        $f8, 0x14($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
            goto L_8046A7E0;
    }
    goto skip_1;
    // 0x8046A7D0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    skip_1:
    // 0x8046A7D4: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8046A7D8: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
L_8046A7DC:
    // 0x8046A7DC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
L_8046A7E0:
    // 0x8046A7E0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8046A7E4: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8046A7E8: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8046A7EC: jal         0x804697D8
    // 0x8046A7F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046A7F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046A7F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A7F8: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8046A7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046A800: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046A804: jr          $ra
    // 0x8046A808: nop

    return;
    // 0x8046A808: nop

;}
RECOMP_FUNC void func_800308D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800308D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800308D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800308D8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800308DC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800308E0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800308E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800308E8: jal         0x80042880
    // 0x800308EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80042880(rdram, ctx);
        goto after_0;
    // 0x800308EC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800308F0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800308F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800308F8: lwc1        $f2, -0x28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X28);
    // 0x800308FC: lwc1        $f0, 0x12D8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X12D8);
    // 0x80030900: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80030904: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80030908: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8003090C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030910: bc1f        L_80030924
    if (!c1cs) {
        // 0x80030914: nop
    
            goto L_80030924;
    }
    // 0x80030914: nop

    // 0x80030918: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003091C: b           L_80030934
    // 0x80030920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80030934;
    // 0x80030920: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030924:
    // 0x80030924: lwc1        $f4, -0x24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X24);
    // 0x80030928: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003092C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030930: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
L_80030934:
    // 0x80030934: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030938: lwc1        $f12, -0x20($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X20);
    // 0x8003093C: swc1        $f0, 0x12D8($a1)
    MEM_W(0X12D8, ctx->r5) = ctx->f0.u32l;
    // 0x80030940: lwc1        $f2, 0x70($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80030944: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030948: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8003094C: nop

    // 0x80030950: bc1f        L_80030964
    if (!c1cs) {
        // 0x80030954: nop
    
            goto L_80030964;
    }
    // 0x80030954: nop

    // 0x80030958: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8003095C: b           L_80030974
    // 0x80030960: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
        goto L_80030974;
    // 0x80030960: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80030964:
    // 0x80030964: lwc1        $f10, -0x1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1C);
    // 0x80030968: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003096C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80030970: sub.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f18.fl;
L_80030974:
    // 0x80030974: bne         $v0, $zero, L_800309A8
    if (ctx->r2 != 0) {
        // 0x80030978: swc1        $f2, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
            goto L_800309A8;
    }
    // 0x80030978: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x8003097C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80030980: jal         0x8002AF54
    // 0x80030984: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8002AF54(rdram, ctx);
        goto after_1;
    // 0x80030984: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80030988: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003098C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80030990: lw          $t6, 0x1A4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1A4);
    // 0x80030994: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80030998: bne         $t7, $zero, L_800309A8
    if (ctx->r15 != 0) {
        // 0x8003099C: sw          $t7, 0x1A4($a1)
        MEM_W(0X1A4, ctx->r5) = ctx->r15;
            goto L_800309A8;
    }
    // 0x8003099C: sw          $t7, 0x1A4($a1)
    MEM_W(0X1A4, ctx->r5) = ctx->r15;
    // 0x800309A0: jal         0x8002E7C8
    // 0x800309A4: nop

    func_8002E7C8(rdram, ctx);
        goto after_2;
    // 0x800309A4: nop

    after_2:
L_800309A8:
    // 0x800309A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800309AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800309B0: jr          $ra
    // 0x800309B4: nop

    return;
    // 0x800309B4: nop

;}
RECOMP_FUNC void func_804C4C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4C18: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804C4C1C: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(209, 0X99C) << 16);
    // 0x804C4C20: addiu       $t6, $t6, 0x498C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(209, 0X99C));
    // 0x804C4C24: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804C4C28: jr          $ra
    // 0x804C4C2C: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x804C4C2C: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_800489BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800489BC: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x800489C0: lbu         $t7, 0x7EA5($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7EA5);
    // 0x800489C4: lbu         $t6, 0x10($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X10);
    // 0x800489C8: jr          $ra
    // 0x800489CC: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    return;
    // 0x800489CC: slt         $v0, $t6, $t7
    ctx->r2 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
;}
RECOMP_FUNC void func_804383DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804383DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804383E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804383E4: jal         0x8004700C
    // 0x804383E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804383E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x804383EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804383F0: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x804383F4: jal         0x80045A34
    // 0x804383F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804383F8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x804383FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80438400: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80438404: bne         $v0, $zero, L_80438414
    if (ctx->r2 != 0) {
        // 0x80438408: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80438414;
    }
    // 0x80438408: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8043840C: b           L_80438510
    // 0x80438410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80438510;
    // 0x80438410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80438414:
    // 0x80438414: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80438418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8043841C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F8C) << 16);
    // 0x80438420: lwc1        $f2, -0x77D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F8C));
    // 0x80438424: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F90) << 16);
    // 0x80438428: lwc1        $f12, -0x77D0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F90));
    // 0x8043842C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80438430: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80438434: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F94) << 16);
    // 0x80438438: lwc1        $f14, -0x77CC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F94));
    // 0x8043843C: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x80438440: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80438444: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80438448: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043844C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F98) << 16);
    // 0x80438450: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80438454: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80438458: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8043845C: lwc1        $f16, -0x77C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F98));
    // 0x80438460: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F9C) << 16);
    // 0x80438464: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    // 0x80438468: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8043846C: lwc1        $f18, -0x77C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F9C));
    // 0x80438470: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1FA0) << 16);
    // 0x80438474: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x80438478: lwc1        $f4, -0x77C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1FA0));
    // 0x8043847C: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1FA4) << 16);
    // 0x80438480: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x80438484: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80438488: swc1        $f12, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f12.u32l;
    // 0x8043848C: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80438490: lwc1        $f6, -0x77BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1FA4));
    // 0x80438494: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80438498: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043849C: swc1        $f12, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f12.u32l;
    // 0x804384A0: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x804384A4: swc1        $f14, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f14.u32l;
    // 0x804384A8: swc1        $f6, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f6.u32l;
    // 0x804384AC: beq         $a2, $zero, L_804384E8
    if (ctx->r6 == 0) {
        // 0x804384B0: swc1        $f8, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
            goto L_804384E8;
    }
    // 0x804384B0: swc1        $f8, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f8.u32l;
    // 0x804384B4: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804384B8: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x804384BC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804384C0: swc1        $f18, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f18.u32l;
    // 0x804384C4: lwc1        $f6, 0x40($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X40);
    // 0x804384C8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804384CC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804384D0: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x804384D4: lwc1        $f16, 0x44($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X44);
    // 0x804384D8: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x804384DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804384E0: b           L_804384F8
    // 0x804384E4: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
        goto L_804384F8;
    // 0x804384E4: swc1        $f18, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f18.u32l;
L_804384E8:
    // 0x804384E8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804384EC: swc1        $f0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f0.u32l;
    // 0x804384F0: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x804384F4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
L_804384F8:
    // 0x804384F8: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1FA8) << 16);
    // 0x804384FC: lwc1        $f4, -0x77B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1FA8));
    // 0x80438500: swc1        $f2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f2.u32l;
    // 0x80438504: swc1        $f2, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f2.u32l;
    // 0x80438508: swc1        $f14, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f14.u32l;
    // 0x8043850C: swc1        $f4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f4.u32l;
L_80438510:
    // 0x80438510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80438514: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80438518: jr          $ra
    // 0x8043851C: nop

    return;
    // 0x8043851C: nop

;}
RECOMP_FUNC void func_80005CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005CF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005CF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80005CF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005CFC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005D00: addiu       $a0, $a0, 0x7108
    ctx->r4 = ADD32(ctx->r4, 0X7108);
    // 0x80005D04: jal         0x80003698
    // 0x80005D08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x80005D08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80005D0C: bne         $v0, $zero, L_80005D1C
    if (ctx->r2 != 0) {
        // 0x80005D10: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80005D1C;
    }
    // 0x80005D10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80005D14: b           L_80005D68
    // 0x80005D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005D68;
    // 0x80005D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005D1C:
    // 0x80005D1C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80005D20: lw          $t6, 0x7398($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7398);
    // 0x80005D24: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80005D28: addiu       $t9, $t9, 0x7108
    ctx->r25 = ADD32(ctx->r25, 0X7108);
    // 0x80005D2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80005D30: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80005D34: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80005D38: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x80005D3C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80005D40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80005D44: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x80005D48: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80005D4C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x80005D50: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80005D54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80005D58: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x80005D5C: lw          $t2, 0x7398($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7398);
    // 0x80005D60: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80005D64: sw          $t3, 0x7398($at)
    MEM_W(0X7398, ctx->r1) = ctx->r11;
L_80005D68:
    // 0x80005D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005D70: jr          $ra
    // 0x80005D74: nop

    return;
    // 0x80005D74: nop

;}
RECOMP_FUNC void func_8078E35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E35C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8078E360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E364: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8078E368: jal         0x800653D8
    // 0x8078E36C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8078E36C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x8078E370: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8078E374: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x8078E378: lw          $v1, 0xD8($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XD8);
    // 0x8078E37C: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x8078E380: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8078E384: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x8078E388: bne         $t6, $zero, L_8078E494
    if (ctx->r14 != 0) {
        // 0x8078E38C: addiu       $a1, $a2, -0x3
        ctx->r5 = ADD32(ctx->r6, -0X3);
            goto L_8078E494;
    }
    // 0x8078E38C: addiu       $a1, $a2, -0x3
    ctx->r5 = ADD32(ctx->r6, -0X3);
    // 0x8078E390: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8078E394: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8078E398: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8078E39C: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8078E3A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078E3A4: lwc1        $f14, 0x70($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8078E3A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8078E3AC: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8078E3B0: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8078E3B4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA8C) << 16);
    // 0x8078E3B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8078E3BC: add.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8078E3C0: mul.s       $f16, $f6, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8078E3C4: nop

    // 0x8078E3C8: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8078E3CC: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8078E3D0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8078E3D4: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8078E3D8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8078E3DC: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8078E3E0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x8078E3E4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8078E3E8: lwc1        $f4, -0x1654($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA8C));
    // 0x8078E3EC: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA90) << 16);
    // 0x8078E3F0: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8078E3F4: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8078E3F8: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8078E3FC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8078E400: lwc1        $f8, -0x1650($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA90));
    // 0x8078E404: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA94) << 16);
    // 0x8078E408: lwc1        $f4, -0x164C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA94));
    // 0x8078E40C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8078E410: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8078E414: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA98) << 16);
    // 0x8078E418: mul.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8078E41C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8078E420: nop

    // 0x8078E424: bc1f        L_8078E430
    if (!c1cs) {
        // 0x8078E428: nop
    
            goto L_8078E430;
    }
    // 0x8078E428: nop

    // 0x8078E42C: lwc1        $f0, -0x1648($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA98));
L_8078E430:
    // 0x8078E430: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8078E434: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078E438: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8078E43C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8078E440: nop

    // 0x8078E444: bc1fl       L_8078E458
    if (!c1cs) {
        // 0x8078E448: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8078E458;
    }
    goto skip_0;
    // 0x8078E448: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_0:
    // 0x8078E44C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8078E450: nop

    // 0x8078E454: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_8078E458:
    // 0x8078E458: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078E45C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA9C) << 16);
    // 0x8078E460: lwc1        $f8, -0x1644($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA9C));
    // 0x8078E464: lw          $t8, 0xA68($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XA68);
    // 0x8078E468: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8078E46C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8078E470: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x8078E474: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x8078E478: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8078E47C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8078E480: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x8078E484: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8078E488: lw          $t9, 0x10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X10);
    // 0x8078E48C: jalr        $t9
    // 0x8078E490: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8078E490: nop

    after_1:
L_8078E494:
    // 0x8078E494: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078E498: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8078E49C: jr          $ra
    // 0x8078E4A0: nop

    return;
    // 0x8078E4A0: nop

;}
RECOMP_FUNC void func_806E6324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6324: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x806E6328: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x806E632C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x806E6330: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x806E6334: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x806E6338: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x806E633C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x806E6340: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x806E6344: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x806E6348: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x806E634C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806E6350: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x806E6354: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x806E6358: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806E635C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806E6360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E6364: jal         0x8004921C
    // 0x806E6368: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x806E6368: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    after_0:
    // 0x806E636C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x806E6370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806E6374: jal         0x8004921C
    // 0x806E6378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x806E6378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x806E637C: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x806E6380: addiu       $s4, $sp, 0xB0
    ctx->r20 = ADD32(ctx->r29, 0XB0);
    // 0x806E6384: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x806E6388: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x806E638C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E6390: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x806E6394: sw          $t8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r24;
    // 0x806E6398: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x806E639C: lw          $s1, 0x88($v1)
    ctx->r17 = MEM_W(ctx->r3, 0X88);
    // 0x806E63A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E63A4: jal         0x80077338
    // 0x806E63A8: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x806E63A8: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    after_2:
    // 0x806E63AC: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806E63B0: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x806E63B4: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x806E63B8: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806E63BC: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806E63C0: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x806E63C4: ori         $t8, $t8, 0xACB0
    ctx->r24 = ctx->r24 | 0XACB0;
    // 0x806E63C8: ori         $t7, $t7, 0x18
    ctx->r15 = ctx->r15 | 0X18;
    // 0x806E63CC: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806E63D0: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x806E63D4: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806E63D8: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x806E63DC: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x806E63E0: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806E63E4: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806E63E8: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x806E63EC: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x806E63F0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806E63F4: sw          $a1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r5;
    // 0x806E63F8: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x806E63FC: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x806E6400: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x806E6404: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x806E6408: sw          $t9, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r25;
    // 0x806E640C: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x806E6410: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x806E6414: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806E6418: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E641C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806E6420: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x806E6424: jal         0x8007711C
    // 0x806E6428: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x806E6428: sw          $t1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r9;
    after_3:
    // 0x806E642C: lw          $t1, 0x9C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X9C);
    // 0x806E6430: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(655, 0X1078) << 16);
    // 0x806E6434: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(655, 0X1088) << 16);
    // 0x806E6438: addiu       $a0, $a0, 0x6D48
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(655, 0X1088));
    // 0x806E643C: addiu       $v0, $v0, 0x6D38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(655, 0X1078));
    // 0x806E6440: addiu       $v1, $t1, 0x40
    ctx->r3 = ADD32(ctx->r9, 0X40);
L_806E6444:
    // 0x806E6444: lwc1        $f4, -0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X10);
    // 0x806E6448: lwc1        $f6, 0x34($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X34);
    // 0x806E644C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x806E6450: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x806E6454: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806E6458: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E645C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806E6460: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x806E6464: bne         $at, $zero, L_806E6444
    if (ctx->r1 != 0) {
        // 0x806E6468: sh          $t8, 0x3A($v1)
        MEM_H(0X3A, ctx->r3) = ctx->r24;
            goto L_806E6444;
    }
    // 0x806E6468: sh          $t8, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r24;
    // 0x806E646C: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6470: multu       $s2, $s3
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806E6474: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x806E6478: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x806E647C: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806E6480: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x806E6484: addiu       $t8, $t1, 0x48
    ctx->r24 = ADD32(ctx->r9, 0X48);
    // 0x806E6488: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x806E648C: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x806E6490: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x806E6494: addiu       $t9, $s2, -0x1
    ctx->r25 = ADD32(ctx->r18, -0X1);
    // 0x806E6498: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x806E649C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x806E64A0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x806E64A4: addiu       $s0, $v1, 0x7
    ctx->r16 = ADD32(ctx->r3, 0X7);
    // 0x806E64A8: sra         $s0, $s0, 3
    ctx->r16 = S32(SIGNED(ctx->r16) >> 3);
    // 0x806E64AC: addiu       $t9, $s3, -0x1
    ctx->r25 = ADD32(ctx->r19, -0X1);
    // 0x806E64B0: mflo        $t5
    ctx->r13 = lo;
    // 0x806E64B4: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x806E64B8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x806E64BC: andi        $s0, $s0, 0x1FF
    ctx->r16 = ctx->r16 & 0X1FF;
    // 0x806E64C0: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x806E64C4: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x806E64C8: sll         $s0, $s0, 9
    ctx->r16 = S32(ctx->r16 << 9);
    // 0x806E64CC: sra         $t5, $t5, 1
    ctx->r13 = S32(SIGNED(ctx->r13) >> 1);
    // 0x806E64D0: lui         $t0, 0x806E
    ctx->r8 = S32(RELOC_HI16(655, 0XFE0) << 16);
    // 0x806E64D4: addiu       $t0, $t0, 0x6CA0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(655, 0XFE0));
    // 0x806E64D8: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x806E64DC: or          $s1, $t8, $t7
    ctx->r17 = ctx->r24 | ctx->r15;
    // 0x806E64E0: addiu       $s3, $zero, 0x240
    ctx->r19 = ADD32(0, 0X240);
    // 0x806E64E4: lui         $s2, 0xFD50
    ctx->r18 = S32(0XFD50 << 16);
    // 0x806E64E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806E64EC: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x806E64F0: bgez        $v1, L_806E6500
    if (SIGNED(ctx->r3) >= 0) {
        // 0x806E64F4: sra         $a3, $v1, 3
        ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
            goto L_806E6500;
    }
    // 0x806E64F4: sra         $a3, $v1, 3
    ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
    // 0x806E64F8: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x806E64FC: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_806E6500:
    // 0x806E6500: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x806E6504: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x806E6508: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x806E650C: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x806E6510: lui         $s6, 0xF300
    ctx->r22 = S32(0XF300 << 16);
    // 0x806E6514: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x806E6518: lui         $s4, 0xF550
    ctx->r20 = S32(0XF550 << 16);
    // 0x806E651C: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
L_806E6520:
    // 0x806E6520: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6524: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x806E6528: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x806E652C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x806E6530: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806E6534: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x806E6538: lh          $t8, 0x2C($t3)
    ctx->r24 = MEM_H(ctx->r11, 0X2C);
    // 0x806E653C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x806E6540: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x806E6544: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806E6548: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806E654C: mflo        $t7
    ctx->r15 = lo;
    // 0x806E6550: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x806E6554: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x806E6558: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x806E655C: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x806E6560: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806E6564: sw          $s4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r20;
    // 0x806E6568: sw          $ra, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r31;
    // 0x806E656C: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6570: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x806E6574: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x806E6578: sw          $t6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r14;
    // 0x806E657C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x806E6580: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
    // 0x806E6584: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6588: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x806E658C: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806E6590: sw          $s6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r22;
    // 0x806E6594: beq         $at, $zero, L_806E65A4
    if (ctx->r1 == 0) {
        // 0x806E6598: or          $t4, $t8, $zero
        ctx->r12 = ctx->r24 | 0;
            goto L_806E65A4;
    }
    // 0x806E6598: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x806E659C: b           L_806E65A4
    // 0x806E65A0: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
        goto L_806E65A4;
    // 0x806E65A0: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
L_806E65A4:
    // 0x806E65A4: bgtz        $a3, L_806E65B4
    if (SIGNED(ctx->r7) > 0) {
        // 0x806E65A8: nop
    
            goto L_806E65B4;
    }
    // 0x806E65A8: nop

    // 0x806E65AC: b           L_806E65B4
    // 0x806E65B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_806E65B4;
    // 0x806E65B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_806E65B4:
    // 0x806E65B4: bgtz        $a3, L_806E65C4
    if (SIGNED(ctx->r7) > 0) {
        // 0x806E65B8: addiu       $t9, $t2, 0x7FF
        ctx->r25 = ADD32(ctx->r10, 0X7FF);
            goto L_806E65C4;
    }
    // 0x806E65B8: addiu       $t9, $t2, 0x7FF
    ctx->r25 = ADD32(ctx->r10, 0X7FF);
    // 0x806E65BC: b           L_806E65C4
    // 0x806E65C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_806E65C4;
    // 0x806E65C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_806E65C4:
    // 0x806E65C4: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x806E65C8: mflo        $t6
    ctx->r14 = lo;
    // 0x806E65CC: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x806E65D0: bne         $a1, $zero, L_806E65DC
    if (ctx->r5 != 0) {
        // 0x806E65D4: nop
    
            goto L_806E65DC;
    }
    // 0x806E65D4: nop

    // 0x806E65D8: break       7
    do_break(2154718680);
L_806E65DC:
    // 0x806E65DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806E65E0: bne         $a1, $at, L_806E65F4
    if (ctx->r5 != ctx->r1) {
        // 0x806E65E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_806E65F4;
    }
    // 0x806E65E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x806E65E8: bne         $t9, $at, L_806E65F4
    if (ctx->r25 != ctx->r1) {
        // 0x806E65EC: nop
    
            goto L_806E65F4;
    }
    // 0x806E65EC: nop

    // 0x806E65F0: break       6
    do_break(2154718704);
L_806E65F4:
    // 0x806E65F4: andi        $t9, $t1, 0xFFF
    ctx->r25 = ctx->r9 & 0XFFF;
    // 0x806E65F8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x806E65FC: or          $t7, $t8, $ra
    ctx->r15 = ctx->r24 | ctx->r31;
    // 0x806E6600: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x806E6604: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x806E6608: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806E660C: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x806E6610: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806E6614: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806E6618: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x806E661C: sw          $s7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r23;
    // 0x806E6620: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6624: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x806E6628: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806E662C: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x806E6630: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x806E6634: sw          $s0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r16;
    // 0x806E6638: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x806E663C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x806E6640: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x806E6644: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x806E6648: sw          $s1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r17;
    // 0x806E664C: sw          $fp, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r30;
    // 0x806E6650: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6654: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(655, 0X1010) << 16);
    // 0x806E6658: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x806E665C: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x806E6660: sw          $t8, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r24;
    // 0x806E6664: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x806E6668: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x806E666C: addiu       $t7, $t7, 0x6CD0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(655, 0X1010));
    // 0x806E6670: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x806E6674: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x806E6678: bne         $t0, $t7, L_806E6520
    if (ctx->r8 != ctx->r15) {
        // 0x806E667C: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_806E6520;
    }
    // 0x806E667C: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x806E6680: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x806E6684: lw          $t8, 0xB8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB8);
    // 0x806E6688: sw          $t6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r14;
    // 0x806E668C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x806E6690: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x806E6694: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x806E6698: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x806E669C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x806E66A0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x806E66A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x806E66A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806E66AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806E66B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806E66B4: jr          $ra
    // 0x806E66B8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x806E66B8: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_8041E564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041E564: lh          $v0, 0x10($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X10);
    // 0x8041E568: lui         $t0, 0x8042
    ctx->r8 = S32(RELOC_HI16(29, 0X31F0) << 16);
    // 0x8041E56C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8041E570: beq         $v0, $zero, L_8041E588
    if (ctx->r2 == 0) {
        // 0x8041E574: addiu       $t0, $t0, 0x850
        ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(29, 0X31F0));
            goto L_8041E588;
    }
    // 0x8041E574: addiu       $t0, $t0, 0x850
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(29, 0X31F0));
    // 0x8041E578: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8041E57C: sh          $t6, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r14;
    // 0x8041E580: jr          $ra
    // 0x8041E584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8041E584: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8041E588:
    // 0x8041E588: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x8041E58C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8041E590: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x8041E594: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    // 0x8041E598: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8041E59C: bnel        $at, $zero, L_8041E5B0
    if (ctx->r1 != 0) {
        // 0x8041E5A0: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_8041E5B0;
    }
    goto skip_0;
    // 0x8041E5A0: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    skip_0:
    // 0x8041E5A4: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8041E5A8: lh          $v0, 0xE($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XE);
    // 0x8041E5AC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8041E5B0:
    // 0x8041E5B0: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x8041E5B4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x8041E5B8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8041E5BC: sh          $t1, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r9;
    // 0x8041E5C0: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x8041E5C4: bne         $v0, $at, L_8041E5D4
    if (ctx->r2 != ctx->r1) {
        // 0x8041E5C8: sh          $t2, 0x10($a0)
        MEM_H(0X10, ctx->r4) = ctx->r10;
            goto L_8041E5D4;
    }
    // 0x8041E5C8: sh          $t2, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r10;
    // 0x8041E5CC: jr          $ra
    // 0x8041E5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8041E5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8041E5D4:
    // 0x8041E5D4: bne         $v0, $zero, L_8041E5E0
    if (ctx->r2 != 0) {
        // 0x8041E5D8: nop
    
            goto L_8041E5E0;
    }
    // 0x8041E5D8: nop

    // 0x8041E5DC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8041E5E0:
    // 0x8041E5E0: jr          $ra
    // 0x8041E5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8041E5E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void Math_FAcosF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80081FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80081FB8: jal         0x80081F80
    // 0x80081FBC: nop

    Math_FAsinF(rdram, ctx);
        goto after_0;
    // 0x80081FBC: nop

    after_0:
    // 0x80081FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80081FC4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80081FC8: lwc1        $f4, 0x3198($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3198);
    // 0x80081FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80081FD0: jr          $ra
    // 0x80081FD4: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    return;
    // 0x80081FD4: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
;}
RECOMP_FUNC void func_80019D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019D34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019D38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80019D3C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80019D40: jal         0x80019AC4
    // 0x80019D44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x80019D44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80019D48: beq         $v0, $zero, L_80019D68
    if (ctx->r2 == 0) {
        // 0x80019D4C: lh          $t6, 0x1A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X1A);
            goto L_80019D68;
    }
    // 0x80019D4C: lh          $t6, 0x1A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X1A);
    // 0x80019D50: sh          $t6, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r14;
    // 0x80019D54: lh          $t7, 0x1E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X1E);
    // 0x80019D58: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x80019D5C: lh          $t8, 0x22($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X22);
    // 0x80019D60: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80019D64: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
L_80019D68:
    // 0x80019D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019D70: jr          $ra
    // 0x80019D74: nop

    return;
    // 0x80019D74: nop

;}
RECOMP_FUNC void func_80471BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80471BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471BAC: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x80471BB0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80471BB4: jal         0x80065728
    // 0x80471BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80471BB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80471BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80471BC4: jr          $ra
    // 0x80471BC8: nop

    return;
    // 0x80471BC8: nop

;}
RECOMP_FUNC void func_80011434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011434: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80011438: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001143C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80011440: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80011444: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80011448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001144C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80011450: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80011454: jal         0x8001A7A0
    // 0x80011458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8001A7A0(rdram, ctx);
        goto after_0;
    // 0x80011458: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8001145C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80011460: addiu       $v1, $v1, -0x6D68
    ctx->r3 = ADD32(ctx->r3, -0X6D68);
    // 0x80011464: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80011468: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001146C: jal         0x8001AE64
    // 0x80011470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001AE64(rdram, ctx);
        goto after_1;
    // 0x80011470: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80011474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80011478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001147C: jr          $ra
    // 0x80011480: nop

    return;
    // 0x80011480: nop

;}
RECOMP_FUNC void gfxprint_color(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F3F4: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8007F3F8: sb          $a1, 0x14($a0)
    MEM_B(0X14, ctx->r4) = ctx->r5;
    // 0x8007F3FC: sb          $a2, 0x15($a0)
    MEM_B(0X15, ctx->r4) = ctx->r6;
    // 0x8007F400: sb          $a3, 0x16($a0)
    MEM_B(0X16, ctx->r4) = ctx->r7;
    // 0x8007F404: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8007F408: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007F40C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007F410: sb          $t6, 0x17($a0)
    MEM_B(0X17, ctx->r4) = ctx->r14;
    // 0x8007F414: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007F418: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007F41C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007F420: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x8007F424: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8007F428: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8007F42C: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007F430: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8007F434: lw          $t2, 0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X14);
    // 0x8007F438: jr          $ra
    // 0x8007F43C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    return;
    // 0x8007F43C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
;}
RECOMP_FUNC void func_8042117C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042117C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80421184: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80421188: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8042118C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80421190: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(32, 0X1700) << 16);
    // 0x80421194: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80421198: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8042119C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804211A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804211A4: lw          $t8, 0x27C0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(32, 0X1700));
    // 0x804211A8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804211AC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804211B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804211B4: jal         0x80048490
    // 0x804211B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804211B8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804211BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804211C0: jal         0x80048378
    // 0x804211C4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804211C4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804211C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804211CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804211D0: jr          $ra
    // 0x804211D4: nop

    return;
    // 0x804211D4: nop

;}
RECOMP_FUNC void func_8057DC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057DC94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057DC98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057DC9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057DCA0: jal         0x8057DD34
    // 0x8057DCA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8057DD34(rdram, ctx);
        goto after_0;
    // 0x8057DCA4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8057DCA8: beq         $v0, $zero, L_8057DD18
    if (ctx->r2 == 0) {
        // 0x8057DCAC: nop
    
            goto L_8057DD18;
    }
    // 0x8057DCAC: nop

    // 0x8057DCB0: jal         0x8057DE04
    // 0x8057DCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8057DE04(rdram, ctx);
        goto after_1;
    // 0x8057DCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8057DCB8: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8057DCBC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8057DCC0: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8057DCC4: lui         $t7, 0x8058
    ctx->r15 = S32(RELOC_HI16(393, 0X1098) << 16);
    // 0x8057DCC8: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8057DCCC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8057DCD0: addiu       $t7, $t7, -0x1428
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(393, 0X1098));
    // 0x8057DCD4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8057DCD8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8057DCDC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8057DCE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057DCE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057DCE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8057DCEC: jal         0x8057EAEC
    // 0x8057DCF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8057EAEC(rdram, ctx);
        goto after_2;
    // 0x8057DCF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8057DCF4: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8057DCF8: lui         $t9, 0x8058
    ctx->r25 = S32(RELOC_HI16(393, 0X664) << 16);
    // 0x8057DCFC: addiu       $t9, $t9, -0x1E5C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(393, 0X664));
    // 0x8057DD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057DD04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8057DD08: jal         0x80057640
    // 0x8057DD0C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_80057640(rdram, ctx);
        goto after_3;
    // 0x8057DD0C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x8057DD10: b           L_8057DD24
    // 0x8057DD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8057DD24;
    // 0x8057DD14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057DD18:
    // 0x8057DD18: jal         0x800445A4
    // 0x8057DD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8057DD1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8057DD20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057DD24:
    // 0x8057DD24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057DD28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057DD2C: jr          $ra
    // 0x8057DD30: nop

    return;
    // 0x8057DD30: nop

;}
RECOMP_FUNC void func_80742BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742BB4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742BB8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742BBC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742BC0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742BC4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742BC8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742BCC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742BD0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742BD4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742BD8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742BDC: jr          $ra
    // 0x80742BE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742BE0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807ABFE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807ABFE0: jr          $ra
    // 0x807ABFE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807ABFE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8073FC9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073FC9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073FCA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073FCA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073FCA8: jal         0x8073FBEC
    // 0x8073FCAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8073FBEC(rdram, ctx);
        goto after_0;
    // 0x8073FCAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8073FCB0: bne         $v0, $zero, L_8073FCC8
    if (ctx->r2 != 0) {
        // 0x8073FCB4: nop
    
            goto L_8073FCC8;
    }
    // 0x8073FCB4: nop

    // 0x8073FCB8: jal         0x800445A4
    // 0x8073FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8073FCBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073FCC0: b           L_8073FD28
    // 0x8073FCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073FD28;
    // 0x8073FCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073FCC8:
    // 0x8073FCC8: jal         0x8073F0F8
    // 0x8073FCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073F0F8(rdram, ctx);
        goto after_2;
    // 0x8073FCCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8073FCD0: bne         $v0, $zero, L_8073FCE8
    if (ctx->r2 != 0) {
        // 0x8073FCD4: nop
    
            goto L_8073FCE8;
    }
    // 0x8073FCD4: nop

    // 0x8073FCD8: jal         0x800445A4
    // 0x8073FCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8073FCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8073FCE0: b           L_8073FD28
    // 0x8073FCE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073FD28;
    // 0x8073FCE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073FCE8:
    // 0x8073FCE8: jal         0x8073FC84
    // 0x8073FCEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073FC84(rdram, ctx);
        goto after_4;
    // 0x8073FCEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073FCF0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8073FCF4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8073FCF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8073FCFC: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8073FD00: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    // 0x8073FD04: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8073FD08: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8073FD0C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8073FD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073FD14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073FD18: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073FD1C: jal         0x8073FD38
    // 0x8073FD20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8073FD38(rdram, ctx);
        goto after_5;
    // 0x8073FD20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8073FD24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073FD28:
    // 0x8073FD28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073FD2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073FD30: jr          $ra
    // 0x8073FD34: nop

    return;
    // 0x8073FD34: nop

;}
RECOMP_FUNC void func_8042FE94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042FE94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042FE98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042FE9C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042FEA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8042FEA4: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x8042FEA8: bne         $at, $zero, L_8042FEC0
    if (ctx->r1 != 0) {
        // 0x8042FEAC: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_8042FEC0;
    }
    // 0x8042FEAC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8042FEB0: jal         0x8042FEDC
    // 0x8042FEB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042FEDC(rdram, ctx);
        goto after_0;
    // 0x8042FEB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042FEB8: b           L_8042FEC4
    // 0x8042FEBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
        goto L_8042FEC4;
    // 0x8042FEBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8042FEC0:
    // 0x8042FEC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8042FEC4:
    // 0x8042FEC4: jal         0x8042F6B4
    // 0x8042FEC8: nop

    func_8042F6B4(rdram, ctx);
        goto after_1;
    // 0x8042FEC8: nop

    after_1:
    // 0x8042FECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042FED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042FED4: jr          $ra
    // 0x8042FED8: nop

    return;
    // 0x8042FED8: nop

;}
RECOMP_FUNC void func_806A2CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A2CB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806A2CB4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806A2CB8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x806A2CBC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806A2CC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806A2CC4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x806A2CC8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x806A2CCC: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(583, 0X650) << 16);
    // 0x806A2CD0: lui         $a1, 0x40EA
    ctx->r5 = S32(0X40EA << 16);
    // 0x806A2CD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806A2CD8: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x806A2CDC: addiu       $a0, $a0, 0x2EB0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(583, 0X650));
    // 0x806A2CE0: jal         0x80046804
    // 0x806A2CE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x806A2CE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806A2CE8: beq         $v0, $zero, L_806A2D68
    if (ctx->r2 == 0) {
        // 0x806A2CEC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806A2D68;
    }
    // 0x806A2CEC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806A2CF0: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x806A2CF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806A2CF8: bnel        $t6, $zero, L_806A2D24
    if (ctx->r14 != 0) {
        // 0x806A2CFC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806A2D24;
    }
    goto skip_0;
    // 0x806A2CFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x806A2D00: jal         0x80045A34
    // 0x806A2D04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806A2D04: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x806A2D08: bne         $v0, $zero, L_806A2D20
    if (ctx->r2 != 0) {
        // 0x806A2D0C: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_806A2D20;
    }
    // 0x806A2D0C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806A2D10: jal         0x800445A4
    // 0x806A2D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x806A2D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806A2D18: b           L_806A2D6C
    // 0x806A2D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806A2D6C;
    // 0x806A2D1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806A2D20:
    // 0x806A2D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806A2D24:
    // 0x806A2D24: jal         0x806A2C64
    // 0x806A2D28: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_806A2C64(rdram, ctx);
        goto after_3;
    // 0x806A2D28: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_3:
    // 0x806A2D2C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x806A2D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806A2D34: jal         0x80044194
    // 0x806A2D38: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x806A2D38: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x806A2D3C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x806A2D40: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806A2D44: lhu         $t8, 0xC($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0XC);
    // 0x806A2D48: bnel        $t8, $at, L_806A2D6C
    if (ctx->r24 != ctx->r1) {
        // 0x806A2D4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806A2D6C;
    }
    goto skip_1;
    // 0x806A2D4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x806A2D50: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806A2D54: jal         0x80067BBC
    // 0x806A2D58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x806A2D58: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x806A2D5C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x806A2D60: jal         0x80067818
    // 0x806A2D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x806A2D64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
L_806A2D68:
    // 0x806A2D68: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806A2D6C:
    // 0x806A2D6C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806A2D70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806A2D74: jr          $ra
    // 0x806A2D78: nop

    return;
    // 0x806A2D78: nop

    // 0x806A2D7C: nop

;}
RECOMP_FUNC void func_8049F060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F060: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8049F064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8049F068: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8049F06C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8049F070: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049F074: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8049F078: jal         0x8049EF18
    // 0x8049F07C: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    func_8049EF18(rdram, ctx);
        goto after_0;
    // 0x8049F07C: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8049F080: lhu         $t6, 0x8($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X8);
    // 0x8049F084: addiu       $s0, $s1, 0xC4
    ctx->r16 = ADD32(ctx->r17, 0XC4);
    // 0x8049F088: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(167, 0X1168) << 16);
    // 0x8049F08C: andi        $t7, $t6, 0xFFFE
    ctx->r15 = ctx->r14 & 0XFFFE;
    // 0x8049F090: sh          $t7, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r15;
    // 0x8049F094: lw          $t8, 0x68($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X68);
    // 0x8049F098: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F09C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8049F0A0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8049F0A4: lw          $t9, -0x318($at)
    ctx->r25 = MEM_W(ctx->r1, (int16_t)RELOC_LO16(167, 0X1168));
    // 0x8049F0A8: jalr        $t9
    // 0x8049F0AC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8049F0AC: nop

    after_1:
    // 0x8049F0B0: jal         0x8049EC3C
    // 0x8049F0B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8049EC3C(rdram, ctx);
        goto after_2;
    // 0x8049F0B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8049F0B8: lhu         $t1, 0x8($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X8);
    // 0x8049F0BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F0C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F0C4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8049F0C8: beq         $t2, $zero, L_8049F104
    if (ctx->r10 == 0) {
        // 0x8049F0CC: nop
    
            goto L_8049F104;
    }
    // 0x8049F0CC: nop

    // 0x8049F0D0: jal         0x800554AC
    // 0x8049F0D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800554AC(rdram, ctx);
        goto after_3;
    // 0x8049F0D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8049F0D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8049F0DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F0E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8049F0E4: jal         0x8049FBAC
    // 0x8049F0E8: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8049FBAC(rdram, ctx);
        goto after_4;
    // 0x8049F0E8: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_4:
    // 0x8049F0EC: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8049F0F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8049F0F4: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x8049F0F8: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8049F0FC: b           L_8049F118
    // 0x8049F100: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
        goto L_8049F118;
    // 0x8049F100: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_8049F104:
    // 0x8049F104: jal         0x8049EEA4
    // 0x8049F108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8049EEA4(rdram, ctx);
        goto after_5;
    // 0x8049F108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8049F10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F110: jal         0x8049EEA4
    // 0x8049F114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8049EEA4(rdram, ctx);
        goto after_6;
    // 0x8049F114: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_8049F118:
    // 0x8049F118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8049F11C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049F120: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8049F124: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8049F128: jr          $ra
    // 0x8049F12C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8049F12C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80445A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445A74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445A78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445A7C: jal         0x800677F8
    // 0x80445A80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445A80: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x80445A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445A8C: jr          $ra
    // 0x80445A90: nop

    return;
    // 0x80445A90: nop

;}
RECOMP_FUNC void func_80448BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448BEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448BF0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80448BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80448BF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80448BFC: bne         $a2, $zero, L_80448C24
    if (ctx->r6 != 0) {
        // 0x80448C00: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80448C24;
    }
    // 0x80448C00: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80448C04: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x80448C08: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80448C0C: bgtz        $t7, L_80448C64
    if (SIGNED(ctx->r15) > 0) {
        // 0x80448C10: sw          $t7, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r15;
            goto L_80448C64;
    }
    // 0x80448C10: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x80448C14: jal         0x804467B0
    // 0x80448C18: nop

    func_804467B0(rdram, ctx);
        goto after_0;
    // 0x80448C18: nop

    after_0:
    // 0x80448C1C: b           L_80448C68
    // 0x80448C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80448C68;
    // 0x80448C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448C24:
    // 0x80448C24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80448C28: bnel        $a2, $at, L_80448C54
    if (ctx->r6 != ctx->r1) {
        // 0x80448C2C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448C54;
    }
    goto skip_0;
    // 0x80448C2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x80448C30: jal         0x80446758
    // 0x80448C34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80446758(rdram, ctx);
        goto after_1;
    // 0x80448C34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80448C38: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80448C3C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448C40: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80448C44: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448C48: b           L_80448C64
    // 0x80448C4C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80448C64;
    // 0x80448C4C: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
    // 0x80448C50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448C54:
    // 0x80448C54: bnel        $a2, $at, L_80448C68
    if (ctx->r6 != ctx->r1) {
        // 0x80448C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448C68;
    }
    goto skip_1;
    // 0x80448C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80448C5C: jal         0x804467B0
    // 0x80448C60: nop

    func_804467B0(rdram, ctx);
        goto after_2;
    // 0x80448C60: nop

    after_2:
L_80448C64:
    // 0x80448C64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448C68:
    // 0x80448C68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80448C6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448C70: jr          $ra
    // 0x80448C74: nop

    return;
    // 0x80448C74: nop

;}
RECOMP_FUNC void func_8005EBF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EBF8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EBFC: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8005EC00: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005EC04: addiu       $t8, $t8, 0x6440
    ctx->r24 = ADD32(ctx->r24, 0X6440);
    // 0x8005EC08: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    // 0x8005EC0C: jr          $ra
    // 0x8005EC10: sw          $t8, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = ctx->r24;
    return;
    // 0x8005EC10: sw          $t8, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_805CA904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA904: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805CA908: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CA90C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805CA910: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CA914: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805CA918: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x805CA91C: lw          $s0, 0x180($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X180);
    // 0x805CA920: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x805CA924: jal         0x80049018
    // 0x805CA928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x805CA928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x805CA92C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x805CA930: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X714) << 16);
    // 0x805CA934: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805CA938: lwc1        $f4, -0x509C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X714));
    // 0x805CA93C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805CA940: lwc1        $f12, 0x50($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X50);
    // 0x805CA944: jal         0x80066DE4
    // 0x805CA948: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x805CA948: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x805CA94C: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805CA950: jal         0x80066E88
    // 0x805CA954: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x805CA954: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x805CA958: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x805CA95C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x805CA960: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x805CA964: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805CA968: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x805CA96C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805CA970: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805CA974: lwc1        $f10, 0x70($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X70);
    // 0x805CA978: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x805CA97C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805CA980: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x805CA984: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x805CA988: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805CA98C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805CA990: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805CA994: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x805CA998: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x805CA99C: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x805CA9A0: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x805CA9A4: nop

    // 0x805CA9A8: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x805CA9AC: nop

    // 0x805CA9B0: mul.s       $f18, $f12, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x805CA9B4: swc1        $f4, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f4.u32l;
    // 0x805CA9B8: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805CA9BC: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x805CA9C0: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x805CA9C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x805CA9C8: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x805CA9CC: swc1        $f10, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f10.u32l;
    // 0x805CA9D0: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x805CA9D4: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805CA9D8: sw          $zero, 0x138($a1)
    MEM_W(0X138, ctx->r5) = 0;
    // 0x805CA9DC: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x805CA9E0: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x805CA9E4: swc1        $f10, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f10.u32l;
    // 0x805CA9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805CA9EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805CA9F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805CA9F4: jr          $ra
    // 0x805CA9F8: nop

    return;
    // 0x805CA9F8: nop

;}
RECOMP_FUNC void func_80448298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448298: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8044829C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x804482A0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x804482A4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x804482A8: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x804482AC: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x804482B0: lw          $t7, 0x6A2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A2C);
    // 0x804482B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804482B8: lui         $t3, 0x1
    ctx->r11 = S32(0X1 << 16);
    // 0x804482BC: bne         $t7, $at, L_80448304
    if (ctx->r15 != ctx->r1) {
        // 0x804482C0: addu        $t3, $t3, $v1
        ctx->r11 = ADD32(ctx->r11, ctx->r3);
            goto L_80448304;
    }
    // 0x804482C0: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x804482C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804482C8: ori         $at, $at, 0x6A3C
    ctx->r1 = ctx->r1 | 0X6A3C;
    // 0x804482CC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x804482D0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x804482D4: addiu       $t1, $zero, 0x3C0
    ctx->r9 = ADD32(0, 0X3C0);
    // 0x804482D8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x804482DC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x804482E0: slti        $at, $t9, 0x3C0
    ctx->r1 = SIGNED(ctx->r25) < 0X3C0 ? 1 : 0;
    // 0x804482E4: bne         $at, $zero, L_80448330
    if (ctx->r1 != 0) {
        // 0x804482E8: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_80448330;
    }
    // 0x804482E8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x804482EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804482F0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x804482F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804482F8: sw          $t2, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r10;
    // 0x804482FC: jr          $ra
    // 0x80448300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448300: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80448304:
    // 0x80448304: lw          $t3, 0x6A2C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A2C);
    // 0x80448308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044830C: bne         $t3, $at, L_80448330
    if (ctx->r11 != ctx->r1) {
        // 0x80448310: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80448330;
    }
    // 0x80448310: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448314: ori         $at, $at, 0x6A3C
    ctx->r1 = ctx->r1 | 0X6A3C;
    // 0x80448318: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044831C: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80448320: subu        $t5, $t4, $a2
    ctx->r13 = SUB32(ctx->r12, ctx->r6);
    // 0x80448324: bgtz        $t5, L_80448330
    if (SIGNED(ctx->r13) > 0) {
        // 0x80448328: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_80448330;
    }
    // 0x80448328: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8044832C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80448330:
    // 0x80448330: jr          $ra
    // 0x80448334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_806D2FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2FB0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806D2FB4: addiu       $at, $zero, 0x45AA
    ctx->r1 = ADD32(0, 0X45AA);
    // 0x806D2FB8: beq         $v0, $at, L_806D2FE0
    if (ctx->r2 == ctx->r1) {
        // 0x806D2FBC: addiu       $at, $zero, 0x45AB
        ctx->r1 = ADD32(0, 0X45AB);
            goto L_806D2FE0;
    }
    // 0x806D2FBC: addiu       $at, $zero, 0x45AB
    ctx->r1 = ADD32(0, 0X45AB);
    // 0x806D2FC0: beq         $v0, $at, L_806D2FEC
    if (ctx->r2 == ctx->r1) {
        // 0x806D2FC4: addiu       $at, $zero, 0x45AC
        ctx->r1 = ADD32(0, 0X45AC);
            goto L_806D2FEC;
    }
    // 0x806D2FC4: addiu       $at, $zero, 0x45AC
    ctx->r1 = ADD32(0, 0X45AC);
    // 0x806D2FC8: beq         $v0, $at, L_806D2FF8
    if (ctx->r2 == ctx->r1) {
        // 0x806D2FCC: addiu       $at, $zero, 0x45AD
        ctx->r1 = ADD32(0, 0X45AD);
            goto L_806D2FF8;
    }
    // 0x806D2FCC: addiu       $at, $zero, 0x45AD
    ctx->r1 = ADD32(0, 0X45AD);
    // 0x806D2FD0: beq         $v0, $at, L_806D3004
    if (ctx->r2 == ctx->r1) {
        // 0x806D2FD4: nop
    
            goto L_806D3004;
    }
    // 0x806D2FD4: nop

    // 0x806D2FD8: b           L_806D3010
    // 0x806D2FDC: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0X1098) << 16);
        goto L_806D3010;
    // 0x806D2FDC: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0X1098) << 16);
L_806D2FE0:
    // 0x806D2FE0: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0X1098) << 16);
    // 0x806D2FE4: jr          $ra
    // 0x806D2FE8: addiu       $v0, $v0, 0x4048
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X1098));
    return;
    // 0x806D2FE8: addiu       $v0, $v0, 0x4048
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X1098));
L_806D2FEC:
    // 0x806D2FEC: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0X10EC) << 16);
    // 0x806D2FF0: jr          $ra
    // 0x806D2FF4: addiu       $v0, $v0, 0x409C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X10EC));
    return;
    // 0x806D2FF4: addiu       $v0, $v0, 0x409C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X10EC));
L_806D2FF8:
    // 0x806D2FF8: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0X1144) << 16);
    // 0x806D2FFC: jr          $ra
    // 0x806D3000: addiu       $v0, $v0, 0x40F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X1144));
    return;
    // 0x806D3000: addiu       $v0, $v0, 0x40F4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X1144));
L_806D3004:
    // 0x806D3004: lui         $v0, 0x806D
    ctx->r2 = S32(RELOC_HI16(616, 0XE1C) << 16);
    // 0x806D3008: jr          $ra
    // 0x806D300C: addiu       $v0, $v0, 0x3DCC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0XE1C));
    return;
    // 0x806D300C: addiu       $v0, $v0, 0x3DCC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0XE1C));
L_806D3010:
    // 0x806D3010: addiu       $v0, $v0, 0x4048
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(616, 0X1098));
    // 0x806D3014: jr          $ra
    // 0x806D3018: nop

    return;
    // 0x806D3018: nop

;}
RECOMP_FUNC void func_80427F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427F14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80427F18: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(41, 0X1E90) << 16);
    // 0x80427F1C: lwc1        $f6, -0x6830($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(41, 0X1E90));
    // 0x80427F20: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80427F24: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80427F28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80427F2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80427F30: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80427F34: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80427F38: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80427F3C: nop

    // 0x80427F40: bc1f        L_80427F54
    if (!c1cs) {
        // 0x80427F44: nop
    
            goto L_80427F54;
    }
    // 0x80427F44: nop

    // 0x80427F48: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80427F4C: nop

    // 0x80427F50: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_80427F54:
    // 0x80427F54: jr          $ra
    // 0x80427F58: nop

    return;
    // 0x80427F58: nop

;}
RECOMP_FUNC void func_8001F050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F050: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001F054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F058: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x8001F05C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001F060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001F064: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001F068: lw          $v0, 0x40($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X40);
    // 0x8001F06C: lhu         $a0, 0x60($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X60);
    // 0x8001F070: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001F074: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8001F078: jal         0x8004A97C
    // 0x8001F07C: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x8001F07C: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    after_0:
    // 0x8001F080: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8001F084: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001F088: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8001F08C: lwc1        $f4, 0x84($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X84);
    // 0x8001F090: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8001F094: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8001F098: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8001F09C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8001F0A0: lwc1        $f8, 0x88($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X88);
    // 0x8001F0A4: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001F0A8: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x8001F0AC: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001F0B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001F0B4: jal         0x8001EFDC
    // 0x8001F0B8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_8001EFDC(rdram, ctx);
        goto after_1;
    // 0x8001F0B8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8001F0BC: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8001F0C0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001F0C4: jal         0x8001EF3C
    // 0x8001F0C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    func_8001EF3C(rdram, ctx);
        goto after_2;
    // 0x8001F0C8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8001F0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F0D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001F0D4: jr          $ra
    // 0x8001F0D8: nop

    return;
    // 0x8001F0D8: nop

;}
RECOMP_FUNC void func_80448338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448338: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044833C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448340: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80448344: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448348: jr          $ra
    // 0x8044834C: sw          $t6, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = ctx->r14;
    return;
    // 0x8044834C: sw          $t6, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8002FF38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FF38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FF3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FF40: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x8002FF44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8002FF48: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FF4C: beql        $t6, $at, L_8002FF7C
    if (ctx->r14 == ctx->r1) {
        // 0x8002FF50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002FF7C;
    }
    goto skip_0;
    // 0x8002FF50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002FF54: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FF58: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8002FF5C: jal         0x8002F678
    // 0x8002FF60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FF60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FF64: beq         $v0, $zero, L_8002FF78
    if (ctx->r2 == 0) {
        // 0x8002FF68: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FF78;
    }
    // 0x8002FF68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FF6C: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002FF70: addiu       $t7, $t7, -0x4234
    ctx->r15 = ADD32(ctx->r15, -0X4234);
    // 0x8002FF74: sw          $t7, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r15;
L_8002FF78:
    // 0x8002FF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002FF7C:
    // 0x8002FF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FF80: jr          $ra
    // 0x8002FF84: nop

    return;
    // 0x8002FF84: nop

;}
RECOMP_FUNC void func_8006AB7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AB7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006AB80: lh          $t6, 0x3A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X3A);
    // 0x8006AB84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006AB88: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006AB8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8006AB90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006AB94: lh          $a3, 0x36($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X36);
    // 0x8006AB98: addiu       $a2, $sp, 0x26
    ctx->r6 = ADD32(ctx->r29, 0X26);
    // 0x8006AB9C: addiu       $a1, $sp, 0x27
    ctx->r5 = ADD32(ctx->r29, 0X27);
    // 0x8006ABA0: jal         0x8006AA74
    // 0x8006ABA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_8006AA74(rdram, ctx);
        goto after_0;
    // 0x8006ABA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8006ABA8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8006ABAC: beq         $v0, $at, L_8006ABDC
    if (ctx->r2 == ctx->r1) {
        // 0x8006ABB0: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_8006ABDC;
    }
    // 0x8006ABB0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8006ABB4: lh          $t8, 0x36($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X36);
    // 0x8006ABB8: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8006ABBC: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8006ABC0: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8006ABC4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8006ABC8: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8006ABCC: lh          $t2, 0x3A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X3A);
    // 0x8006ABD0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8006ABD4: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8006ABD8: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
L_8006ABDC:
    // 0x8006ABDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ABE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006ABE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006ABE8: jr          $ra
    // 0x8006ABEC: nop

    return;
    // 0x8006ABEC: nop

;}
RECOMP_FUNC void func_806F86F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F86F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F86F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F86FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F8700: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F8704: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F8708: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806F870C: lw          $a1, 0x264($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X264);
    // 0x806F8710: beql        $a1, $zero, L_806F87BC
    if (ctx->r5 == 0) {
        // 0x806F8714: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806F87BC;
    }
    goto skip_0;
    // 0x806F8714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x806F8718: lw          $t6, 0x174($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X174);
    // 0x806F871C: lw          $t9, 0x174($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X174);
    // 0x806F8720: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x806F8724: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F8728: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806F872C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806F8730: lw          $t8, 0x34($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X34);
    // 0x806F8734: lw          $t1, 0x34($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X34);
    // 0x806F8738: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806F873C: lwc1        $f6, 0x4($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X4);
    // 0x806F8740: lwc1        $f10, 0x10($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X10);
    // 0x806F8744: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B30) << 16);
    // 0x806F8748: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F874C: lwc1        $f6, 0x8C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8C);
    // 0x806F8750: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F8754: lwc1        $f8, -0x6CC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B30));
    // 0x806F8758: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806F875C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806F8760: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x806F8764: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x806F8768: jal         0x806F864C
    // 0x806F876C: nop

    func_806F864C(rdram, ctx);
        goto after_0;
    // 0x806F876C: nop

    after_0:
    // 0x806F8770: lui         $t3, 0x8070
    ctx->r11 = S32(RELOC_HI16(694, 0X11E0) << 16);
    // 0x806F8774: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x806F8778: addiu       $t3, $t3, -0x7610
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(694, 0X11E0));
    // 0x806F877C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F8780: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F8784: sb          $t2, 0x30($s1)
    MEM_B(0X30, ctx->r17) = ctx->r10;
    // 0x806F8788: sw          $t3, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r11;
    // 0x806F878C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x806F8790: sw          $t4, 0x5F4($s0)
    MEM_W(0X5F4, ctx->r16) = ctx->r12;
    // 0x806F8794: sw          $zero, 0x264($s0)
    MEM_W(0X264, ctx->r16) = 0;
    // 0x806F8798: addiu       $a0, $s0, 0x268
    ctx->r4 = ADD32(ctx->r16, 0X268);
    // 0x806F879C: jal         0x806F85F8
    // 0x806F87A0: swc1        $f16, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->f16.u32l;
    func_806F85F8(rdram, ctx);
        goto after_1;
    // 0x806F87A0: swc1        $f16, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x806F87A4: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    // 0x806F87A8: jal         0x80067818
    // 0x806F87AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x806F87AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x806F87B0: b           L_806F87C8
    // 0x806F87B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F87C8;
    // 0x806F87B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F87B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_806F87BC:
    // 0x806F87BC: jal         0x8005D87C
    // 0x806F87C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8005D87C(rdram, ctx);
        goto after_3;
    // 0x806F87C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x806F87C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F87C8:
    // 0x806F87C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F87CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F87D0: jr          $ra
    // 0x806F87D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806F87D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8064C714(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8064C718: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064C71C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064C720: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8064C724: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064C728: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C72C: blez        $v0, L_8064C740
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8064C730: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_8064C740;
    }
    // 0x8064C730: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064C734: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064C738: b           L_8064C76C
    // 0x8064C73C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_8064C76C;
    // 0x8064C73C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8064C740:
    // 0x8064C740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064C744: jal         0x8064CD50
    // 0x8064C748: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C748: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_0:
    // 0x8064C74C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064C750: jal         0x80067BBC
    // 0x8064C754: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8064C754: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8064C758: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x8064C75C: jal         0x80067818
    // 0x8064C760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8064C760: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8064C764: jal         0x8064A43C
    // 0x8064C768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064A43C(rdram, ctx);
        goto after_3;
    // 0x8064C768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8064C76C:
    // 0x8064C76C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064C770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064C774: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8064C778: jr          $ra
    // 0x8064C77C: nop

    return;
    // 0x8064C77C: nop

;}
RECOMP_FUNC void func_805CAC54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CAC54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CAC58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CAC5C: jal         0x805CAA68
    // 0x805CAC60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805CAA68(rdram, ctx);
        goto after_0;
    // 0x805CAC60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CAC64: jal         0x805CAC04
    // 0x805CAC68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805CAC04(rdram, ctx);
        goto after_1;
    // 0x805CAC68: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805CAC6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CAC70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805CAC74: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805CAC78: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805CAC7C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x805CAC80: nop

    // 0x805CAC84: bc1fl       L_805CACB8
    if (!c1cs) {
        // 0x805CAC88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805CACB8;
    }
    goto skip_0;
    // 0x805CAC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805CAC8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805CAC90: nop

    // 0x805CAC94: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x805CAC98: nop

    // 0x805CAC9C: bc1fl       L_805CACB8
    if (!c1cs) {
        // 0x805CACA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805CACB8;
    }
    goto skip_1;
    // 0x805CACA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805CACA4: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x805CACA8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x805CACAC: jal         0x805CACCC
    // 0x805CACB0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_805CACCC(rdram, ctx);
        goto after_2;
    // 0x805CACB0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x805CACB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805CACB8:
    // 0x805CACB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CACBC: jr          $ra
    // 0x805CACC0: nop

    return;
    // 0x805CACC0: nop

;}
RECOMP_FUNC void func_80742694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742694: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80742698: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8074269C: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x807426A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x807426A4: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x807426A8: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x807426AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807426B0: lw          $t1, 0x6E5C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E5C);
    // 0x807426B4: bne         $v1, $at, L_807426C4
    if (ctx->r3 != ctx->r1) {
        // 0x807426B8: nop
    
            goto L_807426C4;
    }
    // 0x807426B8: nop

    // 0x807426BC: beq         $t1, $zero, L_807426D4
    if (ctx->r9 == 0) {
        // 0x807426C0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_807426D4;
    }
    // 0x807426C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_807426C4:
    // 0x807426C4: jal         0x807424D8
    // 0x807426C8: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x807426C8: nop

    after_0:
    // 0x807426CC: b           L_80742734
    // 0x807426D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742734;
    // 0x807426D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807426D4:
    // 0x807426D4: lwc1        $f12, 0x6BE0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE0);
    // 0x807426D8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807426DC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x807426E0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x807426E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x807426E8: jal         0x807423AC
    // 0x807426EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_807423AC(rdram, ctx);
        goto after_1;
    // 0x807426EC: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x807426F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x807426F4: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x807426F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807426FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742700: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742704: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80742708: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8074270C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742710: jal         0x80742308
    // 0x80742714: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_80742308(rdram, ctx);
        goto after_2;
    // 0x80742714: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x80742718: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8074271C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742720: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80742724: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80742728: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x8074272C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80742730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742734:
    // 0x80742734: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80742738: jr          $ra
    // 0x8074273C: nop

    return;
    // 0x8074273C: nop

;}
RECOMP_FUNC void func_806EE3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE3DC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806EE3E0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806EE3E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806EE3E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EE3EC: jal         0x80045A34
    // 0x806EE3F0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806EE3F0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x806EE3F4: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X246C) << 16);
    // 0x806EE3F8: addiu       $t6, $t6, -0x1C44
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X246C));
    // 0x806EE3FC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806EE400: bne         $v0, $zero, L_806EE410
    if (ctx->r2 != 0) {
        // 0x806EE404: sw          $t6, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = ctx->r14;
            goto L_806EE410;
    }
    // 0x806EE404: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x806EE408: b           L_806EE4AC
    // 0x806EE40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EE4AC;
    // 0x806EE40C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EE410:
    // 0x806EE410: jal         0x806EE384
    // 0x806EE414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE384(rdram, ctx);
        goto after_1;
    // 0x806EE414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EE418: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EE41C: jal         0x80058958
    // 0x806EE420: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_2;
    // 0x806EE420: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_2:
    // 0x806EE424: beq         $v0, $zero, L_806EE4A8
    if (ctx->r2 == 0) {
        // 0x806EE428: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_806EE4A8;
    }
    // 0x806EE428: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806EE42C: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x806EE430: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x806EE434: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x806EE438: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x806EE43C: beql        $t1, $zero, L_806EE4AC
    if (ctx->r9 == 0) {
        // 0x806EE440: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806EE4AC;
    }
    goto skip_0;
    // 0x806EE440: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806EE444: jal         0x80056564
    // 0x806EE448: nop

    func_80056564(rdram, ctx);
        goto after_3;
    // 0x806EE448: nop

    after_3:
    // 0x806EE44C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806EE450: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE454: beq         $v0, $zero, L_806EE4A0
    if (ctx->r2 == 0) {
        // 0x806EE458: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_806EE4A0;
    }
    // 0x806EE458: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x806EE45C: jal         0x800457A0
    // 0x806EE460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_4;
    // 0x806EE460: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x806EE464: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x806EE468: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x806EE46C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x806EE470: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x806EE474: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x806EE478: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x806EE47C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x806EE480: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EE484: jal         0x80056584
    // 0x806EE488: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80056584(rdram, ctx);
        goto after_5;
    // 0x806EE488: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_5:
    // 0x806EE48C: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806EE490: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806EE494: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x806EE498: b           L_806EE4A8
    // 0x806EE49C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
        goto L_806EE4A8;
    // 0x806EE49C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_806EE4A0:
    // 0x806EE4A0: b           L_806EE4AC
    // 0x806EE4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806EE4AC;
    // 0x806EE4A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806EE4A8:
    // 0x806EE4A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EE4AC:
    // 0x806EE4AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806EE4B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806EE4B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806EE4B8: jr          $ra
    // 0x806EE4BC: nop

    return;
    // 0x806EE4BC: nop

;}
RECOMP_FUNC void func_806D8EC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D8EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D8EC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D8EC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D8ECC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x806D8ED0: lui         $a2, 0x806E
    ctx->r6 = S32(RELOC_HI16(628, 0X6D0) << 16);
    // 0x806D8ED4: addiu       $a2, $a2, -0x6A70
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(628, 0X6D0));
    // 0x806D8ED8: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x806D8EDC: jal         0x80057B28
    // 0x806D8EE0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x806D8EE0: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_0:
    // 0x806D8EE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D8EE8: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(628, 0X634) << 16);
    // 0x806D8EEC: addiu       $v0, $v0, -0x6B0C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(628, 0X634));
    // 0x806D8EF0: jr          $ra
    // 0x806D8EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806D8EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80052918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052918: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005291C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052920: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80052924: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80052928: beql        $t6, $zero, L_80052944
    if (ctx->r14 == 0) {
        // 0x8005292C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052944;
    }
    goto skip_0;
    // 0x8005292C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80052930: jal         0x8005FE48
    // 0x80052934: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x80052934: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80052938: jal         0x80052860
    // 0x8005293C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80052860(rdram, ctx);
        goto after_1;
    // 0x8005293C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80052940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052944:
    // 0x80052944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80052948: jr          $ra
    // 0x8005294C: nop

    return;
    // 0x8005294C: nop

;}
RECOMP_FUNC void func_80029DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029DE8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80029DEC: addiu       $v0, $v0, -0x2174
    ctx->r2 = ADD32(ctx->r2, -0X2174);
    // 0x80029DF0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80029DF4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80029DF8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80029DFC: nop

    // 0x80029E00: bc1fl       L_80029E2C
    if (!c1cs) {
        // 0x80029E04: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_80029E2C;
    }
    goto skip_0;
    // 0x80029E04: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x80029E08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029E0C: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029E10: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80029E14: nop

    // 0x80029E18: bc1f        L_80029E58
    if (!c1cs) {
        // 0x80029E1C: nop
    
            goto L_80029E58;
    }
    // 0x80029E1C: nop

    // 0x80029E20: jr          $ra
    // 0x80029E24: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80029E24: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x80029E28: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_80029E2C:
    // 0x80029E2C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80029E30: nop

    // 0x80029E34: bc1f        L_80029E58
    if (!c1cs) {
        // 0x80029E38: nop
    
            goto L_80029E58;
    }
    // 0x80029E38: nop

    // 0x80029E3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80029E40: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80029E44: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80029E48: nop

    // 0x80029E4C: bc1f        L_80029E58
    if (!c1cs) {
        // 0x80029E50: nop
    
            goto L_80029E58;
    }
    // 0x80029E50: nop

    // 0x80029E54: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
L_80029E58:
    // 0x80029E58: jr          $ra
    // 0x80029E5C: nop

    return;
    // 0x80029E5C: nop

;}
RECOMP_FUNC void func_80057D78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057D78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80057D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057D80: lh          $t7, 0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4);
    // 0x80057D84: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80057D88: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80057D8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80057D90: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80057D94: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80057D98: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80057D9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057DA0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80057DA4: jal         0x8006515C
    // 0x80057DA8: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    func_8006515C(rdram, ctx);
        goto after_0;
    // 0x80057DA8: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    after_0:
    // 0x80057DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057DB0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80057DB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80057DB8: jr          $ra
    // 0x80057DBC: nop

    return;
    // 0x80057DBC: nop

;}
RECOMP_FUNC void func_806731F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806731F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806731F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806731FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80673200: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x80673204: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80673208: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8067320C: lw          $t8, 0x88($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X88);
    // 0x80673210: jal         0x8067302C
    // 0x80673214: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_8067302C(rdram, ctx);
        goto after_0;
    // 0x80673214: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_0:
    // 0x80673218: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8067321C: sll         $t9, $v0, 9
    ctx->r25 = S32(ctx->r2 << 9);
    // 0x80673220: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80673224: jal         0x8004590C
    // 0x80673228: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x80673228: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_1:
    // 0x8067322C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80673230: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80673234: jr          $ra
    // 0x80673238: nop

    return;
    // 0x80673238: nop

;}
RECOMP_FUNC void func_806F2B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2B30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F2B34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2B38: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806F2B3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F2B40: beq         $t6, $zero, L_806F2B7C
    if (ctx->r14 == 0) {
        // 0x806F2B44: nop
    
            goto L_806F2B7C;
    }
    // 0x806F2B44: nop

    // 0x806F2B48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F2B4C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806F2B50: jalr        $t9
    // 0x806F2B54: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806F2B54: nop

    after_0:
    // 0x806F2B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F2B5C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806F2B60: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806F2B64: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806F2B68: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806F2B6C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806F2B70: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806F2B74: b           L_806F2B7C
    // 0x806F2B78: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806F2B7C;
    // 0x806F2B78: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806F2B7C:
    // 0x806F2B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F2B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2B84: jr          $ra
    // 0x806F2B88: nop

    return;
    // 0x806F2B88: nop

;}
RECOMP_FUNC void func_806DF9C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF9C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF9CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF9D0: jal         0x8004700C
    // 0x806DF9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806DF9D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806DF9D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806DF9DC: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x806DF9E0: beq         $v0, $zero, L_806DFBC4
    if (ctx->r2 == 0) {
        // 0x806DF9E4: lwc1        $f0, 0x50($a1)
        ctx->f0.u32l = MEM_W(ctx->r5, 0X50);
            goto L_806DFBC4;
    }
    // 0x806DF9E4: lwc1        $f0, 0x50($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806DF9E8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806DF9EC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1190) << 16);
    // 0x806DF9F0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806DF9F4: nop

    // 0x806DF9F8: bc1f        L_806DFA38
    if (!c1cs) {
        // 0x806DF9FC: nop
    
            goto L_806DFA38;
    }
    // 0x806DF9FC: nop

    // 0x806DFA00: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1188) << 16);
    // 0x806DFA04: lwc1        $f12, 0x5B8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1188));
    // 0x806DFA08: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X118C) << 16);
    // 0x806DFA0C: lwc1        $f6, 0x5BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X118C));
    // 0x806DFA10: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x806DFA14: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806DFA18: swc1        $f8, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f8.u32l;
    // 0x806DFA1C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x806DFA20: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x806DFA24: nop

    // 0x806DFA28: bc1fl       L_806DFA6C
    if (!c1cs) {
        // 0x806DFA2C: lw          $t6, 0x180($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X180);
            goto L_806DFA6C;
    }
    goto skip_0;
    // 0x806DFA2C: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    skip_0:
    // 0x806DFA30: b           L_806DFA68
    // 0x806DFA34: swc1        $f12, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f12.u32l;
        goto L_806DFA68;
    // 0x806DFA34: swc1        $f12, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f12.u32l;
L_806DFA38:
    // 0x806DFA38: lwc1        $f12, 0x5C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1190));
    // 0x806DFA3C: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1194) << 16);
    // 0x806DFA40: lwc1        $f18, 0x5C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1194));
    // 0x806DFA44: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x806DFA48: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806DFA4C: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x806DFA50: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x806DFA54: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x806DFA58: nop

    // 0x806DFA5C: bc1fl       L_806DFA6C
    if (!c1cs) {
        // 0x806DFA60: lw          $t6, 0x180($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X180);
            goto L_806DFA6C;
    }
    goto skip_1;
    // 0x806DFA60: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    skip_1:
    // 0x806DFA64: swc1        $f12, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f12.u32l;
L_806DFA68:
    // 0x806DFA68: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
L_806DFA6C:
    // 0x806DFA6C: bnel        $a1, $t6, L_806DFB00
    if (ctx->r5 != ctx->r14) {
        // 0x806DFA70: swc1        $f2, 0x18($v1)
        MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
            goto L_806DFB00;
    }
    goto skip_2;
    // 0x806DFA70: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x806DFA74: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806DFA78: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X1198) << 16);
    // 0x806DFA7C: lwc1        $f16, 0x5C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X1198));
    // 0x806DFA80: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x806DFA84: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806DFA88: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    // 0x806DFA8C: lw          $a0, 0x1E0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1E0);
    // 0x806DFA90: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x806DFA94: bne         $at, $zero, L_806DFAC0
    if (ctx->r1 != 0) {
        // 0x806DFA98: nop
    
            goto L_806DFAC0;
    }
    // 0x806DFA98: nop

    // 0x806DFA9C: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806DFAA0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X119C) << 16);
    // 0x806DFAA4: lwc1        $f8, 0x5CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X119C));
    // 0x806DFAA8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806DFAAC: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806DFAB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806DFAB4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x806DFAB8: b           L_806DFAF0
    // 0x806DFABC: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
        goto L_806DFAF0;
    // 0x806DFABC: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
L_806DFAC0:
    // 0x806DFAC0: blezl       $a0, L_806DFAF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x806DFAC4: swc1        $f2, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
            goto L_806DFAF0;
    }
    goto skip_3;
    // 0x806DFAC4: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x806DFAC8: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806DFACC: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11A0) << 16);
    // 0x806DFAD0: lwc1        $f8, 0x5D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11A0));
    // 0x806DFAD4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806DFAD8: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806DFADC: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806DFAE0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x806DFAE4: b           L_806DFAF0
    // 0x806DFAE8: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
        goto L_806DFAF0;
    // 0x806DFAE8: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x806DFAEC: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
L_806DFAF0:
    // 0x806DFAF0: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x806DFAF4: b           L_806DFB68
    // 0x806DFAF8: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
        goto L_806DFB68;
    // 0x806DFAF8: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x806DFAFC: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
L_806DFB00:
    // 0x806DFB00: lw          $a0, 0x1E0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1E0);
    // 0x806DFB04: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x806DFB08: bne         $at, $zero, L_806DFB34
    if (ctx->r1 != 0) {
        // 0x806DFB0C: nop
    
            goto L_806DFB34;
    }
    // 0x806DFB0C: nop

    // 0x806DFB10: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x806DFB14: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11A4) << 16);
    // 0x806DFB18: lwc1        $f10, 0x5D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11A4));
    // 0x806DFB1C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806DFB20: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806DFB24: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806DFB28: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x806DFB2C: b           L_806DFB64
    // 0x806DFB30: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
        goto L_806DFB64;
    // 0x806DFB30: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
L_806DFB34:
    // 0x806DFB34: blezl       $a0, L_806DFB64
    if (SIGNED(ctx->r4) <= 0) {
        // 0x806DFB38: swc1        $f2, 0x1C($v1)
        MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
            goto L_806DFB64;
    }
    goto skip_4;
    // 0x806DFB38: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    skip_4:
    // 0x806DFB3C: lwc1        $f6, 0x20($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X20);
    // 0x806DFB40: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11A8) << 16);
    // 0x806DFB44: lwc1        $f10, 0x5D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11A8));
    // 0x806DFB48: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806DFB4C: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806DFB50: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806DFB54: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x806DFB58: b           L_806DFB64
    // 0x806DFB5C: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
        goto L_806DFB64;
    // 0x806DFB5C: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x806DFB60: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
L_806DFB64:
    // 0x806DFB64: swc1        $f2, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f2.u32l;
L_806DFB68:
    // 0x806DFB68: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x806DFB6C: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x806DFB70: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x806DFB74: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x806DFB78: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806DFB7C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806DFB80: lui         $at, 0xC188
    ctx->r1 = S32(0XC188 << 16);
    // 0x806DFB84: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x806DFB88: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x806DFB8C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806DFB90: nop

    // 0x806DFB94: bc1fl       L_806DFBA8
    if (!c1cs) {
        // 0x806DFB98: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_806DFBA8;
    }
    goto skip_5;
    // 0x806DFB98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_5:
    // 0x806DFB9C: b           L_806DFBC0
    // 0x806DFBA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_806DFBC0;
    // 0x806DFBA0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806DFBA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_806DFBA8:
    // 0x806DFBA8: nop

    // 0x806DFBAC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806DFBB0: nop

    // 0x806DFBB4: bc1fl       L_806DFBC4
    if (!c1cs) {
        // 0x806DFBB8: swc1        $f0, 0x50($a1)
        MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
            goto L_806DFBC4;
    }
    goto skip_6;
    // 0x806DFBB8: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
    skip_6:
    // 0x806DFBBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806DFBC0:
    // 0x806DFBC0: swc1        $f0, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f0.u32l;
L_806DFBC4:
    // 0x806DFBC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DFBC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DFBCC: jr          $ra
    // 0x806DFBD0: nop

    return;
    // 0x806DFBD0: nop

;}
RECOMP_FUNC void func_8041F390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041F390: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8041F394: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8041F398: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8041F39C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8041F3A0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8041F3A4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8041F3A8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8041F3AC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8041F3B0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8041F3B4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8041F3B8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041F3BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8041F3C0: jal         0x8004700C
    // 0x8041F3C4: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8041F3C4: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    after_0:
    // 0x8041F3C8: beq         $v0, $zero, L_8041F568
    if (ctx->r2 == 0) {
        // 0x8041F3CC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8041F568;
    }
    // 0x8041F3CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8041F3D0: jal         0x8041DB1C
    // 0x8041F3D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8041DB1C(rdram, ctx);
        goto after_1;
    // 0x8041F3D4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8041F3D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8041F3DC: jal         0x8041E9A8
    // 0x8041F3E0: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_8041E9A8(rdram, ctx);
        goto after_2;
    // 0x8041F3E0: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_2:
    // 0x8041F3E4: beql        $v0, $zero, L_8041F56C
    if (ctx->r2 == 0) {
        // 0x8041F3E8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8041F56C;
    }
    goto skip_0;
    // 0x8041F3E8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8041F3EC: jal         0x8041E564
    // 0x8041F3F0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    func_8041E564(rdram, ctx);
        goto after_3;
    // 0x8041F3F0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_3:
    // 0x8041F3F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8041F3F8: bne         $v0, $at, L_8041F45C
    if (ctx->r2 != ctx->r1) {
        // 0x8041F3FC: lui         $s3, 0x800F
        ctx->r19 = S32(0X800F << 16);
            goto L_8041F45C;
    }
    // 0x8041F3FC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8041F400: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041F404: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041F408: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x8041F40C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041F410: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8041F414: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x8041F418: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x8041F41C: sw          $t7, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r15;
    // 0x8041F420: swc1        $f4, 0xDC($s4)
    MEM_W(0XDC, ctx->r20) = ctx->f4.u32l;
    // 0x8041F424: swc1        $f6, 0xE0($s4)
    MEM_W(0XE0, ctx->r20) = ctx->f6.u32l;
    // 0x8041F428: lw          $t8, 0xE88($s3)
    ctx->r24 = MEM_W(ctx->r19, 0XE88);
    // 0x8041F42C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8041F430: bnel        $t9, $zero, L_8041F444
    if (ctx->r25 != 0) {
        // 0x8041F434: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8041F444;
    }
    goto skip_1;
    // 0x8041F434: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
    // 0x8041F438: jal         0x8002FE78
    // 0x8041F43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002FE78(rdram, ctx);
        goto after_4;
    // 0x8041F43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041F440: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8041F444:
    // 0x8041F444: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041F448: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8041F44C: jal         0x8041FE10
    // 0x8041F450: lw          $a3, 0x138($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_5;
    // 0x8041F450: lw          $a3, 0x138($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X138);
    after_5:
    // 0x8041F454: b           L_8041F554
    // 0x8041F458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_8041F554;
    // 0x8041F458: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8041F45C:
    // 0x8041F45C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8041F460: bne         $v0, $at, L_8041F550
    if (ctx->r2 != ctx->r1) {
        // 0x8041F464: lui         $s3, 0x800F
        ctx->r19 = S32(0X800F << 16);
            goto L_8041F550;
    }
    // 0x8041F464: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x8041F468: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x8041F46C: lw          $t0, 0xE70($s3)
    ctx->r8 = MEM_W(ctx->r19, 0XE70);
    // 0x8041F470: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8041F474: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8041F478: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8041F47C: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8041F480: lwc1        $f8, 0x3C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X3C);
    // 0x8041F484: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041F488: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8041F48C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x8041F490: lwc1        $f10, 0x70($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X70);
    // 0x8041F494: lwc1        $f4, 0x40($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X40);
    // 0x8041F498: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3524) << 16);
    // 0x8041F49C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8041F4A0: lwc1        $f10, 0xB84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3524));
    // 0x8041F4A4: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(29, 0X32FC) << 16);
    // 0x8041F4A8: addiu       $t2, $t2, 0x95C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(29, 0X32FC));
    // 0x8041F4AC: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8041F4B0: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8041F4B4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8041F4B8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8041F4BC: addiu       $t4, $zero, 0x4034
    ctx->r12 = ADD32(0, 0X4034);
    // 0x8041F4C0: lui         $s2, 0x8042
    ctx->r18 = S32(RELOC_HI16(29, 0X32FC) << 16);
    // 0x8041F4C4: lwc1        $f24, -0x4($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, -0X4);
    // 0x8041F4C8: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8041F4CC: lwc1        $f8, 0x44($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X44);
    // 0x8041F4D0: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8041F4D4: sh          $t4, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r12;
    // 0x8041F4D8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8041F4DC: addiu       $s2, $s2, 0x95C
    ctx->r18 = ADD32(ctx->r18, (int16_t)RELOC_LO16(29, 0X32FC));
    // 0x8041F4E0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8041F4E4: beq         $v0, $zero, L_8041F538
    if (ctx->r2 == 0) {
        // 0x8041F4E8: swc1        $f16, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
            goto L_8041F538;
    }
    // 0x8041F4E8: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x8041F4EC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8041F4F0: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
L_8041F4F4:
    // 0x8041F4F4: jal         0x80066DE4
    // 0x8041F4F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x8041F4F8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_6:
    // 0x8041F4FC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8041F500: jal         0x80066E88
    // 0x8041F504: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8041F504: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_7:
    // 0x8041F508: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8041F50C: lw          $t5, 0xA68($s3)
    ctx->r13 = MEM_W(ctx->r19, 0XA68);
    // 0x8041F510: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8041F514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8041F518: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8041F51C: lw          $t6, 0x10($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X10);
    // 0x8041F520: lw          $t9, 0x54($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X54);
    // 0x8041F524: jalr        $t9
    // 0x8041F528: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x8041F528: nop

    after_8:
    // 0x8041F52C: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x8041F530: bne         $s0, $s2, L_8041F4F4
    if (ctx->r16 != ctx->r18) {
        // 0x8041F534: add.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
            goto L_8041F4F4;
    }
    // 0x8041F534: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
L_8041F538:
    // 0x8041F538: lw          $a0, 0x34($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X34);
    // 0x8041F53C: jal         0x80067BBC
    // 0x8041F540: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_9;
    // 0x8041F540: lw          $a1, 0x38($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X38);
    after_9:
    // 0x8041F544: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8041F548: jal         0x80067818
    // 0x8041F54C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8041F54C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
L_8041F550:
    // 0x8041F550: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_8041F554:
    // 0x8041F554: jal         0x8041E430
    // 0x8041F558: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_8041E430(rdram, ctx);
        goto after_11;
    // 0x8041F558: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_11:
    // 0x8041F55C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8041F560: jal         0x8041E7D4
    // 0x8041F564: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    func_8041E7D4(rdram, ctx);
        goto after_12;
    // 0x8041F564: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_12:
L_8041F568:
    // 0x8041F568: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8041F56C:
    // 0x8041F56C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8041F570: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8041F574: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8041F578: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8041F57C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8041F580: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8041F584: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8041F588: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8041F58C: jr          $ra
    // 0x8041F590: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8041F590: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80682F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682F54: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682F58: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682F5C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682F60: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682F64: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682F68: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682F6C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682F70: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682F74: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682F78: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682F7C: jr          $ra
    // 0x80682F80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682F80: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80071FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071FF0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80071FF4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80071FF8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80071FFC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80072000: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80072004: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80072008: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007200C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80072010: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80072014: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80072018: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8007201C: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x80072020: addiu       $s4, $s4, -0x5908
    ctx->r20 = ADD32(ctx->r20, -0X5908);
    // 0x80072024: addiu       $s6, $s6, -0x5948
    ctx->r22 = ADD32(ctx->r22, -0X5948);
    // 0x80072028: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x8007202C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80072030:
    // 0x80072030: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80072034: jal         0x800824B0
    // 0x80072038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80072038: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8007203C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80072040: lw          $zero, 0x50($s1)
    (void)(MEM_W(ctx->r17, 0X50));
    // 0x80072044: lw          $s0, 0xA0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XA0);
    // 0x80072048: lhu         $t7, 0x12($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X12);
    // 0x8007204C: lhu         $t8, 0x14($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X14);
    // 0x80072050: lbu         $t0, 0x11($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X11);
    // 0x80072054: lw          $s2, 0x18($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X18);
    // 0x80072058: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007205C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80072060: mflo        $t9
    ctx->r25 = lo;
    // 0x80072064: nop

    // 0x80072068: nop

    // 0x8007206C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072070: mflo        $s3
    ctx->r19 = lo;
    // 0x80072074: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80072078: jal         0x8008AED0
    // 0x8007207C: nop

    osInvalDCache_recomp(rdram, ctx);
        goto after_1;
    // 0x8007207C: nop

    after_1:
    // 0x80072080: lw          $a0, 0x54($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X54);
    // 0x80072084: lw          $t9, 0x50($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X50);
    // 0x80072088: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8007208C: jalr        $t9
    // 0x80072090: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80072090: nop

    after_2:
    // 0x80072094: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80072098: jal         0x80085FE0
    // 0x8007209C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    osWritebackDCache_recomp(rdram, ctx);
        goto after_3;
    // 0x8007209C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800720A0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800720A4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800720A8: jal         0x80082210
    // 0x800720AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800720AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800720B0: b           L_80072030
    // 0x800720B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_80072030;
    // 0x800720B4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800720B8: nop

    // 0x800720BC: nop

    // 0x800720C0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800720C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800720C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800720CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800720D0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800720D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800720D8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800720DC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800720E0: jr          $ra
    // 0x800720E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800720E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8002BF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BF60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002BF64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002BF68: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x8002BF6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BF70: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002BF74: lwc1        $f4, 0xC4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC4);
    // 0x8002BF78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BF7C: lwc1        $f6, -0x7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C);
    // 0x8002BF80: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002BF84: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8002BF88: addiu       $a1, $a1, -0x3558
    ctx->r5 = ADD32(ctx->r5, -0X3558);
    // 0x8002BF8C: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8002BF90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002BF94: jal         0x80028118
    // 0x8002BF98: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002BF98: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002BF9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002BFA0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002BFA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002BFA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002BFAC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8002BFB0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BFB4: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
    // 0x8002BFB8: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
    // 0x8002BFBC: lwc1        $f16, -0x78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78);
    // 0x8002BFC0: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8002BFC4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8002BFC8: swc1        $f16, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f16.u32l;
    // 0x8002BFCC: lwc1        $f18, 0x84($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8002BFD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002BFD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002BFD8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8002BFDC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002BFE0: swc1        $f10, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f10.u32l;
    // 0x8002BFE4: lwc1        $f18, -0x74($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X74);
    // 0x8002BFE8: lwc1        $f16, 0x8C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8002BFEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8002BFF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002BFF4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8002BFF8: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x8002BFFC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002C000: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8002C004: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002C008: swc1        $f10, 0x1B8($t7)
    MEM_W(0X1B8, ctx->r15) = ctx->f10.u32l;
    // 0x8002C00C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C014: jr          $ra
    // 0x8002C018: nop

    return;
    // 0x8002C018: nop

;}
RECOMP_FUNC void func_80675EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675EF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80675EF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675EF8: jal         0x8004700C
    // 0x80675EFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80675EFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80675F00: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80675F04: lw          $v1, 0x180($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X180);
    // 0x80675F08: beql        $v1, $zero, L_80675F74
    if (ctx->r3 == 0) {
        // 0x80675F0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80675F74;
    }
    goto skip_0;
    // 0x80675F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80675F10: beql        $v0, $zero, L_80675F74
    if (ctx->r2 == 0) {
        // 0x80675F14: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80675F74;
    }
    goto skip_1;
    // 0x80675F14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80675F18: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80675F1C: lwc1        $f6, 0x84($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X84);
    // 0x80675F20: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80675F24: jal         0x80065954
    // 0x80675F28: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80675F28: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x80675F2C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80675F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80675F34: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80675F38: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80675F3C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80675F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80675F44: bc1fl       L_80675F74
    if (!c1cs) {
        // 0x80675F48: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80675F74;
    }
    goto skip_2;
    // 0x80675F48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80675F4C: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x80675F50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80675F54: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80675F58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80675F5C: swc1        $f10, 0x3F8($v0)
    MEM_W(0X3F8, ctx->r2) = ctx->f10.u32l;
    // 0x80675F60: jal         0x80677A88
    // 0x80675F64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80677A88(rdram, ctx);
        goto after_2;
    // 0x80675F64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80675F68: b           L_80675F74
    // 0x80675F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80675F74;
    // 0x80675F6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80675F70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80675F74:
    // 0x80675F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675F78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80675F7C: jr          $ra
    // 0x80675F80: nop

    return;
    // 0x80675F80: nop

;}
RECOMP_FUNC void func_80461820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461820: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80461824: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80461828: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8046182C: jal         0x80047090
    // 0x80461830: addiu       $a0, $zero, 0x4501
    ctx->r4 = ADD32(0, 0X4501);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80461830: addiu       $a0, $zero, 0x4501
    ctx->r4 = ADD32(0, 0X4501);
    after_0:
    // 0x80461834: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80461838: bne         $v0, $at, L_80461848
    if (ctx->r2 != ctx->r1) {
        // 0x8046183C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80461848;
    }
    // 0x8046183C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80461840: b           L_804618B8
    // 0x80461844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804618B8;
    // 0x80461844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80461848:
    // 0x80461848: lui         $at, 0x4501
    ctx->r1 = S32(0X4501 << 16);
    // 0x8046184C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80461850: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80461854: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80461858: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8046185C: lui         $a2, 0xC30C
    ctx->r6 = S32(0XC30C << 16);
    // 0x80461860: jal         0x8004613C
    // 0x80461864: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80461864: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x80461868: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x8046186C: bne         $v0, $zero, L_8046187C
    if (ctx->r2 != 0) {
        // 0x80461870: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8046187C;
    }
    // 0x80461870: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80461874: b           L_804618B8
    // 0x80461878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804618B8;
    // 0x80461878: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046187C:
    // 0x8046187C: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x80461880: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80461884: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80461888: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x8046188C: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x80461890: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80461894: jal         0x80047F9C
    // 0x80461898: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80461898: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8046189C: jal         0x80462850
    // 0x804618A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80462850(rdram, ctx);
        goto after_3;
    // 0x804618A0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x804618A4: bnel        $v0, $zero, L_804618B8
    if (ctx->r2 != 0) {
        // 0x804618A8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804618B8;
    }
    goto skip_0;
    // 0x804618A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x804618AC: b           L_804618B8
    // 0x804618B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804618B8;
    // 0x804618B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804618B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804618B8:
    // 0x804618B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804618BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804618C0: jr          $ra
    // 0x804618C4: nop

    return;
    // 0x804618C4: nop

;}
RECOMP_FUNC void func_807922BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807922BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807922C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807922C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807922C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807922CC: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x807922D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807922D4: jal         0x807903C4
    // 0x807922D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x807922D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807922DC: jal         0x80790714
    // 0x807922E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x807922E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x807922E4: beq         $v0, $zero, L_80792314
    if (ctx->r2 == 0) {
        // 0x807922E8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80792314;
    }
    // 0x807922E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807922EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807922F0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x807922F4: jal         0x8079393C
    // 0x807922F8: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x807922F8: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    after_2:
    // 0x807922FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80792300: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x80792304: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x80792308: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8079230C: jal         0x807907AC
    // 0x80792310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_807907AC(rdram, ctx);
        goto after_3;
    // 0x80792310: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_80792314:
    // 0x80792314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80792318: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079231C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80792320: jr          $ra
    // 0x80792324: nop

    return;
    // 0x80792324: nop

;}
RECOMP_FUNC void func_806F6D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6D90: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x806F6D94: addiu       $at, $zero, 0x45EC
    ctx->r1 = ADD32(0, 0X45EC);
    // 0x806F6D98: beq         $v0, $at, L_806F6DB0
    if (ctx->r2 == ctx->r1) {
        // 0x806F6D9C: addiu       $at, $zero, 0x45ED
        ctx->r1 = ADD32(0, 0X45ED);
            goto L_806F6DB0;
    }
    // 0x806F6D9C: addiu       $at, $zero, 0x45ED
    ctx->r1 = ADD32(0, 0X45ED);
    // 0x806F6DA0: beq         $v0, $at, L_806F6DBC
    if (ctx->r2 == ctx->r1) {
        // 0x806F6DA4: nop
    
            goto L_806F6DBC;
    }
    // 0x806F6DA4: nop

    // 0x806F6DA8: b           L_806F6DC8
    // 0x806F6DAC: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(691, 0X5A8) << 16);
        goto L_806F6DC8;
    // 0x806F6DAC: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(691, 0X5A8) << 16);
L_806F6DB0:
    // 0x806F6DB0: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(691, 0X5A8) << 16);
    // 0x806F6DB4: jr          $ra
    // 0x806F6DB8: addiu       $v0, $v0, 0x7338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(691, 0X5A8));
    return;
    // 0x806F6DB8: addiu       $v0, $v0, 0x7338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(691, 0X5A8));
L_806F6DBC:
    // 0x806F6DBC: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(691, 0X5F4) << 16);
    // 0x806F6DC0: jr          $ra
    // 0x806F6DC4: addiu       $v0, $v0, 0x7384
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(691, 0X5F4));
    return;
    // 0x806F6DC4: addiu       $v0, $v0, 0x7384
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(691, 0X5F4));
L_806F6DC8:
    // 0x806F6DC8: addiu       $v0, $v0, 0x7338
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(691, 0X5A8));
    // 0x806F6DCC: jr          $ra
    // 0x806F6DD0: nop

    return;
    // 0x806F6DD0: nop

;}
RECOMP_FUNC void func_806F34EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F34EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F34F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F34F4: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x806F34F8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X908) << 16);
    // 0x806F34FC: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806F3500: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x806F3504: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x806F3508: lwc1        $f14, 0x3D58($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X908));
    // 0x806F350C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806F3510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F3514: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(682, 0X914) << 16);
    // 0x806F3518: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x806F351C: mul.s       $f16, $f14, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x806F3520: lwc1        $f18, 0x3D64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(682, 0X914));
    // 0x806F3524: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x806F3528: nop

    // 0x806F352C: bc1fl       L_806F3540
    if (!c1cs) {
        // 0x806F3530: sub.s       $f6, $f14, $f2
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
            goto L_806F3540;
    }
    goto skip_0;
    // 0x806F3530: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    skip_0:
    // 0x806F3534: b           L_806F3588
    // 0x806F3538: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
        goto L_806F3588;
    // 0x806F3538: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x806F353C: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
L_806F3540:
    // 0x806F3540: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x806F3544: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F3548: sub.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x806F354C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x806F3550: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x806F3554: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x806F3558: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806F355C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x806F3560: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x806F3564: nop

    // 0x806F3568: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x806F356C: jal         0x80066DE4
    // 0x806F3570: nop

    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x806F3570: nop

    after_0:
    // 0x806F3574: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x806F3578: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806F357C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806F3580: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x806F3584: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
L_806F3588:
    // 0x806F3588: add.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x806F358C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x806F3590: nop

    // 0x806F3594: bc1fl       L_806F35A4
    if (!c1cs) {
        // 0x806F3598: swc1        $f2, 0x74($a0)
        MEM_W(0X74, ctx->r4) = ctx->f2.u32l;
            goto L_806F35A4;
    }
    goto skip_1;
    // 0x806F3598: swc1        $f2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f2.u32l;
    skip_1:
    // 0x806F359C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x806F35A0: swc1        $f2, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f2.u32l;
L_806F35A4:
    // 0x806F35A4: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x806F35A8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x806F35AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F35B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F35B4: jr          $ra
    // 0x806F35B8: nop

    return;
    // 0x806F35B8: nop

;}
RECOMP_FUNC void func_8002ECF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ECF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002ECF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002ECF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002ECFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002ED00: jal         0x8002DBA8
    // 0x8002ED04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002DBA8(rdram, ctx);
        goto after_0;
    // 0x8002ED04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002ED08: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002ED0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002ED10: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x8002ED14: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002ED18: lwc1        $f6, 0xC8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x8002ED1C: swc1        $f6, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f6.u32l;
    // 0x8002ED20: lwc1        $f8, 0xCC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x8002ED24: swc1        $f8, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f8.u32l;
    // 0x8002ED28: sb          $zero, 0x21($v0)
    MEM_B(0X21, ctx->r2) = 0;
    // 0x8002ED2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002ED30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002ED34: jr          $ra
    // 0x8002ED38: nop

    return;
    // 0x8002ED38: nop

;}
RECOMP_FUNC void func_800013D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800013D4: sra         $t0, $a3, 4
    ctx->r8 = S32(SIGNED(ctx->r7) >> 4);
    // 0x800013D8: andi        $t0, $t0, 0xFF
    ctx->r8 = ctx->r8 & 0XFF;
    // 0x800013DC: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x800013E0: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x800013E4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x800013E8: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800013EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800013F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800013F4: or          $t7, $t0, $t6
    ctx->r15 = ctx->r8 | ctx->r14;
    // 0x800013F8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800013FC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x80001400: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80001404: addiu       $t5, $t5, 0x4D10
    ctx->r13 = ADD32(ctx->r13, 0X4D10);
    // 0x80001408: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000140C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80001410: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80001414: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80001418: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000141C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80001420: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80001424: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80001428: lw          $t6, 0x38($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X38);
    // 0x8000142C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80001430: sll         $t2, $a2, 1
    ctx->r10 = S32(ctx->r6 << 1);
    // 0x80001434: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80001438: addiu       $t9, $a1, 0x1A0
    ctx->r25 = ADD32(ctx->r5, 0X1A0);
    // 0x8000143C: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80001440: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x80001444: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x80001448: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8000144C: addiu       $t3, $a0, 0x8
    ctx->r11 = ADD32(ctx->r4, 0X8);
    // 0x80001450: or          $t6, $t0, $t5
    ctx->r14 = ctx->r8 | ctx->r13;
    // 0x80001454: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x80001458: lw          $t7, 0x3C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X3C);
    // 0x8000145C: addiu       $v0, $t3, 0x8
    ctx->r2 = ADD32(ctx->r11, 0X8);
    // 0x80001460: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80001464: addu        $t9, $t8, $t4
    ctx->r25 = ADD32(ctx->r24, ctx->r12);
    // 0x80001468: jr          $ra
    // 0x8000146C: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    return;
    // 0x8000146C: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
;}
RECOMP_FUNC void func_8006AC94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AC94: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8006AC98: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006AC9C: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006ACA0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8006ACA4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006ACA8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8006ACAC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8006ACB0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8006ACB4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006ACB8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8006ACBC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006ACC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006ACC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006ACC8: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8006ACCC: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8006ACD0: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006ACD4: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x8006ACD8: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8006ACDC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006ACE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8006ACE4: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x8006ACE8: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006ACEC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8006ACF0: addiu       $a1, $zero, 0x3CD
    ctx->r5 = ADD32(0, 0X3CD);
    // 0x8006ACF4: lw          $t2, 0x1B0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006ACF8: lw          $s3, 0x20($t2)
    ctx->r19 = MEM_W(ctx->r10, 0X20);
    // 0x8006ACFC: bne         $a0, $zero, L_8006AD18
    if (ctx->r4 != 0) {
        // 0x8006AD00: lh          $t1, 0x16($s3)
        ctx->r9 = MEM_H(ctx->r19, 0X16);
            goto L_8006AD18;
    }
    // 0x8006AD00: lh          $t1, 0x16($s3)
    ctx->r9 = MEM_H(ctx->r19, 0X16);
    // 0x8006AD04: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8006AD08: jal         0x80071380
    // 0x8006AD0C: addiu       $a0, $a0, 0x1020
    ctx->r4 = ADD32(ctx->r4, 0X1020);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8006AD0C: addiu       $a0, $a0, 0x1020
    ctx->r4 = ADD32(ctx->r4, 0X1020);
    after_0:
    // 0x8006AD10: b           L_8006ADF8
    // 0x8006AD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006ADF8;
    // 0x8006AD14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006AD18:
    // 0x8006AD18: blez        $s4, L_8006ADF4
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8006AD1C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006ADF4;
    }
    // 0x8006AD1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006AD20: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x8006AD24: addiu       $s7, $sp, 0x5C
    ctx->r23 = ADD32(ctx->r29, 0X5C);
    // 0x8006AD28: addiu       $s6, $sp, 0x5E
    ctx->r22 = ADD32(ctx->r29, 0X5E);
    // 0x8006AD2C: lhu         $s5, 0x7A($sp)
    ctx->r21 = MEM_HU(ctx->r29, 0X7A);
    // 0x8006AD30: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_8006AD34:
    // 0x8006AD34: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x8006AD38: bne         $at, $zero, L_8006ADA8
    if (ctx->r1 != 0) {
        // 0x8006AD3C: slt         $at, $s0, $s4
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_8006ADA8;
    }
    // 0x8006AD3C: slt         $at, $s0, $s4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8006AD40: beq         $at, $zero, L_8006ADA8
    if (ctx->r1 == 0) {
        // 0x8006AD44: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8006ADA8;
    }
    // 0x8006AD44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8006AD48: lh          $t3, 0x72($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X72);
    // 0x8006AD4C: sll         $a3, $s2, 16
    ctx->r7 = S32(ctx->r18 << 16);
    // 0x8006AD50: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8006AD54: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x8006AD58: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8006AD5C: sw          $t1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r9;
    // 0x8006AD60: jal         0x8006AB7C
    // 0x8006AD64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_8006AB7C(rdram, ctx);
        goto after_1;
    // 0x8006AD64: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x8006AD68: bne         $fp, $v0, L_8006AD78
    if (ctx->r30 != ctx->r2) {
        // 0x8006AD6C: lw          $t1, 0x60($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X60);
            goto L_8006AD78;
    }
    // 0x8006AD6C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8006AD70: b           L_8006ADF8
    // 0x8006AD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8006ADF8;
    // 0x8006AD74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006AD78:
    // 0x8006AD78: lh          $t8, 0x5C($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5C);
    // 0x8006AD7C: lh          $t5, 0x5E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5E);
    // 0x8006AD80: lw          $t4, 0x24($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X24);
    // 0x8006AD84: multu       $t1, $t8
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006AD88: andi        $t0, $s2, 0xF
    ctx->r8 = ctx->r18 & 0XF;
    // 0x8006AD8C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8006AD90: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006AD94: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8006AD98: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8006AD9C: mflo        $t9
    ctx->r25 = lo;
    // 0x8006ADA0: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8006ADA4: addu        $v1, $t7, $t2
    ctx->r3 = ADD32(ctx->r15, ctx->r10);
L_8006ADA8:
    // 0x8006ADA8: lhu         $t3, 0x0($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X0);
    // 0x8006ADAC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8006ADB0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8006ADB4: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x8006ADB8: xor         $v0, $s5, $t5
    ctx->r2 = ctx->r21 ^ ctx->r13;
    // 0x8006ADBC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8006ADC0: beq         $v0, $zero, L_8006ADD0
    if (ctx->r2 == 0) {
        // 0x8006ADC4: sh          $t3, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = ctx->r11;
            goto L_8006ADD0;
    }
    // 0x8006ADC4: sh          $t3, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r11;
    // 0x8006ADC8: b           L_8006ADF8
    // 0x8006ADCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006ADF8;
    // 0x8006ADCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006ADD0:
    // 0x8006ADD0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8006ADD4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006ADD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006ADDC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8006ADE0: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006ADE4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8006ADE8: bne         $s0, $s4, L_8006AD34
    if (ctx->r16 != ctx->r20) {
        // 0x8006ADEC: sra         $t0, $t0, 16
        ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
            goto L_8006AD34;
    }
    // 0x8006ADEC: sra         $t0, $t0, 16
    ctx->r8 = S32(SIGNED(ctx->r8) >> 16);
    // 0x8006ADF0: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
L_8006ADF4:
    // 0x8006ADF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006ADF8:
    // 0x8006ADF8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8006ADFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006AE00: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006AE04: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006AE08: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AE0C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8006AE10: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006AE14: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8006AE18: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8006AE1C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8006AE20: jr          $ra
    // 0x8006AE24: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8006AE24: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_804A4DA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4DA4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4DA8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4DAC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4DB0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4DB4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4DB8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4DBC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4DC0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4DC4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4DC8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4DCC: jr          $ra
    // 0x804A4DD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4DD0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804BAFF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BAFF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BAFFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BB000: lh          $t6, 0x184($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X184);
    // 0x804BB004: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804BB008: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804BB00C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x804BB010: beq         $at, $zero, L_804BB044
    if (ctx->r1 == 0) {
        // 0x804BB014: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_804BB044;
    }
    // 0x804BB014: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804BB018: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x804BB01C: jal         0x804BAF2C
    // 0x804BB020: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_804BAF2C(rdram, ctx);
        goto after_0;
    // 0x804BB020: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x804BB024: beq         $v0, $zero, L_804BB064
    if (ctx->r2 == 0) {
        // 0x804BB028: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_804BB064;
    }
    // 0x804BB028: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x804BB02C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804BB030: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB034: jal         0x804BB4C4
    // 0x804BB038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_804BB4C4(rdram, ctx);
        goto after_1;
    // 0x804BB038: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x804BB03C: b           L_804BB068
    // 0x804BB040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804BB068;
    // 0x804BB040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB044:
    // 0x804BB044: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804BB048: lw          $a0, 0x16C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X16C);
    // 0x804BB04C: jal         0x804BAFE4
    // 0x804BB050: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_804BAFE4(rdram, ctx);
        goto after_2;
    // 0x804BB050: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x804BB054: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BB058: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BB05C: jal         0x804BB4C4
    // 0x804BB060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_804BB4C4(rdram, ctx);
        goto after_3;
    // 0x804BB060: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
L_804BB064:
    // 0x804BB064: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BB068:
    // 0x804BB068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BB06C: jr          $ra
    // 0x804BB070: nop

    return;
    // 0x804BB070: nop

;}
RECOMP_FUNC void func_8007638C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007638C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80076390: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80076394: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80076398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007639C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800763A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x800763A4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800763A8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800763AC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800763B0: beql        $t8, $zero, L_800764C8
    if (ctx->r24 == 0) {
        // 0x800763B4: lw          $t6, 0xC($s0)
        ctx->r14 = MEM_W(ctx->r16, 0XC);
            goto L_800764C8;
    }
    goto skip_0;
    // 0x800763B4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800763B8: lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10);
    // 0x800763BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800763C0: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800763C4: beq         $t9, $zero, L_800763DC
    if (ctx->r25 == 0) {
        // 0x800763C8: andi        $t0, $v0, 0x4
        ctx->r8 = ctx->r2 & 0X4;
            goto L_800763DC;
    }
    // 0x800763C8: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x800763CC: jal         0x800765B0
    // 0x800763D0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_800765B0(rdram, ctx);
        goto after_0;
    // 0x800763D0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_0:
    // 0x800763D4: b           L_8007657C
    // 0x800763D8: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
        goto L_8007657C;
    // 0x800763D8: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
L_800763DC:
    // 0x800763DC: beq         $t0, $zero, L_80076420
    if (ctx->r8 == 0) {
        // 0x800763E0: andi        $t5, $v0, 0x20
        ctx->r13 = ctx->r2 & 0X20;
            goto L_80076420;
    }
    // 0x800763E0: andi        $t5, $v0, 0x20
    ctx->r13 = ctx->r2 & 0X20;
    // 0x800763E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800763E8: addiu       $v0, $v0, -0x260C
    ctx->r2 = ADD32(ctx->r2, -0X260C);
    // 0x800763EC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800763F0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800763F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800763F8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x800763FC: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80076400: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80076404: jalr        $t9
    // 0x80076408: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80076408: nop

    after_1:
    // 0x8007640C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80076410: lw          $t3, -0x260C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X260C);
    // 0x80076414: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x80076418: b           L_80076578
    // 0x8007641C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
        goto L_80076578;
    // 0x8007641C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80076420:
    // 0x80076420: beq         $t5, $zero, L_80076470
    if (ctx->r13 == 0) {
        // 0x80076424: andi        $t1, $v0, 0x88
        ctx->r9 = ctx->r2 & 0X88;
            goto L_80076470;
    }
    // 0x80076424: andi        $t1, $v0, 0x88
    ctx->r9 = ctx->r2 & 0X88;
    // 0x80076428: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8007642C: jal         0x800762E8
    // 0x80076430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800762E8(rdram, ctx);
        goto after_2;
    // 0x80076430: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80076434: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80076438: addiu       $v0, $v0, -0x260C
    ctx->r2 = ADD32(ctx->r2, -0X260C);
    // 0x8007643C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80076440: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80076444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076448: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x8007644C: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80076450: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80076454: jalr        $t9
    // 0x80076458: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80076458: nop

    after_3:
    // 0x8007645C: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80076460: lw          $t8, -0x260C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X260C);
    // 0x80076464: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80076468: b           L_80076578
    // 0x8007646C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
        goto L_80076578;
    // 0x8007646C: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_80076470:
    // 0x80076470: beq         $t1, $zero, L_800764BC
    if (ctx->r9 == 0) {
        // 0x80076474: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_800764BC;
    }
    // 0x80076474: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80076478: jal         0x800762E8
    // 0x8007647C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800762E8(rdram, ctx);
        goto after_4;
    // 0x8007647C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80076480: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80076484: addiu       $v0, $v0, -0x260C
    ctx->r2 = ADD32(ctx->r2, -0X260C);
    // 0x80076488: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8007648C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80076490: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80076494: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80076498: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8007649C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800764A0: jalr        $t9
    // 0x800764A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800764A4: nop

    after_5:
    // 0x800764A8: lui         $t4, 0x8011
    ctx->r12 = S32(0X8011 << 16);
    // 0x800764AC: lw          $t4, -0x260C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X260C);
    // 0x800764B0: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x800764B4: b           L_80076578
    // 0x800764B8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_80076578;
    // 0x800764B8: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_800764BC:
    // 0x800764BC: b           L_800764BC
    pause_self(rdram);
    // 0x800764C0: nop

    // 0x800764C4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800764C8:
    // 0x800764C8: beql        $t6, $zero, L_8007657C
    if (ctx->r14 == 0) {
        // 0x800764CC: lhu         $t3, 0x10($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X10);
            goto L_8007657C;
    }
    goto skip_1;
    // 0x800764CC: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
    skip_1:
    // 0x800764D0: lhu         $v0, 0x10($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X10);
    // 0x800764D4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800764D8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800764DC: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x800764E0: beq         $t7, $zero, L_80076504
    if (ctx->r15 == 0) {
        // 0x800764E4: andi        $t3, $v0, 0x88
        ctx->r11 = ctx->r2 & 0X88;
            goto L_80076504;
    }
    // 0x800764E4: andi        $t3, $v0, 0x88
    ctx->r11 = ctx->r2 & 0X88;
    // 0x800764E8: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800764EC: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800764F0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x800764F4: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800764F8: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x800764FC: b           L_8007657C
    // 0x80076500: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
        goto L_8007657C;
    // 0x80076500: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
L_80076504:
    // 0x80076504: beq         $t3, $zero, L_8007653C
    if (ctx->r11 == 0) {
        // 0x80076508: andi        $t7, $v0, 0x20
        ctx->r15 = ctx->r2 & 0X20;
            goto L_8007653C;
    }
    // 0x80076508: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8007650C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80076510: jal         0x800762E8
    // 0x80076514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800762E8(rdram, ctx);
        goto after_6;
    // 0x80076514: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80076518: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007651C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80076520: addiu       $t4, $t9, 0x8
    ctx->r12 = ADD32(ctx->r25, 0X8);
    // 0x80076524: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80076528: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x8007652C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80076530: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80076534: b           L_8007657C
    // 0x80076538: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
        goto L_8007657C;
    // 0x80076538: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
L_8007653C:
    // 0x8007653C: beq         $t7, $zero, L_80076570
    if (ctx->r15 == 0) {
        // 0x80076540: addiu       $a0, $sp, 0x34
        ctx->r4 = ADD32(ctx->r29, 0X34);
            goto L_80076570;
    }
    // 0x80076540: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80076544: jal         0x800762E8
    // 0x80076548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800762E8(rdram, ctx);
        goto after_7;
    // 0x80076548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8007654C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x80076550: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80076554: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x80076558: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8007655C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80076560: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x80076564: sw          $t2, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r10;
    // 0x80076568: b           L_8007657C
    // 0x8007656C: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
        goto L_8007657C;
    // 0x8007656C: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
L_80076570:
    // 0x80076570: b           L_80076570
    pause_self(rdram);
    // 0x80076574: nop

L_80076578:
    // 0x80076578: lhu         $t3, 0x10($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X10);
L_8007657C:
    // 0x8007657C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80076580: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076584: andi        $t9, $t3, 0x40
    ctx->r25 = ctx->r11 & 0X40;
    // 0x80076588: bnel        $t9, $zero, L_80076598
    if (ctx->r25 != 0) {
        // 0x8007658C: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_80076598;
    }
    goto skip_2;
    // 0x8007658C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x80076590: sw          $t4, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->r12;
    // 0x80076594: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80076598:
    // 0x80076598: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8007659C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800765A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800765A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800765A8: jr          $ra
    // 0x800765AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800765AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80534FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534FE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80534FE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534FEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80534FF0: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x80534FF4: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(348, 0X1040) << 16);
    // 0x80534FF8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80534FFC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80535000: lw          $t9, 0x5650($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(348, 0X1040));
    // 0x80535004: jalr        $t9
    // 0x80535008: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80535008: nop

    after_0:
    // 0x8053500C: jal         0x8053484C
    // 0x80535010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8053484C(rdram, ctx);
        goto after_1;
    // 0x80535010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80535014: jal         0x80534678
    // 0x80535018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80534678(rdram, ctx);
        goto after_2;
    // 0x80535018: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8053501C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535020: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535024: jr          $ra
    // 0x80535028: nop

    return;
    // 0x80535028: nop

;}
RECOMP_FUNC void func_806EFBD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFBD8: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x806EFBDC: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EFBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EFBE4: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x806EFBE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EFBEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806EFBF0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EFBF4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D80) << 16);
    // 0x806EFBF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EFBFC: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x806EFC00: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EFC04: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806EFC08: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x806EFC0C: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x806EFC10: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x806EFC14: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x806EFC18: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x806EFC1C: nop

    // 0x806EFC20: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x806EFC24: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806EFC28: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x806EFC2C: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806EFC30: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806EFC34: lwc1        $f4, 0xCD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D80));
    // 0x806EFC38: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D84) << 16);
    // 0x806EFC3C: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806EFC40: nop

    // 0x806EFC44: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806EFC48: lwc1        $f4, 0xCD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D84));
    // 0x806EFC4C: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
    // 0x806EFC50: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D88) << 16);
    // 0x806EFC54: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x806EFC58: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x806EFC5C: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x806EFC60: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806EFC64: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x806EFC68: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806EFC6C: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x806EFC70: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806EFC74: lwc1        $f8, 0xCD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D88));
    // 0x806EFC78: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806EFC7C: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806EFC80: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EFC84: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x806EFC88: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EFC8C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x806EFC90: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EFC94: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x806EFC98: nop

    // 0x806EFC9C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x806EFCA0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x806EFCA4: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x806EFCA8: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x806EFCAC: nop

    // 0x806EFCB0: bc1f        L_806EFCBC
    if (!c1cs) {
        // 0x806EFCB4: nop
    
            goto L_806EFCBC;
    }
    // 0x806EFCB4: nop

    // 0x806EFCB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EFCBC:
    // 0x806EFCBC: jr          $ra
    // 0x806EFCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806EFCC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8042F574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F574: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F578: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042F57C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042F580: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8042F584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F588: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8042F58C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8042F590: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042F594: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042F598: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8042F59C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042F5A0: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8042F5A4: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X35FC) << 16);
    // 0x8042F5A8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042F5AC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8042F5B0: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042F5B4: lw          $t2, 0x16DC($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X35FC));
    // 0x8042F5B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042F5BC: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8042F5C0: jal         0x8042F060
    // 0x8042F5C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042F060(rdram, ctx);
        goto after_0;
    // 0x8042F5C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F5C8: jal         0x8042F0BC
    // 0x8042F5CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042F0BC(rdram, ctx);
        goto after_1;
    // 0x8042F5CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042F5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F5D8: jr          $ra
    // 0x8042F5DC: nop

    return;
    // 0x8042F5DC: nop

;}
RECOMP_FUNC void func_80680410(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680410: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80680414: addiu       $at, $zero, 0x4578
    ctx->r1 = ADD32(0, 0X4578);
    // 0x80680418: beq         $v0, $at, L_80680450
    if (ctx->r2 == ctx->r1) {
        // 0x8068041C: addiu       $at, $zero, 0x4579
        ctx->r1 = ADD32(0, 0X4579);
            goto L_80680450;
    }
    // 0x8068041C: addiu       $at, $zero, 0x4579
    ctx->r1 = ADD32(0, 0X4579);
    // 0x80680420: beq         $v0, $at, L_8068045C
    if (ctx->r2 == ctx->r1) {
        // 0x80680424: addiu       $at, $zero, 0x457A
        ctx->r1 = ADD32(0, 0X457A);
            goto L_8068045C;
    }
    // 0x80680424: addiu       $at, $zero, 0x457A
    ctx->r1 = ADD32(0, 0X457A);
    // 0x80680428: beq         $v0, $at, L_80680468
    if (ctx->r2 == ctx->r1) {
        // 0x8068042C: addiu       $at, $zero, 0x457B
        ctx->r1 = ADD32(0, 0X457B);
            goto L_80680468;
    }
    // 0x8068042C: addiu       $at, $zero, 0x457B
    ctx->r1 = ADD32(0, 0X457B);
    // 0x80680430: beq         $v0, $at, L_80680480
    if (ctx->r2 == ctx->r1) {
        // 0x80680434: addiu       $at, $zero, 0x4595
        ctx->r1 = ADD32(0, 0X4595);
            goto L_80680480;
    }
    // 0x80680434: addiu       $at, $zero, 0x4595
    ctx->r1 = ADD32(0, 0X4595);
    // 0x80680438: beq         $v0, $at, L_80680474
    if (ctx->r2 == ctx->r1) {
        // 0x8068043C: addiu       $at, $zero, 0x4596
        ctx->r1 = ADD32(0, 0X4596);
            goto L_80680474;
    }
    // 0x8068043C: addiu       $at, $zero, 0x4596
    ctx->r1 = ADD32(0, 0X4596);
    // 0x80680440: beq         $v0, $at, L_8068048C
    if (ctx->r2 == ctx->r1) {
        // 0x80680444: nop
    
            goto L_8068048C;
    }
    // 0x80680444: nop

    // 0x80680448: b           L_80680498
    // 0x8068044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680498;
    // 0x8068044C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680450:
    // 0x80680450: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X834) << 16);
    // 0x80680454: jr          $ra
    // 0x80680458: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
    return;
    // 0x80680458: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
L_8068045C:
    // 0x8068045C: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X834) << 16);
    // 0x80680460: jr          $ra
    // 0x80680464: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
    return;
    // 0x80680464: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
L_80680468:
    // 0x80680468: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X834) << 16);
    // 0x8068046C: jr          $ra
    // 0x80680470: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
    return;
    // 0x80680470: addiu       $v0, $v0, 0xC44
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X834));
L_80680474:
    // 0x80680474: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X111C) << 16);
    // 0x80680478: jr          $ra
    // 0x8068047C: addiu       $v0, $v0, 0x152C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X111C));
    return;
    // 0x8068047C: addiu       $v0, $v0, 0x152C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X111C));
L_80680480:
    // 0x80680480: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X154C) << 16);
    // 0x80680484: jr          $ra
    // 0x80680488: addiu       $v0, $v0, 0x195C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X154C));
    return;
    // 0x80680488: addiu       $v0, $v0, 0x195C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X154C));
L_8068048C:
    // 0x8068048C: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(550, 0X1C60) << 16);
    // 0x80680490: jr          $ra
    // 0x80680494: addiu       $v0, $v0, 0x2070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X1C60));
    return;
    // 0x80680494: addiu       $v0, $v0, 0x2070
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(550, 0X1C60));
L_80680498:
    // 0x80680498: jr          $ra
    // 0x8068049C: nop

    return;
    // 0x8068049C: nop

;}
RECOMP_FUNC void func_804C20D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C20D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C20D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C20DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C20E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804C20E4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804C20E8: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804C20EC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804C20F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804C20F4: bne         $v0, $at, L_804C2104
    if (ctx->r2 != ctx->r1) {
        // 0x804C20F8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_804C2104;
    }
    // 0x804C20F8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804C20FC: jal         0x8002F6E4
    // 0x804C2100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x804C2100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_804C2104:
    // 0x804C2104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C2108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C210C: jr          $ra
    // 0x804C2110: nop

    return;
    // 0x804C2110: nop

;}
RECOMP_FUNC void func_805D37C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D37C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D37CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D37D0: jal         0x805D3358
    // 0x805D37D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805D3358(rdram, ctx);
        goto after_0;
    // 0x805D37D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805D37D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D37DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D37E0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805D37E4: jal         0x805D3B18
    // 0x805D37E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_805D3B18(rdram, ctx);
        goto after_1;
    // 0x805D37E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x805D37EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D37F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D37F4: jr          $ra
    // 0x805D37F8: nop

    return;
    // 0x805D37F8: nop

;}
RECOMP_FUNC void func_807B9034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9034: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9038: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B903C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x807B9040: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B9044: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807B9048: beql        $v1, $zero, L_807B9064
    if (ctx->r3 == 0) {
        // 0x807B904C: lbu         $t6, 0xFB8($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0XFB8);
            goto L_807B9064;
    }
    goto skip_0;
    // 0x807B904C: lbu         $t6, 0xFB8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XFB8);
    skip_0:
    // 0x807B9050: beq         $v1, $at, L_807B9070
    if (ctx->r3 == ctx->r1) {
        // 0x807B9054: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_807B9070;
    }
    // 0x807B9054: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B9058: jr          $ra
    // 0x807B905C: nop

    return;
    // 0x807B905C: nop

    // 0x807B9060: lbu         $t6, 0xFB8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XFB8);
L_807B9064:
    // 0x807B9064: andi        $t7, $t6, 0xFFF3
    ctx->r15 = ctx->r14 & 0XFFF3;
    // 0x807B9068: jr          $ra
    // 0x807B906C: sb          $t7, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r15;
    return;
    // 0x807B906C: sb          $t7, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r15;
L_807B9070:
    // 0x807B9070: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807B9074: lbu         $t8, 0xFB8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XFB8);
    // 0x807B9078: andi        $t9, $t8, 0xFFF3
    ctx->r25 = ctx->r24 & 0XFFF3;
    // 0x807B907C: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x807B9080: sb          $t0, 0xFB8($v0)
    MEM_B(0XFB8, ctx->r2) = ctx->r8;
    // 0x807B9084: jr          $ra
    // 0x807B9088: nop

    return;
    // 0x807B9088: nop

;}
RECOMP_FUNC void func_8041D7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041D7EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041D7F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041D7F4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8041D7F8: lui         $t6, 0x8042
    ctx->r14 = S32(RELOC_HI16(29, 0X354) << 16);
    // 0x8041D7FC: addiu       $t6, $t6, -0x264C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(29, 0X354));
    // 0x8041D800: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8041D804: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    // 0x8041D808: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8041D80C: beql        $v0, $zero, L_8041D858
    if (ctx->r2 == 0) {
        // 0x8041D810: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8041D858;
    }
    goto skip_0;
    // 0x8041D810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8041D814: lhu         $t9, 0xC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XC);
    // 0x8041D818: addiu       $at, $zero, 0x45CB
    ctx->r1 = ADD32(0, 0X45CB);
    // 0x8041D81C: bnel        $t9, $at, L_8041D844
    if (ctx->r25 != ctx->r1) {
        // 0x8041D820: lw          $t3, 0x174($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X174);
            goto L_8041D844;
    }
    goto skip_1;
    // 0x8041D820: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    skip_1:
    // 0x8041D824: jal         0x8005FD1C
    // 0x8041D828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8041D828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8041D82C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041D830: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x8041D834: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8041D838: b           L_8041D854
    // 0x8041D83C: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
        goto L_8041D854;
    // 0x8041D83C: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x8041D840: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
L_8041D844:
    // 0x8041D844: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8041D848: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8041D84C: jal         0x8005FCA8
    // 0x8041D850: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x8041D850: sh          $t2, 0x12($t4)
    MEM_H(0X12, ctx->r12) = ctx->r10;
    after_1:
L_8041D854:
    // 0x8041D854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8041D858:
    // 0x8041D858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041D85C: jr          $ra
    // 0x8041D860: nop

    return;
    // 0x8041D860: nop

;}
RECOMP_FUNC void func_80041698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041698: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004169C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800416A0: jal         0x800309B8
    // 0x800416A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800309B8(rdram, ctx);
        goto after_0;
    // 0x800416A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800416A8: beq         $v0, $zero, L_800416B8
    if (ctx->r2 == 0) {
        // 0x800416AC: nop
    
            goto L_800416B8;
    }
    // 0x800416AC: nop

    // 0x800416B0: b           L_80041704
    // 0x800416B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041704;
    // 0x800416B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800416B8:
    // 0x800416B8: jal         0x800415D0
    // 0x800416BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415D0(rdram, ctx);
        goto after_1;
    // 0x800416BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800416C0: beq         $v0, $zero, L_800416D0
    if (ctx->r2 == 0) {
        // 0x800416C4: nop
    
            goto L_800416D0;
    }
    // 0x800416C4: nop

    // 0x800416C8: b           L_80041704
    // 0x800416CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041704;
    // 0x800416CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800416D0:
    // 0x800416D0: jal         0x8003200C
    // 0x800416D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003200C(rdram, ctx);
        goto after_2;
    // 0x800416D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800416D8: beq         $v0, $zero, L_800416E8
    if (ctx->r2 == 0) {
        // 0x800416DC: nop
    
            goto L_800416E8;
    }
    // 0x800416DC: nop

    // 0x800416E0: b           L_80041704
    // 0x800416E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041704;
    // 0x800416E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800416E8:
    // 0x800416E8: jal         0x8003BEC8
    // 0x800416EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8003BEC8(rdram, ctx);
        goto after_3;
    // 0x800416EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800416F0: beql        $v0, $zero, L_80041704
    if (ctx->r2 == 0) {
        // 0x800416F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80041704;
    }
    goto skip_0;
    // 0x800416F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800416F8: b           L_80041704
    // 0x800416FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80041704;
    // 0x800416FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80041700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80041704:
    // 0x80041704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004170C: jr          $ra
    // 0x80041710: nop

    return;
    // 0x80041710: nop

;}
RECOMP_FUNC void func_80054530(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054530: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80054538: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8005453C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054540: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80054544: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80054548: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8005454C: addiu       $a0, $zero, 0x108
    ctx->r4 = ADD32(0, 0X108);
    // 0x80054550: mflo        $t0
    ctx->r8 = lo;
    // 0x80054554: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80054558: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8005455C: beql        $at, $zero, L_8005457C
    if (ctx->r1 == 0) {
        // 0x80054560: slti        $at, $v0, 0x31
        ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
            goto L_8005457C;
    }
    goto skip_0;
    // 0x80054560: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
    skip_0:
    // 0x80054564: jal         0x80064D1C
    // 0x80054568: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x80054568: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8005456C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80054570: b           L_800545A0
    // 0x80054574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800545A0;
    // 0x80054574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80054578: slti        $at, $v0, 0x31
    ctx->r1 = SIGNED(ctx->r2) < 0X31 ? 1 : 0;
L_8005457C:
    // 0x8005457C: beq         $at, $zero, L_80054598
    if (ctx->r1 == 0) {
        // 0x80054580: addiu       $a0, $zero, 0x308
        ctx->r4 = ADD32(0, 0X308);
            goto L_80054598;
    }
    // 0x80054580: addiu       $a0, $zero, 0x308
    ctx->r4 = ADD32(0, 0X308);
    // 0x80054584: jal         0x80064D1C
    // 0x80054588: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x80054588: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8005458C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80054590: b           L_800545A0
    // 0x80054594: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800545A0;
    // 0x80054594: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80054598:
    // 0x80054598: b           L_800545E4
    // 0x8005459C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800545E4;
    // 0x8005459C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800545A0:
    // 0x800545A0: bne         $v0, $zero, L_800545B0
    if (ctx->r2 != 0) {
        // 0x800545A4: addiu       $a0, $v1, 0x8
        ctx->r4 = ADD32(ctx->r3, 0X8);
            goto L_800545B0;
    }
    // 0x800545A4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800545A8: b           L_800545E4
    // 0x800545AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800545E4;
    // 0x800545AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800545B0:
    // 0x800545B0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800545B4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800545B8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800545BC: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800545C0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x800545C4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800545C8: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800545CC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800545D0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800545D4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800545D8: jal         0x80053A20
    // 0x800545DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80053A20(rdram, ctx);
        goto after_2;
    // 0x800545DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x800545E0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_800545E4:
    // 0x800545E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800545E8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800545EC: jr          $ra
    // 0x800545F0: nop

    return;
    // 0x800545F0: nop

;}
RECOMP_FUNC void func_8042DE2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042DE2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042DE30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042DE34: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042DE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042DE3C: beq         $t6, $zero, L_8042DE78
    if (ctx->r14 == 0) {
        // 0x8042DE40: nop
    
            goto L_8042DE78;
    }
    // 0x8042DE40: nop

    // 0x8042DE44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042DE48: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042DE4C: jalr        $t9
    // 0x8042DE50: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042DE50: nop

    after_0:
    // 0x8042DE54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042DE58: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042DE5C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042DE60: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042DE64: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042DE68: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042DE6C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042DE70: b           L_8042DE78
    // 0x8042DE74: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042DE78;
    // 0x8042DE74: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042DE78:
    // 0x8042DE78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042DE7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042DE80: jr          $ra
    // 0x8042DE84: nop

    return;
    // 0x8042DE84: nop

;}
RECOMP_FUNC void func_80069728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069728: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8006972C: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x80069730: lw          $v0, 0xFBC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XFBC);
    // 0x80069734: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80069738: sllv        $t7, $t6, $a0
    ctx->r15 = S32(ctx->r14 << (ctx->r4 & 31));
    // 0x8006973C: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x80069740: beq         $t8, $zero, L_80069764
    if (ctx->r24 == 0) {
        // 0x80069744: addiu       $t9, $a0, 0x1F
        ctx->r25 = ADD32(ctx->r4, 0X1F);
            goto L_80069764;
    }
    // 0x80069744: addiu       $t9, $a0, 0x1F
    ctx->r25 = ADD32(ctx->r4, 0X1F);
    // 0x80069748: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8006974C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80069750: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80069754: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80069758: xor         $t2, $t1, $at
    ctx->r10 = ctx->r9 ^ ctx->r1;
    // 0x8006975C: and         $v1, $v0, $t2
    ctx->r3 = ctx->r2 & ctx->r10;
    // 0x80069760: sw          $v1, 0xFBC($a1)
    MEM_W(0XFBC, ctx->r5) = ctx->r3;
L_80069764:
    // 0x80069764: jr          $ra
    // 0x80069768: nop

    return;
    // 0x80069768: nop

;}
