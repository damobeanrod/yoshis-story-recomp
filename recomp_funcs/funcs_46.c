#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_806EE888(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EE888: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EE88C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EE890: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EE894: jal         0x806EC16C
    // 0x806EE898: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EE898: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EE89C: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EE8A0: jal         0x800577D8
    // 0x806EE8A4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EE8A4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EE8A8: jal         0x806EE5E4
    // 0x806EE8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE5E4(rdram, ctx);
        goto after_2;
    // 0x806EE8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EE8B0: jal         0x806EE664
    // 0x806EE8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE664(rdram, ctx);
        goto after_3;
    // 0x806EE8B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EE8B8: jal         0x806EE720
    // 0x806EE8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE720(rdram, ctx);
        goto after_4;
    // 0x806EE8BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EE8C0: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x806EE8C4: lw          $v0, 0x12C($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X12C);
    // 0x806EE8C8: bnel        $v0, $zero, L_806EE8E0
    if (ctx->r2 != 0) {
        // 0x806EE8CC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_806EE8E0;
    }
    goto skip_0;
    // 0x806EE8CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x806EE8D0: lw          $t8, 0x12C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X12C);
    // 0x806EE8D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806EE8D8: beq         $t8, $at, L_806EE8F4
    if (ctx->r24 == ctx->r1) {
        // 0x806EE8DC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_806EE8F4;
    }
    // 0x806EE8DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_806EE8E0:
    // 0x806EE8E0: bnel        $v0, $at, L_806EE914
    if (ctx->r2 != ctx->r1) {
        // 0x806EE8E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EE914;
    }
    goto skip_1;
    // 0x806EE8E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806EE8E8: lw          $t9, 0x12C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X12C);
    // 0x806EE8EC: bnel        $t9, $zero, L_806EE914
    if (ctx->r25 != 0) {
        // 0x806EE8F0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EE914;
    }
    goto skip_2;
    // 0x806EE8F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_806EE8F4:
    // 0x806EE8F4: jal         0x806EE640
    // 0x806EE8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EE640(rdram, ctx);
        goto after_5;
    // 0x806EE8F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EE8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EE900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EE904: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806EE908: jal         0x806EF4A0
    // 0x806EE90C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806EF4A0(rdram, ctx);
        goto after_6;
    // 0x806EE90C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EE910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EE914:
    // 0x806EE914: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806EE918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806EE91C: jr          $ra
    // 0x806EE920: nop

    return;
    // 0x806EE920: nop

;}
RECOMP_FUNC void func_8040C6D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C6D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8040C6DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C6E0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8040C6E4: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8040C6E8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8040C6EC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040C6F0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8040C6F4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8040C6F8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(20, 0X1EF0) << 16);
    // 0x8040C6FC: lwc1        $f10, -0x1B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(20, 0X1EF0));
    // 0x8040C700: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8040C704: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8040C708: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8040C70C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8040C710: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8040C714: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8040C718: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8040C71C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8040C720: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8040C724: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8040C728: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8040C72C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8040C730: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8040C734: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8040C738: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8040C73C: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8040C740: jalr        $t9
    // 0x8040C744: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8040C744: nop

    after_0:
    // 0x8040C748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C74C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8040C750: jr          $ra
    // 0x8040C754: nop

    return;
    // 0x8040C754: nop

;}
RECOMP_FUNC void func_807C6A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807C6A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C6A58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807C6A5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807C6A60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807C6A64: jal         0x80045A34
    // 0x807C6A68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807C6A68: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x807C6A6C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C6A70: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807C6A74: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x807C6A78: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x807C6A7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x807C6A80: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x807C6A84: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x807C6A88: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x807C6A8C: jal         0x8004613C
    // 0x807C6A90: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807C6A90: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x807C6A94: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C6A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C6A9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807C6AA0: jal         0x80047F9C
    // 0x807C6AA4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807C6AA4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    after_2:
    // 0x807C6AA8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x807C6AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C6AB0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x807C6AB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x807C6AB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807C6ABC: sb          $v0, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r2;
    // 0x807C6AC0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x807C6AC4: sb          $v0, 0x31($t7)
    MEM_B(0X31, ctx->r15) = ctx->r2;
    // 0x807C6AC8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807C6ACC: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x807C6AD0: sb          $zero, 0x10($t9)
    MEM_B(0X10, ctx->r25) = 0;
    // 0x807C6AD4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x807C6AD8: jal         0x807C6C84
    // 0x807C6ADC: sb          $v0, 0x165($t0)
    MEM_B(0X165, ctx->r8) = ctx->r2;
    func_807C6C84(rdram, ctx);
        goto after_3;
    // 0x807C6ADC: sb          $v0, 0x165($t0)
    MEM_B(0X165, ctx->r8) = ctx->r2;
    after_3:
    // 0x807C6AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807C6AE4: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
    // 0x807C6AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807C6AEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807C6AF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807C6AF4: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x807C6AF8: jr          $ra
    // 0x807C6AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807C6AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8003E558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E558: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x8003E55C: addiu       $at, $zero, 0x406C
    ctx->r1 = ADD32(0, 0X406C);
    // 0x8003E560: beq         $v0, $at, L_8003E578
    if (ctx->r2 == ctx->r1) {
        // 0x8003E564: addiu       $at, $zero, 0x4144
        ctx->r1 = ADD32(0, 0X4144);
            goto L_8003E578;
    }
    // 0x8003E564: addiu       $at, $zero, 0x4144
    ctx->r1 = ADD32(0, 0X4144);
    // 0x8003E568: beq         $v0, $at, L_8003E580
    if (ctx->r2 == ctx->r1) {
        // 0x8003E56C: nop
    
            goto L_8003E580;
    }
    // 0x8003E56C: nop

    // 0x8003E570: b           L_8003E588
    // 0x8003E574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003E588;
    // 0x8003E574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003E578:
    // 0x8003E578: jr          $ra
    // 0x8003E57C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003E57C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E580:
    // 0x8003E580: jr          $ra
    // 0x8003E584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8003E584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003E588:
    // 0x8003E588: jr          $ra
    // 0x8003E58C: nop

    return;
    // 0x8003E58C: nop

;}
RECOMP_FUNC void func_806F23E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F23E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F23E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F23EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F23F0: jal         0x80045A34
    // 0x806F23F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F23F4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806F23F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F23FC: bne         $v0, $zero, L_806F240C
    if (ctx->r2 != 0) {
        // 0x806F2400: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806F240C;
    }
    // 0x806F2400: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806F2404: b           L_806F2418
    // 0x806F2408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F2418;
    // 0x806F2408: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F240C:
    // 0x806F240C: jal         0x806F23D4
    // 0x806F2410: nop

    func_806F23D4(rdram, ctx);
        goto after_1;
    // 0x806F2410: nop

    after_1:
    // 0x806F2414: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F2418:
    // 0x806F2418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F241C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F2420: jr          $ra
    // 0x806F2424: nop

    return;
    // 0x806F2424: nop

;}
RECOMP_FUNC void func_8066B050(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8066B050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8066B054: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8066B058: jal         0x8066AF94
    // 0x8066B05C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8066AF94(rdram, ctx);
        goto after_0;
    // 0x8066B05C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8066B060: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8066B064: beq         $v0, $at, L_8066B080
    if (ctx->r2 == ctx->r1) {
        // 0x8066B068: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_8066B080;
    }
    // 0x8066B068: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8066B06C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8066B070: beq         $v0, $at, L_8066B0C4
    if (ctx->r2 == ctx->r1) {
        // 0x8066B074: nop
    
            goto L_8066B0C4;
    }
    // 0x8066B074: nop

    // 0x8066B078: b           L_8066B0D4
    // 0x8066B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8066B0D4;
    // 0x8066B07C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066B080:
    // 0x8066B080: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8066B084: jal         0x8066AD88
    // 0x8066B088: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8066AD88(rdram, ctx);
        goto after_1;
    // 0x8066B088: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8066B08C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8066B090: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8066B094: lw          $t6, 0x1F4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1F4);
    // 0x8066B098: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8066B09C: bne         $t7, $at, L_8066B0BC
    if (ctx->r15 != ctx->r1) {
        // 0x8066B0A0: nop
    
            goto L_8066B0BC;
    }
    // 0x8066B0A0: nop

    // 0x8066B0A4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x8066B0A8: jal         0x80067BBC
    // 0x8066B0AC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x8066B0AC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x8066B0B0: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8066B0B4: jal         0x80067818
    // 0x8066B0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8066B0B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
L_8066B0BC:
    // 0x8066B0BC: b           L_8066B0D4
    // 0x8066B0C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8066B0D4;
    // 0x8066B0C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8066B0C4:
    // 0x8066B0C4: jal         0x8066AD88
    // 0x8066B0C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_8066AD88(rdram, ctx);
        goto after_4;
    // 0x8066B0C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8066B0CC: b           L_8066B0D4
    // 0x8066B0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8066B0D4;
    // 0x8066B0D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8066B0D4:
    // 0x8066B0D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8066B0D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8066B0DC: jr          $ra
    // 0x8066B0E0: nop

    return;
    // 0x8066B0E0: nop

;}
RECOMP_FUNC void func_80568AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568AD4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80568AD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80568ADC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568AE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568AE4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    // 0x80568AE8: jal         0x80568710
    // 0x80568AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80568710(rdram, ctx);
        goto after_0;
    // 0x80568AEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568AF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80568AF8: jal         0x8005FE48
    // 0x80568AFC: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_8005FE48(rdram, ctx);
        goto after_1;
    // 0x80568AFC: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_1:
    // 0x80568B00: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568B04: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80568B08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80568B0C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568B10: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80568B14: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80568B18: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x80568B1C: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x80568B20: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x80568B24: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80568B28: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80568B2C: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80568B30: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80568B34: jal         0x80569310
    // 0x80568B38: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    func_80569310(rdram, ctx);
        goto after_2;
    // 0x80568B38: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    after_2:
    // 0x80568B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80568B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80568B44: jr          $ra
    // 0x80568B48: nop

    return;
    // 0x80568B48: nop

;}
RECOMP_FUNC void func_806E7AB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7AB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806E7ABC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806E7AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7AC8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(664, 0XEF8) << 16);
    // 0x806E7ACC: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806E7AD0: lwc1        $f4, -0x7EC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(664, 0XEF8));
    // 0x806E7AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E7AD8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806E7ADC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806E7AE0: nop

    // 0x806E7AE4: bc1fl       L_806E7AFC
    if (!c1cs) {
        // 0x806E7AE8: swc1        $f2, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
            goto L_806E7AFC;
    }
    goto skip_0;
    // 0x806E7AE8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    skip_0:
    // 0x806E7AEC: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x806E7AF0: b           L_806E7B20
    // 0x806E7AF4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
        goto L_806E7B20;
    // 0x806E7AF4: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x806E7AF8: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
L_806E7AFC:
    // 0x806E7AFC: swc1        $f2, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f2.u32l;
    // 0x806E7B00: jal         0x806E7E4C
    // 0x806E7B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806E7E4C(rdram, ctx);
        goto after_0;
    // 0x806E7B04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E7B08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E7B0C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806E7B10: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E7B14: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E7B18: jal         0x8005FCA8
    // 0x806E7B1C: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x806E7B1C: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    after_1:
L_806E7B20:
    // 0x806E7B20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E7B24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7B28: jr          $ra
    // 0x806E7B2C: nop

    return;
    // 0x806E7B2C: nop

;}
RECOMP_FUNC void func_805C9080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9080: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C9084: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C9088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C908C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C9090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C9094: jal         0x805C6AF0
    // 0x805C9098: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_805C6AF0(rdram, ctx);
        goto after_0;
    // 0x805C9098: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x805C909C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805C90A0: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x805C90A4: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C90A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805C90AC: lwc1        $f6, 0x30($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X30);
    // 0x805C90B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C90B4: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C90B8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C90BC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x805C90C0: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x805C90C4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805C90C8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C90CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C90D0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805C90D4: nop

    // 0x805C90D8: bc1f        L_805C9124
    if (!c1cs) {
        // 0x805C90DC: nop
    
            goto L_805C9124;
    }
    // 0x805C90DC: nop

    // 0x805C90E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C90E4: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x805C90E8: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x805C90EC: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x805C90F0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C90F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C90F8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C90FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9100: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    // 0x805C9104: jal         0x805C74C8
    // 0x805C9108: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    func_805C74C8(rdram, ctx);
        goto after_1;
    // 0x805C9108: swc1        $f0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f0.u32l;
    after_1:
    // 0x805C910C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9114: jal         0x805C9D10
    // 0x805C9118: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C9118: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x805C911C: b           L_805C9144
    // 0x805C9120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9144;
    // 0x805C9120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9124:
    // 0x805C9124: jal         0x80048F84
    // 0x805C9128: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805C9128: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_3:
    // 0x805C912C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C9130: jal         0x80048F84
    // 0x805C9134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805C9134: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805C9138: jal         0x805C7844
    // 0x805C913C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_5;
    // 0x805C913C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805C9140: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9144:
    // 0x805C9144: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9148: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805C914C: jr          $ra
    // 0x805C9150: nop

    return;
    // 0x805C9150: nop

;}
RECOMP_FUNC void func_806F7384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F7384: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F7388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F738C: jal         0x806F72C0
    // 0x806F7390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F72C0(rdram, ctx);
        goto after_0;
    // 0x806F7390: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F7394: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F7398: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F739C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806F73A0: jal         0x806F73DC
    // 0x806F73A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F73DC(rdram, ctx);
        goto after_1;
    // 0x806F73A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x806F73A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F73AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806F73B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F73B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806F73B8: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F73BC: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x806F73C0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x806F73C4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806F73C8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x806F73CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F73D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F73D4: jr          $ra
    // 0x806F73D8: nop

    return;
    // 0x806F73D8: nop

;}
RECOMP_FUNC void func_806F6058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6058: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F605C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806F6060: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806F6064: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806F6068: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0X1190) << 16);
    // 0x806F606C: addiu       $t6, $t6, 0x64F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0X1190));
    // 0x806F6070: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806F6074: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F6078: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F607C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F6080: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F6084: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806F6088: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x806F608C: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806F6090: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806F6094: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F6098: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x806F609C: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(685, 0X8C0) << 16);
    // 0x806F60A0: addiu       $t8, $t8, 0x5C20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(685, 0X8C0));
    // 0x806F60A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F60A8: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806F60AC: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F60B0: jal         0x806F600C
    // 0x806F60B4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    func_806F600C(rdram, ctx);
        goto after_0;
    // 0x806F60B4: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    after_0:
    // 0x806F60B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F60BC: jal         0x80045A34
    // 0x806F60C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x806F60C0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x806F60C4: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(685, 0XCCC) << 16);
    // 0x806F60C8: addiu       $t9, $t9, 0x602C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(685, 0XCCC));
    // 0x806F60CC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806F60D0: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x806F60D4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806F60D8: jal         0x80058958
    // 0x806F60DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_80058958(rdram, ctx);
        goto after_2;
    // 0x806F60DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_2:
    // 0x806F60E0: beq         $v0, $zero, L_806F6158
    if (ctx->r2 == 0) {
        // 0x806F60E4: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_806F6158;
    }
    // 0x806F60E4: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x806F60E8: lw          $t0, -0x7BC4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7BC4);
    // 0x806F60EC: lw          $t1, 0x10C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10C);
    // 0x806F60F0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x806F60F4: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x806F60F8: beql        $t3, $zero, L_806F615C
    if (ctx->r11 == 0) {
        // 0x806F60FC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806F615C;
    }
    goto skip_0;
    // 0x806F60FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x806F6100: jal         0x80056564
    // 0x806F6104: nop

    func_80056564(rdram, ctx);
        goto after_3;
    // 0x806F6104: nop

    after_3:
    // 0x806F6108: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x806F610C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F6110: beq         $v0, $zero, L_806F6158
    if (ctx->r2 == 0) {
        // 0x806F6114: sw          $v0, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r2;
            goto L_806F6158;
    }
    // 0x806F6114: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x806F6118: jal         0x800457A0
    // 0x806F611C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_4;
    // 0x806F611C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x806F6120: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x806F6124: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x806F6128: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806F612C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x806F6130: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x806F6134: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806F6138: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F613C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F6140: jal         0x80056584
    // 0x806F6144: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80056584(rdram, ctx);
        goto after_5;
    // 0x806F6144: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_5:
    // 0x806F6148: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806F614C: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806F6150: addiu       $t8, $t8, 0x784C
    ctx->r24 = ADD32(ctx->r24, 0X784C);
    // 0x806F6154: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
L_806F6158:
    // 0x806F6158: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806F615C:
    // 0x806F615C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806F6160: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F6164: jr          $ra
    // 0x806F6168: nop

    return;
    // 0x806F6168: nop

;}
RECOMP_FUNC void func_80466950(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466950: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80466954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80466958: lw          $a2, 0x180($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X180);
    // 0x8046695C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80466960: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80466964: beq         $a2, $zero, L_804669FC
    if (ctx->r6 == 0) {
        // 0x80466968: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_804669FC;
    }
    // 0x80466968: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8046696C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80466970: lwc1        $f0, 0x2CF4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x80466974: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80466978: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x8046697C: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80466980: lwc1        $f4, 0x6C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X6C);
    // 0x80466984: lwc1        $f10, 0x6C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x80466988: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8046698C: nop

    // 0x80466990: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80466994: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80466998: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x8046699C: lwc1        $f0, 0x2CF4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2CF4);
    // 0x804669A0: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x804669A4: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x804669A8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x804669AC: lwc1        $f4, 0x6C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X6C);
    // 0x804669B0: lwc1        $f16, 0x6C($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X6C);
    // 0x804669B4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x804669B8: nop

    // 0x804669BC: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x804669C0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804669C4: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x804669C8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x804669CC: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x804669D0: jal         0x80049018
    // 0x804669D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x804669D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x804669D8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x804669DC: beq         $v0, $zero, L_804669F4
    if (ctx->r2 == 0) {
        // 0x804669E0: lw          $a2, 0x1C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1C);
            goto L_804669F4;
    }
    // 0x804669E0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x804669E4: lwc1        $f4, 0x50($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X50);
    // 0x804669E8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x804669EC: b           L_804669FC
    // 0x804669F0: swc1        $f6, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f6.u32l;
        goto L_804669FC;
    // 0x804669F0: swc1        $f6, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f6.u32l;
L_804669F4:
    // 0x804669F4: lwc1        $f16, 0x50($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X50);
    // 0x804669F8: swc1        $f16, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f16.u32l;
L_804669FC:
    // 0x804669FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80466A00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80466A04: jr          $ra
    // 0x80466A08: nop

    return;
    // 0x80466A08: nop

;}
RECOMP_FUNC void func_80709504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709504: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80709508: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8070950C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80709510: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80709514: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80709518: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8070951C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80709520: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80709524: lui         $t1, 0x8071
    ctx->r9 = S32(RELOC_HI16(718, 0X1500) << 16);
    // 0x80709528: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8070952C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80709530: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80709534: lw          $t1, -0x5920($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(718, 0X1500));
    // 0x80709538: jr          $ra
    // 0x8070953C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8070953C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8042E0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E0E0: lui         $v0, 0x8043
    ctx->r2 = S32(RELOC_HI16(56, 0X10) << 16);
    // 0x8042E0E4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8042E0E8: jr          $ra
    // 0x8042E0EC: addiu       $v0, $v0, -0x1F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(56, 0X10));
    return;
    // 0x8042E0EC: addiu       $v0, $v0, -0x1F10
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(56, 0X10));
;}
RECOMP_FUNC void func_806E0250(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E0250: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E0254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E0258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E025C: jal         0x80045A34
    // 0x806E0260: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806E0260: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x806E0264: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E0268: bne         $v0, $zero, L_806E0278
    if (ctx->r2 != 0) {
        // 0x806E026C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806E0278;
    }
    // 0x806E026C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806E0270: b           L_806E0284
    // 0x806E0274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806E0284;
    // 0x806E0274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806E0278:
    // 0x806E0278: jal         0x806E021C
    // 0x806E027C: nop

    func_806E021C(rdram, ctx);
        goto after_1;
    // 0x806E027C: nop

    after_1:
    // 0x806E0280: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806E0284:
    // 0x806E0284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E0288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E028C: jr          $ra
    // 0x806E0290: nop

    return;
    // 0x806E0290: nop

;}
RECOMP_FUNC void func_80058248(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058248: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005824C: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80058250: lw          $a1, -0x6DA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6DA8);
    // 0x80058254: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058258: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005825C: addiu       $a0, $a0, 0x10C
    ctx->r4 = ADD32(ctx->r4, 0X10C);
    // 0x80058260: jal         0x80065490
    // 0x80058264: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x80058264: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    after_0:
    // 0x80058268: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x8005826C: lw          $a1, -0x6DA8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6DA8);
    // 0x80058270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80058274: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    // 0x80058278: jal         0x80065490
    // 0x8005827C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x8005827C: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    after_1:
    // 0x80058280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058288: jr          $ra
    // 0x8005828C: nop

    return;
    // 0x8005828C: nop

;}
RECOMP_FUNC void func_8042EED4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042EED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042EED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042EEDC: jal         0x8042E298
    // 0x8042EEE0: nop

    func_8042E298(rdram, ctx);
        goto after_0;
    // 0x8042EEE0: nop

    after_0:
    // 0x8042EEE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042EEE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042EEEC: jr          $ra
    // 0x8042EEF0: nop

    return;
    // 0x8042EEF0: nop

;}
RECOMP_FUNC void func_8002CF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CF40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CF48: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CF4C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002CF50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002CF54: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8002CF58: addiu       $t8, $t8, 0x3450
    ctx->r24 = ADD32(ctx->r24, 0X3450);
    // 0x8002CF5C: sb          $t7, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r15;
    // 0x8002CF60: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8002CF64: lw          $a2, 0x138($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X138);
    // 0x8002CF68: jal         0x8002DBE4
    // 0x8002CF6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8002DBE4(rdram, ctx);
        goto after_0;
    // 0x8002CF6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8002CF70: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CF74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002CF78: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8002CF7C: sb          $t9, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = ctx->r25;
    // 0x8002CF80: sw          $zero, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = 0;
    // 0x8002CF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CF88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CF8C: jr          $ra
    // 0x8002CF90: nop

    return;
    // 0x8002CF90: nop

;}
RECOMP_FUNC void func_800186E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800186E0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800186E4: lw          $t6, -0x6D70($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D70);
    // 0x800186E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800186EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800186F0: beq         $t6, $zero, L_80018B3C
    if (ctx->r14 == 0) {
        // 0x800186F4: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80018B3C;
    }
    // 0x800186F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800186F8: sw          $a0, -0x6D30($at)
    MEM_W(-0X6D30, ctx->r1) = ctx->r4;
    // 0x800186FC: jal         0x800109DC
    // 0x80018700: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800109DC(rdram, ctx);
        goto after_0;
    // 0x80018700: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80018704: beq         $v0, $zero, L_80018B3C
    if (ctx->r2 == 0) {
        // 0x80018708: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80018B3C;
    }
    // 0x80018708: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001870C: beq         $a0, $zero, L_80018738
    if (ctx->r4 == 0) {
        // 0x80018710: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80018738;
    }
    // 0x80018710: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80018714: beq         $a0, $at, L_800187B4
    if (ctx->r4 == ctx->r1) {
        // 0x80018718: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800187B4;
    }
    // 0x80018718: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001871C: beq         $a0, $at, L_80018830
    if (ctx->r4 == ctx->r1) {
        // 0x80018720: addiu       $a1, $zero, -0x3C
        ctx->r5 = ADD32(0, -0X3C);
            goto L_80018830;
    }
    // 0x80018720: addiu       $a1, $zero, -0x3C
    ctx->r5 = ADD32(0, -0X3C);
    // 0x80018724: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80018728: beq         $a0, $at, L_80018AD8
    if (ctx->r4 == ctx->r1) {
        // 0x8001872C: nop
    
            goto L_80018AD8;
    }
    // 0x8001872C: nop

    // 0x80018730: b           L_80018B40
    // 0x80018734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018738:
    // 0x80018738: jal         0x80018B4C
    // 0x8001873C: nop

    func_80018B4C(rdram, ctx);
        goto after_1;
    // 0x8001873C: nop

    after_1:
    // 0x80018740: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018744: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018748: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001874C: jal         0x8001ADE8
    // 0x80018750: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001ADE8(rdram, ctx);
        goto after_2;
    // 0x80018750: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_2:
    // 0x80018754: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018758: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x8001875C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80018760: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80018764: sltiu       $at, $t8, 0x35
    ctx->r1 = ctx->r24 < 0X35 ? 1 : 0;
    // 0x80018768: beq         $at, $zero, L_80018794
    if (ctx->r1 == 0) {
        // 0x8001876C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80018794;
    }
    // 0x8001876C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80018770: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018774: addu        $at, $at, $t8
    gpr jr_addend_8001877C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80018778: lw          $t8, -0xF14($at)
    ctx->r24 = ADD32(ctx->r1, -0XF14);
    // 0x8001877C: jr          $t8
    // 0x80018780: nop

    switch (jr_addend_8001877C >> 2) {
        case 0: goto L_80018784; break;
        case 1: goto L_80018784; break;
        case 2: goto L_80018784; break;
        case 3: goto L_80018784; break;
        case 4: goto L_80018784; break;
        case 5: goto L_80018784; break;
        case 6: goto L_80018784; break;
        case 7: goto L_80018784; break;
        case 8: goto L_80018784; break;
        case 9: goto L_80018784; break;
        case 10: goto L_80018794; break;
        case 11: goto L_80018794; break;
        case 12: goto L_80018794; break;
        case 13: goto L_80018794; break;
        case 14: goto L_80018794; break;
        case 15: goto L_80018794; break;
        case 16: goto L_80018784; break;
        case 17: goto L_80018794; break;
        case 18: goto L_80018794; break;
        case 19: goto L_80018784; break;
        case 20: goto L_80018794; break;
        case 21: goto L_80018794; break;
        case 22: goto L_80018794; break;
        case 23: goto L_80018794; break;
        case 24: goto L_80018794; break;
        case 25: goto L_80018794; break;
        case 26: goto L_80018794; break;
        case 27: goto L_80018794; break;
        case 28: goto L_80018794; break;
        case 29: goto L_80018794; break;
        case 30: goto L_80018794; break;
        case 31: goto L_80018794; break;
        case 32: goto L_80018794; break;
        case 33: goto L_80018794; break;
        case 34: goto L_80018784; break;
        case 35: goto L_800187A4; break;
        case 36: goto L_80018794; break;
        case 37: goto L_80018794; break;
        case 38: goto L_80018794; break;
        case 39: goto L_80018794; break;
        case 40: goto L_80018794; break;
        case 41: goto L_80018794; break;
        case 42: goto L_80018794; break;
        case 43: goto L_80018794; break;
        case 44: goto L_80018784; break;
        case 45: goto L_80018794; break;
        case 46: goto L_80018794; break;
        case 47: goto L_80018794; break;
        case 48: goto L_80018794; break;
        case 49: goto L_80018784; break;
        case 50: goto L_80018794; break;
        case 51: goto L_80018794; break;
        case 52: goto L_80018794; break;
        default: switch_error(__func__, 0x8001877C, 0x800AF0EC);
    }
    // 0x80018780: nop

L_80018784:
    // 0x80018784: jal         0x8001AE64
    // 0x80018788: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_3;
    // 0x80018788: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_3:
    // 0x8001878C: b           L_80018B40
    // 0x80018790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018794:
    // 0x80018794: jal         0x8001AE64
    // 0x80018798: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_8001AE64(rdram, ctx);
        goto after_4;
    // 0x80018798: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_4:
    // 0x8001879C: b           L_80018B40
    // 0x800187A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800187A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800187A4:
    // 0x800187A4: jal         0x80018B78
    // 0x800187A8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80018B78(rdram, ctx);
        goto after_5;
    // 0x800187A8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_5:
    // 0x800187AC: b           L_80018B40
    // 0x800187B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800187B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800187B4:
    // 0x800187B4: jal         0x80018B4C
    // 0x800187B8: nop

    func_80018B4C(rdram, ctx);
        goto after_6;
    // 0x800187B8: nop

    after_6:
    // 0x800187BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800187C0: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800187C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800187C8: jal         0x8001ADE8
    // 0x800187CC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001ADE8(rdram, ctx);
        goto after_7;
    // 0x800187CC: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_7:
    // 0x800187D0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800187D4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800187D8: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x800187DC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x800187E0: sltiu       $at, $t0, 0x35
    ctx->r1 = ctx->r8 < 0X35 ? 1 : 0;
    // 0x800187E4: beq         $at, $zero, L_80018810
    if (ctx->r1 == 0) {
        // 0x800187E8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80018810;
    }
    // 0x800187E8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800187EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800187F0: addu        $at, $at, $t0
    gpr jr_addend_800187F8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800187F4: lw          $t0, -0xE40($at)
    ctx->r8 = ADD32(ctx->r1, -0XE40);
    // 0x800187F8: jr          $t0
    // 0x800187FC: nop

    switch (jr_addend_800187F8 >> 2) {
        case 0: goto L_80018800; break;
        case 1: goto L_80018800; break;
        case 2: goto L_80018800; break;
        case 3: goto L_80018800; break;
        case 4: goto L_80018800; break;
        case 5: goto L_80018800; break;
        case 6: goto L_80018800; break;
        case 7: goto L_80018800; break;
        case 8: goto L_80018800; break;
        case 9: goto L_80018800; break;
        case 10: goto L_80018810; break;
        case 11: goto L_80018810; break;
        case 12: goto L_80018810; break;
        case 13: goto L_80018810; break;
        case 14: goto L_80018810; break;
        case 15: goto L_80018810; break;
        case 16: goto L_80018800; break;
        case 17: goto L_80018810; break;
        case 18: goto L_80018810; break;
        case 19: goto L_80018800; break;
        case 20: goto L_80018810; break;
        case 21: goto L_80018810; break;
        case 22: goto L_80018810; break;
        case 23: goto L_80018810; break;
        case 24: goto L_80018810; break;
        case 25: goto L_80018810; break;
        case 26: goto L_80018810; break;
        case 27: goto L_80018810; break;
        case 28: goto L_80018810; break;
        case 29: goto L_80018810; break;
        case 30: goto L_80018810; break;
        case 31: goto L_80018810; break;
        case 32: goto L_80018810; break;
        case 33: goto L_80018810; break;
        case 34: goto L_80018800; break;
        case 35: goto L_80018820; break;
        case 36: goto L_80018810; break;
        case 37: goto L_80018810; break;
        case 38: goto L_80018810; break;
        case 39: goto L_80018810; break;
        case 40: goto L_80018810; break;
        case 41: goto L_80018810; break;
        case 42: goto L_80018810; break;
        case 43: goto L_80018810; break;
        case 44: goto L_80018800; break;
        case 45: goto L_80018810; break;
        case 46: goto L_80018810; break;
        case 47: goto L_80018810; break;
        case 48: goto L_80018810; break;
        case 49: goto L_80018800; break;
        case 50: goto L_80018810; break;
        case 51: goto L_80018810; break;
        case 52: goto L_80018810; break;
        default: switch_error(__func__, 0x800187F8, 0x800AF1C0);
    }
    // 0x800187FC: nop

L_80018800:
    // 0x80018800: jal         0x8001AE64
    // 0x80018804: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_8;
    // 0x80018804: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_8:
    // 0x80018808: b           L_80018B40
    // 0x8001880C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x8001880C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018810:
    // 0x80018810: jal         0x8001AE64
    // 0x80018814: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_8001AE64(rdram, ctx);
        goto after_9;
    // 0x80018814: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_9:
    // 0x80018818: b           L_80018B40
    // 0x8001881C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x8001881C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018820:
    // 0x80018820: jal         0x80018B78
    // 0x80018824: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80018B78(rdram, ctx);
        goto after_10;
    // 0x80018824: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_10:
    // 0x80018828: b           L_80018B40
    // 0x8001882C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x8001882C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018830:
    // 0x80018830: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018834: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018838: jal         0x8001ADE8
    // 0x8001883C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001ADE8(rdram, ctx);
        goto after_11;
    // 0x8001883C: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_11:
    // 0x80018840: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018844: lui         $a1, 0x3F2B
    ctx->r5 = S32(0X3F2B << 16);
    // 0x80018848: ori         $a1, $a1, 0x851F
    ctx->r5 = ctx->r5 | 0X851F;
    // 0x8001884C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018850: jal         0x8001AEDC
    // 0x80018854: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001AEDC(rdram, ctx);
        goto after_12;
    // 0x80018854: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_12:
    // 0x80018858: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8001885C: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018860: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x80018864: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80018868: sltiu       $at, $t2, 0x35
    ctx->r1 = ctx->r10 < 0X35 ? 1 : 0;
    // 0x8001886C: beq         $at, $zero, L_80018B3C
    if (ctx->r1 == 0) {
        // 0x80018870: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80018B3C;
    }
    // 0x80018870: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80018874: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018878: addu        $at, $at, $t2
    gpr jr_addend_80018880 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8001887C: lw          $t2, -0xD6C($at)
    ctx->r10 = ADD32(ctx->r1, -0XD6C);
    // 0x80018880: jr          $t2
    // 0x80018884: nop

    switch (jr_addend_80018880 >> 2) {
        case 0: goto L_80018888; break;
        case 1: goto L_800188A8; break;
        case 2: goto L_800188C8; break;
        case 3: goto L_800188E8; break;
        case 4: goto L_80018908; break;
        case 5: goto L_80018918; break;
        case 6: goto L_80018938; break;
        case 7: goto L_80018958; break;
        case 8: goto L_80018AB8; break;
        case 9: goto L_80018A38; break;
        case 10: goto L_80018B3C; break;
        case 11: goto L_80018B3C; break;
        case 12: goto L_80018B3C; break;
        case 13: goto L_80018A18; break;
        case 14: goto L_80018B3C; break;
        case 15: goto L_80018B3C; break;
        case 16: goto L_80018978; break;
        case 17: goto L_80018B3C; break;
        case 18: goto L_80018B3C; break;
        case 19: goto L_800189F8; break;
        case 20: goto L_80018B3C; break;
        case 21: goto L_80018B3C; break;
        case 22: goto L_80018B3C; break;
        case 23: goto L_80018B3C; break;
        case 24: goto L_80018B3C; break;
        case 25: goto L_80018B3C; break;
        case 26: goto L_80018B3C; break;
        case 27: goto L_80018B3C; break;
        case 28: goto L_80018B3C; break;
        case 29: goto L_80018B3C; break;
        case 30: goto L_80018B3C; break;
        case 31: goto L_80018B3C; break;
        case 32: goto L_80018B3C; break;
        case 33: goto L_80018B3C; break;
        case 34: goto L_80018998; break;
        case 35: goto L_800189B8; break;
        case 36: goto L_80018A78; break;
        case 37: goto L_80018B3C; break;
        case 38: goto L_80018B3C; break;
        case 39: goto L_80018B3C; break;
        case 40: goto L_80018B3C; break;
        case 41: goto L_80018B3C; break;
        case 42: goto L_80018B3C; break;
        case 43: goto L_80018B3C; break;
        case 44: goto L_800189D8; break;
        case 45: goto L_80018B3C; break;
        case 46: goto L_80018B3C; break;
        case 47: goto L_80018B3C; break;
        case 48: goto L_80018B3C; break;
        case 49: goto L_80018A58; break;
        case 50: goto L_80018B3C; break;
        case 51: goto L_80018B3C; break;
        case 52: goto L_80018A98; break;
        default: switch_error(__func__, 0x80018880, 0x800AF294);
    }
    // 0x80018884: nop

L_80018888:
    // 0x80018888: jal         0x8001AE64
    // 0x8001888C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_13;
    // 0x8001888C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_13:
    // 0x80018890: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018894: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018898: jal         0x8001AEC4
    // 0x8001889C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8001AEC4(rdram, ctx);
        goto after_14;
    // 0x8001889C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x800188A0: b           L_80018B40
    // 0x800188A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800188A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800188A8:
    // 0x800188A8: jal         0x8001AE64
    // 0x800188AC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_15;
    // 0x800188AC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_15:
    // 0x800188B0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800188B4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800188B8: jal         0x8001AEC4
    // 0x800188BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8001AEC4(rdram, ctx);
        goto after_16;
    // 0x800188BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_16:
    // 0x800188C0: b           L_80018B40
    // 0x800188C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800188C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800188C8:
    // 0x800188C8: jal         0x8001AE64
    // 0x800188CC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_17;
    // 0x800188CC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_17:
    // 0x800188D0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800188D4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800188D8: jal         0x8001AEC4
    // 0x800188DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8001AEC4(rdram, ctx);
        goto after_18;
    // 0x800188DC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_18:
    // 0x800188E0: b           L_80018B40
    // 0x800188E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800188E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800188E8:
    // 0x800188E8: jal         0x8001AE64
    // 0x800188EC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_19;
    // 0x800188EC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_19:
    // 0x800188F0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800188F4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800188F8: jal         0x8001AEC4
    // 0x800188FC: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    func_8001AEC4(rdram, ctx);
        goto after_20;
    // 0x800188FC: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    after_20:
    // 0x80018900: b           L_80018B40
    // 0x80018904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018904: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018908:
    // 0x80018908: jal         0x8001AE64
    // 0x8001890C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_21;
    // 0x8001890C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_21:
    // 0x80018910: b           L_80018B40
    // 0x80018914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018918:
    // 0x80018918: jal         0x8001AE64
    // 0x8001891C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_22;
    // 0x8001891C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_22:
    // 0x80018920: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018924: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018928: jal         0x8001AEC4
    // 0x8001892C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    func_8001AEC4(rdram, ctx);
        goto after_23;
    // 0x8001892C: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    after_23:
    // 0x80018930: b           L_80018B40
    // 0x80018934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018938:
    // 0x80018938: jal         0x8001AE64
    // 0x8001893C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_24;
    // 0x8001893C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_24:
    // 0x80018940: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018944: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018948: jal         0x8001AEC4
    // 0x8001894C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    func_8001AEC4(rdram, ctx);
        goto after_25;
    // 0x8001894C: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_25:
    // 0x80018950: b           L_80018B40
    // 0x80018954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018958:
    // 0x80018958: jal         0x8001AE64
    // 0x8001895C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_26;
    // 0x8001895C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_26:
    // 0x80018960: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018964: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018968: jal         0x8001AEC4
    // 0x8001896C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_8001AEC4(rdram, ctx);
        goto after_27;
    // 0x8001896C: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_27:
    // 0x80018970: b           L_80018B40
    // 0x80018974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018978:
    // 0x80018978: jal         0x8001AE64
    // 0x8001897C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_28;
    // 0x8001897C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_28:
    // 0x80018980: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018984: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018988: jal         0x8001AEC4
    // 0x8001898C: addiu       $a1, $zero, 0x405
    ctx->r5 = ADD32(0, 0X405);
    func_8001AEC4(rdram, ctx);
        goto after_29;
    // 0x8001898C: addiu       $a1, $zero, 0x405
    ctx->r5 = ADD32(0, 0X405);
    after_29:
    // 0x80018990: b           L_80018B40
    // 0x80018994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018998:
    // 0x80018998: jal         0x8001AE64
    // 0x8001899C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_30;
    // 0x8001899C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_30:
    // 0x800189A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800189A4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800189A8: jal         0x8001AEC4
    // 0x800189AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    func_8001AEC4(rdram, ctx);
        goto after_31;
    // 0x800189AC: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_31:
    // 0x800189B0: b           L_80018B40
    // 0x800189B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800189B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800189B8:
    // 0x800189B8: jal         0x80018B78
    // 0x800189BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80018B78(rdram, ctx);
        goto after_32;
    // 0x800189BC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_32:
    // 0x800189C0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800189C4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800189C8: jal         0x8001AEC4
    // 0x800189CC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    func_8001AEC4(rdram, ctx);
        goto after_33;
    // 0x800189CC: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    after_33:
    // 0x800189D0: b           L_80018B40
    // 0x800189D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800189D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800189D8:
    // 0x800189D8: jal         0x8001AE64
    // 0x800189DC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_34;
    // 0x800189DC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_34:
    // 0x800189E0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800189E4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x800189E8: jal         0x8001AEC4
    // 0x800189EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8001AEC4(rdram, ctx);
        goto after_35;
    // 0x800189EC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_35:
    // 0x800189F0: b           L_80018B40
    // 0x800189F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x800189F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800189F8:
    // 0x800189F8: jal         0x8001AE64
    // 0x800189FC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_36;
    // 0x800189FC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_36:
    // 0x80018A00: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018A04: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018A08: jal         0x8001AEC4
    // 0x80018A0C: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    func_8001AEC4(rdram, ctx);
        goto after_37;
    // 0x80018A0C: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_37:
    // 0x80018A10: b           L_80018B40
    // 0x80018A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018A14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018A18:
    // 0x80018A18: jal         0x8001AE64
    // 0x80018A1C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_8001AE64(rdram, ctx);
        goto after_38;
    // 0x80018A1C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_38:
    // 0x80018A20: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018A24: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018A28: jal         0x8001AEC4
    // 0x80018A2C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    func_8001AEC4(rdram, ctx);
        goto after_39;
    // 0x80018A2C: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_39:
    // 0x80018A30: b           L_80018B40
    // 0x80018A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018A34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018A38:
    // 0x80018A38: jal         0x8001AE64
    // 0x80018A3C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_40;
    // 0x80018A3C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_40:
    // 0x80018A40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018A44: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018A48: jal         0x8001AEC4
    // 0x80018A4C: addiu       $a1, $zero, 0x391
    ctx->r5 = ADD32(0, 0X391);
    func_8001AEC4(rdram, ctx);
        goto after_41;
    // 0x80018A4C: addiu       $a1, $zero, 0x391
    ctx->r5 = ADD32(0, 0X391);
    after_41:
    // 0x80018A50: b           L_80018B40
    // 0x80018A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018A58:
    // 0x80018A58: jal         0x8001AE64
    // 0x80018A5C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_42;
    // 0x80018A5C: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_42:
    // 0x80018A60: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018A64: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018A68: jal         0x8001AEC4
    // 0x80018A6C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    func_8001AEC4(rdram, ctx);
        goto after_43;
    // 0x80018A6C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_43:
    // 0x80018A70: b           L_80018B40
    // 0x80018A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018A78:
    // 0x80018A78: jal         0x8001AE64
    // 0x80018A7C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_8001AE64(rdram, ctx);
        goto after_44;
    // 0x80018A7C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_44:
    // 0x80018A80: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018A84: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018A88: jal         0x8001AEC4
    // 0x80018A8C: addiu       $a1, $zero, 0x17B
    ctx->r5 = ADD32(0, 0X17B);
    func_8001AEC4(rdram, ctx);
        goto after_45;
    // 0x80018A8C: addiu       $a1, $zero, 0x17B
    ctx->r5 = ADD32(0, 0X17B);
    after_45:
    // 0x80018A90: b           L_80018B40
    // 0x80018A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018A94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018A98:
    // 0x80018A98: jal         0x8001AE64
    // 0x80018A9C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    func_8001AE64(rdram, ctx);
        goto after_46;
    // 0x80018A9C: addiu       $a1, $zero, 0x4000
    ctx->r5 = ADD32(0, 0X4000);
    after_46:
    // 0x80018AA0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018AA4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018AA8: jal         0x8001AEC4
    // 0x80018AAC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    func_8001AEC4(rdram, ctx);
        goto after_47;
    // 0x80018AAC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_47:
    // 0x80018AB0: b           L_80018B40
    // 0x80018AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018AB8:
    // 0x80018AB8: jal         0x8001AE64
    // 0x80018ABC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    func_8001AE64(rdram, ctx);
        goto after_48;
    // 0x80018ABC: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_48:
    // 0x80018AC0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018AC4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018AC8: jal         0x8001AEC4
    // 0x80018ACC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    func_8001AEC4(rdram, ctx);
        goto after_49;
    // 0x80018ACC: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    after_49:
    // 0x80018AD0: b           L_80018B40
    // 0x80018AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018AD8:
    // 0x80018AD8: jal         0x80018B4C
    // 0x80018ADC: nop

    func_80018B4C(rdram, ctx);
        goto after_50;
    // 0x80018ADC: nop

    after_50:
    // 0x80018AE0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018AE4: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018AEC: jal         0x8001ADE8
    // 0x80018AF0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    func_8001ADE8(rdram, ctx);
        goto after_51;
    // 0x80018AF0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    after_51:
    // 0x80018AF4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80018AF8: lw          $a0, -0x6D70($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6D70);
    // 0x80018AFC: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x80018B00: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80018B04: sltiu       $at, $t4, 0x35
    ctx->r1 = ctx->r12 < 0X35 ? 1 : 0;
    // 0x80018B08: beq         $at, $zero, L_80018B3C
    if (ctx->r1 == 0) {
        // 0x80018B0C: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80018B3C;
    }
    // 0x80018B0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80018B10: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80018B14: addu        $at, $at, $t4
    gpr jr_addend_80018B1C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80018B18: lw          $t4, -0xC98($at)
    ctx->r12 = ADD32(ctx->r1, -0XC98);
    // 0x80018B1C: jr          $t4
    // 0x80018B20: nop

    switch (jr_addend_80018B1C >> 2) {
        case 0: goto L_80018B24; break;
        case 1: goto L_80018B24; break;
        case 2: goto L_80018B24; break;
        case 3: goto L_80018B24; break;
        case 4: goto L_80018B24; break;
        case 5: goto L_80018B24; break;
        case 6: goto L_80018B24; break;
        case 7: goto L_80018B24; break;
        case 8: goto L_80018B24; break;
        case 9: goto L_80018B24; break;
        case 10: goto L_80018B3C; break;
        case 11: goto L_80018B3C; break;
        case 12: goto L_80018B3C; break;
        case 13: goto L_80018B34; break;
        case 14: goto L_80018B3C; break;
        case 15: goto L_80018B3C; break;
        case 16: goto L_80018B24; break;
        case 17: goto L_80018B3C; break;
        case 18: goto L_80018B3C; break;
        case 19: goto L_80018B24; break;
        case 20: goto L_80018B3C; break;
        case 21: goto L_80018B3C; break;
        case 22: goto L_80018B3C; break;
        case 23: goto L_80018B3C; break;
        case 24: goto L_80018B3C; break;
        case 25: goto L_80018B3C; break;
        case 26: goto L_80018B3C; break;
        case 27: goto L_80018B3C; break;
        case 28: goto L_80018B3C; break;
        case 29: goto L_80018B3C; break;
        case 30: goto L_80018B3C; break;
        case 31: goto L_80018B3C; break;
        case 32: goto L_80018B3C; break;
        case 33: goto L_80018B3C; break;
        case 34: goto L_80018B24; break;
        case 35: goto L_80018B24; break;
        case 36: goto L_80018B34; break;
        case 37: goto L_80018B3C; break;
        case 38: goto L_80018B3C; break;
        case 39: goto L_80018B3C; break;
        case 40: goto L_80018B3C; break;
        case 41: goto L_80018B3C; break;
        case 42: goto L_80018B3C; break;
        case 43: goto L_80018B3C; break;
        case 44: goto L_80018B24; break;
        case 45: goto L_80018B3C; break;
        case 46: goto L_80018B3C; break;
        case 47: goto L_80018B3C; break;
        case 48: goto L_80018B3C; break;
        case 49: goto L_80018B24; break;
        case 50: goto L_80018B3C; break;
        case 51: goto L_80018B3C; break;
        case 52: goto L_80018B34; break;
        default: switch_error(__func__, 0x80018B1C, 0x800AF368);
    }
    // 0x80018B20: nop

L_80018B24:
    // 0x80018B24: jal         0x8001AE64
    // 0x80018B28: addiu       $a1, $zero, 0x47FF
    ctx->r5 = ADD32(0, 0X47FF);
    func_8001AE64(rdram, ctx);
        goto after_52;
    // 0x80018B28: addiu       $a1, $zero, 0x47FF
    ctx->r5 = ADD32(0, 0X47FF);
    after_52:
    // 0x80018B2C: b           L_80018B40
    // 0x80018B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80018B40;
    // 0x80018B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018B34:
    // 0x80018B34: jal         0x8001AE64
    // 0x80018B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8001AE64(rdram, ctx);
        goto after_53;
    // 0x80018B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_53:
L_80018B3C:
    // 0x80018B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80018B40:
    // 0x80018B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018B44: jr          $ra
    // 0x80018B48: nop

    return;
    // 0x80018B48: nop

;}
RECOMP_FUNC void func_804291E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804291E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804291E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804291E8: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x804291EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x804291F0: beq         $t6, $zero, L_8042922C
    if (ctx->r14 == 0) {
        // 0x804291F4: nop
    
            goto L_8042922C;
    }
    // 0x804291F4: nop

    // 0x804291F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804291FC: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80429200: jalr        $t9
    // 0x80429204: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80429204: nop

    after_0:
    // 0x80429208: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042920C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80429210: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80429214: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80429218: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042921C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80429220: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80429224: b           L_8042922C
    // 0x80429228: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042922C;
    // 0x80429228: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042922C:
    // 0x8042922C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80429230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80429234: jr          $ra
    // 0x80429238: nop

    return;
    // 0x80429238: nop

;}
RECOMP_FUNC void func_80580AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580AEC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80580AF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80580AF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80580AF8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80580AFC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80580B00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80580B04: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80580B08: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80580B0C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80580B10: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80580B14: nop

    // 0x80580B18: bc1f        L_80580B60
    if (!c1cs) {
        // 0x80580B1C: nop
    
            goto L_80580B60;
    }
    // 0x80580B1C: nop

    // 0x80580B20: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80580B24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80580B28: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80580B2C: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x80580B30: bnel        $t6, $at, L_80580B50
    if (ctx->r14 != ctx->r1) {
        // 0x80580B34: lwc1        $f6, 0x44($a0)
        ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
            goto L_80580B50;
    }
    goto skip_0;
    // 0x80580B34: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    skip_0:
    // 0x80580B38: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80580B3C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80580B40: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80580B44: jr          $ra
    // 0x80580B48: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80580B48: swc1        $f4, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f4.u32l;
    // 0x80580B4C: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
L_80580B50:
    // 0x80580B50: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80580B54: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x80580B58: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80580B5C: swc1        $f8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f8.u32l;
L_80580B60:
    // 0x80580B60: jr          $ra
    // 0x80580B64: nop

    return;
    // 0x80580B64: nop

;}
RECOMP_FUNC void func_806F2E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2E38: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806F2E3C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806F2E40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806F2E44: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806F2E48: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806F2E4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806F2E50: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806F2E54: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806F2E58: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(679, 0X1BB8) << 16);
    // 0x806F2E5C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806F2E60: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F2E64: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806F2E68: lw          $t1, 0x3138($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(679, 0X1BB8));
    // 0x806F2E6C: jr          $ra
    // 0x806F2E70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806F2E70: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80430DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80430DFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80430E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80430E04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80430E08: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80430E0C: jal         0x80430BE8
    // 0x80430E10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80430BE8(rdram, ctx);
        goto after_0;
    // 0x80430E10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430E14: jal         0x80430C44
    // 0x80430E18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80430C44(rdram, ctx);
        goto after_1;
    // 0x80430E18: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80430E1C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80430E20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80430E24: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80430E28: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80430E2C: nop

    // 0x80430E30: bc1f        L_80430E84
    if (!c1cs) {
        // 0x80430E34: nop
    
            goto L_80430E84;
    }
    // 0x80430E34: nop

    // 0x80430E38: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80430E3C: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x80430E40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80430E44: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80430E48: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80430E4C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80430E50: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80430E54: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80430E58: nop

    // 0x80430E5C: bc1f        L_80430E84
    if (!c1cs) {
        // 0x80430E60: nop
    
            goto L_80430E84;
    }
    // 0x80430E60: nop

    // 0x80430E64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80430E68: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x80430E6C: sh          $t6, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r14;
    // 0x80430E70: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80430E74: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80430E78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80430E7C: jal         0x804311BC
    // 0x80430E80: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    func_804311BC(rdram, ctx);
        goto after_2;
    // 0x80430E80: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    after_2:
L_80430E84:
    // 0x80430E84: jal         0x80430CC0
    // 0x80430E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80430CC0(rdram, ctx);
        goto after_3;
    // 0x80430E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80430E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80430E90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80430E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80430E98: jr          $ra
    // 0x80430E9C: nop

    return;
    // 0x80430E9C: nop

;}
RECOMP_FUNC void func_8001F7A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F7A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001F7AC: jr          $ra
    // 0x8001F7B0: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8001F7B0: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_806FBAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FBAE8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x806FBAEC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806FBAF0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x806FBAF4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806FBAF8: nop

    // 0x806FBAFC: bc1fl       L_806FBB2C
    if (!c1cs) {
        // 0x806FBB00: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_806FBB2C;
    }
    goto skip_0;
    // 0x806FBB00: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x806FBB04: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x806FBB08: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x806FBB0C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806FBB10: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x806FBB14: nop

    // 0x806FBB18: bc1f        L_806FBB58
    if (!c1cs) {
        // 0x806FBB1C: nop
    
            goto L_806FBB58;
    }
    // 0x806FBB1C: nop

    // 0x806FBB20: jr          $ra
    // 0x806FBB24: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x806FBB24: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x806FBB28: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_806FBB2C:
    // 0x806FBB2C: nop

    // 0x806FBB30: bc1f        L_806FBB58
    if (!c1cs) {
        // 0x806FBB34: nop
    
            goto L_806FBB58;
    }
    // 0x806FBB34: nop

    // 0x806FBB38: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x806FBB3C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x806FBB40: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806FBB44: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x806FBB48: nop

    // 0x806FBB4C: bc1f        L_806FBB58
    if (!c1cs) {
        // 0x806FBB50: nop
    
            goto L_806FBB58;
    }
    // 0x806FBB50: nop

    // 0x806FBB54: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_806FBB58:
    // 0x806FBB58: jr          $ra
    // 0x806FBB5C: nop

    return;
    // 0x806FBB5C: nop

;}
RECOMP_FUNC void func_8005C27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C27C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8005C280: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005C284: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8005C288: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8005C28C: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8005C290: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x8005C294: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8005C298: lw          $t5, 0xE4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE4);
    // 0x8005C29C: lhu         $a2, 0xDE($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0XDE);
    // 0x8005C2A0: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8005C2A4: lw          $t0, 0x1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C);
    // 0x8005C2A8: or          $a1, $sp, $zero
    ctx->r5 = ctx->r29 | 0;
    // 0x8005C2AC: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
    // 0x8005C2B0: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x8005C2B4: addiu       $a1, $a1, 0x3F
    ctx->r5 = ADD32(ctx->r5, 0X3F);
    // 0x8005C2B8: srl         $a1, $a1, 3
    ctx->r5 = S32(U32(ctx->r5) >> 3);
    // 0x8005C2BC: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x8005C2C0: lh          $a3, 0x13C($a0)
    ctx->r7 = MEM_H(ctx->r4, 0X13C);
    // 0x8005C2C4: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x8005C2C8: lw          $t8, 0xE0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE0);
    // 0x8005C2CC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x8005C2D0: addu        $t4, $t9, $a2
    ctx->r12 = ADD32(ctx->r25, ctx->r6);
    // 0x8005C2D4: lbu         $t1, 0x0($t4)
    ctx->r9 = MEM_BU(ctx->r12, 0X0);
    // 0x8005C2D8: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x8005C2DC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005C2E0: bgez        $a3, L_8005C2EC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8005C2E4: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_8005C2EC;
    }
    // 0x8005C2E4: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x8005C2E8: addiu       $at, $a3, 0x1
    ctx->r1 = ADD32(ctx->r7, 0X1);
L_8005C2EC:
    // 0x8005C2EC: sra         $a3, $at, 1
    ctx->r7 = S32(SIGNED(ctx->r1) >> 1);
    // 0x8005C2F0: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x8005C2F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8005C2F8: multu       $a3, $t5
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005C2FC: sll         $t3, $t1, 16
    ctx->r11 = S32(ctx->r9 << 16);
    // 0x8005C300: sra         $t3, $t3, 16
    ctx->r11 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8005C304: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005C308: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    // 0x8005C30C: sh          $a3, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r7;
    // 0x8005C310: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    // 0x8005C314: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8005C318: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8005C31C: sh          $a2, 0xDE($sp)
    MEM_H(0XDE, ctx->r29) = ctx->r6;
    // 0x8005C320: mflo        $t7
    ctx->r15 = lo;
    // 0x8005C324: addu        $t2, $t7, $t8
    ctx->r10 = ADD32(ctx->r15, ctx->r24);
    // 0x8005C328: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8005C32C: jal         0x8005BF50
    // 0x8005C330: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    func_8005BF50(rdram, ctx);
        goto after_0;
    // 0x8005C330: addu        $a0, $t2, $t0
    ctx->r4 = ADD32(ctx->r10, ctx->r8);
    after_0:
    // 0x8005C334: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x8005C338: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C33C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x8005C340: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8005C344: lh          $a3, 0xC2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XC2);
    // 0x8005C348: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005C34C: beq         $t6, $zero, L_8005C39C
    if (ctx->r14 == 0) {
        // 0x8005C350: addu        $a0, $t9, $t4
        ctx->r4 = ADD32(ctx->r25, ctx->r12);
            goto L_8005C39C;
    }
    // 0x8005C350: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x8005C354: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8005C358: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C35C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8005C360: lhu         $a2, 0xDE($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0XDE);
    // 0x8005C364: sh          $a3, 0xC2($sp)
    MEM_H(0XC2, ctx->r29) = ctx->r7;
    // 0x8005C368: jal         0x8005BF50
    // 0x8005C36C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_8005BF50(rdram, ctx);
        goto after_1;
    // 0x8005C36C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x8005C370: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8005C374: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x8005C378: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8005C37C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8005C380: lh          $a3, 0xC2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XC2);
    // 0x8005C384: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8005C388: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8005C38C: lhu         $a2, 0xDE($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0XDE);
    // 0x8005C390: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8005C394: jal         0x8005BF50
    // 0x8005C398: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_8005BF50(rdram, ctx);
        goto after_2;
    // 0x8005C398: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_2:
L_8005C39C:
    // 0x8005C39C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005C3A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005C3A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C3A8: sb          $t5, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r13;
    // 0x8005C3AC: jr          $ra
    // 0x8005C3B0: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8005C3B0: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_800317F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800317F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800317F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800317F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800317FC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80031804: jal         0x800310A0
    // 0x80031808: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031808: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003180C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80031810: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80031814: beq         $t7, $zero, L_80031824
    if (ctx->r15 == 0) {
        // 0x80031818: nop
    
            goto L_80031824;
    }
    // 0x80031818: nop

    // 0x8003181C: jal         0x80021A44
    // 0x80031820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021A44(rdram, ctx);
        goto after_1;
    // 0x80031820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80031824:
    // 0x80031824: jal         0x80031060
    // 0x80031828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80031060(rdram, ctx);
        goto after_2;
    // 0x80031828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003182C: beq         $v0, $zero, L_8003183C
    if (ctx->r2 == 0) {
        // 0x80031830: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003183C;
    }
    // 0x80031830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80031834: jal         0x800310D0
    // 0x80031838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_800310D0(rdram, ctx);
        goto after_3;
    // 0x80031838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
L_8003183C:
    // 0x8003183C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80031840: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80031844: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80031848: jr          $ra
    // 0x8003184C: nop

    return;
    // 0x8003184C: nop

;}
RECOMP_FUNC void func_806D0A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D0A04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D0A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D0A0C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D0A10: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x806D0A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806D0A18: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x806D0A1C: jal         0x806D099C
    // 0x806D0A20: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    func_806D099C(rdram, ctx);
        goto after_0;
    // 0x806D0A20: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D0A24: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x806D0A28: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x806D0A2C: lui         $t9, 0x806D
    ctx->r25 = S32(RELOC_HI16(607, 0X1A18) << 16);
    // 0x806D0A30: addiu       $t9, $t9, 0x11B8
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(607, 0X1A18));
    // 0x806D0A34: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x806D0A38: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x806D0A3C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806D0A40: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806D0A44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806D0A48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806D0A4C: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    // 0x806D0A50: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806D0A54: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x806D0A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D0A5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806D0A60: jr          $ra
    // 0x806D0A64: nop

    return;
    // 0x806D0A64: nop

;}
RECOMP_FUNC void func_8000102C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000102C: jr          $ra
    // 0x80001030: nop

    return;
    // 0x80001030: nop

    // 0x80001034: jr          $ra
    // 0x80001038: nop

    return;
    // 0x80001038: nop

    // 0x8000103C: jr          $ra
    // 0x80001040: nop

    return;
    // 0x80001040: nop

    // 0x80001044: jr          $ra
    // 0x80001048: nop

    return;
    // 0x80001048: nop

    // 0x8000104C: jr          $ra
    // 0x80001050: nop

    return;
    // 0x80001050: nop

    // 0x80001054: jr          $ra
    // 0x80001058: nop

    return;
    // 0x80001058: nop

    // 0x8000105C: jr          $ra
    // 0x80001060: nop

    return;
    // 0x80001060: nop

;}
RECOMP_FUNC void func_806B27FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B27FC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2800: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2804: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2808: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B280C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2810: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2814: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2818: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B281C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2820: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2824: jr          $ra
    // 0x806B2828: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2828: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042856C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042856C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80428570: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80428574: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80428578: jal         0x80427DC8
    // 0x8042857C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80427DC8(rdram, ctx);
        goto after_0;
    // 0x8042857C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80428580: bne         $v0, $zero, L_8042867C
    if (ctx->r2 != 0) {
        // 0x80428584: nop
    
            goto L_8042867C;
    }
    // 0x80428584: nop

    // 0x80428588: jal         0x8004700C
    // 0x8042858C: nop

    func_8004700C(rdram, ctx);
        goto after_1;
    // 0x8042858C: nop

    after_1:
    // 0x80428590: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80428594: jal         0x80427AC0
    // 0x80428598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427AC0(rdram, ctx);
        goto after_2;
    // 0x80428598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042859C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x804285A0: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x804285A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804285A8: jal         0x8004D618
    // 0x804285AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004D618(rdram, ctx);
        goto after_3;
    // 0x804285AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x804285B0: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x804285B4: addiu       $a2, $a2, -0x2B40
    ctx->r6 = ADD32(ctx->r6, -0X2B40);
    // 0x804285B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804285BC: jal         0x8004D618
    // 0x804285C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004D618(rdram, ctx);
        goto after_4;
    // 0x804285C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x804285C4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x804285C8: addiu       $a2, $a2, -0x2BEC
    ctx->r6 = ADD32(ctx->r6, -0X2BEC);
    // 0x804285CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804285D0: jal         0x8004D618
    // 0x804285D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004D618(rdram, ctx);
        goto after_5;
    // 0x804285D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x804285D8: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x804285DC: addiu       $a2, $a2, -0x2A94
    ctx->r6 = ADD32(ctx->r6, -0X2A94);
    // 0x804285E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804285E4: jal         0x8004D618
    // 0x804285E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8004D618(rdram, ctx);
        goto after_6;
    // 0x804285E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
    // 0x804285EC: jal         0x80428294
    // 0x804285F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80428294(rdram, ctx);
        goto after_7;
    // 0x804285F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x804285F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804285F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804285FC: jal         0x80428460
    // 0x80428600: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80428460(rdram, ctx);
        goto after_8;
    // 0x80428600: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x80428604: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80428608: bnel        $v0, $zero, L_80428624
    if (ctx->r2 != 0) {
        // 0x8042860C: lw          $t6, 0x180($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X180);
            goto L_80428624;
    }
    goto skip_0;
    // 0x8042860C: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    skip_0:
    // 0x80428610: jal         0x80427FB8
    // 0x80428614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427FB8(rdram, ctx);
        goto after_9;
    // 0x80428614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80428618: b           L_80428688
    // 0x8042861C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428688;
    // 0x8042861C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80428620: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
L_80428624:
    // 0x80428624: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80428628: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8042862C: beq         $s0, $t6, L_80428644
    if (ctx->r16 == ctx->r14) {
        // 0x80428630: nop
    
            goto L_80428644;
    }
    // 0x80428630: nop

    // 0x80428634: jal         0x80427FB8
    // 0x80428638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427FB8(rdram, ctx);
        goto after_10;
    // 0x80428638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8042863C: b           L_80428688
    // 0x80428640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428688;
    // 0x80428640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428644:
    // 0x80428644: jal         0x80047590
    // 0x80428648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80047590(rdram, ctx);
        goto after_11;
    // 0x80428648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x8042864C: beq         $v0, $zero, L_8042865C
    if (ctx->r2 == 0) {
        // 0x80428650: nop
    
            goto L_8042865C;
    }
    // 0x80428650: nop

    // 0x80428654: jal         0x80427F5C
    // 0x80428658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427F5C(rdram, ctx);
        goto after_12;
    // 0x80428658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8042865C:
    // 0x8042865C: jal         0x80427B1C
    // 0x80428660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427B1C(rdram, ctx);
        goto after_13;
    // 0x80428660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80428664: jal         0x80427C6C
    // 0x80428668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427C6C(rdram, ctx);
        goto after_14;
    // 0x80428668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8042866C: jal         0x80427A9C
    // 0x80428670: nop

    func_80427A9C(rdram, ctx);
        goto after_15;
    // 0x80428670: nop

    after_15:
    // 0x80428674: b           L_80428688
    // 0x80428678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80428688;
    // 0x80428678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042867C:
    // 0x8042867C: jal         0x80427F5C
    // 0x80428680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80427F5C(rdram, ctx);
        goto after_16;
    // 0x80428680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80428684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80428688:
    // 0x80428688: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042868C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80428690: jr          $ra
    // 0x80428694: nop

    return;
    // 0x80428694: nop

;}
RECOMP_FUNC void func_80736D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80736D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80736D88: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80736D8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80736D90: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(736, 0X39AC) << 16);
    // 0x80736D94: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80736D98: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80736D9C: addiu       $t7, $t7, -0x6BF4
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(736, 0X39AC));
    // 0x80736DA0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80736DA4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80736DA8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80736DAC: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x80736DB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80736DB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80736DB8: jal         0x80736DD0
    // 0x80736DBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80736DD0(rdram, ctx);
        goto after_0;
    // 0x80736DBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x80736DC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80736DC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80736DC8: jr          $ra
    // 0x80736DCC: nop

    return;
    // 0x80736DCC: nop

;}
RECOMP_FUNC void func_8001AB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AB70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001AB74: nop

    // 0x8001AB78: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8001AB7C: nop

    // 0x8001AB80: bc1fl       L_8001AB94
    if (!c1cs) {
        // 0x8001AB84: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8001AB94;
    }
    goto skip_0;
    // 0x8001AB84: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8001AB88: jr          $ra
    // 0x8001AB8C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    return;
    // 0x8001AB8C: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x8001AB90: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8001AB94:
    // 0x8001AB94: jr          $ra
    // 0x8001AB98: nop

    return;
    // 0x8001AB98: nop

;}
RECOMP_FUNC void func_80446938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446938: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044693C: addiu       $t6, $zero, 0xAC8
    ctx->r14 = ADD32(0, 0XAC8);
    // 0x80446940: jr          $ra
    // 0x80446944: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    return;
    // 0x80446944: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_80011D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011D1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80011D20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80011D24: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80011D28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80011D2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80011D30: addiu       $t6, $zero, 0x3F
    ctx->r14 = ADD32(0, 0X3F);
    // 0x80011D34: slti        $at, $a0, 0x296
    ctx->r1 = SIGNED(ctx->r4) < 0X296 ? 1 : 0;
    // 0x80011D38: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80011D3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011D40: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80011D44: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x80011D48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80011D4C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80011D50: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80011D54: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80011D58: bne         $at, $zero, L_80011D84
    if (ctx->r1 != 0) {
        // 0x80011D5C: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80011D84;
    }
    // 0x80011D5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80011D60: addiu       $t7, $a0, -0x3E8
    ctx->r15 = ADD32(ctx->r4, -0X3E8);
    // 0x80011D64: sltiu       $at, $t7, 0x46
    ctx->r1 = ctx->r15 < 0X46 ? 1 : 0;
    // 0x80011D68: beq         $at, $zero, L_80015C10
    if (ctx->r1 == 0) {
        // 0x80011D6C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80015C10;
    }
    // 0x80011D6C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80011D70: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011D74: addu        $at, $at, $t7
    gpr jr_addend_80011D7C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80011D78: lw          $t7, -0x2D80($at)
    ctx->r15 = ADD32(ctx->r1, -0X2D80);
    // 0x80011D7C: jr          $t7
    // 0x80011D80: nop

    switch (jr_addend_80011D7C >> 2) {
        case 0: goto L_80015698; break;
        case 1: goto L_800156AC; break;
        case 2: goto L_800156C0; break;
        case 3: goto L_800156D4; break;
        case 4: goto L_800156E8; break;
        case 5: goto L_800156FC; break;
        case 6: goto L_80015710; break;
        case 7: goto L_80015724; break;
        case 8: goto L_80015738; break;
        case 9: goto L_8001574C; break;
        case 10: goto L_80015760; break;
        case 11: goto L_80015774; break;
        case 12: goto L_80015788; break;
        case 13: goto L_8001579C; break;
        case 14: goto L_800157B0; break;
        case 15: goto L_800157C4; break;
        case 16: goto L_800157D8; break;
        case 17: goto L_800157EC; break;
        case 18: goto L_80015800; break;
        case 19: goto L_80015814; break;
        case 20: goto L_80015828; break;
        case 21: goto L_8001583C; break;
        case 22: goto L_80015850; break;
        case 23: goto L_80015864; break;
        case 24: goto L_80015878; break;
        case 25: goto L_8001588C; break;
        case 26: goto L_800158A0; break;
        case 27: goto L_800158B4; break;
        case 28: goto L_800158C8; break;
        case 29: goto L_800158DC; break;
        case 30: goto L_800158F0; break;
        case 31: goto L_80015904; break;
        case 32: goto L_80015918; break;
        case 33: goto L_8001592C; break;
        case 34: goto L_80015940; break;
        case 35: goto L_80015954; break;
        case 36: goto L_80015968; break;
        case 37: goto L_8001597C; break;
        case 38: goto L_80015990; break;
        case 39: goto L_800159A4; break;
        case 40: goto L_800159B8; break;
        case 41: goto L_800159CC; break;
        case 42: goto L_800159E0; break;
        case 43: goto L_800159F4; break;
        case 44: goto L_80015A08; break;
        case 45: goto L_80015A1C; break;
        case 46: goto L_80015A30; break;
        case 47: goto L_80015A44; break;
        case 48: goto L_80015A58; break;
        case 49: goto L_80015A6C; break;
        case 50: goto L_80015A80; break;
        case 51: goto L_80015A94; break;
        case 52: goto L_80015AA8; break;
        case 53: goto L_80015ABC; break;
        case 54: goto L_80015AD0; break;
        case 55: goto L_80015AE4; break;
        case 56: goto L_80015AF8; break;
        case 57: goto L_80015B0C; break;
        case 58: goto L_80015B20; break;
        case 59: goto L_80015B34; break;
        case 60: goto L_80015B48; break;
        case 61: goto L_80015B5C; break;
        case 62: goto L_80015B70; break;
        case 63: goto L_80015B84; break;
        case 64: goto L_80015B98; break;
        case 65: goto L_80015BAC; break;
        case 66: goto L_80015BC0; break;
        case 67: goto L_80015BD4; break;
        case 68: goto L_80015BE8; break;
        case 69: goto L_80015BFC; break;
        default: switch_error(__func__, 0x80011D7C, 0x800AD280);
    }
    // 0x80011D80: nop

L_80011D84:
    // 0x80011D84: slti        $at, $a0, 0xDB
    ctx->r1 = SIGNED(ctx->r4) < 0XDB ? 1 : 0;
    // 0x80011D88: bne         $at, $zero, L_80011DB0
    if (ctx->r1 != 0) {
        // 0x80011D8C: addiu       $t8, $a0, -0x1F4
        ctx->r24 = ADD32(ctx->r4, -0X1F4);
            goto L_80011DB0;
    }
    // 0x80011D8C: addiu       $t8, $a0, -0x1F4
    ctx->r24 = ADD32(ctx->r4, -0X1F4);
    // 0x80011D90: sltiu       $at, $t8, 0xA2
    ctx->r1 = ctx->r24 < 0XA2 ? 1 : 0;
    // 0x80011D94: beq         $at, $zero, L_80015C10
    if (ctx->r1 == 0) {
        // 0x80011D98: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80015C10;
    }
    // 0x80011D98: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80011D9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011DA0: addu        $at, $at, $t8
    gpr jr_addend_80011DA8 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80011DA4: lw          $t8, -0x2C68($at)
    ctx->r24 = ADD32(ctx->r1, -0X2C68);
    // 0x80011DA8: jr          $t8
    // 0x80011DAC: nop

    switch (jr_addend_80011DA8 >> 2) {
        case 0: goto L_800141F4; break;
        case 1: goto L_80014210; break;
        case 2: goto L_8001422C; break;
        case 3: goto L_80014248; break;
        case 4: goto L_80014260; break;
        case 5: goto L_8001427C; break;
        case 6: goto L_80014294; break;
        case 7: goto L_800142AC; break;
        case 8: goto L_800142F0; break;
        case 9: goto L_8001430C; break;
        case 10: goto L_80014324; break;
        case 11: goto L_80014340; break;
        case 12: goto L_8001435C; break;
        case 13: goto L_80014378; break;
        case 14: goto L_80014390; break;
        case 15: goto L_800143AC; break;
        case 16: goto L_800143C4; break;
        case 17: goto L_800143DC; break;
        case 18: goto L_800143F4; break;
        case 19: goto L_80014410; break;
        case 20: goto L_80014428; break;
        case 21: goto L_80014440; break;
        case 22: goto L_80014488; break;
        case 23: goto L_800144A4; break;
        case 24: goto L_80015E60; break;
        case 25: goto L_800144C0; break;
        case 26: goto L_80014508; break;
        case 27: goto L_80015E60; break;
        case 28: goto L_80015E60; break;
        case 29: goto L_80014524; break;
        case 30: goto L_800145B4; break;
        case 31: goto L_80014604; break;
        case 32: goto L_80014620; break;
        case 33: goto L_8001463C; break;
        case 34: goto L_80014654; break;
        case 35: goto L_8001466C; break;
        case 36: goto L_80014684; break;
        case 37: goto L_8001469C; break;
        case 38: goto L_800146B4; break;
        case 39: goto L_800146CC; break;
        case 40: goto L_800146E4; break;
        case 41: goto L_800146FC; break;
        case 42: goto L_80014714; break;
        case 43: goto L_80014730; break;
        case 44: goto L_8001474C; break;
        case 45: goto L_80014764; break;
        case 46: goto L_8001477C; break;
        case 47: goto L_80014798; break;
        case 48: goto L_800147B4; break;
        case 49: goto L_800147D0; break;
        case 50: goto L_800147EC; break;
        case 51: goto L_80014804; break;
        case 52: goto L_8001481C; break;
        case 53: goto L_80014834; break;
        case 54: goto L_800148A4; break;
        case 55: goto L_80014914; break;
        case 56: goto L_80014930; break;
        case 57: goto L_8001494C; break;
        case 58: goto L_80014990; break;
        case 59: goto L_800149F8; break;
        case 60: goto L_80014A10; break;
        case 61: goto L_80015E60; break;
        case 62: goto L_80014A6C; break;
        case 63: goto L_80014A88; break;
        case 64: goto L_80014AA4; break;
        case 65: goto L_80014AC0; break;
        case 66: goto L_80015E60; break;
        case 67: goto L_80015E60; break;
        case 68: goto L_80015E60; break;
        case 69: goto L_80015E60; break;
        case 70: goto L_80015E60; break;
        case 71: goto L_80014ADC; break;
        case 72: goto L_80014B0C; break;
        case 73: goto L_80014B24; break;
        case 74: goto L_80014B58; break;
        case 75: goto L_80014B74; break;
        case 76: goto L_80014B8C; break;
        case 77: goto L_80014BA4; break;
        case 78: goto L_80014C0C; break;
        case 79: goto L_80014C28; break;
        case 80: goto L_80015E60; break;
        case 81: goto L_80015E60; break;
        case 82: goto L_80014C44; break;
        case 83: goto L_80015E60; break;
        case 84: goto L_80014C5C; break;
        case 85: goto L_80014C74; break;
        case 86: goto L_80014C8C; break;
        case 87: goto L_80014CF8; break;
        case 88: goto L_80014D14; break;
        case 89: goto L_80015E60; break;
        case 90: goto L_80014D30; break;
        case 91: goto L_80015E60; break;
        case 92: goto L_80015E60; break;
        case 93: goto L_80014D4C; break;
        case 94: goto L_80014DA4; break;
        case 95: goto L_80014DC0; break;
        case 96: goto L_80014DDC; break;
        case 97: goto L_80014DF8; break;
        case 98: goto L_80014E10; break;
        case 99: goto L_80014E2C; break;
        case 100: goto L_80014E48; break;
        case 101: goto L_80014EB4; break;
        case 102: goto L_80014ED0; break;
        case 103: goto L_80014EEC; break;
        case 104: goto L_80014F08; break;
        case 105: goto L_80014F24; break;
        case 106: goto L_80014F40; break;
        case 107: goto L_80014F5C; break;
        case 108: goto L_80014F78; break;
        case 109: goto L_80014FFC; break;
        case 110: goto L_80015018; break;
        case 111: goto L_80015034; break;
        case 112: goto L_80015050; break;
        case 113: goto L_80015068; break;
        case 114: goto L_80015098; break;
        case 115: goto L_800150B0; break;
        case 116: goto L_800150C8; break;
        case 117: goto L_800150E0; break;
        case 118: goto L_80015148; break;
        case 119: goto L_80015164; break;
        case 120: goto L_80015180; break;
        case 121: goto L_8001519C; break;
        case 122: goto L_800151B8; break;
        case 123: goto L_800151D4; break;
        case 124: goto L_800151F0; break;
        case 125: goto L_8001520C; break;
        case 126: goto L_80015278; break;
        case 127: goto L_80015294; break;
        case 128: goto L_800152B0; break;
        case 129: goto L_800152E4; break;
        case 130: goto L_800152FC; break;
        case 131: goto L_80015318; break;
        case 132: goto L_80015334; break;
        case 133: goto L_80015350; break;
        case 134: goto L_80015368; break;
        case 135: goto L_80015384; break;
        case 136: goto L_8001539C; break;
        case 137: goto L_800153B8; break;
        case 138: goto L_800153D4; break;
        case 139: goto L_80015408; break;
        case 140: goto L_80015420; break;
        case 141: goto L_80015438; break;
        case 142: goto L_80015450; break;
        case 143: goto L_8001546C; break;
        case 144: goto L_80015484; break;
        case 145: goto L_8001549C; break;
        case 146: goto L_80015508; break;
        case 147: goto L_80015520; break;
        case 148: goto L_8001553C; break;
        case 149: goto L_80015558; break;
        case 150: goto L_80015570; break;
        case 151: goto L_80015588; break;
        case 152: goto L_800155B0; break;
        case 153: goto L_800155C8; break;
        case 154: goto L_800155E0; break;
        case 155: goto L_800155F8; break;
        case 156: goto L_80015610; break;
        case 157: goto L_80015628; break;
        case 158: goto L_80015644; break;
        case 159: goto L_80015660; break;
        case 160: goto L_8001567C; break;
        case 161: goto L_80015E60; break;
        default: switch_error(__func__, 0x80011DA8, 0x800AD398);
    }
    // 0x80011DAC: nop

L_80011DB0:
    // 0x80011DB0: sltiu       $at, $a0, 0xDB
    ctx->r1 = ctx->r4 < 0XDB ? 1 : 0;
    // 0x80011DB4: beq         $at, $zero, L_80015C10
    if (ctx->r1 == 0) {
        // 0x80011DB8: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80015C10;
    }
    // 0x80011DB8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x80011DBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011DC0: addu        $at, $at, $t9
    gpr jr_addend_80011DC8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80011DC4: lw          $t9, -0x29E0($at)
    ctx->r25 = ADD32(ctx->r1, -0X29E0);
    // 0x80011DC8: jr          $t9
    // 0x80011DCC: nop

    switch (jr_addend_80011DC8 >> 2) {
        case 0: goto L_80015E60; break;
        case 1: goto L_80011DD0; break;
        case 2: goto L_80011E94; break;
        case 3: goto L_80011F34; break;
        case 4: goto L_80011FD4; break;
        case 5: goto L_8001208C; break;
        case 6: goto L_800120AC; break;
        case 7: goto L_800120C8; break;
        case 8: goto L_80012128; break;
        case 9: goto L_80012188; break;
        case 10: goto L_800121A8; break;
        case 11: goto L_800121D4; break;
        case 12: goto L_80012200; break;
        case 13: goto L_8001223C; break;
        case 14: goto L_80012254; break;
        case 15: goto L_80012270; break;
        case 16: goto L_800122F0; break;
        case 17: goto L_8001230C; break;
        case 18: goto L_8001232C; break;
        case 19: goto L_80012380; break;
        case 20: goto L_80015E60; break;
        case 21: goto L_800123A0; break;
        case 22: goto L_800123B8; break;
        case 23: goto L_800123D4; break;
        case 24: goto L_800123F0; break;
        case 25: goto L_80012408; break;
        case 26: goto L_80012428; break;
        case 27: goto L_80012448; break;
        case 28: goto L_80012460; break;
        case 29: goto L_800124BC; break;
        case 30: goto L_8001250C; break;
        case 31: goto L_80015E60; break;
        case 32: goto L_8001256C; break;
        case 33: goto L_80012588; break;
        case 34: goto L_800125A4; break;
        case 35: goto L_800125C0; break;
        case 36: goto L_800125DC; break;
        case 37: goto L_80012620; break;
        case 38: goto L_8001263C; break;
        case 39: goto L_80012658; break;
        case 40: goto L_8001268C; break;
        case 41: goto L_800126A4; break;
        case 42: goto L_800126BC; break;
        case 43: goto L_800126D8; break;
        case 44: goto L_800126F4; break;
        case 45: goto L_80012710; break;
        case 46: goto L_80012774; break;
        case 47: goto L_800127D8; break;
        case 48: goto L_800127F4; break;
        case 49: goto L_80012810; break;
        case 50: goto L_80012894; break;
        case 51: goto L_800128B0; break;
        case 52: goto L_800128CC; break;
        case 53: goto L_800128E8; break;
        case 54: goto L_80012900; break;
        case 55: goto L_8001291C; break;
        case 56: goto L_80012938; break;
        case 57: goto L_80012950; break;
        case 58: goto L_80012968; break;
        case 59: goto L_80012980; break;
        case 60: goto L_80012998; break;
        case 61: goto L_800129B4; break;
        case 62: goto L_80012A1C; break;
        case 63: goto L_80012A34; break;
        case 64: goto L_80012A50; break;
        case 65: goto L_80012A6C; break;
        case 66: goto L_80012A88; break;
        case 67: goto L_80012AA4; break;
        case 68: goto L_80012AC0; break;
        case 69: goto L_80012AD8; break;
        case 70: goto L_80012AF4; break;
        case 71: goto L_80012B10; break;
        case 72: goto L_80012B2C; break;
        case 73: goto L_80012B48; break;
        case 74: goto L_80012B64; break;
        case 75: goto L_80012B80; break;
        case 76: goto L_80012B9C; break;
        case 77: goto L_80012BB8; break;
        case 78: goto L_80012BD4; break;
        case 79: goto L_80012BF0; break;
        case 80: goto L_80012C0C; break;
        case 81: goto L_80012C34; break;
        case 82: goto L_80012C58; break;
        case 83: goto L_80012C74; break;
        case 84: goto L_80012C90; break;
        case 85: goto L_80012CA8; break;
        case 86: goto L_80012CC4; break;
        case 87: goto L_80012D74; break;
        case 88: goto L_80012D8C; break;
        case 89: goto L_80012DA4; break;
        case 90: goto L_80012DC0; break;
        case 91: goto L_80012DDC; break;
        case 92: goto L_80012DF8; break;
        case 93: goto L_80012E54; break;
        case 94: goto L_80012E70; break;
        case 95: goto L_80012E8C; break;
        case 96: goto L_80012EA8; break;
        case 97: goto L_80012EF0; break;
        case 98: goto L_80012F0C; break;
        case 99: goto L_80012F28; break;
        case 100: goto L_80012F40; break;
        case 101: goto L_80012F5C; break;
        case 102: goto L_80012F78; break;
        case 103: goto L_80012F94; break;
        case 104: goto L_80012FB0; break;
        case 105: goto L_80012FCC; break;
        case 106: goto L_80012FE8; break;
        case 107: goto L_80013004; break;
        case 108: goto L_80013020; break;
        case 109: goto L_8001303C; break;
        case 110: goto L_80013058; break;
        case 111: goto L_80013074; break;
        case 112: goto L_80013090; break;
        case 113: goto L_800130A8; break;
        case 114: goto L_800130C4; break;
        case 115: goto L_800130E0; break;
        case 116: goto L_800130FC; break;
        case 117: goto L_80013118; break;
        case 118: goto L_80013130; break;
        case 119: goto L_800131E0; break;
        case 120: goto L_800131F8; break;
        case 121: goto L_80013214; break;
        case 122: goto L_80013234; break;
        case 123: goto L_80013250; break;
        case 124: goto L_8001326C; break;
        case 125: goto L_80013288; break;
        case 126: goto L_800132A4; break;
        case 127: goto L_800132C0; break;
        case 128: goto L_800132D8; break;
        case 129: goto L_800132F0; break;
        case 130: goto L_80013368; break;
        case 131: goto L_800133C4; break;
        case 132: goto L_800133DC; break;
        case 133: goto L_800133F4; break;
        case 134: goto L_80013414; break;
        case 135: goto L_80013430; break;
        case 136: goto L_8001344C; break;
        case 137: goto L_80013464; break;
        case 138: goto L_8001347C; break;
        case 139: goto L_80013494; break;
        case 140: goto L_800134AC; break;
        case 141: goto L_800134D8; break;
        case 142: goto L_800134F4; break;
        case 143: goto L_80013510; break;
        case 144: goto L_8001352C; break;
        case 145: goto L_80013548; break;
        case 146: goto L_80013564; break;
        case 147: goto L_80013580; break;
        case 148: goto L_8001359C; break;
        case 149: goto L_80013604; break;
        case 150: goto L_80013620; break;
        case 151: goto L_8001363C; break;
        case 152: goto L_80013680; break;
        case 153: goto L_800136C4; break;
        case 154: goto L_80013708; break;
        case 155: goto L_8001374C; break;
        case 156: goto L_80013790; break;
        case 157: goto L_800137D4; break;
        case 158: goto L_800137F0; break;
        case 159: goto L_8001380C; break;
        case 160: goto L_80013828; break;
        case 161: goto L_80013844; break;
        case 162: goto L_8001386C; break;
        case 163: goto L_80013884; break;
        case 164: goto L_8001389C; break;
        case 165: goto L_800138B4; break;
        case 166: goto L_800138FC; break;
        case 167: goto L_80013918; break;
        case 168: goto L_80013934; break;
        case 169: goto L_80013988; break;
        case 170: goto L_800139A0; break;
        case 171: goto L_800139BC; break;
        case 172: goto L_800139D8; break;
        case 173: goto L_800139F4; break;
        case 174: goto L_80013A0C; break;
        case 175: goto L_80013A28; break;
        case 176: goto L_80013A84; break;
        case 177: goto L_80013AAC; break;
        case 178: goto L_80013AC8; break;
        case 179: goto L_80013B40; break;
        case 180: goto L_80013B5C; break;
        case 181: goto L_80013BE4; break;
        case 182: goto L_80013BFC; break;
        case 183: goto L_80013C18; break;
        case 184: goto L_80013C40; break;
        case 185: goto L_80013C5C; break;
        case 186: goto L_80013C78; break;
        case 187: goto L_80013C94; break;
        case 188: goto L_80015E60; break;
        case 189: goto L_80013CA8; break;
        case 190: goto L_80013CF8; break;
        case 191: goto L_80013D10; break;
        case 192: goto L_80013D28; break;
        case 193: goto L_80013D40; break;
        case 194: goto L_80013D5C; break;
        case 195: goto L_80013D74; break;
        case 196: goto L_80013D8C; break;
        case 197: goto L_80013DA4; break;
        case 198: goto L_80013DBC; break;
        case 199: goto L_80013DD8; break;
        case 200: goto L_80013E0C; break;
        case 201: goto L_80013E28; break;
        case 202: goto L_80013E44; break;
        case 203: goto L_80013E60; break;
        case 204: goto L_80013E7C; break;
        case 205: goto L_80013E98; break;
        case 206: goto L_80013EB0; break;
        case 207: goto L_80013EC8; break;
        case 208: goto L_80013EE4; break;
        case 209: goto L_80013F18; break;
        case 210: goto L_80013F34; break;
        case 211: goto L_80013F80; break;
        case 212: goto L_80013FCC; break;
        case 213: goto L_80014048; break;
        case 214: goto L_8001416C; break;
        case 215: goto L_80014188; break;
        case 216: goto L_800141A4; break;
        case 217: goto L_800141C0; break;
        case 218: goto L_800141D8; break;
        default: switch_error(__func__, 0x80011DC8, 0x800AD620);
    }
    // 0x80011DCC: nop

L_80011DD0:
    // 0x80011DD0: lw          $t3, 0x8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X8);
    // 0x80011DD4: sltiu       $at, $t3, 0xD
    ctx->r1 = ctx->r11 < 0XD ? 1 : 0;
    // 0x80011DD8: beq         $at, $zero, L_80011DF4
    if (ctx->r1 == 0) {
        // 0x80011DDC: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80011DF4;
    }
    // 0x80011DDC: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80011DE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011DE4: addu        $at, $at, $t3
    gpr jr_addend_80011DEC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80011DE8: lw          $t3, -0x2674($at)
    ctx->r11 = ADD32(ctx->r1, -0X2674);
    // 0x80011DEC: jr          $t3
    // 0x80011DF0: nop

    switch (jr_addend_80011DEC >> 2) {
        case 0: goto L_80015E60; break;
        case 1: goto L_80011DF4; break;
        case 2: goto L_80011DFC; break;
        case 3: goto L_80011E04; break;
        case 4: goto L_80011E0C; break;
        case 5: goto L_80011E14; break;
        case 6: goto L_80011E1C; break;
        case 7: goto L_80011E24; break;
        case 8: goto L_80011E2C; break;
        case 9: goto L_80011E5C; break;
        case 10: goto L_80011E34; break;
        case 11: goto L_80011E54; break;
        case 12: goto L_80011DF4; break;
        default: switch_error(__func__, 0x80011DEC, 0x800AD98C);
    }
    // 0x80011DF0: nop

L_80011DF4:
    // 0x80011DF4: b           L_80011E7C
    // 0x80011DF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80011E7C;
    // 0x80011DF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80011DFC:
    // 0x80011DFC: b           L_80011E7C
    // 0x80011E00: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80011E7C;
    // 0x80011E00: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80011E04:
    // 0x80011E04: b           L_80011E7C
    // 0x80011E08: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
        goto L_80011E7C;
    // 0x80011E08: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80011E0C:
    // 0x80011E0C: b           L_80011E7C
    // 0x80011E10: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80011E7C;
    // 0x80011E10: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80011E14:
    // 0x80011E14: b           L_80011E7C
    // 0x80011E18: addiu       $s0, $zero, 0x7A
    ctx->r16 = ADD32(0, 0X7A);
        goto L_80011E7C;
    // 0x80011E18: addiu       $s0, $zero, 0x7A
    ctx->r16 = ADD32(0, 0X7A);
L_80011E1C:
    // 0x80011E1C: b           L_80011E7C
    // 0x80011E20: addiu       $s0, $zero, 0xBB
    ctx->r16 = ADD32(0, 0XBB);
        goto L_80011E7C;
    // 0x80011E20: addiu       $s0, $zero, 0xBB
    ctx->r16 = ADD32(0, 0XBB);
L_80011E24:
    // 0x80011E24: b           L_80011E7C
    // 0x80011E28: addiu       $s0, $zero, 0xD8
    ctx->r16 = ADD32(0, 0XD8);
        goto L_80011E7C;
    // 0x80011E28: addiu       $s0, $zero, 0xD8
    ctx->r16 = ADD32(0, 0XD8);
L_80011E2C:
    // 0x80011E2C: b           L_80011E7C
    // 0x80011E30: addiu       $s0, $zero, 0xDB
    ctx->r16 = ADD32(0, 0XDB);
        goto L_80011E7C;
    // 0x80011E30: addiu       $s0, $zero, 0xDB
    ctx->r16 = ADD32(0, 0XDB);
L_80011E34:
    // 0x80011E34: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011E38: ldc1        $f6, -0x2640($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2640);
    // 0x80011E3C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80011E40: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80011E44: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80011E48: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80011E4C: b           L_80011E7C
    // 0x80011E50: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
        goto L_80011E7C;
    // 0x80011E50: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_80011E54:
    // 0x80011E54: b           L_80011E7C
    // 0x80011E58: addiu       $s0, $zero, 0x1F7
    ctx->r16 = ADD32(0, 0X1F7);
        goto L_80011E7C;
    // 0x80011E58: addiu       $s0, $zero, 0x1F7
    ctx->r16 = ADD32(0, 0X1F7);
L_80011E5C:
    // 0x80011E5C: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80011E60: lw          $t4, 0x6BA4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6BA4);
    // 0x80011E64: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80011E68: beql        $t5, $zero, L_80011E7C
    if (ctx->r13 == 0) {
        // 0x80011E6C: addiu       $s0, $zero, 0x14B
        ctx->r16 = ADD32(0, 0X14B);
            goto L_80011E7C;
    }
    goto skip_0;
    // 0x80011E6C: addiu       $s0, $zero, 0x14B
    ctx->r16 = ADD32(0, 0X14B);
    skip_0:
    // 0x80011E70: b           L_80011E7C
    // 0x80011E74: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
        goto L_80011E7C;
    // 0x80011E74: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
    // 0x80011E78: addiu       $s0, $zero, 0x14B
    ctx->r16 = ADD32(0, 0X14B);
L_80011E7C:
    // 0x80011E7C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80011E80: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80011E84: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80011E88: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80011E8C: b           L_80015C10
    // 0x80011E90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80011E90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011E94:
    // 0x80011E94: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x80011E98: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x80011E9C: beq         $at, $zero, L_80011F1C
    if (ctx->r1 == 0) {
        // 0x80011EA0: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80011F1C;
    }
    // 0x80011EA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80011EA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011EA8: addu        $at, $at, $t8
    gpr jr_addend_80011EB0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80011EAC: lw          $t8, -0x2630($at)
    ctx->r24 = ADD32(ctx->r1, -0X2630);
    // 0x80011EB0: jr          $t8
    // 0x80011EB4: nop

    switch (jr_addend_80011EB0 >> 2) {
        case 0: goto L_80015E60; break;
        case 1: goto L_80011EB8; break;
        case 2: goto L_80011EC0; break;
        case 3: goto L_80011EC8; break;
        case 4: goto L_80011ED0; break;
        case 5: goto L_80011ED8; break;
        case 6: goto L_80011EE0; break;
        case 7: goto L_80011EE8; break;
        case 8: goto L_80011EF0; break;
        case 9: goto L_80011F1C; break;
        case 10: goto L_80011EF8; break;
        case 11: goto L_80011F18; break;
        case 12: goto L_80011EB8; break;
        default: switch_error(__func__, 0x80011EB0, 0x800AD9D0);
    }
    // 0x80011EB4: nop

L_80011EB8:
    // 0x80011EB8: b           L_80011F1C
    // 0x80011EBC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
        goto L_80011F1C;
    // 0x80011EBC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
L_80011EC0:
    // 0x80011EC0: b           L_80011F1C
    // 0x80011EC4: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
        goto L_80011F1C;
    // 0x80011EC4: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
L_80011EC8:
    // 0x80011EC8: b           L_80011F1C
    // 0x80011ECC: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
        goto L_80011F1C;
    // 0x80011ECC: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_80011ED0:
    // 0x80011ED0: b           L_80011F1C
    // 0x80011ED4: addiu       $s0, $zero, 0x61
    ctx->r16 = ADD32(0, 0X61);
        goto L_80011F1C;
    // 0x80011ED4: addiu       $s0, $zero, 0x61
    ctx->r16 = ADD32(0, 0X61);
L_80011ED8:
    // 0x80011ED8: b           L_80011F1C
    // 0x80011EDC: addiu       $s0, $zero, 0x7B
    ctx->r16 = ADD32(0, 0X7B);
        goto L_80011F1C;
    // 0x80011EDC: addiu       $s0, $zero, 0x7B
    ctx->r16 = ADD32(0, 0X7B);
L_80011EE0:
    // 0x80011EE0: b           L_80011F1C
    // 0x80011EE4: addiu       $s0, $zero, 0xBC
    ctx->r16 = ADD32(0, 0XBC);
        goto L_80011F1C;
    // 0x80011EE4: addiu       $s0, $zero, 0xBC
    ctx->r16 = ADD32(0, 0XBC);
L_80011EE8:
    // 0x80011EE8: b           L_80011F1C
    // 0x80011EEC: addiu       $s0, $zero, 0xD9
    ctx->r16 = ADD32(0, 0XD9);
        goto L_80011F1C;
    // 0x80011EEC: addiu       $s0, $zero, 0xD9
    ctx->r16 = ADD32(0, 0XD9);
L_80011EF0:
    // 0x80011EF0: b           L_80011F1C
    // 0x80011EF4: addiu       $s0, $zero, 0xDC
    ctx->r16 = ADD32(0, 0XDC);
        goto L_80011F1C;
    // 0x80011EF4: addiu       $s0, $zero, 0xDC
    ctx->r16 = ADD32(0, 0XDC);
L_80011EF8:
    // 0x80011EF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011EFC: ldc1        $f18, -0x25F8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X25F8);
    // 0x80011F00: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80011F04: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80011F08: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80011F0C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80011F10: b           L_80011F1C
    // 0x80011F14: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
        goto L_80011F1C;
    // 0x80011F14: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80011F18:
    // 0x80011F18: addiu       $s0, $zero, 0x1F8
    ctx->r16 = ADD32(0, 0X1F8);
L_80011F1C:
    // 0x80011F1C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80011F20: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80011F24: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80011F28: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80011F2C: b           L_80015C10
    // 0x80011F30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80011F30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011F34:
    // 0x80011F34: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x80011F38: sltiu       $at, $t4, 0xD
    ctx->r1 = ctx->r12 < 0XD ? 1 : 0;
    // 0x80011F3C: beq         $at, $zero, L_80011FBC
    if (ctx->r1 == 0) {
        // 0x80011F40: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80011FBC;
    }
    // 0x80011F40: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80011F44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011F48: addu        $at, $at, $t4
    gpr jr_addend_80011F50 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80011F4C: lw          $t4, -0x25E8($at)
    ctx->r12 = ADD32(ctx->r1, -0X25E8);
    // 0x80011F50: jr          $t4
    // 0x80011F54: nop

    switch (jr_addend_80011F50 >> 2) {
        case 0: goto L_80015E60; break;
        case 1: goto L_80011F58; break;
        case 2: goto L_80011F60; break;
        case 3: goto L_80011F68; break;
        case 4: goto L_80011F70; break;
        case 5: goto L_80011F78; break;
        case 6: goto L_80011F80; break;
        case 7: goto L_80011F88; break;
        case 8: goto L_80011F90; break;
        case 9: goto L_80011FBC; break;
        case 10: goto L_80011F98; break;
        case 11: goto L_80011FB8; break;
        case 12: goto L_80011F58; break;
        default: switch_error(__func__, 0x80011F50, 0x800ADA18);
    }
    // 0x80011F54: nop

L_80011F58:
    // 0x80011F58: b           L_80011FBC
    // 0x80011F5C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80011FBC;
    // 0x80011F5C: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011F60:
    // 0x80011F60: b           L_80011FBC
    // 0x80011F64: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
        goto L_80011FBC;
    // 0x80011F64: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
L_80011F68:
    // 0x80011F68: b           L_80011FBC
    // 0x80011F6C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
        goto L_80011FBC;
    // 0x80011F6C: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
L_80011F70:
    // 0x80011F70: b           L_80011FBC
    // 0x80011F74: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
        goto L_80011FBC;
    // 0x80011F74: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80011F78:
    // 0x80011F78: b           L_80011FBC
    // 0x80011F7C: addiu       $s0, $zero, 0x7A
    ctx->r16 = ADD32(0, 0X7A);
        goto L_80011FBC;
    // 0x80011F7C: addiu       $s0, $zero, 0x7A
    ctx->r16 = ADD32(0, 0X7A);
L_80011F80:
    // 0x80011F80: b           L_80011FBC
    // 0x80011F84: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
        goto L_80011FBC;
    // 0x80011F84: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011F88:
    // 0x80011F88: b           L_80011FBC
    // 0x80011F8C: addiu       $s0, $zero, 0xDA
    ctx->r16 = ADD32(0, 0XDA);
        goto L_80011FBC;
    // 0x80011F8C: addiu       $s0, $zero, 0xDA
    ctx->r16 = ADD32(0, 0XDA);
L_80011F90:
    // 0x80011F90: b           L_80011FBC
    // 0x80011F94: addiu       $s0, $zero, 0xDD
    ctx->r16 = ADD32(0, 0XDD);
        goto L_80011FBC;
    // 0x80011F94: addiu       $s0, $zero, 0xDD
    ctx->r16 = ADD32(0, 0XDD);
L_80011F98:
    // 0x80011F98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80011F9C: ldc1        $f10, -0x25B0($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X25B0);
    // 0x80011FA0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80011FA4: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80011FA8: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80011FAC: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80011FB0: b           L_80011FBC
    // 0x80011FB4: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
        goto L_80011FBC;
    // 0x80011FB4: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_80011FB8:
    // 0x80011FB8: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_80011FBC:
    // 0x80011FBC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80011FC0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80011FC4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80011FC8: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80011FCC: b           L_80015C10
    // 0x80011FD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80011FD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011FD4:
    // 0x80011FD4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80011FD8: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80011FDC: beq         $v0, $zero, L_80011FF0
    if (ctx->r2 == 0) {
        // 0x80011FE0: nop
    
            goto L_80011FF0;
    }
    // 0x80011FE0: nop

    // 0x80011FE4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80011FE8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80011FEC: beq         $t7, $at, L_8001200C
    if (ctx->r15 == ctx->r1) {
        // 0x80011FF0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8001200C;
    }
L_80011FF0:
    // 0x80011FF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80011FF4: lw          $v0, -0x6D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D6C);
    // 0x80011FF8: beq         $v0, $zero, L_80012028
    if (ctx->r2 == 0) {
        // 0x80011FFC: nop
    
            goto L_80012028;
    }
    // 0x80011FFC: nop

    // 0x80012000: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80012004: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80012008: bne         $t8, $at, L_80012028
    if (ctx->r24 != ctx->r1) {
        // 0x8001200C: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80012028;
    }
L_8001200C:
    // 0x8001200C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012010: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80012014: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012018: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8001201C: addiu       $s0, $zero, 0x99
    ctx->r16 = ADD32(0, 0X99);
    // 0x80012020: b           L_80012080
    // 0x80012024: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80012080;
    // 0x80012024: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80012028:
    // 0x80012028: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8001202C: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x80012030: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012034: divu        $zero, $v0, $at
    lo = S32(U32(ctx->r2) / U32(ctx->r1)); hi = S32(U32(ctx->r2) % U32(ctx->r1));
    // 0x80012038: mfhi        $v0
    ctx->r2 = hi;
    // 0x8001203C: beq         $v0, $zero, L_8001205C
    if (ctx->r2 == 0) {
        // 0x80012040: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001205C;
    }
    // 0x80012040: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012044: beq         $v0, $at, L_80012064
    if (ctx->r2 == ctx->r1) {
        // 0x80012048: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012064;
    }
    // 0x80012048: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001204C: beql        $v0, $at, L_80012070
    if (ctx->r2 == ctx->r1) {
        // 0x80012050: addiu       $s0, $zero, 0x179
        ctx->r16 = ADD32(0, 0X179);
            goto L_80012070;
    }
    goto skip_1;
    // 0x80012050: addiu       $s0, $zero, 0x179
    ctx->r16 = ADD32(0, 0X179);
    skip_1:
    // 0x80012054: b           L_80012074
    // 0x80012058: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
        goto L_80012074;
    // 0x80012058: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_8001205C:
    // 0x8001205C: b           L_80012070
    // 0x80012060: addiu       $s0, $zero, 0x177
    ctx->r16 = ADD32(0, 0X177);
        goto L_80012070;
    // 0x80012060: addiu       $s0, $zero, 0x177
    ctx->r16 = ADD32(0, 0X177);
L_80012064:
    // 0x80012064: b           L_80012070
    // 0x80012068: addiu       $s0, $zero, 0x178
    ctx->r16 = ADD32(0, 0X178);
        goto L_80012070;
    // 0x80012068: addiu       $s0, $zero, 0x178
    ctx->r16 = ADD32(0, 0X178);
    // 0x8001206C: addiu       $s0, $zero, 0x179
    ctx->r16 = ADD32(0, 0X179);
L_80012070:
    // 0x80012070: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80012074:
    // 0x80012074: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80012078: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001207C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
L_80012080:
    // 0x80012080: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80012084: b           L_80015C10
    // 0x80012088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012088: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001208C:
    // 0x8001208C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012090: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80012094: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012098: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8001209C: addiu       $s0, $zero, 0x1B0
    ctx->r16 = ADD32(0, 0X1B0);
    // 0x800120A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800120A4: b           L_80015C10
    // 0x800120A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800120A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800120AC:
    // 0x800120AC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800120B0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800120B4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800120B8: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800120BC: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x800120C0: b           L_80015C10
    // 0x800120C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800120C4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800120C8:
    // 0x800120C8: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800120CC: lbu         $t3, -0x6D78($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X6D78);
    // 0x800120D0: bnel        $t3, $zero, L_80015E64
    if (ctx->r11 != 0) {
        // 0x800120D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015E64;
    }
    goto skip_2;
    // 0x800120D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800120D8: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x800120DC: beq         $v0, $zero, L_800120FC
    if (ctx->r2 == 0) {
        // 0x800120E0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800120FC;
    }
    // 0x800120E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800120E4: beq         $v0, $at, L_80012104
    if (ctx->r2 == ctx->r1) {
        // 0x800120E8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012104;
    }
    // 0x800120E8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800120EC: beql        $v0, $at, L_80012110
    if (ctx->r2 == ctx->r1) {
        // 0x800120F0: addiu       $s0, $zero, 0x26
        ctx->r16 = ADD32(0, 0X26);
            goto L_80012110;
    }
    goto skip_3;
    // 0x800120F0: addiu       $s0, $zero, 0x26
    ctx->r16 = ADD32(0, 0X26);
    skip_3:
    // 0x800120F4: b           L_80012114
    // 0x800120F8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
        goto L_80012114;
    // 0x800120F8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_800120FC:
    // 0x800120FC: b           L_80012110
    // 0x80012100: addiu       $s0, $zero, 0x24
    ctx->r16 = ADD32(0, 0X24);
        goto L_80012110;
    // 0x80012100: addiu       $s0, $zero, 0x24
    ctx->r16 = ADD32(0, 0X24);
L_80012104:
    // 0x80012104: b           L_80012110
    // 0x80012108: addiu       $s0, $zero, 0x25
    ctx->r16 = ADD32(0, 0X25);
        goto L_80012110;
    // 0x80012108: addiu       $s0, $zero, 0x25
    ctx->r16 = ADD32(0, 0X25);
    // 0x8001210C: addiu       $s0, $zero, 0x26
    ctx->r16 = ADD32(0, 0X26);
L_80012110:
    // 0x80012110: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
L_80012114:
    // 0x80012114: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80012118: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001211C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012120: b           L_80015C10
    // 0x80012124: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012124: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012128:
    // 0x80012128: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001212C: lbu         $t6, -0x6D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D78);
    // 0x80012130: bnel        $t6, $zero, L_80015E64
    if (ctx->r14 != 0) {
        // 0x80012134: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015E64;
    }
    goto skip_4;
    // 0x80012134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80012138: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8001213C: beq         $v0, $zero, L_8001215C
    if (ctx->r2 == 0) {
        // 0x80012140: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001215C;
    }
    // 0x80012140: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012144: beq         $v0, $at, L_80012164
    if (ctx->r2 == ctx->r1) {
        // 0x80012148: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012164;
    }
    // 0x80012148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001214C: beql        $v0, $at, L_80012170
    if (ctx->r2 == ctx->r1) {
        // 0x80012150: addiu       $s0, $zero, 0x29
        ctx->r16 = ADD32(0, 0X29);
            goto L_80012170;
    }
    goto skip_5;
    // 0x80012150: addiu       $s0, $zero, 0x29
    ctx->r16 = ADD32(0, 0X29);
    skip_5:
    // 0x80012154: b           L_80012174
    // 0x80012158: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
        goto L_80012174;
    // 0x80012158: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
L_8001215C:
    // 0x8001215C: b           L_80012170
    // 0x80012160: addiu       $s0, $zero, 0x27
    ctx->r16 = ADD32(0, 0X27);
        goto L_80012170;
    // 0x80012160: addiu       $s0, $zero, 0x27
    ctx->r16 = ADD32(0, 0X27);
L_80012164:
    // 0x80012164: b           L_80012170
    // 0x80012168: addiu       $s0, $zero, 0x28
    ctx->r16 = ADD32(0, 0X28);
        goto L_80012170;
    // 0x80012168: addiu       $s0, $zero, 0x28
    ctx->r16 = ADD32(0, 0X28);
    // 0x8001216C: addiu       $s0, $zero, 0x29
    ctx->r16 = ADD32(0, 0X29);
L_80012170:
    // 0x80012170: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
L_80012174:
    // 0x80012174: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80012178: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001217C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012180: b           L_80015C10
    // 0x80012184: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012184: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012188:
    // 0x80012188: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8001218C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80012190: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012194: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012198: addiu       $s0, $zero, 0x2C
    ctx->r16 = ADD32(0, 0X2C);
    // 0x8001219C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800121A0: b           L_80015C10
    // 0x800121A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800121A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800121A8:
    // 0x800121A8: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800121AC: lbu         $t4, -0x6D78($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6D78);
    // 0x800121B0: bne         $t4, $zero, L_80015E60
    if (ctx->r12 != 0) {
        // 0x800121B4: addiu       $t5, $zero, 0x4
        ctx->r13 = ADD32(0, 0X4);
            goto L_80015E60;
    }
    // 0x800121B4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800121B8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800121BC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800121C0: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800121C4: addiu       $s0, $zero, 0x2A
    ctx->r16 = ADD32(0, 0X2A);
    // 0x800121C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800121CC: b           L_80015C10
    // 0x800121D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800121D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800121D4:
    // 0x800121D4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800121D8: lbu         $t7, -0x6D78($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6D78);
    // 0x800121DC: bne         $t7, $zero, L_80015E60
    if (ctx->r15 != 0) {
        // 0x800121E0: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_80015E60;
    }
    // 0x800121E0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800121E4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800121E8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800121EC: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800121F0: addiu       $s0, $zero, 0x2B
    ctx->r16 = ADD32(0, 0X2B);
    // 0x800121F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800121F8: b           L_80015C10
    // 0x800121FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800121FC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012200:
    // 0x80012200: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80012204: lw          $t3, 0x6BA4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA4);
    // 0x80012208: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8001220C: beql        $t4, $zero, L_80012220
    if (ctx->r12 == 0) {
        // 0x80012210: addiu       $s0, $zero, 0x17D
        ctx->r16 = ADD32(0, 0X17D);
            goto L_80012220;
    }
    goto skip_6;
    // 0x80012210: addiu       $s0, $zero, 0x17D
    ctx->r16 = ADD32(0, 0X17D);
    skip_6:
    // 0x80012214: b           L_80012220
    // 0x80012218: addiu       $s0, $zero, 0x17C
    ctx->r16 = ADD32(0, 0X17C);
        goto L_80012220;
    // 0x80012218: addiu       $s0, $zero, 0x17C
    ctx->r16 = ADD32(0, 0X17C);
    // 0x8001221C: addiu       $s0, $zero, 0x17D
    ctx->r16 = ADD32(0, 0X17D);
L_80012220:
    // 0x80012220: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012224: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80012228: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001222C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012230: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80012234: b           L_80015C10
    // 0x80012238: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012238: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001223C:
    // 0x8001223C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012240: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80012244: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012248: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x8001224C: b           L_80015C10
    // 0x80012250: addiu       $s0, $zero, 0x207
    ctx->r16 = ADD32(0, 0X207);
        goto L_80015C10;
    // 0x80012250: addiu       $s0, $zero, 0x207
    ctx->r16 = ADD32(0, 0X207);
L_80012254:
    // 0x80012254: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012258: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8001225C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012260: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012264: addiu       $s0, $zero, 0x2D
    ctx->r16 = ADD32(0, 0X2D);
    // 0x80012268: b           L_80015C10
    // 0x8001226C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001226C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012270:
    // 0x80012270: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80012274: lhu         $t4, -0x4830($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X4830);
    // 0x80012278: sltiu       $at, $t4, 0xA
    ctx->r1 = ctx->r12 < 0XA ? 1 : 0;
    // 0x8001227C: beq         $at, $zero, L_800122D8
    if (ctx->r1 == 0) {
        // 0x80012280: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800122D8;
    }
    // 0x80012280: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80012284: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80012288: addu        $at, $at, $t4
    gpr jr_addend_80012290 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8001228C: lw          $t4, -0x2548($at)
    ctx->r12 = ADD32(ctx->r1, -0X2548);
    // 0x80012290: jr          $t4
    // 0x80012294: nop

    switch (jr_addend_80012290 >> 2) {
        case 0: goto L_800122BC; break;
        case 1: goto L_80012298; break;
        case 2: goto L_800122C4; break;
        case 3: goto L_800122CC; break;
        case 4: goto L_800122D8; break;
        case 5: goto L_800122D8; break;
        case 6: goto L_800122D8; break;
        case 7: goto L_800122D8; break;
        case 8: goto L_800122D4; break;
        case 9: goto L_800122D4; break;
        default: switch_error(__func__, 0x80012290, 0x800ADAB8);
    }
    // 0x80012294: nop

L_80012298:
    // 0x80012298: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x8001229C: lw          $t5, 0x6BA4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BA4);
    // 0x800122A0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x800122A4: beq         $t6, $zero, L_800122B4
    if (ctx->r14 == 0) {
        // 0x800122A8: nop
    
            goto L_800122B4;
    }
    // 0x800122A8: nop

    // 0x800122AC: b           L_800122D8
    // 0x800122B0: addiu       $s0, $zero, 0x189
    ctx->r16 = ADD32(0, 0X189);
        goto L_800122D8;
    // 0x800122B0: addiu       $s0, $zero, 0x189
    ctx->r16 = ADD32(0, 0X189);
L_800122B4:
    // 0x800122B4: b           L_800122D8
    // 0x800122B8: addiu       $s0, $zero, 0x18D
    ctx->r16 = ADD32(0, 0X18D);
        goto L_800122D8;
    // 0x800122B8: addiu       $s0, $zero, 0x18D
    ctx->r16 = ADD32(0, 0X18D);
L_800122BC:
    // 0x800122BC: b           L_800122D8
    // 0x800122C0: addiu       $s0, $zero, 0x18A
    ctx->r16 = ADD32(0, 0X18A);
        goto L_800122D8;
    // 0x800122C0: addiu       $s0, $zero, 0x18A
    ctx->r16 = ADD32(0, 0X18A);
L_800122C4:
    // 0x800122C4: b           L_800122D8
    // 0x800122C8: addiu       $s0, $zero, 0x18E
    ctx->r16 = ADD32(0, 0X18E);
        goto L_800122D8;
    // 0x800122C8: addiu       $s0, $zero, 0x18E
    ctx->r16 = ADD32(0, 0X18E);
L_800122CC:
    // 0x800122CC: b           L_800122D8
    // 0x800122D0: addiu       $s0, $zero, 0x18B
    ctx->r16 = ADD32(0, 0X18B);
        goto L_800122D8;
    // 0x800122D0: addiu       $s0, $zero, 0x18B
    ctx->r16 = ADD32(0, 0X18B);
L_800122D4:
    // 0x800122D4: addiu       $s0, $zero, 0x18C
    ctx->r16 = ADD32(0, 0X18C);
L_800122D8:
    // 0x800122D8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800122DC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800122E0: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800122E4: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800122E8: b           L_80015C10
    // 0x800122EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800122EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800122F0:
    // 0x800122F0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800122F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800122F8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800122FC: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012300: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
    // 0x80012304: b           L_80015C10
    // 0x80012308: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012308: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001230C:
    // 0x8001230C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012310: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80012314: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012318: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x8001231C: addiu       $s0, $zero, 0x1E8
    ctx->r16 = ADD32(0, 0X1E8);
    // 0x80012320: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80012324: b           L_80015C10
    // 0x80012328: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012328: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001232C:
    // 0x8001232C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80012330: lw          $v0, -0x6D30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D30);
    // 0x80012334: beq         $v0, $zero, L_8001235C
    if (ctx->r2 == 0) {
        // 0x80012338: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8001235C;
    }
    // 0x80012338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001233C: beq         $v0, $at, L_80012364
    if (ctx->r2 == ctx->r1) {
        // 0x80012340: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012364;
    }
    // 0x80012340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012344: beq         $v0, $at, L_8001235C
    if (ctx->r2 == ctx->r1) {
        // 0x80012348: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001235C;
    }
    // 0x80012348: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001234C: bnel        $v0, $at, L_8001236C
    if (ctx->r2 != ctx->r1) {
        // 0x80012350: addiu       $t6, $zero, 0x4
        ctx->r14 = ADD32(0, 0X4);
            goto L_8001236C;
    }
    goto skip_7;
    // 0x80012350: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    skip_7:
    // 0x80012354: b           L_80012368
    // 0x80012358: addiu       $s0, $zero, 0x17F
    ctx->r16 = ADD32(0, 0X17F);
        goto L_80012368;
    // 0x80012358: addiu       $s0, $zero, 0x17F
    ctx->r16 = ADD32(0, 0X17F);
L_8001235C:
    // 0x8001235C: b           L_80012368
    // 0x80012360: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
        goto L_80012368;
    // 0x80012360: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
L_80012364:
    // 0x80012364: addiu       $s0, $zero, 0x17E
    ctx->r16 = ADD32(0, 0X17E);
L_80012368:
    // 0x80012368: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
L_8001236C:
    // 0x8001236C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80012370: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012374: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012378: b           L_80015C10
    // 0x8001237C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001237C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012380:
    // 0x80012380: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012384: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80012388: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x8001238C: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012390: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    // 0x80012394: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80012398: b           L_80015C10
    // 0x8001239C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001239C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800123A0:
    // 0x800123A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800123A4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800123A8: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800123AC: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800123B0: b           L_80015C10
    // 0x800123B4: addiu       $s0, $zero, 0x1C
    ctx->r16 = ADD32(0, 0X1C);
        goto L_80015C10;
    // 0x800123B4: addiu       $s0, $zero, 0x1C
    ctx->r16 = ADD32(0, 0X1C);
L_800123B8:
    // 0x800123B8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800123BC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800123C0: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800123C4: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800123C8: addiu       $s0, $zero, 0x11
    ctx->r16 = ADD32(0, 0X11);
    // 0x800123CC: b           L_80015C10
    // 0x800123D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800123D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800123D4:
    // 0x800123D4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800123D8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800123DC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800123E0: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800123E4: addiu       $s0, $zero, 0x12
    ctx->r16 = ADD32(0, 0X12);
    // 0x800123E8: b           L_80015C10
    // 0x800123EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800123EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800123F0:
    // 0x800123F0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800123F4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800123F8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800123FC: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012400: b           L_80015C10
    // 0x80012404: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
        goto L_80015C10;
    // 0x80012404: addiu       $s0, $zero, 0x19
    ctx->r16 = ADD32(0, 0X19);
L_80012408:
    // 0x80012408: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001240C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80012410: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012414: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012418: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x8001241C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80012420: b           L_80015C10
    // 0x80012424: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012424: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012428:
    // 0x80012428: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001242C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80012430: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012434: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012438: addiu       $s0, $zero, 0x177
    ctx->r16 = ADD32(0, 0X177);
    // 0x8001243C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80012440: b           L_80015C10
    // 0x80012444: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012444: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012448:
    // 0x80012448: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8001244C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80012450: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012454: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012458: b           L_80015C10
    // 0x8001245C: addiu       $s0, $zero, 0x1B
    ctx->r16 = ADD32(0, 0X1B);
        goto L_80015C10;
    // 0x8001245C: addiu       $s0, $zero, 0x1B
    ctx->r16 = ADD32(0, 0X1B);
L_80012460:
    // 0x80012460: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80012464: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012468: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x8001246C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80012470: jal         0x80011928
    // 0x80012474: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_0;
    // 0x80012474: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80012478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001247C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80012480: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80012484: beq         $v0, $at, L_800124A0
    if (ctx->r2 == ctx->r1) {
        // 0x80012488: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800124A0;
    }
    // 0x80012488: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001248C: addiu       $a0, $zero, 0xD0
    ctx->r4 = ADD32(0, 0XD0);
    // 0x80012490: jal         0x80011D1C
    // 0x80012494: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80011D1C(rdram, ctx);
        goto after_1;
    // 0x80012494: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80012498: b           L_80015E64
    // 0x8001249C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80015E64;
    // 0x8001249C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800124A0:
    // 0x800124A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800124A4: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800124A8: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800124AC: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800124B0: addiu       $s0, $zero, 0x31
    ctx->r16 = ADD32(0, 0X31);
    // 0x800124B4: b           L_80015C10
    // 0x800124B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800124B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800124BC:
    // 0x800124BC: beql        $s1, $zero, L_800124FC
    if (ctx->r17 == 0) {
        // 0x800124C0: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_800124FC;
    }
    goto skip_8;
    // 0x800124C0: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    skip_8:
    // 0x800124C4: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x800124C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800124CC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800124D0: bne         $at, $zero, L_800124F4
    if (ctx->r1 != 0) {
        // 0x800124D4: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800124F4;
    }
    // 0x800124D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800124D8: ldc1        $f0, -0x24B8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X24B8);
L_800124DC:
    // 0x800124DC: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800124E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800124E4: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800124E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800124EC: bne         $at, $zero, L_800124DC
    if (ctx->r1 != 0) {
        // 0x800124F0: cvt.s.d     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
            goto L_800124DC;
    }
    // 0x800124F0: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_800124F4:
    // 0x800124F4: addiu       $s0, $zero, 0x24A
    ctx->r16 = ADD32(0, 0X24A);
    // 0x800124F8: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
L_800124FC:
    // 0x800124FC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80012500: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012504: b           L_80015C10
    // 0x80012508: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
        goto L_80015C10;
    // 0x80012508: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
L_8001250C:
    // 0x8001250C: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80012510: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012514: beq         $v0, $at, L_8001253C
    if (ctx->r2 == ctx->r1) {
        // 0x80012518: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001253C;
    }
    // 0x80012518: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001251C: beq         $v0, $at, L_80012544
    if (ctx->r2 == ctx->r1) {
        // 0x80012520: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80012544;
    }
    // 0x80012520: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012524: beq         $v0, $at, L_8001254C
    if (ctx->r2 == ctx->r1) {
        // 0x80012528: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8001254C;
    }
    // 0x80012528: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001252C: beql        $v0, $at, L_80012558
    if (ctx->r2 == ctx->r1) {
        // 0x80012530: addiu       $s0, $zero, 0x53
        ctx->r16 = ADD32(0, 0X53);
            goto L_80012558;
    }
    goto skip_9;
    // 0x80012530: addiu       $s0, $zero, 0x53
    ctx->r16 = ADD32(0, 0X53);
    skip_9:
    // 0x80012534: b           L_80012558
    // 0x80012538: addiu       $s0, $zero, 0x53
    ctx->r16 = ADD32(0, 0X53);
        goto L_80012558;
    // 0x80012538: addiu       $s0, $zero, 0x53
    ctx->r16 = ADD32(0, 0X53);
L_8001253C:
    // 0x8001253C: b           L_80012558
    // 0x80012540: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
        goto L_80012558;
    // 0x80012540: addiu       $s0, $zero, 0x50
    ctx->r16 = ADD32(0, 0X50);
L_80012544:
    // 0x80012544: b           L_80012558
    // 0x80012548: addiu       $s0, $zero, 0x51
    ctx->r16 = ADD32(0, 0X51);
        goto L_80012558;
    // 0x80012548: addiu       $s0, $zero, 0x51
    ctx->r16 = ADD32(0, 0X51);
L_8001254C:
    // 0x8001254C: b           L_80012558
    // 0x80012550: addiu       $s0, $zero, 0x52
    ctx->r16 = ADD32(0, 0X52);
        goto L_80012558;
    // 0x80012550: addiu       $s0, $zero, 0x52
    ctx->r16 = ADD32(0, 0X52);
    // 0x80012554: addiu       $s0, $zero, 0x53
    ctx->r16 = ADD32(0, 0X53);
L_80012558:
    // 0x80012558: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8001255C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012560: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012564: b           L_80015C10
    // 0x80012568: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
        goto L_80015C10;
    // 0x80012568: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
L_8001256C:
    // 0x8001256C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012570: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80012574: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012578: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8001257C: addiu       $s0, $zero, 0x3C
    ctx->r16 = ADD32(0, 0X3C);
    // 0x80012580: b           L_80015C10
    // 0x80012584: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012584: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012588:
    // 0x80012588: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8001258C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012590: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012594: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012598: addiu       $s0, $zero, 0x15B
    ctx->r16 = ADD32(0, 0X15B);
    // 0x8001259C: b           L_80015C10
    // 0x800125A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800125A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800125A4:
    // 0x800125A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800125A8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800125AC: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800125B0: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800125B4: addiu       $s0, $zero, 0x47
    ctx->r16 = ADD32(0, 0X47);
    // 0x800125B8: b           L_80015C10
    // 0x800125BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800125BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800125C0:
    // 0x800125C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800125C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800125C8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800125CC: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800125D0: addiu       $s0, $zero, 0x3E
    ctx->r16 = ADD32(0, 0X3E);
    // 0x800125D4: b           L_80015C10
    // 0x800125D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800125D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800125DC:
    // 0x800125DC: beql        $s1, $zero, L_8001260C
    if (ctx->r17 == 0) {
        // 0x800125E0: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_8001260C;
    }
    goto skip_10;
    // 0x800125E0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    skip_10:
    // 0x800125E4: lw          $t3, 0x14($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X14);
    // 0x800125E8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800125EC: ldc1        $f16, -0x2480($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2480);
    // 0x800125F0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800125F4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800125F8: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x800125FC: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80012600: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x80012604: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80012608: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_8001260C:
    // 0x8001260C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012610: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012614: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012618: b           L_80015C10
    // 0x8001261C: addiu       $s0, $zero, 0x1D
    ctx->r16 = ADD32(0, 0X1D);
        goto L_80015C10;
    // 0x8001261C: addiu       $s0, $zero, 0x1D
    ctx->r16 = ADD32(0, 0X1D);
L_80012620:
    // 0x80012620: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012624: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012628: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001262C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012630: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80012634: b           L_80015C10
    // 0x80012638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001263C:
    // 0x8001263C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012640: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80012644: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012648: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001264C: addiu       $s0, $zero, 0x3F
    ctx->r16 = ADD32(0, 0X3F);
    // 0x80012650: b           L_80015C10
    // 0x80012654: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012654: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012658:
    // 0x80012658: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001265C: ldc1        $f10, -0x2460($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X2460);
    // 0x80012660: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80012664: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012668: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001266C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012670: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012674: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012678: addiu       $s0, $zero, 0x3D
    ctx->r16 = ADD32(0, 0X3D);
    // 0x8001267C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80012680: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80012684: b           L_80015C10
    // 0x80012688: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
        goto L_80015C10;
    // 0x80012688: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_8001268C:
    // 0x8001268C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80012690: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80012694: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012698: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001269C: b           L_80015C10
    // 0x800126A0: addiu       $s0, $zero, 0x2F
    ctx->r16 = ADD32(0, 0X2F);
        goto L_80015C10;
    // 0x800126A0: addiu       $s0, $zero, 0x2F
    ctx->r16 = ADD32(0, 0X2F);
L_800126A4:
    // 0x800126A4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800126A8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800126AC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800126B0: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800126B4: b           L_80015C10
    // 0x800126B8: addiu       $s0, $zero, 0x23
    ctx->r16 = ADD32(0, 0X23);
        goto L_80015C10;
    // 0x800126B8: addiu       $s0, $zero, 0x23
    ctx->r16 = ADD32(0, 0X23);
L_800126BC:
    // 0x800126BC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800126C0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800126C4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800126C8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800126CC: addiu       $s0, $zero, 0xEF
    ctx->r16 = ADD32(0, 0XEF);
    // 0x800126D0: b           L_80015C10
    // 0x800126D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800126D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800126D8:
    // 0x800126D8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800126DC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800126E0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800126E4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800126E8: addiu       $s0, $zero, 0x5C
    ctx->r16 = ADD32(0, 0X5C);
    // 0x800126EC: b           L_80015C10
    // 0x800126F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800126F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800126F4:
    // 0x800126F4: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x800126F8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800126FC: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012700: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012704: addiu       $s0, $zero, 0xD
    ctx->r16 = ADD32(0, 0XD);
    // 0x80012708: b           L_80015C10
    // 0x8001270C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001270C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012710:
    // 0x80012710: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80012714: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012718: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x8001271C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80012720: jal         0x80011928
    // 0x80012724: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_2;
    // 0x80012724: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80012728: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001272C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80012730: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012734: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80012738: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x8001273C: bne         $v0, $at, L_80012758
    if (ctx->r2 != ctx->r1) {
        // 0x80012740: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80012758;
    }
    // 0x80012740: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80012744: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80012748: ldc1        $f6, -0x2428($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2428);
    // 0x8001274C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80012750: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80012754: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_80012758:
    // 0x80012758: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001275C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012760: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012764: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012768: addiu       $s0, $zero, 0x62
    ctx->r16 = ADD32(0, 0X62);
    // 0x8001276C: b           L_80015C10
    // 0x80012770: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012770: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012774:
    // 0x80012774: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80012778: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001277C: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80012780: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80012784: jal         0x80011928
    // 0x80012788: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_3;
    // 0x80012788: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x8001278C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012790: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80012794: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012798: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x8001279C: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800127A0: bne         $v0, $at, L_800127BC
    if (ctx->r2 != ctx->r1) {
        // 0x800127A4: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800127BC;
    }
    // 0x800127A4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800127A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800127AC: ldc1        $f16, -0x2418($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2418);
    // 0x800127B0: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800127B4: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800127B8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_800127BC:
    // 0x800127BC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800127C0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800127C4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800127C8: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800127CC: addiu       $s0, $zero, 0x63
    ctx->r16 = ADD32(0, 0X63);
    // 0x800127D0: b           L_80015C10
    // 0x800127D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800127D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800127D8:
    // 0x800127D8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800127DC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800127E0: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800127E4: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800127E8: addiu       $s0, $zero, 0x5D
    ctx->r16 = ADD32(0, 0X5D);
    // 0x800127EC: b           L_80015C10
    // 0x800127F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800127F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800127F4:
    // 0x800127F4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800127F8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800127FC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012800: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012804: addiu       $s0, $zero, 0x5E
    ctx->r16 = ADD32(0, 0X5E);
    // 0x80012808: b           L_80015C10
    // 0x8001280C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001280C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012810:
    // 0x80012810: beql        $s1, $zero, L_80012880
    if (ctx->r17 == 0) {
        // 0x80012814: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80012880;
    }
    goto skip_11;
    // 0x80012814: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    skip_11:
    // 0x80012818: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x8001281C: lui         $at, 0x3F60
    ctx->r1 = S32(0X3F60 << 16);
    // 0x80012820: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80012824: addiu       $t9, $v1, -0x40
    ctx->r25 = ADD32(ctx->r3, -0X40);
    // 0x80012828: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8001282C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012830: lui         $at, 0x3F70
    ctx->r1 = S32(0X3F70 << 16);
    // 0x80012834: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80012838: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x8001283C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80012840: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80012844: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80012848: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8001284C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80012850: cvt.d.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.d = CVT_D_W(ctx->f18.u32l);
    // 0x80012854: add.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d + ctx->f10.d;
    // 0x80012858: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001285C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80012860: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80012864: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80012868: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x8001286C: add.d       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f16.d + ctx->f10.d;
    // 0x80012870: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80012874: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80012878: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8001287C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80012880:
    // 0x80012880: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80012884: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012888: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8001288C: b           L_80015C10
    // 0x80012890: addiu       $s0, $zero, 0x6A
    ctx->r16 = ADD32(0, 0X6A);
        goto L_80015C10;
    // 0x80012890: addiu       $s0, $zero, 0x6A
    ctx->r16 = ADD32(0, 0X6A);
L_80012894:
    // 0x80012894: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012898: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001289C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800128A0: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800128A4: addiu       $s0, $zero, 0x6B
    ctx->r16 = ADD32(0, 0X6B);
    // 0x800128A8: b           L_80015C10
    // 0x800128AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800128AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800128B0:
    // 0x800128B0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800128B4: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800128B8: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800128BC: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800128C0: addiu       $s0, $zero, 0x6F
    ctx->r16 = ADD32(0, 0X6F);
    // 0x800128C4: b           L_80015C10
    // 0x800128C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800128C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800128CC:
    // 0x800128CC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800128D0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800128D4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800128D8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800128DC: addiu       $s0, $zero, 0x75
    ctx->r16 = ADD32(0, 0X75);
    // 0x800128E0: b           L_80015C10
    // 0x800128E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800128E4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800128E8:
    // 0x800128E8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800128EC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800128F0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800128F4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800128F8: b           L_80015C10
    // 0x800128FC: addiu       $s0, $zero, 0xC7
    ctx->r16 = ADD32(0, 0XC7);
        goto L_80015C10;
    // 0x800128FC: addiu       $s0, $zero, 0xC7
    ctx->r16 = ADD32(0, 0XC7);
L_80012900:
    // 0x80012900: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012904: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012908: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001290C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012910: addiu       $s0, $zero, 0x3E
    ctx->r16 = ADD32(0, 0X3E);
    // 0x80012914: b           L_80015C10
    // 0x80012918: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012918: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001291C:
    // 0x8001291C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012920: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012924: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012928: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001292C: addiu       $s0, $zero, 0x86
    ctx->r16 = ADD32(0, 0X86);
    // 0x80012930: b           L_80015C10
    // 0x80012934: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012934: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012938:
    // 0x80012938: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001293C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012940: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012944: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012948: b           L_80015C10
    // 0x8001294C: addiu       $s0, $zero, 0x87
    ctx->r16 = ADD32(0, 0X87);
        goto L_80015C10;
    // 0x8001294C: addiu       $s0, $zero, 0x87
    ctx->r16 = ADD32(0, 0X87);
L_80012950:
    // 0x80012950: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012954: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012958: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001295C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012960: b           L_80015C10
    // 0x80012964: addiu       $s0, $zero, 0x88
    ctx->r16 = ADD32(0, 0X88);
        goto L_80015C10;
    // 0x80012964: addiu       $s0, $zero, 0x88
    ctx->r16 = ADD32(0, 0X88);
L_80012968:
    // 0x80012968: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8001296C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012970: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012974: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012978: b           L_80015C10
    // 0x8001297C: addiu       $s0, $zero, 0x89
    ctx->r16 = ADD32(0, 0X89);
        goto L_80015C10;
    // 0x8001297C: addiu       $s0, $zero, 0x89
    ctx->r16 = ADD32(0, 0X89);
L_80012980:
    // 0x80012980: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80012984: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80012988: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x8001298C: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012990: b           L_80015C10
    // 0x80012994: addiu       $s0, $zero, 0x43
    ctx->r16 = ADD32(0, 0X43);
        goto L_80015C10;
    // 0x80012994: addiu       $s0, $zero, 0x43
    ctx->r16 = ADD32(0, 0X43);
L_80012998:
    // 0x80012998: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8001299C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800129A0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800129A4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800129A8: addiu       $s0, $zero, 0x45
    ctx->r16 = ADD32(0, 0X45);
    // 0x800129AC: b           L_80015C10
    // 0x800129B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800129B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800129B4:
    // 0x800129B4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800129B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800129BC: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800129C0: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800129C4: jal         0x80011928
    // 0x800129C8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_4;
    // 0x800129C8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x800129CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800129D0: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800129D4: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800129D8: bne         $v0, $at, L_80012A00
    if (ctx->r2 != ctx->r1) {
        // 0x800129DC: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80012A00;
    }
    // 0x800129DC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800129E0: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800129E4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800129E8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800129EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800129F0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800129F4: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800129F8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800129FC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80012A00:
    // 0x80012A00: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012A04: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80012A08: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012A0C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012A10: addiu       $s0, $zero, 0x91
    ctx->r16 = ADD32(0, 0X91);
    // 0x80012A14: b           L_80015C10
    // 0x80012A18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012A18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012A1C:
    // 0x80012A1C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012A20: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80012A24: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012A28: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012A2C: b           L_80015C10
    // 0x80012A30: addiu       $s0, $zero, 0x92
    ctx->r16 = ADD32(0, 0X92);
        goto L_80015C10;
    // 0x80012A30: addiu       $s0, $zero, 0x92
    ctx->r16 = ADD32(0, 0X92);
L_80012A34:
    // 0x80012A34: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012A38: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012A3C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012A40: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012A44: addiu       $s0, $zero, 0x98
    ctx->r16 = ADD32(0, 0X98);
    // 0x80012A48: b           L_80015C10
    // 0x80012A4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012A4C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012A50:
    // 0x80012A50: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012A54: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012A58: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012A5C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012A60: addiu       $s0, $zero, 0x9C
    ctx->r16 = ADD32(0, 0X9C);
    // 0x80012A64: b           L_80015C10
    // 0x80012A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012A6C:
    // 0x80012A6C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012A70: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80012A74: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012A78: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012A7C: addiu       $s0, $zero, 0xA0
    ctx->r16 = ADD32(0, 0XA0);
    // 0x80012A80: b           L_80015C10
    // 0x80012A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012A88:
    // 0x80012A88: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012A8C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80012A90: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012A94: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012A98: addiu       $s0, $zero, 0x4D
    ctx->r16 = ADD32(0, 0X4D);
    // 0x80012A9C: b           L_80015C10
    // 0x80012AA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012AA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012AA4:
    // 0x80012AA4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80012AA8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012AAC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012AB0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012AB4: addiu       $s0, $zero, 0x9D
    ctx->r16 = ADD32(0, 0X9D);
    // 0x80012AB8: b           L_80015C10
    // 0x80012ABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012ABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012AC0:
    // 0x80012AC0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012AC4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80012AC8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012ACC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012AD0: b           L_80015C10
    // 0x80012AD4: addiu       $s0, $zero, 0xA1
    ctx->r16 = ADD32(0, 0XA1);
        goto L_80015C10;
    // 0x80012AD4: addiu       $s0, $zero, 0xA1
    ctx->r16 = ADD32(0, 0XA1);
L_80012AD8:
    // 0x80012AD8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80012ADC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80012AE0: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012AE4: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012AE8: addiu       $s0, $zero, 0xA2
    ctx->r16 = ADD32(0, 0XA2);
    // 0x80012AEC: b           L_80015C10
    // 0x80012AF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012AF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012AF4:
    // 0x80012AF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012AF8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012AFC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012B00: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012B04: addiu       $s0, $zero, 0xA3
    ctx->r16 = ADD32(0, 0XA3);
    // 0x80012B08: b           L_80015C10
    // 0x80012B0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B0C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B10:
    // 0x80012B10: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012B14: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012B18: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012B1C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012B20: addiu       $s0, $zero, 0xB1
    ctx->r16 = ADD32(0, 0XB1);
    // 0x80012B24: b           L_80015C10
    // 0x80012B28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B2C:
    // 0x80012B2C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012B30: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80012B34: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012B38: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012B3C: addiu       $s0, $zero, 0xB3
    ctx->r16 = ADD32(0, 0XB3);
    // 0x80012B40: b           L_80015C10
    // 0x80012B44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B48:
    // 0x80012B48: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012B4C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80012B50: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012B54: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012B58: addiu       $s0, $zero, 0xB4
    ctx->r16 = ADD32(0, 0XB4);
    // 0x80012B5C: b           L_80015C10
    // 0x80012B60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B64:
    // 0x80012B64: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80012B68: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80012B6C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012B70: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012B74: addiu       $s0, $zero, 0x3F
    ctx->r16 = ADD32(0, 0X3F);
    // 0x80012B78: b           L_80015C10
    // 0x80012B7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B80:
    // 0x80012B80: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012B84: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012B88: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012B8C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012B90: addiu       $s0, $zero, 0xB5
    ctx->r16 = ADD32(0, 0XB5);
    // 0x80012B94: b           L_80015C10
    // 0x80012B98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012B98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012B9C:
    // 0x80012B9C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012BA0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012BA4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012BA8: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012BAC: addiu       $s0, $zero, 0xB6
    ctx->r16 = ADD32(0, 0XB6);
    // 0x80012BB0: b           L_80015C10
    // 0x80012BB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012BB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012BB8:
    // 0x80012BB8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012BBC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80012BC0: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012BC4: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012BC8: addiu       $s0, $zero, 0xB7
    ctx->r16 = ADD32(0, 0XB7);
    // 0x80012BCC: b           L_80015C10
    // 0x80012BD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012BD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012BD4:
    // 0x80012BD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012BD8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80012BDC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012BE0: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012BE4: addiu       $s0, $zero, 0xBA
    ctx->r16 = ADD32(0, 0XBA);
    // 0x80012BE8: b           L_80015C10
    // 0x80012BEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012BEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012BF0:
    // 0x80012BF0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012BF4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012BF8: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012BFC: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012C00: addiu       $s0, $zero, 0xBD
    ctx->r16 = ADD32(0, 0XBD);
    // 0x80012C04: b           L_80015C10
    // 0x80012C08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012C08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012C0C:
    // 0x80012C0C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80012C10: lbu         $t9, -0x6D78($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6D78);
    // 0x80012C14: bne         $t9, $zero, L_80015E60
    if (ctx->r25 != 0) {
        // 0x80012C18: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80015E60;
    }
    // 0x80012C18: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012C1C: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80012C20: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012C24: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012C28: addiu       $s0, $zero, 0xBE
    ctx->r16 = ADD32(0, 0XBE);
    // 0x80012C2C: b           L_80015C10
    // 0x80012C30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012C30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012C34:
    // 0x80012C34: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80012C38: lbu         $t5, -0x6D78($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X6D78);
    // 0x80012C3C: bne         $t5, $zero, L_80015E60
    if (ctx->r13 != 0) {
        // 0x80012C40: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_80015E60;
    }
    // 0x80012C40: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012C44: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012C48: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012C4C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012C50: b           L_80015C10
    // 0x80012C54: addiu       $s0, $zero, 0xC0
    ctx->r16 = ADD32(0, 0XC0);
        goto L_80015C10;
    // 0x80012C54: addiu       $s0, $zero, 0xC0
    ctx->r16 = ADD32(0, 0XC0);
L_80012C58:
    // 0x80012C58: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012C5C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80012C60: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012C64: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012C68: addiu       $s0, $zero, 0xC1
    ctx->r16 = ADD32(0, 0XC1);
    // 0x80012C6C: b           L_80015C10
    // 0x80012C70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012C70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012C74:
    // 0x80012C74: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012C78: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80012C7C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012C80: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012C84: addiu       $s0, $zero, 0xC6
    ctx->r16 = ADD32(0, 0XC6);
    // 0x80012C88: b           L_80015C10
    // 0x80012C8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012C8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80012C90:
    // 0x80012C90: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80012C94: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012C98: addiu       $s0, $zero, 0x147
    ctx->r16 = ADD32(0, 0X147);
    // 0x80012C9C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80012CA0: b           L_80015C10
    // 0x80012CA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012CA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80012CA8:
    // 0x80012CA8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012CAC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012CB0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012CB4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012CB8: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x80012CBC: b           L_80015C10
    // 0x80012CC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012CC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012CC4:
    // 0x80012CC4: beql        $s1, $zero, L_80012D38
    if (ctx->r17 == 0) {
        // 0x80012CC8: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_80012D38;
    }
    goto skip_12;
    // 0x80012CC8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    skip_12:
    // 0x80012CCC: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
    // 0x80012CD0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80012CD4: sh          $t8, -0x4830($at)
    MEM_H(-0X4830, ctx->r1) = ctx->r24;
    // 0x80012CD8: lw          $t9, 0x14($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X14);
    // 0x80012CDC: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x80012CE0: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x80012CE4: beq         $at, $zero, L_80012D08
    if (ctx->r1 == 0) {
        // 0x80012CE8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80012D08;
    }
    // 0x80012CE8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80012CEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80012CF0: addu        $at, $at, $t3
    gpr jr_addend_80012CF8 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80012CF4: lw          $t3, -0x22D0($at)
    ctx->r11 = ADD32(ctx->r1, -0X22D0);
    // 0x80012CF8: jr          $t3
    // 0x80012CFC: nop

    switch (jr_addend_80012CF8 >> 2) {
        case 0: goto L_80012D00; break;
        case 1: goto L_80012D08; break;
        case 2: goto L_80012D10; break;
        case 3: goto L_80012D18; break;
        case 4: goto L_80012D20; break;
        case 5: goto L_80012D08; break;
        case 6: goto L_80012D08; break;
        case 7: goto L_80012D08; break;
        case 8: goto L_80012D08; break;
        case 9: goto L_80012D28; break;
        case 10: goto L_80012D30; break;
        default: switch_error(__func__, 0x80012CF8, 0x800ADD30);
    }
    // 0x80012CFC: nop

L_80012D00:
    // 0x80012D00: b           L_80012D34
    // 0x80012D04: addiu       $s0, $zero, 0x260
    ctx->r16 = ADD32(0, 0X260);
        goto L_80012D34;
    // 0x80012D04: addiu       $s0, $zero, 0x260
    ctx->r16 = ADD32(0, 0X260);
L_80012D08:
    // 0x80012D08: b           L_80012D34
    // 0x80012D0C: addiu       $s0, $zero, 0x207
    ctx->r16 = ADD32(0, 0X207);
        goto L_80012D34;
    // 0x80012D0C: addiu       $s0, $zero, 0x207
    ctx->r16 = ADD32(0, 0X207);
L_80012D10:
    // 0x80012D10: b           L_80012D34
    // 0x80012D14: addiu       $s0, $zero, 0x1D3
    ctx->r16 = ADD32(0, 0X1D3);
        goto L_80012D34;
    // 0x80012D14: addiu       $s0, $zero, 0x1D3
    ctx->r16 = ADD32(0, 0X1D3);
L_80012D18:
    // 0x80012D18: b           L_80012D34
    // 0x80012D1C: addiu       $s0, $zero, 0x1D4
    ctx->r16 = ADD32(0, 0X1D4);
        goto L_80012D34;
    // 0x80012D1C: addiu       $s0, $zero, 0x1D4
    ctx->r16 = ADD32(0, 0X1D4);
L_80012D20:
    // 0x80012D20: b           L_80012D34
    // 0x80012D24: addiu       $s0, $zero, 0x1D5
    ctx->r16 = ADD32(0, 0X1D5);
        goto L_80012D34;
    // 0x80012D24: addiu       $s0, $zero, 0x1D5
    ctx->r16 = ADD32(0, 0X1D5);
L_80012D28:
    // 0x80012D28: b           L_80012D34
    // 0x80012D2C: addiu       $s0, $zero, 0x1D6
    ctx->r16 = ADD32(0, 0X1D6);
        goto L_80012D34;
    // 0x80012D2C: addiu       $s0, $zero, 0x1D6
    ctx->r16 = ADD32(0, 0X1D6);
L_80012D30:
    // 0x80012D30: addiu       $s0, $zero, 0x1D7
    ctx->r16 = ADD32(0, 0X1D7);
L_80012D34:
    // 0x80012D34: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80012D38:
    // 0x80012D38: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80012D3C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012D40: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012D44: addiu       $a0, $zero, 0xD5
    ctx->r4 = ADD32(0, 0XD5);
    // 0x80012D48: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80012D4C: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80012D50: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80012D54: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80012D58: jal         0x80011D1C
    // 0x80012D5C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_5;
    // 0x80012D5C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_5:
    // 0x80012D60: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80012D64: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80012D68: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80012D6C: b           L_80015C10
    // 0x80012D70: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x80012D70: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80012D74:
    // 0x80012D74: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80012D78: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012D7C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012D80: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012D84: b           L_80015C10
    // 0x80012D88: addiu       $s0, $zero, 0xDE
    ctx->r16 = ADD32(0, 0XDE);
        goto L_80015C10;
    // 0x80012D88: addiu       $s0, $zero, 0xDE
    ctx->r16 = ADD32(0, 0XDE);
L_80012D8C:
    // 0x80012D8C: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80012D90: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012D94: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012D98: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012D9C: b           L_80015C10
    // 0x80012DA0: addiu       $s0, $zero, 0xDF
    ctx->r16 = ADD32(0, 0XDF);
        goto L_80015C10;
    // 0x80012DA0: addiu       $s0, $zero, 0xDF
    ctx->r16 = ADD32(0, 0XDF);
L_80012DA4:
    // 0x80012DA4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012DA8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012DAC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012DB0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012DB4: addiu       $s0, $zero, 0xEC
    ctx->r16 = ADD32(0, 0XEC);
    // 0x80012DB8: b           L_80015C10
    // 0x80012DBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012DBC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012DC0:
    // 0x80012DC0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012DC4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012DC8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012DCC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012DD0: addiu       $s0, $zero, 0xED
    ctx->r16 = ADD32(0, 0XED);
    // 0x80012DD4: b           L_80015C10
    // 0x80012DD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012DD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012DDC:
    // 0x80012DDC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80012DE0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80012DE4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012DE8: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012DEC: addiu       $s0, $zero, 0xEE
    ctx->r16 = ADD32(0, 0XEE);
    // 0x80012DF0: b           L_80015C10
    // 0x80012DF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012DF4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012DF8:
    // 0x80012DF8: beql        $s1, $zero, L_80012E40
    if (ctx->r17 == 0) {
        // 0x80012DFC: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80012E40;
    }
    goto skip_13;
    // 0x80012DFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_13:
    // 0x80012E00: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x80012E04: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012E08: beq         $v0, $at, L_80012E28
    if (ctx->r2 == ctx->r1) {
        // 0x80012E0C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80012E28;
    }
    // 0x80012E0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80012E10: beq         $v0, $at, L_80012E30
    if (ctx->r2 == ctx->r1) {
        // 0x80012E14: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80012E30;
    }
    // 0x80012E14: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80012E18: beql        $v0, $at, L_80012E3C
    if (ctx->r2 == ctx->r1) {
        // 0x80012E1C: addiu       $s0, $zero, 0x151
        ctx->r16 = ADD32(0, 0X151);
            goto L_80012E3C;
    }
    goto skip_14;
    // 0x80012E1C: addiu       $s0, $zero, 0x151
    ctx->r16 = ADD32(0, 0X151);
    skip_14:
    // 0x80012E20: b           L_80012E40
    // 0x80012E24: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80012E40;
    // 0x80012E24: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80012E28:
    // 0x80012E28: b           L_80012E3C
    // 0x80012E2C: addiu       $s0, $zero, 0x14E
    ctx->r16 = ADD32(0, 0X14E);
        goto L_80012E3C;
    // 0x80012E2C: addiu       $s0, $zero, 0x14E
    ctx->r16 = ADD32(0, 0X14E);
L_80012E30:
    // 0x80012E30: b           L_80012E3C
    // 0x80012E34: addiu       $s0, $zero, 0xEF
    ctx->r16 = ADD32(0, 0XEF);
        goto L_80012E3C;
    // 0x80012E34: addiu       $s0, $zero, 0xEF
    ctx->r16 = ADD32(0, 0XEF);
    // 0x80012E38: addiu       $s0, $zero, 0x151
    ctx->r16 = ADD32(0, 0X151);
L_80012E3C:
    // 0x80012E3C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80012E40:
    // 0x80012E40: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80012E44: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012E48: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012E4C: b           L_80015C10
    // 0x80012E50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012E50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012E54:
    // 0x80012E54: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80012E58: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80012E5C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012E60: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012E64: addiu       $s0, $zero, 0xF0
    ctx->r16 = ADD32(0, 0XF0);
    // 0x80012E68: b           L_80015C10
    // 0x80012E6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012E6C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80012E70:
    // 0x80012E70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012E74: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012E78: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012E7C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012E80: addiu       $s0, $zero, 0xF2
    ctx->r16 = ADD32(0, 0XF2);
    // 0x80012E84: b           L_80015C10
    // 0x80012E88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012E88: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012E8C:
    // 0x80012E8C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80012E90: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80012E94: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012E98: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012E9C: addiu       $s0, $zero, 0xF4
    ctx->r16 = ADD32(0, 0XF4);
    // 0x80012EA0: b           L_80015C10
    // 0x80012EA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012EA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012EA8:
    // 0x80012EA8: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80012EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80012EB0: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80012EB4: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80012EB8: jal         0x80011928
    // 0x80012EBC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_6;
    // 0x80012EBC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x80012EC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012EC4: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80012EC8: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80012ECC: bne         $v0, $at, L_80015E60
    if (ctx->r2 != ctx->r1) {
        // 0x80012ED0: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80015E60;
    }
    // 0x80012ED0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80012ED4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012ED8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80012EDC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012EE0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012EE4: addiu       $s0, $zero, 0xF3
    ctx->r16 = ADD32(0, 0XF3);
    // 0x80012EE8: b           L_80015C10
    // 0x80012EEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012EEC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012EF0:
    // 0x80012EF0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80012EF4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80012EF8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012EFC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012F00: addiu       $s0, $zero, 0x253
    ctx->r16 = ADD32(0, 0X253);
    // 0x80012F04: b           L_80015C10
    // 0x80012F08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012F08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012F0C:
    // 0x80012F0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012F10: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012F14: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012F18: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012F1C: addiu       $s0, $zero, 0x252
    ctx->r16 = ADD32(0, 0X252);
    // 0x80012F20: b           L_80015C10
    // 0x80012F24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012F24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012F28:
    // 0x80012F28: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012F2C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80012F30: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012F34: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012F38: b           L_80015C10
    // 0x80012F3C: addiu       $s0, $zero, 0x103
    ctx->r16 = ADD32(0, 0X103);
        goto L_80015C10;
    // 0x80012F3C: addiu       $s0, $zero, 0x103
    ctx->r16 = ADD32(0, 0X103);
L_80012F40:
    // 0x80012F40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80012F44: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012F48: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80012F4C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80012F50: addiu       $s0, $zero, 0x104
    ctx->r16 = ADD32(0, 0X104);
    // 0x80012F54: b           L_80015C10
    // 0x80012F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012F5C:
    // 0x80012F5C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80012F60: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80012F64: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80012F68: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80012F6C: addiu       $s0, $zero, 0x105
    ctx->r16 = ADD32(0, 0X105);
    // 0x80012F70: b           L_80015C10
    // 0x80012F74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012F74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012F78:
    // 0x80012F78: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80012F7C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80012F80: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80012F84: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80012F88: addiu       $s0, $zero, 0x106
    ctx->r16 = ADD32(0, 0X106);
    // 0x80012F8C: b           L_80015C10
    // 0x80012F90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012F90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80012F94:
    // 0x80012F94: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80012F98: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80012F9C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80012FA0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80012FA4: addiu       $s0, $zero, 0x12E
    ctx->r16 = ADD32(0, 0X12E);
    // 0x80012FA8: b           L_80015C10
    // 0x80012FAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012FAC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012FB0:
    // 0x80012FB0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80012FB4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80012FB8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80012FBC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80012FC0: addiu       $s0, $zero, 0x17B
    ctx->r16 = ADD32(0, 0X17B);
    // 0x80012FC4: b           L_80015C10
    // 0x80012FC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012FC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80012FCC:
    // 0x80012FCC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80012FD0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80012FD4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80012FD8: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80012FDC: addiu       $s0, $zero, 0x130
    ctx->r16 = ADD32(0, 0X130);
    // 0x80012FE0: b           L_80015C10
    // 0x80012FE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80012FE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80012FE8:
    // 0x80012FE8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80012FEC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80012FF0: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80012FF4: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80012FF8: addiu       $s0, $zero, 0x131
    ctx->r16 = ADD32(0, 0X131);
    // 0x80012FFC: b           L_80015C10
    // 0x80013000: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013000: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013004:
    // 0x80013004: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80013008: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8001300C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013010: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013014: addiu       $s0, $zero, 0x132
    ctx->r16 = ADD32(0, 0X132);
    // 0x80013018: b           L_80015C10
    // 0x8001301C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001301C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013020:
    // 0x80013020: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013024: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013028: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001302C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80013030: addiu       $s0, $zero, 0x40
    ctx->r16 = ADD32(0, 0X40);
    // 0x80013034: b           L_80015C10
    // 0x80013038: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013038: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001303C:
    // 0x8001303C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80013040: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80013044: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013048: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001304C: addiu       $s0, $zero, 0x135
    ctx->r16 = ADD32(0, 0X135);
    // 0x80013050: b           L_80015C10
    // 0x80013054: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013054: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013058:
    // 0x80013058: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001305C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013060: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013064: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013068: addiu       $s0, $zero, 0x134
    ctx->r16 = ADD32(0, 0X134);
    // 0x8001306C: b           L_80015C10
    // 0x80013070: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013070: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013074:
    // 0x80013074: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013078: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001307C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013080: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013084: addiu       $s0, $zero, 0x133
    ctx->r16 = ADD32(0, 0X133);
    // 0x80013088: b           L_80015C10
    // 0x8001308C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001308C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013090:
    // 0x80013090: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80013094: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013098: addiu       $s0, $zero, 0x137
    ctx->r16 = ADD32(0, 0X137);
    // 0x8001309C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800130A0: b           L_80015C10
    // 0x800130A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800130A4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800130A8:
    // 0x800130A8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800130AC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800130B0: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800130B4: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800130B8: addiu       $s0, $zero, 0x140
    ctx->r16 = ADD32(0, 0X140);
    // 0x800130BC: b           L_80015C10
    // 0x800130C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800130C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800130C4:
    // 0x800130C4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800130C8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800130CC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800130D0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800130D4: addiu       $s0, $zero, 0x141
    ctx->r16 = ADD32(0, 0X141);
    // 0x800130D8: b           L_80015C10
    // 0x800130DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800130DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800130E0:
    // 0x800130E0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800130E4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800130E8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800130EC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800130F0: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
    // 0x800130F4: b           L_80015C10
    // 0x800130F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800130F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800130FC:
    // 0x800130FC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013100: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013104: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013108: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x8001310C: addiu       $s0, $zero, 0x155
    ctx->r16 = ADD32(0, 0X155);
    // 0x80013110: b           L_80015C10
    // 0x80013114: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013114: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013118:
    // 0x80013118: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001311C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013120: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013124: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013128: b           L_80015C10
    // 0x8001312C: addiu       $s0, $zero, 0x145
    ctx->r16 = ADD32(0, 0X145);
        goto L_80015C10;
    // 0x8001312C: addiu       $s0, $zero, 0x145
    ctx->r16 = ADD32(0, 0X145);
L_80013130:
    // 0x80013130: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80013134: lbu         $t4, -0x6D78($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6D78);
    // 0x80013138: bne         $t4, $zero, L_80015E60
    if (ctx->r12 != 0) {
        // 0x8001313C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80015E60;
    }
    // 0x8001313C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80013140: lw          $v0, -0x6D30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D30);
    // 0x80013144: beq         $v0, $zero, L_80013184
    if (ctx->r2 == 0) {
        // 0x80013148: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80013184;
    }
    // 0x80013148: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001314C: beq         $v0, $at, L_80013160
    if (ctx->r2 == ctx->r1) {
        // 0x80013150: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80013160;
    }
    // 0x80013150: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80013154: beq         $v0, $at, L_800131A8
    if (ctx->r2 == ctx->r1) {
        // 0x80013158: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800131A8;
    }
    // 0x80013158: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001315C: bne         $v0, $at, L_800131C8
    if (ctx->r2 != ctx->r1) {
        // 0x80013160: lui         $t5, 0x800B
        ctx->r13 = S32(0X800B << 16);
            goto L_800131C8;
    }
L_80013160:
    // 0x80013160: lui         $t5, 0x800B
    ctx->r13 = S32(0X800B << 16);
    // 0x80013164: lw          $t5, 0x6BA4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6BA4);
    // 0x80013168: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8001316C: beq         $t6, $zero, L_8001317C
    if (ctx->r14 == 0) {
        // 0x80013170: nop
    
            goto L_8001317C;
    }
    // 0x80013170: nop

    // 0x80013174: b           L_800131C8
    // 0x80013178: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
        goto L_800131C8;
    // 0x80013178: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
L_8001317C:
    // 0x8001317C: b           L_800131C8
    // 0x80013180: addiu       $s0, $zero, 0x14B
    ctx->r16 = ADD32(0, 0X14B);
        goto L_800131C8;
    // 0x80013180: addiu       $s0, $zero, 0x14B
    ctx->r16 = ADD32(0, 0X14B);
L_80013184:
    // 0x80013184: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80013188: lw          $t7, 0x6BA4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA4);
    // 0x8001318C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80013190: beq         $t8, $zero, L_800131A0
    if (ctx->r24 == 0) {
        // 0x80013194: nop
    
            goto L_800131A0;
    }
    // 0x80013194: nop

    // 0x80013198: b           L_800131C8
    // 0x8001319C: addiu       $s0, $zero, 0x14F
    ctx->r16 = ADD32(0, 0X14F);
        goto L_800131C8;
    // 0x8001319C: addiu       $s0, $zero, 0x14F
    ctx->r16 = ADD32(0, 0X14F);
L_800131A0:
    // 0x800131A0: b           L_800131C8
    // 0x800131A4: addiu       $s0, $zero, 0x150
    ctx->r16 = ADD32(0, 0X150);
        goto L_800131C8;
    // 0x800131A4: addiu       $s0, $zero, 0x150
    ctx->r16 = ADD32(0, 0X150);
L_800131A8:
    // 0x800131A8: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x800131AC: lw          $t9, 0x6BA4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6BA4);
    // 0x800131B0: andi        $t3, $t9, 0x1
    ctx->r11 = ctx->r25 & 0X1;
    // 0x800131B4: beql        $t3, $zero, L_800131C8
    if (ctx->r11 == 0) {
        // 0x800131B8: addiu       $s0, $zero, 0x183
        ctx->r16 = ADD32(0, 0X183);
            goto L_800131C8;
    }
    goto skip_15;
    // 0x800131B8: addiu       $s0, $zero, 0x183
    ctx->r16 = ADD32(0, 0X183);
    skip_15:
    // 0x800131BC: b           L_800131C8
    // 0x800131C0: addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
        goto L_800131C8;
    // 0x800131C0: addiu       $s0, $zero, 0x180
    ctx->r16 = ADD32(0, 0X180);
    // 0x800131C4: addiu       $s0, $zero, 0x183
    ctx->r16 = ADD32(0, 0X183);
L_800131C8:
    // 0x800131C8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800131CC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800131D0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800131D4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800131D8: b           L_80015C10
    // 0x800131DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800131DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800131E0:
    // 0x800131E0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800131E4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800131E8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800131EC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800131F0: b           L_80015C10
    // 0x800131F4: addiu       $s0, $zero, 0x14D
    ctx->r16 = ADD32(0, 0X14D);
        goto L_80015C10;
    // 0x800131F4: addiu       $s0, $zero, 0x14D
    ctx->r16 = ADD32(0, 0X14D);
L_800131F8:
    // 0x800131F8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800131FC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80013200: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013204: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80013208: addiu       $s0, $zero, 0x14C
    ctx->r16 = ADD32(0, 0X14C);
    // 0x8001320C: b           L_80015C10
    // 0x80013210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013210: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80013214:
    // 0x80013214: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013218: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8001321C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013220: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013224: addiu       $s0, $zero, 0x152
    ctx->r16 = ADD32(0, 0X152);
    // 0x80013228: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001322C: b           L_80015C10
    // 0x80013230: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013230: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013234:
    // 0x80013234: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80013238: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8001323C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013240: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013244: addiu       $s0, $zero, 0x163
    ctx->r16 = ADD32(0, 0X163);
    // 0x80013248: b           L_80015C10
    // 0x8001324C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001324C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80013250:
    // 0x80013250: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013254: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80013258: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001325C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013260: addiu       $s0, $zero, 0x1A1
    ctx->r16 = ADD32(0, 0X1A1);
    // 0x80013264: b           L_80015C10
    // 0x80013268: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013268: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8001326C:
    // 0x8001326C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80013270: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80013274: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013278: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8001327C: addiu       $s0, $zero, 0x175
    ctx->r16 = ADD32(0, 0X175);
    // 0x80013280: b           L_80015C10
    // 0x80013284: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013284: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80013288:
    // 0x80013288: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8001328C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80013290: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013294: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013298: addiu       $s0, $zero, 0x175
    ctx->r16 = ADD32(0, 0X175);
    // 0x8001329C: b           L_80015C10
    // 0x800132A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800132A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800132A4:
    // 0x800132A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800132A8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800132AC: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800132B0: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800132B4: addiu       $s0, $zero, 0x175
    ctx->r16 = ADD32(0, 0X175);
    // 0x800132B8: b           L_80015C10
    // 0x800132BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800132BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800132C0:
    // 0x800132C0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800132C4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x800132C8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800132CC: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800132D0: b           L_80015C10
    // 0x800132D4: addiu       $s0, $zero, 0x1A7
    ctx->r16 = ADD32(0, 0X1A7);
        goto L_80015C10;
    // 0x800132D4: addiu       $s0, $zero, 0x1A7
    ctx->r16 = ADD32(0, 0X1A7);
L_800132D8:
    // 0x800132D8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800132DC: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800132E0: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800132E4: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800132E8: b           L_80015C10
    // 0x800132EC: addiu       $s0, $zero, 0x1A8
    ctx->r16 = ADD32(0, 0X1A8);
        goto L_80015C10;
    // 0x800132EC: addiu       $s0, $zero, 0x1A8
    ctx->r16 = ADD32(0, 0X1A8);
L_800132F0:
    // 0x800132F0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800132F4: lb          $t5, -0x6D60($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X6D60);
    // 0x800132F8: beq         $t5, $zero, L_80013320
    if (ctx->r13 == 0) {
        // 0x800132FC: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80013320;
    }
    // 0x800132FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013300: sb          $zero, -0x6D60($at)
    MEM_B(-0X6D60, ctx->r1) = 0;
    // 0x80013304: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013308: ldc1        $f16, -0x2148($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X2148);
    // 0x8001330C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80013310: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80013314: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80013318: b           L_8001332C
    // 0x8001331C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
        goto L_8001332C;
    // 0x8001331C: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_80013320:
    // 0x80013320: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013324: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013328: sb          $t6, -0x6D60($at)
    MEM_B(-0X6D60, ctx->r1) = ctx->r14;
L_8001332C:
    // 0x8001332C: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80013330: lw          $t7, 0x6BA4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6BA4);
    // 0x80013334: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80013338: beql        $t8, $zero, L_8001334C
    if (ctx->r24 == 0) {
        // 0x8001333C: addiu       $s0, $zero, 0x176
        ctx->r16 = ADD32(0, 0X176);
            goto L_8001334C;
    }
    goto skip_16;
    // 0x8001333C: addiu       $s0, $zero, 0x176
    ctx->r16 = ADD32(0, 0X176);
    skip_16:
    // 0x80013340: b           L_8001334C
    // 0x80013344: addiu       $s0, $zero, 0x166
    ctx->r16 = ADD32(0, 0X166);
        goto L_8001334C;
    // 0x80013344: addiu       $s0, $zero, 0x166
    ctx->r16 = ADD32(0, 0X166);
    // 0x80013348: addiu       $s0, $zero, 0x176
    ctx->r16 = ADD32(0, 0X176);
L_8001334C:
    // 0x8001334C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80013350: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80013354: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013358: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8001335C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80013360: b           L_80015C10
    // 0x80013364: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013364: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013368:
    // 0x80013368: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8001336C: lb          $t4, -0x6D5C($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X6D5C);
    // 0x80013370: beq         $t4, $zero, L_80013398
    if (ctx->r12 == 0) {
        // 0x80013374: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80013398;
    }
    // 0x80013374: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013378: sb          $zero, -0x6D5C($at)
    MEM_B(-0X6D5C, ctx->r1) = 0;
    // 0x8001337C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013380: ldc1        $f6, -0x2138($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X2138);
    // 0x80013384: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013388: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8001338C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x80013390: b           L_800133A4
    // 0x80013394: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
        goto L_800133A4;
    // 0x80013394: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_80013398:
    // 0x80013398: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001339C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800133A0: sb          $t5, -0x6D5C($at)
    MEM_B(-0X6D5C, ctx->r1) = ctx->r13;
L_800133A4:
    // 0x800133A4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800133A8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800133AC: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800133B0: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800133B4: addiu       $s0, $zero, 0x167
    ctx->r16 = ADD32(0, 0X167);
    // 0x800133B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800133BC: b           L_80015C10
    // 0x800133C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800133C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800133C4:
    // 0x800133C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800133C8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800133CC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800133D0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800133D4: b           L_80015C10
    // 0x800133D8: addiu       $s0, $zero, 0x2F
    ctx->r16 = ADD32(0, 0X2F);
        goto L_80015C10;
    // 0x800133D8: addiu       $s0, $zero, 0x2F
    ctx->r16 = ADD32(0, 0X2F);
L_800133DC:
    // 0x800133DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800133E0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800133E4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800133E8: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800133EC: b           L_80015C10
    // 0x800133F0: addiu       $s0, $zero, 0x174
    ctx->r16 = ADD32(0, 0X174);
        goto L_80015C10;
    // 0x800133F0: addiu       $s0, $zero, 0x174
    ctx->r16 = ADD32(0, 0X174);
L_800133F4:
    // 0x800133F4: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800133F8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800133FC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013400: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013404: addiu       $s0, $zero, 0x184
    ctx->r16 = ADD32(0, 0X184);
    // 0x80013408: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001340C: b           L_80015C10
    // 0x80013410: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013410: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013414:
    // 0x80013414: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013418: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001341C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013420: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013424: addiu       $s0, $zero, 0x185
    ctx->r16 = ADD32(0, 0X185);
    // 0x80013428: b           L_80015C10
    // 0x8001342C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001342C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013430:
    // 0x80013430: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013434: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80013438: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x8001343C: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013440: addiu       $s0, $zero, 0x1AD
    ctx->r16 = ADD32(0, 0X1AD);
    // 0x80013444: b           L_80015C10
    // 0x80013448: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013448: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001344C:
    // 0x8001344C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013450: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80013454: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013458: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x8001345C: b           L_80015C10
    // 0x80013460: addiu       $s0, $zero, 0x27
    ctx->r16 = ADD32(0, 0X27);
        goto L_80015C10;
    // 0x80013460: addiu       $s0, $zero, 0x27
    ctx->r16 = ADD32(0, 0X27);
L_80013464:
    // 0x80013464: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013468: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8001346C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013470: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80013474: b           L_80015C10
    // 0x80013478: addiu       $s0, $zero, 0x186
    ctx->r16 = ADD32(0, 0X186);
        goto L_80015C10;
    // 0x80013478: addiu       $s0, $zero, 0x186
    ctx->r16 = ADD32(0, 0X186);
L_8001347C:
    // 0x8001347C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013480: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80013484: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013488: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001348C: b           L_80015C10
    // 0x80013490: addiu       $s0, $zero, 0x187
    ctx->r16 = ADD32(0, 0X187);
        goto L_80015C10;
    // 0x80013490: addiu       $s0, $zero, 0x187
    ctx->r16 = ADD32(0, 0X187);
L_80013494:
    // 0x80013494: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013498: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001349C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800134A0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800134A4: b           L_80015C10
    // 0x800134A8: addiu       $s0, $zero, 0x181
    ctx->r16 = ADD32(0, 0X181);
        goto L_80015C10;
    // 0x800134A8: addiu       $s0, $zero, 0x181
    ctx->r16 = ADD32(0, 0X181);
L_800134AC:
    // 0x800134AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800134B0: ldc1        $f18, -0x20E0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X20E0);
    // 0x800134B4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800134B8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800134BC: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800134C0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800134C4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800134C8: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800134CC: addiu       $s0, $zero, 0x181
    ctx->r16 = ADD32(0, 0X181);
    // 0x800134D0: b           L_80015C10
    // 0x800134D4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
        goto L_80015C10;
    // 0x800134D4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
L_800134D8:
    // 0x800134D8: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800134DC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800134E0: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800134E4: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800134E8: addiu       $s0, $zero, 0xC8
    ctx->r16 = ADD32(0, 0XC8);
    // 0x800134EC: b           L_80015C10
    // 0x800134F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800134F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800134F4:
    // 0x800134F4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800134F8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800134FC: addiu       $s0, $zero, 0x2B
    ctx->r16 = ADD32(0, 0X2B);
    // 0x80013500: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013504: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013508: b           L_80015C10
    // 0x8001350C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001350C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013510:
    // 0x80013510: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013514: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80013518: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001351C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013520: addiu       $s0, $zero, 0x182
    ctx->r16 = ADD32(0, 0X182);
    // 0x80013524: b           L_80015C10
    // 0x80013528: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013528: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001352C:
    // 0x8001352C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013530: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013534: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013538: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001353C: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
    // 0x80013540: b           L_80015C10
    // 0x80013544: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013544: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013548:
    // 0x80013548: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8001354C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013550: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013554: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013558: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
    // 0x8001355C: b           L_80015C10
    // 0x80013560: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013560: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013564:
    // 0x80013564: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013568: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001356C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013570: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013574: addiu       $s0, $zero, 0xB6
    ctx->r16 = ADD32(0, 0XB6);
    // 0x80013578: b           L_80015C10
    // 0x8001357C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001357C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013580:
    // 0x80013580: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80013584: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80013588: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001358C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013590: addiu       $s0, $zero, 0x254
    ctx->r16 = ADD32(0, 0X254);
    // 0x80013594: b           L_80015C10
    // 0x80013598: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013598: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001359C:
    // 0x8001359C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x800135A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800135A4: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800135A8: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800135AC: jal         0x80011928
    // 0x800135B0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_7;
    // 0x800135B0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x800135B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800135B8: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800135BC: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800135C0: bne         $v0, $at, L_800135E8
    if (ctx->r2 != ctx->r1) {
        // 0x800135C4: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800135E8;
    }
    // 0x800135C4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800135C8: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800135CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800135D0: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800135D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800135D8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800135DC: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800135E0: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800135E4: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_800135E8:
    // 0x800135E8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800135EC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800135F0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800135F4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800135F8: addiu       $s0, $zero, 0x1A5
    ctx->r16 = ADD32(0, 0X1A5);
    // 0x800135FC: b           L_80015C10
    // 0x80013600: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013600: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013604:
    // 0x80013604: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80013608: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8001360C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013610: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80013614: addiu       $s0, $zero, 0x1B2
    ctx->r16 = ADD32(0, 0X1B2);
    // 0x80013618: b           L_80015C10
    // 0x8001361C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001361C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013620:
    // 0x80013620: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013624: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013628: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001362C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013630: addiu       $s0, $zero, 0x1B3
    ctx->r16 = ADD32(0, 0X1B3);
    // 0x80013634: b           L_80015C10
    // 0x80013638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001363C:
    // 0x8001363C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013640: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013644: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013648: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001364C: addiu       $s0, $zero, 0x287
    ctx->r16 = ADD32(0, 0X287);
    // 0x80013650: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80013654: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80013658: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x8001365C: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80013660: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80013664: jal         0x80011D1C
    // 0x80013668: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_8;
    // 0x80013668: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_8:
    // 0x8001366C: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80013670: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80013674: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80013678: b           L_80015C10
    // 0x8001367C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x8001367C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80013680:
    // 0x80013680: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013684: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013688: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001368C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013690: addiu       $s0, $zero, 0x286
    ctx->r16 = ADD32(0, 0X286);
    // 0x80013694: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80013698: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001369C: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800136A0: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800136A4: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800136A8: jal         0x80011D1C
    // 0x800136AC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_9;
    // 0x800136AC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x800136B0: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x800136B4: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800136B8: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800136BC: b           L_80015C10
    // 0x800136C0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x800136C0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_800136C4:
    // 0x800136C4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800136C8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800136CC: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800136D0: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800136D4: addiu       $s0, $zero, 0x284
    ctx->r16 = ADD32(0, 0X284);
    // 0x800136D8: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x800136DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800136E0: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800136E4: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800136E8: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800136EC: jal         0x80011D1C
    // 0x800136F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_10;
    // 0x800136F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_10:
    // 0x800136F4: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x800136F8: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800136FC: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80013700: b           L_80015C10
    // 0x80013704: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x80013704: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80013708:
    // 0x80013708: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8001370C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80013710: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013714: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013718: addiu       $s0, $zero, 0x288
    ctx->r16 = ADD32(0, 0X288);
    // 0x8001371C: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80013720: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80013724: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80013728: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x8001372C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80013730: jal         0x80011D1C
    // 0x80013734: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_11;
    // 0x80013734: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_11:
    // 0x80013738: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x8001373C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80013740: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80013744: b           L_80015C10
    // 0x80013748: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x80013748: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_8001374C:
    // 0x8001374C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013750: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013754: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013758: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8001375C: addiu       $s0, $zero, 0x285
    ctx->r16 = ADD32(0, 0X285);
    // 0x80013760: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x80013764: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80013768: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x8001376C: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80013770: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80013774: jal         0x80011D1C
    // 0x80013778: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_12;
    // 0x80013778: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_12:
    // 0x8001377C: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80013780: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80013784: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80013788: b           L_80015C10
    // 0x8001378C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x8001378C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80013790:
    // 0x80013790: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80013794: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80013798: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x8001379C: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800137A0: addiu       $s0, $zero, 0x289
    ctx->r16 = ADD32(0, 0X289);
    // 0x800137A4: addiu       $a0, $zero, 0xD6
    ctx->r4 = ADD32(0, 0XD6);
    // 0x800137A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800137AC: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800137B0: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800137B4: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800137B8: jal         0x80011D1C
    // 0x800137BC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_13;
    // 0x800137BC: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_13:
    // 0x800137C0: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x800137C4: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800137C8: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800137CC: b           L_80015C10
    // 0x800137D0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x800137D0: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_800137D4:
    // 0x800137D4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800137D8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800137DC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800137E0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800137E4: addiu       $s0, $zero, 0x1B5
    ctx->r16 = ADD32(0, 0X1B5);
    // 0x800137E8: b           L_80015C10
    // 0x800137EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800137EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800137F0:
    // 0x800137F0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800137F4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800137F8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800137FC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013800: addiu       $s0, $zero, 0x1B6
    ctx->r16 = ADD32(0, 0X1B6);
    // 0x80013804: b           L_80015C10
    // 0x80013808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013808: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001380C:
    // 0x8001380C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013810: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80013814: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013818: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x8001381C: addiu       $s0, $zero, 0x1B7
    ctx->r16 = ADD32(0, 0X1B7);
    // 0x80013820: b           L_80015C10
    // 0x80013824: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013824: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013828:
    // 0x80013828: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001382C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80013830: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013834: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013838: addiu       $s0, $zero, 0x142
    ctx->r16 = ADD32(0, 0X142);
    // 0x8001383C: b           L_80015C10
    // 0x80013840: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013840: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013844:
    // 0x80013844: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80013848: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x8001384C: beq         $v0, $zero, L_80013858
    if (ctx->r2 == 0) {
        // 0x80013850: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80013858;
    }
    // 0x80013850: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80013854: sw          $t4, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r12;
L_80013858:
    // 0x80013858: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x8001385C: jal         0x800113B0
    // 0x80013860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800113B0(rdram, ctx);
        goto after_14;
    // 0x80013860: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80013864: b           L_80015E64
    // 0x80013868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80015E64;
    // 0x80013868: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001386C:
    // 0x8001386C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013870: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80013874: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013878: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001387C: b           L_80015C10
    // 0x80013880: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
        goto L_80015C10;
    // 0x80013880: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
L_80013884:
    // 0x80013884: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013888: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001388C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013890: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013894: b           L_80015C10
    // 0x80013898: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
        goto L_80015C10;
    // 0x80013898: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
L_8001389C:
    // 0x8001389C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800138A0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800138A4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800138A8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800138AC: b           L_80015C10
    // 0x800138B0: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
        goto L_80015C10;
    // 0x800138B0: addiu       $s0, $zero, 0x23C
    ctx->r16 = ADD32(0, 0X23C);
L_800138B4:
    // 0x800138B4: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800138B8: lbu         $t4, -0x6D58($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6D58);
    // 0x800138BC: beq         $t4, $zero, L_800138D0
    if (ctx->r12 == 0) {
        // 0x800138C0: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_800138D0;
    }
    // 0x800138C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800138C4: sb          $zero, -0x6D58($at)
    MEM_B(-0X6D58, ctx->r1) = 0;
    // 0x800138C8: b           L_800138E0
    // 0x800138CC: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
        goto L_800138E0;
    // 0x800138CC: addiu       $s0, $zero, 0x14A
    ctx->r16 = ADD32(0, 0X14A);
L_800138D0:
    // 0x800138D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800138D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800138D8: sb          $t5, -0x6D58($at)
    MEM_B(-0X6D58, ctx->r1) = ctx->r13;
    // 0x800138DC: addiu       $s0, $zero, 0x14B
    ctx->r16 = ADD32(0, 0X14B);
L_800138E0:
    // 0x800138E0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800138E4: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800138E8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800138EC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800138F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800138F4: b           L_80015C10
    // 0x800138F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800138F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800138FC:
    // 0x800138FC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013900: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80013904: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013908: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001390C: addiu       $s0, $zero, 0x1A1
    ctx->r16 = ADD32(0, 0X1A1);
    // 0x80013910: b           L_80015C10
    // 0x80013914: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013914: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80013918:
    // 0x80013918: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001391C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80013920: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013924: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013928: addiu       $s0, $zero, 0xEF
    ctx->r16 = ADD32(0, 0XEF);
    // 0x8001392C: b           L_80015C10
    // 0x80013930: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013930: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013934:
    // 0x80013934: beql        $s1, $zero, L_80013974
    if (ctx->r17 == 0) {
        // 0x80013938: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80013974;
    }
    goto skip_17;
    // 0x80013938: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    skip_17:
    // 0x8001393C: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x80013940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80013944: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80013948: bne         $at, $zero, L_8001396C
    if (ctx->r1 != 0) {
        // 0x8001394C: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_8001396C;
    }
    // 0x8001394C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013950: ldc1        $f0, -0x2000($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X2000);
L_80013954:
    // 0x80013954: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80013958: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001395C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80013960: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80013964: bne         $at, $zero, L_80013954
    if (ctx->r1 != 0) {
        // 0x80013968: cvt.s.d     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
            goto L_80013954;
    }
    // 0x80013968: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_8001396C:
    // 0x8001396C: addiu       $s0, $zero, 0x90
    ctx->r16 = ADD32(0, 0X90);
    // 0x80013970: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80013974:
    // 0x80013974: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80013978: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001397C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013980: b           L_80015C10
    // 0x80013984: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013984: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013988:
    // 0x80013988: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8001398C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80013990: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013994: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013998: b           L_80015C10
    // 0x8001399C: addiu       $s0, $zero, 0x1DF
    ctx->r16 = ADD32(0, 0X1DF);
        goto L_80015C10;
    // 0x8001399C: addiu       $s0, $zero, 0x1DF
    ctx->r16 = ADD32(0, 0X1DF);
L_800139A0:
    // 0x800139A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800139A4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800139A8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800139AC: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800139B0: addiu       $s0, $zero, 0x1E0
    ctx->r16 = ADD32(0, 0X1E0);
    // 0x800139B4: b           L_80015C10
    // 0x800139B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800139B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800139BC:
    // 0x800139BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800139C0: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800139C4: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800139C8: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800139CC: addiu       $s0, $zero, 0x1E1
    ctx->r16 = ADD32(0, 0X1E1);
    // 0x800139D0: b           L_80015C10
    // 0x800139D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800139D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800139D8:
    // 0x800139D8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800139DC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800139E0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800139E4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800139E8: addiu       $s0, $zero, 0x1E2
    ctx->r16 = ADD32(0, 0X1E2);
    // 0x800139EC: b           L_80015C10
    // 0x800139F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800139F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800139F4:
    // 0x800139F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800139F8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800139FC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013A00: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80013A04: b           L_80015C10
    // 0x80013A08: addiu       $s0, $zero, 0x1E3
    ctx->r16 = ADD32(0, 0X1E3);
        goto L_80015C10;
    // 0x80013A08: addiu       $s0, $zero, 0x1E3
    ctx->r16 = ADD32(0, 0X1E3);
L_80013A0C:
    // 0x80013A0C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013A10: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013A14: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013A18: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013A1C: addiu       $s0, $zero, 0x3D
    ctx->r16 = ADD32(0, 0X3D);
    // 0x80013A20: b           L_80015C10
    // 0x80013A24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013A24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013A28:
    // 0x80013A28: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80013A2C: lb          $t5, -0x6D54($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X6D54);
    // 0x80013A30: beq         $t5, $zero, L_80013A58
    if (ctx->r13 == 0) {
        // 0x80013A34: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_80013A58;
    }
    // 0x80013A34: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013A38: sb          $zero, -0x6D54($at)
    MEM_B(-0X6D54, ctx->r1) = 0;
    // 0x80013A3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013A40: ldc1        $f16, -0x1FC0($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1FC0);
    // 0x80013A44: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80013A48: mul.d       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x80013A4C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80013A50: b           L_80013A64
    // 0x80013A54: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
        goto L_80013A64;
    // 0x80013A54: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_80013A58:
    // 0x80013A58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013A5C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013A60: sb          $t6, -0x6D54($at)
    MEM_B(-0X6D54, ctx->r1) = ctx->r14;
L_80013A64:
    // 0x80013A64: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013A68: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80013A6C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013A70: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013A74: addiu       $s0, $zero, 0x156
    ctx->r16 = ADD32(0, 0X156);
    // 0x80013A78: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80013A7C: b           L_80015C10
    // 0x80013A80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013A80: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013A84:
    // 0x80013A84: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80013A88: lbu         $t9, -0x6D78($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X6D78);
    // 0x80013A8C: bne         $t9, $zero, L_80015E60
    if (ctx->r25 != 0) {
        // 0x80013A90: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80015E60;
    }
    // 0x80013A90: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013A94: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013A98: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013A9C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013AA0: addiu       $s0, $zero, 0x1FB
    ctx->r16 = ADD32(0, 0X1FB);
    // 0x80013AA4: b           L_80015C10
    // 0x80013AA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013AA8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013AAC:
    // 0x80013AAC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013AB0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013AB4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013AB8: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013ABC: addiu       $s0, $zero, 0x1FC
    ctx->r16 = ADD32(0, 0X1FC);
    // 0x80013AC0: b           L_80015C10
    // 0x80013AC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013AC4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013AC8:
    // 0x80013AC8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80013ACC: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80013AD0: beql        $v0, $zero, L_80013B2C
    if (ctx->r2 == 0) {
        // 0x80013AD4: addiu       $t5, $zero, 0x16
        ctx->r13 = ADD32(0, 0X16);
            goto L_80013B2C;
    }
    goto skip_18;
    // 0x80013AD4: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    skip_18:
    // 0x80013AD8: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80013ADC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80013AE0: bne         $t7, $at, L_80013B08
    if (ctx->r15 != ctx->r1) {
        // 0x80013AE4: lui         $t8, 0x800B
        ctx->r24 = S32(0X800B << 16);
            goto L_80013B08;
    }
    // 0x80013AE4: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80013AE8: lw          $t8, 0x6BA4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6BA4);
    // 0x80013AEC: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80013AF0: beq         $t9, $zero, L_80013B00
    if (ctx->r25 == 0) {
        // 0x80013AF4: nop
    
            goto L_80013B00;
    }
    // 0x80013AF4: nop

    // 0x80013AF8: b           L_80013B28
    // 0x80013AFC: addiu       $s0, $zero, 0x251
    ctx->r16 = ADD32(0, 0X251);
        goto L_80013B28;
    // 0x80013AFC: addiu       $s0, $zero, 0x251
    ctx->r16 = ADD32(0, 0X251);
L_80013B00:
    // 0x80013B00: b           L_80013B28
    // 0x80013B04: addiu       $s0, $zero, 0x28C
    ctx->r16 = ADD32(0, 0X28C);
        goto L_80013B28;
    // 0x80013B04: addiu       $s0, $zero, 0x28C
    ctx->r16 = ADD32(0, 0X28C);
L_80013B08:
    // 0x80013B08: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80013B0C: lw          $t3, 0x6BA4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6BA4);
    // 0x80013B10: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80013B14: beql        $t4, $zero, L_80013B28
    if (ctx->r12 == 0) {
        // 0x80013B18: addiu       $s0, $zero, 0x28E
        ctx->r16 = ADD32(0, 0X28E);
            goto L_80013B28;
    }
    goto skip_19;
    // 0x80013B18: addiu       $s0, $zero, 0x28E
    ctx->r16 = ADD32(0, 0X28E);
    skip_19:
    // 0x80013B1C: b           L_80013B28
    // 0x80013B20: addiu       $s0, $zero, 0x28D
    ctx->r16 = ADD32(0, 0X28D);
        goto L_80013B28;
    // 0x80013B20: addiu       $s0, $zero, 0x28D
    ctx->r16 = ADD32(0, 0X28D);
    // 0x80013B24: addiu       $s0, $zero, 0x28E
    ctx->r16 = ADD32(0, 0X28E);
L_80013B28:
    // 0x80013B28: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
L_80013B2C:
    // 0x80013B2C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013B30: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013B34: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013B38: b           L_80015C10
    // 0x80013B3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013B3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013B40:
    // 0x80013B40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013B44: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013B48: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013B4C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013B50: addiu       $s0, $zero, 0x1FF
    ctx->r16 = ADD32(0, 0X1FF);
    // 0x80013B54: b           L_80015C10
    // 0x80013B58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013B58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013B5C:
    // 0x80013B5C: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x80013B60: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013B64: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013B68: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013B6C: addiu       $s0, $zero, 0x23B
    ctx->r16 = ADD32(0, 0X23B);
    // 0x80013B70: beq         $s1, $zero, L_80013BDC
    if (ctx->r17 == 0) {
        // 0x80013B74: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80013BDC;
    }
    // 0x80013B74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013B78: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x80013B7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80013B80: bne         $t4, $at, L_80013BDC
    if (ctx->r12 != ctx->r1) {
        // 0x80013B84: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80013BDC;
    }
    // 0x80013B84: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80013B88: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80013B8C: beq         $v0, $zero, L_80013BDC
    if (ctx->r2 == 0) {
        // 0x80013B90: nop
    
            goto L_80013BDC;
    }
    // 0x80013B90: nop

    // 0x80013B94: lh          $t5, 0x2($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X2);
    // 0x80013B98: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80013B9C: bne         $t5, $at, L_80013BD8
    if (ctx->r13 != ctx->r1) {
        // 0x80013BA0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80013BD8;
    }
    // 0x80013BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80013BA4: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80013BA8: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80013BAC: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80013BB0: jal         0x8001137C
    // 0x80013BB4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_8001137C(rdram, ctx);
        goto after_15;
    // 0x80013BB4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_15:
    // 0x80013BB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013BBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80013BC0: sb          $t6, -0x6D78($at)
    MEM_B(-0X6D78, ctx->r1) = ctx->r14;
    // 0x80013BC4: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80013BC8: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80013BCC: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80013BD0: b           L_80013BDC
    // 0x80013BD4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80013BDC;
    // 0x80013BD4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80013BD8:
    // 0x80013BD8: addiu       $s0, $zero, 0x290
    ctx->r16 = ADD32(0, 0X290);
L_80013BDC:
    // 0x80013BDC: b           L_80015C14
    // 0x80013BE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80015C14;
    // 0x80013BE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80013BE4:
    // 0x80013BE4: addiu       $t7, $zero, 0x16
    ctx->r15 = ADD32(0, 0X16);
    // 0x80013BE8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013BEC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013BF0: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013BF4: b           L_80015C10
    // 0x80013BF8: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
        goto L_80015C10;
    // 0x80013BF8: addiu       $s0, $zero, 0x200
    ctx->r16 = ADD32(0, 0X200);
L_80013BFC:
    // 0x80013BFC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013C00: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013C04: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013C08: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013C0C: addiu       $s0, $zero, 0x202
    ctx->r16 = ADD32(0, 0X202);
    // 0x80013C10: b           L_80015C10
    // 0x80013C14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013C14: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013C18:
    // 0x80013C18: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80013C1C: lbu         $t4, -0x6D78($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X6D78);
    // 0x80013C20: bne         $t4, $zero, L_80015E60
    if (ctx->r12 != 0) {
        // 0x80013C24: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80015E60;
    }
    // 0x80013C24: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013C28: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013C2C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013C30: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013C34: addiu       $s0, $zero, 0x1FE
    ctx->r16 = ADD32(0, 0X1FE);
    // 0x80013C38: b           L_80015C10
    // 0x80013C3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013C3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013C40:
    // 0x80013C40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013C44: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013C48: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013C4C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013C50: addiu       $s0, $zero, 0x1FE
    ctx->r16 = ADD32(0, 0X1FE);
    // 0x80013C54: b           L_80015C10
    // 0x80013C58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013C58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013C5C:
    // 0x80013C5C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013C60: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013C64: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013C68: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013C6C: addiu       $s0, $zero, 0x1FD
    ctx->r16 = ADD32(0, 0X1FD);
    // 0x80013C70: b           L_80015C10
    // 0x80013C74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013C74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013C78:
    // 0x80013C78: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80013C7C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80013C80: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013C84: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013C88: addiu       $s0, $zero, 0x208
    ctx->r16 = ADD32(0, 0X208);
    // 0x80013C8C: b           L_80015C10
    // 0x80013C90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013C90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013C94:
    // 0x80013C94: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80013C98: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013C9C: addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
    // 0x80013CA0: b           L_80015C10
    // 0x80013CA4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80013CA4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80013CA8:
    // 0x80013CA8: beql        $s1, $zero, L_80013CE4
    if (ctx->r17 == 0) {
        // 0x80013CAC: addiu       $t8, $zero, 0xE
        ctx->r24 = ADD32(0, 0XE);
            goto L_80013CE4;
    }
    goto skip_20;
    // 0x80013CAC: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    skip_20:
    // 0x80013CB0: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x80013CB4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013CB8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80013CBC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80013CC0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80013CC4: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80013CC8: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80013CCC: mul.d       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80013CD0: nop

    // 0x80013CD4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80013CD8: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80013CDC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80013CE0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
L_80013CE4:
    // 0x80013CE4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80013CE8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013CEC: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80013CF0: b           L_80015C10
    // 0x80013CF4: addiu       $s0, $zero, 0x213
    ctx->r16 = ADD32(0, 0X213);
        goto L_80015C10;
    // 0x80013CF4: addiu       $s0, $zero, 0x213
    ctx->r16 = ADD32(0, 0X213);
L_80013CF8:
    // 0x80013CF8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80013CFC: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013D00: addiu       $s0, $zero, 0x24E
    ctx->r16 = ADD32(0, 0X24E);
    // 0x80013D04: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013D08: b           L_80015C10
    // 0x80013D0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013D0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013D10:
    // 0x80013D10: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80013D14: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013D18: addiu       $s0, $zero, 0x24F
    ctx->r16 = ADD32(0, 0X24F);
    // 0x80013D1C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013D20: b           L_80015C10
    // 0x80013D24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013D24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013D28:
    // 0x80013D28: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013D2C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013D30: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013D34: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013D38: b           L_80015C10
    // 0x80013D3C: addiu       $s0, $zero, 0x215
    ctx->r16 = ADD32(0, 0X215);
        goto L_80015C10;
    // 0x80013D3C: addiu       $s0, $zero, 0x215
    ctx->r16 = ADD32(0, 0X215);
L_80013D40:
    // 0x80013D40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013D44: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80013D48: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013D4C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013D50: addiu       $s0, $zero, 0x20B
    ctx->r16 = ADD32(0, 0X20B);
    // 0x80013D54: b           L_80015C10
    // 0x80013D58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013D58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013D5C:
    // 0x80013D5C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80013D60: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013D64: addiu       $s0, $zero, 0x123
    ctx->r16 = ADD32(0, 0X123);
    // 0x80013D68: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013D6C: b           L_80015C10
    // 0x80013D70: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013D70: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013D74:
    // 0x80013D74: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013D78: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80013D7C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013D80: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013D84: b           L_80015C10
    // 0x80013D88: addiu       $s0, $zero, 0x239
    ctx->r16 = ADD32(0, 0X239);
        goto L_80015C10;
    // 0x80013D88: addiu       $s0, $zero, 0x239
    ctx->r16 = ADD32(0, 0X239);
L_80013D8C:
    // 0x80013D8C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80013D90: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013D94: addiu       $s0, $zero, 0x24C
    ctx->r16 = ADD32(0, 0X24C);
    // 0x80013D98: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013D9C: b           L_80015C10
    // 0x80013DA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013DA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013DA4:
    // 0x80013DA4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80013DA8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013DAC: addiu       $s0, $zero, 0x23F
    ctx->r16 = ADD32(0, 0X23F);
    // 0x80013DB0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013DB4: b           L_80015C10
    // 0x80013DB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013DB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013DBC:
    // 0x80013DBC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80013DC0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80013DC4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013DC8: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80013DCC: addiu       $s0, $zero, 0x243
    ctx->r16 = ADD32(0, 0X243);
    // 0x80013DD0: b           L_80015C10
    // 0x80013DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013DD8:
    // 0x80013DD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013DDC: ldc1        $f8, -0x1F00($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X1F00);
    // 0x80013DE0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80013DE4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013DE8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80013DEC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013DF0: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013DF4: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013DF8: addiu       $s0, $zero, 0xC0
    ctx->r16 = ADD32(0, 0XC0);
    // 0x80013DFC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013E00: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80013E04: b           L_80015C10
    // 0x80013E08: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
        goto L_80015C10;
    // 0x80013E08: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_80013E0C:
    // 0x80013E0C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80013E10: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80013E14: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013E18: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013E1C: addiu       $s0, $zero, 0x144
    ctx->r16 = ADD32(0, 0X144);
    // 0x80013E20: b           L_80015C10
    // 0x80013E24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013E24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013E28:
    // 0x80013E28: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013E2C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013E30: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013E34: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80013E38: addiu       $s0, $zero, 0x1FC
    ctx->r16 = ADD32(0, 0X1FC);
    // 0x80013E3C: b           L_80015C10
    // 0x80013E40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013E40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013E44:
    // 0x80013E44: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80013E48: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80013E4C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80013E50: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80013E54: addiu       $s0, $zero, 0x24B
    ctx->r16 = ADD32(0, 0X24B);
    // 0x80013E58: b           L_80015C10
    // 0x80013E5C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013E5C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80013E60:
    // 0x80013E60: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80013E64: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80013E68: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80013E6C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80013E70: addiu       $s0, $zero, 0x18C
    ctx->r16 = ADD32(0, 0X18C);
    // 0x80013E74: b           L_80015C10
    // 0x80013E78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013E78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013E7C:
    // 0x80013E7C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80013E80: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80013E84: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013E88: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013E8C: addiu       $s0, $zero, 0xEC
    ctx->r16 = ADD32(0, 0XEC);
    // 0x80013E90: b           L_80015C10
    // 0x80013E94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013E94: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013E98:
    // 0x80013E98: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80013E9C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013EA0: addiu       $s0, $zero, 0x257
    ctx->r16 = ADD32(0, 0X257);
    // 0x80013EA4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013EA8: b           L_80015C10
    // 0x80013EAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013EAC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013EB0:
    // 0x80013EB0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80013EB4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80013EB8: addiu       $s0, $zero, 0x258
    ctx->r16 = ADD32(0, 0X258);
    // 0x80013EBC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80013EC0: b           L_80015C10
    // 0x80013EC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013EC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013EC8:
    // 0x80013EC8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80013ECC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80013ED0: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013ED4: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013ED8: addiu       $s0, $zero, 0x28B
    ctx->r16 = ADD32(0, 0X28B);
    // 0x80013EDC: b           L_80015C10
    // 0x80013EE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013EE0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013EE4:
    // 0x80013EE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013EE8: ldc1        $f4, -0x1EB0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1EB0);
    // 0x80013EEC: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80013EF0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80013EF4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x80013EF8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80013EFC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80013F00: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80013F04: addiu       $s0, $zero, 0x1FC
    ctx->r16 = ADD32(0, 0X1FC);
    // 0x80013F08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013F0C: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80013F10: b           L_80015C10
    // 0x80013F14: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_80015C10;
    // 0x80013F14: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80013F18:
    // 0x80013F18: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80013F1C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80013F20: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80013F24: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80013F28: addiu       $s0, $zero, 0x255
    ctx->r16 = ADD32(0, 0X255);
    // 0x80013F2C: b           L_80015C10
    // 0x80013F30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013F30: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013F34:
    // 0x80013F34: beql        $s1, $zero, L_80013F64
    if (ctx->r17 == 0) {
        // 0x80013F38: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80013F64;
    }
    goto skip_21;
    // 0x80013F38: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_21:
    // 0x80013F3C: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
    // 0x80013F40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013F44: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80013F48: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80013F4C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80013F50: cvt.d.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.d = CVT_D_W(ctx->f10.u32l);
    // 0x80013F54: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80013F58: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80013F5C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x80013F60: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80013F64:
    // 0x80013F64: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80013F68: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80013F6C: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80013F70: addiu       $s0, $zero, 0x25F
    ctx->r16 = ADD32(0, 0X25F);
    // 0x80013F74: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013F78: b           L_80015C10
    // 0x80013F7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013F7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013F80:
    // 0x80013F80: beql        $s1, $zero, L_80013FB0
    if (ctx->r17 == 0) {
        // 0x80013F84: addiu       $t5, $zero, -0x1
        ctx->r13 = ADD32(0, -0X1);
            goto L_80013FB0;
    }
    goto skip_22;
    // 0x80013F84: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    skip_22:
    // 0x80013F88: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x80013F8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013F90: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80013F94: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80013F98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80013F9C: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80013FA0: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80013FA4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x80013FA8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x80013FAC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
L_80013FB0:
    // 0x80013FB0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80013FB4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80013FB8: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80013FBC: addiu       $s0, $zero, 0x25E
    ctx->r16 = ADD32(0, 0X25E);
    // 0x80013FC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80013FC4: b           L_80015C10
    // 0x80013FC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80013FC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80013FCC:
    // 0x80013FCC: beql        $s1, $zero, L_80014038
    if (ctx->r17 == 0) {
        // 0x80013FD0: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80014038;
    }
    goto skip_23;
    // 0x80013FD0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    skip_23:
    // 0x80013FD4: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x80013FD8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80013FDC: sh          $t7, -0x4830($at)
    MEM_H(-0X4830, ctx->r1) = ctx->r15;
    // 0x80013FE0: lw          $t8, 0x14($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X14);
    // 0x80013FE4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80013FE8: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x80013FEC: beq         $at, $zero, L_80015E60
    if (ctx->r1 == 0) {
        // 0x80013FF0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80015E60;
    }
    // 0x80013FF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80013FF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80013FF8: addu        $at, $at, $t9
    gpr jr_addend_80014000 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80013FFC: lw          $t9, -0x1E88($at)
    ctx->r25 = ADD32(ctx->r1, -0X1E88);
    // 0x80014000: jr          $t9
    // 0x80014004: nop

    switch (jr_addend_80014000 >> 2) {
        case 0: goto L_80014008; break;
        case 1: goto L_80015E60; break;
        case 2: goto L_80014010; break;
        case 3: goto L_80014018; break;
        case 4: goto L_80014020; break;
        case 5: goto L_80015E60; break;
        case 6: goto L_80015E60; break;
        case 7: goto L_80015E60; break;
        case 8: goto L_80015E60; break;
        case 9: goto L_80014028; break;
        case 10: goto L_80014030; break;
        default: switch_error(__func__, 0x80014000, 0x800AE178);
    }
    // 0x80014004: nop

L_80014008:
    // 0x80014008: b           L_80014034
    // 0x8001400C: addiu       $s0, $zero, 0x260
    ctx->r16 = ADD32(0, 0X260);
        goto L_80014034;
    // 0x8001400C: addiu       $s0, $zero, 0x260
    ctx->r16 = ADD32(0, 0X260);
L_80014010:
    // 0x80014010: b           L_80014034
    // 0x80014014: addiu       $s0, $zero, 0x1D3
    ctx->r16 = ADD32(0, 0X1D3);
        goto L_80014034;
    // 0x80014014: addiu       $s0, $zero, 0x1D3
    ctx->r16 = ADD32(0, 0X1D3);
L_80014018:
    // 0x80014018: b           L_80014034
    // 0x8001401C: addiu       $s0, $zero, 0x1D4
    ctx->r16 = ADD32(0, 0X1D4);
        goto L_80014034;
    // 0x8001401C: addiu       $s0, $zero, 0x1D4
    ctx->r16 = ADD32(0, 0X1D4);
L_80014020:
    // 0x80014020: b           L_80014034
    // 0x80014024: addiu       $s0, $zero, 0x1D5
    ctx->r16 = ADD32(0, 0X1D5);
        goto L_80014034;
    // 0x80014024: addiu       $s0, $zero, 0x1D5
    ctx->r16 = ADD32(0, 0X1D5);
L_80014028:
    // 0x80014028: b           L_80014034
    // 0x8001402C: addiu       $s0, $zero, 0x1D6
    ctx->r16 = ADD32(0, 0X1D6);
        goto L_80014034;
    // 0x8001402C: addiu       $s0, $zero, 0x1D6
    ctx->r16 = ADD32(0, 0X1D6);
L_80014030:
    // 0x80014030: addiu       $s0, $zero, 0x1D7
    ctx->r16 = ADD32(0, 0X1D7);
L_80014034:
    // 0x80014034: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80014038:
    // 0x80014038: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001403C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014040: b           L_80015C10
    // 0x80014044: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
        goto L_80015C10;
    // 0x80014044: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
L_80014048:
    // 0x80014048: beql        $s1, $zero, L_80014160
    if (ctx->r17 == 0) {
        // 0x8001404C: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80014160;
    }
    goto skip_24;
    // 0x8001404C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_24:
    // 0x80014050: lw          $t5, 0x18($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X18);
    // 0x80014054: addiu       $t6, $t5, -0x2
    ctx->r14 = ADD32(ctx->r13, -0X2);
    // 0x80014058: sltiu       $at, $t6, 0x1D
    ctx->r1 = ctx->r14 < 0X1D ? 1 : 0;
    // 0x8001405C: beq         $at, $zero, L_80015E60
    if (ctx->r1 == 0) {
        // 0x80014060: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80015E60;
    }
    // 0x80014060: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80014064: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014068: addu        $at, $at, $t6
    gpr jr_addend_80014070 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001406C: lw          $t6, -0x1E50($at)
    ctx->r14 = ADD32(ctx->r1, -0X1E50);
    // 0x80014070: jr          $t6
    // 0x80014074: nop

    switch (jr_addend_80014070 >> 2) {
        case 0: goto L_80014078; break;
        case 1: goto L_80014080; break;
        case 2: goto L_80014088; break;
        case 3: goto L_80014090; break;
        case 4: goto L_80014098; break;
        case 5: goto L_800140A0; break;
        case 6: goto L_800140A8; break;
        case 7: goto L_800140B0; break;
        case 8: goto L_800140B8; break;
        case 9: goto L_800140C0; break;
        case 10: goto L_800140C8; break;
        case 11: goto L_800140D0; break;
        case 12: goto L_800140D8; break;
        case 13: goto L_800140E0; break;
        case 14: goto L_800140E8; break;
        case 15: goto L_800140F0; break;
        case 16: goto L_800140F8; break;
        case 17: goto L_80014100; break;
        case 18: goto L_80014108; break;
        case 19: goto L_80014110; break;
        case 20: goto L_80014118; break;
        case 21: goto L_80014120; break;
        case 22: goto L_80014128; break;
        case 23: goto L_80014130; break;
        case 24: goto L_80014138; break;
        case 25: goto L_80014140; break;
        case 26: goto L_80014148; break;
        case 27: goto L_80014150; break;
        case 28: goto L_80014158; break;
        default: switch_error(__func__, 0x80014070, 0x800AE1B0);
    }
    // 0x80014074: nop

L_80014078:
    // 0x80014078: b           L_8001415C
    // 0x8001407C: addiu       $s0, $zero, 0x267
    ctx->r16 = ADD32(0, 0X267);
        goto L_8001415C;
    // 0x8001407C: addiu       $s0, $zero, 0x267
    ctx->r16 = ADD32(0, 0X267);
L_80014080:
    // 0x80014080: b           L_8001415C
    // 0x80014084: addiu       $s0, $zero, 0x268
    ctx->r16 = ADD32(0, 0X268);
        goto L_8001415C;
    // 0x80014084: addiu       $s0, $zero, 0x268
    ctx->r16 = ADD32(0, 0X268);
L_80014088:
    // 0x80014088: b           L_8001415C
    // 0x8001408C: addiu       $s0, $zero, 0x269
    ctx->r16 = ADD32(0, 0X269);
        goto L_8001415C;
    // 0x8001408C: addiu       $s0, $zero, 0x269
    ctx->r16 = ADD32(0, 0X269);
L_80014090:
    // 0x80014090: b           L_8001415C
    // 0x80014094: addiu       $s0, $zero, 0x26A
    ctx->r16 = ADD32(0, 0X26A);
        goto L_8001415C;
    // 0x80014094: addiu       $s0, $zero, 0x26A
    ctx->r16 = ADD32(0, 0X26A);
L_80014098:
    // 0x80014098: b           L_8001415C
    // 0x8001409C: addiu       $s0, $zero, 0x26B
    ctx->r16 = ADD32(0, 0X26B);
        goto L_8001415C;
    // 0x8001409C: addiu       $s0, $zero, 0x26B
    ctx->r16 = ADD32(0, 0X26B);
L_800140A0:
    // 0x800140A0: b           L_8001415C
    // 0x800140A4: addiu       $s0, $zero, 0x26C
    ctx->r16 = ADD32(0, 0X26C);
        goto L_8001415C;
    // 0x800140A4: addiu       $s0, $zero, 0x26C
    ctx->r16 = ADD32(0, 0X26C);
L_800140A8:
    // 0x800140A8: b           L_8001415C
    // 0x800140AC: addiu       $s0, $zero, 0x26D
    ctx->r16 = ADD32(0, 0X26D);
        goto L_8001415C;
    // 0x800140AC: addiu       $s0, $zero, 0x26D
    ctx->r16 = ADD32(0, 0X26D);
L_800140B0:
    // 0x800140B0: b           L_8001415C
    // 0x800140B4: addiu       $s0, $zero, 0x26E
    ctx->r16 = ADD32(0, 0X26E);
        goto L_8001415C;
    // 0x800140B4: addiu       $s0, $zero, 0x26E
    ctx->r16 = ADD32(0, 0X26E);
L_800140B8:
    // 0x800140B8: b           L_8001415C
    // 0x800140BC: addiu       $s0, $zero, 0x26F
    ctx->r16 = ADD32(0, 0X26F);
        goto L_8001415C;
    // 0x800140BC: addiu       $s0, $zero, 0x26F
    ctx->r16 = ADD32(0, 0X26F);
L_800140C0:
    // 0x800140C0: b           L_8001415C
    // 0x800140C4: addiu       $s0, $zero, 0x270
    ctx->r16 = ADD32(0, 0X270);
        goto L_8001415C;
    // 0x800140C4: addiu       $s0, $zero, 0x270
    ctx->r16 = ADD32(0, 0X270);
L_800140C8:
    // 0x800140C8: b           L_8001415C
    // 0x800140CC: addiu       $s0, $zero, 0x271
    ctx->r16 = ADD32(0, 0X271);
        goto L_8001415C;
    // 0x800140CC: addiu       $s0, $zero, 0x271
    ctx->r16 = ADD32(0, 0X271);
L_800140D0:
    // 0x800140D0: b           L_8001415C
    // 0x800140D4: addiu       $s0, $zero, 0x272
    ctx->r16 = ADD32(0, 0X272);
        goto L_8001415C;
    // 0x800140D4: addiu       $s0, $zero, 0x272
    ctx->r16 = ADD32(0, 0X272);
L_800140D8:
    // 0x800140D8: b           L_8001415C
    // 0x800140DC: addiu       $s0, $zero, 0x273
    ctx->r16 = ADD32(0, 0X273);
        goto L_8001415C;
    // 0x800140DC: addiu       $s0, $zero, 0x273
    ctx->r16 = ADD32(0, 0X273);
L_800140E0:
    // 0x800140E0: b           L_8001415C
    // 0x800140E4: addiu       $s0, $zero, 0x274
    ctx->r16 = ADD32(0, 0X274);
        goto L_8001415C;
    // 0x800140E4: addiu       $s0, $zero, 0x274
    ctx->r16 = ADD32(0, 0X274);
L_800140E8:
    // 0x800140E8: b           L_8001415C
    // 0x800140EC: addiu       $s0, $zero, 0x275
    ctx->r16 = ADD32(0, 0X275);
        goto L_8001415C;
    // 0x800140EC: addiu       $s0, $zero, 0x275
    ctx->r16 = ADD32(0, 0X275);
L_800140F0:
    // 0x800140F0: b           L_8001415C
    // 0x800140F4: addiu       $s0, $zero, 0x276
    ctx->r16 = ADD32(0, 0X276);
        goto L_8001415C;
    // 0x800140F4: addiu       $s0, $zero, 0x276
    ctx->r16 = ADD32(0, 0X276);
L_800140F8:
    // 0x800140F8: b           L_8001415C
    // 0x800140FC: addiu       $s0, $zero, 0x277
    ctx->r16 = ADD32(0, 0X277);
        goto L_8001415C;
    // 0x800140FC: addiu       $s0, $zero, 0x277
    ctx->r16 = ADD32(0, 0X277);
L_80014100:
    // 0x80014100: b           L_8001415C
    // 0x80014104: addiu       $s0, $zero, 0x278
    ctx->r16 = ADD32(0, 0X278);
        goto L_8001415C;
    // 0x80014104: addiu       $s0, $zero, 0x278
    ctx->r16 = ADD32(0, 0X278);
L_80014108:
    // 0x80014108: b           L_8001415C
    // 0x8001410C: addiu       $s0, $zero, 0x279
    ctx->r16 = ADD32(0, 0X279);
        goto L_8001415C;
    // 0x8001410C: addiu       $s0, $zero, 0x279
    ctx->r16 = ADD32(0, 0X279);
L_80014110:
    // 0x80014110: b           L_8001415C
    // 0x80014114: addiu       $s0, $zero, 0x27A
    ctx->r16 = ADD32(0, 0X27A);
        goto L_8001415C;
    // 0x80014114: addiu       $s0, $zero, 0x27A
    ctx->r16 = ADD32(0, 0X27A);
L_80014118:
    // 0x80014118: b           L_8001415C
    // 0x8001411C: addiu       $s0, $zero, 0x27B
    ctx->r16 = ADD32(0, 0X27B);
        goto L_8001415C;
    // 0x8001411C: addiu       $s0, $zero, 0x27B
    ctx->r16 = ADD32(0, 0X27B);
L_80014120:
    // 0x80014120: b           L_8001415C
    // 0x80014124: addiu       $s0, $zero, 0x27C
    ctx->r16 = ADD32(0, 0X27C);
        goto L_8001415C;
    // 0x80014124: addiu       $s0, $zero, 0x27C
    ctx->r16 = ADD32(0, 0X27C);
L_80014128:
    // 0x80014128: b           L_8001415C
    // 0x8001412C: addiu       $s0, $zero, 0x27D
    ctx->r16 = ADD32(0, 0X27D);
        goto L_8001415C;
    // 0x8001412C: addiu       $s0, $zero, 0x27D
    ctx->r16 = ADD32(0, 0X27D);
L_80014130:
    // 0x80014130: b           L_8001415C
    // 0x80014134: addiu       $s0, $zero, 0x27E
    ctx->r16 = ADD32(0, 0X27E);
        goto L_8001415C;
    // 0x80014134: addiu       $s0, $zero, 0x27E
    ctx->r16 = ADD32(0, 0X27E);
L_80014138:
    // 0x80014138: b           L_8001415C
    // 0x8001413C: addiu       $s0, $zero, 0x27F
    ctx->r16 = ADD32(0, 0X27F);
        goto L_8001415C;
    // 0x8001413C: addiu       $s0, $zero, 0x27F
    ctx->r16 = ADD32(0, 0X27F);
L_80014140:
    // 0x80014140: b           L_8001415C
    // 0x80014144: addiu       $s0, $zero, 0x280
    ctx->r16 = ADD32(0, 0X280);
        goto L_8001415C;
    // 0x80014144: addiu       $s0, $zero, 0x280
    ctx->r16 = ADD32(0, 0X280);
L_80014148:
    // 0x80014148: b           L_8001415C
    // 0x8001414C: addiu       $s0, $zero, 0x281
    ctx->r16 = ADD32(0, 0X281);
        goto L_8001415C;
    // 0x8001414C: addiu       $s0, $zero, 0x281
    ctx->r16 = ADD32(0, 0X281);
L_80014150:
    // 0x80014150: b           L_8001415C
    // 0x80014154: addiu       $s0, $zero, 0x282
    ctx->r16 = ADD32(0, 0X282);
        goto L_8001415C;
    // 0x80014154: addiu       $s0, $zero, 0x282
    ctx->r16 = ADD32(0, 0X282);
L_80014158:
    // 0x80014158: addiu       $s0, $zero, 0x283
    ctx->r16 = ADD32(0, 0X283);
L_8001415C:
    // 0x8001415C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80014160:
    // 0x80014160: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014164: b           L_80015C10
    // 0x80014168: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80014168: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
L_8001416C:
    // 0x8001416C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80014170: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80014174: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014178: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001417C: addiu       $s0, $zero, 0x28A
    ctx->r16 = ADD32(0, 0X28A);
    // 0x80014180: b           L_80015C10
    // 0x80014184: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014184: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014188:
    // 0x80014188: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8001418C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80014190: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014194: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014198: addiu       $s0, $zero, 0x182
    ctx->r16 = ADD32(0, 0X182);
    // 0x8001419C: b           L_80015C10
    // 0x800141A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800141A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800141A4:
    // 0x800141A4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800141A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800141AC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800141B0: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800141B4: addiu       $s0, $zero, 0x298
    ctx->r16 = ADD32(0, 0X298);
    // 0x800141B8: b           L_80015C10
    // 0x800141BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800141BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800141C0:
    // 0x800141C0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800141C4: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800141C8: addiu       $s0, $zero, 0x283
    ctx->r16 = ADD32(0, 0X283);
    // 0x800141CC: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x800141D0: b           L_80015C10
    // 0x800141D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800141D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800141D8:
    // 0x800141D8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800141DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800141E0: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800141E4: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800141E8: addiu       $s0, $zero, 0x187
    ctx->r16 = ADD32(0, 0X187);
    // 0x800141EC: b           L_80015C10
    // 0x800141F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800141F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800141F4:
    // 0x800141F4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800141F8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800141FC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014200: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014204: addiu       $s0, $zero, 0x1A3
    ctx->r16 = ADD32(0, 0X1A3);
    // 0x80014208: b           L_80015C10
    // 0x8001420C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001420C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014210:
    // 0x80014210: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014214: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014218: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001421C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014220: addiu       $s0, $zero, 0x1A4
    ctx->r16 = ADD32(0, 0X1A4);
    // 0x80014224: b           L_80015C10
    // 0x80014228: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014228: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001422C:
    // 0x8001422C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014230: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80014234: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014238: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x8001423C: addiu       $s0, $zero, 0x66
    ctx->r16 = ADD32(0, 0X66);
    // 0x80014240: b           L_80015C10
    // 0x80014244: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014244: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014248:
    // 0x80014248: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001424C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80014250: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014254: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014258: b           L_80015C10
    // 0x8001425C: addiu       $s0, $zero, 0x68
    ctx->r16 = ADD32(0, 0X68);
        goto L_80015C10;
    // 0x8001425C: addiu       $s0, $zero, 0x68
    ctx->r16 = ADD32(0, 0X68);
L_80014260:
    // 0x80014260: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014264: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014268: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001426C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014270: addiu       $s0, $zero, 0x69
    ctx->r16 = ADD32(0, 0X69);
    // 0x80014274: b           L_80015C10
    // 0x80014278: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014278: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001427C:
    // 0x8001427C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80014280: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80014284: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014288: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8001428C: b           L_80015C10
    // 0x80014290: addiu       $s0, $zero, 0x30
    ctx->r16 = ADD32(0, 0X30);
        goto L_80015C10;
    // 0x80014290: addiu       $s0, $zero, 0x30
    ctx->r16 = ADD32(0, 0X30);
L_80014294:
    // 0x80014294: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80014298: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001429C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800142A0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800142A4: b           L_80015C10
    // 0x800142A8: addiu       $s0, $zero, 0x1A9
    ctx->r16 = ADD32(0, 0X1A9);
        goto L_80015C10;
    // 0x800142A8: addiu       $s0, $zero, 0x1A9
    ctx->r16 = ADD32(0, 0X1A9);
L_800142AC:
    // 0x800142AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800142B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800142B4: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800142B8: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800142BC: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800142C0: jal         0x80018CB0
    // 0x800142C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80018CB0(rdram, ctx);
        goto after_16;
    // 0x800142C4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_16:
    // 0x800142C8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800142CC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800142D0: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800142D4: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800142D8: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x800142DC: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800142E0: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800142E4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800142E8: b           L_80015C10
    // 0x800142EC: addiu       $s0, $zero, 0x1AA
    ctx->r16 = ADD32(0, 0X1AA);
        goto L_80015C10;
    // 0x800142EC: addiu       $s0, $zero, 0x1AA
    ctx->r16 = ADD32(0, 0X1AA);
L_800142F0:
    // 0x800142F0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800142F4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800142F8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800142FC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014300: addiu       $s0, $zero, 0x7C
    ctx->r16 = ADD32(0, 0X7C);
    // 0x80014304: b           L_80015C10
    // 0x80014308: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014308: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001430C:
    // 0x8001430C: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80014310: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014314: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014318: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x8001431C: b           L_80015C10
    // 0x80014320: addiu       $s0, $zero, 0x70
    ctx->r16 = ADD32(0, 0X70);
        goto L_80015C10;
    // 0x80014320: addiu       $s0, $zero, 0x70
    ctx->r16 = ADD32(0, 0X70);
L_80014324:
    // 0x80014324: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80014328: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8001432C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014330: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014334: addiu       $s0, $zero, 0x72
    ctx->r16 = ADD32(0, 0X72);
    // 0x80014338: b           L_80015C10
    // 0x8001433C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001433C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014340:
    // 0x80014340: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014344: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014348: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001434C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014350: addiu       $s0, $zero, 0x73
    ctx->r16 = ADD32(0, 0X73);
    // 0x80014354: b           L_80015C10
    // 0x80014358: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014358: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001435C:
    // 0x8001435C: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x80014360: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80014364: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014368: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8001436C: addiu       $s0, $zero, 0x74
    ctx->r16 = ADD32(0, 0X74);
    // 0x80014370: b           L_80015C10
    // 0x80014374: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014374: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014378:
    // 0x80014378: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001437C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80014380: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014384: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014388: b           L_80015C10
    // 0x8001438C: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
        goto L_80015C10;
    // 0x8001438C: addiu       $s0, $zero, 0x78
    ctx->r16 = ADD32(0, 0X78);
L_80014390:
    // 0x80014390: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014394: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80014398: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001439C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800143A0: addiu       $s0, $zero, 0x79
    ctx->r16 = ADD32(0, 0X79);
    // 0x800143A4: b           L_80015C10
    // 0x800143A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800143A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800143AC:
    // 0x800143AC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800143B0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800143B4: addiu       $s0, $zero, 0x55
    ctx->r16 = ADD32(0, 0X55);
    // 0x800143B8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800143BC: b           L_80015C10
    // 0x800143C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800143C0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800143C4:
    // 0x800143C4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800143C8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800143CC: addiu       $s0, $zero, 0x4F
    ctx->r16 = ADD32(0, 0X4F);
    // 0x800143D0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800143D4: b           L_80015C10
    // 0x800143D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800143D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800143DC:
    // 0x800143DC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800143E0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800143E4: addiu       $s0, $zero, 0x76
    ctx->r16 = ADD32(0, 0X76);
    // 0x800143E8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800143EC: b           L_80015C10
    // 0x800143F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800143F0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800143F4:
    // 0x800143F4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800143F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800143FC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014400: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014404: addiu       $s0, $zero, 0x77
    ctx->r16 = ADD32(0, 0X77);
    // 0x80014408: b           L_80015C10
    // 0x8001440C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001440C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014410:
    // 0x80014410: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80014414: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014418: addiu       $s0, $zero, 0x80
    ctx->r16 = ADD32(0, 0X80);
    // 0x8001441C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80014420: b           L_80015C10
    // 0x80014424: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014424: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014428:
    // 0x80014428: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8001442C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014430: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014434: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014438: b           L_80015C10
    // 0x8001443C: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_80015C10;
    // 0x8001443C: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_80014440:
    // 0x80014440: beql        $s1, $zero, L_80014474
    if (ctx->r17 == 0) {
        // 0x80014444: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_80014474;
    }
    goto skip_25;
    // 0x80014444: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    skip_25:
    // 0x80014448: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x8001444C: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x80014450: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80014454: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80014458: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001445C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80014460: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x80014464: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80014468: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x8001446C: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80014470: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
L_80014474:
    // 0x80014474: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014478: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001447C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014480: b           L_80015C10
    // 0x80014484: addiu       $s0, $zero, 0x81
    ctx->r16 = ADD32(0, 0X81);
        goto L_80015C10;
    // 0x80014484: addiu       $s0, $zero, 0x81
    ctx->r16 = ADD32(0, 0X81);
L_80014488:
    // 0x80014488: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001448C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80014490: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014494: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014498: addiu       $s0, $zero, 0x41
    ctx->r16 = ADD32(0, 0X41);
    // 0x8001449C: b           L_80015C10
    // 0x800144A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800144A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800144A4:
    // 0x800144A4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800144A8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800144AC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800144B0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800144B4: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
    // 0x800144B8: b           L_80015C10
    // 0x800144BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800144BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800144C0:
    // 0x800144C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800144C4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800144C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800144CC: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x800144D0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800144D4: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800144D8: addiu       $s0, $zero, 0x265
    ctx->r16 = ADD32(0, 0X265);
    // 0x800144DC: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    // 0x800144E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800144E4: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x800144E8: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800144EC: jal         0x80011D1C
    // 0x800144F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011D1C(rdram, ctx);
        goto after_17;
    // 0x800144F0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_17:
    // 0x800144F4: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x800144F8: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800144FC: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80014500: b           L_80015C10
    // 0x80014504: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
        goto L_80015C10;
    // 0x80014504: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80014508:
    // 0x80014508: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001450C: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80014510: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014514: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014518: addiu       $s0, $zero, 0x46
    ctx->r16 = ADD32(0, 0X46);
    // 0x8001451C: b           L_80015C10
    // 0x80014520: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014520: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014524:
    // 0x80014524: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80014528: addiu       $v1, $v1, -0x6D74
    ctx->r3 = ADD32(ctx->r3, -0X6D74);
    // 0x8001452C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80014530: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80014534: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80014538: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001453C: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x80014540: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80014544: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80014548: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001454C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014550: addiu       $s0, $zero, 0x8F
    ctx->r16 = ADD32(0, 0X8F);
    // 0x80014554: bne         $t7, $at, L_800145AC
    if (ctx->r15 != ctx->r1) {
        // 0x80014558: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800145AC;
    }
    // 0x80014558: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001455C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80014560: lw          $v0, -0x6D70($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6D70);
    // 0x80014564: beql        $v0, $zero, L_800145AC
    if (ctx->r2 == 0) {
        // 0x80014568: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_800145AC;
    }
    goto skip_26;
    // 0x80014568: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_26:
    // 0x8001456C: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80014570: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80014574: bne         $t8, $at, L_800145A8
    if (ctx->r24 != ctx->r1) {
        // 0x80014578: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800145A8;
    }
    // 0x80014578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001457C: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80014580: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80014584: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80014588: jal         0x8001137C
    // 0x8001458C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_8001137C(rdram, ctx);
        goto after_18;
    // 0x8001458C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_18:
    // 0x80014590: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80014594: addiu       $v1, $v1, -0x6D74
    ctx->r3 = ADD32(ctx->r3, -0X6D74);
    // 0x80014598: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x8001459C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800145A0: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800145A4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_800145A8:
    // 0x800145A8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_800145AC:
    // 0x800145AC: b           L_80015C14
    // 0x800145B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
        goto L_80015C14;
    // 0x800145B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_800145B4:
    // 0x800145B4: beql        $s1, $zero, L_800145F4
    if (ctx->r17 == 0) {
        // 0x800145B8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800145F4;
    }
    goto skip_27;
    // 0x800145B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_27:
    // 0x800145BC: lw          $v1, 0x14($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X14);
    // 0x800145C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800145C4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800145C8: bne         $at, $zero, L_800145EC
    if (ctx->r1 != 0) {
        // 0x800145CC: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_800145EC;
    }
    // 0x800145CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800145D0: ldc1        $f2, -0x1CD0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X1CD0);
L_800145D4:
    // 0x800145D4: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x800145D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800145DC: mul.d       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f2.d);
    // 0x800145E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800145E4: bne         $at, $zero, L_800145D4
    if (ctx->r1 != 0) {
        // 0x800145E8: cvt.s.d     $f12, $f8
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
            goto L_800145D4;
    }
    // 0x800145E8: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_800145EC:
    // 0x800145EC: addiu       $s0, $zero, 0x90
    ctx->r16 = ADD32(0, 0X90);
    // 0x800145F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800145F4:
    // 0x800145F4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800145F8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800145FC: b           L_80015C10
    // 0x80014600: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
        goto L_80015C10;
    // 0x80014600: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
L_80014604:
    // 0x80014604: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014608: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8001460C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014610: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014614: addiu       $s0, $zero, 0x148
    ctx->r16 = ADD32(0, 0X148);
    // 0x80014618: b           L_80015C10
    // 0x8001461C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001461C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014620:
    // 0x80014620: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014624: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80014628: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001462C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014630: addiu       $s0, $zero, 0xA4
    ctx->r16 = ADD32(0, 0XA4);
    // 0x80014634: b           L_80015C10
    // 0x80014638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001463C:
    // 0x8001463C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80014640: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80014644: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014648: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001464C: b           L_80015C10
    // 0x80014650: addiu       $s0, $zero, 0xA6
    ctx->r16 = ADD32(0, 0XA6);
        goto L_80015C10;
    // 0x80014650: addiu       $s0, $zero, 0xA6
    ctx->r16 = ADD32(0, 0XA6);
L_80014654:
    // 0x80014654: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014658: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001465C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014660: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014664: b           L_80015C10
    // 0x80014668: addiu       $s0, $zero, 0xA7
    ctx->r16 = ADD32(0, 0XA7);
        goto L_80015C10;
    // 0x80014668: addiu       $s0, $zero, 0xA7
    ctx->r16 = ADD32(0, 0XA7);
L_8001466C:
    // 0x8001466C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014670: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014674: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014678: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001467C: b           L_80015C10
    // 0x80014680: addiu       $s0, $zero, 0xA8
    ctx->r16 = ADD32(0, 0XA8);
        goto L_80015C10;
    // 0x80014680: addiu       $s0, $zero, 0xA8
    ctx->r16 = ADD32(0, 0XA8);
L_80014684:
    // 0x80014684: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014688: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001468C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014690: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014694: b           L_80015C10
    // 0x80014698: addiu       $s0, $zero, 0xA9
    ctx->r16 = ADD32(0, 0XA9);
        goto L_80015C10;
    // 0x80014698: addiu       $s0, $zero, 0xA9
    ctx->r16 = ADD32(0, 0XA9);
L_8001469C:
    // 0x8001469C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800146A0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800146A4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800146A8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800146AC: b           L_80015C10
    // 0x800146B0: addiu       $s0, $zero, 0xAA
    ctx->r16 = ADD32(0, 0XAA);
        goto L_80015C10;
    // 0x800146B0: addiu       $s0, $zero, 0xAA
    ctx->r16 = ADD32(0, 0XAA);
L_800146B4:
    // 0x800146B4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800146B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800146BC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800146C0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800146C4: b           L_80015C10
    // 0x800146C8: addiu       $s0, $zero, 0xAB
    ctx->r16 = ADD32(0, 0XAB);
        goto L_80015C10;
    // 0x800146C8: addiu       $s0, $zero, 0xAB
    ctx->r16 = ADD32(0, 0XAB);
L_800146CC:
    // 0x800146CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800146D0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800146D4: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800146D8: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800146DC: b           L_80015C10
    // 0x800146E0: addiu       $s0, $zero, 0xAC
    ctx->r16 = ADD32(0, 0XAC);
        goto L_80015C10;
    // 0x800146E0: addiu       $s0, $zero, 0xAC
    ctx->r16 = ADD32(0, 0XAC);
L_800146E4:
    // 0x800146E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800146E8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800146EC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800146F0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800146F4: b           L_80015C10
    // 0x800146F8: addiu       $s0, $zero, 0xAD
    ctx->r16 = ADD32(0, 0XAD);
        goto L_80015C10;
    // 0x800146F8: addiu       $s0, $zero, 0xAD
    ctx->r16 = ADD32(0, 0XAD);
L_800146FC:
    // 0x800146FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80014700: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80014704: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014708: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8001470C: b           L_80015C10
    // 0x80014710: addiu       $s0, $zero, 0x96
    ctx->r16 = ADD32(0, 0X96);
        goto L_80015C10;
    // 0x80014710: addiu       $s0, $zero, 0x96
    ctx->r16 = ADD32(0, 0X96);
L_80014714:
    // 0x80014714: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014718: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001471C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014720: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014724: addiu       $s0, $zero, 0xB0
    ctx->r16 = ADD32(0, 0XB0);
    // 0x80014728: b           L_80015C10
    // 0x8001472C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001472C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014730:
    // 0x80014730: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80014734: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80014738: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001473C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014740: addiu       $s0, $zero, 0xB2
    ctx->r16 = ADD32(0, 0XB2);
    // 0x80014744: b           L_80015C10
    // 0x80014748: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014748: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001474C:
    // 0x8001474C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80014750: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80014754: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014758: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x8001475C: b           L_80015C10
    // 0x80014760: addiu       $s0, $zero, 0xB8
    ctx->r16 = ADD32(0, 0XB8);
        goto L_80015C10;
    // 0x80014760: addiu       $s0, $zero, 0xB8
    ctx->r16 = ADD32(0, 0XB8);
L_80014764:
    // 0x80014764: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014768: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8001476C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014770: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014774: b           L_80015C10
    // 0x80014778: addiu       $s0, $zero, 0xB9
    ctx->r16 = ADD32(0, 0XB9);
        goto L_80015C10;
    // 0x80014778: addiu       $s0, $zero, 0xB9
    ctx->r16 = ADD32(0, 0XB9);
L_8001477C:
    // 0x8001477C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014780: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80014784: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014788: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x8001478C: addiu       $s0, $zero, 0x57
    ctx->r16 = ADD32(0, 0X57);
    // 0x80014790: b           L_80015C10
    // 0x80014794: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014794: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014798:
    // 0x80014798: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8001479C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800147A0: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800147A4: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800147A8: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
    // 0x800147AC: b           L_80015C10
    // 0x800147B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800147B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800147B4:
    // 0x800147B4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800147B8: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800147BC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800147C0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800147C4: addiu       $s0, $zero, 0xC2
    ctx->r16 = ADD32(0, 0XC2);
    // 0x800147C8: b           L_80015C10
    // 0x800147CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800147CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800147D0:
    // 0x800147D0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800147D4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800147D8: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800147DC: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800147E0: addiu       $s0, $zero, 0xC3
    ctx->r16 = ADD32(0, 0XC3);
    // 0x800147E4: b           L_80015C10
    // 0x800147E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800147E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800147EC:
    // 0x800147EC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x800147F0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800147F4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800147F8: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800147FC: b           L_80015C10
    // 0x80014800: addiu       $s0, $zero, 0xC4
    ctx->r16 = ADD32(0, 0XC4);
        goto L_80015C10;
    // 0x80014800: addiu       $s0, $zero, 0xC4
    ctx->r16 = ADD32(0, 0XC4);
L_80014804:
    // 0x80014804: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80014808: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x8001480C: addiu       $s0, $zero, 0xC9
    ctx->r16 = ADD32(0, 0XC9);
    // 0x80014810: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80014814: b           L_80015C10
    // 0x80014818: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014818: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001481C:
    // 0x8001481C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80014820: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014824: addiu       $s0, $zero, 0xCA
    ctx->r16 = ADD32(0, 0XCA);
    // 0x80014828: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8001482C: b           L_80015C10
    // 0x80014830: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014830: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014834:
    // 0x80014834: beql        $s1, $zero, L_80014894
    if (ctx->r17 == 0) {
        // 0x80014838: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80014894;
    }
    goto skip_28;
    // 0x80014838: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    skip_28:
    // 0x8001483C: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x80014840: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80014844: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80014848: beq         $at, $zero, L_80014890
    if (ctx->r1 == 0) {
        // 0x8001484C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80014890;
    }
    // 0x8001484C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80014850: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014854: addu        $at, $at, $t5
    gpr jr_addend_8001485C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80014858: lw          $t5, -0x1C08($at)
    ctx->r13 = ADD32(ctx->r1, -0X1C08);
    // 0x8001485C: jr          $t5
    // 0x80014860: nop

    switch (jr_addend_8001485C >> 2) {
        case 0: goto L_80014864; break;
        case 1: goto L_8001486C; break;
        case 2: goto L_80014874; break;
        case 3: goto L_8001487C; break;
        case 4: goto L_80014884; break;
        case 5: goto L_8001488C; break;
        default: switch_error(__func__, 0x8001485C, 0x800AE3F8);
    }
    // 0x80014860: nop

L_80014864:
    // 0x80014864: b           L_80014890
    // 0x80014868: addiu       $s0, $zero, 0xCB
    ctx->r16 = ADD32(0, 0XCB);
        goto L_80014890;
    // 0x80014868: addiu       $s0, $zero, 0xCB
    ctx->r16 = ADD32(0, 0XCB);
L_8001486C:
    // 0x8001486C: b           L_80014890
    // 0x80014870: addiu       $s0, $zero, 0xCC
    ctx->r16 = ADD32(0, 0XCC);
        goto L_80014890;
    // 0x80014870: addiu       $s0, $zero, 0xCC
    ctx->r16 = ADD32(0, 0XCC);
L_80014874:
    // 0x80014874: b           L_80014890
    // 0x80014878: addiu       $s0, $zero, 0xCD
    ctx->r16 = ADD32(0, 0XCD);
        goto L_80014890;
    // 0x80014878: addiu       $s0, $zero, 0xCD
    ctx->r16 = ADD32(0, 0XCD);
L_8001487C:
    // 0x8001487C: b           L_80014890
    // 0x80014880: addiu       $s0, $zero, 0xCE
    ctx->r16 = ADD32(0, 0XCE);
        goto L_80014890;
    // 0x80014880: addiu       $s0, $zero, 0xCE
    ctx->r16 = ADD32(0, 0XCE);
L_80014884:
    // 0x80014884: b           L_80014890
    // 0x80014888: addiu       $s0, $zero, 0xCF
    ctx->r16 = ADD32(0, 0XCF);
        goto L_80014890;
    // 0x80014888: addiu       $s0, $zero, 0xCF
    ctx->r16 = ADD32(0, 0XCF);
L_8001488C:
    // 0x8001488C: addiu       $s0, $zero, 0xD0
    ctx->r16 = ADD32(0, 0XD0);
L_80014890:
    // 0x80014890: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
L_80014894:
    // 0x80014894: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014898: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8001489C: b           L_80015C10
    // 0x800148A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800148A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800148A4:
    // 0x800148A4: beql        $s1, $zero, L_80014904
    if (ctx->r17 == 0) {
        // 0x800148A8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80014904;
    }
    goto skip_29;
    // 0x800148A8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    skip_29:
    // 0x800148AC: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x800148B0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800148B4: sltiu       $at, $t8, 0x6
    ctx->r1 = ctx->r24 < 0X6 ? 1 : 0;
    // 0x800148B8: beq         $at, $zero, L_80014900
    if (ctx->r1 == 0) {
        // 0x800148BC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80014900;
    }
    // 0x800148BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800148C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800148C4: addu        $at, $at, $t8
    gpr jr_addend_800148CC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800148C8: lw          $t8, -0x1BE8($at)
    ctx->r24 = ADD32(ctx->r1, -0X1BE8);
    // 0x800148CC: jr          $t8
    // 0x800148D0: nop

    switch (jr_addend_800148CC >> 2) {
        case 0: goto L_800148D4; break;
        case 1: goto L_800148DC; break;
        case 2: goto L_800148E4; break;
        case 3: goto L_800148EC; break;
        case 4: goto L_800148F4; break;
        case 5: goto L_800148FC; break;
        default: switch_error(__func__, 0x800148CC, 0x800AE418);
    }
    // 0x800148D0: nop

L_800148D4:
    // 0x800148D4: b           L_80014900
    // 0x800148D8: addiu       $s0, $zero, 0xD1
    ctx->r16 = ADD32(0, 0XD1);
        goto L_80014900;
    // 0x800148D8: addiu       $s0, $zero, 0xD1
    ctx->r16 = ADD32(0, 0XD1);
L_800148DC:
    // 0x800148DC: b           L_80014900
    // 0x800148E0: addiu       $s0, $zero, 0xD2
    ctx->r16 = ADD32(0, 0XD2);
        goto L_80014900;
    // 0x800148E0: addiu       $s0, $zero, 0xD2
    ctx->r16 = ADD32(0, 0XD2);
L_800148E4:
    // 0x800148E4: b           L_80014900
    // 0x800148E8: addiu       $s0, $zero, 0xD3
    ctx->r16 = ADD32(0, 0XD3);
        goto L_80014900;
    // 0x800148E8: addiu       $s0, $zero, 0xD3
    ctx->r16 = ADD32(0, 0XD3);
L_800148EC:
    // 0x800148EC: b           L_80014900
    // 0x800148F0: addiu       $s0, $zero, 0xD4
    ctx->r16 = ADD32(0, 0XD4);
        goto L_80014900;
    // 0x800148F0: addiu       $s0, $zero, 0xD4
    ctx->r16 = ADD32(0, 0XD4);
L_800148F4:
    // 0x800148F4: b           L_80014900
    // 0x800148F8: addiu       $s0, $zero, 0xD5
    ctx->r16 = ADD32(0, 0XD5);
        goto L_80014900;
    // 0x800148F8: addiu       $s0, $zero, 0xD5
    ctx->r16 = ADD32(0, 0XD5);
L_800148FC:
    // 0x800148FC: addiu       $s0, $zero, 0xD6
    ctx->r16 = ADD32(0, 0XD6);
L_80014900:
    // 0x80014900: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
L_80014904:
    // 0x80014904: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014908: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8001490C: b           L_80015C10
    // 0x80014910: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014910: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014914:
    // 0x80014914: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014918: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001491C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014920: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014924: addiu       $s0, $zero, 0x1A3
    ctx->r16 = ADD32(0, 0X1A3);
    // 0x80014928: b           L_80015C10
    // 0x8001492C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001492C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014930:
    // 0x80014930: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014934: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014938: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001493C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014940: addiu       $s0, $zero, 0x1A4
    ctx->r16 = ADD32(0, 0X1A4);
    // 0x80014944: b           L_80015C10
    // 0x80014948: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014948: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001494C:
    // 0x8001494C: beql        $s1, $zero, L_8001497C
    if (ctx->r17 == 0) {
        // 0x80014950: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8001497C;
    }
    goto skip_30;
    // 0x80014950: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    skip_30:
    // 0x80014954: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x80014958: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001495C: ldc1        $f16, -0x1BB8($at)
    CHECK_FR(ctx, 16);
    ctx->f16.u64 = LD(ctx->r1, -0X1BB8);
    // 0x80014960: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80014964: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80014968: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x8001496C: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80014970: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x80014974: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80014978: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8001497C:
    // 0x8001497C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80014980: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014984: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014988: b           L_80015C10
    // 0x8001498C: addiu       $s0, $zero, 0x238
    ctx->r16 = ADD32(0, 0X238);
        goto L_80015C10;
    // 0x8001498C: addiu       $s0, $zero, 0x238
    ctx->r16 = ADD32(0, 0X238);
L_80014990:
    // 0x80014990: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80014994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014998: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x8001499C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x800149A0: jal         0x80011928
    // 0x800149A4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_19;
    // 0x800149A4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_19:
    // 0x800149A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800149AC: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x800149B0: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x800149B4: bne         $v0, $at, L_800149DC
    if (ctx->r2 != ctx->r1) {
        // 0x800149B8: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_800149DC;
    }
    // 0x800149B8: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800149BC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800149C0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800149C4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800149C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800149CC: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800149D0: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800149D4: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x800149D8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_800149DC:
    // 0x800149DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800149E0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800149E4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800149E8: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800149EC: addiu       $s0, $zero, 0xE5
    ctx->r16 = ADD32(0, 0XE5);
    // 0x800149F0: b           L_80015C10
    // 0x800149F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800149F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800149F8:
    // 0x800149F8: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x800149FC: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80014A00: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014A04: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014A08: b           L_80015C10
    // 0x80014A0C: addiu       $s0, $zero, 0xE6
    ctx->r16 = ADD32(0, 0XE6);
        goto L_80015C10;
    // 0x80014A0C: addiu       $s0, $zero, 0xE6
    ctx->r16 = ADD32(0, 0XE6);
L_80014A10:
    // 0x80014A10: beql        $s1, $zero, L_80014A58
    if (ctx->r17 == 0) {
        // 0x80014A14: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80014A58;
    }
    goto skip_31;
    // 0x80014A14: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_31:
    // 0x80014A18: lw          $t7, 0x14($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X14);
    // 0x80014A1C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80014A20: sltiu       $at, $t8, 0xD
    ctx->r1 = ctx->r24 < 0XD ? 1 : 0;
    // 0x80014A24: beq         $at, $zero, L_80014A54
    if (ctx->r1 == 0) {
        // 0x80014A28: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80014A54;
    }
    // 0x80014A28: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80014A2C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014A30: addu        $at, $at, $t8
    gpr jr_addend_80014A38 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80014A34: lw          $t8, -0x1B98($at)
    ctx->r24 = ADD32(ctx->r1, -0X1B98);
    // 0x80014A38: jr          $t8
    // 0x80014A3C: nop

    switch (jr_addend_80014A38 >> 2) {
        case 0: goto L_80014A40; break;
        case 1: goto L_80014A48; break;
        case 2: goto L_80014A40; break;
        case 3: goto L_80014A40; break;
        case 4: goto L_80014A48; break;
        case 5: goto L_80014A40; break;
        case 6: goto L_80014A40; break;
        case 7: goto L_80014A48; break;
        case 8: goto L_80014A40; break;
        case 9: goto L_80014A48; break;
        case 10: goto L_80014A40; break;
        case 11: goto L_80014A48; break;
        case 12: goto L_80014A50; break;
        default: switch_error(__func__, 0x80014A38, 0x800AE468);
    }
    // 0x80014A3C: nop

L_80014A40:
    // 0x80014A40: b           L_80014A54
    // 0x80014A44: addiu       $s0, $zero, 0x247
    ctx->r16 = ADD32(0, 0X247);
        goto L_80014A54;
    // 0x80014A44: addiu       $s0, $zero, 0x247
    ctx->r16 = ADD32(0, 0X247);
L_80014A48:
    // 0x80014A48: b           L_80014A54
    // 0x80014A4C: addiu       $s0, $zero, 0x248
    ctx->r16 = ADD32(0, 0X248);
        goto L_80014A54;
    // 0x80014A4C: addiu       $s0, $zero, 0x248
    ctx->r16 = ADD32(0, 0X248);
L_80014A50:
    // 0x80014A50: addiu       $s0, $zero, 0xE8
    ctx->r16 = ADD32(0, 0XE8);
L_80014A54:
    // 0x80014A54: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80014A58:
    // 0x80014A58: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x80014A5C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014A60: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014A64: b           L_80015C10
    // 0x80014A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014A68: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014A6C:
    // 0x80014A6C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014A70: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014A74: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014A78: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014A7C: addiu       $s0, $zero, 0x161
    ctx->r16 = ADD32(0, 0X161);
    // 0x80014A80: b           L_80015C10
    // 0x80014A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014A84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014A88:
    // 0x80014A88: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014A8C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80014A90: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014A94: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014A98: addiu       $s0, $zero, 0xEA
    ctx->r16 = ADD32(0, 0XEA);
    // 0x80014A9C: b           L_80015C10
    // 0x80014AA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014AA0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014AA4:
    // 0x80014AA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80014AA8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80014AAC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014AB0: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014AB4: addiu       $s0, $zero, 0xEB
    ctx->r16 = ADD32(0, 0XEB);
    // 0x80014AB8: b           L_80015C10
    // 0x80014ABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014ABC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014AC0:
    // 0x80014AC0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014AC4: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80014AC8: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014ACC: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014AD0: addiu       $s0, $zero, 0xF5
    ctx->r16 = ADD32(0, 0XF5);
    // 0x80014AD4: b           L_80015C10
    // 0x80014AD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014AD8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014ADC:
    // 0x80014ADC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014AE0: ldc1        $f10, -0x1B38($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X1B38);
    // 0x80014AE4: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80014AE8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014AEC: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80014AF0: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80014AF4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014AF8: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014AFC: addiu       $s0, $zero, 0x3F
    ctx->r16 = ADD32(0, 0X3F);
    // 0x80014B00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80014B04: b           L_80015C10
    // 0x80014B08: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
        goto L_80015C10;
    // 0x80014B08: cvt.s.d     $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f12.fl = CVT_S_D(ctx->f18.d);
L_80014B0C:
    // 0x80014B0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014B10: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014B14: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014B18: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014B1C: b           L_80015C10
    // 0x80014B20: addiu       $s0, $zero, 0xFC
    ctx->r16 = ADD32(0, 0XFC);
        goto L_80015C10;
    // 0x80014B20: addiu       $s0, $zero, 0xFC
    ctx->r16 = ADD32(0, 0XFC);
L_80014B24:
    // 0x80014B24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014B28: ldc1        $f6, -0x1B20($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1B20);
    // 0x80014B2C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80014B30: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80014B34: mul.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80014B38: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80014B3C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014B40: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014B44: addiu       $s0, $zero, 0xFE
    ctx->r16 = ADD32(0, 0XFE);
    // 0x80014B48: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80014B4C: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80014B50: b           L_80015C10
    // 0x80014B54: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
        goto L_80015C10;
    // 0x80014B54: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80014B58:
    // 0x80014B58: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014B5C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014B60: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014B64: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014B68: addiu       $s0, $zero, 0x160
    ctx->r16 = ADD32(0, 0X160);
    // 0x80014B6C: b           L_80015C10
    // 0x80014B70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014B70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014B74:
    // 0x80014B74: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80014B78: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80014B7C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014B80: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014B84: b           L_80015C10
    // 0x80014B88: addiu       $s0, $zero, 0x107
    ctx->r16 = ADD32(0, 0X107);
        goto L_80015C10;
    // 0x80014B88: addiu       $s0, $zero, 0x107
    ctx->r16 = ADD32(0, 0X107);
L_80014B8C:
    // 0x80014B8C: addiu       $t8, $zero, 0x15
    ctx->r24 = ADD32(0, 0X15);
    // 0x80014B90: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80014B94: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014B98: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014B9C: b           L_80015C10
    // 0x80014BA0: addiu       $s0, $zero, 0x108
    ctx->r16 = ADD32(0, 0X108);
        goto L_80015C10;
    // 0x80014BA0: addiu       $s0, $zero, 0x108
    ctx->r16 = ADD32(0, 0X108);
L_80014BA4:
    // 0x80014BA4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80014BA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014BAC: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80014BB0: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80014BB4: jal         0x80011928
    // 0x80014BB8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_20;
    // 0x80014BB8: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_20:
    // 0x80014BBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014BC0: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80014BC4: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80014BC8: bne         $v0, $at, L_80014BF0
    if (ctx->r2 != ctx->r1) {
        // 0x80014BCC: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80014BF0;
    }
    // 0x80014BCC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80014BD0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80014BD4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014BD8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80014BDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80014BE0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80014BE4: mul.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x80014BE8: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80014BEC: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
L_80014BF0:
    // 0x80014BF0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014BF4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80014BF8: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014BFC: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014C00: addiu       $s0, $zero, 0x109
    ctx->r16 = ADD32(0, 0X109);
    // 0x80014C04: b           L_80015C10
    // 0x80014C08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014C08: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014C0C:
    // 0x80014C0C: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    // 0x80014C10: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014C14: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014C18: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014C1C: addiu       $s0, $zero, 0x11F
    ctx->r16 = ADD32(0, 0X11F);
    // 0x80014C20: b           L_80015C10
    // 0x80014C24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014C24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014C28:
    // 0x80014C28: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014C2C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80014C30: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014C34: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014C38: addiu       $s0, $zero, 0x120
    ctx->r16 = ADD32(0, 0X120);
    // 0x80014C3C: b           L_80015C10
    // 0x80014C40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014C40: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014C44:
    // 0x80014C44: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80014C48: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014C4C: addiu       $s0, $zero, 0x123
    ctx->r16 = ADD32(0, 0X123);
    // 0x80014C50: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80014C54: b           L_80015C10
    // 0x80014C58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014C58: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014C5C:
    // 0x80014C5C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80014C60: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80014C64: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014C68: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014C6C: b           L_80015C10
    // 0x80014C70: addiu       $s0, $zero, 0x125
    ctx->r16 = ADD32(0, 0X125);
        goto L_80015C10;
    // 0x80014C70: addiu       $s0, $zero, 0x125
    ctx->r16 = ADD32(0, 0X125);
L_80014C74:
    // 0x80014C74: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80014C78: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80014C7C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014C80: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014C84: b           L_80015C10
    // 0x80014C88: addiu       $s0, $zero, 0x127
    ctx->r16 = ADD32(0, 0X127);
        goto L_80015C10;
    // 0x80014C88: addiu       $s0, $zero, 0x127
    ctx->r16 = ADD32(0, 0X127);
L_80014C8C:
    // 0x80014C8C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80014C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014C94: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80014C98: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80014C9C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80014CA0: jal         0x80011928
    // 0x80014CA4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_21;
    // 0x80014CA4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_21:
    // 0x80014CA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014CAC: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80014CB0: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80014CB4: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80014CB8: bne         $v0, $at, L_80014CE0
    if (ctx->r2 != ctx->r1) {
        // 0x80014CBC: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80014CE0;
    }
    // 0x80014CBC: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80014CC0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80014CC4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014CC8: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80014CCC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80014CD0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80014CD4: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80014CD8: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x80014CDC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_80014CE0:
    // 0x80014CE0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80014CE4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014CE8: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014CEC: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014CF0: b           L_80015C10
    // 0x80014CF4: addiu       $s0, $zero, 0xE4
    ctx->r16 = ADD32(0, 0XE4);
        goto L_80015C10;
    // 0x80014CF4: addiu       $s0, $zero, 0xE4
    ctx->r16 = ADD32(0, 0XE4);
L_80014CF8:
    // 0x80014CF8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80014CFC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80014D00: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014D04: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014D08: addiu       $s0, $zero, 0x129
    ctx->r16 = ADD32(0, 0X129);
    // 0x80014D0C: b           L_80015C10
    // 0x80014D10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014D10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014D14:
    // 0x80014D14: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80014D18: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014D1C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014D20: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014D24: addiu       $s0, $zero, 0x12A
    ctx->r16 = ADD32(0, 0X12A);
    // 0x80014D28: b           L_80015C10
    // 0x80014D2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014D2C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014D30:
    // 0x80014D30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014D34: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80014D38: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014D3C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014D40: addiu       $s0, $zero, 0x12C
    ctx->r16 = ADD32(0, 0X12C);
    // 0x80014D44: b           L_80015C10
    // 0x80014D48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014D48: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014D4C:
    // 0x80014D4C: beql        $s1, $zero, L_80014D90
    if (ctx->r17 == 0) {
        // 0x80014D50: addiu       $t9, $zero, 0x18
        ctx->r25 = ADD32(0, 0X18);
            goto L_80014D90;
    }
    goto skip_32;
    // 0x80014D50: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    skip_32:
    // 0x80014D54: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x80014D58: sltiu       $at, $t8, 0x11
    ctx->r1 = ctx->r24 < 0X11 ? 1 : 0;
    // 0x80014D5C: beq         $at, $zero, L_80014D8C
    if (ctx->r1 == 0) {
        // 0x80014D60: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80014D8C;
    }
    // 0x80014D60: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80014D64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014D68: addu        $at, $at, $t8
    gpr jr_addend_80014D70 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80014D6C: lw          $t8, -0x1AA8($at)
    ctx->r24 = ADD32(ctx->r1, -0X1AA8);
    // 0x80014D70: jr          $t8
    // 0x80014D74: nop

    switch (jr_addend_80014D70 >> 2) {
        case 0: goto L_80014D78; break;
        case 1: goto L_80014D80; break;
        case 2: goto L_80014D78; break;
        case 3: goto L_80014D78; break;
        case 4: goto L_80014D78; break;
        case 5: goto L_80014D80; break;
        case 6: goto L_80014D80; break;
        case 7: goto L_80014D78; break;
        case 8: goto L_80014D78; break;
        case 9: goto L_80014D78; break;
        case 10: goto L_80014D78; break;
        case 11: goto L_80014D78; break;
        case 12: goto L_80014D78; break;
        case 13: goto L_80014D78; break;
        case 14: goto L_80014D88; break;
        case 15: goto L_80014D88; break;
        case 16: goto L_80014D80; break;
        default: switch_error(__func__, 0x80014D70, 0x800AE558);
    }
    // 0x80014D74: nop

L_80014D78:
    // 0x80014D78: b           L_80014D8C
    // 0x80014D7C: addiu       $s0, $zero, 0x142
    ctx->r16 = ADD32(0, 0X142);
        goto L_80014D8C;
    // 0x80014D7C: addiu       $s0, $zero, 0x142
    ctx->r16 = ADD32(0, 0X142);
L_80014D80:
    // 0x80014D80: b           L_80014D8C
    // 0x80014D84: addiu       $s0, $zero, 0x95
    ctx->r16 = ADD32(0, 0X95);
        goto L_80014D8C;
    // 0x80014D84: addiu       $s0, $zero, 0x95
    ctx->r16 = ADD32(0, 0X95);
L_80014D88:
    // 0x80014D88: addiu       $s0, $zero, 0x143
    ctx->r16 = ADD32(0, 0X143);
L_80014D8C:
    // 0x80014D8C: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
L_80014D90:
    // 0x80014D90: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80014D94: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014D98: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014D9C: b           L_80015C10
    // 0x80014DA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014DA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014DA4:
    // 0x80014DA4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014DA8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80014DAC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014DB0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014DB4: addiu       $s0, $zero, 0x142
    ctx->r16 = ADD32(0, 0X142);
    // 0x80014DB8: b           L_80015C10
    // 0x80014DBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014DBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014DC0:
    // 0x80014DC0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014DC4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80014DC8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014DCC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014DD0: addiu       $s0, $zero, 0x95
    ctx->r16 = ADD32(0, 0X95);
    // 0x80014DD4: b           L_80015C10
    // 0x80014DD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014DD8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014DDC:
    // 0x80014DDC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80014DE0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80014DE4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014DE8: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014DEC: addiu       $s0, $zero, 0x143
    ctx->r16 = ADD32(0, 0X143);
    // 0x80014DF0: b           L_80015C10
    // 0x80014DF4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014DF4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014DF8:
    // 0x80014DF8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014DFC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80014E00: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014E04: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014E08: b           L_80015C10
    // 0x80014E0C: addiu       $s0, $zero, 0x157
    ctx->r16 = ADD32(0, 0X157);
        goto L_80015C10;
    // 0x80014E0C: addiu       $s0, $zero, 0x157
    ctx->r16 = ADD32(0, 0X157);
L_80014E10:
    // 0x80014E10: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014E14: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80014E18: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014E1C: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014E20: addiu       $s0, $zero, 0x17E
    ctx->r16 = ADD32(0, 0X17E);
    // 0x80014E24: b           L_80015C10
    // 0x80014E28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014E28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014E2C:
    // 0x80014E2C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014E30: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014E34: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014E38: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014E3C: addiu       $s0, $zero, 0x12B
    ctx->r16 = ADD32(0, 0X12B);
    // 0x80014E40: b           L_80015C10
    // 0x80014E44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014E44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014E48:
    // 0x80014E48: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80014E4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80014E50: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80014E54: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80014E58: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80014E5C: jal         0x80011928
    // 0x80014E60: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_22;
    // 0x80014E60: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_22:
    // 0x80014E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80014E68: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80014E6C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80014E70: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80014E74: bne         $v0, $at, L_80014E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80014E78: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80014E9C;
    }
    // 0x80014E78: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80014E7C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80014E80: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80014E84: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80014E88: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80014E8C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80014E90: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80014E94: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80014E98: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_80014E9C:
    // 0x80014E9C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80014EA0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80014EA4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014EA8: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014EAC: b           L_80015C10
    // 0x80014EB0: addiu       $s0, $zero, 0x15E
    ctx->r16 = ADD32(0, 0X15E);
        goto L_80015C10;
    // 0x80014EB0: addiu       $s0, $zero, 0x15E
    ctx->r16 = ADD32(0, 0X15E);
L_80014EB4:
    // 0x80014EB4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80014EB8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80014EBC: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80014EC0: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80014EC4: addiu       $s0, $zero, 0x15F
    ctx->r16 = ADD32(0, 0X15F);
    // 0x80014EC8: b           L_80015C10
    // 0x80014ECC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014ECC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014ED0:
    // 0x80014ED0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80014ED4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80014ED8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014EDC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014EE0: addiu       $s0, $zero, 0x15C
    ctx->r16 = ADD32(0, 0X15C);
    // 0x80014EE4: b           L_80015C10
    // 0x80014EE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014EE8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014EEC:
    // 0x80014EEC: addiu       $t8, $zero, 0x12
    ctx->r24 = ADD32(0, 0X12);
    // 0x80014EF0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80014EF4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80014EF8: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80014EFC: addiu       $s0, $zero, 0x15D
    ctx->r16 = ADD32(0, 0X15D);
    // 0x80014F00: b           L_80015C10
    // 0x80014F04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014F04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014F08:
    // 0x80014F08: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80014F0C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80014F10: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80014F14: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80014F18: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x80014F1C: b           L_80015C10
    // 0x80014F20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014F20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014F24:
    // 0x80014F24: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80014F28: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80014F2C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80014F30: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80014F34: addiu       $s0, $zero, 0x161
    ctx->r16 = ADD32(0, 0X161);
    // 0x80014F38: b           L_80015C10
    // 0x80014F3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014F3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014F40:
    // 0x80014F40: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80014F44: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80014F48: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80014F4C: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80014F50: addiu       $s0, $zero, 0x162
    ctx->r16 = ADD32(0, 0X162);
    // 0x80014F54: b           L_80015C10
    // 0x80014F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014F58: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80014F5C:
    // 0x80014F5C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80014F60: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80014F64: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80014F68: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80014F6C: addiu       $s0, $zero, 0x1AB
    ctx->r16 = ADD32(0, 0X1AB);
    // 0x80014F70: b           L_80015C10
    // 0x80014F74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014F74: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014F78:
    // 0x80014F78: beql        $s1, $zero, L_80014FE8
    if (ctx->r17 == 0) {
        // 0x80014F7C: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_80014FE8;
    }
    goto skip_33;
    // 0x80014F7C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    skip_33:
    // 0x80014F80: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x80014F84: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80014F88: sltiu       $at, $t5, 0x8
    ctx->r1 = ctx->r13 < 0X8 ? 1 : 0;
    // 0x80014F8C: beq         $at, $zero, L_80014FE4
    if (ctx->r1 == 0) {
        // 0x80014F90: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80014FE4;
    }
    // 0x80014F90: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80014F94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80014F98: addu        $at, $at, $t5
    gpr jr_addend_80014FA0 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80014F9C: lw          $t5, -0x19E8($at)
    ctx->r13 = ADD32(ctx->r1, -0X19E8);
    // 0x80014FA0: jr          $t5
    // 0x80014FA4: nop

    switch (jr_addend_80014FA0 >> 2) {
        case 0: goto L_80014FA8; break;
        case 1: goto L_80014FB0; break;
        case 2: goto L_80014FB8; break;
        case 3: goto L_80014FC0; break;
        case 4: goto L_80014FC8; break;
        case 5: goto L_80014FD0; break;
        case 6: goto L_80014FD8; break;
        case 7: goto L_80014FE0; break;
        default: switch_error(__func__, 0x80014FA0, 0x800AE618);
    }
    // 0x80014FA4: nop

L_80014FA8:
    // 0x80014FA8: b           L_80014FE4
    // 0x80014FAC: addiu       $s0, $zero, 0x16C
    ctx->r16 = ADD32(0, 0X16C);
        goto L_80014FE4;
    // 0x80014FAC: addiu       $s0, $zero, 0x16C
    ctx->r16 = ADD32(0, 0X16C);
L_80014FB0:
    // 0x80014FB0: b           L_80014FE4
    // 0x80014FB4: addiu       $s0, $zero, 0x16D
    ctx->r16 = ADD32(0, 0X16D);
        goto L_80014FE4;
    // 0x80014FB4: addiu       $s0, $zero, 0x16D
    ctx->r16 = ADD32(0, 0X16D);
L_80014FB8:
    // 0x80014FB8: b           L_80014FE4
    // 0x80014FBC: addiu       $s0, $zero, 0x16E
    ctx->r16 = ADD32(0, 0X16E);
        goto L_80014FE4;
    // 0x80014FBC: addiu       $s0, $zero, 0x16E
    ctx->r16 = ADD32(0, 0X16E);
L_80014FC0:
    // 0x80014FC0: b           L_80014FE4
    // 0x80014FC4: addiu       $s0, $zero, 0x16F
    ctx->r16 = ADD32(0, 0X16F);
        goto L_80014FE4;
    // 0x80014FC4: addiu       $s0, $zero, 0x16F
    ctx->r16 = ADD32(0, 0X16F);
L_80014FC8:
    // 0x80014FC8: b           L_80014FE4
    // 0x80014FCC: addiu       $s0, $zero, 0x170
    ctx->r16 = ADD32(0, 0X170);
        goto L_80014FE4;
    // 0x80014FCC: addiu       $s0, $zero, 0x170
    ctx->r16 = ADD32(0, 0X170);
L_80014FD0:
    // 0x80014FD0: b           L_80014FE4
    // 0x80014FD4: addiu       $s0, $zero, 0x171
    ctx->r16 = ADD32(0, 0X171);
        goto L_80014FE4;
    // 0x80014FD4: addiu       $s0, $zero, 0x171
    ctx->r16 = ADD32(0, 0X171);
L_80014FD8:
    // 0x80014FD8: b           L_80014FE4
    // 0x80014FDC: addiu       $s0, $zero, 0x172
    ctx->r16 = ADD32(0, 0X172);
        goto L_80014FE4;
    // 0x80014FDC: addiu       $s0, $zero, 0x172
    ctx->r16 = ADD32(0, 0X172);
L_80014FE0:
    // 0x80014FE0: addiu       $s0, $zero, 0x173
    ctx->r16 = ADD32(0, 0X173);
L_80014FE4:
    // 0x80014FE4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80014FE8:
    // 0x80014FE8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80014FEC: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80014FF0: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80014FF4: b           L_80015C10
    // 0x80014FF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80014FF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80014FFC:
    // 0x80014FFC: addiu       $t8, $zero, 0x17
    ctx->r24 = ADD32(0, 0X17);
    // 0x80015000: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015004: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015008: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001500C: addiu       $s0, $zero, 0x16B
    ctx->r16 = ADD32(0, 0X16B);
    // 0x80015010: b           L_80015C10
    // 0x80015014: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015014: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015018:
    // 0x80015018: addiu       $t3, $zero, 0x17
    ctx->r11 = ADD32(0, 0X17);
    // 0x8001501C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015020: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015024: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80015028: addiu       $s0, $zero, 0x169
    ctx->r16 = ADD32(0, 0X169);
    // 0x8001502C: b           L_80015C10
    // 0x80015030: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015030: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015034:
    // 0x80015034: addiu       $t5, $zero, 0x17
    ctx->r13 = ADD32(0, 0X17);
    // 0x80015038: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001503C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015040: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80015044: addiu       $s0, $zero, 0x1AC
    ctx->r16 = ADD32(0, 0X1AC);
    // 0x80015048: b           L_80015C10
    // 0x8001504C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001504C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015050:
    // 0x80015050: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80015054: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015058: addiu       $s0, $zero, 0x24D
    ctx->r16 = ADD32(0, 0X24D);
    // 0x8001505C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80015060: b           L_80015C10
    // 0x80015064: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015064: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015068:
    // 0x80015068: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001506C: ldc1        $f4, -0x19A0($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X19A0);
    // 0x80015070: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80015074: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015078: mul.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x8001507C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015080: addiu       $s0, $zero, 0x24D
    ctx->r16 = ADD32(0, 0X24D);
    // 0x80015084: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80015088: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8001508C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80015090: b           L_80015C10
    // 0x80015094: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
        goto L_80015C10;
    // 0x80015094: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
L_80015098:
    // 0x80015098: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001509C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800150A0: addiu       $s0, $zero, 0x18F
    ctx->r16 = ADD32(0, 0X18F);
    // 0x800150A4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800150A8: b           L_80015C10
    // 0x800150AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800150AC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800150B0:
    // 0x800150B0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800150B4: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800150B8: addiu       $s0, $zero, 0x190
    ctx->r16 = ADD32(0, 0X190);
    // 0x800150BC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800150C0: b           L_80015C10
    // 0x800150C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800150C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800150C8:
    // 0x800150C8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800150CC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800150D0: addiu       $s0, $zero, 0x191
    ctx->r16 = ADD32(0, 0X191);
    // 0x800150D4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x800150D8: b           L_80015C10
    // 0x800150DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800150DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800150E0:
    // 0x800150E0: beql        $s1, $zero, L_80015138
    if (ctx->r17 == 0) {
        // 0x800150E4: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80015138;
    }
    goto skip_34;
    // 0x800150E4: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    skip_34:
    // 0x800150E8: lw          $t5, 0x14($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X14);
    // 0x800150EC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800150F0: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800150F4: beq         $at, $zero, L_80015134
    if (ctx->r1 == 0) {
        // 0x800150F8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80015134;
    }
    // 0x800150F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800150FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015100: addu        $at, $at, $t6
    gpr jr_addend_80015108 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80015104: lw          $t6, -0x1978($at)
    ctx->r14 = ADD32(ctx->r1, -0X1978);
    // 0x80015108: jr          $t6
    // 0x8001510C: nop

    switch (jr_addend_80015108 >> 2) {
        case 0: goto L_80015110; break;
        case 1: goto L_80015118; break;
        case 2: goto L_80015120; break;
        case 3: goto L_80015128; break;
        case 4: goto L_80015130; break;
        default: switch_error(__func__, 0x80015108, 0x800AE688);
    }
    // 0x8001510C: nop

L_80015110:
    // 0x80015110: b           L_80015134
    // 0x80015114: addiu       $s0, $zero, 0x291
    ctx->r16 = ADD32(0, 0X291);
        goto L_80015134;
    // 0x80015114: addiu       $s0, $zero, 0x291
    ctx->r16 = ADD32(0, 0X291);
L_80015118:
    // 0x80015118: b           L_80015134
    // 0x8001511C: addiu       $s0, $zero, 0x292
    ctx->r16 = ADD32(0, 0X292);
        goto L_80015134;
    // 0x8001511C: addiu       $s0, $zero, 0x292
    ctx->r16 = ADD32(0, 0X292);
L_80015120:
    // 0x80015120: b           L_80015134
    // 0x80015124: addiu       $s0, $zero, 0x293
    ctx->r16 = ADD32(0, 0X293);
        goto L_80015134;
    // 0x80015124: addiu       $s0, $zero, 0x293
    ctx->r16 = ADD32(0, 0X293);
L_80015128:
    // 0x80015128: b           L_80015134
    // 0x8001512C: addiu       $s0, $zero, 0x294
    ctx->r16 = ADD32(0, 0X294);
        goto L_80015134;
    // 0x8001512C: addiu       $s0, $zero, 0x294
    ctx->r16 = ADD32(0, 0X294);
L_80015130:
    // 0x80015130: addiu       $s0, $zero, 0x295
    ctx->r16 = ADD32(0, 0X295);
L_80015134:
    // 0x80015134: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80015138:
    // 0x80015138: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8001513C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015140: b           L_80015C10
    // 0x80015144: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
        goto L_80015C10;
    // 0x80015144: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
L_80015148:
    // 0x80015148: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001514C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80015150: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015154: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80015158: addiu       $s0, $zero, 0x197
    ctx->r16 = ADD32(0, 0X197);
    // 0x8001515C: b           L_80015C10
    // 0x80015160: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015160: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015164:
    // 0x80015164: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80015168: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8001516C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015170: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015174: addiu       $s0, $zero, 0x198
    ctx->r16 = ADD32(0, 0X198);
    // 0x80015178: b           L_80015C10
    // 0x8001517C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001517C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015180:
    // 0x80015180: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80015184: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80015188: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001518C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80015190: addiu       $s0, $zero, 0x199
    ctx->r16 = ADD32(0, 0X199);
    // 0x80015194: b           L_80015C10
    // 0x80015198: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015198: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001519C:
    // 0x8001519C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800151A0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800151A4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800151A8: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800151AC: addiu       $s0, $zero, 0x19B
    ctx->r16 = ADD32(0, 0X19B);
    // 0x800151B0: b           L_80015C10
    // 0x800151B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800151B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800151B8:
    // 0x800151B8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800151BC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800151C0: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800151C4: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800151C8: addiu       $s0, $zero, 0x19C
    ctx->r16 = ADD32(0, 0X19C);
    // 0x800151CC: b           L_80015C10
    // 0x800151D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800151D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800151D4:
    // 0x800151D4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800151D8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800151DC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800151E0: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800151E4: addiu       $s0, $zero, 0x19A
    ctx->r16 = ADD32(0, 0X19A);
    // 0x800151E8: b           L_80015C10
    // 0x800151EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800151EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800151F0:
    // 0x800151F0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800151F4: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x800151F8: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800151FC: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80015200: addiu       $s0, $zero, 0x19D
    ctx->r16 = ADD32(0, 0X19D);
    // 0x80015204: b           L_80015C10
    // 0x80015208: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015208: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001520C:
    // 0x8001520C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80015210: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015214: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80015218: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x8001521C: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80015220: jal         0x80011928
    // 0x80015224: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011928(rdram, ctx);
        goto after_23;
    // 0x80015224: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_23:
    // 0x80015228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001522C: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80015230: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80015234: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80015238: bne         $v0, $at, L_80015260
    if (ctx->r2 != ctx->r1) {
        // 0x8001523C: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80015260;
    }
    // 0x8001523C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80015240: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80015244: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80015248: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8001524C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015250: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80015254: mul.d       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f6.d);
    // 0x80015258: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x8001525C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80015260:
    // 0x80015260: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x80015264: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80015268: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x8001526C: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80015270: b           L_80015C10
    // 0x80015274: addiu       $s0, $zero, 0x19F
    ctx->r16 = ADD32(0, 0X19F);
        goto L_80015C10;
    // 0x80015274: addiu       $s0, $zero, 0x19F
    ctx->r16 = ADD32(0, 0X19F);
L_80015278:
    // 0x80015278: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8001527C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015280: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015284: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015288: addiu       $s0, $zero, 0x1A0
    ctx->r16 = ADD32(0, 0X1A0);
    // 0x8001528C: b           L_80015C10
    // 0x80015290: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015290: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015294:
    // 0x80015294: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80015298: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8001529C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800152A0: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800152A4: addiu       $s0, $zero, 0x7E
    ctx->r16 = ADD32(0, 0X7E);
    // 0x800152A8: b           L_80015C10
    // 0x800152AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800152AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800152B0:
    // 0x800152B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800152B4: ldc1        $f18, -0x1908($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1908);
    // 0x800152B8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800152BC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800152C0: mul.d       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f16.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800152C4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800152C8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800152CC: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x800152D0: addiu       $s0, $zero, 0x1B8
    ctx->r16 = ADD32(0, 0X1B8);
    // 0x800152D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800152D8: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800152DC: b           L_80015C10
    // 0x800152E0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
        goto L_80015C10;
    // 0x800152E0: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_800152E4:
    // 0x800152E4: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x800152E8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800152EC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800152F0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800152F4: b           L_80015C10
    // 0x800152F8: addiu       $s0, $zero, 0x1BA
    ctx->r16 = ADD32(0, 0X1BA);
        goto L_80015C10;
    // 0x800152F8: addiu       $s0, $zero, 0x1BA
    ctx->r16 = ADD32(0, 0X1BA);
L_800152FC:
    // 0x800152FC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80015300: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015304: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015308: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x8001530C: addiu       $s0, $zero, 0x1BB
    ctx->r16 = ADD32(0, 0X1BB);
    // 0x80015310: b           L_80015C10
    // 0x80015314: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015314: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015318:
    // 0x80015318: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8001531C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80015320: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015324: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80015328: addiu       $s0, $zero, 0x1BC
    ctx->r16 = ADD32(0, 0X1BC);
    // 0x8001532C: b           L_80015C10
    // 0x80015330: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015330: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015334:
    // 0x80015334: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80015338: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x8001533C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015340: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80015344: addiu       $s0, $zero, 0x37
    ctx->r16 = ADD32(0, 0X37);
    // 0x80015348: b           L_80015C10
    // 0x8001534C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001534C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015350:
    // 0x80015350: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80015354: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015358: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001535C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015360: b           L_80015C10
    // 0x80015364: addiu       $s0, $zero, 0x36
    ctx->r16 = ADD32(0, 0X36);
        goto L_80015C10;
    // 0x80015364: addiu       $s0, $zero, 0x36
    ctx->r16 = ADD32(0, 0X36);
L_80015368:
    // 0x80015368: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001536C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80015370: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015374: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80015378: addiu       $s0, $zero, 0x1B9
    ctx->r16 = ADD32(0, 0X1B9);
    // 0x8001537C: b           L_80015C10
    // 0x80015380: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015380: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015384:
    // 0x80015384: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80015388: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8001538C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015390: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80015394: b           L_80015C10
    // 0x80015398: addiu       $s0, $zero, 0x6D
    ctx->r16 = ADD32(0, 0X6D);
        goto L_80015C10;
    // 0x80015398: addiu       $s0, $zero, 0x6D
    ctx->r16 = ADD32(0, 0X6D);
L_8001539C:
    // 0x8001539C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800153A0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x800153A4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800153A8: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x800153AC: addiu       $s0, $zero, 0x164
    ctx->r16 = ADD32(0, 0X164);
    // 0x800153B0: b           L_80015C10
    // 0x800153B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800153B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800153B8:
    // 0x800153B8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800153BC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x800153C0: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800153C4: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x800153C8: addiu       $s0, $zero, 0xF
    ctx->r16 = ADD32(0, 0XF);
    // 0x800153CC: b           L_80015C10
    // 0x800153D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800153D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800153D4:
    // 0x800153D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800153D8: ldc1        $f8, -0x18B0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X18B0);
    // 0x800153DC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800153E0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800153E4: mul.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f8.d);
    // 0x800153E8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x800153EC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800153F0: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800153F4: addiu       $s0, $zero, 0x9A
    ctx->r16 = ADD32(0, 0X9A);
    // 0x800153F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800153FC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80015400: b           L_80015C10
    // 0x80015404: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
        goto L_80015C10;
    // 0x80015404: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_80015408:
    // 0x80015408: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8001540C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80015410: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015414: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80015418: b           L_80015C10
    // 0x8001541C: addiu       $s0, $zero, 0x1E9
    ctx->r16 = ADD32(0, 0X1E9);
        goto L_80015C10;
    // 0x8001541C: addiu       $s0, $zero, 0x1E9
    ctx->r16 = ADD32(0, 0X1E9);
L_80015420:
    // 0x80015420: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80015424: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015428: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001542C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015430: b           L_80015C10
    // 0x80015434: addiu       $s0, $zero, 0x1EA
    ctx->r16 = ADD32(0, 0X1EA);
        goto L_80015C10;
    // 0x80015434: addiu       $s0, $zero, 0x1EA
    ctx->r16 = ADD32(0, 0X1EA);
L_80015438:
    // 0x80015438: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8001543C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80015440: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015444: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80015448: b           L_80015C10
    // 0x8001544C: addiu       $s0, $zero, 0x1EC
    ctx->r16 = ADD32(0, 0X1EC);
        goto L_80015C10;
    // 0x8001544C: addiu       $s0, $zero, 0x1EC
    ctx->r16 = ADD32(0, 0X1EC);
L_80015450:
    // 0x80015450: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80015454: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80015458: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x8001545C: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80015460: addiu       $s0, $zero, 0x1ED
    ctx->r16 = ADD32(0, 0X1ED);
    // 0x80015464: b           L_80015C10
    // 0x80015468: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015468: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001546C:
    // 0x8001546C: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80015470: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80015474: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015478: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8001547C: b           L_80015C10
    // 0x80015480: addiu       $s0, $zero, 0x1F3
    ctx->r16 = ADD32(0, 0X1F3);
        goto L_80015C10;
    // 0x80015480: addiu       $s0, $zero, 0x1F3
    ctx->r16 = ADD32(0, 0X1F3);
L_80015484:
    // 0x80015484: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x80015488: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8001548C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015490: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80015494: b           L_80015C10
    // 0x80015498: addiu       $s0, $zero, 0x1F4
    ctx->r16 = ADD32(0, 0X1F4);
        goto L_80015C10;
    // 0x80015498: addiu       $s0, $zero, 0x1F4
    ctx->r16 = ADD32(0, 0X1F4);
L_8001549C:
    // 0x8001549C: beql        $s1, $zero, L_800154F8
    if (ctx->r17 == 0) {
        // 0x800154A0: addiu       $t9, $zero, 0xE
        ctx->r25 = ADD32(0, 0XE);
            goto L_800154F8;
    }
    goto skip_35;
    // 0x800154A0: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
    skip_35:
    // 0x800154A4: lw          $v0, 0x14($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X14);
    // 0x800154A8: beq         $v0, $zero, L_800154C0
    if (ctx->r2 == 0) {
        // 0x800154AC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800154C0;
    }
    // 0x800154AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800154B0: beq         $v0, $at, L_800154C0
    if (ctx->r2 == ctx->r1) {
        // 0x800154B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800154C0;
    }
    // 0x800154B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800154B8: beq         $v0, $at, L_800154C8
    if (ctx->r2 == ctx->r1) {
        // 0x800154BC: nop
    
            goto L_800154C8;
    }
    // 0x800154BC: nop

L_800154C0:
    // 0x800154C0: b           L_800154F4
    // 0x800154C4: addiu       $s0, $zero, 0x1F5
    ctx->r16 = ADD32(0, 0X1F5);
        goto L_800154F4;
    // 0x800154C4: addiu       $s0, $zero, 0x1F5
    ctx->r16 = ADD32(0, 0X1F5);
L_800154C8:
    // 0x800154C8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800154CC: lbu         $t7, -0x6D50($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6D50);
    // 0x800154D0: beq         $t7, $zero, L_800154E4
    if (ctx->r15 == 0) {
        // 0x800154D4: lui         $at, 0x800A
        ctx->r1 = S32(0X800A << 16);
            goto L_800154E4;
    }
    // 0x800154D4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800154D8: sb          $zero, -0x6D50($at)
    MEM_B(-0X6D50, ctx->r1) = 0;
    // 0x800154DC: b           L_800154F4
    // 0x800154E0: addiu       $s0, $zero, 0x211
    ctx->r16 = ADD32(0, 0X211);
        goto L_800154F4;
    // 0x800154E0: addiu       $s0, $zero, 0x211
    ctx->r16 = ADD32(0, 0X211);
L_800154E4:
    // 0x800154E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800154E8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800154EC: sb          $t8, -0x6D50($at)
    MEM_B(-0X6D50, ctx->r1) = ctx->r24;
    // 0x800154F0: addiu       $s0, $zero, 0x212
    ctx->r16 = ADD32(0, 0X212);
L_800154F4:
    // 0x800154F4: addiu       $t9, $zero, 0xE
    ctx->r25 = ADD32(0, 0XE);
L_800154F8:
    // 0x800154F8: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800154FC: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015500: b           L_80015C10
    // 0x80015504: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
        goto L_80015C10;
    // 0x80015504: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
L_80015508:
    // 0x80015508: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8001550C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80015510: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015514: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015518: b           L_80015C10
    // 0x8001551C: addiu       $s0, $zero, 0x1F6
    ctx->r16 = ADD32(0, 0X1F6);
        goto L_80015C10;
    // 0x8001551C: addiu       $s0, $zero, 0x1F6
    ctx->r16 = ADD32(0, 0X1F6);
L_80015520:
    // 0x80015520: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80015524: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80015528: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x8001552C: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x80015530: addiu       $s0, $zero, 0x204
    ctx->r16 = ADD32(0, 0X204);
    // 0x80015534: b           L_80015C10
    // 0x80015538: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015538: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8001553C:
    // 0x8001553C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80015540: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80015544: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015548: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x8001554C: addiu       $s0, $zero, 0x205
    ctx->r16 = ADD32(0, 0X205);
    // 0x80015550: b           L_80015C10
    // 0x80015554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015554: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015558:
    // 0x80015558: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8001555C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015560: addiu       $s0, $zero, 0x206
    ctx->r16 = ADD32(0, 0X206);
    // 0x80015564: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x80015568: b           L_80015C10
    // 0x8001556C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001556C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015570:
    // 0x80015570: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x80015574: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80015578: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x8001557C: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x80015580: b           L_80015C10
    // 0x80015584: addiu       $s0, $zero, 0x203
    ctx->r16 = ADD32(0, 0X203);
        goto L_80015C10;
    // 0x80015584: addiu       $s0, $zero, 0x203
    ctx->r16 = ADD32(0, 0X203);
L_80015588:
    // 0x80015588: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8001558C: lbu         $t6, -0x6D78($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X6D78);
    // 0x80015590: bne         $t6, $zero, L_80015E60
    if (ctx->r14 != 0) {
        // 0x80015594: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_80015E60;
    }
    // 0x80015594: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80015598: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8001559C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800155A0: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x800155A4: addiu       $s0, $zero, 0x20B
    ctx->r16 = ADD32(0, 0X20B);
    // 0x800155A8: b           L_80015C10
    // 0x800155AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x800155AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800155B0:
    // 0x800155B0: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x800155B4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800155B8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800155BC: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x800155C0: b           L_80015C10
    // 0x800155C4: addiu       $s0, $zero, 0x20C
    ctx->r16 = ADD32(0, 0X20C);
        goto L_80015C10;
    // 0x800155C4: addiu       $s0, $zero, 0x20C
    ctx->r16 = ADD32(0, 0X20C);
L_800155C8:
    // 0x800155C8: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x800155CC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800155D0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800155D4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x800155D8: b           L_80015C10
    // 0x800155DC: addiu       $s0, $zero, 0x20F
    ctx->r16 = ADD32(0, 0X20F);
        goto L_80015C10;
    // 0x800155DC: addiu       $s0, $zero, 0x20F
    ctx->r16 = ADD32(0, 0X20F);
L_800155E0:
    // 0x800155E0: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x800155E4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800155E8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800155EC: sh          $t6, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r14;
    // 0x800155F0: b           L_80015C10
    // 0x800155F4: addiu       $s0, $zero, 0x210
    ctx->r16 = ADD32(0, 0X210);
        goto L_80015C10;
    // 0x800155F4: addiu       $s0, $zero, 0x210
    ctx->r16 = ADD32(0, 0X210);
L_800155F8:
    // 0x800155F8: addiu       $t8, $zero, 0x16
    ctx->r24 = ADD32(0, 0X16);
    // 0x800155FC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80015600: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015604: sh          $t8, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r24;
    // 0x80015608: b           L_80015C10
    // 0x8001560C: addiu       $s0, $zero, 0x20D
    ctx->r16 = ADD32(0, 0X20D);
        goto L_80015C10;
    // 0x8001560C: addiu       $s0, $zero, 0x20D
    ctx->r16 = ADD32(0, 0X20D);
L_80015610:
    // 0x80015610: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80015614: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80015618: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001561C: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x80015620: b           L_80015C10
    // 0x80015624: addiu       $s0, $zero, 0x214
    ctx->r16 = ADD32(0, 0X214);
        goto L_80015C10;
    // 0x80015624: addiu       $s0, $zero, 0x214
    ctx->r16 = ADD32(0, 0X214);
L_80015628:
    // 0x80015628: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x8001562C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80015630: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015634: sh          $t5, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r13;
    // 0x80015638: addiu       $s0, $zero, 0x25B
    ctx->r16 = ADD32(0, 0X25B);
    // 0x8001563C: b           L_80015C10
    // 0x80015640: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015640: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80015644:
    // 0x80015644: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80015648: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8001564C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015650: sh          $t7, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r15;
    // 0x80015654: addiu       $s0, $zero, 0x259
    ctx->r16 = ADD32(0, 0X259);
    // 0x80015658: b           L_80015C10
    // 0x8001565C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x8001565C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015660:
    // 0x80015660: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80015664: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015668: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x8001566C: sh          $t9, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r25;
    // 0x80015670: addiu       $s0, $zero, 0x25A
    ctx->r16 = ADD32(0, 0X25A);
    // 0x80015674: b           L_80015C10
    // 0x80015678: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015678: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8001567C:
    // 0x8001567C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80015680: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015684: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015688: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x8001568C: addiu       $s0, $zero, 0x266
    ctx->r16 = ADD32(0, 0X266);
    // 0x80015690: b           L_80015C10
    // 0x80015694: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80015C10;
    // 0x80015694: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80015698:
    // 0x80015698: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001569C: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800156A0: addiu       $s0, $zero, 0x10B
    ctx->r16 = ADD32(0, 0X10B);
    // 0x800156A4: b           L_80015C10
    // 0x800156A8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800156A8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800156AC:
    // 0x800156AC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800156B0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800156B4: addiu       $s0, $zero, 0x10C
    ctx->r16 = ADD32(0, 0X10C);
    // 0x800156B8: b           L_80015C10
    // 0x800156BC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800156BC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800156C0:
    // 0x800156C0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800156C4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800156C8: addiu       $s0, $zero, 0x10D
    ctx->r16 = ADD32(0, 0X10D);
    // 0x800156CC: b           L_80015C10
    // 0x800156D0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800156D0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800156D4:
    // 0x800156D4: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800156D8: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800156DC: addiu       $s0, $zero, 0x10E
    ctx->r16 = ADD32(0, 0X10E);
    // 0x800156E0: b           L_80015C10
    // 0x800156E4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800156E4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800156E8:
    // 0x800156E8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800156EC: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800156F0: addiu       $s0, $zero, 0x10F
    ctx->r16 = ADD32(0, 0X10F);
    // 0x800156F4: b           L_80015C10
    // 0x800156F8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800156F8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800156FC:
    // 0x800156FC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015700: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015704: addiu       $s0, $zero, 0x110
    ctx->r16 = ADD32(0, 0X110);
    // 0x80015708: b           L_80015C10
    // 0x8001570C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001570C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015710:
    // 0x80015710: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015714: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015718: addiu       $s0, $zero, 0x111
    ctx->r16 = ADD32(0, 0X111);
    // 0x8001571C: b           L_80015C10
    // 0x80015720: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015720: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015724:
    // 0x80015724: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015728: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001572C: addiu       $s0, $zero, 0x112
    ctx->r16 = ADD32(0, 0X112);
    // 0x80015730: b           L_80015C10
    // 0x80015734: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015734: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015738:
    // 0x80015738: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001573C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015740: addiu       $s0, $zero, 0x113
    ctx->r16 = ADD32(0, 0X113);
    // 0x80015744: b           L_80015C10
    // 0x80015748: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015748: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001574C:
    // 0x8001574C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015750: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015754: addiu       $s0, $zero, 0x114
    ctx->r16 = ADD32(0, 0X114);
    // 0x80015758: b           L_80015C10
    // 0x8001575C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001575C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015760:
    // 0x80015760: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015764: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015768: addiu       $s0, $zero, 0x115
    ctx->r16 = ADD32(0, 0X115);
    // 0x8001576C: b           L_80015C10
    // 0x80015770: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015770: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015774:
    // 0x80015774: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015778: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x8001577C: addiu       $s0, $zero, 0x116
    ctx->r16 = ADD32(0, 0X116);
    // 0x80015780: b           L_80015C10
    // 0x80015784: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015784: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015788:
    // 0x80015788: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8001578C: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015790: addiu       $s0, $zero, 0x117
    ctx->r16 = ADD32(0, 0X117);
    // 0x80015794: b           L_80015C10
    // 0x80015798: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015798: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001579C:
    // 0x8001579C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800157A0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800157A4: addiu       $s0, $zero, 0x118
    ctx->r16 = ADD32(0, 0X118);
    // 0x800157A8: b           L_80015C10
    // 0x800157AC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800157AC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800157B0:
    // 0x800157B0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800157B4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800157B8: addiu       $s0, $zero, 0x119
    ctx->r16 = ADD32(0, 0X119);
    // 0x800157BC: b           L_80015C10
    // 0x800157C0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800157C0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800157C4:
    // 0x800157C4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800157C8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800157CC: addiu       $s0, $zero, 0x11A
    ctx->r16 = ADD32(0, 0X11A);
    // 0x800157D0: b           L_80015C10
    // 0x800157D4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800157D4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800157D8:
    // 0x800157D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800157DC: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800157E0: addiu       $s0, $zero, 0x11B
    ctx->r16 = ADD32(0, 0X11B);
    // 0x800157E4: b           L_80015C10
    // 0x800157E8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800157E8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800157EC:
    // 0x800157EC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800157F0: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x800157F4: addiu       $s0, $zero, 0x11C
    ctx->r16 = ADD32(0, 0X11C);
    // 0x800157F8: b           L_80015C10
    // 0x800157FC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800157FC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015800:
    // 0x80015800: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015804: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015808: addiu       $s0, $zero, 0x11D
    ctx->r16 = ADD32(0, 0X11D);
    // 0x8001580C: b           L_80015C10
    // 0x80015810: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015810: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015814:
    // 0x80015814: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015818: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8001581C: addiu       $s0, $zero, 0x11E
    ctx->r16 = ADD32(0, 0X11E);
    // 0x80015820: b           L_80015C10
    // 0x80015824: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015824: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015828:
    // 0x80015828: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8001582C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015830: addiu       $s0, $zero, 0x1BF
    ctx->r16 = ADD32(0, 0X1BF);
    // 0x80015834: b           L_80015C10
    // 0x80015838: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015838: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001583C:
    // 0x8001583C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015840: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015844: addiu       $s0, $zero, 0x1C0
    ctx->r16 = ADD32(0, 0X1C0);
    // 0x80015848: b           L_80015C10
    // 0x8001584C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001584C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015850:
    // 0x80015850: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80015854: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015858: addiu       $s0, $zero, 0x1C1
    ctx->r16 = ADD32(0, 0X1C1);
    // 0x8001585C: b           L_80015C10
    // 0x80015860: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015860: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015864:
    // 0x80015864: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015868: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8001586C: addiu       $s0, $zero, 0x1C2
    ctx->r16 = ADD32(0, 0X1C2);
    // 0x80015870: b           L_80015C10
    // 0x80015874: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015874: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015878:
    // 0x80015878: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001587C: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015880: addiu       $s0, $zero, 0x1C3
    ctx->r16 = ADD32(0, 0X1C3);
    // 0x80015884: b           L_80015C10
    // 0x80015888: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015888: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001588C:
    // 0x8001588C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015890: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015894: addiu       $s0, $zero, 0x1C4
    ctx->r16 = ADD32(0, 0X1C4);
    // 0x80015898: b           L_80015C10
    // 0x8001589C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001589C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800158A0:
    // 0x800158A0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800158A4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800158A8: addiu       $s0, $zero, 0x1C5
    ctx->r16 = ADD32(0, 0X1C5);
    // 0x800158AC: b           L_80015C10
    // 0x800158B0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800158B0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800158B4:
    // 0x800158B4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800158B8: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800158BC: addiu       $s0, $zero, 0x1C6
    ctx->r16 = ADD32(0, 0X1C6);
    // 0x800158C0: b           L_80015C10
    // 0x800158C4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800158C4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800158C8:
    // 0x800158C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800158CC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800158D0: addiu       $s0, $zero, 0x1C7
    ctx->r16 = ADD32(0, 0X1C7);
    // 0x800158D4: b           L_80015C10
    // 0x800158D8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800158D8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800158DC:
    // 0x800158DC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800158E0: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800158E4: addiu       $s0, $zero, 0x1C8
    ctx->r16 = ADD32(0, 0X1C8);
    // 0x800158E8: b           L_80015C10
    // 0x800158EC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800158EC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800158F0:
    // 0x800158F0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800158F4: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x800158F8: addiu       $s0, $zero, 0x1C9
    ctx->r16 = ADD32(0, 0X1C9);
    // 0x800158FC: b           L_80015C10
    // 0x80015900: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015900: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015904:
    // 0x80015904: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015908: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x8001590C: addiu       $s0, $zero, 0x1CA
    ctx->r16 = ADD32(0, 0X1CA);
    // 0x80015910: b           L_80015C10
    // 0x80015914: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015914: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015918:
    // 0x80015918: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8001591C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015920: addiu       $s0, $zero, 0x1CB
    ctx->r16 = ADD32(0, 0X1CB);
    // 0x80015924: b           L_80015C10
    // 0x80015928: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015928: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001592C:
    // 0x8001592C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015930: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015934: addiu       $s0, $zero, 0x1CC
    ctx->r16 = ADD32(0, 0X1CC);
    // 0x80015938: b           L_80015C10
    // 0x8001593C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001593C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015940:
    // 0x80015940: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015944: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015948: addiu       $s0, $zero, 0x1CD
    ctx->r16 = ADD32(0, 0X1CD);
    // 0x8001594C: b           L_80015C10
    // 0x80015950: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015950: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015954:
    // 0x80015954: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015958: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x8001595C: addiu       $s0, $zero, 0x1CE
    ctx->r16 = ADD32(0, 0X1CE);
    // 0x80015960: b           L_80015C10
    // 0x80015964: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015964: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015968:
    // 0x80015968: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001596C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015970: addiu       $s0, $zero, 0x1CF
    ctx->r16 = ADD32(0, 0X1CF);
    // 0x80015974: b           L_80015C10
    // 0x80015978: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015978: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_8001597C:
    // 0x8001597C: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015980: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015984: addiu       $s0, $zero, 0x1D0
    ctx->r16 = ADD32(0, 0X1D0);
    // 0x80015988: b           L_80015C10
    // 0x8001598C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x8001598C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015990:
    // 0x80015990: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015994: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015998: addiu       $s0, $zero, 0x1D1
    ctx->r16 = ADD32(0, 0X1D1);
    // 0x8001599C: b           L_80015C10
    // 0x800159A0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800159A0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800159A4:
    // 0x800159A4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800159A8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x800159AC: addiu       $s0, $zero, 0x1D2
    ctx->r16 = ADD32(0, 0X1D2);
    // 0x800159B0: b           L_80015C10
    // 0x800159B4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800159B4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800159B8:
    // 0x800159B8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800159BC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x800159C0: addiu       $s0, $zero, 0x21A
    ctx->r16 = ADD32(0, 0X21A);
    // 0x800159C4: b           L_80015C10
    // 0x800159C8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800159C8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800159CC:
    // 0x800159CC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800159D0: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x800159D4: addiu       $s0, $zero, 0x21B
    ctx->r16 = ADD32(0, 0X21B);
    // 0x800159D8: b           L_80015C10
    // 0x800159DC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800159DC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800159E0:
    // 0x800159E0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800159E4: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x800159E8: addiu       $s0, $zero, 0x21C
    ctx->r16 = ADD32(0, 0X21C);
    // 0x800159EC: b           L_80015C10
    // 0x800159F0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x800159F0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_800159F4:
    // 0x800159F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800159F8: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x800159FC: addiu       $s0, $zero, 0x21D
    ctx->r16 = ADD32(0, 0X21D);
    // 0x80015A00: b           L_80015C10
    // 0x80015A04: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A04: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A08:
    // 0x80015A08: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015A0C: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015A10: addiu       $s0, $zero, 0x21E
    ctx->r16 = ADD32(0, 0X21E);
    // 0x80015A14: b           L_80015C10
    // 0x80015A18: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A18: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A1C:
    // 0x80015A1C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015A20: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015A24: addiu       $s0, $zero, 0x21F
    ctx->r16 = ADD32(0, 0X21F);
    // 0x80015A28: b           L_80015C10
    // 0x80015A2C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A2C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A30:
    // 0x80015A30: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015A34: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015A38: addiu       $s0, $zero, 0x220
    ctx->r16 = ADD32(0, 0X220);
    // 0x80015A3C: b           L_80015C10
    // 0x80015A40: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A40: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A44:
    // 0x80015A44: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015A48: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015A4C: addiu       $s0, $zero, 0x221
    ctx->r16 = ADD32(0, 0X221);
    // 0x80015A50: b           L_80015C10
    // 0x80015A54: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A54: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A58:
    // 0x80015A58: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015A5C: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015A60: addiu       $s0, $zero, 0x222
    ctx->r16 = ADD32(0, 0X222);
    // 0x80015A64: b           L_80015C10
    // 0x80015A68: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A68: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A6C:
    // 0x80015A6C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015A70: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015A74: addiu       $s0, $zero, 0x223
    ctx->r16 = ADD32(0, 0X223);
    // 0x80015A78: b           L_80015C10
    // 0x80015A7C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A7C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A80:
    // 0x80015A80: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80015A84: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015A88: addiu       $s0, $zero, 0x224
    ctx->r16 = ADD32(0, 0X224);
    // 0x80015A8C: b           L_80015C10
    // 0x80015A90: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015A90: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015A94:
    // 0x80015A94: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015A98: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015A9C: addiu       $s0, $zero, 0x225
    ctx->r16 = ADD32(0, 0X225);
    // 0x80015AA0: b           L_80015C10
    // 0x80015AA4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015AA4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015AA8:
    // 0x80015AA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015AAC: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015AB0: addiu       $s0, $zero, 0x226
    ctx->r16 = ADD32(0, 0X226);
    // 0x80015AB4: b           L_80015C10
    // 0x80015AB8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015AB8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015ABC:
    // 0x80015ABC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015AC0: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015AC4: addiu       $s0, $zero, 0x227
    ctx->r16 = ADD32(0, 0X227);
    // 0x80015AC8: b           L_80015C10
    // 0x80015ACC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015ACC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015AD0:
    // 0x80015AD0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015AD4: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015AD8: addiu       $s0, $zero, 0x228
    ctx->r16 = ADD32(0, 0X228);
    // 0x80015ADC: b           L_80015C10
    // 0x80015AE0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015AE0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015AE4:
    // 0x80015AE4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015AE8: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015AEC: addiu       $s0, $zero, 0x229
    ctx->r16 = ADD32(0, 0X229);
    // 0x80015AF0: b           L_80015C10
    // 0x80015AF4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015AF4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015AF8:
    // 0x80015AF8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015AFC: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015B00: addiu       $s0, $zero, 0x22A
    ctx->r16 = ADD32(0, 0X22A);
    // 0x80015B04: b           L_80015C10
    // 0x80015B08: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B08: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B0C:
    // 0x80015B0C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80015B10: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015B14: addiu       $s0, $zero, 0x22B
    ctx->r16 = ADD32(0, 0X22B);
    // 0x80015B18: b           L_80015C10
    // 0x80015B1C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B1C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B20:
    // 0x80015B20: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015B24: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015B28: addiu       $s0, $zero, 0x22C
    ctx->r16 = ADD32(0, 0X22C);
    // 0x80015B2C: b           L_80015C10
    // 0x80015B30: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B30: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B34:
    // 0x80015B34: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015B38: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015B3C: addiu       $s0, $zero, 0x22D
    ctx->r16 = ADD32(0, 0X22D);
    // 0x80015B40: b           L_80015C10
    // 0x80015B44: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B44: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B48:
    // 0x80015B48: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015B4C: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015B50: addiu       $s0, $zero, 0x22E
    ctx->r16 = ADD32(0, 0X22E);
    // 0x80015B54: b           L_80015C10
    // 0x80015B58: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B58: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B5C:
    // 0x80015B5C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015B60: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015B64: addiu       $s0, $zero, 0x22F
    ctx->r16 = ADD32(0, 0X22F);
    // 0x80015B68: b           L_80015C10
    // 0x80015B6C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B6C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B70:
    // 0x80015B70: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015B74: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015B78: addiu       $s0, $zero, 0x230
    ctx->r16 = ADD32(0, 0X230);
    // 0x80015B7C: b           L_80015C10
    // 0x80015B80: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B80: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B84:
    // 0x80015B84: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80015B88: sh          $t6, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r14;
    // 0x80015B8C: addiu       $s0, $zero, 0x231
    ctx->r16 = ADD32(0, 0X231);
    // 0x80015B90: b           L_80015C10
    // 0x80015B94: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015B94: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015B98:
    // 0x80015B98: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80015B9C: sh          $t7, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r15;
    // 0x80015BA0: addiu       $s0, $zero, 0x232
    ctx->r16 = ADD32(0, 0X232);
    // 0x80015BA4: b           L_80015C10
    // 0x80015BA8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015BA8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015BAC:
    // 0x80015BAC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80015BB0: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x80015BB4: addiu       $s0, $zero, 0x233
    ctx->r16 = ADD32(0, 0X233);
    // 0x80015BB8: b           L_80015C10
    // 0x80015BBC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015BBC: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015BC0:
    // 0x80015BC0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80015BC4: sh          $t9, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r25;
    // 0x80015BC8: addiu       $s0, $zero, 0x234
    ctx->r16 = ADD32(0, 0X234);
    // 0x80015BCC: b           L_80015C10
    // 0x80015BD0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015BD0: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015BD4:
    // 0x80015BD4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80015BD8: sh          $t3, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r11;
    // 0x80015BDC: addiu       $s0, $zero, 0x235
    ctx->r16 = ADD32(0, 0X235);
    // 0x80015BE0: b           L_80015C10
    // 0x80015BE4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015BE4: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015BE8:
    // 0x80015BE8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80015BEC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x80015BF0: addiu       $s0, $zero, 0x236
    ctx->r16 = ADD32(0, 0X236);
    // 0x80015BF4: b           L_80015C10
    // 0x80015BF8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015BF8: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015BFC:
    // 0x80015BFC: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80015C00: sh          $t5, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r13;
    // 0x80015C04: addiu       $s0, $zero, 0x237
    ctx->r16 = ADD32(0, 0X237);
    // 0x80015C08: b           L_80015C10
    // 0x80015C0C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
        goto L_80015C10;
    // 0x80015C0C: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
L_80015C10:
    // 0x80015C10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_80015C14:
    // 0x80015C14: beql        $s0, $at, L_80015E64
    if (ctx->r16 == ctx->r1) {
        // 0x80015C18: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80015E64;
    }
    goto skip_36;
    // 0x80015C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_36:
    // 0x80015C1C: bne         $t1, $zero, L_80015C50
    if (ctx->r9 != 0) {
        // 0x80015C20: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80015C50;
    }
    // 0x80015C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80015C24: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80015C28: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x80015C2C: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80015C30: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80015C34: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80015C38: jal         0x80011AE4
    // 0x80015C3C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    func_80011AE4(rdram, ctx);
        goto after_24;
    // 0x80015C3C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    after_24:
    // 0x80015C40: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80015C44: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80015C48: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80015C4C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
L_80015C50:
    // 0x80015C50: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80015C54: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80015C58: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80015C5C: lh          $a1, 0x54($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X54);
    // 0x80015C60: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x80015C64: lh          $a3, 0x50($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X50);
    // 0x80015C68: sh          $t0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r8;
    // 0x80015C6C: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    // 0x80015C70: sh          $t2, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r10;
    // 0x80015C74: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x80015C78: jal         0x8001B7B0
    // 0x80015C7C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_8001B7B0(rdram, ctx);
        goto after_25;
    // 0x80015C7C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_25:
    // 0x80015C80: lh          $t0, 0x44($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X44);
    // 0x80015C84: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015C88: ldc1        $f2, -0x15B0($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X15B0);
    // 0x80015C8C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80015C90: lh          $t2, 0x42($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X42);
    // 0x80015C94: beq         $t0, $zero, L_80015D20
    if (ctx->r8 == 0) {
        // 0x80015C98: lwc1        $f12, 0x48($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
            goto L_80015D20;
    }
    // 0x80015C98: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80015C9C: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x80015CA0: lw          $t6, 0x6BA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BA4);
    // 0x80015CA4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80015CA8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80015CAC: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x80015CB0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80015CB4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80015CB8: bgez        $t7, L_80015CD4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80015CBC: cvt.d.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
            goto L_80015CD4;
    }
    // 0x80015CBC: cvt.d.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.d = CVT_D_W(ctx->f4.u32l);
    // 0x80015CC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80015CC4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80015CC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015CCC: nop

    // 0x80015CD0: add.d       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f8.d + ctx->f10.d;
L_80015CD4:
    // 0x80015CD4: sub.d       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f6.d - ctx->f8.d;
    // 0x80015CD8: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80015CDC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80015CE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015CE4: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80015CE8: lui         $at, 0x4064
    ctx->r1 = S32(0X4064 << 16);
    // 0x80015CEC: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80015CF0: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80015CF4: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80015CF8: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80015CFC: div.d       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x80015D00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80015D04: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80015D08: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x80015D0C: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x80015D10: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
    // 0x80015D14: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80015D18: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80015D1C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
L_80015D20:
    // 0x80015D20: beq         $t2, $zero, L_80015E00
    if (ctx->r10 == 0) {
        // 0x80015D24: lui         $t8, 0x800A
        ctx->r24 = S32(0X800A << 16);
            goto L_80015E00;
    }
    // 0x80015D24: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80015D28: lbu         $t8, -0x6D14($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6D14);
    // 0x80015D2C: beq         $t8, $zero, L_80015D44
    if (ctx->r24 == 0) {
        // 0x80015D30: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80015D44;
    }
    // 0x80015D30: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015D34: ldc1        $f10, -0x15A8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X15A8);
    // 0x80015D38: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80015D3C: mul.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f10.d);
    // 0x80015D40: cvt.s.d     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f12.fl = CVT_S_D(ctx->f16.d);
L_80015D44:
    // 0x80015D44: beq         $s1, $zero, L_80015E00
    if (ctx->r17 == 0) {
        // 0x80015D48: nop
    
            goto L_80015E00;
    }
    // 0x80015D48: nop

    // 0x80015D4C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x80015D50: slti        $at, $v0, 0x41
    ctx->r1 = SIGNED(ctx->r2) < 0X41 ? 1 : 0;
    // 0x80015D54: bne         $at, $zero, L_80015D6C
    if (ctx->r1 != 0) {
        // 0x80015D58: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_80015D6C;
    }
    // 0x80015D58: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x80015D5C: beq         $v0, $at, L_80015DAC
    if (ctx->r2 == ctx->r1) {
        // 0x80015D60: nop
    
            goto L_80015DAC;
    }
    // 0x80015D60: nop

    // 0x80015D64: b           L_80015E00
    // 0x80015D68: nop

        goto L_80015E00;
    // 0x80015D68: nop

L_80015D6C:
    // 0x80015D6C: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x80015D70: bne         $at, $zero, L_80015D88
    if (ctx->r1 != 0) {
        // 0x80015D74: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80015D88;
    }
    // 0x80015D74: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80015D78: beq         $v0, $at, L_80015DD4
    if (ctx->r2 == ctx->r1) {
        // 0x80015D7C: nop
    
            goto L_80015DD4;
    }
    // 0x80015D7C: nop

    // 0x80015D80: b           L_80015E00
    // 0x80015D84: nop

        goto L_80015E00;
    // 0x80015D84: nop

L_80015D88:
    // 0x80015D88: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80015D8C: sltiu       $at, $t9, 0x20
    ctx->r1 = ctx->r25 < 0X20 ? 1 : 0;
    // 0x80015D90: beq         $at, $zero, L_80015E00
    if (ctx->r1 == 0) {
        // 0x80015D94: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80015E00;
    }
    // 0x80015D94: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80015D98: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015D9C: addu        $at, $at, $t9
    gpr jr_addend_80015DA4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80015DA0: lw          $t9, -0x15A0($at)
    ctx->r25 = ADD32(ctx->r1, -0X15A0);
    // 0x80015DA4: jr          $t9
    // 0x80015DA8: nop

    switch (jr_addend_80015DA4 >> 2) {
        case 0: goto L_80015E00; break;
        case 1: goto L_80015DAC; break;
        case 2: goto L_80015E00; break;
        case 3: goto L_80015DC4; break;
        case 4: goto L_80015E00; break;
        case 5: goto L_80015E00; break;
        case 6: goto L_80015E00; break;
        case 7: goto L_80015E00; break;
        case 8: goto L_80015E00; break;
        case 9: goto L_80015E00; break;
        case 10: goto L_80015E00; break;
        case 11: goto L_80015E00; break;
        case 12: goto L_80015E00; break;
        case 13: goto L_80015E00; break;
        case 14: goto L_80015E00; break;
        case 15: goto L_80015DC4; break;
        case 16: goto L_80015E00; break;
        case 17: goto L_80015E00; break;
        case 18: goto L_80015E00; break;
        case 19: goto L_80015E00; break;
        case 20: goto L_80015E00; break;
        case 21: goto L_80015E00; break;
        case 22: goto L_80015E00; break;
        case 23: goto L_80015E00; break;
        case 24: goto L_80015E00; break;
        case 25: goto L_80015E00; break;
        case 26: goto L_80015E00; break;
        case 27: goto L_80015E00; break;
        case 28: goto L_80015E00; break;
        case 29: goto L_80015E00; break;
        case 30: goto L_80015E00; break;
        case 31: goto L_80015DEC; break;
        default: switch_error(__func__, 0x80015DA4, 0x800AEA60);
    }
    // 0x80015DA8: nop

L_80015DAC:
    // 0x80015DAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015DB0: ldc1        $f6, -0x1520($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X1520);
    // 0x80015DB4: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80015DB8: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80015DBC: b           L_80015E00
    // 0x80015DC0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
        goto L_80015E00;
    // 0x80015DC0: cvt.s.d     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f12.fl = CVT_S_D(ctx->f8.d);
L_80015DC4:
    // 0x80015DC4: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x80015DC8: mul.d       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x80015DCC: b           L_80015E00
    // 0x80015DD0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
        goto L_80015E00;
    // 0x80015DD0: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80015DD4:
    // 0x80015DD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015DD8: ldc1        $f4, -0x1518($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X1518);
    // 0x80015DDC: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x80015DE0: mul.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f16.d, ctx->f4.d);
    // 0x80015DE4: b           L_80015E00
    // 0x80015DE8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
        goto L_80015E00;
    // 0x80015DE8: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
L_80015DEC:
    // 0x80015DEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80015DF0: ldc1        $f18, -0x1510($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X1510);
    // 0x80015DF4: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80015DF8: mul.d       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f18.d);
    // 0x80015DFC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_80015E00:
    // 0x80015E00: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80015E04: addiu       $s0, $s0, -0x6CEC
    ctx->r16 = ADD32(ctx->r16, -0X6CEC);
    // 0x80015E08: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80015E0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80015E10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80015E14: jal         0x8001BCD0
    // 0x80015E18: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    func_8001BCD0(rdram, ctx);
        goto after_26;
    // 0x80015E18: sh          $t1, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r9;
    after_26:
    // 0x80015E1C: lh          $t1, 0x3E($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3E);
    // 0x80015E20: bne         $t1, $zero, L_80015E60
    if (ctx->r9 != 0) {
        // 0x80015E24: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80015E60;
    }
    // 0x80015E24: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80015E28: addiu       $v0, $v0, -0x6D80
    ctx->r2 = ADD32(ctx->r2, -0X6D80);
    // 0x80015E2C: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80015E30: beq         $t3, $zero, L_80015E60
    if (ctx->r11 == 0) {
        // 0x80015E34: lui         $t4, 0x800A
        ctx->r12 = S32(0X800A << 16);
            goto L_80015E60;
    }
    // 0x80015E34: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80015E38: lh          $t4, -0x6D90($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6D90);
    // 0x80015E3C: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80015E40: bnel        $t4, $at, L_80015E54
    if (ctx->r12 != ctx->r1) {
        // 0x80015E44: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_80015E54;
    }
    goto skip_37;
    // 0x80015E44: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_37:
    // 0x80015E48: b           L_80015E60
    // 0x80015E4C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
        goto L_80015E60;
    // 0x80015E4C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80015E50: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_80015E54:
    // 0x80015E54: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80015E58: jal         0x8001BCF4
    // 0x80015E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8001BCF4(rdram, ctx);
        goto after_27;
    // 0x80015E5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
L_80015E60:
    // 0x80015E60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80015E64:
    // 0x80015E64: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80015E68: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80015E6C: jr          $ra
    // 0x80015E70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80015E70: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_807AF65C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF65C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807AF660: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807AF664: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AF668: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807AF66C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AF670: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807AF674: bne         $v0, $at, L_807AF6B0
    if (ctx->r2 != ctx->r1) {
        // 0x807AF678: nop
    
            goto L_807AF6B0;
    }
    // 0x807AF678: nop

    // 0x807AF67C: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x807AF680: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807AF684: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x807AF688: beq         $v0, $zero, L_807AF6B0
    if (ctx->r2 == 0) {
        // 0x807AF68C: nop
    
            goto L_807AF6B0;
    }
    // 0x807AF68C: nop

    // 0x807AF690: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF694: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF698: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF69C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AF6A0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807AF6A4: bne         $t8, $at, L_807AF6B0
    if (ctx->r24 != ctx->r1) {
        // 0x807AF6A8: nop
    
            goto L_807AF6B0;
    }
    // 0x807AF6A8: nop

    // 0x807AF6AC: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
L_807AF6B0:
    // 0x807AF6B0: jr          $ra
    // 0x807AF6B4: nop

    return;
    // 0x807AF6B4: nop

;}
RECOMP_FUNC void func_8073B270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073B270: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8073B274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073B278: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x8073B27C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073B280: lbu         $v0, 0x10($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X10);
    // 0x8073B284: addiu       $v0, $v0, -0x10
    ctx->r2 = ADD32(ctx->r2, -0X10);
    // 0x8073B288: bgtzl       $v0, L_8073B2C8
    if (SIGNED(ctx->r2) > 0) {
        // 0x8073B28C: sb          $v0, 0x10($v1)
        MEM_B(0X10, ctx->r3) = ctx->r2;
            goto L_8073B2C8;
    }
    goto skip_0;
    // 0x8073B28C: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
    skip_0:
    // 0x8073B290: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8073B294: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8073B298: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8073B29C: swc1        $f4, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f4.u32l;
    // 0x8073B2A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8073B2A4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8073B2A8: jal         0x8073B8CC
    // 0x8073B2AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8073B8CC(rdram, ctx);
        goto after_0;
    // 0x8073B2AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8073B2B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8073B2B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8073B2B8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8073B2BC: lw          $t6, 0x148($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X148);
    // 0x8073B2C0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8073B2C4: sb          $v0, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r2;
L_8073B2C8:
    // 0x8073B2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073B2CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8073B2D0: jr          $ra
    // 0x8073B2D4: nop

    return;
    // 0x8073B2D4: nop

;}
RECOMP_FUNC void func_804C358C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C358C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C3590: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C3594: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C3598: jal         0x804C3530
    // 0x804C359C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C3530(rdram, ctx);
        goto after_0;
    // 0x804C359C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C35A0: bne         $v0, $zero, L_804C35B8
    if (ctx->r2 != 0) {
        // 0x804C35A4: lui         $t6, 0x804C
        ctx->r14 = S32(RELOC_HI16(206, 0X678) << 16);
            goto L_804C35B8;
    }
    // 0x804C35A4: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(206, 0X678) << 16);
    // 0x804C35A8: jal         0x800447C8
    // 0x804C35AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x804C35AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C35B0: b           L_804C3608
    // 0x804C35B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C3608;
    // 0x804C35B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C35B8:
    // 0x804C35B8: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x804C35BC: addiu       $t6, $t6, 0x30F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(206, 0X678));
    // 0x804C35C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C35C4: jal         0x804C3574
    // 0x804C35C8: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    func_804C3574(rdram, ctx);
        goto after_2;
    // 0x804C35C8: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    after_2:
    // 0x804C35CC: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x804C35D0: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(206, 0X13F0) << 16);
    // 0x804C35D4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804C35D8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804C35DC: addiu       $t8, $t8, 0x3E70
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(206, 0X13F0));
    // 0x804C35E0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804C35E4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804C35E8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804C35EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C35F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C35F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C35F8: jal         0x804C3618
    // 0x804C35FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C3618(rdram, ctx);
        goto after_3;
    // 0x804C35FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804C3600: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x804C3604: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C3608:
    // 0x804C3608: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C360C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C3610: jr          $ra
    // 0x804C3614: nop

    return;
    // 0x804C3614: nop

;}
RECOMP_FUNC void func_804BD600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD600: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD604: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD608: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BD60C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804BD610: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X3DD4) << 16);
    // 0x804BD614: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BD618: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BD61C: lw          $t8, -0x8FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(191, 0X3DD4));
    // 0x804BD620: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804BD624: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804BD628: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804BD62C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804BD630: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804BD634: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804BD638: beql        $v1, $zero, L_804BD66C
    if (ctx->r3 == 0) {
        // 0x804BD63C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD66C;
    }
    goto skip_0;
    // 0x804BD63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD640: jalr        $v1
    // 0x804BD644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804BD644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804BD64C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804BD650: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804BD654: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804BD658: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804BD65C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804BD660: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804BD664: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804BD668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD66C:
    // 0x804BD66C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BD670: jr          $ra
    // 0x804BD674: nop

    return;
    // 0x804BD674: nop

;}
RECOMP_FUNC void func_807165FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807165FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80716600: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80716604: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80716608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8071660C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80716610: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80716614: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80716618: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8071661C: addiu       $t6, $zero, 0x960
    ctx->r14 = ADD32(0, 0X960);
    // 0x80716620: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80716624: addiu       $a2, $zero, 0x3C0
    ctx->r6 = ADD32(0, 0X3C0);
    // 0x80716628: addiu       $a3, $zero, 0x744
    ctx->r7 = ADD32(0, 0X744);
    // 0x8071662C: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    // 0x80716630: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80716634: jal         0x8071637C
    // 0x80716638: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_8071637C(rdram, ctx);
        goto after_0;
    // 0x80716638: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8071663C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80716640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80716644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80716648: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8071664C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80716650: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80716654: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80716658: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8071665C: jr          $ra
    // 0x80716660: nop

    return;
    // 0x80716660: nop

;}
RECOMP_FUNC void func_804503B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804503B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804503B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804503BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804503C0: jal         0x80444408
    // 0x804503C4: addiu       $a1, $zero, 0x40F7
    ctx->r5 = ADD32(0, 0X40F7);
    func_80444408(rdram, ctx);
        goto after_0;
    // 0x804503C4: addiu       $a1, $zero, 0x40F7
    ctx->r5 = ADD32(0, 0X40F7);
    after_0:
    // 0x804503C8: bnel        $v0, $zero, L_804503DC
    if (ctx->r2 != 0) {
        // 0x804503CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804503DC;
    }
    goto skip_0;
    // 0x804503CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804503D0: jal         0x804455B0
    // 0x804503D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804455B0(rdram, ctx);
        goto after_1;
    // 0x804503D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804503D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804503DC:
    // 0x804503DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804503E0: jr          $ra
    // 0x804503E4: nop

    return;
    // 0x804503E4: nop

    // 0x804503E8: jr          $ra
    // 0x804503EC: nop

    return;
    // 0x804503EC: nop

    // 0x804503F0: jr          $ra
    // 0x804503F4: nop

    return;
    // 0x804503F4: nop

;}
RECOMP_FUNC void func_807B00B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B00B0: addiu       $v0, $a2, 0x4
    ctx->r2 = ADD32(ctx->r6, 0X4);
    // 0x807B00B4: beq         $a1, $zero, L_807B0168
    if (ctx->r5 == 0) {
        // 0x807B00B8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_807B0168;
    }
    // 0x807B00B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807B00BC: andi        $a3, $a1, 0x3
    ctx->r7 = ctx->r5 & 0X3;
    // 0x807B00C0: beq         $a3, $zero, L_807B00F8
    if (ctx->r7 == 0) {
        // 0x807B00C4: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_807B00F8;
    }
    // 0x807B00C4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_807B00C8:
    // 0x807B00C8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x807B00CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x807B00D0: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x807B00D4: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x807B00D8: lh          $t7, -0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X4);
    // 0x807B00DC: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x807B00E0: sh          $t7, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r15;
    // 0x807B00E4: lh          $t8, -0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X2);
    // 0x807B00E8: bne         $a2, $v1, L_807B00C8
    if (ctx->r6 != ctx->r3) {
        // 0x807B00EC: sh          $t8, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r24;
            goto L_807B00C8;
    }
    // 0x807B00EC: sh          $t8, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r24;
    // 0x807B00F0: beq         $v1, $a1, L_807B0168
    if (ctx->r3 == ctx->r5) {
        // 0x807B00F4: nop
    
            goto L_807B0168;
    }
    // 0x807B00F4: nop

L_807B00F8:
    // 0x807B00F8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x807B00FC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807B0100: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x807B0104: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x807B0108: lh          $t0, -0x16($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X16);
    // 0x807B010C: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    // 0x807B0110: sh          $t0, -0x16($a0)
    MEM_H(-0X16, ctx->r4) = ctx->r8;
    // 0x807B0114: lh          $t1, -0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X14);
    // 0x807B0118: sh          $t1, -0x14($a0)
    MEM_H(-0X14, ctx->r4) = ctx->r9;
    // 0x807B011C: lh          $t2, -0x12($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X12);
    // 0x807B0120: sh          $t2, -0x12($a0)
    MEM_H(-0X12, ctx->r4) = ctx->r10;
    // 0x807B0124: lh          $t3, -0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X10);
    // 0x807B0128: sh          $t3, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r11;
    // 0x807B012C: lh          $t4, -0xE($v0)
    ctx->r12 = MEM_H(ctx->r2, -0XE);
    // 0x807B0130: sh          $t4, -0xE($a0)
    MEM_H(-0XE, ctx->r4) = ctx->r12;
    // 0x807B0134: lh          $t5, -0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, -0XC);
    // 0x807B0138: sh          $t5, -0xC($a0)
    MEM_H(-0XC, ctx->r4) = ctx->r13;
    // 0x807B013C: lh          $t6, -0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, -0XA);
    // 0x807B0140: sh          $t6, -0xA($a0)
    MEM_H(-0XA, ctx->r4) = ctx->r14;
    // 0x807B0144: lh          $t7, -0x8($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X8);
    // 0x807B0148: sh          $t7, -0x8($a0)
    MEM_H(-0X8, ctx->r4) = ctx->r15;
    // 0x807B014C: lh          $t8, -0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X6);
    // 0x807B0150: sh          $t8, -0x6($a0)
    MEM_H(-0X6, ctx->r4) = ctx->r24;
    // 0x807B0154: lh          $t9, -0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X4);
    // 0x807B0158: sh          $t9, -0x4($a0)
    MEM_H(-0X4, ctx->r4) = ctx->r25;
    // 0x807B015C: lh          $t0, -0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X2);
    // 0x807B0160: bne         $v1, $a1, L_807B00F8
    if (ctx->r3 != ctx->r5) {
        // 0x807B0164: sh          $t0, -0x2($a0)
        MEM_H(-0X2, ctx->r4) = ctx->r8;
            goto L_807B00F8;
    }
    // 0x807B0164: sh          $t0, -0x2($a0)
    MEM_H(-0X2, ctx->r4) = ctx->r8;
L_807B0168:
    // 0x807B0168: jr          $ra
    // 0x807B016C: nop

    return;
    // 0x807B016C: nop

;}
RECOMP_FUNC void func_8079BA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079BA0C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079BA10: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8079BA14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079BA18: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8079BA1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079BA20: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079BA24: jal         0x8079B840
    // 0x8079BA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8079B840(rdram, ctx);
        goto after_0;
    // 0x8079BA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8079BA2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079BA30: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079BA34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8079BA38: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8079BA3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8079BA40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8079BA44: lwc1        $f10, 0x50($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X50);
    // 0x8079BA48: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8079BA4C: swc1        $f16, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f16.u32l;
    // 0x8079BA50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079BA54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079BA58: jr          $ra
    // 0x8079BA5C: nop

    return;
    // 0x8079BA5C: nop

;}
RECOMP_FUNC void func_804090B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804090B8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x804090BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804090C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804090C4: lui         $a3, 0x8041
    ctx->r7 = S32(RELOC_HI16(11, 0X2CA0) << 16);
    // 0x804090C8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x804090CC: jal         0x80408F40
    // 0x804090D0: addiu       $a3, $a3, -0x5990
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(11, 0X2CA0));
    func_80408F40(rdram, ctx);
        goto after_0;
    // 0x804090D0: addiu       $a3, $a3, -0x5990
    ctx->r7 = ADD32(ctx->r7, (int16_t)RELOC_LO16(11, 0X2CA0));
    after_0:
    // 0x804090D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804090D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804090DC: jr          $ra
    // 0x804090E0: nop

    return;
    // 0x804090E0: nop

;}
RECOMP_FUNC void func_805E0D08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E0D08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805E0D0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E0D10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E0D14: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805E0D18: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(483, 0X680) << 16);
    // 0x805E0D1C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805E0D20: addiu       $t6, $t6, 0x1310
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(483, 0X680));
    // 0x805E0D24: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805E0D28: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x805E0D2C: addiu       $at, $zero, 0x453A
    ctx->r1 = ADD32(0, 0X453A);
    // 0x805E0D30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E0D34: bne         $t8, $at, L_805E0D4C
    if (ctx->r24 != ctx->r1) {
        // 0x805E0D38: sh          $zero, 0x144($a0)
        MEM_H(0X144, ctx->r4) = 0;
            goto L_805E0D4C;
    }
    // 0x805E0D38: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x805E0D3C: jal         0x800653D8
    // 0x805E0D40: nop

    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805E0D40: nop

    after_0:
    // 0x805E0D44: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x805E0D48: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
L_805E0D4C:
    // 0x805E0D4C: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x805E0D50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x805E0D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E0D58: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x805E0D5C: jal         0x8005FCA8
    // 0x805E0D60: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    func_8005FCA8(rdram, ctx);
        goto after_1;
    // 0x805E0D60: sh          $t0, 0x12($t2)
    MEM_H(0X12, ctx->r10) = ctx->r8;
    after_1:
    // 0x805E0D64: jal         0x800653D8
    // 0x805E0D68: nop

    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x805E0D68: nop

    after_2:
    // 0x805E0D6C: andi        $t3, $v0, 0x7
    ctx->r11 = ctx->r2 & 0X7;
    // 0x805E0D70: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x805E0D74: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x805E0D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805E0D7C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805E0D80: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805E0D84: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x805E0D88: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x805E0D8C: addiu       $t5, $t5, -0x7C48
    ctx->r13 = ADD32(ctx->r13, -0X7C48);
    // 0x805E0D90: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805E0D94: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x805E0D98: sw          $t4, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r12;
    // 0x805E0D9C: sw          $t5, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r13;
    // 0x805E0DA0: jal         0x80048378
    // 0x805E0DA4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048378(rdram, ctx);
        goto after_3;
    // 0x805E0DA4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x805E0DA8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x805E0DAC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805E0DB0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x805E0DB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805E0DB8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6A0) << 16);
    // 0x805E0DBC: swc1        $f0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f0.u32l;
    // 0x805E0DC0: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
    // 0x805E0DC4: swc1        $f16, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f16.u32l;
    // 0x805E0DC8: lwc1        $f18, 0x1330($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6A0));
    // 0x805E0DCC: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(483, 0X6A4) << 16);
    // 0x805E0DD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E0DD4: swc1        $f18, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f18.u32l;
    // 0x805E0DD8: lwc1        $f4, 0x1334($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(483, 0X6A4));
    // 0x805E0DDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E0DE0: jal         0x805E11E0
    // 0x805E0DE4: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    func_805E11E0(rdram, ctx);
        goto after_4;
    // 0x805E0DE4: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    after_4:
    // 0x805E0DE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805E0DEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805E0DF0: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x805E0DF4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x805E0DF8: jal         0x80067BBC
    // 0x805E0DFC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x805E0DFC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x805E0E00: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x805E0E04: jal         0x80067818
    // 0x805E0E08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x805E0E08: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x805E0E0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E0E10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E0E14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805E0E18: jr          $ra
    // 0x805E0E1C: nop

    return;
    // 0x805E0E1C: nop

;}
RECOMP_FUNC void func_806F2C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2C80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806F2C84: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F2C88: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F2C8C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806F2C90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806F2C94: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806F2C98: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806F2C9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F2CA0: bnel        $v0, $at, L_806F2D44
    if (ctx->r2 != ctx->r1) {
        // 0x806F2CA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2D44;
    }
    goto skip_0;
    // 0x806F2CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F2CA8: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x806F2CAC: jal         0x8004816C
    // 0x806F2CB0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x806F2CB0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F2CB4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x806F2CB8: beq         $a1, $zero, L_806F2CC8
    if (ctx->r5 == 0) {
        // 0x806F2CBC: nop
    
            goto L_806F2CC8;
    }
    // 0x806F2CBC: nop

    // 0x806F2CC0: jal         0x800447C8
    // 0x806F2CC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806F2CC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_806F2CC8:
    // 0x806F2CC8: jal         0x8005FE48
    // 0x806F2CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806F2CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F2CD0: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806F2CD4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806F2CD8: addiu       $t8, $zero, 0x44
    ctx->r24 = ADD32(0, 0X44);
    // 0x806F2CDC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806F2CE0: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806F2CE4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BF4) << 16);
    // 0x806F2CE8: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    // 0x806F2CEC: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806F2CF0: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x806F2CF4: lwc1        $f4, 0x3174($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BF4));
    // 0x806F2CF8: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806F2CFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F2D00: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806F2D04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806F2D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F2D0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2D10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F2D14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806F2D18: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x806F2D1C: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x806F2D20: jal         0x806F2E38
    // 0x806F2D24: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    func_806F2E38(rdram, ctx);
        goto after_3;
    // 0x806F2D24: swc1        $f8, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x806F2D28: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806F2D2C: jal         0x80067BBC
    // 0x806F2D30: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x806F2D30: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_4:
    // 0x806F2D34: addiu       $a0, $zero, 0x280
    ctx->r4 = ADD32(0, 0X280);
    // 0x806F2D38: jal         0x80067818
    // 0x806F2D3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F2D3C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806F2D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2D44:
    // 0x806F2D44: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F2D48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806F2D4C: jr          $ra
    // 0x806F2D50: nop

    return;
    // 0x806F2D50: nop

;}
RECOMP_FUNC void func_8007524C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007524C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80075250: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80075254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80075258: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007525C: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80075260: addiu       $t7, $t7, -0x7B20
    ctx->r15 = ADD32(ctx->r15, -0X7B20);
    // 0x80075264: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80075268: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8007526C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075270: jal         0x8008B920
    // 0x80075274: sb          $t8, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80075274: sb          $t8, 0x24C($s0)
    MEM_B(0X24C, ctx->r16) = ctx->r24;
    after_0:
    // 0x80075278: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x8007527C: addiu       $t9, $t9, -0x7B18
    ctx->r25 = ADD32(ctx->r25, -0X7B18);
    // 0x80075280: sw          $v0, 0x250($s0)
    MEM_W(0X250, ctx->r16) = ctx->r2;
    // 0x80075284: sw          $v1, 0x254($s0)
    MEM_W(0X254, ctx->r16) = ctx->r3;
    // 0x80075288: sw          $v0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r2;
    // 0x8007528C: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x80075290: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80075294: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80075298: lw          $a1, -0x53BC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X53BC);
    // 0x8007529C: lw          $a0, -0x53C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X53C0);
    // 0x800752A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800752A4: jal         0x80082C88
    // 0x800752A8: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800752A8: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_1:
    // 0x800752AC: lui         $a1, 0x7
    ctx->r5 = S32(0X7 << 16);
    // 0x800752B0: ori         $a1, $a1, 0xA120
    ctx->r5 = ctx->r5 | 0XA120;
    // 0x800752B4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800752B8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800752BC: jal         0x80082D88
    // 0x800752C0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_2;
    // 0x800752C0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x800752C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800752C8: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800752CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800752D0: jal         0x80082C88
    // 0x800752D4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x800752D4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_3:
    // 0x800752D8: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800752DC: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x800752E0: addiu       $t2, $s0, 0x60
    ctx->r10 = ADD32(ctx->r16, 0X60);
    // 0x800752E4: addiu       $t3, $zero, 0x29E
    ctx->r11 = ADD32(0, 0X29E);
    // 0x800752E8: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x800752EC: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800752F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800752F4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800752F8: addiu       $a0, $s0, 0x258
    ctx->r4 = ADD32(ctx->r16, 0X258);
    // 0x800752FC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80075300: jal         0x8008F6D0
    // 0x80075304: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    osSetTimer_recomp(rdram, ctx);
        goto after_4;
    // 0x80075304: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_4:
    // 0x80075308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007530C: jal         0x800751FC
    // 0x80075310: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    func_800751FC(rdram, ctx);
        goto after_5;
    // 0x80075310: addiu       $a1, $s0, 0x20
    ctx->r5 = ADD32(ctx->r16, 0X20);
    after_5:
    // 0x80075314: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80075318: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007531C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80075320: jr          $ra
    // 0x80075324: nop

    return;
    // 0x80075324: nop

;}
RECOMP_FUNC void func_805AD974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AD974: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805AD978: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AD97C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805AD980: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805AD984: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805AD988: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805AD98C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805AD990: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805AD994: addiu       $t6, $zero, 0x1C98
    ctx->r14 = ADD32(0, 0X1C98);
    // 0x805AD998: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x805AD99C: addiu       $a2, $zero, 0x168
    ctx->r6 = ADD32(0, 0X168);
    // 0x805AD9A0: addiu       $a3, $zero, 0x1B6C
    ctx->r7 = ADD32(0, 0X1B6C);
    // 0x805AD9A4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x805AD9A8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x805AD9AC: jal         0x805AD70C
    // 0x805AD9B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_805AD70C(rdram, ctx);
        goto after_0;
    // 0x805AD9B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805AD9B4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x805AD9B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805AD9BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805AD9C0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x805AD9C4: swc1        $f2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f2.u32l;
    // 0x805AD9C8: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x805AD9CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805AD9D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805AD9D4: jr          $ra
    // 0x805AD9D8: nop

    return;
    // 0x805AD9D8: nop

;}
RECOMP_FUNC void func_8042CF18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042CF18: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8042CF1C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8042CF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8042CF24: blez        $t6, L_8042CF8C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8042CF28: addiu       $t3, $zero, 0xA0
        ctx->r11 = ADD32(0, 0XA0);
            goto L_8042CF8C;
    }
    // 0x8042CF28: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x8042CF2C: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
L_8042CF30:
    // 0x8042CF30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8042CF34: sll         $a3, $v1, 4
    ctx->r7 = S32(ctx->r3 << 4);
    // 0x8042CF38: blez        $t7, L_8042CF78
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8042CF3C: or          $t2, $a0, $zero
        ctx->r10 = ctx->r4 | 0;
            goto L_8042CF78;
    }
    // 0x8042CF3C: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8042CF40: lw          $a2, 0x20($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X20);
L_8042CF44:
    // 0x8042CF44: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8042CF48: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8042CF4C: addu        $t0, $a2, $a3
    ctx->r8 = ADD32(ctx->r6, ctx->r7);
    // 0x8042CF50: sb          $t3, 0xE($t0)
    MEM_B(0XE, ctx->r8) = ctx->r11;
    // 0x8042CF54: sb          $t3, 0xD($t0)
    MEM_B(0XD, ctx->r8) = ctx->r11;
    // 0x8042CF58: sb          $t3, 0xC($t0)
    MEM_B(0XC, ctx->r8) = ctx->r11;
    // 0x8042CF5C: sb          $t3, 0x1E($t0)
    MEM_B(0X1E, ctx->r8) = ctx->r11;
    // 0x8042CF60: sb          $t3, 0x1D($t0)
    MEM_B(0X1D, ctx->r8) = ctx->r11;
    // 0x8042CF64: sb          $t3, 0x1C($t0)
    MEM_B(0X1C, ctx->r8) = ctx->r11;
    // 0x8042CF68: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    // 0x8042CF6C: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8042CF70: bnel        $at, $zero, L_8042CF44
    if (ctx->r1 != 0) {
        // 0x8042CF74: lw          $a2, 0x20($t2)
        ctx->r6 = MEM_W(ctx->r10, 0X20);
            goto L_8042CF44;
    }
    goto skip_0;
    // 0x8042CF74: lw          $a2, 0x20($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X20);
    skip_0:
L_8042CF78:
    // 0x8042CF78: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8042CF7C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8042CF80: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8042CF84: bnel        $at, $zero, L_8042CF30
    if (ctx->r1 != 0) {
        // 0x8042CF88: lw          $t7, 0x34($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X34);
            goto L_8042CF30;
    }
    goto skip_1;
    // 0x8042CF88: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    skip_1:
L_8042CF8C:
    // 0x8042CF8C: jr          $ra
    // 0x8042CF90: nop

    return;
    // 0x8042CF90: nop

;}
RECOMP_FUNC void func_8042F6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F6B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F6B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F6BC: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042F6C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042F6C4: beq         $t6, $zero, L_8042F700
    if (ctx->r14 == 0) {
        // 0x8042F6C8: nop
    
            goto L_8042F700;
    }
    // 0x8042F6C8: nop

    // 0x8042F6CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042F6D0: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042F6D4: jalr        $t9
    // 0x8042F6D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042F6D8: nop

    after_0:
    // 0x8042F6DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042F6E0: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042F6E4: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042F6E8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042F6EC: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042F6F0: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042F6F4: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042F6F8: b           L_8042F700
    // 0x8042F6FC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042F700;
    // 0x8042F6FC: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042F700:
    // 0x8042F700: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042F704: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F708: jr          $ra
    // 0x8042F70C: nop

    return;
    // 0x8042F70C: nop

;}
RECOMP_FUNC void func_805DA7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DA7B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805DA7BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805DA7C0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805DA7C4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805DA7C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805DA7CC: jal         0x805DA4E0
    // 0x805DA7D0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805DA4E0(rdram, ctx);
        goto after_0;
    // 0x805DA7D0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805DA7D4: bnel        $v0, $zero, L_805DA814
    if (ctx->r2 != 0) {
        // 0x805DA7D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA814;
    }
    goto skip_0;
    // 0x805DA7D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805DA7DC: jal         0x805DA464
    // 0x805DA7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805DA464(rdram, ctx);
        goto after_1;
    // 0x805DA7E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805DA7E4: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x805DA7E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805DA7EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805DA7F0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805DA7F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x805DA7F8: bnel        $t8, $zero, L_805DA814
    if (ctx->r24 != 0) {
        // 0x805DA7FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805DA814;
    }
    goto skip_1;
    // 0x805DA7FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805DA800: jal         0x805DAA20
    // 0x805DA804: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_805DAA20(rdram, ctx);
        goto after_2;
    // 0x805DA804: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x805DA808: addiu       $t9, $zero, 0x14A
    ctx->r25 = ADD32(0, 0X14A);
    // 0x805DA80C: sw          $t9, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r25;
    // 0x805DA810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805DA814:
    // 0x805DA814: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805DA818: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805DA81C: jr          $ra
    // 0x805DA820: nop

    return;
    // 0x805DA820: nop

;}
RECOMP_FUNC void func_804E9F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9F9C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804E9FA0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804E9FA4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804E9FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9FAC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804E9FB0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804E9FB4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804E9FB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804E9FBC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804E9FC0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804E9FC4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804E9FC8: lui         $t2, 0x804F
    ctx->r10 = S32(RELOC_HI16(264, 0X804) << 16);
    // 0x804E9FCC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804E9FD0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804E9FD4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804E9FD8: lw          $t2, -0x5E8C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(264, 0X804));
    // 0x804E9FDC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804E9FE0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804E9FE4: jal         0x804E9B7C
    // 0x804E9FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804E9B7C(rdram, ctx);
        goto after_0;
    // 0x804E9FE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E9FEC: jal         0x804E9BD8
    // 0x804E9FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804E9BD8(rdram, ctx);
        goto after_1;
    // 0x804E9FF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804E9FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804E9FF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9FFC: jr          $ra
    // 0x804EA000: nop

    return;
    // 0x804EA000: nop

;}
RECOMP_FUNC void func_80475E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475E38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475E3C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475E40: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475E44: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475E48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475E4C: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E18) << 16);
    // 0x80475E50: addiu       $a2, $a2, -0x4A28
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E18));
    // 0x80475E54: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80475E58: jal         0x80475B40
    // 0x80475E5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475E5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475E60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475E64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475E68: jr          $ra
    // 0x80475E6C: nop

    return;
    // 0x80475E6C: nop

;}
RECOMP_FUNC void func_80046DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046DC8: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80046DCC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80046DD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80046DD4: bne         $t6, $t7, L_80046DE4
    if (ctx->r14 != ctx->r15) {
        // 0x80046DD8: nop
    
            goto L_80046DE4;
    }
    // 0x80046DD8: nop

    // 0x80046DDC: jr          $ra
    // 0x80046DE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80046DE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80046DE4:
    // 0x80046DE4: jr          $ra
    // 0x80046DE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80046DE8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80680540(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680540: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680544: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80680548: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X2234) << 16);
    // 0x8068054C: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80680550: lwc1        $f10, 0x2644($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X2234));
    // 0x80680554: lwc1        $f18, 0xE0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XE0);
    // 0x80680558: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8068055C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80680560: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80680564: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80680568: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8068056C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x80680570: nop

    // 0x80680574: bc1f        L_8068059C
    if (!c1cs) {
        // 0x80680578: add.s       $f2, $f16, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f0.fl;
            goto L_8068059C;
    }
    // 0x80680578: add.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8068057C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80680580: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80680584: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80680588: nop

    // 0x8068058C: bc1f        L_806805B4
    if (!c1cs) {
        // 0x80680590: nop
    
            goto L_806805B4;
    }
    // 0x80680590: nop

    // 0x80680594: b           L_806805B4
    // 0x80680598: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_806805B4;
    // 0x80680598: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8068059C:
    // 0x8068059C: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x806805A0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x806805A4: nop

    // 0x806805A8: bc1f        L_806805B4
    if (!c1cs) {
        // 0x806805AC: nop
    
            goto L_806805B4;
    }
    // 0x806805AC: nop

    // 0x806805B0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_806805B4:
    // 0x806805B4: jr          $ra
    // 0x806805B8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
    return;
    // 0x806805B8: swc1        $f2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f2.u32l;
;}
RECOMP_FUNC void func_806B2C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2C1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B2C20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x806B2C24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B2C28: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B2C2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806B2C30: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806B2C34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x806B2C38: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x806B2C3C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x806B2C40: addiu       $t6, $zero, 0xA50
    ctx->r14 = ADD32(0, 0XA50);
    // 0x806B2C44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806B2C48: addiu       $a2, $zero, 0x744
    ctx->r6 = ADD32(0, 0X744);
    // 0x806B2C4C: addiu       $a3, $zero, 0x8E8
    ctx->r7 = ADD32(0, 0X8E8);
    // 0x806B2C50: addiu       $a1, $zero, 0x690
    ctx->r5 = ADD32(0, 0X690);
    // 0x806B2C54: jal         0x806B1BC4
    // 0x806B2C58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_806B1BC4(rdram, ctx);
        goto after_0;
    // 0x806B2C58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x806B2C5C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x806B2C60: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(601, 0X19088) << 16);
    // 0x806B2C64: lui         $a2, 0x806D
    ctx->r6 = S32(RELOC_HI16(601, 0X19074) << 16);
    // 0x806B2C68: swc1        $f0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f0.u32l;
    // 0x806B2C6C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806B2C70: addiu       $a2, $a2, -0x563C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(601, 0X19074));
    // 0x806B2C74: addiu       $a1, $a1, -0x5628
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(601, 0X19088));
    // 0x806B2C78: jal         0x806B1A18
    // 0x806B2C7C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_806B1A18(rdram, ctx);
        goto after_1;
    // 0x806B2C7C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x806B2C80: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x806B2C84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806B2C88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806B2C8C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806B2C90: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806B2C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806B2C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B2C9C: jr          $ra
    // 0x806B2CA0: nop

    return;
    // 0x806B2CA0: nop

;}
RECOMP_FUNC void func_804A0070(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A0070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A0074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A0078: lwc1        $f0, 0x7C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x804A007C: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x804A0080: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x804A0084: jal         0x80062684
    // 0x804A0088: nop

    func_80062684(rdram, ctx);
        goto after_0;
    // 0x804A0088: nop

    after_0:
    // 0x804A008C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A0090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A0094: jr          $ra
    // 0x804A0098: nop

    return;
    // 0x804A0098: nop

;}
RECOMP_FUNC void func_80452D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452D80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452D84: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452D88: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452D8C: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452D90: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452D94: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452D98: ori         $at, $at, 0x6DDC
    ctx->r1 = ctx->r1 | 0X6DDC;
    // 0x80452D9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80452DA0: jal         0x80452A64
    // 0x80452DA4: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    func_80452A64(rdram, ctx);
        goto after_0;
    // 0x80452DA4: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    after_0:
    // 0x80452DA8: bne         $v0, $zero, L_80452DC0
    if (ctx->r2 != 0) {
        // 0x80452DAC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80452DC0;
    }
    // 0x80452DAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80452DB0: jal         0x80452A14
    // 0x80452DB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80452A14(rdram, ctx);
        goto after_1;
    // 0x80452DB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80452DB8: b           L_80452DCC
    // 0x80452DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80452DCC;
    // 0x80452DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452DC0:
    // 0x80452DC0: jal         0x80452744
    // 0x80452DC4: nop

    func_80452744(rdram, ctx);
        goto after_2;
    // 0x80452DC4: nop

    after_2:
    // 0x80452DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80452DCC:
    // 0x80452DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452DD0: jr          $ra
    // 0x80452DD4: nop

    return;
    // 0x80452DD4: nop

;}
RECOMP_FUNC void func_807A1AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A1AE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x807A1AEC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x807A1AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A1AF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x807A1AF8: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x807A1AFC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x807A1B00: lui         $t9, 0x807A
    ctx->r25 = S32(RELOC_HI16(841, 0XD74) << 16);
    // 0x807A1B04: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A1B08: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807A1B0C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x807A1B10: lw          $t9, 0x1CB4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(841, 0XD74));
    // 0x807A1B14: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x807A1B18: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807A1B1C: jal         0x807A0FB0
    // 0x807A1B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807A0FB0(rdram, ctx);
        goto after_0;
    // 0x807A1B20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807A1B24: jal         0x807A1144
    // 0x807A1B28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_807A1144(rdram, ctx);
        goto after_1;
    // 0x807A1B28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x807A1B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A1B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A1B34: jr          $ra
    // 0x807A1B38: nop

    return;
    // 0x807A1B38: nop

    // 0x807A1B3C: nop

;}
RECOMP_FUNC void func_804752D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804752D0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804752D4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804752D8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804752DC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804752E0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804752E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804752E8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804752EC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804752F0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804752F4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804752F8: jr          $ra
    // 0x804752FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804752FC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807B2B4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B2B4C: addiu       $sp, $sp, -0x260
    ctx->r29 = ADD32(ctx->r29, -0X260);
    // 0x807B2B50: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(871, 0X36B8) << 16);
    // 0x807B2B54: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x807B2B58: addiu       $t6, $t6, 0x3208
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(871, 0X36B8));
    // 0x807B2B5C: addiu       $t0, $sp, 0x4
    ctx->r8 = ADD32(ctx->r29, 0X4);
    // 0x807B2B60: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x807B2B64: addiu       $t1, $t6, 0x210
    ctx->r9 = ADD32(ctx->r14, 0X210);
    // 0x807B2B68: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
L_807B2B6C:
    // 0x807B2B6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x807B2B70: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x807B2B74: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x807B2B78: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x807B2B7C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x807B2B80: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x807B2B84: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x807B2B88: bne         $t6, $t1, L_807B2B6C
    if (ctx->r14 != ctx->r9) {
        // 0x807B2B8C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_807B2B6C;
    }
    // 0x807B2B8C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x807B2B90: lui         $t2, 0x807B
    ctx->r10 = S32(RELOC_HI16(871, 0X38C8) << 16);
    // 0x807B2B94: addiu       $t2, $t2, 0x3418
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(871, 0X38C8));
    // 0x807B2B98: addiu       $t1, $t2, 0x3C
    ctx->r9 = ADD32(ctx->r10, 0X3C);
    // 0x807B2B9C: or          $t5, $t0, $zero
    ctx->r13 = ctx->r8 | 0;
L_807B2BA0:
    // 0x807B2BA0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x807B2BA4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x807B2BA8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x807B2BAC: sw          $t4, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r12;
    // 0x807B2BB0: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x807B2BB4: sw          $t3, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r11;
    // 0x807B2BB8: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x807B2BBC: bne         $t2, $t1, L_807B2BA0
    if (ctx->r10 != ctx->r9) {
        // 0x807B2BC0: sw          $t4, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r12;
            goto L_807B2BA0;
    }
    // 0x807B2BC0: sw          $t4, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r12;
    // 0x807B2BC4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x807B2BC8: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
    // 0x807B2BCC: or          $v1, $sp, $zero
    ctx->r3 = ctx->r29 | 0;
    // 0x807B2BD0: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x807B2BD4: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x807B2BD8: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x807B2BDC: addiu       $v0, $v0, 0x5C
    ctx->r2 = ADD32(ctx->r2, 0X5C);
    // 0x807B2BE0: sh          $t4, 0x4($t5)
    MEM_H(0X4, ctx->r13) = ctx->r12;
    // 0x807B2BE4: lh          $t6, 0x4C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4C);
    // 0x807B2BE8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x807B2BEC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x807B2BF0: sh          $t6, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r14;
    // 0x807B2BF4: lh          $t9, 0x4E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X4E);
    // 0x807B2BF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x807B2BFC: addiu       $a3, $zero, 0x42
    ctx->r7 = ADD32(0, 0X42);
    // 0x807B2C00: sh          $t9, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r25;
    // 0x807B2C04: lh          $t7, 0x50($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X50);
    // 0x807B2C08: sh          $t7, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r15;
    // 0x807B2C0C: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x807B2C10: sh          $t8, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = ctx->r24;
    // 0x807B2C14: lbu         $t1, 0x4($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X4);
    // 0x807B2C18: sb          $t1, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r9;
    // 0x807B2C1C: lh          $t2, -0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X8);
    // 0x807B2C20: sh          $t2, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r10;
    // 0x807B2C24: lh          $t5, -0x6($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X6);
    // 0x807B2C28: sh          $t5, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r13;
    // 0x807B2C2C: lh          $t3, -0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X4);
    // 0x807B2C30: sh          $t3, -0x4($a2)
    MEM_H(-0X4, ctx->r6) = ctx->r11;
    // 0x807B2C34: lh          $t4, -0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X2);
    // 0x807B2C38: sh          $t4, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r12;
    // 0x807B2C3C: lbu         $t6, -0x1($v1)
    ctx->r14 = MEM_BU(ctx->r3, -0X1);
    // 0x807B2C40: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
L_807B2C44:
    // 0x807B2C44: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x807B2C48: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807B2C4C: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x807B2C50: sh          $t9, -0x20($a2)
    MEM_H(-0X20, ctx->r6) = ctx->r25;
    // 0x807B2C54: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x807B2C58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x807B2C5C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x807B2C60: sh          $t7, -0x1E($a2)
    MEM_H(-0X1E, ctx->r6) = ctx->r15;
    // 0x807B2C64: lh          $t8, -0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X1C);
    // 0x807B2C68: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807B2C6C: sh          $t8, -0x1C($a2)
    MEM_H(-0X1C, ctx->r6) = ctx->r24;
    // 0x807B2C70: lh          $t1, -0x1A($v0)
    ctx->r9 = MEM_H(ctx->r2, -0X1A);
    // 0x807B2C74: sh          $t1, -0x1A($a2)
    MEM_H(-0X1A, ctx->r6) = ctx->r9;
    // 0x807B2C78: lbu         $t2, -0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, -0X4);
    // 0x807B2C7C: sb          $t2, -0x4($a1)
    MEM_B(-0X4, ctx->r5) = ctx->r10;
    // 0x807B2C80: lh          $t5, -0x18($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X18);
    // 0x807B2C84: sh          $t5, -0x18($a2)
    MEM_H(-0X18, ctx->r6) = ctx->r13;
    // 0x807B2C88: lh          $t3, -0x16($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X16);
    // 0x807B2C8C: sh          $t3, -0x16($a2)
    MEM_H(-0X16, ctx->r6) = ctx->r11;
    // 0x807B2C90: lh          $t4, -0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X14);
    // 0x807B2C94: sh          $t4, -0x14($a2)
    MEM_H(-0X14, ctx->r6) = ctx->r12;
    // 0x807B2C98: lh          $t6, -0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X12);
    // 0x807B2C9C: sh          $t6, -0x12($a2)
    MEM_H(-0X12, ctx->r6) = ctx->r14;
    // 0x807B2CA0: lbu         $t9, -0x3($v1)
    ctx->r25 = MEM_BU(ctx->r3, -0X3);
    // 0x807B2CA4: sb          $t9, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r25;
    // 0x807B2CA8: lh          $t7, -0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, -0X10);
    // 0x807B2CAC: sh          $t7, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r15;
    // 0x807B2CB0: lh          $t8, -0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XE);
    // 0x807B2CB4: sh          $t8, -0xE($a2)
    MEM_H(-0XE, ctx->r6) = ctx->r24;
    // 0x807B2CB8: lh          $t1, -0xC($v0)
    ctx->r9 = MEM_H(ctx->r2, -0XC);
    // 0x807B2CBC: sh          $t1, -0xC($a2)
    MEM_H(-0XC, ctx->r6) = ctx->r9;
    // 0x807B2CC0: lh          $t2, -0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, -0XA);
    // 0x807B2CC4: sh          $t2, -0xA($a2)
    MEM_H(-0XA, ctx->r6) = ctx->r10;
    // 0x807B2CC8: lbu         $t5, -0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, -0X2);
    // 0x807B2CCC: sb          $t5, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r13;
    // 0x807B2CD0: lh          $t3, -0x8($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X8);
    // 0x807B2CD4: sh          $t3, -0x8($a2)
    MEM_H(-0X8, ctx->r6) = ctx->r11;
    // 0x807B2CD8: lh          $t4, -0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X6);
    // 0x807B2CDC: sh          $t4, -0x6($a2)
    MEM_H(-0X6, ctx->r6) = ctx->r12;
    // 0x807B2CE0: lh          $t6, -0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X4);
    // 0x807B2CE4: sh          $t6, -0x4($a2)
    MEM_H(-0X4, ctx->r6) = ctx->r14;
    // 0x807B2CE8: lh          $t9, -0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X2);
    // 0x807B2CEC: sh          $t9, -0x2($a2)
    MEM_H(-0X2, ctx->r6) = ctx->r25;
    // 0x807B2CF0: lbu         $t7, -0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, -0X1);
    // 0x807B2CF4: bne         $a0, $a3, L_807B2C44
    if (ctx->r4 != ctx->r7) {
        // 0x807B2CF8: sb          $t7, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r15;
            goto L_807B2C44;
    }
    // 0x807B2CF8: sb          $t7, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r15;
    // 0x807B2CFC: jr          $ra
    // 0x807B2D00: addiu       $sp, $sp, 0x260
    ctx->r29 = ADD32(ctx->r29, 0X260);
    return;
    // 0x807B2D00: addiu       $sp, $sp, 0x260
    ctx->r29 = ADD32(ctx->r29, 0X260);
;}
RECOMP_FUNC void func_80532CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80532CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532D04: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x80532D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80532D0C: beq         $t6, $zero, L_80532D48
    if (ctx->r14 == 0) {
        // 0x80532D10: nop
    
            goto L_80532D48;
    }
    // 0x80532D10: nop

    // 0x80532D14: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80532D18: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x80532D1C: jalr        $t9
    // 0x80532D20: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80532D20: nop

    after_0:
    // 0x80532D24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80532D28: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x80532D2C: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x80532D30: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80532D34: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80532D38: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80532D3C: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x80532D40: b           L_80532D48
    // 0x80532D44: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_80532D48;
    // 0x80532D44: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_80532D48:
    // 0x80532D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532D4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532D50: jr          $ra
    // 0x80532D54: nop

    return;
    // 0x80532D54: nop

;}
RECOMP_FUNC void func_8040AB70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040AB70: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8040AB74: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(14, 0X4C0) << 16);
    // 0x8040AB78: addiu       $t6, $t6, -0x4FE0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(14, 0X4C0));
    // 0x8040AB7C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8040AB80: jr          $ra
    // 0x8040AB84: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8040AB84: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8078D138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D138: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078D13C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078D140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078D144: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8078D148: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8078D14C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078D150: bne         $a1, $at, L_8078D178
    if (ctx->r5 != ctx->r1) {
        // 0x8078D154: nop
    
            goto L_8078D178;
    }
    // 0x8078D154: nop

    // 0x8078D158: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x8078D15C: jal         0x80067BBC
    // 0x8078D160: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8078D160: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_0:
    // 0x8078D164: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D168: jal         0x80067F78
    // 0x8078D16C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x8078D16C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8078D170: b           L_8078D1D0
    // 0x8078D174: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8078D1D0;
    // 0x8078D174: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_8078D178:
    // 0x8078D178: jal         0x80067930
    // 0x8078D17C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x8078D17C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    after_2:
    // 0x8078D180: beq         $v0, $zero, L_8078D1B4
    if (ctx->r2 == 0) {
        // 0x8078D184: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8078D1B4;
    }
    // 0x8078D184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078D188: bnel        $v0, $at, L_8078D1D4
    if (ctx->r2 != ctx->r1) {
        // 0x8078D18C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8078D1D4;
    }
    goto skip_0;
    // 0x8078D18C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8078D190: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8078D194: jal         0x80067BBC
    // 0x8078D198: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8078D198: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8078D19C: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D1A0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8078D1A4: jal         0x800678F0
    // 0x8078D1A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8078D1A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8078D1AC: b           L_8078D1D4
    // 0x8078D1B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8078D1D4;
    // 0x8078D1B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D1B4:
    // 0x8078D1B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8078D1B8: jal         0x80067BBC
    // 0x8078D1BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x8078D1BC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8078D1C0: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D1C4: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8078D1C8: jal         0x80067838
    // 0x8078D1CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_6;
    // 0x8078D1CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
L_8078D1D0:
    // 0x8078D1D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8078D1D4:
    // 0x8078D1D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078D1D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078D1DC: jr          $ra
    // 0x8078D1E0: nop

    return;
    // 0x8078D1E0: nop

;}
RECOMP_FUNC void func_8003EA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EA1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003EA20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003EA24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003EA28: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8003EA2C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003EA30: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8003EA34: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8003EA38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003EA3C: jal         0x8005FE48
    // 0x8003EA40: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8003EA40: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003EA44: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8003EA48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003EA4C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003EA50: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x8003EA54: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003EA58: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x8003EA5C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003EA60: jal         0x8004816C
    // 0x8003EA64: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8003EA64: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    after_1:
    // 0x8003EA68: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8003EA6C: jal         0x80065490
    // 0x8003EA70: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003EA70: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_2:
    // 0x8003EA74: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x8003EA78: addiu       $t0, $t0, -0x71F4
    ctx->r8 = ADD32(ctx->r8, -0X71F4);
    // 0x8003EA7C: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x8003EA80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EA84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003EA88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003EA8C: jr          $ra
    // 0x8003EA90: nop

    return;
    // 0x8003EA90: nop

;}
RECOMP_FUNC void func_8003EB2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EB2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EB30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EB34: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8003EB38: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8003EB3C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8003EB40: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8003EB44: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003EB48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003EB4C: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x8003EB50: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003EB54: sh          $t8, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r24;
    // 0x8003EB58: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003EB5C: sh          $zero, 0x14($t0)
    MEM_H(0X14, ctx->r8) = 0;
    // 0x8003EB60: jal         0x8005FDC4
    // 0x8003EB64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FDC4(rdram, ctx);
        goto after_0;
    // 0x8003EB64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003EB68: jal         0x8004816C
    // 0x8003EB6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8003EB6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8003EB70: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8003EB74: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    // 0x8003EB78: jal         0x80065490
    // 0x8003EB7C: addiu       $a1, $a2, 0x84
    ctx->r5 = ADD32(ctx->r6, 0X84);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003EB7C: addiu       $a1, $a2, 0x84
    ctx->r5 = ADD32(ctx->r6, 0X84);
    after_2:
    // 0x8003EB80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003EB84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003EB88: jr          $ra
    // 0x8003EB8C: nop

    return;
    // 0x8003EB8C: nop

;}
RECOMP_FUNC void func_805D1570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1570: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D1574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D1578: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805D157C: jal         0x80045A34
    // 0x805D1580: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x805D1580: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x805D1584: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x805D1588: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805D158C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x805D1590: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x805D1594: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805D1598: jal         0x800657CC
    // 0x805D159C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x805D159C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x805D15A0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x805D15A4: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x805D15A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D15AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D15B0: jr          $ra
    // 0x805D15B4: nop

    return;
    // 0x805D15B4: nop

;}
RECOMP_FUNC void func_8070D090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070D090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8070D094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070D098: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8070D09C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8070D0A0: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8070D0A4: lui         $t8, 0x8071
    ctx->r24 = S32(RELOC_HI16(721, 0XC9C) << 16);
    // 0x8070D0A8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8070D0AC: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8070D0B0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8070D0B4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8070D0B8: lw          $t8, -0x2CD4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(721, 0XC9C));
    // 0x8070D0BC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8070D0C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8070D0C4: jal         0x80048490
    // 0x8070D0C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8070D0C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8070D0CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070D0D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8070D0D4: jr          $ra
    // 0x8070D0D8: nop

    return;
    // 0x8070D0D8: nop

;}
RECOMP_FUNC void func_800278A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800278A0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800278A4: lwc1        $f0, -0x7678($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x800278A8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800278AC: lwc1        $f4, -0x264($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X264);
    // 0x800278B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800278B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800278B8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800278BC: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x800278C0: bc1fl       L_800278D4
    if (!c1cs) {
        // 0x800278C4: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800278D4;
    }
    goto skip_0;
    // 0x800278C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x800278C8: b           L_800278F0
    // 0x800278CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800278F0;
    // 0x800278CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800278D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800278D4:
    // 0x800278D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800278D8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800278DC: nop

    // 0x800278E0: bc1f        L_800278F0
    if (!c1cs) {
        // 0x800278E4: nop
    
            goto L_800278F0;
    }
    // 0x800278E4: nop

    // 0x800278E8: b           L_800278F0
    // 0x800278EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800278F0;
    // 0x800278EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800278F0:
    // 0x800278F0: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x800278F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800278F8: sw          $v0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r2;
    // 0x800278FC: lwc1        $f8, -0x260($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X260);
    // 0x80027900: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80027904: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80027908: nop

    // 0x8002790C: bc1t        L_80027944
    if (c1cs) {
        // 0x80027910: nop
    
            goto L_80027944;
    }
    // 0x80027910: nop

    // 0x80027914: lwc1        $f10, -0x25C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25C);
    // 0x80027918: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002791C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80027920: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80027924: addiu       $t8, $t8, 0x7820
    ctx->r24 = ADD32(ctx->r24, 0X7820);
    // 0x80027928: bc1t        L_80027944
    if (c1cs) {
        // 0x8002792C: nop
    
            goto L_80027944;
    }
    // 0x8002792C: nop

    // 0x80027930: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80027934: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80027938: sb          $t7, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r15;
    // 0x8002793C: b           L_80027958
    // 0x80027940: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
        goto L_80027958;
    // 0x80027940: sw          $t8, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r24;
L_80027944:
    // 0x80027944: jal         0x800247E4
    // 0x80027948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800247E4(rdram, ctx);
        goto after_0;
    // 0x80027948: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002794C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80027950: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80027954: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
L_80027958:
    // 0x80027958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002795C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80027960: jr          $ra
    // 0x80027964: nop

    return;
    // 0x80027964: nop

;}
RECOMP_FUNC void func_807C4060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C4060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C4064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C4068: lbu         $t6, 0x165($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X165);
    // 0x807C406C: bnel        $t6, $zero, L_807C4084
    if (ctx->r14 != 0) {
        // 0x807C4070: lw          $v0, 0x1E0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1E0);
            goto L_807C4084;
    }
    goto skip_0;
    // 0x807C4070: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    skip_0:
    // 0x807C4074: jal         0x807C3F00
    // 0x807C4078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_807C3F00(rdram, ctx);
        goto after_0;
    // 0x807C4078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807C407C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807C4080: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
L_807C4084:
    // 0x807C4084: beq         $v0, $zero, L_807C4094
    if (ctx->r2 == 0) {
        // 0x807C4088: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_807C4094;
    }
    // 0x807C4088: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x807C408C: b           L_807C40B8
    // 0x807C4090: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
        goto L_807C40B8;
    // 0x807C4090: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
L_807C4094:
    // 0x807C4094: lh          $t8, 0x144($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X144);
    // 0x807C4098: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x807C409C: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    // 0x807C40A0: lh          $t0, 0x144($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X144);
    // 0x807C40A4: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x807C40A8: bnel        $at, $zero, L_807C40B8
    if (ctx->r1 != 0) {
        // 0x807C40AC: sw          $zero, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = 0;
            goto L_807C40B8;
    }
    goto skip_1;
    // 0x807C40AC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    skip_1:
    // 0x807C40B0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807C40B4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
L_807C40B8:
    // 0x807C40B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C40BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C40C0: jr          $ra
    // 0x807C40C4: nop

    return;
    // 0x807C40C4: nop

;}
RECOMP_FUNC void func_804B6CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6CE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B6CE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804B6CEC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804B6CF0: andi        $s0, $a1, 0xFFFF
    ctx->r16 = ctx->r5 & 0XFFFF;
    // 0x804B6CF4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x804B6CF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6CFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804B6D00: jal         0x80047090
    // 0x804B6D04: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804B6D04: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    after_0:
    // 0x804B6D08: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804B6D0C: bne         $v0, $at, L_804B6D1C
    if (ctx->r2 != ctx->r1) {
        // 0x804B6D10: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804B6D1C;
    }
    // 0x804B6D10: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804B6D14: b           L_804B6DDC
    // 0x804B6D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B6DDC;
    // 0x804B6D18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B6D1C:
    // 0x804B6D1C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x804B6D20: lw          $a1, 0x3C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X3C);
    // 0x804B6D24: lw          $a2, 0x40($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X40);
    // 0x804B6D28: lw          $a3, 0x44($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X44);
    // 0x804B6D2C: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // 0x804B6D30: jal         0x8004613C
    // 0x804B6D34: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804B6D34: ori         $a0, $a0, 0x2000
    ctx->r4 = ctx->r4 | 0X2000;
    after_1:
    // 0x804B6D38: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x804B6D3C: bne         $v0, $zero, L_804B6D4C
    if (ctx->r2 != 0) {
        // 0x804B6D40: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804B6D4C;
    }
    // 0x804B6D40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804B6D44: b           L_804B6DDC
    // 0x804B6D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B6DDC;
    // 0x804B6D48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B6D4C:
    // 0x804B6D4C: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x804B6D50: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x804B6D54: sw          $s1, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r17;
    // 0x804B6D58: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804B6D5C: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804B6D60: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x804B6D64: jal         0x80044194
    // 0x804B6D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804B6D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804B6D6C: jal         0x8005FDC4
    // 0x804B6D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_3;
    // 0x804B6D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B6D74: jal         0x8005FE48
    // 0x804B6D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FE48(rdram, ctx);
        goto after_4;
    // 0x804B6D78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x804B6D7C: lw          $t1, 0x174($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X174);
    // 0x804B6D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804B6D84: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804B6D88: jal         0x800444D0
    // 0x804B6D8C: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    func_800444D0(rdram, ctx);
        goto after_5;
    // 0x804B6D8C: sw          $zero, 0x44($t2)
    MEM_W(0X44, ctx->r10) = 0;
    after_5:
    // 0x804B6D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6D94: jal         0x80047F9C
    // 0x804B6D98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x804B6D98: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x804B6D9C: lw          $t3, 0x174($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X174);
    // 0x804B6DA0: sb          $zero, 0x17C($s1)
    MEM_B(0X17C, ctx->r17) = 0;
    // 0x804B6DA4: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x804B6DA8: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x804B6DAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804B6DB0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x804B6DB4: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x804B6DB8: sh          $t5, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r13;
    // 0x804B6DBC: lw          $t7, 0x174($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X174);
    // 0x804B6DC0: lw          $t1, 0x174($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X174);
    // 0x804B6DC4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x804B6DC8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804B6DCC: lhu         $t0, 0x1A($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X1A);
    // 0x804B6DD0: sh          $t0, 0x1A($t2)
    MEM_H(0X1A, ctx->r10) = ctx->r8;
    // 0x804B6DD4: lw          $t3, 0x1EC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1EC);
    // 0x804B6DD8: sw          $t3, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r11;
L_804B6DDC:
    // 0x804B6DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804B6DE0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804B6DE4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804B6DE8: jr          $ra
    // 0x804B6DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804B6DEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8055394C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8055394C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80553950: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80553954: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80553958: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8055395C: lw          $t6, 0xDCC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XDCC);
    // 0x80553960: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80553964: or          $t7, $a0, $zero
    ctx->r15 = ctx->r4 | 0;
    // 0x80553968: bnel        $t6, $zero, L_805539D0
    if (ctx->r14 != 0) {
        // 0x8055396C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805539D0;
    }
    goto skip_0;
    // 0x8055396C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80553970: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80553974: lw          $a1, 0x38($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X38);
    // 0x80553978: jal         0x80067BBC
    // 0x8055397C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x8055397C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80553980: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    // 0x80553984: jal         0x80067818
    // 0x80553988: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80553988: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8055398C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80553990: lw          $a0, 0x34($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X34);
    // 0x80553994: jal         0x80067BBC
    // 0x80553998: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80553998: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_2:
    // 0x8055399C: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x805539A0: jal         0x80067818
    // 0x805539A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805539A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805539A8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x805539AC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x805539B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805539B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805539B8: sw          $v0, 0xDCC($a3)
    MEM_W(0XDCC, ctx->r7) = ctx->r2;
    // 0x805539BC: sw          $v0, 0xDD4($a3)
    MEM_W(0XDD4, ctx->r7) = ctx->r2;
    // 0x805539C0: sw          $zero, 0xD54($a3)
    MEM_W(0XD54, ctx->r7) = 0;
    // 0x805539C4: sw          $t8, 0xDD0($a3)
    MEM_W(0XDD0, ctx->r7) = ctx->r24;
    // 0x805539C8: swc1        $f4, 0xDB8($a3)
    MEM_W(0XDB8, ctx->r7) = ctx->f4.u32l;
    // 0x805539CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805539D0:
    // 0x805539D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805539D4: jr          $ra
    // 0x805539D8: nop

    return;
    // 0x805539D8: nop

;}
RECOMP_FUNC void func_80037094(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037098: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003709C: jal         0x80021958
    // 0x800370A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800370A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800370A4: bne         $v0, $zero, L_800370B4
    if (ctx->r2 != 0) {
        // 0x800370A8: nop
    
            goto L_800370B4;
    }
    // 0x800370A8: nop

    // 0x800370AC: b           L_800370F0
    // 0x800370B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800370F0;
    // 0x800370B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800370B4:
    // 0x800370B4: jal         0x80041714
    // 0x800370B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80041714(rdram, ctx);
        goto after_1;
    // 0x800370B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800370BC: beq         $v0, $zero, L_800370CC
    if (ctx->r2 == 0) {
        // 0x800370C0: nop
    
            goto L_800370CC;
    }
    // 0x800370C0: nop

    // 0x800370C4: b           L_800370F0
    // 0x800370C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800370F0;
    // 0x800370C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800370CC:
    // 0x800370CC: jal         0x80036C54
    // 0x800370D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036C54(rdram, ctx);
        goto after_2;
    // 0x800370D0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x800370D4: bne         $v0, $zero, L_800370E4
    if (ctx->r2 != 0) {
        // 0x800370D8: nop
    
            goto L_800370E4;
    }
    // 0x800370D8: nop

    // 0x800370DC: b           L_800370F0
    // 0x800370E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800370F0;
    // 0x800370E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800370E4:
    // 0x800370E4: jal         0x80036EDC
    // 0x800370E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80036EDC(rdram, ctx);
        goto after_3;
    // 0x800370E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x800370EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800370F0:
    // 0x800370F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800370F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800370F8: jr          $ra
    // 0x800370FC: nop

    return;
    // 0x800370FC: nop

;}
RECOMP_FUNC void func_806AA590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA590: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AA594: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA598: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA59C: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806AA5A0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806AA5A4: lui         $t7, 0x806B
    ctx->r15 = S32(RELOC_HI16(589, 0X1184) << 16);
    // 0x806AA5A8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806AA5AC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806AA5B0: addiu       $t7, $t7, -0x56BC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(589, 0X1184));
    // 0x806AA5B4: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AA5B8: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806AA5BC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806AA5C0: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x806AA5C4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806AA5C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806AA5CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AA5D0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806AA5D4: jal         0x80045A34
    // 0x806AA5D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806AA5D8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x806AA5DC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806AA5E0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(589, 0X11F4) << 16);
    // 0x806AA5E4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806AA5E8: lwc1        $f4, -0x564C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(589, 0X11F4));
    // 0x806AA5EC: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x806AA5F0: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806AA5F4: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x806AA5F8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806AA5FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA600: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA604: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806AA608: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806AA60C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x806AA610: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x806AA614: jal         0x806AA784
    // 0x806AA618: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA618: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    after_1:
    // 0x806AA61C: jal         0x806AA2A4
    // 0x806AA620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AA2A4(rdram, ctx);
        goto after_2;
    // 0x806AA620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AA624: lw          $t1, 0x168($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X168);
    // 0x806AA628: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA62C: lw          $a1, 0x88($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X88);
    // 0x806AA630: jal         0x8004590C
    // 0x806AA634: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    func_8004590C(rdram, ctx);
        goto after_3;
    // 0x806AA634: addiu       $a1, $a1, 0x200
    ctx->r5 = ADD32(ctx->r5, 0X200);
    after_3:
    // 0x806AA638: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806AA63C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA640: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AA644: jr          $ra
    // 0x806AA648: nop

    return;
    // 0x806AA648: nop

;}
RECOMP_FUNC void func_8046C420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046C420: jr          $ra
    // 0x8046C424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8046C424: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8046C428: nop

    // 0x8046C42C: nop

;}
RECOMP_FUNC void func_8045AA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AA4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045AA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045AA54: jal         0x8004700C
    // 0x8045AA58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8045AA58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045AA5C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8045AA60: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    // 0x8045AA64: lhu         $v1, 0x40($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X40);
    // 0x8045AA68: andi        $t6, $v1, 0x2
    ctx->r14 = ctx->r3 & 0X2;
    // 0x8045AA6C: beq         $t6, $zero, L_8045AAA8
    if (ctx->r14 == 0) {
        // 0x8045AA70: andi        $t7, $v1, 0x4
        ctx->r15 = ctx->r3 & 0X4;
            goto L_8045AAA8;
    }
    // 0x8045AA70: andi        $t7, $v1, 0x4
    ctx->r15 = ctx->r3 & 0X4;
    // 0x8045AA74: bnel        $t7, $zero, L_8045AAAC
    if (ctx->r15 != 0) {
        // 0x8045AA78: andi        $t0, $v1, 0xFFFB
        ctx->r8 = ctx->r3 & 0XFFFB;
            goto L_8045AAAC;
    }
    goto skip_0;
    // 0x8045AA78: andi        $t0, $v1, 0xFFFB
    ctx->r8 = ctx->r3 & 0XFFFB;
    skip_0:
    // 0x8045AA7C: beql        $v0, $zero, L_8045AAA0
    if (ctx->r2 == 0) {
        // 0x8045AA80: andi        $t9, $v1, 0xFFFD
        ctx->r25 = ctx->r3 & 0XFFFD;
            goto L_8045AAA0;
    }
    goto skip_1;
    // 0x8045AA80: andi        $t9, $v1, 0xFFFD
    ctx->r25 = ctx->r3 & 0XFFFD;
    skip_1:
    // 0x8045AA84: lw          $a1, 0x174($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X174);
    // 0x8045AA88: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x8045AA8C: bnel        $a2, $t8, L_8045AAA0
    if (ctx->r6 != ctx->r24) {
        // 0x8045AA90: andi        $t9, $v1, 0xFFFD
        ctx->r25 = ctx->r3 & 0XFFFD;
            goto L_8045AAA0;
    }
    goto skip_2;
    // 0x8045AA90: andi        $t9, $v1, 0xFFFD
    ctx->r25 = ctx->r3 & 0XFFFD;
    skip_2:
    // 0x8045AA94: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8045AA98: lhu         $v1, 0x40($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X40);
    // 0x8045AA9C: andi        $t9, $v1, 0xFFFD
    ctx->r25 = ctx->r3 & 0XFFFD;
L_8045AAA0:
    // 0x8045AAA0: sh          $t9, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r25;
    // 0x8045AAA4: andi        $v1, $t9, 0xFFFF
    ctx->r3 = ctx->r25 & 0XFFFF;
L_8045AAA8:
    // 0x8045AAA8: andi        $t0, $v1, 0xFFFB
    ctx->r8 = ctx->r3 & 0XFFFB;
L_8045AAAC:
    // 0x8045AAAC: sh          $t0, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r8;
    // 0x8045AAB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045AAB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045AAB8: jr          $ra
    // 0x8045AABC: nop

    return;
    // 0x8045AABC: nop

;}
RECOMP_FUNC void func_8077F9EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077F9EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8077F9F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8077F9F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8077F9F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8077F9FC: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8077FA00: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8077FA04: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8077FA08: bne         $t6, $at, L_8077FB34
    if (ctx->r14 != ctx->r1) {
        // 0x8077FA0C: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8077FB34;
    }
    // 0x8077FA0C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8077FA10: lbu         $t7, 0x18($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X18);
    // 0x8077FA14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8077FA18: bnel        $t7, $at, L_8077FB38
    if (ctx->r15 != ctx->r1) {
        // 0x8077FA1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_0;
    // 0x8077FA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8077FA20: lw          $t8, 0x174($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X174);
    // 0x8077FA24: lui         $at, 0x8078
    ctx->r1 = S32(RELOC_HI16(781, 0X7D0) << 16);
    // 0x8077FA28: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8077FA2C: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x8077FA30: beql        $t0, $zero, L_8077FB38
    if (ctx->r8 == 0) {
        // 0x8077FA34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_1;
    // 0x8077FA34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8077FA38: lw          $v1, 0x134($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X134);
    // 0x8077FA3C: lwc1        $f4, 0x84($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8077FA40: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8077FA44: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8077FA48: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8077FA4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8077FA50: lwc1        $f0, 0xE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(781, 0X7D0));
    // 0x8077FA54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8077FA58: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8077FA5C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8077FA60: nop

    // 0x8077FA64: bc1fl       L_8077FB38
    if (!c1cs) {
        // 0x8077FA68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_2;
    // 0x8077FA68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8077FA6C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8077FA70: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8077FA74: lh          $t6, -0x7682($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X7682);
    // 0x8077FA78: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8077FA7C: nop

    // 0x8077FA80: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8077FA84: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8077FA88: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8077FA8C: mflo        $t7
    ctx->r15 = lo;
    // 0x8077FA90: blezl       $t7, L_8077FB38
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8077FA94: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_3;
    // 0x8077FA94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8077FA98: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8077FA9C: lw          $t8, 0x12EC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X12EC);
    // 0x8077FAA0: bnel        $t8, $zero, L_8077FB38
    if (ctx->r24 != 0) {
        // 0x8077FAA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_4;
    // 0x8077FAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8077FAA8: lbu         $t9, 0xF4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF4);
    // 0x8077FAAC: bnel        $t9, $zero, L_8077FB38
    if (ctx->r25 != 0) {
        // 0x8077FAB0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_5;
    // 0x8077FAB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8077FAB4: lbu         $t0, 0x154($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X154);
    // 0x8077FAB8: bnel        $t0, $zero, L_8077FB38
    if (ctx->r8 != 0) {
        // 0x8077FABC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_6;
    // 0x8077FABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8077FAC0: lbu         $t1, 0x155($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X155);
    // 0x8077FAC4: bnel        $t1, $zero, L_8077FB38
    if (ctx->r9 != 0) {
        // 0x8077FAC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_7;
    // 0x8077FAC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8077FACC: lbu         $t2, 0x1F8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1F8);
    // 0x8077FAD0: bnel        $t2, $zero, L_8077FB38
    if (ctx->r10 != 0) {
        // 0x8077FAD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8077FB38;
    }
    goto skip_8;
    // 0x8077FAD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8077FAD8: beq         $v1, $zero, L_8077FAFC
    if (ctx->r3 == 0) {
        // 0x8077FADC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8077FAFC;
    }
    // 0x8077FADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8077FAE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8077FAE4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8077FAE8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8077FAEC: jal         0x8002F7AC
    // 0x8077FAF0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    func_8002F7AC(rdram, ctx);
        goto after_0;
    // 0x8077FAF0: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    after_0:
    // 0x8077FAF4: b           L_8077FB10
    // 0x8077FAF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_8077FB10;
    // 0x8077FAF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8077FAFC:
    // 0x8077FAFC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8077FB00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8077FB04: jal         0x8002F7AC
    // 0x8077FB08: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    func_8002F7AC(rdram, ctx);
        goto after_1;
    // 0x8077FB08: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_1:
    // 0x8077FB0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8077FB10:
    // 0x8077FB10: jal         0x807800BC
    // 0x8077FB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807800BC(rdram, ctx);
        goto after_2;
    // 0x8077FB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8077FB18: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x8077FB1C: sw          $t3, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r11;
    // 0x8077FB20: jal         0x8005FE48
    // 0x8077FB24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8077FB24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8077FB28: lw          $t4, 0x174($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X174);
    // 0x8077FB2C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8077FB30: sb          $zero, 0x74($t5)
    MEM_B(0X74, ctx->r13) = 0;
L_8077FB34:
    // 0x8077FB34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8077FB38:
    // 0x8077FB38: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8077FB3C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8077FB40: jr          $ra
    // 0x8077FB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8077FB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8044E87C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044E87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044E880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044E884: lui         $a0, 0x8046
    ctx->r4 = S32(RELOC_HI16(98, 0X13C48) << 16);
    // 0x8044E888: lui         $a1, 0x8046
    ctx->r5 = S32(RELOC_HI16(98, 0X13C54) << 16);
    // 0x8044E88C: addiu       $a1, $a1, -0x7FCC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(98, 0X13C54));
    // 0x8044E890: addiu       $a0, $a0, -0x7FD8
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X13C48));
    // 0x8044E894: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8044E898: jal         0x8006C56C
    // 0x8044E89C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    func_8006C56C(rdram, ctx);
        goto after_0;
    // 0x8044E89C: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_0:
    // 0x8044E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044E8A8: jr          $ra
    // 0x8044E8AC: nop

    return;
    // 0x8044E8AC: nop

;}
RECOMP_FUNC void func_8067302C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067302C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673030: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80673034: beq         $at, $zero, L_80673044
    if (ctx->r1 == 0) {
        // 0x80673038: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80673044;
    }
    // 0x80673038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067303C: b           L_806730A0
    // 0x80673040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806730A0;
    // 0x80673040: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80673044:
    // 0x80673044: bnel        $a0, $a1, L_80673058
    if (ctx->r4 != ctx->r5) {
        // 0x80673048: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80673058;
    }
    goto skip_0;
    // 0x80673048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x8067304C: b           L_806730A0
    // 0x80673050: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_806730A0;
    // 0x80673050: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80673054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_80673058:
    // 0x80673058: jal         0x800653D8
    // 0x8067305C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8067305C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80673060: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80673064: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80673068: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x8067306C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80673070: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x80673074: mfhi        $t8
    ctx->r24 = hi;
    // 0x80673078: bne         $t7, $zero, L_80673084
    if (ctx->r15 != 0) {
        // 0x8067307C: nop
    
            goto L_80673084;
    }
    // 0x8067307C: nop

    // 0x80673080: break       7
    do_break(2154246272);
L_80673084:
    // 0x80673084: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80673088: bne         $t7, $at, L_8067309C
    if (ctx->r15 != ctx->r1) {
        // 0x8067308C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8067309C;
    }
    // 0x8067308C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80673090: bne         $v0, $at, L_8067309C
    if (ctx->r2 != ctx->r1) {
        // 0x80673094: nop
    
            goto L_8067309C;
    }
    // 0x80673094: nop

    // 0x80673098: break       6
    do_break(2154246296);
L_8067309C:
    // 0x8067309C: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_806730A0:
    // 0x806730A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806730A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806730A8: jr          $ra
    // 0x806730AC: nop

    return;
    // 0x806730AC: nop

;}
RECOMP_FUNC void func_8003D76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D76C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003D770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003D774: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003D778: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003D77C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003D780: lw          $s1, 0x15C($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X15C);
    // 0x8003D784: lw          $s0, 0x160($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X160);
    // 0x8003D788: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003D78C: lw          $v0, 0x174($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X174);
    // 0x8003D790: sb          $t6, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r14;
    // 0x8003D794: lw          $t7, 0x1F4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003D798: sb          $t6, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r14;
    // 0x8003D79C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8003D7A0: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003D7A4: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003D7A8: addiu       $v1, $v1, -0x3650
    ctx->r3 = ADD32(ctx->r3, -0X3650);
    // 0x8003D7AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003D7B0: sb          $t6, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r14;
    // 0x8003D7B4: sw          $v1, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r3;
    // 0x8003D7B8: sw          $v1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r3;
    // 0x8003D7BC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8003D7C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003D7C4: sh          $zero, 0x10($t9)
    MEM_H(0X10, ctx->r25) = 0;
    // 0x8003D7C8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003D7CC: jal         0x8005FD1C
    // 0x8003D7D0: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8003D7D0: sh          $zero, 0x12($t0)
    MEM_H(0X12, ctx->r8) = 0;
    after_0:
    // 0x8003D7D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003D7D8: lw          $t1, 0x180($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X180);
    // 0x8003D7DC: beql        $a0, $t1, L_8003D824
    if (ctx->r4 == ctx->r9) {
        // 0x8003D7E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003D824;
    }
    goto skip_0;
    // 0x8003D7E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8003D7E4: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x8003D7E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003D7EC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8003D7F0: jal         0x8004816C
    // 0x8003D7F4: sh          $t2, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r10;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x8003D7F4: sh          $t2, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r10;
    after_1:
    // 0x8003D7F8: jal         0x80048060
    // 0x8003D7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80048060(rdram, ctx);
        goto after_2;
    // 0x8003D7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003D800: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003D804: jal         0x80047F9C
    // 0x8003D808: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8003D808: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8003D80C: jal         0x80048060
    // 0x8003D810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80048060(rdram, ctx);
        goto after_4;
    // 0x8003D810: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8003D814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003D818: jal         0x80047F9C
    // 0x8003D81C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8003D81C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8003D820: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003D824:
    // 0x8003D824: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003D828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D82C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003D830: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003D834: sb          $t5, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r13;
    // 0x8003D838: jr          $ra
    // 0x8003D83C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003D83C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80046E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046E2C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046E30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046E34: bne         $a1, $at, L_80046E44
    if (ctx->r5 != ctx->r1) {
        // 0x80046E38: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80046E44;
    }
    // 0x80046E38: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046E3C: b           L_80046E54
    // 0x80046E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046E54;
    // 0x80046E40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046E44:
    // 0x80046E44: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80046E48: addiu       $a1, $a1, 0x6DC8
    ctx->r5 = ADD32(ctx->r5, 0X6DC8);
    // 0x80046E4C: jal         0x80046D90
    // 0x80046E50: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80046D90(rdram, ctx);
        goto after_0;
    // 0x80046E50: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
L_80046E54:
    // 0x80046E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046E5C: jr          $ra
    // 0x80046E60: nop

    return;
    // 0x80046E60: nop

;}
RECOMP_FUNC void func_80475C4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475C4C: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x80475C50: addiu       $t2, $t2, 0x7EA0
    ctx->r10 = ADD32(ctx->r10, 0X7EA0);
    // 0x80475C54: lhu         $t1, 0x13B4($t2)
    ctx->r9 = MEM_HU(ctx->r10, 0X13B4);
    // 0x80475C58: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80475C5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80475C60: andi        $t1, $t1, 0x7
    ctx->r9 = ctx->r9 & 0X7;
    // 0x80475C64: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80475C68: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80475C6C: blez        $t1, L_80475C84
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80475C70: lw          $v0, 0x1F4($t6)
        ctx->r2 = MEM_W(ctx->r14, 0X1F4);
            goto L_80475C84;
    }
    // 0x80475C70: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80475C74: slti        $at, $t1, 0x6
    ctx->r1 = SIGNED(ctx->r9) < 0X6 ? 1 : 0;
    // 0x80475C78: beql        $at, $zero, L_80475C88
    if (ctx->r1 == 0) {
        // 0x80475C7C: lui         $t7, 0x1
        ctx->r15 = S32(0X1 << 16);
            goto L_80475C88;
    }
    goto skip_0;
    // 0x80475C7C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    skip_0:
    // 0x80475C80: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_80475C84:
    // 0x80475C84: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
L_80475C88:
    // 0x80475C88: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80475C8C: lw          $t7, 0x6D10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D10);
    // 0x80475C90: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x80475C94: beql        $a3, $t7, L_80475CA4
    if (ctx->r7 == ctx->r15) {
        // 0x80475C98: lw          $t8, 0xFB8($t2)
        ctx->r24 = MEM_W(ctx->r10, 0XFB8);
            goto L_80475CA4;
    }
    goto skip_1;
    // 0x80475C98: lw          $t8, 0xFB8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XFB8);
    skip_1:
    // 0x80475C9C: addiu       $t0, $t0, 0x6
    ctx->r8 = ADD32(ctx->r8, 0X6);
    // 0x80475CA0: lw          $t8, 0xFB8($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XFB8);
L_80475CA4:
    // 0x80475CA4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80475CA8: srl         $t3, $t9, 30
    ctx->r11 = S32(U32(ctx->r25) >> 30);
    // 0x80475CAC: bne         $t3, $zero, L_80475CB8
    if (ctx->r11 != 0) {
        // 0x80475CB0: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_80475CB8;
    }
    // 0x80475CB0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80475CB4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
L_80475CB8:
    // 0x80475CB8: sll         $t4, $t0, 2
    ctx->r12 = S32(ctx->r8 << 2);
    // 0x80475CBC: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80475CC0: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x80475CC4: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80475CC8: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x80475CCC: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80475CD0: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80475CD4: addu        $t3, $v1, $t9
    ctx->r11 = ADD32(ctx->r3, ctx->r25);
    // 0x80475CD8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80475CDC: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80475CE0: jr          $ra
    // 0x80475CE4: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x80475CE4: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void func_80410F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80410F28: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80410F2C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80410F30: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80410F34: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80410F38: addu        $s4, $a0, $at
    ctx->r20 = ADD32(ctx->r4, ctx->r1);
    // 0x80410F3C: addu        $s5, $a0, $at
    ctx->r21 = ADD32(ctx->r4, ctx->r1);
    // 0x80410F40: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80410F44: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80410F48: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80410F4C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80410F50: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80410F54: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80410F58: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80410F5C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80410F60: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80410F64: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80410F68: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80410F6C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80410F70: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80410F74: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80410F78: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80410F7C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80410F80: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x80410F84: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80410F88: lw          $v0, 0x1E0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1E0);
    // 0x80410F8C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80410F90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80410F94: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80410F98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80410F9C: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x80410FA0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80410FA4: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x80410FA8: addiu       $s7, $zero, 0x50
    ctx->r23 = ADD32(0, 0X50);
    // 0x80410FAC: addiu       $fp, $v0, -0x12
    ctx->r30 = ADD32(ctx->r2, -0X12);
    // 0x80410FB0: mtc1        $fp, $f4
    ctx->f4.u32l = ctx->r30;
L_80410FB4:
    // 0x80410FB4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80410FB8: lui         $at, 0xC320
    ctx->r1 = S32(0XC320 << 16);
    // 0x80410FBC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80410FC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80410FC4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80410FC8: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x80410FCC: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80410FD0: nop

    // 0x80410FD4: bc1f        L_80410FE4
    if (!c1cs) {
        // 0x80410FD8: nop
    
            goto L_80410FE4;
    }
    // 0x80410FD8: nop

    // 0x80410FDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80410FE0: nop

L_80410FE4:
    // 0x80410FE4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80410FE8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X247C) << 16);
    // 0x80410FEC: lwc1        $f8, 0x1AFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(26, 0X247C));
    // 0x80410FF0: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x80410FF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80410FF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80410FFC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80411000: bgez        $s3, L_80411014
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80411004: swc1        $f2, 0xA0($sp)
        MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
            goto L_80411014;
    }
    // 0x80411004: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    // 0x80411008: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8041100C: nop

    // 0x80411010: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80411014:
    // 0x80411014: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80411018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8041101C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80411020: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80411024: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80411028: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8041102C: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
L_80411030:
    // 0x80411030: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80411034: lw          $a0, 0x39E8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X39E8);
    // 0x80411038: beq         $s1, $zero, L_80411054
    if (ctx->r17 == 0) {
        // 0x8041103C: add.s       $f20, $f20, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
            goto L_80411054;
    }
    // 0x8041103C: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x80411040: c.lt.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl < ctx->f20.fl;
    // 0x80411044: nop

    // 0x80411048: bc1fl       L_80411058
    if (!c1cs) {
        // 0x8041104C: addiu       $t7, $a0, 0x1
        ctx->r15 = ADD32(ctx->r4, 0X1);
            goto L_80411058;
    }
    goto skip_0;
    // 0x8041104C: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80411050: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
L_80411054:
    // 0x80411054: addiu       $t7, $a0, 0x1
    ctx->r15 = ADD32(ctx->r4, 0X1);
L_80411058:
    // 0x80411058: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8041105C: mul.s       $f16, $f22, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80411060: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2480) << 16);
    // 0x80411064: c.lt.s      $f30, $f20
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f30.fl < ctx->f20.fl;
    // 0x80411068: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8041106C: mflo        $t8
    ctx->r24 = lo;
    // 0x80411070: addu        $v1, $t8, $s3
    ctx->r3 = ADD32(ctx->r24, ctx->r19);
    // 0x80411074: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80411078: multu       $v1, $s6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8041107C: mflo        $t9
    ctx->r25 = lo;
    // 0x80411080: addu        $v0, $s0, $t9
    ctx->r2 = ADD32(ctx->r16, ctx->r25);
    // 0x80411084: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80411088: lwc1        $f6, 0x1B00($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(26, 0X2480));
    // 0x8041108C: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80411090: sb          $s2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r18;
    // 0x80411094: mul.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x80411098: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8041109C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x804110A0: mul.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x804110A4: nop

    // 0x804110A8: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x804110AC: trunc.w.s   $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804110B0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x804110B4: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x804110B8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x804110BC: sh          $t3, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r11;
    // 0x804110C0: bc1f        L_80411178
    if (!c1cs) {
        // 0x804110C4: sh          $t5, 0x4($v0)
        MEM_H(0X4, ctx->r2) = ctx->r13;
            goto L_80411178;
    }
    // 0x804110C4: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x804110C8: sub.s       $f8, $f20, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f30.fl;
    // 0x804110CC: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x804110D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804110D4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804110D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804110DC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804110E0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804110E4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804110E8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x804110EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x804110F0: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804110F4: nop

    // 0x804110F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x804110FC: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80411100: nop

    // 0x80411104: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80411108: beql        $v1, $zero, L_80411158
    if (ctx->r3 == 0) {
        // 0x8041110C: mfc1        $v1, $f6
        ctx->r3 = (int32_t)ctx->f6.u32l;
            goto L_80411158;
    }
    goto skip_1;
    // 0x8041110C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x80411110: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80411114: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80411118: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8041111C: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80411120: nop

    // 0x80411124: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80411128: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x8041112C: nop

    // 0x80411130: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80411134: bne         $v1, $zero, L_8041114C
    if (ctx->r3 != 0) {
        // 0x80411138: nop
    
            goto L_8041114C;
    }
    // 0x80411138: nop

    // 0x8041113C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80411140: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80411144: b           L_80411164
    // 0x80411148: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80411164;
    // 0x80411148: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_8041114C:
    // 0x8041114C: b           L_80411164
    // 0x80411150: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80411164;
    // 0x80411150: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80411154: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
L_80411158:
    // 0x80411158: nop

    // 0x8041115C: bltz        $v1, L_8041114C
    if (SIGNED(ctx->r3) < 0) {
        // 0x80411160: nop
    
            goto L_8041114C;
    }
    // 0x80411160: nop

L_80411164:
    // 0x80411164: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80411168: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x8041116C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x80411170: b           L_80411278
    // 0x80411174: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
        goto L_80411278;
    // 0x80411174: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
L_80411178:
    // 0x80411178: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8041117C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80411180: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80411184: nop

    // 0x80411188: bc1fl       L_804111A4
    if (!c1cs) {
        // 0x8041118C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804111A4;
    }
    goto skip_2;
    // 0x8041118C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x80411190: sb          $s2, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r18;
    // 0x80411194: sb          $s2, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r18;
    // 0x80411198: b           L_80411278
    // 0x8041119C: sb          $s2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r18;
        goto L_80411278;
    // 0x8041119C: sb          $s2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r18;
    // 0x804111A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804111A4:
    // 0x804111A4: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x804111A8: c.lt.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl < ctx->f20.fl;
    // 0x804111AC: nop

    // 0x804111B0: bc1fl       L_80411270
    if (!c1cs) {
        // 0x804111B4: sb          $s7, 0x8($v0)
        MEM_B(0X8, ctx->r2) = ctx->r23;
            goto L_80411270;
    }
    goto skip_3;
    // 0x804111B4: sb          $s7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r23;
    skip_3:
    // 0x804111B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804111BC: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x804111C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804111C4: sub.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x804111C8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x804111CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804111D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x804111D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x804111D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x804111DC: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x804111E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x804111E4: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x804111E8: nop

    // 0x804111EC: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x804111F0: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x804111F4: nop

    // 0x804111F8: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x804111FC: beql        $v1, $zero, L_8041124C
    if (ctx->r3 == 0) {
        // 0x80411200: mfc1        $v1, $f16
        ctx->r3 = (int32_t)ctx->f16.u32l;
            goto L_8041124C;
    }
    goto skip_4;
    // 0x80411200: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    skip_4:
    // 0x80411204: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80411208: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8041120C: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80411210: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80411214: nop

    // 0x80411218: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8041121C: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80411220: nop

    // 0x80411224: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80411228: bne         $v1, $zero, L_80411240
    if (ctx->r3 != 0) {
        // 0x8041122C: nop
    
            goto L_80411240;
    }
    // 0x8041122C: nop

    // 0x80411230: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80411234: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80411238: b           L_80411258
    // 0x8041123C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80411258;
    // 0x8041123C: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80411240:
    // 0x80411240: b           L_80411258
    // 0x80411244: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80411258;
    // 0x80411244: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80411248: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
L_8041124C:
    // 0x8041124C: nop

    // 0x80411250: bltz        $v1, L_80411240
    if (SIGNED(ctx->r3) < 0) {
        // 0x80411254: nop
    
            goto L_80411240;
    }
    // 0x80411254: nop

L_80411258:
    // 0x80411258: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8041125C: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x80411260: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x80411264: b           L_80411278
    // 0x80411268: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
        goto L_80411278;
    // 0x80411268: sb          $v1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r3;
    // 0x8041126C: sb          $s7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r23;
L_80411270:
    // 0x80411270: sb          $s7, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r23;
    // 0x80411274: sb          $s7, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r23;
L_80411278:
    // 0x80411278: jal         0x80066E88
    // 0x8041127C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8041127C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80411280: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80411284: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80411288: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8041128C: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80411290: jal         0x80066DE4
    // 0x80411294: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80411294: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
    after_1:
    // 0x80411298: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8041129C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804112A0: lw          $t8, 0x39E4($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X39E4);
    // 0x804112A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x804112A8: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x804112AC: sltu        $at, $t8, $s1
    ctx->r1 = ctx->r24 < ctx->r17 ? 1 : 0;
    // 0x804112B0: beq         $at, $zero, L_80411030
    if (ctx->r1 == 0) {
        // 0x804112B4: add.s       $f24, $f24, $f6
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
            goto L_80411030;
    }
    // 0x804112B4: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x804112B8: lw          $t9, 0x39E8($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X39E8);
    // 0x804112BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x804112C0: addiu       $fp, $fp, 0x3
    ctx->r30 = ADD32(ctx->r30, 0X3);
    // 0x804112C4: sltu        $at, $t9, $s3
    ctx->r1 = ctx->r25 < ctx->r19 ? 1 : 0;
    // 0x804112C8: beql        $at, $zero, L_80410FB4
    if (ctx->r1 == 0) {
        // 0x804112CC: mtc1        $fp, $f4
        ctx->f4.u32l = ctx->r30;
            goto L_80410FB4;
    }
    goto skip_5;
    // 0x804112CC: mtc1        $fp, $f4
    ctx->f4.u32l = ctx->r30;
    skip_5:
    // 0x804112D0: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x804112D4: lw          $v0, 0x1E0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1E0);
    // 0x804112D8: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x804112DC: sw          $t1, 0x1E0($t0)
    MEM_W(0X1E0, ctx->r8) = ctx->r9;
    // 0x804112E0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x804112E4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x804112E8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x804112EC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x804112F0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x804112F4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x804112F8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x804112FC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80411300: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80411304: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80411308: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8041130C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80411310: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80411314: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80411318: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8041131C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80411320: jr          $ra
    // 0x80411324: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80411324: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_80455D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455D88: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455D8C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80455D90: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x80455D94: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80455D98: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455D9C: ori         $at, $at, 0x6D14
    ctx->r1 = ctx->r1 | 0X6D14;
    // 0x80455DA0: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    // 0x80455DA4: addu        $v1, $a2, $at
    ctx->r3 = ADD32(ctx->r6, ctx->r1);
    // 0x80455DA8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80455DAC: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x80455DB0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x80455DB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80455DB8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_80455DBC:
    // 0x80455DBC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80455DC0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80455DC4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80455DC8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x80455DCC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80455DD0: bne         $v0, $a0, L_80455DBC
    if (ctx->r2 != ctx->r4) {
        // 0x80455DD4: sw          $zero, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = 0;
            goto L_80455DBC;
    }
    // 0x80455DD4: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x80455DD8: jr          $ra
    // 0x80455DDC: nop

    return;
    // 0x80455DDC: nop

;}
RECOMP_FUNC void func_8073EA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EA68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EA70: jal         0x8073EA50
    // 0x8073EA74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8073EA50(rdram, ctx);
        goto after_0;
    // 0x8073EA74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8073EA78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8073EA7C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8073EA80: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8073EA84: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8073EA88: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(748, 0X2318) << 16);
    // 0x8073EA8C: addiu       $t7, $t7, 0xB08
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(748, 0X2318));
    // 0x8073EA90: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8073EA94: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8073EA98: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8073EA9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073EAA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8073EAA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8073EAA8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8073EAAC: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8073EAB0: jal         0x8073EB14
    // 0x8073EAB4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    func_8073EB14(rdram, ctx);
        goto after_1;
    // 0x8073EAB4: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    after_1:
    // 0x8073EAB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EAC0: jr          $ra
    // 0x8073EAC4: nop

    return;
    // 0x8073EAC4: nop

;}
RECOMP_FUNC void func_8040FABC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040FABC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8040FAC0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8040FAC4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8040FAC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8040FACC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8040FAD0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8040FAD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8040FAD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8040FADC: sb          $t6, 0x7EC0($at)
    MEM_B(0X7EC0, ctx->r1) = ctx->r14;
    // 0x8040FAE0: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8040FAE4: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(26, 0X2420) << 16);
    // 0x8040FAE8: addiu       $t7, $t7, 0x1AA0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(26, 0X2420));
    // 0x8040FAEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040FAF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040FAF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040FAF8: jal         0x8040FCEC
    // 0x8040FAFC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    func_8040FCEC(rdram, ctx);
        goto after_0;
    // 0x8040FAFC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    after_0:
    // 0x8040FB00: lw          $s1, 0x1E0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1E0);
    // 0x8040FB04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8040FB08: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8040FB0C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8040FB10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8040FB14: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x8040FB18: sltiu       $at, $s1, 0x5
    ctx->r1 = ctx->r17 < 0X5 ? 1 : 0;
    // 0x8040FB1C: sb          $v0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r2;
    // 0x8040FB20: sb          $v0, 0x31($s0)
    MEM_B(0X31, ctx->r16) = ctx->r2;
    // 0x8040FB24: beq         $at, $zero, L_8040FB90
    if (ctx->r1 == 0) {
        // 0x8040FB28: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_8040FB90;
    }
    // 0x8040FB28: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8040FB2C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8040FB30: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2454) << 16);
    // 0x8040FB34: addu        $at, $at, $t9
    gpr jr_addend_8040FB3C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8040FB38: lw          $t9, 0x1AD4($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(26, 0X2454));
    // 0x8040FB3C: jr          $t9
    // 0x8040FB40: nop

    switch (jr_addend_8040FB3C >> 2) {
        case 0: goto L_8040FB44; break;
        case 1: goto L_8040FB58; break;
        case 2: goto L_8040FB6C; break;
        case 3: goto L_8040FB80; break;
        case 4: goto L_8040FB44; break;
        default: switch_error(__func__, 0x8040FB3C, 0x80411AD4);
    }
    // 0x8040FB40: nop

L_8040FB44:
    // 0x8040FB44: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8040FB48: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(26, 0X10) << 16);
    // 0x8040FB4C: addiu       $t0, $t0, -0x970
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(26, 0X10));
    // 0x8040FB50: b           L_8040FB90
    // 0x8040FB54: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
        goto L_8040FB90;
    // 0x8040FB54: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
L_8040FB58:
    // 0x8040FB58: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x8040FB5C: lui         $t2, 0x8041
    ctx->r10 = S32(RELOC_HI16(26, 0X78) << 16);
    // 0x8040FB60: addiu       $t2, $t2, -0x908
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(26, 0X78));
    // 0x8040FB64: b           L_8040FB90
    // 0x8040FB68: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
        goto L_8040FB90;
    // 0x8040FB68: sw          $t2, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->r10;
L_8040FB6C:
    // 0x8040FB6C: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x8040FB70: lui         $t4, 0x8041
    ctx->r12 = S32(RELOC_HI16(26, 0XE0) << 16);
    // 0x8040FB74: addiu       $t4, $t4, -0x8A0
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(26, 0XE0));
    // 0x8040FB78: b           L_8040FB90
    // 0x8040FB7C: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
        goto L_8040FB90;
    // 0x8040FB7C: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
L_8040FB80:
    // 0x8040FB80: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8040FB84: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(26, 0X148) << 16);
    // 0x8040FB88: addiu       $t6, $t6, -0x838
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(26, 0X148));
    // 0x8040FB8C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_8040FB90:
    // 0x8040FB90: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8040FB94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040FB98: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8040FB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040FBA0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8040FBA4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8040FBA8: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x8040FBAC: jal         0x80045A34
    // 0x8040FBB0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x8040FBB0: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x8040FBB4: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(26, 0X434) << 16);
    // 0x8040FBB8: addiu       $t8, $t8, -0x54C
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(26, 0X434));
    // 0x8040FBBC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8040FBC0: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
    // 0x8040FBC4: jal         0x80071760
    // 0x8040FBC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    func_80071760(rdram, ctx);
        goto after_2;
    // 0x8040FBC8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_2:
    // 0x8040FBCC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x8040FBD0: sw          $s1, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r17;
    // 0x8040FBD4: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x8040FBD8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8040FBDC: sltiu       $at, $t9, 0x5
    ctx->r1 = ctx->r25 < 0X5 ? 1 : 0;
    // 0x8040FBE0: beq         $at, $zero, L_8040FC44
    if (ctx->r1 == 0) {
        // 0x8040FBE4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8040FC44;
    }
    // 0x8040FBE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040FBE8: lui         $at, 0x8041
    ctx->r1 = S32(RELOC_HI16(26, 0X2468) << 16);
    // 0x8040FBEC: addu        $at, $at, $t9
    gpr jr_addend_8040FBF4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8040FBF0: lw          $t9, 0x1AE8($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(26, 0X2468));
    // 0x8040FBF4: jr          $t9
    // 0x8040FBF8: nop

    switch (jr_addend_8040FBF4 >> 2) {
        case 0: goto L_8040FBFC; break;
        case 1: goto L_8040FC24; break;
        case 2: goto L_8040FC24; break;
        case 3: goto L_8040FC24; break;
        case 4: goto L_8040FBFC; break;
        default: switch_error(__func__, 0x8040FBF4, 0x80411AE8);
    }
    // 0x8040FBF8: nop

L_8040FBFC:
    // 0x8040FBFC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x8040FC00: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8040FC04: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8040FC08: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8040FC0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8040FC10: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8040FC14: jal         0x8040FD24
    // 0x8040FC18: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_8040FD24(rdram, ctx);
        goto after_3;
    // 0x8040FC18: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_3:
    // 0x8040FC1C: b           L_8040FC48
    // 0x8040FC20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8040FC48;
    // 0x8040FC20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8040FC24:
    // 0x8040FC24: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x8040FC28: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8040FC2C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8040FC30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8040FC34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8040FC38: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x8040FC3C: jal         0x8040FD24
    // 0x8040FC40: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    func_8040FD24(rdram, ctx);
        goto after_4;
    // 0x8040FC40: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    after_4:
L_8040FC44:
    // 0x8040FC44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8040FC48:
    // 0x8040FC48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
L_8040FC4C:
    // 0x8040FC4C: jal         0x804104C4
    // 0x8040FC50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_804104C4(rdram, ctx);
        goto after_5;
    // 0x8040FC50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8040FC54: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8040FC58: jal         0x80411844
    // 0x8040FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80411844(rdram, ctx);
        goto after_6;
    // 0x8040FC5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_6:
    // 0x8040FC60: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8040FC64: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8040FC68: bnel        $at, $zero, L_8040FC4C
    if (ctx->r1 != 0) {
        // 0x8040FC6C: lw          $a0, 0x0($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X0);
            goto L_8040FC4C;
    }
    goto skip_0;
    // 0x8040FC6C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x8040FC70: jal         0x8040FDC8
    // 0x8040FC74: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    func_8040FDC8(rdram, ctx);
        goto after_7;
    // 0x8040FC74: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x8040FC78: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8040FC7C: addiu       $s3, $zero, 0x5A00
    ctx->r19 = ADD32(0, 0X5A00);
    // 0x8040FC80: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_8040FC84:
    // 0x8040FC84: addu        $a1, $s0, $s1
    ctx->r5 = ADD32(ctx->r16, ctx->r17);
    // 0x8040FC88: addiu       $a1, $a1, 0x5C0
    ctx->r5 = ADD32(ctx->r5, 0X5C0);
    // 0x8040FC8C: jal         0x8040FF04
    // 0x8040FC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040FF04(rdram, ctx);
        goto after_8;
    // 0x8040FC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8040FC94: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8040FC98: addu        $a1, $s0, $s1
    ctx->r5 = ADD32(ctx->r16, ctx->r17);
    // 0x8040FC9C: addiu       $a1, $a1, 0x5FC0
    ctx->r5 = ADD32(ctx->r5, 0X5FC0);
    // 0x8040FCA0: jal         0x8040FF04
    // 0x8040FCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8040FF04(rdram, ctx);
        goto after_9;
    // 0x8040FCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8040FCA8: addiu       $s1, $s1, 0x1E00
    ctx->r17 = ADD32(ctx->r17, 0X1E00);
    // 0x8040FCAC: bnel        $s1, $s3, L_8040FC84
    if (ctx->r17 != ctx->r19) {
        // 0x8040FCB0: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_8040FC84;
    }
    goto skip_1;
    // 0x8040FCB0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x8040FCB4: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x8040FCB8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8040FCBC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8040FCC0: bne         $t5, $zero, L_8040FCD0
    if (ctx->r13 != 0) {
        // 0x8040FCC4: sb          $t4, -0x7D78($at)
        MEM_B(-0X7D78, ctx->r1) = ctx->r12;
            goto L_8040FCD0;
    }
    // 0x8040FCC4: sb          $t4, -0x7D78($at)
    MEM_B(-0X7D78, ctx->r1) = ctx->r12;
    // 0x8040FCC8: jal         0x800677F8
    // 0x8040FCCC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800677F8(rdram, ctx);
        goto after_10;
    // 0x8040FCCC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_10:
L_8040FCD0:
    // 0x8040FCD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8040FCD4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8040FCD8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8040FCDC: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8040FCE0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8040FCE4: jr          $ra
    // 0x8040FCE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8040FCE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_806D3460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3460: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x806D3464: lui         $t9, 0x806D
    ctx->r25 = S32(RELOC_HI16(616, 0X34B8) << 16);
    // 0x806D3468: addiu       $t9, $t9, 0x6468
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(616, 0X34B8));
    // 0x806D346C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806D3470: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x806D3474: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x806D3478: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x806D347C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x806D3480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806D3484: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3488: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x806D348C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x806D3490: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x806D3494: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x806D3498: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x806D349C: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x806D34A0: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x806D34A4: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x806D34A8: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x806D34AC: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x806D34B0: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x806D34B4: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x806D34B8: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x806D34BC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x806D34C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x806D34C4: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x806D34C8: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x806D34CC: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x806D34D0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x806D34D4: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x806D34D8: sltu        $at, $t4, $t9
    ctx->r1 = ctx->r12 < ctx->r25 ? 1 : 0;
    // 0x806D34DC: bnel        $at, $zero, L_806D3514
    if (ctx->r1 != 0) {
        // 0x806D34E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806D3514;
    }
    goto skip_0;
    // 0x806D34E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806D34E4: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x806D34E8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x806D34EC: lbu         $t1, 0x8($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X8);
    // 0x806D34F0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x806D34F4: sltu        $at, $t6, $t1
    ctx->r1 = ctx->r14 < ctx->r9 ? 1 : 0;
    // 0x806D34F8: bne         $at, $zero, L_806D3508
    if (ctx->r1 != 0) {
        // 0x806D34FC: nop
    
            goto L_806D3508;
    }
    // 0x806D34FC: nop

    // 0x806D3500: b           L_806D3514
    // 0x806D3504: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_806D3514;
    // 0x806D3504: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_806D3508:
    // 0x806D3508: b           L_806D3514
    // 0x806D350C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806D3514;
    // 0x806D350C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D3510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D3514:
    // 0x806D3514: jr          $ra
    // 0x806D3518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806D3518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806EFF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EFF70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EFF74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EFF78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806EFF7C: jal         0x806EC16C
    // 0x806EFF80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806EC16C(rdram, ctx);
        goto after_0;
    // 0x806EFF80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806EFF84: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x806EFF88: jal         0x800577D8
    // 0x806EFF8C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    func_800577D8(rdram, ctx);
        goto after_1;
    // 0x806EFF8C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_1:
    // 0x806EFF90: jal         0x806EF504
    // 0x806EFF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF504(rdram, ctx);
        goto after_2;
    // 0x806EFF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EFF98: jal         0x806EF584
    // 0x806EFF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EF584(rdram, ctx);
        goto after_3;
    // 0x806EFF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EFFA0: jal         0x806EFD78
    // 0x806EFFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EFD78(rdram, ctx);
        goto after_4;
    // 0x806EFFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806EFFA8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806EFFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EFFB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFFB4: blez        $v0, L_806EFFC8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806EFFB8: addiu       $a2, $zero, 0x7
        ctx->r6 = ADD32(0, 0X7);
            goto L_806EFFC8;
    }
    // 0x806EFFB8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x806EFFBC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x806EFFC0: b           L_806F0004
    // 0x806EFFC4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
        goto L_806F0004;
    // 0x806EFFC4: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
L_806EFFC8:
    // 0x806EFFC8: jal         0x806F0348
    // 0x806EFFCC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F0348(rdram, ctx);
        goto after_5;
    // 0x806EFFCC: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_5:
    // 0x806EFFD0: lw          $a0, 0x180($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X180);
    // 0x806EFFD4: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x806EFFD8: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x806EFFDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EFFE0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x806EFFE4: jal         0x806ED360
    // 0x806EFFE8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_6;
    // 0x806EFFE8: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_6:
    // 0x806EFFEC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806EFFF0: jal         0x80067BBC
    // 0x806EFFF4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x806EFFF4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_7:
    // 0x806EFFF8: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x806EFFFC: jal         0x80067818
    // 0x806F0000: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x806F0000: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_806F0004:
    // 0x806F0004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F0008: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F000C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F0010: jr          $ra
    // 0x806F0014: nop

    return;
    // 0x806F0014: nop

;}
RECOMP_FUNC void func_806EED30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EED30: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x806EED34: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806EED38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EED3C: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x806EED40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806EED44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806EED48: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EED4C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D2C) << 16);
    // 0x806EED50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806EED54: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x806EED58: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806EED5C: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x806EED60: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x806EED64: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x806EED68: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x806EED6C: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x806EED70: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x806EED74: nop

    // 0x806EED78: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x806EED7C: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x806EED80: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x806EED84: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806EED88: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x806EED8C: lwc1        $f4, 0xC7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D2C));
    // 0x806EED90: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D30) << 16);
    // 0x806EED94: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x806EED98: nop

    // 0x806EED9C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806EEDA0: lwc1        $f4, 0xC80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D30));
    // 0x806EEDA4: swc1        $f10, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f10.u32l;
    // 0x806EEDA8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(676, 0X4D34) << 16);
    // 0x806EEDAC: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x806EEDB0: add.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x806EEDB4: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x806EEDB8: lwc1        $f10, 0xC4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806EEDBC: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x806EEDC0: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x806EEDC4: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x806EEDC8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x806EEDCC: lwc1        $f8, 0xC84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(676, 0X4D34));
    // 0x806EEDD0: lwc1        $f14, 0xC4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806EEDD4: mul.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x806EEDD8: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EEDDC: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x806EEDE0: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EEDE4: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x806EEDE8: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EEDEC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x806EEDF0: nop

    // 0x806EEDF4: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x806EEDF8: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x806EEDFC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x806EEE00: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x806EEE04: nop

    // 0x806EEE08: bc1f        L_806EEE14
    if (!c1cs) {
        // 0x806EEE0C: nop
    
            goto L_806EEE14;
    }
    // 0x806EEE0C: nop

    // 0x806EEE10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806EEE14:
    // 0x806EEE14: jr          $ra
    // 0x806EEE18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x806EEE18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80453564(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453564: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453568: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045356C: jal         0x8045341C
    // 0x80453570: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x80453570: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80453574: jal         0x80445CBC
    // 0x80453578: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80445CBC(rdram, ctx);
        goto after_1;
    // 0x80453578: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_1:
    // 0x8045357C: jal         0x80445D08
    // 0x80453580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445D08(rdram, ctx);
        goto after_2;
    // 0x80453580: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80453584: jal         0x804444FC
    // 0x80453588: nop

    static_98_804444FC(rdram, ctx);
        goto after_3;
    // 0x80453588: nop

    after_3:
    // 0x8045358C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453590: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453594: jr          $ra
    // 0x80453598: nop

    return;
    // 0x80453598: nop

;}
RECOMP_FUNC void func_80699F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80699F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80699F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80699F98: jal         0x80699C60
    // 0x80699F9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80699C60(rdram, ctx);
        goto after_0;
    // 0x80699F9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80699FA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80699FA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80699FA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80699FAC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80699FB0: jal         0x8069A0F0
    // 0x80699FB4: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    func_8069A0F0(rdram, ctx);
        goto after_1;
    // 0x80699FB4: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    after_1:
    // 0x80699FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80699FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80699FC0: jr          $ra
    // 0x80699FC4: nop

    return;
    // 0x80699FC4: nop

;}
RECOMP_FUNC void func_800805C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800805C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800805CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800805D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800805D4: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800805D8: jal         0x80082730
    // 0x800805DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x800805DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800805E0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800805E4: jal         0x8008D250
    // 0x800805E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x800805E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800805EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800805F0: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800805F4: lwc1        $f2, 0x20($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800805F8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800805FC: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080600: nop

    // 0x80080604: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080608: nop

    // 0x8008060C: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080610: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080614: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080618: lwc1        $f2, 0x24($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8008061C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080620: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080624: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x80080628: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8008062C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080630: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080634: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080638: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8008063C: lwc1        $f2, 0x28($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80080640: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080644: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x80080648: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008064C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x80080650: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080654: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080658: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8008065C: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080660: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080664: lwc1        $f2, 0x2C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80080668: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008066C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80080670: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080674: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x80080678: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8008067C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080680: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080684: nop

    // 0x80080688: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8008068C: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x80080690: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080694: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x80080698: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8008069C: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x800806A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800806A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800806A8: jr          $ra
    // 0x800806AC: nop

    return;
    // 0x800806AC: nop

;}
RECOMP_FUNC void func_80534C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534C34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80534C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80534C3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80534C40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80534C44: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x80534C48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80534C4C: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534C50: beq         $v0, $zero, L_80534C7C
    if (ctx->r2 == 0) {
        // 0x80534C54: nop
    
            goto L_80534C7C;
    }
    // 0x80534C54: nop

    // 0x80534C58: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80534C5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534C60: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80534C64: lhu         $t7, 0x119E($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X119E);
    // 0x80534C68: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80534C6C: beq         $t8, $zero, L_80534C7C
    if (ctx->r24 == 0) {
        // 0x80534C70: nop
    
            goto L_80534C7C;
    }
    // 0x80534C70: nop

    // 0x80534C74: jal         0x805350A0
    // 0x80534C78: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x80534C78: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_0:
L_80534C7C:
    // 0x80534C7C: jal         0x80534B48
    // 0x80534C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534B48(rdram, ctx);
        goto after_1;
    // 0x80534C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80534C84: lw          $t9, 0x12C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X12C);
    // 0x80534C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80534C8C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80534C90: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(348, 0X1038) << 16);
    // 0x80534C94: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80534C98: lw          $t9, 0x5648($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(348, 0X1038));
    // 0x80534C9C: jalr        $t9
    // 0x80534CA0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80534CA0: nop

    after_2:
    // 0x80534CA4: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
    // 0x80534CA8: lw          $t1, 0x1E0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1E0);
    // 0x80534CAC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80534CB0: slti        $at, $t2, 0x78
    ctx->r1 = SIGNED(ctx->r10) < 0X78 ? 1 : 0;
    // 0x80534CB4: bne         $at, $zero, L_80534CD4
    if (ctx->r1 != 0) {
        // 0x80534CB8: sw          $t2, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r10;
            goto L_80534CD4;
    }
    // 0x80534CB8: sw          $t2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r10;
    // 0x80534CBC: jal         0x800653D8
    // 0x80534CC0: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80534CC0: nop

    after_3:
    // 0x80534CC4: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x80534CC8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80534CCC: sh          $t5, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r13;
    // 0x80534CD0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80534CD4:
    // 0x80534CD4: lhu         $t6, 0x10($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X10);
    // 0x80534CD8: beq         $t6, $zero, L_80534D00
    if (ctx->r14 == 0) {
        // 0x80534CDC: nop
    
            goto L_80534D00;
    }
    // 0x80534CDC: nop

    // 0x80534CE0: jal         0x805347F0
    // 0x80534CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805347F0(rdram, ctx);
        goto after_4;
    // 0x80534CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80534CE8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534CEC: bne         $v0, $at, L_80534D00
    if (ctx->r2 != ctx->r1) {
        // 0x80534CF0: nop
    
            goto L_80534D00;
    }
    // 0x80534CF0: nop

    // 0x80534CF4: lhu         $t7, 0x10($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X10);
    // 0x80534CF8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80534CFC: sh          $t8, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r24;
L_80534D00:
    // 0x80534D00: jal         0x8053484C
    // 0x80534D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8053484C(rdram, ctx);
        goto after_5;
    // 0x80534D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80534D08: jal         0x80534678
    // 0x80534D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534678(rdram, ctx);
        goto after_6;
    // 0x80534D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80534D10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80534D14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80534D18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80534D1C: jr          $ra
    // 0x80534D20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80534D20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8041FF80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FF80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041FF84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041FF88: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8041FF8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8041FF90: beq         $t6, $zero, L_8041FFCC
    if (ctx->r14 == 0) {
        // 0x8041FF94: nop
    
            goto L_8041FFCC;
    }
    // 0x8041FF94: nop

    // 0x8041FF98: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8041FF9C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8041FFA0: jalr        $t9
    // 0x8041FFA4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8041FFA4: nop

    after_0:
    // 0x8041FFA8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8041FFAC: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8041FFB0: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8041FFB4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8041FFB8: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8041FFBC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8041FFC0: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8041FFC4: b           L_8041FFCC
    // 0x8041FFC8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8041FFCC;
    // 0x8041FFC8: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8041FFCC:
    // 0x8041FFCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041FFD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041FFD4: jr          $ra
    // 0x8041FFD8: nop

    return;
    // 0x8041FFD8: nop

;}
RECOMP_FUNC void func_805A5DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5DF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A5DF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A5DF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A5DFC: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x805A5E00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A5E04: beq         $t6, $zero, L_805A5E1C
    if (ctx->r14 == 0) {
        // 0x805A5E08: nop
    
            goto L_805A5E1C;
    }
    // 0x805A5E08: nop

    // 0x805A5E0C: jal         0x805A5440
    // 0x805A5E10: nop

    func_805A5440(rdram, ctx);
        goto after_0;
    // 0x805A5E10: nop

    after_0:
    // 0x805A5E14: b           L_805A5E24
    // 0x805A5E18: nop

        goto L_805A5E24;
    // 0x805A5E18: nop

L_805A5E1C:
    // 0x805A5E1C: jal         0x805A5368
    // 0x805A5E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5368(rdram, ctx);
        goto after_1;
    // 0x805A5E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_805A5E24:
    // 0x805A5E24: jal         0x805A5480
    // 0x805A5E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5480(rdram, ctx);
        goto after_2;
    // 0x805A5E28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805A5E2C: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x805A5E30: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x805A5E34: jal         0x80065ABC
    // 0x805A5E38: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_3;
    // 0x805A5E38: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_3:
    // 0x805A5E3C: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x805A5E40: jal         0x805A58AC
    // 0x805A5E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A58AC(rdram, ctx);
        goto after_4;
    // 0x805A5E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805A5E48: bne         $v0, $zero, L_805A5E58
    if (ctx->r2 != 0) {
        // 0x805A5E4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A5E58;
    }
    // 0x805A5E4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805A5E50: b           L_805A5E5C
    // 0x805A5E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805A5E5C;
    // 0x805A5E54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805A5E58:
    // 0x805A5E58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805A5E5C:
    // 0x805A5E5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A5E60: jr          $ra
    // 0x805A5E64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805A5E64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8003B2DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B2DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B2E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B2E4: jal         0x8003B2B0
    // 0x8003B2E8: nop

    func_8003B2B0(rdram, ctx);
        goto after_0;
    // 0x8003B2E8: nop

    after_0:
    // 0x8003B2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B2F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B2F4: jr          $ra
    // 0x8003B2F8: nop

    return;
    // 0x8003B2F8: nop

;}
RECOMP_FUNC void func_806AEFD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEFD4: jr          $ra
    // 0x806AEFD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806AEFD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_800035F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800035F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800035FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003600: jal         0x80003698
    // 0x80003604: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x80003604: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80003608: beq         $v0, $zero, L_80003628
    if (ctx->r2 == 0) {
        // 0x8000360C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80003628;
    }
    // 0x8000360C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80003610: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80003614: jal         0x8000ACD0
    // 0x80003618: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8000ACD0(rdram, ctx);
        goto after_1;
    // 0x80003618: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000361C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80003620: lui         $at, 0x2000
    ctx->r1 = S32(0X2000 << 16);
    // 0x80003624: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
L_80003628:
    // 0x80003628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000362C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80003630: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80003634: jr          $ra
    // 0x80003638: nop

    return;
    // 0x80003638: nop

;}
RECOMP_FUNC void func_8002DD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DD44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002DD48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002DD4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002DD50: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DD54: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8002DD58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002DD5C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8002DD60: lbu         $t7, 0x18($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X18);
    // 0x8002DD64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002DD68: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8002DD6C: sb          $t7, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r15;
    // 0x8002DD70: lbu         $t8, 0x30($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X30);
    // 0x8002DD74: sb          $t8, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r24;
    // 0x8002DD78: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8002DD7C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8002DD80: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8002DD84: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    // 0x8002DD88: beql        $t9, $zero, L_8002DDA8
    if (ctx->r25 == 0) {
        // 0x8002DD8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8002DDA8;
    }
    goto skip_0;
    // 0x8002DD8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x8002DD90: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8002DD94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002DD98: nop

    // 0x8002DD9C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8002DDA0: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x8002DDA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8002DDA8:
    // 0x8002DDA8: jal         0x8002DB78
    // 0x8002DDAC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8002DB78(rdram, ctx);
        goto after_0;
    // 0x8002DDAC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002DDB0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8002DDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002DDB8: beq         $v1, $zero, L_8002DDD8
    if (ctx->r3 == 0) {
        // 0x8002DDBC: nop
    
            goto L_8002DDD8;
    }
    // 0x8002DDBC: nop

    // 0x8002DDC0: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x8002DDC4: addiu       $at, $zero, 0x4080
    ctx->r1 = ADD32(0, 0X4080);
    // 0x8002DDC8: beq         $v0, $at, L_8002DDE0
    if (ctx->r2 == ctx->r1) {
        // 0x8002DDCC: addiu       $at, $zero, 0x4081
        ctx->r1 = ADD32(0, 0X4081);
            goto L_8002DDE0;
    }
    // 0x8002DDCC: addiu       $at, $zero, 0x4081
    ctx->r1 = ADD32(0, 0X4081);
    // 0x8002DDD0: beql        $v0, $at, L_8002DDE4
    if (ctx->r2 == ctx->r1) {
        // 0x8002DDD4: lw          $t0, 0x2C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X2C);
            goto L_8002DDE4;
    }
    goto skip_1;
    // 0x8002DDD4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    skip_1:
L_8002DDD8:
    // 0x8002DDD8: jal         0x80021F54
    // 0x8002DDDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80021F54(rdram, ctx);
        goto after_1;
    // 0x8002DDDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
L_8002DDE0:
    // 0x8002DDE0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
L_8002DDE4:
    // 0x8002DDE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002DDE8: sb          $zero, 0x1AD($t0)
    MEM_B(0X1AD, ctx->r8) = 0;
    // 0x8002DDEC: lbu         $t1, 0x2B($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X2B);
    // 0x8002DDF0: lbu         $t2, 0x2A($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X2A);
    // 0x8002DDF4: bne         $t1, $at, L_8002DE30
    if (ctx->r9 != ctx->r1) {
        // 0x8002DDF8: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_8002DE30;
    }
    // 0x8002DDF8: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x8002DDFC: bne         $t2, $at, L_8002DE30
    if (ctx->r10 != ctx->r1) {
        // 0x8002DE00: nop
    
            goto L_8002DE30;
    }
    // 0x8002DE00: nop

    // 0x8002DE04: jal         0x8001D770
    // 0x8002DE08: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x8002DE08: nop

    after_2:
    // 0x8002DE0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DE10: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002DE14: jal         0x80067BF8
    // 0x8002DE18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x8002DE18: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8002DE1C: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    // 0x8002DE20: jal         0x80067818
    // 0x8002DE24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x8002DE24: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8002DE28: b           L_8002DE58
    // 0x8002DE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002DE58;
    // 0x8002DE2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002DE30:
    // 0x8002DE30: jal         0x8001D770
    // 0x8002DE34: nop

    func_8001D770(rdram, ctx);
        goto after_5;
    // 0x8002DE34: nop

    after_5:
    // 0x8002DE38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002DE3C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002DE40: jal         0x80067BF8
    // 0x8002DE44: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_6;
    // 0x8002DE44: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8002DE48: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002DE4C: jal         0x80067818
    // 0x8002DE50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8002DE50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8002DE54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002DE58:
    // 0x8002DE58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DE5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002DE60: jr          $ra
    // 0x8002DE64: nop

    return;
    // 0x8002DE64: nop

;}
RECOMP_FUNC void func_80043450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043450: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043454: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043458: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004345C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80043460: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80043464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043468: jal         0x800421B4
    // 0x8004346C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_800421B4(rdram, ctx);
        goto after_0;
    // 0x8004346C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80043470: beql        $v0, $zero, L_800434DC
    if (ctx->r2 == 0) {
        // 0x80043474: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800434DC;
    }
    goto skip_0;
    // 0x80043474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80043478: jal         0x800433D0
    // 0x8004347C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800433D0(rdram, ctx);
        goto after_1;
    // 0x8004347C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80043480: lw          $t9, 0xA8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XA8);
    // 0x80043484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043488: jalr        $t9
    // 0x8004348C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8004348C: nop

    after_2:
    // 0x80043490: lw          $t9, 0xAC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XAC);
    // 0x80043494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80043498: jalr        $t9
    // 0x8004349C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8004349C: nop

    after_3:
    // 0x800434A0: beql        $v0, $zero, L_800434DC
    if (ctx->r2 == 0) {
        // 0x800434A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800434DC;
    }
    goto skip_1;
    // 0x800434A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x800434A8: lw          $t9, 0xB0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB0);
    // 0x800434AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800434B0: jalr        $t9
    // 0x800434B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800434B4: nop

    after_4:
    // 0x800434B8: lw          $t9, 0xB8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XB8);
    // 0x800434BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800434C0: jalr        $t9
    // 0x800434C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800434C4: nop

    after_5:
    // 0x800434C8: lw          $t9, 0xBC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XBC);
    // 0x800434CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800434D0: jalr        $t9
    // 0x800434D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x800434D4: nop

    after_6:
    // 0x800434D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800434DC:
    // 0x800434DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800434E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800434E4: jr          $ra
    // 0x800434E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800434E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
