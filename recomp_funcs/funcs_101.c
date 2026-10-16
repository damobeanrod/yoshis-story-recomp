#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80475240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80475240: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80475244: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80475248: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8047524C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80475250: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80475254: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80475258: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8047525C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80475260: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80475264: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80475268: jr          $ra
    // 0x8047526C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8047526C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8045AAC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045AAC0: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8045AAC4: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8045AAC8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8045AACC: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8045AAD0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045AAD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8045AAD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8045AADC: lui         $at, 0xC3B4
    ctx->r1 = S32(0XC3B4 << 16);
    // 0x8045AAE0: swc1        $f8, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f8.u32l;
    // 0x8045AAE4: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8045AAE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8045AAEC: nop

    // 0x8045AAF0: bc1fl       L_8045AB10
    if (!c1cs) {
        // 0x8045AAF4: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_8045AB10;
    }
    goto skip_0;
    // 0x8045AAF4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x8045AAF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8045AAFC: nop

    // 0x8045AB00: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8045AB04: swc1        $f16, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f16.u32l;
    // 0x8045AB08: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8045AB0C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_8045AB10:
    // 0x8045AB10: nop

    // 0x8045AB14: bc1f        L_8045AB24
    if (!c1cs) {
        // 0x8045AB18: nop
    
            goto L_8045AB24;
    }
    // 0x8045AB18: nop

    // 0x8045AB1C: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8045AB20: swc1        $f4, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f4.u32l;
L_8045AB24:
    // 0x8045AB24: jr          $ra
    // 0x8045AB28: nop

    return;
    // 0x8045AB28: nop

;}
RECOMP_FUNC void func_804B8844(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B8844: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x804B8848: lui         $a2, 0xB800
    ctx->r6 = S32(0XB800 << 16);
    // 0x804B884C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x804B8850: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x804B8854: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x804B8858: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x804B885C: jr          $ra
    // 0x804B8860: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    return;
    // 0x804B8860: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
;}
RECOMP_FUNC void func_80447134(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80447134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80447138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8044713C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80447140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80447144: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80447148: bne         $a2, $zero, L_80447170
    if (ctx->r6 != 0) {
        // 0x8044714C: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_80447170;
    }
    // 0x8044714C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80447150: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80447154: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x80447158: bgtz        $t7, L_804471AC
    if (SIGNED(ctx->r15) > 0) {
        // 0x8044715C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_804471AC;
    }
    // 0x8044715C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80447160: jal         0x80445F04
    // 0x80447164: nop

    func_80445F04(rdram, ctx);
        goto after_0;
    // 0x80447164: nop

    after_0:
    // 0x80447168: b           L_804471B0
    // 0x8044716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804471B0;
    // 0x8044716C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80447170:
    // 0x80447170: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80447174: bnel        $a2, $at, L_8044719C
    if (ctx->r6 != ctx->r1) {
        // 0x80447178: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8044719C;
    }
    goto skip_0;
    // 0x80447178: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8044717C: jal         0x80445EC8
    // 0x80447180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80445EC8(rdram, ctx);
        goto after_1;
    // 0x80447180: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80447184: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80447188: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8044718C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80447190: b           L_804471AC
    // 0x80447194: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
        goto L_804471AC;
    // 0x80447194: sw          $zero, 0x6A28($at)
    MEM_W(0X6A28, ctx->r1) = 0;
    // 0x80447198: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8044719C:
    // 0x8044719C: bnel        $a2, $at, L_804471B0
    if (ctx->r6 != ctx->r1) {
        // 0x804471A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804471B0;
    }
    goto skip_1;
    // 0x804471A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804471A4: jal         0x80445F04
    // 0x804471A8: nop

    func_80445F04(rdram, ctx);
        goto after_2;
    // 0x804471A8: nop

    after_2:
L_804471AC:
    // 0x804471AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804471B0:
    // 0x804471B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804471B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804471B8: jr          $ra
    // 0x804471BC: nop

    return;
    // 0x804471BC: nop

;}
RECOMP_FUNC void func_80051258(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051258: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8005125C: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x80051260: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80051264: blez        $a1, L_8005133C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80051268: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8005133C;
    }
    // 0x80051268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005126C: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80051270: beq         $v1, $zero, L_800512AC
    if (ctx->r3 == 0) {
        // 0x80051274: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_800512AC;
    }
    // 0x80051274: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x80051278: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8005127C: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
L_80051280:
    // 0x80051280: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80051284: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80051288: xor         $v1, $a0, $t6
    ctx->r3 = ctx->r4 ^ ctx->r14;
    // 0x8005128C: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80051290: beq         $v1, $zero, L_800512A0
    if (ctx->r3 == 0) {
        // 0x80051294: nop
    
            goto L_800512A0;
    }
    // 0x80051294: nop

    // 0x80051298: jr          $ra
    // 0x8005129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8005129C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800512A0:
    // 0x800512A0: bnel        $t0, $v0, L_80051280
    if (ctx->r8 != ctx->r2) {
        // 0x800512A4: lhu         $t6, 0x0($a3)
        ctx->r14 = MEM_HU(ctx->r7, 0X0);
            goto L_80051280;
    }
    goto skip_0;
    // 0x800512A4: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    skip_0:
    // 0x800512A8: beq         $v0, $a1, L_8005133C
    if (ctx->r2 == ctx->r5) {
        // 0x800512AC: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8005133C;
    }
L_800512AC:
    // 0x800512AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800512B0: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
L_800512B4:
    // 0x800512B4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800512B8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800512BC: xor         $v1, $a0, $t7
    ctx->r3 = ctx->r4 ^ ctx->r15;
    // 0x800512C0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800512C4: beql        $v1, $zero, L_800512D8
    if (ctx->r3 == 0) {
        // 0x800512C8: lhu         $t8, 0x0($a3)
        ctx->r24 = MEM_HU(ctx->r7, 0X0);
            goto L_800512D8;
    }
    goto skip_1;
    // 0x800512C8: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
    skip_1:
    // 0x800512CC: jr          $ra
    // 0x800512D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800512D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800512D4: lhu         $t8, 0x0($a3)
    ctx->r24 = MEM_HU(ctx->r7, 0X0);
L_800512D8:
    // 0x800512D8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800512DC: xor         $v1, $a0, $t8
    ctx->r3 = ctx->r4 ^ ctx->r24;
    // 0x800512E0: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800512E4: beql        $v1, $zero, L_800512F8
    if (ctx->r3 == 0) {
        // 0x800512E8: lhu         $t9, 0x0($a3)
        ctx->r25 = MEM_HU(ctx->r7, 0X0);
            goto L_800512F8;
    }
    goto skip_2;
    // 0x800512E8: lhu         $t9, 0x0($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X0);
    skip_2:
    // 0x800512EC: jr          $ra
    // 0x800512F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800512F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800512F4: lhu         $t9, 0x0($a3)
    ctx->r25 = MEM_HU(ctx->r7, 0X0);
L_800512F8:
    // 0x800512F8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800512FC: xor         $v1, $a0, $t9
    ctx->r3 = ctx->r4 ^ ctx->r25;
    // 0x80051300: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80051304: beql        $v1, $zero, L_80051318
    if (ctx->r3 == 0) {
        // 0x80051308: lhu         $t1, 0x0($a3)
        ctx->r9 = MEM_HU(ctx->r7, 0X0);
            goto L_80051318;
    }
    goto skip_3;
    // 0x80051308: lhu         $t1, 0x0($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X0);
    skip_3:
    // 0x8005130C: jr          $ra
    // 0x80051310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80051310: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80051314: lhu         $t1, 0x0($a3)
    ctx->r9 = MEM_HU(ctx->r7, 0X0);
L_80051318:
    // 0x80051318: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8005131C: xor         $v1, $a0, $t1
    ctx->r3 = ctx->r4 ^ ctx->r9;
    // 0x80051320: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x80051324: beq         $v1, $zero, L_80051334
    if (ctx->r3 == 0) {
        // 0x80051328: nop
    
            goto L_80051334;
    }
    // 0x80051328: nop

    // 0x8005132C: jr          $ra
    // 0x80051330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80051330: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051334:
    // 0x80051334: bnel        $v0, $a1, L_800512B4
    if (ctx->r2 != ctx->r5) {
        // 0x80051338: lhu         $t7, 0x0($a3)
        ctx->r15 = MEM_HU(ctx->r7, 0X0);
            goto L_800512B4;
    }
    goto skip_4;
    // 0x80051338: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    skip_4:
L_8005133C:
    // 0x8005133C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80051340: jr          $ra
    // 0x80051344: nop

    return;
    // 0x80051344: nop

;}
RECOMP_FUNC void func_80059448(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005944C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059450: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80059454: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80059458: jal         0x80081C64
    // 0x8005945C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    Math_FFloorF(rdram, ctx);
        goto after_0;
    // 0x8005945C: lwc1        $f12, 0x8($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80059460: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x80059464: addiu       $a0, $a0, 0x7EA0
    ctx->r4 = ADD32(ctx->r4, 0X7EA0);
    // 0x80059468: lw          $v1, 0x3F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3F4);
    // 0x8005946C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80059470: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80059474: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80059478: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8005947C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80059480: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80059484: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80059488: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8005948C: lw          $t1, 0x478($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X478);
    // 0x80059490: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80059494: lwc1        $f4, 0xB9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB9C);
    // 0x80059498: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8005949C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800594A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800594A4: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800594A8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800594AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800594B0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800594B4: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800594B8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800594BC: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800594C0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800594C4: lwc1        $f6, 0x30($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X30);
    // 0x800594C8: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800594CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800594D0: add.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800594D4: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800594D8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800594DC: c.lt.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl < ctx->f10.fl;
    // 0x800594E0: nop

    // 0x800594E4: bc1f        L_800594F0
    if (!c1cs) {
        // 0x800594E8: nop
    
            goto L_800594F0;
    }
    // 0x800594E8: nop

    // 0x800594EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800594F0:
    // 0x800594F0: jr          $ra
    // 0x800594F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800594F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80581488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80581488: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8058148C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80581490: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80581494: jal         0x80045A34
    // 0x80581498: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80581498: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x8058149C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x805814A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805814A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x805814A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x805814AC: jal         0x800657CC
    // 0x805814B0: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x805814B0: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x805814B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805814B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805814BC: jr          $ra
    // 0x805814C0: nop

    return;
    // 0x805814C0: nop

;}
RECOMP_FUNC void func_805A5758(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A5758: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A575C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805A5760: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805A5764: lhu         $t6, 0xC($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC);
    // 0x805A5768: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x805A576C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805A5770: bne         $t6, $at, L_805A57F4
    if (ctx->r14 != ctx->r1) {
        // 0x805A5774: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_805A57F4;
    }
    // 0x805A5774: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x805A5778: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x805A577C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x805A5780: lw          $v0, 0x1F4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1F4);
    // 0x805A5784: bnel        $v1, $at, L_805A57A8
    if (ctx->r3 != ctx->r1) {
        // 0x805A5788: lbu         $v0, 0x18($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X18);
            goto L_805A57A8;
    }
    goto skip_0;
    // 0x805A5788: lbu         $v0, 0x18($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X18);
    skip_0:
    // 0x805A578C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x805A5790: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A5794: bnel        $t7, $zero, L_805A57A8
    if (ctx->r15 != 0) {
        // 0x805A5798: lbu         $v0, 0x18($a2)
        ctx->r2 = MEM_BU(ctx->r6, 0X18);
            goto L_805A57A8;
    }
    goto skip_1;
    // 0x805A5798: lbu         $v0, 0x18($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X18);
    skip_1:
    // 0x805A579C: b           L_805A5848
    // 0x805A57A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_805A5848;
    // 0x805A57A0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805A57A4: lbu         $v0, 0x18($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X18);
L_805A57A8:
    // 0x805A57A8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805A57AC: beq         $v0, $at, L_805A57BC
    if (ctx->r2 == ctx->r1) {
        // 0x805A57B0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_805A57BC;
    }
    // 0x805A57B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805A57B4: bnel        $v0, $at, L_805A584C
    if (ctx->r2 != ctx->r1) {
        // 0x805A57B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A584C;
    }
    goto skip_2;
    // 0x805A57B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
L_805A57BC:
    // 0x805A57BC: bne         $v1, $zero, L_805A5848
    if (ctx->r3 != 0) {
        // 0x805A57C0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_805A5848;
    }
    // 0x805A57C0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x805A57C4: jal         0x80040AC8
    // 0x805A57C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80040AC8(rdram, ctx);
        goto after_0;
    // 0x805A57C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x805A57CC: jal         0x805A5628
    // 0x805A57D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805A5628(rdram, ctx);
        goto after_1;
    // 0x805A57D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805A57D4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805A57D8: jal         0x80067BBC
    // 0x805A57DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805A57DC: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x805A57E0: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x805A57E4: jal         0x80067818
    // 0x805A57E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x805A57E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805A57EC: b           L_805A584C
    // 0x805A57F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805A584C;
    // 0x805A57F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A57F4:
    // 0x805A57F4: lbu         $v0, 0x18($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X18);
    // 0x805A57F8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x805A57FC: beq         $v0, $at, L_805A580C
    if (ctx->r2 == ctx->r1) {
        // 0x805A5800: addiu       $at, $zero, 0x67
        ctx->r1 = ADD32(0, 0X67);
            goto L_805A580C;
    }
    // 0x805A5800: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x805A5804: bnel        $v0, $at, L_805A584C
    if (ctx->r2 != ctx->r1) {
        // 0x805A5808: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A584C;
    }
    goto skip_3;
    // 0x805A5808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
L_805A580C:
    // 0x805A580C: lbu         $t9, 0x30($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X30);
    // 0x805A5810: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805A5814: bnel        $t9, $zero, L_805A584C
    if (ctx->r25 != 0) {
        // 0x805A5818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_805A584C;
    }
    goto skip_4;
    // 0x805A5818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x805A581C: jal         0x805A5628
    // 0x805A5820: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_805A5628(rdram, ctx);
        goto after_4;
    // 0x805A5820: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_4:
    // 0x805A5824: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805A5828: jal         0x8003E478
    // 0x805A582C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8003E478(rdram, ctx);
        goto after_5;
    // 0x805A582C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x805A5830: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805A5834: jal         0x80067BBC
    // 0x805A5838: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x805A5838: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x805A583C: addiu       $a0, $zero, 0x90
    ctx->r4 = ADD32(0, 0X90);
    // 0x805A5840: jal         0x80067818
    // 0x805A5844: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x805A5844: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_805A5848:
    // 0x805A5848: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805A584C:
    // 0x805A584C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805A5850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A5854: jr          $ra
    // 0x805A5858: nop

    return;
    // 0x805A5858: nop

;}
RECOMP_FUNC void func_805D2FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D2FE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D2FEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805D2FF0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805D2FF4: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x805D2FF8: jal         0x80058B44
    // 0x805D2FFC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80058B44(rdram, ctx);
        goto after_0;
    // 0x805D2FFC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805D3000: beq         $v0, $zero, L_805D3024
    if (ctx->r2 == 0) {
        // 0x805D3004: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_805D3024;
    }
    // 0x805D3004: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805D3008: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x805D300C: jal         0x80058C10
    // 0x805D3010: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    func_80058C10(rdram, ctx);
        goto after_1;
    // 0x805D3010: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x805D3014: beq         $v0, $zero, L_805D3024
    if (ctx->r2 == 0) {
        // 0x805D3018: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_805D3024;
    }
    // 0x805D3018: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x805D301C: jal         0x800447C8
    // 0x805D3020: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_800447C8(rdram, ctx);
        goto after_2;
    // 0x805D3020: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_805D3024:
    // 0x805D3024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805D3028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805D302C: jr          $ra
    // 0x805D3030: nop

    return;
    // 0x805D3030: nop

;}
RECOMP_FUNC void func_806806D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806806D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806806DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806806E0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x806806E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806806E8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x806806EC: jal         0x80062684
    // 0x806806F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x806806F0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x806806F4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x806806F8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806806FC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80680700: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80680704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80680708: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8068070C: lbu         $t9, 0x30($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X30);
    // 0x80680710: bnel        $t9, $zero, L_8068072C
    if (ctx->r25 != 0) {
        // 0x80680714: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8068072C;
    }
    goto skip_0;
    // 0x80680714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80680718: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8068071C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80680720: jal         0x80680D04
    // 0x80680724: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    func_80680D04(rdram, ctx);
        goto after_1;
    // 0x80680724: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    after_1:
    // 0x80680728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8068072C:
    // 0x8068072C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680730: jr          $ra
    // 0x80680734: nop

    return;
    // 0x80680734: nop

;}
RECOMP_FUNC void func_804C5264(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C5264: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804C5268: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C526C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804C5270: lhu         $v0, 0xC($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XC);
    // 0x804C5274: addiu       $at, $zero, 0x4001
    ctx->r1 = ADD32(0, 0X4001);
    // 0x804C5278: bnel        $v0, $at, L_804C5294
    if (ctx->r2 != ctx->r1) {
        // 0x804C527C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C5294;
    }
    goto skip_0;
    // 0x804C527C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C5280: jal         0x804C57AC
    // 0x804C5284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_804C57AC(rdram, ctx);
        goto after_0;
    // 0x804C5284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x804C5288: jal         0x804C5158
    // 0x804C528C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804C5158(rdram, ctx);
        goto after_1;
    // 0x804C528C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x804C5290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C5294:
    // 0x804C5294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804C5298: jr          $ra
    // 0x804C529C: nop

    return;
    // 0x804C529C: nop

;}
RECOMP_FUNC void func_8002E670(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E670: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002E674: lw          $t6, -0x76BC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X76BC);
    // 0x8002E678: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002E67C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002E680: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002E684: beq         $t6, $zero, L_8002E69C
    if (ctx->r14 == 0) {
        // 0x8002E688: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8002E69C;
    }
    // 0x8002E688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002E68C: jal         0x8002E488
    // 0x8002E690: nop

    func_8002E488(rdram, ctx);
        goto after_0;
    // 0x8002E690: nop

    after_0:
    // 0x8002E694: b           L_8002E6EC
    // 0x8002E698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002E6EC;
    // 0x8002E698: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E69C:
    // 0x8002E69C: jal         0x8002B798
    // 0x8002E6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002B798(rdram, ctx);
        goto after_1;
    // 0x8002E6A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8002E6A4: beq         $v0, $zero, L_8002E6BC
    if (ctx->r2 == 0) {
        // 0x8002E6A8: nop
    
            goto L_8002E6BC;
    }
    // 0x8002E6A8: nop

    // 0x8002E6AC: jal         0x8002E4F0
    // 0x8002E6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002E4F0(rdram, ctx);
        goto after_2;
    // 0x8002E6B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002E6B4: b           L_8002E6C4
    // 0x8002E6B8: nop

        goto L_8002E6C4;
    // 0x8002E6B8: nop

L_8002E6BC:
    // 0x8002E6BC: jal         0x8002D34C
    // 0x8002E6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002D34C(rdram, ctx);
        goto after_3;
    // 0x8002E6C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_8002E6C4:
    // 0x8002E6C4: jal         0x8001D770
    // 0x8002E6C8: nop

    func_8001D770(rdram, ctx);
        goto after_4;
    // 0x8002E6C8: nop

    after_4:
    // 0x8002E6CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002E6D0: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x8002E6D4: jal         0x80067BF8
    // 0x8002E6D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_5;
    // 0x8002E6D8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x8002E6DC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8002E6E0: jal         0x80067818
    // 0x8002E6E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x8002E6E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8002E6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002E6EC:
    // 0x8002E6EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002E6F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002E6F4: jr          $ra
    // 0x8002E6F8: nop

    return;
    // 0x8002E6F8: nop

;}
RECOMP_FUNC void func_8002BB90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002BB90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002BB94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002BB98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002BB9C: sb          $zero, 0x1AD($a0)
    MEM_B(0X1AD, ctx->r4) = 0;
    // 0x8002BBA0: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x8002BBA4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8002BBA8: sb          $zero, 0x21($a0)
    MEM_B(0X21, ctx->r4) = 0;
    // 0x8002BBAC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8002BBB0: swc1        $f4, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f4.u32l;
    // 0x8002BBB4: lw          $t6, -0x7CE8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7CE8);
    // 0x8002BBB8: sb          $zero, 0xF0($t6)
    MEM_B(0XF0, ctx->r14) = 0;
    // 0x8002BBBC: sw          $zero, 0x16C($a0)
    MEM_W(0X16C, ctx->r4) = 0;
    // 0x8002BBC0: sw          $zero, 0x11C($a0)
    MEM_W(0X11C, ctx->r4) = 0;
    // 0x8002BBC4: sw          $zero, 0x12D0($a0)
    MEM_W(0X12D0, ctx->r4) = 0;
    // 0x8002BBC8: sw          $zero, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = 0;
    // 0x8002BBCC: jal         0x8002E274
    // 0x8002BBD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002E274(rdram, ctx);
        goto after_0;
    // 0x8002BBD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002BBD4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8002BBD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002BBDC: nop

    // 0x8002BBE0: swc1        $f6, 0x12E4($a0)
    MEM_W(0X12E4, ctx->r4) = ctx->f6.u32l;
    // 0x8002BBE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002BBE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002BBEC: jr          $ra
    // 0x8002BBF0: nop

    return;
    // 0x8002BBF0: nop

;}
RECOMP_FUNC void func_804622E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804622E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804622E8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804622EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804622F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x804622F4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x804622F8: jal         0x80082730
    // 0x804622FC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    fsin(rdram, ctx);
        goto after_0;
    // 0x804622FC: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x80462300: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80462304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80462308: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8046230C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80462310: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80462314: lwc1        $f4, 0x3C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80462318: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8046231C: jal         0x8008D250
    // 0x80462320: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80462320: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x80462324: lui         $at, 0x439B
    ctx->r1 = S32(0X439B << 16);
    // 0x80462328: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8046232C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80462330: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80462334: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80462338: lwc1        $f16, 0x40($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X40);
    // 0x8046233C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80462340: jal         0x80081F80
    // 0x80462344: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    Math_FAsinF(rdram, ctx);
        goto after_2;
    // 0x80462344: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x80462348: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8046234C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80462350: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80462354: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80462358: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8046235C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80462360: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80462364: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80462368: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8046236C: jr          $ra
    // 0x80462370: nop

    return;
    // 0x80462370: nop

;}
RECOMP_FUNC void func_804BA28C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BA28C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BA290: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BA294: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804BA298: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804BA29C: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BA2A0: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X2A94) << 16);
    // 0x804BA2A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804BA2A8: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804BA2AC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804BA2B0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BA2B4: lw          $t8, -0x574C($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X2A94));
    // 0x804BA2B8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804BA2BC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x804BA2C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804BA2C4: jal         0x80048490
    // 0x804BA2C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x804BA2C8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x804BA2CC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x804BA2D0: jal         0x80048378
    // 0x804BA2D4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x804BA2D4: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x804BA2D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BA2DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BA2E0: jr          $ra
    // 0x804BA2E4: nop

    return;
    // 0x804BA2E4: nop

;}
RECOMP_FUNC void func_80709D9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80709D9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80709DA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80709DA4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80709DA8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80709DAC: jal         0x80047090
    // 0x80709DB0: addiu       $a0, $zero, 0x401A
    ctx->r4 = ADD32(0, 0X401A);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80709DB0: addiu       $a0, $zero, 0x401A
    ctx->r4 = ADD32(0, 0X401A);
    after_0:
    // 0x80709DB4: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80709DB8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80709DBC: beq         $v0, $at, L_80709E28
    if (ctx->r2 == ctx->r1) {
        // 0x80709DC0: andi        $t0, $v0, 0xFFFF
        ctx->r8 = ctx->r2 & 0XFFFF;
            goto L_80709E28;
    }
    // 0x80709DC0: andi        $t0, $v0, 0xFFFF
    ctx->r8 = ctx->r2 & 0XFFFF;
    // 0x80709DC4: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x80709DC8: lui         $at, 0x401A
    ctx->r1 = S32(0X401A << 16);
    // 0x80709DCC: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80709DD0: lui         $a0, 0x8071
    ctx->r4 = S32(RELOC_HI16(718, 0X258C) << 16);
    // 0x80709DD4: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x80709DD8: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x80709DDC: addiu       $a0, $a0, -0x4894
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(718, 0X258C));
    // 0x80709DE0: or          $a1, $t0, $at
    ctx->r5 = ctx->r8 | ctx->r1;
    // 0x80709DE4: jal         0x80046804
    // 0x80709DE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x80709DE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80709DEC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80709DF0: beq         $v0, $zero, L_80709E28
    if (ctx->r2 == 0) {
        // 0x80709DF4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80709E28;
    }
    // 0x80709DF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80709DF8: beq         $v1, $zero, L_80709E18
    if (ctx->r3 == 0) {
        // 0x80709DFC: nop
    
            goto L_80709E18;
    }
    // 0x80709DFC: nop

    // 0x80709E00: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80709E04: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80709E08: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80709E0C: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x80709E10: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80709E14: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_80709E18:
    // 0x80709E18: jal         0x807094B4
    // 0x80709E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_807094B4(rdram, ctx);
        goto after_2;
    // 0x80709E1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x80709E20: b           L_80709E2C
    // 0x80709E24: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_80709E2C;
    // 0x80709E24: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_80709E28:
    // 0x80709E28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80709E2C:
    // 0x80709E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80709E30: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80709E34: jr          $ra
    // 0x80709E38: nop

    return;
    // 0x80709E38: nop

    // 0x80709E3C: nop

;}
RECOMP_FUNC void func_80558A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558A28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80558A2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558A30: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558A34: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558A38: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558A3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558A40: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80558A44: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80558A48: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    // 0x80558A4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80558A50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80558A54: jal         0x80048F84
    // 0x80558A58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80558A58: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80558A5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80558A60: jal         0x80048F84
    // 0x80558A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80558A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80558A68: jal         0x805580E8
    // 0x80558A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_2;
    // 0x80558A6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80558A70: jal         0x805582E0
    // 0x80558A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x80558A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80558A78: beq         $v0, $zero, L_80558ACC
    if (ctx->r2 == 0) {
        // 0x80558A7C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80558ACC;
    }
    // 0x80558A7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558A80: jal         0x80557B60
    // 0x80558A84: addiu       $a1, $zero, 0x285
    ctx->r5 = ADD32(0, 0X285);
    func_80557B60(rdram, ctx);
        goto after_4;
    // 0x80558A84: addiu       $a1, $zero, 0x285
    ctx->r5 = ADD32(0, 0X285);
    after_4:
    // 0x80558A88: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80558A8C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80558A90: sb          $t6, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r14;
    // 0x80558A94: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80558A98: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80558A9C: sb          $t7, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r15;
    // 0x80558AA0: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80558AA4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80558AA8: sb          $t8, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r24;
    // 0x80558AAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80558AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558AB4: jal         0x80559928
    // 0x80558AB8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_80559928(rdram, ctx);
        goto after_5;
    // 0x80558AB8: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_5:
    // 0x80558ABC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80558AC0: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x80558AC4: xori        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 ^ 0X1;
    // 0x80558AC8: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_80558ACC:
    // 0x80558ACC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558AD0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558AD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80558AD8: jr          $ra
    // 0x80558ADC: nop

    return;
    // 0x80558ADC: nop

;}
RECOMP_FUNC void func_804B945C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804B945C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804B9460: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804B9464: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804B9468: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x804B946C: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(185, 0X2A50) << 16);
    // 0x804B9470: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804B9474: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804B9478: lw          $t8, -0x5790($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(185, 0X2A50));
    // 0x804B947C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x804B9480: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x804B9484: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x804B9488: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x804B948C: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x804B9490: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x804B9494: beql        $v1, $zero, L_804B94C8
    if (ctx->r3 == 0) {
        // 0x804B9498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804B94C8;
    }
    goto skip_0;
    // 0x804B9498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804B949C: jalr        $v1
    // 0x804B94A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x804B94A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804B94A4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804B94A8: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x804B94AC: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x804B94B0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x804B94B4: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x804B94B8: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x804B94BC: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x804B94C0: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x804B94C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804B94C8:
    // 0x804B94C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804B94CC: jr          $ra
    // 0x804B94D0: nop

    return;
    // 0x804B94D0: nop

;}
RECOMP_FUNC void func_805A6420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A6420: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805A6424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805A6428: jal         0x805A5DF0
    // 0x805A642C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_805A5DF0(rdram, ctx);
        goto after_0;
    // 0x805A642C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x805A6430: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x805A6434: lbu         $t6, 0x7EA5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7EA5);
    // 0x805A6438: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805A643C: bnel        $t6, $zero, L_805A6470
    if (ctx->r14 != 0) {
        // 0x805A6440: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805A6470;
    }
    goto skip_0;
    // 0x805A6440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805A6444: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x805A6448: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805A644C: jal         0x805A6730
    // 0x805A6450: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_805A6730(rdram, ctx);
        goto after_1;
    // 0x805A6450: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x805A6454: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x805A6458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x805A645C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805A6460: sb          $t8, 0x75($t0)
    MEM_B(0X75, ctx->r8) = ctx->r24;
    // 0x805A6464: jal         0x8005FC0C
    // 0x805A6468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_8005FC0C(rdram, ctx);
        goto after_2;
    // 0x805A6468: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x805A646C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805A6470:
    // 0x805A6470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805A6474: jr          $ra
    // 0x805A6478: nop

    return;
    // 0x805A6478: nop

;}
RECOMP_FUNC void func_807803A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807803A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807803AC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807803B0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x807803B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807803B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807803BC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x807803C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x807803C4: lui         $a0, 0x463B
    ctx->r4 = S32(0X463B << 16);
    // 0x807803C8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x807803CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807803D0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807803D4: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807803D8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x807803DC: jal         0x8004613C
    // 0x807803E0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    func_8004613C(rdram, ctx);
        goto after_0;
    // 0x807803E0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x807803E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807803E8: jal         0x80047F9C
    // 0x807803EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_1;
    // 0x807803EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x807803F0: lui         $a0, 0x463C
    ctx->r4 = S32(0X463C << 16);
    // 0x807803F4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807803F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807803FC: lui         $a3, 0x3B03
    ctx->r7 = S32(0X3B03 << 16);
    // 0x80780400: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80780404: jal         0x8004613C
    // 0x80780408: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_2;
    // 0x80780408: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_2:
    // 0x8078040C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780410: jal         0x80047F9C
    // 0x80780414: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x80780414: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80780418: lui         $a0, 0x463C
    ctx->r4 = S32(0X463C << 16);
    // 0x8078041C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780420: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80780424: lui         $a3, 0x3B44
    ctx->r7 = S32(0X3B44 << 16);
    // 0x80780428: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x8078042C: jal         0x8004613C
    // 0x80780430: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x80780430: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    after_4:
    // 0x80780434: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780438: jal         0x80047F9C
    // 0x8078043C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x8078043C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x80780440: lui         $a0, 0x463C
    ctx->r4 = S32(0X463C << 16);
    // 0x80780444: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780448: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078044C: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x80780450: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80780454: jal         0x8004613C
    // 0x80780458: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    func_8004613C(rdram, ctx);
        goto after_6;
    // 0x80780458: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    after_6:
    // 0x8078045C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780460: jal         0x80047F9C
    // 0x80780464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_7;
    // 0x80780464: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x80780468: lui         $a0, 0x463C
    ctx->r4 = S32(0X463C << 16);
    // 0x8078046C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780470: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80780474: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80780478: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8078047C: jal         0x8004613C
    // 0x80780480: ori         $a0, $a0, 0x203
    ctx->r4 = ctx->r4 | 0X203;
    func_8004613C(rdram, ctx);
        goto after_8;
    // 0x80780480: ori         $a0, $a0, 0x203
    ctx->r4 = ctx->r4 | 0X203;
    after_8:
    // 0x80780484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780488: jal         0x80047F9C
    // 0x8078048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_9;
    // 0x8078048C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80780490: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x80780494: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780498: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078049C: lui         $a3, 0x3BC4
    ctx->r7 = S32(0X3BC4 << 16);
    // 0x807804A0: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x807804A4: jal         0x8004613C
    // 0x807804A8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_10;
    // 0x807804A8: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_10:
    // 0x807804AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807804B0: jal         0x80047F9C
    // 0x807804B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_11;
    // 0x807804B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x807804B8: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x807804BC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807804C0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807804C4: lui         $a3, 0x3BE5
    ctx->r7 = S32(0X3BE5 << 16);
    // 0x807804C8: ori         $a3, $a3, 0x6042
    ctx->r7 = ctx->r7 | 0X6042;
    // 0x807804CC: jal         0x8004613C
    // 0x807804D0: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    func_8004613C(rdram, ctx);
        goto after_12;
    // 0x807804D0: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    after_12:
    // 0x807804D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807804D8: jal         0x80047F9C
    // 0x807804DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_13;
    // 0x807804DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x807804E0: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x807804E4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807804E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807804EC: lui         $a3, 0x3C03
    ctx->r7 = S32(0X3C03 << 16);
    // 0x807804F0: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807804F4: jal         0x8004613C
    // 0x807804F8: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    func_8004613C(rdram, ctx);
        goto after_14;
    // 0x807804F8: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    after_14:
    // 0x807804FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780500: jal         0x80047F9C
    // 0x80780504: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_15;
    // 0x80780504: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x80780508: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x8078050C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780510: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80780514: lui         $a3, 0x3C13
    ctx->r7 = S32(0X3C13 << 16);
    // 0x80780518: ori         $a3, $a3, 0x74BC
    ctx->r7 = ctx->r7 | 0X74BC;
    // 0x8078051C: jal         0x8004613C
    // 0x80780520: ori         $a0, $a0, 0x203
    ctx->r4 = ctx->r4 | 0X203;
    func_8004613C(rdram, ctx);
        goto after_16;
    // 0x80780520: ori         $a0, $a0, 0x203
    ctx->r4 = ctx->r4 | 0X203;
    after_16:
    // 0x80780524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780528: jal         0x80047F9C
    // 0x8078052C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_17;
    // 0x8078052C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80780530: lui         $a0, 0x463E
    ctx->r4 = S32(0X463E << 16);
    // 0x80780534: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780538: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078053C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80780540: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80780544: jal         0x8004613C
    // 0x80780548: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_18;
    // 0x80780548: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_18:
    // 0x8078054C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80780550: sh          $t7, 0x144($v0)
    MEM_H(0X144, ctx->r2) = ctx->r15;
    // 0x80780554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780558: jal         0x80047F9C
    // 0x8078055C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_19;
    // 0x8078055C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x80780560: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80780564: lw          $t8, -0x7250($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7250);
    // 0x80780568: lui         $a0, 0x8078
    ctx->r4 = S32(RELOC_HI16(784, 0X64E8) << 16);
    // 0x8078056C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780570: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80780574: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80780578: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078057C: lui         $a3, 0x3C34
    ctx->r7 = S32(0X3C34 << 16);
    // 0x80780580: ori         $a3, $a3, 0x3958
    ctx->r7 = ctx->r7 | 0X3958;
    // 0x80780584: jal         0x8004613C
    // 0x80780588: lw          $a0, 0x66D8($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(784, 0X64E8));
    func_8004613C(rdram, ctx);
        goto after_20;
    // 0x80780588: lw          $a0, 0x66D8($a0)
    ctx->r4 = MEM_W(ctx->r4, (int16_t)RELOC_LO16(784, 0X64E8));
    after_20:
    // 0x8078058C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780590: jal         0x80047F9C
    // 0x80780594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_21;
    // 0x80780594: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_21:
    // 0x80780598: lui         $a0, 0x463E
    ctx->r4 = S32(0X463E << 16);
    // 0x8078059C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807805A0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807805A4: lui         $a3, 0x3C44
    ctx->r7 = S32(0X3C44 << 16);
    // 0x807805A8: ori         $a3, $a3, 0x9BA6
    ctx->r7 = ctx->r7 | 0X9BA6;
    // 0x807805AC: jal         0x8004613C
    // 0x807805B0: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    func_8004613C(rdram, ctx);
        goto after_22;
    // 0x807805B0: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    after_22:
    // 0x807805B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807805B8: jal         0x80047F9C
    // 0x807805BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_23;
    // 0x807805BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_23:
    // 0x807805C0: lui         $a0, 0x463E
    ctx->r4 = S32(0X463E << 16);
    // 0x807805C4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807805C8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807805CC: lui         $a3, 0x3C54
    ctx->r7 = S32(0X3C54 << 16);
    // 0x807805D0: ori         $a3, $a3, 0xFDF4
    ctx->r7 = ctx->r7 | 0XFDF4;
    // 0x807805D4: jal         0x8004613C
    // 0x807805D8: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    func_8004613C(rdram, ctx);
        goto after_24;
    // 0x807805D8: ori         $a0, $a0, 0x201
    ctx->r4 = ctx->r4 | 0X201;
    after_24:
    // 0x807805DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807805E0: jal         0x80047F9C
    // 0x807805E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_25;
    // 0x807805E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_25:
    // 0x807805E8: lui         $a0, 0x463E
    ctx->r4 = S32(0X463E << 16);
    // 0x807805EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x807805F0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x807805F4: lui         $a3, 0x3C65
    ctx->r7 = S32(0X3C65 << 16);
    // 0x807805F8: ori         $a3, $a3, 0x6042
    ctx->r7 = ctx->r7 | 0X6042;
    // 0x807805FC: jal         0x8004613C
    // 0x80780600: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    func_8004613C(rdram, ctx);
        goto after_26;
    // 0x80780600: ori         $a0, $a0, 0x202
    ctx->r4 = ctx->r4 | 0X202;
    after_26:
    // 0x80780604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780608: jal         0x80047F9C
    // 0x8078060C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_27;
    // 0x8078060C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_27:
    // 0x80780610: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x80780614: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780618: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078061C: lui         $a3, 0x3C75
    ctx->r7 = S32(0X3C75 << 16);
    // 0x80780620: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80780624: jal         0x8004613C
    // 0x80780628: ori         $a0, $a0, 0x204
    ctx->r4 = ctx->r4 | 0X204;
    func_8004613C(rdram, ctx);
        goto after_28;
    // 0x80780628: ori         $a0, $a0, 0x204
    ctx->r4 = ctx->r4 | 0X204;
    after_28:
    // 0x8078062C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780630: jal         0x80047F9C
    // 0x80780634: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_29;
    // 0x80780634: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_29:
    // 0x80780638: lui         $a0, 0x4652
    ctx->r4 = S32(0X4652 << 16);
    // 0x8078063C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780640: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80780644: lui         $a3, 0x3C83
    ctx->r7 = S32(0X3C83 << 16);
    // 0x80780648: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8078064C: jal         0x8004613C
    // 0x80780650: ori         $a0, $a0, 0x205
    ctx->r4 = ctx->r4 | 0X205;
    func_8004613C(rdram, ctx);
        goto after_30;
    // 0x80780650: ori         $a0, $a0, 0x205
    ctx->r4 = ctx->r4 | 0X205;
    after_30:
    // 0x80780654: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780658: jal         0x80047F9C
    // 0x8078065C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_31;
    // 0x8078065C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_31:
    // 0x80780660: lui         $a0, 0x4014
    ctx->r4 = S32(0X4014 << 16);
    // 0x80780664: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80780668: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8078066C: ori         $a0, $a0, 0x200
    ctx->r4 = ctx->r4 | 0X200;
    // 0x80780670: jal         0x8004613C
    // 0x80780674: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    func_8004613C(rdram, ctx);
        goto after_32;
    // 0x80780674: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    after_32:
    // 0x80780678: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8078067C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80780680: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80780684: jal         0x80047F9C
    // 0x80780688: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_33;
    // 0x80780688: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    after_33:
    // 0x8078068C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80780690: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80780694: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80780698: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8078069C: sb          $t1, 0x17C($t2)
    MEM_B(0X17C, ctx->r10) = ctx->r9;
    // 0x807806A0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x807806A4: lw          $t5, 0x16C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X16C);
    // 0x807806A8: sb          $t3, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r11;
    // 0x807806AC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x807806B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807806B4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807806B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807806BC: jr          $ra
    // 0x807806C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x807806C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8079C0A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079C0A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079C0AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079C0B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8079C0B4: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x8079C0B8: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8079C0BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8079C0C0: jal         0x80045A34
    // 0x8079C0C4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8079C0C4: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x8079C0C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8079C0CC: bne         $v0, $zero, L_8079C0E4
    if (ctx->r2 != 0) {
        // 0x8079C0D0: sw          $v0, 0x1F4($a2)
        MEM_W(0X1F4, ctx->r6) = ctx->r2;
            goto L_8079C0E4;
    }
    // 0x8079C0D0: sw          $v0, 0x1F4($a2)
    MEM_W(0X1F4, ctx->r6) = ctx->r2;
    // 0x8079C0D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8079C0D8: jal         0x800445A4
    // 0x8079C0DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8079C0DC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8079C0E0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8079C0E4:
    // 0x8079C0E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079C0E8: sw          $zero, 0x130($a2)
    MEM_W(0X130, ctx->r6) = 0;
    // 0x8079C0EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8079C0F0: sb          $a1, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r5;
    // 0x8079C0F4: lui         $t7, 0x807A
    ctx->r15 = S32(RELOC_HI16(829, 0X614) << 16);
    // 0x8079C0F8: addiu       $t7, $t7, -0x427C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(829, 0X614));
    // 0x8079C0FC: sb          $a1, 0x30($a2)
    MEM_B(0X30, ctx->r6) = ctx->r5;
    // 0x8079C100: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x8079C104: lw          $v0, 0x1F4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1F4);
    // 0x8079C108: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8079C10C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8079C110:
    // 0x8079C110: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8079C114: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8079C118: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8079C11C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8079C120: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8079C124: bne         $v1, $a0, L_8079C110
    if (ctx->r3 != ctx->r4) {
        // 0x8079C128: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8079C110;
    }
    // 0x8079C128: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8079C12C: sw          $zero, 0x24($a2)
    MEM_W(0X24, ctx->r6) = 0;
    // 0x8079C130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079C134: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079C138: jr          $ra
    // 0x8079C13C: nop

    return;
    // 0x8079C13C: nop

;}
RECOMP_FUNC void func_804626D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804626D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804626DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804626E0: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x804626E4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x804626E8: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x804626EC: lui         $t8, 0x8046
    ctx->r24 = S32(RELOC_HI16(122, 0X3874) << 16);
    // 0x804626F0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804626F4: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x804626F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x804626FC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80462700: lw          $t8, 0x3E04($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(122, 0X3874));
    // 0x80462704: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80462708: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8046270C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80462710: jal         0x80048490
    // 0x80462714: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80462714: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80462718: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8046271C: jal         0x80048378
    // 0x80462720: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x80462720: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80462724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80462728: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8046272C: jr          $ra
    // 0x80462730: nop

    return;
    // 0x80462730: nop

;}
RECOMP_FUNC void func_806F864C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F864C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806F8650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806F8654: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806F8658: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x806F865C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x806F8660: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x806F8664: jal         0x800443EC
    // 0x806F8668: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800443EC(rdram, ctx);
        goto after_0;
    // 0x806F8668: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x806F866C: beq         $v0, $zero, L_806F86E4
    if (ctx->r2 == 0) {
        // 0x806F8670: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_806F86E4;
    }
    // 0x806F8670: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806F8674: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(694, 0X1B2C) << 16);
    // 0x806F8678: lwc1        $f6, -0x6CC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(694, 0X1B2C));
    // 0x806F867C: lwc1        $f4, 0x78($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X78);
    // 0x806F8680: addiu       $a0, $a1, 0x84
    ctx->r4 = ADD32(ctx->r5, 0X84);
    // 0x806F8684: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x806F8688: swc1        $f0, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->f0.u32l;
    // 0x806F868C: swc1        $f0, 0x70($a1)
    MEM_W(0X70, ctx->r5) = ctx->f0.u32l;
    // 0x806F8690: swc1        $f0, 0x6C($a1)
    MEM_W(0X6C, ctx->r5) = ctx->f0.u32l;
    // 0x806F8694: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x806F8698: lwc1        $f8, 0x84($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X84);
    // 0x806F869C: swc1        $f8, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f8.u32l;
    // 0x806F86A0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x806F86A4: swc1        $f10, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f10.u32l;
    // 0x806F86A8: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x806F86AC: swc1        $f16, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f16.u32l;
    // 0x806F86B0: jal         0x80047AB8
    // 0x806F86B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80047AB8(rdram, ctx);
        goto after_1;
    // 0x806F86B4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x806F86B8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x806F86BC: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x806F86C0: jal         0x8005FE48
    // 0x806F86C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8005FE48(rdram, ctx);
        goto after_2;
    // 0x806F86C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806F86C8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x806F86CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806F86D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806F86D4: lw          $t8, 0x174($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X174);
    // 0x806F86D8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x806F86DC: sb          $zero, 0x74($t9)
    MEM_B(0X74, ctx->r25) = 0;
    // 0x806F86E0: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
L_806F86E4:
    // 0x806F86E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806F86E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806F86EC: jr          $ra
    // 0x806F86F0: nop

    return;
    // 0x806F86F0: nop

;}
RECOMP_FUNC void func_806DF29C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF29C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806DF2A0: addiu       $t6, $zero, 0x4034
    ctx->r14 = ADD32(0, 0X4034);
    // 0x806DF2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806DF2A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x806DF2AC: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x806DF2B0: lwc1        $f4, 0x3C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x806DF2B4: lui         $at, 0x806E
    ctx->r1 = S32(RELOC_HI16(640, 0X3C0) << 16);
    // 0x806DF2B8: lwc1        $f10, -0xC40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(640, 0X3C0));
    // 0x806DF2BC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x806DF2C0: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x806DF2C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x806DF2C8: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806DF2CC: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x806DF2D0: lwc1        $f8, 0x44($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X44);
    // 0x806DF2D4: lw          $t8, -0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X76F8);
    // 0x806DF2D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x806DF2DC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806DF2E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x806DF2E4: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x806DF2E8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x806DF2EC: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x806DF2F0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x806DF2F4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x806DF2F8: lw          $t9, 0x10($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10);
    // 0x806DF2FC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x806DF300: lw          $t9, 0x54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X54);
    // 0x806DF304: jalr        $t9
    // 0x806DF308: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x806DF308: nop

    after_0:
    // 0x806DF30C: jal         0x80044658
    // 0x806DF310: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    func_80044658(rdram, ctx);
        goto after_1;
    // 0x806DF310: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x806DF314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806DF318: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x806DF31C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x806DF320: sb          $t0, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r8;
    // 0x806DF324: jr          $ra
    // 0x806DF328: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x806DF328: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_805A9768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9768: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805A976C: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805A9770: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805A9774: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805A9778: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805A977C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805A9780: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x805A9784: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805A9788: lui         $t1, 0x805B
    ctx->r9 = S32(RELOC_HI16(429, 0X1440) << 16);
    // 0x805A978C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x805A9790: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805A9794: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x805A9798: lw          $t1, -0x5EC0($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(429, 0X1440));
    // 0x805A979C: jr          $ra
    // 0x805A97A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x805A97A0: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x805A97A4: nop

    // 0x805A97A8: nop

    // 0x805A97AC: nop

;}
RECOMP_FUNC void func_806D6AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D6AF8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806D6AFC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806D6B00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806D6B04: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D6B08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D6B0C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806D6B10: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806D6B14: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(619, 0X2E8) << 16);
    // 0x806D6B18: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806D6B1C: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D6B20: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D6B24: lw          $t1, 0x6B38($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(619, 0X2E8));
    // 0x806D6B28: jr          $ra
    // 0x806D6B2C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806D6B2C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80452FDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80452FDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80452FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80452FE4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80452FE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80452FEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80452FF0: lw          $v1, 0xA50($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XA50);
    // 0x80452FF4: slti        $at, $v1, 0x158
    ctx->r1 = SIGNED(ctx->r3) < 0X158 ? 1 : 0;
    // 0x80452FF8: beq         $at, $zero, L_80453008
    if (ctx->r1 == 0) {
        // 0x80452FFC: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_80453008;
    }
    // 0x80452FFC: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80453000: b           L_80453058
    // 0x80453004: sw          $t6, 0xA50($v0)
    MEM_W(0XA50, ctx->r2) = ctx->r14;
        goto L_80453058;
    // 0x80453004: sw          $t6, 0xA50($v0)
    MEM_W(0XA50, ctx->r2) = ctx->r14;
L_80453008:
    // 0x80453008: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x8045300C: ori         $at, $at, 0x6CE0
    ctx->r1 = ctx->r1 | 0X6CE0;
    // 0x80453010: addu        $v1, $v0, $at
    ctx->r3 = ADD32(ctx->r2, ctx->r1);
    // 0x80453014: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80453018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8045301C: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80453020: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80453024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80453028: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8045302C: nop

    // 0x80453030: bc1f        L_8045304C
    if (!c1cs) {
        // 0x80453034: nop
    
            goto L_8045304C;
    }
    // 0x80453034: nop

    // 0x80453038: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8045303C: nop

    // 0x80453040: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80453044: b           L_80453058
    // 0x80453048: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_80453058;
    // 0x80453048: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_8045304C:
    // 0x8045304C: jal         0x8045297C
    // 0x80453050: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8045297C(rdram, ctx);
        goto after_0;
    // 0x80453050: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80453054: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_80453058:
    // 0x80453058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8045305C: jal         0x8044E964
    // 0x80453060: lw          $a1, 0xA50($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA50);
    func_8044E964(rdram, ctx);
        goto after_1;
    // 0x80453060: lw          $a1, 0xA50($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA50);
    after_1:
    // 0x80453064: jal         0x8044F178
    // 0x80453068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F178(rdram, ctx);
        goto after_2;
    // 0x80453068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8045306C: jal         0x8044F384
    // 0x80453070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8044F384(rdram, ctx);
        goto after_3;
    // 0x80453070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80453074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80453078: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8045307C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80453080: jr          $ra
    // 0x80453084: nop

    return;
    // 0x80453084: nop

;}
RECOMP_FUNC void func_806ED1B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806ED1B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x806ED1BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x806ED1C0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x806ED1C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806ED1C8: jal         0x80045A34
    // 0x806ED1CC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x806ED1CC: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_0:
    // 0x806ED1D0: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(676, 0X1248) << 16);
    // 0x806ED1D4: addiu       $t6, $t6, -0x2E68
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(676, 0X1248));
    // 0x806ED1D8: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x806ED1DC: bne         $v0, $zero, L_806ED1EC
    if (ctx->r2 != 0) {
        // 0x806ED1E0: sw          $t6, 0x1F8($s0)
        MEM_W(0X1F8, ctx->r16) = ctx->r14;
            goto L_806ED1EC;
    }
    // 0x806ED1E0: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
    // 0x806ED1E4: b           L_806ED288
    // 0x806ED1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED288;
    // 0x806ED1E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED1EC:
    // 0x806ED1EC: jal         0x806ED160
    // 0x806ED1F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806ED160(rdram, ctx);
        goto after_1;
    // 0x806ED1F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806ED1F4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x806ED1F8: jal         0x80058958
    // 0x806ED1FC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    func_80058958(rdram, ctx);
        goto after_2;
    // 0x806ED1FC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    after_2:
    // 0x806ED200: beq         $v0, $zero, L_806ED284
    if (ctx->r2 == 0) {
        // 0x806ED204: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_806ED284;
    }
    // 0x806ED204: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x806ED208: lw          $t8, -0x7BC4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7BC4);
    // 0x806ED20C: lw          $t9, 0x10C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X10C);
    // 0x806ED210: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x806ED214: srl         $t1, $t0, 30
    ctx->r9 = S32(U32(ctx->r8) >> 30);
    // 0x806ED218: beql        $t1, $zero, L_806ED288
    if (ctx->r9 == 0) {
        // 0x806ED21C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_806ED288;
    }
    goto skip_0;
    // 0x806ED21C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x806ED220: jal         0x80056564
    // 0x806ED224: nop

    func_80056564(rdram, ctx);
        goto after_3;
    // 0x806ED224: nop

    after_3:
    // 0x806ED228: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x806ED22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806ED230: beq         $v0, $zero, L_806ED27C
    if (ctx->r2 == 0) {
        // 0x806ED234: sw          $v0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r2;
            goto L_806ED27C;
    }
    // 0x806ED234: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x806ED238: jal         0x800457A0
    // 0x806ED23C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_4;
    // 0x806ED23C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_4:
    // 0x806ED240: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x806ED244: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x806ED248: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x806ED24C: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x806ED250: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x806ED254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x806ED258: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x806ED25C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806ED260: jal         0x80056584
    // 0x806ED264: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    func_80056584(rdram, ctx);
        goto after_5;
    // 0x806ED264: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_5:
    // 0x806ED268: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x806ED26C: lui         $t6, 0x8005
    ctx->r14 = S32(0X8005 << 16);
    // 0x806ED270: addiu       $t6, $t6, 0x784C
    ctx->r14 = ADD32(ctx->r14, 0X784C);
    // 0x806ED274: b           L_806ED284
    // 0x806ED278: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
        goto L_806ED284;
    // 0x806ED278: sw          $t6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r14;
L_806ED27C:
    // 0x806ED27C: b           L_806ED288
    // 0x806ED280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806ED288;
    // 0x806ED280: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_806ED284:
    // 0x806ED284: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_806ED288:
    // 0x806ED288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x806ED28C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x806ED290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806ED294: jr          $ra
    // 0x806ED298: nop

    return;
    // 0x806ED298: nop

;}
RECOMP_FUNC void func_80053EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053EE4: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80053EE8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80053EEC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80053EF0: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80053EF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80053EF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80053EFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80053F00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80053F04: sw          $a1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r5;
    // 0x80053F08: addiu       $s4, $a1, 0x8
    ctx->r20 = ADD32(ctx->r5, 0X8);
    // 0x80053F0C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80053F10: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80053F14: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80053F18: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80053F1C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80053F20: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80053F24: or          $s2, $s4, $zero
    ctx->r18 = ctx->r20 | 0;
    // 0x80053F28: jal         0x8004921C
    // 0x80053F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8004921C(rdram, ctx);
        goto after_0;
    // 0x80053F2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80053F30: sll         $s5, $v0, 16
    ctx->r21 = S32(ctx->r2 << 16);
    // 0x80053F34: sra         $s5, $s5, 16
    ctx->r21 = S32(SIGNED(ctx->r21) >> 16);
    // 0x80053F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80053F3C: jal         0x8004921C
    // 0x80053F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8004921C(rdram, ctx);
        goto after_1;
    // 0x80053F40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80053F44: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053F48: lh          $t7, 0x144($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X144);
    // 0x80053F4C: lw          $t9, 0x168($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X168);
    // 0x80053F50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80053F54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80053F58: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80053F5C: addiu       $ra, $s0, 0x34
    ctx->r31 = ADD32(ctx->r16, 0X34);
    // 0x80053F60: mflo        $t6
    ctx->r14 = lo;
    // 0x80053F64: nop

    // 0x80053F68: nop

    // 0x80053F6C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80053F70: lw          $t6, 0x80($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X80);
    // 0x80053F74: mflo        $t8
    ctx->r24 = lo;
    // 0x80053F78: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80053F7C: sw          $t7, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r15;
    // 0x80053F80: lwc1        $f6, 0xB4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XB4);
    // 0x80053F84: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80053F88: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80053F8C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80053F90: nop

    // 0x80053F94: bc1fl       L_80053FB8
    if (!c1cs) {
        // 0x80053F98: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80053FB8;
    }
    goto skip_0;
    // 0x80053F98: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80053F9C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80053FA0: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x80053FA4: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x80053FA8: addu        $s2, $t9, $s4
    ctx->r18 = ADD32(ctx->r25, ctx->r20);
    // 0x80053FAC: b           L_80053FB8
    // 0x80053FB0: addiu       $s2, $s2, -0x40
    ctx->r18 = ADD32(ctx->r18, -0X40);
        goto L_80053FB8;
    // 0x80053FB0: addiu       $s2, $s2, -0x40
    ctx->r18 = ADD32(ctx->r18, -0X40);
    // 0x80053FB4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80053FB8:
    // 0x80053FB8: blez        $v0, L_80054500
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80053FBC: or          $t5, $zero, $zero
        ctx->r13 = 0 | 0;
            goto L_80054500;
    }
    // 0x80053FBC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x80053FC0: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x80053FC4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80053FC8: sw          $s0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r16;
    // 0x80053FCC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80053FD0:
    // 0x80053FD0: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x80053FD4: ori         $t7, $t7, 0x103F
    ctx->r15 = ctx->r15 | 0X103F;
    // 0x80053FD8: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80053FDC: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80053FE0: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80053FE4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80053FE8: lw          $a0, 0x0($ra)
    ctx->r4 = MEM_W(ctx->r31, 0X0);
    // 0x80053FEC: lh          $v1, 0x2($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X2);
    // 0x80053FF0: lw          $a1, 0x4($ra)
    ctx->r5 = MEM_W(ctx->r31, 0X4);
    // 0x80053FF4: lh          $t9, 0x0($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X0);
    // 0x80053FF8: lh          $t8, 0x30($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X30);
    // 0x80053FFC: lh          $t6, 0x32($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X32);
    // 0x80054000: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80054004: subu        $s5, $a1, $v1
    ctx->r21 = SUB32(ctx->r5, ctx->r3);
    // 0x80054008: addu        $s4, $a0, $t9
    ctx->r20 = ADD32(ctx->r4, ctx->r25);
    // 0x8005400C: addu        $s6, $a0, $t8
    ctx->r22 = ADD32(ctx->r4, ctx->r24);
    // 0x80054010: bne         $v1, $zero, L_8005401C
    if (ctx->r3 != 0) {
        // 0x80054014: subu        $s7, $a1, $t6
        ctx->r23 = SUB32(ctx->r5, ctx->r14);
            goto L_8005401C;
    }
    // 0x80054014: subu        $s7, $a1, $t6
    ctx->r23 = SUB32(ctx->r5, ctx->r14);
    // 0x80054018: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_8005401C:
    // 0x8005401C: slti        $at, $s4, 0x140
    ctx->r1 = SIGNED(ctx->r20) < 0X140 ? 1 : 0;
    // 0x80054020: bne         $at, $zero, L_8005402C
    if (ctx->r1 != 0) {
        // 0x80054024: nop
    
            goto L_8005402C;
    }
    // 0x80054024: nop

    // 0x80054028: addiu       $s4, $zero, 0x13F
    ctx->r20 = ADD32(0, 0X13F);
L_8005402C:
    // 0x8005402C: bgez        $s4, L_8005403C
    if (SIGNED(ctx->r20) >= 0) {
        // 0x80054030: slti        $at, $s6, 0x140
        ctx->r1 = SIGNED(ctx->r22) < 0X140 ? 1 : 0;
            goto L_8005403C;
    }
    // 0x80054030: slti        $at, $s6, 0x140
    ctx->r1 = SIGNED(ctx->r22) < 0X140 ? 1 : 0;
    // 0x80054034: negu        $t4, $s4
    ctx->r12 = SUB32(0, ctx->r20);
    // 0x80054038: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8005403C:
    // 0x8005403C: bne         $at, $zero, L_80054048
    if (ctx->r1 != 0) {
        // 0x80054040: nop
    
            goto L_80054048;
    }
    // 0x80054040: nop

    // 0x80054044: addiu       $s6, $zero, 0x13F
    ctx->r22 = ADD32(0, 0X13F);
L_80054048:
    // 0x80054048: bgez        $s6, L_80054054
    if (SIGNED(ctx->r22) >= 0) {
        // 0x8005404C: slti        $at, $s5, 0xF0
        ctx->r1 = SIGNED(ctx->r21) < 0XF0 ? 1 : 0;
            goto L_80054054;
    }
    // 0x8005404C: slti        $at, $s5, 0xF0
    ctx->r1 = SIGNED(ctx->r21) < 0XF0 ? 1 : 0;
    // 0x80054050: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_80054054:
    // 0x80054054: bnel        $at, $zero, L_80054064
    if (ctx->r1 != 0) {
        // 0x80054058: slti        $at, $s7, 0xF0
        ctx->r1 = SIGNED(ctx->r23) < 0XF0 ? 1 : 0;
            goto L_80054064;
    }
    goto skip_1;
    // 0x80054058: slti        $at, $s7, 0xF0
    ctx->r1 = SIGNED(ctx->r23) < 0XF0 ? 1 : 0;
    skip_1:
    // 0x8005405C: addiu       $s5, $zero, 0xEF
    ctx->r21 = ADD32(0, 0XEF);
    // 0x80054060: slti        $at, $s7, 0xF0
    ctx->r1 = SIGNED(ctx->r23) < 0XF0 ? 1 : 0;
L_80054064:
    // 0x80054064: bne         $at, $zero, L_80054070
    if (ctx->r1 != 0) {
        // 0x80054068: nop
    
            goto L_80054070;
    }
    // 0x80054068: nop

    // 0x8005406C: addiu       $s7, $zero, 0xEF
    ctx->r23 = ADD32(0, 0XEF);
L_80054070:
    // 0x80054070: bgez        $s5, L_8005407C
    if (SIGNED(ctx->r21) >= 0) {
        // 0x80054074: nop
    
            goto L_8005407C;
    }
    // 0x80054074: nop

    // 0x80054078: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8005407C:
    // 0x8005407C: bgez        $s7, L_80054088
    if (SIGNED(ctx->r23) >= 0) {
        // 0x80054080: nop
    
            goto L_80054088;
    }
    // 0x80054080: nop

    // 0x80054084: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
L_80054088:
    // 0x80054088: beql        $s4, $s6, L_800544E4
    if (ctx->r20 == ctx->r22) {
        // 0x8005408C: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800544E4;
    }
    goto skip_2;
    // 0x8005408C: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_2:
    // 0x80054090: beq         $s5, $s7, L_800544E0
    if (ctx->r21 == ctx->r23) {
        // 0x80054094: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800544E0;
    }
    // 0x80054094: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80054098: lw          $s3, 0x0($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X0);
    // 0x8005409C: lui         $fp, 0xF00
    ctx->r30 = S32(0XF00 << 16);
    // 0x800540A0: addiu       $fp, $fp, 0x0
    ctx->r30 = ADD32(ctx->r30, 0X0);
    // 0x800540A4: addiu       $t7, $s3, 0x8
    ctx->r15 = ADD32(ctx->r19, 0X8);
    // 0x800540A8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800540AC: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x800540B0: sw          $t5, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r13;
    // 0x800540B4: sw          $t4, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r12;
    // 0x800540B8: jal         0x8004921C
    // 0x800540BC: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    func_8004921C(rdram, ctx);
        goto after_2;
    // 0x800540BC: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    after_2:
    // 0x800540C0: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x800540C4: addiu       $t6, $t8, -0x1
    ctx->r14 = ADD32(ctx->r24, -0X1);
    // 0x800540C8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x800540CC: lui         $at, 0xFD88
    ctx->r1 = S32(0XFD88 << 16);
    // 0x800540D0: lw          $t4, 0xB4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB4);
    // 0x800540D4: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800540D8: lw          $t5, 0xC8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC8);
    // 0x800540DC: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x800540E0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800540E4: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800540E8: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x800540EC: lui         $t3, 0xF200
    ctx->r11 = S32(0XF200 << 16);
    // 0x800540F0: sw          $t8, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r24;
    // 0x800540F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800540F8: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x800540FC: subu        $a0, $s6, $s4
    ctx->r4 = SUB32(ctx->r22, ctx->r20);
    // 0x80054100: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80054104: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80054108: lh          $t7, 0x38($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X38);
    // 0x8005410C: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x80054110: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80054114: sra         $t9, $t7, 6
    ctx->r25 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80054118: sra         $t6, $t8, 6
    ctx->r14 = S32(SIGNED(ctx->r24) >> 6);
    // 0x8005411C: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x80054120: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80054124: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80054128: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x8005412C: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80054130: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x80054134: sll         $t9, $t8, 9
    ctx->r25 = S32(ctx->r24 << 9);
    // 0x80054138: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8005413C: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80054140: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80054144: ori         $t7, $t6, 0x190
    ctx->r15 = ctx->r14 | 0X190;
    // 0x80054148: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005414C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80054150: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054154: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x80054158: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x8005415C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80054160: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80054164: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80054168: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005416C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054170: addiu       $a0, $a0, 0x7
    ctx->r4 = ADD32(ctx->r4, 0X7);
    // 0x80054174: sra         $a0, $a0, 3
    ctx->r4 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80054178: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x8005417C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80054180: lh          $t8, 0xA($s2)
    ctx->r24 = MEM_H(ctx->r18, 0XA);
    // 0x80054184: andi        $a0, $a0, 0x1FF
    ctx->r4 = ctx->r4 & 0X1FF;
    // 0x80054188: sll         $a0, $a0, 9
    ctx->r4 = S32(ctx->r4 << 9);
    // 0x8005418C: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80054190: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80054194: lh          $t9, 0x8($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X8);
    // 0x80054198: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8005419C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800541A0: sra         $t6, $t9, 6
    ctx->r14 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800541A4: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800541A8: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800541AC: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800541B0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x800541B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800541B8: lh          $t9, 0x3A($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3A);
    // 0x800541BC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800541C0: addiu       $t0, $s6, -0x1
    ctx->r8 = ADD32(ctx->r22, -0X1);
    // 0x800541C4: sra         $t8, $t9, 6
    ctx->r24 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800541C8: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800541CC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800541D0: lh          $t6, 0x38($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X38);
    // 0x800541D4: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x800541D8: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x800541DC: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x800541E0: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x800541E4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800541E8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800541EC: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800541F0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800541F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800541F8: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800541FC: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x80054200: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80054204: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80054208: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8005420C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054210: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054214: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80054218: andi        $t0, $t0, 0xFFF
    ctx->r8 = ctx->r8 & 0XFFF;
    // 0x8005421C: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80054220: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80054224: lh          $t9, 0x38($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X38);
    // 0x80054228: lh          $t8, 0x8($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X8);
    // 0x8005422C: sll         $t0, $t0, 12
    ctx->r8 = S32(ctx->r8 << 12);
    // 0x80054230: sra         $t6, $t9, 6
    ctx->r14 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80054234: sra         $t7, $t8, 6
    ctx->r15 = S32(SIGNED(ctx->r24) >> 6);
    // 0x80054238: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x8005423C: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80054240: sra         $t6, $t8, 1
    ctx->r14 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80054244: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80054248: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8005424C: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80054250: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x80054254: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80054258: lui         $t8, 0x108
    ctx->r24 = S32(0X108 << 16);
    // 0x8005425C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80054260: ori         $t9, $t7, 0x190
    ctx->r25 = ctx->r15 | 0X190;
    // 0x80054264: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80054268: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8005426C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054270: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x80054274: or          $a0, $a0, $at
    ctx->r4 = ctx->r4 | ctx->r1;
    // 0x80054278: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8005427C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80054280: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x80054284: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x80054288: sll         $a3, $s5, 2
    ctx->r7 = S32(ctx->r21 << 2);
    // 0x8005428C: sra         $t9, $t7, 6
    ctx->r25 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80054290: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80054294: lh          $t9, 0x8($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X8);
    // 0x80054298: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8005429C: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800542A0: sra         $t8, $t9, 6
    ctx->r24 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800542A4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800542A8: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800542AC: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x800542B0: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800542B4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800542B8: lh          $t9, 0x3A($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3A);
    // 0x800542BC: sll         $t1, $s7, 2
    ctx->r9 = S32(ctx->r23 << 2);
    // 0x800542C0: andi        $t1, $t1, 0xFFF
    ctx->r9 = ctx->r9 & 0XFFF;
    // 0x800542C4: sra         $t7, $t9, 6
    ctx->r15 = S32(SIGNED(ctx->r25) >> 6);
    // 0x800542C8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800542CC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800542D0: lh          $t8, 0x38($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X38);
    // 0x800542D4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800542D8: or          $t7, $t9, $a2
    ctx->r15 = ctx->r25 | ctx->r6;
    // 0x800542DC: sra         $t6, $t8, 6
    ctx->r14 = S32(SIGNED(ctx->r24) >> 6);
    // 0x800542E0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x800542E4: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800542E8: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x800542EC: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x800542F0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800542F4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800542F8: andi        $a3, $a3, 0xFFF
    ctx->r7 = ctx->r7 & 0XFFF;
    // 0x800542FC: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80054300: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80054304: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x80054308: sra         $t6, $t7, 6
    ctx->r14 = S32(SIGNED(ctx->r15) >> 6);
    // 0x8005430C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80054310: lh          $t6, 0x8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X8);
    // 0x80054314: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80054318: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x8005431C: sra         $t9, $t6, 6
    ctx->r25 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80054320: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80054324: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80054328: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8005432C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80054330: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80054334: lh          $t6, 0x3A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X3A);
    // 0x80054338: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x8005433C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80054340: lh          $t7, 0x38($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X38);
    // 0x80054344: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80054348: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8005434C: sra         $t9, $t7, 6
    ctx->r25 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80054350: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80054354: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80054358: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8005435C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80054360: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80054364: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054368: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8005436C: ori         $t6, $t6, 0x13F
    ctx->r14 = ctx->r14 | 0X13F;
    // 0x80054370: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80054374: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80054378: sw          $fp, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r30;
    // 0x8005437C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054380: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054384: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80054388: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x8005438C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80054390: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80054394: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80054398: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x8005439C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800543A0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800543A4: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
    // 0x800543A8: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800543AC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800543B0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800543B4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800543B8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800543BC: andi        $a2, $a2, 0xFFF
    ctx->r6 = ctx->r6 & 0XFFF;
    // 0x800543C0: sll         $a2, $a2, 12
    ctx->r6 = S32(ctx->r6 << 12);
    // 0x800543C4: or          $t8, $a2, $at
    ctx->r24 = ctx->r6 | ctx->r1;
    // 0x800543C8: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800543CC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800543D0: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800543D4: or          $t6, $t0, $at
    ctx->r14 = ctx->r8 | ctx->r1;
    // 0x800543D8: or          $t9, $t6, $t1
    ctx->r25 = ctx->r14 | ctx->r9;
    // 0x800543DC: or          $t7, $t8, $a3
    ctx->r15 = ctx->r24 | ctx->r7;
    // 0x800543E0: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800543E4: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800543E8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800543EC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800543F0: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800543F4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800543F8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800543FC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80054400: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054404: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054408: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x8005440C: or          $t7, $a2, $t3
    ctx->r15 = ctx->r6 | ctx->r11;
    // 0x80054410: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80054414: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80054418: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8005441C: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80054420: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054424: or          $t9, $t0, $t1
    ctx->r25 = ctx->r8 | ctx->r9;
    // 0x80054428: or          $t6, $t7, $a3
    ctx->r14 = ctx->r15 | ctx->r7;
    // 0x8005442C: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80054430: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80054434: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80054438: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005443C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80054440: lui         $a0, 0xBF00
    ctx->r4 = S32(0XBF00 << 16);
    // 0x80054444: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80054448: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8005444C: lh          $t7, 0xA($s2)
    ctx->r15 = MEM_H(ctx->r18, 0XA);
    // 0x80054450: sra         $t6, $t7, 6
    ctx->r14 = S32(SIGNED(ctx->r15) >> 6);
    // 0x80054454: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80054458: lh          $t6, 0x8($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X8);
    // 0x8005445C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80054460: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x80054464: sra         $t9, $t6, 6
    ctx->r25 = S32(SIGNED(ctx->r14) >> 6);
    // 0x80054468: addu        $t8, $t9, $t4
    ctx->r24 = ADD32(ctx->r25, ctx->r12);
    // 0x8005446C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80054470: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80054474: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80054478: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8005447C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80054480: lh          $t9, 0x3A($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X3A);
    // 0x80054484: sra         $t7, $t9, 6
    ctx->r15 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80054488: lh          $t9, 0x38($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X38);
    // 0x8005448C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80054490: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80054494: sra         $t7, $t9, 6
    ctx->r15 = S32(SIGNED(ctx->r25) >> 6);
    // 0x80054498: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005449C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800544A0: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x800544A4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800544A8: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800544AC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800544B0: addiu       $t6, $zero, 0x204
    ctx->r14 = ADD32(0, 0X204);
    // 0x800544B4: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x800544B8: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800544BC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800544C0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800544C4: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x800544C8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800544CC: ori         $t8, $t8, 0x604
    ctx->r24 = ctx->r24 | 0X604;
    // 0x800544D0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800544D4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800544D8: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800544DC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
L_800544E0:
    // 0x800544E0: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800544E4:
    // 0x800544E4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800544E8: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800544EC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800544F0: addu        $s2, $s2, $t9
    ctx->r18 = ADD32(ctx->r18, ctx->r25);
    // 0x800544F4: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800544F8: bnel        $at, $zero, L_80053FD0
    if (ctx->r1 != 0) {
        // 0x800544FC: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80053FD0;
    }
    goto skip_3;
    // 0x800544FC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_3:
L_80054500:
    // 0x80054500: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80054504: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80054508: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005450C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80054510: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80054514: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80054518: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8005451C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80054520: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80054524: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80054528: jr          $ra
    // 0x8005452C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x8005452C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void func_8003420C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003420C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80034210: lbu         $t6, -0x766B($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X766B);
    // 0x80034214: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80034218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003421C: bne         $t6, $zero, L_8003423C
    if (ctx->r14 != 0) {
        // 0x80034220: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_8003423C;
    }
    // 0x80034220: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80034224: jal         0x8002DB14
    // 0x80034228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x80034228: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003422C: jal         0x80034160
    // 0x80034230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80034160(rdram, ctx);
        goto after_1;
    // 0x80034230: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80034234: b           L_800342B0
    // 0x80034238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800342B0;
    // 0x80034238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8003423C:
    // 0x8003423C: lbu         $t7, 0xF5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF5);
    // 0x80034240: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80034244: lwc1        $f0, 0xC8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80034248: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003424C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80034250: lwc1        $f2, -0x157C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X157C);
    // 0x80034254: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034258: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8003425C: nop

    // 0x80034260: bc1f        L_80034278
    if (!c1cs) {
        // 0x80034264: nop
    
            goto L_80034278;
    }
    // 0x80034264: nop

    // 0x80034268: lbu         $t9, 0xF6($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF6);
    // 0x8003426C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80034270: b           L_800342A8
    // 0x80034274: sb          $t0, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r8;
        goto L_800342A8;
    // 0x80034274: sb          $t0, 0xF6($v0)
    MEM_B(0XF6, ctx->r2) = ctx->r8;
L_80034278:
    // 0x80034278: lwc1        $f4, 0x9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9C);
    // 0x8003427C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034280: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80034284: nop

    // 0x80034288: bc1f        L_800342A0
    if (!c1cs) {
        // 0x8003428C: nop
    
            goto L_800342A0;
    }
    // 0x8003428C: nop

    // 0x80034290: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80034294: lwc1        $f6, 0xA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA0);
    // 0x80034298: b           L_800342A8
    // 0x8003429C: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
        goto L_800342A8;
    // 0x8003429C: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
L_800342A0:
    // 0x800342A0: lwc1        $f8, 0xA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA4);
    // 0x800342A4: swc1        $f8, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f8.u32l;
L_800342A8:
    // 0x800342A8: swc1        $f2, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f2.u32l;
    // 0x800342AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800342B0:
    // 0x800342B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800342B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800342B8: jr          $ra
    // 0x800342BC: nop

    return;
    // 0x800342BC: nop

;}
RECOMP_FUNC void func_800325F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800325F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800325FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80032600: lw          $a2, 0x164($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X164);
    // 0x80032604: beql        $a2, $zero, L_80032620
    if (ctx->r6 == 0) {
        // 0x80032608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80032620;
    }
    goto skip_0;
    // 0x80032608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8003260C: jal         0x800324C8
    // 0x80032610: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    func_800324C8(rdram, ctx);
        goto after_0;
    // 0x80032610: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x80032614: jal         0x8003E240
    // 0x80032618: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8003E240(rdram, ctx);
        goto after_1;
    // 0x80032618: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8003261C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80032620:
    // 0x80032620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80032624: jr          $ra
    // 0x80032628: nop

    return;
    // 0x80032628: nop

;}
RECOMP_FUNC void func_805AC77C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805AC77C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805AC780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805AC784: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805AC788: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x805AC78C: beql        $v0, $zero, L_805AC7D4
    if (ctx->r2 == 0) {
        // 0x805AC790: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC7D4;
    }
    goto skip_0;
    // 0x805AC790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x805AC794: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x805AC798: beql        $a0, $zero, L_805AC7D4
    if (ctx->r4 == 0) {
        // 0x805AC79C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC7D4;
    }
    goto skip_1;
    // 0x805AC79C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x805AC7A0: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x805AC7A4: bnel        $a1, $t6, L_805AC7D4
    if (ctx->r5 != ctx->r14) {
        // 0x805AC7A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_805AC7D4;
    }
    goto skip_2;
    // 0x805AC7A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x805AC7AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805AC7B0: jal         0x8004816C
    // 0x805AC7B4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_8004816C(rdram, ctx);
        goto after_0;
    // 0x805AC7B4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x805AC7B8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x805AC7BC: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x805AC7C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805AC7C4: addiu       $t7, $t7, -0x7218
    ctx->r15 = ADD32(ctx->r15, -0X7218);
    // 0x805AC7C8: jal         0x80048C00
    // 0x805AC7CC: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    func_80048C00(rdram, ctx);
        goto after_1;
    // 0x805AC7CC: sw          $t7, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r15;
    after_1:
    // 0x805AC7D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_805AC7D4:
    // 0x805AC7D4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x805AC7D8: jr          $ra
    // 0x805AC7DC: nop

    return;
    // 0x805AC7DC: nop

;}
RECOMP_FUNC void func_804E9970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804E9970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804E9974: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x804E9978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804E997C: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(264, 0X910) << 16);
    // 0x804E9980: lui         $a1, 0x804F
    ctx->r5 = S32(RELOC_HI16(264, 0X920) << 16);
    // 0x804E9984: addiu       $a1, $a1, -0x5D70
    ctx->r5 = ADD32(ctx->r5, (int16_t)RELOC_LO16(264, 0X920));
    // 0x804E9988: addiu       $a0, $a0, -0x5D80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(264, 0X910));
    // 0x804E998C: jal         0x8004667C
    // 0x804E9990: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8004667C(rdram, ctx);
        goto after_0;
    // 0x804E9990: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_0:
    // 0x804E9994: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x804E9998: lw          $a0, -0x76F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X76F8);
    // 0x804E999C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x804E99A0: lui         $a2, 0x804F
    ctx->r6 = S32(RELOC_HI16(264, 0X694) << 16);
    // 0x804E99A4: lw          $t6, 0x10($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X10);
    // 0x804E99A8: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x804E99AC: bnel        $t7, $zero, L_804E99C0
    if (ctx->r15 != 0) {
        // 0x804E99B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804E99C0;
    }
    goto skip_0;
    // 0x804E99B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804E99B4: jal         0x80057B28
    // 0x804E99B8: addiu       $a2, $a2, -0x5FFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(264, 0X694));
    func_80057B28(rdram, ctx);
        goto after_1;
    // 0x804E99B8: addiu       $a2, $a2, -0x5FFC
    ctx->r6 = ADD32(ctx->r6, (int16_t)RELOC_LO16(264, 0X694));
    after_1:
    // 0x804E99BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804E99C0:
    // 0x804E99C0: lui         $v0, 0x804F
    ctx->r2 = S32(RELOC_HI16(264, 0X60) << 16);
    // 0x804E99C4: addiu       $v0, $v0, -0x6630
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(264, 0X60));
    // 0x804E99C8: jr          $ra
    // 0x804E99CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804E99CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8075F198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F198: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x8075F19C: lui         $t6, 0x8076
    ctx->r14 = S32(RELOC_HI16(757, 0X3A8) << 16);
    // 0x8075F1A0: addiu       $t6, $t6, -0xF08
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(757, 0X3A8));
    // 0x8075F1A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8075F1A8: jr          $ra
    // 0x8075F1AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x8075F1AC: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_806A9E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A9E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806A9E2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806A9E30: jal         0x806A98AC
    // 0x806A9E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_806A98AC(rdram, ctx);
        goto after_0;
    // 0x806A9E34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x806A9E38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x806A9E3C: bne         $v0, $at, L_806A9E54
    if (ctx->r2 != ctx->r1) {
        // 0x806A9E40: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_806A9E54;
    }
    // 0x806A9E40: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x806A9E44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806A9E48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806A9E4C: jal         0x806AA784
    // 0x806A9E50: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    func_806AA784(rdram, ctx);
        goto after_1;
    // 0x806A9E50: lw          $a3, 0x12C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X12C);
    after_1:
L_806A9E54:
    // 0x806A9E54: jal         0x806A9CD8
    // 0x806A9E58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_806A9CD8(rdram, ctx);
        goto after_2;
    // 0x806A9E58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x806A9E5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806A9E60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806A9E64: jr          $ra
    // 0x806A9E68: nop

    return;
    // 0x806A9E68: nop

;}
RECOMP_FUNC void func_807B9484(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9484: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B9488: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B948C: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B9490: lw          $t6, 0x20($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X20);
    // 0x807B9494: lw          $a1, 0x16C($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X16C);
    // 0x807B9498: lbu         $v0, 0x10($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X10);
    // 0x807B949C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807B94A0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x807B94A4: jal         0x807B8D30
    // 0x807B94A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_807B8D30(rdram, ctx);
        goto after_0;
    // 0x807B94A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x807B94AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x807B94B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x807B94B4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x807B94B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x807B94BC: slti        $at, $v0, 0x100
    ctx->r1 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x807B94C0: bne         $at, $zero, L_807B94F0
    if (ctx->r1 != 0) {
        // 0x807B94C4: addiu       $t7, $zero, 0xFF
        ctx->r15 = ADD32(0, 0XFF);
            goto L_807B94F0;
    }
    // 0x807B94C4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x807B94C8: jal         0x807B9390
    // 0x807B94CC: sb          $t7, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r15;
    func_807B9390(rdram, ctx);
        goto after_1;
    // 0x807B94CC: sb          $t7, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r15;
    after_1:
    // 0x807B94D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x807B94D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x807B94D8: jal         0x8006E0FC
    // 0x807B94DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_8006E0FC(rdram, ctx);
        goto after_2;
    // 0x807B94DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x807B94E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x807B94E4: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x807B94E8: b           L_807B94F4
    // 0x807B94EC: sw          $t8, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r24;
        goto L_807B94F4;
    // 0x807B94EC: sw          $t8, -0x7200($at)
    MEM_W(-0X7200, ctx->r1) = ctx->r24;
L_807B94F0:
    // 0x807B94F0: sb          $v0, 0x10($a1)
    MEM_B(0X10, ctx->r5) = ctx->r2;
L_807B94F4:
    // 0x807B94F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807B94F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807B94FC: jr          $ra
    // 0x807B9500: nop

    return;
    // 0x807B9500: nop

;}
RECOMP_FUNC void func_80400A24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80400A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80400A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80400A2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80400A30: jal         0x80045A34
    // 0x80400A34: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80400A34: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    after_0:
    // 0x80400A38: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80400A3C: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    // 0x80400A40: bne         $v0, $zero, L_80400A50
    if (ctx->r2 != 0) {
        // 0x80400A44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80400A50;
    }
    // 0x80400A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80400A48: b           L_80400A54
    // 0x80400A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80400A54;
    // 0x80400A4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80400A50:
    // 0x80400A50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80400A54:
    // 0x80400A54: jr          $ra
    // 0x80400A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80400A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806B264C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B264C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2650: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2654: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2658: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B265C: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2660: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2664: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2668: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B266C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2670: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2674: jr          $ra
    // 0x806B2678: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2678: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804BBA18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BBA18: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BBA1C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BBA20: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BBA24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BBA28: jal         0x80051194
    // 0x804BBA2C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    func_80051194(rdram, ctx);
        goto after_0;
    // 0x804BBA2C: lhu         $a0, 0xC($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XC);
    after_0:
    // 0x804BBA30: sw          $v0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->r2;
    // 0x804BBA34: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(191, 0X3F54) << 16);
    // 0x804BBA38: lw          $t6, -0x77C($t6)
    ctx->r14 = MEM_W(ctx->r14, (int16_t)RELOC_LO16(191, 0X3F54));
    // 0x804BBA3C: lui         $a0, 0x804C
    ctx->r4 = S32(RELOC_HI16(191, 0X3F58) << 16);
    // 0x804BBA40: addiu       $a0, $a0, -0x778
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(191, 0X3F58));
    // 0x804BBA44: bne         $t6, $zero, L_804BBA54
    if (ctx->r14 != 0) {
        // 0x804BBA48: nop
    
            goto L_804BBA54;
    }
    // 0x804BBA48: nop

    // 0x804BBA4C: jal         0x80066AD8
    // 0x804BBA50: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    func_80066AD8(rdram, ctx);
        goto after_1;
    // 0x804BBA50: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_1:
L_804BBA54:
    // 0x804BBA54: jal         0x804BBB38
    // 0x804BBA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BBB38(rdram, ctx);
        goto after_2;
    // 0x804BBA58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x804BBA5C: beql        $v0, $zero, L_804BBB00
    if (ctx->r2 == 0) {
        // 0x804BBA60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804BBB00;
    }
    goto skip_0;
    // 0x804BBA60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804BBA64: jal         0x804BBB80
    // 0x804BBA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BBB80(rdram, ctx);
        goto after_3;
    // 0x804BBA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x804BBA6C: lw          $t8, 0x1F4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1F4);
    // 0x804BBA70: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X3F54) << 16);
    // 0x804BBA74: addiu       $t7, $t7, -0x77C
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X3F54));
    // 0x804BBA78: sw          $t7, 0x35C($t8)
    MEM_W(0X35C, ctx->r24) = ctx->r15;
    // 0x804BBA7C: lw          $t9, 0x1F4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1F4);
    // 0x804BBA80: lui         $t2, 0x804C
    ctx->r10 = S32(RELOC_HI16(191, 0X3F28) << 16);
    // 0x804BBA84: addiu       $t2, $t2, -0x7A8
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(191, 0X3F28));
    // 0x804BBA88: lw          $v0, 0x35C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X35C);
    // 0x804BBA8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BBA90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BBA94: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x804BBA98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BBA9C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x804BBAA0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x804BBAA4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x804BBAA8: lw          $t3, 0x16C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X16C);
    // 0x804BBAAC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804BBAB0: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804BBAB4: sw          $t2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r10;
    // 0x804BBAB8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804BBABC: jal         0x804BCEF4
    // 0x804BBAC0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    func_804BCEF4(rdram, ctx);
        goto after_4;
    // 0x804BBAC0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    after_4:
    // 0x804BBAC4: lw          $t5, 0x16C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X16C);
    // 0x804BBAC8: lui         $t4, 0x804C
    ctx->r12 = S32(RELOC_HI16(191, 0X91C) << 16);
    // 0x804BBACC: addiu       $t4, $t4, -0x3DB4
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(191, 0X91C));
    // 0x804BBAD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BBAD4: jal         0x804BB9D8
    // 0x804BBAD8: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    func_804BB9D8(rdram, ctx);
        goto after_5;
    // 0x804BBAD8: sw          $t4, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->r12;
    after_5:
    // 0x804BBADC: jal         0x804BCF58
    // 0x804BBAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BCF58(rdram, ctx);
        goto after_6;
    // 0x804BBAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x804BBAE4: bne         $v0, $zero, L_804BBAF4
    if (ctx->r2 != 0) {
        // 0x804BBAE8: nop
    
            goto L_804BBAF4;
    }
    // 0x804BBAE8: nop

    // 0x804BBAEC: b           L_804BBB00
    // 0x804BBAF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804BBB00;
    // 0x804BBAF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BBAF4:
    // 0x804BBAF4: b           L_804BBB00
    // 0x804BBAF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BBB00;
    // 0x804BBAF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x804BBAFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BBB00:
    // 0x804BBB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804BBB04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BBB08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BBB0C: jr          $ra
    // 0x804BBB10: nop

    return;
    // 0x804BBB10: nop

;}
RECOMP_FUNC void func_805C7C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C7C2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805C7C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C7C34: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C7C38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C7C3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C7C40: jal         0x8004700C
    // 0x805C7C44: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x805C7C44: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C7C48: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7C4C: beq         $v0, $zero, L_805C812C
    if (ctx->r2 == 0) {
        // 0x805C7C50: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_805C812C;
    }
    // 0x805C7C50: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x805C7C54: lw          $v0, 0x40($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X40);
    // 0x805C7C58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7C5C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x805C7C60: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x805C7C64: bne         $at, $zero, L_805C7C74
    if (ctx->r1 != 0) {
        // 0x805C7C68: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805C7C74;
    }
    // 0x805C7C68: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805C7C6C: sw          $t6, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r14;
    // 0x805C7C70: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_805C7C74:
    // 0x805C7C74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805C7C78: bne         $v0, $at, L_805C7CA0
    if (ctx->r2 != ctx->r1) {
        // 0x805C7C7C: lui         $a2, 0x4080
        ctx->r6 = S32(0X4080 << 16);
            goto L_805C7CA0;
    }
    // 0x805C7C7C: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x805C7C80: jal         0x8002FCBC
    // 0x805C7C84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_8002FCBC(rdram, ctx);
        goto after_1;
    // 0x805C7C84: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x805C7C88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7C8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C7C90: jal         0x805C9D10
    // 0x805C7C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_805C9D10(rdram, ctx);
        goto after_2;
    // 0x805C7C94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x805C7C98: b           L_805C8130
    // 0x805C7C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C8130;
    // 0x805C7C9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C7CA0:
    // 0x805C7CA0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x805C7CA4: jal         0x805C70B0
    // 0x805C7CA8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    func_805C70B0(rdram, ctx);
        goto after_3;
    // 0x805C7CA8: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_3:
    // 0x805C7CAC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x805C7CB0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x805C7CB4: lw          $t7, 0x478($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X478);
    // 0x805C7CB8: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805C7CBC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x805C7CC0: lwc1        $f6, 0x30($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X30);
    // 0x805C7CC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C7CC8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7CCC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x805C7CD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7CD4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C7CD8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x805C7CDC: nop

    // 0x805C7CE0: bc1fl       L_805C7D50
    if (!c1cs) {
        // 0x805C7CE4: lw          $t0, 0x28($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X28);
            goto L_805C7D50;
    }
    goto skip_0;
    // 0x805C7CE4: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
    skip_0:
    // 0x805C7CE8: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C7CEC: jal         0x805C6E30
    // 0x805C7CF0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_805C6E30(rdram, ctx);
        goto after_4;
    // 0x805C7CF0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_4:
    // 0x805C7CF4: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x805C7CF8: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x805C7CFC: bne         $v0, $zero, L_805C7D84
    if (ctx->r2 != 0) {
        // 0x805C7D00: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805C7D84;
    }
    // 0x805C7D00: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7D04: lw          $t8, 0x478($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X478);
    // 0x805C7D08: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C7D0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x805C7D10: lwc1        $f16, 0x30($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X30);
    // 0x805C7D14: lui         $at, 0xC090
    ctx->r1 = S32(0XC090 << 16);
    // 0x805C7D18: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C7D1C: nop

    // 0x805C7D20: bc1fl       L_805C7D40
    if (!c1cs) {
        // 0x805C7D24: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_805C7D40;
    }
    goto skip_1;
    // 0x805C7D24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_1:
    // 0x805C7D28: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x805C7D2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C7D30: sw          $t9, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r25;
    // 0x805C7D34: b           L_805C7D84
    // 0x805C7D38: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
        goto L_805C7D84;
    // 0x805C7D38: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x805C7D3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_805C7D40:
    // 0x805C7D40: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x805C7D44: b           L_805C7D84
    // 0x805C7D48: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
        goto L_805C7D84;
    // 0x805C7D48: swc1        $f4, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f4.u32l;
    // 0x805C7D4C: lw          $t0, 0x28($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X28);
L_805C7D50:
    // 0x805C7D50: beql        $t0, $zero, L_805C7D88
    if (ctx->r8 == 0) {
        // 0x805C7D54: addiu       $a3, $s0, 0xC4
        ctx->r7 = ADD32(ctx->r16, 0XC4);
            goto L_805C7D88;
    }
    goto skip_2;
    // 0x805C7D54: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
    skip_2:
    // 0x805C7D58: lw          $t1, 0x138($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X138);
    // 0x805C7D5C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x805C7D60: bnel        $t1, $zero, L_805C7D7C
    if (ctx->r9 != 0) {
        // 0x805C7D64: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_805C7D7C;
    }
    goto skip_3;
    // 0x805C7D64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x805C7D68: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x805C7D6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C7D70: b           L_805C7D84
    // 0x805C7D74: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
        goto L_805C7D84;
    // 0x805C7D74: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
    // 0x805C7D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_805C7D7C:
    // 0x805C7D7C: nop

    // 0x805C7D80: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
L_805C7D84:
    // 0x805C7D84: addiu       $a3, $s0, 0xC4
    ctx->r7 = ADD32(ctx->r16, 0XC4);
L_805C7D88:
    // 0x805C7D88: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x805C7D8C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x805C7D90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805C7D94: jal         0x80048F84
    // 0x805C7D98: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_80048F84(rdram, ctx);
        goto after_5;
    // 0x805C7D98: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_5:
    // 0x805C7D9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805C7DA0: jal         0x80048F84
    // 0x805C7DA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_6;
    // 0x805C7DA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x805C7DA8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7DAC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x805C7DB0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x805C7DB4: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x805C7DB8: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805C7DBC: beq         $a0, $zero, L_805C7DC8
    if (ctx->r4 == 0) {
        // 0x805C7DC0: addiu       $t2, $a0, -0x1
        ctx->r10 = ADD32(ctx->r4, -0X1);
            goto L_805C7DC8;
    }
    // 0x805C7DC0: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x805C7DC4: sw          $t2, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r10;
L_805C7DC8:
    // 0x805C7DC8: lw          $t3, 0x478($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X478);
    // 0x805C7DCC: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C7DD0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x805C7DD4: lwc1        $f16, 0x30($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X30);
    // 0x805C7DD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C7DDC: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x805C7DE0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x805C7DE4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x805C7DE8: nop

    // 0x805C7DEC: bc1fl       L_805C7FA0
    if (!c1cs) {
        // 0x805C7DF0: lw          $t6, 0x24($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X24);
            goto L_805C7FA0;
    }
    goto skip_4;
    // 0x805C7DF0: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
    skip_4:
    // 0x805C7DF4: sw          $zero, 0x24($v1)
    MEM_W(0X24, ctx->r3) = 0;
    // 0x805C7DF8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x805C7DFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7E00: lw          $t5, 0x1F4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1F4);
    // 0x805C7E04: lbu         $t6, 0x111($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X111);
    // 0x805C7E08: beql        $t6, $zero, L_805C7E88
    if (ctx->r14 == 0) {
        // 0x805C7E0C: lw          $t0, 0x34($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X34);
            goto L_805C7E88;
    }
    goto skip_5;
    // 0x805C7E0C: lw          $t0, 0x34($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X34);
    skip_5:
    // 0x805C7E10: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x805C7E14: jal         0x805C6E30
    // 0x805C7E18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_805C6E30(rdram, ctx);
        goto after_7;
    // 0x805C7E18: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_7:
    // 0x805C7E1C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7E20: bne         $v0, $zero, L_805C7E84
    if (ctx->r2 != 0) {
        // 0x805C7E24: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805C7E84;
    }
    // 0x805C7E24: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805C7E28: lw          $t7, 0x24($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X24);
    // 0x805C7E2C: bnel        $t7, $zero, L_805C7E88
    if (ctx->r15 != 0) {
        // 0x805C7E30: lw          $t0, 0x34($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X34);
            goto L_805C7E88;
    }
    goto skip_6;
    // 0x805C7E30: lw          $t0, 0x34($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X34);
    skip_6:
    // 0x805C7E34: lw          $t8, 0x40($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X40);
    // 0x805C7E38: addiu       $t9, $zero, 0x96
    ctx->r25 = ADD32(0, 0X96);
    // 0x805C7E3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7E40: bne         $t8, $zero, L_805C7E84
    if (ctx->r24 != 0) {
        // 0x805C7E44: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_805C7E84;
    }
    // 0x805C7E44: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x805C7E48: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805C7E4C: sw          $t9, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r25;
    // 0x805C7E50: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x805C7E54: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x805C7E58: sw          $zero, 0x20($v1)
    MEM_W(0X20, ctx->r3) = 0;
    // 0x805C7E5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C7E60: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x805C7E64: jal         0x805C74C8
    // 0x805C7E68: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    func_805C74C8(rdram, ctx);
        goto after_8;
    // 0x805C7E68: swc1        $f0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->f0.u32l;
    after_8:
    // 0x805C7E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7E70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C7E74: jal         0x805C9D10
    // 0x805C7E78: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    func_805C9D10(rdram, ctx);
        goto after_9;
    // 0x805C7E78: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_9:
    // 0x805C7E7C: b           L_805C8130
    // 0x805C7E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C8130;
    // 0x805C7E80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C7E84:
    // 0x805C7E84: lw          $t0, 0x34($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X34);
L_805C7E88:
    // 0x805C7E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7E8C: bne         $t0, $zero, L_805C8124
    if (ctx->r8 != 0) {
        // 0x805C7E90: nop
    
            goto L_805C8124;
    }
    // 0x805C7E90: nop

    // 0x805C7E94: jal         0x805C6E30
    // 0x805C7E98: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    func_805C6E30(rdram, ctx);
        goto after_10;
    // 0x805C7E98: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_10:
    // 0x805C7E9C: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x805C7EA0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x805C7EA4: bne         $v0, $zero, L_805C8124
    if (ctx->r2 != 0) {
        // 0x805C7EA8: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_805C8124;
    }
    // 0x805C7EA8: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7EAC: lw          $t1, 0x40($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X40);
    // 0x805C7EB0: bne         $t1, $zero, L_805C8124
    if (ctx->r9 != 0) {
        // 0x805C7EB4: nop
    
            goto L_805C8124;
    }
    // 0x805C7EB4: nop

    // 0x805C7EB8: lh          $t2, 0xADE($a2)
    ctx->r10 = MEM_H(ctx->r6, 0XADE);
    // 0x805C7EBC: lh          $t3, 0xAFE($a2)
    ctx->r11 = MEM_H(ctx->r6, 0XAFE);
    // 0x805C7EC0: lh          $t4, 0xAE0($a2)
    ctx->r12 = MEM_H(ctx->r6, 0XAE0);
    // 0x805C7EC4: lh          $t5, 0xB00($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XB00);
    // 0x805C7EC8: subu        $v0, $t2, $t3
    ctx->r2 = SUB32(ctx->r10, ctx->r11);
    // 0x805C7ECC: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C7ED0: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x805C7ED4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x805C7ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7EDC: mflo        $t6
    ctx->r14 = lo;
    // 0x805C7EE0: nop

    // 0x805C7EE4: nop

    // 0x805C7EE8: multu       $v1, $v1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x805C7EEC: mflo        $t7
    ctx->r15 = lo;
    // 0x805C7EF0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x805C7EF4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x805C7EF8: nop

    // 0x805C7EFC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805C7F00: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x805C7F04: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x805C7F08: nop

    // 0x805C7F0C: bc1fl       L_805C7F6C
    if (!c1cs) {
        // 0x805C7F10: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_805C7F6C;
    }
    goto skip_7;
    // 0x805C7F10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_7:
    // 0x805C7F14: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x805C7F18: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x805C7F1C: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x805C7F20: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x805C7F24: beq         $t0, $at, L_805C7F68
    if (ctx->r8 == ctx->r1) {
        // 0x805C7F28: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_805C7F68;
    }
    // 0x805C7F28: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x805C7F2C: addiu       $at, $zero, 0x4000
    ctx->r1 = ADD32(0, 0X4000);
    // 0x805C7F30: beq         $t1, $at, L_805C7F68
    if (ctx->r9 == ctx->r1) {
        // 0x805C7F34: andi        $t2, $v0, 0x2
        ctx->r10 = ctx->r2 & 0X2;
            goto L_805C7F68;
    }
    // 0x805C7F34: andi        $t2, $v0, 0x2
    ctx->r10 = ctx->r2 & 0X2;
    // 0x805C7F38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x805C7F3C: beq         $t2, $at, L_805C7F68
    if (ctx->r10 == ctx->r1) {
        // 0x805C7F40: andi        $t3, $v0, 0x4
        ctx->r11 = ctx->r2 & 0X4;
            goto L_805C7F68;
    }
    // 0x805C7F40: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x805C7F44: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x805C7F48: beq         $t3, $at, L_805C7F68
    if (ctx->r11 == ctx->r1) {
        // 0x805C7F4C: andi        $t4, $v0, 0x8
        ctx->r12 = ctx->r2 & 0X8;
            goto L_805C7F68;
    }
    // 0x805C7F4C: andi        $t4, $v0, 0x8
    ctx->r12 = ctx->r2 & 0X8;
    // 0x805C7F50: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x805C7F54: beq         $t4, $at, L_805C7F68
    if (ctx->r12 == ctx->r1) {
        // 0x805C7F58: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_805C7F68;
    }
    // 0x805C7F58: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x805C7F5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x805C7F60: bne         $t5, $at, L_805C8124
    if (ctx->r13 != ctx->r1) {
        // 0x805C7F64: nop
    
            goto L_805C8124;
    }
    // 0x805C7F64: nop

L_805C7F68:
    // 0x805C7F68: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_805C7F6C:
    // 0x805C7F6C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x805C7F70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C7F74: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x805C7F78: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x805C7F7C: jal         0x805C74C8
    // 0x805C7F80: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    func_805C74C8(rdram, ctx);
        goto after_11;
    // 0x805C7F80: swc1        $f8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x805C7F84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C7F8C: jal         0x805C9D10
    // 0x805C7F90: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    func_805C9D10(rdram, ctx);
        goto after_12;
    // 0x805C7F90: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_12:
    // 0x805C7F94: b           L_805C8124
    // 0x805C7F98: nop

        goto L_805C8124;
    // 0x805C7F98: nop

    // 0x805C7F9C: lw          $t6, 0x24($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X24);
L_805C7FA0:
    // 0x805C7FA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C7FA4: bne         $t6, $zero, L_805C8124
    if (ctx->r14 != 0) {
        // 0x805C7FA8: nop
    
            goto L_805C8124;
    }
    // 0x805C7FA8: nop

    // 0x805C7FAC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x805C7FB0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x805C7FB4: jal         0x805C6E30
    // 0x805C7FB8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_805C6E30(rdram, ctx);
        goto after_13;
    // 0x805C7FB8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_13:
    // 0x805C7FBC: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x805C7FC0: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x805C7FC4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x805C7FC8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x805C7FCC: bne         $v0, $zero, L_805C802C
    if (ctx->r2 != 0) {
        // 0x805C7FD0: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_805C802C;
    }
    // 0x805C7FD0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x805C7FD4: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x805C7FD8: bne         $v0, $zero, L_805C7FFC
    if (ctx->r2 != 0) {
        // 0x805C7FDC: nop
    
            goto L_805C7FFC;
    }
    // 0x805C7FDC: nop

    // 0x805C7FE0: lw          $t7, 0x478($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X478);
    // 0x805C7FE4: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C7FE8: lwc1        $f16, 0x30($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X30);
    // 0x805C7FEC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C7FF0: nop

    // 0x805C7FF4: bc1tl       L_805C8020
    if (c1cs) {
        // 0x805C7FF8: addiu       $t9, $zero, 0xC8
        ctx->r25 = ADD32(0, 0XC8);
            goto L_805C8020;
    }
    goto skip_8;
    // 0x805C7FF8: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    skip_8:
L_805C7FFC:
    // 0x805C7FFC: beql        $v0, $zero, L_805C8084
    if (ctx->r2 == 0) {
        // 0x805C8000: lw          $v0, 0x60($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X60);
            goto L_805C8084;
    }
    goto skip_9;
    // 0x805C8000: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    skip_9:
    // 0x805C8004: lw          $t8, 0x478($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X478);
    // 0x805C8008: lwc1        $f4, 0x3C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C800C: lwc1        $f18, 0x30($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X30);
    // 0x805C8010: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x805C8014: nop

    // 0x805C8018: bc1f        L_805C8080
    if (!c1cs) {
        // 0x805C801C: addiu       $t9, $zero, 0xC8
        ctx->r25 = ADD32(0, 0XC8);
            goto L_805C8080;
    }
    // 0x805C801C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
L_805C8020:
    // 0x805C8020: sw          $t9, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r25;
    // 0x805C8024: b           L_805C8080
    // 0x805C8028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_805C8080;
    // 0x805C8028: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805C802C:
    // 0x805C802C: lw          $v0, 0x138($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X138);
    // 0x805C8030: bne         $v0, $zero, L_805C8050
    if (ctx->r2 != 0) {
        // 0x805C8034: nop
    
            goto L_805C8050;
    }
    // 0x805C8034: nop

    // 0x805C8038: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C803C: lwc1        $f8, 0x180($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X180);
    // 0x805C8040: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x805C8044: nop

    // 0x805C8048: bc1tl       L_805C8074
    if (c1cs) {
        // 0x805C804C: lw          $t0, 0x60($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X60);
            goto L_805C8074;
    }
    goto skip_10;
    // 0x805C804C: lw          $t0, 0x60($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X60);
    skip_10:
L_805C8050:
    // 0x805C8050: beql        $v0, $zero, L_805C8084
    if (ctx->r2 == 0) {
        // 0x805C8054: lw          $v0, 0x60($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X60);
            goto L_805C8084;
    }
    goto skip_11;
    // 0x805C8054: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    skip_11:
    // 0x805C8058: lwc1        $f10, 0x180($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X180);
    // 0x805C805C: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x805C8060: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x805C8064: nop

    // 0x805C8068: bc1fl       L_805C8084
    if (!c1cs) {
        // 0x805C806C: lw          $v0, 0x60($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X60);
            goto L_805C8084;
    }
    goto skip_12;
    // 0x805C806C: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    skip_12:
    // 0x805C8070: lw          $t0, 0x60($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X60);
L_805C8074:
    // 0x805C8074: bnel        $t0, $zero, L_805C8084
    if (ctx->r8 != 0) {
        // 0x805C8078: lw          $v0, 0x60($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X60);
            goto L_805C8084;
    }
    goto skip_13;
    // 0x805C8078: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
    skip_13:
    // 0x805C807C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_805C8080:
    // 0x805C8080: lw          $v0, 0x60($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X60);
L_805C8084:
    // 0x805C8084: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x805C8088: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x805C808C: beq         $v0, $zero, L_805C8098
    if (ctx->r2 == 0) {
        // 0x805C8090: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_805C8098;
    }
    // 0x805C8090: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x805C8094: sw          $t1, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r9;
L_805C8098:
    // 0x805C8098: beq         $a1, $zero, L_805C8124
    if (ctx->r5 == 0) {
        // 0x805C809C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_805C8124;
    }
    // 0x805C809C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C80A0: sw          $t2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r10;
    // 0x805C80A4: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x805C80A8: sw          $zero, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = 0;
    // 0x805C80AC: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805C80B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x805C80B4: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x805C80B8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805C80BC: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x805C80C0: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x805C80C4: bc1fl       L_805C80E0
    if (!c1cs) {
        // 0x805C80C8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_805C80E0;
    }
    goto skip_14;
    // 0x805C80C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_14:
    // 0x805C80CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805C80D0: nop

    // 0x805C80D4: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x805C80D8: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x805C80DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_805C80E0:
    // 0x805C80E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x805C80E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805C80E8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x805C80EC: nop

    // 0x805C80F0: bc1f        L_805C8104
    if (!c1cs) {
        // 0x805C80F4: nop
    
            goto L_805C8104;
    }
    // 0x805C80F4: nop

    // 0x805C80F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x805C80FC: nop

    // 0x805C8100: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_805C8104:
    // 0x805C8104: jal         0x805C74C8
    // 0x805C8108: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    func_805C74C8(rdram, ctx);
        goto after_14;
    // 0x805C8108: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_14:
    // 0x805C810C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C8110: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C8114: jal         0x805C9D10
    // 0x805C8118: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_805C9D10(rdram, ctx);
        goto after_15;
    // 0x805C8118: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_15:
    // 0x805C811C: b           L_805C8130
    // 0x805C8120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C8130;
    // 0x805C8120: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8124:
    // 0x805C8124: jal         0x805C7844
    // 0x805C8128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7844(rdram, ctx);
        goto after_16;
    // 0x805C8128: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
L_805C812C:
    // 0x805C812C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C8130:
    // 0x805C8130: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C8134: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805C8138: jr          $ra
    // 0x805C813C: nop

    return;
    // 0x805C813C: nop

;}
RECOMP_FUNC void func_806F2C0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F2C0C: jr          $ra
    // 0x806F2C10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806F2C10: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_805361A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805361A4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x805361A8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x805361AC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x805361B0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x805361B4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x805361B8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x805361BC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x805361C0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x805361C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x805361C8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x805361CC: jr          $ra
    // 0x805361D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x805361D0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8053240C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8053240C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80532410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80532414: jal         0x80530E78
    // 0x80532418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80530E78(rdram, ctx);
        goto after_0;
    // 0x80532418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8053241C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80532420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80532424: jr          $ra
    // 0x80532428: nop

    return;
    // 0x80532428: nop

;}
RECOMP_FUNC void func_80057D1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80057D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80057D24: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80057D28: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80057D2C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80057D30: beq         $t6, $zero, L_80057D68
    if (ctx->r14 == 0) {
        // 0x80057D34: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80057D68;
    }
    // 0x80057D34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80057D38: lh          $a1, 0x8($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X8);
    // 0x80057D3C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80057D40: jal         0x800651B0
    // 0x80057D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800651B0(rdram, ctx);
        goto after_0;
    // 0x80057D44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80057D48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80057D4C: jal         0x80057BAC
    // 0x80057D50: lh          $a1, 0x4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X4);
    func_80057BAC(rdram, ctx);
        goto after_1;
    // 0x80057D50: lh          $a1, 0x4($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X4);
    after_1:
    // 0x80057D54: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80057D58: lh          $t7, 0x6($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X6);
    // 0x80057D5C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80057D60: b           L_80057D68
    // 0x80057D64: sh          $t8, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r24;
        goto L_80057D68;
    // 0x80057D64: sh          $t8, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r24;
L_80057D68:
    // 0x80057D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80057D6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80057D70: jr          $ra
    // 0x80057D74: nop

    return;
    // 0x80057D74: nop

;}
RECOMP_FUNC void func_8079A2B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079A2B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8079A2B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8079A2BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8079A2C0: jal         0x80799B68
    // 0x8079A2C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_80799B68(rdram, ctx);
        goto after_0;
    // 0x8079A2C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8079A2C8: jal         0x80799B94
    // 0x8079A2CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80799B94(rdram, ctx);
        goto after_1;
    // 0x8079A2CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8079A2D0: beq         $v0, $zero, L_8079A2F4
    if (ctx->r2 == 0) {
        // 0x8079A2D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8079A2F4;
    }
    // 0x8079A2D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A2D8: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8079A2DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A2E0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8079A2E4: jal         0x8079AEDC
    // 0x8079A2E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_2;
    // 0x8079A2E8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x8079A2EC: b           L_8079A334
    // 0x8079A2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8079A334;
    // 0x8079A2F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079A2F4:
    // 0x8079A2F4: jal         0x80799BE0
    // 0x8079A2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80799BE0(rdram, ctx);
        goto after_3;
    // 0x8079A2F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8079A2FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A300: jal         0x80062684
    // 0x8079A304: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    func_80062684(rdram, ctx);
        goto after_4;
    // 0x8079A304: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    after_4:
    // 0x8079A308: jal         0x8079A15C
    // 0x8079A30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079A15C(rdram, ctx);
        goto after_5;
    // 0x8079A30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8079A310: jal         0x8079A258
    // 0x8079A314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8079A258(rdram, ctx);
        goto after_6;
    // 0x8079A314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8079A318: beq         $v0, $zero, L_8079A330
    if (ctx->r2 == 0) {
        // 0x8079A31C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8079A330;
    }
    // 0x8079A31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8079A320: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8079A324: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8079A328: jal         0x8079AEDC
    // 0x8079A32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_8079AEDC(rdram, ctx);
        goto after_7;
    // 0x8079A32C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
L_8079A330:
    // 0x8079A330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8079A334:
    // 0x8079A334: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8079A338: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8079A33C: jr          $ra
    // 0x8079A340: nop

    return;
    // 0x8079A340: nop

;}
RECOMP_FUNC void func_80045BD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80045BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80045BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80045BE0: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80045BE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045BE8: beql        $t6, $at, L_80045C38
    if (ctx->r14 == ctx->r1) {
        // 0x80045BEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80045C38;
    }
    goto skip_0;
    // 0x80045BEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80045BF0: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80045BF4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80045BF8: bne         $v0, $zero, L_80045C18
    if (ctx->r2 != 0) {
        // 0x80045BFC: nop
    
            goto L_80045C18;
    }
    // 0x80045BFC: nop

    // 0x80045C00: jal         0x80045B64
    // 0x80045C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80045B64(rdram, ctx);
        goto after_0;
    // 0x80045C04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80045C08: jal         0x80045AE8
    // 0x80045C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045AE8(rdram, ctx);
        goto after_1;
    // 0x80045C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80045C10: b           L_80045C2C
    // 0x80045C14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80045C2C;
    // 0x80045C14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80045C18:
    // 0x80045C18: beql        $v0, $at, L_80045C2C
    if (ctx->r2 == ctx->r1) {
        // 0x80045C1C: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80045C2C;
    }
    goto skip_1;
    // 0x80045C1C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_1:
    // 0x80045C20: jal         0x800468E8
    // 0x80045C24: nop

    func_800468E8(rdram, ctx);
        goto after_2;
    // 0x80045C24: nop

    after_2:
    // 0x80045C28: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80045C2C:
    // 0x80045C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80045C30: sb          $t7, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r15;
    // 0x80045C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80045C38:
    // 0x80045C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80045C3C: jr          $ra
    // 0x80045C40: nop

    return;
    // 0x80045C40: nop

;}
RECOMP_FUNC void func_800493F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800493F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800493F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800493FC: jal         0x8004937C
    // 0x80049400: nop

    func_8004937C(rdram, ctx);
        goto after_0;
    // 0x80049400: nop

    after_0:
    // 0x80049404: jal         0x800493B8
    // 0x80049408: nop

    func_800493B8(rdram, ctx);
        goto after_1;
    // 0x80049408: nop

    after_1:
    // 0x8004940C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80049410: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80049414: jr          $ra
    // 0x80049418: nop

    return;
    // 0x80049418: nop

;}
RECOMP_FUNC void func_804A491C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A491C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x804A4920: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x804A4924: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x804A4928: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x804A492C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x804A4930: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x804A4934: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x804A4938: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x804A493C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x804A4940: lui         $t1, 0x804A
    ctx->r9 = S32(RELOC_HI16(176, 0X1028) << 16);
    // 0x804A4944: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x804A4948: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x804A494C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x804A4950: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x804A4954: lw          $t1, 0x4A28($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(176, 0X1028));
    // 0x804A4958: jr          $ra
    // 0x804A495C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x804A495C: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8000D9D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D9D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8000D9D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000D9D8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000D9DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000D9E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000D9E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000D9E8: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8000D9EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000D9F0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000D9F4: addiu       $s2, $s2, -0x64A0
    ctx->r18 = ADD32(ctx->r18, -0X64A0);
    // 0x8000D9F8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D9FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000DA00: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000DA04: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_8000DA08:
    // 0x8000DA08: lw          $a0, 0x34($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X34);
    // 0x8000DA0C: xor         $t6, $a0, $s2
    ctx->r14 = ctx->r4 ^ ctx->r18;
    // 0x8000DA10: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x8000DA14: bnel        $s3, $t6, L_8000DA28
    if (ctx->r19 != ctx->r14) {
        // 0x8000DA18: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000DA28;
    }
    goto skip_0;
    // 0x8000DA18: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_0:
    // 0x8000DA1C: jal         0x8000D86C
    // 0x8000DA20: nop

    func_8000D86C(rdram, ctx);
        goto after_0;
    // 0x8000DA20: nop

    after_0:
    // 0x8000DA24: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000DA28:
    // 0x8000DA28: bne         $s0, $s4, L_8000DA08
    if (ctx->r16 != ctx->r20) {
        // 0x8000DA2C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000DA08;
    }
    // 0x8000DA2C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000DA30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000DA34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000DA38: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DA3C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000DA40: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000DA44: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000DA48: jr          $ra
    // 0x8000DA4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8000DA4C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80474E50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80474E50: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80474E54: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x80474E58: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80474E5C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80474E60: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80474E64: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80474E68: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80474E6C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80474E70: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80474E74: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80474E78: jr          $ra
    // 0x80474E7C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80474E7C: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_800804E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800804E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800804E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800804E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800804EC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800804F0: jal         0x80082730
    // 0x800804F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    fsin(rdram, ctx);
        goto after_0;
    // 0x800804F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800804F8: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800804FC: jal         0x8008D250
    // 0x80080500: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    fcos(rdram, ctx);
        goto after_1;
    // 0x80080500: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80080504: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80080508: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8008050C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80080510: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80080514: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080518: nop

    // 0x8008051C: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080520: nop

    // 0x80080524: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080528: lwc1        $f12, 0x14($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8008052C: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080530: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80080534: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080538: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008053C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80080540: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080544: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080548: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8008054C: lwc1        $f12, 0x18($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80080550: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80080554: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80080558: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8008055C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x80080560: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80080564: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80080568: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8008056C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080570: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80080574: lwc1        $f12, 0x1C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x80080578: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8008057C: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80080580: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80080584: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x80080588: mul.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8008058C: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80080590: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80080594: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80080598: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8008059C: nop

    // 0x800805A0: mul.s       $f16, $f2, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800805A4: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800805A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800805AC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800805B0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800805B4: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x800805B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800805BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800805C0: jr          $ra
    // 0x800805C4: nop

    return;
    // 0x800805C4: nop

;}
RECOMP_FUNC void func_8002C1E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C1E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002C1E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002C1E8: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8002C1EC: addiu       $a1, $a1, -0x250C
    ctx->r5 = ADD32(ctx->r5, -0X250C);
    // 0x8002C1F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002C1F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002C1F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002C1FC: jal         0x80028118
    // 0x8002C200: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    func_80028118(rdram, ctx);
        goto after_0;
    // 0x8002C200: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    after_0:
    // 0x8002C204: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x8002C208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8002C20C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8002C210: sw          $zero, 0x44($t7)
    MEM_W(0X44, ctx->r15) = 0;
    // 0x8002C214: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x8002C218: jal         0x8002B00C
    // 0x8002C21C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_8002B00C(rdram, ctx);
        goto after_1;
    // 0x8002C21C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8002C220: jal         0x8002AE90
    // 0x8002C224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8002AE90(rdram, ctx);
        goto after_2;
    // 0x8002C224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8002C228: jal         0x8003EE80
    // 0x8002C22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8003EE80(rdram, ctx);
        goto after_3;
    // 0x8002C22C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8002C230: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002C234: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8002C238: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8002C23C: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8002C240: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8002C244: lw          $v0, -0x727C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X727C);
    // 0x8002C248: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8002C24C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002C250: beql        $v0, $zero, L_8002C284
    if (ctx->r2 == 0) {
        // 0x8002C254: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8002C284;
    }
    goto skip_0;
    // 0x8002C254: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_0:
    // 0x8002C258: lwc1        $f0, 0x64($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X64);
    // 0x8002C25C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8002C260: lwc1        $f10, 0x88($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X88);
    // 0x8002C264: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8002C268: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8002C26C: lw          $a2, 0x8C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8C);
    // 0x8002C270: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002C274: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8002C278: jalr        $v0
    // 0x8002C27C: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_4;
    // 0x8002C27C: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    after_4:
    // 0x8002C280: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8002C284:
    // 0x8002C284: sb          $t0, 0x165($s0)
    MEM_B(0X165, ctx->r16) = ctx->r8;
    // 0x8002C288: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C28C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002C290: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002C294: jr          $ra
    // 0x8002C298: nop

    return;
    // 0x8002C298: nop

;}
RECOMP_FUNC void func_807B63C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B63C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807B63C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B63CC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x807B63D0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x807B63D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x807B63D8: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B63DC: jal         0x80047090
    // 0x807B63E0: addiu       $a0, $zero, 0x473B
    ctx->r4 = ADD32(0, 0X473B);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x807B63E0: addiu       $a0, $zero, 0x473B
    ctx->r4 = ADD32(0, 0X473B);
    after_0:
    // 0x807B63E4: lui         $at, 0x473B
    ctx->r1 = S32(0X473B << 16);
    // 0x807B63E8: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x807B63EC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B63F0: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x807B63F4: lui         $a1, 0x42D0
    ctx->r5 = S32(0X42D0 << 16);
    // 0x807B63F8: jal         0x8004613C
    // 0x807B63FC: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x807B63FC: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    after_1:
    // 0x807B6400: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x807B6404: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x807B6408: sb          $t7, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r15;
    // 0x807B640C: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x807B6410: jal         0x80047F9C
    // 0x807B6414: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x807B6414: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x807B6418: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(880, 0X2EC4) << 16);
    // 0x807B641C: lwc1        $f20, 0x76C4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(880, 0X2EC4));
    // 0x807B6420: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    // 0x807B6424: addiu       $a0, $zero, 0x473B
    ctx->r4 = ADD32(0, 0X473B);
    // 0x807B6428: swc1        $f20, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f20.u32l;
    // 0x807B642C: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x807B6430: jal         0x80047090
    // 0x807B6434: swc1        $f20, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_3;
    // 0x807B6434: swc1        $f20, 0x70($t9)
    MEM_W(0X70, ctx->r25) = ctx->f20.u32l;
    after_3:
    // 0x807B6438: lui         $at, 0x473B
    ctx->r1 = S32(0X473B << 16);
    // 0x807B643C: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x807B6440: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B6444: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x807B6448: lui         $a1, 0x42D0
    ctx->r5 = S32(0X42D0 << 16);
    // 0x807B644C: jal         0x8004613C
    // 0x807B6450: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    func_8004613C(rdram, ctx);
        goto after_4;
    // 0x807B6450: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    after_4:
    // 0x807B6454: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    // 0x807B6458: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x807B645C: sb          $t0, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r8;
    // 0x807B6460: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x807B6464: jal         0x80047F9C
    // 0x807B6468: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_5;
    // 0x807B6468: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x807B646C: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x807B6470: addiu       $a0, $zero, 0x473B
    ctx->r4 = ADD32(0, 0X473B);
    // 0x807B6474: swc1        $f20, 0x6C($t1)
    MEM_W(0X6C, ctx->r9) = ctx->f20.u32l;
    // 0x807B6478: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x807B647C: jal         0x80047090
    // 0x807B6480: swc1        $f20, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f20.u32l;
    func_80047090(rdram, ctx);
        goto after_6;
    // 0x807B6480: swc1        $f20, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f20.u32l;
    after_6:
    // 0x807B6484: lui         $at, 0x473B
    ctx->r1 = S32(0X473B << 16);
    // 0x807B6488: lui         $a3, 0xBB03
    ctx->r7 = S32(0XBB03 << 16);
    // 0x807B648C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x807B6490: or          $a0, $v0, $at
    ctx->r4 = ctx->r2 | ctx->r1;
    // 0x807B6494: lui         $a1, 0x42D0
    ctx->r5 = S32(0X42D0 << 16);
    // 0x807B6498: jal         0x8004613C
    // 0x807B649C: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    func_8004613C(rdram, ctx);
        goto after_7;
    // 0x807B649C: lui         $a2, 0xC200
    ctx->r6 = S32(0XC200 << 16);
    after_7:
    // 0x807B64A0: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x807B64A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807B64A8: sb          $t3, 0x31($v0)
    MEM_B(0X31, ctx->r2) = ctx->r11;
    // 0x807B64AC: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x807B64B0: jal         0x80047F9C
    // 0x807B64B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_80047F9C(rdram, ctx);
        goto after_8;
    // 0x807B64B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_8:
    // 0x807B64B8: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x807B64BC: swc1        $f20, 0x6C($t4)
    MEM_W(0X6C, ctx->r12) = ctx->f20.u32l;
    // 0x807B64C0: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x807B64C4: swc1        $f20, 0x70($t5)
    MEM_W(0X70, ctx->r13) = ctx->f20.u32l;
    // 0x807B64C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B64CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x807B64D0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x807B64D4: jr          $ra
    // 0x807B64D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x807B64D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8040C180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040C180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8040C184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8040C188: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8040C18C: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8040C190: lui         $t8, 0x8041
    ctx->r24 = S32(RELOC_HI16(17, 0X4E0) << 16);
    // 0x8040C194: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8040C198: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8040C19C: lw          $t8, -0x3A90($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(17, 0X4E0));
    // 0x8040C1A0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8040C1A4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8040C1A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8040C1AC: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8040C1B0: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8040C1B4: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8040C1B8: beql        $v1, $zero, L_8040C1EC
    if (ctx->r3 == 0) {
        // 0x8040C1BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8040C1EC;
    }
    goto skip_0;
    // 0x8040C1BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8040C1C0: jalr        $v1
    // 0x8040C1C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8040C1C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8040C1C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8040C1CC: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8040C1D0: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8040C1D4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8040C1D8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8040C1DC: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8040C1E0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8040C1E4: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8040C1E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8040C1EC:
    // 0x8040C1EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8040C1F0: jr          $ra
    // 0x8040C1F4: nop

    return;
    // 0x8040C1F4: nop

;}
RECOMP_FUNC void func_8006671C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006671C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066720: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80066724: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80066728: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006672C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80066730: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
L_80066734:
    // 0x80066734: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80066738: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8006673C: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80066740: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80066744: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80066748: lh          $t8, 0x0($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X0);
    // 0x8006674C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80066750: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80066754: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80066758: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8006675C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80066760: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80066764: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80066768: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006676C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80066770: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80066774: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80066778: nop

    // 0x8006677C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80066780: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80066784: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80066788: add.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006678C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80066790: nop

    // 0x80066794: bc1fl       L_800667B4
    if (!c1cs) {
        // 0x80066798: add.s       $f16, $f0, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
            goto L_800667B4;
    }
    goto skip_0;
    // 0x80066798: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
    skip_0:
    // 0x8006679C: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800667A0: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800667A4: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800667A8: b           L_800667C4
    // 0x800667AC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
        goto L_800667C4;
    // 0x800667AC: sh          $t1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r9;
    // 0x800667B0: add.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f12.fl;
L_800667B4:
    // 0x800667B4: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800667B8: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x800667BC: nop

    // 0x800667C0: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_800667C4:
    // 0x800667C4: bne         $v0, $t0, L_80066734
    if (ctx->r2 != ctx->r8) {
        // 0x800667C8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80066734;
    }
    // 0x800667C8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800667CC: jr          $ra
    // 0x800667D0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    return;
    // 0x800667D0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
;}
RECOMP_FUNC void func_805ABF14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805ABF14: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805ABF18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805ABF1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805ABF20: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(438, 0X598) << 16);
    // 0x805ABF24: lwc1        $f6, -0x3ED8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(438, 0X598));
    // 0x805ABF28: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x805ABF2C: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x805ABF30: addiu       $t6, $zero, -0x10
    ctx->r14 = ADD32(0, -0X10);
    // 0x805ABF34: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x805ABF38: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x805ABF3C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x805ABF40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x805ABF44: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x805ABF48: jal         0x805ABD0C
    // 0x805ABF4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    func_805ABD0C(rdram, ctx);
        goto after_0;
    // 0x805ABF4C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x805ABF50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x805ABF54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805ABF58: jr          $ra
    // 0x805ABF5C: nop

    return;
    // 0x805ABF5C: nop

;}
RECOMP_FUNC void func_8044602C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044602C: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80446030: jr          $ra
    // 0x80446034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    return;
    // 0x80446034: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
;}
RECOMP_FUNC void func_806F96BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F96BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806F96C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F96C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F96C8: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x806F96CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806F96D0: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x806F96D4: andi        $t7, $t6, 0xF00
    ctx->r15 = ctx->r14 & 0XF00;
    // 0x806F96D8: beq         $t7, $zero, L_806F971C
    if (ctx->r15 == 0) {
        // 0x806F96DC: nop
    
            goto L_806F971C;
    }
    // 0x806F96DC: nop

    // 0x806F96E0: lbu         $t8, 0x11($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X11);
    // 0x806F96E4: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x806F96E8: bnel        $at, $zero, L_806F9708
    if (ctx->r1 != 0) {
        // 0x806F96EC: lwc1        $f6, 0xC8($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
            goto L_806F9708;
    }
    goto skip_0;
    // 0x806F96EC: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    skip_0:
    // 0x806F96F0: jal         0x806F9A78
    // 0x806F96F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806F9A78(rdram, ctx);
        goto after_0;
    // 0x806F96F4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x806F96F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F96FC: nop

    // 0x806F9700: swc1        $f4, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f4.u32l;
    // 0x806F9704: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
L_806F9708:
    // 0x806F9708: lui         $at, 0x8070
    ctx->r1 = S32(RELOC_HI16(697, 0X5E0) << 16);
    // 0x806F970C: lwc1        $f10, -0x64A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(697, 0X5E0));
    // 0x806F9710: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x806F9714: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x806F9718: swc1        $f16, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f16.u32l;
L_806F971C:
    // 0x806F971C: jal         0x806F95A0
    // 0x806F9720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806F95A0(rdram, ctx);
        goto after_1;
    // 0x806F9720: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806F9724: lwc1        $f12, 0xC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x806F9728: lwc1        $f14, 0xEC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x806F972C: jal         0x80065ABC
    // 0x806F9730: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    func_80065ABC(rdram, ctx);
        goto after_2;
    // 0x806F9730: lw          $a2, 0xE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XE0);
    after_2:
    // 0x806F9734: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x806F9738: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F973C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F9740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806F9744: jr          $ra
    // 0x806F9748: nop

    return;
    // 0x806F9748: nop

;}
RECOMP_FUNC void func_8044FFC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044FFC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8044FFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8044FFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8044FFCC: jal         0x80046E88
    // 0x8044FFD0: addiu       $a0, $zero, 0x4505
    ctx->r4 = ADD32(0, 0X4505);
    func_80046E88(rdram, ctx);
        goto after_0;
    // 0x8044FFD0: addiu       $a0, $zero, 0x4505
    ctx->r4 = ADD32(0, 0X4505);
    after_0:
    // 0x8044FFD4: beql        $v0, $zero, L_8044FFF4
    if (ctx->r2 == 0) {
        // 0x8044FFD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044FFF4;
    }
    goto skip_0;
    // 0x8044FFD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8044FFDC: lw          $a1, 0x1F4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1F4);
    // 0x8044FFE0: beql        $a1, $zero, L_8044FFF4
    if (ctx->r5 == 0) {
        // 0x8044FFE4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8044FFF4;
    }
    goto skip_1;
    // 0x8044FFE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8044FFE8: jal         0x8044FF44
    // 0x8044FFEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_8044FF44(rdram, ctx);
        goto after_1;
    // 0x8044FFEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8044FFF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8044FFF4:
    // 0x8044FFF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8044FFF8: jr          $ra
    // 0x8044FFFC: nop

    return;
    // 0x8044FFFC: nop

;}
RECOMP_FUNC void func_8059EB6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059EB6C: lbu         $v0, 0x30($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X30);
    // 0x8059EB70: lui         $t7, 0x805A
    ctx->r15 = S32(RELOC_HI16(405, 0X808) << 16);
    // 0x8059EB74: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8059EB78: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8059EB7C: beq         $at, $zero, L_8059EB98
    if (ctx->r1 == 0) {
        // 0x8059EB80: sll         $t6, $v0, 1
        ctx->r14 = S32(ctx->r2 << 1);
            goto L_8059EB98;
    }
    // 0x8059EB80: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8059EB84: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8059EB88: lhu         $t7, -0xDA8($t7)
    ctx->r15 = MEM_HU(ctx->r15, (int16_t)RELOC_LO16(405, 0X808));
    // 0x8059EB8C: lw          $t8, 0x1F4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059EB90: jr          $ra
    // 0x8059EB94: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    return;
    // 0x8059EB94: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
L_8059EB98:
    // 0x8059EB98: lw          $t9, -0x76C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76C0);
    // 0x8059EB9C: lui         $t1, 0x805A
    ctx->r9 = S32(RELOC_HI16(405, 0X834) << 16);
    // 0x8059EBA0: lw          $t2, 0x1F4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059EBA4: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8059EBA8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8059EBAC: lhu         $t1, -0xD7C($t1)
    ctx->r9 = MEM_HU(ctx->r9, (int16_t)RELOC_LO16(405, 0X834));
    // 0x8059EBB0: sh          $t1, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r9;
    // 0x8059EBB4: jr          $ra
    // 0x8059EBB8: nop

    return;
    // 0x8059EBB8: nop

;}
RECOMP_FUNC void func_806F5DFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806F5DFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x806F5E00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806F5E04: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x806F5E08: lbu         $t6, 0x18($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X18);
    // 0x806F5E0C: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x806F5E10: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x806F5E14: beql        $t6, $at, L_806F5E28
    if (ctx->r14 == ctx->r1) {
        // 0x806F5E18: lwc1        $f4, 0x84($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
            goto L_806F5E28;
    }
    goto skip_0;
    // 0x806F5E18: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    skip_0:
    // 0x806F5E1C: b           L_806F5F30
    // 0x806F5E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F5F30;
    // 0x806F5E20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F5E24: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
L_806F5E28:
    // 0x806F5E28: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x806F5E2C: lwc1        $f8, 0x88($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X88);
    // 0x806F5E30: lwc1        $f10, 0x88($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X88);
    // 0x806F5E34: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806F5E38: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x806F5E3C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x806F5E40: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x806F5E44: jal         0x80065954
    // 0x806F5E48: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x806F5E48: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x806F5E4C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x806F5E50: jal         0x80065954
    // 0x806F5E54: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x806F5E54: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x806F5E58: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x806F5E5C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x806F5E60: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806F5E64: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x806F5E68: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806F5E6C: bc1fl       L_806F5EA0
    if (!c1cs) {
        // 0x806F5E70: lwc1        $f18, 0x4($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
            goto L_806F5EA0;
    }
    goto skip_1;
    // 0x806F5E70: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x806F5E74: addiu       $v1, $s0, 0xC4
    ctx->r3 = ADD32(ctx->r16, 0XC4);
    // 0x806F5E78: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x806F5E7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x806F5E80: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x806F5E84: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806F5E88: nop

    // 0x806F5E8C: bc1fl       L_806F5EC4
    if (!c1cs) {
        // 0x806F5E90: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_806F5EC4;
    }
    goto skip_2;
    // 0x806F5E90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_2:
    // 0x806F5E94: b           L_806F5F30
    // 0x806F5E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F5F30;
    // 0x806F5E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F5E9C: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
L_806F5EA0:
    // 0x806F5EA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x806F5EA4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x806F5EA8: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x806F5EAC: nop

    // 0x806F5EB0: bc1fl       L_806F5EC4
    if (!c1cs) {
        // 0x806F5EB4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_806F5EC4;
    }
    goto skip_3;
    // 0x806F5EB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_3:
    // 0x806F5EB8: b           L_806F5F30
    // 0x806F5EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_806F5F30;
    // 0x806F5EBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x806F5EC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_806F5EC4:
    // 0x806F5EC4: sb          $t7, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r15;
    // 0x806F5EC8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x806F5ECC: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x806F5ED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806F5ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806F5ED8: jalr        $t9
    // 0x806F5EDC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x806F5EDC: nop

    after_2:
    // 0x806F5EE0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x806F5EE4: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x806F5EE8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x806F5EEC: lwc1        $f10, 0x84($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X84);
    // 0x806F5EF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x806F5EF4: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x806F5EF8: nop

    // 0x806F5EFC: bc1fl       L_806F5F18
    if (!c1cs) {
        // 0x806F5F00: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_806F5F18;
    }
    goto skip_4;
    // 0x806F5F00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x806F5F04: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806F5F08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x806F5F0C: b           L_806F5F20
    // 0x806F5F10: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
        goto L_806F5F20;
    // 0x806F5F10: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x806F5F14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_806F5F18:
    // 0x806F5F18: nop

    // 0x806F5F1C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_806F5F20:
    // 0x806F5F20: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x806F5F24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x806F5F28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x806F5F2C: swc1        $f16, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f16.u32l;
L_806F5F30:
    // 0x806F5F30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806F5F34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806F5F38: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x806F5F3C: jr          $ra
    // 0x806F5F40: nop

    return;
    // 0x806F5F40: nop

;}
RECOMP_FUNC void func_804BD4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD4E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804BD4E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804BD4E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804BD4EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804BD4F0: jal         0x804BD568
    // 0x804BD4F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_804BD568(rdram, ctx);
        goto after_0;
    // 0x804BD4F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x804BD4F8: beq         $v0, $zero, L_804BD54C
    if (ctx->r2 == 0) {
        // 0x804BD4FC: nop
    
            goto L_804BD54C;
    }
    // 0x804BD4FC: nop

    // 0x804BD500: jal         0x804BD5A0
    // 0x804BD504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_804BD5A0(rdram, ctx);
        goto after_1;
    // 0x804BD504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x804BD508: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x804BD50C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x804BD510: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x804BD514: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BD518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804BD51C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804BD520: jal         0x804BF568
    // 0x804BD524: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_804BF568(rdram, ctx);
        goto after_2;
    // 0x804BD524: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_2:
    // 0x804BD528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804BD52C: jal         0x804BF3E0
    // 0x804BD530: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    func_804BF3E0(rdram, ctx);
        goto after_3;
    // 0x804BD530: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x804BD534: bnel        $v0, $zero, L_804BD558
    if (ctx->r2 != 0) {
        // 0x804BD538: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804BD558;
    }
    goto skip_0;
    // 0x804BD538: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804BD53C: jal         0x800445A4
    // 0x804BD540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_4;
    // 0x804BD540: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x804BD544: b           L_804BD558
    // 0x804BD548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804BD558;
    // 0x804BD548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BD54C:
    // 0x804BD54C: jal         0x800445A4
    // 0x804BD550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_5;
    // 0x804BD550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x804BD554: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804BD558:
    // 0x804BD558: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804BD55C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804BD560: jr          $ra
    // 0x804BD564: nop

    return;
    // 0x804BD564: nop

;}
RECOMP_FUNC void func_8004627C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004627C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046280: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80046288: jal         0x800461F4
    // 0x8004628C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800461F4(rdram, ctx);
        goto after_0;
    // 0x8004628C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80046290: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80046294: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80046298: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x8004629C: addiu       $a3, $a3, 0x625C
    ctx->r7 = ADD32(ctx->r7, 0X625C);
    // 0x800462A0: addiu       $a2, $a2, 0x3E10
    ctx->r6 = ADD32(ctx->r6, 0X3E10);
    // 0x800462A4: addiu       $a0, $v0, 0x188
    ctx->r4 = ADD32(ctx->r2, 0X188);
    // 0x800462A8: jal         0x80057F74
    // 0x800462AC: lh          $a1, 0x184($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X184);
    func_80057F74(rdram, ctx);
        goto after_1;
    // 0x800462AC: lh          $a1, 0x184($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X184);
    after_1:
    // 0x800462B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800462B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800462B8: jr          $ra
    // 0x800462BC: nop

    return;
    // 0x800462BC: nop

;}
RECOMP_FUNC void func_804BF004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BF004: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BF008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BF00C: lw          $v1, 0x1F4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X1F4);
    // 0x804BF010: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x804BF014: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x804BF018: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804BF01C: lui         $t7, 0x804C
    ctx->r15 = S32(RELOC_HI16(191, 0X1FBC) << 16);
    // 0x804BF020: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x804BF024: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x804BF028: lui         $t8, 0x804C
    ctx->r24 = S32(RELOC_HI16(191, 0X2850) << 16);
    // 0x804BF02C: addiu       $t7, $t7, -0x2714
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(191, 0X1FBC));
    // 0x804BF030: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x804BF034: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x804BF038: addiu       $t8, $t8, -0x1E80
    ctx->r24 = ADD32(ctx->r24, (int16_t)RELOC_LO16(191, 0X2850));
    // 0x804BF03C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x804BF040: lwc1        $f10, 0x18($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X18);
    // 0x804BF044: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x804BF048: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x804BF04C: swc1        $f16, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f16.u32l;
    // 0x804BF050: lwc1        $f18, 0x1C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x804BF054: sh          $zero, 0x34($a0)
    MEM_H(0X34, ctx->r4) = 0;
    // 0x804BF058: lh          $v0, 0x34($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X34);
    // 0x804BF05C: sh          $zero, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = 0;
    // 0x804BF060: lh          $t6, 0x2A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2A);
    // 0x804BF064: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x804BF068: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x804BF06C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x804BF070: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x804BF074: sh          $v0, 0x30($a0)
    MEM_H(0X30, ctx->r4) = ctx->r2;
    // 0x804BF078: sh          $v0, 0x2E($a0)
    MEM_H(0X2E, ctx->r4) = ctx->r2;
    // 0x804BF07C: sh          $t6, 0x2C($a0)
    MEM_H(0X2C, ctx->r4) = ctx->r14;
    // 0x804BF080: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x804BF084: swc1        $f4, 0x368($v1)
    MEM_W(0X368, ctx->r3) = ctx->f4.u32l;
    // 0x804BF088: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x804BF08C: swc1        $f6, 0x36C($v1)
    MEM_W(0X36C, ctx->r3) = ctx->f6.u32l;
    // 0x804BF090: sw          $t7, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r15;
    // 0x804BF094: jal         0x804BD678
    // 0x804BF098: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
    func_804BD678(rdram, ctx);
        goto after_0;
    // 0x804BF098: sw          $t8, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r24;
    after_0:
    // 0x804BF09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BF0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804BF0A4: jr          $ra
    // 0x804BF0A8: nop

    return;
    // 0x804BF0A8: nop

;}
RECOMP_FUNC void func_807041F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807041F8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x807041FC: lui         $t6, 0x8070
    ctx->r14 = S32(RELOC_HI16(709, 0X377C) << 16);
    // 0x80704200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80704204: addiu       $t6, $t6, 0x6BEC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(709, 0X377C));
    // 0x80704208: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8070420C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80704210: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80704214: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80704218: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8070421C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80704220: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80704224: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80704228: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x8070422C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80704230: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80704234: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80704238: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x8070423C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80704240: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80704244: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80704248: lwc1        $f16, 0x70($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8070424C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80704250: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x80704254: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80704258: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8070425C: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80704260: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80704264: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80704268: lwc1        $f16, 0x40($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8070426C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x80704270: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80704274: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80704278: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8070427C: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80704280: lw          $t9, 0x4C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X4C);
    // 0x80704284: jalr        $t9
    // 0x80704288: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80704288: nop

    after_0:
    // 0x8070428C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80704290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80704294: jr          $ra
    // 0x80704298: nop

    return;
    // 0x80704298: nop

;}
RECOMP_FUNC void func_80559640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80559640: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80559644: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80559648: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8055964C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80559650: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80559654: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80559658: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8055965C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80559660: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x80559664: lwc1        $f20, 0x6C($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80559668: lwc1        $f22, 0x70($a0)
    ctx->f22.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8055966C: addiu       $s1, $a0, 0xC4
    ctx->r17 = ADD32(ctx->r4, 0XC4);
    // 0x80559670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559674: jal         0x80048F84
    // 0x80559678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80559678: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8055967C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80559680: jal         0x80048F84
    // 0x80559684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x80559684: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80559688: jal         0x805594F8
    // 0x8055968C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_805594F8(rdram, ctx);
        goto after_2;
    // 0x8055968C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80559690: jal         0x805582E0
    // 0x80559694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_805582E0(rdram, ctx);
        goto after_3;
    // 0x80559694: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x80559698: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X9540) << 16);
    // 0x8055969C: lwc1        $f0, 0x1090($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X9540));
    // 0x805596A0: lui         $at, 0x8056
    ctx->r1 = S32(RELOC_HI16(363, 0X9544) << 16);
    // 0x805596A4: lwc1        $f2, 0x1094($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(363, 0X9544));
    // 0x805596A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x805596AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x805596B0: sub.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x805596B4: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x805596B8: nop

    // 0x805596BC: bc1fl       L_805596CC
    if (!c1cs) {
        // 0x805596C0: swc1        $f20, 0x6C($s2)
        MEM_W(0X6C, ctx->r18) = ctx->f20.u32l;
            goto L_805596CC;
    }
    goto skip_0;
    // 0x805596C0: swc1        $f20, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f20.u32l;
    skip_0:
    // 0x805596C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x805596C8: swc1        $f20, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f20.u32l;
L_805596CC:
    // 0x805596CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x805596D0: sub.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x805596D4: swc1        $f20, 0x6C($t6)
    MEM_W(0X6C, ctx->r14) = ctx->f20.u32l;
    // 0x805596D8: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x805596DC: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x805596E0: swc1        $f20, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f20.u32l;
    // 0x805596E4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x805596E8: swc1        $f20, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->f20.u32l;
    // 0x805596EC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x805596F0: swc1        $f20, 0x6C($t9)
    MEM_W(0X6C, ctx->r25) = ctx->f20.u32l;
    // 0x805596F4: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x805596F8: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x805596FC: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80559700: bc1f        L_8055970C
    if (!c1cs) {
        // 0x80559704: swc1        $f6, 0x6C($v0)
        MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
            goto L_8055970C;
    }
    // 0x80559704: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x80559708: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_8055970C:
    // 0x8055970C: swc1        $f22, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f22.u32l;
    // 0x80559710: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80559714: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80559718: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8055971C: swc1        $f22, 0x70($t0)
    MEM_W(0X70, ctx->r8) = ctx->f22.u32l;
    // 0x80559720: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x80559724: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80559728: lui         $t7, 0x8056
    ctx->r15 = S32(RELOC_HI16(363, 0X93C8) << 16);
    // 0x8055972C: swc1        $f22, 0x70($t1)
    MEM_W(0X70, ctx->r9) = ctx->f22.u32l;
    // 0x80559730: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x80559734: addiu       $t7, $t7, 0xF18
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(363, 0X93C8));
    // 0x80559738: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8055973C: swc1        $f22, 0x70($t2)
    MEM_W(0X70, ctx->r10) = ctx->f22.u32l;
    // 0x80559740: lw          $t3, 0xC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XC);
    // 0x80559744: swc1        $f22, 0x70($t3)
    MEM_W(0X70, ctx->r11) = ctx->f22.u32l;
    // 0x80559748: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x8055974C: lwc1        $f8, 0x7C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80559750: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80559754: nop

    // 0x80559758: mul.s       $f18, $f20, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x8055975C: swc1        $f10, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f10.u32l;
    // 0x80559760: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80559764: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80559768: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8055976C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80559770: nop

    // 0x80559774: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80559778: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8055977C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80559780: bc1f        L_8055979C
    if (!c1cs) {
        // 0x80559784: swc1        $f6, 0x18($s1)
        MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
            goto L_8055979C;
    }
    // 0x80559784: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x80559788: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8055978C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80559790: nop

    // 0x80559794: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80559798: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
L_8055979C:
    // 0x8055979C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x805597A0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x805597A4: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x805597A8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x805597AC: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x805597B0: bc1fl       L_805597D0
    if (!c1cs) {
        // 0x805597B4: c.le.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
            goto L_805597D0;
    }
    goto skip_1;
    // 0x805597B4: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    skip_1:
    // 0x805597B8: lwc1        $f8, 0x1C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x805597BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x805597C0: nop

    // 0x805597C4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x805597C8: swc1        $f16, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f16.u32l;
    // 0x805597CC: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
L_805597D0:
    // 0x805597D0: nop

    // 0x805597D4: bc1t        L_805597EC
    if (c1cs) {
        // 0x805597D8: nop
    
            goto L_805597EC;
    }
    // 0x805597D8: nop

    // 0x805597DC: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x805597E0: nop

    // 0x805597E4: bc1fl       L_805597F8
    if (!c1cs) {
        // 0x805597E8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_805597F8;
    }
    goto skip_2;
    // 0x805597E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_2:
L_805597EC:
    // 0x805597EC: jal         0x80559928
    // 0x805597F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80559928(rdram, ctx);
        goto after_4;
    // 0x805597F0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x805597F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_805597F8:
    // 0x805597F8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805597FC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80559800: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80559804: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80559808: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8055980C: jr          $ra
    // 0x80559810: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80559810: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8002DC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DC8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DC90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DC94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DC98: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002DC9C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8002DCA0: lbu         $a2, 0x27($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X27);
    // 0x8002DCA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002DCA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002DCAC: jal         0x8002B9E4
    // 0x8002DCB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002B9E4(rdram, ctx);
        goto after_0;
    // 0x8002DCB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002DCB4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DCB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002DCBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002DCC0: sb          $zero, 0x1AD($v0)
    MEM_B(0X1AD, ctx->r2) = 0;
    // 0x8002DCC4: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x8002DCC8: lw          $t6, 0x138($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X138);
    // 0x8002DCCC: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8002DCD0: beql        $t6, $zero, L_8002DCE8
    if (ctx->r14 == 0) {
        // 0x8002DCD4: lwc1        $f8, 0x120($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0X120);
            goto L_8002DCE8;
    }
    goto skip_0;
    // 0x8002DCD4: lwc1        $f8, 0x120($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X120);
    skip_0:
    // 0x8002DCD8: lwc1        $f6, 0x120($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X120);
    // 0x8002DCDC: b           L_8002DCEC
    // 0x8002DCE0: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
        goto L_8002DCEC;
    // 0x8002DCE0: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8002DCE4: lwc1        $f8, 0x120($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X120);
L_8002DCE8:
    // 0x8002DCE8: add.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f0.fl;
L_8002DCEC:
    // 0x8002DCEC: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002DCF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002DCF4: swc1        $f10, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f10.u32l;
    // 0x8002DCF8: sb          $t7, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r15;
    // 0x8002DCFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002DD00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DD04: jr          $ra
    // 0x8002DD08: nop

    return;
    // 0x8002DD08: nop

;}
RECOMP_FUNC void func_8041FBE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041FBE0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8041FBE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8041FBE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8041FBEC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8041FBF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8041FBF4: jal         0x8041DB1C
    // 0x8041FBF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_8041DB1C(rdram, ctx);
        goto after_0;
    // 0x8041FBF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x8041FBFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FC00: jal         0x8041E9A8
    // 0x8041FC04: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8041E9A8(rdram, ctx);
        goto after_1;
    // 0x8041FC04: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8041FC08: beq         $v0, $zero, L_8041FCAC
    if (ctx->r2 == 0) {
        // 0x8041FC0C: lui         $at, 0x8042
        ctx->r1 = S32(RELOC_HI16(29, 0X3534) << 16);
            goto L_8041FCAC;
    }
    // 0x8041FC0C: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3534) << 16);
    // 0x8041FC10: lwc1        $f2, 0xB94($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3534));
    // 0x8041FC14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8041FC18: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(29, 0X3538) << 16);
    // 0x8041FC1C: lwc1        $f4, 0xB98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(29, 0X3538));
    // 0x8041FC20: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8041FC24: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8041FC28: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8041FC2C: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8041FC30: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8041FC34: lw          $t7, -0x76F8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X76F8);
    // 0x8041FC38: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8041FC3C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8041FC40: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8041FC44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8041FC48: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8041FC4C: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8041FC50: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8041FC54: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x8041FC58: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8041FC5C: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x8041FC60: jalr        $t9
    // 0x8041FC64: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8041FC64: nop

    after_2:
    // 0x8041FC68: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8041FC6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FC70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8041FC74: jal         0x80047F9C
    // 0x8041FC78: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_3;
    // 0x8041FC78: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    after_3:
    // 0x8041FC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FC80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8041FC84: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8041FC88: jal         0x8041FE10
    // 0x8041FC8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8041FE10(rdram, ctx);
        goto after_4;
    // 0x8041FC8C: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_4:
    // 0x8041FC90: jal         0x8041F594
    // 0x8041FC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041F594(rdram, ctx);
        goto after_5;
    // 0x8041FC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8041FC98: jal         0x8041E5E8
    // 0x8041FC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8041E5E8(rdram, ctx);
        goto after_6;
    // 0x8041FC9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8041FCA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8041FCA4: jal         0x8041E430
    // 0x8041FCA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    func_8041E430(rdram, ctx);
        goto after_7;
    // 0x8041FCA8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_7:
L_8041FCAC:
    // 0x8041FCAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8041FCB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8041FCB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8041FCB8: jr          $ra
    // 0x8041FCBC: nop

    return;
    // 0x8041FCBC: nop

;}
RECOMP_FUNC void func_805CC3B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CC3B8: lw          $t7, 0x1F4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CC3BC: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x805CC3C0: jr          $ra
    // 0x805CC3C4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    return;
    // 0x805CC3C4: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
;}
RECOMP_FUNC void func_8003635C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003635C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036368: jal         0x80065954
    // 0x8003636C: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8003636C: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x80036370: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036374: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003637C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80036380: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80036384: jal         0x80041214
    // 0x80036388: nop

    func_80041214(rdram, ctx);
        goto after_1;
    // 0x80036388: nop

    after_1:
    // 0x8003638C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036394: jr          $ra
    // 0x80036398: nop

    return;
    // 0x80036398: nop

;}
RECOMP_FUNC void func_8045F724(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045F724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8045F728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8045F72C: jal         0x8004700C
    // 0x8045F730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8045F730: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8045F734: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8045F738: lw          $a1, 0x180($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X180);
    // 0x8045F73C: beql        $a1, $zero, L_8045F864
    if (ctx->r5 == 0) {
        // 0x8045F740: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_0;
    // 0x8045F740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8045F744: beql        $v0, $zero, L_8045F864
    if (ctx->r2 == 0) {
        // 0x8045F748: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_1;
    // 0x8045F748: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8045F74C: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x8045F750: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8045F754: lw          $a0, 0x1F4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X1F4);
    // 0x8045F758: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8045F75C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8045F760: bc1fl       L_8045F864
    if (!c1cs) {
        // 0x8045F764: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_2;
    // 0x8045F764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8045F768: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x8045F76C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8045F770: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8045F774: bnel        $t8, $at, L_8045F864
    if (ctx->r24 != ctx->r1) {
        // 0x8045F778: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_3;
    // 0x8045F778: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8045F77C: lw          $a0, 0x1F4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1F4);
    // 0x8045F780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8045F784: lw          $t9, 0x34($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X34);
    // 0x8045F788: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x8045F78C: sw          $t0, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r8;
    // 0x8045F790: lwc1        $f18, 0x88($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8045F794: lwc1        $f16, 0x88($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X88);
    // 0x8045F798: lwc1        $f10, 0x84($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8045F79C: lwc1        $f8, 0x84($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X84);
    // 0x8045F7A0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8045F7A4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8045F7A8: bc1fl       L_8045F810
    if (!c1cs) {
        // 0x8045F7AC: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_8045F810;
    }
    goto skip_4;
    // 0x8045F7AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_4:
    // 0x8045F7B0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8045F7B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8045F7B8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(113, 0XACC) << 16);
    // 0x8045F7BC: lwc1        $f6, -0x414($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(113, 0XACC));
    // 0x8045F7C0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F7C4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8045F7C8: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8045F7CC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045F7D0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8045F7D4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8045F7D8: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F7DC: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8045F7E0: nop

    // 0x8045F7E4: bc1fl       L_8045F7F8
    if (!c1cs) {
        // 0x8045F7E8: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8045F7F8;
    }
    goto skip_5;
    // 0x8045F7E8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_5:
    // 0x8045F7EC: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8045F7F0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F7F4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8045F7F8:
    // 0x8045F7F8: nop

    // 0x8045F7FC: bc1fl       L_8045F864
    if (!c1cs) {
        // 0x8045F800: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_6;
    // 0x8045F800: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8045F804: b           L_8045F860
    // 0x8045F808: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
        goto L_8045F860;
    // 0x8045F808: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x8045F80C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_8045F810:
    // 0x8045F810: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(113, 0XAD0) << 16);
    // 0x8045F814: lwc1        $f18, -0x410($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(113, 0XAD0));
    // 0x8045F818: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F81C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8045F820: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8045F824: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8045F828: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8045F82C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8045F830: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F834: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8045F838: nop

    // 0x8045F83C: bc1fl       L_8045F850
    if (!c1cs) {
        // 0x8045F840: c.le.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
            goto L_8045F850;
    }
    goto skip_7;
    // 0x8045F840: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    skip_7:
    // 0x8045F844: swc1        $f12, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f12.u32l;
    // 0x8045F848: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8045F84C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
L_8045F850:
    // 0x8045F850: nop

    // 0x8045F854: bc1fl       L_8045F864
    if (!c1cs) {
        // 0x8045F858: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8045F864;
    }
    goto skip_8;
    // 0x8045F858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x8045F85C: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_8045F860:
    // 0x8045F860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8045F864:
    // 0x8045F864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045F868: jr          $ra
    // 0x8045F86C: nop

    return;
    // 0x8045F86C: nop

;}
RECOMP_FUNC void func_806E7F18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806E7F18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x806E7F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806E7F20: lw          $t7, 0x16C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X16C);
    // 0x806E7F24: lui         $t6, 0x806F
    ctx->r14 = S32(RELOC_HI16(664, 0XEA0) << 16);
    // 0x806E7F28: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x806E7F2C: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x806E7F30: addiu       $t6, $t6, -0x7F20
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(664, 0XEA0));
    // 0x806E7F34: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x806E7F38: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x806E7F3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806E7F40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x806E7F44: jal         0x806E7FF4
    // 0x806E7F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_806E7FF4(rdram, ctx);
        goto after_0;
    // 0x806E7F48: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x806E7F4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806E7F50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806E7F54: jr          $ra
    // 0x806E7F58: nop

    return;
    // 0x806E7F58: nop

;}
RECOMP_FUNC void func_8002CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002CA68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002CA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002CA70: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002CA74: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002CA78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002CA7C: addiu       $t7, $t7, 0x3450
    ctx->r15 = ADD32(ctx->r15, 0X3450);
    // 0x8002CA80: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8002CA84: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8002CA88: jal         0x8002DB14
    // 0x8002CA8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_8002DB14(rdram, ctx);
        goto after_0;
    // 0x8002CA8C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8002CA90: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8002CA94: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002CA98: sb          $t8, 0x1AC($v0)
    MEM_B(0X1AC, ctx->r2) = ctx->r24;
    // 0x8002CA9C: sw          $zero, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = 0;
    // 0x8002CAA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002CAA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002CAA8: jr          $ra
    // 0x8002CAAC: nop

    return;
    // 0x8002CAAC: nop

;}
RECOMP_FUNC void func_8045352C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045352C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80453530: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80453534: jal         0x8045341C
    // 0x80453538: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8045341C(rdram, ctx);
        goto after_0;
    // 0x80453538: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x8045353C: jal         0x80445CBC
    // 0x80453540: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80445CBC(rdram, ctx);
        goto after_1;
    // 0x80453540: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x80453544: jal         0x80445D08
    // 0x80453548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_80445D08(rdram, ctx);
        goto after_2;
    // 0x80453548: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8045354C: jal         0x804444FC
    // 0x80453550: nop

    static_98_804444FC(rdram, ctx);
        goto after_3;
    // 0x80453550: nop

    after_3:
    // 0x80453554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80453558: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8045355C: jr          $ra
    // 0x80453560: nop

    return;
    // 0x80453560: nop

;}
RECOMP_FUNC void func_80003A5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003A5C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80003A60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80003A64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80003A68: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80003A6C: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80003A70: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80003A74: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x80003A78: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80003A7C: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80003A80: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80003A84: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80003A88:
    // 0x80003A88: beq         $s0, $zero, L_80003AA8
    if (ctx->r16 == 0) {
        // 0x80003A8C: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_80003AA8;
    }
    // 0x80003A8C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80003A90: beq         $s0, $t1, L_80003ABC
    if (ctx->r16 == ctx->r9) {
        // 0x80003A94: nop
    
            goto L_80003ABC;
    }
    // 0x80003A94: nop

    // 0x80003A98: beq         $s0, $t0, L_80003AD0
    if (ctx->r16 == ctx->r8) {
        // 0x80003A9C: nop
    
            goto L_80003AD0;
    }
    // 0x80003A9C: nop

    // 0x80003AA0: b           L_80003AE0
    // 0x80003AA4: nop

        goto L_80003AE0;
    // 0x80003AA4: nop

L_80003AA8:
    // 0x80003AA8: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80003AAC: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80003AB0: addiu       $a3, $a3, 0x6C48
    ctx->r7 = ADD32(ctx->r7, 0X6C48);
    // 0x80003AB4: b           L_80003AE0
    // 0x80003AB8: addiu       $t2, $t2, 0x76EC
    ctx->r10 = ADD32(ctx->r10, 0X76EC);
        goto L_80003AE0;
    // 0x80003AB8: addiu       $t2, $t2, 0x76EC
    ctx->r10 = ADD32(ctx->r10, 0X76EC);
L_80003ABC:
    // 0x80003ABC: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80003AC0: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80003AC4: addiu       $a3, $a3, 0x6D58
    ctx->r7 = ADD32(ctx->r7, 0X6D58);
    // 0x80003AC8: b           L_80003AE0
    // 0x80003ACC: addiu       $t2, $t2, 0x76A6
    ctx->r10 = ADD32(ctx->r10, 0X76A6);
        goto L_80003AE0;
    // 0x80003ACC: addiu       $t2, $t2, 0x76A6
    ctx->r10 = ADD32(ctx->r10, 0X76A6);
L_80003AD0:
    // 0x80003AD0: lui         $a3, 0x800B
    ctx->r7 = S32(0X800B << 16);
    // 0x80003AD4: lui         $t2, 0x800B
    ctx->r10 = S32(0X800B << 16);
    // 0x80003AD8: addiu       $a3, $a3, 0x6E68
    ctx->r7 = ADD32(ctx->r7, 0X6E68);
    // 0x80003ADC: addiu       $t2, $t2, 0x7660
    ctx->r10 = ADD32(ctx->r10, 0X7660);
L_80003AE0:
    // 0x80003AE0: bne         $a2, $zero, L_80004098
    if (ctx->r6 != 0) {
        // 0x80003AE4: addiu       $a0, $a3, 0x4
        ctx->r4 = ADD32(ctx->r7, 0X4);
            goto L_80004098;
    }
    // 0x80003AE4: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x80003AE8: lh          $t6, 0xF2($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XF2);
    // 0x80003AEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003AF0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80003AF4: bne         $t6, $at, L_80003B04
    if (ctx->r14 != ctx->r1) {
        // 0x80003AF8: addiu       $a2, $a3, 0xD4
        ctx->r6 = ADD32(ctx->r7, 0XD4);
            goto L_80003B04;
    }
    // 0x80003AF8: addiu       $a2, $a3, 0xD4
    ctx->r6 = ADD32(ctx->r7, 0XD4);
    // 0x80003AFC: b           L_80003B10
    // 0x80003B00: addiu       $a2, $a3, 0xD4
    ctx->r6 = ADD32(ctx->r7, 0XD4);
        goto L_80003B10;
    // 0x80003B00: addiu       $a2, $a3, 0xD4
    ctx->r6 = ADD32(ctx->r7, 0XD4);
L_80003B04:
    // 0x80003B04: lh          $t7, 0x1E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1E);
    // 0x80003B08: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x80003B0C: lbu         $t3, 0x0($t8)
    ctx->r11 = MEM_BU(ctx->r24, 0X0);
L_80003B10:
    // 0x80003B10: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x80003B14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003B18: bne         $a0, $at, L_80003B28
    if (ctx->r4 != ctx->r1) {
        // 0x80003B1C: addu        $t9, $a0, $t2
        ctx->r25 = ADD32(ctx->r4, ctx->r10);
            goto L_80003B28;
    }
    // 0x80003B1C: addu        $t9, $a0, $t2
    ctx->r25 = ADD32(ctx->r4, ctx->r10);
    // 0x80003B20: b           L_80003B2C
    // 0x80003B24: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
        goto L_80003B2C;
    // 0x80003B24: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_80003B28:
    // 0x80003B28: lbu         $t4, 0x0($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X0);
L_80003B2C:
    // 0x80003B2C: bne         $s0, $t1, L_80003C60
    if (ctx->r16 != ctx->r9) {
        // 0x80003B30: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80003C60;
    }
    // 0x80003B30: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80003B34: bne         $t3, $at, L_80003BC8
    if (ctx->r11 != ctx->r1) {
        // 0x80003B38: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_80003BC8;
    }
    // 0x80003B38: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003B3C: lw          $a1, 0x6ABC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6ABC);
    // 0x80003B40: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003B44: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003B48: blez        $a1, L_80003B84
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80003B4C: nop
    
            goto L_80003B84;
    }
    // 0x80003B4C: nop

    // 0x80003B50: lw          $v0, 0x773C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X773C);
    // 0x80003B54: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_80003B58:
    // 0x80003B58: lbu         $t6, 0x33($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X33);
    // 0x80003B5C: bnel        $t6, $a0, L_80003B78
    if (ctx->r14 != ctx->r4) {
        // 0x80003B60: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003B78;
    }
    goto skip_0;
    // 0x80003B60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x80003B64: lw          $t7, 0xB0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB0);
    // 0x80003B68: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80003B6C: bne         $t8, $zero, L_80003B84
    if (ctx->r24 != 0) {
        // 0x80003B70: nop
    
            goto L_80003B84;
    }
    // 0x80003B70: nop

    // 0x80003B74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003B78:
    // 0x80003B78: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003B7C: bne         $at, $zero, L_80003B58
    if (ctx->r1 != 0) {
        // 0x80003B80: addiu       $v0, $v0, 0xD0
        ctx->r2 = ADD32(ctx->r2, 0XD0);
            goto L_80003B58;
    }
    // 0x80003B80: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
L_80003B84:
    // 0x80003B84: bnel        $v1, $a1, L_80003BCC
    if (ctx->r3 != ctx->r5) {
        // 0x80003B88: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80003BCC;
    }
    goto skip_1;
    // 0x80003B88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
    // 0x80003B8C: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    // 0x80003B90: sb          $t4, 0x3A($sp)
    MEM_B(0X3A, ctx->r29) = ctx->r12;
    // 0x80003B94: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80003B98: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80003B9C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80003BA0: jal         0x8000675C
    // 0x80003BA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8000675C(rdram, ctx);
        goto after_0;
    // 0x80003BA4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80003BA8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80003BAC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80003BB0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80003BB4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80003BB8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80003BBC: lbu         $t4, 0x3A($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3A);
    // 0x80003BC0: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x80003BC4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_80003BC8:
    // 0x80003BC8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_80003BCC:
    // 0x80003BCC: bne         $t4, $at, L_80003C60
    if (ctx->r12 != ctx->r1) {
        // 0x80003BD0: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_80003C60;
    }
    // 0x80003BD0: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003BD4: lw          $a1, 0x6ABC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6ABC);
    // 0x80003BD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003BDC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003BE0: blez        $a1, L_80003C1C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80003BE4: nop
    
            goto L_80003C1C;
    }
    // 0x80003BE4: nop

    // 0x80003BE8: lw          $v0, 0x773C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X773C);
    // 0x80003BEC: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_80003BF0:
    // 0x80003BF0: lbu         $t9, 0x33($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X33);
    // 0x80003BF4: bnel        $t9, $a0, L_80003C10
    if (ctx->r25 != ctx->r4) {
        // 0x80003BF8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003C10;
    }
    goto skip_2;
    // 0x80003BF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x80003BFC: lw          $t6, 0xB0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB0);
    // 0x80003C00: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003C04: bne         $t7, $zero, L_80003C1C
    if (ctx->r15 != 0) {
        // 0x80003C08: nop
    
            goto L_80003C1C;
    }
    // 0x80003C08: nop

    // 0x80003C0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003C10:
    // 0x80003C10: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003C14: bne         $at, $zero, L_80003BF0
    if (ctx->r1 != 0) {
        // 0x80003C18: addiu       $v0, $v0, 0xD0
        ctx->r2 = ADD32(ctx->r2, 0XD0);
            goto L_80003BF0;
    }
    // 0x80003C18: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
L_80003C1C:
    // 0x80003C1C: bne         $v1, $a1, L_80003C60
    if (ctx->r3 != ctx->r5) {
        // 0x80003C20: nop
    
            goto L_80003C60;
    }
    // 0x80003C20: nop

    // 0x80003C24: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x80003C28: sb          $t3, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r11;
    // 0x80003C2C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80003C30: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80003C34: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80003C38: jal         0x8000675C
    // 0x80003C3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    func_8000675C(rdram, ctx);
        goto after_1;
    // 0x80003C3C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80003C40: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80003C44: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80003C48: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80003C4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80003C50: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80003C54: lbu         $t3, 0x3B($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X3B);
    // 0x80003C58: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x80003C5C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80003C60:
    // 0x80003C60: bne         $t3, $zero, L_80003C74
    if (ctx->r11 != 0) {
        // 0x80003C64: or          $t5, $t3, $zero
        ctx->r13 = ctx->r11 | 0;
            goto L_80003C74;
    }
    // 0x80003C64: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x80003C68: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80003C6C: b           L_80003E94
    // 0x80003C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003E94;
    // 0x80003C70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003C74:
    // 0x80003C74: bne         $t4, $zero, L_80003C88
    if (ctx->r12 != 0) {
        // 0x80003C78: or          $t3, $t4, $zero
        ctx->r11 = ctx->r12 | 0;
            goto L_80003C88;
    }
    // 0x80003C78: or          $t3, $t4, $zero
    ctx->r11 = ctx->r12 | 0;
    // 0x80003C7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003C80: b           L_80003E94
    // 0x80003C84: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80003E94;
    // 0x80003C84: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80003C88:
    // 0x80003C88: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80003C8C: bne         $v0, $t5, L_80003CA4
    if (ctx->r2 != ctx->r13) {
        // 0x80003C90: nop
    
            goto L_80003CA4;
    }
    // 0x80003C90: nop

    // 0x80003C94: bne         $v0, $t3, L_80003CA4
    if (ctx->r2 != ctx->r11) {
        // 0x80003C98: nop
    
            goto L_80003CA4;
    }
    // 0x80003C98: nop

    // 0x80003C9C: b           L_80003E94
    // 0x80003CA0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_80003E94;
    // 0x80003CA0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80003CA4:
    // 0x80003CA4: bne         $v0, $t5, L_80003CB8
    if (ctx->r2 != ctx->r13) {
        // 0x80003CA8: nop
    
            goto L_80003CB8;
    }
    // 0x80003CA8: nop

    // 0x80003CAC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80003CB0: b           L_80003E94
    // 0x80003CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80003E94;
    // 0x80003CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003CB8:
    // 0x80003CB8: bne         $v0, $t3, L_80003CC8
    if (ctx->r2 != ctx->r11) {
        // 0x80003CBC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003CC8;
    }
    // 0x80003CBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003CC0: b           L_80003E94
    // 0x80003CC4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80003E94;
    // 0x80003CC4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80003CC8:
    // 0x80003CC8: bne         $s0, $zero, L_80003D88
    if (ctx->r16 != 0) {
        // 0x80003CCC: nop
    
            goto L_80003D88;
    }
    // 0x80003CCC: nop

    // 0x80003CD0: bne         $t0, $t5, L_80003D2C
    if (ctx->r8 != ctx->r13) {
        // 0x80003CD4: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80003D2C;
    }
    // 0x80003CD4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003CD8: lh          $a0, 0x6AA0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6AA0);
    // 0x80003CDC: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003CE0: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80003CE4: blez        $a0, L_80003D1C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80003CE8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80003D1C;
    }
    // 0x80003CE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80003CEC:
    // 0x80003CEC: lw          $t6, 0x2A30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2A30);
    // 0x80003CF0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003CF4: beql        $t7, $zero, L_80003D10
    if (ctx->r15 == 0) {
        // 0x80003CF8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003D10;
    }
    goto skip_3;
    // 0x80003CF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x80003CFC: lbu         $t8, 0x2A34($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A34);
    // 0x80003D00: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x80003D04: beq         $t8, $t9, L_80003D1C
    if (ctx->r24 == ctx->r25) {
        // 0x80003D08: nop
    
            goto L_80003D1C;
    }
    // 0x80003D08: nop

    // 0x80003D0C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003D10:
    // 0x80003D10: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80003D14: bne         $at, $zero, L_80003CEC
    if (ctx->r1 != 0) {
        // 0x80003D18: addiu       $v0, $v0, 0x160
        ctx->r2 = ADD32(ctx->r2, 0X160);
            goto L_80003CEC;
    }
    // 0x80003D18: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
L_80003D1C:
    // 0x80003D1C: bne         $v1, $a0, L_80003D2C
    if (ctx->r3 != ctx->r4) {
        // 0x80003D20: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003D2C;
    }
    // 0x80003D20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003D24: b           L_80003E94
    // 0x80003D28: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80003E94;
    // 0x80003D28: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80003D2C:
    // 0x80003D2C: bne         $t0, $t3, L_80003E50
    if (ctx->r8 != ctx->r11) {
        // 0x80003D30: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80003E50;
    }
    // 0x80003D30: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80003D34: lh          $a0, 0x6AA0($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6AA0);
    // 0x80003D38: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003D3C: addiu       $v0, $v0, 0x4D10
    ctx->r2 = ADD32(ctx->r2, 0X4D10);
    // 0x80003D40: blez        $a0, L_80003D78
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80003D44: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80003D78;
    }
    // 0x80003D44: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80003D48:
    // 0x80003D48: lw          $t6, 0x2A30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2A30);
    // 0x80003D4C: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003D50: beql        $t7, $zero, L_80003D6C
    if (ctx->r15 == 0) {
        // 0x80003D54: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003D6C;
    }
    goto skip_4;
    // 0x80003D54: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_4:
    // 0x80003D58: lbu         $t8, 0x2A34($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2A34);
    // 0x80003D5C: lh          $t9, 0x2A($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X2A);
    // 0x80003D60: beq         $t8, $t9, L_80003D78
    if (ctx->r24 == ctx->r25) {
        // 0x80003D64: nop
    
            goto L_80003D78;
    }
    // 0x80003D64: nop

    // 0x80003D68: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003D6C:
    // 0x80003D6C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80003D70: bne         $at, $zero, L_80003D48
    if (ctx->r1 != 0) {
        // 0x80003D74: addiu       $v0, $v0, 0x160
        ctx->r2 = ADD32(ctx->r2, 0X160);
            goto L_80003D48;
    }
    // 0x80003D74: addiu       $v0, $v0, 0x160
    ctx->r2 = ADD32(ctx->r2, 0X160);
L_80003D78:
    // 0x80003D78: bne         $v1, $a0, L_80003E50
    if (ctx->r3 != ctx->r4) {
        // 0x80003D7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003E50;
    }
    // 0x80003D7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003D80: b           L_80003E94
    // 0x80003D84: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80003E94;
    // 0x80003D84: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80003D88:
    // 0x80003D88: bnel        $s0, $t1, L_80003E54
    if (ctx->r16 != ctx->r9) {
        // 0x80003D8C: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80003E54;
    }
    goto skip_5;
    // 0x80003D8C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_5:
    // 0x80003D90: bne         $t0, $t5, L_80003DF0
    if (ctx->r8 != ctx->r13) {
        // 0x80003D94: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_80003DF0;
    }
    // 0x80003D94: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003D98: lw          $a1, 0x6ABC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6ABC);
    // 0x80003D9C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003DA0: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003DA4: blez        $a1, L_80003DE0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80003DA8: nop
    
            goto L_80003DE0;
    }
    // 0x80003DA8: nop

    // 0x80003DAC: lw          $v0, 0x773C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X773C);
    // 0x80003DB0: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_80003DB4:
    // 0x80003DB4: lbu         $t7, 0x33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X33);
    // 0x80003DB8: bnel        $t7, $a0, L_80003DD4
    if (ctx->r15 != ctx->r4) {
        // 0x80003DBC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003DD4;
    }
    goto skip_6;
    // 0x80003DBC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_6:
    // 0x80003DC0: lw          $t8, 0xB0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB0);
    // 0x80003DC4: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80003DC8: bne         $t9, $zero, L_80003DE0
    if (ctx->r25 != 0) {
        // 0x80003DCC: nop
    
            goto L_80003DE0;
    }
    // 0x80003DCC: nop

    // 0x80003DD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003DD4:
    // 0x80003DD4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003DD8: bne         $at, $zero, L_80003DB4
    if (ctx->r1 != 0) {
        // 0x80003DDC: addiu       $v0, $v0, 0xD0
        ctx->r2 = ADD32(ctx->r2, 0XD0);
            goto L_80003DB4;
    }
    // 0x80003DDC: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
L_80003DE0:
    // 0x80003DE0: bne         $v1, $a1, L_80003DF0
    if (ctx->r3 != ctx->r5) {
        // 0x80003DE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003DF0;
    }
    // 0x80003DE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003DE8: b           L_80003E94
    // 0x80003DEC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80003E94;
    // 0x80003DEC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80003DF0:
    // 0x80003DF0: bne         $t0, $t3, L_80003E50
    if (ctx->r8 != ctx->r11) {
        // 0x80003DF4: lui         $a1, 0x800B
        ctx->r5 = S32(0X800B << 16);
            goto L_80003E50;
    }
    // 0x80003DF4: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x80003DF8: lw          $a1, 0x6ABC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6ABC);
    // 0x80003DFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003E00: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x80003E04: blez        $a1, L_80003E40
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80003E08: nop
    
            goto L_80003E40;
    }
    // 0x80003E08: nop

    // 0x80003E0C: lw          $v0, 0x773C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X773C);
    // 0x80003E10: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_80003E14:
    // 0x80003E14: lbu         $t6, 0x33($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X33);
    // 0x80003E18: bnel        $t6, $a0, L_80003E34
    if (ctx->r14 != ctx->r4) {
        // 0x80003E1C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80003E34;
    }
    goto skip_7;
    // 0x80003E1C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_7:
    // 0x80003E20: lw          $t7, 0xB0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB0);
    // 0x80003E24: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80003E28: bne         $t8, $zero, L_80003E40
    if (ctx->r24 != 0) {
        // 0x80003E2C: nop
    
            goto L_80003E40;
    }
    // 0x80003E2C: nop

    // 0x80003E30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003E34:
    // 0x80003E34: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80003E38: bne         $at, $zero, L_80003E14
    if (ctx->r1 != 0) {
        // 0x80003E3C: addiu       $v0, $v0, 0xD0
        ctx->r2 = ADD32(ctx->r2, 0XD0);
            goto L_80003E14;
    }
    // 0x80003E3C: addiu       $v0, $v0, 0xD0
    ctx->r2 = ADD32(ctx->r2, 0XD0);
L_80003E40:
    // 0x80003E40: bne         $v1, $a1, L_80003E50
    if (ctx->r3 != ctx->r5) {
        // 0x80003E44: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003E50;
    }
    // 0x80003E44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E48: b           L_80003E94
    // 0x80003E4C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80003E94;
    // 0x80003E4C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80003E50:
    // 0x80003E50: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80003E54:
    // 0x80003E54: bne         $v0, $zero, L_80003E74
    if (ctx->r2 != 0) {
        // 0x80003E58: nop
    
            goto L_80003E74;
    }
    // 0x80003E58: nop

    // 0x80003E5C: bne         $t1, $t5, L_80003E94
    if (ctx->r9 != ctx->r13) {
        // 0x80003E60: nop
    
            goto L_80003E94;
    }
    // 0x80003E60: nop

    // 0x80003E64: beq         $t1, $t3, L_80003E8C
    if (ctx->r9 == ctx->r11) {
        // 0x80003E68: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80003E8C;
    }
    // 0x80003E68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80003E6C: b           L_80003E94
    // 0x80003E70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80003E94;
    // 0x80003E70: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80003E74:
    // 0x80003E74: bne         $t1, $t3, L_80003E94
    if (ctx->r9 != ctx->r11) {
        // 0x80003E78: nop
    
            goto L_80003E94;
    }
    // 0x80003E78: nop

    // 0x80003E7C: beq         $t1, $t5, L_80003E8C
    if (ctx->r9 == ctx->r13) {
        // 0x80003E80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80003E8C;
    }
    // 0x80003E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003E84: b           L_80003E94
    // 0x80003E88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80003E94;
    // 0x80003E88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80003E8C:
    // 0x80003E8C: b           L_8000414C
    // 0x80003E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000414C;
    // 0x80003E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80003E94:
    // 0x80003E94: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003E98: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003E9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80003EA0: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80003EA4: lh          $v1, 0x1E($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X1E);
    // 0x80003EA8: beq         $v1, $at, L_80003EEC
    if (ctx->r3 == ctx->r1) {
        // 0x80003EAC: addu        $t9, $t2, $v1
        ctx->r25 = ADD32(ctx->r10, ctx->r3);
            goto L_80003EEC;
    }
    // 0x80003EAC: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x80003EB0: bne         $s0, $t1, L_80003EEC
    if (ctx->r16 != ctx->r9) {
        // 0x80003EB4: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_80003EEC;
    }
    // 0x80003EB4: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80003EB8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80003EBC: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80003EC0: mflo        $t7
    ctx->r15 = lo;
    // 0x80003EC4: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x80003EC8: lh          $a0, 0x1E($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X1E);
    // 0x80003ECC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80003ED0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80003ED4: jal         0x8000344C
    // 0x80003ED8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    func_8000344C(rdram, ctx);
        goto after_2;
    // 0x80003ED8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_2:
    // 0x80003EDC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80003EE0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80003EE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80003EE8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_80003EEC:
    // 0x80003EEC: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x80003EF0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80003EF4: addiu       $v0, $a3, 0xD8
    ctx->r2 = ADD32(ctx->r7, 0XD8);
    // 0x80003EF8: beql        $a0, $zero, L_80003F14
    if (ctx->r4 == 0) {
        // 0x80003EFC: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_80003F14;
    }
    goto skip_8;
    // 0x80003EFC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_8:
    // 0x80003F00: beq         $a0, $at, L_80003FD8
    if (ctx->r4 == ctx->r1) {
        // 0x80003F04: addiu       $v0, $a3, 0xD8
        ctx->r2 = ADD32(ctx->r7, 0XD8);
            goto L_80003FD8;
    }
    // 0x80003F04: addiu       $v0, $a3, 0xD8
    ctx->r2 = ADD32(ctx->r7, 0XD8);
    // 0x80003F08: b           L_8000414C
    // 0x80003F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000414C;
    // 0x80003F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80003F10: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_80003F14:
    // 0x80003F14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80003F18: sw          $t9, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r25;
    // 0x80003F1C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80003F20: sh          $t6, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r14;
    // 0x80003F24: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80003F28: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x80003F2C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80003F30: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003F34: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80003F38: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80003F3C: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x80003F40: beql        $a0, $at, L_80003FC4
    if (ctx->r4 == ctx->r1) {
        // 0x80003F44: lw          $v1, 0x14($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X14);
            goto L_80003FC4;
    }
    goto skip_9;
    // 0x80003F44: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    skip_9:
    // 0x80003F48: lw          $t7, 0x20($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X20);
    // 0x80003F4C: addu        $t9, $t2, $a0
    ctx->r25 = ADD32(ctx->r10, ctx->r4);
    // 0x80003F50: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x80003F54: beql        $at, $zero, L_80003FC4
    if (ctx->r1 == 0) {
        // 0x80003F58: lw          $v1, 0x14($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X14);
            goto L_80003FC4;
    }
    goto skip_10;
    // 0x80003F58: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    skip_10:
    // 0x80003F5C: beq         $s0, $zero, L_80003F74
    if (ctx->r16 == 0) {
        // 0x80003F60: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_80003F74;
    }
    // 0x80003F60: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x80003F64: beql        $s0, $t1, L_80003F94
    if (ctx->r16 == ctx->r9) {
        // 0x80003F68: lh          $a0, 0x2A($a2)
        ctx->r4 = MEM_H(ctx->r6, 0X2A);
            goto L_80003F94;
    }
    goto skip_11;
    // 0x80003F68: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    skip_11:
    // 0x80003F6C: b           L_80003FAC
    // 0x80003F70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80003FAC;
    // 0x80003F70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80003F74:
    // 0x80003F74: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x80003F78: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80003F7C: jal         0x80003530
    // 0x80003F80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80003530(rdram, ctx);
        goto after_3;
    // 0x80003F80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x80003F84: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80003F88: b           L_80003FA8
    // 0x80003F8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_80003FA8;
    // 0x80003F8C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80003F90: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_80003F94:
    // 0x80003F94: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80003F98: jal         0x8000344C
    // 0x80003F9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8000344C(rdram, ctx);
        goto after_4;
    // 0x80003F9C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x80003FA0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80003FA4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80003FA8:
    // 0x80003FA8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_80003FAC:
    // 0x80003FAC: sh          $t6, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r14;
    // 0x80003FB0: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80003FB4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80003FB8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80003FBC: sw          $t9, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r25;
    // 0x80003FC0: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
L_80003FC4:
    // 0x80003FC4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80003FC8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80003FCC: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x80003FD0: b           L_8000414C
    // 0x80003FD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_8000414C;
    // 0x80003FD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80003FD8:
    // 0x80003FD8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003FDC: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80003FE0: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80003FE4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80003FE8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80003FEC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80003FF0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80003FF4: sw          $t9, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r25;
    // 0x80003FF8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80003FFC: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    // 0x80004000: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80004004: sh          $t6, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r14;
    // 0x80004008: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8000400C: or          $t8, $t9, $zero
    ctx->r24 = ctx->r25 | 0;
    // 0x80004010: beq         $a0, $at, L_80004088
    if (ctx->r4 == ctx->r1) {
        // 0x80004014: sw          $t7, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r15;
            goto L_80004088;
    }
    // 0x80004014: sw          $t7, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r15;
    // 0x80004018: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8000401C: addu        $t6, $t2, $a0
    ctx->r14 = ADD32(ctx->r10, ctx->r4);
    // 0x80004020: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x80004024: beq         $at, $zero, L_80004088
    if (ctx->r1 == 0) {
        // 0x80004028: nop
    
            goto L_80004088;
    }
    // 0x80004028: nop

    // 0x8000402C: beq         $s0, $zero, L_80004044
    if (ctx->r16 == 0) {
        // 0x80004030: sb          $zero, 0x0($t6)
        MEM_B(0X0, ctx->r14) = 0;
            goto L_80004044;
    }
    // 0x80004030: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80004034: beql        $s0, $t1, L_80004064
    if (ctx->r16 == ctx->r9) {
        // 0x80004038: lh          $a0, 0x1E($a2)
        ctx->r4 = MEM_H(ctx->r6, 0X1E);
            goto L_80004064;
    }
    goto skip_12;
    // 0x80004038: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    skip_12:
    // 0x8000403C: b           L_8000407C
    // 0x80004040: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8000407C;
    // 0x80004040: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_80004044:
    // 0x80004044: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    // 0x80004048: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000404C: jal         0x80003530
    // 0x80004050: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80003530(rdram, ctx);
        goto after_5;
    // 0x80004050: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_5:
    // 0x80004054: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80004058: b           L_80004078
    // 0x8000405C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_80004078;
    // 0x8000405C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80004060: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_80004064:
    // 0x80004064: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80004068: jal         0x8000344C
    // 0x8000406C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_8000344C(rdram, ctx);
        goto after_6;
    // 0x8000406C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_6:
    // 0x80004070: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80004074: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_80004078:
    // 0x80004078: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8000407C:
    // 0x8000407C: sh          $t7, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r15;
    // 0x80004080: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80004084: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80004088:
    // 0x80004088: b           L_80003FC4
    // 0x8000408C: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
        goto L_80003FC4;
    // 0x8000408C: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x80004090: b           L_8000414C
    // 0x80004094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000414C;
    // 0x80004094: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004098:
    // 0x80004098: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8000409C: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800040A0: jal         0x80003698
    // 0x800040A4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    func_80003698(rdram, ctx);
        goto after_7;
    // 0x800040A4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    after_7:
    // 0x800040A8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x800040AC: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x800040B0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800040B4: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x800040B8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800040BC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800040C0: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800040C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800040C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800040CC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800040D0: bne         $v0, $zero, L_80004100
    if (ctx->r2 != 0) {
        // 0x800040D4: sw          $v0, 0x14($t7)
        MEM_W(0X14, ctx->r15) = ctx->r2;
            goto L_80004100;
    }
    // 0x800040D4: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x800040D8: beq         $a2, $zero, L_800040F8
    if (ctx->r6 == 0) {
        // 0x800040DC: nop
    
            goto L_800040F8;
    }
    // 0x800040DC: nop

    // 0x800040E0: beq         $a2, $t1, L_800040F8
    if (ctx->r6 == ctx->r9) {
        // 0x800040E4: nop
    
            goto L_800040F8;
    }
    // 0x800040E4: nop

    // 0x800040E8: bnel        $a2, $t0, L_80004104
    if (ctx->r6 != ctx->r8) {
        // 0x800040EC: lw          $t9, 0x0($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X0);
            goto L_80004104;
    }
    goto skip_13;
    // 0x800040EC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    skip_13:
    // 0x800040F0: b           L_80003A88
    // 0x800040F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80003A88;
    // 0x800040F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800040F8:
    // 0x800040F8: b           L_8000414C
    // 0x800040FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000414C;
    // 0x800040FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004100:
    // 0x80004100: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
L_80004104:
    // 0x80004104: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x80004108: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000410C: mflo        $t6
    ctx->r14 = lo;
    // 0x80004110: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80004114: sh          $t8, 0x1E($t7)
    MEM_H(0X1E, ctx->r15) = ctx->r24;
    // 0x80004118: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8000411C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80004120: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80004124: mflo        $t8
    ctx->r24 = lo;
    // 0x80004128: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8000412C: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x80004130: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80004134: multu       $v1, $ra
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80004138: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8000413C: mflo        $t6
    ctx->r14 = lo;
    // 0x80004140: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80004144: lw          $v0, 0x14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X14);
    // 0x80004148: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8000414C:
    // 0x8000414C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004150: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004154: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80004158: jr          $ra
    // 0x8000415C: nop

    return;
    // 0x8000415C: nop

;}
RECOMP_FUNC void func_80037D88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037D88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80037D8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80037D90: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80037D94: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80037D98: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x80037D9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037DA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80037DA4: lw          $t6, 0x14($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X14);
    // 0x80037DA8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80037DAC: beq         $t6, $zero, L_80037DD4
    if (ctx->r14 == 0) {
        // 0x80037DB0: nop
    
            goto L_80037DD4;
    }
    // 0x80037DB0: nop

    // 0x80037DB4: lw          $t7, 0x78($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X78);
    // 0x80037DB8: beq         $t7, $zero, L_80037DD4
    if (ctx->r15 == 0) {
        // 0x80037DBC: nop
    
            goto L_80037DD4;
    }
    // 0x80037DBC: nop

    // 0x80037DC0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80037DC4: jal         0x80037498
    // 0x80037DC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80037498(rdram, ctx);
        goto after_0;
    // 0x80037DC8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_0:
    // 0x80037DCC: b           L_80037EB4
    // 0x80037DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80037EB4;
    // 0x80037DD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037DD4:
    // 0x80037DD4: jal         0x800356E8
    // 0x80037DD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    func_800356E8(rdram, ctx);
        goto after_1;
    // 0x80037DD8: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x80037DDC: lh          $t8, 0x148($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X148);
    // 0x80037DE0: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80037DE4: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x80037DE8: beql        $t8, $zero, L_80037EA4
    if (ctx->r24 == 0) {
        // 0x80037DEC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037EA4;
    }
    goto skip_0;
    // 0x80037DEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80037DF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037DF4: nop

    // 0x80037DF8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80037DFC: nop

    // 0x80037E00: bc1fl       L_80037EA4
    if (!c1cs) {
        // 0x80037E04: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037EA4;
    }
    goto skip_1;
    // 0x80037E04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80037E08: jal         0x8001D770
    // 0x80037E0C: nop

    func_8001D770(rdram, ctx);
        goto after_2;
    // 0x80037E0C: nop

    after_2:
    // 0x80037E10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80037E14: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80037E18: jal         0x80067BF8
    // 0x80037E1C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    func_80067BF8(rdram, ctx);
        goto after_3;
    // 0x80037E1C: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    after_3:
    // 0x80037E20: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x80037E24: jal         0x80067818
    // 0x80037E28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_4;
    // 0x80037E28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80037E2C: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80037E30: jal         0x80067BBC
    // 0x80037E34: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_5;
    // 0x80037E34: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_5:
    // 0x80037E38: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80037E3C: jal         0x80067818
    // 0x80037E40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_6;
    // 0x80037E40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80037E44: sh          $zero, 0x148($s1)
    MEM_H(0X148, ctx->r17) = 0;
    // 0x80037E48: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80037E4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80037E50: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80037E54: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x80037E58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80037E5C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80037E60: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80037E64: lui         $at, 0xC1B4
    ctx->r1 = S32(0XC1B4 << 16);
    // 0x80037E68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80037E6C: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80037E70: lw          $t9, -0x76F8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X76F8);
    // 0x80037E74: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80037E78: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80037E7C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80037E80: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x80037E84: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80037E88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037E8C: lw          $t9, 0x40($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X40);
    // 0x80037E90: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80037E94: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80037E98: jalr        $t9
    // 0x80037E9C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80037E9C: nop

    after_7:
    // 0x80037EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80037EA4:
    // 0x80037EA4: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x80037EA8: jal         0x80037498
    // 0x80037EAC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80037498(rdram, ctx);
        goto after_8;
    // 0x80037EAC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_8:
    // 0x80037EB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80037EB4:
    // 0x80037EB4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80037EB8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80037EBC: jr          $ra
    // 0x80037EC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80037EC0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_8005FFB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005FFB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005FFB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FFBC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8005FFC0: jal         0x80049018
    // 0x8005FFC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x8005FFC4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005FFC8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FFCC: beq         $v0, $zero, L_8005FFFC
    if (ctx->r2 == 0) {
        // 0x8005FFD0: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8005FFFC;
    }
    // 0x8005FFD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005FFD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FFD8: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8005FFDC: lh          $t7, 0x50($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X50);
    // 0x8005FFE0: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x8005FFE4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8005FFE8: lwc1        $f4, 0x0($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X0);
    // 0x8005FFEC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005FFF0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005FFF4: b           L_80060020
    // 0x8005FFF8: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
        goto L_80060020;
    // 0x8005FFF8: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
L_8005FFFC:
    // 0x8005FFFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80060000: lwc1        $f16, 0x84($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80060004: lh          $t9, 0x50($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X50);
    // 0x80060008: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x8006000C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80060010: lwc1        $f18, 0x0($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80060014: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060018: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006001C: add.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f16.fl;
L_80060020:
    // 0x80060020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80060024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80060028: jr          $ra
    // 0x8006002C: nop

    return;
    // 0x8006002C: nop

;}
RECOMP_FUNC void func_805DAF08(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DAF08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DAF0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DAF10: lw          $t6, 0x160($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X160);
    // 0x805DAF14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x805DAF18: beq         $t6, $zero, L_805DAF54
    if (ctx->r14 == 0) {
        // 0x805DAF1C: nop
    
            goto L_805DAF54;
    }
    // 0x805DAF1C: nop

    // 0x805DAF20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x805DAF24: lw          $t9, 0x160($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X160);
    // 0x805DAF28: jalr        $t9
    // 0x805DAF2C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x805DAF2C: nop

    after_0:
    // 0x805DAF30: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x805DAF34: lw          $t7, 0x15C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X15C);
    // 0x805DAF38: lw          $t0, 0x14C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14C);
    // 0x805DAF3C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x805DAF40: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x805DAF44: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x805DAF48: lhu         $t3, 0x0($t2)
    ctx->r11 = MEM_HU(ctx->r10, 0X0);
    // 0x805DAF4C: b           L_805DAF54
    // 0x805DAF50: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
        goto L_805DAF54;
    // 0x805DAF50: sh          $t3, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r11;
L_805DAF54:
    // 0x805DAF54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DAF58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DAF5C: jr          $ra
    // 0x805DAF60: nop

    return;
    // 0x805DAF60: nop

;}
RECOMP_FUNC void func_804BD364(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804BD364: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804BD368: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804BD36C: jal         0x8004700C
    // 0x804BD370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x804BD370: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804BD374: beq         $v0, $zero, L_804BD394
    if (ctx->r2 == 0) {
        // 0x804BD378: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804BD394;
    }
    // 0x804BD378: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804BD37C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x804BD380: lw          $t7, 0x180($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X180);
    // 0x804BD384: bnel        $t6, $t7, L_804BD398
    if (ctx->r14 != ctx->r15) {
        // 0x804BD388: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_804BD398;
    }
    goto skip_0;
    // 0x804BD388: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x804BD38C: b           L_804BD398
    // 0x804BD390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_804BD398;
    // 0x804BD390: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_804BD394:
    // 0x804BD394: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804BD398:
    // 0x804BD398: jr          $ra
    // 0x804BD39C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804BD39C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806B10F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B10F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806B10F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806B10FC: jal         0x8004700C
    // 0x806B1100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x806B1100: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x806B1104: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B1108: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x806B110C: beql        $a0, $zero, L_806B118C
    if (ctx->r4 == 0) {
        // 0x806B1110: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_806B118C;
    }
    goto skip_0;
    // 0x806B1110: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x806B1114: beq         $v0, $zero, L_806B1188
    if (ctx->r2 == 0) {
        // 0x806B1118: lui         $t6, 0x806B
        ctx->r14 = S32(RELOC_HI16(598, 0X103C) << 16);
            goto L_806B1188;
    }
    // 0x806B1118: lui         $t6, 0x806B
    ctx->r14 = S32(RELOC_HI16(598, 0X103C) << 16);
    // 0x806B111C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x806B1120: lw          $v0, 0x1F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1F4);
    // 0x806B1124: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806B1128: addiu       $t6, $t6, 0xFCC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(598, 0X103C));
    // 0x806B112C: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x806B1130: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x806B1134: lui         $at, 0x806B
    ctx->r1 = S32(RELOC_HI16(598, 0X1774) << 16);
    // 0x806B1138: swc1        $f4, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f4.u32l;
    // 0x806B113C: lwc1        $f6, 0x1704($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(598, 0X1774));
    // 0x806B1140: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806B1144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x806B1148: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x806B114C: swc1        $f8, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f8.u32l;
    // 0x806B1150: sw          $zero, 0x108($v0)
    MEM_W(0X108, ctx->r2) = 0;
    // 0x806B1154: sw          $zero, 0x104($v0)
    MEM_W(0X104, ctx->r2) = 0;
    // 0x806B1158: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x806B115C: jal         0x8004816C
    // 0x806B1160: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004816C(rdram, ctx);
        goto after_1;
    // 0x806B1160: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x806B1164: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x806B1168: lui         $t7, 0x8005
    ctx->r15 = S32(0X8005 << 16);
    // 0x806B116C: addiu       $t7, $t7, -0x7C48
    ctx->r15 = ADD32(ctx->r15, -0X7C48);
    // 0x806B1170: jal         0x8005FD1C
    // 0x806B1174: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    func_8005FD1C(rdram, ctx);
        goto after_2;
    // 0x806B1174: sw          $t7, 0x130($a0)
    MEM_W(0X130, ctx->r4) = ctx->r15;
    after_2:
    // 0x806B1178: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x806B117C: lui         $t8, 0x8002
    ctx->r24 = S32(0X8002 << 16);
    // 0x806B1180: addiu       $t8, $t8, 0x33B4
    ctx->r24 = ADD32(ctx->r24, 0X33B4);
    // 0x806B1184: sw          $t8, 0x130($t9)
    MEM_W(0X130, ctx->r25) = ctx->r24;
L_806B1188:
    // 0x806B1188: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_806B118C:
    // 0x806B118C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806B1190: jr          $ra
    // 0x806B1194: nop

    return;
    // 0x806B1194: nop

;}
RECOMP_FUNC void func_806FA738(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806FA738: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x806FA73C: lw          $a0, 0x14A0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14A0);
    // 0x806FA740: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x806FA744: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x806FA748: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x806FA74C: addu        $a2, $a1, $t6
    ctx->r6 = ADD32(ctx->r5, ctx->r14);
    // 0x806FA750: lwc1        $f4, 0xA0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA754: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x806FA758: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA75C: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x806FA760: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA764: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA768: addiu       $v0, $a1, 0x10
    ctx->r2 = ADD32(ctx->r5, 0X10);
    // 0x806FA76C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806FA770: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x806FA774: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x806FA778: lwc1        $f10, -0x5C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA77C: sub.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x806FA780: bne         $at, $zero, L_806FA790
    if (ctx->r1 != 0) {
        // 0x806FA784: swc1        $f16, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
            goto L_806FA790;
    }
    // 0x806FA784: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x806FA788: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA78C: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA790:
    // 0x806FA790: lwc1        $f18, 0xA0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA794: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA798: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA79C: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x806FA7A0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA7A4: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA7A8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x806FA7AC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x806FA7B0: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x806FA7B4: lwc1        $f8, -0x5C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA7B8: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x806FA7BC: bne         $at, $zero, L_806FA7CC
    if (ctx->r1 != 0) {
        // 0x806FA7C0: swc1        $f10, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
            goto L_806FA7CC;
    }
    // 0x806FA7C0: swc1        $f10, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f10.u32l;
    // 0x806FA7C4: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA7C8: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA7CC:
    // 0x806FA7CC: lwc1        $f16, 0xA0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA7D0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA7D4: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA7D8: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x806FA7DC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA7E0: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA7E4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806FA7E8: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x806FA7EC: lwc1        $f6, -0x5C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA7F0: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x806FA7F4: bne         $at, $zero, L_806FA804
    if (ctx->r1 != 0) {
        // 0x806FA7F8: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_806FA804;
    }
    // 0x806FA7F8: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x806FA7FC: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA800: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA804:
    // 0x806FA804: lwc1        $f10, 0xA0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XA0);
L_806FA808:
    // 0x806FA808: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA80C: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA810: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x806FA814: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x806FA818: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA81C: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA820: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x806FA824: swc1        $f18, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f18.u32l;
    // 0x806FA828: lwc1        $f4, -0x5C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA82C: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x806FA830: bne         $at, $zero, L_806FA840
    if (ctx->r1 != 0) {
        // 0x806FA834: swc1        $f6, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
            goto L_806FA840;
    }
    // 0x806FA834: swc1        $f6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f6.u32l;
    // 0x806FA838: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA83C: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA840:
    // 0x806FA840: lwc1        $f8, 0xA0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA844: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA848: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA84C: sub.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x806FA850: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA854: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA858: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806FA85C: swc1        $f16, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f16.u32l;
    // 0x806FA860: lwc1        $f18, -0x5C($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA864: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x806FA868: bne         $at, $zero, L_806FA878
    if (ctx->r1 != 0) {
        // 0x806FA86C: swc1        $f4, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
            goto L_806FA878;
    }
    // 0x806FA86C: swc1        $f4, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f4.u32l;
    // 0x806FA870: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA874: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA878:
    // 0x806FA878: lwc1        $f6, 0xA0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA87C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA880: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA884: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x806FA888: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA88C: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA890: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806FA894: swc1        $f10, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f10.u32l;
    // 0x806FA898: lwc1        $f16, -0x5C($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA89C: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x806FA8A0: bne         $at, $zero, L_806FA8B0
    if (ctx->r1 != 0) {
        // 0x806FA8A4: swc1        $f18, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
            goto L_806FA8B0;
    }
    // 0x806FA8A4: swc1        $f18, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f18.u32l;
    // 0x806FA8A8: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA8AC: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA8B0:
    // 0x806FA8B0: lwc1        $f4, 0xA0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XA0);
    // 0x806FA8B4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x806FA8B8: slti        $at, $a0, 0x280
    ctx->r1 = SIGNED(ctx->r4) < 0X280 ? 1 : 0;
    // 0x806FA8BC: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x806FA8C0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806FA8C4: addiu       $a2, $a2, 0x100
    ctx->r6 = ADD32(ctx->r6, 0X100);
    // 0x806FA8C8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806FA8CC: swc1        $f8, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f8.u32l;
    // 0x806FA8D0: lwc1        $f10, -0x5C($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, -0X5C);
    // 0x806FA8D4: sub.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x806FA8D8: bne         $at, $zero, L_806FA8E8
    if (ctx->r1 != 0) {
        // 0x806FA8DC: swc1        $f16, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
            goto L_806FA8E8;
    }
    // 0x806FA8DC: swc1        $f16, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f16.u32l;
    // 0x806FA8E0: addiu       $a0, $a0, -0x280
    ctx->r4 = ADD32(ctx->r4, -0X280);
    // 0x806FA8E4: addiu       $a2, $a2, -0x1400
    ctx->r6 = ADD32(ctx->r6, -0X1400);
L_806FA8E8:
    // 0x806FA8E8: bnel        $v1, $a1, L_806FA808
    if (ctx->r3 != ctx->r5) {
        // 0x806FA8EC: lwc1        $f10, 0xA0($a2)
        ctx->f10.u32l = MEM_W(ctx->r6, 0XA0);
            goto L_806FA808;
    }
    goto skip_0;
    // 0x806FA8EC: lwc1        $f10, 0xA0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0XA0);
    skip_0:
    // 0x806FA8F0: jr          $ra
    // 0x806FA8F4: nop

    return;
    // 0x806FA8F4: nop

;}
RECOMP_FUNC void func_804A4D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4D44: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A4D48: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A4D4C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A4D50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A4D54: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A4D58: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A4D5C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A4D60: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A4D64: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A4D68: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A4D6C: jr          $ra
    // 0x804A4D70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A4D70: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80680C2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80680C2C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x80680C30: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(550, 0X384) << 16);
    // 0x80680C34: addiu       $t6, $t6, 0x794
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(550, 0X384));
    // 0x80680C38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80680C3C: jr          $ra
    // 0x80680C40: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x80680C40: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_8059FAD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8059FAD8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8059FADC: lhu         $t6, 0x8($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8);
    // 0x8059FAE0: andi        $t7, $t6, 0xFFF7
    ctx->r15 = ctx->r14 & 0XFFF7;
    // 0x8059FAE4: jr          $ra
    // 0x8059FAE8: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    return;
    // 0x8059FAE8: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_806829D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806829D0: slti        $at, $a0, 0x21C
    ctx->r1 = SIGNED(ctx->r4) < 0X21C ? 1 : 0;
    // 0x806829D4: beq         $at, $zero, L_806829E8
    if (ctx->r1 == 0) {
        // 0x806829D8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_806829E8;
    }
    // 0x806829D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806829DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x806829E0: jr          $ra
    // 0x806829E4: nop

    return;
    // 0x806829E4: nop

L_806829E8:
    // 0x806829E8: slti        $at, $a0, 0x3C0
    ctx->r1 = SIGNED(ctx->r4) < 0X3C0 ? 1 : 0;
    // 0x806829EC: beq         $at, $zero, L_80682A24
    if (ctx->r1 == 0) {
        // 0x806829F0: addiu       $t6, $a0, -0x21C
        ctx->r14 = ADD32(ctx->r4, -0X21C);
            goto L_80682A24;
    }
    // 0x806829F0: addiu       $t6, $a0, -0x21C
    ctx->r14 = ADD32(ctx->r4, -0X21C);
    // 0x806829F4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x806829F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x806829FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80682A00: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80682A04: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x80682A08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80682A0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80682A10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80682A14: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80682A18: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80682A1C: jr          $ra
    // 0x80682A20: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    return;
    // 0x80682A20: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_80682A24:
    // 0x80682A24: slti        $at, $a0, 0x1B6C
    ctx->r1 = SIGNED(ctx->r4) < 0X1B6C ? 1 : 0;
    // 0x80682A28: beq         $at, $zero, L_80682A3C
    if (ctx->r1 == 0) {
        // 0x80682A2C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80682A3C;
    }
    // 0x80682A2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682A30: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80682A34: jr          $ra
    // 0x80682A38: nop

    return;
    // 0x80682A38: nop

L_80682A3C:
    // 0x80682A3C: slti        $at, $a0, 0x1CD4
    ctx->r1 = SIGNED(ctx->r4) < 0X1CD4 ? 1 : 0;
    // 0x80682A40: beq         $at, $zero, L_80682A78
    if (ctx->r1 == 0) {
        // 0x80682A44: addiu       $t7, $a0, -0x1B6C
        ctx->r15 = ADD32(ctx->r4, -0X1B6C);
            goto L_80682A78;
    }
    // 0x80682A44: addiu       $t7, $a0, -0x1B6C
    ctx->r15 = ADD32(ctx->r4, -0X1B6C);
    // 0x80682A48: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80682A4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80682A50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80682A54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80682A58: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80682A5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80682A60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80682A64: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80682A68: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80682A6C: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80682A70: jr          $ra
    // 0x80682A74: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    return;
    // 0x80682A74: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
L_80682A78:
    // 0x80682A78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80682A7C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80682A80: nop

    // 0x80682A84: jr          $ra
    // 0x80682A88: nop

    return;
    // 0x80682A88: nop

;}
RECOMP_FUNC void func_80048874(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048874: lw          $t6, 0x15C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X15C);
    // 0x80048878: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x8004887C: lw          $v1, 0x7F78($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7F78);
    // 0x80048880: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80048884: addiu       $v0, $a0, 0x14C
    ctx->r2 = ADD32(ctx->r4, 0X14C);
    // 0x80048888: divu        $zero, $v1, $t7
    lo = S32(U32(ctx->r3) / U32(ctx->r15)); hi = S32(U32(ctx->r3) % U32(ctx->r15));
    // 0x8004888C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80048890: bne         $t7, $zero, L_8004889C
    if (ctx->r15 != 0) {
        // 0x80048894: nop
    
            goto L_8004889C;
    }
    // 0x80048894: nop

    // 0x80048898: break       7
    do_break(2147780760);
L_8004889C:
    // 0x8004889C: bnel        $t8, $zero, L_800488F0
    if (ctx->r24 != 0) {
        // 0x800488A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800488F0;
    }
    goto skip_0;
    // 0x800488A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800488A4: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x800488A8: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800488AC: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x800488B0: divu        $zero, $v1, $t9
    lo = S32(U32(ctx->r3) / U32(ctx->r25)); hi = S32(U32(ctx->r3) % U32(ctx->r25));
    // 0x800488B4: mflo        $a1
    ctx->r5 = lo;
    // 0x800488B8: bne         $t9, $zero, L_800488C4
    if (ctx->r25 != 0) {
        // 0x800488BC: nop
    
            goto L_800488C4;
    }
    // 0x800488BC: nop

    // 0x800488C0: break       7
    do_break(2147780800);
L_800488C4:
    // 0x800488C4: divu        $zero, $a1, $t0
    lo = S32(U32(ctx->r5) / U32(ctx->r8)); hi = S32(U32(ctx->r5) % U32(ctx->r8));
    // 0x800488C8: mfhi        $a2
    ctx->r6 = hi;
    // 0x800488CC: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800488D0: bne         $t0, $zero, L_800488DC
    if (ctx->r8 != 0) {
        // 0x800488D4: nop
    
            goto L_800488DC;
    }
    // 0x800488D4: nop

    // 0x800488D8: break       7
    do_break(2147780824);
L_800488DC:
    // 0x800488DC: bnel        $a2, $zero, L_800488F0
    if (ctx->r6 != 0) {
        // 0x800488E0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800488F0;
    }
    goto skip_1;
    // 0x800488E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800488E4: jr          $ra
    // 0x800488E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800488E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800488EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800488F0:
    // 0x800488F0: jr          $ra
    // 0x800488F4: nop

    return;
    // 0x800488F4: nop

;}
RECOMP_FUNC void func_804455B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804455B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804455B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804455B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x804455BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x804455C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x804455C4: jal         0x80047090
    // 0x804455C8: addiu       $a0, $zero, 0x40F7
    ctx->r4 = ADD32(0, 0X40F7);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804455C8: addiu       $a0, $zero, 0x40F7
    ctx->r4 = ADD32(0, 0X40F7);
    after_0:
    // 0x804455CC: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804455D0: beq         $v0, $at, L_8044571C
    if (ctx->r2 == ctx->r1) {
        // 0x804455D4: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_8044571C;
    }
    // 0x804455D4: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804455D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804455DC: lui         $at, 0x40F7
    ctx->r1 = S32(0X40F7 << 16);
    // 0x804455E0: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x804455E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x804455E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x804455EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x804455F0: jal         0x8004613C
    // 0x804455F4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x804455F4: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x804455F8: beq         $v0, $zero, L_8044571C
    if (ctx->r2 == 0) {
        // 0x804455FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8044571C;
    }
    // 0x804455FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80445600: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80445604: jal         0x80047F9C
    // 0x80445608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80445608: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x8044560C: lw          $t9, 0x20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X20);
    // 0x80445610: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80445614: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80445618: jalr        $t9
    // 0x8044561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8044561C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80445620: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80445624: lw          $t7, -0x71A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X71A8);
    // 0x80445628: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14030) << 16);
    // 0x8044562C: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x80445630: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80445634: srl         $t0, $t8, 30
    ctx->r8 = S32(U32(ctx->r24) >> 30);
    // 0x80445638: bne         $t0, $zero, L_80445674
    if (ctx->r8 != 0) {
        // 0x8044563C: addiu       $a1, $zero, 0x46
        ctx->r5 = ADD32(0, 0X46);
            goto L_80445674;
    }
    // 0x8044563C: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80445640: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14028) << 16);
    // 0x80445644: lwc1        $f0, -0x7BF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14028));
    // 0x80445648: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X1402C) << 16);
    // 0x8044564C: lwc1        $f4, -0x7BF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X1402C));
    // 0x80445650: addiu       $a0, $zero, 0x4024
    ctx->r4 = ADD32(0, 0X4024);
    // 0x80445654: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80445658: lui         $a2, 0xC2FC
    ctx->r6 = S32(0XC2FC << 16);
    // 0x8044565C: lui         $a3, 0xC27C
    ctx->r7 = S32(0XC27C << 16);
    // 0x80445660: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80445664: jal         0x8005D078
    // 0x80445668: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_8005D078(rdram, ctx);
        goto after_4;
    // 0x80445668: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8044566C: b           L_80445690
    // 0x80445670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80445690;
    // 0x80445670: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80445674:
    // 0x80445674: lwc1        $f0, -0x7BF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14030));
    // 0x80445678: lui         $a2, 0xC2F2
    ctx->r6 = S32(0XC2F2 << 16);
    // 0x8044567C: lui         $a3, 0xC27C
    ctx->r7 = S32(0XC27C << 16);
    // 0x80445680: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80445684: jal         0x8005D078
    // 0x80445688: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_8005D078(rdram, ctx);
        goto after_5;
    // 0x80445688: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8044568C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80445690:
    // 0x80445690: beq         $v0, $zero, L_80445714
    if (ctx->r2 == 0) {
        // 0x80445694: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80445714;
    }
    // 0x80445694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80445698: jal         0x80047F9C
    // 0x8044569C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_80047F9C(rdram, ctx);
        goto after_6;
    // 0x8044569C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_6:
    // 0x804456A0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x804456A4: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804456A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x804456AC: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804456B0: sb          $t1, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r9;
    // 0x804456B4: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x804456B8: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X14034) << 16);
    // 0x804456BC: lw          $t5, 0x16C($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X16C);
    // 0x804456C0: lwc1        $f0, 0x0($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X0);
    // 0x804456C4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x804456C8: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x804456CC: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x804456D0: lw          $t3, 0x478($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X478);
    // 0x804456D4: lwc1        $f0, 0x4($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X4);
    // 0x804456D8: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x804456DC: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x804456E0: lw          $t4, 0x478($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X478);
    // 0x804456E4: lwc1        $f8, -0x7BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X14034));
    // 0x804456E8: lwc1        $f6, 0x8($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X8);
    // 0x804456EC: sb          $zero, 0x165($a1)
    MEM_B(0X165, ctx->r5) = 0;
    // 0x804456F0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x804456F4: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x804456F8: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x804456FC: sb          $v0, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r2;
    // 0x80445700: lw          $t6, 0x16C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X16C);
    // 0x80445704: sb          $v0, 0xE($t6)
    MEM_B(0XE, ctx->r14) = ctx->r2;
    // 0x80445708: lw          $t9, 0x16C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X16C);
    // 0x8044570C: b           L_8044571C
    // 0x80445710: sb          $zero, 0xF($t9)
    MEM_B(0XF, ctx->r25) = 0;
        goto L_8044571C;
    // 0x80445710: sb          $zero, 0xF($t9)
    MEM_B(0XF, ctx->r25) = 0;
L_80445714:
    // 0x80445714: jal         0x800445A4
    // 0x80445718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_7;
    // 0x80445718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_8044571C:
    // 0x8044571C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80445720: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80445724: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80445728: jr          $ra
    // 0x8044572C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8044572C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_804712B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804712B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804712BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804712C0: jal         0x80471168
    // 0x804712C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80471168(rdram, ctx);
        goto after_0;
    // 0x804712C4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x804712C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x804712CC: lw          $t6, 0x1E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1E0);
    // 0x804712D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x804712D4: bne         $t7, $zero, L_804712E4
    if (ctx->r15 != 0) {
        // 0x804712D8: sw          $t7, 0x1E0($a0)
        MEM_W(0X1E0, ctx->r4) = ctx->r15;
            goto L_804712E4;
    }
    // 0x804712D8: sw          $t7, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r15;
    // 0x804712DC: jal         0x8047139C
    // 0x804712E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_8047139C(rdram, ctx);
        goto after_1;
    // 0x804712E0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
L_804712E4:
    // 0x804712E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804712E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804712EC: jr          $ra
    // 0x804712F0: nop

    return;
    // 0x804712F0: nop

;}
RECOMP_FUNC void func_806DF000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806DF000: lui         $v0, 0x806E
    ctx->r2 = S32(RELOC_HI16(640, 0X114) << 16);
    // 0x806DF004: addiu       $v0, $v0, -0xEEC
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(640, 0X114));
    // 0x806DF008: jr          $ra
    // 0x806DF00C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x806DF00C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_8052C9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8052C9F4: jr          $ra
    // 0x8052C9F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8052C9F8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void func_80425240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80425240: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80425244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80425248: jal         0x804251D4
    // 0x8042524C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_804251D4(rdram, ctx);
        goto after_0;
    // 0x8042524C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80425250: bne         $v0, $zero, L_80425268
    if (ctx->r2 != 0) {
        // 0x80425254: lui         $a1, 0x8042
        ctx->r5 = S32(RELOC_HI16(35, 0X34F0) << 16);
            goto L_80425268;
    }
    // 0x80425254: lui         $a1, 0x8042
    ctx->r5 = S32(RELOC_HI16(35, 0X34F0) << 16);
    // 0x80425258: jal         0x800445A4
    // 0x8042525C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8042525C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80425260: b           L_80425318
    // 0x80425264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80425318;
    // 0x80425264: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80425268:
    // 0x80425268: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8042526C: lui         $t7, 0x8042
    ctx->r15 = S32(RELOC_HI16(35, 0X3534) << 16);
    // 0x80425270: addiu       $v0, $a1, 0x5EF0
    ctx->r2 = ADD32(ctx->r5, (int16_t)RELOC_LO16(35, 0X34F0));
    // 0x80425274: lw          $t0, 0x1F4($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X1F4);
    // 0x80425278: addiu       $t7, $t7, 0x5F34
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(35, 0X3534));
    // 0x8042527C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80425280: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x80425284: sw          $t7, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->r15;
    // 0x80425288: sw          $v0, 0xF4($t0)
    MEM_W(0XF4, ctx->r8) = ctx->r2;
    // 0x8042528C: srl         $a2, $a2, 1
    ctx->r6 = S32(U32(ctx->r6) >> 1);
    // 0x80425290: beq         $a2, $zero, L_804252F4
    if (ctx->r6 == 0) {
        // 0x80425294: addiu       $v1, $t0, 0xA0
        ctx->r3 = ADD32(ctx->r8, 0XA0);
            goto L_804252F4;
    }
    // 0x80425294: addiu       $v1, $t0, 0xA0
    ctx->r3 = ADD32(ctx->r8, 0XA0);
    // 0x80425298: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8042529C: beq         $a3, $zero, L_804252C4
    if (ctx->r7 == 0) {
        // 0x804252A0: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_804252C4;
    }
    // 0x804252A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_804252A4:
    // 0x804252A4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804252A8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x804252AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x804252B0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x804252B4: bne         $a1, $a0, L_804252A4
    if (ctx->r5 != ctx->r4) {
        // 0x804252B8: swc1        $f4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
            goto L_804252A4;
    }
    // 0x804252B8: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x804252BC: beql        $a0, $a2, L_804252F8
    if (ctx->r4 == ctx->r6) {
        // 0x804252C0: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_804252F8;
    }
    goto skip_0;
    // 0x804252C0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_0:
L_804252C4:
    // 0x804252C4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804252C8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x804252CC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x804252D0: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x804252D4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804252D8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x804252DC: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x804252E0: lwc1        $f10, -0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X8);
    // 0x804252E4: swc1        $f10, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f10.u32l;
    // 0x804252E8: lwc1        $f16, -0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X4);
    // 0x804252EC: bne         $a0, $a2, L_804252C4
    if (ctx->r4 != ctx->r6) {
        // 0x804252F0: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_804252C4;
    }
    // 0x804252F0: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_804252F4:
    // 0x804252F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_804252F8:
    // 0x804252F8: sw          $zero, 0xF0($t0)
    MEM_W(0XF0, ctx->r8) = 0;
    // 0x804252FC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80425300: swc1        $f18, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f18.u32l;
    // 0x80425304: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80425308: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8042530C: jal         0x80425408
    // 0x80425310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_2;
    // 0x80425310: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80425314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80425318:
    // 0x80425318: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042531C: jr          $ra
    // 0x80425320: nop

    return;
    // 0x80425320: nop

;}
RECOMP_FUNC void func_804629F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804629F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804629FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80462A00: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80462A04: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80462A08: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80462A0C: beql        $v1, $zero, L_80462A4C
    if (ctx->r3 == 0) {
        // 0x80462A10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462A4C;
    }
    goto skip_0;
    // 0x80462A10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80462A14: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80462A18: jal         0x80062684
    // 0x80462A1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80062684(rdram, ctx);
        goto after_0;
    // 0x80462A1C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80462A20: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80462A24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80462A28: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80462A2C: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x80462A30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80462A34: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80462A38: bnel        $t6, $at, L_80462A4C
    if (ctx->r14 != ctx->r1) {
        // 0x80462A3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80462A4C;
    }
    goto skip_1;
    // 0x80462A3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80462A40: jal         0x80463260
    // 0x80462A44: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_80463260(rdram, ctx);
        goto after_1;
    // 0x80462A44: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_1:
    // 0x80462A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80462A4C:
    // 0x80462A4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80462A50: jr          $ra
    // 0x80462A54: nop

    return;
    // 0x80462A54: nop

;}
RECOMP_FUNC void func_805A4AF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A4AF8: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x805A4AFC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x805A4B00: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x805A4B04: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x805A4B08: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x805A4B0C: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x805A4B10: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x805A4B14: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x805A4B18: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x805A4B1C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x805A4B20: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x805A4B24: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x805A4B28: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x805A4B2C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x805A4B30: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x805A4B34: sw          $a1, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r5;
    // 0x805A4B38: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805A4B3C: lw          $s3, 0x4($a1)
    ctx->r19 = MEM_W(ctx->r5, 0X4);
    // 0x805A4B40: lw          $t1, 0x16C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X16C);
    // 0x805A4B44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4B48: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x805A4B4C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x805A4B50: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805A4B54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A4B58: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805A4B5C: lui         $t9, 0x1F
    ctx->r25 = S32(0X1F << 16);
    // 0x805A4B60: ori         $t9, $t9, 0x3205
    ctx->r25 = ctx->r25 | 0X3205;
    // 0x805A4B64: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4B68: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x805A4B6C: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x805A4B70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4B74: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805A4B78: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x805A4B7C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x805A4B80: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x805A4B84: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4B88: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x805A4B8C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A4B90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805A4B94: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4B98: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x805A4B9C: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x805A4BA0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4BA4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4BA8: ori         $t9, $t9, 0x2C80
    ctx->r25 = ctx->r25 | 0X2C80;
    // 0x805A4BAC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805A4BB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4BB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4BB8: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x805A4BBC: lui         $a2, 0x50
    ctx->r6 = S32(0X50 << 16);
    // 0x805A4BC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4BC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x805A4BC8: ori         $a2, $a2, 0x4240
    ctx->r6 = ctx->r6 | 0X4240;
    // 0x805A4BCC: ori         $t7, $t7, 0x3
    ctx->r15 = ctx->r15 | 0X3;
    // 0x805A4BD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A4BD4: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x805A4BD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4BDC: lui         $t9, 0xB900
    ctx->r25 = S32(0XB900 << 16);
    // 0x805A4BE0: ori         $t9, $t9, 0x31D
    ctx->r25 = ctx->r25 | 0X31D;
    // 0x805A4BE4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A4BE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x805A4BEC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x805A4BF0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A4BF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4BF8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x805A4BFC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x805A4C00: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4C04: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x805A4C08: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A4C0C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x805A4C10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4C14: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x805A4C18: addiu       $a1, $s1, 0x34
    ctx->r5 = ADD32(ctx->r17, 0X34);
    // 0x805A4C1C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4C20: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4C24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4C28: lbu         $t8, 0xD($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0XD);
    // 0x805A4C2C: lbu         $t6, 0x10($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X10);
    // 0x805A4C30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x805A4C34: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x805A4C38: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x805A4C3C: lbu         $t6, 0xE($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XE);
    // 0x805A4C40: lui         $at, 0x436F
    ctx->r1 = S32(0X436F << 16);
    // 0x805A4C44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805A4C48: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x805A4C4C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x805A4C50: lbu         $t7, 0xF($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0XF);
    // 0x805A4C54: lui         $s7, 0xF00
    ctx->r23 = S32(0XF00 << 16);
    // 0x805A4C58: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x805A4C5C: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x805A4C60: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x805A4C64: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A4C68: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4C6C: lui         $t8, 0xFC12
    ctx->r24 = S32(0XFC12 << 16);
    // 0x805A4C70: ori         $t8, $t8, 0x7E24
    ctx->r24 = ctx->r24 | 0X7E24;
    // 0x805A4C74: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4C78: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4C7C: addiu       $t9, $zero, -0x604
    ctx->r25 = ADD32(0, -0X604);
    // 0x805A4C80: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x805A4C84: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4C88: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4C8C: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x805A4C90: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x805A4C94: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4C98: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x805A4C9C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x805A4CA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A4CA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4CA8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x805A4CAC: lui         $t6, 0xBB00
    ctx->r14 = S32(0XBB00 << 16);
    // 0x805A4CB0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805A4CB4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x805A4CB8: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x805A4CBC: ori         $t7, $t7, 0x8000
    ctx->r15 = ctx->r15 | 0X8000;
    // 0x805A4CC0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805A4CC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805A4CC8: lw          $a0, 0x4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4);
    // 0x805A4CCC: lh          $t8, 0x2($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X2);
    // 0x805A4CD0: addiu       $fp, $fp, -0x260C
    ctx->r30 = ADD32(ctx->r30, -0X260C);
    // 0x805A4CD4: addiu       $s7, $s7, 0x0
    ctx->r23 = ADD32(ctx->r23, 0X0);
    // 0x805A4CD8: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x805A4CDC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x805A4CE0: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x805A4CE4: lui         $s5, 0xF200
    ctx->r21 = S32(0XF200 << 16);
    // 0x805A4CE8: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x805A4CEC: lui         $s6, 0xBF00
    ctx->r22 = S32(0XBF00 << 16);
    // 0x805A4CF0: addiu       $t1, $t1, 0xD
    ctx->r9 = ADD32(ctx->r9, 0XD);
    // 0x805A4CF4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x805A4CF8: nop

    // 0x805A4CFC: bc1fl       L_805A4D0C
    if (!c1cs) {
        // 0x805A4D00: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_805A4D0C;
    }
    goto skip_0;
    // 0x805A4D00: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_0:
    // 0x805A4D04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x805A4D08: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_805A4D0C:
    // 0x805A4D0C: nop

    // 0x805A4D10: bc1fl       L_805A4D20
    if (!c1cs) {
        // 0x805A4D14: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_805A4D20;
    }
    goto skip_1;
    // 0x805A4D14: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x805A4D18: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x805A4D1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_805A4D20:
    // 0x805A4D20: sll         $t7, $v0, 6
    ctx->r15 = S32(ctx->r2 << 6);
    // 0x805A4D24: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x805A4D28: lh          $t9, -0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, -0XE);
    // 0x805A4D2C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x805A4D30: addu        $t6, $a0, $t9
    ctx->r14 = ADD32(ctx->r4, ctx->r25);
    // 0x805A4D34: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x805A4D38: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x805A4D3C: cvt.s.w     $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    ctx->f26.fl = CVT_S_W(ctx->f6.u32l);
    // 0x805A4D40: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x805A4D44: nop

    // 0x805A4D48: bc1fl       L_805A4D58
    if (!c1cs) {
        // 0x805A4D4C: c.lt.s      $f2, $f26
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
            goto L_805A4D58;
    }
    goto skip_2;
    // 0x805A4D4C: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    skip_2:
    // 0x805A4D50: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x805A4D54: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
L_805A4D58:
    // 0x805A4D58: nop

    // 0x805A4D5C: bc1fl       L_805A4D6C
    if (!c1cs) {
        // 0x805A4D60: sub.s       $f8, $f26, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f20.fl;
            goto L_805A4D6C;
    }
    goto skip_3;
    // 0x805A4D60: sub.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f20.fl;
    skip_3:
    // 0x805A4D64: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    // 0x805A4D68: sub.s       $f8, $f26, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f26.fl - ctx->f20.fl;
L_805A4D6C:
    // 0x805A4D6C: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x805A4D70: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x805A4D74: blez        $v0, L_805A5070
    if (SIGNED(ctx->r2) <= 0) {
        // 0x805A4D78: div.s       $f26, $f8, $f16
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
            goto L_805A5070;
    }
    // 0x805A4D78: div.s       $f26, $f8, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x805A4D7C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x805A4D80: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x805A4D84: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
L_805A4D88:
    // 0x805A4D88: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x805A4D8C: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x805A4D90: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x805A4D94: addiu       $s1, $s1, -0x40
    ctx->r17 = ADD32(ctx->r17, -0X40);
    // 0x805A4D98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x805A4D9C: jal         0x80065528
    // 0x805A4DA0: sw          $s1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r17;
    func_80065528(rdram, ctx);
        goto after_0;
    // 0x805A4DA0: sw          $s1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r17;
    after_0:
    // 0x805A4DA4: add.s       $f0, $f20, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x805A4DA8: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x805A4DAC: ori         $t6, $t6, 0x103F
    ctx->r14 = ctx->r14 | 0X103F;
    // 0x805A4DB0: sub.s       $f18, $f20, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x805A4DB4: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x805A4DB8: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x805A4DBC: nop

    // 0x805A4DC0: mul.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x805A4DC4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x805A4DC8: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x805A4DCC: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x805A4DD0: trunc.w.s   $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    ctx->f18.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x805A4DD4: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x805A4DD8: sh          $v1, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r3;
    // 0x805A4DDC: sh          $v1, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r3;
    // 0x805A4DE0: sh          $a0, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r4;
    // 0x805A4DE4: sh          $a0, 0x2A($s1)
    MEM_H(0X2A, ctx->r17) = ctx->r4;
    // 0x805A4DE8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4DEC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x805A4DF0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x805A4DF4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805A4DF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x805A4DFC: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x805A4E00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x805A4E04: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x805A4E08: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x805A4E0C: lh          $t6, 0x30($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X30);
    // 0x805A4E10: lw          $a2, 0x0($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X0);
    // 0x805A4E14: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x805A4E18: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x805A4E1C: addu        $ra, $a2, $t8
    ctx->r31 = ADD32(ctx->r6, ctx->r24);
    // 0x805A4E20: addu        $s2, $a2, $t6
    ctx->r18 = ADD32(ctx->r6, ctx->r14);
    // 0x805A4E24: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x805A4E28: beq         $at, $zero, L_805A4E38
    if (ctx->r1 == 0) {
        // 0x805A4E2C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_805A4E38;
    }
    // 0x805A4E2C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x805A4E30: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x805A4E34: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_805A4E38:
    // 0x805A4E38: slti        $at, $ra, 0x140
    ctx->r1 = SIGNED(ctx->r31) < 0X140 ? 1 : 0;
    // 0x805A4E3C: bne         $at, $zero, L_805A4E48
    if (ctx->r1 != 0) {
        // 0x805A4E40: lui         $t9, 0xFD10
        ctx->r25 = S32(0XFD10 << 16);
            goto L_805A4E48;
    }
    // 0x805A4E40: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x805A4E44: addiu       $ra, $zero, 0x13F
    ctx->r31 = ADD32(0, 0X13F);
L_805A4E48:
    // 0x805A4E48: slti        $at, $s2, 0x140
    ctx->r1 = SIGNED(ctx->r18) < 0X140 ? 1 : 0;
    // 0x805A4E4C: bne         $at, $zero, L_805A4E58
    if (ctx->r1 != 0) {
        // 0x805A4E50: ori         $t9, $t9, 0x13F
        ctx->r25 = ctx->r25 | 0X13F;
            goto L_805A4E58;
    }
    // 0x805A4E50: ori         $t9, $t9, 0x13F
    ctx->r25 = ctx->r25 | 0X13F;
    // 0x805A4E54: addiu       $s2, $zero, 0x13F
    ctx->r18 = ADD32(0, 0X13F);
L_805A4E58:
    // 0x805A4E58: bgez        $ra, L_805A4E64
    if (SIGNED(ctx->r31) >= 0) {
        // 0x805A4E5C: slti        $at, $t0, 0xF0
        ctx->r1 = SIGNED(ctx->r8) < 0XF0 ? 1 : 0;
            goto L_805A4E64;
    }
    // 0x805A4E5C: slti        $at, $t0, 0xF0
    ctx->r1 = SIGNED(ctx->r8) < 0XF0 ? 1 : 0;
    // 0x805A4E60: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
L_805A4E64:
    // 0x805A4E64: bgez        $s2, L_805A4E70
    if (SIGNED(ctx->r18) >= 0) {
        // 0x805A4E68: lui         $t7, 0x708
        ctx->r15 = S32(0X708 << 16);
            goto L_805A4E70;
    }
    // 0x805A4E68: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x805A4E6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_805A4E70:
    // 0x805A4E70: beq         $at, $zero, L_805A4E84
    if (ctx->r1 == 0) {
        // 0x805A4E74: subu        $a3, $s2, $ra
        ctx->r7 = SUB32(ctx->r18, ctx->r31);
            goto L_805A4E84;
    }
    // 0x805A4E74: subu        $a3, $s2, $ra
    ctx->r7 = SUB32(ctx->r18, ctx->r31);
    // 0x805A4E78: slti        $at, $a2, 0xF0
    ctx->r1 = SIGNED(ctx->r6) < 0XF0 ? 1 : 0;
    // 0x805A4E7C: bne         $at, $zero, L_805A4E90
    if (ctx->r1 != 0) {
        // 0x805A4E80: nop
    
            goto L_805A4E90;
    }
    // 0x805A4E80: nop

L_805A4E84:
    // 0x805A4E84: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x805A4E88: addiu       $t0, $t0, 0xEF
    ctx->r8 = ADD32(ctx->r8, 0XEF);
    // 0x805A4E8C: addiu       $a2, $zero, 0xEF
    ctx->r6 = ADD32(0, 0XEF);
L_805A4E90:
    // 0x805A4E90: bltz        $t0, L_805A4EA0
    if (SIGNED(ctx->r8) < 0) {
        // 0x805A4E94: sll         $a3, $a3, 1
        ctx->r7 = S32(ctx->r7 << 1);
            goto L_805A4EA0;
    }
    // 0x805A4E94: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x805A4E98: bgezl       $a2, L_805A4EB0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x805A4E9C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_805A4EB0;
    }
    goto skip_4;
    // 0x805A4E9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
L_805A4EA0:
    // 0x805A4EA0: subu        $a2, $t0, $a2
    ctx->r6 = SUB32(ctx->r8, ctx->r6);
    // 0x805A4EA4: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x805A4EA8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x805A4EAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_805A4EB0:
    // 0x805A4EB0: addiu       $a3, $a3, 0x9
    ctx->r7 = ADD32(ctx->r7, 0X9);
    // 0x805A4EB4: sra         $a3, $a3, 3
    ctx->r7 = S32(SIGNED(ctx->r7) >> 3);
    // 0x805A4EB8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A4EBC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x805A4EC0: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x805A4EC4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A4EC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4ECC: andi        $a3, $a3, 0x1FF
    ctx->r7 = ctx->r7 & 0X1FF;
    // 0x805A4ED0: sll         $a3, $a3, 9
    ctx->r7 = S32(ctx->r7 << 9);
    // 0x805A4ED4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4ED8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x805A4EDC: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x805A4EE0: or          $a3, $a3, $at
    ctx->r7 = ctx->r7 | ctx->r1;
    // 0x805A4EE4: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x805A4EE8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805A4EEC: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x805A4EF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4EF4: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x805A4EF8: sll         $a1, $ra, 2
    ctx->r5 = S32(ctx->r31 << 2);
    // 0x805A4EFC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A4F00: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x805A4F04: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A4F08: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A4F0C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4F10: andi        $a1, $a1, 0xFFF
    ctx->r5 = ctx->r5 & 0XFFF;
    // 0x805A4F14: sll         $a1, $a1, 12
    ctx->r5 = S32(ctx->r5 << 12);
    // 0x805A4F18: lui         $at, 0xF400
    ctx->r1 = S32(0XF400 << 16);
    // 0x805A4F1C: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x805A4F20: andi        $t3, $t3, 0xFFF
    ctx->r11 = ctx->r11 & 0XFFF;
    // 0x805A4F24: or          $t7, $a1, $at
    ctx->r15 = ctx->r5 | ctx->r1;
    // 0x805A4F28: addiu       $t4, $a2, 0x1
    ctx->r12 = ADD32(ctx->r6, 0X1);
    // 0x805A4F2C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x805A4F30: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x805A4F34: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x805A4F38: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x805A4F3C: sll         $t3, $t3, 12
    ctx->r11 = S32(ctx->r11 << 12);
    // 0x805A4F40: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x805A4F44: andi        $t2, $t2, 0xFFF
    ctx->r10 = ctx->r10 & 0XFFF;
    // 0x805A4F48: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x805A4F4C: andi        $t4, $t4, 0xFFF
    ctx->r12 = ctx->r12 & 0XFFF;
    // 0x805A4F50: or          $t6, $t9, $t4
    ctx->r14 = ctx->r25 | ctx->r12;
    // 0x805A4F54: or          $t8, $t7, $t2
    ctx->r24 = ctx->r15 | ctx->r10;
    // 0x805A4F58: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4F5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A4F60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4F64: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x805A4F68: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x805A4F6C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4F70: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4F74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x805A4F78: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x805A4F7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4F80: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x805A4F84: or          $t8, $a1, $s5
    ctx->r24 = ctx->r5 | ctx->r21;
    // 0x805A4F88: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805A4F8C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x805A4F90: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A4F94: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x805A4F98: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4F9C: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x805A4FA0: or          $t9, $t8, $t2
    ctx->r25 = ctx->r24 | ctx->r10;
    // 0x805A4FA4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4FA8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4FAC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A4FB0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x805A4FB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A4FB8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x805A4FBC: addiu       $s3, $s3, 0x40
    ctx->r19 = ADD32(ctx->r19, 0X40);
    // 0x805A4FC0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x805A4FC4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x805A4FC8: lh          $t8, 0xA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XA);
    // 0x805A4FCC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x805A4FD0: sra         $t9, $t8, 6
    ctx->r25 = S32(SIGNED(ctx->r24) >> 6);
    // 0x805A4FD4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x805A4FD8: lh          $t9, 0x8($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X8);
    // 0x805A4FDC: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x805A4FE0: or          $t8, $t7, $s5
    ctx->r24 = ctx->r15 | ctx->r21;
    // 0x805A4FE4: sra         $t6, $t9, 6
    ctx->r14 = S32(SIGNED(ctx->r25) >> 6);
    // 0x805A4FE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x805A4FEC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x805A4FF0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x805A4FF4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x805A4FF8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x805A4FFC: lh          $t9, 0x3A($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X3A);
    // 0x805A5000: sra         $t8, $t9, 6
    ctx->r24 = S32(SIGNED(ctx->r25) >> 6);
    // 0x805A5004: lh          $t9, 0x38($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X38);
    // 0x805A5008: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x805A500C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x805A5010: sra         $t8, $t9, 6
    ctx->r24 = S32(SIGNED(ctx->r25) >> 6);
    // 0x805A5014: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x805A5018: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x805A501C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x805A5020: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x805A5024: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A5028: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A502C: addiu       $t7, $zero, 0x204
    ctx->r15 = ADD32(0, 0X204);
    // 0x805A5030: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x805A5034: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x805A5038: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x805A503C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x805A5040: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x805A5044: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x805A5048: ori         $t6, $t6, 0x604
    ctx->r14 = ctx->r14 | 0X604;
    // 0x805A504C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x805A5050: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x805A5054: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x805A5058: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x805A505C: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x805A5060: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x805A5064: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x805A5068: bnel        $at, $zero, L_805A4D88
    if (ctx->r1 != 0) {
        // 0x805A506C: lw          $v0, 0x0($fp)
        ctx->r2 = MEM_W(ctx->r30, 0X0);
            goto L_805A4D88;
    }
    goto skip_5;
    // 0x805A506C: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    skip_5:
L_805A5070:
    // 0x805A5070: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x805A5074: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x805A5078: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x805A507C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x805A5080: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x805A5084: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x805A5088: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x805A508C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x805A5090: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x805A5094: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x805A5098: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x805A509C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x805A50A0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x805A50A4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x805A50A8: jr          $ra
    // 0x805A50AC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x805A50AC: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void func_807807F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807807F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807807F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807807F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807807FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80780800: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80780804: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80780808: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8078080C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80780810: nop

    // 0x80780814: bc1fl       L_80780824
    if (!c1cs) {
        // 0x80780818: lh          $t6, 0x1F0($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X1F0);
            goto L_80780824;
    }
    goto skip_0;
    // 0x80780818: lh          $t6, 0x1F0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1F0);
    skip_0:
    // 0x8078081C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80780820: lh          $t6, 0x1F0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1F0);
L_80780824:
    // 0x80780824: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80780828: bne         $t6, $at, L_80780864
    if (ctx->r14 != ctx->r1) {
        // 0x8078082C: lui         $at, 0x42FE
        ctx->r1 = S32(0X42FE << 16);
            goto L_80780864;
    }
    // 0x8078082C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80780830: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80780834: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80780838: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x8078083C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80780840: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80780844: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x80780848: jal         0x80067D5C
    // 0x8078084C: nop

    func_80067D5C(rdram, ctx);
        goto after_0;
    // 0x8078084C: nop

    after_0:
    // 0x80780850: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x80780854: jal         0x80067F78
    // 0x80780858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_1;
    // 0x80780858: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8078085C: b           L_80780898
    // 0x80780860: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
        goto L_80780898;
    // 0x80780860: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
L_80780864:
    // 0x80780864: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80780868: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078086C: lw          $a1, 0x34($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X34);
    // 0x80780870: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80780874: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80780878: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8078087C: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80780880: jal         0x80067D5C
    // 0x80780884: nop

    func_80067D5C(rdram, ctx);
        goto after_2;
    // 0x80780884: nop

    after_2:
    // 0x80780888: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x8078088C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    // 0x80780890: jal         0x800678F0
    // 0x80780894: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    func_800678F0(rdram, ctx);
        goto after_3;
    // 0x80780894: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
L_80780898:
    // 0x80780898: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078089C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807808A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x807808A4: jr          $ra
    // 0x807808A8: nop

    return;
    // 0x807808A8: nop

;}
RECOMP_FUNC void func_80428904(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80428904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80428908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042890C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80428910: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80428914: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80428918: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(41, 0X1E04) << 16);
    // 0x8042891C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80428920: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x80428924: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80428928: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8042892C: lw          $t8, -0x68BC($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(41, 0X1E04));
    // 0x80428930: subu        $t9, $t9, $a1
    ctx->r25 = SUB32(ctx->r25, ctx->r5);
    // 0x80428934: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80428938: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8042893C: jal         0x80048490
    // 0x80428940: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x80428940: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80428944: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80428948: jal         0x80048378
    // 0x8042894C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    func_80048378(rdram, ctx);
        goto after_1;
    // 0x8042894C: addiu       $a0, $a2, 0xC4
    ctx->r4 = ADD32(ctx->r6, 0XC4);
    after_1:
    // 0x80428950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80428954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80428958: jr          $ra
    // 0x8042895C: nop

    return;
    // 0x8042895C: nop

;}
RECOMP_FUNC void func_80424FE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424FE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80424FE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80424FE8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80424FEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80424FF0: jal         0x80424F94
    // 0x80424FF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80424F94(rdram, ctx);
        goto after_0;
    // 0x80424FF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80424FF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80424FFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80425000: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80425004: lw          $v1, 0xF0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF0);
    // 0x80425008: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8042500C: beq         $v1, $zero, L_8042501C
    if (ctx->r3 == 0) {
        // 0x80425010: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_8042501C;
    }
    // 0x80425010: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80425014: b           L_80425024
    // 0x80425018: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
        goto L_80425024;
    // 0x80425018: sw          $t6, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r14;
L_8042501C:
    // 0x8042501C: jal         0x80425408
    // 0x80425020: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80425408(rdram, ctx);
        goto after_1;
    // 0x80425020: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
L_80425024:
    // 0x80425024: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80425028: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042502C: jr          $ra
    // 0x80425030: nop

    return;
    // 0x80425030: nop

;}
RECOMP_FUNC void func_80424690(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80424690: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80424694: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80424698: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8042469C: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x804246A0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x804246A4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x804246A8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x804246AC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x804246B0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x804246B4: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x804246B8: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x804246BC: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x804246C0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x804246C4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x804246C8: srl         $s4, $a2, 1
    ctx->r20 = S32(U32(ctx->r6) >> 1);
    // 0x804246CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804246D0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x804246D4: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x804246D8: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804246DC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x804246E0: beq         $s4, $zero, L_804247CC
    if (ctx->r20 == 0) {
        // 0x804246E4: mov.s       $f24, $f26
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
            goto L_804247CC;
    }
    // 0x804246E4: mov.s       $f24, $f26
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 26);
    ctx->f24.fl = ctx->f26.fl;
    // 0x804246E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x804246EC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x804246F0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x804246F4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x804246F8: nop

L_804246FC:
    // 0x804246FC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80424700: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80424704: mul.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f30.fl);
    // 0x80424708: add.s       $f28, $f8, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f28.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8042470C: jal         0x80066E88
    // 0x80424710: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x80424710: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_0:
    // 0x80424714: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80424718: jal         0x80066DE4
    // 0x8042471C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8042471C: mov.s       $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    ctx->f12.fl = ctx->f28.fl;
    after_1:
    // 0x80424720: mul.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x80424724: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80424728: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x8042472C: mul.s       $f14, $f22, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80424730: sub.s       $f10, $f26, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f2.fl;
    // 0x80424734: sub.s       $f18, $f24, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f14.fl;
    // 0x80424738: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8042473C: add.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f26.fl + ctx->f2.fl;
    // 0x80424740: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80424744: add.s       $f10, $f24, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f14.fl;
    // 0x80424748: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x8042474C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80424750: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80424754: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80424758: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8042475C: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80424760: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x80424764: trunc.w.s   $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    ctx->f18.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80424768: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8042476C: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x80424770: trunc.w.s   $f4, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    ctx->f4.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80424774: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80424778: sh          $t3, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r11;
    // 0x8042477C: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x80424780: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80424784: sh          $t5, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r13;
    // 0x80424788: sh          $t7, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r15;
    // 0x8042478C: jal         0x80066E88
    // 0x80424790: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_80066E88(rdram, ctx);
        goto after_2;
    // 0x80424790: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x80424794: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80424798: jal         0x80066DE4
    // 0x8042479C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    func_80066DE4(rdram, ctx);
        goto after_3;
    // 0x8042479C: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x804247A0: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x804247A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x804247A8: sltu        $at, $s3, $s4
    ctx->r1 = ctx->r19 < ctx->r20 ? 1 : 0;
    // 0x804247AC: mul.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
    // 0x804247B0: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x804247B4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x804247B8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x804247BC: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
    // 0x804247C0: add.s       $f26, $f6, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x804247C4: bne         $at, $zero, L_804246FC
    if (ctx->r1 != 0) {
        // 0x804247C8: sub.s       $f24, $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f8.fl;
            goto L_804246FC;
    }
    // 0x804247C8: sub.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f8.fl;
L_804247CC:
    // 0x804247CC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x804247D0: lui         $at, 0x8042
    ctx->r1 = S32(RELOC_HI16(35, 0X36D0) << 16);
    // 0x804247D4: swc1        $f26, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f26.u32l;
    // 0x804247D8: swc1        $f24, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f24.u32l;
    // 0x804247DC: lwc1        $f10, 0x60D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(35, 0X36D0));
    // 0x804247E0: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x804247E4: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x804247E8: swc1        $f2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f2.u32l;
    // 0x804247EC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x804247F0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x804247F4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x804247F8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x804247FC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80424800: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80424804: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80424808: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8042480C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80424810: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80424814: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80424818: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8042481C: jr          $ra
    // 0x80424820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80424820: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_80048490(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048490: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80048494: sw          $t6, 0x134($a0)
    MEM_W(0X134, ctx->r4) = ctx->r14;
    // 0x80048498: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8004849C: sw          $t7, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r15;
    // 0x800484A0: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800484A4: swc1        $f4, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f4.u32l;
    // 0x800484A8: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800484AC: swc1        $f6, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f6.u32l;
    // 0x800484B0: lwc1        $f8, 0x10($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800484B4: swc1        $f8, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f8.u32l;
    // 0x800484B8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800484BC: swc1        $f10, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f10.u32l;
    // 0x800484C0: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800484C4: swc1        $f16, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f16.u32l;
    // 0x800484C8: lwc1        $f18, 0x1C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800484CC: swc1        $f18, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f18.u32l;
    // 0x800484D0: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800484D4: swc1        $f4, 0xF4($a0)
    MEM_W(0XF4, ctx->r4) = ctx->f4.u32l;
    // 0x800484D8: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800484DC: swc1        $f6, 0xF8($a0)
    MEM_W(0XF8, ctx->r4) = ctx->f6.u32l;
    // 0x800484E0: lwc1        $f8, 0x28($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800484E4: jr          $ra
    // 0x800484E8: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x800484E8: swc1        $f8, 0xFC($a0)
    MEM_W(0XFC, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_80743034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80743034: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80743038: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8074303C: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x80743040: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80743044: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x80743048: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8074304C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80743050: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x80743054: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80743058: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8074305C: jr          $ra
    // 0x80743060: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x80743060: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_80556744(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80556744: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80556748: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8055674C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80556750: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80556754: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80556758: jal         0x80047090
    // 0x8055675C: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x8055675C: lhu         $a0, 0x32($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X32);
    after_0:
    // 0x80556760: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80556764: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80556768: beq         $v0, $at, L_805567D0
    if (ctx->r2 == ctx->r1) {
        // 0x8055676C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_805567D0;
    }
    // 0x8055676C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80556770: lhu         $t6, 0x32($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X32);
    // 0x80556774: lwc1        $f4, 0x8($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80556778: lui         $a0, 0x8055
    ctx->r4 = S32(RELOC_HI16(357, 0X1B30) << 16);
    // 0x8055677C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80556780: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80556784: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x80556788: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x8055678C: or          $a1, $t8, $v1
    ctx->r5 = ctx->r24 | ctx->r3;
    // 0x80556790: addiu       $a0, $a0, 0x6A20
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(357, 0X1B30));
    // 0x80556794: jal         0x80046804
    // 0x80556798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x80556798: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8055679C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x805567A0: beq         $v0, $zero, L_805567D0
    if (ctx->r2 == 0) {
        // 0x805567A4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_805567D0;
    }
    // 0x805567A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x805567A8: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x805567AC: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x805567B0: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x805567B4: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x805567B8: lwc1        $f10, 0x8($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X8);
    // 0x805567BC: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x805567C0: jal         0x80044194
    // 0x805567C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x805567C4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x805567C8: b           L_805567D4
    // 0x805567CC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
        goto L_805567D4;
    // 0x805567CC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_805567D0:
    // 0x805567D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_805567D4:
    // 0x805567D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805567D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805567DC: jr          $ra
    // 0x805567E0: nop

    return;
    // 0x805567E0: nop

    // 0x805567E4: nop

    // 0x805567E8: nop

    // 0x805567EC: nop

;}
