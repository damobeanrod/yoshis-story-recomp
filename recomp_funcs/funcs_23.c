#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_804303F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804303F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804303F4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804303F8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804303FC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x80430400: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80430404: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80430408: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8043040C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80430410: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80430414: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80430418: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8043041C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80430420: lui         $t2, 0x8043
    ctx->r10 = S32(RELOC_HI16(56, 0X3830) << 16);
    // 0x80430424: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80430428: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8043042C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x80430430: lw          $t2, 0x1910($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(56, 0X3830));
    // 0x80430434: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80430438: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8043043C: jal         0x8042F5E0
    // 0x80430440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042F5E0(rdram, ctx);
        goto after_0;
    // 0x80430440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80430444: jal         0x8042F63C
    // 0x80430448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042F63C(rdram, ctx);
        goto after_1;
    // 0x80430448: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8043044C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80430450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80430454: jr          $ra
    // 0x80430458: nop

    return;
    // 0x80430458: nop

;}
RECOMP_FUNC void func_804E9BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E9BE0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804E9BE4: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804E9BE8: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(264, 0X7F0) << 16);
    // 0x804E9BEC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804E9BF0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804E9BF4: lw          $t8, -0x5EA0($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(264, 0X7F0));
    // 0x804E9BF8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804E9BFC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804E9C00: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804E9C04: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804E9C08: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804E9C0C: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804E9C10: beql        $v1, $zero, L_804E9C44
    if (ctx->r3 == 0) {
        // 0x804E9C14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804E9C44;
    }
    goto skip_0;
    // 0x804E9C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804E9C18: jalr        $v1
    // 0x804E9C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804E9C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804E9C20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804E9C24: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804E9C28: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804E9C2C: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804E9C30: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804E9C34: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804E9C38: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804E9C3C: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804E9C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E9C44:
    // 0x804E9C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804E9C48: jr          $ra
    // 0x804E9C4C: nop

    return;
    // 0x804E9C4C: nop

;}
RECOMP_FUNC void func_80436148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80436148: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8043614C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80436150: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80436154: jal         0x80045A34
    // 0x80436158: addiu       $a1, $zero, 0x1350
    ctx->r5 = ADD32(0, 0X1350);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80436158: addiu       $a1, $zero, 0x1350
    ctx->r5 = ADD32(0, 0X1350);
    after_0:
    // 0x8043615C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80436160: beq         $v0, $zero, L_80436178
    if (ctx->r2 == 0) {
        // 0x80436164: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_80436178;
    }
    // 0x80436164: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80436168: jal         0x804360A0
    // 0x8043616C: nop

    func_804360A0(rdram, ctx);
        goto after_1;
    // 0x8043616C: nop

    after_1:
    // 0x80436170: jal         0x80436044
    // 0x80436174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80436044(rdram, ctx);
        goto after_2;
    // 0x80436174: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80436178:
    // 0x80436178: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043617C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80436180: jr          $ra
    // 0x80436184: nop

    return;
    // 0x80436184: nop

;}
RECOMP_FUNC void func_8064E16C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E16C: lw          $v0, 0x14($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X14);
    // 0x8064E170: beq         $v0, $zero, L_8064E180
    if (ctx->r2 == 0) {
        // 0x8064E174: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8064E180;
    }
    // 0x8064E174: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8064E178: jr          $ra
    // 0x8064E17C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    return;
    // 0x8064E17C: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
L_8064E180:
    // 0x8064E180: lw          $t7, 0x18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X18);
    // 0x8064E184: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8064E188: sw          $t8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r24;
    // 0x8064E18C: jr          $ra
    // 0x8064E190: nop

    return;
    // 0x8064E190: nop

;}
RECOMP_FUNC void func_80068470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068470: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x80068474: addiu       $a3, $a3, 0x7EA0
    ctx->r7 = ADD32(ctx->r7, 0X7EA0);
    // 0x80068478: lh          $a2, 0x28($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X28);
    // 0x8006847C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068480: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068484: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x80068488: bne         $at, $zero, L_80068498
    if (ctx->r1 != 0) {
        // 0x8006848C: nop
    
            goto L_80068498;
    }
    // 0x8006848C: nop

    // 0x80068490: b           L_800684D8
    // 0x80068494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800684D8;
    // 0x80068494: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80068498:
    // 0x80068498: bne         $a0, $zero, L_800684B8
    if (ctx->r4 != 0) {
        // 0x8006849C: sll         $t6, $a2, 3
        ctx->r14 = S32(ctx->r6 << 3);
            goto L_800684B8;
    }
    // 0x8006849C: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x800684A0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800684A4: addiu       $a0, $a0, 0xE18
    ctx->r4 = ADD32(ctx->r4, 0XE18);
    // 0x800684A8: jal         0x80071380
    // 0x800684AC: addiu       $a1, $zero, 0x1A8
    ctx->r5 = ADD32(0, 0X1A8);
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800684AC: addiu       $a1, $zero, 0x1A8
    ctx->r5 = ADD32(0, 0X1A8);
    after_0:
    // 0x800684B0: b           L_800684D8
    // 0x800684B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800684D8;
    // 0x800684B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800684B8:
    // 0x800684B8: addu        $v1, $a3, $t6
    ctx->r3 = ADD32(ctx->r7, ctx->r14);
    // 0x800684BC: sw          $a0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r4;
    // 0x800684C0: sw          $a1, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r5;
    // 0x800684C4: lh          $t7, 0x28($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X28);
    // 0x800684C8: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x800684CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800684D0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800684D4: sh          $t8, 0x28($a3)
    MEM_H(0X28, ctx->r7) = ctx->r24;
L_800684D8:
    // 0x800684D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800684DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800684E0: jr          $ra
    // 0x800684E4: nop

    return;
    // 0x800684E4: nop

;}
RECOMP_FUNC void func_80519A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80519A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80519A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80519A78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80519A7C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80519A80: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80519A84: lw          $v1, 0x204($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X204);
    // 0x80519A88: beq         $v1, $zero, L_80519A94
    if (ctx->r3 == 0) {
        // 0x80519A8C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80519A94;
    }
    // 0x80519A8C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80519A90: sw          $t6, 0x204($v0)
    MEM_W(0X204, ctx->r2) = ctx->r14;
L_80519A94:
    // 0x80519A94: jal         0x805198F8
    // 0x80519A98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_805198F8(rdram, ctx);
        goto after_0;
    // 0x80519A98: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80519A9C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80519AA0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80519AA4: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80519AA8: lwc1        $f6, 0xC4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC4);
    // 0x80519AAC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80519AB0: nop

    // 0x80519AB4: bc1fl       L_80519AC4
    if (!c1cs) {
        // 0x80519AB8: lw          $t8, 0x174($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X174);
            goto L_80519AC4;
    }
    goto skip_0;
    // 0x80519AB8: lw          $t8, 0x174($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X174);
    skip_0:
    // 0x80519ABC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80519AC0: lw          $t8, 0x174($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X174);
L_80519AC4:
    // 0x80519AC4: sw          $t7, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r15;
    // 0x80519AC8: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80519ACC: beql        $t9, $zero, L_80519AF0
    if (ctx->r25 == 0) {
        // 0x80519AD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80519AF0;
    }
    goto skip_1;
    // 0x80519AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80519AD4: lw          $a0, 0x34($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X34);
    // 0x80519AD8: jal         0x80067BBC
    // 0x80519ADC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_1;
    // 0x80519ADC: lw          $a1, 0x38($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x80519AE0: addiu       $a0, $zero, 0xB0
    ctx->r4 = ADD32(0, 0XB0);
    // 0x80519AE4: jal         0x80067818
    // 0x80519AE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80519AE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80519AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80519AF0:
    // 0x80519AF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80519AF4: jr          $ra
    // 0x80519AF8: nop

    return;
    // 0x80519AF8: nop

;}
RECOMP_FUNC void func_804559F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804559F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804559F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804559F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804559FC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455A00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80455A04: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455A08: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455A0C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80455A10: jal         0x8044EFA0
    // 0x80455A14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455A14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455A18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80455A1C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455A20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80455A24: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455A28: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455A2C: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D48) << 16);
    // 0x80455A30: lw          $t9, -0x7ED8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D48));
    // 0x80455A34: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80455A38: jalr        $t9
    // 0x80455A3C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80455A3C: nop

    after_1:
    // 0x80455A40: jal         0x804559B4
    // 0x80455A44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_804559B4(rdram, ctx);
        goto after_2;
    // 0x80455A44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80455A48: jal         0x80445CBC
    // 0x80455A4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80445CBC(rdram, ctx);
        goto after_3;
    // 0x80455A4C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80455A50: jal         0x80445CC4
    // 0x80455A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445CC4(rdram, ctx);
        goto after_4;
    // 0x80455A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80455A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80455A5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80455A60: jr          $ra
    // 0x80455A64: nop

    return;
    // 0x80455A64: nop

;}
RECOMP_FUNC void func_806775C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806775C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806775C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806775CC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806775D0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806775D4: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(535, 0X2530) << 16);
    // 0x806775D8: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806775DC: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806775E0: addiu       $t7, $t7, 0x7BF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(535, 0X2530));
    // 0x806775E4: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806775E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806775EC: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806775F0: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806775F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x806775F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806775FC: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80677600: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80677604: jal         0x80048378
    // 0x80677608: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    func_80048378(rdram, ctx);
        goto after_0;
    // 0x80677608: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    after_0:
    // 0x8067760C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80677610: jal         0x80045A34
    // 0x80677614: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_80045A34(rdram, ctx);
        goto after_1;
    // 0x80677614: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_1:
    // 0x80677618: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067761C: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x80677620: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80677624: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80677628: jal         0x806775AC
    // 0x8067762C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    func_806775AC(rdram, ctx);
        goto after_2;
    // 0x8067762C: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    after_2:
    // 0x80677630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80677634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80677638: jr          $ra
    // 0x8067763C: nop

    return;
    // 0x8067763C: nop

;}
RECOMP_FUNC void func_806CB7EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CB7EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806CB7F0: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    // 0x806CB7F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806CB7F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x806CB7FC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x806CB800: bne         $a1, $at, L_806CB838
    if (ctx->r5 != ctx->r1) {
        // 0x806CB804: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_806CB838;
    }
    // 0x806CB804: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x806CB808: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x806CB80C: addiu       $t8, $zero, 0x1F4
    ctx->r24 = ADD32(0, 0X1F4);
    // 0x806CB810: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3BFC) << 16);
    // 0x806CB814: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x806CB818: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x806CB81C: lwc1        $f8, -0xCE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3BFC));
    // 0x806CB820: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x806CB824: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806CB828: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CB82C: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x806CB830: nop

    // 0x806CB834: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
L_806CB838:
    // 0x806CB838: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x806CB83C: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    // 0x806CB840: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x806CB844: jal         0x80067D5C
    // 0x806CB848: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x806CB848: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_0:
    // 0x806CB84C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806CB850: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806CB854: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806CB858: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    // 0x806CB85C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806CB860: bnel        $a1, $at, L_806CB888
    if (ctx->r5 != ctx->r1) {
        // 0x806CB864: sw          $a2, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r6;
            goto L_806CB888;
    }
    goto skip_0;
    // 0x806CB864: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    skip_0:
    // 0x806CB868: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806CB86C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806CB870: jal         0x80067F78
    // 0x806CB874: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x806CB874: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x806CB878: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806CB87C: b           L_806CB8AC
    // 0x806CB880: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
        goto L_806CB8AC;
    // 0x806CB880: sh          $v0, 0x1F0($a3)
    MEM_H(0X1F0, ctx->r7) = ctx->r2;
    // 0x806CB884: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
L_806CB888:
    // 0x806CB888: jal         0x80067930
    // 0x806CB88C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    func_80067930(rdram, ctx);
        goto after_2;
    // 0x806CB88C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_2:
    // 0x806CB890: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806CB894: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x806CB898: bne         $v0, $at, L_806CB8AC
    if (ctx->r2 != ctx->r1) {
        // 0x806CB89C: lw          $a3, 0x28($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X28);
            goto L_806CB8AC;
    }
    // 0x806CB89C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x806CB8A0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x806CB8A4: jal         0x800678F0
    // 0x806CB8A8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x806CB8A8: lh          $a1, 0x1F0($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X1F0);
    after_3:
L_806CB8AC:
    // 0x806CB8AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806CB8B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806CB8B4: jr          $ra
    // 0x806CB8B8: nop

    return;
    // 0x806CB8B8: nop

;}
RECOMP_FUNC void func_807C3B5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C3B5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x807C3B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807C3B64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807C3B68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807C3B6C: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C3B70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807C3B74: addiu       $a1, $s1, 0x6C
    ctx->r5 = ADD32(ctx->r17, 0X6C);
    // 0x807C3B78: jal         0x807C38CC
    // 0x807C3B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807C38CC(rdram, ctx);
        goto after_0;
    // 0x807C3B7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x807C3B80: jal         0x807C3A3C
    // 0x807C3B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807C3A3C(rdram, ctx);
        goto after_1;
    // 0x807C3B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807C3B88: lw          $v0, 0x1E4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1E4);
    // 0x807C3B8C: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x807C3B90: beq         $v0, $zero, L_807C3BA0
    if (ctx->r2 == 0) {
        // 0x807C3B94: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_807C3BA0;
    }
    // 0x807C3B94: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x807C3B98: b           L_807C3BF0
    // 0x807C3B9C: sw          $t6, 0x1E4($s1)
    MEM_W(0X1E4, ctx->r17) = ctx->r14;
        goto L_807C3BF0;
    // 0x807C3B9C: sw          $t6, 0x1E4($s1)
    MEM_W(0X1E4, ctx->r17) = ctx->r14;
L_807C3BA0:
    // 0x807C3BA0: lw          $t7, 0x7EA8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7EA8);
    // 0x807C3BA4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x807C3BA8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807C3BAC: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x807C3BB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C3BB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807C3BB8: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x807C3BBC: beq         $t8, $at, L_807C3BDC
    if (ctx->r24 == ctx->r1) {
        // 0x807C3BC0: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_807C3BDC;
    }
    // 0x807C3BC0: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x807C3BC4: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x807C3BC8: beq         $t9, $at, L_807C3BDC
    if (ctx->r25 == ctx->r1) {
        // 0x807C3BCC: andi        $t0, $v0, 0x1000
        ctx->r8 = ctx->r2 & 0X1000;
            goto L_807C3BDC;
    }
    // 0x807C3BCC: andi        $t0, $v0, 0x1000
    ctx->r8 = ctx->r2 & 0X1000;
    // 0x807C3BD0: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x807C3BD4: bnel        $t0, $at, L_807C3BF4
    if (ctx->r8 != ctx->r1) {
        // 0x807C3BD8: lw          $t1, 0x18($s0)
        ctx->r9 = MEM_W(ctx->r16, 0X18);
            goto L_807C3BF4;
    }
    goto skip_0;
    // 0x807C3BD8: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    skip_0:
L_807C3BDC:
    // 0x807C3BDC: sw          $zero, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = 0;
    // 0x807C3BE0: jal         0x807C3EC0
    // 0x807C3BE4: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    func_807C3EC0(rdram, ctx);
        goto after_2;
    // 0x807C3BE4: sw          $zero, 0x130($s1)
    MEM_W(0X130, ctx->r17) = 0;
    after_2:
    // 0x807C3BE8: b           L_807C3D88
    // 0x807C3BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807C3D88;
    // 0x807C3BEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C3BF0:
    // 0x807C3BF0: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
L_807C3BF4:
    // 0x807C3BF4: slti        $at, $t1, 0x4
    ctx->r1 = SIGNED(ctx->r9) < 0X4 ? 1 : 0;
    // 0x807C3BF8: bnel        $at, $zero, L_807C3C14
    if (ctx->r1 != 0) {
        // 0x807C3BFC: lw          $v0, 0x14($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X14);
            goto L_807C3C14;
    }
    goto skip_1;
    // 0x807C3BFC: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x807C3C00: jal         0x807C3A94
    // 0x807C3C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_807C3A94(rdram, ctx);
        goto after_3;
    // 0x807C3C04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x807C3C08: bnel        $v0, $zero, L_807C3D88
    if (ctx->r2 != 0) {
        // 0x807C3C0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807C3D88;
    }
    goto skip_2;
    // 0x807C3C0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x807C3C10: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_807C3C14:
    // 0x807C3C14: addiu       $a0, $s1, 0xC4
    ctx->r4 = ADD32(ctx->r17, 0XC4);
    // 0x807C3C18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807C3C1C: beq         $v0, $zero, L_807C3C54
    if (ctx->r2 == 0) {
        // 0x807C3C20: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_807C3C54;
    }
    // 0x807C3C20: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x807C3C24: bne         $t2, $zero, L_807C3D84
    if (ctx->r10 != 0) {
        // 0x807C3C28: sw          $t2, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r10;
            goto L_807C3D84;
    }
    // 0x807C3C28: sw          $t2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r10;
    // 0x807C3C2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C3C30: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x807C3C34: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x807C3C38: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x807C3C3C: lui         $t4, 0x807C
    ctx->r12 = S32(RELOC_HI16(907, 0X1414) << 16);
    // 0x807C3C40: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x807C3C44: lw          $t4, 0x4774($t4)
    ctx->r12 = MEM_W(ctx->r12, (int16_t)RELOC_LO16(907, 0X1414));
    // 0x807C3C48: sw          $t4, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r12;
    // 0x807C3C4C: b           L_807C3D84
    // 0x807C3C50: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
        goto L_807C3D84;
    // 0x807C3C50: sb          $zero, 0x20($s0)
    MEM_B(0X20, ctx->r16) = 0;
L_807C3C54:
    // 0x807C3C54: jal         0x80048F84
    // 0x807C3C58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x807C3C58: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x807C3C5C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x807C3C60: jal         0x80048F84
    // 0x807C3C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x807C3C64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x807C3C68: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(907, 0X14B4) << 16);
    // 0x807C3C6C: lwc1        $f2, 0x4814($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(907, 0X14B4));
    // 0x807C3C70: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(907, 0X14B8) << 16);
    // 0x807C3C74: lwc1        $f6, 0x4818($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(907, 0X14B8));
    // 0x807C3C78: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x807C3C7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C3C80: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x807C3C84: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x807C3C88: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x807C3C8C: nop

    // 0x807C3C90: bc1fl       L_807C3CA4
    if (!c1cs) {
        // 0x807C3C94: lwc1        $f2, 0x6C($s1)
        ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
            goto L_807C3CA4;
    }
    goto skip_3;
    // 0x807C3C94: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
    skip_3:
    // 0x807C3C98: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x807C3C9C: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x807C3CA0: lwc1        $f2, 0x6C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X6C);
L_807C3CA4:
    // 0x807C3CA4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807C3CA8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x807C3CAC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x807C3CB0: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x807C3CB4: nop

    // 0x807C3CB8: bc1fl       L_807C3CC8
    if (!c1cs) {
        // 0x807C3CBC: lwc1        $f12, 0x50($s1)
        ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
            goto L_807C3CC8;
    }
    goto skip_4;
    // 0x807C3CBC: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
    skip_4:
    // 0x807C3CC0: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x807C3CC4: lwc1        $f12, 0x50($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X50);
L_807C3CC8:
    // 0x807C3CC8: swc1        $f2, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f2.u32l;
    // 0x807C3CCC: swc1        $f2, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f2.u32l;
    // 0x807C3CD0: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x807C3CD4: jal         0x80066DE4
    // 0x807C3CD8: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    func_80066DE4(rdram, ctx);
        goto after_6;
    // 0x807C3CD8: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x807C3CDC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807C3CE0: jal         0x80066E88
    // 0x807C3CE4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_7;
    // 0x807C3CE4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x807C3CE8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807C3CEC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x807C3CF0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x807C3CF4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x807C3CF8: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807C3CFC: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x807C3D00: lw          $v0, 0x1E0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1E0);
    // 0x807C3D04: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807C3D08: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x807C3D0C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x807C3D10: nop

    // 0x807C3D14: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x807C3D18: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    // 0x807C3D1C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x807C3D20: beq         $v0, $zero, L_807C3D30
    if (ctx->r2 == 0) {
        // 0x807C3D24: swc1        $f8, 0xC8($s1)
        MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
            goto L_807C3D30;
    }
    // 0x807C3D24: swc1        $f8, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f8.u32l;
    // 0x807C3D28: b           L_807C3D68
    // 0x807C3D2C: sw          $t5, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r13;
        goto L_807C3D68;
    // 0x807C3D2C: sw          $t5, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r13;
L_807C3D30:
    // 0x807C3D30: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x807C3D34: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x807C3D38: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x807C3D3C: beq         $at, $zero, L_807C3D4C
    if (ctx->r1 == 0) {
        // 0x807C3D40: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_807C3D4C;
    }
    // 0x807C3D40: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x807C3D44: b           L_807C3D50
    // 0x807C3D48: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
        goto L_807C3D50;
    // 0x807C3D48: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
L_807C3D4C:
    // 0x807C3D4C: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_807C3D50:
    // 0x807C3D50: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x807C3D54: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(907, 0X1414) << 16);
    // 0x807C3D58: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x807C3D5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807C3D60: lw          $t9, 0x4774($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(907, 0X1414));
    // 0x807C3D64: sw          $t9, 0x1E0($s1)
    MEM_W(0X1E0, ctx->r17) = ctx->r25;
L_807C3D68:
    // 0x807C3D68: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x807C3D6C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(907, 0X1400) << 16);
    // 0x807C3D70: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x807C3D74: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x807C3D78: lwc1        $f10, 0x4760($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(907, 0X1400));
    // 0x807C3D7C: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807C3D80: swc1        $f12, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f12.u32l;
L_807C3D84:
    // 0x807C3D84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807C3D88:
    // 0x807C3D88: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x807C3D8C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x807C3D90: jr          $ra
    // 0x807C3D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x807C3D94: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_8057ABF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057ABF4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8057ABF8: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8057ABFC: lbu         $t6, -0x7204($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X7204);
    // 0x8057AC00: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8057AC04: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8057AC08: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8057AC0C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8057AC10: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8057AC14: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8057AC18: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8057AC1C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8057AC20: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8057AC24: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8057AC28: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8057AC2C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8057AC30: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8057AC34: sb          $t6, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r14;
    // 0x8057AC38: lw          $v0, 0x16C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X16C);
    // 0x8057AC3C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8057AC40: lw          $s5, 0x1F4($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057AC44: lbu         $t7, 0x34($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X34);
    // 0x8057AC48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8057AC4C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8057AC50: jal         0x8057A6CC
    // 0x8057AC54: lw          $s3, 0x38($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X38);
    func_8057A6CC(rdram, ctx);
        goto after_0;
    // 0x8057AC54: lw          $s3, 0x38($t9)
    ctx->r19 = MEM_W(ctx->r25, 0X38);
    after_0:
    // 0x8057AC58: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8057AC5C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8057AC60: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B74) << 16);
    // 0x8057AC64: lwc1        $f26, -0x4A4C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B74));
    // 0x8057AC68: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B78) << 16);
    // 0x8057AC6C: lwc1        $f24, -0x4A48($at)
    ctx->f24.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B78));
    // 0x8057AC70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8057AC74: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8057AC78: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x8057AC7C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8057AC80: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8057AC84: or          $s0, $s5, $zero
    ctx->r16 = ctx->r21 | 0;
L_8057AC88:
    // 0x8057AC88: lwc1        $f0, 0x228($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X228);
    // 0x8057AC8C: lwc1        $f4, 0x2A0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2A0);
    // 0x8057AC90: addiu       $s1, $s2, 0x1
    ctx->r17 = ADD32(ctx->r18, 0X1);
    // 0x8057AC94: c.eq.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl == ctx->f0.fl;
    // 0x8057AC98: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8057AC9C: bc1t        L_8057AD28
    if (c1cs) {
        // 0x8057ACA0: swc1        $f6, 0x2A0($s0)
        MEM_W(0X2A0, ctx->r16) = ctx->f6.u32l;
            goto L_8057AD28;
    }
    // 0x8057ACA0: swc1        $f6, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->f6.u32l;
    // 0x8057ACA4: lwc1        $f8, 0x2A0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2A0);
    // 0x8057ACA8: c.le.s      $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f8.fl <= ctx->f24.fl;
    // 0x8057ACAC: nop

    // 0x8057ACB0: bc1f        L_8057AD28
    if (!c1cs) {
        // 0x8057ACB4: nop
    
            goto L_8057AD28;
    }
    // 0x8057ACB4: nop

    // 0x8057ACB8: lw          $t0, 0x1E0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1E0);
    // 0x8057ACBC: addiu       $v0, $s2, 0x1
    ctx->r2 = ADD32(ctx->r18, 0X1);
    // 0x8057ACC0: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8057ACC4: beq         $at, $zero, L_8057AD0C
    if (ctx->r1 == 0) {
        // 0x8057ACC8: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_8057AD0C;
    }
    // 0x8057ACC8: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8057ACCC: bnel        $at, $zero, L_8057ACDC
    if (ctx->r1 != 0) {
        // 0x8057ACD0: sll         $t1, $v0, 2
        ctx->r9 = S32(ctx->r2 << 2);
            goto L_8057ACDC;
    }
    goto skip_0;
    // 0x8057ACD0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    skip_0:
    // 0x8057ACD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8057ACD8: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
L_8057ACDC:
    // 0x8057ACDC: addu        $v1, $s5, $t1
    ctx->r3 = ADD32(ctx->r21, ctx->r9);
    // 0x8057ACE0: lwc1        $f10, 0x228($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X228);
    // 0x8057ACE4: c.eq.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl == ctx->f10.fl;
    // 0x8057ACE8: nop

    // 0x8057ACEC: bc1fl       L_8057AD10
    if (!c1cs) {
        // 0x8057ACF0: lwc1        $f16, 0x2A0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2A0);
            goto L_8057AD10;
    }
    goto skip_1;
    // 0x8057ACF0: lwc1        $f16, 0x2A0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2A0);
    skip_1:
    // 0x8057ACF4: swc1        $f26, 0x228($v1)
    MEM_W(0X228, ctx->r3) = ctx->f26.u32l;
    // 0x8057ACF8: bne         $v0, $zero, L_8057AD0C
    if (ctx->r2 != 0) {
        // 0x8057ACFC: swc1        $f28, 0x2A0($v1)
        MEM_W(0X2A0, ctx->r3) = ctx->f28.u32l;
            goto L_8057AD0C;
    }
    // 0x8057ACFC: swc1        $f28, 0x2A0($v1)
    MEM_W(0X2A0, ctx->r3) = ctx->f28.u32l;
    // 0x8057AD00: lw          $t2, 0x1E0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X1E0);
    // 0x8057AD04: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8057AD08: sw          $t3, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = ctx->r11;
L_8057AD0C:
    // 0x8057AD0C: lwc1        $f16, 0x2A0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2A0);
L_8057AD10:
    // 0x8057AD10: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8057AD14: nop

    // 0x8057AD18: bc1f        L_8057AD28
    if (!c1cs) {
        // 0x8057AD1C: nop
    
            goto L_8057AD28;
    }
    // 0x8057AD1C: nop

    // 0x8057AD20: swc1        $f30, 0x228($s0)
    MEM_W(0X228, ctx->r16) = ctx->f30.u32l;
    // 0x8057AD24: swc1        $f20, 0x2A0($s0)
    MEM_W(0X2A0, ctx->r16) = ctx->f20.u32l;
L_8057AD28:
    // 0x8057AD28: jal         0x8005B270
    // 0x8057AD2C: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    func_8005B270(rdram, ctx);
        goto after_1;
    // 0x8057AD2C: lwc1        $f12, 0x2A0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X2A0);
    after_1:
    // 0x8057AD30: slti        $at, $s1, 0x1E
    ctx->r1 = SIGNED(ctx->r17) < 0X1E ? 1 : 0;
    // 0x8057AD34: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x8057AD38: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8057AD3C: sh          $v0, 0x1A($s3)
    MEM_H(0X1A, ctx->r19) = ctx->r2;
    // 0x8057AD40: sh          $v0, 0x22($s3)
    MEM_H(0X22, ctx->r19) = ctx->r2;
    // 0x8057AD44: bne         $at, $zero, L_8057AC88
    if (ctx->r1 != 0) {
        // 0x8057AD48: addiu       $s3, $s3, 0x30
        ctx->r19 = ADD32(ctx->r19, 0X30);
            goto L_8057AC88;
    }
    // 0x8057AD48: addiu       $s3, $s3, 0x30
    ctx->r19 = ADD32(ctx->r19, 0X30);
    // 0x8057AD4C: lw          $t4, 0x1E0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X1E0);
    // 0x8057AD50: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8057AD54: bnel        $at, $zero, L_8057ADFC
    if (ctx->r1 != 0) {
        // 0x8057AD58: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8057ADFC;
    }
    goto skip_2;
    // 0x8057AD58: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_2:
    // 0x8057AD5C: lwc1        $f18, 0x29C($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X29C);
    // 0x8057AD60: lui         $at, 0x8058
    ctx->r1 = S32(RELOC_HI16(384, 0X1B7C) << 16);
    // 0x8057AD64: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x8057AD68: c.eq.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl == ctx->f18.fl;
    // 0x8057AD6C: addiu       $s0, $s5, 0x8
    ctx->r16 = ADD32(ctx->r21, 0X8);
    // 0x8057AD70: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x8057AD74: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8057AD78: bc1fl       L_8057ADFC
    if (!c1cs) {
        // 0x8057AD7C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_8057ADFC;
    }
    goto skip_3;
    // 0x8057AD7C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x8057AD80: lwc1        $f0, -0x4A44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(384, 0X1B7C));
    // 0x8057AD84: swc1        $f20, 0x2A4($s5)
    MEM_W(0X2A4, ctx->r21) = ctx->f20.u32l;
    // 0x8057AD88: swc1        $f20, 0x2A0($s5)
    MEM_W(0X2A0, ctx->r21) = ctx->f20.u32l;
    // 0x8057AD8C: swc1        $f0, 0x228($s5)
    MEM_W(0X228, ctx->r21) = ctx->f0.u32l;
    // 0x8057AD90: swc1        $f0, 0x22C($s5)
    MEM_W(0X22C, ctx->r21) = ctx->f0.u32l;
L_8057AD94:
    // 0x8057AD94: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8057AD98: swc1        $f0, 0x22C($s0)
    MEM_W(0X22C, ctx->r16) = ctx->f0.u32l;
    // 0x8057AD9C: swc1        $f20, 0x2A4($s0)
    MEM_W(0X2A4, ctx->r16) = ctx->f20.u32l;
    // 0x8057ADA0: swc1        $f0, 0x230($s0)
    MEM_W(0X230, ctx->r16) = ctx->f0.u32l;
    // 0x8057ADA4: swc1        $f20, 0x2A8($s0)
    MEM_W(0X2A8, ctx->r16) = ctx->f20.u32l;
    // 0x8057ADA8: swc1        $f0, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->f0.u32l;
    // 0x8057ADAC: swc1        $f20, 0x2AC($s0)
    MEM_W(0X2AC, ctx->r16) = ctx->f20.u32l;
    // 0x8057ADB0: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8057ADB4: swc1        $f0, 0x218($s0)
    MEM_W(0X218, ctx->r16) = ctx->f0.u32l;
    // 0x8057ADB8: bne         $s2, $v0, L_8057AD94
    if (ctx->r18 != ctx->r2) {
        // 0x8057ADBC: swc1        $f20, 0x290($s0)
        MEM_W(0X290, ctx->r16) = ctx->f20.u32l;
            goto L_8057AD94;
    }
    // 0x8057ADBC: swc1        $f20, 0x290($s0)
    MEM_W(0X290, ctx->r16) = ctx->f20.u32l;
    // 0x8057ADC0: jal         0x8057B444
    // 0x8057ADC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    func_8057B444(rdram, ctx);
        goto after_2;
    // 0x8057ADC4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x8057ADC8: lbu         $v0, 0x67($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X67);
    // 0x8057ADCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8057ADD0: beq         $v0, $at, L_8057ADF0
    if (ctx->r2 == ctx->r1) {
        // 0x8057ADD4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8057ADF0;
    }
    // 0x8057ADD4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8057ADD8: beq         $v0, $at, L_8057ADF0
    if (ctx->r2 == ctx->r1) {
        // 0x8057ADDC: nop
    
            goto L_8057ADF0;
    }
    // 0x8057ADDC: nop

    // 0x8057ADE0: jal         0x800677F8
    // 0x8057ADE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    func_800677F8(rdram, ctx);
        goto after_3;
    // 0x8057ADE4: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    after_3:
    // 0x8057ADE8: b           L_8057ADFC
    // 0x8057ADEC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8057ADFC;
    // 0x8057ADEC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8057ADF0:
    // 0x8057ADF0: jal         0x800677F8
    // 0x8057ADF4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    func_800677F8(rdram, ctx);
        goto after_4;
    // 0x8057ADF4: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_4:
    // 0x8057ADF8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8057ADFC:
    // 0x8057ADFC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8057AE00: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8057AE04: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8057AE08: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8057AE0C: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8057AE10: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8057AE14: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8057AE18: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8057AE1C: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8057AE20: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8057AE24: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8057AE28: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8057AE2C: jr          $ra
    // 0x8057AE30: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8057AE30: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_807A67CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A67CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A67D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A67D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A67D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807A67DC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807A67E0: jal         0x80047090
    // 0x807A67E4: addiu       $a0, $zero, 0x46E6
    ctx->r4 = ADD32(0, 0X46E6);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807A67E4: addiu       $a0, $zero, 0x46E6
    ctx->r4 = ADD32(0, 0X46E6);
    after_0:
    // 0x807A67E8: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x807A67EC: bne         $v0, $at, L_807A67FC
    if (ctx->r2 != ctx->r1) {
        // 0x807A67F0: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_807A67FC;
    }
    // 0x807A67F0: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x807A67F4: b           L_807A686C
    // 0x807A67F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A686C;
    // 0x807A67F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A67FC:
    // 0x807A67FC: lui         $at, 0x46E6
    ctx->r1 = S32(0X46E6 << 16);
    // 0x807A6800: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x807A6804: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x807A6808: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x807A680C: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x807A6810: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    // 0x807A6814: jal         0x8004613C
    // 0x807A6818: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807A6818: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x807A681C: lhu         $v1, 0x22($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X22);
    // 0x807A6820: bne         $v0, $zero, L_807A6830
    if (ctx->r2 != 0) {
        // 0x807A6824: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_807A6830;
    }
    // 0x807A6824: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x807A6828: b           L_807A686C
    // 0x807A682C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807A686C;
    // 0x807A682C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807A6830:
    // 0x807A6830: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x807A6834: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x807A6838: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x807A683C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x807A6840: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x807A6844: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    // 0x807A6848: jal         0x80047F9C
    // 0x807A684C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807A684C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807A6850: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x807A6854: sb          $t1, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r9;
    // 0x807A6858: jal         0x807A6710
    // 0x807A685C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A6710(rdram, ctx);
        goto after_3;
    // 0x807A685C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807A6860: jal         0x807A67B8
    // 0x807A6864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807A67B8(rdram, ctx);
        goto after_4;
    // 0x807A6864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x807A6868: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_807A686C:
    // 0x807A686C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807A6870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A6874: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A6878: jr          $ra
    // 0x807A687C: nop

    return;
    // 0x807A687C: nop

;}
RECOMP_FUNC void func_80423630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80423630: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80423634: srl         $v1, $a3, 1
    ctx->r3 = S32(U32(ctx->r7) >> 1);
    // 0x80423638: addiu       $v1, $v1, -0x3
    ctx->r3 = ADD32(ctx->r3, -0X3);
    // 0x8042363C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80423640: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80423644: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80423648: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8042364C: lw          $s1, 0xB8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XB8);
    // 0x80423650: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80423654: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80423658: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8042365C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80423660: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80423664: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80423668: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8042366C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80423670: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80423674: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80423678: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8042367C: bgez        $v1, L_80423694
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80423680: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80423694;
    }
    // 0x80423680: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80423684: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80423688: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042368C: nop

    // 0x80423690: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80423694:
    // 0x80423694: div.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80423698: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8042369C: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x804236A0: addiu       $s4, $v1, 0x3
    ctx->r20 = ADD32(ctx->r3, 0X3);
    // 0x804236A4: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x804236A8: sltiu       $at, $s4, 0x3
    ctx->r1 = ctx->r20 < 0X3 ? 1 : 0;
    // 0x804236AC: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x804236B0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x804236B4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x804236B8: addiu       $s0, $a0, 0x18
    ctx->r16 = ADD32(ctx->r4, 0X18);
    // 0x804236BC: addiu       $s2, $a1, 0x18
    ctx->r18 = ADD32(ctx->r5, 0X18);
    // 0x804236C0: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x804236C4: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x804236C8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x804236CC: lwc1        $f24, 0x64($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804236D0: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x804236D4: lh          $v0, -0x2($s1)
    ctx->r2 = MEM_H(ctx->r17, -0X2);
    // 0x804236D8: sh          $t6, -0x4($s1)
    MEM_H(-0X4, ctx->r17) = ctx->r14;
    // 0x804236DC: sh          $v0, -0x6($s1)
    MEM_H(-0X6, ctx->r17) = ctx->r2;
    // 0x804236E0: sh          $v0, -0x8($s1)
    MEM_H(-0X8, ctx->r17) = ctx->r2;
    // 0x804236E4: sh          $v0, -0xA($s1)
    MEM_H(-0XA, ctx->r17) = ctx->r2;
    // 0x804236E8: sh          $v0, -0xC($s1)
    MEM_H(-0XC, ctx->r17) = ctx->r2;
    // 0x804236EC: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x804236F0: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x804236F4: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x804236F8: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x804236FC: lh          $t9, 0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X4);
    // 0x80423700: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x80423704: lh          $t0, 0x6($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X6);
    // 0x80423708: sh          $t0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r8;
    // 0x8042370C: lh          $t1, 0x8($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X8);
    // 0x80423710: sh          $t1, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r9;
    // 0x80423714: lh          $t2, 0xA($a1)
    ctx->r10 = MEM_H(ctx->r5, 0XA);
    // 0x80423718: sh          $t2, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r10;
    // 0x8042371C: lh          $t3, 0xC($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XC);
    // 0x80423720: sh          $t3, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r11;
    // 0x80423724: lh          $t4, 0xE($a1)
    ctx->r12 = MEM_H(ctx->r5, 0XE);
    // 0x80423728: sh          $t4, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r12;
    // 0x8042372C: lh          $t5, 0x10($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X10);
    // 0x80423730: sh          $t5, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r13;
    // 0x80423734: lh          $t6, 0x12($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X12);
    // 0x80423738: sh          $t6, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r14;
    // 0x8042373C: lh          $t7, 0x14($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X14);
    // 0x80423740: sh          $t7, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r15;
    // 0x80423744: lh          $t8, 0x16($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X16);
    // 0x80423748: bne         $at, $zero, L_8042389C
    if (ctx->r1 != 0) {
        // 0x8042374C: sh          $t8, 0x16($a0)
        MEM_H(0X16, ctx->r4) = ctx->r24;
            goto L_8042389C;
    }
    // 0x8042374C: sh          $t8, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r24;
    // 0x80423750: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80423754: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80423758: nop

L_8042375C:
    // 0x8042375C: sub.s       $f16, $f24, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x80423760: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80423764: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80423768: nop

    // 0x8042376C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80423770: add.s       $f22, $f4, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80423774: jal         0x80066E88
    // 0x80423778: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80423778: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x8042377C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80423780: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80423784: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80423788: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042378C: nop

    // 0x80423790: bc1f        L_804237A8
    if (!c1cs) {
        // 0x80423794: nop
    
            goto L_804237A8;
    }
    // 0x80423794: nop

    // 0x80423798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042379C: nop

    // 0x804237A0: mul.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x804237A4: nop

L_804237A8:
    // 0x804237A8: jal         0x80066DE4
    // 0x804237AC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804237AC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_1:
    // 0x804237B0: mul.s       $f2, $f26, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x804237B4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x804237B8: mul.s       $f14, $f26, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x804237BC: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x804237C0: sub.s       $f18, $f30, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f30.fl - ctx->f14.fl;
    // 0x804237C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804237C8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x804237CC: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x804237D0: add.s       $f8, $f28, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f28.fl + ctx->f2.fl;
    // 0x804237D4: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x804237D8: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x804237DC: add.s       $f10, $f30, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f30.fl + ctx->f14.fl;
    // 0x804237E0: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x804237E4: lh          $t3, 0x4($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X4);
    // 0x804237E8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x804237EC: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x804237F0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x804237F4: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x804237F8: trunc.w.s   $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    ctx->f18.u32l = TRUNC_W_S(ctx->f28.fl);
    // 0x804237FC: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80423800: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x80423804: trunc.w.s   $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    ctx->f4.u32l = TRUNC_W_S(ctx->f30.fl);
    // 0x80423808: sh          $t7, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r15;
    // 0x8042380C: lh          $t8, 0xA($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XA);
    // 0x80423810: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80423814: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x80423818: sh          $t8, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r24;
    // 0x8042381C: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x80423820: sh          $t0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r8;
    // 0x80423824: jal         0x80066E88
    // 0x80423828: sh          $t2, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r10;
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80423828: sh          $t2, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r10;
    after_2:
    // 0x8042382C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80423830: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80423834: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80423838: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8042383C: nop

    // 0x80423840: bc1f        L_80423858
    if (!c1cs) {
        // 0x80423844: nop
    
            goto L_80423858;
    }
    // 0x80423844: nop

    // 0x80423848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042384C: nop

    // 0x80423850: mul.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80423854: nop

L_80423858:
    // 0x80423858: jal         0x80066DE4
    // 0x8042385C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8042385C: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    after_3:
    // 0x80423860: mul.s       $f10, $f26, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x80423864: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80423868: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8042386C: mul.s       $f16, $f26, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f20.fl);
    // 0x80423870: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x80423874: mov.s       $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    ctx->f2.fl = ctx->f24.fl;
    // 0x80423878: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8042387C: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80423880: add.s       $f28, $f10, $f28
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f28.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80423884: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    // 0x80423888: sub.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8042388C: bne         $at, $zero, L_8042375C
    if (ctx->r1 != 0) {
        // 0x80423890: sub.s       $f24, $f24, $f18
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f18.fl;
            goto L_8042375C;
    }
    // 0x80423890: sub.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80423894: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80423898: nop

L_8042389C:
    // 0x8042389C: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x804238A0: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36C8) << 16);
    // 0x804238A4: swc1        $f28, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f28.u32l;
    // 0x804238A8: swc1        $f30, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f30.u32l;
    // 0x804238AC: lwc1        $f4, 0x60C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36C8));
    // 0x804238B0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804238B4: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x804238B8: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x804238BC: add.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x804238C0: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x804238C4: nop

    // 0x804238C8: bc1fl       L_80423914
    if (!c1cs) {
        // 0x804238CC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80423914;
    }
    goto skip_0;
    // 0x804238CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x804238D0: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x804238D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x804238D8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x804238DC: c.le.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl <= ctx->f2.fl;
    // 0x804238E0: nop

    // 0x804238E4: bc1fl       L_80423940
    if (!c1cs) {
        // 0x804238E8: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80423940;
    }
    goto skip_1;
    // 0x804238E8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_1:
    // 0x804238EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x804238F0: nop

    // 0x804238F4: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
L_804238F8:
    // 0x804238F8: c.le.s      $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f24.fl <= ctx->f2.fl;
    // 0x804238FC: nop

    // 0x80423900: bc1tl       L_804238F8
    if (c1cs) {
        // 0x80423904: add.s       $f24, $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
            goto L_804238F8;
    }
    goto skip_2;
    // 0x80423904: add.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f0.fl;
    skip_2:
    // 0x80423908: b           L_80423940
    // 0x8042390C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
        goto L_80423940;
    // 0x8042390C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80423910: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80423914:
    // 0x80423914: nop

    // 0x80423918: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x8042391C: nop

    // 0x80423920: bc1fl       L_80423940
    if (!c1cs) {
        // 0x80423924: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80423940;
    }
    goto skip_3;
    // 0x80423924: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    skip_3:
    // 0x80423928: sub.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f0.fl;
L_8042392C:
    // 0x8042392C: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x80423930: nop

    // 0x80423934: bc1tl       L_8042392C
    if (c1cs) {
        // 0x80423938: sub.s       $f24, $f24, $f0
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f0.fl;
            goto L_8042392C;
    }
    goto skip_4;
    // 0x80423938: sub.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f0.fl;
    skip_4:
    // 0x8042393C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
L_80423940:
    // 0x80423940: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80423944: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80423948: c.lt.s      $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f6.fl < ctx->f24.fl;
    // 0x8042394C: nop

    // 0x80423950: bc1fl       L_80423988
    if (!c1cs) {
        // 0x80423954: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_80423988;
    }
    goto skip_5;
    // 0x80423954: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    skip_5:
    // 0x80423958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8042395C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80423960: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80423964: nop

    // 0x80423968: bc1fl       L_80423988
    if (!c1cs) {
        // 0x8042396C: lui         $at, 0xC2B4
        ctx->r1 = S32(0XC2B4 << 16);
            goto L_80423988;
    }
    goto skip_6;
    // 0x8042396C: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    skip_6:
    // 0x80423970: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80423974: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x80423978: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x8042397C: b           L_804239D4
    // 0x80423980: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
        goto L_804239D4;
    // 0x80423980: swc1        $f18, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f18.u32l;
    // 0x80423984: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
L_80423988:
    // 0x80423988: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042398C: lui         $at, 0xC387
    ctx->r1 = S32(0XC387 << 16);
    // 0x80423990: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x80423994: c.lt.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl < ctx->f4.fl;
    // 0x80423998: nop

    // 0x8042399C: bc1fl       L_804239D4
    if (!c1cs) {
        // 0x804239A0: swc1        $f24, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->f24.u32l;
            goto L_804239D4;
    }
    goto skip_7;
    // 0x804239A0: swc1        $f24, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f24.u32l;
    skip_7:
    // 0x804239A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x804239A8: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x804239AC: c.lt.s      $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f8.fl < ctx->f24.fl;
    // 0x804239B0: nop

    // 0x804239B4: bc1fl       L_804239D4
    if (!c1cs) {
        // 0x804239B8: swc1        $f24, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->f24.u32l;
            goto L_804239D4;
    }
    goto skip_8;
    // 0x804239B8: swc1        $f24, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f24.u32l;
    skip_8:
    // 0x804239BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804239C0: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x804239C4: sub.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x804239C8: b           L_804239D4
    // 0x804239CC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
        goto L_804239D4;
    // 0x804239CC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x804239D0: swc1        $f24, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f24.u32l;
L_804239D4:
    // 0x804239D4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x804239D8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x804239DC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x804239E0: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x804239E4: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x804239E8: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x804239EC: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x804239F0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x804239F4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x804239F8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804239FC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80423A00: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80423A04: jr          $ra
    // 0x80423A08: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80423A08: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_804CF298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CF298: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804CF29C: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(240, 0X910) << 16);
    // 0x804CF2A0: addiu       $t6, $t6, -0x1440
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(240, 0X910));
    // 0x804CF2A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804CF2A8: jr          $ra
    // 0x804CF2AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804CF2AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8057F0F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057F0F4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8057F0F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057F0FC: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8057F100: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8057F104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8057F108: lw          $t0, 0x5C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X5C);
    // 0x8057F10C: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8057F110: subu        $t6, $t6, $t0
    ctx->r14 = SUB32(ctx->r14, ctx->r8);
    // 0x8057F114: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8057F118: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8057F11C: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8057F120: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8057F124: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8057F128: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8057F12C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8057F130: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8057F134: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8057F138: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8057F13C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8057F140: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8057F144: jal         0x80580720
    // 0x8057F148: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    func_80580720(rdram, ctx);
        goto after_0;
    // 0x8057F148: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    after_0:
    // 0x8057F14C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8057F150: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8057F154: lui         $a1, 0x8058
    ctx->r5 = S32(RELOC_HI16(399, 0X41A8) << 16);
    // 0x8057F158: sw          $v0, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r2;
    // 0x8057F15C: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8057F160: addiu       $a1, $a1, 0x2FB8
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(399, 0X41A8));
    // 0x8057F164: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8057F168: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8057F16C: addiu       $a2, $zero, 0x40EC
    ctx->r6 = ADD32(0, 0X40EC);
    // 0x8057F170: lw          $t9, 0x18($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X18);
    // 0x8057F174: jalr        $t9
    // 0x8057F178: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8057F178: nop

    after_1:
    // 0x8057F17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8057F180: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8057F184: jr          $ra
    // 0x8057F188: nop

    return;
    // 0x8057F188: nop

;}
RECOMP_FUNC void func_804A225C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A225C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804A2260: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A2264: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A2268: jal         0x804A2910
    // 0x804A226C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A226C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804A2270: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    // 0x804A2274: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x804A2278: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x804A227C: jal         0x80048F84
    // 0x804A2280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x804A2280: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x804A2284: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x804A2288: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A228C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804A2290: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x804A2294: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804A2298: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804A229C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x804A22A0: swc1        $f8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f8.u32l;
    // 0x804A22A4: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x804A22A8: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x804A22AC: nop

    // 0x804A22B0: bc1fl       L_804A231C
    if (!c1cs) {
        // 0x804A22B4: lw          $t7, 0x1E0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1E0);
            goto L_804A231C;
    }
    goto skip_0;
    // 0x804A22B4: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x804A22B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804A22BC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X31A0) << 16);
    // 0x804A22C0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x804A22C4: swc1        $f18, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f18.u32l;
    // 0x804A22C8: lwc1        $f4, 0x35E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X31A0));
    // 0x804A22CC: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X31A4) << 16);
    // 0x804A22D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A22D4: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x804A22D8: lwc1        $f6, 0x35E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X31A4));
    // 0x804A22DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A22E0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x804A22E4: swc1        $f6, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f6.u32l;
    // 0x804A22E8: jal         0x804A27A0
    // 0x804A22EC: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    func_804A27A0(rdram, ctx);
        goto after_2;
    // 0x804A22EC: sw          $t6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r14;
    after_2:
    // 0x804A22F0: jal         0x804A13E8
    // 0x804A22F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804A13E8(rdram, ctx);
        goto after_3;
    // 0x804A22F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804A22F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804A22FC: jal         0x80067E98
    // 0x804A2300: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    func_80067E98(rdram, ctx);
        goto after_4;
    // 0x804A2300: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    after_4:
    // 0x804A2304: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x804A2308: jal         0x80067818
    // 0x804A230C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_5;
    // 0x804A230C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x804A2310: b           L_804A2358
    // 0x804A2314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A2358;
    // 0x804A2314: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A2318: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
L_804A231C:
    // 0x804A231C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A2320: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x804A2324: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x804A2328: bne         $at, $zero, L_804A2354
    if (ctx->r1 != 0) {
        // 0x804A232C: sw          $t8, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r24;
            goto L_804A2354;
    }
    // 0x804A232C: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x804A2330: jal         0x804A13E8
    // 0x804A2334: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    func_804A13E8(rdram, ctx);
        goto after_6;
    // 0x804A2334: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    after_6:
    // 0x804A2338: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804A233C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A2340: jal         0x80067ED8
    // 0x804A2344: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    func_80067ED8(rdram, ctx);
        goto after_7;
    // 0x804A2344: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    after_7:
    // 0x804A2348: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x804A234C: jal         0x80067818
    // 0x804A2350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_8;
    // 0x804A2350: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
L_804A2354:
    // 0x804A2354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A2358:
    // 0x804A2358: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A235C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804A2360: jr          $ra
    // 0x804A2364: nop

    return;
    // 0x804A2364: nop

;}
RECOMP_FUNC void func_80006CA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006CA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80006CAC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80006CB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80006CB4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006CB8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006CBC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80006CC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006CC4: jal         0x800073BC
    // 0x80006CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800073BC(rdram, ctx);
        goto after_0;
    // 0x80006CC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006CCC: lui         $s3, 0x800B
    ctx->r19 = S32(0X800B << 16);
    // 0x80006CD0: addiu       $s3, $s3, 0x4D10
    ctx->r19 = ADD32(ctx->r19, 0X4D10);
    // 0x80006CD4: lw          $v1, 0x1D70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X1D70);
    // 0x80006CD8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006CDC: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006CE0: lhu         $s1, 0x0($t7)
    ctx->r17 = MEM_HU(ctx->r15, 0X0);
    // 0x80006CE4: addu        $t8, $s1, $v1
    ctx->r24 = ADD32(ctx->r17, ctx->r3);
    // 0x80006CE8: lbu         $s2, 0x0($t8)
    ctx->r18 = MEM_BU(ctx->r24, 0X0);
    // 0x80006CEC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80006CF0: blezl       $s2, L_80006D4C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80006CF4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80006D4C;
    }
    goto skip_0;
    // 0x80006CF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80006CF8: lw          $t9, 0x1D70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1D70);
L_80006CFC:
    // 0x80006CFC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80006D00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006D04: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x80006D08: lbu         $a1, 0x0($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X0);
    // 0x80006D0C: jal         0x800073BC
    // 0x80006D10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    func_800073BC(rdram, ctx);
        goto after_1;
    // 0x80006D10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_1:
    // 0x80006D14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80006D18: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80006D1C: jal         0x80005640
    // 0x80006D20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80005640(rdram, ctx);
        goto after_2;
    // 0x80006D20: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80006D24: bne         $v0, $zero, L_80006D40
    if (ctx->r2 != 0) {
        // 0x80006D28: nop
    
            goto L_80006D40;
    }
    // 0x80006D28: nop

    // 0x80006D2C: jal         0x80006D64
    // 0x80006D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80006D64(rdram, ctx);
        goto after_3;
    // 0x80006D30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80006D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006D38: jal         0x8000675C
    // 0x80006D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8000675C(rdram, ctx);
        goto after_4;
    // 0x80006D3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
L_80006D40:
    // 0x80006D40: bgtzl       $s2, L_80006CFC
    if (SIGNED(ctx->r18) > 0) {
        // 0x80006D44: lw          $t9, 0x1D70($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X1D70);
            goto L_80006CFC;
    }
    goto skip_1;
    // 0x80006D44: lw          $t9, 0x1D70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X1D70);
    skip_1:
    // 0x80006D48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80006D4C:
    // 0x80006D4C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80006D50: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80006D54: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80006D58: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80006D5C: jr          $ra
    // 0x80006D60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80006D60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80454550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80454550: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80454554: addiu       $v1, $zero, 0x3C0
    ctx->r3 = ADD32(0, 0X3C0);
    // 0x80454558: addiu       $a1, $zero, 0x1B6C
    ctx->r5 = ADD32(0, 0X1B6C);
    // 0x8045455C: addiu       $t6, $zero, 0x1EF0
    ctx->r14 = ADD32(0, 0X1EF0);
    // 0x80454560: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x80454564: sw          $v1, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r3;
    // 0x80454568: sw          $a1, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r5;
    // 0x8045456C: sw          $v1, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r3;
    // 0x80454570: sw          $a1, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->r5;
    // 0x80454574: jr          $ra
    // 0x80454578: sw          $t6, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r14;
    return;
    // 0x80454578: sw          $t6, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8003C8F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C8F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003C8F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003C8F8: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x8003C8FC: addiu       $t8, $t8, -0x1330
    ctx->r24 = ADD32(ctx->r24, -0X1330);
    // 0x8003C900: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8003C904: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003C908: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8003C90C: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8003C910: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003C914: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003C918: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003C91C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8003C920: jal         0x8004613C
    // 0x8003C924: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x8003C924: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003C928: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8003C92C: bne         $v0, $zero, L_8003C93C
    if (ctx->r2 != 0) {
        // 0x8003C930: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8003C93C;
    }
    // 0x8003C930: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8003C934: b           L_8003C964
    // 0x8003C938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003C964;
    // 0x8003C938: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003C93C:
    // 0x8003C93C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8003C940: addiu       $t9, $t9, -0x132C
    ctx->r25 = ADD32(ctx->r25, -0X132C);
    // 0x8003C944: bnel        $v1, $t9, L_8003C964
    if (ctx->r3 != ctx->r25) {
        // 0x8003C948: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003C964;
    }
    goto skip_0;
    // 0x8003C948: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
    // 0x8003C94C: lw          $t0, 0x174($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X174);
    // 0x8003C950: bnel        $t0, $zero, L_8003C964
    if (ctx->r8 != 0) {
        // 0x8003C954: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003C964;
    }
    goto skip_1;
    // 0x8003C954: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_1:
    // 0x8003C958: b           L_8003C964
    // 0x8003C95C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003C964;
    // 0x8003C95C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8003C960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003C964:
    // 0x8003C964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003C968: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C96C: jr          $ra
    // 0x8003C970: nop

    return;
    // 0x8003C970: nop

;}
RECOMP_FUNC void func_800538BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800538BC: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x800538C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800538C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800538C8: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x800538CC: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800538D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800538D4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800538D8: jal         0x8006A99C
    // 0x800538DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x800538DC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_0:
    // 0x800538E0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800538E4: sh          $v0, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r2;
    // 0x800538E8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800538EC: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800538F0: nop

    // 0x800538F4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800538F8: jal         0x8006A99C
    // 0x800538FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x800538FC: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_1:
    // 0x80053900: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80053904: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80053908: lh          $a0, 0x1E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X1E);
    // 0x8005390C: jal         0x8006B1C8
    // 0x80053910: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    func_8006B1C8(rdram, ctx);
        goto after_2;
    // 0x80053910: lhu         $a2, 0x2A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X2A);
    after_2:
    // 0x80053914: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80053918: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005391C: jr          $ra
    // 0x80053920: nop

    return;
    // 0x80053920: nop

;}
RECOMP_FUNC void func_807C6920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6920: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807C6924: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807C6928: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807C692C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807C6930: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807C6934: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x807C6938: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807C693C: lui         $t1, 0x807C
    ctx->r9 = S32(RELOC_HI16(916, 0X1D0) << 16);
    // 0x807C6940: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807C6944: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807C6948: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807C694C: lw          $t1, 0x69E0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(916, 0X1D0));
    // 0x807C6950: jr          $ra
    // 0x807C6954: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807C6954: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8064BBEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BBEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BBF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BBF4: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8064BBF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064BBFC: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x8064BC00: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8064BC04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BC08: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064BC0C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8064BC10: bc1fl       L_8064BC28
    if (!c1cs) {
        // 0x8064BC14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BC28;
    }
    goto skip_0;
    // 0x8064BC14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BC18: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064BC1C: jal         0x8064BF74
    // 0x8064BC20: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BC20: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064BC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BC28:
    // 0x8064BC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BC2C: jr          $ra
    // 0x8064BC30: nop

    return;
    // 0x8064BC30: nop

;}
RECOMP_FUNC void func_80031778(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031778: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003177C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031780: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80031784: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80031788: jal         0x800310A0
    // 0x8003178C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800310A0(rdram, ctx);
        goto after_0;
    // 0x8003178C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80031790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80031794: jal         0x800421B4
    // 0x80031798: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_800421B4(rdram, ctx);
        goto after_1;
    // 0x80031798: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003179C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800317A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800317A4: jr          $ra
    // 0x800317A8: nop

    return;
    // 0x800317A8: nop

;}
RECOMP_FUNC void func_8042CF94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042CF94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042CF98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8042CF9C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8042CFA0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8042CFA4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8042CFA8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8042CFAC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8042CFB0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8042CFB4: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8042CFB8: lw          $s1, 0x4($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X4);
    // 0x8042CFBC: jal         0x80064D1C
    // 0x8042CFC0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8042CFC0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x8042CFC4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8042CFC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8042CFCC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8042CFD0: lw          $a0, 0x4C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4C);
    // 0x8042CFD4: jal         0x80064D1C
    // 0x8042CFD8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x8042CFD8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_1:
    // 0x8042CFDC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8042CFE0: lw          $a0, 0x4C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4C);
    // 0x8042CFE4: jal         0x80064D1C
    // 0x8042CFE8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8042CFE8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_2:
    // 0x8042CFEC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8042CFF0: lw          $a0, 0x4C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4C);
    // 0x8042CFF4: jal         0x80064D1C
    // 0x8042CFF8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8042CFF8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_3:
    // 0x8042CFFC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8042D000: lw          $t7, 0x4C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4C);
    // 0x8042D004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8042D008: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8042D00C: blezl       $t7, L_8042D078
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8042D010: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8042D078;
    }
    goto skip_0;
    // 0x8042D010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8042D014: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
L_8042D018:
    // 0x8042D018: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8042D01C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8042D020: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8042D024: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8042D028: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x8042D02C: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
    // 0x8042D030: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x8042D034: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8042D038: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8042D03C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8042D040: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8042D044: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8042D048: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8042D04C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8042D050: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8042D054: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8042D058: addu        $t2, $t0, $v0
    ctx->r10 = ADD32(ctx->r8, ctx->r2);
    // 0x8042D05C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8042D060: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x8042D064: lw          $t3, 0x4C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4C);
    // 0x8042D068: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8042D06C: bnel        $at, $zero, L_8042D018
    if (ctx->r1 != 0) {
        // 0x8042D070: lw          $t8, 0x0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X0);
            goto L_8042D018;
    }
    goto skip_1;
    // 0x8042D070: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    skip_1:
    // 0x8042D074: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8042D078:
    // 0x8042D078: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8042D07C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8042D080: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8042D084: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8042D088: jr          $ra
    // 0x8042D08C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8042D08C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8076D360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8076D360: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8076D364: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8076D368: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8076D36C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8076D370: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8076D374: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8076D378: beq         $v0, $zero, L_8076D384
    if (ctx->r2 == 0) {
        // 0x8076D37C: swc1        $f4, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
            goto L_8076D384;
    }
    // 0x8076D37C: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8076D380: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
L_8076D384:
    // 0x8076D384: jr          $ra
    // 0x8076D388: nop

    return;
    // 0x8076D388: nop

;}
RECOMP_FUNC void func_80776D98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80776D98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80776D9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80776DA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80776DA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80776DA8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80776DAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80776DB0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80776DB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80776DB8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80776DBC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80776DC0: nop

    // 0x80776DC4: bc1f        L_80776DDC
    if (!c1cs) {
        // 0x80776DC8: nop
    
            goto L_80776DDC;
    }
    // 0x80776DC8: nop

    // 0x80776DCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80776DD0: nop

    // 0x80776DD4: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80776DD8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
L_80776DDC:
    // 0x80776DDC: jal         0x80776B7C
    // 0x80776DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80776B7C(rdram, ctx);
        goto after_0;
    // 0x80776DE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80776DE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80776DE8: bne         $v0, $at, L_80776E04
    if (ctx->r2 != ctx->r1) {
        // 0x80776DEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80776E04;
    }
    // 0x80776DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80776DF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80776DF4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80776DF8: jal         0x8077725C
    // 0x80776DFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8077725C(rdram, ctx);
        goto after_1;
    // 0x80776DFC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80776E00: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
L_80776E04:
    // 0x80776E04: lw          $t6, 0x1E0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E0);
    // 0x80776E08: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80776E0C: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80776E10: beq         $t9, $zero, L_80776E58
    if (ctx->r25 == 0) {
        // 0x80776E14: sw          $t7, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r15;
            goto L_80776E58;
    }
    // 0x80776E14: sw          $t7, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r15;
    // 0x80776E18: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80776E1C: lui         $at, 0x8077
    ctx->r1 = S32(RELOC_HI16(772, 0X850) << 16);
    // 0x80776E20: lwc1        $f4, 0x7320($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(772, 0X850));
    // 0x80776E24: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80776E28: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80776E2C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80776E30: lw          $t9, -0x72C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X72C0);
    // 0x80776E34: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80776E38: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80776E3C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80776E40: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80776E44: jalr        $t9
    // 0x80776E48: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80776E48: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80776E4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80776E50: jal         0x80776C38
    // 0x80776E54: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    func_80776C38(rdram, ctx);
        goto after_3;
    // 0x80776E54: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_3:
L_80776E58:
    // 0x80776E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80776E5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80776E60: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80776E64: jr          $ra
    // 0x80776E68: nop

    return;
    // 0x80776E68: nop

;}
RECOMP_FUNC void func_8044BB60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BB60: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BB64: jr          $ra
    // 0x8044BB68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BB68: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_804753C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804753C0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804753C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804753C8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804753CC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804753D0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804753D4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804753D8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804753DC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804753E0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804753E4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804753E8: jr          $ra
    // 0x804753EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804753EC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804652D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804652D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804652D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804652D8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x804652DC: lw          $v1, -0x7CE8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7CE8);
    // 0x804652E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804652E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804652E8: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    // 0x804652EC: jal         0x80051194
    // 0x804652F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804652F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x804652F4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x804652F8: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804652FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80465300: lwc1        $f4, 0x30($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80465304: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x80465308: lwc1        $f6, 0x34($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8046530C: jal         0x80465268
    // 0x80465310: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    func_80465268(rdram, ctx);
        goto after_1;
    // 0x80465310: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80465314: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80465318: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(125, 0X1D38) << 16);
    // 0x8046531C: addiu       $t7, $t7, 0x6308
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(125, 0X1D38));
    // 0x80465320: bne         $t6, $zero, L_80465338
    if (ctx->r14 != 0) {
        // 0x80465324: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80465338;
    }
    // 0x80465324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80465328: jal         0x800445A4
    // 0x8046532C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_2;
    // 0x8046532C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80465330: b           L_804653A8
    // 0x80465334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804653A8;
    // 0x80465334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80465338:
    // 0x80465338: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x8046533C: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80465340: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80465344: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80465348: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8046534C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80465350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80465354: jal         0x804653B8
    // 0x80465358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804653B8(rdram, ctx);
        goto after_3;
    // 0x80465358: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x8046535C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80465360: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80465364: sb          $t9, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r25;
    // 0x80465368: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8046536C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80465370: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80465374: lw          $a2, 0x40($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X40);
    // 0x80465378: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    // 0x8046537C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80465380: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80465384: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80465388: jal         0x80466010
    // 0x8046538C: nop

    func_80466010(rdram, ctx);
        goto after_4;
    // 0x8046538C: nop

    after_4:
    // 0x80465390: lui         $t1, 0x8046
    ctx->r9 = S32(RELOC_HI16(125, 0XCD8) << 16);
    // 0x80465394: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x80465398: addiu       $t1, $t1, 0x52A8
    ctx->r9 = ADD32(ctx->r9, (int16_t)RELOC_LO16(125, 0XCD8));
    // 0x8046539C: sh          $t0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r8;
    // 0x804653A0: sw          $t1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r9;
    // 0x804653A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804653A8:
    // 0x804653A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804653AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804653B0: jr          $ra
    // 0x804653B4: nop

    return;
    // 0x804653B4: nop

;}
RECOMP_FUNC void func_804406D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804406D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804406D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804406D8: jal         0x8004700C
    // 0x804406DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804406DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804406E0: bne         $v0, $zero, L_804406F0
    if (ctx->r2 != 0) {
        // 0x804406E4: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_804406F0;
    }
    // 0x804406E4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x804406E8: b           L_804407A8
    // 0x804406EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804407A8;
    // 0x804406EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804406F0:
    // 0x804406F0: lw          $v1, 0x180($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X180);
    // 0x804406F4: bnel        $v1, $zero, L_80440708
    if (ctx->r3 != 0) {
        // 0x804406F8: lwc1        $f8, 0x88($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
            goto L_80440708;
    }
    goto skip_0;
    // 0x804406F8: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
    skip_0:
    // 0x804406FC: b           L_804407A8
    // 0x80440700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804407A8;
    // 0x80440700: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80440704: lwc1        $f8, 0x88($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X88);
L_80440708:
    // 0x80440708: lwc1        $f10, 0x88($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X88);
    // 0x8044070C: lui         $at, 0xC2F0
    ctx->r1 = S32(0XC2F0 << 16);
    // 0x80440710: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80440714: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80440718: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8044071C: lwc1        $f6, 0x84($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X84);
    // 0x80440720: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80440724: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80440728: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8044072C: bc1fl       L_804407A8
    if (!c1cs) {
        // 0x80440730: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804407A8;
    }
    goto skip_1;
    // 0x80440730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80440734: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80440738: nop

    // 0x8044073C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80440740: nop

    // 0x80440744: bc1fl       L_804407A8
    if (!c1cs) {
        // 0x80440748: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804407A8;
    }
    goto skip_2;
    // 0x80440748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8044074C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80440750: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80440754: bc1fl       L_804407A8
    if (!c1cs) {
        // 0x80440758: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804407A8;
    }
    goto skip_3;
    // 0x80440758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8044075C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80440760: nop

    // 0x80440764: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80440768: nop

    // 0x8044076C: bc1fl       L_804407A8
    if (!c1cs) {
        // 0x80440770: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804407A8;
    }
    goto skip_4;
    // 0x80440770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80440774: lbu         $v1, 0x30($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X30);
    // 0x80440778: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8044077C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80440780: beql        $a0, $v1, L_80440794
    if (ctx->r4 == ctx->r3) {
        // 0x80440784: lw          $t7, 0x1F4($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X1F4);
            goto L_80440794;
    }
    goto skip_5;
    // 0x80440784: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
    skip_5:
    // 0x80440788: bne         $v1, $at, L_8044079C
    if (ctx->r3 != ctx->r1) {
        // 0x8044078C: nop
    
            goto L_8044079C;
    }
    // 0x8044078C: nop

    // 0x80440790: lw          $t7, 0x1F4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X1F4);
L_80440794:
    // 0x80440794: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80440798: sw          $t6, 0x2630($t7)
    MEM_W(0X2630, ctx->r15) = ctx->r14;
L_8044079C:
    // 0x8044079C: b           L_804407A8
    // 0x804407A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804407A8;
    // 0x804407A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804407A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804407A8:
    // 0x804407A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804407AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804407B0: jr          $ra
    // 0x804407B4: nop

    return;
    // 0x804407B4: nop

;}
RECOMP_FUNC void func_80581CA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80581CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581CA8: jal         0x80581B84
    // 0x80581CAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80581B84(rdram, ctx);
        goto after_0;
    // 0x80581CAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581CB0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80581CB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80581CB8: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x80581CBC: beql        $a2, $zero, L_80581CD0
    if (ctx->r6 == 0) {
        // 0x80581CC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80581CD0;
    }
    goto skip_0;
    // 0x80581CC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80581CC4: jal         0x80581F38
    // 0x80581CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80581F38(rdram, ctx);
        goto after_1;
    // 0x80581CC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80581CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80581CD0:
    // 0x80581CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80581CD4: jr          $ra
    // 0x80581CD8: nop

    return;
    // 0x80581CD8: nop

;}
RECOMP_FUNC void func_804D8CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8CD0: lui         $v0, 0x804E
    ctx->r2 = S32(RELOC_HI16(258, 0X10) << 16);
    // 0x804D8CD4: addiu       $v0, $v0, -0x7320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(258, 0X10));
    // 0x804D8CD8: jr          $ra
    // 0x804D8CDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x804D8CDC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8006F1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F1F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F1F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F1F8: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8006F1FC: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8006F200: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8006F204: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8006F208: sw          $t6, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r14;
    // 0x8006F20C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8006F210: addiu       $t7, $t7, 0x7EF8
    ctx->r15 = ADD32(ctx->r15, 0X7EF8);
    // 0x8006F214: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8006F218: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F21C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006F220: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006F224: jal         0x8006F49C
    // 0x8006F228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F49C(rdram, ctx);
        goto after_0;
    // 0x8006F228: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8006F22C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F230: lui         $t9, 0x8007
    ctx->r25 = S32(0X8007 << 16);
    // 0x8006F234: addiu       $t9, $t9, -0xC94
    ctx->r25 = ADD32(ctx->r25, -0XC94);
    // 0x8006F238: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x8006F23C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8006F240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F248: jr          $ra
    // 0x8006F24C: nop

    return;
    // 0x8006F24C: nop

;}
RECOMP_FUNC void func_804A21B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A21B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804A21B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804A21B8: jal         0x804A2910
    // 0x804A21BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804A2910(rdram, ctx);
        goto after_0;
    // 0x804A21BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804A21C0: beq         $v0, $zero, L_804A224C
    if (ctx->r2 == 0) {
        // 0x804A21C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804A224C;
    }
    // 0x804A21C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804A21C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x804A21CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A21D0: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804A21D4: lui         $at, 0x804A
    ctx->r1 = S32(RELOC_HI16(173, 0X319C) << 16);
    // 0x804A21D8: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x804A21DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804A21E0: lwc1        $f6, 0x35DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(173, 0X319C));
    // 0x804A21E4: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x804A21E8: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x804A21EC: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x804A21F0: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x804A21F4: lwc1        $f8, 0x3C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804A21F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x804A21FC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x804A2200: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x804A2204: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x804A2208: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x804A220C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x804A2210: addiu       $t9, $zero, 0x13
    ctx->r25 = ADD32(0, 0X13);
    // 0x804A2214: bc1f        L_804A223C
    if (!c1cs) {
        // 0x804A2218: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_804A223C;
    }
    // 0x804A2218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A221C: sw          $t6, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r14;
    // 0x804A2220: sb          $t7, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r15;
    // 0x804A2224: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x804A2228: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804A222C: nop

    // 0x804A2230: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804A2234: b           L_804A2244
    // 0x804A2238: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
        goto L_804A2244;
    // 0x804A2238: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
L_804A223C:
    // 0x804A223C: sw          $t8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r24;
    // 0x804A2240: sb          $t9, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r25;
L_804A2244:
    // 0x804A2244: jal         0x804A27A0
    // 0x804A2248: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    func_804A27A0(rdram, ctx);
        goto after_1;
    // 0x804A2248: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    after_1:
L_804A224C:
    // 0x804A224C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804A2250: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804A2254: jr          $ra
    // 0x804A2258: nop

    return;
    // 0x804A2258: nop

;}
RECOMP_FUNC void func_80559128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8055912C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80559130: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80559134: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80559138: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x8055913C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80559140: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80559144: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80559148: lw          $s0, 0x130($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X130);
    // 0x8055914C: jal         0x80048F84
    // 0x80559150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80559154: jal         0x805580E8
    // 0x80559158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559158: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8055915C: jal         0x805582E0
    // 0x80559160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80559160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80559164: beq         $v0, $zero, L_80559278
    if (ctx->r2 == 0) {
        // 0x80559168: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_80559278;
    }
    // 0x80559168: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8055916C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559170: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80559174: jal         0x80559928
    // 0x80559178: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80559178: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x8055917C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80559180: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80559184: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559188: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x8055918C: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80559190: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x80559194: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80559198: swc1        $f0, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f0.u32l;
    // 0x8055919C: lw          $t9, 0x138($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X138);
    // 0x805591A0: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x805591A4: sw          $t0, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->r8;
    // 0x805591A8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x805591AC: lw          $t1, 0x138($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X138);
    // 0x805591B0: xori        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 ^ 0X1;
    // 0x805591B4: sw          $t2, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->r10;
    // 0x805591B8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x805591BC: lw          $t3, 0x138($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X138);
    // 0x805591C0: xori        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 ^ 0X1;
    // 0x805591C4: sw          $t4, 0x138($a2)
    MEM_W(0X138, ctx->r6) = ctx->r12;
    // 0x805591C8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x805591CC: lw          $t5, 0x138($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X138);
    // 0x805591D0: xori        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 ^ 0X1;
    // 0x805591D4: sw          $t6, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r14;
    // 0x805591D8: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x805591DC: lw          $t7, 0x138($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X138);
    // 0x805591E0: xori        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 ^ 0X1;
    // 0x805591E4: sw          $t8, 0x138($v1)
    MEM_W(0X138, ctx->r3) = ctx->r24;
    // 0x805591E8: lw          $a3, 0x10($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10);
    // 0x805591EC: lw          $t9, 0x138($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X138);
    // 0x805591F0: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x805591F4: jal         0x805582E0
    // 0x805591F8: sw          $t0, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r8;
    func_805582E0(rdram, ctx);
        goto after_4;
    // 0x805591F8: sw          $t0, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->r8;
    after_4:
    // 0x805591FC: lw          $a0, 0x14C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X14C);
    // 0x80559200: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(363, 0X9384) << 16);
    // 0x80559204: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80559208: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8055920C: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x80559210: lh          $t1, 0xED4($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(363, 0X9384));
    // 0x80559214: lui         $t3, 0x8056
    ctx->r11 = S32(RELOC_HI16(363, 0X938C) << 16);
    // 0x80559218: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8055921C: sh          $t1, 0x144($t2)
    MEM_H(0X144, ctx->r10) = ctx->r9;
    // 0x80559220: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80559224: lh          $t3, 0xEDC($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(363, 0X938C));
    // 0x80559228: lui         $t5, 0x8056
    ctx->r13 = S32(RELOC_HI16(363, 0X9394) << 16);
    // 0x8055922C: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80559230: sh          $t3, 0x144($t4)
    MEM_H(0X144, ctx->r12) = ctx->r11;
    // 0x80559234: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80559238: lh          $t5, 0xEE4($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(363, 0X9394));
    // 0x8055923C: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(363, 0X939C) << 16);
    // 0x80559240: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x80559244: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
    // 0x80559248: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8055924C: lh          $t7, 0xEEC($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(363, 0X939C));
    // 0x80559250: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(363, 0X93A4) << 16);
    // 0x80559254: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80559258: sh          $t7, 0x144($t8)
    MEM_H(0X144, ctx->r24) = ctx->r15;
    // 0x8055925C: lw          $t0, 0x24($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X24);
    // 0x80559260: lh          $t9, 0xEF4($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(363, 0X93A4));
    // 0x80559264: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x80559268: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8055926C: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80559270: b           L_805592EC
    // 0x80559274: sh          $t2, 0x144($t3)
    MEM_H(0X144, ctx->r11) = ctx->r10;
        goto L_805592EC;
    // 0x80559274: sh          $t2, 0x144($t3)
    MEM_H(0X144, ctx->r11) = ctx->r10;
L_80559278:
    // 0x80559278: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8055927C: lui         $t4, 0x8056
    ctx->r12 = S32(RELOC_HI16(363, 0X935C) << 16);
    // 0x80559280: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80559284: lh          $t4, 0xEAC($t4)
    ctx->r12 = MEM_H(ctx->r12, (int16_t)RELOC_LO16(363, 0X935C));
    // 0x80559288: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8055928C: lui         $t6, 0x8056
    ctx->r14 = S32(RELOC_HI16(363, 0X9364) << 16);
    // 0x80559290: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x80559294: sh          $t4, 0x144($t5)
    MEM_H(0X144, ctx->r13) = ctx->r12;
    // 0x80559298: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8055929C: lh          $t6, 0xEB4($t6)
    ctx->r14 = MEM_H(ctx->r14, (int16_t)RELOC_LO16(363, 0X9364));
    // 0x805592A0: lui         $t8, 0x8056
    ctx->r24 = S32(RELOC_HI16(363, 0X936C) << 16);
    // 0x805592A4: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x805592A8: sh          $t6, 0x144($t7)
    MEM_H(0X144, ctx->r15) = ctx->r14;
    // 0x805592AC: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x805592B0: lh          $t8, 0xEBC($t8)
    ctx->r24 = MEM_H(ctx->r24, (int16_t)RELOC_LO16(363, 0X936C));
    // 0x805592B4: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(363, 0X9374) << 16);
    // 0x805592B8: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x805592BC: sh          $t8, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r24;
    // 0x805592C0: lw          $t1, 0xC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XC);
    // 0x805592C4: lh          $t9, 0xEC4($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(363, 0X9374));
    // 0x805592C8: lui         $t2, 0x8056
    ctx->r10 = S32(RELOC_HI16(363, 0X937C) << 16);
    // 0x805592CC: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x805592D0: sh          $t9, 0x144($t1)
    MEM_H(0X144, ctx->r9) = ctx->r25;
    // 0x805592D4: lw          $t3, 0x24($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X24);
    // 0x805592D8: lh          $t2, 0xECC($t2)
    ctx->r10 = MEM_H(ctx->r10, (int16_t)RELOC_LO16(363, 0X937C));
    // 0x805592DC: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x805592E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x805592E4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x805592E8: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
L_805592EC:
    // 0x805592EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805592F0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805592F4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805592F8: jr          $ra
    // 0x805592FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x805592FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80559300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559300: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80559304: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80559308: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8055930C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80559310: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80559314: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80559318: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8055931C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80559320: lw          $s0, 0x130($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X130);
    // 0x80559324: jal         0x80048F84
    // 0x80559328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8055932C: jal         0x805580E8
    // 0x80559330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80559330: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80559334: jal         0x805582E0
    // 0x80559338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_805582E0(rdram, ctx);
        goto after_2;
    // 0x80559338: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8055933C: beq         $v0, $zero, L_80559380
    if (ctx->r2 == 0) {
        // 0x80559340: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80559380;
    }
    // 0x80559340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559344: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80559348: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8055934C: jal         0x80559928
    // 0x80559350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80559928(rdram, ctx);
        goto after_3;
    // 0x80559350: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80559354: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80559358: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8055935C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559360: lwc1        $f4, 0x44($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80559364: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80559368: swc1        $f4, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f4.u32l;
    // 0x8055936C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80559370: jal         0x805582E0
    // 0x80559374: swc1        $f0, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f0.u32l;
    func_805582E0(rdram, ctx);
        goto after_4;
    // 0x80559374: swc1        $f0, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f0.u32l;
    after_4:
    // 0x80559378: b           L_805593FC
    // 0x8055937C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805593FC;
    // 0x8055937C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80559380:
    // 0x80559380: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80559384: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(363, 0X9384) << 16);
    // 0x80559388: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8055938C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80559390: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80559394: lh          $t9, 0xED4($t9)
    ctx->r25 = MEM_H(ctx->r25, (int16_t)RELOC_LO16(363, 0X9384));
    // 0x80559398: lui         $t1, 0x8056
    ctx->r9 = S32(RELOC_HI16(363, 0X938C) << 16);
    // 0x8055939C: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x805593A0: sh          $t9, 0x144($t0)
    MEM_H(0X144, ctx->r8) = ctx->r25;
    // 0x805593A4: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x805593A8: lh          $t1, 0xEDC($t1)
    ctx->r9 = MEM_H(ctx->r9, (int16_t)RELOC_LO16(363, 0X938C));
    // 0x805593AC: lui         $t3, 0x8056
    ctx->r11 = S32(RELOC_HI16(363, 0X9394) << 16);
    // 0x805593B0: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x805593B4: sh          $t1, 0x144($t2)
    MEM_H(0X144, ctx->r10) = ctx->r9;
    // 0x805593B8: lw          $t4, 0x8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X8);
    // 0x805593BC: lh          $t3, 0xEE4($t3)
    ctx->r11 = MEM_H(ctx->r11, (int16_t)RELOC_LO16(363, 0X9394));
    // 0x805593C0: lui         $t5, 0x8056
    ctx->r13 = S32(RELOC_HI16(363, 0X939C) << 16);
    // 0x805593C4: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x805593C8: sh          $t3, 0x144($t4)
    MEM_H(0X144, ctx->r12) = ctx->r11;
    // 0x805593CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x805593D0: lh          $t5, 0xEEC($t5)
    ctx->r13 = MEM_H(ctx->r13, (int16_t)RELOC_LO16(363, 0X939C));
    // 0x805593D4: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(363, 0X93A4) << 16);
    // 0x805593D8: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x805593DC: sh          $t5, 0x144($t6)
    MEM_H(0X144, ctx->r14) = ctx->r13;
    // 0x805593E0: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x805593E4: lh          $t7, 0xEF4($t7)
    ctx->r15 = MEM_H(ctx->r15, (int16_t)RELOC_LO16(363, 0X93A4));
    // 0x805593E8: lw          $t1, 0x10($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X10);
    // 0x805593EC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805593F0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805593F4: sh          $t0, 0x144($t1)
    MEM_H(0X144, ctx->r9) = ctx->r8;
    // 0x805593F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805593FC:
    // 0x805593FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80559400: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80559404: jr          $ra
    // 0x80559408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80559408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8045243C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045243C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80452440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80452444: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452448: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045244C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80452450: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80452454: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80452458: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045245C: lwc1        $f4, 0x6CE0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X6CE0);
    // 0x80452460: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452464: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80452468: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045246C: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x80452470: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452474: ori         $at, $at, 0x6EA4
    ctx->r1 = ctx->r1 | 0X6EA4;
    // 0x80452478: swc1        $f8, 0x6CE0($v1)
    MEM_W(0X6CE0, ctx->r3) = ctx->f8.u32l;
    // 0x8045247C: lw          $t6, -0x71A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X71A8);
    // 0x80452480: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x80452484: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80452488: srl         $t8, $t7, 30
    ctx->r24 = S32(U32(ctx->r15) >> 30);
    // 0x8045248C: bne         $t8, $zero, L_804524BC
    if (ctx->r24 != 0) {
        // 0x80452490: nop
    
            goto L_804524BC;
    }
    // 0x80452490: nop

    // 0x80452494: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80452498: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x8045249C: addu        $a1, $v0, $at
    ctx->r5 = ADD32(ctx->r2, ctx->r1);
    // 0x804524A0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x804524A4: ori         $at, $at, 0x6EA4
    ctx->r1 = ctx->r1 | 0X6EA4;
    // 0x804524A8: addu        $a2, $v0, $at
    ctx->r6 = ADD32(ctx->r2, ctx->r1);
    // 0x804524AC: jal         0x80452154
    // 0x804524B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80452154(rdram, ctx);
        goto after_0;
    // 0x804524B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804524B4: b           L_804524C4
    // 0x804524B8: nop

        goto L_804524C4;
    // 0x804524B8: nop

L_804524BC:
    // 0x804524BC: jal         0x80451F38
    // 0x804524C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80451F38(rdram, ctx);
        goto after_1;
    // 0x804524C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
L_804524C4:
    // 0x804524C4: jal         0x804507C4
    // 0x804524C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804507C4(rdram, ctx);
        goto after_2;
    // 0x804524C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x804524CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804524D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804524D4: jr          $ra
    // 0x804524D8: nop

    return;
    // 0x804524D8: nop

;}
RECOMP_FUNC void func_805D7E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D7E30: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805D7E34: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805D7E38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805D7E3C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805D7E40: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805D7E44: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805D7E48: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805D7E4C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805D7E50: lui         $t1, 0x805E
    ctx->r9 = S32(RELOC_HI16(474, 0X24EC) << 16);
    // 0x805D7E54: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805D7E58: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805D7E5C: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805D7E60: lw          $t1, -0x6214($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(474, 0X24EC));
    // 0x805D7E64: jr          $ra
    // 0x805D7E68: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805D7E68: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804C246C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C246C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804C2470: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804C2474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804C2478: jal         0x804C2378
    // 0x804C247C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804C2378(rdram, ctx);
        goto after_0;
    // 0x804C247C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804C2480: bne         $v0, $zero, L_804C2498
    if (ctx->r2 != 0) {
        // 0x804C2484: lui         $t6, 0x8005
        ctx->r14 = S32(0X8005 << 16);
            goto L_804C2498;
    }
    // 0x804C2484: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x804C2488: jal         0x800445A4
    // 0x804C248C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x804C248C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804C2490: b           L_804C2504
    // 0x804C2494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C2504;
    // 0x804C2494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C2498:
    // 0x804C2498: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x804C249C: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x804C24A0: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(203, 0X1104) << 16);
    // 0x804C24A4: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x804C24A8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804C24AC: addiu       $t7, $t7, 0x2874
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(203, 0X1104));
    // 0x804C24B0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x804C24B4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804C24B8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804C24BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804C24C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C24C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804C24C8: jal         0x804C2514
    // 0x804C24CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804C2514(rdram, ctx);
        goto after_2;
    // 0x804C24CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x804C24D0: jal         0x804C2454
    // 0x804C24D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C2454(rdram, ctx);
        goto after_3;
    // 0x804C24D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804C24D8: jal         0x804C23BC
    // 0x804C24DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C23BC(rdram, ctx);
        goto after_4;
    // 0x804C24DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804C24E0: bne         $v0, $zero, L_804C24F8
    if (ctx->r2 != 0) {
        // 0x804C24E4: nop
    
            goto L_804C24F8;
    }
    // 0x804C24E4: nop

    // 0x804C24E8: jal         0x800445A4
    // 0x804C24EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804C24EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804C24F0: b           L_804C2504
    // 0x804C24F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804C2504;
    // 0x804C24F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C24F8:
    // 0x804C24F8: jal         0x804C22D8
    // 0x804C24FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804C22D8(rdram, ctx);
        goto after_6;
    // 0x804C24FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804C2500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804C2504:
    // 0x804C2504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804C2508: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804C250C: jr          $ra
    // 0x804C2510: nop

    return;
    // 0x804C2510: nop

;}
RECOMP_FUNC void func_805808C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805808C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805808C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805808CC: jal         0x80580868
    // 0x805808D0: nop

    func_80580868(rdram, ctx);
        goto after_0;
    // 0x805808D0: nop

    after_0:
    // 0x805808D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805808D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805808DC: jr          $ra
    // 0x805808E0: nop

    return;
    // 0x805808E0: nop

;}
RECOMP_FUNC void func_80527A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80527A98: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x80527A9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80527AA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80527AA4: lwc1        $f0, 0x30($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80527AA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80527AAC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80527AB0: nop

    // 0x80527AB4: bc1fl       L_80527B04
    if (!c1cs) {
        // 0x80527AB8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80527B04;
    }
    goto skip_0;
    // 0x80527AB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80527ABC: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80527AC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80527AC4: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80527AC8: sw          $v0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r2;
    // 0x80527ACC: blez        $v0, L_80527AE4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80527AD0: swc1        $f6, 0x30($a1)
        MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
            goto L_80527AE4;
    }
    // 0x80527AD0: swc1        $f6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f6.u32l;
    // 0x80527AD4: jal         0x80526C4C
    // 0x80527AD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_80526C4C(rdram, ctx);
        goto after_0;
    // 0x80527AD8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80527ADC: b           L_80527B14
    // 0x80527AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527B14;
    // 0x80527AE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527AE4:
    // 0x80527AE4: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80527AE8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80527AEC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80527AF0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80527AF4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80527AF8: b           L_80527B10
    // 0x80527AFC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
        goto L_80527B10;
    // 0x80527AFC: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80527B00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80527B04:
    // 0x80527B04: nop

    // 0x80527B08: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80527B0C: swc1        $f10, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f10.u32l;
L_80527B10:
    // 0x80527B10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527B14:
    // 0x80527B14: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527B18: jr          $ra
    // 0x80527B1C: nop

    return;
    // 0x80527B1C: nop

;}
RECOMP_FUNC void func_80036900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036900: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80036904: addu        $v1, $a0, $t6
    ctx->r3 = ADD32(ctx->r4, ctx->r14);
    // 0x80036908: lw          $v0, 0x130($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X130);
    // 0x8003690C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80036910: beq         $at, $zero, L_8003691C
    if (ctx->r1 == 0) {
        // 0x80036914: nop
    
            goto L_8003691C;
    }
    // 0x80036914: nop

    // 0x80036918: sw          $a1, 0x130($v1)
    MEM_W(0X130, ctx->r3) = ctx->r5;
L_8003691C:
    // 0x8003691C: jr          $ra
    // 0x80036920: nop

    return;
    // 0x80036920: nop

;}
RECOMP_FUNC void func_8044A558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A558: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8044A55C: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x8044A560: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044A564: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x8044A568: lw          $t6, 0x6A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A28);
    // 0x8044A56C: ori         $at, $at, 0x6A20
    ctx->r1 = ctx->r1 | 0X6A20;
    // 0x8044A570: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8044A574: bne         $a1, $t6, L_8044A584
    if (ctx->r5 != ctx->r14) {
        // 0x8044A578: addu        $v1, $v0, $at
        ctx->r3 = ADD32(ctx->r2, ctx->r1);
            goto L_8044A584;
    }
    // 0x8044A578: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x8044A57C: b           L_8044A5B0
    // 0x8044A580: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8044A5B0;
    // 0x8044A580: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8044A584:
    // 0x8044A584: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8044A588: bnel        $a1, $t7, L_8044A59C
    if (ctx->r5 != ctx->r15) {
        // 0x8044A58C: lw          $t8, 0x4($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X4);
            goto L_8044A59C;
    }
    goto skip_0;
    // 0x8044A58C: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x8044A590: b           L_8044A5B0
    // 0x8044A594: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8044A5B0;
    // 0x8044A594: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8044A598: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
L_8044A59C:
    // 0x8044A59C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8044A5A0: bne         $a1, $t8, L_8044A5B0
    if (ctx->r5 != ctx->r24) {
        // 0x8044A5A4: nop
    
            goto L_8044A5B0;
    }
    // 0x8044A5A4: nop

    // 0x8044A5A8: b           L_8044A5B0
    // 0x8044A5AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8044A5B0;
    // 0x8044A5AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8044A5B0:
    // 0x8044A5B0: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8044A5B4: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8044A5B8: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8044A5BC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8044A5C0: lw          $t1, 0x6A2C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A2C);
    // 0x8044A5C4: jr          $ra
    // 0x8044A5C8: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    return;
    // 0x8044A5C8: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
;}
RECOMP_FUNC void func_80058C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058C7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80058C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058C84: jal         0x80052CA0
    // 0x80058C88: nop

    func_80052CA0(rdram, ctx);
        goto after_0;
    // 0x80058C88: nop

    after_0:
    // 0x80058C8C: jal         0x800581F0
    // 0x80058C90: nop

    func_800581F0(rdram, ctx);
        goto after_1;
    // 0x80058C90: nop

    after_1:
    // 0x80058C94: jal         0x8005896C
    // 0x80058C98: nop

    func_8005896C(rdram, ctx);
        goto after_2;
    // 0x80058C98: nop

    after_2:
    // 0x80058C9C: jal         0x80058B18
    // 0x80058CA0: nop

    func_80058B18(rdram, ctx);
        goto after_3;
    // 0x80058CA0: nop

    after_3:
    // 0x80058CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058CA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80058CAC: jr          $ra
    // 0x80058CB0: nop

    return;
    // 0x80058CB0: nop

    // 0x80058CB4: nop

    // 0x80058CB8: nop

    // 0x80058CBC: nop

;}
RECOMP_FUNC void func_806F1DDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1DDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F1DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F1DE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F1DE8: jal         0x806F1D80
    // 0x806F1DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806F1D80(rdram, ctx);
        goto after_0;
    // 0x806F1DEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806F1DF0: bnel        $v0, $zero, L_806F1E0C
    if (ctx->r2 != 0) {
        // 0x806F1DF4: lw          $t6, 0x1F4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1F4);
            goto L_806F1E0C;
    }
    goto skip_0;
    // 0x806F1DF4: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x806F1DF8: jal         0x800445A4
    // 0x806F1DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F1DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F1E00: b           L_806F1F04
    // 0x806F1E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1F04;
    // 0x806F1E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F1E08: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
L_806F1E0C:
    // 0x806F1E0C: lui         $v0, 0x806F
    ctx->r2 = S32(RELOC_HI16(679, 0X1970) << 16);
    // 0x806F1E10: addiu       $v0, $v0, 0x2EF0
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(679, 0X1970));
    // 0x806F1E14: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806F1E18: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x806F1E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1E20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F1E24: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x806F1E28: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806F1E2C: jal         0x806F1DC4
    // 0x806F1E30: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    func_806F1DC4(rdram, ctx);
        goto after_2;
    // 0x806F1E30: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x806F1E34: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x806F1E38: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x806F1E3C: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x806F1E40: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(679, 0X1A30) << 16);
    // 0x806F1E44: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x806F1E48: addiu       $t8, $t8, 0x2FB0
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(679, 0X1A30));
    // 0x806F1E4C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x806F1E50: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x806F1E54: addiu       $at, $zero, 0x45E6
    ctx->r1 = ADD32(0, 0X45E6);
    // 0x806F1E58: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F1E5C: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806F1E60: beq         $v0, $at, L_806F1E88
    if (ctx->r2 == ctx->r1) {
        // 0x806F1E64: sh          $zero, 0x144($s0)
        MEM_H(0X144, ctx->r16) = 0;
            goto L_806F1E88;
    }
    // 0x806F1E64: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806F1E68: addiu       $at, $zero, 0x460E
    ctx->r1 = ADD32(0, 0X460E);
    // 0x806F1E6C: beq         $v0, $at, L_806F1EA8
    if (ctx->r2 == ctx->r1) {
        // 0x806F1E70: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_806F1EA8;
    }
    // 0x806F1E70: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F1E74: addiu       $at, $zero, 0x460F
    ctx->r1 = ADD32(0, 0X460F);
    // 0x806F1E78: beq         $v0, $at, L_806F1ED0
    if (ctx->r2 == ctx->r1) {
        // 0x806F1E7C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_806F1ED0;
    }
    // 0x806F1E7C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x806F1E80: b           L_806F1F04
    // 0x806F1E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1F04;
    // 0x806F1E84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1E88:
    // 0x806F1E88: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F1E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1E90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1E94: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F1E98: jal         0x806F1F14
    // 0x806F1E9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F1F14(rdram, ctx);
        goto after_3;
    // 0x806F1E9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806F1EA0: b           L_806F1F04
    // 0x806F1EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1F04;
    // 0x806F1EA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1EA8:
    // 0x806F1EA8: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x806F1EAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F1EB8: jal         0x806F1F14
    // 0x806F1EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F1F14(rdram, ctx);
        goto after_4;
    // 0x806F1EBC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x806F1EC0: jal         0x8005FE48
    // 0x806F1EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_5;
    // 0x806F1EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806F1EC8: b           L_806F1F04
    // 0x806F1ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F1F04;
    // 0x806F1ECC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1ED0:
    // 0x806F1ED0: sb          $t1, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r9;
    // 0x806F1ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F1ED8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F1EDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806F1EE0: jal         0x806F1F14
    // 0x806F1EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F1F14(rdram, ctx);
        goto after_6;
    // 0x806F1EE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x806F1EE8: jal         0x8005FE48
    // 0x806F1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FE48(rdram, ctx);
        goto after_7;
    // 0x806F1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x806F1EF0: lbu         $t2, 0xE($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0XE);
    // 0x806F1EF4: andi        $t3, $t2, 0xFF03
    ctx->r11 = ctx->r10 & 0XFF03;
    // 0x806F1EF8: ori         $t4, $t3, 0x18
    ctx->r12 = ctx->r11 | 0X18;
    // 0x806F1EFC: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
    // 0x806F1F00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F1F04:
    // 0x806F1F04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F1F08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F1F0C: jr          $ra
    // 0x806F1F10: nop

    return;
    // 0x806F1F10: nop

;}
RECOMP_FUNC void func_80475D20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80475D24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80475D28: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80475D2C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80475D30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80475D34: lui         $a2, 0x804A
    ctx->r6 = S32(RELOC_HI16(164, 0X26DC8) << 16);
    // 0x80475D38: addiu       $a2, $a2, -0x4A78
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(164, 0X26DC8));
    // 0x80475D3C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80475D40: jal         0x80475B40
    // 0x80475D44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_80475B40(rdram, ctx);
        goto after_0;
    // 0x80475D44: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80475D48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80475D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80475D50: jr          $ra
    // 0x80475D54: nop

    return;
    // 0x80475D54: nop

;}
RECOMP_FUNC void func_8078EB00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EB00: lui         $v0, 0x8079
    ctx->r2 = S32(RELOC_HI16(811, 0X4E8) << 16);
    // 0x8078EB04: addiu       $v0, $v0, -0x1018
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(811, 0X4E8));
    // 0x8078EB08: jr          $ra
    // 0x8078EB0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8078EB0C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_804CC61C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC61C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x804CC620: lui         $t7, 0x804D
    ctx->r15 = S32(RELOC_HI16(237, 0X1BE0) << 16);
    // 0x804CC624: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CC628: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CC62C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x804CC630: addiu       $t7, $t7, -0x1FB0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(237, 0X1BE0));
    // 0x804CC634: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x804CC638: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x804CC63C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x804CC640: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x804CC644: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x804CC648: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CC64C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x804CC650: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x804CC654: jal         0x80051194
    // 0x804CC658: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804CC658: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x804CC65C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804CC660: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x804CC664: jal         0x804CC8EC
    // 0x804CC668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CC8EC(rdram, ctx);
        goto after_1;
    // 0x804CC668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CC66C: beq         $v0, $zero, L_804CC780
    if (ctx->r2 == 0) {
        // 0x804CC670: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CC780;
    }
    // 0x804CC670: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC674: jal         0x804CC9B0
    // 0x804CC678: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    func_804CC9B0(rdram, ctx);
        goto after_2;
    // 0x804CC678: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_2:
    // 0x804CC67C: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x804CC680: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(237, 0X844) << 16);
    // 0x804CC684: addiu       $t0, $t0, -0x334C
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(237, 0X844));
    // 0x804CC688: sw          $t0, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r8;
    // 0x804CC68C: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x804CC690: lui         $t2, 0x804D
    ctx->r10 = S32(RELOC_HI16(237, 0X1BB4) << 16);
    // 0x804CC694: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804CC698: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804CC69C: addiu       $t2, $t2, -0x1FDC
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(237, 0X1BB4));
    // 0x804CC6A0: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x804CC6A4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804CC6A8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804CC6AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC6B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CC6B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CC6B8: jal         0x804CDF54
    // 0x804CC6BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CDF54(rdram, ctx);
        goto after_3;
    // 0x804CC6BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804CC6C0: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x804CC6C4: lui         $t4, 0x804D
    ctx->r12 = S32(RELOC_HI16(237, 0XF20) << 16);
    // 0x804CC6C8: addiu       $t4, $t4, -0x2C70
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(237, 0XF20));
    // 0x804CC6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC6D0: jal         0x804CC548
    // 0x804CC6D4: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    func_804CC548(rdram, ctx);
        goto after_4;
    // 0x804CC6D4: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    after_4:
    // 0x804CC6D8: lui         $at, 0xC1F8
    ctx->r1 = S32(0XC1F8 << 16);
    // 0x804CC6DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804CC6E0: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x804CC6E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x804CC6E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC6EC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x804CC6F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x804CC6F4: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x804CC6F8: jal         0x804CC830
    // 0x804CC6FC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_804CC830(rdram, ctx);
        goto after_5;
    // 0x804CC6FC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x804CC700: bne         $v0, $zero, L_804CC718
    if (ctx->r2 != 0) {
        // 0x804CC704: lw          $t6, 0x34($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X34);
            goto L_804CC718;
    }
    // 0x804CC704: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x804CC708: jal         0x800445A4
    // 0x804CC70C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x804CC70C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804CC710: b           L_804CC78C
    // 0x804CC714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CC78C;
    // 0x804CC714: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CC718:
    // 0x804CC718: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804CC71C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804CC720: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x804CC724: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x804CC728: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804CC72C: bgez        $t7, L_804CC744
    if (SIGNED(ctx->r15) >= 0) {
        // 0x804CC730: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_804CC744;
    }
    // 0x804CC730: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804CC734: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x804CC738: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804CC73C: nop

    // 0x804CC740: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_804CC744:
    // 0x804CC744: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x804CC748: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x804CC74C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x804CC750: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC754: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x804CC758: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x804CC75C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CC760: jal         0x804CC830
    // 0x804CC764: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    func_804CC830(rdram, ctx);
        goto after_7;
    // 0x804CC764: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x804CC768: bnel        $v0, $zero, L_804CC78C
    if (ctx->r2 != 0) {
        // 0x804CC76C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804CC78C;
    }
    goto skip_0;
    // 0x804CC76C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804CC770: jal         0x800445A4
    // 0x804CC774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x804CC774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x804CC778: b           L_804CC78C
    // 0x804CC77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CC78C;
    // 0x804CC77C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CC780:
    // 0x804CC780: jal         0x800445A4
    // 0x804CC784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x804CC784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x804CC788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CC78C:
    // 0x804CC78C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CC790: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x804CC794: jr          $ra
    // 0x804CC798: nop

    return;
    // 0x804CC798: nop

;}
RECOMP_FUNC void func_8046DD3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8046DD3C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8046DD40: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8046DD44: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8046DD48: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8046DD4C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8046DD50: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8046DD54: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8046DD58: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8046DD5C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8046DD60: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8046DD64: jr          $ra
    // 0x8046DD68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8046DD68: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806FA6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA6F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806FA6F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806FA6F8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806FA6FC: addiu       $a1, $zero, 0x14D0
    ctx->r5 = ADD32(0, 0X14D0);
    // 0x806FA700: bnel        $t6, $zero, L_806FA728
    if (ctx->r14 != 0) {
        // 0x806FA704: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806FA728;
    }
    goto skip_0;
    // 0x806FA704: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806FA708: jal         0x80045A34
    // 0x806FA70C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806FA70C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806FA710: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806FA714: bne         $v0, $zero, L_806FA724
    if (ctx->r2 != 0) {
        // 0x806FA718: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_806FA724;
    }
    // 0x806FA718: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x806FA71C: b           L_806FA728
    // 0x806FA720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806FA728;
    // 0x806FA720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806FA724:
    // 0x806FA724: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806FA728:
    // 0x806FA728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806FA72C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806FA730: jr          $ra
    // 0x806FA734: nop

    return;
    // 0x806FA734: nop

;}
RECOMP_FUNC void func_80076DB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076DB8: addiu       $t6, $a2, 0x2
    ctx->r14 = ADD32(ctx->r6, 0X2);
    // 0x80076DBC: sllv        $v1, $a3, $t6
    ctx->r3 = S32(ctx->r7 << (ctx->r14 & 31));
    // 0x80076DC0: addiu       $v1, $v1, 0x3F
    ctx->r3 = ADD32(ctx->r3, 0X3F);
    // 0x80076DC4: addiu       $at, $zero, -0x40
    ctx->r1 = ADD32(0, -0X40);
    // 0x80076DC8: and         $v1, $v1, $at
    ctx->r3 = ctx->r3 & ctx->r1;
    // 0x80076DCC: sra         $t0, $v1, 6
    ctx->r8 = S32(SIGNED(ctx->r3) >> 6);
    // 0x80076DD0: slti        $at, $t0, 0x21
    ctx->r1 = SIGNED(ctx->r8) < 0X21 ? 1 : 0;
    // 0x80076DD4: beq         $at, $zero, L_80076DF0
    if (ctx->r1 == 0) {
        // 0x80076DD8: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80076DF0;
    }
    // 0x80076DD8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80076DDC: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x80076DE0: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x80076DE4: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80076DE8: b           L_80076E20
    // 0x80076DEC: lh          $a2, -0x7A10($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X7A10);
        goto L_80076E20;
    // 0x80076DEC: lh          $a2, -0x7A10($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X7A10);
L_80076DF0:
    // 0x80076DF0: addiu       $t8, $t0, 0x7FF
    ctx->r24 = ADD32(ctx->r8, 0X7FF);
    // 0x80076DF4: div         $zero, $t8, $t0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r8)));
    // 0x80076DF8: mflo        $a2
    ctx->r6 = lo;
    // 0x80076DFC: bne         $t0, $zero, L_80076E08
    if (ctx->r8 != 0) {
        // 0x80076E00: nop
    
            goto L_80076E08;
    }
    // 0x80076E00: nop

    // 0x80076E04: break       7
    do_break(2147970564);
L_80076E08:
    // 0x80076E08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80076E0C: bne         $t0, $at, L_80076E20
    if (ctx->r8 != ctx->r1) {
        // 0x80076E10: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80076E20;
    }
    // 0x80076E10: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80076E14: bne         $t8, $at, L_80076E20
    if (ctx->r24 != ctx->r1) {
        // 0x80076E18: nop
    
            goto L_80076E20;
    }
    // 0x80076E18: nop

    // 0x80076E1C: break       6
    do_break(2147970588);
L_80076E20:
    // 0x80076E20: lui         $t5, 0x700
    ctx->r13 = S32(0X700 << 16);
    // 0x80076E24: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80076E28: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x80076E2C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80076E30: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x80076E34: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076E38: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x80076E3C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80076E40: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80076E44: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x80076E48: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80076E4C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80076E50: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x80076E54: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076E58: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80076E5C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80076E60: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80076E64: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x80076E68: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076E6C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80076E70: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80076E74: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80076E78: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x80076E7C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80076E80: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80076E84: addiu       $v1, $zero, 0x7FF
    ctx->r3 = ADD32(0, 0X7FF);
    // 0x80076E88: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80076E8C: mflo        $t3
    ctx->r11 = lo;
    // 0x80076E90: sra         $t3, $t3, 4
    ctx->r11 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80076E94: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80076E98: slti        $at, $t4, 0x7FF
    ctx->r1 = SIGNED(ctx->r12) < 0X7FF ? 1 : 0;
    // 0x80076E9C: beq         $at, $zero, L_80076EAC
    if (ctx->r1 == 0) {
        // 0x80076EA0: nop
    
            goto L_80076EAC;
    }
    // 0x80076EA0: nop

    // 0x80076EA4: b           L_80076EAC
    // 0x80076EA8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
        goto L_80076EAC;
    // 0x80076EA8: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_80076EAC:
    // 0x80076EAC: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x80076EB0: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80076EB4: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80076EB8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80076EBC: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80076EC0: slti        $at, $t3, 0x801
    ctx->r1 = SIGNED(ctx->r11) < 0X801 ? 1 : 0;
    // 0x80076EC4: bne         $at, $zero, L_80076ED0
    if (ctx->r1 != 0) {
        // 0x80076EC8: lui         $at, 0x800B
        ctx->r1 = S32(0X800B << 16);
            goto L_80076ED0;
    }
    // 0x80076EC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80076ECC: sw          $zero, -0x7A18($at)
    MEM_W(-0X7A18, ctx->r1) = 0;
L_80076ED0:
    // 0x80076ED0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80076ED4: jr          $ra
    // 0x80076ED8: nop

    return;
    // 0x80076ED8: nop

;}
RECOMP_FUNC void func_80060798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060798: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006079C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800607A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800607A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800607A8: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x800607AC: jal         0x8005FEBC
    // 0x800607B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    func_8005FEBC(rdram, ctx);
        goto after_0;
    // 0x800607B0: lw          $a0, 0x3C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3C);
    after_0:
    // 0x800607B4: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x800607B8: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800607BC: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x800607C0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800607C4: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800607C8: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800607CC: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x800607D0: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800607D4: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800607D8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800607DC: lwc1        $f10, 0x4($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X4);
    // 0x800607E0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800607E4: lwc1        $f6, 0x88($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X88);
    // 0x800607E8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800607EC: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800607F0: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800607F4: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800607F8: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800607FC: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80060800: nop

    // 0x80060804: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80060808: nop

    // 0x8006080C: mul.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x80060810: sub.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80060814: swc1        $f12, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f12.u32l;
    // 0x80060818: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006081C: jal         0x80065954
    // 0x80060820: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x80060820: swc1        $f6, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x80060824: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80060828: lwc1        $f12, 0x80($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8006082C: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80060830: jal         0x80065954
    // 0x80060834: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x80060834: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80060838: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8006083C: lw          $t0, 0x3C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X3C);
    // 0x80060840: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80060844: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80060848: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    // 0x8006084C: lwc1        $f4, 0x8C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x80060850: jal         0x80065954
    // 0x80060854: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x80060854: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    after_3:
    // 0x80060858: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8006085C: lwc1        $f4, 0x64($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80060860: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80060864: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80060868: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8006086C: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80060870: bc1f        L_8006087C
    if (!c1cs) {
        // 0x80060874: swc1        $f6, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
            goto L_8006087C;
    }
    // 0x80060874: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80060878: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006087C:
    // 0x8006087C: beq         $v1, $zero, L_800608C4
    if (ctx->r3 == 0) {
        // 0x80060880: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800608C4;
    }
    // 0x80060880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80060884: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80060888: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006088C: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80060890: nop

    // 0x80060894: bc1f        L_800608A0
    if (!c1cs) {
        // 0x80060898: nop
    
            goto L_800608A0;
    }
    // 0x80060898: nop

    // 0x8006089C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800608A0:
    // 0x800608A0: beql        $v1, $zero, L_800608C8
    if (ctx->r3 == 0) {
        // 0x800608A4: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_800608C8;
    }
    goto skip_0;
    // 0x800608A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x800608A8: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x800608AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800608B0: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x800608B4: nop

    // 0x800608B8: bc1fl       L_800608C8
    if (!c1cs) {
        // 0x800608BC: lw          $s0, 0x18($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X18);
            goto L_800608C8;
    }
    goto skip_1;
    // 0x800608BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x800608C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800608C4:
    // 0x800608C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
L_800608C8:
    // 0x800608C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800608CC: jr          $ra
    // 0x800608D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800608D0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_8067BEDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067BEDC: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8067BEE0: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(541, 0X400) << 16);
    // 0x8067BEE4: addiu       $t6, $t6, -0x5F50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(541, 0X400));
    // 0x8067BEE8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8067BEEC: jr          $ra
    // 0x8067BEF0: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    return;
    // 0x8067BEF0: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80030D14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030D18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030D1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80030D20: lwc1        $f12, -0xC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XC);
    // 0x80030D24: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80030D28: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80030D2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80030D30: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80030D34: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80030D38: nop

    // 0x80030D3C: bc1t        L_80030D68
    if (c1cs) {
        // 0x80030D40: nop
    
            goto L_80030D68;
    }
    // 0x80030D40: nop

    // 0x80030D44: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80030D48: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80030D4C: nop

    // 0x80030D50: bc1t        L_80030D68
    if (c1cs) {
        // 0x80030D54: nop
    
            goto L_80030D68;
    }
    // 0x80030D54: nop

    // 0x80030D58: jal         0x8002CA68
    // 0x80030D5C: nop

    func_8002CA68(rdram, ctx);
        goto after_0;
    // 0x80030D5C: nop

    after_0:
    // 0x80030D60: b           L_80030D68
    // 0x80030D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030D68;
    // 0x80030D64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80030D68:
    // 0x80030D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030D70: jr          $ra
    // 0x80030D74: nop

    return;
    // 0x80030D74: nop

;}
RECOMP_FUNC void func_8042E490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E490: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8042E494: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8042E498: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8042E49C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8042E4A0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8042E4A4: ori         $at, $zero, 0x8CA0
    ctx->r1 = 0 | 0X8CA0;
    // 0x8042E4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E4AC: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8042E4B0: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042E4B4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8042E4B8: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8042E4BC: nop

    // 0x8042E4C0: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8042E4C4: mfhi        $t8
    ctx->r24 = hi;
    // 0x8042E4C8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8042E4CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042E4D0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8042E4D4: div.s       $f14, $f18, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8042E4D8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x8042E4DC: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x8042E4E0: bc1fl       L_8042E5C8
    if (!c1cs) {
        // 0x8042E4E4: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_8042E5C8;
    }
    goto skip_0;
    // 0x8042E4E4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_0:
    // 0x8042E4E8: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8042E4EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042E4F0: nop

    // 0x8042E4F4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8042E4F8: nop

    // 0x8042E4FC: bc1f        L_8042E564
    if (!c1cs) {
        // 0x8042E500: nop
    
            goto L_8042E564;
    }
    // 0x8042E500: nop

    // 0x8042E504: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8042E508: jal         0x80065954
    // 0x8042E50C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8042E50C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8042E510: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042E514: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042E518: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042E51C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042E520: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042E524: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8042E528: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8042E52C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8042E530: nop

    // 0x8042E534: bc1fl       L_8042E548
    if (!c1cs) {
        // 0x8042E538: add.s       $f12, $f14, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_8042E548;
    }
    goto skip_1;
    // 0x8042E538: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    skip_1:
    // 0x8042E53C: b           L_8042E548
    // 0x8042E540: add.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f2.fl;
        goto L_8042E548;
    // 0x8042E540: add.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8042E544: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
L_8042E548:
    // 0x8042E548: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042E54C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8042E550: nop

    // 0x8042E554: bc1fl       L_8042E6AC
    if (!c1cs) {
        // 0x8042E558: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E6AC;
    }
    goto skip_2;
    // 0x8042E558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8042E55C: b           L_8042E6A8
    // 0x8042E560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8042E6A8;
    // 0x8042E560: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8042E564:
    // 0x8042E564: jal         0x80065954
    // 0x8042E568: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8042E568: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8042E56C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042E570: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042E574: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042E578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8042E57C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8042E580: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8042E584: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8042E588: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042E58C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8042E590: nop

    // 0x8042E594: bc1fl       L_8042E5A8
    if (!c1cs) {
        // 0x8042E598: sub.s       $f12, $f14, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
            goto L_8042E5A8;
    }
    goto skip_3;
    // 0x8042E598: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    skip_3:
    // 0x8042E59C: b           L_8042E5A8
    // 0x8042E5A0: sub.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f2.fl;
        goto L_8042E5A8;
    // 0x8042E5A0: sub.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8042E5A4: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
L_8042E5A8:
    // 0x8042E5A8: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x8042E5AC: nop

    // 0x8042E5B0: bc1fl       L_8042E6AC
    if (!c1cs) {
        // 0x8042E5B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E6AC;
    }
    goto skip_4;
    // 0x8042E5B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x8042E5B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8042E5BC: b           L_8042E6A8
    // 0x8042E5C0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
        goto L_8042E6A8;
    // 0x8042E5C0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8042E5C4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_8042E5C8:
    // 0x8042E5C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8042E5CC: bc1fl       L_8042E6AC
    if (!c1cs) {
        // 0x8042E5D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E6AC;
    }
    goto skip_5;
    // 0x8042E5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8042E5D4: sub.s       $f12, $f14, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8042E5D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8042E5DC: nop

    // 0x8042E5E0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8042E5E4: nop

    // 0x8042E5E8: bc1f        L_8042E650
    if (!c1cs) {
        // 0x8042E5EC: nop
    
            goto L_8042E650;
    }
    // 0x8042E5EC: nop

    // 0x8042E5F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8042E5F4: jal         0x80065954
    // 0x8042E5F8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_2;
    // 0x8042E5F8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8042E5FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042E600: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042E604: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042E608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042E60C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8042E610: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8042E614: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8042E618: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8042E61C: nop

    // 0x8042E620: bc1fl       L_8042E634
    if (!c1cs) {
        // 0x8042E624: sub.s       $f12, $f14, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
            goto L_8042E634;
    }
    goto skip_6;
    // 0x8042E624: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    skip_6:
    // 0x8042E628: b           L_8042E634
    // 0x8042E62C: sub.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f2.fl;
        goto L_8042E634;
    // 0x8042E62C: sub.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8042E630: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
L_8042E634:
    // 0x8042E634: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8042E638: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8042E63C: nop

    // 0x8042E640: bc1fl       L_8042E6AC
    if (!c1cs) {
        // 0x8042E644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E6AC;
    }
    goto skip_7;
    // 0x8042E644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8042E648: b           L_8042E6A8
    // 0x8042E64C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8042E6A8;
    // 0x8042E64C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_8042E650:
    // 0x8042E650: jal         0x80065954
    // 0x8042E654: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    func_80065954(rdram, ctx);
        goto after_3;
    // 0x8042E654: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8042E658: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8042E65C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8042E660: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8042E664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8042E668: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8042E66C: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8042E670: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8042E674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8042E678: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8042E67C: nop

    // 0x8042E680: bc1fl       L_8042E694
    if (!c1cs) {
        // 0x8042E684: add.s       $f12, $f14, $f16
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_8042E694;
    }
    goto skip_8;
    // 0x8042E684: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    skip_8:
    // 0x8042E688: b           L_8042E694
    // 0x8042E68C: add.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f2.fl;
        goto L_8042E694;
    // 0x8042E68C: add.s       $f12, $f14, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8042E690: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
L_8042E694:
    // 0x8042E694: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8042E698: nop

    // 0x8042E69C: bc1fl       L_8042E6AC
    if (!c1cs) {
        // 0x8042E6A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042E6AC;
    }
    goto skip_9;
    // 0x8042E6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8042E6A4: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_8042E6A8:
    // 0x8042E6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042E6AC:
    // 0x8042E6AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8042E6B0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8042E6B4: jr          $ra
    // 0x8042E6B8: nop

    return;
    // 0x8042E6B8: nop

;}
RECOMP_FUNC void func_8078FD04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078FD04: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8078FD08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8078FD0C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8078FD10: lui         $t7, 0x8079
    ctx->r15 = S32(RELOC_HI16(814, 0XD88) << 16);
    // 0x8078FD14: sb          $v0, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r2;
    // 0x8078FD18: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8078FD1C: lw          $t7, -0xE8($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(814, 0XD88));
    // 0x8078FD20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8078FD24: bne         $v0, $at, L_8078FD44
    if (ctx->r2 != ctx->r1) {
        // 0x8078FD28: sw          $t7, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r15;
            goto L_8078FD44;
    }
    // 0x8078FD28: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8078FD2C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8078FD30: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8078FD34: lw          $t8, 0xF54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XF54);
    // 0x8078FD38: ori         $t9, $t8, 0x200
    ctx->r25 = ctx->r24 | 0X200;
    // 0x8078FD3C: jr          $ra
    // 0x8078FD40: sw          $t9, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r25;
    return;
    // 0x8078FD40: sw          $t9, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r25;
L_8078FD44:
    // 0x8078FD44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8078FD48: bne         $v0, $at, L_8078FD64
    if (ctx->r2 != ctx->r1) {
        // 0x8078FD4C: lui         $v0, 0x800F
        ctx->r2 = S32(0X800F << 16);
            goto L_8078FD64;
    }
    // 0x8078FD4C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8078FD50: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8078FD54: lw          $t0, 0xF54($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XF54);
    // 0x8078FD58: ori         $t1, $t0, 0x200
    ctx->r9 = ctx->r8 | 0X200;
    // 0x8078FD5C: jr          $ra
    // 0x8078FD60: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
    return;
    // 0x8078FD60: sw          $t1, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r9;
L_8078FD64:
    // 0x8078FD64: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8078FD68: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8078FD6C: lw          $t2, 0xF54($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XF54);
    // 0x8078FD70: addiu       $at, $zero, -0x201
    ctx->r1 = ADD32(0, -0X201);
    // 0x8078FD74: and         $t3, $t2, $at
    ctx->r11 = ctx->r10 & ctx->r1;
    // 0x8078FD78: sw          $t3, 0xF54($v0)
    MEM_W(0XF54, ctx->r2) = ctx->r11;
    // 0x8078FD7C: jr          $ra
    // 0x8078FD80: nop

    return;
    // 0x8078FD80: nop

;}
RECOMP_FUNC void func_806F725C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F725C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F7260: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F7264: jal         0x8004700C
    // 0x806F7268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806F7268: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F726C: beq         $v0, $zero, L_806F72B0
    if (ctx->r2 == 0) {
        // 0x806F7270: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806F72B0;
    }
    // 0x806F7270: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F7274: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x806F7278: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806F727C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x806F7280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7284: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806F7288: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806F728C: bc1f        L_806F72A8
    if (!c1cs) {
        // 0x806F7290: nop
    
            goto L_806F72A8;
    }
    // 0x806F7290: nop

    // 0x806F7294: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F7298: jal         0x806F73DC
    // 0x806F729C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_806F73DC(rdram, ctx);
        goto after_1;
    // 0x806F729C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x806F72A0: b           L_806F72B4
    // 0x806F72A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_806F72B4;
    // 0x806F72A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F72A8:
    // 0x806F72A8: jal         0x806F73DC
    // 0x806F72AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_806F73DC(rdram, ctx);
        goto after_2;
    // 0x806F72AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_806F72B0:
    // 0x806F72B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806F72B4:
    // 0x806F72B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F72B8: jr          $ra
    // 0x806F72BC: nop

    return;
    // 0x806F72BC: nop

;}
RECOMP_FUNC void func_805270C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805270C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805270CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805270D0: jal         0x80527D68
    // 0x805270D4: nop

    func_80527D68(rdram, ctx);
        goto after_0;
    // 0x805270D4: nop

    after_0:
    // 0x805270D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805270DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805270E0: jr          $ra
    // 0x805270E4: nop

    return;
    // 0x805270E4: nop

;}
RECOMP_FUNC void func_80051368(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051368: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005136C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80051370: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80051374: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80051378: beq         $a0, $at, L_800513E4
    if (ctx->r4 == ctx->r1) {
        // 0x8005137C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800513E4;
    }
    // 0x8005137C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80051380: jal         0x80051200
    // 0x80051384: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    func_80051200(rdram, ctx);
        goto after_0;
    // 0x80051384: sh          $a0, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r4;
    after_0:
    // 0x80051388: bne         $v0, $zero, L_800513E4
    if (ctx->r2 != 0) {
        // 0x8005138C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800513E4;
    }
    // 0x8005138C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80051390: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80051394: lw          $a1, -0x57D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X57D0);
    // 0x80051398: lw          $a0, -0x57CC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X57CC);
    // 0x8005139C: jal         0x80051258
    // 0x800513A0: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    func_80051258(rdram, ctx);
        goto after_1;
    // 0x800513A0: lhu         $a2, 0x1A($sp)
    ctx->r6 = MEM_HU(ctx->r29, 0X1A);
    after_1:
    // 0x800513A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800513A8: bne         $v0, $zero, L_800513E4
    if (ctx->r2 != 0) {
        // 0x800513AC: addiu       $a0, $a0, -0x57D0
        ctx->r4 = ADD32(ctx->r4, -0X57D0);
            goto L_800513E4;
    }
    // 0x800513AC: addiu       $a0, $a0, -0x57D0
    ctx->r4 = ADD32(ctx->r4, -0X57D0);
    // 0x800513B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800513B4: addiu       $v1, $v1, -0x57C8
    ctx->r3 = ADD32(ctx->r3, -0X57C8);
    // 0x800513B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800513BC: lhu         $t6, 0x1A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1A);
    // 0x800513C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800513C4: sh          $t6, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r14;
    // 0x800513C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800513CC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800513D0: addiu       $t9, $t8, 0x2
    ctx->r25 = ADD32(ctx->r24, 0X2);
    // 0x800513D4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800513D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800513DC: b           L_800513E8
    // 0x800513E0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_800513E8;
    // 0x800513E0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_800513E4:
    // 0x800513E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800513E8:
    // 0x800513E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800513EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800513F0: jr          $ra
    // 0x800513F4: nop

    return;
    // 0x800513F4: nop

;}
RECOMP_FUNC void func_80025EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025EA4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80025EA8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80025EAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80025EB0: lwc1        $f14, -0x274($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X274);
    // 0x80025EB4: lwc1        $f0, 0xAF0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XAF0);
    // 0x80025EB8: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80025EBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80025EC0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80025EC4: lwc1        $f2, 0x174($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X174);
    // 0x80025EC8: bc1tl       L_80025F24
    if (c1cs) {
        // 0x80025ECC: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80025F24;
    }
    goto skip_0;
    // 0x80025ECC: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_0:
    // 0x80025ED0: lwc1        $f16, -0x270($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X270);
    // 0x80025ED4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80025ED8: nop

    // 0x80025EDC: bc1tl       L_80025F24
    if (c1cs) {
        // 0x80025EE0: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80025F24;
    }
    goto skip_1;
    // 0x80025EE0: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_1:
    // 0x80025EE4: lwc1        $f12, 0xAE8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XAE8);
    // 0x80025EE8: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80025EEC: nop

    // 0x80025EF0: bc1tl       L_80025F24
    if (c1cs) {
        // 0x80025EF4: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80025F24;
    }
    goto skip_2;
    // 0x80025EF4: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_2:
    // 0x80025EF8: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80025EFC: nop

    // 0x80025F00: bc1tl       L_80025F24
    if (c1cs) {
        // 0x80025F04: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80025F24;
    }
    goto skip_3;
    // 0x80025F04: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_3:
    // 0x80025F08: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x80025F0C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80025F10: bnel        $t6, $zero, L_80025F24
    if (ctx->r14 != 0) {
        // 0x80025F14: lw          $t7, 0x138($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X138);
            goto L_80025F24;
    }
    goto skip_4;
    // 0x80025F14: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
    skip_4:
    // 0x80025F18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80025F1C: nop

    // 0x80025F20: lw          $t7, 0x138($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X138);
L_80025F24:
    // 0x80025F24: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80025F28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80025F2C: bne         $t7, $zero, L_80025F70
    if (ctx->r15 != 0) {
        // 0x80025F30: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80025F70;
    }
    // 0x80025F30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80025F34: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80025F38: nop

    // 0x80025F3C: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x80025F40: nop

    // 0x80025F44: bc1fl       L_80025F58
    if (!c1cs) {
        // 0x80025F48: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_80025F58;
    }
    goto skip_5;
    // 0x80025F48: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_5:
    // 0x80025F4C: b           L_80025F70
    // 0x80025F50: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
        goto L_80025F70;
    // 0x80025F50: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80025F54: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_80025F58:
    // 0x80025F58: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80025F5C: bc1fl       L_80025F74
    if (!c1cs) {
        // 0x80025F60: lwc1        $f4, 0x98($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
            goto L_80025F74;
    }
    goto skip_6;
    // 0x80025F60: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
    skip_6:
    // 0x80025F64: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80025F68: nop

    // 0x80025F6C: sub.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f0.fl;
L_80025F70:
    // 0x80025F70: lwc1        $f4, 0x98($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X98);
L_80025F74:
    // 0x80025F74: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80025F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80025F7C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80025F80: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80025F84: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80025F88: nop

    // 0x80025F8C: bc1fl       L_80025FB4
    if (!c1cs) {
        // 0x80025F90: c.le.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
            goto L_80025FB4;
    }
    goto skip_7;
    // 0x80025F90: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    skip_7:
    // 0x80025F94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80025F98: nop

    // 0x80025F9C: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
L_80025FA0:
    // 0x80025FA0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80025FA4: nop

    // 0x80025FA8: bc1tl       L_80025FA0
    if (c1cs) {
        // 0x80025FAC: sub.s       $f0, $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
            goto L_80025FA0;
    }
    goto skip_8;
    // 0x80025FAC: sub.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f14.fl;
    skip_8:
    // 0x80025FB0: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
L_80025FB4:
    // 0x80025FB4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80025FB8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80025FBC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80025FC0: bc1fl       L_80025FE0
    if (!c1cs) {
        // 0x80025FC4: mtc1        $at, $f14
        ctx->f14.u32l = ctx->r1;
            goto L_80025FE0;
    }
    goto skip_9;
    // 0x80025FC4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    skip_9:
    // 0x80025FC8: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
L_80025FCC:
    // 0x80025FCC: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80025FD0: nop

    // 0x80025FD4: bc1tl       L_80025FCC
    if (c1cs) {
        // 0x80025FD8: add.s       $f0, $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
            goto L_80025FCC;
    }
    goto skip_10;
    // 0x80025FD8: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
    skip_10:
    // 0x80025FDC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
L_80025FE0:
    // 0x80025FE0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80025FE4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80025FE8: nop

    // 0x80025FEC: bc1fl       L_80026008
    if (!c1cs) {
        // 0x80025FF0: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80026008;
    }
    goto skip_11;
    // 0x80025FF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_11:
    // 0x80025FF4: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x80025FF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80025FFC: b           L_8002602C
    // 0x80026000: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8002602C;
    // 0x80026000: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80026004: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80026008:
    // 0x80026008: nop

    // 0x8002600C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80026010: nop

    // 0x80026014: bc1fl       L_80026028
    if (!c1cs) {
        // 0x80026018: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80026028;
    }
    goto skip_12;
    // 0x80026018: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_12:
    // 0x8002601C: b           L_80026028
    // 0x80026020: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
        goto L_80026028;
    // 0x80026020: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80026024: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80026028:
    // 0x80026028: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8002602C:
    // 0x8002602C: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80026030: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80026034: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80026038: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8002603C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80026040: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80026044: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80026048: nop

    // 0x8002604C: bc1fl       L_80026060
    if (!c1cs) {
        // 0x80026050: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_80026060;
    }
    goto skip_13;
    // 0x80026050: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_13:
    // 0x80026054: b           L_8002607C
    // 0x80026058: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_8002607C;
    // 0x80026058: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8002605C: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_80026060:
    // 0x80026060: nop

    // 0x80026064: bc1fl       L_80026078
    if (!c1cs) {
        // 0x80026068: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_80026078;
    }
    goto skip_14;
    // 0x80026068: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_14:
    // 0x8002606C: b           L_80026078
    // 0x80026070: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
        goto L_80026078;
    // 0x80026070: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80026074: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80026078:
    // 0x80026078: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8002607C:
    // 0x8002607C: sub.s       $f18, $f14, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80026080: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80026084: swc1        $f2, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f2.u32l;
    // 0x80026088: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002608C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80026090: nop

    // 0x80026094: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80026098: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002609C: nop

    // 0x800260A0: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800260A4: beql        $t9, $zero, L_800260F4
    if (ctx->r25 == 0) {
        // 0x800260A8: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_800260F4;
    }
    goto skip_15;
    // 0x800260A8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_15:
    // 0x800260AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800260B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800260B4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800260B8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800260BC: nop

    // 0x800260C0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800260C4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800260C8: nop

    // 0x800260CC: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800260D0: bne         $t9, $zero, L_800260E8
    if (ctx->r25 != 0) {
        // 0x800260D4: nop
    
            goto L_800260E8;
    }
    // 0x800260D4: nop

    // 0x800260D8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800260DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800260E0: b           L_80026100
    // 0x800260E4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80026100;
    // 0x800260E4: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800260E8:
    // 0x800260E8: b           L_80026100
    // 0x800260EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80026100;
    // 0x800260EC: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800260F0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_800260F4:
    // 0x800260F4: nop

    // 0x800260F8: bltz        $t9, L_800260E8
    if (SIGNED(ctx->r25) < 0) {
        // 0x800260FC: nop
    
            goto L_800260E8;
    }
    // 0x800260FC: nop

L_80026100:
    // 0x80026100: addiu       $t0, $t9, 0x5
    ctx->r8 = ADD32(ctx->r25, 0X5);
    // 0x80026104: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80026108: divu        $zero, $t0, $at
    lo = S32(U32(ctx->r8) / U32(ctx->r1)); hi = S32(U32(ctx->r8) % U32(ctx->r1));
    // 0x8002610C: mflo        $t1
    ctx->r9 = lo;
    // 0x80026110: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80026114: jr          $ra
    // 0x80026118: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
    return;
    // 0x80026118: sw          $t1, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_805AE354(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AE354: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805AE358: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805AE35C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805AE360: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805AE364: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805AE368: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805AE36C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805AE370: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805AE374: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805AE378: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805AE37C: jr          $ra
    // 0x805AE380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805AE380: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80026B80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026B80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80026B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80026B88: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x80026B8C: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x80026B90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80026B94: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80026B98: lw          $t7, 0x9C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C);
    // 0x80026B9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80026BA0: lui         $t0, 0x8002
    ctx->r8 = S32(0X8002 << 16);
    // 0x80026BA4: sw          $v1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r3;
    // 0x80026BA8: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x80026BAC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80026BB0: addiu       $t0, $t0, 0x6B08
    ctx->r8 = ADD32(ctx->r8, 0X6B08);
    // 0x80026BB4: sw          $v1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r3;
    // 0x80026BB8: sb          $t9, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r25;
    // 0x80026BBC: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x80026BC0: jal         0x8001D770
    // 0x80026BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_8001D770(rdram, ctx);
        goto after_0;
    // 0x80026BC4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80026BC8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80026BCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80026BD0: lw          $a1, 0x34($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X34);
    // 0x80026BD4: jal         0x80067BF8
    // 0x80026BD8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_1;
    // 0x80026BD8: lw          $a2, 0x38($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X38);
    after_1:
    // 0x80026BDC: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    // 0x80026BE0: jal         0x80067818
    // 0x80026BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x80026BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80026BE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80026BEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80026BF0: jr          $ra
    // 0x80026BF4: nop

    return;
    // 0x80026BF4: nop

;}
RECOMP_FUNC void func_8067E59C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067E59C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8067E5A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067E5A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067E5A8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067E5AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067E5B0: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8067E5B4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x8067E5B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8067E5BC: jal         0x8067DF94
    // 0x8067E5C0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8067DF94(rdram, ctx);
        goto after_0;
    // 0x8067E5C0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8067E5C4: jal         0x8067E480
    // 0x8067E5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E480(rdram, ctx);
        goto after_1;
    // 0x8067E5C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067E5CC: jal         0x8067E420
    // 0x8067E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067E420(rdram, ctx);
        goto after_2;
    // 0x8067E5D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8067E5D4: beq         $v0, $zero, L_8067E5F4
    if (ctx->r2 == 0) {
        // 0x8067E5D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8067E5F4;
    }
    // 0x8067E5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8067E5DC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8067E5E0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8067E5E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8067E5E8: lbu         $a2, 0x8($t7)
    ctx->r6 = MEM_BU(ctx->r15, 0X8);
    // 0x8067E5EC: jal         0x8067EAE0
    // 0x8067E5F0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    func_8067EAE0(rdram, ctx);
        goto after_3;
    // 0x8067E5F0: lw          $a3, 0x68($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X68);
    after_3:
L_8067E5F4:
    // 0x8067E5F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8067E5F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8067E5FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8067E600: jr          $ra
    // 0x8067E604: nop

    return;
    // 0x8067E604: nop

;}
RECOMP_FUNC void func_806EC0CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC0CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806EC0D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EC0D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806EC0D8: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x806EC0DC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x806EC0E0: beql        $a1, $at, L_806EC118
    if (ctx->r5 == ctx->r1) {
        // 0x806EC0E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806EC118;
    }
    goto skip_0;
    // 0x806EC0E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806EC0E8: jal         0x80067930
    // 0x806EC0EC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    func_80067930(rdram, ctx);
        goto after_0;
    // 0x806EC0EC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    after_0:
    // 0x806EC0F0: bne         $v0, $zero, L_806EC114
    if (ctx->r2 != 0) {
        // 0x806EC0F4: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_806EC114;
    }
    // 0x806EC0F4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x806EC0F8: jal         0x80067E78
    // 0x806EC0FC: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    func_80067E78(rdram, ctx);
        goto after_1;
    // 0x806EC0FC: lw          $a0, 0x34($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X34);
    after_1:
    // 0x806EC100: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x806EC104: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x806EC108: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806EC10C: jal         0x80067838
    // 0x806EC110: lh          $a1, 0x1F0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X1F0);
    func_80067838(rdram, ctx);
        goto after_2;
    // 0x806EC110: lh          $a1, 0x1F0($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X1F0);
    after_2:
L_806EC114:
    // 0x806EC114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EC118:
    // 0x806EC118: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806EC11C: jr          $ra
    // 0x806EC120: nop

    return;
    // 0x806EC120: nop

;}
RECOMP_FUNC void func_804B6F28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6F30: jal         0x804B6BF8
    // 0x804B6F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B6BF8(rdram, ctx);
        goto after_0;
    // 0x804B6F34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6F38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6F40: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6F44: jal         0x804B6FF0
    // 0x804B6F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6F4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6F50: lui         $t6, 0x804B
    ctx->r14 = S32(RELOC_HI16(182, 0XC50) << 16);
    // 0x804B6F54: addiu       $t6, $t6, 0x6EF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(182, 0XC50));
    // 0x804B6F58: jal         0x80057978
    // 0x804B6F5C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    func_80057978(rdram, ctx);
        goto after_2;
    // 0x804B6F5C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    after_2:
    // 0x804B6F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6F68: jr          $ra
    // 0x804B6F6C: nop

    return;
    // 0x804B6F6C: nop

;}
RECOMP_FUNC void func_8045A800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045A804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045A808: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8045A80C: jal         0x80064E84
    // 0x8045A810: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    func_80064E84(rdram, ctx);
        goto after_0;
    // 0x8045A810: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x8045A814: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8045A818: jal         0x80064E84
    // 0x8045A81C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    func_80064E84(rdram, ctx);
        goto after_1;
    // 0x8045A81C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_1:
    // 0x8045A820: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045A824: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045A828: jr          $ra
    // 0x8045A82C: nop

    return;
    // 0x8045A82C: nop

;}
RECOMP_FUNC void func_80400F7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400F7C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80400F80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80400F84: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80400F88: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80400F8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80400F90: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80400F94: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80400F98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80400F9C: jal         0x8004921C
    // 0x80400FA0: addiu       $s0, $s1, 0xF4
    ctx->r16 = ADD32(ctx->r17, 0XF4);
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80400FA0: addiu       $s0, $s1, 0xF4
    ctx->r16 = ADD32(ctx->r17, 0XF4);
    after_0:
    // 0x80400FA4: sll         $t6, $v0, 5
    ctx->r14 = S32(ctx->r2 << 5);
    // 0x80400FA8: sh          $t6, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r14;
    // 0x80400FAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80400FB0: jal         0x8004921C
    // 0x80400FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80400FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80400FB8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x80400FBC: negu        $t2, $v1
    ctx->r10 = SUB32(0, ctx->r3);
    // 0x80400FC0: sll         $t7, $v0, 5
    ctx->r15 = S32(ctx->r2 << 5);
    // 0x80400FC4: sh          $t7, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r15;
    // 0x80400FC8: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80400FCC: sh          $t2, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r10;
    // 0x80400FD0: sh          $t2, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r10;
    // 0x80400FD4: sh          $t2, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r10;
    // 0x80400FD8: sh          $v1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r3;
    // 0x80400FDC: sh          $v1, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r3;
    // 0x80400FE0: sh          $v1, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r3;
    // 0x80400FE4: sh          $zero, 0x84($sp)
    MEM_H(0X84, ctx->r29) = 0;
    // 0x80400FE8: sh          $v1, 0x70($sp)
    MEM_H(0X70, ctx->r29) = ctx->r3;
    // 0x80400FEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80400FF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80400FF4: jal         0x8004921C
    // 0x80400FF8: sh          $zero, 0x86($sp)
    MEM_H(0X86, ctx->r29) = 0;
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x80400FF8: sh          $zero, 0x86($sp)
    MEM_H(0X86, ctx->r29) = 0;
    after_2:
    // 0x80400FFC: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x80401000: sh          $v1, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r3;
    // 0x80401004: sh          $v1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r3;
    // 0x80401008: sh          $zero, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = 0;
    // 0x8040100C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80401010: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80401014: jal         0x8004921C
    // 0x80401018: sh          $zero, 0x82($sp)
    MEM_H(0X82, ctx->r29) = 0;
    func_8004921C(rdram, ctx);
        goto after_3;
    // 0x80401018: sh          $zero, 0x82($sp)
    MEM_H(0X82, ctx->r29) = 0;
    after_3:
    // 0x8040101C: sll         $v1, $v0, 6
    ctx->r3 = S32(ctx->r2 << 6);
    // 0x80401020: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x80401024: sh          $v1, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r3;
    // 0x80401028: lw          $t8, 0xF0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XF0);
    // 0x8040102C: addiu       $a0, $t8, 0x1
    ctx->r4 = ADD32(ctx->r24, 0X1);
    // 0x80401030: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80401034: bne         $at, $zero, L_80401044
    if (ctx->r1 != 0) {
        // 0x80401038: sw          $a0, 0xF0($s1)
        MEM_W(0XF0, ctx->r17) = ctx->r4;
            goto L_80401044;
    }
    // 0x80401038: sw          $a0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->r4;
    // 0x8040103C: sw          $zero, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = 0;
    // 0x80401040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80401044:
    // 0x80401044: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80401048: addu        $t5, $t5, $a0
    ctx->r13 = ADD32(ctx->r13, ctx->r4);
    // 0x8040104C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80401050: addu        $v0, $s1, $t5
    ctx->r2 = ADD32(ctx->r17, ctx->r13);
    // 0x80401054: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x80401058: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8040105C: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80401060: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80401064: lh          $t6, 0x5E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X5E);
    // 0x80401068: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8040106C: addiu       $a2, $sp, 0x7A
    ctx->r6 = ADD32(ctx->r29, 0X7A);
    // 0x80401070: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80401074: lh          $t7, 0x5C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5C);
    // 0x80401078: sb          $t8, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r24;
    // 0x8040107C: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x80401080: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x80401084: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x80401088: sh          $t7, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r15;
    // 0x8040108C: lh          $t9, 0x74($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X74);
    // 0x80401090: addiu       $a3, $sp, 0x72
    ctx->r7 = ADD32(ctx->r29, 0X72);
    // 0x80401094: addiu       $t0, $sp, 0x8A
    ctx->r8 = ADD32(ctx->r29, 0X8A);
    // 0x80401098: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x8040109C: lh          $t5, 0x6C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6C);
    // 0x804010A0: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x804010A4: sh          $zero, 0x14($v0)
    MEM_H(0X14, ctx->r2) = 0;
    // 0x804010A8: sh          $t5, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r13;
    // 0x804010AC: lh          $t6, 0x84($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X84);
    // 0x804010B0: addiu       $t1, $sp, 0x82
    ctx->r9 = ADD32(ctx->r29, 0X82);
    // 0x804010B4: addiu       $v1, $s0, 0x18
    ctx->r3 = ADD32(ctx->r16, 0X18);
    // 0x804010B8: sh          $t6, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r14;
    // 0x804010BC: lh          $t7, 0x7C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X7C);
    // 0x804010C0: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x804010C4: sh          $t7, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r15;
    // 0x804010C8: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x804010CC: sb          $t8, -0x24($v0)
    MEM_B(-0X24, ctx->r2) = ctx->r24;
    // 0x804010D0: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x804010D4: sb          $t9, -0x23($v0)
    MEM_B(-0X23, ctx->r2) = ctx->r25;
    // 0x804010D8: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x804010DC: sb          $t5, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r13;
    // 0x804010E0: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x804010E4: sb          $t6, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r14;
    // 0x804010E8: lh          $t7, 0x76($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X76);
    // 0x804010EC: sh          $t7, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = ctx->r15;
    // 0x804010F0: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x804010F4: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x804010F8: sh          $zero, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = 0;
    // 0x804010FC: sh          $t8, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r24;
    // 0x80401100: lh          $t9, 0x86($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X86);
    // 0x80401104: sh          $t9, -0x18($v0)
    MEM_H(-0X18, ctx->r2) = ctx->r25;
    // 0x80401108: lh          $t5, 0x7E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X7E);
    // 0x8040110C: sh          $t5, -0x16($v0)
    MEM_H(-0X16, ctx->r2) = ctx->r13;
    // 0x80401110: lh          $t6, 0x8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8);
    // 0x80401114: sb          $t6, -0x14($v0)
    MEM_B(-0X14, ctx->r2) = ctx->r14;
    // 0x80401118: lh          $t7, 0xA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA);
    // 0x8040111C: sb          $t7, -0x13($v0)
    MEM_B(-0X13, ctx->r2) = ctx->r15;
    // 0x80401120: lh          $t8, 0xC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XC);
    // 0x80401124: sb          $t8, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r24;
    // 0x80401128: lh          $t9, 0xE($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XE);
    // 0x8040112C: sb          $t9, -0x11($v0)
    MEM_B(-0X11, ctx->r2) = ctx->r25;
    // 0x80401130: lh          $t5, 0x78($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X78);
    // 0x80401134: sh          $t5, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r13;
    // 0x80401138: lh          $t6, 0x70($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X70);
    // 0x8040113C: sh          $zero, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = 0;
    // 0x80401140: sh          $zero, -0xC($v0)
    MEM_H(-0XC, ctx->r2) = 0;
    // 0x80401144: sh          $t6, -0xE($v0)
    MEM_H(-0XE, ctx->r2) = ctx->r14;
    // 0x80401148: lh          $t7, 0x88($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X88);
    // 0x8040114C: sh          $t7, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r15;
    // 0x80401150: lh          $t8, 0x80($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X80);
    // 0x80401154: sh          $t8, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r24;
    // 0x80401158: lh          $t9, 0x10($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X10);
    // 0x8040115C: sb          $t9, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r25;
    // 0x80401160: lh          $t5, 0x12($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X12);
    // 0x80401164: sb          $t5, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r13;
    // 0x80401168: lh          $t6, 0x14($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X14);
    // 0x8040116C: sb          $t6, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r14;
    // 0x80401170: lh          $t7, 0x16($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16);
    // 0x80401174: sb          $t7, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r15;
    // 0x80401178: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8040117C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80401180: lh          $t9, 0x0($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X0);
    // 0x80401184: sh          $zero, 0x6($v0)
    MEM_H(0X6, ctx->r2) = 0;
    // 0x80401188: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8040118C: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80401190: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x80401194: sh          $t5, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r13;
    // 0x80401198: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8040119C: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x804011A0: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x804011A4: sb          $t7, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r15;
    // 0x804011A8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x804011AC: sb          $t8, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r24;
    // 0x804011B0: lh          $t9, 0x4($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X4);
    // 0x804011B4: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
    // 0x804011B8: lh          $t5, 0x6($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X6);
    // 0x804011BC: sb          $t5, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r13;
    // 0x804011C0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804011C4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x804011C8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x804011CC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804011D0: jr          $ra
    // 0x804011D4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x804011D4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void FindFaultedThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007033C: lui         $t9, 0xFFFA
    ctx->r25 = S32(0XFFFA << 16);
    // 0x80070340: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x80070344: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80070348: ori         $t9, $t9, 0x5A5A
    ctx->r25 = ctx->r25 | 0X5A5A;
L_8007034C:
    // 0x8007034C: addiu       $t0, $t0, -0x8
    ctx->r8 = ADD32(ctx->r8, -0X8);
    // 0x80070350: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80070354: bne         $t0, $sp, L_8007034C
    if (ctx->r8 != ctx->r29) {
        // 0x80070358: sw          $t9, 0x4($t0)
        MEM_W(0X4, ctx->r8) = ctx->r25;
            goto L_8007034C;
    }
    // 0x80070358: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007035C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80070360: jal         0x8008C130
    // 0x80070364: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x80070364: nop

    after_0:
    // 0x80070368: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8007036C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80070370: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80070374: beq         $a0, $t6, L_800703B8
    if (ctx->r4 == ctx->r14) {
        // 0x80070378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800703B8;
    }
    // 0x80070378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007037C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80070380:
    // 0x80070380: blez        $v0, L_800703A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80070384: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_800703A8;
    }
    // 0x80070384: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x80070388: beql        $at, $zero, L_800703AC
    if (ctx->r1 == 0) {
        // 0x8007038C: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_800703AC;
    }
    goto skip_0;
    // 0x8007038C: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x80070390: lhu         $t7, 0x12($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X12);
    // 0x80070394: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x80070398: beql        $t8, $zero, L_800703AC
    if (ctx->r24 == 0) {
        // 0x8007039C: lw          $v1, 0xC($v1)
        ctx->r3 = MEM_W(ctx->r3, 0XC);
            goto L_800703AC;
    }
    goto skip_1;
    // 0x8007039C: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
    skip_1:
    // 0x800703A0: b           L_800703BC
    // 0x800703A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800703BC;
    // 0x800703A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800703A8:
    // 0x800703A8: lw          $v1, 0xC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XC);
L_800703AC:
    // 0x800703AC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800703B0: bne         $a0, $v0, L_80070380
    if (ctx->r4 != ctx->r2) {
        // 0x800703B4: nop
    
            goto L_80070380;
    }
    // 0x800703B4: nop

L_800703B8:
    // 0x800703B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800703BC:
    // 0x800703BC: jr          $ra
    // 0x800703C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800703C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800307D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800307D4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800307D8: lwc1        $f12, -0x30($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30);
    // 0x800307DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800307E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800307E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800307E8: lwc1        $f14, -0x2C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2C);
    // 0x800307EC: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800307F0: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x800307F4: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800307F8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800307FC: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80030800: bc1fl       L_80030810
    if (!c1cs) {
        // 0x80030804: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_80030810;
    }
    goto skip_0;
    // 0x80030804: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x80030808: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8003080C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_80030810:
    // 0x80030810: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x80030814: bc1fl       L_80030824
    if (!c1cs) {
        // 0x80030818: c.eq.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
            goto L_80030824;
    }
    goto skip_1;
    // 0x80030818: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    skip_1:
    // 0x8003081C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80030820: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
L_80030824:
    // 0x80030824: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x80030828: bc1fl       L_80030850
    if (!c1cs) {
        // 0x8003082C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80030850;
    }
    goto skip_2;
    // 0x8003082C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80030830: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x80030834: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80030838: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003083C: bc1fl       L_80030850
    if (!c1cs) {
        // 0x80030840: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80030850;
    }
    goto skip_3;
    // 0x80030840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80030844: jal         0x8003D894
    // 0x80030848: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    func_8003D894(rdram, ctx);
        goto after_0;
    // 0x80030848: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    after_0:
    // 0x8003084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80030850:
    // 0x80030850: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030854: jr          $ra
    // 0x80030858: nop

    return;
    // 0x80030858: nop

;}
RECOMP_FUNC void func_804B64E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B64E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B64E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B64EC: lwc1        $f6, 0xC4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x804B64F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x804B64F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B64F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x804B64FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x804B6500: nop

    // 0x804B6504: bc1fl       L_804B6518
    if (!c1cs) {
        // 0x804B6508: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B6518;
    }
    goto skip_0;
    // 0x804B6508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B650C: jal         0x804B6FF0
    // 0x804B6510: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804B6FF0(rdram, ctx);
        goto after_0;
    // 0x804B6510: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x804B6514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B6518:
    // 0x804B6518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B651C: jr          $ra
    // 0x804B6520: nop

    return;
    // 0x804B6520: nop

;}
RECOMP_FUNC void func_8044A550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044A550: jr          $ra
    // 0x8044A554: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8044A554: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80060A90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060A90: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80060A94: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80060A98: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80060A9C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80060AA0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80060AA4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80060AA8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80060AAC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80060AB0: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x80060AB4: lw          $a2, 0x70($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X70);
    // 0x80060AB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80060ABC: sw          $t6, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r14;
    // 0x80060AC0: lh          $t7, 0x6($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X6);
    // 0x80060AC4: beq         $a2, $zero, L_80060CC8
    if (ctx->r6 == 0) {
        // 0x80060AC8: sh          $t7, 0x78($a0)
        MEM_H(0X78, ctx->r4) = ctx->r15;
            goto L_80060CC8;
    }
    // 0x80060AC8: sh          $t7, 0x78($a0)
    MEM_H(0X78, ctx->r4) = ctx->r15;
    // 0x80060ACC: lh          $t8, 0x78($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X78);
    // 0x80060AD0: addiu       $s5, $sp, 0x44
    ctx->r21 = ADD32(ctx->r29, 0X44);
    // 0x80060AD4: addiu       $s4, $zero, 0x68
    ctx->r20 = ADD32(0, 0X68);
    // 0x80060AD8: beq         $t8, $zero, L_80060CC8
    if (ctx->r24 == 0) {
        // 0x80060ADC: lui         $s3, 0x800F
        ctx->r19 = S32(0X800F << 16);
            goto L_80060CC8;
    }
    // 0x80060ADC: lui         $s3, 0x800F
    ctx->r19 = S32(0X800F << 16);
    // 0x80060AE0: addiu       $s3, $s3, 0x7EA0
    ctx->r19 = ADD32(ctx->r19, 0X7EA0);
    // 0x80060AE4: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x80060AE8: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
L_80060AEC:
    // 0x80060AEC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060AF0: beql        $v0, $zero, L_80060CB4
    if (ctx->r2 == 0) {
        // 0x80060AF4: addiu       $t3, $v1, 0x4
        ctx->r11 = ADD32(ctx->r3, 0X4);
            goto L_80060CB4;
    }
    goto skip_0;
    // 0x80060AF4: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80060AF8: lw          $a0, 0x174($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X174);
    // 0x80060AFC: beql        $a0, $zero, L_80060CB4
    if (ctx->r4 == 0) {
        // 0x80060B00: addiu       $t3, $v1, 0x4
        ctx->r11 = ADD32(ctx->r3, 0X4);
            goto L_80060CB4;
    }
    goto skip_1;
    // 0x80060B00: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    skip_1:
    // 0x80060B04: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80060B08: bnel        $t9, $zero, L_80060CB4
    if (ctx->r25 != 0) {
        // 0x80060B0C: addiu       $t3, $v1, 0x4
        ctx->r11 = ADD32(ctx->r3, 0X4);
            goto L_80060CB4;
    }
    goto skip_2;
    // 0x80060B0C: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
    skip_2:
    // 0x80060B10: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80060B14: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80060B18: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x80060B1C: lw          $t1, 0x174($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X174);
    // 0x80060B20: beq         $t2, $v0, L_80060C9C
    if (ctx->r10 == ctx->r2) {
        // 0x80060B24: sw          $t1, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r9;
            goto L_80060C9C;
    }
    // 0x80060B24: sw          $t1, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r9;
    // 0x80060B28: lbu         $t3, 0x17D($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X17D);
    // 0x80060B2C: beql        $s2, $t3, L_80060CA0
    if (ctx->r18 == ctx->r11) {
        // 0x80060B30: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80060CA0;
    }
    goto skip_3;
    // 0x80060B30: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_3:
    // 0x80060B34: lbu         $t4, 0x5($s3)
    ctx->r12 = MEM_BU(ctx->r19, 0X5);
    // 0x80060B38: beq         $t4, $zero, L_80060B4C
    if (ctx->r12 == 0) {
        // 0x80060B3C: nop
    
            goto L_80060B4C;
    }
    // 0x80060B3C: nop

    // 0x80060B40: lbu         $t5, 0x10($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X10);
    // 0x80060B44: beql        $t5, $zero, L_80060CA0
    if (ctx->r13 == 0) {
        // 0x80060B48: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80060CA0;
    }
    goto skip_4;
    // 0x80060B48: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_4:
L_80060B4C:
    // 0x80060B4C: jal         0x8006009C
    // 0x80060B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006009C(rdram, ctx);
        goto after_0;
    // 0x80060B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80060B54: beql        $v0, $zero, L_80060CA0
    if (ctx->r2 == 0) {
        // 0x80060B58: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80060CA0;
    }
    goto skip_5;
    // 0x80060B58: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_5:
    // 0x80060B5C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80060B60: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80060B64: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80060B68: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80060B6C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80060B70: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x80060B74: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x80060B78: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80060B7C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80060B80: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80060B84: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x80060B88: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x80060B8C: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80060B90: sw          $t3, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r11;
    // 0x80060B94: lbu         $t4, 0x18($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X18);
    // 0x80060B98: bnel        $s4, $t4, L_80060C40
    if (ctx->r20 != ctx->r12) {
        // 0x80060B9C: lw          $v0, 0x174($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X174);
            goto L_80060C40;
    }
    goto skip_6;
    // 0x80060B9C: lw          $v0, 0x174($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X174);
    skip_6:
    // 0x80060BA0: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x80060BA4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x80060BA8: lhu         $v0, 0x16($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X16);
    // 0x80060BAC: andi        $t7, $v0, 0xC000
    ctx->r15 = ctx->r2 & 0XC000;
    // 0x80060BB0: beq         $t7, $zero, L_80060C3C
    if (ctx->r15 == 0) {
        // 0x80060BB4: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_80060C3C;
    }
    // 0x80060BB4: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x80060BB8: beq         $t8, $zero, L_80060BD0
    if (ctx->r24 == 0) {
        // 0x80060BBC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80060BD0;
    }
    // 0x80060BBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80060BC0: jal         0x8003DC78
    // 0x80060BC4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_8003DC78(rdram, ctx);
        goto after_1;
    // 0x80060BC4: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_1:
    // 0x80060BC8: b           L_80060C34
    // 0x80060BCC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
        goto L_80060C34;
    // 0x80060BCC: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
L_80060BD0:
    // 0x80060BD0: lw          $t9, 0x3C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X3C);
    // 0x80060BD4: lw          $t0, 0x174($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X174);
    // 0x80060BD8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80060BDC: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x80060BE0: beq         $t2, $zero, L_80060C34
    if (ctx->r10 == 0) {
        // 0x80060BE4: nop
    
            goto L_80060C34;
    }
    // 0x80060BE4: nop

    // 0x80060BE8: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80060BEC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80060BF0: addiu       $a3, $s0, 0x88
    ctx->r7 = ADD32(ctx->r16, 0X88);
    // 0x80060BF4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80060BF8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x80060BFC: lwc1        $f8, 0x80($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80060C00: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80060C04: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x80060C08: lwc1        $f16, 0x84($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80060C0C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80060C10: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    // 0x80060C14: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x80060C18: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80060C1C: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x80060C20: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80060C24: lw          $t9, 0x28($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X28);
    // 0x80060C28: jalr        $t9
    // 0x80060C2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80060C2C: nop

    after_2:
    // 0x80060C30: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
L_80060C34:
    // 0x80060C34: b           L_80060C6C
    // 0x80060C38: lw          $v0, 0x174($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X174);
        goto L_80060C6C;
    // 0x80060C38: lw          $v0, 0x174($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X174);
L_80060C3C:
    // 0x80060C3C: lw          $v0, 0x174($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X174);
L_80060C40:
    // 0x80060C40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80060C44: addiu       $a2, $s0, 0x7C
    ctx->r6 = ADD32(ctx->r16, 0X7C);
    // 0x80060C48: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80060C4C: addiu       $a3, $s0, 0x88
    ctx->r7 = ADD32(ctx->r16, 0X88);
    // 0x80060C50: lw          $v1, 0x24($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X24);
    // 0x80060C54: beq         $v1, $zero, L_80060C6C
    if (ctx->r3 == 0) {
        // 0x80060C58: nop
    
            goto L_80060C6C;
    }
    // 0x80060C58: nop

    // 0x80060C5C: jalr        $v1
    // 0x80060C60: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_3;
    // 0x80060C60: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    after_3:
    // 0x80060C64: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80060C68: lw          $v0, 0x174($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X174);
L_80060C6C:
    // 0x80060C6C: beq         $v0, $zero, L_80060C94
    if (ctx->r2 == 0) {
        // 0x80060C70: nop
    
            goto L_80060C94;
    }
    // 0x80060C70: nop

    // 0x80060C74: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80060C78: lw          $t7, 0x14($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14);
    // 0x80060C7C: bne         $t7, $zero, L_80060C94
    if (ctx->r15 != 0) {
        // 0x80060C80: nop
    
            goto L_80060C94;
    }
    // 0x80060C80: nop

    // 0x80060C84: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80060C88: lbu         $t0, 0x76($t8)
    ctx->r8 = MEM_BU(ctx->r24, 0X76);
    // 0x80060C8C: bnel        $t0, $zero, L_80060CA0
    if (ctx->r8 != 0) {
        // 0x80060C90: lh          $t1, 0x78($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X78);
            goto L_80060CA0;
    }
    goto skip_7;
    // 0x80060C90: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
    skip_7:
L_80060C94:
    // 0x80060C94: b           L_80060CCC
    // 0x80060C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80060CCC;
    // 0x80060C98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80060C9C:
    // 0x80060C9C: lh          $t1, 0x78($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X78);
L_80060CA0:
    // 0x80060CA0: lw          $a2, 0x70($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X70);
    // 0x80060CA4: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    // 0x80060CA8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80060CAC: sh          $t2, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r10;
    // 0x80060CB0: addiu       $t3, $v1, 0x4
    ctx->r11 = ADD32(ctx->r3, 0X4);
L_80060CB4:
    // 0x80060CB4: beq         $a2, $zero, L_80060CC8
    if (ctx->r6 == 0) {
        // 0x80060CB8: sw          $t3, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->r11;
            goto L_80060CC8;
    }
    // 0x80060CB8: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80060CBC: lh          $t4, 0x78($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X78);
    // 0x80060CC0: bnel        $t4, $zero, L_80060AEC
    if (ctx->r12 != 0) {
        // 0x80060CC4: lw          $v1, 0x74($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X74);
            goto L_80060AEC;
    }
    goto skip_8;
    // 0x80060CC4: lw          $v1, 0x74($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X74);
    skip_8:
L_80060CC8:
    // 0x80060CC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80060CCC:
    // 0x80060CCC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80060CD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80060CD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80060CD8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80060CDC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80060CE0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80060CE4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80060CE8: jr          $ra
    // 0x80060CEC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80060CEC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80681944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80681944: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80681948: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X11EC) << 16);
    // 0x8068194C: addiu       $t6, $t6, 0x15FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X11EC));
    // 0x80681950: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80681954: jr          $ra
    // 0x80681958: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80681958: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80062748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062748: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
    // 0x8006274C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80062750: lh          $v0, 0x184($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X184);
    // 0x80062754: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80062758: addiu       $v1, $a0, 0x188
    ctx->r3 = ADD32(ctx->r4, 0X188);
    // 0x8006275C: lh          $t7, 0x58($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X58);
    // 0x80062760: lh          $t8, 0x52($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X52);
    // 0x80062764: lw          $t6, 0x70($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X70);
    // 0x80062768: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006276C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80062770: lwc1        $f2, 0x4($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X4);
    // 0x80062774: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80062778: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006277C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80062780: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x80062784: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x80062788: beq         $v0, $zero, L_80062808
    if (ctx->r2 == 0) {
        // 0x8006278C: sub.s       $f0, $f10, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_80062808;
    }
    // 0x8006278C: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
L_80062790:
    // 0x80062790: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80062794: beq         $a1, $zero, L_800627FC
    if (ctx->r5 == 0) {
        // 0x80062798: nop
    
            goto L_800627FC;
    }
    // 0x80062798: nop

    // 0x8006279C: lw          $a2, 0x174($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X174);
    // 0x800627A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800627A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800627A8: beq         $a2, $zero, L_800627FC
    if (ctx->r6 == 0) {
        // 0x800627AC: sra         $v0, $v0, 16
        ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800627FC;
    }
    // 0x800627AC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800627B0: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    // 0x800627B4: bne         $a0, $t9, L_800627FC
    if (ctx->r4 != ctx->r25) {
        // 0x800627B8: nop
    
            goto L_800627FC;
    }
    // 0x800627B8: nop

    // 0x800627BC: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800627C0: lh          $t1, 0x6($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X6);
    // 0x800627C4: lh          $t2, 0xC($a3)
    ctx->r10 = MEM_H(ctx->r7, 0XC);
    // 0x800627C8: lw          $t0, 0x70($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X70);
    // 0x800627CC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800627D0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800627D4: lwc1        $f12, 0x4($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800627D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800627DC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800627E0: mul.s       $f16, $f12, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800627E4: nop

    // 0x800627E8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800627EC: add.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800627F0: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800627F4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800627F8: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
L_800627FC:
    // 0x800627FC: bne         $v0, $zero, L_80062790
    if (ctx->r2 != 0) {
        // 0x80062800: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80062790;
    }
    // 0x80062800: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80062804: lw          $a2, 0x174($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X174);
L_80062808:
    // 0x80062808: lwc1        $f18, 0x98($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8006280C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80062810: jr          $ra
    // 0x80062814: swc1        $f18, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f18.u32l;
    return;
    // 0x80062814: swc1        $f18, 0x6C($t3)
    MEM_W(0X6C, ctx->r11) = ctx->f18.u32l;
;}
RECOMP_FUNC void func_806DF22C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF22C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806DF230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF234: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806DF238: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x806DF23C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x806DF240: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x806DF244: beql        $t7, $zero, L_806DF290
    if (ctx->r15 == 0) {
        // 0x806DF248: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806DF290;
    }
    goto skip_0;
    // 0x806DF248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806DF24C: lw          $t8, 0x174($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X174);
    // 0x806DF250: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806DF254: sh          $zero, 0x12($t9)
    MEM_H(0X12, ctx->r25) = 0;
    // 0x806DF258: jal         0x8005FD1C
    // 0x806DF25C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_8005FD1C(rdram, ctx);
        goto after_0;
    // 0x806DF25C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x806DF260: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x806DF264: jal         0x806DF1B8
    // 0x806DF268: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    func_806DF1B8(rdram, ctx);
        goto after_1;
    // 0x806DF268: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    after_1:
    // 0x806DF26C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806DF270: jal         0x806DF37C
    // 0x806DF274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806DF37C(rdram, ctx);
        goto after_2;
    // 0x806DF274: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x806DF278: jal         0x80067E68
    // 0x806DF27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_80067E68(rdram, ctx);
        goto after_3;
    // 0x806DF27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x806DF280: addiu       $a0, $zero, 0x251
    ctx->r4 = ADD32(0, 0X251);
    // 0x806DF284: jal         0x80067818
    // 0x806DF288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x806DF288: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x806DF28C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806DF290:
    // 0x806DF290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806DF294: jr          $ra
    // 0x806DF298: nop

    return;
    // 0x806DF298: nop

;}
RECOMP_FUNC void func_8078749C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078749C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807874A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807874A4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x807874A8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x807874AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x807874B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x807874B4: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x807874B8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807874BC: lui         $a0, 0x8079
    ctx->r4 = S32(RELOC_HI16(787, 0X3264) << 16);
    // 0x807874C0: lh          $t6, 0x52C2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X52C2);
    // 0x807874C4: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x807874C8: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x807874CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x807874D0: addiu       $a0, $a0, -0x635C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(787, 0X3264));
    // 0x807874D4: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x807874D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x807874DC: sh          $t7, 0x52C2($a1)
    MEM_H(0X52C2, ctx->r5) = ctx->r15;
    // 0x807874E0: lh          $v0, 0x52C4($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X52C4);
L_807874E4:
    // 0x807874E4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x807874E8: lh          $t8, 0x52C2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X52C2);
    // 0x807874EC: lw          $t3, 0xED0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XED0);
    // 0x807874F0: multu       $v1, $t9
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807874F4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x807874F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x807874FC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80787500: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80787504: mflo        $t0
    ctx->r8 = lo;
    // 0x80787508: subu        $t1, $t8, $t0
    ctx->r9 = SUB32(ctx->r24, ctx->r8);
    // 0x8078750C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80787510: lh          $t4, 0x52C6($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X52C6);
    // 0x80787514: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80787518: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8078751C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80787520: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80787524: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80787528: bne         $at, $zero, L_80787534
    if (ctx->r1 != 0) {
        // 0x8078752C: sw          $t1, 0xC($t9)
        MEM_W(0XC, ctx->r25) = ctx->r9;
            goto L_80787534;
    }
    // 0x8078752C: sw          $t1, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r9;
    // 0x80787530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80787534:
    // 0x80787534: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80787538: bne         $at, $zero, L_807874E4
    if (ctx->r1 != 0) {
        // 0x8078753C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_807874E4;
    }
    // 0x8078753C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80787540: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80787544: addiu       $s3, $sp, 0x44
    ctx->r19 = ADD32(ctx->r29, 0X44);
    // 0x80787548: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8078754C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
L_80787550:
    // 0x80787550: bnel        $s2, $t8, L_80787574
    if (ctx->r18 != ctx->r24) {
        // 0x80787554: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80787574;
    }
    goto skip_0;
    // 0x80787554: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x80787558: lbu         $t0, 0x165($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X165);
    // 0x8078755C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80787560: bnel        $t0, $zero, L_80787574
    if (ctx->r8 != 0) {
        // 0x80787564: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80787574;
    }
    goto skip_1;
    // 0x80787564: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_1:
    // 0x80787568: jal         0x80787064
    // 0x8078756C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    func_80787064(rdram, ctx);
        goto after_0;
    // 0x8078756C: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    after_0:
    // 0x80787570: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80787574:
    // 0x80787574: bnel        $s0, $s3, L_80787550
    if (ctx->r16 != ctx->r19) {
        // 0x80787578: lw          $t8, 0x0($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X0);
            goto L_80787550;
    }
    goto skip_2;
    // 0x80787578: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x8078757C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80787580: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80787584: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80787588: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8078758C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80787590: jr          $ra
    // 0x80787594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80787594: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80026AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026AE4: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x80026AE8: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x80026AEC: addiu       $t7, $zero, 0x17
    ctx->r15 = ADD32(0, 0X17);
    // 0x80026AF0: addiu       $t8, $t8, 0x4748
    ctx->r24 = ADD32(ctx->r24, 0X4748);
    // 0x80026AF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80026AF8: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x80026AFC: sb          $t7, 0xC($a0)
    MEM_B(0XC, ctx->r4) = ctx->r15;
    // 0x80026B00: jr          $ra
    // 0x80026B04: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
    return;
    // 0x80026B04: sw          $t8, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void func_8007788C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007788C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80077890: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80077894: jr          $ra
    // 0x80077898: nop

    return;
    // 0x80077898: nop

    // 0x8007789C: nop

;}
RECOMP_FUNC void func_8073DCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073DCE8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8073DCEC: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073DCF0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8073DCF4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8073DCF8: nop

    // 0x8073DCFC: bc1fl       L_8073DD2C
    if (!c1cs) {
        // 0x8073DD00: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_8073DD2C;
    }
    goto skip_0;
    // 0x8073DD00: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x8073DD04: add.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8073DD08: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8073DD0C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073DD10: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8073DD14: nop

    // 0x8073DD18: bc1f        L_8073DD58
    if (!c1cs) {
        // 0x8073DD1C: nop
    
            goto L_8073DD58;
    }
    // 0x8073DD1C: nop

    // 0x8073DD20: jr          $ra
    // 0x8073DD24: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    return;
    // 0x8073DD24: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x8073DD28: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_8073DD2C:
    // 0x8073DD2C: nop

    // 0x8073DD30: bc1f        L_8073DD58
    if (!c1cs) {
        // 0x8073DD34: nop
    
            goto L_8073DD58;
    }
    // 0x8073DD34: nop

    // 0x8073DD38: sub.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8073DD3C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8073DD40: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8073DD44: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x8073DD48: nop

    // 0x8073DD4C: bc1f        L_8073DD58
    if (!c1cs) {
        // 0x8073DD50: nop
    
            goto L_8073DD58;
    }
    // 0x8073DD50: nop

    // 0x8073DD54: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
L_8073DD58:
    // 0x8073DD58: jr          $ra
    // 0x8073DD5C: nop

    return;
    // 0x8073DD5C: nop

;}
RECOMP_FUNC void func_80427BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80427BEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80427BF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80427BF4: lh          $a1, 0x1F0($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X1F0);
    // 0x80427BF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80427BFC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80427C00: beq         $a1, $at, L_80427C1C
    if (ctx->r5 == ctx->r1) {
        // 0x80427C04: addiu       $a0, $zero, 0x13
        ctx->r4 = ADD32(0, 0X13);
            goto L_80427C1C;
    }
    // 0x80427C04: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x80427C08: jal         0x80067878
    // 0x80427C0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80067878(rdram, ctx);
        goto after_0;
    // 0x80427C0C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80427C10: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80427C14: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80427C18: sh          $t6, 0x1F0($a2)
    MEM_H(0X1F0, ctx->r6) = ctx->r14;
L_80427C1C:
    // 0x80427C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80427C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80427C24: jr          $ra
    // 0x80427C28: nop

    return;
    // 0x80427C28: nop

;}
RECOMP_FUNC void func_80066448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066448: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006644C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066450: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066454: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x80066458: swc1        $f0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f0.u32l;
    // 0x8006645C: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80066460: jr          $ra
    // 0x80066464: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80066464: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_806D913C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D913C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D9140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9144: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x806D9148: bnel        $t6, $zero, L_806D915C
    if (ctx->r14 != 0) {
        // 0x806D914C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806D915C;
    }
    goto skip_0;
    // 0x806D914C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806D9150: jal         0x806D9100
    // 0x806D9154: nop

    func_806D9100(rdram, ctx);
        goto after_0;
    // 0x806D9154: nop

    after_0:
    // 0x806D9158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806D915C:
    // 0x806D915C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D9160: jr          $ra
    // 0x806D9164: nop

    return;
    // 0x806D9164: nop

;}
RECOMP_FUNC void func_804CC560(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CC560: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804CC564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804CC568: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804CC56C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804CC570: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804CC574: jal         0x80051194
    // 0x804CC578: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804CC578: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x804CC57C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804CC580: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804CC584: jal         0x804CC8EC
    // 0x804CC588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804CC8EC(rdram, ctx);
        goto after_1;
    // 0x804CC588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804CC58C: beq         $v0, $zero, L_804CC600
    if (ctx->r2 == 0) {
        // 0x804CC590: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_804CC600;
    }
    // 0x804CC590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC594: jal         0x804CC9B0
    // 0x804CC598: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_804CC9B0(rdram, ctx);
        goto after_2;
    // 0x804CC598: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x804CC59C: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804CC5A0: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(237, 0X6BC) << 16);
    // 0x804CC5A4: addiu       $t6, $t6, -0x34D4
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(237, 0X6BC));
    // 0x804CC5A8: sw          $t6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r14;
    // 0x804CC5AC: lw          $t9, 0x16C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X16C);
    // 0x804CC5B0: lui         $t8, 0x804D
    ctx->r24 = S32(RELOC_HI16(237, 0X1BB4) << 16);
    // 0x804CC5B4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804CC5B8: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804CC5BC: addiu       $t8, $t8, -0x1FDC
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(237, 0X1BB4));
    // 0x804CC5C0: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x804CC5C4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804CC5C8: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x804CC5CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC5D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804CC5D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804CC5D8: jal         0x804CDF54
    // 0x804CC5DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804CDF54(rdram, ctx);
        goto after_3;
    // 0x804CC5DC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x804CC5E0: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x804CC5E4: lui         $t0, 0x804D
    ctx->r8 = S32(RELOC_HI16(237, 0XC30) << 16);
    // 0x804CC5E8: addiu       $t0, $t0, -0x2F60
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(237, 0XC30));
    // 0x804CC5EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804CC5F0: jal         0x804CC548
    // 0x804CC5F4: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    func_804CC548(rdram, ctx);
        goto after_4;
    // 0x804CC5F4: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    after_4:
    // 0x804CC5F8: b           L_804CC60C
    // 0x804CC5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804CC60C;
    // 0x804CC5FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CC600:
    // 0x804CC600: jal         0x800445A4
    // 0x804CC604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804CC604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804CC608: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804CC60C:
    // 0x804CC60C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804CC610: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804CC614: jr          $ra
    // 0x804CC618: nop

    return;
    // 0x804CC618: nop

;}
RECOMP_FUNC void func_8064EA0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EA0C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8064EA10: beql        $at, $zero, L_8064EA24
    if (ctx->r1 == 0) {
        // 0x8064EA14: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8064EA24;
    }
    goto skip_0;
    // 0x8064EA14: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_0:
    // 0x8064EA18: jr          $ra
    // 0x8064EA1C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    return;
    // 0x8064EA1C: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8064EA20: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_8064EA24:
    // 0x8064EA24: beq         $at, $zero, L_8064EA60
    if (ctx->r1 == 0) {
        // 0x8064EA28: subu        $t6, $a0, $a1
        ctx->r14 = SUB32(ctx->r4, ctx->r5);
            goto L_8064EA60;
    }
    // 0x8064EA28: subu        $t6, $a0, $a1
    ctx->r14 = SUB32(ctx->r4, ctx->r5);
    // 0x8064EA2C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8064EA30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EA34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8064EA38: lwc1        $f2, 0x14($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8064EA3C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8064EA40: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x8064EA44: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8064EA48: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8064EA4C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064EA50: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8064EA54: div.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8064EA58: jr          $ra
    // 0x8064EA5C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    return;
    // 0x8064EA5C: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
L_8064EA60:
    // 0x8064EA60: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8064EA64: beq         $at, $zero, L_8064EA7C
    if (ctx->r1 == 0) {
        // 0x8064EA68: lw          $v0, 0x10($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X10);
            goto L_8064EA7C;
    }
    // 0x8064EA68: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x8064EA6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EA70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8064EA74: jr          $ra
    // 0x8064EA78: nop

    return;
    // 0x8064EA78: nop

L_8064EA7C:
    // 0x8064EA7C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8064EA80: beq         $at, $zero, L_8064EAC0
    if (ctx->r1 == 0) {
        // 0x8064EA84: lwc1        $f0, 0x18($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8064EAC0;
    }
    // 0x8064EA84: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8064EA88: subu        $t8, $a0, $a3
    ctx->r24 = SUB32(ctx->r4, ctx->r7);
    // 0x8064EA8C: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8064EA90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8064EA94: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8064EA98: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8064EA9C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8064EAA0: subu        $t9, $v0, $a3
    ctx->r25 = SUB32(ctx->r2, ctx->r7);
    // 0x8064EAA4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8064EAA8: sub.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x8064EAAC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8064EAB0: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8064EAB4: div.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8064EAB8: jr          $ra
    // 0x8064EABC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
    return;
    // 0x8064EABC: sub.s       $f0, $f12, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f16.fl;
L_8064EAC0:
    // 0x8064EAC0: jr          $ra
    // 0x8064EAC4: nop

    return;
    // 0x8064EAC4: nop

;}
RECOMP_FUNC void func_8004A97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A980: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8004A984: lbu         $t7, 0x1B($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1B);
    // 0x8004A988: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x8004A98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A990: srl         $t8, $t7, 6
    ctx->r24 = S32(U32(ctx->r15) >> 6);
    // 0x8004A994: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8004A998: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x8004A99C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8004A9A0: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x8004A9A4: lw          $t9, 0xD24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD24);
    // 0x8004A9A8: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x8004A9AC: jalr        $t9
    // 0x8004A9B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8004A9B0: nop

    after_0:
    // 0x8004A9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A9B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A9BC: jr          $ra
    // 0x8004A9C0: nop

    return;
    // 0x8004A9C0: nop

;}
RECOMP_FUNC void func_80551A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80551A04: addiu       $sp, $sp, -0x1A8
    ctx->r29 = ADD32(ctx->r29, -0X1A8);
    // 0x80551A08: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80551A0C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80551A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80551A14: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80551A18: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80551A1C: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80551A20: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80551A24: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80551A28: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80551A2C: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80551A30: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80551A34: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80551A38: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80551A3C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80551A40: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80551A44: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80551A48: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80551A4C: jal         0x8004921C
    // 0x80551A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80551A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80551A54: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x80551A58: sh          $t6, 0x16A($sp)
    MEM_H(0X16A, ctx->r29) = ctx->r14;
    // 0x80551A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80551A60: jal         0x8004921C
    // 0x80551A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80551A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80551A68: sll         $t7, $v0, 6
    ctx->r15 = S32(ctx->r2 << 6);
    // 0x80551A6C: sh          $t7, 0x168($sp)
    MEM_H(0X168, ctx->r29) = ctx->r15;
    // 0x80551A70: lw          $t3, 0x1F4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1F4);
    // 0x80551A74: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80551A78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80551A7C: lw          $t8, 0xD58($t3)
    ctx->r24 = MEM_W(ctx->r11, 0XD58);
    // 0x80551A80: addiu       $a3, $t3, 0x908
    ctx->r7 = ADD32(ctx->r11, 0X908);
    // 0x80551A84: lwc1        $f20, 0x84($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80551A88: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80551A8C: lwc1        $f24, 0x88($s0)
    ctx->f24.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80551A90: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80551A94: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80551A98: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80551A9C: lwc1        $f28, 0xD5C($t3)
    ctx->f28.u32l = MEM_W(ctx->r11, 0XD5C);
    // 0x80551AA0: addiu       $fp, $t3, 0x970
    ctx->r30 = ADD32(ctx->r11, 0X970);
    // 0x80551AA4: addiu       $a1, $t3, 0x980
    ctx->r5 = ADD32(ctx->r11, 0X980);
    // 0x80551AA8: addiu       $s6, $t3, 0xB70
    ctx->r22 = ADD32(ctx->r11, 0XB70);
    // 0x80551AAC: addiu       $s4, $t3, 0xB80
    ctx->r20 = ADD32(ctx->r11, 0XB80);
    // 0x80551AB0: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_80551AB4:
    // 0x80551AB4: mtc1        $s5, $f10
    ctx->f10.u32l = ctx->r21;
    // 0x80551AB8: lw          $t9, 0xD50($t3)
    ctx->r25 = MEM_W(ctx->r11, 0XD50);
    // 0x80551ABC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80551AC0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80551AC4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80551AC8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80551ACC: nop

    // 0x80551AD0: addu        $v1, $t9, $t5
    ctx->r3 = ADD32(ctx->r25, ctx->r13);
    // 0x80551AD4: slti        $at, $v1, 0x120
    ctx->r1 = SIGNED(ctx->r3) < 0X120 ? 1 : 0;
    // 0x80551AD8: bnel        $at, $zero, L_80551AE8
    if (ctx->r1 != 0) {
        // 0x80551ADC: sll         $t6, $v1, 3
        ctx->r14 = S32(ctx->r3 << 3);
            goto L_80551AE8;
    }
    goto skip_0;
    // 0x80551ADC: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    skip_0:
    // 0x80551AE0: addiu       $v1, $v1, -0x120
    ctx->r3 = ADD32(ctx->r3, -0X120);
    // 0x80551AE4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
L_80551AE8:
    // 0x80551AE8: addu        $v0, $t3, $t6
    ctx->r2 = ADD32(ctx->r11, ctx->r14);
    // 0x80551AEC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80551AF0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80551AF4: slti        $at, $s5, 0x9
    ctx->r1 = SIGNED(ctx->r21) < 0X9 ? 1 : 0;
    // 0x80551AF8: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x80551AFC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80551B00: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80551B04: bne         $at, $zero, L_80551AB4
    if (ctx->r1 != 0) {
        // 0x80551B08: swc1        $f4, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
            goto L_80551AB4;
    }
    // 0x80551B08: swc1        $f4, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f4.u32l;
    // 0x80551B0C: lui         $t7, 0x8055
    ctx->r15 = S32(RELOC_HI16(354, 0X4098) << 16);
    // 0x80551B10: addiu       $t7, $t7, 0x4BB8
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(354, 0X4098));
    // 0x80551B14: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80551B18: addiu       $v1, $sp, 0xF0
    ctx->r3 = ADD32(ctx->r29, 0XF0);
    // 0x80551B1C: addiu       $v0, $t3, 0xB60
    ctx->r2 = ADD32(ctx->r11, 0XB60);
    // 0x80551B20: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80551B24: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80551B28: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80551B2C: addiu       $a0, $sp, 0x100
    ctx->r4 = ADD32(ctx->r29, 0X100);
    // 0x80551B30: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80551B34: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x80551B38: addiu       $s3, $t3, 0xB50
    ctx->r19 = ADD32(ctx->r11, 0XB50);
    // 0x80551B3C: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    // 0x80551B40: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80551B44: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80551B48: addiu       $s7, $t3, 0x960
    ctx->r23 = ADD32(ctx->r11, 0X960);
    // 0x80551B4C: addiu       $s5, $t3, 0x950
    ctx->r21 = ADD32(ctx->r11, 0X950);
    // 0x80551B50: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x80551B54: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80551B58: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x80551B5C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x80551B60: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80551B64: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80551B68: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x80551B6C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80551B70: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80551B74: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80551B78: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80551B7C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80551B80: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80551B84: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80551B88: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80551B8C: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x80551B90: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80551B94: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80551B98: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80551B9C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80551BA0: sw          $t8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r24;
    // 0x80551BA4: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
    // 0x80551BA8: sw          $t4, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r12;
    // 0x80551BAC: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    // 0x80551BB0: sw          $t8, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r24;
    // 0x80551BB4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80551BB8: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80551BBC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80551BC0: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x80551BC4: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x80551BC8: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80551BCC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80551BD0: sw          $t5, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r13;
    // 0x80551BD4: sw          $t9, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r25;
    // 0x80551BD8: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x80551BDC: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80551BE0: sw          $t6, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r14;
    // 0x80551BE4: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x80551BE8: sw          $t7, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r15;
    // 0x80551BEC: lw          $t6, 0xC($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XC);
    // 0x80551BF0: sw          $t6, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r14;
    // 0x80551BF4: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80551BF8: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80551BFC: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x80551C00: sw          $t8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r24;
    // 0x80551C04: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    // 0x80551C08: sw          $t4, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r12;
    // 0x80551C0C: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x80551C10: sw          $t8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r24;
    // 0x80551C14: lwc1        $f6, 0x908($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X908);
    // 0x80551C18: lwc1        $f8, 0x90C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X90C);
    // 0x80551C1C: sw          $t3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r11;
    // 0x80551C20: sub.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x80551C24: sw          $a3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r7;
    // 0x80551C28: sw          $a1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r5;
    // 0x80551C2C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80551C30: swc1        $f18, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->f18.u32l;
    // 0x80551C34: jal         0x80066DE4
    // 0x80551C38: sub.s       $f26, $f8, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f24.fl;
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x80551C38: sub.s       $f26, $f8, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f26.fl = ctx->f8.fl - ctx->f24.fl;
    after_2:
    // 0x80551C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80551C40: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    // 0x80551C44: swc1        $f20, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->f20.u32l;
    // 0x80551C48: jal         0x80066E88
    // 0x80551C4C: swc1        $f24, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f24.u32l;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x80551C4C: swc1        $f24, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->f24.u32l;
    after_3:
    // 0x80551C50: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80551C54: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80551C58: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80551C5C: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80551C60: lwc1        $f18, 0x194($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X194);
    // 0x80551C64: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x80551C68: mul.s       $f2, $f30, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80551C6C: lw          $v0, 0x84($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X84);
    // 0x80551C70: lw          $a3, 0x94($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X94);
    // 0x80551C74: mul.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80551C78: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80551C7C: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x80551C80: mul.s       $f14, $f20, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80551C84: addiu       $s0, $s5, 0x40
    ctx->r16 = ADD32(ctx->r21, 0X40);
    // 0x80551C88: addiu       $s1, $s7, 0x40
    ctx->r17 = ADD32(ctx->r23, 0X40);
    // 0x80551C8C: mul.s       $f16, $f30, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x80551C90: addiu       $s2, $s3, 0x40
    ctx->r18 = ADD32(ctx->r19, 0X40);
    // 0x80551C94: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80551C98: addiu       $a2, $a3, 0x8
    ctx->r6 = ADD32(ctx->r7, 0X8);
    // 0x80551C9C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80551CA0: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80551CA4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80551CA8: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x80551CAC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80551CB0: add.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80551CB4: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x80551CB8: sh          $v1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r3;
    // 0x80551CBC: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80551CC0: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80551CC4: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80551CC8: sub.s       $f4, $f16, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80551CCC: sh          $a0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r4;
    // 0x80551CD0: sh          $a0, 0x2($s5)
    MEM_H(0X2, ctx->r21) = ctx->r4;
    // 0x80551CD4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80551CD8: sub.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f26.fl;
    // 0x80551CDC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80551CE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80551CE4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80551CE8: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80551CEC: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x80551CF0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80551CF4: nop

    // 0x80551CF8: sh          $t4, 0x2($s7)
    MEM_H(0X2, ctx->r23) = ctx->r12;
    // 0x80551CFC: sub.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80551D00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80551D04: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80551D08: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80551D0C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80551D10: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80551D14: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x80551D18: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x80551D1C: sh          $t5, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r13;
    // 0x80551D20: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80551D24: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80551D28: nop

    // 0x80551D2C: sh          $t7, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r15;
    // 0x80551D30: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x80551D34: sh          $zero, 0x8($s3)
    MEM_H(0X8, ctx->r19) = 0;
    // 0x80551D38: sh          $zero, 0x8($s7)
    MEM_H(0X8, ctx->r23) = 0;
    // 0x80551D3C: sh          $zero, 0x8($s5)
    MEM_H(0X8, ctx->r21) = 0;
    // 0x80551D40: sh          $zero, 0xA($s3)
    MEM_H(0XA, ctx->r19) = 0;
    // 0x80551D44: lh          $t8, 0xA($s3)
    ctx->r24 = MEM_H(ctx->r19, 0XA);
    // 0x80551D48: addiu       $s3, $v0, 0x40
    ctx->r19 = ADD32(ctx->r2, 0X40);
    // 0x80551D4C: sh          $t8, 0xA($s5)
    MEM_H(0XA, ctx->r21) = ctx->r24;
    // 0x80551D50: lh          $t4, 0x168($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X168);
    // 0x80551D54: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80551D58: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x80551D5C: lh          $t9, 0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA);
    // 0x80551D60: sh          $t9, 0xA($s7)
    MEM_H(0XA, ctx->r23) = ctx->r25;
    // 0x80551D64: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
L_80551D68:
    // 0x80551D68: lui         $t5, 0x8055
    ctx->r13 = S32(RELOC_HI16(354, 0X4098) << 16);
    // 0x80551D6C: addiu       $t5, $t5, 0x4BB8
    ctx->r13 = ADD32(ctx->r13, (int16_t)RELOC_LO16(354, 0X4098));
    // 0x80551D70: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80551D74: addiu       $v0, $sp, 0xA0
    ctx->r2 = ADD32(ctx->r29, 0XA0);
    // 0x80551D78: addiu       $v1, $sp, 0xB0
    ctx->r3 = ADD32(ctx->r29, 0XB0);
    // 0x80551D7C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80551D80: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80551D84: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80551D88: addiu       $a0, $sp, 0xC0
    ctx->r4 = ADD32(ctx->r29, 0XC0);
    // 0x80551D8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80551D90: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80551D94: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    // 0x80551D98: addiu       $t0, $sp, 0xF0
    ctx->r8 = ADD32(ctx->r29, 0XF0);
    // 0x80551D9C: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x80551DA0: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80551DA4: addiu       $t1, $sp, 0x100
    ctx->r9 = ADD32(ctx->r29, 0X100);
    // 0x80551DA8: addiu       $t2, $sp, 0x110
    ctx->r10 = ADD32(ctx->r29, 0X110);
    // 0x80551DAC: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x80551DB0: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x80551DB4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80551DB8: sw          $t8, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r24;
    // 0x80551DBC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80551DC0: sw          $t4, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r12;
    // 0x80551DC4: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x80551DC8: sw          $t8, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r24;
    // 0x80551DCC: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80551DD0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80551DD4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80551DD8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80551DDC: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80551DE0: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x80551DE4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80551DE8: sw          $t5, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r13;
    // 0x80551DEC: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x80551DF0: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x80551DF4: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80551DF8: sw          $t6, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r14;
    // 0x80551DFC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80551E00: sw          $t7, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r15;
    // 0x80551E04: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    // 0x80551E08: sw          $t6, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r14;
    // 0x80551E0C: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80551E10: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80551E14: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80551E18: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80551E1C: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x80551E20: lw          $t8, 0xC($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XC);
    // 0x80551E24: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80551E28: sw          $t4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r12;
    // 0x80551E2C: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x80551E30: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80551E34: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80551E38: sw          $t9, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r25;
    // 0x80551E3C: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x80551E40: sw          $t5, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r13;
    // 0x80551E44: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    // 0x80551E48: sw          $t9, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r25;
    // 0x80551E4C: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80551E50: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80551E54: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x80551E58: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80551E5C: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80551E60: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x80551E64: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80551E68: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x80551E6C: sw          $t6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r14;
    // 0x80551E70: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80551E74: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x80551E78: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x80551E7C: lw          $t4, 0x8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8);
    // 0x80551E80: sw          $t4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r12;
    // 0x80551E84: lw          $t8, 0xC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XC);
    // 0x80551E88: sw          $t8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r24;
    // 0x80551E8C: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x80551E90: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80551E94: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80551E98: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80551E9C: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x80551EA0: lw          $t9, 0xC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XC);
    // 0x80551EA4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80551EA8: sw          $t5, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r13;
    // 0x80551EAC: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x80551EB0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80551EB4: lw          $t6, 0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X4);
    // 0x80551EB8: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80551EBC: lw          $t7, 0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X8);
    // 0x80551EC0: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x80551EC4: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x80551EC8: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x80551ECC: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x80551ED0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80551ED4: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80551ED8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80551EDC: lw          $t4, 0x8($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X8);
    // 0x80551EE0: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    // 0x80551EE4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80551EE8: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80551EEC: sw          $t8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r24;
    // 0x80551EF0: sw          $t5, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r13;
    // 0x80551EF4: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x80551EF8: sw          $t9, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r25;
    // 0x80551EFC: lw          $t5, 0x8($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X8);
    // 0x80551F00: sw          $t5, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r13;
    // 0x80551F04: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x80551F08: sw          $t9, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r25;
    // 0x80551F0C: lw          $t6, 0x4($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X4);
    // 0x80551F10: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80551F14: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80551F18: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80551F1C: lw          $t7, 0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X8);
    // 0x80551F20: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x80551F24: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80551F28: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x80551F2C: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
    // 0x80551F30: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x80551F34: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x80551F38: sw          $t8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r24;
    // 0x80551F3C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80551F40: sw          $t4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r12;
    // 0x80551F44: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x80551F48: sw          $t8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r24;
    // 0x80551F4C: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80551F50: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80551F54: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x80551F58: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80551F5C: lw          $t5, 0x8($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X8);
    // 0x80551F60: sw          $t5, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r13;
    // 0x80551F64: lw          $t9, 0xC($t2)
    ctx->r25 = MEM_W(ctx->r10, 0XC);
    // 0x80551F68: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80551F6C: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x80551F70: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80551F74: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x80551F78: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80551F7C: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80551F80: sw          $t3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r11;
    // 0x80551F84: sw          $a2, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r6;
    // 0x80551F88: sub.s       $f24, $f10, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80551F8C: sw          $a1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r5;
    // 0x80551F90: sub.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80551F94: jal         0x80067114
    // 0x80551F98: sub.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f24.fl;
    func_80067114(rdram, ctx);
        goto after_4;
    // 0x80551F98: sub.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f24.fl;
    after_4:
    // 0x80551F9C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80551FA0: jal         0x80066DE4
    // 0x80551FA4: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_5;
    // 0x80551FA4: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    after_5:
    // 0x80551FA8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80551FAC: jal         0x80066E88
    // 0x80551FB0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066E88(rdram, ctx);
        goto after_6;
    // 0x80551FB0: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_6:
    // 0x80551FB4: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80551FB8: mul.s       $f2, $f30, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80551FBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80551FC0: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x80551FC4: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x80551FC8: mul.s       $f12, $f18, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80551FCC: lw          $a2, 0x144($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X144);
    // 0x80551FD0: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x80551FD4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80551FD8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80551FDC: mov.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.fl = ctx->f20.fl;
    // 0x80551FE0: mul.s       $f16, $f30, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x80551FE4: mov.s       $f26, $f24
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    ctx->f26.fl = ctx->f24.fl;
    // 0x80551FE8: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80551FEC: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80551FF0: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80551FF4: add.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80551FF8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80551FFC: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80552000: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80552004: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80552008: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8055200C: sh          $v1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r3;
    // 0x80552010: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80552014: sh          $v1, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r3;
    // 0x80552018: sh          $v1, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r3;
    // 0x8055201C: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80552020: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80552024: sh          $v1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r3;
    // 0x80552028: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x8055202C: sh          $a0, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r4;
    // 0x80552030: sh          $a0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r4;
    // 0x80552034: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80552038: sh          $a0, 0x2($fp)
    MEM_H(0X2, ctx->r30) = ctx->r4;
    // 0x8055203C: sh          $a0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r4;
    // 0x80552040: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80552044: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80552048: mul.s       $f6, $f12, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x8055204C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80552050: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x80552054: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x80552058: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8055205C: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80552060: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80552064: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80552068: nop

    // 0x8055206C: sh          $v1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r3;
    // 0x80552070: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x80552074: sh          $v1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r3;
    // 0x80552078: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8055207C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80552080: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80552084: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80552088: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8055208C: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x80552090: sh          $a0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r4;
    // 0x80552094: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80552098: nop

    // 0x8055209C: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
    // 0x805520A0: beq         $s7, $zero, L_805520D0
    if (ctx->r23 == 0) {
        // 0x805520A4: sh          $v0, 0x2($s2)
        MEM_H(0X2, ctx->r18) = ctx->r2;
            goto L_805520D0;
    }
    // 0x805520A4: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x805520A8: sll         $v0, $s7, 6
    ctx->r2 = S32(ctx->r23 << 6);
    // 0x805520AC: sh          $v0, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r2;
    // 0x805520B0: sh          $v0, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r2;
    // 0x805520B4: sh          $v0, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r2;
    // 0x805520B8: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // 0x805520BC: sh          $v0, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r2;
    // 0x805520C0: sh          $v0, 0x8($fp)
    MEM_H(0X8, ctx->r30) = ctx->r2;
    // 0x805520C4: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x805520C8: b           L_805520FC
    // 0x805520CC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
        goto L_805520FC;
    // 0x805520CC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_805520D0:
    // 0x805520D0: sll         $v0, $s7, 6
    ctx->r2 = S32(ctx->r23 << 6);
    // 0x805520D4: sh          $v0, 0x8($s3)
    MEM_H(0X8, ctx->r19) = ctx->r2;
    // 0x805520D8: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // 0x805520DC: sh          $v0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r2;
    // 0x805520E0: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x805520E4: lh          $t6, 0x16A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X16A);
    // 0x805520E8: sh          $t6, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r14;
    // 0x805520EC: lh          $v1, 0x8($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X8);
    // 0x805520F0: sh          $v1, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r3;
    // 0x805520F4: sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
    // 0x805520F8: sh          $v1, 0x8($fp)
    MEM_H(0X8, ctx->r30) = ctx->r3;
L_805520FC:
    // 0x805520FC: sh          $zero, 0xA($s6)
    MEM_H(0XA, ctx->r22) = 0;
    // 0x80552100: lh          $v1, 0xA($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XA);
    // 0x80552104: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x80552108: andi        $s7, $s7, 0x3F
    ctx->r23 = ctx->r23 & 0X3F;
    // 0x8055210C: sh          $v1, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r3;
    // 0x80552110: sh          $v1, 0xA($fp)
    MEM_H(0XA, ctx->r30) = ctx->r3;
    // 0x80552114: sh          $v1, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r3;
    // 0x80552118: lh          $t7, 0x168($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X168);
    // 0x8055211C: sll         $s7, $s7, 16
    ctx->r23 = S32(ctx->r23 << 16);
    // 0x80552120: addiu       $s0, $s0, 0x40
    ctx->r16 = ADD32(ctx->r16, 0X40);
    // 0x80552124: sh          $t7, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r15;
    // 0x80552128: lh          $v1, 0xA($s4)
    ctx->r3 = MEM_H(ctx->r20, 0XA);
    // 0x8055212C: addiu       $s1, $s1, 0x40
    ctx->r17 = ADD32(ctx->r17, 0X40);
    // 0x80552130: addiu       $fp, $fp, 0x40
    ctx->r30 = ADD32(ctx->r30, 0X40);
    // 0x80552134: sh          $v1, 0xA($s3)
    MEM_H(0XA, ctx->r19) = ctx->r3;
    // 0x80552138: sh          $v1, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r3;
    // 0x8055213C: addiu       $a1, $a1, 0x40
    ctx->r5 = ADD32(ctx->r5, 0X40);
    // 0x80552140: addiu       $s2, $s2, 0x40
    ctx->r18 = ADD32(ctx->r18, 0X40);
    // 0x80552144: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x80552148: addiu       $s6, $s6, 0x40
    ctx->r22 = ADD32(ctx->r22, 0X40);
    // 0x8055214C: addiu       $s4, $s4, 0x40
    ctx->r20 = ADD32(ctx->r20, 0X40);
    // 0x80552150: sra         $s7, $s7, 16
    ctx->r23 = S32(SIGNED(ctx->r23) >> 16);
    // 0x80552154: bne         $s5, $at, L_80551D68
    if (ctx->r21 != ctx->r1) {
        // 0x80552158: sh          $v1, -0x36($s1)
        MEM_H(-0X36, ctx->r17) = ctx->r3;
            goto L_80551D68;
    }
    // 0x80552158: sh          $v1, -0x36($s1)
    MEM_H(-0X36, ctx->r17) = ctx->r3;
    // 0x8055215C: lui         $t4, 0x8055
    ctx->r12 = S32(RELOC_HI16(354, 0X4098) << 16);
    // 0x80552160: addiu       $t4, $t4, 0x4BB8
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(354, 0X4098));
    // 0x80552164: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80552168: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x8055216C: addiu       $t8, $sp, 0xF0
    ctx->r24 = ADD32(ctx->r29, 0XF0);
    // 0x80552170: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80552174: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80552178: lw          $t9, 0xC($t4)
    ctx->r25 = MEM_W(ctx->r12, 0XC);
    // 0x8055217C: lw          $t5, 0x8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X8);
    // 0x80552180: addiu       $t6, $sp, 0xF0
    ctx->r14 = ADD32(ctx->r29, 0XF0);
    // 0x80552184: sw          $t9, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r25;
    // 0x80552188: sw          $t5, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r13;
    // 0x8055218C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80552190: addiu       $t9, $sp, 0xF0
    ctx->r25 = ADD32(ctx->r29, 0XF0);
    // 0x80552194: addiu       $t4, $sp, 0x100
    ctx->r12 = ADD32(ctx->r29, 0X100);
    // 0x80552198: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8055219C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x805521A0: sw          $t7, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r15;
    // 0x805521A4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x805521A8: sw          $t8, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r24;
    // 0x805521AC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x805521B0: sw          $t7, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r15;
    // 0x805521B4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x805521B8: addiu       $t7, $sp, 0x100
    ctx->r15 = ADD32(ctx->r29, 0X100);
    // 0x805521BC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x805521C0: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x805521C4: sw          $t5, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r13;
    // 0x805521C8: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x805521CC: sw          $t6, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r14;
    // 0x805521D0: lw          $t5, 0xC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0XC);
    // 0x805521D4: addiu       $t9, $sp, 0x110
    ctx->r25 = ADD32(ctx->r29, 0X110);
    // 0x805521D8: sw          $t5, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r13;
    // 0x805521DC: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x805521E0: addiu       $t5, $sp, 0x100
    ctx->r13 = ADD32(ctx->r29, 0X100);
    // 0x805521E4: sw          $t4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r12;
    // 0x805521E8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x805521EC: sw          $t8, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r24;
    // 0x805521F0: lw          $t4, 0x8($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X8);
    // 0x805521F4: sw          $t4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r12;
    // 0x805521F8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805521FC: sw          $t8, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r24;
    // 0x80552200: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80552204: addiu       $t8, $sp, 0x110
    ctx->r24 = ADD32(ctx->r29, 0X110);
    // 0x80552208: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8055220C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80552210: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80552214: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80552218: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x8055221C: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80552220: addiu       $t5, $sp, 0x110
    ctx->r13 = ADD32(ctx->r29, 0X110);
    // 0x80552224: sw          $t6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r14;
    // 0x80552228: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8055222C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80552230: lw          $t4, 0x4($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X4);
    // 0x80552234: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x80552238: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8055223C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x80552240: lw          $t4, 0xC($t8)
    ctx->r12 = MEM_W(ctx->r24, 0XC);
    // 0x80552244: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
    // 0x80552248: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8055224C: sw          $t7, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r15;
    // 0x80552250: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80552254: sw          $t6, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r14;
    // 0x80552258: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8055225C: sw          $t7, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r15;
    // 0x80552260: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80552264: sw          $t6, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r14;
    // 0x80552268: lwc1        $f8, 0x158($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8055226C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80552270: lwc1        $f4, 0x154($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X154);
    // 0x80552274: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80552278: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8055227C: sw          $t3, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r11;
    // 0x80552280: sw          $a1, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r5;
    // 0x80552284: sub.s       $f24, $f10, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80552288: sub.s       $f12, $f18, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x8055228C: jal         0x80067114
    // 0x80552290: sub.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f24.fl;
    func_80067114(rdram, ctx);
        goto after_7;
    // 0x80552290: sub.s       $f14, $f26, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f26.fl - ctx->f24.fl;
    after_7:
    // 0x80552294: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80552298: jal         0x80066DE4
    // 0x8055229C: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    func_80066DE4(rdram, ctx);
        goto after_8;
    // 0x8055229C: mov.s       $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    ctx->f28.fl = ctx->f12.fl;
    after_8:
    // 0x805522A0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x805522A4: jal         0x80066E88
    // 0x805522A8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066E88(rdram, ctx);
        goto after_9;
    // 0x805522A8: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_9:
    // 0x805522AC: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x805522B0: mul.s       $f2, $f30, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x805522B4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805522B8: lui         $at, 0xC240
    ctx->r1 = S32(0XC240 << 16);
    // 0x805522BC: lw          $a1, 0x130($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X130);
    // 0x805522C0: mul.s       $f12, $f18, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x805522C4: lw          $t3, 0x164($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X164);
    // 0x805522C8: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x805522CC: nop

    // 0x805522D0: mul.s       $f16, $f30, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x805522D4: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x805522D8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x805522DC: add.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x805522E0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805522E4: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x805522E8: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x805522EC: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x805522F0: sh          $v1, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r3;
    // 0x805522F4: sh          $v1, 0x0($fp)
    MEM_H(0X0, ctx->r30) = ctx->r3;
    // 0x805522F8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x805522FC: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80552300: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80552304: sub.s       $f8, $f16, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80552308: sh          $a0, 0x2($s4)
    MEM_H(0X2, ctx->r20) = ctx->r4;
    // 0x8055230C: sh          $a0, 0x2($fp)
    MEM_H(0X2, ctx->r30) = ctx->r4;
    // 0x80552310: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80552314: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80552318: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8055231C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80552320: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80552324: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80552328: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x8055232C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80552330: nop

    // 0x80552334: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x80552338: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8055233C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80552340: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x80552344: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80552348: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8055234C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80552350: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80552354: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80552358: sh          $t4, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r12;
    // 0x8055235C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80552360: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80552364: nop

    // 0x80552368: sh          $t5, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r13;
    // 0x8055236C: lh          $t6, 0x16A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X16A);
    // 0x80552370: sh          $t6, 0x8($s4)
    MEM_H(0X8, ctx->r20) = ctx->r14;
    // 0x80552374: lh          $v1, 0x8($s4)
    ctx->r3 = MEM_H(ctx->r20, 0X8);
    // 0x80552378: sh          $v1, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r3;
    // 0x8055237C: sh          $v1, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r3;
    // 0x80552380: sh          $v1, 0x8($fp)
    MEM_H(0X8, ctx->r30) = ctx->r3;
    // 0x80552384: sh          $zero, 0xA($s6)
    MEM_H(0XA, ctx->r22) = 0;
    // 0x80552388: lh          $t7, 0xA($s6)
    ctx->r15 = MEM_H(ctx->r22, 0XA);
    // 0x8055238C: sh          $t7, 0xA($fp)
    MEM_H(0XA, ctx->r30) = ctx->r15;
    // 0x80552390: lh          $t8, 0x168($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X168);
    // 0x80552394: sh          $t8, 0xA($s4)
    MEM_H(0XA, ctx->r20) = ctx->r24;
    // 0x80552398: lh          $t4, 0xA($s4)
    ctx->r12 = MEM_H(ctx->r20, 0XA);
    // 0x8055239C: sh          $t4, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r12;
    // 0x805523A0: lh          $t9, 0x9B0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X9B0);
    // 0x805523A4: lh          $t5, 0x9B2($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X9B2);
    // 0x805523A8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x805523AC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x805523B0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805523B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805523B8: swc1        $f4, 0xDF0($t3)
    MEM_W(0XDF0, ctx->r11) = ctx->f4.u32l;
    // 0x805523BC: swc1        $f8, 0xDF4($t3)
    MEM_W(0XDF4, ctx->r11) = ctx->f8.u32l;
    // 0x805523C0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x805523C4: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x805523C8: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x805523CC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x805523D0: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x805523D4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x805523D8: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x805523DC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x805523E0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x805523E4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x805523E8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x805523EC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x805523F0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805523F4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805523F8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805523FC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80552400: jr          $ra
    // 0x80552404: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
    return;
    // 0x80552404: addiu       $sp, $sp, 0x1A8
    ctx->r29 = ADD32(ctx->r29, 0X1A8);
;}
RECOMP_FUNC void func_807A0244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A0244: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807A0248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807A024C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807A0250: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807A0254: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807A0258: jal         0x807A008C
    // 0x807A025C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    func_807A008C(rdram, ctx);
        goto after_0;
    // 0x807A025C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    after_0:
    // 0x807A0260: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x807A0264: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(838, 0X16B4) << 16);
    // 0x807A0268: addiu       $t7, $t7, 0xD14
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(838, 0X16B4));
    // 0x807A026C: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x807A0270: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807A0274: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x807A0278: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x807A027C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x807A0280: sw          $t9, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r25;
    // 0x807A0284: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807A0288: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807A028C: jal         0x80048378
    // 0x807A0290: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x807A0290: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    after_1:
    // 0x807A0294: lw          $a2, 0x1F4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1F4);
    // 0x807A0298: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    // 0x807A029C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A02A0: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x807A02A4: jal         0x80045A34
    // 0x807A02A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80045A34(rdram, ctx);
        goto after_2;
    // 0x807A02A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x807A02AC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807A02B0: bne         $v0, $zero, L_807A02D0
    if (ctx->r2 != 0) {
        // 0x807A02B4: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_807A02D0;
    }
    // 0x807A02B4: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x807A02B8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x807A02BC: sb          $t1, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r9;
    // 0x807A02C0: jal         0x800447C8
    // 0x807A02C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_3;
    // 0x807A02C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807A02C8: b           L_807A0350
    // 0x807A02CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807A0350;
    // 0x807A02CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A02D0:
    // 0x807A02D0: lw          $t2, 0x174($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X174);
    // 0x807A02D4: lw          $t5, 0x174($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X174);
    // 0x807A02D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A02DC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x807A02E0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x807A02E4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x807A02E8: lhu         $t4, 0x18($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X18);
    // 0x807A02EC: sh          $t4, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r12;
    // 0x807A02F0: lw          $t7, 0x174($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X174);
    // 0x807A02F4: lw          $t0, 0x174($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X174);
    // 0x807A02F8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x807A02FC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x807A0300: lhu         $t9, 0x1A($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X1A);
    // 0x807A0304: sh          $t9, 0x1A($t1)
    MEM_H(0X1A, ctx->r9) = ctx->r25;
    // 0x807A0308: lw          $t2, 0x1F4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F4);
    // 0x807A030C: sh          $zero, 0x0($t2)
    MEM_H(0X0, ctx->r10) = 0;
    // 0x807A0310: jal         0x807A00F8
    // 0x807A0314: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_807A00F8(rdram, ctx);
        goto after_4;
    // 0x807A0314: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x807A0318: bne         $v0, $zero, L_807A0338
    if (ctx->r2 != 0) {
        // 0x807A031C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_807A0338;
    }
    // 0x807A031C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x807A0320: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x807A0324: sb          $t3, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r11;
    // 0x807A0328: jal         0x800447C8
    // 0x807A032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_5;
    // 0x807A032C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x807A0330: b           L_807A0350
    // 0x807A0334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807A0350;
    // 0x807A0334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A0338:
    // 0x807A0338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807A033C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807A0340: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x807A0344: jal         0x807A0380
    // 0x807A0348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807A0380(rdram, ctx);
        goto after_6;
    // 0x807A0348: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x807A034C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807A0350:
    // 0x807A0350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807A0354: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807A0358: jr          $ra
    // 0x807A035C: nop

    return;
    // 0x807A035C: nop

;}
RECOMP_FUNC void func_8051F4A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8051F4A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8051F4AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8051F4B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8051F4B4: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x8051F4B8: jalr        $t9
    // 0x8051F4BC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8051F4BC: nop

    after_0:
    // 0x8051F4C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8051F4C4: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x8051F4C8: lw          $t8, 0x14C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14C);
    // 0x8051F4CC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8051F4D0: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x8051F4D4: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x8051F4D8: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x8051F4DC: jal         0x8004894C
    // 0x8051F4E0: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    func_8004894C(rdram, ctx);
        goto after_1;
    // 0x8051F4E0: sh          $t2, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r10;
    after_1:
    // 0x8051F4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8051F4E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8051F4EC: jr          $ra
    // 0x8051F4F0: nop

    return;
    // 0x8051F4F0: nop

;}
RECOMP_FUNC void func_805159E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805159E4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x805159E8: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x805159EC: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x805159F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805159F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805159F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805159FC: bne         $t7, $zero, L_80515A88
    if (ctx->r15 != 0) {
        // 0x80515A00: lw          $a3, 0x1F4($a0)
        ctx->r7 = MEM_W(ctx->r4, 0X1F4);
            goto L_80515A88;
    }
    // 0x80515A00: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x80515A04: lbu         $t8, 0x14($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X14);
    // 0x80515A08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80515A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80515A10: bne         $v0, $t8, L_80515A20
    if (ctx->r2 != ctx->r24) {
        // 0x80515A14: lui         $a2, 0x8006
        ctx->r6 = S32(0X8006 << 16);
            goto L_80515A20;
    }
    // 0x80515A14: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80515A18: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
    // 0x80515A1C: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_80515A20:
    // 0x80515A20: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80515A24: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80515A28: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x80515A2C: sb          $v0, 0x10($t9)
    MEM_B(0X10, ctx->r25) = ctx->r2;
    // 0x80515A30: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x80515A34: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80515A38: jal         0x8005A994
    // 0x80515A3C: lw          $a0, 0x478($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X478);
    func_8005A994(rdram, ctx);
        goto after_0;
    // 0x80515A3C: lw          $a0, 0x478($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X478);
    after_0:
    // 0x80515A40: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80515A44: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80515A48: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80515A4C: lw          $t0, 0x478($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X478);
    // 0x80515A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80515A54: swc1        $f12, 0xB0($t0)
    MEM_W(0XB0, ctx->r8) = ctx->f12.u32l;
    // 0x80515A58: lw          $v0, 0x478($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X478);
    // 0x80515A5C: lwc1        $f4, 0xB0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80515A60: jal         0x8006CA74
    // 0x80515A64: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    func_8006CA74(rdram, ctx);
        goto after_1;
    // 0x80515A64: swc1        $f4, 0xAC($v0)
    MEM_W(0XAC, ctx->r2) = ctx->f4.u32l;
    after_1:
    // 0x80515A68: jal         0x805157F4
    // 0x80515A6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_805157F4(rdram, ctx);
        goto after_2;
    // 0x80515A6C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80515A70: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80515A74: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80515A78: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80515A7C: sb          $zero, 0x165($t2)
    MEM_B(0X165, ctx->r10) = 0;
    // 0x80515A80: jal         0x80515DD4
    // 0x80515A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80515DD4(rdram, ctx);
        goto after_3;
    // 0x80515A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_80515A88:
    // 0x80515A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80515A8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80515A90: jr          $ra
    // 0x80515A94: nop

    return;
    // 0x80515A94: nop

;}
RECOMP_FUNC void func_8004F7C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F7C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8004F7C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004F7CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004F7D0: lw          $s0, 0x1B8($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1B8);
    // 0x8004F7D4: jal         0x8006A99C
    // 0x8004F7D8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    func_8006A99C(rdram, ctx);
        goto after_0;
    // 0x8004F7D8: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    after_0:
    // 0x8004F7DC: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8004F7E0: jal         0x8006A99C
    // 0x8004F7E4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    func_8006A99C(rdram, ctx);
        goto after_1;
    // 0x8004F7E4: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    after_1:
    // 0x8004F7E8: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x8004F7EC: jal         0x8006A99C
    // 0x8004F7F0: lh          $a0, 0x3E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X3E);
    func_8006A99C(rdram, ctx);
        goto after_2;
    // 0x8004F7F0: lh          $a0, 0x3E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X3E);
    after_2:
    // 0x8004F7F4: sh          $v0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r2;
    // 0x8004F7F8: jal         0x8006A99C
    // 0x8004F7FC: lh          $a0, 0x40($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X40);
    func_8006A99C(rdram, ctx);
        goto after_3;
    // 0x8004F7FC: lh          $a0, 0x40($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X40);
    after_3:
    // 0x8004F800: lbu         $v1, 0x4D($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4D);
    // 0x8004F804: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8004F808: bnel        $v1, $zero, L_8004F848
    if (ctx->r3 != 0) {
        // 0x8004F80C: sb          $zero, 0x4D($s0)
        MEM_B(0X4D, ctx->r16) = 0;
            goto L_8004F848;
    }
    goto skip_0;
    // 0x8004F80C: sb          $zero, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = 0;
    skip_0:
    // 0x8004F810: lbu         $t6, 0x4C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4C);
    // 0x8004F814: lbu         $t7, 0x3C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3C);
    // 0x8004F818: lh          $t8, 0x2A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X2A);
    // 0x8004F81C: lh          $t9, 0x26($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X26);
    // 0x8004F820: xor         $v1, $t6, $t7
    ctx->r3 = ctx->r14 ^ ctx->r15;
    // 0x8004F824: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8004F828: bne         $v1, $zero, L_8004F844
    if (ctx->r3 != 0) {
        // 0x8004F82C: xor         $a0, $t8, $t9
        ctx->r4 = ctx->r24 ^ ctx->r25;
            goto L_8004F844;
    }
    // 0x8004F82C: xor         $a0, $t8, $t9
    ctx->r4 = ctx->r24 ^ ctx->r25;
    // 0x8004F830: sltu        $v1, $zero, $a0
    ctx->r3 = 0 < ctx->r4 ? 1 : 0;
    // 0x8004F834: bne         $v1, $zero, L_8004F844
    if (ctx->r3 != 0) {
        // 0x8004F838: lh          $t0, 0x28($sp)
        ctx->r8 = MEM_H(ctx->r29, 0X28);
            goto L_8004F844;
    }
    // 0x8004F838: lh          $t0, 0x28($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X28);
    // 0x8004F83C: xor         $v1, $t0, $v0
    ctx->r3 = ctx->r8 ^ ctx->r2;
    // 0x8004F840: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
L_8004F844:
    // 0x8004F844: sb          $zero, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = 0;
L_8004F848:
    // 0x8004F848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F84C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004F850: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8004F854: jr          $ra
    // 0x8004F858: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8004F858: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_80581734(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581734: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80581738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8058173C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80581740: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80581744: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80581748: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8058174C: jal         0x80580CE8
    // 0x80581750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_80580CE8(rdram, ctx);
        goto after_0;
    // 0x80581750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80581754: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80581758: addiu       $a1, $zero, 0x4023
    ctx->r5 = ADD32(0, 0X4023);
    // 0x8058175C: lw          $t6, 0x16C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X16C);
    // 0x80581760: sb          $v0, 0x10($t6)
    MEM_B(0X10, ctx->r14) = ctx->r2;
    // 0x80581764: jal         0x8057EF14
    // 0x80581768: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    func_8057EF14(rdram, ctx);
        goto after_1;
    // 0x80581768: sb          $v0, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r2;
    after_1:
    // 0x8058176C: beq         $v0, $zero, L_8058177C
    if (ctx->r2 == 0) {
        // 0x80581770: lbu         $t7, 0x1F($sp)
        ctx->r15 = MEM_BU(ctx->r29, 0X1F);
            goto L_8058177C;
    }
    // 0x80581770: lbu         $t7, 0x1F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X1F);
    // 0x80581774: lw          $t8, 0x16C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X16C);
    // 0x80581778: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
L_8058177C:
    // 0x8058177C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80581780: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80581784: jr          $ra
    // 0x80581788: nop

    return;
    // 0x80581788: nop

;}
RECOMP_FUNC void func_80011AE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011AE4: beq         $a0, $zero, L_80011C34
    if (ctx->r4 == 0) {
        // 0x80011AE8: nop
    
            goto L_80011C34;
    }
    // 0x80011AE8: nop

    // 0x80011AEC: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80011AF0: bgez        $v0, L_80011B48
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011AF4: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80011B48;
    }
    // 0x80011AF4: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80011AF8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80011AFC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x80011B00: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80011B04: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80011B08: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80011B0C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80011B10: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80011B14: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80011B18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80011B1C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80011B20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011B24: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80011B28: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80011B2C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80011B30: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80011B34: add.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f16.d + ctx->f0.d;
    // 0x80011B38: div.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f18.d);
    // 0x80011B3C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80011B40: b           L_80011BB0
    // 0x80011B44: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
        goto L_80011BB0;
    // 0x80011B44: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_80011B48:
    // 0x80011B48: bne         $at, $zero, L_80011BA0
    if (ctx->r1 != 0) {
        // 0x80011B4C: addiu       $t8, $zero, 0x7F
        ctx->r24 = ADD32(0, 0X7F);
            goto L_80011BA0;
    }
    // 0x80011B4C: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x80011B50: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80011B54: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80011B58: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80011B5C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80011B60: addiu       $t0, $t9, -0x7F
    ctx->r8 = ADD32(ctx->r25, -0X7F);
    // 0x80011B64: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80011B68: lui         $at, 0x4044
    ctx->r1 = S32(0X4044 << 16);
    // 0x80011B6C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80011B70: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80011B74: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80011B78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011B7C: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80011B80: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80011B84: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80011B88: div.d       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f18.d);
    // 0x80011B8C: add.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f8.d + ctx->f0.d;
    // 0x80011B90: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80011B94: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x80011B98: b           L_80011BB0
    // 0x80011B9C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
        goto L_80011BB0;
    // 0x80011B9C: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_80011BA0:
    // 0x80011BA0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80011BA4: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80011BA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011BAC: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_80011BB0:
    // 0x80011BB0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    // 0x80011BB4: bgez        $v0, L_80011BF8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80011BB8: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_80011BF8;
    }
    // 0x80011BB8: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80011BBC: negu        $t1, $v0
    ctx->r9 = SUB32(0, ctx->r2);
    // 0x80011BC0: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80011BC4: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80011BC8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80011BCC: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80011BD0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80011BD4: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80011BD8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80011BDC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80011BE0: div.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x80011BE4: add.d       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f6.d + ctx->f0.d;
    // 0x80011BE8: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80011BEC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80011BF0: jr          $ra
    // 0x80011BF4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    return;
    // 0x80011BF4: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
L_80011BF8:
    // 0x80011BF8: bne         $at, $zero, L_80011C34
    if (ctx->r1 != 0) {
        // 0x80011BFC: addiu       $t2, $v0, -0x7F
        ctx->r10 = ADD32(ctx->r2, -0X7F);
            goto L_80011C34;
    }
    // 0x80011BFC: addiu       $t2, $v0, -0x7F
    ctx->r10 = ADD32(ctx->r2, -0X7F);
    // 0x80011C00: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80011C04: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x80011C08: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80011C0C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80011C10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80011C14: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80011C18: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80011C1C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80011C20: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80011C24: add.d       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f4.d + ctx->f0.d;
    // 0x80011C28: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x80011C2C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80011C30: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_80011C34:
    // 0x80011C34: jr          $ra
    // 0x80011C38: nop

    return;
    // 0x80011C38: nop

;}
RECOMP_FUNC void func_80033C9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C9C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033CA4: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80033CA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033CAC: lwc1        $f4, 0x90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X90);
    // 0x80033CB0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80033CB4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80033CB8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80033CBC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80033CC0: bc1tl       L_80033CF4
    if (c1cs) {
        // 0x80033CC4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80033CF4;
    }
    goto skip_0;
    // 0x80033CC4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x80033CC8: lwc1        $f6, 0x94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X94);
    // 0x80033CCC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80033CD0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80033CD4: nop

    // 0x80033CD8: bc1tl       L_80033CF4
    if (c1cs) {
        // 0x80033CDC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_80033CF4;
    }
    goto skip_1;
    // 0x80033CDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_1:
    // 0x80033CE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033CE4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80033CE8: b           L_80033D88
    // 0x80033CEC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
        goto L_80033D88;
    // 0x80033CEC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80033CF0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80033CF4:
    // 0x80033CF4: lwc1        $f12, 0x50($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X50);
    // 0x80033CF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033CFC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80033D00: nop

    // 0x80033D04: bc1fl       L_80033D30
    if (!c1cs) {
        // 0x80033D08: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80033D30;
    }
    goto skip_2;
    // 0x80033D08: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_2:
    // 0x80033D0C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80033D10: nop

    // 0x80033D14: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x80033D18: nop

    // 0x80033D1C: bc1fl       L_80033D30
    if (!c1cs) {
        // 0x80033D20: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80033D30;
    }
    goto skip_3;
    // 0x80033D20: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_3:
    // 0x80033D24: b           L_80033D58
    // 0x80033D28: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_80033D58;
    // 0x80033D28: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80033D2C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80033D30:
    // 0x80033D30: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80033D34: bc1fl       L_80033D5C
    if (!c1cs) {
        // 0x80033D38: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80033D5C;
    }
    goto skip_4;
    // 0x80033D38: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_4:
    // 0x80033D3C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80033D40: nop

    // 0x80033D44: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80033D48: nop

    // 0x80033D4C: bc1fl       L_80033D5C
    if (!c1cs) {
        // 0x80033D50: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80033D5C;
    }
    goto skip_5;
    // 0x80033D50: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_5:
    // 0x80033D54: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
L_80033D58:
    // 0x80033D58: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_80033D5C:
    // 0x80033D5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033D60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80033D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033D68: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80033D6C: jal         0x800659EC
    // 0x80033D70: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    func_800659EC(rdram, ctx);
        goto after_0;
    // 0x80033D70: add.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f16.fl;
    after_0:
    // 0x80033D74: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033D78: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D7C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80033D80: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    // 0x80033D84: swc1        $f2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f2.u32l;
L_80033D88:
    // 0x80033D88: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80033D8C: jal         0x80033760
    // 0x80033D90: swc1        $f2, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f2.u32l;
    func_80033760(rdram, ctx);
        goto after_1;
    // 0x80033D90: swc1        $f2, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f2.u32l;
    after_1:
    // 0x80033D94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033D98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033D9C: jr          $ra
    // 0x80033DA0: nop

    return;
    // 0x80033DA0: nop

;}
RECOMP_FUNC void func_8002C534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C538: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C53C: addiu       $a1, $a1, -0x3558
    ctx->r5 = ADD32(ctx->r5, -0X3558);
    // 0x8002C540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C544: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8002C548: jal         0x80028118
    // 0x8002C54C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C54C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C550: jal         0x8002C4F0
    // 0x8002C554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8002C4F0(rdram, ctx);
        goto after_1;
    // 0x8002C554: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8002C558: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8002C55C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002C564: jal         0x8002C51C
    // 0x8002C568: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_8002C51C(rdram, ctx);
        goto after_2;
    // 0x8002C568: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_2:
    // 0x8002C56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C574: jr          $ra
    // 0x8002C578: nop

    return;
    // 0x8002C578: nop

;}
RECOMP_FUNC void func_80036DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036DE4: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x80036DE8: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x80036DEC: lwc1        $f6, 0xAE8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XAE8);
    // 0x80036DF0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036DF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036DF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036DFC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80036E00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80036E04: bc1tl       L_80036E40
    if (c1cs) {
        // 0x80036E08: lwc1        $f0, 0xC4($a0)
        ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
            goto L_80036E40;
    }
    goto skip_0;
    // 0x80036E08: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    skip_0:
    // 0x80036E0C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80036E10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80036E14: lwc1        $f8, 0xAF0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAF0);
    // 0x80036E18: lwc1        $f16, 0x64($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X64);
    // 0x80036E1C: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80036E20: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80036E24: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x80036E28: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80036E2C: jal         0x80036CF0
    // 0x80036E30: swc1        $f18, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f18.u32l;
    func_80036CF0(rdram, ctx);
        goto after_0;
    // 0x80036E30: swc1        $f18, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f18.u32l;
    after_0:
    // 0x80036E34: b           L_80036ED0
    // 0x80036E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80036ED0;
    // 0x80036E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036E3C: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
L_80036E40:
    // 0x80036E40: lwc1        $f4, 0xE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XE4);
    // 0x80036E44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80036E48: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80036E4C: nop

    // 0x80036E50: bc1tl       L_80036ED0
    if (c1cs) {
        // 0x80036E54: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036ED0;
    }
    goto skip_1;
    // 0x80036E54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80036E58: lwc1        $f6, 0xE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE8);
    // 0x80036E5C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80036E60: nop

    // 0x80036E64: bc1tl       L_80036ED0
    if (c1cs) {
        // 0x80036E68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036ED0;
    }
    goto skip_2;
    // 0x80036E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80036E6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80036E70: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80036E74: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80036E78: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x80036E7C: nop

    // 0x80036E80: bc1fl       L_80036ED0
    if (!c1cs) {
        // 0x80036E84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036ED0;
    }
    goto skip_3;
    // 0x80036E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80036E88: lwc1        $f10, 0x118($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X118);
    // 0x80036E8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80036E90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80036E94: lwc1        $f4, 0xEC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XEC);
    // 0x80036E98: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80036E9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80036EA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80036EA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80036EA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80036EAC: swc1        $f2, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f2.u32l;
    // 0x80036EB0: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x80036EB4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80036EB8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80036EBC: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80036EC0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80036EC4: jal         0x80036CF0
    // 0x80036EC8: nop

    func_80036CF0(rdram, ctx);
        goto after_1;
    // 0x80036EC8: nop

    after_1:
    // 0x80036ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036ED0:
    // 0x80036ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036ED4: jr          $ra
    // 0x80036ED8: nop

    return;
    // 0x80036ED8: nop

;}
RECOMP_FUNC void func_8001A97C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001A980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001A984: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8001A988: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8001A98C: beq         $a0, $zero, L_8001A9A0
    if (ctx->r4 == 0) {
        // 0x8001A990: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8001A9A0;
    }
    // 0x8001A990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001A994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001A998: jal         0x8001A900
    // 0x8001A99C: sw          $t6, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r14;
    func_8001A900(rdram, ctx);
        goto after_0;
    // 0x8001A99C: sw          $t6, 0x8C($a0)
    MEM_W(0X8C, ctx->r4) = ctx->r14;
    after_0:
L_8001A9A0:
    // 0x8001A9A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001A9A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001A9A8: jr          $ra
    // 0x8001A9AC: nop

    return;
    // 0x8001A9AC: nop

;}
RECOMP_FUNC void func_800389BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800389C0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x800389C4: addiu       $a0, $a0, 0x3D58
    ctx->r4 = ADD32(ctx->r4, 0X3D58);
    // 0x800389C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800389CC: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x800389D0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800389D4: sw          $a0, 0x3D50($at)
    MEM_W(0X3D50, ctx->r1) = ctx->r4;
    // 0x800389D8: addiu       $a1, $a1, 0x3D68
    ctx->r5 = ADD32(ctx->r5, 0X3D68);
    // 0x800389DC: jal         0x8004667C
    // 0x800389E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x800389E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x800389E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800389E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800389EC: jr          $ra
    // 0x800389F0: nop

    return;
    // 0x800389F0: nop

;}
RECOMP_FUNC void func_806D88C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D88C0: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(625, 0X468) << 16);
    // 0x806D88C4: addiu       $v0, $v0, -0x72D8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(625, 0X468));
    // 0x806D88C8: jr          $ra
    // 0x806D88CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806D88CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806F29A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F29A0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x806F29A4: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x806F29A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F29AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F29B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F29B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806F29B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x806F29BC: lwc1        $f4, 0x4($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X4);
    // 0x806F29C0: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x806F29C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x806F29C8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F29CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F29D0: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x806F29D4: jal         0x806F295C
    // 0x806F29D8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    func_806F295C(rdram, ctx);
        goto after_0;
    // 0x806F29D8: swc1        $f8, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f8.u32l;
    after_0:
    // 0x806F29DC: bne         $v0, $zero, L_806F29F4
    if (ctx->r2 != 0) {
        // 0x806F29E0: lui         $t7, 0x8005
        ctx->r15 = S32(0X8005 << 16);
            goto L_806F29F4;
    }
    // 0x806F29E0: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x806F29E4: jal         0x800445A4
    // 0x806F29E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806F29E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F29EC: b           L_806F2A38
    // 0x806F29F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806F2A38;
    // 0x806F29F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F29F4:
    // 0x806F29F4: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x806F29F8: sw          $t7, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r15;
    // 0x806F29FC: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806F2A00: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806F2A04: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806F2A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F2A0C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F2A10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806F2A14: jal         0x806F2A48
    // 0x806F2A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806F2A48(rdram, ctx);
        goto after_2;
    // 0x806F2A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x806F2A1C: jal         0x806F2788
    // 0x806F2A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F2788(rdram, ctx);
        goto after_3;
    // 0x806F2A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806F2A24: bnel        $v0, $zero, L_806F2A38
    if (ctx->r2 != 0) {
        // 0x806F2A28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806F2A38;
    }
    goto skip_0;
    // 0x806F2A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806F2A2C: jal         0x800445A4
    // 0x806F2A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x806F2A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806F2A34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806F2A38:
    // 0x806F2A38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F2A3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F2A40: jr          $ra
    // 0x806F2A44: nop

    return;
    // 0x806F2A44: nop

;}
RECOMP_FUNC void func_8006D6F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D6F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006D6FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006D700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006D704: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8006D708: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006D70C: addiu       $a1, $a1, -0x291C
    ctx->r5 = ADD32(ctx->r5, -0X291C);
    // 0x8006D710: addiu       $a0, $a0, -0x7BC0
    ctx->r4 = ADD32(ctx->r4, -0X7BC0);
    // 0x8006D714: jal         0x80057A28
    // 0x8006D718: addiu       $a2, $sp, 0x1B
    ctx->r6 = ADD32(ctx->r29, 0X1B);
    func_80057A28(rdram, ctx);
        goto after_0;
    // 0x8006D718: addiu       $a2, $sp, 0x1B
    ctx->r6 = ADD32(ctx->r29, 0X1B);
    after_0:
    // 0x8006D71C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006D720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006D724: jr          $ra
    // 0x8006D728: nop

    return;
    // 0x8006D728: nop

;}
