#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8064DEBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064DEBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064DEC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064DEC4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064DEC8: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x8064DECC: bnel        $t7, $zero, L_8064DEF0
    if (ctx->r15 != 0) {
        // 0x8064DED0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064DEF0;
    }
    goto skip_0;
    // 0x8064DED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064DED4: jal         0x8005FD1C
    // 0x8064DED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x8064DED8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064DEDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064DEE0: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8064DEE4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8064DEE8: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x8064DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064DEF0:
    // 0x8064DEF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064DEF4: jr          $ra
    // 0x8064DEF8: nop

    return;
    // 0x8064DEF8: nop

;}
RECOMP_FUNC void func_80584C6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584C6C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584C70: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584C74: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584C78: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584C7C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584C80: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584C84: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584C88: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584C8C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584C90: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584C94: jr          $ra
    // 0x80584C98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584C98: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042C2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042C2E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042C2E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042C2E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042C2EC: jal         0x8042BFF4
    // 0x8042C2F0: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    func_8042BFF4(rdram, ctx);
        goto after_0;
    // 0x8042C2F0: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    after_0:
    // 0x8042C2F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042C2F8: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X304C) << 16);
    // 0x8042C2FC: lwc1        $f0, -0x2714($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X304C));
    // 0x8042C300: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8042C304: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8042C308: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x8042C30C: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8042C310: lui         $at, 0x8043
    ctx->r1 = S32(RELOC_HI16(50, 0X3050) << 16);
    // 0x8042C314: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8042C318: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8042C31C: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8042C320: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8042C324: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8042C328: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8042C32C: lwc1        $f18, -0x2710($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(50, 0X3050));
    // 0x8042C330: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8042C334: nop

    // 0x8042C338: bc1fl       L_8042C34C
    if (!c1cs) {
        // 0x8042C33C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042C34C;
    }
    goto skip_0;
    // 0x8042C33C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042C340: jal         0x80048D4C
    // 0x8042C344: nop

    func_80048D4C(rdram, ctx);
        goto after_1;
    // 0x8042C344: nop

    after_1:
    // 0x8042C348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042C34C:
    // 0x8042C34C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042C350: jr          $ra
    // 0x8042C354: nop

    return;
    // 0x8042C354: nop

;}
RECOMP_FUNC void func_8044AB24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AB24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8044AB28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AB2C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x8044AB30: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x8044AB34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044AB38: jal         0x8044A558
    // 0x8044AB3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_8044A558(rdram, ctx);
        goto after_0;
    // 0x8044AB3C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8044AB40: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AB44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8044AB48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8044AB4C: bne         $v0, $zero, L_8044AB64
    if (ctx->r2 != 0) {
        // 0x8044AB50: nop
    
            goto L_8044AB64;
    }
    // 0x8044AB50: nop

    // 0x8044AB54: jal         0x80446310
    // 0x8044AB58: nop

    func_80446310(rdram, ctx);
        goto after_1;
    // 0x8044AB58: nop

    after_1:
    // 0x8044AB5C: b           L_8044AB88
    // 0x8044AB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AB88;
    // 0x8044AB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AB64:
    // 0x8044AB64: bne         $v0, $at, L_8044AB7C
    if (ctx->r2 != ctx->r1) {
        // 0x8044AB68: nop
    
            goto L_8044AB7C;
    }
    // 0x8044AB68: nop

    // 0x8044AB6C: jal         0x80446348
    // 0x8044AB70: nop

    func_80446348(rdram, ctx);
        goto after_2;
    // 0x8044AB70: nop

    after_2:
    // 0x8044AB74: b           L_8044AB88
    // 0x8044AB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8044AB88;
    // 0x8044AB78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AB7C:
    // 0x8044AB7C: jal         0x80446384
    // 0x8044AB80: nop

    func_80446384(rdram, ctx);
        goto after_3;
    // 0x8044AB80: nop

    after_3:
    // 0x8044AB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044AB88:
    // 0x8044AB88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044AB8C: jr          $ra
    // 0x8044AB90: nop

    return;
    // 0x8044AB90: nop

;}
RECOMP_FUNC void func_800612B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800612B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800612B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800612BC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800612C0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800612C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800612C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800612CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800612D0: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x800612D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800612D8: lh          $s1, 0x184($s3)
    ctx->r17 = MEM_H(ctx->r19, 0X184);
    // 0x800612DC: addiu       $s2, $s3, 0x188
    ctx->r18 = ADD32(ctx->r19, 0X188);
    // 0x800612E0: beql        $s1, $zero, L_80061398
    if (ctx->r17 == 0) {
        // 0x800612E4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80061398;
    }
    goto skip_0;
    // 0x800612E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800612E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800612EC: nop

L_800612F0:
    // 0x800612F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800612F4: beq         $v0, $zero, L_8006138C
    if (ctx->r2 == 0) {
        // 0x800612F8: nop
    
            goto L_8006138C;
    }
    // 0x800612F8: nop

    // 0x800612FC: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80061300: lw          $t6, 0x174($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X174);
    // 0x80061304: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80061308: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8006130C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80061310: beq         $t6, $zero, L_8006138C
    if (ctx->r14 == 0) {
        // 0x80061314: sw          $t6, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r14;
            goto L_8006138C;
    }
    // 0x80061314: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x80061318: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8006131C: bne         $s3, $t7, L_8006138C
    if (ctx->r19 != ctx->r15) {
        // 0x80061320: nop
    
            goto L_8006138C;
    }
    // 0x80061320: nop

    // 0x80061324: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x80061328: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006132C: lwc1        $f8, 0xC8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x80061330: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80061334: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80061338: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8006133C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80061340: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80061344: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80061348: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x8006134C: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80061350: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80061354: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80061358: nop

    // 0x8006135C: bc1t        L_80061384
    if (c1cs) {
        // 0x80061360: nop
    
            goto L_80061384;
    }
    // 0x80061360: nop

    // 0x80061364: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80061368: andi        $t9, $t8, 0xF00
    ctx->r25 = ctx->r24 & 0XF00;
    // 0x8006136C: bne         $t9, $zero, L_80061384
    if (ctx->r25 != 0) {
        // 0x80061370: nop
    
            goto L_80061384;
    }
    // 0x80061370: nop

    // 0x80061374: jal         0x80060624
    // 0x80061378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060624(rdram, ctx);
        goto after_0;
    // 0x80061378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006137C: bne         $v0, $zero, L_8006138C
    if (ctx->r2 != 0) {
        // 0x80061380: nop
    
            goto L_8006138C;
    }
    // 0x80061380: nop

L_80061384:
    // 0x80061384: jal         0x8006106C
    // 0x80061388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006106C(rdram, ctx);
        goto after_1;
    // 0x80061388: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8006138C:
    // 0x8006138C: bne         $s1, $zero, L_800612F0
    if (ctx->r17 != 0) {
        // 0x80061390: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800612F0;
    }
    // 0x80061390: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80061394: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80061398:
    // 0x80061398: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8006139C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800613A0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800613A4: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800613A8: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800613AC: jr          $ra
    // 0x800613B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800613B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_804F4D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F4D88: lw          $t6, 0x90($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X90);
    // 0x804F4D8C: lw          $a1, 0x24($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X24);
    // 0x804F4D90: addiu       $v1, $a0, 0x80
    ctx->r3 = ADD32(ctx->r4, 0X80);
    // 0x804F4D94: bne         $t6, $zero, L_804F4E18
    if (ctx->r14 != 0) {
        // 0x804F4D98: addiu       $v0, $a1, 0xC
        ctx->r2 = ADD32(ctx->r5, 0XC);
            goto L_804F4E18;
    }
    // 0x804F4D98: addiu       $v0, $a1, 0xC
    ctx->r2 = ADD32(ctx->r5, 0XC);
    // 0x804F4D9C: addiu       $v1, $a0, 0x80
    ctx->r3 = ADD32(ctx->r4, 0X80);
    // 0x804F4DA0: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x804F4DA4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x804F4DA8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x804F4DAC: beql        $at, $zero, L_804F4E10
    if (ctx->r1 == 0) {
        // 0x804F4DB0: sw          $zero, 0xC($v1)
        MEM_W(0XC, ctx->r3) = 0;
            goto L_804F4E10;
    }
    goto skip_0;
    // 0x804F4DB0: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    skip_0:
    // 0x804F4DB4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x804F4DB8: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x804F4DBC: lui         $t2, 0x8051
    ctx->r10 = S32(RELOC_HI16(273, 0X207BC) << 16);
    // 0x804F4DC0: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x804F4DC4: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x804F4DC8: lui         $t5, 0x8051
    ctx->r13 = S32(RELOC_HI16(273, 0X207B4) << 16);
    // 0x804F4DCC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804F4DD0: sll         $t1, $a0, 1
    ctx->r9 = S32(ctx->r4 << 1);
    // 0x804F4DD4: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804F4DD8: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x804F4DDC: lhu         $t2, 0x4A4C($t2)
    ctx->r10 = MEM_HU(ctx->r10, (int16_t)RELOC_LO16(273, 0X207BC));
    // 0x804F4DE0: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    // 0x804F4DE4: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x804F4DE8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804F4DEC: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x804F4DF0: lhu         $t5, 0x4A44($t5)
    ctx->r13 = MEM_HU(ctx->r13, (int16_t)RELOC_LO16(273, 0X207B4));
    // 0x804F4DF4: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x804F4DF8: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x804F4DFC: sw          $t8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r24;
    // 0x804F4E00: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804F4E04: b           L_804F4E24
    // 0x804F4E08: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
        goto L_804F4E24;
    // 0x804F4E08: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x804F4E0C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
L_804F4E10:
    // 0x804F4E10: jr          $ra
    // 0x804F4E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x804F4E14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804F4E18:
    // 0x804F4E18: lw          $t9, 0x10($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X10);
    // 0x804F4E1C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x804F4E20: sw          $t0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r8;
L_804F4E24:
    // 0x804F4E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804F4E28: jr          $ra
    // 0x804F4E2C: nop

    return;
    // 0x804F4E2C: nop

;}
RECOMP_FUNC void func_8003E590(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E590: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8003E594: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8003E598: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003E59C: beq         $a2, $zero, L_8003E5E4
    if (ctx->r6 == 0) {
        // 0x8003E5A0: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8003E5E4;
    }
    // 0x8003E5A0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8003E5A4: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003E5A8: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x8003E5AC: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8003E5B0:
    // 0x8003E5B0: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003E5B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8003E5B8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003E5BC: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x8003E5C0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8003E5C4: mflo        $t6
    ctx->r14 = lo;
    // 0x8003E5C8: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8003E5CC: lbu         $t7, 0x1202($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X1202);
    // 0x8003E5D0: bne         $v1, $t7, L_8003E5DC
    if (ctx->r3 != ctx->r15) {
        // 0x8003E5D4: nop
    
            goto L_8003E5DC;
    }
    // 0x8003E5D4: nop

    // 0x8003E5D8: sb          $t0, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = ctx->r8;
L_8003E5DC:
    // 0x8003E5DC: bne         $a2, $zero, L_8003E5B0
    if (ctx->r6 != 0) {
        // 0x8003E5E0: andi        $a1, $a1, 0xFFFF
        ctx->r5 = ctx->r5 & 0XFFFF;
            goto L_8003E5B0;
    }
    // 0x8003E5E0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_8003E5E4:
    // 0x8003E5E4: jr          $ra
    // 0x8003E5E8: nop

    return;
    // 0x8003E5E8: nop

;}
RECOMP_FUNC void func_80066FA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066FA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066FA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066FA8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80066FAC: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80066FB0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80066FB4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80066FB8: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x80066FBC: bc1f        L_8006705C
    if (!c1cs) {
        // 0x80066FC0: sw          $ra, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r31;
            goto L_8006705C;
    }
    // 0x80066FC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80066FC4: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80066FC8: nop

    // 0x80066FCC: bc1fl       L_80067018
    if (!c1cs) {
        // 0x80066FD0: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_80067018;
    }
    goto skip_0;
    // 0x80066FD0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_0:
    // 0x80066FD4: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x80066FD8: nop

    // 0x80066FDC: bc1fl       L_80066FFC
    if (!c1cs) {
        // 0x80066FE0: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_80066FFC;
    }
    goto skip_1;
    // 0x80066FE0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_1:
    // 0x80066FE4: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x80066FE8: jal         0x80066F2C
    // 0x80066FEC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80066F2C(rdram, ctx);
        goto after_0;
    // 0x80066FEC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_0:
    // 0x80066FF0: b           L_800670F8
    // 0x80066FF4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
        goto L_800670F8;
    // 0x80066FF4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80066FF8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80066FFC:
    // 0x80066FFC: jal         0x80066F2C
    // 0x80067000: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80066F2C(rdram, ctx);
        goto after_1;
    // 0x80067000: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_1:
    // 0x80067004: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80067008: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x8006700C: b           L_800670F8
    // 0x80067010: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x80067010: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80067014: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
L_80067018:
    // 0x80067018: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x8006701C: nop

    // 0x80067020: bc1fl       L_80067044
    if (!c1cs) {
        // 0x80067024: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_80067044;
    }
    goto skip_2;
    // 0x80067024: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_2:
    // 0x80067028: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8006702C: jal         0x80066F2C
    // 0x80067030: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80066F2C(rdram, ctx);
        goto after_2;
    // 0x80067030: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_2:
    // 0x80067034: addiu       $v1, $v0, 0x4000
    ctx->r3 = ADD32(ctx->r2, 0X4000);
    // 0x80067038: b           L_800670F8
    // 0x8006703C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x8006703C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80067040: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_80067044:
    // 0x80067044: jal         0x80066F2C
    // 0x80067048: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80066F2C(rdram, ctx);
        goto after_3;
    // 0x80067048: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_3:
    // 0x8006704C: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x80067050: subu        $v1, $t7, $v0
    ctx->r3 = SUB32(ctx->r15, ctx->r2);
    // 0x80067054: b           L_800670F8
    // 0x80067058: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x80067058: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_8006705C:
    // 0x8006705C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x80067060: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x80067064: bc1fl       L_800670BC
    if (!c1cs) {
        // 0x80067068: c.lt.s      $f20, $f22
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
            goto L_800670BC;
    }
    goto skip_3;
    // 0x80067068: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    skip_3:
    // 0x8006706C: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x80067070: c.le.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl <= ctx->f20.fl;
    // 0x80067074: nop

    // 0x80067078: bc1fl       L_800670A0
    if (!c1cs) {
        // 0x8006707C: mov.s       $f12, $f20
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
            goto L_800670A0;
    }
    goto skip_4;
    // 0x8006707C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    skip_4:
    // 0x80067080: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80067084: jal         0x80066F2C
    // 0x80067088: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80066F2C(rdram, ctx);
        goto after_4;
    // 0x80067088: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_4:
    // 0x8006708C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80067090: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80067094: b           L_800670F8
    // 0x80067098: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x80067098: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8006709C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800670A0:
    // 0x800670A0: jal         0x80066F2C
    // 0x800670A4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80066F2C(rdram, ctx);
        goto after_5;
    // 0x800670A4: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_5:
    // 0x800670A8: ori         $t8, $zero, 0xC000
    ctx->r24 = 0 | 0XC000;
    // 0x800670AC: subu        $v1, $t8, $v0
    ctx->r3 = SUB32(ctx->r24, ctx->r2);
    // 0x800670B0: b           L_800670F8
    // 0x800670B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x800670B4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800670B8: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
L_800670BC:
    // 0x800670BC: nop

    // 0x800670C0: bc1fl       L_800670E8
    if (!c1cs) {
        // 0x800670C4: mov.s       $f12, $f22
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
            goto L_800670E8;
    }
    goto skip_5;
    // 0x800670C4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    skip_5:
    // 0x800670C8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800670CC: jal         0x80066F2C
    // 0x800670D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    func_80066F2C(rdram, ctx);
        goto after_6;
    // 0x800670D0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_6:
    // 0x800670D4: ori         $at, $zero, 0xC000
    ctx->r1 = 0 | 0XC000;
    // 0x800670D8: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x800670DC: b           L_800670F8
    // 0x800670E0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
        goto L_800670F8;
    // 0x800670E0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800670E4: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_800670E8:
    // 0x800670E8: jal         0x80066F2C
    // 0x800670EC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    func_80066F2C(rdram, ctx);
        goto after_7;
    // 0x800670EC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_7:
    // 0x800670F0: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x800670F4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_800670F8:
    // 0x800670F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800670FC: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80067100: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80067104: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80067108: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006710C: jr          $ra
    // 0x80067110: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    return;
    // 0x80067110: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
;}
RECOMP_FUNC void func_8004E95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004E95C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8004E960: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004E964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004E968: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8004E96C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8004E970: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x8004E974: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004E978: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8004E97C: srl         $t7, $v0, 28
    ctx->r15 = S32(U32(ctx->r2) >> 28);
    // 0x8004E980: beq         $t7, $zero, L_8004EA14
    if (ctx->r15 == 0) {
        // 0x8004E984: lwc1        $f14, 0xC8($a0)
        ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_8004EA14;
    }
    // 0x8004E984: lwc1        $f14, 0xC8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8004E988: andi        $t8, $v0, 0xF00
    ctx->r24 = ctx->r2 & 0XF00;
    // 0x8004E98C: beq         $t8, $zero, L_8004E9CC
    if (ctx->r24 == 0) {
        // 0x8004E990: andi        $t9, $v0, 0xF000
        ctx->r25 = ctx->r2 & 0XF000;
            goto L_8004E9CC;
    }
    // 0x8004E990: andi        $t9, $v0, 0xF000
    ctx->r25 = ctx->r2 & 0XF000;
    // 0x8004E994: jal         0x80065954
    // 0x8004E998: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8004E998: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8004E99C: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9A0: jal         0x80065954
    // 0x8004E9A4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8004E9A4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8004E9A8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E9AC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8004E9B0: nop

    // 0x8004E9B4: bc1f        L_8004E9C4
    if (!c1cs) {
        // 0x8004E9B8: nop
    
            goto L_8004E9C4;
    }
    // 0x8004E9B8: nop

    // 0x8004E9BC: b           L_8004EA30
    // 0x8004E9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EA30;
    // 0x8004E9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004E9C4:
    // 0x8004E9C4: b           L_8004EA30
    // 0x8004E9C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004EA30;
    // 0x8004E9C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004E9CC:
    // 0x8004E9CC: beq         $t9, $zero, L_8004EA0C
    if (ctx->r25 == 0) {
        // 0x8004E9D0: nop
    
            goto L_8004EA0C;
    }
    // 0x8004E9D0: nop

    // 0x8004E9D4: jal         0x80065954
    // 0x8004E9D8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8004E9D8: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8004E9DC: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8004E9E0: jal         0x80065954
    // 0x8004E9E4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8004E9E4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8004E9E8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004E9EC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8004E9F0: nop

    // 0x8004E9F4: bc1f        L_8004EA04
    if (!c1cs) {
        // 0x8004E9F8: nop
    
            goto L_8004EA04;
    }
    // 0x8004E9F8: nop

    // 0x8004E9FC: b           L_8004EA30
    // 0x8004EA00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EA30;
    // 0x8004EA00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EA04:
    // 0x8004EA04: b           L_8004EA30
    // 0x8004EA08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8004EA30;
    // 0x8004EA08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004EA0C:
    // 0x8004EA0C: b           L_8004EA30
    // 0x8004EA10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004EA30;
    // 0x8004EA10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004EA14:
    // 0x8004EA14: andi        $t0, $v0, 0xF00
    ctx->r8 = ctx->r2 & 0XF00;
    // 0x8004EA18: beq         $t0, $zero, L_8004EA28
    if (ctx->r8 == 0) {
        // 0x8004EA1C: andi        $t1, $v0, 0xF000
        ctx->r9 = ctx->r2 & 0XF000;
            goto L_8004EA28;
    }
    // 0x8004EA1C: andi        $t1, $v0, 0xF000
    ctx->r9 = ctx->r2 & 0XF000;
    // 0x8004EA20: b           L_8004EA30
    // 0x8004EA24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8004EA30;
    // 0x8004EA24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004EA28:
    // 0x8004EA28: beq         $t1, $zero, L_8004EBFC
    if (ctx->r9 == 0) {
        // 0x8004EA2C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8004EBFC;
    }
    // 0x8004EA2C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8004EA30:
    // 0x8004EA30: beq         $v0, $zero, L_8004EA58
    if (ctx->r2 == 0) {
        // 0x8004EA34: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8004EA58;
    }
    // 0x8004EA34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004EA38: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004EA3C: beq         $v0, $at, L_8004EAA0
    if (ctx->r2 == ctx->r1) {
        // 0x8004EA40: lwc1        $f16, 0xC8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_8004EAA0;
    }
    // 0x8004EA40: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004EA44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004EA48: beq         $v0, $at, L_8004EAB8
    if (ctx->r2 == ctx->r1) {
        // 0x8004EA4C: lw          $t9, 0x54($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X54);
            goto L_8004EAB8;
    }
    // 0x8004EA4C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8004EA50: b           L_8004EAC8
    // 0x8004EA54: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8004EAC8;
    // 0x8004EA54: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8004EA58:
    // 0x8004EA58: jal         0x80049018
    // 0x8004EA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80049018(rdram, ctx);
        goto after_4;
    // 0x8004EA5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8004EA60: bne         $v0, $zero, L_8004EA7C
    if (ctx->r2 != 0) {
        // 0x8004EA64: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8004EA7C;
    }
    // 0x8004EA64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004EA68: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8004EA6C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8004EA70: lw          $v0, 0x40($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X40);
    // 0x8004EA74: b           L_8004EA8C
    // 0x8004EA78: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
        goto L_8004EA8C;
    // 0x8004EA78: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
L_8004EA7C:
    // 0x8004EA7C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8004EA80: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8004EA84: lw          $v0, 0x40($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X40);
    // 0x8004EA88: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
L_8004EA8C:
    // 0x8004EA8C: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x8004EA90: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8004EA94: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004EA98: b           L_8004EAC4
    // 0x8004EA9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_8004EAC4;
    // 0x8004EA9C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_8004EAA0:
    // 0x8004EAA0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8004EAA4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8004EAA8: lw          $v0, 0x40($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X40);
    // 0x8004EAAC: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8004EAB0: b           L_8004EAC4
    // 0x8004EAB4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_8004EAC4;
    // 0x8004EAB4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_8004EAB8:
    // 0x8004EAB8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8004EABC: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8004EAC0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
L_8004EAC4:
    // 0x8004EAC4: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_8004EAC8:
    // 0x8004EAC8: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    // 0x8004EACC: neg.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = -ctx->f16.fl;
    // 0x8004EAD0: jal         0x80081E8C
    // 0x8004EAD4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    fatan2(rdram, ctx);
        goto after_5;
    // 0x8004EAD4: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8004EAD8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004EADC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004EAE0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8004EAE4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004EAE8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004EAEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004EAF0: lwc1        $f18, 0x8F4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X8F4);
    // 0x8004EAF4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8004EAF8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8004EAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004EB00: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004EB04: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8004EB08: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004EB0C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8004EB10: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x8004EB14: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8004EB18: jal         0x8004A97C
    // 0x8004EB1C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    func_8004A97C(rdram, ctx);
        goto after_6;
    // 0x8004EB1C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    after_6:
    // 0x8004EB20: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8004EB24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8004EB28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004EB2C: beql        $t2, $zero, L_8004EB70
    if (ctx->r10 == 0) {
        // 0x8004EB30: add.s       $f4, $f2, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_8004EB70;
    }
    goto skip_0;
    // 0x8004EB30: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    skip_0:
    // 0x8004EB34: lwc1        $f10, 0x8F8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X8F8);
    // 0x8004EB38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004EB3C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8004EB40: nop

    // 0x8004EB44: bc1tl       L_8004EB70
    if (c1cs) {
        // 0x8004EB48: add.s       $f4, $f2, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_8004EB70;
    }
    goto skip_1;
    // 0x8004EB48: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    skip_1:
    // 0x8004EB4C: lwc1        $f18, 0x8FC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X8FC);
    // 0x8004EB50: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8004EB54: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004EB58: nop

    // 0x8004EB5C: bc1tl       L_8004EB70
    if (c1cs) {
        // 0x8004EB60: add.s       $f4, $f2, $f2
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
            goto L_8004EB70;
    }
    goto skip_2;
    // 0x8004EB60: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    skip_2:
    // 0x8004EB64: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004EB68: nop

    // 0x8004EB6C: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
L_8004EB70:
    // 0x8004EB70: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004EB74: jal         0x800659EC
    // 0x8004EB78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_800659EC(rdram, ctx);
        goto after_7;
    // 0x8004EB78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_7:
    // 0x8004EB7C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004EB80: jal         0x80066E88
    // 0x8004EB84: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_8;
    // 0x8004EB84: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x8004EB88: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004EB8C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004EB90: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
    // 0x8004EB94: jal         0x80066DE4
    // 0x8004EB98: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066DE4(rdram, ctx);
        goto after_9;
    // 0x8004EB98: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_9:
    // 0x8004EB9C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004EBA0: lw          $v0, 0x12C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X12C);
    // 0x8004EBA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8004EBA8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8004EBAC: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8004EBB0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8004EBB4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8004EBB8: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8004EBBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004EBC0: xori        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 ^ 0X1;
    // 0x8004EBC4: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8004EBC8: lwc1        $f8, 0x1010($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1010);
    // 0x8004EBCC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004EBD0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8004EBD4: nop

    // 0x8004EBD8: bc1fl       L_8004EC00
    if (!c1cs) {
        // 0x8004EBDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004EC00;
    }
    goto skip_3;
    // 0x8004EBDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8004EBE0: lw          $t5, 0x138($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X138);
    // 0x8004EBE4: lw          $t7, 0x134($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X134);
    // 0x8004EBE8: sw          $t4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->r12;
    // 0x8004EBEC: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x8004EBF0: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x8004EBF4: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    // 0x8004EBF8: sw          $t8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->r24;
L_8004EBFC:
    // 0x8004EBFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004EC00:
    // 0x8004EC00: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004EC04: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8004EC08: jr          $ra
    // 0x8004EC0C: nop

    return;
    // 0x8004EC0C: nop

;}
RECOMP_FUNC void func_805ADFF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADFF4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADFF8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADFFC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE000: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE004: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE008: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE00C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE010: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE014: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE018: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE01C: jr          $ra
    // 0x805AE020: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE020: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80426FCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426FCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80426FD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80426FD4: jal         0x80426E54
    // 0x80426FD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80426E54(rdram, ctx);
        goto after_0;
    // 0x80426FD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80426FDC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80426FE0: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(38, 0XEF8) << 16);
    // 0x80426FE4: lui         $a2, 0x8042
    ctx->r6 = S32(RELOC_HI16(38, 0XF7C) << 16);
    // 0x80426FE8: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x80426FEC: addiu       $a2, $a2, 0x757C
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(38, 0XF7C));
    // 0x80426FF0: addiu       $a1, $a1, 0x74F8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(38, 0XEF8));
    // 0x80426FF4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80426FF8: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80426FFC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80427000: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80427004: jal         0x8042668C
    // 0x80427008: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_8042668C(rdram, ctx);
        goto after_1;
    // 0x80427008: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x8042700C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80427010: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80427014: jr          $ra
    // 0x80427018: nop

    return;
    // 0x80427018: nop

;}
RECOMP_FUNC void func_806AA200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AA200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806AA204: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AA208: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AA20C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AA210: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AA214: jal         0x806A9BBC
    // 0x806AA218: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_806A9BBC(rdram, ctx);
        goto after_0;
    // 0x806AA218: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x806AA21C: bne         $v0, $zero, L_806AA234
    if (ctx->r2 != 0) {
        // 0x806AA220: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806AA234;
    }
    // 0x806AA220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806AA224: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806AA228: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806AA22C: jal         0x806AA784
    // 0x806AA230: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806AA230: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
L_806AA234:
    // 0x806AA234: jal         0x806A99EC
    // 0x806AA238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806A99EC(rdram, ctx);
        goto after_2;
    // 0x806AA238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806AA23C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x806AA240: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x806AA244: beql        $a1, $zero, L_806AA280
    if (ctx->r5 == 0) {
        // 0x806AA248: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AA280;
    }
    goto skip_0;
    // 0x806AA248: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806AA24C: jal         0x80047EB0
    // 0x806AA250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80047EB0(rdram, ctx);
        goto after_3;
    // 0x806AA250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806AA254: bnel        $v0, $zero, L_806AA280
    if (ctx->r2 != 0) {
        // 0x806AA258: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AA280;
    }
    goto skip_1;
    // 0x806AA258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806AA25C: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x806AA260: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x806AA264: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806AA268: beq         $v0, $zero, L_806AA27C
    if (ctx->r2 == 0) {
        // 0x806AA26C: sw          $zero, 0xC($t8)
        MEM_W(0XC, ctx->r24) = 0;
            goto L_806AA27C;
    }
    // 0x806AA26C: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x806AA270: addiu       $t9, $t9, -0x7218
    ctx->r25 = ADD32(ctx->r25, -0X7218);
    // 0x806AA274: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x806AA278: sw          $zero, 0x1D8($v0)
    MEM_W(0X1D8, ctx->r2) = 0;
L_806AA27C:
    // 0x806AA27C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AA280:
    // 0x806AA280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AA284: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806AA288: jr          $ra
    // 0x806AA28C: nop

    return;
    // 0x806AA28C: nop

;}
RECOMP_FUNC void func_806B005C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B005C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x806B0060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B0064: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806B0068: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x806B006C: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x806B0070: lwc1        $f0, 0x64($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X64);
    // 0x806B0074: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x806B0078: lh          $v1, -0x7682($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X7682);
    // 0x806B007C: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x806B0080: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806B0084: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x806B0088: bne         $v1, $zero, L_806B0148
    if (ctx->r3 != 0) {
        // 0x806B008C: mov.s       $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
            goto L_806B0148;
    }
    // 0x806B008C: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x806B0090: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x806B0094: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B0098: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x806B009C: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x806B00A0: sub.s       $f12, $f14, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x806B00A4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x806B00A8: sw          $a2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r6;
    // 0x806B00AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x806B00B0: jal         0x80065954
    // 0x806B00B4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x806B00B4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x806B00B8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806B00BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806B00C0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806B00C4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x806B00C8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x806B00CC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x806B00D0: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x806B00D4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806B00D8: bc1f        L_806B0114
    if (!c1cs) {
        // 0x806B00DC: lwc1        $f16, 0x40($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
            goto L_806B0114;
    }
    // 0x806B00DC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806B00E0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806B00E4: or          $t6, $zero, $zero
    ctx->r14 = 0 | 0;
    // 0x806B00E8: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16E0) << 16);
    // 0x806B00EC: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x806B00F0: nop

    // 0x806B00F4: bc1fl       L_806B0104
    if (!c1cs) {
        // 0x806B00F8: sll         $t7, $t6, 2
        ctx->r15 = S32(ctx->r14 << 2);
            goto L_806B0104;
    }
    goto skip_0;
    // 0x806B00F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    skip_0:
    // 0x806B00FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x806B0100: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
L_806B0104:
    // 0x806B0104: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x806B0108: lwc1        $f10, 0x1670($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16E0));
    // 0x806B010C: b           L_806B0230
    // 0x806B0110: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
        goto L_806B0230;
    // 0x806B0110: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
L_806B0114:
    // 0x806B0114: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806B0118: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x806B011C: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X16E8) << 16);
    // 0x806B0120: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x806B0124: nop

    // 0x806B0128: bc1fl       L_806B0138
    if (!c1cs) {
        // 0x806B012C: sll         $t9, $t8, 2
        ctx->r25 = S32(ctx->r24 << 2);
            goto L_806B0138;
    }
    goto skip_1;
    // 0x806B012C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    skip_1:
    // 0x806B0130: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806B0134: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
L_806B0138:
    // 0x806B0138: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x806B013C: lwc1        $f18, 0x1678($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X16E8));
    // 0x806B0140: b           L_806B0230
    // 0x806B0144: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
        goto L_806B0230;
    // 0x806B0144: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
L_806B0148:
    // 0x806B0148: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x806B014C: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x806B0150: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x806B0154: nop

    // 0x806B0158: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x806B015C: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x806B0160: multu       $v1, $t3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x806B0164: mflo        $t4
    ctx->r12 = lo;
    // 0x806B0168: bgezl       $t4, L_806B01D8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x806B016C: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_806B01D8;
    }
    goto skip_2;
    // 0x806B016C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x806B0170: addiu       $v0, $a0, 0x50
    ctx->r2 = ADD32(ctx->r4, 0X50);
    // 0x806B0174: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B0178: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1700) << 16);
    // 0x806B017C: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x806B0180: nop

    // 0x806B0184: bc1fl       L_806B01A0
    if (!c1cs) {
        // 0x806B0188: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_806B01A0;
    }
    goto skip_3;
    // 0x806B0188: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_3:
    // 0x806B018C: lwc1        $f6, 0x1690($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1700));
    // 0x806B0190: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806B0194: b           L_806B0230
    // 0x806B0198: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
        goto L_806B0230;
    // 0x806B0198: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x806B019C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_806B01A0:
    // 0x806B01A0: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1704) << 16);
    // 0x806B01A4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x806B01A8: nop

    // 0x806B01AC: bc1fl       L_806B0234
    if (!c1cs) {
        // 0x806B01B0: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_806B0234;
    }
    goto skip_4;
    // 0x806B01B0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_4:
    // 0x806B01B4: lwc1        $f8, 0x1694($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1704));
    // 0x806B01B8: sub.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x806B01BC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x806B01C0: nop

    // 0x806B01C4: bc1fl       L_806B0234
    if (!c1cs) {
        // 0x806B01C8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_806B0234;
    }
    goto skip_5;
    // 0x806B01C8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_5:
    // 0x806B01CC: b           L_806B0230
    // 0x806B01D0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_806B0230;
    // 0x806B01D0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x806B01D4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_806B01D8:
    // 0x806B01D8: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1708) << 16);
    // 0x806B01DC: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x806B01E0: nop

    // 0x806B01E4: bc1fl       L_806B0200
    if (!c1cs) {
        // 0x806B01E8: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_806B0200;
    }
    goto skip_6;
    // 0x806B01E8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_6:
    // 0x806B01EC: lwc1        $f10, 0x1698($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1708));
    // 0x806B01F0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x806B01F4: b           L_806B0230
    // 0x806B01F8: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_806B0230;
    // 0x806B01F8: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x806B01FC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_806B0200:
    // 0x806B0200: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X170C) << 16);
    // 0x806B0204: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x806B0208: nop

    // 0x806B020C: bc1fl       L_806B0234
    if (!c1cs) {
        // 0x806B0210: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_806B0234;
    }
    goto skip_7;
    // 0x806B0210: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_7:
    // 0x806B0214: lwc1        $f18, 0x169C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X170C));
    // 0x806B0218: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x806B021C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x806B0220: nop

    // 0x806B0224: bc1fl       L_806B0234
    if (!c1cs) {
        // 0x806B0228: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_806B0234;
    }
    goto skip_8;
    // 0x806B0228: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_8:
    // 0x806B022C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_806B0230:
    // 0x806B0230: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_806B0234:
    // 0x806B0234: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806B0238: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x806B023C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806B0240: nop

    // 0x806B0244: bc1fl       L_806B0258
    if (!c1cs) {
        // 0x806B0248: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806B0258;
    }
    goto skip_9;
    // 0x806B0248: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_9:
    // 0x806B024C: b           L_806B027C
    // 0x806B0250: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_806B027C;
    // 0x806B0250: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x806B0254: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806B0258:
    // 0x806B0258: nop

    // 0x806B025C: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x806B0260: nop

    // 0x806B0264: bc1fl       L_806B0278
    if (!c1cs) {
        // 0x806B0268: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_806B0278;
    }
    goto skip_10;
    // 0x806B0268: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_10:
    // 0x806B026C: b           L_806B0278
    // 0x806B0270: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_806B0278;
    // 0x806B0270: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x806B0274: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_806B0278:
    // 0x806B0278: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_806B027C:
    // 0x806B027C: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x806B0280: swc1        $f2, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f2.u32l;
    // 0x806B0284: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806B0288: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x806B028C: c.lt.s      $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f8.fl < ctx->f14.fl;
    // 0x806B0290: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x806B0294: bc1fl       L_806B02C8
    if (!c1cs) {
        // 0x806B0298: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B02C8;
    }
    goto skip_11;
    // 0x806B0298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x806B029C: jal         0x8001D770
    // 0x806B02A0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    func_8001D770(rdram, ctx);
        goto after_1;
    // 0x806B02A0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_1:
    // 0x806B02A4: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x806B02A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806B02AC: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806B02B0: jal         0x80067BF8
    // 0x806B02B4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_2;
    // 0x806B02B4: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_2:
    // 0x806B02B8: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    // 0x806B02BC: jal         0x80067818
    // 0x806B02C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806B02C0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806B02C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B02C8:
    // 0x806B02C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x806B02CC: jr          $ra
    // 0x806B02D0: nop

    return;
    // 0x806B02D0: nop

;}
RECOMP_FUNC void func_80675194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675194: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80675198: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8067519C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806751A0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x806751A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806751A8: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(532, 0X688) << 16);
    // 0x806751AC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x806751B0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806751B4: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806751B8: lwc1        $f6, 0x55D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X688));
    // 0x806751BC: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(532, 0X628) << 16);
    // 0x806751C0: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x806751C4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x806751C8: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x806751CC: addiu       $t7, $t7, 0x5284
    ctx->r15 = ADD32(ctx->r15, 0X5284);
    // 0x806751D0: bc1f        L_806751E4
    if (!c1cs) {
        // 0x806751D4: nop
    
            goto L_806751E4;
    }
    // 0x806751D4: nop

    // 0x806751D8: lwc1        $f0, 0x5578($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(532, 0X628));
    // 0x806751DC: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806751E0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
L_806751E4:
    // 0x806751E4: jr          $ra
    // 0x806751E8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x806751E8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_806D17C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D17C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806D17C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806D17CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806D17D0: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D17D4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806D17D8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x806D17DC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806D17E0: jal         0x8004700C
    // 0x806D17E4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806D17E4: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x806D17E8: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D17EC: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D17F0: lw          $t7, 0xD8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0XD8);
    // 0x806D17F4: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x806D17F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x806D17FC: beq         $v0, $zero, L_806D1ADC
    if (ctx->r2 == 0) {
        // 0x806D1800: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_806D1ADC;
    }
    // 0x806D1800: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x806D1804: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x806D1808: lbu         $t8, 0xF4($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0XF4);
    // 0x806D180C: bnel        $t8, $zero, L_806D1928
    if (ctx->r24 != 0) {
        // 0x806D1810: lwc1        $f6, 0x4($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
            goto L_806D1928;
    }
    goto skip_0;
    // 0x806D1810: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    skip_0:
    // 0x806D1814: lw          $v1, 0xE88($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XE88);
    // 0x806D1818: lw          $t9, 0x24($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X24);
    // 0x806D181C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x806D1820: addiu       $t2, $t9, 0x2
    ctx->r10 = ADD32(ctx->r25, 0X2);
    // 0x806D1824: bne         $t2, $t3, L_806D1914
    if (ctx->r10 != ctx->r11) {
        // 0x806D1828: nop
    
            goto L_806D1914;
    }
    // 0x806D1828: nop

    // 0x806D182C: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    // 0x806D1830: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x806D1834: beq         $t4, $at, L_806D1914
    if (ctx->r12 == ctx->r1) {
        // 0x806D1838: nop
    
            goto L_806D1914;
    }
    // 0x806D1838: nop

    // 0x806D183C: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x806D1840: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x806D1844: beq         $v1, $at, L_806D1914
    if (ctx->r3 == ctx->r1) {
        // 0x806D1848: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_806D1914;
    }
    // 0x806D1848: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806D184C: beq         $v1, $at, L_806D1914
    if (ctx->r3 == ctx->r1) {
        // 0x806D1850: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_806D1914;
    }
    // 0x806D1850: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x806D1854: beq         $v1, $at, L_806D1914
    if (ctx->r3 == ctx->r1) {
        // 0x806D1858: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_806D1914;
    }
    // 0x806D1858: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x806D185C: beq         $v1, $at, L_806D1914
    if (ctx->r3 == ctx->r1) {
        // 0x806D1860: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_806D1914;
    }
    // 0x806D1860: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x806D1864: beq         $v1, $at, L_806D1914
    if (ctx->r3 == ctx->r1) {
        // 0x806D1868: nop
    
            goto L_806D1914;
    }
    // 0x806D1868: nop

    // 0x806D186C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806D1870: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D1874: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1710) << 16);
    // 0x806D1878: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x806D187C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x806D1880: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
    // 0x806D1884: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x806D1888: lwc1        $f6, 0x2CD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1710));
    // 0x806D188C: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x806D1890: lbu         $t5, 0x165($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X165);
    // 0x806D1894: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D1898: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806D189C: bne         $t5, $at, L_806D18B0
    if (ctx->r13 != ctx->r1) {
        // 0x806D18A0: swc1        $f8, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
            goto L_806D18B0;
    }
    // 0x806D18A0: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x806D18A4: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806D18A8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x806D18AC: sb          $zero, 0x165($t6)
    MEM_B(0X165, ctx->r14) = 0;
L_806D18B0:
    // 0x806D18B0: lw          $t7, 0x478($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X478);
    // 0x806D18B4: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x806D18B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D18BC: lwc1        $f10, 0x30($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X30);
    // 0x806D18C0: swc1        $f10, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f10.u32l;
    // 0x806D18C4: lw          $t8, 0x478($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X478);
    // 0x806D18C8: lwc1        $f16, 0x34($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X34);
    // 0x806D18CC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x806D18D0: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x806D18D4: jal         0x8002FDF8
    // 0x806D18D8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    func_8002FDF8(rdram, ctx);
        goto after_1;
    // 0x806D18D8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_1:
    // 0x806D18DC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806D18E0: jal         0x80067BBC
    // 0x806D18E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806D18E4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x806D18E8: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    // 0x806D18EC: jal         0x80067818
    // 0x806D18F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x806D18F0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806D18F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806D18F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D18FC: jal         0x806D2BCC
    // 0x806D1900: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_806D2BCC(rdram, ctx);
        goto after_4;
    // 0x806D1900: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x806D1904: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D1908: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D190C: b           L_806D1924
    // 0x806D1910: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
        goto L_806D1924;
    // 0x806D1910: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
L_806D1914:
    // 0x806D1914: jal         0x800447C8
    // 0x806D1918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x806D1918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806D191C: b           L_806D1AE0
    // 0x806D1920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D1AE0;
    // 0x806D1920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1924:
    // 0x806D1924: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
L_806D1928:
    // 0x806D1928: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806D192C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x806D1930: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D1934: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x806D1938: nop

    // 0x806D193C: bc1fl       L_806D19B8
    if (!c1cs) {
        // 0x806D1940: lw          $t3, 0xC($a3)
        ctx->r11 = MEM_W(ctx->r7, 0XC);
            goto L_806D19B8;
    }
    goto skip_1;
    // 0x806D1940: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    skip_1:
    // 0x806D1944: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x806D1948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D194C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x806D1950: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x806D1954: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D1958: bc1fl       L_806D19B8
    if (!c1cs) {
        // 0x806D195C: lw          $t3, 0xC($a3)
        ctx->r11 = MEM_W(ctx->r7, 0XC);
            goto L_806D19B8;
    }
    goto skip_2;
    // 0x806D195C: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
    skip_2:
    // 0x806D1960: sb          $v0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r2;
    // 0x806D1964: sb          $v0, 0x165($t1)
    MEM_B(0X165, ctx->r9) = ctx->r2;
    // 0x806D1968: swc1        $f2, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f2.u32l;
    // 0x806D196C: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x806D1970: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x806D1974: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D1978: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806D197C: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X1664) << 16);
    // 0x806D1980: swc1        $f12, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f12.u32l;
    // 0x806D1984: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x806D1988: swc1        $f12, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f12.u32l;
    // 0x806D198C: lw          $t9, 0xA68($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XA68);
    // 0x806D1990: addiu       $a1, $a1, 0x2C24
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X1664));
    // 0x806D1994: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D1998: lw          $t2, 0x10($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X10);
    // 0x806D199C: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D19A0: lw          $t9, 0x18($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X18);
    // 0x806D19A4: jalr        $t9
    // 0x806D19A8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x806D19A8: nop

    after_6:
    // 0x806D19AC: b           L_806D1AE0
    // 0x806D19B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806D1AE0;
    // 0x806D19B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806D19B4: lw          $t3, 0xC($a3)
    ctx->r11 = MEM_W(ctx->r7, 0XC);
L_806D19B8:
    // 0x806D19B8: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x806D19BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D19C0: bne         $t3, $zero, L_806D1A0C
    if (ctx->r11 != 0) {
        // 0x806D19C4: addiu       $v1, $s0, 0xC4
        ctx->r3 = ADD32(ctx->r16, 0XC4);
            goto L_806D1A0C;
    }
    // 0x806D19C4: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806D19C8: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1714) << 16);
    // 0x806D19CC: lwc1        $f14, 0x2CD4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1714));
    // 0x806D19D0: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x806D19D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806D19D8: nop

    // 0x806D19DC: bc1fl       L_806D1A38
    if (!c1cs) {
        // 0x806D19E0: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_806D1A38;
    }
    goto skip_3;
    // 0x806D19E0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_3:
    // 0x806D19E4: lw          $t4, 0x138($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X138);
    // 0x806D19E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806D19EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x806D19F0: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x806D19F4: sw          $t5, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r13;
    // 0x806D19F8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x806D19FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806D1A00: sw          $t5, 0x138($t7)
    MEM_W(0X138, ctx->r15) = ctx->r13;
    // 0x806D1A04: b           L_806D1A34
    // 0x806D1A08: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
        goto L_806D1A34;
    // 0x806D1A08: sw          $t8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r24;
L_806D1A0C:
    // 0x806D1A0C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806D1A10: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X1718) << 16);
    // 0x806D1A14: lwc1        $f14, 0x2CD8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X1718));
    // 0x806D1A18: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x806D1A1C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x806D1A20: nop

    // 0x806D1A24: bc1fl       L_806D1A38
    if (!c1cs) {
        // 0x806D1A28: swc1        $f0, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
            goto L_806D1A38;
    }
    goto skip_4;
    // 0x806D1A28: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    skip_4:
    // 0x806D1A2C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x806D1A30: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_806D1A34:
    // 0x806D1A34: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
L_806D1A38:
    // 0x806D1A38: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x806D1A3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D1A40: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x806D1A44: swc1        $f0, 0x6C($t2)
    MEM_W(0X6C, ctx->r10) = ctx->f0.u32l;
    // 0x806D1A48: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x806D1A4C: beq         $v0, $zero, L_806D1A5C
    if (ctx->r2 == 0) {
        // 0x806D1A50: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_806D1A5C;
    }
    // 0x806D1A50: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x806D1A54: sw          $t9, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r25;
    // 0x806D1A58: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_806D1A5C:
    // 0x806D1A5C: bne         $v0, $at, L_806D1A80
    if (ctx->r2 != ctx->r1) {
        // 0x806D1A60: lui         $at, 0xC080
        ctx->r1 = S32(0XC080 << 16);
            goto L_806D1A80;
    }
    // 0x806D1A60: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806D1A64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806D1A68: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806D1A6C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806D1A70: swc1        $f14, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f14.u32l;
    // 0x806D1A74: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x806D1A78: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x806D1A7C: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
L_806D1A80:
    // 0x806D1A80: bnel        $v0, $zero, L_806D1A9C
    if (ctx->r2 != 0) {
        // 0x806D1A84: lw          $t3, 0x20($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X20);
            goto L_806D1A9C;
    }
    goto skip_5;
    // 0x806D1A84: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    skip_5:
    // 0x806D1A88: jal         0x80048F84
    // 0x806D1A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x806D1A8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x806D1A90: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x806D1A94: addiu       $t0, $t0, 0x7EA0
    ctx->r8 = ADD32(ctx->r8, 0X7EA0);
    // 0x806D1A98: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
L_806D1A9C:
    // 0x806D1A9C: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x806D1AA0: bnel        $t4, $zero, L_806D1AE0
    if (ctx->r12 != 0) {
        // 0x806D1AA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D1AE0;
    }
    goto skip_6;
    // 0x806D1AA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x806D1AA8: lbu         $t5, 0x165($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X165);
    // 0x806D1AAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806D1AB0: beql        $t5, $at, L_806D1AE0
    if (ctx->r13 == ctx->r1) {
        // 0x806D1AB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806D1AE0;
    }
    goto skip_7;
    // 0x806D1AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x806D1AB8: lw          $t6, 0xA68($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XA68);
    // 0x806D1ABC: lui         $a1, 0x806D
    ctx->r5 = S32(RELOC_HI16(610, 0X1658) << 16);
    // 0x806D1AC0: addiu       $a1, $a1, 0x2C18
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(610, 0X1658));
    // 0x806D1AC4: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x806D1AC8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x806D1ACC: addiu       $a2, $zero, 0x400E
    ctx->r6 = ADD32(0, 0X400E);
    // 0x806D1AD0: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x806D1AD4: jalr        $t9
    // 0x806D1AD8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x806D1AD8: nop

    after_8:
L_806D1ADC:
    // 0x806D1ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806D1AE0:
    // 0x806D1AE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806D1AE4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806D1AE8: jr          $ra
    // 0x806D1AEC: nop

    return;
    // 0x806D1AEC: nop

;}
RECOMP_FUNC void func_807AF7D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AF7D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x807AF7DC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x807AF7E0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x807AF7E4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x807AF7E8: bne         $v0, $at, L_807AF894
    if (ctx->r2 != ctx->r1) {
        // 0x807AF7EC: lui         $at, 0x41C0
        ctx->r1 = S32(0X41C0 << 16);
            goto L_807AF894;
    }
    // 0x807AF7EC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x807AF7F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807AF7F4: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x807AF7F8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x807AF7FC: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x807AF800: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x807AF804: nop

    // 0x807AF808: bc1fl       L_807AF84C
    if (!c1cs) {
        // 0x807AF80C: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_807AF84C;
    }
    goto skip_0;
    // 0x807AF80C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x807AF810: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x807AF814: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x807AF818: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x807AF81C: beq         $v0, $zero, L_807AF894
    if (ctx->r2 == 0) {
        // 0x807AF820: nop
    
            goto L_807AF894;
    }
    // 0x807AF820: nop

    // 0x807AF824: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF828: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF82C: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF830: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x807AF834: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x807AF838: bne         $t8, $at, L_807AF894
    if (ctx->r24 != ctx->r1) {
        // 0x807AF83C: nop
    
            goto L_807AF894;
    }
    // 0x807AF83C: nop

    // 0x807AF840: jr          $ra
    // 0x807AF844: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    return;
    // 0x807AF844: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x807AF848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_807AF84C:
    // 0x807AF84C: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807AF850: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x807AF854: nop

    // 0x807AF858: bc1f        L_807AF894
    if (!c1cs) {
        // 0x807AF85C: nop
    
            goto L_807AF894;
    }
    // 0x807AF85C: nop

    // 0x807AF860: lw          $t0, -0x77F0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X77F0);
    // 0x807AF864: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x807AF868: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x807AF86C: beq         $v0, $zero, L_807AF894
    if (ctx->r2 == 0) {
        // 0x807AF870: nop
    
            goto L_807AF894;
    }
    // 0x807AF870: nop

    // 0x807AF874: lw          $v1, 0x1F4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1F4);
    // 0x807AF878: lui         $at, 0xEDCB
    ctx->r1 = S32(0XEDCB << 16);
    // 0x807AF87C: ori         $at, $at, 0xA987
    ctx->r1 = ctx->r1 | 0XA987;
    // 0x807AF880: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x807AF884: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x807AF888: bne         $t2, $at, L_807AF894
    if (ctx->r10 != ctx->r1) {
        // 0x807AF88C: nop
    
            goto L_807AF894;
    }
    // 0x807AF88C: nop

    // 0x807AF890: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
L_807AF894:
    // 0x807AF894: jr          $ra
    // 0x807AF898: nop

    return;
    // 0x807AF898: nop

;}
RECOMP_FUNC void func_805D1720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D1720: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805D1724: lui         $t6, 0x805D
    ctx->r14 = S32(RELOC_HI16(468, 0X158) << 16);
    // 0x805D1728: addiu       $t6, $t6, 0x1868
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(468, 0X158));
    // 0x805D172C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805D1730: jr          $ra
    // 0x805D1734: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805D1734: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80446048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446048: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044604C: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80446050: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446054: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446058: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8044605C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446060: jr          $ra
    // 0x80446064: sw          $t7, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r15;
    return;
    // 0x80446064: sw          $t7, 0x6CA0($at)
    MEM_W(0X6CA0, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_806D3AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D3AD4: jr          $ra
    // 0x806D3AD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D3AD8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805E4B90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4B90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E4B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E4B98: jal         0x805E41AC
    // 0x805E4B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805E41AC(rdram, ctx);
        goto after_0;
    // 0x805E4B9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805E4BA0: jal         0x80045BD8
    // 0x805E4BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x805E4BA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805E4BA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E4BAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805E4BB0: jr          $ra
    // 0x805E4BB4: nop

    return;
    // 0x805E4BB4: nop

;}
RECOMP_FUNC void func_80583CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80583CCC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80583CD0: beql        $at, $zero, L_80583CE4
    if (ctx->r1 == 0) {
        // 0x80583CD4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80583CE4;
    }
    goto skip_0;
    // 0x80583CD4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x80583CD8: jr          $ra
    // 0x80583CDC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x80583CDC: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80583CE0: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_80583CE4:
    // 0x80583CE4: beq         $at, $zero, L_80583D20
    if (ctx->r1 == 0) {
        // 0x80583CE8: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_80583D20;
    }
    // 0x80583CE8: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x80583CEC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80583CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583CF4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583CF8: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80583CFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583D00: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x80583D04: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80583D08: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80583D0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583D10: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80583D14: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80583D18: jr          $ra
    // 0x80583D1C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x80583D1C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_80583D20:
    // 0x80583D20: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80583D24: beq         $at, $zero, L_80583D3C
    if (ctx->r1 == 0) {
        // 0x80583D28: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_80583D3C;
    }
    // 0x80583D28: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x80583D2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583D30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80583D34: jr          $ra
    // 0x80583D38: nop

    return;
    // 0x80583D38: nop

L_80583D3C:
    // 0x80583D3C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80583D40: beq         $at, $zero, L_80583D80
    if (ctx->r1 == 0) {
        // 0x80583D44: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_80583D80;
    }
    // 0x80583D44: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80583D48: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x80583D4C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80583D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80583D54: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80583D58: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80583D5C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80583D60: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x80583D64: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80583D68: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80583D6C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80583D70: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80583D74: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80583D78: jr          $ra
    // 0x80583D7C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x80583D7C: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_80583D80:
    // 0x80583D80: jr          $ra
    // 0x80583D84: nop

    return;
    // 0x80583D84: nop

;}
RECOMP_FUNC void func_8002CAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CAB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CAB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CABC: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002CAC0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8002CAC4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002CAC8: addiu       $t6, $t6, 0x14B4
    ctx->r14 = ADD32(ctx->r14, 0X14B4);
    // 0x8002CACC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x8002CAD0: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
    // 0x8002CAD4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002CAD8: swc1        $f4, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f4.u32l;
    // 0x8002CADC: lwc1        $f6, -0x64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X64);
    // 0x8002CAE0: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x8002CAE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002CAE8: jal         0x80040C0C
    // 0x8002CAEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80040C0C(rdram, ctx);
        goto after_0;
    // 0x8002CAEC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002CAF0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CAF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002CAF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002CAFC: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x8002CB00: addiu       $t8, $t8, 0x33B4
    ctx->r24 = ADD32(ctx->r24, 0X33B4);
    // 0x8002CB04: sb          $t7, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r15;
    // 0x8002CB08: sw          $t8, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r24;
    // 0x8002CB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CB14: jr          $ra
    // 0x8002CB18: nop

    return;
    // 0x8002CB18: nop

;}
RECOMP_FUNC void func_804380B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804380B8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804380BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804380C0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804380C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804380C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x804380CC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x804380D0: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x804380D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804380D8: nop

    // 0x804380DC: bc1fl       L_80438130
    if (!c1cs) {
        // 0x804380E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80438130;
    }
    goto skip_0;
    // 0x804380E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804380E4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804380E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804380EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804380F0: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x804380F4: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x804380F8: jal         0x8004A97C
    // 0x804380FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8004A97C(rdram, ctx);
        goto after_0;
    // 0x804380FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80438100: jal         0x80066E88
    // 0x80438104: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x80438104: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80438108: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8043810C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80438110: lwc1        $f10, 0x14($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80438114: addiu       $v0, $a2, 0xC4
    ctx->r2 = ADD32(ctx->r6, 0XC4);
    // 0x80438118: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8043811C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80438120: nop

    // 0x80438124: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80438128: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8043812C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80438130:
    // 0x80438130: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80438134: jr          $ra
    // 0x80438138: nop

    return;
    // 0x80438138: nop

;}
RECOMP_FUNC void func_806785F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806785F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806785FC: lw          $v1, 0x304($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X304);
    // 0x80678600: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80678604: slti        $at, $t6, 0x3
    ctx->r1 = SIGNED(ctx->r14) < 0X3 ? 1 : 0;
    // 0x80678608: sw          $t6, 0x304($v0)
    MEM_W(0X304, ctx->r2) = ctx->r14;
    // 0x8067860C: bne         $at, $zero, L_80678618
    if (ctx->r1 != 0) {
        // 0x80678610: sw          $v1, 0x300($v0)
        MEM_W(0X300, ctx->r2) = ctx->r3;
            goto L_80678618;
    }
    // 0x80678610: sw          $v1, 0x300($v0)
    MEM_W(0X300, ctx->r2) = ctx->r3;
    // 0x80678614: sw          $zero, 0x304($v0)
    MEM_W(0X304, ctx->r2) = 0;
L_80678618:
    // 0x80678618: jr          $ra
    // 0x8067861C: nop

    return;
    // 0x8067861C: nop

;}
RECOMP_FUNC void func_80672058(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80672058: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067205C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80672060: lw          $a2, 0x1F4($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X1F4);
    // 0x80672064: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80672068: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8067206C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80672070: jal         0x80671D4C
    // 0x80672074: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80671D4C(rdram, ctx);
        goto after_0;
    // 0x80672074: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80672078: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8067207C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80672080: lw          $t6, 0x1E0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1E0);
    // 0x80672084: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80672088: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8067208C: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x80672090: bne         $at, $zero, L_806720B0
    if (ctx->r1 != 0) {
        // 0x80672094: sw          $t7, 0x1E0($a3)
        MEM_W(0X1E0, ctx->r7) = ctx->r15;
            goto L_806720B0;
    }
    // 0x80672094: sw          $t7, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r15;
    // 0x80672098: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8067209C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x806720A0: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x806720A4: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x806720A8: jal         0x80672C80
    // 0x806720AC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_80672C80(rdram, ctx);
        goto after_1;
    // 0x806720AC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_1:
L_806720B0:
    // 0x806720B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806720B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806720B8: jr          $ra
    // 0x806720BC: nop

    return;
    // 0x806720BC: nop

;}
RECOMP_FUNC void func_80448648(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448648: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8044864C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80448650: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80448654: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80448658: lw          $v0, 0x1F4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X1F4);
    // 0x8044865C: addiu       $t0, $zero, 0x1B6C
    ctx->r8 = ADD32(0, 0X1B6C);
    // 0x80448660: subu        $t1, $t0, $a3
    ctx->r9 = SUB32(ctx->r8, ctx->r7);
    // 0x80448664: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x80448668: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x8044866C: slti        $at, $t8, 0x3C0
    ctx->r1 = SIGNED(ctx->r24) < 0X3C0 ? 1 : 0;
    // 0x80448670: beq         $at, $zero, L_8044867C
    if (ctx->r1 == 0) {
        // 0x80448674: sw          $t8, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r24;
            goto L_8044867C;
    }
    // 0x80448674: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x80448678: sw          $t1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r9;
L_8044867C:
    // 0x8044867C: jr          $ra
    // 0x80448680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80448680: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_80516F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80516F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80516F04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80516F08: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80516F0C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80516F10: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80516F14: lui         $t8, 0x8051
    ctx->r24 = S32(RELOC_HI16(282, 0X23C) << 16);
    // 0x80516F18: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80516F1C: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80516F20: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80516F24: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80516F28: lw          $t8, 0x706C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(282, 0X23C));
    // 0x80516F2C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80516F30: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80516F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80516F38: jal         0x80048490
    // 0x80516F3C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80516F3C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80516F40: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80516F44: jal         0x80048378
    // 0x80516F48: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80516F48: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80516F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80516F50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80516F54: jr          $ra
    // 0x80516F58: nop

    return;
    // 0x80516F58: nop

;}
RECOMP_FUNC void func_80536384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536384: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536388: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053638C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536390: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536394: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536398: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053639C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805363A0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805363A4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805363A8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805363AC: jr          $ra
    // 0x805363B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805363B0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80534B48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534B48: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x80534B4C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534B50: beq         $v1, $zero, L_80534BAC
    if (ctx->r3 == 0) {
        // 0x80534B54: nop
    
            goto L_80534BAC;
    }
    // 0x80534B54: nop

    // 0x80534B58: lw          $a1, 0x1F4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1F4);
    // 0x80534B5C: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80534B60: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80534B64: lwc1        $f6, 0x114C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X114C);
    // 0x80534B68: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x80534B6C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80534B70: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80534B74: nop

    // 0x80534B78: bc1fl       L_80534B94
    if (!c1cs) {
        // 0x80534B7C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80534B94;
    }
    goto skip_0;
    // 0x80534B7C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x80534B80: lhu         $t6, 0xE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XE);
    // 0x80534B84: ori         $t7, $t6, 0x5
    ctx->r15 = ctx->r14 | 0X5;
    // 0x80534B88: jr          $ra
    // 0x80534B8C: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    return;
    // 0x80534B8C: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x80534B90: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80534B94:
    // 0x80534B94: nop

    // 0x80534B98: bc1f        L_80534BAC
    if (!c1cs) {
        // 0x80534B9C: nop
    
            goto L_80534BAC;
    }
    // 0x80534B9C: nop

    // 0x80534BA0: lhu         $t8, 0xE($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0XE);
    // 0x80534BA4: ori         $t9, $t8, 0x6
    ctx->r25 = ctx->r24 | 0X6;
    // 0x80534BA8: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
L_80534BAC:
    // 0x80534BAC: jr          $ra
    // 0x80534BB0: nop

    return;
    // 0x80534BB0: nop

;}
RECOMP_FUNC void func_8001E478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E480: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E484: jal         0x80065954
    // 0x8001E488: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8001E488: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x8001E48C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001E490: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001E494: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E498: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E49C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001E4A0: lbu         $v0, 0x1FB($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1FB);
    // 0x8001E4A4: bc1f        L_8001E574
    if (!c1cs) {
        // 0x8001E4A8: nop
    
            goto L_8001E574;
    }
    // 0x8001E4A8: nop

    // 0x8001E4AC: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8001E4B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001E4B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E4B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001E4BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8001E4C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001E4C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001E4C8: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8001E4CC: nop

    // 0x8001E4D0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001E4D4: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8001E4D8: nop

    // 0x8001E4DC: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8001E4E0: beql        $a0, $zero, L_8001E530
    if (ctx->r4 == 0) {
        // 0x8001E4E4: mfc1        $a0, $f10
        ctx->r4 = (int32_t)ctx->f10.u32l;
            goto L_8001E530;
    }
    goto skip_0;
    // 0x8001E4E4: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8001E4E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001E4EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E4F0: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001E4F4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8001E4F8: nop

    // 0x8001E4FC: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001E500: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8001E504: nop

    // 0x8001E508: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8001E50C: bne         $a0, $zero, L_8001E524
    if (ctx->r4 != 0) {
        // 0x8001E510: nop
    
            goto L_8001E524;
    }
    // 0x8001E510: nop

    // 0x8001E514: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8001E518: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E51C: b           L_8001E53C
    // 0x8001E520: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8001E53C;
    // 0x8001E520: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8001E524:
    // 0x8001E524: b           L_8001E53C
    // 0x8001E528: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8001E53C;
    // 0x8001E528: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8001E52C: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
L_8001E530:
    // 0x8001E530: nop

    // 0x8001E534: bltz        $a0, L_8001E524
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E538: nop
    
            goto L_8001E524;
    }
    // 0x8001E538: nop

L_8001E53C:
    // 0x8001E53C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001E540: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001E544: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E548: beql        $at, $zero, L_8001E560
    if (ctx->r1 == 0) {
        // 0x8001E54C: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E560;
    }
    goto skip_1;
    // 0x8001E54C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x8001E550: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E554: b           L_8001E660
    // 0x8001E558: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8001E660;
    // 0x8001E558: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001E55C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E560:
    // 0x8001E560: beql        $at, $zero, L_8001E664
    if (ctx->r1 == 0) {
        // 0x8001E564: sb          $v0, 0x1FB($a1)
        MEM_B(0X1FB, ctx->r5) = ctx->r2;
            goto L_8001E664;
    }
    goto skip_2;
    // 0x8001E564: sb          $v0, 0x1FB($a1)
    MEM_B(0X1FB, ctx->r5) = ctx->r2;
    skip_2:
    // 0x8001E568: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E56C: b           L_8001E660
    // 0x8001E570: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8001E660;
    // 0x8001E570: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8001E574:
    // 0x8001E574: lwc1        $f16, -0x438($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X438);
    // 0x8001E578: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001E57C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8001E580: nop

    // 0x8001E584: bc1f        L_8001E650
    if (!c1cs) {
        // 0x8001E588: nop
    
            goto L_8001E650;
    }
    // 0x8001E588: nop

    // 0x8001E58C: lwc1        $f18, -0x434($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X434);
    // 0x8001E590: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E594: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8001E598: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8001E59C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001E5A0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8001E5A4: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8001E5A8: nop

    // 0x8001E5AC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001E5B0: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8001E5B4: nop

    // 0x8001E5B8: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8001E5BC: beql        $a0, $zero, L_8001E60C
    if (ctx->r4 == 0) {
        // 0x8001E5C0: mfc1        $a0, $f6
        ctx->r4 = (int32_t)ctx->f6.u32l;
            goto L_8001E60C;
    }
    goto skip_3;
    // 0x8001E5C0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    skip_3:
    // 0x8001E5C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001E5C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001E5CC: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001E5D0: ctc1        $a0, $FpcCsr
    set_cop1_cs(ctx->r4);
    // 0x8001E5D4: nop

    // 0x8001E5D8: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8001E5DC: cfc1        $a0, $FpcCsr
    ctx->r4 = get_cop1_cs();
    // 0x8001E5E0: nop

    // 0x8001E5E4: andi        $a0, $a0, 0x78
    ctx->r4 = ctx->r4 & 0X78;
    // 0x8001E5E8: bne         $a0, $zero, L_8001E600
    if (ctx->r4 != 0) {
        // 0x8001E5EC: nop
    
            goto L_8001E600;
    }
    // 0x8001E5EC: nop

    // 0x8001E5F0: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x8001E5F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001E5F8: b           L_8001E618
    // 0x8001E5FC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
        goto L_8001E618;
    // 0x8001E5FC: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
L_8001E600:
    // 0x8001E600: b           L_8001E618
    // 0x8001E604: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
        goto L_8001E618;
    // 0x8001E604: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8001E608: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
L_8001E60C:
    // 0x8001E60C: nop

    // 0x8001E610: bltz        $a0, L_8001E600
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E614: nop
    
            goto L_8001E600;
    }
    // 0x8001E614: nop

L_8001E618:
    // 0x8001E618: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8001E61C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001E620: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8001E624: beql        $at, $zero, L_8001E63C
    if (ctx->r1 == 0) {
        // 0x8001E628: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E63C;
    }
    goto skip_4;
    // 0x8001E628: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_4:
    // 0x8001E62C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E630: b           L_8001E660
    // 0x8001E634: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8001E660;
    // 0x8001E634: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8001E638: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E63C:
    // 0x8001E63C: beql        $at, $zero, L_8001E664
    if (ctx->r1 == 0) {
        // 0x8001E640: sb          $v0, 0x1FB($a1)
        MEM_B(0X1FB, ctx->r5) = ctx->r2;
            goto L_8001E664;
    }
    goto skip_5;
    // 0x8001E640: sb          $v0, 0x1FB($a1)
    MEM_B(0X1FB, ctx->r5) = ctx->r2;
    skip_5:
    // 0x8001E644: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E648: b           L_8001E660
    // 0x8001E64C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_8001E660;
    // 0x8001E64C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8001E650:
    // 0x8001E650: beql        $v0, $zero, L_8001E664
    if (ctx->r2 == 0) {
        // 0x8001E654: sb          $v0, 0x1FB($a1)
        MEM_B(0X1FB, ctx->r5) = ctx->r2;
            goto L_8001E664;
    }
    goto skip_6;
    // 0x8001E654: sb          $v0, 0x1FB($a1)
    MEM_B(0X1FB, ctx->r5) = ctx->r2;
    skip_6:
    // 0x8001E658: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001E65C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_8001E660:
    // 0x8001E660: sb          $v0, 0x1FB($a1)
    MEM_B(0X1FB, ctx->r5) = ctx->r2;
L_8001E664:
    // 0x8001E664: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E668: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E66C: jr          $ra
    // 0x8001E670: nop

    return;
    // 0x8001E670: nop

;}
RECOMP_FUNC void func_806F5420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F5424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5428: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F542C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806F5430: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    // 0x806F5434: jal         0x80067BBC
    // 0x806F5438: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x806F5438: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    after_0:
    // 0x806F543C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x806F5440: jal         0x80067818
    // 0x806F5444: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x806F5444: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x806F5448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F544C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F5450: jr          $ra
    // 0x806F5454: nop

    return;
    // 0x806F5454: nop

;}
RECOMP_FUNC void func_804632B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804632B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804632BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804632C0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804632C4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804632C8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804632CC: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3998) << 16);
    // 0x804632D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804632D4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804632D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804632DC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804632E0: lw          $t8, 0x3F28($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3998));
    // 0x804632E4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804632E8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804632EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804632F0: jal         0x80048490
    // 0x804632F4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804632F4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804632F8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804632FC: jal         0x80048378
    // 0x80463300: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80463300: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80463304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80463308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046330C: jr          $ra
    // 0x80463310: nop

    return;
    // 0x80463310: nop

;}
RECOMP_FUNC void func_807B3810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3810: jr          $ra
    // 0x807B3814: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807B3814: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80581CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581CDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80581CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581CE4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80581CE8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80581CEC: jal         0x80581B84
    // 0x80581CF0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80581B84(rdram, ctx);
        goto after_0;
    // 0x80581CF0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80581CF4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80581CF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80581CFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80581D00: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    // 0x80581D04: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80581D08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80581D0C: slti        $at, $a1, 0x3
    ctx->r1 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x80581D10: bne         $at, $zero, L_80581D30
    if (ctx->r1 != 0) {
        // 0x80581D14: lui         $at, 0x4313
        ctx->r1 = S32(0X4313 << 16);
            goto L_80581D30;
    }
    // 0x80581D14: lui         $at, 0x4313
    ctx->r1 = S32(0X4313 << 16);
    // 0x80581D18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80581D1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581D20: jal         0x80581F38
    // 0x80581D24: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    func_80581F38(rdram, ctx);
        goto after_1;
    // 0x80581D24: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x80581D28: b           L_80581DD0
    // 0x80581D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80581DD0;
    // 0x80581D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581D30:
    // 0x80581D30: lui         $at, 0x4313
    ctx->r1 = S32(0X4313 << 16);
    // 0x80581D34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80581D38: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x80581D3C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x80581D40: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80581D44: nop

    // 0x80581D48: bc1fl       L_80581D94
    if (!c1cs) {
        // 0x80581D4C: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_80581D94;
    }
    goto skip_0;
    // 0x80581D4C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    skip_0:
    // 0x80581D50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80581D54: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80581D58: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x80581D5C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4804) << 16);
    // 0x80581D60: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80581D64: nop

    // 0x80581D68: bc1fl       L_80581D94
    if (!c1cs) {
        // 0x80581D6C: addiu       $v0, $a0, 0xC4
        ctx->r2 = ADD32(ctx->r4, 0XC4);
            goto L_80581D94;
    }
    goto skip_1;
    // 0x80581D6C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    skip_1:
    // 0x80581D70: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80581D74: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80581D78: lwc1        $f4, 0x3614($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X4804));
    // 0x80581D7C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80581D80: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x80581D84: jal         0x80581BFC
    // 0x80581D88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80581BFC(rdram, ctx);
        goto after_2;
    // 0x80581D88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80581D8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80581D90: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
L_80581D94:
    // 0x80581D94: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80581D98: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80581D9C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80581DA0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80581DA4: nop

    // 0x80581DA8: bc1fl       L_80581DC4
    if (!c1cs) {
        // 0x80581DAC: lwc1        $f4, 0x58($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
            goto L_80581DC4;
    }
    goto skip_2;
    // 0x80581DAC: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    skip_2:
    // 0x80581DB0: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x80581DB4: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80581DB8: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x80581DBC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80581DC0: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
L_80581DC4:
    // 0x80581DC4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80581DC8: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80581DCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581DD0:
    // 0x80581DD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80581DD4: jr          $ra
    // 0x80581DD8: nop

    return;
    // 0x80581DD8: nop

;}
RECOMP_FUNC void func_80421690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80421690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80421694: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80421698: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042169C: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804216A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804216A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804216A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804216AC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804216B0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804216B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804216B8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804216BC: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804216C0: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(32, 0X1718) << 16);
    // 0x804216C4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804216C8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804216CC: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804216D0: lw          $t2, 0x27D8($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(32, 0X1718));
    // 0x804216D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804216D8: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x804216DC: jal         0x8042117C
    // 0x804216E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042117C(rdram, ctx);
        goto after_0;
    // 0x804216E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804216E4: jal         0x804211D8
    // 0x804216E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804211D8(rdram, ctx);
        goto after_1;
    // 0x804216E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804216EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804216F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804216F4: jr          $ra
    // 0x804216F8: nop

    return;
    // 0x804216F8: nop

;}
RECOMP_FUNC void func_805D7B94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D7B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D7B9C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x805D7BA0: lui         $t6, 0x805E
    ctx->r14 = S32(RELOC_HI16(474, 0X24BC) << 16);
    // 0x805D7BA4: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x805D7BA8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x805D7BAC: addiu       $t6, $t6, -0x6244
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(474, 0X24BC));
    // 0x805D7BB0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x805D7BB4: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x805D7BB8: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x805D7BBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805D7BC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D7BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805D7BC8: jal         0x805D7DA4
    // 0x805D7BCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_805D7DA4(rdram, ctx);
        goto after_0;
    // 0x805D7BCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x805D7BD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805D7BD4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805D7BD8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x805D7BDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D7BE0: lui         $at, 0x805E
    ctx->r1 = S32(RELOC_HI16(474, 0X2574) << 16);
    // 0x805D7BE4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x805D7BE8: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x805D7BEC: lwc1        $f8, -0x618C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(474, 0X2574));
    // 0x805D7BF0: jal         0x805D7B7C
    // 0x805D7BF4: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    func_805D7B7C(rdram, ctx);
        goto after_1;
    // 0x805D7BF4: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    after_1:
    // 0x805D7BF8: jal         0x8005FCA8
    // 0x805D7BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FCA8(rdram, ctx);
        goto after_2;
    // 0x805D7BFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x805D7C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D7C04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D7C08: jr          $ra
    // 0x805D7C0C: nop

    return;
    // 0x805D7C0C: nop

;}
RECOMP_FUNC void func_804254D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804254D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804254D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804254D8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804254DC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804254E0: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X2DA0) << 16);
    // 0x804254E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804254E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804254EC: lw          $t8, 0x57A0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X2DA0));
    // 0x804254F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804254F4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804254F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804254FC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80425500: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80425504: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80425508: beql        $v1, $zero, L_8042553C
    if (ctx->r3 == 0) {
        // 0x8042550C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042553C;
    }
    goto skip_0;
    // 0x8042550C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80425510: jalr        $v1
    // 0x80425514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80425514: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80425518: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042551C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80425520: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80425524: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80425528: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042552C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80425530: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80425534: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80425538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042553C:
    // 0x8042553C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80425540: jr          $ra
    // 0x80425544: nop

    return;
    // 0x80425544: nop

;}
RECOMP_FUNC void func_804D668C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D668C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804D6690: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804D6694: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804D6698: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x804D669C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x804D66A0: jal         0x8004700C
    // 0x804D66A4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804D66A4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804D66A8: lhu         $a0, 0x4A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X4A);
    // 0x804D66AC: jal         0x80047090
    // 0x804D66B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x804D66B0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x804D66B4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804D66B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x804D66BC: beq         $v0, $at, L_804D67EC
    if (ctx->r2 == ctx->r1) {
        // 0x804D66C0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804D67EC;
    }
    // 0x804D66C0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804D66C4: beql        $a1, $zero, L_804D67F0
    if (ctx->r5 == 0) {
        // 0x804D66C8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804D67F0;
    }
    goto skip_0;
    // 0x804D66C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804D66CC: beq         $a1, $zero, L_804D66E8
    if (ctx->r5 == 0) {
        // 0x804D66D0: lui         $at, 0x804D
        ctx->r1 = S32(RELOC_HI16(252, 0X630) << 16);
            goto L_804D66E8;
    }
    // 0x804D66D0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(252, 0X630) << 16);
    // 0x804D66D4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x804D66D8: jal         0x80047AB8
    // 0x804D66DC: sh          $v1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r3;
    func_80047AB8(rdram, ctx);
        goto after_2;
    // 0x804D66DC: sh          $v1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r3;
    after_2:
    // 0x804D66E0: b           L_804D66F0
    // 0x804D66E4: lhu         $v1, 0x46($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X46);
        goto L_804D66F0;
    // 0x804D66E4: lhu         $v1, 0x46($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X46);
L_804D66E8:
    // 0x804D66E8: lwc1        $f4, 0x6930($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(252, 0X630));
    // 0x804D66EC: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
L_804D66F0:
    // 0x804D66F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(252, 0X634) << 16);
    // 0x804D66F4: lwc1        $f8, 0x6934($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(252, 0X634));
    // 0x804D66F8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804D66FC: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x804D6700: lhu         $t6, 0x4A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X4A);
    // 0x804D6704: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804D6708: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(252, 0X720) << 16);
    // 0x804D670C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x804D6710: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x804D6714: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x804D6718: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x804D671C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x804D6720: or          $a1, $t8, $v1
    ctx->r5 = ctx->r24 | ctx->r3;
    // 0x804D6724: jal         0x80046804
    // 0x804D6728: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(252, 0X720));
    func_80046804(rdram, ctx);
        goto after_3;
    // 0x804D6728: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(252, 0X720));
    after_3:
    // 0x804D672C: beq         $v0, $zero, L_804D67EC
    if (ctx->r2 == 0) {
        // 0x804D6730: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804D67EC;
    }
    // 0x804D6730: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804D6734: lw          $v1, 0x16C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X16C);
    // 0x804D6738: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x804D673C: beq         $s0, $zero, L_804D6788
    if (ctx->r16 == 0) {
        // 0x804D6740: addiu       $v1, $v1, 0xD
        ctx->r3 = ADD32(ctx->r3, 0XD);
            goto L_804D6788;
    }
    // 0x804D6740: addiu       $v1, $v1, 0xD
    ctx->r3 = ADD32(ctx->r3, 0XD);
    // 0x804D6744: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x804D6748: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x804D674C: lbu         $t0, 0x1($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X1);
    // 0x804D6750: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    // 0x804D6754: lbu         $t1, 0x2($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X2);
    // 0x804D6758: sb          $t1, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r9;
    // 0x804D675C: lbu         $t2, 0x3($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X3);
    // 0x804D6760: sb          $t2, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r10;
    // 0x804D6764: lbu         $t3, 0x4($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X4);
    // 0x804D6768: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x804D676C: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
    // 0x804D6770: sb          $t4, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r12;
    // 0x804D6774: lbu         $t5, 0x6($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6);
    // 0x804D6778: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
    // 0x804D677C: lbu         $t6, 0x7($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X7);
    // 0x804D6780: b           L_804D67D8
    // 0x804D6784: sb          $t6, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r14;
        goto L_804D67D8;
    // 0x804D6784: sb          $t6, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r14;
L_804D6788:
    // 0x804D6788: lw          $t7, -0x7BC4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BC4);
    // 0x804D678C: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(252, 0X60C) << 16);
    // 0x804D6790: addiu       $t9, $t9, 0x690C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(252, 0X60C));
    // 0x804D6794: lw          $a0, 0x10C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10C);
    // 0x804D6798: srl         $a0, $a0, 30
    ctx->r4 = S32(U32(ctx->r4) >> 30);
    // 0x804D679C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x804D67A0: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x804D67A4: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x804D67A8: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x804D67AC: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x804D67B0: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x804D67B4: sb          $t1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r9;
    // 0x804D67B8: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x804D67BC: sb          $t2, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r10;
    // 0x804D67C0: lbu         $t3, 0x4($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X4);
    // 0x804D67C4: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x804D67C8: lbu         $t4, 0x5($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X5);
    // 0x804D67CC: sb          $t4, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r12;
    // 0x804D67D0: lbu         $t5, 0x6($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X6);
    // 0x804D67D4: sb          $t5, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r13;
L_804D67D8:
    // 0x804D67D8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804D67DC: jal         0x80044194
    // 0x804D67E0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x804D67E0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_4:
    // 0x804D67E4: b           L_804D67F0
    // 0x804D67E8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_804D67F0;
    // 0x804D67E8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_804D67EC:
    // 0x804D67EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D67F0:
    // 0x804D67F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804D67F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804D67F8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804D67FC: jr          $ra
    // 0x804D6800: nop

    return;
    // 0x804D6800: nop

    // 0x804D6804: nop

    // 0x804D6808: nop

    // 0x804D680C: nop

;}
RECOMP_FUNC void func_804CACA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CACA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804CACA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804CACA8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804CACAC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804CACB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CACB4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804CACB8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804CACBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804CACC0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804CACC4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804CACC8: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(231, 0X12AC) << 16);
    // 0x804CACCC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804CACD0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804CACD4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804CACD8: lw          $t2, -0x4214($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(231, 0X12AC));
    // 0x804CACDC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CACE0: jal         0x804CAB88
    // 0x804CACE4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    func_804CAB88(rdram, ctx);
        goto after_0;
    // 0x804CACE4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    after_0:
    // 0x804CACE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CACEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804CACF0: jr          $ra
    // 0x804CACF4: nop

    return;
    // 0x804CACF4: nop

;}
RECOMP_FUNC void func_8073F4BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073F4BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073F4C0: sll         $a2, $a1, 3
    ctx->r6 = S32(ctx->r5 << 3);
    // 0x8073F4C4: subu        $a2, $a2, $a1
    ctx->r6 = SUB32(ctx->r6, ctx->r5);
    // 0x8073F4C8: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8073F4CC: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8073F4D0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8073F4D4: addu        $a3, $t6, $a2
    ctx->r7 = ADD32(ctx->r14, ctx->r6);
    // 0x8073F4D8: lw          $t7, 0x14($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X14);
    // 0x8073F4DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073F4E0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8073F4E4: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8073F4E8: beq         $v1, $zero, L_8073F630
    if (ctx->r3 == 0) {
        // 0x8073F4EC: nop
    
            goto L_8073F630;
    }
    // 0x8073F4EC: nop

    // 0x8073F4F0: lw          $t0, 0x18($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X18);
    // 0x8073F4F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073F4F8: bgezl       $t0, L_8073F510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8073F4FC: sb          $zero, 0x165($v1)
        MEM_B(0X165, ctx->r3) = 0;
            goto L_8073F510;
    }
    goto skip_0;
    // 0x8073F4FC: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
    skip_0:
    // 0x8073F500: sb          $t1, 0x165($v1)
    MEM_B(0X165, ctx->r3) = ctx->r9;
    // 0x8073F504: b           L_8073F520
    // 0x8073F508: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
        goto L_8073F520;
    // 0x8073F508: sh          $zero, 0x144($v1)
    MEM_H(0X144, ctx->r3) = 0;
    // 0x8073F50C: sb          $zero, 0x165($v1)
    MEM_B(0X165, ctx->r3) = 0;
L_8073F510:
    // 0x8073F510: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x8073F514: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x8073F518: lw          $t4, 0x18($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X18);
    // 0x8073F51C: sh          $t4, 0x144($v1)
    MEM_H(0X144, ctx->r3) = ctx->r12;
L_8073F520:
    // 0x8073F520: lw          $t5, 0x138($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X138);
    // 0x8073F524: bnel        $t5, $zero, L_8073F54C
    if (ctx->r13 != 0) {
        // 0x8073F528: lw          $t8, 0x14($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X14);
            goto L_8073F54C;
    }
    goto skip_1;
    // 0x8073F528: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    skip_1:
    // 0x8073F52C: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x8073F530: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8073F534: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8073F538: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8073F53C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8073F540: b           L_8073F564
    // 0x8073F544: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
        goto L_8073F564;
    // 0x8073F544: swc1        $f8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f8.u32l;
    // 0x8073F548: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
L_8073F54C:
    // 0x8073F54C: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8073F550: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8073F554: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8073F558: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8073F55C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8073F560: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
L_8073F564:
    // 0x8073F564: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    // 0x8073F568: lwc1        $f6, 0x70($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8073F56C: lwc1        $f18, 0x0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8073F570: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x8073F574: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8073F578: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8073F57C: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(748, 0X2304) << 16);
    // 0x8073F580: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8073F584: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8073F588: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x8073F58C: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8073F590: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8073F594: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x8073F598: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8073F59C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8073F5A0: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073F5A4: swc1        $f16, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f16.u32l;
    // 0x8073F5A8: lwc1        $f18, 0xAF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(748, 0X2304));
    // 0x8073F5AC: lwc1        $f10, 0x44($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8073F5B0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8073F5B4: swc1        $f4, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f4.u32l;
    // 0x8073F5B8: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8073F5BC: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8073F5C0: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x8073F5C4: lwc1        $f8, 0x8($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8073F5C8: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8073F5CC: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    // 0x8073F5D0: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8073F5D4: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8073F5D8: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8073F5DC: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8073F5E0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8073F5E4: swc1        $f4, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f4.u32l;
    // 0x8073F5E8: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    // 0x8073F5EC: bnel        $t7, $zero, L_8073F614
    if (ctx->r15 != 0) {
        // 0x8073F5F0: lw          $t0, 0x14($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X14);
            goto L_8073F614;
    }
    goto skip_2;
    // 0x8073F5F0: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
    skip_2:
    // 0x8073F5F4: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8073F5F8: lwc1        $f6, 0x50($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8073F5FC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8073F600: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8073F604: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8073F608: b           L_8073F628
    // 0x8073F60C: swc1        $f16, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f16.u32l;
        goto L_8073F628;
    // 0x8073F60C: swc1        $f16, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f16.u32l;
    // 0x8073F610: lw          $t0, 0x14($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X14);
L_8073F614:
    // 0x8073F614: lwc1        $f10, 0x50($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8073F618: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x8073F61C: lwc1        $f18, 0x10($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X10);
    // 0x8073F620: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8073F624: swc1        $f4, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f4.u32l;
L_8073F628:
    // 0x8073F628: lw          $t2, 0x138($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X138);
    // 0x8073F62C: sw          $t2, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r10;
L_8073F630:
    // 0x8073F630: jr          $ra
    // 0x8073F634: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8073F634: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_8006920C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006920C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80069210: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80069214: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80069218: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006921C: lbu         $a2, 0xF0($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XF0);
    // 0x80069220: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80069224: lw          $t8, 0xEC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XEC);
    // 0x80069228: lbu         $t6, 0xF9($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XF9);
    // 0x8006922C: lui         $t7, 0x8006
    ctx->r15 = S32(0X8006 << 16);
    // 0x80069230: addiu       $t7, $t7, 0x5284
    ctx->r15 = ADD32(ctx->r15, 0X5284);
    // 0x80069234: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80069238: sb          $zero, 0xF9($a0)
    MEM_B(0XF9, ctx->r4) = 0;
    // 0x8006923C: bne         $t7, $t8, L_80069260
    if (ctx->r15 != ctx->r24) {
        // 0x80069240: sb          $t6, 0xF8($a0)
        MEM_B(0XF8, ctx->r4) = ctx->r14;
            goto L_80069260;
    }
    // 0x80069240: sb          $t6, 0xF8($a0)
    MEM_B(0XF8, ctx->r4) = ctx->r14;
    // 0x80069244: addiu       $a1, $s0, 0x84
    ctx->r5 = ADD32(ctx->r16, 0X84);
    // 0x80069248: jal         0x80065490
    // 0x8006924C: sb          $a2, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r6;
    func_80065490(rdram, ctx);
        goto after_0;
    // 0x8006924C: sb          $a2, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069250: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80069254: lbu         $a2, 0x2F($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X2F);
    // 0x80069258: swc1        $f0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f0.u32l;
    // 0x8006925C: swc1        $f0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f0.u32l;
L_80069260:
    // 0x80069260: beq         $a2, $zero, L_80069288
    if (ctx->r6 == 0) {
        // 0x80069264: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_80069288;
    }
    // 0x80069264: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80069268: jal         0x8006919C
    // 0x8006926C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8006919C(rdram, ctx);
        goto after_1;
    // 0x8006926C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80069270: lbu         $t9, 0xF0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XF0);
    // 0x80069274: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x80069278: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8006927C: sb          $t1, 0xF0($s0)
    MEM_B(0XF0, ctx->r16) = ctx->r9;
    // 0x80069280: b           L_800692AC
    // 0x80069284: sb          $t2, 0xF1($s0)
    MEM_B(0XF1, ctx->r16) = ctx->r10;
        goto L_800692AC;
    // 0x80069284: sb          $t2, 0xF1($s0)
    MEM_B(0XF1, ctx->r16) = ctx->r10;
L_80069288:
    // 0x80069288: lbu         $a2, 0xF1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0XF1);
    // 0x8006928C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80069290: beq         $a2, $zero, L_800692AC
    if (ctx->r6 == 0) {
        // 0x80069294: nop
    
            goto L_800692AC;
    }
    // 0x80069294: nop

    // 0x80069298: jal         0x8006919C
    // 0x8006929C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8006919C(rdram, ctx);
        goto after_2;
    // 0x8006929C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800692A0: lbu         $t3, 0xF1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XF1);
    // 0x800692A4: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800692A8: sb          $t4, 0xF1($s0)
    MEM_B(0XF1, ctx->r16) = ctx->r12;
L_800692AC:
    // 0x800692AC: jal         0x8005A52C
    // 0x800692B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A52C(rdram, ctx);
        goto after_3;
    // 0x800692B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x800692B4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800692B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800692BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800692C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800692C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800692C8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800692CC: jr          $ra
    // 0x800692D0: nop

    return;
    // 0x800692D0: nop

;}
RECOMP_FUNC void func_8002C868(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C868: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C86C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C870: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002C874: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C878: addiu       $a1, $a1, -0x3558
    ctx->r5 = ADD32(ctx->r5, -0X3558);
    // 0x8002C87C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8002C880: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002C884: jal         0x80028118
    // 0x8002C888: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C888: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002C88C: jal         0x8002C4F0
    // 0x8002C890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002C4F0(rdram, ctx);
        goto after_1;
    // 0x8002C890: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8002C894: lui         $at, 0xC140
    ctx->r1 = S32(0XC140 << 16);
    // 0x8002C898: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C89C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C8A0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8002C8A4: swc1        $f4, 0xC8($t7)
    MEM_W(0XC8, ctx->r15) = ctx->f4.u32l;
    // 0x8002C8A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8002C8AC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8002C8B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C8B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C8B8: jr          $ra
    // 0x8002C8BC: nop

    return;
    // 0x8002C8BC: nop

;}
RECOMP_FUNC void func_80523560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80523564: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80523568: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x8052356C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80523570: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80523574: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80523578: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8052357C: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x80523580: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80523584: bne         $t7, $at, L_8052359C
    if (ctx->r15 != ctx->r1) {
        // 0x80523588: addiu       $a1, $zero, 0x24
        ctx->r5 = ADD32(0, 0X24);
            goto L_8052359C;
    }
    // 0x80523588: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8052358C: jal         0x800447C8
    // 0x80523590: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x80523590: nop

    after_0:
    // 0x80523594: b           L_805236C4
    // 0x80523598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805236C4;
    // 0x80523598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052359C:
    // 0x8052359C: jal         0x80045A34
    // 0x805235A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805235A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805235A4: bne         $v0, $zero, L_805235BC
    if (ctx->r2 != 0) {
        // 0x805235A8: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_805235BC;
    }
    // 0x805235A8: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x805235AC: jal         0x800445A4
    // 0x805235B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x805235B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805235B4: b           L_805236C4
    // 0x805235B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805236C4;
    // 0x805235B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805235BC:
    // 0x805235BC: lw          $t0, 0x16C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X16C);
    // 0x805235C0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805235C4: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(321, 0X1E3C) << 16);
    // 0x805235C8: sb          $t8, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r24;
    // 0x805235CC: addiu       $t9, $t9, 0x40EC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(321, 0X1E3C));
    // 0x805235D0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x805235D4: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x805235D8: jal         0x80522AA4
    // 0x805235DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80522AA4(rdram, ctx);
        goto after_3;
    // 0x805235DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x805235E0: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x805235E4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x805235E8: sw          $t1, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r9;
    // 0x805235EC: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    // 0x805235F0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805235F4: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x805235F8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x805235FC: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80523600: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80523604: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80523608: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052360C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80523610: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80523614: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80523618: addiu       $a0, $zero, 0x4146
    ctx->r4 = ADD32(0, 0X4146);
    // 0x8052361C: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80523620: lwc1        $f10, 0x40($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80523624: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80523628: jal         0x80047090
    // 0x8052362C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x8052362C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80523630: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80523634: lui         $at, 0x4146
    ctx->r1 = S32(0X4146 << 16);
    // 0x80523638: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8052363C: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80523640: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80523644: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80523648: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8052364C: jal         0x8004613C
    // 0x80523650: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x80523650: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    after_5:
    // 0x80523654: bne         $v0, $zero, L_8052366C
    if (ctx->r2 != 0) {
        // 0x80523658: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8052366C;
    }
    // 0x80523658: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8052365C: jal         0x800445A4
    // 0x80523660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80523660: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80523664: b           L_805236C4
    // 0x80523668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805236C4;
    // 0x80523668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8052366C:
    // 0x8052366C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80523670: jal         0x80047F9C
    // 0x80523674: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80523674: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x80523678: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8052367C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80523680: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80523684: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x80523688: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8052368C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EA8) << 16);
    // 0x80523690: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80523694: sb          $t4, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r12;
    // 0x80523698: lwc1        $f4, 0x4158($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EA8));
    // 0x8052369C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(321, 0X1EAC) << 16);
    // 0x805236A0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x805236A4: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x805236A8: lwc1        $f6, 0x415C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(321, 0X1EAC));
    // 0x805236AC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x805236B0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805236B4: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x805236B8: jal         0x80523830
    // 0x805236BC: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    func_80523830(rdram, ctx);
        goto after_8;
    // 0x805236BC: swc1        $f8, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f8.u32l;
    after_8:
    // 0x805236C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805236C4:
    // 0x805236C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805236C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805236CC: jr          $ra
    // 0x805236D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805236D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806F54B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F54B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F54B8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x806F54BC: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x806F54C0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x806F54C4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x806F54C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806F54CC: lui         $s3, 0x4074
    ctx->r19 = S32(0X4074 << 16);
    // 0x806F54D0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x806F54D4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x806F54D8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806F54DC: ori         $s3, $s3, 0x1A00
    ctx->r19 = ctx->r19 | 0X1A00;
    // 0x806F54E0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x806F54E4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x806F54E8: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x806F54EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_806F54F0:
    // 0x806F54F0: lw          $a1, 0x84($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X84);
    // 0x806F54F4: lw          $a2, 0x88($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X88);
    // 0x806F54F8: jal         0x8004613C
    // 0x806F54FC: lw          $a3, 0x8C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8C);
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x806F54FC: lw          $a3, 0x8C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8C);
    after_0:
    // 0x806F5500: beq         $v0, $zero, L_806F5538
    if (ctx->r2 == 0) {
        // 0x806F5504: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_806F5538;
    }
    // 0x806F5504: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x806F5508: jal         0x80047090
    // 0x806F550C: addiu       $a0, $zero, 0x4074
    ctx->r4 = ADD32(0, 0X4074);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x806F550C: addiu       $a0, $zero, 0x4074
    ctx->r4 = ADD32(0, 0X4074);
    after_1:
    // 0x806F5510: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x806F5514: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x806F5518: sw          $s2, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r18;
    // 0x806F551C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x806F5520: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x806F5524: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x806F5528: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x806F552C: jal         0x80047F9C
    // 0x806F5530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x806F5530: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x806F5534: sb          $s4, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r20;
L_806F5538:
    // 0x806F5538: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x806F553C: bnel        $s2, $s5, L_806F54F0
    if (ctx->r18 != ctx->r21) {
        // 0x806F5540: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_806F54F0;
    }
    goto skip_0;
    // 0x806F5540: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x806F5544: lui         $t1, 0x806F
    ctx->r9 = S32(RELOC_HI16(685, 0X118) << 16);
    // 0x806F5548: addiu       $t1, $t1, 0x5478
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(685, 0X118));
    // 0x806F554C: sw          $t1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r9;
    // 0x806F5550: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x806F5554: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x806F5558: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x806F555C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x806F5560: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x806F5564: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x806F5568: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806F556C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806F5570: jr          $ra
    // 0x806F5574: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x806F5574: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806D9168(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9168: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806D916C: lui         $t7, 0x806E
    ctx->r15 = S32(RELOC_HI16(628, 0X398) << 16);
    // 0x806D9170: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x806D9174: addiu       $t7, $t7, -0x6DA8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(628, 0X398));
    // 0x806D9178: addiu       $t8, $zero, 0xC0
    ctx->r24 = ADD32(0, 0XC0);
    // 0x806D917C: sb          $t6, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r14;
    // 0x806D9180: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x806D9184: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x806D9188: jr          $ra
    // 0x806D918C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x806D918C: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_80790640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80790640: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x80790644: lui         $t9, 0x8079
    ctx->r25 = S32(RELOC_HI16(817, 0X766C) << 16);
    // 0x80790648: addiu       $t9, $t9, 0x79BC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(817, 0X766C));
    // 0x8079064C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80790650: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80790654: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80790658: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8079065C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80790660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80790664: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80790668: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x8079066C: sw          $t2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r10;
    // 0x80790670: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80790674: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x80790678: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x8079067C: sw          $t2, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r10;
    // 0x80790680: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80790684: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80790688: lw          $t2, 0x10($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X10);
    // 0x8079068C: sw          $t2, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r10;
    // 0x80790690: lw          $t1, 0x14($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X14);
    // 0x80790694: sw          $t1, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r9;
    // 0x80790698: lw          $v0, 0x3C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X3C);
    // 0x8079069C: blez        $v0, L_807906AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807906A0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_807906AC;
    }
    // 0x807906A0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x807906A4: b           L_807906B0
    // 0x807906A8: sw          $t3, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r11;
        goto L_807906B0;
    // 0x807906A8: sw          $t3, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r11;
L_807906AC:
    // 0x807906AC: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
L_807906B0:
    // 0x807906B0: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x807906B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x807906B8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x807906BC: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x807906C0: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x807906C4: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x807906C8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x807906CC: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x807906D0: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x807906D4: bnel        $at, $zero, L_8079070C
    if (ctx->r1 != 0) {
        // 0x807906D8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8079070C;
    }
    goto skip_0;
    // 0x807906D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x807906DC: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x807906E0: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x807906E4: lbu         $t2, 0x8($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X8);
    // 0x807906E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x807906EC: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x807906F0: bne         $at, $zero, L_80790700
    if (ctx->r1 != 0) {
        // 0x807906F4: nop
    
            goto L_80790700;
    }
    // 0x807906F4: nop

    // 0x807906F8: b           L_8079070C
    // 0x807906FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
        goto L_8079070C;
    // 0x807906FC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_80790700:
    // 0x80790700: b           L_8079070C
    // 0x80790704: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8079070C;
    // 0x80790704: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80790708: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079070C:
    // 0x8079070C: jr          $ra
    // 0x80790710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80790710: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8043DF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043DF98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043DF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043DFA0: jal         0x8043DCF4
    // 0x8043DFA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8043DCF4(rdram, ctx);
        goto after_0;
    // 0x8043DFA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043DFA8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8043DFAC: bne         $v0, $at, L_8043DFBC
    if (ctx->r2 != ctx->r1) {
        // 0x8043DFB0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8043DFBC;
    }
    // 0x8043DFB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043DFB4: jal         0x8043E0F8
    // 0x8043DFB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8043E0F8(rdram, ctx);
        goto after_1;
    // 0x8043DFB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8043DFBC:
    // 0x8043DFBC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8043DFC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8043DFC4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8043DFC8: jal         0x80048F84
    // 0x8043DFCC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8043DFCC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x8043DFD0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8043DFD4: jal         0x80048F84
    // 0x8043DFD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8043DFD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8043DFDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043DFE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043DFE4: jr          $ra
    // 0x8043DFE8: nop

    return;
    // 0x8043DFE8: nop

;}
RECOMP_FUNC void func_80034878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034878: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8003487C: lbu         $t6, -0x766B($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X766B);
    // 0x80034880: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034884: beq         $t6, $zero, L_80034898
    if (ctx->r14 == 0) {
        // 0x80034888: nop
    
            goto L_80034898;
    }
    // 0x80034888: nop

    // 0x8003488C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034890: jr          $ra
    // 0x80034894: lwc1        $f0, 0xB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XB8);
    return;
    // 0x80034894: lwc1        $f0, 0xB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XB8);
L_80034898:
    // 0x80034898: lwc1        $f0, 0xBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XBC);
    // 0x8003489C: jr          $ra
    // 0x800348A0: nop

    return;
    // 0x800348A0: nop

;}
RECOMP_FUNC void func_80799780(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799780: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799784: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799788: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8079978C: lui         $t8, 0x807A
    ctx->r24 = S32(RELOC_HI16(826, 0X250C) << 16);
    // 0x80799790: addiu       $t8, $t8, -0x4FD4
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(826, 0X250C));
    // 0x80799794: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80799798: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8079979C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x807997A0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x807997A4: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x807997A8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x807997AC: beql        $v1, $zero, L_807997E4
    if (ctx->r3 == 0) {
        // 0x807997B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807997E4;
    }
    goto skip_0;
    // 0x807997B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807997B4: jalr        $v1
    // 0x807997B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x807997B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x807997BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807997C0: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x807997C4: lw          $t0, 0x15C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X15C);
    // 0x807997C8: sw          $t9, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r25;
    // 0x807997CC: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x807997D0: sll         $t3, $t9, 1
    ctx->r11 = S32(ctx->r25 << 1);
    // 0x807997D4: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x807997D8: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x807997DC: sh          $t5, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r13;
    // 0x807997E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807997E4:
    // 0x807997E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807997E8: jr          $ra
    // 0x807997EC: nop

    return;
    // 0x807997EC: nop

;}
RECOMP_FUNC void func_8067B4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067B4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067B4AC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8067B4B0: lbu         $a2, 0x23($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X23);
    // 0x8067B4B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067B4B8: andi        $a2, $a2, 0x3F
    ctx->r6 = ctx->r6 & 0X3F;
    // 0x8067B4BC: jal         0x8067B194
    // 0x8067B4C0: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    func_8067B194(rdram, ctx);
        goto after_0;
    // 0x8067B4C0: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    after_0:
    // 0x8067B4C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067B4C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067B4CC: jr          $ra
    // 0x8067B4D0: nop

    return;
    // 0x8067B4D0: nop

;}
RECOMP_FUNC void func_806662B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806662B8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806662BC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806662C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806662C4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806662C8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806662CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806662D0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806662D4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806662D8: lui         $t1, 0x8066
    ctx->r9 = S32(RELOC_HI16(504, 0X2D30) << 16);
    // 0x806662DC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806662E0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806662E4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806662E8: lw          $t1, 0x7A00($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(504, 0X2D30));
    // 0x806662EC: jr          $ra
    // 0x806662F0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806662F0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8076D320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D320: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x8076D324: beq         $v0, $zero, L_8076D334
    if (ctx->r2 == 0) {
        // 0x8076D328: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8076D334;
    }
    // 0x8076D328: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8076D32C: jr          $ra
    // 0x8076D330: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    return;
    // 0x8076D330: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_8076D334:
    // 0x8076D334: lh          $v0, 0x144($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X144);
    // 0x8076D338: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8076D33C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8076D340: bne         $v0, $at, L_8076D350
    if (ctx->r2 != ctx->r1) {
        // 0x8076D344: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_8076D350;
    }
    // 0x8076D344: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8076D348: jr          $ra
    // 0x8076D34C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    return;
    // 0x8076D34C: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
L_8076D350:
    // 0x8076D350: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8076D354: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x8076D358: jr          $ra
    // 0x8076D35C: nop

    return;
    // 0x8076D35C: nop

;}
RECOMP_FUNC void func_80471088(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471088: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8047108C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80471090: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80471094: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80471098: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(155, 0X390) << 16);
    // 0x8047109C: addiu       $t8, $t8, 0x13D0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(155, 0X390));
    // 0x804710A0: addiu       $t7, $t6, 0x4C
    ctx->r15 = ADD32(ctx->r14, 0X4C);
    // 0x804710A4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x804710A8: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x804710AC: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(155, 0X380) << 16);
    // 0x804710B0: sw          $t8, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r24;
    // 0x804710B4: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x804710B8: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x804710BC: addiu       $t9, $t9, 0x13C0
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(155, 0X380));
    // 0x804710C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804710C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x804710C8: jal         0x8047139C
    // 0x804710CC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    func_8047139C(rdram, ctx);
        goto after_0;
    // 0x804710CC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    after_0:
    // 0x804710D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804710D4: jal         0x80045A34
    // 0x804710D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x804710D8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x804710DC: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804710E0: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804710E4: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(155, 0X3D0) << 16);
    // 0x804710E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x804710EC: lwc1        $f6, 0x1410($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(155, 0X3D0));
    // 0x804710F0: lui         $t2, 0x8005
    ctx->r10 = S32(0X8005 << 16);
    // 0x804710F4: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x804710F8: addiu       $t2, $t2, -0x7C48
    ctx->r10 = ADD32(ctx->r10, -0X7C48);
    // 0x804710FC: sw          $t1, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r9;
    // 0x80471100: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x80471104: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x80471108: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8047110C: addiu       $t3, $zero, 0xC80
    ctx->r11 = ADD32(0, 0XC80);
    // 0x80471110: lui         $t9, 0x8047
    ctx->r25 = S32(RELOC_HI16(155, 0X398) << 16);
    // 0x80471114: sh          $t3, 0x30($t4)
    MEM_H(0X30, ctx->r12) = ctx->r11;
    // 0x80471118: lw          $t9, 0x13D8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(155, 0X398));
    // 0x8047111C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80471120: jalr        $t9
    // 0x80471124: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80471124: nop

    after_2:
    // 0x80471128: lw          $t5, 0x15C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X15C);
    // 0x8047112C: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80471130: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80471134: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80471138: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8047113C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80471140: addu        $t0, $t6, $t8
    ctx->r8 = ADD32(ctx->r14, ctx->r24);
    // 0x80471144: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80471148: sh          $t1, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r9;
    // 0x8047114C: jal         0x80471050
    // 0x80471150: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    func_80471050(rdram, ctx);
        goto after_3;
    // 0x80471150: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
    after_3:
    // 0x80471154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80471158: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8047115C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80471160: jr          $ra
    // 0x80471164: nop

    return;
    // 0x80471164: nop

;}
RECOMP_FUNC void func_8004D51C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D51C: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D520: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D524: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D528: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D52C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D530: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D534: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D538: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D53C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8004D540: bne         $t9, $zero, L_8004D564
    if (ctx->r25 != 0) {
        // 0x8004D544: nop
    
            goto L_8004D564;
    }
    // 0x8004D544: nop

    // 0x8004D548: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D54C: nop

    // 0x8004D550: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004D554: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D558: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8004D55C: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8004D560: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
L_8004D564:
    // 0x8004D564: jr          $ra
    // 0x8004D568: nop

    return;
    // 0x8004D568: nop

;}
RECOMP_FUNC void func_8043FEAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043FEAC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8043FEB0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8043FEB4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8043FEB8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8043FEBC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8043FEC0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8043FEC4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8043FEC8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8043FECC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8043FED0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8043FED4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8043FED8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8043FEDC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8043FEE0: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043FEE4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8043FEE8: lwc1        $f2, 0x3C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8043FEEC: lw          $s1, 0x1C90($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X1C90);
    // 0x8043FEF0: lwc1        $f12, 0x40($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8043FEF4: lwc1        $f0, 0x1C2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X1C2C);
    // 0x8043FEF8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8043FEFC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x8043FF00: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8043FF04: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x8043FF08: slti        $at, $s1, 0x96
    ctx->r1 = SIGNED(ctx->r17) < 0X96 ? 1 : 0;
    // 0x8043FF0C: beq         $at, $zero, L_8044006C
    if (ctx->r1 == 0) {
        // 0x8043FF10: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8044006C;
    }
    // 0x8043FF10: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8043FF14: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(95, 0X4EB8) << 16);
    // 0x8043FF18: lwc1        $f30, 0x3DB8($at)
    ctx->f30.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(95, 0X4EB8));
    // 0x8043FF1C: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x8043FF20: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8043FF24: swc1        $f12, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f12.u32l;
    // 0x8043FF28: addiu       $s4, $zero, 0x168
    ctx->r20 = ADD32(0, 0X168);
L_8043FF2C:
    // 0x8043FF2C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8043FF30: lwc1        $f6, 0x3C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x8043FF34: lwc1        $f0, 0x6C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8043FF38: lwc1        $f24, 0x1C24($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X1C24);
    // 0x8043FF3C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8043FF40: lwc1        $f26, 0x1C28($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X1C28);
    // 0x8043FF44: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8043FF48: lwc1        $f20, 0x8($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8043FF4C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8043FF50: lwc1        $f22, 0xC($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8043FF54: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8043FF58: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8043FF5C: lwc1        $f4, 0x40($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8043FF60: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8043FF64: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8043FF68: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043FF6C: jal         0x800653D8
    // 0x8043FF70: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x8043FF70: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_0:
    // 0x8043FF74: div         $zero, $v0, $s4
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r20)));
    // 0x8043FF78: mfhi        $t7
    ctx->r15 = hi;
    // 0x8043FF7C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8043FF80: bne         $s4, $zero, L_8043FF8C
    if (ctx->r20 != 0) {
        // 0x8043FF84: nop
    
            goto L_8043FF8C;
    }
    // 0x8043FF84: nop

    // 0x8043FF88: break       7
    do_break(2151939976);
L_8043FF8C:
    // 0x8043FF8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8043FF90: bne         $s4, $at, L_8043FFA4
    if (ctx->r20 != ctx->r1) {
        // 0x8043FF94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8043FFA4;
    }
    // 0x8043FF94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8043FF98: bne         $v0, $at, L_8043FFA4
    if (ctx->r2 != ctx->r1) {
        // 0x8043FF9C: nop
    
            goto L_8043FFA4;
    }
    // 0x8043FF9C: nop

    // 0x8043FFA0: break       6
    do_break(2151940000);
L_8043FFA4:
    // 0x8043FFA4: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8043FFA8: jal         0x80066E88
    // 0x8043FFAC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8043FFAC: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    after_1:
    // 0x8043FFB0: mul.s       $f4, $f0, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8043FFB4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8043FFB8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x8043FFBC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8043FFC0: jal         0x80066DE4
    // 0x8043FFC4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8043FFC4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8043FFC8: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8043FFCC: mul.s       $f10, $f0, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8043FFD0: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8043FFD4: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x8043FFD8: addiu       $s1, $s1, 0x7
    ctx->r17 = ADD32(ctx->r17, 0X7);
    // 0x8043FFDC: slti        $at, $s1, 0x96
    ctx->r1 = SIGNED(ctx->r17) < 0X96 ? 1 : 0;
    // 0x8043FFE0: neg.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = -ctx->f24.fl;
    // 0x8043FFE4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8043FFE8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8043FFEC: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8043FFF0: bc1fl       L_8044001C
    if (!c1cs) {
        // 0x8043FFF4: swc1        $f2, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
            goto L_8044001C;
    }
    goto skip_0;
    // 0x8043FFF4: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    skip_0:
    // 0x8043FFF8: c.lt.s      $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f20.fl < ctx->f24.fl;
    // 0x8043FFFC: nop

    // 0x80440000: bc1f        L_80440010
    if (!c1cs) {
        // 0x80440004: nop
    
            goto L_80440010;
    }
    // 0x80440004: nop

    // 0x80440008: b           L_8044001C
    // 0x8044000C: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
        goto L_8044001C;
    // 0x8044000C: swc1        $f20, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f20.u32l;
L_80440010:
    // 0x80440010: b           L_8044001C
    // 0x80440014: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
        goto L_8044001C;
    // 0x80440014: swc1        $f24, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f24.u32l;
    // 0x80440018: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
L_8044001C:
    // 0x8044001C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80440020: neg.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = -ctx->f26.fl;
    // 0x80440024: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x80440028: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8044002C: nop

    // 0x80440030: bc1fl       L_8044005C
    if (!c1cs) {
        // 0x80440034: swc1        $f0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
            goto L_8044005C;
    }
    goto skip_1;
    // 0x80440034: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    skip_1:
    // 0x80440038: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x8044003C: nop

    // 0x80440040: bc1f        L_80440050
    if (!c1cs) {
        // 0x80440044: nop
    
            goto L_80440050;
    }
    // 0x80440044: nop

    // 0x80440048: b           L_8044005C
    // 0x8044004C: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
        goto L_8044005C;
    // 0x8044004C: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
L_80440050:
    // 0x80440050: b           L_8044005C
    // 0x80440054: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
        goto L_8044005C;
    // 0x80440054: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
    // 0x80440058: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
L_8044005C:
    // 0x8044005C: bne         $at, $zero, L_8043FF2C
    if (ctx->r1 != 0) {
        // 0x80440060: addiu       $s0, $s0, 0x150
        ctx->r16 = ADD32(ctx->r16, 0X150);
            goto L_8043FF2C;
    }
    // 0x80440060: addiu       $s0, $s0, 0x150
    ctx->r16 = ADD32(ctx->r16, 0X150);
    // 0x80440064: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80440068: lwc1        $f2, 0x64($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X64);
L_8044006C:
    // 0x8044006C: addiu       $s0, $s2, 0x4
    ctx->r16 = ADD32(ctx->r18, 0X4);
    // 0x80440070: addiu       $s1, $zero, 0x95
    ctx->r17 = ADD32(0, 0X95);
L_80440074:
    // 0x80440074: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80440078: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8044007C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80440080: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80440084: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80440088: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8044008C: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x80440090: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80440094: swc1        $f10, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80440098: lwc1        $f6, -0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X10);
    // 0x8044009C: swc1        $f4, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->f4.u32l;
    // 0x804400A0: lwc1        $f10, -0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, -0XC);
    // 0x804400A4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x804400A8: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x804400AC: swc1        $f8, -0x30($s0)
    MEM_W(-0X30, ctx->r16) = ctx->f8.u32l;
    // 0x804400B0: bgez        $s1, L_80440074
    if (SIGNED(ctx->r17) >= 0) {
        // 0x804400B4: swc1        $f16, -0x2C($s0)
        MEM_W(-0X2C, ctx->r16) = ctx->f16.u32l;
            goto L_80440074;
    }
    // 0x804400B4: swc1        $f16, -0x2C($s0)
    MEM_W(-0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x804400B8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x804400BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804400C0: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804400C4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804400C8: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804400CC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804400D0: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804400D4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804400D8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804400DC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804400E0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x804400E4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x804400E8: jr          $ra
    // 0x804400EC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x804400EC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80446B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446B80: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446B84: jr          $ra
    // 0x80446B88: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    return;
    // 0x80446B88: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
;}
RECOMP_FUNC void func_807C3360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3360: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x807C3364: addiu       $at, $zero, 0x4725
    ctx->r1 = ADD32(0, 0X4725);
    // 0x807C3368: beq         $v0, $at, L_807C3388
    if (ctx->r2 == ctx->r1) {
        // 0x807C336C: addiu       $at, $zero, 0x4726
        ctx->r1 = ADD32(0, 0X4726);
            goto L_807C3388;
    }
    // 0x807C336C: addiu       $at, $zero, 0x4726
    ctx->r1 = ADD32(0, 0X4726);
    // 0x807C3370: beq         $v0, $at, L_807C3394
    if (ctx->r2 == ctx->r1) {
        // 0x807C3374: addiu       $at, $zero, 0x4727
        ctx->r1 = ADD32(0, 0X4727);
            goto L_807C3394;
    }
    // 0x807C3374: addiu       $at, $zero, 0x4727
    ctx->r1 = ADD32(0, 0X4727);
    // 0x807C3378: beq         $v0, $at, L_807C33A0
    if (ctx->r2 == ctx->r1) {
        // 0x807C337C: nop
    
            goto L_807C33A0;
    }
    // 0x807C337C: nop

    // 0x807C3380: b           L_807C33AC
    // 0x807C3384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807C33AC;
    // 0x807C3384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807C3388:
    // 0x807C3388: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(907, 0X358) << 16);
    // 0x807C338C: jr          $ra
    // 0x807C3390: addiu       $v0, $v0, 0x36B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0X358));
    return;
    // 0x807C3390: addiu       $v0, $v0, 0x36B8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0X358));
L_807C3394:
    // 0x807C3394: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(907, 0XCA4) << 16);
    // 0x807C3398: jr          $ra
    // 0x807C339C: addiu       $v0, $v0, 0x4004
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0XCA4));
    return;
    // 0x807C339C: addiu       $v0, $v0, 0x4004
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0XCA4));
L_807C33A0:
    // 0x807C33A0: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(907, 0XDA0) << 16);
    // 0x807C33A4: jr          $ra
    // 0x807C33A8: addiu       $v0, $v0, 0x4100
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0XDA0));
    return;
    // 0x807C33A8: addiu       $v0, $v0, 0x4100
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(907, 0XDA0));
L_807C33AC:
    // 0x807C33AC: jr          $ra
    // 0x807C33B0: nop

    return;
    // 0x807C33B0: nop

;}
RECOMP_FUNC void func_8045A944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A944: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8045A948: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8045A94C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8045A950: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8045A954: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8045A958: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8045A95C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8045A960: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(101, 0X4F0) << 16);
    // 0x8045A964: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8045A968: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045A96C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8045A970: lw          $t1, -0x5680($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(101, 0X4F0));
    // 0x8045A974: jr          $ra
    // 0x8045A978: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8045A978: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x8045A97C: nop

;}
RECOMP_FUNC void func_806655E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806655E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806655E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806655EC: jal         0x8004700C
    // 0x806655F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806655F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806655F4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x806655F8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806655FC: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80665600: lw          $v1, 0x1E0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X1E0);
    // 0x80665604: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80665608: beq         $v1, $zero, L_80665618
    if (ctx->r3 == 0) {
        // 0x8066560C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80665618;
    }
    // 0x8066560C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80665610: b           L_80665654
    // 0x80665614: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
        goto L_80665654;
    // 0x80665614: sw          $t6, 0x1E0($a3)
    MEM_W(0X1E0, ctx->r7) = ctx->r14;
L_80665618:
    // 0x80665618: beq         $v0, $zero, L_80665654
    if (ctx->r2 == 0) {
        // 0x8066561C: addiu       $a0, $zero, -0x63
        ctx->r4 = ADD32(0, -0X63);
            goto L_80665654;
    }
    // 0x8066561C: addiu       $a0, $zero, -0x63
    ctx->r4 = ADD32(0, -0X63);
    // 0x80665620: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80665624: jal         0x800492C0
    // 0x80665628: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x80665628: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x8066562C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80665630: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80665634: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80665638: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8066563C: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x80665640: sb          $v1, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r3;
    // 0x80665644: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80665648: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8066564C: jal         0x8066622C
    // 0x80665650: sb          $v1, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r3;
    func_8066622C(rdram, ctx);
        goto after_2;
    // 0x80665650: sb          $v1, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r3;
    after_2:
L_80665654:
    // 0x80665654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80665658: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8066565C: jr          $ra
    // 0x80665660: nop

    return;
    // 0x80665660: nop

;}
RECOMP_FUNC void func_806B28EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B28EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B28F0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B28F4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B28F8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B28FC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2900: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2904: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2908: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B290C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2910: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2914: jr          $ra
    // 0x806B2918: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2918: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F17B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F17B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F17B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F17BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F17C0: jal         0x8004700C
    // 0x806F17C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F17C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F17C8: beql        $v0, $zero, L_806F1888
    if (ctx->r2 == 0) {
        // 0x806F17CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1888;
    }
    goto skip_0;
    // 0x806F17CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F17D0: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x806F17D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806F17D8: bnel        $t6, $at, L_806F1888
    if (ctx->r14 != ctx->r1) {
        // 0x806F17DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1888;
    }
    goto skip_1;
    // 0x806F17DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806F17E0: lbu         $t7, 0x30($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X30);
    // 0x806F17E4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x806F17E8: bnel        $t7, $at, L_806F1888
    if (ctx->r15 != ctx->r1) {
        // 0x806F17EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1888;
    }
    goto skip_2;
    // 0x806F17EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x806F17F0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806F17F4: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806F17F8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(679, 0X1BD4) << 16);
    // 0x806F17FC: lwc1        $f8, 0x3154($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(679, 0X1BD4));
    // 0x806F1800: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F1804: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806F1808: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806F180C: nop

    // 0x806F1810: bc1fl       L_806F1888
    if (!c1cs) {
        // 0x806F1814: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1888;
    }
    goto skip_3;
    // 0x806F1814: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x806F1818: lw          $t8, 0x174($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X174);
    // 0x806F181C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1824: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x806F1828: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F182C: andi        $t0, $t9, 0xF00
    ctx->r8 = ctx->r25 & 0XF00;
    // 0x806F1830: beql        $t0, $zero, L_806F1888
    if (ctx->r8 == 0) {
        // 0x806F1834: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F1888;
    }
    goto skip_4;
    // 0x806F1834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x806F1838: jal         0x806F1F14
    // 0x806F183C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806F1F14(rdram, ctx);
        goto after_1;
    // 0x806F183C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_1:
    // 0x806F1840: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F1844: jal         0x8005FDC4
    // 0x806F1848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_2;
    // 0x806F1848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F184C: jal         0x806F1644
    // 0x806F1850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F1644(rdram, ctx);
        goto after_3;
    // 0x806F1850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F1854: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x806F1858: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x806F185C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806F1860: andi        $t2, $t1, 0xFF03
    ctx->r10 = ctx->r9 & 0XFF03;
    // 0x806F1864: ori         $t3, $t2, 0x44
    ctx->r11 = ctx->r10 | 0X44;
    // 0x806F1868: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
    // 0x806F186C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x806F1870: jal         0x80067E68
    // 0x806F1874: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    func_80067E68(rdram, ctx);
        goto after_4;
    // 0x806F1874: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x806F1878: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806F187C: jal         0x80067818
    // 0x806F1880: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x806F1880: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x806F1884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1888:
    // 0x806F1888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F188C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1890: jr          $ra
    // 0x806F1894: nop

    return;
    // 0x806F1894: nop

;}
RECOMP_FUNC void func_80020508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020508: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002050C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80020510: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80020514: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80020518: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002051C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x80020520: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80020524: bnel        $t7, $zero, L_80020570
    if (ctx->r15 != 0) {
        // 0x80020528: lw          $t5, 0x34($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X34);
            goto L_80020570;
    }
    goto skip_0;
    // 0x80020528: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8002052C: lw          $v0, 0x2C($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X2C);
    // 0x80020530: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80020534: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x80020538: andi        $v0, $v0, 0x700
    ctx->r2 = ctx->r2 & 0X700;
    // 0x8002053C: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x80020540: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80020544: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80020548: lw          $t0, -0x6568($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6568);
    // 0x8002054C: lw          $t3, 0x40($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X40);
    // 0x80020550: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80020554: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80020558: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8002055C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80020560: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80020564: jal         0x8004A9C4
    // 0x80020568: lhu         $a2, 0x0($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X0);
    func_8004A9C4(rdram, ctx);
        goto after_0;
    // 0x80020568: lhu         $a2, 0x0($t4)
    ctx->r6 = MEM_HU(ctx->r12, 0X0);
    after_0:
    // 0x8002056C: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
L_80020570:
    // 0x80020570: lw          $t6, 0x2C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X2C);
    // 0x80020574: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x80020578: bnel        $t7, $zero, L_800205AC
    if (ctx->r15 != 0) {
        // 0x8002057C: lwc1        $f4, 0xC8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_800205AC;
    }
    goto skip_1;
    // 0x8002057C: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    skip_1:
    // 0x80020580: lw          $t8, 0x38($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X38);
    // 0x80020584: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80020588: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x8002058C: andi        $t9, $t8, 0x700
    ctx->r25 = ctx->r24 & 0X700;
    // 0x80020590: bne         $t9, $zero, L_800205A8
    if (ctx->r25 != 0) {
        // 0x80020594: addiu       $a2, $zero, 0xF0
        ctx->r6 = ADD32(0, 0XF0);
            goto L_800205A8;
    }
    // 0x80020594: addiu       $a2, $zero, 0xF0
    ctx->r6 = ADD32(0, 0XF0);
    // 0x80020598: jal         0x800475EC
    // 0x8002059C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_800475EC(rdram, ctx);
        goto after_1;
    // 0x8002059C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x800205A0: beq         $v0, $zero, L_800205FC
    if (ctx->r2 == 0) {
        // 0x800205A4: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_800205FC;
    }
    // 0x800205A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_800205A8:
    // 0x800205A8: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
L_800205AC:
    // 0x800205AC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800205B0: jal         0x8001D770
    // 0x800205B4: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x800205B4: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x800205B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800205BC: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800205C0: jal         0x80067BF8
    // 0x800205C4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x800205C4: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x800205C8: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x800205CC: jal         0x80067818
    // 0x800205D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x800205D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x800205D4: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x800205D8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800205DC: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x800205E0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800205E4: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x800205E8: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x800205EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800205F0: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x800205F4: b           L_800206A0
    // 0x800205F8: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
        goto L_800206A0;
    // 0x800205F8: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_800205FC:
    // 0x800205FC: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80020600: lw          $t4, 0x2C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X2C);
    // 0x80020604: andi        $t6, $t4, 0x3000
    ctx->r14 = ctx->r12 & 0X3000;
    // 0x80020608: bnel        $t6, $zero, L_80020638
    if (ctx->r14 != 0) {
        // 0x8002060C: lwc1        $f8, 0xC8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80020638;
    }
    goto skip_2;
    // 0x8002060C: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    skip_2:
    // 0x80020610: lw          $t7, 0x38($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X38);
    // 0x80020614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80020618: andi        $t5, $t7, 0x3000
    ctx->r13 = ctx->r15 & 0X3000;
    // 0x8002061C: bnel        $t5, $zero, L_80020638
    if (ctx->r13 != 0) {
        // 0x80020620: lwc1        $f8, 0xC8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_80020638;
    }
    goto skip_3;
    // 0x80020620: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    skip_3:
    // 0x80020624: jal         0x80047590
    // 0x80020628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80047590(rdram, ctx);
        goto after_5;
    // 0x80020628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8002062C: beq         $v0, $zero, L_800206A0
    if (ctx->r2 == 0) {
        // 0x80020630: nop
    
            goto L_800206A0;
    }
    // 0x80020630: nop

    // 0x80020634: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
L_80020638:
    // 0x80020638: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8002063C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80020640: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x80020644: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80020648: beq         $t9, $zero, L_80020658
    if (ctx->r25 == 0) {
        // 0x8002064C: nop
    
            goto L_80020658;
    }
    // 0x8002064C: nop

    // 0x80020650: jal         0x80061170
    // 0x80020654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80061170(rdram, ctx);
        goto after_6;
    // 0x80020654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80020658:
    // 0x80020658: jal         0x8001D770
    // 0x8002065C: nop

    func_8001D770(rdram, ctx);
        goto after_7;
    // 0x8002065C: nop

    after_7:
    // 0x80020660: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80020664: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80020668: jal         0x80067BF8
    // 0x8002066C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_8;
    // 0x8002066C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_8:
    // 0x80020670: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80020674: jal         0x80067818
    // 0x80020678: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x80020678: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8002067C: addiu       $t0, $zero, 0x50
    ctx->r8 = ADD32(0, 0X50);
    // 0x80020680: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020684: sb          $t0, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r8;
    // 0x80020688: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8002068C: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80020690: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x80020694: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020698: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8002069C: sb          $t1, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r9;
L_800206A0:
    // 0x800206A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800206A4: lwc1        $f16, -0x40C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X40C);
    // 0x800206A8: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800206AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800206B0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800206B4: nop

    // 0x800206B8: bc1tl       L_800206D8
    if (c1cs) {
        // 0x800206BC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800206D8;
    }
    goto skip_4;
    // 0x800206BC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_4:
    // 0x800206C0: lwc1        $f18, -0x408($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X408);
    // 0x800206C4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800206C8: nop

    // 0x800206CC: bc1fl       L_80020810
    if (!c1cs) {
        // 0x800206D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80020810;
    }
    goto skip_5;
    // 0x800206D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x800206D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800206D8:
    // 0x800206D8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800206DC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800206E0: nop

    // 0x800206E4: bc1fl       L_80020784
    if (!c1cs) {
        // 0x800206E8: lw          $t0, 0x2C($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X2C);
            goto L_80020784;
    }
    goto skip_6;
    // 0x800206E8: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    skip_6:
    // 0x800206EC: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800206F0: lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // 0x800206F4: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    // 0x800206F8: and         $t6, $t4, $v0
    ctx->r14 = ctx->r12 & ctx->r2;
    // 0x800206FC: bnel        $t6, $zero, L_80020734
    if (ctx->r14 != 0) {
        // 0x80020700: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_80020734;
    }
    goto skip_7;
    // 0x80020700: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_7:
    // 0x80020704: lw          $t3, 0x38($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X38);
    // 0x80020708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002070C: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x80020710: and         $t7, $t3, $v0
    ctx->r15 = ctx->r11 & ctx->r2;
    // 0x80020714: bnel        $t7, $zero, L_80020734
    if (ctx->r15 != 0) {
        // 0x80020718: neg.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
            goto L_80020734;
    }
    goto skip_8;
    // 0x80020718: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    skip_8:
    // 0x8002071C: jal         0x80047534
    // 0x80020720: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    func_80047534(rdram, ctx);
        goto after_10;
    // 0x80020720: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    after_10:
    // 0x80020724: beql        $v0, $zero, L_80020810
    if (ctx->r2 == 0) {
        // 0x80020728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80020810;
    }
    goto skip_9;
    // 0x80020728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8002072C: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80020730: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
L_80020734:
    // 0x80020734: jal         0x8001D770
    // 0x80020738: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    func_8001D770(rdram, ctx);
        goto after_11;
    // 0x80020738: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    after_11:
    // 0x8002073C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80020740: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80020744: jal         0x80067BF8
    // 0x80020748: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_12;
    // 0x80020748: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_12:
    // 0x8002074C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x80020750: jal         0x80067818
    // 0x80020754: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_13;
    // 0x80020754: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x80020758: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8002075C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020760: sb          $t5, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r13;
    // 0x80020764: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020768: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8002076C: sb          $t8, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r24;
    // 0x80020770: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020774: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80020778: b           L_8002080C
    // 0x8002077C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
        goto L_8002080C;
    // 0x8002077C: sb          $t9, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r25;
    // 0x80020780: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
L_80020784:
    // 0x80020784: lui         $v0, 0xF0
    ctx->r2 = S32(0XF0 << 16);
    // 0x80020788: and         $t2, $t0, $v0
    ctx->r10 = ctx->r8 & ctx->r2;
    // 0x8002078C: bnel        $t2, $zero, L_800207C4
    if (ctx->r10 != 0) {
        // 0x80020790: neg.s       $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
            goto L_800207C4;
    }
    goto skip_10;
    // 0x80020790: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    skip_10:
    // 0x80020794: lw          $t1, 0x38($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X38);
    // 0x80020798: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002079C: addiu       $a1, $s0, 0xC4
    ctx->r5 = ADD32(ctx->r16, 0XC4);
    // 0x800207A0: and         $t4, $t1, $v0
    ctx->r12 = ctx->r9 & ctx->r2;
    // 0x800207A4: bnel        $t4, $zero, L_800207C4
    if (ctx->r12 != 0) {
        // 0x800207A8: neg.s       $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
            goto L_800207C4;
    }
    goto skip_11;
    // 0x800207A8: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    skip_11:
    // 0x800207AC: jal         0x800474D8
    // 0x800207B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800474D8(rdram, ctx);
        goto after_14;
    // 0x800207B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x800207B4: beql        $v0, $zero, L_80020810
    if (ctx->r2 == 0) {
        // 0x800207B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80020810;
    }
    goto skip_12;
    // 0x800207B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x800207BC: lwc1        $f0, 0xC4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800207C0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
L_800207C4:
    // 0x800207C4: jal         0x8001D770
    // 0x800207C8: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    func_8001D770(rdram, ctx);
        goto after_15;
    // 0x800207C8: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    after_15:
    // 0x800207CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800207D0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800207D4: jal         0x80067BF8
    // 0x800207D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_16;
    // 0x800207D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_16:
    // 0x800207DC: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x800207E0: jal         0x80067818
    // 0x800207E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_17;
    // 0x800207E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x800207E8: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800207EC: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800207F0: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x800207F4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x800207F8: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x800207FC: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x80020800: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80020804: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x80020808: sb          $t7, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r15;
L_8002080C:
    // 0x8002080C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80020810:
    // 0x80020810: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80020814: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80020818: jr          $ra
    // 0x8002081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002081C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void func_806E6EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6EA0: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(658, 0XE8) << 16);
    // 0x806E6EA4: addiu       $v0, $v0, 0x6F88
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(658, 0XE8));
    // 0x806E6EA8: jr          $ra
    // 0x806E6EAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806E6EAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_807B0170(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B0170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807B0174: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B0178: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B017C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B0180: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B0184: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B0188: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B018C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807B0190: lw          $s0, 0xC($a0)
    ctx->r16 = MEM_W(ctx->r4, 0XC);
    // 0x807B0194: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B0198: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x807B019C: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x807B01A0: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // 0x807B01A4: jal         0x80064D1C
    // 0x807B01A8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x807B01A8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_0:
    // 0x807B01AC: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x807B01B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807B01B4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x807B01B8: jal         0x807B00B0
    // 0x807B01BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_807B00B0(rdram, ctx);
        goto after_1;
    // 0x807B01BC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x807B01C0: sll         $s4, $s0, 4
    ctx->r20 = S32(ctx->r16 << 4);
    // 0x807B01C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x807B01C8: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x807B01CC: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_807B01D0:
    // 0x807B01D0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B01D4: jal         0x80064D1C
    // 0x807B01D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x807B01D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    after_2:
    // 0x807B01DC: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x807B01E0: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x807B01E4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B01E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x807B01EC: beq         $t6, $zero, L_807B0234
    if (ctx->r14 == 0) {
        // 0x807B01F0: nop
    
            goto L_807B0234;
    }
    // 0x807B01F0: nop

    // 0x807B01F4: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
L_807B01F8:
    // 0x807B01F8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x807B01FC: sh          $zero, 0x4($v1)
    MEM_H(0X4, ctx->r3) = 0;
    // 0x807B0200: sh          $zero, 0x6($v1)
    MEM_H(0X6, ctx->r3) = 0;
    // 0x807B0204: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x807B0208: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
    // 0x807B020C: sb          $zero, 0xC($v1)
    MEM_B(0XC, ctx->r3) = 0;
    // 0x807B0210: sb          $zero, 0xD($v1)
    MEM_B(0XD, ctx->r3) = 0;
    // 0x807B0214: sb          $zero, 0xE($v1)
    MEM_B(0XE, ctx->r3) = 0;
    // 0x807B0218: sb          $zero, 0xF($v1)
    MEM_B(0XF, ctx->r3) = 0;
    // 0x807B021C: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x807B0220: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B0224: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x807B0228: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x807B022C: bnel        $at, $zero, L_807B01F8
    if (ctx->r1 != 0) {
        // 0x807B0230: sh          $zero, 0x0($v1)
        MEM_H(0X0, ctx->r3) = 0;
            goto L_807B01F8;
    }
    goto skip_0;
    // 0x807B0230: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    skip_0:
L_807B0234:
    // 0x807B0234: bne         $s2, $s5, L_807B01D0
    if (ctx->r18 != ctx->r21) {
        // 0x807B0238: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_807B01D0;
    }
    // 0x807B0238: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x807B023C: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x807B0240: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B0244: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B0248: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B024C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B0250: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B0254: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B0258: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B025C: jr          $ra
    // 0x807B0260: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807B0260: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80580B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580B6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580B70: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580B74: jal         0x80045A34
    // 0x80580B78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80580B78: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80580B7C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80580B80: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80580B84: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80580B88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580B8C: jal         0x800657CC
    // 0x80580B90: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80580B90: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80580B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580B9C: jr          $ra
    // 0x80580BA0: nop

    return;
    // 0x80580BA0: nop

;}
RECOMP_FUNC void func_80530998(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530998: lh          $v0, 0x184($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X184);
    // 0x8053099C: sll         $a1, $zero, 2
    ctx->r5 = S32(0 << 2);
    // 0x805309A0: addu        $a2, $a0, $a1
    ctx->r6 = ADD32(ctx->r4, ctx->r5);
    // 0x805309A4: blez        $v0, L_80530A00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805309A8: addiu       $t0, $zero, 0x4001
        ctx->r8 = ADD32(0, 0X4001);
            goto L_80530A00;
    }
    // 0x805309A8: addiu       $t0, $zero, 0x4001
    ctx->r8 = ADD32(0, 0X4001);
    // 0x805309AC: lw          $v1, 0x188($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X188);
L_805309B0:
    // 0x805309B0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x805309B4: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    // 0x805309B8: beq         $v1, $zero, L_805309F0
    if (ctx->r3 == 0) {
        // 0x805309BC: nop
    
            goto L_805309F0;
    }
    // 0x805309BC: nop

    // 0x805309C0: lw          $a3, 0x174($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X174);
    // 0x805309C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x805309C8: beq         $a3, $zero, L_805309F0
    if (ctx->r7 == 0) {
        // 0x805309CC: nop
    
            goto L_805309F0;
    }
    // 0x805309CC: nop

    // 0x805309D0: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x805309D4: bne         $a0, $t6, L_805309F0
    if (ctx->r4 != ctx->r14) {
        // 0x805309D8: nop
    
            goto L_805309F0;
    }
    // 0x805309D8: nop

    // 0x805309DC: lhu         $t7, 0xC($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XC);
    // 0x805309E0: bne         $t0, $t7, L_805309F0
    if (ctx->r8 != ctx->r15) {
        // 0x805309E4: nop
    
            goto L_805309F0;
    }
    // 0x805309E4: nop

    // 0x805309E8: jr          $ra
    // 0x805309EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x805309EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_805309F0:
    // 0x805309F0: beq         $at, $zero, L_80530A00
    if (ctx->r1 == 0) {
        // 0x805309F4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80530A00;
    }
    // 0x805309F4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x805309F8: bgtzl       $v0, L_805309B0
    if (SIGNED(ctx->r2) > 0) {
        // 0x805309FC: lw          $v1, 0x188($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X188);
            goto L_805309B0;
    }
    goto skip_0;
    // 0x805309FC: lw          $v1, 0x188($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X188);
    skip_0:
L_80530A00:
    // 0x80530A00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80530A04: jr          $ra
    // 0x80530A08: nop

    return;
    // 0x80530A08: nop

;}
RECOMP_FUNC void ltrunc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082078: trunc.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_D(ctx->f12.d);
    // 0x8008207C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80082080: jr          $ra
    // 0x80082084: nop

    return;
    // 0x80082084: nop

;}
RECOMP_FUNC void func_8044AE9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AE9C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AEA0: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X134E4) << 16);
    // 0x8044AEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AEA8: addiu       $t6, $t6, 0x78C4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X134E4));
    // 0x8044AEAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AEB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AEB4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AEB8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AEBC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AEC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AEC4: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044AEC8: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044AECC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044AED0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044AED4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044AED8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044AEDC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AEE0: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044AEE4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044AEE8: jal         0x80050A50
    // 0x8044AEEC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044AEEC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044AEF0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044AEF4: jalr        $v0
    // 0x8044AEF8: sw          $v0, 0x6A64($v1)
    MEM_W(0X6A64, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044AEF8: sw          $v0, 0x6A64($v1)
    MEM_W(0X6A64, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044AEFC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AF00: sw          $v0, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r2;
    // 0x8044AF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AF08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044AF0C: jr          $ra
    // 0x8044AF10: nop

    return;
    // 0x8044AF10: nop

;}
RECOMP_FUNC void func_8044AA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044AA6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044AA70: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13484) << 16);
    // 0x8044AA74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044AA78: addiu       $t6, $t6, 0x7864
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13484));
    // 0x8044AA7C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044AA80: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044AA84: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044AA88: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044AA8C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044AA90: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044AA94: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044AA98: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044AA9C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044AAA0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044AAA4: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044AAA8: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044AAAC: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044AAB0: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044AAB4: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044AAB8: jal         0x80050A50
    // 0x8044AABC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044AABC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044AAC0: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044AAC4: jalr        $v0
    // 0x8044AAC8: sw          $v0, 0x6A5C($v1)
    MEM_W(0X6A5C, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044AAC8: sw          $v0, 0x6A5C($v1)
    MEM_W(0X6A5C, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044AACC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044AAD0: sw          $v0, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r2;
    // 0x8044AAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044AAD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044AADC: jr          $ra
    // 0x8044AAE0: nop

    return;
    // 0x8044AAE0: nop

;}
RECOMP_FUNC void func_80052798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052798: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005279C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800527A0: jal         0x8007C61C
    // 0x800527A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_8007C61C(rdram, ctx);
        goto after_0;
    // 0x800527A4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800527A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800527AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800527B0: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x800527B4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800527B8: jal         0x8008DCB0
    // 0x800527BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    osPfsFileState_recomp(rdram, ctx);
        goto after_1;
    // 0x800527BC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800527C0: bne         $v0, $zero, L_800527EC
    if (ctx->r2 != 0) {
        // 0x800527C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800527EC;
    }
    // 0x800527C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800527C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800527CC: addiu       $t6, $sp, 0x32
    ctx->r14 = ADD32(ctx->r29, 0X32);
    // 0x800527D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800527D4: addiu       $a0, $a0, -0x4D70
    ctx->r4 = ADD32(ctx->r4, -0X4D70);
    // 0x800527D8: lhu         $a1, 0x30($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X30);
    // 0x800527DC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800527E0: jal         0x8008C560
    // 0x800527E4: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    osPfsDeleteFile_recomp(rdram, ctx);
        goto after_2;
    // 0x800527E4: addiu       $a3, $sp, 0x36
    ctx->r7 = ADD32(ctx->r29, 0X36);
    after_2:
    // 0x800527E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800527EC:
    // 0x800527EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800527F0: jal         0x8007C640
    // 0x800527F4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8007C640(rdram, ctx);
        goto after_3;
    // 0x800527F4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x800527F8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800527FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052800: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052804: bne         $v1, $zero, L_80052814
    if (ctx->r3 != 0) {
        // 0x80052808: nop
    
            goto L_80052814;
    }
    // 0x80052808: nop

    // 0x8005280C: b           L_80052838
    // 0x80052810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80052838;
    // 0x80052810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80052814:
    // 0x80052814: bnel        $v1, $at, L_80052828
    if (ctx->r3 != ctx->r1) {
        // 0x80052818: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80052828;
    }
    goto skip_0;
    // 0x80052818: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8005281C: b           L_80052838
    // 0x80052820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80052838;
    // 0x80052820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80052824: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80052828:
    // 0x80052828: bne         $v1, $at, L_80052838
    if (ctx->r3 != ctx->r1) {
        // 0x8005282C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80052838;
    }
    // 0x8005282C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80052830: b           L_80052838
    // 0x80052834: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80052838;
    // 0x80052834: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80052838:
    // 0x80052838: jr          $ra
    // 0x8005283C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005283C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80522014(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80522014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80522018: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8052201C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80522020: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80522024: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80522028: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8052202C: lui         $t8, 0x8052
    ctx->r24 = S32(RELOC_HI16(315, 0X2D8) << 16);
    // 0x80522030: sb          $a3, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r7;
    // 0x80522034: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80522038: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8052203C: lw          $t8, 0x2118($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(315, 0X2D8));
    // 0x80522040: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x80522044: lui         $a1, 0x8052
    ctx->r5 = S32(RELOC_HI16(315, 0X280) << 16);
    // 0x80522048: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8052204C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80522050: jal         0x80048490
    // 0x80522054: addiu       $a1, $a1, 0x20C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(315, 0X280));
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80522054: addiu       $a1, $a1, 0x20C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(315, 0X280));
    after_0:
    // 0x80522058: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8052205C: lui         $at, 0x8052
    ctx->r1 = S32(RELOC_HI16(315, 0X2E0) << 16);
    // 0x80522060: lwc1        $f4, 0x2120($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(315, 0X2E0));
    // 0x80522064: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    // 0x80522068: jal         0x80048378
    // 0x8052206C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8052206C: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x80522070: jal         0x80521F54
    // 0x80522074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80521F54(rdram, ctx);
        goto after_2;
    // 0x80522074: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80522078: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8052207C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80522080: jr          $ra
    // 0x80522084: nop

    return;
    // 0x80522084: nop

    // 0x80522088: nop

    // 0x8052208C: nop

;}
RECOMP_FUNC void func_80584E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584E2C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584E30: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584E34: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584E38: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584E3C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584E40: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584E44: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584E48: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584E4C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584E50: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584E54: jr          $ra
    // 0x80584E58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584E58: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805DB054(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DB054: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DB058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DB05C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805DB060: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805DB064: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x805DB068: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x805DB06C: jal         0x80067BBC
    // 0x805DB070: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x805DB070: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x805DB074: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805DB078: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805DB07C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805DB080: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x805DB084: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805DB088: bne         $a1, $at, L_805DB0A8
    if (ctx->r5 != ctx->r1) {
        // 0x805DB08C: nop
    
            goto L_805DB0A8;
    }
    // 0x805DB08C: nop

    // 0x805DB090: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805DB094: jal         0x805DAFBC
    // 0x805DB098: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_805DAFBC(rdram, ctx);
        goto after_1;
    // 0x805DB098: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x805DB09C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805DB0A0: b           L_805DB0B0
    // 0x805DB0A4: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_805DB0B0;
    // 0x805DB0A4: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
L_805DB0A8:
    // 0x805DB0A8: jal         0x800678F0
    // 0x805DB0AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_800678F0(rdram, ctx);
        goto after_2;
    // 0x805DB0AC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_805DB0B0:
    // 0x805DB0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DB0B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DB0B8: jr          $ra
    // 0x805DB0BC: nop

    return;
    // 0x805DB0BC: nop

;}
RECOMP_FUNC void func_805D8778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D8778: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x805D877C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x805D8780: lui         $t0, 0x805E
    ctx->r8 = S32(RELOC_HI16(474, 0X2350) << 16);
    // 0x805D8784: bne         $v0, $zero, L_805D87B0
    if (ctx->r2 != 0) {
        // 0x805D8788: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_805D87B0;
    }
    // 0x805D8788: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x805D878C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x805D8790: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x805D8794: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x805D8798: bgez        $a1, L_805D87B8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x805D879C: sw          $a1, 0x18($a0)
        MEM_W(0X18, ctx->r4) = ctx->r5;
            goto L_805D87B8;
    }
    // 0x805D879C: sw          $a1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r5;
    // 0x805D87A0: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x805D87A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x805D87A8: b           L_805D87B8
    // 0x805D87AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_805D87B8;
    // 0x805D87AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_805D87B0:
    // 0x805D87B0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x805D87B4: lw          $a1, 0x18($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X18);
L_805D87B8:
    // 0x805D87B8: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x805D87BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x805D87C0: lw          $t0, -0x63B0($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(474, 0X2350));
    // 0x805D87C4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x805D87C8: jr          $ra
    // 0x805D87CC: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    return;
    // 0x805D87CC: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void func_8057EFA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057EFA0: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8057EFA4: lbu         $v1, -0x71F4($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X71F4);
    // 0x8057EFA8: bltz        $v1, L_8057EFB8
    if (SIGNED(ctx->r3) < 0) {
        // 0x8057EFAC: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8057EFB8;
    }
    // 0x8057EFAC: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8057EFB0: bne         $at, $zero, L_8057EFBC
    if (ctx->r1 != 0) {
        // 0x8057EFB4: nop
    
            goto L_8057EFBC;
    }
    // 0x8057EFB4: nop

L_8057EFB8:
    // 0x8057EFB8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_8057EFBC:
    // 0x8057EFBC: jr          $ra
    // 0x8057EFC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8057EFC0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_805341DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805341DC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805341E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805341E4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x805341E8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805341EC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805341F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805341F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805341F8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x805341FC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x80534200: lui         $t1, 0x8053
    ctx->r9 = S32(RELOC_HI16(345, 0X1908) << 16);
    // 0x80534204: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80534208: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8053420C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80534210: lw          $t1, 0x43D8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(345, 0X1908));
    // 0x80534214: jr          $ra
    // 0x80534218: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80534218: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8069D25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D25C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D264: jal         0x8069D1E8
    // 0x8069D268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D1E8(rdram, ctx);
        goto after_0;
    // 0x8069D268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D26C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D270: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X3F8) << 16);
    // 0x8069D274: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8069D278: addiu       $t7, $t7, -0x2F18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X3F8));
    // 0x8069D27C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8069D280: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D284: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D288: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D28C: jr          $ra
    // 0x8069D290: nop

    return;
    // 0x8069D290: nop

;}
RECOMP_FUNC void func_806662B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806662B0: jr          $ra
    // 0x806662B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806662B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805AB1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AB1B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x805AB1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AB1B8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x805AB1BC: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x805AB1C0: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x805AB1C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805AB1C8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x805AB1CC: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x805AB1D0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB04) << 16);
    // 0x805AB1D4: lwc1        $f18, -0x45BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB04));
    // 0x805AB1D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x805AB1DC: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805AB1E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805AB1E4: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805AB1E8: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x805AB1EC: lwc1        $f16, 0x8C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x805AB1F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805AB1F4: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(435, 0XB08) << 16);
    // 0x805AB1F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x805AB1FC: lwc1        $f16, -0x45B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(435, 0XB08));
    // 0x805AB200: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x805AB204: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x805AB208: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805AB20C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x805AB210: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805AB214: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805AB218: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805AB21C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x805AB220: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    // 0x805AB224: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x805AB228: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805AB22C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805AB230: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x805AB234: jalr        $t9
    // 0x805AB238: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805AB238: nop

    after_0:
    // 0x805AB23C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805AB240: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805AB244: jr          $ra
    // 0x805AB248: nop

    return;
    // 0x805AB248: nop

;}
RECOMP_FUNC void func_8000AD10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    yoshi_ai_set_next_buffer(rdram, ctx); return;
    // 0x8000AD10: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8000AD14: lbu         $t6, -0x7680($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7680);
    // 0x8000AD18: addu        $t7, $a0, $a1
    ctx->r15 = ADD32(ctx->r4, ctx->r5);
    // 0x8000AD1C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000AD20: beq         $t6, $zero, L_8000AD2C
    if (ctx->r14 == 0) {
        // 0x8000AD24: andi        $t8, $t7, 0x1FFF
        ctx->r24 = ctx->r15 & 0X1FFF;
            goto L_8000AD2C;
    }
    // 0x8000AD24: andi        $t8, $t7, 0x1FFF
    ctx->r24 = ctx->r15 & 0X1FFF;
    // 0x8000AD28: addiu       $v1, $a0, -0x2000
    ctx->r3 = ADD32(ctx->r4, -0X2000);
L_8000AD2C:
    // 0x8000AD2C: bne         $t8, $zero, L_8000AD44
    if (ctx->r24 != 0) {
        // 0x8000AD30: lui         $t0, 0xA450
        ctx->r8 = S32(0XA450 << 16);
            goto L_8000AD44;
    }
    // 0x8000AD30: lui         $t0, 0xA450
    ctx->r8 = S32(0XA450 << 16);
    // 0x8000AD34: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000AD38: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8000AD3C: b           L_8000AD4C
    // 0x8000AD40: sb          $t9, -0x7680($at)
    MEM_B(-0X7680, ctx->r1) = ctx->r25;
        goto L_8000AD4C;
    // 0x8000AD40: sb          $t9, -0x7680($at)
    MEM_B(-0X7680, ctx->r1) = ctx->r25;
L_8000AD44:
    // 0x8000AD44: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8000AD48: sb          $zero, -0x7680($at)
    MEM_B(-0X7680, ctx->r1) = 0;
L_8000AD4C:
    // 0x8000AD4C: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x8000AD50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000AD54: addu        $t2, $v1, $at
    ctx->r10 = ADD32(ctx->r3, ctx->r1);
    // 0x8000AD58: sll         $t1, $v0, 0
    ctx->r9 = S32(ctx->r2 << 0);
    // 0x8000AD5C: bgez        $t1, L_8000AD6C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000AD60: lui         $t3, 0xA450
        ctx->r11 = S32(0XA450 << 16);
            goto L_8000AD6C;
    }
    // 0x8000AD60: lui         $t3, 0xA450
    ctx->r11 = S32(0XA450 << 16);
    // 0x8000AD64: jr          $ra
    // 0x8000AD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8000AD68: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000AD6C:
    // 0x8000AD6C: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x8000AD70: lui         $t4, 0xA450
    ctx->r12 = S32(0XA450 << 16);
    // 0x8000AD74: sw          $a1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r5;
    // 0x8000AD78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000AD7C: jr          $ra
    // 0x8000AD80: nop

    return;
    // 0x8000AD80: nop

    // 0x8000AD84: nop

    // 0x8000AD88: nop

    // 0x8000AD8C: nop

    // 0x8000AD90: nop

    // 0x8000AD94: nop

    // 0x8000AD98: nop

    // 0x8000AD9C: nop

;}
RECOMP_FUNC void func_80043830(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043830: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80043834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80043838: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8004383C: beq         $t7, $zero, L_8004384C
    if (ctx->r15 == 0) {
        // 0x80043840: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8004384C;
    }
    // 0x80043840: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80043844: b           L_8004388C
    // 0x80043848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004388C;
    // 0x80043848: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004384C:
    // 0x8004384C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80043850: lui         $at, 0x1997
    ctx->r1 = S32(0X1997 << 16);
    // 0x80043854: ori         $at, $at, 0x1110
    ctx->r1 = ctx->r1 | 0X1110;
    // 0x80043858: beq         $t8, $at, L_80043874
    if (ctx->r24 == ctx->r1) {
        // 0x8004385C: addiu       $a1, $zero, 0x112
        ctx->r5 = ADD32(0, 0X112);
            goto L_80043874;
    }
    // 0x8004385C: addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // 0x80043860: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80043864: jal         0x80071380
    // 0x80043868: addiu       $a0, $a0, 0x340
    ctx->r4 = ADD32(ctx->r4, 0X340);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80043868: addiu       $a0, $a0, 0x340
    ctx->r4 = ADD32(ctx->r4, 0X340);
    after_0:
    // 0x8004386C: b           L_8004388C
    // 0x80043870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004388C;
    // 0x80043870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80043874:
    // 0x80043874: lbu         $t9, 0x17D($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X17D);
    // 0x80043878: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004387C: beq         $t9, $zero, L_8004388C
    if (ctx->r25 == 0) {
        // 0x80043880: nop
    
            goto L_8004388C;
    }
    // 0x80043880: nop

    // 0x80043884: b           L_8004388C
    // 0x80043888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004388C;
    // 0x80043888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004388C:
    // 0x8004388C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80043890: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80043894: jr          $ra
    // 0x80043898: nop

    return;
    // 0x80043898: nop

;}
RECOMP_FUNC void func_804695D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804695D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804695D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804695D8: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804695DC: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804695E0: lui         $t8, 0x8047
    ctx->r24 = S32(RELOC_HI16(135, 0XE58) << 16);
    // 0x804695E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804695E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804695EC: lw          $t8, -0x6988($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(135, 0XE58));
    // 0x804695F0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804695F4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804695F8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804695FC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80469600: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80469604: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80469608: beql        $v1, $zero, L_8046963C
    if (ctx->r3 == 0) {
        // 0x8046960C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046963C;
    }
    goto skip_0;
    // 0x8046960C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80469610: jalr        $v1
    // 0x80469614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80469614: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80469618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8046961C: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80469620: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80469624: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80469628: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8046962C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80469630: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80469634: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80469638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046963C:
    // 0x8046963C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80469640: jr          $ra
    // 0x80469644: nop

    return;
    // 0x80469644: nop

    // 0x80469648: nop

    // 0x8046964C: nop

;}
RECOMP_FUNC void func_805D2514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2514: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805D2518: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D251C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805D2520: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x805D2524: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805D2528: jal         0x805D1D0C
    // 0x805D252C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_805D1D0C(rdram, ctx);
        goto after_0;
    // 0x805D252C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x805D2530: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x805D2534: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x805D2538: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805D253C: lwc1        $f4, 0x50($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X50);
    // 0x805D2540: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805D2544: swc1        $f8, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f8.u32l;
    // 0x805D2548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D254C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805D2550: jr          $ra
    // 0x805D2554: nop

    return;
    // 0x805D2554: nop

;}
RECOMP_FUNC void func_805ADDE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ADDE4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805ADDE8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805ADDEC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805ADDF0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805ADDF4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805ADDF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805ADDFC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805ADE00: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805ADE04: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805ADE08: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805ADE0C: jr          $ra
    // 0x805ADE10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805ADE10: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804BD82C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD82C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BD830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD834: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41AC) << 16);
    // 0x804BD838: lwc1        $f4, -0x524($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41AC));
    // 0x804BD83C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x804BD840: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x804BD844: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(191, 0X41B0) << 16);
    // 0x804BD848: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804BD84C: lw          $t7, 0x1F4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1F4);
    // 0x804BD850: bc1t        L_804BD8DC
    if (c1cs) {
        // 0x804BD854: lw          $a1, 0x370($t7)
        ctx->r5 = MEM_W(ctx->r15, 0X370);
            goto L_804BD8DC;
    }
    // 0x804BD854: lw          $a1, 0x370($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X370);
    // 0x804BD858: lwc1        $f6, -0x520($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(191, 0X41B0));
    // 0x804BD85C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x804BD860: nop

    // 0x804BD864: bc1tl       L_804BD8E0
    if (c1cs) {
        // 0x804BD868: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD8E0;
    }
    goto skip_0;
    // 0x804BD868: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804BD86C: lh          $t8, 0x2E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2E);
    // 0x804BD870: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804BD874: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804BD878: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x804BD87C: sh          $t9, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r25;
    // 0x804BD880: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
    // 0x804BD884: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x804BD888: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x804BD88C: bnel        $at, $zero, L_804BD8CC
    if (ctx->r1 != 0) {
        // 0x804BD890: sll         $t1, $v0, 1
        ctx->r9 = S32(ctx->r2 << 1);
            goto L_804BD8CC;
    }
    goto skip_1;
    // 0x804BD890: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    skip_1:
    // 0x804BD894: lh          $v1, 0x30($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X30);
    // 0x804BD898: sh          $zero, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = 0;
    // 0x804BD89C: bne         $v1, $zero, L_804BD8C0
    if (ctx->r3 != 0) {
        // 0x804BD8A0: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_804BD8C0;
    }
    // 0x804BD8A0: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x804BD8A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804BD8A8: jal         0x804BD6D8
    // 0x804BD8AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_804BD6D8(rdram, ctx);
        goto after_0;
    // 0x804BD8AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x804BD8B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804BD8B4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804BD8B8: b           L_804BD8C8
    // 0x804BD8BC: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
        goto L_804BD8C8;
    // 0x804BD8BC: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
L_804BD8C0:
    // 0x804BD8C0: sh          $t0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r8;
    // 0x804BD8C4: lh          $v0, 0x2E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2E);
L_804BD8C8:
    // 0x804BD8C8: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
L_804BD8CC:
    // 0x804BD8CC: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X3D94) << 16);
    // 0x804BD8D0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804BD8D4: lh          $t2, -0x93C($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(191, 0X3D94));
    // 0x804BD8D8: sh          $t2, 0x144($a1)
    MEM_H(0X144, ctx->r5) = ctx->r10;
L_804BD8DC:
    // 0x804BD8DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804BD8E0:
    // 0x804BD8E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BD8E4: jr          $ra
    // 0x804BD8E8: nop

    return;
    // 0x804BD8E8: nop

;}
RECOMP_FUNC void func_804C9808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9808: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C980C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C9810: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C9814: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C9818: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C981C: bnel        $a3, $zero, L_804C984C
    if (ctx->r7 != 0) {
        // 0x804C9820: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_804C984C;
    }
    goto skip_0;
    // 0x804C9820: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    skip_0:
    // 0x804C9824: jal         0x80045A34
    // 0x804C9828: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C9828: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x804C982C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x804C9830: bne         $v0, $zero, L_804C9848
    if (ctx->r2 != 0) {
        // 0x804C9834: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_804C9848;
    }
    // 0x804C9834: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x804C9838: jal         0x800445A4
    // 0x804C983C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804C983C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C9840: b           L_804C9884
    // 0x804C9844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C9884;
    // 0x804C9844: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C9848:
    // 0x804C9848: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_804C984C:
    // 0x804C984C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x804C9850: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C9854: jal         0x80065728
    // 0x804C9858: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x804C9858: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x804C985C: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x804C9860: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x804C9864: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x804C9868: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x804C986C: jal         0x80065528
    // 0x804C9870: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    func_80065528(rdram, ctx);
        goto after_3;
    // 0x804C9870: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    after_3:
    // 0x804C9874: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804C9878: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x804C987C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C9880: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
L_804C9884:
    // 0x804C9884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C9888: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C988C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C9890: jr          $ra
    // 0x804C9894: nop

    return;
    // 0x804C9894: nop

;}
RECOMP_FUNC void func_80469834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80469834: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80469838: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8046983C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80469840: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80469844: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80469848: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8046984C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80469850: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80469854: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80469858: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8046985C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80469860: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80469864: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(138, 0X2920) << 16);
    // 0x80469868: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8046986C: lwc1        $f24, -0x3FA0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(138, 0X2920));
    // 0x80469870: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80469874: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80469878: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8046987C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x80469880: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
L_80469884:
    // 0x80469884: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x80469888: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8046988C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80469890: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80469894: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80469898: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x8046989C: jal         0x804697D8
    // 0x804698A0: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    func_804697D8(rdram, ctx);
        goto after_0;
    // 0x804698A0: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    after_0:
    // 0x804698A4: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x804698A8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x804698AC: div.s       $f12, $f18, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f26.fl);
    // 0x804698B0: jal         0x80082730
    // 0x804698B4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    fsin(rdram, ctx);
        goto after_1;
    // 0x804698B4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    after_1:
    // 0x804698B8: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x804698BC: jal         0x8008D250
    // 0x804698C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    fcos(rdram, ctx);
        goto after_2;
    // 0x804698C0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x804698C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x804698C8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x804698CC: bne         $s1, $s3, L_80469884
    if (ctx->r17 != ctx->r19) {
        // 0x804698D0: swc1        $f0, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
            goto L_80469884;
    }
    // 0x804698D0: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x804698D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x804698D8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x804698DC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x804698E0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x804698E4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x804698E8: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x804698EC: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x804698F0: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x804698F4: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x804698F8: jr          $ra
    // 0x804698FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x804698FC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804615A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804615A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804615AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804615B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804615B4: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804615B8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804615BC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x804615C0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x804615C4: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804615C8: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804615CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804615D0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804615D4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x804615D8: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x804615DC: jal         0x80081E8C
    // 0x804615E0: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x804615E0: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x804615E4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804615E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804615EC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A24) << 16);
    // 0x804615F0: lwc1        $f8, 0x3FB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A24));
    // 0x804615F4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804615F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804615FC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80461600: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x80461604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80461608: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8046160C: jr          $ra
    // 0x80461610: nop

    return;
    // 0x80461610: nop

;}
RECOMP_FUNC void func_8079DB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079DB00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079DB04: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8079DB08: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8079DB0C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079DB10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8079DB14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8079DB18: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8079DB1C: addiu       $s2, $zero, 0x60
    ctx->r18 = ADD32(0, 0X60);
L_8079DB20:
    // 0x8079DB20: jal         0x80064E84
    // 0x8079DB24: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8079DB24: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    after_0:
    // 0x8079DB28: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8079DB2C: bne         $s0, $s2, L_8079DB20
    if (ctx->r16 != ctx->r18) {
        // 0x8079DB30: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8079DB20;
    }
    // 0x8079DB30: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8079DB34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8079DB38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079DB3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8079DB40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8079DB44: jr          $ra
    // 0x8079DB48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079DB48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804756F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804756F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804756F4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804756F8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804756FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475700: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475704: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475708: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047570C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475710: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475714: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475718: jr          $ra
    // 0x8047571C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047571C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804CF6B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF6B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x804CF6BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CF6C0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804CF6C4: lw          $t9, 0x180($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X180);
    // 0x804CF6C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x804CF6CC: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x804CF6D0: lwc1        $f16, 0xC4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0XC4);
    // 0x804CF6D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CF6D8: lh          $t8, 0x56($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X56);
    // 0x804CF6DC: lw          $t7, 0x70($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X70);
    // 0x804CF6E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804CF6E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x804CF6E8: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804CF6EC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x804CF6F0: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x804CF6F4: bne         $a0, $t9, L_804CF824
    if (ctx->r4 != ctx->r25) {
        // 0x804CF6F8: addiu       $a0, $sp, 0x24
        ctx->r4 = ADD32(ctx->r29, 0X24);
            goto L_804CF824;
    }
    // 0x804CF6F8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x804CF6FC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x804CF700: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x804CF704: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x804CF708: jal         0x80047AB8
    // 0x804CF70C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_80047AB8(rdram, ctx);
        goto after_0;
    // 0x804CF70C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x804CF710: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x804CF714: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x804CF718: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x804CF71C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804CF720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CF724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CF728: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x804CF72C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x804CF730: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x804CF734: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CF738: div.s       $f2, $f12, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = DIV_S(ctx->f12.fl, ctx->f18.fl);
    // 0x804CF73C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x804CF740: nop

    // 0x804CF744: bc1fl       L_804CF758
    if (!c1cs) {
        // 0x804CF748: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_804CF758;
    }
    goto skip_0;
    // 0x804CF748: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    skip_0:
    // 0x804CF74C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804CF750: nop

    // 0x804CF754: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
L_804CF758:
    // 0x804CF758: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CF75C: nop

    // 0x804CF760: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x804CF764: nop

    // 0x804CF768: bc1f        L_804CF774
    if (!c1cs) {
        // 0x804CF76C: nop
    
            goto L_804CF774;
    }
    // 0x804CF76C: nop

    // 0x804CF770: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_804CF774:
    // 0x804CF774: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x804CF778: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x804CF77C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CF780: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B64) << 16);
    // 0x804CF784: lwc1        $f4, -0x1EC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B64));
    // 0x804CF788: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x804CF78C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804CF790: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x804CF794: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804CF798: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804CF79C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x804CF7A0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B70) << 16);
    // 0x804CF7A4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x804CF7A8: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x804CF7AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804CF7B0: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804CF7B4: nop

    // 0x804CF7B8: mul.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x804CF7BC: nop

    // 0x804CF7C0: mul.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x804CF7C4: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x804CF7C8: nop

    // 0x804CF7CC: bc1f        L_804CF800
    if (!c1cs) {
        // 0x804CF7D0: nop
    
            goto L_804CF800;
    }
    // 0x804CF7D0: nop

    // 0x804CF7D4: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B68) << 16);
    // 0x804CF7D8: lwc1        $f8, -0x1E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B68));
    // 0x804CF7DC: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B6C) << 16);
    // 0x804CF7E0: lwc1        $f10, -0x1E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B6C));
    // 0x804CF7E4: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x804CF7E8: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x804CF7EC: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CF7F0: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x804CF7F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804CF7F8: b           L_804CF824
    // 0x804CF7FC: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
        goto L_804CF824;
    // 0x804CF7FC: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_804CF800:
    // 0x804CF800: lwc1        $f4, -0x1E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B70));
    // 0x804CF804: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(240, 0X1B74) << 16);
    // 0x804CF808: lwc1        $f8, -0x1DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(240, 0X1B74));
    // 0x804CF80C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x804CF810: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804CF814: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x804CF818: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x804CF81C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x804CF820: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_804CF824:
    // 0x804CF824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CF828: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x804CF82C: jr          $ra
    // 0x804CF830: nop

    return;
    // 0x804CF830: nop

;}
RECOMP_FUNC void func_804C8EFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C8EFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C8F00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C8F04: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804C8F08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x804C8F0C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x804C8F10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804C8F14: jal         0x8004700C
    // 0x804C8F18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804C8F18: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C8F1C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x804C8F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C8F24: jal         0x80049F68
    // 0x804C8F28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80049F68(rdram, ctx);
        goto after_1;
    // 0x804C8F28: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x804C8F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C8F30: jal         0x8004E708
    // 0x804C8F34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004E708(rdram, ctx);
        goto after_2;
    // 0x804C8F34: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x804C8F38: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x804C8F3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C8F40: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x804C8F44: beq         $t8, $zero, L_804C8F88
    if (ctx->r24 == 0) {
        // 0x804C8F48: nop
    
            goto L_804C8F88;
    }
    // 0x804C8F48: nop

    // 0x804C8F4C: beq         $s1, $zero, L_804C8F88
    if (ctx->r17 == 0) {
        // 0x804C8F50: nop
    
            goto L_804C8F88;
    }
    // 0x804C8F50: nop

    // 0x804C8F54: lw          $t9, 0x174($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X174);
    // 0x804C8F58: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x804C8F5C: bne         $s0, $t0, L_804C8F88
    if (ctx->r16 != ctx->r8) {
        // 0x804C8F60: nop
    
            goto L_804C8F88;
    }
    // 0x804C8F60: nop

    // 0x804C8F64: jal         0x80061170
    // 0x804C8F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80061170(rdram, ctx);
        goto after_3;
    // 0x804C8F68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x804C8F6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x804C8F70: jal         0x8002FABC
    // 0x804C8F74: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    func_8002FABC(rdram, ctx);
        goto after_4;
    // 0x804C8F74: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x804C8F78: jal         0x804C8E98
    // 0x804C8F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C8E98(rdram, ctx);
        goto after_5;
    // 0x804C8F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804C8F80: b           L_804C8F88
    // 0x804C8F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C8F88;
    // 0x804C8F84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C8F88:
    // 0x804C8F88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804C8F8C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804C8F90: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804C8F94: jr          $ra
    // 0x804C8F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804C8F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_807B3818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B3818: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B381C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B3820: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x807B3824: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(874, 0X1D0) << 16);
    // 0x807B3828: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807B382C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807B3830: addiu       $t6, $t6, 0x39D0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(874, 0X1D0));
    // 0x807B3834: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x807B3838: lhu         $t8, 0xC($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0XC);
    // 0x807B383C: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x807B3840: addiu       $t9, $t8, -0x46FB
    ctx->r25 = ADD32(ctx->r24, -0X46FB);
    // 0x807B3844: sltiu       $at, $t9, 0xA
    ctx->r1 = ctx->r25 < 0XA ? 1 : 0;
    // 0x807B3848: beq         $at, $zero, L_807B397C
    if (ctx->r1 == 0) {
        // 0x807B384C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_807B397C;
    }
    // 0x807B384C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x807B3850: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(874, 0X1F0) << 16);
    // 0x807B3854: addu        $at, $at, $t9
    gpr jr_addend_807B385C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x807B3858: lw          $t9, 0x39F0($at)
    ctx->r25 = ADD32(ctx->r1, (int16_t)RELOC_LO16(874, 0X1F0));
    // 0x807B385C: jr          $t9
    // 0x807B3860: nop

    switch (jr_addend_807B385C >> 2) {
        case 0: goto L_807B3864; break;
        case 1: goto L_807B397C; break;
        case 2: goto L_807B397C; break;
        case 3: goto L_807B38B8; break;
        case 4: goto L_807B3914; break;
        case 5: goto L_807B3920; break;
        case 6: goto L_807B392C; break;
        case 7: goto L_807B393C; break;
        case 8: goto L_807B3954; break;
        case 9: goto L_807B396C; break;
        default: switch_error(__func__, 0x807B385C, 0x807B39F0);
    }
    // 0x807B3860: nop

L_807B3864:
    // 0x807B3864: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807B3868: lbu         $v0, -0x7204($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X7204);
    // 0x807B386C: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807B3870: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B3874: bne         $v0, $zero, L_807B3894
    if (ctx->r2 != 0) {
        // 0x807B3878: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_807B3894;
    }
    // 0x807B3878: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x807B387C: lbu         $t0, -0x7203($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X7203);
    // 0x807B3880: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807B3884: bne         $t0, $at, L_807B3894
    if (ctx->r8 != ctx->r1) {
        // 0x807B3888: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_807B3894;
    }
    // 0x807B3888: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x807B388C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B3890: nop

L_807B3894:
    // 0x807B3894: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x807B3898: bne         $v0, $at, L_807B38A8
    if (ctx->r2 != ctx->r1) {
        // 0x807B389C: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_807B38A8;
    }
    // 0x807B389C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x807B38A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B38A4: nop

L_807B38A8:
    // 0x807B38A8: lwc1        $f4, 0x40($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807B38AC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807B38B0: b           L_807B397C
    // 0x807B38B4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
        goto L_807B397C;
    // 0x807B38B4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
L_807B38B8:
    // 0x807B38B8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x807B38BC: lbu         $v0, -0x7204($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X7204);
    // 0x807B38C0: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x807B38C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B38C8: bne         $v0, $zero, L_807B38E8
    if (ctx->r2 != 0) {
        // 0x807B38CC: lui         $t1, 0x8010
        ctx->r9 = S32(0X8010 << 16);
            goto L_807B38E8;
    }
    // 0x807B38CC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x807B38D0: lbu         $t1, -0x7203($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X7203);
    // 0x807B38D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x807B38D8: bne         $t1, $at, L_807B38E8
    if (ctx->r9 != ctx->r1) {
        // 0x807B38DC: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_807B38E8;
    }
    // 0x807B38DC: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x807B38E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B38E4: nop

L_807B38E8:
    // 0x807B38E8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x807B38EC: bne         $v0, $at, L_807B38FC
    if (ctx->r2 != ctx->r1) {
        // 0x807B38F0: lui         $at, 0xC0A0
        ctx->r1 = S32(0XC0A0 << 16);
            goto L_807B38FC;
    }
    // 0x807B38F0: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x807B38F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B38F8: nop

L_807B38FC:
    // 0x807B38FC: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x807B3900: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807B3904: sw          $t2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r10;
    // 0x807B3908: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x807B390C: b           L_807B397C
    // 0x807B3910: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
        goto L_807B397C;
    // 0x807B3910: swc1        $f10, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f10.u32l;
L_807B3914:
    // 0x807B3914: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x807B3918: b           L_807B397C
    // 0x807B391C: sw          $t3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r11;
        goto L_807B397C;
    // 0x807B391C: sw          $t3, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r11;
L_807B3920:
    // 0x807B3920: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x807B3924: b           L_807B397C
    // 0x807B3928: sw          $t4, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r12;
        goto L_807B397C;
    // 0x807B3928: sw          $t4, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r12;
L_807B392C:
    // 0x807B392C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807B3930: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x807B3934: b           L_807B397C
    // 0x807B3938: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
        goto L_807B397C;
    // 0x807B3938: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
L_807B393C:
    // 0x807B393C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x807B3940: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x807B3944: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x807B3948: sw          $t5, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r13;
    // 0x807B394C: b           L_807B397C
    // 0x807B3950: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
        goto L_807B397C;
    // 0x807B3950: swc1        $f18, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f18.u32l;
L_807B3954:
    // 0x807B3954: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x807B3958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B395C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x807B3960: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x807B3964: b           L_807B397C
    // 0x807B3968: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
        goto L_807B397C;
    // 0x807B3968: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_807B396C:
    // 0x807B396C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x807B3970: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807B3974: nop

    // 0x807B3978: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
L_807B397C:
    // 0x807B397C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B3980: jal         0x807B3998
    // 0x807B3984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_807B3998(rdram, ctx);
        goto after_0;
    // 0x807B3984: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x807B3988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B398C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B3990: jr          $ra
    // 0x807B3994: nop

    return;
    // 0x807B3994: nop

;}
RECOMP_FUNC void func_806753CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806753CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806753D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806753D4: jal         0x80675354
    // 0x806753D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80675354(rdram, ctx);
        goto after_0;
    // 0x806753D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806753DC: beq         $v0, $zero, L_80675460
    if (ctx->r2 == 0) {
        // 0x806753E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80675460;
    }
    // 0x806753E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806753E4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806753E8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806753EC: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(532, 0X620) << 16);
    // 0x806753F0: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806753F4: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806753F8: addiu       $t7, $t7, 0x5570
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(532, 0X620));
    // 0x806753FC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80675400: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80675404: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x80675408: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x8067540C: addiu       $at, $zero, 0x4082
    ctx->r1 = ADD32(0, 0X4082);
    // 0x80675410: sb          $zero, 0x18($a0)
    MEM_B(0X18, ctx->r4) = 0;
    // 0x80675414: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80675418: beq         $v0, $at, L_80675434
    if (ctx->r2 == ctx->r1) {
        // 0x8067541C: sw          $t9, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r25;
            goto L_80675434;
    }
    // 0x8067541C: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x80675420: addiu       $at, $zero, 0x4083
    ctx->r1 = ADD32(0, 0X4083);
    // 0x80675424: beq         $v0, $at, L_80675440
    if (ctx->r2 == ctx->r1) {
        // 0x80675428: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80675440;
    }
    // 0x80675428: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8067542C: b           L_80675444
    // 0x80675430: nop

        goto L_80675444;
    // 0x80675430: nop

L_80675434:
    // 0x80675434: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80675438: b           L_80675444
    // 0x8067543C: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
        goto L_80675444;
    // 0x8067543C: sh          $t0, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r8;
L_80675440:
    // 0x80675440: sh          $t1, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r9;
L_80675444:
    // 0x80675444: jal         0x80675098
    // 0x80675448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80675098(rdram, ctx);
        goto after_1;
    // 0x80675448: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8067544C: jal         0x806754EC
    // 0x80675450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806754EC(rdram, ctx);
        goto after_2;
    // 0x80675450: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80675454: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80675458: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8067545C: sb          $t2, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r10;
L_80675460:
    // 0x80675460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80675464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80675468: jr          $ra
    // 0x8067546C: nop

    return;
    // 0x8067546C: nop

;}
RECOMP_FUNC void func_8069CCF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069CCF0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8069CCF4: addiu       $at, $zero, 0x4591
    ctx->r1 = ADD32(0, 0X4591);
    // 0x8069CCF8: beq         $v0, $at, L_8069CD30
    if (ctx->r2 == ctx->r1) {
        // 0x8069CCFC: addiu       $at, $zero, 0x4592
        ctx->r1 = ADD32(0, 0X4592);
            goto L_8069CD30;
    }
    // 0x8069CCFC: addiu       $at, $zero, 0x4592
    ctx->r1 = ADD32(0, 0X4592);
    // 0x8069CD00: beq         $v0, $at, L_8069CD3C
    if (ctx->r2 == ctx->r1) {
        // 0x8069CD04: addiu       $at, $zero, 0x4593
        ctx->r1 = ADD32(0, 0X4593);
            goto L_8069CD3C;
    }
    // 0x8069CD04: addiu       $at, $zero, 0x4593
    ctx->r1 = ADD32(0, 0X4593);
    // 0x8069CD08: beq         $v0, $at, L_8069CD48
    if (ctx->r2 == ctx->r1) {
        // 0x8069CD0C: addiu       $at, $zero, 0x466E
        ctx->r1 = ADD32(0, 0X466E);
            goto L_8069CD48;
    }
    // 0x8069CD0C: addiu       $at, $zero, 0x466E
    ctx->r1 = ADD32(0, 0X466E);
    // 0x8069CD10: beq         $v0, $at, L_8069CD54
    if (ctx->r2 == ctx->r1) {
        // 0x8069CD14: addiu       $at, $zero, 0x466F
        ctx->r1 = ADD32(0, 0X466F);
            goto L_8069CD54;
    }
    // 0x8069CD14: addiu       $at, $zero, 0x466F
    ctx->r1 = ADD32(0, 0X466F);
    // 0x8069CD18: beq         $v0, $at, L_8069CD60
    if (ctx->r2 == ctx->r1) {
        // 0x8069CD1C: addiu       $at, $zero, 0x4670
        ctx->r1 = ADD32(0, 0X4670);
            goto L_8069CD60;
    }
    // 0x8069CD1C: addiu       $at, $zero, 0x4670
    ctx->r1 = ADD32(0, 0X4670);
    // 0x8069CD20: beq         $v0, $at, L_8069CD6C
    if (ctx->r2 == ctx->r1) {
        // 0x8069CD24: nop
    
            goto L_8069CD6C;
    }
    // 0x8069CD24: nop

    // 0x8069CD28: b           L_8069CD78
    // 0x8069CD2C: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X4F8) << 16);
        goto L_8069CD78;
    // 0x8069CD2C: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X4F8) << 16);
L_8069CD30:
    // 0x8069CD30: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X4F8) << 16);
    // 0x8069CD34: jr          $ra
    // 0x8069CD38: addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X4F8));
    return;
    // 0x8069CD38: addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X4F8));
L_8069CD3C:
    // 0x8069CD3C: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X5A4) << 16);
    // 0x8069CD40: jr          $ra
    // 0x8069CD44: addiu       $v0, $v0, -0x2D6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X5A4));
    return;
    // 0x8069CD44: addiu       $v0, $v0, -0x2D6C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X5A4));
L_8069CD48:
    // 0x8069CD48: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X630) << 16);
    // 0x8069CD4C: jr          $ra
    // 0x8069CD50: addiu       $v0, $v0, -0x2CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X630));
    return;
    // 0x8069CD50: addiu       $v0, $v0, -0x2CE0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X630));
L_8069CD54:
    // 0x8069CD54: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X56C) << 16);
    // 0x8069CD58: jr          $ra
    // 0x8069CD5C: addiu       $v0, $v0, -0x2DA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X56C));
    return;
    // 0x8069CD5C: addiu       $v0, $v0, -0x2DA4
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X56C));
L_8069CD60:
    // 0x8069CD60: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X5F8) << 16);
    // 0x8069CD64: jr          $ra
    // 0x8069CD68: addiu       $v0, $v0, -0x2D18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X5F8));
    return;
    // 0x8069CD68: addiu       $v0, $v0, -0x2D18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X5F8));
L_8069CD6C:
    // 0x8069CD6C: lui         $v0, 0x806A
    ctx->r2 = S32(RELOC_HI16(571, 0X684) << 16);
    // 0x8069CD70: jr          $ra
    // 0x8069CD74: addiu       $v0, $v0, -0x2C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X684));
    return;
    // 0x8069CD74: addiu       $v0, $v0, -0x2C8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X684));
L_8069CD78:
    // 0x8069CD78: addiu       $v0, $v0, -0x2E18
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(571, 0X4F8));
    // 0x8069CD7C: jr          $ra
    // 0x8069CD80: nop

    return;
    // 0x8069CD80: nop

;}
RECOMP_FUNC void func_805E11B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E11B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805E11BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805E11C0: jal         0x800447C8
    // 0x805E11C4: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x805E11C4: nop

    after_0:
    // 0x805E11C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805E11CC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x805E11D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x805E11D4: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x805E11D8: jr          $ra
    // 0x805E11DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x805E11DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806DB5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DB5EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DB5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DB5F4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806DB5F8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806DB5FC: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806DB600: lui         $t8, 0x806E
    ctx->r24 = S32(RELOC_HI16(634, 0X64C) << 16);
    // 0x806DB604: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806DB608: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806DB60C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806DB610: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806DB614: lw          $t8, -0x44F4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(634, 0X64C));
    // 0x806DB618: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806DB61C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806DB620: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DB624: jal         0x80048490
    // 0x806DB628: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806DB628: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806DB62C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806DB630: jal         0x80048378
    // 0x806DB634: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x806DB634: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x806DB638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DB63C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DB640: jr          $ra
    // 0x806DB644: nop

    return;
    // 0x806DB644: nop

;}
RECOMP_FUNC void func_8052F0C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052F0C4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8052F0C8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8052F0CC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8052F0D0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8052F0D4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8052F0D8: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8052F0DC: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8052F0E0: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8052F0E4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8052F0E8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8052F0EC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8052F0F0: lw          $t6, 0x1F4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X1F4);
    // 0x8052F0F4: lw          $s2, 0x1F4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X1F4);
    // 0x8052F0F8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8052F0FC: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x8052F100: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8052F104: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8052F108: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8052F10C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F110: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8052F114: lw          $t9, 0x116C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X116C);
    // 0x8052F118: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8052F11C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8052F120: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8052F124: nop

    // 0x8052F128: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
    // 0x8052F12C: bltzl       $s1, L_8052F624
    if (SIGNED(ctx->r17) < 0) {
        // 0x8052F130: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8052F624;
    }
    goto skip_0;
    // 0x8052F130: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8052F134: lw          $v1, 0x1160($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1160);
    // 0x8052F138: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x8052F13C: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8052F140: beql        $at, $zero, L_8052F624
    if (ctx->r1 == 0) {
        // 0x8052F144: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8052F624;
    }
    goto skip_1;
    // 0x8052F144: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
    // 0x8052F148: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8052F14C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8052F150: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8052F154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052F158: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8052F15C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8052F160: addiu       $s0, $a1, 0xC4
    ctx->r16 = ADD32(ctx->r5, 0XC4);
    // 0x8052F164: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8052F168: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8052F16C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8052F170: nop

    // 0x8052F174: bc1fl       L_8052F624
    if (!c1cs) {
        // 0x8052F178: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8052F624;
    }
    goto skip_2;
    // 0x8052F178: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_2:
    // 0x8052F17C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8052F180: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8052F184: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8052F188: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8052F18C: addiu       $v0, $s1, -0x5
    ctx->r2 = ADD32(ctx->r17, -0X5);
    // 0x8052F190: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8052F194: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8052F198: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8052F19C: bc1f        L_8052F258
    if (!c1cs) {
        // 0x8052F1A0: sqrt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = sqrtf(ctx->f0.fl);
            goto L_8052F258;
    }
    // 0x8052F1A0: sqrt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = sqrtf(ctx->f0.fl);
    // 0x8052F1A4: addiu       $v0, $s1, 0x5
    ctx->r2 = ADD32(ctx->r17, 0X5);
    // 0x8052F1A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8052F1AC: beq         $at, $zero, L_8052F250
    if (ctx->r1 == 0) {
        // 0x8052F1B0: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8052F250;
    }
    // 0x8052F1B0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x8052F1B4: addu        $t2, $s2, $t1
    ctx->r10 = ADD32(ctx->r18, ctx->r9);
    // 0x8052F1B8: lwc1        $f10, 0xF6C($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XF6C);
    // 0x8052F1BC: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8052F1C0: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8052F1C4: addu        $t5, $s2, $t4
    ctx->r13 = ADD32(ctx->r18, ctx->r12);
    // 0x8052F1C8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8052F1CC: lwc1        $f6, 0xF6C($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XF6C);
    // 0x8052F1D0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8052F1D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052F1D8: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8052F1DC: jal         0x80067114
    // 0x8052F1E0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    func_80067114(rdram, ctx);
        goto after_0;
    // 0x8052F1E0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8052F1E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8052F1E8: jal         0x80066E88
    // 0x8052F1EC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8052F1EC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8052F1F0: mul.s       $f20, $f0, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8052F1F4: jal         0x80066DE4
    // 0x8052F1F8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8052F1F8: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x8052F1FC: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8052F200: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8052F204: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8052F208: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8052F20C: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8052F210: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8052F214: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052F218: bc1f        L_8052F224
    if (!c1cs) {
        // 0x8052F21C: nop
    
            goto L_8052F224;
    }
    // 0x8052F21C: nop

    // 0x8052F220: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_8052F224:
    // 0x8052F224: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8052F228: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8052F22C: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8052F230: nop

    // 0x8052F234: bc1f        L_8052F250
    if (!c1cs) {
        // 0x8052F238: nop
    
            goto L_8052F250;
    }
    // 0x8052F238: nop

    // 0x8052F23C: add.s       $f18, $f12, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8052F240: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8052F244: nop

    // 0x8052F248: mul.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f28.fl);
    // 0x8052F24C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_8052F250:
    // 0x8052F250: b           L_8052F30C
    // 0x8052F254: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
        goto L_8052F30C;
    // 0x8052F254: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_8052F258:
    // 0x8052F258: bltz        $v0, L_8052F308
    if (SIGNED(ctx->r2) < 0) {
        // 0x8052F25C: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8052F308;
    }
    // 0x8052F25C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8052F260: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8052F264: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8052F268: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x8052F26C: lwc1        $f6, 0xF6C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XF6C);
    // 0x8052F270: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8052F274: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x8052F278: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x8052F27C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8052F280: lwc1        $f18, 0xF6C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0XF6C);
    // 0x8052F284: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8052F288: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8052F28C: jal         0x80067114
    // 0x8052F290: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    func_80067114(rdram, ctx);
        goto after_3;
    // 0x8052F290: sub.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f18.fl;
    after_3:
    // 0x8052F294: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8052F298: jal         0x80066E88
    // 0x8052F29C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8052F29C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8052F2A0: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8052F2A4: lwc1        $f12, 0x5C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8052F2A8: mul.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8052F2AC: jal         0x80066DE4
    // 0x8052F2B0: nop

    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x8052F2B0: nop

    after_5:
    // 0x8052F2B4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8052F2B8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8052F2BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F2C0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8052F2C4: mul.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8052F2C8: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8052F2CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052F2D0: bc1f        L_8052F2DC
    if (!c1cs) {
        // 0x8052F2D4: nop
    
            goto L_8052F2DC;
    }
    // 0x8052F2D4: nop

    // 0x8052F2D8: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
L_8052F2DC:
    // 0x8052F2DC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8052F2E0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8052F2E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8052F2E8: nop

    // 0x8052F2EC: bc1fl       L_8052F30C
    if (!c1cs) {
        // 0x8052F2F0: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8052F30C;
    }
    goto skip_3;
    // 0x8052F2F0: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    skip_3:
    // 0x8052F2F4: add.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8052F2F8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8052F2FC: nop

    // 0x8052F300: mul.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8052F304: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
L_8052F308:
    // 0x8052F308: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_8052F30C:
    // 0x8052F30C: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8052F310: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8052F314: lwc1        $f6, 0x4($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8052F318: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8052F31C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8052F320: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8052F324: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8052F328: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X243C) << 16);
    // 0x8052F32C: lwc1        $f10, 0x1FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X243C));
    // 0x8052F330: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8052F334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052F338: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8052F33C: mul.s       $f30, $f8, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f30.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8052F340: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8052F344: addiu       $s0, $s1, 0x1
    ctx->r16 = ADD32(ctx->r17, 0X1);
    // 0x8052F348: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2440) << 16);
    // 0x8052F34C: add.s       $f18, $f30, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f30.fl + ctx->f30.fl;
    // 0x8052F350: mul.s       $f6, $f30, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x8052F354: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x8052F358: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8052F35C: div.s       $f30, $f22, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = DIV_S(ctx->f22.fl, ctx->f30.fl);
    // 0x8052F360: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8052F364: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8052F368: nop

    // 0x8052F36C: bc1fl       L_8052F454
    if (!c1cs) {
        // 0x8052F370: lwc1        $f8, 0x64($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
            goto L_8052F454;
    }
    goto skip_4;
    // 0x8052F370: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    skip_4:
    // 0x8052F374: lwc1        $f26, 0x200($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2440));
    // 0x8052F378: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8052F37C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8052F380: nop

L_8052F384:
    // 0x8052F384: mul.s       $f18, $f20, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x8052F388: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8052F38C: mul.s       $f12, $f18, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8052F390: jal         0x80066E88
    // 0x8052F394: nop

    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x8052F394: nop

    after_6:
    // 0x8052F398: bltz        $s1, L_8052F3DC
    if (SIGNED(ctx->r17) < 0) {
        // 0x8052F39C: lwc1        $f16, 0x70($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8052F3DC;
    }
    // 0x8052F39C: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8052F3A0: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8052F3A4: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8052F3A8: addu        $v0, $s2, $t2
    ctx->r2 = ADD32(ctx->r18, ctx->r10);
    // 0x8052F3AC: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F3B0: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8052F3B4: nop

    // 0x8052F3B8: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8052F3BC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8052F3C0: nop

    // 0x8052F3C4: bc1f        L_8052F3DC
    if (!c1cs) {
        // 0x8052F3C8: nop
    
            goto L_8052F3DC;
    }
    // 0x8052F3C8: nop

    // 0x8052F3CC: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8052F3D0: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8052F3D4: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8052F3D8: swc1        $f18, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f18.u32l;
L_8052F3DC:
    // 0x8052F3DC: lw          $t3, 0x1160($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X1160);
    // 0x8052F3E0: slt         $at, $s0, $t3
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8052F3E4: beql        $at, $zero, L_8052F42C
    if (ctx->r1 == 0) {
        // 0x8052F3E8: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8052F42C;
    }
    goto skip_5;
    // 0x8052F3E8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_5:
    // 0x8052F3EC: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8052F3F0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8052F3F4: addu        $v0, $s2, $t4
    ctx->r2 = ADD32(ctx->r18, ctx->r12);
    // 0x8052F3F8: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F3FC: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8052F400: nop

    // 0x8052F404: mul.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8052F408: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8052F40C: nop

    // 0x8052F410: bc1f        L_8052F428
    if (!c1cs) {
        // 0x8052F414: nop
    
            goto L_8052F428;
    }
    // 0x8052F414: nop

    // 0x8052F418: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8052F41C: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x8052F420: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x8052F424: swc1        $f18, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f18.u32l;
L_8052F428:
    // 0x8052F428: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_8052F42C:
    // 0x8052F42C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8052F430: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8052F434: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8052F438: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x8052F43C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8052F440: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x8052F444: nop

    // 0x8052F448: bc1t        L_8052F384
    if (c1cs) {
        // 0x8052F44C: nop
    
            goto L_8052F384;
    }
    // 0x8052F44C: nop

    // 0x8052F450: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
L_8052F454:
    // 0x8052F454: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2444) << 16);
    // 0x8052F458: lwc1        $f26, 0x204($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2444));
    // 0x8052F45C: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x8052F460: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8052F464: bc1f        L_8052F54C
    if (!c1cs) {
        // 0x8052F468: nop
    
            goto L_8052F54C;
    }
    // 0x8052F468: nop

    // 0x8052F46C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8052F470: nop

    // 0x8052F474: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
L_8052F478:
    // 0x8052F478: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x8052F47C: sub.s       $f18, $f20, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x8052F480: mul.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f30.fl);
    // 0x8052F484: nop

    // 0x8052F488: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8052F48C: jal         0x80066E88
    // 0x8052F490: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x8052F490: add.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f24.fl;
    after_7:
    // 0x8052F494: bltz        $s1, L_8052F4D8
    if (SIGNED(ctx->r17) < 0) {
        // 0x8052F498: lwc1        $f16, 0x70($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
            goto L_8052F4D8;
    }
    // 0x8052F498: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8052F49C: add.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8052F4A0: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8052F4A4: addu        $v0, $s2, $t5
    ctx->r2 = ADD32(ctx->r18, ctx->r13);
    // 0x8052F4A8: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F4AC: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8052F4B0: nop

    // 0x8052F4B4: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8052F4B8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8052F4BC: nop

    // 0x8052F4C0: bc1f        L_8052F4D8
    if (!c1cs) {
        // 0x8052F4C4: nop
    
            goto L_8052F4D8;
    }
    // 0x8052F4C4: nop

    // 0x8052F4C8: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8052F4CC: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8052F4D0: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8052F4D4: swc1        $f6, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f6.u32l;
L_8052F4D8:
    // 0x8052F4D8: lw          $t6, 0x1160($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X1160);
    // 0x8052F4DC: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8052F4E0: beql        $at, $zero, L_8052F528
    if (ctx->r1 == 0) {
        // 0x8052F4E4: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8052F528;
    }
    goto skip_6;
    // 0x8052F4E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_6:
    // 0x8052F4E8: add.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x8052F4EC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8052F4F0: addu        $v0, $s2, $t7
    ctx->r2 = ADD32(ctx->r18, ctx->r15);
    // 0x8052F4F4: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F4F8: mul.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f28.fl);
    // 0x8052F4FC: nop

    // 0x8052F500: mul.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8052F504: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8052F508: nop

    // 0x8052F50C: bc1f        L_8052F524
    if (!c1cs) {
        // 0x8052F510: nop
    
            goto L_8052F524;
    }
    // 0x8052F510: nop

    // 0x8052F514: sub.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8052F518: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x8052F51C: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8052F520: swc1        $f6, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f6.u32l;
L_8052F524:
    // 0x8052F524: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_8052F528:
    // 0x8052F528: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8052F52C: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8052F530: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8052F534: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8052F538: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8052F53C: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8052F540: nop

    // 0x8052F544: bc1tl       L_8052F478
    if (c1cs) {
        // 0x8052F548: lwc1        $f10, 0x68($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
            goto L_8052F478;
    }
    goto skip_7;
    // 0x8052F548: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    skip_7:
L_8052F54C:
    // 0x8052F54C: bltz        $s1, L_8052F5B0
    if (SIGNED(ctx->r17) < 0) {
        // 0x8052F550: lui         $at, 0x8053
        ctx->r1 = S32(RELOC_HI16(333, 0X2448) << 16);
            goto L_8052F5B0;
    }
    // 0x8052F550: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X2448) << 16);
    // 0x8052F554: lwc1        $f2, 0x208($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X2448));
    // 0x8052F558: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052F55C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8052F560: nop

    // 0x8052F564: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
L_8052F568:
    // 0x8052F568: addu        $v0, $s2, $t8
    ctx->r2 = ADD32(ctx->r18, ctx->r24);
    // 0x8052F56C: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F570: lwc1        $f18, 0xF70($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XF70);
    // 0x8052F574: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8052F578: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8052F57C: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8052F580: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8052F584: nop

    // 0x8052F588: bc1fl       L_8052F5A8
    if (!c1cs) {
        // 0x8052F58C: addiu       $s1, $zero, -0x1
        ctx->r17 = ADD32(0, -0X1);
            goto L_8052F5A8;
    }
    goto skip_8;
    // 0x8052F58C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    skip_8:
    // 0x8052F590: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8052F594: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8052F598: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8052F59C: b           L_8052F5A8
    // 0x8052F5A0: swc1        $f10, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f10.u32l;
        goto L_8052F5A8;
    // 0x8052F5A0: swc1        $f10, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f10.u32l;
    // 0x8052F5A4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8052F5A8:
    // 0x8052F5A8: bgezl       $s1, L_8052F568
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8052F5AC: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_8052F568;
    }
    goto skip_9;
    // 0x8052F5AC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    skip_9:
L_8052F5B0:
    // 0x8052F5B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8052F5B4: lw          $v1, 0x1160($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1160);
    // 0x8052F5B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8052F5BC: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(333, 0X244C) << 16);
    // 0x8052F5C0: lwc1        $f2, 0x20C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(333, 0X244C));
    // 0x8052F5C4: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8052F5C8: beq         $at, $zero, L_8052F620
    if (ctx->r1 == 0) {
        // 0x8052F5CC: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8052F620;
    }
    // 0x8052F5CC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
L_8052F5D0:
    // 0x8052F5D0: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x8052F5D4: lwc1        $f12, 0xF6C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XF6C);
    // 0x8052F5D8: lwc1        $f18, 0xF68($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XF68);
    // 0x8052F5DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8052F5E0: sub.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8052F5E4: sub.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8052F5E8: c.lt.s      $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f6.fl < ctx->f14.fl;
    // 0x8052F5EC: nop

    // 0x8052F5F0: bc1fl       L_8052F614
    if (!c1cs) {
        // 0x8052F5F4: or          $s0, $v1, $zero
        ctx->r16 = ctx->r3 | 0;
            goto L_8052F614;
    }
    goto skip_10;
    // 0x8052F5F4: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    skip_10:
    // 0x8052F5F8: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8052F5FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8052F600: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8052F604: swc1        $f10, 0xF6C($v0)
    MEM_W(0XF6C, ctx->r2) = ctx->f10.u32l;
    // 0x8052F608: b           L_8052F614
    // 0x8052F60C: lw          $v1, 0x1160($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1160);
        goto L_8052F614;
    // 0x8052F60C: lw          $v1, 0x1160($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X1160);
    // 0x8052F610: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_8052F614:
    // 0x8052F614: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8052F618: bnel        $at, $zero, L_8052F5D0
    if (ctx->r1 != 0) {
        // 0x8052F61C: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_8052F5D0;
    }
    goto skip_11;
    // 0x8052F61C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    skip_11:
L_8052F620:
    // 0x8052F620: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8052F624:
    // 0x8052F624: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8052F628: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8052F62C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8052F630: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8052F634: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8052F638: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8052F63C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8052F640: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8052F644: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8052F648: jr          $ra
    // 0x8052F64C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8052F64C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80535C74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80535C74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80535C78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80535C7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80535C80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80535C84: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80535C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80535C8C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80535C90: lui         $a2, 0x8053
    ctx->r6 = S32(RELOC_HI16(351, 0X1328) << 16);
    // 0x80535C94: lui         $a1, 0x8053
    ctx->r5 = S32(RELOC_HI16(351, 0X133C) << 16);
    // 0x80535C98: addiu       $a1, $a1, 0x6BCC
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(351, 0X133C));
    // 0x80535C9C: addiu       $a2, $a2, 0x6BB8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(351, 0X1328));
    // 0x80535CA0: jal         0x80535958
    // 0x80535CA4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    func_80535958(rdram, ctx);
        goto after_0;
    // 0x80535CA4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_0:
    // 0x80535CA8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80535CAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80535CB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80535CB4: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80535CB8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80535CBC: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80535CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80535CC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80535CC8: jr          $ra
    // 0x80535CCC: nop

    return;
    // 0x80535CCC: nop

;}
RECOMP_FUNC void func_8078DDB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078DDB0: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(805, 0X18) << 16);
    // 0x8078DDB4: addiu       $v0, $v0, -0x2238
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(805, 0X18));
    // 0x8078DDB8: jr          $ra
    // 0x8078DDBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8078DDBC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
