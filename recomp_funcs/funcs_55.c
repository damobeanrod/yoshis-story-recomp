#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80682C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80682C24: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80682C28: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80682C2C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80682C30: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80682C34: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80682C38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80682C3C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80682C40: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80682C44: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80682C48: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80682C4C: jr          $ra
    // 0x80682C50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80682C50: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80675470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675470: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80675474: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(532, 0X48) << 16);
    // 0x80675478: addiu       $t6, $t6, 0x4F98
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(532, 0X48));
    // 0x8067547C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80675480: jr          $ra
    // 0x80675484: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80675484: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8043F310(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F310: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8043F318: addiu       $v1, $zero, 0x95
    ctx->r3 = ADD32(0, 0X95);
    // 0x8043F31C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8043F320:
    // 0x8043F320: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8043F324: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8043F328: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8043F32C: bgez        $v1, L_8043F320
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8043F330: addiu       $v0, $v0, 0x30
        ctx->r2 = ADD32(ctx->r2, 0X30);
            goto L_8043F320;
    }
    // 0x8043F330: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x8043F334: jr          $ra
    // 0x8043F338: nop

    return;
    // 0x8043F338: nop

;}
RECOMP_FUNC void func_80065B50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065B50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065B54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065B58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065B5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80065B60: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80065B64: jal         0x8006593C
    // 0x80065B68: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80065B68: subu        $a0, $a0, $a2
    ctx->r4 = SUB32(ctx->r4, ctx->r6);
    after_0:
    // 0x80065B6C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80065B70: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80065B74: subu        $t8, $t7, $v0
    ctx->r24 = SUB32(ctx->r15, ctx->r2);
    // 0x80065B78: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80065B7C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80065B80: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80065B84: jal         0x8006593C
    // 0x80065B88: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    func_8006593C(rdram, ctx);
        goto after_1;
    // 0x80065B88: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    after_1:
    // 0x80065B8C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80065B90: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80065B94: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x80065B98: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80065B9C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80065BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065BA4: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80065BA8: slti        $v0, $v0, 0x0
    ctx->r2 = SIGNED(ctx->r2) < 0X0 ? 1 : 0;
    // 0x80065BAC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80065BB0: beq         $v0, $zero, L_80065BC0
    if (ctx->r2 == 0) {
        // 0x80065BB4: nop
    
            goto L_80065BC0;
    }
    // 0x80065BB4: nop

    // 0x80065BB8: slti        $v0, $t3, 0x0
    ctx->r2 = SIGNED(ctx->r11) < 0X0 ? 1 : 0;
    // 0x80065BBC: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
L_80065BC0:
    // 0x80065BC0: jr          $ra
    // 0x80065BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80065BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806F84D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F84D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F84DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F84E0: jal         0x8004700C
    // 0x806F84E4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F84E4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x806F84E8: beql        $v0, $zero, L_806F8594
    if (ctx->r2 == 0) {
        // 0x806F84EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F8594;
    }
    goto skip_0;
    // 0x806F84EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806F84F0: jal         0x80058958
    // 0x806F84F4: nop

    func_80058958(rdram, ctx);
        goto after_1;
    // 0x806F84F4: nop

    after_1:
    // 0x806F84F8: beql        $v0, $zero, L_806F8594
    if (ctx->r2 == 0) {
        // 0x806F84FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806F8594;
    }
    goto skip_1;
    // 0x806F84FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806F8500: jal         0x800582CC
    // 0x806F8504: nop

    func_800582CC(rdram, ctx);
        goto after_2;
    // 0x806F8504: nop

    after_2:
    // 0x806F8508: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x806F850C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806F8510: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x806F8514: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x806F8518: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x806F851C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806F8520: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x806F8524: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x806F8528: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x806F852C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806F8530: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x806F8534: nop

L_806F8538:
    // 0x806F8538: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806F853C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x806F8540: addu        $a2, $t1, $v0
    ctx->r6 = ADD32(ctx->r9, ctx->r2);
L_806F8544:
    // 0x806F8544: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x806F8548: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x806F854C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x806F8550: addu        $v1, $t7, $a3
    ctx->r3 = ADD32(ctx->r15, ctx->r7);
    // 0x806F8554: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x806F8558: bne         $at, $zero, L_806F8568
    if (ctx->r1 != 0) {
        // 0x806F855C: nop
    
            goto L_806F8568;
    }
    // 0x806F855C: nop

    // 0x806F8560: b           L_806F8574
    // 0x806F8564: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
        goto L_806F8574;
    // 0x806F8564: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_806F8568:
    // 0x806F8568: bgezl       $v1, L_806F8578
    if (SIGNED(ctx->r3) >= 0) {
        // 0x806F856C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_806F8578;
    }
    goto skip_2;
    // 0x806F856C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x806F8570: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_806F8574:
    // 0x806F8574: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_806F8578:
    // 0x806F8578: bne         $a0, $t0, L_806F8544
    if (ctx->r4 != ctx->r8) {
        // 0x806F857C: sb          $v1, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r3;
            goto L_806F8544;
    }
    // 0x806F857C: sb          $v1, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r3;
    // 0x806F8580: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x806F8584: addiu       $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x806F8588: bne         $t2, $t4, L_806F8538
    if (ctx->r10 != ctx->r12) {
        // 0x806F858C: addiu       $t3, $t3, 0x3
        ctx->r11 = ADD32(ctx->r11, 0X3);
            goto L_806F8538;
    }
    // 0x806F858C: addiu       $t3, $t3, 0x3
    ctx->r11 = ADD32(ctx->r11, 0X3);
    // 0x806F8590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F8594:
    // 0x806F8594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F8598: jr          $ra
    // 0x806F859C: nop

    return;
    // 0x806F859C: nop

;}
RECOMP_FUNC void func_804D8D68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8D68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8D6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8D70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D8D74: jal         0x80064E84
    // 0x804D8D78: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x804D8D78: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x804D8D7C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x804D8D80: jal         0x80064E84
    // 0x804D8D84: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x804D8D84: lw          $a0, 0x24($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X24);
    after_1:
    // 0x804D8D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8D8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D8D90: jr          $ra
    // 0x804D8D94: nop

    return;
    // 0x804D8D94: nop

;}
RECOMP_FUNC void func_805A3E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A3E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A3E08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805A3E0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A3E10: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x805A3E14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805A3E18: jal         0x805A3690
    // 0x805A3E1C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_805A3690(rdram, ctx);
        goto after_0;
    // 0x805A3E1C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x805A3E20: jal         0x805A33FC
    // 0x805A3E24: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    func_805A33FC(rdram, ctx);
        goto after_1;
    // 0x805A3E24: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x805A3E28: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x805A3E2C: jal         0x805A3558
    // 0x805A3E30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805A3558(rdram, ctx);
        goto after_2;
    // 0x805A3E30: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x805A3E34: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x805A3E38: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x805A3E3C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x805A3E40: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x805A3E44: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x805A3E48: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x805A3E4C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x805A3E50: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x805A3E54: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x805A3E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A3E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A3E60: jr          $ra
    // 0x805A3E64: nop

    return;
    // 0x805A3E64: nop

;}
RECOMP_FUNC void func_8057C4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057C4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057C4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057C4B0: jal         0x8057BB68
    // 0x8057C4B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8057BB68(rdram, ctx);
        goto after_0;
    // 0x8057C4B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8057C4B8: jal         0x8057BD84
    // 0x8057C4BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8057BD84(rdram, ctx);
        goto after_1;
    // 0x8057C4BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8057C4C0: beq         $v0, $zero, L_8057C4D0
    if (ctx->r2 == 0) {
        // 0x8057C4C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8057C4D0;
    }
    // 0x8057C4C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8057C4C8: jal         0x8057C6B0
    // 0x8057C4CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_8057C6B0(rdram, ctx);
        goto after_2;
    // 0x8057C4CC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
L_8057C4D0:
    // 0x8057C4D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057C4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057C4D8: jr          $ra
    // 0x8057C4DC: nop

    return;
    // 0x8057C4DC: nop

;}
RECOMP_FUNC void func_800212D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800212D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800212D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800212DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800212E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800212E4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800212E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800212EC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800212F0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800212F4: addiu       $t8, $t7, 0x90
    ctx->r24 = ADD32(ctx->r15, 0X90);
    // 0x800212F8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x800212FC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80021300: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80021304: addiu       $t1, $t0, 0xA8
    ctx->r9 = ADD32(ctx->r8, 0XA8);
    // 0x80021308: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8002130C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80021310: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x80021314: addiu       $t4, $t3, 0xC0
    ctx->r12 = ADD32(ctx->r11, 0XC0);
    // 0x80021318: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8002131C: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    // 0x80021320: beq         $t5, $zero, L_80021364
    if (ctx->r13 == 0) {
        // 0x80021324: nop
    
            goto L_80021364;
    }
    // 0x80021324: nop

    // 0x80021328: jal         0x80021194
    // 0x8002132C: nop

    func_80021194(rdram, ctx);
        goto after_0;
    // 0x8002132C: nop

    after_0:
    // 0x80021330: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80021334: addiu       $a3, $a3, -0x6540
    ctx->r7 = ADD32(ctx->r7, -0X6540);
    // 0x80021338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002133C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80021340: jal         0x80020F8C
    // 0x80021344: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80020F8C(rdram, ctx);
        goto after_1;
    // 0x80021344: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80021348: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8002134C: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x80021350: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80021354: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80021358: or          $t8, $v0, $t7
    ctx->r24 = ctx->r2 | ctx->r15;
    // 0x8002135C: b           L_8002139C
    // 0x80021360: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
        goto L_8002139C;
    // 0x80021360: sw          $t8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r24;
L_80021364:
    // 0x80021364: jal         0x80021054
    // 0x80021368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80021054(rdram, ctx);
        goto after_2;
    // 0x80021368: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002136C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80021370: addiu       $a3, $a3, -0x6540
    ctx->r7 = ADD32(ctx->r7, -0X6540);
    // 0x80021374: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80021378: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002137C: jal         0x80020EB4
    // 0x80021380: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    func_80020EB4(rdram, ctx);
        goto after_3;
    // 0x80021380: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x80021384: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x80021388: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8002138C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80021390: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80021394: or          $t1, $v0, $t0
    ctx->r9 = ctx->r2 | ctx->r8;
    // 0x80021398: sw          $t1, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r9;
L_8002139C:
    // 0x8002139C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800213A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800213A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800213A8: jr          $ra
    // 0x800213AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800213AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8005FB74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FB74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FB78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FB7C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8005FB80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8005FB84: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005FB88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005FB8C: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x8005FB90: bnel        $t7, $zero, L_8005FBB4
    if (ctx->r15 != 0) {
        // 0x8005FB94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005FBB4;
    }
    goto skip_0;
    // 0x8005FB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005FB98: jal         0x8005F9A8
    // 0x8005FB9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8005F9A8(rdram, ctx);
        goto after_0;
    // 0x8005FB9C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005FBA0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FBA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005FBA8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005FBAC: sb          $t8, 0x79($t9)
    MEM_B(0X79, ctx->r25) = ctx->r24;
    // 0x8005FBB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005FBB4:
    // 0x8005FBB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FBB8: jr          $ra
    // 0x8005FBBC: nop

    return;
    // 0x8005FBBC: nop

;}
RECOMP_FUNC void func_804475B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804475B8: jr          $ra
    // 0x804475BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804475BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806D98EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D98EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D98F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D98F4: jal         0x80059278
    // 0x806D98F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80059278(rdram, ctx);
        goto after_0;
    // 0x806D98F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806D98FC: bnel        $v0, $zero, L_806D9918
    if (ctx->r2 != 0) {
        // 0x806D9900: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_806D9918;
    }
    goto skip_0;
    // 0x806D9900: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x806D9904: jal         0x800447C8
    // 0x806D9908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806D9908: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806D990C: b           L_806D9918
    // 0x806D9910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_806D9918;
    // 0x806D9910: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D9914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D9918:
    // 0x806D9918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D991C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9920: jr          $ra
    // 0x806D9924: nop

    return;
    // 0x806D9924: nop

;}
RECOMP_FUNC void func_8002E6FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E6FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002E700: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E704: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E708: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E70C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002E710: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E714: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8002E718: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8002E71C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x8002E720: jal         0x8002E110
    // 0x8002E724: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    func_8002E110(rdram, ctx);
        goto after_0;
    // 0x8002E724: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    after_0:
    // 0x8002E728: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8002E72C: addiu       $t9, $t9, 0x3450
    ctx->r25 = ADD32(ctx->r25, 0X3450);
    // 0x8002E730: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x8002E734: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002E738: jal         0x8002E274
    // 0x8002E73C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002E274(rdram, ctx);
        goto after_1;
    // 0x8002E73C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8002E740: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002E744: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
    // 0x8002E748: sw          $t0, 0x1A4($t1)
    MEM_W(0X1A4, ctx->r9) = ctx->r8;
    // 0x8002E74C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002E750: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8002E754: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8002E758: beql        $t3, $zero, L_8002E780
    if (ctx->r11 == 0) {
        // 0x8002E75C: lh          $t6, 0x12($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X12);
            goto L_8002E780;
    }
    goto skip_0;
    // 0x8002E75C: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    skip_0:
    // 0x8002E760: lbu         $t4, 0x76($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X76);
    // 0x8002E764: bnel        $t4, $zero, L_8002E780
    if (ctx->r12 != 0) {
        // 0x8002E768: lh          $t6, 0x12($v0)
        ctx->r14 = MEM_H(ctx->r2, 0X12);
            goto L_8002E780;
    }
    goto skip_1;
    // 0x8002E768: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
    skip_1:
    // 0x8002E76C: jal         0x8005FA48
    // 0x8002E770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FA48(rdram, ctx);
        goto after_2;
    // 0x8002E770: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002E774: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8002E778: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8002E77C: lh          $t6, 0x12($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X12);
L_8002E780:
    // 0x8002E780: beq         $t6, $zero, L_8002E79C
    if (ctx->r14 == 0) {
        // 0x8002E784: nop
    
            goto L_8002E79C;
    }
    // 0x8002E784: nop

    // 0x8002E788: lbu         $t7, 0x77($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X77);
    // 0x8002E78C: bne         $t7, $zero, L_8002E79C
    if (ctx->r15 != 0) {
        // 0x8002E790: nop
    
            goto L_8002E79C;
    }
    // 0x8002E790: nop

    // 0x8002E794: jal         0x8005FAE0
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FAE0(rdram, ctx);
        goto after_3;
    // 0x8002E798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8002E79C:
    // 0x8002E79C: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002E7A0: addiu       $t8, $t8, 0x33B4
    ctx->r24 = ADD32(ctx->r24, 0X33B4);
    // 0x8002E7A4: jal         0x8002AFA0
    // 0x8002E7A8: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    func_8002AFA0(rdram, ctx);
        goto after_4;
    // 0x8002E7A8: sw          $t8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r24;
    after_4:
    // 0x8002E7AC: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002E7B0: sw          $zero, 0xD8($t9)
    MEM_W(0XD8, ctx->r25) = 0;
    // 0x8002E7B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E7B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E7BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002E7C0: jr          $ra
    // 0x8002E7C4: nop

    return;
    // 0x8002E7C4: nop

;}
RECOMP_FUNC void func_80558030(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558030: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80558034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80558038: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8055803C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80558040: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80558044: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80558048: addiu       $a2, $a2, -0x3108
    ctx->r6 = ADD32(ctx->r6, -0X3108);
    // 0x8055804C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80558050: nop

    // 0x80558054: bc1fl       L_80558080
    if (!c1cs) {
        // 0x80558058: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80558080;
    }
    goto skip_0;
    // 0x80558058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8055805C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80558060: jal         0x8004D1F0
    // 0x80558064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80558064: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80558068: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8055806C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80558070: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80558074: jal         0x8004D698
    // 0x80558078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80558078: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8055807C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80558080:
    // 0x80558080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80558084: jr          $ra
    // 0x80558088: nop

    return;
    // 0x80558088: nop

;}
RECOMP_FUNC void func_8003271C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003271C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80032720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80032724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80032728: lbu         $t6, 0x154($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X154);
    // 0x8003272C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80032730: beql        $t6, $zero, L_800327AC
    if (ctx->r14 == 0) {
        // 0x80032734: lbu         $t0, 0x155($s0)
        ctx->r8 = MEM_BU(ctx->r16, 0X155);
            goto L_800327AC;
    }
    goto skip_0;
    // 0x80032734: lbu         $t0, 0x155($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X155);
    skip_0:
    // 0x80032738: lbu         $t7, 0x155($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X155);
    // 0x8003273C: beql        $t7, $zero, L_80032758
    if (ctx->r15 == 0) {
        // 0x80032740: lbu         $t8, 0x18($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X18);
            goto L_80032758;
    }
    goto skip_1;
    // 0x80032740: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
    skip_1:
    // 0x80032744: jal         0x80032564
    // 0x80032748: nop

    func_80032564(rdram, ctx);
        goto after_0;
    // 0x80032748: nop

    after_0:
    // 0x8003274C: b           L_800327A0
    // 0x80032750: nop

        goto L_800327A0;
    // 0x80032750: nop

    // 0x80032754: lbu         $t8, 0x18($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X18);
L_80032758:
    // 0x80032758: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003275C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80032760: bne         $t8, $at, L_80032788
    if (ctx->r24 != ctx->r1) {
        // 0x80032764: nop
    
            goto L_80032788;
    }
    // 0x80032764: nop

    // 0x80032768: lbu         $t9, 0x30($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X30);
    // 0x8003276C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80032770: bne         $t9, $at, L_80032788
    if (ctx->r25 != ctx->r1) {
        // 0x80032774: nop
    
            goto L_80032788;
    }
    // 0x80032774: nop

    // 0x80032778: jal         0x8003D76C
    // 0x8003277C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003D76C(rdram, ctx);
        goto after_1;
    // 0x8003277C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80032780: b           L_800327A0
    // 0x80032784: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
        goto L_800327A0;
    // 0x80032784: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
L_80032788:
    // 0x80032788: jal         0x800323A4
    // 0x8003278C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800323A4(rdram, ctx);
        goto after_2;
    // 0x8003278C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80032790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80032794: jal         0x8003D76C
    // 0x80032798: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8003D76C(rdram, ctx);
        goto after_3;
    // 0x80032798: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8003279C: sb          $zero, 0x156($s0)
    MEM_B(0X156, ctx->r16) = 0;
L_800327A0:
    // 0x800327A0: b           L_800327BC
    // 0x800327A4: sb          $zero, 0x154($s0)
    MEM_B(0X154, ctx->r16) = 0;
        goto L_800327BC;
    // 0x800327A4: sb          $zero, 0x154($s0)
    MEM_B(0X154, ctx->r16) = 0;
    // 0x800327A8: lbu         $t0, 0x155($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X155);
L_800327AC:
    // 0x800327AC: beql        $t0, $zero, L_800327C0
    if (ctx->r8 == 0) {
        // 0x800327B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800327C0;
    }
    goto skip_2;
    // 0x800327B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800327B4: jal         0x80032C5C
    // 0x800327B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80032C5C(rdram, ctx);
        goto after_4;
    // 0x800327B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
L_800327BC:
    // 0x800327BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800327C0:
    // 0x800327C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800327C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800327C8: jr          $ra
    // 0x800327CC: nop

    return;
    // 0x800327CC: nop

;}
RECOMP_FUNC void func_8006B284(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B284: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006B288: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x8006B28C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006B290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006B294: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8006B298: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8006B29C: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006B2A0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8006B2A4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x8006B2A8: lw          $t9, 0x16C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X16C);
    // 0x8006B2AC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B2B0: lw          $t0, 0x1B0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1B0);
    // 0x8006B2B4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8006B2B8: lw          $t1, 0x20($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X20);
    // 0x8006B2BC: jal         0x8006A99C
    // 0x8006B2C0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8006B2C0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8006B2C4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006B2C8: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x8006B2CC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8006B2D0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8006B2D4: nop

    // 0x8006B2D8: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8006B2DC: jal         0x8006A99C
    // 0x8006B2E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8006B2E0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x8006B2E4: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8006B2E8: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8006B2EC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006B2F0: jal         0x8006AA18
    // 0x8006B2F4: lh          $a1, 0x18($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X18);
    func_8006AA18(rdram, ctx);
        goto after_2;
    // 0x8006B2F4: lh          $a1, 0x18($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X18);
    after_2:
    // 0x8006B2F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006B2FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006B300: jr          $ra
    // 0x8006B304: nop

    return;
    // 0x8006B304: nop

;}
RECOMP_FUNC void func_806FD9C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FD9C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FD9C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FD9CC: jal         0x8004700C
    // 0x806FD9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806FD9D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FD9D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FD9D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806FD9DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x806FD9E0: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
    // 0x806FD9E4: beq         $v0, $zero, L_806FDA4C
    if (ctx->r2 == 0) {
        // 0x806FD9E8: swc1        $f2, 0xEC($a0)
        MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
            goto L_806FDA4C;
    }
    // 0x806FD9E8: swc1        $f2, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f2.u32l;
    // 0x806FD9EC: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x806FD9F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806FD9F4: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806FD9F8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x806FD9FC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806FDA00: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806FDA04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806FDA08: nop

    // 0x806FDA0C: bc1tl       L_806FDA50
    if (c1cs) {
        // 0x806FDA10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806FDA50;
    }
    goto skip_0;
    // 0x806FDA10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806FDA14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x806FDA18: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x806FDA1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806FDA20: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806FDA24: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x806FDA28: bc1fl       L_806FDA38
    if (!c1cs) {
        // 0x806FDA2C: add.s       $f4, $f0, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
            goto L_806FDA38;
    }
    goto skip_1;
    // 0x806FDA2C: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    skip_1:
    // 0x806FDA30: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806FDA34: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
L_806FDA38:
    // 0x806FDA38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806FDA3C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806FDA40: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806FDA44: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x806FDA48: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
L_806FDA4C:
    // 0x806FDA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806FDA50:
    // 0x806FDA50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FDA54: jr          $ra
    // 0x806FDA58: nop

    return;
    // 0x806FDA58: nop

;}
RECOMP_FUNC void func_8045FCE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FCE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8045FCE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045FCE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045FCEC: jal         0x8045FD6C
    // 0x8045FCF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8045FD6C(rdram, ctx);
        goto after_0;
    // 0x8045FCF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8045FCF4: beq         $v0, $zero, L_8045FD50
    if (ctx->r2 == 0) {
        // 0x8045FCF8: nop
    
            goto L_8045FD50;
    }
    // 0x8045FCF8: nop

    // 0x8045FCFC: jal         0x8045FD78
    // 0x8045FD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8045FD78(rdram, ctx);
        goto after_1;
    // 0x8045FD00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8045FD04: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8045FD08: lui         $t6, 0x8046
    ctx->r14 = S32(RELOC_HI16(116, 0X35C) << 16);
    // 0x8045FD0C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8045FD10: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8045FD14: addiu       $t6, $t6, 0x2C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(116, 0X35C));
    // 0x8045FD18: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8045FD1C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8045FD20: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8045FD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045FD28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8045FD2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8045FD30: jal         0x8045FF6C
    // 0x8045FD34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8045FF6C(rdram, ctx);
        goto after_2;
    // 0x8045FD34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8045FD38: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x8045FD3C: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(116, 0X184) << 16);
    // 0x8045FD40: addiu       $t8, $t8, -0x1AC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(116, 0X184));
    // 0x8045FD44: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
    // 0x8045FD48: b           L_8045FD58
    // 0x8045FD4C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
        goto L_8045FD58;
    // 0x8045FD4C: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8045FD50:
    // 0x8045FD50: jal         0x800445A4
    // 0x8045FD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8045FD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8045FD58:
    // 0x8045FD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045FD5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045FD60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8045FD64: jr          $ra
    // 0x8045FD68: nop

    return;
    // 0x8045FD68: nop

;}
RECOMP_FUNC void func_8059EA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EA50: lui         $v0, 0x805A
    ctx->r2 = S32(RELOC_HI16(405, 0X28) << 16);
    // 0x8059EA54: addiu       $v0, $v0, -0x1588
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(405, 0X28));
    // 0x8059EA58: jr          $ra
    // 0x8059EA5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8059EA5C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80673590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80673590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80673594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80673598: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8067359C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806735A0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806735A4: jal         0x8005FCA8
    // 0x806735A8: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x806735A8: sh          $t6, 0x12($t8)
    MEM_H(0X12, ctx->r24) = ctx->r14;
    after_0:
    // 0x806735AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806735B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806735B4: jr          $ra
    // 0x806735B8: nop

    return;
    // 0x806735B8: nop

;}
RECOMP_FUNC void func_8000BDA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BDA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BDA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BDA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000BDAC: jal         0x8000BD90
    // 0x8000BDB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8000BD90(rdram, ctx);
        goto after_0;
    // 0x8000BDB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8000BDB4: jal         0x8000BD90
    // 0x8000BDB8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_8000BD90(rdram, ctx);
        goto after_1;
    // 0x8000BDB8: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_1:
    // 0x8000BDBC: jal         0x8000BD90
    // 0x8000BDC0: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    func_8000BD90(rdram, ctx);
        goto after_2;
    // 0x8000BDC0: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    after_2:
    // 0x8000BDC4: jal         0x8000BD90
    // 0x8000BDC8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    func_8000BD90(rdram, ctx);
        goto after_3;
    // 0x8000BDC8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    after_3:
    // 0x8000BDCC: sw          $s0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r16;
    // 0x8000BDD0: sw          $s0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r16;
    // 0x8000BDD4: sw          $s0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r16;
    // 0x8000BDD8: sw          $s0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r16;
    // 0x8000BDDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BDE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000BDE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000BDE8: jr          $ra
    // 0x8000BDEC: nop

    return;
    // 0x8000BDEC: nop

;}
RECOMP_FUNC void func_8042F2C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F2C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042F2C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042F2C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8042F2CC: jal         0x8004700C
    // 0x8042F2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8042F2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8042F2D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8042F2D8: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8042F2DC: jal         0x80048F84
    // 0x8042F2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8042F2E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8042F2E4: jal         0x8042E198
    // 0x8042F2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042E198(rdram, ctx);
        goto after_2;
    // 0x8042F2E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8042F2EC: jal         0x8042F134
    // 0x8042F2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8042F134(rdram, ctx);
        goto after_3;
    // 0x8042F2F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8042F2F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8042F2F8: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8042F2FC: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042F300: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8042F304: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8042F308: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8042F30C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8042F310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042F314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8042F318: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8042F31C: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8042F320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8042F324: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042F328: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8042F32C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8042F330: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8042F334: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8042F338: nop

    // 0x8042F33C: bc1fl       L_8042F370
    if (!c1cs) {
        // 0x8042F340: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8042F370;
    }
    goto skip_0;
    // 0x8042F340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8042F344: jal         0x8042F574
    // 0x8042F348: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8042F574(rdram, ctx);
        goto after_4;
    // 0x8042F348: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8042F34C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8042F350: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042F354: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8042F358: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042F35C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8042F360: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8042F364: swc1        $f10, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f10.u32l;
    // 0x8042F368: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
    // 0x8042F36C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8042F370:
    // 0x8042F370: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8042F374: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042F378: jr          $ra
    // 0x8042F37C: nop

    return;
    // 0x8042F37C: nop

;}
RECOMP_FUNC void func_807A5E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A5E50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807A5E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807A5E58: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x807A5E5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807A5E60: lwc1        $f0, 0x88($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X88);
    // 0x807A5E64: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807A5E68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x807A5E6C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x807A5E70: nop

    // 0x807A5E74: bc1fl       L_807A5E88
    if (!c1cs) {
        // 0x807A5E78: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_807A5E88;
    }
    goto skip_0;
    // 0x807A5E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x807A5E7C: b           L_807A5F18
    // 0x807A5E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807A5F18;
    // 0x807A5E80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807A5E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_807A5E88:
    // 0x807A5E88: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(847, 0X1484) << 16);
    // 0x807A5E8C: lui         $a1, 0x807A
    ctx->r5 = S32(RELOC_HI16(847, 0X148C) << 16);
    // 0x807A5E90: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x807A5E94: addiu       $a1, $a1, 0x718C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(847, 0X148C));
    // 0x807A5E98: addiu       $a0, $a0, 0x7184
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(847, 0X1484));
    // 0x807A5E9C: bc1fl       L_807A5EB0
    if (!c1cs) {
        // 0x807A5EA0: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_807A5EB0;
    }
    goto skip_1;
    // 0x807A5EA0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x807A5EA4: b           L_807A5F18
    // 0x807A5EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807A5F18;
    // 0x807A5EA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807A5EAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_807A5EB0:
    // 0x807A5EB0: jal         0x807A5E24
    // 0x807A5EB4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_807A5E24(rdram, ctx);
        goto after_0;
    // 0x807A5EB4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807A5EB8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807A5EBC: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(847, 0X1494) << 16);
    // 0x807A5EC0: lui         $a1, 0x807A
    ctx->r5 = S32(RELOC_HI16(847, 0X149C) << 16);
    // 0x807A5EC4: lwc1        $f8, 0x84($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X84);
    // 0x807A5EC8: addiu       $a1, $a1, 0x719C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(847, 0X149C));
    // 0x807A5ECC: addiu       $a0, $a0, 0x7194
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(847, 0X1494));
    // 0x807A5ED0: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x807A5ED4: nop

    // 0x807A5ED8: bc1fl       L_807A5EEC
    if (!c1cs) {
        // 0x807A5EDC: lw          $a2, 0x88($a3)
        ctx->r6 = MEM_W(ctx->r7, 0X88);
            goto L_807A5EEC;
    }
    goto skip_2;
    // 0x807A5EDC: lw          $a2, 0x88($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X88);
    skip_2:
    // 0x807A5EE0: b           L_807A5F18
    // 0x807A5EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807A5F18;
    // 0x807A5EE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807A5EE8: lw          $a2, 0x88($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X88);
L_807A5EEC:
    // 0x807A5EEC: jal         0x807A5E24
    // 0x807A5EF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_807A5E24(rdram, ctx);
        goto after_1;
    // 0x807A5EF0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x807A5EF4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x807A5EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807A5EFC: lwc1        $f10, 0x84($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X84);
    // 0x807A5F00: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x807A5F04: nop

    // 0x807A5F08: bc1f        L_807A5F18
    if (!c1cs) {
        // 0x807A5F0C: nop
    
            goto L_807A5F18;
    }
    // 0x807A5F0C: nop

    // 0x807A5F10: b           L_807A5F18
    // 0x807A5F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807A5F18;
    // 0x807A5F14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807A5F18:
    // 0x807A5F18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807A5F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807A5F20: jr          $ra
    // 0x807A5F24: nop

    return;
    // 0x807A5F24: nop

;}
RECOMP_FUNC void func_80046324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046324: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80046328: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004632C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80046330: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80046334: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80046338: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8004633C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80046340: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80046344: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80046348: lw          $s0, 0x8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X8);
    // 0x8004634C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80046350: blez        $v0, L_80046390
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046354: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80046390;
    }
    // 0x80046354: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80046358: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8004635C:
    // 0x8004635C: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x80046360: beql        $s2, $t6, L_80046380
    if (ctx->r18 == ctx->r14) {
        // 0x80046364: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80046380;
    }
    goto skip_0;
    // 0x80046364: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    skip_0:
    // 0x80046368: jal         0x80045B64
    // 0x8004636C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_80045B64(rdram, ctx);
        goto after_0;
    // 0x8004636C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_0:
    // 0x80046370: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x80046374: b           L_80046380
    // 0x80046378: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
        goto L_80046380;
    // 0x80046378: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8004637C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80046380:
    // 0x80046380: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80046384: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80046388: bne         $at, $zero, L_8004635C
    if (ctx->r1 != 0) {
        // 0x8004638C: addiu       $s0, $s0, 0x280
        ctx->r16 = ADD32(ctx->r16, 0X280);
            goto L_8004635C;
    }
    // 0x8004638C: addiu       $s0, $s0, 0x280
    ctx->r16 = ADD32(ctx->r16, 0X280);
L_80046390:
    // 0x80046390: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80046394: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80046398: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8004639C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800463A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800463A4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800463A8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800463AC: jr          $ra
    // 0x800463B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800463B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8040C0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C0A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C0A8: jal         0x8040C444
    // 0x8040C0AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8040C444(rdram, ctx);
        goto after_0;
    // 0x8040C0AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040C0B0: beq         $v0, $zero, L_8040C10C
    if (ctx->r2 == 0) {
        // 0x8040C0B4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8040C10C;
    }
    // 0x8040C0B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040C0B8: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8040C0BC: lui         $t6, 0x8041
    ctx->r14 = S32(RELOC_HI16(17, 0X168) << 16);
    // 0x8040C0C0: addiu       $t6, $t6, -0x3E08
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(17, 0X168));
    // 0x8040C0C4: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x8040C0C8: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040C0CC: addiu       $t8, $zero, 0x140
    ctx->r24 = ADD32(0, 0X140);
    // 0x8040C0D0: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(17, 0X4BC) << 16);
    // 0x8040C0D4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8040C0D8: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x8040C0DC: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8040C0E0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8040C0E4: addiu       $t0, $t0, -0x3AB4
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(17, 0X4BC));
    // 0x8040C0E8: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8040C0EC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8040C0F0: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x8040C0F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040C0F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040C0FC: jal         0x8040C4B0
    // 0x8040C100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8040C4B0(rdram, ctx);
        goto after_1;
    // 0x8040C100: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8040C104: b           L_8040C118
    // 0x8040C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8040C118;
    // 0x8040C108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C10C:
    // 0x8040C10C: jal         0x800445A4
    // 0x8040C110: nop

    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8040C110: nop

    after_2:
    // 0x8040C114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C118:
    // 0x8040C118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C11C: jr          $ra
    // 0x8040C120: nop

    return;
    // 0x8040C120: nop

;}
RECOMP_FUNC void func_800484EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800484EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800484F0: bne         $a0, $zero, L_80048510
    if (ctx->r4 != 0) {
        // 0x800484F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80048510;
    }
    // 0x800484F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800484F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800484FC: addiu       $a0, $a0, 0x800
    ctx->r4 = ADD32(ctx->r4, 0X800);
    // 0x80048500: jal         0x80071380
    // 0x80048504: addiu       $a1, $zero, 0xAC9
    ctx->r5 = ADD32(0, 0XAC9);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048504: addiu       $a1, $zero, 0xAC9
    ctx->r5 = ADD32(0, 0XAC9);
    after_0:
    // 0x80048508: b           L_8004853C
    // 0x8004850C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004853C;
    // 0x8004850C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048510:
    // 0x80048510: bne         $a1, $zero, L_80048530
    if (ctx->r5 != 0) {
        // 0x80048514: nop
    
            goto L_80048530;
    }
    // 0x80048514: nop

    // 0x80048518: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004851C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    // 0x80048520: jal         0x80071380
    // 0x80048524: addiu       $a1, $zero, 0xAD0
    ctx->r5 = ADD32(0, 0XAD0);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80048524: addiu       $a1, $zero, 0xAD0
    ctx->r5 = ADD32(0, 0XAD0);
    after_1:
    // 0x80048528: b           L_8004853C
    // 0x8004852C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8004853C;
    // 0x8004852C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80048530:
    // 0x80048530: jal         0x80065528
    // 0x80048534: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    func_80065528(rdram, ctx);
        goto after_2;
    // 0x80048534: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    after_2:
    // 0x80048538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004853C:
    // 0x8004853C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80048540: jr          $ra
    // 0x80048544: nop

    return;
    // 0x80048544: nop

;}
RECOMP_FUNC void func_8003841C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003841C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038424: jal         0x80021958
    // 0x80038428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80038428: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003842C: bne         $v0, $zero, L_8003843C
    if (ctx->r2 != 0) {
        // 0x80038430: nop
    
            goto L_8003843C;
    }
    // 0x80038430: nop

    // 0x80038434: b           L_80038470
    // 0x80038438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038470;
    // 0x80038438: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003843C:
    // 0x8003843C: jal         0x800415FC
    // 0x80038440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x80038440: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80038444: beq         $v0, $zero, L_80038454
    if (ctx->r2 == 0) {
        // 0x80038448: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80038454;
    }
    // 0x80038448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003844C: b           L_80038470
    // 0x80038450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038470;
    // 0x80038450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80038454:
    // 0x80038454: jal         0x8003790C
    // 0x80038458: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    func_8003790C(rdram, ctx);
        goto after_2;
    // 0x80038458: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x8003845C: bnel        $v0, $zero, L_80038470
    if (ctx->r2 != 0) {
        // 0x80038460: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038470;
    }
    goto skip_0;
    // 0x80038460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80038464: b           L_80038470
    // 0x80038468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038470;
    // 0x80038468: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003846C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038470:
    // 0x80038470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038478: jr          $ra
    // 0x8003847C: nop

    return;
    // 0x8003847C: nop

;}
RECOMP_FUNC void func_8001C4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C4F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001C4F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001C4F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C4FC: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8001C500: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001C504: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8001C508: jal         0x80081C64
    // 0x8001C50C: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8001C50C: lwc1        $f12, 0x44($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X44);
    after_0:
    // 0x8001C510: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8001C514: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8001C518: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001C51C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8001C520: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8001C524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001C528: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001C52C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C530: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8001C534: div.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001C538: lui         $a1, 0x8002
    ctx->r5 = S32(0X8002 << 16);
    // 0x8001C53C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001C540: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8001C544: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001C548: addiu       $a1, $a1, -0x3BEC
    ctx->r5 = ADD32(ctx->r5, -0X3BEC);
    // 0x8001C54C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C550: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8001C554: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8001C558: div.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8001C55C: jal         0x8006E154
    // 0x8001C560: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_8006E154(rdram, ctx);
        goto after_1;
    // 0x8001C560: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8001C564: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8001C568: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001C56C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001C570: lbu         $t7, 0x24($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X24);
    // 0x8001C574: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8001C578: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8001C57C: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8001C580: sb          $t9, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r25;
    // 0x8001C584: swc1        $f12, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f12.u32l;
    // 0x8001C588: jal         0x80045A34
    // 0x8001C58C: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x8001C58C: swc1        $f12, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f12.u32l;
    after_2:
    // 0x8001C590: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8001C594: lui         $t0, 0xEDCB
    ctx->r8 = S32(0XEDCB << 16);
    // 0x8001C598: lui         $t1, 0x8007
    ctx->r9 = S32(0X8007 << 16);
    // 0x8001C59C: ori         $t0, $t0, 0xA987
    ctx->r8 = ctx->r8 | 0XA987;
    // 0x8001C5A0: addiu       $t1, $t1, -0x1BBC
    ctx->r9 = ADD32(ctx->r9, -0X1BBC);
    // 0x8001C5A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8001C5A8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8001C5AC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8001C5B0: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8001C5B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C5B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C5BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001C5C0: jr          $ra
    // 0x8001C5C4: nop

    return;
    // 0x8001C5C4: nop

    // 0x8001C5C8: nop

    // 0x8001C5CC: nop

;}
RECOMP_FUNC void func_805AB24C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB24C: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB0C) << 16);
    // 0x805AB250: lwc1        $f4, -0x45B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB0C));
    // 0x805AB254: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x805AB258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805AB25C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x805AB260: sb          $t6, 0x26C($a1)
    MEM_B(0X26C, ctx->r5) = ctx->r14;
    // 0x805AB264: sb          $zero, 0x26D($a1)
    MEM_B(0X26D, ctx->r5) = 0;
    // 0x805AB268: swc1        $f4, 0x274($a1)
    MEM_W(0X274, ctx->r5) = ctx->f4.u32l;
    // 0x805AB26C: swc1        $f6, 0x270($a1)
    MEM_W(0X270, ctx->r5) = ctx->f6.u32l;
    // 0x805AB270: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805AB274: jr          $ra
    // 0x805AB278: swc1        $f8, 0x278($a1)
    MEM_W(0X278, ctx->r5) = ctx->f8.u32l;
    return;
    // 0x805AB278: swc1        $f8, 0x278($a1)
    MEM_W(0X278, ctx->r5) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80671C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80671C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80671C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80671CA0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80671CA4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80671CA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80671CAC: lw          $s0, 0x1E0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1E0);
    // 0x80671CB0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80671CB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671CB8: sra         $s0, $s0, 1
    ctx->r16 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80671CBC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80671CC0: beq         $a1, $zero, L_80671CEC
    if (ctx->r5 == 0) {
        // 0x80671CC4: andi        $s0, $s0, 0xFFFF
        ctx->r16 = ctx->r16 & 0XFFFF;
            goto L_80671CEC;
    }
    // 0x80671CC4: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80671CC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80671CCC: beq         $a1, $at, L_80671CFC
    if (ctx->r5 == ctx->r1) {
        // 0x80671CD0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80671CFC;
    }
    // 0x80671CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80671CD4: beq         $a1, $at, L_80671D10
    if (ctx->r5 == ctx->r1) {
        // 0x80671CD8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80671D10;
    }
    // 0x80671CD8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80671CDC: beql        $a1, $at, L_80671D28
    if (ctx->r5 == ctx->r1) {
        // 0x80671CE0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80671D28;
    }
    goto skip_0;
    // 0x80671CE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x80671CE4: b           L_80671D3C
    // 0x80671CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80671D3C;
    // 0x80671CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80671CEC:
    // 0x80671CEC: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671CF0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80671CF4: jal         0x8005C27C
    // 0x80671CF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x80671CF8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_0:
L_80671CFC:
    // 0x80671CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671D00: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671D04: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80671D08: jal         0x8005C27C
    // 0x80671D0C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x80671D0C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_1:
L_80671D10:
    // 0x80671D10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80671D14: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671D18: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80671D1C: jal         0x8005C27C
    // 0x80671D20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x80671D20: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80671D24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80671D28:
    // 0x80671D28: andi        $a1, $s0, 0xFFFF
    ctx->r5 = ctx->r16 & 0XFFFF;
    // 0x80671D2C: addiu       $a2, $zero, 0x48
    ctx->r6 = ADD32(0, 0X48);
    // 0x80671D30: jal         0x8005C27C
    // 0x80671D34: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8005C27C(rdram, ctx);
        goto after_3;
    // 0x80671D34: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80671D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80671D3C:
    // 0x80671D3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80671D40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80671D44: jr          $ra
    // 0x80671D48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80671D48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8042231C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042231C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80422320: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80422324: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80422328: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8042232C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80422330: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80422334: addiu       $a1, $zero, 0x8A0
    ctx->r5 = ADD32(0, 0X8A0);
    // 0x80422338: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8042233C: jal         0x80065728
    // 0x80422340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80422340: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80422344: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80422348: addiu       $v0, $s0, 0x10
    ctx->r2 = ADD32(ctx->r16, 0X10);
    // 0x8042234C: addiu       $v1, $s0, 0x790
    ctx->r3 = ADD32(ctx->r16, 0X790);
    // 0x80422350: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80422354: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80422358: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8042235C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80422360: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x80422364: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80422368: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8042236C: beq         $a0, $a1, L_804223E4
    if (ctx->r4 == ctx->r5) {
        // 0x80422370: lw          $t6, 0x138($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X138);
            goto L_804223E4;
    }
    // 0x80422370: lw          $t6, 0x138($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X138);
L_80422374:
    // 0x80422374: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80422378: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8042237C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80422380: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80422384: swc1        $f18, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f18.u32l;
    // 0x80422388: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8042238C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80422390: swc1        $f18, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f18.u32l;
    // 0x80422394: lw          $t7, 0x138($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X138);
    // 0x80422398: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x8042239C: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x804223A0: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x804223A4: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x804223A8: swc1        $f18, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f18.u32l;
    // 0x804223AC: lw          $t8, 0x138($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X138);
    // 0x804223B0: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x804223B4: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x804223B8: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x804223BC: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x804223C0: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x804223C4: lw          $t9, 0x138($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X138);
    // 0x804223C8: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x804223CC: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x804223D0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x804223D4: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x804223D8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x804223DC: bne         $a0, $a1, L_80422374
    if (ctx->r4 != ctx->r5) {
        // 0x804223E0: lw          $t6, 0x138($a3)
        ctx->r14 = MEM_W(ctx->r7, 0X138);
            goto L_80422374;
    }
    // 0x804223E0: lw          $t6, 0x138($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X138);
L_804223E4:
    // 0x804223E4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x804223E8: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x804223EC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x804223F0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804223F4: swc1        $f18, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f18.u32l;
    // 0x804223F8: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x804223FC: swc1        $f18, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f18.u32l;
    // 0x80422400: lw          $t7, 0x138($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X138);
    // 0x80422404: sb          $t7, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r15;
    // 0x80422408: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8042240C: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80422410: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80422414: swc1        $f18, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f18.u32l;
    // 0x80422418: lw          $t8, 0x138($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X138);
    // 0x8042241C: sb          $t8, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r24;
    // 0x80422420: lwc1        $f18, 0x3C($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80422424: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x80422428: lwc1        $f18, 0x40($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8042242C: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80422430: lw          $t9, 0x138($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X138);
    // 0x80422434: sb          $t9, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r25;
    // 0x80422438: addiu       $t0, $zero, 0xC0
    ctx->r8 = ADD32(0, 0XC0);
    // 0x8042243C: sw          $t0, 0x880($s0)
    MEM_W(0X880, ctx->r16) = ctx->r8;
    // 0x80422440: sw          $zero, 0x884($s0)
    MEM_W(0X884, ctx->r16) = 0;
    // 0x80422444: sw          $zero, 0x888($s0)
    MEM_W(0X888, ctx->r16) = 0;
    // 0x80422448: lwc1        $f8, 0x6C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X6C);
    // 0x8042244C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80422450: swc1        $f8, 0x88C($s0)
    MEM_W(0X88C, ctx->r16) = ctx->f8.u32l;
    // 0x80422454: lwc1        $f10, 0x70($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X70);
    // 0x80422458: swc1        $f10, 0x890($s0)
    MEM_W(0X890, ctx->r16) = ctx->f10.u32l;
    // 0x8042245C: lwc1        $f16, 0x74($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X74);
    // 0x80422460: sw          $t1, 0x89C($s0)
    MEM_W(0X89C, ctx->r16) = ctx->r9;
    // 0x80422464: swc1        $f16, 0x894($s0)
    MEM_W(0X894, ctx->r16) = ctx->f16.u32l;
    // 0x80422468: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8042246C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80422470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80422474: jr          $ra
    // 0x80422478: nop

    return;
    // 0x80422478: nop

;}
RECOMP_FUNC void func_8005A894(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A894: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8005A898: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8005A89C: lw          $t6, 0x970($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X970);
    // 0x8005A8A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A8A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A8A8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8005A8AC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005A8B0: bnel        $t8, $zero, L_8005A8C4
    if (ctx->r24 != 0) {
        // 0x8005A8B4: lw          $t9, 0x3F4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X3F4);
            goto L_8005A8C4;
    }
    goto skip_0;
    // 0x8005A8B4: lw          $t9, 0x3F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3F4);
    skip_0:
    // 0x8005A8B8: b           L_8005A928
    // 0x8005A8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A928;
    // 0x8005A8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A8C0: lw          $t9, 0x3F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3F4);
L_8005A8C4:
    // 0x8005A8C4: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8005A8C8: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x8005A8CC: jal         0x8005A874
    // 0x8005A8D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8005A874(rdram, ctx);
        goto after_0;
    // 0x8005A8D0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005A8D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005A8D8: lw          $t9, 0xEC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XEC);
    // 0x8005A8DC: jalr        $t9
    // 0x8005A8E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8005A8E0: nop

    after_1:
    // 0x8005A8E4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8005A8E8: beq         $v0, $zero, L_8005A8FC
    if (ctx->r2 == 0) {
        // 0x8005A8EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005A8FC;
    }
    // 0x8005A8EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005A8F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8005A8F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A8F8: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_8005A8FC:
    // 0x8005A8FC: lw          $v0, 0xF4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XF4);
    // 0x8005A900: beql        $v0, $zero, L_8005A928
    if (ctx->r2 == 0) {
        // 0x8005A904: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8005A928;
    }
    goto skip_1;
    // 0x8005A904: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8005A908: jalr        $v0
    // 0x8005A90C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8005A90C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8005A910: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A914: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8005A918: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A91C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x8005A920: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8005A924: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005A928:
    // 0x8005A928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A92C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A930: jr          $ra
    // 0x8005A934: nop

    return;
    // 0x8005A934: nop

;}
RECOMP_FUNC void func_8068152C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8068152C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80681530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80681534: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80681538: jal         0x806814D0
    // 0x8068153C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806814D0(rdram, ctx);
        goto after_0;
    // 0x8068153C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80681540: bne         $v0, $zero, L_80681550
    if (ctx->r2 != 0) {
        // 0x80681544: lui         $t6, 0x8068
        ctx->r14 = S32(RELOC_HI16(550, 0XF24) << 16);
            goto L_80681550;
    }
    // 0x80681544: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0XF24) << 16);
    // 0x80681548: b           L_806815A4
    // 0x8068154C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806815A4;
    // 0x8068154C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80681550:
    // 0x80681550: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x80681554: addiu       $t6, $t6, 0x1334
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0XF24));
    // 0x80681558: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(550, 0X21EC) << 16);
    // 0x8068155C: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
    // 0x80681560: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x80681564: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80681568: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8068156C: addiu       $t8, $t8, 0x25FC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(550, 0X21EC));
    // 0x80681570: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80681574: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80681578: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8068157C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80681580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80681584: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80681588: jal         0x806815B8
    // 0x8068158C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806815B8(rdram, ctx);
        goto after_1;
    // 0x8068158C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80681590: jal         0x80681428
    // 0x80681594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80681428(rdram, ctx);
        goto after_2;
    // 0x80681594: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80681598: jal         0x80681514
    // 0x8068159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80681514(rdram, ctx);
        goto after_3;
    // 0x8068159C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806815A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806815A4:
    // 0x806815A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806815A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806815AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806815B0: jr          $ra
    // 0x806815B4: nop

    return;
    // 0x806815B4: nop

;}
RECOMP_FUNC void func_8068195C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8068195C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80681960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80681964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80681968: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8068196C: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X1434) << 16);
    // 0x80681970: addiu       $t6, $t6, 0x1844
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X1434));
    // 0x80681974: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(550, 0X2200) << 16);
    // 0x80681978: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8068197C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80681980: addiu       $t7, $t7, 0x2610
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(550, 0X2200));
    // 0x80681984: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80681988: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8068198C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80681990: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x80681994: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80681998: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8068199C: jal         0x806819DC
    // 0x806819A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806819DC(rdram, ctx);
        goto after_0;
    // 0x806819A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806819A4: jal         0x8068098C
    // 0x806819A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8068098C(rdram, ctx);
        goto after_1;
    // 0x806819A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806819AC: jal         0x80681944
    // 0x806819B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80681944(rdram, ctx);
        goto after_2;
    // 0x806819B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806819B4: jal         0x80681894
    // 0x806819B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80681894(rdram, ctx);
        goto after_3;
    // 0x806819B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806819BC: bne         $v0, $zero, L_806819CC
    if (ctx->r2 != 0) {
        // 0x806819C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806819CC;
    }
    // 0x806819C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806819C4: b           L_806819D0
    // 0x806819C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806819D0;
    // 0x806819C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806819CC:
    // 0x806819CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806819D0:
    // 0x806819D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806819D4: jr          $ra
    // 0x806819D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806819D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80050210(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80050214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80050218: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005021C: lw          $t6, 0x1B8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B8);
    // 0x80050220: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80050224: beql        $t6, $zero, L_8005024C
    if (ctx->r14 == 0) {
        // 0x80050228: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005024C;
    }
    goto skip_0;
    // 0x80050228: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005022C: jal         0x8004FC28
    // 0x80050230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004FC28(rdram, ctx);
        goto after_0;
    // 0x80050230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80050234: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80050238: jal         0x80050128
    // 0x8005023C: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    func_80050128(rdram, ctx);
        goto after_1;
    // 0x8005023C: lhu         $a1, 0x1E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X1E);
    after_1:
    // 0x80050240: jal         0x8004F26C
    // 0x80050244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8004F26C(rdram, ctx);
        goto after_2;
    // 0x80050244: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80050248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005024C:
    // 0x8005024C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80050250: jr          $ra
    // 0x80050254: nop

    return;
    // 0x80050254: nop

;}
RECOMP_FUNC void func_80407B24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80407B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80407B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80407B2C: jal         0x80407BF4
    // 0x80407B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80407BF4(rdram, ctx);
        goto after_0;
    // 0x80407B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80407B34: beq         $v0, $zero, L_80407B74
    if (ctx->r2 == 0) {
        // 0x80407B38: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80407B74;
    }
    // 0x80407B38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80407B3C: jal         0x80407C2C
    // 0x80407B40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80407C2C(rdram, ctx);
        goto after_1;
    // 0x80407B40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x80407B44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80407B48: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80407B4C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80407B50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80407B54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80407B58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80407B5C: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x80407B60: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80407B64: jal         0x8040818C
    // 0x80407B68: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    func_8040818C(rdram, ctx);
        goto after_2;
    // 0x80407B68: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    after_2:
    // 0x80407B6C: b           L_80407B80
    // 0x80407B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80407B80;
    // 0x80407B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407B74:
    // 0x80407B74: jal         0x800445A4
    // 0x80407B78: nop

    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x80407B78: nop

    after_3:
    // 0x80407B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80407B80:
    // 0x80407B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80407B84: jr          $ra
    // 0x80407B88: nop

    return;
    // 0x80407B88: nop

;}
RECOMP_FUNC void func_80456FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80456FA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80456FA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80456FA8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80456FAC: jal         0x80456D98
    // 0x80456FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80456D98(rdram, ctx);
        goto after_0;
    // 0x80456FB0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80456FB4: jal         0x80455948
    // 0x80456FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455948(rdram, ctx);
        goto after_1;
    // 0x80456FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80456FBC: jal         0x80455770
    // 0x80456FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80455770(rdram, ctx);
        goto after_2;
    // 0x80456FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80456FC4: jal         0x80456CE0
    // 0x80456FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80456CE0(rdram, ctx);
        goto after_3;
    // 0x80456FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80456FCC: jal         0x8044FD5C
    // 0x80456FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_4;
    // 0x80456FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80456FD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80456FD8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80456FDC: jal         0x80450490
    // 0x80456FE0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_5;
    // 0x80456FE0: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_5:
    // 0x80456FE4: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80456FE8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80456FEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456FF0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80456FF4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80456FF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80456FFC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80457000: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80457004: jal         0x80457164
    // 0x80457008: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    func_80457164(rdram, ctx);
        goto after_6;
    // 0x80457008: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    after_6:
    // 0x8045700C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80457010: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80457014: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80457018: jr          $ra
    // 0x8045701C: nop

    return;
    // 0x8045701C: nop

;}
RECOMP_FUNC void func_8069EF70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069EF70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069EF74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8069EF78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069EF7C: lui         $a0, 0x806A
    ctx->r4 = S32(RELOC_HI16(580, 0X6E0) << 16);
    // 0x8069EF80: lui         $a1, 0x806A
    ctx->r5 = S32(RELOC_HI16(580, 0X6F0) << 16);
    // 0x8069EF84: addiu       $a1, $a1, -0x9A0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(580, 0X6F0));
    // 0x8069EF88: addiu       $a0, $a0, -0x9B0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(580, 0X6E0));
    // 0x8069EF8C: jal         0x8004667C
    // 0x8069EF90: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8069EF90: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_0:
    // 0x8069EF94: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8069EF98: lui         $a2, 0x806A
    ctx->r6 = S32(RELOC_HI16(580, 0X49C) << 16);
    // 0x8069EF9C: addiu       $a2, $a2, -0xBF4
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(580, 0X49C));
    // 0x8069EFA0: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x8069EFA4: jal         0x80057B28
    // 0x8069EFA8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x8069EFA8: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_1:
    // 0x8069EFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069EFB0: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(580, 0X358) << 16);
    // 0x8069EFB4: addiu       $v0, $v0, -0xD38
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(580, 0X358));
    // 0x8069EFB8: jr          $ra
    // 0x8069EFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8069EFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8049F4C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8049F4C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8049F4C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8049F4C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8049F4CC: jal         0x8004700C
    // 0x8049F4D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8049F4D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8049F4D4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8049F4D8: jal         0x8049EF18
    // 0x8049F4DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8049EF18(rdram, ctx);
        goto after_1;
    // 0x8049F4DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8049F4E0: lwc1        $f0, 0x7C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8049F4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F4E8: add.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8049F4EC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8049F4F0: jal         0x80062684
    // 0x8049F4F4: nop

    func_80062684(rdram, ctx);
        goto after_2;
    // 0x8049F4F4: nop

    after_2:
    // 0x8049F4F8: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8049F4FC: beql        $v0, $zero, L_8049F5E8
    if (ctx->r2 == 0) {
        // 0x8049F500: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F5E8;
    }
    goto skip_0;
    // 0x8049F500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8049F504: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8049F508: lwc1        $f8, 0x84($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8049F50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F510: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8049F514: jal         0x8049EBD8
    // 0x8049F518: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    func_8049EBD8(rdram, ctx);
        goto after_3;
    // 0x8049F518: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8049F51C: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x8049F520: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8049F524: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8049F528: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8049F52C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8049F530: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8049F534: nop

    // 0x8049F538: bc1fl       L_8049F588
    if (!c1cs) {
        // 0x8049F53C: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_8049F588;
    }
    goto skip_1;
    // 0x8049F53C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    skip_1:
    // 0x8049F540: jal         0x80049018
    // 0x8049F544: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_80049018(rdram, ctx);
        goto after_4;
    // 0x8049F544: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_4:
    // 0x8049F548: bne         $v0, $zero, L_8049F584
    if (ctx->r2 != 0) {
        // 0x8049F54C: lhu         $v1, 0x22($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X22);
            goto L_8049F584;
    }
    // 0x8049F54C: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x8049F550: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8049F554: bne         $t6, $zero, L_8049F584
    if (ctx->r14 != 0) {
        // 0x8049F558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8049F584;
    }
    // 0x8049F558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F55C: jal         0x800554AC
    // 0x8049F560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800554AC(rdram, ctx);
        goto after_5;
    // 0x8049F560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8049F564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F568: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F56C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8049F570: jal         0x8049FBAC
    // 0x8049F574: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_6;
    // 0x8049F574: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x8049F578: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8049F57C: b           L_8049F5E4
    // 0x8049F580: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
        goto L_8049F5E4;
    // 0x8049F580: sh          $t7, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r15;
L_8049F584:
    // 0x8049F584: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
L_8049F588:
    // 0x8049F588: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8049F58C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8049F590: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8049F594: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8049F598: nop

    // 0x8049F59C: bc1fl       L_8049F5E8
    if (!c1cs) {
        // 0x8049F5A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8049F5E8;
    }
    goto skip_2;
    // 0x8049F5A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8049F5A4: jal         0x80049018
    // 0x8049F5A8: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    func_80049018(rdram, ctx);
        goto after_7;
    // 0x8049F5A8: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_7:
    // 0x8049F5AC: beq         $v0, $zero, L_8049F5E4
    if (ctx->r2 == 0) {
        // 0x8049F5B0: lhu         $v1, 0x22($sp)
        ctx->r3 = MEM_HU(ctx->r29, 0X22);
            goto L_8049F5E4;
    }
    // 0x8049F5B0: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x8049F5B4: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8049F5B8: bne         $t8, $zero, L_8049F5E4
    if (ctx->r24 != 0) {
        // 0x8049F5BC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8049F5E4;
    }
    // 0x8049F5BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F5C0: jal         0x800554AC
    // 0x8049F5C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800554AC(rdram, ctx);
        goto after_8;
    // 0x8049F5C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8049F5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8049F5CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8049F5D0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8049F5D4: jal         0x8049FBAC
    // 0x8049F5D8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8049FBAC(rdram, ctx);
        goto after_9;
    // 0x8049F5D8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_9:
    // 0x8049F5DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8049F5E0: sh          $t9, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r25;
L_8049F5E4:
    // 0x8049F5E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8049F5E8:
    // 0x8049F5E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8049F5EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8049F5F0: jr          $ra
    // 0x8049F5F4: nop

    return;
    // 0x8049F5F4: nop

;}
RECOMP_FUNC void func_80450928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450928: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8045092C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450930: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80450934: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80450938: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045093C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80450940: lw          $v0, 0xA5C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XA5C);
    // 0x80450944: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80450948: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8045094C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80450950: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80450954: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80450958: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045095C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80450960: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80450964: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80450968: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8045096C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80450970: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80450974: addiu       $t8, $t7, 0xAE0
    ctx->r24 = ADD32(ctx->r15, 0XAE0);
    // 0x80450978: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8045097C: jal         0x80446D70
    // 0x80450980: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80450980: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_0:
    // 0x80450984: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80450988: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8045098C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80450990: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80450994: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80450998: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8045099C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804509A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804509A4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x804509A8: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x804509AC: addu        $a1, $s0, $t0
    ctx->r5 = ADD32(ctx->r16, ctx->r8);
    // 0x804509B0: jal         0x8044ED68
    // 0x804509B4: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_1;
    // 0x804509B4: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_1:
    // 0x804509B8: jal         0x80450568
    // 0x804509BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80450568(rdram, ctx);
        goto after_2;
    // 0x804509BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x804509C0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x804509C4: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x804509C8: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x804509CC: sw          $t1, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r9;
    // 0x804509D0: lw          $t2, 0x7EA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7EA8);
    // 0x804509D4: lhu         $v0, 0xC($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XC);
    // 0x804509D8: andi        $t3, $v0, 0x1000
    ctx->r11 = ctx->r2 & 0X1000;
    // 0x804509DC: beq         $t3, $at, L_804509F0
    if (ctx->r11 == ctx->r1) {
        // 0x804509E0: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_804509F0;
    }
    // 0x804509E0: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    // 0x804509E4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804509E8: bnel        $t4, $at, L_80450A1C
    if (ctx->r12 != ctx->r1) {
        // 0x804509EC: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80450A1C;
    }
    goto skip_0;
    // 0x804509EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    skip_0:
L_804509F0:
    // 0x804509F0: jal         0x80445A10
    // 0x804509F4: nop

    func_80445A10(rdram, ctx);
        goto after_3;
    // 0x804509F4: nop

    after_3:
    // 0x804509F8: jal         0x80445BDC
    // 0x804509FC: nop

    func_80445BDC(rdram, ctx);
        goto after_4;
    // 0x804509FC: nop

    after_4:
    // 0x80450A00: jal         0x80445790
    // 0x80450A04: nop

    func_80445790(rdram, ctx);
        goto after_5;
    // 0x80450A04: nop

    after_5:
    // 0x80450A08: jal         0x80450818
    // 0x80450A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80450818(rdram, ctx);
        goto after_6;
    // 0x80450A0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80450A10: b           L_80450A64
    // 0x80450A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80450A64;
    // 0x80450A14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80450A18: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
L_80450A1C:
    // 0x80450A1C: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80450A20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450A24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450A28: lwc1        $f4, 0x6CE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80450A2C: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80450A30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80450A34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80450A38: swc1        $f8, 0x6CE0($v0)
    MEM_W(0X6CE0, ctx->r2) = ctx->f8.u32l;
    // 0x80450A3C: lwc1        $f16, 0x6CE0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80450A40: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80450A44: nop

    // 0x80450A48: bc1fl       L_80450A64
    if (!c1cs) {
        // 0x80450A4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80450A64;
    }
    goto skip_1;
    // 0x80450A4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80450A50: jal         0x80445790
    // 0x80450A54: nop

    func_80445790(rdram, ctx);
        goto after_7;
    // 0x80450A54: nop

    after_7:
    // 0x80450A58: jal         0x8045089C
    // 0x80450A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8045089C(rdram, ctx);
        goto after_8;
    // 0x80450A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80450A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80450A64:
    // 0x80450A64: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80450A68: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80450A6C: jr          $ra
    // 0x80450A70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80450A70: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806D1DA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D1DA0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x806D1DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D1DA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806D1DAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806D1DB0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D1DB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D1DB8: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x806D1DBC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x806D1DC0: jal         0x8004700C
    // 0x806D1DC4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D1DC4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x806D1DC8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x806D1DCC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x806D1DD0: beq         $v0, $zero, L_806D1F08
    if (ctx->r2 == 0) {
        // 0x806D1DD4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_806D1F08;
    }
    // 0x806D1DD4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806D1DD8: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x806D1DDC: addiu       $s1, $s1, 0x7EA0
    ctx->r17 = ADD32(ctx->r17, 0X7EA0);
    // 0x806D1DE0: lw          $t6, 0xE88($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XE88);
    // 0x806D1DE4: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x806D1DE8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x806D1DEC: bnel        $t7, $at, L_806D1E08
    if (ctx->r15 != ctx->r1) {
        // 0x806D1DF0: lw          $v0, 0x20($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X20);
            goto L_806D1E08;
    }
    goto skip_0;
    // 0x806D1DF0: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    skip_0:
    // 0x806D1DF4: jal         0x800447C8
    // 0x806D1DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x806D1DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806D1DFC: b           L_806D1F0C
    // 0x806D1E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D1F0C;
    // 0x806D1E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D1E04: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
L_806D1E08:
    // 0x806D1E08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D1E0C: beq         $v0, $zero, L_806D1E1C
    if (ctx->r2 == 0) {
        // 0x806D1E10: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_806D1E1C;
    }
    // 0x806D1E10: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x806D1E14: sw          $t8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r24;
    // 0x806D1E18: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_806D1E1C:
    // 0x806D1E1C: bnel        $v0, $zero, L_806D1F0C
    if (ctx->r2 != 0) {
        // 0x806D1E20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D1F0C;
    }
    goto skip_1;
    // 0x806D1E20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806D1E24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806D1E28: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D1E2C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x806D1E30: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806D1E34: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x806D1E38: lwc1        $f8, 0x6C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x806D1E3C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806D1E40: swc1        $f10, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f10.u32l;
    // 0x806D1E44: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D1E48: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806D1E4C: nop

    // 0x806D1E50: bc1fl       L_806D1F0C
    if (!c1cs) {
        // 0x806D1E54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D1F0C;
    }
    goto skip_2;
    // 0x806D1E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806D1E58: lw          $v0, 0x478($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X478);
    // 0x806D1E5C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806D1E60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806D1E64: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x806D1E68: lw          $t9, 0xE88($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XE88);
    // 0x806D1E6C: lw          $t0, 0xE70($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XE70);
    // 0x806D1E70: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x806D1E74: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x806D1E78: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x806D1E7C: lwc1        $f8, 0x34($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X34);
    // 0x806D1E80: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806D1E84: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x806D1E88: lwc1        $f16, 0x8C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8C);
    // 0x806D1E8C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x806D1E90: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x806D1E94: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x806D1E98: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x806D1E9C: lw          $t9, 0x10($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X10);
    // 0x806D1EA0: jalr        $t9
    // 0x806D1EA4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x806D1EA4: nop

    after_2:
    // 0x806D1EA8: lw          $t1, 0xA68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XA68);
    // 0x806D1EAC: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X167C) << 16);
    // 0x806D1EB0: addiu       $a1, $a1, 0x2C3C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X167C));
    // 0x806D1EB4: lw          $t2, 0x10($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X10);
    // 0x806D1EB8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D1EBC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D1EC0: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x806D1EC4: jalr        $t9
    // 0x806D1EC8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x806D1EC8: nop

    after_3:
    // 0x806D1ECC: jal         0x800447C8
    // 0x806D1ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_4;
    // 0x806D1ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806D1ED4: lw          $t4, 0xE88($s1)
    ctx->r12 = MEM_W(ctx->r17, 0XE88);
    // 0x806D1ED8: addiu       $t3, $zero, 0x309
    ctx->r11 = ADD32(0, 0X309);
    // 0x806D1EDC: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x806D1EE0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x806D1EE4: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x806D1EE8: beq         $at, $zero, L_806D1F00
    if (ctx->r1 == 0) {
        // 0x806D1EEC: nop
    
            goto L_806D1F00;
    }
    // 0x806D1EEC: nop

    // 0x806D1EF0: jal         0x800677F8
    // 0x806D1EF4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800677F8(rdram, ctx);
        goto after_5;
    // 0x806D1EF4: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_5:
    // 0x806D1EF8: b           L_806D1F0C
    // 0x806D1EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D1F0C;
    // 0x806D1EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1F00:
    // 0x806D1F00: jal         0x800677F8
    // 0x806D1F04: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800677F8(rdram, ctx);
        goto after_6;
    // 0x806D1F04: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_6:
L_806D1F08:
    // 0x806D1F08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1F0C:
    // 0x806D1F0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806D1F10: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806D1F14: jr          $ra
    // 0x806D1F18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x806D1F18: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_806F85A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F85A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F85A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806F85A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F85AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F85B0: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B24) << 16);
    // 0x806F85B4: lwc1        $f6, -0x6CCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B24));
    // 0x806F85B8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F85BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F85C0: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x806F85C4: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x806F85C8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x806F85CC: nop

    // 0x806F85D0: bc1f        L_806F85E0
    if (!c1cs) {
        // 0x806F85D4: nop
    
            goto L_806F85E0;
    }
    // 0x806F85D4: nop

    // 0x806F85D8: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x806F85DC: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
L_806F85E0:
    // 0x806F85E0: jal         0x806F84D8
    // 0x806F85E4: nop

    func_806F84D8(rdram, ctx);
        goto after_0;
    // 0x806F85E4: nop

    after_0:
    // 0x806F85E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F85EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F85F0: jr          $ra
    // 0x806F85F4: nop

    return;
    // 0x806F85F4: nop

;}
RECOMP_FUNC void func_805A3E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A3E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A3E70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A3E74: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x805A3E78: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x805A3E7C: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
    // 0x805A3E80: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805A3E84: lwc1        $f8, 0x68($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X68);
    // 0x805A3E88: lwc1        $f18, 0x60($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X60);
    // 0x805A3E8C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x805A3E90: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
    // 0x805A3E94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805A3E98: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x805A3E9C: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x805A3EA0: lwc1        $f10, 0x6C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x805A3EA4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x805A3EA8: lwc1        $f8, 0x7C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x805A3EAC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x805A3EB0: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x805A3EB4: lwc1        $f16, 0x78($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X78);
    // 0x805A3EB8: swc1        $f10, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f10.u32l;
    // 0x805A3EBC: lwc1        $f2, 0x7C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x805A3EC0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805A3EC4: lwc1        $f4, 0x70($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X70);
    // 0x805A3EC8: lwc1        $f0, 0x84($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X84);
    // 0x805A3ECC: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x805A3ED0: swc1        $f6, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f6.u32l;
    // 0x805A3ED4: lwc1        $f16, 0x8C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x805A3ED8: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x805A3EDC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x805A3EE0: lwc1        $f4, 0x88($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X88);
    // 0x805A3EE4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x805A3EE8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x805A3EEC: lwc1        $f10, 0x80($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X80);
    // 0x805A3EF0: swc1        $f18, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = ctx->f18.u32l;
    // 0x805A3EF4: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x805A3EF8: lwc1        $f6, 0x8C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x805A3EFC: sw          $t7, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r15;
    // 0x805A3F00: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x805A3F04: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805A3F08: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805A3F0C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x805A3F10: swc1        $f18, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f18.u32l;
    // 0x805A3F14: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x805A3F18: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x805A3F1C: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x805A3F20: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x805A3F24: nop

    // 0x805A3F28: bc1fl       L_805A3F50
    if (!c1cs) {
        // 0x805A3F2C: sub.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_805A3F50;
    }
    goto skip_0;
    // 0x805A3F2C: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
    skip_0:
    // 0x805A3F30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805A3F34: nop

    // 0x805A3F38: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x805A3F3C: jal         0x805A431C
    // 0x805A3F40: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    func_805A431C(rdram, ctx);
        goto after_0;
    // 0x805A3F40: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x805A3F44: b           L_805A3F7C
    // 0x805A3F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A3F7C;
    // 0x805A3F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805A3F4C: sub.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f14.fl;
L_805A3F50:
    // 0x805A3F50: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x805A3F54: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x805A3F58: nop

    // 0x805A3F5C: bc1fl       L_805A3F7C
    if (!c1cs) {
        // 0x805A3F60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A3F7C;
    }
    goto skip_1;
    // 0x805A3F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805A3F64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x805A3F68: nop

    // 0x805A3F6C: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x805A3F70: jal         0x805A431C
    // 0x805A3F74: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    func_805A431C(rdram, ctx);
        goto after_1;
    // 0x805A3F74: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    after_1:
    // 0x805A3F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A3F7C:
    // 0x805A3F7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A3F80: jr          $ra
    // 0x805A3F84: nop

    return;
    // 0x805A3F84: nop

;}
RECOMP_FUNC void func_8002E110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E114: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E118: lw          $t0, 0x1F4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E11C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E120: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8002E124: lbu         $t6, 0x154($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X154);
    // 0x8002E128: bne         $t6, $zero, L_8002E214
    if (ctx->r14 != 0) {
        // 0x8002E12C: nop
    
            goto L_8002E214;
    }
    // 0x8002E12C: nop

    // 0x8002E130: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8002E134: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x8002E138: beq         $v0, $zero, L_8002E204
    if (ctx->r2 == 0) {
        // 0x8002E13C: nop
    
            goto L_8002E204;
    }
    // 0x8002E13C: nop

    // 0x8002E140: lbu         $t8, 0xDC($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0XDC);
    // 0x8002E144: beql        $t8, $zero, L_8002E1A4
    if (ctx->r24 == 0) {
        // 0x8002E148: lhu         $v1, 0xE($v0)
        ctx->r3 = MEM_HU(ctx->r2, 0XE);
            goto L_8002E1A4;
    }
    goto skip_0;
    // 0x8002E148: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    skip_0:
    // 0x8002E14C: lw          $t9, 0x180($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X180);
    // 0x8002E150: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002E154: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E158: lw          $t1, 0x174($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X174);
    // 0x8002E15C: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8002E160: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8002E164: lhu         $v0, 0x5C($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X5C);
    // 0x8002E168: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x8002E16C: beq         $v0, $at, L_8002E190
    if (ctx->r2 == ctx->r1) {
        // 0x8002E170: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8002E190;
    }
    // 0x8002E170: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002E174: bne         $v0, $at, L_8002E21C
    if (ctx->r2 != ctx->r1) {
        // 0x8002E178: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8002E21C;
    }
    // 0x8002E178: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E17C: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x8002E180: jal         0x8002B9E4
    // 0x8002E184: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002E184: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8002E188: b           L_8002E220
    // 0x8002E18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E220;
    // 0x8002E18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E190:
    // 0x8002E190: jal         0x8002B9E4
    // 0x8002E194: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_1;
    // 0x8002E194: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x8002E198: b           L_8002E220
    // 0x8002E19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E220;
    // 0x8002E19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E1A0: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
L_8002E1A4:
    // 0x8002E1A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E1A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E1AC: srl         $v1, $v1, 10
    ctx->r3 = S32(U32(ctx->r3) >> 10);
    // 0x8002E1B0: andi        $v1, $v1, 0xF
    ctx->r3 = ctx->r3 & 0XF;
    // 0x8002E1B4: bne         $v1, $at, L_8002E1D4
    if (ctx->r3 != ctx->r1) {
        // 0x8002E1B8: addiu       $a2, $zero, 0x1B
        ctx->r6 = ADD32(0, 0X1B);
            goto L_8002E1D4;
    }
    // 0x8002E1B8: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8002E1BC: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    // 0x8002E1C0: jal         0x8002B9E4
    // 0x8002E1C4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8002B9E4(rdram, ctx);
        goto after_2;
    // 0x8002E1C4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x8002E1C8: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E1CC: b           L_8002E21C
    // 0x8002E1D0: sb          $zero, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = 0;
        goto L_8002E21C;
    // 0x8002E1D0: sb          $zero, 0x17C($t0)
    MEM_B(0X17C, ctx->r8) = 0;
L_8002E1D4:
    // 0x8002E1D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002E1D8: bne         $v1, $at, L_8002E1F4
    if (ctx->r3 != ctx->r1) {
        // 0x8002E1DC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8002E1F4;
    }
    // 0x8002E1DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002E1E0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8002E1E4: jal         0x8002B9E4
    // 0x8002E1E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_3;
    // 0x8002E1E8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_3:
    // 0x8002E1EC: b           L_8002E220
    // 0x8002E1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E220;
    // 0x8002E1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E1F4:
    // 0x8002E1F4: jal         0x800345AC
    // 0x8002E1F8: nop

    func_800345AC(rdram, ctx);
        goto after_4;
    // 0x8002E1F8: nop

    after_4:
    // 0x8002E1FC: b           L_8002E220
    // 0x8002E200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E220;
    // 0x8002E200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E204:
    // 0x8002E204: jal         0x800345AC
    // 0x8002E208: nop

    func_800345AC(rdram, ctx);
        goto after_5;
    // 0x8002E208: nop

    after_5:
    // 0x8002E20C: b           L_8002E220
    // 0x8002E210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002E220;
    // 0x8002E210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E214:
    // 0x8002E214: jal         0x8002B9E4
    // 0x8002E218: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8002B9E4(rdram, ctx);
        goto after_6;
    // 0x8002E218: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_6:
L_8002E21C:
    // 0x8002E21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002E220:
    // 0x8002E220: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E224: jr          $ra
    // 0x8002E228: nop

    return;
    // 0x8002E228: nop

;}
RECOMP_FUNC void func_8040DCF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DCF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8040DCF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040DCF8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8040DCFC: jal         0x80045A34
    // 0x8040DD00: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8040DD00: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x8040DD04: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8040DD08: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x8040DD0C: bne         $v0, $zero, L_8040DD1C
    if (ctx->r2 != 0) {
        // 0x8040DD10: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_8040DD1C;
    }
    // 0x8040DD10: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x8040DD14: b           L_8040DDBC
    // 0x8040DD18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8040DDBC;
    // 0x8040DD18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8040DD1C:
    // 0x8040DD1C: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x8040DD20: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8040DD24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8040DD28: jal         0x80065728
    // 0x8040DD2C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8040DD2C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x8040DD30: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8040DD34: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8040DD38: lui         $t7, 0x8041
    ctx->r15 = S32(RELOC_HI16(20, 0X178) << 16);
    // 0x8040DD3C: lw          $t6, 0x1F4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1F4);
    // 0x8040DD40: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8040DD44: addiu       $t7, $t7, -0x3888
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(20, 0X178));
    // 0x8040DD48: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8040DD4C: lwc1        $f4, 0x3C($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x8040DD50: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8040DD54: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8040DD58: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x8040DD5C: lwc1        $f6, 0x40($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8040DD60: lui         $t0, 0x8041
    ctx->r8 = S32(RELOC_HI16(20, 0X1DF4) << 16);
    // 0x8040DD64: addiu       $t0, $t0, -0x1C0C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(20, 0X1DF4));
    // 0x8040DD68: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x8040DD6C: lwc1        $f8, 0x44($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X44);
    // 0x8040DD70: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x8040DD74: lwc1        $f10, 0x78($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X78);
    // 0x8040DD78: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x8040DD7C: lwc1        $f16, 0x7C($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X7C);
    // 0x8040DD80: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x8040DD84: lwc1        $f18, 0x80($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X80);
    // 0x8040DD88: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8040DD8C: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x8040DD90: lw          $t1, 0x16C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X16C);
    // 0x8040DD94: sw          $t7, 0x1F8($a3)
    MEM_W(0X1F8, ctx->r7) = ctx->r15;
    // 0x8040DD98: sw          $t8, 0x124($a3)
    MEM_W(0X124, ctx->r7) = ctx->r24;
    // 0x8040DD9C: sw          $t9, 0x130($a3)
    MEM_W(0X130, ctx->r7) = ctx->r25;
    // 0x8040DDA0: sb          $zero, 0x165($a3)
    MEM_B(0X165, ctx->r7) = 0;
    // 0x8040DDA4: sw          $zero, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = 0;
    // 0x8040DDA8: sw          $zero, 0x138($a3)
    MEM_W(0X138, ctx->r7) = 0;
    // 0x8040DDAC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8040DDB0: jal         0x8040DCD8
    // 0x8040DDB4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    func_8040DCD8(rdram, ctx);
        goto after_2;
    // 0x8040DDB4: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    after_2:
    // 0x8040DDB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8040DDBC:
    // 0x8040DDBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040DDC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8040DDC4: jr          $ra
    // 0x8040DDC8: nop

    return;
    // 0x8040DDC8: nop

;}
RECOMP_FUNC void func_80031734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031734: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003173C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031740: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031744: jal         0x800310A0
    // 0x80031748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x80031748: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003174C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031750: jal         0x800421B4
    // 0x80031754: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800421B4(rdram, ctx);
        goto after_1;
    // 0x80031754: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80031758: beq         $v0, $zero, L_80031768
    if (ctx->r2 == 0) {
        // 0x8003175C: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80031768;
    }
    // 0x8003175C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031760: jal         0x800310D0
    // 0x80031764: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031764: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80031768:
    // 0x80031768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003176C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031770: jr          $ra
    // 0x80031774: nop

    return;
    // 0x80031774: nop

;}
RECOMP_FUNC void func_805A5EDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5EDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A5EE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A5EE4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A5EE8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x805A5EEC: lw          $a3, 0x270($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X270);
    // 0x805A5EF0: lwc1        $f0, 0x26C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X26C);
    // 0x805A5EF4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805A5EF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A5EFC: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x805A5F00: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805A5F04: jal         0x805A5DF0
    // 0x805A5F08: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A5F08: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x805A5F0C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805A5F10: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X151C) << 16);
    // 0x805A5F14: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x805A5F18: andi        $v1, $a3, 0x1
    ctx->r3 = ctx->r7 & 0X1;
    // 0x805A5F1C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x805A5F20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x805A5F24: lwc1        $f4, 0x67DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X151C));
    // 0x805A5F28: lui         $at, 0x805A
    ctx->r1 = S32(RELOC_HI16(417, 0X14FC) << 16);
    // 0x805A5F2C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x805A5F30: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805A5F34: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x805A5F38: lwc1        $f12, 0x67BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(417, 0X14FC));
    // 0x805A5F3C: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(417, 0X1524) << 16);
    // 0x805A5F40: addiu       $t6, $t6, 0x67E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(417, 0X1524));
    // 0x805A5F44: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x805A5F48: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x805A5F4C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x805A5F50: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x805A5F54: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805A5F58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x805A5F5C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805A5F60: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805A5F64: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x805A5F68: c.le.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl <= ctx->f14.fl;
    // 0x805A5F6C: nop

    // 0x805A5F70: bc1fl       L_805A5F80
    if (!c1cs) {
        // 0x805A5F74: add.s       $f2, $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_805A5F80;
    }
    goto skip_0;
    // 0x805A5F74: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    skip_0:
    // 0x805A5F78: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x805A5F7C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
L_805A5F80:
    // 0x805A5F80: swc1        $f0, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = ctx->f0.u32l;
    // 0x805A5F84: swc1        $f2, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f2.u32l;
    // 0x805A5F88: lwc1        $f16, 0x0($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X0);
    // 0x805A5F8C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x805A5F90: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x805A5F94: nop

    // 0x805A5F98: bc1fl       L_805A5FE8
    if (!c1cs) {
        // 0x805A5F9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A5FE8;
    }
    goto skip_1;
    // 0x805A5F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805A5FA0: bne         $a3, $at, L_805A5FE0
    if (ctx->r7 != ctx->r1) {
        // 0x805A5FA4: addiu       $t8, $a3, 0x1
        ctx->r24 = ADD32(ctx->r7, 0X1);
            goto L_805A5FE0;
    }
    // 0x805A5FA4: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x805A5FA8: swc1        $f14, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f14.u32l;
    // 0x805A5FAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x805A5FB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805A5FB4: jal         0x805A6730
    // 0x805A5FB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_805A6730(rdram, ctx);
        goto after_1;
    // 0x805A5FB8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x805A5FBC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x805A5FC0: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x805A5FC4: jal         0x80067BBC
    // 0x805A5FC8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A5FC8: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_2:
    // 0x805A5FCC: addiu       $a0, $zero, 0x275
    ctx->r4 = ADD32(0, 0X275);
    // 0x805A5FD0: jal         0x80067818
    // 0x805A5FD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805A5FD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A5FD8: b           L_805A5FE8
    // 0x805A5FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805A5FE8;
    // 0x805A5FDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A5FE0:
    // 0x805A5FE0: sw          $t8, 0x270($a1)
    MEM_W(0X270, ctx->r5) = ctx->r24;
    // 0x805A5FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A5FE8:
    // 0x805A5FE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A5FEC: jr          $ra
    // 0x805A5FF0: nop

    return;
    // 0x805A5FF0: nop

;}
RECOMP_FUNC void func_804714D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804714D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804714D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804714D8: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x804714DC: addiu       $at, $zero, 0x4127
    ctx->r1 = ADD32(0, 0X4127);
    // 0x804714E0: beq         $v0, $at, L_80471508
    if (ctx->r2 == ctx->r1) {
        // 0x804714E4: addiu       $at, $zero, 0x4128
        ctx->r1 = ADD32(0, 0X4128);
            goto L_80471508;
    }
    // 0x804714E4: addiu       $at, $zero, 0x4128
    ctx->r1 = ADD32(0, 0X4128);
    // 0x804714E8: beq         $v0, $at, L_80471518
    if (ctx->r2 == ctx->r1) {
        // 0x804714EC: addiu       $at, $zero, 0x45EA
        ctx->r1 = ADD32(0, 0X45EA);
            goto L_80471518;
    }
    // 0x804714EC: addiu       $at, $zero, 0x45EA
    ctx->r1 = ADD32(0, 0X45EA);
    // 0x804714F0: bnel        $v0, $at, L_80471524
    if (ctx->r2 != ctx->r1) {
        // 0x804714F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471524;
    }
    goto skip_0;
    // 0x804714F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804714F8: jal         0x80471A5C
    // 0x804714FC: nop

    func_80471A5C(rdram, ctx);
        goto after_0;
    // 0x804714FC: nop

    after_0:
    // 0x80471500: b           L_80471524
    // 0x80471504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80471524;
    // 0x80471504: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80471508:
    // 0x80471508: jal         0x804716D4
    // 0x8047150C: nop

    func_804716D4(rdram, ctx);
        goto after_1;
    // 0x8047150C: nop

    after_1:
    // 0x80471510: b           L_80471524
    // 0x80471514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80471524;
    // 0x80471514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80471518:
    // 0x80471518: jal         0x80471818
    // 0x8047151C: nop

    func_80471818(rdram, ctx);
        goto after_2;
    // 0x8047151C: nop

    after_2:
    // 0x80471520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80471524:
    // 0x80471524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80471528: jr          $ra
    // 0x8047152C: nop

    return;
    // 0x8047152C: nop

;}
RECOMP_FUNC void func_804B6790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6790: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804B6794: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804B6798: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804B679C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804B67A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B67A4: jal         0x804B66F8
    // 0x804B67A8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_804B66F8(rdram, ctx);
        goto after_0;
    // 0x804B67A8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x804B67AC: bnel        $v0, $zero, L_804B68B0
    if (ctx->r2 != 0) {
        // 0x804B67B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804B68B0;
    }
    goto skip_0;
    // 0x804B67B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804B67B4: jal         0x804B6400
    // 0x804B67B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804B6400(rdram, ctx);
        goto after_1;
    // 0x804B67B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804B67BC: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x804B67C0: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x804B67C4: lw          $t7, 0x68($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X68);
    // 0x804B67C8: lui         $t9, 0x804B
    ctx->r25 = S32(RELOC_HI16(182, 0XF24) << 16);
    // 0x804B67CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B67D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804B67D4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804B67D8: lw          $t9, 0x71C4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(182, 0XF24));
    // 0x804B67DC: jalr        $t9
    // 0x804B67E0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x804B67E0: nop

    after_2:
    // 0x804B67E4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x804B67E8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x804B67EC: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x804B67F0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x804B67F4: lbu         $t3, 0x2C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X2C);
    // 0x804B67F8: beql        $t3, $zero, L_804B6890
    if (ctx->r11 == 0) {
        // 0x804B67FC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_804B6890;
    }
    goto skip_1;
    // 0x804B67FC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x804B6800: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    // 0x804B6804: lhu         $t6, 0xC($t4)
    ctx->r14 = MEM_HU(ctx->r12, 0XC);
    // 0x804B6808: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x804B680C: beql        $t7, $zero, L_804B6830
    if (ctx->r15 == 0) {
        // 0x804B6810: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B6830;
    }
    goto skip_2;
    // 0x804B6810: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x804B6814: jal         0x8005FCA8
    // 0x804B6818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_3;
    // 0x804B6818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B681C: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804B6820: lhu         $t8, 0xC($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XC);
    // 0x804B6824: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x804B6828: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x804B682C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_804B6830:
    // 0x804B6830: jal         0x804B6580
    // 0x804B6834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_804B6580(rdram, ctx);
        goto after_4;
    // 0x804B6834: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x804B6838: lh          $v1, 0x144($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X144);
    // 0x804B683C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6840: jal         0x804B6524
    // 0x804B6844: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    func_804B6524(rdram, ctx);
        goto after_5;
    // 0x804B6844: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    after_5:
    // 0x804B6848: lh          $v1, 0x26($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X26);
    // 0x804B684C: lh          $t0, 0x144($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X144);
    // 0x804B6850: beql        $v1, $t0, L_804B68A4
    if (ctx->r3 == ctx->r8) {
        // 0x804B6854: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_804B68A4;
    }
    goto skip_3;
    // 0x804B6854: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    skip_3:
    // 0x804B6858: bne         $v1, $zero, L_804B6874
    if (ctx->r3 != 0) {
        // 0x804B685C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_804B6874;
    }
    // 0x804B685C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x804B6860: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B6864: jal         0x804B63C8
    // 0x804B6868: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    func_804B63C8(rdram, ctx);
        goto after_6;
    // 0x804B6868: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    after_6:
    // 0x804B686C: b           L_804B68A4
    // 0x804B6870: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_804B68A4;
    // 0x804B6870: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_804B6874:
    // 0x804B6874: bne         $v1, $at, L_804B68A0
    if (ctx->r3 != ctx->r1) {
        // 0x804B6878: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804B68A0;
    }
    // 0x804B6878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B687C: jal         0x804B63C8
    // 0x804B6880: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    func_804B63C8(rdram, ctx);
        goto after_7;
    // 0x804B6880: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_7:
    // 0x804B6884: b           L_804B68A4
    // 0x804B6888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_804B68A4;
    // 0x804B6888: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804B688C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_804B6890:
    // 0x804B6890: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804B6894: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x804B6898: jal         0x804B6580
    // 0x804B689C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804B6580(rdram, ctx);
        goto after_8;
    // 0x804B689C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_8:
L_804B68A0:
    // 0x804B68A0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_804B68A4:
    // 0x804B68A4: jal         0x804B6580
    // 0x804B68A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_804B6580(rdram, ctx);
        goto after_9;
    // 0x804B68A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x804B68AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804B68B0:
    // 0x804B68B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804B68B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804B68B8: jr          $ra
    // 0x804B68BC: nop

    return;
    // 0x804B68BC: nop

;}
RECOMP_FUNC void func_8064CB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064CB78: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8064CB7C: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x8064CB80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8064CB84: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8064CB88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8064CB8C:
    // 0x8064CB8C: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8064CB90: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064CB94: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8064CB98: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8064CB9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8064CBA0: bc1f        L_8064CBC4
    if (!c1cs) {
        // 0x8064CBA4: swc1        $f8, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
            goto L_8064CBC4;
    }
    // 0x8064CBA4: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8064CBA8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064CBAC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8064CBB0: nop

    // 0x8064CBB4: bc1fl       L_8064CBE0
    if (!c1cs) {
        // 0x8064CBB8: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064CBE0;
    }
    goto skip_0;
    // 0x8064CBB8: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_0:
    // 0x8064CBBC: b           L_8064CBDC
    // 0x8064CBC0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
        goto L_8064CBDC;
    // 0x8064CBC0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064CBC4:
    // 0x8064CBC4: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8064CBC8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8064CBCC: nop

    // 0x8064CBD0: bc1fl       L_8064CBE0
    if (!c1cs) {
        // 0x8064CBD4: lwc1        $f18, 0x3C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
            goto L_8064CBE0;
    }
    goto skip_1;
    // 0x8064CBD4: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    skip_1:
    // 0x8064CBD8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_8064CBDC:
    // 0x8064CBDC: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
L_8064CBE0:
    // 0x8064CBE0: lwc1        $f4, 0xC4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8064CBE4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8064CBE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8064CBEC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8064CBF0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8064CBF4: bne         $v0, $a0, L_8064CB8C
    if (ctx->r2 != ctx->r4) {
        // 0x8064CBF8: swc1        $f6, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
            goto L_8064CB8C;
    }
    // 0x8064CBF8: swc1        $f6, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->f6.u32l;
    // 0x8064CBFC: jr          $ra
    // 0x8064CC00: nop

    return;
    // 0x8064CC00: nop

;}
RECOMP_FUNC void func_80793010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80793010: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80793014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80793018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8079301C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80793020: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80793024: jal         0x80790CB4
    // 0x80793028: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_80790CB4(rdram, ctx);
        goto after_0;
    // 0x80793028: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8079302C: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x80793030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80793034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80793038: blez        $v0, L_8079304C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8079303C: addiu       $a2, $zero, 0x1D
        ctx->r6 = ADD32(0, 0X1D);
            goto L_8079304C;
    }
    // 0x8079303C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80793040: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80793044: b           L_80793130
    // 0x80793048: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_80793130;
    // 0x80793048: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_8079304C:
    // 0x8079304C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80793050: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80793054: jal         0x8079393C
    // 0x80793058: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8079393C(rdram, ctx);
        goto after_1;
    // 0x80793058: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_1:
    // 0x8079305C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80793060: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80793064: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80793068: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8079306C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80793070: jal         0x80047AB8
    // 0x80793074: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x80793074: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    after_2:
    // 0x80793078: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8079307C: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80793080: lw          $t7, 0xED0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XED0);
    // 0x80793084: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x80793088: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x8079308C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x80793090: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x80793094: jalr        $t9
    // 0x80793098: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80793098: nop

    after_3:
    // 0x8079309C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807930A0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807930A4: lw          $t8, 0xED0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XED0);
    // 0x807930A8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x807930AC: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x807930B0: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x807930B4: lw          $a0, 0x2C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X2C);
    // 0x807930B8: addiu       $a2, $zero, -0xC
    ctx->r6 = ADD32(0, -0XC);
    // 0x807930BC: jalr        $t9
    // 0x807930C0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x807930C0: nop

    after_4:
    // 0x807930C4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807930C8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807930CC: lw          $t0, 0xED0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XED0);
    // 0x807930D0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x807930D4: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B08) << 16);
    // 0x807930D8: sw          $s0, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r16;
    // 0x807930DC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807930E0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807930E4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807930E8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x807930EC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807930F0: lw          $t1, 0xED0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XED0);
    // 0x807930F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807930F8: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x807930FC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80793100: swc1        $f8, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->f8.u32l;
    // 0x80793104: lw          $t2, 0xED0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XED0);
    // 0x80793108: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8079310C: swc1        $f4, 0x2C($t2)
    MEM_W(0X2C, ctx->r10) = ctx->f4.u32l;
    // 0x80793110: lw          $t4, 0xED0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XED0);
    // 0x80793114: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x80793118: sw          $t3, 0x34($t4)
    MEM_W(0X34, ctx->r12) = ctx->r11;
    // 0x8079311C: lw          $t6, 0xED0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XED0);
    // 0x80793120: lw          $t5, 0x30($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X30);
    // 0x80793124: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    // 0x80793128: lwc1        $f6, 0x7E58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B08));
    // 0x8079312C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
L_80793130:
    // 0x80793130: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80793134: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80793138: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8079313C: jr          $ra
    // 0x80793140: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80793140: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_805179B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805179B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805179B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805179B8: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x805179BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805179C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805179C4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805179C8: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(288, 0X62C) << 16);
    // 0x805179CC: sb          $a2, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r6;
    // 0x805179D0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x805179D4: lw          $t8, 0x7BAC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(288, 0X62C));
    // 0x805179D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805179DC: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x805179E0: jal         0x805178E8
    // 0x805179E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805178E8(rdram, ctx);
        goto after_0;
    // 0x805179E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805179E8: jal         0x80517944
    // 0x805179EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80517944(rdram, ctx);
        goto after_1;
    // 0x805179EC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805179F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805179F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805179F8: jr          $ra
    // 0x805179FC: nop

    return;
    // 0x805179FC: nop

;}
RECOMP_FUNC void func_80057F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057F74: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80057F78: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057F7C: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80057F80: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80057F84: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80057F88: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80057F8C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80057F90: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80057F94: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80057F98: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80057F9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80057FA0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80057FA4: beq         $s0, $zero, L_80057FE0
    if (ctx->r16 == 0) {
        // 0x80057FA8: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80057FE0;
    }
    // 0x80057FA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80057FAC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80057FB0:
    // 0x80057FB0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057FB4: beq         $a0, $zero, L_80057FD8
    if (ctx->r4 == 0) {
        // 0x80057FB8: nop
    
            goto L_80057FD8;
    }
    // 0x80057FB8: nop

    // 0x80057FBC: beql        $s4, $a0, L_80057FD0
    if (ctx->r20 == ctx->r4) {
        // 0x80057FC0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80057FD0;
    }
    goto skip_0;
    // 0x80057FC0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x80057FC4: jalr        $s3
    // 0x80057FC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    LOOKUP_FUNC(ctx->r19)(rdram, ctx);
        goto after_0;
    // 0x80057FC8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80057FCC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80057FD0:
    // 0x80057FD0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80057FD4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_80057FD8:
    // 0x80057FD8: bne         $s0, $zero, L_80057FB0
    if (ctx->r16 != 0) {
        // 0x80057FDC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80057FB0;
    }
    // 0x80057FDC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057FE0:
    // 0x80057FE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80057FE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80057FE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80057FEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80057FF0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80057FF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80057FF8: jr          $ra
    // 0x80057FFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057FFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806F019C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F019C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F01A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F01A4: jal         0x80056904
    // 0x806F01A8: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x806F01A8: nop

    after_0:
    // 0x806F01AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F01B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F01B4: jr          $ra
    // 0x806F01B8: nop

    return;
    // 0x806F01B8: nop

;}
RECOMP_FUNC void func_80534BB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534BB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80534BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80534BBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80534BC0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534BC4: jal         0x8004700C
    // 0x80534BC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80534BC8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80534BCC: beq         $v0, $zero, L_80534C24
    if (ctx->r2 == 0) {
        // 0x80534BD0: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80534C24;
    }
    // 0x80534BD0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80534BD4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80534BD8: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80534BDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80534BE0: lwc1        $f4, 0x84($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X84);
    // 0x80534BE4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80534BE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80534BEC: nop

    // 0x80534BF0: bc1fl       L_80534C0C
    if (!c1cs) {
        // 0x80534BF4: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80534C0C;
    }
    goto skip_0;
    // 0x80534BF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80534BF8: lhu         $t8, 0xE($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0XE);
    // 0x80534BFC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80534C00: b           L_80534C24
    // 0x80534C04: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
        goto L_80534C24;
    // 0x80534C04: sh          $t9, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r25;
    // 0x80534C08: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80534C0C:
    // 0x80534C0C: nop

    // 0x80534C10: bc1fl       L_80534C28
    if (!c1cs) {
        // 0x80534C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80534C28;
    }
    goto skip_1;
    // 0x80534C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80534C18: lhu         $t0, 0xE($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0XE);
    // 0x80534C1C: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x80534C20: sh          $t1, 0xE($v1)
    MEM_H(0XE, ctx->r3) = ctx->r9;
L_80534C24:
    // 0x80534C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80534C28:
    // 0x80534C28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80534C2C: jr          $ra
    // 0x80534C30: nop

    return;
    // 0x80534C30: nop

;}
RECOMP_FUNC void func_804449C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804449C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804449C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804449C8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804449CC: jal         0x80047090
    // 0x804449D0: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804449D0: addiu       $a0, $zero, 0x4014
    ctx->r4 = ADD32(0, 0X4014);
    after_0:
    // 0x804449D4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804449D8: beq         $v0, $at, L_80444A30
    if (ctx->r2 == ctx->r1) {
        // 0x804449DC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80444A30;
    }
    // 0x804449DC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804449E0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x804449E4: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x804449E8: ori         $at, $at, 0x1C00
    ctx->r1 = ctx->r1 | 0X1C00;
    // 0x804449EC: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804449F0: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    // 0x804449F4: lw          $a1, 0x3C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X3C);
    // 0x804449F8: jal         0x8004613C
    // 0x804449FC: lw          $a2, 0x40($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X40);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804449FC: lw          $a2, 0x40($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X40);
    after_1:
    // 0x80444A00: beq         $v0, $zero, L_80444A30
    if (ctx->r2 == 0) {
        // 0x80444A04: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80444A30;
    }
    // 0x80444A04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80444A08: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FD8) << 16);
    // 0x80444A0C: lwc1        $f4, -0x7C48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FD8));
    // 0x80444A10: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80444A14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80444A18: jal         0x80047F9C
    // 0x80444A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80444A20: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80444A24: lw          $t9, 0x20($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X20);
    // 0x80444A28: jalr        $t9
    // 0x80444A2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80444A2C: nop

    after_3:
L_80444A30:
    // 0x80444A30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80444A34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80444A38: jr          $ra
    // 0x80444A3C: nop

    return;
    // 0x80444A3C: nop

;}
RECOMP_FUNC void func_8052E9E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052E9E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8052E9EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052E9F0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8052E9F4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8052E9F8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8052E9FC: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052EA00: jal         0x8004700C
    // 0x8052EA04: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8052EA04: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8052EA08: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8052EA0C: beq         $v0, $zero, L_8052EB9C
    if (ctx->r2 == 0) {
        // 0x8052EA10: lw          $a2, 0x28($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X28);
            goto L_8052EB9C;
    }
    // 0x8052EA10: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8052EA14: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052EA18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8052EA1C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052EA20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052EA24: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8052EA28: lw          $t8, 0x116C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X116C);
    // 0x8052EA2C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052EA30: mul.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8052EA34: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8052EA38: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8052EA3C: nop

    // 0x8052EA40: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8052EA44: bltzl       $a0, L_8052EBA0
    if (SIGNED(ctx->r4) < 0) {
        // 0x8052EA48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052EBA0;
    }
    goto skip_0;
    // 0x8052EA48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8052EA4C: lw          $t9, 0x1160($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X1160);
    // 0x8052EA50: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8052EA54: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8052EA58: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8052EA5C: beql        $at, $zero, L_8052EBA0
    if (ctx->r1 == 0) {
        // 0x8052EA60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052EBA0;
    }
    goto skip_1;
    // 0x8052EA60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052EA64: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052EA68: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8052EA6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052EA70: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052EA74: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8052EA78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8052EA7C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8052EA80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8052EA84: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8052EA88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052EA8C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8052EA90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052EA94: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8052EA98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8052EA9C: add.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8052EAA0: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8052EAA4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8052EAA8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8052EAAC: nop

    // 0x8052EAB0: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8052EAB4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8052EAB8: nop

    // 0x8052EABC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8052EAC0: beql        $t3, $zero, L_8052EB10
    if (ctx->r11 == 0) {
        // 0x8052EAC4: mfc1        $t3, $f4
        ctx->r11 = (int32_t)ctx->f4.u32l;
            goto L_8052EB10;
    }
    goto skip_2;
    // 0x8052EAC4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    skip_2:
    // 0x8052EAC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052EACC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8052EAD0: sub.s       $f4, $f2, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8052EAD4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8052EAD8: nop

    // 0x8052EADC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8052EAE0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8052EAE4: nop

    // 0x8052EAE8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x8052EAEC: bne         $t3, $zero, L_8052EB04
    if (ctx->r11 != 0) {
        // 0x8052EAF0: nop
    
            goto L_8052EB04;
    }
    // 0x8052EAF0: nop

    // 0x8052EAF4: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8052EAF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8052EAFC: b           L_8052EB1C
    // 0x8052EB00: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_8052EB1C;
    // 0x8052EB00: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8052EB04:
    // 0x8052EB04: b           L_8052EB1C
    // 0x8052EB08: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_8052EB1C;
    // 0x8052EB08: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8052EB0C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
L_8052EB10:
    // 0x8052EB10: nop

    // 0x8052EB14: bltz        $t3, L_8052EB04
    if (SIGNED(ctx->r11) < 0) {
        // 0x8052EB18: nop
    
            goto L_8052EB04;
    }
    // 0x8052EB18: nop

L_8052EB1C:
    // 0x8052EB1C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x8052EB20: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x8052EB24: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8052EB28: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8052EB2C: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8052EB30: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
    // 0x8052EB34: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8052EB38: lwc1        $f6, 0xF6C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XF6C);
    // 0x8052EB3C: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8052EB40: mul.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8052EB44: lwc1        $f8, 0xF70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XF70);
    // 0x8052EB48: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x8052EB4C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052EB50: nop

    // 0x8052EB54: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8052EB58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8052EB5C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8052EB60: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8052EB64: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8052EB68: nop

    // 0x8052EB6C: bc1f        L_8052EB9C
    if (!c1cs) {
        // 0x8052EB70: nop
    
            goto L_8052EB9C;
    }
    // 0x8052EB70: nop

    // 0x8052EB74: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x8052EB78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8052EB7C: lbu         $a0, 0x159($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X159);
    // 0x8052EB80: beql        $a0, $at, L_8052EBA0
    if (ctx->r4 == ctx->r1) {
        // 0x8052EB84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052EBA0;
    }
    goto skip_3;
    // 0x8052EB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8052EB88: beq         $a0, $zero, L_8052EB9C
    if (ctx->r4 == 0) {
        // 0x8052EB8C: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8052EB9C;
    }
    // 0x8052EB8C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8052EB90: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8052EB94: sb          $t6, 0x159($v1)
    MEM_B(0X159, ctx->r3) = ctx->r14;
    // 0x8052EB98: sb          $t7, 0x15A($v1)
    MEM_B(0X15A, ctx->r3) = ctx->r15;
L_8052EB9C:
    // 0x8052EB9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052EBA0:
    // 0x8052EBA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8052EBA4: jr          $ra
    // 0x8052EBA8: nop

    return;
    // 0x8052EBA8: nop

;}
RECOMP_FUNC void func_8000E398(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E398: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000E39C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E3A0: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000E3A4: lbu         $t0, 0x2($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X2);
    // 0x8000E3A8: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x8000E3AC: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000E3B0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000E3B4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E3B8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000E3BC: bne         $t0, $t4, L_8000E3E0
    if (ctx->r8 != ctx->r12) {
        // 0x8000E3C0: lw          $t2, 0x4C($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X4C);
            goto L_8000E3E0;
    }
    // 0x8000E3C0: lw          $t2, 0x4C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4C);
    // 0x8000E3C4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000E3C8: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x8000E3CC: bltzl       $t8, L_8000E3E0
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000E3D0: lh          $v1, 0x24($v0)
        ctx->r3 = MEM_H(ctx->r2, 0X24);
            goto L_8000E3E0;
    }
    goto skip_0;
    // 0x8000E3D0: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
    skip_0:
    // 0x8000E3D4: b           L_8000E7F4
    // 0x8000E3D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8000E7F4;
    // 0x8000E3D8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E3DC: lh          $v1, 0x24($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X24);
L_8000E3E0:
    // 0x8000E3E0: bne         $v1, $zero, L_8000E470
    if (ctx->r3 != 0) {
        // 0x8000E3E4: lbu         $t8, 0x67($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0X67);
            goto L_8000E470;
    }
    // 0x8000E3E4: lbu         $t8, 0x67($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X67);
    // 0x8000E3E8: lbu         $t9, 0x67($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X67);
    // 0x8000E3EC: lh          $t5, 0x26($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X26);
    // 0x8000E3F0: lh          $t7, 0x10($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X10);
    // 0x8000E3F4: lbu         $a0, 0x7($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X7);
    // 0x8000E3F8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8000E3FC: addu        $t1, $t6, $t7
    ctx->r9 = ADD32(ctx->r14, ctx->r15);
    // 0x8000E400: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x8000E404: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8000E408: jal         0x8000B8DC
    // 0x8000E40C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    func_8000B8DC(rdram, ctx);
        goto after_0;
    // 0x8000E40C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000E410: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8000E414: bne         $v0, $zero, L_8000E438
    if (ctx->r2 != 0) {
        // 0x8000E418: lw          $t3, 0x5C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X5C);
            goto L_8000E438;
    }
    // 0x8000E418: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8000E41C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E420: lh          $t6, 0x8($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X8);
    // 0x8000E424: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E428: ori         $t5, $t9, 0x20
    ctx->r13 = ctx->r25 | 0X20;
    // 0x8000E42C: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x8000E430: b           L_8000E7F4
    // 0x8000E434: sh          $t6, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r14;
        goto L_8000E7F4;
    // 0x8000E434: sh          $t6, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r14;
L_8000E438:
    // 0x8000E438: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8000E43C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8000E440: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x8000E444: sw          $t7, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r15;
    // 0x8000E448: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8000E44C: sll         $t6, $t9, 5
    ctx->r14 = S32(ctx->r25 << 5);
    // 0x8000E450: bltz        $t6, L_8000E460
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000E454: sb          $t8, 0x18($a2)
        MEM_B(0X18, ctx->r6) = ctx->r24;
            goto L_8000E460;
    }
    // 0x8000E454: sb          $t8, 0x18($a2)
    MEM_B(0X18, ctx->r6) = ctx->r24;
    // 0x8000E458: lbu         $t7, 0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1);
    // 0x8000E45C: sb          $t7, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r15;
L_8000E460:
    // 0x8000E460: sw          $v1, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r3;
    // 0x8000E464: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8000E468: b           L_8000E7D8
    // 0x8000E46C: swc1        $f4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f4.u32l;
        goto L_8000E7D8;
    // 0x8000E46C: swc1        $f4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f4.u32l;
L_8000E470:
    // 0x8000E470: lh          $t9, 0xE($t2)
    ctx->r25 = MEM_H(ctx->r10, 0XE);
    // 0x8000E474: lh          $t6, 0x26($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X26);
    // 0x8000E478: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x8000E47C: lh          $t8, 0x10($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X10);
    // 0x8000E480: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8000E484: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
    // 0x8000E488: andi        $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 & 0XFF;
    // 0x8000E48C: slti        $at, $t1, 0x80
    ctx->r1 = SIGNED(ctx->r9) < 0X80 ? 1 : 0;
    // 0x8000E490: bne         $at, $zero, L_8000E4AC
    if (ctx->r1 != 0) {
        // 0x8000E494: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8000E4AC;
    }
    // 0x8000E494: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8000E498: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E49C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E4A0: ori         $t6, $t5, 0x20
    ctx->r14 = ctx->r13 | 0X20;
    // 0x8000E4A4: b           L_8000E7F4
    // 0x8000E4A8: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
        goto L_8000E7F4;
    // 0x8000E4A8: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
L_8000E4AC:
    // 0x8000E4AC: bnel        $t4, $t0, L_8000E4C0
    if (ctx->r12 != ctx->r8) {
        // 0x8000E4B0: lw          $a0, 0x48($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X48);
            goto L_8000E4C0;
    }
    goto skip_1;
    // 0x8000E4B0: lw          $a0, 0x48($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X48);
    skip_1:
    // 0x8000E4B4: b           L_8000E4C0
    // 0x8000E4B8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
        goto L_8000E4C0;
    // 0x8000E4B8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x8000E4BC: lw          $a0, 0x48($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X48);
L_8000E4C0:
    // 0x8000E4C0: lbu         $t7, 0x20($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X20);
    // 0x8000E4C4: beq         $t7, $zero, L_8000E72C
    if (ctx->r15 == 0) {
        // 0x8000E4C8: nop
    
            goto L_8000E72C;
    }
    // 0x8000E4C8: nop

    // 0x8000E4CC: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x8000E4D0: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000E4D4: beq         $at, $zero, L_8000E4E4
    if (ctx->r1 == 0) {
        // 0x8000E4D8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000E4E4;
    }
    // 0x8000E4D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000E4DC: b           L_8000E4E4
    // 0x8000E4E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_8000E4E4;
    // 0x8000E4E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8000E4E4:
    // 0x8000E4E4: beq         $a0, $zero, L_8000E528
    if (ctx->r4 == 0) {
        // 0x8000E4E8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000E528;
    }
    // 0x8000E4E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E4EC: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8000E4F0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8000E4F4: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x8000E4F8: jal         0x8000B7CC
    // 0x8000E4FC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    func_8000B7CC(rdram, ctx);
        goto after_1;
    // 0x8000E4FC: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_1:
    // 0x8000E500: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8000E504: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000E508: lbu         $t1, 0x27($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X27);
    // 0x8000E50C: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8000E510: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000E514: sw          $v0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r2;
    // 0x8000E518: xor         $t3, $v0, $t8
    ctx->r11 = ctx->r2 ^ ctx->r24;
    // 0x8000E51C: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8000E520: b           L_8000E570
    // 0x8000E524: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
        goto L_8000E570;
    // 0x8000E524: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_8000E528:
    // 0x8000E528: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000E52C: slti        $at, $v1, 0xC0
    ctx->r1 = SIGNED(ctx->r3) < 0XC0 ? 1 : 0;
    // 0x8000E530: bne         $at, $zero, L_8000E570
    if (ctx->r1 != 0) {
        // 0x8000E534: sw          $zero, 0x4C($a2)
        MEM_W(0X4C, ctx->r6) = 0;
            goto L_8000E570;
    }
    // 0x8000E534: sw          $zero, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = 0;
    // 0x8000E538: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000E53C: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8000E540: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000E544: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8000E548: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8000E54C: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000E550: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x8000E554: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
    // 0x8000E558: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8000E55C: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8000E560: ori         $at, $at, 0xFF28
    ctx->r1 = ctx->r1 | 0XFF28;
    // 0x8000E564: addu        $t5, $a1, $t9
    ctx->r13 = ADD32(ctx->r5, ctx->r25);
    // 0x8000E568: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8000E56C: sw          $t6, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r14;
L_8000E570:
    // 0x8000E570: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000E574: lbu         $t9, 0x4($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X4);
    // 0x8000E578: addiu       $a0, $a0, 0x69D4
    ctx->r4 = ADD32(ctx->r4, 0X69D4);
    // 0x8000E57C: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8000E580: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8000E584: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000E588: addiu       $v1, $a2, 0x20
    ctx->r3 = ADD32(ctx->r6, 0X20);
    // 0x8000E58C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E590: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8000E594: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8000E598: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8000E59C: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8000E5A0: addiu       $t0, $zero, -0x81
    ctx->r8 = ADD32(0, -0X81);
    // 0x8000E5A4: and         $t7, $v0, $t0
    ctx->r15 = ctx->r2 & ctx->r8;
    // 0x8000E5A8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8000E5AC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000E5B0: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x8000E5B4: mul.s       $f14, $f8, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8000E5B8: beq         $at, $zero, L_8000E5F0
    if (ctx->r1 == 0) {
        // 0x8000E5BC: addiu       $a1, $a1, 0x4D10
        ctx->r5 = ADD32(ctx->r5, 0X4D10);
            goto L_8000E5F0;
    }
    // 0x8000E5BC: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
    // 0x8000E5C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000E5C4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000E5C8: addu        $at, $at, $t8
    gpr jr_addend_8000E5D0 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8000E5CC: lw          $t8, -0x4218($at)
    ctx->r24 = ADD32(ctx->r1, -0X4218);
    // 0x8000E5D0: jr          $t8
    // 0x8000E5D4: nop

    switch (jr_addend_8000E5D0 >> 2) {
        case 0: goto L_8000E5D8; break;
        case 1: goto L_8000E5E4; break;
        case 2: goto L_8000E5D8; break;
        case 3: goto L_8000E5E4; break;
        case 4: goto L_8000E5D8; break;
        default: switch_error(__func__, 0x8000E5D0, 0x800ABDE8);
    }
    // 0x8000E5D4: nop

L_8000E5D8:
    // 0x8000E5D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8000E5DC: b           L_8000E5F8
    // 0x8000E5E0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_8000E5F8;
    // 0x8000E5E0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_8000E5E4:
    // 0x8000E5E4: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8000E5E8: b           L_8000E5F8
    // 0x8000E5EC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8000E5F8;
    // 0x8000E5EC: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_8000E5F0:
    // 0x8000E5F0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8000E5F4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8000E5F8:
    // 0x8000E5F8: div.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8000E5FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E600: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000E604: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x8000E608: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000E60C: beq         $t9, $zero, L_8000E69C
    if (ctx->r25 == 0) {
        // 0x8000E610: swc1        $f18, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
            goto L_8000E69C;
    }
    // 0x8000E610: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
    // 0x8000E614: lhu         $t5, 0x8($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X8);
    // 0x8000E618: lh          $t7, 0x1DB0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X1DB0);
    // 0x8000E61C: lh          $t8, 0x8($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X8);
    // 0x8000E620: sll         $t6, $t5, 15
    ctx->r14 = S32(ctx->r13 << 15);
    // 0x8000E624: div         $zero, $t6, $t7
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r15)));
    // 0x8000E628: mflo        $v0
    ctx->r2 = lo;
    // 0x8000E62C: lhu         $t9, 0xE($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XE);
    // 0x8000E630: bne         $t7, $zero, L_8000E63C
    if (ctx->r15 != 0) {
        // 0x8000E634: nop
    
            goto L_8000E63C;
    }
    // 0x8000E634: nop

    // 0x8000E638: break       7
    do_break(2147542584);
L_8000E63C:
    // 0x8000E63C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000E640: bne         $t7, $at, L_8000E654
    if (ctx->r15 != ctx->r1) {
        // 0x8000E644: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000E654;
    }
    // 0x8000E644: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E648: bne         $t6, $at, L_8000E654
    if (ctx->r14 != ctx->r1) {
        // 0x8000E64C: nop
    
            goto L_8000E654;
    }
    // 0x8000E64C: nop

    // 0x8000E650: break       6
    do_break(2147542608);
L_8000E654:
    // 0x8000E654: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E658: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x8000E65C: mflo        $t5
    ctx->r13 = lo;
    // 0x8000E660: nop

    // 0x8000E664: nop

    // 0x8000E668: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x8000E66C: mflo        $v0
    ctx->r2 = lo;
    // 0x8000E670: bne         $t5, $zero, L_8000E67C
    if (ctx->r13 != 0) {
        // 0x8000E674: nop
    
            goto L_8000E67C;
    }
    // 0x8000E674: nop

    // 0x8000E678: break       7
    do_break(2147542648);
L_8000E67C:
    // 0x8000E67C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000E680: bne         $t5, $at, L_8000E694
    if (ctx->r13 != ctx->r1) {
        // 0x8000E684: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000E694;
    }
    // 0x8000E684: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E688: bne         $t6, $at, L_8000E694
    if (ctx->r14 != ctx->r1) {
        // 0x8000E68C: nop
    
            goto L_8000E694;
    }
    // 0x8000E68C: nop

    // 0x8000E690: break       6
    do_break(2147542672);
L_8000E694:
    // 0x8000E694: b           L_8000E6E8
    // 0x8000E698: slti        $at, $v0, 0x7FFF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FFF ? 1 : 0;
        goto L_8000E6E8;
    // 0x8000E698: slti        $at, $v0, 0x7FFF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FFF ? 1 : 0;
L_8000E69C:
    // 0x8000E69C: lhu         $t7, 0xE($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0XE);
    // 0x8000E6A0: lh          $t8, 0x1D88($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X1D88);
    // 0x8000E6A4: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x8000E6A8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000E6AC: mflo        $t9
    ctx->r25 = lo;
    // 0x8000E6B0: nop

    // 0x8000E6B4: nop

    // 0x8000E6B8: div         $zero, $t6, $t9
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r25)));
    // 0x8000E6BC: mflo        $v0
    ctx->r2 = lo;
    // 0x8000E6C0: bne         $t9, $zero, L_8000E6CC
    if (ctx->r25 != 0) {
        // 0x8000E6C4: nop
    
            goto L_8000E6CC;
    }
    // 0x8000E6C4: nop

    // 0x8000E6C8: break       7
    do_break(2147542728);
L_8000E6CC:
    // 0x8000E6CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000E6D0: bne         $t9, $at, L_8000E6E4
    if (ctx->r25 != ctx->r1) {
        // 0x8000E6D4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000E6E4;
    }
    // 0x8000E6D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000E6D8: bne         $t6, $at, L_8000E6E4
    if (ctx->r14 != ctx->r1) {
        // 0x8000E6DC: nop
    
            goto L_8000E6E4;
    }
    // 0x8000E6DC: nop

    // 0x8000E6E0: break       6
    do_break(2147542752);
L_8000E6E4:
    // 0x8000E6E4: slti        $at, $v0, 0x7FFF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FFF ? 1 : 0;
L_8000E6E8:
    // 0x8000E6E8: bne         $at, $zero, L_8000E6F8
    if (ctx->r1 != 0) {
        // 0x8000E6EC: nop
    
            goto L_8000E6F8;
    }
    // 0x8000E6EC: nop

    // 0x8000E6F0: b           L_8000E704
    // 0x8000E6F4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_8000E704;
    // 0x8000E6F4: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
L_8000E6F8:
    // 0x8000E6F8: bgtzl       $v0, L_8000E708
    if (SIGNED(ctx->r2) > 0) {
        // 0x8000E6FC: sh          $v0, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r2;
            goto L_8000E708;
    }
    goto skip_2;
    // 0x8000E6FC: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    skip_2:
    // 0x8000E700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E704:
    // 0x8000E704: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
L_8000E708:
    // 0x8000E708: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8000E70C: swc1        $f12, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f12.u32l;
    // 0x8000E710: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E714: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000E718: and         $t7, $t5, $t0
    ctx->r15 = ctx->r13 & ctx->r8;
    // 0x8000E71C: bnel        $t7, $at, L_8000E7DC
    if (ctx->r15 != ctx->r1) {
        // 0x8000E720: lwc1        $f16, 0x30($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
            goto L_8000E7DC;
    }
    goto skip_3;
    // 0x8000E720: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
    skip_3:
    // 0x8000E724: b           L_8000E7D8
    // 0x8000E728: sb          $t1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r9;
        goto L_8000E7D8;
    // 0x8000E728: sb          $t1, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r9;
L_8000E72C:
    // 0x8000E72C: beq         $a0, $zero, L_8000E780
    if (ctx->r4 == 0) {
        // 0x8000E730: sll         $t5, $a3, 2
        ctx->r13 = S32(ctx->r7 << 2);
            goto L_8000E780;
    }
    // 0x8000E730: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x8000E734: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8000E738: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8000E73C: jal         0x8000B7CC
    // 0x8000E740: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_8000B7CC(rdram, ctx);
        goto after_2;
    // 0x8000E740: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_2:
    // 0x8000E744: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8000E748: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8000E74C: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000E750: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8000E754: addiu       $a0, $a0, 0x69D4
    ctx->r4 = ADD32(ctx->r4, 0X69D4);
    // 0x8000E758: sw          $v0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r2;
    // 0x8000E75C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8000E760: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x8000E764: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8000E768: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000E76C: xor         $t3, $v0, $t8
    ctx->r11 = ctx->r2 ^ ctx->r24;
    // 0x8000E770: sltiu       $t3, $t3, 0x1
    ctx->r11 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8000E774: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000E778: b           L_8000E7D8
    // 0x8000E77C: swc1        $f8, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f8.u32l;
        goto L_8000E7D8;
    // 0x8000E77C: swc1        $f8, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f8.u32l;
L_8000E780:
    // 0x8000E780: lui         $a0, 0x8009
    ctx->r4 = S32(0X8009 << 16);
    // 0x8000E784: addiu       $a0, $a0, 0x69D4
    ctx->r4 = ADD32(ctx->r4, 0X69D4);
    // 0x8000E788: sw          $zero, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = 0;
    // 0x8000E78C: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x8000E790: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8000E794: slti        $at, $v1, 0xC0
    ctx->r1 = SIGNED(ctx->r3) < 0XC0 ? 1 : 0;
    // 0x8000E798: bne         $at, $zero, L_8000E7D8
    if (ctx->r1 != 0) {
        // 0x8000E79C: swc1        $f10, 0x30($a2)
        MEM_W(0X30, ctx->r6) = ctx->f10.u32l;
            goto L_8000E7D8;
    }
    // 0x8000E79C: swc1        $f10, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f10.u32l;
    // 0x8000E7A0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8000E7A4: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8000E7A8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000E7AC: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8000E7B0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000E7B4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x8000E7B8: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x8000E7BC: addiu       $a1, $a1, 0x4D10
    ctx->r5 = ADD32(ctx->r5, 0X4D10);
    // 0x8000E7C0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000E7C4: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x8000E7C8: ori         $at, $at, 0xFF28
    ctx->r1 = ctx->r1 | 0XFF28;
    // 0x8000E7CC: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x8000E7D0: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x8000E7D4: sw          $t9, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r25;
L_8000E7D8:
    // 0x8000E7D8: lwc1        $f16, 0x30($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X30);
L_8000E7DC:
    // 0x8000E7DC: lwc1        $f18, 0x34($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X34);
    // 0x8000E7E0: lh          $t5, 0x8($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X8);
    // 0x8000E7E4: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8000E7E8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8000E7EC: sh          $t5, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r13;
    // 0x8000E7F0: swc1        $f4, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f4.u32l;
L_8000E7F4:
    // 0x8000E7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E7F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8000E7FC: jr          $ra
    // 0x8000E800: nop

    return;
    // 0x8000E800: nop

;}
RECOMP_FUNC void func_80742E04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742E04: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742E08: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742E0C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742E10: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742E14: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742E18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742E1C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742E20: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742E24: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742E28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742E2C: jr          $ra
    // 0x80742E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742E30: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8007393C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007393C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80073940: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073944: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80073948: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007394C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80073950: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073954: lbu         $v1, 0x9($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X9);
    // 0x80073958: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007395C: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
    // 0x80073960: bne         $v1, $at, L_800739FC
    if (ctx->r3 != ctx->r1) {
        // 0x80073964: lui         $t7, 0xFA00
        ctx->r15 = S32(0XFA00 << 16);
            goto L_800739FC;
    }
    // 0x80073964: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80073968: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007396C: sll         $t8, $a0, 24
    ctx->r24 = S32(ctx->r4 << 24);
    // 0x80073970: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80073974: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x80073978: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8007397C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80073980: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073984: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80073988: lui         $t1, 0xFCFF
    ctx->r9 = S32(0XFCFF << 16);
    // 0x8007398C: lui         $t2, 0xFFFD
    ctx->r10 = S32(0XFFFD << 16);
    // 0x80073990: ori         $t2, $t2, 0xF6FB
    ctx->r10 = ctx->r10 | 0XF6FB;
    // 0x80073994: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80073998: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x8007399C: sw          $t2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r10;
    // 0x800739A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800739A4: lui         $a3, 0xF0A
    ctx->r7 = S32(0XF0A << 16);
    // 0x800739A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800739AC: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800739B0: ori         $t3, $t3, 0x18
    ctx->r11 = ctx->r11 | 0X18;
    // 0x800739B4: addiu       $t4, $zero, 0xCF0
    ctx->r12 = ADD32(0, 0XCF0);
    // 0x800739B8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800739BC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800739C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800739C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800739C8: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x800739CC: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x800739D0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800739D4: sw          $a3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r7;
    // 0x800739D8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800739DC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800739E0: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x800739E4: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x800739E8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800739EC: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
    // 0x800739F0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800739F4: b           L_80073A70
    // 0x800739F8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_80073A70;
    // 0x800739F8: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_800739FC:
    // 0x800739FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80073A00: bne         $v1, $at, L_80073A6C
    if (ctx->r3 != ctx->r1) {
        // 0x80073A04: lui         $t7, 0xF700
        ctx->r15 = S32(0XF700 << 16);
            goto L_80073A6C;
    }
    // 0x80073A04: lui         $t7, 0xF700
    ctx->r15 = S32(0XF700 << 16);
    // 0x80073A08: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073A0C: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80073A10: or          $t9, $t8, $a2
    ctx->r25 = ctx->r24 | ctx->r6;
    // 0x80073A14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80073A18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80073A1C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073A20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073A24: lui         $t0, 0xBA00
    ctx->r8 = S32(0XBA00 << 16);
    // 0x80073A28: ori         $t0, $t0, 0x18
    ctx->r8 = ctx->r8 | 0X18;
    // 0x80073A2C: lui         $t1, 0x30
    ctx->r9 = S32(0X30 << 16);
    // 0x80073A30: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80073A34: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80073A38: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80073A40: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x80073A44: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x80073A48: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80073A4C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80073A50: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80073A54: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80073A58: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x80073A5C: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x80073A60: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80073A64: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80073A68: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80073A6C:
    // 0x80073A6C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80073A70:
    // 0x80073A70: jr          $ra
    // 0x80073A74: nop

    return;
    // 0x80073A74: nop

;}
RECOMP_FUNC void func_8057E934(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057E934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8057E938: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057E93C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8057E940: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8057E944: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8057E948: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8057E94C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8057E950: addiu       $v0, $a1, 0x208
    ctx->r2 = ADD32(ctx->r5, 0X208);
    // 0x8057E954: bc1fl       L_8057E9D0
    if (!c1cs) {
        // 0x8057E958: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E9D0;
    }
    goto skip_0;
    // 0x8057E958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057E95C: lwc1        $f6, 0x2C4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E960: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8057E964: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8057E968: nop

    // 0x8057E96C: bc1fl       L_8057E9D0
    if (!c1cs) {
        // 0x8057E970: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057E9D0;
    }
    goto skip_1;
    // 0x8057E970: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057E974: swc1        $f0, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f0.u32l;
    // 0x8057E978: swc1        $f0, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f0.u32l;
    // 0x8057E97C: swc1        $f0, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f0.u32l;
    // 0x8057E980: swc1        $f0, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f0.u32l;
    // 0x8057E984: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8057E988: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8057E98C: lwc1        $f16, 0x2C4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C4);
    // 0x8057E990: swc1        $f16, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f16.u32l;
    // 0x8057E994: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8057E998: addiu       $a1, $a2, 0x3C
    ctx->r5 = ADD32(ctx->r6, 0X3C);
    // 0x8057E99C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8057E9A0: jal         0x8057DD6C
    // 0x8057E9A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8057DD6C(rdram, ctx);
        goto after_0;
    // 0x8057E9A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8057E9A8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8057E9AC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8057E9B0: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x8057E9B4: sw          $zero, 0x2B4($a3)
    MEM_W(0X2B4, ctx->r7) = 0;
    // 0x8057E9B8: sw          $t6, 0x2CC($a3)
    MEM_W(0X2CC, ctx->r7) = ctx->r14;
    // 0x8057E9BC: sw          $zero, 0x1E0($a2)
    MEM_W(0X1E0, ctx->r6) = 0;
    // 0x8057E9C0: lw          $t7, 0x2C8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X2C8);
    // 0x8057E9C4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8057E9C8: sw          $t8, 0x2C8($a3)
    MEM_W(0X2C8, ctx->r7) = ctx->r24;
    // 0x8057E9CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057E9D0:
    // 0x8057E9D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8057E9D4: jr          $ra
    // 0x8057E9D8: nop

    return;
    // 0x8057E9D8: nop

;}
RECOMP_FUNC void func_80033A68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033A68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033A6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033A70: jal         0x80021B44
    // 0x80033A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021B44(rdram, ctx);
        goto after_0;
    // 0x80033A74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033A78: bne         $v0, $zero, L_80033A88
    if (ctx->r2 != 0) {
        // 0x80033A7C: nop
    
            goto L_80033A88;
    }
    // 0x80033A7C: nop

    // 0x80033A80: b           L_80033AD4
    // 0x80033A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033AD4;
    // 0x80033A84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033A88:
    // 0x80033A88: jal         0x80033494
    // 0x80033A8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033494(rdram, ctx);
        goto after_1;
    // 0x80033A8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80033A90: bne         $v0, $zero, L_80033AA0
    if (ctx->r2 != 0) {
        // 0x80033A94: nop
    
            goto L_80033AA0;
    }
    // 0x80033A94: nop

    // 0x80033A98: b           L_80033AD4
    // 0x80033A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033AD4;
    // 0x80033A9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033AA0:
    // 0x80033AA0: jal         0x80033160
    // 0x80033AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033160(rdram, ctx);
        goto after_2;
    // 0x80033AA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80033AA8: beq         $v0, $zero, L_80033AB8
    if (ctx->r2 == 0) {
        // 0x80033AAC: nop
    
            goto L_80033AB8;
    }
    // 0x80033AAC: nop

    // 0x80033AB0: b           L_80033AD4
    // 0x80033AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033AD4;
    // 0x80033AB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033AB8:
    // 0x80033AB8: jal         0x800335B0
    // 0x80033ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800335B0(rdram, ctx);
        goto after_3;
    // 0x80033ABC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80033AC0: bnel        $v0, $zero, L_80033AD4
    if (ctx->r2 != 0) {
        // 0x80033AC4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80033AD4;
    }
    goto skip_0;
    // 0x80033AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80033AC8: b           L_80033AD4
    // 0x80033ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033AD4;
    // 0x80033ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80033AD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80033AD4:
    // 0x80033AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033ADC: jr          $ra
    // 0x80033AE0: nop

    return;
    // 0x80033AE0: nop

;}
RECOMP_FUNC void func_8046D35C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046D35C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8046D360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046D364: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8046D368: lui         $t6, 0x8047
    ctx->r14 = S32(RELOC_HI16(143, 0X1430) << 16);
    // 0x8046D36C: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(143, 0X1474) << 16);
    // 0x8046D370: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8046D374: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8046D378: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8046D37C: lw          $t6, -0x2780($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(143, 0X1430));
    // 0x8046D380: lw          $t8, -0x273C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(143, 0X1474));
    // 0x8046D384: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8046D388: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    // 0x8046D38C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8046D390: sw          $t8, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r24;
    // 0x8046D394: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8046D398: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8046D39C: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8046D3A0: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8046D3A4: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8046D3A8: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8046D3AC: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x8046D3B0: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8046D3B4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x8046D3B8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8046D3BC: sw          $a1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r5;
    // 0x8046D3C0: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8046D3C4: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x8046D3C8: swc1        $f0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f0.u32l;
    // 0x8046D3CC: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8046D3D0: jal         0x80048378
    // 0x8046D3D4: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x8046D3D4: swc1        $f10, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f10.u32l;
    after_0:
    // 0x8046D3D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8046D3DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046D3E0: jr          $ra
    // 0x8046D3E4: nop

    return;
    // 0x8046D3E4: nop

;}
RECOMP_FUNC void func_80058290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005829C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800582A0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800582A4: lui         $a3, 0x8006
    ctx->r7 = S32(0X8006 << 16);
    // 0x800582A8: addiu       $a3, $a3, -0x7DB8
    ctx->r7 = ADD32(ctx->r7, -0X7DB8);
    // 0x800582AC: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x800582B0: lh          $a1, 0x6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X6);
    // 0x800582B4: jal         0x80057F74
    // 0x800582B8: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    func_80057F74(rdram, ctx);
        goto after_0;
    // 0x800582B8: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    after_0:
    // 0x800582BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800582C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800582C4: jr          $ra
    // 0x800582C8: nop

    return;
    // 0x800582C8: nop

;}
RECOMP_FUNC void func_8002D76C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D76C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002D770: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D774: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D778: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002D77C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8002D780: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D784: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002D788: jal         0x800340DC
    // 0x8002D78C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_800340DC(rdram, ctx);
        goto after_0;
    // 0x8002D78C: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002D790: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002D794: lui         $t9, 0x8003
    ctx->r25 = S32(0X8003 << 16);
    // 0x8002D798: addiu       $a1, $a1, -0x2EB0
    ctx->r5 = ADD32(ctx->r5, -0X2EB0);
    // 0x8002D79C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8002D7A0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8002D7A4: addiu       $t9, $t9, 0x1368
    ctx->r25 = ADD32(ctx->r25, 0X1368);
    // 0x8002D7A8: sb          $t7, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r15;
    // 0x8002D7AC: sb          $t8, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r24;
    // 0x8002D7B0: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x8002D7B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002D7B8: jal         0x80028118
    // 0x8002D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80028118(rdram, ctx);
        goto after_1;
    // 0x8002D7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002D7C0: jal         0x80022EB4
    // 0x8002D7C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80022EB4(rdram, ctx);
        goto after_2;
    // 0x8002D7C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002D7C8: jal         0x8002AE90
    // 0x8002D7CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE90(rdram, ctx);
        goto after_3;
    // 0x8002D7CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002D7D0: jal         0x8005FE48
    // 0x8002D7D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_4;
    // 0x8002D7D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8002D7D8: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8002D7DC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002D7E0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8002D7E4: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x8002D7E8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8002D7EC: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    // 0x8002D7F0: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8002D7F4: sh          $zero, 0x14($t2)
    MEM_H(0X14, ctx->r10) = 0;
    // 0x8002D7F8: jal         0x8002BBF4
    // 0x8002D7FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_8002BBF4(rdram, ctx);
        goto after_5;
    // 0x8002D7FC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x8002D800: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8002D804: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8002D808: lw          $t3, 0x59C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X59C);
    // 0x8002D80C: lw          $t7, 0xA68($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XA68);
    // 0x8002D810: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8002D814: lw          $t4, 0x10C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10C);
    // 0x8002D818: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8002D81C: addiu       $a0, $zero, 0x400F
    ctx->r4 = ADD32(0, 0X400F);
    // 0x8002D820: srl         $t5, $t4, 30
    ctx->r13 = S32(U32(ctx->r12) >> 30);
    // 0x8002D824: lw          $t9, 0x14($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X14);
    // 0x8002D828: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8002D82C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
    // 0x8002D830: lw          $a2, -0x20E8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X20E8);
    // 0x8002D834: jalr        $t9
    // 0x8002D838: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8002D838: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    after_6:
    // 0x8002D83C: jal         0x80032E38
    // 0x8002D840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80032E38(rdram, ctx);
        goto after_7;
    // 0x8002D840: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_7:
    // 0x8002D844: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002D848: jal         0x8001D770
    // 0x8002D84C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    func_8001D770(rdram, ctx);
        goto after_8;
    // 0x8002D84C: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x8002D850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002D854: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002D858: jal         0x80067BF8
    // 0x8002D85C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_9;
    // 0x8002D85C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_9:
    // 0x8002D860: addiu       $a0, $zero, 0x1FB
    ctx->r4 = ADD32(0, 0X1FB);
    // 0x8002D864: jal         0x80067818
    // 0x8002D868: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8002D868: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8002D86C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002D870: jal         0x80067ACC
    // 0x8002D874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067ACC(rdram, ctx);
        goto after_11;
    // 0x8002D874: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8002D878: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x8002D87C: addiu       $t0, $t0, 0x33B4
    ctx->r8 = ADD32(ctx->r8, 0X33B4);
    // 0x8002D880: sw          $t0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r8;
    // 0x8002D884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D88C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002D890: jr          $ra
    // 0x8002D894: nop

    return;
    // 0x8002D894: nop

;}
RECOMP_FUNC void func_80680E68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680E68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80680E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680E70: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80680E74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80680E78: jal         0x80680DC0
    // 0x80680E7C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80680DC0(rdram, ctx);
        goto after_0;
    // 0x80680E7C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80680E80: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80680E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80680E88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80680E8C: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x80680E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680E94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80680E98: bne         $t8, $at, L_80680EB4
    if (ctx->r24 != ctx->r1) {
        // 0x80680E9C: lui         $at, 0x8068
        ctx->r1 = S32(RELOC_HI16(550, 0X225C) << 16);
            goto L_80680EB4;
    }
    // 0x80680E9C: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(550, 0X225C) << 16);
    // 0x80680EA0: lwc1        $f4, 0x266C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(550, 0X225C));
    // 0x80680EA4: lw          $t9, 0x1F4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1F4);
    // 0x80680EA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80680EAC: jal         0x806815B8
    // 0x80680EB0: swc1        $f4, 0x8C($t9)
    MEM_W(0X8C, ctx->r25) = ctx->f4.u32l;
    func_806815B8(rdram, ctx);
        goto after_1;
    // 0x80680EB0: swc1        $f4, 0x8C($t9)
    MEM_W(0X8C, ctx->r25) = ctx->f4.u32l;
    after_1:
L_80680EB4:
    // 0x80680EB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680EB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680EBC: jr          $ra
    // 0x80680EC0: nop

    return;
    // 0x80680EC0: nop

;}
RECOMP_FUNC void func_8057B240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057B240: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8057B244: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8057B248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8057B24C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8057B250: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057B254: jal         0x80066DE4
    // 0x8057B258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x8057B258: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8057B25C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8057B260: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8057B264: jal         0x80066E88
    // 0x8057B268: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8057B268: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8057B26C: lw          $v0, 0x16C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X16C);
    // 0x8057B270: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x8057B274: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8057B278: lbu         $v1, 0x34($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X34);
    // 0x8057B27C: lw          $a0, 0x390($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X390);
    // 0x8057B280: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8057B284: xori        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 ^ 0X1;
    // 0x8057B288: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8057B28C: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8057B290: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8057B294: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x8057B298: lw          $a2, 0x38($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X38);
    // 0x8057B29C: beq         $a0, $zero, L_8057B2AC
    if (ctx->r4 == 0) {
        // 0x8057B2A0: lw          $a3, 0x38($t4)
        ctx->r7 = MEM_W(ctx->r12, 0X38);
            goto L_8057B2AC;
    }
    // 0x8057B2A0: lw          $a3, 0x38($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X38);
    // 0x8057B2A4: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x8057B2A8: sw          $t5, 0x390($t3)
    MEM_W(0X390, ctx->r11) = ctx->r13;
L_8057B2AC:
    // 0x8057B2AC: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1BC4) << 16);
    // 0x8057B2B0: lwc1        $f16, -0x49FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1BC4));
    // 0x8057B2B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8057B2B8: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8057B2BC: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8057B2C0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8057B2C4: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
L_8057B2C8:
    // 0x8057B2C8: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x8057B2CC: sra         $t7, $t6, 2
    ctx->r15 = S32(SIGNED(ctx->r14) >> 2);
    // 0x8057B2D0: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8057B2D4: bnel        $at, $zero, L_8057B338
    if (ctx->r1 != 0) {
        // 0x8057B2D8: lwc1        $f4, 0x394($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X394);
            goto L_8057B338;
    }
    goto skip_0;
    // 0x8057B2D8: lwc1        $f4, 0x394($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X394);
    skip_0:
    // 0x8057B2DC: lw          $v0, 0x318($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X318);
    // 0x8057B2E0: beq         $v0, $zero, L_8057B2F0
    if (ctx->r2 == 0) {
        // 0x8057B2E4: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8057B2F0;
    }
    // 0x8057B2E4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8057B2E8: b           L_8057B334
    // 0x8057B2EC: sw          $t8, 0x318($a0)
    MEM_W(0X318, ctx->r4) = ctx->r24;
        goto L_8057B334;
    // 0x8057B2EC: sw          $t8, 0x318($a0)
    MEM_W(0X318, ctx->r4) = ctx->r24;
L_8057B2F0:
    // 0x8057B2F0: sw          $t2, 0x318($a0)
    MEM_W(0X318, ctx->r4) = ctx->r10;
    // 0x8057B2F4: lwc1        $f4, 0x394($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X394);
    // 0x8057B2F8: lwc1        $f6, 0x398($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X398);
    // 0x8057B2FC: mul.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8057B300: nop

    // 0x8057B304: mul.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8057B308: nop

    // 0x8057B30C: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8057B310: nop

    // 0x8057B314: mul.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8057B318: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057B31C: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8057B320: nop

    // 0x8057B324: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8057B328: swc1        $f4, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f4.u32l;
    // 0x8057B32C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8057B330: swc1        $f10, 0x1B0($a0)
    MEM_W(0X1B0, ctx->r4) = ctx->f10.u32l;
L_8057B334:
    // 0x8057B334: lwc1        $f4, 0x394($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X394);
L_8057B338:
    // 0x8057B338: lwc1        $f6, 0x138($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X138);
    // 0x8057B33C: lwc1        $f10, 0x398($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X398);
    // 0x8057B340: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8057B344: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8057B348: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8057B34C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8057B350: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
    // 0x8057B354: swc1        $f8, 0x38C($v1)
    MEM_W(0X38C, ctx->r3) = ctx->f8.u32l;
    // 0x8057B358: lwc1        $f4, 0x1AC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1AC);
    // 0x8057B35C: lwc1        $f2, 0x38C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X38C);
    // 0x8057B360: addiu       $a3, $a3, 0x30
    ctx->r7 = ADD32(ctx->r7, 0X30);
    // 0x8057B364: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8057B368: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8057B36C: swc1        $f6, 0x390($v1)
    MEM_W(0X390, ctx->r3) = ctx->f6.u32l;
    // 0x8057B370: lwc1        $f8, 0x390($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X390);
    // 0x8057B374: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8057B378: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8057B37C: nop

    // 0x8057B380: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8057B384: sh          $v0, -0x18($a2)
    MEM_H(-0X18, ctx->r6) = ctx->r2;
    // 0x8057B388: sh          $v0, -0x18($a3)
    MEM_H(-0X18, ctx->r7) = ctx->r2;
    // 0x8057B38C: lwc1        $f4, 0x390($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X390);
    // 0x8057B390: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x8057B394: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8057B398: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8057B39C: nop

    // 0x8057B3A0: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8057B3A4: sh          $v0, -0x10($a2)
    MEM_H(-0X10, ctx->r6) = ctx->r2;
    // 0x8057B3A8: bne         $t0, $t1, L_8057B2C8
    if (ctx->r8 != ctx->r9) {
        // 0x8057B3AC: sh          $v0, -0x10($a3)
        MEM_H(-0X10, ctx->r7) = ctx->r2;
            goto L_8057B2C8;
    }
    // 0x8057B3AC: sh          $v0, -0x10($a3)
    MEM_H(-0X10, ctx->r7) = ctx->r2;
    // 0x8057B3B0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x8057B3B4: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8057B3B8: beq         $at, $zero, L_8057B3C4
    if (ctx->r1 == 0) {
        // 0x8057B3BC: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_8057B3C4;
    }
    // 0x8057B3BC: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8057B3C0: sw          $t5, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r13;
L_8057B3C4:
    // 0x8057B3C4: lw          $t6, 0x390($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X390);
    // 0x8057B3C8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1BC8) << 16);
    // 0x8057B3CC: beq         $t6, $zero, L_8057B400
    if (ctx->r14 == 0) {
        // 0x8057B3D0: nop
    
            goto L_8057B400;
    }
    // 0x8057B3D0: nop

    // 0x8057B3D4: lwc1        $f8, -0x49F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1BC8));
    // 0x8057B3D8: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1BCC) << 16);
    // 0x8057B3DC: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x8057B3E0: nop

    // 0x8057B3E4: bc1fl       L_8057B428
    if (!c1cs) {
        // 0x8057B3E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8057B428;
    }
    goto skip_1;
    // 0x8057B3E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8057B3EC: lwc1        $f10, -0x49F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1BCC));
    // 0x8057B3F0: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x8057B3F4: nop

    // 0x8057B3F8: bc1fl       L_8057B428
    if (!c1cs) {
        // 0x8057B3FC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8057B428;
    }
    goto skip_2;
    // 0x8057B3FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_8057B400:
    // 0x8057B400: jal         0x8004700C
    // 0x8057B404: nop

    func_8004700C(rdram, ctx);
        goto after_2;
    // 0x8057B404: nop

    after_2:
    // 0x8057B408: beq         $v0, $zero, L_8057B424
    if (ctx->r2 == 0) {
        // 0x8057B40C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8057B424;
    }
    // 0x8057B40C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8057B410: jal         0x8002FDB8
    // 0x8057B414: nop

    func_8002FDB8(rdram, ctx);
        goto after_3;
    // 0x8057B414: nop

    after_3:
    // 0x8057B418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8057B41C: jal         0x8057B444
    // 0x8057B420: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_8057B444(rdram, ctx);
        goto after_4;
    // 0x8057B420: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_4:
L_8057B424:
    // 0x8057B424: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8057B428:
    // 0x8057B428: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8057B42C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8057B430: jr          $ra
    // 0x8057B434: nop

    return;
    // 0x8057B434: nop

;}
RECOMP_FUNC void func_80517D80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517D80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517D84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517D88: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80517D8C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80517D90: beql        $a1, $at, L_80517DA4
    if (ctx->r5 == ctx->r1) {
        // 0x80517D94: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80517DA4;
    }
    goto skip_0;
    // 0x80517D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80517D98: jal         0x80067878
    // 0x80517D9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80517D9C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_0:
    // 0x80517DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80517DA4:
    // 0x80517DA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80517DA8: jr          $ra
    // 0x80517DAC: nop

    return;
    // 0x80517DAC: nop

;}
RECOMP_FUNC void func_80672A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672A34: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80672A38: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80672A3C: lbu         $v0, 0xF5C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0XF5C);
    // 0x80672A40: lbu         $v1, 0xF5D($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0XF5D);
    // 0x80672A44: lhu         $a1, 0x2A($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X2A);
    // 0x80672A48: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80672A4C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80672A50: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80672A54: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80672A58: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80672A5C: addu        $a2, $a3, $t8
    ctx->r6 = ADD32(ctx->r7, ctx->r24);
    // 0x80672A60: lhu         $t9, 0xFE8($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0XFE8);
    // 0x80672A64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80672A68: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x80672A6C: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80672A70: beq         $at, $zero, L_80672A80
    if (ctx->r1 == 0) {
        // 0x80672A74: addu        $v0, $a2, $t0
        ctx->r2 = ADD32(ctx->r6, ctx->r8);
            goto L_80672A80;
    }
    // 0x80672A74: addu        $v0, $a2, $t0
    ctx->r2 = ADD32(ctx->r6, ctx->r8);
    // 0x80672A78: jr          $ra
    // 0x80672A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80672A7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80672A80:
    // 0x80672A80: lhu         $t1, 0xFE8($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XFE8);
    // 0x80672A84: slt         $at, $t1, $a1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80672A88: beql        $at, $zero, L_80672A9C
    if (ctx->r1 == 0) {
        // 0x80672A8C: lhu         $t2, 0xFF0($v0)
        ctx->r10 = MEM_HU(ctx->r2, 0XFF0);
            goto L_80672A9C;
    }
    goto skip_0;
    // 0x80672A8C: lhu         $t2, 0xFF0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XFF0);
    skip_0:
    // 0x80672A90: jr          $ra
    // 0x80672A94: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    return;
    // 0x80672A94: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80672A98: lhu         $t2, 0xFF0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XFF0);
L_80672A9C:
    // 0x80672A9C: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80672AA0: beql        $at, $zero, L_80672AB4
    if (ctx->r1 == 0) {
        // 0x80672AA4: lhu         $t3, 0xFF8($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0XFF8);
            goto L_80672AB4;
    }
    goto skip_1;
    // 0x80672AA4: lhu         $t3, 0xFF8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XFF8);
    skip_1:
    // 0x80672AA8: jr          $ra
    // 0x80672AAC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    return;
    // 0x80672AAC: addiu       $v0, $v1, 0x2
    ctx->r2 = ADD32(ctx->r3, 0X2);
    // 0x80672AB0: lhu         $t3, 0xFF8($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XFF8);
L_80672AB4:
    // 0x80672AB4: slt         $at, $t3, $a1
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80672AB8: beql        $at, $zero, L_80672ACC
    if (ctx->r1 == 0) {
        // 0x80672ABC: lhu         $t4, 0x1000($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X1000);
            goto L_80672ACC;
    }
    goto skip_2;
    // 0x80672ABC: lhu         $t4, 0x1000($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X1000);
    skip_2:
    // 0x80672AC0: jr          $ra
    // 0x80672AC4: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    return;
    // 0x80672AC4: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
    // 0x80672AC8: lhu         $t4, 0x1000($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X1000);
L_80672ACC:
    // 0x80672ACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80672AD0: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80672AD4: beq         $at, $zero, L_80672AE4
    if (ctx->r1 == 0) {
        // 0x80672AD8: nop
    
            goto L_80672AE4;
    }
    // 0x80672AD8: nop

    // 0x80672ADC: jr          $ra
    // 0x80672AE0: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
    return;
    // 0x80672AE0: addiu       $v0, $v1, 0x4
    ctx->r2 = ADD32(ctx->r3, 0X4);
L_80672AE4:
    // 0x80672AE4: jr          $ra
    // 0x80672AE8: nop

    return;
    // 0x80672AE8: nop

;}
RECOMP_FUNC void func_8006528C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006528C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80065290: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065294: bne         $v1, $zero, L_800652A4
    if (ctx->r3 != 0) {
        // 0x80065298: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_800652A4;
    }
    // 0x80065298: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8006529C: jr          $ra
    // 0x800652A0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    return;
    // 0x800652A0: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_800652A4:
    // 0x800652A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800652A8: slti        $v0, $t6, 0x1
    ctx->r2 = SIGNED(ctx->r14) < 0X1 ? 1 : 0;
    // 0x800652AC: jr          $ra
    // 0x800652B0: nop

    return;
    // 0x800652B0: nop

;}
RECOMP_FUNC void func_805AE324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE324: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE328: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE32C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE330: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE334: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE338: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE33C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE340: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE344: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE348: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE34C: jr          $ra
    // 0x805AE350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001C748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C74C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C750: jal         0x8001C648
    // 0x8001C754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8001C648(rdram, ctx);
        goto after_0;
    // 0x8001C754: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001C758: jal         0x8001C608
    // 0x8001C75C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8001C608(rdram, ctx);
        goto after_1;
    // 0x8001C75C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8001C760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C768: jr          $ra
    // 0x8001C76C: nop

    return;
    // 0x8001C76C: nop

;}
RECOMP_FUNC void func_80008800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008800: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80008804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000880C: lb          $v0, 0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1);
    // 0x80008810: lui         $v1, 0x800B
    ctx->r3 = S32(0X800B << 16);
    // 0x80008814: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80008818: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8000881C: bne         $at, $zero, L_80008830
    if (ctx->r1 != 0) {
        // 0x80008820: lw          $v1, 0x6A7C($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X6A7C);
            goto L_80008830;
    }
    // 0x80008820: lw          $v1, 0x6A7C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6A7C);
    // 0x80008824: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80008828: b           L_80008A44
    // 0x8000882C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
        goto L_80008A44;
    // 0x8000882C: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
L_80008830:
    // 0x80008830: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80008834: bne         $a3, $v0, L_80008844
    if (ctx->r7 != ctx->r2) {
        // 0x80008838: nop
    
            goto L_80008844;
    }
    // 0x80008838: nop

    // 0x8000883C: b           L_80008884
    // 0x80008840: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
        goto L_80008884;
    // 0x80008840: sb          $zero, 0x1($s0)
    MEM_B(0X1, ctx->r16) = 0;
L_80008844:
    // 0x80008844: beq         $a1, $zero, L_80008864
    if (ctx->r5 == 0) {
        // 0x80008848: addiu       $a0, $s0, 0x20
        ctx->r4 = ADD32(ctx->r16, 0X20);
            goto L_80008864;
    }
    // 0x80008848: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x8000884C: addiu       $a0, $s0, 0x20
    ctx->r4 = ADD32(ctx->r16, 0X20);
    // 0x80008850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008854: jal         0x800824B0
    // 0x80008858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80008858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000885C: b           L_80008A44
    // 0x80008860: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80008A44;
    // 0x80008860: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80008864:
    // 0x80008864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80008868: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000886C: jal         0x800824B0
    // 0x80008870: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80008870: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80008874: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80008878: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8000887C: beq         $v0, $at, L_80008A44
    if (ctx->r2 == ctx->r1) {
        // 0x80008880: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_80008A44;
    }
    // 0x80008880: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80008884:
    // 0x80008884: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x80008888: bne         $t7, $zero, L_8000899C
    if (ctx->r15 != 0) {
        // 0x8000888C: sw          $t7, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r15;
            goto L_8000899C;
    }
    // 0x8000888C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80008890: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x80008894: srl         $v1, $a1, 16
    ctx->r3 = S32(U32(ctx->r5) >> 16);
    // 0x80008898: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x8000889C: beq         $v1, $zero, L_800088C0
    if (ctx->r3 == 0) {
        // 0x800088A0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800088C0;
    }
    // 0x800088A0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800088A4: beq         $v1, $a3, L_800088EC
    if (ctx->r3 == ctx->r7) {
        // 0x800088A8: srl         $a0, $v0, 8
        ctx->r4 = S32(U32(ctx->r2) >> 8);
            goto L_800088EC;
    }
    // 0x800088A8: srl         $a0, $v0, 8
    ctx->r4 = S32(U32(ctx->r2) >> 8);
    // 0x800088AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800088B0: beq         $v1, $at, L_800088D8
    if (ctx->r3 == ctx->r1) {
        // 0x800088B4: srl         $a0, $v0, 8
        ctx->r4 = S32(U32(ctx->r2) >> 8);
            goto L_800088D8;
    }
    // 0x800088B4: srl         $a0, $v0, 8
    ctx->r4 = S32(U32(ctx->r2) >> 8);
    // 0x800088B8: b           L_80008988
    // 0x800088BC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_80008988;
    // 0x800088BC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800088C0:
    // 0x800088C0: srl         $a0, $v0, 8
    ctx->r4 = S32(U32(ctx->r2) >> 8);
    // 0x800088C4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800088C8: jal         0x8000678C
    // 0x800088CC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_8000678C(rdram, ctx);
        goto after_2;
    // 0x800088CC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_2:
    // 0x800088D0: b           L_80008984
    // 0x800088D4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
        goto L_80008984;
    // 0x800088D4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_800088D8:
    // 0x800088D8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800088DC: jal         0x800067BC
    // 0x800088E0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_800067BC(rdram, ctx);
        goto after_3;
    // 0x800088E0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_3:
    // 0x800088E4: b           L_80008984
    // 0x800088E8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
        goto L_80008984;
    // 0x800088E8: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_800088EC:
    // 0x800088EC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800088F0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x800088F4: jal         0x8000675C
    // 0x800088F8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_8000675C(rdram, ctx);
        goto after_4;
    // 0x800088F8: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_4:
    // 0x800088FC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80008900: lui         $t9, 0x800B
    ctx->r25 = S32(0X800B << 16);
    // 0x80008904: lw          $t9, 0x6A88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A88);
    // 0x80008908: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000890C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x80008910: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80008914: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80008918: lbu         $a0, 0x2($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X2);
    // 0x8000891C: lbu         $a2, 0x3($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X3);
    // 0x80008920: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80008924: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80008928: beq         $a0, $at, L_80008948
    if (ctx->r4 == ctx->r1) {
        // 0x8000892C: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80008948;
    }
    // 0x8000892C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80008930: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80008934: jal         0x80007014
    // 0x80008938: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    func_80007014(rdram, ctx);
        goto after_5;
    // 0x80008938: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    after_5:
    // 0x8000893C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80008940: b           L_8000894C
    // 0x80008944: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_8000894C;
    // 0x80008944: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
L_80008948:
    // 0x80008948: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8000894C:
    // 0x8000894C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80008950: beq         $a2, $at, L_80008968
    if (ctx->r6 == ctx->r1) {
        // 0x80008954: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80008968;
    }
    // 0x80008954: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80008958: jal         0x80007014
    // 0x8000895C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    func_80007014(rdram, ctx);
        goto after_6;
    // 0x8000895C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    after_6:
    // 0x80008960: b           L_8000896C
    // 0x80008964: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_8000896C;
    // 0x80008964: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80008968:
    // 0x80008968: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_8000896C:
    // 0x8000896C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80008970: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80008974: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80008978: jal         0x80008C3C
    // 0x8000897C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_80008C3C(rdram, ctx);
        goto after_7;
    // 0x8000897C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80008980: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
L_80008984:
    // 0x80008984: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80008988:
    // 0x80008988: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8000898C: jal         0x80082210
    // 0x80008990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_8;
    // 0x80008990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x80008994: b           L_80008A48
    // 0x80008998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80008A48;
    // 0x80008998: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000899C:
    // 0x8000899C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800089A0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800089A4: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x800089A8: beql        $at, $zero, L_800089F0
    if (ctx->r1 == 0) {
        // 0x800089AC: lb          $t4, 0x2($s0)
        ctx->r12 = MEM_B(ctx->r16, 0X2);
            goto L_800089F0;
    }
    goto skip_0;
    // 0x800089AC: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    skip_0:
    // 0x800089B0: lb          $t3, 0x2($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X2);
    // 0x800089B4: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    // 0x800089B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800089BC: bne         $a3, $t3, L_800089DC
    if (ctx->r7 != ctx->r11) {
        // 0x800089C0: nop
    
            goto L_800089DC;
    }
    // 0x800089C0: nop

    // 0x800089C4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x800089C8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800089CC: jal         0x80008AE8
    // 0x800089D0: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    func_80008AE8(rdram, ctx);
        goto after_9;
    // 0x800089D0: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    after_9:
    // 0x800089D4: b           L_800089E4
    // 0x800089D8: nop

        goto L_800089E4;
    // 0x800089D8: nop

L_800089DC:
    // 0x800089DC: jal         0x80008A58
    // 0x800089E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80008A58(rdram, ctx);
        goto after_10;
    // 0x800089E0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_10:
L_800089E4:
    // 0x800089E4: b           L_80008A44
    // 0x800089E8: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
        goto L_80008A44;
    // 0x800089E8: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800089EC: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
L_800089F0:
    // 0x800089F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800089F4: bne         $a3, $t4, L_80008A14
    if (ctx->r7 != ctx->r12) {
        // 0x800089F8: nop
    
            goto L_80008A14;
    }
    // 0x800089F8: nop

    // 0x800089FC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80008A00: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80008A04: jal         0x80008AE8
    // 0x80008A08: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    func_80008AE8(rdram, ctx);
        goto after_11;
    // 0x80008A08: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    after_11:
    // 0x80008A0C: b           L_80008A20
    // 0x80008A10: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
        goto L_80008A20;
    // 0x80008A10: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
L_80008A14:
    // 0x80008A14: jal         0x80008A58
    // 0x80008A18: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_80008A58(rdram, ctx);
        goto after_12;
    // 0x80008A18: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_12:
    // 0x80008A1C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
L_80008A20:
    // 0x80008A20: lw          $t5, 0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X10);
    // 0x80008A24: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80008A28: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x80008A2C: subu        $t6, $t5, $a2
    ctx->r14 = SUB32(ctx->r13, ctx->r6);
    // 0x80008A30: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x80008A34: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x80008A38: sw          $t6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r14;
    // 0x80008A3C: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x80008A40: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_80008A44:
    // 0x80008A44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80008A48:
    // 0x80008A48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008A4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80008A50: jr          $ra
    // 0x80008A54: nop

    return;
    // 0x80008A54: nop

;}
RECOMP_FUNC void func_80044DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044DC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80044DC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044DC8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80044DCC: jal         0x80057D1C
    // 0x80044DD0: addiu       $a0, $a0, -0x770C
    ctx->r4 = ADD32(ctx->r4, -0X770C);
    func_80057D1C(rdram, ctx);
        goto after_0;
    // 0x80044DD0: addiu       $a0, $a0, -0x770C
    ctx->r4 = ADD32(ctx->r4, -0X770C);
    after_0:
    // 0x80044DD4: beq         $v0, $zero, L_80044DEC
    if (ctx->r2 == 0) {
        // 0x80044DD8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80044DEC;
    }
    // 0x80044DD8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80044DDC: jal         0x800462E0
    // 0x80044DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_800462E0(rdram, ctx);
        goto after_1;
    // 0x80044DE0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80044DE4: jal         0x800440E4
    // 0x80044DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800440E4(rdram, ctx);
        goto after_2;
    // 0x80044DE8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80044DEC:
    // 0x80044DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044DF0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80044DF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80044DF8: jr          $ra
    // 0x80044DFC: nop

    return;
    // 0x80044DFC: nop

;}
RECOMP_FUNC void func_806D301C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D301C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D3020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D3024: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x806D3028: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x806D302C: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D3030: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806D3034: beq         $a3, $v0, L_806D3084
    if (ctx->r7 == ctx->r2) {
        // 0x806D3038: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_806D3084;
    }
    // 0x806D3038: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806D303C: lh          $t6, 0x26($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X26);
    // 0x806D3040: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x806D3044: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x806D3048: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806D304C: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(616, 0X13D8) << 16);
    // 0x806D3050: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x806D3054: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x806D3058: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x806D305C: mflo        $t7
    ctx->r15 = lo;
    // 0x806D3060: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x806D3064: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x806D3068: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806D306C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D3070: lw          $t1, 0x4388($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(616, 0X13D8));
    // 0x806D3074: jal         0x80048490
    // 0x806D3078: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806D3078: addu        $a1, $t1, $t3
    ctx->r5 = ADD32(ctx->r9, ctx->r11);
    after_0:
    // 0x806D307C: b           L_806D30B8
    // 0x806D3080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D30B8;
    // 0x806D3080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D3084:
    // 0x806D3084: lw          $t6, 0x12C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X12C);
    // 0x806D3088: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x806D308C: lui         $t5, 0x806D
    ctx->r13 = S32(RELOC_HI16(616, 0X13D8) << 16);
    // 0x806D3090: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D3094: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806D3098: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D309C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x806D30A0: lw          $t5, 0x4388($t5)
    ctx->r13 = MEM_W(ctx->r13, (int16_t)RELOC_LO16(616, 0X13D8));
    // 0x806D30A4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806D30A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D30AC: jal         0x80048490
    // 0x806D30B0: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    func_80048490(rdram, ctx);
        goto after_1;
    // 0x806D30B0: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    after_1:
    // 0x806D30B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D30B8:
    // 0x806D30B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D30BC: jr          $ra
    // 0x806D30C0: nop

    return;
    // 0x806D30C0: nop

;}
RECOMP_FUNC void func_807100BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807100BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807100C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x807100C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x807100C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x807100CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807100D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807100D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807100D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807100DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807100E0: lw          $v0, 0x1E4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E4);
    // 0x807100E4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x807100E8: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x807100EC: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x807100F0: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x807100F4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x807100F8: lw          $t1, 0x1F4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X1F4);
    // 0x807100FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80710100: beq         $at, $zero, L_80710128
    if (ctx->r1 == 0) {
        // 0x80710104: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_80710128;
    }
    // 0x80710104: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80710108: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8071010C: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
L_80710110:
    // 0x80710110: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x80710114: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80710118: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8071011C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80710120: bne         $at, $zero, L_80710110
    if (ctx->r1 != 0) {
        // 0x80710124: addu        $t0, $t0, $t7
        ctx->r8 = ADD32(ctx->r8, ctx->r15);
            goto L_80710110;
    }
    // 0x80710124: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
L_80710128:
    // 0x80710128: bne         $t0, $zero, L_80710210
    if (ctx->r8 != 0) {
        // 0x8071012C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80710210;
    }
    // 0x8071012C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80710130: lw          $a0, 0x16C($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X16C);
    // 0x80710134: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80710138: jal         0x8070FFC0
    // 0x8071013C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    func_8070FFC0(rdram, ctx);
        goto after_0;
    // 0x8071013C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x80710140: beql        $s3, $zero, L_80710150
    if (ctx->r19 == 0) {
        // 0x80710144: lw          $t9, 0x1F4($s5)
        ctx->r25 = MEM_W(ctx->r21, 0X1F4);
            goto L_80710150;
    }
    goto skip_0;
    // 0x80710144: lw          $t9, 0x1F4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1F4);
    skip_0:
    // 0x80710148: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x8071014C: lw          $t9, 0x1F4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X1F4);
L_80710150:
    // 0x80710150: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80710154: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80710158: lw          $v0, 0x1E4($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1E4);
    // 0x8071015C: slt         $at, $v0, $s2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80710160: beq         $at, $zero, L_807101A0
    if (ctx->r1 == 0) {
        // 0x80710164: negu        $s0, $v0
        ctx->r16 = SUB32(0, ctx->r2);
            goto L_807101A0;
    }
    // 0x80710164: negu        $s0, $v0
    ctx->r16 = SUB32(0, ctx->r2);
    // 0x80710168: negu        $at, $s2
    ctx->r1 = SUB32(0, ctx->r18);
    // 0x8071016C: sll         $s1, $at, 3
    ctx->r17 = S32(ctx->r1 << 3);
    // 0x80710170: sll         $s0, $s0, 3
    ctx->r16 = S32(ctx->r16 << 3);
    // 0x80710174: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80710178: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x8071017C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80710180:
    // 0x80710180: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80710184: addu        $a2, $s0, $s3
    ctx->r6 = ADD32(ctx->r16, ctx->r19);
    // 0x80710188: jal         0x8005C27C
    // 0x8071018C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x8071018C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x80710190: addiu       $s0, $s0, -0x8
    ctx->r16 = ADD32(ctx->r16, -0X8);
    // 0x80710194: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80710198: bnel        $at, $zero, L_80710180
    if (ctx->r1 != 0) {
        // 0x8071019C: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80710180;
    }
    goto skip_1;
    // 0x8071019C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_1:
L_807101A0:
    // 0x807101A0: lw          $t2, 0x1F4($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X1F4);
    // 0x807101A4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x807101A8: jal         0x8070FB48
    // 0x807101AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8070FB48(rdram, ctx);
        goto after_2;
    // 0x807101AC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x807101B0: lbu         $t3, 0x18($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X18);
    // 0x807101B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x807101B8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x807101BC: beq         $t3, $at, L_807101D4
    if (ctx->r11 == ctx->r1) {
        // 0x807101C0: addiu       $a1, $zero, 0x7
        ctx->r5 = ADD32(0, 0X7);
            goto L_807101D4;
    }
    // 0x807101C0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x807101C4: jal         0x80710C50
    // 0x807101C8: sw          $zero, 0x1E4($s6)
    MEM_W(0X1E4, ctx->r22) = 0;
    func_80710C50(rdram, ctx);
        goto after_3;
    // 0x807101C8: sw          $zero, 0x1E4($s6)
    MEM_W(0X1E4, ctx->r22) = 0;
    after_3:
    // 0x807101CC: b           L_80710210
    // 0x807101D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80710210;
    // 0x807101D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807101D4:
    // 0x807101D4: jal         0x80710020
    // 0x807101D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80710020(rdram, ctx);
        goto after_4;
    // 0x807101D8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_4:
    // 0x807101DC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807101E0: beq         $v0, $zero, L_807101FC
    if (ctx->r2 == 0) {
        // 0x807101E4: sw          $v0, -0x7470($at)
        MEM_W(-0X7470, ctx->r1) = ctx->r2;
            goto L_807101FC;
    }
    // 0x807101E4: sw          $v0, -0x7470($at)
    MEM_W(-0X7470, ctx->r1) = ctx->r2;
    // 0x807101E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x807101EC: jal         0x80710C50
    // 0x807101F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80710C50(rdram, ctx);
        goto after_5;
    // 0x807101F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_5:
    // 0x807101F4: b           L_80710210
    // 0x807101F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80710210;
    // 0x807101F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807101FC:
    // 0x807101FC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80710200: jal         0x80710C50
    // 0x80710204: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    func_80710C50(rdram, ctx);
        goto after_6;
    // 0x80710204: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_6:
    // 0x80710208: b           L_80710210
    // 0x8071020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80710210;
    // 0x8071020C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80710210:
    // 0x80710210: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80710214: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80710218: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8071021C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80710220: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80710224: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80710228: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8071022C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80710230: jr          $ra
    // 0x80710234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80710234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80568710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80568710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80568714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80568718: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8056871C: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x80568720: bne         $v1, $zero, L_8056873C
    if (ctx->r3 != 0) {
        // 0x80568724: nop
    
            goto L_8056873C;
    }
    // 0x80568724: nop

    // 0x80568728: jal         0x80045A34
    // 0x8056872C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8056872C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80568730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80568734: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80568738: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
L_8056873C:
    // 0x8056873C: bne         $v1, $zero, L_80568754
    if (ctx->r3 != 0) {
        // 0x80568740: lui         $t6, 0x8057
        ctx->r14 = S32(RELOC_HI16(378, 0X1FC0) << 16);
            goto L_80568754;
    }
    // 0x80568740: lui         $t6, 0x8057
    ctx->r14 = S32(RELOC_HI16(378, 0X1FC0) << 16);
    // 0x80568744: jal         0x800445A4
    // 0x80568748: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x80568748: nop

    after_1:
    // 0x8056874C: b           L_80568798
    // 0x80568750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80568798;
    // 0x80568750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80568754:
    // 0x80568754: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80568758: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8056875C: addiu       $t6, $t6, -0x6A90
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(378, 0X1FC0));
    // 0x80568760: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80568764: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80568768: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8056876C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80568770: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x80568774: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80568778: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8056877C: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x80568780: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80568784: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80568788: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8056878C: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80568790: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80568794: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80568798:
    // 0x80568798: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8056879C: jr          $ra
    // 0x805687A0: nop

    return;
    // 0x805687A0: nop

;}
RECOMP_FUNC void func_80034D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034D60: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80034D64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80034D68: jal         0x800411AC
    // 0x80034D6C: lbu         $a1, -0x7684($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7684);
    func_800411AC(rdram, ctx);
        goto after_0;
    // 0x80034D6C: lbu         $a1, -0x7684($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X7684);
    after_0:
    // 0x80034D70: jal         0x80034BE4
    // 0x80034D74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034BE4(rdram, ctx);
        goto after_1;
    // 0x80034D74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034D78: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x80034D7C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034D80: sb          $v0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r2;
    // 0x80034D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80034D88: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034D8C: sb          $v0, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r2;
    // 0x80034D90: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80034D94: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80034D98: sb          $t6, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r14;
    // 0x80034D9C: jr          $ra
    // 0x80034DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80034DA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8040C124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C124: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C128: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C12C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8040C130: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8040C134: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040C138: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(17, 0X4D8) << 16);
    // 0x8040C13C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040C140: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8040C144: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040C148: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040C14C: lw          $t8, -0x3A98($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(17, 0X4D8));
    // 0x8040C150: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x8040C154: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8040C158: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8040C15C: jal         0x80048490
    // 0x8040C160: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8040C160: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8040C164: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8040C168: jal         0x80048378
    // 0x8040C16C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8040C16C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x8040C170: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8040C174: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C178: jr          $ra
    // 0x8040C17C: nop

    return;
    // 0x8040C17C: nop

;}
RECOMP_FUNC void func_80519A48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519A48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519A4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519A50: jal         0x805198F8
    // 0x80519A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805198F8(rdram, ctx);
        goto after_0;
    // 0x80519A54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519A58: jal         0x80519358
    // 0x80519A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80519358(rdram, ctx);
        goto after_1;
    // 0x80519A5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80519A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519A68: jr          $ra
    // 0x80519A6C: nop

    return;
    // 0x80519A6C: nop

;}
RECOMP_FUNC void func_807C2D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C2D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807C2D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C2D08: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807C2D0C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(901, 0X1A0) << 16);
    // 0x807C2D10: beq         $v0, $zero, L_807C2D38
    if (ctx->r2 == 0) {
        // 0x807C2D14: nop
    
            goto L_807C2D38;
    }
    // 0x807C2D14: nop

    // 0x807C2D18: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x807C2D1C: lwc1        $f4, 0x2E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(901, 0X1A0));
    // 0x807C2D20: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807C2D24: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x807C2D28: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x807C2D2C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x807C2D30: b           L_807C2D40
    // 0x807C2D34: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
        goto L_807C2D40;
    // 0x807C2D34: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
L_807C2D38:
    // 0x807C2D38: jal         0x800447C8
    // 0x807C2D3C: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x807C2D3C: nop

    after_0:
L_807C2D40:
    // 0x807C2D40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C2D44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807C2D48: jr          $ra
    // 0x807C2D4C: nop

    return;
    // 0x807C2D4C: nop

;}
RECOMP_FUNC void func_80021054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021058: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002105C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021060: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80021064: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80021068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002106C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80021070: bne         $t6, $at, L_800210B0
    if (ctx->r14 != ctx->r1) {
        // 0x80021074: nop
    
            goto L_800210B0;
    }
    // 0x80021074: nop

    // 0x80021078: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x8002107C: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80021080: bne         $t7, $at, L_800210B0
    if (ctx->r15 != ctx->r1) {
        // 0x80021084: nop
    
            goto L_800210B0;
    }
    // 0x80021084: nop

    // 0x80021088: lwc1        $f4, 0xA8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x8002108C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80021090: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021094: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80021098: nop

    // 0x8002109C: bc1f        L_800210EC
    if (!c1cs) {
        // 0x800210A0: nop
    
            goto L_800210EC;
    }
    // 0x800210A0: nop

    // 0x800210A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800210A8: b           L_800210EC
    // 0x800210AC: nop

        goto L_800210EC;
    // 0x800210AC: nop

L_800210B0:
    // 0x800210B0: jal         0x80066E88
    // 0x800210B4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800210B4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_0:
    // 0x800210B8: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800210BC: lwc1        $f10, 0x100($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800210C0: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800210C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800210C8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800210CC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800210D0: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800210D4: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800210D8: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x800210DC: nop

    // 0x800210E0: bc1f        L_800210EC
    if (!c1cs) {
        // 0x800210E4: nop
    
            goto L_800210EC;
    }
    // 0x800210E4: nop

    // 0x800210E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800210EC:
    // 0x800210EC: beq         $v0, $zero, L_80021140
    if (ctx->r2 == 0) {
        // 0x800210F0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021140;
    }
    // 0x800210F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800210F4: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x800210F8: addiu       $s1, $s1, -0x301C
    ctx->r17 = ADD32(ctx->r17, -0X301C);
    // 0x800210FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021104: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021108: jal         0x8004D23C
    // 0x8002110C: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_1;
    // 0x8002110C: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_1:
    // 0x80021110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021114: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80021118: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002111C: jal         0x8004D23C
    // 0x80021120: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_2;
    // 0x80021120: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_2:
    // 0x80021124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021128: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8002112C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021130: jal         0x8004D23C
    // 0x80021134: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_3;
    // 0x80021134: lui         $a3, 0xBF80
    ctx->r7 = S32(0XBF80 << 16);
    after_3:
    // 0x80021138: b           L_80021184
    // 0x8002113C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80021184;
    // 0x8002113C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021140:
    // 0x80021140: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021144: addiu       $s1, $s1, -0x301C
    ctx->r17 = ADD32(ctx->r17, -0X301C);
    // 0x80021148: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002114C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80021150: jal         0x8004D23C
    // 0x80021154: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_4;
    // 0x80021154: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x80021158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002115C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80021160: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021164: jal         0x8004D23C
    // 0x80021168: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_5;
    // 0x80021168: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x8002116C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021170: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80021174: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021178: jal         0x8004D23C
    // 0x8002117C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_6;
    // 0x8002117C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x80021180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021184:
    // 0x80021184: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80021188: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002118C: jr          $ra
    // 0x80021190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80021190: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8070FA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070FA5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8070FA60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070FA64: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070FA68: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x8070FA6C: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x8070FA70: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8070FA74: lbu         $a3, 0xF5C($t0)
    ctx->r7 = MEM_BU(ctx->r8, 0XF5C);
    // 0x8070FA78: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8070FA7C: lw          $t7, 0x16C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X16C);
    // 0x8070FA80: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8070FA84: lw          $a1, 0xCCC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XCCC);
    // 0x8070FA88: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8070FA8C: lbu         $v1, 0x10($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X10);
    // 0x8070FA90: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8070FA94: addiu       $v1, $v1, -0xC
    ctx->r3 = ADD32(ctx->r3, -0XC);
    // 0x8070FA98: bgezl       $v1, L_8070FAF0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8070FA9C: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_8070FAF0;
    }
    goto skip_0;
    // 0x8070FA9C: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8070FAA0: lw          $t2, 0x18($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X18);
    // 0x8070FAA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8070FAA8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8070FAAC: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8070FAB0: beql        $at, $zero, L_8070FAE0
    if (ctx->r1 == 0) {
        // 0x8070FAB4: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_8070FAE0;
    }
    goto skip_1;
    // 0x8070FAB4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    skip_1:
    // 0x8070FAB8: addiu       $a0, $v0, 0x30
    ctx->r4 = ADD32(ctx->r2, 0X30);
    // 0x8070FABC: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8070FAC0: jal         0x8070F740
    // 0x8070FAC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    func_8070F740(rdram, ctx);
        goto after_0;
    // 0x8070FAC4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_0:
    // 0x8070FAC8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8070FACC: jal         0x80710C50
    // 0x8070FAD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80710C50(rdram, ctx);
        goto after_1;
    // 0x8070FAD0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8070FAD4: b           L_8070FAEC
    // 0x8070FAD8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
        goto L_8070FAEC;
    // 0x8070FAD8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8070FADC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
L_8070FAE0:
    // 0x8070FAE0: jal         0x80710C50
    // 0x8070FAE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80710C50(rdram, ctx);
        goto after_2;
    // 0x8070FAE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_2:
    // 0x8070FAE8: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_8070FAEC:
    // 0x8070FAEC: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_8070FAF0:
    // 0x8070FAF0: sb          $v1, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r3;
    // 0x8070FAF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8070FAF8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8070FAFC: jr          $ra
    // 0x8070FB00: nop

    return;
    // 0x8070FB00: nop

;}
RECOMP_FUNC void func_80068CF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068CFC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80068D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068D04: addiu       $t6, $t6, 0x48BC
    ctx->r14 = ADD32(ctx->r14, 0X48BC);
    // 0x80068D08: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80068D0C: jal         0x80068CD4
    // 0x80068D10: sw          $t6, -0x7808($at)
    MEM_W(-0X7808, ctx->r1) = ctx->r14;
    func_80068CD4(rdram, ctx);
        goto after_0;
    // 0x80068D10: sw          $t6, -0x7808($at)
    MEM_W(-0X7808, ctx->r1) = ctx->r14;
    after_0:
    // 0x80068D14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068D1C: jr          $ra
    // 0x80068D20: nop

    return;
    // 0x80068D20: nop

;}
RECOMP_FUNC void func_8043F42C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043F42C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043F430: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043F434: lwc1        $f2, 0x40($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043F438: addiu       $a1, $zero, 0x95
    ctx->r5 = ADD32(0, 0X95);
    // 0x8043F43C: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
L_8043F440:
    // 0x8043F440: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8043F444: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8043F448: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8043F44C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8043F450: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x8043F454: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8043F458: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8043F45C: bgez        $a1, L_8043F440
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8043F460: swc1        $f10, -0xC($v1)
        MEM_W(-0XC, ctx->r3) = ctx->f10.u32l;
            goto L_8043F440;
    }
    // 0x8043F460: swc1        $f10, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8043F464: jr          $ra
    // 0x8043F468: nop

    return;
    // 0x8043F468: nop

;}
RECOMP_FUNC void func_80421864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421864: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80421868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8042186C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80421870: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80421874: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80421878: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8042187C: lw          $t7, 0x174($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X174);
    // 0x80421880: lbu         $t1, 0x18($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X18);
    // 0x80421884: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80421888: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8042188C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80421890: lhu         $v1, 0xC($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XC);
    // 0x80421894: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x80421898: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8042189C: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x804218A0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x804218A4: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x804218A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x804218AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804218B0: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804218B4: bne         $t1, $at, L_804218CC
    if (ctx->r9 != ctx->r1) {
        // 0x804218B8: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_804218CC;
    }
    // 0x804218B8: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x804218BC: bne         $v1, $at, L_80421970
    if (ctx->r3 != ctx->r1) {
        // 0x804218C0: nop
    
            goto L_80421970;
    }
    // 0x804218C0: nop

    // 0x804218C4: b           L_80421970
    // 0x804218C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80421970;
    // 0x804218C8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_804218CC:
    // 0x804218CC: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804218D0: bne         $v1, $at, L_80421970
    if (ctx->r3 != ctx->r1) {
        // 0x804218D4: lw          $t2, 0x68($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X68);
            goto L_80421970;
    }
    // 0x804218D4: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x804218D8: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x804218DC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x804218E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x804218E4: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x804218E8: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x804218EC: bc1f        L_80421964
    if (!c1cs) {
        // 0x804218F0: nop
    
            goto L_80421964;
    }
    // 0x804218F0: nop

    // 0x804218F4: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x804218F8: lui         $a1, 0xC0A0
    ctx->r5 = S32(0XC0A0 << 16);
    // 0x804218FC: jal         0x8002FABC
    // 0x80421900: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_8002FABC(rdram, ctx);
        goto after_0;
    // 0x80421900: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80421904: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80421908: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8042190C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80421910: sw          $t3, 0x888($a3)
    MEM_W(0X888, ctx->r7) = ctx->r11;
    // 0x80421914: jal         0x8042182C
    // 0x80421918: addiu       $a1, $a3, 0x898
    ctx->r5 = ADD32(ctx->r7, 0X898);
    func_8042182C(rdram, ctx);
        goto after_1;
    // 0x80421918: addiu       $a1, $a3, 0x898
    ctx->r5 = ADD32(ctx->r7, 0X898);
    after_1:
    // 0x8042191C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80421920: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80421924: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80421928: jal         0x80067D5C
    // 0x8042192C: lw          $a0, 0x89C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X89C);
    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x8042192C: lw          $a0, 0x89C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X89C);
    after_2:
    // 0x80421930: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    // 0x80421934: jal         0x80067818
    // 0x80421938: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x80421938: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8042193C: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x80421940: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80421944: sb          $t4, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r12;
    // 0x80421948: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8042194C: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80421950: sb          $t5, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r13;
    // 0x80421954: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80421958: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8042195C: b           L_8042196C
    // 0x80421960: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
        goto L_8042196C;
    // 0x80421960: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_80421964:
    // 0x80421964: jal         0x8002F6E4
    // 0x80421968: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x80421968: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
L_8042196C:
    // 0x8042196C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80421970:
    // 0x80421970: beql        $t0, $zero, L_80421A24
    if (ctx->r8 == 0) {
        // 0x80421974: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421A24;
    }
    goto skip_0;
    // 0x80421974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80421978: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x8042197C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80421980: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80421984: lw          $t8, 0x884($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X884);
    // 0x80421988: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8042198C: bnel        $t8, $zero, L_80421A24
    if (ctx->r24 != 0) {
        // 0x80421990: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80421A24;
    }
    goto skip_1;
    // 0x80421990: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80421994: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80421998: sw          $t9, 0x884($v0)
    MEM_W(0X884, ctx->r2) = ctx->r25;
    // 0x8042199C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804219A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x804219A4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x804219A8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x804219AC: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(32, 0X1768) << 16);
    // 0x804219B0: lwc1        $f18, 0x2828($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(32, 0X1768));
    // 0x804219B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804219B8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x804219BC: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x804219C0: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x804219C4: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x804219C8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x804219CC: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x804219D0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x804219D4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x804219D8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x804219DC: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x804219E0: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x804219E4: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x804219E8: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x804219EC: lw          $t2, -0x76F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X76F8);
    // 0x804219F0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x804219F4: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x804219F8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x804219FC: lwc1        $f6, 0x4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80421A00: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80421A04: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80421A08: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80421A0C: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80421A10: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x80421A14: lw          $t9, 0x10($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X10);
    // 0x80421A18: jalr        $t9
    // 0x80421A1C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80421A1C: nop

    after_5:
    // 0x80421A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80421A24:
    // 0x80421A24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80421A28: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80421A2C: jr          $ra
    // 0x80421A30: nop

    return;
    // 0x80421A30: nop

;}
RECOMP_FUNC void func_804346A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804346A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804346A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804346A8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804346AC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804346B0: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(71, 0X29F4) << 16);
    // 0x804346B4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804346B8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804346BC: lw          $t8, 0x64A4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(71, 0X29F4));
    // 0x804346C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804346C4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804346C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804346CC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804346D0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804346D4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804346D8: beql        $v1, $zero, L_8043470C
    if (ctx->r3 == 0) {
        // 0x804346DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043470C;
    }
    goto skip_0;
    // 0x804346DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804346E0: jalr        $v1
    // 0x804346E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804346E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804346E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804346EC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804346F0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804346F4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804346F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804346FC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80434700: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80434704: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80434708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043470C:
    // 0x8043470C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80434710: jr          $ra
    // 0x80434714: nop

    return;
    // 0x80434714: nop

;}
RECOMP_FUNC void func_80055464(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055464: jr          $ra
    // 0x80055468: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80055468: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805E478C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E478C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4790: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4794: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4798: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805E479C: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0X1008) << 16);
    // 0x805E47A0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805E47A4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805E47A8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E47AC: nop

    // 0x805E47B0: bc1fl       L_805E47F0
    if (!c1cs) {
        // 0x805E47B4: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_805E47F0;
    }
    goto skip_0;
    // 0x805E47B4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x805E47B8: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x805E47BC: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0X1000) << 16);
    // 0x805E47C0: lwc1        $f8, 0x5140($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0X1000));
    // 0x805E47C4: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x805E47C8: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0X1004) << 16);
    // 0x805E47CC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x805E47D0: nop

    // 0x805E47D4: bc1f        L_805E4814
    if (!c1cs) {
        // 0x805E47D8: nop
    
            goto L_805E4814;
    }
    // 0x805E47D8: nop

    // 0x805E47DC: lwc1        $f10, 0x5144($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0X1004));
    // 0x805E47E0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x805E47E4: b           L_805E4814
    // 0x805E47E8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
        goto L_805E4814;
    // 0x805E47E8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x805E47EC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_805E47F0:
    // 0x805E47F0: lwc1        $f18, 0x5148($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0X1008));
    // 0x805E47F4: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(486, 0X100C) << 16);
    // 0x805E47F8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x805E47FC: nop

    // 0x805E4800: bc1f        L_805E4814
    if (!c1cs) {
        // 0x805E4804: nop
    
            goto L_805E4814;
    }
    // 0x805E4804: nop

    // 0x805E4808: lwc1        $f4, 0x514C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(486, 0X100C));
    // 0x805E480C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x805E4810: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_805E4814:
    // 0x805E4814: jal         0x805E4674
    // 0x805E4818: nop

    func_805E4674(rdram, ctx);
        goto after_0;
    // 0x805E4818: nop

    after_0:
    // 0x805E481C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4820: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4824: jr          $ra
    // 0x805E4828: nop

    return;
    // 0x805E4828: nop

;}
RECOMP_FUNC void func_8001C414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001C418: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C41C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C420: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001C424: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8001C428: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8001C42C: jalr        $t9
    // 0x8001C430: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8001C430: nop

    after_0:
    // 0x8001C434: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C438: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8001C43C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001C440: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8001C444: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001C448: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8001C44C: lw          $t8, -0x69C0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X69C0);
    // 0x8001C450: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8001C454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C458: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001C45C: jr          $ra
    // 0x8001C460: nop

    return;
    // 0x8001C460: nop

;}
RECOMP_FUNC void func_80440F08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80440F08: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80440F0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80440F10: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80440F14: jal         0x8004700C
    // 0x80440F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80440F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80440F1C: beql        $v0, $zero, L_804410CC
    if (ctx->r2 == 0) {
        // 0x80440F20: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804410CC;
    }
    goto skip_0;
    // 0x80440F20: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80440F24: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80440F28: beql        $t6, $zero, L_804410CC
    if (ctx->r14 == 0) {
        // 0x80440F2C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_804410CC;
    }
    goto skip_1;
    // 0x80440F2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80440F30: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x80440F34: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80440F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80440F3C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80440F40: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80440F44: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80440F48: lwc1        $f10, 0x88($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X88);
    // 0x80440F4C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80440F50: jal         0x8043F33C
    // 0x80440F54: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    func_8043F33C(rdram, ctx);
        goto after_1;
    // 0x80440F54: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80440F58: jal         0x8043FDF0
    // 0x80440F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043FDF0(rdram, ctx);
        goto after_2;
    // 0x80440F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80440F60: jal         0x8043F150
    // 0x80440F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F150(rdram, ctx);
        goto after_3;
    // 0x80440F64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80440F68: jal         0x8044045C
    // 0x80440F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044045C(rdram, ctx);
        goto after_4;
    // 0x80440F6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80440F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80440F74: jal         0x8043EF80
    // 0x80440F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8043EF80(rdram, ctx);
        goto after_5;
    // 0x80440F78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80440F7C: jal         0x804406D0
    // 0x80440F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804406D0(rdram, ctx);
        goto after_6;
    // 0x80440F80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80440F84: beq         $v0, $zero, L_804410C0
    if (ctx->r2 == 0) {
        // 0x80440F88: nop
    
            goto L_804410C0;
    }
    // 0x80440F88: nop

    // 0x80440F8C: jal         0x80440950
    // 0x80440F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80440950(rdram, ctx);
        goto after_7;
    // 0x80440F90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80440F94: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x80440F98: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80440F9C: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80440FA0: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x80440FA4: bnel        $t8, $at, L_80440FC0
    if (ctx->r24 != ctx->r1) {
        // 0x80440FA8: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_80440FC0;
    }
    goto skip_2;
    // 0x80440FA8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_2:
    // 0x80440FAC: jal         0x8043F6F4
    // 0x80440FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F6F4(rdram, ctx);
        goto after_8;
    // 0x80440FB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80440FB4: b           L_804410CC
    // 0x80440FB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804410CC;
    // 0x80440FB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80440FBC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_80440FC0:
    // 0x80440FC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80440FC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80440FC8: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x80440FCC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80440FD0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80440FD4: bc1fl       L_80441028
    if (!c1cs) {
        // 0x80440FD8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80441028;
    }
    goto skip_3;
    // 0x80440FD8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x80440FDC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80440FE0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80440FE4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80440FE8: nop

    // 0x80440FEC: bc1fl       L_80441028
    if (!c1cs) {
        // 0x80440FF0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80441028;
    }
    goto skip_4;
    // 0x80440FF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_4:
    // 0x80440FF4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80440FF8: nop

    // 0x80440FFC: bc1fl       L_80441028
    if (!c1cs) {
        // 0x80441000: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80441028;
    }
    goto skip_5;
    // 0x80441000: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_5:
    // 0x80441004: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80441008: nop

    // 0x8044100C: bc1fl       L_80441028
    if (!c1cs) {
        // 0x80441010: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80441028;
    }
    goto skip_6;
    // 0x80441010: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_6:
    // 0x80441014: jal         0x8043F504
    // 0x80441018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F504(rdram, ctx);
        goto after_9;
    // 0x80441018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8044101C: b           L_804410CC
    // 0x80441020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_804410CC;
    // 0x80441020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80441024: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80441028:
    // 0x80441028: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8044102C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80441030: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80441034: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80441038: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044103C: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80441040: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80441044: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80441048: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8044104C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80441050: jal         0x80440E3C
    // 0x80441054: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80440E3C(rdram, ctx);
        goto after_10;
    // 0x80441054: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80441058: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8044105C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80441060: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80441064: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80441068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8044106C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80441070: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80441074: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80441078: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8044107C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80441080: jal         0x80440E3C
    // 0x80441084: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80440E3C(rdram, ctx);
        goto after_11;
    // 0x80441084: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_11:
    // 0x80441088: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8044108C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80441090: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80441094: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80441098: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8044109C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804410A0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x804410A4: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804410A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x804410AC: swc1        $f18, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f18.u32l;
    // 0x804410B0: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804410B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804410B8: b           L_804410C8
    // 0x804410BC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
        goto L_804410C8;
    // 0x804410BC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
L_804410C0:
    // 0x804410C0: jal         0x8043F93C
    // 0x804410C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043F93C(rdram, ctx);
        goto after_12;
    // 0x804410C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_804410C8:
    // 0x804410C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_804410CC:
    // 0x804410CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804410D0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x804410D4: jr          $ra
    // 0x804410D8: nop

    return;
    // 0x804410D8: nop

;}
RECOMP_FUNC void func_8000D86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D86C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000D870: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000D874: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000D878: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000D87C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000D880: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000D884: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D888: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8000D88C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000D890:
    // 0x8000D890: jal         0x8000D81C
    // 0x8000D894: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000D81C(rdram, ctx);
        goto after_0;
    // 0x8000D894: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000D898: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D89C: bnel        $s0, $s2, L_8000D890
    if (ctx->r16 != ctx->r18) {
        // 0x8000D8A0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000D890;
    }
    goto skip_0;
    // 0x8000D8A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8000D8A4: jal         0x8000BE94
    // 0x8000D8A8: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    func_8000BE94(rdram, ctx);
        goto after_1;
    // 0x8000D8A8: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    after_1:
    // 0x8000D8AC: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x8000D8B0: andi        $t9, $t6, 0xFF7F
    ctx->r25 = ctx->r14 & 0XFF7F;
    // 0x8000D8B4: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x8000D8B8: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x8000D8BC: sb          $t0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r8;
    // 0x8000D8C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000D8C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000D8C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000D8CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000D8D0: jr          $ra
    // 0x8000D8D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000D8D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_806DF458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF45C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF460: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806DF464: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806DF468: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806DF46C: beq         $a1, $at, L_806DF4AC
    if (ctx->r5 == ctx->r1) {
        // 0x806DF470: addiu       $a0, $zero, 0x55
        ctx->r4 = ADD32(0, 0X55);
            goto L_806DF4AC;
    }
    // 0x806DF470: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF474: jal         0x80067930
    // 0x806DF478: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806DF478: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x806DF47C: bne         $v0, $zero, L_806DF4AC
    if (ctx->r2 != 0) {
        // 0x806DF480: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806DF4AC;
    }
    // 0x806DF480: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806DF484: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806DF488: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x806DF48C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x806DF490: jal         0x80067D5C
    // 0x806DF494: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x806DF494: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x806DF498: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806DF49C: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x806DF4A0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806DF4A4: jal         0x80067838
    // 0x806DF4A8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x806DF4A8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_2:
L_806DF4AC:
    // 0x806DF4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF4B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF4B4: jr          $ra
    // 0x806DF4B8: nop

    return;
    // 0x806DF4B8: nop

;}
RECOMP_FUNC void func_8045464C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045464C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454650: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80454654: addiu       $t6, $zero, 0x3C0
    ctx->r14 = ADD32(0, 0X3C0);
    // 0x80454658: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8045465C: jr          $ra
    // 0x80454660: sw          $t6, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = ctx->r14;
    return;
    // 0x80454660: sw          $t6, 0x6A3C($at)
    MEM_W(0X6A3C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void func_8079EFE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079EFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079EFEC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8079EFF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079EFF4: beql        $t6, $zero, L_8079F014
    if (ctx->r14 == 0) {
        // 0x8079EFF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079F014;
    }
    goto skip_0;
    // 0x8079EFF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079EFFC: jal         0x8079F1C0
    // 0x8079F000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    func_8079F1C0(rdram, ctx);
        goto after_0;
    // 0x8079F000: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x8079F004: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8079F008: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8079F00C: sb          $t7, 0x7EA5($at)
    MEM_B(0X7EA5, ctx->r1) = ctx->r15;
    // 0x8079F010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079F014:
    // 0x8079F014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079F018: jr          $ra
    // 0x8079F01C: nop

    return;
    // 0x8079F01C: nop

;}
RECOMP_FUNC void func_80526114(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526114: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80526118: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052611C: jal         0x8004700C
    // 0x80526120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80526120: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80526124: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80526128: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x8052612C: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x80526130: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80526134: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80526138: jal         0x80062748
    // 0x8052613C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_80062748(rdram, ctx);
        goto after_1;
    // 0x8052613C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80526140: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80526144: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80526148: lw          $t7, 0x88($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X88);
    // 0x8052614C: beq         $a2, $zero, L_805261FC
    if (ctx->r6 == 0) {
        // 0x80526150: sw          $t7, 0x8C($v1)
        MEM_W(0X8C, ctx->r3) = ctx->r15;
            goto L_805261FC;
    }
    // 0x80526150: sw          $t7, 0x8C($v1)
    MEM_W(0X8C, ctx->r3) = ctx->r15;
    // 0x80526154: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80526158: lw          $t9, 0x180($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X180);
    // 0x8052615C: bnel        $t8, $t9, L_80526200
    if (ctx->r24 != ctx->r25) {
        // 0x80526160: sw          $zero, 0x88($v1)
        MEM_W(0X88, ctx->r3) = 0;
            goto L_80526200;
    }
    goto skip_0;
    // 0x80526160: sw          $zero, 0x88($v1)
    MEM_W(0X88, ctx->r3) = 0;
    skip_0:
    // 0x80526164: lw          $t0, 0x174($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X174);
    // 0x80526168: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8052616C: lw          $t3, -0x7CE8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7CE8);
    // 0x80526170: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80526174: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80526178: lbu         $t4, 0xF0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0XF0);
    // 0x8052617C: lh          $t2, 0xA($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XA);
    // 0x80526180: lw          $t1, 0x70($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X70);
    // 0x80526184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80526188: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8052618C: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80526190: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80526194: mul.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80526198: beql        $t4, $zero, L_805261B0
    if (ctx->r12 == 0) {
        // 0x8052619C: sw          $v0, 0x88($v1)
        MEM_W(0X88, ctx->r3) = ctx->r2;
            goto L_805261B0;
    }
    goto skip_1;
    // 0x8052619C: sw          $v0, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r2;
    skip_1:
    // 0x805261A0: sw          $t5, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r13;
    // 0x805261A4: b           L_805261B0
    // 0x805261A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_805261B0;
    // 0x805261A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805261AC: sw          $v0, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r2;
L_805261B0:
    // 0x805261B0: lwc1        $f0, 0x3C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x805261B4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x805261B8: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x805261BC: add.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x805261C0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x805261C4: nop

    // 0x805261C8: bc1fl       L_805261DC
    if (!c1cs) {
        // 0x805261CC: sw          $zero, 0x44($v1)
        MEM_W(0X44, ctx->r3) = 0;
            goto L_805261DC;
    }
    goto skip_2;
    // 0x805261CC: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    skip_2:
    // 0x805261D0: b           L_805261DC
    // 0x805261D4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
        goto L_805261DC;
    // 0x805261D4: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x805261D8: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
L_805261DC:
    // 0x805261DC: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x805261E0: nop

    // 0x805261E4: bc1f        L_805261F4
    if (!c1cs) {
        // 0x805261E8: nop
    
            goto L_805261F4;
    }
    // 0x805261E8: nop

    // 0x805261EC: b           L_80526208
    // 0x805261F0: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
        goto L_80526208;
    // 0x805261F0: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
L_805261F4:
    // 0x805261F4: b           L_80526208
    // 0x805261F8: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
        goto L_80526208;
    // 0x805261F8: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
L_805261FC:
    // 0x805261FC: sw          $zero, 0x88($v1)
    MEM_W(0X88, ctx->r3) = 0;
L_80526200:
    // 0x80526200: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x80526204: sw          $zero, 0x64($v1)
    MEM_W(0X64, ctx->r3) = 0;
L_80526208:
    // 0x80526208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052620C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80526210: jr          $ra
    // 0x80526214: nop

    return;
    // 0x80526214: nop

;}
RECOMP_FUNC void func_80067D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D38: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x80067D3C: addiu       $v0, $v1, -0x6A50
    ctx->r2 = ADD32(ctx->r3, -0X6A50);
    // 0x80067D40: jr          $ra
    // 0x80067D44: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
    return;
    // 0x80067D44: sw          $a0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_805D7C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7C10: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805D7C14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D7C18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805D7C1C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x805D7C20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x805D7C24: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x805D7C28: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805D7C2C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x805D7C30: bnel        $t6, $at, L_805D7D8C
    if (ctx->r14 != ctx->r1) {
        // 0x805D7C34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D7D8C;
    }
    goto skip_0;
    // 0x805D7C34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805D7C38: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x805D7C3C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805D7C40: beq         $v0, $at, L_805D7CD8
    if (ctx->r2 == ctx->r1) {
        // 0x805D7C44: addiu       $at, $zero, 0x4002
        ctx->r1 = ADD32(0, 0X4002);
            goto L_805D7CD8;
    }
    // 0x805D7C44: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x805D7C48: bnel        $v0, $at, L_805D7D8C
    if (ctx->r2 != ctx->r1) {
        // 0x805D7C4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D7D8C;
    }
    goto skip_1;
    // 0x805D7C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805D7C50: lw          $a0, 0x34($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X34);
    // 0x805D7C54: jal         0x80067BBC
    // 0x805D7C58: lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805D7C58: lw          $a1, 0x38($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X38);
    after_0:
    // 0x805D7C5C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x805D7C60: jal         0x80067818
    // 0x805D7C64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x805D7C64: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x805D7C68: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x805D7C6C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805D7C70: sb          $t7, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r15;
    // 0x805D7C74: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805D7C78: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x805D7C7C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x805D7C80: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x805D7C84: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x805D7C88: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x805D7C8C: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805D7C90: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x805D7C94: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x805D7C98: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x805D7C9C: lwc1        $f6, 0x88($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805D7CA0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x805D7CA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805D7CA8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x805D7CAC: lwc1        $f8, 0x8C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x805D7CB0: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x805D7CB4: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x805D7CB8: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x805D7CBC: lw          $t9, 0x18($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X18);
    // 0x805D7CC0: jalr        $t9
    // 0x805D7CC4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x805D7CC4: nop

    after_2:
    // 0x805D7CC8: jal         0x800447C8
    // 0x805D7CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x805D7CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805D7CD0: b           L_805D7D8C
    // 0x805D7CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805D7D8C;
    // 0x805D7CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D7CD8:
    // 0x805D7CD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805D7CDC: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x805D7CE0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x805D7CE4: nop

    // 0x805D7CE8: bc1fl       L_805D7D44
    if (!c1cs) {
        // 0x805D7CEC: lwc1        $f0, 0xC4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
            goto L_805D7D44;
    }
    goto skip_2;
    // 0x805D7CEC: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    skip_2:
    // 0x805D7CF0: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x805D7CF4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805D7CF8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805D7CFC: nop

    // 0x805D7D00: bc1fl       L_805D7D8C
    if (!c1cs) {
        // 0x805D7D04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D7D8C;
    }
    goto skip_3;
    // 0x805D7D04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x805D7D08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D7D0C: lwc1        $f18, 0xDC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x805D7D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D7D14: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805D7D18: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    // 0x805D7D1C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x805D7D20: swc1        $f16, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f16.u32l;
    // 0x805D7D24: jal         0x8001D808
    // 0x805D7D28: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    func_8001D808(rdram, ctx);
        goto after_4;
    // 0x805D7D28: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x805D7D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x805D7D30: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x805D7D34: sw          $v0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r2;
    // 0x805D7D38: b           L_805D7D88
    // 0x805D7D3C: sw          $v0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r2;
        goto L_805D7D88;
    // 0x805D7D3C: sw          $v0, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r2;
    // 0x805D7D40: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
L_805D7D44:
    // 0x805D7D44: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805D7D48: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x805D7D4C: nop

    // 0x805D7D50: bc1fl       L_805D7D8C
    if (!c1cs) {
        // 0x805D7D54: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805D7D8C;
    }
    goto skip_4;
    // 0x805D7D54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x805D7D58: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805D7D5C: lwc1        $f8, 0xDC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x805D7D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D7D64: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x805D7D68: lw          $a1, 0x138($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X138);
    // 0x805D7D6C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x805D7D70: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x805D7D74: jal         0x8001D808
    // 0x805D7D78: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    func_8001D808(rdram, ctx);
        goto after_5;
    // 0x805D7D78: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x805D7D7C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x805D7D80: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805D7D84: sw          $zero, 0x134($s0)
    MEM_W(0X134, ctx->r16) = 0;
L_805D7D88:
    // 0x805D7D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805D7D8C:
    // 0x805D7D8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805D7D90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805D7D94: jr          $ra
    // 0x805D7D98: nop

    return;
    // 0x805D7D98: nop

;}
RECOMP_FUNC void func_80675178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675178: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8067517C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80675180: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80675184: nop

    // 0x80675188: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8067518C: jr          $ra
    // 0x80675190: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x80675190: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_806D9010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9018: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D901C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806D9020: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x806D9024: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806D9028: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806D902C: bne         $t7, $at, L_806D9054
    if (ctx->r15 != ctx->r1) {
        // 0x806D9030: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_806D9054;
    }
    // 0x806D9030: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x806D9034: jal         0x8002F6E4
    // 0x806D9038: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x806D9038: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806D903C: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x806D9040: lui         $t9, 0x806E
    ctx->r25 = S32(RELOC_HI16(628, 0X430) << 16);
    // 0x806D9044: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x806D9048: addiu       $t9, $t9, -0x6D10
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(628, 0X430));
    // 0x806D904C: sb          $t8, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r24;
    // 0x806D9050: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
L_806D9054:
    // 0x806D9054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D9058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D905C: jr          $ra
    // 0x806D9060: nop

    return;
    // 0x806D9060: nop

;}
