#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8004F26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F26C: lw          $t6, 0x1B8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F270: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004F274: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x8004F278: addiu       $t7, $t7, -0xA30
    ctx->r15 = ADD32(ctx->r15, -0XA30);
    // 0x8004F27C: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x8004F280: sw          $t7, 0x1C0($a0)
    MEM_W(0X1C0, ctx->r4) = ctx->r15;
    // 0x8004F284: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8004F288: jr          $ra
    // 0x8004F28C: sb          $v0, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = ctx->r2;
    return;
    // 0x8004F28C: sb          $v0, -0x7D76($at)
    MEM_B(-0X7D76, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80672300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80672304: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80672308: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8067230C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80672310: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80672314: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672318: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8067231C: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80672320: jal         0x80671D4C
    // 0x80672324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80672324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80672328: lw          $t6, 0x1E0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1E0);
    // 0x8067232C: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x80672330: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80672334: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80672338: blez        $t7, L_80672368
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8067233C: sw          $t7, 0x1E0($s2)
        MEM_W(0X1E0, ctx->r18) = ctx->r15;
            goto L_80672368;
    }
    // 0x8067233C: sw          $t7, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = ctx->r15;
    // 0x80672340: sw          $zero, 0x1E0($s2)
    MEM_W(0X1E0, ctx->r18) = 0;
    // 0x80672344: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672348: jal         0x80671954
    // 0x8067234C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    func_80671954(rdram, ctx);
        goto after_1;
    // 0x8067234C: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    after_1:
    // 0x80672350: beq         $v0, $zero, L_8067235C
    if (ctx->r2 == 0) {
        // 0x80672354: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8067235C;
    }
    // 0x80672354: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80672358: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_8067235C:
    // 0x8067235C: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x80672360: addiu       $s1, $t0, 0x1
    ctx->r17 = ADD32(ctx->r8, 0X1);
    // 0x80672364: sw          $s1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r17;
L_80672368:
    // 0x80672368: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8067236C: beq         $at, $zero, L_80672380
    if (ctx->r1 == 0) {
        // 0x80672370: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80672380;
    }
    // 0x80672370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80672374: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80672378: jal         0x80671C98
    // 0x8067237C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    func_80671C98(rdram, ctx);
        goto after_2;
    // 0x8067237C: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_2:
L_80672380:
    // 0x80672380: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80672384: bne         $at, $zero, L_806723A0
    if (ctx->r1 != 0) {
        // 0x80672388: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_806723A0;
    }
    // 0x80672388: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8067238C: jal         0x80672C80
    // 0x80672390: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_80672C80(rdram, ctx);
        goto after_3;
    // 0x80672390: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_3:
    // 0x80672394: addiu       $a0, $zero, 0xBE
    ctx->r4 = ADD32(0, 0XBE);
    // 0x80672398: jal         0x80067818
    // 0x8067239C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8067239C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_806723A0:
    // 0x806723A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806723A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806723A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x806723AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x806723B0: jr          $ra
    // 0x806723B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x806723B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004DA60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DA60: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8004DA64: lwc1        $f8, 0xDC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x8004DA68: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x8004DA6C: lw          $t8, 0x138($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X138);
    // 0x8004DA70: lw          $t0, 0x134($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X134);
    // 0x8004DA74: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8004DA78: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8004DA7C: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8004DA80: xori        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 ^ 0X1;
    // 0x8004DA84: xori        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 ^ 0X1;
    // 0x8004DA88: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x8004DA8C: swc1        $f10, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f10.u32l;
    // 0x8004DA90: sw          $t7, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r15;
    // 0x8004DA94: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x8004DA98: jr          $ra
    // 0x8004DA9C: sw          $t1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r9;
    return;
    // 0x8004DA9C: sw          $t1, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80736BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736BBC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80736BC0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80736BC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80736BC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80736BCC:
    // 0x80736BCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80736BD0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80736BD4: bne         $v1, $a0, L_80736BCC
    if (ctx->r3 != ctx->r4) {
        // 0x80736BD8: sw          $zero, -0x4($a1)
        MEM_W(-0X4, ctx->r5) = 0;
            goto L_80736BCC;
    }
    // 0x80736BD8: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x80736BDC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80736BE0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80736BE4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80736BE8: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80736BEC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B4C) << 16);
    // 0x80736BF0: lwc1        $f4, -0x6A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B4C));
    // 0x80736BF4: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80736BF8: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80736BFC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80736C00: jr          $ra
    // 0x80736C04: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    return;
    // 0x80736C04: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_805222B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805222B0: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x805222B4: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(321, 0X20C0) << 16);
    // 0x805222B8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x805222BC: addiu       $t6, $t6, 0x4370
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(321, 0X20C0));
    // 0x805222C0: sw          $t6, 0xE88($v1)
    MEM_W(0XE88, ctx->r3) = ctx->r14;
    // 0x805222C4: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(321, 0X15B0) << 16);
    // 0x805222C8: lw          $t7, 0x3860($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(321, 0X15B0));
    // 0x805222CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805222D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805222D4: bnel        $t7, $zero, L_80522318
    if (ctx->r15 != 0) {
        // 0x805222D8: lw          $t0, 0xE88($v1)
        ctx->r8 = MEM_W(ctx->r3, 0XE88);
            goto L_80522318;
    }
    goto skip_0;
    // 0x805222D8: lw          $t0, 0xE88($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE88);
    skip_0:
    // 0x805222DC: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x805222E0: addiu       $at, $zero, 0x4147
    ctx->r1 = ADD32(0, 0X4147);
    // 0x805222E4: lui         $a0, 0x8052
    ctx->r4 = S32(RELOC_HI16(321, 0X20D0) << 16);
    // 0x805222E8: bne         $t8, $at, L_80522314
    if (ctx->r24 != ctx->r1) {
        // 0x805222EC: addiu       $a0, $a0, 0x4380
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(321, 0X20D0));
            goto L_80522314;
    }
    // 0x805222EC: addiu       $a0, $a0, 0x4380
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(321, 0X20D0));
    // 0x805222F0: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(321, 0X20E0) << 16);
    // 0x805222F4: addiu       $a1, $a1, 0x4390
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(321, 0X20E0));
    // 0x805222F8: jal         0x8004667C
    // 0x805222FC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x805222FC: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_0:
    // 0x80522300: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80522304: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80522308: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X15B0) << 16);
    // 0x8052230C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80522310: sw          $t9, 0x3860($at)
    MEM_W((int16_t)RELOC_LO16(321, 0X15B0), ctx->r1) = ctx->r25;
L_80522314:
    // 0x80522314: lw          $t0, 0xE88($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XE88);
L_80522318:
    // 0x80522318: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(321, 0X94) << 16);
    // 0x8052231C: addiu       $v0, $v0, 0x2344
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(321, 0X94));
    // 0x80522320: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80522324: lw          $t1, 0xE88($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XE88);
    // 0x80522328: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8052232C: lw          $t2, 0xE88($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XE88);
    // 0x80522330: sw          $zero, 0xC($t2)
    MEM_W(0XC, ctx->r10) = 0;
    // 0x80522334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80522338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8052233C: jr          $ra
    // 0x80522340: nop

    return;
    // 0x80522340: nop

;}
RECOMP_FUNC void func_80025578(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025578: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002557C: lwc1        $f4, -0x27C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X27C);
    // 0x80025580: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80025584: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80025588: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8002558C: nop

    // 0x80025590: bc1t        L_800255DC
    if (c1cs) {
        // 0x80025594: nop
    
            goto L_800255DC;
    }
    // 0x80025594: nop

    // 0x80025598: lwc1        $f6, -0x278($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X278);
    // 0x8002559C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800255A0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800255A4: nop

    // 0x800255A8: bc1t        L_800255DC
    if (c1cs) {
        // 0x800255AC: nop
    
            goto L_800255DC;
    }
    // 0x800255AC: nop

    // 0x800255B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800255B4: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x800255B8: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x800255BC: lw          $t7, 0x9C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C);
    // 0x800255C0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800255C4: lui         $t9, 0x8002
    ctx->r25 = S32(0X8002 << 16);
    // 0x800255C8: sw          $v1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r3;
    // 0x800255CC: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x800255D0: addiu       $t9, $t9, 0x4748
    ctx->r25 = ADD32(ctx->r25, 0X4748);
    // 0x800255D4: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // 0x800255D8: sw          $t9, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r25;
L_800255DC:
    // 0x800255DC: jr          $ra
    // 0x800255E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800255E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_804460C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804460C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804460CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804460D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804460D4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x804460D8: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x804460DC: sw          $t6, 0x6CA4($v1)
    MEM_W(0X6CA4, ctx->r3) = ctx->r14;
    // 0x804460E0: addiu       $a1, $zero, 0x3C0
    ctx->r5 = ADD32(0, 0X3C0);
    // 0x804460E4: addiu       $a2, $zero, 0x1B6C
    ctx->r6 = ADD32(0, 0X1B6C);
    // 0x804460E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804460EC: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x804460F0: sw          $a1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r5;
    // 0x804460F4: sw          $a2, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r6;
    // 0x804460F8: sw          $a1, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->r5;
    // 0x804460FC: sw          $a2, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->r6;
    // 0x80446100: sw          $t7, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r15;
    // 0x80446104: jr          $ra
    // 0x80446108: swc1        $f4, 0x6AF0($v1)
    MEM_W(0X6AF0, ctx->r3) = ctx->f4.u32l;
    return;
    // 0x80446108: swc1        $f4, 0x6AF0($v1)
    MEM_W(0X6AF0, ctx->r3) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80429AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429AD0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(44, 0X10) << 16);
    // 0x80429AD4: addiu       $v0, $v0, -0x6520
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(44, 0X10));
    // 0x80429AD8: jr          $ra
    // 0x80429ADC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80429ADC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80464EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464EA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80464EA8: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80464EAC: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80464EB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80464EB4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80464EB8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80464EBC: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80464EC0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80464EC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80464EC8: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80464ECC: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80464ED0: addiu       $s1, $v1, 0x1F1C
    ctx->r17 = ADD32(ctx->r3, 0X1F1C);
    // 0x80464ED4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80464ED8: lw          $t6, 0x1F1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1F1C);
    // 0x80464EDC: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x80464EE0: bnel        $at, $zero, L_80464F1C
    if (ctx->r1 != 0) {
        // 0x80464EE4: lw          $t9, 0x0($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X0);
            goto L_80464F1C;
    }
    goto skip_0;
    // 0x80464EE4: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x80464EE8: lw          $t7, 0x1F18($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1F18);
    // 0x80464EEC: addiu       $s1, $v1, 0x1F1C
    ctx->r17 = ADD32(ctx->r3, 0X1F1C);
    // 0x80464EF0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80464EF4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80464EF8: sw          $t8, 0x1F18($v1)
    MEM_W(0X1F18, ctx->r3) = ctx->r24;
    // 0x80464EFC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80464F00: lw          $a0, 0x1F18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X1F18);
    // 0x80464F04: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80464F08: jal         0x80464CD4
    // 0x80464F0C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80464CD4(rdram, ctx);
        goto after_0;
    // 0x80464F0C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_0:
    // 0x80464F10: b           L_80464F24
    // 0x80464F14: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80464F24;
    // 0x80464F14: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80464F18: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
L_80464F1C:
    // 0x80464F1C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80464F20: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80464F24:
    // 0x80464F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80464F28: jal         0x804647B8
    // 0x80464F2C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_804647B8(rdram, ctx);
        goto after_1;
    // 0x80464F2C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80464F30: jal         0x804649C8
    // 0x80464F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804649C8(rdram, ctx);
        goto after_2;
    // 0x80464F34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80464F38: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80464F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80464F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80464F44: lw          $t1, 0x1F18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1F18);
    // 0x80464F48: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80464F4C: slti        $at, $t1, 0x18
    ctx->r1 = SIGNED(ctx->r9) < 0X18 ? 1 : 0;
    // 0x80464F50: bnel        $at, $zero, L_80464F88
    if (ctx->r1 != 0) {
        // 0x80464F54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80464F88;
    }
    goto skip_1;
    // 0x80464F54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80464F58: jal         0x804653B8
    // 0x80464F5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804653B8(rdram, ctx);
        goto after_3;
    // 0x80464F5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80464F60: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80464F64: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80464F68: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80464F6C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x80464F70: nop

    // 0x80464F74: bc1tl       L_80464F84
    if (c1cs) {
        // 0x80464F78: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80464F84;
    }
    goto skip_2;
    // 0x80464F78: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_2:
    // 0x80464F7C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80464F80: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80464F84:
    // 0x80464F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80464F88:
    // 0x80464F88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80464F8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80464F90: jr          $ra
    // 0x80464F94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80464F94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804BE180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BE180: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BE184: lh          $t0, 0x2A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2A);
    // 0x804BE188: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X2AA0) << 16);
    // 0x804BE18C: lw          $a2, 0x1F4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BE190: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x804BE194: addiu       $t7, $t7, -0x1C30
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X2AA0));
    // 0x804BE198: lw          $v1, 0x370($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X370);
    // 0x804BE19C: bne         $t0, $zero, L_804BE1AC
    if (ctx->r8 != 0) {
        // 0x804BE1A0: addiu       $a3, $a2, 0x350
        ctx->r7 = ADD32(ctx->r6, 0X350);
            goto L_804BE1AC;
    }
    // 0x804BE1A0: addiu       $a3, $a2, 0x350
    ctx->r7 = ADD32(ctx->r6, 0X350);
    // 0x804BE1A4: jr          $ra
    // 0x804BE1A8: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    return;
    // 0x804BE1A8: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
L_804BE1AC:
    // 0x804BE1AC: lh          $t8, 0x2C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2C);
    // 0x804BE1B0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804BE1B4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x804BE1B8: beql        $t8, $t0, L_804BE1D0
    if (ctx->r24 == ctx->r8) {
        // 0x804BE1BC: sh          $zero, 0x2E($a0)
        MEM_H(0X2E, ctx->r4) = 0;
            goto L_804BE1D0;
    }
    goto skip_0;
    // 0x804BE1BC: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    skip_0:
    // 0x804BE1C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804BE1C4: nop

    // 0x804BE1C8: swc1        $f4, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f4.u32l;
    // 0x804BE1CC: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
L_804BE1D0:
    // 0x804BE1D0: lh          $t9, 0x2E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2E);
    // 0x804BE1D4: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X3DC0) << 16);
    // 0x804BE1D8: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x804BE1DC: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x804BE1E0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BE1E4: lh          $t2, -0x910($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(191, 0X3DC0));
    // 0x804BE1E8: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41DC) << 16);
    // 0x804BE1EC: sh          $t2, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r10;
    // 0x804BE1F0: lh          $t3, 0x28($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X28);
    // 0x804BE1F4: beql        $t3, $zero, L_804BE210
    if (ctx->r11 == 0) {
        // 0x804BE1F8: lwc1        $f0, 0x24($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
            goto L_804BE210;
    }
    goto skip_1;
    // 0x804BE1F8: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x804BE1FC: sh          $zero, 0xE4($v0)
    MEM_H(0XE4, ctx->r2) = 0;
    // 0x804BE200: lh          $t4, 0xE4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE4);
    // 0x804BE204: sh          $t4, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r12;
    // 0x804BE208: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x804BE20C: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
L_804BE210:
    // 0x804BE210: lwc1        $f8, -0x4F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41DC));
    // 0x804BE214: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41E0) << 16);
    // 0x804BE218: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x804BE21C: nop

    // 0x804BE220: bc1t        L_804BE248
    if (c1cs) {
        // 0x804BE224: nop
    
            goto L_804BE248;
    }
    // 0x804BE224: nop

    // 0x804BE228: lwc1        $f10, -0x4F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41E0));
    // 0x804BE22C: lui         $t5, 0x804C
    ctx->r13 = S32(RELOC_HI16(191, 0X2920) << 16);
    // 0x804BE230: addiu       $t5, $t5, -0x1DB0
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(191, 0X2920));
    // 0x804BE234: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804BE238: nop

    // 0x804BE23C: bc1t        L_804BE248
    if (c1cs) {
        // 0x804BE240: nop
    
            goto L_804BE248;
    }
    // 0x804BE240: nop

    // 0x804BE244: sw          $t5, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r13;
L_804BE248:
    // 0x804BE248: jr          $ra
    // 0x804BE24C: nop

    return;
    // 0x804BE24C: nop

;}
RECOMP_FUNC void func_80068E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068E24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068E28: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80068E2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80068E30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80068E34: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068E38: lui         $s0, 0x800F
    ctx->r16 = S32(0X800F << 16);
    // 0x80068E3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068E40: sb          $t6, -0x6BF7($at)
    MEM_B(-0X6BF7, ctx->r1) = ctx->r14;
    // 0x80068E44: addiu       $s0, $s0, 0x7EA0
    ctx->r16 = ADD32(ctx->r16, 0X7EA0);
    // 0x80068E48: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80068E4C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
L_80068E50:
    // 0x80068E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068E54: jalr        $t9
    // 0x80068E58: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80068E58: nop

    after_0:
    // 0x80068E5C: lbu         $t7, 0x5($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X5);
    // 0x80068E60: xor         $a0, $s1, $t7
    ctx->r4 = ctx->r17 ^ ctx->r15;
    // 0x80068E64: jal         0x80069030
    // 0x80068E68: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    func_80069030(rdram, ctx);
        goto after_1;
    // 0x80068E68: sltiu       $a0, $a0, 0x1
    ctx->r4 = ctx->r4 < 0X1 ? 1 : 0;
    after_1:
    // 0x80068E6C: lw          $t8, 0xD8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XD8);
    // 0x80068E70: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80068E74: jal         0x80068D8C
    // 0x80068E78: sw          $t0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r8;
    func_80068D8C(rdram, ctx);
        goto after_2;
    // 0x80068E78: sw          $t0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r8;
    after_2:
    // 0x80068E7C: jal         0x80067AAC
    // 0x80068E80: nop

    func_80067AAC(rdram, ctx);
        goto after_3;
    // 0x80068E80: nop

    after_3:
    // 0x80068E84: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80068E88: beql        $v0, $zero, L_80068E50
    if (ctx->r2 == 0) {
        // 0x80068E8C: lw          $t9, 0x1C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X1C);
            goto L_80068E50;
    }
    goto skip_0;
    // 0x80068E8C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    skip_0:
    // 0x80068E90: jalr        $v0
    // 0x80068E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x80068E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80068E98: jal         0x8005DB34
    // 0x80068E9C: nop

    func_8005DB34(rdram, ctx);
        goto after_5;
    // 0x80068E9C: nop

    after_5:
    // 0x80068EA0: b           L_80068E50
    // 0x80068EA4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
        goto L_80068E50;
    // 0x80068EA4: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80068EA8: nop

    // 0x80068EAC: nop

    // 0x80068EB0: nop

    // 0x80068EB4: nop

    // 0x80068EB8: nop

    // 0x80068EBC: nop

    // 0x80068EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80068EC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80068EC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80068ECC: jr          $ra
    // 0x80068ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068ED0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800787F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800787F8: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800787FC: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80078800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80078804: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80078808: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8007880C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80078810: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80078814: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80078818: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8007881C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80078820: sw          $t7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r15;
    // 0x80078824: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80078828: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007882C: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x80078830: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80078834: swc1        $f6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f6.u32l;
    // 0x80078838: lw          $s1, 0x1C($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1C);
    // 0x8007883C: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
    // 0x80078840: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x80078844: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80078848: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x8007884C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80078850: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x80078854: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80078858: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x8007885C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80078860: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x80078864: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80078868: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    // 0x8007886C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80078870: sw          $t5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r13;
    // 0x80078874: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80078878: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x8007887C: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80078880: lhu         $a1, 0x6($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X6);
    // 0x80078884: jal         0x800773A4
    // 0x80078888: lbu         $a2, 0x24($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X24);
    func_800773A4(rdram, ctx);
        goto after_0;
    // 0x80078888: lbu         $a2, 0x24($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X24);
    after_0:
    // 0x8007888C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80078890: jal         0x800733D8
    // 0x80078894: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    func_800733D8(rdram, ctx);
        goto after_1;
    // 0x80078894: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    after_1:
    // 0x80078898: lw          $t8, 0x20($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X20);
    // 0x8007889C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x800788A0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800788A4: beq         $t8, $zero, L_800788BC
    if (ctx->r24 == 0) {
        // 0x800788A8: addiu       $t0, $t9, 0x8
        ctx->r8 = ADD32(ctx->r25, 0X8);
            goto L_800788BC;
    }
    // 0x800788A8: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x800788AC: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x800788B0: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x800788B4: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x800788B8: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
L_800788BC:
    // 0x800788BC: lhu         $v0, 0xA($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XA);
    // 0x800788C0: lhu         $v1, 0x8($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X8);
    // 0x800788C4: lbu         $a3, 0x5($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X5);
    // 0x800788C8: lbu         $t3, 0x9($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X9);
    // 0x800788CC: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800788D0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800788D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800788D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800788DC: lwc1        $f14, 0x7C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800788E0: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800788E4: mflo        $t4
    ctx->r12 = lo;
    // 0x800788E8: sllv        $t5, $t4, $a3
    ctx->r13 = S32(ctx->r12 << (ctx->r7 & 31));
    // 0x800788EC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800788F0: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800788F4: multu       $t3, $t7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800788F8: mflo        $t8
    ctx->r24 = lo;
    // 0x800788FC: addu        $a1, $t9, $t8
    ctx->r5 = ADD32(ctx->r25, ctx->r24);
    // 0x80078900: nop

    // 0x80078904: lh          $t0, 0xC($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XC);
    // 0x80078908: sub.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x8007890C: lh          $t1, 0xE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XE);
    // 0x80078910: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80078914: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80078918: lbu         $a2, 0x4($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X4);
    // 0x8007891C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078920: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80078924: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x80078928: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007892C: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80078930: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80078934: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80078938: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007893C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80078940: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80078944: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x80078948: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007894C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80078950: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x80078954: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80078958: jal         0x8007A700
    // 0x8007895C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_8007A700(rdram, ctx);
        goto after_2;
    // 0x8007895C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80078960: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80078964: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x80078968: sw          $t2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r10;
    // 0x8007896C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80078970: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80078974: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80078978: jr          $ra
    // 0x8007897C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8007897C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80703968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80703968: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8070396C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80703970: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80703974: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80703978: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8070397C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80703980: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80703984: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80703988: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8070398C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80703990: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80703994: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80703998: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8070399C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x807039A0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x807039A4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x807039A8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807039AC: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x807039B0: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x807039B4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807039B8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x807039BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807039C0: jal         0x8004921C
    // 0x807039C4: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x807039C4: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    after_0:
    // 0x807039C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x807039CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807039D0: jal         0x8004921C
    // 0x807039D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x807039D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x807039D8: lw          $v1, 0x168($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X168);
    // 0x807039DC: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(709, 0X2878) << 16);
    // 0x807039E0: addiu       $s6, $sp, 0xE4
    ctx->r22 = ADD32(ctx->r29, 0XE4);
    // 0x807039E4: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x807039E8: addiu       $t7, $t7, 0x5CE8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(709, 0X2878));
    // 0x807039EC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x807039F0: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
    // 0x807039F4: lw          $s4, 0x1F4($s0)
    ctx->r20 = MEM_W(ctx->r16, 0X1F4);
    // 0x807039F8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x807039FC: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80703A00: lw          $t9, 0x28($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X28);
    // 0x80703A04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80703A08: lw          $s2, 0x88($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X88);
    // 0x80703A0C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80703A10: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80703A14: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80703A18: jal         0x80077338
    // 0x80703A1C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    func_80077338(rdram, ctx);
        goto after_2;
    // 0x80703A1C: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80703A20: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80703A24: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80703A28: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80703A2C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80703A30: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80703A34: ori         $t7, $t7, 0xACB0
    ctx->r15 = ctx->r15 | 0XACB0;
    // 0x80703A38: ori         $t6, $t6, 0x18
    ctx->r14 = ctx->r14 | 0X18;
    // 0x80703A3C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80703A40: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80703A44: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80703A48: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x80703A4C: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x80703A50: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80703A54: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80703A58: ori         $a1, $a1, 0x3048
    ctx->r5 = ctx->r5 | 0X3048;
    // 0x80703A5C: ori         $t6, $t6, 0x3
    ctx->r14 = ctx->r14 | 0X3;
    // 0x80703A60: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80703A64: sw          $a1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r5;
    // 0x80703A68: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80703A6C: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x80703A70: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x80703A74: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80703A78: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    // 0x80703A7C: sw          $a1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r5;
    // 0x80703A80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80703A84: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80703A88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80703A8C: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80703A90: jal         0x8007711C
    // 0x80703A94: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x80703A94: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    after_3:
    // 0x80703A98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80703A9C: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
L_80703AA0:
    // 0x80703AA0: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x80703AA4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80703AA8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80703AAC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80703AB0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80703AB4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80703AB8: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80703ABC: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80703AC0: jal         0x80066DE4
    // 0x80703AC4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x80703AC4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    after_4:
    // 0x80703AC8: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80703ACC: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    // 0x80703AD0: jal         0x80066E88
    // 0x80703AD4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_5;
    // 0x80703AD4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_5:
    // 0x80703AD8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80703ADC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80703AE0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80703AE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80703AE8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80703AEC: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80703AF0: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x80703AF4: slti        $at, $s2, 0x180
    ctx->r1 = SIGNED(ctx->r18) < 0X180 ? 1 : 0;
    // 0x80703AF8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80703AFC: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80703B00: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x80703B04: mul.s       $f24, $f2, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80703B08: nop

    // 0x80703B0C: mul.s       $f18, $f12, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f28.fl);
    // 0x80703B10: nop

    // 0x80703B14: mul.s       $f26, $f12, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80703B18: neg.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = -ctx->f24.fl;
    // 0x80703B1C: mul.s       $f16, $f2, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f28.fl);
    // 0x80703B20: sub.s       $f8, $f30, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f18.fl;
    // 0x80703B24: neg.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f14.fl = -ctx->f26.fl;
    // 0x80703B28: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80703B2C: add.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80703B30: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80703B34: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80703B38: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80703B3C: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80703B40: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    // 0x80703B44: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80703B48: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80703B4C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80703B50: sub.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x80703B54: sh          $t7, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r15;
    // 0x80703B58: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80703B5C: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80703B60: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80703B64: add.s       $f8, $f30, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f30.fl + ctx->f18.fl;
    // 0x80703B68: sh          $t9, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r25;
    // 0x80703B6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80703B70: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80703B74: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80703B78: add.s       $f6, $f26, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x80703B7C: sh          $t7, 0x2A($s0)
    MEM_H(0X2A, ctx->r16) = ctx->r15;
    // 0x80703B80: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80703B84: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80703B88: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80703B8C: add.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x80703B90: sh          $t9, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r25;
    // 0x80703B94: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80703B98: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80703B9C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80703BA0: sub.s       $f10, $f26, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x80703BA4: sh          $t7, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r15;
    // 0x80703BA8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80703BAC: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x80703BB0: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80703BB4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80703BB8: sh          $t9, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r25;
    // 0x80703BBC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80703BC0: bne         $at, $zero, L_80703AA0
    if (ctx->r1 != 0) {
        // 0x80703BC4: sh          $t7, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r15;
            goto L_80703AA0;
    }
    // 0x80703BC4: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x80703BC8: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80703BCC: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80703BD0: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x80703BD4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80703BD8: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80703BDC: ori         $t6, $t6, 0x617F
    ctx->r14 = ctx->r14 | 0X617F;
    // 0x80703BE0: addiu       $t7, $s4, 0x58
    ctx->r15 = ADD32(ctx->r20, 0X58);
    // 0x80703BE4: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80703BE8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80703BEC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80703BF0: addiu       $t8, $s3, -0x1
    ctx->r24 = ADD32(ctx->r19, -0X1);
    // 0x80703BF4: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80703BF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80703BFC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80703C00: addiu       $s0, $v1, 0x7
    ctx->r16 = ADD32(ctx->r3, 0X7);
    // 0x80703C04: sra         $s0, $s0, 3
    ctx->r16 = S32(SIGNED(ctx->r16) >> 3);
    // 0x80703C08: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x80703C0C: mflo        $t5
    ctx->r13 = lo;
    // 0x80703C10: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80703C14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80703C18: andi        $s0, $s0, 0x1FF
    ctx->r16 = ctx->r16 & 0X1FF;
    // 0x80703C1C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80703C20: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80703C24: sll         $s0, $s0, 9
    ctx->r16 = S32(ctx->r16 << 9);
    // 0x80703C28: sra         $t5, $t5, 1
    ctx->r13 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80703C2C: or          $t3, $s4, $zero
    ctx->r11 = ctx->r20 | 0;
    // 0x80703C30: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(709, 0X27E8) << 16);
    // 0x80703C34: addiu       $t0, $t0, 0x5C58
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(709, 0X27E8));
    // 0x80703C38: lui         $s4, 0xF550
    ctx->r20 = S32(0XF550 << 16);
    // 0x80703C3C: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x80703C40: or          $s1, $t7, $t6
    ctx->r17 = ctx->r15 | ctx->r14;
    // 0x80703C44: lui         $s5, 0xE600
    ctx->r21 = S32(0XE600 << 16);
    // 0x80703C48: addiu       $s3, $zero, 0x240
    ctx->r19 = ADD32(0, 0X240);
    // 0x80703C4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80703C50: bgez        $v1, L_80703C60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80703C54: sra         $a3, $v1, 3
        ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80703C60;
    }
    // 0x80703C54: sra         $a3, $v1, 3
    ctx->r7 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80703C58: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80703C5C: sra         $a3, $at, 3
    ctx->r7 = S32(SIGNED(ctx->r1) >> 3);
L_80703C60:
    // 0x80703C60: lui         $at, 0xF548
    ctx->r1 = S32(0XF548 << 16);
    // 0x80703C64: or          $s0, $s0, $at
    ctx->r16 = ctx->r16 | ctx->r1;
    // 0x80703C68: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x80703C6C: lui         $s7, 0xE700
    ctx->r23 = S32(0XE700 << 16);
    // 0x80703C70: lui         $s6, 0xF300
    ctx->r22 = S32(0XF300 << 16);
    // 0x80703C74: lui         $s2, 0xFD50
    ctx->r18 = S32(0XFD50 << 16);
    // 0x80703C78: lui         $ra, 0x700
    ctx->r31 = S32(0X700 << 16);
L_80703C7C:
    // 0x80703C7C: lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE4);
    // 0x80703C80: slti        $at, $t5, 0x7FF
    ctx->r1 = SIGNED(ctx->r13) < 0X7FF ? 1 : 0;
    // 0x80703C84: addiu       $t1, $zero, 0x7FF
    ctx->r9 = ADD32(0, 0X7FF);
    // 0x80703C88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80703C8C: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80703C90: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x80703C94: lh          $t7, 0x48($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X48);
    // 0x80703C98: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x80703C9C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x80703CA0: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80703CA4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80703CA8: mflo        $t6
    ctx->r14 = lo;
    // 0x80703CAC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80703CB0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80703CB4: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80703CB8: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80703CBC: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80703CC0: sw          $s4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r20;
    // 0x80703CC4: sw          $ra, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r31;
    // 0x80703CC8: lw          $a0, 0xE4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE4);
    // 0x80703CCC: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80703CD0: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80703CD4: sw          $t9, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r25;
    // 0x80703CD8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80703CDC: sw          $s5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r21;
    // 0x80703CE0: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x80703CE4: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80703CE8: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80703CEC: sw          $s6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r22;
    // 0x80703CF0: beq         $at, $zero, L_80703D00
    if (ctx->r1 == 0) {
        // 0x80703CF4: or          $t4, $t7, $zero
        ctx->r12 = ctx->r15 | 0;
            goto L_80703D00;
    }
    // 0x80703CF4: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x80703CF8: b           L_80703D00
    // 0x80703CFC: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
        goto L_80703D00;
    // 0x80703CFC: or          $t1, $t5, $zero
    ctx->r9 = ctx->r13 | 0;
L_80703D00:
    // 0x80703D00: bgtz        $a3, L_80703D10
    if (SIGNED(ctx->r7) > 0) {
        // 0x80703D04: nop
    
            goto L_80703D10;
    }
    // 0x80703D04: nop

    // 0x80703D08: b           L_80703D10
    // 0x80703D0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80703D10;
    // 0x80703D0C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80703D10:
    // 0x80703D10: bgtz        $a3, L_80703D20
    if (SIGNED(ctx->r7) > 0) {
        // 0x80703D14: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_80703D20;
    }
    // 0x80703D14: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x80703D18: b           L_80703D20
    // 0x80703D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80703D20;
    // 0x80703D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80703D20:
    // 0x80703D20: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x80703D24: mflo        $t9
    ctx->r25 = lo;
    // 0x80703D28: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80703D2C: bne         $a1, $zero, L_80703D38
    if (ctx->r5 != 0) {
        // 0x80703D30: nop
    
            goto L_80703D38;
    }
    // 0x80703D30: nop

    // 0x80703D34: break       7
    do_break(2154839348);
L_80703D38:
    // 0x80703D38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80703D3C: bne         $a1, $at, L_80703D50
    if (ctx->r5 != ctx->r1) {
        // 0x80703D40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80703D50;
    }
    // 0x80703D40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80703D44: bne         $t8, $at, L_80703D50
    if (ctx->r24 != ctx->r1) {
        // 0x80703D48: nop
    
            goto L_80703D50;
    }
    // 0x80703D48: nop

    // 0x80703D4C: break       6
    do_break(2154839372);
L_80703D50:
    // 0x80703D50: andi        $t8, $t1, 0xFFF
    ctx->r24 = ctx->r9 & 0XFFF;
    // 0x80703D54: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80703D58: or          $t6, $t7, $ra
    ctx->r14 = ctx->r15 | ctx->r31;
    // 0x80703D5C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80703D60: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x80703D64: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80703D68: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x80703D6C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80703D70: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80703D74: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80703D78: sw          $s7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r23;
    // 0x80703D7C: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80703D80: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80703D84: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80703D88: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80703D8C: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x80703D90: sw          $s0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r16;
    // 0x80703D94: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x80703D98: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80703D9C: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x80703DA0: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80703DA4: sw          $s1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r17;
    // 0x80703DA8: sw          $fp, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r30;
    // 0x80703DAC: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80703DB0: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0X2878) << 16);
    // 0x80703DB4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80703DB8: addiu       $t7, $t9, 0x8
    ctx->r15 = ADD32(ctx->r25, 0X8);
    // 0x80703DBC: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x80703DC0: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80703DC4: addiu       $t0, $t0, 0x18
    ctx->r8 = ADD32(ctx->r8, 0X18);
    // 0x80703DC8: addiu       $t6, $t6, 0x5CE8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0X2878));
    // 0x80703DCC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80703DD0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80703DD4: bne         $t0, $t6, L_80703C7C
    if (ctx->r8 != ctx->r14) {
        // 0x80703DD8: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_80703C7C;
    }
    // 0x80703DD8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80703DDC: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x80703DE0: lw          $t7, 0x118($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X118);
    // 0x80703DE4: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x80703DE8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80703DEC: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80703DF0: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80703DF4: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80703DF8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80703DFC: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80703E00: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80703E04: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80703E08: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80703E0C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80703E10: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80703E14: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80703E18: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80703E1C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80703E20: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80703E24: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80703E28: jr          $ra
    // 0x80703E2C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80703E2C: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80064FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064FEC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80064FF0: addiu       $v0, $a1, -0x6C08
    ctx->r2 = ADD32(ctx->r5, -0X6C08);
    // 0x80064FF4: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80064FF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80064FFC: beq         $a0, $v0, L_80065024
    if (ctx->r4 == ctx->r2) {
        // 0x80065000: nop
    
            goto L_80065024;
    }
    // 0x80065000: nop

    // 0x80065004: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
L_80065008:
    // 0x80065008: beql        $t6, $zero, L_8006501C
    if (ctx->r14 == 0) {
        // 0x8006500C: lw          $a0, 0x8($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X8);
            goto L_8006501C;
    }
    goto skip_0;
    // 0x8006500C: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x80065010: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x80065014: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80065018: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
L_8006501C:
    // 0x8006501C: bnel        $a0, $v0, L_80065008
    if (ctx->r4 != ctx->r2) {
        // 0x80065020: lhu         $t6, 0x2($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X2);
            goto L_80065008;
    }
    goto skip_1;
    // 0x80065020: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    skip_1:
L_80065024:
    // 0x80065024: jr          $ra
    // 0x80065028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80065028: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_805D3034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3034: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D3038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D303C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D3040: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D3044: jal         0x8004700C
    // 0x805D3048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805D3048: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805D304C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D3050: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805D3054: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D3058: lhu         $t6, 0x4($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X4);
    // 0x805D305C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805D3060: bne         $t6, $zero, L_805D3070
    if (ctx->r14 != 0) {
        // 0x805D3064: nop
    
            goto L_805D3070;
    }
    // 0x805D3064: nop

    // 0x805D3068: b           L_805D3070
    // 0x805D306C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_805D3070;
    // 0x805D306C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3070:
    // 0x805D3070: beq         $v0, $zero, L_805D3178
    if (ctx->r2 == 0) {
        // 0x805D3074: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_805D3178;
    }
    // 0x805D3074: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x805D3078: addu        $t7, $a0, $v0
    ctx->r15 = ADD32(ctx->r4, ctx->r2);
    // 0x805D307C: addu        $t8, $a2, $v0
    ctx->r24 = ADD32(ctx->r6, ctx->r2);
    // 0x805D3080: lwc1        $f6, 0x84($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X84);
    // 0x805D3084: lwc1        $f4, 0x84($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X84);
    // 0x805D3088: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805D308C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D3090: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D3094: jal         0x80065954
    // 0x805D3098: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x805D3098: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x805D309C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x805D30A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805D30A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D30A8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D30AC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805D30B0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x805D30B4: bc1fl       L_805D317C
    if (!c1cs) {
        // 0x805D30B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D317C;
    }
    goto skip_0;
    // 0x805D30B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805D30BC: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x805D30C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x805D30C4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x805D30C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x805D30CC: addu        $t0, $a2, $v0
    ctx->r8 = ADD32(ctx->r6, ctx->r2);
    // 0x805D30D0: lwc1        $f2, 0x84($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X84);
    // 0x805D30D4: addu        $t9, $a0, $v0
    ctx->r25 = ADD32(ctx->r4, ctx->r2);
    // 0x805D30D8: lwc1        $f0, 0x84($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X84);
    // 0x805D30DC: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805D30E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805D30E4: add.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x805D30E8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x805D30EC: nop

    // 0x805D30F0: bc1fl       L_805D3100
    if (!c1cs) {
        // 0x805D30F4: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_805D3100;
    }
    goto skip_1;
    // 0x805D30F4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_1:
    // 0x805D30F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x805D30FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_805D3100:
    // 0x805D3100: nop

    // 0x805D3104: bc1f        L_805D3110
    if (!c1cs) {
        // 0x805D3108: nop
    
            goto L_805D3110;
    }
    // 0x805D3108: nop

    // 0x805D310C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_805D3110:
    // 0x805D3110: beql        $v1, $zero, L_805D317C
    if (ctx->r3 == 0) {
        // 0x805D3114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805D317C;
    }
    goto skip_2;
    // 0x805D3114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805D3118: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x805D311C: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x805D3120: beq         $t2, $zero, L_805D312C
    if (ctx->r10 == 0) {
        // 0x805D3124: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_805D312C;
    }
    // 0x805D3124: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x805D3128: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_805D312C:
    // 0x805D312C: bgez        $v1, L_805D3158
    if (SIGNED(ctx->r3) >= 0) {
        // 0x805D3130: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_805D3158;
    }
    // 0x805D3130: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x805D3134: bne         $t4, $zero, L_805D314C
    if (ctx->r12 != 0) {
        // 0x805D3138: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805D314C;
    }
    // 0x805D3138: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805D313C: jal         0x805D2F88
    // 0x805D3140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_805D2F88(rdram, ctx);
        goto after_2;
    // 0x805D3140: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_2:
    // 0x805D3144: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D3148: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
L_805D314C:
    // 0x805D314C: ori         $t5, $v0, 0x2
    ctx->r13 = ctx->r2 | 0X2;
    // 0x805D3150: b           L_805D3178
    // 0x805D3154: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
        goto L_805D3178;
    // 0x805D3154: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
L_805D3158:
    // 0x805D3158: beq         $t7, $zero, L_805D3170
    if (ctx->r15 == 0) {
        // 0x805D315C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805D3170;
    }
    // 0x805D315C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805D3160: jal         0x805D2FE8
    // 0x805D3164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_805D2FE8(rdram, ctx);
        goto after_3;
    // 0x805D3164: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x805D3168: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805D316C: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
L_805D3170:
    // 0x805D3170: andi        $t8, $v0, 0xFFFD
    ctx->r24 = ctx->r2 & 0XFFFD;
    // 0x805D3174: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
L_805D3178:
    // 0x805D3178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805D317C:
    // 0x805D317C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D3180: jr          $ra
    // 0x805D3184: nop

    return;
    // 0x805D3184: nop

;}
RECOMP_FUNC void func_804715A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804715A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804715A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804715AC: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x804715B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804715B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x804715B8: beq         $a1, $at, L_804715D4
    if (ctx->r5 == ctx->r1) {
        // 0x804715BC: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_804715D4;
    }
    // 0x804715BC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x804715C0: jal         0x80067878
    // 0x804715C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x804715C4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x804715C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804715CC: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x804715D0: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_804715D4:
    // 0x804715D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804715D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804715DC: jr          $ra
    // 0x804715E0: nop

    return;
    // 0x804715E0: nop

;}
RECOMP_FUNC void func_80799BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799BE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80799BE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80799BE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80799BEC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80799BF0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80799BF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80799BF8: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x80799BFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80799C00: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80799C04: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80799C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80799C0C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80799C10: jal         0x8004D150
    // 0x80799C14: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8004D150(rdram, ctx);
        goto after_0;
    // 0x80799C14: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80799C18: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x80799C1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80799C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80799C24: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80799C28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80799C2C: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80799C30: lbu         $t1, 0x14($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X14);
    // 0x80799C34: beq         $t1, $zero, L_80799C58
    if (ctx->r9 == 0) {
        // 0x80799C38: nop
    
            goto L_80799C58;
    }
    // 0x80799C38: nop

    // 0x80799C3C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80799C40: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80799C44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80799C48: jal         0x8004D618
    // 0x80799C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004D618(rdram, ctx);
        goto after_1;
    // 0x80799C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80799C50: b           L_80799C9C
    // 0x80799C54: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_80799C9C;
    // 0x80799C54: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80799C58:
    // 0x80799C58: jal         0x8004D150
    // 0x80799C5C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    func_8004D150(rdram, ctx);
        goto after_2;
    // 0x80799C5C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    after_2:
    // 0x80799C60: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    // 0x80799C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80799C68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80799C6C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80799C70: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80799C74: lw          $t4, 0x40($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X40);
    // 0x80799C78: lbu         $t5, 0x2C($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X2C);
    // 0x80799C7C: beql        $t5, $zero, L_80799C98
    if (ctx->r13 == 0) {
        // 0x80799C80: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_80799C98;
    }
    goto skip_0;
    // 0x80799C80: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    skip_0:
    // 0x80799C84: jal         0x8004D618
    // 0x80799C88: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    func_8004D618(rdram, ctx);
        goto after_3;
    // 0x80799C88: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    after_3:
    // 0x80799C8C: b           L_80799C9C
    // 0x80799C90: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_80799C9C;
    // 0x80799C90: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80799C94: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
L_80799C98:
    // 0x80799C98: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_80799C9C:
    // 0x80799C9C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80799CA0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80799CA4: bnel        $t7, $zero, L_80799CC0
    if (ctx->r15 != 0) {
        // 0x80799CA8: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80799CC0;
    }
    goto skip_1;
    // 0x80799CA8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x80799CAC: beql        $t8, $zero, L_80799CC0
    if (ctx->r24 == 0) {
        // 0x80799CB0: lw          $t9, 0x28($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X28);
            goto L_80799CC0;
    }
    goto skip_2;
    // 0x80799CB0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    skip_2:
    // 0x80799CB4: jal         0x807999F8
    // 0x80799CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807999F8(rdram, ctx);
        goto after_4;
    // 0x80799CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80799CBC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
L_80799CC0:
    // 0x80799CC0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80799CC4: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X267C) << 16);
    // 0x80799CC8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80799CCC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80799CD0: beql        $t1, $zero, L_80799CE4
    if (ctx->r9 == 0) {
        // 0x80799CD4: lw          $t2, 0x174($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X174);
            goto L_80799CE4;
    }
    goto skip_3;
    // 0x80799CD4: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
    skip_3:
    // 0x80799CD8: lwc1        $f4, -0x4E64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(826, 0X267C));
    // 0x80799CDC: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x80799CE0: lw          $t2, 0x174($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X174);
L_80799CE4:
    // 0x80799CE4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80799CE8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80799CEC: lw          $v0, 0x40($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X40);
    // 0x80799CF0: lhu         $v1, 0x30($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X30);
    // 0x80799CF4: beql        $v1, $zero, L_80799D44
    if (ctx->r3 == 0) {
        // 0x80799CF8: lhu         $v1, 0x48($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X48);
            goto L_80799D44;
    }
    goto skip_4;
    // 0x80799CF8: lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X48);
    skip_4:
    // 0x80799CFC: beql        $v1, $at, L_80799D44
    if (ctx->r3 == ctx->r1) {
        // 0x80799D00: lhu         $v1, 0x48($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X48);
            goto L_80799D44;
    }
    goto skip_5;
    // 0x80799D00: lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X48);
    skip_5:
    // 0x80799D04: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x80799D08: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80799D0C: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80799D10: beq         $v1, $at, L_80799D40
    if (ctx->r3 == ctx->r1) {
        // 0x80799D14: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80799D40;
    }
    // 0x80799D14: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80799D18: beql        $v1, $at, L_80799D44
    if (ctx->r3 == ctx->r1) {
        // 0x80799D1C: lhu         $v1, 0x48($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0X48);
            goto L_80799D44;
    }
    goto skip_6;
    // 0x80799D1C: lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X48);
    skip_6:
    // 0x80799D20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80799D24: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80799D28: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80799D2C: nop

    // 0x80799D30: bc1fl       L_80799D94
    if (!c1cs) {
        // 0x80799D34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799D94;
    }
    goto skip_7;
    // 0x80799D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x80799D38: b           L_80799D90
    // 0x80799D3C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
        goto L_80799D90;
    // 0x80799D3C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
L_80799D40:
    // 0x80799D40: lhu         $v1, 0x48($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X48);
L_80799D44:
    // 0x80799D44: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80799D48: beql        $v1, $zero, L_80799D94
    if (ctx->r3 == 0) {
        // 0x80799D4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799D94;
    }
    goto skip_8;
    // 0x80799D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x80799D50: beql        $v1, $at, L_80799D94
    if (ctx->r3 == ctx->r1) {
        // 0x80799D54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799D94;
    }
    goto skip_9;
    // 0x80799D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80799D58: lbu         $v1, 0x48($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X48);
    // 0x80799D5C: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80799D60: andi        $v1, $v1, 0xF8
    ctx->r3 = ctx->r3 & 0XF8;
    // 0x80799D64: beq         $v1, $at, L_80799D90
    if (ctx->r3 == ctx->r1) {
        // 0x80799D68: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80799D90;
    }
    // 0x80799D68: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80799D6C: beql        $v1, $at, L_80799D94
    if (ctx->r3 == ctx->r1) {
        // 0x80799D70: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799D94;
    }
    goto skip_10;
    // 0x80799D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80799D74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80799D78: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80799D7C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80799D80: nop

    // 0x80799D84: bc1fl       L_80799D94
    if (!c1cs) {
        // 0x80799D88: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80799D94;
    }
    goto skip_11;
    // 0x80799D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x80799D8C: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
L_80799D90:
    // 0x80799D90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80799D94:
    // 0x80799D94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80799D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80799D9C: jr          $ra
    // 0x80799DA0: nop

    return;
    // 0x80799DA0: nop

;}
RECOMP_FUNC void func_805D3444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D3444: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x805D3448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D344C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D3450: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x805D3454: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x805D3458: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x805D345C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805D3460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D3464: bnel        $t6, $at, L_805D353C
    if (ctx->r14 != ctx->r1) {
        // 0x805D3468: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D353C;
    }
    goto skip_0;
    // 0x805D3468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D346C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805D3470: jal         0x80067BBC
    // 0x805D3474: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805D3474: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x805D3478: addiu       $a0, $zero, 0x277
    ctx->r4 = ADD32(0, 0X277);
    // 0x805D347C: jal         0x80067818
    // 0x805D3480: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805D3480: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805D3484: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805D3488: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805D348C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D3490: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(471, 0X2554) << 16);
    // 0x805D3494: lwc1        $f4, 0x3F84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(471, 0X2554));
    // 0x805D3498: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x805D349C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x805D34A0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x805D34A4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x805D34A8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x805D34AC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805D34B0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x805D34B4: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x805D34B8: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x805D34BC: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805D34C0: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x805D34C4: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x805D34C8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x805D34CC: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805D34D0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x805D34D4: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x805D34D8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x805D34DC: lw          $t9, 0x28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28);
    // 0x805D34E0: jalr        $t9
    // 0x805D34E4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805D34E4: nop

    after_2:
    // 0x805D34E8: jal         0x805D1EDC
    // 0x805D34EC: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    func_805D1EDC(rdram, ctx);
        goto after_3;
    // 0x805D34EC: addiu       $a0, $s0, 0x84
    ctx->r4 = ADD32(ctx->r16, 0X84);
    after_3:
    // 0x805D34F0: beq         $v0, $zero, L_805D3530
    if (ctx->r2 == 0) {
        // 0x805D34F4: sw          $v0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r2;
            goto L_805D3530;
    }
    // 0x805D34F4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x805D34F8: jal         0x8005FE48
    // 0x805D34FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_4;
    // 0x805D34FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805D3500: jal         0x800444D0
    // 0x805D3504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800444D0(rdram, ctx);
        goto after_5;
    // 0x805D3504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805D3508: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x805D350C: jal         0x80047F9C
    // 0x805D3510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x805D3510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x805D3514: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(471, 0X1A08) << 16);
    // 0x805D3518: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805D351C: addiu       $t1, $t1, 0x3438
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(471, 0X1A08));
    // 0x805D3520: sb          $zero, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = 0;
    // 0x805D3524: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x805D3528: b           L_805D3538
    // 0x805D352C: sw          $t1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r9;
        goto L_805D3538;
    // 0x805D352C: sw          $t1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r9;
L_805D3530:
    // 0x805D3530: jal         0x800447C8
    // 0x805D3534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_7;
    // 0x805D3534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_805D3538:
    // 0x805D3538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D353C:
    // 0x805D353C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D3540: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x805D3544: jr          $ra
    // 0x805D3548: nop

    return;
    // 0x805D3548: nop

;}
RECOMP_FUNC void func_80433D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433D20: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80433D24: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80433D28: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80433D2C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80433D30: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80433D34: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80433D38: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80433D3C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80433D40: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80433D44: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80433D48: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80433D4C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80433D50: addiu       $s2, $zero, 0x168
    ctx->r18 = ADD32(0, 0X168);
    // 0x80433D54: lw          $s1, 0xF2C($v1)
    ctx->r17 = MEM_W(ctx->r3, 0XF2C);
    // 0x80433D58: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x80433D5C: addu        $s0, $v1, $t6
    ctx->r16 = ADD32(ctx->r3, ctx->r14);
    // 0x80433D60: slti        $at, $s1, 0x78
    ctx->r1 = SIGNED(ctx->r17) < 0X78 ? 1 : 0;
    // 0x80433D64: beq         $at, $zero, L_80433E5C
    if (ctx->r1 == 0) {
        // 0x80433D68: addiu       $s0, $s0, 0xB6C
        ctx->r16 = ADD32(ctx->r16, 0XB6C);
            goto L_80433E5C;
    }
    // 0x80433D68: addiu       $s0, $s0, 0xB6C
    ctx->r16 = ADD32(ctx->r16, 0XB6C);
    // 0x80433D6C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AC0) << 16);
    // 0x80433D70: lwc1        $f30, 0x6570($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AC0));
    // 0x80433D74: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AC4) << 16);
    // 0x80433D78: lwc1        $f26, 0x6574($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AC4));
    // 0x80433D7C: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(71, 0X2AC8) << 16);
    // 0x80433D80: lwc1        $f24, 0x6578($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(71, 0X2AC8));
L_80433D84:
    // 0x80433D84: jal         0x800653D8
    // 0x80433D88: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80433D88: nop

    after_0:
    // 0x80433D8C: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80433D90: mfhi        $t7
    ctx->r15 = hi;
    // 0x80433D94: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80433D98: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80433D9C: lwc1        $f22, 0x4($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80433DA0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80433DA4: bne         $s2, $zero, L_80433DB0
    if (ctx->r18 != 0) {
        // 0x80433DA8: nop
    
            goto L_80433DB0;
    }
    // 0x80433DA8: nop

    // 0x80433DAC: break       7
    do_break(2151890348);
L_80433DB0:
    // 0x80433DB0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80433DB4: bne         $s2, $at, L_80433DC8
    if (ctx->r18 != ctx->r1) {
        // 0x80433DB8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80433DC8;
    }
    // 0x80433DB8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80433DBC: bne         $v0, $at, L_80433DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80433DC0: nop
    
            goto L_80433DC8;
    }
    // 0x80433DC0: nop

    // 0x80433DC4: break       6
    do_break(2151890372);
L_80433DC8:
    // 0x80433DC8: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    // 0x80433DCC: jal         0x80066E88
    // 0x80433DD0: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80433DD0: addiu       $s0, $s0, 0x0
    ctx->r16 = ADD32(ctx->r16, 0X0);
    after_1:
    // 0x80433DD4: mul.s       $f6, $f30, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80433DD8: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x80433DDC: c.lt.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl < ctx->f20.fl;
    // 0x80433DE0: nop

    // 0x80433DE4: bc1fl       L_80433DF8
    if (!c1cs) {
        // 0x80433DE8: c.lt.s      $f20, $f26
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
            goto L_80433DF8;
    }
    goto skip_0;
    // 0x80433DE8: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    skip_0:
    // 0x80433DEC: b           L_80433E08
    // 0x80433DF0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
        goto L_80433E08;
    // 0x80433DF0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80433DF4: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
L_80433DF8:
    // 0x80433DF8: nop

    // 0x80433DFC: bc1f        L_80433E08
    if (!c1cs) {
        // 0x80433E00: nop
    
            goto L_80433E08;
    }
    // 0x80433E00: nop

    // 0x80433E04: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
L_80433E08:
    // 0x80433E08: jal         0x80066DE4
    // 0x80433E0C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80433E0C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_2:
    // 0x80433E10: mul.s       $f8, $f30, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80433E14: addiu       $s1, $s1, 0x32
    ctx->r17 = ADD32(ctx->r17, 0X32);
    // 0x80433E18: slti        $at, $s1, 0x78
    ctx->r1 = SIGNED(ctx->r17) < 0X78 ? 1 : 0;
    // 0x80433E1C: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80433E20: c.lt.s      $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f24.fl < ctx->f22.fl;
    // 0x80433E24: nop

    // 0x80433E28: bc1fl       L_80433E3C
    if (!c1cs) {
        // 0x80433E2C: c.lt.s      $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
            goto L_80433E3C;
    }
    goto skip_1;
    // 0x80433E2C: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    skip_1:
    // 0x80433E30: b           L_80433E4C
    // 0x80433E34: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
        goto L_80433E4C;
    // 0x80433E34: mov.s       $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    ctx->f22.fl = ctx->f24.fl;
    // 0x80433E38: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
L_80433E3C:
    // 0x80433E3C: nop

    // 0x80433E40: bc1fl       L_80433E50
    if (!c1cs) {
        // 0x80433E44: swc1        $f20, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
            goto L_80433E50;
    }
    goto skip_2;
    // 0x80433E44: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    skip_2:
    // 0x80433E48: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
L_80433E4C:
    // 0x80433E4C: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_80433E50:
    // 0x80433E50: swc1        $f22, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f22.u32l;
    // 0x80433E54: bne         $at, $zero, L_80433D84
    if (ctx->r1 != 0) {
        // 0x80433E58: addiu       $s0, $s0, 0x190
        ctx->r16 = ADD32(ctx->r16, 0X190);
            goto L_80433D84;
    }
    // 0x80433E58: addiu       $s0, $s0, 0x190
    ctx->r16 = ADD32(ctx->r16, 0X190);
L_80433E5C:
    // 0x80433E5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80433E60: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80433E64: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80433E68: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80433E6C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80433E70: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80433E74: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80433E78: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80433E7C: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80433E80: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80433E84: jr          $ra
    // 0x80433E88: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80433E88: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_805548D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805548D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805548DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805548E0: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805548E4: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(354, 0X4078) << 16);
    // 0x805548E8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805548EC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805548F0: addiu       $t6, $t6, 0x4B98
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(354, 0X4078));
    // 0x805548F4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805548F8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805548FC: jal         0x80554890
    // 0x80554900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80554890(rdram, ctx);
        goto after_0;
    // 0x80554900: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80554904: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80554908: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8055490C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80554910: jal         0x80554A58
    // 0x80554914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80554A58(rdram, ctx);
        goto after_1;
    // 0x80554914: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80554918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8055491C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80554920: jr          $ra
    // 0x80554924: nop

    return;
    // 0x80554924: nop

;}
RECOMP_FUNC void func_807A9B9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9B9C: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x807A9BA0: beq         $v0, $zero, L_807A9BB8
    if (ctx->r2 == 0) {
        // 0x807A9BA4: nop
    
            goto L_807A9BB8;
    }
    // 0x807A9BA4: nop

    // 0x807A9BA8: lbu         $t6, 0x165($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X165);
    // 0x807A9BAC: bne         $t6, $zero, L_807A9BB8
    if (ctx->r14 != 0) {
        // 0x807A9BB0: nop
    
            goto L_807A9BB8;
    }
    // 0x807A9BB0: nop

    // 0x807A9BB4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
L_807A9BB8:
    // 0x807A9BB8: jr          $ra
    // 0x807A9BBC: nop

    return;
    // 0x807A9BBC: nop

;}
RECOMP_FUNC void func_806B1D2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B1D2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806B1D30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806B1D34: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806B1D38: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806B1D3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B1D40: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806B1D44: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806B1D48: lui         $a2, 0x806B
    ctx->r6 = S32(RELOC_HI16(601, 0X13D0) << 16);
    // 0x806B1D4C: lui         $a1, 0x806B
    ctx->r5 = S32(RELOC_HI16(601, 0X13EC) << 16);
    // 0x806B1D50: addiu       $a1, $a1, 0x2D3C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X13EC));
    // 0x806B1D54: addiu       $a2, $a2, 0x2D20
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X13D0));
    // 0x806B1D58: jal         0x806B1A18
    // 0x806B1D5C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    func_806B1A18(rdram, ctx);
        goto after_0;
    // 0x806B1D5C: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x806B1D60: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x806B1D64: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806B1D68: addiu       $t7, $zero, 0x1EF0
    ctx->r15 = ADD32(0, 0X1EF0);
    // 0x806B1D6C: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x806B1D70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806B1D74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x806B1D78: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x806B1D7C: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x806B1D80: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x806B1D84: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x806B1D88: jal         0x806B195C
    // 0x806B1D8C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_806B195C(rdram, ctx);
        goto after_1;
    // 0x806B1D8C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x806B1D90: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x806B1D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B1D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1D9C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B1DA0: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806B1DA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806B1DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806B1DAC: jr          $ra
    // 0x806B1DB0: nop

    return;
    // 0x806B1DB0: nop

;}
RECOMP_FUNC void func_80066AD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AD8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80066ADC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066AE0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x80066AE4: blez        $a1, L_80066CFC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80066AE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80066CFC;
    }
    // 0x80066AE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80066AEC: andi        $a2, $a1, 0x3
    ctx->r6 = ctx->r5 & 0X3;
    // 0x80066AF0: beql        $a2, $zero, L_80066BCC
    if (ctx->r6 == 0) {
        // 0x80066AF4: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_80066BCC;
    }
    goto skip_0;
    // 0x80066AF4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_0:
    // 0x80066AF8: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80066AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066B00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066B04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80066B08: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80066B0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80066B10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066B14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80066B18: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x80066B1C: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80066B20: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066B24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066B28: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80066B2C: nop

    // 0x80066B30: mul.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066B34: nop

    // 0x80066B38: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066B3C: beq         $v1, $v0, L_80066B90
    if (ctx->r3 == ctx->r2) {
        // 0x80066B40: nop
    
            goto L_80066B90;
    }
    // 0x80066B40: nop

L_80066B44:
    // 0x80066B44: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80066B48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066B4C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80066B50: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066B54: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066B58: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066B5C: nop

    // 0x80066B60: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80066B64: swc1        $f6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80066B68: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066B6C: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80066B70: swc1        $f4, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80066B74: mul.s       $f12, $f14, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80066B78: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80066B7C: mul.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066B80: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80066B84: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066B88: bne         $v1, $v0, L_80066B44
    if (ctx->r3 != ctx->r2) {
        // 0x80066B8C: nop
    
            goto L_80066B44;
    }
    // 0x80066B8C: nop

L_80066B90:
    // 0x80066B90: mul.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80066B94: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80066B98: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066B9C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066BA0: mul.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066BA4: nop

    // 0x80066BA8: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80066BAC: swc1        $f6, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80066BB0: mul.s       $f6, $f16, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80066BB4: swc1        $f4, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f4.u32l;
    // 0x80066BB8: swc1        $f8, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80066BBC: swc1        $f6, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f6.u32l;
    // 0x80066BC0: beql        $v0, $a1, L_80066D00
    if (ctx->r2 == ctx->r5) {
        // 0x80066BC4: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_80066D00;
    }
    goto skip_1;
    // 0x80066BC4: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_1:
    // 0x80066BC8: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_80066BCC:
    // 0x80066BCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066BD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80066BD4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066BD8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80066BDC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80066BE0: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
L_80066BE4:
    // 0x80066BE4: mul.s       $f16, $f20, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066BE8: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066BEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80066BF0: mul.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066BF4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80066BF8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80066BFC: nop

    // 0x80066C00: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80066C04: swc1        $f8, -0x40($a0)
    MEM_W(-0X40, ctx->r4) = ctx->f8.u32l;
    // 0x80066C08: mul.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80066C0C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066C10: mul.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80066C14: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066C18: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066C1C: swc1        $f8, -0x34($a0)
    MEM_W(-0X34, ctx->r4) = ctx->f8.u32l;
    // 0x80066C20: mul.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066C24: nop

    // 0x80066C28: mul.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066C2C: swc1        $f14, -0x38($a0)
    MEM_W(-0X38, ctx->r4) = ctx->f14.u32l;
    // 0x80066C30: mul.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80066C34: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066C38: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80066C3C: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066C40: mul.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80066C44: swc1        $f14, -0x24($a0)
    MEM_W(-0X24, ctx->r4) = ctx->f14.u32l;
    // 0x80066C48: mul.s       $f14, $f6, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80066C4C: nop

    // 0x80066C50: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80066C54: swc1        $f10, -0x3C($a0)
    MEM_W(-0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80066C58: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066C5C: nop

    // 0x80066C60: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80066C64: swc1        $f8, -0x2C($a0)
    MEM_W(-0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x80066C68: mul.s       $f8, $f20, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066C6C: nop

    // 0x80066C70: mul.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80066C74: nop

    // 0x80066C78: mul.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80066C7C: nop

    // 0x80066C80: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80066C84: swc1        $f14, -0x30($a0)
    MEM_W(-0X30, ctx->r4) = ctx->f14.u32l;
    // 0x80066C88: mul.s       $f14, $f10, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80066C8C: swc1        $f6, -0x28($a0)
    MEM_W(-0X28, ctx->r4) = ctx->f6.u32l;
    // 0x80066C90: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066C94: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80066C98: swc1        $f8, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = ctx->f8.u32l;
    // 0x80066C9C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80066CA0: swc1        $f14, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = ctx->f14.u32l;
    // 0x80066CA4: sub.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80066CA8: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80066CAC: nop

    // 0x80066CB0: mul.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80066CB4: swc1        $f16, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = ctx->f16.u32l;
    // 0x80066CB8: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80066CBC: swc1        $f12, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = ctx->f12.u32l;
    // 0x80066CC0: mul.s       $f12, $f20, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80066CC4: nop

    // 0x80066CC8: mul.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x80066CCC: swc1        $f12, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = ctx->f12.u32l;
    // 0x80066CD0: mul.s       $f12, $f8, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80066CD4: nop

    // 0x80066CD8: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80066CDC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80066CE0: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80066CE4: nop

    // 0x80066CE8: mul.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80066CEC: swc1        $f8, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80066CF0: swc1        $f16, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80066CF4: bne         $v0, $a1, L_80066BE4
    if (ctx->r2 != ctx->r5) {
        // 0x80066CF8: swc1        $f14, -0x8($a0)
        MEM_W(-0X8, ctx->r4) = ctx->f14.u32l;
            goto L_80066BE4;
    }
    // 0x80066CF8: swc1        $f14, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = ctx->f14.u32l;
L_80066CFC:
    // 0x80066CFC: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_80066D00:
    // 0x80066D00: jr          $ra
    // 0x80066D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80066D04: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80445AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445AD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445AD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445ADC: jal         0x800677F8
    // 0x80445AE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445AE0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x80445AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445AE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445AEC: jr          $ra
    // 0x80445AF0: nop

    return;
    // 0x80445AF0: nop

;}
RECOMP_FUNC void func_805DA204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA204: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805DA208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DA20C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805DA210: jal         0x80047090
    // 0x805DA214: addiu       $a0, $zero, 0x4115
    ctx->r4 = ADD32(0, 0X4115);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x805DA214: addiu       $a0, $zero, 0x4115
    ctx->r4 = ADD32(0, 0X4115);
    after_0:
    // 0x805DA218: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x805DA21C: beq         $v0, $at, L_805DA288
    if (ctx->r2 == ctx->r1) {
        // 0x805DA220: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805DA288;
    }
    // 0x805DA220: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x805DA224: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805DA228: jal         0x805DA1FC
    // 0x805DA22C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_805DA1FC(rdram, ctx);
        goto after_1;
    // 0x805DA22C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x805DA230: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x805DA234: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x805DA238: lui         $at, 0x4115
    ctx->r1 = S32(0X4115 << 16);
    // 0x805DA23C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x805DA240: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x805DA244: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x805DA248: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805DA24C: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(477, 0XBA8) << 16);
    // 0x805DA250: lwc1        $f16, -0x5418($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(477, 0XBA8));
    // 0x805DA254: lwc1        $f10, 0x8C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x805DA258: lwc1        $f4, 0xC($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0XC);
    // 0x805DA25C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805DA260: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805DA264: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805DA268: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x805DA26C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x805DA270: jal         0x8004613C
    // 0x805DA274: nop

    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x805DA274: nop

    after_2:
    // 0x805DA278: beq         $v0, $zero, L_805DA288
    if (ctx->r2 == 0) {
        // 0x805DA27C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805DA288;
    }
    // 0x805DA27C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805DA280: jal         0x80044194
    // 0x805DA284: nop

    func_80044194(rdram, ctx);
        goto after_3;
    // 0x805DA284: nop

    after_3:
L_805DA288:
    // 0x805DA288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DA28C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805DA290: jr          $ra
    // 0x805DA294: nop

    return;
    // 0x805DA294: nop

;}
RECOMP_FUNC void func_805A770C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A770C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805A7710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A7714: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805A7718: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805A771C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7720: jal         0x8004700C
    // 0x805A7724: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805A7724: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805A7728: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x805A772C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x805A7730: beq         $v0, $zero, L_805A7868
    if (ctx->r2 == 0) {
        // 0x805A7734: lw          $v1, -0x7CE8($v1)
        ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
            goto L_805A7868;
    }
    // 0x805A7734: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x805A7738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A773C: jal         0x805A7440
    // 0x805A7740: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805A7440(rdram, ctx);
        goto after_1;
    // 0x805A7740: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x805A7744: jal         0x800692D4
    // 0x805A7748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800692D4(rdram, ctx);
        goto after_2;
    // 0x805A7748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A774C: jal         0x805A7620
    // 0x805A7750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A7620(rdram, ctx);
        goto after_3;
    // 0x805A7750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805A7754: beq         $v0, $zero, L_805A7778
    if (ctx->r2 == 0) {
        // 0x805A7758: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_805A7778;
    }
    // 0x805A7758: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805A775C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7760: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A7764: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805A7768: jal         0x805A8794
    // 0x805A776C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_4;
    // 0x805A776C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x805A7770: b           L_805A786C
    // 0x805A7774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A786C;
    // 0x805A7774: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A7778:
    // 0x805A7778: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x805A777C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x805A7780: lw          $t7, 0x478($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X478);
    // 0x805A7784: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x805A7788: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805A778C: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x805A7790: lwc1        $f4, 0x84($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X84);
    // 0x805A7794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A7798: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805A779C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805A77A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805A77A4: bc1fl       L_805A77E0
    if (!c1cs) {
        // 0x805A77A8: lwc1        $f8, 0x0($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
            goto L_805A77E0;
    }
    goto skip_0;
    // 0x805A77A8: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x805A77AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x805A77B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A77B4: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x805A77B8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805A77BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A77C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x805A77C4: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x805A77C8: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x805A77CC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805A77D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805A77D4: b           L_805A7808
    // 0x805A77D8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_805A7808;
    // 0x805A77D8: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x805A77DC: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
L_805A77E0:
    // 0x805A77E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805A77E4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805A77E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A77EC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805A77F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A77F4: swc1        $f16, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f16.u32l;
    // 0x805A77F8: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x805A77FC: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x805A7800: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805A7804: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_805A7808:
    // 0x805A7808: lw          $t9, 0x478($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X478);
    // 0x805A780C: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x805A7810: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805A7814: lwc1        $f8, 0x30($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X30);
    // 0x805A7818: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A781C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805A7820: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805A7824: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805A7828: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x805A782C: nop

    // 0x805A7830: bc1fl       L_805A786C
    if (!c1cs) {
        // 0x805A7834: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A786C;
    }
    goto skip_1;
    // 0x805A7834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A7838: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x805A783C: lw          $t0, 0x4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4);
    // 0x805A7840: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805A7844: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x805A7848: sb          $zero, 0x165($t0)
    MEM_B(0X165, ctx->r8) = 0;
    // 0x805A784C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805A7850: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x805A7854: sw          $zero, 0xC($s1)
    MEM_W(0XC, ctx->r17) = 0;
    // 0x805A7858: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
    // 0x805A785C: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x805A7860: jal         0x805A8794
    // 0x805A7864: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805A8794(rdram, ctx);
        goto after_5;
    // 0x805A7864: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
L_805A7868:
    // 0x805A7868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A786C:
    // 0x805A786C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805A7870: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805A7874: jr          $ra
    // 0x805A7878: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x805A7878: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80022E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80022E80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80022E84: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80022E88: swc1        $f0, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f0.u32l;
    // 0x80022E8C: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80022E90: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x80022E94: swc1        $f0, 0xCC($a0)
    MEM_W(0XCC, ctx->r4) = ctx->f0.u32l;
    // 0x80022E98: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x80022E9C: lwc1        $f4, -0x360($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X360);
    // 0x80022EA0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80022EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80022EA8: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x80022EAC: jr          $ra
    // 0x80022EB0: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80022EB0: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_805D15B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D15B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D15BC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D15C0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D15C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D15C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D15CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805D15D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D15D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805D15D8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D15DC: lui         $t1, 0x805D
    ctx->r9 = S32(RELOC_HI16(465, 0X6B4) << 16);
    // 0x805D15E0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D15E4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D15E8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D15EC: lw          $t1, 0x16A4($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(465, 0X6B4));
    // 0x805D15F0: jal         0x805D1000
    // 0x805D15F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    func_805D1000(rdram, ctx);
        goto after_0;
    // 0x805D15F4: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    after_0:
    // 0x805D15F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D15FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D1600: jr          $ra
    // 0x805D1604: nop

    return;
    // 0x805D1604: nop

;}
RECOMP_FUNC void func_8043E268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E268: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043E26C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043E270: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043E274: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8043E278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043E27C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043E280: beq         $t6, $zero, L_8043E298
    if (ctx->r14 == 0) {
        // 0x8043E284: nop
    
            goto L_8043E298;
    }
    // 0x8043E284: nop

    // 0x8043E288: jal         0x8043D41C
    // 0x8043E28C: nop

    func_8043D41C(rdram, ctx);
        goto after_0;
    // 0x8043E28C: nop

    after_0:
    // 0x8043E290: b           L_8043E2A0
    // 0x8043E294: nop

        goto L_8043E2A0;
    // 0x8043E294: nop

L_8043E298:
    // 0x8043E298: jal         0x80048F84
    // 0x8043E29C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8043E29C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    after_1:
L_8043E2A0:
    // 0x8043E2A0: jal         0x8043DCF4
    // 0x8043E2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043DCF4(rdram, ctx);
        goto after_2;
    // 0x8043E2A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8043E2A8: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8043E2AC: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8043E2B0: jal         0x80065ABC
    // 0x8043E2B4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x8043E2B4: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x8043E2B8: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8043E2BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8043E2C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043E2C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043E2C8: jr          $ra
    // 0x8043E2CC: nop

    return;
    // 0x8043E2CC: nop

;}
RECOMP_FUNC void func_806E8E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E8E68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806E8E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E8E70: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806E8E74: lh          $v0, 0x5C8($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X5C8);
    // 0x806E8E78: addiu       $a1, $v0, 0x17
    ctx->r5 = ADD32(ctx->r2, 0X17);
    // 0x806E8E7C: slti        $at, $a1, 0x2E
    ctx->r1 = SIGNED(ctx->r5) < 0X2E ? 1 : 0;
    // 0x806E8E80: bne         $at, $zero, L_806E8E8C
    if (ctx->r1 != 0) {
        // 0x806E8E84: addiu       $a2, $v0, 0x18
        ctx->r6 = ADD32(ctx->r2, 0X18);
            goto L_806E8E8C;
    }
    // 0x806E8E84: addiu       $a2, $v0, 0x18
    ctx->r6 = ADD32(ctx->r2, 0X18);
    // 0x806E8E88: addiu       $a1, $a1, -0x2E
    ctx->r5 = ADD32(ctx->r5, -0X2E);
L_806E8E8C:
    // 0x806E8E8C: slti        $at, $a2, 0x2E
    ctx->r1 = SIGNED(ctx->r6) < 0X2E ? 1 : 0;
    // 0x806E8E90: bnel        $at, $zero, L_806E8EA0
    if (ctx->r1 != 0) {
        // 0x806E8E94: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_806E8EA0;
    }
    goto skip_0;
    // 0x806E8E94: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_0:
    // 0x806E8E98: addiu       $a2, $a2, -0x2E
    ctx->r6 = ADD32(ctx->r6, -0X2E);
    // 0x806E8E9C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_806E8EA0:
    // 0x806E8EA0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806E8EA4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x806E8EA8: jal         0x80049018
    // 0x806E8EAC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x806E8EAC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x806E8EB0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806E8EB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806E8EB8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806E8EBC: beq         $v0, $zero, L_806E8EE4
    if (ctx->r2 == 0) {
        // 0x806E8EC0: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_806E8EE4;
    }
    // 0x806E8EC0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x806E8EC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806E8EC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E8ECC: lwc1        $f4, 0x5D0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5D0);
    // 0x806E8ED0: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E8ED4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806E8ED8: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806E8EDC: b           L_806E8F00
    // 0x806E8EE0: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
        goto L_806E8F00;
    // 0x806E8EE0: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_806E8EE4:
    // 0x806E8EE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806E8EE8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806E8EEC: lwc1        $f18, 0x5D0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X5D0);
    // 0x806E8EF0: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806E8EF4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806E8EF8: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x806E8EFC: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
L_806E8F00:
    // 0x806E8F00: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x806E8F04: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x806E8F08: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x806E8F0C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x806E8F10: lwc1        $f16, 0x458($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X458);
    // 0x806E8F14: lwc1        $f18, 0x458($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X458);
    // 0x806E8F18: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(667, 0X16C4) << 16);
    // 0x806E8F1C: lwc1        $f10, -0x668C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(667, 0X16C4));
    // 0x806E8F20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806E8F24: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806E8F28: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x806E8F2C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x806E8F30: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x806E8F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E8F38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806E8F3C: jr          $ra
    // 0x806E8F40: nop

    return;
    // 0x806E8F40: nop

;}
RECOMP_FUNC void func_80682014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80682018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8068201C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80682020: jal         0x80045A34
    // 0x80682024: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80682024: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x80682028: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8068202C: bne         $v0, $zero, L_8068203C
    if (ctx->r2 != 0) {
        // 0x80682030: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8068203C;
    }
    // 0x80682030: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80682034: b           L_80682048
    // 0x80682038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80682048;
    // 0x80682038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8068203C:
    // 0x8068203C: jal         0x80681FC0
    // 0x80682040: nop

    func_80681FC0(rdram, ctx);
        goto after_1;
    // 0x80682040: nop

    after_1:
    // 0x80682044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80682048:
    // 0x80682048: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8068204C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80682050: jr          $ra
    // 0x80682054: nop

    return;
    // 0x80682054: nop

;}
RECOMP_FUNC void func_80008FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FF8: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80008FFC: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009000: lw          $t6, 0xD84($a3)
    ctx->r14 = MEM_W(ctx->r7, 0XD84);
    // 0x80009004: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80009008: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000900C: blez        $t6, L_800091A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80009010: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_800091A0;
    }
    // 0x80009010: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80009014: beq         $a0, $zero, L_80009044
    if (ctx->r4 == 0) {
        // 0x80009018: addiu       $a1, $sp, 0x50
        ctx->r5 = ADD32(ctx->r29, 0X50);
            goto L_80009044;
    }
    // 0x80009018: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8000901C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80009020: addiu       $a0, $a0, 0x60DC
    ctx->r4 = ADD32(ctx->r4, 0X60DC);
    // 0x80009024: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80009028: jal         0x800824B0
    // 0x8000902C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000902C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80009030: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80009034: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009038: sw          $zero, 0xD84($a3)
    MEM_W(0XD84, ctx->r7) = 0;
    // 0x8000903C: b           L_800091A4
    // 0x80009040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800091A4;
    // 0x80009040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009044:
    // 0x80009044: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80009048: addiu       $a0, $a0, 0x60DC
    ctx->r4 = ADD32(ctx->r4, 0X60DC);
    // 0x8000904C: jal         0x800824B0
    // 0x80009050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80009050: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80009054: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80009058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000905C: bne         $v0, $at, L_8000906C
    if (ctx->r2 != ctx->r1) {
        // 0x80009060: addiu       $a3, $a3, 0x4D10
        ctx->r7 = ADD32(ctx->r7, 0X4D10);
            goto L_8000906C;
    }
    // 0x80009060: addiu       $a3, $a3, 0x4D10
    ctx->r7 = ADD32(ctx->r7, 0X4D10);
    // 0x80009064: b           L_800091A4
    // 0x80009068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800091A4;
    // 0x80009068: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000906C:
    // 0x8000906C: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80009070: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80009074: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80009078: srl         $v1, $v1, 24
    ctx->r3 = S32(U32(ctx->r3) >> 24);
    // 0x8000907C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80009080: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80009084: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80009088: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x8000908C: lw          $t8, 0x390($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X390);
    // 0x80009090: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80009094: bnel        $t8, $zero, L_80009100
    if (ctx->r24 != 0) {
        // 0x80009098: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80009100;
    }
    goto skip_0;
    // 0x80009098: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_0:
    // 0x8000909C: lw          $v1, 0x384($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X384);
    // 0x800090A0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800090A4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800090A8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800090AC: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x800090B0: lw          $t8, 0x380($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X380);
    // 0x800090B4: and         $t4, $a0, $at
    ctx->r12 = ctx->r4 & ctx->r1;
    // 0x800090B8: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x800090BC: srl         $t7, $t6, 30
    ctx->r15 = S32(U32(ctx->r14) >> 30);
    // 0x800090C0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x800090C4: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x800090C8: bnel        $a1, $t8, L_800090FC
    if (ctx->r5 != ctx->r24) {
        // 0x800090CC: sw          $t1, 0x390($v0)
        MEM_W(0X390, ctx->r2) = ctx->r9;
            goto L_800090FC;
    }
    goto skip_1;
    // 0x800090CC: sw          $t1, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->r9;
    skip_1:
    // 0x800090D0: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x800090D4: lw          $t9, 0x388($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X388);
    // 0x800090D8: andi        $t6, $t4, 0xFFF3
    ctx->r14 = ctx->r12 & 0XFFF3;
    // 0x800090DC: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x800090E0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800090E4: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800090E8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800090EC: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800090F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800090F4: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x800090F8: sw          $t1, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->r9;
L_800090FC:
    // 0x800090FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80009100:
    // 0x80009100: lw          $v1, 0xD84($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XD84);
    // 0x80009104: blez        $v1, L_800091A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80009108: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_800091A0;
    }
    // 0x80009108: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x8000910C: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80009110: mflo        $t8
    ctx->r24 = lo;
    // 0x80009114: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80009118: lw          $t9, 0x37C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X37C);
    // 0x8000911C: bnel        $t1, $t9, L_80009130
    if (ctx->r9 != ctx->r25) {
        // 0x80009120: lw          $v1, 0x370($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X370);
            goto L_80009130;
    }
    goto skip_2;
    // 0x80009120: lw          $v1, 0x370($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X370);
    skip_2:
    // 0x80009124: b           L_80009100
    // 0x80009128: sw          $t4, 0xD84($a3)
    MEM_W(0XD84, ctx->r7) = ctx->r12;
        goto L_80009100;
    // 0x80009128: sw          $t4, 0xD84($a3)
    MEM_W(0XD84, ctx->r7) = ctx->r12;
    // 0x8000912C: lw          $v1, 0x370($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X370);
L_80009130:
    // 0x80009130: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80009134: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80009138: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8000913C: lw          $s0, 0x4($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X4);
    // 0x80009140: lw          $t5, 0x36C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X36C);
    // 0x80009144: and         $a2, $a0, $at
    ctx->r6 = ctx->r4 & ctx->r1;
    // 0x80009148: sll         $t0, $a0, 4
    ctx->r8 = S32(ctx->r4 << 4);
    // 0x8000914C: srl         $t0, $t0, 30
    ctx->r8 = S32(U32(ctx->r8) >> 30);
    // 0x80009150: addu        $t6, $s0, $a2
    ctx->r14 = ADD32(ctx->r16, ctx->r6);
    // 0x80009154: srl         $t2, $a2, 12
    ctx->r10 = S32(U32(ctx->r6) >> 12);
    // 0x80009158: addu        $a1, $t6, $t0
    ctx->r5 = ADD32(ctx->r14, ctx->r8);
    // 0x8000915C: beq         $a1, $t5, L_80009178
    if (ctx->r5 == ctx->r13) {
        // 0x80009160: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80009178;
    }
    // 0x80009160: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80009164: sw          $t1, 0x37C($v0)
    MEM_W(0X37C, ctx->r2) = ctx->r9;
    // 0x80009168: lw          $t7, 0xD84($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XD84);
    // 0x8000916C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80009170: b           L_80009100
    // 0x80009174: sw          $t8, 0xD84($a3)
    MEM_W(0XD84, ctx->r7) = ctx->r24;
        goto L_80009100;
    // 0x80009174: sw          $t8, 0xD84($a3)
    MEM_W(0XD84, ctx->r7) = ctx->r24;
L_80009178:
    // 0x80009178: lw          $t4, 0x378($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X378);
    // 0x8000917C: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80009180: addiu       $t9, $t9, 0x60DC
    ctx->r25 = ADD32(ctx->r25, 0X60DC);
    // 0x80009184: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80009188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000918C: lw          $a1, 0x374($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X374);
    // 0x80009190: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x80009194: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80009198: jal         0x80008668
    // 0x8000919C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    func_80008668(rdram, ctx);
        goto after_2;
    // 0x8000919C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_2:
L_800091A0:
    // 0x800091A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800091A4:
    // 0x800091A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800091A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800091AC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800091B0: jr          $ra
    // 0x800091B4: nop

    return;
    // 0x800091B4: nop

;}
RECOMP_FUNC void func_8067F738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067F738: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8067F73C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067F740: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8067F744: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067F748: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8067F74C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8067F750: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8067F754: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067F758: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(547, 0X10F0) << 16);
    // 0x8067F75C: lwc1        $f10, 0x2E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(547, 0X10F0));
    // 0x8067F760: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8067F764: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8067F768: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8067F76C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8067F770: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8067F774: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8067F778: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8067F77C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8067F780: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8067F784: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8067F788: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8067F78C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8067F790: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8067F794: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8067F798: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8067F79C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8067F7A0: jalr        $t9
    // 0x8067F7A4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067F7A4: nop

    after_0:
    // 0x8067F7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067F7AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8067F7B0: jr          $ra
    // 0x8067F7B4: nop

    return;
    // 0x8067F7B4: nop

;}
RECOMP_FUNC void func_8002C164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C168: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002C16C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C170: addiu       $a1, $a1, -0x2848
    ctx->r5 = ADD32(ctx->r5, -0X2848);
    // 0x8002C174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C178: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8002C17C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002C180: jal         0x80028118
    // 0x8002C184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C184: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C188: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C18C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002C190: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x8002C194: addiu       $t6, $t6, 0x381C
    ctx->r14 = ADD32(ctx->r14, 0X381C);
    // 0x8002C198: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8002C19C: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8002C1A0: swc1        $f0, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C1A4: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8002C1A8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002C1AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002C1B0: lw          $t8, 0x134($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X134);
    // 0x8002C1B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002C1B8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002C1BC: lwc1        $f4, -0x193C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X193C);
    // 0x8002C1C0: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8002C1C4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x8002C1C8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C1CC: swc1        $f0, 0x54($t0)
    MEM_W(0X54, ctx->r8) = ctx->f0.u32l;
    // 0x8002C1D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C1D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C1D8: jr          $ra
    // 0x8002C1DC: nop

    return;
    // 0x8002C1DC: nop

;}
RECOMP_FUNC void func_806FAA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FAA54: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x806FAA58: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x806FAA5C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x806FAA60: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x806FAA64: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x806FAA68: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x806FAA6C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x806FAA70: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x806FAA74: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x806FAA78: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x806FAA7C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x806FAA80: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806FAA84: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x806FAA88: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x806FAA8C: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2600) << 16);
    // 0x806FAA90: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x806FAA94: lw          $t6, 0x138($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X138);
    // 0x806FAA98: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x806FAA9C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x806FAAA0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806FAAA4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806FAAA8: lwc1        $f4, -0x3DD0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2600));
    // 0x806FAAAC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806FAAB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FAAB4: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    // 0x806FAAB8: lwc1        $f6, 0x48($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X48);
    // 0x806FAABC: lwc1        $f24, 0x44($a0)
    ctx->f24.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806FAAC0: lwc1        $f22, 0x0($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806FAAC4: lwc1        $f28, 0x4($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806FAAC8: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x806FAACC: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
    // 0x806FAAD0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2AC0) << 16);
    // 0x806FAAD4: lwc1        $f18, -0x3910($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2AC0));
    // 0x806FAAD8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806FAADC: addiu       $s3, $zero, 0x13
    ctx->r19 = ADD32(0, 0X13);
    // 0x806FAAE0: addiu       $s0, $v0, 0x8
    ctx->r16 = ADD32(ctx->r2, 0X8);
    // 0x806FAAE4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x806FAAE8: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_806FAAEC:
    // 0x806FAAEC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x806FAAF0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x806FAAF4: lwc1        $f26, 0x4($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X4);
    // 0x806FAAF8: mul.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FAAFC: sub.s       $f14, $f26, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f28.fl;
    // 0x806FAB00: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    // 0x806FAB04: sub.s       $f30, $f20, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x806FAB08: jal         0x80067114
    // 0x806FAB0C: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x806FAB0C: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    after_0:
    // 0x806FAB10: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x806FAB14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806FAB18: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x806FAB1C: add.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x806FAB20: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x806FAB24: swc1        $f2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f2.u32l;
    // 0x806FAB28: bc1fl       L_806FAB48
    if (!c1cs) {
        // 0x806FAB2C: c.lt.s      $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
            goto L_806FAB48;
    }
    goto skip_0;
    // 0x806FAB2C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    skip_0:
    // 0x806FAB30: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x806FAB34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806FAB38: nop

    // 0x806FAB3C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806FAB40: swc1        $f16, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f16.u32l;
    // 0x806FAB44: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
L_806FAB48:
    // 0x806FAB48: nop

    // 0x806FAB4C: bc1fl       L_806FABC4
    if (!c1cs) {
        // 0x806FAB50: c.le.s      $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl <= ctx->f24.fl;
            goto L_806FABC4;
    }
    goto skip_1;
    // 0x806FAB50: c.le.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl <= ctx->f24.fl;
    skip_1:
    // 0x806FAB54: c.le.s      $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f22.fl <= ctx->f24.fl;
    // 0x806FAB58: nop

    // 0x806FAB5C: bc1fl       L_806FAC30
    if (!c1cs) {
        // 0x806FAB60: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806FAC30;
    }
    goto skip_2;
    // 0x806FAB60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x806FAB64: c.le.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl <= ctx->f20.fl;
    // 0x806FAB68: nop

    // 0x806FAB6C: bc1fl       L_806FAC30
    if (!c1cs) {
        // 0x806FAB70: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806FAC30;
    }
    goto skip_3;
    // 0x806FAB70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_3:
    // 0x806FAB74: sub.s       $f18, $f24, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x806FAB78: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x806FAB7C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x806FAB80: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x806FAB84: div.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f30.fl);
    // 0x806FAB88: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x806FAB8C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806FAB90: add.s       $f0, $f8, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x806FAB94: sub.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x806FAB98: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x806FAB9C: swc1        $f2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f2.u32l;
    // 0x806FABA0: bc1f        L_806FAC40
    if (!c1cs) {
        // 0x806FABA4: nop
    
            goto L_806FAC40;
    }
    // 0x806FABA4: nop

    // 0x806FABA8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806FABAC: nop

    // 0x806FABB0: bc1f        L_806FAC40
    if (!c1cs) {
        // 0x806FABB4: nop
    
            goto L_806FAC40;
    }
    // 0x806FABB4: nop

    // 0x806FABB8: b           L_806FAC48
    // 0x806FABBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_806FAC48;
    // 0x806FABBC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806FABC0: c.le.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl <= ctx->f24.fl;
L_806FABC4:
    // 0x806FABC4: nop

    // 0x806FABC8: bc1fl       L_806FAC30
    if (!c1cs) {
        // 0x806FABCC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806FAC30;
    }
    goto skip_4;
    // 0x806FABCC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x806FABD0: c.le.s      $f24, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f24.fl <= ctx->f22.fl;
    // 0x806FABD4: nop

    // 0x806FABD8: bc1fl       L_806FAC30
    if (!c1cs) {
        // 0x806FABDC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_806FAC30;
    }
    goto skip_5;
    // 0x806FABDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x806FABE0: sub.s       $f16, $f24, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f22.fl;
    // 0x806FABE4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x806FABE8: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x806FABEC: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x806FABF0: div.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f30.fl);
    // 0x806FABF4: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x806FABF8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806FABFC: add.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x806FAC00: sub.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x806FAC04: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x806FAC08: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
    // 0x806FAC0C: bc1f        L_806FAC40
    if (!c1cs) {
        // 0x806FAC10: nop
    
            goto L_806FAC40;
    }
    // 0x806FAC10: nop

    // 0x806FAC14: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806FAC18: nop

    // 0x806FAC1C: bc1f        L_806FAC40
    if (!c1cs) {
        // 0x806FAC20: nop
    
            goto L_806FAC40;
    }
    // 0x806FAC20: nop

    // 0x806FAC24: b           L_806FAC48
    // 0x806FAC28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_806FAC48;
    // 0x806FAC28: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806FAC2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_806FAC30:
    // 0x806FAC30: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x806FAC34: mov.s       $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.fl = ctx->f26.fl;
    // 0x806FAC38: bne         $s1, $s3, L_806FAAEC
    if (ctx->r17 != ctx->r19) {
        // 0x806FAC3C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_806FAAEC;
    }
    // 0x806FAC3C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_806FAC40:
    // 0x806FAC40: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(700, 0X2AC4) << 16);
    // 0x806FAC44: lwc1        $f0, -0x390C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(700, 0X2AC4));
L_806FAC48:
    // 0x806FAC48: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x806FAC4C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806FAC50: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x806FAC54: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x806FAC58: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x806FAC5C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x806FAC60: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x806FAC64: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x806FAC68: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x806FAC6C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x806FAC70: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x806FAC74: jr          $ra
    // 0x806FAC78: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x806FAC78: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8045BCC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BCC4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045BCC8: lui         $at, 0xC280
    ctx->r1 = S32(0XC280 << 16);
    // 0x8045BCCC: srl         $a3, $a1, 1
    ctx->r7 = S32(U32(ctx->r5) >> 1);
    // 0x8045BCD0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8045BCD4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8045BCD8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8045BCDC: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x8045BCE0: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x8045BCE4: beq         $a3, $zero, L_8045BD24
    if (ctx->r7 == 0) {
        // 0x8045BCE8: sw          $a1, 0x2C($v0)
        MEM_W(0X2C, ctx->r2) = ctx->r5;
            goto L_8045BD24;
    }
    // 0x8045BCE8: sw          $a1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r5;
    // 0x8045BCEC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045BCF0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045BCF4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BCF8: nop

L_8045BCFC:
    // 0x8045BCFC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8045BD00: sltu        $at, $t1, $a3
    ctx->r1 = ctx->r9 < ctx->r7 ? 1 : 0;
    // 0x8045BD04: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8045BD08: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x8045BD0C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8045BD10: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x8045BD14: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8045BD18: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8045BD1C: bne         $at, $zero, L_8045BCFC
    if (ctx->r1 != 0) {
        // 0x8045BD20: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8045BCFC;
    }
    // 0x8045BD20: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8045BD24:
    // 0x8045BD24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8045BD28: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8045BD2C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045BD30: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2290) << 16);
    // 0x8045BD34: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x8045BD38: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8045BD3C: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8045BD40: lwc1        $f4, -0x24E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2290));
    // 0x8045BD44: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2294) << 16);
    // 0x8045BD48: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8045BD4C: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x8045BD50: lwc1        $f6, -0x24DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2294));
    // 0x8045BD54: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(107, 0X2298) << 16);
    // 0x8045BD58: swc1        $f12, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f12.u32l;
    // 0x8045BD5C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8045BD60: lwc1        $f8, -0x24D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(107, 0X2298));
    // 0x8045BD64: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8045BD68: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
    // 0x8045BD6C: jr          $ra
    // 0x8045BD70: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8045BD70: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_800248D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800248D8: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x800248DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800248E0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800248E4: addiu       $t8, $t8, 0x4840
    ctx->r24 = ADD32(ctx->r24, 0X4840);
    // 0x800248E8: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x800248EC: sb          $t6, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r14;
    // 0x800248F0: sw          $t7, 0x150($a0)
    MEM_W(0X150, ctx->r4) = ctx->r15;
    // 0x800248F4: jr          $ra
    // 0x800248F8: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
    return;
    // 0x800248F8: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_80742A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742A94: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742A98: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742A9C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742AA0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742AA4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742AA8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742AAC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742AB0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742AB4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742AB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742ABC: jr          $ra
    // 0x80742AC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742AC0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B95DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B95DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B95E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B95E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B95E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B95EC: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x807B95F0: sb          $t6, 0x165($t7)
    MEM_B(0X165, ctx->r15) = ctx->r14;
    // 0x807B95F4: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x807B95F8: blez        $v1, L_807B9608
    if (SIGNED(ctx->r3) <= 0) {
        // 0x807B95FC: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_807B9608;
    }
    // 0x807B95FC: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x807B9600: b           L_807B965C
    // 0x807B9604: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
        goto L_807B965C;
    // 0x807B9604: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
L_807B9608:
    // 0x807B9608: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x807B960C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x807B9610: addiu       $a1, $t9, 0x10
    ctx->r5 = ADD32(ctx->r25, 0X10);
    // 0x807B9614: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x807B9618: bne         $at, $zero, L_807B9654
    if (ctx->r1 != 0) {
        // 0x807B961C: sw          $a1, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r5;
            goto L_807B9654;
    }
    // 0x807B961C: sw          $a1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r5;
    // 0x807B9620: sw          $t1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r9;
    // 0x807B9624: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807B9628: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x807B962C: jal         0x807B93C0
    // 0x807B9630: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    func_807B93C0(rdram, ctx);
        goto after_0;
    // 0x807B9630: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x807B9634: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B9638: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x807B963C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B9640: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x807B9644: jal         0x807B9E2C
    // 0x807B9648: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    func_807B9E2C(rdram, ctx);
        goto after_1;
    // 0x807B9648: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    after_1:
    // 0x807B964C: b           L_807B9660
    // 0x807B9650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807B9660;
    // 0x807B9650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9654:
    // 0x807B9654: jal         0x807B93C0
    // 0x807B9658: nop

    func_807B93C0(rdram, ctx);
        goto after_2;
    // 0x807B9658: nop

    after_2:
L_807B965C:
    // 0x807B965C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B9660:
    // 0x807B9660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807B9664: jr          $ra
    // 0x807B9668: nop

    return;
    // 0x807B9668: nop

;}
RECOMP_FUNC void func_8002B698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B698: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002B69C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002B6A0: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x8002B6A4: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x8002B6A8: lw          $t6, 0xF10($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XF10);
    // 0x8002B6AC: lw          $t9, 0xAA4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAA4);
    // 0x8002B6B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002B6B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8002B6B8: addu        $t8, $s1, $t7
    ctx->r24 = ADD32(ctx->r17, ctx->r15);
    // 0x8002B6BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002B6C0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002B6C4: beq         $t9, $zero, L_8002B6F0
    if (ctx->r25 == 0) {
        // 0x8002B6C8: lw          $s0, 0xF14($t8)
        ctx->r16 = MEM_W(ctx->r24, 0XF14);
            goto L_8002B6F0;
    }
    // 0x8002B6C8: lw          $s0, 0xF14($t8)
    ctx->r16 = MEM_W(ctx->r24, 0XF14);
    // 0x8002B6CC: sw          $zero, 0xAA4($s1)
    MEM_W(0XAA4, ctx->r17) = 0;
    // 0x8002B6D0: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x8002B6D4: jal         0x80067D28
    // 0x8002B6D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80067D28(rdram, ctx);
        goto after_0;
    // 0x8002B6D8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x8002B6DC: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    // 0x8002B6E0: jal         0x80067818
    // 0x8002B6E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x8002B6E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8002B6E8: b           L_8002B778
    // 0x8002B6EC: lw          $t0, 0xF10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XF10);
        goto L_8002B778;
    // 0x8002B6EC: lw          $t0, 0xF10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XF10);
L_8002B6F0:
    // 0x8002B6F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002B6F4: addiu       $s0, $s0, -0x3
    ctx->r16 = ADD32(ctx->r16, -0X3);
    // 0x8002B6F8: bgtz        $s0, L_8002B760
    if (SIGNED(ctx->r16) > 0) {
        // 0x8002B6FC: nop
    
            goto L_8002B760;
    }
    // 0x8002B6FC: nop

    // 0x8002B700: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002B704: jal         0x8001D770
    // 0x8002B708: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8002B708: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x8002B70C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8002B710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002B714: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x8002B718: jal         0x80067BF8
    // 0x8002B71C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8002B71C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_3:
    // 0x8002B720: addiu       $a0, $zero, 0x85
    ctx->r4 = ADD32(0, 0X85);
    // 0x8002B724: jal         0x80067818
    // 0x8002B728: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002B728: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8002B72C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002B730: jal         0x80067D28
    // 0x8002B734: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80067D28(rdram, ctx);
        goto after_5;
    // 0x8002B734: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_5:
    // 0x8002B738: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    // 0x8002B73C: jal         0x80067818
    // 0x8002B740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002B740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002B744: addiu       $a0, $zero, 0x263
    ctx->r4 = ADD32(0, 0X263);
    // 0x8002B748: jal         0x80067818
    // 0x8002B74C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8002B74C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8002B750: jal         0x8004977C
    // 0x8002B754: nop

    func_8004977C(rdram, ctx);
        goto after_8;
    // 0x8002B754: nop

    after_8:
    // 0x8002B758: b           L_8002B778
    // 0x8002B75C: lw          $t0, 0xF10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XF10);
        goto L_8002B778;
    // 0x8002B75C: lw          $t0, 0xF10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XF10);
L_8002B760:
    // 0x8002B760: jal         0x80067D28
    // 0x8002B764: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80067D28(rdram, ctx);
        goto after_9;
    // 0x8002B764: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x8002B768: addiu       $a0, $zero, 0x25F
    ctx->r4 = ADD32(0, 0X25F);
    // 0x8002B76C: jal         0x80067818
    // 0x8002B770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8002B770: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8002B774: lw          $t0, 0xF10($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XF10);
L_8002B778:
    // 0x8002B778: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8002B77C: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x8002B780: sw          $s0, 0xF14($t2)
    MEM_W(0XF14, ctx->r10) = ctx->r16;
    // 0x8002B784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002B788: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002B78C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002B790: jr          $ra
    // 0x8002B794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002B794: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80447350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447350: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447354: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80447358: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044735C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447360: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447364: bne         $a2, $zero, L_804473A4
    if (ctx->r6 != 0) {
        // 0x80447368: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804473A4;
    }
    // 0x80447368: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044736C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80447370: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x80447374: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80447378: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8044737C: bne         $at, $zero, L_804473E4
    if (ctx->r1 != 0) {
        // 0x80447380: sw          $t7, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r15;
            goto L_804473E4;
    }
    // 0x80447380: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80447384: jal         0x80445FD4
    // 0x80447388: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_0;
    // 0x80447388: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8044738C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447390: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80447394: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80447398: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8044739C: b           L_804473E4
    // 0x804473A0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_804473E4;
    // 0x804473A0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_804473A4:
    // 0x804473A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804473A8: bnel        $a2, $at, L_804473D4
    if (ctx->r6 != ctx->r1) {
        // 0x804473AC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_804473D4;
    }
    goto skip_0;
    // 0x804473AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804473B0: jal         0x80445FD4
    // 0x804473B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445FD4(rdram, ctx);
        goto after_1;
    // 0x804473B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804473B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804473BC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804473C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804473C4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804473C8: b           L_804473E4
    // 0x804473CC: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_804473E4;
    // 0x804473CC: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x804473D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_804473D4:
    // 0x804473D4: bnel        $a2, $at, L_804473E8
    if (ctx->r6 != ctx->r1) {
        // 0x804473D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804473E8;
    }
    goto skip_1;
    // 0x804473D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804473DC: jal         0x8044602C
    // 0x804473E0: nop

    func_8044602C(rdram, ctx);
        goto after_2;
    // 0x804473E0: nop

    after_2:
L_804473E4:
    // 0x804473E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804473E8:
    // 0x804473E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804473EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804473F0: jr          $ra
    // 0x804473F4: nop

    return;
    // 0x804473F4: nop

;}
RECOMP_FUNC void func_804D8394(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D839C: jal         0x804D88E4
    // 0x804D83A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804D88E4(rdram, ctx);
        goto after_0;
    // 0x804D83A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x804D83A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D83A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D83AC: jr          $ra
    // 0x804D83B0: nop

    return;
    // 0x804D83B0: nop

;}
RECOMP_FUNC void func_80737A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737A2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80737A30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80737A34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80737A38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80737A3C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80737A40: jal         0x8004700C
    // 0x80737A44: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80737A44: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80737A48: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    // 0x80737A4C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80737A50: jal         0x80066DE4
    // 0x80737A54: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80737A54: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_1:
    // 0x80737A58: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x80737A5C: jal         0x80066E88
    // 0x80737A60: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80737A60: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    after_2:
    // 0x80737A64: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80737A68: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80737A6C: beql        $v1, $zero, L_80737B40
    if (ctx->r3 == 0) {
        // 0x80737A70: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80737B40;
    }
    goto skip_0;
    // 0x80737A70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80737A74: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80737A78: lwc1        $f6, 0x84($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X84);
    // 0x80737A7C: addiu       $v0, $s1, 0xC4
    ctx->r2 = ADD32(ctx->r17, 0XC4);
    // 0x80737A80: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B98) << 16);
    // 0x80737A84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80737A88: swc1        $f8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f8.u32l;
    // 0x80737A8C: lwc1        $f4, 0x88($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X88);
    // 0x80737A90: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80737A94: lwc1        $f12, 0x38($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80737A98: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80737A9C: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80737AA0: lwc1        $f14, 0x4($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80737AA4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80737AA8: lwc1        $f2, 0x3C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80737AAC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80737AB0: nop

    // 0x80737AB4: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80737AB8: nop

    // 0x80737ABC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80737AC0: nop

    // 0x80737AC4: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80737AC8: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80737ACC: mul.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80737AD0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80737AD4: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80737AD8: nop

    // 0x80737ADC: mul.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80737AE0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80737AE4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80737AE8: lwc1        $f10, -0x6A08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B98));
    // 0x80737AEC: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B9C) << 16);
    // 0x80737AF0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80737AF4: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80737AF8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80737AFC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80737B00: nop

    // 0x80737B04: bc1t        L_80737B30
    if (c1cs) {
        // 0x80737B08: nop
    
            goto L_80737B30;
    }
    // 0x80737B08: nop

    // 0x80737B0C: lwc1        $f4, -0x6A04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B9C));
    // 0x80737B10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80737B14: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80737B18: nop

    // 0x80737B1C: bc1tl       L_80737B34
    if (c1cs) {
        // 0x80737B20: div.s       $f10, $f8, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
            goto L_80737B34;
    }
    goto skip_1;
    // 0x80737B20: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    skip_1:
    // 0x80737B24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80737B28: b           L_80737B54
    // 0x80737B2C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
        goto L_80737B54;
    // 0x80737B2C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
L_80737B30:
    // 0x80737B30: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
L_80737B34:
    // 0x80737B34: b           L_80737B54
    // 0x80737B38: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
        goto L_80737B54;
    // 0x80737B38: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x80737B3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80737B40:
    // 0x80737B40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80737B44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80737B48: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
    // 0x80737B4C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80737B50: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
L_80737B54:
    // 0x80737B54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80737B58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80737B5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80737B60: jr          $ra
    // 0x80737B64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80737B64: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80527B20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527B28: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80527B2C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80527B30: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80527B34: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80527B38: jal         0x80067BBC
    // 0x80527B3C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80527B3C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80527B40: addiu       $a0, $zero, 0x97
    ctx->r4 = ADD32(0, 0X97);
    // 0x80527B44: jal         0x80067818
    // 0x80527B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80527B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80527B4C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80527B50: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6198) << 16);
    // 0x80527B54: lwc1        $f4, -0x3F68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6198));
    // 0x80527B58: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x80527B5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80527B60: lui         $v0, 0x8053
    ctx->r2 = S32(RELOC_HI16(327, 0X591C) << 16);
    // 0x80527B64: addiu       $v0, $v0, -0x47E4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(327, 0X591C));
    // 0x80527B68: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(327, 0X1CA4) << 16);
    // 0x80527B6C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80527B70: addiu       $t7, $t7, 0x7BA4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(327, 0X1CA4));
    // 0x80527B74: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x80527B78: sw          $t6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r14;
    // 0x80527B7C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80527B80: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80527B84: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x80527B88: sw          $t7, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r15;
    // 0x80527B8C: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80527B90: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80527B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80527B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527B9C: jr          $ra
    // 0x80527BA0: nop

    return;
    // 0x80527BA0: nop

;}
RECOMP_FUNC void func_8069D170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D178: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8069D17C: lui         $t6, 0x806A
    ctx->r14 = S32(RELOC_HI16(571, 0X6C0) << 16);
    // 0x8069D180: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8069D184: addiu       $t6, $t6, -0x2C50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(571, 0X6C0));
    // 0x8069D188: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8069D18C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8069D190: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8069D194: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8069D198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8069D19C: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x8069D1A0: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x8069D1A4: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8069D1A8: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x8069D1AC: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x8069D1B0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8069D1B4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x8069D1B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069D1BC: jal         0x80045A34
    // 0x8069D1C0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8069D1C0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8069D1C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D1C8: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(571, 0X43C) << 16);
    // 0x8069D1CC: addiu       $t8, $t8, -0x2ED4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(571, 0X43C));
    // 0x8069D1D0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8069D1D4: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x8069D1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D1DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D1E0: jr          $ra
    // 0x8069D1E4: nop

    return;
    // 0x8069D1E4: nop

;}
RECOMP_FUNC void func_804413E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804413E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804413E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804413E8: jal         0x8004700C
    // 0x804413EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804413EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804413F0: beq         $v0, $zero, L_80441444
    if (ctx->r2 == 0) {
        // 0x804413F4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80441444;
    }
    // 0x804413F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804413F8: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x804413FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80441400: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80441404: bne         $t7, $at, L_8044141C
    if (ctx->r15 != ctx->r1) {
        // 0x80441408: nop
    
            goto L_8044141C;
    }
    // 0x80441408: nop

    // 0x8044140C: jal         0x8043F6F4
    // 0x80441410: nop

    func_8043F6F4(rdram, ctx);
        goto after_1;
    // 0x80441410: nop

    after_1:
    // 0x80441414: b           L_80441448
    // 0x80441418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80441448;
    // 0x80441418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044141C:
    // 0x8044141C: jal         0x80440950
    // 0x80441420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80440950(rdram, ctx);
        goto after_2;
    // 0x80441420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x80441424: beq         $v0, $zero, L_8044143C
    if (ctx->r2 == 0) {
        // 0x80441428: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8044143C;
    }
    // 0x80441428: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8044142C: jal         0x8043F46C
    // 0x80441430: nop

    func_8043F46C(rdram, ctx);
        goto after_3;
    // 0x80441430: nop

    after_3:
    // 0x80441434: b           L_80441448
    // 0x80441438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80441448;
    // 0x80441438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044143C:
    // 0x8044143C: jal         0x80441330
    // 0x80441440: nop

    func_80441330(rdram, ctx);
        goto after_4;
    // 0x80441440: nop

    after_4:
L_80441444:
    // 0x80441444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80441448:
    // 0x80441448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044144C: jr          $ra
    // 0x80441450: nop

    return;
    // 0x80441450: nop

;}
RECOMP_FUNC void func_805D2238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2238: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(471, 0X23BC) << 16);
    // 0x805D223C: addiu       $t6, $t6, 0x3DEC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(471, 0X23BC));
    // 0x805D2240: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x805D2244: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2248: addiu       $v1, $sp, 0x8
    ctx->r3 = ADD32(ctx->r29, 0X8);
    // 0x805D224C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x805D2250: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x805D2254: lui         $t2, 0x805D
    ctx->r10 = S32(RELOC_HI16(471, 0X23CC) << 16);
    // 0x805D2258: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x805D225C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x805D2260: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x805D2264: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805D2268: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x805D226C: lw          $t9, 0x1E0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1E0);
    // 0x805D2270: addiu       $v0, $t9, 0x1
    ctx->r2 = ADD32(ctx->r25, 0X1);
    // 0x805D2274: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x805D2278: bne         $at, $zero, L_805D2288
    if (ctx->r1 != 0) {
        // 0x805D227C: sw          $v0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r2;
            goto L_805D2288;
    }
    // 0x805D227C: sw          $v0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r2;
    // 0x805D2280: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D2284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805D2288:
    // 0x805D2288: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x805D228C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805D2290: lh          $t2, 0x3DFC($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(471, 0X23CC));
    // 0x805D2294: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x805D2298: lh          $t3, 0x144($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X144);
    // 0x805D229C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x805D22A0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x805D22A4: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x805D22A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D22AC: jr          $ra
    // 0x805D22B0: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x805D22B0: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80475270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475270: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475274: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475278: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047527C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475280: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475284: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475288: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047528C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475290: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475294: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475298: jr          $ra
    // 0x8047529C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047529C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80515B60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80515B64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80515B68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80515B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80515B70: lui         $at, 0x8051
    ctx->r1 = S32(RELOC_HI16(276, 0XE6C) << 16);
    // 0x80515B74: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80515B78: lwc1        $f4, 0x630C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(276, 0XE6C));
    // 0x80515B7C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80515B80: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80515B84: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80515B88: nop

    // 0x80515B8C: bc1fl       L_80515BBC
    if (!c1cs) {
        // 0x80515B90: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80515BBC;
    }
    goto skip_0;
    // 0x80515B90: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80515B94: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80515B98: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80515B9C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80515BA0: sb          $t6, 0x18($t7)
    MEM_B(0X18, ctx->r15) = ctx->r14;
    // 0x80515BA4: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80515BA8: jal         0x80515DD4
    // 0x80515BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80515DD4(rdram, ctx);
        goto after_0;
    // 0x80515BAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80515BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80515BB4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80515BB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80515BBC:
    // 0x80515BBC: jal         0x805158B4
    // 0x80515BC0: nop

    func_805158B4(rdram, ctx);
        goto after_1;
    // 0x80515BC0: nop

    after_1:
    // 0x80515BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515BC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515BCC: jr          $ra
    // 0x80515BD0: nop

    return;
    // 0x80515BD0: nop

;}
RECOMP_FUNC void func_807B4E4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4E4C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x807B4E50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B4E54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B4E58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B4E5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B4E60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B4E64: lw          $s2, 0x14($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X14);
    // 0x807B4E68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B4E6C: jal         0x807B4A10
    // 0x807B4E70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B4E70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x807B4E74: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2D34) << 16);
    // 0x807B4E78: addiu       $a1, $a1, 0x7534
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2D34));
    // 0x807B4E7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4E80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B4E84: jal         0x807B4900
    // 0x807B4E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B4E88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4E8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4E90: jal         0x807B4A10
    // 0x807B4E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_807B4A10(rdram, ctx);
        goto after_2;
    // 0x807B4E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x807B4E98: jal         0x807B4A74
    // 0x807B4E9C: nop

    func_807B4A74(rdram, ctx);
        goto after_3;
    // 0x807B4E9C: nop

    after_3:
    // 0x807B4EA0: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x807B4EA4: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x807B4EA8: lw          $t6, 0xCEC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XCEC);
    // 0x807B4EAC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x807B4EB0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x807B4EB4: jal         0x807B4B3C
    // 0x807B4EB8: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    func_807B4B3C(rdram, ctx);
        goto after_4;
    // 0x807B4EB8: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    after_4:
    // 0x807B4EBC: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x807B4EC0: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
L_807B4EC4:
    // 0x807B4EC4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4EC8: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x807B4ECC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B4ED0: jal         0x8005C27C
    // 0x807B4ED4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B4ED4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x807B4ED8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B4EDC: slti        $at, $s0, 0x78
    ctx->r1 = SIGNED(ctx->r16) < 0X78 ? 1 : 0;
    // 0x807B4EE0: bne         $at, $zero, L_807B4EC4
    if (ctx->r1 != 0) {
        // 0x807B4EE4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B4EC4;
    }
    // 0x807B4EE4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B4EE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4EEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B4EF0: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B4EF4: jal         0x8005C27C
    // 0x807B4EF8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B4EF8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x807B4EFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4F00: jal         0x807B4A10
    // 0x807B4F04: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_807B4A10(rdram, ctx);
        goto after_7;
    // 0x807B4F04: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_7:
    // 0x807B4F08: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2D64) << 16);
    // 0x807B4F0C: addiu       $a1, $a1, 0x7564
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2D64));
    // 0x807B4F10: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4F14: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x807B4F18: jal         0x807B4900
    // 0x807B4F1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_8;
    // 0x807B4F1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x807B4F20: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4F24: jal         0x807B4A10
    // 0x807B4F28: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_807B4A10(rdram, ctx);
        goto after_9;
    // 0x807B4F28: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_9:
    // 0x807B4F2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B4F30: jal         0x80069644
    // 0x807B4F34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80069644(rdram, ctx);
        goto after_10;
    // 0x807B4F34: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_10:
    // 0x807B4F38: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x807B4F3C: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
L_807B4F40:
    // 0x807B4F40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4F44: lhu         $a1, 0x0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X0);
    // 0x807B4F48: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B4F4C: jal         0x8005C27C
    // 0x807B4F50: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x807B4F50: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_11:
    // 0x807B4F54: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B4F58: slti        $at, $s0, 0x48
    ctx->r1 = SIGNED(ctx->r16) < 0X48 ? 1 : 0;
    // 0x807B4F5C: bne         $at, $zero, L_807B4F40
    if (ctx->r1 != 0) {
        // 0x807B4F60: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_807B4F40;
    }
    // 0x807B4F60: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x807B4F64: lhu         $a1, 0xFC0($s3)
    ctx->r5 = MEM_HU(ctx->r19, 0XFC0);
    // 0x807B4F68: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x807B4F6C: jal         0x807B4B3C
    // 0x807B4F70: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_807B4B3C(rdram, ctx);
        goto after_12;
    // 0x807B4F70: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_12:
    // 0x807B4F74: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x807B4F78: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
    // 0x807B4F7C: addiu       $s3, $zero, 0x78
    ctx->r19 = ADD32(0, 0X78);
L_807B4F80:
    // 0x807B4F80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4F84: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x807B4F88: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B4F8C: jal         0x8005C27C
    // 0x807B4F90: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_13;
    // 0x807B4F90: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_13:
    // 0x807B4F94: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B4F98: bne         $s0, $s3, L_807B4F80
    if (ctx->r16 != ctx->r19) {
        // 0x807B4F9C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_807B4F80;
    }
    // 0x807B4F9C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x807B4FA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x807B4FA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B4FA8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B4FAC: jal         0x8005C27C
    // 0x807B4FB0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_14;
    // 0x807B4FB0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_14:
    // 0x807B4FB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B4FB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B4FBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B4FC0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B4FC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B4FC8: jr          $ra
    // 0x807B4FCC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x807B4FCC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80519E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519E90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80519E94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80519E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80519E9C: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80519EA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80519EA4: lw          $t7, 0x88($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X88);
    // 0x80519EA8: jal         0x80519DE8
    // 0x80519EAC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_80519DE8(rdram, ctx);
        goto after_0;
    // 0x80519EAC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80519EB0: beq         $v0, $zero, L_80519F74
    if (ctx->r2 == 0) {
        // 0x80519EB4: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_80519F74;
    }
    // 0x80519EB4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80519EB8: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80519EBC: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(291, 0X24B0) << 16);
    // 0x80519EC0: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x80519EC4: addiu       $t9, $t9, -0x5EE0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(291, 0X24B0));
    // 0x80519EC8: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80519ECC: lui         $t2, 0x8052
    ctx->r10 = S32(RELOC_HI16(291, 0X21F8) << 16);
    // 0x80519ED0: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x80519ED4: addiu       $t2, $t2, -0x6198
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(291, 0X21F8));
    // 0x80519ED8: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80519EDC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80519EE0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80519EE4: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x80519EE8: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x80519EEC: sh          $t3, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r11;
    // 0x80519EF0: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
    // 0x80519EF4: lbu         $a1, 0x30($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X30);
    // 0x80519EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80519EFC: jal         0x80519AFC
    // 0x80519F00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80519AFC(rdram, ctx);
        goto after_1;
    // 0x80519F00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80519F04: lbu         $t5, 0x30($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X30);
    // 0x80519F08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80519F0C: beq         $t5, $zero, L_80519F1C
    if (ctx->r13 == 0) {
        // 0x80519F10: addiu       $a1, $a1, 0x200
        ctx->r5 = ADD32(ctx->r5, 0X200);
            goto L_80519F1C;
    }
    // 0x80519F10: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    // 0x80519F14: jal         0x8004590C
    // 0x80519F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004590C(rdram, ctx);
        goto after_2;
    // 0x80519F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
L_80519F1C:
    // 0x80519F1C: jal         0x80519E3C
    // 0x80519F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80519E3C(rdram, ctx);
        goto after_3;
    // 0x80519F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80519F24: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80519F28: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(291, 0X20B0) << 16);
    // 0x80519F2C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80519F30: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80519F34: addiu       $t7, $t7, -0x62E0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(291, 0X20B0));
    // 0x80519F38: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80519F3C: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80519F40: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x80519F44: lw          $t8, 0x3EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3EC);
    // 0x80519F48: addiu       $at, $zero, 0x4E
    ctx->r1 = ADD32(0, 0X4E);
    // 0x80519F4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80519F50: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80519F54: lbu         $t0, 0x598($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X598);
    // 0x80519F58: addiu       $v0, $zero, 0x180
    ctx->r2 = ADD32(0, 0X180);
    // 0x80519F5C: bne         $t0, $at, L_80519F6C
    if (ctx->r8 != ctx->r1) {
        // 0x80519F60: nop
    
            goto L_80519F6C;
    }
    // 0x80519F60: nop

    // 0x80519F64: sh          $v0, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r2;
    // 0x80519F68: sh          $v0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r2;
L_80519F6C:
    // 0x80519F6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80519F70: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
L_80519F74:
    // 0x80519F74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80519F78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80519F7C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80519F80: jr          $ra
    // 0x80519F84: nop

    return;
    // 0x80519F84: nop

;}
RECOMP_FUNC void func_80429C44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80429C44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80429C48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80429C4C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80429C50: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80429C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80429C58: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80429C5C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80429C60: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80429C64: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80429C68: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80429C6C: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(44, 0X268) << 16);
    // 0x80429C70: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80429C74: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80429C78: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80429C7C: lw          $t2, -0x62C8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(44, 0X268));
    // 0x80429C80: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80429C84: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80429C88: jal         0x80429B68
    // 0x80429C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80429B68(rdram, ctx);
        goto after_0;
    // 0x80429C8C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80429C90: jal         0x80429BC4
    // 0x80429C94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80429BC4(rdram, ctx);
        goto after_1;
    // 0x80429C94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80429C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429C9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429CA0: jr          $ra
    // 0x80429CA4: nop

    return;
    // 0x80429CA4: nop

    // 0x80429CA8: nop

    // 0x80429CAC: nop

;}
RECOMP_FUNC void func_8042ECD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042ECD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042ECDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042ECE0: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8042ECE4: jal         0x8042E6BC
    // 0x8042ECE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042E6BC(rdram, ctx);
        goto after_0;
    // 0x8042ECE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042ECEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042ECF0: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(56, 0X3B88) << 16);
    // 0x8042ECF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8042ECF8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x8042ECFC: lwc1        $f6, 0x1C68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(56, 0X3B88));
    // 0x8042ED00: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8042ED04: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8042ED08: nop

    // 0x8042ED0C: bc1fl       L_8042ED20
    if (!c1cs) {
        // 0x8042ED10: sw          $zero, 0x138($a0)
        MEM_W(0X138, ctx->r4) = 0;
            goto L_8042ED20;
    }
    goto skip_0;
    // 0x8042ED10: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    skip_0:
    // 0x8042ED14: b           L_8042ED20
    // 0x8042ED18: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
        goto L_8042ED20;
    // 0x8042ED18: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x8042ED1C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
L_8042ED20:
    // 0x8042ED20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042ED24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042ED28: jr          $ra
    // 0x8042ED2C: nop

    return;
    // 0x8042ED2C: nop

;}
RECOMP_FUNC void func_8074224C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8074224C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80742250: beql        $at, $zero, L_80742264
    if (ctx->r1 == 0) {
        // 0x80742254: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80742264;
    }
    goto skip_0;
    // 0x80742254: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80742258: jr          $ra
    // 0x8074225C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x8074225C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80742260: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80742264:
    // 0x80742264: beq         $at, $zero, L_807422A0
    if (ctx->r1 == 0) {
        // 0x80742268: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_807422A0;
    }
    // 0x80742268: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x8074226C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80742270: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742274: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80742278: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8074227C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80742280: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x80742284: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80742288: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8074228C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80742290: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80742294: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80742298: jr          $ra
    // 0x8074229C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x8074229C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_807422A0:
    // 0x807422A0: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x807422A4: beq         $at, $zero, L_807422BC
    if (ctx->r1 == 0) {
        // 0x807422A8: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_807422BC;
    }
    // 0x807422A8: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x807422AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807422B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807422B4: jr          $ra
    // 0x807422B8: nop

    return;
    // 0x807422B8: nop

L_807422BC:
    // 0x807422BC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x807422C0: beq         $at, $zero, L_80742300
    if (ctx->r1 == 0) {
        // 0x807422C4: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80742300;
    }
    // 0x807422C4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807422C8: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x807422CC: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x807422D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807422D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807422D8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x807422DC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x807422E0: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x807422E4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x807422E8: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x807422EC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807422F0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807422F4: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807422F8: jr          $ra
    // 0x807422FC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x807422FC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80742300:
    // 0x80742300: jr          $ra
    // 0x80742304: nop

    return;
    // 0x80742304: nop

;}
RECOMP_FUNC void func_8002780C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002780C: lui         $t6, 0x8002
    ctx->r14 = S32(0X8002 << 16);
    // 0x80027810: addiu       $t6, $t6, 0x7744
    ctx->r14 = ADD32(ctx->r14, 0X7744);
    // 0x80027814: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80027818: jr          $ra
    // 0x8002781C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
    return;
    // 0x8002781C: sw          $t6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80039A00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039A00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039A04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039A08: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80039A0C: addiu       $t7, $t6, -0x4002
    ctx->r15 = ADD32(ctx->r14, -0X4002);
    // 0x80039A10: sltiu       $at, $t7, 0x1D
    ctx->r1 = ctx->r15 < 0X1D ? 1 : 0;
    // 0x80039A14: beq         $at, $zero, L_80039AA8
    if (ctx->r1 == 0) {
        // 0x80039A18: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80039AA8;
    }
    // 0x80039A18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80039A1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80039A20: addu        $at, $at, $t7
    gpr jr_addend_80039A28 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80039A24: lw          $t7, 0x16C($at)
    ctx->r15 = ADD32(ctx->r1, 0X16C);
    // 0x80039A28: jr          $t7
    // 0x80039A2C: nop

    switch (jr_addend_80039A28 >> 2) {
        case 0: goto L_80039A30; break;
        case 1: goto L_80039AA8; break;
        case 2: goto L_80039A44; break;
        case 3: goto L_80039A58; break;
        case 4: goto L_80039AA8; break;
        case 5: goto L_80039AA8; break;
        case 6: goto L_80039AA8; break;
        case 7: goto L_80039AA8; break;
        case 8: goto L_80039AA8; break;
        case 9: goto L_80039AA8; break;
        case 10: goto L_80039AA8; break;
        case 11: goto L_80039AA8; break;
        case 12: goto L_80039AA8; break;
        case 13: goto L_80039AA8; break;
        case 14: goto L_80039AA8; break;
        case 15: goto L_80039AA8; break;
        case 16: goto L_80039AA8; break;
        case 17: goto L_80039AA8; break;
        case 18: goto L_80039AA8; break;
        case 19: goto L_80039AA8; break;
        case 20: goto L_80039AA8; break;
        case 21: goto L_80039AA8; break;
        case 22: goto L_80039AA8; break;
        case 23: goto L_80039AA8; break;
        case 24: goto L_80039AA8; break;
        case 25: goto L_80039AA8; break;
        case 26: goto L_80039A6C; break;
        case 27: goto L_80039A80; break;
        case 28: goto L_80039A94; break;
        default: switch_error(__func__, 0x80039A28, 0x800B016C);
    }
    // 0x80039A2C: nop

L_80039A30:
    // 0x80039A30: jal         0x80039B20
    // 0x80039A34: nop

    func_80039B20(rdram, ctx);
        goto after_0;
    // 0x80039A34: nop

    after_0:
    // 0x80039A38: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039A3C: b           L_80039AAC
    // 0x80039A40: addiu       $v0, $v0, -0x4F30
    ctx->r2 = ADD32(ctx->r2, -0X4F30);
        goto L_80039AAC;
    // 0x80039A40: addiu       $v0, $v0, -0x4F30
    ctx->r2 = ADD32(ctx->r2, -0X4F30);
L_80039A44:
    // 0x80039A44: jal         0x80039B68
    // 0x80039A48: nop

    func_80039B68(rdram, ctx);
        goto after_1;
    // 0x80039A48: nop

    after_1:
    // 0x80039A4C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039A50: b           L_80039AAC
    // 0x80039A54: addiu       $v0, $v0, -0x4D50
    ctx->r2 = ADD32(ctx->r2, -0X4D50);
        goto L_80039AAC;
    // 0x80039A54: addiu       $v0, $v0, -0x4D50
    ctx->r2 = ADD32(ctx->r2, -0X4D50);
L_80039A58:
    // 0x80039A58: jal         0x80039BB0
    // 0x80039A5C: nop

    func_80039BB0(rdram, ctx);
        goto after_2;
    // 0x80039A5C: nop

    after_2:
    // 0x80039A60: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039A64: b           L_80039AAC
    // 0x80039A68: addiu       $v0, $v0, -0x4D50
    ctx->r2 = ADD32(ctx->r2, -0X4D50);
        goto L_80039AAC;
    // 0x80039A68: addiu       $v0, $v0, -0x4D50
    ctx->r2 = ADD32(ctx->r2, -0X4D50);
L_80039A6C:
    // 0x80039A6C: jal         0x80039BF8
    // 0x80039A70: nop

    func_80039BF8(rdram, ctx);
        goto after_3;
    // 0x80039A70: nop

    after_3:
    // 0x80039A74: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039A78: b           L_80039AAC
    // 0x80039A7C: addiu       $v0, $v0, -0x4CD8
    ctx->r2 = ADD32(ctx->r2, -0X4CD8);
        goto L_80039AAC;
    // 0x80039A7C: addiu       $v0, $v0, -0x4CD8
    ctx->r2 = ADD32(ctx->r2, -0X4CD8);
L_80039A80:
    // 0x80039A80: jal         0x80039C40
    // 0x80039A84: nop

    func_80039C40(rdram, ctx);
        goto after_4;
    // 0x80039A84: nop

    after_4:
    // 0x80039A88: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039A8C: b           L_80039AAC
    // 0x80039A90: addiu       $v0, $v0, -0x4CD8
    ctx->r2 = ADD32(ctx->r2, -0X4CD8);
        goto L_80039AAC;
    // 0x80039A90: addiu       $v0, $v0, -0x4CD8
    ctx->r2 = ADD32(ctx->r2, -0X4CD8);
L_80039A94:
    // 0x80039A94: jal         0x80039C88
    // 0x80039A98: nop

    func_80039C88(rdram, ctx);
        goto after_5;
    // 0x80039A98: nop

    after_5:
    // 0x80039A9C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80039AA0: b           L_80039AAC
    // 0x80039AA4: addiu       $v0, $v0, -0x4DE8
    ctx->r2 = ADD32(ctx->r2, -0X4DE8);
        goto L_80039AAC;
    // 0x80039AA4: addiu       $v0, $v0, -0x4DE8
    ctx->r2 = ADD32(ctx->r2, -0X4DE8);
L_80039AA8:
    // 0x80039AA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80039AAC:
    // 0x80039AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039AB4: jr          $ra
    // 0x80039AB8: nop

    return;
    // 0x80039AB8: nop

;}
RECOMP_FUNC void func_806F824C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F824C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x806F8250: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x806F8254: lw          $t7, 0xC78($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC78);
    // 0x806F8258: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x806F825C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806F8260: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806F8264: sw          $t6, 0xC7C($t9)
    MEM_W(0XC7C, ctx->r25) = ctx->r14;
    // 0x806F8268: lw          $t0, 0xC78($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC78);
    // 0x806F826C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x806F8270: jr          $ra
    // 0x806F8274: sw          $t1, 0xC78($v0)
    MEM_W(0XC78, ctx->r2) = ctx->r9;
    return;
    // 0x806F8274: sw          $t1, 0xC78($v0)
    MEM_W(0XC78, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_800359EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800359EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800359F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800359F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800359F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800359FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80035A00: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x80035A04: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x80035A08: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80035A0C: bne         $t7, $zero, L_80035A60
    if (ctx->r15 != 0) {
        // 0x80035A10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80035A60;
    }
    // 0x80035A10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80035A14: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80035A18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035A1C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80035A20: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80035A24: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80035A28: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80035A2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A30: bc1f        L_80035A50
    if (!c1cs) {
        // 0x80035A34: nop
    
            goto L_80035A50;
    }
    // 0x80035A34: nop

    // 0x80035A38: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80035A3C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80035A40: jal         0x80035900
    // 0x80035A44: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80035900(rdram, ctx);
        goto after_0;
    // 0x80035A44: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_0:
    // 0x80035A48: b           L_80035A60
    // 0x80035A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035A60;
    // 0x80035A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035A50:
    // 0x80035A50: jal         0x800358B8
    // 0x80035A54: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    func_800358B8(rdram, ctx);
        goto after_1;
    // 0x80035A54: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80035A58: b           L_80035A60
    // 0x80035A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80035A60;
    // 0x80035A5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80035A60:
    // 0x80035A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035A64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80035A68: jr          $ra
    // 0x80035A6C: nop

    return;
    // 0x80035A6C: nop

;}
RECOMP_FUNC void func_806D15D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D15D0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806D15D4: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x806D15D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D15DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D15E0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806D15E4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x806D15E8: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806D15EC: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x806D15F0: jal         0x80067D5C
    // 0x806D15F4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x806D15F4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    after_0:
    // 0x806D15F8: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x806D15FC: jal         0x80067818
    // 0x806D1600: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806D1600: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806D1604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D1608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D160C: jr          $ra
    // 0x806D1610: nop

    return;
    // 0x806D1610: nop

;}
RECOMP_FUNC void func_805CC370(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805CC374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CC378: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CC37C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x805CC380: bnel        $t6, $zero, L_805CC3A8
    if (ctx->r14 != 0) {
        // 0x805CC384: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_805CC3A8;
    }
    goto skip_0;
    // 0x805CC384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x805CC388: jal         0x80045A34
    // 0x805CC38C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805CC38C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805CC390: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805CC394: bne         $v0, $zero, L_805CC3A4
    if (ctx->r2 != 0) {
        // 0x805CC398: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_805CC3A4;
    }
    // 0x805CC398: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x805CC39C: b           L_805CC3A8
    // 0x805CC3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805CC3A8;
    // 0x805CC3A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805CC3A4:
    // 0x805CC3A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805CC3A8:
    // 0x805CC3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CC3AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805CC3B0: jr          $ra
    // 0x805CC3B4: nop

    return;
    // 0x805CC3B4: nop

;}
RECOMP_FUNC void func_806AE4CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AE4CC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x806AE4D0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x806AE4D4: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x806AE4D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806AE4DC: nop

    // 0x806AE4E0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x806AE4E4: nop

    // 0x806AE4E8: bc1fl       L_806AE518
    if (!c1cs) {
        // 0x806AE4EC: lwc1        $f2, 0x0($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806AE518;
    }
    goto skip_0;
    // 0x806AE4EC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x806AE4F0: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806AE4F4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806AE4F8: nop

    // 0x806AE4FC: bc1f        L_806AE534
    if (!c1cs) {
        // 0x806AE500: nop
    
            goto L_806AE534;
    }
    // 0x806AE500: nop

    // 0x806AE504: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806AE508: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806AE50C: jr          $ra
    // 0x806AE510: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x806AE510: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x806AE514: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_806AE518:
    // 0x806AE518: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806AE51C: nop

    // 0x806AE520: bc1f        L_806AE534
    if (!c1cs) {
        // 0x806AE524: nop
    
            goto L_806AE534;
    }
    // 0x806AE524: nop

    // 0x806AE528: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806AE52C: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x806AE530: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_806AE534:
    // 0x806AE534: jr          $ra
    // 0x806AE538: nop

    return;
    // 0x806AE538: nop

;}
RECOMP_FUNC void func_8005C8E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C8E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C8EC: jal         0x8005C3B4
    // 0x8005C8F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005C3B4(rdram, ctx);
        goto after_0;
    // 0x8005C8F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C8F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C8F8: jal         0x8005D134
    // 0x8005C8FC: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_8005D134(rdram, ctx);
        goto after_1;
    // 0x8005C8FC: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_1:
    // 0x8005C900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C904: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C908: jr          $ra
    // 0x8005C90C: nop

    return;
    // 0x8005C90C: nop

;}
RECOMP_FUNC void func_805749AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805749AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805749B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805749B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805749B8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805749BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805749C0: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x805749C4: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x805749C8: beql        $t7, $zero, L_805749F4
    if (ctx->r15 == 0) {
        // 0x805749CC: lwc1        $f12, 0xC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_805749F4;
    }
    goto skip_0;
    // 0x805749CC: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x805749D0: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x805749D4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x805749D8: beq         $at, $zero, L_805749F0
    if (ctx->r1 == 0) {
        // 0x805749DC: lui         $at, 0x8057
        ctx->r1 = S32(RELOC_HI16(381, 0XEF4) << 16);
            goto L_805749F0;
    }
    // 0x805749DC: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEF4) << 16);
    // 0x805749E0: lwc1        $f6, 0x4D84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEF4));
    // 0x805749E4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805749E8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x805749EC: swc1        $f8, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f8.u32l;
L_805749F0:
    // 0x805749F0: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
L_805749F4:
    // 0x805749F4: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x805749F8: jal         0x80065ABC
    // 0x805749FC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x805749FC: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_0:
    // 0x80574A00: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80574A04: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80574A08: lw          $t9, -0x6C78($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6C78);
    // 0x80574A0C: bnel        $t9, $zero, L_80574A54
    if (ctx->r25 != 0) {
        // 0x80574A10: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80574A54;
    }
    goto skip_1;
    // 0x80574A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80574A14: jal         0x80574650
    // 0x80574A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80574650(rdram, ctx);
        goto after_1;
    // 0x80574A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80574A1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574A20: jal         0x80574A64
    // 0x80574A24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80574A64(rdram, ctx);
        goto after_2;
    // 0x80574A24: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_2:
    // 0x80574A28: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x80574A2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80574A30: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x80574A34: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80574A38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80574A3C: jal         0x8005FD1C
    // 0x80574A40: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    func_8005FD1C(rdram, ctx);
        goto after_3;
    // 0x80574A40: sh          $zero, 0x12($t2)
    MEM_H(0X12, ctx->r10) = 0;
    after_3:
    // 0x80574A44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80574A48: nop

    // 0x80574A4C: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80574A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80574A54:
    // 0x80574A54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80574A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80574A5C: jr          $ra
    // 0x80574A60: nop

    return;
    // 0x80574A60: nop

;}
RECOMP_FUNC void func_8051B688(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051B688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051B68C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051B690: jal         0x8051B630
    // 0x8051B694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8051B630(rdram, ctx);
        goto after_0;
    // 0x8051B694: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8051B698: beq         $v0, $zero, L_8051B6B8
    if (ctx->r2 == 0) {
        // 0x8051B69C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8051B6B8;
    }
    // 0x8051B69C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051B6A0: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(297, 0XF0) << 16);
    // 0x8051B6A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8051B6A8: addiu       $t7, $t7, -0x4BE0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(297, 0XF0));
    // 0x8051B6AC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8051B6B0: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x8051B6B4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
L_8051B6B8:
    // 0x8051B6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051B6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051B6C0: jr          $ra
    // 0x8051B6C4: nop

    return;
    // 0x8051B6C4: nop

;}
RECOMP_FUNC void func_8069DAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069DAC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8069DAC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069DAC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8069DACC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8069DAD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8069DAD4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8069DAD8: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8069DADC: beq         $t9, $zero, L_8069DB08
    if (ctx->r25 == 0) {
        // 0x8069DAE0: nop
    
            goto L_8069DB08;
    }
    // 0x8069DAE0: nop

    // 0x8069DAE4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8069DAE8: jal         0x8069D8CC
    // 0x8069DAEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8069D8CC(rdram, ctx);
        goto after_0;
    // 0x8069DAEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069DAF0: jal         0x8004816C
    // 0x8069DAF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8069DAF4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8069DAF8: jal         0x8069D820
    // 0x8069DAFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8069D820(rdram, ctx);
        goto after_2;
    // 0x8069DAFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8069DB00: b           L_8069DB08
    // 0x8069DB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8069DB08;
    // 0x8069DB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8069DB08:
    // 0x8069DB08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069DB0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8069DB10: jr          $ra
    // 0x8069DB14: nop

    return;
    // 0x8069DB14: nop

;}
RECOMP_FUNC void func_80737B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80737B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80737B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737B70: jal         0x80737A2C
    // 0x80737B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80737A2C(rdram, ctx);
        goto after_0;
    // 0x80737B74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80737B78: jal         0x80737798
    // 0x80737B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80737798(rdram, ctx);
        goto after_1;
    // 0x80737B7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80737B80: jal         0x807378E8
    // 0x80737B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807378E8(rdram, ctx);
        goto after_2;
    // 0x80737B84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80737B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80737B90: jr          $ra
    // 0x80737B94: nop

    return;
    // 0x80737B94: nop

;}
RECOMP_FUNC void func_804EA004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EA004: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804EA008: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804EA00C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804EA010: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x804EA014: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x804EA018: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x804EA01C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x804EA020: jal         0x80047090
    // 0x804EA024: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804EA024: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    after_0:
    // 0x804EA028: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804EA02C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x804EA030: beq         $v0, $at, L_804EA0E8
    if (ctx->r2 == ctx->r1) {
        // 0x804EA034: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_804EA0E8;
    }
    // 0x804EA034: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x804EA038: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x804EA03C: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x804EA040: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(264, 0X910) << 16);
    // 0x804EA044: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x804EA048: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x804EA04C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x804EA050: or          $a1, $t7, $t0
    ctx->r5 = ctx->r15 | ctx->r8;
    // 0x804EA054: addiu       $a0, $a0, -0x5D80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(264, 0X910));
    // 0x804EA058: jal         0x80046804
    // 0x804EA05C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804EA05C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804EA060: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x804EA064: beq         $v0, $zero, L_804EA0E8
    if (ctx->r2 == 0) {
        // 0x804EA068: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804EA0E8;
    }
    // 0x804EA068: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804EA06C: beq         $v1, $zero, L_804EA08C
    if (ctx->r3 == 0) {
        // 0x804EA070: nop
    
            goto L_804EA08C;
    }
    // 0x804EA070: nop

    // 0x804EA074: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x804EA078: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x804EA07C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804EA080: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x804EA084: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x804EA088: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_804EA08C:
    // 0x804EA08C: beql        $s0, $zero, L_804EA0D8
    if (ctx->r16 == 0) {
        // 0x804EA090: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_804EA0D8;
    }
    goto skip_0;
    // 0x804EA090: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x804EA094: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x804EA098: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x804EA09C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x804EA0A0: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
L_804EA0A4:
    // 0x804EA0A4: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x804EA0A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804EA0AC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x804EA0B0: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x804EA0B4: lbu         $t9, -0x3($s0)
    ctx->r25 = MEM_BU(ctx->r16, -0X3);
    // 0x804EA0B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804EA0BC: sb          $t9, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r25;
    // 0x804EA0C0: lbu         $t2, -0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, -0X2);
    // 0x804EA0C4: sb          $t2, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r10;
    // 0x804EA0C8: lbu         $t3, -0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, -0X1);
    // 0x804EA0CC: bne         $a0, $v0, L_804EA0A4
    if (ctx->r4 != ctx->r2) {
        // 0x804EA0D0: sb          $t3, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r11;
            goto L_804EA0A4;
    }
    // 0x804EA0D0: sb          $t3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r11;
    // 0x804EA0D4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_804EA0D8:
    // 0x804EA0D8: jal         0x80044194
    // 0x804EA0DC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804EA0DC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_2:
    // 0x804EA0E0: b           L_804EA0EC
    // 0x804EA0E4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_804EA0EC;
    // 0x804EA0E4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_804EA0E8:
    // 0x804EA0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804EA0EC:
    // 0x804EA0EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804EA0F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804EA0F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804EA0F8: jr          $ra
    // 0x804EA0FC: nop

    return;
    // 0x804EA0FC: nop

;}
RECOMP_FUNC void func_806792AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806792AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806792B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806792B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806792B8: jal         0x80678FD8
    // 0x806792BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80678FD8(rdram, ctx);
        goto after_0;
    // 0x806792BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806792C0: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x806792C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806792C8: bne         $v1, $zero, L_806792E0
    if (ctx->r3 != 0) {
        // 0x806792CC: nop
    
            goto L_806792E0;
    }
    // 0x806792CC: nop

    // 0x806792D0: jal         0x80045A34
    // 0x806792D4: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806792D4: addiu       $a1, $zero, 0x428
    ctx->r5 = ADD32(0, 0X428);
    after_1:
    // 0x806792D8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806792DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_806792E0:
    // 0x806792E0: bne         $v1, $zero, L_806792F4
    if (ctx->r3 != 0) {
        // 0x806792E4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806792F4;
    }
    // 0x806792E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806792E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806792EC: b           L_80679350
    // 0x806792F0: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_80679350;
    // 0x806792F0: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806792F4:
    // 0x806792F4: sh          $zero, 0x424($v1)
    MEM_H(0X424, ctx->r3) = 0;
    // 0x806792F8: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
    // 0x806792FC: jal         0x80678F24
    // 0x80679300: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    func_80678F24(rdram, ctx);
        goto after_2;
    // 0x80679300: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    after_2:
    // 0x80679304: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80679308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067930C: jal         0x80679364
    // 0x80679310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80679364(rdram, ctx);
        goto after_3;
    // 0x80679310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80679314: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80679318: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(538, 0X628) << 16);
    // 0x8067931C: addiu       $t7, $t7, -0x7A68
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(538, 0X628));
    // 0x80679320: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80679324: jal         0x80679028
    // 0x80679328: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    func_80679028(rdram, ctx);
        goto after_4;
    // 0x80679328: sw          $t7, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r15;
    after_4:
    // 0x8067932C: bne         $v0, $zero, L_8067933C
    if (ctx->r2 != 0) {
        // 0x80679330: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8067933C;
    }
    // 0x80679330: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80679334: b           L_80679350
    // 0x80679338: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
        goto L_80679350;
    // 0x80679338: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
L_8067933C:
    // 0x8067933C: jal         0x8067926C
    // 0x80679340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067926C(rdram, ctx);
        goto after_5;
    // 0x80679340: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80679344: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(538, 0X1314) << 16);
    // 0x80679348: addiu       $t0, $t0, -0x6D7C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(538, 0X1314));
    // 0x8067934C: sw          $t0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r8;
L_80679350:
    // 0x80679350: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80679354: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80679358: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8067935C: jr          $ra
    // 0x80679360: nop

    return;
    // 0x80679360: nop

;}
RECOMP_FUNC void func_80455A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455A68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455A70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455A74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455A78: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80455A7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455A80: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455A84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455A88: jal         0x8044EFA0
    // 0x80455A8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455A8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455A90: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455A94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455A98: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80455A9C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455AA0: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455AA4: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D54) << 16);
    // 0x80455AA8: lw          $t9, -0x7ECC($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D54));
    // 0x80455AAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455AB0: jalr        $t9
    // 0x80455AB4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455AB4: nop

    after_1:
    // 0x80455AB8: jal         0x804559B4
    // 0x80455ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455ABC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455AC0: jal         0x80445CBC
    // 0x80455AC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455AC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80455AC8: jal         0x80445CC4
    // 0x80455ACC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455ACC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455AD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455AD8: jr          $ra
    // 0x80455ADC: nop

    return;
    // 0x80455ADC: nop

;}
RECOMP_FUNC void func_80040804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004080C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x80040810: addiu       $at, $zero, 0x4005
    ctx->r1 = ADD32(0, 0X4005);
    // 0x80040814: beq         $v0, $at, L_80040834
    if (ctx->r2 == ctx->r1) {
        // 0x80040818: addiu       $at, $zero, 0x406C
        ctx->r1 = ADD32(0, 0X406C);
            goto L_80040834;
    }
    // 0x80040818: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8004081C: beq         $v0, $at, L_80040844
    if (ctx->r2 == ctx->r1) {
        // 0x80040820: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_80040844;
    }
    // 0x80040820: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x80040824: beq         $v0, $at, L_80040844
    if (ctx->r2 == ctx->r1) {
        // 0x80040828: nop
    
            goto L_80040844;
    }
    // 0x80040828: nop

    // 0x8004082C: b           L_80040854
    // 0x80040830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80040854;
    // 0x80040830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040834:
    // 0x80040834: jal         0x800405C8
    // 0x80040838: nop

    func_800405C8(rdram, ctx);
        goto after_0;
    // 0x80040838: nop

    after_0:
    // 0x8004083C: b           L_80040854
    // 0x80040840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80040854;
    // 0x80040840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040844:
    // 0x80040844: jal         0x800406E0
    // 0x80040848: nop

    func_800406E0(rdram, ctx);
        goto after_1;
    // 0x80040848: nop

    after_1:
    // 0x8004084C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80040850: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80040854:
    // 0x80040854: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040858: jr          $ra
    // 0x8004085C: nop

    return;
    // 0x8004085C: nop

;}
RECOMP_FUNC void func_800676F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800676F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800676FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067700: jal         0x80067530
    // 0x80067704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80067530(rdram, ctx);
        goto after_0;
    // 0x80067704: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80067708: jal         0x80067508
    // 0x8006770C: nop

    func_80067508(rdram, ctx);
        goto after_1;
    // 0x8006770C: nop

    after_1:
    // 0x80067710: jal         0x8007DF74
    // 0x80067714: nop

    DmaMgr_Init(rdram, ctx);
        goto after_2;
    // 0x80067714: nop

    after_2:
    // 0x80067718: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8006771C: addiu       $t7, $t7, 0xDF4
    ctx->r15 = ADD32(ctx->r15, 0XDF4);
    // 0x80067720: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067724: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067728: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x8006772C: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x80067730: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80067734: addiu       $a2, $a2, 0x1D8
    ctx->r6 = ADD32(ctx->r6, 0X1D8);
    // 0x80067738: addiu       $a1, $a1, -0x328
    ctx->r5 = ADD32(ctx->r5, -0X328);
    // 0x8006773C: addiu       $a0, $a0, 0x1D8
    ctx->r4 = ADD32(ctx->r4, 0X1D8);
    // 0x80067740: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80067744: jal         0x80081910
    // 0x80067748: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_3;
    // 0x80067748: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8006774C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067750: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80067754: addiu       $a1, $a1, 0x1D8
    ctx->r5 = ADD32(ctx->r5, 0X1D8);
    // 0x80067758: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    // 0x8006775C: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80067760: jal         0x800755E0
    // 0x80067764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800755E0(rdram, ctx);
        goto after_4;
    // 0x80067764: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80067768: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006776C: jal         0x80071B0C
    // 0x80067770: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    func_80071B0C(rdram, ctx);
        goto after_5;
    // 0x80067770: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    after_5:
    // 0x80067774: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80067778: addiu       $a1, $a1, 0x6E34
    ctx->r5 = ADD32(ctx->r5, 0X6E34);
    // 0x8006777C: jal         0x80071740
    // 0x80067780: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80071740(rdram, ctx);
        goto after_6;
    // 0x80067780: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x80067784: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80067788: jal         0x800729DC
    // 0x8006778C: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    func_800729DC(rdram, ctx);
        goto after_7;
    // 0x8006778C: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    after_7:
    // 0x80067790: jal         0x800715E0
    // 0x80067794: nop

    func_800715E0(rdram, ctx);
        goto after_8;
    // 0x80067794: nop

    after_8:
    // 0x80067798: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006779C: jal         0x80076AA0
    // 0x800677A0: addiu       $a0, $a0, 0xE0
    ctx->r4 = ADD32(ctx->r4, 0XE0);
    func_80076AA0(rdram, ctx);
        goto after_9;
    // 0x800677A0: addiu       $a0, $a0, 0xE0
    ctx->r4 = ADD32(ctx->r4, 0XE0);
    after_9:
    // 0x800677A4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x800677A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800677AC: addiu       $t8, $t8, -0x54D8
    ctx->r24 = ADD32(ctx->r24, -0X54D8);
    // 0x800677B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800677B4: sw          $t8, -0x7AEC($at)
    MEM_W(-0X7AEC, ctx->r1) = ctx->r24;
    // 0x800677B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800677BC: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x800677C0: sw          $t9, -0x7AE8($at)
    MEM_W(-0X7AE8, ctx->r1) = ctx->r25;
    // 0x800677C4: jr          $ra
    // 0x800677C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800677C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_805657B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805657B0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x805657B4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x805657B8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x805657BC: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x805657C0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x805657C4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x805657C8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x805657CC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x805657D0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x805657D4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x805657D8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x805657DC: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x805657E0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805657E4: mtc1        $a1, $f24
    ctx->f24.u32l = ctx->r5;
    // 0x805657E8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805657EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805657F0: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x805657F4: lw          $s7, 0x1F4($a0)
    ctx->r23 = MEM_W(ctx->r4, 0X1F4);
    // 0x805657F8: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x805657FC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80565800: lwc1        $f16, 0x504($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X504);
    // 0x80565804: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80565808: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8056580C: mul.s       $f16, $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80565810: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80565814: addiu       $v1, $s7, 0x174
    ctx->r3 = ADD32(ctx->r23, 0X174);
    // 0x80565818: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8056581C: mul.s       $f26, $f18, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80565820: or          $fp, $s7, $zero
    ctx->r30 = ctx->r23 | 0;
    // 0x80565824: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80565828: mul.s       $f24, $f16, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f24.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x8056582C: addiu       $s6, $zero, 0x3E
    ctx->r22 = ADD32(0, 0X3E);
L_80565830:
    // 0x80565830: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80565834: or          $s0, $fp, $zero
    ctx->r16 = ctx->r30 | 0;
    // 0x80565838: mov.s       $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    ctx->f20.fl = ctx->f26.fl;
    // 0x8056583C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80565840: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80565844: or          $s5, $s7, $zero
    ctx->r21 = ctx->r23 | 0;
    // 0x80565848: or          $s2, $s7, $zero
    ctx->r18 = ctx->r23 | 0;
L_8056584C:
    // 0x8056584C: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x80565850: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80565854: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x80565858: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8056585C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80565860: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x80565864: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80565868: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8056586C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80565870: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80565874: sh          $v0, -0x4($s1)
    MEM_H(-0X4, ctx->r17) = ctx->r2;
    // 0x80565878: jal         0x805640E0
    // 0x8056587C: sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    func_805640E0(rdram, ctx);
        goto after_0;
    // 0x8056587C: sh          $v0, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = ctx->r2;
    after_0:
    // 0x80565880: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80565884: swc1        $f0, 0x3E8($s5)
    MEM_W(0X3E8, ctx->r21) = ctx->f0.u32l;
    // 0x80565888: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8056588C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80565890: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80565894: swc1        $f22, 0x2E8($s2)
    MEM_W(0X2E8, ctx->r18) = ctx->f22.u32l;
    // 0x80565898: bne         $s4, $s6, L_8056584C
    if (ctx->r20 != ctx->r22) {
        // 0x8056589C: swc1        $f22, 0x2EC($s2)
        MEM_W(0X2EC, ctx->r18) = ctx->f22.u32l;
            goto L_8056584C;
    }
    // 0x8056589C: swc1        $f22, 0x2EC($s2)
    MEM_W(0X2EC, ctx->r18) = ctx->f22.u32l;
    // 0x805658A0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x805658A4: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x805658A8: addiu       $at, $zero, 0x174
    ctx->r1 = ADD32(0, 0X174);
    // 0x805658AC: addiu       $t9, $t8, 0x7C
    ctx->r25 = ADD32(ctx->r24, 0X7C);
    // 0x805658B0: addiu       $t1, $t0, 0x7C
    ctx->r9 = ADD32(ctx->r8, 0X7C);
    // 0x805658B4: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x805658B8: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x805658BC: bne         $t9, $at, L_80565830
    if (ctx->r25 != ctx->r1) {
        // 0x805658C0: addiu       $fp, $fp, 0x7C
        ctx->r30 = ADD32(ctx->r30, 0X7C);
            goto L_80565830;
    }
    // 0x805658C0: addiu       $fp, $fp, 0x7C
    ctx->r30 = ADD32(ctx->r30, 0X7C);
    // 0x805658C4: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x805658C8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x805658CC: swc1        $f6, 0x508($s7)
    MEM_W(0X508, ctx->r23) = ctx->f6.u32l;
    // 0x805658D0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x805658D4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x805658D8: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x805658DC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x805658E0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x805658E4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x805658E8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x805658EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x805658F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x805658F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x805658F8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805658FC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80565900: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80565904: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80565908: jr          $ra
    // 0x8056590C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8056590C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void func_800623C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800623C8: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800623CC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800623D0: lui         $s4, 0x800F
    ctx->r20 = S32(0X800F << 16);
    // 0x800623D4: addiu       $s4, $s4, 0x7EA0
    ctx->r20 = ADD32(ctx->r20, 0X7EA0);
    // 0x800623D8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800623DC: lw          $s3, 0xA00($s4)
    ctx->r19 = MEM_W(ctx->r20, 0XA00);
    // 0x800623E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800623E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800623E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800623EC: sll         $s2, $a1, 16
    ctx->r18 = S32(ctx->r5 << 16);
    // 0x800623F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800623F4: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800623F8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800623FC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80062400: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80062404: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80062408: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x8006240C: jal         0x8006237C
    // 0x80062410: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_8006237C(rdram, ctx);
        goto after_0;
    // 0x80062410: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80062414: beq         $s2, $zero, L_800624EC
    if (ctx->r18 == 0) {
        // 0x80062418: addiu       $s6, $sp, 0x50
        ctx->r22 = ADD32(ctx->r29, 0X50);
            goto L_800624EC;
    }
    // 0x80062418: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8006241C: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
L_80062420:
    // 0x80062420: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80062424: beq         $v1, $zero, L_800624E4
    if (ctx->r3 == 0) {
        // 0x80062428: nop
    
            goto L_800624E4;
    }
    // 0x80062428: nop

    // 0x8006242C: lbu         $t6, 0x5($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X5);
    // 0x80062430: beql        $t6, $zero, L_80062448
    if (ctx->r14 == 0) {
        // 0x80062434: lwc1        $f20, 0x50($v1)
        ctx->f20.u32l = MEM_W(ctx->r3, 0X50);
            goto L_80062448;
    }
    goto skip_0;
    // 0x80062434: lwc1        $f20, 0x50($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X50);
    skip_0:
    // 0x80062438: lbu         $t7, 0x10($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X10);
    // 0x8006243C: beql        $t7, $zero, L_800624DC
    if (ctx->r15 == 0) {
        // 0x80062440: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_800624DC;
    }
    goto skip_1;
    // 0x80062440: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    skip_1:
    // 0x80062444: lwc1        $f20, 0x50($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X50);
L_80062448:
    // 0x80062448: sw          $v1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r3;
    // 0x8006244C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80062450: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80062454: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80062458: lw          $v0, 0x174($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X174);
    // 0x8006245C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80062460: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80062464: lh          $t0, 0x184($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X184);
    // 0x80062468: subu        $t1, $s5, $t0
    ctx->r9 = SUB32(ctx->r21, ctx->r8);
    // 0x8006246C: sw          $t1, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r9;
    // 0x80062470: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80062474: lw          $t3, 0x64($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X64);
    // 0x80062478: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8006247C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80062480: lw          $t5, 0x68($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X68);
    // 0x80062484: jal         0x80066DE4
    // 0x80062488: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80062488: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    after_1:
    // 0x8006248C: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80062490: jal         0x80066E88
    // 0x80062494: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80062494: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80062498: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8006249C: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x800624A0: beql        $v0, $zero, L_800624BC
    if (ctx->r2 == 0) {
        // 0x800624A4: lwc1        $f4, 0xC4($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_800624BC;
    }
    goto skip_2;
    // 0x800624A4: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    skip_2:
    // 0x800624A8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800624AC:
    // 0x800624AC: lw          $v0, 0x180($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X180);
    // 0x800624B0: bnel        $v0, $zero, L_800624AC
    if (ctx->r2 != 0) {
        // 0x800624B4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800624AC;
    }
    goto skip_3;
    // 0x800624B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    skip_3:
    // 0x800624B8: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
L_800624BC:
    // 0x800624BC: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800624C0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800624C4: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x800624C8: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800624CC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800624D0: jalr        $t9
    // 0x800624D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800624D4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x800624D8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_800624DC:
    // 0x800624DC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800624E0: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
L_800624E4:
    // 0x800624E4: bne         $s2, $zero, L_80062420
    if (ctx->r18 != 0) {
        // 0x800624E8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80062420;
    }
    // 0x800624E8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800624EC:
    // 0x800624EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800624F0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800624F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800624F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800624FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80062500: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80062504: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80062508: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8006250C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80062510: jr          $ra
    // 0x80062514: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x80062514: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_80057560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057560: lw          $t6, 0x1CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1CC);
    // 0x80057564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80057568: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005756C: blez        $t6, L_800575AC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80057570: addiu       $a3, $zero, 0xFF
        ctx->r7 = ADD32(0, 0XFF);
            goto L_800575AC;
    }
    // 0x80057570: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80057574: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x80057578: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8005757C: lw          $t7, 0x13B8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X13B8);
L_80057580:
    // 0x80057580: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80057584: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80057588: lbu         $v0, 0x5D($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X5D);
    // 0x8005758C: sb          $a3, 0x1CF($a1)
    MEM_B(0X1CF, ctx->r5) = ctx->r7;
    // 0x80057590: sb          $v0, 0x1CE($a1)
    MEM_B(0X1CE, ctx->r5) = ctx->r2;
    // 0x80057594: sb          $v0, 0x1CD($a1)
    MEM_B(0X1CD, ctx->r5) = ctx->r2;
    // 0x80057598: sb          $v0, 0x1CC($a1)
    MEM_B(0X1CC, ctx->r5) = ctx->r2;
    // 0x8005759C: lw          $t8, 0x1CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1CC);
    // 0x800575A0: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800575A4: bnel        $at, $zero, L_80057580
    if (ctx->r1 != 0) {
        // 0x800575A8: lw          $t7, 0x13B8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X13B8);
            goto L_80057580;
    }
    goto skip_0;
    // 0x800575A8: lw          $t7, 0x13B8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X13B8);
    skip_0:
L_800575AC:
    // 0x800575AC: jr          $ra
    // 0x800575B0: nop

    return;
    // 0x800575B0: nop

;}
RECOMP_FUNC void func_80474E80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474E80: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474E84: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474E88: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474E8C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474E90: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474E94: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474E98: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474E9C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474EA0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474EA4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474EA8: jr          $ra
    // 0x80474EAC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474EAC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8006DF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DF14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006DF18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006DF1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006DF20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006DF24: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006DF28: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006DF2C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006DF30: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    // 0x8006DF34: jal         0x80065728
    // 0x8006DF38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8006DF38: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006DF3C: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x8006DF40: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8006DF44: addiu       $s1, $s1, 0x1188
    ctx->r17 = ADD32(ctx->r17, 0X1188);
    // 0x8006DF48: addiu       $t6, $t6, 0x78A0
    ctx->r14 = ADD32(ctx->r14, 0X78A0);
    // 0x8006DF4C: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x8006DF50: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006DF54: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8006DF58: jal         0x80065728
    // 0x8006DF5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8006DF5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8006DF60: addiu       $s2, $s0, 0x24
    ctx->r18 = ADD32(ctx->r16, 0X24);
    // 0x8006DF64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006DF68: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8006DF6C: jal         0x80058110
    // 0x8006DF70: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_80058110(rdram, ctx);
        goto after_2;
    // 0x8006DF70: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x8006DF74: lui         $s1, 0x8010
    ctx->r17 = S32(0X8010 << 16);
    // 0x8006DF78: addiu       $s1, $s1, 0x11B8
    ctx->r17 = ADD32(ctx->r17, 0X11B8);
    // 0x8006DF7C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006DF80: addiu       $s3, $zero, 0xB
    ctx->r19 = ADD32(0, 0XB);
L_8006DF84:
    // 0x8006DF84: jal         0x8006D508
    // 0x8006DF88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8006D508(rdram, ctx);
        goto after_3;
    // 0x8006DF88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8006DF8C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8006DF90: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8006DF94: jal         0x80057B28
    // 0x8006DF98: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80057B28(rdram, ctx);
        goto after_4;
    // 0x8006DF98: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_4:
    // 0x8006DF9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006DFA0: bne         $s0, $s3, L_8006DF84
    if (ctx->r16 != ctx->r19) {
        // 0x8006DFA4: addiu       $s1, $s1, 0xA94
        ctx->r17 = ADD32(ctx->r17, 0XA94);
            goto L_8006DF84;
    }
    // 0x8006DFA4: addiu       $s1, $s1, 0xA94
    ctx->r17 = ADD32(ctx->r17, 0XA94);
    // 0x8006DFA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006DFAC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006DFB0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006DFB4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DFB8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006DFBC: jr          $ra
    // 0x8006DFC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006DFC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80059398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059398: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005939C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800593A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800593A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800593A8: jal         0x80081C64
    // 0x800593AC: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x800593AC: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x800593B0: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800593B4: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x800593B8: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x800593BC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800593C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800593C4: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800593C8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800593CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800593D0: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800593D4: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800593D8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800593DC: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x800593E0: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800593E4: lwc1        $f4, 0xB98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB98);
    // 0x800593E8: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800593EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800593F0: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800593F4: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800593F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800593FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059400: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80059404: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80059408: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8005940C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80059410: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059414: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80059418: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005941C: lwc1        $f8, 0x30($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X30);
    // 0x80059420: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80059424: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80059428: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005942C: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80059430: nop

    // 0x80059434: bc1f        L_80059440
    if (!c1cs) {
        // 0x80059438: nop
    
            goto L_80059440;
    }
    // 0x80059438: nop

    // 0x8005943C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059440:
    // 0x80059440: jr          $ra
    // 0x80059444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80792548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792548: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079254C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80792550: jal         0x80790714
    // 0x80792554: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80790714(rdram, ctx);
        goto after_0;
    // 0x80792554: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80792558: beq         $v0, $zero, L_807925A0
    if (ctx->r2 == 0) {
        // 0x8079255C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_807925A0;
    }
    // 0x8079255C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80792560: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80792564: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80792568: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8079256C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792570: jal         0x8079393C
    // 0x80792574: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80792574: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_1:
    // 0x80792578: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x8079257C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80792580: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80792584: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80792588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079258C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80792590: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80792594: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80792598: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x8079259C: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
L_807925A0:
    // 0x807925A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807925A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807925A8: jr          $ra
    // 0x807925AC: nop

    return;
    // 0x807925AC: nop

;}
RECOMP_FUNC void func_8007711C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007711C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80077120: bne         $a1, $at, L_80077264
    if (ctx->r5 != ctx->r1) {
        // 0x80077124: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80077264;
    }
    // 0x80077124: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077128: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x8007712C: addiu       $v1, $v1, -0x7A18
    ctx->r3 = ADD32(ctx->r3, -0X7A18);
    // 0x80077130: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80077134: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077138: beql        $a3, $t6, L_80077268
    if (ctx->r7 == ctx->r14) {
        // 0x8007713C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_80077268;
    }
    goto skip_0;
    // 0x8007713C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    skip_0:
    // 0x80077140: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x80077144: bne         $a2, $zero, L_800771DC
    if (ctx->r6 != 0) {
        // 0x80077148: sw          $zero, -0x7A1C($at)
        MEM_W(-0X7A1C, ctx->r1) = 0;
            goto L_800771DC;
    }
    // 0x80077148: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
    // 0x8007714C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077150: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80077154: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077158: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x8007715C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077160: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80077164: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x80077168: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007716C: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80077170: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077174: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80077178: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007717C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80077180: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80077184: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80077188: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007718C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077190: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80077194: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80077198: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8007719C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800771A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800771A4: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800771A8: lui         $t5, 0x703
    ctx->r13 = S32(0X703 << 16);
    // 0x800771AC: ori         $t5, $t5, 0xC000
    ctx->r13 = ctx->r13 | 0XC000;
    // 0x800771B0: lui         $t4, 0xF000
    ctx->r12 = S32(0XF000 << 16);
    // 0x800771B4: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800771B8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800771BC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800771C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800771C4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800771C8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800771CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800771D0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800771D4: b           L_80077268
    // 0x800771D8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80077268;
    // 0x800771D8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_800771DC:
    // 0x800771DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800771E0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x800771E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800771E8: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800771EC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800771F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800771F4: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800771F8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800771FC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80077200: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077204: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80077208: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007720C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x80077210: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x80077214: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80077218: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007721C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077220: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80077224: lui         $t3, 0xE600
    ctx->r11 = S32(0XE600 << 16);
    // 0x80077228: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8007722C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80077230: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077234: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80077238: lui         $t5, 0x73F
    ctx->r13 = S32(0X73F << 16);
    // 0x8007723C: ori         $t5, $t5, 0xC000
    ctx->r13 = ctx->r13 | 0XC000;
    // 0x80077240: lui         $t4, 0xF000
    ctx->r12 = S32(0XF000 << 16);
    // 0x80077244: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80077248: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x8007724C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077250: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077254: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80077258: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007725C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077260: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80077264:
    // 0x80077264: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80077268:
    // 0x80077268: jr          $ra
    // 0x8007726C: nop

    return;
    // 0x8007726C: nop

;}
RECOMP_FUNC void func_8044EDC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044EDC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044EDC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044EDCC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044EDD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044EDD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8044EDD8: lw          $v1, 0x1F4($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X1F4);
    // 0x8044EDDC: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8044EDE0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8044EDE4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8044EDE8: lw          $t7, 0x6A20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A20);
    // 0x8044EDEC: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x8044EDF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8044EDF4: slti        $at, $t7, -0x1
    ctx->r1 = SIGNED(ctx->r15) < -0X1 ? 1 : 0;
    // 0x8044EDF8: bne         $at, $zero, L_8044EE48
    if (ctx->r1 != 0) {
        // 0x8044EDFC: addu        $t8, $t8, $v1
        ctx->r24 = ADD32(ctx->r24, ctx->r3);
            goto L_8044EE48;
    }
    // 0x8044EDFC: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8044EE00: lw          $t8, 0x6A2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A2C);
    // 0x8044EE04: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044EE08: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8044EE0C: bne         $t8, $at, L_8044EE48
    if (ctx->r24 != ctx->r1) {
        // 0x8044EE10: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_8044EE48;
    }
    // 0x8044EE10: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8044EE14: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8044EE18: lw          $t0, 0x6A20($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6A20);
    // 0x8044EE1C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8044EE20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8044EE24: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8044EE28: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8044EE2C: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x8044EE30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8044EE34: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8044EE38: jalr        $t9
    // 0x8044EE3C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8044EE3C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    after_0:
    // 0x8044EE40: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044EE44: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8044EE48:
    // 0x8044EE48: beq         $a3, $zero, L_8044EE94
    if (ctx->r7 == 0) {
        // 0x8044EE4C: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8044EE94;
    }
    // 0x8044EE4C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044EE50: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044EE54: lw          $v0, 0x6A24($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A24);
    // 0x8044EE58: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8044EE5C: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x8044EE60: beq         $at, $zero, L_8044EE94
    if (ctx->r1 == 0) {
        // 0x8044EE64: nop
    
            goto L_8044EE94;
    }
    // 0x8044EE64: nop

    // 0x8044EE68: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8044EE6C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x8044EE70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8044EE74: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8044EE78: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x8044EE7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8044EE80: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8044EE84: jalr        $t9
    // 0x8044EE88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8044EE88: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8044EE8C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044EE90: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8044EE94:
    // 0x8044EE94: beq         $a3, $zero, L_8044EEE8
    if (ctx->r7 == 0) {
        // 0x8044EE98: lui         $v0, 0x1
        ctx->r2 = S32(0X1 << 16);
            goto L_8044EEE8;
    }
    // 0x8044EE98: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x8044EE9C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8044EEA0: lw          $v0, 0x6A20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A20);
    // 0x8044EEA4: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x8044EEA8: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8044EEAC: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8044EEB0: bnel        $at, $zero, L_8044EEEC
    if (ctx->r1 != 0) {
        // 0x8044EEB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044EEEC;
    }
    goto skip_0;
    // 0x8044EEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044EEB8: lw          $t7, 0x6A2C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A2C);
    // 0x8044EEBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8044EEC0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8044EEC4: beq         $t7, $at, L_8044EEE8
    if (ctx->r15 == ctx->r1) {
        // 0x8044EEC8: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8044EEE8;
    }
    // 0x8044EEC8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8044EECC: addu        $t0, $t8, $t6
    ctx->r8 = ADD32(ctx->r24, ctx->r14);
    // 0x8044EED0: lw          $t9, 0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4);
    // 0x8044EED4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8044EED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8044EEDC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8044EEE0: jalr        $t9
    // 0x8044EEE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8044EEE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
L_8044EEE8:
    // 0x8044EEE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044EEEC:
    // 0x8044EEEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044EEF0: jr          $ra
    // 0x8044EEF4: nop

    return;
    // 0x8044EEF4: nop

;}
RECOMP_FUNC void func_8006EC10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EC10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EC14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EC18: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8006EC1C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8006EC20: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8006EC24: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006EC28: jal         0x8005FDC4
    // 0x8006EC2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8006EC2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006EC30: jal         0x8006EB90
    // 0x8006EC34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8006EB90(rdram, ctx);
        goto after_1;
    // 0x8006EC34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8006EC38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006EC3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EC40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8006EC44: jal         0x8006F070
    // 0x8006EC48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_2;
    // 0x8006EC48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8006EC4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EC50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EC54: jr          $ra
    // 0x8006EC58: nop

    return;
    // 0x8006EC58: nop

;}
RECOMP_FUNC void func_8001D808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D808: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x8001D80C: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8001D810: beq         $a1, $v0, L_8001D838
    if (ctx->r5 == ctx->r2) {
        // 0x8001D814: nop
    
            goto L_8001D838;
    }
    // 0x8001D814: nop

    // 0x8001D818: beq         $v0, $zero, L_8001D830
    if (ctx->r2 == 0) {
        // 0x8001D81C: lwc1        $f0, 0x120($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0X120);
            goto L_8001D830;
    }
    // 0x8001D81C: lwc1        $f0, 0x120($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X120);
    // 0x8001D820: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8001D824: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001D828: jr          $ra
    // 0x8001D82C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001D82C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001D830:
    // 0x8001D830: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8001D834: sub.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f6.fl;
L_8001D838:
    // 0x8001D838: jr          $ra
    // 0x8001D83C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8001D83C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void func_804A2534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A2534: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804A2538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A253C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A2540: jal         0x804A2910
    // 0x804A2544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A2544: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804A2548: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x804A254C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804A2550: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x804A2554: jal         0x80048F84
    // 0x804A2558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804A2558: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804A255C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804A2560: jal         0x80048F84
    // 0x804A2564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x804A2564: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x804A2568: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804A256C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A2570: lh          $t6, 0x13C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X13C);
    // 0x804A2574: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804A2578: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804A257C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2580: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804A2584: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x804A2588: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x804A258C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x804A2590: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x804A2594: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804A2598: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x804A259C: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x804A25A0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804A25A4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804A25A8: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x804A25AC: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804A25B0: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x804A25B4: jal         0x80047534
    // 0x804A25B8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    func_80047534(rdram, ctx);
        goto after_3;
    // 0x804A25B8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x804A25BC: beq         $v0, $zero, L_804A25CC
    if (ctx->r2 == 0) {
        // 0x804A25C0: lui         $t7, 0x804A
        ctx->r15 = S32(RELOC_HI16(173, 0X22D4) << 16);
            goto L_804A25CC;
    }
    // 0x804A25C0: lui         $t7, 0x804A
    ctx->r15 = S32(RELOC_HI16(173, 0X22D4) << 16);
    // 0x804A25C4: addiu       $t7, $t7, 0x2714
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(173, 0X22D4));
    // 0x804A25C8: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
L_804A25CC:
    // 0x804A25CC: jal         0x804A2714
    // 0x804A25D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A2714(rdram, ctx);
        goto after_4;
    // 0x804A25D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804A25D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A25D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A25DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804A25E0: jr          $ra
    // 0x804A25E4: nop

    return;
    // 0x804A25E4: nop

;}
RECOMP_FUNC void func_8044C778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044C778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044C77C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044C780: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8044C784: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8044C788: jal         0x80066E88
    // 0x8044C78C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8044C78C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044C790: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8044C794: lwc1        $f12, 0x0($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8044C798: jal         0x80066DE4
    // 0x8044C79C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8044C79C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8044C7A0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8044C7A4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8044C7A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044C7AC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8044C7B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8044C7B4: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x8044C7B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C7BC: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x8044C7C0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C7C4: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8044C7C8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8044C7CC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8044C7D0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8044C7D4: swc1        $f14, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f14.u32l;
    // 0x8044C7D8: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8044C7DC: swc1        $f2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f2.u32l;
    // 0x8044C7E0: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x8044C7E4: swc1        $f14, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f14.u32l;
    // 0x8044C7E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044C7EC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8044C7F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8044C7F4: jr          $ra
    // 0x8044C7F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8044C7F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001A568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A568: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A56C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A570: bne         $a0, $zero, L_8001A580
    if (ctx->r4 != 0) {
        // 0x8001A574: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8001A580;
    }
    // 0x8001A574: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001A578: b           L_8001A594
    // 0x8001A57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001A594;
    // 0x8001A57C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A580:
    // 0x8001A580: jal         0x8001A5C4
    // 0x8001A584: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    func_8001A5C4(rdram, ctx);
        goto after_0;
    // 0x8001A584: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x8001A588: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x8001A58C: jal         0x8001A5A4
    // 0x8001A590: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8001A5A4(rdram, ctx);
        goto after_1;
    // 0x8001A590: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
L_8001A594:
    // 0x8001A594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A59C: jr          $ra
    // 0x8001A5A0: nop

    return;
    // 0x8001A5A0: nop

;}
RECOMP_FUNC void func_8042CE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042CE5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042CE60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042CE64: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8042CE68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8042CE6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042CE70: lw          $s2, 0x0($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X0);
    // 0x8042CE74: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x8042CE78: lw          $s0, 0x4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X4);
    // 0x8042CE7C: jal         0x80064E84
    // 0x8042CE80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8042CE80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x8042CE84: jal         0x80064E84
    // 0x8042CE88: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8042CE88: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x8042CE8C: jal         0x80064E84
    // 0x8042CE90: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_80064E84(rdram, ctx);
        goto after_2;
    // 0x8042CE90: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x8042CE94: jal         0x80064E84
    // 0x8042CE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x8042CE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042CE9C: jal         0x80064E84
    // 0x8042CEA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_80064E84(rdram, ctx);
        goto after_4;
    // 0x8042CEA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8042CEA4: jal         0x80064E84
    // 0x8042CEA8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    func_80064E84(rdram, ctx);
        goto after_5;
    // 0x8042CEA8: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    after_5:
    // 0x8042CEAC: jal         0x80064E84
    // 0x8042CEB0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    func_80064E84(rdram, ctx);
        goto after_6;
    // 0x8042CEB0: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    after_6:
    // 0x8042CEB4: jal         0x80064E84
    // 0x8042CEB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80064E84(rdram, ctx);
        goto after_7;
    // 0x8042CEB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8042CEBC: lw          $t6, 0x34($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X34);
    // 0x8042CEC0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8042CEC4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x8042CEC8: blez        $t6, L_8042CEF8
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8042CECC: nop
    
            goto L_8042CEF8;
    }
    // 0x8042CECC: nop

L_8042CED0:
    // 0x8042CED0: jal         0x80064E84
    // 0x8042CED4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    func_80064E84(rdram, ctx);
        goto after_8;
    // 0x8042CED4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_8:
    // 0x8042CED8: jal         0x80064E84
    // 0x8042CEDC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    func_80064E84(rdram, ctx);
        goto after_9;
    // 0x8042CEDC: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_9:
    // 0x8042CEE0: lw          $t7, 0x34($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X34);
    // 0x8042CEE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8042CEE8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8042CEEC: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8042CEF0: bne         $at, $zero, L_8042CED0
    if (ctx->r1 != 0) {
        // 0x8042CEF4: nop
    
            goto L_8042CED0;
    }
    // 0x8042CEF4: nop

L_8042CEF8:
    // 0x8042CEF8: jal         0x80064E84
    // 0x8042CEFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80064E84(rdram, ctx);
        goto after_10;
    // 0x8042CEFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8042CF00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8042CF04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042CF08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8042CF0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8042CF10: jr          $ra
    // 0x8042CF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8042CF14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80566E48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566E48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80566E4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566E50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80566E54: jal         0x80045A34
    // 0x80566E58: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80566E58: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
    // 0x80566E5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80566E60: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(375, 0XBE0) << 16);
    // 0x80566E64: bne         $v0, $zero, L_80566E7C
    if (ctx->r2 != 0) {
        // 0x80566E68: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80566E7C;
    }
    // 0x80566E68: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80566E6C: jal         0x800445A4
    // 0x80566E70: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80566E70: nop

    after_1:
    // 0x80566E74: b           L_80566EB4
    // 0x80566E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80566EB4;
    // 0x80566E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566E7C:
    // 0x80566E7C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80566E80: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80566E84: addiu       $t6, $t6, 0x7130
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(375, 0XBE0));
    // 0x80566E88: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80566E8C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566E90: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80566E94: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80566E98: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80566E9C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80566EA0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80566EA4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80566EA8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x80566EAC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x80566EB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566EB4:
    // 0x80566EB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80566EB8: jr          $ra
    // 0x80566EBC: nop

    return;
    // 0x80566EBC: nop

;}
RECOMP_FUNC void func_8047265C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8047265C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80472660: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80472664: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AF0) << 16);
    // 0x80472668: lwc1        $f12, 0x2FB0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AF0));
    // 0x8047266C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80472670: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AF4) << 16);
    // 0x80472674: lwc1        $f14, 0x2FB4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AF4));
    // 0x80472678: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AF8) << 16);
    // 0x8047267C: mul.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80472680: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80472684: nop

    // 0x80472688: bc1tl       L_804726A8
    if (c1cs) {
        // 0x8047268C: add.s       $f10, $f2, $f0
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_804726A8;
    }
    goto skip_0;
    // 0x8047268C: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    skip_0:
    // 0x80472690: lwc1        $f8, 0x2FB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AF8));
    // 0x80472694: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80472698: nop

    // 0x8047269C: bc1fl       L_804726B0
    if (!c1cs) {
        // 0x804726A0: lwc1        $f2, 0x10($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
            goto L_804726B0;
    }
    goto skip_1;
    // 0x804726A0: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    skip_1:
    // 0x804726A4: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
L_804726A8:
    // 0x804726A8: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x804726AC: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
L_804726B0:
    // 0x804726B0: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x804726B4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(158, 0X1AFC) << 16);
    // 0x804726B8: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x804726BC: mul.s       $f0, $f18, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x804726C0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x804726C4: nop

    // 0x804726C8: bc1tl       L_804726E8
    if (c1cs) {
        // 0x804726CC: add.s       $f6, $f2, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_804726E8;
    }
    goto skip_2;
    // 0x804726CC: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    skip_2:
    // 0x804726D0: lwc1        $f4, 0x2FBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(158, 0X1AFC));
    // 0x804726D4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x804726D8: nop

    // 0x804726DC: bc1f        L_804726EC
    if (!c1cs) {
        // 0x804726E0: nop
    
            goto L_804726EC;
    }
    // 0x804726E0: nop

    // 0x804726E4: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
L_804726E8:
    // 0x804726E8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_804726EC:
    // 0x804726EC: jr          $ra
    // 0x804726F0: nop

    return;
    // 0x804726F0: nop

;}
RECOMP_FUNC void func_80566320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566320: jr          $ra
    // 0x80566324: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80566324: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804D142C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D142C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D1430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D1434: jal         0x80044658
    // 0x804D1438: nop

    func_80044658(rdram, ctx);
        goto after_0;
    // 0x804D1438: nop

    after_0:
    // 0x804D143C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D1440: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804D1444: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D1448: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x804D144C: jr          $ra
    // 0x804D1450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D1450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80584E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584E8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584E90: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584E94: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584E98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584E9C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584EA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584EA4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584EA8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584EAC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584EB0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584EB4: jr          $ra
    // 0x80584EB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584EB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    // 0x80584EBC: nop

;}
RECOMP_FUNC void func_80030120(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030120: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030124: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030128: lw          $t6, 0x1A4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1A4);
    // 0x8003012C: bnel        $t6, $zero, L_8003016C
    if (ctx->r14 != 0) {
        // 0x80030130: lw          $t0, 0x24($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X24);
            goto L_8003016C;
    }
    goto skip_0;
    // 0x80030130: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
    skip_0:
    // 0x80030134: lw          $t7, 0x24($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X24);
    // 0x80030138: andi        $t8, $t7, 0x700
    ctx->r24 = ctx->r15 & 0X700;
    // 0x8003013C: beq         $t8, $zero, L_80030158
    if (ctx->r24 == 0) {
        // 0x80030140: nop
    
            goto L_80030158;
    }
    // 0x80030140: nop

    // 0x80030144: lw          $t9, 0x78($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X78);
    // 0x80030148: bne         $t9, $zero, L_80030158
    if (ctx->r25 != 0) {
        // 0x8003014C: nop
    
            goto L_80030158;
    }
    // 0x8003014C: nop

    // 0x80030150: b           L_80030184
    // 0x80030154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80030184;
    // 0x80030154: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030158:
    // 0x80030158: jal         0x8002E6FC
    // 0x8003015C: nop

    func_8002E6FC(rdram, ctx);
        goto after_0;
    // 0x8003015C: nop

    after_0:
    // 0x80030160: b           L_80030184
    // 0x80030164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030184;
    // 0x80030164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030168: lw          $t0, 0x24($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X24);
L_8003016C:
    // 0x8003016C: andi        $t1, $t0, 0x700
    ctx->r9 = ctx->r8 & 0X700;
    // 0x80030170: beql        $t1, $zero, L_80030184
    if (ctx->r9 == 0) {
        // 0x80030174: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030184;
    }
    goto skip_1;
    // 0x80030174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x80030178: jal         0x800232C0
    // 0x8003017C: nop

    func_800232C0(rdram, ctx);
        goto after_1;
    // 0x8003017C: nop

    after_1:
    // 0x80030180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030184:
    // 0x80030184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030188: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003018C: jr          $ra
    // 0x80030190: nop

    return;
    // 0x80030190: nop

;}
RECOMP_FUNC void func_806CF8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CF8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806CF8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CF8C8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806CF8CC: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806CF8D0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806CF8D4: lui         $t8, 0x806D
    ctx->r24 = S32(RELOC_HI16(607, 0X1990) << 16);
    // 0x806CF8D8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806CF8DC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806CF8E0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806CF8E4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806CF8E8: lw          $t8, 0x1130($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(607, 0X1990));
    // 0x806CF8EC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806CF8F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806CF8F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806CF8F8: jal         0x80048490
    // 0x806CF8FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806CF8FC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806CF900: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806CF904: jal         0x80048378
    // 0x806CF908: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806CF908: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x806CF90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CF910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806CF914: jr          $ra
    // 0x806CF918: nop

    return;
    // 0x806CF918: nop

;}
RECOMP_FUNC void func_805D2110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2110: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2118: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D211C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805D2120: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x805D2124: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805D2128: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805D212C: beq         $a2, $at, L_805D2160
    if (ctx->r6 == ctx->r1) {
        // 0x805D2130: sll         $a1, $a2, 16
        ctx->r5 = S32(ctx->r6 << 16);
            goto L_805D2160;
    }
    // 0x805D2130: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x805D2134: jal         0x80067930
    // 0x805D2138: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x805D2138: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_0:
    // 0x805D213C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805D2140: bne         $v0, $at, L_805D2160
    if (ctx->r2 != ctx->r1) {
        // 0x805D2144: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_805D2160;
    }
    // 0x805D2144: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x805D2148: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805D214C: jal         0x80067878
    // 0x805D2150: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x805D2150: lh          $a1, 0x1F0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X1F0);
    after_1:
    // 0x805D2154: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x805D2158: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x805D215C: sh          $t8, 0x1F0($t9)
    MEM_H(0X1F0, ctx->r25) = ctx->r24;
L_805D2160:
    // 0x805D2160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D2164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D2168: jr          $ra
    // 0x805D216C: nop

    return;
    // 0x805D216C: nop

;}
RECOMP_FUNC void func_806F2700(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2700: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F2704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F2708: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806F270C: jal         0x80047090
    // 0x806F2710: addiu       $a0, $zero, 0x4655
    ctx->r4 = ADD32(0, 0X4655);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x806F2710: addiu       $a0, $zero, 0x4655
    ctx->r4 = ADD32(0, 0X4655);
    after_0:
    // 0x806F2714: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806F2718: lui         $at, 0x4655
    ctx->r1 = S32(0X4655 << 16);
    // 0x806F271C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806F2720: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x806F2724: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x806F2728: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x806F272C: sh          $v0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r2;
    // 0x806F2730: jal         0x8004613C
    // 0x806F2734: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x806F2734: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_1:
    // 0x806F2738: bne         $v0, $zero, L_806F2748
    if (ctx->r2 != 0) {
        // 0x806F273C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_806F2748;
    }
    // 0x806F273C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806F2740: b           L_806F2778
    // 0x806F2744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F2778;
    // 0x806F2744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F2748:
    // 0x806F2748: lhu         $t7, 0x1A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X1A);
    // 0x806F274C: lhu         $t9, 0xE($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XE);
    // 0x806F2750: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x806F2754: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x806F2758: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x806F275C: sh          $t1, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r9;
    // 0x806F2760: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F2764: jal         0x80047F9C
    // 0x806F2768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806F2768: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x806F276C: jal         0x8005FDC4
    // 0x806F2770: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x806F2770: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x806F2774: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_806F2778:
    // 0x806F2778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F277C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2780: jr          $ra
    // 0x806F2784: nop

    return;
    // 0x806F2784: nop

;}
RECOMP_FUNC void func_8040EEA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040EEA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040EEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040EEA8: jal         0x8040EDB0
    // 0x8040EEAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EDB0(rdram, ctx);
        goto after_0;
    // 0x8040EEAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040EEB0: beq         $v0, $zero, L_8040EED0
    if (ctx->r2 == 0) {
        // 0x8040EEB4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040EED0;
    }
    // 0x8040EEB4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040EEB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040EEBC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040EEC0: jal         0x8040F0B8
    // 0x8040EEC4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_8040F0B8(rdram, ctx);
        goto after_1;
    // 0x8040EEC4: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
    // 0x8040EEC8: b           L_8040EEE4
    // 0x8040EECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040EEE4;
    // 0x8040EECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EED0:
    // 0x8040EED0: jal         0x8040EC38
    // 0x8040EED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040EC38(rdram, ctx);
        goto after_2;
    // 0x8040EED4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8040EED8: jal         0x8040ECBC
    // 0x8040EEDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8040ECBC(rdram, ctx);
        goto after_3;
    // 0x8040EEDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8040EEE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040EEE4:
    // 0x8040EEE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040EEE8: jr          $ra
    // 0x8040EEEC: nop

    return;
    // 0x8040EEEC: nop

;}
RECOMP_FUNC void func_8043515C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043515C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80435160: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80435164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80435168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043516C: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80435170: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80435174: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80435178: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x8043517C: jal         0x8043511C
    // 0x80435180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8043511C(rdram, ctx);
        goto after_0;
    // 0x80435180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80435184: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80435188: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(71, 0X29D4) << 16);
    // 0x8043518C: addiu       $t7, $t7, 0x6484
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(71, 0X29D4));
    // 0x80435190: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80435194: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80435198: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8043519C: bne         $t6, $zero, L_804351B4
    if (ctx->r14 != 0) {
        // 0x804351A0: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_804351B4;
    }
    // 0x804351A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804351A4: jal         0x800445A4
    // 0x804351A8: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804351A8: nop

    after_1:
    // 0x804351AC: b           L_804351DC
    // 0x804351B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804351DC;
    // 0x804351B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804351B4:
    // 0x804351B4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x804351B8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x804351BC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804351C0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804351C4: jal         0x804351E8
    // 0x804351C8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_804351E8(rdram, ctx);
        goto after_2;
    // 0x804351C8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x804351CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804351D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804351D4: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804351D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804351DC:
    // 0x804351DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804351E0: jr          $ra
    // 0x804351E4: nop

    return;
    // 0x804351E4: nop

;}
RECOMP_FUNC void func_804450A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804450A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804450A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804450AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804450B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804450B4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804450B8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804450BC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804450C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804450C4: jal         0x80047090
    // 0x804450C8: addiu       $a0, $zero, 0x46E5
    ctx->r4 = ADD32(0, 0X46E5);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804450C8: addiu       $a0, $zero, 0x46E5
    ctx->r4 = ADD32(0, 0X46E5);
    after_0:
    // 0x804450CC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804450D0: beq         $v0, $at, L_80445134
    if (ctx->r2 == ctx->r1) {
        // 0x804450D4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80445134;
    }
    // 0x804450D4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804450D8: lui         $at, 0x46E5
    ctx->r1 = S32(0X46E5 << 16);
    // 0x804450DC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x804450E0: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804450E4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804450E8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x804450EC: jal         0x8004613C
    // 0x804450F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804450F0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x804450F4: beq         $v0, $zero, L_80445134
    if (ctx->r2 == 0) {
        // 0x804450F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80445134;
    }
    // 0x804450F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804450FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80445100: jal         0x80047F9C
    // 0x80445104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80445104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80445108: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8044510C: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x80445110: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445114: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80445118: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8044511C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445120: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x80445124: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80445128: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x8044512C: jalr        $t9
    // 0x80445130: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80445130: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    after_3:
L_80445134:
    // 0x80445134: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80445138: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8044513C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80445140: jr          $ra
    // 0x80445144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80445144: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8051A8E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A8E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8051A8E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A8E8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8051A8EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8051A8F0: beql        $t6, $zero, L_8051A94C
    if (ctx->r14 == 0) {
        // 0x8051A8F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8051A94C;
    }
    goto skip_0;
    // 0x8051A8F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8051A8F8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8051A8FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8051A900: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8051A904: jalr        $t9
    // 0x8051A908: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8051A908: nop

    after_0:
    // 0x8051A90C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8051A910: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8051A914: bne         $v0, $at, L_8051A920
    if (ctx->r2 != ctx->r1) {
        // 0x8051A918: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8051A920;
    }
    // 0x8051A918: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8051A91C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8051A920:
    // 0x8051A920: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8051A924: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8051A928: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8051A92C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8051A930: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8051A934: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8051A938: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
    // 0x8051A93C: jal         0x8051A820
    // 0x8051A940: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8051A820(rdram, ctx);
        goto after_1;
    // 0x8051A940: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8051A944: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8051A948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8051A94C:
    // 0x8051A94C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8051A950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8051A954: jr          $ra
    // 0x8051A958: nop

    return;
    // 0x8051A958: nop

;}
RECOMP_FUNC void func_805221B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805221B0: jr          $ra
    // 0x805221B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805221B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
