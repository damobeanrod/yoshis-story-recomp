#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800202B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800202B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800202B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800202BC: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800202C0: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x800202C4: bnel        $t6, $zero, L_80020320
    if (ctx->r14 != 0) {
        // 0x800202C8: lw          $t3, 0x2C($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X2C);
            goto L_80020320;
    }
    goto skip_0;
    // 0x800202C8: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
    skip_0:
    // 0x800202CC: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x800202D0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800202D4: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800202D8: andi        $v0, $v0, 0x700
    ctx->r2 = ctx->r2 & 0X700;
    // 0x800202DC: srl         $v0, $v0, 8
    ctx->r2 = S32(U32(ctx->r2) >> 8);
    // 0x800202E0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800202E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800202E8: lw          $t8, -0x6568($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6568);
    // 0x800202EC: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x800202F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800202F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800202F8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800202FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80020300: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80020304: lhu         $a2, 0x0($t2)
    ctx->r6 = MEM_HU(ctx->r10, 0X0);
    // 0x80020308: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002030C: jal         0x8004A9C4
    // 0x80020310: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_8004A9C4(rdram, ctx);
        goto after_0;
    // 0x80020310: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80020314: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80020318: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8002031C: lw          $t3, 0x2C($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X2C);
L_80020320:
    // 0x80020320: andi        $t4, $t3, 0x700
    ctx->r12 = ctx->r11 & 0X700;
    // 0x80020324: bne         $t4, $zero, L_8002033C
    if (ctx->r12 != 0) {
        // 0x80020328: nop
    
            goto L_8002033C;
    }
    // 0x80020328: nop

    // 0x8002032C: lw          $t5, 0x38($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X38);
    // 0x80020330: andi        $t6, $t5, 0x700
    ctx->r14 = ctx->r13 & 0X700;
    // 0x80020334: beql        $t6, $zero, L_80020348
    if (ctx->r14 == 0) {
        // 0x80020338: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80020348;
    }
    goto skip_1;
    // 0x80020338: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
L_8002033C:
    // 0x8002033C: b           L_800203C0
    // 0x80020340: sw          $zero, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = 0;
        goto L_800203C0;
    // 0x80020340: sw          $zero, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = 0;
    // 0x80020344: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80020348:
    // 0x80020348: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8002034C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80020350: nop

    // 0x80020354: bc1fl       L_80020370
    if (!c1cs) {
        // 0x80020358: sw          $zero, 0xFC($v1)
        MEM_W(0XFC, ctx->r3) = 0;
            goto L_80020370;
    }
    goto skip_2;
    // 0x80020358: sw          $zero, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = 0;
    skip_2:
    // 0x8002035C: lw          $t7, 0xFC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XFC);
    // 0x80020360: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80020364: b           L_80020370
    // 0x80020368: sw          $t8, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = ctx->r24;
        goto L_80020370;
    // 0x80020368: sw          $t8, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = ctx->r24;
    // 0x8002036C: sw          $zero, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = 0;
L_80020370:
    // 0x80020370: lw          $t0, 0x2C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2C);
    // 0x80020374: andi        $t9, $t0, 0x3000
    ctx->r25 = ctx->r8 & 0X3000;
    // 0x80020378: bnel        $t9, $zero, L_80020394
    if (ctx->r25 != 0) {
        // 0x8002037C: lwc1        $f8, 0xC8($a0)
        ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
            goto L_80020394;
    }
    goto skip_3;
    // 0x8002037C: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    skip_3:
    // 0x80020380: lw          $t1, 0x38($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X38);
    // 0x80020384: andi        $t2, $t1, 0x3000
    ctx->r10 = ctx->r9 & 0X3000;
    // 0x80020388: beq         $t2, $zero, L_800203C0
    if (ctx->r10 == 0) {
        // 0x8002038C: nop
    
            goto L_800203C0;
    }
    // 0x8002038C: nop

    // 0x80020390: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
L_80020394:
    // 0x80020394: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x80020398: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8002039C: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x800203A0: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800203A4: beq         $t4, $zero, L_800203C0
    if (ctx->r12 == 0) {
        // 0x800203A8: nop
    
            goto L_800203C0;
    }
    // 0x800203A8: nop

    // 0x800203AC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800203B0: jal         0x80061170
    // 0x800203B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80061170(rdram, ctx);
        goto after_1;
    // 0x800203B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x800203B8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800203BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
L_800203C0:
    // 0x800203C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800203C4: lwc1        $f16, -0x414($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X414);
    // 0x800203C8: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x800203CC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800203D0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800203D4: nop

    // 0x800203D8: bc1tl       L_800203F8
    if (c1cs) {
        // 0x800203DC: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800203F8;
    }
    goto skip_4;
    // 0x800203DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_4:
    // 0x800203E0: lwc1        $f18, -0x410($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X410);
    // 0x800203E4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800203E8: nop

    // 0x800203EC: bc1fl       L_800204F8
    if (!c1cs) {
        // 0x800203F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800204F8;
    }
    goto skip_5;
    // 0x800203F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800203F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800203F8:
    // 0x800203F8: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x800203FC: lui         $a1, 0xF0
    ctx->r5 = S32(0XF0 << 16);
    // 0x80020400: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80020404: and         $t8, $v0, $a1
    ctx->r24 = ctx->r2 & ctx->r5;
    // 0x80020408: bc1f        L_80020488
    if (!c1cs) {
        // 0x8002040C: nop
    
            goto L_80020488;
    }
    // 0x8002040C: nop

    // 0x80020410: lui         $a1, 0xF
    ctx->r5 = S32(0XF << 16);
    // 0x80020414: and         $t5, $v0, $a1
    ctx->r13 = ctx->r2 & ctx->r5;
    // 0x80020418: bnel        $t5, $zero, L_8002044C
    if (ctx->r13 != 0) {
        // 0x8002041C: lui         $at, 0xC0E0
        ctx->r1 = S32(0XC0E0 << 16);
            goto L_8002044C;
    }
    goto skip_6;
    // 0x8002041C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    skip_6:
    // 0x80020420: lw          $t6, 0x38($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X38);
    // 0x80020424: addiu       $a2, $zero, 0x140
    ctx->r6 = ADD32(0, 0X140);
    // 0x80020428: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8002042C: bne         $t7, $zero, L_80020448
    if (ctx->r15 != 0) {
        // 0x80020430: addiu       $a1, $a0, 0xC4
        ctx->r5 = ADD32(ctx->r4, 0XC4);
            goto L_80020448;
    }
    // 0x80020430: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x80020434: jal         0x80047534
    // 0x80020438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80047534(rdram, ctx);
        goto after_2;
    // 0x80020438: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_2:
    // 0x8002043C: beq         $v0, $zero, L_800204F4
    if (ctx->r2 == 0) {
        // 0x80020440: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800204F4;
    }
    // 0x80020440: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80020444: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
L_80020448:
    // 0x80020448: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
L_8002044C:
    // 0x8002044C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80020450: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80020454: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80020458: lwc1        $f8, 0xC8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x8002045C: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80020460: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80020464: swc1        $f6, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f6.u32l;
    // 0x80020468: swc1        $f16, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f16.u32l;
    // 0x8002046C: lwc1        $f18, 0xC8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x80020470: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80020474: nop

    // 0x80020478: bc1fl       L_800204F8
    if (!c1cs) {
        // 0x8002047C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800204F8;
    }
    goto skip_7;
    // 0x8002047C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80020480: b           L_800204F4
    // 0x80020484: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
        goto L_800204F4;
    // 0x80020484: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
L_80020488:
    // 0x80020488: bnel        $t8, $zero, L_800204BC
    if (ctx->r24 != 0) {
        // 0x8002048C: lui         $at, 0xC0E0
        ctx->r1 = S32(0XC0E0 << 16);
            goto L_800204BC;
    }
    goto skip_8;
    // 0x8002048C: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    skip_8:
    // 0x80020490: lw          $t0, 0x38($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X38);
    // 0x80020494: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80020498: and         $t9, $t0, $a1
    ctx->r25 = ctx->r8 & ctx->r5;
    // 0x8002049C: bne         $t9, $zero, L_800204B8
    if (ctx->r25 != 0) {
        // 0x800204A0: addiu       $a1, $a0, 0xC4
        ctx->r5 = ADD32(ctx->r4, 0XC4);
            goto L_800204B8;
    }
    // 0x800204A0: addiu       $a1, $a0, 0xC4
    ctx->r5 = ADD32(ctx->r4, 0XC4);
    // 0x800204A4: jal         0x800474D8
    // 0x800204A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_800474D8(rdram, ctx);
        goto after_3;
    // 0x800204A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x800204AC: beq         $v0, $zero, L_800204F4
    if (ctx->r2 == 0) {
        // 0x800204B0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800204F4;
    }
    // 0x800204B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800204B4: lwc1        $f0, 0xC4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC4);
L_800204B8:
    // 0x800204B8: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
L_800204BC:
    // 0x800204BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800204C0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800204C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800204C8: lwc1        $f6, 0xC8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800204CC: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800204D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800204D4: swc1        $f4, 0xC4($a0)
    MEM_W(0XC4, ctx->r4) = ctx->f4.u32l;
    // 0x800204D8: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    // 0x800204DC: lwc1        $f16, 0xC8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC8);
    // 0x800204E0: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800204E4: nop

    // 0x800204E8: bc1fl       L_800204F8
    if (!c1cs) {
        // 0x800204EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800204F8;
    }
    goto skip_9;
    // 0x800204EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x800204F0: swc1        $f2, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f2.u32l;
L_800204F4:
    // 0x800204F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800204F8:
    // 0x800204F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800204FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80020500: jr          $ra
    // 0x80020504: nop

    return;
    // 0x80020504: nop

;}
RECOMP_FUNC void func_806D2BCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D2BCC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806D2BD0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x806D2BD4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x806D2BD8: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806D2BDC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806D2BE0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806D2BE4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806D2BE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806D2BEC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806D2BF0: lui         $t1, 0x806D
    ctx->r9 = S32(RELOC_HI16(610, 0X16C4) << 16);
    // 0x806D2BF4: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806D2BF8: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806D2BFC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806D2C00: lw          $t1, 0x2C84($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(610, 0X16C4));
    // 0x806D2C04: jr          $ra
    // 0x806D2C08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806D2C08: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    // 0x806D2C0C: nop

;}
RECOMP_FUNC void func_804CFAE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CFAE4: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x804CFAE8: lui         $t6, 0x804D
    ctx->r14 = S32(RELOC_HI16(240, 0X910) << 16);
    // 0x804CFAEC: addiu       $t6, $t6, -0x1440
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(240, 0X910));
    // 0x804CFAF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x804CFAF4: jr          $ra
    // 0x804CFAF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
    return;
    // 0x804CFAF8: sw          $t6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r14;
;}
RECOMP_FUNC void func_807BA478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807BA478: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x807BA47C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x807BA480: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807BA484: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x807BA488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x807BA48C: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x807BA490: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x807BA494: lui         $a0, 0x807C
    ctx->r4 = S32(RELOC_HI16(892, 0X190) << 16);
    // 0x807BA498: lui         $a1, 0x4006
    ctx->r5 = S32(0X4006 << 16);
    // 0x807BA49C: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x807BA4A0: addiu       $a0, $a0, -0x5A80
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(892, 0X190));
    // 0x807BA4A4: jal         0x80046804
    // 0x807BA4A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x807BA4A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x807BA4AC: beq         $v0, $zero, L_807BA4FC
    if (ctx->r2 == 0) {
        // 0x807BA4B0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_807BA4FC;
    }
    // 0x807BA4B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x807BA4B4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x807BA4B8: lui         $at, 0x807C
    ctx->r1 = S32(RELOC_HI16(892, 0X130) << 16);
    // 0x807BA4BC: lwc1        $f0, -0x5AE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(892, 0X130));
    // 0x807BA4C0: lw          $t7, 0x138($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X138);
    // 0x807BA4C4: lw          $t8, 0x168($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X168);
    // 0x807BA4C8: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x807BA4CC: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x807BA4D0: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x807BA4D4: swc1        $f0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f0.u32l;
    // 0x807BA4D8: sw          $t7, 0x138($v0)
    MEM_W(0X138, ctx->r2) = ctx->r15;
    // 0x807BA4DC: lw          $t9, -0x7250($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7250);
    // 0x807BA4E0: lw          $v0, 0x88($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X88);
    // 0x807BA4E4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x807BA4E8: sll         $t0, $t9, 9
    ctx->r8 = S32(ctx->r25 << 9);
    // 0x807BA4EC: jal         0x8004590C
    // 0x807BA4F0: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    func_8004590C(rdram, ctx);
        goto after_1;
    // 0x807BA4F0: addu        $a1, $t0, $v0
    ctx->r5 = ADD32(ctx->r8, ctx->r2);
    after_1:
    // 0x807BA4F4: jal         0x80044194
    // 0x807BA4F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_80044194(rdram, ctx);
        goto after_2;
    // 0x807BA4F8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_807BA4FC:
    // 0x807BA4FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x807BA500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x807BA504: jr          $ra
    // 0x807BA508: nop

    return;
    // 0x807BA508: nop

    // 0x807BA50C: nop

;}
RECOMP_FUNC void func_8041DAA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8041DAA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8041DAA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8041DAAC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8041DAB0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8041DAB4: jal         0x80048F84
    // 0x8041DAB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8041DAB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8041DABC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8041DAC0: jal         0x80048F84
    // 0x8041DAC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8041DAC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8041DAC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8041DACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8041DAD0: jr          $ra
    // 0x8041DAD4: nop

    return;
    // 0x8041DAD4: nop

;}
RECOMP_FUNC void func_804EFBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804EFBB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804EFBB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804EFBBC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x804EFBC0: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x804EFBC4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x804EFBC8: jal         0x80047090
    // 0x804EFBCC: addiu       $a0, $zero, 0x413C
    ctx->r4 = ADD32(0, 0X413C);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x804EFBCC: addiu       $a0, $zero, 0x413C
    ctx->r4 = ADD32(0, 0X413C);
    after_0:
    // 0x804EFBD0: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x804EFBD4: beq         $v0, $at, L_804EFC28
    if (ctx->r2 == ctx->r1) {
        // 0x804EFBD8: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_804EFC28;
    }
    // 0x804EFBD8: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x804EFBDC: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804EFBE0: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x804EFBE4: lui         $a0, 0x804F
    ctx->r4 = S32(RELOC_HI16(267, 0X1390) << 16);
    // 0x804EFBE8: addiu       $a0, $a0, 0x120
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(267, 0X1390));
    // 0x804EFBEC: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x804EFBF0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804EFBF4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x804EFBF8: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x804EFBFC: beq         $at, $zero, L_804EFC28
    if (ctx->r1 == 0) {
        // 0x804EFC00: lwc1        $f4, 0x28($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
            goto L_804EFC28;
    }
    // 0x804EFC00: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x804EFC04: lui         $at, 0x413C
    ctx->r1 = S32(0X413C << 16);
    // 0x804EFC08: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x804EFC0C: or          $a1, $v1, $at
    ctx->r5 = ctx->r3 | ctx->r1;
    // 0x804EFC10: jal         0x80046804
    // 0x804EFC14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_1;
    // 0x804EFC14: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x804EFC18: beq         $v0, $zero, L_804EFC28
    if (ctx->r2 == 0) {
        // 0x804EFC1C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_804EFC28;
    }
    // 0x804EFC1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x804EFC20: jal         0x80044194
    // 0x804EFC24: nop

    func_80044194(rdram, ctx);
        goto after_2;
    // 0x804EFC24: nop

    after_2:
L_804EFC28:
    // 0x804EFC28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804EFC2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804EFC30: jr          $ra
    // 0x804EFC34: nop

    return;
    // 0x804EFC34: nop

;}
RECOMP_FUNC void func_80048060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80048060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80048064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80048068: lw          $t6, 0x180($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X180);
    // 0x8004806C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80048070: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80048074: bne         $t6, $zero, L_8004808C
    if (ctx->r14 != 0) {
        // 0x80048078: addiu       $a0, $a0, 0x7D0
        ctx->r4 = ADD32(ctx->r4, 0X7D0);
            goto L_8004808C;
    }
    // 0x80048078: addiu       $a0, $a0, 0x7D0
    ctx->r4 = ADD32(ctx->r4, 0X7D0);
    // 0x8004807C: addiu       $a1, $zero, 0x995
    ctx->r5 = ADD32(0, 0X995);
    // 0x80048080: jal         0x80071380
    // 0x80048084: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Fault_HungUp(rdram, ctx);
        goto after_0;
    // 0x80048084: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80048088: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_8004808C:
    // 0x8004808C: addiu       $a0, $a2, 0x3C
    ctx->r4 = ADD32(ctx->r6, 0X3C);
    // 0x80048090: addiu       $a1, $a2, 0x84
    ctx->r5 = ADD32(ctx->r6, 0X84);
    // 0x80048094: jal         0x80065490
    // 0x80048098: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80065490(rdram, ctx);
        goto after_1;
    // 0x80048098: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8004809C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800480A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800480A4: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x800480A8: lh          $t9, 0x17E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X17E);
    // 0x800480AC: lw          $t8, 0x180($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X180);
    // 0x800480B0: sb          $t7, 0x17C($a2)
    MEM_B(0X17C, ctx->r6) = ctx->r15;
    // 0x800480B4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800480B8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800480BC: sw          $zero, 0x188($t1)
    MEM_W(0X188, ctx->r9) = 0;
    // 0x800480C0: lw          $v0, 0x180($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X180);
    // 0x800480C4: sh          $t2, 0x17E($a2)
    MEM_H(0X17E, ctx->r6) = ctx->r10;
    // 0x800480C8: lh          $t3, 0x184($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X184);
    // 0x800480CC: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x800480D0: sh          $t4, 0x184($v0)
    MEM_H(0X184, ctx->r2) = ctx->r12;
    // 0x800480D4: sw          $zero, 0x180($a2)
    MEM_W(0X180, ctx->r6) = 0;
    // 0x800480D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800480DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800480E0: jr          $ra
    // 0x800480E4: nop

    return;
    // 0x800480E4: nop

;}
RECOMP_FUNC void func_80021E8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021E8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80021E90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021E94: lwc1        $f12, 0xDC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XDC);
    // 0x80021E98: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80021E9C: jal         0x80065954
    // 0x80021EA0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x80021EA0: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80021EA4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80021EA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80021EAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80021EB0: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80021EB4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80021EB8: nop

    // 0x80021EBC: bc1fl       L_80021EFC
    if (!c1cs) {
        // 0x80021EC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021EFC;
    }
    goto skip_0;
    // 0x80021EC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80021EC4: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80021EC8: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x80021ECC: bnel        $t7, $zero, L_80021EFC
    if (ctx->r15 != 0) {
        // 0x80021ED0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021EFC;
    }
    goto skip_1;
    // 0x80021ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80021ED4: lwc1        $f8, 0xC4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC4);
    // 0x80021ED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80021EDC: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80021EE0: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x80021EE4: nop

    // 0x80021EE8: bc1fl       L_80021EFC
    if (!c1cs) {
        // 0x80021EEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80021EFC;
    }
    goto skip_2;
    // 0x80021EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80021EF0: jal         0x80021F54
    // 0x80021EF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_80021F54(rdram, ctx);
        goto after_1;
    // 0x80021EF4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80021EF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021EFC:
    // 0x80021EFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80021F00: jr          $ra
    // 0x80021F04: nop

    return;
    // 0x80021F04: nop

;}
RECOMP_FUNC void func_80444F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80444F4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80444F50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80444F54: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80444F58: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80444F5C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80444F60: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80444F64: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80444F68: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80444F6C: jal         0x80047090
    // 0x80444F70: addiu       $a0, $zero, 0x40F4
    ctx->r4 = ADD32(0, 0X40F4);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80444F70: addiu       $a0, $zero, 0x40F4
    ctx->r4 = ADD32(0, 0X40F4);
    after_0:
    // 0x80444F74: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80444F78: beq         $v0, $at, L_80445090
    if (ctx->r2 == ctx->r1) {
        // 0x80444F7C: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80445090;
    }
    // 0x80444F7C: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80444F80: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80444F84: lui         $at, 0x40F4
    ctx->r1 = S32(0X40F4 << 16);
    // 0x80444F88: ori         $at, $at, 0x2000
    ctx->r1 = ctx->r1 | 0X2000;
    // 0x80444F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80444F90: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80444F94: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80444F98: jal         0x8004613C
    // 0x80444F9C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80444F9C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    after_1:
    // 0x80444FA0: beq         $v0, $zero, L_80445090
    if (ctx->r2 == 0) {
        // 0x80444FA4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80445090;
    }
    // 0x80444FA4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80444FA8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80444FAC: jal         0x80047F9C
    // 0x80444FB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80444FB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80444FB4: lwc1        $f2, 0x44($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80444FB8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80444FBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80444FC0: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80444FC4: sb          $t6, 0x17C($s0)
    MEM_B(0X17C, ctx->r16) = ctx->r14;
    // 0x80444FC8: lw          $t7, 0x478($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X478);
    // 0x80444FCC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FF0) << 16);
    // 0x80444FD0: addiu       $a0, $zero, 0x4023
    ctx->r4 = ADD32(0, 0X4023);
    // 0x80444FD4: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80444FD8: addiu       $a1, $zero, 0x1F
    ctx->r5 = ADD32(0, 0X1F);
    // 0x80444FDC: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x80444FE0: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80444FE4: lw          $t8, 0x478($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X478);
    // 0x80444FE8: lwc1        $f0, 0x4($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80444FEC: swc1        $f0, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->f0.u32l;
    // 0x80444FF0: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80444FF4: lw          $t9, 0x478($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X478);
    // 0x80444FF8: lwc1        $f6, -0x7C30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FF0));
    // 0x80444FFC: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80445000: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80445004: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80445008: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    // 0x8044500C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80445010: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80445014: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80445018: jal         0x8005D078
    // 0x8044501C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_8005D078(rdram, ctx);
        goto after_3;
    // 0x8044501C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x80445020: beq         $v0, $zero, L_80445090
    if (ctx->r2 == 0) {
        // 0x80445024: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80445090;
    }
    // 0x80445024: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80445028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8044502C: jal         0x80047F9C
    // 0x80445030: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    func_80047F9C(rdram, ctx);
        goto after_4;
    // 0x80445030: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_4:
    // 0x80445034: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80445038: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8044503C: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x80445040: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x80445044: sb          $v0, 0x17C($a1)
    MEM_B(0X17C, ctx->r5) = ctx->r2;
    // 0x80445048: lw          $t0, 0x478($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X478);
    // 0x8044504C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X13FF4) << 16);
    // 0x80445050: lw          $t3, 0x16C($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X16C);
    // 0x80445054: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80445058: swc1        $f0, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f0.u32l;
    // 0x8044505C: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x80445060: lw          $t1, 0x478($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X478);
    // 0x80445064: lwc1        $f0, 0x4($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X4);
    // 0x80445068: swc1        $f0, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f0.u32l;
    // 0x8044506C: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x80445070: lw          $t2, 0x478($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X478);
    // 0x80445074: lwc1        $f10, -0x7C2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X13FF4));
    // 0x80445078: lwc1        $f8, 0x8($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X8);
    // 0x8044507C: sb          $v0, 0x165($a1)
    MEM_B(0X165, ctx->r5) = ctx->r2;
    // 0x80445080: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80445084: swc1        $f0, 0x8C($a1)
    MEM_W(0X8C, ctx->r5) = ctx->f0.u32l;
    // 0x80445088: swc1        $f0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f0.u32l;
    // 0x8044508C: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
L_80445090:
    // 0x80445090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80445094: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80445098: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8044509C: jr          $ra
    // 0x804450A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804450A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800765B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800765B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800765B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800765B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800765BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800765C0: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800765C4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800765C8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800765CC: jal         0x80076190
    // 0x800765D0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    func_80076190(rdram, ctx);
        goto after_0;
    // 0x800765D0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x800765D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800765D8: jal         0x8007288C
    // 0x800765DC: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    func_8007288C(rdram, ctx);
        goto after_1;
    // 0x800765DC: lw          $a0, -0x260C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X260C);
    after_1:
    // 0x800765E0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800765E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800765E8: jal         0x800728EC
    // 0x800765EC: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    func_800728EC(rdram, ctx);
        goto after_2;
    // 0x800765EC: lw          $a1, 0x8($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X8);
    after_2:
    // 0x800765F0: lui         $t8, 0x800B
    ctx->r24 = S32(0X800B << 16);
    // 0x800765F4: lw          $t8, -0x7AD8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AD8);
    // 0x800765F8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800765FC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80076600: sw          $t8, -0x7ADC($at)
    MEM_W(-0X7ADC, ctx->r1) = ctx->r24;
    // 0x80076604: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80076608: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8007660C: jal         0x80075DAC
    // 0x80076610: sw          $t9, -0x26A0($at)
    MEM_W(-0X26A0, ctx->r1) = ctx->r25;
    func_80075DAC(rdram, ctx);
        goto after_3;
    // 0x80076610: sw          $t9, -0x26A0($at)
    MEM_W(-0X26A0, ctx->r1) = ctx->r25;
    after_3:
    // 0x80076614: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80076618: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8007661C: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80076620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076624: jr          $ra
    // 0x80076628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80076628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8045A4B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8045A4B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A4B4: lui         $t8, 0x1F
    ctx->r24 = S32(0X1F << 16);
    // 0x8045A4B8: ori         $t8, $t8, 0x3205
    ctx->r24 = ctx->r24 | 0X3205;
    // 0x8045A4BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8045A4C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8045A4C4: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8045A4C8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8045A4CC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8045A4D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A4D4: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x8045A4D8: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8045A4DC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8045A4E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8045A4E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8045A4E8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8045A4EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A4F0: ori         $t2, $t2, 0x18
    ctx->r10 = ctx->r10 | 0X18;
    // 0x8045A4F4: addiu       $t3, $zero, 0x2C80
    ctx->r11 = ADD32(0, 0X2C80);
    // 0x8045A4F8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8045A4FC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8045A500: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8045A504: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8045A508: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A50C: lui         $a3, 0x50
    ctx->r7 = S32(0X50 << 16);
    // 0x8045A510: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8045A514: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8045A518: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8045A51C: ori         $t5, $t5, 0x3
    ctx->r13 = ctx->r13 | 0X3;
    // 0x8045A520: ori         $a3, $a3, 0x4240
    ctx->r7 = ctx->r7 | 0X4240;
    // 0x8045A524: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8045A528: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8045A52C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A530: lui         $t7, 0xB900
    ctx->r15 = S32(0XB900 << 16);
    // 0x8045A534: ori         $t7, $t7, 0x31D
    ctx->r15 = ctx->r15 | 0X31D;
    // 0x8045A538: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8045A53C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8045A540: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x8045A544: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8045A548: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A54C: lui         $t0, 0xFFFE
    ctx->r8 = S32(0XFFFE << 16);
    // 0x8045A550: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8045A554: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8045A558: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8045A55C: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8045A560: ori         $t0, $t0, 0x793C
    ctx->r8 = ctx->r8 | 0X793C;
    // 0x8045A564: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8045A568: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8045A56C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A570: lui         $t2, 0xB700
    ctx->r10 = S32(0XB700 << 16);
    // 0x8045A574: addiu       $t3, $zero, 0x204
    ctx->r11 = ADD32(0, 0X204);
    // 0x8045A578: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8045A57C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8045A580: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8045A584: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8045A588: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8045A58C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8045A590: ori         $t6, $t6, 0x8000
    ctx->r14 = ctx->r14 | 0X8000;
    // 0x8045A594: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8045A598: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8045A59C: lui         $t5, 0xBB00
    ctx->r13 = S32(0XBB00 << 16);
    // 0x8045A5A0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8045A5A4: jr          $ra
    // 0x8045A5A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    return;
    // 0x8045A5A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void func_8067612C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067612C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80676130: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80676134: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80676138: lw          $v1, 0x180($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X180);
    // 0x8067613C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80676140: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80676144: beq         $v1, $zero, L_806761D4
    if (ctx->r3 == 0) {
        // 0x80676148: nop
    
            goto L_806761D4;
    }
    // 0x80676148: nop

    // 0x8067614C: lw          $a1, 0x1F4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X1F4);
    // 0x80676150: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80676154: jal         0x80675C30
    // 0x80676158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_80675C30(rdram, ctx);
        goto after_0;
    // 0x80676158: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8067615C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80676160: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80676164: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80676168: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x8067616C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80676170: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80676174: blez        $v1, L_806761C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80676178: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_806761C0;
    }
    // 0x80676178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8067617C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80676180: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80676184: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x80676188: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8067618C: lwc1        $f0, 0x3F8($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X3F8);
    // 0x80676190: lui         $at, 0x8067
    ctx->r1 = S32(RELOC_HI16(535, 0X25E0) << 16);
    // 0x80676194: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80676198: nop

    // 0x8067619C: bc1f        L_806761B0
    if (!c1cs) {
        // 0x806761A0: nop
    
            goto L_806761B0;
    }
    // 0x806761A0: nop

    // 0x806761A4: lwc1        $f6, 0x7CA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(535, 0X25E0));
    // 0x806761A8: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x806761AC: swc1        $f8, 0x3F8($a1)
    MEM_W(0X3F8, ctx->r5) = ctx->f8.u32l;
L_806761B0:
    // 0x806761B0: jal         0x80675C30
    // 0x806761B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675C30(rdram, ctx);
        goto after_1;
    // 0x806761B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806761B8: b           L_806761D4
    // 0x806761BC: nop

        goto L_806761D4;
    // 0x806761BC: nop

L_806761C0:
    // 0x806761C0: sh          $t7, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r15;
    // 0x806761C4: jal         0x80677A88
    // 0x806761C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80677A88(rdram, ctx);
        goto after_2;
    // 0x806761C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x806761CC: jal         0x80675B9C
    // 0x806761D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675B9C(rdram, ctx);
        goto after_3;
    // 0x806761D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_806761D4:
    // 0x806761D4: jal         0x80675CD0
    // 0x806761D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80675CD0(rdram, ctx);
        goto after_4;
    // 0x806761D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x806761DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x806761E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806761E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x806761E8: jr          $ra
    // 0x806761EC: nop

    return;
    // 0x806761EC: nop

;}
RECOMP_FUNC void func_8064E5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E5E8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8064E5EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E5F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E5F4: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064E5F8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E5FC: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8064E600: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8064E604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8064E608: jal         0x80048F84
    // 0x8064E60C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8064E60C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8064E610: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8064E614: jal         0x80048F84
    // 0x8064E618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8064E618: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8064E61C: jal         0x8064E014
    // 0x8064E620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8064E014(rdram, ctx);
        goto after_2;
    // 0x8064E620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8064E624: bne         $v0, $zero, L_8064E6F8
    if (ctx->r2 != 0) {
        // 0x8064E628: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8064E6F8;
    }
    // 0x8064E628: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8064E62C: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x8064E630: beq         $v0, $zero, L_8064E640
    if (ctx->r2 == 0) {
        // 0x8064E634: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8064E640;
    }
    // 0x8064E634: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8064E638: b           L_8064E6F8
    // 0x8064E63C: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
        goto L_8064E6F8;
    // 0x8064E63C: sw          $t7, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r15;
L_8064E640:
    // 0x8064E640: jal         0x8004700C
    // 0x8064E644: nop

    func_8004700C(rdram, ctx);
        goto after_3;
    // 0x8064E644: nop

    after_3:
    // 0x8064E648: beq         $v0, $zero, L_8064E694
    if (ctx->r2 == 0) {
        // 0x8064E64C: nop
    
            goto L_8064E694;
    }
    // 0x8064E64C: nop

    // 0x8064E650: lwc1        $f4, 0x84($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8064E654: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064E658: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8064E65C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8064E660: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8064E664: nop

    // 0x8064E668: bc1fl       L_8064E688
    if (!c1cs) {
        // 0x8064E66C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8064E688;
    }
    goto skip_0;
    // 0x8064E66C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x8064E670: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064E674: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064E678: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064E67C: b           L_8064E6CC
    // 0x8064E680: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
        goto L_8064E6CC;
    // 0x8064E680: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x8064E684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8064E688:
    // 0x8064E688: sw          $t8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r24;
    // 0x8064E68C: b           L_8064E6CC
    // 0x8064E690: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
        goto L_8064E6CC;
    // 0x8064E690: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
L_8064E694:
    // 0x8064E694: jal         0x800653D8
    // 0x8064E698: nop

    func_800653D8(rdram, ctx);
        goto after_4;
    // 0x8064E698: nop

    after_4:
    // 0x8064E69C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8064E6A0: beq         $t9, $zero, L_8064E6BC
    if (ctx->r25 == 0) {
        // 0x8064E6A4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8064E6BC;
    }
    // 0x8064E6A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8064E6A8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8064E6AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8064E6B0: sw          $zero, 0x138($s0)
    MEM_W(0X138, ctx->r16) = 0;
    // 0x8064E6B4: b           L_8064E6CC
    // 0x8064E6B8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
        goto L_8064E6CC;
    // 0x8064E6B8: swc1        $f16, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f16.u32l;
L_8064E6BC:
    // 0x8064E6BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8064E6C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8064E6C4: sw          $t0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->r8;
    // 0x8064E6C8: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
L_8064E6CC:
    // 0x8064E6CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064E6D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064E6D4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x8064E6D8: jal         0x8064E7C0
    // 0x8064E6DC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    func_8064E7C0(rdram, ctx);
        goto after_5;
    // 0x8064E6DC: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x8064E6E0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x8064E6E4: jal         0x80067BBC
    // 0x8064E6E8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_6;
    // 0x8064E6E8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_6:
    // 0x8064E6EC: addiu       $a0, $zero, 0x6B
    ctx->r4 = ADD32(0, 0X6B);
    // 0x8064E6F0: jal         0x80067818
    // 0x8064E6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067818(rdram, ctx);
        goto after_7;
    // 0x8064E6F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
L_8064E6F8:
    // 0x8064E6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8064E6FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8064E704: jr          $ra
    // 0x8064E708: nop

    return;
    // 0x8064E708: nop

;}
RECOMP_FUNC void func_805196C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805196C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805196CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805196D0: lw          $v1, 0x174($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X174);
    // 0x805196D4: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x805196D8: sw          $t6, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r14;
    // 0x805196DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x805196E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805196E4: jal         0x80519BE4
    // 0x805196E8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_80519BE4(rdram, ctx);
        goto after_0;
    // 0x805196E8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805196EC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x805196F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x805196F4: addiu       $t1, $zero, 0x101
    ctx->r9 = ADD32(0, 0X101);
    // 0x805196F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x805196FC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80519700: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x80519704: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80519708: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x8051970C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80519710: lh          $t9, 0xC($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XC);
    // 0x80519714: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80519718: sh          $t0, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r8;
    // 0x8051971C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80519720: sh          $t1, 0x16($t2)
    MEM_H(0X16, ctx->r10) = ctx->r9;
    // 0x80519724: jal         0x80519668
    // 0x80519728: sb          $t3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r11;
    func_80519668(rdram, ctx);
        goto after_1;
    // 0x80519728: sb          $t3, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r11;
    after_1:
    // 0x8051972C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80519730: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80519734: sw          $zero, 0x130($a0)
    MEM_W(0X130, ctx->r4) = 0;
    // 0x80519738: sb          $t4, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r12;
    // 0x8051973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80519740: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80519744: jr          $ra
    // 0x80519748: nop

    return;
    // 0x80519748: nop

;}
RECOMP_FUNC void func_8004F2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004F2B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004F2B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004F2B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8004F2BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8004F2C0: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8004F2C4: lw          $s0, 0x16C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X16C);
    // 0x8004F2C8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8004F2CC: jal         0x80045520
    // 0x8004F2D0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    func_80045520(rdram, ctx);
        goto after_0;
    // 0x8004F2D0: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    after_0:
    // 0x8004F2D4: bnel        $v0, $zero, L_8004F2E8
    if (ctx->r2 != 0) {
        // 0x8004F2D8: lbu         $t7, 0x24($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X24);
            goto L_8004F2E8;
    }
    goto skip_0;
    // 0x8004F2D8: lbu         $t7, 0x24($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X24);
    skip_0:
    // 0x8004F2DC: b           L_8004F378
    // 0x8004F2E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004F378;
    // 0x8004F2E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004F2E4: lbu         $t7, 0x24($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X24);
L_8004F2E8:
    // 0x8004F2E8: andi        $t8, $t7, 0xFF0F
    ctx->r24 = ctx->r15 & 0XFF0F;
    // 0x8004F2EC: sb          $t8, 0x24($s0)
    MEM_B(0X24, ctx->r16) = ctx->r24;
    // 0x8004F2F0: lw          $t9, 0x168($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X168);
    // 0x8004F2F4: sw          $t9, 0x1AC($s0)
    MEM_W(0X1AC, ctx->r16) = ctx->r25;
    // 0x8004F2F8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8004F2FC: addiu       $v1, $v1, 0x4C
    ctx->r3 = ADD32(ctx->r3, 0X4C);
    // 0x8004F300: sw          $v1, 0x1B0($s0)
    MEM_W(0X1B0, ctx->r16) = ctx->r3;
    // 0x8004F304: lw          $t0, 0x1C($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X1C);
    // 0x8004F308: sw          $t0, 0x1B4($s0)
    MEM_W(0X1B4, ctx->r16) = ctx->r8;
    // 0x8004F30C: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8004F310: beql        $t1, $zero, L_8004F378
    if (ctx->r9 == 0) {
        // 0x8004F314: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8004F378;
    }
    goto skip_1;
    // 0x8004F314: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8004F318: jal         0x8004ED70
    // 0x8004F31C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_8004ED70(rdram, ctx);
        goto after_1;
    // 0x8004F31C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8004F320: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004F324: bne         $v0, $zero, L_8004F344
    if (ctx->r2 != 0) {
        // 0x8004F328: sw          $v0, 0x1BC($s0)
        MEM_W(0X1BC, ctx->r16) = ctx->r2;
            goto L_8004F344;
    }
    // 0x8004F328: sw          $v0, 0x1BC($s0)
    MEM_W(0X1BC, ctx->r16) = ctx->r2;
    // 0x8004F32C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8004F330: addiu       $a0, $a0, 0x93C
    ctx->r4 = ADD32(ctx->r4, 0X93C);
    // 0x8004F334: addiu       $a1, $zero, 0x159
    ctx->r5 = ADD32(0, 0X159);
    // 0x8004F338: jal         0x80071380
    // 0x8004F33C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    Fault_HungUp(rdram, ctx);
        goto after_2;
    // 0x8004F33C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x8004F340: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_8004F344:
    // 0x8004F344: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x8004F348: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8004F34C: jal         0x8004EEEC
    // 0x8004F350: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    func_8004EEEC(rdram, ctx);
        goto after_3;
    // 0x8004F350: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    after_3:
    // 0x8004F354: bne         $v0, $zero, L_8004F364
    if (ctx->r2 != 0) {
        // 0x8004F358: sw          $v0, 0x1B8($s0)
        MEM_W(0X1B8, ctx->r16) = ctx->r2;
            goto L_8004F364;
    }
    // 0x8004F358: sw          $v0, 0x1B8($s0)
    MEM_W(0X1B8, ctx->r16) = ctx->r2;
    // 0x8004F35C: b           L_8004F378
    // 0x8004F360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8004F378;
    // 0x8004F360: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004F364:
    // 0x8004F364: jal         0x8004EFDC
    // 0x8004F368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_8004EFDC(rdram, ctx);
        goto after_4;
    // 0x8004F368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x8004F36C: jal         0x8004F290
    // 0x8004F370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8004F290(rdram, ctx);
        goto after_5;
    // 0x8004F370: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8004F374: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8004F378:
    // 0x8004F378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004F37C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8004F380: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8004F384: jr          $ra
    // 0x8004F388: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8004F388: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80046F44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046F44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80046F48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80046F4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80046F50: bne         $a1, $at, L_80046F60
    if (ctx->r5 != ctx->r1) {
        // 0x80046F54: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80046F60;
    }
    // 0x80046F54: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80046F58: b           L_80046F70
    // 0x80046F5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80046F70;
    // 0x80046F5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80046F60:
    // 0x80046F60: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80046F64: addiu       $a1, $a1, 0x6EF0
    ctx->r5 = ADD32(ctx->r5, 0X6EF0);
    // 0x80046F68: jal         0x80046D90
    // 0x80046F6C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    func_80046D90(rdram, ctx);
        goto after_0;
    // 0x80046F6C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    after_0:
L_80046F70:
    // 0x80046F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80046F74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80046F78: jr          $ra
    // 0x80046F7C: nop

    return;
    // 0x80046F7C: nop

;}
RECOMP_FUNC void func_8064E450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064E450: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8064E454: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8064E458: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8064E45C: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x8064E460: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8064E464: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x8064E468: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8064E46C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8064E470: jal         0x80048F84
    // 0x8064E474: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x8064E474: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8064E478: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8064E47C: jal         0x80048F84
    // 0x8064E480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_1;
    // 0x8064E480: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8064E484: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8064E488: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8064E48C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8064E490: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8064E494: lbu         $t0, 0x2C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X2C);
    // 0x8064E498: beql        $t0, $zero, L_8064E4C8
    if (ctx->r8 == 0) {
        // 0x8064E49C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8064E4C8;
    }
    goto skip_0;
    // 0x8064E49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8064E4A0: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8064E4A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8064E4A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8064E4AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064E4B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8064E4B4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8064E4B8: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8064E4BC: jal         0x8064E7C0
    // 0x8064E4C0: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    func_8064E7C0(rdram, ctx);
        goto after_2;
    // 0x8064E4C0: swc1        $f8, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x8064E4C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8064E4C8:
    // 0x8064E4C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8064E4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8064E4D0: jr          $ra
    // 0x8064E4D4: nop

    return;
    // 0x8064E4D4: nop

;}
RECOMP_FUNC void func_805D89AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805D89AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x805D89B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805D89B4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x805D89B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x805D89BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805D89C0: jal         0x805D87D0
    // 0x805D89C4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    func_805D87D0(rdram, ctx);
        goto after_0;
    // 0x805D89C4: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x805D89C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D89CC: jal         0x805D84A4
    // 0x805D89D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_805D84A4(rdram, ctx);
        goto after_1;
    // 0x805D89D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x805D89D4: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x805D89D8: beq         $v0, $zero, L_805D89E8
    if (ctx->r2 == 0) {
        // 0x805D89DC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_805D89E8;
    }
    // 0x805D89DC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x805D89E0: b           L_805D8A1C
    // 0x805D89E4: sw          $t6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r14;
        goto L_805D8A1C;
    // 0x805D89E4: sw          $t6, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r14;
L_805D89E8:
    // 0x805D89E8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x805D89EC: jal         0x80067BBC
    // 0x805D89F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x805D89F0: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x805D89F4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x805D89F8: jal         0x80011D1C
    // 0x805D89FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80011D1C(rdram, ctx);
        goto after_3;
    // 0x805D89FC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x805D8A00: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x805D8A04: sw          $t7, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r15;
    // 0x805D8A08: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x805D8A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805D8A10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805D8A14: jal         0x805D8AB4
    // 0x805D8A18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    func_805D8AB4(rdram, ctx);
        goto after_4;
    // 0x805D8A18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
L_805D8A1C:
    // 0x805D8A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805D8A20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x805D8A24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x805D8A28: jr          $ra
    // 0x805D8A2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x805D8A2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80036C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036C54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036C58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036C5C: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80036C60: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80036C64: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80036C68: bnel        $at, $zero, L_80036CA4
    if (ctx->r1 != 0) {
        // 0x80036C6C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80036CA4;
    }
    goto skip_0;
    // 0x80036C6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_0:
    // 0x80036C70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80036C74: jal         0x80036B50
    // 0x80036C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_80036B50(rdram, ctx);
        goto after_0;
    // 0x80036C78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80036C7C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80036C80: beq         $v0, $zero, L_80036CA0
    if (ctx->r2 == 0) {
        // 0x80036C84: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80036CA0;
    }
    // 0x80036C84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80036C88: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x80036C8C: lwc1        $f4, -0x7678($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7678);
    // 0x80036C90: jal         0x8002F26C
    // 0x80036C94: swc1        $f4, 0x114($v1)
    MEM_W(0X114, ctx->r3) = ctx->f4.u32l;
    func_8002F26C(rdram, ctx);
        goto after_1;
    // 0x80036C94: swc1        $f4, 0x114($v1)
    MEM_W(0X114, ctx->r3) = ctx->f4.u32l;
    after_1:
    // 0x80036C98: b           L_80036CA4
    // 0x80036C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80036CA4;
    // 0x80036C9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036CA0:
    // 0x80036CA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036CA4:
    // 0x80036CA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036CA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036CAC: jr          $ra
    // 0x80036CB0: nop

    return;
    // 0x80036CB0: nop

;}
RECOMP_FUNC void func_80675288(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80675288: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8067528C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80675290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80675294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80675298: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x8067529C: lwc1        $f0, 0x50($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X50);
    // 0x806752A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x806752A4: lui         $t6, 0x8067
    ctx->r14 = S32(RELOC_HI16(532, 0X3AC) << 16);
    // 0x806752A8: lui         $t7, 0x8067
    ctx->r15 = S32(RELOC_HI16(532, 0X244) << 16);
    // 0x806752AC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x806752B0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x806752B4: addiu       $t6, $t6, 0x52FC
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(532, 0X3AC));
    // 0x806752B8: addiu       $t7, $t7, 0x5194
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(532, 0X244));
    // 0x806752BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x806752C0: nop

    // 0x806752C4: bc1f        L_806752E4
    if (!c1cs) {
        // 0x806752C8: nop
    
            goto L_806752E4;
    }
    // 0x806752C8: nop

    // 0x806752CC: lw          $v0, 0x180($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X180);
    // 0x806752D0: sb          $v1, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r3;
    // 0x806752D4: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x806752D8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x806752DC: sb          $v1, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r3;
    // 0x806752E0: sw          $t7, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r15;
L_806752E4:
    // 0x806752E4: jal         0x806751EC
    // 0x806752E8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    func_806751EC(rdram, ctx);
        goto after_0;
    // 0x806752E8: swc1        $f0, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f0.u32l;
    after_0:
    // 0x806752EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x806752F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x806752F4: jr          $ra
    // 0x806752F8: nop

    return;
    // 0x806752F8: nop

;}
RECOMP_FUNC void func_8042F0BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042F0BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8042F0C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042F0C4: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8042F0C8: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x8042F0CC: lui         $t8, 0x8043
    ctx->r24 = S32(RELOC_HI16(56, 0X35E8) << 16);
    // 0x8042F0D0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8042F0D4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8042F0D8: lw          $t8, 0x16C8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(56, 0X35E8));
    // 0x8042F0DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8042F0E0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8042F0E4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8042F0E8: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x8042F0EC: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x8042F0F0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8042F0F4: beql        $v1, $zero, L_8042F128
    if (ctx->r3 == 0) {
        // 0x8042F0F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8042F128;
    }
    goto skip_0;
    // 0x8042F0F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8042F0FC: jalr        $v1
    // 0x8042F100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x8042F100: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8042F104: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8042F108: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x8042F10C: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x8042F110: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8042F114: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x8042F118: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8042F11C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x8042F120: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x8042F124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8042F128:
    // 0x8042F128: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8042F12C: jr          $ra
    // 0x8042F130: nop

    return;
    // 0x8042F130: nop

;}
RECOMP_FUNC void func_804D2D8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2D8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804D2D90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804D2D94: jal         0x80044658
    // 0x804D2D98: nop

    func_80044658(rdram, ctx);
        goto after_0;
    // 0x804D2D98: nop

    after_0:
    // 0x804D2D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804D2DA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x804D2DA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804D2DA8: sb          $t6, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r14;
    // 0x804D2DAC: jr          $ra
    // 0x804D2DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x804D2DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_806EC704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806EC704: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806EC708: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x806EC70C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x806EC710: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x806EC714: lw          $s1, 0x1F4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X1F4);
    // 0x806EC718: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x806EC71C: jal         0x800577D8
    // 0x806EC720: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    func_800577D8(rdram, ctx);
        goto after_0;
    // 0x806EC720: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x806EC724: jal         0x806EC444
    // 0x806EC728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC444(rdram, ctx);
        goto after_1;
    // 0x806EC728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x806EC72C: jal         0x806EC4B0
    // 0x806EC730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC4B0(rdram, ctx);
        goto after_2;
    // 0x806EC730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x806EC734: jal         0x806EC584
    // 0x806EC738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC584(rdram, ctx);
        goto after_3;
    // 0x806EC738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x806EC73C: bne         $v0, $zero, L_806EC75C
    if (ctx->r2 != 0) {
        // 0x806EC740: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EC75C;
    }
    // 0x806EC740: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC744: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC748: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x806EC74C: jal         0x806ED360
    // 0x806EC750: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_4;
    // 0x806EC750: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x806EC754: b           L_806EC894
    // 0x806EC758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC894;
    // 0x806EC758: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC75C:
    // 0x806EC75C: jal         0x806EC5D4
    // 0x806EC760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_806EC5D4(rdram, ctx);
        goto after_5;
    // 0x806EC760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x806EC764: beq         $v0, $zero, L_806EC784
    if (ctx->r2 == 0) {
        // 0x806EC768: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EC784;
    }
    // 0x806EC768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC76C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC770: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x806EC774: jal         0x806ED360
    // 0x806EC778: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_6;
    // 0x806EC778: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_6:
    // 0x806EC77C: b           L_806EC894
    // 0x806EC780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806EC894;
    // 0x806EC780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC784:
    // 0x806EC784: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC788: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x806EC78C: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x806EC790: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x806EC794: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x806EC798: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x806EC79C: nop

    // 0x806EC7A0: bc1fl       L_806EC894
    if (!c1cs) {
        // 0x806EC7A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_806EC894;
    }
    goto skip_0;
    // 0x806EC7A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x806EC7A8: jal         0x806EBFB8
    // 0x806EC7AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_806EBFB8(rdram, ctx);
        goto after_7;
    // 0x806EC7AC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x806EC7B0: bne         $v0, $zero, L_806EC824
    if (ctx->r2 != 0) {
        // 0x806EC7B4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_806EC824;
    }
    // 0x806EC7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC7B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806EC7BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC7C0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x806EC7C4: jal         0x806ED360
    // 0x806EC7C8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_8;
    // 0x806EC7C8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_8:
    // 0x806EC7CC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806EC7D0: lwc1        $f18, 0x40($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC7D4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x806EC7D8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x806EC7DC: nop

    // 0x806EC7E0: bc1fl       L_806EC80C
    if (!c1cs) {
        // 0x806EC7E4: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EC80C;
    }
    goto skip_1;
    // 0x806EC7E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_1:
    // 0x806EC7E8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806EC7EC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EC7F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806EC7F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC7F8: jal         0x806EC03C
    // 0x806EC7FC: nop

    func_806EC03C(rdram, ctx);
        goto after_9;
    // 0x806EC7FC: nop

    after_9:
    // 0x806EC800: b           L_806EC888
    // 0x806EC804: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EC888;
    // 0x806EC804: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x806EC808: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EC80C:
    // 0x806EC80C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x806EC810: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC814: jal         0x806EC03C
    // 0x806EC818: nop

    func_806EC03C(rdram, ctx);
        goto after_10;
    // 0x806EC818: nop

    after_10:
    // 0x806EC81C: b           L_806EC888
    // 0x806EC820: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EC888;
    // 0x806EC820: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
L_806EC824:
    // 0x806EC824: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806EC828: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x806EC82C: jal         0x806ED360
    // 0x806EC830: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_806ED360(rdram, ctx);
        goto after_11;
    // 0x806EC830: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_11:
    // 0x806EC834: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x806EC838: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC83C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x806EC840: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x806EC844: nop

    // 0x806EC848: bc1fl       L_806EC874
    if (!c1cs) {
        // 0x806EC84C: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_806EC874;
    }
    goto skip_2;
    // 0x806EC84C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x806EC850: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806EC854: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806EC858: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x806EC85C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC860: jal         0x806EC03C
    // 0x806EC864: nop

    func_806EC03C(rdram, ctx);
        goto after_12;
    // 0x806EC864: nop

    after_12:
    // 0x806EC868: b           L_806EC888
    // 0x806EC86C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
        goto L_806EC888;
    // 0x806EC86C: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x806EC870: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_806EC874:
    // 0x806EC874: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x806EC878: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x806EC87C: jal         0x806EC03C
    // 0x806EC880: nop

    func_806EC03C(rdram, ctx);
        goto after_13;
    // 0x806EC880: nop

    after_13:
    // 0x806EC884: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
L_806EC888:
    // 0x806EC888: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x806EC88C: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x806EC890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806EC894:
    // 0x806EC894: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x806EC898: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x806EC89C: jr          $ra
    // 0x806EC8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x806EC8A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_806A7CF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806A7CF0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x806A7CF4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x806A7CF8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x806A7CFC: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x806A7D00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x806A7D04: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x806A7D08: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806A7D0C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x806A7D10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x806A7D14: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x806A7D18: lui         $t1, 0x806A
    ctx->r9 = S32(RELOC_HI16(586, 0X448) << 16);
    // 0x806A7D1C: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x806A7D20: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x806A7D24: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x806A7D28: lw          $t1, 0x7E08($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(586, 0X448));
    // 0x806A7D2C: jr          $ra
    // 0x806A7D30: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x806A7D30: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void Fault_PrintCallback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F7FC: lui         $t8, 0xFFFA
    ctx->r24 = S32(0XFFFA << 16);
    // 0x8006F800: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8006F804: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006F808: ori         $t8, $t8, 0x5A5A
    ctx->r24 = ctx->r24 | 0X5A5A;
L_8006F80C:
    // 0x8006F80C: addiu       $t9, $t9, -0x8
    ctx->r25 = ADD32(ctx->r25, -0X8);
    // 0x8006F810: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8006F814: bne         $t9, $sp, L_8006F80C
    if (ctx->r25 != ctx->r29) {
        // 0x8006F818: sw          $t8, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r24;
            goto L_8006F80C;
    }
    // 0x8006F818: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8006F81C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006F820: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006F824: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006F828: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8006F82C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8006F830: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8006F834: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006F838: beql        $s0, $zero, L_8006F86C
    if (ctx->r16 == 0) {
        // 0x8006F83C: or          $v0, $s2, $zero
        ctx->r2 = ctx->r18 | 0;
            goto L_8006F86C;
    }
    goto skip_0;
    // 0x8006F83C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    skip_0:
L_8006F840:
    // 0x8006F840: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8006F844: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8006F848: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x8006F84C: jal         0x8006F7B8
    // 0x8006F850: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    Fault_PrintChar(rdram, ctx);
        goto after_0;
    // 0x8006F850: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_0:
    // 0x8006F854: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8006F858: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x8006F85C: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x8006F860: bne         $s0, $zero, L_8006F840
    if (ctx->r16 != 0) {
        // 0x8006F864: sw          $t7, 0x0($s2)
        MEM_W(0X0, ctx->r18) = ctx->r15;
            goto L_8006F840;
    }
    // 0x8006F864: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x8006F868: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8006F86C:
    // 0x8006F86C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006F870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006F874: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006F878: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006F87C: jr          $ra
    // 0x8006F880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006F880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006CB3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CB3C: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x8006CB40: addiu       $v0, $v0, 0x7EA0
    ctx->r2 = ADD32(ctx->r2, 0X7EA0);
    // 0x8006CB44: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8006CB48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006CB4C: lw          $t6, 0x3F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X3F4);
    // 0x8006CB50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006CB54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006CB58: swc1        $f4, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->f4.u32l;
    // 0x8006CB5C: lw          $t7, 0x3F4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X3F4);
    // 0x8006CB60: swc1        $f6, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->f6.u32l;
    // 0x8006CB64: lw          $t8, 0x3F4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3F4);
    // 0x8006CB68: sh          $zero, 0x64($t8)
    MEM_H(0X64, ctx->r24) = 0;
    // 0x8006CB6C: lw          $t9, 0x3F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3F4);
    // 0x8006CB70: jr          $ra
    // 0x8006CB74: sw          $zero, 0x68($t9)
    MEM_W(0X68, ctx->r25) = 0;
    return;
    // 0x8006CB74: sw          $zero, 0x68($t9)
    MEM_W(0X68, ctx->r25) = 0;
;}
RECOMP_FUNC void func_807B11E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B11E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x807B11EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x807B11F0: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x807B11F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807B11F8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x807B11FC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x807B1200: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x807B1204: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x807B1208: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x807B120C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x807B1210: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x807B1214: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x807B1218: addiu       $s1, $zero, 0xF
    ctx->r17 = ADD32(0, 0XF);
    // 0x807B121C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x807B1220: addiu       $t5, $zero, 0x10
    ctx->r13 = ADD32(0, 0X10);
    // 0x807B1224: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x807B1228: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x807B122C: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
L_807B1230:
    // 0x807B1230: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x807B1234: bnel        $t3, $t6, L_807B14DC
    if (ctx->r11 != ctx->r14) {
        // 0x807B1238: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_807B14DC;
    }
    goto skip_0;
    // 0x807B1238: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_0:
    // 0x807B123C: lwc1        $f12, 0x12C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x807B1240: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x807B1244: lwc1        $f16, 0x130($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B1248: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x807B124C: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x807B1250: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x807B1254: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x807B1258: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x807B125C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B1260: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x807B1264: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1268: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B126C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B1270: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x807B1274: sub.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x807B1278: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B127C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B1280: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x807B1284: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B1288: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x807B128C: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x807B1290: bne         $t2, $zero, L_807B1358
    if (ctx->r10 != 0) {
        // 0x807B1294: sqrt.s      $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
            goto L_807B1358;
    }
    // 0x807B1294: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B1298: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x807B129C: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x807B12A0: bnel        $t9, $zero, L_807B12F8
    if (ctx->r25 != 0) {
        // 0x807B12A4: lw          $t8, 0x3C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X3C);
            goto L_807B12F8;
    }
    goto skip_1;
    // 0x807B12A4: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    skip_1:
    // 0x807B12A8: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x807B12AC: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x807B12B0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x807B12B4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x807B12B8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807B12BC: sub.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B12C0: sub.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x807B12C4: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x807B12C8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807B12CC: add.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807B12D0: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x807B12D4: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B12D8: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x807B12DC: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B12E0: swc1        $f8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f8.u32l;
    // 0x807B12E4: lwc1        $f10, 0x130($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B12E8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x807B12EC: swc1        $f6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f6.u32l;
    // 0x807B12F0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x807B12F4: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
L_807B12F8:
    // 0x807B12F8: bnel        $t8, $zero, L_807B14DC
    if (ctx->r24 != 0) {
        // 0x807B12FC: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_807B14DC;
    }
    goto skip_2;
    // 0x807B12FC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_2:
    // 0x807B1300: lh          $t9, 0x5A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X5A);
    // 0x807B1304: lwc1        $f12, 0x12C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x807B1308: lh          $t6, 0x5C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X5C);
    // 0x807B130C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x807B1310: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x807B1314: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B1318: lwc1        $f8, 0x130($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B131C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B1320: sub.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x807B1324: sub.s       $f10, $f20, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B1328: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807B132C: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x807B1330: add.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x807B1334: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B1338: add.s       $f8, $f12, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x807B133C: mul.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B1340: swc1        $f8, 0x3C($a2)
    MEM_W(0X3C, ctx->r6) = ctx->f8.u32l;
    // 0x807B1344: lwc1        $f10, 0x130($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B1348: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x807B134C: swc1        $f6, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f6.u32l;
    // 0x807B1350: b           L_807B14D8
    // 0x807B1354: sw          $t4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r12;
        goto L_807B14D8;
    // 0x807B1354: sw          $t4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r12;
L_807B1358:
    // 0x807B1358: bnel        $t2, $s1, L_807B1424
    if (ctx->r10 != ctx->r17) {
        // 0x807B135C: lw          $t9, -0x4($t1)
        ctx->r25 = MEM_W(ctx->r9, -0X4);
            goto L_807B1424;
    }
    goto skip_3;
    // 0x807B135C: lw          $t9, -0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X4);
    skip_3:
    // 0x807B1360: lw          $t7, -0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, -0X4);
    // 0x807B1364: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x807B1368: bnel        $t7, $zero, L_807B13C0
    if (ctx->r15 != 0) {
        // 0x807B136C: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_807B13C0;
    }
    goto skip_4;
    // 0x807B136C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x807B1370: lh          $t8, -0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, -0X6);
    // 0x807B1374: lh          $t9, -0x4($a1)
    ctx->r25 = MEM_H(ctx->r5, -0X4);
    // 0x807B1378: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x807B137C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x807B1380: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B1384: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B1388: sub.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x807B138C: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x807B1390: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B1394: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x807B1398: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x807B139C: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B13A0: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x807B13A4: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B13A8: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x807B13AC: lwc1        $f8, 0x130($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B13B0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B13B4: swc1        $f4, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f4.u32l;
    // 0x807B13B8: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x807B13BC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_807B13C0:
    // 0x807B13C0: bnel        $t6, $zero, L_807B14DC
    if (ctx->r14 != 0) {
        // 0x807B13C4: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_807B14DC;
    }
    goto skip_5;
    // 0x807B13C4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_5:
    // 0x807B13C8: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x807B13CC: lwc1        $f12, 0x12C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x807B13D0: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x807B13D4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x807B13D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x807B13DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807B13E0: lwc1        $f6, 0x130($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B13E4: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807B13E8: sub.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x807B13EC: sub.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B13F0: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x807B13F4: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x807B13F8: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x807B13FC: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B1400: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x807B1404: mul.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B1408: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x807B140C: lwc1        $f8, 0x130($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B1410: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x807B1414: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x807B1418: b           L_807B14D8
    // 0x807B141C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_807B14D8;
    // 0x807B141C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x807B1420: lw          $t9, -0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, -0X4);
L_807B1424:
    // 0x807B1424: bnel        $t9, $zero, L_807B147C
    if (ctx->r25 != 0) {
        // 0x807B1428: lw          $t8, 0x4($t1)
        ctx->r24 = MEM_W(ctx->r9, 0X4);
            goto L_807B147C;
    }
    goto skip_6;
    // 0x807B1428: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    skip_6:
    // 0x807B142C: lh          $t6, -0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, -0X6);
    // 0x807B1430: lh          $t7, -0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, -0X4);
    // 0x807B1434: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x807B1438: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x807B143C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x807B1440: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B1444: sub.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x807B1448: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x807B144C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x807B1450: add.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x807B1454: sub.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x807B1458: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B145C: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807B1460: mul.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B1464: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x807B1468: lwc1        $f6, 0x130($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B146C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B1470: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x807B1474: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x807B1478: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
L_807B147C:
    // 0x807B147C: bnel        $t8, $zero, L_807B14DC
    if (ctx->r24 != 0) {
        // 0x807B1480: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_807B14DC;
    }
    goto skip_7;
    // 0x807B1480: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_7:
    // 0x807B1484: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x807B1488: lwc1        $f12, 0x12C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X12C);
    // 0x807B148C: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x807B1490: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x807B1494: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x807B1498: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x807B149C: lwc1        $f4, 0x130($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B14A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x807B14A4: sub.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x807B14A8: sub.s       $f6, $f20, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x807B14AC: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x807B14B0: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x807B14B4: add.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x807B14B8: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x807B14BC: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x807B14C0: mul.s       $f8, $f14, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f18.fl);
    // 0x807B14C4: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
    // 0x807B14C8: lwc1        $f6, 0x130($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X130);
    // 0x807B14CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x807B14D0: swc1        $f10, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f10.u32l;
    // 0x807B14D4: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
L_807B14D8:
    // 0x807B14D8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_807B14DC:
    // 0x807B14DC: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x807B14E0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x807B14E4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x807B14E8: bne         $t2, $t5, L_807B1230
    if (ctx->r10 != ctx->r13) {
        // 0x807B14EC: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_807B1230;
    }
    // 0x807B14EC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x807B14F0: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x807B14F4: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x807B14F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x807B14FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x807B1500: jr          $ra
    // 0x807B1504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x807B1504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8064C200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C208: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8064C20C: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064C210: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8064C214: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8064C218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8064C21C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C220: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8064C224: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8064C228: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x8064C22C: nop

    // 0x8064C230: bc1fl       L_8064C244
    if (!c1cs) {
        // 0x8064C234: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C244;
    }
    goto skip_0;
    // 0x8064C234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C238: jal         0x8064C5D8
    // 0x8064C23C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_8064C5D8(rdram, ctx);
        goto after_0;
    // 0x8064C23C: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_0:
    // 0x8064C240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C244:
    // 0x8064C244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C248: jr          $ra
    // 0x8064C24C: nop

    return;
    // 0x8064C24C: nop

;}
RECOMP_FUNC void func_80036420(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036420: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80036424: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036428: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8003642C: jal         0x80028220
    // 0x80036430: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    func_80028220(rdram, ctx);
        goto after_0;
    // 0x80036430: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80036434: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80036438: sw          $v0, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r2;
    // 0x8003643C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036440: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80036444: jr          $ra
    // 0x80036448: nop

    return;
    // 0x80036448: nop

;}
RECOMP_FUNC void func_80445F20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80445F20: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80445F24: addiu       $t6, $zero, 0x1B6C
    ctx->r14 = ADD32(0, 0X1B6C);
    // 0x80445F28: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80445F2C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80445F30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80445F34: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80445F38: jr          $ra
    // 0x80445F3C: sw          $t7, 0x6C9C($at)
    MEM_W(0X6C9C, ctx->r1) = ctx->r15;
    return;
    // 0x80445F3C: sw          $t7, 0x6C9C($at)
    MEM_W(0X6C9C, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void func_8005A400(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A400: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005A404: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8005A408: lw          $v0, -0x77F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X77F0);
    // 0x8005A40C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005A410: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005A414: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8005A418: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005A41C: lh          $s0, 0x6($v0)
    ctx->r16 = MEM_H(ctx->r2, 0X6);
    // 0x8005A420: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005A424: lw          $s1, 0x10($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X10);
    // 0x8005A428: beql        $s0, $zero, L_8005A470
    if (ctx->r16 == 0) {
        // 0x8005A42C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8005A470;
    }
    goto skip_0;
    // 0x8005A42C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
L_8005A430:
    // 0x8005A430: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005A434: beq         $a0, $zero, L_8005A464
    if (ctx->r4 == 0) {
        // 0x8005A438: nop
    
            goto L_8005A464;
    }
    // 0x8005A438: nop

    // 0x8005A43C: beql        $a0, $s2, L_8005A45C
    if (ctx->r4 == ctx->r18) {
        // 0x8005A440: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8005A45C;
    }
    goto skip_1;
    // 0x8005A440: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_1:
    // 0x8005A444: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8005A448: beql        $v0, $zero, L_8005A45C
    if (ctx->r2 == 0) {
        // 0x8005A44C: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_8005A45C;
    }
    goto skip_2;
    // 0x8005A44C: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_2:
    // 0x8005A450: jalr        $v0
    // 0x8005A454: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8005A454: nop

    after_0:
    // 0x8005A458: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8005A45C:
    // 0x8005A45C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8005A460: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
L_8005A464:
    // 0x8005A464: bne         $s0, $zero, L_8005A430
    if (ctx->r16 != 0) {
        // 0x8005A468: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8005A430;
    }
    // 0x8005A468: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8005A46C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005A470:
    // 0x8005A470: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A474: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A478: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005A47C: jr          $ra
    // 0x8005A480: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8005A480: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800213B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800213B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800213B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800213B8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800213BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800213C0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800213C4: jal         0x80020FFC
    // 0x800213C8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    func_80020FFC(rdram, ctx);
        goto after_0;
    // 0x800213C8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x800213CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800213D0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213D4: jal         0x800212D4
    // 0x800213D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    func_800212D4(rdram, ctx);
        goto after_1;
    // 0x800213D8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800213DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800213E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800213E4: jr          $ra
    // 0x800213E8: nop

    return;
    // 0x800213E8: nop

;}
RECOMP_FUNC void func_8002FBFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FBFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FC00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FC04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002FC08: lw          $a0, 0x1F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FC0C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002FC10: jal         0x8002F678
    // 0x8002FC14: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_8002F678(rdram, ctx);
        goto after_0;
    // 0x8002FC14: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002FC18: beq         $v0, $zero, L_8002FC2C
    if (ctx->r2 == 0) {
        // 0x8002FC1C: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8002FC2C;
    }
    // 0x8002FC1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FC20: lui         $t6, 0x8003
    ctx->r14 = S32(0X8003 << 16);
    // 0x8002FC24: addiu       $t6, $t6, -0x2B64
    ctx->r14 = ADD32(ctx->r14, -0X2B64);
    // 0x8002FC28: sw          $t6, 0xC0($a0)
    MEM_W(0XC0, ctx->r4) = ctx->r14;
L_8002FC2C:
    // 0x8002FC2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FC30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002FC34: jr          $ra
    // 0x8002FC38: nop

    return;
    // 0x8002FC38: nop

;}
RECOMP_FUNC void func_80777508(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80777508: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8077750C: jr          $ra
    // 0x80777510: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
    return;
    // 0x80777510: sw          $a1, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void func_805DD234(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805DD234: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x805DD238: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x805DD23C: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x805DD240: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x805DD244: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805DD248: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x805DD24C: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x805DD250: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x805DD254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x805DD258: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x805DD25C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x805DD260: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x805DD264: lui         $t2, 0x805E
    ctx->r10 = S32(RELOC_HI16(480, 0X2778) << 16);
    // 0x805DD268: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x805DD26C: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x805DD270: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x805DD274: lw          $t2, -0x2B88($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(480, 0X2778));
    // 0x805DD278: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x805DD27C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x805DD280: jal         0x805DADD4
    // 0x805DD284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_805DADD4(rdram, ctx);
        goto after_0;
    // 0x805DD284: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x805DD288: jal         0x805DAE90
    // 0x805DD28C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_805DAE90(rdram, ctx);
        goto after_1;
    // 0x805DD28C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x805DD290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805DD294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x805DD298: jr          $ra
    // 0x805DD29C: nop

    return;
    // 0x805DD29C: nop

;}
RECOMP_FUNC void func_80742C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80742C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80742C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80742C1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80742C20: lw          $v0, 0x1F4($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X1F4);
    // 0x80742C24: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80742C28: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80742C2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80742C30: lw          $v1, 0x6E54($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6E54);
    // 0x80742C34: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80742C38: beql        $v1, $zero, L_80742C54
    if (ctx->r3 == 0) {
        // 0x80742C3C: lw          $v1, 0x0($t6)
        ctx->r3 = MEM_W(ctx->r14, 0X0);
            goto L_80742C54;
    }
    goto skip_0;
    // 0x80742C3C: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    skip_0:
    // 0x80742C40: jal         0x80742944
    // 0x80742C44: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    func_80742944(rdram, ctx);
        goto after_0;
    // 0x80742C44: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    after_0:
    // 0x80742C48: b           L_80742C78
    // 0x80742C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80742C78;
    // 0x80742C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80742C50: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
L_80742C54:
    // 0x80742C54: lw          $a0, 0x14($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X14);
    // 0x80742C58: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x80742C5C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80742C60: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x80742C64: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80742C68: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80742C6C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80742C70: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80742C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80742C78:
    // 0x80742C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80742C7C: jr          $ra
    // 0x80742C80: nop

    return;
    // 0x80742C80: nop

;}
RECOMP_FUNC void func_8002FCFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FCFC: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8002FD00: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002FD04: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002FD08: lw          $t6, 0xD8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XD8);
    // 0x8002FD0C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8002FD10: lui         $t7, 0x8003
    ctx->r15 = S32(0X8003 << 16);
    // 0x8002FD14: beq         $t6, $at, L_8002FD30
    if (ctx->r14 == ctx->r1) {
        // 0x8002FD18: addiu       $t7, $t7, -0x14FC
        ctx->r15 = ADD32(ctx->r15, -0X14FC);
            goto L_8002FD30;
    }
    // 0x8002FD18: addiu       $t7, $t7, -0x14FC
    ctx->r15 = ADD32(ctx->r15, -0X14FC);
    // 0x8002FD1C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8002FD20: sw          $t7, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->r15;
    // 0x8002FD24: swc1        $f12, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f12.u32l;
    // 0x8002FD28: swc1        $f14, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f14.u32l;
    // 0x8002FD2C: sw          $t8, 0xD8($v0)
    MEM_W(0XD8, ctx->r2) = ctx->r24;
L_8002FD30:
    // 0x8002FD30: jr          $ra
    // 0x8002FD34: nop

    return;
    // 0x8002FD34: nop

;}
RECOMP_FUNC void func_804CE468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804CE468: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804CE46C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804CE470: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804CE474: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x804CE478: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x804CE47C: jal         0x80066E88
    // 0x804CE480: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80066E88(rdram, ctx);
        goto after_0;
    // 0x804CE480: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x804CE484: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804CE488: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CE48C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x804CE490: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x804CE494: jal         0x80066DE4
    // 0x804CE498: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x804CE498: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    after_1:
    // 0x804CE49C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x804CE4A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x804CE4A4: lwc1        $f18, 0x1C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x804CE4A8: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x804CE4AC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x804CE4B0: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x804CE4B4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x804CE4B8: swc1        $f18, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f18.u32l;
    // 0x804CE4BC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x804CE4C0: swc1        $f4, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f4.u32l;
    // 0x804CE4C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x804CE4C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804CE4CC: jr          $ra
    // 0x804CE4D0: nop

    return;
    // 0x804CE4D0: nop

;}
RECOMP_FUNC void lnearbyint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800820B0: round.w.d   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = lround(ctx->f12.d);
    // 0x800820B4: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800820B8: jr          $ra
    // 0x800820BC: nop

    return;
    // 0x800820BC: nop

;}
RECOMP_FUNC void func_80023064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023064: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023068: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002306C: lwc1        $f4, -0x32C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32C);
    // 0x80023070: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023074: swc1        $f0, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f0.u32l;
    // 0x80023078: swc1        $f4, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f4.u32l;
    // 0x8002307C: swc1        $f0, 0xE4($a0)
    MEM_W(0XE4, ctx->r4) = ctx->f0.u32l;
    // 0x80023080: lwc1        $f6, -0x328($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X328);
    // 0x80023084: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80023088: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002308C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80023090: swc1        $f6, 0xEC($a0)
    MEM_W(0XEC, ctx->r4) = ctx->f6.u32l;
    // 0x80023094: swc1        $f8, 0xDC($a0)
    MEM_W(0XDC, ctx->r4) = ctx->f8.u32l;
    // 0x80023098: lwc1        $f10, -0x324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X324);
    // 0x8002309C: jr          $ra
    // 0x800230A0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x800230A0: swc1        $f10, 0xE0($a0)
    MEM_W(0XE0, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8005A9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A9BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A9C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005A9C4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005A9C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005A9CC: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x8005A9D0: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8005A9D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005A9D8: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8005A9DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005A9E0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005A9E4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005A9E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8005A9EC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8005A9F0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8005A9F4: sw          $a1, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->r5;
    // 0x8005A9F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8005A9FC: swc1        $f4, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->f4.u32l;
    // 0x8005AA00: swc1        $f6, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f6.u32l;
L_8005AA04:
    // 0x8005AA04: lwc1        $f0, 0x11C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X11C);
    // 0x8005AA08: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8005AA0C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005AA10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8005AA14: swc1        $f2, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f2.u32l;
    // 0x8005AA18: swc1        $f0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f0.u32l;
    // 0x8005AA1C: bne         $v1, $a0, L_8005AA04
    if (ctx->r3 != ctx->r4) {
        // 0x8005AA20: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8005AA04;
    }
    // 0x8005AA20: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8005AA24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AA28: lw          $a1, 0x11C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X11C);
    // 0x8005AA2C: lw          $a2, 0x120($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X120);
    // 0x8005AA30: jal         0x8005A6E4
    // 0x8005AA34: lw          $a3, 0x124($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X124);
    func_8005A6E4(rdram, ctx);
        goto after_0;
    // 0x8005AA34: lw          $a3, 0x124($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X124);
    after_0:
    // 0x8005AA38: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x8005AA3C: addiu       $a2, $a2, 0x5284
    ctx->r6 = ADD32(ctx->r6, 0X5284);
    // 0x8005AA40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005AA44: jal         0x8005A994
    // 0x8005AA48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_8005A994(rdram, ctx);
        goto after_1;
    // 0x8005AA48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8005AA4C: jal         0x8005A824
    // 0x8005AA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8005A824(rdram, ctx);
        goto after_2;
    // 0x8005AA50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005AA54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005AA58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005AA5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005AA60: jr          $ra
    // 0x8005AA64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005AA64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800250FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800250FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80025100: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80025104: jal         0x80024FF8
    // 0x80025108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80024FF8(rdram, ctx);
        goto after_0;
    // 0x80025108: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8002510C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025110: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025114: jr          $ra
    // 0x80025118: nop

    return;
    // 0x80025118: nop

;}
RECOMP_FUNC void func_804755A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804755A0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804755A4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804755A8: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804755AC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804755B0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804755B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804755B8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804755BC: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804755C0: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804755C4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804755C8: jr          $ra
    // 0x804755CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804755CC: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8000D574(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000D574: lui         $t6, 0x800B
    ctx->r14 = S32(0X800B << 16);
    // 0x8000D578: addiu       $t6, $t6, 0x4D10
    ctx->r14 = ADD32(ctx->r14, 0X4D10);
    // 0x8000D57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000D580: addiu       $t7, $t6, 0x4E50
    ctx->r15 = ADD32(ctx->r14, 0X4E50);
    // 0x8000D584: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000D588: beq         $a0, $t7, L_8000D6AC
    if (ctx->r4 == ctx->r15) {
        // 0x8000D58C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8000D6AC;
    }
    // 0x8000D58C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8000D590: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8000D594: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000D598: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000D59C: andi        $t0, $t8, 0xFF7F
    ctx->r8 = ctx->r24 & 0XFF7F;
    // 0x8000D5A0: andi        $t2, $t0, 0xBF
    ctx->r10 = ctx->r8 & 0XBF;
    // 0x8000D5A4: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x8000D5A8: andi        $t4, $t2, 0xDF
    ctx->r12 = ctx->r10 & 0XDF;
    // 0x8000D5AC: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x8000D5B0: andi        $t6, $t4, 0xF7
    ctx->r14 = ctx->r12 & 0XF7;
    // 0x8000D5B4: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x8000D5B8: andi        $t8, $t6, 0xFB
    ctx->r24 = ctx->r14 & 0XFB;
    // 0x8000D5BC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8000D5C0: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x8000D5C4: lui         $t5, 0x8009
    ctx->r13 = S32(0X8009 << 16);
    // 0x8000D5C8: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8000D5CC: andi        $t9, $t8, 0xFD
    ctx->r25 = ctx->r24 & 0XFD;
    // 0x8000D5D0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8000D5D4: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8000D5D8: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x8000D5DC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8000D5E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000D5E4: addiu       $t5, $t5, 0x6BF4
    ctx->r13 = ADD32(ctx->r13, 0X6BF4);
    // 0x8000D5E8: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8000D5EC: sh          $v0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r2;
    // 0x8000D5F0: sh          $v0, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r2;
    // 0x8000D5F4: sh          $zero, 0x26($a0)
    MEM_H(0X26, ctx->r4) = 0;
    // 0x8000D5F8: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x8000D5FC: sb          $zero, 0x9($a0)
    MEM_B(0X9, ctx->r4) = 0;
    // 0x8000D600: sb          $t0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r8;
    // 0x8000D604: sb          $zero, 0x80($a0)
    MEM_B(0X80, ctx->r4) = 0;
    // 0x8000D608: sb          $t1, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r9;
    // 0x8000D60C: sb          $t2, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r10;
    // 0x8000D610: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x8000D614: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x8000D618: sw          $zero, 0x40($a0)
    MEM_W(0X40, ctx->r4) = 0;
    // 0x8000D61C: sb          $zero, 0x8($a0)
    MEM_B(0X8, ctx->r4) = 0;
    // 0x8000D620: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    // 0x8000D624: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x8000D628: sb          $t3, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r11;
    // 0x8000D62C: sb          $t4, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r12;
    // 0x8000D630: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x8000D634: sw          $t5, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r13;
    // 0x8000D638: sb          $t6, 0x84($a0)
    MEM_B(0X84, ctx->r4) = ctx->r14;
    // 0x8000D63C: sb          $zero, 0x85($a0)
    MEM_B(0X85, ctx->r4) = 0;
    // 0x8000D640: sh          $zero, 0x16($a0)
    MEM_H(0X16, ctx->r4) = 0;
    // 0x8000D644: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x8000D648: sh          $zero, 0x18($a0)
    MEM_H(0X18, ctx->r4) = 0;
    // 0x8000D64C: sh          $zero, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = 0;
    // 0x8000D650: sh          $zero, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = 0;
    // 0x8000D654: sw          $zero, 0xD4($a0)
    MEM_W(0XD4, ctx->r4) = 0;
    // 0x8000D658: sh          $zero, 0x20($a0)
    MEM_H(0X20, ctx->r4) = 0;
    // 0x8000D65C: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x8000D660: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x8000D664: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8000D668: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x8000D66C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D670: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000D674: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8000D678: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_8000D67C:
    // 0x8000D67C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000D680: sb          $v0, 0xCD($v1)
    MEM_B(0XCD, ctx->r3) = ctx->r2;
    // 0x8000D684: sb          $v0, 0xCE($v1)
    MEM_B(0XCE, ctx->r3) = ctx->r2;
    // 0x8000D688: sb          $v0, 0xCF($v1)
    MEM_B(0XCF, ctx->r3) = ctx->r2;
    // 0x8000D68C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000D690: bne         $a0, $a2, L_8000D67C
    if (ctx->r4 != ctx->r6) {
        // 0x8000D694: sb          $v0, 0xC8($v1)
        MEM_B(0XC8, ctx->r3) = ctx->r2;
            goto L_8000D67C;
    }
    // 0x8000D694: sb          $v0, 0xC8($v1)
    MEM_B(0XC8, ctx->r3) = ctx->r2;
    // 0x8000D698: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x8000D69C: addiu       $a0, $a1, 0x8C
    ctx->r4 = ADD32(ctx->r5, 0X8C);
    // 0x8000D6A0: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x8000D6A4: jal         0x8000BDA0
    // 0x8000D6A8: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    func_8000BDA0(rdram, ctx);
        goto after_0;
    // 0x8000D6A8: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_0:
L_8000D6AC:
    // 0x8000D6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000D6B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000D6B4: jr          $ra
    // 0x8000D6B8: nop

    return;
    // 0x8000D6B8: nop

;}
RECOMP_FUNC void func_806CBA6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806CBA6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x806CBA70: addiu       $sp, $sp, -0x7B0
    ctx->r29 = ADD32(ctx->r29, -0X7B0);
    // 0x806CBA74: bne         $a1, $at, L_806CBA84
    if (ctx->r5 != ctx->r1) {
        // 0x806CBA78: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_806CBA84;
    }
    // 0x806CBA78: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x806CBA7C: b           L_806CBA88
    // 0x806CBA80: lw          $v1, 0x58C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58C);
        goto L_806CBA88;
    // 0x806CBA80: lw          $v1, 0x58C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58C);
L_806CBA84:
    // 0x806CBA84: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_806CBA88:
    // 0x806CBA88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x806CBA8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x806CBA90: lwc1        $f4, 0x858($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X858);
    // 0x806CBA94: lwc1        $f6, 0x854($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X854);
    // 0x806CBA98: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C0C) << 16);
    // 0x806CBA9C: mul.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x806CBAA0: lwc1        $f14, -0xCD4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C0C));
    // 0x806CBAA4: addiu       $a3, $sp, 0x5B4
    ctx->r7 = ADD32(ctx->r29, 0X5B4);
    // 0x806CBAA8: mul.s       $f2, $f6, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x806CBAAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x806CBAB0: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x806CBAB4: addiu       $t1, $sp, 0x3DC
    ctx->r9 = ADD32(ctx->r29, 0X3DC);
    // 0x806CBAB8: addiu       $t2, $sp, 0x204
    ctx->r10 = ADD32(ctx->r29, 0X204);
    // 0x806CBABC: addiu       $t3, $sp, 0x2C
    ctx->r11 = ADD32(ctx->r29, 0X2C);
    // 0x806CBAC0: addiu       $a0, $sp, 0x204
    ctx->r4 = ADD32(ctx->r29, 0X204);
    // 0x806CBAC4: lwc1        $f8, 0x67C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X67C);
    // 0x806CBAC8: lwc1        $f16, 0x590($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X590);
    // 0x806CBACC: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x806CBAD0: sltu        $at, $t3, $a0
    ctx->r1 = ctx->r11 < ctx->r4 ? 1 : 0;
    // 0x806CBAD4: beq         $at, $zero, L_806CBB5C
    if (ctx->r1 == 0) {
        // 0x806CBAD8: add.s       $f18, $f8, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_806CBB5C;
    }
    // 0x806CBAD8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
L_806CBADC:
    // 0x806CBADC: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806CBAE0: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x806CBAE4: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x806CBAE8: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x806CBAEC: sltu        $at, $t3, $a0
    ctx->r1 = ctx->r11 < ctx->r4 ? 1 : 0;
    // 0x806CBAF0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806CBAF4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x806CBAF8: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x806CBAFC: lwc1        $f16, 0x58C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X58C);
    // 0x806CBB00: lwc1        $f8, 0x680($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X680);
    // 0x806CBB04: lwc1        $f6, -0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X8);
    // 0x806CBB08: swc1        $f0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->f0.u32l;
    // 0x806CBB0C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x806CBB10: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806CBB14: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x806CBB18: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806CBB1C: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806CBB20: swc1        $f10, -0x10($t3)
    MEM_W(-0X10, ctx->r11) = ctx->f10.u32l;
    // 0x806CBB24: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x806CBB28: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806CBB2C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x806CBB30: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x806CBB34: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x806CBB38: swc1        $f8, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f8.u32l;
    // 0x806CBB3C: lwc1        $f8, -0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, -0X4);
    // 0x806CBB40: swc1        $f16, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->f16.u32l;
    // 0x806CBB44: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x806CBB48: swc1        $f8, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f8.u32l;
    // 0x806CBB4C: lwc1        $f8, 0x67C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X67C);
    // 0x806CBB50: lwc1        $f16, 0x590($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X590);
    // 0x806CBB54: bne         $at, $zero, L_806CBADC
    if (ctx->r1 != 0) {
        // 0x806CBB58: add.s       $f18, $f8, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
            goto L_806CBADC;
    }
    // 0x806CBB58: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
L_806CBB5C:
    // 0x806CBB5C: mul.s       $f16, $f18, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x806CBB60: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x806CBB64: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x806CBB68: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x806CBB6C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x806CBB70: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x806CBB74: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x806CBB78: swc1        $f16, -0x8($a3)
    MEM_W(-0X8, ctx->r7) = ctx->f16.u32l;
    // 0x806CBB7C: lwc1        $f8, 0x678($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X678);
    // 0x806CBB80: lwc1        $f16, 0x58C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X58C);
    // 0x806CBB84: lwc1        $f6, -0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X8);
    // 0x806CBB88: swc1        $f0, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f0.u32l;
    // 0x806CBB8C: sub.s       $f8, $f16, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x806CBB90: mul.s       $f6, $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x806CBB94: lwc1        $f16, -0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, -0X4);
    // 0x806CBB98: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x806CBB9C: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x806CBBA0: swc1        $f10, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->f10.u32l;
    // 0x806CBBA4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x806CBBA8: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x806CBBAC: swc1        $f6, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f6.u32l;
    // 0x806CBBB0: swc1        $f8, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f8.u32l;
    // 0x806CBBB4: lwc1        $f8, -0x4($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, -0X4);
    // 0x806CBBB8: swc1        $f16, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->f16.u32l;
    // 0x806CBBBC: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x806CBBC0: swc1        $f8, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f8.u32l;
    // 0x806CBBC4: lwc1        $f18, 0x5B4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5B4);
    // 0x806CBBC8: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x806CBBCC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x806CBBD0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806CBBD4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x806CBBD8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x806CBBDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x806CBBE0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x806CBBE4: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x806CBBE8: addiu       $a1, $a0, 0x2C4
    ctx->r5 = ADD32(ctx->r4, 0X2C4);
    // 0x806CBBEC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x806CBBF0: lwc1        $f6, 0x3DC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3DC);
    // 0x806CBBF4: lui         $at, 0x806D
    ctx->r1 = S32(RELOC_HI16(604, 0X3C10) << 16);
    // 0x806CBBF8: addiu       $t0, $a0, 0x4
    ctx->r8 = ADD32(ctx->r4, 0X4);
    // 0x806CBBFC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806CBC00: addiu       $t4, $a1, 0x4
    ctx->r12 = ADD32(ctx->r5, 0X4);
    // 0x806CBC04: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x806CBC08: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x806CBC0C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x806CBC10: addiu       $a3, $sp, 0x5C4
    ctx->r7 = ADD32(ctx->r29, 0X5C4);
    // 0x806CBC14: addiu       $t1, $sp, 0x3EC
    ctx->r9 = ADD32(ctx->r29, 0X3EC);
    // 0x806CBC18: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x806CBC1C: lwc1        $f10, 0x5B8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5B8);
    // 0x806CBC20: addiu       $t2, $sp, 0x214
    ctx->r10 = ADD32(ctx->r29, 0X214);
    // 0x806CBC24: addiu       $t3, $sp, 0x3C
    ctx->r11 = ADD32(ctx->r29, 0X3C);
    // 0x806CBC28: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBC2C: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x806CBC30: nop

    // 0x806CBC34: sh          $t7, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r15;
    // 0x806CBC38: lwc1        $f18, 0x3E0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3E0);
    // 0x806CBC3C: addiu       $a0, $sp, 0x1FC
    ctx->r4 = ADD32(ctx->r29, 0X1FC);
    // 0x806CBC40: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x806CBC44: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x806CBC48: nop

    // 0x806CBC4C: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x806CBC50: lwc1        $f6, 0x5BC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5BC);
    // 0x806CBC54: lwc1        $f0, -0xCD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(604, 0X3C10));
    // 0x806CBC58: lwc1        $f10, 0x204($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X204);
    // 0x806CBC5C: lwc1        $f18, 0x214($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X214);
    // 0x806CBC60: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x806CBC64: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x806CBC68: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x806CBC6C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806CBC70: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x806CBC74: nop

    // 0x806CBC78: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x806CBC7C: lwc1        $f8, 0x3E4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3E4);
    // 0x806CBC80: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x806CBC84: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x806CBC88: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x806CBC8C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x806CBC90: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x806CBC94: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806CBC98: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x806CBC9C: nop

    // 0x806CBCA0: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
    // 0x806CBCA4: lwc1        $f10, 0x5C0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C0);
    // 0x806CBCA8: lwc1        $f4, 0x208($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X208);
    // 0x806CBCAC: lwc1        $f6, 0x218($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X218);
    // 0x806CBCB0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CBCB4: add.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x806CBCB8: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x806CBCBC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x806CBCC0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x806CBCC4: nop

    // 0x806CBCC8: sh          $t5, 0x2($t0)
    MEM_H(0X2, ctx->r8) = ctx->r13;
    // 0x806CBCCC: lwc1        $f18, 0x3E8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3E8);
    // 0x806CBCD0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x806CBCD4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x806CBCD8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x806CBCDC: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x806CBCE0: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x806CBCE4: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBCE8: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x806CBCEC: nop

    // 0x806CBCF0: sh          $t7, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r15;
    // 0x806CBCF4: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806CBCF8: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x806CBCFC: lwc1        $f16, -0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, -0X8);
    // 0x806CBD00: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBD04: beql        $t3, $a0, L_806CBE70
    if (ctx->r11 == ctx->r4) {
        // 0x806CBD08: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_806CBE70;
    }
    goto skip_0;
    // 0x806CBD08: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_0:
    // 0x806CBD0C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_806CBD10:
    // 0x806CBD10: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    // 0x806CBD14: addiu       $t3, $t3, 0x10
    ctx->r11 = ADD32(ctx->r11, 0X10);
    // 0x806CBD18: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x806CBD1C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBD20: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x806CBD24: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x806CBD28: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806CBD2C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBD30: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x806CBD34: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x806CBD38: nop

    // 0x806CBD3C: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x806CBD40: lwc1        $f14, -0x10($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, -0X10);
    // 0x806CBD44: lwc1        $f12, -0x28($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0X28);
    // 0x806CBD48: lwc1        $f10, -0x18($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, -0X18);
    // 0x806CBD4C: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBD50: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBD54: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBD58: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBD5C: mfc1        $t6, $f12
    ctx->r14 = (int32_t)ctx->f12.u32l;
    // 0x806CBD60: nop

    // 0x806CBD64: sh          $t6, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r14;
    // 0x806CBD68: lwc1        $f12, -0xC($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, -0XC);
    // 0x806CBD6C: lwc1        $f10, -0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, -0X14);
    // 0x806CBD70: lwc1        $f14, -0x4($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, -0X4);
    // 0x806CBD74: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBD78: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x806CBD7C: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x806CBD80: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBD84: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x806CBD88: nop

    // 0x806CBD8C: sh          $t8, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r24;
    // 0x806CBD90: lwc1        $f10, -0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0XC);
    // 0x806CBD94: lwc1        $f14, -0x24($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, -0X24);
    // 0x806CBD98: lwc1        $f12, -0x14($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0X14);
    // 0x806CBD9C: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CBDA0: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806CBDA4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBDA8: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBDAC: mfc1        $t5, $f14
    ctx->r13 = (int32_t)ctx->f14.u32l;
    // 0x806CBDB0: nop

    // 0x806CBDB4: sh          $t5, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r13;
    // 0x806CBDB8: lwc1        $f14, -0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, -0X8);
    // 0x806CBDBC: lwc1        $f12, -0x10($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, -0X10);
    // 0x806CBDC0: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806CBDC4: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBDC8: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBDCC: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBDD0: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBDD4: mfc1        $t7, $f12
    ctx->r15 = (int32_t)ctx->f12.u32l;
    // 0x806CBDD8: nop

    // 0x806CBDDC: sh          $t7, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r15;
    // 0x806CBDE0: lwc1        $f12, -0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, -0X8);
    // 0x806CBDE4: lwc1        $f10, -0x20($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, -0X20);
    // 0x806CBDE8: lwc1        $f14, -0x10($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, -0X10);
    // 0x806CBDEC: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBDF0: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x806CBDF4: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x806CBDF8: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBDFC: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x806CBE00: nop

    // 0x806CBE04: sh          $t9, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r25;
    // 0x806CBE08: lwc1        $f10, -0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, -0X4);
    // 0x806CBE0C: lwc1        $f14, -0xC($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, -0XC);
    // 0x806CBE10: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x806CBE14: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CBE18: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806CBE1C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBE20: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBE24: mfc1        $t6, $f14
    ctx->r14 = (int32_t)ctx->f14.u32l;
    // 0x806CBE28: nop

    // 0x806CBE2C: sh          $t6, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r14;
    // 0x806CBE30: lwc1        $f14, -0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, -0X4);
    // 0x806CBE34: lwc1        $f12, -0x1C($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0X1C);
    // 0x806CBE38: lwc1        $f10, -0xC($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, -0XC);
    // 0x806CBE3C: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBE40: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBE44: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBE48: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBE4C: mfc1        $t8, $f12
    ctx->r24 = (int32_t)ctx->f12.u32l;
    // 0x806CBE50: nop

    // 0x806CBE54: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x806CBE58: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806CBE5C: lwc1        $f16, -0x8($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, -0X8);
    // 0x806CBE60: mul.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBE64: bnel        $t3, $a0, L_806CBD10
    if (ctx->r11 != ctx->r4) {
        // 0x806CBE68: add.s       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
            goto L_806CBD10;
    }
    goto skip_1;
    // 0x806CBE68: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
    skip_1:
    // 0x806CBE6C: add.s       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f16.fl;
L_806CBE70:
    // 0x806CBE70: lwc1        $f12, 0x8($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X8);
    // 0x806CBE74: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x806CBE78: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x806CBE7C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBE80: addiu       $t1, $t1, 0x10
    ctx->r9 = ADD32(ctx->r9, 0X10);
    // 0x806CBE84: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x806CBE88: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x806CBE8C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBE90: mfc1        $t9, $f14
    ctx->r25 = (int32_t)ctx->f14.u32l;
    // 0x806CBE94: nop

    // 0x806CBE98: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x806CBE9C: lwc1        $f14, -0x10($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, -0X10);
    // 0x806CBEA0: lwc1        $f12, -0x18($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0X18);
    // 0x806CBEA4: lwc1        $f10, -0x8($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, -0X8);
    // 0x806CBEA8: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBEAC: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBEB0: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBEB4: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBEB8: mfc1        $t6, $f12
    ctx->r14 = (int32_t)ctx->f12.u32l;
    // 0x806CBEBC: nop

    // 0x806CBEC0: sh          $t6, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r14;
    // 0x806CBEC4: lwc1        $f12, -0xC($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, -0XC);
    // 0x806CBEC8: lwc1        $f10, -0x14($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, -0X14);
    // 0x806CBECC: lwc1        $f14, -0x4($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, -0X4);
    // 0x806CBED0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBED4: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x806CBED8: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x806CBEDC: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBEE0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x806CBEE4: nop

    // 0x806CBEE8: sh          $t8, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r24;
    // 0x806CBEEC: lwc1        $f10, -0xC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, -0XC);
    // 0x806CBEF0: lwc1        $f14, -0x14($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, -0X14);
    // 0x806CBEF4: lwc1        $f12, -0x4($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0X4);
    // 0x806CBEF8: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CBEFC: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806CBF00: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBF04: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBF08: mfc1        $t5, $f14
    ctx->r13 = (int32_t)ctx->f14.u32l;
    // 0x806CBF0C: nop

    // 0x806CBF10: sh          $t5, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r13;
    // 0x806CBF14: lwc1        $f14, -0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, -0X8);
    // 0x806CBF18: lwc1        $f12, -0x10($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, -0X10);
    // 0x806CBF1C: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x806CBF20: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBF24: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBF28: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBF2C: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBF30: mfc1        $t7, $f12
    ctx->r15 = (int32_t)ctx->f12.u32l;
    // 0x806CBF34: nop

    // 0x806CBF38: sh          $t7, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r15;
    // 0x806CBF3C: lwc1        $f12, -0x8($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, -0X8);
    // 0x806CBF40: lwc1        $f10, -0x10($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, -0X10);
    // 0x806CBF44: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    // 0x806CBF48: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x806CBF4C: add.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x806CBF50: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x806CBF54: trunc.w.s   $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBF58: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x806CBF5C: nop

    // 0x806CBF60: sh          $t9, -0x4($v1)
    MEM_H(-0X4, ctx->r3) = ctx->r25;
    // 0x806CBF64: lwc1        $f10, -0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, -0X4);
    // 0x806CBF68: lwc1        $f14, -0xC($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, -0XC);
    // 0x806CBF6C: lwc1        $f12, 0x4($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X4);
    // 0x806CBF70: mul.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x806CBF74: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x806CBF78: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x806CBF7C: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x806CBF80: mfc1        $t6, $f14
    ctx->r14 = (int32_t)ctx->f14.u32l;
    // 0x806CBF84: nop

    // 0x806CBF88: sh          $t6, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r14;
    // 0x806CBF8C: lwc1        $f14, -0x4($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, -0X4);
    // 0x806CBF90: lwc1        $f12, -0xC($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, -0XC);
    // 0x806CBF94: lwc1        $f10, 0x4($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X4);
    // 0x806CBF98: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x806CBF9C: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x806CBFA0: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x806CBFA4: trunc.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x806CBFA8: mfc1        $t8, $f12
    ctx->r24 = (int32_t)ctx->f12.u32l;
    // 0x806CBFAC: nop

    // 0x806CBFB0: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
    // 0x806CBFB4: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x806CBFB8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBFBC: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x806CBFC0: nop

    // 0x806CBFC4: sh          $t5, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r13;
    // 0x806CBFC8: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x806CBFCC: trunc.w.s   $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x806CBFD0: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x806CBFD4: nop

    // 0x806CBFD8: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x806CBFDC: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x806CBFE0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x806CBFE4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x806CBFE8: nop

    // 0x806CBFEC: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x806CBFF0: lwc1        $f10, 0x4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X4);
    // 0x806CBFF4: addiu       $sp, $sp, 0x7B0
    ctx->r29 = ADD32(ctx->r29, 0X7B0);
    // 0x806CBFF8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x806CBFFC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x806CC000: jr          $ra
    // 0x806CC004: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    return;
    // 0x806CC004: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void func_8067FF44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067FF44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8067FF48: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8067FF4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8067FF50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8067FF54: jal         0x80045A34
    // 0x8067FF58: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x8067FF58: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_0:
    // 0x8067FF5C: bne         $v0, $zero, L_8067FF74
    if (ctx->r2 != 0) {
        // 0x8067FF60: sw          $v0, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r2;
            goto L_8067FF74;
    }
    // 0x8067FF60: sw          $v0, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r2;
    // 0x8067FF64: jal         0x800445A4
    // 0x8067FF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8067FF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8067FF6C: b           L_806800EC
    // 0x8067FF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_806800EC;
    // 0x8067FF70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8067FF74:
    // 0x8067FF74: lw          $t7, 0x16C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X16C);
    // 0x8067FF78: lui         $t6, 0x8068
    ctx->r14 = S32(RELOC_HI16(547, 0X10A8) << 16);
    // 0x8067FF7C: sb          $zero, 0x165($s0)
    MEM_B(0X165, ctx->r16) = 0;
    // 0x8067FF80: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x8067FF84: addiu       $t6, $t6, 0x298
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(547, 0X10A8));
    // 0x8067FF88: lui         $t9, 0x8005
    ctx->r25 = S32(0X8005 << 16);
    // 0x8067FF8C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8067FF90: addiu       $t9, $t9, -0x7C48
    ctx->r25 = ADD32(ctx->r25, -0X7C48);
    // 0x8067FF94: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8067FF98: sw          $t8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->r24;
    // 0x8067FF9C: sw          $t9, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->r25;
    // 0x8067FFA0: jal         0x8067F6A8
    // 0x8067FFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_8067F6A8(rdram, ctx);
        goto after_2;
    // 0x8067FFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8067FFA8: lw          $t1, 0x16C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X16C);
    // 0x8067FFAC: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(547, 0X10) << 16);
    // 0x8067FFB0: addiu       $t0, $t0, -0xE00
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(547, 0X10));
    // 0x8067FFB4: lui         $t2, 0x8068
    ctx->r10 = S32(RELOC_HI16(547, 0X484) << 16);
    // 0x8067FFB8: sw          $t0, 0x34($t1)
    MEM_W(0X34, ctx->r9) = ctx->r8;
    // 0x8067FFBC: addiu       $t2, $t2, -0x98C
    ctx->r10 = ADD32(ctx->r10, (int16_t)RELOC_LO16(547, 0X484));
    // 0x8067FFC0: sw          $t2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r10;
    // 0x8067FFC4: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x8067FFC8: jal         0x80067BBC
    // 0x8067FFCC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_80067BBC(rdram, ctx);
        goto after_3;
    // 0x8067FFCC: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8067FFD0: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    // 0x8067FFD4: jal         0x80067F78
    // 0x8067FFD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_4;
    // 0x8067FFD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8067FFDC: lui         $at, 0x8068
    ctx->r1 = S32(RELOC_HI16(547, 0X1100) << 16);
    // 0x8067FFE0: lwc1        $f2, 0x2F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(547, 0X1100));
    // 0x8067FFE4: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x8067FFE8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x8067FFEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8067FFF0: addiu       $t3, $zero, 0x1F4
    ctx->r11 = ADD32(0, 0X1F4);
    // 0x8067FFF4: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    // 0x8067FFF8: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8067FFFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80680000: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80680004: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
    // 0x80680008: swc1        $f0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f0.u32l;
    // 0x8068000C: lui         $t4, 0x8068
    ctx->r12 = S32(RELOC_HI16(547, 0X1050) << 16);
    // 0x80680010: addiu       $t4, $t4, 0x240
    ctx->r12 = ADD32(ctx->r12, (int16_t)RELOC_LO16(547, 0X1050));
    // 0x80680014: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x80680018: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x8068001C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80680020: lui         $t7, 0x8068
    ctx->r15 = S32(RELOC_HI16(547, 0X1060) << 16);
    // 0x80680024: addiu       $t7, $t7, 0x250
    ctx->r15 = ADD32(ctx->r15, (int16_t)RELOC_LO16(547, 0X1060));
    // 0x80680028: sw          $t6, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r14;
    // 0x8068002C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80680030: lui         $t0, 0x8068
    ctx->r8 = S32(RELOC_HI16(547, 0X1070) << 16);
    // 0x80680034: addiu       $t0, $t0, 0x260
    ctx->r8 = ADD32(ctx->r8, (int16_t)RELOC_LO16(547, 0X1070));
    // 0x80680038: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
    // 0x8068003C: lw          $t6, 0x8($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X8);
    // 0x80680040: lui         $t3, 0x8068
    ctx->r11 = S32(RELOC_HI16(547, 0X1080) << 16);
    // 0x80680044: addiu       $t3, $t3, 0x270
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(547, 0X1080));
    // 0x80680048: sw          $t6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r14;
    // 0x8068004C: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80680050: sb          $zero, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = 0;
    // 0x80680054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80680058: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x8068005C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80680060: sw          $t9, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r25;
    // 0x80680064: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80680068: sw          $t8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r24;
    // 0x8068006C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80680070: sw          $t9, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->r25;
    // 0x80680074: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80680078: sb          $zero, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = 0;
    // 0x8068007C: sw          $t8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r24;
    // 0x80680080: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80680084: sw          $t2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r10;
    // 0x80680088: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8068008C: sw          $t1, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->r9;
    // 0x80680090: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80680094: sw          $t2, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r10;
    // 0x80680098: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x8068009C: sb          $zero, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = 0;
    // 0x806800A0: sw          $t1, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r9;
    // 0x806800A4: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x806800A8: sw          $t5, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->r13;
    // 0x806800AC: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x806800B0: sw          $t4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r12;
    // 0x806800B4: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x806800B8: sw          $t5, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r13;
    // 0x806800BC: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x806800C0: sb          $zero, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = 0;
    // 0x806800C4: jal         0x8005FD1C
    // 0x806800C8: sw          $t4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r12;
    func_8005FD1C(rdram, ctx);
        goto after_5;
    // 0x806800C8: sw          $t4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r12;
    after_5:
    // 0x806800CC: lw          $t6, 0x174($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X174);
    // 0x806800D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x806800D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x806800D8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x806800DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x806800E0: jal         0x80680194
    // 0x806800E4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    func_80680194(rdram, ctx);
        goto after_6;
    // 0x806800E4: sh          $zero, 0x12($t7)
    MEM_H(0X12, ctx->r15) = 0;
    after_6:
    // 0x806800E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_806800EC:
    // 0x806800EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x806800F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x806800F4: jr          $ra
    // 0x806800F8: nop

    return;
    // 0x806800F8: nop

;}
RECOMP_FUNC void func_8001C7B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C7B8: lui         $v1, 0x8010
    ctx->r3 = S32(0X8010 << 16);
    // 0x8001C7BC: lw          $v1, -0x76BC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X76BC);
    // 0x8001C7C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001C7C4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001C7C8: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8001C7CC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8001C7D0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001C7D4: lwc1        $f2, -0x69A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X69A0);
    // 0x8001C7D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8001C7DC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8001C7E0: lwc1        $f4, -0x69A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X69A8);
    // 0x8001C7E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C7E8: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x8001C7EC: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8001C7F0: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x8001C7F4: lw          $t7, 0x1E0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1E0);
    // 0x8001C7F8: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8001C7FC: lw          $a2, 0x1F4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X1F4);
    // 0x8001C800: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8001C804: lbu         $a3, 0x28($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X28);
    // 0x8001C808: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001C80C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x8001C810: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8001C814: jal         0x8001C748
    // 0x8001C818: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    func_8001C748(rdram, ctx);
        goto after_0;
    // 0x8001C818: sb          $a3, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001C81C: lbu         $a3, 0x1F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X1F);
    // 0x8001C820: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001C824: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001C828: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C82C: beq         $a3, $at, L_8001C844
    if (ctx->r7 == ctx->r1) {
        // 0x8001C830: lwc1        $f2, 0x2C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8001C844;
    }
    // 0x8001C830: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001C834: jal         0x8001CBB8
    // 0x8001C838: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    func_8001CBB8(rdram, ctx);
        goto after_1;
    // 0x8001C838: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_1:
    // 0x8001C83C: b           L_8001C880
    // 0x8001C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001C880;
    // 0x8001C840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001C844:
    // 0x8001C844: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001C848: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001C84C: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8001C850: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8001C854: nop

    // 0x8001C858: bc1fl       L_8001C878
    if (!c1cs) {
        // 0x8001C85C: swc1        $f0, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
            goto L_8001C878;
    }
    goto skip_0;
    // 0x8001C85C: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    skip_0:
    // 0x8001C860: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8001C864: jal         0x8001CBB8
    // 0x8001C868: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    func_8001CBB8(rdram, ctx);
        goto after_2;
    // 0x8001C868: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8001C86C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8001C870: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001C874: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
L_8001C878:
    // 0x8001C878: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8001C87C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001C880:
    // 0x8001C880: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8001C884: jr          $ra
    // 0x8001C888: nop

    return;
    // 0x8001C888: nop

;}
RECOMP_FUNC void func_8078B528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8078B528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8078B52C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8078B530: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8078B534: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8078B538: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    // 0x8078B53C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8078B540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8078B544: jal         0x80065728
    // 0x8078B548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80065728(rdram, ctx);
        goto after_0;
    // 0x8078B548: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8078B54C: jal         0x80066DE4
    // 0x8078B550: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    func_80066DE4(rdram, ctx);
        goto after_1;
    // 0x8078B550: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    after_1:
    // 0x8078B554: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8078B558: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8078B55C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8078B560: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8078B564: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8078B568: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8078B56C: sub.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x8078B570: add.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8078B574: swc1        $f6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f6.u32l;
    // 0x8078B578: swc1        $f8, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f8.u32l;
    // 0x8078B57C: jal         0x80066DE4
    // 0x8078B580: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x8078B580: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    after_2:
    // 0x8078B584: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8078B588: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8078B58C: nop

    // 0x8078B590: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8078B594: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8078B598: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8078B59C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8078B5A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8078B5A4: jr          $ra
    // 0x8078B5A8: nop

    return;
    // 0x8078B5A8: nop

;}
RECOMP_FUNC void func_80075328(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007532C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075330: jal         0x80081A0C
    // 0x80075334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    StackCheck_Check(rdram, ctx);
        goto after_0;
    // 0x80075334: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80075338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007533C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80075340: jr          $ra
    // 0x80075344: nop

    return;
    // 0x80075344: nop

;}
RECOMP_FUNC void func_8006D2E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D2E0: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x8006D2E4: lw          $t6, -0x7BA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7BA4);
    // 0x8006D2E8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8006D2EC: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8006D2F0: beq         $t6, $zero, L_8006D2FC
    if (ctx->r14 == 0) {
        // 0x8006D2F4: lui         $t8, 0x8010
        ctx->r24 = S32(0X8010 << 16);
            goto L_8006D2FC;
    }
    // 0x8006D2F4: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x8006D2F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006D2FC:
    // 0x8006D2FC: lw          $t7, -0x7BA0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7BA0);
    // 0x8006D300: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8006D304: beq         $t7, $zero, L_8006D310
    if (ctx->r15 == 0) {
        // 0x8006D308: nop
    
            goto L_8006D310;
    }
    // 0x8006D308: nop

    // 0x8006D30C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8006D310:
    // 0x8006D310: lw          $t8, -0x7B9C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7B9C);
    // 0x8006D314: beq         $t8, $zero, L_8006D320
    if (ctx->r24 == 0) {
        // 0x8006D318: nop
    
            goto L_8006D320;
    }
    // 0x8006D318: nop

    // 0x8006D31C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8006D320:
    // 0x8006D320: lw          $t9, -0x7B98($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7B98);
    // 0x8006D324: beq         $t9, $zero, L_8006D330
    if (ctx->r25 == 0) {
        // 0x8006D328: nop
    
            goto L_8006D330;
    }
    // 0x8006D328: nop

    // 0x8006D32C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_8006D330:
    // 0x8006D330: jr          $ra
    // 0x8006D334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006D334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006D338: nop

    // 0x8006D33C: nop

;}
RECOMP_FUNC void func_8001C01C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C01C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001C020: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001C024: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8001C028: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001C02C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001C030: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001C034: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001C038: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001C03C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001C040: slti        $at, $a1, 0x7
    ctx->r1 = SIGNED(ctx->r5) < 0X7 ? 1 : 0;
    // 0x8001C044: beq         $at, $zero, L_8001C08C
    if (ctx->r1 == 0) {
        // 0x8001C048: lw          $s3, 0x16C($a0)
        ctx->r19 = MEM_W(ctx->r4, 0X16C);
            goto L_8001C08C;
    }
    // 0x8001C048: lw          $s3, 0x16C($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X16C);
    // 0x8001C04C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8001C050: addiu       $t7, $t7, -0x6A04
    ctx->r15 = ADD32(ctx->r15, -0X6A04);
    // 0x8001C054: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8001C058: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8001C05C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C060: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001C064: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_8001C068:
    // 0x8001C068: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001C06C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001C070: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8001C074: jal         0x8001BE40
    // 0x8001C078: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    func_8001BE40(rdram, ctx);
        goto after_0;
    // 0x8001C078: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    after_0:
    // 0x8001C07C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001C080: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001C084: bne         $s2, $s4, L_8001C068
    if (ctx->r18 != ctx->r20) {
        // 0x8001C088: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8001C068;
    }
    // 0x8001C088: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8001C08C:
    // 0x8001C08C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C090: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C094: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C098: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C09C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001C0A0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001C0A4: jr          $ra
    // 0x8001C0A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001C0A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8002611C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002611C: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x80026120: sw          $zero, 0x154($a0)
    MEM_W(0X154, ctx->r4) = 0;
    // 0x80026124: sw          $zero, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = 0;
    // 0x80026128: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8002612C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80026130: lwc1        $f6, 0x174($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X174);
    // 0x80026134: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80026138: lui         $t1, 0x8002
    ctx->r9 = S32(0X8002 << 16);
    // 0x8002613C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80026140: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80026144: addiu       $t1, $t1, 0x5EA4
    ctx->r9 = ADD32(ctx->r9, 0X5EA4);
    // 0x80026148: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002614C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80026150: nop

    // 0x80026154: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80026158: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002615C: nop

    // 0x80026160: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80026164: beql        $t8, $zero, L_800261B4
    if (ctx->r24 == 0) {
        // 0x80026168: mfc1        $t8, $f10
        ctx->r24 = (int32_t)ctx->f10.u32l;
            goto L_800261B4;
    }
    goto skip_0;
    // 0x80026168: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x8002616C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80026170: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80026174: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80026178: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002617C: nop

    // 0x80026180: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80026184: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80026188: nop

    // 0x8002618C: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80026190: bne         $t8, $zero, L_800261A8
    if (ctx->r24 != 0) {
        // 0x80026194: nop
    
            goto L_800261A8;
    }
    // 0x80026194: nop

    // 0x80026198: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8002619C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800261A0: b           L_800261C0
    // 0x800261A4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800261C0;
    // 0x800261A4: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800261A8:
    // 0x800261A8: b           L_800261C0
    // 0x800261AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800261C0;
    // 0x800261AC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800261B0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
L_800261B4:
    // 0x800261B4: nop

    // 0x800261B8: bltz        $t8, L_800261A8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800261BC: nop
    
            goto L_800261A8;
    }
    // 0x800261BC: nop

L_800261C0:
    // 0x800261C0: addiu       $t9, $t8, 0x5
    ctx->r25 = ADD32(ctx->r24, 0X5);
    // 0x800261C4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800261C8: divu        $zero, $t9, $at
    lo = S32(U32(ctx->r25) / U32(ctx->r1)); hi = S32(U32(ctx->r25) % U32(ctx->r1));
    // 0x800261CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800261D0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800261D4: sw          $t0, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r8;
    // 0x800261D8: jr          $ra
    // 0x800261DC: sw          $t1, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r9;
    return;
    // 0x800261DC: sw          $t1, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_807AE95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807AE95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807AE960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807AE964: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x807AE968: jal         0x80045A34
    // 0x807AE96C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x807AE96C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x807AE970: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x807AE974: bne         $v0, $zero, L_807AE984
    if (ctx->r2 != 0) {
        // 0x807AE978: sw          $v0, 0x1F4($a0)
        MEM_W(0X1F4, ctx->r4) = ctx->r2;
            goto L_807AE984;
    }
    // 0x807AE978: sw          $v0, 0x1F4($a0)
    MEM_W(0X1F4, ctx->r4) = ctx->r2;
    // 0x807AE97C: b           L_807AE990
    // 0x807AE980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807AE990;
    // 0x807AE980: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807AE984:
    // 0x807AE984: jal         0x807AE930
    // 0x807AE988: nop

    func_807AE930(rdram, ctx);
        goto after_1;
    // 0x807AE988: nop

    after_1:
    // 0x807AE98C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807AE990:
    // 0x807AE990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x807AE994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807AE998: jr          $ra
    // 0x807AE99C: nop

    return;
    // 0x807AE99C: nop

;}
RECOMP_FUNC void func_80792CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80792CB0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80792CB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80792CB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80792CBC: lw          $v0, 0x174($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X174);
    // 0x80792CC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80792CC4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x80792CC8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80792CCC: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80792CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792CD4: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x80792CD8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80792CDC: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x80792CE0: lbu         $t8, 0x44($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X44);
    // 0x80792CE4: beql        $t8, $zero, L_80792D2C
    if (ctx->r24 == 0) {
        // 0x80792CE8: lw          $t2, 0x2C($v1)
        ctx->r10 = MEM_W(ctx->r3, 0X2C);
            goto L_80792D2C;
    }
    goto skip_0;
    // 0x80792CE8: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
    skip_0:
    // 0x80792CEC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    // 0x80792CF0: jal         0x8079393C
    // 0x80792CF4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_8079393C(rdram, ctx);
        goto after_0;
    // 0x80792CF4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x80792CF8: lui         $at, 0xC100
    ctx->r1 = S32(0XC100 << 16);
    // 0x80792CFC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80792D00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80792D04: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80792D08: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x80792D0C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x80792D10: lw          $t9, -0x7290($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7290);
    // 0x80792D14: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B00) << 16);
    // 0x80792D18: sw          $zero, 0x24($t9)
    MEM_W(0X24, ctx->r25) = 0;
    // 0x80792D1C: lwc1        $f6, 0x7E50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B00));
    // 0x80792D20: b           L_80792F24
    // 0x80792D24: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
        goto L_80792F24;
    // 0x80792D24: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80792D28: lw          $t2, 0x2C($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2C);
L_80792D2C:
    // 0x80792D2C: lw          $t1, -0x7290($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7290);
    // 0x80792D30: lw          $t5, 0x30($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X30);
    // 0x80792D34: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80792D38: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x80792D3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80792D40: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80792D44: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80792D48: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80792D4C: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x80792D50: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80792D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792D58: jal         0x80790714
    // 0x80792D5C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_80790714(rdram, ctx);
        goto after_1;
    // 0x80792D5C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x80792D60: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80792D64: beq         $v0, $zero, L_80792DB0
    if (ctx->r2 == 0) {
        // 0x80792D68: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80792DB0;
    }
    // 0x80792D68: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80792D6C: lh          $t8, 0x36($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X36);
    // 0x80792D70: slti        $at, $t0, 0x5A
    ctx->r1 = SIGNED(ctx->r8) < 0X5A ? 1 : 0;
    // 0x80792D74: bnel        $t8, $zero, L_80792DB4
    if (ctx->r24 != 0) {
        // 0x80792D78: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80792DB4;
    }
    goto skip_1;
    // 0x80792D78: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    skip_1:
    // 0x80792D7C: beq         $at, $zero, L_80792DB0
    if (ctx->r1 == 0) {
        // 0x80792D80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80792DB0;
    }
    // 0x80792D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792D84: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x80792D88: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x80792D8C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80792D90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792D94: jal         0x8079393C
    // 0x80792D98: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    func_8079393C(rdram, ctx);
        goto after_2;
    // 0x80792D98: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_2:
    // 0x80792D9C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80792DA0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80792DA4: sw          $zero, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = 0;
    // 0x80792DA8: lh          $t9, 0x38($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X38);
    // 0x80792DAC: sh          $t9, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r25;
L_80792DB0:
    // 0x80792DB0: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
L_80792DB4:
    // 0x80792DB4: bne         $t0, $at, L_80792DCC
    if (ctx->r8 != ctx->r1) {
        // 0x80792DB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80792DCC;
    }
    // 0x80792DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792DBC: lh          $v0, 0x36($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X36);
    // 0x80792DC0: blez        $v0, L_80792DCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80792DC4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80792DCC;
    }
    // 0x80792DC4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80792DC8: sh          $t2, 0x36($v1)
    MEM_H(0X36, ctx->r3) = ctx->r10;
L_80792DCC:
    // 0x80792DCC: slti        $at, $t0, 0x6F
    ctx->r1 = SIGNED(ctx->r8) < 0X6F ? 1 : 0;
    // 0x80792DD0: bne         $at, $zero, L_80792F24
    if (ctx->r1 != 0) {
        // 0x80792DD4: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_80792F24;
    }
    // 0x80792DD4: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80792DD8: lw          $t1, 0x2C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X2C);
    // 0x80792DDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80792DE0: beq         $t1, $zero, L_80792DF0
    if (ctx->r9 == 0) {
        // 0x80792DE4: nop
    
            goto L_80792DF0;
    }
    // 0x80792DE4: nop

    // 0x80792DE8: b           L_80792DF0
    // 0x80792DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80792DF0;
    // 0x80792DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80792DF0:
    // 0x80792DF0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80792DF4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80792DF8: jal         0x807925B0
    // 0x80792DFC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    func_807925B0(rdram, ctx);
        goto after_3;
    // 0x80792DFC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x80792E00: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80792E04: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80792E08: beq         $v0, $zero, L_80792F24
    if (ctx->r2 == 0) {
        // 0x80792E0C: lw          $t0, 0x38($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X38);
            goto L_80792F24;
    }
    // 0x80792E0C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80792E10: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x80792E14: beq         $t3, $zero, L_80792E38
    if (ctx->r11 == 0) {
        // 0x80792E18: slti        $at, $t0, 0x8C
        ctx->r1 = SIGNED(ctx->r8) < 0X8C ? 1 : 0;
            goto L_80792E38;
    }
    // 0x80792E18: slti        $at, $t0, 0x8C
    ctx->r1 = SIGNED(ctx->r8) < 0X8C ? 1 : 0;
    // 0x80792E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792E20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792E24: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80792E28: jal         0x8079393C
    // 0x80792E2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    func_8079393C(rdram, ctx);
        goto after_4;
    // 0x80792E2C: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    after_4:
    // 0x80792E30: b           L_80792F28
    // 0x80792E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80792F28;
    // 0x80792E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80792E38:
    // 0x80792E38: beq         $at, $zero, L_80792E4C
    if (ctx->r1 == 0) {
        // 0x80792E3C: addiu       $v0, $s0, 0xC4
        ctx->r2 = ADD32(ctx->r16, 0XC4);
            goto L_80792E4C;
    }
    // 0x80792E3C: addiu       $v0, $s0, 0xC4
    ctx->r2 = ADD32(ctx->r16, 0XC4);
    // 0x80792E40: sltiu       $t5, $a2, 0x1
    ctx->r13 = ctx->r6 < 0X1 ? 1 : 0;
    // 0x80792E44: b           L_80792F24
    // 0x80792E48: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
        goto L_80792F24;
    // 0x80792E48: sw          $t5, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r13;
L_80792E4C:
    // 0x80792E4C: lui         $t4, 0x8010
    ctx->r12 = S32(0X8010 << 16);
    // 0x80792E50: lw          $t4, -0x7290($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7290);
    // 0x80792E54: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x80792E58: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x80792E5C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80792E60: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80792E64: lw          $t9, 0x4($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X4);
    // 0x80792E68: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80792E6C: jalr        $t9
    // 0x80792E70: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x80792E70: nop

    after_5:
    // 0x80792E74: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x80792E78: lw          $t6, -0x7290($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7290);
    // 0x80792E7C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80792E80: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80792E84: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80792E88: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80792E8C: lw          $a0, 0x2C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X2C);
    // 0x80792E90: jalr        $t9
    // 0x80792E94: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x80792E94: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    after_6:
    // 0x80792E98: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80792E9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80792EA0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80792EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80792EA8: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80792EAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80792EB0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80792EB4: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x80792EB8: jal         0x8079393C
    // 0x80792EBC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    func_8079393C(rdram, ctx);
        goto after_7;
    // 0x80792EBC: lw          $a3, 0x68($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X68);
    after_7:
    // 0x80792EC0: lwc1        $f16, 0x88($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X88);
    // 0x80792EC4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80792EC8: lui         $at, 0x8079
    ctx->r1 = S32(RELOC_HI16(817, 0X7B04) << 16);
    // 0x80792ECC: lwc1        $f0, 0x7E54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(817, 0X7B04));
    // 0x80792ED0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80792ED4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x80792ED8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80792EDC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80792EE0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80792EE4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80792EE8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80792EEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80792EF0: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80792EF4: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x80792EF8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80792EFC: swc1        $f18, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80792F00: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x80792F04: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x80792F08: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80792F0C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80792F10: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80792F14: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80792F18: lw          $t7, -0x7290($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7290);
    // 0x80792F1C: sw          $zero, 0x24($t7)
    MEM_W(0X24, ctx->r15) = 0;
    // 0x80792F20: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
L_80792F24:
    // 0x80792F24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80792F28:
    // 0x80792F28: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80792F2C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80792F30: jr          $ra
    // 0x80792F34: nop

    return;
    // 0x80792F34: nop

;}
RECOMP_FUNC void func_806D944C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806D944C: lw          $t7, 0x174($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X174);
    // 0x806D9450: lui         $t6, 0x806E
    ctx->r14 = S32(RELOC_HI16(628, 0X150) << 16);
    // 0x806D9454: addiu       $t6, $t6, -0x6FF0
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(628, 0X150));
    // 0x806D9458: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x806D945C: lui         $t9, 0x8006
    ctx->r25 = S32(0X8006 << 16);
    // 0x806D9460: addiu       $t9, $t9, 0x5284
    ctx->r25 = ADD32(ctx->r25, 0X5284);
    // 0x806D9464: sw          $t6, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r14;
    // 0x806D9468: lw          $t0, 0x174($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X174);
    // 0x806D946C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x806D9470: jr          $ra
    // 0x806D9474: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
    return;
    // 0x806D9474: sw          $t9, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r25;
;}
RECOMP_FUNC void func_8040E034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8040E034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8040E038: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8040E03C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8040E040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8040E044: jal         0x8040DCF0
    // 0x8040E048: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    func_8040DCF0(rdram, ctx);
        goto after_0;
    // 0x8040E048: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    after_0:
    // 0x8040E04C: bne         $v0, $zero, L_8040E064
    if (ctx->r2 != 0) {
        // 0x8040E050: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_8040E064;
    }
    // 0x8040E050: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8040E054: jal         0x800445A4
    // 0x8040E058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_800445A4(rdram, ctx);
        goto after_1;
    // 0x8040E058: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8040E05C: b           L_8040E110
    // 0x8040E060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8040E110;
    // 0x8040E060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040E064:
    // 0x8040E064: lw          $s1, 0x1F4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X1F4);
    // 0x8040E068: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8040E06C: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8040E070: sw          $t6, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r14;
    // 0x8040E074: sw          $t7, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r15;
    // 0x8040E078: sw          $t8, 0x1E0($s0)
    MEM_W(0X1E0, ctx->r16) = ctx->r24;
    // 0x8040E07C: sh          $zero, 0x144($s0)
    MEM_H(0X144, ctx->r16) = 0;
    // 0x8040E080: lw          $a3, 0x138($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X138);
    // 0x8040E084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040E088: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8040E08C: jal         0x8040E254
    // 0x8040E090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_8040E254(rdram, ctx);
        goto after_2;
    // 0x8040E090: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8040E094: jal         0x80058958
    // 0x8040E098: nop

    func_80058958(rdram, ctx);
        goto after_3;
    // 0x8040E098: nop

    after_3:
    // 0x8040E09C: beq         $v0, $zero, L_8040E10C
    if (ctx->r2 == 0) {
        // 0x8040E0A0: lui         $t9, 0x8010
        ctx->r25 = S32(0X8010 << 16);
            goto L_8040E10C;
    }
    // 0x8040E0A0: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x8040E0A4: lw          $t9, -0x7BC4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7BC4);
    // 0x8040E0A8: lw          $t0, 0x10C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10C);
    // 0x8040E0AC: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8040E0B0: srl         $t2, $t1, 30
    ctx->r10 = S32(U32(ctx->r9) >> 30);
    // 0x8040E0B4: beql        $t2, $zero, L_8040E110
    if (ctx->r10 == 0) {
        // 0x8040E0B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8040E110;
    }
    goto skip_0;
    // 0x8040E0B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8040E0BC: jal         0x80056564
    // 0x8040E0C0: nop

    func_80056564(rdram, ctx);
        goto after_4;
    // 0x8040E0C0: nop

    after_4:
    // 0x8040E0C4: beq         $v0, $zero, L_8040E10C
    if (ctx->r2 == 0) {
        // 0x8040E0C8: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8040E10C;
    }
    // 0x8040E0C8: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8040E0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8040E0D0: jal         0x800457A0
    // 0x8040E0D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    func_800457A0(rdram, ctx);
        goto after_5;
    // 0x8040E0D4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_5:
    // 0x8040E0D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8040E0DC: addiu       $t3, $zero, 0x1F
    ctx->r11 = ADD32(0, 0X1F);
    // 0x8040E0E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8040E0E4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8040E0E8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8040E0EC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8040E0F0: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8040E0F4: jal         0x80056584
    // 0x8040E0F8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    func_80056584(rdram, ctx);
        goto after_6;
    // 0x8040E0F8: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    after_6:
    // 0x8040E0FC: lw          $t6, 0x16C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X16C);
    // 0x8040E100: lui         $t5, 0x8005
    ctx->r13 = S32(0X8005 << 16);
    // 0x8040E104: addiu       $t5, $t5, 0x784C
    ctx->r13 = ADD32(ctx->r13, 0X784C);
    // 0x8040E108: sw          $t5, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r13;
L_8040E10C:
    // 0x8040E10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8040E110:
    // 0x8040E110: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8040E114: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8040E118: jr          $ra
    // 0x8040E11C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8040E11C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80030B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80030B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030B84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80030B88: jal         0x8002C95C
    // 0x80030B8C: lbu         $a1, 0x16($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X16);
    func_8002C95C(rdram, ctx);
        goto after_0;
    // 0x80030B8C: lbu         $a1, 0x16($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X16);
    after_0:
    // 0x80030B90: jal         0x8005D320
    // 0x80030B94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8005D320(rdram, ctx);
        goto after_1;
    // 0x80030B94: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80030B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80030B9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80030BA0: jr          $ra
    // 0x80030BA4: nop

    return;
    // 0x80030BA4: nop

;}
RECOMP_FUNC void func_807B9390(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B9390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x807B9394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x807B9398: jal         0x807B9118
    // 0x807B939C: nop

    func_807B9118(rdram, ctx);
        goto after_0;
    // 0x807B939C: nop

    after_0:
    // 0x807B93A0: beql        $v0, $zero, L_807B93B4
    if (ctx->r2 == 0) {
        // 0x807B93A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_807B93B4;
    }
    goto skip_0;
    // 0x807B93A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x807B93A8: jal         0x8006988C
    // 0x807B93AC: nop

    func_8006988C(rdram, ctx);
        goto after_1;
    // 0x807B93AC: nop

    after_1:
    // 0x807B93B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_807B93B4:
    // 0x807B93B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x807B93B8: jr          $ra
    // 0x807B93BC: nop

    return;
    // 0x807B93BC: nop

;}
RECOMP_FUNC void func_804C1BE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C1BE4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804C1BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804C1BEC: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x804C1BF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x804C1BF4: jal         0x804C192C
    // 0x804C1BF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    func_804C192C(rdram, ctx);
        goto after_0;
    // 0x804C1BF8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    after_0:
    // 0x804C1BFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C1C00: addiu       $v0, $a0, 0xC4
    ctx->r2 = ADD32(ctx->r4, 0XC4);
    // 0x804C1C04: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C1C08: lwc1        $f14, 0x28($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X28);
    // 0x804C1C0C: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x804C1C10: jal         0x80065ABC
    // 0x804C1C14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_80065ABC(rdram, ctx);
        goto after_1;
    // 0x804C1C14: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x804C1C18: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x804C1C1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x804C1C20: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x804C1C24: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x804C1C28: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x804C1C2C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x804C1C30: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x804C1C34: nop

    // 0x804C1C38: bc1fl       L_804C1CA4
    if (!c1cs) {
        // 0x804C1C3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C1CA4;
    }
    goto skip_0;
    // 0x804C1C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x804C1C40: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C1C44: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x804C1C48: nop

    // 0x804C1C4C: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x804C1C50: nop

    // 0x804C1C54: bc1fl       L_804C1CA4
    if (!c1cs) {
        // 0x804C1C58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804C1CA4;
    }
    goto skip_1;
    // 0x804C1C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x804C1C5C: lw          $v1, 0x1E0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1E0);
    // 0x804C1C60: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x804C1C64: lui         $at, 0x804C
    ctx->r1 = S32(RELOC_HI16(203, 0X1148) << 16);
    // 0x804C1C68: bne         $v1, $zero, L_804C1C8C
    if (ctx->r3 != 0) {
        // 0x804C1C6C: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_804C1C8C;
    }
    // 0x804C1C6C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x804C1C70: sw          $t8, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r24;
    // 0x804C1C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804C1C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x804C1C7C: jal         0x804C1F2C
    // 0x804C1C80: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    func_804C1F2C(rdram, ctx);
        goto after_2;
    // 0x804C1C80: lw          $a3, 0x138($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X138);
    after_2:
    // 0x804C1C84: b           L_804C1CA4
    // 0x804C1C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804C1CA4;
    // 0x804C1C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1C8C:
    // 0x804C1C8C: sw          $t9, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = ctx->r25;
    // 0x804C1C90: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x804C1C94: lwc1        $f18, 0x28B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(203, 0X1148));
    // 0x804C1C98: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x804C1C9C: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x804C1CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804C1CA4:
    // 0x804C1CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x804C1CA8: jr          $ra
    // 0x804C1CAC: nop

    return;
    // 0x804C1CAC: nop

;}
RECOMP_FUNC void func_80579CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80579CB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80579CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80579CB8: jal         0x80579C6C
    // 0x80579CBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80579C6C(rdram, ctx);
        goto after_0;
    // 0x80579CBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80579CC0: jal         0x80045BD8
    // 0x80579CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_80045BD8(rdram, ctx);
        goto after_1;
    // 0x80579CC4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80579CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80579CCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80579CD0: jr          $ra
    // 0x80579CD4: nop

    return;
    // 0x80579CD4: nop

;}
RECOMP_FUNC void func_80039828(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039828: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8003982C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80039830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80039834: jal         0x8004700C
    // 0x80039838: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x80039838: lw          $s0, 0x1F4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X1F4);
    after_0:
    // 0x8003983C: lw          $t6, 0x1F4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1F4);
    // 0x80039840: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80039844: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80039848: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8003984C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80039850: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80039854: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80039858: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003985C: jal         0x800393C8
    // 0x80039860: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    func_800393C8(rdram, ctx);
        goto after_1;
    // 0x80039860: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80039864: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80039868: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x8003986C: lh          $t7, -0x7662($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X7662);
    // 0x80039870: lwc1        $f8, 0x68($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X68);
    // 0x80039874: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80039878: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8003987C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80039880: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80039884: nop

    // 0x80039888: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x8003988C: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80039890: multu       $t7, $t2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80039894: mflo        $a2
    ctx->r6 = lo;
    // 0x80039898: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x8003989C: jal         0x8003943C
    // 0x800398A0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    func_8003943C(rdram, ctx);
        goto after_2;
    // 0x800398A0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_2:
    // 0x800398A4: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800398A8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x800398AC: jal         0x800659EC
    // 0x800398B0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    func_800659EC(rdram, ctx);
        goto after_3;
    // 0x800398B0: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x800398B4: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x800398B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800398BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800398C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800398C4: jr          $ra
    // 0x800398C8: nop

    return;
    // 0x800398C8: nop

;}
RECOMP_FUNC void func_8043751C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8043751C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80437520: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80437524: jr          $ra
    // 0x80437528: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    return;
    // 0x80437528: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
;}
RECOMP_FUNC void func_806809F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806809F8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x806809FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80680A00: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80680A04: jal         0x80047090
    // 0x80680A08: addiu       $a0, $zero, 0x457B
    ctx->r4 = ADD32(0, 0X457B);
    func_80047090(rdram, ctx);
        goto after_0;
    // 0x80680A08: addiu       $a0, $zero, 0x457B
    ctx->r4 = ADD32(0, 0X457B);
    after_0:
    // 0x80680A0C: addiu       $at, $zero, 0x3FF
    ctx->r1 = ADD32(0, 0X3FF);
    // 0x80680A10: bne         $v0, $at, L_80680A20
    if (ctx->r2 != ctx->r1) {
        // 0x80680A14: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80680A20;
    }
    // 0x80680A14: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80680A18: b           L_80680A98
    // 0x80680A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680A98;
    // 0x80680A1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680A20:
    // 0x80680A20: lui         $at, 0x457B
    ctx->r1 = S32(0X457B << 16);
    // 0x80680A24: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80680A28: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80680A2C: or          $a0, $v1, $at
    ctx->r4 = ctx->r3 | ctx->r1;
    // 0x80680A30: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x80680A34: lui         $a2, 0xC220
    ctx->r6 = S32(0XC220 << 16);
    // 0x80680A38: jal         0x8004613C
    // 0x80680A3C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    func_8004613C(rdram, ctx);
        goto after_1;
    // 0x80680A3C: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    after_1:
    // 0x80680A40: lhu         $v1, 0x1A($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0X1A);
    // 0x80680A44: bne         $v0, $zero, L_80680A54
    if (ctx->r2 != 0) {
        // 0x80680A48: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80680A54;
    }
    // 0x80680A48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80680A4C: b           L_80680A98
    // 0x80680A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680A98;
    // 0x80680A50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680A54:
    // 0x80680A54: lhu         $t8, 0xE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XE);
    // 0x80680A58: andi        $t7, $v1, 0x3FF
    ctx->r15 = ctx->r3 & 0X3FF;
    // 0x80680A5C: andi        $t9, $t8, 0xFC00
    ctx->r25 = ctx->r24 & 0XFC00;
    // 0x80680A60: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80680A64: sh          $t0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r8;
    // 0x80680A68: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80680A6C: jal         0x80047F9C
    // 0x80680A70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    func_80047F9C(rdram, ctx);
        goto after_2;
    // 0x80680A70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80680A74: jal         0x8068195C
    // 0x80680A78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_8068195C(rdram, ctx);
        goto after_3;
    // 0x80680A78: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80680A7C: bne         $v0, $zero, L_80680A8C
    if (ctx->r2 != 0) {
        // 0x80680A80: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80680A8C;
    }
    // 0x80680A80: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80680A84: b           L_80680A98
    // 0x80680A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80680A98;
    // 0x80680A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80680A8C:
    // 0x80680A8C: jal         0x8005FDC4
    // 0x80680A90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    func_8005FDC4(rdram, ctx);
        goto after_4;
    // 0x80680A90: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80680A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80680A98:
    // 0x80680A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80680A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80680AA0: jr          $ra
    // 0x80680AA4: nop

    return;
    // 0x80680AA4: nop

;}
RECOMP_FUNC void func_80558B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80558B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80558B8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80558B90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80558B94: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x80558B98: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80558B9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80558BA0: sb          $zero, 0x7EA6($at)
    MEM_B(0X7EA6, ctx->r1) = 0;
    // 0x80558BA4: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x80558BA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80558BAC: jal         0x80048F84
    // 0x80558BB0: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    func_80048F84(rdram, ctx);
        goto after_0;
    // 0x80558BB0: sw          $zero, 0x30($v0)
    MEM_W(0X30, ctx->r2) = 0;
    after_0:
    // 0x80558BB4: jal         0x805580E8
    // 0x80558BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805580E8(rdram, ctx);
        goto after_1;
    // 0x80558BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80558BBC: lw          $t6, 0x1E4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1E4);
    // 0x80558BC0: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80558BC4: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x80558BC8: bne         $v1, $at, L_80558BF8
    if (ctx->r3 != ctx->r1) {
        // 0x80558BCC: sw          $v1, 0x1E4($s0)
        MEM_W(0X1E4, ctx->r16) = ctx->r3;
            goto L_80558BF8;
    }
    // 0x80558BCC: sw          $v1, 0x1E4($s0)
    MEM_W(0X1E4, ctx->r16) = ctx->r3;
    // 0x80558BD0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    // 0x80558BD4: jal         0x80067BBC
    // 0x80558BD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    func_80067BBC(rdram, ctx);
        goto after_2;
    // 0x80558BD8: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    after_2:
    // 0x80558BDC: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x80558BE0: jal         0x80067F78
    // 0x80558BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_80067F78(rdram, ctx);
        goto after_3;
    // 0x80558BE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80558BE8: sh          $v0, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r2;
    // 0x80558BEC: jal         0x800492C0
    // 0x80558BF0: addiu       $a0, $zero, -0x66
    ctx->r4 = ADD32(0, -0X66);
    func_800492C0(rdram, ctx);
        goto after_4;
    // 0x80558BF0: addiu       $a0, $zero, -0x66
    ctx->r4 = ADD32(0, -0X66);
    after_4:
    // 0x80558BF4: lw          $v1, 0x1E4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1E4);
L_80558BF8:
    // 0x80558BF8: slti        $at, $v1, 0x5F
    ctx->r1 = SIGNED(ctx->r3) < 0X5F ? 1 : 0;
    // 0x80558BFC: bne         $at, $zero, L_80558C3C
    if (ctx->r1 != 0) {
        // 0x80558C00: addiu       $a0, $zero, 0x69
        ctx->r4 = ADD32(0, 0X69);
            goto L_80558C3C;
    }
    // 0x80558C00: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x80558C04: jal         0x80067930
    // 0x80558C08: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067930(rdram, ctx);
        goto after_5;
    // 0x80558C08: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_5:
    // 0x80558C0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80558C10: bne         $v0, $at, L_80558C28
    if (ctx->r2 != ctx->r1) {
        // 0x80558C14: addiu       $a0, $zero, 0x69
        ctx->r4 = ADD32(0, 0X69);
            goto L_80558C28;
    }
    // 0x80558C14: addiu       $a0, $zero, 0x69
    ctx->r4 = ADD32(0, 0X69);
    // 0x80558C18: jal         0x80067878
    // 0x80558C1C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    func_80067878(rdram, ctx);
        goto after_6;
    // 0x80558C1C: lh          $a1, 0x1F0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X1F0);
    after_6:
    // 0x80558C20: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80558C24: sh          $t8, 0x1F0($s0)
    MEM_H(0X1F0, ctx->r16) = ctx->r24;
L_80558C28:
    // 0x80558C28: jal         0x800677F8
    // 0x80558C2C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    func_800677F8(rdram, ctx);
        goto after_7;
    // 0x80558C2C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_7:
    // 0x80558C30: lui         $t9, 0x8056
    ctx->r25 = S32(RELOC_HI16(363, 0XF90) << 16);
    // 0x80558C34: addiu       $t9, $t9, -0x7520
    ctx->r25 = ADD32(ctx->r25, (int16_t)RELOC_LO16(363, 0XF90));
    // 0x80558C38: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
L_80558C3C:
    // 0x80558C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80558C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80558C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80558C48: jr          $ra
    // 0x80558C4C: nop

    return;
    // 0x80558C4C: nop

;}
RECOMP_FUNC void func_80004774(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000477C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80004780: bne         $a1, $zero, L_800047A0
    if (ctx->r5 != 0) {
        // 0x80004784: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800047A0;
    }
    // 0x80004784: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80004788: bne         $a2, $zero, L_800047A0
    if (ctx->r6 != 0) {
        // 0x8000478C: nop
    
            goto L_800047A0;
    }
    // 0x8000478C: nop

    // 0x80004790: jal         0x800046C8
    // 0x80004794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_800046C8(rdram, ctx);
        goto after_0;
    // 0x80004794: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80004798: b           L_80004894
    // 0x8000479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004894;
    // 0x8000479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800047A0:
    // 0x800047A0: bne         $a3, $zero, L_800047B8
    if (ctx->r7 != 0) {
        // 0x800047A4: nop
    
            goto L_800047B8;
    }
    // 0x800047A4: nop

    // 0x800047A8: jal         0x800046C8
    // 0x800047AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_800046C8(rdram, ctx);
        goto after_1;
    // 0x800047AC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800047B0: b           L_80004894
    // 0x800047B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004894;
    // 0x800047B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800047B8:
    // 0x800047B8: bne         $a1, $zero, L_800047D4
    if (ctx->r5 != 0) {
        // 0x800047BC: lw          $v0, 0x18($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X18);
            goto L_800047D4;
    }
    // 0x800047BC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x800047C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800047C4: jal         0x8000471C
    // 0x800047C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_8000471C(rdram, ctx);
        goto after_2;
    // 0x800047C8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x800047CC: b           L_80004894
    // 0x800047D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80004894;
    // 0x800047D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800047D4:
    // 0x800047D4: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800047D8: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800047DC: lui         $t6, 0x8009
    ctx->r14 = S32(0X8009 << 16);
    // 0x800047E0: lui         $t7, 0x8009
    ctx->r15 = S32(0X8009 << 16);
    // 0x800047E4: addiu       $t7, $t7, 0x7448
    ctx->r15 = ADD32(ctx->r15, 0X7448);
    // 0x800047E8: addiu       $t6, $t6, 0x7638
    ctx->r14 = ADD32(ctx->r14, 0X7638);
    // 0x800047EC: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800047F0: addu        $a0, $a2, $t7
    ctx->r4 = ADD32(ctx->r6, ctx->r15);
    // 0x800047F4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800047F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800047FC:
    // 0x800047FC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80004800: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80004804: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004808: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8000480C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80004810: bgez        $t0, L_80004820
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80004814: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80004820;
    }
    // 0x80004814: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80004818: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8000481C: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80004820:
    // 0x80004820: sh          $t1, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r9;
    // 0x80004824: lh          $t3, 0x2($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2);
    // 0x80004828: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8000482C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80004830: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80004834: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80004838: bgez        $t4, L_80004848
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000483C: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_80004848;
    }
    // 0x8000483C: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80004840: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x80004844: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_80004848:
    // 0x80004848: sh          $t5, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r13;
    // 0x8000484C: lh          $t7, -0x4($a0)
    ctx->r15 = MEM_H(ctx->r4, -0X4);
    // 0x80004850: lh          $t6, -0x4($v1)
    ctx->r14 = MEM_H(ctx->r3, -0X4);
    // 0x80004854: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80004858: bgez        $t8, L_80004868
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000485C: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80004868;
    }
    // 0x8000485C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80004860: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80004864: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_80004868:
    // 0x80004868: sh          $t9, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = ctx->r25;
    // 0x8000486C: lh          $t1, -0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, -0X2);
    // 0x80004870: lh          $t0, -0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, -0X2);
    // 0x80004874: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80004878: bgez        $t2, L_80004888
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8000487C: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_80004888;
    }
    // 0x8000487C: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x80004880: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x80004884: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80004888:
    // 0x80004888: bne         $a1, $a2, L_800047FC
    if (ctx->r5 != ctx->r6) {
        // 0x8000488C: sh          $t3, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r11;
            goto L_800047FC;
    }
    // 0x8000488C: sh          $t3, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r11;
    // 0x80004890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80004894:
    // 0x80004894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004898: jr          $ra
    // 0x8000489C: nop

    return;
    // 0x8000489C: nop

;}
RECOMP_FUNC void func_8067DF04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067DF04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8067DF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067DF0C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x8067DF10: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x8067DF14: sw          $a1, 0x12C($a0)
    MEM_W(0X12C, ctx->r4) = ctx->r5;
    // 0x8067DF18: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8067DF1C: lui         $t8, 0x8068
    ctx->r24 = S32(RELOC_HI16(544, 0XE58) << 16);
    // 0x8067DF20: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8067DF24: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8067DF28: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8067DF2C: lw          $t8, -0x12E8($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(544, 0XE58));
    // 0x8067DF30: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8067DF34: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8067DF38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8067DF3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8067DF40: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x8067DF44: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8067DF48: jal         0x80048490
    // 0x8067DF4C: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    func_80048490(rdram, ctx);
        goto after_0;
    // 0x8067DF4C: addu        $a1, $t8, $v0
    ctx->r5 = ADD32(ctx->r24, ctx->r2);
    after_0:
    // 0x8067DF50: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8067DF54: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8067DF58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8067DF5C: lbu         $v1, 0x30($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X30);
    // 0x8067DF60: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8067DF64: sltiu       $t9, $v0, 0x1
    ctx->r25 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x8067DF68: beq         $v1, $at, L_8067DF78
    if (ctx->r3 == ctx->r1) {
        // 0x8067DF6C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8067DF78;
    }
    // 0x8067DF6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8067DF70: bnel        $v1, $at, L_8067DF84
    if (ctx->r3 != ctx->r1) {
        // 0x8067DF74: sw          $a2, 0x138($a0)
        MEM_W(0X138, ctx->r4) = ctx->r6;
            goto L_8067DF84;
    }
    goto skip_0;
    // 0x8067DF74: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
    skip_0:
L_8067DF78:
    // 0x8067DF78: b           L_8067DF84
    // 0x8067DF7C: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
        goto L_8067DF84;
    // 0x8067DF7C: sw          $t9, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r25;
    // 0x8067DF80: sw          $a2, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->r6;
L_8067DF84:
    // 0x8067DF84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8067DF88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8067DF8C: jr          $ra
    // 0x8067DF90: nop

    return;
    // 0x8067DF90: nop

;}
RECOMP_FUNC void func_805CAA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805CAA68: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x805CAA6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x805CAA70: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x805CAA74: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x805CAA78: lwc1        $f2, 0x6C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x805CAA7C: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
    // 0x805CAA80: lwc1        $f14, 0x70($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X70);
    // 0x805CAA84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805CAA88: beql        $v1, $zero, L_805CAB04
    if (ctx->r3 == 0) {
        // 0x805CAA8C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_805CAB04;
    }
    goto skip_0;
    // 0x805CAA8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x805CAA90: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    // 0x805CAA94: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x805CAA98: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x805CAA9C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x805CAAA0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x805CAAA4: lw          $t8, 0x24($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X24);
    // 0x805CAAA8: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805CAAAC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x805CAAB0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x805CAAB4: lw          $a0, 0x1C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X1C);
    // 0x805CAAB8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x805CAABC: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x805CAAC0: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x805CAAC4: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x805CAAC8: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x805CAACC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x805CAAD0: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x805CAAD4: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x805CAAD8: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x805CAADC: bne         $a0, $zero, L_805CAAF8
    if (ctx->r4 != 0) {
        // 0x805CAAE0: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_805CAAF8;
    }
    // 0x805CAAE0: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x805CAAE4: lw          $t0, 0x28($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X28);
    // 0x805CAAE8: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x805CAAEC: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x805CAAF0: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x805CAAF4: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
L_805CAAF8:
    // 0x805CAAF8: b           L_805CABEC
    // 0x805CAAFC: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
        goto L_805CABEC;
    // 0x805CAAFC: sw          $a0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r4;
    // 0x805CAB00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_805CAB04:
    // 0x805CAB04: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805CAB08: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x805CAB0C: sub.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x805CAB10: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x805CAB14: jal         0x80065954
    // 0x805CAB18: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x805CAB18: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x805CAB1C: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X930) << 16);
    // 0x805CAB20: lwc1        $f16, -0x4E80($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X930));
    // 0x805CAB24: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x805CAB28: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805CAB2C: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805CAB30: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805CAB34: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805CAB38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805CAB3C: bc1fl       L_805CAB54
    if (!c1cs) {
        // 0x805CAB40: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_805CAB54;
    }
    goto skip_1;
    // 0x805CAB40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x805CAB44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x805CAB48: b           L_805CAB78
    // 0x805CAB4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_805CAB78;
    // 0x805CAB4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805CAB50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_805CAB54:
    // 0x805CAB54: nop

    // 0x805CAB58: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x805CAB5C: nop

    // 0x805CAB60: bc1fl       L_805CAB74
    if (!c1cs) {
        // 0x805CAB64: sub.s       $f2, $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
            goto L_805CAB74;
    }
    goto skip_2;
    // 0x805CAB64: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    skip_2:
    // 0x805CAB68: b           L_805CAB74
    // 0x805CAB6C: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
        goto L_805CAB74;
    // 0x805CAB6C: add.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x805CAB70: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
L_805CAB74:
    // 0x805CAB74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_805CAB78:
    // 0x805CAB78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x805CAB7C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x805CAB80: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x805CAB84: sub.s       $f12, $f4, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x805CAB88: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    // 0x805CAB8C: jal         0x80065954
    // 0x805CAB90: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x805CAB90: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x805CAB94: lui         $at, 0x805D
    ctx->r1 = S32(RELOC_HI16(453, 0X934) << 16);
    // 0x805CAB98: lwc1        $f16, -0x4E7C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(453, 0X934));
    // 0x805CAB9C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x805CABA0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x805CABA4: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x805CABA8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x805CABAC: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x805CABB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x805CABB4: bc1fl       L_805CABCC
    if (!c1cs) {
        // 0x805CABB8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_805CABCC;
    }
    goto skip_3;
    // 0x805CABB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_3:
    // 0x805CABBC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x805CABC0: b           L_805CABF0
    // 0x805CABC4: swc1        $f2, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f2.u32l;
        goto L_805CABF0;
    // 0x805CABC4: swc1        $f2, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f2.u32l;
    // 0x805CABC8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_805CABCC:
    // 0x805CABCC: nop

    // 0x805CABD0: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x805CABD4: nop

    // 0x805CABD8: bc1fl       L_805CABEC
    if (!c1cs) {
        // 0x805CABDC: sub.s       $f14, $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
            goto L_805CABEC;
    }
    goto skip_4;
    // 0x805CABDC: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    skip_4:
    // 0x805CABE0: b           L_805CABEC
    // 0x805CABE4: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
        goto L_805CABEC;
    // 0x805CABE4: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x805CABE8: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
L_805CABEC:
    // 0x805CABEC: swc1        $f2, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f2.u32l;
L_805CABF0:
    // 0x805CABF0: swc1        $f14, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f14.u32l;
    // 0x805CABF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x805CABF8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x805CABFC: jr          $ra
    // 0x805CAC00: nop

    return;
    // 0x805CAC00: nop

;}
RECOMP_FUNC void func_8001A534(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A534: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001A538: addiu       $v1, $v1, 0x5A0
    ctx->r3 = ADD32(ctx->r3, 0X5A0);
    // 0x8001A53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001A540:
    // 0x8001A540: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001A544: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001A548: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8001A54C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8001A550: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8001A554: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8001A558: bne         $at, $zero, L_8001A540
    if (ctx->r1 != 0) {
        // 0x8001A55C: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8001A540;
    }
    // 0x8001A55C: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8001A560: jr          $ra
    // 0x8001A564: nop

    return;
    // 0x8001A564: nop

;}
RECOMP_FUNC void func_8079FB84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8079FB84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8079FB88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8079FB8C: jal         0x8079FAC8
    // 0x8079FB90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8079FAC8(rdram, ctx);
        goto after_0;
    // 0x8079FB90: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8079FB94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8079FB98: beq         $v0, $at, L_8079FBB4
    if (ctx->r2 == ctx->r1) {
        // 0x8079FB9C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8079FBB4;
    }
    // 0x8079FB9C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8079FBA0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8079FBA4: beq         $v0, $at, L_8079FBC4
    if (ctx->r2 == ctx->r1) {
        // 0x8079FBA8: nop
    
            goto L_8079FBC4;
    }
    // 0x8079FBA8: nop

    // 0x8079FBAC: b           L_8079FBD4
    // 0x8079FBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079FBD4;
    // 0x8079FBB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079FBB4:
    // 0x8079FBB4: jal         0x8079F7D8
    // 0x8079FBB8: nop

    func_8079F7D8(rdram, ctx);
        goto after_1;
    // 0x8079FBB8: nop

    after_1:
    // 0x8079FBBC: b           L_8079FBD4
    // 0x8079FBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8079FBD4;
    // 0x8079FBC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8079FBC4:
    // 0x8079FBC4: jal         0x8079F7D8
    // 0x8079FBC8: nop

    func_8079F7D8(rdram, ctx);
        goto after_2;
    // 0x8079FBC8: nop

    after_2:
    // 0x8079FBCC: b           L_8079FBD4
    // 0x8079FBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8079FBD4;
    // 0x8079FBD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8079FBD4:
    // 0x8079FBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8079FBD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8079FBDC: jr          $ra
    // 0x8079FBE0: nop

    return;
    // 0x8079FBE0: nop

;}
RECOMP_FUNC void func_8064C638(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064C638: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8064C63C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8064C640: jal         0x8004700C
    // 0x8064C644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8004700C(rdram, ctx);
        goto after_0;
    // 0x8064C644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8064C648: beq         $v0, $zero, L_8064C694
    if (ctx->r2 == 0) {
        // 0x8064C64C: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8064C694;
    }
    // 0x8064C64C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8064C650: lwc1        $f4, 0x84($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8064C654: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x8064C658: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8064C65C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8064C660: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8064C664: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x8064C668: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8064C66C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8064C670: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8064C674: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8064C678: nop

    // 0x8064C67C: bc1fl       L_8064C698
    if (!c1cs) {
        // 0x8064C680: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8064C698;
    }
    goto skip_0;
    // 0x8064C680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8064C684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8064C688: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8064C68C: jal         0x8064CD50
    // 0x8064C690: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    func_8064CD50(rdram, ctx);
        goto after_1;
    // 0x8064C690: swc1        $f10, 0xC8($a0)
    MEM_W(0XC8, ctx->r4) = ctx->f10.u32l;
    after_1:
L_8064C694:
    // 0x8064C694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8064C698:
    // 0x8064C698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8064C69C: jr          $ra
    // 0x8064C6A0: nop

    return;
    // 0x8064C6A0: nop

;}
RECOMP_FUNC void func_807B21D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x807B21D8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x807B21DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x807B21E0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x807B21E4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x807B21E8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x807B21EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x807B21F0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x807B21F4: bne         $a1, $zero, L_807B2204
    if (ctx->r5 != 0) {
        // 0x807B21F8: lw          $v0, 0x1F4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X1F4);
            goto L_807B2204;
    }
    // 0x807B21F8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x807B21FC: b           L_807B2458
    // 0x807B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_807B2458;
    // 0x807B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_807B2204:
    // 0x807B2204: lw          $t6, 0x140($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X140);
    // 0x807B2208: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x807B220C: lw          $t7, 0x170($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X170);
    // 0x807B2210: lwc1        $f6, 0x8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8);
    // 0x807B2214: lwc1        $f8, 0x144($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X144);
    // 0x807B2218: lwc1        $f10, 0x148($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X148);
    // 0x807B221C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x807B2220: mul.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x807B2224: bne         $t7, $at, L_807B241C
    if (ctx->r15 != ctx->r1) {
        // 0x807B2228: sub.s       $f0, $f8, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
            goto L_807B241C;
    }
    // 0x807B2228: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x807B222C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x807B2230: lwc1        $f12, 0x150($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X150);
    // 0x807B2234: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x807B2238: nop

    // 0x807B223C: bc1f        L_807B2388
    if (!c1cs) {
        // 0x807B2240: nop
    
            goto L_807B2388;
    }
    // 0x807B2240: nop

    // 0x807B2244: lbu         $t8, 0x30($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X30);
    // 0x807B2248: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x807B224C: beql        $t8, $at, L_807B231C
    if (ctx->r24 == ctx->r1) {
        // 0x807B2250: neg.s       $f8, $f2
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
            goto L_807B231C;
    }
    goto skip_0;
    // 0x807B2250: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    skip_0:
    // 0x807B2254: lwc1        $f18, 0xC8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x807B2258: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x807B225C: nop

    // 0x807B2260: bc1t        L_807B227C
    if (c1cs) {
        // 0x807B2264: nop
    
            goto L_807B227C;
    }
    // 0x807B2264: nop

    // 0x807B2268: lw          $v1, 0x1F4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1F4);
    // 0x807B226C: lw          $t9, 0x34($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X34);
    // 0x807B2270: ori         $t0, $t9, 0x700
    ctx->r8 = ctx->r25 | 0X700;
    // 0x807B2274: sw          $t0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r8;
    // 0x807B2278: lwc1        $f12, 0x150($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X150);
L_807B227C:
    // 0x807B227C: jal         0x80081E8C
    // 0x807B2280: lwc1        $f14, 0x14C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14C);
    fatan2(rdram, ctx);
        goto after_0;
    // 0x807B2280: lwc1        $f14, 0x14C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14C);
    after_0:
    // 0x807B2284: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3990) << 16);
    // 0x807B2288: lwc1        $f4, 0x34E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3990));
    // 0x807B228C: lwc1        $f14, 0xC4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x807B2290: lwc1        $f2, 0xC8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x807B2294: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x807B2298: nop

    // 0x807B229C: mul.s       $f20, $f14, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B22A0: nop

    // 0x807B22A4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B22A8: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x807B22AC: add.s       $f0, $f20, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x807B22B0: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B22B4: jal         0x80066E88
    // 0x807B22B8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_1;
    // 0x807B22B8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x807B22BC: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807B22C0: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807B22C4: mul.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807B22C8: jal         0x80066DE4
    // 0x807B22CC: nop

    func_80066DE4(rdram, ctx);
        goto after_2;
    // 0x807B22CC: nop

    after_2:
    // 0x807B22D0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x807B22D4: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x807B22D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B22DC: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x807B22E0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x807B22E4: jal         0x8002FABC
    // 0x807B22E8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    func_8002FABC(rdram, ctx);
        goto after_3;
    // 0x807B22E8: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x807B22EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807B22F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x807B22F4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x807B22F8: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x807B22FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x807B2300: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x807B2304: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x807B2308: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x807B230C: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
    // 0x807B2310: b           L_807B2458
    // 0x807B2314: swc1        $f6, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f6.u32l;
        goto L_807B2458;
    // 0x807B2314: swc1        $f6, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f6.u32l;
    // 0x807B2318: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
L_807B231C:
    // 0x807B231C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2320: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x807B2324: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x807B2328: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x807B232C: bc1f        L_807B2414
    if (!c1cs) {
        // 0x807B2330: nop
    
            goto L_807B2414;
    }
    // 0x807B2330: nop

    // 0x807B2334: jal         0x807B2D04
    // 0x807B2338: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    func_807B2D04(rdram, ctx);
        goto after_4;
    // 0x807B2338: lw          $a3, 0x138($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X138);
    after_4:
    // 0x807B233C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x807B2340: jal         0x80048114
    // 0x807B2344: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_80048114(rdram, ctx);
        goto after_5;
    // 0x807B2344: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x807B2348: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x807B234C: lwc1        $f18, 0x3C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x807B2350: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x807B2354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x807B2358: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x807B235C: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x807B2360: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x807B2364: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x807B2368: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x807B236C: swc1        $f10, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f10.u32l;
    // 0x807B2370: lwc1        $f4, 0x44($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X44);
    // 0x807B2374: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x807B2378: jal         0x8002FB10
    // 0x807B237C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    func_8002FB10(rdram, ctx);
        goto after_6;
    // 0x807B237C: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x807B2380: b           L_807B2458
    // 0x807B2384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807B2458;
    // 0x807B2384: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B2388:
    // 0x807B2388: jal         0x80081E8C
    // 0x807B238C: lwc1        $f14, 0x14C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14C);
    fatan2(rdram, ctx);
        goto after_7;
    // 0x807B238C: lwc1        $f14, 0x14C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14C);
    after_7:
    // 0x807B2390: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3994) << 16);
    // 0x807B2394: lwc1        $f8, 0x34E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3994));
    // 0x807B2398: lwc1        $f14, 0xC4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x807B239C: lwc1        $f2, 0xC8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x807B23A0: mul.s       $f12, $f0, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x807B23A4: nop

    // 0x807B23A8: mul.s       $f20, $f14, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x807B23AC: nop

    // 0x807B23B0: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x807B23B4: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x807B23B8: add.s       $f0, $f20, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x807B23BC: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x807B23C0: jal         0x80066E88
    // 0x807B23C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80066E88(rdram, ctx);
        goto after_8;
    // 0x807B23C4: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x807B23C8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807B23CC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807B23D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x807B23D4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x807B23D8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x807B23DC: mul.s       $f20, $f18, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x807B23E0: jal         0x80066DE4
    // 0x807B23E4: nop

    func_80066DE4(rdram, ctx);
        goto after_9;
    // 0x807B23E4: nop

    after_9:
    // 0x807B23E8: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x807B23EC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x807B23F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x807B23F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x807B23F8: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x807B23FC: neg.s       $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = -ctx->f20.fl;
    // 0x807B2400: mul.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x807B2404: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x807B2408: swc1        $f2, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f2.u32l;
    // 0x807B240C: swc1        $f18, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f18.u32l;
    // 0x807B2410: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
L_807B2414:
    // 0x807B2414: b           L_807B2458
    // 0x807B2418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807B2458;
    // 0x807B2418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B241C:
    // 0x807B241C: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X3998) << 16);
    // 0x807B2420: lwc1        $f6, 0x34E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X3998));
    // 0x807B2424: lui         $at, 0x807B
    ctx->r1 = S32(RELOC_HI16(871, 0X399C) << 16);
    // 0x807B2428: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x807B242C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x807B2430: nop

    // 0x807B2434: bc1t        L_807B2458
    if (c1cs) {
        // 0x807B2438: nop
    
            goto L_807B2458;
    }
    // 0x807B2438: nop

    // 0x807B243C: lwc1        $f8, 0x34EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(871, 0X399C));
    // 0x807B2440: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x807B2444: nop

    // 0x807B2448: bc1t        L_807B2458
    if (c1cs) {
        // 0x807B244C: nop
    
            goto L_807B2458;
    }
    // 0x807B244C: nop

    // 0x807B2450: b           L_807B2458
    // 0x807B2454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_807B2458;
    // 0x807B2454: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_807B2458:
    // 0x807B2458: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x807B245C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x807B2460: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x807B2464: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x807B2468: jr          $ra
    // 0x807B246C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x807B246C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80566550(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80566550: lui         $v0, 0x8056
    ctx->r2 = S32(RELOC_HI16(375, 0X10) << 16);
    // 0x80566554: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80566558: jr          $ra
    // 0x8056655C: addiu       $v0, $v0, 0x6560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(375, 0X10));
    return;
    // 0x8056655C: addiu       $v0, $v0, 0x6560
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(375, 0X10));
;}
RECOMP_FUNC void func_8003E8C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E8C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003E8C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003E8C8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003E8CC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003E8D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8003E8D4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003E8D8: lw          $a3, 0x1EC($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X1EC);
    // 0x8003E8DC: lw          $a2, 0x44($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X44);
    // 0x8003E8E0: lwc1        $f14, 0x40($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X40);
    // 0x8003E8E4: jal         0x8003B8F0
    // 0x8003E8E8: lwc1        $f12, 0x3C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X3C);
    func_8003B8F0(rdram, ctx);
        goto after_0;
    // 0x8003E8E8: lwc1        $f12, 0x3C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X3C);
    after_0:
    // 0x8003E8EC: bne         $v0, $zero, L_8003E8FC
    if (ctx->r2 != 0) {
        // 0x8003E8F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8003E8FC;
    }
    // 0x8003E8F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003E8F4: b           L_8003E958
    // 0x8003E8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8003E958;
    // 0x8003E8F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003E8FC:
    // 0x8003E8FC: lw          $v0, 0x174($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X174);
    // 0x8003E900: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8003E904: addiu       $t6, $t6, -0x4E44
    ctx->r14 = ADD32(ctx->r14, -0X4E44);
    // 0x8003E908: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x8003E90C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003E910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E914: sh          $zero, 0x10($t7)
    MEM_H(0X10, ctx->r15) = 0;
    // 0x8003E918: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8003E91C: sh          $zero, 0x12($t8)
    MEM_H(0X12, ctx->r24) = 0;
    // 0x8003E920: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8003E924: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8003E928: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003E92C: jal         0x80044194
    // 0x8003E930: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    func_80044194(rdram, ctx);
        goto after_1;
    // 0x8003E930: sw          $zero, 0x44($t0)
    MEM_W(0X44, ctx->r8) = 0;
    after_1:
    // 0x8003E934: addiu       $a1, $s1, 0x78
    ctx->r5 = ADD32(ctx->r17, 0X78);
    // 0x8003E938: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8003E93C: jal         0x80065490
    // 0x8003E940: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    func_80065490(rdram, ctx);
        goto after_2;
    // 0x8003E940: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    after_2:
    // 0x8003E944: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8003E948: jal         0x80065490
    // 0x8003E94C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    func_80065490(rdram, ctx);
        goto after_3;
    // 0x8003E94C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    after_3:
    // 0x8003E950: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8003E954: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003E958:
    // 0x8003E958: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003E95C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003E960: jr          $ra
    // 0x8003E964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003E964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_804A4C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4C10: lui         $v0, 0x804A
    ctx->r2 = S32(RELOC_HI16(179, 0X780) << 16);
    // 0x804A4C14: jr          $ra
    // 0x804A4C18: addiu       $v0, $v0, 0x5390
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(179, 0X780));
    return;
    // 0x804A4C18: addiu       $v0, $v0, 0x5390
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(179, 0X780));
;}
RECOMP_FUNC void func_8075F2B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8075F2B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8075F2B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8075F2B8: lw          $v0, 0x1F4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1F4);
    // 0x8075F2BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8075F2C0: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x8075F2C4: lwc1        $f0, 0x214($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X214);
    // 0x8075F2C8: addiu       $a2, $a2, 0x7EA0
    ctx->r6 = ADD32(ctx->r6, 0X7EA0);
    // 0x8075F2CC: lw          $v1, 0xD8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0XD8);
    // 0x8075F2D0: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x8075F2D4: lui         $t3, 0x8076
    ctx->r11 = S32(RELOC_HI16(757, 0XB28) << 16);
    // 0x8075F2D8: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8075F2DC: bc1t        L_8075F33C
    if (c1cs) {
        // 0x8075F2E0: nop
    
            goto L_8075F33C;
    }
    // 0x8075F2E0: nop

    // 0x8075F2E4: lwc1        $f2, 0x210($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X210);
    // 0x8075F2E8: lwc1        $f12, 0x218($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X218);
    // 0x8075F2EC: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x8075F2F0: nop

    // 0x8075F2F4: bc1tl       L_8075F30C
    if (c1cs) {
        // 0x8075F2F8: c.eq.s      $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl == ctx->f12.fl;
            goto L_8075F30C;
    }
    goto skip_0;
    // 0x8075F2F8: c.eq.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl == ctx->f12.fl;
    skip_0:
    // 0x8075F2FC: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8075F300: b           L_8075F354
    // 0x8075F304: swc1        $f4, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->f4.u32l;
        goto L_8075F354;
    // 0x8075F304: swc1        $f4, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->f4.u32l;
    // 0x8075F308: c.eq.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl == ctx->f12.fl;
L_8075F30C:
    // 0x8075F30C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8075F310: bc1tl       L_8075F334
    if (c1cs) {
        // 0x8075F314: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8075F334;
    }
    goto skip_1;
    // 0x8075F314: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x8075F318: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8075F31C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8075F320: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8075F324: swc1        $f10, 0x218($v0)
    MEM_W(0X218, ctx->r2) = ctx->f10.u32l;
    // 0x8075F328: b           L_8075F354
    // 0x8075F32C: swc1        $f8, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f8.u32l;
        goto L_8075F354;
    // 0x8075F32C: swc1        $f8, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f8.u32l;
    // 0x8075F330: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8075F334:
    // 0x8075F334: b           L_8075F354
    // 0x8075F338: swc1        $f16, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f16.u32l;
        goto L_8075F354;
    // 0x8075F338: swc1        $f16, 0x214($v0)
    MEM_W(0X214, ctx->r2) = ctx->f16.u32l;
L_8075F33C:
    // 0x8075F33C: bne         $t6, $zero, L_8075F354
    if (ctx->r14 != 0) {
        // 0x8075F340: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8075F354;
    }
    // 0x8075F340: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8075F344: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8075F348: lwc1        $f4, 0x210($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X210);
    // 0x8075F34C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8075F350: swc1        $f6, 0x210($v0)
    MEM_W(0X210, ctx->r2) = ctx->f6.u32l;
L_8075F354:
    // 0x8075F354: lw          $t7, 0xEC0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XEC0);
    // 0x8075F358: lw          $t0, 0x220($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X220);
    // 0x8075F35C: addiu       $t3, $t3, -0x788
    ctx->r11 = ADD32(ctx->r11, (int16_t)RELOC_LO16(757, 0XB28));
    // 0x8075F360: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8075F364: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8075F368: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8075F36C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8075F370: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x8075F374: sll         $t2, $a1, 2
    ctx->r10 = S32(ctx->r5 << 2);
    // 0x8075F378: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8075F37C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8075F380: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8075F384: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8075F388: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8075F38C: jal         0x8075F224
    // 0x8075F390: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    func_8075F224(rdram, ctx);
        goto after_0;
    // 0x8075F390: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8075F394: jal         0x8075F1B0
    // 0x8075F398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8075F1B0(rdram, ctx);
        goto after_1;
    // 0x8075F398: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8075F39C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8075F3A0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8075F3A4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8075F3A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8075F3AC: c.eq.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl == ctx->f16.fl;
    // 0x8075F3B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8075F3B4: sw          $t4, 0x21C($v0)
    MEM_W(0X21C, ctx->r2) = ctx->r12;
    // 0x8075F3B8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8075F3BC: bc1f        L_8075F3D4
    if (!c1cs) {
        // 0x8075F3C0: lwc1        $f10, 0x20($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
            goto L_8075F3D4;
    }
    // 0x8075F3C0: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8075F3C4: lwc1        $f18, 0x20C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x8075F3C8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8075F3CC: b           L_8075F404
    // 0x8075F3D0: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
        goto L_8075F404;
    // 0x8075F3D0: swc1        $f6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f6.u32l;
L_8075F3D4:
    // 0x8075F3D4: lwc1        $f8, 0x20C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20C);
    // 0x8075F3D8: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8075F3DC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8075F3E0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x8075F3E4: nop

    // 0x8075F3E8: bc1tl       L_8075F404
    if (c1cs) {
        // 0x8075F3EC: swc1        $f2, 0x3C($a0)
        MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
            goto L_8075F404;
    }
    goto skip_2;
    // 0x8075F3EC: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
    skip_2:
    // 0x8075F3F0: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8075F3F4: sw          $zero, 0x21C($v0)
    MEM_W(0X21C, ctx->r2) = 0;
    // 0x8075F3F8: b           L_8075F404
    // 0x8075F3FC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
        goto L_8075F404;
    // 0x8075F3FC: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x8075F400: swc1        $f2, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f2.u32l;
L_8075F404:
    // 0x8075F404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8075F408: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8075F40C: jr          $ra
    // 0x8075F410: nop

    return;
    // 0x8075F410: nop

;}
RECOMP_FUNC void func_805C9918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805C9918: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x805C991C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805C9920: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805C9924: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x805C9928: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805C992C: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    // 0x805C9930: bnel        $t6, $zero, L_805C9970
    if (ctx->r14 != 0) {
        // 0x805C9934: lw          $t8, 0x2C($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X2C);
            goto L_805C9970;
    }
    goto skip_0;
    // 0x805C9934: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    skip_0:
    // 0x805C9938: jal         0x805C7BAC
    // 0x805C993C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_805C7BAC(rdram, ctx);
        goto after_0;
    // 0x805C993C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x805C9940: beq         $v0, $zero, L_805C996C
    if (ctx->r2 == 0) {
        // 0x805C9944: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_805C996C;
    }
    // 0x805C9944: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x805C9948: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x805C994C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805C9950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805C9954: bnel        $t7, $zero, L_805C9970
    if (ctx->r15 != 0) {
        // 0x805C9958: lw          $t8, 0x2C($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X2C);
            goto L_805C9970;
    }
    goto skip_1;
    // 0x805C9958: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
    skip_1:
    // 0x805C995C: jal         0x805C9D10
    // 0x805C9960: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    func_805C9D10(rdram, ctx);
        goto after_1;
    // 0x805C9960: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_1:
    // 0x805C9964: b           L_805C99BC
    // 0x805C9968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_805C99BC;
    // 0x805C9968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C996C:
    // 0x805C996C: lw          $t8, 0x2C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X2C);
L_805C9970:
    // 0x805C9970: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x805C9974: bne         $at, $zero, L_805C998C
    if (ctx->r1 != 0) {
        // 0x805C9978: nop
    
            goto L_805C998C;
    }
    // 0x805C9978: nop

    // 0x805C997C: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x805C9980: bne         $t9, $zero, L_805C998C
    if (ctx->r25 != 0) {
        // 0x805C9984: nop
    
            goto L_805C998C;
    }
    // 0x805C9984: nop

    // 0x805C9988: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
L_805C998C:
    // 0x805C998C: jal         0x805C74EC
    // 0x805C9990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C74EC(rdram, ctx);
        goto after_2;
    // 0x805C9990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x805C9994: addiu       $a0, $s0, 0xC4
    ctx->r4 = ADD32(ctx->r16, 0XC4);
    // 0x805C9998: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x805C999C: jal         0x80048F84
    // 0x805C99A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80048F84(rdram, ctx);
        goto after_3;
    // 0x805C99A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x805C99A4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x805C99A8: jal         0x80048F84
    // 0x805C99AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80048F84(rdram, ctx);
        goto after_4;
    // 0x805C99AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x805C99B0: jal         0x805C7ABC
    // 0x805C99B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805C7ABC(rdram, ctx);
        goto after_5;
    // 0x805C99B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x805C99B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_805C99BC:
    // 0x805C99BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805C99C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x805C99C4: jr          $ra
    // 0x805C99C8: nop

    return;
    // 0x805C99C8: nop

;}
RECOMP_FUNC void func_8064EFB8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8064EFB8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8064EFBC: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x8064EFC0: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8064EFC4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8064EFC8: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x8064EFCC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8064EFD0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8064EFD4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8064EFD8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8064EFDC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8064EFE0: jr          $ra
    // 0x8064EFE4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x8064EFE4: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_805E4B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805E4B0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x805E4B10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x805E4B14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x805E4B18: lw          $t6, 0x1F4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1F4);
    // 0x805E4B1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x805E4B20: addiu       $a0, $a0, 0xC4
    ctx->r4 = ADD32(ctx->r4, 0XC4);
    // 0x805E4B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x805E4B28: jal         0x805E4378
    // 0x805E4B2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    func_805E4378(rdram, ctx);
        goto after_0;
    // 0x805E4B2C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x805E4B30: jal         0x805E4460
    // 0x805E4B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4460(rdram, ctx);
        goto after_1;
    // 0x805E4B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x805E4B38: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x805E4B3C: lwc1        $f6, 0x84($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X84);
    // 0x805E4B40: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x805E4B44: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x805E4B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x805E4B4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x805E4B50: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x805E4B54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x805E4B58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x805E4B5C: bc1f        L_805E4B6C
    if (!c1cs) {
        // 0x805E4B60: nop
    
            goto L_805E4B6C;
    }
    // 0x805E4B60: nop

    // 0x805E4B64: jal         0x805E4D78
    // 0x805E4B68: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    func_805E4D78(rdram, ctx);
        goto after_2;
    // 0x805E4B68: sb          $t7, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r15;
    after_2:
L_805E4B6C:
    // 0x805E4B6C: jal         0x805E478C
    // 0x805E4B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E478C(rdram, ctx);
        goto after_3;
    // 0x805E4B70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x805E4B74: jal         0x805E4674
    // 0x805E4B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_805E4674(rdram, ctx);
        goto after_4;
    // 0x805E4B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x805E4B7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x805E4B80: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x805E4B84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x805E4B88: jr          $ra
    // 0x805E4B8C: nop

    return;
    // 0x805E4B8C: nop

;}
RECOMP_FUNC void func_806B249C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B249C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B24A0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B24A4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B24A8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B24AC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B24B0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B24B4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B24B8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B24BC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B24C0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B24C4: jr          $ra
    // 0x806B24C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B24C8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8042E6BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8042E6BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8042E6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8042E6C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8042E6C8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8042E6CC: jal         0x80065954
    // 0x8042E6D0: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    func_80065954(rdram, ctx);
        goto after_0;
    // 0x8042E6D0: lwc1        $f12, 0xC4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC4);
    after_0:
    // 0x8042E6D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8042E6D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8042E6DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8042E6E0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8042E6E4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8042E6E8: nop

    // 0x8042E6EC: bc1fl       L_8042E6FC
    if (!c1cs) {
        // 0x8042E6F0: lwc1        $f12, 0xC4($t7)
        ctx->f12.u32l = MEM_W(ctx->r15, 0XC4);
            goto L_8042E6FC;
    }
    goto skip_0;
    // 0x8042E6F0: lwc1        $f12, 0xC4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC4);
    skip_0:
    // 0x8042E6F4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8042E6F8: lwc1        $f12, 0xC4($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC4);
L_8042E6FC:
    // 0x8042E6FC: jal         0x80065954
    // 0x8042E700: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80065954(rdram, ctx);
        goto after_1;
    // 0x8042E700: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x8042E704: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8042E708: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8042E70C: lwc1        $f12, 0xC8($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x8042E710: jal         0x8042E428
    // 0x8042E714: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    func_8042E428(rdram, ctx);
        goto after_2;
    // 0x8042E714: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_2:
    // 0x8042E718: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x8042E71C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8042E720: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8042E724: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8042E728: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8042E72C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8042E730: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8042E734: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8042E738: jal         0x8042E490
    // 0x8042E73C: lw          $a1, 0x50($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X50);
    func_8042E490(rdram, ctx);
        goto after_3;
    // 0x8042E73C: lw          $a1, 0x50($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X50);
    after_3:
    // 0x8042E740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8042E744: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8042E748: jr          $ra
    // 0x8042E74C: nop

    return;
    // 0x8042E74C: nop

;}
RECOMP_FUNC void func_80460348(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80460348: lui         $v0, 0x8010
    ctx->r2 = S32(0X8010 << 16);
    // 0x8046034C: lw          $v0, -0x7D6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D6C);
    // 0x80460350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80460354: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80460358: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8046035C: sb          $t6, 0x165($a0)
    MEM_B(0X165, ctx->r4) = ctx->r14;
    // 0x80460360: lhu         $t7, 0x64($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X64);
    // 0x80460364: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80460368: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x8046036C: beql        $t8, $zero, L_80460380
    if (ctx->r24 == 0) {
        // 0x80460370: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80460380;
    }
    goto skip_0;
    // 0x80460370: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80460374: jal         0x80460470
    // 0x80460378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_80460470(rdram, ctx);
        goto after_0;
    // 0x80460378: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8046037C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80460380:
    // 0x80460380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80460384: jr          $ra
    // 0x80460388: nop

    return;
    // 0x80460388: nop

;}
RECOMP_FUNC void func_806789CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806789CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x806789D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x806789D4: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x806789D8: lh          $v0, 0x408($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X408);
    // 0x806789DC: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x806789E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x806789E4: bne         $at, $zero, L_806789F0
    if (ctx->r1 != 0) {
        // 0x806789E8: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_806789F0;
    }
    // 0x806789E8: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x806789EC: addiu       $a2, $v0, -0x40
    ctx->r6 = ADD32(ctx->r2, -0X40);
L_806789F0:
    // 0x806789F0: slti        $at, $a1, 0x40
    ctx->r1 = SIGNED(ctx->r5) < 0X40 ? 1 : 0;
    // 0x806789F4: bnel        $at, $zero, L_80678A04
    if (ctx->r1 != 0) {
        // 0x806789F8: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80678A04;
    }
    goto skip_0;
    // 0x806789F8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    skip_0:
    // 0x806789FC: addiu       $a1, $a1, -0x40
    ctx->r5 = ADD32(ctx->r5, -0X40);
    // 0x80678A00: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
L_80678A04:
    // 0x80678A04: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80678A08: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80678A0C: jal         0x80049018
    // 0x80678A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80049018(rdram, ctx);
        goto after_0;
    // 0x80678A10: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80678A14: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80678A18: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80678A1C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80678A20: beq         $v0, $zero, L_80678A48
    if (ctx->r2 == 0) {
        // 0x80678A24: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80678A48;
    }
    // 0x80678A24: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80678A28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80678A2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80678A30: lwc1        $f4, 0x414($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X414);
    // 0x80678A34: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80678A38: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80678A3C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80678A40: b           L_80678A64
    // 0x80678A44: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
        goto L_80678A64;
    // 0x80678A44: swc1        $f16, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f16.u32l;
L_80678A48:
    // 0x80678A48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80678A4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80678A50: lwc1        $f18, 0x414($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X414);
    // 0x80678A54: lwc1        $f10, 0x3C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80678A58: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80678A5C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80678A60: swc1        $f8, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f8.u32l;
L_80678A64:
    // 0x80678A64: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80678A68: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80678A6C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80678A70: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80678A74: lwc1        $f16, 0x308($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X308);
    // 0x80678A78: lwc1        $f18, 0x308($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X308);
    // 0x80678A7C: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80678A80: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80678A84: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80678A88: swc1        $f6, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f6.u32l;
    // 0x80678A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80678A90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80678A94: jr          $ra
    // 0x80678A98: nop

    return;
    // 0x80678A98: nop

;}
RECOMP_FUNC void func_80035C80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C80: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80035C84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80035C88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80035C8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035C90: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80035C94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80035C98: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80035C9C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80035CA0: jal         0x800356E8
    // 0x80035CA4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_800356E8(rdram, ctx);
        goto after_0;
    // 0x80035CA4: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80035CA8: addiu       $a0, $sp, 0x57
    ctx->r4 = ADD32(ctx->r29, 0X57);
    // 0x80035CAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80035CB0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80035CB4: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80035CB8: jal         0x800359EC
    // 0x80035CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_800359EC(rdram, ctx);
        goto after_1;
    // 0x80035CBC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80035CC0: bne         $v0, $zero, L_80035CFC
    if (ctx->r2 != 0) {
        // 0x80035CC4: addiu       $a0, $sp, 0x57
        ctx->r4 = ADD32(ctx->r29, 0X57);
            goto L_80035CFC;
    }
    // 0x80035CC4: addiu       $a0, $sp, 0x57
    ctx->r4 = ADD32(ctx->r29, 0X57);
    // 0x80035CC8: addiu       $t6, $zero, 0x27
    ctx->r14 = ADD32(0, 0X27);
    // 0x80035CCC: addiu       $t7, $zero, 0x3E
    ctx->r15 = ADD32(0, 0X3E);
    // 0x80035CD0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80035CD4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80035CD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80035CDC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80035CE0: jal         0x80035A70
    // 0x80035CE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_80035A70(rdram, ctx);
        goto after_2;
    // 0x80035CE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80035CE8: bne         $v0, $zero, L_80035CFC
    if (ctx->r2 != 0) {
        // 0x80035CEC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80035CFC;
    }
    // 0x80035CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035CF0: jal         0x80035AE8
    // 0x80035CF4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    func_80035AE8(rdram, ctx);
        goto after_3;
    // 0x80035CF4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_3:
    // 0x80035CF8: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
L_80035CFC:
    // 0x80035CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80035D00: jal         0x80035BC8
    // 0x80035D04: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    func_80035BC8(rdram, ctx);
        goto after_4;
    // 0x80035D04: addiu       $a1, $sp, 0x57
    ctx->r5 = ADD32(ctx->r29, 0X57);
    after_4:
    // 0x80035D08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035D0C: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x80035D10: jal         0x8002DBE4
    // 0x80035D14: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    func_8002DBE4(rdram, ctx);
        goto after_5;
    // 0x80035D14: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_5:
    // 0x80035D18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80035D1C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80035D20: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80035D24: jr          $ra
    // 0x80035D28: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035D28: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_805820E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805820E0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x805820E4: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x805820E8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x805820EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x805820F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x805820F4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x805820F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x805820FC: lui         $t1, 0x8058
    ctx->r9 = S32(RELOC_HI16(399, 0X46FC) << 16);
    // 0x80582100: sb          $a1, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r5;
    // 0x80582104: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x80582108: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8058210C: lw          $t1, 0x350C($t1)
    ctx->r9 = MEM_W(ctx->r9, (int16_t)RELOC_LO16(399, 0X46FC));
    // 0x80582110: jr          $ra
    // 0x80582114: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
    return;
    // 0x80582114: sw          $t1, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_80422B64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80422B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80422B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80422B6C: lbu         $t6, 0x30($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X30);
    // 0x80422B70: lw          $t9, 0x134($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X134);
    // 0x80422B74: lui         $t8, 0x8042
    ctx->r24 = S32(RELOC_HI16(35, 0X2E40) << 16);
    // 0x80422B78: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80422B7C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80422B80: lw          $t8, 0x5840($t8)
    ctx->r24 = MEM_W(ctx->r24, (int16_t)RELOC_LO16(35, 0X2E40));
    // 0x80422B84: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80422B88: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80422B8C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80422B90: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80422B94: sw          $v0, 0x15C($a0)
    MEM_W(0X15C, ctx->r4) = ctx->r2;
    // 0x80422B98: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80422B9C: beql        $v1, $zero, L_80422BD0
    if (ctx->r3 == 0) {
        // 0x80422BA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80422BD0;
    }
    goto skip_0;
    // 0x80422BA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80422BA4: jalr        $v1
    // 0x80422BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_0;
    // 0x80422BA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80422BAC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80422BB0: lw          $t1, 0x15C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X15C);
    // 0x80422BB4: lw          $t3, 0x14C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14C);
    // 0x80422BB8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80422BBC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80422BC0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80422BC4: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x80422BC8: sh          $t6, 0x144($a0)
    MEM_H(0X144, ctx->r4) = ctx->r14;
    // 0x80422BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80422BD0:
    // 0x80422BD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80422BD4: jr          $ra
    // 0x80422BD8: nop

    return;
    // 0x80422BD8: nop

;}
RECOMP_FUNC void func_8044BAD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8044BAD0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8044BAD4: jr          $ra
    // 0x8044BAD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8044BAD8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80580F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80580F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80580F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80580F38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80580F3C: jal         0x80045A34
    // 0x80580F40: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    func_80045A34(rdram, ctx);
        goto after_0;
    // 0x80580F40: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80580F44: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80580F48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80580F4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80580F50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80580F54: jal         0x800657CC
    // 0x80580F58: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    func_800657CC(rdram, ctx);
        goto after_1;
    // 0x80580F58: sw          $v0, 0x1F4($t6)
    MEM_W(0X1F4, ctx->r14) = ctx->r2;
    after_1:
    // 0x80580F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80580F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80580F64: jr          $ra
    // 0x80580F68: nop

    return;
    // 0x80580F68: nop

;}
RECOMP_FUNC void func_800496D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800496D4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800496D8: lbu         $t6, 0x5BC($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5BC);
    // 0x800496DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800496E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800496E4: bnel        $t6, $zero, L_80049718
    if (ctx->r14 != 0) {
        // 0x800496E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049718;
    }
    goto skip_0;
    // 0x800496E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800496EC: jal         0x80049318
    // 0x800496F0: nop

    func_80049318(rdram, ctx);
        goto after_0;
    // 0x800496F0: nop

    after_0:
    // 0x800496F4: beql        $v0, $zero, L_80049718
    if (ctx->r2 == 0) {
        // 0x800496F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80049718;
    }
    goto skip_1;
    // 0x800496F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800496FC: jal         0x800492C0
    // 0x80049700: addiu       $a0, $zero, -0x9F
    ctx->r4 = ADD32(0, -0X9F);
    func_800492C0(rdram, ctx);
        goto after_1;
    // 0x80049700: addiu       $a0, $zero, -0x9F
    ctx->r4 = ADD32(0, -0X9F);
    after_1:
    // 0x80049704: beq         $v0, $zero, L_80049714
    if (ctx->r2 == 0) {
        // 0x80049708: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80049714;
    }
    // 0x80049708: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8004970C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80049710: sb          $t7, 0x5BC($at)
    MEM_B(0X5BC, ctx->r1) = ctx->r15;
L_80049714:
    // 0x80049714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80049718:
    // 0x80049718: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004971C: jr          $ra
    // 0x80049720: nop

    return;
    // 0x80049720: nop

;}
RECOMP_FUNC void func_8004A064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A064: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8004A068: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004A06C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8004A070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8004A074: subu        $a0, $a0, $a1
    ctx->r4 = SUB32(ctx->r4, ctx->r5);
    // 0x8004A078: jal         0x80064D1C
    // 0x8004A07C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    func_80064D1C(rdram, ctx);
        goto after_0;
    // 0x8004A07C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_0:
    // 0x8004A080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8004A084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8004A088: jr          $ra
    // 0x8004A08C: nop

    return;
    // 0x8004A08C: nop

;}
RECOMP_FUNC void func_804A4768(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A4768: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x804A476C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804A4770: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x804A4774: jal         0x804A49CC
    // 0x804A4778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    func_804A49CC(rdram, ctx);
        goto after_0;
    // 0x804A4778: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x804A477C: lh          $t6, 0x144($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X144);
    // 0x804A4780: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x804A4784: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x804A4788: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x804A478C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x804A4790: lwc1        $f4, 0x6C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6C);
    // 0x804A4794: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x804A4798: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x804A479C: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x804A47A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804A47A4: lwc1        $f6, 0x70($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X70);
    // 0x804A47A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x804A47AC: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    // 0x804A47B0: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x804A47B4: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x804A47B8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x804A47BC: jal         0x804A3BA0
    // 0x804A47C0: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    func_804A3BA0(rdram, ctx);
        goto after_1;
    // 0x804A47C0: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x804A47C4: lw          $t7, 0x1F4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1F4);
    // 0x804A47C8: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x804A47CC: beq         $v0, $zero, L_804A47F4
    if (ctx->r2 == 0) {
        // 0x804A47D0: sw          $v0, 0x0($t7)
        MEM_W(0X0, ctx->r15) = ctx->r2;
            goto L_804A47F4;
    }
    // 0x804A47D0: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x804A47D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A47D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A47DC: jal         0x804A491C
    // 0x804A47E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    func_804A491C(rdram, ctx);
        goto after_2;
    // 0x804A47E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x804A47E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x804A47E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x804A47EC: b           L_804A48B4
    // 0x804A47F0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
        goto L_804A48B4;
    // 0x804A47F0: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_804A47F4:
    // 0x804A47F4: lw          $t9, 0x7EA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7EA8);
    // 0x804A47F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x804A47FC: addiu       $a0, $zero, 0x203
    ctx->r4 = ADD32(0, 0X203);
    // 0x804A4800: lhu         $v0, 0xC($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0XC);
    // 0x804A4804: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x804A4808: beq         $t0, $at, L_804A481C
    if (ctx->r8 == ctx->r1) {
        // 0x804A480C: andi        $t1, $v0, 0x1000
        ctx->r9 = ctx->r2 & 0X1000;
            goto L_804A481C;
    }
    // 0x804A480C: andi        $t1, $v0, 0x1000
    ctx->r9 = ctx->r2 & 0X1000;
    // 0x804A4810: addiu       $at, $zero, 0x1000
    ctx->r1 = ADD32(0, 0X1000);
    // 0x804A4814: bnel        $t1, $at, L_804A48B8
    if (ctx->r9 != ctx->r1) {
        // 0x804A4818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804A48B8;
    }
    goto skip_0;
    // 0x804A4818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_804A481C:
    // 0x804A481C: jal         0x80067818
    // 0x804A4820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80067818(rdram, ctx);
        goto after_3;
    // 0x804A4820: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x804A4824: lw          $v0, 0x180($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X180);
    // 0x804A4828: addiu       $at, $zero, 0x41F9
    ctx->r1 = ADD32(0, 0X41F9);
    // 0x804A482C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x804A4830: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x804A4834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A4838: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A483C: bnel        $t2, $at, L_804A4860
    if (ctx->r10 != ctx->r1) {
        // 0x804A4840: lw          $t5, 0xC($v0)
        ctx->r13 = MEM_W(ctx->r2, 0XC);
            goto L_804A4860;
    }
    goto skip_1;
    // 0x804A4840: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    skip_1:
    // 0x804A4844: lw          $t4, 0x1F4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1F4);
    // 0x804A4848: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804A484C: jal         0x804A491C
    // 0x804A4850: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    func_804A491C(rdram, ctx);
        goto after_4;
    // 0x804A4850: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    after_4:
    // 0x804A4854: b           L_804A48B8
    // 0x804A4858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_804A48B8;
    // 0x804A4858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x804A485C: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
L_804A4860:
    // 0x804A4860: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A4864: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x804A4868: srl         $t6, $t5, 16
    ctx->r14 = S32(U32(ctx->r13) >> 16);
    // 0x804A486C: addiu       $t7, $t6, -0x41F1
    ctx->r15 = ADD32(ctx->r14, -0X41F1);
    // 0x804A4870: sw          $t7, -0x7250($at)
    MEM_W(-0X7250, ctx->r1) = ctx->r15;
    // 0x804A4874: lw          $t9, 0x180($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X180);
    // 0x804A4878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x804A487C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804A4880: lw          $t0, 0x1F4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1F4);
    // 0x804A4884: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x804A4888: jal         0x804A491C
    // 0x804A488C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    func_804A491C(rdram, ctx);
        goto after_5;
    // 0x804A488C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    after_5:
    // 0x804A4890: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x804A4894: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A4898: sb          $t1, -0x5508($at)
    MEM_B(-0X5508, ctx->r1) = ctx->r9;
    // 0x804A489C: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A48A0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x804A48A4: sb          $t2, -0x54E4($at)
    MEM_B(-0X54E4, ctx->r1) = ctx->r10;
    // 0x804A48A8: lui         $at, 0x8010
    ctx->r1 = S32(0X8010 << 16);
    // 0x804A48AC: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x804A48B0: sb          $t3, -0x54E0($at)
    MEM_B(-0X54E0, ctx->r1) = ctx->r11;
L_804A48B4:
    // 0x804A48B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804A48B8:
    // 0x804A48B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x804A48BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x804A48C0: jr          $ra
    // 0x804A48C4: nop

    return;
    // 0x804A48C4: nop

;}
RECOMP_FUNC void func_804733F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804733F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x804733F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x804733F8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x804733FC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80473400: lw          $t6, 0x174($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X174);
    // 0x80473404: sltiu       $t7, $a1, 0x1
    ctx->r15 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x80473408: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8047340C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x80473410: lw          $v0, 0x138($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X138);
    // 0x80473414: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80473418: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8047341C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    // 0x80473420: bne         $t7, $v0, L_80473454
    if (ctx->r15 != ctx->r2) {
        // 0x80473424: addiu       $a2, $a2, -0x2F94
        ctx->r6 = ADD32(ctx->r6, -0X2F94);
            goto L_80473454;
    }
    // 0x80473424: addiu       $a2, $a2, -0x2F94
    ctx->r6 = ADD32(ctx->r6, -0X2F94);
    // 0x80473428: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8047342C: addiu       $a2, $a2, -0x3078
    ctx->r6 = ADD32(ctx->r6, -0X3078);
    // 0x80473430: jal         0x8004D1F0
    // 0x80473434: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D1F0(rdram, ctx);
        goto after_0;
    // 0x80473434: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_0:
    // 0x80473438: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x8047343C: addiu       $a2, $a2, -0x2AE4
    ctx->r6 = ADD32(ctx->r6, -0X2AE4);
    // 0x80473440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473444: jal         0x8004D698
    // 0x80473448: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004D698(rdram, ctx);
        goto after_1;
    // 0x80473448: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x8047344C: b           L_8047347C
    // 0x80473450: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
        goto L_8047347C;
    // 0x80473450: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_80473454:
    // 0x80473454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473458: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8047345C: jal         0x8004D1F0
    // 0x80473460: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    func_8004D1F0(rdram, ctx);
        goto after_2;
    // 0x80473460: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_2:
    // 0x80473464: lui         $a2, 0x8005
    ctx->r6 = S32(0X8005 << 16);
    // 0x80473468: addiu       $a2, $a2, -0x2A38
    ctx->r6 = ADD32(ctx->r6, -0X2A38);
    // 0x8047346C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80473470: jal         0x8004D698
    // 0x80473474: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_8004D698(rdram, ctx);
        goto after_3;
    // 0x80473474: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80473478: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_8047347C:
    // 0x8047347C: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80473480: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80473484: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80473488: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8047348C: lw          $t1, 0x40($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X40);
    // 0x80473490: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80473494: lbu         $t4, 0x14($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X14);
    // 0x80473498: beql        $t4, $zero, L_804734B4
    if (ctx->r12 == 0) {
        // 0x8047349C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_804734B4;
    }
    goto skip_0;
    // 0x8047349C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x804734A0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x804734A4: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x804734A8: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x804734AC: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x804734B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_804734B4:
    // 0x804734B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x804734B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x804734BC: jr          $ra
    // 0x804734C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x804734C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8067EAE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8067EAE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8067EAE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8067EAE8: lbu         $t6, 0x1F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1F);
    // 0x8067EAEC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x8067EAF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8067EAF4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x8067EAF8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8067EAFC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8067EB00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8067EB04: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8067EB08: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8067EB0C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8067EB10: lui         $t2, 0x8068
    ctx->r10 = S32(RELOC_HI16(544, 0X1150) << 16);
    // 0x8067EB14: sb          $a2, 0x30($a0)
    MEM_B(0X30, ctx->r4) = ctx->r6;
    // 0x8067EB18: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8067EB1C: sb          $t6, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r14;
    // 0x8067EB20: lw          $t2, -0xFF0($t2)
    ctx->r10 = MEM_W(ctx->r10, (int16_t)RELOC_LO16(544, 0X1150));
    // 0x8067EB24: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8067EB28: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8067EB2C: jal         0x8067DF04
    // 0x8067EB30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_8067DF04(rdram, ctx);
        goto after_0;
    // 0x8067EB30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8067EB34: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8067EB38: lw          $v1, 0x1F4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1F4);
    // 0x8067EB3C: beql        $v1, $zero, L_8067EB54
    if (ctx->r3 == 0) {
        // 0x8067EB40: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8067EB54;
    }
    goto skip_0;
    // 0x8067EB40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8067EB44: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8067EB48: jal         0x8067E004
    // 0x8067EB4C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    func_8067E004(rdram, ctx);
        goto after_1;
    // 0x8067EB4C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    after_1:
    // 0x8067EB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8067EB54:
    // 0x8067EB54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8067EB58: jr          $ra
    // 0x8067EB5C: nop

    return;
    // 0x8067EB5C: nop

;}
RECOMP_FUNC void func_805A9468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x805A9468: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x805A946C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x805A9470: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X1498) << 16);
    // 0x805A9474: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x805A9478: nop

    // 0x805A947C: bc1fl       L_805A94B0
    if (!c1cs) {
        // 0x805A9480: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_805A94B0;
    }
    goto skip_0;
    // 0x805A9480: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_0:
    // 0x805A9484: lwc1        $f4, -0x5E68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X1498));
    // 0x805A9488: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x805A948C: swc1        $f6, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f6.u32l;
    // 0x805A9490: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x805A9494: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x805A9498: nop

    // 0x805A949C: bc1f        L_805A94E0
    if (!c1cs) {
        // 0x805A94A0: nop
    
            goto L_805A94E0;
    }
    // 0x805A94A0: nop

    // 0x805A94A4: jr          $ra
    // 0x805A94A8: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x805A94A8: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x805A94AC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_805A94B0:
    // 0x805A94B0: lui         $at, 0x805B
    ctx->r1 = S32(RELOC_HI16(429, 0X149C) << 16);
    // 0x805A94B4: bc1f        L_805A94E0
    if (!c1cs) {
        // 0x805A94B8: nop
    
            goto L_805A94E0;
    }
    // 0x805A94B8: nop

    // 0x805A94BC: lwc1        $f10, -0x5E64($at)
    ctx->f10.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(429, 0X149C));
    // 0x805A94C0: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x805A94C4: swc1        $f16, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f16.u32l;
    // 0x805A94C8: lwc1        $f18, 0x48($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X48);
    // 0x805A94CC: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x805A94D0: nop

    // 0x805A94D4: bc1f        L_805A94E0
    if (!c1cs) {
        // 0x805A94D8: nop
    
            goto L_805A94E0;
    }
    // 0x805A94D8: nop

    // 0x805A94DC: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
L_805A94E0:
    // 0x805A94E0: jr          $ra
    // 0x805A94E4: nop

    return;
    // 0x805A94E4: nop

;}
RECOMP_FUNC void func_804D2E98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804D2E98: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x804D2E9C: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x804D2EA0: lw          $t6, -0x77F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77F0);
    // 0x804D2EA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x804D2EA8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x804D2EAC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x804D2EB0: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x804D2EB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x804D2EB8: lui         $a0, 0x804D
    ctx->r4 = S32(RELOC_HI16(249, 0X5E0) << 16);
    // 0x804D2EBC: slti        $at, $t7, 0x96
    ctx->r1 = SIGNED(ctx->r15) < 0X96 ? 1 : 0;
    // 0x804D2EC0: bne         $at, $zero, L_804D2ED0
    if (ctx->r1 != 0) {
        // 0x804D2EC4: addiu       $a0, $a0, 0x30F0
        ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(249, 0X5E0));
            goto L_804D2ED0;
    }
    // 0x804D2EC4: addiu       $a0, $a0, 0x30F0
    ctx->r4 = ADD32(ctx->r4, (int16_t)RELOC_LO16(249, 0X5E0));
    // 0x804D2EC8: b           L_804D2F80
    // 0x804D2ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D2F80;
    // 0x804D2ECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D2ED0:
    // 0x804D2ED0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x804D2ED4: lui         $a1, 0x4009
    ctx->r5 = S32(0X4009 << 16);
    // 0x804D2ED8: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x804D2EDC: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x804D2EE0: ori         $a1, $a1, 0x200
    ctx->r5 = ctx->r5 | 0X200;
    // 0x804D2EE4: jal         0x80046804
    // 0x804D2EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_80046804(rdram, ctx);
        goto after_0;
    // 0x804D2EE8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x804D2EEC: bne         $v0, $zero, L_804D2EFC
    if (ctx->r2 != 0) {
        // 0x804D2EF0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_804D2EFC;
    }
    // 0x804D2EF0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x804D2EF4: b           L_804D2F80
    // 0x804D2EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_804D2F80;
    // 0x804D2EF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_804D2EFC:
    // 0x804D2EFC: jal         0x80047090
    // 0x804D2F00: addiu       $a0, $zero, 0x4009
    ctx->r4 = ADD32(0, 0X4009);
    func_80047090(rdram, ctx);
        goto after_1;
    // 0x804D2F00: addiu       $a0, $zero, 0x4009
    ctx->r4 = ADD32(0, 0X4009);
    after_1:
    // 0x804D2F04: lhu         $t0, 0xE($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0XE);
    // 0x804D2F08: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x804D2F0C: addiu       $a2, $s1, 0xC4
    ctx->r6 = ADD32(ctx->r17, 0XC4);
    // 0x804D2F10: andi        $t1, $t0, 0xFC00
    ctx->r9 = ctx->r8 & 0XFC00;
    // 0x804D2F14: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x804D2F18: sh          $t2, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r10;
    // 0x804D2F1C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x804D2F20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x804D2F24: swc1        $f6, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f6.u32l;
    // 0x804D2F28: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x804D2F2C: swc1        $f8, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f8.u32l;
    // 0x804D2F30: jal         0x80048378
    // 0x804D2F34: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80048378(rdram, ctx);
        goto after_2;
    // 0x804D2F34: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x804D2F38: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x804D2F3C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x804D2F40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x804D2F44: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x804D2F48: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x804D2F4C: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x804D2F50: swc1        $f16, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f16.u32l;
    // 0x804D2F54: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x804D2F58: swc1        $f18, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->f18.u32l;
    // 0x804D2F5C: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x804D2F60: swc1        $f0, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f0.u32l;
    // 0x804D2F64: swc1        $f4, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->f4.u32l;
    // 0x804D2F68: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x804D2F6C: jal         0x804D2C64
    // 0x804D2F70: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    func_804D2C64(rdram, ctx);
        goto after_3;
    // 0x804D2F70: lw          $a0, 0x16C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X16C);
    after_3:
    // 0x804D2F74: jal         0x80044194
    // 0x804D2F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80044194(rdram, ctx);
        goto after_4;
    // 0x804D2F78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x804D2F7C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_804D2F80:
    // 0x804D2F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x804D2F84: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x804D2F88: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x804D2F8C: jr          $ra
    // 0x804D2F90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x804D2F90: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x804D2F94: nop

    // 0x804D2F98: nop

    // 0x804D2F9C: nop

;}
RECOMP_FUNC void func_806B2ACC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x806B2ACC: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x806B2AD0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x806B2AD4: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x806B2AD8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x806B2ADC: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x806B2AE0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x806B2AE4: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x806B2AE8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x806B2AEC: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x806B2AF0: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x806B2AF4: jr          $ra
    // 0x806B2AF8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x806B2AF8: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_8001D5B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D5B4: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8001D5B8: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8001D5BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D5C0: lw          $t8, 0xF10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XF10);
    // 0x8001D5C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D5C8: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8001D5CC: lw          $t1, 0xF08($a1)
    ctx->r9 = MEM_W(ctx->r5, 0XF08);
    // 0x8001D5D0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001D5D4: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8001D5D8: addiu       $t7, $t6, 0x4C
    ctx->r15 = ADD32(ctx->r14, 0X4C);
    // 0x8001D5DC: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8001D5E0: beq         $t1, $zero, L_8001D600
    if (ctx->r9 == 0) {
        // 0x8001D5E4: lw          $v1, 0xF14($t0)
        ctx->r3 = MEM_W(ctx->r8, 0XF14);
            goto L_8001D600;
    }
    // 0x8001D5E4: lw          $v1, 0xF14($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XF14);
    // 0x8001D5E8: jal         0x800445A4
    // 0x8001D5EC: nop

    func_800445A4(rdram, ctx);
        goto after_0;
    // 0x8001D5EC: nop

    after_0:
    // 0x8001D5F0: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x8001D5F4: addiu       $a1, $a1, 0x7EA0
    ctx->r5 = ADD32(ctx->r5, 0X7EA0);
    // 0x8001D5F8: b           L_8001D688
    // 0x8001D5FC: sw          $zero, 0xF08($a1)
    MEM_W(0XF08, ctx->r5) = 0;
        goto L_8001D688;
    // 0x8001D5FC: sw          $zero, 0xF08($a1)
    MEM_W(0XF08, ctx->r5) = 0;
L_8001D600:
    // 0x8001D600: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8001D604: jal         0x8001D560
    // 0x8001D608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8001D560(rdram, ctx);
        goto after_1;
    // 0x8001D608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8001D60C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D610: beq         $v0, $zero, L_8001D688
    if (ctx->r2 == 0) {
        // 0x8001D614: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_8001D688;
    }
    // 0x8001D614: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8001D618: lw          $t4, 0x16C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X16C);
    // 0x8001D61C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8001D620: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x8001D624: sw          $t2, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->r10;
    // 0x8001D628: addiu       $t3, $t3, -0x6968
    ctx->r11 = ADD32(ctx->r11, -0X6968);
    // 0x8001D62C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8001D630: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8001D634: sltiu       $at, $v1, 0x8
    ctx->r1 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x8001D638: sb          $zero, 0x165($a0)
    MEM_B(0X165, ctx->r4) = 0;
    // 0x8001D63C: sw          $zero, 0x1E0($a0)
    MEM_W(0X1E0, ctx->r4) = 0;
    // 0x8001D640: bne         $at, $zero, L_8001D650
    if (ctx->r1 != 0) {
        // 0x8001D644: sb          $t5, 0x18($a0)
        MEM_B(0X18, ctx->r4) = ctx->r13;
            goto L_8001D650;
    }
    // 0x8001D644: sb          $t5, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r13;
    // 0x8001D648: b           L_8001D660
    // 0x8001D64C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_8001D660;
    // 0x8001D64C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8001D650:
    // 0x8001D650: beq         $v1, $zero, L_8001D660
    if (ctx->r3 == 0) {
        // 0x8001D654: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001D660;
    }
    // 0x8001D654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D658: b           L_8001D660
    // 0x8001D65C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8001D660;
    // 0x8001D65C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8001D660:
    // 0x8001D660: jal         0x8001D698
    // 0x8001D664: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    func_8001D698(rdram, ctx);
        goto after_2;
    // 0x8001D664: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_2:
    // 0x8001D668: jal         0x8001CF70
    // 0x8001D66C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_8001CF70(rdram, ctx);
        goto after_3;
    // 0x8001D66C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8001D670: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8001D674: addiu       $t6, $zero, 0x180
    ctx->r14 = ADD32(0, 0X180);
    // 0x8001D678: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001D67C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001D680: sh          $t6, 0x30($t7)
    MEM_H(0X30, ctx->r15) = ctx->r14;
    // 0x8001D684: sb          $t8, -0x7EB0($at)
    MEM_B(-0X7EB0, ctx->r1) = ctx->r24;
L_8001D688:
    // 0x8001D688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001D68C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D690: jr          $ra
    // 0x8001D694: nop

    return;
    // 0x8001D694: nop

;}
RECOMP_FUNC void func_8007D5E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D5E0: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007D5E4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D5E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007D5EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D5F0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D5F4: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8007D5F8: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8007D5FC: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x8007D600: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007D604: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8007D608: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8007D60C: addiu       $s1, $t7, 0x8
    ctx->r17 = ADD32(ctx->r15, 0X8);
    // 0x8007D610: addiu       $v0, $s1, 0x28
    ctx->r2 = ADD32(ctx->r17, 0X28);
    // 0x8007D614: sw          $v0, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r2;
    // 0x8007D618: sw          $t8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r24;
    // 0x8007D61C: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x8007D620: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x8007D624: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x8007D628: sll         $t0, $t9, 5
    ctx->r8 = S32(ctx->r25 << 5);
    // 0x8007D62C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007D630: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
    // 0x8007D634: lhu         $t3, 0xA($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XA);
    // 0x8007D638: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007D63C: sh          $t4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r12;
    // 0x8007D640: lh          $t5, 0x1C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C);
    // 0x8007D644: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007D648: sh          $t6, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r14;
    // 0x8007D64C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8007D650: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8007D654: addiu       $t6, $zero, 0x33
    ctx->r14 = ADD32(0, 0X33);
    // 0x8007D658: sll         $t7, $t8, 5
    ctx->r15 = S32(ctx->r24 << 5);
    // 0x8007D65C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007D660: sh          $t0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r8;
    // 0x8007D664: lhu         $t1, 0xC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC);
    // 0x8007D668: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007D66C: sh          $t2, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r10;
    // 0x8007D670: lh          $t3, 0x1E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X1E);
    // 0x8007D674: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8007D678: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
    // 0x8007D67C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8007D680: sh          $t6, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r14;
    // 0x8007D684: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
    // 0x8007D688: lbu         $t8, 0x8($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X8);
    // 0x8007D68C: sb          $t8, 0x16($s1)
    MEM_B(0X16, ctx->r17) = ctx->r24;
    // 0x8007D690: lbu         $t7, 0x9($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X9);
    // 0x8007D694: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
    // 0x8007D698: sh          $zero, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = 0;
    // 0x8007D69C: sb          $t7, 0x17($s1)
    MEM_B(0X17, ctx->r17) = ctx->r15;
    // 0x8007D6A0: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x8007D6A4: beql        $v0, $zero, L_8007D6B8
    if (ctx->r2 == 0) {
        // 0x8007D6A8: lhu         $t9, 0x18($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X18);
            goto L_8007D6B8;
    }
    goto skip_0;
    // 0x8007D6A8: lhu         $t9, 0x18($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X18);
    skip_0:
    // 0x8007D6AC: bnel        $v0, $at, L_8007D820
    if (ctx->r2 != ctx->r1) {
        // 0x8007D6B0: lhu         $t0, 0x18($s0)
        ctx->r8 = MEM_HU(ctx->r16, 0X18);
            goto L_8007D820;
    }
    goto skip_1;
    // 0x8007D6B0: lhu         $t0, 0x18($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X18);
    skip_1:
    // 0x8007D6B4: lhu         $t9, 0x18($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X18);
L_8007D6B8:
    // 0x8007D6B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007D6BC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8007D6C0: sh          $t0, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r8;
    // 0x8007D6C4: lhu         $t1, 0x1A($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X1A);
    // 0x8007D6C8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8007D6CC: jal         0x8008DAB0
    // 0x8007D6D0: sh          $t2, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r10;
    guS2DInitBg(rdram, ctx);
        goto after_0;
    // 0x8007D6D0: sh          $t2, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r10;
    after_0:
    // 0x8007D6D4: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
    // 0x8007D6D8: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8007D6DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8007D6E0: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007D6E4: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x8007D6E8: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007D6EC: sw          $a3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r7;
    // 0x8007D6F0: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007D6F4: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8007D6F8: ori         $t8, $t8, 0x18
    ctx->r24 = ctx->r24 | 0X18;
    // 0x8007D6FC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8007D700: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8007D704: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8007D708: lhu         $t7, 0xE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XE);
    // 0x8007D70C: lui         $at, 0x20
    ctx->r1 = S32(0X20 << 16);
    // 0x8007D710: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007D714: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x8007D718: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8007D71C: lui         $t2, 0xB900
    ctx->r10 = S32(0XB900 << 16);
    // 0x8007D720: ori         $t2, $t2, 0x3
    ctx->r10 = ctx->r10 | 0X3;
    // 0x8007D724: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8007D728: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8007D72C: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x8007D730: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8007D734: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8007D738: lui         $t5, 0xB900
    ctx->r13 = S32(0XB900 << 16);
    // 0x8007D73C: ori         $t5, $t5, 0x31D
    ctx->r13 = ctx->r13 | 0X31D;
    // 0x8007D740: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007D744: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x8007D748: sw          $a1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r5;
    // 0x8007D74C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007D750: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x8007D754: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8007D758: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D75C: bne         $t6, $at, L_8007D7FC
    if (ctx->r14 != ctx->r1) {
        // 0x8007D760: addiu       $t7, $t8, 0x8
        ctx->r15 = ADD32(ctx->r24, 0X8);
            goto L_8007D7FC;
    }
    // 0x8007D760: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8007D764: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8007D768: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8007D76C: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8007D770: lw          $t0, 0x4($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4);
    // 0x8007D774: lui         $t3, 0xE800
    ctx->r11 = S32(0XE800 << 16);
    // 0x8007D778: lui         $t6, 0xF500
    ctx->r14 = S32(0XF500 << 16);
    // 0x8007D77C: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8007D780: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8007D784: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007D788: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8007D78C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007D790: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D794: lw          $t4, 0x94($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X94);
    // 0x8007D798: ori         $t6, $t6, 0x100
    ctx->r14 = ctx->r14 | 0X100;
    // 0x8007D79C: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x8007D7A0: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x8007D7A4: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x8007D7A8: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x8007D7AC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8007D7B0: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8007D7B4: lui         $t0, 0xE600
    ctx->r8 = S32(0XE600 << 16);
    // 0x8007D7B8: lui         $t3, 0xF000
    ctx->r11 = S32(0XF000 << 16);
    // 0x8007D7BC: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8007D7C0: sw          $t9, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r25;
    // 0x8007D7C4: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8007D7C8: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x8007D7CC: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8007D7D0: lui         $t4, 0x73F
    ctx->r12 = S32(0X73F << 16);
    // 0x8007D7D4: ori         $t4, $t4, 0xC000
    ctx->r12 = ctx->r12 | 0XC000;
    // 0x8007D7D8: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007D7DC: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8007D7E0: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8007D7E4: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D7E8: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007D7EC: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8007D7F0: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8007D7F4: sw          $zero, 0x4($t5)
    MEM_W(0X4, ctx->r13) = 0;
    // 0x8007D7F8: sw          $a3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r7;
L_8007D7FC:
    // 0x8007D7FC: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8007D800: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8007D804: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8007D808: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8007D80C: sw          $s1, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r17;
    // 0x8007D810: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8007D814: b           L_8007DB04
    // 0x8007D818: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
        goto L_8007DB04;
    // 0x8007D818: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8007D81C: lhu         $t0, 0x18($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X18);
L_8007D820:
    // 0x8007D820: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007D824: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007D828: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8007D82C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8007D830: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8007D834: bgez        $t0, L_8007D84C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D838: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8007D84C;
    }
    // 0x8007D838: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007D83C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D844: nop

    // 0x8007D848: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8007D84C:
    // 0x8007D84C: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8007D850: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8007D854: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007D858: nop

    // 0x8007D85C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8007D860: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007D864: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x8007D868: nop

    // 0x8007D86C: sh          $t2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r10;
    // 0x8007D870: lhu         $t3, 0x1A($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X1A);
    // 0x8007D874: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8007D878: bgez        $t3, L_8007D88C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8007D87C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8007D88C;
    }
    // 0x8007D87C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007D880: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007D884: nop

    // 0x8007D888: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8007D88C:
    // 0x8007D88C: lwc1        $f16, 0x2C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8007D890: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007D894: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007D898: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8007D89C: nop

    // 0x8007D8A0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007D8A4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8007D8A8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8007D8AC: nop

    // 0x8007D8B0: sh          $t5, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r13;
    // 0x8007D8B4: lwc1        $f10, 0x28($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8007D8B8: div.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8007D8BC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007D8C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007D8C4: nop

    // 0x8007D8C8: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8007D8CC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007D8D0: nop

    // 0x8007D8D4: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007D8D8: beq         $t8, $zero, L_8007D924
    if (ctx->r24 == 0) {
        // 0x8007D8DC: nop
    
            goto L_8007D924;
    }
    // 0x8007D8DC: nop

    // 0x8007D8E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007D8E4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007D8E8: sub.s       $f16, $f6, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8007D8EC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007D8F0: nop

    // 0x8007D8F4: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8007D8F8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007D8FC: nop

    // 0x8007D900: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8007D904: bne         $t8, $zero, L_8007D91C
    if (ctx->r24 != 0) {
        // 0x8007D908: nop
    
            goto L_8007D91C;
    }
    // 0x8007D908: nop

    // 0x8007D90C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8007D910: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D914: b           L_8007D934
    // 0x8007D918: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8007D934;
    // 0x8007D918: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8007D91C:
    // 0x8007D91C: b           L_8007D934
    // 0x8007D920: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8007D934;
    // 0x8007D920: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8007D924:
    // 0x8007D924: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8007D928: nop

    // 0x8007D92C: bltz        $t8, L_8007D91C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8007D930: nop
    
            goto L_8007D91C;
    }
    // 0x8007D930: nop

L_8007D934:
    // 0x8007D934: sh          $t8, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r24;
    // 0x8007D938: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007D93C: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8007D940: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007D944: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8007D948: div.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8007D94C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007D950: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007D954: nop

    // 0x8007D958: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8007D95C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007D960: nop

    // 0x8007D964: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8007D968: beql        $t9, $zero, L_8007D9B8
    if (ctx->r25 == 0) {
        // 0x8007D96C: mfc1        $t9, $f8
        ctx->r25 = (int32_t)ctx->f8.u32l;
            goto L_8007D9B8;
    }
    goto skip_2;
    // 0x8007D96C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x8007D970: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007D974: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8007D978: sub.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8007D97C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8007D980: nop

    // 0x8007D984: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8007D988: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8007D98C: nop

    // 0x8007D990: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8007D994: bne         $t9, $zero, L_8007D9AC
    if (ctx->r25 != 0) {
        // 0x8007D998: nop
    
            goto L_8007D9AC;
    }
    // 0x8007D998: nop

    // 0x8007D99C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8007D9A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D9A4: b           L_8007D9C4
    // 0x8007D9A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8007D9C4;
    // 0x8007D9A8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_8007D9AC:
    // 0x8007D9AC: b           L_8007D9C4
    // 0x8007D9B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8007D9C4;
    // 0x8007D9B0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8007D9B4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
L_8007D9B8:
    // 0x8007D9B8: nop

    // 0x8007D9BC: bltz        $t9, L_8007D9AC
    if (SIGNED(ctx->r25) < 0) {
        // 0x8007D9C0: nop
    
            goto L_8007D9AC;
    }
    // 0x8007D9C0: nop

L_8007D9C4:
    // 0x8007D9C4: lhu         $t0, 0x8($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X8);
    // 0x8007D9C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007D9CC: sh          $t9, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r25;
    // 0x8007D9D0: sw          $t0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r8;
    // 0x8007D9D4: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x8007D9D8: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8007D9DC: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8007D9E0: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8007D9E4: sw          $t2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r10;
    // 0x8007D9E8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007D9EC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8007D9F0: lbu         $t4, 0x38($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X38);
    // 0x8007D9F4: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8007D9F8: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
    // 0x8007D9FC: bne         $t4, $zero, L_8007DA54
    if (ctx->r12 != 0) {
        // 0x8007DA00: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_8007DA54;
    }
    // 0x8007DA00: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8007DA04: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007DA08: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007DA0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8007DA10: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x8007DA14: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8007DA18: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x8007DA1C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8007DA20: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8007DA24: lui         $t2, 0x101
    ctx->r10 = S32(0X101 << 16);
    // 0x8007DA28: ori         $t2, $t2, 0x101
    ctx->r10 = ctx->r10 | 0X101;
    // 0x8007DA2C: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8007DA30: sw          $t0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r8;
    // 0x8007DA34: sw          $t2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r10;
    // 0x8007DA38: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8007DA3C: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x8007DA40: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x8007DA44: jal         0x800773A4
    // 0x8007DA48: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    func_800773A4(rdram, ctx);
        goto after_1;
    // 0x8007DA48: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_1:
    // 0x8007DA4C: b           L_8007DA94
    // 0x8007DA50: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
        goto L_8007DA94;
    // 0x8007DA50: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
L_8007DA54:
    // 0x8007DA54: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007DA58: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x8007DA5C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
    // 0x8007DA60: lw          $t6, 0x3C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X3C);
    // 0x8007DA64: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8007DA68: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007DA6C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x8007DA70: addiu       $t7, $t8, 0x8
    ctx->r15 = ADD32(ctx->r24, 0X8);
    // 0x8007DA74: sw          $t7, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r15;
    // 0x8007DA78: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8007DA7C: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x8007DA80: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x8007DA84: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x8007DA88: jal         0x800773A4
    // 0x8007DA8C: lbu         $a2, 0x38($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X38);
    func_800773A4(rdram, ctx);
        goto after_2;
    // 0x8007DA8C: lbu         $a2, 0x38($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X38);
    after_2:
    // 0x8007DA90: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
L_8007DA94:
    // 0x8007DA94: lbu         $a1, 0x8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X8);
    // 0x8007DA98: lbu         $a2, 0x9($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X9);
    // 0x8007DA9C: jal         0x8007711C
    // 0x8007DAA0: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    func_8007711C(rdram, ctx);
        goto after_3;
    // 0x8007DAA0: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    after_3:
    // 0x8007DAA4: lw          $t1, 0x30($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X30);
    // 0x8007DAA8: lw          $t2, 0x94($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X94);
    // 0x8007DAAC: lui         $a3, 0xE700
    ctx->r7 = S32(0XE700 << 16);
    // 0x8007DAB0: beq         $t1, $zero, L_8007DACC
    if (ctx->r9 == 0) {
        // 0x8007DAB4: addiu       $t3, $t2, 0x8
        ctx->r11 = ADD32(ctx->r10, 0X8);
            goto L_8007DACC;
    }
    // 0x8007DAB4: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x8007DAB8: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x8007DABC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8007DAC0: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8007DAC4: lw          $t5, 0x30($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X30);
    // 0x8007DAC8: sw          $t5, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r13;
L_8007DACC:
    // 0x8007DACC: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x8007DAD0: lui         $t7, 0xB100
    ctx->r15 = S32(0XB100 << 16);
    // 0x8007DAD4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8007DAD8: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8007DADC: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8007DAE0: sw          $t9, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r25;
    // 0x8007DAE4: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    // 0x8007DAE8: lw          $t0, 0x94($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X94);
    // 0x8007DAEC: lui         $t2, 0x100
    ctx->r10 = S32(0X100 << 16);
    // 0x8007DAF0: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x8007DAF4: sw          $t1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r9;
    // 0x8007DAF8: sw          $s1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r17;
    // 0x8007DAFC: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8007DB00: lw          $t3, 0x94($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X94);
L_8007DB04:
    // 0x8007DB04: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x8007DB08: sw          $t4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r12;
    // 0x8007DB0C: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007DB10: sw          $a3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r7;
    // 0x8007DB14: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8007DB18: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x8007DB1C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x8007DB20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DB24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007DB28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007DB2C: jr          $ra
    // 0x8007DB30: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007DB30: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_804511DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804511DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x804511E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x804511E4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x804511E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x804511EC: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x804511F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x804511F4: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140BC) << 16);
    // 0x804511F8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x804511FC: nop

    // 0x80451200: bc1f        L_80451228
    if (!c1cs) {
        // 0x80451204: nop
    
            goto L_80451228;
    }
    // 0x80451204: nop

    // 0x80451208: jal         0x80450B18
    // 0x8045120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_80450B18(rdram, ctx);
        goto after_0;
    // 0x8045120C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80451210: jal         0x804510D4
    // 0x80451214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_804510D4(rdram, ctx);
        goto after_1;
    // 0x80451214: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80451218: jal         0x80445A34
    // 0x8045121C: nop

    func_80445A34(rdram, ctx);
        goto after_2;
    // 0x8045121C: nop

    after_2:
    // 0x80451220: b           L_804513F4
    // 0x80451224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_804513F4;
    // 0x80451224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80451228:
    // 0x80451228: lwc1        $f6, -0x7B64($at)
    ctx->f6.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140BC));
    // 0x8045122C: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140C0) << 16);
    // 0x80451230: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80451234: nop

    // 0x80451238: bc1f        L_80451264
    if (!c1cs) {
        // 0x8045123C: nop
    
            goto L_80451264;
    }
    // 0x8045123C: nop

    // 0x80451240: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80451244: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451248: beql        $t6, $zero, L_804513F4
    if (ctx->r14 == 0) {
        // 0x8045124C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_0;
    // 0x8045124C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80451250: jal         0x80450B18
    // 0x80451254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_3;
    // 0x80451254: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80451258: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8045125C: b           L_804513F0
    // 0x80451260: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_804513F0;
    // 0x80451260: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80451264:
    // 0x80451264: lwc1        $f8, -0x7B60($at)
    ctx->f8.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140C0));
    // 0x80451268: lui         $at, 0x4434
    ctx->r1 = S32(0X4434 << 16);
    // 0x8045126C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80451270: nop

    // 0x80451274: bc1fl       L_804512AC
    if (!c1cs) {
        // 0x80451278: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_804512AC;
    }
    goto skip_1;
    // 0x80451278: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x8045127C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80451280: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80451284: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451288: beql        $t7, $at, L_804513F4
    if (ctx->r15 == ctx->r1) {
        // 0x8045128C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_2;
    // 0x8045128C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80451290: jal         0x80450B18
    // 0x80451294: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_4;
    // 0x80451294: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x80451298: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8045129C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x804512A0: b           L_804513F0
    // 0x804512A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
        goto L_804513F0;
    // 0x804512A4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x804512A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_804512AC:
    // 0x804512AC: lui         $at, 0x8046
    ctx->r1 = S32(RELOC_HI16(98, 0X140C4) << 16);
    // 0x804512B0: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x804512B4: nop

    // 0x804512B8: bc1f        L_804512EC
    if (!c1cs) {
        // 0x804512BC: nop
    
            goto L_804512EC;
    }
    // 0x804512BC: nop

    // 0x804512C0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x804512C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x804512C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804512CC: beql        $t9, $at, L_804513F4
    if (ctx->r25 == ctx->r1) {
        // 0x804512D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_3;
    // 0x804512D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x804512D4: jal         0x80450B18
    // 0x804512D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_5;
    // 0x804512D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_5:
    // 0x804512DC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804512E0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x804512E4: b           L_804513F0
    // 0x804512E8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_804513F0;
    // 0x804512E8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_804512EC:
    // 0x804512EC: lwc1        $f16, -0x7B5C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, (int16_t)RELOC_LO16(98, 0X140C4));
    // 0x804512F0: lui         $at, 0x4407
    ctx->r1 = S32(0X4407 << 16);
    // 0x804512F4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x804512F8: nop

    // 0x804512FC: bc1fl       L_80451334
    if (!c1cs) {
        // 0x80451300: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80451334;
    }
    goto skip_4;
    // 0x80451300: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x80451304: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x80451308: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8045130C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451310: beql        $t1, $at, L_804513F4
    if (ctx->r9 == ctx->r1) {
        // 0x80451314: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_5;
    // 0x80451314: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80451318: jal         0x80450B18
    // 0x8045131C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_6;
    // 0x8045131C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x80451320: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451324: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80451328: b           L_804513F0
    // 0x8045132C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
        goto L_804513F0;
    // 0x8045132C: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80451330: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80451334:
    // 0x80451334: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80451338: c.le.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl <= ctx->f0.fl;
    // 0x8045133C: nop

    // 0x80451340: bc1fl       L_80451370
    if (!c1cs) {
        // 0x80451344: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_80451370;
    }
    goto skip_6;
    // 0x80451344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_6:
    // 0x80451348: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8045134C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80451350: beql        $t3, $zero, L_804513F4
    if (ctx->r11 == 0) {
        // 0x80451354: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_7;
    // 0x80451354: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80451358: jal         0x80450B18
    // 0x8045135C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_7;
    // 0x8045135C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_7:
    // 0x80451360: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80451364: b           L_804513F0
    // 0x80451368: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_804513F0;
    // 0x80451368: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8045136C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_80451370:
    // 0x80451370: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80451374: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80451378: nop

    // 0x8045137C: bc1fl       L_804513B4
    if (!c1cs) {
        // 0x80451380: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_804513B4;
    }
    goto skip_8;
    // 0x80451380: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_8:
    // 0x80451384: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x80451388: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8045138C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80451390: beql        $t4, $at, L_804513F4
    if (ctx->r12 == ctx->r1) {
        // 0x80451394: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_9;
    // 0x80451394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80451398: jal         0x80450B18
    // 0x8045139C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_8;
    // 0x8045139C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_8:
    // 0x804513A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804513A4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x804513A8: b           L_804513F0
    // 0x804513AC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
        goto L_804513F0;
    // 0x804513AC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x804513B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_804513B4:
    // 0x804513B4: nop

    // 0x804513B8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x804513BC: nop

    // 0x804513C0: bc1fl       L_804513F4
    if (!c1cs) {
        // 0x804513C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_10;
    // 0x804513C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x804513C8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x804513CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x804513D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x804513D4: beql        $t6, $at, L_804513F4
    if (ctx->r14 == ctx->r1) {
        // 0x804513D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_804513F4;
    }
    goto skip_11;
    // 0x804513D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x804513DC: jal         0x80450B18
    // 0x804513E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_80450B18(rdram, ctx);
        goto after_9;
    // 0x804513E0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_9:
    // 0x804513E4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x804513E8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x804513EC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_804513F0:
    // 0x804513F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_804513F4:
    // 0x804513F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x804513F8: jr          $ra
    // 0x804513FC: nop

    return;
    // 0x804513FC: nop

;}
RECOMP_FUNC void func_804A52C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804A52C4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x804A52C8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x804A52CC: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x804A52D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x804A52D4: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x804A52D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x804A52DC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x804A52E0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x804A52E4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x804A52E8: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x804A52EC: jr          $ra
    // 0x804A52F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
    return;
    // 0x804A52F0: sw          $t0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r8;
;}
RECOMP_FUNC void func_804C4F40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x804C4F40: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x804C4F44: lui         $t6, 0x804C
    ctx->r14 = S32(RELOC_HI16(212, 0XAC0) << 16);
    // 0x804C4F48: addiu       $v1, $v1, 0x7EA0
    ctx->r3 = ADD32(ctx->r3, 0X7EA0);
    // 0x804C4F4C: addiu       $t6, $t6, 0x5A00
    ctx->r14 = ADD32(ctx->r14, (int16_t)RELOC_LO16(212, 0XAC0));
    // 0x804C4F50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x804C4F54: sw          $t6, 0xF74($v1)
    MEM_W(0XF74, ctx->r3) = ctx->r14;
    // 0x804C4F58: lui         $v0, 0x804C
    ctx->r2 = S32(RELOC_HI16(212, 0X40) << 16);
    // 0x804C4F5C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x804C4F60: jr          $ra
    // 0x804C4F64: addiu       $v0, $v0, 0x4F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(212, 0X40));
    return;
    // 0x804C4F64: addiu       $v0, $v0, 0x4F80
    ctx->r2 = ADD32(ctx->r2, (int16_t)RELOC_LO16(212, 0X40));
;}
