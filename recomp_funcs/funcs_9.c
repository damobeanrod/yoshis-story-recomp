#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_8042D50C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042D50C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042D510: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8042D514: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8042D518: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8042D51C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8042D520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042D524: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8042D528: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(50, 0X2E64) << 16);
    // 0x8042D52C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8042D530: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042D534: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8042D538: lw          $t8, -0x28FC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(50, 0X2E64));
    // 0x8042D53C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8042D540: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8042D544: jal         0x8042D564
    // 0x8042D548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8042D564(rdram, ctx);
        goto after_0;
    // 0x8042D548: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042D54C: jal         0x8042D5C0
    // 0x8042D550: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8042D5C0(rdram, ctx);
        goto after_1;
    // 0x8042D550: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8042D554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042D558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042D55C: jr          $ra
    // 0x8042D560: nop

    return;
    // 0x8042D560: nop

;}
RECOMP_FUNC void func_8064C6A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C6A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C6A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C6AC: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8064C6B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8064C6B4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C6B8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064C6BC: nop

    // 0x8064C6C0: bc1fl       L_8064C708
    if (!c1cs) {
        // 0x8064C6C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C708;
    }
    goto skip_0;
    // 0x8064C6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C6C8: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8064C6CC: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8064C6D0: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8064C6D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064C6D8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8064C6DC: addiu       $t6, $zero, 0x24
    ctx->r14 = ADD32(0, 0X24);
    // 0x8064C6E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C6E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8064C6E8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8064C6EC: nop

    // 0x8064C6F0: bc1fl       L_8064C708
    if (!c1cs) {
        // 0x8064C6F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C708;
    }
    goto skip_1;
    // 0x8064C6F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8064C6F8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x8064C6FC: jal         0x8064CD50
    // 0x8064C700: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C700: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C708:
    // 0x8064C708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C70C: jr          $ra
    // 0x8064C710: nop

    return;
    // 0x8064C710: nop

;}
RECOMP_FUNC void func_8044263C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044263C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80442640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80442644: jal         0x80442398
    // 0x80442648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80442398(rdram, ctx);
        goto after_0;
    // 0x80442648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8044264C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80442650: bne         $v0, $at, L_80442668
    if (ctx->r2 != ctx->r1) {
        // 0x80442654: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80442668;
    }
    // 0x80442654: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80442658: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8044265C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80442660: jal         0x8044284C
    // 0x80442664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8044284C(rdram, ctx);
        goto after_1;
    // 0x80442664: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_80442668:
    // 0x80442668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8044266C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80442670: jr          $ra
    // 0x80442674: nop

    return;
    // 0x80442674: nop

;}
RECOMP_FUNC void func_80034570(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80034578: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003457C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80034580: lw          $t7, 0x78($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X78);
    // 0x80034584: beq         $t7, $zero, L_8003459C
    if (ctx->r15 == 0) {
        // 0x80034588: nop
    
            goto L_8003459C;
    }
    // 0x80034588: nop

    // 0x8003458C: jal         0x8002E428
    // 0x80034590: nop

    func_8002E428(rdram, ctx);
        goto after_0;
    // 0x80034590: nop

    after_0:
    // 0x80034594: b           L_8003459C
    // 0x80034598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8003459C;
    // 0x80034598: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003459C:
    // 0x8003459C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800345A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800345A4: jr          $ra
    // 0x800345A8: nop

    return;
    // 0x800345A8: nop

;}
RECOMP_FUNC void func_8043D320(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043D320: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043D324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8043D328: jal         0x8004700C
    // 0x8043D32C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8043D32C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8043D330: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8043D334: beq         $v0, $zero, L_8043D360
    if (ctx->r2 == 0) {
        // 0x8043D338: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8043D360;
    }
    // 0x8043D338: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8043D33C: addiu       $a0, $a1, 0xC4
    ctx->r4 = ADD32(ctx->r5, 0XC4);
    // 0x8043D340: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8043D344: jal         0x8043D1FC
    // 0x8043D348: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8043D1FC(rdram, ctx);
        goto after_1;
    // 0x8043D348: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8043D34C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8043D350: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8043D354: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8043D358: jal         0x8043D1FC
    // 0x8043D35C: addiu       $a0, $a1, 0xC8
    ctx->r4 = ADD32(ctx->r5, 0XC8);
    func_8043D1FC(rdram, ctx);
        goto after_2;
    // 0x8043D35C: addiu       $a0, $a1, 0xC8
    ctx->r4 = ADD32(ctx->r5, 0XC8);
    after_2:
L_8043D360:
    // 0x8043D360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8043D364: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043D368: jr          $ra
    // 0x8043D36C: nop

    return;
    // 0x8043D36C: nop

;}
RECOMP_FUNC void func_804EF7F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF7F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EF7FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF800: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804EF804: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x804EF808: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804EF80C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x804EF810: addiu       $a0, $zero, 0x413B
    ctx->r4 = ADD32(0, 0X413B);
    // 0x804EF814: jal         0x80047090
    // 0x804EF818: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804EF818: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_0:
    // 0x804EF81C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804EF820: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804EF824: beq         $v0, $at, L_804EF864
    if (ctx->r2 == ctx->r1) {
        // 0x804EF828: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804EF864;
    }
    // 0x804EF828: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804EF82C: lui         $at, 0x413B
    ctx->r1 = S32(0X413B << 16);
    // 0x804EF830: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x804EF834: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x804EF838: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x804EF83C: jal         0x8004613C
    // 0x804EF840: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804EF840: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x804EF844: beq         $v0, $zero, L_804EF864
    if (ctx->r2 == 0) {
        // 0x804EF848: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_804EF864;
    }
    // 0x804EF848: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x804EF84C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x804EF850: jal         0x80047F9C
    // 0x804EF854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x804EF854: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x804EF858: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x804EF85C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804EF860: sb          $t6, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r14;
L_804EF864:
    // 0x804EF864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804EF868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EF86C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x804EF870: jr          $ra
    // 0x804EF874: nop

    return;
    // 0x804EF874: nop

;}
RECOMP_FUNC void func_807B4A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B4A74: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x807B4A78: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x807B4A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B4A80: lw          $v1, 0xF54($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XF54);
    // 0x807B4A84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B4A88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_807B4A8C:
    // 0x807B4A8C: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x807B4A90: beq         $t6, $zero, L_807B4A9C
    if (ctx->r14 == 0) {
        // 0x807B4A94: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_807B4A9C;
    }
    // 0x807B4A94: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x807B4A98: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B4A9C:
    // 0x807B4A9C: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x807B4AA0: beq         $t7, $zero, L_807B4AAC
    if (ctx->r15 == 0) {
        // 0x807B4AA4: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_807B4AAC;
    }
    // 0x807B4AA4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x807B4AA8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B4AAC:
    // 0x807B4AAC: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x807B4AB0: beq         $t8, $zero, L_807B4ABC
    if (ctx->r24 == 0) {
        // 0x807B4AB4: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_807B4ABC;
    }
    // 0x807B4AB4: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x807B4AB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B4ABC:
    // 0x807B4ABC: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x807B4AC0: beq         $t9, $zero, L_807B4ACC
    if (ctx->r25 == 0) {
        // 0x807B4AC4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_807B4ACC;
    }
    // 0x807B4AC4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x807B4AC8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_807B4ACC:
    // 0x807B4ACC: bne         $a0, $a2, L_807B4A8C
    if (ctx->r4 != ctx->r6) {
        // 0x807B4AD0: srl         $v1, $v1, 1
        ctx->r3 = S32(U32(ctx->r3) >> 1);
            goto L_807B4A8C;
    }
    // 0x807B4AD0: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x807B4AD4: lw          $t3, 0xAB8($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XAB8);
    // 0x807B4AD8: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x807B4ADC: lw          $t8, 0xAC0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XAC0);
    // 0x807B4AE0: multu       $t3, $a0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B4AE4: lw          $t0, 0xAB0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XAB0);
    // 0x807B4AE8: lw          $t1, 0xAB4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XAB4);
    // 0x807B4AEC: lw          $t6, 0xABC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XABC);
    // 0x807B4AF0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x807B4AF4: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x807B4AF8: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x807B4AFC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x807B4B00: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x807B4B04: mflo        $t4
    ctx->r12 = lo;
    // 0x807B4B08: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x807B4B0C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x807B4B10: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x807B4B14: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x807B4B18: mflo        $t9
    ctx->r25 = lo;
    // 0x807B4B1C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807B4B20: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x807B4B24: slti        $at, $v1, 0x2710
    ctx->r1 = SIGNED(ctx->r3) < 0X2710 ? 1 : 0;
    // 0x807B4B28: bne         $at, $zero, L_807B4B34
    if (ctx->r1 != 0) {
        // 0x807B4B2C: nop
    
            goto L_807B4B34;
    }
    // 0x807B4B2C: nop

    // 0x807B4B30: addiu       $v1, $zero, 0x270F
    ctx->r3 = ADD32(0, 0X270F);
L_807B4B34:
    // 0x807B4B34: jr          $ra
    // 0x807B4B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x807B4B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_806F66C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F66C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F66CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F66D0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x806F66D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x806F66D8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F66DC: lui         $t8, 0x806F
    ctx->r24 = S32(RELOC_HI16(688, 0X608) << 16);
    // 0x806F66E0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806F66E4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x806F66E8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x806F66EC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F66F0: lw          $t8, 0x6CA8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(688, 0X608));
    // 0x806F66F4: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x806F66F8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x806F66FC: jal         0x80048490
    // 0x806F6700: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x806F6700: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x806F6704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F6708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F670C: jr          $ra
    // 0x806F6710: nop

    return;
    // 0x806F6710: nop

;}
RECOMP_FUNC void func_8079EDB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079EDB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8079EDBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079EDC0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8079EDC4: lw          $a3, 0x1F4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079EDC8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8079EDCC: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8079EDD0: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8079EDD4: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8079EDD8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8079EDDC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8079EDE0: jal         0x8079E4CC
    // 0x8079EDE4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    func_8079E4CC(rdram, ctx);
        goto after_0;
    // 0x8079EDE4: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8079EDE8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8079EDEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8079EDF0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8079EDF4: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8079EDF8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8079EDFC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8079EE00: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8079EE04: bc1fl       L_8079EE14
    if (!c1cs) {
        // 0x8079EE08: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8079EE14;
    }
    goto skip_0;
    // 0x8079EE08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x8079EE0C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8079EE10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8079EE14:
    // 0x8079EE14: swc1        $f2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f2.u32l;
    // 0x8079EE18: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8079EE1C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8079EE20: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1728) << 16);
    // 0x8079EE24: bc1fl       L_8079EE34
    if (!c1cs) {
        // 0x8079EE28: lwc1        $f8, 0x28($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8079EE34;
    }
    goto skip_1;
    // 0x8079EE28: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    skip_1:
    // 0x8079EE2C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8079EE30: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_8079EE34:
    // 0x8079EE34: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8079EE38: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8079EE3C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8079EE40: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8079EE44: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x8079EE48: nop

    // 0x8079EE4C: beql        $a0, $t8, L_8079EE5C
    if (ctx->r4 == ctx->r24) {
        // 0x8079EE50: sw          $a0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r4;
            goto L_8079EE5C;
    }
    goto skip_2;
    // 0x8079EE50: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    skip_2:
    // 0x8079EE54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079EE58: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
L_8079EE5C:
    // 0x8079EE5C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8079EE60: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x8079EE64: nop

    // 0x8079EE68: bc1fl       L_8079EE78
    if (!c1cs) {
        // 0x8079EE6C: lwc1        $f4, 0x2C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8079EE78;
    }
    goto skip_3;
    // 0x8079EE6C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x8079EE70: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8079EE74: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
L_8079EE78:
    // 0x8079EE78: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8079EE7C: nop

    // 0x8079EE80: bc1fl       L_8079EE90
    if (!c1cs) {
        // 0x8079EE84: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8079EE90;
    }
    goto skip_4;
    // 0x8079EE84: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x8079EE88: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8079EE8C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
L_8079EE90:
    // 0x8079EE90: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8079EE94: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8079EE98: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8079EE9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8079EEA0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8079EEA4: nop

    // 0x8079EEA8: beq         $v1, $t0, L_8079EEB4
    if (ctx->r3 == ctx->r8) {
        // 0x8079EEAC: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_8079EEB4;
    }
    // 0x8079EEAC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8079EEB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8079EEB4:
    // 0x8079EEB4: addu        $a2, $t1, $a0
    ctx->r6 = ADD32(ctx->r9, ctx->r4);
    // 0x8079EEB8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8079EEBC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x8079EEC0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8079EEC4: lwc1        $f16, -0xDE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1728));
    // 0x8079EEC8: lw          $t2, 0x84($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X84);
    // 0x8079EECC: lui         $at, 0x807A
    ctx->r1 = S32(RELOC_HI16(835, 0X1788) << 16);
    // 0x8079EED0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8079EED4: swc1        $f16, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f16.u32l;
    // 0x8079EED8: lw          $t3, 0x84($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X84);
    // 0x8079EEDC: lwc1        $f18, -0xD88($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(835, 0X1788));
    // 0x8079EEE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8079EEE4: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
    // 0x8079EEE8: beq         $a1, $zero, L_8079EF1C
    if (ctx->r5 == 0) {
        // 0x8079EEEC: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8079EF1C;
    }
    // 0x8079EEEC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079EEF0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8079EEF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8079EEF8: jal         0x8079E800
    // 0x8079EEFC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8079E800(rdram, ctx);
        goto after_1;
    // 0x8079EEFC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8079EF00: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8079EF04: jal         0x8079EC04
    // 0x8079EF08: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8079EC04(rdram, ctx);
        goto after_2;
    // 0x8079EF08: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8079EF0C: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8079EF10: jal         0x80067818
    // 0x8079EF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8079EF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8079EF18: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
L_8079EF1C:
    // 0x8079EF1C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8079EF20: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8079EF24: jal         0x8079EC7C
    // 0x8079EF28: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    func_8079EC7C(rdram, ctx);
        goto after_4;
    // 0x8079EF28: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_4:
    // 0x8079EF2C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8079EF30: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8079EF34: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x8079EF38: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8079EF3C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8079EF40: lhu         $v0, 0x0($t4)
    ctx->r2 = MEM_HU(ctx->r12, 0X0);
    // 0x8079EF44: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8079EF48: andi        $t5, $v0, 0x8000
    ctx->r13 = ctx->r2 & 0X8000;
    // 0x8079EF4C: beq         $t5, $at, L_8079EF60
    if (ctx->r13 == ctx->r1) {
        // 0x8079EF50: andi        $t6, $v0, 0x1000
        ctx->r14 = ctx->r2 & 0X1000;
            goto L_8079EF60;
    }
    // 0x8079EF50: andi        $t6, $v0, 0x1000
    ctx->r14 = ctx->r2 & 0X1000;
    // 0x8079EF54: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x8079EF58: bnel        $t6, $at, L_8079EFBC
    if (ctx->r14 != ctx->r1) {
        // 0x8079EF5C: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_8079EFBC;
    }
    goto skip_5;
    // 0x8079EF5C: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    skip_5:
L_8079EF60:
    // 0x8079EF60: lw          $t0, 0xFBC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0XFBC);
    // 0x8079EF64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8079EF68: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8079EF6C: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8079EF70: beq         $t1, $zero, L_8079EFB8
    if (ctx->r9 == 0) {
        // 0x8079EF74: addiu       $t2, $zero, 0x32
        ctx->r10 = ADD32(0, 0X32);
            goto L_8079EFB8;
    }
    // 0x8079EF74: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8079EF78: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079EF7C: sb          $t2, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r10;
    // 0x8079EF80: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079EF84: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8079EF88: sb          $t3, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r11;
    // 0x8079EF8C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x8079EF90: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8079EF94: sb          $t4, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r12;
    // 0x8079EF98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8079EF9C: sw          $t5, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r13;
    // 0x8079EFA0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8079EFA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079EFA8: jal         0x8079F1C0
    // 0x8079EFAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8079F1C0(rdram, ctx);
        goto after_5;
    // 0x8079EFAC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8079EFB0: b           L_8079EFD8
    // 0x8079EFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8079EFD8;
    // 0x8079EFB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079EFB8:
    // 0x8079EFB8: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
L_8079EFBC:
    // 0x8079EFBC: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x8079EFC0: bne         $t6, $at, L_8079EFD4
    if (ctx->r14 != ctx->r1) {
        // 0x8079EFC4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_8079EFD4;
    }
    // 0x8079EFC4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8079EFC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079EFCC: jal         0x8079F1C0
    // 0x8079EFD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8079F1C0(rdram, ctx);
        goto after_6;
    // 0x8079EFD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
L_8079EFD4:
    // 0x8079EFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8079EFD8:
    // 0x8079EFD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8079EFDC: jr          $ra
    // 0x8079EFE0: nop

    return;
    // 0x8079EFE0: nop

;}
RECOMP_FUNC void func_805AC7E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC7E0: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805AC7E4: lui         $t6, 0x805B
    ctx->r14 = S32(RELOC_HI16(441, 0X608) << 16);
    // 0x805AC7E8: addiu       $t6, $t6, -0x3808
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(441, 0X608));
    // 0x805AC7EC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x805AC7F0: jr          $ra
    // 0x805AC7F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x805AC7F4: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8067A510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067A510: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8067A514: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A518: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A51C: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8067A520: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067A524: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8067A528: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8067A52C: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8067A530: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A534: nop

    // 0x8067A538: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A53C: beql        $t7, $zero, L_8067A58C
    if (ctx->r15 == 0) {
        // 0x8067A540: mfc1        $t7, $f6
        ctx->r15 = (int32_t)ctx->f6.u32l;
            goto L_8067A58C;
    }
    goto skip_0;
    // 0x8067A540: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    skip_0:
    // 0x8067A544: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8067A548: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8067A54C: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8067A550: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8067A554: nop

    // 0x8067A558: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8067A55C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8067A560: nop

    // 0x8067A564: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8067A568: bne         $t7, $zero, L_8067A580
    if (ctx->r15 != 0) {
        // 0x8067A56C: nop
    
            goto L_8067A580;
    }
    // 0x8067A56C: nop

    // 0x8067A570: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8067A574: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8067A578: b           L_8067A598
    // 0x8067A57C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8067A598;
    // 0x8067A57C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8067A580:
    // 0x8067A580: b           L_8067A598
    // 0x8067A584: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8067A598;
    // 0x8067A584: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8067A588: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
L_8067A58C:
    // 0x8067A58C: nop

    // 0x8067A590: bltz        $t7, L_8067A580
    if (SIGNED(ctx->r15) < 0) {
        // 0x8067A594: nop
    
            goto L_8067A580;
    }
    // 0x8067A594: nop

L_8067A598:
    // 0x8067A598: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8067A59C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8067A5A0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8067A5A4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8067A5A8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8067A5AC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8067A5B0: bgez        $t9, L_8067A5C8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8067A5B4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8067A5C8;
    }
    // 0x8067A5B4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8067A5B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8067A5BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8067A5C0: nop

    // 0x8067A5C4: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_8067A5C8:
    // 0x8067A5C8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8067A5CC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x8067A5D0: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8067A5D4: bc1fl       L_8067A5F0
    if (!c1cs) {
        // 0x8067A5D8: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8067A5F0;
    }
    goto skip_1;
    // 0x8067A5D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x8067A5DC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8067A5E0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8067A5E4: b           L_8067A5F4
    // 0x8067A5E8: nop

        goto L_8067A5F4;
    // 0x8067A5E8: nop

    // 0x8067A5EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8067A5F0:
    // 0x8067A5F0: nop

L_8067A5F4:
    // 0x8067A5F4: jr          $ra
    // 0x8067A5F8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x8067A5F8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void func_8073EE08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EE08: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8073EE0C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x8073EE10: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8073EE14: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8073EE18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8073EE1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8073EE20: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8073EE24: lui         $t1, 0x8074
    ctx->r9 = S32(RELOC_HI16(748, 0X239C) << 16);
    // 0x8073EE28: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x8073EE2C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8073EE30: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8073EE34: lw          $t1, 0xB8C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(748, 0X239C));
    // 0x8073EE38: jr          $ra
    // 0x8073EE3C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x8073EE3C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80464F98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80464F98: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x80464F9C: lw          $v0, -0x7CE8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7CE8);
    // 0x80464FA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80464FA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80464FA8: lwc1        $f4, 0x30($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80464FAC: swc1        $f4, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f4.u32l;
    // 0x80464FB0: lwc1        $f6, 0x34($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80464FB4: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80464FB8: jal         0x80464DAC
    // 0x80464FBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80464DAC(rdram, ctx);
        goto after_0;
    // 0x80464FBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80464FC0: jal         0x804647B8
    // 0x80464FC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804647B8(rdram, ctx);
        goto after_1;
    // 0x80464FC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80464FC8: jal         0x804649C8
    // 0x80464FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804649C8(rdram, ctx);
        goto after_2;
    // 0x80464FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80464FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80464FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80464FD8: jr          $ra
    // 0x80464FDC: nop

    return;
    // 0x80464FDC: nop

;}
RECOMP_FUNC void func_807BA438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA438: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x807BA43C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x807BA440: lui         $t7, 0x807C
    ctx->r15 = S32(RELOC_HI16(892, 0X120) << 16);
    // 0x807BA444: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x807BA448: addiu       $t7, $t7, -0x5AF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(892, 0X120));
    // 0x807BA44C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x807BA450: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x807BA454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807BA458: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x807BA45C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x807BA460: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x807BA464: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x807BA468: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x807BA46C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x807BA470: jr          $ra
    // 0x807BA474: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    return;
    // 0x807BA474: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_8069D2E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D2E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8069D2EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8069D2F0: jal         0x8069D294
    // 0x8069D2F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8069D294(rdram, ctx);
        goto after_0;
    // 0x8069D2F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8069D2F8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8069D2FC: lui         $t7, 0x806A
    ctx->r15 = S32(RELOC_HI16(571, 0X3F8) << 16);
    // 0x8069D300: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8069D304: addiu       $t7, $t7, -0x2F18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(571, 0X3F8));
    // 0x8069D308: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8069D30C: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8069D310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8069D314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8069D318: jr          $ra
    // 0x8069D31C: nop

    return;
    // 0x8069D31C: nop

;}
RECOMP_FUNC void func_804D8454(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D8454: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D8458: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D845C: jal         0x8004700C
    // 0x804D8460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804D8460: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804D8464: beq         $v0, $zero, L_804D84A8
    if (ctx->r2 == 0) {
        // 0x804D8468: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_804D84A8;
    }
    // 0x804D8468: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804D846C: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x804D8470: lwc1        $f6, 0x3C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x804D8474: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804D8478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D847C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804D8480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804D8484: bc1f        L_804D84A0
    if (!c1cs) {
        // 0x804D8488: nop
    
            goto L_804D84A0;
    }
    // 0x804D8488: nop

    // 0x804D848C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804D8490: jal         0x804D8878
    // 0x804D8494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_804D8878(rdram, ctx);
        goto after_1;
    // 0x804D8494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x804D8498: b           L_804D84AC
    // 0x804D849C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804D84AC;
    // 0x804D849C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D84A0:
    // 0x804D84A0: jal         0x804D8878
    // 0x804D84A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_804D8878(rdram, ctx);
        goto after_2;
    // 0x804D84A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
L_804D84A8:
    // 0x804D84A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804D84AC:
    // 0x804D84AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804D84B0: jr          $ra
    // 0x804D84B4: nop

    return;
    // 0x804D84B4: nop

;}
RECOMP_FUNC void func_80057B28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057B28: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x80057B2C: lh          $t8, 0x8($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8);
    // 0x80057B30: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80057B34: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80057B38: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80057B3C: bne         $at, $zero, L_80057B4C
    if (ctx->r1 != 0) {
        // 0x80057B40: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_80057B4C;
    }
    // 0x80057B40: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80057B44: jr          $ra
    // 0x80057B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057B4C:
    // 0x80057B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80057B50: beq         $v0, $a1, L_80057B68
    if (ctx->r2 == ctx->r5) {
        // 0x80057B54: nop
    
            goto L_80057B68;
    }
    // 0x80057B54: nop

    // 0x80057B58: beq         $v0, $zero, L_80057B68
    if (ctx->r2 == 0) {
        // 0x80057B5C: nop
    
            goto L_80057B68;
    }
    // 0x80057B5C: nop

    // 0x80057B60: jr          $ra
    // 0x80057B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057B68:
    // 0x80057B68: bne         $a2, $zero, L_80057B78
    if (ctx->r6 != 0) {
        // 0x80057B6C: sll         $t9, $a2, 4
        ctx->r25 = S32(ctx->r6 << 4);
            goto L_80057B78;
    }
    // 0x80057B6C: sll         $t9, $a2, 4
    ctx->r25 = S32(ctx->r6 << 4);
    // 0x80057B70: jr          $ra
    // 0x80057B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057B74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057B78:
    // 0x80057B78: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x80057B7C: beq         $t0, $zero, L_80057B8C
    if (ctx->r8 == 0) {
        // 0x80057B80: nop
    
            goto L_80057B8C;
    }
    // 0x80057B80: nop

    // 0x80057B84: jr          $ra
    // 0x80057B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80057B88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80057B8C:
    // 0x80057B8C: beq         $v0, $a1, L_80057BA0
    if (ctx->r2 == ctx->r5) {
        // 0x80057B90: sw          $a2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r6;
            goto L_80057BA0;
    }
    // 0x80057B90: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80057B94: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x80057B98: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80057B9C: sh          $t2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r10;
L_80057BA0:
    // 0x80057BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80057BA4: jr          $ra
    // 0x80057BA8: nop

    return;
    // 0x80057BA8: nop

;}
RECOMP_FUNC void _blkclr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084820: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x80084824: bne         $at, $zero, L_8008489C
    if (ctx->r1 != 0) {
        // 0x80084828: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8008489C;
    }
    // 0x80084828: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8008482C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x80084830: beq         $v1, $zero, L_80084840
    if (ctx->r3 == 0) {
        // 0x80084834: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_80084840;
    }
    // 0x80084834: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x80084838: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8008483C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_80084840:
    // 0x80084840: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x80084844: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084848: beq         $a3, $zero, L_8008487C
    if (ctx->r7 == 0) {
        // 0x8008484C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008487C;
    }
    // 0x8008484C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x80084850: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084854:
    // 0x80084854: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80084858: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8008485C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x80084860: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x80084864: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x80084868: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8008486C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x80084870: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x80084874: bne         $a0, $a3, L_80084854
    if (ctx->r4 != ctx->r7) {
        // 0x80084878: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084854;
    }
    // 0x80084878: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008487C:
    // 0x8008487C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80084880: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x80084884: beq         $a3, $zero, L_8008489C
    if (ctx->r7 == 0) {
        // 0x80084888: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8008489C;
    }
    // 0x80084888: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8008488C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_80084890:
    // 0x80084890: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80084894: bne         $a0, $a3, L_80084890
    if (ctx->r4 != ctx->r7) {
        // 0x80084898: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_80084890;
    }
    // 0x80084898: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8008489C:
    // 0x8008489C: blez        $a1, L_800848B4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800848A0: nop
    
            goto L_800848B4;
    }
    // 0x800848A0: nop

    // 0x800848A4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800848A8:
    // 0x800848A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800848AC: bne         $a0, $a1, L_800848A8
    if (ctx->r4 != ctx->r5) {
        // 0x800848B0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800848A8;
    }
    // 0x800848B0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800848B4:
    // 0x800848B4: jr          $ra
    // 0x800848B8: nop

    return;
    // 0x800848B8: nop

    // 0x800848BC: nop

;}
RECOMP_FUNC void func_806ED2B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED2B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806ED2B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806ED2BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806ED2C0: jal         0x806ED1B8
    // 0x806ED2C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_806ED1B8(rdram, ctx);
        goto after_0;
    // 0x806ED2C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x806ED2C8: bne         $v0, $zero, L_806ED2E0
    if (ctx->r2 != 0) {
        // 0x806ED2CC: nop
    
            goto L_806ED2E0;
    }
    // 0x806ED2CC: nop

    // 0x806ED2D0: jal         0x800445A4
    // 0x806ED2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806ED2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ED2D8: b           L_806ED350
    // 0x806ED2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806ED350;
    // 0x806ED2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED2E0:
    // 0x806ED2E0: jal         0x806ED29C
    // 0x806ED2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED29C(rdram, ctx);
        goto after_2;
    // 0x806ED2E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806ED2E8: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x806ED2EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806ED2F0: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x806ED2F4: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806ED2F8: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x806ED2FC: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(676, 0X45B8) << 16);
    // 0x806ED300: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x806ED304: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x806ED308: addiu       $t7, $t7, 0x508
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(676, 0X45B8));
    // 0x806ED30C: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x806ED310: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806ED314: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806ED318: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x806ED31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806ED324: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806ED328: jal         0x806ED360
    // 0x806ED32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806ED360(rdram, ctx);
        goto after_3;
    // 0x806ED32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x806ED330: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x806ED334: jal         0x806EC288
    // 0x806ED338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC288(rdram, ctx);
        goto after_4;
    // 0x806ED338: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806ED33C: bnel        $v0, $zero, L_806ED350
    if (ctx->r2 != 0) {
        // 0x806ED340: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806ED350;
    }
    goto skip_0;
    // 0x806ED340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806ED344: jal         0x800445A4
    // 0x806ED348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x806ED348: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806ED34C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806ED350:
    // 0x806ED350: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806ED354: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806ED358: jr          $ra
    // 0x806ED35C: nop

    return;
    // 0x806ED35C: nop

;}
RECOMP_FUNC void func_8040D7C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040D7C0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040D7C4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040D7C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8040D7CC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8040D7D0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040D7D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8040D7D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040D7DC: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8040D7E0: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040D7E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040D7E8: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8040D7EC: jal         0x80066E88
    // 0x8040D7F0: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8040D7F0: nop

    after_0:
    // 0x8040D7F4: lui         $at, 0xC234
    ctx->r1 = S32(0XC234 << 16);
    // 0x8040D7F8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040D7FC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8040D800: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040D804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D808: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040D80C: sub.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x8040D810: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8040D814: nop

    // 0x8040D818: bc1fl       L_8040D840
    if (!c1cs) {
        // 0x8040D81C: swc1        $f20, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
            goto L_8040D840;
    }
    goto skip_0;
    // 0x8040D81C: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8040D820: jal         0x8040D0EC
    // 0x8040D824: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    func_8040D0EC(rdram, ctx);
        goto after_1;
    // 0x8040D824: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    after_1:
    // 0x8040D828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040D82C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040D830: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8040D834: jal         0x8040E254
    // 0x8040D838: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040D838: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8040D83C: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_8040D840:
    // 0x8040D840: jal         0x80066E88
    // 0x8040D844: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8040D844: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8040D848: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040D84C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040D850: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8040D854: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8040D858: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8040D85C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8040D860: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8040D864: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8040D868: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8040D86C: jal         0x80066DE4
    // 0x8040D870: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8040D870: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8040D874: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040D878: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8040D87C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8040D880: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040D884: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8040D888: lwc1        $f8, 0x8($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8040D88C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8040D890: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8040D894: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040D898: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040D89C: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8040D8A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040D8A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8040D8A8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8040D8AC: jr          $ra
    // 0x8040D8B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040D8B0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8006EF6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EF6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006EF70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006EF74: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006EF78: jal         0x8006E7F0
    // 0x8006EF7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_8006E7F0(rdram, ctx);
        goto after_0;
    // 0x8006EF7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8006EF80: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x8006EF84: addiu       $at, $zero, 0x466B
    ctx->r1 = ADD32(0, 0X466B);
    // 0x8006EF88: beq         $v0, $at, L_8006EFA8
    if (ctx->r2 == ctx->r1) {
        // 0x8006EF8C: addiu       $at, $zero, 0x473C
        ctx->r1 = ADD32(0, 0X473C);
            goto L_8006EFA8;
    }
    // 0x8006EF8C: addiu       $at, $zero, 0x473C
    ctx->r1 = ADD32(0, 0X473C);
    // 0x8006EF90: beq         $v0, $at, L_8006F004
    if (ctx->r2 == ctx->r1) {
        // 0x8006EF94: addiu       $at, $zero, 0x473D
        ctx->r1 = ADD32(0, 0X473D);
            goto L_8006F004;
    }
    // 0x8006EF94: addiu       $at, $zero, 0x473D
    ctx->r1 = ADD32(0, 0X473D);
    // 0x8006EF98: beq         $v0, $at, L_8006F040
    if (ctx->r2 == ctx->r1) {
        // 0x8006EF9C: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_8006F040;
    }
    // 0x8006EF9C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8006EFA0: b           L_8006F060
    // 0x8006EFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F060;
    // 0x8006EFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006EFA8:
    // 0x8006EFA8: jal         0x8006E84C
    // 0x8006EFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E84C(rdram, ctx);
        goto after_1;
    // 0x8006EFAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8006EFB0: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8006EFB4: jal         0x80048F84
    // 0x8006EFB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x8006EFB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8006EFBC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006EFC0: lw          $t6, -0x6C78($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C78);
    // 0x8006EFC4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006EFC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006EFCC: bnel        $t6, $zero, L_8006F060
    if (ctx->r14 != 0) {
        // 0x8006EFD0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006F060;
    }
    goto skip_0;
    // 0x8006EFD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8006EFD4: jal         0x8005FE48
    // 0x8006EFD8: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    func_8005FE48(rdram, ctx);
        goto after_3;
    // 0x8006EFD8: sb          $t7, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r15;
    after_3:
    // 0x8006EFDC: jal         0x8006EB90
    // 0x8006EFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006EB90(rdram, ctx);
        goto after_4;
    // 0x8006EFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8006EFE4: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8006EFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006EFEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8006EFF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006EFF4: jal         0x8006F070
    // 0x8006EFF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8006F070(rdram, ctx);
        goto after_5;
    // 0x8006EFF8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8006EFFC: b           L_8006F060
    // 0x8006F000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F060;
    // 0x8006F000: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F004:
    // 0x8006F004: jal         0x8006E84C
    // 0x8006F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006E84C(rdram, ctx);
        goto after_6;
    // 0x8006F008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8006F00C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x8006F010: jal         0x80048F84
    // 0x8006F014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_7;
    // 0x8006F014: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8006F018: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8006F01C: lw          $t8, -0x76BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76BC);
    // 0x8006F020: bnel        $t8, $zero, L_8006F060
    if (ctx->r24 != 0) {
        // 0x8006F024: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006F060;
    }
    goto skip_1;
    // 0x8006F024: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8006F028: jal         0x8006EB90
    // 0x8006F02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006EB90(rdram, ctx);
        goto after_8;
    // 0x8006F02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8006F030: jal         0x800447C8
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_9;
    // 0x8006F034: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8006F038: b           L_8006F060
    // 0x8006F03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006F060;
    // 0x8006F03C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F040:
    // 0x8006F040: lw          $t9, -0x76BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76BC);
    // 0x8006F044: bnel        $t9, $zero, L_8006F060
    if (ctx->r25 != 0) {
        // 0x8006F048: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006F060;
    }
    goto skip_2;
    // 0x8006F048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8006F04C: jal         0x8006EB90
    // 0x8006F050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8006EB90(rdram, ctx);
        goto after_10;
    // 0x8006F050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8006F054: jal         0x800447C8
    // 0x8006F058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800447C8(rdram, ctx);
        goto after_11;
    // 0x8006F058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8006F05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006F060:
    // 0x8006F060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F068: jr          $ra
    // 0x8006F06C: nop

    return;
    // 0x8006F06C: nop

;}
RECOMP_FUNC void func_8006E130(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E130: jr          $ra
    // 0x8006E134: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8006E134: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_806D9478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D9478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806D947C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806D9480: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806D9484: jal         0x80045A34
    // 0x806D9488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806D9488: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x806D948C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x806D9490: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x806D9494: bne         $v0, $zero, L_806D94AC
    if (ctx->r2 != 0) {
        // 0x806D9498: sw          $v0, 0x1F4($a3)
        MEM_W(0X1F4, ctx->r7) = ctx->r2;
            goto L_806D94AC;
    }
    // 0x806D9498: sw          $v0, 0x1F4($a3)
    MEM_W(0X1F4, ctx->r7) = ctx->r2;
    // 0x806D949C: jal         0x800445A4
    // 0x806D94A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x806D94A0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x806D94A4: b           L_806D94BC
    // 0x806D94A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806D94BC;
    // 0x806D94A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806D94AC:
    // 0x806D94AC: lw          $a0, 0x1F4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X1F4);
    // 0x806D94B0: jal         0x80065728
    // 0x806D94B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_2;
    // 0x806D94B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x806D94B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806D94BC:
    // 0x806D94BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806D94C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806D94C4: jr          $ra
    // 0x806D94C8: nop

    return;
    // 0x806D94C8: nop

;}
RECOMP_FUNC void func_8079E460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079E460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8079E464: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079E468: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8079E46C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8079E470: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8079E474: lw          $t6, 0x88($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X88);
    // 0x8079E478: lw          $a3, 0x16C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X16C);
    // 0x8079E47C: lbu         $v0, 0x10($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X10);
    // 0x8079E480: addiu       $v0, $v0, -0x8
    ctx->r2 = ADD32(ctx->r2, -0X8);
    // 0x8079E484: bgtzl       $v0, L_8079E4B4
    if (SIGNED(ctx->r2) > 0) {
        // 0x8079E488: sb          $v0, 0x10($a3)
        MEM_B(0X10, ctx->r7) = ctx->r2;
            goto L_8079E4B4;
    }
    goto skip_0;
    // 0x8079E488: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
    skip_0:
    // 0x8079E48C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8079E490: jal         0x8079F1C0
    // 0x8079E494: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8079F1C0(rdram, ctx);
        goto after_0;
    // 0x8079E494: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8079E498: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8079E49C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x8079E4A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8079E4A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8079E4A8: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x8079E4AC: sb          $zero, 0x14($v1)
    MEM_B(0X14, ctx->r3) = 0;
    // 0x8079E4B0: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_8079E4B4:
    // 0x8079E4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079E4B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8079E4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079E4C0: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x8079E4C4: jr          $ra
    // 0x8079E4C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8079E4C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8073AF74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073AF74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8073AF78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8073AF7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8073AF80: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8073AF84: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8073AF88: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8073AF8C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8073AF90: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8073AF94: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073AF98: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8073AF9C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8073AFA0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8073AFA4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8073AFA8: jal         0x8073A604
    // 0x8073AFAC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    func_8073A604(rdram, ctx);
        goto after_0;
    // 0x8073AFAC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    after_0:
    // 0x8073AFB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073AFB4: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073AFB8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8073AFBC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073AFC0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8073AFC4: nop

    // 0x8073AFC8: bc1fl       L_8073AFD8
    if (!c1cs) {
        // 0x8073AFCC: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_8073AFD8;
    }
    goto skip_0;
    // 0x8073AFCC: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_0:
    // 0x8073AFD0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8073AFD4: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_8073AFD8:
    // 0x8073AFD8: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x8073AFDC: bc1fl       L_8073AFEC
    if (!c1cs) {
        // 0x8073AFE0: lwc1        $f16, 0x30($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
            goto L_8073AFEC;
    }
    goto skip_1;
    // 0x8073AFE0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x8073AFE4: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8073AFE8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
L_8073AFEC:
    // 0x8073AFEC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8073AFF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8073AFF4: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x8073AFF8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8073AFFC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073B000: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x8073B004: nop

    // 0x8073B008: bc1fl       L_8073B0B8
    if (!c1cs) {
        // 0x8073B00C: trunc.w.s   $f8, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
            goto L_8073B0B8;
    }
    goto skip_2;
    // 0x8073B00C: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
    skip_2:
    // 0x8073B010: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8073B014: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8073B018: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X2498) << 16);
    // 0x8073B01C: lwc1        $f0, -0x4138($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X2498));
    // 0x8073B020: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8073B024: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1EC0) << 16);
    // 0x8073B028: lw          $t2, 0x38($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X38);
    // 0x8073B02C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8073B030: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8073B034: nop

    // 0x8073B038: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8073B03C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8073B040: lwc1        $f8, -0x4710($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1EC0));
    // 0x8073B044: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1EF4) << 16);
    // 0x8073B048: swc1        $f8, 0x3C($t2)
    MEM_W(0X3C, ctx->r10) = ctx->f8.u32l;
    // 0x8073B04C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8073B050: lw          $t6, 0x38($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X38);
    // 0x8073B054: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8073B058: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8073B05C: nop

    // 0x8073B060: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8073B064: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8073B068: lwc1        $f18, -0x46DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1EF4));
    // 0x8073B06C: swc1        $f18, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f18.u32l;
    // 0x8073B070: lw          $t7, 0x38($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X38);
    // 0x8073B074: swc1        $f0, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f0.u32l;
    // 0x8073B078: lw          $t8, 0x38($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X38);
    // 0x8073B07C: swc1        $f0, 0x70($t8)
    MEM_W(0X70, ctx->r24) = ctx->f0.u32l;
    // 0x8073B080: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8073B084: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8073B088: swc1        $f4, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f4.u32l;
    // 0x8073B08C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8073B090: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x8073B094: swc1        $f6, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f6.u32l;
    // 0x8073B098: jal         0x8073B8CC
    // 0x8073B09C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8073B8CC(rdram, ctx);
        goto after_1;
    // 0x8073B09C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8073B0A0: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8073B0A4: jal         0x80067818
    // 0x8073B0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_2;
    // 0x8073B0A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8073B0AC: b           L_8073B260
    // 0x8073B0B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073B260;
    // 0x8073B0B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8073B0B4: trunc.w.s   $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    ctx->f8.u32l = TRUNC_W_S(ctx->f12.fl);
L_8073B0B8:
    // 0x8073B0B8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8073B0BC: addiu       $a0, $zero, 0x204
    ctx->r4 = ADD32(0, 0X204);
    // 0x8073B0C0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8073B0C4: nop

    // 0x8073B0C8: beql        $t9, $t1, L_8073B0E4
    if (ctx->r25 == ctx->r9) {
        // 0x8073B0CC: lwc1        $f10, 0x2C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8073B0E4;
    }
    goto skip_3;
    // 0x8073B0CC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x8073B0D0: jal         0x80067818
    // 0x8073B0D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x8073B0D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8073B0D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8073B0DC: nop

    // 0x8073B0E0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
L_8073B0E4:
    // 0x8073B0E4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F08) << 16);
    // 0x8073B0E8: lw          $t5, 0x38($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X38);
    // 0x8073B0EC: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8073B0F0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073B0F4: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x8073B0F8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8073B0FC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8073B100: nop

    // 0x8073B104: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8073B108: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8073B10C: lwc1        $f4, -0x46C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F08));
    // 0x8073B110: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F30) << 16);
    // 0x8073B114: swc1        $f4, 0x3C($t5)
    MEM_W(0X3C, ctx->r13) = ctx->f4.u32l;
    // 0x8073B118: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073B11C: lw          $t0, 0x38($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X38);
    // 0x8073B120: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8073B124: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8073B128: nop

    // 0x8073B12C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073B130: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8073B134: lwc1        $f10, -0x46A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F30));
    // 0x8073B138: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8073B13C: swc1        $f10, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f10.u32l;
    // 0x8073B140: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x8073B144: lwc1        $f16, 0x6C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x8073B148: swc1        $f16, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f16.u32l;
    // 0x8073B14C: lw          $t9, 0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7EA8);
    // 0x8073B150: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8073B154: lhu         $t1, 0xC($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0XC);
    // 0x8073B158: andi        $t2, $t1, 0x8000
    ctx->r10 = ctx->r9 & 0X8000;
    // 0x8073B15C: bnel        $t2, $at, L_8073B260
    if (ctx->r10 != ctx->r1) {
        // 0x8073B160: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8073B260;
    }
    goto skip_4;
    // 0x8073B160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8073B164: trunc.w.s   $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8073B168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8073B16C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8073B170: nop

    // 0x8073B174: beq         $v0, $at, L_8073B1D8
    if (ctx->r2 == ctx->r1) {
        // 0x8073B178: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8073B1D8;
    }
    // 0x8073B178: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8073B17C: bne         $v0, $at, L_8073B210
    if (ctx->r2 != ctx->r1) {
        // 0x8073B180: lui         $a0, 0x4014
        ctx->r4 = S32(0X4014 << 16);
            goto L_8073B210;
    }
    // 0x8073B180: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x8073B184: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8073B188: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8073B18C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8073B190: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x8073B194: jal         0x8004613C
    // 0x8073B198: lw          $a3, 0x44($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X44);
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x8073B198: lw          $a3, 0x44($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X44);
    after_4:
    // 0x8073B19C: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x8073B1A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8073B1A4: jal         0x80047F9C
    // 0x8073B1A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8073B1A8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x8073B1AC: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8073B1B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8073B1B4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x8073B1B8: sb          $t5, 0x17C($t6)
    MEM_B(0X17C, ctx->r14) = ctx->r13;
    // 0x8073B1BC: jal         0x8073B8CC
    // 0x8073B1C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_8073B8CC(rdram, ctx);
        goto after_6;
    // 0x8073B1C0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_6:
    // 0x8073B1C4: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x8073B1C8: jal         0x80067818
    // 0x8073B1CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8073B1CC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8073B1D0: b           L_8073B260
    // 0x8073B1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073B260;
    // 0x8073B1D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073B1D8:
    // 0x8073B1D8: jal         0x8073A940
    // 0x8073B1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8073A940(rdram, ctx);
        goto after_8;
    // 0x8073B1DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8073B1E0: lw          $t7, 0x10($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X10);
    // 0x8073B1E4: lui         $at, 0x8074
    ctx->r1 = S32(RELOC_HI16(739, 0X1F44) << 16);
    // 0x8073B1E8: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8073B1EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8073B1F0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8073B1F4: lwc1        $f4, -0x468C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(739, 0X1F44));
    // 0x8073B1F8: addiu       $a0, $zero, 0x205
    ctx->r4 = ADD32(0, 0X205);
    // 0x8073B1FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8073B200: jal         0x80067818
    // 0x8073B204: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    func_80067818(rdram, ctx);
        goto after_9;
    // 0x8073B204: swc1        $f4, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->f4.u32l;
    after_9:
    // 0x8073B208: b           L_8073B260
    // 0x8073B20C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073B260;
    // 0x8073B20C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073B210:
    // 0x8073B210: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8073B214: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x8073B218: lui         $t3, 0x8074
    ctx->r11 = S32(RELOC_HI16(739, 0X22E0) << 16);
    // 0x8073B21C: beq         $t9, $v0, L_8073B254
    if (ctx->r25 == ctx->r2) {
        // 0x8073B220: addiu       $a0, $zero, 0xC5
        ctx->r4 = ADD32(0, 0XC5);
            goto L_8073B254;
    }
    // 0x8073B220: addiu       $a0, $zero, 0xC5
    ctx->r4 = ADD32(0, 0XC5);
    // 0x8073B224: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8073B228: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8073B22C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8073B230: lw          $t3, -0x42F0($t3)
    ctx->r11 = MEM_W(ctx->r11, (int16_t)RELOC_LO16(739, 0X22E0));
    // 0x8073B234: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8073B238: jal         0x8073B8CC
    // 0x8073B23C: sw          $t3, 0x148($a0)
    MEM_W(0X148, ctx->r4) = ctx->r11;
    func_8073B8CC(rdram, ctx);
        goto after_10;
    // 0x8073B23C: sw          $t3, 0x148($a0)
    MEM_W(0X148, ctx->r4) = ctx->r11;
    after_10:
    // 0x8073B240: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    // 0x8073B244: jal         0x80067818
    // 0x8073B248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_11;
    // 0x8073B248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8073B24C: b           L_8073B260
    // 0x8073B250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8073B260;
    // 0x8073B250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073B254:
    // 0x8073B254: jal         0x80067818
    // 0x8073B258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_12;
    // 0x8073B258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8073B25C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8073B260:
    // 0x8073B260: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8073B264: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8073B268: jr          $ra
    // 0x8073B26C: nop

    return;
    // 0x8073B26C: nop

;}
RECOMP_FUNC void func_80450C18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80450C18: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80450C1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80450C20: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80450C24: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80450C28: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80450C2C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450C30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80450C34: lw          $t6, 0xA5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XA5C);
    // 0x80450C38: addu        $v0, $s0, $at
    ctx->r2 = ADD32(ctx->r16, ctx->r1);
    // 0x80450C3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80450C40: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80450C44: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80450C48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80450C4C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80450C50: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450C54: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450C58: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80450C5C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450C60: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80450C64: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80450C68: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80450C6C: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80450C70: addiu       $t1, $t0, 0xAE0
    ctx->r9 = ADD32(ctx->r8, 0XAE0);
    // 0x80450C74: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x80450C78: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80450C7C: lwc1        $f4, 0x6CE0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CE0);
    // 0x80450C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80450C84: nop

    // 0x80450C88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80450C8C: swc1        $f8, 0x6CE0($v0)
    MEM_W(0X6CE0, ctx->r2) = ctx->f8.u32l;
    // 0x80450C90: lw          $v1, 0xA50($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XA50);
    // 0x80450C94: slti        $at, $v1, 0x8D
    ctx->r1 = SIGNED(ctx->r3) < 0X8D ? 1 : 0;
    // 0x80450C98: beq         $at, $zero, L_80450CA4
    if (ctx->r1 == 0) {
        // 0x80450C9C: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80450CA4;
    }
    // 0x80450C9C: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80450CA0: sw          $t2, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r10;
L_80450CA4:
    // 0x80450CA4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80450CA8: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80450CAC: lwc1        $f0, 0x6CE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x80450CB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80450CB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80450CB8: lui         $at, 0x42D6
    ctx->r1 = S32(0X42D6 << 16);
    // 0x80450CBC: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80450CC0: nop

    // 0x80450CC4: bc1t        L_80450D14
    if (c1cs) {
        // 0x80450CC8: nop
    
            goto L_80450D14;
    }
    // 0x80450CC8: nop

    // 0x80450CCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80450CD0: addiu       $t3, $zero, 0xB3
    ctx->r11 = ADD32(0, 0XB3);
    // 0x80450CD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80450CD8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80450CDC: nop

    // 0x80450CE0: bc1f        L_80450D0C
    if (!c1cs) {
        // 0x80450CE4: nop
    
            goto L_80450D0C;
    }
    // 0x80450CE4: nop

    // 0x80450CE8: jal         0x80446D70
    // 0x80450CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80446D70(rdram, ctx);
        goto after_0;
    // 0x80450CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80450CF0: lui         $a0, 0x8045
    ctx->r4 = S32(RELOC_HI16(98, 0X1363C) << 16);
    // 0x80450CF4: addiu       $a0, $a0, 0x7A1C
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(98, 0X1363C));
    // 0x80450CF8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80450CFC: jal         0x8044EDC4
    // 0x80450D00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_8044EDC4(rdram, ctx);
        goto after_1;
    // 0x80450D00: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x80450D04: b           L_80450D14
    // 0x80450D08: nop

        goto L_80450D14;
    // 0x80450D08: nop

L_80450D0C:
    // 0x80450D0C: jal         0x80450AD0
    // 0x80450D10: sw          $t3, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r11;
    func_80450AD0(rdram, ctx);
        goto after_2;
    // 0x80450D10: sw          $t3, 0xA50($s0)
    MEM_W(0XA50, ctx->r16) = ctx->r11;
    after_2:
L_80450D14:
    // 0x80450D14: jal         0x8044FD5C
    // 0x80450D18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044FD5C(rdram, ctx);
        goto after_3;
    // 0x80450D18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80450D1C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80450D20: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80450D24: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80450D28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80450D2C: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80450D30: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80450D34: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80450D38: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80450D3C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80450D40: sll         $t5, $t5, 8
    ctx->r13 = S32(ctx->r13 << 8);
    // 0x80450D44: addu        $a1, $s0, $t5
    ctx->r5 = ADD32(ctx->r16, ctx->r13);
    // 0x80450D48: jal         0x8044ED68
    // 0x80450D4C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    func_8044ED68(rdram, ctx);
        goto after_4;
    // 0x80450D4C: addiu       $a1, $a1, 0x6F80
    ctx->r5 = ADD32(ctx->r5, 0X6F80);
    after_4:
    // 0x80450D50: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80450D54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80450D58: lw          $a1, 0xA50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA50);
    // 0x80450D5C: jal         0x8044E90C
    // 0x80450D60: sw          $t6, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r14;
    func_8044E90C(rdram, ctx);
        goto after_5;
    // 0x80450D60: sw          $t6, 0xA5C($s0)
    MEM_W(0XA5C, ctx->r16) = ctx->r14;
    after_5:
    // 0x80450D64: jal         0x8044F178
    // 0x80450D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8044F178(rdram, ctx);
        goto after_6;
    // 0x80450D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80450D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80450D70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80450D74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80450D78: jr          $ra
    // 0x80450D7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80450D7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_80038798(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038798: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003879C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800387A0: jal         0x800239FC
    // 0x800387A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800239FC(rdram, ctx);
        goto after_0;
    // 0x800387A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800387A8: jal         0x80023EA0
    // 0x800387AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80023EA0(rdram, ctx);
        goto after_1;
    // 0x800387AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800387B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800387B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800387B8: jr          $ra
    // 0x800387BC: nop

    return;
    // 0x800387BC: nop

;}
RECOMP_FUNC void func_80742E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742E64: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80742E68: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80742E6C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80742E70: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80742E74: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80742E78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80742E7C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80742E80: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80742E84: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80742E88: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80742E8C: jr          $ra
    // 0x80742E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80742E90: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80426F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80426F20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80426F24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80426F28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80426F2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80426F30: jal         0x80045A34
    // 0x80426F34: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80426F34: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    after_0:
    // 0x80426F38: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x80426F3C: jal         0x80064D1C
    // 0x80426F40: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    func_80064D1C(rdram, ctx);
        goto after_1;
    // 0x80426F40: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_1:
    // 0x80426F44: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x80426F48: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x80426F4C: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x80426F50: jal         0x80426A08
    // 0x80426F54: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    func_80426A08(rdram, ctx);
        goto after_2;
    // 0x80426F54: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x80426F58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80426F5C: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x80426F60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80426F64: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80426F68: swc1        $f4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->f4.u32l;
    // 0x80426F6C: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x80426F70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80426F74: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x80426F78: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80426F7C: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x80426F80: swc1        $f0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f0.u32l;
    // 0x80426F84: swc1        $f0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f0.u32l;
    // 0x80426F88: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x80426F8C: addiu       $v0, $v1, 0x18
    ctx->r2 = ADD32(ctx->r3, 0X18);
    // 0x80426F90: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80426F94: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80426F98: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80426F9C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80426FA0: jal         0x80426E54
    // 0x80426FA4: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    func_80426E54(rdram, ctx);
        goto after_3;
    // 0x80426FA4: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    after_3:
    // 0x80426FA8: lw          $t0, 0x16C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X16C);
    // 0x80426FAC: lui         $t9, 0x8042
    ctx->r25 = S32(RELOC_HI16(38, 0X78C) << 16);
    // 0x80426FB0: addiu       $t9, $t9, 0x6D8C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(38, 0X78C));
    // 0x80426FB4: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x80426FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80426FBC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80426FC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80426FC4: jr          $ra
    // 0x80426FC8: nop

    return;
    // 0x80426FC8: nop

;}
RECOMP_FUNC void func_8064BB9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064BB9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064BBA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064BBA4: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064BBA8: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064BBAC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8064BBB0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064BBB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064BBB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064BBBC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064BBC0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8064BBC4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064BBC8: nop

    // 0x8064BBCC: bc1fl       L_8064BBE0
    if (!c1cs) {
        // 0x8064BBD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064BBE0;
    }
    goto skip_0;
    // 0x8064BBD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064BBD4: jal         0x8064BF74
    // 0x8064BBD8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064BF74(rdram, ctx);
        goto after_0;
    // 0x8064BBD8: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064BBDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064BBE0:
    // 0x8064BBE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064BBE4: jr          $ra
    // 0x8064BBE8: nop

    return;
    // 0x8064BBE8: nop

;}
RECOMP_FUNC void func_806F1BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F1BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F1BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F1BDC: jal         0x800447C8
    // 0x806F1BE0: nop

    func_800447C8(rdram, ctx);
        goto after_0;
    // 0x806F1BE0: nop

    after_0:
    // 0x806F1BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F1BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F1BEC: jr          $ra
    // 0x806F1BF0: nop

    return;
    // 0x806F1BF0: nop

;}
RECOMP_FUNC void func_8004597C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004597C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80045980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045984: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80045988: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004598C: beq         $t7, $zero, L_800459AC
    if (ctx->r15 == 0) {
        // 0x80045990: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800459AC;
    }
    // 0x80045990: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80045994: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80045998: addiu       $a0, $a0, 0x680
    ctx->r4 = ADD32(ctx->r4, 0X680);
    // 0x8004599C: addiu       $a1, $zero, 0x211
    ctx->r5 = ADD32(0, 0X211);
    // 0x800459A0: jal         0x80071380
    // 0x800459A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x800459A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800459A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_800459AC:
    // 0x800459AC: lw          $v0, 0x1F8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F8);
    // 0x800459B0: beql        $v0, $zero, L_800459EC
    if (ctx->r2 == 0) {
        // 0x800459B4: lw          $a0, 0x1F4($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X1F4);
            goto L_800459EC;
    }
    goto skip_0;
    // 0x800459B4: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    skip_0:
    // 0x800459B8: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
    // 0x800459BC: addiu       $a1, $zero, 0x21C
    ctx->r5 = ADD32(0, 0X21C);
    // 0x800459C0: bne         $a0, $zero, L_800459DC
    if (ctx->r4 != 0) {
        // 0x800459C4: nop
    
            goto L_800459DC;
    }
    // 0x800459C4: nop

    // 0x800459C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800459CC: jal         0x80071380
    // 0x800459D0: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    Fault_HungUp(rdram, ctx);
        goto after_1;
    // 0x800459D0: addiu       $a0, $a0, 0x690
    ctx->r4 = ADD32(ctx->r4, 0X690);
    after_1:
    // 0x800459D4: b           L_80045A28
    // 0x800459D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80045A28;
    // 0x800459D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800459DC:
    // 0x800459DC: jalr        $v0
    // 0x800459E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800459E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x800459E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800459E8: lw          $a0, 0x1F4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1F4);
L_800459EC:
    // 0x800459EC: beql        $a0, $zero, L_80045A28
    if (ctx->r4 == 0) {
        // 0x800459F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80045A28;
    }
    goto skip_1;
    // 0x800459F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800459F4: lbu         $t8, 0x1F2($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X1F2);
    // 0x800459F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800459FC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80045A00: beql        $t8, $at, L_80045A24
    if (ctx->r24 == ctx->r1) {
        // 0x80045A04: sw          $zero, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = 0;
            goto L_80045A24;
    }
    goto skip_2;
    // 0x80045A04: sw          $zero, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = 0;
    skip_2:
    // 0x80045A08: lw          $t9, 0x6EB4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6EB4);
    // 0x80045A0C: beql        $t9, $zero, L_80045A24
    if (ctx->r25 == 0) {
        // 0x80045A10: sw          $zero, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = 0;
            goto L_80045A24;
    }
    goto skip_3;
    // 0x80045A10: sw          $zero, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = 0;
    skip_3:
    // 0x80045A14: jal         0x80064E84
    // 0x80045A18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80064E84(rdram, ctx);
        goto after_3;
    // 0x80045A18: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_3:
    // 0x80045A1C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80045A20: sw          $zero, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = 0;
L_80045A24:
    // 0x80045A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045A28:
    // 0x80045A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045A2C: jr          $ra
    // 0x80045A30: nop

    return;
    // 0x80045A30: nop

;}
RECOMP_FUNC void func_8053502C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053502C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80535030: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80535034: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80535038: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8053503C: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    // 0x80535040: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(348, 0X1038) << 16);
    // 0x80535044: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80535048: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8053504C: lw          $t9, 0x5648($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(348, 0X1038));
    // 0x80535050: jalr        $t9
    // 0x80535054: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80535054: nop

    after_0:
    // 0x80535058: jal         0x805347F0
    // 0x8053505C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805347F0(rdram, ctx);
        goto after_1;
    // 0x8053505C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80535060: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80535064: bne         $v0, $at, L_8053507C
    if (ctx->r2 != ctx->r1) {
        // 0x80535068: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8053507C;
    }
    // 0x80535068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8053506C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80535070: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80535074: jal         0x805350A0
    // 0x80535078: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_805350A0(rdram, ctx);
        goto after_2;
    // 0x80535078: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_2:
L_8053507C:
    // 0x8053507C: jal         0x8053484C
    // 0x80535080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8053484C(rdram, ctx);
        goto after_3;
    // 0x80535080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80535084: jal         0x80534678
    // 0x80535088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80534678(rdram, ctx);
        goto after_4;
    // 0x80535088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8053508C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80535090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80535094: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80535098: jr          $ra
    // 0x8053509C: nop

    return;
    // 0x8053509C: nop

;}
RECOMP_FUNC void func_8002FB10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FB14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FB18: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FB1C: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FB20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002FB24: jal         0x8002F678
    // 0x8002FB28: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FB28: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FB2C: beq         $v0, $zero, L_8002FB40
    if (ctx->r2 == 0) {
        // 0x8002FB30: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FB40;
    }
    // 0x8002FB30: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FB34: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FB38: addiu       $t6, $t6, -0x1EF0
    ctx->r14 = ADD32(ctx->r14, -0X1EF0);
    // 0x8002FB3C: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FB40:
    // 0x8002FB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FB44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FB48: jr          $ra
    // 0x8002FB4C: nop

    return;
    // 0x8002FB4C: nop

;}
RECOMP_FUNC void func_80527744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80527744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80527748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8052774C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80527750: jal         0x800653D8
    // 0x80527754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x80527754: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80527758: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8052775C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80527760: beq         $t6, $zero, L_80527778
    if (ctx->r14 == 0) {
        // 0x80527764: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80527778;
    }
    // 0x80527764: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80527768: jal         0x80527A10
    // 0x8052776C: nop

    func_80527A10(rdram, ctx);
        goto after_1;
    // 0x8052776C: nop

    after_1:
    // 0x80527770: b           L_80527784
    // 0x80527774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80527784;
    // 0x80527774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527778:
    // 0x80527778: jal         0x80527C58
    // 0x8052777C: nop

    func_80527C58(rdram, ctx);
        goto after_2;
    // 0x8052777C: nop

    after_2:
    // 0x80527780: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80527784:
    // 0x80527784: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80527788: jr          $ra
    // 0x8052778C: nop

    return;
    // 0x8052778C: nop

;}
RECOMP_FUNC void func_807A6AD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A6AD4: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x807A6AD8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x807A6ADC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x807A6AE0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x807A6AE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x807A6AE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x807A6AEC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x807A6AF0: lui         $t1, 0x807A
    ctx->r9 = S32(RELOC_HI16(847, 0X1508) << 16);
    // 0x807A6AF4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x807A6AF8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x807A6AFC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x807A6B00: lw          $t1, 0x7208($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(847, 0X1508));
    // 0x807A6B04: jr          $ra
    // 0x807A6B08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x807A6B08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8000344C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000344C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80003450: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80003454: lui         $s5, 0x800B
    ctx->r21 = S32(0X800B << 16);
    // 0x80003458: addiu       $s5, $s5, 0x4D10
    ctx->r21 = ADD32(ctx->r21, 0X4D10);
    // 0x8000345C: lw          $v0, 0x1DAC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1DAC);
    // 0x80003460: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80003464: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80003468: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8000346C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80003470: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80003474: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80003478: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000347C: blez        $v0, L_8000350C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80003480: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000350C;
    }
    // 0x80003480: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80003484: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80003488: addiu       $s3, $s3, -0x63B4
    ctx->r19 = ADD32(ctx->r19, -0X63B4);
    // 0x8000348C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80003490:
    // 0x80003490: lw          $t6, 0x2A2C($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X2A2C);
    // 0x80003494: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x80003498: lbu         $t7, 0x33($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X33);
    // 0x8000349C: bnel        $s4, $t7, L_80003500
    if (ctx->r20 != ctx->r15) {
        // 0x800034A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80003500;
    }
    goto skip_0;
    // 0x800034A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800034A4: lbu         $t8, 0x34($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X34);
    // 0x800034A8: bne         $t8, $zero, L_800034DC
    if (ctx->r24 != 0) {
        // 0x800034AC: nop
    
            goto L_800034DC;
    }
    // 0x800034AC: nop

    // 0x800034B0: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x800034B4: beq         $t9, $zero, L_800034DC
    if (ctx->r25 == 0) {
        // 0x800034B8: nop
    
            goto L_800034DC;
    }
    // 0x800034B8: nop

    // 0x800034BC: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800034C0: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800034C4: andi        $t1, $t0, 0xFF7F
    ctx->r9 = ctx->r8 & 0XFF7F;
    // 0x800034C8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800034CC: lw          $v0, 0x44($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X44);
    // 0x800034D0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x800034D4: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x800034D8: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800034DC:
    // 0x800034DC: jal         0x8000B2D4
    // 0x800034E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000B2D4(rdram, ctx);
        goto after_0;
    // 0x800034E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800034E4: jal         0x8000C170
    // 0x800034E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8000C170(rdram, ctx);
        goto after_1;
    // 0x800034E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800034EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800034F0: jal         0x8000DB94
    // 0x800034F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_8000DB94(rdram, ctx);
        goto after_2;
    // 0x800034F4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800034F8: lw          $v0, 0x1DAC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X1DAC);
    // 0x800034FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80003500:
    // 0x80003500: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80003504: bne         $at, $zero, L_80003490
    if (ctx->r1 != 0) {
        // 0x80003508: addiu       $s2, $s2, 0xD0
        ctx->r18 = ADD32(ctx->r18, 0XD0);
            goto L_80003490;
    }
    // 0x80003508: addiu       $s2, $s2, 0xD0
    ctx->r18 = ADD32(ctx->r18, 0XD0);
L_8000350C:
    // 0x8000350C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80003510: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80003514: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80003518: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000351C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80003520: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80003524: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80003528: jr          $ra
    // 0x8000352C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000352C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_805C8E20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C8E20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C8E24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C8E28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C8E2C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C8E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C8E34: jal         0x8004700C
    // 0x805C8E38: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C8E38: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C8E3C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805C8E40: beq         $v0, $zero, L_805C906C
    if (ctx->r2 == 0) {
        // 0x805C8E44: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_805C906C;
    }
    // 0x805C8E44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805C8E48: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x805C8E4C: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x805C8E50: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8E54: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x805C8E58: lwc1        $f6, 0x30($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X30);
    // 0x805C8E5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C8E60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8E64: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C8E68: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C8E6C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805C8E70: nop

    // 0x805C8E74: bc1fl       L_805C8F64
    if (!c1cs) {
        // 0x805C8E78: sw          $v1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r3;
            goto L_805C8F64;
    }
    goto skip_0;
    // 0x805C8E78: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    skip_0:
    // 0x805C8E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8E80: jal         0x805C6E30
    // 0x805C8E84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    func_805C6E30(rdram, ctx);
        goto after_1;
    // 0x805C8E84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_1:
    // 0x805C8E88: bne         $v0, $zero, L_805C8EEC
    if (ctx->r2 != 0) {
        // 0x805C8E8C: lw          $v1, 0x28($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X28);
            goto L_805C8EEC;
    }
    // 0x805C8E8C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805C8E90: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x805C8E94: lw          $t7, -0x7CE8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CE8);
    // 0x805C8E98: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8E9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805C8EA0: lwc1        $f16, 0x30($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X30);
    // 0x805C8EA4: lui         $at, 0xC090
    ctx->r1 = S32(0XC090 << 16);
    // 0x805C8EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8EAC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C8EB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8EB4: bc1fl       L_805C8ED4
    if (!c1cs) {
        // 0x805C8EB8: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_805C8ED4;
    }
    goto skip_1;
    // 0x805C8EB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x805C8EBC: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x805C8EC0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C8EC4: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x805C8EC8: b           L_805C8EDC
    // 0x805C8ECC: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
        goto L_805C8EDC;
    // 0x805C8ECC: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x805C8ED0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_805C8ED4:
    // 0x805C8ED4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805C8ED8: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
L_805C8EDC:
    // 0x805C8EDC: jal         0x805C9D10
    // 0x805C8EE0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C8EE0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_2:
    // 0x805C8EE4: b           L_805C9070
    // 0x805C8EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9070;
    // 0x805C8EE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8EEC:
    // 0x805C8EEC: lui         $at, 0x43B5
    ctx->r1 = S32(0X43B5 << 16);
    // 0x805C8EF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x805C8EF4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C8EF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805C8EFC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x805C8F00: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x805C8F04: nop

    // 0x805C8F08: bc1fl       L_805C8F1C
    if (!c1cs) {
        // 0x805C8F0C: sw          $t0, 0x38($v1)
        MEM_W(0X38, ctx->r3) = ctx->r8;
            goto L_805C8F1C;
    }
    goto skip_2;
    // 0x805C8F0C: sw          $t0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r8;
    skip_2:
    // 0x805C8F10: b           L_805C8F1C
    // 0x805C8F14: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
        goto L_805C8F1C;
    // 0x805C8F14: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    // 0x805C8F18: sw          $t0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r8;
L_805C8F1C:
    // 0x805C8F1C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x805C8F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8F24: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C8F28: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x805C8F2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8F30: bc1fl       L_805C8F40
    if (!c1cs) {
        // 0x805C8F34: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_805C8F40;
    }
    goto skip_3;
    // 0x805C8F34: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_3:
    // 0x805C8F38: sw          $zero, 0x38($v1)
    MEM_W(0X38, ctx->r3) = 0;
    // 0x805C8F3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_805C8F40:
    // 0x805C8F40: jal         0x805C74C8
    // 0x805C8F44: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    func_805C74C8(rdram, ctx);
        goto after_3;
    // 0x805C8F44: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    after_3:
    // 0x805C8F48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8F50: jal         0x805C9D10
    // 0x805C8F54: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_805C9D10(rdram, ctx);
        goto after_4;
    // 0x805C8F54: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_4:
    // 0x805C8F58: b           L_805C9070
    // 0x805C8F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9070;
    // 0x805C8F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805C8F60: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_805C8F64:
    // 0x805C8F64: jal         0x805C6AF0
    // 0x805C8F68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_805C6AF0(rdram, ctx);
        goto after_5;
    // 0x805C8F68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_5:
    // 0x805C8F6C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805C8F70: bne         $v0, $zero, L_805C8F94
    if (ctx->r2 != 0) {
        // 0x805C8F74: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_805C8F94;
    }
    // 0x805C8F74: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x805C8F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8F7C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x805C8F80: jal         0x805C6E30
    // 0x805C8F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_805C6E30(rdram, ctx);
        goto after_6;
    // 0x805C8F84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_6:
    // 0x805C8F88: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x805C8F8C: beq         $v0, $zero, L_805C8FE4
    if (ctx->r2 == 0) {
        // 0x805C8F90: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_805C8FE4;
    }
    // 0x805C8F90: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
L_805C8F94:
    // 0x805C8F94: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    // 0x805C8F98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C8F9C: sw          $t1, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r9;
    // 0x805C8FA0: sw          $zero, 0x34($v1)
    MEM_W(0X34, ctx->r3) = 0;
    // 0x805C8FA4: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C8FA8: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C8FAC: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C8FB0: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x805C8FB4: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x805C8FB8: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x805C8FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8FC0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x805C8FC4: jal         0x805C74C8
    // 0x805C8FC8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    func_805C74C8(rdram, ctx);
        goto after_7;
    // 0x805C8FC8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    after_7:
    // 0x805C8FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8FD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8FD4: jal         0x805C9D10
    // 0x805C8FD8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_805C9D10(rdram, ctx);
        goto after_8;
    // 0x805C8FD8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_8:
    // 0x805C8FDC: b           L_805C9070
    // 0x805C8FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C9070;
    // 0x805C8FE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8FE4:
    // 0x805C8FE4: lwc1        $f10, 0x84($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805C8FE8: lwc1        $f16, 0x84($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X84);
    // 0x805C8FEC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x805C8FF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805C8FF4: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805C8FF8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C8FFC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805C9000: nop

    // 0x805C9004: bc1fl       L_805C904C
    if (!c1cs) {
        // 0x805C9008: lw          $t3, 0x2C($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X2C);
            goto L_805C904C;
    }
    goto skip_4;
    // 0x805C9008: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    skip_4:
    // 0x805C900C: lwc1        $f18, 0x88($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X88);
    // 0x805C9010: lwc1        $f4, 0x88($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X88);
    // 0x805C9014: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x805C9018: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C901C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805C9020: nop

    // 0x805C9024: bc1fl       L_805C904C
    if (!c1cs) {
        // 0x805C9028: lw          $t3, 0x2C($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X2C);
            goto L_805C904C;
    }
    goto skip_5;
    // 0x805C9028: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    skip_5:
    // 0x805C902C: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    // 0x805C9030: bne         $t2, $zero, L_805C905C
    if (ctx->r10 != 0) {
        // 0x805C9034: nop
    
            goto L_805C905C;
    }
    // 0x805C9034: nop

    // 0x805C9038: jal         0x805C781C
    // 0x805C903C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C781C(rdram, ctx);
        goto after_9;
    // 0x805C903C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x805C9040: b           L_805C905C
    // 0x805C9044: nop

        goto L_805C905C;
    // 0x805C9044: nop

    // 0x805C9048: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
L_805C904C:
    // 0x805C904C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x805C9050: bne         $t3, $at, L_805C905C
    if (ctx->r11 != ctx->r1) {
        // 0x805C9054: nop
    
            goto L_805C905C;
    }
    // 0x805C9054: nop

    // 0x805C9058: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_805C905C:
    // 0x805C905C: jal         0x805C6CA4
    // 0x805C9060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C6CA4(rdram, ctx);
        goto after_10;
    // 0x805C9060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x805C9064: jal         0x805C7ABC
    // 0x805C9068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_11;
    // 0x805C9068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
L_805C906C:
    // 0x805C906C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C9070:
    // 0x805C9070: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C9074: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805C9078: jr          $ra
    // 0x805C907C: nop

    return;
    // 0x805C907C: nop

;}
RECOMP_FUNC void func_8002C74C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C74C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C754: jal         0x8002C684
    // 0x8002C758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002C684(rdram, ctx);
        goto after_0;
    // 0x8002C758: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002C75C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002C760: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002C764: lwc1        $f6, -0x68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X68);
    // 0x8002C768: lwc1        $f4, 0x7C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8002C76C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002C770: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8002C774: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C778: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C77C: jr          $ra
    // 0x8002C780: nop

    return;
    // 0x8002C780: nop

;}
RECOMP_FUNC void func_8005EA4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005EA50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005EA54: lw          $a2, 0x16C($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X16C);
    // 0x8005EA58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005EA5C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005EA60: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x8005EA64: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8005EA68: bne         $v0, $at, L_8005EA78
    if (ctx->r2 != ctx->r1) {
        // 0x8005EA6C: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8005EA78;
    }
    // 0x8005EA6C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8005EA70: b           L_8005EB28
    // 0x8005EA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EB28;
    // 0x8005EA74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EA78:
    // 0x8005EA78: lw          $t6, -0x76CC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76CC);
    // 0x8005EA7C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8005EA80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005EA84: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8005EA88: bne         $v1, $zero, L_8005EA98
    if (ctx->r3 != 0) {
        // 0x8005EA8C: lui         $v0, 0x8000
        ctx->r2 = S32(0X8000 << 16);
            goto L_8005EA98;
    }
    // 0x8005EA8C: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8005EA90: b           L_8005EB28
    // 0x8005EA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005EB28;
    // 0x8005EA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005EA98:
    // 0x8005EA98: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8005EA9C: bne         $at, $zero, L_8005EAC4
    if (ctx->r1 != 0) {
        // 0x8005EAA0: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_8005EAC4;
    }
    // 0x8005EAA0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8005EAA4: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x8005EAA8: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x8005EAAC: beq         $at, $zero, L_8005EAC4
    if (ctx->r1 == 0) {
        // 0x8005EAB0: lui         $t8, 0x8000
        ctx->r24 = S32(0X8000 << 16);
            goto L_8005EAC4;
    }
    // 0x8005EAB0: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8005EAB4: lw          $t8, 0x318($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X318);
    // 0x8005EAB8: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8005EABC: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x8005EAC0: bne         $at, $zero, L_8005EAE8
    if (ctx->r1 != 0) {
        // 0x8005EAC4: addiu       $a0, $a0, 0xD30
        ctx->r4 = ADD32(ctx->r4, 0XD30);
            goto L_8005EAE8;
    }
L_8005EAC4:
    // 0x8005EAC4: addiu       $a0, $a0, 0xD30
    ctx->r4 = ADD32(ctx->r4, 0XD30);
    // 0x8005EAC8: addiu       $a1, $zero, 0x381
    ctx->r5 = ADD32(0, 0X381);
    // 0x8005EACC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8005EAD0: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8005EAD4: jal         0x80071380
    // 0x8005EAD8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x8005EAD8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005EADC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005EAE0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8005EAE4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
L_8005EAE8:
    // 0x8005EAE8: lbu         $t0, 0x165($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X165);
    // 0x8005EAEC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EAF0: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x8005EAF4: beq         $t0, $at, L_8005EB28
    if (ctx->r8 == ctx->r1) {
        // 0x8005EAF8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005EB28;
    }
    // 0x8005EAF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005EAFC: addiu       $t2, $zero, 0x88
    ctx->r10 = ADD32(0, 0X88);
    // 0x8005EB00: sh          $t2, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r10;
    // 0x8005EB04: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x8005EB08: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8005EB0C: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8005EB10: lw          $t3, 0x30($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X30);
    // 0x8005EB14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005EB18: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8005EB1C: lw          $t4, 0x34($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X34);
    // 0x8005EB20: b           L_8005EB28
    // 0x8005EB24: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
        goto L_8005EB28;
    // 0x8005EB24: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
L_8005EB28:
    // 0x8005EB28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005EB2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005EB30: jr          $ra
    // 0x8005EB34: nop

    return;
    // 0x8005EB34: nop

;}
RECOMP_FUNC void func_806AEAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEAEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806AEAF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806AEAF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806AEAF8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806AEAFC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x806AEB00: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x806AEB04: lui         $at, 0x4338
    ctx->r1 = S32(0X4338 << 16);
    // 0x806AEB08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806AEB0C: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806AEB10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806AEB14: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x806AEB18: nop

    // 0x806AEB1C: bc1fl       L_806AEB44
    if (!c1cs) {
        // 0x806AEB20: lw          $t7, 0x1E0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X1E0);
            goto L_806AEB44;
    }
    goto skip_0;
    // 0x806AEB20: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
    skip_0:
    // 0x806AEB24: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x806AEB28: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x806AEB2C: beq         $at, $zero, L_806AEB40
    if (ctx->r1 == 0) {
        // 0x806AEB30: lui         $at, 0x806B
        ctx->r1 = S32(RELOC_HI16(595, 0X1F9C) << 16);
            goto L_806AEB40;
    }
    // 0x806AEB30: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1F9C) << 16);
    // 0x806AEB34: lwc1        $f6, -0x324($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1F9C));
    // 0x806AEB38: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x806AEB3C: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
L_806AEB40:
    // 0x806AEB40: lw          $t7, 0x1E0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1E0);
L_806AEB44:
    // 0x806AEB44: bne         $t7, $zero, L_806AEB70
    if (ctx->r15 != 0) {
        // 0x806AEB48: nop
    
            goto L_806AEB70;
    }
    // 0x806AEB48: nop

    // 0x806AEB4C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x806AEB50: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x806AEB54: bne         $t8, $at, L_806AEB70
    if (ctx->r24 != ctx->r1) {
        // 0x806AEB58: nop
    
            goto L_806AEB70;
    }
    // 0x806AEB58: nop

    // 0x806AEB5C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x806AEB60: bne         $t9, $zero, L_806AEB70
    if (ctx->r25 != 0) {
        // 0x806AEB64: nop
    
            goto L_806AEB70;
    }
    // 0x806AEB64: nop

    // 0x806AEB68: jal         0x800677F8
    // 0x806AEB6C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    func_800677F8(rdram, ctx);
        goto after_0;
    // 0x806AEB6C: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_0:
L_806AEB70:
    // 0x806AEB70: jal         0x806AE458
    // 0x806AEB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEB74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806AEB78: beql        $v0, $zero, L_806AEBCC
    if (ctx->r2 == 0) {
        // 0x806AEB7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806AEBCC;
    }
    goto skip_1;
    // 0x806AEB7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x806AEB80: lw          $t0, 0x1E0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X1E0);
    // 0x806AEB84: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x806AEB88: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x806AEB8C: bne         $t1, $at, L_806AEBC8
    if (ctx->r9 != ctx->r1) {
        // 0x806AEB90: sw          $t1, 0x1E0($s0)
        MEM_W(0X1E0, ctx->r16) = ctx->r9;
            goto L_806AEBC8;
    }
    // 0x806AEB90: sw          $t1, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r9;
    // 0x806AEB94: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x806AEB98: jal         0x80067BBC
    // 0x806AEB9C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x806AEB9C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x806AEBA0: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x806AEBA4: jal         0x80067F78
    // 0x806AEBA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x806AEBA8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x806AEBAC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x806AEBB0: jal         0x800492C0
    // 0x806AEBB4: addiu       $a0, $zero, -0x64
    ctx->r4 = ADD32(0, -0X64);
    func_800492C0(rdram, ctx);
        goto after_4;
    // 0x806AEBB4: addiu       $a0, $zero, -0x64
    ctx->r4 = ADD32(0, -0X64);
    after_4:
    // 0x806AEBB8: lui         $t3, 0x806B
    ctx->r11 = S32(RELOC_HI16(595, 0XCE4) << 16);
    // 0x806AEBBC: addiu       $t3, $t3, -0x15DC
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(595, 0XCE4));
    // 0x806AEBC0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x806AEBC4: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
L_806AEBC8:
    // 0x806AEBC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806AEBCC:
    // 0x806AEBCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806AEBD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806AEBD4: jr          $ra
    // 0x806AEBD8: nop

    return;
    // 0x806AEBD8: nop

;}
RECOMP_FUNC void func_807C5188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C5188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807C518C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807C5190: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807C5194: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x807C5198: jal         0x807C49D0
    // 0x807C519C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807C49D0(rdram, ctx);
        goto after_0;
    // 0x807C519C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807C51A0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807C51A4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807C51A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807C51AC: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x807C51B0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x807C51B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x807C51B8: beq         $v1, $zero, L_807C51C8
    if (ctx->r3 == 0) {
        // 0x807C51BC: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_807C51C8;
    }
    // 0x807C51BC: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x807C51C0: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x807C51C4: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_807C51C8:
    // 0x807C51C8: bnel        $v1, $zero, L_807C5204
    if (ctx->r3 != 0) {
        // 0x807C51CC: lui         $at, 0x4200
        ctx->r1 = S32(0X4200 << 16);
            goto L_807C5204;
    }
    goto skip_0;
    // 0x807C51CC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    skip_0:
    // 0x807C51D0: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x807C51D4: lui         $t9, 0x807C
    ctx->r25 = S32(RELOC_HI16(910, 0XEF8) << 16);
    // 0x807C51D8: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x807C51DC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x807C51E0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x807C51E4: lw          $t9, 0x58B8($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(910, 0XEF8));
    // 0x807C51E8: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x807C51EC: slti        $at, $t0, 0x6
    ctx->r1 = SIGNED(ctx->r8) < 0X6 ? 1 : 0;
    // 0x807C51F0: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    // 0x807C51F4: bne         $at, $zero, L_807C5200
    if (ctx->r1 != 0) {
        // 0x807C51F8: sw          $t9, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->r25;
            goto L_807C5200;
    }
    // 0x807C51F8: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x807C51FC: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
L_807C5200:
    // 0x807C5200: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
L_807C5204:
    // 0x807C5204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x807C5208: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x807C520C: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x807C5210: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807C5214: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x807C5218: nop

    // 0x807C521C: bc1fl       L_807C525C
    if (!c1cs) {
        // 0x807C5220: addiu       $a0, $a3, 0xC4
        ctx->r4 = ADD32(ctx->r7, 0XC4);
            goto L_807C525C;
    }
    goto skip_1;
    // 0x807C5220: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    skip_1:
    // 0x807C5224: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807C5228: addiu       $v1, $a3, 0xC4
    ctx->r3 = ADD32(ctx->r7, 0XC4);
    // 0x807C522C: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(910, 0X1348) << 16);
    // 0x807C5230: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x807C5234: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x807C5238: lwc1        $f16, 0x5D08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(910, 0X1348));
    // 0x807C523C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807C5240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x807C5244: swc1        $f16, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f16.u32l;
    // 0x807C5248: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x807C524C: jal         0x807C5464
    // 0x807C5250: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_807C5464(rdram, ctx);
        goto after_1;
    // 0x807C5250: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x807C5254: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x807C5258: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
L_807C525C:
    // 0x807C525C: jal         0x80048F84
    // 0x807C5260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_2;
    // 0x807C5260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x807C5264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807C5268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807C526C: jr          $ra
    // 0x807C5270: nop

    return;
    // 0x807C5270: nop

;}
RECOMP_FUNC void func_804D12D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D12D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D12D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804D12D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D12DC: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(246, 0X430) << 16);
    // 0x804D12E0: lui         $a1, 0x804D
    ctx->r5 = S32(RELOC_HI16(246, 0X440) << 16);
    // 0x804D12E4: addiu       $a1, $a1, 0x1710
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(246, 0X440));
    // 0x804D12E8: addiu       $a0, $a0, 0x1700
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(246, 0X430));
    // 0x804D12EC: jal         0x8004667C
    // 0x804D12F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804D12F0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x804D12F4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804D12F8: lui         $a2, 0x804D
    ctx->r6 = S32(RELOC_HI16(246, 0X290) << 16);
    // 0x804D12FC: addiu       $a2, $a2, 0x1560
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(246, 0X290));
    // 0x804D1300: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804D1304: jal         0x80057B28
    // 0x804D1308: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804D1308: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x804D130C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D1310: lui         $v0, 0x804D
    ctx->r2 = S32(RELOC_HI16(246, 0X50) << 16);
    // 0x804D1314: addiu       $v0, $v0, 0x1320
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(246, 0X50));
    // 0x804D1318: jr          $ra
    // 0x804D131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D131C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_804B6FA8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B6FB0: jal         0x804B6BF8
    // 0x804B6FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B6BF8(rdram, ctx);
        goto after_0;
    // 0x804B6FB4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B6FB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6FBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804B6FC0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804B6FC4: jal         0x804B6FF0
    // 0x804B6FC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_804B6FF0(rdram, ctx);
        goto after_1;
    // 0x804B6FC8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x804B6FCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B6FD0: lui         $t6, 0x804B
    ctx->r14 = S32(RELOC_HI16(182, 0XCD0) << 16);
    // 0x804B6FD4: addiu       $t6, $t6, 0x6F70
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(182, 0XCD0));
    // 0x804B6FD8: jal         0x80057978
    // 0x804B6FDC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    func_80057978(rdram, ctx);
        goto after_2;
    // 0x804B6FDC: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    after_2:
    // 0x804B6FE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B6FE4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B6FE8: jr          $ra
    // 0x804B6FEC: nop

    return;
    // 0x804B6FEC: nop

;}
RECOMP_FUNC void func_806EAC60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EAC60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806EAC64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806EAC68: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EAC6C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF64) << 16);
    // 0x806EAC70: lwc1        $f6, -0x48CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF64));
    // 0x806EAC74: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x806EAC78: lwc1        $f4, 0xC4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x806EAC7C: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF68) << 16);
    // 0x806EAC80: lwc1        $f10, 0xC8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806EAC84: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806EAC88: swc1        $f8, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f8.u32l;
    // 0x806EAC8C: lwc1        $f16, -0x48C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF68));
    // 0x806EAC90: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806EAC94: swc1        $f18, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f18.u32l;
    // 0x806EAC98: jal         0x806EA9C0
    // 0x806EAC9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_806EA9C0(rdram, ctx);
        goto after_0;
    // 0x806EAC9C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x806EACA0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806EACA4: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(670, 0XF6C) << 16);
    // 0x806EACA8: lwc1        $f10, -0x48C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(670, 0XF6C));
    // 0x806EACAC: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806EACB0: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x806EACB4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x806EACB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EACBC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x806EACC0: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x806EACC4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x806EACC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806EACCC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EACD0: nop

    // 0x806EACD4: bc1fl       L_806EAD18
    if (!c1cs) {
        // 0x806EACD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806EAD18;
    }
    goto skip_0;
    // 0x806EACD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806EACDC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x806EACE0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x806EACE4: jal         0x806EB43C
    // 0x806EACE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_806EB43C(rdram, ctx);
        goto after_1;
    // 0x806EACE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x806EACEC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x806EACF0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806EACF4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x806EACF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x806EACFC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x806EAD00: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806EAD04: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806EAD08: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x806EAD0C: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806EAD10: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x806EAD14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806EAD18:
    // 0x806EAD18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x806EAD1C: jr          $ra
    // 0x806EAD20: nop

    return;
    // 0x806EAD20: nop

;}
RECOMP_FUNC void func_807C6A40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807C6A40: lui         $v0, 0x807C
    ctx->r2 = S32(RELOC_HI16(919, 0X10) << 16);
    // 0x807C6A44: addiu       $v0, $v0, 0x6A50
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(919, 0X10));
    // 0x807C6A48: jr          $ra
    // 0x807C6A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x807C6A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8000BBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BBF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000BBF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000BBFC: jal         0x8000B9C0
    // 0x8000BC00: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    func_8000B9C0(rdram, ctx);
        goto after_0;
    // 0x8000BC00: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_0:
    // 0x8000BC04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000BC08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000BC0C: jr          $ra
    // 0x8000BC10: nop

    return;
    // 0x8000BC10: nop

;}
RECOMP_FUNC void func_804EF604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EF604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804EF608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804EF60C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804EF610: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804EF614: lui         $t8, 0x804F
    ctx->r24 = S32(RELOC_HI16(267, 0X10AC) << 16);
    // 0x804EF618: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804EF61C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804EF620: lw          $t8, -0x1C4($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(267, 0X10AC));
    // 0x804EF624: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804EF628: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804EF62C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804EF630: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804EF634: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804EF638: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804EF63C: beql        $v1, $zero, L_804EF670
    if (ctx->r3 == 0) {
        // 0x804EF640: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804EF670;
    }
    goto skip_0;
    // 0x804EF640: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804EF644: jalr        $v1
    // 0x804EF648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804EF648: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804EF64C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804EF650: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804EF654: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804EF658: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804EF65C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804EF660: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804EF664: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804EF668: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804EF66C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804EF670:
    // 0x804EF670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804EF674: jr          $ra
    // 0x804EF678: nop

    return;
    // 0x804EF678: nop

;}
RECOMP_FUNC void func_8073EA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8073EA50: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8073EA54: lui         $t6, 0x8074
    ctx->r14 = S32(RELOC_HI16(748, 0X218) << 16);
    // 0x8073EA58: addiu       $t6, $t6, -0x15F8
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(748, 0X218));
    // 0x8073EA5C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8073EA60: jr          $ra
    // 0x8073EA64: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8073EA64: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_80455DE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80455DE0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80455DE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80455DE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80455DEC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455DF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80455DF4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80455DF8: sw          $t6, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = ctx->r14;
    // 0x80455DFC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80455E00: jal         0x8044EFA0
    // 0x80455E04: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_8044EFA0(rdram, ctx);
        goto after_0;
    // 0x80455E04: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80455E08: jal         0x804449C0
    // 0x80455E0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_804449C0(rdram, ctx);
        goto after_1;
    // 0x80455E0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80455E10: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80455E14: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80455E18: jal         0x80450490
    // 0x80455E1C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    func_80450490(rdram, ctx);
        goto after_2;
    // 0x80455E1C: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_2:
    // 0x80455E20: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80455E24: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455E28: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80455E2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80455E30: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80455E34: sw          $t7, 0x6CE8($at)
    MEM_W(0X6CE8, ctx->r1) = ctx->r15;
    // 0x80455E38: lui         $t9, 0x8046
    ctx->r25 = S32(RELOC_HI16(98, 0X13D4C) << 16);
    // 0x80455E3C: lw          $t9, -0x7ED4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(98, 0X13D4C));
    // 0x80455E40: jalr        $t9
    // 0x80455E44: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80455E44: nop

    after_3:
    // 0x80455E48: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80455E4C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80455E50: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80455E54: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80455E58: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80455E5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80455E60: jal         0x80455D88
    // 0x80455E64: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    func_80455D88(rdram, ctx);
        goto after_4;
    // 0x80455E64: swc1        $f4, 0x6CE0($at)
    MEM_W(0X6CE0, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x80455E68: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80455E6C: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80455E70: lw          $t1, 0xFB8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XFB8);
    // 0x80455E74: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80455E78: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80455E7C: srl         $t3, $t2, 30
    ctx->r11 = S32(U32(ctx->r10) >> 30);
    // 0x80455E80: bnel        $t3, $zero, L_80455F9C
    if (ctx->r11 != 0) {
        // 0x80455E84: lbu         $v0, 0xF5D($v1)
        ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
            goto L_80455F9C;
    }
    goto skip_0;
    // 0x80455E84: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    skip_0:
    // 0x80455E88: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
    // 0x80455E8C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455E90: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80455E94: bne         $v0, $zero, L_80455ED0
    if (ctx->r2 != 0) {
        // 0x80455E98: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80455ED0;
    }
    // 0x80455E98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80455E9C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14128) << 16);
    // 0x80455EA0: lwc1        $f0, -0x7AF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14128));
    // 0x80455EA4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80455EA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80455EAC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1412C) << 16);
    // 0x80455EB0: lwc1        $f8, -0x7AF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1412C));
    // 0x80455EB4: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80455EB8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80455EBC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80455EC0: jal         0x80444B28
    // 0x80455EC4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80444B28(rdram, ctx);
        goto after_5;
    // 0x80455EC4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x80455EC8: b           L_80456084
    // 0x80455ECC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80455ECC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80455ED0:
    // 0x80455ED0: bne         $v0, $at, L_80455F10
    if (ctx->r2 != ctx->r1) {
        // 0x80455ED4: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_80455F10;
    }
    // 0x80455ED4: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455ED8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14130) << 16);
    // 0x80455EDC: lwc1        $f0, -0x7AF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14130));
    // 0x80455EE0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80455EE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80455EE8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14134) << 16);
    // 0x80455EEC: lwc1        $f16, -0x7AEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14134));
    // 0x80455EF0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80455EF4: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80455EF8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80455EFC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80455F00: jal         0x80444B28
    // 0x80455F04: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_6;
    // 0x80455F04: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80455F08: b           L_80456084
    // 0x80455F0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80455F0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80455F10:
    // 0x80455F10: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80455F14: bne         $v0, $at, L_80455F54
    if (ctx->r2 != ctx->r1) {
        // 0x80455F18: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_80455F54;
    }
    // 0x80455F18: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455F1C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14138) << 16);
    // 0x80455F20: lwc1        $f0, -0x7AE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14138));
    // 0x80455F24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80455F28: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80455F2C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1413C) << 16);
    // 0x80455F30: lwc1        $f4, -0x7AE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1413C));
    // 0x80455F34: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80455F38: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80455F3C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80455F40: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80455F44: jal         0x80444B28
    // 0x80455F48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_7;
    // 0x80455F48: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x80455F4C: b           L_80456084
    // 0x80455F50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80455F50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80455F54:
    // 0x80455F54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80455F58: bne         $v0, $at, L_80456080
    if (ctx->r2 != ctx->r1) {
        // 0x80455F5C: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_80456080;
    }
    // 0x80455F5C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455F60: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14140) << 16);
    // 0x80455F64: lwc1        $f0, -0x7AE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14140));
    // 0x80455F68: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80455F6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80455F70: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14144) << 16);
    // 0x80455F74: lwc1        $f8, -0x7ADC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14144));
    // 0x80455F78: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80455F7C: lui         $a3, 0xC307
    ctx->r7 = S32(0XC307 << 16);
    // 0x80455F80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80455F84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80455F88: jal         0x80444B28
    // 0x80455F8C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    func_80444B28(rdram, ctx);
        goto after_8;
    // 0x80455F8C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x80455F90: b           L_80456084
    // 0x80455F94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80455F94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80455F98: lbu         $v0, 0xF5D($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF5D);
L_80455F9C:
    // 0x80455F9C: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455FA0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80455FA4: bne         $v0, $zero, L_80455FD8
    if (ctx->r2 != 0) {
        // 0x80455FA8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80455FD8;
    }
    // 0x80455FA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80455FAC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14148) << 16);
    // 0x80455FB0: lwc1        $f0, -0x7AD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14148));
    // 0x80455FB4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80455FB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80455FBC: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80455FC0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80455FC4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80455FC8: jal         0x80444B28
    // 0x80455FCC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_80444B28(rdram, ctx);
        goto after_9;
    // 0x80455FCC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x80455FD0: b           L_80456084
    // 0x80455FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80455FD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80455FD8:
    // 0x80455FD8: bne         $v0, $at, L_80456010
    if (ctx->r2 != ctx->r1) {
        // 0x80455FDC: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_80456010;
    }
    // 0x80455FDC: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80455FE0: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1414C) << 16);
    // 0x80455FE4: lwc1        $f0, -0x7AD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1414C));
    // 0x80455FE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80455FEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80455FF0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80455FF4: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80455FF8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80455FFC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456000: jal         0x80444B28
    // 0x80456004: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    func_80444B28(rdram, ctx);
        goto after_10;
    // 0x80456004: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x80456008: b           L_80456084
    // 0x8045600C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x8045600C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80456010:
    // 0x80456010: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80456014: bne         $v0, $at, L_8045604C
    if (ctx->r2 != ctx->r1) {
        // 0x80456018: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_8045604C;
    }
    // 0x80456018: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x8045601C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14150) << 16);
    // 0x80456020: lwc1        $f0, -0x7AD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14150));
    // 0x80456024: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456028: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8045602C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80456030: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456034: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456038: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8045603C: jal         0x80444B28
    // 0x80456040: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    func_80444B28(rdram, ctx);
        goto after_11;
    // 0x80456040: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80456044: b           L_80456084
    // 0x80456048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80456084;
    // 0x80456048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8045604C:
    // 0x8045604C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80456050: bne         $v0, $at, L_80456080
    if (ctx->r2 != ctx->r1) {
        // 0x80456054: addiu       $a1, $zero, 0x4024
        ctx->r5 = ADD32(0, 0X4024);
            goto L_80456080;
    }
    // 0x80456054: addiu       $a1, $zero, 0x4024
    ctx->r5 = ADD32(0, 0X4024);
    // 0x80456058: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14154) << 16);
    // 0x8045605C: lwc1        $f0, -0x7ACC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14154));
    // 0x80456060: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80456064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80456068: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8045606C: lui         $a3, 0xC2D6
    ctx->r7 = S32(0XC2D6 << 16);
    // 0x80456070: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80456074: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80456078: jal         0x80444B28
    // 0x8045607C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80444B28(rdram, ctx);
        goto after_12;
    // 0x8045607C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_12:
L_80456080:
    // 0x80456080: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80456084:
    // 0x80456084: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80456088: jr          $ra
    // 0x8045608C: nop

    return;
    // 0x8045608C: nop

;}
RECOMP_FUNC void func_807BB160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BB160: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807BB164: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BB168: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807BB16C: jal         0x807BA848
    // 0x807BB170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_807BA848(rdram, ctx);
        goto after_0;
    // 0x807BB170: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x807BB174: jal         0x807BABD4
    // 0x807BB178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BABD4(rdram, ctx);
        goto after_1;
    // 0x807BB178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x807BB17C: jal         0x807BAB94
    // 0x807BB180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAB94(rdram, ctx);
        goto after_2;
    // 0x807BB180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x807BB184: jal         0x807BAA20
    // 0x807BB188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_807BAA20(rdram, ctx);
        goto after_3;
    // 0x807BB188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x807BB18C: beql        $v0, $zero, L_807BB1D0
    if (ctx->r2 == 0) {
        // 0x807BB190: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_807BB1D0;
    }
    goto skip_0;
    // 0x807BB190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x807BB194: lw          $t6, 0x12C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X12C);
    // 0x807BB198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB19C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB1A0: bne         $t6, $zero, L_807BB1C4
    if (ctx->r14 != 0) {
        // 0x807BB1A4: addiu       $a2, $zero, 0x3
        ctx->r6 = ADD32(0, 0X3);
            goto L_807BB1C4;
    }
    // 0x807BB1A4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807BB1A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807BB1AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807BB1B0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x807BB1B4: jal         0x807BB7A4
    // 0x807BB1B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_807BB7A4(rdram, ctx);
        goto after_4;
    // 0x807BB1B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x807BB1BC: b           L_807BB1D0
    // 0x807BB1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_807BB1D0;
    // 0x807BB1C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB1C4:
    // 0x807BB1C4: jal         0x807BB7A4
    // 0x807BB1C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_807BB7A4(rdram, ctx);
        goto after_5;
    // 0x807BB1C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x807BB1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_807BB1D0:
    // 0x807BB1D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807BB1D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807BB1D8: jr          $ra
    // 0x807BB1DC: nop

    return;
    // 0x807BB1DC: nop

;}
RECOMP_FUNC void func_8005E820(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E820: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005E824: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005E828: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005E82C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005E830: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005E834: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005E838: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005E83C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8005E840:
    // 0x8005E840: jal         0x8005D8C0
    // 0x8005E844: nop

    func_8005D8C0(rdram, ctx);
        goto after_0;
    // 0x8005E844: nop

    after_0:
    // 0x8005E848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005E84C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005E850: jal         0x8007BE70
    // 0x8005E854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_8007BE70(rdram, ctx);
        goto after_1;
    // 0x8005E854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8005E858: jal         0x8007FCF0
    // 0x8005E85C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    func_8007FCF0(rdram, ctx);
        goto after_2;
    // 0x8005E85C: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    after_2:
    // 0x8005E860: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005E864: bne         $s1, $s2, L_8005E840
    if (ctx->r17 != ctx->r18) {
        // 0x8005E868: addiu       $s0, $s0, 0x28
        ctx->r16 = ADD32(ctx->r16, 0X28);
            goto L_8005E840;
    }
    // 0x8005E868: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x8005E86C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005E870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005E874: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005E878: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005E87C: jr          $ra
    // 0x8005E880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005E880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8058478C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8058478C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80584790: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80584794: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80584798: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8058479C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805847A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805847A4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805847A8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805847AC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805847B0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805847B4: jr          $ra
    // 0x805847B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805847B8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_807A9E88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807A9E88: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x807A9E8C: lui         $t6, 0x807B
    ctx->r14 = S32(RELOC_HI16(853, 0X1870) << 16);
    // 0x807A9E90: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x807A9E94: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x807A9E98: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x807A9E9C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x807A9EA0: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x807A9EA4: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x807A9EA8: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x807A9EAC: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x807A9EB0: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x807A9EB4: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x807A9EB8: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x807A9EBC: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x807A9EC0: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x807A9EC4: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x807A9EC8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807A9ECC: addiu       $t6, $t6, -0x4B50
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(853, 0X1870));
    // 0x807A9ED0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x807A9ED4: lui         $t9, 0x807B
    ctx->r25 = S32(RELOC_HI16(853, 0X1880) << 16);
    // 0x807A9ED8: addiu       $t9, $t9, -0x4B40
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(853, 0X1880));
    // 0x807A9EDC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x807A9EE0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x807A9EE4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x807A9EE8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x807A9EEC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x807A9EF0: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x807A9EF4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x807A9EF8: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x807A9EFC: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x807A9F00: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x807A9F04: lui         $s4, 0x807B
    ctx->r20 = S32(RELOC_HI16(853, 0X1890) << 16);
    // 0x807A9F08: lui         $s5, 0x807B
    ctx->r21 = S32(RELOC_HI16(853, 0X18A0) << 16);
    // 0x807A9F0C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x807A9F10: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x807A9F14: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807A9F18: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x807A9F1C: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x807A9F20: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x807A9F24: addiu       $s2, $a1, 0x84
    ctx->r18 = ADD32(ctx->r5, 0X84);
    // 0x807A9F28: addiu       $s3, $a1, 0x4
    ctx->r19 = ADD32(ctx->r5, 0X4);
    // 0x807A9F2C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    // 0x807A9F30: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x807A9F34: addiu       $s4, $s4, -0x4B30
    ctx->r20 = ADD32(ctx->r20, (int16_t)RELOC_LO16(853, 0X1890));
    // 0x807A9F38: addiu       $s5, $s5, -0x4B20
    ctx->r21 = ADD32(ctx->r21, (int16_t)RELOC_LO16(853, 0X18A0));
    // 0x807A9F3C: sw          $t1, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r9;
    // 0x807A9F40: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x807A9F44: addiu       $s0, $a0, 0x20
    ctx->r16 = ADD32(ctx->r4, 0X20);
    // 0x807A9F48: addiu       $s1, $a0, 0x30
    ctx->r17 = ADD32(ctx->r4, 0X30);
    // 0x807A9F4C: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x807A9F50: addiu       $s7, $zero, 0x22
    ctx->r23 = ADD32(0, 0X22);
    // 0x807A9F54: mov.s       $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    ctx->f22.fl = ctx->f26.fl;
    // 0x807A9F58: neg.s       $f30, $f30
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); 
    ctx->f30.fl = -ctx->f30.fl;
    // 0x807A9F5C: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
L_807A9F60:
    // 0x807A9F60: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x807A9F64: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x807A9F68: lw          $t2, 0x4($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X4);
    // 0x807A9F6C: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x807A9F70: lw          $t3, 0x8($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X8);
    // 0x807A9F74: sw          $t3, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r11;
    // 0x807A9F78: lw          $t2, 0xC($s4)
    ctx->r10 = MEM_W(ctx->r20, 0XC);
    // 0x807A9F7C: sw          $t2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r10;
    // 0x807A9F80: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x807A9F84: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x807A9F88: lw          $t4, 0x4($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X4);
    // 0x807A9F8C: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x807A9F90: lw          $t5, 0x8($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X8);
    // 0x807A9F94: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
    // 0x807A9F98: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x807A9F9C: sw          $t4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r12;
    // 0x807A9FA0: jal         0x80066DE4
    // 0x807A9FA4: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_0;
    // 0x807A9FA4: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x807A9FA8: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x807A9FAC: jal         0x80066E88
    // 0x807A9FB0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807A9FB0: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x807A9FB4: mul.s       $f16, $f28, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x807A9FB8: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x807A9FBC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x807A9FC0: mul.s       $f2, $f26, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = MUL_S(ctx->f26.fl, ctx->f24.fl);
    // 0x807A9FC4: addiu       $s5, $s5, 0x20
    ctx->r21 = ADD32(ctx->r21, 0X20);
    // 0x807A9FC8: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x807A9FCC: mul.s       $f14, $f26, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x807A9FD0: addiu       $s1, $s1, 0x20
    ctx->r17 = ADD32(ctx->r17, 0X20);
    // 0x807A9FD4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x807A9FD8: mul.s       $f12, $f28, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = MUL_S(ctx->f28.fl, ctx->f24.fl);
    // 0x807A9FDC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x807A9FE0: sub.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x807A9FE4: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x807A9FE8: add.s       $f10, $f14, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x807A9FEC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x807A9FF0: add.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x807A9FF4: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x807A9FF8: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x807A9FFC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x807AA000: sh          $t7, -0x20($s0)
    MEM_H(-0X20, ctx->r16) = ctx->r15;
    // 0x807AA004: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x807AA008: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x807AA00C: sub.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x807AA010: sh          $t9, -0x1E($s0)
    MEM_H(-0X1E, ctx->r16) = ctx->r25;
    // 0x807AA014: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x807AA018: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x807AA01C: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x807AA020: mul.s       $f10, $f30, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f30.fl, ctx->f24.fl);
    // 0x807AA024: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x807AA028: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x807AA02C: sh          $t1, -0x20($s1)
    MEM_H(-0X20, ctx->r17) = ctx->r9;
    // 0x807AA030: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x807AA034: nop

    // 0x807AA038: sh          $t3, -0x1E($s1)
    MEM_H(-0X1E, ctx->r17) = ctx->r11;
    // 0x807AA03C: swc1        $f20, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = ctx->f20.u32l;
    // 0x807AA040: swc1        $f22, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = ctx->f22.u32l;
    // 0x807AA044: add.s       $f20, $f10, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x807AA048: bne         $s6, $s7, L_807A9F60
    if (ctx->r22 != ctx->r23) {
        // 0x807AA04C: add.s       $f22, $f16, $f22
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f22.fl;
            goto L_807A9F60;
    }
    // 0x807AA04C: add.s       $f22, $f16, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x807AA050: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x807AA054: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807AA058: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x807AA05C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x807AA060: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x807AA064: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x807AA068: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x807AA06C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x807AA070: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x807AA074: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x807AA078: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x807AA07C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x807AA080: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x807AA084: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x807AA088: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x807AA08C: jr          $ra
    // 0x807AA090: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x807AA090: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_8004F9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F9B0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8004F9B4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8004F9B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8004F9BC: lwc1        $f4, 0x9A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9A8);
    // 0x8004F9C0: lwc1        $f6, 0x2C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X2C);
    // 0x8004F9C4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8004F9C8: addiu       $t0, $t0, -0x6570
    ctx->r8 = ADD32(ctx->r8, -0X6570);
    // 0x8004F9CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8004F9D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8004F9D4: or          $t8, $zero, $zero
    ctx->r24 = 0 | 0;
    // 0x8004F9D8: sll         $t2, $a1, 3
    ctx->r10 = S32(ctx->r5 << 3);
    // 0x8004F9DC: bc1fl       L_8004F9EC
    if (!c1cs) {
        // 0x8004F9E0: sw          $zero, 0x8($t0)
        MEM_W(0X8, ctx->r8) = 0;
            goto L_8004F9EC;
    }
    goto skip_0;
    // 0x8004F9E0: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
    skip_0:
    // 0x8004F9E4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8004F9E8: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_8004F9EC:
    // 0x8004F9EC: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8004F9F0: lh          $t9, 0x52($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X52);
    // 0x8004F9F4: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x8004F9F8: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8004F9FC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8004FA00: lh          $t1, 0x54($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X54);
    // 0x8004FA04: addu        $a3, $t0, $t2
    ctx->r7 = ADD32(ctx->r8, ctx->r10);
    // 0x8004FA08: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8004FA0C: sw          $t1, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r9;
    // 0x8004FA10: lw          $t6, 0x4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X4);
    // 0x8004FA14: lh          $t5, 0xA($t4)
    ctx->r13 = MEM_H(ctx->r12, 0XA);
    // 0x8004FA18: addu        $t1, $a3, $t9
    ctx->r9 = ADD32(ctx->r7, ctx->r25);
    // 0x8004FA1C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8004FA20: div         $zero, $t5, $t6
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r14)));
    // 0x8004FA24: mfhi        $t7
    ctx->r15 = hi;
    // 0x8004FA28: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8004FA2C: subu        $v0, $t2, $t8
    ctx->r2 = SUB32(ctx->r10, ctx->r24);
    // 0x8004FA30: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8004FA34: bne         $t6, $zero, L_8004FA40
    if (ctx->r14 != 0) {
        // 0x8004FA38: nop
    
            goto L_8004FA40;
    }
    // 0x8004FA38: nop

    // 0x8004FA3C: break       7
    do_break(2147809852);
L_8004FA40:
    // 0x8004FA40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004FA44: bne         $t6, $at, L_8004FA58
    if (ctx->r14 != ctx->r1) {
        // 0x8004FA48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8004FA58;
    }
    // 0x8004FA48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8004FA4C: bne         $t5, $at, L_8004FA58
    if (ctx->r13 != ctx->r1) {
        // 0x8004FA50: nop
    
            goto L_8004FA58;
    }
    // 0x8004FA50: nop

    // 0x8004FA54: break       6
    do_break(2147809876);
L_8004FA58:
    // 0x8004FA58: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8004FA5C: jr          $ra
    // 0x8004FA60: nop

    return;
    // 0x8004FA60: nop

;}
RECOMP_FUNC void func_80555034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80555034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80555038: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8055503C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80555040: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80555044: jal         0x80051194
    // 0x80555048: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x80555048: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x8055504C: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x80555050: jal         0x805551CC
    // 0x80555054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805551CC(rdram, ctx);
        goto after_1;
    // 0x80555054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80555058: beq         $v0, $zero, L_805551B0
    if (ctx->r2 == 0) {
        // 0x8055505C: nop
    
            goto L_805551B0;
    }
    // 0x8055505C: nop

    // 0x80555060: jal         0x80555214
    // 0x80555064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80555214(rdram, ctx);
        goto after_2;
    // 0x80555064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80555068: jal         0x800458EC
    // 0x8055506C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800458EC(rdram, ctx);
        goto after_3;
    // 0x8055506C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80555070: lw          $t8, 0x16C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X16C);
    // 0x80555074: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x80555078: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8055507C: lui         $t7, 0x8055
    ctx->r15 = S32(RELOC_HI16(357, 0X1998) << 16);
    // 0x80555080: sw          $t6, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r14;
    // 0x80555084: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x80555088: addiu       $t7, $t7, 0x6888
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(357, 0X1998));
    // 0x8055508C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x80555090: lui         $t9, 0x8055
    ctx->r25 = S32(RELOC_HI16(357, 0X10C) << 16);
    // 0x80555094: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x80555098: addiu       $t9, $t9, 0x4FFC
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(357, 0X10C));
    // 0x8055509C: lui         $t0, 0x8055
    ctx->r8 = S32(RELOC_HI16(357, 0X8D0) << 16);
    // 0x805550A0: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x805550A4: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805550A8: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x805550AC: addiu       $t0, $t0, 0x57C0
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(357, 0X8D0));
    // 0x805550B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805550B4: jal         0x80554F68
    // 0x805550B8: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    func_80554F68(rdram, ctx);
        goto after_4;
    // 0x805550B8: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    after_4:
    // 0x805550BC: lhu         $v0, 0xC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC);
    // 0x805550C0: addiu       $at, $zero, 0x41C8
    ctx->r1 = ADD32(0, 0X41C8);
    // 0x805550C4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x805550C8: beq         $v0, $at, L_805550E4
    if (ctx->r2 == ctx->r1) {
        // 0x805550CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805550E4;
    }
    // 0x805550CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805550D0: addiu       $at, $zero, 0x45DD
    ctx->r1 = ADD32(0, 0X45DD);
    // 0x805550D4: beq         $v0, $at, L_80555138
    if (ctx->r2 == ctx->r1) {
        // 0x805550D8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80555138;
    }
    // 0x805550D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805550DC: b           L_8055518C
    // 0x805550E0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
        goto L_8055518C;
    // 0x805550E0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_805550E4:
    // 0x805550E4: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805550E8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x805550EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805550F0: jal         0x80556700
    // 0x805550F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80556700(rdram, ctx);
        goto after_5;
    // 0x805550F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x805550F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x805550FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80555100: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80555104: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19D0) << 16);
    // 0x80555108: lwc1        $f12, 0x68C0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19D0));
    // 0x8055510C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80555110: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80555114: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    // 0x80555118: swc1        $f12, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f12.u32l;
    // 0x8055511C: swc1        $f12, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f12.u32l;
    // 0x80555120: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80555124: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80555128: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8055512C: swc1        $f2, 0x550($v1)
    MEM_W(0X550, ctx->r3) = ctx->f2.u32l;
    // 0x80555130: b           L_80555188
    // 0x80555134: sw          $t2, 0x554($v1)
    MEM_W(0X554, ctx->r3) = ctx->r10;
        goto L_80555188;
    // 0x80555134: sw          $t2, 0x554($v1)
    MEM_W(0X554, ctx->r3) = ctx->r10;
L_80555138:
    // 0x80555138: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8055513C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80555140: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80555144: jal         0x80556700
    // 0x80555148: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80556700(rdram, ctx);
        goto after_6;
    // 0x80555148: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_6:
    // 0x8055514C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80555150: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80555154: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80555158: lui         $at, 0x8055
    ctx->r1 = S32(RELOC_HI16(357, 0X19D4) << 16);
    // 0x8055515C: lwc1        $f12, 0x68C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(357, 0X19D4));
    // 0x80555160: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80555164: swc1        $f2, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f2.u32l;
    // 0x80555168: swc1        $f12, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f12.u32l;
    // 0x8055516C: swc1        $f12, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f12.u32l;
    // 0x80555170: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x80555174: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80555178: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x8055517C: addiu       $t3, $zero, 0x3B
    ctx->r11 = ADD32(0, 0X3B);
    // 0x80555180: swc1        $f2, 0x550($v1)
    MEM_W(0X550, ctx->r3) = ctx->f2.u32l;
    // 0x80555184: sw          $t3, 0x554($v1)
    MEM_W(0X554, ctx->r3) = ctx->r11;
L_80555188:
    // 0x80555188: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
L_8055518C:
    // 0x8055518C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80555190: jal         0x80067BBC
    // 0x80555194: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80067BBC(rdram, ctx);
        goto after_7;
    // 0x80555194: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x80555198: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8055519C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x805551A0: jal         0x80067F78
    // 0x805551A4: lw          $a0, 0x554($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X554);
    func_80067F78(rdram, ctx);
        goto after_8;
    // 0x805551A4: lw          $a0, 0x554($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X554);
    after_8:
    // 0x805551A8: b           L_805551B8
    // 0x805551AC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_805551B8;
    // 0x805551AC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_805551B0:
    // 0x805551B0: jal         0x800445A4
    // 0x805551B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_9;
    // 0x805551B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
L_805551B8:
    // 0x805551B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805551BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805551C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805551C4: jr          $ra
    // 0x805551C8: nop

    return;
    // 0x805551C8: nop

;}
RECOMP_FUNC void func_8000A25C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A25C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000A260: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000A264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A268: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8000A26C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8000A270: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8000A274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A278: addiu       $a0, $t6, -0x635C
    ctx->r4 = ADD32(ctx->r14, -0X635C);
    // 0x8000A27C: addiu       $t7, $t7, -0x6344
    ctx->r15 = ADD32(ctx->r15, -0X6344);
    // 0x8000A280: addiu       $t8, $t8, -0x632C
    ctx->r24 = ADD32(ctx->r24, -0X632C);
    // 0x8000A284: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000A288: sb          $zero, 0x4F7C($v0)
    MEM_B(0X4F7C, ctx->r2) = 0;
    // 0x8000A28C: sb          $zero, 0x4F7D($v0)
    MEM_B(0X4F7D, ctx->r2) = 0;
    // 0x8000A290: sb          $zero, 0x4F7E($v0)
    MEM_B(0X4F7E, ctx->r2) = 0;
    // 0x8000A294: sw          $a0, 0x4F8C($v0)
    MEM_W(0X4F8C, ctx->r2) = ctx->r4;
    // 0x8000A298: sw          $t7, 0x4F90($v0)
    MEM_W(0X4F90, ctx->r2) = ctx->r15;
    // 0x8000A29C: sw          $t8, 0x4F88($v0)
    MEM_W(0X4F88, ctx->r2) = ctx->r24;
    // 0x8000A2A0: addiu       $a1, $a1, -0x6314
    ctx->r5 = ADD32(ctx->r5, -0X6314);
    // 0x8000A2A4: jal         0x8008AE20
    // 0x8000A2A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000A2A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8000A2AC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000A2B0: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000A2B4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000A2B8: addiu       $a1, $a1, -0x630C
    ctx->r5 = ADD32(ctx->r5, -0X630C);
    // 0x8000A2BC: lw          $a0, 0x4F90($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4F90);
    // 0x8000A2C0: jal         0x8008AE20
    // 0x8000A2C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x8000A2C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8000A2C8: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8000A2CC: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x8000A2D0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8000A2D4: addiu       $a1, $a1, -0x6310
    ctx->r5 = ADD32(ctx->r5, -0X6310);
    // 0x8000A2D8: lw          $a0, 0x4F88($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4F88);
    // 0x8000A2DC: jal         0x8008AE20
    // 0x8000A2E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x8000A2E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8000A2E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A2E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A2EC: jr          $ra
    // 0x8000A2F0: nop

    return;
    // 0x8000A2F0: nop

;}
RECOMP_FUNC void func_806E73F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E73F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E73FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7400: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806E7404: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806E7408: lui         $t7, 0x806F
    ctx->r15 = S32(RELOC_HI16(664, 0XEA0) << 16);
    // 0x806E740C: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806E7410: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E7414: addiu       $t7, $t7, -0x7F20
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(664, 0XEA0));
    // 0x806E7418: lui         $a1, 0x806F
    ctx->r5 = S32(RELOC_HI16(664, 0XEA4) << 16);
    // 0x806E741C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806E7420: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806E7424: jal         0x806E8030
    // 0x806E7428: addiu       $a1, $a1, -0x7F1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(664, 0XEA4));
    func_806E8030(rdram, ctx);
        goto after_0;
    // 0x806E7428: addiu       $a1, $a1, -0x7F1C
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(664, 0XEA4));
    after_0:
    // 0x806E742C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806E7430: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x806E7434: beq         $v0, $zero, L_806E744C
    if (ctx->r2 == 0) {
        // 0x806E7438: sb          $v1, 0x165($a0)
        MEM_B(0X165, ctx->r4) = ctx->r3;
            goto L_806E744C;
    }
    // 0x806E7438: sb          $v1, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r3;
    // 0x806E743C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x806E7440: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
    // 0x806E7444: sb          $v1, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r3;
    // 0x806E7448: sb          $v1, 0x165($v0)
    MEM_B(0X165, ctx->r2) = ctx->r3;
L_806E744C:
    // 0x806E744C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E7450: jal         0x806E7E4C
    // 0x806E7454: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    func_806E7E4C(rdram, ctx);
        goto after_1;
    // 0x806E7454: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x806E7458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E745C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7460: jr          $ra
    // 0x806E7464: nop

    return;
    // 0x806E7464: nop

;}
RECOMP_FUNC void func_80447244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447244: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447248: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8044724C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80447250: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80447254: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80447258: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x8044725C: lui         $t0, 0x8045
    ctx->r8 = S32(RELOC_HI16(98, 0X132F4) << 16);
    // 0x80447260: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80447264: lw          $v1, 0x6C9C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6C9C);
    // 0x80447268: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x8044726C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80447270: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80447274: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x80447278: lw          $t0, 0x76D4($t0)
    ctx->r8 = MEM_W(ctx->r8, (int16_t)RELOC_LO16(98, 0X132F4));
    // 0x8044727C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80447280: beql        $t0, $zero, L_80447294
    if (ctx->r8 == 0) {
        // 0x80447284: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80447294;
    }
    goto skip_0;
    // 0x80447284: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80447288: jalr        $t0
    // 0x8044728C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    LOOKUP_FUNC(ctx->r8)(rdram, ctx);
        goto after_0;
    // 0x8044728C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80447290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80447294:
    // 0x80447294: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80447298: jr          $ra
    // 0x8044729C: nop

    return;
    // 0x8044729C: nop

;}
RECOMP_FUNC void func_800382B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800382B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800382B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800382BC: jal         0x80021958
    // 0x800382C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80021958(rdram, ctx);
        goto after_0;
    // 0x800382C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800382C4: bne         $v0, $zero, L_800382D4
    if (ctx->r2 != 0) {
        // 0x800382C8: nop
    
            goto L_800382D4;
    }
    // 0x800382C8: nop

    // 0x800382CC: b           L_80038308
    // 0x800382D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038308;
    // 0x800382D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800382D4:
    // 0x800382D4: jal         0x800415FC
    // 0x800382D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800415FC(rdram, ctx);
        goto after_1;
    // 0x800382D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800382DC: beq         $v0, $zero, L_800382EC
    if (ctx->r2 == 0) {
        // 0x800382E0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_800382EC;
    }
    // 0x800382E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800382E4: b           L_80038308
    // 0x800382E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038308;
    // 0x800382E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800382EC:
    // 0x800382EC: jal         0x8003776C
    // 0x800382F0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    func_8003776C(rdram, ctx);
        goto after_2;
    // 0x800382F0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_2:
    // 0x800382F4: bnel        $v0, $zero, L_80038308
    if (ctx->r2 != 0) {
        // 0x800382F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80038308;
    }
    goto skip_0;
    // 0x800382F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x800382FC: b           L_80038308
    // 0x80038300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80038308;
    // 0x80038300: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038304: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80038308:
    // 0x80038308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003830C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038310: jr          $ra
    // 0x80038314: nop

    return;
    // 0x80038314: nop

;}
RECOMP_FUNC void func_805C6C20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C6C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805C6C24: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x805C6C28: beq         $at, $zero, L_805C6C38
    if (ctx->r1 == 0) {
        // 0x805C6C2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_805C6C38;
    }
    // 0x805C6C2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805C6C30: b           L_805C6C94
    // 0x805C6C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_805C6C94;
    // 0x805C6C34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805C6C38:
    // 0x805C6C38: bnel        $a0, $a1, L_805C6C4C
    if (ctx->r4 != ctx->r5) {
        // 0x805C6C3C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_805C6C4C;
    }
    goto skip_0;
    // 0x805C6C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    skip_0:
    // 0x805C6C40: b           L_805C6C94
    // 0x805C6C44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_805C6C94;
    // 0x805C6C44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x805C6C48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
L_805C6C4C:
    // 0x805C6C4C: jal         0x800653D8
    // 0x805C6C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800653D8(rdram, ctx);
        goto after_0;
    // 0x805C6C50: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x805C6C54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805C6C58: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x805C6C5C: subu        $t6, $a1, $a0
    ctx->r14 = SUB32(ctx->r5, ctx->r4);
    // 0x805C6C60: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x805C6C64: div         $zero, $v0, $t7
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r15)));
    // 0x805C6C68: mfhi        $t8
    ctx->r24 = hi;
    // 0x805C6C6C: bne         $t7, $zero, L_805C6C78
    if (ctx->r15 != 0) {
        // 0x805C6C70: nop
    
            goto L_805C6C78;
    }
    // 0x805C6C70: nop

    // 0x805C6C74: break       7
    do_break(2153540724);
L_805C6C78:
    // 0x805C6C78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x805C6C7C: bne         $t7, $at, L_805C6C90
    if (ctx->r15 != ctx->r1) {
        // 0x805C6C80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_805C6C90;
    }
    // 0x805C6C80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x805C6C84: bne         $v0, $at, L_805C6C90
    if (ctx->r2 != ctx->r1) {
        // 0x805C6C88: nop
    
            goto L_805C6C90;
    }
    // 0x805C6C88: nop

    // 0x805C6C8C: break       6
    do_break(2153540748);
L_805C6C90:
    // 0x805C6C90: addu        $v0, $t8, $a0
    ctx->r2 = ADD32(ctx->r24, ctx->r4);
L_805C6C94:
    // 0x805C6C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805C6C98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805C6C9C: jr          $ra
    // 0x805C6CA0: nop

    return;
    // 0x805C6CA0: nop

;}
RECOMP_FUNC void func_8045BBF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045BBF4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8045BBF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8045BBFC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8045BC00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8045BC04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8045BC08: jal         0x80045A34
    // 0x8045BC0C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8045BC0C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    after_0:
    // 0x8045BC10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8045BC14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8045BC18: bne         $v0, $zero, L_8045BC28
    if (ctx->r2 != 0) {
        // 0x8045BC1C: sw          $v0, 0x1F4($t6)
        MEM_W(0X1F4, ctx->r14) = ctx->r2;
            goto L_8045BC28;
    }
    // 0x8045BC1C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8045BC20: b           L_8045BCB0
    // 0x8045BC24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8045BCB0;
    // 0x8045BC24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8045BC28:
    // 0x8045BC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045BC2C: addiu       $a1, $zero, 0x54
    ctx->r5 = ADD32(0, 0X54);
    // 0x8045BC30: jal         0x80065728
    // 0x8045BC34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80065728(rdram, ctx);
        goto after_1;
    // 0x8045BC34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8045BC38: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8045BC3C: jal         0x80064D1C
    // 0x8045BC40: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    func_80064D1C(rdram, ctx);
        goto after_2;
    // 0x8045BC40: sll         $a0, $a0, 4
    ctx->r4 = S32(ctx->r4 << 4);
    after_2:
    // 0x8045BC44: bne         $v0, $zero, L_8045BC54
    if (ctx->r2 != 0) {
        // 0x8045BC48: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_8045BC54;
    }
    // 0x8045BC48: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8045BC4C: b           L_8045BCB0
    // 0x8045BC50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8045BCB0;
    // 0x8045BC50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8045BC54:
    // 0x8045BC54: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8045BC58: srl         $v1, $v1, 1
    ctx->r3 = S32(U32(ctx->r3) >> 1);
    // 0x8045BC5C: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x8045BC60: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8045BC64: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8045BC68: jal         0x80064D1C
    // 0x8045BC6C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    func_80064D1C(rdram, ctx);
        goto after_3;
    // 0x8045BC6C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_3:
    // 0x8045BC70: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8045BC74: bne         $v0, $zero, L_8045BC84
    if (ctx->r2 != 0) {
        // 0x8045BC78: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_8045BC84;
    }
    // 0x8045BC78: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8045BC7C: b           L_8045BCB0
    // 0x8045BC80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8045BCB0;
    // 0x8045BC80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8045BC84:
    // 0x8045BC84: jal         0x80064D1C
    // 0x8045BC88: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    func_80064D1C(rdram, ctx);
        goto after_4;
    // 0x8045BC88: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    after_4:
    // 0x8045BC8C: bne         $v0, $zero, L_8045BC9C
    if (ctx->r2 != 0) {
        // 0x8045BC90: sw          $v0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r2;
            goto L_8045BC9C;
    }
    // 0x8045BC90: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x8045BC94: b           L_8045BCB0
    // 0x8045BC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8045BCB0;
    // 0x8045BC98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8045BC9C:
    // 0x8045BC9C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8045BCA0: lui         $t7, 0x8046
    ctx->r15 = S32(RELOC_HI16(107, 0X328) << 16);
    // 0x8045BCA4: addiu       $t7, $t7, -0x4448
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(107, 0X328));
    // 0x8045BCA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8045BCAC: sw          $t7, 0x1F8($t8)
    MEM_W(0X1F8, ctx->r24) = ctx->r15;
L_8045BCB0:
    // 0x8045BCB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8045BCB4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045BCB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8045BCBC: jr          $ra
    // 0x8045BCC0: nop

    return;
    // 0x8045BCC0: nop

;}
RECOMP_FUNC void func_80515DD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80515DD4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80515DD8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80515DDC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80515DE0: lui         $t7, 0x8051
    ctx->r15 = S32(RELOC_HI16(276, 0XE14) << 16);
    // 0x80515DE4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80515DE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80515DEC: lw          $t7, 0x62B4($t7)
    ctx->r15 = MEM_W(ctx->r15, (int16_t)RELOC_LO16(276, 0XE14));
    // 0x80515DF0: jr          $ra
    // 0x80515DF4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    return;
    // 0x80515DF4: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void func_80055D6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055D6C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80055D70: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x80055D74: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x80055D78: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80055D7C: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x80055D80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80055D84: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80055D88: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80055D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80055D90: blez        $t0, L_80055DFC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80055D94: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80055DFC;
    }
    // 0x80055D94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80055D98: lh          $a3, 0x0($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X0);
L_80055D9C:
    // 0x80055D9C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80055DA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80055DA4: blez        $a3, L_80055DDC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80055DA8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80055DDC;
    }
    // 0x80055DA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80055DAC:
    // 0x80055DAC: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x80055DB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80055DB4: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80055DB8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80055DBC: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80055DC0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x80055DC4: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80055DC8: beq         $t1, $zero, L_80055DD4
    if (ctx->r9 == 0) {
        // 0x80055DCC: nop
    
            goto L_80055DD4;
    }
    // 0x80055DCC: nop

    // 0x80055DD0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80055DD4:
    // 0x80055DD4: bne         $at, $zero, L_80055DAC
    if (ctx->r1 != 0) {
        // 0x80055DD8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80055DAC;
    }
    // 0x80055DD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80055DDC:
    // 0x80055DDC: beq         $a0, $zero, L_80055DF0
    if (ctx->r4 == 0) {
        // 0x80055DE0: addu        $t2, $s2, $v0
        ctx->r10 = ADD32(ctx->r18, ctx->r2);
            goto L_80055DF0;
    }
    // 0x80055DE0: addu        $t2, $s2, $v0
    ctx->r10 = ADD32(ctx->r18, ctx->r2);
    // 0x80055DE4: sb          $a0, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r4;
    // 0x80055DE8: lh          $t0, 0x2($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X2);
    // 0x80055DEC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80055DF0:
    // 0x80055DF0: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80055DF4: bnel        $at, $zero, L_80055D9C
    if (ctx->r1 != 0) {
        // 0x80055DF8: lh          $a3, 0x0($a2)
        ctx->r7 = MEM_H(ctx->r6, 0X0);
            goto L_80055D9C;
    }
    goto skip_0;
    // 0x80055DF8: lh          $a3, 0x0($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X0);
    skip_0:
L_80055DFC:
    // 0x80055DFC: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80055E00: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x80055E04: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x80055E08: jr          $ra
    // 0x80055E0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80055E0C: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void func_80021584(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021584: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021588: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002158C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80021590: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80021594: lbu         $t6, 0x18($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X18);
    // 0x80021598: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002159C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800215A0: bne         $t6, $at, L_800215E0
    if (ctx->r14 != ctx->r1) {
        // 0x800215A4: nop
    
            goto L_800215E0;
    }
    // 0x800215A4: nop

    // 0x800215A8: lbu         $t7, 0x30($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X30);
    // 0x800215AC: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x800215B0: bne         $t7, $at, L_800215E0
    if (ctx->r15 != ctx->r1) {
        // 0x800215B4: nop
    
            goto L_800215E0;
    }
    // 0x800215B4: nop

    // 0x800215B8: lwc1        $f4, 0x84($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800215BC: lwc1        $f6, 0xA8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XA8);
    // 0x800215C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800215C4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800215C8: nop

    // 0x800215CC: bc1f        L_8002161C
    if (!c1cs) {
        // 0x800215D0: nop
    
            goto L_8002161C;
    }
    // 0x800215D0: nop

    // 0x800215D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800215D8: b           L_8002161C
    // 0x800215DC: nop

        goto L_8002161C;
    // 0x800215DC: nop

L_800215E0:
    // 0x800215E0: jal         0x80066E88
    // 0x800215E4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x800215E4: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    after_0:
    // 0x800215E8: lwc1        $f8, 0xC4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800215EC: lwc1        $f10, 0x100($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X100);
    // 0x800215F0: lwc1        $f4, 0x10C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x800215F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800215F8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800215FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80021600: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80021604: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80021608: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8002160C: nop

    // 0x80021610: bc1f        L_8002161C
    if (!c1cs) {
        // 0x80021614: nop
    
            goto L_8002161C;
    }
    // 0x80021614: nop

    // 0x80021618: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002161C:
    // 0x8002161C: beq         $v0, $zero, L_80021670
    if (ctx->r2 == 0) {
        // 0x80021620: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80021670;
    }
    // 0x80021620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021624: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021628: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x8002162C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021634: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80021638: jal         0x8004D23C
    // 0x8002163C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_1;
    // 0x8002163C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80021640: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021644: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80021648: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002164C: jal         0x8004D23C
    // 0x80021650: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_2;
    // 0x80021650: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80021654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80021658: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8002165C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021660: jal         0x8004D23C
    // 0x80021664: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    func_8004D23C(rdram, ctx);
        goto after_3;
    // 0x80021664: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x80021668: b           L_800216B4
    // 0x8002166C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800216B4;
    // 0x8002166C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80021670:
    // 0x80021670: lui         $s1, 0x8005
    ctx->r17 = S32(0X8005 << 16);
    // 0x80021674: addiu       $s1, $s1, -0x2F38
    ctx->r17 = ADD32(ctx->r17, -0X2F38);
    // 0x80021678: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8002167C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x80021680: jal         0x8004D23C
    // 0x80021684: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_4;
    // 0x80021684: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x80021688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002168C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80021690: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80021694: jal         0x8004D23C
    // 0x80021698: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_5;
    // 0x80021698: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x8002169C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800216A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800216A4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800216A8: jal         0x8004D23C
    // 0x800216AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D23C(rdram, ctx);
        goto after_6;
    // 0x800216AC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_6:
    // 0x800216B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800216B4:
    // 0x800216B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800216B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800216BC: jr          $ra
    // 0x800216C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800216C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8069D5B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8069D5B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8069D5B4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8069D5B8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8069D5BC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8069D5C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8069D5C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8069D5C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8069D5CC: jal         0x8069D784
    // 0x8069D5D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_8069D784(rdram, ctx);
        goto after_0;
    // 0x8069D5D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8069D5D4: beq         $v0, $zero, L_8069D75C
    if (ctx->r2 == 0) {
        // 0x8069D5D8: nop
    
            goto L_8069D75C;
    }
    // 0x8069D5D8: nop

    // 0x8069D5DC: jal         0x8069D7BC
    // 0x8069D5E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_8069D7BC(rdram, ctx);
        goto after_1;
    // 0x8069D5E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x8069D5E4: lw          $t9, 0x16C($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X16C);
    // 0x8069D5E8: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x8069D5EC: addiu       $t6, $t6, -0x7C48
    ctx->r14 = ADD32(ctx->r14, -0X7C48);
    // 0x8069D5F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8069D5F4: lui         $t8, 0x806A
    ctx->r24 = S32(RELOC_HI16(574, 0XD30) << 16);
    // 0x8069D5F8: sw          $t6, 0x130($s4)
    MEM_W(0X130, ctx->r20) = ctx->r14;
    // 0x8069D5FC: sb          $t7, 0x165($s4)
    MEM_B(0X165, ctx->r20) = ctx->r15;
    // 0x8069D600: addiu       $t8, $t8, -0x1D50
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(574, 0XD30));
    // 0x8069D604: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8069D608: sw          $zero, 0x1E0($s4)
    MEM_W(0X1E0, ctx->r20) = 0;
    // 0x8069D60C: sw          $zero, 0x138($s4)
    MEM_W(0X138, ctx->r20) = 0;
    // 0x8069D610: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8069D614: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8069D618: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8069D61C: jal         0x8069DBF8
    // 0x8069D620: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8069DBF8(rdram, ctx);
        goto after_2;
    // 0x8069D620: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8069D624: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8069D628: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(574, 0XD70) << 16);
    // 0x8069D62C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8069D630: swc1        $f0, 0xC8($s4)
    MEM_W(0XC8, ctx->r20) = ctx->f0.u32l;
    // 0x8069D634: lwc1        $f4, -0x1D10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(574, 0XD70));
    // 0x8069D638: lui         $at, 0x806A
    ctx->r1 = S32(RELOC_HI16(574, 0XD74) << 16);
    // 0x8069D63C: swc1        $f4, 0xE0($s4)
    MEM_W(0XE0, ctx->r20) = ctx->f4.u32l;
    // 0x8069D640: lwc1        $f6, -0x1D0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(574, 0XD74));
    // 0x8069D644: jal         0x8069D590
    // 0x8069D648: swc1        $f6, 0xEC($s4)
    MEM_W(0XEC, ctx->r20) = ctx->f6.u32l;
    func_8069D590(rdram, ctx);
        goto after_3;
    // 0x8069D648: swc1        $f6, 0xEC($s4)
    MEM_W(0XEC, ctx->r20) = ctx->f6.u32l;
    after_3:
    // 0x8069D64C: lw          $t0, 0x1F4($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1F4);
    // 0x8069D650: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8069D654: addiu       $at, $zero, 0x4580
    ctx->r1 = ADD32(0, 0X4580);
    // 0x8069D658: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8069D65C: lhu         $v0, 0xC($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0XC);
    // 0x8069D660: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8069D664: addiu       $a1, $zero, 0x457D
    ctx->r5 = ADD32(0, 0X457D);
    // 0x8069D668: beq         $v0, $at, L_8069D6C4
    if (ctx->r2 == ctx->r1) {
        // 0x8069D66C: addiu       $at, $zero, 0x4581
        ctx->r1 = ADD32(0, 0X4581);
            goto L_8069D6C4;
    }
    // 0x8069D66C: addiu       $at, $zero, 0x4581
    ctx->r1 = ADD32(0, 0X4581);
    // 0x8069D670: bne         $v0, $at, L_8069D6D4
    if (ctx->r2 != ctx->r1) {
        // 0x8069D674: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_8069D6D4;
    }
    // 0x8069D674: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8069D678: lui         $t3, 0x8010
    ctx->r11 = S32(0X8010 << 16);
    // 0x8069D67C: lw          $t3, -0x76F8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X76F8);
    // 0x8069D680: addiu       $t2, $zero, 0x4034
    ctx->r10 = ADD32(0, 0X4034);
    // 0x8069D684: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8069D688: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8069D68C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8069D690: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8069D694: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8069D698: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8069D69C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x8069D6A0: sh          $t2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r10;
    // 0x8069D6A4: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8069D6A8: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8069D6AC: lw          $t9, 0x54($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X54);
    // 0x8069D6B0: jalr        $t9
    // 0x8069D6B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x8069D6B4: nop

    after_4:
    // 0x8069D6B8: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8069D6BC: b           L_8069D6D4
    // 0x8069D6C0: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
        goto L_8069D6D4;
    // 0x8069D6C0: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
L_8069D6C4:
    // 0x8069D6C4: jal         0x8069DC34
    // 0x8069D6C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_8069DC34(rdram, ctx);
        goto after_5;
    // 0x8069D6C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x8069D6CC: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8069D6D0: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_8069D6D4:
    // 0x8069D6D4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8069D6D8: lui         $s1, 0x806A
    ctx->r17 = S32(RELOC_HI16(574, 0XD42) << 16);
    // 0x8069D6DC: lui         $s0, 0x806A
    ctx->r16 = S32(RELOC_HI16(574, 0XD4C) << 16);
    // 0x8069D6E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8069D6E4: addiu       $s0, $s0, -0x1D34
    ctx->r16 = ADD32(ctx->r16, (int16_t)RELOC_LO16(574, 0XD4C));
    // 0x8069D6E8: addiu       $s1, $s1, -0x1D3E
    ctx->r17 = ADD32(ctx->r17, (int16_t)RELOC_LO16(574, 0XD42));
    // 0x8069D6EC: bne         $t8, $zero, L_8069D704
    if (ctx->r24 != 0) {
        // 0x8069D6F0: lw          $s2, 0x60($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X60);
            goto L_8069D704;
    }
    // 0x8069D6F0: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8069D6F4: jal         0x800445A4
    // 0x8069D6F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_6;
    // 0x8069D6F8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x8069D6FC: b           L_8069D768
    // 0x8069D700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8069D768;
    // 0x8069D700: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8069D704:
    // 0x8069D704: lui         $s3, 0x806A
    ctx->r19 = S32(RELOC_HI16(574, 0XD54) << 16);
    // 0x8069D708: addiu       $s3, $s3, -0x1D2C
    ctx->r19 = ADD32(ctx->r19, (int16_t)RELOC_LO16(574, 0XD54));
    // 0x8069D70C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8069D710:
    // 0x8069D710: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8069D714: lhu         $a1, -0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, -0X2);
    // 0x8069D718: jal         0x8069DC34
    // 0x8069D71C: lw          $a2, -0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X4);
    func_8069DC34(rdram, ctx);
        goto after_7;
    // 0x8069D71C: lw          $a2, -0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X4);
    after_7:
    // 0x8069D720: bne         $v0, $zero, L_8069D738
    if (ctx->r2 != 0) {
        // 0x8069D724: sw          $v0, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r2;
            goto L_8069D738;
    }
    // 0x8069D724: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8069D728: jal         0x800445A4
    // 0x8069D72C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_8;
    // 0x8069D72C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x8069D730: b           L_8069D768
    // 0x8069D734: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8069D768;
    // 0x8069D734: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8069D738:
    // 0x8069D738: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8069D73C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8069D740: bne         $s0, $s3, L_8069D710
    if (ctx->r16 != ctx->r19) {
        // 0x8069D744: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8069D710;
    }
    // 0x8069D744: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8069D748: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8069D74C: jal         0x8069D988
    // 0x8069D750: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    func_8069D988(rdram, ctx);
        goto after_9;
    // 0x8069D750: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_9:
    // 0x8069D754: b           L_8069D768
    // 0x8069D758: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8069D768;
    // 0x8069D758: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8069D75C:
    // 0x8069D75C: jal         0x800445A4
    // 0x8069D760: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    func_800445A4(rdram, ctx);
        goto after_10;
    // 0x8069D760: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_10:
    // 0x8069D764: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8069D768:
    // 0x8069D768: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8069D76C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8069D770: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8069D774: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8069D778: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8069D77C: jr          $ra
    // 0x8069D780: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8069D780: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_805AAF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AAF60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805AAF64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AAF68: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AAF6C: beql        $v0, $zero, L_805AAF80
    if (ctx->r2 == 0) {
        // 0x805AAF70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AAF80;
    }
    goto skip_0;
    // 0x805AAF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AAF74: jal         0x800577D8
    // 0x805AAF78: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x805AAF78: lw          $a0, 0x268($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X268);
    after_0:
    // 0x805AAF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AAF80:
    // 0x805AAF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805AAF84: jr          $ra
    // 0x805AAF88: nop

    return;
    // 0x805AAF88: nop

;}
RECOMP_FUNC void func_806F5F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F5F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F5F4C: lw          $a2, 0xE0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XE0);
    // 0x806F5F50: lwc1        $f14, 0xEC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XEC);
    // 0x806F5F54: lwc1        $f12, 0xC8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x806F5F58: jal         0x80065ABC
    // 0x806F5F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80065ABC(rdram, ctx);
        goto after_0;
    // 0x806F5F5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806F5F60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806F5F64: lui         $at, 0x806F
    ctx->r1 = S32(RELOC_HI16(685, 0X11E4) << 16);
    // 0x806F5F68: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x806F5F6C: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x806F5F70: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x806F5F74: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806F5F78: lwc1        $f10, 0x6C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806F5F7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806F5F80: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x806F5F84: lwc1        $f16, 0x6544($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(685, 0X11E4));
    // 0x806F5F88: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x806F5F8C: swc1        $f18, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f18.u32l;
    // 0x806F5F90: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806F5F94: swc1        $f4, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f4.u32l;
    // 0x806F5F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F5F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F5FA0: jr          $ra
    // 0x806F5FA4: nop

    return;
    // 0x806F5FA4: nop

;}
RECOMP_FUNC void func_8057FCCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8057FCCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8057FCD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8057FCD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8057FCD8: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x8057FCDC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8057FCE0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8057FCE4: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x8057FCE8: beq         $v0, $zero, L_8057FD5C
    if (ctx->r2 == 0) {
        // 0x8057FCEC: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_8057FD5C;
    }
    // 0x8057FCEC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8057FCF0: lw          $v1, 0x180($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X180);
    // 0x8057FCF4: beql        $v1, $zero, L_8057FD60
    if (ctx->r3 == 0) {
        // 0x8057FCF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057FD60;
    }
    goto skip_0;
    // 0x8057FCF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8057FCFC: lw          $v0, 0x1F4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X1F4);
    // 0x8057FD00: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8057FD04: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8057FD08: lw          $a0, 0x6A28($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A28);
    // 0x8057FD0C: sh          $a2, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r6;
    // 0x8057FD10: jal         0x8057EF98
    // 0x8057FD14: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    func_8057EF98(rdram, ctx);
        goto after_0;
    // 0x8057FD14: sh          $a1, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r5;
    after_0:
    // 0x8057FD18: lh          $a1, 0x26($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X26);
    // 0x8057FD1C: bltz        $v0, L_8057FD5C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8057FD20: lh          $a2, 0x1E($sp)
        ctx->r6 = MEM_H(ctx->r29, 0X1E);
            goto L_8057FD5C;
    }
    // 0x8057FD20: lh          $a2, 0x1E($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X1E);
    // 0x8057FD24: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8057FD28: beq         $at, $zero, L_8057FD5C
    if (ctx->r1 == 0) {
        // 0x8057FD2C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8057FD5C;
    }
    // 0x8057FD2C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8057FD30: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x8057FD34: lw          $t0, -0x71A4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X71A4);
    // 0x8057FD38: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8057FD3C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8057FD40: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8057FD44: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8057FD48: bnel        $t1, $zero, L_8057FD60
    if (ctx->r9 != 0) {
        // 0x8057FD4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8057FD60;
    }
    goto skip_1;
    // 0x8057FD4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8057FD50: addiu       $a2, $a1, 0x4
    ctx->r6 = ADD32(ctx->r5, 0X4);
    // 0x8057FD54: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8057FD58: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
L_8057FD5C:
    // 0x8057FD5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8057FD60:
    // 0x8057FD60: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8057FD64: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8057FD68: jr          $ra
    // 0x8057FD6C: nop

    return;
    // 0x8057FD6C: nop

;}
RECOMP_FUNC void func_8045FAB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045FAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045FAB4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8045FAB8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8045FABC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8045FAC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045FAC4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8045FAC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8045FACC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8045FAD0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8045FAD4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8045FAD8: lui         $t2, 0x8046
    ctx->r10 = S32(RELOC_HI16(113, 0XAAC) << 16);
    // 0x8045FADC: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8045FAE0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8045FAE4: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8045FAE8: lw          $t2, -0x434($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(113, 0XAAC));
    // 0x8045FAEC: lui         $a1, 0x8046
    ctx->r5 = S32(RELOC_HI16(113, 0XA80) << 16);
    // 0x8045FAF0: addiu       $a1, $a1, -0x460
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(113, 0XA80));
    // 0x8045FAF4: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8045FAF8: jal         0x80048490
    // 0x8045FAFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8045FAFC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045FB00: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8045FB04: jal         0x80048378
    // 0x8045FB08: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8045FB08: addiu       $a0, $a3, 0xC4
    ctx->r4 = ADD32(ctx->r7, 0XC4);
    after_1:
    // 0x8045FB0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8045FB10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045FB14: jr          $ra
    // 0x8045FB18: nop

    return;
    // 0x8045FB18: nop

    // 0x8045FB1C: nop

;}
RECOMP_FUNC void func_80037C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037C2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037C30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037C34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037C3C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80037C40: jal         0x8006593C
    // 0x80037C44: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    func_8006593C(rdram, ctx);
        goto after_0;
    // 0x80037C44: lh          $a0, -0x7682($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X7682);
    after_0:
    // 0x80037C48: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80037C4C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80037C50: bne         $t7, $zero, L_80037CA0
    if (ctx->r15 != 0) {
        // 0x80037C54: lui         $a2, 0x8010
        ctx->r6 = S32(0X8010 << 16);
            goto L_80037CA0;
    }
    // 0x80037C54: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80037C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037C5C: jal         0x80040E24
    // 0x80037C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80040E24(rdram, ctx);
        goto after_1;
    // 0x80037C60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80037C64: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80037C68: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80037C6C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037C70: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80037C74: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x80037C78: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80037C7C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037C80: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80037C84: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80037C88: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80037C8C: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80037C90: jalr        $t9
    // 0x80037C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80037C94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80037C98: b           L_80037D74
    // 0x80037C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037D74;
    // 0x80037C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037CA0:
    // 0x80037CA0: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80037CA4: lw          $t0, 0x138($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X138);
    // 0x80037CA8: beql        $a2, $t0, L_80037D40
    if (ctx->r6 == ctx->r8) {
        // 0x80037CAC: lw          $t5, 0x1F4($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X1F4);
            goto L_80037D40;
    }
    goto skip_0;
    // 0x80037CAC: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
    skip_0:
    // 0x80037CB0: lw          $t1, 0x1F4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1F4);
    // 0x80037CB4: lw          $t2, 0x12EC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X12EC);
    // 0x80037CB8: bne         $t2, $zero, L_80037CFC
    if (ctx->r10 != 0) {
        // 0x80037CBC: nop
    
            goto L_80037CFC;
    }
    // 0x80037CBC: nop

    // 0x80037CC0: jal         0x80040FD4
    // 0x80037CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80040FD4(rdram, ctx);
        goto after_3;
    // 0x80037CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80037CC8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80037CCC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037CD0: addu        $t9, $t9, $t3
    ctx->r25 = ADD32(ctx->r25, ctx->r11);
    // 0x80037CD4: lw          $t9, -0x1028($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1028);
    // 0x80037CD8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037CDC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80037CE0: lui         $a2, 0x8010
    ctx->r6 = S32(0X8010 << 16);
    // 0x80037CE4: lbu         $a2, -0x7684($a2)
    ctx->r6 = MEM_BU(ctx->r6, -0X7684);
    // 0x80037CE8: lbu         $a1, -0xFCC($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCC);
    // 0x80037CEC: jalr        $t9
    // 0x80037CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80037CF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80037CF4: b           L_80037D30
    // 0x80037CF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_80037D30;
    // 0x80037CF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80037CFC:
    // 0x80037CFC: jal         0x80040C9C
    // 0x80037D00: nop

    func_80040C9C(rdram, ctx);
        goto after_5;
    // 0x80037D00: nop

    after_5:
    // 0x80037D04: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80037D08: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037D0C: addu        $t9, $t9, $t4
    ctx->r25 = ADD32(ctx->r25, ctx->r12);
    // 0x80037D10: lw          $t9, -0xFFC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFFC);
    // 0x80037D14: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037D18: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80037D1C: lbu         $a1, -0xFC1($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFC1);
    // 0x80037D20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037D24: jalr        $t9
    // 0x80037D28: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80037D28: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x80037D2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80037D30:
    // 0x80037D30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80037D34: b           L_80037D74
    // 0x80037D38: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
        goto L_80037D74;
    // 0x80037D38: swc1        $f6, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f6.u32l;
    // 0x80037D3C: lw          $t5, 0x1F4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1F4);
L_80037D40:
    // 0x80037D40: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80037D44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80037D48: lw          $t6, 0x24($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X24);
    // 0x80037D4C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80037D50: bne         $t7, $zero, L_80037D74
    if (ctx->r15 != 0) {
        // 0x80037D54: nop
    
            goto L_80037D74;
    }
    // 0x80037D54: nop

    // 0x80037D58: lw          $t9, -0x1020($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1020);
    // 0x80037D5C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80037D60: lbu         $a1, -0xFCA($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0XFCA);
    // 0x80037D64: jalr        $t9
    // 0x80037D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80037D68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80037D6C: b           L_80037D74
    // 0x80037D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80037D74;
    // 0x80037D70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80037D74:
    // 0x80037D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037D78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037D7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80037D80: jr          $ra
    // 0x80037D84: nop

    return;
    // 0x80037D84: nop

;}
RECOMP_FUNC void func_807425E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807425E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807425EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807425F0: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x807425F4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x807425F8: addu        $t0, $v0, $at
    ctx->r8 = ADD32(ctx->r2, ctx->r1);
    // 0x807425FC: lw          $v1, 0x6E6C($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X6E6C);
    // 0x80742600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80742604: lw          $t1, 0x6E58($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X6E58);
    // 0x80742608: bne         $v1, $at, L_80742618
    if (ctx->r3 != ctx->r1) {
        // 0x8074260C: nop
    
            goto L_80742618;
    }
    // 0x8074260C: nop

    // 0x80742610: beq         $t1, $zero, L_80742628
    if (ctx->r9 == 0) {
        // 0x80742614: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80742628;
    }
    // 0x80742614: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80742618:
    // 0x80742618: jal         0x807424D8
    // 0x8074261C: nop

    func_807424D8(rdram, ctx);
        goto after_0;
    // 0x8074261C: nop

    after_0:
    // 0x80742620: b           L_80742688
    // 0x80742624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742688;
    // 0x80742624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742628:
    // 0x80742628: lwc1        $f12, 0x6BE0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X6BE0);
    // 0x8074262C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742630: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742634: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80742638: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8074263C: jal         0x80742354
    // 0x80742640: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80742354(rdram, ctx);
        goto after_1;
    // 0x80742640: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80742644: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80742648: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8074264C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742650: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80742654: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80742658: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x8074265C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80742660: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80742664: jal         0x807423AC
    // 0x80742668: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    func_807423AC(rdram, ctx);
        goto after_2;
    // 0x80742668: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    after_2:
    // 0x8074266C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80742670: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80742674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80742678: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8074267C: swc1        $f0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->f0.u32l;
    // 0x80742680: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80742684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742688:
    // 0x80742688: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8074268C: jr          $ra
    // 0x80742690: nop

    return;
    // 0x80742690: nop

;}
RECOMP_FUNC void func_8003B0D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B0D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B0D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B0D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003B0DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003B0E0: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8003B0E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B0E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8003B0EC: bne         $t6, $zero, L_8003B168
    if (ctx->r14 != 0) {
        // 0x8003B0F0: nop
    
            goto L_8003B168;
    }
    // 0x8003B0F0: nop

    // 0x8003B0F4: lwc1        $f12, 0x3C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8003B0F8: lwc1        $f14, 0x40($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8003B0FC: jal         0x8003BA24
    // 0x8003B100: lw          $a2, 0x44($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X44);
    func_8003BA24(rdram, ctx);
        goto after_0;
    // 0x8003B100: lw          $a2, 0x44($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X44);
    after_0:
    // 0x8003B104: bne         $v0, $zero, L_8003B11C
    if (ctx->r2 != 0) {
        // 0x8003B108: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003B11C;
    }
    // 0x8003B108: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003B10C: jal         0x8003B078
    // 0x8003B110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003B078(rdram, ctx);
        goto after_1;
    // 0x8003B110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003B114: b           L_8003B1AC
    // 0x8003B118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003B1AC;
    // 0x8003B118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B11C:
    // 0x8003B11C: addiu       $a0, $s1, 0x6C
    ctx->r4 = ADD32(ctx->r17, 0X6C);
    // 0x8003B120: jal         0x80065490
    // 0x8003B124: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003B124: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    after_2:
    // 0x8003B128: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x8003B12C: jal         0x80065490
    // 0x8003B130: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003B130: addiu       $a1, $s0, 0x78
    ctx->r5 = ADD32(ctx->r16, 0X78);
    after_3:
    // 0x8003B134: lui         $v0, 0x8005
    ctx->r2 = S32(0X8005 << 16);
    // 0x8003B138: addiu       $v0, $v0, -0x71D0
    ctx->r2 = ADD32(ctx->r2, -0X71D0);
    // 0x8003B13C: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8003B140: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8003B144: jal         0x8003B078
    // 0x8003B148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003B078(rdram, ctx);
        goto after_4;
    // 0x8003B148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003B14C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8003B150: jal         0x80052BA4
    // 0x8003B154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80052BA4(rdram, ctx);
        goto after_5;
    // 0x8003B154: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8003B158: jal         0x80044194
    // 0x8003B15C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80044194(rdram, ctx);
        goto after_6;
    // 0x8003B15C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x8003B160: b           L_8003B184
    // 0x8003B164: nop

        goto L_8003B184;
    // 0x8003B164: nop

L_8003B168:
    // 0x8003B168: jal         0x80052BA4
    // 0x8003B16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_7;
    // 0x8003B16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8003B170: jal         0x8005FDC4
    // 0x8003B174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_8;
    // 0x8003B174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003B178: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x8003B17C: addiu       $t7, $t7, -0x71D0
    ctx->r15 = ADD32(ctx->r15, -0X71D0);
    // 0x8003B180: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_8003B184:
    // 0x8003B184: jal         0x8003B004
    // 0x8003B188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003B004(rdram, ctx);
        goto after_9;
    // 0x8003B188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003B18C: jal         0x8003AE00
    // 0x8003B190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003AE00(rdram, ctx);
        goto after_10;
    // 0x8003B190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8003B194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B198: jal         0x8003B540
    // 0x8003B19C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003B540(rdram, ctx);
        goto after_11;
    // 0x8003B19C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x8003B1A0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8003B1A4: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x8003B1A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B1AC:
    // 0x8003B1AC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003B1B0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003B1B4: jr          $ra
    // 0x8003B1B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B1B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8079FD88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FD88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079FD8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079FD90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079FD94: lw          $s0, 0x174($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X174);
    // 0x8079FD98: jal         0x8079FBE4
    // 0x8079FD9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8079FBE4(rdram, ctx);
        goto after_0;
    // 0x8079FD9C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079FDA0: bne         $v0, $zero, L_8079FE20
    if (ctx->r2 != 0) {
        // 0x8079FDA4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8079FE20;
    }
    // 0x8079FDA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8079FDA8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8079FDAC: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    // 0x8079FDB0: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8079FDB4: lbu         $t8, 0x2C($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X2C);
    // 0x8079FDB8: beq         $t8, $zero, L_8079FE00
    if (ctx->r24 == 0) {
        // 0x8079FDBC: nop
    
            goto L_8079FE00;
    }
    // 0x8079FDBC: nop

    // 0x8079FDC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8079FDC4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8079FDC8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8079FDCC: nop

    // 0x8079FDD0: bc1f        L_8079FE00
    if (!c1cs) {
        // 0x8079FDD4: nop
    
            goto L_8079FE00;
    }
    // 0x8079FDD4: nop

    // 0x8079FDD8: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8079FDDC: lbu         $a2, 0x30($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0X30);
    // 0x8079FDE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079FDE4: lw          $a3, 0x68($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X68);
    // 0x8079FDE8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8079FDEC: jal         0x807A0380
    // 0x8079FDF0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    func_807A0380(rdram, ctx);
        goto after_1;
    // 0x8079FDF0: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_1:
    // 0x8079FDF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8079FDF8: b           L_8079FE20
    // 0x8079FDFC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
        goto L_8079FE20;
    // 0x8079FDFC: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8079FE00:
    // 0x8079FE00: jal         0x8079FB84
    // 0x8079FE04: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    func_8079FB84(rdram, ctx);
        goto after_2;
    // 0x8079FE04: addiu       $s0, $a0, 0xC4
    ctx->r16 = ADD32(ctx->r4, 0XC4);
    after_2:
    // 0x8079FE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079FE0C: jal         0x8079F730
    // 0x8079FE10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8079F730(rdram, ctx);
        goto after_3;
    // 0x8079FE10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8079FE14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079FE18: jal         0x8079F730
    // 0x8079FE1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8079F730(rdram, ctx);
        goto after_4;
    // 0x8079FE1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_8079FE20:
    // 0x8079FE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8079FE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079FE28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079FE2C: jr          $ra
    // 0x8079FE30: nop

    return;
    // 0x8079FE30: nop

;}
RECOMP_FUNC void func_8078B920(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078B924: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078B928: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078B92C: jal         0x80045A34
    // 0x8078B930: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078B930: addiu       $a1, $zero, 0xD0
    ctx->r5 = ADD32(0, 0XD0);
    after_0:
    // 0x8078B934: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8078B938: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x8078B93C: bne         $v0, $zero, L_8078B94C
    if (ctx->r2 != 0) {
        // 0x8078B940: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8078B94C;
    }
    // 0x8078B940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078B944: b           L_8078B950
    // 0x8078B948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078B950;
    // 0x8078B948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078B94C:
    // 0x8078B94C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078B950:
    // 0x8078B950: jr          $ra
    // 0x8078B954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8078B954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80475720(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475720: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475724: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475728: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047572C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475730: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475734: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475738: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047573C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475740: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475744: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475748: jr          $ra
    // 0x8047574C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047574C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8064C850(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C858: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C85C: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064C860: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8064C864: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064C868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C86C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C870: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064C874: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8064C878: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064C87C: nop

    // 0x8064C880: bc1fl       L_8064C894
    if (!c1cs) {
        // 0x8064C884: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C894;
    }
    goto skip_0;
    // 0x8064C884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C888: jal         0x8064CD50
    // 0x8064C88C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064CD50(rdram, ctx);
        goto after_0;
    // 0x8064C88C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C894:
    // 0x8064C894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C898: jr          $ra
    // 0x8064C89C: nop

    return;
    // 0x8064C89C: nop

;}
RECOMP_FUNC void func_80475420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475420: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475424: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475428: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047542C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475430: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475434: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475438: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047543C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475440: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475444: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475448: jr          $ra
    // 0x8047544C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047544C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_806F9018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F9018: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x806F901C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x806F9020: lui         $t7, 0x8070
    ctx->r15 = S32(RELOC_HI16(694, 0X1900) << 16);
    // 0x806F9024: sw          $t6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r14;
    // 0x806F9028: addiu       $t7, $t7, -0x6EF0
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(694, 0X1900));
    // 0x806F902C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x806F9030: lw          $t0, 0x16C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X16C);
    // 0x806F9034: lui         $t9, 0x806F
    ctx->r25 = S32(RELOC_HI16(694, 0X7A4) << 16);
    // 0x806F9038: addiu       $t9, $t9, 0x7FB4
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(694, 0X7A4));
    // 0x806F903C: sw          $t9, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r25;
    // 0x806F9040: lui         $t2, 0x8006
    ctx->r10 = S32(0X8006 << 16);
    // 0x806F9044: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F9048: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x806F904C: addiu       $t2, $t2, 0x5284
    ctx->r10 = ADD32(ctx->r10, 0X5284);
    // 0x806F9050: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806F9054: sb          $v0, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r2;
    // 0x806F9058: sb          $t1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r9;
    // 0x806F905C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x806F9060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F9064: jr          $ra
    // 0x806F9068: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
    return;
    // 0x806F9068: sb          $v0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r2;
;}
RECOMP_FUNC void func_80460BDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460BDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80460BE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80460BE4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80460BE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80460BEC: jal         0x8004700C
    // 0x80460BF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80460BF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80460BF4: beq         $v0, $zero, L_80460C6C
    if (ctx->r2 == 0) {
        // 0x80460BF8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80460C6C;
    }
    // 0x80460BF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80460BFC: jal         0x8046088C
    // 0x80460C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8046088C(rdram, ctx);
        goto after_1;
    // 0x80460C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80460C04: jal         0x80460908
    // 0x80460C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80460908(rdram, ctx);
        goto after_2;
    // 0x80460C08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80460C0C: jal         0x804609B4
    // 0x80460C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_804609B4(rdram, ctx);
        goto after_3;
    // 0x80460C10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80460C14: jal         0x80460ACC
    // 0x80460C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80460ACC(rdram, ctx);
        goto after_4;
    // 0x80460C18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80460C1C: jal         0x80460830
    // 0x80460C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80460830(rdram, ctx);
        goto after_5;
    // 0x80460C20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80460C24: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80460C28: beql        $s1, $t6, L_80460C70
    if (ctx->r17 == ctx->r14) {
        // 0x80460C2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80460C70;
    }
    goto skip_0;
    // 0x80460C2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80460C30: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80460C34: lwc1        $f6, 0xC4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x80460C38: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80460C3C: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x80460C40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80460C44: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80460C48: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80460C4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80460C50: jal         0x80460954
    // 0x80460C54: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    func_80460954(rdram, ctx);
        goto after_6;
    // 0x80460C54: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x80460C58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80460C5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80460C60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80460C64: jal         0x80460DB8
    // 0x80460C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80460DB8(rdram, ctx);
        goto after_7;
    // 0x80460C68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_80460C6C:
    // 0x80460C6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80460C70:
    // 0x80460C70: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80460C74: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80460C78: jr          $ra
    // 0x80460C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80460C7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8001F27C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F27C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001F280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001F284: lw          $a1, 0x1F4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001F288: lw          $v0, 0x2C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X2C);
    // 0x8001F28C: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x8001F290: beq         $t6, $zero, L_8001F2A8
    if (ctx->r14 == 0) {
        // 0x8001F294: andi        $t7, $v0, 0x700
        ctx->r15 = ctx->r2 & 0X700;
            goto L_8001F2A8;
    }
    // 0x8001F294: andi        $t7, $v0, 0x700
    ctx->r15 = ctx->r2 & 0X700;
    // 0x8001F298: jal         0x8001F050
    // 0x8001F29C: nop

    func_8001F050(rdram, ctx);
        goto after_0;
    // 0x8001F29C: nop

    after_0:
    // 0x8001F2A0: b           L_8001F2C8
    // 0x8001F2A4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8001F2C8;
    // 0x8001F2A4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8001F2A8:
    // 0x8001F2A8: beql        $t7, $zero, L_8001F2C4
    if (ctx->r15 == 0) {
        // 0x8001F2AC: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8001F2C4;
    }
    goto skip_0;
    // 0x8001F2AC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_0:
    // 0x8001F2B0: jal         0x8001F0DC
    // 0x8001F2B4: nop

    func_8001F0DC(rdram, ctx);
        goto after_1;
    // 0x8001F2B4: nop

    after_1:
    // 0x8001F2B8: b           L_8001F2C8
    // 0x8001F2BC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8001F2C8;
    // 0x8001F2BC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8001F2C0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8001F2C4:
    // 0x8001F2C4: nop

L_8001F2C8:
    // 0x8001F2C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001F2CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001F2D0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x8001F2D4: jr          $ra
    // 0x8001F2D8: nop

    return;
    // 0x8001F2D8: nop

;}
RECOMP_FUNC void func_80517C70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80517C70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80517C74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80517C78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80517C7C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80517C80: lui         $a2, 0x8052
    ctx->r6 = S32(RELOC_HI16(291, 0X2318) << 16);
    // 0x80517C84: addiu       $a2, $a2, -0x6078
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(291, 0X2318));
    // 0x80517C88: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x80517C8C: jal         0x80057B28
    // 0x80517C90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    func_80057B28(rdram, ctx);
        goto after_0;
    // 0x80517C90: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_0:
    // 0x80517C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80517C98: lui         $v0, 0x8052
    ctx->r2 = S32(RELOC_HI16(291, 0X2220) << 16);
    // 0x80517C9C: addiu       $v0, $v0, -0x6170
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(291, 0X2220));
    // 0x80517CA0: jr          $ra
    // 0x80517CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80517CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8078EFA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078EFA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8078EFA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8078EFAC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8078EFB0: jal         0x80045A34
    // 0x8078EFB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8078EFB4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_0:
    // 0x8078EFB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8078EFBC: bne         $v0, $zero, L_8078EFCC
    if (ctx->r2 != 0) {
        // 0x8078EFC0: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_8078EFCC;
    }
    // 0x8078EFC0: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x8078EFC4: b           L_8078EFD8
    // 0x8078EFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8078EFD8;
    // 0x8078EFC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8078EFCC:
    // 0x8078EFCC: jal         0x8078EF60
    // 0x8078EFD0: nop

    func_8078EF60(rdram, ctx);
        goto after_1;
    // 0x8078EFD0: nop

    after_1:
    // 0x8078EFD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8078EFD8:
    // 0x8078EFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8078EFDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8078EFE0: jr          $ra
    // 0x8078EFE4: nop

    return;
    // 0x8078EFE4: nop

;}
RECOMP_FUNC void func_805AC1F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC1F0: lui         $v0, 0x805B
    ctx->r2 = S32(RELOC_HI16(441, 0XC48) << 16);
    // 0x805AC1F4: addiu       $v0, $v0, -0x31C8
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(441, 0XC48));
    // 0x805AC1F8: jr          $ra
    // 0x805AC1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x805AC1FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80536A18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80536A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80536A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80536A20: jal         0x805368BC
    // 0x80536A24: nop

    func_805368BC(rdram, ctx);
        goto after_0;
    // 0x80536A24: nop

    after_0:
    // 0x80536A28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80536A2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80536A30: jr          $ra
    // 0x80536A34: nop

    return;
    // 0x80536A34: nop

;}
RECOMP_FUNC void func_804B7124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B7124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804B7128: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804B712C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804B7130: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x804B7134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804B7138: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x804B713C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x804B7140: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x804B7144: lui         $a1, 0x403A
    ctx->r5 = S32(0X403A << 16);
    // 0x804B7148: lui         $a0, 0x804B
    ctx->r4 = S32(RELOC_HI16(182, 0X13F0) << 16);
    // 0x804B714C: addiu       $a0, $a0, 0x7690
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(182, 0X13F0));
    // 0x804B7150: ori         $a1, $a1, 0x2800
    ctx->r5 = ctx->r5 | 0X2800;
    // 0x804B7154: jal         0x80046804
    // 0x804B7158: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x804B7158: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804B715C: bne         $v0, $zero, L_804B716C
    if (ctx->r2 != 0) {
        // 0x804B7160: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_804B716C;
    }
    // 0x804B7160: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x804B7164: b           L_804B71AC
    // 0x804B7168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804B71AC;
    // 0x804B7168: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804B716C:
    // 0x804B716C: jal         0x80047090
    // 0x804B7170: addiu       $a0, $zero, 0x403A
    ctx->r4 = ADD32(0, 0X403A);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x804B7170: addiu       $a0, $zero, 0x403A
    ctx->r4 = ADD32(0, 0X403A);
    after_1:
    // 0x804B7174: lhu         $t8, 0xE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XE);
    // 0x804B7178: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x804B717C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804B7180: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x804B7184: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x804B7188: jal         0x80044194
    // 0x804B718C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804B718C: sh          $t0, 0xE($s0)
    MEM_H(0XE, ctx->r16) = ctx->r8;
    after_2:
    // 0x804B7190: jal         0x80052BA4
    // 0x804B7194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80052BA4(rdram, ctx);
        goto after_3;
    // 0x804B7194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804B7198: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x804B719C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x804B71A0: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x804B71A4: sw          $t1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r9;
    // 0x804B71A8: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
L_804B71AC:
    // 0x804B71AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804B71B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x804B71B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804B71B8: jr          $ra
    // 0x804B71BC: nop

    return;
    // 0x804B71BC: nop

;}
RECOMP_FUNC void func_80038790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038790: jr          $ra
    // 0x80038794: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80038794: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8001BB04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BB04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001BB08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BB0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001BB10: beq         $a0, $zero, L_8001BC54
    if (ctx->r4 == 0) {
        // 0x8001BB14: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8001BC54;
    }
    // 0x8001BB14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001BB18: jal         0x8001BA50
    // 0x8001BB1C: nop

    func_8001BA50(rdram, ctx);
        goto after_0;
    // 0x8001BB1C: nop

    after_0:
    // 0x8001BB20: beql        $v0, $zero, L_8001BC58
    if (ctx->r2 == 0) {
        // 0x8001BB24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001BC58;
    }
    goto skip_0;
    // 0x8001BB24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001BB28: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8001BB2C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8001BB30: jal         0x8001BA90
    // 0x8001BB34: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    func_8001BA90(rdram, ctx);
        goto after_1;
    // 0x8001BB34: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_1:
    // 0x8001BB38: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001BB3C: ldc1        $f8, -0x4A0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X4A0);
    // 0x8001BB40: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8001BB44: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x8001BB48: nop

    // 0x8001BB4C: bc1fl       L_8001BB7C
    if (!c1cs) {
        // 0x8001BB50: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8001BB7C;
    }
    goto skip_1;
    // 0x8001BB50: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8001BB54: jal         0x8001BABC
    // 0x8001BB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001BABC(rdram, ctx);
        goto after_2;
    // 0x8001BB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8001BB5C: beq         $v0, $zero, L_8001BB78
    if (ctx->r2 == 0) {
        // 0x8001BB60: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001BB78;
    }
    // 0x8001BB60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001BB64: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001BB68: addiu       $t7, $s0, 0x20
    ctx->r15 = ADD32(ctx->r16, 0X20);
    // 0x8001BB6C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001BB70: jal         0x8001BD40
    // 0x8001BB74: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    func_8001BD40(rdram, ctx);
        goto after_3;
    // 0x8001BB74: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
    after_3:
L_8001BB78:
    // 0x8001BB78: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_8001BB7C:
    // 0x8001BB7C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001BB80: jal         0x8001BA90
    // 0x8001BB84: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_8001BA90(rdram, ctx);
        goto after_4;
    // 0x8001BB84: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_4:
    // 0x8001BB88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001BB8C: ldc1        $f4, -0x498($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X498);
    // 0x8001BB90: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001BB94: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8001BB98: nop

    // 0x8001BB9C: bc1fl       L_8001BBCC
    if (!c1cs) {
        // 0x8001BBA0: lwc1        $f8, 0x14($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
            goto L_8001BBCC;
    }
    goto skip_2;
    // 0x8001BBA0: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    skip_2:
    // 0x8001BBA4: jal         0x8001BABC
    // 0x8001BBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001BABC(rdram, ctx);
        goto after_5;
    // 0x8001BBA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8001BBAC: beq         $v0, $zero, L_8001BBC8
    if (ctx->r2 == 0) {
        // 0x8001BBB0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001BBC8;
    }
    // 0x8001BBB0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001BBB4: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8001BBB8: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x8001BBBC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8001BBC0: jal         0x8001BD40
    // 0x8001BBC4: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    func_8001BD40(rdram, ctx);
        goto after_6;
    // 0x8001BBC4: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    after_6:
L_8001BBC8:
    // 0x8001BBC8: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
L_8001BBCC:
    // 0x8001BBCC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8001BBD0: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8001BBD4: nop

    // 0x8001BBD8: bc1tl       L_8001BC08
    if (c1cs) {
        // 0x8001BBDC: lwc1        $f16, 0x30($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
            goto L_8001BC08;
    }
    goto skip_3;
    // 0x8001BBDC: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
    skip_3:
    // 0x8001BBE0: jal         0x8001BABC
    // 0x8001BBE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001BABC(rdram, ctx);
        goto after_7;
    // 0x8001BBE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8001BBE8: beq         $v0, $zero, L_8001BC04
    if (ctx->r2 == 0) {
        // 0x8001BBEC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001BC04;
    }
    // 0x8001BBEC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001BBF0: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x8001BBF4: addiu       $t1, $s0, 0x14
    ctx->r9 = ADD32(ctx->r16, 0X14);
    // 0x8001BBF8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8001BBFC: jal         0x8001BD40
    // 0x8001BC00: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    func_8001BD40(rdram, ctx);
        goto after_8;
    // 0x8001BC00: sw          $t1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r9;
    after_8:
L_8001BC04:
    // 0x8001BC04: lwc1        $f16, 0x30($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X30);
L_8001BC08:
    // 0x8001BC08: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001BC0C: jal         0x8001BA90
    // 0x8001BC10: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    func_8001BA90(rdram, ctx);
        goto after_9;
    // 0x8001BC10: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    after_9:
    // 0x8001BC14: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8001BC18: ldc1        $f4, -0x490($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X490);
    // 0x8001BC1C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001BC20: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8001BC24: nop

    // 0x8001BC28: bc1fl       L_8001BC58
    if (!c1cs) {
        // 0x8001BC2C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001BC58;
    }
    goto skip_4;
    // 0x8001BC2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8001BC30: jal         0x8001BABC
    // 0x8001BC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8001BABC(rdram, ctx);
        goto after_10;
    // 0x8001BC34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8001BC38: beq         $v0, $zero, L_8001BC54
    if (ctx->r2 == 0) {
        // 0x8001BC3C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8001BC54;
    }
    // 0x8001BC3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8001BC40: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001BC44: addiu       $t3, $s0, 0x2C
    ctx->r11 = ADD32(ctx->r16, 0X2C);
    // 0x8001BC48: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8001BC4C: jal         0x8001BD40
    // 0x8001BC50: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    func_8001BD40(rdram, ctx);
        goto after_11;
    // 0x8001BC50: sw          $t3, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r11;
    after_11:
L_8001BC54:
    // 0x8001BC54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001BC58:
    // 0x8001BC58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001BC5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001BC60: jr          $ra
    // 0x8001BC64: nop

    return;
    // 0x8001BC64: nop

;}
RECOMP_FUNC void func_8043AF28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043AF28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8043AF2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8043AF30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8043AF34: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8043AF38: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11D4) << 16);
    // 0x8043AF3C: lwc1        $f4, -0x47CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11D4));
    // 0x8043AF40: lwc1        $f0, 0x0($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8043AF44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8043AF48: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11D8) << 16);
    // 0x8043AF4C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8043AF50: nop

    // 0x8043AF54: bc1fl       L_8043AF70
    if (!c1cs) {
        // 0x8043AF58: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043AF70;
    }
    goto skip_0;
    // 0x8043AF58: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    skip_0:
    // 0x8043AF5C: lwc1        $f6, -0x47C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11D8));
    // 0x8043AF60: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8043AF64: nop

    // 0x8043AF68: bc1t        L_8043AFE4
    if (c1cs) {
        // 0x8043AF6C: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_8043AFE4;
    }
    // 0x8043AF6C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
L_8043AF70:
    // 0x8043AF70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8043AF74: lui         $at, 0x8044
    ctx->r1 = S32(RELOC_HI16(83, 0X11DC) << 16);
    // 0x8043AF78: lwc1        $f16, -0x47C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(83, 0X11DC));
    // 0x8043AF7C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8043AF80: jal         0x80065954
    // 0x8043AF84: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8043AF84: div.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    after_0:
    // 0x8043AF88: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8043AF8C: lh          $t8, 0x1F0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043AF90: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8043AF94: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8043AF98: bnel        $t8, $at, L_8043AFC4
    if (ctx->r24 != ctx->r1) {
        // 0x8043AF9C: lw          $a1, 0x34($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X34);
            goto L_8043AFC4;
    }
    goto skip_1;
    // 0x8043AF9C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    skip_1:
    // 0x8043AFA0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8043AFA4: jal         0x80067D5C
    // 0x8043AFA8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_1;
    // 0x8043AFA8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_1:
    // 0x8043AFAC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043AFB0: jal         0x80067F78
    // 0x8043AFB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_2;
    // 0x8043AFB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8043AFB8: b           L_8043AFEC
    // 0x8043AFBC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_8043AFEC;
    // 0x8043AFBC: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8043AFC0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
L_8043AFC4:
    // 0x8043AFC4: jal         0x80067D5C
    // 0x8043AFC8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067D5C(rdram, ctx);
        goto after_3;
    // 0x8043AFC8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x8043AFCC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8043AFD0: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x8043AFD4: jal         0x800678F0
    // 0x8043AFD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_4;
    // 0x8043AFD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_4:
    // 0x8043AFDC: b           L_8043AFF0
    // 0x8043AFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8043AFF0;
    // 0x8043AFE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043AFE4:
    // 0x8043AFE4: jal         0x8043A6B4
    // 0x8043AFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8043A6B4(rdram, ctx);
        goto after_5;
    // 0x8043AFE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8043AFEC:
    // 0x8043AFEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8043AFF0:
    // 0x8043AFF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8043AFF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8043AFF8: jr          $ra
    // 0x8043AFFC: nop

    return;
    // 0x8043AFFC: nop

;}
RECOMP_FUNC void func_8002301C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002301C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80023020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023024: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023028: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x8002302C: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80023030: jal         0x80023A2C
    // 0x80023034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80023A2C(rdram, ctx);
        goto after_0;
    // 0x80023034: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80023038: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8002303C: lwc1        $f4, -0x330($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X330);
    // 0x80023040: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80023044: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80023048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002304C: swc1        $f4, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f4.u32l;
    // 0x80023050: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x80023054: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80023058: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002305C: jr          $ra
    // 0x80023060: nop

    return;
    // 0x80023060: nop

;}
RECOMP_FUNC void func_8007FF9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FF9C: jr          $ra
    // 0x8007FFA0: nop

    return;
    // 0x8007FFA0: nop

;}
RECOMP_FUNC void func_8040DA98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040DA98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8040DA9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040DAA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8040DAA4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8040DAA8: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8040DAAC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8040DAB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8040DAB4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8040DAB8: lwc1        $f20, 0x50($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8040DABC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040DAC0: mul.s       $f12, $f20, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8040DAC4: jal         0x80066E88
    // 0x8040DAC8: nop

    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x8040DAC8: nop

    after_0:
    // 0x8040DACC: lui         $at, 0xC110
    ctx->r1 = S32(0XC110 << 16);
    // 0x8040DAD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040DAD4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8040DAD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DADC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8040DAE0: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x8040DAE4: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8040DAE8: nop

    // 0x8040DAEC: bc1fl       L_8040DB14
    if (!c1cs) {
        // 0x8040DAF0: swc1        $f20, 0x50($s0)
        MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
            goto L_8040DB14;
    }
    goto skip_0;
    // 0x8040DAF0: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x8040DAF4: jal         0x8005FDC4
    // 0x8040DAF8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    func_8005FDC4(rdram, ctx);
        goto after_1;
    // 0x8040DAF8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    after_1:
    // 0x8040DAFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040DB00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040DB04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8040DB08: jal         0x8040E254
    // 0x8040DB0C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040DB0C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x8040DB10: swc1        $f20, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f20.u32l;
L_8040DB14:
    // 0x8040DB14: jal         0x80066E88
    // 0x8040DB18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_80066E88(rdram, ctx);
        goto after_3;
    // 0x8040DB18: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8040DB1C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040DB20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8040DB24: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8040DB28: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8040DB2C: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8040DB30: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8040DB34: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8040DB38: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8040DB3C: jal         0x80066DE4
    // 0x8040DB40: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    func_80066DE4(rdram, ctx);
        goto after_4;
    // 0x8040DB40: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8040DB44: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8040DB48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8040DB4C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8040DB50: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8040DB54: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8040DB58: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8040DB5C: lwc1        $f16, 0x8($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X8);
    // 0x8040DB60: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8040DB64: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8040DB68: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8040DB6C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8040DB70: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    // 0x8040DB74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8040DB78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8040DB7C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8040DB80: jr          $ra
    // 0x8040DB84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8040DB84: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_806AEE00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806AEE00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806AEE04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806AEE08: jal         0x806AEBDC
    // 0x806AEE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AEBDC(rdram, ctx);
        goto after_0;
    // 0x806AEE0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806AEE10: bne         $v0, $zero, L_806AEE68
    if (ctx->r2 != 0) {
        // 0x806AEE14: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806AEE68;
    }
    // 0x806AEE14: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AEE18: jal         0x806AE458
    // 0x806AEE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806AE458(rdram, ctx);
        goto after_1;
    // 0x806AEE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x806AEE20: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806AEE24: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1FA0) << 16);
    // 0x806AEE28: lwc1        $f0, -0x320($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1FA0));
    // 0x806AEE2C: lwc1        $f4, 0x6C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806AEE30: lwc1        $f8, 0x70($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X70);
    // 0x806AEE34: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(595, 0X1FA4) << 16);
    // 0x806AEE38: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x806AEE3C: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x806AEE40: swc1        $f6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f6.u32l;
    // 0x806AEE44: lwc1        $f16, 0x6C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x806AEE48: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x806AEE4C: lwc1        $f18, -0x31C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(595, 0X1FA4));
    // 0x806AEE50: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806AEE54: nop

    // 0x806AEE58: bc1fl       L_806AEE6C
    if (!c1cs) {
        // 0x806AEE5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806AEE6C;
    }
    goto skip_0;
    // 0x806AEE5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806AEE60: jal         0x80048D4C
    // 0x806AEE64: nop

    func_80048D4C(rdram, ctx);
        goto after_2;
    // 0x806AEE64: nop

    after_2:
L_806AEE68:
    // 0x806AEE68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806AEE6C:
    // 0x806AEE6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806AEE70: jr          $ra
    // 0x806AEE74: nop

    return;
    // 0x806AEE74: nop

;}
RECOMP_FUNC void func_8005A36C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A36C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A370: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A374: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005A378: lbu         $v1, 0x58($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X58);
    // 0x8005A37C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005A380: beql        $at, $zero, L_8005A3C8
    if (ctx->r1 == 0) {
        // 0x8005A384: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A3C8;
    }
    goto skip_0;
    // 0x8005A384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005A388: lbu         $t7, 0x59($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X59);
    // 0x8005A38C: slt         $at, $a1, $t7
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005A390: beql        $at, $zero, L_8005A3C8
    if (ctx->r1 == 0) {
        // 0x8005A394: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A3C8;
    }
    goto skip_1;
    // 0x8005A394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8005A398: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005A39C: lw          $t8, 0x5C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5C);
    // 0x8005A3A0: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x8005A3A4: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8005A3A8: mflo        $t2
    ctx->r10 = lo;
    // 0x8005A3AC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8005A3B0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8005A3B4: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8005A3B8: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8005A3BC: jal         0x8005A2C0
    // 0x8005A3C0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    func_8005A2C0(rdram, ctx);
        goto after_0;
    // 0x8005A3C0: lh          $a1, 0x0($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X0);
    after_0:
    // 0x8005A3C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A3C8:
    // 0x8005A3C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A3CC: jr          $ra
    // 0x8005A3D0: nop

    return;
    // 0x8005A3D0: nop

;}
RECOMP_FUNC void func_806819DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806819DC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806819E0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806819E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806819E8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806819EC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806819F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806819F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806819F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806819FC: lui         $t1, 0x8068
    ctx->r9 = S32(RELOC_HI16(550, 0X2204) << 16);
    // 0x80681A00: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80681A04: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80681A08: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80681A0C: lw          $t1, 0x2614($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(550, 0X2204));
    // 0x80681A10: jr          $ra
    // 0x80681A14: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80681A14: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_804B6FF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B6FF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B6FF4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x804B6FF8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x804B6FFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B7000: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x804B7004: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x804B7008: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x804B700C: lui         $t9, 0x804B
    ctx->r25 = S32(RELOC_HI16(182, 0XF34) << 16);
    // 0x804B7010: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804B7014: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x804B7018: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x804B701C: lw          $t9, 0x71D4($t9)
    ctx->r25 = MEM_W(ctx->r25, (int16_t)RELOC_LO16(182, 0XF34));
    // 0x804B7020: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x804B7024: sw          $t9, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r25;
    // 0x804B7028: jal         0x804B7048
    // 0x804B702C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804B7048(rdram, ctx);
        goto after_0;
    // 0x804B702C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B7030: jal         0x804B70C0
    // 0x804B7034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804B70C0(rdram, ctx);
        goto after_1;
    // 0x804B7034: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804B7038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804B703C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B7040: jr          $ra
    // 0x804B7044: nop

    return;
    // 0x804B7044: nop

;}
RECOMP_FUNC void func_804C91F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C91F8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804C91FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804C9200: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x804C9204: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804C9208: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804C920C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804C9210: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804C9214: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804C9218: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804C921C: lui         $t1, 0x804D
    ctx->r9 = S32(RELOC_HI16(225, 0X910) << 16);
    // 0x804C9220: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804C9224: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804C9228: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804C922C: lw          $t1, -0x6DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(225, 0X910));
    // 0x804C9230: jr          $ra
    // 0x804C9234: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804C9234: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x804C9238: nop

    // 0x804C923C: nop

;}
RECOMP_FUNC void func_80526DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80526DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80526DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80526DF0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80526DF4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80526DF8: lw          $a1, 0x38($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X38);
    // 0x80526DFC: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x80526E00: jal         0x80067BBC
    // 0x80526E04: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_80067BBC(rdram, ctx);
        goto after_0;
    // 0x80526E04: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80526E08: addiu       $a0, $zero, 0x9A
    ctx->r4 = ADD32(0, 0X9A);
    // 0x80526E0C: jal         0x80067818
    // 0x80526E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_1;
    // 0x80526E10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80526E14: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80526E18: lui         $at, 0x8053
    ctx->r1 = S32(RELOC_HI16(327, 0X6158) << 16);
    // 0x80526E1C: lwc1        $f4, -0x3FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(327, 0X6158));
    // 0x80526E20: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80526E24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80526E28: lui         $t8, 0x8053
    ctx->r24 = S32(RELOC_HI16(327, 0X3B70) << 16);
    // 0x80526E2C: lui         $t9, 0x8053
    ctx->r25 = S32(RELOC_HI16(327, 0X3BC4) << 16);
    // 0x80526E30: lui         $t0, 0x8052
    ctx->r8 = S32(RELOC_HI16(327, 0XF74) << 16);
    // 0x80526E34: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80526E38: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x80526E3C: addiu       $t8, $t8, -0x6590
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(327, 0X3B70));
    // 0x80526E40: addiu       $t9, $t9, -0x653C
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(327, 0X3BC4));
    // 0x80526E44: addiu       $t0, $t0, 0x6E74
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(327, 0XF74));
    // 0x80526E48: sw          $t6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r14;
    // 0x80526E4C: sw          $t7, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r15;
    // 0x80526E50: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x80526E54: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80526E58: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x80526E5C: swc1        $f4, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f4.u32l;
    // 0x80526E60: swc1        $f6, 0x30($a2)
    MEM_W(0X30, ctx->r6) = ctx->f6.u32l;
    // 0x80526E64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80526E68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80526E6C: jr          $ra
    // 0x80526E70: nop

    return;
    // 0x80526E70: nop

;}
RECOMP_FUNC void func_80449AFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80449AFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80449B00: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80449B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80449B08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80449B0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80449B10: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80449B14: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80449B18: lw          $v1, 0x1F4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1F4);
    // 0x80449B1C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449B20: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80449B24: lwc1        $f12, 0x6CE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x80449B28: jal         0x80449A94
    // 0x80449B2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80449A94(rdram, ctx);
        goto after_0;
    // 0x80449B2C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80449B30: beq         $v0, $zero, L_80449CA4
    if (ctx->r2 == 0) {
        // 0x80449B34: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80449CA4;
    }
    // 0x80449B34: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80449B38: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x80449B3C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80449B40: lw          $v0, 0x54($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X54);
    // 0x80449B44: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80449B48: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80449B4C: bne         $at, $zero, L_80449B58
    if (ctx->r1 != 0) {
        // 0x80449B50: sw          $t9, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r25;
            goto L_80449B58;
    }
    // 0x80449B50: sw          $t9, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r25;
    // 0x80449B54: sw          $v0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r2;
L_80449B58:
    // 0x80449B58: lw          $v0, 0x24($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X24);
    // 0x80449B5C: slti        $at, $v0, 0x439
    ctx->r1 = SIGNED(ctx->r2) < 0X439 ? 1 : 0;
    // 0x80449B60: beq         $at, $zero, L_80449B94
    if (ctx->r1 == 0) {
        // 0x80449B64: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449B94;
    }
    // 0x80449B64: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449B68: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449B6C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449B70: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80449B74: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80449B78: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80449B7C: beql        $a1, $t1, L_80449CA8
    if (ctx->r5 == ctx->r9) {
        // 0x80449B80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_0;
    // 0x80449B80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80449B84: jal         0x80445978
    // 0x80449B88: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_1;
    // 0x80449B88: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_1:
    // 0x80449B8C: b           L_80449CA8
    // 0x80449B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449CA8;
    // 0x80449B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449B94:
    // 0x80449B94: slti        $at, $v0, 0x4B1
    ctx->r1 = SIGNED(ctx->r2) < 0X4B1 ? 1 : 0;
    // 0x80449B98: beq         $at, $zero, L_80449BCC
    if (ctx->r1 == 0) {
        // 0x80449B9C: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449BCC;
    }
    // 0x80449B9C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449BA0: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449BA4: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449BA8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80449BAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80449BB0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80449BB4: beql        $a1, $t2, L_80449CA8
    if (ctx->r5 == ctx->r10) {
        // 0x80449BB8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_1;
    // 0x80449BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80449BBC: jal         0x80445978
    // 0x80449BC0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_2;
    // 0x80449BC0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_2:
    // 0x80449BC4: b           L_80449CA8
    // 0x80449BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449CA8;
    // 0x80449BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449BCC:
    // 0x80449BCC: slti        $at, $v0, 0x529
    ctx->r1 = SIGNED(ctx->r2) < 0X529 ? 1 : 0;
    // 0x80449BD0: beq         $at, $zero, L_80449C04
    if (ctx->r1 == 0) {
        // 0x80449BD4: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449C04;
    }
    // 0x80449BD4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449BD8: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449BDC: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449BE0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80449BE4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80449BE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80449BEC: beql        $a1, $t3, L_80449CA8
    if (ctx->r5 == ctx->r11) {
        // 0x80449BF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_2;
    // 0x80449BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80449BF4: jal         0x80445978
    // 0x80449BF8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_3;
    // 0x80449BF8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_3:
    // 0x80449BFC: b           L_80449CA8
    // 0x80449C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449CA8;
    // 0x80449C00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449C04:
    // 0x80449C04: slti        $at, $v0, 0x5A1
    ctx->r1 = SIGNED(ctx->r2) < 0X5A1 ? 1 : 0;
    // 0x80449C08: beq         $at, $zero, L_80449C3C
    if (ctx->r1 == 0) {
        // 0x80449C0C: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449C3C;
    }
    // 0x80449C0C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449C10: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449C14: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449C18: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80449C1C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80449C20: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80449C24: beql        $a1, $t4, L_80449CA8
    if (ctx->r5 == ctx->r12) {
        // 0x80449C28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_3;
    // 0x80449C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80449C2C: jal         0x80445978
    // 0x80449C30: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_4;
    // 0x80449C30: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_4:
    // 0x80449C34: b           L_80449CA8
    // 0x80449C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449CA8;
    // 0x80449C38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449C3C:
    // 0x80449C3C: slti        $at, $v0, 0x655
    ctx->r1 = SIGNED(ctx->r2) < 0X655 ? 1 : 0;
    // 0x80449C40: beq         $at, $zero, L_80449C74
    if (ctx->r1 == 0) {
        // 0x80449C44: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449C74;
    }
    // 0x80449C44: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449C48: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449C4C: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449C50: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80449C54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80449C58: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80449C5C: beql        $a1, $t5, L_80449CA8
    if (ctx->r5 == ctx->r13) {
        // 0x80449C60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_4;
    // 0x80449C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80449C64: jal         0x80445978
    // 0x80449C68: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_5;
    // 0x80449C68: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_5:
    // 0x80449C6C: b           L_80449CA8
    // 0x80449C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80449CA8;
    // 0x80449C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449C74:
    // 0x80449C74: slti        $at, $v0, 0x709
    ctx->r1 = SIGNED(ctx->r2) < 0X709 ? 1 : 0;
    // 0x80449C78: beq         $at, $zero, L_80449CA4
    if (ctx->r1 == 0) {
        // 0x80449C7C: lui         $at, 0x1
        ctx->r1 = S32(0X1 << 16);
            goto L_80449CA4;
    }
    // 0x80449C7C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80449C80: ori         $at, $at, 0x6E7C
    ctx->r1 = ctx->r1 | 0X6E7C;
    // 0x80449C84: addu        $v0, $v1, $at
    ctx->r2 = ADD32(ctx->r3, ctx->r1);
    // 0x80449C88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80449C8C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80449C90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80449C94: beql        $a1, $t6, L_80449CA8
    if (ctx->r5 == ctx->r14) {
        // 0x80449C98: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80449CA8;
    }
    goto skip_5;
    // 0x80449C98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80449C9C: jal         0x80445978
    // 0x80449CA0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    func_80445978(rdram, ctx);
        goto after_6;
    // 0x80449CA0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    after_6:
L_80449CA4:
    // 0x80449CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80449CA8:
    // 0x80449CA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80449CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80449CB0: jr          $ra
    // 0x80449CB4: nop

    return;
    // 0x80449CB4: nop

;}
RECOMP_FUNC void func_80024188(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80024188: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8002418C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80024190: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80024194: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80024198: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002419C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800241A0: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800241A4: lwc1        $f20, 0x118($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X118);
    // 0x800241A8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800241AC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800241B0: sub.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800241B4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800241B8: jal         0x80065954
    // 0x800241BC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x800241BC: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x800241C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800241C4: lwc1        $f2, -0x290($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X290);
    // 0x800241C8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800241CC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800241D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800241D4: nop

    // 0x800241D8: bc1fl       L_800241EC
    if (!c1cs) {
        // 0x800241DC: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_800241EC;
    }
    goto skip_0;
    // 0x800241DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x800241E0: b           L_80024210
    // 0x800241E4: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
        goto L_80024210;
    // 0x800241E4: lwc1        $f20, 0x3C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800241E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_800241EC:
    // 0x800241EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800241F0: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800241F4: nop

    // 0x800241F8: bc1fl       L_80024210
    if (!c1cs) {
        // 0x800241FC: add.s       $f20, $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
            goto L_80024210;
    }
    goto skip_1;
    // 0x800241FC: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
    skip_1:
    // 0x80024200: lwc1        $f10, -0x28C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X28C);
    // 0x80024204: b           L_80024210
    // 0x80024208: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
        goto L_80024210;
    // 0x80024208: sub.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x8002420C: add.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f2.fl;
L_80024210:
    // 0x80024210: swc1        $f20, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f20.u32l;
    // 0x80024214: jal         0x80066DE4
    // 0x80024218: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x80024218: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x8002421C: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80024220: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80024224: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80024228: lwc1        $f18, 0x68($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X68);
    // 0x8002422C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80024230: swc1        $f4, 0xC4($t8)
    MEM_W(0XC4, ctx->r24) = ctx->f4.u32l;
    // 0x80024234: jal         0x80066E88
    // 0x80024238: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80024238: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x8002423C: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x80024240: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80024244: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80024248: swc1        $f8, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->f8.u32l;
    // 0x8002424C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80024250: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80024254: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80024258: jr          $ra
    // 0x8002425C: nop

    return;
    // 0x8002425C: nop

;}
