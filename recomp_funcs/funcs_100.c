#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800457A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800457A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800457A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800457A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800457AC: lbu         $v1, 0x164($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X164);
    // 0x800457B0: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    // 0x800457B4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800457B8: bne         $a3, $v1, L_800457D8
    if (ctx->r7 != ctx->r3) {
        // 0x800457BC: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800457D8;
    }
    // 0x800457BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800457C0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800457C4: addiu       $a0, $a0, 0x630
    ctx->r4 = ADD32(ctx->r4, 0X630);
    // 0x800457C8: jal         0x80071380
    // 0x800457CC: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800457CC: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    after_0:
    // 0x800457D0: b           L_800458E0
    // 0x800457D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800458E0;
    // 0x800457D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800457D8:
    // 0x800457D8: bne         $a3, $a1, L_800457F8
    if (ctx->r7 != ctx->r5) {
        // 0x800457DC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800457F8;
    }
    // 0x800457DC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800457E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800457E4: addiu       $a0, $a0, 0x640
    ctx->r4 = ADD32(ctx->r4, 0X640);
    // 0x800457E8: jal         0x80071380
    // 0x800457EC: addiu       $a1, $zero, 0x16B
    ctx->r5 = ADD32(0, 0X16B);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800457EC: addiu       $a1, $zero, 0x16B
    ctx->r5 = ADD32(0, 0X16B);
    after_1:
    // 0x800457F0: b           L_800458E0
    // 0x800457F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800458E0;
    // 0x800457F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800457F8:
    // 0x800457F8: beq         $v1, $zero, L_80045820
    if (ctx->r3 == 0) {
        // 0x800457FC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80045820;
    }
    // 0x800457FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045800: beq         $v1, $at, L_80045820
    if (ctx->r3 == ctx->r1) {
        // 0x80045804: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80045820;
    }
    // 0x80045804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045808: beq         $v1, $at, L_80045820
    if (ctx->r3 == ctx->r1) {
        // 0x8004580C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80045820;
    }
    // 0x8004580C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80045810: beq         $v1, $at, L_80045820
    if (ctx->r3 == ctx->r1) {
        // 0x80045814: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80045820;
    }
    // 0x80045814: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80045818: bne         $v1, $at, L_80045844
    if (ctx->r3 != ctx->r1) {
        // 0x8004581C: nop
    
            goto L_80045844;
    }
    // 0x8004581C: nop

L_80045820:
    // 0x80045820: beq         $v0, $zero, L_8004585C
    if (ctx->r2 == 0) {
        // 0x80045824: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8004585C;
    }
    // 0x80045824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045828: beq         $v0, $at, L_8004585C
    if (ctx->r2 == ctx->r1) {
        // 0x8004582C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004585C;
    }
    // 0x8004582C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045830: beq         $v0, $at, L_8004585C
    if (ctx->r2 == ctx->r1) {
        // 0x80045834: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8004585C;
    }
    // 0x80045834: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80045838: beq         $v0, $at, L_8004585C
    if (ctx->r2 == ctx->r1) {
        // 0x8004583C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8004585C;
    }
    // 0x8004583C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80045840: beq         $v0, $at, L_8004585C
    if (ctx->r2 == ctx->r1) {
        // 0x80045844: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8004585C;
    }
L_80045844:
    // 0x80045844: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045848: addiu       $a0, $a0, 0x650
    ctx->r4 = ADD32(ctx->r4, 0X650);
    // 0x8004584C: jal         0x80071380
    // 0x80045850: addiu       $a1, $zero, 0x175
    ctx->r5 = ADD32(0, 0X175);
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x80045850: addiu       $a1, $zero, 0x175
    ctx->r5 = ADD32(0, 0X175);
    after_2:
    // 0x80045854: b           L_800458E0
    // 0x80045858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800458E0;
    // 0x80045858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004585C:
    // 0x8004585C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80045860: sb          $a1, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r5;
    // 0x80045864: jal         0x8005DAA4
    // 0x80045868: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8005DAA4(rdram, ctx);
        goto after_3;
    // 0x80045868: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x8004586C: lbu         $a1, 0x1F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X1F);
    // 0x80045870: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80045874: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x80045878: jal         0x8005D96C
    // 0x8004587C: sb          $a1, 0x164($a2)
    MEM_B(0X164, ctx->r6) = ctx->r5;
    func_8005D96C(rdram, ctx);
        goto after_4;
    // 0x8004587C: sb          $a1, 0x164($a2)
    MEM_B(0X164, ctx->r6) = ctx->r5;
    after_4:
    // 0x80045880: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80045884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80045888: lw          $t6, 0x16C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X16C);
    // 0x8004588C: sw          $v0, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r2;
    // 0x80045890: lbu         $v1, 0x164($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X164);
    // 0x80045894: bne         $v1, $at, L_800458AC
    if (ctx->r3 != ctx->r1) {
        // 0x80045898: nop
    
            goto L_800458AC;
    }
    // 0x80045898: nop

    // 0x8004589C: lw          $t8, 0x16C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X16C);
    // 0x800458A0: addiu       $t7, $zero, 0x88
    ctx->r15 = ADD32(0, 0X88);
    // 0x800458A4: sb          $t7, 0x30($t8)
    MEM_B(0X30, ctx->r24) = ctx->r15;
    // 0x800458A8: lbu         $v1, 0x164($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X164);
L_800458AC:
    // 0x800458AC: beq         $v1, $zero, L_800458BC
    if (ctx->r3 == 0) {
        // 0x800458B0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800458BC;
    }
    // 0x800458B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800458B4: bnel        $v1, $at, L_800458E0
    if (ctx->r3 != ctx->r1) {
        // 0x800458B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800458E0;
    }
    goto skip_0;
    // 0x800458B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800458BC:
    // 0x800458BC: lw          $t9, 0x16C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X16C);
    // 0x800458C0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800458C4: addiu       $a0, $a0, 0x660
    ctx->r4 = ADD32(ctx->r4, 0X660);
    // 0x800458C8: lw          $t0, 0x30($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X30);
    // 0x800458CC: bnel        $t0, $zero, L_800458E0
    if (ctx->r8 != 0) {
        // 0x800458D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800458E0;
    }
    goto skip_1;
    // 0x800458D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800458D4: jal         0x80071380
    // 0x800458D8: addiu       $a1, $zero, 0x189
    ctx->r5 = ADD32(0, 0X189);
    Fault_HungUp(rdram, ctx);
        goto after_5;
    // 0x800458D8: addiu       $a1, $zero, 0x189
    ctx->r5 = ADD32(0, 0X189);
    after_5:
    // 0x800458DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800458E0:
    // 0x800458E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800458E4: jr          $ra
    // 0x800458E8: nop

    return;
    // 0x800458E8: nop

;}
RECOMP_FUNC void func_8006692C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006692C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066938: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006693C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80066940: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80066944: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80066948: jal         0x80066894
    // 0x8006694C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80066894(rdram, ctx);
        goto after_0;
    // 0x8006694C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x80066950: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80066954: jal         0x80066894
    // 0x80066958: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_80066894(rdram, ctx);
        goto after_1;
    // 0x80066958: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8006695C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80066960: jal         0x80066894
    // 0x80066964: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80066894(rdram, ctx);
        goto after_2;
    // 0x80066964: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x80066968: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8006696C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80066970: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80066974: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80066978: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006697C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80066980: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80066984: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80066988: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006698C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80066990: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80066994: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80066998: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8006699C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800669A0: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800669A4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800669A8: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800669AC: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800669B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800669B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800669B8: jr          $ra
    // 0x800669BC: nop

    return;
    // 0x800669BC: nop

;}
RECOMP_FUNC void func_8069C99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069C99C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8069C9A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8069C9A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8069C9A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8069C9AC: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8069C9B0: lw          $a1, 0x7F78($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7F78);
    // 0x8069C9B4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8069C9B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8069C9BC: andi        $t0, $a1, 0x7
    ctx->r8 = ctx->r5 & 0X7;
    // 0x8069C9C0: beq         $v1, $zero, L_8069CA04
    if (ctx->r3 == 0) {
        // 0x8069C9C4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8069CA04;
    }
    // 0x8069C9C4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8069C9C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069C9CC: bne         $a1, $t6, L_8069CA18
    if (ctx->r5 != ctx->r14) {
        // 0x8069C9D0: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_8069CA18;
    }
    // 0x8069C9D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8069C9D4: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x8069C9D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8069C9DC: sh          $a1, 0x12($t9)
    MEM_H(0X12, ctx->r25) = ctx->r5;
    // 0x8069C9E0: jal         0x8005FCA8
    // 0x8069C9E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8005FCA8(rdram, ctx);
        goto after_0;
    // 0x8069C9E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8069C9E8: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(568, 0X4D0) << 16);
    // 0x8069C9EC: lwc1        $f6, -0x3390($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(568, 0X4D0));
    // 0x8069C9F0: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8069C9F4: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8069C9F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8069C9FC: b           L_8069CA18
    // 0x8069CA00: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
        goto L_8069CA18;
    // 0x8069CA00: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
L_8069CA04:
    // 0x8069CA04: bne         $t0, $zero, L_8069CA18
    if (ctx->r8 != 0) {
        // 0x8069CA08: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8069CA18;
    }
    // 0x8069CA08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8069CA0C: jal         0x8069C7B0
    // 0x8069CA10: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8069C7B0(rdram, ctx);
        goto after_1;
    // 0x8069CA10: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8069CA14: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_8069CA18:
    // 0x8069CA18: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8069CA1C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8069CA20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8069CA24: beq         $v1, $zero, L_8069CA34
    if (ctx->r3 == 0) {
        // 0x8069CA28: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8069CA34;
    }
    // 0x8069CA28: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x8069CA2C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8069CA30: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_8069CA34:
    // 0x8069CA34: bne         $v1, $zero, L_8069CA70
    if (ctx->r3 != 0) {
        // 0x8069CA38: nop
    
            goto L_8069CA70;
    }
    // 0x8069CA38: nop

    // 0x8069CA3C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8069CA40: lui         $t3, 0x806A
    ctx->r11 = S32(RELOC_HI16(568, 0X498) << 16);
    // 0x8069CA44: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8069CA48: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8069CA4C: lw          $t3, -0x33C8($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(568, 0X498));
    // 0x8069CA50: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x8069CA54: slti        $at, $t4, 0x6
    ctx->r1 = SIGNED(ctx->r12) < 0X6 ? 1 : 0;
    // 0x8069CA58: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x8069CA5C: beq         $at, $zero, L_8069CA6C
    if (ctx->r1 == 0) {
        // 0x8069CA60: sw          $t3, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r11;
            goto L_8069CA6C;
    }
    // 0x8069CA60: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8069CA64: b           L_8069CA70
    // 0x8069CA68: sh          $t4, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r12;
        goto L_8069CA70;
    // 0x8069CA68: sh          $t4, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r12;
L_8069CA6C:
    // 0x8069CA6C: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_8069CA70:
    // 0x8069CA70: jal         0x80048F84
    // 0x8069CA74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8069CA74: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8069CA78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8069CA7C: jal         0x80048F84
    // 0x8069CA80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x8069CA80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8069CA84: jal         0x8069C864
    // 0x8069CA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8069C864(rdram, ctx);
        goto after_4;
    // 0x8069CA88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8069CA8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8069CA90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069CA94: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8069CA98: jr          $ra
    // 0x8069CA9C: nop

    return;
    // 0x8069CA9C: nop

;}
RECOMP_FUNC void func_8067C1D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067C1D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8067C1D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067C1DC: lw          $t6, 0x134($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X134);
    // 0x8067C1E0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8067C1E4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067C1E8: bne         $t6, $zero, L_8067C260
    if (ctx->r14 != 0) {
        // 0x8067C1EC: addiu       $t7, $zero, 0x4034
        ctx->r15 = ADD32(0, 0X4034);
            goto L_8067C260;
    }
    // 0x8067C1EC: addiu       $t7, $zero, 0x4034
    ctx->r15 = ADD32(0, 0X4034);
    // 0x8067C1F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8067C1F4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D94) << 16);
    // 0x8067C1F8: lwc1        $f4, -0x25BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D94));
    // 0x8067C1FC: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8067C200: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8067C204: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8067C208: sh          $t7, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r15;
    // 0x8067C20C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067C210: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8067C214: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x8067C218: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8067C21C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8067C220: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8067C224: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8067C228: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8067C22C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8067C230: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8067C234: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8067C238: lw          $t9, 0x54($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X54);
    // 0x8067C23C: jalr        $t9
    // 0x8067C240: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8067C240: nop

    after_0:
    // 0x8067C244: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8067C248: beq         $v0, $zero, L_8067C2EC
    if (ctx->r2 == 0) {
        // 0x8067C24C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_8067C2EC;
    }
    // 0x8067C24C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8067C250: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8067C254: sw          $t1, 0x134($a1)
    MEM_W(0X134, ctx->r5) = ctx->r9;
    // 0x8067C258: b           L_8067C2EC
    // 0x8067C25C: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
        goto L_8067C2EC;
    // 0x8067C25C: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
L_8067C260:
    // 0x8067C260: lh          $t2, 0x184($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X184);
    // 0x8067C264: lui         $a0, 0x8068
    ctx->r4 = S32(RELOC_HI16(541, 0X3D18) << 16);
    // 0x8067C268: beql        $t2, $zero, L_8067C2AC
    if (ctx->r10 == 0) {
        // 0x8067C26C: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_8067C2AC;
    }
    goto skip_0;
    // 0x8067C26C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    skip_0:
    // 0x8067C270: lw          $t3, 0x14C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X14C);
    // 0x8067C274: addiu       $a0, $a0, -0x2638
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(541, 0X3D18));
    // 0x8067C278: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x8067C27C: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8067C280: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8067C284: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8067C288: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8067C28C: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x8067C290: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8067C294: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8067C298: lwc1        $f8, 0x4($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8067C29C: swc1        $f8, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f8.u32l;
    // 0x8067C2A0: b           L_8067C2EC
    // 0x8067C2A4: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
        goto L_8067C2EC;
    // 0x8067C2A4: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x8067C2A8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_8067C2AC:
    // 0x8067C2AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067C2B0: lui         $t9, 0x8068
    ctx->r25 = S32(RELOC_HI16(541, 0X2110) << 16);
    // 0x8067C2B4: addiu       $t0, $zero, 0x6B
    ctx->r8 = ADD32(0, 0X6B);
    // 0x8067C2B8: addiu       $t9, $t9, -0x4240
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(541, 0X2110));
    // 0x8067C2BC: sb          $t0, 0x18($a1)
    MEM_B(0X18, ctx->r5) = ctx->r8;
    // 0x8067C2C0: sw          $t9, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r25;
    // 0x8067C2C4: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(541, 0X3D98) << 16);
    // 0x8067C2C8: swc1        $f10, 0xC8($a1)
    MEM_W(0XC8, ctx->r5) = ctx->f10.u32l;
    // 0x8067C2CC: lwc1        $f16, -0x25B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(541, 0X3D98));
    // 0x8067C2D0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8067C2D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067C2D8: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x8067C2DC: addiu       $t1, $t1, -0x7218
    ctx->r9 = ADD32(ctx->r9, -0X7218);
    // 0x8067C2E0: sw          $t1, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r9;
    // 0x8067C2E4: swc1        $f16, 0xEC($a1)
    MEM_W(0XEC, ctx->r5) = ctx->f16.u32l;
    // 0x8067C2E8: swc1        $f18, 0xE0($a1)
    MEM_W(0XE0, ctx->r5) = ctx->f18.u32l;
L_8067C2EC:
    // 0x8067C2EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067C2F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8067C2F4: jr          $ra
    // 0x8067C2F8: nop

    return;
    // 0x8067C2F8: nop

    // 0x8067C2FC: nop

;}
RECOMP_FUNC void func_80521444(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80521444: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80521448: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052144C: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80521450: lui         $t6, 0x8052
    ctx->r14 = S32(RELOC_HI16(306, 0X1E0) << 16);
    // 0x80521454: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80521458: addiu       $t6, $t6, 0x15A0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(306, 0X1E0));
    // 0x8052145C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80521460: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80521464: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80521468: jal         0x8052154C
    // 0x8052146C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8052154C(rdram, ctx);
        goto after_0;
    // 0x8052146C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80521470: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80521474: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80521478: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8052147C: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x80521480: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80521484: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80521488: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8052148C: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80521490: jr          $ra
    // 0x80521494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80521494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8077FE4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077FE4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8077FE50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8077FE54: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8077FE58: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8077FE5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8077FE60: addiu       $a1, $zero, 0x268
    ctx->r5 = ADD32(0, 0X268);
    // 0x8077FE64: lw          $t7, 0x34($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X34);
    // 0x8077FE68: jal         0x80045A34
    // 0x8077FE6C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8077FE6C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8077FE70: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8077FE74: bne         $v0, $zero, L_8077FE8C
    if (ctx->r2 != 0) {
        // 0x8077FE78: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8077FE8C;
    }
    // 0x8077FE78: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8077FE7C: jal         0x800445A4
    // 0x8077FE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8077FE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8077FE84: b           L_8077FEC8
    // 0x8077FE88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8077FEC8;
    // 0x8077FE88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8077FE8C:
    // 0x8077FE8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8077FE90: addiu       $a1, $zero, 0x268
    ctx->r5 = ADD32(0, 0X268);
    // 0x8077FE94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8077FE98: jal         0x80065728
    // 0x8077FE9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x8077FE9C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_2:
    // 0x8077FEA0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8077FEA4: jal         0x8005D730
    // 0x8077FEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005D730(rdram, ctx);
        goto after_3;
    // 0x8077FEA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8077FEAC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8077FEB0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8077FEB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8077FEB8: sw          $t8, 0x260($a3)
    MEM_W(0X260, ctx->r7) = ctx->r24;
    // 0x8077FEBC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8077FEC0: andi        $t0, $t9, 0x3FF
    ctx->r8 = ctx->r25 & 0X3FF;
    // 0x8077FEC4: sh          $t0, 0x25C($a3)
    MEM_H(0X25C, ctx->r7) = ctx->r8;
L_8077FEC8:
    // 0x8077FEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8077FECC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8077FED0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8077FED4: jr          $ra
    // 0x8077FED8: nop

    return;
    // 0x8077FED8: nop

;}
RECOMP_FUNC void func_800617DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800617DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800617E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800617E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800617E8: jal         0x8004700C
    // 0x800617EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x800617EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800617F0: beq         $v0, $zero, L_80061978
    if (ctx->r2 == 0) {
        // 0x800617F4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80061978;
    }
    // 0x800617F4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800617F8: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x800617FC: lw          $a3, 0x174($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X174);
    // 0x80061800: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80061804: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061808: lh          $t7, 0x56($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X56);
    // 0x8006180C: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x80061810: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80061814: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80061818: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006181C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80061820: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x80061824: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061828: lh          $t9, 0x58($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X58);
    // 0x8006182C: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x80061830: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80061834: lwc1        $f16, 0x4($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80061838: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8006183C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80061840: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x80061844: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061848: lh          $t1, 0x5A($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X5A);
    // 0x8006184C: lw          $t0, 0x70($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X70);
    // 0x80061850: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80061854: lwc1        $f8, 0x8($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80061858: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006185C: mul.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80061860: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
    // 0x80061864: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80061868: jal         0x8005FFB4
    // 0x8006186C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8005FFB4(rdram, ctx);
        goto after_1;
    // 0x8006186C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80061870: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80061874: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80061878: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8006187C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80061880: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x80061884: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x80061888: lh          $t3, 0x52($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X52);
    // 0x8006188C: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x80061890: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80061894: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80061898: lwc1        $f6, 0x4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8006189C: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800618A0: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800618A4: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800618A8: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x800618AC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800618B0: lwc1        $f18, 0x8C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x800618B4: lh          $t5, 0x54($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X54);
    // 0x800618B8: lw          $t4, 0x70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X70);
    // 0x800618BC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800618C0: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800618C4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800618C8: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800618CC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800618D0: beq         $a3, $zero, L_80061978
    if (ctx->r7 == 0) {
        // 0x800618D4: swc1        $f16, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
            goto L_80061978;
    }
    // 0x800618D4: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x800618D8: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800618DC: lbu         $t7, 0x79($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X79);
    // 0x800618E0: beql        $t7, $zero, L_8006197C
    if (ctx->r15 == 0) {
        // 0x800618E4: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_8006197C;
    }
    goto skip_0;
    // 0x800618E4: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x800618E8: sw          $a2, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r6;
    // 0x800618EC: lwc1        $f6, 0xC4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x800618F0: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800618F4: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800618F8: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800618FC: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    // 0x80061900: lwc1        $f8, 0xC8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC8);
    // 0x80061904: sub.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80061908: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x8006190C: lwc1        $f16, 0xC8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC8);
    // 0x80061910: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80061914: nop

    // 0x80061918: bc1fl       L_8006197C
    if (!c1cs) {
        // 0x8006191C: lw          $t6, 0x4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X4);
            goto L_8006197C;
    }
    goto skip_1;
    // 0x8006191C: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x80061920: lw          $t9, 0x174($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X174);
    // 0x80061924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80061928: sw          $t9, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r25;
    // 0x8006192C: jal         0x80060274
    // 0x80061930: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_80060274(rdram, ctx);
        goto after_2;
    // 0x80061930: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x80061934: beq         $v0, $zero, L_80061978
    if (ctx->r2 == 0) {
        // 0x80061938: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_80061978;
    }
    // 0x80061938: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8006193C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x80061940: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80061944: andi        $t2, $t1, 0xF00
    ctx->r10 = ctx->r9 & 0XF00;
    // 0x80061948: bnel        $t2, $zero, L_8006196C
    if (ctx->r10 != 0) {
        // 0x8006194C: lw          $v0, 0x1F4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1F4);
            goto L_8006196C;
    }
    goto skip_2;
    // 0x8006194C: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    skip_2:
    // 0x80061950: jal         0x80060ED0
    // 0x80061954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060ED0(rdram, ctx);
        goto after_3;
    // 0x80061954: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80061958: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8006195C: lw          $t3, 0x3C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X3C);
    // 0x80061960: b           L_80061978
    // 0x80061964: swc1        $f6, 0x120($t3)
    MEM_W(0X120, ctx->r11) = ctx->f6.u32l;
        goto L_80061978;
    // 0x80061964: swc1        $f6, 0x120($t3)
    MEM_W(0X120, ctx->r11) = ctx->f6.u32l;
    // 0x80061968: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
L_8006196C:
    // 0x8006196C: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x80061970: ori         $t5, $t4, 0x700
    ctx->r13 = ctx->r12 | 0X700;
    // 0x80061974: sw          $t5, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r13;
L_80061978:
    // 0x80061978: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
L_8006197C:
    // 0x8006197C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80061980: lh          $t7, 0x184($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X184);
    // 0x80061984: beql        $t7, $zero, L_800619AC
    if (ctx->r15 == 0) {
        // 0x80061988: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800619AC;
    }
    goto skip_3;
    // 0x80061988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8006198C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80061990: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061994: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80061998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006199C: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800619A0: jalr        $t9
    // 0x800619A4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800619A4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x800619A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800619AC:
    // 0x800619AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800619B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800619B4: jr          $ra
    // 0x800619B8: nop

    return;
    // 0x800619B8: nop

;}
RECOMP_FUNC void func_80558794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558794: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8055879C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805587A0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805587A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805587A8: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805587AC: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x805587B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805587B4: jal         0x80048F84
    // 0x805587B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x805587B8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x805587BC: jal         0x805580E8
    // 0x805587C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x805587C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805587C4: jal         0x805582E0
    // 0x805587C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x805587C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805587CC: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x805587D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805587D4: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x805587D8: bne         $at, $zero, L_8055881C
    if (ctx->r1 != 0) {
        // 0x805587DC: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_8055881C;
    }
    // 0x805587DC: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x805587E0: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x805587E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x805587E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805587EC: lw          $t0, 0x24($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X24);
    // 0x805587F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805587F4: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x805587F8: beq         $at, $zero, L_80558814
    if (ctx->r1 == 0) {
        // 0x805587FC: nop
    
            goto L_80558814;
    }
    // 0x805587FC: nop

    // 0x80558800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558804: jal         0x80559928
    // 0x80558808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80558808: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8055880C: b           L_80558820
    // 0x80558810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80558820;
    // 0x80558810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558814:
    // 0x80558814: jal         0x80559928
    // 0x80558818: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x80558818: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
L_8055881C:
    // 0x8055881C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80558820:
    // 0x80558820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558824: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558828: jr          $ra
    // 0x8055882C: nop

    return;
    // 0x8055882C: nop

;}
RECOMP_FUNC void func_806F1AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F1ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F1AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F1AD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F1AD8: jal         0x80062684
    // 0x806F1ADC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x806F1ADC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x806F1AE0: jal         0x806F16CC
    // 0x806F1AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F16CC(rdram, ctx);
        goto after_1;
    // 0x806F1AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F1AE8: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x806F1AEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F1AF0: blez        $v0, L_806F1B04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x806F1AF4: swc1        $f4, 0xC8($s0)
        MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
            goto L_806F1B04;
    }
    // 0x806F1AF4: swc1        $f4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f4.u32l;
    // 0x806F1AF8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x806F1AFC: b           L_806F1B58
    // 0x806F1B00: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
        goto L_806F1B58;
    // 0x806F1B00: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_806F1B04:
    // 0x806F1B04: jal         0x806F1644
    // 0x806F1B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F1644(rdram, ctx);
        goto after_2;
    // 0x806F1B08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806F1B0C: jal         0x8004700C
    // 0x806F1B10: nop

    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x806F1B10: nop

    after_3:
    // 0x806F1B14: beq         $v0, $zero, L_806F1B30
    if (ctx->r2 == 0) {
        // 0x806F1B18: nop
    
            goto L_806F1B30;
    }
    // 0x806F1B18: nop

    // 0x806F1B1C: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x806F1B20: bne         $s0, $t7, L_806F1B30
    if (ctx->r16 != ctx->r15) {
        // 0x806F1B24: nop
    
            goto L_806F1B30;
    }
    // 0x806F1B24: nop

    // 0x806F1B28: jal         0x80060FE0
    // 0x806F1B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80060FE0(rdram, ctx);
        goto after_4;
    // 0x806F1B2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_806F1B30:
    // 0x806F1B30: jal         0x8005FE48
    // 0x806F1B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x806F1B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806F1B38: addiu       $t8, $zero, 0x4B0
    ctx->r24 = ADD32(0, 0X4B0);
    // 0x806F1B3C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x806F1B40: sw          $t8, -0x6C78($at)
    MEM_W(-0X6C78, ctx->r1) = ctx->r24;
    // 0x806F1B44: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x806F1B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1B50: jal         0x806F1F14
    // 0x806F1B54: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_806F1F14(rdram, ctx);
        goto after_6;
    // 0x806F1B54: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_6:
L_806F1B58:
    // 0x806F1B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F1B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1B60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1B64: jr          $ra
    // 0x806F1B68: nop

    return;
    // 0x806F1B68: nop

;}
RECOMP_FUNC void func_80434000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80434000: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80434004: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80434008: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8043400C: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80434010: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80434014: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80434018: addiu       $a1, $zero, 0x77
    ctx->r5 = ADD32(0, 0X77);
    // 0x8043401C: addiu       $v1, $v0, 0x7AC
    ctx->r3 = ADD32(ctx->r2, 0X7AC);
L_80434020:
    // 0x80434020: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80434024: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80434028: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8043402C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80434030: addiu       $v1, $v1, 0x0
    ctx->r3 = ADD32(ctx->r3, 0X0);
    // 0x80434034: bc1fl       L_80434048
    if (!c1cs) {
        // 0x80434038: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_80434048;
    }
    goto skip_0;
    // 0x80434038: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_0:
    // 0x8043403C: b           L_80434058
    // 0x80434040: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_80434058;
    // 0x80434040: sub.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80434044: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_80434048:
    // 0x80434048: nop

    // 0x8043404C: bc1fl       L_8043405C
    if (!c1cs) {
        // 0x80434050: c.lt.s      $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
            goto L_8043405C;
    }
    goto skip_1;
    // 0x80434050: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    skip_1:
    // 0x80434054: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
L_80434058:
    // 0x80434058: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
L_8043405C:
    // 0x8043405C: nop

    // 0x80434060: bc1fl       L_80434074
    if (!c1cs) {
        // 0x80434064: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_80434074;
    }
    goto skip_2;
    // 0x80434064: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_2:
    // 0x80434068: b           L_80434084
    // 0x8043406C: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
        goto L_80434084;
    // 0x8043406C: sub.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80434070: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_80434074:
    // 0x80434074: nop

    // 0x80434078: bc1fl       L_80434088
    if (!c1cs) {
        // 0x8043407C: swc1        $f0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
            goto L_80434088;
    }
    goto skip_3;
    // 0x8043407C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    skip_3:
    // 0x80434080: add.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f14.fl;
L_80434084:
    // 0x80434084: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
L_80434088:
    // 0x80434088: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x8043408C: bgez        $a1, L_80434020
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80434090: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80434020;
    }
    // 0x80434090: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80434094: jr          $ra
    // 0x80434098: nop

    return;
    // 0x80434098: nop

;}
RECOMP_FUNC void func_804C3D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C3D3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C3D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C3D44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C3D48: jal         0x80045A34
    // 0x804C3D4C: addiu       $a1, $zero, 0x910
    ctx->r5 = ADD32(0, 0X910);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C3D4C: addiu       $a1, $zero, 0x910
    ctx->r5 = ADD32(0, 0X910);
    after_0:
    // 0x804C3D50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C3D54: bne         $v0, $zero, L_804C3D64
    if (ctx->r2 != 0) {
        // 0x804C3D58: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C3D64;
    }
    // 0x804C3D58: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C3D5C: b           L_804C3D70
    // 0x804C3D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C3D70;
    // 0x804C3D60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C3D64:
    // 0x804C3D64: jal         0x804C3CE4
    // 0x804C3D68: nop

    func_804C3CE4(rdram, ctx);
        goto after_1;
    // 0x804C3D68: nop

    after_1:
    // 0x804C3D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C3D70:
    // 0x804C3D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C3D74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C3D78: jr          $ra
    // 0x804C3D7C: nop

    return;
    // 0x804C3D7C: nop

;}
RECOMP_FUNC void func_80742308(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742308: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8074230C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742310: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80742314: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80742318: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8074231C: jal         0x80066DE4
    // 0x80742320: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x80742320: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80742324: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80742328: jal         0x80066E88
    // 0x8074232C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x8074232C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80742330: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80742334: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80742338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8074233C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80742340: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80742344: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80742348: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8074234C: jr          $ra
    // 0x80742350: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    return;
    // 0x80742350: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
;}
RECOMP_FUNC void func_80553EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80553EB0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80553EB4: lui         $t6, 0x8055
    ctx->r14 = S32(RELOC_HI16(354, 0X40D0) << 16);
    // 0x80553EB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80553EBC: addiu       $t6, $t6, 0x4BF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(354, 0X40D0));
    // 0x80553EC0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80553EC4: addiu       $v1, $sp, 0x64
    ctx->r3 = ADD32(ctx->r29, 0X64);
    // 0x80553EC8: lui         $t0, 0x8055
    ctx->r8 = S32(RELOC_HI16(354, 0X40DC) << 16);
    // 0x80553ECC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80553ED0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80553ED4: addiu       $t0, $t0, 0x4BFC
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(354, 0X40DC));
    // 0x80553ED8: addiu       $t3, $t0, 0x3C
    ctx->r11 = ADD32(ctx->r8, 0X3C);
    // 0x80553EDC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80553EE0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80553EE4: addiu       $t9, $sp, 0x24
    ctx->r25 = ADD32(ctx->r29, 0X24);
    // 0x80553EE8: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
L_80553EEC:
    // 0x80553EEC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80553EF0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80553EF4: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80553EF8: sw          $t2, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r10;
    // 0x80553EFC: lw          $t1, -0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, -0X8);
    // 0x80553F00: sw          $t1, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r9;
    // 0x80553F04: lw          $t2, -0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, -0X4);
    // 0x80553F08: bne         $t0, $t3, L_80553EEC
    if (ctx->r8 != ctx->r11) {
        // 0x80553F0C: sw          $t2, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r10;
            goto L_80553EEC;
    }
    // 0x80553F0C: sw          $t2, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r10;
    // 0x80553F10: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80553F14: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80553F18: jal         0x80553E4C
    // 0x80553F1C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    func_80553E4C(rdram, ctx);
        goto after_0;
    // 0x80553F1C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_0:
    // 0x80553F20: addiu       $v1, $sp, 0x64
    ctx->r3 = ADD32(ctx->r29, 0X64);
    // 0x80553F24: beq         $v0, $zero, L_80553F50
    if (ctx->r2 == 0) {
        // 0x80553F28: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_80553F50;
    }
    // 0x80553F28: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80553F2C: jal         0x800653D8
    // 0x80553F30: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    func_800653D8(rdram, ctx);
        goto after_1;
    // 0x80553F30: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    after_1:
    // 0x80553F34: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x80553F38: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80553F3C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x80553F40: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80553F44: lw          $t6, 0x24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24);
    // 0x80553F48: addiu       $v1, $sp, 0x64
    ctx->r3 = ADD32(ctx->r29, 0X64);
    // 0x80553F4C: sw          $t6, 0xDD8($a0)
    MEM_W(0XDD8, ctx->r4) = ctx->r14;
L_80553F50:
    // 0x80553F50: lw          $v0, 0xDD8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XDD8);
    // 0x80553F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80553F58: beq         $v0, $at, L_80553F78
    if (ctx->r2 == ctx->r1) {
        // 0x80553F5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80553F78;
    }
    // 0x80553F5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80553F60: beq         $v0, $at, L_80553F94
    if (ctx->r2 == ctx->r1) {
        // 0x80553F64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80553F94;
    }
    // 0x80553F64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80553F68: beql        $v0, $at, L_80553FB4
    if (ctx->r2 == ctx->r1) {
        // 0x80553F6C: lw          $t7, 0xDE0($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XDE0);
            goto L_80553FB4;
    }
    goto skip_0;
    // 0x80553F6C: lw          $t7, 0xDE0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XDE0);
    skip_0:
    // 0x80553F70: b           L_80553FE4
    // 0x80553F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80553FE4;
    // 0x80553F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80553F78:
    // 0x80553F78: lw          $t7, 0xDE0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XDE0);
    // 0x80553F7C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80553F80: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80553F84: addu        $t3, $v1, $t8
    ctx->r11 = ADD32(ctx->r3, ctx->r24);
    // 0x80553F88: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x80553F8C: b           L_80553FE0
    // 0x80553F90: sh          $t0, 0x144($t9)
    MEM_H(0X144, ctx->r25) = ctx->r8;
        goto L_80553FE0;
    // 0x80553F90: sh          $t0, 0x144($t9)
    MEM_H(0X144, ctx->r25) = ctx->r8;
L_80553F94:
    // 0x80553F94: lw          $t1, 0xDE0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XDE0);
    // 0x80553F98: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80553F9C: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80553FA0: addu        $t4, $v1, $t2
    ctx->r12 = ADD32(ctx->r3, ctx->r10);
    // 0x80553FA4: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80553FA8: b           L_80553FE0
    // 0x80553FAC: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
        goto L_80553FE0;
    // 0x80553FAC: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
    // 0x80553FB0: lw          $t7, 0xDE0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XDE0);
L_80553FB4:
    // 0x80553FB4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80553FB8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80553FBC: addu        $t3, $v1, $t8
    ctx->r11 = ADD32(ctx->r3, ctx->r24);
    // 0x80553FC0: lh          $t0, 0x0($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X0);
    // 0x80553FC4: sh          $t0, 0x144($t9)
    MEM_H(0X144, ctx->r25) = ctx->r8;
    // 0x80553FC8: lw          $t1, 0xDE0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XDE0);
    // 0x80553FCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80553FD0: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80553FD4: addu        $t4, $v1, $t2
    ctx->r12 = ADD32(ctx->r3, ctx->r10);
    // 0x80553FD8: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80553FDC: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
L_80553FE0:
    // 0x80553FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80553FE4:
    // 0x80553FE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80553FE8: jr          $ra
    // 0x80553FEC: nop

    return;
    // 0x80553FEC: nop

;}
RECOMP_FUNC void func_8004FEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004FEC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004FECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004FED0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8004FED4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8004FED8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8004FEDC: lw          $v0, 0x1B8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004FEE0: lw          $v1, 0x1AC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1AC);
    // 0x8004FEE4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8004FEE8: beq         $v0, $zero, L_80050038
    if (ctx->r2 == 0) {
        // 0x8004FEEC: lw          $a1, 0x34($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X34);
            goto L_80050038;
    }
    // 0x8004FEEC: lw          $a1, 0x34($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X34);
    // 0x8004FEF0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004FEF4: beq         $a1, $zero, L_8004FF04
    if (ctx->r5 == 0) {
        // 0x8004FEF8: nop
    
            goto L_8004FF04;
    }
    // 0x8004FEF8: nop

    // 0x8004FEFC: lbu         $t6, 0xC($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XC);
    // 0x8004FF00: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
L_8004FF04:
    // 0x8004FF04: beq         $a1, $zero, L_8004FFB0
    if (ctx->r5 == 0) {
        // 0x8004FF08: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8004FFB0;
    }
    // 0x8004FF08: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8004FF0C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004FF10: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8004FF14: jal         0x80081C64
    // 0x8004FF18: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8004FF18: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8004FF1C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8004FF20: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8004FF24: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004FF28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004FF2C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004FF30: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004FF34: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8004FF38: div.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8004FF3C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8004FF40: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x8004FF44: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8004FF48: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8004FF4C: nop

    // 0x8004FF50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004FF54: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8004FF58: div.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8004FF5C: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8004FF60: jal         0x80081C64
    // 0x8004FF64: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    Math_FFloorF(rdram, ctx);
        goto after_1;
    // 0x8004FF64: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8004FF68: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8004FF6C: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x8004FF70: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004FF74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004FF78: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8004FF7C: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004FF80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8004FF84: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004FF88: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8004FF8C: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x8004FF90: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8004FF94: sub.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8004FF98: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8004FF9C: nop

    // 0x8004FFA0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004FFA4: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8004FFA8: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8004FFAC: div.s       $f2, $f10, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
L_8004FFB0:
    // 0x8004FFB0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004FFB4: lwc1        $f8, 0x34($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X34);
    // 0x8004FFB8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004FFBC: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x8004FFC0: lwc1        $f18, 0x38($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X38);
    // 0x8004FFC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8004FFC8: mul.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8004FFCC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004FFD0: sub.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8004FFD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004FFD8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004FFDC: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004FFE0: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004FFE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004FFE8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8004FFEC: nop

    // 0x8004FFF0: sra         $t2, $t0, 4
    ctx->r10 = S32(SIGNED(ctx->r8) >> 4);
    // 0x8004FFF4: trunc.w.s   $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004FFF8: sll         $t3, $t2, 20
    ctx->r11 = S32(ctx->r10 << 20);
    // 0x8004FFFC: sra         $t4, $t3, 16
    ctx->r12 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80050000: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80050004: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80050008: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005000C: sra         $t8, $t6, 4
    ctx->r24 = S32(SIGNED(ctx->r14) >> 4);
    // 0x80050010: sll         $t9, $t8, 20
    ctx->r25 = S32(ctx->r24 << 20);
    // 0x80050014: sra         $t0, $t9, 16
    ctx->r8 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80050018: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8005001C: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80050020: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80050024: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x80050028: add.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8005002C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80050030: jal         0x8004F44C
    // 0x80050034: nop

    func_8004F44C(rdram, ctx);
        goto after_2;
    // 0x80050034: nop

    after_2:
L_80050038:
    // 0x80050038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005003C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80050040: jr          $ra
    // 0x80050044: nop

    return;
    // 0x80050044: nop

;}
RECOMP_FUNC void func_8004D11C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D11C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004D120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004D124: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004D128: jal         0x8004C834
    // 0x8004D12C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_8004C834(rdram, ctx);
        goto after_0;
    // 0x8004D12C: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x8004D130: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8004D134: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D138: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8004D13C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8004D140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004D144: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004D148: jr          $ra
    // 0x8004D14C: nop

    return;
    // 0x8004D14C: nop

;}
RECOMP_FUNC void func_80556544(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80556544: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80556548: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8055654C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80556550: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80556554: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80556558: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8055655C: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80556560: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80556564: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80556568: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8055656C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80556570: jal         0x80556158
    // 0x80556574: nop

    func_80556158(rdram, ctx);
        goto after_0;
    // 0x80556574: nop

    after_0:
    // 0x80556578: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8055657C: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80556580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80556584: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x80556588: nop

    // 0x8055658C: bc1f        L_805565A8
    if (!c1cs) {
        // 0x80556590: nop
    
            goto L_805565A8;
    }
    // 0x80556590: nop

    // 0x80556594: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80556598: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8055659C: nop

    // 0x805565A0: bc1tl       L_805565B4
    if (c1cs) {
        // 0x805565A4: addiu       $a0, $s0, 0xC4
        ctx->r4 = ADD32(ctx->r16, 0XC4);
            goto L_805565B4;
    }
    goto skip_0;
    // 0x805565A4: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    skip_0:
L_805565A8:
    // 0x805565A8: jal         0x805564FC
    // 0x805565AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_805564FC(rdram, ctx);
        goto after_1;
    // 0x805565AC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805565B0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
L_805565B4:
    // 0x805565B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805565B8: jal         0x80048F84
    // 0x805565BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x805565BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x805565C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805565C4: jal         0x80048F84
    // 0x805565C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805565C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x805565CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805565D0: jal         0x80554F80
    // 0x805565D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_80554F80(rdram, ctx);
        goto after_4;
    // 0x805565D4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x805565D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805565DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805565E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805565E4: jr          $ra
    // 0x805565E8: nop

    return;
    // 0x805565E8: nop

;}
RECOMP_FUNC void func_80446948(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80446948: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044694C: addiu       $t6, $zero, 0x744
    ctx->r14 = ADD32(0, 0X744);
    // 0x80446950: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80446954: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80446958: sw          $t6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r14;
    // 0x8044695C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80446960: jr          $ra
    // 0x80446964: sw          $t7, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r15;
    return;
    // 0x80446964: sw          $t7, 0x6CBC($at)
    MEM_W(0X6CBC, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_80451C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80451C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80451C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80451C84: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80451C88: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80451C8C: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80451C90: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140E0) << 16);
    // 0x80451C94: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80451C98: nop

    // 0x80451C9C: bc1f        L_80451CC8
    if (!c1cs) {
        // 0x80451CA0: nop
    
            goto L_80451CC8;
    }
    // 0x80451CA0: nop

    // 0x80451CA4: jal         0x80451AC8
    // 0x80451CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80451AC8(rdram, ctx);
        goto after_0;
    // 0x80451CA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80451CAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80451CB0: jal         0x80450B18
    // 0x80451CB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80450B18(rdram, ctx);
        goto after_1;
    // 0x80451CB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80451CB8: jal         0x80445A34
    // 0x80451CBC: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x80451CBC: nop

    after_2:
    // 0x80451CC0: b           L_80451E58
    // 0x80451CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80451E58;
    // 0x80451CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451CC8:
    // 0x80451CC8: lwc1        $f6, -0x7B40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140E0));
    // 0x80451CCC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140E4) << 16);
    // 0x80451CD0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80451CD4: nop

    // 0x80451CD8: bc1f        L_80451D04
    if (!c1cs) {
        // 0x80451CDC: nop
    
            goto L_80451D04;
    }
    // 0x80451CDC: nop

    // 0x80451CE0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451CE4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451CE8: beql        $t6, $zero, L_80451E58
    if (ctx->r14 == 0) {
        // 0x80451CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_0;
    // 0x80451CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80451CF0: jal         0x80450B18
    // 0x80451CF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451CF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80451CF8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451CFC: b           L_80451E54
    // 0x80451D00: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80451E54;
    // 0x80451D00: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80451D04:
    // 0x80451D04: lwc1        $f8, -0x7B3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140E4));
    // 0x80451D08: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140E8) << 16);
    // 0x80451D0C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451D10: nop

    // 0x80451D14: bc1f        L_80451D48
    if (!c1cs) {
        // 0x80451D18: nop
    
            goto L_80451D48;
    }
    // 0x80451D18: nop

    // 0x80451D1C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80451D20: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80451D24: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451D28: beql        $t7, $at, L_80451E58
    if (ctx->r15 == ctx->r1) {
        // 0x80451D2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_1;
    // 0x80451D2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80451D30: jal         0x80450B18
    // 0x80451D34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80451D34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80451D38: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451D3C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80451D40: b           L_80451E54
    // 0x80451D44: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_80451E54;
    // 0x80451D44: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80451D48:
    // 0x80451D48: lwc1        $f10, -0x7B38($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140E8));
    // 0x80451D4C: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x80451D50: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80451D54: nop

    // 0x80451D58: bc1fl       L_80451D90
    if (!c1cs) {
        // 0x80451D5C: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80451D90;
    }
    goto skip_2;
    // 0x80451D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_2:
    // 0x80451D60: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80451D64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80451D68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451D6C: beql        $t9, $at, L_80451E58
    if (ctx->r25 == ctx->r1) {
        // 0x80451D70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_3;
    // 0x80451D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80451D74: jal         0x80450B18
    // 0x80451D78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x80451D78: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x80451D7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451D80: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80451D84: b           L_80451E54
    // 0x80451D88: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80451E54;
    // 0x80451D88: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80451D8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80451D90:
    // 0x80451D90: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80451D94: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x80451D98: nop

    // 0x80451D9C: bc1fl       L_80451DD4
    if (!c1cs) {
        // 0x80451DA0: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80451DD4;
    }
    goto skip_4;
    // 0x80451DA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x80451DA4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80451DA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80451DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451DB0: beql        $t1, $at, L_80451E58
    if (ctx->r9 == ctx->r1) {
        // 0x80451DB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_5;
    // 0x80451DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80451DB8: jal         0x80450B18
    // 0x80451DBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x80451DBC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80451DC0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451DC4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80451DC8: b           L_80451E54
    // 0x80451DCC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_80451E54;
    // 0x80451DCC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80451DD0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80451DD4:
    // 0x80451DD4: nop

    // 0x80451DD8: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x80451DDC: nop

    // 0x80451DE0: bc1fl       L_80451E18
    if (!c1cs) {
        // 0x80451DE4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80451E18;
    }
    goto skip_6;
    // 0x80451DE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_6:
    // 0x80451DE8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80451DEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80451DF0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451DF4: beql        $t3, $at, L_80451E58
    if (ctx->r11 == ctx->r1) {
        // 0x80451DF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_7;
    // 0x80451DF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80451DFC: jal         0x80450B18
    // 0x80451E00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x80451E00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x80451E04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451E08: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80451E0C: b           L_80451E54
    // 0x80451E10: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
        goto L_80451E54;
    // 0x80451E10: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x80451E14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80451E18:
    // 0x80451E18: nop

    // 0x80451E1C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80451E20: nop

    // 0x80451E24: bc1fl       L_80451E58
    if (!c1cs) {
        // 0x80451E28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_8;
    // 0x80451E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80451E2C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80451E30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80451E34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80451E38: beql        $t5, $at, L_80451E58
    if (ctx->r13 == ctx->r1) {
        // 0x80451E3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80451E58;
    }
    goto skip_9;
    // 0x80451E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80451E40: jal         0x80450B18
    // 0x80451E44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_8;
    // 0x80451E44: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x80451E48: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451E4C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80451E50: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
L_80451E54:
    // 0x80451E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451E58:
    // 0x80451E58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80451E5C: jr          $ra
    // 0x80451E60: nop

    return;
    // 0x80451E60: nop

;}
RECOMP_FUNC void func_80057640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005764C: jal         0x80058958
    // 0x80057650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80058958(rdram, ctx);
        goto after_0;
    // 0x80057650: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80057654: bne         $v0, $zero, L_80057664
    if (ctx->r2 != 0) {
        // 0x80057658: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80057664;
    }
    // 0x80057658: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005765C: b           L_800576BC
    // 0x80057660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800576BC;
    // 0x80057660: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057664:
    // 0x80057664: jal         0x800575B4
    // 0x80057668: addiu       $a1, $zero, 0x405F
    ctx->r5 = ADD32(0, 0X405F);
    func_800575B4(rdram, ctx);
        goto after_1;
    // 0x80057668: addiu       $a1, $zero, 0x405F
    ctx->r5 = ADD32(0, 0X405F);
    after_1:
    // 0x8005766C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80057670: beq         $v0, $zero, L_800576B8
    if (ctx->r2 == 0) {
        // 0x80057674: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800576B8;
    }
    // 0x80057674: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80057678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005767C: beq         $a2, $at, L_800576A4
    if (ctx->r6 == ctx->r1) {
        // 0x80057680: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800576A4;
    }
    // 0x80057680: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80057684: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057688: beq         $a2, $at, L_800576AC
    if (ctx->r6 == ctx->r1) {
        // 0x8005768C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800576AC;
    }
    // 0x8005768C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80057690: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057694: beq         $a2, $at, L_800576B4
    if (ctx->r6 == ctx->r1) {
        // 0x80057698: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800576B4;
    }
    // 0x80057698: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8005769C: b           L_800576BC
    // 0x800576A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800576BC;
    // 0x800576A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800576A4:
    // 0x800576A4: b           L_800576B8
    // 0x800576A8: sw          $t6, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r14;
        goto L_800576B8;
    // 0x800576A8: sw          $t6, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r14;
L_800576AC:
    // 0x800576AC: b           L_800576B8
    // 0x800576B0: sw          $t7, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r15;
        goto L_800576B8;
    // 0x800576B0: sw          $t7, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r15;
L_800576B4:
    // 0x800576B4: sw          $t8, 0x1F4($v0)
    MEM_W(0X1F4, ctx->r2) = ctx->r24;
L_800576B8:
    // 0x800576B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800576BC:
    // 0x800576BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800576C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800576C4: jr          $ra
    // 0x800576C8: nop

    return;
    // 0x800576C8: nop

;}
RECOMP_FUNC void func_8058496C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058496C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584970: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584974: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584978: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058497C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584980: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584984: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584988: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8058498C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584990: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584994: jr          $ra
    // 0x80584998: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584998: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807A1F90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1F90: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A1F94: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807A1F98: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A1F9C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807A1FA0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807A1FA4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807A1FA8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807A1FAC: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(844, 0X17C) << 16);
    // 0x807A1FB0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A1FB4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A1FB8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x807A1FBC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A1FC0: lw          $t1, 0x204C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(844, 0X17C));
    // 0x807A1FC4: jr          $ra
    // 0x807A1FC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807A1FC8: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804D65DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D65DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D65E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D65E4: jal         0x804D65A0
    // 0x804D65E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804D65A0(rdram, ctx);
        goto after_0;
    // 0x804D65E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D65EC: beql        $v0, $zero, L_804D6614
    if (ctx->r2 == 0) {
        // 0x804D65F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D6614;
    }
    goto skip_0;
    // 0x804D65F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804D65F4: jal         0x804D6544
    // 0x804D65F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804D6544(rdram, ctx);
        goto after_1;
    // 0x804D65F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804D65FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804D6600: bnel        $v0, $at, L_804D6614
    if (ctx->r2 != ctx->r1) {
        // 0x804D6604: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804D6614;
    }
    goto skip_1;
    // 0x804D6604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804D6608: jal         0x800447C8
    // 0x804D660C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x804D660C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804D6610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D6614:
    // 0x804D6614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D6618: jr          $ra
    // 0x804D661C: nop

    return;
    // 0x804D661C: nop

;}
RECOMP_FUNC void func_8003001C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003001C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030024: jal         0x80021958
    // 0x80030028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80030028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003002C: bne         $v0, $zero, L_8003003C
    if (ctx->r2 != 0) {
        // 0x80030030: nop
    
            goto L_8003003C;
    }
    // 0x80030030: nop

    // 0x80030034: b           L_80030058
    // 0x80030038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030058;
    // 0x80030038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003003C:
    // 0x8003003C: jal         0x80033FB0
    // 0x80030040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80033FB0(rdram, ctx);
        goto after_1;
    // 0x80030040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80030044: beql        $v0, $zero, L_80030058
    if (ctx->r2 == 0) {
        // 0x80030048: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80030058;
    }
    goto skip_0;
    // 0x80030048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x8003004C: b           L_80030058
    // 0x80030050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030058;
    // 0x80030050: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030054: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030058:
    // 0x80030058: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003005C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030060: jr          $ra
    // 0x80030064: nop

    return;
    // 0x80030064: nop

;}
RECOMP_FUNC void func_805A17C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A17C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A17C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A17CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x805A17D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A17D4: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x805A17D8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x805A17DC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A17E0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x805A17E4: nop

    // 0x805A17E8: bc1fl       L_805A183C
    if (!c1cs) {
        // 0x805A17EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A183C;
    }
    goto skip_0;
    // 0x805A17EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A17F0: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x805A17F4: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A17F8: addiu       $a2, $a2, -0x3198
    ctx->r6 = ADD32(ctx->r6, -0X3198);
    // 0x805A17FC: beql        $t6, $zero, L_805A183C
    if (ctx->r14 == 0) {
        // 0x805A1800: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A183C;
    }
    goto skip_1;
    // 0x805A1800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805A1804: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x805A1808: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x805A180C: jal         0x8004D1F0
    // 0x805A1810: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x805A1810: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A1814: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x805A1818: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A181C: addiu       $a2, $a2, -0x2B90
    ctx->r6 = ADD32(ctx->r6, -0X2B90);
    // 0x805A1820: jal         0x8004D698
    // 0x805A1824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x805A1824: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x805A1828: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x805A182C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x805A1830: ori         $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 | 0XF000;
    // 0x805A1834: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x805A1838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A183C:
    // 0x805A183C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A1840: jr          $ra
    // 0x805A1844: nop

    return;
    // 0x805A1844: nop

;}
RECOMP_FUNC void func_807B4D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4D10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B4D14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B4D18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807B4D1C: jal         0x807B4A10
    // 0x807B4D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_807B4A10(rdram, ctx);
        goto after_0;
    // 0x807B4D20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x807B4D24: lui         $a1, 0x807B
    ctx->r5 = S32(RELOC_HI16(880, 0X2C70) << 16);
    // 0x807B4D28: addiu       $a1, $a1, 0x7470
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(880, 0X2C70));
    // 0x807B4D2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807B4D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807B4D34: jal         0x807B4900
    // 0x807B4D38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807B4900(rdram, ctx);
        goto after_1;
    // 0x807B4D38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x807B4D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B4D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B4D44: jr          $ra
    // 0x807B4D48: nop

    return;
    // 0x807B4D48: nop

;}
RECOMP_FUNC void func_807BC57C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC57C: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807BC580: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807BC584: beq         $v0, $zero, L_807BC594
    if (ctx->r2 == 0) {
        // 0x807BC588: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807BC594;
    }
    // 0x807BC588: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807BC58C: jr          $ra
    // 0x807BC590: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    return;
    // 0x807BC590: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807BC594:
    // 0x807BC594: lh          $t7, 0x144($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X144);
    // 0x807BC598: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x807BC59C: sh          $t8, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r24;
    // 0x807BC5A0: lh          $t9, 0x144($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X144);
    // 0x807BC5A4: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x807BC5A8: bnel        $at, $zero, L_807BC5B8
    if (ctx->r1 != 0) {
        // 0x807BC5AC: sw          $t0, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r8;
            goto L_807BC5B8;
    }
    goto skip_0;
    // 0x807BC5AC: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
    skip_0:
    // 0x807BC5B0: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x807BC5B4: sw          $t0, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r8;
L_807BC5B8:
    // 0x807BC5B8: jr          $ra
    // 0x807BC5BC: nop

    return;
    // 0x807BC5BC: nop

;}
RECOMP_FUNC void func_8004D5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D5C8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x8004D5CC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8004D5D0: subu        $v1, $v1, $a1
    ctx->r3 = SUB32(ctx->r3, ctx->r5);
    // 0x8004D5D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8004D5D8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8004D5DC: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004D5E0: addu        $a2, $t7, $v1
    ctx->r6 = ADD32(ctx->r15, ctx->r3);
    // 0x8004D5E4: lbu         $t8, 0x0($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X0);
    // 0x8004D5E8: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8004D5EC: bne         $t9, $zero, L_8004D610
    if (ctx->r25 != 0) {
        // 0x8004D5F0: nop
    
            goto L_8004D610;
    }
    // 0x8004D5F0: nop

    // 0x8004D5F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004D5F8: nop

    // 0x8004D5FC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8004D600: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004D604: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x8004D608: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8004D60C: sb          $zero, 0x14($t2)
    MEM_B(0X14, ctx->r10) = 0;
L_8004D610:
    // 0x8004D610: jr          $ra
    // 0x8004D614: nop

    return;
    // 0x8004D614: nop

;}
RECOMP_FUNC void func_80453EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80453EB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453EB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453EB8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80453EBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80453EC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80453EC4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80453EC8: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    // 0x80453ECC: jal         0x804449C0
    // 0x80453ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804449C0(rdram, ctx);
        goto after_0;
    // 0x80453ED0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80453ED4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80453ED8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80453EDC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80453EE0: jal         0x80450490
    // 0x80453EE4: nop

    func_80450490(rdram, ctx);
        goto after_1;
    // 0x80453EE4: nop

    after_1:
    // 0x80453EE8: jal         0x80445760
    // 0x80453EEC: nop

    func_80445760(rdram, ctx);
        goto after_2;
    // 0x80453EEC: nop

    after_2:
    // 0x80453EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80453EF4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80453EF8: jal         0x80457164
    // 0x80453EFC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    func_80457164(rdram, ctx);
        goto after_3;
    // 0x80453EFC: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_3:
    // 0x80453F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80453F08: jr          $ra
    // 0x80453F0C: nop

    return;
    // 0x80453F0C: nop

;}
RECOMP_FUNC void func_806B276C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B276C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2770: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2774: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2778: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B277C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2780: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2784: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2788: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B278C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2790: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2794: jr          $ra
    // 0x806B2798: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2798: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8078B5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B5AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8078B5B0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8078B5B4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8078B5B8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8078B5BC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8078B5C0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8078B5C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8078B5C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8078B5CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8078B5D0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8078B5D4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8078B5D8: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078B5DC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8078B5E0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8078B5E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8078B5E8: jal         0x80048F84
    // 0x8078B5EC: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8078B5EC: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
    after_0:
    // 0x8078B5F0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8078B5F4: jal         0x8078B1E0
    // 0x8078B5F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    func_8078B1E0(rdram, ctx);
        goto after_1;
    // 0x8078B5F8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x8078B5FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078B600: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8078B604: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B48) << 16);
    // 0x8078B608: lui         $s3, 0x8079
    ctx->r19 = S32(RELOC_HI16(796, 0X1AB8) << 16);
    // 0x8078B60C: addiu       $s3, $s3, -0x33B8
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(796, 0X1AB8));
    // 0x8078B610: lwc1        $f20, -0x3328($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B48));
    // 0x8078B614: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8078B618: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_8078B61C:
    // 0x8078B61C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8078B620: lw          $s0, 0x1F4($t6)
    ctx->r16 = MEM_W(ctx->r14, 0X1F4);
    // 0x8078B624: lwc1        $f0, 0xC0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8078B628: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x8078B62C: nop

    // 0x8078B630: bc1fl       L_8078B6A8
    if (!c1cs) {
        // 0x8078B634: add.s       $f4, $f0, $f20
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
            goto L_8078B6A8;
    }
    goto skip_0;
    // 0x8078B634: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    skip_0:
    // 0x8078B638: lw          $t7, 0xC8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC8);
    // 0x8078B63C: swc1        $f20, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f20.u32l;
    // 0x8078B640: jal         0x800653D8
    // 0x8078B644: sw          $t7, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r15;
    func_800653D8(rdram, ctx);
        goto after_2;
    // 0x8078B644: sw          $t7, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->r15;
    after_2:
    // 0x8078B648: bgez        $v0, L_8078B65C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8078B64C: andi        $v1, $v0, 0x3
        ctx->r3 = ctx->r2 & 0X3;
            goto L_8078B65C;
    }
    // 0x8078B64C: andi        $v1, $v0, 0x3
    ctx->r3 = ctx->r2 & 0X3;
    // 0x8078B650: beq         $v1, $zero, L_8078B65C
    if (ctx->r3 == 0) {
        // 0x8078B654: nop
    
            goto L_8078B65C;
    }
    // 0x8078B654: nop

    // 0x8078B658: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
L_8078B65C:
    // 0x8078B65C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8078B660: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x8078B664: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8078B668: lw          $t8, 0xC8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC8);
    // 0x8078B66C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8078B670: bnel        $t8, $t1, L_8078B694
    if (ctx->r24 != ctx->r9) {
        // 0x8078B674: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_8078B694;
    }
    goto skip_1;
    // 0x8078B674: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    skip_1:
    // 0x8078B678: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x8078B67C: bgez        $a0, L_8078B690
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8078B680: andi        $a0, $a0, 0x3
        ctx->r4 = ctx->r4 & 0X3;
            goto L_8078B690;
    }
    // 0x8078B680: andi        $a0, $a0, 0x3
    ctx->r4 = ctx->r4 & 0X3;
    // 0x8078B684: beq         $a0, $zero, L_8078B690
    if (ctx->r4 == 0) {
        // 0x8078B688: nop
    
            goto L_8078B690;
    }
    // 0x8078B688: nop

    // 0x8078B68C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_8078B690:
    // 0x8078B690: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
L_8078B694:
    // 0x8078B694: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x8078B698: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8078B69C: b           L_8078B6C4
    // 0x8078B6A0: sw          $t4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r12;
        goto L_8078B6C4;
    // 0x8078B6A0: sw          $t4, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->r12;
    // 0x8078B6A4: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
L_8078B6A8:
    // 0x8078B6A8: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x8078B6AC: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8078B6B0: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8078B6B4: nop

    // 0x8078B6B8: bc1fl       L_8078B6C8
    if (!c1cs) {
        // 0x8078B6BC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8078B6C8;
    }
    goto skip_2;
    // 0x8078B6BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8078B6C0: swc1        $f22, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f22.u32l;
L_8078B6C4:
    // 0x8078B6C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8078B6C8:
    // 0x8078B6C8: bne         $s1, $s4, L_8078B61C
    if (ctx->r17 != ctx->r20) {
        // 0x8078B6CC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8078B61C;
    }
    // 0x8078B6CC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8078B6D0: jal         0x80066DE4
    // 0x8078B6D4: lwc1        $f12, 0x14($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X14);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8078B6D4: lwc1        $f12, 0x14($s5)
    ctx->f12.u32l = MEM_W(ctx->r21, 0X14);
    after_3:
    // 0x8078B6D8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B4C) << 16);
    // 0x8078B6DC: lwc1        $f12, -0x3324($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B4C));
    // 0x8078B6E0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8078B6E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8078B6E8: nop

    // 0x8078B6EC: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8078B6F0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8078B6F4: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8078B6F8: bc1t        L_8078B720
    if (c1cs) {
        // 0x8078B6FC: nop
    
            goto L_8078B720;
    }
    // 0x8078B6FC: nop

    // 0x8078B700: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8078B704: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B50) << 16);
    // 0x8078B708: bc1t        L_8078B75C
    if (c1cs) {
        // 0x8078B70C: nop
    
            goto L_8078B75C;
    }
    // 0x8078B70C: nop

    // 0x8078B710: lwc1        $f14, -0x3320($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B50));
    // 0x8078B714: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8078B718: nop

    // 0x8078B71C: bc1t        L_8078B75C
    if (c1cs) {
        // 0x8078B720: lui         $at, 0x8079
        ctx->r1 = S32(RELOC_HI16(796, 0X1B54) << 16);
            goto L_8078B75C;
    }
L_8078B720:
    // 0x8078B720: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B54) << 16);
    // 0x8078B724: lwc1        $f14, -0x331C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B54));
    // 0x8078B728: lwc1        $f10, 0x18($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8078B72C: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x8078B730: nop

    // 0x8078B734: bc1f        L_8078B75C
    if (!c1cs) {
        // 0x8078B738: nop
    
            goto L_8078B75C;
    }
    // 0x8078B738: nop

    // 0x8078B73C: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8078B740: jal         0x80067BBC
    // 0x8078B744: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_4;
    // 0x8078B744: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    after_4:
    // 0x8078B748: addiu       $a0, $zero, 0x27C
    ctx->r4 = ADD32(0, 0X27C);
    // 0x8078B74C: jal         0x80067818
    // 0x8078B750: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x8078B750: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8078B754: b           L_8078B7C4
    // 0x8078B758: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
        goto L_8078B7C4;
    // 0x8078B758: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
L_8078B75C:
    // 0x8078B75C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(796, 0X1B58) << 16);
    // 0x8078B760: lwc1        $f14, -0x3318($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(796, 0X1B58));
    // 0x8078B764: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8078B768: nop

    // 0x8078B76C: bc1fl       L_8078B7C4
    if (!c1cs) {
        // 0x8078B770: sub.s       $f16, $f22, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
            goto L_8078B7C4;
    }
    goto skip_3;
    // 0x8078B770: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
    skip_3:
    // 0x8078B774: lwc1        $f0, 0x18($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8078B778: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8078B77C: nop

    // 0x8078B780: bc1tl       L_8078B7AC
    if (c1cs) {
        // 0x8078B784: lw          $a0, 0x34($s6)
        ctx->r4 = MEM_W(ctx->r22, 0X34);
            goto L_8078B7AC;
    }
    goto skip_4;
    // 0x8078B784: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    skip_4:
    // 0x8078B788: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8078B78C: nop

    // 0x8078B790: bc1tl       L_8078B7C4
    if (c1cs) {
        // 0x8078B794: sub.s       $f16, $f22, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
            goto L_8078B7C4;
    }
    goto skip_5;
    // 0x8078B794: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
    skip_5:
    // 0x8078B798: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8078B79C: nop

    // 0x8078B7A0: bc1tl       L_8078B7C4
    if (c1cs) {
        // 0x8078B7A4: sub.s       $f16, $f22, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
            goto L_8078B7C4;
    }
    goto skip_6;
    // 0x8078B7A4: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
    skip_6:
    // 0x8078B7A8: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
L_8078B7AC:
    // 0x8078B7AC: jal         0x80067BBC
    // 0x8078B7B0: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8078B7B0: lw          $a1, 0x38($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X38);
    after_6:
    // 0x8078B7B4: addiu       $a0, $zero, 0x27D
    ctx->r4 = ADD32(0, 0X27D);
    // 0x8078B7B8: jal         0x80067818
    // 0x8078B7BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8078B7BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8078B7C0: sub.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f20.fl;
L_8078B7C4:
    // 0x8078B7C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8078B7C8: swc1        $f20, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f20.u32l;
    // 0x8078B7CC: add.s       $f18, $f22, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x8078B7D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8078B7D4: swc1        $f16, 0x6C($s6)
    MEM_W(0X6C, ctx->r22) = ctx->f16.u32l;
    // 0x8078B7D8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8078B7DC: swc1        $f18, 0x70($s6)
    MEM_W(0X70, ctx->r22) = ctx->f18.u32l;
    // 0x8078B7E0: lwc1        $f4, 0x14($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8078B7E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078B7E8: nop

    // 0x8078B7EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8078B7F0: swc1        $f8, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->f8.u32l;
    // 0x8078B7F4: lwc1        $f0, 0x14($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8078B7F8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8078B7FC: nop

    // 0x8078B800: bc1fl       L_8078B814
    if (!c1cs) {
        // 0x8078B804: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8078B814;
    }
    goto skip_7;
    // 0x8078B804: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_7:
    // 0x8078B808: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8078B80C: swc1        $f10, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->f10.u32l;
    // 0x8078B810: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8078B814:
    // 0x8078B814: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8078B818: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8078B81C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8078B820: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8078B824: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8078B828: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8078B82C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8078B830: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8078B834: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8078B838: jr          $ra
    // 0x8078B83C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8078B83C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_804D2DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2DB4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804D2DB8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x804D2DBC: addiu       $v1, $a0, -0x8
    ctx->r3 = ADD32(ctx->r4, -0X8);
    // 0x804D2DC0: sltiu       $at, $v1, 0xFF
    ctx->r1 = ctx->r3 < 0XFF ? 1 : 0;
    // 0x804D2DC4: bne         $at, $zero, L_804D2DD0
    if (ctx->r1 != 0) {
        // 0x804D2DC8: nop
    
            goto L_804D2DD0;
    }
    // 0x804D2DC8: nop

    // 0x804D2DCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_804D2DD0:
    // 0x804D2DD0: jr          $ra
    // 0x804D2DD4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    return;
    // 0x804D2DD4: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
;}
RECOMP_FUNC void func_8042946C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042946C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80429470: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80429474: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80429478: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8042947C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80429480: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80429484: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80429488: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8042948C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80429490: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80429494: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80429498: bltz        $v0, L_804294F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8042949C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_804294F8;
    }
    // 0x8042949C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x804294A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x804294A4: addu        $s0, $a3, $v0
    ctx->r16 = ADD32(ctx->r7, ctx->r2);
    // 0x804294A8: addu        $s1, $a1, $v0
    ctx->r17 = ADD32(ctx->r5, ctx->r2);
    // 0x804294AC: lwc1        $f24, 0x50($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X50);
L_804294B0:
    // 0x804294B0: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x804294B4: jal         0x80066E88
    // 0x804294B8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804294B8: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x804294BC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x804294C0: jal         0x80066DE4
    // 0x804294C4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804294C4: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x804294C8: mul.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x804294CC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x804294D0: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x804294D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x804294D8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x804294DC: jal         0x804293FC
    // 0x804294E0: nop

    func_804293FC(rdram, ctx);
        goto after_2;
    // 0x804294E0: nop

    after_2:
    // 0x804294E4: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x804294E8: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
    // 0x804294EC: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x804294F0: bgez        $s2, L_804294B0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x804294F4: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_804294B0;
    }
    // 0x804294F4: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
L_804294F8:
    // 0x804294F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x804294FC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80429500: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x80429504: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80429508: jal         0x804293FC
    // 0x8042950C: nop

    func_804293FC(rdram, ctx);
        goto after_3;
    // 0x8042950C: nop

    after_3:
    // 0x80429510: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80429514: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80429518: jal         0x804293FC
    // 0x8042951C: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    func_804293FC(rdram, ctx);
        goto after_4;
    // 0x8042951C: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    after_4:
    // 0x80429520: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80429524: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80429528: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8042952C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80429530: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80429534: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80429538: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x8042953C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80429540: jr          $ra
    // 0x80429544: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80429544: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80429548: nop

    // 0x8042954C: nop

;}
RECOMP_FUNC void func_8006E514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E514: lui         $v0, 0x8007
    ctx->r2 = S32(0X8007 << 16);
    // 0x8006E518: addiu       $v0, $v0, -0x1ADC
    ctx->r2 = ADD32(ctx->r2, -0X1ADC);
    // 0x8006E51C: jr          $ra
    // 0x8006E520: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E520: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001AB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AB9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001ABA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ABA4: jal         0x80019AC4
    // 0x8001ABA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80019AC4(rdram, ctx);
        goto after_0;
    // 0x8001ABA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001ABAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001ABB0: beq         $v0, $zero, L_8001ABCC
    if (ctx->r2 == 0) {
        // 0x8001ABB4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001ABCC;
    }
    // 0x8001ABB4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001ABB8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001ABBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8001ABC0: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8001ABC4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x8001ABC8: sh          $t7, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r15;
L_8001ABCC:
    // 0x8001ABCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ABD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001ABD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001ABD8: jr          $ra
    // 0x8001ABDC: nop

    return;
    // 0x8001ABDC: nop

;}
RECOMP_FUNC void func_8006767C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006767C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80067680: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80067684: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80067688: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006768C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80067690: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80067694: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80067698: sb          $zero, 0x15C($a0)
    MEM_B(0X15C, ctx->r4) = 0;
    // 0x8006769C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800676A0: addiu       $s1, $a0, 0x168
    ctx->r17 = ADD32(ctx->r4, 0X168);
    // 0x800676A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800676A8: addiu       $s3, $a0, 0x258
    ctx->r19 = ADD32(ctx->r4, 0X258);
    // 0x800676AC: addiu       $s4, $zero, 0x190
    ctx->r20 = ADD32(0, 0X190);
L_800676B0:
    // 0x800676B0: sb          $zero, 0x15D($s0)
    MEM_B(0X15D, ctx->r16) = 0;
    // 0x800676B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800676B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800676BC: jal         0x8008AE20
    // 0x800676C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800676C0: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_0:
    // 0x800676C4: addiu       $s2, $s2, 0x28
    ctx->r18 = ADD32(ctx->r18, 0X28);
    // 0x800676C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800676CC: addiu       $s1, $s1, 0x18
    ctx->r17 = ADD32(ctx->r17, 0X18);
    // 0x800676D0: bne         $s2, $s4, L_800676B0
    if (ctx->r18 != ctx->r20) {
        // 0x800676D4: addiu       $s3, $s3, 0x28
        ctx->r19 = ADD32(ctx->r19, 0X28);
            goto L_800676B0;
    }
    // 0x800676D4: addiu       $s3, $s3, 0x28
    ctx->r19 = ADD32(ctx->r19, 0X28);
    // 0x800676D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800676DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800676E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800676E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800676E8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800676EC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800676F0: jr          $ra
    // 0x800676F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800676F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Fault_HungUp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    yoshi_report_hungup(rdram, ctx);
    // 0x80071380: lui         $t2, 0xFFFA
    ctx->r10 = S32(0XFFFA << 16);
    // 0x80071384: or          $t3, $sp, $zero
    ctx->r11 = ctx->r29 | 0;
    // 0x80071388: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007138C: ori         $t2, $t2, 0x5A5A
    ctx->r10 = ctx->r10 | 0X5A5A;
L_80071390:
    // 0x80071390: addiu       $t3, $t3, -0x8
    ctx->r11 = ADD32(ctx->r11, -0X8);
    // 0x80071394: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80071398: bne         $t3, $sp, L_80071390
    if (ctx->r11 != ctx->r29) {
        // 0x8007139C: sw          $t2, 0x4($t3)
        MEM_W(0X4, ctx->r11) = ctx->r10;
            goto L_80071390;
    }
    // 0x8007139C: sw          $t2, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r10;
    // 0x800713A0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800713A4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800713A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800713AC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800713B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800713B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800713B8: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800713BC: addiu       $t7, $t7, -0x7FFC
    ctx->r15 = ADD32(ctx->r15, -0X7FFC);
    // 0x800713C0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800713C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800713C8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800713CC: addiu       $a0, $a0, 0x1A40
    ctx->r4 = ADD32(ctx->r4, 0X1A40);
    // 0x800713D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800713D4: jal         0x8008AD5C
    // 0x800713D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    osSyncPrintf(rdram, ctx);
        goto after_0;
    // 0x800713D8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x800713DC: jal         0x80086880
    // 0x800713E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    osGetThreadId_recomp(rdram, ctx);
        goto after_1;
    // 0x800713E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800713E4: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800713E8: addiu       $s0, $s0, -0x7FF8
    ctx->r16 = ADD32(ctx->r16, -0X7FF8);
    // 0x800713EC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800713F0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800713F4: addiu       $t8, $t8, 0x1A6C
    ctx->r24 = ADD32(ctx->r24, 0X1A6C);
    // 0x800713F8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800713FC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80071400: addiu       $a2, $a2, 0x1A64
    ctx->r6 = ADD32(ctx->r6, 0X1A64);
    // 0x80071404: addiu       $a0, $a0, 0x1A50
    ctx->r4 = ADD32(ctx->r4, 0X1A50);
    // 0x80071408: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007140C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80071410: addiu       $a3, $zero, 0x4DF
    ctx->r7 = ADD32(0, 0X4DF);
    // 0x80071414: jal         0x8008AD5C
    // 0x80071418: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osSyncPrintf(rdram, ctx);
        goto after_2;
    // 0x80071418: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x8007141C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80071420: bne         $t0, $zero, L_8007143C
    if (ctx->r8 != 0) {
        // 0x80071424: nop
    
            goto L_8007143C;
    }
    // 0x80071424: nop

L_80071428:
    // 0x80071428: jal         0x8006F8F0
    // 0x8007142C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    Fault_Sleep(rdram, ctx);
        goto after_3;
    // 0x8007142C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_3:
    // 0x80071430: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80071434: beq         $t1, $zero, L_80071428
    if (ctx->r9 == 0) {
        // 0x80071438: nop
    
            goto L_80071428;
    }
    // 0x80071438: nop

L_8007143C:
    // 0x8007143C: jal         0x8006F8F0
    // 0x80071440: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    Fault_Sleep(rdram, ctx);
        goto after_4;
    // 0x80071440: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_4:
    // 0x80071444: jal         0x800703C4
    // 0x80071448: nop

    Fault_WaitButtonCombo(rdram, ctx);
        goto after_5;
    // 0x80071448: nop

    after_5:
    // 0x8007144C: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x80071450: addiu       $s0, $s0, 0x1A84
    ctx->r16 = ADD32(ctx->r16, 0X1A84);
L_80071454:
    // 0x80071454: jal         0x80070F1C
    // 0x80071458: nop

    Fault_DisplayFramebuffer(rdram, ctx);
        goto after_6;
    // 0x80071458: nop

    after_6:
    // 0x8007145C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80071460: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80071464: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x80071468: jal         0x8006F600
    // 0x8007146C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    Fault_DrawRec(rdram, ctx);
        goto after_7;
    // 0x8007146C: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    after_7:
    // 0x80071470: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80071474: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80071478: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8007147C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80071480: jal         0x8006F884
    // 0x80071484: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    Fault_Printf(rdram, ctx);
        goto after_8;
    // 0x80071484: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_8:
    // 0x80071488: jal         0x8006F8F0
    // 0x8007148C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    Fault_Sleep(rdram, ctx);
        goto after_9;
    // 0x8007148C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    after_9:
    // 0x80071490: b           L_80071454
    // 0x80071494: nop

        goto L_80071454;
    // 0x80071494: nop

    // 0x80071498: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007149C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800714A0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800714A4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800714A8: jr          $ra
    // 0x800714AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800714AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8073EA08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EA08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8073EA0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8073EA10: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8073EA14: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8073EA18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8073EA1C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8073EA20: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8073EA24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8073EA28: bne         $v0, $at, L_8073EA40
    if (ctx->r2 != ctx->r1) {
        // 0x8073EA2C: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8073EA40;
    }
    // 0x8073EA2C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8073EA30: jal         0x8002F6E4
    // 0x8073EA34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_0;
    // 0x8073EA34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8073EA38: jal         0x8073E8FC
    // 0x8073EA3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8073E8FC(rdram, ctx);
        goto after_1;
    // 0x8073EA3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_8073EA40:
    // 0x8073EA40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8073EA44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8073EA48: jr          $ra
    // 0x8073EA4C: nop

    return;
    // 0x8073EA4C: nop

;}
RECOMP_FUNC void func_804D2E60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2E60: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804D2E64: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804D2E68: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x804D2E6C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x804D2E70: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x804D2E74: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x804D2E78: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x804D2E7C: lui         $t9, 0x804D
    ctx->r25 = S32(RELOC_HI16(249, 0X538) << 16);
    // 0x804D2E80: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804D2E84: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804D2E88: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804D2E8C: lw          $t9, 0x3048($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(249, 0X538));
    // 0x804D2E90: jr          $ra
    // 0x804D2E94: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    return;
    // 0x804D2E94: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_805539DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805539DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x805539E0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x805539E4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x805539E8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x805539EC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x805539F0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x805539F4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x805539F8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x805539FC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80553A00: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80553A04: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80553A08: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80553A0C: lw          $t6, 0x174($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X174);
    // 0x80553A10: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80553A14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80553A18: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80553A1C: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80553A20: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80553A24: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80553A28: lw          $v1, 0x70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X70);
    // 0x80553A2C: lh          $t8, 0xC($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XC);
    // 0x80553A30: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80553A34: mul.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80553A38: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80553A3C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80553A40: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80553A44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80553A48: lwc1        $f24, 0x84($a2)
    ctx->f24.u32l = MEM_W(ctx->r6, 0X84);
    // 0x80553A4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80553A50: lwc1        $f26, 0x88($a2)
    ctx->f26.u32l = MEM_W(ctx->r6, 0X88);
    // 0x80553A54: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80553A58: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x80553A5C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80553A60: mul.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80553A64: add.s       $f30, $f0, $f22
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f30.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80553A68: mul.s       $f28, $f18, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80553A6C: nop

L_80553A70:
    // 0x80553A70: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80553A74: sub.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x80553A78: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80553A7C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80553A80: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80553A84: sub.s       $f4, $f16, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x80553A88: jal         0x80065954
    // 0x80553A8C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80553A8C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x80553A90: c.lt.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl < ctx->f30.fl;
    // 0x80553A94: nop

    // 0x80553A98: bc1fl       L_80553AC8
    if (!c1cs) {
        // 0x80553A9C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80553AC8;
    }
    goto skip_0;
    // 0x80553A9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80553AA0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80553AA4: jal         0x80065954
    // 0x80553AA8: add.s       $f20, $f28, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f28.fl + ctx->f22.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80553AA8: add.s       $f20, $f28, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f28.fl + ctx->f22.fl;
    after_1:
    // 0x80553AAC: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80553AB0: nop

    // 0x80553AB4: bc1fl       L_80553AC8
    if (!c1cs) {
        // 0x80553AB8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80553AC8;
    }
    goto skip_1;
    // 0x80553AB8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80553ABC: b           L_80553AD4
    // 0x80553AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80553AD4;
    // 0x80553AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80553AC4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80553AC8:
    // 0x80553AC8: bne         $s2, $s3, L_80553A70
    if (ctx->r18 != ctx->r19) {
        // 0x80553ACC: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80553A70;
    }
    // 0x80553ACC: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80553AD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80553AD4:
    // 0x80553AD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80553AD8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80553ADC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80553AE0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80553AE4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80553AE8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80553AEC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80553AF0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80553AF4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80553AF8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80553AFC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80553B00: jr          $ra
    // 0x80553B04: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80553B04: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8079EC5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EC5C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC60: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8079EC64: sb          $zero, 0xD($t6)
    MEM_B(0XD, ctx->r14) = 0;
    // 0x8079EC68: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC6C: sb          $zero, 0xE($t7)
    MEM_B(0XE, ctx->r15) = 0;
    // 0x8079EC70: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x8079EC74: jr          $ra
    // 0x8079EC78: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
    return;
    // 0x8079EC78: sb          $t8, 0xF($t9)
    MEM_B(0XF, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void func_806D1AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D1AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D1AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D1AF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806D1AFC: lw          $v1, 0x16C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X16C);
    // 0x806D1B00: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(610, 0X171C) << 16);
    // 0x806D1B04: lw          $a1, 0x10($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X10);
    // 0x806D1B08: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x806D1B0C: beq         $a1, $zero, L_806D1B20
    if (ctx->r5 == 0) {
        // 0x806D1B10: lw          $a2, 0x16C($a3)
        ctx->r6 = MEM_W(ctx->r7, 0X16C);
            goto L_806D1B20;
    }
    // 0x806D1B10: lw          $a2, 0x16C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X16C);
    // 0x806D1B14: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x806D1B18: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x806D1B1C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_806D1B20:
    // 0x806D1B20: bnel        $a1, $zero, L_806D1BBC
    if (ctx->r5 != 0) {
        // 0x806D1B24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D1BBC;
    }
    goto skip_0;
    // 0x806D1B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D1B28: lwc1        $f4, 0x2CDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(610, 0X171C));
    // 0x806D1B2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806D1B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806D1B34: addiu       $a3, $a0, 0xC4
    ctx->r7 = ADD32(ctx->r4, 0XC4);
    // 0x806D1B38: swc1        $f4, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f4.u32l;
    // 0x806D1B3C: swc1        $f6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f6.u32l;
    // 0x806D1B40: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x806D1B44: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x806D1B48: addiu       $t8, $t7, -0x4
    ctx->r24 = ADD32(ctx->r15, -0X4);
    // 0x806D1B4C: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x806D1B50: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x806D1B54: bgez        $t0, L_806D1B6C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x806D1B58: sw          $t0, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r8;
            goto L_806D1B6C;
    }
    // 0x806D1B58: sw          $t0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r8;
    // 0x806D1B5C: jal         0x800447C8
    // 0x806D1B60: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806D1B60: nop

    after_0:
    // 0x806D1B64: b           L_806D1BBC
    // 0x806D1B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806D1BBC;
    // 0x806D1B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D1B6C:
    // 0x806D1B6C: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x806D1B70: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806D1B74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806D1B78: sb          $t2, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r10;
    // 0x806D1B7C: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x806D1B80: sb          $t3, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r11;
    // 0x806D1B84: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x806D1B88: sb          $t4, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r12;
    // 0x806D1B8C: lw          $t5, 0x1C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X1C);
    // 0x806D1B90: sb          $t5, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r13;
    // 0x806D1B94: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x806D1B98: sb          $t6, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r14;
    // 0x806D1B9C: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x806D1BA0: sb          $t7, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r15;
    // 0x806D1BA4: lw          $t8, 0x18($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X18);
    // 0x806D1BA8: sb          $t8, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r24;
    // 0x806D1BAC: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x806D1BB0: jal         0x80048F84
    // 0x806D1BB4: sb          $t9, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r25;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x806D1BB4: sb          $t9, 0x10($a2)
    MEM_B(0X10, ctx->r6) = ctx->r25;
    after_1:
    // 0x806D1BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D1BBC:
    // 0x806D1BBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D1BC0: jr          $ra
    // 0x806D1BC4: nop

    return;
    // 0x806D1BC4: nop

;}
RECOMP_FUNC void func_8044B3B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B3B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8044B3B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B3BC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044B3C0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B3C4: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B3C8: lw          $a1, 0x6A74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X6A74);
    // 0x8044B3CC: beq         $a1, $zero, L_8044B3E4
    if (ctx->r5 == 0) {
        // 0x8044B3D0: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8044B3E4;
    }
    // 0x8044B3D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8044B3D4: jal         0x80050A2C
    // 0x8044B3D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80050A2C(rdram, ctx);
        goto after_0;
    // 0x8044B3D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8044B3DC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B3E0: sw          $zero, 0x6A74($v1)
    MEM_W(0X6A74, ctx->r3) = 0;
L_8044B3E4:
    // 0x8044B3E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B3E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8044B3EC: jr          $ra
    // 0x8044B3F0: nop

    return;
    // 0x8044B3F0: nop

;}
RECOMP_FUNC void func_80044AC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80044AC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80044ACC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80044AD0: jal         0x8004434C
    // 0x80044AD4: nop

    func_8004434C(rdram, ctx);
        goto after_0;
    // 0x80044AD4: nop

    after_0:
    // 0x80044AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80044ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80044AE0: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80044AE4: jr          $ra
    // 0x80044AE8: nop

    return;
    // 0x80044AE8: nop

;}
RECOMP_FUNC void func_80052CDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052CDC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80052CE0: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x80052CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80052CE8: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80052CEC: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x80052CF0: beq         $v1, $zero, L_80052D14
    if (ctx->r3 == 0) {
        // 0x80052CF4: nop
    
            goto L_80052D14;
    }
    // 0x80052CF4: nop

    // 0x80052CF8: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    // 0x80052CFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80052D00: beq         $t8, $zero, L_80052D14
    if (ctx->r24 == 0) {
        // 0x80052D04: nop
    
            goto L_80052D14;
    }
    // 0x80052D04: nop

    // 0x80052D08: sw          $v1, 0x60D0($at)
    MEM_W(0X60D0, ctx->r1) = ctx->r3;
    // 0x80052D0C: jr          $ra
    // 0x80052D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80052D10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80052D14:
    // 0x80052D14: jr          $ra
    // 0x80052D18: nop

    return;
    // 0x80052D18: nop

;}
RECOMP_FUNC void func_8051A800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051A800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051A804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051A808: jal         0x80056904
    // 0x8051A80C: nop

    func_80056904(rdram, ctx);
        goto after_0;
    // 0x8051A80C: nop

    after_0:
    // 0x8051A810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051A814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051A818: jr          $ra
    // 0x8051A81C: nop

    return;
    // 0x8051A81C: nop

;}
RECOMP_FUNC void func_807B5AA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B5AA8: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x807B5AAC: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x807B5AB0: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x807B5AB4: lbu         $t6, 0xF5C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF5C);
    // 0x807B5AB8: lbu         $t7, 0xF5D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF5D);
    // 0x807B5ABC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B5AC0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x807B5AC4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x807B5AC8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x807B5ACC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B5AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B5AD4: lw          $s3, 0x14($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X14);
    // 0x807B5AD8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5ADC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x807B5AE0: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x807B5AE4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B5AE8:
    // 0x807B5AE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5AEC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5AF0: jal         0x8005C27C
    // 0x807B5AF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_0;
    // 0x807B5AF4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x807B5AF8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5AFC: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5B00: bnel        $at, $zero, L_807B5AE8
    if (ctx->r1 != 0) {
        // 0x807B5B04: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B5AE8;
    }
    goto skip_0;
    // 0x807B5B04: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_0:
    // 0x807B5B08: lui         $s0, 0x807B
    ctx->r16 = S32(RELOC_HI16(880, 0X2E58) << 16);
    // 0x807B5B0C: addiu       $s0, $s0, 0x7658
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(880, 0X2E58));
    // 0x807B5B10: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5B14: addiu       $s4, $zero, 0x1000
    ctx->r20 = ADD32(0, 0X1000);
    // 0x807B5B18: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
L_807B5B1C:
    // 0x807B5B1C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x807B5B20: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x807B5B24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5B28: sll         $a2, $s1, 3
    ctx->r6 = S32(ctx->r17 << 3);
    // 0x807B5B2C: bne         $s4, $a1, L_807B5B3C
    if (ctx->r20 != ctx->r5) {
        // 0x807B5B30: nop
    
            goto L_807B5B3C;
    }
    // 0x807B5B30: nop

    // 0x807B5B34: b           L_807B5B44
    // 0x807B5B38: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
        goto L_807B5B44;
    // 0x807B5B38: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_807B5B3C:
    // 0x807B5B3C: jal         0x8005C27C
    // 0x807B5B40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8005C27C(rdram, ctx);
        goto after_1;
    // 0x807B5B40: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_807B5B44:
    // 0x807B5B44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807B5B48: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x807B5B4C: bnel        $at, $zero, L_807B5B1C
    if (ctx->r1 != 0) {
        // 0x807B5B50: sll         $t8, $s1, 1
        ctx->r24 = S32(ctx->r17 << 1);
            goto L_807B5B1C;
    }
    goto skip_1;
    // 0x807B5B50: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    skip_1:
    // 0x807B5B54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5B58: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B5B5C:
    // 0x807B5B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5B60: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5B64: jal         0x8005C27C
    // 0x807B5B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_2;
    // 0x807B5B68: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x807B5B6C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5B70: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5B74: bnel        $at, $zero, L_807B5B5C
    if (ctx->r1 != 0) {
        // 0x807B5B78: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B5B5C;
    }
    goto skip_2;
    // 0x807B5B78: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_2:
    // 0x807B5B7C: jal         0x807B4A74
    // 0x807B5B80: nop

    func_807B4A74(rdram, ctx);
        goto after_3;
    // 0x807B5B80: nop

    after_3:
    // 0x807B5B84: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x807B5B88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x807B5B8C: jal         0x807B4B3C
    // 0x807B5B90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_4;
    // 0x807B5B90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x807B5B94: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x807B5B98: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
L_807B5B9C:
    // 0x807B5B9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5BA0: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x807B5BA4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5BA8: jal         0x8005C27C
    // 0x807B5BAC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_5;
    // 0x807B5BAC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_5:
    // 0x807B5BB0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5BB4: slti        $at, $s0, 0x78
    ctx->r1 = SIGNED(ctx->r16) < 0X78 ? 1 : 0;
    // 0x807B5BB8: bne         $at, $zero, L_807B5B9C
    if (ctx->r1 != 0) {
        // 0x807B5BBC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_807B5B9C;
    }
    // 0x807B5BBC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B5BC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5BC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5BC8: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5BCC: jal         0x8005C27C
    // 0x807B5BD0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_8005C27C(rdram, ctx);
        goto after_6;
    // 0x807B5BD0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_6:
    // 0x807B5BD4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5BD8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B5BDC:
    // 0x807B5BDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5BE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5BE4: jal         0x8005C27C
    // 0x807B5BE8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_7;
    // 0x807B5BE8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_7:
    // 0x807B5BEC: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5BF0: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5BF4: bnel        $at, $zero, L_807B5BDC
    if (ctx->r1 != 0) {
        // 0x807B5BF8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B5BDC;
    }
    goto skip_3;
    // 0x807B5BF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_3:
    // 0x807B5BFC: lui         $s0, 0x807B
    ctx->r16 = S32(RELOC_HI16(880, 0X2E70) << 16);
    // 0x807B5C00: addiu       $s0, $s0, 0x7670
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(880, 0X2E70));
    // 0x807B5C04: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x807B5C08: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
L_807B5C0C:
    // 0x807B5C0C: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x807B5C10: lhu         $a1, 0x0($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X0);
    // 0x807B5C14: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5C18: sll         $a2, $s1, 3
    ctx->r6 = S32(ctx->r17 << 3);
    // 0x807B5C1C: bne         $s4, $a1, L_807B5C2C
    if (ctx->r20 != ctx->r5) {
        // 0x807B5C20: nop
    
            goto L_807B5C2C;
    }
    // 0x807B5C20: nop

    // 0x807B5C24: b           L_807B5C34
    // 0x807B5C28: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
        goto L_807B5C34;
    // 0x807B5C28: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
L_807B5C2C:
    // 0x807B5C2C: jal         0x8005C27C
    // 0x807B5C30: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_8005C27C(rdram, ctx);
        goto after_8;
    // 0x807B5C30: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_8:
L_807B5C34:
    // 0x807B5C34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x807B5C38: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x807B5C3C: bnel        $at, $zero, L_807B5C0C
    if (ctx->r1 != 0) {
        // 0x807B5C40: sll         $t0, $s1, 1
        ctx->r8 = S32(ctx->r17 << 1);
            goto L_807B5C0C;
    }
    goto skip_4;
    // 0x807B5C40: sll         $t0, $s1, 1
    ctx->r8 = S32(ctx->r17 << 1);
    skip_4:
    // 0x807B5C44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x807B5C48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_807B5C4C:
    // 0x807B5C4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5C50: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5C54: jal         0x8005C27C
    // 0x807B5C58: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_9;
    // 0x807B5C58: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_9:
    // 0x807B5C5C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5C60: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    // 0x807B5C64: bnel        $at, $zero, L_807B5C4C
    if (ctx->r1 != 0) {
        // 0x807B5C68: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_807B5C4C;
    }
    goto skip_5;
    // 0x807B5C68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_5:
    // 0x807B5C6C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x807B5C70: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x807B5C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B5C78: sll         $s4, $s4, 2
    ctx->r20 = S32(ctx->r20 << 2);
    // 0x807B5C7C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x807B5C80: jal         0x800696D4
    // 0x807B5C84: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    func_800696D4(rdram, ctx);
        goto after_10;
    // 0x807B5C84: addu        $a0, $s4, $t2
    ctx->r4 = ADD32(ctx->r20, ctx->r10);
    after_10:
    // 0x807B5C88: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x807B5C8C: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
L_807B5C90:
    // 0x807B5C90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5C94: lhu         $a1, 0x0($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X0);
    // 0x807B5C98: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5C9C: jal         0x8005C27C
    // 0x807B5CA0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_11;
    // 0x807B5CA0: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_11:
    // 0x807B5CA4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5CA8: slti        $at, $s0, 0x48
    ctx->r1 = SIGNED(ctx->r16) < 0X48 ? 1 : 0;
    // 0x807B5CAC: bne         $at, $zero, L_807B5C90
    if (ctx->r1 != 0) {
        // 0x807B5CB0: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_807B5C90;
    }
    // 0x807B5CB0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x807B5CB4: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x807B5CB8: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x807B5CBC: addu        $t5, $t5, $s4
    ctx->r13 = ADD32(ctx->r13, ctx->r20);
    // 0x807B5CC0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x807B5CC4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x807B5CC8: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x807B5CCC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x807B5CD0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x807B5CD4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x807B5CD8: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x807B5CDC: lhu         $a1, -0x7178($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7178);
    // 0x807B5CE0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x807B5CE4: jal         0x807B4B3C
    // 0x807B5CE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_807B4B3C(rdram, ctx);
        goto after_12;
    // 0x807B5CE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x807B5CEC: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x807B5CF0: addiu       $s0, $zero, 0x58
    ctx->r16 = ADD32(0, 0X58);
    // 0x807B5CF4: addiu       $s1, $zero, 0x78
    ctx->r17 = ADD32(0, 0X78);
L_807B5CF8:
    // 0x807B5CF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5CFC: lhu         $a1, 0x2($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X2);
    // 0x807B5D00: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x807B5D04: jal         0x8005C27C
    // 0x807B5D08: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_13;
    // 0x807B5D08: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_13:
    // 0x807B5D0C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x807B5D10: bne         $s0, $s1, L_807B5CF8
    if (ctx->r16 != ctx->r17) {
        // 0x807B5D14: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_807B5CF8;
    }
    // 0x807B5D14: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807B5D18: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x807B5D1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807B5D20: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x807B5D24: jal         0x8005C27C
    // 0x807B5D28: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_8005C27C(rdram, ctx);
        goto after_14;
    // 0x807B5D28: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_14:
    // 0x807B5D2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B5D30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B5D34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B5D38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x807B5D3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x807B5D40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x807B5D44: jr          $ra
    // 0x807B5D48: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x807B5D48: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_80781260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80781260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80781264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80781268: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078126C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80781270: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80781274: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80781278: beql        $t6, $zero, L_80781298
    if (ctx->r14 == 0) {
        // 0x8078127C: lw          $t7, 0x8($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X8);
            goto L_80781298;
    }
    goto skip_0;
    // 0x8078127C: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    skip_0:
    // 0x80781280: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80781284: jal         0x80780DC4
    // 0x80781288: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_80780DC4(rdram, ctx);
        goto after_0;
    // 0x80781288: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8078128C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80781290: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80781294: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
L_80781298:
    // 0x80781298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8078129C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807812A0: lw          $t8, 0x180($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X180);
    // 0x807812A4: lw          $t9, 0x1F4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1F4);
    // 0x807812A8: lw          $t0, 0x48($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X48);
    // 0x807812AC: beql        $t0, $zero, L_807812C0
    if (ctx->r8 == 0) {
        // 0x807812B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807812C0;
    }
    goto skip_1;
    // 0x807812B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807812B4: jal         0x807813F0
    // 0x807812B8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    func_807813F0(rdram, ctx);
        goto after_1;
    // 0x807812B8: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_1:
    // 0x807812BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807812C0:
    // 0x807812C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807812C4: jr          $ra
    // 0x807812C8: nop

    return;
    // 0x807812C8: nop

;}
RECOMP_FUNC void func_80005AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005AEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80005AF0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80005AF4: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x80005AF8: addiu       $s6, $s6, 0x4D10
    ctx->r22 = ADD32(ctx->r22, 0X4D10);
    // 0x80005AFC: lw          $t6, 0x1D68($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X1D68);
    // 0x80005B00: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80005B04: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80005B08: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80005B0C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80005B10: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80005B14: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80005B18: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80005B1C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80005B20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005B24: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80005B28: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80005B2C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80005B30: blez        $t7, L_80005C7C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80005B34: sw          $t7, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r15;
            goto L_80005C7C;
    }
    // 0x80005B34: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x80005B38: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80005B3C: addiu       $fp, $zero, 0xFF
    ctx->r30 = ADD32(0, 0XFF);
    // 0x80005B40: addiu       $s7, $zero, 0x7F
    ctx->r23 = ADD32(0, 0X7F);
    // 0x80005B44: lw          $t9, 0x1D78($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X1D78);
L_80005B48:
    // 0x80005B48: lb          $a1, 0x2($s3)
    ctx->r5 = MEM_B(ctx->r19, 0X2);
    // 0x80005B4C: addu        $v0, $t9, $s4
    ctx->r2 = ADD32(ctx->r25, ctx->r20);
    // 0x80005B50: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x80005B54: lbu         $a0, 0x3($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X3);
    // 0x80005B58: beq         $v1, $fp, L_80005B68
    if (ctx->r3 == ctx->r30) {
        // 0x80005B5C: nop
    
            goto L_80005B68;
    }
    // 0x80005B5C: nop

    // 0x80005B60: beql        $v1, $a1, L_80005B80
    if (ctx->r3 == ctx->r5) {
        // 0x80005B64: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80005B80;
    }
    goto skip_0;
    // 0x80005B64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_0:
L_80005B68:
    // 0x80005B68: beq         $a0, $fp, L_80005B78
    if (ctx->r4 == ctx->r30) {
        // 0x80005B6C: nop
    
            goto L_80005B78;
    }
    // 0x80005B6C: nop

    // 0x80005B70: beql        $a0, $a1, L_80005B80
    if (ctx->r4 == ctx->r5) {
        // 0x80005B74: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80005B80;
    }
    goto skip_1;
    // 0x80005B74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_1:
L_80005B78:
    // 0x80005B78: bne         $a1, $zero, L_80005C68
    if (ctx->r5 != 0) {
        // 0x80005B7C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80005C68;
    }
    // 0x80005B7C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80005B80:
    // 0x80005B80: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80005B84: jal         0x80004160
    // 0x80005B88: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    func_80004160(rdram, ctx);
        goto after_0;
    // 0x80005B88: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80005B8C: beql        $v0, $zero, L_80005C6C
    if (ctx->r2 == 0) {
        // 0x80005B90: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_80005C6C;
    }
    goto skip_2;
    // 0x80005B90: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    skip_2:
    // 0x80005B94: jal         0x800066A8
    // 0x80005B98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_800066A8(rdram, ctx);
        goto after_1;
    // 0x80005B98: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x80005B9C: beql        $v0, $zero, L_80005C6C
    if (ctx->r2 == 0) {
        // 0x80005BA0: lw          $t0, 0x40($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X40);
            goto L_80005C6C;
    }
    goto skip_3;
    // 0x80005BA0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    skip_3:
    // 0x80005BA4: lw          $t0, 0x1D78($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X1D78);
    // 0x80005BA8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80005BAC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80005BB0: addu        $v0, $t0, $s4
    ctx->r2 = ADD32(ctx->r8, ctx->r20);
    // 0x80005BB4: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80005BB8: blez        $t1, L_80005C28
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80005BBC: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80005C28;
    }
    // 0x80005BBC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80005BC0:
    // 0x80005BC0: jal         0x8000B808
    // 0x80005BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8000B808(rdram, ctx);
        goto after_2;
    // 0x80005BC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x80005BC8: beq         $v0, $zero, L_80005C0C
    if (ctx->r2 == 0) {
        // 0x80005BCC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80005C0C;
    }
    // 0x80005BCC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80005BD0: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x80005BD4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005BD8: beql        $t2, $zero, L_80005BEC
    if (ctx->r10 == 0) {
        // 0x80005BDC: lbu         $t3, 0x2($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X2);
            goto L_80005BEC;
    }
    goto skip_4;
    // 0x80005BDC: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
    skip_4:
    // 0x80005BE0: jal         0x80005CAC
    // 0x80005BE4: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    func_80005CAC(rdram, ctx);
        goto after_3;
    // 0x80005BE4: lw          $a1, 0x8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8);
    after_3:
    // 0x80005BE8: lbu         $t3, 0x2($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X2);
L_80005BEC:
    // 0x80005BEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005BF0: beql        $s7, $t3, L_80005C04
    if (ctx->r23 == ctx->r11) {
        // 0x80005BF4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80005C04;
    }
    goto skip_5;
    // 0x80005BF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    skip_5:
    // 0x80005BF8: jal         0x80005CAC
    // 0x80005BFC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    func_80005CAC(rdram, ctx);
        goto after_4;
    // 0x80005BFC: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    after_4:
    // 0x80005C00: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80005C04:
    // 0x80005C04: jal         0x80005CAC
    // 0x80005C08: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    func_80005CAC(rdram, ctx);
        goto after_5;
    // 0x80005C08: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    after_5:
L_80005C0C:
    // 0x80005C0C: lw          $t4, 0x1D78($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X1D78);
    // 0x80005C10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80005C14: addu        $v0, $t4, $s4
    ctx->r2 = ADD32(ctx->r12, ctx->r20);
    // 0x80005C18: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80005C1C: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80005C20: bnel        $at, $zero, L_80005BC0
    if (ctx->r1 != 0) {
        // 0x80005C24: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80005BC0;
    }
    goto skip_6;
    // 0x80005C24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_6:
L_80005C28:
    // 0x80005C28: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80005C2C: blez        $t6, L_80005C68
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80005C30: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80005C68;
    }
    // 0x80005C30: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_80005C34:
    // 0x80005C34: jal         0x8000B8DC
    // 0x80005C38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    func_8000B8DC(rdram, ctx);
        goto after_6;
    // 0x80005C38: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_6:
    // 0x80005C3C: beq         $v0, $zero, L_80005C4C
    if (ctx->r2 == 0) {
        // 0x80005C40: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80005C4C;
    }
    // 0x80005C40: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80005C44: jal         0x80005CAC
    // 0x80005C48: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    func_80005CAC(rdram, ctx);
        goto after_7;
    // 0x80005C48: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    after_7:
L_80005C4C:
    // 0x80005C4C: lw          $t7, 0x1D78($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X1D78);
    // 0x80005C50: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80005C54: addu        $t8, $t7, $s4
    ctx->r24 = ADD32(ctx->r15, ctx->r20);
    // 0x80005C58: lbu         $t9, 0x1($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1);
    // 0x80005C5C: slt         $at, $s2, $t9
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80005C60: bnel        $at, $zero, L_80005C34
    if (ctx->r1 != 0) {
        // 0x80005C64: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80005C34;
    }
    goto skip_7;
    // 0x80005C64: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    skip_7:
L_80005C68:
    // 0x80005C68: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
L_80005C6C:
    // 0x80005C6C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80005C70: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x80005C74: bnel        $s5, $t0, L_80005B48
    if (ctx->r21 != ctx->r8) {
        // 0x80005C78: lw          $t9, 0x1D78($s6)
        ctx->r25 = MEM_W(ctx->r22, 0X1D78);
            goto L_80005B48;
    }
    goto skip_8;
    // 0x80005C78: lw          $t9, 0x1D78($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X1D78);
    skip_8:
L_80005C7C:
    // 0x80005C7C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80005C80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80005C84: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80005C88: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80005C8C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80005C90: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80005C94: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80005C98: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80005C9C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80005CA0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80005CA4: jr          $ra
    // 0x80005CA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80005CA8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8003CA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003CA60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CA64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003CA68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003CA6C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8003CA70: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003CA74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003CA78: jal         0x8003C9C8
    // 0x8003CA7C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_8003C9C8(rdram, ctx);
        goto after_0;
    // 0x8003CA7C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8003CA80: bne         $v0, $zero, L_8003CA90
    if (ctx->r2 != 0) {
        // 0x8003CA84: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003CA90;
    }
    // 0x8003CA84: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003CA88: b           L_8003CC00
    // 0x8003CA8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003CC00;
    // 0x8003CA8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003CA90:
    // 0x8003CA90: jal         0x80047090
    // 0x8003CA94: addiu       $a0, $zero, 0x400B
    ctx->r4 = ADD32(0, 0X400B);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x8003CA94: addiu       $a0, $zero, 0x400B
    ctx->r4 = ADD32(0, 0X400B);
    after_1:
    // 0x8003CA98: lhu         $t0, 0xE($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0XE);
    // 0x8003CA9C: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x8003CAA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003CAA4: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x8003CAA8: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8003CAAC: jal         0x8003C9C8
    // 0x8003CAB0: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    func_8003C9C8(rdram, ctx);
        goto after_2;
    // 0x8003CAB0: sh          $t2, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r10;
    after_2:
    // 0x8003CAB4: bne         $v0, $zero, L_8003CACC
    if (ctx->r2 != 0) {
        // 0x8003CAB8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003CACC;
    }
    // 0x8003CAB8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003CABC: jal         0x800445A4
    // 0x8003CAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_3;
    // 0x8003CAC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8003CAC4: b           L_8003CC00
    // 0x8003CAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003CC00;
    // 0x8003CAC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003CACC:
    // 0x8003CACC: jal         0x80047090
    // 0x8003CAD0: addiu       $a0, $zero, 0x400C
    ctx->r4 = ADD32(0, 0X400C);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x8003CAD0: addiu       $a0, $zero, 0x400C
    ctx->r4 = ADD32(0, 0X400C);
    after_4:
    // 0x8003CAD4: lhu         $t5, 0xE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XE);
    // 0x8003CAD8: andi        $t4, $v0, 0x3FF
    ctx->r12 = ctx->r2 & 0X3FF;
    // 0x8003CADC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003CAE0: andi        $t6, $t5, 0xFC00
    ctx->r14 = ctx->r13 & 0XFC00;
    // 0x8003CAE4: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x8003CAE8: sh          $t7, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r15;
    // 0x8003CAEC: jal         0x80047F9C
    // 0x8003CAF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8003CAF0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x8003CAF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003CAF8: jal         0x80047F9C
    // 0x8003CAFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8003CAFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x8003CB00: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8003CB04: sw          $s1, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->r17;
    // 0x8003CB08: jal         0x80056564
    // 0x8003CB0C: sw          $s0, 0x160($v0)
    MEM_W(0X160, ctx->r2) = ctx->r16;
    func_80056564(rdram, ctx);
        goto after_7;
    // 0x8003CB0C: sw          $s0, 0x160($v0)
    MEM_W(0X160, ctx->r2) = ctx->r16;
    after_7:
    // 0x8003CB10: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003CB14: jal         0x80056564
    // 0x8003CB18: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    func_80056564(rdram, ctx);
        goto after_8;
    // 0x8003CB18: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    after_8:
    // 0x8003CB1C: lw          $t0, 0x1F4($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003CB20: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8003CB24: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003CB28: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8003CB2C: beq         $a0, $zero, L_8003CB48
    if (ctx->r4 == 0) {
        // 0x8003CB30: nop
    
            goto L_8003CB48;
    }
    // 0x8003CB30: nop

    // 0x8003CB34: lw          $t1, 0x1F4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003CB38: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003CB3C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8003CB40: bne         $t2, $zero, L_8003CB70
    if (ctx->r10 != 0) {
        // 0x8003CB44: nop
    
            goto L_8003CB70;
    }
    // 0x8003CB44: nop

L_8003CB48:
    // 0x8003CB48: jal         0x800568E0
    // 0x8003CB4C: nop

    func_800568E0(rdram, ctx);
        goto after_9;
    // 0x8003CB4C: nop

    after_9:
    // 0x8003CB50: lw          $t3, 0x1F4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003CB54: jal         0x800568E0
    // 0x8003CB58: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    func_800568E0(rdram, ctx);
        goto after_10;
    // 0x8003CB58: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_10:
    // 0x8003CB5C: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003CB60: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8003CB64: lw          $t4, 0x1F4($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003CB68: b           L_8003CBFC
    // 0x8003CB6C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_8003CBFC;
    // 0x8003CB6C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8003CB70:
    // 0x8003CB70: jal         0x800457A0
    // 0x8003CB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800457A0(rdram, ctx);
        goto after_11;
    // 0x8003CB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003CB78: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x8003CB7C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8003CB80: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003CB84: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x8003CB88: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003CB8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003CB90: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003CB94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003CB98: jal         0x80056584
    // 0x8003CB9C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80056584(rdram, ctx);
        goto after_12;
    // 0x8003CB9C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_12:
    // 0x8003CBA0: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8003CBA4: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8003CBA8: addiu       $v0, $v0, 0x784C
    ctx->r2 = ADD32(ctx->r2, 0X784C);
    // 0x8003CBAC: sw          $v0, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r2;
    // 0x8003CBB0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8003CBB4: jal         0x8005FDC4
    // 0x8003CBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_13;
    // 0x8003CBB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8003CBBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003CBC0: jal         0x800457A0
    // 0x8003CBC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_14;
    // 0x8003CBC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_14:
    // 0x8003CBC8: lw          $t9, 0x1F4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X1F4);
    // 0x8003CBCC: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x8003CBD0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003CBD4: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8003CBD8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8003CBDC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003CBE0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003CBE4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8003CBE8: jal         0x80056584
    // 0x8003CBEC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    func_80056584(rdram, ctx);
        goto after_15;
    // 0x8003CBEC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_15:
    // 0x8003CBF0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x8003CBF4: lw          $t5, 0x16C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X16C);
    // 0x8003CBF8: sw          $t3, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r11;
L_8003CBFC:
    // 0x8003CBFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003CC00:
    // 0x8003CC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003CC04: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003CC08: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003CC0C: jr          $ra
    // 0x8003CC10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003CC10: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80051504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051504: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80051508: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005150C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80051510: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80051514: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80051518: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005151C: lhu         $a1, 0x3C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X3C);
    // 0x80051520: addiu       $a0, $a0, 0xA50
    ctx->r4 = ADD32(ctx->r4, 0XA50);
    // 0x80051524: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80051528: bne         $a1, $at, L_80051540
    if (ctx->r5 != ctx->r1) {
        // 0x8005152C: nop
    
            goto L_80051540;
    }
    // 0x8005152C: nop

    // 0x80051530: jal         0x80071380
    // 0x80051534: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80051534: addiu       $a1, $zero, 0x13B
    ctx->r5 = ADD32(0, 0X13B);
    after_0:
    // 0x80051538: b           L_800515F8
    // 0x8005153C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800515F8;
    // 0x8005153C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051540:
    // 0x80051540: lw          $t6, -0x79D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X79D8);
    // 0x80051544: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80051548: addiu       $s0, $v1, 0x48
    ctx->r16 = ADD32(ctx->r3, 0X48);
    // 0x8005154C: beq         $t6, $at, L_8005155C
    if (ctx->r14 == ctx->r1) {
        // 0x80051550: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005155C;
    }
    // 0x80051550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051554: b           L_800515F8
    // 0x80051558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800515F8;
    // 0x80051558: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005155C:
    // 0x8005155C: jal         0x8005B134
    // 0x80051560: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8005B134(rdram, ctx);
        goto after_1;
    // 0x80051560: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x80051564: beq         $v0, $zero, L_800515CC
    if (ctx->r2 == 0) {
        // 0x80051568: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_800515CC;
    }
    // 0x80051568: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005156C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80051570: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80051574: beql        $v0, $zero, L_80051588
    if (ctx->r2 == 0) {
        // 0x80051578: lw          $t7, 0x40($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X40);
            goto L_80051588;
    }
    goto skip_0;
    // 0x80051578: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x8005157C: bnel        $v0, $at, L_800515D8
    if (ctx->r2 != ctx->r1) {
        // 0x80051580: lh          $t1, 0x0($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X0);
            goto L_800515D8;
    }
    goto skip_1;
    // 0x80051580: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    skip_1:
    // 0x80051584: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
L_80051588:
    // 0x80051588: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x8005158C: lbu         $a1, 0x20($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X20);
    // 0x80051590: lh          $a2, 0x34($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X34);
    // 0x80051594: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80051598: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005159C: lh          $t8, 0x2C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2C);
    // 0x800515A0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800515A4: lh          $t9, 0x2E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2E);
    // 0x800515A8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800515AC: lw          $t0, 0x30($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X30);
    // 0x800515B0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800515B4: jal         0x8005B8D4
    // 0x800515B8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    func_8005B8D4(rdram, ctx);
        goto after_2;
    // 0x800515B8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800515BC: bne         $v0, $zero, L_800515D4
    if (ctx->r2 != 0) {
        // 0x800515C0: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_800515D4;
    }
    // 0x800515C0: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800515C4: b           L_800515F8
    // 0x800515C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800515F8;
    // 0x800515C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800515CC:
    // 0x800515CC: b           L_800515F8
    // 0x800515D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800515F8;
    // 0x800515D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800515D4:
    // 0x800515D4: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
L_800515D8:
    // 0x800515D8: bnel        $t1, $zero, L_800515F8
    if (ctx->r9 != 0) {
        // 0x800515DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800515F8;
    }
    goto skip_2;
    // 0x800515DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_2:
    // 0x800515E0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800515E4: beql        $v0, $zero, L_800515F8
    if (ctx->r2 == 0) {
        // 0x800515E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800515F8;
    }
    goto skip_3;
    // 0x800515E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_3:
    // 0x800515EC: lw          $t2, 0x24($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X24);
    // 0x800515F0: sw          $t2, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->r10;
    // 0x800515F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800515F8:
    // 0x800515F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800515FC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80051600: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80051604: jr          $ra
    // 0x80051608: nop

    return;
    // 0x80051608: nop

;}
RECOMP_FUNC void func_805A54AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A54AC: lw          $v1, 0x14C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X14C);
    // 0x805A54B0: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(417, 0X14D0) << 16);
    // 0x805A54B4: lw          $v0, 0x154($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X154);
    // 0x805A54B8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x805A54BC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x805A54C0: lw          $t7, 0x6790($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(417, 0X14D0));
    // 0x805A54C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x805A54C8: lui         $t9, 0x805A
    ctx->r25 = S32(RELOC_HI16(417, 0X14C8) << 16);
    // 0x805A54CC: sltu        $at, $v0, $t7
    ctx->r1 = ctx->r2 < ctx->r15 ? 1 : 0;
    // 0x805A54D0: bnel        $at, $zero, L_805A54F0
    if (ctx->r1 != 0) {
        // 0x805A54D4: sll         $t8, $v1, 1
        ctx->r24 = S32(ctx->r3 << 1);
            goto L_805A54F0;
    }
    goto skip_0;
    // 0x805A54D4: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    skip_0:
    // 0x805A54D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x805A54DC: sltiu       $at, $v1, 0x4
    ctx->r1 = ctx->r3 < 0X4 ? 1 : 0;
    // 0x805A54E0: bne         $at, $zero, L_805A54EC
    if (ctx->r1 != 0) {
        // 0x805A54E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_805A54EC;
    }
    // 0x805A54E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805A54E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_805A54EC:
    // 0x805A54EC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
L_805A54F0:
    // 0x805A54F0: sw          $v0, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r2;
    // 0x805A54F4: sw          $v1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r3;
    // 0x805A54F8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x805A54FC: lh          $t9, 0x6788($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(417, 0X14C8));
    // 0x805A5500: jr          $ra
    // 0x805A5504: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
    return;
    // 0x805A5504: sh          $t9, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void func_8057BE88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057BE88: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8057BE8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057BE90: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x8057BE94: beql        $v1, $zero, L_8057BFDC
    if (ctx->r3 == 0) {
        // 0x8057BE98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057BFDC;
    }
    goto skip_0;
    // 0x8057BE98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057BE9C: lw          $a1, 0x174($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X174);
    // 0x8057BEA0: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x8057BEA4: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8057BEA8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8057BEAC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8057BEB0: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(387, 0XE98) << 16);
    // 0x8057BEB4: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8057BEB8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8057BEBC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8057BEC0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8057BEC4: lwc1        $f4, -0x3658($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(387, 0XE98));
    // 0x8057BEC8: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x8057BECC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8057BED0: lh          $t1, 0xA($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XA);
    // 0x8057BED4: lwc1        $f16, 0x84($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8057BED8: lwc1        $f2, 0x84($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057BEDC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8057BEE0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8057BEE4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8057BEE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8057BEEC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8057BEF0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8057BEF4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8057BEF8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8057BEFC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8057BF00: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8057BF04: jal         0x80065954
    // 0x8057BF08: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8057BF08: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    after_0:
    // 0x8057BF0C: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8057BF10: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8057BF14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8057BF18: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8057BF1C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8057BF20: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8057BF24: bc1fl       L_8057BFDC
    if (!c1cs) {
        // 0x8057BF28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057BFDC;
    }
    goto skip_1;
    // 0x8057BF28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057BF2C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8057BF30: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8057BF34: lwc1        $f16, 0x88($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8057BF38: lh          $t3, 0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6);
    // 0x8057BF3C: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x8057BF40: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x8057BF44: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8057BF48: lwc1        $f2, 0x88($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057BF4C: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8057BF50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8057BF54: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8057BF58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8057BF5C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8057BF60: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8057BF64: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8057BF68: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8057BF6C: jal         0x80065954
    // 0x8057BF70: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8057BF70: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    after_1:
    // 0x8057BF74: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8057BF78: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8057BF7C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8057BF80: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8057BF84: nop

    // 0x8057BF88: bc1fl       L_8057BFDC
    if (!c1cs) {
        // 0x8057BF8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057BFDC;
    }
    goto skip_2;
    // 0x8057BF8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8057BF90: sb          $zero, 0x17C($a0)
    MEM_B(0X17C, ctx->r4) = 0;
    // 0x8057BF94: lwc1        $f10, 0x84($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X84);
    // 0x8057BF98: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8057BF9C: lwc1        $f18, 0x88($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8057BFA0: lbu         $a1, 0x30($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X30);
    // 0x8057BFA4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057BFA8: lwc1        $f8, 0x8C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8C);
    // 0x8057BFAC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8057BFB0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8057BFB4: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
    // 0x8057BFB8: lwc1        $f6, 0x88($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8057BFBC: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8057BFC0: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
    // 0x8057BFC4: lwc1        $f10, 0x8C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8C);
    // 0x8057BFC8: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x8057BFCC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057BFD0: jal         0x8057C6B0
    // 0x8057BFD4: swc1        $f16, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f16.u32l;
    func_8057C6B0(rdram, ctx);
        goto after_2;
    // 0x8057BFD4: swc1        $f16, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f16.u32l;
    after_2:
    // 0x8057BFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057BFDC:
    // 0x8057BFDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8057BFE0: jr          $ra
    // 0x8057BFE4: nop

    return;
    // 0x8057BFE4: nop

;}
RECOMP_FUNC void func_80584D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80584D8C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584D90: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584D94: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584D98: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80584D9C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80584DA0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80584DA4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80584DA8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80584DAC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80584DB0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80584DB4: jr          $ra
    // 0x80584DB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80584DB8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80533B34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80533B34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80533B38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80533B3C: jal         0x80067E68
    // 0x80533B40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_0;
    // 0x80533B40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80533B44: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80533B48: jal         0x80067818
    // 0x80533B4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80533B4C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80533B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80533B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80533B58: jr          $ra
    // 0x80533B5C: nop

    return;
    // 0x80533B5C: nop

;}
RECOMP_FUNC void func_806F61C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F61C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806F61C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806F61C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806F61CC: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806F61D0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(685, 0X1190) << 16);
    // 0x806F61D4: addiu       $t6, $t6, 0x64F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(685, 0X1190));
    // 0x806F61D8: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806F61DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F61E0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806F61E4: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F61E8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806F61EC: sw          $zero, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = 0;
    // 0x806F61F0: sw          $zero, 0x134($a0)
    MEM_W(0X134, ctx->r4) = 0;
    // 0x806F61F4: sw          $zero, 0x138($a0)
    MEM_W(0X138, ctx->r4) = 0;
    // 0x806F61F8: sh          $zero, 0x144($a0)
    MEM_H(0X144, ctx->r4) = 0;
    // 0x806F61FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F6200: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    // 0x806F6204: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(685, 0X8C0) << 16);
    // 0x806F6208: addiu       $t8, $t8, 0x5C20
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(685, 0X8C0));
    // 0x806F620C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F6210: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806F6214: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806F6218: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x806F621C: jal         0x80045A34
    // 0x806F6220: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F6220: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x806F6224: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(685, 0XCCC) << 16);
    // 0x806F6228: addiu       $t9, $t9, 0x602C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(685, 0XCCC));
    // 0x806F622C: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806F6230: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x806F6234: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x806F6238: jal         0x80058958
    // 0x806F623C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    func_80058958(rdram, ctx);
        goto after_1;
    // 0x806F623C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // 0x806F6240: beq         $v0, $zero, L_806F62B8
    if (ctx->r2 == 0) {
        // 0x806F6244: lui         $t0, 0x8010
        ctx->r8 = S32(0X8010 << 16);
            goto L_806F62B8;
    }
    // 0x806F6244: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x806F6248: lw          $t0, -0x7BC4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7BC4);
    // 0x806F624C: lw          $t1, 0x10C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10C);
    // 0x806F6250: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x806F6254: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x806F6258: beql        $t3, $zero, L_806F62BC
    if (ctx->r11 == 0) {
        // 0x806F625C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_806F62BC;
    }
    goto skip_0;
    // 0x806F625C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x806F6260: jal         0x80056564
    // 0x806F6264: nop

    func_80056564(rdram, ctx);
        goto after_2;
    // 0x806F6264: nop

    after_2:
    // 0x806F6268: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x806F626C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F6270: beq         $v0, $zero, L_806F62B8
    if (ctx->r2 == 0) {
        // 0x806F6274: sw          $v0, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r2;
            goto L_806F62B8;
    }
    // 0x806F6274: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x806F6278: jal         0x800457A0
    // 0x806F627C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_3;
    // 0x806F627C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x806F6280: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x806F6284: addiu       $t6, $zero, 0x1F
    ctx->r14 = ADD32(0, 0X1F);
    // 0x806F6288: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x806F628C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x806F6290: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x806F6294: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x806F6298: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x806F629C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F62A0: jal         0x80056584
    // 0x806F62A4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80056584(rdram, ctx);
        goto after_4;
    // 0x806F62A4: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_4:
    // 0x806F62A8: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806F62AC: lui         $t8, 0x8005
    ctx->r24 = S32(0X8005 << 16);
    // 0x806F62B0: addiu       $t8, $t8, 0x784C
    ctx->r24 = ADD32(ctx->r24, 0X784C);
    // 0x806F62B4: sw          $t8, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->r24;
L_806F62B8:
    // 0x806F62B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806F62BC:
    // 0x806F62BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806F62C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806F62C4: jr          $ra
    // 0x806F62C8: nop

    return;
    // 0x806F62C8: nop

;}
RECOMP_FUNC void func_80433860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80433860: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80433864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80433868: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8043386C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80433870: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x80433874: lui         $t7, 0x8043
    ctx->r15 = S32(RELOC_HI16(68, 0X1F8) << 16);
    // 0x80433878: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8043387C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80433880: addiu       $t7, $t7, 0x3A28
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(68, 0X1F8));
    // 0x80433884: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80433888: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8043388C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80433890: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80433894: jal         0x804338B4
    // 0x80433898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804338B4(rdram, ctx);
        goto after_0;
    // 0x80433898: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8043389C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804338A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x804338A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804338A8: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x804338AC: jr          $ra
    // 0x804338B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804338B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_805813E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805813E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805813E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805813EC: jal         0x8058129C
    // 0x805813F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8058129C(rdram, ctx);
        goto after_0;
    // 0x805813F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805813F4: beq         $v0, $zero, L_80581410
    if (ctx->r2 == 0) {
        // 0x805813F8: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80581410;
    }
    // 0x805813F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805813FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581400: jal         0x805814C4
    // 0x80581404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_805814C4(rdram, ctx);
        goto after_1;
    // 0x80581404: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80581408: b           L_8058144C
    // 0x8058140C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8058144C;
    // 0x8058140C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581410:
    // 0x80581410: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80581414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80581418: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8058141C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581420: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80581424: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80581428: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8058142C: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80581430: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80581434: nop

    // 0x80581438: bc1fl       L_8058144C
    if (!c1cs) {
        // 0x8058143C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8058144C;
    }
    goto skip_0;
    // 0x8058143C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80581440: jal         0x800447C8
    // 0x80581444: nop

    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x80581444: nop

    after_2:
    // 0x80581448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8058144C:
    // 0x8058144C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581450: jr          $ra
    // 0x80581454: nop

    return;
    // 0x80581454: nop

;}
RECOMP_FUNC void func_804C5A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5A20: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C5A24: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x804C5A28: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x804C5A2C: lw          $t9, 0x18($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X18);
    // 0x804C5A30: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804C5A34: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x804C5A38: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
    // 0x804C5A3C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x804C5A40: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x804C5A44: sltu        $at, $t7, $t2
    ctx->r1 = ctx->r15 < ctx->r10 ? 1 : 0;
    // 0x804C5A48: bnel        $at, $zero, L_804C5A78
    if (ctx->r1 != 0) {
        // 0x804C5A4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804C5A78;
    }
    goto skip_0;
    // 0x804C5A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804C5A50: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x804C5A54: addiu       $t3, $v0, 0x1
    ctx->r11 = ADD32(ctx->r2, 0X1);
    // 0x804C5A58: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x804C5A5C: sltu        $at, $t3, $t5
    ctx->r1 = ctx->r11 < ctx->r13 ? 1 : 0;
    // 0x804C5A60: bne         $at, $zero, L_804C5A6C
    if (ctx->r1 != 0) {
        // 0x804C5A64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_804C5A6C;
    }
    // 0x804C5A64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804C5A68: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
L_804C5A6C:
    // 0x804C5A6C: jr          $ra
    // 0x804C5A70: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    return;
    // 0x804C5A70: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x804C5A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C5A78:
    // 0x804C5A78: jr          $ra
    // 0x804C5A7C: nop

    return;
    // 0x804C5A7C: nop

;}
RECOMP_FUNC void func_80452834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452834: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452838: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045283C: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x80452840: jal         0x804527B0
    // 0x80452844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804527B0(rdram, ctx);
        goto after_0;
    // 0x80452844: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80452848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045284C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80452850: jr          $ra
    // 0x80452854: nop

    return;
    // 0x80452854: nop

;}
RECOMP_FUNC void func_805A3558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A3558: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A355C: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A3560: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x805A3564: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x805A3568: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805A356C: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x805A3570: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x805A3574: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x805A3578: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A357C: lui         $t1, 0xBF00
    ctx->r9 = S32(0XBF00 << 16);
    // 0x805A3580: addiu       $t9, $zero, 0x204
    ctx->r25 = ADD32(0, 0X204);
    // 0x805A3584: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x805A3588: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x805A358C: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x805A3590: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x805A3594: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x805A3598: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x805A359C: ori         $t3, $t3, 0x604
    ctx->r11 = ctx->r11 | 0X604;
    // 0x805A35A0: addiu       $t2, $a2, 0x8
    ctx->r10 = ADD32(ctx->r6, 0X8);
    // 0x805A35A4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x805A35A8: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x805A35AC: jr          $ra
    // 0x805A35B0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    return;
    // 0x805A35B0: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
;}
RECOMP_FUNC void func_8003BF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BF28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BF2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BF30: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003BF34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003BF38: lw          $t6, 0x7C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X7C);
    // 0x8003BF3C: beq         $t6, $zero, L_8003BF78
    if (ctx->r14 == 0) {
        // 0x8003BF40: nop
    
            goto L_8003BF78;
    }
    // 0x8003BF40: nop

    // 0x8003BF44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003BF48: jal         0x80021A44
    // 0x8003BF4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80021A44(rdram, ctx);
        goto after_0;
    // 0x8003BF4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003BF50: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BF54: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003BF58: lw          $t9, 0xA8($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XA8);
    // 0x8003BF5C: jalr        $t9
    // 0x8003BF60: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8003BF60: nop

    after_1:
    // 0x8003BF64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BF68: jal         0x8002EFD0
    // 0x8003BF6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002EFD0(rdram, ctx);
        goto after_2;
    // 0x8003BF6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8003BF70: b           L_8003BF78
    // 0x8003BF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003BF78;
    // 0x8003BF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003BF78:
    // 0x8003BF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BF7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003BF80: jr          $ra
    // 0x8003BF84: nop

    return;
    // 0x8003BF84: nop

;}
RECOMP_FUNC void func_805AE4A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE4A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE4A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE4AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE4B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE4B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE4B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE4BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE4C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE4C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE4C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE4CC: jr          $ra
    // 0x805AE4D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE4D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805190BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805190BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805190C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805190C4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x805190C8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x805190CC: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(291, 0X2560) << 16);
    // 0x805190D0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x805190D4: lw          $v0, -0x5E30($v0)
    ctx->r2 = MEM_W(ctx->r2, (int16_t)RELOC_LO16(291, 0X2560));
    // 0x805190D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805190DC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x805190E0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x805190E4: beql        $v1, $zero, L_80519118
    if (ctx->r3 == 0) {
        // 0x805190E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80519118;
    }
    goto skip_0;
    // 0x805190E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805190EC: jalr        $v1
    // 0x805190F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x805190F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805190F4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805190F8: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x805190FC: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x80519100: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80519104: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x80519108: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8051910C: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x80519110: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    // 0x80519114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519118:
    // 0x80519118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051911C: jr          $ra
    // 0x80519120: nop

    return;
    // 0x80519120: nop

;}
RECOMP_FUNC void func_806E69A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E69A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x806E69AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x806E69B0: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x806E69B4: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x806E69B8: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x806E69BC: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x806E69C0: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x806E69C4: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x806E69C8: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x806E69CC: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x806E69D0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x806E69D4: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x806E69D8: jal         0x80045A34
    // 0x806E69DC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806E69DC: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_0:
    // 0x806E69E0: bne         $v0, $zero, L_806E69F8
    if (ctx->r2 != 0) {
        // 0x806E69E4: sw          $v0, 0x1F4($s4)
        MEM_W(0X1F4, ctx->r20) = ctx->r2;
            goto L_806E69F8;
    }
    // 0x806E69E4: sw          $v0, 0x1F4($s4)
    MEM_W(0X1F4, ctx->r20) = ctx->r2;
    // 0x806E69E8: jal         0x800445A4
    // 0x806E69EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806E69EC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x806E69F0: b           L_806E6B9C
    // 0x806E69F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_806E6B9C;
    // 0x806E69F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_806E69F8:
    // 0x806E69F8: lw          $t7, 0x16C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X16C);
    // 0x806E69FC: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(655, 0XF54) << 16);
    // 0x806E6A00: sw          $zero, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = 0;
    // 0x806E6A04: sb          $zero, 0x165($s4)
    MEM_B(0X165, ctx->r20) = 0;
    // 0x806E6A08: addiu       $t6, $t6, 0x6C14
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(655, 0XF54));
    // 0x806E6A0C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E6A10: lw          $s5, 0x1F4($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X1F4);
    // 0x806E6A14: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x806E6A18: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x806E6A1C: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x806E6A20: sw          $t8, 0x124($s4)
    MEM_W(0X124, ctx->r20) = ctx->r24;
    // 0x806E6A24: sw          $t9, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r25;
    // 0x806E6A28: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x806E6A2C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x806E6A30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806E6A34: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(655, 0XF60) << 16);
    // 0x806E6A38: lui         $a0, 0x806E
    ctx->r4 = S32(RELOC_HI16(655, 0XFE0) << 16);
    // 0x806E6A3C: addiu       $a0, $a0, 0x6CA0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(655, 0XFE0));
    // 0x806E6A40: addiu       $v0, $v0, 0x6C20
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(655, 0XF60));
    // 0x806E6A44: sw          $t0, 0x3C($s5)
    MEM_W(0X3C, ctx->r21) = ctx->r8;
    // 0x806E6A48: sh          $zero, 0x2C($s5)
    MEM_H(0X2C, ctx->r21) = 0;
    // 0x806E6A4C: sh          $t1, 0x2E($s5)
    MEM_H(0X2E, ctx->r21) = ctx->r9;
    // 0x806E6A50: sw          $zero, 0x44($s5)
    MEM_W(0X44, ctx->r21) = 0;
    // 0x806E6A54: sw          $zero, 0x38($s5)
    MEM_W(0X38, ctx->r21) = 0;
    // 0x806E6A58: sw          $zero, 0x40($s5)
    MEM_W(0X40, ctx->r21) = 0;
    // 0x806E6A5C: addiu       $v1, $s5, 0x48
    ctx->r3 = ADD32(ctx->r21, 0X48);
    // 0x806E6A60: swc1        $f24, 0x34($s5)
    MEM_W(0X34, ctx->r21) = ctx->f24.u32l;
    // 0x806E6A64: swc1        $f24, 0x30($s5)
    MEM_W(0X30, ctx->r21) = ctx->f24.u32l;
L_806E6A68:
    // 0x806E6A68: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x806E6A6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x806E6A70: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x806E6A74: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x806E6A78: lw          $t2, -0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, -0XC);
    // 0x806E6A7C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E6A80: sw          $t2, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r10;
    // 0x806E6A84: lw          $t3, -0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, -0X8);
    // 0x806E6A88: sw          $t3, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r11;
    // 0x806E6A8C: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x806E6A90: bne         $at, $zero, L_806E6A68
    if (ctx->r1 != 0) {
        // 0x806E6A94: sw          $t2, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r10;
            goto L_806E6A68;
    }
    // 0x806E6A94: sw          $t2, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r10;
    // 0x806E6A98: lw          $t5, 0x16C($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X16C);
    // 0x806E6A9C: lui         $t4, 0x806E
    ctx->r12 = S32(RELOC_HI16(655, 0X664) << 16);
    // 0x806E6AA0: addiu       $t4, $t4, 0x6324
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(655, 0X664));
    // 0x806E6AA4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E6AA8: jal         0x806E630C
    // 0x806E6AAC: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    func_806E630C(rdram, ctx);
        goto after_2;
    // 0x806E6AAC: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    after_2:
    // 0x806E6AB0: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X10A0) << 16);
    // 0x806E6AB4: lwc1        $f22, 0x6D60($at)
    ctx->f22.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X10A0));
    // 0x806E6AB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x806E6ABC: lui         $s2, 0x45C4
    ctx->r18 = S32(0X45C4 << 16);
    // 0x806E6AC0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x806E6AC4: ori         $s2, $s2, 0x2000
    ctx->r18 = ctx->r18 | 0X2000;
    // 0x806E6AC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x806E6ACC: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
    // 0x806E6AD0: addiu       $s3, $zero, 0x28
    ctx->r19 = ADD32(0, 0X28);
L_806E6AD4:
    // 0x806E6AD4: jal         0x80047090
    // 0x806E6AD8: addiu       $a0, $zero, 0x45C4
    ctx->r4 = ADD32(0, 0X45C4);
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x806E6AD8: addiu       $a0, $zero, 0x45C4
    ctx->r4 = ADD32(0, 0X45C4);
    after_3:
    // 0x806E6ADC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806E6AE0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x806E6AE4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x806E6AE8: jal         0x8004613C
    // 0x806E6AEC: or          $a0, $v0, $s2
    ctx->r4 = ctx->r2 | ctx->r18;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x806E6AEC: or          $a0, $v0, $s2
    ctx->r4 = ctx->r2 | ctx->r18;
    after_4:
    // 0x806E6AF0: bne         $v0, $zero, L_806E6B08
    if (ctx->r2 != 0) {
        // 0x806E6AF4: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_806E6B08;
    }
    // 0x806E6AF4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x806E6AF8: jal         0x800445A4
    // 0x806E6AFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806E6AFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x806E6B00: b           L_806E6B9C
    // 0x806E6B04: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_806E6B9C;
    // 0x806E6B04: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_806E6B08:
    // 0x806E6B08: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E6B0C: jal         0x80047F9C
    // 0x806E6B10: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x806E6B10: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_6:
    // 0x806E6B14: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x806E6B18: bne         $s1, $s3, L_806E6AD4
    if (ctx->r17 != ctx->r19) {
        // 0x806E6B1C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_806E6AD4;
    }
    // 0x806E6B1C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x806E6B20: jal         0x80047090
    // 0x806E6B24: addiu       $a0, $zero, 0x45C1
    ctx->r4 = ADD32(0, 0X45C1);
    func_80047090(rdram, ctx);
        goto after_7;
    // 0x806E6B24: addiu       $a0, $zero, 0x45C1
    ctx->r4 = ADD32(0, 0X45C1);
    after_7:
    // 0x806E6B28: lui         $at, 0x45C1
    ctx->r1 = S32(0X45C1 << 16);
    // 0x806E6B2C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x806E6B30: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x806E6B34: lui         $a3, 0xBDCC
    ctx->r7 = S32(0XBDCC << 16);
    // 0x806E6B38: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x806E6B3C: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x806E6B40: jal         0x8004613C
    // 0x806E6B44: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x806E6B44: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    after_8:
    // 0x806E6B48: bne         $v0, $zero, L_806E6B60
    if (ctx->r2 != 0) {
        // 0x806E6B4C: sw          $v0, 0x28($s5)
        MEM_W(0X28, ctx->r21) = ctx->r2;
            goto L_806E6B60;
    }
    // 0x806E6B4C: sw          $v0, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->r2;
    // 0x806E6B50: jal         0x800445A4
    // 0x806E6B54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x806E6B54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x806E6B58: b           L_806E6B9C
    // 0x806E6B5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_806E6B9C;
    // 0x806E6B5C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_806E6B60:
    // 0x806E6B60: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E6B64: jal         0x80047F9C
    // 0x806E6B68: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x806E6B68: lw          $a1, 0x28($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X28);
    after_10:
    // 0x806E6B6C: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(655, 0X10A4) << 16);
    // 0x806E6B70: lwc1        $f4, 0x6D64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(655, 0X10A4));
    // 0x806E6B74: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x806E6B78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806E6B7C: addiu       $v0, $s4, 0xC4
    ctx->r2 = ADD32(ctx->r20, 0XC4);
    // 0x806E6B80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x806E6B84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E6B88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806E6B8C: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x806E6B90: jal         0x806E6BC8
    // 0x806E6B94: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    func_806E6BC8(rdram, ctx);
        goto after_11;
    // 0x806E6B94: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    after_11:
    // 0x806E6B98: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_806E6B9C:
    // 0x806E6B9C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x806E6BA0: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x806E6BA4: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x806E6BA8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x806E6BAC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x806E6BB0: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x806E6BB4: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x806E6BB8: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x806E6BBC: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x806E6BC0: jr          $ra
    // 0x806E6BC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x806E6BC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8043EF40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043EF40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043EF44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043EF48: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x8043EF4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8043EF50: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043EF54: beq         $a1, $at, L_8043EF70
    if (ctx->r5 == ctx->r1) {
        // 0x8043EF58: addiu       $a0, $zero, 0x56
        ctx->r4 = ADD32(0, 0X56);
            goto L_8043EF70;
    }
    // 0x8043EF58: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x8043EF5C: jal         0x80067878
    // 0x8043EF60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8043EF60: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8043EF64: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8043EF68: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8043EF6C: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_8043EF70:
    // 0x8043EF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043EF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043EF78: jr          $ra
    // 0x8043EF7C: nop

    return;
    // 0x8043EF7C: nop

;}
RECOMP_FUNC void func_805A7504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A7504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805A7508: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A750C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A7510: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805A7514: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A7518: beql        $v0, $zero, L_805A756C
    if (ctx->r2 == 0) {
        // 0x805A751C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A756C;
    }
    goto skip_0;
    // 0x805A751C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x805A7520: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x805A7524: beql        $a3, $zero, L_805A756C
    if (ctx->r7 == 0) {
        // 0x805A7528: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A756C;
    }
    goto skip_1;
    // 0x805A7528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x805A752C: lw          $t6, 0x180($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X180);
    // 0x805A7530: bne         $a0, $t6, L_805A7568
    if (ctx->r4 != ctx->r14) {
        // 0x805A7534: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_805A7568;
    }
    // 0x805A7534: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805A7538: jal         0x8004816C
    // 0x805A753C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x805A753C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x805A7540: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x805A7544: addiu       $t7, $t7, -0x7218
    ctx->r15 = ADD32(ctx->r15, -0X7218);
    // 0x805A7548: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x805A754C: lw          $a0, 0x1D8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1D8);
    // 0x805A7550: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x805A7554: jal         0x80048C18
    // 0x805A7558: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    func_80048C18(rdram, ctx);
        goto after_1;
    // 0x805A7558: lw          $a2, 0x88($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X88);
    after_1:
    // 0x805A755C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A7560: jal         0x80048C00
    // 0x805A7564: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80048C00(rdram, ctx);
        goto after_2;
    // 0x805A7564: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
L_805A7568:
    // 0x805A7568: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A756C:
    // 0x805A756C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A7570: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805A7574: jr          $ra
    // 0x805A7578: nop

    return;
    // 0x805A7578: nop

;}
RECOMP_FUNC void func_800313E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800313E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800313E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800313E8: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x800313EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800313F0: jal         0x800310A0
    // 0x800313F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x800313F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800313F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800313FC: jal         0x80030EE8
    // 0x80031400: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_80030EE8(rdram, ctx);
        goto after_1;
    // 0x80031400: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80031404: beq         $v0, $zero, L_80031414
    if (ctx->r2 == 0) {
        // 0x80031408: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80031414;
    }
    // 0x80031408: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003140C: jal         0x800310D0
    // 0x80031410: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800310D0(rdram, ctx);
        goto after_2;
    // 0x80031410: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
L_80031414:
    // 0x80031414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031418: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003141C: jr          $ra
    // 0x80031420: nop

    return;
    // 0x80031420: nop

;}
RECOMP_FUNC void func_807AE0E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE0E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE0E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE0E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807AE0EC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE0F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807AE0F4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x807AE0F8: swc1        $f0, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f0.u32l;
    // 0x807AE0FC: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x807AE100: jal         0x807AEA24
    // 0x807AE104: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    func_807AEA24(rdram, ctx);
        goto after_0;
    // 0x807AE104: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
    after_0:
    // 0x807AE108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE10C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE110: jr          $ra
    // 0x807AE114: nop

    return;
    // 0x807AE114: nop

;}
RECOMP_FUNC void func_8041FCC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FCC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041FCC4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041FCC8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8041FCCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8041FCD0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8041FCD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8041FCD8: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8041FCDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041FCE0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8041FCE4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8041FCE8: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041FCEC: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x8041FCF0: jal         0x8041DB1C
    // 0x8041FCF4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041FCF4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8041FCF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FCFC: jal         0x8041E9A8
    // 0x8041FD00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041FD00: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8041FD04: beq         $v0, $zero, L_8041FDFC
    if (ctx->r2 == 0) {
        // 0x8041FD08: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8041FDFC;
    }
    // 0x8041FD08: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8041FD0C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X353C) << 16);
    // 0x8041FD10: lwc1        $f2, 0xB9C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X353C));
    // 0x8041FD14: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041FD18: lwc1        $f0, 0x40($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8041FD1C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3540) << 16);
    // 0x8041FD20: mul.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8041FD24: lwc1        $f14, 0xBA0($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3540));
    // 0x8041FD28: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8041FD2C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3548) << 16);
    // 0x8041FD30: add.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8041FD34: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8041FD38: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8041FD3C: nop

    // 0x8041FD40: bc1f        L_8041FDC0
    if (!c1cs) {
        // 0x8041FD44: nop
    
            goto L_8041FDC0;
    }
    // 0x8041FD44: nop

    // 0x8041FD48: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3544) << 16);
    // 0x8041FD4C: lwc1        $f12, 0xBA4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3544));
    // 0x8041FD50: lwc1        $f6, 0x6C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8041FD54: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8041FD58: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8041FD5C: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x8041FD60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FD64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FD68: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8041FD6C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x8041FD70: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8041FD74: lwc1        $f10, 0x70($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X70);
    // 0x8041FD78: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8041FD7C: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x8041FD80: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x8041FD84: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8041FD88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8041FD8C: bc1fl       L_8041FDB4
    if (!c1cs) {
        // 0x8041FD90: swc1        $f6, 0x6C($v1)
        MEM_W(0X6C, ctx->r3) = ctx->f6.u32l;
            goto L_8041FDB4;
    }
    goto skip_0;
    // 0x8041FD90: swc1        $f6, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f6.u32l;
    skip_0:
    // 0x8041FD94: swc1        $f2, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f2.u32l;
    // 0x8041FD98: swc1        $f2, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f2.u32l;
    // 0x8041FD9C: sh          $t6, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r14;
    // 0x8041FDA0: jal         0x8041FE10
    // 0x8041FDA4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_2;
    // 0x8041FDA4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8041FDA8: b           L_8041FDE0
    // 0x8041FDAC: nop

        goto L_8041FDE0;
    // 0x8041FDAC: nop

    // 0x8041FDB0: swc1        $f6, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f6.u32l;
L_8041FDB4:
    // 0x8041FDB4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8041FDB8: b           L_8041FDE0
    // 0x8041FDBC: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
        goto L_8041FDE0;
    // 0x8041FDBC: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
L_8041FDC0:
    // 0x8041FDC0: lwc1        $f12, 0xBA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3548));
    // 0x8041FDC4: lwc1        $f10, 0x6C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X6C);
    // 0x8041FDC8: lwc1        $f18, 0x70($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X70);
    // 0x8041FDCC: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8041FDD0: add.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8041FDD4: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8041FDD8: swc1        $f16, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = ctx->f16.u32l;
    // 0x8041FDDC: swc1        $f4, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f4.u32l;
L_8041FDE0:
    // 0x8041FDE0: jal         0x8041F594
    // 0x8041FDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_3;
    // 0x8041FDE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8041FDE8: jal         0x8041E5E8
    // 0x8041FDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_4;
    // 0x8041FDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8041FDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FDF4: jal         0x8041E430
    // 0x8041FDF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8041E430(rdram, ctx);
        goto after_5;
    // 0x8041FDF8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
L_8041FDFC:
    // 0x8041FDFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FE00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8041FE04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8041FE08: jr          $ra
    // 0x8041FE0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8041FE0C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80526CFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526CFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526D00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526D04: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80526D08: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80526D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80526D10: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80526D14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80526D18: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80526D1C: nop

    // 0x80526D20: bc1fl       L_80526DCC
    if (!c1cs) {
        // 0x80526D24: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80526DCC;
    }
    goto skip_0;
    // 0x80526D24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80526D28: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80526D2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80526D30: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80526D34: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80526D38: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80526D3C: bne         $at, $zero, L_80526DAC
    if (ctx->r1 != 0) {
        // 0x80526D40: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80526DAC;
    }
    // 0x80526D40: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80526D44: lw          $t8, 0x78($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X78);
    // 0x80526D48: blezl       $t8, L_80526D70
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80526D4C: lhu         $v0, 0xC($a0)
        ctx->r2 = MEM_HU(ctx->r4, 0XC);
            goto L_80526D70;
    }
    goto skip_1;
    // 0x80526D4C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    skip_1:
    // 0x80526D50: lw          $t0, 0x78($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X78);
    // 0x80526D54: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x80526D58: sw          $zero, 0x10($a1)
    MEM_W(0X10, ctx->r5) = 0;
    // 0x80526D5C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80526D60: sw          $t1, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r9;
    // 0x80526D64: b           L_80526DD8
    // 0x80526D68: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_80526DD8;
    // 0x80526D68: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80526D6C: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
L_80526D70:
    // 0x80526D70: addiu       $at, $zero, 0x41ED
    ctx->r1 = ADD32(0, 0X41ED);
    // 0x80526D74: beq         $v0, $at, L_80526D9C
    if (ctx->r2 == ctx->r1) {
        // 0x80526D78: addiu       $at, $zero, 0x41EF
        ctx->r1 = ADD32(0, 0X41EF);
            goto L_80526D9C;
    }
    // 0x80526D78: addiu       $at, $zero, 0x41EF
    ctx->r1 = ADD32(0, 0X41EF);
    // 0x80526D7C: beq         $v0, $at, L_80526D9C
    if (ctx->r2 == ctx->r1) {
        // 0x80526D80: addiu       $at, $zero, 0x41F0
        ctx->r1 = ADD32(0, 0X41F0);
            goto L_80526D9C;
    }
    // 0x80526D80: addiu       $at, $zero, 0x41F0
    ctx->r1 = ADD32(0, 0X41F0);
    // 0x80526D84: bne         $v0, $at, L_80526D9C
    if (ctx->r2 != ctx->r1) {
        // 0x80526D88: nop
    
            goto L_80526D9C;
    }
    // 0x80526D88: nop

    // 0x80526D8C: jal         0x80526CDC
    // 0x80526D90: nop

    func_80526CDC(rdram, ctx);
        goto after_0;
    // 0x80526D90: nop

    after_0:
    // 0x80526D94: b           L_80526DDC
    // 0x80526D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526DDC;
    // 0x80526D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526D9C:
    // 0x80526D9C: jal         0x80526C90
    // 0x80526DA0: nop

    func_80526C90(rdram, ctx);
        goto after_1;
    // 0x80526DA0: nop

    after_1:
    // 0x80526DA4: b           L_80526DDC
    // 0x80526DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80526DDC;
    // 0x80526DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526DAC:
    // 0x80526DAC: lw          $t2, 0x4($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X4);
    // 0x80526DB0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80526DB4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80526DB8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80526DBC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80526DC0: b           L_80526DD8
    // 0x80526DC4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_80526DD8;
    // 0x80526DC4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x80526DC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80526DCC:
    // 0x80526DCC: nop

    // 0x80526DD0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80526DD4: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80526DD8:
    // 0x80526DD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80526DDC:
    // 0x80526DDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526DE0: jr          $ra
    // 0x80526DE4: nop

    return;
    // 0x80526DE4: nop

;}
RECOMP_FUNC void func_80565A8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80565A8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80565A90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80565A94: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80565A98: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80565A9C: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(369, 0X2470) << 16);
    // 0x80565AA0: addiu       $t6, $t6, 0x5CD0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(369, 0X2470));
    // 0x80565AA4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80565AA8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80565AAC: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x80565AB0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80565AB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80565AB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80565ABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80565AC0: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80565AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80565AC8: jal         0x80565C28
    // 0x80565ACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80565C28(rdram, ctx);
        goto after_0;
    // 0x80565ACC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80565AD0: lw          $t2, 0x16C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X16C);
    // 0x80565AD4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80565AD8: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(369, 0X4A4) << 16);
    // 0x80565ADC: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x80565AE0: addiu       $t1, $t1, 0x3D04
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(369, 0X4A4));
    // 0x80565AE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80565AE8: jal         0x80565A74
    // 0x80565AEC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    func_80565A74(rdram, ctx);
        goto after_1;
    // 0x80565AEC: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    after_1:
    // 0x80565AF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80565AF4: jal         0x80045A34
    // 0x80565AF8: addiu       $a1, $zero, 0x530
    ctx->r5 = ADD32(0, 0X530);
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x80565AF8: addiu       $a1, $zero, 0x530
    ctx->r5 = ADD32(0, 0X530);
    after_2:
    // 0x80565AFC: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80565B00: jal         0x80565910
    // 0x80565B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80565910(rdram, ctx);
        goto after_3;
    // 0x80565B04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80565B08: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x80565B0C: addiu       $at, $zero, 0x413D
    ctx->r1 = ADD32(0, 0X413D);
    // 0x80565B10: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80565B14: beq         $v0, $at, L_80565B2C
    if (ctx->r2 == ctx->r1) {
        // 0x80565B18: addiu       $at, $zero, 0x4552
        ctx->r1 = ADD32(0, 0X4552);
            goto L_80565B2C;
    }
    // 0x80565B18: addiu       $at, $zero, 0x4552
    ctx->r1 = ADD32(0, 0X4552);
    // 0x80565B1C: beql        $v0, $at, L_80565BA8
    if (ctx->r2 == ctx->r1) {
        // 0x80565B20: lui         $at, 0x4290
        ctx->r1 = S32(0X4290 << 16);
            goto L_80565BA8;
    }
    goto skip_0;
    // 0x80565B20: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    skip_0:
    // 0x80565B24: b           L_80565C18
    // 0x80565B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80565C18;
    // 0x80565B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80565B2C:
    // 0x80565B2C: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x80565B30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80565B34: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80565B38: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80565B3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80565B40: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80565B44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80565B48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80565B4C: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80565B50: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80565B54: jal         0x800653D8
    // 0x80565B58: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x80565B58: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80565B5C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80565B60: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80565B64: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80565B68: lui         $t4, 0x8056
    ctx->r12 = S32(RELOC_HI16(369, 0X24B0) << 16);
    // 0x80565B6C: lui         $t5, 0x8056
    ctx->r13 = S32(RELOC_HI16(369, 0X2498) << 16);
    // 0x80565B70: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(369, 0X24C4) << 16);
    // 0x80565B74: mfhi        $t3
    ctx->r11 = hi;
    // 0x80565B78: addiu       $t4, $t4, 0x5D10
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(369, 0X24B0));
    // 0x80565B7C: addiu       $t5, $t5, 0x5CF8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(369, 0X2498));
    // 0x80565B80: addiu       $t6, $t6, 0x5D24
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(369, 0X24C4));
    // 0x80565B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80565B88: sw          $t3, 0x51C($v1)
    MEM_W(0X51C, ctx->r3) = ctx->r11;
    // 0x80565B8C: sw          $t4, 0x524($v1)
    MEM_W(0X524, ctx->r3) = ctx->r12;
    // 0x80565B90: sw          $t5, 0x520($v1)
    MEM_W(0X520, ctx->r3) = ctx->r13;
    // 0x80565B94: jal         0x80563D64
    // 0x80565B98: sw          $t6, 0x528($v1)
    MEM_W(0X528, ctx->r3) = ctx->r14;
    func_80563D64(rdram, ctx);
        goto after_5;
    // 0x80565B98: sw          $t6, 0x528($v1)
    MEM_W(0X528, ctx->r3) = ctx->r14;
    after_5:
    // 0x80565B9C: b           L_80565C18
    // 0x80565BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80565C18;
    // 0x80565BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80565BA4: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
L_80565BA8:
    // 0x80565BA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80565BAC: lui         $at, 0x4308
    ctx->r1 = S32(0X4308 << 16);
    // 0x80565BB0: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80565BB4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80565BB8: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80565BBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80565BC0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80565BC4: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x80565BC8: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80565BCC: jal         0x800653D8
    // 0x80565BD0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800653D8(rdram, ctx);
        goto after_6;
    // 0x80565BD0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x80565BD4: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80565BD8: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80565BDC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80565BE0: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(369, 0X2500) << 16);
    // 0x80565BE4: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(369, 0X24E8) << 16);
    // 0x80565BE8: lui         $t0, 0x8056
    ctx->r8 = S32(RELOC_HI16(369, 0X2514) << 16);
    // 0x80565BEC: mfhi        $t7
    ctx->r15 = hi;
    // 0x80565BF0: addiu       $t8, $t8, 0x5D60
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(369, 0X2500));
    // 0x80565BF4: addiu       $t9, $t9, 0x5D48
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(369, 0X24E8));
    // 0x80565BF8: addiu       $t0, $t0, 0x5D74
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(369, 0X2514));
    // 0x80565BFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80565C00: sw          $t7, 0x51C($v1)
    MEM_W(0X51C, ctx->r3) = ctx->r15;
    // 0x80565C04: sw          $t8, 0x524($v1)
    MEM_W(0X524, ctx->r3) = ctx->r24;
    // 0x80565C08: sw          $t9, 0x520($v1)
    MEM_W(0X520, ctx->r3) = ctx->r25;
    // 0x80565C0C: jal         0x80563D64
    // 0x80565C10: sw          $t0, 0x528($v1)
    MEM_W(0X528, ctx->r3) = ctx->r8;
    func_80563D64(rdram, ctx);
        goto after_7;
    // 0x80565C10: sw          $t0, 0x528($v1)
    MEM_W(0X528, ctx->r3) = ctx->r8;
    after_7:
    // 0x80565C14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80565C18:
    // 0x80565C18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80565C1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80565C20: jr          $ra
    // 0x80565C24: nop

    return;
    // 0x80565C24: nop

;}
RECOMP_FUNC void func_8079B770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079B770: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079B774: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079B778: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8079B77C: addiu       $at, $zero, 0x41A7
    ctx->r1 = ADD32(0, 0X41A7);
    // 0x8079B780: lui         $t6, 0x807A
    ctx->r14 = S32(RELOC_HI16(829, 0XA30) << 16);
    // 0x8079B784: beq         $v0, $at, L_8079B79C
    if (ctx->r2 == ctx->r1) {
        // 0x8079B788: addiu       $at, $zero, 0x46B1
        ctx->r1 = ADD32(0, 0X46B1);
            goto L_8079B79C;
    }
    // 0x8079B788: addiu       $at, $zero, 0x46B1
    ctx->r1 = ADD32(0, 0X46B1);
    // 0x8079B78C: beq         $v0, $at, L_8079B7D4
    if (ctx->r2 == ctx->r1) {
        // 0x8079B790: nop
    
            goto L_8079B7D4;
    }
    // 0x8079B790: nop

    // 0x8079B794: b           L_8079B7E0
    // 0x8079B798: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(829, 0X904) << 16);
        goto L_8079B7E0;
    // 0x8079B798: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(829, 0X904) << 16);
L_8079B79C:
    // 0x8079B79C: lw          $t6, -0x3E60($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(829, 0XA30));
    // 0x8079B7A0: lui         $a0, 0x807A
    ctx->r4 = S32(RELOC_HI16(829, 0XC20) << 16);
    // 0x8079B7A4: addiu       $a0, $a0, -0x3C70
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(829, 0XC20));
    // 0x8079B7A8: bne         $t6, $zero, L_8079B7C8
    if (ctx->r14 != 0) {
        // 0x8079B7AC: lui         $a1, 0x807A
        ctx->r5 = S32(RELOC_HI16(829, 0XC30) << 16);
            goto L_8079B7C8;
    }
    // 0x8079B7AC: lui         $a1, 0x807A
    ctx->r5 = S32(RELOC_HI16(829, 0XC30) << 16);
    // 0x8079B7B0: addiu       $a1, $a1, -0x3C60
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(829, 0XC30));
    // 0x8079B7B4: jal         0x8004667C
    // 0x8079B7B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x8079B7B8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x8079B7BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8079B7C0: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(829, 0XA30) << 16);
    // 0x8079B7C4: sw          $t7, -0x3E60($at)
    MEM_W((int16_t)RELOC_LO16(829, 0XA30), ctx->r1) = ctx->r15;
L_8079B7C8:
    // 0x8079B7C8: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(829, 0X904) << 16);
    // 0x8079B7CC: b           L_8079B7E4
    // 0x8079B7D0: addiu       $v0, $v0, -0x3F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(829, 0X904));
        goto L_8079B7E4;
    // 0x8079B7D0: addiu       $v0, $v0, -0x3F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(829, 0X904));
L_8079B7D4:
    // 0x8079B7D4: lui         $v0, 0x807A
    ctx->r2 = S32(RELOC_HI16(829, 0X938) << 16);
    // 0x8079B7D8: b           L_8079B7E4
    // 0x8079B7DC: addiu       $v0, $v0, -0x3F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(829, 0X938));
        goto L_8079B7E4;
    // 0x8079B7DC: addiu       $v0, $v0, -0x3F58
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(829, 0X938));
L_8079B7E0:
    // 0x8079B7E0: addiu       $v0, $v0, -0x3F8C
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(829, 0X904));
L_8079B7E4:
    // 0x8079B7E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079B7E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079B7EC: jr          $ra
    // 0x8079B7F0: nop

    return;
    // 0x8079B7F0: nop

;}
RECOMP_FUNC void func_800336A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800336A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800336AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800336B0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x800336B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800336B8: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x800336BC: andi        $t7, $t6, 0x700
    ctx->r15 = ctx->r14 & 0X700;
    // 0x800336C0: beq         $t7, $zero, L_80033740
    if (ctx->r15 == 0) {
        // 0x800336C4: nop
    
            goto L_80033740;
    }
    // 0x800336C4: nop

    // 0x800336C8: lwc1        $f12, 0x60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X60);
    // 0x800336CC: lwc1        $f2, 0xC4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800336D0: lwc1        $f4, 0x120($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X120);
    // 0x800336D4: lwc1        $f6, 0x68($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800336D8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800336DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800336E0: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800336E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800336E8: bc1t        L_80033750
    if (c1cs) {
        // 0x800336EC: nop
    
            goto L_80033750;
    }
    // 0x800336EC: nop

    // 0x800336F0: lwc1        $f8, 0x64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X64);
    // 0x800336F4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800336F8: nop

    // 0x800336FC: bc1t        L_80033750
    if (c1cs) {
        // 0x80033700: nop
    
            goto L_80033750;
    }
    // 0x80033700: nop

    // 0x80033704: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80033708: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8003370C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80033710: nop

    // 0x80033714: bc1t        L_80033750
    if (c1cs) {
        // 0x80033718: nop
    
            goto L_80033750;
    }
    // 0x80033718: nop

    // 0x8003371C: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80033720: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80033724: nop

    // 0x80033728: bc1t        L_80033750
    if (c1cs) {
        // 0x8003372C: nop
    
            goto L_80033750;
    }
    // 0x8003372C: nop

    // 0x80033730: jal         0x8002D958
    // 0x80033734: nop

    func_8002D958(rdram, ctx);
        goto after_0;
    // 0x80033734: nop

    after_0:
    // 0x80033738: b           L_80033750
    // 0x8003373C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033750;
    // 0x8003373C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033740:
    // 0x80033740: jal         0x8002D9A8
    // 0x80033744: nop

    func_8002D9A8(rdram, ctx);
        goto after_1;
    // 0x80033744: nop

    after_1:
    // 0x80033748: b           L_80033750
    // 0x8003374C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80033750;
    // 0x8003374C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80033750:
    // 0x80033750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033758: jr          $ra
    // 0x8003375C: nop

    return;
    // 0x8003375C: nop

;}
RECOMP_FUNC void func_80530A0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80530A0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80530A10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80530A14: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80530A18: lwc1        $f0, 0x40($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80530A1C: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(339, 0X430) << 16);
    // 0x80530A20: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80530A24: lwc1        $f8, 0xD50($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(339, 0X430));
    // 0x80530A28: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80530A2C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80530A30: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80530A34: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x80530A38: swc1        $f18, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f18.u32l;
    // 0x80530A3C: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80530A40: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80530A44: jal         0x8053096C
    // 0x80530A48: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    func_8053096C(rdram, ctx);
        goto after_0;
    // 0x80530A48: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    after_0:
    // 0x80530A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80530A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80530A54: jr          $ra
    // 0x80530A58: nop

    return;
    // 0x80530A58: nop

;}
RECOMP_FUNC void func_805227D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805227D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805227D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805227DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x805227E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x805227E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x805227E8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805227EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x805227F0: jal         0x8004700C
    // 0x805227F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805227F4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x805227F8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x805227FC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80522800: beq         $v0, $zero, L_80522938
    if (ctx->r2 == 0) {
        // 0x80522804: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80522938;
    }
    // 0x80522804: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80522808: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8052280C: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x80522810: lw          $a2, 0x1F4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1F4);
    // 0x80522814: lhu         $t7, 0xC($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC);
    // 0x80522818: bnel        $t7, $at, L_8052293C
    if (ctx->r15 != ctx->r1) {
        // 0x8052281C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052293C;
    }
    goto skip_0;
    // 0x8052281C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80522820: lbu         $t8, 0x165($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X165);
    // 0x80522824: bnel        $t8, $zero, L_8052293C
    if (ctx->r24 != 0) {
        // 0x80522828: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8052293C;
    }
    goto skip_1;
    // 0x80522828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8052282C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80522830: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80522834: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80522838: bne         $t9, $zero, L_80522938
    if (ctx->r25 != 0) {
        // 0x8052283C: addiu       $a3, $zero, 0x2
        ctx->r7 = ADD32(0, 0X2);
            goto L_80522938;
    }
    // 0x8052283C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80522840: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80522844: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x80522848: lw          $t1, 0xE88($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XE88);
    // 0x8052284C: addiu       $t2, $zero, 0x11
    ctx->r10 = ADD32(0, 0X11);
    // 0x80522850: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80522854: sw          $a3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r7;
    // 0x80522858: sw          $a3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r7;
    // 0x8052285C: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x80522860: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80522864: jal         0x80523830
    // 0x80522868: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80523830(rdram, ctx);
        goto after_1;
    // 0x80522868: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8052286C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80522870: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80522874: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80522878: lw          $t3, 0x20($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X20);
    // 0x8052287C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80522880: beql        $t3, $zero, L_80522908
    if (ctx->r11 == 0) {
        // 0x80522884: lw          $t0, 0xE88($v0)
        ctx->r8 = MEM_W(ctx->r2, 0XE88);
            goto L_80522908;
    }
    goto skip_2;
    // 0x80522884: lw          $t0, 0xE88($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE88);
    skip_2:
    // 0x80522888: lw          $t4, 0xF70($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XF70);
    // 0x8052288C: andi        $t9, $zero, 0xFF
    ctx->r25 = 0 & 0XFF;
    // 0x80522890: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x80522894: lw          $t5, 0x12EC($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X12EC);
    // 0x80522898: beq         $t5, $zero, L_805228E4
    if (ctx->r13 == 0) {
        // 0x8052289C: nop
    
            goto L_805228E4;
    }
    // 0x8052289C: nop

    // 0x805228A0: lbu         $t6, 0x12E8($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X12E8);
    // 0x805228A4: lw          $t8, 0xE88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XE88);
    // 0x805228A8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x805228AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805228B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x805228B4: bne         $t9, $at, L_805228CC
    if (ctx->r25 != ctx->r1) {
        // 0x805228B8: sb          $zero, 0x12E8($a2)
        MEM_B(0X12E8, ctx->r6) = 0;
            goto L_805228CC;
    }
    // 0x805228B8: sb          $zero, 0x12E8($a2)
    MEM_B(0X12E8, ctx->r6) = 0;
    // 0x805228BC: jal         0x800677F8
    // 0x805228C0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800677F8(rdram, ctx);
        goto after_2;
    // 0x805228C0: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_2:
    // 0x805228C4: b           L_805228D4
    // 0x805228C8: nop

        goto L_805228D4;
    // 0x805228C8: nop

L_805228CC:
    // 0x805228CC: jal         0x800677F8
    // 0x805228D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x805228D0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_3:
L_805228D4:
    // 0x805228D4: jal         0x8002FEF8
    // 0x805228D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FEF8(rdram, ctx);
        goto after_4;
    // 0x805228D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x805228DC: b           L_805228F4
    // 0x805228E0: nop

        goto L_805228F4;
    // 0x805228E0: nop

L_805228E4:
    // 0x805228E4: jal         0x800677F8
    // 0x805228E8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    func_800677F8(rdram, ctx);
        goto after_5;
    // 0x805228E8: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    after_5:
    // 0x805228EC: jal         0x8002FF38
    // 0x805228F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FF38(rdram, ctx);
        goto after_6;
    // 0x805228F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
L_805228F4:
    // 0x805228F4: jal         0x80522574
    // 0x805228F8: nop

    func_80522574(rdram, ctx);
        goto after_7;
    // 0x805228F8: nop

    after_7:
    // 0x805228FC: b           L_8052293C
    // 0x80522900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8052293C;
    // 0x80522900: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80522904: lw          $t0, 0xE88($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XE88);
L_80522908:
    // 0x80522908: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8052290C: slti        $at, $t1, 0x7
    ctx->r1 = SIGNED(ctx->r9) < 0X7 ? 1 : 0;
    // 0x80522910: beq         $at, $zero, L_80522928
    if (ctx->r1 == 0) {
        // 0x80522914: nop
    
            goto L_80522928;
    }
    // 0x80522914: nop

    // 0x80522918: jal         0x800677F8
    // 0x8052291C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_800677F8(rdram, ctx);
        goto after_8;
    // 0x8052291C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_8:
    // 0x80522920: b           L_80522930
    // 0x80522924: nop

        goto L_80522930;
    // 0x80522924: nop

L_80522928:
    // 0x80522928: jal         0x800677F8
    // 0x8052292C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    func_800677F8(rdram, ctx);
        goto after_9;
    // 0x8052292C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_9:
L_80522930:
    // 0x80522930: jal         0x8002FEF8
    // 0x80522934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8002FEF8(rdram, ctx);
        goto after_10;
    // 0x80522934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_10:
L_80522938:
    // 0x80522938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8052293C:
    // 0x8052293C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80522940: jr          $ra
    // 0x80522944: nop

    return;
    // 0x80522944: nop

;}
RECOMP_FUNC void func_8078E0A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078E0A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078E0A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078E0A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078E0AC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8078E0B0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8078E0B4: jal         0x8004700C
    // 0x8078E0B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8078E0B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8078E0BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8078E0C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8078E0C4: jal         0x80062AEC
    // 0x8078E0C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80062AEC(rdram, ctx);
        goto after_1;
    // 0x8078E0C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8078E0CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8078E0D0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8078E0D4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8078E0D8: bne         $v1, $zero, L_8078E0EC
    if (ctx->r3 != 0) {
        // 0x8078E0DC: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8078E0EC;
    }
    // 0x8078E0DC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8078E0E0: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x8078E0E4: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8078E0E8: beq         $t6, $at, L_8078E334
    if (ctx->r14 == ctx->r1) {
        // 0x8078E0EC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8078E334;
    }
L_8078E0EC:
    // 0x8078E0EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078E0F0: beq         $v0, $at, L_8078E11C
    if (ctx->r2 == ctx->r1) {
        // 0x8078E0F4: lw          $a0, 0x24($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X24);
            goto L_8078E11C;
    }
    // 0x8078E0F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8078E0F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8078E0FC: beq         $v0, $at, L_8078E1A0
    if (ctx->r2 == ctx->r1) {
        // 0x8078E100: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8078E1A0;
    }
    // 0x8078E100: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8078E104: beq         $v0, $at, L_8078E2B0
    if (ctx->r2 == ctx->r1) {
        // 0x8078E108: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8078E2B0;
    }
    // 0x8078E108: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8078E10C: beq         $v0, $at, L_8078E224
    if (ctx->r2 == ctx->r1) {
        // 0x8078E110: nop
    
            goto L_8078E224;
    }
    // 0x8078E110: nop

    // 0x8078E114: b           L_8078E338
    // 0x8078E118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078E338;
    // 0x8078E118: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E11C:
    // 0x8078E11C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA74) << 16);
    // 0x8078E120: lwc1        $f4, -0x166C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA74));
    // 0x8078E124: lwc1        $f6, 0xC4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8078E128: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8078E12C: nop

    // 0x8078E130: bc1fl       L_8078E160
    if (!c1cs) {
        // 0x8078E134: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_8078E160;
    }
    goto skip_0;
    // 0x8078E134: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_0:
    // 0x8078E138: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8078E13C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8078E140: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E144: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078E148: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078E14C: lwc1        $f6, 0x3C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8078E150: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8078E154: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8078E158: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8078E15C: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_8078E160:
    // 0x8078E160: lui         $at, 0xF
    ctx->r1 = S32(0XF << 16);
    // 0x8078E164: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x8078E168: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8078E16C: sw          $t8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r24;
    // 0x8078E170: lbu         $t9, 0x18($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X18);
    // 0x8078E174: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8078E178: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8078E17C: beql        $t9, $at, L_8078E198
    if (ctx->r25 == ctx->r1) {
        // 0x8078E180: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8078E198;
    }
    goto skip_1;
    // 0x8078E180: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_1:
    // 0x8078E184: jal         0x8002F6E4
    // 0x8078E188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_2;
    // 0x8078E188: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8078E18C: b           L_8078E338
    // 0x8078E190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078E338;
    // 0x8078E190: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078E194: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8078E198:
    // 0x8078E198: b           L_8078E334
    // 0x8078E19C: swc1        $f10, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f10.u32l;
        goto L_8078E334;
    // 0x8078E19C: swc1        $f10, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f10.u32l;
L_8078E1A0:
    // 0x8078E1A0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA78) << 16);
    // 0x8078E1A4: lwc1        $f18, -0x1668($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA78));
    // 0x8078E1A8: lwc1        $f16, 0xC4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8078E1AC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8078E1B0: nop

    // 0x8078E1B4: bc1fl       L_8078E1E4
    if (!c1cs) {
        // 0x8078E1B8: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_8078E1E4;
    }
    goto skip_2;
    // 0x8078E1B8: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_2:
    // 0x8078E1BC: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8078E1C0: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8078E1C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E1C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078E1CC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8078E1D0: lwc1        $f18, 0x3C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x8078E1D4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078E1D8: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8078E1DC: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x8078E1E0: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_8078E1E4:
    // 0x8078E1E4: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x8078E1E8: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x8078E1EC: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8078E1F0: sw          $t1, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r9;
    // 0x8078E1F4: lbu         $t2, 0x18($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X18);
    // 0x8078E1F8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8078E1FC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8078E200: beql        $t2, $at, L_8078E21C
    if (ctx->r10 == ctx->r1) {
        // 0x8078E204: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8078E21C;
    }
    goto skip_3;
    // 0x8078E204: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x8078E208: jal         0x8002F6E4
    // 0x8078E20C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_3;
    // 0x8078E20C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8078E210: b           L_8078E338
    // 0x8078E214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078E338;
    // 0x8078E214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078E218: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8078E21C:
    // 0x8078E21C: b           L_8078E334
    // 0x8078E220: swc1        $f4, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f4.u32l;
        goto L_8078E334;
    // 0x8078E220: swc1        $f4, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f4.u32l;
L_8078E224:
    // 0x8078E224: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA7C) << 16);
    // 0x8078E228: lwc1        $f8, -0x1664($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA7C));
    // 0x8078E22C: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x8078E230: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8078E234: nop

    // 0x8078E238: bc1fl       L_8078E280
    if (!c1cs) {
        // 0x8078E23C: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_8078E280;
    }
    goto skip_4;
    // 0x8078E23C: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_4:
    // 0x8078E240: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8078E244: lwc1        $f16, 0x4($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8078E248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E24C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8078E250: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8078E254: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8078E258: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8078E25C: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA80) << 16);
    // 0x8078E260: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8078E264: swc1        $f16, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f16.u32l;
    // 0x8078E268: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8078E26C: swc1        $f10, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f10.u32l;
    // 0x8078E270: lwc1        $f18, -0x1660($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA80));
    // 0x8078E274: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8078E278: swc1        $f6, 0xC8($v1)
    MEM_W(0XC8, ctx->r3) = ctx->f6.u32l;
    // 0x8078E27C: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_8078E280:
    // 0x8078E280: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8078E284: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x8078E288: ori         $t4, $t3, 0x3000
    ctx->r12 = ctx->r11 | 0X3000;
    // 0x8078E28C: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8078E290: lbu         $t5, 0x18($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X18);
    // 0x8078E294: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8078E298: beql        $t5, $at, L_8078E338
    if (ctx->r13 == ctx->r1) {
        // 0x8078E29C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078E338;
    }
    goto skip_5;
    // 0x8078E29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8078E2A0: jal         0x8002F6E4
    // 0x8078E2A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_4;
    // 0x8078E2A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8078E2A8: b           L_8078E338
    // 0x8078E2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8078E338;
    // 0x8078E2AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E2B0:
    // 0x8078E2B0: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA84) << 16);
    // 0x8078E2B4: lwc1        $f4, -0x165C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA84));
    // 0x8078E2B8: lwc1        $f0, 0xC8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x8078E2BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8078E2C0: nop

    // 0x8078E2C4: bc1fl       L_8078E30C
    if (!c1cs) {
        // 0x8078E2C8: lw          $v0, 0x1F4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X1F4);
            goto L_8078E30C;
    }
    goto skip_6;
    // 0x8078E2C8: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    skip_6:
    // 0x8078E2CC: lwc1        $f8, 0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8078E2D0: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8078E2D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078E2D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8078E2DC: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8078E2E0: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x8078E2E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8078E2E8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(808, 0XA88) << 16);
    // 0x8078E2EC: sub.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8078E2F0: swc1        $f10, 0xC4($v1)
    MEM_W(0XC4, ctx->r3) = ctx->f10.u32l;
    // 0x8078E2F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8078E2F8: swc1        $f8, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f8.u32l;
    // 0x8078E2FC: lwc1        $f16, -0x1658($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(808, 0XA88));
    // 0x8078E300: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8078E304: swc1        $f18, 0xC8($v1)
    MEM_W(0XC8, ctx->r3) = ctx->f18.u32l;
    // 0x8078E308: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
L_8078E30C:
    // 0x8078E30C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8078E310: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x8078E314: ori         $t7, $t6, 0x700
    ctx->r15 = ctx->r14 | 0X700;
    // 0x8078E318: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
    // 0x8078E31C: lbu         $t8, 0x18($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18);
    // 0x8078E320: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8078E324: beql        $t8, $at, L_8078E338
    if (ctx->r24 == ctx->r1) {
        // 0x8078E328: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078E338;
    }
    goto skip_7;
    // 0x8078E328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8078E32C: jal         0x8002F6E4
    // 0x8078E330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8002F6E4(rdram, ctx);
        goto after_5;
    // 0x8078E330: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
L_8078E334:
    // 0x8078E334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8078E338:
    // 0x8078E338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078E33C: jr          $ra
    // 0x8078E340: nop

    return;
    // 0x8078E340: nop

;}
RECOMP_FUNC void func_805A65C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A65C0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805A65C4: lui         $t6, 0x805A
    ctx->r14 = S32(RELOC_HI16(417, 0X498) << 16);
    // 0x805A65C8: addiu       $t6, $t6, 0x5758
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(417, 0X498));
    // 0x805A65CC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805A65D0: jr          $ra
    // 0x805A65D4: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x805A65D4: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8073741C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073741C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80737420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80737424: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80737428: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073742C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80737430: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80737434: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80737438: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8073743C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80737440: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80737444: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80737448: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8073744C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80737450: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80737454: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80737458: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8073745C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80737460: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80737464: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80737468: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8073746C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80737470: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80737474: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80737478: jalr        $t9
    // 0x8073747C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8073747C: nop

    after_0:
    // 0x80737480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80737484: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80737488: jr          $ra
    // 0x8073748C: nop

    return;
    // 0x8073748C: nop

;}
RECOMP_FUNC void func_806E7C68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7C70: jal         0x8004700C
    // 0x806E7C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806E7C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806E7C78: beq         $v0, $zero, L_806E7D98
    if (ctx->r2 == 0) {
        // 0x806E7C7C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_806E7D98;
    }
    // 0x806E7C7C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806E7C80: lhu         $t6, 0xC($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0XC);
    // 0x806E7C84: addiu       $at, $zero, 0x4689
    ctx->r1 = ADD32(0, 0X4689);
    // 0x806E7C88: bnel        $t6, $at, L_806E7D9C
    if (ctx->r14 != ctx->r1) {
        // 0x806E7C8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7D9C;
    }
    goto skip_0;
    // 0x806E7C8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806E7C90: lbu         $t7, 0x18($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18);
    // 0x806E7C94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806E7C98: bnel        $t7, $at, L_806E7D9C
    if (ctx->r15 != ctx->r1) {
        // 0x806E7C9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7D9C;
    }
    goto skip_1;
    // 0x806E7C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x806E7CA0: lbu         $t8, 0x30($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X30);
    // 0x806E7CA4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x806E7CA8: bnel        $t8, $at, L_806E7D9C
    if (ctx->r24 != ctx->r1) {
        // 0x806E7CAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7D9C;
    }
    goto skip_2;
    // 0x806E7CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x806E7CB0: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806E7CB4: lwc1        $f6, 0x84($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X84);
    // 0x806E7CB8: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(664, 0XEFC) << 16);
    // 0x806E7CBC: lwc1        $f8, -0x7EC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(664, 0XEFC));
    // 0x806E7CC0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806E7CC4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x806E7CC8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x806E7CCC: nop

    // 0x806E7CD0: bc1fl       L_806E7D9C
    if (!c1cs) {
        // 0x806E7CD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7D9C;
    }
    goto skip_3;
    // 0x806E7CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x806E7CD8: lw          $t9, 0x174($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X174);
    // 0x806E7CDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x806E7CE0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x806E7CE4: andi        $t1, $t0, 0xF00
    ctx->r9 = ctx->r8 & 0XF00;
    // 0x806E7CE8: beql        $t1, $zero, L_806E7D9C
    if (ctx->r9 == 0) {
        // 0x806E7CEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806E7D9C;
    }
    goto skip_4;
    // 0x806E7CEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x806E7CF0: jal         0x806E77D4
    // 0x806E7CF4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_806E77D4(rdram, ctx);
        goto after_1;
    // 0x806E7CF4: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_1:
    // 0x806E7CF8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806E7CFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x806E7D00: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x806E7D04: addiu       $a0, $zero, 0x4027
    ctx->r4 = ADD32(0, 0X4027);
    // 0x806E7D08: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_806E7D0C:
    // 0x806E7D0C: lw          $v0, 0x188($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X188);
    // 0x806E7D10: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x806E7D14: beql        $v0, $zero, L_806E7D30
    if (ctx->r2 == 0) {
        // 0x806E7D18: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E7D30;
    }
    goto skip_5;
    // 0x806E7D18: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_5:
    // 0x806E7D1C: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7D20: bnel        $a0, $t2, L_806E7D30
    if (ctx->r4 != ctx->r10) {
        // 0x806E7D24: lw          $v0, 0x18C($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18C);
            goto L_806E7D30;
    }
    goto skip_6;
    // 0x806E7D24: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
    skip_6:
    // 0x806E7D28: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E7D2C: lw          $v0, 0x18C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18C);
L_806E7D30:
    // 0x806E7D30: beql        $v0, $zero, L_806E7D4C
    if (ctx->r2 == 0) {
        // 0x806E7D34: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E7D4C;
    }
    goto skip_7;
    // 0x806E7D34: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_7:
    // 0x806E7D38: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7D3C: bnel        $a0, $t3, L_806E7D4C
    if (ctx->r4 != ctx->r11) {
        // 0x806E7D40: lw          $v0, 0x190($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X190);
            goto L_806E7D4C;
    }
    goto skip_8;
    // 0x806E7D40: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
    skip_8:
    // 0x806E7D44: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E7D48: lw          $v0, 0x190($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X190);
L_806E7D4C:
    // 0x806E7D4C: beql        $v0, $zero, L_806E7D68
    if (ctx->r2 == 0) {
        // 0x806E7D50: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7D68;
    }
    goto skip_9;
    // 0x806E7D50: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_9:
    // 0x806E7D54: lhu         $t4, 0xC($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7D58: bnel        $a0, $t4, L_806E7D68
    if (ctx->r4 != ctx->r12) {
        // 0x806E7D5C: lw          $v0, 0x194($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X194);
            goto L_806E7D68;
    }
    goto skip_10;
    // 0x806E7D5C: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
    skip_10:
    // 0x806E7D60: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
    // 0x806E7D64: lw          $v0, 0x194($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X194);
L_806E7D68:
    // 0x806E7D68: beq         $v0, $zero, L_806E7D80
    if (ctx->r2 == 0) {
        // 0x806E7D6C: nop
    
            goto L_806E7D80;
    }
    // 0x806E7D6C: nop

    // 0x806E7D70: lhu         $t5, 0xC($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0XC);
    // 0x806E7D74: bne         $a0, $t5, L_806E7D80
    if (ctx->r4 != ctx->r13) {
        // 0x806E7D78: nop
    
            goto L_806E7D80;
    }
    // 0x806E7D78: nop

    // 0x806E7D7C: sb          $zero, 0x165($v0)
    MEM_B(0X165, ctx->r2) = 0;
L_806E7D80:
    // 0x806E7D80: bne         $a1, $a2, L_806E7D0C
    if (ctx->r5 != ctx->r6) {
        // 0x806E7D84: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_806E7D0C;
    }
    // 0x806E7D84: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x806E7D88: lbu         $t6, 0xE($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XE);
    // 0x806E7D8C: andi        $t7, $t6, 0xFF03
    ctx->r15 = ctx->r14 & 0XFF03;
    // 0x806E7D90: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x806E7D94: sb          $t8, 0xE($a3)
    MEM_B(0XE, ctx->r7) = ctx->r24;
L_806E7D98:
    // 0x806E7D98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806E7D9C:
    // 0x806E7D9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7DA0: jr          $ra
    // 0x806E7DA4: nop

    return;
    // 0x806E7DA4: nop

;}
RECOMP_FUNC void func_8007FF0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FF0C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007FF10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007FF14: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8007FF18: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8007FF1C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8007FF20: jal         0x800818E8
    // 0x8007FF24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    MtxConv_L2F(rdram, ctx);
        goto after_0;
    // 0x8007FF24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007FF28: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007FF2C: jal         0x800805C8
    // 0x8007FF30: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    func_800805C8(rdram, ctx);
        goto after_1;
    // 0x8007FF30: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x8007FF34: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8007FF38: jal         0x800817A0
    // 0x8007FF3C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    MtxConv_F2L(rdram, ctx);
        goto after_2;
    // 0x8007FF3C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8007FF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007FF44: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8007FF48: jr          $ra
    // 0x8007FF4C: nop

    return;
    // 0x8007FF4C: nop

;}
RECOMP_FUNC void func_80681E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681E34: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80681E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80681E3C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80681E40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80681E44: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x80681E48: lw          $t0, 0x1F4($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X1F4);
    // 0x80681E4C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80681E50: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80681E54: lw          $t9, 0x168($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X168);
    // 0x80681E58: addiu       $t1, $t8, 0x8
    ctx->r9 = ADD32(ctx->r24, 0X8);
    // 0x80681E5C: lui         $t5, 0xBA00
    ctx->r13 = S32(0XBA00 << 16);
    // 0x80681E60: lw          $a3, 0x88($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X88);
    // 0x80681E64: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80681E68: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x80681E6C: sw          $t2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r10;
    // 0x80681E70: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80681E74: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80681E78: ori         $t7, $t7, 0xAC80
    ctx->r15 = ctx->r15 | 0XAC80;
    // 0x80681E7C: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80681E80: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80681E84: ori         $t5, $t5, 0x18
    ctx->r13 = ctx->r13 | 0X18;
    // 0x80681E88: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x80681E8C: sw          $t7, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r15;
    // 0x80681E90: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80681E94: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80681E98: lui         $a1, 0x55
    ctx->r5 = S32(0X55 << 16);
    // 0x80681E9C: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80681EA0: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x80681EA4: ori         $a1, $a1, 0x3008
    ctx->r5 = ctx->r5 | 0X3008;
    // 0x80681EA8: ori         $t8, $t8, 0x3
    ctx->r24 = ctx->r24 | 0X3;
    // 0x80681EAC: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80681EB0: sw          $a1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r5;
    // 0x80681EB4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80681EB8: lui         $t3, 0xB900
    ctx->r11 = S32(0XB900 << 16);
    // 0x80681EBC: ori         $t3, $t3, 0x31D
    ctx->r11 = ctx->r11 | 0X31D;
    // 0x80681EC0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80681EC4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80681EC8: sw          $a1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r5;
    // 0x80681ECC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80681ED0: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80681ED4: lui         $t6, 0xFFFC
    ctx->r14 = S32(0XFFFC << 16);
    // 0x80681ED8: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x80681EDC: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80681EE0: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x80681EE4: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80681EE8: ori         $t6, $t6, 0xF279
    ctx->r14 = ctx->r14 | 0XF279;
    // 0x80681EEC: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80681EF0: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80681EF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80681EF8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x80681EFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80681F00: jal         0x8007711C
    // 0x80681F04: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    func_8007711C(rdram, ctx);
        goto after_0;
    // 0x80681F04: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80681F08: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80681F0C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80681F10: lui         $t1, 0x104
    ctx->r9 = S32(0X104 << 16);
    // 0x80681F14: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x80681F18: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80681F1C: ori         $t1, $t1, 0x40
    ctx->r9 = ctx->r9 | 0X40;
    // 0x80681F20: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80681F24: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x80681F28: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80681F2C: jal         0x80681BBC
    // 0x80681F30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    func_80681BBC(rdram, ctx);
        goto after_1;
    // 0x80681F30: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_1:
    // 0x80681F34: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80681F38: lui         $t4, 0xBD00
    ctx->r12 = S32(0XBD00 << 16);
    // 0x80681F3C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80681F40: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x80681F44: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80681F48: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x80681F4C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80681F50: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80681F54: sw          $t5, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r13;
    // 0x80681F58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80681F5C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80681F60: jr          $ra
    // 0x80681F64: nop

    return;
    // 0x80681F64: nop

;}
RECOMP_FUNC void func_80041B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80041B5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80041B60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80041B64: lhu         $t7, 0x8($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X8);
    // 0x80041B68: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80041B6C: lhu         $a2, 0xA($a0)
    ctx->r6 = MEM_HU(ctx->r4, 0XA);
    // 0x80041B70: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80041B74: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80041B78: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80041B7C: addu        $v0, $t6, $t8
    ctx->r2 = ADD32(ctx->r14, ctx->r24);
    // 0x80041B80: lhu         $a1, 0x1200($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X1200);
    // 0x80041B84: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80041B88: beq         $at, $zero, L_80041B9C
    if (ctx->r1 == 0) {
        // 0x80041B8C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80041B9C;
    }
    // 0x80041B8C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80041B90: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80041B94: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80041B98: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80041B9C:
    // 0x80041B9C: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80041BA0: bne         $at, $zero, L_80041BB4
    if (ctx->r1 != 0) {
        // 0x80041BA4: nop
    
            goto L_80041BB4;
    }
    // 0x80041BA4: nop

    // 0x80041BA8: lbu         $t9, 0x1202($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1202);
    // 0x80041BAC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80041BB0: sb          $t0, 0x1202($v0)
    MEM_B(0X1202, ctx->r2) = ctx->r8;
L_80041BB4:
    // 0x80041BB4: jal         0x80041914
    // 0x80041BB8: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    func_80041914(rdram, ctx);
        goto after_0;
    // 0x80041BB8: sh          $a1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r5;
    after_0:
    // 0x80041BBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80041BC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80041BC4: jr          $ra
    // 0x80041BC8: nop

    return;
    // 0x80041BC8: nop

;}
RECOMP_FUNC void func_80000A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000A24: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80000A28: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x80000A2C: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x80000A30: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x80000A34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80000A38: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000A3C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000A40: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000A44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80000A48: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80000A4C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80000A50: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80000A54: lbu         $t9, 0x1B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1B);
    // 0x80000A58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80000A5C: lh          $t2, 0x32($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X32);
    // 0x80000A60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80000A64: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80000A68: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80000A6C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80000A70: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80000A74: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80000A78: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80000A7C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80000A80: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80000A84: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x80000A88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80000A8C: addiu       $v1, $v1, 0x50
    ctx->r3 = ADD32(ctx->r3, 0X50);
    // 0x80000A90: lh          $a3, 0x10($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X10);
    // 0x80000A94: lhu         $a2, 0xE($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0XE);
    // 0x80000A98: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80000A9C: addiu       $a1, $zero, 0x3E0
    ctx->r5 = ADD32(0, 0X3E0);
    // 0x80000AA0: jal         0x80001338
    // 0x80000AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80001338(rdram, ctx);
        goto after_0;
    // 0x80000AA4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80000AA8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80000AAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000AB0: lh          $t4, 0x2E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X2E);
    // 0x80000AB4: lh          $a3, 0x12($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X12);
    // 0x80000AB8: beql        $a3, $zero, L_80000AE0
    if (ctx->r7 == 0) {
        // 0x80000ABC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80000AE0;
    }
    goto skip_0;
    // 0x80000ABC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80000AC0: lh          $a1, 0x10($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X10);
    // 0x80000AC4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80000AC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80000ACC: addiu       $a1, $a1, 0x3E0
    ctx->r5 = ADD32(ctx->r5, 0X3E0);
    // 0x80000AD0: jal         0x80001338
    // 0x80000AD4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    func_80001338(rdram, ctx);
        goto after_1;
    // 0x80000AD4: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_1:
    // 0x80000AD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80000ADC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80000AE0:
    // 0x80000AE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80000AE4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80000AE8: jr          $ra
    // 0x80000AEC: nop

    return;
    // 0x80000AEC: nop

;}
RECOMP_FUNC void func_8005F904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005F908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F90C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005F910: jal         0x8005D91C
    // 0x8005F914: sb          $zero, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = 0;
    func_8005D91C(rdram, ctx);
        goto after_0;
    // 0x8005F914: sb          $zero, 0xA80($a0)
    MEM_B(0XA80, ctx->r4) = 0;
    after_0:
    // 0x8005F918: jal         0x8005DAE4
    // 0x8005F91C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005DAE4(rdram, ctx);
        goto after_1;
    // 0x8005F91C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8005F920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005F928: jr          $ra
    // 0x8005F92C: nop

    return;
    // 0x8005F92C: nop

;}
RECOMP_FUNC void func_80462FE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80462FE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80462FE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80462FEC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80462FF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80462FF4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462FF8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80462FFC: addiu       $a0, $zero, 0x410F
    ctx->r4 = ADD32(0, 0X410F);
    // 0x80463000: jal         0x80047090
    // 0x80463004: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80463004: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80463008: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8046300C: bne         $v0, $at, L_8046301C
    if (ctx->r2 != ctx->r1) {
        // 0x80463010: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8046301C;
    }
    // 0x80463010: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80463014: b           L_804630C4
    // 0x80463018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804630C4;
    // 0x80463018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8046301C:
    // 0x8046301C: lui         $at, 0x410F
    ctx->r1 = S32(0X410F << 16);
    // 0x80463020: ori         $at, $at, 0x800
    ctx->r1 = ctx->r1 | 0X800;
    // 0x80463024: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80463028: lui         $at, 0xC33E
    ctx->r1 = S32(0XC33E << 16);
    // 0x8046302C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80463030: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A88) << 16);
    // 0x80463034: lwc1        $f16, 0x4018($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A88));
    // 0x80463038: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8046303C: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80463040: lw          $a2, 0x40($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X40);
    // 0x80463044: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80463048: sh          $v1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r3;
    // 0x8046304C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80463050: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80463054: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80463058: jal         0x8004613C
    // 0x8046305C: nop

    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8046305C: nop

    after_1:
    // 0x80463060: lhu         $v1, 0x26($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X26);
    // 0x80463064: bne         $v0, $zero, L_80463074
    if (ctx->r2 != 0) {
        // 0x80463068: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80463074;
    }
    // 0x80463068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8046306C: b           L_804630C4
    // 0x80463070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804630C4;
    // 0x80463070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80463074:
    // 0x80463074: lhu         $t9, 0xE($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XE);
    // 0x80463078: andi        $t8, $v1, 0x3FF
    ctx->r24 = ctx->r3 & 0X3FF;
    // 0x8046307C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80463080: andi        $t0, $t9, 0xFC00
    ctx->r8 = ctx->r25 & 0XFC00;
    // 0x80463084: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80463088: sh          $t1, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r9;
    // 0x8046308C: jal         0x80047F9C
    // 0x80463090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80463090: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x80463094: jal         0x804619EC
    // 0x80463098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804619EC(rdram, ctx);
        goto after_3;
    // 0x80463098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8046309C: bne         $v0, $zero, L_804630AC
    if (ctx->r2 != 0) {
        // 0x804630A0: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_804630AC;
    }
    // 0x804630A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x804630A4: b           L_804630C4
    // 0x804630A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804630C4;
    // 0x804630A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804630AC:
    // 0x804630AC: sb          $t2, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r10;
    // 0x804630B0: jal         0x8005FDC4
    // 0x804630B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x804630B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804630B8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x804630BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804630C0: sw          $s0, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->r16;
L_804630C4:
    // 0x804630C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804630C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804630CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804630D0: jr          $ra
    // 0x804630D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x804630D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8003B3B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B3B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003B3B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003B3B8: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8003B3BC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8003B3C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003B3C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8003B3C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003B3CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8003B3D0: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x8003B3D4: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x8003B3D8: swc1        $f6, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f6.u32l;
    // 0x8003B3DC: lwc1        $f8, 0x1E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1E4);
    // 0x8003B3E0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8003B3E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B3E8: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
    // 0x8003B3EC: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    // 0x8003B3F0: jal         0x8005FE48
    // 0x8003B3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005FE48(rdram, ctx);
        goto after_0;
    // 0x8003B3F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003B3F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003B3FC: lwc1        $f16, 0x78($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8003B400: lwc1        $f18, 0x7C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8003B404: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x8003B408: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x8003B40C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003B410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003B414: jr          $ra
    // 0x8003B418: nop

    return;
    // 0x8003B418: nop

;}
RECOMP_FUNC void func_80445A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445A94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445A98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445A9C: jal         0x800677F8
    // 0x80445AA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x80445AA0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x80445AA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445AA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445AAC: jr          $ra
    // 0x80445AB0: nop

    return;
    // 0x80445AB0: nop

;}
RECOMP_FUNC void func_800519C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800519C0: addiu       $sp, $sp, -0x1130
    ctx->r29 = ADD32(ctx->r29, -0X1130);
    // 0x800519C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800519C8: sw          $a2, 0x1138($sp)
    MEM_W(0X1138, ctx->r29) = ctx->r6;
    // 0x800519CC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800519D0: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800519D4: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x800519D8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800519DC: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    // 0x800519E0: sh          $t7, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r15;
    // 0x800519E4: addiu       $a0, $sp, 0x1120
    ctx->r4 = ADD32(ctx->r29, 0X1120);
    // 0x800519E8: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x800519EC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800519F0: sw          $t6, 0x1120($sp)
    MEM_W(0X1120, ctx->r29) = ctx->r14;
L_800519F4:
    // 0x800519F4: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800519F8: sh          $v0, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r2;
    // 0x800519FC: sh          $v0, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r2;
    // 0x80051A00: sh          $v0, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r2;
    // 0x80051A04: bne         $v1, $a0, L_800519F4
    if (ctx->r3 != ctx->r4) {
        // 0x80051A08: sh          $v0, -0x8($v1)
        MEM_H(-0X8, ctx->r3) = ctx->r2;
            goto L_800519F4;
    }
    // 0x80051A08: sh          $v0, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r2;
    // 0x80051A0C: lw          $t9, 0x1138($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1138);
    // 0x80051A10: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80051A14: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x80051A18: jal         0x80051418
    // 0x80051A1C: lw          $a2, 0x78($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X78);
    func_80051418(rdram, ctx);
        goto after_0;
    // 0x80051A1C: lw          $a2, 0x78($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X78);
    after_0:
    // 0x80051A20: slti        $at, $v0, 0xA5
    ctx->r1 = SIGNED(ctx->r2) < 0XA5 ? 1 : 0;
    // 0x80051A24: bne         $at, $zero, L_80051A44
    if (ctx->r1 != 0) {
        // 0x80051A28: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80051A44;
    }
    // 0x80051A28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80051A2C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80051A30: addiu       $a0, $a0, 0xA9C
    ctx->r4 = ADD32(ctx->r4, 0XA9C);
    // 0x80051A34: jal         0x80071380
    // 0x80051A38: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x80051A38: addiu       $a1, $zero, 0x28F
    ctx->r5 = ADD32(0, 0X28F);
    after_1:
    // 0x80051A3C: b           L_80051AB0
    // 0x80051A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051AB0;
    // 0x80051A40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051A44:
    // 0x80051A44: lw          $a0, 0x1120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1120);
    // 0x80051A48: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80051A4C: jal         0x80050F2C
    // 0x80051A50: sw          $a2, 0x1128($sp)
    MEM_W(0X1128, ctx->r29) = ctx->r6;
    func_80050F2C(rdram, ctx);
        goto after_2;
    // 0x80051A50: sw          $a2, 0x1128($sp)
    MEM_W(0X1128, ctx->r29) = ctx->r6;
    after_2:
    // 0x80051A54: bne         $v0, $zero, L_80051A74
    if (ctx->r2 != 0) {
        // 0x80051A58: lw          $a2, 0x1128($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1128);
            goto L_80051A74;
    }
    // 0x80051A58: lw          $a2, 0x1128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1128);
    // 0x80051A5C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80051A60: addiu       $a0, $a0, 0xAAC
    ctx->r4 = ADD32(ctx->r4, 0XAAC);
    // 0x80051A64: jal         0x80071380
    // 0x80051A68: addiu       $a1, $zero, 0x299
    ctx->r5 = ADD32(0, 0X299);
    Fault_HungUp(rdram, ctx);
        goto after_3;
    // 0x80051A68: addiu       $a1, $zero, 0x299
    ctx->r5 = ADD32(0, 0X299);
    after_3:
    // 0x80051A6C: b           L_80051AB0
    // 0x80051A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80051AB0;
    // 0x80051A70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80051A74:
    // 0x80051A74: lw          $a0, 0x1120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1120);
    // 0x80051A78: jal         0x80051838
    // 0x80051A7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_80051838(rdram, ctx);
        goto after_4;
    // 0x80051A7C: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_4:
    // 0x80051A80: sw          $v0, 0x1124($sp)
    MEM_W(0X1124, ctx->r29) = ctx->r2;
    // 0x80051A84: jal         0x80050FCC
    // 0x80051A88: lw          $a0, 0x1120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1120);
    func_80050FCC(rdram, ctx);
        goto after_5;
    // 0x80051A88: lw          $a0, 0x1120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1120);
    after_5:
    // 0x80051A8C: jal         0x8005160C
    // 0x80051A90: nop

    func_8005160C(rdram, ctx);
        goto after_6;
    // 0x80051A90: nop

    after_6:
    // 0x80051A94: lw          $a0, 0x1120($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1120);
    // 0x80051A98: lw          $a1, 0x1124($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1124);
    // 0x80051A9C: jal         0x800518F8
    // 0x80051AA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    func_800518F8(rdram, ctx);
        goto after_7;
    // 0x80051AA0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_7:
    // 0x80051AA4: jal         0x800516A8
    // 0x80051AA8: nop

    func_800516A8(rdram, ctx);
        goto after_8;
    // 0x80051AA8: nop

    after_8:
    // 0x80051AAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051AB0:
    // 0x80051AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80051AB4: addiu       $sp, $sp, 0x1130
    ctx->r29 = ADD32(ctx->r29, 0X1130);
    // 0x80051AB8: jr          $ra
    // 0x80051ABC: nop

    return;
    // 0x80051ABC: nop

;}
RECOMP_FUNC void func_8046FC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046FC20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046FC24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8046FC28: lw          $a1, 0x180($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X180);
    // 0x8046FC2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8046FC30: lui         $at, 0x8047
    ctx->r1 = S32(RELOC_HI16(149, 0X1230) << 16);
    // 0x8046FC34: beql        $a1, $zero, L_8046FC90
    if (ctx->r5 == 0) {
        // 0x8046FC38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8046FC90;
    }
    goto skip_0;
    // 0x8046FC38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8046FC3C: lwc1        $f0, 0xE40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(149, 0X1230));
    // 0x8046FC40: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x8046FC44: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8046FC48: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x8046FC4C: lwc1        $f8, 0x70($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X70);
    // 0x8046FC50: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8046FC54: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x8046FC58: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8046FC5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8046FC60: jal         0x80049018
    // 0x8046FC64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8046FC64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8046FC68: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8046FC6C: beq         $v0, $zero, L_8046FC84
    if (ctx->r2 == 0) {
        // 0x8046FC70: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8046FC84;
    }
    // 0x8046FC70: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8046FC74: lwc1        $f16, 0x50($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X50);
    // 0x8046FC78: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8046FC7C: b           L_8046FC8C
    // 0x8046FC80: swc1        $f18, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f18.u32l;
        goto L_8046FC8C;
    // 0x8046FC80: swc1        $f18, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f18.u32l;
L_8046FC84:
    // 0x8046FC84: lwc1        $f4, 0x50($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X50);
    // 0x8046FC88: swc1        $f4, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f4.u32l;
L_8046FC8C:
    // 0x8046FC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8046FC90:
    // 0x8046FC90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046FC94: jr          $ra
    // 0x8046FC98: nop

    return;
    // 0x8046FC98: nop

;}
RECOMP_FUNC void func_8075F414(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F414: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8075F418: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8075F41C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8075F420: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8075F424: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x8075F428: lui         $t6, 0x8076
    ctx->r14 = S32(RELOC_HI16(757, 0XD58) << 16);
    // 0x8075F42C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8075F430: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8075F434: addiu       $t6, $t6, -0x558
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(757, 0XD58));
    // 0x8075F438: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8075F43C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8075F440: lw          $t2, 0x16C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X16C);
    // 0x8075F444: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8075F448: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8075F44C: lui         $t1, 0x8076
    ctx->r9 = S32(RELOC_HI16(757, 0X10) << 16);
    // 0x8075F450: sw          $t8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r24;
    // 0x8075F454: sw          $t9, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r25;
    // 0x8075F458: addiu       $t1, $t1, -0x12A0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(757, 0X10));
    // 0x8075F45C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8075F460: addiu       $a1, $zero, 0x238
    ctx->r5 = ADD32(0, 0X238);
    // 0x8075F464: jal         0x80045A34
    // 0x8075F468: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8075F468: sw          $t1, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r9;
    after_0:
    // 0x8075F46C: lw          $t3, 0x138($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X138);
    // 0x8075F470: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8075F474: addiu       $at, $zero, 0x467E
    ctx->r1 = ADD32(0, 0X467E);
    // 0x8075F478: sw          $t3, 0x220($v0)
    MEM_W(0X220, ctx->r2) = ctx->r11;
    // 0x8075F47C: lhu         $t4, 0xC($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0XC);
    // 0x8075F480: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8075F484: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8075F488: bne         $t4, $at, L_8075F498
    if (ctx->r12 != ctx->r1) {
        // 0x8075F48C: lui         $a0, 0x8076
        ctx->r4 = S32(RELOC_HI16(757, 0X9E0) << 16);
            goto L_8075F498;
    }
    // 0x8075F48C: lui         $a0, 0x8076
    ctx->r4 = S32(RELOC_HI16(757, 0X9E0) << 16);
    // 0x8075F490: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8075F494: sw          $t5, 0x220($v0)
    MEM_W(0X220, ctx->r2) = ctx->r13;
L_8075F498:
    // 0x8075F498: sw          $zero, 0x224($v0)
    MEM_W(0X224, ctx->r2) = 0;
    // 0x8075F49C: sw          $zero, 0x228($v0)
    MEM_W(0X228, ctx->r2) = 0;
    // 0x8075F4A0: sw          $zero, 0x230($v0)
    MEM_W(0X230, ctx->r2) = 0;
    // 0x8075F4A4: sw          $zero, 0x22C($v0)
    MEM_W(0X22C, ctx->r2) = 0;
    // 0x8075F4A8: sw          $zero, 0x21C($v0)
    MEM_W(0X21C, ctx->r2) = 0;
    // 0x8075F4AC: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8075F4B0: swc1        $f16, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f16.u32l;
    // 0x8075F4B4: swc1        $f16, 0x218($v0)
    MEM_W(0X218, ctx->r2) = ctx->f16.u32l;
    // 0x8075F4B8: swc1        $f16, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->f16.u32l;
    // 0x8075F4BC: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8075F4C0: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(757, 0XD70) << 16);
    // 0x8075F4C4: lui         $t6, 0x8076
    ctx->r14 = S32(RELOC_HI16(757, 0XAE0) << 16);
    // 0x8075F4C8: swc1        $f4, 0x20C($v0)
    MEM_W(0X20C, ctx->r2) = ctx->f4.u32l;
    // 0x8075F4CC: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8075F4D0: addiu       $a3, $t6, -0x7D0
    ctx->r7 = ADD32(ctx->r14, (int16_t)RELOC_LO16(757, 0XAE0));
    // 0x8075F4D4: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8075F4D8: swc1        $f6, 0x208($v0)
    MEM_W(0X208, ctx->r2) = ctx->f6.u32l;
    // 0x8075F4DC: lwc1        $f14, -0x540($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(757, 0XD70));
    // 0x8075F4E0: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(757, 0XD74) << 16);
    // 0x8075F4E4: lwc1        $f12, -0x53C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(757, 0XD74));
    // 0x8075F4E8: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(757, 0XD78) << 16);
    // 0x8075F4EC: lwc1        $f2, -0x538($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(757, 0XD78));
    // 0x8075F4F0: lui         $at, 0x8076
    ctx->r1 = S32(RELOC_HI16(757, 0XD7C) << 16);
    // 0x8075F4F4: lwc1        $f0, -0x534($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(757, 0XD7C));
    // 0x8075F4F8: addiu       $a0, $a0, -0x8D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(757, 0X9E0));
    // 0x8075F4FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8075F500: addiu       $a2, $v0, 0x108
    ctx->r6 = ADD32(ctx->r2, 0X108);
    // 0x8075F504: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
L_8075F508:
    // 0x8075F508: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8075F50C: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8075F510: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8075F514: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8075F518: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8075F51C: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8075F520: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8075F524: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8075F528: beq         $at, $zero, L_8075F570
    if (ctx->r1 == 0) {
        // 0x8075F52C: sw          $t7, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r15;
            goto L_8075F570;
    }
    // 0x8075F52C: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8075F530: lh          $t9, 0x8($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X8);
    // 0x8075F534: lh          $t3, 0xA($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XA);
    // 0x8075F538: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8075F53C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8075F540: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8075F544: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8075F548: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8075F54C: nop

    // 0x8075F550: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8075F554: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8075F558: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8075F55C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8075F560: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8075F564: sh          $t2, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r10;
    // 0x8075F568: b           L_8075F5AC
    // 0x8075F56C: sh          $t5, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r13;
        goto L_8075F5AC;
    // 0x8075F56C: sh          $t5, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r13;
L_8075F570:
    // 0x8075F570: lh          $t6, 0x8($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X8);
    // 0x8075F574: lh          $t9, 0xA($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XA);
    // 0x8075F578: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8075F57C: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8075F580: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8075F584: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8075F588: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8075F58C: nop

    // 0x8075F590: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8075F594: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8075F598: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8075F59C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8075F5A0: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8075F5A4: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x8075F5A8: sh          $t2, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r10;
L_8075F5AC:
    // 0x8075F5AC: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8075F5B0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8075F5B4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8075F5B8: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8075F5BC: lw          $t3, 0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X4);
    // 0x8075F5C0: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8075F5C4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x8075F5C8: sw          $t3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r11;
    // 0x8075F5CC: lw          $t4, -0x8($a1)
    ctx->r12 = MEM_W(ctx->r5, -0X8);
    // 0x8075F5D0: sw          $t4, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r12;
    // 0x8075F5D4: lw          $t3, -0x4($a1)
    ctx->r11 = MEM_W(ctx->r5, -0X4);
    // 0x8075F5D8: bne         $a0, $t0, L_8075F508
    if (ctx->r4 != ctx->r8) {
        // 0x8075F5DC: sw          $t3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r11;
            goto L_8075F508;
    }
    // 0x8075F5DC: sw          $t3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r11;
    // 0x8075F5E0: lui         $t5, 0x8076
    ctx->r13 = S32(RELOC_HI16(757, 0X4A0) << 16);
    // 0x8075F5E4: addiu       $t5, $t5, -0xE10
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(757, 0X4A0));
    // 0x8075F5E8: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8075F5EC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8075F5F0: jal         0x80067BBC
    // 0x8075F5F4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x8075F5F4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8075F5F8: addiu       $a0, $zero, 0x75
    ctx->r4 = ADD32(0, 0X75);
    // 0x8075F5FC: jal         0x80067F78
    // 0x8075F600: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8075F600: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8075F604: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8075F608: jal         0x8075F198
    // 0x8075F60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8075F198(rdram, ctx);
        goto after_3;
    // 0x8075F60C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8075F610: jal         0x80047090
    // 0x8075F614: addiu       $a0, $zero, 0x46EC
    ctx->r4 = ADD32(0, 0X46EC);
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x8075F614: addiu       $a0, $zero, 0x46EC
    ctx->r4 = ADD32(0, 0X46EC);
    after_4:
    // 0x8075F618: lui         $at, 0x46EC
    ctx->r1 = S32(0X46EC << 16);
    // 0x8075F61C: lui         $a3, 0xBC23
    ctx->r7 = S32(0XBC23 << 16);
    // 0x8075F620: sh          $v0, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r2;
    // 0x8075F624: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8075F628: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8075F62C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8075F630: jal         0x8004613C
    // 0x8075F634: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x8075F634: lui         $a2, 0x41E0
    ctx->r6 = S32(0X41E0 << 16);
    after_5:
    // 0x8075F638: bne         $v0, $zero, L_8075F650
    if (ctx->r2 != 0) {
        // 0x8075F63C: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8075F650;
    }
    // 0x8075F63C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8075F640: jal         0x800445A4
    // 0x8075F644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8075F644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8075F648: b           L_8075F6E8
    // 0x8075F64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8075F6E8;
    // 0x8075F64C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8075F650:
    // 0x8075F650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075F654: jal         0x80047F9C
    // 0x8075F658: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8075F658: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_7:
    // 0x8075F65C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8075F660: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8075F664: lui         $at, 0x46EC
    ctx->r1 = S32(0X46EC << 16);
    // 0x8075F668: sb          $t6, 0x17C($t7)
    MEM_B(0X17C, ctx->r15) = ctx->r14;
    // 0x8075F66C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8075F670: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8075F674: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8075F678: sw          $zero, 0x138($v0)
    MEM_W(0X138, ctx->r2) = 0;
    // 0x8075F67C: lhu         $a0, 0x22($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X22);
    // 0x8075F680: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8075F684: lui         $a2, 0xC24C
    ctx->r6 = S32(0XC24C << 16);
    // 0x8075F688: jal         0x8004613C
    // 0x8075F68C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x8075F68C: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    after_8:
    // 0x8075F690: bne         $v0, $zero, L_8075F6A8
    if (ctx->r2 != 0) {
        // 0x8075F694: sw          $v0, 0x4($s1)
        MEM_W(0X4, ctx->r17) = ctx->r2;
            goto L_8075F6A8;
    }
    // 0x8075F694: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8075F698: jal         0x800445A4
    // 0x8075F69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x8075F69C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8075F6A0: b           L_8075F6E8
    // 0x8075F6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8075F6E8;
    // 0x8075F6A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8075F6A8:
    // 0x8075F6A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075F6AC: jal         0x80047F9C
    // 0x8075F6B0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    func_80047F9C(rdram, ctx);
        goto after_10;
    // 0x8075F6B0: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_10:
    // 0x8075F6B4: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8075F6B8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8075F6BC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x8075F6C0: sb          $t8, 0x17C($t9)
    MEM_B(0X17C, ctx->r25) = ctx->r24;
    // 0x8075F6C4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8075F6C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8075F6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8075F6D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8075F6D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8075F6D8: sh          $t1, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r9;
    // 0x8075F6DC: jal         0x8075F6F8
    // 0x8075F6E0: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    func_8075F6F8(rdram, ctx);
        goto after_11;
    // 0x8075F6E0: sw          $t2, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r10;
    after_11:
    // 0x8075F6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8075F6E8:
    // 0x8075F6E8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8075F6EC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8075F6F0: jr          $ra
    // 0x8075F6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8075F6F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8004B3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004B3F8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8004B3FC: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8004B400: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004B404: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004B408: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8004B40C: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004B410: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8004B414: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004B418: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004B41C: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004B420: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004B424: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004B428: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004B42C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8004B430: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8004B434: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8004B438: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8004B43C: jal         0x80049864
    // 0x8004B440: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004B440: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004B444: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8004B448: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8004B44C: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8004B450: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8004B454: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x8004B458: lwc1        $f6, 0x4($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X4);
    // 0x8004B45C: lw          $t3, 0x34($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X34);
    // 0x8004B460: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004B464: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B468: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8004B46C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8004B470: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8004B474: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8004B478: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004B47C: andi        $t4, $t3, 0xF
    ctx->r12 = ctx->r11 & 0XF;
    // 0x8004B480: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8004B484: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004B488: trunc.w.s   $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    ctx->f10.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8004B48C: sh          $t7, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r15;
    // 0x8004B490: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x8004B494: srav        $t8, $t7, $t6
    ctx->r24 = S32(SIGNED(ctx->r15) >> (ctx->r14 & 31));
    // 0x8004B498: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8004B49C: addiu       $t5, $t0, 0xC
    ctx->r13 = ADD32(ctx->r8, 0XC);
    // 0x8004B4A0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8004B4A4: sll         $t1, $t1, 16
    ctx->r9 = S32(ctx->r9 << 16);
    // 0x8004B4A8: sra         $t1, $t1, 16
    ctx->r9 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8004B4AC: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8004B4B0: sh          $t2, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r10;
    // 0x8004B4B4: lh          $t3, 0x60($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X60);
    // 0x8004B4B8: sh          $t8, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r24;
    // 0x8004B4BC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8004B4C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8004B4C4: sh          $t4, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r12;
    // 0x8004B4C8: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x8004B4CC: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    // 0x8004B4D0: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x8004B4D4: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8004B4D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004B4DC: srl         $t7, $v0, 6
    ctx->r15 = S32(U32(ctx->r2) >> 6);
    // 0x8004B4E0: andi        $t9, $v0, 0x3F
    ctx->r25 = ctx->r2 & 0X3F;
    // 0x8004B4E4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8004B4E8: sll         $t6, $t7, 8
    ctx->r14 = S32(ctx->r15 << 8);
    // 0x8004B4EC: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x8004B4F0: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8004B4F4: lw          $t5, 0xA24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XA24);
    // 0x8004B4F8: sll         $t7, $t3, 1
    ctx->r15 = S32(ctx->r11 << 1);
    // 0x8004B4FC: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x8004B500: addu        $t9, $t5, $t7
    ctx->r25 = ADD32(ctx->r13, ctx->r15);
    // 0x8004B504: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x8004B508: lhu         $t3, 0x50($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X50);
    // 0x8004B50C: and         $t4, $t6, $t2
    ctx->r12 = ctx->r14 & ctx->r10;
    // 0x8004B510: beql        $t4, $zero, L_8004B788
    if (ctx->r12 == 0) {
        // 0x8004B514: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_0;
    // 0x8004B514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8004B518: sh          $t3, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r11;
    // 0x8004B51C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8004B520: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8004B524: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8004B528: jal         0x8004B154
    // 0x8004B52C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    func_8004B154(rdram, ctx);
        goto after_1;
    // 0x8004B52C: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8004B530: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
    // 0x8004B534: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x8004B538: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8004B53C: sh          $v1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r3;
    // 0x8004B540: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8004B544: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8004B548: beq         $a0, $zero, L_8004B784
    if (ctx->r4 == 0) {
        // 0x8004B54C: lwc1        $f14, 0x44($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
            goto L_8004B784;
    }
    // 0x8004B54C: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004B550: lbu         $v0, 0x50($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X50);
    // 0x8004B554: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8004B558: slti        $at, $a0, -0x8
    ctx->r1 = SIGNED(ctx->r4) < -0X8 ? 1 : 0;
    // 0x8004B55C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8004B560: bne         $t5, $zero, L_8004B73C
    if (ctx->r13 != 0) {
        // 0x8004B564: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_8004B73C;
    }
    // 0x8004B564: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8004B568: beq         $t7, $zero, L_8004B73C
    if (ctx->r15 == 0) {
        // 0x8004B56C: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8004B73C;
    }
    // 0x8004B56C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8004B570: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8004B574: lwc1        $f4, 0x4($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X4);
    // 0x8004B578: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B57C: lwc1        $f6, 0x88($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X88);
    // 0x8004B580: lbu         $v0, 0x3A($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X3A);
    // 0x8004B584: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004B588: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004B58C: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8004B590: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004B594: nop

    // 0x8004B598: bc1f        L_8004B6C4
    if (!c1cs) {
        // 0x8004B59C: nop
    
            goto L_8004B6C4;
    }
    // 0x8004B59C: nop

    // 0x8004B5A0: lhu         $a0, 0x50($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X50);
    // 0x8004B5A4: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8004B5A8: jal         0x8004A97C
    // 0x8004B5AC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    func_8004A97C(rdram, ctx);
        goto after_2;
    // 0x8004B5AC: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8004B5B0: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8004B5B4: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8004B5B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004B5BC: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8004B5C0: lwc1        $f10, 0x84($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X84);
    // 0x8004B5C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8004B5C8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8004B5CC: jal         0x80066DE4
    // 0x8004B5D0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8004B5D0: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8004B5D4: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8004B5D8: jal         0x80066E88
    // 0x8004B5DC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x8004B5DC: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8004B5E0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004B5E4: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8004B5E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8004B5EC: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004B5F0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004B5F4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8004B5F8: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8004B5FC: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8004B600: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x8004B604: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004B608: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8004B60C: bc1f        L_8004B664
    if (!c1cs) {
        // 0x8004B610: mov.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
            goto L_8004B664;
    }
    // 0x8004B610: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x8004B614: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8004B618: nop

    // 0x8004B61C: bc1fl       L_8004B788
    if (!c1cs) {
        // 0x8004B620: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_1;
    // 0x8004B620: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_1:
    // 0x8004B624: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8004B628: lh          $t4, 0x38($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X38);
    // 0x8004B62C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004B630: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8004B634: nop

    // 0x8004B638: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B63C: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8004B640: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8004B644: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8004B648: nop

    // 0x8004B64C: bc1f        L_8004B65C
    if (!c1cs) {
        // 0x8004B650: nop
    
            goto L_8004B65C;
    }
    // 0x8004B650: nop

    // 0x8004B654: b           L_8004B78C
    // 0x8004B658: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8004B78C;
    // 0x8004B658: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8004B65C:
    // 0x8004B65C: b           L_8004B78C
    // 0x8004B660: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8004B78C;
    // 0x8004B660: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8004B664:
    // 0x8004B664: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x8004B668: nop

    // 0x8004B66C: bc1fl       L_8004B788
    if (!c1cs) {
        // 0x8004B670: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_2;
    // 0x8004B670: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_2:
    // 0x8004B674: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8004B678: nop

    // 0x8004B67C: bc1fl       L_8004B788
    if (!c1cs) {
        // 0x8004B680: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_3;
    // 0x8004B680: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_3:
    // 0x8004B684: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8004B688: lh          $t3, 0x38($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X38);
    // 0x8004B68C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B690: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8004B694: nop

    // 0x8004B698: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004B69C: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x8004B6A0: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004B6A4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x8004B6A8: nop

    // 0x8004B6AC: bc1f        L_8004B6BC
    if (!c1cs) {
        // 0x8004B6B0: nop
    
            goto L_8004B6BC;
    }
    // 0x8004B6B0: nop

    // 0x8004B6B4: b           L_8004B78C
    // 0x8004B6B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8004B78C;
    // 0x8004B6B8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8004B6BC:
    // 0x8004B6BC: b           L_8004B78C
    // 0x8004B6C0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8004B78C;
    // 0x8004B6C0: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8004B6C4:
    // 0x8004B6C4: bne         $t5, $zero, L_8004B718
    if (ctx->r13 != 0) {
        // 0x8004B6C8: andi        $t7, $v0, 0x2
        ctx->r15 = ctx->r2 & 0X2;
            goto L_8004B718;
    }
    // 0x8004B6C8: andi        $t7, $v0, 0x2
    ctx->r15 = ctx->r2 & 0X2;
    // 0x8004B6CC: bne         $t7, $zero, L_8004B718
    if (ctx->r15 != 0) {
        // 0x8004B6D0: andi        $t9, $v0, 0x4
        ctx->r25 = ctx->r2 & 0X4;
            goto L_8004B718;
    }
    // 0x8004B6D0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x8004B6D4: beq         $t9, $zero, L_8004B718
    if (ctx->r25 == 0) {
        // 0x8004B6D8: lhu         $t8, 0x50($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X50);
            goto L_8004B718;
    }
    // 0x8004B6D8: lhu         $t8, 0x50($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X50);
    // 0x8004B6DC: lhu         $t6, 0x3A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X3A);
    // 0x8004B6E0: slti        $at, $a0, -0x8
    ctx->r1 = SIGNED(ctx->r4) < -0X8 ? 1 : 0;
    // 0x8004B6E4: beql        $t8, $t6, L_8004B788
    if (ctx->r24 == ctx->r14) {
        // 0x8004B6E8: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_4;
    // 0x8004B6E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_4:
    // 0x8004B6EC: bnel        $at, $zero, L_8004B788
    if (ctx->r1 != 0) {
        // 0x8004B6F0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8004B788;
    }
    goto skip_5;
    // 0x8004B6F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_5:
    // 0x8004B6F4: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8004B6F8: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004B6FC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004B700: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004B704: sb          $t2, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r10;
    // 0x8004B708: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B70C: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8004B710: b           L_8004B78C
    // 0x8004B714: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
        goto L_8004B78C;
    // 0x8004B714: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
L_8004B718:
    // 0x8004B718: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8004B71C: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x8004B720: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004B724: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004B728: sb          $t4, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r12;
    // 0x8004B72C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8004B730: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x8004B734: b           L_8004B78C
    // 0x8004B738: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
        goto L_8004B78C;
    // 0x8004B738: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
L_8004B73C:
    // 0x8004B73C: beq         $at, $zero, L_8004B768
    if (ctx->r1 == 0) {
        // 0x8004B740: sb          $t3, 0x14($t0)
        MEM_B(0X14, ctx->r8) = ctx->r11;
            goto L_8004B768;
    }
    // 0x8004B740: sb          $t3, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r11;
    // 0x8004B744: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8004B748: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8004B74C: lhu         $t5, 0x3A($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X3A);
    // 0x8004B750: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B754: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004B758: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8004B75C: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x8004B760: b           L_8004B78C
    // 0x8004B764: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
        goto L_8004B78C;
    // 0x8004B764: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
L_8004B768:
    // 0x8004B768: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8004B76C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8004B770: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8004B774: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004B778: sub.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8004B77C: b           L_8004B78C
    // 0x8004B780: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
        goto L_8004B78C;
    // 0x8004B780: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
L_8004B784:
    // 0x8004B784: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8004B788:
    // 0x8004B788: nop

L_8004B78C:
    // 0x8004B78C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004B790: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8004B794: jr          $ra
    // 0x8004B798: nop

    return;
    // 0x8004B798: nop

;}
RECOMP_FUNC void func_8005EC50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC50: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005EC54: sb          $zero, 0x38($t6)
    MEM_B(0X38, ctx->r14) = 0;
    // 0x8005EC58: jr          $ra
    // 0x8005EC5C: sw          $zero, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = 0;
    return;
    // 0x8005EC5C: sw          $zero, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = 0;
;}
RECOMP_FUNC void func_80455770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455770: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80455774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80455778: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8045577C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80455780: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80455784: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455788: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8045578C: jal         0x8044AC0C
    // 0x80455790: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_8044AC0C(rdram, ctx);
        goto after_0;
    // 0x80455790: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80455794: jal         0x8044AB94
    // 0x80455798: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8044AB94(rdram, ctx);
        goto after_1;
    // 0x80455798: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8045579C: jal         0x8044AC84
    // 0x804557A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8044AC84(rdram, ctx);
        goto after_2;
    // 0x804557A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x804557A4: jal         0x8044ACFC
    // 0x804557A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_8044ACFC(rdram, ctx);
        goto after_3;
    // 0x804557A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x804557AC: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x804557B0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804557B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x804557B8: addu        $s1, $v0, $at
    ctx->r17 = ADD32(ctx->r2, ctx->r1);
    // 0x804557BC: lw          $t7, 0x6980($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X6980);
    // 0x804557C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804557C4: lw          $t8, 0x44($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X44);
    // 0x804557C8: jal         0x80446F58
    // 0x804557CC: sw          $t8, 0x6A94($at)
    MEM_W(0X6A94, ctx->r1) = ctx->r24;
    func_80446F58(rdram, ctx);
        goto after_4;
    // 0x804557CC: sw          $t8, 0x6A94($at)
    MEM_W(0X6A94, ctx->r1) = ctx->r24;
    after_4:
    // 0x804557D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x804557D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804557D8: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x804557DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804557E0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x804557E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804557E8: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
    // 0x804557EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x804557F0: sw          $v0, 0x6A20($s1)
    MEM_W(0X6A20, ctx->r17) = ctx->r2;
    // 0x804557F4: sw          $t9, 0x6A28($s1)
    MEM_W(0X6A28, ctx->r17) = ctx->r25;
    // 0x804557F8: sw          $v0, 0x6A24($s1)
    MEM_W(0X6A24, ctx->r17) = ctx->r2;
    // 0x804557FC: swc1        $f4, 0x6984($s1)
    MEM_W(0X6984, ctx->r17) = ctx->f4.u32l;
    // 0x80455800: swc1        $f6, 0x6994($s1)
    MEM_W(0X6994, ctx->r17) = ctx->f6.u32l;
    // 0x80455804: swc1        $f8, 0x6998($s1)
    MEM_W(0X6998, ctx->r17) = ctx->f8.u32l;
    // 0x80455808: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8045580C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455810: lui         $s1, 0x8045
    ctx->r17 = S32(RELOC_HI16(98, 0X136AC) << 16);
    // 0x80455814: lui         $s0, 0x8045
    ctx->r16 = S32(RELOC_HI16(98, 0X13674) << 16);
    // 0x80455818: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8045581C: sw          $v0, 0x6A40($at)
    MEM_W(0X6A40, ctx->r1) = ctx->r2;
    // 0x80455820: addiu       $s0, $s0, 0x7A54
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(98, 0X13674));
    // 0x80455824: addiu       $s1, $s1, 0x7A8C
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(98, 0X136AC));
    // 0x80455828: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_8045582C:
    // 0x8045582C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80455830: jalr        $t9
    // 0x80455834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80455834: nop

    after_5:
    // 0x80455838: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8045583C: bnel        $s0, $s1, L_8045582C
    if (ctx->r16 != ctx->r17) {
        // 0x80455840: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_8045582C;
    }
    goto skip_0;
    // 0x80455840: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80455844: jal         0x804556D8
    // 0x80455848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_804556D8(rdram, ctx);
        goto after_6;
    // 0x80455848: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8045584C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80455850: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80455854: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80455858: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8045585C: jr          $ra
    // 0x80455860: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80455860: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_806F2428(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2428: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806F242C: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(679, 0XD10) << 16);
    // 0x806F2430: addiu       $t6, $t6, 0x2290
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(679, 0XD10));
    // 0x806F2434: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806F2438: jr          $ra
    // 0x806F243C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806F243C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_804D8E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8E34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8E38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D8E3C: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x804D8E40: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x804D8E44: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x804D8E48: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x804D8E4C: lui         $t9, 0x804E
    ctx->r25 = S32(RELOC_HI16(258, 0X4320) << 16);
    // 0x804D8E50: sw          $t6, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r14;
    // 0x804D8E54: sw          $t7, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r15;
    // 0x804D8E58: sw          $t8, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r24;
    // 0x804D8E5C: lh          $t9, -0x3010($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(258, 0X4320));
    // 0x804D8E60: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x804D8E64: lui         $v1, 0x804E
    ctx->r3 = S32(RELOC_HI16(258, 0X4322) << 16);
    // 0x804D8E68: addiu       $v1, $v1, -0x300E
    ctx->r3 = ADD32(ctx->r3, (int16_t)RELOC_LO16(258, 0X4322));
    // 0x804D8E6C: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x804D8E70: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x804D8E74: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804D8E78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x804D8E7C: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x804D8E80: lh          $t1, -0x2($v1)
    ctx->r9 = MEM_H(ctx->r3, -0X2);
    // 0x804D8E84: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x804D8E88: sh          $t1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r9;
    // 0x804D8E8C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x804D8E90: jal         0x804D8FC4
    // 0x804D8E94: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    func_804D8FC4(rdram, ctx);
        goto after_0;
    // 0x804D8E94: sh          $t2, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x804D8E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D8E9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D8EA0: jr          $ra
    // 0x804D8EA4: nop

    return;
    // 0x804D8EA4: nop

;}
RECOMP_FUNC void func_80461490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80461490: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80461494: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80461498: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8046149C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x804614A0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A10) << 16);
    // 0x804614A4: lwc1        $f6, 0x3FA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A10));
    // 0x804614A8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804614AC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A14) << 16);
    // 0x804614B0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x804614B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804614B8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x804614BC: lwc1        $f10, 0x3FA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A14));
    // 0x804614C0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804614C4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A1C) << 16);
    // 0x804614C8: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x804614CC: nop

    // 0x804614D0: bc1f        L_804614F0
    if (!c1cs) {
        // 0x804614D4: nop
    
            goto L_804614F0;
    }
    // 0x804614D4: nop

    // 0x804614D8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A18) << 16);
    // 0x804614DC: lwc1        $f16, 0x3FA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A18));
    // 0x804614E0: sub.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x804614E4: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x804614E8: b           L_80461518
    // 0x804614EC: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
        goto L_80461518;
    // 0x804614EC: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_804614F0:
    // 0x804614F0: lwc1        $f4, 0x3FAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A1C));
    // 0x804614F4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(122, 0X3A20) << 16);
    // 0x804614F8: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x804614FC: nop

    // 0x80461500: bc1f        L_80461518
    if (!c1cs) {
        // 0x80461504: nop
    
            goto L_80461518;
    }
    // 0x80461504: nop

    // 0x80461508: lwc1        $f6, 0x3FB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(122, 0X3A20));
    // 0x8046150C: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x80461510: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80461514: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
L_80461518:
    // 0x80461518: jal         0x80082730
    // 0x8046151C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    fsin(rdram, ctx);
        goto after_0;
    // 0x8046151C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_0:
    // 0x80461520: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80461524: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80461528: jal         0x80082730
    // 0x8046152C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    fsin(rdram, ctx);
        goto after_1;
    // 0x8046152C: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80461530: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80461534: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80461538: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8046153C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80461540: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80461544: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80461548: jal         0x8008D250
    // 0x8046154C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    fcos(rdram, ctx);
        goto after_2;
    // 0x8046154C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80461550: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80461554: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80461558: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8046155C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80461560: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80461564: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80461568: addiu       $a0, $a1, 0xC4
    ctx->r4 = ADD32(ctx->r5, 0XC4);
    // 0x8046156C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80461570: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80461574: lwc1        $f6, 0x3C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80461578: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8046157C: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80461580: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80461584: lwc1        $f18, 0x40($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X40);
    // 0x80461588: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8046158C: jal         0x80461430
    // 0x80461590: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    func_80461430(rdram, ctx);
        goto after_3;
    // 0x80461590: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    after_3:
    // 0x80461594: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80461598: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8046159C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804615A0: jr          $ra
    // 0x804615A4: nop

    return;
    // 0x804615A4: nop

;}
RECOMP_FUNC void func_805DAF64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAF64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DAF68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DAF6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805DAF70: lh          $a2, 0x1F0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X1F0);
    // 0x805DAF74: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x805DAF78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x805DAF7C: beq         $a2, $at, L_805DAFAC
    if (ctx->r6 == ctx->r1) {
        // 0x805DAF80: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_805DAFAC;
    }
    // 0x805DAF80: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x805DAF84: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x805DAF88: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x805DAF8C: jal         0x80067930
    // 0x805DAF90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x805DAF90: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x805DAF94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805DAF98: bne         $v0, $at, L_805DAFAC
    if (ctx->r2 != ctx->r1) {
        // 0x805DAF9C: lw          $a3, 0x18($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X18);
            goto L_805DAFAC;
    }
    // 0x805DAF9C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x805DAFA0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x805DAFA4: jal         0x80067878
    // 0x805DAFA8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x805DAFA8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_1:
L_805DAFAC:
    // 0x805DAFAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DAFB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAFB4: jr          $ra
    // 0x805DAFB8: nop

    return;
    // 0x805DAFB8: nop

;}
RECOMP_FUNC void func_80519AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519AFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519B00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80519B04: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80519B08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519B0C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80519B10: lui         $t7, 0x8052
    ctx->r15 = S32(RELOC_HI16(291, 0X25B8) << 16);
    // 0x80519B14: sb          $a1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r5;
    // 0x80519B18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80519B1C: lw          $t7, -0x5DD8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(291, 0X25B8));
    // 0x80519B20: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
    // 0x80519B24: sw          $a2, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r6;
    // 0x80519B28: sw          $a2, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r6;
    // 0x80519B2C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x80519B30: jal         0x80519010
    // 0x80519B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80519010(rdram, ctx);
        goto after_0;
    // 0x80519B34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80519B38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80519B3C: jal         0x80517EBC
    // 0x80519B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80517EBC(rdram, ctx);
        goto after_1;
    // 0x80519B40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80519B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519B48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519B4C: jr          $ra
    // 0x80519B50: nop

    return;
    // 0x80519B50: nop

;}
RECOMP_FUNC void func_8000A990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A994: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x8000A998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A99C: addiu       $t7, $t7, 0x4D10
    ctx->r15 = ADD32(ctx->r15, 0X4D10);
    // 0x8000A9A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000A9A4: sw          $t6, 0x1E9C($t7)
    MEM_W(0X1E9C, ctx->r15) = ctx->r14;
    // 0x8000A9A8: jal         0x8000A8F8
    // 0x8000A9AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8000A8F8(rdram, ctx);
        goto after_0;
    // 0x8000A9AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000A9B0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x8000A9B4: addiu       $t8, $t8, 0x4D10
    ctx->r24 = ADD32(ctx->r24, 0X4D10);
    // 0x8000A9B8: sb          $zero, 0x2A22($t8)
    MEM_B(0X2A22, ctx->r24) = 0;
    // 0x8000A9BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A9C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A9C4: jr          $ra
    // 0x8000A9C8: nop

    return;
    // 0x8000A9C8: nop

;}
RECOMP_FUNC void func_8043E764(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043E764: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043E768: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043E76C: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x8043E770: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x8043E774: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043E778: bnel        $t6, $at, L_8043E7C0
    if (ctx->r14 != ctx->r1) {
        // 0x8043E77C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E7C0;
    }
    goto skip_0;
    // 0x8043E77C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8043E780: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x8043E784: bnel        $t7, $zero, L_8043E7C0
    if (ctx->r15 != 0) {
        // 0x8043E788: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E7C0;
    }
    goto skip_1;
    // 0x8043E788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8043E78C: lbu         $t8, 0x18($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X18);
    // 0x8043E790: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8043E794: slti        $at, $t8, 0x8
    ctx->r1 = SIGNED(ctx->r24) < 0X8 ? 1 : 0;
    // 0x8043E798: beql        $at, $zero, L_8043E7C0
    if (ctx->r1 == 0) {
        // 0x8043E79C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E7C0;
    }
    goto skip_2;
    // 0x8043E79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8043E7A0: lbu         $t9, -0x764C($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X764C);
    // 0x8043E7A4: bnel        $t9, $zero, L_8043E7C0
    if (ctx->r25 != 0) {
        // 0x8043E7A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8043E7C0;
    }
    goto skip_3;
    // 0x8043E7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8043E7AC: jal         0x8004012C
    // 0x8043E7B0: nop

    func_8004012C(rdram, ctx);
        goto after_0;
    // 0x8043E7B0: nop

    after_0:
    // 0x8043E7B4: jal         0x800496D4
    // 0x8043E7B8: nop

    func_800496D4(rdram, ctx);
        goto after_1;
    // 0x8043E7B8: nop

    after_1:
    // 0x8043E7BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8043E7C0:
    // 0x8043E7C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8043E7C4: jr          $ra
    // 0x8043E7C8: nop

    return;
    // 0x8043E7C8: nop

;}
