#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80536354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536354: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536358: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053635C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536360: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536364: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536368: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053636C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536370: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536374: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536378: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053637C: jr          $ra
    // 0x80536380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804250DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804250DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804250E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804250E4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804250E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804250EC: jal         0x80424F94
    // 0x804250F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80424F94(rdram, ctx);
        goto after_0;
    // 0x804250F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804250F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804250F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804250FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80425100: lw          $v1, 0xF0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF0);
    // 0x80425104: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80425108: beq         $v1, $zero, L_80425118
    if (ctx->r3 == 0) {
        // 0x8042510C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80425118;
    }
    // 0x8042510C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80425110: b           L_80425120
    // 0x80425114: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
        goto L_80425120;
    // 0x80425114: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
L_80425118:
    // 0x80425118: jal         0x80425408
    // 0x8042511C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_1;
    // 0x8042511C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_80425120:
    // 0x80425120: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425124: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80425128: jr          $ra
    // 0x8042512C: nop

    return;
    // 0x8042512C: nop

;}
RECOMP_FUNC void func_80036638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003663C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036640: jal         0x80021958
    // 0x80036644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x80036644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036648: bne         $v0, $zero, L_80036658
    if (ctx->r2 != 0) {
        // 0x8003664C: nop
    
            goto L_80036658;
    }
    // 0x8003664C: nop

    // 0x80036650: b           L_8003668C
    // 0x80036654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003668C;
    // 0x80036654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036658:
    // 0x80036658: jal         0x800415FC
    // 0x8003665C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x8003665C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80036660: beq         $v0, $zero, L_80036670
    if (ctx->r2 == 0) {
        // 0x80036664: nop
    
            goto L_80036670;
    }
    // 0x80036664: nop

    // 0x80036668: b           L_8003668C
    // 0x8003666C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003668C;
    // 0x8003666C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036670:
    // 0x80036670: jal         0x800360F4
    // 0x80036674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800360F4(rdram, ctx);
        goto after_2;
    // 0x80036674: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80036678: bnel        $v0, $zero, L_8003668C
    if (ctx->r2 != 0) {
        // 0x8003667C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8003668C;
    }
    goto skip_0;
    // 0x8003667C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036680: b           L_8003668C
    // 0x80036684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003668C;
    // 0x80036684: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003668C:
    // 0x8003668C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036694: jr          $ra
    // 0x80036698: nop

    return;
    // 0x80036698: nop

;}
RECOMP_FUNC void func_80036260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036260: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036268: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8003626C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80036270: bne         $t6, $zero, L_80036288
    if (ctx->r14 != 0) {
        // 0x80036274: nop
    
            goto L_80036288;
    }
    // 0x80036274: nop

    // 0x80036278: jal         0x8002DB14
    // 0x8003627C: nop

    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x8003627C: nop

    after_0:
    // 0x80036280: b           L_80036288
    // 0x80036284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036288;
    // 0x80036284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036288:
    // 0x80036288: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003628C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036290: jr          $ra
    // 0x80036294: nop

    return;
    // 0x80036294: nop

;}
RECOMP_FUNC void func_804C911C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C911C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C9120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C9124: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C9128: jal         0x80045A34
    // 0x804C912C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x804C912C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x804C9130: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804C9134: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x804C9138: bne         $v0, $zero, L_804C9150
    if (ctx->r2 != 0) {
        // 0x804C913C: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_804C9150;
    }
    // 0x804C913C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x804C9140: jal         0x800445A4
    // 0x804C9144: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804C9144: nop

    after_1:
    // 0x804C9148: b           L_804C9164
    // 0x804C914C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C9164;
    // 0x804C914C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C9150:
    // 0x804C9150: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804C9154: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x804C9158: jal         0x80065728
    // 0x804C915C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x804C915C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x804C9160: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804C9164:
    // 0x804C9164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C9168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C916C: jr          $ra
    // 0x804C9170: nop

    return;
    // 0x804C9170: nop

;}
RECOMP_FUNC void func_806E9748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E9748: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806E974C: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(667, 0X1418) << 16);
    // 0x806E9750: addiu       $t6, $t6, -0x6938
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(667, 0X1418));
    // 0x806E9754: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806E9758: jr          $ra
    // 0x806E975C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x806E975C: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80574650(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80574650: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80574654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80574658: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8057465C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80574660: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80574664: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80574668: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8057466C: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80574670: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(381, 0XEEC) << 16);
    // 0x80574674: lwc1        $f10, 0x4D7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(381, 0XEEC));
    // 0x80574678: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8057467C: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80574680: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80574684: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80574688: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8057468C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x80574690: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x80574694: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x80574698: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8057469C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x805746A0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x805746A4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x805746A8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x805746AC: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x805746B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x805746B4: lw          $t9, 0x28($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X28);
    // 0x805746B8: jalr        $t9
    // 0x805746BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805746BC: nop

    after_0:
    // 0x805746C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805746C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x805746C8: jr          $ra
    // 0x805746CC: nop

    return;
    // 0x805746CC: nop

;}
RECOMP_FUNC void func_804EF4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF4E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF4E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF4EC: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x804EF4F0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x804EF4F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x804EF4F8: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X102C) << 16);
    // 0x804EF4FC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x804EF500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804EF504: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x804EF508: sb          $t7, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r15;
    // 0x804EF50C: addiu       $t8, $t8, -0x244
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(267, 0X102C));
    // 0x804EF510: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804EF514: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804EF518: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
    // 0x804EF51C: jal         0x804EF46C
    // 0x804EF520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF46C(rdram, ctx);
        goto after_0;
    // 0x804EF520: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF524: bne         $v0, $zero, L_804EF53C
    if (ctx->r2 != 0) {
        // 0x804EF528: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804EF53C;
    }
    // 0x804EF528: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF52C: jal         0x800445A4
    // 0x804EF530: nop

    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804EF530: nop

    after_1:
    // 0x804EF534: b           L_804EF594
    // 0x804EF538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804EF594;
    // 0x804EF538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF53C:
    // 0x804EF53C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804EF540: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x804EF544: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804EF548: jal         0x804EF5A0
    // 0x804EF54C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804EF5A0(rdram, ctx);
        goto after_2;
    // 0x804EF54C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x804EF550: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF554: lui         $t0, 0x8005
    ctx->r8 = S32(0X8005 << 16);
    // 0x804EF558: addiu       $t0, $t0, -0x7C48
    ctx->r8 = ADD32(ctx->r8, -0X7C48);
    // 0x804EF55C: lui         $at, 0x804F
    ctx->r1 = S32(RELOC_HI16(267, 0X1194) << 16);
    // 0x804EF560: sw          $t0, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r8;
    // 0x804EF564: lwc1        $f8, -0xDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(267, 0X1194));
    // 0x804EF568: lwc1        $f6, 0x44($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X44);
    // 0x804EF56C: lw          $a1, 0x3C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X3C);
    // 0x804EF570: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x804EF574: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804EF578: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x804EF57C: jal         0x804EF7F8
    // 0x804EF580: nop

    func_804EF7F8(rdram, ctx);
        goto after_3;
    // 0x804EF580: nop

    after_3:
    // 0x804EF584: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804EF588: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804EF58C: sb          $t1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r9;
    // 0x804EF590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF594:
    // 0x804EF594: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF598: jr          $ra
    // 0x804EF59C: nop

    return;
    // 0x804EF59C: nop

;}
RECOMP_FUNC void func_80736E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736E0C: jr          $ra
    // 0x80736E10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80736E10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80466600(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80466600: lui         $v0, 0x8046
    ctx->r2 = S32(RELOC_HI16(129, 0X1D0) << 16);
    // 0x80466604: addiu       $v0, $v0, 0x67D0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(129, 0X1D0));
    // 0x80466608: jr          $ra
    // 0x8046660C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8046660C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8056766C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8056766C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80567670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80567674: lhu         $v0, 0xC($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0XC);
    // 0x80567678: slti        $at, $v0, 0x4669
    ctx->r1 = SIGNED(ctx->r2) < 0X4669 ? 1 : 0;
    // 0x8056767C: bne         $at, $zero, L_805676A0
    if (ctx->r1 != 0) {
        // 0x80567680: addiu       $t6, $v0, -0x4150
        ctx->r14 = ADD32(ctx->r2, -0X4150);
            goto L_805676A0;
    }
    // 0x80567680: addiu       $t6, $v0, -0x4150
    ctx->r14 = ADD32(ctx->r2, -0X4150);
    // 0x80567684: addiu       $at, $zero, 0x4669
    ctx->r1 = ADD32(0, 0X4669);
    // 0x80567688: beq         $v0, $at, L_805676FC
    if (ctx->r2 == ctx->r1) {
        // 0x8056768C: addiu       $at, $zero, 0x468A
        ctx->r1 = ADD32(0, 0X468A);
            goto L_805676FC;
    }
    // 0x8056768C: addiu       $at, $zero, 0x468A
    ctx->r1 = ADD32(0, 0X468A);
    // 0x80567690: beq         $v0, $at, L_8056778C
    if (ctx->r2 == ctx->r1) {
        // 0x80567694: nop
    
            goto L_8056778C;
    }
    // 0x80567694: nop

    // 0x80567698: b           L_805677E8
    // 0x8056769C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x8056769C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805676A0:
    // 0x805676A0: slti        $at, $v0, 0x417E
    ctx->r1 = SIGNED(ctx->r2) < 0X417E ? 1 : 0;
    // 0x805676A4: bne         $at, $zero, L_805676BC
    if (ctx->r1 != 0) {
        // 0x805676A8: addiu       $at, $zero, 0x4668
        ctx->r1 = ADD32(0, 0X4668);
            goto L_805676BC;
    }
    // 0x805676A8: addiu       $at, $zero, 0x4668
    ctx->r1 = ADD32(0, 0X4668);
    // 0x805676AC: beq         $v0, $at, L_8056771C
    if (ctx->r2 == ctx->r1) {
        // 0x805676B0: nop
    
            goto L_8056771C;
    }
    // 0x805676B0: nop

    // 0x805676B4: b           L_805677E8
    // 0x805676B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805676B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805676BC:
    // 0x805676BC: sltiu       $at, $t6, 0x2E
    ctx->r1 = ctx->r14 < 0X2E ? 1 : 0;
    // 0x805676C0: beq         $at, $zero, L_805677E4
    if (ctx->r1 == 0) {
        // 0x805676C4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_805677E4;
    }
    // 0x805676C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x805676C8: lui         $at, 0x8057
    ctx->r1 = S32(RELOC_HI16(378, 0X20B4) << 16);
    // 0x805676CC: addu        $at, $at, $t6
    gpr jr_addend_805676D4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x805676D0: lw          $t6, -0x699C($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(378, 0X20B4));
    // 0x805676D4: jr          $t6
    // 0x805676D8: nop

    switch (jr_addend_805676D4 >> 2) {
        case 0: goto L_805676DC; break;
        case 1: goto L_805676EC; break;
        case 2: goto L_8056770C; break;
        case 3: goto L_8056772C; break;
        case 4: goto L_8056773C; break;
        case 5: goto L_8056774C; break;
        case 6: goto L_8056775C; break;
        case 7: goto L_8056776C; break;
        case 8: goto L_8056777C; break;
        case 9: goto L_8056779C; break;
        case 10: goto L_805677AC; break;
        case 11: goto L_805677BC; break;
        case 12: goto L_805676DC; break;
        case 13: goto L_805676EC; break;
        case 14: goto L_8056770C; break;
        case 15: goto L_8056772C; break;
        case 16: goto L_8056773C; break;
        case 17: goto L_8056774C; break;
        case 18: goto L_8056775C; break;
        case 19: goto L_8056776C; break;
        case 20: goto L_8056777C; break;
        case 21: goto L_8056779C; break;
        case 22: goto L_805677AC; break;
        case 23: goto L_805677BC; break;
        case 24: goto L_805676DC; break;
        case 25: goto L_805676EC; break;
        case 26: goto L_8056770C; break;
        case 27: goto L_8056772C; break;
        case 28: goto L_8056773C; break;
        case 29: goto L_8056774C; break;
        case 30: goto L_8056775C; break;
        case 31: goto L_8056776C; break;
        case 32: goto L_8056777C; break;
        case 33: goto L_8056779C; break;
        case 34: goto L_805677AC; break;
        case 35: goto L_805677BC; break;
        case 36: goto L_805677E4; break;
        case 37: goto L_805677E4; break;
        case 38: goto L_805677E4; break;
        case 39: goto L_805677E4; break;
        case 40: goto L_805677E4; break;
        case 41: goto L_805677E4; break;
        case 42: goto L_805677E4; break;
        case 43: goto L_805677E4; break;
        case 44: goto L_805677CC; break;
        case 45: goto L_805677DC; break;
        default: switch_error(__func__, 0x805676D4, 0x80569664);
    }
    // 0x805676D8: nop

L_805676DC:
    // 0x805676DC: jal         0x805687A4
    // 0x805676E0: nop

    func_805687A4(rdram, ctx);
        goto after_0;
    // 0x805676E0: nop

    after_0:
    // 0x805676E4: b           L_805677E8
    // 0x805676E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805676E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805676EC:
    // 0x805676EC: jal         0x8056888C
    // 0x805676F0: nop

    func_8056888C(rdram, ctx);
        goto after_1;
    // 0x805676F0: nop

    after_1:
    // 0x805676F4: b           L_805677E8
    // 0x805676F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805676F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805676FC:
    // 0x805676FC: jal         0x80568974
    // 0x80567700: nop

    func_80568974(rdram, ctx);
        goto after_2;
    // 0x80567700: nop

    after_2:
    // 0x80567704: b           L_805677E8
    // 0x80567708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056770C:
    // 0x8056770C: jal         0x805689EC
    // 0x80567710: nop

    func_805689EC(rdram, ctx);
        goto after_3;
    // 0x80567710: nop

    after_3:
    // 0x80567714: b           L_805677E8
    // 0x80567718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056771C:
    // 0x8056771C: jal         0x80568AD4
    // 0x80567720: nop

    func_80568AD4(rdram, ctx);
        goto after_4;
    // 0x80567720: nop

    after_4:
    // 0x80567724: b           L_805677E8
    // 0x80567728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056772C:
    // 0x8056772C: jal         0x80568B4C
    // 0x80567730: nop

    func_80568B4C(rdram, ctx);
        goto after_5;
    // 0x80567730: nop

    after_5:
    // 0x80567734: b           L_805677E8
    // 0x80567738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056773C:
    // 0x8056773C: jal         0x80568C34
    // 0x80567740: nop

    func_80568C34(rdram, ctx);
        goto after_6;
    // 0x80567740: nop

    after_6:
    // 0x80567744: b           L_805677E8
    // 0x80567748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056774C:
    // 0x8056774C: jal         0x80568CD8
    // 0x80567750: nop

    func_80568CD8(rdram, ctx);
        goto after_7;
    // 0x80567750: nop

    after_7:
    // 0x80567754: b           L_805677E8
    // 0x80567758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056775C:
    // 0x8056775C: jal         0x80568D74
    // 0x80567760: nop

    func_80568D74(rdram, ctx);
        goto after_8;
    // 0x80567760: nop

    after_8:
    // 0x80567764: b           L_805677E8
    // 0x80567768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056776C:
    // 0x8056776C: jal         0x80568E18
    // 0x80567770: nop

    func_80568E18(rdram, ctx);
        goto after_9;
    // 0x80567770: nop

    after_9:
    // 0x80567774: b           L_805677E8
    // 0x80567778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056777C:
    // 0x8056777C: jal         0x80568EB4
    // 0x80567780: nop

    func_80568EB4(rdram, ctx);
        goto after_10;
    // 0x80567780: nop

    after_10:
    // 0x80567784: b           L_805677E8
    // 0x80567788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056778C:
    // 0x8056778C: jal         0x80568F50
    // 0x80567790: nop

    func_80568F50(rdram, ctx);
        goto after_11;
    // 0x80567790: nop

    after_11:
    // 0x80567794: b           L_805677E8
    // 0x80567798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x80567798: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8056779C:
    // 0x8056779C: jal         0x80568FC0
    // 0x805677A0: nop

    func_80568FC0(rdram, ctx);
        goto after_12;
    // 0x805677A0: nop

    after_12:
    // 0x805677A4: b           L_805677E8
    // 0x805677A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805677A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805677AC:
    // 0x805677AC: jal         0x8056908C
    // 0x805677B0: nop

    func_8056908C(rdram, ctx);
        goto after_13;
    // 0x805677B0: nop

    after_13:
    // 0x805677B4: b           L_805677E8
    // 0x805677B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805677B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805677BC:
    // 0x805677BC: jal         0x80569158
    // 0x805677C0: nop

    func_80569158(rdram, ctx);
        goto after_14;
    // 0x805677C0: nop

    after_14:
    // 0x805677C4: b           L_805677E8
    // 0x805677C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805677C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805677CC:
    // 0x805677CC: jal         0x805691F4
    // 0x805677D0: nop

    func_805691F4(rdram, ctx);
        goto after_15;
    // 0x805677D0: nop

    after_15:
    // 0x805677D4: b           L_805677E8
    // 0x805677D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_805677E8;
    // 0x805677D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805677DC:
    // 0x805677DC: jal         0x8056924C
    // 0x805677E0: nop

    func_8056924C(rdram, ctx);
        goto after_16;
    // 0x805677E0: nop

    after_16:
L_805677E4:
    // 0x805677E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805677E8:
    // 0x805677E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805677EC: jr          $ra
    // 0x805677F0: nop

    return;
    // 0x805677F0: nop

;}
RECOMP_FUNC void func_804558BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804558BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804558C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804558C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804558C8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804558CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804558D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804558D4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804558D8: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x804558DC: jal         0x8044EFA0
    // 0x804558E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x804558E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804558E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804558E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x804558EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804558F0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804558F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804558F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804558FC: jal         0x804449C0
    // 0x80455900: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x80455900: swc1        $f4, 0x6C84($at)
    MEM_W(0X6C84, ctx->r1) = ctx->f4.u32l;
    after_1:
    // 0x80455904: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80455908: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045590C: jal         0x80450490
    // 0x80455910: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x80455910: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x80455914: jal         0x8044FD5C
    // 0x80455918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_3;
    // 0x80455918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8045591C: jal         0x80445EC8
    // 0x80455920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80445EC8(rdram, ctx);
        goto after_4;
    // 0x80455920: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80455924: jal         0x8044DED8
    // 0x80455928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044DED8(rdram, ctx);
        goto after_5;
    // 0x80455928: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8045592C: jal         0x8044E684
    // 0x80455930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044E684(rdram, ctx);
        goto after_6;
    // 0x80455930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80455934: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80455938: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045593C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80455940: jr          $ra
    // 0x80455944: nop

    return;
    // 0x80455944: nop

;}
RECOMP_FUNC void func_804652A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804652A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804652AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804652B0: jal         0x80464610
    // 0x804652B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80464610(rdram, ctx);
        goto after_0;
    // 0x804652B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804652B8: jal         0x80045BD8
    // 0x804652BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x804652BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804652C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804652C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804652C8: jr          $ra
    // 0x804652CC: nop

    return;
    // 0x804652CC: nop

;}
RECOMP_FUNC void func_8001B36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B36C: beq         $a0, $zero, L_8001B3A4
    if (ctx->r4 == 0) {
        // 0x8001B370: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001B3A4;
    }
    // 0x8001B370: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B374: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B378: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x8001B37C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001B380: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8001B384: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x8001B388: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x8001B38C: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x8001B390: sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
    // 0x8001B394: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x8001B398: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x8001B39C: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8001B3A0: swc1        $f6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f6.u32l;
L_8001B3A4:
    // 0x8001B3A4: jr          $ra
    // 0x8001B3A8: nop

    return;
    // 0x8001B3A8: nop

;}
RECOMP_FUNC void func_80438234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80438234: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80438238: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043823C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80438240: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F80) << 16);
    // 0x80438244: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80438248: lwc1        $f4, -0x77E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F80));
    // 0x8043824C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80438250: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F84) << 16);
    // 0x80438254: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80438258: nop

    // 0x8043825C: bc1f        L_80438274
    if (!c1cs) {
        // 0x80438260: nop
    
            goto L_80438274;
    }
    // 0x80438260: nop

    // 0x80438264: lwc1        $f6, -0x77DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F84));
    // 0x80438268: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8043826C: nop

    // 0x80438270: bc1t        L_804382E4
    if (c1cs) {
        // 0x80438274: lui         $at, 0x8044
        ctx->r1 = S32(RELOC_HI16(77, 0X1F88) << 16);
            goto L_804382E4;
    }
L_80438274:
    // 0x80438274: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(77, 0X1F88) << 16);
    // 0x80438278: lwc1        $f8, -0x77D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(77, 0X1F88));
    // 0x8043827C: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80438280: jal         0x80065954
    // 0x80438284: nop

    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80438284: nop

    after_0:
    // 0x80438288: lh          $t6, 0x1F0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043828C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80438290: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x80438294: bnel        $t6, $at, L_804382C4
    if (ctx->r14 != ctx->r1) {
        // 0x80438298: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_804382C4;
    }
    goto skip_0;
    // 0x80438298: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_0:
    // 0x8043829C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    // 0x804382A0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x804382A4: jal         0x80067D5C
    // 0x804382A8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x804382A8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x804382AC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x804382B0: jal         0x80067F78
    // 0x804382B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x804382B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x804382B8: b           L_804382EC
    // 0x804382BC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_804382EC;
    // 0x804382BC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x804382C0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_804382C4:
    // 0x804382C4: jal         0x80067D5C
    // 0x804382C8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x804382C8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x804382CC: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x804382D0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x804382D4: jal         0x800678F0
    // 0x804382D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x804382D8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x804382DC: b           L_804382F0
    // 0x804382E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804382F0;
    // 0x804382E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804382E4:
    // 0x804382E4: jal         0x804381F4
    // 0x804382E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804381F4(rdram, ctx);
        goto after_5;
    // 0x804382E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_804382EC:
    // 0x804382EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804382F0:
    // 0x804382F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804382F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804382F8: jr          $ra
    // 0x804382FC: nop

    return;
    // 0x804382FC: nop

;}
RECOMP_FUNC void func_806DFC88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DFC88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806DFC8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806DFC90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806DFC94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806DFC98: jal         0x80062748
    // 0x806DFC9C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062748(rdram, ctx);
        goto after_0;
    // 0x806DFC9C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_0:
    // 0x806DFCA0: jal         0x806DF6E0
    // 0x806DFCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF6E0(rdram, ctx);
        goto after_1;
    // 0x806DFCA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806DFCA8: jal         0x806DFBD4
    // 0x806DFCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DFBD4(rdram, ctx);
        goto after_2;
    // 0x806DFCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806DFCB0: jal         0x806DF504
    // 0x806DFCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806DF504(rdram, ctx);
        goto after_3;
    // 0x806DFCB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806DFCB8: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(643, 0X11B0) << 16);
    // 0x806DFCBC: lwc1        $f4, 0x5E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(643, 0X11B0));
    // 0x806DFCC0: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x806DFCC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806DFCC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806DFCCC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806DFCD0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806DFCD4: bc1fl       L_806DFCE8
    if (!c1cs) {
        // 0x806DFCD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806DFCE8;
    }
    goto skip_0;
    // 0x806DFCD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806DFCDC: jal         0x806E0398
    // 0x806DFCE0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806E0398(rdram, ctx);
        goto after_4;
    // 0x806DFCE0: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806DFCE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806DFCE8:
    // 0x806DFCE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806DFCEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806DFCF0: jr          $ra
    // 0x806DFCF4: nop

    return;
    // 0x806DFCF4: nop

;}
RECOMP_FUNC void func_8001B17C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B17C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001B180: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x8001B184: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001B188: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8001B18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001B190: beq         $a0, $zero, L_8001B1F0
    if (ctx->r4 == 0) {
        // 0x8001B194: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8001B1F0;
    }
    // 0x8001B194: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001B198: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B19C: bgez        $a3, L_8001B1A8
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8001B1A0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001B1A8;
    }
    // 0x8001B1A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B1A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001B1A8:
    // 0x8001B1A8: slti        $at, $a3, 0x80
    ctx->r1 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // 0x8001B1AC: bnel        $at, $zero, L_8001B1BC
    if (ctx->r1 != 0) {
        // 0x8001B1B0: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8001B1BC;
    }
    goto skip_0;
    // 0x8001B1B0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x8001B1B4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    // 0x8001B1B8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8001B1BC:
    // 0x8001B1BC: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x8001B1C0: bc1fl       L_8001B1D0
    if (!c1cs) {
        // 0x8001B1C4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8001B1D0;
    }
    goto skip_1;
    // 0x8001B1C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_1:
    // 0x8001B1C8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8001B1CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_8001B1D0:
    // 0x8001B1D0: jal         0x8001BC8C
    // 0x8001B1D4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    func_8001BC8C(rdram, ctx);
        goto after_0;
    // 0x8001B1D4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8001B1D8: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001B1DC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001B1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001B1E4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001B1E8: jal         0x8001BC68
    // 0x8001B1EC: nop

    func_8001BC68(rdram, ctx);
        goto after_1;
    // 0x8001B1EC: nop

    after_1:
L_8001B1F0:
    // 0x8001B1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001B1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001B1F8: jr          $ra
    // 0x8001B1FC: nop

    return;
    // 0x8001B1FC: nop

;}
RECOMP_FUNC void func_8042B810(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042B810: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042B814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042B818: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x8042B81C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042B820: beq         $t6, $zero, L_8042B85C
    if (ctx->r14 == 0) {
        // 0x8042B824: nop
    
            goto L_8042B85C;
    }
    // 0x8042B824: nop

    // 0x8042B828: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042B82C: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8042B830: jalr        $t9
    // 0x8042B834: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8042B834: nop

    after_0:
    // 0x8042B838: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042B83C: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x8042B840: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x8042B844: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8042B848: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8042B84C: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8042B850: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x8042B854: b           L_8042B85C
    // 0x8042B858: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_8042B85C;
    // 0x8042B858: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_8042B85C:
    // 0x8042B85C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042B860: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042B864: jr          $ra
    // 0x8042B868: nop

    return;
    // 0x8042B868: nop

;}
RECOMP_FUNC void func_804C9340(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C9340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C9344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C9348: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x804C934C: addiu       $at, $zero, 0x4038
    ctx->r1 = ADD32(0, 0X4038);
    // 0x804C9350: beq         $v0, $at, L_804C9368
    if (ctx->r2 == ctx->r1) {
        // 0x804C9354: addiu       $at, $zero, 0x4705
        ctx->r1 = ADD32(0, 0X4705);
            goto L_804C9368;
    }
    // 0x804C9354: addiu       $at, $zero, 0x4705
    ctx->r1 = ADD32(0, 0X4705);
    // 0x804C9358: beq         $v0, $at, L_804C9374
    if (ctx->r2 == ctx->r1) {
        // 0x804C935C: lui         $a0, 0x804D
        ctx->r4 = S32(RELOC_HI16(228, 0X8F0) << 16);
            goto L_804C9374;
    }
    // 0x804C935C: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(228, 0X8F0) << 16);
    // 0x804C9360: b           L_804C9394
    // 0x804C9364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804C9394;
    // 0x804C9364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804C9368:
    // 0x804C9368: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(228, 0X570) << 16);
    // 0x804C936C: b           L_804C9394
    // 0x804C9370: addiu       $v0, $v0, -0x6750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(228, 0X570));
        goto L_804C9394;
    // 0x804C9370: addiu       $v0, $v0, -0x6750
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(228, 0X570));
L_804C9374:
    // 0x804C9374: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(228, 0X900) << 16);
    // 0x804C9378: addiu       $a1, $a1, -0x63C0
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(228, 0X900));
    // 0x804C937C: addiu       $a0, $a0, -0x63D0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(228, 0X8F0));
    // 0x804C9380: jal         0x8004667C
    // 0x804C9384: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804C9384: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x804C9388: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(228, 0X600) << 16);
    // 0x804C938C: b           L_804C9394
    // 0x804C9390: addiu       $v0, $v0, -0x66C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(228, 0X600));
        goto L_804C9394;
    // 0x804C9390: addiu       $v0, $v0, -0x66C0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(228, 0X600));
L_804C9394:
    // 0x804C9394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804C9398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C939C: jr          $ra
    // 0x804C93A0: nop

    return;
    // 0x804C93A0: nop

;}
RECOMP_FUNC void func_806E71AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E71AC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E71B0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E71B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E71B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E71BC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E71C0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E71C4: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E71C8: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(661, 0XB8) << 16);
    // 0x806E71CC: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E71D0: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E71D4: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E71D8: lw          $t1, 0x71F8($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(661, 0XB8));
    // 0x806E71DC: jr          $ra
    // 0x806E71E0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E71E0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806E71E4: nop

    // 0x806E71E8: nop

    // 0x806E71EC: nop

;}
RECOMP_FUNC void func_80005854(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005854: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80005858: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000585C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80005860: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80005864: lui         $s6, 0x800B
    ctx->r22 = S32(0X800B << 16);
    // 0x80005868: addiu       $s6, $s6, 0x4D10
    ctx->r22 = ADD32(ctx->r22, 0X4D10);
    // 0x8000586C: addiu       $a0, $a0, 0x739C
    ctx->r4 = ADD32(ctx->r4, 0X739C);
    // 0x80005870: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80005874: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80005878: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000587C: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80005880: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80005884: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80005888: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000588C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005890: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80005894: lw          $s3, 0x2690($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X2690);
    // 0x80005898: jal         0x80003698
    // 0x8000589C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    func_80003698(rdram, ctx);
        goto after_0;
    // 0x8000589C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    after_0:
    // 0x800058A0: bne         $v0, $zero, L_800058F0
    if (ctx->r2 != 0) {
        // 0x800058A4: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_800058F0;
    }
    // 0x800058A4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800058A8: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x800058AC: lw          $t6, 0x739C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X739C);
    // 0x800058B0: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800058B4: lw          $s0, 0x73A0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X73A0);
    // 0x800058B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800058BC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800058C0: addiu       $a0, $a0, 0x739C
    ctx->r4 = ADD32(ctx->r4, 0X739C);
    // 0x800058C4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800058C8: jal         0x80003698
    // 0x800058CC: sw          $t6, 0x73A0($at)
    MEM_W(0X73A0, ctx->r1) = ctx->r14;
    func_80003698(rdram, ctx);
        goto after_1;
    // 0x800058CC: sw          $t6, 0x73A0($at)
    MEM_W(0X73A0, ctx->r1) = ctx->r14;
    after_1:
    // 0x800058D0: bne         $v0, $zero, L_800058E8
    if (ctx->r2 != 0) {
        // 0x800058D4: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_800058E8;
    }
    // 0x800058D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800058D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800058DC: sw          $s0, 0x73A0($at)
    MEM_W(0X73A0, ctx->r1) = ctx->r16;
    // 0x800058E0: b           L_80005AC0
    // 0x800058E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005AC0;
    // 0x800058E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800058E8:
    // 0x800058E8: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x800058EC: lw          $s3, 0x739C($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X739C);
L_800058F0:
    // 0x800058F0: lw          $a3, 0xD84($s6)
    ctx->r7 = MEM_W(ctx->r22, 0XD84);
    // 0x800058F4: lui         $s2, 0x800B
    ctx->r18 = S32(0X800B << 16);
    // 0x800058F8: lw          $s2, 0x73A0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X73A0);
    // 0x800058FC: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
    // 0x80005900: blez        $a3, L_800059D4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80005904: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800059D4;
    }
    // 0x80005904: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80005908: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x8000590C: addiu       $a2, $a2, 0x4D10
    ctx->r6 = ADD32(ctx->r6, 0X4D10);
    // 0x80005910: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x80005914: lw          $t7, 0x390($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X390);
L_80005918:
    // 0x80005918: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8000591C: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x80005920: bne         $t7, $zero, L_800059B0
    if (ctx->r15 != 0) {
        // 0x80005924: addiu       $a0, $a2, 0x380
        ctx->r4 = ADD32(ctx->r6, 0X380);
            goto L_800059B0;
    }
    // 0x80005924: addiu       $a0, $a2, 0x380
    ctx->r4 = ADD32(ctx->r6, 0X380);
    // 0x80005928: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8000592C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80005930: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80005934: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80005938: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8000593C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80005940: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x80005944: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // 0x80005948: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8000594C: sltu        $at, $a1, $s3
    ctx->r1 = ctx->r5 < ctx->r19 ? 1 : 0;
    // 0x80005950: beq         $at, $zero, L_80005978
    if (ctx->r1 == 0) {
        // 0x80005954: sltu        $at, $v0, $s3
        ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
            goto L_80005978;
    }
    // 0x80005954: sltu        $at, $v0, $s3
    ctx->r1 = ctx->r2 < ctx->r19 ? 1 : 0;
    // 0x80005958: beq         $at, $zero, L_80005978
    if (ctx->r1 == 0) {
        // 0x8000595C: sll         $t1, $a3, 2
        ctx->r9 = S32(ctx->r7 << 2);
            goto L_80005978;
    }
    // 0x8000595C: sll         $t1, $a3, 2
    ctx->r9 = S32(ctx->r7 << 2);
    // 0x80005960: addu        $t1, $t1, $a3
    ctx->r9 = ADD32(ctx->r9, ctx->r7);
    // 0x80005964: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80005968: addiu       $t2, $t2, 0x4D10
    ctx->r10 = ADD32(ctx->r10, 0X4D10);
    // 0x8000596C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80005970: b           L_800059C0
    // 0x80005974: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
        goto L_800059C0;
    // 0x80005974: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_80005978:
    // 0x80005978: sltu        $at, $a1, $s2
    ctx->r1 = ctx->r5 < ctx->r18 ? 1 : 0;
    // 0x8000597C: bne         $at, $zero, L_800059A4
    if (ctx->r1 != 0) {
        // 0x80005980: sltu        $at, $v1, $s2
        ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
            goto L_800059A4;
    }
    // 0x80005980: sltu        $at, $v1, $s2
    ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
    // 0x80005984: bne         $at, $zero, L_800059A4
    if (ctx->r1 != 0) {
        // 0x80005988: sll         $t3, $a3, 2
        ctx->r11 = S32(ctx->r7 << 2);
            goto L_800059A4;
    }
    // 0x80005988: sll         $t3, $a3, 2
    ctx->r11 = S32(ctx->r7 << 2);
    // 0x8000598C: addu        $t3, $t3, $a3
    ctx->r11 = ADD32(ctx->r11, ctx->r7);
    // 0x80005990: lui         $t4, 0x800B
    ctx->r12 = S32(0X800B << 16);
    // 0x80005994: addiu       $t4, $t4, 0x4D10
    ctx->r12 = ADD32(ctx->r12, 0X4D10);
    // 0x80005998: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000599C: b           L_800059C0
    // 0x800059A0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
        goto L_800059C0;
    // 0x800059A0: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_800059A4:
    // 0x800059A4: sw          $s7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r23;
    // 0x800059A8: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x800059AC: lw          $a3, 0x5A94($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X5A94);
L_800059B0:
    // 0x800059B0: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800059B4: addu        $t5, $t5, $a3
    ctx->r13 = ADD32(ctx->r13, ctx->r7);
    // 0x800059B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800059BC: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_800059C0:
    // 0x800059C0: addiu       $a2, $a2, 0x14
    ctx->r6 = ADD32(ctx->r6, 0X14);
    // 0x800059C4: sltu        $at, $a2, $v0
    ctx->r1 = ctx->r6 < ctx->r2 ? 1 : 0;
    // 0x800059C8: bnel        $at, $zero, L_80005918
    if (ctx->r1 != 0) {
        // 0x800059CC: lw          $t7, 0x390($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X390);
            goto L_80005918;
    }
    goto skip_0;
    // 0x800059CC: lw          $t7, 0x390($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X390);
    skip_0:
    // 0x800059D0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800059D4:
    // 0x800059D4: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x800059D8: lw          $t7, 0x762C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X762C);
    // 0x800059DC: lui         $s0, 0x800B
    ctx->r16 = S32(0X800B << 16);
    // 0x800059E0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800059E4: blez        $t7, L_80005A74
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800059E8: addiu       $s0, $s0, 0x739C
        ctx->r16 = ADD32(ctx->r16, 0X739C);
            goto L_80005A74;
    }
    // 0x800059E8: addiu       $s0, $s0, 0x739C
    ctx->r16 = ADD32(ctx->r16, 0X739C);
    // 0x800059EC: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800059F0:
    // 0x800059F0: lb          $t8, 0x10($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X10);
    // 0x800059F4: bnel        $t8, $zero, L_80005A08
    if (ctx->r24 != 0) {
        // 0x800059F8: lw          $v1, 0x18($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X18);
            goto L_80005A08;
    }
    goto skip_1;
    // 0x800059F8: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x800059FC: b           L_80005A64
    // 0x80005A00: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
        goto L_80005A64;
    // 0x80005A00: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
    // 0x80005A04: lw          $v1, 0x18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X18);
L_80005A08:
    // 0x80005A08: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x80005A0C: addu        $a1, $t9, $v1
    ctx->r5 = ADD32(ctx->r25, ctx->r3);
    // 0x80005A10: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80005A14: sltu        $at, $a1, $s3
    ctx->r1 = ctx->r5 < ctx->r19 ? 1 : 0;
    // 0x80005A18: beq         $at, $zero, L_80005A30
    if (ctx->r1 == 0) {
        // 0x80005A1C: sltu        $at, $v1, $s3
        ctx->r1 = ctx->r3 < ctx->r19 ? 1 : 0;
            goto L_80005A30;
    }
    // 0x80005A1C: sltu        $at, $v1, $s3
    ctx->r1 = ctx->r3 < ctx->r19 ? 1 : 0;
    // 0x80005A20: beql        $at, $zero, L_80005A34
    if (ctx->r1 == 0) {
        // 0x80005A24: sltu        $at, $a1, $s2
        ctx->r1 = ctx->r5 < ctx->r18 ? 1 : 0;
            goto L_80005A34;
    }
    goto skip_2;
    // 0x80005A24: sltu        $at, $a1, $s2
    ctx->r1 = ctx->r5 < ctx->r18 ? 1 : 0;
    skip_2:
    // 0x80005A28: b           L_80005A64
    // 0x80005A2C: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
        goto L_80005A64;
    // 0x80005A2C: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
L_80005A30:
    // 0x80005A30: sltu        $at, $a1, $s2
    ctx->r1 = ctx->r5 < ctx->r18 ? 1 : 0;
L_80005A34:
    // 0x80005A34: bne         $at, $zero, L_80005A4C
    if (ctx->r1 != 0) {
        // 0x80005A38: sltu        $at, $v1, $s2
        ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
            goto L_80005A4C;
    }
    // 0x80005A38: sltu        $at, $v1, $s2
    ctx->r1 = ctx->r3 < ctx->r18 ? 1 : 0;
    // 0x80005A3C: bne         $at, $zero, L_80005A4C
    if (ctx->r1 != 0) {
        // 0x80005A40: nop
    
            goto L_80005A4C;
    }
    // 0x80005A40: nop

    // 0x80005A44: b           L_80005A64
    // 0x80005A48: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
        goto L_80005A64;
    // 0x80005A48: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
L_80005A4C:
    // 0x80005A4C: jal         0x80005AEC
    // 0x80005A50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    func_80005AEC(rdram, ctx);
        goto after_2;
    // 0x80005A50: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    after_2:
    // 0x80005A54: bnel        $s5, $s6, L_80005A64
    if (ctx->r21 != ctx->r22) {
        // 0x80005A58: lw          $v0, 0x290($s4)
        ctx->r2 = MEM_W(ctx->r20, 0X290);
            goto L_80005A64;
    }
    goto skip_3;
    // 0x80005A58: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
    skip_3:
    // 0x80005A5C: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x80005A60: lw          $v0, 0x290($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X290);
L_80005A64:
    // 0x80005A64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80005A68: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80005A6C: bne         $at, $zero, L_800059F0
    if (ctx->r1 != 0) {
        // 0x80005A70: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_800059F0;
    }
    // 0x80005A70: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_80005A74:
    // 0x80005A74: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80005A78: bne         $s5, $s6, L_80005A94
    if (ctx->r21 != ctx->r22) {
        // 0x80005A7C: lui         $t3, 0x800B
        ctx->r11 = S32(0X800B << 16);
            goto L_80005A94;
    }
    // 0x80005A7C: lui         $t3, 0x800B
    ctx->r11 = S32(0X800B << 16);
    // 0x80005A80: lui         $t0, 0x800B
    ctx->r8 = S32(0X800B << 16);
    // 0x80005A84: lw          $s5, 0x762C($t0)
    ctx->r21 = MEM_W(ctx->r8, 0X762C);
    // 0x80005A88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80005A8C: addiu       $t1, $s5, 0x1
    ctx->r9 = ADD32(ctx->r21, 0X1);
    // 0x80005A90: sw          $t1, 0x762C($at)
    MEM_W(0X762C, ctx->r1) = ctx->r9;
L_80005A94:
    // 0x80005A94: sll         $t2, $s5, 2
    ctx->r10 = S32(ctx->r21 << 2);
    // 0x80005A98: addu        $t2, $t2, $s5
    ctx->r10 = ADD32(ctx->r10, ctx->r21);
    // 0x80005A9C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80005AA0: addiu       $t3, $t3, 0x739C
    ctx->r11 = ADD32(ctx->r11, 0X739C);
    // 0x80005AA4: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x80005AA8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x80005AAC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80005AB0: sb          $s7, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r23;
    // 0x80005AB4: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x80005AB8: sw          $t4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r12;
    // 0x80005ABC: sw          $t5, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r13;
L_80005AC0:
    // 0x80005AC0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80005AC4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80005AC8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80005ACC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80005AD0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80005AD4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80005AD8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80005ADC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x80005AE0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80005AE4: jr          $ra
    // 0x80005AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80005AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_8067EA7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067EA7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067EA80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067EA84: jal         0x8067E94C
    // 0x8067EA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8067E94C(rdram, ctx);
        goto after_0;
    // 0x8067EA88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067EA8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067EA90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067EA94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8067EA98: jal         0x8067EAE0
    // 0x8067EA9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_8067EAE0(rdram, ctx);
        goto after_1;
    // 0x8067EA9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8067EAA0: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8067EAA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067EAA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067EAAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8067EAB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067EAB4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067EAB8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8067EABC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8067EAC0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067EAC4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067EAC8: jal         0x8067E728
    // 0x8067EACC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    func_8067E728(rdram, ctx);
        goto after_2;
    // 0x8067EACC: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    after_2:
    // 0x8067EAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067EAD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067EAD8: jr          $ra
    // 0x8067EADC: nop

    return;
    // 0x8067EADC: nop

;}
RECOMP_FUNC void func_80740F2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80740F2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80740F30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80740F34: jal         0x80045A34
    // 0x80740F38: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80740F38: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_0:
    // 0x80740F3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80740F40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80740F44: jr          $ra
    // 0x80740F48: nop

    return;
    // 0x80740F48: nop

;}
RECOMP_FUNC void func_805AE2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE2C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE2C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE2CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE2D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE2D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE2D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE2DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE2E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE2E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE2E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE2EC: jr          $ra
    // 0x805AE2F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE2F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80077338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077338: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8007733C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80077340: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80077344: sll         $t0, $a2, 7
    ctx->r8 = S32(ctx->r6 << 7);
    // 0x80077348: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8007734C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80077350: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80077354: addiu       $t2, $t2, -0x79C8
    ctx->r10 = ADD32(ctx->r10, -0X79C8);
    // 0x80077358: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8007735C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80077360: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
    // 0x80077364: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80077368: sw          $t3, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r11;
    // 0x8007736C: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80077370: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80077374: beq         $a1, $at, L_80077394
    if (ctx->r5 == ctx->r1) {
        // 0x80077378: lw          $t4, 0x4($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X4);
            goto L_80077394;
    }
    // 0x80077378: lw          $t4, 0x4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4);
    // 0x8007737C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x80077380: sw          $t5, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r13;
    // 0x80077384: lui         $t6, 0xBA00
    ctx->r14 = S32(0XBA00 << 16);
    // 0x80077388: ori         $t6, $t6, 0xE02
    ctx->r14 = ctx->r14 | 0XE02;
    // 0x8007738C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80077390: sw          $a1, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r5;
L_80077394:
    // 0x80077394: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x80077398: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007739C: jr          $ra
    // 0x800773A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800773A0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void func_8078C7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078C7E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078C7E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078C7E8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078C7EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078C7F0: jal         0x80047090
    // 0x8078C7F4: addiu       $a0, $zero, 0x4675
    ctx->r4 = ADD32(0, 0X4675);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8078C7F4: addiu       $a0, $zero, 0x4675
    ctx->r4 = ADD32(0, 0X4675);
    after_0:
    // 0x8078C7F8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x8078C7FC: beq         $v0, $at, L_8078C864
    if (ctx->r2 == ctx->r1) {
        // 0x8078C800: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8078C864;
    }
    // 0x8078C800: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x8078C804: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8078C808: lui         $at, 0x4675
    ctx->r1 = S32(0X4675 << 16);
    // 0x8078C80C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x8078C810: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8078C814: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8078C818: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8078C81C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8078C820: jal         0x8004613C
    // 0x8078C824: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x8078C824: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x8078C828: beq         $v0, $zero, L_8078C864
    if (ctx->r2 == 0) {
        // 0x8078C82C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8078C864;
    }
    // 0x8078C82C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8078C830: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8078C834: jal         0x80047F9C
    // 0x8078C838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x8078C838: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8078C83C: jal         0x8078B894
    // 0x8078C840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8078B894(rdram, ctx);
        goto after_3;
    // 0x8078C840: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8078C844: beq         $v0, $zero, L_8078C85C
    if (ctx->r2 == 0) {
        // 0x8078C848: nop
    
            goto L_8078C85C;
    }
    // 0x8078C848: nop

    // 0x8078C84C: jal         0x8005FCA8
    // 0x8078C850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FCA8(rdram, ctx);
        goto after_4;
    // 0x8078C850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8078C854: b           L_8078C868
    // 0x8078C858: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_8078C868;
    // 0x8078C858: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_8078C85C:
    // 0x8078C85C: b           L_8078C868
    // 0x8078C860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078C868;
    // 0x8078C860: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078C864:
    // 0x8078C864: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078C868:
    // 0x8078C868: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078C86C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078C870: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078C874: jr          $ra
    // 0x8078C878: nop

    return;
    // 0x8078C878: nop

    // 0x8078C87C: nop

;}
RECOMP_FUNC void func_8070F454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8070F454: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8070F458: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8070F45C: lw          $t6, -0x76F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76F8);
    // 0x8070F460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8070F464: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8070F468: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8070F46C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8070F470: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8070F474: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8070F478: lw          $t9, 0xAC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XAC);
    // 0x8070F47C: jalr        $t9
    // 0x8070F480: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8070F480: nop

    after_0:
    // 0x8070F484: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X1900) << 16);
    // 0x8070F488: lwc1        $f4, 0xCF0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X1900));
    // 0x8070F48C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070F490: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8070F494: jal         0x80047F9C
    // 0x8070F498: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x8070F498: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x8070F49C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X1904) << 16);
    // 0x8070F4A0: lwc1        $f6, 0xCF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X1904));
    // 0x8070F4A4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8070F4A8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8070F4AC: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x8070F4B0: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x8070F4B4: lui         $a2, 0x41B0
    ctx->r6 = S32(0X41B0 << 16);
    // 0x8070F4B8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8070F4BC: jal         0x8005CEBC
    // 0x8070F4C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_2;
    // 0x8070F4C0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8070F4C4: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8070F4C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070F4CC: jal         0x80047F9C
    // 0x8070F4D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8070F4D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x8070F4D4: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X1908) << 16);
    // 0x8070F4D8: lwc1        $f8, 0xCF8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X1908));
    // 0x8070F4DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8070F4E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8070F4E4: addiu       $a0, $zero, 0x40F1
    ctx->r4 = ADD32(0, 0X40F1);
    // 0x8070F4E8: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8070F4EC: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    // 0x8070F4F0: lui         $a3, 0x4264
    ctx->r7 = S32(0X4264 << 16);
    // 0x8070F4F4: jal         0x8005CEBC
    // 0x8070F4F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_4;
    // 0x8070F4F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8070F4FC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8070F500: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070F504: jal         0x80047F9C
    // 0x8070F508: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8070F508: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8070F50C: lui         $at, 0x8071
    ctx->r1 = S32(RELOC_HI16(724, 0X190C) << 16);
    // 0x8070F510: lwc1        $f10, 0xCFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(724, 0X190C));
    // 0x8070F514: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8070F518: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8070F51C: addiu       $a0, $zero, 0x40F2
    ctx->r4 = ADD32(0, 0X40F2);
    // 0x8070F520: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x8070F524: lui         $a2, 0x429C
    ctx->r6 = S32(0X429C << 16);
    // 0x8070F528: lui         $a3, 0x4292
    ctx->r7 = S32(0X4292 << 16);
    // 0x8070F52C: jal         0x8005CEBC
    // 0x8070F530: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_8005CEBC(rdram, ctx);
        goto after_6;
    // 0x8070F530: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8070F534: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8070F538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070F53C: jal         0x80047F9C
    // 0x8070F540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x8070F540: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8070F544: lui         $a3, 0x7F7F
    ctx->r7 = S32(0X7F7F << 16);
    // 0x8070F548: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8070F54C: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x8070F550: lui         $a1, 0x4320
    ctx->r5 = S32(0X4320 << 16);
    // 0x8070F554: jal         0x8004613C
    // 0x8070F558: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x8070F558: lui         $a2, 0x42F0
    ctx->r6 = S32(0X42F0 << 16);
    after_8:
    // 0x8070F55C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8070F560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8070F564: jal         0x80047F9C
    // 0x8070F568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x8070F568: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x8070F56C: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x8070F570: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8070F574: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8070F578: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x8070F57C: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x8070F580: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8070F584: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8070F588: lw          $t6, 0x16C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X16C);
    // 0x8070F58C: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8070F590: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8070F594: sb          $t4, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r12;
    // 0x8070F598: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8070F59C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8070F5A0: lw          $t7, -0x7490($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7490);
    // 0x8070F5A4: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x8070F5A8: lui         $t2, 0x8010
    ctx->r10 = S32(0X8010 << 16);
    // 0x8070F5AC: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x8070F5B0: lw          $t9, -0x748C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X748C);
    // 0x8070F5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8070F5B8: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
    // 0x8070F5BC: lw          $t8, -0x7488($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7488);
    // 0x8070F5C0: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x8070F5C4: lw          $t0, -0x7484($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7484);
    // 0x8070F5C8: sw          $t0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r8;
    // 0x8070F5CC: lw          $t1, -0x7480($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7480);
    // 0x8070F5D0: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x8070F5D4: lw          $t2, -0x747C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X747C);
    // 0x8070F5D8: jal         0x8070F400
    // 0x8070F5DC: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    func_8070F400(rdram, ctx);
        goto after_10;
    // 0x8070F5DC: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    after_10:
    // 0x8070F5E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8070F5E4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8070F5E8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8070F5EC: jr          $ra
    // 0x8070F5F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8070F5F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800697F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800697F0: addiu       $sp, $sp, -0x438
    ctx->r29 = ADD32(ctx->r29, -0X438);
    // 0x800697F4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800697F8: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x800697FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80069800: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80069804: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80069808: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006980C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80069810: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x80069814: addiu       $a0, $a0, -0x71A8
    ctx->r4 = ADD32(ctx->r4, -0X71A8);
    // 0x80069818: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
    // 0x8006981C: jal         0x80065728
    // 0x80069820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x80069820: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80069824: jal         0x80069B34
    // 0x80069828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80069B34(rdram, ctx);
        goto after_1;
    // 0x80069828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006982C: beq         $v0, $zero, L_8006983C
    if (ctx->r2 == 0) {
        // 0x80069830: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_8006983C;
    }
    // 0x80069830: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80069834: b           L_80069870
    // 0x80069838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80069870;
    // 0x80069838: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006983C:
    // 0x8006983C: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x80069840: addiu       $s3, $s3, 0x6F58
    ctx->r19 = ADD32(ctx->r19, 0X6F58);
    // 0x80069844: addiu       $s0, $s0, 0x6F1C
    ctx->r16 = ADD32(ctx->r16, 0X6F1C);
L_80069848:
    // 0x80069848: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8006984C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80069850: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80069854: jal         0x800655F4
    // 0x80069858: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    func_800655F4(rdram, ctx);
        goto after_2;
    // 0x80069858: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    after_2:
    // 0x8006985C: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x80069860: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80069864: bne         $s0, $s3, L_80069848
    if (ctx->r16 != ctx->r19) {
        // 0x80069868: addu        $s1, $s1, $t6
        ctx->r17 = ADD32(ctx->r17, ctx->r14);
            goto L_80069848;
    }
    // 0x80069868: addu        $s1, $s1, $t6
    ctx->r17 = ADD32(ctx->r17, ctx->r14);
    // 0x8006986C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80069870:
    // 0x80069870: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80069874: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80069878: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006987C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80069880: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80069884: jr          $ra
    // 0x80069888: addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
    return;
    // 0x80069888: addiu       $sp, $sp, 0x438
    ctx->r29 = ADD32(ctx->r29, 0X438);
;}
RECOMP_FUNC void func_800715E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800715E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800715E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800715E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800715EC: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800715F0: addiu       $a1, $a1, 0x1B04
    ctx->r5 = ADD32(ctx->r5, 0X1B04);
    // 0x800715F4: jal         0x8007E3D0
    // 0x800715F8: addiu       $a0, $a0, -0x6340
    ctx->r4 = ADD32(ctx->r4, -0X6340);
    func_8007E3D0(rdram, ctx);
        goto after_0;
    // 0x800715F8: addiu       $a0, $a0, -0x6340
    ctx->r4 = ADD32(ctx->r4, -0X6340);
    after_0:
    // 0x800715FC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071600: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80071604: addiu       $a1, $a1, 0x1B14
    ctx->r5 = ADD32(ctx->r5, 0X1B14);
    // 0x80071608: jal         0x8007E3D0
    // 0x8007160C: addiu       $a0, $a0, -0x6360
    ctx->r4 = ADD32(ctx->r4, -0X6360);
    func_8007E3D0(rdram, ctx);
        goto after_1;
    // 0x8007160C: addiu       $a0, $a0, -0x6360
    ctx->r4 = ADD32(ctx->r4, -0X6360);
    after_1:
    // 0x80071610: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071614: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071618: addiu       $a1, $a1, -0x6328
    ctx->r5 = ADD32(ctx->r5, -0X6328);
    // 0x8007161C: addiu       $a0, $a0, -0x6340
    ctx->r4 = ADD32(ctx->r4, -0X6340);
    // 0x80071620: jal         0x8008AE20
    // 0x80071624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x80071624: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80071628: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007162C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071630: addiu       $a1, $a1, -0x6348
    ctx->r5 = ADD32(ctx->r5, -0X6348);
    // 0x80071634: addiu       $a0, $a0, -0x6360
    ctx->r4 = ADD32(ctx->r4, -0X6360);
    // 0x80071638: jal         0x8008AE20
    // 0x8007163C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x8007163C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80071640: lui         $t7, 0x800B
    ctx->r15 = S32(0X800B << 16);
    // 0x80071644: addiu       $t7, $t7, 0x1B24
    ctx->r15 = ADD32(ctx->r15, 0X1B24);
    // 0x80071648: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8007164C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80071650: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80071654: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80071658: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007165C: addiu       $a2, $a2, -0x6380
    ctx->r6 = ADD32(ctx->r6, -0X6380);
    // 0x80071660: addiu       $a1, $a1, -0x6D80
    ctx->r5 = ADD32(ctx->r5, -0X6D80);
    // 0x80071664: addiu       $a0, $a0, -0x6380
    ctx->r4 = ADD32(ctx->r4, -0X6380);
    // 0x80071668: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007166C: jal         0x80081910
    // 0x80071670: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    StackCheck_Init(rdram, ctx);
        goto after_4;
    // 0x80071670: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80071674: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80071678: addiu       $t8, $t8, -0x6380
    ctx->r24 = ADD32(ctx->r24, -0X6380);
    // 0x8007167C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80071680: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80071684: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80071688: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007168C: addiu       $a2, $a2, 0x14C0
    ctx->r6 = ADD32(ctx->r6, 0X14C0);
    // 0x80071690: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    // 0x80071694: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80071698: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8007169C: jal         0x80085B10
    // 0x800716A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_5;
    // 0x800716A0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x800716A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800716A8: jal         0x80090CC0
    // 0x800716AC: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    osStartThread_recomp(rdram, ctx);
        goto after_6;
    // 0x800716AC: addiu       $a0, $a0, -0x6F30
    ctx->r4 = ADD32(ctx->r4, -0X6F30);
    after_6:
    // 0x800716B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800716B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800716B8: jr          $ra
    // 0x800716BC: nop

    return;
    // 0x800716BC: nop

;}
RECOMP_FUNC void func_8044B0EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044B0EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8044B0F0: lui         $t6, 0x8045
    ctx->r14 = S32(RELOC_HI16(98, 0X13504) << 16);
    // 0x8044B0F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044B0F8: addiu       $t6, $t6, 0x78E4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(98, 0X13504));
    // 0x8044B0FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8044B100: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8044B104: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8044B108: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8044B10C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8044B110: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044B114: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8044B118: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8044B11C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8044B120: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8044B124: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8044B128: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x8044B12C: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044B130: lw          $t9, 0x6980($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X6980);
    // 0x8044B134: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8044B138: jal         0x80050A50
    // 0x8044B13C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    func_80050A50(rdram, ctx);
        goto after_0;
    // 0x8044B13C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x8044B140: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8044B144: jalr        $v0
    // 0x8044B148: sw          $v0, 0x6A6C($v1)
    MEM_W(0X6A6C, ctx->r3) = ctx->r2;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8044B148: sw          $v0, 0x6A6C($v1)
    MEM_W(0X6A6C, ctx->r3) = ctx->r2;
    after_1:
    // 0x8044B14C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8044B150: sw          $v0, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r2;
    // 0x8044B154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044B158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8044B15C: jr          $ra
    // 0x8044B160: nop

    return;
    // 0x8044B160: nop

;}
RECOMP_FUNC void func_80039BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039BF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80039BFC: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039C00: addiu       $a0, $a0, 0x6FB0
    ctx->r4 = ADD32(ctx->r4, 0X6FB0);
    // 0x80039C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039C08: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x80039C0C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80039C10: sw          $a0, 0x4274($at)
    MEM_W(0X4274, ctx->r1) = ctx->r4;
    // 0x80039C14: addiu       $a1, $a1, 0x6FC0
    ctx->r5 = ADD32(ctx->r5, 0X6FC0);
    // 0x80039C18: jal         0x8004667C
    // 0x80039C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x80039C1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80039C20: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039C24: addiu       $a0, $a0, 0x6FC0
    ctx->r4 = ADD32(ctx->r4, 0X6FC0);
    // 0x80039C28: jal         0x80039ABC
    // 0x80039C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80039ABC(rdram, ctx);
        goto after_1;
    // 0x80039C2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80039C30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039C34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039C38: jr          $ra
    // 0x80039C3C: nop

    return;
    // 0x80039C3C: nop

;}
RECOMP_FUNC void func_8078D1E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078D1E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078D1E8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078D1EC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8078D1F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078D1F4: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x8078D1F8: jal         0x80067878
    // 0x8078D1FC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8078D1FC: lh          $a1, 0x1F0($t6)
    ctx->r5 = MEM_H(ctx->r14, 0X1F0);
    after_0:
    // 0x8078D200: jal         0x80045BD8
    // 0x8078D204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x8078D204: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8078D208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078D20C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078D210: jr          $ra
    // 0x8078D214: nop

    return;
    // 0x8078D214: nop

;}
RECOMP_FUNC void func_807B2A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B2A24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x807B2A28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x807B2A2C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x807B2A30: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x807B2A34: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x807B2A38: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807B2A3C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807B2A40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807B2A44: jal         0x8004700C
    // 0x807B2A48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x807B2A48: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x807B2A4C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x807B2A50: lw          $s0, 0x1F4($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X1F4);
    // 0x807B2A54: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807B2A58: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x807B2A5C: addiu       $s1, $s0, 0x6C
    ctx->r17 = ADD32(ctx->r16, 0X6C);
    // 0x807B2A60: addiu       $s3, $s0, 0x4
    ctx->r19 = ADD32(ctx->r16, 0X4);
    // 0x807B2A64: jal         0x807B0E30
    // 0x807B2A68: lw          $s2, 0x0($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X0);
    func_807B0E30(rdram, ctx);
        goto after_1;
    // 0x807B2A68: lw          $s2, 0x0($v1)
    ctx->r18 = MEM_W(ctx->r3, 0X0);
    after_1:
    // 0x807B2A6C: addiu       $s4, $s5, 0xC4
    ctx->r20 = ADD32(ctx->r21, 0XC4);
    // 0x807B2A70: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B2A74: jal         0x80048F84
    // 0x807B2A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x807B2A78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x807B2A7C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x807B2A80: jal         0x80048F84
    // 0x807B2A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x807B2A84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x807B2A88: jal         0x807B26B8
    // 0x807B2A8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_807B26B8(rdram, ctx);
        goto after_4;
    // 0x807B2A8C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x807B2A90: jal         0x807B20D8
    // 0x807B2A94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_807B20D8(rdram, ctx);
        goto after_5;
    // 0x807B2A94: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x807B2A98: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x807B2A9C: beq         $a1, $zero, L_807B2AAC
    if (ctx->r5 == 0) {
        // 0x807B2AA0: nop
    
            goto L_807B2AAC;
    }
    // 0x807B2AA0: nop

    // 0x807B2AA4: jal         0x807B2470
    // 0x807B2AA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_807B2470(rdram, ctx);
        goto after_6;
    // 0x807B2AA8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_6:
L_807B2AAC:
    // 0x807B2AAC: jal         0x807B10B8
    // 0x807B2AB0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    func_807B10B8(rdram, ctx);
        goto after_7;
    // 0x807B2AB0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    after_7:
    // 0x807B2AB4: lw          $t6, 0x170($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X170);
    // 0x807B2AB8: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x807B2ABC: beql        $t6, $zero, L_807B2AFC
    if (ctx->r14 == 0) {
        // 0x807B2AC0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_807B2AFC;
    }
    goto skip_0;
    // 0x807B2AC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    skip_0:
    // 0x807B2AC4: lwc1        $f12, 0x150($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X150);
    // 0x807B2AC8: lwc1        $f2, 0x14C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x807B2ACC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x807B2AD0: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x807B2AD4: swc1        $f12, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f12.u32l;
    // 0x807B2AD8: swc1        $f2, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f2.u32l;
    // 0x807B2ADC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B2AE0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B2AE4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B2AE8: jal         0x807B1A50
    // 0x807B2AEC: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    func_807B1A50(rdram, ctx);
        goto after_8;
    // 0x807B2AEC: swc1        $f0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f0.u32l;
    after_8:
    // 0x807B2AF0: b           L_807B2B20
    // 0x807B2AF4: nop

        goto L_807B2B20;
    // 0x807B2AF4: nop

    // 0x807B2AF8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_807B2AFC:
    // 0x807B2AFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2B00: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x807B2B04: jal         0x807B1048
    // 0x807B2B08: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_807B1048(rdram, ctx);
        goto after_9;
    // 0x807B2B08: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_9:
    // 0x807B2B0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x807B2B10: addiu       $s3, $s3, 0x6
    ctx->r19 = ADD32(ctx->r19, 0X6);
    // 0x807B2B14: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x807B2B18: bne         $s0, $s4, L_807B2AFC
    if (ctx->r16 != ctx->r20) {
        // 0x807B2B1C: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_807B2AFC;
    }
    // 0x807B2B1C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_807B2B20:
    // 0x807B2B20: jal         0x807B101C
    // 0x807B2B24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    func_807B101C(rdram, ctx);
        goto after_10;
    // 0x807B2B24: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x807B2B28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x807B2B2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807B2B30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807B2B34: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x807B2B38: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x807B2B3C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x807B2B40: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x807B2B44: jr          $ra
    // 0x807B2B48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x807B2B48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800490D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800490D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800490DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800490E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800490E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800490E8: jal         0x800490A8
    // 0x800490EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_800490A8(rdram, ctx);
        goto after_0;
    // 0x800490EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800490F0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800490F4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800490F8: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800490FC: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80049100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049104: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049108: jr          $ra
    // 0x8004910C: nop

    return;
    // 0x8004910C: nop

;}
RECOMP_FUNC void func_80475F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475F18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475F1C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475F20: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475F24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475F28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475F2C: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26E58) << 16);
    // 0x80475F30: addiu       $a2, $a2, -0x49E8
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26E58));
    // 0x80475F34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80475F38: jal         0x80475BBC
    // 0x80475F3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475BBC(rdram, ctx);
        goto after_0;
    // 0x80475F3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475F40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475F44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475F48: jr          $ra
    // 0x80475F4C: nop

    return;
    // 0x80475F4C: nop

;}
RECOMP_FUNC void func_8006586C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006586C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80065870: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80065874: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80065878: nop

    // 0x8006587C: bc1fl       L_800658A4
    if (!c1cs) {
        // 0x80065880: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800658A4;
    }
    goto skip_0;
    // 0x80065880: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x80065884: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80065888: nop

    // 0x8006588C: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80065890: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80065894: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80065898: jr          $ra
    // 0x8006589C: nop

    return;
    // 0x8006589C: nop

    // 0x800658A0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800658A4:
    // 0x800658A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800658A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800658AC: bc1f        L_800658D0
    if (!c1cs) {
        // 0x800658B0: nop
    
            goto L_800658D0;
    }
    // 0x800658B0: nop

    // 0x800658B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800658B8: nop

    // 0x800658BC: sub.s       $f16, $f12, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800658C0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800658C4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x800658C8: jr          $ra
    // 0x800658CC: nop

    return;
    // 0x800658CC: nop

L_800658D0:
    // 0x800658D0: jr          $ra
    // 0x800658D4: nop

    return;
    // 0x800658D4: nop

;}
RECOMP_FUNC void func_807BC420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BC420: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807BC424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807BC428: lw          $v0, 0x1E0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1E0);
    // 0x807BC42C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x807BC430: beq         $v0, $zero, L_807BC440
    if (ctx->r2 == 0) {
        // 0x807BC434: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807BC440;
    }
    // 0x807BC434: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807BC438: b           L_807BC464
    // 0x807BC43C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
        goto L_807BC464;
    // 0x807BC43C: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
L_807BC440:
    // 0x807BC440: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x807BC444: jal         0x80062DD4
    // 0x807BC448: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80062DD4(rdram, ctx);
        goto after_0;
    // 0x807BC448: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x807BC44C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807BC450: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x807BC454: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BC458: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807BC45C: jal         0x807BC4D4
    // 0x807BC460: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    func_807BC4D4(rdram, ctx);
        goto after_1;
    // 0x807BC460: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    after_1:
L_807BC464:
    // 0x807BC464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807BC468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807BC46C: jr          $ra
    // 0x807BC470: nop

    return;
    // 0x807BC470: nop

;}
RECOMP_FUNC void func_806F9840(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F9844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F9848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F984C: jal         0x80045A34
    // 0x806F9850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806F9850: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x806F9854: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806F9858: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F985C: bne         $v0, $zero, L_806F9874
    if (ctx->r2 != 0) {
        // 0x806F9860: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_806F9874;
    }
    // 0x806F9860: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x806F9864: jal         0x800445A4
    // 0x806F9868: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F9868: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x806F986C: b           L_806F9884
    // 0x806F9870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F9884;
    // 0x806F9870: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806F9874:
    // 0x806F9874: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x806F9878: jal         0x800657CC
    // 0x806F987C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_800657CC(rdram, ctx);
        goto after_2;
    // 0x806F987C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x806F9880: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806F9884:
    // 0x806F9884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F9888: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F988C: jr          $ra
    // 0x806F9890: nop

    return;
    // 0x806F9890: nop

;}
RECOMP_FUNC void func_804719F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804719F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804719FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80471A00: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x80471A04: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80471A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471A0C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80471A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80471A14: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80471A18: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80471A1C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80471A20: lui         $t2, 0x8047
    ctx->r10 = S32(RELOC_HI16(158, 0X1A8C) << 16);
    // 0x80471A24: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80471A28: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80471A2C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80471A30: lw          $t2, 0x2F4C($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(158, 0X1A8C));
    // 0x80471A34: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80471A38: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80471A3C: jal         0x80471860
    // 0x80471A40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80471860(rdram, ctx);
        goto after_0;
    // 0x80471A40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80471A44: jal         0x804718BC
    // 0x80471A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804718BC(rdram, ctx);
        goto after_1;
    // 0x80471A48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80471A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80471A50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80471A54: jr          $ra
    // 0x80471A58: nop

    return;
    // 0x80471A58: nop

;}
RECOMP_FUNC void func_80670FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80670FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80670FE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80670FE4: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x80670FE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80670FEC: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(526, 0X2180) << 16);
    // 0x80670FF0: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80670FF4: addiu       $t7, $t7, 0x2CB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(526, 0X2180));
    // 0x80670FF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80670FFC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80671000: sw          $t9, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r25;
    // 0x80671004: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80671008: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8067100C: jal         0x80045A34
    // 0x80671010: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80671010: addiu       $a1, $zero, 0xB0
    ctx->r5 = ADD32(0, 0XB0);
    after_0:
    // 0x80671014: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80671018: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8067101C: jal         0x80670B40
    // 0x80671020: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    func_80670B40(rdram, ctx);
        goto after_1;
    // 0x80671020: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    after_1:
    // 0x80671024: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80671028: jal         0x80672C80
    // 0x8067102C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80672C80(rdram, ctx);
        goto after_2;
    // 0x8067102C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80671030: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80671034: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80671038: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8067103C: sb          $zero, 0x14($v0)
    MEM_B(0X14, ctx->r2) = 0;
    // 0x80671040: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80671044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80671048: jal         0x80068D24
    // 0x8067104C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80068D24(rdram, ctx);
        goto after_3;
    // 0x8067104C: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_3:
    // 0x80671050: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80671054: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80671058: jr          $ra
    // 0x8067105C: nop

    return;
    // 0x8067105C: nop

;}
RECOMP_FUNC void func_8006976C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006976C: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80069770: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80069774: lw          $v1, 0x13B4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X13B4);
    // 0x80069778: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x8006977C: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x80069780: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80069784: bne         $v0, $zero, L_800697E8
    if (ctx->r2 != 0) {
        // 0x80069788: nop
    
            goto L_800697E8;
    }
    // 0x80069788: nop

    // 0x8006978C: sll         $v0, $v1, 5
    ctx->r2 = S32(ctx->r3 << 5);
    // 0x80069790: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x80069794: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x80069798: bne         $v0, $zero, L_800697E8
    if (ctx->r2 != 0) {
        // 0x8006979C: nop
    
            goto L_800697E8;
    }
    // 0x8006979C: nop

    // 0x800697A0: sll         $v0, $v1, 7
    ctx->r2 = S32(ctx->r3 << 7);
    // 0x800697A4: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x800697A8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800697AC: bne         $v0, $zero, L_800697E8
    if (ctx->r2 != 0) {
        // 0x800697B0: nop
    
            goto L_800697E8;
    }
    // 0x800697B0: nop

    // 0x800697B4: sll         $v0, $v1, 9
    ctx->r2 = S32(ctx->r3 << 9);
    // 0x800697B8: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x800697BC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800697C0: bne         $v0, $zero, L_800697E8
    if (ctx->r2 != 0) {
        // 0x800697C4: nop
    
            goto L_800697E8;
    }
    // 0x800697C4: nop

    // 0x800697C8: sll         $v0, $v1, 11
    ctx->r2 = S32(ctx->r3 << 11);
    // 0x800697CC: srl         $v0, $v0, 30
    ctx->r2 = S32(U32(ctx->r2) >> 30);
    // 0x800697D0: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800697D4: bne         $v0, $zero, L_800697E8
    if (ctx->r2 != 0) {
        // 0x800697D8: nop
    
            goto L_800697E8;
    }
    // 0x800697D8: nop

    // 0x800697DC: lhu         $v0, 0x13B4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X13B4);
    // 0x800697E0: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x800697E4: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
L_800697E8:
    // 0x800697E8: jr          $ra
    // 0x800697EC: nop

    return;
    // 0x800697EC: nop

;}
RECOMP_FUNC void func_80735B44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80735B44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80735B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80735B4C: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80735B50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80735B54: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80735B58: beq         $a1, $at, L_80735B7C
    if (ctx->r5 == ctx->r1) {
        // 0x80735B5C: addiu       $a0, $zero, 0x61
        ctx->r4 = ADD32(0, 0X61);
            goto L_80735B7C;
    }
    // 0x80735B5C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80735B60: jal         0x80067930
    // 0x80735B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80735B64: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80735B68: beq         $v0, $zero, L_80735B7C
    if (ctx->r2 == 0) {
        // 0x80735B6C: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80735B7C;
    }
    // 0x80735B6C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80735B70: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    // 0x80735B74: jal         0x80067878
    // 0x80735B78: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80735B78: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_80735B7C:
    // 0x80735B7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80735B80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80735B84: jr          $ra
    // 0x80735B88: nop

    return;
    // 0x80735B88: nop

;}
RECOMP_FUNC void func_80582EF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80582EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80582EFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80582F00: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x80582F04: lui         $t6, 0x8058
    ctx->r14 = S32(RELOC_HI16(399, 0X474C) << 16);
    // 0x80582F08: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x80582F0C: addiu       $t6, $t6, 0x355C
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(399, 0X474C));
    // 0x80582F10: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80582F14: sw          $zero, 0x24($a0)
    MEM_W(0X24, ctx->r4) = 0;
    // 0x80582F18: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x80582F1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80582F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80582F24: jal         0x80582EC0
    // 0x80582F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80582EC0(rdram, ctx);
        goto after_0;
    // 0x80582F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80582F2C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80582F30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80582F34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80582F38: lui         $at, 0xC1F8
    ctx->r1 = S32(0XC1F8 << 16);
    // 0x80582F3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80582F40: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80582F44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80582F48: lwc1        $f8, 0x6C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80582F4C: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(399, 0X4814) << 16);
    // 0x80582F50: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80582F54: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80582F58: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x80582F5C: swc1        $f6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f6.u32l;
    // 0x80582F60: lwc1        $f18, 0x70($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X70);
    // 0x80582F64: lw          $t9, 0x16C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X16C);
    // 0x80582F68: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80582F6C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80582F70: swc1        $f16, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f16.u32l;
    // 0x80582F74: lwc1        $f4, 0x3624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(399, 0X4814));
    // 0x80582F78: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80582F7C: swc1        $f6, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f6.u32l;
    // 0x80582F80: sb          $t8, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r24;
    // 0x80582F84: sb          $t0, 0x31($a0)
    MEM_B(0X31, ctx->r4) = ctx->r8;
    // 0x80582F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80582F8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80582F90: jr          $ra
    // 0x80582F94: nop

    return;
    // 0x80582F94: nop

    // 0x80582F98: nop

    // 0x80582F9C: nop

;}
RECOMP_FUNC void func_805A628C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A628C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805A6290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6294: jal         0x805A5DF0
    // 0x805A6298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A6298: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A629C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805A62A0: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x805A62A4: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x805A62A8: andi        $t8, $t7, 0xF00
    ctx->r24 = ctx->r15 & 0XF00;
    // 0x805A62AC: beql        $t8, $zero, L_805A62C0
    if (ctx->r24 == 0) {
        // 0x805A62B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A62C0;
    }
    goto skip_0;
    // 0x805A62B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A62B4: jal         0x805A6730
    // 0x805A62B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_805A6730(rdram, ctx);
        goto after_1;
    // 0x805A62B8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x805A62BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A62C0:
    // 0x805A62C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805A62C4: jr          $ra
    // 0x805A62C8: nop

    return;
    // 0x805A62C8: nop

;}
RECOMP_FUNC void func_8005EC14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EC14: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005EC18: addiu       $t6, $zero, 0x12
    ctx->r14 = ADD32(0, 0X12);
    // 0x8005EC1C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8005EC20: addiu       $t8, $t8, 0x6450
    ctx->r24 = ADD32(ctx->r24, 0X6450);
    // 0x8005EC24: sb          $t6, 0x38($t7)
    MEM_B(0X38, ctx->r15) = ctx->r14;
    // 0x8005EC28: jr          $ra
    // 0x8005EC2C: sw          $t8, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = ctx->r24;
    return;
    // 0x8005EC2C: sw          $t8, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_804F36A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804F36A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804F36A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804F36A8: jal         0x804F3680
    // 0x804F36AC: nop

    func_804F3680(rdram, ctx);
        goto after_0;
    // 0x804F36AC: nop

    after_0:
    // 0x804F36B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804F36B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804F36B8: jr          $ra
    // 0x804F36BC: nop

    return;
    // 0x804F36BC: nop

;}
RECOMP_FUNC void Fault_SetFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071250: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80071254: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80071258: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8007125C: addiu       $v0, $v0, -0x7968
    ctx->r2 = ADD32(ctx->r2, -0X7968);
    // 0x80071260: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80071264: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80071268: sw          $a0, 0x5CC($v0)
    MEM_W(0X5CC, ctx->r2) = ctx->r4;
    // 0x8007126C: sh          $a1, 0x5D0($v0)
    MEM_H(0X5D0, ctx->r2) = ctx->r5;
    // 0x80071270: sh          $a2, 0x5D2($v0)
    MEM_H(0X5D2, ctx->r2) = ctx->r6;
    // 0x80071274: jr          $ra
    // 0x80071278: nop

    return;
    // 0x80071278: nop

;}
RECOMP_FUNC void func_80536324(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536324: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80536328: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8053632C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80536330: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80536334: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80536338: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8053633C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80536340: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80536344: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80536348: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8053634C: jr          $ra
    // 0x80536350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80536350: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8073D1F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073D1F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8073D1FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073D200: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073D204: jal         0x8073D2A8
    // 0x8073D208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8073D2A8(rdram, ctx);
        goto after_0;
    // 0x8073D208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8073D20C: beq         $v0, $zero, L_8073D28C
    if (ctx->r2 == 0) {
        // 0x8073D210: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_8073D28C;
    }
    // 0x8073D210: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8073D214: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8073D218: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8073D21C: lui         $t7, 0x8074
    ctx->r15 = S32(RELOC_HI16(745, 0X1428) << 16);
    // 0x8073D220: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x8073D224: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8073D228: addiu       $t7, $t7, -0x1A08
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(745, 0X1428));
    // 0x8073D22C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8073D230: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8073D234: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8073D238: jal         0x8073D2F0
    // 0x8073D23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073D2F0(rdram, ctx);
        goto after_1;
    // 0x8073D23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8073D240: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8073D244: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8073D248: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(745, 0X1460) << 16);
    // 0x8073D24C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073D250: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    // 0x8073D254: lwc1        $f6, -0x19D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(745, 0X1460));
    // 0x8073D258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073D25C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8073D260: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8073D264: jal         0x8073E498
    // 0x8073D268: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    func_8073E498(rdram, ctx);
        goto after_2;
    // 0x8073D268: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8073D26C: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x8073D270: lui         $t9, 0x8074
    ctx->r25 = S32(RELOC_HI16(745, 0X430) << 16);
    // 0x8073D274: addiu       $t9, $t9, -0x2A00
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(745, 0X430));
    // 0x8073D278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8073D27C: jal         0x8073D1E0
    // 0x8073D280: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    func_8073D1E0(rdram, ctx);
        goto after_3;
    // 0x8073D280: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    after_3:
    // 0x8073D284: b           L_8073D298
    // 0x8073D288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073D298;
    // 0x8073D288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073D28C:
    // 0x8073D28C: jal         0x800445A4
    // 0x8073D290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x8073D290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8073D294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073D298:
    // 0x8073D298: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073D29C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8073D2A0: jr          $ra
    // 0x8073D2A4: nop

    return;
    // 0x8073D2A4: nop

;}
RECOMP_FUNC void func_806E6BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E6BC8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806E6BCC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806E6BD0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806E6BD4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806E6BD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806E6BDC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806E6BE0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806E6BE4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806E6BE8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806E6BEC: lui         $t1, 0x806E
    ctx->r9 = S32(RELOC_HI16(655, 0X1078) << 16);
    // 0x806E6BF0: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806E6BF4: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806E6BF8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806E6BFC: lw          $t1, 0x6D38($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(655, 0X1078));
    // 0x806E6C00: jr          $ra
    // 0x806E6C04: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806E6C04: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806E6C08: nop

    // 0x806E6C0C: nop

;}
RECOMP_FUNC void func_80736898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80736898: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8073689C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807368A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807368A4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807368A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807368AC: jal         0x80735DE4
    // 0x807368B0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80735DE4(rdram, ctx);
        goto after_0;
    // 0x807368B0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x807368B4: jal         0x80735E58
    // 0x807368B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80735E58(rdram, ctx);
        goto after_1;
    // 0x807368B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807368BC: jal         0x807360A0
    // 0x807368C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807360A0(rdram, ctx);
        goto after_2;
    // 0x807368C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807368C4: bnel        $v0, $zero, L_80736974
    if (ctx->r2 != 0) {
        // 0x807368C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80736974;
    }
    goto skip_0;
    // 0x807368C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x807368CC: jal         0x80736550
    // 0x807368D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80736550(rdram, ctx);
        goto after_3;
    // 0x807368D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807368D4: jal         0x8073677C
    // 0x807368D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073677C(rdram, ctx);
        goto after_4;
    // 0x807368D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807368DC: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x807368E0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x807368E4: lw          $t7, 0xA68($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XA68);
    // 0x807368E8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x807368EC: lw          $v0, 0x70($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X70);
    // 0x807368F0: beql        $v0, $zero, L_80736944
    if (ctx->r2 == 0) {
        // 0x807368F4: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80736944;
    }
    goto skip_1;
    // 0x807368F4: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x807368F8: lw          $t9, 0xD8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XD8);
    // 0x807368FC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80736900: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80736904: mfhi        $t0
    ctx->r8 = hi;
    // 0x80736908: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(736, 0X3B48) << 16);
    // 0x8073690C: bnel        $t0, $zero, L_80736944
    if (ctx->r8 != 0) {
        // 0x80736910: lw          $t2, 0x2C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X2C);
            goto L_80736944;
    }
    goto skip_2;
    // 0x80736910: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80736914: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80736918: lwc1        $f6, -0x6A58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(736, 0X3B48));
    // 0x8073691C: lwc1        $f12, 0x84($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80736920: lwc1        $f14, 0x88($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80736924: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80736928: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8073692C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80736930: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80736934: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80736938: jalr        $v0
    // 0x8073693C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_5;
    // 0x8073693C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x80736940: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
L_80736944:
    // 0x80736944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80736948: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8073694C: lw          $v0, 0xC($t2)
    ctx->r2 = MEM_W(ctx->r10, 0XC);
    // 0x80736950: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80736954: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80736958: bne         $at, $zero, L_80736968
    if (ctx->r1 != 0) {
        // 0x8073695C: slti        $at, $v0, 0x10
        ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
            goto L_80736968;
    }
    // 0x8073695C: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80736960: bnel        $at, $zero, L_80736974
    if (ctx->r1 != 0) {
        // 0x80736964: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80736974;
    }
    goto skip_3;
    // 0x80736964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
L_80736968:
    // 0x80736968: jal         0x80736D18
    // 0x8073696C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_80736D18(rdram, ctx);
        goto after_6;
    // 0x8073696C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x80736970: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80736974:
    // 0x80736974: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80736978: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8073697C: jr          $ra
    // 0x80736980: nop

    return;
    // 0x80736980: nop

;}
RECOMP_FUNC void func_8005C974(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C974: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005C978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005C97C: jal         0x8005C3B4
    // 0x8005C980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8005C3B4(rdram, ctx);
        goto after_0;
    // 0x8005C980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005C984: jal         0x8005C910
    // 0x8005C988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005C910(rdram, ctx);
        goto after_1;
    // 0x8005C988: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8005C98C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005C990: jal         0x8005D134
    // 0x8005C994: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    func_8005D134(rdram, ctx);
        goto after_2;
    // 0x8005C994: lbu         $a1, 0x18($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X18);
    after_2:
    // 0x8005C998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005C99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005C9A0: jr          $ra
    // 0x8005C9A4: nop

    return;
    // 0x8005C9A4: nop

;}
RECOMP_FUNC void func_8004DE6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004DE6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8004DE70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004DE74: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8004DE78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004DE7C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8004DE80: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8004DE84: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x8004DE88: lw          $t8, 0x40($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X40);
    // 0x8004DE8C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8004DE90: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004DE94: addu        $v1, $t8, $t0
    ctx->r3 = ADD32(ctx->r24, ctx->r8);
    // 0x8004DE98: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x8004DE9C: beql        $v0, $zero, L_8004DF4C
    if (ctx->r2 == 0) {
        // 0x8004DEA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DF4C;
    }
    goto skip_0;
    // 0x8004DEA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8004DEA4: beql        $v0, $at, L_8004DF4C
    if (ctx->r2 == ctx->r1) {
        // 0x8004DEA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DF4C;
    }
    goto skip_1;
    // 0x8004DEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8004DEAC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8004DEB0: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x8004DEB4: andi        $v0, $v0, 0xF8
    ctx->r2 = ctx->r2 & 0XF8;
    // 0x8004DEB8: beq         $v0, $at, L_8004DF48
    if (ctx->r2 == ctx->r1) {
        // 0x8004DEBC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8004DF48;
    }
    // 0x8004DEBC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8004DEC0: beq         $v0, $at, L_8004DF48
    if (ctx->r2 == ctx->r1) {
        // 0x8004DEC4: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8004DF48;
    }
    // 0x8004DEC4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8004DEC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8004DECC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8004DED0: jal         0x8004CF88
    // 0x8004DED4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004CF88(rdram, ctx);
        goto after_0;
    // 0x8004DED4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004DED8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8004DEDC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8004DEE0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8004DEE4: lbu         $t1, 0x14($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X14);
    // 0x8004DEE8: beql        $t1, $zero, L_8004DF4C
    if (ctx->r9 == 0) {
        // 0x8004DEEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8004DF4C;
    }
    goto skip_2;
    // 0x8004DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8004DEF0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8004DEF4: lhu         $v0, 0x4C($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X4C);
    // 0x8004DEF8: andi        $t3, $v0, 0x100
    ctx->r11 = ctx->r2 & 0X100;
    // 0x8004DEFC: bne         $t3, $zero, L_8004DF18
    if (ctx->r11 != 0) {
        // 0x8004DF00: nop
    
            goto L_8004DF18;
    }
    // 0x8004DF00: nop

    // 0x8004DF04: lbu         $t4, 0x18($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X18);
    // 0x8004DF08: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x8004DF0C: andi        $t5, $v0, 0x200
    ctx->r13 = ctx->r2 & 0X200;
    // 0x8004DF10: bne         $t4, $at, L_8004DF28
    if (ctx->r12 != ctx->r1) {
        // 0x8004DF14: nop
    
            goto L_8004DF28;
    }
    // 0x8004DF14: nop

L_8004DF18:
    // 0x8004DF18: jal         0x8004DA60
    // 0x8004DF1C: nop

    func_8004DA60(rdram, ctx);
        goto after_1;
    // 0x8004DF1C: nop

    after_1:
    // 0x8004DF20: b           L_8004DF3C
    // 0x8004DF24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
        goto L_8004DF3C;
    // 0x8004DF24: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_8004DF28:
    // 0x8004DF28: beql        $t5, $zero, L_8004DF40
    if (ctx->r13 == 0) {
        // 0x8004DF2C: lw          $t6, 0x8($a1)
        ctx->r14 = MEM_W(ctx->r5, 0X8);
            goto L_8004DF40;
    }
    goto skip_3;
    // 0x8004DF2C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    skip_3:
    // 0x8004DF30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004DF34: nop

    // 0x8004DF38: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
L_8004DF3C:
    // 0x8004DF3C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
L_8004DF40:
    // 0x8004DF40: ori         $t7, $t6, 0xF0
    ctx->r15 = ctx->r14 | 0XF0;
    // 0x8004DF44: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
L_8004DF48:
    // 0x8004DF48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8004DF4C:
    // 0x8004DF4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8004DF50: jr          $ra
    // 0x8004DF54: nop

    return;
    // 0x8004DF54: nop

;}
RECOMP_FUNC void func_806CE75C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CE75C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CE760: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806CE764: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x806CE768: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x806CE76C: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x806CE770: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x806CE774: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x806CE778: beq         $v0, $at, L_806CE794
    if (ctx->r2 == ctx->r1) {
        // 0x806CE77C: lui         $t7, 0x806D
        ctx->r15 = S32(RELOC_HI16(604, 0X2814) << 16);
            goto L_806CE794;
    }
    // 0x806CE77C: lui         $t7, 0x806D
    ctx->r15 = S32(RELOC_HI16(604, 0X2814) << 16);
    // 0x806CE780: addiu       $at, $zero, 0x4002
    ctx->r1 = ADD32(0, 0X4002);
    // 0x806CE784: beql        $v0, $at, L_806CE7D4
    if (ctx->r2 == ctx->r1) {
        // 0x806CE788: lbu         $t9, 0x18($a1)
        ctx->r25 = MEM_BU(ctx->r5, 0X18);
            goto L_806CE7D4;
    }
    goto skip_0;
    // 0x806CE788: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
    skip_0:
    // 0x806CE78C: b           L_806CE81C
    // 0x806CE790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806CE81C;
    // 0x806CE790: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806CE794:
    // 0x806CE794: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x806CE798: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x806CE79C: lw          $a2, 0x4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X4);
    // 0x806CE7A0: addiu       $t7, $t7, -0x20CC
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(604, 0X2814));
    // 0x806CE7A4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x806CE7A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x806CE7AC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x806CE7B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806CE7B4: lwc1        $f8, 0x0($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X0);
    // 0x806CE7B8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x806CE7BC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x806CE7C0: jal         0x806CE138
    // 0x806CE7C4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_806CE138(rdram, ctx);
        goto after_0;
    // 0x806CE7C4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x806CE7C8: b           L_806CE81C
    // 0x806CE7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_806CE81C;
    // 0x806CE7CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806CE7D0: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
L_806CE7D4:
    // 0x806CE7D4: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806CE7D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x806CE7DC: bne         $t9, $at, L_806CE818
    if (ctx->r25 != ctx->r1) {
        // 0x806CE7E0: lui         $t1, 0x806D
        ctx->r9 = S32(RELOC_HI16(604, 0X2840) << 16);
            goto L_806CE818;
    }
    // 0x806CE7E0: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(604, 0X2840) << 16);
    // 0x806CE7E4: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x806CE7E8: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x806CE7EC: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x806CE7F0: addiu       $t1, $t1, -0x20A0
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(604, 0X2840));
    // 0x806CE7F4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x806CE7F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x806CE7FC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x806CE800: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806CE804: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806CE808: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x806CE80C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x806CE810: jal         0x806CE138
    // 0x806CE814: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_806CE138(rdram, ctx);
        goto after_1;
    // 0x806CE814: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_1:
L_806CE818:
    // 0x806CE818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_806CE81C:
    // 0x806CE81C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806CE820: jr          $ra
    // 0x806CE824: nop

    return;
    // 0x806CE824: nop

;}
RECOMP_FUNC void func_80445BBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80445BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80445BC4: jal         0x800679B0
    // 0x80445BC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    func_800679B0(rdram, ctx);
        goto after_0;
    // 0x80445BC8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_0:
    // 0x80445BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80445BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80445BD4: jr          $ra
    // 0x80445BD8: nop

    return;
    // 0x80445BD8: nop

;}
RECOMP_FUNC void func_80523294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80523294: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80523298: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8052329C: lw          $t6, -0x72D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X72D8);
    // 0x805232A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805232A4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805232A8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805232AC: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x805232B0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805232B4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x805232B8: beq         $t7, $zero, L_805232D0
    if (ctx->r15 == 0) {
        // 0x805232BC: nop
    
            goto L_805232D0;
    }
    // 0x805232BC: nop

    // 0x805232C0: jal         0x800447C8
    // 0x805232C4: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x805232C4: nop

    after_0:
    // 0x805232C8: b           L_805233D4
    // 0x805232CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805233D4;
    // 0x805232CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805232D0:
    // 0x805232D0: jal         0x80045A34
    // 0x805232D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x805232D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x805232D8: bne         $v0, $zero, L_805232F0
    if (ctx->r2 != 0) {
        // 0x805232DC: sw          $v0, 0x1F4($s1)
        MEM_W(0X1F4, ctx->r17) = ctx->r2;
            goto L_805232F0;
    }
    // 0x805232DC: sw          $v0, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r2;
    // 0x805232E0: jal         0x800445A4
    // 0x805232E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x805232E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x805232E8: b           L_805233D4
    // 0x805232EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805233D4;
    // 0x805232EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805232F0:
    // 0x805232F0: lw          $t0, 0x16C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X16C);
    // 0x805232F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805232F8: lui         $t9, 0x8052
    ctx->r25 = S32(RELOC_HI16(321, 0X1E3C) << 16);
    // 0x805232FC: sb          $t8, 0x165($s1)
    MEM_B(0X165, ctx->r17) = ctx->r24;
    // 0x80523300: addiu       $t9, $t9, 0x40EC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(321, 0X1E3C));
    // 0x80523304: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80523308: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x8052330C: jal         0x80522A74
    // 0x80523310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80522A74(rdram, ctx);
        goto after_3;
    // 0x80523310: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80523314: lw          $s0, 0x1F4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X1F4);
    // 0x80523318: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8052331C: sw          $t1, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->r9;
    // 0x80523320: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    // 0x80523324: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80523328: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8052332C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x80523330: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80523334: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80523338: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8052333C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x80523340: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80523344: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80523348: lwc1        $f6, 0x40($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8052334C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80523350: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80523354: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80523358: addiu       $a0, $zero, 0x4146
    ctx->r4 = ADD32(0, 0X4146);
    // 0x8052335C: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80523360: jal         0x80047090
    // 0x80523364: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    func_80047090(rdram, ctx);
        goto after_4;
    // 0x80523364: swc1        $f16, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f16.u32l;
    after_4:
    // 0x80523368: lui         $at, 0x4146
    ctx->r1 = S32(0X4146 << 16);
    // 0x8052336C: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80523370: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80523374: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80523378: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x8052337C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80523380: jal         0x8004613C
    // 0x80523384: lui         $a2, 0x41D8
    ctx->r6 = S32(0X41D8 << 16);
    func_8004613C(rdram, ctx);
        goto after_5;
    // 0x80523384: lui         $a2, 0x41D8
    ctx->r6 = S32(0X41D8 << 16);
    after_5:
    // 0x80523388: bne         $v0, $zero, L_805233A0
    if (ctx->r2 != 0) {
        // 0x8052338C: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_805233A0;
    }
    // 0x8052338C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80523390: jal         0x800445A4
    // 0x80523394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80523394: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80523398: b           L_805233D4
    // 0x8052339C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805233D4;
    // 0x8052339C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805233A0:
    // 0x805233A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805233A4: jal         0x80047F9C
    // 0x805233A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x805233A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x805233AC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x805233B0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x805233B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x805233B8: sb          $t2, 0x17C($t3)
    MEM_B(0X17C, ctx->r11) = ctx->r10;
    // 0x805233BC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x805233C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805233C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805233C8: jal         0x80523830
    // 0x805233CC: sb          $t4, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r12;
    func_80523830(rdram, ctx);
        goto after_8;
    // 0x805233CC: sb          $t4, 0x18($t5)
    MEM_B(0X18, ctx->r13) = ctx->r12;
    after_8:
    // 0x805233D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805233D4:
    // 0x805233D4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805233D8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805233DC: jr          $ra
    // 0x805233E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805233E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80460908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8046090C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460910: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80460914: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x80460918: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x8046091C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80460920: lb          $t8, 0x2($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X2);
    // 0x80460924: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80460928: nop

    // 0x8046092C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80460930: jal         0x804608AC
    // 0x80460934: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    func_804608AC(rdram, ctx);
        goto after_0;
    // 0x80460934: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80460938: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8046093C: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80460940: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x80460944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80460948: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046094C: jr          $ra
    // 0x80460950: nop

    return;
    // 0x80460950: nop

;}
RECOMP_FUNC void func_80410EEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80410EEC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80410EF0: addu        $v0, $a0, $at
    ctx->r2 = ADD32(ctx->r4, ctx->r1);
    // 0x80410EF4: lw          $t6, 0x39D0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X39D0);
    // 0x80410EF8: addiu       $at, $a0, 0x7FFF
    ctx->r1 = ADD32(ctx->r4, 0X7FFF);
    // 0x80410EFC: sw          $t6, 0x39CD($at)
    MEM_W(0X39CD, ctx->r1) = ctx->r14;
    // 0x80410F00: lw          $t7, 0x39D0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X39D0);
    // 0x80410F04: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80410F08: sw          $t8, 0x39D1($at)
    MEM_W(0X39D1, ctx->r1) = ctx->r24;
    // 0x80410F0C: lw          $t9, 0x39D0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X39D0);
    // 0x80410F10: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80410F14: bne         $at, $zero, L_80410F20
    if (ctx->r1 != 0) {
        // 0x80410F18: addiu       $at, $a0, 0x7FFF
        ctx->r1 = ADD32(ctx->r4, 0X7FFF);
            goto L_80410F20;
    }
    // 0x80410F18: addiu       $at, $a0, 0x7FFF
    ctx->r1 = ADD32(ctx->r4, 0X7FFF);
    // 0x80410F1C: sw          $zero, 0x39D1($at)
    MEM_W(0X39D1, ctx->r1) = 0;
L_80410F20:
    // 0x80410F20: jr          $ra
    // 0x80410F24: nop

    return;
    // 0x80410F24: nop

;}
RECOMP_FUNC void func_80566CE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80566CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80566CE8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80566CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80566CF0: jal         0x8056682C
    // 0x80566CF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_8056682C(rdram, ctx);
        goto after_0;
    // 0x80566CF4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80566CF8: jal         0x80566674
    // 0x80566CFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80566674(rdram, ctx);
        goto after_1;
    // 0x80566CFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80566D00: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80566D04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80566D08: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80566D0C: bnel        $t8, $zero, L_80566D20
    if (ctx->r24 != 0) {
        // 0x80566D10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80566D20;
    }
    goto skip_0;
    // 0x80566D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80566D14: jal         0x805670F4
    // 0x80566D18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_805670F4(rdram, ctx);
        goto after_2;
    // 0x80566D18: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_2:
    // 0x80566D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80566D20:
    // 0x80566D20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80566D24: jr          $ra
    // 0x80566D28: nop

    return;
    // 0x80566D28: nop

;}
RECOMP_FUNC void func_80707624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80707624: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80707628: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8070762C: lhu         $v1, 0xC($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0XC);
    // 0x80707630: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80707634: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80707638: addiu       $at, $zero, 0x4608
    ctx->r1 = ADD32(0, 0X4608);
    // 0x8070763C: beq         $v1, $at, L_80707658
    if (ctx->r3 == ctx->r1) {
        // 0x80707640: lw          $a1, 0xD8($v0)
        ctx->r5 = MEM_W(ctx->r2, 0XD8);
            goto L_80707658;
    }
    // 0x80707640: lw          $a1, 0xD8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XD8);
    // 0x80707644: addiu       $at, $zero, 0x4609
    ctx->r1 = ADD32(0, 0X4609);
    // 0x80707648: beq         $v1, $at, L_807076A8
    if (ctx->r3 == ctx->r1) {
        // 0x8070764C: lui         $t0, 0x8070
        ctx->r8 = S32(RELOC_HI16(712, 0X750) << 16);
            goto L_807076A8;
    }
    // 0x8070764C: lui         $t0, 0x8070
    ctx->r8 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x80707650: b           L_807076F0
    // 0x80707654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807076F0;
    // 0x80707654: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80707658:
    // 0x80707658: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(712, 0X750) << 16);
    // 0x8070765C: addiu       $t6, $t6, 0x78F0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(712, 0X750));
    // 0x80707660: sw          $t6, 0xE90($v0)
    MEM_W(0XE90, ctx->r2) = ctx->r14;
    // 0x80707664: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80707668: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8070766C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80707670: beq         $t8, $zero, L_80707688
    if (ctx->r24 == 0) {
        // 0x80707674: nop
    
            goto L_80707688;
    }
    // 0x80707674: nop

    // 0x80707678: jal         0x80707788
    // 0x8070767C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80707788(rdram, ctx);
        goto after_0;
    // 0x8070767C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80707680: b           L_807076F0
    // 0x80707684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807076F0;
    // 0x80707684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80707688:
    // 0x80707688: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x8070768C: mfhi        $t9
    ctx->r25 = hi;
    // 0x80707690: bnel        $t9, $zero, L_807076F0
    if (ctx->r25 != 0) {
        // 0x80707694: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807076F0;
    }
    goto skip_0;
    // 0x80707694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80707698: jal         0x80707388
    // 0x8070769C: addiu       $a1, $zero, 0x4605
    ctx->r5 = ADD32(0, 0X4605);
    func_80707388(rdram, ctx);
        goto after_1;
    // 0x8070769C: addiu       $a1, $zero, 0x4605
    ctx->r5 = ADD32(0, 0X4605);
    after_1:
    // 0x807076A0: b           L_807076F0
    // 0x807076A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807076F0;
    // 0x807076A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807076A8:
    // 0x807076A8: addiu       $t0, $t0, 0x78F0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(712, 0X750));
    // 0x807076AC: sw          $t0, 0xE90($v0)
    MEM_W(0XE90, ctx->r2) = ctx->r8;
    // 0x807076B0: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x807076B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807076B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x807076BC: beq         $t2, $zero, L_807076D4
    if (ctx->r10 == 0) {
        // 0x807076C0: nop
    
            goto L_807076D4;
    }
    // 0x807076C0: nop

    // 0x807076C4: jal         0x80707788
    // 0x807076C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80707788(rdram, ctx);
        goto after_2;
    // 0x807076C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x807076CC: b           L_807076F0
    // 0x807076D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_807076F0;
    // 0x807076D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807076D4:
    // 0x807076D4: divu        $zero, $a1, $at
    lo = S32(U32(ctx->r5) / U32(ctx->r1)); hi = S32(U32(ctx->r5) % U32(ctx->r1));
    // 0x807076D8: mfhi        $t3
    ctx->r11 = hi;
    // 0x807076DC: bnel        $t3, $zero, L_807076F0
    if (ctx->r11 != 0) {
        // 0x807076E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807076F0;
    }
    goto skip_1;
    // 0x807076E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x807076E4: jal         0x80707388
    // 0x807076E8: addiu       $a1, $zero, 0x4606
    ctx->r5 = ADD32(0, 0X4606);
    func_80707388(rdram, ctx);
        goto after_3;
    // 0x807076E8: addiu       $a1, $zero, 0x4606
    ctx->r5 = ADD32(0, 0X4606);
    after_3:
    // 0x807076EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807076F0:
    // 0x807076F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807076F4: jr          $ra
    // 0x807076F8: nop

    return;
    // 0x807076F8: nop

;}
RECOMP_FUNC void func_80423C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423C54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80423C58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80423C5C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80423C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80423C64: jal         0x80051194
    // 0x80423C68: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80423C68: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x80423C6C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80423C70: jal         0x804234C0
    // 0x80423C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804234C0(rdram, ctx);
        goto after_1;
    // 0x80423C74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80423C78: bne         $v0, $zero, L_80423C90
    if (ctx->r2 != 0) {
        // 0x80423C7C: nop
    
            goto L_80423C90;
    }
    // 0x80423C7C: nop

    // 0x80423C80: jal         0x800445A4
    // 0x80423C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x80423C84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80423C88: b           L_80423DA8
    // 0x80423C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80423DA8;
    // 0x80423C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80423C90:
    // 0x80423C90: jal         0x800653D8
    // 0x80423C94: nop

    func_800653D8(rdram, ctx);
        goto after_3;
    // 0x80423C94: nop

    after_3:
    // 0x80423C98: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80423C9C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80423CA0: mfhi        $t6
    ctx->r14 = hi;
    // 0x80423CA4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80423CA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80423CAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80423CB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80423CB4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80423CB8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80423CBC: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423CC0: lui         $t1, 0x8005
    ctx->r9 = S32(0X8005 << 16);
    // 0x80423CC4: addiu       $t1, $t1, -0x7C48
    ctx->r9 = ADD32(ctx->r9, -0X7C48);
    // 0x80423CC8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80423CCC: lui         $t2, 0x8042
    ctx->r10 = S32(RELOC_HI16(35, 0X31C8) << 16);
    // 0x80423CD0: addiu       $t2, $t2, 0x5BC8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(35, 0X31C8));
    // 0x80423CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80423CD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80423CDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80423CE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80423CE4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80423CE8: swc1        $f18, 0xEC($t7)
    MEM_W(0XEC, ctx->r15) = ctx->f18.u32l;
    // 0x80423CEC: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423CF0: sw          $zero, 0xF4($t8)
    MEM_W(0XF4, ctx->r24) = 0;
    // 0x80423CF4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423CF8: lw          $t9, 0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF4);
    // 0x80423CFC: sw          $t9, 0xF8($v1)
    MEM_W(0XF8, ctx->r3) = ctx->r25;
    // 0x80423D00: lw          $t0, 0x1F4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1F4);
    // 0x80423D04: sw          $zero, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = 0;
    // 0x80423D08: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x80423D0C: sw          $t1, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r9;
    // 0x80423D10: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80423D14: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x80423D18: jal         0x80423DB8
    // 0x80423D1C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_80423DB8(rdram, ctx);
        goto after_4;
    // 0x80423D1C: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_4:
    // 0x80423D20: jal         0x80047090
    // 0x80423D24: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    func_80047090(rdram, ctx);
        goto after_5;
    // 0x80423D24: addiu       $a0, $zero, 0x4066
    ctx->r4 = ADD32(0, 0X4066);
    after_5:
    // 0x80423D28: addiu       $a0, $zero, 0x3FF
    ctx->r4 = ADD32(0, 0X3FF);
    // 0x80423D2C: bne         $a0, $v0, L_80423D44
    if (ctx->r4 != ctx->r2) {
        // 0x80423D30: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80423D44;
    }
    // 0x80423D30: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80423D34: jal         0x800445A4
    // 0x80423D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x80423D38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80423D3C: b           L_80423DA8
    // 0x80423D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80423DA8;
    // 0x80423D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80423D44:
    // 0x80423D44: andi        $t4, $v0, 0xFFFF
    ctx->r12 = ctx->r2 & 0XFFFF;
    // 0x80423D48: beql        $a0, $t4, L_80423DA8
    if (ctx->r4 == ctx->r12) {
        // 0x80423D4C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80423DA8;
    }
    goto skip_0;
    // 0x80423D4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80423D50: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80423D54: lui         $at, 0x4066
    ctx->r1 = S32(0X4066 << 16);
    // 0x80423D58: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80423D5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80423D60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80423D64: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80423D68: jal         0x8004613C
    // 0x80423D6C: nop

    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x80423D6C: nop

    after_7:
    // 0x80423D70: beq         $v0, $zero, L_80423D9C
    if (ctx->r2 == 0) {
        // 0x80423D74: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80423D9C;
    }
    // 0x80423D74: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80423D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80423D7C: jal         0x80047F9C
    // 0x80423D80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x80423D80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_8:
    // 0x80423D84: jal         0x804255F0
    // 0x80423D88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_804255F0(rdram, ctx);
        goto after_9;
    // 0x80423D88: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_9:
    // 0x80423D8C: jal         0x804235A8
    // 0x80423D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804235A8(rdram, ctx);
        goto after_10;
    // 0x80423D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80423D94: b           L_80423DA8
    // 0x80423D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80423DA8;
    // 0x80423D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80423D9C:
    // 0x80423D9C: jal         0x800445A4
    // 0x80423DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_11;
    // 0x80423DA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80423DA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80423DA8:
    // 0x80423DA8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80423DAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80423DB0: jr          $ra
    // 0x80423DB4: nop

    return;
    // 0x80423DB4: nop

;}
RECOMP_FUNC void func_80039CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039CD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80039CD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80039CD8: jal         0x8004700C
    // 0x80039CDC: nop

    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80039CDC: nop

    after_0:
    // 0x80039CE0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80039CE4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80039CE8: beq         $v0, $zero, L_80039D5C
    if (ctx->r2 == 0) {
        // 0x80039CEC: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_80039D5C;
    }
    // 0x80039CEC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80039CF0: lh          $a0, 0x184($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X184);
    // 0x80039CF4: addiu       $a1, $v0, 0x188
    ctx->r5 = ADD32(ctx->r2, 0X188);
    // 0x80039CF8: addiu       $t0, $zero, 0x401D
    ctx->r8 = ADD32(0, 0X401D);
    // 0x80039CFC: beq         $a0, $zero, L_80039D5C
    if (ctx->r4 == 0) {
        // 0x80039D00: addiu       $a3, $zero, 0x401C
        ctx->r7 = ADD32(0, 0X401C);
            goto L_80039D5C;
    }
    // 0x80039D00: addiu       $a3, $zero, 0x401C
    ctx->r7 = ADD32(0, 0X401C);
    // 0x80039D04: addiu       $a2, $zero, 0x4004
    ctx->r6 = ADD32(0, 0X4004);
L_80039D08:
    // 0x80039D08: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80039D0C: beq         $v1, $zero, L_80039D54
    if (ctx->r3 == 0) {
        // 0x80039D10: nop
    
            goto L_80039D54;
    }
    // 0x80039D10: nop

    // 0x80039D14: lhu         $v0, 0xC($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0XC);
    // 0x80039D18: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80039D1C: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80039D20: beq         $v0, $a2, L_80039D40
    if (ctx->r2 == ctx->r6) {
        // 0x80039D24: sra         $a0, $a0, 16
        ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
            goto L_80039D40;
    }
    // 0x80039D24: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80039D28: beq         $v0, $a3, L_80039D48
    if (ctx->r2 == ctx->r7) {
        // 0x80039D2C: nop
    
            goto L_80039D48;
    }
    // 0x80039D2C: nop

    // 0x80039D30: beql        $v0, $t0, L_80039D54
    if (ctx->r2 == ctx->r8) {
        // 0x80039D34: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80039D54;
    }
    goto skip_0;
    // 0x80039D34: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    skip_0:
    // 0x80039D38: b           L_80039D54
    // 0x80039D3C: nop

        goto L_80039D54;
    // 0x80039D3C: nop

L_80039D40:
    // 0x80039D40: b           L_80039D54
    // 0x80039D44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80039D54;
    // 0x80039D44: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80039D48:
    // 0x80039D48: b           L_80039D54
    // 0x80039D4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80039D54;
    // 0x80039D4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80039D50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80039D54:
    // 0x80039D54: bne         $a0, $zero, L_80039D08
    if (ctx->r4 != 0) {
        // 0x80039D58: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80039D08;
    }
    // 0x80039D58: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80039D5C:
    // 0x80039D5C: beq         $t1, $zero, L_80039D7C
    if (ctx->r9 == 0) {
        // 0x80039D60: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_80039D7C;
    }
    // 0x80039D60: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039D64: lw          $a0, 0x426C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X426C);
    // 0x80039D68: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80039D6C: jal         0x80046730
    // 0x80039D70: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_80046730(rdram, ctx);
        goto after_1;
    // 0x80039D70: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_1:
    // 0x80039D74: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80039D78: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80039D7C:
    // 0x80039D7C: beq         $t2, $zero, L_80039D94
    if (ctx->r10 == 0) {
        // 0x80039D80: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_80039D94;
    }
    // 0x80039D80: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039D84: lw          $a0, 0x4274($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4274);
    // 0x80039D88: jal         0x80046730
    // 0x80039D8C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    func_80046730(rdram, ctx);
        goto after_2;
    // 0x80039D8C: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_2:
    // 0x80039D90: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
L_80039D94:
    // 0x80039D94: beq         $t3, $zero, L_80039DA4
    if (ctx->r11 == 0) {
        // 0x80039D98: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_80039DA4;
    }
    // 0x80039D98: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80039D9C: jal         0x80046730
    // 0x80039DA0: lw          $a0, 0x4278($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4278);
    func_80046730(rdram, ctx);
        goto after_3;
    // 0x80039DA0: lw          $a0, 0x4278($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4278);
    after_3:
L_80039DA4:
    // 0x80039DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80039DAC: jr          $ra
    // 0x80039DB0: nop

    return;
    // 0x80039DB0: nop

;}
RECOMP_FUNC void func_806F6BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F6BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F6BE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x806F6BEC: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x806F6BF0: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x806F6BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F6BF8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x806F6BFC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F6C00: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x806F6C04: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x806F6C08: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x806F6C0C: lui         $t2, 0x806F
    ctx->r10 = S32(RELOC_HI16(688, 0X630) << 16);
    // 0x806F6C10: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806F6C14: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x806F6C18: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x806F6C1C: lw          $t2, 0x6CD0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(688, 0X630));
    // 0x806F6C20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x806F6C24: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806F6C28: jal         0x806F66C8
    // 0x806F6C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806F66C8(rdram, ctx);
        goto after_0;
    // 0x806F6C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F6C30: jal         0x806F6714
    // 0x806F6C34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806F6714(rdram, ctx);
        goto after_1;
    // 0x806F6C34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x806F6C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6C3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F6C40: jr          $ra
    // 0x806F6C44: nop

    return;
    // 0x806F6C44: nop

    // 0x806F6C48: nop

    // 0x806F6C4C: nop

;}
RECOMP_FUNC void func_80799F74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80799F74: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80799F78: lw          $t9, -0x72A4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72A4);
    // 0x80799F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80799F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80799F84: jalr        $t9
    // 0x80799F88: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80799F88: addiu       $a0, $a0, 0x84
    ctx->r4 = ADD32(ctx->r4, 0X84);
    after_0:
    // 0x80799F8C: jal         0x80067E68
    // 0x80799F90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80067E68(rdram, ctx);
        goto after_1;
    // 0x80799F90: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80799F94: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x80799F98: jal         0x80067818
    // 0x80799F9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80799F9C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80799FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80799FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80799FA8: jr          $ra
    // 0x80799FAC: nop

    return;
    // 0x80799FAC: nop

;}
RECOMP_FUNC void func_8002E290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E290: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E294: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E298: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002E29C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002E2A0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8002E2A4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8002E2A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E2AC: bne         $t6, $at, L_8002E340
    if (ctx->r14 != ctx->r1) {
        // 0x8002E2B0: lw          $s1, 0x1F4($a0)
        ctx->r17 = MEM_W(ctx->r4, 0X1F4);
            goto L_8002E340;
    }
    // 0x8002E2B0: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E2B4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8002E2B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E2BC: lwc1        $f4, 0xC8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8002E2C0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8002E2C4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8002E2C8: nop

    // 0x8002E2CC: bc1fl       L_8002E308
    if (!c1cs) {
        // 0x8002E2D0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8002E308;
    }
    goto skip_0;
    // 0x8002E2D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x8002E2D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002E2D8: jal         0x8001D770
    // 0x8002E2DC: swc1        $f8, 0x12E4($s1)
    MEM_W(0X12E4, ctx->r17) = ctx->f8.u32l;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x8002E2DC: swc1        $f8, 0x12E4($s1)
    MEM_W(0X12E4, ctx->r17) = ctx->f8.u32l;
    after_0:
    // 0x8002E2E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E2E4: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002E2E8: jal         0x80067BF8
    // 0x8002E2EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x8002E2EC: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8002E2F0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8002E2F4: jal         0x80067818
    // 0x8002E2F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8002E2F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8002E2FC: b           L_8002E3AC
    // 0x8002E300: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
        goto L_8002E3AC;
    // 0x8002E300: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
    // 0x8002E304: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8002E308:
    // 0x8002E308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E30C: jal         0x8002E110
    // 0x8002E310: swc1        $f10, 0x12E4($s1)
    MEM_W(0X12E4, ctx->r17) = ctx->f10.u32l;
    func_8002E110(rdram, ctx);
        goto after_3;
    // 0x8002E310: swc1        $f10, 0x12E4($s1)
    MEM_W(0X12E4, ctx->r17) = ctx->f10.u32l;
    after_3:
    // 0x8002E314: jal         0x8001D770
    // 0x8002E318: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8002E318: nop

    after_4:
    // 0x8002E31C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E320: lbu         $a1, 0xDE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XDE);
    // 0x8002E324: jal         0x80067ED8
    // 0x8002E328: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_5;
    // 0x8002E328: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_5:
    // 0x8002E32C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002E330: jal         0x80067818
    // 0x8002E334: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002E334: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002E338: b           L_8002E3AC
    // 0x8002E33C: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
        goto L_8002E3AC;
    // 0x8002E33C: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
L_8002E340:
    // 0x8002E340: jal         0x8002E110
    // 0x8002E344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E110(rdram, ctx);
        goto after_7;
    // 0x8002E344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8002E348: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x8002E34C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8002E350: bne         $t7, $at, L_8002E384
    if (ctx->r15 != ctx->r1) {
        // 0x8002E354: nop
    
            goto L_8002E384;
    }
    // 0x8002E354: nop

    // 0x8002E358: jal         0x8001D770
    // 0x8002E35C: nop

    func_8001D770(rdram, ctx);
        goto after_8;
    // 0x8002E35C: nop

    after_8:
    // 0x8002E360: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E364: lbu         $a1, 0xDE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XDE);
    // 0x8002E368: jal         0x80067ED8
    // 0x8002E36C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_9;
    // 0x8002E36C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_9:
    // 0x8002E370: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x8002E374: jal         0x80067818
    // 0x8002E378: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_10;
    // 0x8002E378: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8002E37C: b           L_8002E3AC
    // 0x8002E380: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
        goto L_8002E3AC;
    // 0x8002E380: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
L_8002E384:
    // 0x8002E384: jal         0x8001D770
    // 0x8002E388: nop

    func_8001D770(rdram, ctx);
        goto after_11;
    // 0x8002E388: nop

    after_11:
    // 0x8002E38C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E390: lbu         $a1, 0xDE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XDE);
    // 0x8002E394: jal         0x80067ED8
    // 0x8002E398: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_12;
    // 0x8002E398: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_12:
    // 0x8002E39C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002E3A0: jal         0x80067818
    // 0x8002E3A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_13;
    // 0x8002E3A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8002E3A8: lw          $t8, 0x174($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X174);
L_8002E3AC:
    // 0x8002E3AC: lw          $v0, 0x4($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X4);
    // 0x8002E3B0: beq         $v0, $zero, L_8002E3E8
    if (ctx->r2 == 0) {
        // 0x8002E3B4: nop
    
            goto L_8002E3E8;
    }
    // 0x8002E3B4: nop

    // 0x8002E3B8: lw          $t9, 0x174($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X174);
    // 0x8002E3BC: beq         $t9, $zero, L_8002E3E8
    if (ctx->r25 == 0) {
        // 0x8002E3C0: nop
    
            goto L_8002E3E8;
    }
    // 0x8002E3C0: nop

    // 0x8002E3C4: lhu         $t0, 0xE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0XE);
    // 0x8002E3C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002E3CC: srl         $t1, $t0, 10
    ctx->r9 = S32(U32(ctx->r8) >> 10);
    // 0x8002E3D0: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8002E3D4: bne         $t2, $at, L_8002E3E8
    if (ctx->r10 != ctx->r1) {
        // 0x8002E3D8: nop
    
            goto L_8002E3E8;
    }
    // 0x8002E3D8: nop

    // 0x8002E3DC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8002E3E0: b           L_8002E3F8
    // 0x8002E3E4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
        goto L_8002E3F8;
    // 0x8002E3E4: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
L_8002E3E8:
    // 0x8002E3E8: jal         0x80041338
    // 0x8002E3EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80041338(rdram, ctx);
        goto after_14;
    // 0x8002E3EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8002E3F0: lwc1        $f18, 0x70($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8002E3F4: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
L_8002E3F8:
    // 0x8002E3F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002E3FC: jal         0x8002E274
    // 0x8002E400: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002E274(rdram, ctx);
        goto after_15;
    // 0x8002E400: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
    // 0x8002E404: lwc1        $f0, 0x120($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8002E408: lwc1        $f4, 0x68($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8002E40C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002E410: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x8002E414: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002E418: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002E41C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002E420: jr          $ra
    // 0x8002E424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002E424: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80067A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067A38: jal         0x80018EE8
    // 0x80067A3C: nop

    func_80018EE8(rdram, ctx);
        goto after_0;
    // 0x80067A3C: nop

    after_0:
    // 0x80067A40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067A44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80067A48: jr          $ra
    // 0x80067A4C: nop

    return;
    // 0x80067A4C: nop

;}
RECOMP_FUNC void func_80000FC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000FC0: jr          $ra
    // 0x80000FC4: nop

    return;
    // 0x80000FC4: nop

    // 0x80000FC8: jr          $ra
    // 0x80000FCC: nop

    return;
    // 0x80000FCC: nop

    // 0x80000FD0: jr          $ra
    // 0x80000FD4: nop

    return;
    // 0x80000FD4: nop

    // 0x80000FD8: jr          $ra
    // 0x80000FDC: nop

    return;
    // 0x80000FDC: nop

    // 0x80000FE0: jr          $ra
    // 0x80000FE4: nop

    return;
    // 0x80000FE4: nop

    // 0x80000FE8: jr          $ra
    // 0x80000FEC: nop

    return;
    // 0x80000FEC: nop

    // 0x80000FF0: jr          $ra
    // 0x80000FF4: nop

    return;
    // 0x80000FF4: nop

;}
RECOMP_FUNC void func_807A1380(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A1380: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A1384: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A1388: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A138C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A1390: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x807A1394: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807A1398: jal         0x807A0FFC
    // 0x807A139C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_807A0FFC(rdram, ctx);
        goto after_0;
    // 0x807A139C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x807A13A0: lw          $v0, 0x1E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1E0);
    // 0x807A13A4: blez        $v0, L_807A13B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x807A13A8: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807A13B0;
    }
    // 0x807A13A8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807A13AC: sw          $t6, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r14;
L_807A13B0:
    // 0x807A13B0: jal         0x807A10CC
    // 0x807A13B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A10CC(rdram, ctx);
        goto after_1;
    // 0x807A13B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807A13B8: beq         $v0, $zero, L_807A13DC
    if (ctx->r2 == 0) {
        // 0x807A13BC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_807A13DC;
    }
    // 0x807A13BC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807A13C0: sw          $t7, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r15;
    // 0x807A13C4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x807A13C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A13CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A13D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807A13D4: jal         0x807A1AE4
    // 0x807A13D8: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_807A1AE4(rdram, ctx);
        goto after_2;
    // 0x807A13D8: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_2:
L_807A13DC:
    // 0x807A13DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A13E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A13E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A13E8: jr          $ra
    // 0x807A13EC: nop

    return;
    // 0x807A13EC: nop

;}
RECOMP_FUNC void func_804CB704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CB704: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804CB708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CB70C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CB710: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x804CB714: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x804CB718: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CB71C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x804CB720: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804CB724: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CB728: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x804CB72C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CB730: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804CB734: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804CB738: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x804CB73C: lw          $a3, 0x188($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X188);
    // 0x804CB740: bc1f        L_804CB74C
    if (!c1cs) {
        // 0x804CB744: lw          $v0, 0x174($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X174);
            goto L_804CB74C;
    }
    // 0x804CB744: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x804CB748: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
L_804CB74C:
    // 0x804CB74C: beq         $a3, $zero, L_804CB780
    if (ctx->r7 == 0) {
        // 0x804CB750: lwc1        $f6, 0x34($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
            goto L_804CB780;
    }
    // 0x804CB750: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x804CB754: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804CB758: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804CB75C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x804CB760: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804CB764: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x804CB768: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x804CB76C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x804CB770: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x804CB774: jal         0x804CB704
    // 0x804CB778: nop

    func_804CB704(rdram, ctx);
        goto after_0;
    // 0x804CB778: nop

    after_0:
    // 0x804CB77C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_804CB780:
    // 0x804CB780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CB784: jal         0x8005FD1C
    // 0x804CB788: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_8005FD1C(rdram, ctx);
        goto after_1;
    // 0x804CB788: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x804CB78C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x804CB790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CB794: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x804CB798: sh          $zero, 0x10($t0)
    MEM_H(0X10, ctx->r8) = 0;
    // 0x804CB79C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x804CB7A0: jal         0x8004816C
    // 0x804CB7A4: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    func_8004816C(rdram, ctx);
        goto after_2;
    // 0x804CB7A4: sh          $zero, 0x12($t1)
    MEM_H(0X12, ctx->r9) = 0;
    after_2:
    // 0x804CB7A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CB7AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CB7B0: jal         0x804CBA88
    // 0x804CB7B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804CBA88(rdram, ctx);
        goto after_3;
    // 0x804CB7B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x804CB7B8: jal         0x80066E88
    // 0x804CB7BC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    func_80066E88(rdram, ctx);
        goto after_4;
    // 0x804CB7BC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x804CB7C0: jal         0x800653D8
    // 0x804CB7C4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_800653D8(rdram, ctx);
        goto after_5;
    // 0x804CB7C4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x804CB7C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804CB7CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804CB7D0: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804CB7D4: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x804CB7D8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x804CB7DC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804CB7E0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X137C) << 16);
    // 0x804CB7E4: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x804CB7E8: lwc1        $f6, -0x4144($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X137C));
    // 0x804CB7EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804CB7F0: lui         $at, 0x804D
    ctx->r1 = S32(RELOC_HI16(231, 0X13F8) << 16);
    // 0x804CB7F4: lui         $t4, 0x8005
    ctx->r12 = S32(0X8005 << 16);
    // 0x804CB7F8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x804CB7FC: swc1        $f10, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f10.u32l;
    // 0x804CB800: addiu       $t4, $t4, -0x7C48
    ctx->r12 = ADD32(ctx->r12, -0X7C48);
    // 0x804CB804: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x804CB808: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x804CB80C: lwc1        $f16, -0x40C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(231, 0X13F8));
    // 0x804CB810: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x804CB814: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CB818: sw          $t4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r12;
    // 0x804CB81C: sb          $t5, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r13;
    // 0x804CB820: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x804CB824: swc1        $f18, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f18.u32l;
    // 0x804CB828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804CB82C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CB830: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804CB834: jr          $ra
    // 0x804CB838: nop

    return;
    // 0x804CB838: nop

;}
RECOMP_FUNC void func_80038FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038FEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038FF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038FF4: lw          $v0, 0x14C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14C);
    // 0x80038FF8: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x80038FFC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80039000: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80039004: bne         $at, $zero, L_80039010
    if (ctx->r1 != 0) {
        // 0x80039008: lw          $v1, 0x88($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X88);
            goto L_80039010;
    }
    // 0x80039008: lw          $v1, 0x88($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X88);
    // 0x8003900C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80039010:
    // 0x80039010: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x80039014: sw          $v0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r2;
    // 0x80039018: jal         0x8004590C
    // 0x8003901C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    func_8004590C(rdram, ctx);
        goto after_0;
    // 0x8003901C: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x80039020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80039024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80039028: jr          $ra
    // 0x8003902C: nop

    return;
    // 0x8003902C: nop

;}
RECOMP_FUNC void func_8077DF1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8077DF1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8077DF20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8077DF24: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8077DF28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8077DF2C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8077DF30: lui         $a0, 0x8078
    ctx->r4 = S32(RELOC_HI16(778, 0X220) << 16);
    // 0x8077DF34: lui         $a1, 0x401B
    ctx->r5 = S32(0X401B << 16);
    // 0x8077DF38: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8077DF3C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x8077DF40: addiu       $a0, $a0, -0x2000
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(778, 0X220));
    // 0x8077DF44: jal         0x80046804
    // 0x8077DF48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x8077DF48: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8077DF4C: beq         $v0, $zero, L_8077DF5C
    if (ctx->r2 == 0) {
        // 0x8077DF50: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8077DF5C;
    }
    // 0x8077DF50: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8077DF54: jal         0x80044194
    // 0x8077DF58: nop

    func_80044194(rdram, ctx);
        goto after_1;
    // 0x8077DF58: nop

    after_1:
L_8077DF5C:
    // 0x8077DF5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8077DF60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8077DF64: jr          $ra
    // 0x8077DF68: nop

    return;
    // 0x8077DF68: nop

    // 0x8077DF6C: nop

;}
RECOMP_FUNC void func_80471660(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80471660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80471664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80471668: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8047166C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80471670: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x80471674: lh          $a1, 0x30($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X30);
    // 0x80471678: beql        $a1, $at, L_80471698
    if (ctx->r5 == ctx->r1) {
        // 0x8047167C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80471698;
    }
    goto skip_0;
    // 0x8047167C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80471680: jal         0x80067878
    // 0x80471684: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80471684: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80471688: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8047168C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80471690: sh          $t6, 0x30($v0)
    MEM_H(0X30, ctx->r2) = ctx->r14;
    // 0x80471694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80471698:
    // 0x80471698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8047169C: jr          $ra
    // 0x804716A0: nop

    return;
    // 0x804716A0: nop

;}
RECOMP_FUNC void func_80077270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077270: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80077274: beq         $a1, $zero, L_8007732C
    if (ctx->r5 == 0) {
        // 0x80077278: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_8007732C;
    }
    // 0x80077278: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007727C: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80077280: addiu       $t2, $t2, -0x7A18
    ctx->r10 = ADD32(ctx->r10, -0X7A18);
    // 0x80077284: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80077288: lui         $t3, 0x700
    ctx->r11 = S32(0X700 << 16);
    // 0x8007728C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077290: beq         $a1, $t6, L_8007732C
    if (ctx->r5 == ctx->r14) {
        // 0x80077294: lui         $t7, 0xFD10
        ctx->r15 = S32(0XFD10 << 16);
            goto L_8007732C;
    }
    // 0x80077294: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x80077298: sw          $a1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r5;
    // 0x8007729C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800772A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800772A4: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800772A8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800772AC: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x800772B0: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800772B4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800772B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800772BC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800772C0: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x800772C4: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x800772C8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800772CC: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800772D0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800772D4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x800772D8: lui         $t4, 0xE600
    ctx->r12 = S32(0XE600 << 16);
    // 0x800772DC: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800772E0: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800772E4: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800772E8: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800772EC: lui         $t5, 0xF000
    ctx->r13 = S32(0XF000 << 16);
    // 0x800772F0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800772F4: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x800772F8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800772FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80077300: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80077304: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80077308: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8007730C: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x80077310: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x80077314: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80077318: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8007731C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80077320: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80077324: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80077328: sw          $zero, -0x7A1C($at)
    MEM_W(-0X7A1C, ctx->r1) = 0;
L_8007732C:
    // 0x8007732C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80077330: jr          $ra
    // 0x80077334: nop

    return;
    // 0x80077334: nop

;}
RECOMP_FUNC void func_80669E38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80669E38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80669E3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80669E40: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80669E44: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80669E48: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80669E4C: beq         $a1, $at, L_80669E70
    if (ctx->r5 == ctx->r1) {
        // 0x80669E50: addiu       $a0, $zero, 0x12
        ctx->r4 = ADD32(0, 0X12);
            goto L_80669E70;
    }
    // 0x80669E50: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669E54: jal         0x80067930
    // 0x80669E58: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x80669E58: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80669E5C: beq         $v0, $zero, L_80669E70
    if (ctx->r2 == 0) {
        // 0x80669E60: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80669E70;
    }
    // 0x80669E60: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80669E64: addiu       $a0, $zero, 0x12
    ctx->r4 = ADD32(0, 0X12);
    // 0x80669E68: jal         0x80067878
    // 0x80669E6C: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_1;
    // 0x80669E6C: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    after_1:
L_80669E70:
    // 0x80669E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80669E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80669E78: jr          $ra
    // 0x80669E7C: nop

    return;
    // 0x80669E7C: nop

;}
RECOMP_FUNC void func_80450220(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450220: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80450224: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450228: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045022C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80450230: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450234: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450238: addu        $v1, $s0, $at
    ctx->r3 = ADD32(ctx->r16, ctx->r1);
    // 0x8045023C: lw          $a0, 0x6A28($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X6A28);
    // 0x80450240: jal         0x8044DED0
    // 0x80450244: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_8044DED0(rdram, ctx);
        goto after_0;
    // 0x80450244: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x80450248: bltz        $v0, L_804502CC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8045024C: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_804502CC;
    }
    // 0x8045024C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80450250: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80450254: beq         $at, $zero, L_804502CC
    if (ctx->r1 == 0) {
        // 0x80450258: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_804502CC;
    }
    // 0x80450258: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8045025C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450260: lwc1        $f4, 0x6F00($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6F00);
    // 0x80450264: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450268: ori         $at, $at, 0x6F00
    ctx->r1 = ctx->r1 | 0X6F00;
    // 0x8045026C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80450270: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80450274: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450278: bc1fl       L_804502B8
    if (!c1cs) {
        // 0x8045027C: lwc1        $f8, 0x0($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
            goto L_804502B8;
    }
    goto skip_0;
    // 0x8045027C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x80450280: jal         0x80450000
    // 0x80450284: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_80450000(rdram, ctx);
        goto after_1;
    // 0x80450284: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80450288: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045028C: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80450290: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80450294: sw          $t7, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = ctx->r15;
    // 0x80450298: jal         0x804500B8
    // 0x8045029C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_804500B8(rdram, ctx);
        goto after_2;
    // 0x8045029C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x804502A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804502A4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804502A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804502AC: b           L_804502E4
    // 0x804502B0: sw          $t8, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = ctx->r24;
        goto L_804502E4;
    // 0x804502B0: sw          $t8, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = ctx->r24;
    // 0x804502B4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
L_804502B8:
    // 0x804502B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804502BC: nop

    // 0x804502C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x804502C4: b           L_804502E4
    // 0x804502C8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
        goto L_804502E4;
    // 0x804502C8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_804502CC:
    // 0x804502CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804502D0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804502D4: sw          $zero, 0x6EF4($at)
    MEM_W(0X6EF4, ctx->r1) = 0;
    // 0x804502D8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804502DC: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804502E0: sw          $zero, 0x6EFC($at)
    MEM_W(0X6EFC, ctx->r1) = 0;
L_804502E4:
    // 0x804502E4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x804502E8: lbu         $t9, -0x7203($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X7203);
    // 0x804502EC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804502F0: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x804502F4: sw          $t9, 0x6EF8($at)
    MEM_W(0X6EF8, ctx->r1) = ctx->r25;
    // 0x804502F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804502FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80450300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80450304: jr          $ra
    // 0x80450308: nop

    return;
    // 0x80450308: nop

;}
RECOMP_FUNC void func_804653B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804653B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804653BC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804653C0: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804653C4: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x804653C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804653CC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x804653D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804653D4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x804653D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804653DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x804653E0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804653E4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x804653E8: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(125, 0X1D64) << 16);
    // 0x804653EC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804653F0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x804653F4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804653F8: lw          $t2, 0x6334($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(125, 0X1D64));
    // 0x804653FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80465400: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x80465404: jal         0x8046475C
    // 0x80465408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8046475C(rdram, ctx);
        goto after_0;
    // 0x80465408: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8046540C: jal         0x804646E4
    // 0x80465410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804646E4(rdram, ctx);
        goto after_1;
    // 0x80465410: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80465414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80465418: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046541C: jr          $ra
    // 0x80465420: nop

    return;
    // 0x80465420: nop

;}
RECOMP_FUNC void func_8067EA14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067EA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067EA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067EA1C: jal         0x8067E94C
    // 0x8067EA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8067E94C(rdram, ctx);
        goto after_0;
    // 0x8067EA20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067EA24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067EA28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067EA2C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8067EA30: jal         0x8067EAE0
    // 0x8067EA34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8067EAE0(rdram, ctx);
        goto after_1;
    // 0x8067EA34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8067EA38: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8067EA3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067EA40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067EA44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8067EA48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067EA4C: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067EA50: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8067EA54: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8067EA58: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067EA5C: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067EA60: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8067EA64: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8067EA68: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8067EA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067EA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067EA74: jr          $ra
    // 0x8067EA78: nop

    return;
    // 0x8067EA78: nop

;}
RECOMP_FUNC void func_807BB4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB4E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807BB4E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB4E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807BB4EC: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x807BB4F0: jal         0x80058958
    // 0x807BB4F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_0;
    // 0x807BB4F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x807BB4F8: beq         $v0, $zero, L_807BB578
    if (ctx->r2 == 0) {
        // 0x807BB4FC: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_807BB578;
    }
    // 0x807BB4FC: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x807BB500: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x807BB504: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x807BB508: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x807BB50C: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x807BB510: beql        $t1, $zero, L_807BB57C
    if (ctx->r9 == 0) {
        // 0x807BB514: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_807BB57C;
    }
    goto skip_0;
    // 0x807BB514: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x807BB518: jal         0x80056564
    // 0x807BB51C: nop

    func_80056564(rdram, ctx);
        goto after_1;
    // 0x807BB51C: nop

    after_1:
    // 0x807BB520: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x807BB524: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807BB528: beq         $v0, $zero, L_807BB580
    if (ctx->r2 == 0) {
        // 0x807BB52C: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_807BB580;
    }
    // 0x807BB52C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x807BB530: jal         0x800457A0
    // 0x807BB534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800457A0(rdram, ctx);
        goto after_2;
    // 0x807BB534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807BB538: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x807BB53C: addiu       $t4, $zero, 0x29
    ctx->r12 = ADD32(0, 0X29);
    // 0x807BB540: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x807BB544: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x807BB548: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x807BB54C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x807BB550: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x807BB554: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807BB558: jal         0x80056584
    // 0x807BB55C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    func_80056584(rdram, ctx);
        goto after_3;
    // 0x807BB55C: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    after_3:
    // 0x807BB560: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x807BB564: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x807BB568: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x807BB56C: lw          $t8, 0x16C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X16C);
    // 0x807BB570: b           L_807BB580
    // 0x807BB574: sw          $t6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r14;
        goto L_807BB580;
    // 0x807BB574: sw          $t6, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r14;
L_807BB578:
    // 0x807BB578: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_807BB57C:
    // 0x807BB57C: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
L_807BB580:
    // 0x807BB580: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BB584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807BB588: jr          $ra
    // 0x807BB58C: nop

    return;
    // 0x807BB58C: nop

;}
RECOMP_FUNC void func_80448790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80448790: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80448794: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80448798: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8044879C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804487A0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804487A4: bne         $a2, $zero, L_804487E4
    if (ctx->r6 != 0) {
        // 0x804487A8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_804487E4;
    }
    // 0x804487A8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804487AC: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x804487B0: lw          $v1, 0x48($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X48);
    // 0x804487B4: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x804487B8: slt         $at, $t7, $v1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x804487BC: bne         $at, $zero, L_80448824
    if (ctx->r1 != 0) {
        // 0x804487C0: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_80448824;
    }
    // 0x804487C0: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x804487C4: jal         0x804465DC
    // 0x804487C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_0;
    // 0x804487C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x804487CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804487D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804487D4: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x804487D8: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x804487DC: b           L_80448824
    // 0x804487E0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
        goto L_80448824;
    // 0x804487E0: sw          $t9, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r25;
L_804487E4:
    // 0x804487E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804487E8: bnel        $a2, $at, L_80448814
    if (ctx->r6 != ctx->r1) {
        // 0x804487EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80448814;
    }
    goto skip_0;
    // 0x804487EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x804487F0: jal         0x804465DC
    // 0x804487F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_804465DC(rdram, ctx);
        goto after_1;
    // 0x804487F4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804487F8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804487FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80448800: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80448804: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80448808: b           L_80448824
    // 0x8044880C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
        goto L_80448824;
    // 0x8044880C: sw          $t0, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r8;
    // 0x80448810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80448814:
    // 0x80448814: bnel        $a2, $at, L_80448828
    if (ctx->r6 != ctx->r1) {
        // 0x80448818: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80448828;
    }
    goto skip_1;
    // 0x80448818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044881C: jal         0x80446634
    // 0x80448820: nop

    func_80446634(rdram, ctx);
        goto after_2;
    // 0x80448820: nop

    after_2:
L_80448824:
    // 0x80448824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80448828:
    // 0x80448828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8044882C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80448830: jr          $ra
    // 0x80448834: nop

    return;
    // 0x80448834: nop

;}
RECOMP_FUNC void func_8003EA94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EA94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003EA98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003EA9C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003EAA0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003EAA4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003EAA8: sb          $t6, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r14;
    // 0x8003EAAC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8003EAB0: lw          $t9, 0x1C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X1C);
    // 0x8003EAB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8003EAB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003EABC: jalr        $t9
    // 0x8003EAC0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8003EAC0: nop

    after_0:
    // 0x8003EAC4: jal         0x8003EA1C
    // 0x8003EAC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8003EA1C(rdram, ctx);
        goto after_1;
    // 0x8003EAC8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003EACC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003EAD0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EAD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003EAD8: jr          $ra
    // 0x8003EADC: nop

    return;
    // 0x8003EADC: nop

;}
RECOMP_FUNC void func_8000E804(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E804: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E80C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8000E810: lw          $t0, 0x50($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X50);
    // 0x8000E814: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x8000E818: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000E81C: lw          $t6, 0x4C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4C);
    // 0x8000E820: bne         $a1, $at, L_8000E858
    if (ctx->r5 != ctx->r1) {
        // 0x8000E824: sw          $t6, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r14;
            goto L_8000E858;
    }
    // 0x8000E824: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8000E828: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
    // 0x8000E82C: jal         0x8000DD00
    // 0x8000E830: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    func_8000DD00(rdram, ctx);
        goto after_0;
    // 0x8000E830: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000E834: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000E838: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E83C: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // 0x8000E840: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000E844: ori         $t2, $t9, 0x20
    ctx->r10 = ctx->r25 | 0X20;
    // 0x8000E848: andi        $t3, $t2, 0xFD
    ctx->r11 = ctx->r10 & 0XFD;
    // 0x8000E84C: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x8000E850: b           L_8000EC08
    // 0x8000E854: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
        goto L_8000EC08;
    // 0x8000E854: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
L_8000E858:
    // 0x8000E858: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x8000E85C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000E860: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x8000E864: sb          $t5, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r13;
    // 0x8000E868: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8000E86C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000E870: sll         $t7, $t6, 6
    ctx->r15 = S32(ctx->r14 << 6);
    // 0x8000E874: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000E878: bne         $t8, $at, L_8000E9C8
    if (ctx->r24 != ctx->r1) {
        // 0x8000E87C: andi        $a1, $a1, 0xC0
        ctx->r5 = ctx->r5 & 0XC0;
            goto L_8000E9C8;
    }
    // 0x8000E87C: andi        $a1, $a1, 0xC0
    ctx->r5 = ctx->r5 & 0XC0;
    // 0x8000E880: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8000E884: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8000E888: andi        $a1, $a1, 0xC0
    ctx->r5 = ctx->r5 & 0XC0;
    // 0x8000E88C: beql        $a1, $zero, L_8000E8B0
    if (ctx->r5 == 0) {
        // 0x8000E890: addiu       $a0, $a2, 0x54
        ctx->r4 = ADD32(ctx->r6, 0X54);
            goto L_8000E8B0;
    }
    goto skip_0;
    // 0x8000E890: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
    skip_0:
    // 0x8000E894: beq         $a1, $at, L_8000E908
    if (ctx->r5 == ctx->r1) {
        // 0x8000E898: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_8000E908;
    }
    // 0x8000E898: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8000E89C: beql        $a1, $at, L_8000E954
    if (ctx->r5 == ctx->r1) {
        // 0x8000E8A0: lh          $t6, 0x14($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X14);
            goto L_8000E954;
    }
    goto skip_1;
    // 0x8000E8A0: lh          $t6, 0x14($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X14);
    skip_1:
    // 0x8000E8A4: b           L_8000E984
    // 0x8000E8A8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
        goto L_8000E984;
    // 0x8000E8A8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8000E8AC: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
L_8000E8B0:
    // 0x8000E8B0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8000E8B4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E8B8: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000E8BC: jal         0x8000DD00
    // 0x8000E8C0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8000DD00(rdram, ctx);
        goto after_1;
    // 0x8000E8C0: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_1:
    // 0x8000E8C4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E8C8: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x8000E8CC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000E8D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000E8D4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000E8D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000E8DC: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E8E0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8000E8E4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000E8E8: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x8000E8EC: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8000E8F0: sb          $t2, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r10;
    // 0x8000E8F4: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8000E8F8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8000E8FC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8000E900: b           L_8000E984
    // 0x8000E904: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
        goto L_8000E984;
    // 0x8000E904: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
L_8000E908:
    // 0x8000E908: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
    // 0x8000E90C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8000E910: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E914: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000E918: jal         0x8000DD00
    // 0x8000E91C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8000DD00(rdram, ctx);
        goto after_2;
    // 0x8000E91C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_2:
    // 0x8000E920: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E924: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x8000E928: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000E92C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000E930: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000E934: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000E938: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E93C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x8000E940: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8000E944: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x8000E948: b           L_8000E984
    // 0x8000E94C: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
        goto L_8000E984;
    // 0x8000E94C: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
    // 0x8000E950: lh          $t6, 0x14($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X14);
L_8000E954:
    // 0x8000E954: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
    // 0x8000E958: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
    // 0x8000E95C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8000E960: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x8000E964: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8000E968: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8000E96C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x8000E970: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8000E974: sb          $t9, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r25;
    // 0x8000E978: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8000E97C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8000E980: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
L_8000E984:
    // 0x8000E984: slti        $at, $a3, 0x80
    ctx->r1 = SIGNED(ctx->r7) < 0X80 ? 1 : 0;
    // 0x8000E988: beql        $at, $zero, L_8000E99C
    if (ctx->r1 == 0) {
        // 0x8000E98C: addiu       $a3, $zero, 0x7F
        ctx->r7 = ADD32(0, 0X7F);
            goto L_8000E99C;
    }
    goto skip_2;
    // 0x8000E98C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    skip_2:
    // 0x8000E990: bgezl       $a3, L_8000E9A0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8000E994: mtc1        $a3, $f4
        ctx->f4.u32l = ctx->r7;
            goto L_8000E9A0;
    }
    goto skip_3;
    // 0x8000E994: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    skip_3:
    // 0x8000E998: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
L_8000E99C:
    // 0x8000E99C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
L_8000E9A0:
    // 0x8000E9A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8000E9A4: lwc1        $f8, -0x4204($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4204);
    // 0x8000E9A8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E9AC: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000E9B0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000E9B4: swc1        $f10, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f10.u32l;
    // 0x8000E9B8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8000E9BC: subu        $t4, $t3, $a1
    ctx->r12 = SUB32(ctx->r11, ctx->r5);
    // 0x8000E9C0: b           L_8000EA38
    // 0x8000E9C4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
        goto L_8000EA38;
    // 0x8000E9C4: sw          $t4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r12;
L_8000E9C8:
    // 0x8000E9C8: beq         $a1, $zero, L_8000E9EC
    if (ctx->r5 == 0) {
        // 0x8000E9CC: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_8000E9EC;
    }
    // 0x8000E9CC: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8000E9D0: beql        $a1, $at, L_8000EA1C
    if (ctx->r5 == ctx->r1) {
        // 0x8000E9D4: lh          $t5, 0x12($a2)
        ctx->r13 = MEM_H(ctx->r6, 0X12);
            goto L_8000EA1C;
    }
    goto skip_4;
    // 0x8000E9D4: lh          $t5, 0x12($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X12);
    skip_4:
    // 0x8000E9D8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8000E9DC: beql        $a1, $at, L_8000EA28
    if (ctx->r5 == ctx->r1) {
        // 0x8000E9E0: lh          $t6, 0x14($a2)
        ctx->r14 = MEM_H(ctx->r6, 0X14);
            goto L_8000EA28;
    }
    goto skip_5;
    // 0x8000E9E0: lh          $t6, 0x14($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X14);
    skip_5:
    // 0x8000E9E4: b           L_8000EA30
    // 0x8000E9E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
        goto L_8000EA30;
    // 0x8000E9E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8000E9EC:
    // 0x8000E9EC: addiu       $a0, $a2, 0x54
    ctx->r4 = ADD32(ctx->r6, 0X54);
    // 0x8000E9F0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8000E9F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8000E9F8: jal         0x8000DD00
    // 0x8000E9FC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    func_8000DD00(rdram, ctx);
        goto after_3;
    // 0x8000E9FC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_3:
    // 0x8000EA00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8000EA04: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8000EA08: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8000EA0C: sh          $v0, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r2;
    // 0x8000EA10: b           L_8000EA2C
    // 0x8000EA14: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
        goto L_8000EA2C;
    // 0x8000EA14: sh          $v0, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r2;
    // 0x8000EA18: lh          $t5, 0x12($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X12);
L_8000EA1C:
    // 0x8000EA1C: b           L_8000EA2C
    // 0x8000EA20: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
        goto L_8000EA2C;
    // 0x8000EA20: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
    // 0x8000EA24: lh          $t6, 0x14($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X14);
L_8000EA28:
    // 0x8000EA28: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
L_8000EA2C:
    // 0x8000EA2C: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
L_8000EA30:
    // 0x8000EA30: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8000EA34: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_8000EA38:
    // 0x8000EA38: lbu         $v1, 0xD($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0XD);
    // 0x8000EA3C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000EA40: beql        $v1, $zero, L_8000EAEC
    if (ctx->r3 == 0) {
        // 0x8000EA44: lwc1        $f16, 0x3C($a2)
        ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
            goto L_8000EAEC;
    }
    goto skip_6;
    // 0x8000EA44: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
    skip_6:
    // 0x8000EA48: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x8000EA4C: lwc1        $f12, 0x3C($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x8000EA50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000EA54: divu        $zero, $v0, $v1
    lo = S32(U32(ctx->r2) / U32(ctx->r3)); hi = S32(U32(ctx->r2) % U32(ctx->r3));
    // 0x8000EA58: mfhi        $t9
    ctx->r25 = hi;
    // 0x8000EA5C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000EA60: bne         $v1, $zero, L_8000EA6C
    if (ctx->r3 != 0) {
        // 0x8000EA64: nop
    
            goto L_8000EA6C;
    }
    // 0x8000EA64: nop

    // 0x8000EA68: break       7
    do_break(2147543656);
L_8000EA6C:
    // 0x8000EA6C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000EA70: bgez        $t9, L_8000EA84
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000EA74: nop
    
            goto L_8000EA84;
    }
    // 0x8000EA74: nop

    // 0x8000EA78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000EA7C: nop

    // 0x8000EA80: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8000EA84:
    // 0x8000EA84: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000EA88: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8000EA8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000EA90: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x8000EA94: beq         $t1, $zero, L_8000EAA0
    if (ctx->r9 == 0) {
        // 0x8000EA98: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_8000EAA0;
    }
    // 0x8000EA98: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000EA9C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8000EAA0:
    // 0x8000EAA0: add.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8000EAA4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8000EAA8: nop

    // 0x8000EAAC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000EAB0: swc1        $f0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f0.u32l;
    // 0x8000EAB4: bc1fl       L_8000EAC8
    if (!c1cs) {
        // 0x8000EAB8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000EAC8;
    }
    goto skip_7;
    // 0x8000EAB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_7:
    // 0x8000EABC: b           L_8000EAF0
    // 0x8000EAC0: swc1        $f14, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f14.u32l;
        goto L_8000EAF0;
    // 0x8000EAC0: swc1        $f14, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f14.u32l;
    // 0x8000EAC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000EAC8:
    // 0x8000EAC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000EACC: lwc1        $f10, 0x38($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X38);
    // 0x8000EAD0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8000EAD4: nop

    // 0x8000EAD8: bc1fl       L_8000EAF4
    if (!c1cs) {
        // 0x8000EADC: lhu         $v0, 0x3A($sp)
        ctx->r2 = MEM_HU(ctx->r29, 0X3A);
            goto L_8000EAF4;
    }
    goto skip_8;
    // 0x8000EADC: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
    skip_8:
    // 0x8000EAE0: b           L_8000EAF0
    // 0x8000EAE4: swc1        $f0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f0.u32l;
        goto L_8000EAF0;
    // 0x8000EAE4: swc1        $f0, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f0.u32l;
    // 0x8000EAE8: lwc1        $f16, 0x3C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X3C);
L_8000EAEC:
    // 0x8000EAEC: swc1        $f16, 0x38($a2)
    MEM_W(0X38, ctx->r6) = ctx->f16.u32l;
L_8000EAF0:
    // 0x8000EAF0: lhu         $v0, 0x3A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X3A);
L_8000EAF4:
    // 0x8000EAF4: lbu         $t2, 0x3($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X3);
    // 0x8000EAF8: sh          $v0, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r2;
    // 0x8000EAFC: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EB00: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000EB04: mflo        $t3
    ctx->r11 = lo;
    // 0x8000EB08: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x8000EB0C: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x8000EB10: lbu         $t5, 0xE($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XE);
    // 0x8000EB14: beql        $t5, $zero, L_8000EB9C
    if (ctx->r13 == 0) {
        // 0x8000EB18: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_8000EB9C;
    }
    goto skip_9;
    // 0x8000EB18: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_9:
    // 0x8000EB1C: lw          $v0, 0x6BA4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BA4);
    // 0x8000EB20: lbu         $t6, 0xD($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XD);
    // 0x8000EB24: lh          $v1, 0xA($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XA);
    // 0x8000EB28: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8000EB2C: divu        $zero, $v0, $t6
    lo = S32(U32(ctx->r2) / U32(ctx->r14)); hi = S32(U32(ctx->r2) % U32(ctx->r14));
    // 0x8000EB30: mfhi        $t7
    ctx->r15 = hi;
    // 0x8000EB34: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x8000EB38: bne         $t6, $zero, L_8000EB44
    if (ctx->r14 != 0) {
        // 0x8000EB3C: nop
    
            goto L_8000EB44;
    }
    // 0x8000EB3C: nop

    // 0x8000EB40: break       7
    do_break(2147543872);
L_8000EB44:
    // 0x8000EB44: multu       $v1, $t7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000EB48: mflo        $a0
    ctx->r4 = lo;
    // 0x8000EB4C: nop

    // 0x8000EB50: nop

    // 0x8000EB54: divu        $zero, $a0, $at
    lo = S32(U32(ctx->r4) / U32(ctx->r1)); hi = S32(U32(ctx->r4) % U32(ctx->r1));
    // 0x8000EB58: mflo        $a0
    ctx->r4 = lo;
    // 0x8000EB5C: beql        $t8, $zero, L_8000EB6C
    if (ctx->r24 == 0) {
        // 0x8000EB60: addu        $t9, $v1, $a0
        ctx->r25 = ADD32(ctx->r3, ctx->r4);
            goto L_8000EB6C;
    }
    goto skip_10;
    // 0x8000EB60: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
    skip_10:
    // 0x8000EB64: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8000EB68: addu        $t9, $v1, $a0
    ctx->r25 = ADD32(ctx->r3, ctx->r4);
L_8000EB6C:
    // 0x8000EB6C: sh          $t9, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r25;
    // 0x8000EB70: lh          $v1, 0xA($a2)
    ctx->r3 = MEM_H(ctx->r6, 0XA);
    // 0x8000EB74: bgezl       $v1, L_8000EB88
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000EB78: lh          $v0, 0x8($a2)
        ctx->r2 = MEM_H(ctx->r6, 0X8);
            goto L_8000EB88;
    }
    goto skip_11;
    // 0x8000EB78: lh          $v0, 0x8($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X8);
    skip_11:
    // 0x8000EB7C: b           L_8000EB98
    // 0x8000EB80: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
        goto L_8000EB98;
    // 0x8000EB80: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x8000EB84: lh          $v0, 0x8($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X8);
L_8000EB88:
    // 0x8000EB88: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000EB8C: beql        $at, $zero, L_8000EB9C
    if (ctx->r1 == 0) {
        // 0x8000EB90: lw          $t1, 0x2C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X2C);
            goto L_8000EB9C;
    }
    goto skip_12;
    // 0x8000EB90: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    skip_12:
    // 0x8000EB94: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
L_8000EB98:
    // 0x8000EB98: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
L_8000EB9C:
    // 0x8000EB9C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8000EBA0: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8000EBA4: bgezl       $t4, L_8000EBC0
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000EBA8: lw          $t7, 0x0($t0)
        ctx->r15 = MEM_W(ctx->r8, 0X0);
            goto L_8000EBC0;
    }
    goto skip_13;
    // 0x8000EBA8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    skip_13:
    // 0x8000EBAC: lbu         $t5, 0x3($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X3);
    // 0x8000EBB0: andi        $t6, $t5, 0x50
    ctx->r14 = ctx->r13 & 0X50;
    // 0x8000EBB4: bnel        $t6, $zero, L_8000EBD4
    if (ctx->r14 != 0) {
        // 0x8000EBB8: lbu         $t2, 0x0($a2)
        ctx->r10 = MEM_BU(ctx->r6, 0X0);
            goto L_8000EBD4;
    }
    goto skip_14;
    // 0x8000EBB8: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
    skip_14:
    // 0x8000EBBC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_8000EBC0:
    // 0x8000EBC0: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8000EBC4: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8000EBC8: bgezl       $t9, L_8000EBE8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000EBCC: lw          $t5, 0xD8($t4)
        ctx->r13 = MEM_W(ctx->r12, 0XD8);
            goto L_8000EBE8;
    }
    goto skip_15;
    // 0x8000EBCC: lw          $t5, 0xD8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD8);
    skip_15:
    // 0x8000EBD0: lbu         $t2, 0x0($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X0);
L_8000EBD4:
    // 0x8000EBD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EBD8: ori         $t3, $t2, 0x20
    ctx->r11 = ctx->r10 | 0X20;
    // 0x8000EBDC: b           L_8000EC08
    // 0x8000EBE0: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
        goto L_8000EC08;
    // 0x8000EBE0: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x8000EBE4: lw          $t5, 0xD8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XD8);
L_8000EBE8:
    // 0x8000EBE8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000EBEC: beq         $t5, $zero, L_8000EC08
    if (ctx->r13 == 0) {
        // 0x8000EBF0: nop
    
            goto L_8000EC08;
    }
    // 0x8000EBF0: nop

    // 0x8000EBF4: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x8000EBF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000EBFC: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8000EC00: b           L_8000EC08
    // 0x8000EC04: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
        goto L_8000EC08;
    // 0x8000EC04: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
L_8000EC08:
    // 0x8000EC08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000EC0C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000EC10: jr          $ra
    // 0x8000EC14: nop

    return;
    // 0x8000EC14: nop

;}
RECOMP_FUNC void Fault_PrintDebuggerInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070B60: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x80070B64: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x80070B68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070B6C: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_80070B70:
    // 0x80070B70: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x80070B74: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80070B78: bne         $t9, $sp, L_80070B70
    if (ctx->r25 != ctx->r29) {
        // 0x80070B7C: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_80070B70;
    }
    // 0x80070B7C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x80070B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070B84: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80070B88: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80070B8C: addiu       $a2, $zero, 0x114
    ctx->r6 = ADD32(0, 0X114);
    // 0x80070B90: jal         0x8006F600
    // 0x80070B94: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    Fault_DrawRec(rdram, ctx);
        goto after_0;
    // 0x80070B94: addiu       $a3, $zero, 0xD0
    ctx->r7 = ADD32(0, 0XD0);
    after_0:
    // 0x80070B98: addiu       $t6, $zero, 0x7BFF
    ctx->r14 = ADD32(0, 0X7BFF);
    // 0x80070B9C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070BA0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070BA4: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80070BA8: sh          $t6, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r14;
    // 0x80070BAC: lw          $a3, 0x65AC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X65AC);
    // 0x80070BB0: addiu       $a2, $a2, 0x1820
    ctx->r6 = ADD32(ctx->r6, 0X1820);
    // 0x80070BB4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070BB8: jal         0x8006F884
    // 0x80070BBC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    Fault_Printf(rdram, ctx);
        goto after_1;
    // 0x80070BBC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x80070BC0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070BC4: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80070BC8: lw          $a3, 0x65B0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X65B0);
    // 0x80070BCC: addiu       $a2, $a2, 0x183C
    ctx->r6 = ADD32(ctx->r6, 0X183C);
    // 0x80070BD0: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070BD4: jal         0x8006F884
    // 0x80070BD8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Fault_Printf(rdram, ctx);
        goto after_2;
    // 0x80070BD8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x80070BDC: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070BE0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80070BE4: lw          $a3, 0x65B4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X65B4);
    // 0x80070BE8: addiu       $a2, $a2, 0x1858
    ctx->r6 = ADD32(ctx->r6, 0X1858);
    // 0x80070BEC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070BF0: jal         0x8006F884
    // 0x80070BF4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    Fault_Printf(rdram, ctx);
        goto after_3;
    // 0x80070BF4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_3:
    // 0x80070BF8: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070BFC: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80070C00: lw          $a3, 0x65B8($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X65B8);
    // 0x80070C04: addiu       $a2, $a2, 0x1874
    ctx->r6 = ADD32(ctx->r6, 0X1874);
    // 0x80070C08: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070C0C: jal         0x8006F884
    // 0x80070C10: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    Fault_Printf(rdram, ctx);
        goto after_4;
    // 0x80070C10: addiu       $a1, $zero, 0x38
    ctx->r5 = ADD32(0, 0X38);
    after_4:
    // 0x80070C14: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070C18: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80070C1C: lw          $a3, 0x65BC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X65BC);
    // 0x80070C20: addiu       $a2, $a2, 0x1890
    ctx->r6 = ADD32(ctx->r6, 0X1890);
    // 0x80070C24: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070C28: jal         0x8006F884
    // 0x80070C2C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    Fault_Printf(rdram, ctx);
        goto after_5;
    // 0x80070C2C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_5:
    // 0x80070C30: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070C34: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80070C38: lw          $a3, -0x739C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X739C);
    // 0x80070C3C: addiu       $a2, $a2, 0x18AC
    ctx->r6 = ADD32(ctx->r6, 0X18AC);
    // 0x80070C40: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070C44: jal         0x8006F884
    // 0x80070C48: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    Fault_Printf(rdram, ctx);
        goto after_6;
    // 0x80070C48: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    after_6:
    // 0x80070C4C: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070C50: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80070C54: lhu         $a3, -0x7398($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7398);
    // 0x80070C58: addiu       $a2, $a2, 0x18C4
    ctx->r6 = ADD32(ctx->r6, 0X18C4);
    // 0x80070C5C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070C60: jal         0x8006F884
    // 0x80070C64: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    Fault_Printf(rdram, ctx);
        goto after_7;
    // 0x80070C64: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    after_7:
    // 0x80070C68: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80070C6C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80070C70: lhu         $a3, -0x7396($a3)
    ctx->r7 = MEM_HU(ctx->r7, -0X7396);
    // 0x80070C74: addiu       $a2, $a2, 0x18D8
    ctx->r6 = ADD32(ctx->r6, 0X18D8);
    // 0x80070C78: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80070C7C: jal         0x8006F884
    // 0x80070C80: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    Fault_Printf(rdram, ctx);
        goto after_8;
    // 0x80070C80: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    after_8:
    // 0x80070C84: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80070C88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80070C8C: sh          $t7, -0x7B94($at)
    MEM_H(-0X7B94, ctx->r1) = ctx->r15;
    // 0x80070C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80070C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80070C98: jr          $ra
    // 0x80070C9C: nop

    return;
    // 0x80070C9C: nop

;}
RECOMP_FUNC void func_8002E7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E7C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002E7CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E7D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E7D4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002E7D8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002E7DC: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002E7E0: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8002E7E4: addiu       $a1, $a1, -0x2878
    ctx->r5 = ADD32(ctx->r5, -0X2878);
    // 0x8002E7E8: addiu       $t7, $t7, 0x520
    ctx->r15 = ADD32(ctx->r15, 0X520);
    // 0x8002E7EC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8002E7F0: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8002E7F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E7F8: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002E7FC: sb          $t8, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r24;
    // 0x8002E800: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
    // 0x8002E804: jal         0x80028118
    // 0x8002E808: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002E808: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002E80C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002E810: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8002E814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002E818: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x8002E81C: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x8002E820: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8002E824: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8002E828: lw          $t0, -0x76F8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X76F8);
    // 0x8002E82C: lw          $t1, 0x10($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X10);
    // 0x8002E830: lw          $t9, 0x30($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X30);
    // 0x8002E834: jalr        $t9
    // 0x8002E838: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8002E838: nop

    after_1:
    // 0x8002E83C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8002E840: jal         0x8002BBF4
    // 0x8002E844: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8002BBF4(rdram, ctx);
        goto after_2;
    // 0x8002E844: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8002E848: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002E84C: lui         $t2, 0x8002
    ctx->r10 = S32(0X8002 << 16);
    // 0x8002E850: addiu       $t2, $t2, 0x381C
    ctx->r10 = ADD32(ctx->r10, 0X381C);
    // 0x8002E854: sw          $t2, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r10;
    // 0x8002E858: jal         0x800678B0
    // 0x8002E85C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    func_800678B0(rdram, ctx);
        goto after_3;
    // 0x8002E85C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8002E860: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8002E864: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002E868: jal         0x80067838
    // 0x8002E86C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80067838(rdram, ctx);
        goto after_4;
    // 0x8002E86C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8002E870: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8002E874: jal         0x80067930
    // 0x8002E878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_5;
    // 0x8002E878: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8002E87C: beq         $v0, $zero, L_8002E898
    if (ctx->r2 == 0) {
        // 0x8002E880: addiu       $a0, $zero, 0x23
        ctx->r4 = ADD32(0, 0X23);
            goto L_8002E898;
    }
    // 0x8002E880: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8002E884: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8002E888: jal         0x80067878
    // 0x8002E88C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_6;
    // 0x8002E88C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8002E890: b           L_8002E8B4
    // 0x8002E894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002E8B4;
    // 0x8002E894: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E898:
    // 0x8002E898: jal         0x80067930
    // 0x8002E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067930(rdram, ctx);
        goto after_7;
    // 0x8002E89C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8002E8A0: beq         $v0, $zero, L_8002E8B0
    if (ctx->r2 == 0) {
        // 0x8002E8A4: addiu       $a0, $zero, 0x23
        ctx->r4 = ADD32(0, 0X23);
            goto L_8002E8B0;
    }
    // 0x8002E8A4: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x8002E8A8: jal         0x80067878
    // 0x8002E8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067878(rdram, ctx);
        goto after_8;
    // 0x8002E8AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
L_8002E8B0:
    // 0x8002E8B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E8B4:
    // 0x8002E8B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E8B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002E8BC: jr          $ra
    // 0x8002E8C0: nop

    return;
    // 0x8002E8C0: nop

;}
RECOMP_FUNC void func_8003F18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F18C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003F190: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003F194: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003F198: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003F19C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003F1A0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8003F1A4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8003F1A8: jal         0x8003EBD4
    // 0x8003F1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_8003EBD4(rdram, ctx);
        goto after_0;
    // 0x8003F1AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8003F1B0: bne         $v0, $zero, L_8003F1C0
    if (ctx->r2 != 0) {
        // 0x8003F1B4: nop
    
            goto L_8003F1C0;
    }
    // 0x8003F1B4: nop

    // 0x8003F1B8: b           L_8003F210
    // 0x8003F1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003F210;
    // 0x8003F1BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003F1C0:
    // 0x8003F1C0: jal         0x800447C8
    // 0x8003F1C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_800447C8(rdram, ctx);
        goto after_1;
    // 0x8003F1C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8003F1C8: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8003F1CC: jal         0x80065490
    // 0x8003F1D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003F1D0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_2:
    // 0x8003F1D4: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8003F1D8: jal         0x80065490
    // 0x8003F1DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003F1DC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_3:
    // 0x8003F1E0: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8003F1E4: jal         0x80065490
    // 0x8003F1E8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    func_80065490(rdram, ctx);
        goto after_4;
    // 0x8003F1E8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_4:
    // 0x8003F1EC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003F1F0: addiu       $t6, $t6, -0x19E8
    ctx->r14 = ADD32(ctx->r14, -0X19E8);
    // 0x8003F1F4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F1F8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F1FC: lhu         $a1, 0x32($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X32);
    // 0x8003F200: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8003F204: jal         0x8003E6C4
    // 0x8003F208: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    func_8003E6C4(rdram, ctx);
        goto after_5;
    // 0x8003F208: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    after_5:
    // 0x8003F20C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003F210:
    // 0x8003F210: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003F214: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003F218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8003F21C: jr          $ra
    // 0x8003F220: nop

    return;
    // 0x8003F220: nop

;}
RECOMP_FUNC void eepmgr_SendWrite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007D594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007D598: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007D59C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8007D5A0: lh          $t6, 0x48($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X48);
    // 0x8007D5A4: addiu       $a1, $a3, 0x48
    ctx->r5 = ADD32(ctx->r7, 0X48);
    // 0x8007D5A8: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8007D5AC: beq         $t6, $zero, L_8007D5BC
    if (ctx->r14 == 0) {
        // 0x8007D5B0: addiu       $a0, $a3, 0x14
        ctx->r4 = ADD32(ctx->r7, 0X14);
            goto L_8007D5BC;
    }
    // 0x8007D5B0: addiu       $a0, $a3, 0x14
    ctx->r4 = ADD32(ctx->r7, 0X14);
L_8007D5B4:
    // 0x8007D5B4: b           L_8007D5B4
    pause_self(rdram);
    // 0x8007D5B8: nop

L_8007D5BC:
    // 0x8007D5BC: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x8007D5C0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D5C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007D5C8: jal         0x80082210
    // 0x8007D5CC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8007D5CC: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    after_0:
    // 0x8007D5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007D5D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007D5D8: jr          $ra
    // 0x8007D5DC: nop

    return;
    // 0x8007D5DC: nop

;}
RECOMP_FUNC void func_8041DB8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DB8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8041DB90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041DB94: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8041DB98: lh          $a1, 0x1F0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X1F0);
    // 0x8041DB9C: jal         0x80067878
    // 0x8041DBA0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x8041DBA0: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8041DBA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041DBA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8041DBAC: jr          $ra
    // 0x8041DBB0: nop

    return;
    // 0x8041DBB0: nop

;}
RECOMP_FUNC void func_80534E34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80534E34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80534E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80534E3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80534E40: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80534E44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80534E48: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x80534E4C: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80534E50: beql        $t7, $zero, L_80534E88
    if (ctx->r15 == 0) {
        // 0x80534E54: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80534E88;
    }
    goto skip_0;
    // 0x80534E54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80534E58: lw          $t8, 0x1E0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1E0);
    // 0x80534E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80534E60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80534E64: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80534E68: slti        $at, $t9, 0x3C
    ctx->r1 = SIGNED(ctx->r25) < 0X3C ? 1 : 0;
    // 0x80534E6C: bne         $at, $zero, L_80534EB4
    if (ctx->r1 != 0) {
        // 0x80534E70: sw          $t9, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r25;
            goto L_80534EB4;
    }
    // 0x80534E70: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x80534E74: jal         0x805350A0
    // 0x80534E78: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_0;
    // 0x80534E78: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_0:
    // 0x80534E7C: b           L_80534EB4
    // 0x80534E80: nop

        goto L_80534EB4;
    // 0x80534E80: nop

    // 0x80534E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80534E88:
    // 0x80534E88: jal         0x805347F0
    // 0x80534E8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_805347F0(rdram, ctx);
        goto after_1;
    // 0x80534E8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80534E90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80534E94: bne         $v0, $at, L_80534EB4
    if (ctx->r2 != ctx->r1) {
        // 0x80534E98: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80534EB4;
    }
    // 0x80534E98: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80534E9C: lhu         $t1, 0xC($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0XC);
    // 0x80534EA0: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80534EA4: ori         $t2, $t1, 0x2
    ctx->r10 = ctx->r9 | 0X2;
    // 0x80534EA8: sh          $t2, 0xC($v1)
    MEM_H(0XC, ctx->r3) = ctx->r10;
    // 0x80534EAC: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80534EB0: sh          $t3, 0x144($s0)
    MEM_H(0X144, ctx->r16) = ctx->r11;
L_80534EB4:
    // 0x80534EB4: jal         0x8053484C
    // 0x80534EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8053484C(rdram, ctx);
        goto after_2;
    // 0x80534EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80534EBC: jal         0x80534620
    // 0x80534EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534620(rdram, ctx);
        goto after_3;
    // 0x80534EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80534EC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80534EC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80534ECC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80534ED0: jr          $ra
    // 0x80534ED4: nop

    return;
    // 0x80534ED4: nop

;}
RECOMP_FUNC void func_8079A588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079A58C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079A590: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079A594: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8079A598: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8079A59C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8079A5A0: beq         $v0, $at, L_8079A64C
    if (ctx->r2 == ctx->r1) {
        // 0x8079A5A4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8079A64C;
    }
    // 0x8079A5A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8079A5A8: beql        $v0, $at, L_8079A650
    if (ctx->r2 == ctx->r1) {
        // 0x8079A5AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8079A650;
    }
    goto skip_0;
    // 0x8079A5AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8079A5B0: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x8079A5B4: slti        $at, $v0, 0x471D
    ctx->r1 = SIGNED(ctx->r2) < 0X471D ? 1 : 0;
    // 0x8079A5B8: bne         $at, $zero, L_8079A5D8
    if (ctx->r1 != 0) {
        // 0x8079A5BC: addiu       $at, $zero, 0x471D
        ctx->r1 = ADD32(0, 0X471D);
            goto L_8079A5D8;
    }
    // 0x8079A5BC: addiu       $at, $zero, 0x471D
    ctx->r1 = ADD32(0, 0X471D);
    // 0x8079A5C0: beq         $v0, $at, L_8079A634
    if (ctx->r2 == ctx->r1) {
        // 0x8079A5C4: addiu       $at, $zero, 0x471E
        ctx->r1 = ADD32(0, 0X471E);
            goto L_8079A634;
    }
    // 0x8079A5C4: addiu       $at, $zero, 0x471E
    ctx->r1 = ADD32(0, 0X471E);
    // 0x8079A5C8: beql        $v0, $at, L_8079A638
    if (ctx->r2 == ctx->r1) {
        // 0x8079A5CC: addiu       $t7, $zero, 0x1E
        ctx->r15 = ADD32(0, 0X1E);
            goto L_8079A638;
    }
    goto skip_1;
    // 0x8079A5CC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    skip_1:
    // 0x8079A5D0: b           L_8079A650
    // 0x8079A5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A650;
    // 0x8079A5D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A5D8:
    // 0x8079A5D8: slti        $at, $v0, 0x46E2
    ctx->r1 = SIGNED(ctx->r2) < 0X46E2 ? 1 : 0;
    // 0x8079A5DC: bne         $at, $zero, L_8079A5F4
    if (ctx->r1 != 0) {
        // 0x8079A5E0: addiu       $at, $zero, 0x471C
        ctx->r1 = ADD32(0, 0X471C);
            goto L_8079A5F4;
    }
    // 0x8079A5E0: addiu       $at, $zero, 0x471C
    ctx->r1 = ADD32(0, 0X471C);
    // 0x8079A5E4: beql        $v0, $at, L_8079A638
    if (ctx->r2 == ctx->r1) {
        // 0x8079A5E8: addiu       $t7, $zero, 0x1E
        ctx->r15 = ADD32(0, 0X1E);
            goto L_8079A638;
    }
    goto skip_2;
    // 0x8079A5E8: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    skip_2:
    // 0x8079A5EC: b           L_8079A650
    // 0x8079A5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A650;
    // 0x8079A5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A5F4:
    // 0x8079A5F4: slti        $at, $v0, 0x46B9
    ctx->r1 = SIGNED(ctx->r2) < 0X46B9 ? 1 : 0;
    // 0x8079A5F8: bne         $at, $zero, L_8079A614
    if (ctx->r1 != 0) {
        // 0x8079A5FC: addiu       $t6, $v0, -0x469B
        ctx->r14 = ADD32(ctx->r2, -0X469B);
            goto L_8079A614;
    }
    // 0x8079A5FC: addiu       $t6, $v0, -0x469B
    ctx->r14 = ADD32(ctx->r2, -0X469B);
    // 0x8079A600: addiu       $at, $zero, 0x46E1
    ctx->r1 = ADD32(0, 0X46E1);
    // 0x8079A604: beql        $v0, $at, L_8079A638
    if (ctx->r2 == ctx->r1) {
        // 0x8079A608: addiu       $t7, $zero, 0x1E
        ctx->r15 = ADD32(0, 0X1E);
            goto L_8079A638;
    }
    goto skip_3;
    // 0x8079A608: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    skip_3:
    // 0x8079A60C: b           L_8079A650
    // 0x8079A610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079A650;
    // 0x8079A610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A614:
    // 0x8079A614: sltiu       $at, $t6, 0x1E
    ctx->r1 = ctx->r14 < 0X1E ? 1 : 0;
    // 0x8079A618: beq         $at, $zero, L_8079A64C
    if (ctx->r1 == 0) {
        // 0x8079A61C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8079A64C;
    }
    // 0x8079A61C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8079A620: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(826, 0X26B0) << 16);
    // 0x8079A624: addu        $at, $at, $t6
    gpr jr_addend_8079A62C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8079A628: lw          $t6, -0x4E30($at)
    ctx->r14 = ADD32(ctx->r1, (int16_t)RELOC_LO16(826, 0X26B0));
    // 0x8079A62C: jr          $t6
    // 0x8079A630: nop

    switch (jr_addend_8079A62C >> 2) {
        case 0: goto L_8079A634; break;
        case 1: goto L_8079A64C; break;
        case 2: goto L_8079A64C; break;
        case 3: goto L_8079A64C; break;
        case 4: goto L_8079A64C; break;
        case 5: goto L_8079A64C; break;
        case 6: goto L_8079A64C; break;
        case 7: goto L_8079A64C; break;
        case 8: goto L_8079A64C; break;
        case 9: goto L_8079A64C; break;
        case 10: goto L_8079A64C; break;
        case 11: goto L_8079A64C; break;
        case 12: goto L_8079A64C; break;
        case 13: goto L_8079A64C; break;
        case 14: goto L_8079A64C; break;
        case 15: goto L_8079A64C; break;
        case 16: goto L_8079A64C; break;
        case 17: goto L_8079A64C; break;
        case 18: goto L_8079A64C; break;
        case 19: goto L_8079A64C; break;
        case 20: goto L_8079A64C; break;
        case 21: goto L_8079A64C; break;
        case 22: goto L_8079A64C; break;
        case 23: goto L_8079A64C; break;
        case 24: goto L_8079A64C; break;
        case 25: goto L_8079A634; break;
        case 26: goto L_8079A634; break;
        case 27: goto L_8079A634; break;
        case 28: goto L_8079A634; break;
        case 29: goto L_8079A634; break;
        default: switch_error(__func__, 0x8079A62C, 0x8079B1D0);
    }
    // 0x8079A630: nop

L_8079A634:
    // 0x8079A634: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
L_8079A638:
    // 0x8079A638: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x8079A63C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A640: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8079A644: jal         0x8079AEDC
    // 0x8079A648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_0;
    // 0x8079A648: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
L_8079A64C:
    // 0x8079A64C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079A650:
    // 0x8079A650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079A654: jr          $ra
    // 0x8079A658: nop

    return;
    // 0x8079A658: nop

;}
RECOMP_FUNC void func_8004393C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004393C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80043940: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80043944: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80043948: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8004394C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80043950: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80043954: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80043958: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004395C: lui         $s4, 0x800D
    ctx->r20 = S32(0X800D << 16);
    // 0x80043960: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80043964: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80043968: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8004396C: addiu       $s4, $s4, -0x7720
    ctx->r20 = ADD32(ctx->r20, -0X7720);
    // 0x80043970: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80043974: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80043978: addiu       $s5, $zero, 0x27C
    ctx->r21 = ADD32(0, 0X27C);
    // 0x8004397C: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x80043980: addiu       $s7, $zero, 0x64
    ctx->r23 = ADD32(0, 0X64);
L_80043984:
    // 0x80043984: lw          $t6, 0x10($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X10);
    // 0x80043988: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8004398C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80043990: bnel        $t8, $zero, L_800439BC
    if (ctx->r24 != 0) {
        // 0x80043994: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800439BC;
    }
    goto skip_0;
    // 0x80043994: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80043998: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004399C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800439A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800439A4: mflo        $t9
    ctx->r25 = lo;
    // 0x800439A8: addu        $s2, $s4, $t9
    ctx->r18 = ADD32(ctx->r20, ctx->r25);
    // 0x800439AC: jal         0x80057B28
    // 0x800439B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x800439B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_0:
    // 0x800439B4: sb          $s6, 0x6($s2)
    MEM_B(0X6, ctx->r18) = ctx->r22;
    // 0x800439B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800439BC:
    // 0x800439BC: bne         $s0, $s7, L_80043984
    if (ctx->r16 != ctx->r23) {
        // 0x800439C0: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80043984;
    }
    // 0x800439C0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800439C4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800439C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800439CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800439D0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800439D4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800439D8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800439DC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800439E0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800439E4: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800439E8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800439EC: jr          $ra
    // 0x800439F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800439F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_8004A6AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A6AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004A6B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A6B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A6B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8004A6BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A6C0: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x8004A6C4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8004A6C8: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8004A6CC: beql        $t7, $zero, L_8004A6E4
    if (ctx->r15 == 0) {
        // 0x8004A6D0: lw          $t8, 0x34($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X34);
            goto L_8004A6E4;
    }
    goto skip_0;
    // 0x8004A6D0: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
    skip_0:
    // 0x8004A6D4: jal         0x8004A0DC
    // 0x8004A6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004A0DC(rdram, ctx);
        goto after_0;
    // 0x8004A6D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8004A6DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004A6E0: lw          $t8, 0x34($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X34);
L_8004A6E4:
    // 0x8004A6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004A6E8: beql        $t8, $zero, L_8004A700
    if (ctx->r24 == 0) {
        // 0x8004A6EC: lw          $t9, 0x38($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X38);
            goto L_8004A700;
    }
    goto skip_1;
    // 0x8004A6EC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    skip_1:
    // 0x8004A6F0: jal         0x8004A0DC
    // 0x8004A6F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004A0DC(rdram, ctx);
        goto after_1;
    // 0x8004A6F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8004A6F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004A6FC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
L_8004A700:
    // 0x8004A700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8004A704: beql        $t9, $zero, L_8004A718
    if (ctx->r25 == 0) {
        // 0x8004A708: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_8004A718;
    }
    goto skip_2;
    // 0x8004A708: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8004A70C: jal         0x8004A0DC
    // 0x8004A710: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8004A0DC(rdram, ctx);
        goto after_2;
    // 0x8004A710: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8004A714: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8004A718:
    // 0x8004A718: beq         $t0, $zero, L_8004A728
    if (ctx->r8 == 0) {
        // 0x8004A71C: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_8004A728;
    }
    // 0x8004A71C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8004A720: jal         0x8004A090
    // 0x8004A724: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8004A090(rdram, ctx);
        goto after_3;
    // 0x8004A724: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_8004A728:
    // 0x8004A728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004A72C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004A730: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004A734: jr          $ra
    // 0x8004A738: nop

    return;
    // 0x8004A738: nop

;}
RECOMP_FUNC void func_8001CD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CD44: lw          $t6, 0x154($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X154);
    // 0x8001CD48: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001CD4C: sltiu       $at, $t7, 0x4
    ctx->r1 = ctx->r15 < 0X4 ? 1 : 0;
    // 0x8001CD50: bne         $at, $zero, L_8001CD78
    if (ctx->r1 != 0) {
        // 0x8001CD54: sw          $t7, 0x154($a0)
        MEM_W(0X154, ctx->r4) = ctx->r15;
            goto L_8001CD78;
    }
    // 0x8001CD54: sw          $t7, 0x154($a0)
    MEM_W(0X154, ctx->r4) = ctx->r15;
    // 0x8001CD58: lw          $t9, 0x14C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14C);
    // 0x8001CD5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001CD60: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x8001CD64: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x8001CD68: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8001CD6C: mfhi        $t1
    ctx->r9 = hi;
    // 0x8001CD70: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    // 0x8001CD74: nop

L_8001CD78:
    // 0x8001CD78: lbu         $t2, 0x30($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X30);
    // 0x8001CD7C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8001CD80: lw          $t5, 0x14C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X14C);
    // 0x8001CD84: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8001CD88: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8001CD8C: lh          $t4, -0x6960($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X6960);
    // 0x8001CD90: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001CD94: jr          $ra
    // 0x8001CD98: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    return;
    // 0x8001CD98: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void func_80408CBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80408CBC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80408CC0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80408CC4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80408CC8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80408CCC: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80408CD0: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80408CD4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80408CD8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80408CDC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80408CE0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80408CE4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80408CE8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80408CEC: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80408CF0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80408CF4: lui         $s1, 0x8041
    ctx->r17 = S32(RELOC_HI16(11, 0X2D00) << 16);
    // 0x80408CF8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80408CFC: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x80408D00: addiu       $s1, $s1, -0x5930
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(11, 0X2D00));
    // 0x80408D04: beq         $t6, $zero, L_80408F0C
    if (ctx->r14 == 0) {
        // 0x80408D08: addiu       $s5, $a1, 0xA00
        ctx->r21 = ADD32(ctx->r5, 0XA00);
            goto L_80408F0C;
    }
    // 0x80408D08: addiu       $s5, $a1, 0xA00
    ctx->r21 = ADD32(ctx->r5, 0XA00);
    // 0x80408D0C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80408D10: lw          $t0, 0x24($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X24);
    // 0x80408D14: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80408D18: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x80408D1C: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x80408D20: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80408D24: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80408D28: nop

    // 0x80408D2C: bgez        $v1, L_80408D3C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80408D30: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80408D3C;
    }
    // 0x80408D30: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80408D34: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80408D38: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80408D3C:
    // 0x80408D3C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80408D40: addu        $s0, $s5, $t9
    ctx->r16 = ADD32(ctx->r21, ctx->r25);
    // 0x80408D44: blez        $t1, L_80408E44
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80408D48: addiu       $s2, $s0, -0x4
        ctx->r18 = ADD32(ctx->r16, -0X4);
            goto L_80408E44;
    }
    // 0x80408D48: addiu       $s2, $s0, -0x4
    ctx->r18 = ADD32(ctx->r16, -0X4);
    // 0x80408D4C: bgez        $v1, L_80408D60
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80408D50: andi        $v0, $v1, 0x7
        ctx->r2 = ctx->r3 & 0X7;
            goto L_80408D60;
    }
    // 0x80408D50: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x80408D54: beq         $v0, $zero, L_80408D60
    if (ctx->r2 == 0) {
        // 0x80408D58: nop
    
            goto L_80408D60;
    }
    // 0x80408D58: nop

    // 0x80408D5C: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
L_80408D60:
    // 0x80408D60: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x80408D64: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x80408D68: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x80408D6C: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80408D70: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80408D74: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408D78: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80408D7C: sw          $v1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r3;
    // 0x80408D80: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
L_80408D84:
    // 0x80408D84: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80408D88: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80408D8C: jal         0x80065954
    // 0x80408D90: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80408D90: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    after_0:
    // 0x80408D94: div.s       $f12, $f0, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80408D98: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80408D9C: lwc1        $f14, 0x4($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80408DA0: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x80408DA4: addiu       $t4, $s6, 0xB40
    ctx->r12 = ADD32(ctx->r22, 0XB40);
    // 0x80408DA8: addiu       $t5, $s6, 0xB40
    ctx->r13 = ADD32(ctx->r22, 0XB40);
    // 0x80408DAC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80408DB0: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80408DB4: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80408DB8: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80408DBC: nop

    // 0x80408DC0: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80408DC4: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80408DC8: mul.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80408DCC: bne         $at, $zero, L_80408DF8
    if (ctx->r1 != 0) {
        // 0x80408DD0: nop
    
            goto L_80408DF8;
    }
    // 0x80408DD0: nop

    // 0x80408DD4: sltu        $at, $s0, $t4
    ctx->r1 = ctx->r16 < ctx->r12 ? 1 : 0;
    // 0x80408DD8: beql        $at, $zero, L_80408DFC
    if (ctx->r1 == 0) {
        // 0x80408DDC: sltu        $at, $s2, $s5
        ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
            goto L_80408DFC;
    }
    goto skip_0;
    // 0x80408DDC: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    skip_0:
    // 0x80408DE0: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80408DE4: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80408DE8: nop

    // 0x80408DEC: bc1fl       L_80408DFC
    if (!c1cs) {
        // 0x80408DF0: sltu        $at, $s2, $s5
        ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
            goto L_80408DFC;
    }
    goto skip_1;
    // 0x80408DF0: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    skip_1:
    // 0x80408DF4: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_80408DF8:
    // 0x80408DF8: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
L_80408DFC:
    // 0x80408DFC: bne         $at, $zero, L_80408E24
    if (ctx->r1 != 0) {
        // 0x80408E00: sltu        $at, $s2, $t5
        ctx->r1 = ctx->r18 < ctx->r13 ? 1 : 0;
            goto L_80408E24;
    }
    // 0x80408E00: sltu        $at, $s2, $t5
    ctx->r1 = ctx->r18 < ctx->r13 ? 1 : 0;
    // 0x80408E04: beql        $at, $zero, L_80408E28
    if (ctx->r1 == 0) {
        // 0x80408E08: lw          $t6, 0x24($s4)
        ctx->r14 = MEM_W(ctx->r20, 0X24);
            goto L_80408E28;
    }
    goto skip_2;
    // 0x80408E08: lw          $t6, 0x24($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X24);
    skip_2:
    // 0x80408E0C: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80408E10: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80408E14: nop

    // 0x80408E18: bc1fl       L_80408E28
    if (!c1cs) {
        // 0x80408E1C: lw          $t6, 0x24($s4)
        ctx->r14 = MEM_W(ctx->r20, 0X24);
            goto L_80408E28;
    }
    goto skip_3;
    // 0x80408E1C: lw          $t6, 0x24($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X24);
    skip_3:
    // 0x80408E20: swc1        $f18, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f18.u32l;
L_80408E24:
    // 0x80408E24: lw          $t6, 0x24($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X24);
L_80408E28:
    // 0x80408E28: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80408E2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80408E30: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80408E34: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80408E38: bne         $at, $zero, L_80408D84
    if (ctx->r1 != 0) {
        // 0x80408E3C: addiu       $s2, $s2, -0x4
        ctx->r18 = ADD32(ctx->r18, -0X4);
            goto L_80408D84;
    }
    // 0x80408E3C: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80408E40: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
L_80408E44:
    // 0x80408E44: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80408E48: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80408E4C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80408E50: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80408E54: bgez        $v1, L_80408E68
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80408E58: andi        $v0, $v1, 0x7
        ctx->r2 = ctx->r3 & 0X7;
            goto L_80408E68;
    }
    // 0x80408E58: andi        $v0, $v1, 0x7
    ctx->r2 = ctx->r3 & 0X7;
    // 0x80408E5C: beq         $v0, $zero, L_80408E68
    if (ctx->r2 == 0) {
        // 0x80408E60: nop
    
            goto L_80408E68;
    }
    // 0x80408E60: nop

    // 0x80408E64: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
L_80408E68:
    // 0x80408E68: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x80408E6C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80408E70: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80408E74: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80408E78: jal         0x80065954
    // 0x80408E7C: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80408E7C: cvt.s.w     $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    ctx->f22.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x80408E80: div.s       $f12, $f0, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x80408E84: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80408E88: lwc1        $f14, 0x4($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80408E8C: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x80408E90: addiu       $t0, $s6, 0xB40
    ctx->r8 = ADD32(ctx->r22, 0XB40);
    // 0x80408E94: addiu       $t1, $s6, 0xB40
    ctx->r9 = ADD32(ctx->r22, 0XB40);
    // 0x80408E98: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80408E9C: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80408EA0: mul.s       $f16, $f4, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80408EA4: nop

    // 0x80408EA8: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80408EAC: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80408EB0: mul.s       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80408EB4: bne         $at, $zero, L_80408EE0
    if (ctx->r1 != 0) {
        // 0x80408EB8: nop
    
            goto L_80408EE0;
    }
    // 0x80408EB8: nop

    // 0x80408EBC: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x80408EC0: beql        $at, $zero, L_80408EE4
    if (ctx->r1 == 0) {
        // 0x80408EC4: sltu        $at, $s2, $s5
        ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
            goto L_80408EE4;
    }
    goto skip_4;
    // 0x80408EC4: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    skip_4:
    // 0x80408EC8: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80408ECC: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x80408ED0: nop

    // 0x80408ED4: bc1fl       L_80408EE4
    if (!c1cs) {
        // 0x80408ED8: sltu        $at, $s2, $s5
        ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
            goto L_80408EE4;
    }
    goto skip_5;
    // 0x80408ED8: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
    skip_5:
    // 0x80408EDC: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_80408EE0:
    // 0x80408EE0: sltu        $at, $s2, $s5
    ctx->r1 = ctx->r18 < ctx->r21 ? 1 : 0;
L_80408EE4:
    // 0x80408EE4: bne         $at, $zero, L_80408F0C
    if (ctx->r1 != 0) {
        // 0x80408EE8: sltu        $at, $s2, $t1
        ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
            goto L_80408F0C;
    }
    // 0x80408EE8: sltu        $at, $s2, $t1
    ctx->r1 = ctx->r18 < ctx->r9 ? 1 : 0;
    // 0x80408EEC: beql        $at, $zero, L_80408F10
    if (ctx->r1 == 0) {
        // 0x80408EF0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80408F10;
    }
    goto skip_6;
    // 0x80408EF0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x80408EF4: lwc1        $f4, 0x0($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80408EF8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80408EFC: nop

    // 0x80408F00: bc1fl       L_80408F10
    if (!c1cs) {
        // 0x80408F04: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80408F10;
    }
    goto skip_7;
    // 0x80408F04: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_7:
    // 0x80408F08: swc1        $f18, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f18.u32l;
L_80408F0C:
    // 0x80408F0C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80408F10:
    // 0x80408F10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80408F14: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80408F18: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80408F1C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80408F20: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80408F24: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80408F28: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80408F2C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80408F30: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80408F34: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80408F38: jr          $ra
    // 0x80408F3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80408F3C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800276E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800276E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800276E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800276E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800276EC: jal         0x8001D770
    // 0x800276F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x800276F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x800276F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800276F8: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x800276FC: jal         0x80067BF8
    // 0x80027700: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80027700: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x80027704: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80027708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002770C: jal         0x80067838
    // 0x80027710: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x80027710: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80027714: lui         $t7, 0x8002
    ctx->r15 = S32(0X8002 << 16);
    // 0x80027718: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8002771C: addiu       $t7, $t7, 0x769C
    ctx->r15 = ADD32(ctx->r15, 0X769C);
    // 0x80027720: sw          $zero, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = 0;
    // 0x80027724: sw          $zero, 0x154($s0)
    MEM_W(0X154, ctx->r16) = 0;
    // 0x80027728: sb          $t6, 0x158($s0)
    MEM_B(0X158, ctx->r16) = ctx->r14;
    // 0x8002772C: sw          $t7, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r15;
    // 0x80027730: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80027734: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80027738: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002773C: jr          $ra
    // 0x80027740: nop

    return;
    // 0x80027740: nop

;}
RECOMP_FUNC void func_8005205C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005205C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052060: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052064: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80052068: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x8005206C: lw          $v1, 0x168($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X168);
    // 0x80052070: lw          $a3, 0x4C($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4C);
    // 0x80052074: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80052078: addiu       $a3, $a3, 0x1C
    ctx->r7 = ADD32(ctx->r7, 0X1C);
    // 0x8005207C: jal         0x80045520
    // 0x80052080: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_80045520(rdram, ctx);
        goto after_0;
    // 0x80052080: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80052084: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80052088: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8005208C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80052090: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x80052094: addiu       $v0, $v1, 0x58
    ctx->r2 = ADD32(ctx->r3, 0X58);
    // 0x80052098: addiu       $a1, $v1, 0x4C
    ctx->r5 = ADD32(ctx->r3, 0X4C);
    // 0x8005209C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800520A0: lbu         $t8, 0x1($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1);
    // 0x800520A4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x800520A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800520AC: jal         0x80051EE4
    // 0x800520B0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    func_80051EE4(rdram, ctx);
        goto after_1;
    // 0x800520B0: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_1:
    // 0x800520B4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800520B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800520BC: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x800520C0: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x800520C4: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x800520C8: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x800520CC: sw          $t2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r10;
    // 0x800520D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800520D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800520D8: jr          $ra
    // 0x800520DC: nop

    return;
    // 0x800520DC: nop

;}
RECOMP_FUNC void func_805D7E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7E28: jr          $ra
    // 0x805D7E2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805D7E2C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80455C48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455C48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80455C4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80455C50: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455C54: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455C58: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80455C5C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455C60: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455C64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455C68: jal         0x8044EFA0
    // 0x80455C6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455C6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455C70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455C74: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455C78: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80455C7C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455C80: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455C84: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D84) << 16);
    // 0x80455C88: lw          $t9, -0x7E9C($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D84));
    // 0x80455C8C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455C90: jalr        $t9
    // 0x80455C94: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455C94: nop

    after_1:
    // 0x80455C98: jal         0x804559B4
    // 0x80455C9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455C9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455CA0: jal         0x80445CBC
    // 0x80455CA4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455CA4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_3:
    // 0x80455CA8: jal         0x80445CC4
    // 0x80455CAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455CAC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455CB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455CB8: jr          $ra
    // 0x80455CBC: nop

    return;
    // 0x80455CBC: nop

;}
RECOMP_FUNC void func_804A1898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A1898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A189C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A18A0: jal         0x804A1820
    // 0x804A18A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A1820(rdram, ctx);
        goto after_0;
    // 0x804A18A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A18A8: bne         $v0, $zero, L_804A18D8
    if (ctx->r2 != 0) {
        // 0x804A18AC: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A18D8;
    }
    // 0x804A18AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A18B0: jal         0x804A2910
    // 0x804A18B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_1;
    // 0x804A18B4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x804A18B8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A18BC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804A18C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x804A18C4: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x804A18C8: bne         $at, $zero, L_804A18D8
    if (ctx->r1 != 0) {
        // 0x804A18CC: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804A18D8;
    }
    // 0x804A18CC: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804A18D0: jal         0x804A1604
    // 0x804A18D4: nop

    func_804A1604(rdram, ctx);
        goto after_2;
    // 0x804A18D4: nop

    after_2:
L_804A18D8:
    // 0x804A18D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A18DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A18E0: jr          $ra
    // 0x804A18E4: nop

    return;
    // 0x804A18E4: nop

;}
RECOMP_FUNC void func_8067E480(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E480: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E484: lwc1        $f4, 0x88($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8067E488: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8067E48C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8067E490: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067E494: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8067E498: nop

    // 0x8067E49C: bc1fl       L_8067E4E0
    if (!c1cs) {
        // 0x8067E4A0: lwc1        $f0, 0x4($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
            goto L_8067E4E0;
    }
    goto skip_0;
    // 0x8067E4A0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x8067E4A4: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x8067E4A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8067E4AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8067E4B0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8067E4B4: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8067E4B8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8067E4BC: nop

    // 0x8067E4C0: bc1f        L_8067E508
    if (!c1cs) {
        // 0x8067E4C4: nop
    
            goto L_8067E508;
    }
    // 0x8067E4C4: nop

    // 0x8067E4C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8067E4CC: nop

    // 0x8067E4D0: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8067E4D4: jr          $ra
    // 0x8067E4D8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    return;
    // 0x8067E4D8: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8067E4DC: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
L_8067E4E0:
    // 0x8067E4E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8067E4E4: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x8067E4E8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8067E4EC: nop

    // 0x8067E4F0: bc1f        L_8067E508
    if (!c1cs) {
        // 0x8067E4F4: nop
    
            goto L_8067E508;
    }
    // 0x8067E4F4: nop

    // 0x8067E4F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067E4FC: nop

    // 0x8067E500: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8067E504: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
L_8067E508:
    // 0x8067E508: jr          $ra
    // 0x8067E50C: nop

    return;
    // 0x8067E50C: nop

;}
RECOMP_FUNC void func_8004BDA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004BDA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004BDA8: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8004BDAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004BDB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004BDB4: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8004BDB8: lw          $a0, 0x174($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X174);
    // 0x8004BDBC: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8004BDC0: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8004BDC4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8004BDC8: subu        $t8, $t8, $a1
    ctx->r24 = SUB32(ctx->r24, ctx->r5);
    // 0x8004BDCC: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x8004BDD0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8004BDD4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8004BDD8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8004BDDC: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8004BDE0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004BDE4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8004BDE8: jal         0x80049864
    // 0x8004BDEC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    func_80049864(rdram, ctx);
        goto after_0;
    // 0x8004BDEC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004BDF0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x8004BDF4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8004BDF8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8004BDFC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8004BE00: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x8004BE04: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8004BE08: lw          $t2, 0x34($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X34);
    // 0x8004BE0C: lwc1        $f6, 0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X4);
    // 0x8004BE10: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004BE14: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8004BE18: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004BE1C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8004BE20: lhu         $t7, 0x0($t0)
    ctx->r15 = MEM_HU(ctx->r8, 0X0);
    // 0x8004BE24: add.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004BE28: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004BE2C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004BE30: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x8004BE34: trunc.w.s   $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    ctx->f18.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8004BE38: sh          $t4, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r12;
    // 0x8004BE3C: lh          $t5, 0x48($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X48);
    // 0x8004BE40: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8004BE44: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8004BE48: sh          $t7, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r15;
    // 0x8004BE4C: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8004BE50: andi        $t3, $t2, 0xF
    ctx->r11 = ctx->r10 & 0XF;
    // 0x8004BE54: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8004BE58: sh          $t3, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r11;
    // 0x8004BE5C: sh          $t7, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r15;
    // 0x8004BE60: lbu         $v1, 0x1($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X1);
    // 0x8004BE64: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8004BE68: sll         $t7, $t3, 16
    ctx->r15 = S32(ctx->r11 << 16);
    // 0x8004BE6C: srl         $t8, $v1, 6
    ctx->r24 = S32(U32(ctx->r3) >> 6);
    // 0x8004BE70: andi        $t1, $v1, 0x3F
    ctx->r9 = ctx->r3 & 0X3F;
    // 0x8004BE74: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8004BE78: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8004BE7C: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x8004BE80: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x8004BE84: lw          $t6, 0xA24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XA24);
    // 0x8004BE88: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8004BE8C: sll         $t1, $t8, 1
    ctx->r9 = S32(ctx->r24 << 1);
    // 0x8004BE90: addu        $t9, $t6, $t1
    ctx->r25 = ADD32(ctx->r14, ctx->r9);
    // 0x8004BE94: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8004BE98: addiu       $t4, $t0, 0xC
    ctx->r12 = ADD32(ctx->r8, 0XC);
    // 0x8004BE9C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004BEA0: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8004BEA4: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
    // 0x8004BEA8: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8004BEAC: sh          $t2, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r10;
    // 0x8004BEB0: lbu         $t8, 0x1($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1);
    // 0x8004BEB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004BEB8: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8004BEBC: andi        $t6, $t8, 0x3F
    ctx->r14 = ctx->r24 & 0X3F;
    // 0x8004BEC0: xori        $t1, $t6, 0x4
    ctx->r9 = ctx->r14 ^ 0X4;
    // 0x8004BEC4: sltu        $t1, $zero, $t1
    ctx->r9 = 0 < ctx->r9 ? 1 : 0;
    // 0x8004BEC8: andi        $t7, $t3, 0x1
    ctx->r15 = ctx->r11 & 0X1;
    // 0x8004BECC: and         $t9, $t7, $t1
    ctx->r25 = ctx->r15 & ctx->r9;
    // 0x8004BED0: beq         $t9, $zero, L_8004BF54
    if (ctx->r25 == 0) {
        // 0x8004BED4: sub.s       $f12, $f0, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
            goto L_8004BF54;
    }
    // 0x8004BED4: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8004BED8: sllv        $t4, $t2, $t5
    ctx->r12 = S32(ctx->r10 << (ctx->r13 & 31));
    // 0x8004BEDC: andi        $t3, $t4, 0x8000
    ctx->r11 = ctx->r12 & 0X8000;
    // 0x8004BEE0: beq         $t3, $zero, L_8004BF54
    if (ctx->r11 == 0) {
        // 0x8004BEE4: lhu         $t8, 0x38($sp)
        ctx->r24 = MEM_HU(ctx->r29, 0X38);
            goto L_8004BF54;
    }
    // 0x8004BEE4: lhu         $t8, 0x38($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X38);
    // 0x8004BEE8: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x8004BEEC: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8004BEF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8004BEF4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8004BEF8: jal         0x8004BBD4
    // 0x8004BEFC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_8004BBD4(rdram, ctx);
        goto after_1;
    // 0x8004BEFC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8004BF00: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x8004BF04: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8004BF08: bne         $at, $zero, L_8004BF3C
    if (ctx->r1 != 0) {
        // 0x8004BF0C: lwc1        $f12, 0x24($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8004BF3C;
    }
    // 0x8004BF0C: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004BF10: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8004BF14: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x8004BF18: lhu         $t1, 0x22($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X22);
    // 0x8004BF1C: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8004BF20: lwc1        $f6, 0x84($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X84);
    // 0x8004BF24: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004BF28: sh          $t1, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r9;
    // 0x8004BF2C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8004BF30: lwc1        $f8, 0x8C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8C0);
    // 0x8004BF34: b           L_8004BF5C
    // 0x8004BF38: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
        goto L_8004BF5C;
    // 0x8004BF38: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_8004BF3C:
    // 0x8004BF3C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8004BF40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004BF44: sb          $t9, 0x14($t0)
    MEM_B(0X14, ctx->r8) = ctx->r25;
    // 0x8004BF48: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8004BF4C: b           L_8004BF5C
    // 0x8004BF50: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
        goto L_8004BF5C;
    // 0x8004BF50: sub.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f12.fl;
L_8004BF54:
    // 0x8004BF54: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004BF58: nop

L_8004BF5C:
    // 0x8004BF5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004BF60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8004BF64: jr          $ra
    // 0x8004BF68: nop

    return;
    // 0x8004BF68: nop

;}
RECOMP_FUNC void func_80580DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580DF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80580DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80580E00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80580E04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80580E08: jal         0x8057EF14
    // 0x80580E0C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    func_8057EF14(rdram, ctx);
        goto after_0;
    // 0x80580E0C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    after_0:
    // 0x80580E10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80580E14: jal         0x80580C70
    // 0x80580E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80580C70(rdram, ctx);
        goto after_1;
    // 0x80580E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80580E1C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80580E20: beql        $t6, $zero, L_80580E94
    if (ctx->r14 == 0) {
        // 0x80580E24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80580E94;
    }
    goto skip_0;
    // 0x80580E24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80580E28: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x80580E2C: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80580E30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80580E34: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80580E38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80580E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80580E40: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80580E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80580E48: bc1f        L_80580E88
    if (!c1cs) {
        // 0x80580E4C: nop
    
            goto L_80580E88;
    }
    // 0x80580E4C: nop

    // 0x80580E50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80580E54: nop

    // 0x80580E58: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80580E5C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80580E60: jal         0x80580CE8
    // 0x80580E64: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    func_80580CE8(rdram, ctx);
        goto after_2;
    // 0x80580E64: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x80580E68: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80580E6C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80580E70: subu        $v1, $t7, $v0
    ctx->r3 = SUB32(ctx->r15, ctx->r2);
    // 0x80580E74: sb          $v1, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r3;
    // 0x80580E78: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80580E7C: lw          $t0, 0x16C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X16C);
    // 0x80580E80: b           L_80580E90
    // 0x80580E84: sb          $v1, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r3;
        goto L_80580E90;
    // 0x80580E84: sb          $v1, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r3;
L_80580E88:
    // 0x80580E88: jal         0x80580F6C
    // 0x80580E8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80580F6C(rdram, ctx);
        goto after_3;
    // 0x80580E8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
L_80580E90:
    // 0x80580E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80580E94:
    // 0x80580E94: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80580E98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80580E9C: jr          $ra
    // 0x80580EA0: nop

    return;
    // 0x80580EA0: nop

;}
