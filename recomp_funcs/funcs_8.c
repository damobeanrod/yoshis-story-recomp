#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8058475C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058475C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584760: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584764: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584768: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058476C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584770: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584774: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584778: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058477C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584780: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584784: jr          $ra
    // 0x80584788: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584788: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F21E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F21E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F21EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F21F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F21F4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F21F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F21FC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x806F2200: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F2204: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F2208: jal         0x80065ABC
    // 0x806F220C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F220C: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    after_0:
    // 0x806F2210: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806F2214: jal         0x806F1F6C
    // 0x806F2218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F1F6C(rdram, ctx);
        goto after_1;
    // 0x806F2218: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F221C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806F2220: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806F2224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F2228: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x806F222C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2230: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806F2234: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F2238: nop

    // 0x806F223C: bc1fl       L_806F2274
    if (!c1cs) {
        // 0x806F2240: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2274;
    }
    goto skip_0;
    // 0x806F2240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F2244: jal         0x806F2554
    // 0x806F2248: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F2554(rdram, ctx);
        goto after_2;
    // 0x806F2248: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
    // 0x806F224C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x806F2250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F2254: jal         0x806F1FC8
    // 0x806F2258: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    func_806F1FC8(rdram, ctx);
        goto after_3;
    // 0x806F2258: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x806F225C: jal         0x800447C8
    // 0x806F2260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x806F2260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F2264: addiu       $t8, $zero, 0x4B0
    ctx->r24 = ADD32(0, 0X4B0);
    // 0x806F2268: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F226C: sw          $t8, -0x6C78($at)
    MEM_W(-0X6C78, ctx->r1) = ctx->r24;
    // 0x806F2270: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2274:
    // 0x806F2274: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F2278: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F227C: jr          $ra
    // 0x806F2280: nop

    return;
    // 0x806F2280: nop

;}
RECOMP_FUNC void func_80565518(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565518: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8056551C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80565520: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80565524: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80565528: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8056552C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80565530: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80565534: beq         $v0, $at, L_8056554C
    if (ctx->r2 == ctx->r1) {
        // 0x80565538: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_8056554C;
    }
    // 0x80565538: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x8056553C: beql        $v0, $at, L_805655D4
    if (ctx->r2 == ctx->r1) {
        // 0x80565540: lbu         $t7, 0x18($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X18);
            goto L_805655D4;
    }
    goto skip_0;
    // 0x80565540: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    skip_0:
    // 0x80565544: b           L_80565660
    // 0x80565548: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80565660;
    // 0x80565548: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8056554C:
    // 0x8056554C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80565550: lui         $t3, 0x8056
    ctx->r11 = S32(RELOC_HI16(369, 0X13D8) << 16);
    // 0x80565554: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x80565558: lhu         $v0, 0x52C($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X52C);
    // 0x8056555C: addiu       $t3, $t3, 0x4C38
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(369, 0X13D8));
    // 0x80565560: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80565564: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80565568: beq         $t8, $zero, L_805655A0
    if (ctx->r24 == 0) {
        // 0x8056556C: andi        $t5, $v0, 0x2
        ctx->r13 = ctx->r2 & 0X2;
            goto L_805655A0;
    }
    // 0x8056556C: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x80565570: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x80565574: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80565578: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8056557C: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(369, 0X143C) << 16);
    // 0x80565580: addiu       $t0, $t0, 0x4C9C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(369, 0X143C));
    // 0x80565584: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x80565588: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8056558C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80565590: jal         0x8056512C
    // 0x80565594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8056512C(rdram, ctx);
        goto after_0;
    // 0x80565594: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80565598: b           L_80565660
    // 0x8056559C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80565660;
    // 0x8056559C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_805655A0:
    // 0x805655A0: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x805655A4: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x805655A8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x805655AC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x805655B0: sltiu       $t6, $t5, 0x1
    ctx->r14 = ctx->r13 < 0X1 ? 1 : 0;
    // 0x805655B4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x805655B8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x805655BC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x805655C0: jal         0x8056512C
    // 0x805655C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8056512C(rdram, ctx);
        goto after_1;
    // 0x805655C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x805655C8: b           L_80565660
    // 0x805655CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80565660;
    // 0x805655CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x805655D0: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
L_805655D4:
    // 0x805655D4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805655D8: bnel        $t7, $at, L_80565660
    if (ctx->r15 != ctx->r1) {
        // 0x805655DC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80565660;
    }
    goto skip_1;
    // 0x805655DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x805655E0: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x805655E4: lui         $t5, 0x8056
    ctx->r13 = S32(RELOC_HI16(369, 0X15B4) << 16);
    // 0x805655E8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x805655EC: lhu         $v0, 0x52C($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X52C);
    // 0x805655F0: addiu       $t5, $t5, 0x4E14
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(369, 0X15B4));
    // 0x805655F4: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x805655F8: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x805655FC: beq         $t0, $zero, L_80565634
    if (ctx->r8 == 0) {
        // 0x80565600: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_80565634;
    }
    // 0x80565600: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x80565604: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80565608: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8056560C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80565610: lui         $t2, 0x8056
    ctx->r10 = S32(RELOC_HI16(369, 0X166C) << 16);
    // 0x80565614: addiu       $t2, $t2, 0x4ECC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(369, 0X166C));
    // 0x80565618: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8056561C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80565620: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80565624: jal         0x8056512C
    // 0x80565628: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8056512C(rdram, ctx);
        goto after_2;
    // 0x80565628: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8056562C: b           L_80565660
    // 0x80565630: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80565660;
    // 0x80565630: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80565634:
    // 0x80565634: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80565638: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8056563C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80565640: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80565644: sltiu       $t8, $t7, 0x1
    ctx->r24 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80565648: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8056564C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80565650: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80565654: jal         0x8056512C
    // 0x80565658: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8056512C(rdram, ctx);
        goto after_3;
    // 0x80565658: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8056565C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80565660:
    // 0x80565660: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80565664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80565668: jr          $ra
    // 0x8056566C: nop

    return;
    // 0x8056566C: nop

;}
RECOMP_FUNC void func_805D1A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D1A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1A38: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x805D1A3C: slti        $at, $v0, 0x4528
    ctx->r1 = SIGNED(ctx->r2) < 0X4528 ? 1 : 0;
    // 0x805D1A40: bne         $at, $zero, L_805D1AF8
    if (ctx->r1 != 0) {
        // 0x805D1A44: slti        $at, $v0, 0x45B3
        ctx->r1 = SIGNED(ctx->r2) < 0X45B3 ? 1 : 0;
            goto L_805D1AF8;
    }
    // 0x805D1A44: slti        $at, $v0, 0x45B3
    ctx->r1 = SIGNED(ctx->r2) < 0X45B3 ? 1 : 0;
    // 0x805D1A48: bne         $at, $zero, L_805D1A8C
    if (ctx->r1 != 0) {
        // 0x805D1A4C: slti        $at, $v0, 0x45D6
        ctx->r1 = SIGNED(ctx->r2) < 0X45D6 ? 1 : 0;
            goto L_805D1A8C;
    }
    // 0x805D1A4C: slti        $at, $v0, 0x45D6
    ctx->r1 = SIGNED(ctx->r2) < 0X45D6 ? 1 : 0;
    // 0x805D1A50: bne         $at, $zero, L_805D1A6C
    if (ctx->r1 != 0) {
        // 0x805D1A54: addiu       $t6, $v0, -0x45CC
        ctx->r14 = ADD32(ctx->r2, -0X45CC);
            goto L_805D1A6C;
    }
    // 0x805D1A54: addiu       $t6, $v0, -0x45CC
    ctx->r14 = ADD32(ctx->r2, -0X45CC);
    // 0x805D1A58: addiu       $at, $zero, 0x46DA
    ctx->r1 = ADD32(0, 0X46DA);
    // 0x805D1A5C: beq         $v0, $at, L_805D1BD8
    if (ctx->r2 == ctx->r1) {
        // 0x805D1A60: lui         $t3, 0x805D
        ctx->r11 = S32(RELOC_HI16(471, 0X2164) << 16);
            goto L_805D1BD8;
    }
    // 0x805D1A60: lui         $t3, 0x805D
    ctx->r11 = S32(RELOC_HI16(471, 0X2164) << 16);
    // 0x805D1A64: b           L_805D1CA8
    // 0x805D1A68: nop

        goto L_805D1CA8;
    // 0x805D1A68: nop

L_805D1A6C:
    // 0x805D1A6C: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x805D1A70: beq         $at, $zero, L_805D1CA8
    if (ctx->r1 == 0) {
        // 0x805D1A74: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805D1CA8;
    }
    // 0x805D1A74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805D1A78: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X24E0) << 16);
    // 0x805D1A7C: addu        $at, $at, $t6
    gpr jr_addend_805D1A84 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805D1A80: lw          $t6, 0x3F10($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(471, 0X24E0));
    // 0x805D1A84: jr          $t6
    // 0x805D1A88: nop

    switch (jr_addend_805D1A84 >> 2) {
        case 0: goto L_805D1C9C; break;
        case 1: goto L_805D1C9C; break;
        case 2: goto L_805D1C9C; break;
        case 3: goto L_805D1C9C; break;
        case 4: goto L_805D1CA8; break;
        case 5: goto L_805D1C84; break;
        case 6: goto L_805D1C9C; break;
        case 7: goto L_805D1C9C; break;
        case 8: goto L_805D1C9C; break;
        case 9: goto L_805D1C9C; break;
        default: switch_error(__func__, 0x805D1A84, 0x805D3F10);
    }
    // 0x805D1A88: nop

L_805D1A8C:
    // 0x805D1A8C: slti        $at, $v0, 0x4571
    ctx->r1 = SIGNED(ctx->r2) < 0X4571 ? 1 : 0;
    // 0x805D1A90: bne         $at, $zero, L_805D1AB8
    if (ctx->r1 != 0) {
        // 0x805D1A94: addiu       $t7, $v0, -0x45AE
        ctx->r15 = ADD32(ctx->r2, -0X45AE);
            goto L_805D1AB8;
    }
    // 0x805D1A94: addiu       $t7, $v0, -0x45AE
    ctx->r15 = ADD32(ctx->r2, -0X45AE);
    // 0x805D1A98: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x805D1A9C: beq         $at, $zero, L_805D1CA8
    if (ctx->r1 == 0) {
        // 0x805D1AA0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_805D1CA8;
    }
    // 0x805D1AA0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805D1AA4: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2508) << 16);
    // 0x805D1AA8: addu        $at, $at, $t7
    gpr jr_addend_805D1AB0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805D1AAC: lw          $t7, 0x3F38($at)
    ctx->r15 = ADD32(ctx->r1, (int16_t)RELOC_LO16(471, 0X2508));
    // 0x805D1AB0: jr          $t7
    // 0x805D1AB4: nop

    switch (jr_addend_805D1AB0 >> 2) {
        case 0: goto L_805D1C78; break;
        case 1: goto L_805D1C9C; break;
        case 2: goto L_805D1C9C; break;
        case 3: goto L_805D1C9C; break;
        case 4: goto L_805D1C9C; break;
        default: switch_error(__func__, 0x805D1AB0, 0x805D3F38);
    }
    // 0x805D1AB4: nop

L_805D1AB8:
    // 0x805D1AB8: slti        $at, $v0, 0x4529
    ctx->r1 = SIGNED(ctx->r2) < 0X4529 ? 1 : 0;
    // 0x805D1ABC: bne         $at, $zero, L_805D1AE4
    if (ctx->r1 != 0) {
        // 0x805D1AC0: addiu       $t8, $v0, -0x4569
        ctx->r24 = ADD32(ctx->r2, -0X4569);
            goto L_805D1AE4;
    }
    // 0x805D1AC0: addiu       $t8, $v0, -0x4569
    ctx->r24 = ADD32(ctx->r2, -0X4569);
    // 0x805D1AC4: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x805D1AC8: beq         $at, $zero, L_805D1CA8
    if (ctx->r1 == 0) {
        // 0x805D1ACC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_805D1CA8;
    }
    // 0x805D1ACC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805D1AD0: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X251C) << 16);
    // 0x805D1AD4: addu        $at, $at, $t8
    gpr jr_addend_805D1ADC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x805D1AD8: lw          $t8, 0x3F4C($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(471, 0X251C));
    // 0x805D1ADC: jr          $t8
    // 0x805D1AE0: nop

    switch (jr_addend_805D1ADC >> 2) {
        case 0: goto L_805D1C9C; break;
        case 1: goto L_805D1C9C; break;
        case 2: goto L_805D1C9C; break;
        case 3: goto L_805D1C9C; break;
        case 4: goto L_805D1C9C; break;
        case 5: goto L_805D1C9C; break;
        case 6: goto L_805D1C9C; break;
        case 7: goto L_805D1C9C; break;
        default: switch_error(__func__, 0x805D1ADC, 0x805D3F4C);
    }
    // 0x805D1AE0: nop

L_805D1AE4:
    // 0x805D1AE4: addiu       $at, $zero, 0x4528
    ctx->r1 = ADD32(0, 0X4528);
    // 0x805D1AE8: beq         $v0, $at, L_805D1C6C
    if (ctx->r2 == ctx->r1) {
        // 0x805D1AEC: nop
    
            goto L_805D1C6C;
    }
    // 0x805D1AEC: nop

    // 0x805D1AF0: b           L_805D1CA8
    // 0x805D1AF4: nop

        goto L_805D1CA8;
    // 0x805D1AF4: nop

L_805D1AF8:
    // 0x805D1AF8: addiu       $at, $zero, 0x4046
    ctx->r1 = ADD32(0, 0X4046);
    // 0x805D1AFC: beq         $v0, $at, L_805D1C10
    if (ctx->r2 == ctx->r1) {
        // 0x805D1B00: lui         $t5, 0x805D
        ctx->r13 = S32(RELOC_HI16(471, 0X216C) << 16);
            goto L_805D1C10;
    }
    // 0x805D1B00: lui         $t5, 0x805D
    ctx->r13 = S32(RELOC_HI16(471, 0X216C) << 16);
    // 0x805D1B04: addiu       $at, $zero, 0x44E2
    ctx->r1 = ADD32(0, 0X44E2);
    // 0x805D1B08: beq         $v0, $at, L_805D1C90
    if (ctx->r2 == ctx->r1) {
        // 0x805D1B0C: addiu       $at, $zero, 0x4525
        ctx->r1 = ADD32(0, 0X4525);
            goto L_805D1C90;
    }
    // 0x805D1B0C: addiu       $at, $zero, 0x4525
    ctx->r1 = ADD32(0, 0X4525);
    // 0x805D1B10: beq         $v0, $at, L_805D1B38
    if (ctx->r2 == ctx->r1) {
        // 0x805D1B14: lui         $t9, 0x805D
        ctx->r25 = S32(RELOC_HI16(471, 0X2168) << 16);
            goto L_805D1B38;
    }
    // 0x805D1B14: lui         $t9, 0x805D
    ctx->r25 = S32(RELOC_HI16(471, 0X2168) << 16);
    // 0x805D1B18: addiu       $at, $zero, 0x4526
    ctx->r1 = ADD32(0, 0X4526);
    // 0x805D1B1C: beq         $v0, $at, L_805D1B88
    if (ctx->r2 == ctx->r1) {
        // 0x805D1B20: lui         $t1, 0x805D
        ctx->r9 = S32(RELOC_HI16(471, 0X2160) << 16);
            goto L_805D1B88;
    }
    // 0x805D1B20: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(471, 0X2160) << 16);
    // 0x805D1B24: addiu       $at, $zero, 0x4527
    ctx->r1 = ADD32(0, 0X4527);
    // 0x805D1B28: beq         $v0, $at, L_805D1C60
    if (ctx->r2 == ctx->r1) {
        // 0x805D1B2C: nop
    
            goto L_805D1C60;
    }
    // 0x805D1B2C: nop

    // 0x805D1B30: b           L_805D1CA8
    // 0x805D1B34: nop

        goto L_805D1CA8;
    // 0x805D1B34: nop

L_805D1B38:
    // 0x805D1B38: lw          $t9, 0x3B98($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(471, 0X2168));
    // 0x805D1B3C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A30) << 16);
    // 0x805D1B40: addiu       $a0, $a0, 0x4460
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A30));
    // 0x805D1B44: bne         $t9, $zero, L_805D1B7C
    if (ctx->r25 != 0) {
        // 0x805D1B48: lui         $a1, 0x805D
        ctx->r5 = S32(RELOC_HI16(471, 0X4350) << 16);
            goto L_805D1B7C;
    }
    // 0x805D1B48: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(471, 0X4350) << 16);
    // 0x805D1B4C: addiu       $a1, $a1, 0x5D80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(471, 0X4350));
    // 0x805D1B50: jal         0x8004667C
    // 0x805D1B54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805D1B54: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x805D1B58: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805D1B5C: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(471, 0X534) << 16);
    // 0x805D1B60: addiu       $a2, $a2, 0x1F64
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(471, 0X534));
    // 0x805D1B64: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805D1B68: jal         0x80057B28
    // 0x805D1B6C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x805D1B6C: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_1:
    // 0x805D1B70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805D1B74: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2168) << 16);
    // 0x805D1B78: sw          $t0, 0x3B98($at)
    MEM_W((int16_t)RELOC_LO16(471, 0X2168), ctx->r1) = ctx->r8;
L_805D1B7C:
    // 0x805D1B7C: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X19A8) << 16);
    // 0x805D1B80: b           L_805D1CB0
    // 0x805D1B84: addiu       $v0, $v0, 0x33D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X19A8));
        goto L_805D1CB0;
    // 0x805D1B84: addiu       $v0, $v0, 0x33D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X19A8));
L_805D1B88:
    // 0x805D1B88: lw          $t1, 0x3B90($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(471, 0X2160));
    // 0x805D1B8C: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A10) << 16);
    // 0x805D1B90: addiu       $a0, $a0, 0x4440
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A10));
    // 0x805D1B94: bne         $t1, $zero, L_805D1BCC
    if (ctx->r9 != 0) {
        // 0x805D1B98: lui         $a1, 0x805D
        ctx->r5 = S32(RELOC_HI16(471, 0X2A50) << 16);
            goto L_805D1BCC;
    }
    // 0x805D1B98: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(471, 0X2A50) << 16);
    // 0x805D1B9C: addiu       $a1, $a1, 0x4480
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(471, 0X2A50));
    // 0x805D1BA0: jal         0x8004667C
    // 0x805D1BA4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_2;
    // 0x805D1BA4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_2:
    // 0x805D1BA8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805D1BAC: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(471, 0X424) << 16);
    // 0x805D1BB0: addiu       $a2, $a2, 0x1E54
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(471, 0X424));
    // 0x805D1BB4: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805D1BB8: jal         0x80057B28
    // 0x805D1BBC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80057B28(rdram, ctx);
        goto after_3;
    // 0x805D1BBC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_3:
    // 0x805D1BC0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805D1BC4: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2160) << 16);
    // 0x805D1BC8: sw          $t2, 0x3B90($at)
    MEM_W((int16_t)RELOC_LO16(471, 0X2160), ctx->r1) = ctx->r10;
L_805D1BCC:
    // 0x805D1BCC: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1B1C) << 16);
    // 0x805D1BD0: b           L_805D1CB0
    // 0x805D1BD4: addiu       $v0, $v0, 0x354C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1B1C));
        goto L_805D1CB0;
    // 0x805D1BD4: addiu       $v0, $v0, 0x354C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1B1C));
L_805D1BD8:
    // 0x805D1BD8: lw          $t3, 0x3B94($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(471, 0X2164));
    // 0x805D1BDC: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A20) << 16);
    // 0x805D1BE0: addiu       $a0, $a0, 0x4450
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A20));
    // 0x805D1BE4: bne         $t3, $zero, L_805D1C04
    if (ctx->r11 != 0) {
        // 0x805D1BE8: lui         $a1, 0x805D
        ctx->r5 = S32(RELOC_HI16(471, 0X36D0) << 16);
            goto L_805D1C04;
    }
    // 0x805D1BE8: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(471, 0X36D0) << 16);
    // 0x805D1BEC: addiu       $a1, $a1, 0x5100
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(471, 0X36D0));
    // 0x805D1BF0: jal         0x8004667C
    // 0x805D1BF4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_4;
    // 0x805D1BF4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
    // 0x805D1BF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805D1BFC: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2164) << 16);
    // 0x805D1C00: sw          $t4, 0x3B94($at)
    MEM_W((int16_t)RELOC_LO16(471, 0X2164), ctx->r1) = ctx->r12;
L_805D1C04:
    // 0x805D1C04: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1B84) << 16);
    // 0x805D1C08: b           L_805D1CB0
    // 0x805D1C0C: addiu       $v0, $v0, 0x35B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1B84));
        goto L_805D1CB0;
    // 0x805D1C0C: addiu       $v0, $v0, 0x35B4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1B84));
L_805D1C10:
    // 0x805D1C10: lw          $t5, 0x3B9C($t5)
    ctx->r13 = MEM_W(ctx->r13, (int16_t)RELOC_LO16(471, 0X216C));
    // 0x805D1C14: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A40) << 16);
    // 0x805D1C18: addiu       $a0, $a0, 0x4470
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A40));
    // 0x805D1C1C: bne         $t5, $zero, L_805D1C54
    if (ctx->r13 != 0) {
        // 0x805D1C20: lui         $a1, 0x805D
        ctx->r5 = S32(RELOC_HI16(471, 0X5250) << 16);
            goto L_805D1C54;
    }
    // 0x805D1C20: lui         $a1, 0x805D
    ctx->r5 = S32(RELOC_HI16(471, 0X5250) << 16);
    // 0x805D1C24: addiu       $a1, $a1, 0x6C80
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(471, 0X5250));
    // 0x805D1C28: jal         0x8004667C
    // 0x805D1C2C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8004667C(rdram, ctx);
        goto after_5;
    // 0x805D1C2C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_5:
    // 0x805D1C30: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x805D1C34: lui         $a2, 0x805D
    ctx->r6 = S32(RELOC_HI16(471, 0X5D4) << 16);
    // 0x805D1C38: addiu       $a2, $a2, 0x2004
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(471, 0X5D4));
    // 0x805D1C3C: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x805D1C40: jal         0x80057B28
    // 0x805D1C44: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    func_80057B28(rdram, ctx);
        goto after_6;
    // 0x805D1C44: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    after_6:
    // 0x805D1C48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805D1C4C: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X216C) << 16);
    // 0x805D1C50: sw          $t6, 0x3B9C($at)
    MEM_W((int16_t)RELOC_LO16(471, 0X216C), ctx->r1) = ctx->r14;
L_805D1C54:
    // 0x805D1C54: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1C20) << 16);
    // 0x805D1C58: b           L_805D1CB0
    // 0x805D1C5C: addiu       $v0, $v0, 0x3650
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1C20));
        goto L_805D1CB0;
    // 0x805D1C5C: addiu       $v0, $v0, 0x3650
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1C20));
L_805D1C60:
    // 0x805D1C60: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1BEC) << 16);
    // 0x805D1C64: b           L_805D1CB0
    // 0x805D1C68: addiu       $v0, $v0, 0x361C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1BEC));
        goto L_805D1CB0;
    // 0x805D1C68: addiu       $v0, $v0, 0x361C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1BEC));
L_805D1C6C:
    // 0x805D1C6C: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1D30) << 16);
    // 0x805D1C70: b           L_805D1CB0
    // 0x805D1C74: addiu       $v0, $v0, 0x3760
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D30));
        goto L_805D1CB0;
    // 0x805D1C74: addiu       $v0, $v0, 0x3760
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D30));
L_805D1C78:
    // 0x805D1C78: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1D64) << 16);
    // 0x805D1C7C: b           L_805D1CB0
    // 0x805D1C80: addiu       $v0, $v0, 0x3794
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D64));
        goto L_805D1CB0;
    // 0x805D1C80: addiu       $v0, $v0, 0x3794
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D64));
L_805D1C84:
    // 0x805D1C84: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1D98) << 16);
    // 0x805D1C88: b           L_805D1CB0
    // 0x805D1C8C: addiu       $v0, $v0, 0x37C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D98));
        goto L_805D1CB0;
    // 0x805D1C8C: addiu       $v0, $v0, 0x37C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1D98));
L_805D1C90:
    // 0x805D1C90: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1DCC) << 16);
    // 0x805D1C94: b           L_805D1CB0
    // 0x805D1C98: addiu       $v0, $v0, 0x37FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1DCC));
        goto L_805D1CB0;
    // 0x805D1C98: addiu       $v0, $v0, 0x37FC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1DCC));
L_805D1C9C:
    // 0x805D1C9C: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X1E00) << 16);
    // 0x805D1CA0: b           L_805D1CB0
    // 0x805D1CA4: addiu       $v0, $v0, 0x3830
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1E00));
        goto L_805D1CB0;
    // 0x805D1CA4: addiu       $v0, $v0, 0x3830
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X1E00));
L_805D1CA8:
    // 0x805D1CA8: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(471, 0X19A8) << 16);
    // 0x805D1CAC: addiu       $v0, $v0, 0x33D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(471, 0X19A8));
L_805D1CB0:
    // 0x805D1CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D1CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1CB8: jr          $ra
    // 0x805D1CBC: nop

    return;
    // 0x805D1CBC: nop

;}
RECOMP_FUNC void func_8052C5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C5E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8052C5E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052C5E8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8052C5EC: addiu       $at, $zero, 0x414C
    ctx->r1 = ADD32(0, 0X414C);
    // 0x8052C5F0: beq         $v0, $at, L_8052C610
    if (ctx->r2 == ctx->r1) {
        // 0x8052C5F4: addiu       $at, $zero, 0x414D
        ctx->r1 = ADD32(0, 0X414D);
            goto L_8052C610;
    }
    // 0x8052C5F4: addiu       $at, $zero, 0x414D
    ctx->r1 = ADD32(0, 0X414D);
    // 0x8052C5F8: beq         $v0, $at, L_8052C620
    if (ctx->r2 == ctx->r1) {
        // 0x8052C5FC: addiu       $at, $zero, 0x414E
        ctx->r1 = ADD32(0, 0X414E);
            goto L_8052C620;
    }
    // 0x8052C5FC: addiu       $at, $zero, 0x414E
    ctx->r1 = ADD32(0, 0X414E);
    // 0x8052C600: beq         $v0, $at, L_8052C630
    if (ctx->r2 == ctx->r1) {
        // 0x8052C604: nop
    
            goto L_8052C630;
    }
    // 0x8052C604: nop

    // 0x8052C608: b           L_8052C63C
    // 0x8052C60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8052C63C;
    // 0x8052C60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052C610:
    // 0x8052C610: jal         0x8052C6F0
    // 0x8052C614: nop

    func_8052C6F0(rdram, ctx);
        goto after_0;
    // 0x8052C614: nop

    after_0:
    // 0x8052C618: b           L_8052C63C
    // 0x8052C61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8052C63C;
    // 0x8052C61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052C620:
    // 0x8052C620: jal         0x8052C928
    // 0x8052C624: nop

    func_8052C928(rdram, ctx);
        goto after_1;
    // 0x8052C624: nop

    after_1:
    // 0x8052C628: b           L_8052C63C
    // 0x8052C62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8052C63C;
    // 0x8052C62C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052C630:
    // 0x8052C630: jal         0x8052D658
    // 0x8052C634: nop

    func_8052D658(rdram, ctx);
        goto after_2;
    // 0x8052C634: nop

    after_2:
    // 0x8052C638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052C63C:
    // 0x8052C63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052C640: jr          $ra
    // 0x8052C644: nop

    return;
    // 0x8052C644: nop

;}
RECOMP_FUNC void func_8003DA30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DA30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DA34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003DA38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003DA3C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003DA40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003DA44: jal         0x8003D9E4
    // 0x8003DA48: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    func_8003D9E4(rdram, ctx);
        goto after_0;
    // 0x8003DA48: lw          $s1, 0x174($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X174);
    after_0:
    // 0x8003DA4C: lw          $t6, 0x4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4);
    // 0x8003DA50: beql        $t6, $zero, L_8003DA64
    if (ctx->r14 == 0) {
        // 0x8003DA54: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_8003DA64;
    }
    goto skip_0;
    // 0x8003DA54: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x8003DA58: jal         0x80061170
    // 0x8003DA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80061170(rdram, ctx);
        goto after_1;
    // 0x8003DA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003DA60: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_8003DA64:
    // 0x8003DA64: lbu         $t8, 0x75($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X75);
    // 0x8003DA68: beql        $t8, $zero, L_8003DA7C
    if (ctx->r24 == 0) {
        // 0x8003DA6C: lw          $t9, 0x180($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X180);
            goto L_8003DA7C;
    }
    goto skip_1;
    // 0x8003DA6C: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    skip_1:
    // 0x8003DA70: jal         0x80060FE0
    // 0x8003DA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_2;
    // 0x8003DA74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003DA78: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
L_8003DA7C:
    // 0x8003DA7C: beq         $t9, $zero, L_8003DA8C
    if (ctx->r25 == 0) {
        // 0x8003DA80: nop
    
            goto L_8003DA8C;
    }
    // 0x8003DA80: nop

    // 0x8003DA84: jal         0x8004816C
    // 0x8003DA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004816C(rdram, ctx);
        goto after_3;
    // 0x8003DA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8003DA8C:
    // 0x8003DA8C: jal         0x8005FE48
    // 0x8003DA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_4;
    // 0x8003DA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003DA94: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8003DA98: sb          $zero, 0x74($t0)
    MEM_B(0X74, ctx->r8) = 0;
    // 0x8003DA9C: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8003DAA0: sb          $zero, 0x75($t1)
    MEM_B(0X75, ctx->r9) = 0;
    // 0x8003DAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DAA8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003DAAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003DAB0: jr          $ra
    // 0x8003DAB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003DAB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80460F94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460F94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80460F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80460F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80460FA0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80460FA4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80460FA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80460FAC: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80460FB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80460FB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80460FB8: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80460FBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80460FC0: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80460FC4: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80460FC8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80460FCC: nop

    // 0x80460FD0: bc1fl       L_80460FE4
    if (!c1cs) {
        // 0x80460FD4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_80460FE4;
    }
    goto skip_0;
    // 0x80460FD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x80460FD8: b           L_8046100C
    // 0x80460FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8046100C;
    // 0x80460FDC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80460FE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_80460FE4:
    // 0x80460FE4: nop

    // 0x80460FE8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80460FEC: nop

    // 0x80460FF0: bc1fl       L_80461004
    if (!c1cs) {
        // 0x80460FF4: trunc.w.s   $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
            goto L_80461004;
    }
    goto skip_1;
    // 0x80460FF4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    skip_1:
    // 0x80460FF8: b           L_8046100C
    // 0x80460FFC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
        goto L_8046100C;
    // 0x80460FFC: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x80461000: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
L_80461004:
    // 0x80461004: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80461008: nop

L_8046100C:
    // 0x8046100C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80461010: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80461014: bne         $a1, $at, L_80461040
    if (ctx->r5 != ctx->r1) {
        // 0x80461018: nop
    
            goto L_80461040;
    }
    // 0x80461018: nop

    // 0x8046101C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80461020: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80461024: jal         0x80067D5C
    // 0x80461028: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x80461028: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8046102C: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80461030: jal         0x80067F78
    // 0x80461034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80461034: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80461038: b           L_804610A0
    // 0x8046103C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_804610A0;
    // 0x8046103C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80461040:
    // 0x80461040: jal         0x80067930
    // 0x80461044: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x80461044: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x80461048: beq         $v0, $zero, L_80461080
    if (ctx->r2 == 0) {
        // 0x8046104C: lw          $a3, 0x24($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X24);
            goto L_80461080;
    }
    // 0x8046104C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80461050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80461054: bne         $v0, $at, L_804610A0
    if (ctx->r2 != ctx->r1) {
        // 0x80461058: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_804610A0;
    }
    // 0x80461058: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8046105C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80461060: jal         0x80067D5C
    // 0x80461064: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x80461064: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80461068: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8046106C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80461070: jal         0x800678F0
    // 0x80461074: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x80461074: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x80461078: b           L_804610A4
    // 0x8046107C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804610A4;
    // 0x8046107C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80461080:
    // 0x80461080: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80461084: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80461088: jal         0x80067D5C
    // 0x8046108C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_5;
    // 0x8046108C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80461090: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x80461094: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80461098: jal         0x80067838
    // 0x8046109C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x8046109C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_804610A0:
    // 0x804610A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804610A4:
    // 0x804610A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804610A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804610AC: jr          $ra
    // 0x804610B0: nop

    return;
    // 0x804610B0: nop

;}
RECOMP_FUNC void func_80049FA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049FA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80049FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80049FAC: lw          $a1, 0x174($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X174);
    // 0x80049FB0: jal         0x80049D74
    // 0x80049FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049D74(rdram, ctx);
        goto after_0;
    // 0x80049FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80049FB8: jal         0x8004E5C8
    // 0x80049FBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004E5C8(rdram, ctx);
        goto after_1;
    // 0x80049FBC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80049FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049FC8: jr          $ra
    // 0x80049FCC: nop

    return;
    // 0x80049FCC: nop

;}
RECOMP_FUNC void func_805CF1A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CF1A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805CF1AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805CF1B0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x805CF1B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805CF1B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805CF1BC: lhu         $a1, 0x26($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X26);
    // 0x805CF1C0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x805CF1C4: lui         $at, 0x4071
    ctx->r1 = S32(0X4071 << 16);
    // 0x805CF1C8: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x805CF1CC: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(459, 0X3D0) << 16);
    // 0x805CF1D0: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x805CF1D4: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x805CF1D8: addiu       $a0, $a0, -0xD20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(459, 0X3D0));
    // 0x805CF1DC: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
    // 0x805CF1E0: jal         0x80046804
    // 0x805CF1E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805CF1E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805CF1E8: bne         $v0, $zero, L_805CF1F8
    if (ctx->r2 != 0) {
        // 0x805CF1EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_805CF1F8;
    }
    // 0x805CF1EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x805CF1F0: b           L_805CF1FC
    // 0x805CF1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CF1FC;
    // 0x805CF1F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CF1F8:
    // 0x805CF1F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_805CF1FC:
    // 0x805CF1FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805CF200: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805CF204: jr          $ra
    // 0x805CF208: nop

    return;
    // 0x805CF208: nop

    // 0x805CF20C: nop

;}
RECOMP_FUNC void func_80045A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045A34: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80045A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045A3C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80045A40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045A44: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80045A48: beq         $t7, $zero, L_80045A70
    if (ctx->r15 == 0) {
        // 0x80045A4C: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80045A70;
    }
    // 0x80045A4C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80045A50: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045A54: addiu       $a0, $a0, 0x6A0
    ctx->r4 = ADD32(ctx->r4, 0X6A0);
    // 0x80045A58: addiu       $a1, $zero, 0x246
    ctx->r5 = ADD32(0, 0X246);
    // 0x80045A5C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80045A60: jal         0x80071380
    // 0x80045A64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80045A64: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80045A68: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80045A6C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
L_80045A70:
    // 0x80045A70: lw          $t8, 0x1F4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X1F4);
    // 0x80045A74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045A78: addiu       $a0, $a0, 0x6B0
    ctx->r4 = ADD32(ctx->r4, 0X6B0);
    // 0x80045A7C: beq         $t8, $zero, L_80045A9C
    if (ctx->r24 == 0) {
        // 0x80045A80: sltiu       $at, $a2, 0x31
        ctx->r1 = ctx->r6 < 0X31 ? 1 : 0;
            goto L_80045A9C;
    }
    // 0x80045A80: sltiu       $at, $a2, 0x31
    ctx->r1 = ctx->r6 < 0X31 ? 1 : 0;
    // 0x80045A84: addiu       $a1, $zero, 0x24F
    ctx->r5 = ADD32(0, 0X24F);
    // 0x80045A88: jal         0x80071380
    // 0x80045A8C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80045A8C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x80045A90: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80045A94: b           L_80045AD8
    // 0x80045A98: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
        goto L_80045AD8;
    // 0x80045A98: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
L_80045A9C:
    // 0x80045A9C: beq         $at, $zero, L_80045AD0
    if (ctx->r1 == 0) {
        // 0x80045AA0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80045AD0;
    }
    // 0x80045AA0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80045AA4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80045AA8: addiu       $a0, $a3, 0x24C
    ctx->r4 = ADD32(ctx->r7, 0X24C);
    // 0x80045AAC: sb          $t9, 0x1F2($a3)
    MEM_B(0X1F2, ctx->r7) = ctx->r25;
    // 0x80045AB0: sw          $a0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r4;
    // 0x80045AB4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80045AB8: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80045ABC: jal         0x80065728
    // 0x80045AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x80045AC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80045AC4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80045AC8: b           L_80045AD8
    // 0x80045ACC: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
        goto L_80045AD8;
    // 0x80045ACC: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
L_80045AD0:
    // 0x80045AD0: jal         0x80064DD0
    // 0x80045AD4: sb          $zero, 0x1F2($a3)
    MEM_B(0X1F2, ctx->r7) = 0;
    func_80064DD0(rdram, ctx);
        goto after_3;
    // 0x80045AD4: sb          $zero, 0x1F2($a3)
    MEM_B(0X1F2, ctx->r7) = 0;
    after_3:
L_80045AD8:
    // 0x80045AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80045ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045AE0: jr          $ra
    // 0x80045AE4: nop

    return;
    // 0x80045AE4: nop

;}
RECOMP_FUNC void func_800786D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800786D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800786D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800786DC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800786E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800786E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800786E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800786EC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800786F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800786F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800786F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800786FC: beq         $a3, $zero, L_80078718
    if (ctx->r7 == 0) {
        // 0x80078700: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_80078718;
    }
    // 0x80078700: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80078704: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80078708: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007870C: sw          $a3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r7;
    // 0x80078710: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80078714: sw          $t0, -0x7A20($at)
    MEM_W(-0X7A20, ctx->r1) = ctx->r8;
L_80078718:
    // 0x80078718: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007871C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80078720: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80078724: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x80078728: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8007872C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80078730: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x80078734: sll         $a3, $v0, 24
    ctx->r7 = S32(ctx->r2 << 24);
    // 0x80078738: srl         $a3, $a3, 24
    ctx->r7 = S32(U32(ctx->r7) >> 24);
    // 0x8007873C: srl         $a2, $a2, 24
    ctx->r6 = S32(U32(ctx->r6) >> 24);
    // 0x80078740: jal         0x80078584
    // 0x80078744: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    func_80078584(rdram, ctx);
        goto after_0;
    // 0x80078744: addu        $a0, $t2, $t4
    ctx->r4 = ADD32(ctx->r10, ctx->r12);
    after_0:
    // 0x80078748: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8007874C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80078750: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80078754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078758: jr          $ra
    // 0x8007875C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007875C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800190D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800190D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800190D8: jal         0x80019AC4
    // 0x800190DC: nop

    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x800190DC: nop

    after_0:
    // 0x800190E0: beq         $v0, $zero, L_800190EC
    if (ctx->r2 == 0) {
        // 0x800190E4: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800190EC;
    }
    // 0x800190E4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800190E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800190EC:
    // 0x800190EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800190F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800190F4: jr          $ra
    // 0x800190F8: nop

    return;
    // 0x800190F8: nop

;}
RECOMP_FUNC void func_804289D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804289D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804289DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804289E0: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804289E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804289E8: beq         $t6, $zero, L_80428A24
    if (ctx->r14 == 0) {
        // 0x804289EC: nop
    
            goto L_80428A24;
    }
    // 0x804289EC: nop

    // 0x804289F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804289F4: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804289F8: jalr        $t9
    // 0x804289FC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804289FC: nop

    after_0:
    // 0x80428A00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80428A04: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80428A08: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80428A0C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80428A10: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80428A14: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80428A18: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80428A1C: b           L_80428A24
    // 0x80428A20: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80428A24;
    // 0x80428A20: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80428A24:
    // 0x80428A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428A2C: jr          $ra
    // 0x80428A30: nop

    return;
    // 0x80428A30: nop

;}
RECOMP_FUNC void func_8066DF78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066DF78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8066DF7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8066DF80: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8066DF84: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8066DF88: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8066DF8C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8066DF90: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(517, 0X2A54) << 16);
    // 0x8066DF94: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8066DF98: beq         $v0, $zero, L_8066DFA8
    if (ctx->r2 == 0) {
        // 0x8066DF9C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8066DFA8;
    }
    // 0x8066DF9C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8066DFA0: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x8066DFA4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8066DFA8:
    // 0x8066DFA8: bnel        $v0, $zero, L_8066E0F0
    if (ctx->r2 != 0) {
        // 0x8066DFAC: lw          $v0, 0x20($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X20);
            goto L_8066E0F0;
    }
    goto skip_0;
    // 0x8066DFAC: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x8066DFB0: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x8066DFB4: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(517, 0X2950) << 16);
    // 0x8066DFB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8066DFBC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8066DFC0: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8066DFC4: lw          $t7, 0x14($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(517, 0X2A54));
    // 0x8066DFC8: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8066DFCC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x8066DFD0: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x8066DFD4: lw          $t8, -0xF0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(517, 0X2950));
    // 0x8066DFD8: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x8066DFDC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8066DFE0: bne         $t9, $at, L_8066E054
    if (ctx->r25 != ctx->r1) {
        // 0x8066DFE4: sw          $t8, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r24;
            goto L_8066E054;
    }
    // 0x8066DFE4: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x8066DFE8: jal         0x80047090
    // 0x8066DFEC: addiu       $a0, $zero, 0x4559
    ctx->r4 = ADD32(0, 0X4559);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8066DFEC: addiu       $a0, $zero, 0x4559
    ctx->r4 = ADD32(0, 0X4559);
    after_0:
    // 0x8066DFF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8066DFF4: lui         $at, 0x4559
    ctx->r1 = S32(0X4559 << 16);
    // 0x8066DFF8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8066DFFC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8066E000: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8066E004: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8066E008: jal         0x8004613C
    // 0x8066E00C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8066E00C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x8066E010: beq         $v0, $zero, L_8066E050
    if (ctx->r2 == 0) {
        // 0x8066E014: sw          $v0, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r2;
            goto L_8066E050;
    }
    // 0x8066E014: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8066E018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E01C: jal         0x80047F9C
    // 0x8066E020: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8066E020: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8066E024: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8066E028: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8066E02C: sb          $t0, 0x17C($t1)
    MEM_B(0X17C, ctx->r9) = ctx->r8;
    // 0x8066E030: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x8066E034: jal         0x80067BBC
    // 0x8066E038: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8066E038: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_3:
    // 0x8066E03C: addiu       $a0, $zero, 0x255
    ctx->r4 = ADD32(0, 0X255);
    // 0x8066E040: jal         0x80067818
    // 0x8066E044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8066E044: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8066E048: b           L_8066E054
    // 0x8066E04C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
        goto L_8066E054;
    // 0x8066E04C: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_8066E050:
    // 0x8066E050: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_8066E054:
    // 0x8066E054: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8066E058: bnel        $v0, $at, L_8066E0BC
    if (ctx->r2 != ctx->r1) {
        // 0x8066E05C: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_8066E0BC;
    }
    goto skip_1;
    // 0x8066E05C: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    skip_1:
    // 0x8066E060: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8066E064: beql        $a2, $zero, L_8066E0BC
    if (ctx->r6 == 0) {
        // 0x8066E068: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_8066E0BC;
    }
    goto skip_2;
    // 0x8066E068: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    skip_2:
    // 0x8066E06C: lw          $t2, 0x180($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X180);
    // 0x8066E070: bnel        $s1, $t2, L_8066E0BC
    if (ctx->r17 != ctx->r10) {
        // 0x8066E074: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_8066E0BC;
    }
    goto skip_3;
    // 0x8066E074: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    skip_3:
    // 0x8066E078: jal         0x8004816C
    // 0x8066E07C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8004816C(rdram, ctx);
        goto after_5;
    // 0x8066E07C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_5:
    // 0x8066E080: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8066E084: lw          $t3, 0x138($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X138);
    // 0x8066E088: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8066E08C: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x8066E090: sw          $t3, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r11;
    // 0x8066E094: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8066E098: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x8066E09C: lw          $a1, 0x38($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X38);
    // 0x8066E0A0: jal         0x80067BBC
    // 0x8066E0A4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8066E0A4: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    after_6:
    // 0x8066E0A8: addiu       $a0, $zero, 0x23C
    ctx->r4 = ADD32(0, 0X23C);
    // 0x8066E0AC: jal         0x80067818
    // 0x8066E0B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8066E0B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8066E0B4: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x8066E0B8: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
L_8066E0BC:
    // 0x8066E0BC: bne         $at, $zero, L_8066E0EC
    if (ctx->r1 != 0) {
        // 0x8066E0C0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8066E0EC;
    }
    // 0x8066E0C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8066E0C4: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8066E0C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8066E0CC: jal         0x8066E4C8
    // 0x8066E0D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_8066E4C8(rdram, ctx);
        goto after_8;
    // 0x8066E0D0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x8066E0D4: jal         0x8066DB84
    // 0x8066E0D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8066DB84(rdram, ctx);
        goto after_9;
    // 0x8066E0D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8066E0DC: jal         0x8066D8D8
    // 0x8066E0E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8066D8D8(rdram, ctx);
        goto after_10;
    // 0x8066E0E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8066E0E4: b           L_8066E19C
    // 0x8066E0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8066E19C;
    // 0x8066E0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E0EC:
    // 0x8066E0EC: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
L_8066E0F0:
    // 0x8066E0F0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8066E0F4: bne         $at, $zero, L_8066E188
    if (ctx->r1 != 0) {
        // 0x8066E0F8: slti        $at, $v0, 0xC
        ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
            goto L_8066E188;
    }
    // 0x8066E0F8: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x8066E0FC: beq         $at, $zero, L_8066E188
    if (ctx->r1 == 0) {
        // 0x8066E100: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8066E188;
    }
    // 0x8066E100: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8066E104: lw          $t5, 0x138($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X138);
    // 0x8066E108: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8066E10C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8066E110: beq         $t5, $zero, L_8066E124
    if (ctx->r13 == 0) {
        // 0x8066E114: lw          $a2, 0x14($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X14);
            goto L_8066E124;
    }
    // 0x8066E114: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8066E118: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8066E11C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8066E120: nop

L_8066E124:
    // 0x8066E124: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8066E128: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8066E12C: lui         $t8, 0x8067
    ctx->r24 = S32(RELOC_HI16(517, 0X26C8) << 16);
    // 0x8066E130: addiu       $t8, $t8, -0x378
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(517, 0X26C8));
    // 0x8066E134: addiu       $t7, $t6, -0x18
    ctx->r15 = ADD32(ctx->r14, -0X18);
    // 0x8066E138: beq         $a2, $zero, L_8066E188
    if (ctx->r6 == 0) {
        // 0x8066E13C: addu        $v1, $t7, $t8
        ctx->r3 = ADD32(ctx->r15, ctx->r24);
            goto L_8066E188;
    }
    // 0x8066E13C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8066E140: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8066E144: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8066E148: nop

    // 0x8066E14C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8066E150: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8066E154: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x8066E158: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8066E15C: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8066E160: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x8066E164: nop

    // 0x8066E168: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8066E16C: swc1        $f16, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f16.u32l;
    // 0x8066E170: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x8066E174: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8066E178: swc1        $f18, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f18.u32l;
    // 0x8066E17C: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x8066E180: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8066E184: swc1        $f4, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f4.u32l;
L_8066E188:
    // 0x8066E188: jal         0x8066DB84
    // 0x8066E18C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8066DB84(rdram, ctx);
        goto after_11;
    // 0x8066E18C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8066E190: jal         0x8066D8D8
    // 0x8066E194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8066D8D8(rdram, ctx);
        goto after_12;
    // 0x8066E194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x8066E198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8066E19C:
    // 0x8066E19C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8066E1A0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8066E1A4: jr          $ra
    // 0x8066E1A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8066E1A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800367CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800367CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800367D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800367D4: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800367D8: jal         0x80065954
    // 0x800367DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800367DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800367E0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800367E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800367E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800367EC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800367F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800367F4: jal         0x80041214
    // 0x800367F8: nop

    func_80041214(rdram, ctx);
        goto after_1;
    // 0x800367F8: nop

    after_1:
    // 0x800367FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80036800: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80036804: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80036808: bnel        $t6, $at, L_8003682C
    if (ctx->r14 != ctx->r1) {
        // 0x8003680C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003682C;
    }
    goto skip_0;
    // 0x8003680C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80036810: lw          $t7, 0x154($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X154);
    // 0x80036814: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80036818: bnel        $t7, $zero, L_8003682C
    if (ctx->r15 != 0) {
        // 0x8003681C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003682C;
    }
    goto skip_1;
    // 0x8003681C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80036820: jal         0x8002288C
    // 0x80036824: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    func_8002288C(rdram, ctx);
        goto after_2;
    // 0x80036824: lui         $a2, 0xC000
    ctx->r6 = S32(0XC000 << 16);
    after_2:
    // 0x80036828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003682C:
    // 0x8003682C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036830: jr          $ra
    // 0x80036834: nop

    return;
    // 0x80036834: nop

;}
RECOMP_FUNC void func_8004BF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BF6C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004BF70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8004BF74: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8004BF78: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8004BF7C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8004BF80: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8004BF84: lh          $v0, 0x6($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X6);
    // 0x8004BF88: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8004BF8C: lh          $t0, 0x10($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X10);
    // 0x8004BF90: blez        $v0, L_8004BFD0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004BF94: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8004BFD0;
    }
    // 0x8004BF94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004BF98: lhu         $a0, 0x2($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X2);
    // 0x8004BF9C: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
L_8004BFA0:
    // 0x8004BFA0: srav        $t7, $a0, $t6
    ctx->r15 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x8004BFA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8004BFA8: bnel        $t8, $zero, L_8004BFBC
    if (ctx->r24 != 0) {
        // 0x8004BFAC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8004BFBC;
    }
    goto skip_0;
    // 0x8004BFAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8004BFB0: b           L_8004C128
    // 0x8004BFB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C128;
    // 0x8004BFB4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004BFB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8004BFBC:
    // 0x8004BFBC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004BFC0: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8004BFC4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004BFC8: bnel        $at, $zero, L_8004BFA0
    if (ctx->r1 != 0) {
        // 0x8004BFCC: addu        $t6, $t0, $v1
        ctx->r14 = ADD32(ctx->r8, ctx->r3);
            goto L_8004BFA0;
    }
    goto skip_1;
    // 0x8004BFCC: addu        $t6, $t0, $v1
    ctx->r14 = ADD32(ctx->r8, ctx->r3);
    skip_1:
L_8004BFD0:
    // 0x8004BFD0: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x8004BFD4: slti        $at, $t9, 0x11
    ctx->r1 = SIGNED(ctx->r25) < 0X11 ? 1 : 0;
    // 0x8004BFD8: bnel        $at, $zero, L_8004BFEC
    if (ctx->r1 != 0) {
        // 0x8004BFDC: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8004BFEC;
    }
    goto skip_2;
    // 0x8004BFDC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    skip_2:
    // 0x8004BFE0: b           L_8004C128
    // 0x8004BFE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8004C128;
    // 0x8004BFE4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8004BFE8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
L_8004BFEC:
    // 0x8004BFEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004BFF0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004BFF4: lw          $t1, 0x14($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X14);
    // 0x8004BFF8: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004BFFC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004C000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004C004: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8004C008: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004C00C: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C010: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8004C014: jal         0x800534C0
    // 0x8004C018: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    func_800534C0(rdram, ctx);
        goto after_0;
    // 0x8004C018: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8004C01C: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C020: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x8004C024: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C028: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8004C02C: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x8004C030: andi        $t3, $t2, 0xF8
    ctx->r11 = ctx->r10 & 0XF8;
    // 0x8004C034: bnel        $t3, $at, L_8004C044
    if (ctx->r11 != ctx->r1) {
        // 0x8004C038: lhu         $v0, 0x0($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X0);
            goto L_8004C044;
    }
    goto skip_3;
    // 0x8004C038: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    skip_3:
    // 0x8004C03C: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8004C040: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
L_8004C044:
    // 0x8004C044: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004C048: beql        $v0, $zero, L_8004C128
    if (ctx->r2 == 0) {
        // 0x8004C04C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C128;
    }
    goto skip_4;
    // 0x8004C04C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8004C050: beql        $v0, $at, L_8004C128
    if (ctx->r2 == ctx->r1) {
        // 0x8004C054: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C128;
    }
    goto skip_5;
    // 0x8004C054: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_5:
    // 0x8004C058: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8004C05C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004C060: andi        $a0, $v0, 0xF8
    ctx->r4 = ctx->r2 & 0XF8;
    // 0x8004C064: beq         $a0, $at, L_8004C124
    if (ctx->r4 == ctx->r1) {
        // 0x8004C068: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004C124;
    }
    // 0x8004C068: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004C06C: beql        $a0, $at, L_8004C128
    if (ctx->r4 == ctx->r1) {
        // 0x8004C070: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8004C128;
    }
    goto skip_6;
    // 0x8004C070: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_6:
    // 0x8004C074: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8004C078: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8004C07C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8004C080: andi        $a1, $a0, 0x3F
    ctx->r5 = ctx->r4 & 0X3F;
    // 0x8004C084: xori        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 ^ 0X3;
    // 0x8004C088: sltu        $t7, $zero, $t7
    ctx->r15 = 0 < ctx->r15 ? 1 : 0;
    // 0x8004C08C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8004C090: beq         $t8, $zero, L_8004C124
    if (ctx->r24 == 0) {
        // 0x8004C094: srl         $t1, $a0, 6
        ctx->r9 = S32(U32(ctx->r4) >> 6);
            goto L_8004C124;
    }
    // 0x8004C094: srl         $t1, $a0, 6
    ctx->r9 = S32(U32(ctx->r4) >> 6);
    // 0x8004C098: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x8004C09C: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004C0A0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004C0A4: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8004C0A8: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8004C0AC: sh          $zero, 0x10($s0)
    MEM_H(0X10, ctx->r16) = 0;
    // 0x8004C0B0: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x8004C0B4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8004C0B8: lw          $t5, 0xA24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA24);
    // 0x8004C0BC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8004C0C0: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8004C0C4: lhu         $t1, 0x0($t8)
    ctx->r9 = MEM_HU(ctx->r24, 0X0);
    // 0x8004C0C8: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8004C0CC: beq         $t2, $zero, L_8004C124
    if (ctx->r10 == 0) {
        // 0x8004C0D0: sh          $t1, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r9;
            goto L_8004C124;
    }
    // 0x8004C0D0: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x8004C0D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8004C0D8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8004C0DC: lhu         $t3, 0x0($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X0);
    // 0x8004C0E0: lw          $t4, 0x174($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X174);
    // 0x8004C0E4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x8004C0E8: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x8004C0EC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x8004C0F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8004C0F4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8004C0F8: lw          $t5, 0x40($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X40);
    // 0x8004C0FC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8004C100: sh          $t3, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r11;
    // 0x8004C104: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8004C108: sh          $v1, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r3;
    // 0x8004C10C: jal         0x8004BF6C
    // 0x8004C110: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    func_8004BF6C(rdram, ctx);
        goto after_1;
    // 0x8004C110: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x8004C114: lh          $v1, 0x2E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X2E);
    // 0x8004C118: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8004C11C: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8004C120: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_8004C124:
    // 0x8004C124: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C128:
    // 0x8004C128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8004C12C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8004C130: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004C134: jr          $ra
    // 0x8004C138: nop

    return;
    // 0x8004C138: nop

;}
RECOMP_FUNC void func_804B7E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7E20: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804B7E24: addiu       $at, $zero, 0x411C
    ctx->r1 = ADD32(0, 0X411C);
    // 0x804B7E28: beq         $v0, $at, L_804B7E48
    if (ctx->r2 == ctx->r1) {
        // 0x804B7E2C: addiu       $at, $zero, 0x411D
        ctx->r1 = ADD32(0, 0X411D);
            goto L_804B7E48;
    }
    // 0x804B7E2C: addiu       $at, $zero, 0x411D
    ctx->r1 = ADD32(0, 0X411D);
    // 0x804B7E30: beq         $v0, $at, L_804B7E54
    if (ctx->r2 == ctx->r1) {
        // 0x804B7E34: addiu       $at, $zero, 0x411E
        ctx->r1 = ADD32(0, 0X411E);
            goto L_804B7E54;
    }
    // 0x804B7E34: addiu       $at, $zero, 0x411E
    ctx->r1 = ADD32(0, 0X411E);
    // 0x804B7E38: beq         $v0, $at, L_804B7E60
    if (ctx->r2 == ctx->r1) {
        // 0x804B7E3C: nop
    
            goto L_804B7E60;
    }
    // 0x804B7E3C: nop

    // 0x804B7E40: b           L_804B7E6C
    // 0x804B7E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B7E6C;
    // 0x804B7E44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B7E48:
    // 0x804B7E48: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(185, 0XD34) << 16);
    // 0x804B7E4C: jr          $ra
    // 0x804B7E50: addiu       $v0, $v0, -0x74AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0XD34));
    return;
    // 0x804B7E50: addiu       $v0, $v0, -0x74AC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0XD34));
L_804B7E54:
    // 0x804B7E54: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(185, 0X19C4) << 16);
    // 0x804B7E58: jr          $ra
    // 0x804B7E5C: addiu       $v0, $v0, -0x681C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0X19C4));
    return;
    // 0x804B7E5C: addiu       $v0, $v0, -0x681C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0X19C4));
L_804B7E60:
    // 0x804B7E60: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(185, 0X285C) << 16);
    // 0x804B7E64: jr          $ra
    // 0x804B7E68: addiu       $v0, $v0, -0x5984
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0X285C));
    return;
    // 0x804B7E68: addiu       $v0, $v0, -0x5984
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(185, 0X285C));
L_804B7E6C:
    // 0x804B7E6C: jr          $ra
    // 0x804B7E70: nop

    return;
    // 0x804B7E70: nop

;}
RECOMP_FUNC void func_805267A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805267A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x805267A8: bne         $v0, $zero, L_80526804
    if (ctx->r2 != 0) {
        // 0x805267AC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80526804;
    }
    // 0x805267AC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x805267B0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x805267B4: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X60F4) << 16);
    // 0x805267B8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x805267BC: beq         $at, $zero, L_805267FC
    if (ctx->r1 == 0) {
        // 0x805267C0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_805267FC;
    }
    // 0x805267C0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x805267C4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x805267C8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x805267CC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805267D0: lw          $t9, -0x400C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(327, 0X60F4));
    // 0x805267D4: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x805267D8: lw          $t5, 0x14($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14);
    // 0x805267DC: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x805267E0: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x805267E4: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x805267E8: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x805267EC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x805267F0: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x805267F4: b           L_80526808
    // 0x805267F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
        goto L_80526808;
    // 0x805267F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_805267FC:
    // 0x805267FC: jr          $ra
    // 0x80526800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80526800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80526804:
    // 0x80526804: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80526808:
    // 0x80526808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8052680C: jr          $ra
    // 0x80526810: nop

    return;
    // 0x80526810: nop

;}
RECOMP_FUNC void func_800324C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800324C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800324CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800324D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800324D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800324D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800324DC: jal         0x8004816C
    // 0x800324E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x800324E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800324E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800324E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800324EC: jal         0x8003241C
    // 0x800324F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    func_8003241C(rdram, ctx);
        goto after_1;
    // 0x800324F0: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800324F4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800324F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800324FC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80032500: sw          $t7, 0x16C($a3)
    MEM_W(0X16C, ctx->r7) = ctx->r15;
    // 0x80032504: sw          $zero, 0x164($a3)
    MEM_W(0X164, ctx->r7) = 0;
    // 0x80032508: sb          $zero, 0x155($a3)
    MEM_B(0X155, ctx->r7) = 0;
    // 0x8003250C: jal         0x8001D770
    // 0x80032510: sw          $t6, 0x168($a3)
    MEM_W(0X168, ctx->r7) = ctx->r14;
    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x80032510: sw          $t6, 0x168($a3)
    MEM_W(0X168, ctx->r7) = ctx->r14;
    after_2:
    // 0x80032514: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80032518: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003251C: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x80032520: jal         0x80067BF8
    // 0x80032524: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x80032524: lw          $a2, 0x38($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X38);
    after_3:
    // 0x80032528: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8003252C: jal         0x80067818
    // 0x80032530: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80032530: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80032534: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80032538: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003253C: sb          $t8, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r24;
    // 0x80032540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80032544: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80032548: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8003254C: sb          $t9, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r25;
    // 0x80032550: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80032554: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80032558: sb          $t0, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r8;
    // 0x8003255C: jr          $ra
    // 0x80032560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80032560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80579A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80579A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80579A98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80579A9C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80579AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80579AA4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80579AA8: sw          $t6, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r14;
    // 0x80579AAC: sw          $zero, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = 0;
    // 0x80579AB0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1AF0) << 16);
    // 0x80579AB4: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x80579AB8: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x80579ABC: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80579AC0: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x80579AC4: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x80579AC8: lwc1        $f6, -0x4AD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1AF0));
    // 0x80579ACC: sw          $zero, 0x68($a0)
    MEM_W(0X68, ctx->r4) = 0;
    // 0x80579AD0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80579AD4: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x80579AD8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x80579ADC: jal         0x80048378
    // 0x80579AE0: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80579AE0: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x80579AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80579AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80579AEC: jr          $ra
    // 0x80579AF0: nop

    return;
    // 0x80579AF0: nop

;}
RECOMP_FUNC void func_80535D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535D30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535D34: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535D38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535D3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535D44: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535D48: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X1378) << 16);
    // 0x80535D4C: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X138C) << 16);
    // 0x80535D50: addiu       $a1, $a1, 0x6C1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X138C));
    // 0x80535D54: addiu       $a2, $a2, 0x6C08
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X1378));
    // 0x80535D58: jal         0x80535958
    // 0x80535D5C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535D5C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80535D60: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535D64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535D6C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535D70: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535D74: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535D80: jr          $ra
    // 0x80535D84: nop

    return;
    // 0x80535D84: nop

;}
RECOMP_FUNC void func_805843F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805843F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805843F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x805843FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80584400: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A3A0) << 16);
    // 0x80584404: lwc1        $f4, -0x1FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A3A0));
    // 0x80584408: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A3A4) << 16);
    // 0x8058440C: lwc1        $f6, -0x1F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A3A4));
    // 0x80584410: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80584414: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80584418: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8058441C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80584420: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80584424: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80584428: addiu       $t6, $zero, 0x1BA8
    ctx->r14 = ADD32(0, 0X1BA8);
    // 0x8058442C: addiu       $t7, $zero, 0x1CD4
    ctx->r15 = ADD32(0, 0X1CD4);
    // 0x80584430: addiu       $t8, $zero, 0x1EF0
    ctx->r24 = ADD32(0, 0X1EF0);
    // 0x80584434: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80584438: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8058443C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80584440: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80584444: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x80584448: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8058444C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80584450: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80584454: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80584458: jal         0x80583E84
    // 0x8058445C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    func_80583E84(rdram, ctx);
        goto after_0;
    // 0x8058445C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80584460: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80584464: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A3A8) << 16);
    // 0x80584468: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8058446C: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x80584470: lwc1        $f8, -0x1F98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A3A8));
    // 0x80584474: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(402, 0X1A3AC) << 16);
    // 0x80584478: lwc1        $f10, -0x1F94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(402, 0X1A3AC));
    // 0x8058447C: addiu       $t0, $zero, 0x1BA8
    ctx->r8 = ADD32(0, 0X1BA8);
    // 0x80584480: addiu       $t1, $zero, 0x1C98
    ctx->r9 = ADD32(0, 0X1C98);
    // 0x80584484: addiu       $t2, $zero, 0x1EF0
    ctx->r10 = ADD32(0, 0X1EF0);
    // 0x80584488: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8058448C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80584490: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80584494: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80584498: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8058449C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x805844A0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805844A4: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x805844A8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x805844AC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x805844B0: jal         0x80583E84
    // 0x805844B4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    func_80583E84(rdram, ctx);
        goto after_1;
    // 0x805844B4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x805844B8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x805844BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805844C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805844C4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805844C8: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x805844CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x805844D0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805844D4: jr          $ra
    // 0x805844D8: nop

    return;
    // 0x805844D8: nop

;}
RECOMP_FUNC void func_804A4E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4E64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4E68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4E6C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4E70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4E74: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4E78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4E7C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4E80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4E84: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4E88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4E8C: jr          $ra
    // 0x804A4E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80558430(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558430: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80558434: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(363, 0X93AC) << 16);
    // 0x80558438: addiu       $v0, $v0, 0xEFC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(363, 0X93AC));
    // 0x8055843C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80558440: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80558444: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80558448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8055844C: jalr        $t9
    // 0x80558450: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80558450: nop

    after_0:
    // 0x80558454: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80558458: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8055845C: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x80558460: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80558464: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x80558468: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8055846C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80558470: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x80558474: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80558478: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8055847C: jr          $ra
    // 0x80558480: nop

    return;
    // 0x80558480: nop

;}
RECOMP_FUNC void func_80028288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028288: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002828C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028290: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80028294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80028298: beq         $t6, $zero, L_80028310
    if (ctx->r14 == 0) {
        // 0x8002829C: nop
    
            goto L_80028310;
    }
    // 0x8002829C: nop

    // 0x800282A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800282A4: lw          $t7, 0x14C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X14C);
    // 0x800282A8: lbu         $t8, 0x1F8($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1F8);
    // 0x800282AC: sw          $t7, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r15;
    // 0x800282B0: bnel        $t8, $zero, L_800282C8
    if (ctx->r24 != 0) {
        // 0x800282B4: lw          $t0, 0xA0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XA0);
            goto L_800282C8;
    }
    goto skip_0;
    // 0x800282B4: lw          $t0, 0xA0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA0);
    skip_0:
    // 0x800282B8: lw          $t9, 0x12EC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X12EC);
    // 0x800282BC: beql        $t9, $zero, L_800282D4
    if (ctx->r25 == 0) {
        // 0x800282C0: lw          $t1, 0x9C($v0)
        ctx->r9 = MEM_W(ctx->r2, 0X9C);
            goto L_800282D4;
    }
    goto skip_1;
    // 0x800282C0: lw          $t1, 0x9C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X9C);
    skip_1:
    // 0x800282C4: lw          $t0, 0xA0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA0);
L_800282C8:
    // 0x800282C8: b           L_800282D8
    // 0x800282CC: sw          $t0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r8;
        goto L_800282D8;
    // 0x800282CC: sw          $t0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r8;
    // 0x800282D0: lw          $t1, 0x9C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X9C);
L_800282D4:
    // 0x800282D4: sw          $t1, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r9;
L_800282D8:
    // 0x800282D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800282DC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x800282E0: jalr        $t9
    // 0x800282E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800282E4: nop

    after_0:
    // 0x800282E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800282EC: lw          $t2, 0x15C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X15C);
    // 0x800282F0: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x800282F4: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800282F8: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800282FC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80028300: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80028304: sw          $v1, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r3;
    // 0x80028308: b           L_80028310
    // 0x8002830C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
        goto L_80028310;
    // 0x8002830C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
L_80028310:
    // 0x80028310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028318: jr          $ra
    // 0x8002831C: nop

    return;
    // 0x8002831C: nop

;}
RECOMP_FUNC void func_807AC790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AC790: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AC794: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(859, 0X26A0) << 16);
    // 0x807AC798: lwc1        $f6, -0x1300($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(859, 0X26A0));
    // 0x807AC79C: lwc1        $f4, 0x470($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X470);
    // 0x807AC7A0: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x807AC7A4: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x807AC7A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807AC7AC: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x807AC7B0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x807AC7B4: swc1        $f8, 0x470($v0)
    MEM_W(0X470, ctx->r2) = ctx->f8.u32l;
    // 0x807AC7B8: lwc1        $f10, 0x470($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X470);
    // 0x807AC7BC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x807AC7C0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x807AC7C4: nop

    // 0x807AC7C8: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x807AC7CC: bne         $at, $zero, L_807AC7D8
    if (ctx->r1 != 0) {
        // 0x807AC7D0: nop
    
            goto L_807AC7D8;
    }
    // 0x807AC7D0: nop

    // 0x807AC7D4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_807AC7D8:
    // 0x807AC7D8: jr          $ra
    // 0x807AC7DC: sb          $v1, 0x17($t8)
    MEM_B(0X17, ctx->r24) = ctx->r3;
    return;
    // 0x807AC7DC: sb          $v1, 0x17($t8)
    MEM_B(0X17, ctx->r24) = ctx->r3;
;}
RECOMP_FUNC void func_806EA988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EA988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EA98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EA990: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806EA994: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806EA998: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806EA99C: jal         0x80067BBC
    // 0x806EA9A0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806EA9A0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806EA9A4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806EA9A8: jal         0x80067818
    // 0x806EA9AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806EA9AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806EA9B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806EA9B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EA9B8: jr          $ra
    // 0x806EA9BC: nop

    return;
    // 0x806EA9BC: nop

;}
RECOMP_FUNC void func_80429390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429398: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8042939C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804293A0: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(41, 0X1E64) << 16);
    // 0x804293A4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804293A8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804293AC: addiu       $t7, $t7, -0x685C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(41, 0X1E64));
    // 0x804293B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804293B4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804293B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804293BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804293C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804293C4: jal         0x804292FC
    // 0x804293C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804292FC(rdram, ctx);
        goto after_0;
    // 0x804293C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x804293CC: jal         0x80429360
    // 0x804293D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80429360(rdram, ctx);
        goto after_1;
    // 0x804293D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804293D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804293D8: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x804293DC: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x804293E0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x804293E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804293E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804293EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804293F0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x804293F4: jr          $ra
    // 0x804293F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804293F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8040B950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040B950: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040B954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040B958: jal         0x8040AE28
    // 0x8040B95C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040AE28(rdram, ctx);
        goto after_0;
    // 0x8040B95C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040B960: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B964: lui         $t9, 0x8041
    ctx->r25 = S32(RELOC_HI16(14, 0X1338) << 16);
    // 0x8040B968: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8040B96C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040B970: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8040B974: lw          $t9, -0x4168($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(14, 0X1338));
    // 0x8040B978: jalr        $t9
    // 0x8040B97C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8040B97C: nop

    after_1:
    // 0x8040B980: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040B984: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8040B988: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040B98C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8040B990: sltiu       $v1, $v0, 0x1
    ctx->r3 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8040B994: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8040B998: beq         $v1, $zero, L_8040B9A8
    if (ctx->r3 == 0) {
        // 0x8040B99C: sw          $t8, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r24;
            goto L_8040B9A8;
    }
    // 0x8040B99C: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x8040B9A0: jal         0x8040BA40
    // 0x8040B9A4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8040BA40(rdram, ctx);
        goto after_2;
    // 0x8040B9A4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
L_8040B9A8:
    // 0x8040B9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040B9AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040B9B0: jr          $ra
    // 0x8040B9B4: nop

    return;
    // 0x8040B9B4: nop

;}
RECOMP_FUNC void func_80526218(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526218: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8052621C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x80526220: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80526224: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80526228: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8052622C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80526230: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80526234: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80526238: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(327, 0X6114) << 16);
    // 0x8052623C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80526240: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80526244: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80526248: lw          $t1, -0x3FEC($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(327, 0X6114));
    // 0x8052624C: jr          $ra
    // 0x80526250: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80526250: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80517580(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517580: lui         $v0, 0x8051
    ctx->r2 = S32(RELOC_HI16(288, 0X31C) << 16);
    // 0x80517584: addiu       $v0, $v0, 0x789C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(288, 0X31C));
    // 0x80517588: jr          $ra
    // 0x8051758C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8051758C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805D1EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1EDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805D1EE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805D1EE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805D1EE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805D1EEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x805D1EF0: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x805D1EF4: lui         $a0, 0x805D
    ctx->r4 = S32(RELOC_HI16(471, 0X2A20) << 16);
    // 0x805D1EF8: lw          $a3, 0x4($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X4);
    // 0x805D1EFC: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x805D1F00: addiu       $a0, $a0, 0x4450
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(471, 0X2A20));
    // 0x805D1F04: lui         $a1, 0x46DA
    ctx->r5 = S32(0X46DA << 16);
    // 0x805D1F08: jal         0x80046804
    // 0x805D1F0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x805D1F0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x805D1F10: bne         $v0, $zero, L_805D1F20
    if (ctx->r2 != 0) {
        // 0x805D1F14: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_805D1F20;
    }
    // 0x805D1F14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x805D1F18: b           L_805D1F50
    // 0x805D1F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805D1F50;
    // 0x805D1F1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D1F20:
    // 0x805D1F20: jal         0x80047090
    // 0x805D1F24: addiu       $a0, $zero, 0x46DA
    ctx->r4 = ADD32(0, 0X46DA);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x805D1F24: addiu       $a0, $zero, 0x46DA
    ctx->r4 = ADD32(0, 0X46DA);
    after_1:
    // 0x805D1F28: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x805D1F2C: andi        $t8, $v0, 0x3FF
    ctx->r24 = ctx->r2 & 0X3FF;
    // 0x805D1F30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D1F34: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x805D1F38: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x805D1F3C: jal         0x80044194
    // 0x805D1F40: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805D1F40: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    after_2:
    // 0x805D1F44: jal         0x80052BA4
    // 0x805D1F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x805D1F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D1F4C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_805D1F50:
    // 0x805D1F50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805D1F54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x805D1F58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805D1F5C: jr          $ra
    // 0x805D1F60: nop

    return;
    // 0x805D1F60: nop

;}
RECOMP_FUNC void func_8043AC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AC18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043AC1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043AC20: lui         $a1, 0x8044
    ctx->r5 = S32(RELOC_HI16(83, 0X3D4) << 16);
    // 0x8043AC24: jal         0x800628E4
    // 0x8043AC28: addiu       $a1, $a1, -0x55CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(83, 0X3D4));
    func_800628E4(rdram, ctx);
        goto after_0;
    // 0x8043AC28: addiu       $a1, $a1, -0x55CC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(83, 0X3D4));
    after_0:
    // 0x8043AC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043AC30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043AC34: jr          $ra
    // 0x8043AC38: nop

    return;
    // 0x8043AC38: nop

;}
RECOMP_FUNC void func_805CA4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CA4E0: lui         $v0, 0x805D
    ctx->r2 = S32(RELOC_HI16(450, 0X10) << 16);
    // 0x805CA4E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x805CA4E8: jr          $ra
    // 0x805CA4EC: addiu       $v0, $v0, -0x5B10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(450, 0X10));
    return;
    // 0x805CA4EC: addiu       $v0, $v0, -0x5B10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(450, 0X10));
;}
RECOMP_FUNC void func_80453C3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453C3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453C44: jal         0x80445730
    // 0x80453C48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80445730(rdram, ctx);
        goto after_0;
    // 0x80453C48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80453C4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80453C50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453C54: jal         0x80457164
    // 0x80453C58: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_80457164(rdram, ctx);
        goto after_1;
    // 0x80453C58: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x80453C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453C64: jr          $ra
    // 0x80453C68: nop

    return;
    // 0x80453C68: nop

;}
RECOMP_FUNC void func_8001D7CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D7CC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8001D7D0: sltiu       $t6, $a1, 0x1
    ctx->r14 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x8001D7D4: addiu       $v1, $v1, -0x68E0
    ctx->r3 = ADD32(ctx->r3, -0X68E0);
    // 0x8001D7D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D7DC: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x8001D7E0: sw          $a1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r5;
    // 0x8001D7E4: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8001D7E8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001D7EC: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8001D7F0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001D7F4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8001D7F8: swc1        $f4, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f4.u32l;
    // 0x8001D7FC: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8001D800: jr          $ra
    // 0x8001D804: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8001D804: swc1        $f6, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_80448140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448140: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80448144: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80448148: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8044814C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80448150: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80448154: addiu       $t0, $zero, 0x1B6C
    ctx->r8 = ADD32(0, 0X1B6C);
    // 0x80448158: subu        $t1, $t0, $a3
    ctx->r9 = SUB32(ctx->r8, ctx->r7);
    // 0x8044815C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80448160: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80448164: slti        $at, $t8, 0x3C0
    ctx->r1 = SIGNED(ctx->r24) < 0X3C0 ? 1 : 0;
    // 0x80448168: beq         $at, $zero, L_80448174
    if (ctx->r1 == 0) {
        // 0x8044816C: sw          $t8, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r24;
            goto L_80448174;
    }
    // 0x8044816C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x80448170: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
L_80448174:
    // 0x80448174: jr          $ra
    // 0x80448178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448178: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_800517F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800517F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800517F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800517FC: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80051800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051804: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051808: sh          $a1, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r5;
    // 0x8005180C: jal         0x80050E40
    // 0x80051810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80050E40(rdram, ctx);
        goto after_0;
    // 0x80051810: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x80051814: jal         0x80051504
    // 0x80051818: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_80051504(rdram, ctx);
        goto after_1;
    // 0x80051818: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x8005181C: bne         $v0, $zero, L_8005182C
    if (ctx->r2 != 0) {
        // 0x80051820: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005182C;
    }
    // 0x80051820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051824: b           L_80051830
    // 0x80051828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051830;
    // 0x80051828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005182C:
    // 0x8005182C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051830:
    // 0x80051830: jr          $ra
    // 0x80051834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80051834: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8045BED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BED4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045BED8: lui         $at, 0xC300
    ctx->r1 = S32(0XC300 << 16);
    // 0x8045BEDC: srl         $a3, $a1, 1
    ctx->r7 = S32(U32(ctx->r5) >> 1);
    // 0x8045BEE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045BEE4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8045BEE8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8045BEEC: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8045BEF0: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x8045BEF4: beq         $a3, $zero, L_8045BF34
    if (ctx->r7 == 0) {
        // 0x8045BEF8: sw          $a1, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r5;
            goto L_8045BF34;
    }
    // 0x8045BEF8: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x8045BEFC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045BF00: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045BF04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BF08: nop

L_8045BF0C:
    // 0x8045BF0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8045BF10: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8045BF14: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8045BF18: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x8045BF1C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8045BF20: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8045BF24: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8045BF28: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8045BF2C: bne         $at, $zero, L_8045BF0C
    if (ctx->r1 != 0) {
        // 0x8045BF30: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8045BF0C;
    }
    // 0x8045BF30: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8045BF34:
    // 0x8045BF34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BF38: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22B4) << 16);
    // 0x8045BF3C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8045BF40: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x8045BF44: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8045BF48: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8045BF4C: lwc1        $f4, -0x24BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22B4));
    // 0x8045BF50: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22B8) << 16);
    // 0x8045BF54: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x8045BF58: lwc1        $f6, -0x24B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22B8));
    // 0x8045BF5C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8045BF60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8045BF64: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X22BC) << 16);
    // 0x8045BF68: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8045BF6C: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x8045BF70: lwc1        $f10, -0x24B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X22BC));
    // 0x8045BF74: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8045BF78: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x8045BF7C: jr          $ra
    // 0x8045BF80: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    return;
    // 0x8045BF80: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8052E144(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E144: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052E148: lw          $v1, 0xF64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF64);
    // 0x8052E14C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8052E150: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8052E154: sw          $t6, 0xF64($v0)
    MEM_W(0XF64, ctx->r2) = ctx->r14;
    // 0x8052E158: bne         $at, $zero, L_8052E164
    if (ctx->r1 != 0) {
        // 0x8052E15C: sw          $v1, 0xF60($v0)
        MEM_W(0XF60, ctx->r2) = ctx->r3;
            goto L_8052E164;
    }
    // 0x8052E15C: sw          $v1, 0xF60($v0)
    MEM_W(0XF60, ctx->r2) = ctx->r3;
    // 0x8052E160: sw          $zero, 0xF64($v0)
    MEM_W(0XF64, ctx->r2) = 0;
L_8052E164:
    // 0x8052E164: jr          $ra
    // 0x8052E168: nop

    return;
    // 0x8052E168: nop

;}
RECOMP_FUNC void func_804B8038(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8038: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x804B803C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804B8040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B8044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B8048: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x804B804C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x804B8050: jal         0x8004921C
    // 0x804B8054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x804B8054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804B8058: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x804B805C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8060: jal         0x8004921C
    // 0x804B8064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x804B8064: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x804B8068: lh          $s1, 0x2A($sp)
    ctx->r17 = MEM_H(ctx->r29, 0X2A);
    // 0x804B806C: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B8070: lh          $t9, 0x144($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X144);
    // 0x804B8074: andi        $t7, $s1, 0xFF
    ctx->r15 = ctx->r17 & 0XFF;
    // 0x804B8078: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B807C: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x804B8080: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804B8084: lw          $t6, 0x168($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X168);
    // 0x804B8088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B808C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B8090: mflo        $t8
    ctx->r24 = lo;
    // 0x804B8094: nop

    // 0x804B8098: nop

    // 0x804B809C: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B80A0: lw          $t8, 0x80($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X80);
    // 0x804B80A4: mflo        $t9
    ctx->r25 = lo;
    // 0x804B80A8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x804B80AC: jal         0x8004921C
    // 0x804B80B0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x804B80B0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    after_2:
    // 0x804B80B4: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B80B8: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B80BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B80C0: jal         0x8004921C
    // 0x804B80C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x804B80C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x804B80C8: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x804B80CC: andi        $t9, $s1, 0xFF
    ctx->r25 = ctx->r17 & 0XFF;
    // 0x804B80D0: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B80D4: lbu         $t7, 0x145($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X145);
    // 0x804B80D8: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B80DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B80E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B80E4: mflo        $t8
    ctx->r24 = lo;
    // 0x804B80E8: nop

    // 0x804B80EC: nop

    // 0x804B80F0: multu       $t8, $t7
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B80F4: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B80F8: mflo        $t6
    ctx->r14 = lo;
    // 0x804B80FC: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x804B8100: jal         0x8004921C
    // 0x804B8104: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_4;
    // 0x804B8104: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    after_4:
    // 0x804B8108: sll         $s1, $v0, 16
    ctx->r17 = S32(ctx->r2 << 16);
    // 0x804B810C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x804B8110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B8114: jal         0x8004921C
    // 0x804B8118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_5;
    // 0x804B8118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804B811C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x804B8120: andi        $t6, $s1, 0xFF
    ctx->r14 = ctx->r17 & 0XFF;
    // 0x804B8124: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B8128: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x804B812C: lui         $s2, 0x400
    ctx->r18 = S32(0X400 << 16);
    // 0x804B8130: ori         $s2, $s2, 0x81FF
    ctx->r18 = ctx->r18 | 0X81FF;
    // 0x804B8134: addiu       $t9, $t7, 0x20
    ctx->r25 = ADD32(ctx->r15, 0X20);
    // 0x804B8138: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x804B813C: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x804B8140: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x804B8144: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x804B8148: addiu       $ra, $zero, 0x2
    ctx->r31 = ADD32(0, 0X2);
    // 0x804B814C: mflo        $t8
    ctx->r24 = lo;
    // 0x804B8150: lui         $t3, 0xB100
    ctx->r11 = S32(0XB100 << 16);
    // 0x804B8154: nop

    // 0x804B8158: multu       $t8, $t6
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x804B815C: lw          $t8, 0x80($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X80);
    // 0x804B8160: mflo        $t7
    ctx->r15 = lo;
    // 0x804B8164: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x804B8168: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x804B816C: lw          $a3, 0x1F4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X1F4);
    // 0x804B8170: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B8174: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B8178: lw          $t0, 0x1F0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X1F0);
    // 0x804B817C: addiu       $t5, $a3, 0x1F8
    ctx->r13 = ADD32(ctx->r7, 0X1F8);
    // 0x804B8180: lui         $s0, 0x400
    ctx->r16 = S32(0X400 << 16);
    // 0x804B8184: xori        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 ^ 0X1;
    // 0x804B8188: andi        $t0, $t0, 0x1
    ctx->r8 = ctx->r8 & 0X1;
    // 0x804B818C: sll         $t9, $t0, 5
    ctx->r25 = S32(ctx->r8 << 5);
    // 0x804B8190: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x804B8194: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x804B8198: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x804B819C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B81A0: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B81A4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x804B81A8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B81AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B81B0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x804B81B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B81B8: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B81BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B81C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B81C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B81C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B81CC: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B81D0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B81D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B81D8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B81DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B81E0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B81E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B81E8: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B81EC: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B81F0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B81F4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B81F8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B81FC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8200: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B8204: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B8208: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B820C: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x804B8210: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8214: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8218: sw          $a3, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r7;
    // 0x804B821C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B8220: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8224: lui         $t0, 0xF548
    ctx->r8 = S32(0XF548 << 16);
    // 0x804B8228: ori         $t0, $t0, 0x600
    ctx->r8 = ctx->r8 | 0X600;
    // 0x804B822C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B8230: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8234: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B8238: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B823C: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B8240: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B8244: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x804B8248: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B824C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B8250: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x804B8254: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x804B8258: lui         $t6, 0xB100
    ctx->r14 = S32(0XB100 << 16);
    // 0x804B825C: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x804B8260: ori         $t9, $t9, 0x604
    ctx->r25 = ctx->r25 | 0X604;
    // 0x804B8264: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8268: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x804B826C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804B8270: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B8274: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B8278: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x804B827C: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x804B8280: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8284: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x804B8288: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x804B828C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8290: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B8294: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B8298: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x804B829C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x804B82A0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B82A4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B82A8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B82AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B82B0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x804B82B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B82B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B82BC: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B82C0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B82C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B82C8: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B82CC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x804B82D0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B82D4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B82D8: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x804B82DC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B82E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x804B82E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B82E8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B82EC: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x804B82F0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x804B82F4: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x804B82F8: lui         $t8, 0x5
    ctx->r24 = S32(0X5 << 16);
    // 0x804B82FC: ori         $t8, $t8, 0xC05C
    ctx->r24 = ctx->r24 | 0XC05C;
    // 0x804B8300: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x804B8304: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x804B8308: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x804B830C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x804B8310: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x804B8314: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
L_804B8318:
    // 0x804B8318: bne         $t4, $zero, L_804B8328
    if (ctx->r12 != 0) {
        // 0x804B831C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_804B8328;
    }
    // 0x804B831C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804B8320: b           L_804B8328
    // 0x804B8324: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
        goto L_804B8328;
    // 0x804B8324: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
L_804B8328:
    // 0x804B8328: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B832C: beq         $at, $zero, L_804B83B0
    if (ctx->r1 == 0) {
        // 0x804B8330: sll         $a0, $t0, 2
        ctx->r4 = S32(ctx->r8 << 2);
            goto L_804B83B0;
    }
    // 0x804B8330: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
    // 0x804B8334: sll         $t6, $t4, 5
    ctx->r14 = S32(ctx->r12 << 5);
    // 0x804B8338: addu        $a1, $t6, $a0
    ctx->r5 = ADD32(ctx->r14, ctx->r4);
L_804B833C:
    // 0x804B833C: slti        $at, $a1, 0x1C
    ctx->r1 = SIGNED(ctx->r5) < 0X1C ? 1 : 0;
    // 0x804B8340: beq         $at, $zero, L_804B83B0
    if (ctx->r1 == 0) {
        // 0x804B8344: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_804B83B0;
    }
    // 0x804B8344: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x804B8348: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x804B834C: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B8350: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B8354: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x804B8358: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x804B835C: sll         $t8, $a2, 8
    ctx->r24 = S32(ctx->r6 << 8);
    // 0x804B8360: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B8364: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B8368: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x804B836C: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B8370: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x804B8374: addiu       $t6, $v1, 0x6
    ctx->r14 = ADD32(ctx->r3, 0X6);
    // 0x804B8378: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B837C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B8380: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x804B8384: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x804B8388: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B838C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x804B8390: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x804B8394: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B8398: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x804B839C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804B83A0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x804B83A4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x804B83A8: bne         $at, $zero, L_804B833C
    if (ctx->r1 != 0) {
        // 0x804B83AC: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_804B833C;
    }
    // 0x804B83AC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B83B0:
    // 0x804B83B0: slti        $at, $t0, 0x8
    ctx->r1 = SIGNED(ctx->r8) < 0X8 ? 1 : 0;
    // 0x804B83B4: beq         $at, $zero, L_804B8408
    if (ctx->r1 == 0) {
        // 0x804B83B8: sll         $t6, $t4, 9
        ctx->r14 = S32(ctx->r12 << 9);
            goto L_804B8408;
    }
    // 0x804B83B8: sll         $t6, $t4, 9
    ctx->r14 = S32(ctx->r12 << 9);
    // 0x804B83BC: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B83C0: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B83C4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B83C8: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B83CC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x804B83D0: sll         $t6, $a2, 8
    ctx->r14 = S32(ctx->r6 << 8);
    // 0x804B83D4: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x804B83D8: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B83DC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B83E0: addiu       $t7, $v1, 0x6
    ctx->r15 = ADD32(ctx->r3, 0X6);
    // 0x804B83E4: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x804B83E8: or          $t0, $t9, $a3
    ctx->r8 = ctx->r25 | ctx->r7;
    // 0x804B83EC: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x804B83F0: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B83F4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x804B83F8: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B83FC: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B8400: b           L_804B848C
    // 0x804B8404: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
        goto L_804B848C;
    // 0x804B8404: or          $t3, $t7, $a3
    ctx->r11 = ctx->r15 | ctx->r7;
L_804B8408:
    // 0x804B8408: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x804B840C: bne         $t4, $ra, L_804B8428
    if (ctx->r12 != ctx->r31) {
        // 0x804B8410: addiu       $v1, $v1, 0x200
        ctx->r3 = ADD32(ctx->r3, 0X200);
            goto L_804B8428;
    }
    // 0x804B8410: addiu       $v1, $v1, 0x200
    ctx->r3 = ADD32(ctx->r3, 0X200);
    // 0x804B8414: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8418: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x804B841C: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B8420: b           L_804B8438
    // 0x804B8424: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_804B8438;
    // 0x804B8424: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B8428:
    // 0x804B8428: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B842C: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x804B8430: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x804B8434: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_804B8438:
    // 0x804B8438: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x804B843C: bne         $t4, $s1, L_804B8318
    if (ctx->r12 != ctx->r17) {
        // 0x804B8440: nop
    
            goto L_804B8318;
    }
    // 0x804B8440: nop

    // 0x804B8444: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x804B8448: addiu       $a2, $v1, 0x2
    ctx->r6 = ADD32(ctx->r3, 0X2);
    // 0x804B844C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804B8450: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x804B8454: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x804B8458: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x804B845C: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x804B8460: addiu       $a3, $v1, 0x4
    ctx->r7 = ADD32(ctx->r3, 0X4);
    // 0x804B8464: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x804B8468: addiu       $t9, $v1, 0x6
    ctx->r25 = ADD32(ctx->r3, 0X6);
    // 0x804B846C: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x804B8470: or          $t0, $t6, $a3
    ctx->r8 = ctx->r14 | ctx->r7;
    // 0x804B8474: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x804B8478: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x804B847C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x804B8480: lui         $at, 0xB100
    ctx->r1 = S32(0XB100 << 16);
    // 0x804B8484: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
    // 0x804B8488: or          $t3, $t9, $a3
    ctx->r11 = ctx->r25 | ctx->r7;
L_804B848C:
    // 0x804B848C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x804B8490: lui         $t7, 0xFD50
    ctx->r15 = S32(0XFD50 << 16);
    // 0x804B8494: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x804B8498: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x804B849C: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B84A0: lui         $t6, 0xF550
    ctx->r14 = S32(0XF550 << 16);
    // 0x804B84A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x804B84A8: lui         $t9, 0x700
    ctx->r25 = S32(0X700 << 16);
    // 0x804B84AC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x804B84B0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x804B84B4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x804B84B8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x804B84BC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x804B84C0: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x804B84C4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x804B84C8: lui         $t6, 0x711
    ctx->r14 = S32(0X711 << 16);
    // 0x804B84CC: ori         $t6, $t6, 0xF2AB
    ctx->r14 = ctx->r14 | 0XF2AB;
    // 0x804B84D0: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x804B84D4: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x804B84D8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x804B84DC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x804B84E0: addiu       $t1, $a2, 0x8
    ctx->r9 = ADD32(ctx->r6, 0X8);
    // 0x804B84E4: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x804B84E8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x804B84EC: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x804B84F0: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x804B84F4: ori         $t7, $t7, 0x600
    ctx->r15 = ctx->r15 | 0X600;
    // 0x804B84F8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x804B84FC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B8500: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x804B8504: lui         $t6, 0x5
    ctx->r14 = S32(0X5 << 16);
    // 0x804B8508: ori         $t6, $t6, 0xC05C
    ctx->r14 = ctx->r14 | 0XC05C;
    // 0x804B850C: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x804B8510: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x804B8514: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x804B8518: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x804B851C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x804B8520: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x804B8524: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x804B8528: lui         $t9, 0xB800
    ctx->r25 = S32(0XB800 << 16);
    // 0x804B852C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x804B8530: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x804B8534: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x804B8538: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x804B853C: sw          $t7, 0x1F0($t8)
    MEM_W(0X1F0, ctx->r24) = ctx->r15;
    // 0x804B8540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804B8544: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804B8548: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804B854C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B8550: jr          $ra
    // 0x804B8554: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x804B8554: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void func_800554F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800554F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800554F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800554FC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80055500: lui         $v1, 0x8005
    ctx->r3 = S32(0X8005 << 16);
    // 0x80055504: addiu       $v1, $v1, 0x5464
    ctx->r3 = ADD32(ctx->r3, 0X5464);
    // 0x80055508: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8005550C: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80055510: lw          $t6, 0x20($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X20);
    // 0x80055514: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80055518: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8005551C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80055520: sw          $v1, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r3;
    // 0x80055524: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80055528: sw          $v1, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r3;
    // 0x8005552C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80055530: lw          $t0, 0x174($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X174);
    // 0x80055534: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80055538: beql        $t0, $zero, L_80055554
    if (ctx->r8 == 0) {
        // 0x8005553C: lw          $a0, 0x10($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X10);
            goto L_80055554;
    }
    goto skip_0;
    // 0x8005553C: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x80055540: jal         0x8005FD1C
    // 0x80055544: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x80055544: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80055548: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005554C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x80055550: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
L_80055554:
    // 0x80055554: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80055558: beql        $a1, $a0, L_80055580
    if (ctx->r5 == ctx->r4) {
        // 0x8005555C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80055580;
    }
    goto skip_1;
    // 0x8005555C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80055560: sb          $t1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r9;
    // 0x80055564: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80055568: lw          $t2, 0x174($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X174);
    // 0x8005556C: beql        $t2, $zero, L_80055580
    if (ctx->r10 == 0) {
        // 0x80055570: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80055580;
    }
    goto skip_2;
    // 0x80055570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80055574: jal         0x8005FD1C
    // 0x80055578: nop

    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x80055578: nop

    after_1:
    // 0x8005557C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80055580:
    // 0x80055580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80055584: jr          $ra
    // 0x80055588: nop

    return;
    // 0x80055588: nop

;}
RECOMP_FUNC void func_807BB3E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB3E8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807BB3EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB3F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB3F4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x807BB3F8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x807BB3FC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x807BB400: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x807BB404: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807BB408: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x807BB40C: addiu       $v0, $v0, 0xD
    ctx->r2 = ADD32(ctx->r2, 0XD);
    // 0x807BB410: slti        $at, $t6, 0xEB
    ctx->r1 = SIGNED(ctx->r14) < 0XEB ? 1 : 0;
    // 0x807BB414: bnel        $at, $zero, L_807BB498
    if (ctx->r1 != 0) {
        // 0x807BB418: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BB498;
    }
    goto skip_0;
    // 0x807BB418: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807BB41C: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    // 0x807BB420: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x807BB424: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x807BB428: bne         $t8, $at, L_807BB46C
    if (ctx->r24 != ctx->r1) {
        // 0x807BB42C: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_807BB46C;
    }
    // 0x807BB42C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807BB430: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807BB434: sb          $t9, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r25;
    // 0x807BB438: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x807BB43C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x807BB440: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x807BB444: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x807BB448: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x807BB44C: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    // 0x807BB450: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x807BB454: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x807BB458: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x807BB45C: jalr        $t9
    // 0x807BB460: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x807BB460: nop

    after_0:
    // 0x807BB464: jal         0x800447C8
    // 0x807BB468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x807BB468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_807BB46C:
    // 0x807BB46C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x807BB470: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807BB474: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807BB478: lhu         $t3, 0xC($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0XC);
    // 0x807BB47C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x807BB480: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x807BB484: bnel        $t3, $at, L_807BB498
    if (ctx->r11 != ctx->r1) {
        // 0x807BB488: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BB498;
    }
    goto skip_1;
    // 0x807BB488: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x807BB48C: jal         0x8002F6E4
    // 0x807BB490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x807BB490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x807BB494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB498:
    // 0x807BB498: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB49C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x807BB4A0: jr          $ra
    // 0x807BB4A4: nop

    return;
    // 0x807BB4A4: nop

;}
RECOMP_FUNC void func_80792B6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792B6C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80792B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80792B74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80792B78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80792B7C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80792B80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80792B84: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792B88: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80792B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80792B90: jal         0x807903C4
    // 0x80792B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807903C4(rdram, ctx);
        goto after_0;
    // 0x80792B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80792B98: jal         0x80790714
    // 0x80792B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80792B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80792BA0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80792BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792BAC: blez        $v0, L_80792BC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80792BB0: addiu       $a2, $zero, 0x1D
        ctx->r6 = ADD32(0, 0X1D);
            goto L_80792BC0;
    }
    // 0x80792BB0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80792BB4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80792BB8: b           L_80792C98
    // 0x80792BBC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_80792C98;
    // 0x80792BBC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_80792BC0:
    // 0x80792BC0: jal         0x8079393C
    // 0x80792BC4: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80792BC4: lw          $a3, 0x68($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X68);
    after_2:
    // 0x80792BC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80792BCC: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80792BD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80792BD4: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80792BD8: jal         0x80047AB8
    // 0x80792BDC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    func_80047AB8(rdram, ctx);
        goto after_3;
    // 0x80792BDC: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    after_3:
    // 0x80792BE0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80792BE4: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80792BE8: lw          $t7, 0xED0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XED0);
    // 0x80792BEC: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x80792BF0: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80792BF4: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80792BF8: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x80792BFC: jalr        $t9
    // 0x80792C00: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80792C00: nop

    after_4:
    // 0x80792C04: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80792C08: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80792C0C: lw          $t8, 0xED0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C10: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80792C14: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80792C18: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80792C1C: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x80792C20: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x80792C24: jalr        $t9
    // 0x80792C28: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80792C28: nop

    after_5:
    // 0x80792C2C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80792C30: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80792C34: lw          $t0, 0xED0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C38: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80792C3C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7AFC) << 16);
    // 0x80792C40: sw          $s0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r16;
    // 0x80792C44: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80792C48: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80792C4C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80792C50: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80792C54: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80792C58: lw          $t1, 0xED0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C5C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80792C60: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x80792C64: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80792C68: swc1        $f8, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f8.u32l;
    // 0x80792C6C: lw          $t2, 0xED0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C70: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80792C74: swc1        $f4, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f4.u32l;
    // 0x80792C78: lw          $t4, 0xED0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C7C: lw          $t3, 0x2C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X2C);
    // 0x80792C80: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x80792C84: lw          $t6, 0xED0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XED0);
    // 0x80792C88: lw          $t5, 0x30($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X30);
    // 0x80792C8C: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    // 0x80792C90: lwc1        $f6, 0x7E4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7AFC));
    // 0x80792C94: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
L_80792C98:
    // 0x80792C98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80792C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80792CA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80792CA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80792CA8: jr          $ra
    // 0x80792CAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80792CAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8076081C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076081C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80760820: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80760824: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80760828: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8076082C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80760830: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80760834: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80760838: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8076083C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80760840: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80760844: jr          $ra
    // 0x80760848: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80760848: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8043409C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043409C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x804340A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804340A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x804340A8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x804340AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804340B0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x804340B4: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // 0x804340B8: addiu       $v1, $v0, 0x7AC
    ctx->r3 = ADD32(ctx->r2, 0X7AC);
L_804340BC:
    // 0x804340BC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804340C0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x804340C4: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804340C8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x804340CC: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x804340D0: bc1fl       L_804340E4
    if (!c1cs) {
        // 0x804340D4: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_804340E4;
    }
    goto skip_0;
    // 0x804340D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x804340D8: b           L_804340F4
    // 0x804340DC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_804340F4;
    // 0x804340DC: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x804340E0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_804340E4:
    // 0x804340E4: nop

    // 0x804340E8: bc1fl       L_804340F8
    if (!c1cs) {
        // 0x804340EC: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_804340F8;
    }
    goto skip_1;
    // 0x804340EC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x804340F0: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_804340F4:
    // 0x804340F4: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_804340F8:
    // 0x804340F8: nop

    // 0x804340FC: bc1fl       L_8043410C
    if (!c1cs) {
        // 0x80434100: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_8043410C;
    }
    goto skip_2;
    // 0x80434100: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_2:
    // 0x80434104: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80434108: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_8043410C:
    // 0x8043410C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80434110: bgez        $a1, L_804340BC
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434114: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_804340BC;
    }
    // 0x80434114: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434118: jr          $ra
    // 0x8043411C: nop

    return;
    // 0x8043411C: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80090270: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80090274: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80090278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009027C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80090280: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80090284: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80090288: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8009028C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80090290: jal         0x80082D2C
    // 0x80090294: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80090294: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80090298: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009029C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800902A0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800902A4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800902A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800902AC: jal         0x80082D88
    // 0x800902B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x800902B0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x800902B4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800902B8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800902BC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800902C0: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x800902C4: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x800902C8: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x800902CC: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800902D0: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800902D4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800902D8: bgtz        $t0, L_80090338
    if (SIGNED(ctx->r8) > 0) {
        // 0x800902DC: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80090338;
    }
    // 0x800902DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800902E0: bltz        $t0, L_800902F0
    if (SIGNED(ctx->r8) < 0) {
        // 0x800902E4: nop
    
            goto L_800902F0;
    }
    // 0x800902E4: nop

    // 0x800902E8: b           L_8009033C
    // 0x800902EC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_8009033C;
    // 0x800902EC: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800902F0:
    // 0x800902F0: bltzl       $t8, L_8009033C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800902F4: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8009033C;
    }
    goto skip_0;
    // 0x800902F4: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x800902F8: bgtz        $t8, L_80090308
    if (SIGNED(ctx->r24) > 0) {
        // 0x800902FC: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_80090308;
    }
    // 0x800902FC: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80090300: beql        $t9, $zero, L_8009033C
    if (ctx->r25 == 0) {
        // 0x80090304: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8009033C;
    }
    goto skip_1;
    // 0x80090304: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_80090308:
    // 0x80090308: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8009030C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80090310: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80090314: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80090318: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x8009031C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80090320: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80090324: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80090328: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8009032C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80090330: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80090334: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_80090338:
    // 0x80090338: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_8009033C:
    // 0x8009033C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80090340: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80090344: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x80090348: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8009034C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80090350: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80090354: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x80090358: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x8009035C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x80090360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80090364: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80090368: jr          $ra
    // 0x8009036C: nop

    return;
    // 0x8009036C: nop

;}
RECOMP_FUNC void func_80052C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052C90: jr          $ra
    // 0x80052C94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80052C94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804C5FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5FE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C5FE8: jal         0x804C605C
    // 0x804C5FEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C605C(rdram, ctx);
        goto after_0;
    // 0x804C5FEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804C5FF0: beq         $v0, $zero, L_804C6044
    if (ctx->r2 == 0) {
        // 0x804C5FF4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804C6044;
    }
    // 0x804C5FF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C5FF8: jal         0x804C60A4
    // 0x804C5FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804C60A4(rdram, ctx);
        goto after_1;
    // 0x804C5FFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804C6000: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C6004: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804C6008: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804C600C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804C6010: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(218, 0X458) << 16);
    // 0x804C6014: addiu       $t7, $t7, 0x63D8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(218, 0X458));
    // 0x804C6018: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x804C601C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804C6020: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C6024: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C6028: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C602C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804C6030: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804C6034: jal         0x804C6254
    // 0x804C6038: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    func_804C6254(rdram, ctx);
        goto after_2;
    // 0x804C6038: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    after_2:
    // 0x804C603C: b           L_804C6050
    // 0x804C6040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C6050;
    // 0x804C6040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6044:
    // 0x804C6044: jal         0x800447C8
    // 0x804C6048: nop

    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x804C6048: nop

    after_3:
    // 0x804C604C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C6050:
    // 0x804C6050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C6054: jr          $ra
    // 0x804C6058: nop

    return;
    // 0x804C6058: nop

;}
RECOMP_FUNC void func_8067E608(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E608: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067E60C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067E610: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067E614: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E618: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067E61C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8067E620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067E624: jal         0x8067DF94
    // 0x8067E628: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8067DF94(rdram, ctx);
        goto after_0;
    // 0x8067E628: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8067E62C: jal         0x8067E420
    // 0x8067E630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E420(rdram, ctx);
        goto after_1;
    // 0x8067E630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067E634: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8067E638: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8067E63C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8067E640: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8067E644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067E64C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067E650: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8067E654: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8067E658: bc1f        L_8067E674
    if (!c1cs) {
        // 0x8067E65C: nop
    
            goto L_8067E674;
    }
    // 0x8067E65C: nop

    // 0x8067E660: jal         0x8067EAE0
    // 0x8067E664: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_8067EAE0(rdram, ctx);
        goto after_2;
    // 0x8067E664: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
    // 0x8067E668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E66C: jal         0x8067E3E8
    // 0x8067E670: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    func_8067E3E8(rdram, ctx);
        goto after_3;
    // 0x8067E670: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_3:
L_8067E674:
    // 0x8067E674: jal         0x8067E480
    // 0x8067E678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E480(rdram, ctx);
        goto after_4;
    // 0x8067E678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8067E67C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067E680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067E684: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067E688: jr          $ra
    // 0x8067E68C: nop

    return;
    // 0x8067E68C: nop

;}
RECOMP_FUNC void func_8058050C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058050C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580514: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80580518: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8058051C: beq         $t6, $zero, L_80580558
    if (ctx->r14 == 0) {
        // 0x80580520: nop
    
            goto L_80580558;
    }
    // 0x80580520: nop

    // 0x80580524: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580528: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8058052C: jalr        $t9
    // 0x80580530: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80580530: nop

    after_0:
    // 0x80580534: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80580538: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8058053C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80580540: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80580544: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80580548: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8058054C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80580550: b           L_80580558
    // 0x80580554: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80580558;
    // 0x80580554: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80580558:
    // 0x80580558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8058055C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580560: jr          $ra
    // 0x80580564: nop

    return;
    // 0x80580564: nop

;}
RECOMP_FUNC void func_804C18B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C18B0: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(203, 0XE00) << 16);
    // 0x804C18B4: lw          $t6, 0x2570($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(203, 0XE00));
    // 0x804C18B8: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(203, 0XC4) << 16);
    // 0x804C18BC: addiu       $t7, $t7, 0x1834
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(203, 0XC4));
    // 0x804C18C0: sw          $t7, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r15;
    // 0x804C18C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C18C8: jr          $ra
    // 0x804C18CC: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    return;
    // 0x804C18CC: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80664D40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80664D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80664D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80664D48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80664D4C: lh          $t6, 0x1F0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X1F0);
    // 0x80664D50: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80664D54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80664D58: bnel        $t6, $at, L_80664D84
    if (ctx->r14 != ctx->r1) {
        // 0x80664D5C: lw          $a0, 0x34($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X34);
            goto L_80664D84;
    }
    goto skip_0;
    // 0x80664D5C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x80664D60: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80664D64: jal         0x80067BBC
    // 0x80664D68: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80664D68: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x80664D6C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x80664D70: jal         0x80067F78
    // 0x80664D74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80664D74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80664D78: b           L_80664D9C
    // 0x80664D7C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80664D9C;
    // 0x80664D7C: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80664D80: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_80664D84:
    // 0x80664D84: jal         0x80067BBC
    // 0x80664D88: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80664D88: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80664D8C: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x80664D90: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80664D94: jal         0x800678F0
    // 0x80664D98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80664D98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_80664D9C:
    // 0x80664D9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80664DA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80664DA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80664DA8: jr          $ra
    // 0x80664DAC: nop

    return;
    // 0x80664DAC: nop

;}
RECOMP_FUNC void func_80000AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000AF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000AF4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80000AF8: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80000AFC: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80000B00: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x80000B04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000B08: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000B0C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000B10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000B14: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000B18: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000B1C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80000B20: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80000B24: lbu         $t9, 0x1B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1B);
    // 0x80000B28: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80000B2C: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x80000B30: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80000B34: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80000B38: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80000B3C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80000B40: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80000B44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80000B48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80000B4C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80000B50: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80000B54: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x80000B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000B5C: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x80000B60: lh          $a3, 0x10($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X10);
    // 0x80000B64: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x80000B68: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80000B6C: addiu       $a1, $zero, 0x3E0
    ctx->r5 = ADD32(0, 0X3E0);
    // 0x80000B70: jal         0x800013D4
    // 0x80000B74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_800013D4(rdram, ctx);
        goto after_0;
    // 0x80000B74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80000B78: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80000B7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000B80: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80000B84: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x80000B88: beql        $a3, $zero, L_80000BB0
    if (ctx->r7 == 0) {
        // 0x80000B8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80000BB0;
    }
    goto skip_0;
    // 0x80000B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80000B90: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80000B94: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80000B98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80000B9C: addiu       $a1, $a1, 0x3E0
    ctx->r5 = ADD32(ctx->r5, 0X3E0);
    // 0x80000BA0: jal         0x800013D4
    // 0x80000BA4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_800013D4(rdram, ctx);
        goto after_1;
    // 0x80000BA4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // 0x80000BA8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80000BB0:
    // 0x80000BB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80000BB4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80000BB8: jr          $ra
    // 0x80000BBC: nop

    return;
    // 0x80000BBC: nop

;}
RECOMP_FUNC void func_8057ED90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057ED90: jr          $ra
    // 0x8057ED94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8057ED94: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8004700C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004700C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80047010: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x80047014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80047018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004701C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80047020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80047024: lw          $v1, 0x14($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X14);
    // 0x80047028: beq         $v1, $at, L_80047040
    if (ctx->r3 == ctx->r1) {
        // 0x8004702C: nop
    
            goto L_80047040;
    }
    // 0x8004702C: nop

    // 0x80047030: beq         $v1, $zero, L_80047040
    if (ctx->r3 == 0) {
        // 0x80047034: nop
    
            goto L_80047040;
    }
    // 0x80047034: nop

    // 0x80047038: b           L_80047048
    // 0x8004703C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80047048;
    // 0x8004703C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80047040:
    // 0x80047040: jal         0x80046E88
    // 0x80047044: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x80047044: addiu       $a0, $zero, 0x4001
    ctx->r4 = ADD32(0, 0X4001);
    after_0:
L_80047048:
    // 0x80047048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004704C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80047050: jr          $ra
    // 0x80047054: nop

    return;
    // 0x80047054: nop

;}
RECOMP_FUNC void func_8001C234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C234: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C23C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C240: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C244: lw          $s0, 0x16C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X16C);
    // 0x8001C248: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001C24C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8001C250: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8001C254: jalr        $t9
    // 0x8001C258: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001C258: nop

    after_0:
    // 0x8001C25C: lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X10);
    // 0x8001C260: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001C264: addiu       $a0, $zero, 0x264
    ctx->r4 = ADD32(0, 0X264);
    // 0x8001C268: bnel        $v0, $at, L_8001C280
    if (ctx->r2 != ctx->r1) {
        // 0x8001C26C: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_8001C280;
    }
    goto skip_0;
    // 0x8001C26C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    skip_0:
    // 0x8001C270: jal         0x80067818
    // 0x8001C274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8001C274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8001C278: lbu         $v0, 0x10($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X10);
    // 0x8001C27C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
L_8001C280:
    // 0x8001C280: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8001C284: bne         $at, $zero, L_8001C298
    if (ctx->r1 != 0) {
        // 0x8001C288: sb          $t6, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r14;
            goto L_8001C298;
    }
    // 0x8001C288: sb          $t6, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r14;
    // 0x8001C28C: addiu       $t7, $v0, -0x4
    ctx->r15 = ADD32(ctx->r2, -0X4);
    // 0x8001C290: b           L_8001C2CC
    // 0x8001C294: sb          $t7, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r15;
        goto L_8001C2CC;
    // 0x8001C294: sb          $t7, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r15;
L_8001C298:
    // 0x8001C298: jal         0x8006CAE0
    // 0x8001C29C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_8006CAE0(rdram, ctx);
        goto after_2;
    // 0x8001C29C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x8001C2A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001C2A4: lwc1        $f12, -0x480($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X480);
    // 0x8001C2A8: jal         0x8006C9DC
    // 0x8001C2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006C9DC(rdram, ctx);
        goto after_3;
    // 0x8001C2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8001C2B0: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8001C2B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001C2B8: jal         0x8006CA74
    // 0x8001C2BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8006CA74(rdram, ctx);
        goto after_4;
    // 0x8001C2BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8001C2C0: sb          $zero, 0x10($s0)
    MEM_B(0X10, ctx->r16) = 0;
    // 0x8001C2C4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8001C2C8: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
L_8001C2CC:
    // 0x8001C2CC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8001C2D0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001C2D4: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8001C2D8: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x8001C2DC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001C2E0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8001C2E4: lw          $t3, -0x69C0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X69C0);
    // 0x8001C2E8: sw          $t3, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->r11;
    // 0x8001C2EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C2F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C2F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C2F8: jr          $ra
    // 0x8001C2FC: nop

    return;
    // 0x8001C2FC: nop

;}
RECOMP_FUNC void func_8069DB18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069DB18: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8069DB1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069DB20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069DB24: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069DB28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069DB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8069DB30: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8069DB34: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8069DB38: bne         $a0, $t6, L_8069DBDC
    if (ctx->r4 != ctx->r14) {
        // 0x8069DB3C: addiu       $a0, $a0, 0xC4
        ctx->r4 = ADD32(ctx->r4, 0XC4);
            goto L_8069DBDC;
    }
    // 0x8069DB3C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8069DB40: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8069DB44: jal         0x80048F84
    // 0x8069DB48: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8069DB48: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8069DB4C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8069DB50: jal         0x80048F84
    // 0x8069DB54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8069DB54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8069DB58: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8069DB5C: jal         0x8069D988
    // 0x8069DB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069D988(rdram, ctx);
        goto after_2;
    // 0x8069DB60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8069DB64: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8069DB68: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(574, 0XC40) << 16);
    // 0x8069DB6C: addiu       $a0, $a0, -0x1E40
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(574, 0XC40));
    // 0x8069DB70: lw          $v0, 0x14($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X14);
    // 0x8069DB74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8069DB78: beq         $v0, $zero, L_8069DB88
    if (ctx->r2 == 0) {
        // 0x8069DB7C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8069DB88;
    }
    // 0x8069DB7C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8069DB80: b           L_8069DBCC
    // 0x8069DB84: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
        goto L_8069DBCC;
    // 0x8069DB84: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
L_8069DB88:
    // 0x8069DB88: lw          $t8, 0x10($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X10);
    // 0x8069DB8C: addiu       $v1, $t8, 0x1
    ctx->r3 = ADD32(ctx->r24, 0X1);
    // 0x8069DB90: slti        $at, $v1, 0x1E
    ctx->r1 = SIGNED(ctx->r3) < 0X1E ? 1 : 0;
    // 0x8069DB94: bne         $at, $zero, L_8069DBA4
    if (ctx->r1 != 0) {
        // 0x8069DB98: sw          $v1, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r3;
            goto L_8069DBA4;
    }
    // 0x8069DB98: sw          $v1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r3;
    // 0x8069DB9C: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x8069DBA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8069DBA4:
    // 0x8069DBA4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8069DBA8: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8069DBAC: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8069DBB0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8069DBB4: ori         $t3, $v0, 0x1
    ctx->r11 = ctx->r2 | 0X1;
    // 0x8069DBB8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8069DBBC: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8069DBC0: sw          $t2, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r10;
    // 0x8069DBC4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8069DBC8: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
L_8069DBCC:
    // 0x8069DBCC: jal         0x8069DAC0
    // 0x8069DBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069DAC0(rdram, ctx);
        goto after_3;
    // 0x8069DBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8069DBD4: b           L_8069DBE8
    // 0x8069DBD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8069DBE8;
    // 0x8069DBD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069DBDC:
    // 0x8069DBDC: jal         0x8069D820
    // 0x8069DBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069D820(rdram, ctx);
        goto after_4;
    // 0x8069DBE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8069DBE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8069DBE8:
    // 0x8069DBE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069DBEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8069DBF0: jr          $ra
    // 0x8069DBF4: nop

    return;
    // 0x8069DBF4: nop

;}
RECOMP_FUNC void func_8003C510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C510: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003C514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C518: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003C51C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003C520: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8003C524: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8003C528: jal         0x8004700C
    // 0x8003C52C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8003C52C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8003C530: lhu         $t6, 0xC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC);
    // 0x8003C534: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8003C538: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8003C53C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8003C540: beq         $t6, $at, L_8003C6FC
    if (ctx->r14 == ctx->r1) {
        // 0x8003C544: lw          $a3, 0x1F4($v0)
        ctx->r7 = MEM_W(ctx->r2, 0X1F4);
            goto L_8003C6FC;
    }
    // 0x8003C544: lw          $a3, 0x1F4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X1F4);
    // 0x8003C548: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8003C54C: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x8003C550: beql        $s0, $t8, L_8003C700
    if (ctx->r16 == ctx->r24) {
        // 0x8003C554: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C700;
    }
    goto skip_0;
    // 0x8003C554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003C558: lw          $t9, 0xD8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XD8);
    // 0x8003C55C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003C560: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8003C564: beq         $t9, $at, L_8003C6FC
    if (ctx->r25 == ctx->r1) {
        // 0x8003C568: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8003C6FC;
    }
    // 0x8003C568: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003C56C: lwc1        $f2, 0x1EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1EC);
    // 0x8003C570: lwc1        $f0, 0x3C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X3C);
    // 0x8003C574: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003C578: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8003C57C: nop

    // 0x8003C580: bc1tl       L_8003C5C4
    if (c1cs) {
        // 0x8003C584: lw          $t2, 0x174($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X174);
            goto L_8003C5C4;
    }
    goto skip_1;
    // 0x8003C584: lw          $t2, 0x174($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X174);
    skip_1:
    // 0x8003C588: lwc1        $f12, 0x1F0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1F0);
    // 0x8003C58C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003C590: nop

    // 0x8003C594: bc1tl       L_8003C5C4
    if (c1cs) {
        // 0x8003C598: lw          $t2, 0x174($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X174);
            goto L_8003C5C4;
    }
    goto skip_2;
    // 0x8003C598: lw          $t2, 0x174($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X174);
    skip_2:
    // 0x8003C59C: lwc1        $f0, 0x40($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X40);
    // 0x8003C5A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8003C5A4: nop

    // 0x8003C5A8: bc1tl       L_8003C5C4
    if (c1cs) {
        // 0x8003C5AC: lw          $t2, 0x174($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X174);
            goto L_8003C5C4;
    }
    goto skip_3;
    // 0x8003C5AC: lw          $t2, 0x174($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X174);
    skip_3:
    // 0x8003C5B0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003C5B4: nop

    // 0x8003C5B8: bc1fl       L_8003C700
    if (!c1cs) {
        // 0x8003C5BC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C700;
    }
    goto skip_4;
    // 0x8003C5BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8003C5C0: lw          $t2, 0x174($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X174);
L_8003C5C4:
    // 0x8003C5C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C5C8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8003C5CC: lbu         $t3, 0x12($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X12);
    // 0x8003C5D0: bnel        $t3, $zero, L_8003C5F0
    if (ctx->r11 != 0) {
        // 0x8003C5D4: lhu         $v0, 0xC($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0XC);
            goto L_8003C5F0;
    }
    goto skip_5;
    // 0x8003C5D4: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    skip_5:
    // 0x8003C5D8: jal         0x8003C3C0
    // 0x8003C5DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8003C3C0(rdram, ctx);
        goto after_1;
    // 0x8003C5DC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x8003C5E0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003C5E4: beq         $v0, $zero, L_8003C6FC
    if (ctx->r2 == 0) {
        // 0x8003C5E8: lw          $t0, 0x48($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X48);
            goto L_8003C6FC;
    }
    // 0x8003C5E8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8003C5EC: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
L_8003C5F0:
    // 0x8003C5F0: addiu       $at, $zero, 0x40B8
    ctx->r1 = ADD32(0, 0X40B8);
    // 0x8003C5F4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8003C5F8: beq         $v0, $at, L_8003C60C
    if (ctx->r2 == ctx->r1) {
        // 0x8003C5FC: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8003C60C;
    }
    // 0x8003C5FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003C600: addiu       $at, $zero, 0x466A
    ctx->r1 = ADD32(0, 0X466A);
    // 0x8003C604: bnel        $v0, $at, L_8003C654
    if (ctx->r2 != ctx->r1) {
        // 0x8003C608: lw          $t9, 0x174($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X174);
            goto L_8003C654;
    }
    goto skip_6;
    // 0x8003C608: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
    skip_6:
L_8003C60C:
    // 0x8003C60C: jal         0x8003C1B0
    // 0x8003C610: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    func_8003C1B0(rdram, ctx);
        goto after_2;
    // 0x8003C610: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_2:
    // 0x8003C614: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8003C618: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8003C61C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003C620: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8003C624: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C628: sb          $t4, 0x159($a3)
    MEM_B(0X159, ctx->r7) = ctx->r12;
    // 0x8003C62C: sb          $t5, 0x15A($a3)
    MEM_B(0X15A, ctx->r7) = ctx->r13;
    // 0x8003C630: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x8003C634: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C638: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8003C63C: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x8003C640: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8003C644: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x8003C648: b           L_8003C6FC
    // 0x8003C64C: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
        goto L_8003C6FC;
    // 0x8003C64C: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x8003C650: lw          $t9, 0x174($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X174);
L_8003C654:
    // 0x8003C654: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8003C658: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8003C65C: lhu         $v0, 0x1C($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1C);
    // 0x8003C660: andi        $v0, $v0, 0xC0
    ctx->r2 = ctx->r2 & 0XC0;
    // 0x8003C664: beq         $v0, $at, L_8003C68C
    if (ctx->r2 == ctx->r1) {
        // 0x8003C668: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8003C68C;
    }
    // 0x8003C668: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8003C66C: beq         $v0, $at, L_8003C6A8
    if (ctx->r2 == ctx->r1) {
        // 0x8003C670: addiu       $at, $zero, 0xC0
        ctx->r1 = ADD32(0, 0XC0);
            goto L_8003C6A8;
    }
    // 0x8003C670: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8003C674: bne         $v0, $at, L_8003C6FC
    if (ctx->r2 != ctx->r1) {
        // 0x8003C678: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8003C6FC;
    }
    // 0x8003C678: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8003C67C: jal         0x8003C358
    // 0x8003C680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003C358(rdram, ctx);
        goto after_3;
    // 0x8003C680: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8003C684: b           L_8003C700
    // 0x8003C688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003C700;
    // 0x8003C688: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003C68C:
    // 0x8003C68C: lbu         $t1, 0x159($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X159);
    // 0x8003C690: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003C694: beql        $t1, $zero, L_8003C6AC
    if (ctx->r9 == 0) {
        // 0x8003C698: lw          $t4, 0x28($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X28);
            goto L_8003C6AC;
    }
    goto skip_7;
    // 0x8003C698: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
    skip_7:
    // 0x8003C69C: sb          $t2, 0x159($a3)
    MEM_B(0X159, ctx->r7) = ctx->r10;
    // 0x8003C6A0: lw          $t3, 0x174($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X174);
    // 0x8003C6A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
L_8003C6A8:
    // 0x8003C6A8: lw          $t4, 0x28($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X28);
L_8003C6AC:
    // 0x8003C6AC: beql        $t4, $zero, L_8003C700
    if (ctx->r12 == 0) {
        // 0x8003C6B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003C700;
    }
    goto skip_8;
    // 0x8003C6B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8003C6B4: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8003C6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C6BC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8003C6C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8003C6C4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8003C6C8: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8003C6CC: lwc1        $f8, 0x4($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8003C6D0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C6D4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C6D8: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8003C6DC: lwc1        $f16, 0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X8);
    // 0x8003C6E0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8003C6E4: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8003C6E8: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x8003C6EC: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003C6F0: lw          $t9, 0x28($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X28);
    // 0x8003C6F4: jalr        $t9
    // 0x8003C6F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8003C6F8: nop

    after_4:
L_8003C6FC:
    // 0x8003C6FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003C700:
    // 0x8003C700: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003C704: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8003C708: jr          $ra
    // 0x8003C70C: nop

    return;
    // 0x8003C70C: nop

;}
RECOMP_FUNC void func_8069D8CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D8D4: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8069D8D8: addiu       $at, $zero, 0x457D
    ctx->r1 = ADD32(0, 0X457D);
    // 0x8069D8DC: bnel        $t6, $at, L_8069D900
    if (ctx->r14 != ctx->r1) {
        // 0x8069D8E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8069D900;
    }
    goto skip_0;
    // 0x8069D8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8069D8E4: jal         0x8005FD1C
    // 0x8069D8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8069D8E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D8EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D8F0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8069D8F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8069D8F8: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x8069D8FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8069D900:
    // 0x8069D900: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D904: jr          $ra
    // 0x8069D908: nop

    return;
    // 0x8069D908: nop

;}
RECOMP_FUNC void func_80582118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058211C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582120: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80582124: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80582128: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8058212C: jal         0x805820E0
    // 0x80582130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805820E0(rdram, ctx);
        goto after_0;
    // 0x80582130: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80582134: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80582138: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8058213C: jr          $ra
    // 0x80582140: nop

    return;
    // 0x80582140: nop

;}
RECOMP_FUNC void func_80475450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475450: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475454: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475458: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047545C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475460: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475464: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475468: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047546C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475470: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475474: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475478: jr          $ra
    // 0x8047547C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047547C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80019BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019BE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019BE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019BE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80019BEC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80019BF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80019BF4: jal         0x80019B94
    // 0x80019BF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_80019B94(rdram, ctx);
        goto after_0;
    // 0x80019BF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80019BFC: beq         $v0, $zero, L_80019C34
    if (ctx->r2 == 0) {
        // 0x80019C00: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80019C34;
    }
    // 0x80019C00: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80019C04: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80019C08: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_80019C0C:
    // 0x80019C0C: bnel        $s1, $t6, L_80019C2C
    if (ctx->r17 != ctx->r14) {
        // 0x80019C10: lw          $s0, 0x44($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X44);
            goto L_80019C2C;
    }
    goto skip_0;
    // 0x80019C10: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x80019C14: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80019C18: bnel        $s2, $t7, L_80019C2C
    if (ctx->r18 != ctx->r15) {
        // 0x80019C1C: lw          $s0, 0x44($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X44);
            goto L_80019C2C;
    }
    goto skip_1;
    // 0x80019C1C: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
    skip_1:
    // 0x80019C20: jal         0x80019A78
    // 0x80019C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80019A78(rdram, ctx);
        goto after_1;
    // 0x80019C24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80019C28: lw          $s0, 0x44($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X44);
L_80019C2C:
    // 0x80019C2C: bnel        $s0, $zero, L_80019C0C
    if (ctx->r16 != 0) {
        // 0x80019C30: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_80019C0C;
    }
    goto skip_2;
    // 0x80019C30: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_2:
L_80019C34:
    // 0x80019C34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80019C38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019C3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80019C40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80019C44: jr          $ra
    // 0x80019C48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80019C48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8046A1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046A1F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046A1FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046A200: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046A204: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2950) << 16);
    // 0x8046A208: lwc1        $f4, -0x3F70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2950));
    // 0x8046A20C: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A210: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8046A214: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8046A218: nop

    // 0x8046A21C: bc1fl       L_8046A234
    if (!c1cs) {
        // 0x8046A220: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8046A234;
    }
    goto skip_0;
    // 0x8046A220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8046A224: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8046A228: b           L_8046A268
    // 0x8046A22C: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
        goto L_8046A268;
    // 0x8046A22C: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8046A230: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8046A234:
    // 0x8046A234: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2958) << 16);
    // 0x8046A238: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8046A23C: nop

    // 0x8046A240: bc1f        L_8046A25C
    if (!c1cs) {
        // 0x8046A244: nop
    
            goto L_8046A25C;
    }
    // 0x8046A244: nop

    // 0x8046A248: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2954) << 16);
    // 0x8046A24C: lwc1        $f10, -0x3F6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2954));
    // 0x8046A250: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8046A254: b           L_8046A268
    // 0x8046A258: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
        goto L_8046A268;
    // 0x8046A258: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
L_8046A25C:
    // 0x8046A25C: lwc1        $f18, -0x3F68($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2958));
    // 0x8046A260: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8046A264: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
L_8046A268:
    // 0x8046A268: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8046A26C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8046A270: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8046A274: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8046A278: lwc1        $f12, 0x14($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8046A27C: jal         0x804697D8
    // 0x8046A280: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x8046A280: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8046A284: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8046A288: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8046A28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046A290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046A294: jr          $ra
    // 0x8046A298: nop

    return;
    // 0x8046A298: nop

;}
RECOMP_FUNC void func_800434EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800434EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800434F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800434F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800434F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800434FC: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80043500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043504: jal         0x800420B8
    // 0x80043508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800420B8(rdram, ctx);
        goto after_0;
    // 0x80043508: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8004350C: beql        $v0, $zero, L_80043600
    if (ctx->r2 == 0) {
        // 0x80043510: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043600;
    }
    goto skip_0;
    // 0x80043510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80043514: jal         0x800433D0
    // 0x80043518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800433D0(rdram, ctx);
        goto after_1;
    // 0x80043518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8004351C: jal         0x80032D1C
    // 0x80043520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80032D1C(rdram, ctx);
        goto after_2;
    // 0x80043520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80043524: bne         $v0, $zero, L_8004353C
    if (ctx->r2 != 0) {
        // 0x80043528: nop
    
            goto L_8004353C;
    }
    // 0x80043528: nop

    // 0x8004352C: jal         0x80021A44
    // 0x80043530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_3;
    // 0x80043530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80043534: b           L_80043600
    // 0x80043538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043600;
    // 0x80043538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004353C:
    // 0x8004353C: jal         0x80032D78
    // 0x80043540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80032D78(rdram, ctx);
        goto after_4;
    // 0x80043540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80043544: jal         0x80032DA4
    // 0x80043548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80032DA4(rdram, ctx);
        goto after_5;
    // 0x80043548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004354C: lbu         $t6, 0xF4($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0XF4);
    // 0x80043550: bnel        $t6, $zero, L_80043568
    if (ctx->r14 != 0) {
        // 0x80043554: lw          $t9, 0xA8($s1)
        ctx->r25 = MEM_W(ctx->r17, 0XA8);
            goto L_80043568;
    }
    goto skip_1;
    // 0x80043554: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    skip_1:
    // 0x80043558: lbu         $t7, 0x111($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X111);
    // 0x8004355C: beq         $t7, $zero, L_800435C4
    if (ctx->r15 == 0) {
        // 0x80043560: nop
    
            goto L_800435C4;
    }
    // 0x80043560: nop

    // 0x80043564: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
L_80043568:
    // 0x80043568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004356C: jalr        $t9
    // 0x80043570: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80043570: nop

    after_6:
    // 0x80043574: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
    // 0x80043578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004357C: jalr        $t9
    // 0x80043580: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80043580: nop

    after_7:
    // 0x80043584: beql        $v0, $zero, L_80043600
    if (ctx->r2 == 0) {
        // 0x80043588: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043600;
    }
    goto skip_2;
    // 0x80043588: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8004358C: lw          $t9, 0xB4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB4);
    // 0x80043590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043594: jalr        $t9
    // 0x80043598: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x80043598: nop

    after_8:
    // 0x8004359C: lw          $t9, 0xB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB8);
    // 0x800435A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800435A4: jalr        $t9
    // 0x800435A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800435A8: nop

    after_9:
    // 0x800435AC: lw          $t9, 0xBC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XBC);
    // 0x800435B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800435B4: jalr        $t9
    // 0x800435B8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x800435B8: nop

    after_10:
    // 0x800435BC: b           L_80043600
    // 0x800435C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043600;
    // 0x800435C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800435C4:
    // 0x800435C4: jal         0x80042060
    // 0x800435C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80042060(rdram, ctx);
        goto after_11;
    // 0x800435C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800435CC: jal         0x80021958
    // 0x800435D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021958(rdram, ctx);
        goto after_12;
    // 0x800435D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800435D4: beql        $v0, $zero, L_80043600
    if (ctx->r2 == 0) {
        // 0x800435D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043600;
    }
    goto skip_3;
    // 0x800435D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x800435DC: jal         0x800415FC
    // 0x800435E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800415FC(rdram, ctx);
        goto after_13;
    // 0x800435E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800435E4: bnel        $v0, $zero, L_80043600
    if (ctx->r2 != 0) {
        // 0x800435E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80043600;
    }
    goto skip_4;
    // 0x800435E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x800435EC: jal         0x80022FE4
    // 0x800435F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022FE4(rdram, ctx);
        goto after_14;
    // 0x800435F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800435F4: jal         0x80023EA0
    // 0x800435F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80023EA0(rdram, ctx);
        goto after_15;
    // 0x800435F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800435FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043600:
    // 0x80043600: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80043604: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80043608: jr          $ra
    // 0x8004360C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8004360C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80407B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80407B90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407B94: jal         0x80407BF4
    // 0x80407B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80407BF4(rdram, ctx);
        goto after_0;
    // 0x80407B98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80407B9C: beq         $v0, $zero, L_80407BDC
    if (ctx->r2 == 0) {
        // 0x80407BA0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80407BDC;
    }
    // 0x80407BA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80407BA4: jal         0x80407C70
    // 0x80407BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80407C70(rdram, ctx);
        goto after_1;
    // 0x80407BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80407BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80407BB0: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80407BB4: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80407BB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80407BBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80407BC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80407BC4: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80407BC8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80407BCC: jal         0x8040818C
    // 0x80407BD0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_8040818C(rdram, ctx);
        goto after_2;
    // 0x80407BD0: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x80407BD4: b           L_80407BE8
    // 0x80407BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407BE8;
    // 0x80407BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407BDC:
    // 0x80407BDC: jal         0x800445A4
    // 0x80407BE0: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80407BE0: nop

    after_3:
    // 0x80407BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407BE8:
    // 0x80407BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80407BEC: jr          $ra
    // 0x80407BF0: nop

    return;
    // 0x80407BF0: nop

;}
RECOMP_FUNC void func_805818EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805818EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805818F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805818F4: jal         0x80581854
    // 0x805818F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80581854(rdram, ctx);
        goto after_0;
    // 0x805818F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805818FC: bne         $v0, $zero, L_80581918
    if (ctx->r2 != 0) {
        // 0x80581900: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80581918;
    }
    // 0x80581900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581904: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581908: jal         0x80581AA4
    // 0x8058190C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80581AA4(rdram, ctx);
        goto after_1;
    // 0x8058190C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80581910: b           L_8058195C
    // 0x80581914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8058195C;
    // 0x80581914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581918:
    // 0x80581918: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8058191C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80581920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80581924: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581928: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8058192C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80581930: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80581934: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581938: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8058193C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581940: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80581944: nop

    // 0x80581948: bc1fl       L_8058195C
    if (!c1cs) {
        // 0x8058194C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8058195C;
    }
    goto skip_0;
    // 0x8058194C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80581950: jal         0x80581AA4
    // 0x80581954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80581AA4(rdram, ctx);
        goto after_2;
    // 0x80581954: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80581958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8058195C:
    // 0x8058195C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581960: jr          $ra
    // 0x80581964: nop

    return;
    // 0x80581964: nop

;}
RECOMP_FUNC void func_80682930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682930: lui         $v0, 0x8068
    ctx->r2 = S32(RELOC_HI16(553, 0X840) << 16);
    // 0x80682934: jr          $ra
    // 0x80682938: addiu       $v0, $v0, 0x3170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(553, 0X840));
    return;
    // 0x80682938: addiu       $v0, $v0, 0x3170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(553, 0X840));
;}
RECOMP_FUNC void func_804D1478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D1478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804D147C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D1480: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804D1484: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804D1488: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x804D148C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x804D1490: beql        $at, $zero, L_804D14B8
    if (ctx->r1 == 0) {
        // 0x804D1494: addiu       $a0, $a3, 0xC4
        ctx->r4 = ADD32(ctx->r7, 0XC4);
            goto L_804D14B8;
    }
    goto skip_0;
    // 0x804D1494: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    skip_0:
    // 0x804D1498: lbu         $a0, 0x10($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X10);
    // 0x804D149C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x804D14A0: jal         0x804D1454
    // 0x804D14A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804D1454(rdram, ctx);
        goto after_0;
    // 0x804D14A4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x804D14A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804D14AC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804D14B0: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    // 0x804D14B4: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
L_804D14B8:
    // 0x804D14B8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x804D14BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D14C0: jal         0x80048F84
    // 0x804D14C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804D14C4: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x804D14C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x804D14CC: jal         0x80048F84
    // 0x804D14D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804D14D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804D14D4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x804D14D8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x804D14DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804D14E0: lwc1        $f4, 0x50($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X50);
    // 0x804D14E4: lw          $v1, 0x1E0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1E0);
    // 0x804D14E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804D14EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804D14F0: sltiu       $a0, $v1, 0x1
    ctx->r4 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x804D14F4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x804D14F8: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x804D14FC: beq         $a0, $zero, L_804D1518
    if (ctx->r4 == 0) {
        // 0x804D1500: swc1        $f8, 0x50($a3)
        MEM_W(0X50, ctx->r7) = ctx->f8.u32l;
            goto L_804D1518;
    }
    // 0x804D1500: swc1        $f8, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->f8.u32l;
    // 0x804D1504: sb          $t8, 0x165($a3)
    MEM_B(0X165, ctx->r7) = ctx->r24;
    // 0x804D1508: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804D150C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804D1510: jal         0x804D1528
    // 0x804D1514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804D1528(rdram, ctx);
        goto after_3;
    // 0x804D1514: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_804D1518:
    // 0x804D1518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D151C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804D1520: jr          $ra
    // 0x804D1524: nop

    return;
    // 0x804D1524: nop

;}
RECOMP_FUNC void func_800010BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800010BC: jr          $ra
    // 0x800010C0: nop

    return;
    // 0x800010C0: nop

;}
RECOMP_FUNC void func_805DB0C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DB0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DB0C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805DB0CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805DB0D0: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x805DB0D4: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805DB0D8: jal         0x80067BBC
    // 0x805DB0DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805DB0DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x805DB0E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805DB0E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805DB0E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805DB0EC: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x805DB0F0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x805DB0F4: bne         $a1, $at, L_805DB128
    if (ctx->r5 != ctx->r1) {
        // 0x805DB0F8: nop
    
            goto L_805DB128;
    }
    // 0x805DB0F8: nop

    // 0x805DB0FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805DB100: jal         0x80067F78
    // 0x805DB104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x805DB104: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x805DB108: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805DB10C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805DB110: sh          $v0, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r2;
    // 0x805DB114: lh          $t6, 0x1F0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X1F0);
    // 0x805DB118: bnel        $t6, $at, L_805DB134
    if (ctx->r14 != ctx->r1) {
        // 0x805DB11C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805DB134;
    }
    goto skip_0;
    // 0x805DB11C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805DB120: b           L_805DB134
    // 0x805DB124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805DB134;
    // 0x805DB124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DB128:
    // 0x805DB128: jal         0x800678F0
    // 0x805DB12C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x805DB12C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_2:
    // 0x805DB130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805DB134:
    // 0x805DB134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DB138: jr          $ra
    // 0x805DB13C: nop

    return;
    // 0x805DB13C: nop

;}
RECOMP_FUNC void func_806FA644(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA644: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806FA648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FA64C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806FA650: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806FA654: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806FA658: jal         0x80047090
    // 0x806FA65C: addiu       $a0, $zero, 0x45F2
    ctx->r4 = ADD32(0, 0X45F2);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806FA65C: addiu       $a0, $zero, 0x45F2
    ctx->r4 = ADD32(0, 0X45F2);
    after_0:
    // 0x806FA660: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x806FA664: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x806FA668: beq         $v0, $at, L_806FA6DC
    if (ctx->r2 == ctx->r1) {
        // 0x806FA66C: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_806FA6DC;
    }
    // 0x806FA66C: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x806FA670: lui         $at, 0x45F2
    ctx->r1 = S32(0X45F2 << 16);
    // 0x806FA674: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806FA678: or          $a0, $t0, $at
    ctx->r4 = ctx->r8 | ctx->r1;
    // 0x806FA67C: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x806FA680: lw          $a2, 0x4($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X4);
    // 0x806FA684: jal         0x8004613C
    // 0x806FA688: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806FA688: lw          $a3, 0x8($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X8);
    after_1:
    // 0x806FA68C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x806FA690: beq         $v0, $zero, L_806FA6DC
    if (ctx->r2 == 0) {
        // 0x806FA694: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806FA6DC;
    }
    // 0x806FA694: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806FA698: beql        $v1, $zero, L_806FA6BC
    if (ctx->r3 == 0) {
        // 0x806FA69C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_806FA6BC;
    }
    goto skip_0;
    // 0x806FA69C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_0:
    // 0x806FA6A0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806FA6A4: swc1        $f4, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f4.u32l;
    // 0x806FA6A8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806FA6AC: swc1        $f6, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f6.u32l;
    // 0x806FA6B0: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x806FA6B4: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x806FA6B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_806FA6BC:
    // 0x806FA6BC: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x806FA6C0: sw          $t6, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r14;
    // 0x806FA6C4: jal         0x80047F9C
    // 0x806FA6C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806FA6C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x806FA6CC: jal         0x806F9EA4
    // 0x806FA6D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_806F9EA4(rdram, ctx);
        goto after_3;
    // 0x806FA6D0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x806FA6D4: b           L_806FA6E0
    // 0x806FA6D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_806FA6E0;
    // 0x806FA6D8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_806FA6DC:
    // 0x806FA6DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FA6E0:
    // 0x806FA6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FA6E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806FA6E8: jr          $ra
    // 0x806FA6EC: nop

    return;
    // 0x806FA6EC: nop

;}
RECOMP_FUNC void func_80681A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681A18: jr          $ra
    // 0x80681A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80681A1C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806FD7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD800: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x806FD804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806FD808: beq         $t6, $zero, L_806FD844
    if (ctx->r14 == 0) {
        // 0x806FD80C: nop
    
            goto L_806FD844;
    }
    // 0x806FD80C: nop

    // 0x806FD810: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806FD814: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x806FD818: jalr        $t9
    // 0x806FD81C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806FD81C: nop

    after_0:
    // 0x806FD820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FD824: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x806FD828: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x806FD82C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x806FD830: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x806FD834: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x806FD838: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x806FD83C: b           L_806FD844
    // 0x806FD840: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_806FD844;
    // 0x806FD840: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_806FD844:
    // 0x806FD844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FD848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FD84C: jr          $ra
    // 0x806FD850: nop

    return;
    // 0x806FD850: nop

;}
RECOMP_FUNC void func_805275CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805275CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805275D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805275D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805275D8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805275DC: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805275E0: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805275E4: jal         0x80067BBC
    // 0x805275E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805275E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x805275EC: addiu       $a0, $zero, 0x99
    ctx->r4 = ADD32(0, 0X99);
    // 0x805275F0: jal         0x80067818
    // 0x805275F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805275F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805275F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x805275FC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6180) << 16);
    // 0x80527600: lwc1        $f4, -0x3F80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6180));
    // 0x80527604: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527608: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X5670) << 16);
    // 0x8052760C: addiu       $v0, $v0, -0x4A90
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X5670));
    // 0x80527610: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X174C) << 16);
    // 0x80527614: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80527618: addiu       $t7, $t7, 0x764C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X174C));
    // 0x8052761C: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527620: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80527624: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527628: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8052762C: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527630: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527634: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527638: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x8052763C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527644: jr          $ra
    // 0x80527648: nop

    return;
    // 0x80527648: nop

;}
RECOMP_FUNC void func_8069CD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CD84: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8069CD88: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8069CD8C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8069CD90: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8069CD94: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8069CD98: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8069CD9C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8069CDA0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8069CDA4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8069CDA8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8069CDAC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8069CDB0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069CDB4: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x8069CDB8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8069CDBC: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8069CDC0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8069CDC4: addiu       $v0, $sp, 0x88
    ctx->r2 = ADD32(ctx->r29, 0X88);
    // 0x8069CDC8: lhu         $t6, 0x4($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X4);
    // 0x8069CDCC: lhu         $s0, 0x0($t0)
    ctx->r16 = MEM_HU(ctx->r8, 0X0);
    // 0x8069CDD0: lhu         $s1, 0x2($t0)
    ctx->r17 = MEM_HU(ctx->r8, 0X2);
    // 0x8069CDD4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8069CDD8: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8069CDDC: bgez        $t6, L_8069CDF0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8069CDE0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8069CDF0;
    }
    // 0x8069CDE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8069CDE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8069CDE8: nop

    // 0x8069CDEC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8069CDF0:
    // 0x8069CDF0: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8069CDF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8069CDF8: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x8069CDFC: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    // 0x8069CE00: lhu         $t7, 0x2($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X2);
    // 0x8069CE04: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8069CE08: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8069CE0C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8069CE10: bgez        $t7, L_8069CE24
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8069CE14: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8069CE24;
    }
    // 0x8069CE14: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8069CE18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8069CE1C: nop

    // 0x8069CE20: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_8069CE24:
    // 0x8069CE24: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8069CE28: sub.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8069CE2C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8069CE30: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x8069CE34: mflo        $a2
    ctx->r6 = lo;
    // 0x8069CE38: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8069CE3C: blez        $a2, L_8069CE60
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8069CE40: addu        $a1, $t8, $t9
        ctx->r5 = ADD32(ctx->r24, ctx->r25);
            goto L_8069CE60;
    }
    // 0x8069CE40: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_8069CE44:
    // 0x8069CE44: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8069CE48: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8069CE4C: sh          $a0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r4;
    // 0x8069CE50: sh          $a0, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r4;
    // 0x8069CE54: sh          $a0, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r4;
    // 0x8069CE58: bne         $at, $zero, L_8069CE44
    if (ctx->r1 != 0) {
        // 0x8069CE5C: sh          $a0, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r4;
            goto L_8069CE44;
    }
    // 0x8069CE5C: sh          $a0, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r4;
L_8069CE60:
    // 0x8069CE60: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8069CE64: sw          $t0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r8;
    // 0x8069CE68: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8069CE6C: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8069CE70: nop

    // 0x8069CE74: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8069CE78: jal         0x8006A99C
    // 0x8069CE7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8069CE7C: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x8069CE80: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8069CE84: sll         $s2, $v0, 16
    ctx->r18 = S32(ctx->r2 << 16);
    // 0x8069CE88: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x8069CE8C: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8069CE90: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8069CE94: nop

    // 0x8069CE98: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8069CE9C: jal         0x8006A99C
    // 0x8069CEA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8069CEA0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8069CEA4: addiu       $s7, $sp, 0x88
    ctx->r23 = ADD32(ctx->r29, 0X88);
    // 0x8069CEA8: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8069CEAC: sll         $a1, $s2, 16
    ctx->r5 = S32(ctx->r18 << 16);
    // 0x8069CEB0: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8069CEB4: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8069CEB8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8069CEBC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8069CEC0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8069CEC4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8069CEC8: jal         0x8006AFA0
    // 0x8069CECC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    func_8006AFA0(rdram, ctx);
        goto after_2;
    // 0x8069CECC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x8069CED0: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x8069CED4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8069CED8: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x8069CEDC: lhu         $s4, 0x0($t0)
    ctx->r20 = MEM_HU(ctx->r8, 0X0);
    // 0x8069CEE0: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x8069CEE4: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x8069CEE8: blez        $s4, L_8069CF80
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8069CEEC: sll         $s5, $s4, 1
        ctx->r21 = S32(ctx->r20 << 1);
            goto L_8069CF80;
    }
    // 0x8069CEEC: sll         $s5, $s4, 1
    ctx->r21 = S32(ctx->r20 << 1);
L_8069CEF0:
    // 0x8069CEF0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8069CEF4: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8069CEF8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8069CEFC: addu        $t5, $s7, $t4
    ctx->r13 = ADD32(ctx->r23, ctx->r12);
    // 0x8069CF00: lhu         $a0, 0x0($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0X0);
    // 0x8069CF04: andi        $v1, $v0, 0xF000
    ctx->r3 = ctx->r2 & 0XF000;
    // 0x8069CF08: sra         $v1, $v1, 12
    ctx->r3 = S32(SIGNED(ctx->r3) >> 12);
    // 0x8069CF0C: beq         $s6, $a0, L_8069CF70
    if (ctx->r22 == ctx->r4) {
        // 0x8069CF10: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8069CF70;
    }
    // 0x8069CF10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8069CF14: andi        $a3, $v0, 0xF00
    ctx->r7 = ctx->r2 & 0XF00;
    // 0x8069CF18: andi        $a2, $a2, 0xF800
    ctx->r6 = ctx->r6 & 0XF800;
    // 0x8069CF1C: beq         $fp, $zero, L_8069CF54
    if (ctx->r30 == 0) {
        // 0x8069CF20: sra         $a3, $a3, 8
        ctx->r7 = S32(SIGNED(ctx->r7) >> 8);
            goto L_8069CF54;
    }
    // 0x8069CF20: sra         $a3, $a3, 8
    ctx->r7 = S32(SIGNED(ctx->r7) >> 8);
    // 0x8069CF24: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x8069CF28: addu        $a0, $s2, $v1
    ctx->r4 = ADD32(ctx->r18, ctx->r3);
    // 0x8069CF2C: addu        $a1, $s3, $a3
    ctx->r5 = ADD32(ctx->r19, ctx->r7);
    // 0x8069CF30: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8069CF34: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8069CF38: or          $a2, $t6, $a2
    ctx->r6 = ctx->r14 | ctx->r6;
    // 0x8069CF3C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x8069CF40: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8069CF44: jal         0x8006B1C8
    // 0x8069CF48: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_3;
    // 0x8069CF48: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_3:
    // 0x8069CF4C: b           L_8069CF74
    // 0x8069CF50: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
        goto L_8069CF74;
    // 0x8069CF50: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8069CF54:
    // 0x8069CF54: addu        $a0, $s2, $v1
    ctx->r4 = ADD32(ctx->r18, ctx->r3);
    // 0x8069CF58: addu        $a1, $s3, $a3
    ctx->r5 = ADD32(ctx->r19, ctx->r7);
    // 0x8069CF5C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8069CF60: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8069CF64: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8069CF68: jal         0x8006B1C8
    // 0x8069CF6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_8006B1C8(rdram, ctx);
        goto after_4;
    // 0x8069CF6C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_4:
L_8069CF70:
    // 0x8069CF70: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8069CF74:
    // 0x8069CF74: slt         $at, $s1, $s5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8069CF78: bne         $at, $zero, L_8069CEF0
    if (ctx->r1 != 0) {
        // 0x8069CF7C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8069CEF0;
    }
    // 0x8069CF7C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8069CF80:
    // 0x8069CF80: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8069CF84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8069CF88: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8069CF8C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8069CF90: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8069CF94: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8069CF98: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8069CF9C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8069CFA0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8069CFA4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8069CFA8: jr          $ra
    // 0x8069CFAC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8069CFAC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_80530F54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530F54: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80530F58: sll         $t8, $a2, 6
    ctx->r24 = S32(ctx->r6 << 6);
    // 0x80530F5C: addu        $t9, $a1, $t8
    ctx->r25 = ADD32(ctx->r5, ctx->r24);
    // 0x80530F60: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80530F64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80530F68: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80530F6C: ori         $t7, $t7, 0x207F
    ctx->r15 = ctx->r15 | 0X207F;
    // 0x80530F70: addiu       $t0, $t9, 0x278
    ctx->r8 = ADD32(ctx->r25, 0X278);
    // 0x80530F74: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80530F78: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80530F7C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80530F80: lui         $t2, 0xB100
    ctx->r10 = S32(0XB100 << 16);
    // 0x80530F84: lui         $t3, 0x6
    ctx->r11 = S32(0X6 << 16);
    // 0x80530F88: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80530F8C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80530F90: ori         $t3, $t3, 0x4
    ctx->r11 = ctx->r11 | 0X4;
    // 0x80530F94: ori         $t2, $t2, 0x204
    ctx->r10 = ctx->r10 | 0X204;
    // 0x80530F98: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80530F9C: jr          $ra
    // 0x80530FA0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    return;
    // 0x80530FA0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
;}
RECOMP_FUNC void func_804243EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804243EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804243F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804243F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804243F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804243FC: jal         0x80051194
    // 0x80424400: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80424400: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80424404: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80424408: jal         0x804234C0
    // 0x8042440C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804234C0(rdram, ctx);
        goto after_1;
    // 0x8042440C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80424410: bne         $v0, $zero, L_80424428
    if (ctx->r2 != 0) {
        // 0x80424414: nop
    
            goto L_80424428;
    }
    // 0x80424414: nop

    // 0x80424418: jal         0x800445A4
    // 0x8042441C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8042441C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80424420: b           L_80424540
    // 0x80424424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424540;
    // 0x80424424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424428:
    // 0x80424428: jal         0x800653D8
    // 0x8042442C: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x8042442C: nop

    after_3:
    // 0x80424430: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80424434: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80424438: mfhi        $t6
    ctx->r14 = hi;
    // 0x8042443C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80424440: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80424444: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80424448: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8042444C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80424450: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80424454: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424458: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8042445C: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x80424460: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80424464: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X31C8) << 16);
    // 0x80424468: addiu       $t2, $t2, 0x5BC8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(35, 0X31C8));
    // 0x8042446C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80424474: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80424478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8042447C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80424480: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x80424484: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424488: sw          $zero, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = 0;
    // 0x8042448C: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80424490: lw          $t9, 0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF4);
    // 0x80424494: sw          $t9, 0xF8($v1)
    MEM_W(0XF8, ctx->r3) = ctx->r25;
    // 0x80424498: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042449C: sw          $zero, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = 0;
    // 0x804244A0: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x804244A4: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x804244A8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804244AC: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x804244B0: jal         0x80424550
    // 0x804244B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_80424550(rdram, ctx);
        goto after_4;
    // 0x804244B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_4:
    // 0x804244B8: jal         0x80047090
    // 0x804244BC: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x804244BC: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    after_5:
    // 0x804244C0: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x804244C4: bne         $a0, $v0, L_804244DC
    if (ctx->r4 != ctx->r2) {
        // 0x804244C8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804244DC;
    }
    // 0x804244C8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804244CC: jal         0x800445A4
    // 0x804244D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x804244D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804244D4: b           L_80424540
    // 0x804244D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424540;
    // 0x804244D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804244DC:
    // 0x804244DC: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x804244E0: beql        $a0, $t4, L_80424540
    if (ctx->r4 == ctx->r12) {
        // 0x804244E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80424540;
    }
    goto skip_0;
    // 0x804244E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804244E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804244EC: lui         $at, 0x4066
    ctx->r1 = S32(0X4066 << 16);
    // 0x804244F0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804244F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804244F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804244FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80424500: jal         0x8004613C
    // 0x80424504: nop

    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x80424504: nop

    after_7:
    // 0x80424508: beq         $v0, $zero, L_80424534
    if (ctx->r2 == 0) {
        // 0x8042450C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80424534;
    }
    // 0x8042450C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80424510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80424514: jal         0x80047F9C
    // 0x80424518: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80424518: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_8:
    // 0x8042451C: jal         0x804255F0
    // 0x80424520: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_804255F0(rdram, ctx);
        goto after_9;
    // 0x80424520: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80424524: jal         0x804235A8
    // 0x80424528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804235A8(rdram, ctx);
        goto after_10;
    // 0x80424528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8042452C: b           L_80424540
    // 0x80424530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80424540;
    // 0x80424530: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424534:
    // 0x80424534: jal         0x800445A4
    // 0x80424538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x80424538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8042453C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80424540:
    // 0x80424540: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80424544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80424548: jr          $ra
    // 0x8042454C: nop

    return;
    // 0x8042454C: nop

;}
RECOMP_FUNC void func_805E4920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4920: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805E4924: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4928: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E492C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4930: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4934: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E4938: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805E493C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805E4940: jal         0x805E4378
    // 0x805E4944: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E4944: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x805E4948: jal         0x805E478C
    // 0x805E494C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E478C(rdram, ctx);
        goto after_1;
    // 0x805E494C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E4950: jal         0x805E4460
    // 0x805E4954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_2;
    // 0x805E4954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805E4958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805E495C: bne         $v0, $at, L_805E497C
    if (ctx->r2 != ctx->r1) {
        // 0x805E4960: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805E497C;
    }
    // 0x805E4960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4964: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x805E4968: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x805E496C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4970: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x805E4974: jal         0x805E4D78
    // 0x805E4978: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_805E4D78(rdram, ctx);
        goto after_3;
    // 0x805E4978: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_3:
L_805E497C:
    // 0x805E497C: jal         0x805E4674
    // 0x805E4980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_4;
    // 0x805E4980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805E4984: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4988: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E498C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805E4990: jr          $ra
    // 0x805E4994: nop

    return;
    // 0x805E4994: nop

;}
RECOMP_FUNC void func_804CED5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CED5C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CED60: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B08) << 16);
    // 0x804CED64: lwc1        $f4, -0x248($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B08));
    // 0x804CED68: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CED6C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x804CED70: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804CED74: nop

    // 0x804CED78: bc1fl       L_804CED90
    if (!c1cs) {
        // 0x804CED7C: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_804CED90;
    }
    goto skip_0;
    // 0x804CED7C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x804CED80: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CED84: jr          $ra
    // 0x804CED88: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x804CED88: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804CED8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_804CED90:
    // 0x804CED90: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B14) << 16);
    // 0x804CED94: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x804CED98: nop

    // 0x804CED9C: bc1f        L_804CEDD8
    if (!c1cs) {
        // 0x804CEDA0: nop
    
            goto L_804CEDD8;
    }
    // 0x804CEDA0: nop

    // 0x804CEDA4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B0C) << 16);
    // 0x804CEDA8: lwc1        $f0, -0x244($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B0C));
    // 0x804CEDAC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B10) << 16);
    // 0x804CEDB0: lwc1        $f10, -0x240($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B10));
    // 0x804CEDB4: sub.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x804CEDB8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x804CEDBC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CEDC0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x804CEDC4: nop

    // 0x804CEDC8: bc1f        L_804CEE04
    if (!c1cs) {
        // 0x804CEDCC: nop
    
            goto L_804CEE04;
    }
    // 0x804CEDCC: nop

    // 0x804CEDD0: jr          $ra
    // 0x804CEDD4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x804CEDD4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_804CEDD8:
    // 0x804CEDD8: lwc1        $f0, -0x23C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B14));
    // 0x804CEDDC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B18) << 16);
    // 0x804CEDE0: lwc1        $f4, -0x238($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B18));
    // 0x804CEDE4: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x804CEDE8: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x804CEDEC: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804CEDF0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x804CEDF4: nop

    // 0x804CEDF8: bc1f        L_804CEE04
    if (!c1cs) {
        // 0x804CEDFC: nop
    
            goto L_804CEE04;
    }
    // 0x804CEDFC: nop

    // 0x804CEE00: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
L_804CEE04:
    // 0x804CEE04: jr          $ra
    // 0x804CEE08: nop

    return;
    // 0x804CEE08: nop

;}
RECOMP_FUNC void func_80019A78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019A78: beq         $a0, $zero, L_80019ABC
    if (ctx->r4 == 0) {
        // 0x80019A7C: nop
    
            goto L_80019ABC;
    }
    // 0x80019A7C: nop

    // 0x80019A80: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80019A84: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x80019A88: bnel        $v0, $zero, L_80019AA4
    if (ctx->r2 != 0) {
        // 0x80019A8C: lw          $t7, 0x44($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X44);
            goto L_80019AA4;
    }
    goto skip_0;
    // 0x80019A8C: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    skip_0:
    // 0x80019A90: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80019A94: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80019A98: b           L_80019AA8
    // 0x80019A9C: sw          $t6, -0x20($at)
    MEM_W(-0X20, ctx->r1) = ctx->r14;
        goto L_80019AA8;
    // 0x80019A9C: sw          $t6, -0x20($at)
    MEM_W(-0X20, ctx->r1) = ctx->r14;
    // 0x80019AA0: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
L_80019AA4:
    // 0x80019AA4: sw          $t7, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r15;
L_80019AA8:
    // 0x80019AA8: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x80019AAC: beq         $v0, $zero, L_80019ABC
    if (ctx->r2 == 0) {
        // 0x80019AB0: nop
    
            goto L_80019ABC;
    }
    // 0x80019AB0: nop

    // 0x80019AB4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80019AB8: sw          $t8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r24;
L_80019ABC:
    // 0x80019ABC: jr          $ra
    // 0x80019AC0: nop

    return;
    // 0x80019AC0: nop

;}
RECOMP_FUNC void func_8057AE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057AE34: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8057AE38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057AE3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057AE40: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8057AE44: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057AE48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8057AE4C: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    // 0x8057AE50: lw          $a2, 0x3C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X3C);
    // 0x8057AE54: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8057AE58: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057AE5C: jal         0x8057A6CC
    // 0x8057AE60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8057A6CC(rdram, ctx);
        goto after_0;
    // 0x8057AE60: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057AE64: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8057AE68: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057AE6C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057AE70: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x8057AE74: bne         $at, $zero, L_8057B0B8
    if (ctx->r1 != 0) {
        // 0x8057AE78: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8057B0B8;
    }
    // 0x8057AE78: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8057AE7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057AE80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8057AE84: jal         0x8004700C
    // 0x8057AE88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8057AE88: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8057AE8C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057AE90: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057AE94: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8057AE98: beq         $v0, $zero, L_8057B0B8
    if (ctx->r2 == 0) {
        // 0x8057AE9C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8057B0B8;
    }
    // 0x8057AE9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8057AEA0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057AEA4: lw          $t7, -0x7BAC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BAC);
    // 0x8057AEA8: addiu       $t8, $t7, -0x9
    ctx->r24 = ADD32(ctx->r15, -0X9);
    // 0x8057AEAC: sltiu       $at, $t8, 0x10
    ctx->r1 = ctx->r24 < 0X10 ? 1 : 0;
    // 0x8057AEB0: beq         $at, $zero, L_8057AEDC
    if (ctx->r1 == 0) {
        // 0x8057AEB4: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_8057AEDC;
    }
    // 0x8057AEB4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8057AEB8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B80) << 16);
    // 0x8057AEBC: addu        $at, $at, $t8
    gpr jr_addend_8057AEC4 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8057AEC0: lw          $t8, -0x4A40($at)
    ctx->r24 = ADD32(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B80));
    // 0x8057AEC4: jr          $t8
    // 0x8057AEC8: nop

    switch (jr_addend_8057AEC4 >> 2) {
        case 0: goto L_8057AECC; break;
        case 1: goto L_8057AECC; break;
        case 2: goto L_8057AECC; break;
        case 3: goto L_8057AECC; break;
        case 4: goto L_8057AEDC; break;
        case 5: goto L_8057AEDC; break;
        case 6: goto L_8057AEDC; break;
        case 7: goto L_8057AEDC; break;
        case 8: goto L_8057AEDC; break;
        case 9: goto L_8057AEDC; break;
        case 10: goto L_8057AEDC; break;
        case 11: goto L_8057AEDC; break;
        case 12: goto L_8057AECC; break;
        case 13: goto L_8057AECC; break;
        case 14: goto L_8057AECC; break;
        case 15: goto L_8057AECC; break;
        default: switch_error(__func__, 0x8057AEC4, 0x8057B5C0);
    }
    // 0x8057AEC8: nop

L_8057AECC:
    // 0x8057AECC: lw          $t1, 0x1F4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X1F4);
    // 0x8057AED0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8057AED4: b           L_8057B0B8
    // 0x8057AED8: sb          $t9, 0x1B4($t1)
    MEM_B(0X1B4, ctx->r9) = ctx->r25;
        goto L_8057B0B8;
    // 0x8057AED8: sb          $t9, 0x1B4($t1)
    MEM_B(0X1B4, ctx->r9) = ctx->r25;
L_8057AEDC:
    // 0x8057AEDC: jal         0x8002FD78
    // 0x8057AEE0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8002FD78(rdram, ctx);
        goto after_2;
    // 0x8057AEE0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8057AEE4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8057AEE8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8057AEEC: addiu       $t2, $zero, 0xBE
    ctx->r10 = ADD32(0, 0XBE);
    // 0x8057AEF0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8057AEF4: sw          $t2, 0x390($t0)
    MEM_W(0X390, ctx->r8) = ctx->r10;
    // 0x8057AEF8: lwc1        $f0, -0x7638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7638);
    // 0x8057AEFC: lwc1        $f4, 0x48($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X48);
    // 0x8057AF00: lwc1        $f8, 0xC0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC0);
    // 0x8057AF04: lwc1        $f16, 0x4C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4C);
    // 0x8057AF08: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8057AF0C: lwc1        $f4, 0xC4($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x8057AF10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8057AF14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8057AF18: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8057AF1C: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8057AF20: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AF24: swc1        $f6, 0x394($t0)
    MEM_W(0X394, ctx->r8) = ctx->f6.u32l;
    // 0x8057AF28: sw          $zero, 0x31C($t0)
    MEM_W(0X31C, ctx->r8) = 0;
    // 0x8057AF2C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8057AF30: swc1        $f10, 0x398($t0)
    MEM_W(0X398, ctx->r8) = ctx->f10.u32l;
    // 0x8057AF34: sw          $zero, 0x318($t0)
    MEM_W(0X318, ctx->r8) = 0;
    // 0x8057AF38: addiu       $v0, $t0, 0x8
    ctx->r2 = ADD32(ctx->r8, 0X8);
    // 0x8057AF3C: swc1        $f18, 0x39C($t0)
    MEM_W(0X39C, ctx->r8) = ctx->f18.u32l;
    // 0x8057AF40: addiu       $v1, $t0, 0x10
    ctx->r3 = ADD32(ctx->r8, 0X10);
    // 0x8057AF44: swc1        $f2, 0x1B0($t0)
    MEM_W(0X1B0, ctx->r8) = ctx->f2.u32l;
    // 0x8057AF48: swc1        $f6, 0x3A0($t0)
    MEM_W(0X3A0, ctx->r8) = ctx->f6.u32l;
    // 0x8057AF4C: swc1        $f2, 0x138($t0)
    MEM_W(0X138, ctx->r8) = ctx->f2.u32l;
    // 0x8057AF50: swc1        $f2, 0x1B4($t0)
    MEM_W(0X1B4, ctx->r8) = ctx->f2.u32l;
    // 0x8057AF54: swc1        $f2, 0x13C($t0)
    MEM_W(0X13C, ctx->r8) = ctx->f2.u32l;
    // 0x8057AF58: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8057AF5C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057AF60: sw          $zero, 0x318($v0)
    MEM_W(0X318, ctx->r2) = 0;
    // 0x8057AF64: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AF68: swc1        $f2, 0x1B0($v0)
    MEM_W(0X1B0, ctx->r2) = ctx->f2.u32l;
    // 0x8057AF6C: beq         $a0, $a3, L_8057B014
    if (ctx->r4 == ctx->r7) {
        // 0x8057AF70: swc1        $f2, 0x138($v0)
        MEM_W(0X138, ctx->r2) = ctx->f2.u32l;
            goto L_8057B014;
    }
    // 0x8057AF70: swc1        $f2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f2.u32l;
L_8057AF74:
    // 0x8057AF74: swc1        $f18, 0x394($v1)
    MEM_W(0X394, ctx->r3) = ctx->f18.u32l;
    // 0x8057AF78: lwc1        $f16, 0xC0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x8057AF7C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8057AF80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057AF84: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AF88: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8057AF8C: swc1        $f16, 0x378($v1)
    MEM_W(0X378, ctx->r3) = ctx->f16.u32l;
    // 0x8057AF90: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8057AF94: sw          $zero, 0x30C($v0)
    MEM_W(0X30C, ctx->r2) = 0;
    // 0x8057AF98: swc1        $f2, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->f2.u32l;
    // 0x8057AF9C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFA0: swc1        $f2, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f2.u32l;
    // 0x8057AFA4: swc1        $f16, 0x37C($v1)
    MEM_W(0X37C, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFA8: lwc1        $f16, 0xB4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x8057AFAC: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFB0: swc1        $f16, 0x380($v1)
    MEM_W(0X380, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFB4: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8057AFB8: sw          $zero, 0x310($v0)
    MEM_W(0X310, ctx->r2) = 0;
    // 0x8057AFBC: swc1        $f2, 0x1A8($v0)
    MEM_W(0X1A8, ctx->r2) = ctx->f2.u32l;
    // 0x8057AFC0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFC4: swc1        $f2, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f2.u32l;
    // 0x8057AFC8: swc1        $f16, 0x384($v1)
    MEM_W(0X384, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFCC: lwc1        $f16, 0xB8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x8057AFD0: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFD4: swc1        $f16, 0x388($v1)
    MEM_W(0X388, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFD8: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8057AFDC: sw          $zero, 0x314($v0)
    MEM_W(0X314, ctx->r2) = 0;
    // 0x8057AFE0: swc1        $f2, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = ctx->f2.u32l;
    // 0x8057AFE4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFE8: swc1        $f2, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f2.u32l;
    // 0x8057AFEC: swc1        $f16, 0x38C($v1)
    MEM_W(0X38C, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFF0: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x8057AFF4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057AFF8: swc1        $f16, 0x390($v1)
    MEM_W(0X390, ctx->r3) = ctx->f16.u32l;
    // 0x8057AFFC: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8057B000: sw          $zero, 0x318($v0)
    MEM_W(0X318, ctx->r2) = 0;
    // 0x8057B004: swc1        $f2, 0x1B0($v0)
    MEM_W(0X1B0, ctx->r2) = ctx->f2.u32l;
    // 0x8057B008: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B00C: bne         $a0, $a3, L_8057AF74
    if (ctx->r4 != ctx->r7) {
        // 0x8057B010: swc1        $f2, 0x138($v0)
        MEM_W(0X138, ctx->r2) = ctx->f2.u32l;
            goto L_8057AF74;
    }
    // 0x8057B010: swc1        $f2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->f2.u32l;
L_8057B014:
    // 0x8057B014: swc1        $f18, 0x394($v1)
    MEM_W(0X394, ctx->r3) = ctx->f18.u32l;
    // 0x8057B018: lwc1        $f16, 0xC0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x8057B01C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8057B020: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x8057B024: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B028: swc1        $f16, 0x378($v1)
    MEM_W(0X378, ctx->r3) = ctx->f16.u32l;
    // 0x8057B02C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8057B030: swc1        $f2, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f2.u32l;
    // 0x8057B034: swc1        $f2, 0x1A4($v0)
    MEM_W(0X1A4, ctx->r2) = ctx->f2.u32l;
    // 0x8057B038: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B03C: sw          $zero, 0x30C($v0)
    MEM_W(0X30C, ctx->r2) = 0;
    // 0x8057B040: swc1        $f16, 0x37C($v1)
    MEM_W(0X37C, ctx->r3) = ctx->f16.u32l;
    // 0x8057B044: lwc1        $f16, 0xB4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x8057B048: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B04C: swc1        $f16, 0x380($v1)
    MEM_W(0X380, ctx->r3) = ctx->f16.u32l;
    // 0x8057B050: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8057B054: swc1        $f2, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f2.u32l;
    // 0x8057B058: swc1        $f2, 0x1A8($v0)
    MEM_W(0X1A8, ctx->r2) = ctx->f2.u32l;
    // 0x8057B05C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B060: sw          $zero, 0x310($v0)
    MEM_W(0X310, ctx->r2) = 0;
    // 0x8057B064: swc1        $f16, 0x384($v1)
    MEM_W(0X384, ctx->r3) = ctx->f16.u32l;
    // 0x8057B068: lwc1        $f16, 0xB8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x8057B06C: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B070: swc1        $f16, 0x388($v1)
    MEM_W(0X388, ctx->r3) = ctx->f16.u32l;
    // 0x8057B074: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8057B078: swc1        $f2, 0x134($v0)
    MEM_W(0X134, ctx->r2) = ctx->f2.u32l;
    // 0x8057B07C: swc1        $f2, 0x1AC($v0)
    MEM_W(0X1AC, ctx->r2) = ctx->f2.u32l;
    // 0x8057B080: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B084: sw          $zero, 0x314($v0)
    MEM_W(0X314, ctx->r2) = 0;
    // 0x8057B088: swc1        $f16, 0x38C($v1)
    MEM_W(0X38C, ctx->r3) = ctx->f16.u32l;
    // 0x8057B08C: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x8057B090: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8057B094: swc1        $f16, 0x390($v1)
    MEM_W(0X390, ctx->r3) = ctx->f16.u32l;
    // 0x8057B098: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1BC0) << 16);
    // 0x8057B09C: lwc1        $f4, -0x4A00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1BC0));
    // 0x8057B0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057B0A4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8057B0A8: jal         0x8057B444
    // 0x8057B0AC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    func_8057B444(rdram, ctx);
        goto after_3;
    // 0x8057B0AC: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8057B0B0: b           L_8057B230
    // 0x8057B0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8057B230;
    // 0x8057B0B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057B0B8:
    // 0x8057B0B8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8057B0BC: lwc1        $f0, 0x228($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X228);
    // 0x8057B0C0: lwc1        $f6, 0x2A0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B0C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057B0C8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8057B0CC: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8057B0D0: bc1f        L_8057B110
    if (!c1cs) {
        // 0x8057B0D4: swc1        $f8, 0x2A0($t0)
        MEM_W(0X2A0, ctx->r8) = ctx->f8.u32l;
            goto L_8057B110;
    }
    // 0x8057B0D4: swc1        $f8, 0x2A0($t0)
    MEM_W(0X2A0, ctx->r8) = ctx->f8.u32l;
    // 0x8057B0D8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8057B0DC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057B0E0: lwc1        $f12, 0x2A0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B0E4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8057B0E8: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x8057B0EC: nop

    // 0x8057B0F0: bc1fl       L_8057B150
    if (!c1cs) {
        // 0x8057B0F4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8057B150;
    }
    goto skip_0;
    // 0x8057B0F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    skip_0:
    // 0x8057B0F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8057B0FC: swc1        $f2, 0x2A0($t0)
    MEM_W(0X2A0, ctx->r8) = ctx->f2.u32l;
    // 0x8057B100: lwc1        $f12, 0x2A0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B104: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8057B108: b           L_8057B14C
    // 0x8057B10C: swc1        $f16, 0x228($t0)
    MEM_W(0X228, ctx->r8) = ctx->f16.u32l;
        goto L_8057B14C;
    // 0x8057B10C: swc1        $f16, 0x228($t0)
    MEM_W(0X228, ctx->r8) = ctx->f16.u32l;
L_8057B110:
    // 0x8057B110: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057B114: lwc1        $f12, 0x2A0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B118: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8057B11C: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8057B120: nop

    // 0x8057B124: bc1fl       L_8057B150
    if (!c1cs) {
        // 0x8057B128: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8057B150;
    }
    goto skip_1;
    // 0x8057B128: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    skip_1:
    // 0x8057B12C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8057B130: swc1        $f2, 0x2A0($t0)
    MEM_W(0X2A0, ctx->r8) = ctx->f2.u32l;
    // 0x8057B134: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8057B138: swc1        $f4, 0x228($t0)
    MEM_W(0X228, ctx->r8) = ctx->f4.u32l;
    // 0x8057B13C: lw          $t3, 0x1E0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1E0);
    // 0x8057B140: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8057B144: sw          $t4, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r12;
    // 0x8057B148: lwc1        $f12, 0x2A0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X2A0);
L_8057B14C:
    // 0x8057B14C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
L_8057B150:
    // 0x8057B150: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8057B154: jal         0x8005B270
    // 0x8057B158: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    func_8005B270(rdram, ctx);
        goto after_4;
    // 0x8057B158: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_4:
    // 0x8057B15C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057B160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8057B164: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8057B168: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8057B16C: sh          $v1, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r3;
    // 0x8057B170: sh          $v1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r3;
    // 0x8057B174: sh          $v1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r3;
    // 0x8057B178: sh          $v1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r3;
    // 0x8057B17C: sh          $v1, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r3;
    // 0x8057B180: sh          $v1, 0x4A($a1)
    MEM_H(0X4A, ctx->r5) = ctx->r3;
    // 0x8057B184: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8057B188: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
    // 0x8057B18C: sh          $v1, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r3;
    // 0x8057B190: sh          $v1, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r3;
    // 0x8057B194: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
    // 0x8057B198: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
L_8057B19C:
    // 0x8057B19C: sh          $v1, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r3;
    // 0x8057B1A0: sh          $v1, 0x22($a1)
    MEM_H(0X22, ctx->r5) = ctx->r3;
    // 0x8057B1A4: sh          $v1, 0x1A($a2)
    MEM_H(0X1A, ctx->r6) = ctx->r3;
    // 0x8057B1A8: sh          $v1, 0x22($a2)
    MEM_H(0X22, ctx->r6) = ctx->r3;
    // 0x8057B1AC: sh          $v1, 0x52($a1)
    MEM_H(0X52, ctx->r5) = ctx->r3;
    // 0x8057B1B0: sh          $v1, 0x4A($a1)
    MEM_H(0X4A, ctx->r5) = ctx->r3;
    // 0x8057B1B4: sh          $v1, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r3;
    // 0x8057B1B8: sh          $v1, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r3;
    // 0x8057B1BC: sh          $v1, 0x82($a1)
    MEM_H(0X82, ctx->r5) = ctx->r3;
    // 0x8057B1C0: sh          $v1, 0x7A($a1)
    MEM_H(0X7A, ctx->r5) = ctx->r3;
    // 0x8057B1C4: sh          $v1, 0x82($a2)
    MEM_H(0X82, ctx->r6) = ctx->r3;
    // 0x8057B1C8: sh          $v1, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r3;
    // 0x8057B1CC: sh          $v1, 0xB2($a1)
    MEM_H(0XB2, ctx->r5) = ctx->r3;
    // 0x8057B1D0: sh          $v1, 0xAA($a1)
    MEM_H(0XAA, ctx->r5) = ctx->r3;
    // 0x8057B1D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057B1D8: sh          $v1, 0xB2($a2)
    MEM_H(0XB2, ctx->r6) = ctx->r3;
    // 0x8057B1DC: sh          $v1, 0xAA($a2)
    MEM_H(0XAA, ctx->r6) = ctx->r3;
    // 0x8057B1E0: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x8057B1E4: bne         $a0, $a3, L_8057B19C
    if (ctx->r4 != ctx->r7) {
        // 0x8057B1E8: addiu       $a2, $a2, 0xC0
        ctx->r6 = ADD32(ctx->r6, 0XC0);
            goto L_8057B19C;
    }
    // 0x8057B1E8: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x8057B1EC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8057B1F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8057B1F4: lwc1        $f6, 0x2A0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B1F8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8057B1FC: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x8057B200: mul.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8057B204: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057B208: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8057B20C: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8057B210: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057B214: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x8057B218: lwc1        $f18, 0x2A0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X2A0);
    // 0x8057B21C: mul.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8057B220: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8057B224: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8057B228: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8057B22C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057B230:
    // 0x8057B230: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057B234: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8057B238: jr          $ra
    // 0x8057B23C: nop

    return;
    // 0x8057B23C: nop

;}
RECOMP_FUNC void func_807BA300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA300: jr          $ra
    // 0x807BA304: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807BA304: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8073F688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073F68C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8073F690: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8073F694: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073F698: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8073F69C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8073F6A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8073F6A4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8073F6A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8073F6AC:
    // 0x8073F6AC: jal         0x8073F4BC
    // 0x8073F6B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8073F4BC(rdram, ctx);
        goto after_0;
    // 0x8073F6B0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8073F6B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8073F6B8: bnel        $s0, $s2, L_8073F6AC
    if (ctx->r16 != ctx->r18) {
        // 0x8073F6BC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8073F6AC;
    }
    goto skip_0;
    // 0x8073F6BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8073F6C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8073F6C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073F6C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8073F6CC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8073F6D0: jr          $ra
    // 0x8073F6D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8073F6D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_805AABAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AABAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AABB0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805AABB4: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805AABB8: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805AABBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AABC0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805AABC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x805AABC8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805AABCC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805AABD0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805AABD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805AABD8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805AABDC: lui         $t2, 0x805B
    ctx->r10 = S32(RELOC_HI16(432, 0XAF0) << 16);
    // 0x805AABE0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805AABE4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805AABE8: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805AABEC: lw          $t2, -0x5220($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(432, 0XAF0));
    // 0x805AABF0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805AABF4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805AABF8: jal         0x805AA55C
    // 0x805AABFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805AA55C(rdram, ctx);
        goto after_0;
    // 0x805AABFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805AAC00: jal         0x805AA5A8
    // 0x805AAC04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805AA5A8(rdram, ctx);
        goto after_1;
    // 0x805AAC04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805AAC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AAC0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AAC10: jr          $ra
    // 0x805AAC14: nop

    return;
    // 0x805AAC14: nop

;}
RECOMP_FUNC void func_80781364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80781364: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80781368: lui         $v0, 0x8078
    ctx->r2 = S32(RELOC_HI16(784, 0X6548) << 16);
    // 0x8078136C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80781370: lw          $v0, 0x6738($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(784, 0X6548));
    // 0x80781374: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80781378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078137C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80781380: jal         0x80048378
    // 0x80781384: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80781384: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80781388: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8078138C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80781390: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80781394: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80781398: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X6678) << 16);
    // 0x8078139C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x807813A0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x807813A4: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x807813A8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x807813AC: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x807813B0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x807813B4: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x807813B8: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x807813BC: lwc1        $f16, 0x6868($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X6678));
    // 0x807813C0: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(784, 0X667C) << 16);
    // 0x807813C4: swc1        $f16, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f16.u32l;
    // 0x807813C8: lwc1        $f18, 0x686C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(784, 0X667C));
    // 0x807813CC: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x807813D0: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x807813D4: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x807813D8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x807813DC: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x807813E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807813E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807813E8: jr          $ra
    // 0x807813EC: nop

    return;
    // 0x807813EC: nop

;}
RECOMP_FUNC void func_8051F080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F084: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051F088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F08C: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(303, 0XA30) << 16);
    // 0x8051F090: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(303, 0XA40) << 16);
    // 0x8051F094: addiu       $a1, $a1, -0x540
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(303, 0XA40));
    // 0x8051F098: addiu       $a0, $a0, -0x550
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(303, 0XA30));
    // 0x8051F09C: jal         0x8004667C
    // 0x8051F0A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8051F0A0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x8051F0A4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8051F0A8: lui         $a2, 0x8052
    ctx->r6 = S32(RELOC_HI16(303, 0X79C) << 16);
    // 0x8051F0AC: addiu       $a2, $a2, -0x7E4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(303, 0X79C));
    // 0x8051F0B0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x8051F0B4: jal         0x80057B28
    // 0x8051F0B8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x8051F0B8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
    // 0x8051F0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F0C0: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(303, 0X360) << 16);
    // 0x8051F0C4: addiu       $v0, $v0, -0xC20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(303, 0X360));
    // 0x8051F0C8: jr          $ra
    // 0x8051F0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8051F0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800651B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800651B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800651B4: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800651B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800651BC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800651C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800651C4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x800651C8: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800651CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800651D0: bgez        $t8, L_800651F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800651D4: nop
    
            goto L_800651F8;
    }
    // 0x800651D4: nop

    // 0x800651D8: bne         $a2, $zero, L_800651EC
    if (ctx->r6 != 0) {
        // 0x800651DC: addiu       $t9, $a1, -0x1
        ctx->r25 = ADD32(ctx->r5, -0X1);
            goto L_800651EC;
    }
    // 0x800651DC: addiu       $t9, $a1, -0x1
    ctx->r25 = ADD32(ctx->r5, -0X1);
    // 0x800651E0: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800651E4: jr          $ra
    // 0x800651E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800651E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800651EC:
    // 0x800651EC: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x800651F0: jr          $ra
    // 0x800651F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800651F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800651F8:
    // 0x800651F8: jr          $ra
    // 0x800651FC: nop

    return;
    // 0x800651FC: nop

;}
RECOMP_FUNC void func_8000C418(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000C41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C420: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000C424: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000C428: jal         0x8000DBD4
    // 0x8000C42C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    func_8000DBD4(rdram, ctx);
        goto after_0;
    // 0x8000C42C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_0:
    // 0x8000C430: beq         $v0, $zero, L_8000C454
    if (ctx->r2 == 0) {
        // 0x8000C434: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_8000C454;
    }
    // 0x8000C434: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000C438: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000C43C: jal         0x8000C3A0
    // 0x8000C440: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8000C3A0(rdram, ctx);
        goto after_1;
    // 0x8000C440: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8000C444: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000C448: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C44C: jal         0x8000DB94
    // 0x8000C450: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    func_8000DB94(rdram, ctx);
        goto after_2;
    // 0x8000C450: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_2:
L_8000C454:
    // 0x8000C454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C458: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C45C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000C460: jr          $ra
    // 0x8000C464: nop

    return;
    // 0x8000C464: nop

;}
RECOMP_FUNC void func_8044DED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044DED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044DEDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044DEE0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044DEE4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044DEE8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DEEC: ori         $at, $at, 0x6CF0
    ctx->r1 = ctx->r1 | 0X6CF0;
    // 0x8044DEF0: addu        $a0, $v0, $at
    ctx->r4 = ADD32(ctx->r2, ctx->r1);
    // 0x8044DEF4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DEF8: ori         $at, $at, 0x6CFC
    ctx->r1 = ctx->r1 | 0X6CFC;
    // 0x8044DEFC: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x8044DF00: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DF04: ori         $at, $at, 0x6D08
    ctx->r1 = ctx->r1 | 0X6D08;
    // 0x8044DF08: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x8044DF0C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044DF10: ori         $at, $at, 0x6D0C
    ctx->r1 = ctx->r1 | 0X6D0C;
    // 0x8044DF14: jal         0x8006C67C
    // 0x8044DF18: addu        $a3, $v0, $at
    ctx->r7 = ADD32(ctx->r2, ctx->r1);
    func_8006C67C(rdram, ctx);
        goto after_0;
    // 0x8044DF18: addu        $a3, $v0, $at
    ctx->r7 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x8044DF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044DF20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044DF24: jr          $ra
    // 0x8044DF28: nop

    return;
    // 0x8044DF28: nop

;}
RECOMP_FUNC void func_804EF67C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF67C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF680: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF684: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804EF688: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804EF68C: beq         $t6, $zero, L_804EF6C8
    if (ctx->r14 == 0) {
        // 0x804EF690: nop
    
            goto L_804EF6C8;
    }
    // 0x804EF690: nop

    // 0x804EF694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804EF698: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x804EF69C: jalr        $t9
    // 0x804EF6A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x804EF6A0: nop

    after_0:
    // 0x804EF6A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF6A8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x804EF6AC: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x804EF6B0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x804EF6B4: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x804EF6B8: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x804EF6BC: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x804EF6C0: b           L_804EF6C8
    // 0x804EF6C4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_804EF6C8;
    // 0x804EF6C4: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_804EF6C8:
    // 0x804EF6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF6CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF6D0: jr          $ra
    // 0x804EF6D4: nop

    return;
    // 0x804EF6D4: nop

;}
RECOMP_FUNC void func_8000124C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000124C: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x80001250: lui         $at, 0x702
    ctx->r1 = S32(0X702 << 16);
    // 0x80001254: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80001258: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000125C: jr          $ra
    // 0x80001260: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    return;
    // 0x80001260: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
;}
RECOMP_FUNC void func_800338A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800338A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800338AC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800338B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800338B4: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800338B8: lwc1        $f4, 0x78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X78);
    // 0x800338BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800338C0: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800338C4: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800338C8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800338CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800338D0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x800338D4: bc1tl       L_80033900
    if (c1cs) {
        // 0x800338D8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80033900;
    }
    goto skip_0;
    // 0x800338D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x800338DC: lwc1        $f6, 0x7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7C);
    // 0x800338E0: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800338E4: nop

    // 0x800338E8: bc1tl       L_80033900
    if (c1cs) {
        // 0x800338EC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80033900;
    }
    goto skip_1;
    // 0x800338EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x800338F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800338F4: b           L_80033970
    // 0x800338F8: swc1        $f2, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f2.u32l;
        goto L_80033970;
    // 0x800338F8: swc1        $f2, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f2.u32l;
    // 0x800338FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80033900:
    // 0x80033900: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80033904: lwc1        $f20, 0xAEC($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0XAEC);
    // 0x80033908: lh          $t6, 0xAE0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XAE0);
    // 0x8003390C: lh          $t7, 0xADE($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XADE);
    // 0x80033910: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x80033914: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80033918: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8003391C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80033920: bc1f        L_8003392C
    if (!c1cs) {
        // 0x80033924: cvt.s.w     $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8003392C;
    }
    // 0x80033924: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80033928: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_8003392C:
    // 0x8003392C: lwc1        $f16, 0x68($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80033930: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80033934: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80033938: mul.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8003393C: jal         0x80081E8C
    // 0x80033940: nop

    fatan2(rdram, ctx);
        goto after_0;
    // 0x80033940: nop

    after_0:
    // 0x80033944: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80033948: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003394C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033950: lwc1        $f6, 0x80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X80);
    // 0x80033954: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80033958: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8003395C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033960: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80033964: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033968: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003396C: swc1        $f2, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f2.u32l;
L_80033970:
    // 0x80033970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80033974: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80033978: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003397C: jr          $ra
    // 0x80033980: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80033980: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8057ED98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057ED98: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8057ED9C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8057EDA0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057EDA4: lui         $t8, 0x8058
    ctx->r24 = S32(RELOC_HI16(396, 0X88) << 16);
    // 0x8057EDA8: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8057EDAC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8057EDB0: lw          $t8, -0x1238($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(396, 0X88));
    // 0x8057EDB4: jr          $ra
    // 0x8057EDB8: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    return;
    // 0x8057EDB8: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8057EDBC: nop

;}
RECOMP_FUNC void func_804D87BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D87BC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804D87C0: lui         $t6, 0x804E
    ctx->r14 = S32(RELOC_HI16(255, 0X478) << 16);
    // 0x804D87C4: addiu       $t6, $t6, -0x7858
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(255, 0X478));
    // 0x804D87C8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804D87CC: jr          $ra
    // 0x804D87D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804D87D0: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8040C8AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C8AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C8B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C8B4: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1EF4) << 16);
    // 0x8040C8B8: lwc1        $f6, -0x1B0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1EF4));
    // 0x8040C8BC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8040C8C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040C8C4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8040C8C8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8040C8CC: nop

    // 0x8040C8D0: bc1f        L_8040C8F0
    if (!c1cs) {
        // 0x8040C8D4: nop
    
            goto L_8040C8F0;
    }
    // 0x8040C8D4: nop

    // 0x8040C8D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040C8DC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8040C8E0: jal         0x8040E254
    // 0x8040C8E4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8040E254(rdram, ctx);
        goto after_0;
    // 0x8040C8E4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8040C8E8: b           L_8040C8FC
    // 0x8040C8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C8FC;
    // 0x8040C8EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C8F0:
    // 0x8040C8F0: jal         0x8040E254
    // 0x8040C8F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8040E254(rdram, ctx);
        goto after_1;
    // 0x8040C8F4: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8040C8F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C8FC:
    // 0x8040C8FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C900: jr          $ra
    // 0x8040C904: nop

    return;
    // 0x8040C904: nop

;}
RECOMP_FUNC void func_8070FDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FDDC: andi        $t6, $a1, 0x8
    ctx->r14 = ctx->r5 & 0X8;
    // 0x8070FDE0: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8070FDE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070FDE8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8070FDEC: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X18B8) << 16);
    // 0x8070FDF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070FDF4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8070FDF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8070FDFC: jal         0x8005B270
    // 0x8070FE00: lwc1        $f12, 0xCA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X18B8));
    func_8005B270(rdram, ctx);
        goto after_0;
    // 0x8070FE00: lwc1        $f12, 0xCA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X18B8));
    after_0:
    // 0x8070FE04: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8070FE08: sh          $v0, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r2;
    // 0x8070FE0C: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x8070FE10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070FE14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070FE18: jr          $ra
    // 0x8070FE1C: nop

    return;
    // 0x8070FE1C: nop

;}
RECOMP_FUNC void MtxConv_F2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800817A0: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800817A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800817A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800817AC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800817B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800817B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800817B8: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800817BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800817C0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800817C4: beql        $v0, $a0, L_80081864
    if (ctx->r2 == ctx->r4) {
        // 0x800817C8: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_80081864;
    }
    goto skip_0;
    // 0x800817C8: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_0:
    // 0x800817CC: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_800817D0:
    // 0x800817D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800817D4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800817D8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800817DC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800817E0: nop

    // 0x800817E4: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800817E8: sh          $t7, -0x8($a3)
    MEM_H(-0X8, ctx->r7) = ctx->r15;
    // 0x800817EC: sh          $v1, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r3;
    // 0x800817F0: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x800817F4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800817F8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800817FC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80081800: nop

    // 0x80081804: sra         $t9, $v1, 16
    ctx->r25 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80081808: sh          $t9, -0x6($a3)
    MEM_H(-0X6, ctx->r7) = ctx->r25;
    // 0x8008180C: sh          $v1, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r3;
    // 0x80081810: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x80081814: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80081818: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008181C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80081820: nop

    // 0x80081824: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80081828: sh          $t1, -0x4($a3)
    MEM_H(-0X4, ctx->r7) = ctx->r9;
    // 0x8008182C: sh          $v1, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r3;
    // 0x80081830: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x80081834: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80081838: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008183C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80081840: nop

    // 0x80081844: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80081848: sh          $t3, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r11;
    // 0x8008184C: sh          $v1, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = ctx->r3;
    // 0x80081850: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80081854: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80081858: bnel        $v0, $a0, L_800817D0
    if (ctx->r2 != ctx->r4) {
        // 0x8008185C: trunc.w.s   $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_800817D0;
    }
    goto skip_1;
    // 0x8008185C: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_1:
    // 0x80081860: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
L_80081864:
    // 0x80081864: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80081868: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8008186C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80081870: nop

    // 0x80081874: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80081878: sh          $t7, -0x8($a3)
    MEM_H(-0X8, ctx->r7) = ctx->r15;
    // 0x8008187C: sh          $v1, 0x18($a3)
    MEM_H(0X18, ctx->r7) = ctx->r3;
    // 0x80081880: lwc1        $f16, -0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0XC);
    // 0x80081884: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80081888: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8008188C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80081890: nop

    // 0x80081894: sra         $t9, $v1, 16
    ctx->r25 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80081898: sh          $t9, -0x6($a3)
    MEM_H(-0X6, ctx->r7) = ctx->r25;
    // 0x8008189C: sh          $v1, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r3;
    // 0x800818A0: lwc1        $f16, -0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X8);
    // 0x800818A4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800818A8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800818AC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800818B0: nop

    // 0x800818B4: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800818B8: sh          $t1, -0x4($a3)
    MEM_H(-0X4, ctx->r7) = ctx->r9;
    // 0x800818BC: sh          $v1, 0x1C($a3)
    MEM_H(0X1C, ctx->r7) = ctx->r3;
    // 0x800818C0: lwc1        $f16, -0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X4);
    // 0x800818C4: mul.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800818C8: trunc.w.s   $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800818CC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800818D0: nop

    // 0x800818D4: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800818D8: sh          $t3, -0x2($a3)
    MEM_H(-0X2, ctx->r7) = ctx->r11;
    // 0x800818DC: sh          $v1, 0x1E($a3)
    MEM_H(0X1E, ctx->r7) = ctx->r3;
    // 0x800818E0: jr          $ra
    // 0x800818E4: nop

    return;
    // 0x800818E4: nop

;}
RECOMP_FUNC void func_805AE1A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE1A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE1A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE1AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE1B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE1B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE1B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE1BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE1C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE1C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE1C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE1CC: jr          $ra
    // 0x805AE1D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE1D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80048CA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048CA4: lw          $v0, 0x1D8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1D8);
    // 0x80048CA8: beq         $v0, $zero, L_80048CB8
    if (ctx->r2 == 0) {
        // 0x80048CAC: nop
    
            goto L_80048CB8;
    }
    // 0x80048CAC: nop

    // 0x80048CB0: lw          $t7, 0x1DC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1DC);
    // 0x80048CB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80048CB8:
    // 0x80048CB8: jr          $ra
    // 0x80048CBC: nop

    return;
    // 0x80048CBC: nop

;}
